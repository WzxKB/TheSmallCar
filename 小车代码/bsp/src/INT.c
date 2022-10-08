#include <STC8H.H>
#include "INT.H"

void INT3_Init(void)
{
	EA=1;
	INTCLKO=EX3;
}