<!--
 * @Author: devilwzx
 * @Date: 2022-10-08 21:25:33
 * @FilePath: \undefinede:\Code\51\The small car\README.md
 * @Description: 这是小车项目的readme
 * 
-->
# 这是小车项目的readme
## 这个项目学习51编程，学习画原理图，画pcb图，焊接，组装调试等，从7月份开始到10月份结束，一共花了三个月的时间。
## 总共决定制作两套小车，一个为橙色，一个为黑白色，分别当作礼物送个两个朋友。
# 文件
* 小车代码
* 遥控器代码
* 制版文件
* 原理图

# 备注
* 硬件
  * 小车7133（3.3v）电源芯片，若是后面的电路短路，会直接导致7133烧毁，同时，由于nrf供电不能超过5v，nrf模块也会直接烧毁。此时，需要更换nrf模块和电源芯片，注意一定不要短路，后续会考虑更换电源芯片。 
  * 本来设计了三个开关，没用上，可以砍掉，小车灯也多了，可以砍掉，之所以这么多是为了学习。
* 软件
  * 信号接收距离没有测试过，但是理论上达到几十米。
  * 小车运行过程中有一卡一卡的情况，猜测是有时候没有接收到数据的原因，可以优化，但是影响不大懒得改了。

### 立创eda项目地址：
https://pro.lceda.cn/editor#id=b4c98ad125bf42fc8df665a7e6db6760
### bilibili：
https://space.bilibili.com/295670011?spm_id_from=333.1007.0.0
### github：
https://github.com/WzxKB/TheSmallCar
### 附上一张图：
![](car.png)  