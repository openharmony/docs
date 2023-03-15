# 位操作


## 基本概念

位操作是指对二进制数的bit位进行操作。程序可以设置某一变量为状态字，状态字中的每一bit位（标志位）可以具有自定义的含义。


## 功能说明

系统提供标志位的置1和清0操作，可以改变标志位的内容，同时还提供获取状态字中标志位为1的最高位和最低位的功能。用户也可以对系统的寄存器进行位操作。位操作模块为用户提供下面几种功能，接口详细信息可以查看API参考。

  **表1** 位操作模块接口

| **功能分类** | **接口描述** | 
| -------- | -------- |
| 置1/清0标志位 | -&nbsp;LOS_BitmapSet：对状态字的某一标志位进行置1操作<br/>-&nbsp;LOS_BitmapClr：对状态字的某一标志位进行清0操作 | 
| 获取标志位为1的bit位 | -&nbsp;LOS_HighBitGet：获取状态字中为1的最高位<br/>-&nbsp;LOS_LowBitGet：获取状态字中为1的最低位 | 
| 连续bit位操作 | -&nbsp;LOS_BitmapSetNBits：对状态字的连续标志位进行置1操作<br/>-&nbsp;LOS_BitmapClrNBits：对状态字的连续标志位进行清0操作<br/>-&nbsp;LOS_BitmapFfz：获取从最低有效位开始的第一个0的bit位 | 


## 编程实例


### 实例描述

对数据实现位操作，本实例实现如下功能：

1. 某一标志位置1。

2. 获取标志位为1的最高bit位。

3. 某一标志位清0。

4. 获取标志位为1的最低bit位。

### 编程示例

本演示代码在./kernel/liteos_a/testsuites/kernel/src/osTest.c中编译验证，在TestTaskEntry中调用验证入口函数BitSample。
 
```
#include "los_bitmap.h"
#include "los_printf.h"

static UINT32 BitSample(VOID)
{
  UINT32 flag = 0x10101010;
  UINT16 pos;

  PRINTK("\nBitmap Sample!\n");
  PRINTK("The flag is 0x%8x\n", flag);

  pos = 8;
  LOS_BitmapSet(&flag, pos);
  PRINTK("LOS_BitmapSet:\t pos : %d, the flag is 0x%0+8x\n", pos, flag);

  pos = LOS_HighBitGet(flag);
  PRINTK("LOS_HighBitGet:\t The highest one bit is %d, the flag is 0x%0+8x\n", pos, flag);

  LOS_BitmapClr(&flag, pos);
  PRINTK("LOS_BitmapClr:\t pos : %d, the flag is 0x%0+8x\n", pos, flag);

  pos = LOS_LowBitGet(flag);
  PRINTK("LOS_LowBitGet:\t The lowest one bit is %d, the flag is 0x%0+8x\n\n", pos, flag);

  return LOS_OK;
}
```


### 结果验证

编译运行得到的结果为：

  
```
Bitmap Sample!
The flag is 0x10101010
LOS_BitmapSet: pos : 8,  the flag is 0x10101110
LOS_HighBitGet:The highest one bit is 28, the flag is 0x10101110
LOS_BitmapClr: pos : 28, the flag is 0x00101110
LOS_LowBitGet: The lowest one bit is 4, the flag is 0x00101110
```
