#include "bsp.h"

u8 code TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01}; // 接收地址
u8 rx_buf[TX_PLOAD_WIDTH];
  
/**************************************************
Function: SPI_RW();

Description:
  Writes one u8 to nRF24L01, and return the u8 read
  from nRF24L01 during write, according to SPI protocol
/**************************************************/
u8 SPI_RW(u8 byte)
{
	u8 bit_ctr;
   	for(bit_ctr=0;bit_ctr<8;bit_ctr++)   // output 8-bit
   	{
   		MOSI = (byte & 0x80);         // output 'u8', MSB to MOSI
   		byte = (byte << 1);           // shift next bit into MSB..
   		SCK = 1;                      // Set SCK high..
   		byte |= MISO;       		  // capture current MISO bit
   		SCK = 0;            		  // ..then set SCK low again
   	}
    return(byte);           		  // return read u8
}
/**************************************************/

/**************************************************
Function: SPI_RW_Reg();

Description:
  Writes value 'value' to register 'reg'
/**************************************************/
u8 SPI_RW_Reg(u8 reg, u8 value)
{
	u8 status;

  	CSN = 0;                   // CSN low, init SPI transaction
  	status = SPI_RW(reg);      // select register
  	SPI_RW(value);             // ..and write value to it..
  	CSN = 1;                   // CSN high again

  	return(status);            // return nRF24L01 status u8
}
/**************************************************/

/**************************************************
Function: SPI_Read();

Description:
  Read one u8 from nRF24L01 register, 'reg'
/**************************************************/
u8 SPI_Read(u8 reg)
{
	u8 reg_val;

  	CSN = 0;                // CSN low, initialize SPI communication...
  	SPI_RW(reg);            // Select register to read from..
  	reg_val = SPI_RW(0);    // ..then read registervalue
  	CSN = 1;                // CSN high, terminate SPI communication

  	return(reg_val);        // return register value
}
/**************************************************/

/**************************************************
Function: SPI_Read_Buf();

Description:
  Reads 'u8s' #of u8s from register 'reg'
  Typically used to read RX payload, Rx/Tx address
/**************************************************/
u8 SPI_Read_Buf(u8 reg, u8 *pBuf, u8 u8s)
{
	u8 status,u8_ctr;

  	CSN = 0;                    		// Set CSN low, init SPI tranaction
  	status = SPI_RW(reg);       		// Select register to write to and read status u8

  	for(u8_ctr=0;u8_ctr<u8s;u8_ctr++)
    	pBuf[u8_ctr] = SPI_RW(0);    // Perform SPI_RW to read u8 from nRF24L01

  	CSN = 1;                           // Set CSN high again

  	return(status);                    // return nRF24L01 status u8
}
/**************************************************/

/**************************************************
Function: SPI_Write_Buf();

Description:
  Writes contents of buffer '*pBuf' to nRF24L01
  Typically used to write TX payload, Rx/Tx address
/**************************************************/
u8 SPI_Write_Buf(u8 reg, u8 *pBuf, u8 u8s)
{
	u8 status,u8_ctr;

  	CSN = 0;                   // Set CSN low, init SPI tranaction
  	status = SPI_RW(reg);    // Select register to write to and read status u8
  	for(u8_ctr=0; u8_ctr<u8s; u8_ctr++) // then write all u8 in buffer(*pBuf)
    	SPI_RW(*pBuf++);
  	CSN = 1;                 // Set CSN high again
  	return(status);          // return nRF24L01 status u8
}
/**************************************************/

/**************************************************
Function: RX_Mode();

Description:
  This function initializes one nRF24L01 device to
  RX Mode, set RX address, writes RX payload width,
  select RF channel, datarate & LNA HCURR.
  After init, CE is toggled high, which means that
  this device is now ready to receive a datapacket.
/**************************************************/
void RX_Mode(void)
{
		CE = 0;
  	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // Writes TX_Address to nRF24L01
		SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // Use the same address on the RX device as the TX device

  	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
  	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
  	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
  	SPI_RW_Reg(WRITE_REG + RX_PW_P0, TX_PLOAD_WIDTH); // Select same RX payload width as TX Payload width
  	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
  	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);     // Set PWR_UP bit, enable CRC(2 u8s) & Prim:RX. RX_DR enabled..

  	CE = 1; // Set CE pin high to enable RX device
	
  //  This device is now ready to receive one packet of 16 u8s payload from a TX device sending to address
  //  '3443101001', with auto acknowledgment, retransmit count of 10, RF channel 40 and datarate = 2Mbps.

}
/**************************************************/

/**************************************************
Function: TX_Mode();

Description:
  This function initializes one nRF24L01 device to
  TX mode, set TX address, set RX address for auto.ack,
  fill TX payload, select RF channel, datarate & TX pwr.
  PWR_UP is set, CRC(2 u8s) is enabled, & PRIM:TX.

  ToDo: One high pulse(>10us) on CE will now send this
  packet and expext an acknowledgment from the RX device.
/**************************************************/
//void TX_Mode(void)
//{
//	CE=0;
//	
//  	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // Writes TX_Address to nRF24L01
//  	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // RX_Addr0 same as TX_Adr for Auto.Ack
//  	SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH); // Writes data to TX payload

//  	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
//  	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
//  	SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
//  	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
//  	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
//  	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);     // Set PWR_UP bit, enable CRC(2 u8s) & Prim:TX. MAX_RT & TX_DS enabled..
//	CE=1;

//}
/**************************************************/








/**
  * @brief NRF初始化函数 
  * @param	无
  * @retval	无
  */
void NRF_Init(void)
{
	CE = 0;				// chip enable
	CSN = 1;			// Spi disable	
	SCK = 1;			// Spi clock line init high
}

/**
  * @brief NRF接收函数，处理接收到的数据 
  * @param	无
  * @retval	无
  */
BUF NRF_Receive(void)
{
	u8 sta;
	BUF buf;
	
	sta=SPI_Read(STATUS);		//读取芯片的状态寄存器	
	  if((sta & 0x40) != 0)		//是否发生了接收数据，完成的中断
	  {		
			//是的话，将收到的数据存到数组rx_buf里
		  SPI_Read_Buf(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);
			
		}
		buf.sw1=rx_buf[0];
		buf.sw2=rx_buf[1];
		
		buf.left=rx_buf[3];
		buf.left<<=8;
		buf.left|=rx_buf[2];
		//为了左摇杆的值上下都为100，所以除以200
		buf.left=(long int)buf.left*200/0x03FF;
		
		buf.middle=rx_buf[5];
		buf.middle<<=8;
		buf.middle|=rx_buf[4];
		//中摇杆ad值设为速度
		buf.middle=(long int)buf.middle*34/0x03FF;
		
		buf.right=rx_buf[7];
		buf.right<<=8;
		buf.right|=rx_buf[6];
		//为了右摇杆的值上下都为100，所以除以200
		buf.right=(long int)buf.right*200/0x03FF;
		
		
		SPI_RW_Reg(FLUSH_RX,0xff);	//清除接收缓冲器
		SPI_RW_Reg(WRITE_REG+STATUS,sta);//清除接收中断标志
		Delay_ms(20);	//必须有的延时，延时20ms可基本收完数据
		
	return buf;
}
