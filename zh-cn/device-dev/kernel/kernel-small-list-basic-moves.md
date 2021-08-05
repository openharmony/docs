# 位操作<a name="ZH-CN_TOPIC_0000001078588212"></a>

-   [基本概念](#section1990715203418)
-   [功能说明](#section848334511411)
-   [编程实例](#section67569495514)
    -   [实例描述](#section33551554391)
    -   [结果验证](#section8931859194)


## 基本概念<a name="section1990715203418"></a>

位操作是指对二进制数的bit位进行操作。程序可以设置某一变量为状态字，状态字中的每一bit位（标志位）可以具有自定义的含义。

## 功能说明<a name="section848334511411"></a>

系统提供标志位的置1和清0操作，可以改变标志位的内容，同时还提供获取状态字中标志位为1的最高位和最低位的功能。用户也可以对系统的寄存器进行位操作。位操作模块为用户提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  位操作模块接口

<a name="table148791521769"></a>
<table><thead align="left"><tr id="row13880624615"><th class="cellrowborder" valign="top" width="16.89168916891689%" id="mcps1.2.4.1.1"><p id="p1587119571763"><a name="p1587119571763"></a><a name="p1587119571763"></a><strong id="b128711357261"><a name="b128711357261"></a><a name="b128711357261"></a><span>功能分类</span></strong></p>
</th>
<th class="cellrowborder" valign="top" width="35.54355435543554%" id="mcps1.2.4.1.2"><p id="p38714577610"><a name="p38714577610"></a><a name="p38714577610"></a><strong id="b2871195711612"><a name="b2871195711612"></a><a name="b2871195711612"></a><span>接口名称</span></strong></p>
</th>
<th class="cellrowborder" valign="top" width="47.56475647564757%" id="mcps1.2.4.1.3"><p id="p108711657563"><a name="p108711657563"></a><a name="p108711657563"></a><strong id="b10871105714617"><a name="b10871105714617"></a><a name="b10871105714617"></a><span>描述</span></strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row18801722069"><td class="cellrowborder" rowspan="2" valign="top" width="16.89168916891689%" headers="mcps1.2.4.1.1 "><p id="p108717579612"><a name="p108717579612"></a><a name="p108717579612"></a>置1/清0标志位</p>
</td>
<td class="cellrowborder" valign="top" width="35.54355435543554%" headers="mcps1.2.4.1.2 "><p id="p88717574616"><a name="p88717574616"></a><a name="p88717574616"></a>LOS_BitmapSet</p>
</td>
<td class="cellrowborder" valign="top" width="47.56475647564757%" headers="mcps1.2.4.1.3 "><p id="p16871957668"><a name="p16871957668"></a><a name="p16871957668"></a>对状态字的某一标志位进行置1操作</p>
</td>
</tr>
<tr id="row38805219612"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p68713574610"><a name="p68713574610"></a><a name="p68713574610"></a>LOS_BitmapClr</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14871155718618"><a name="p14871155718618"></a><a name="p14871155718618"></a>对状态字的某一标志位进行清0操作</p>
</td>
</tr>
<tr id="row16880112663"><td class="cellrowborder" rowspan="2" valign="top" width="16.89168916891689%" headers="mcps1.2.4.1.1 "><p id="p158710579615"><a name="p158710579615"></a><a name="p158710579615"></a>获取标志位为1的bit位</p>
</td>
<td class="cellrowborder" valign="top" width="35.54355435543554%" headers="mcps1.2.4.1.2 "><p id="p1787145718612"><a name="p1787145718612"></a><a name="p1787145718612"></a>LOS_HighBitGet</p>
</td>
<td class="cellrowborder" valign="top" width="47.56475647564757%" headers="mcps1.2.4.1.3 "><p id="p168713571468"><a name="p168713571468"></a><a name="p168713571468"></a>获取状态字中为1的最高位</p>
</td>
</tr>
<tr id="row138803219613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15871957467"><a name="p15871957467"></a><a name="p15871957467"></a>LOS_LowBitGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p148719571569"><a name="p148719571569"></a><a name="p148719571569"></a>获取状态字中为1的最低位</p>
</td>
</tr>
<tr id="row0880182168"><td class="cellrowborder" rowspan="3" valign="top" width="16.89168916891689%" headers="mcps1.2.4.1.1 "><p id="p10871957265"><a name="p10871957265"></a><a name="p10871957265"></a>连续bit位操作</p>
</td>
<td class="cellrowborder" valign="top" width="35.54355435543554%" headers="mcps1.2.4.1.2 "><p id="p787185717616"><a name="p787185717616"></a><a name="p787185717616"></a>LOS_BitmapSetNBits</p>
</td>
<td class="cellrowborder" valign="top" width="47.56475647564757%" headers="mcps1.2.4.1.3 "><p id="p10871135714613"><a name="p10871135714613"></a><a name="p10871135714613"></a>对状态字的连续标志位进行置1操作</p>
</td>
</tr>
<tr id="row12881728619"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18710575615"><a name="p18710575615"></a><a name="p18710575615"></a>LOS_BitmapClrNBits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1387145711610"><a name="p1387145711610"></a><a name="p1387145711610"></a>对状态字的连续标志位进行清0操作</p>
</td>
</tr>
<tr id="row4881192262"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1987155714611"><a name="p1987155714611"></a><a name="p1987155714611"></a>LOS_BitmapFfz</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p187115571369"><a name="p187115571369"></a><a name="p187115571369"></a>获取从最低有效位开始的第一个0的bit位</p>
</td>
</tr>
</tbody>
</table>

## 编程实例<a name="section67569495514"></a>

### 实例描述<a name="section33551554391"></a>

对数据实现位操作，本实例实现如下功能：

1.  某一标志位置1。
2.  获取标志位为1的最高bit位。
3.  某一标志位清0。
4.  获取标志位为1的最低bit位。

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

### 结果验证<a name="section8931859194"></a>

编译运行得到的结果为：

```
Bitmap Sample!
The flag is 0x10101010
LOS_BitmapSet: pos : 8,  the flag is 0x10101110
LOS_HighBitGet:The highest one bit is 28, the flag is 0x10101110
LOS_BitmapClr: pos : 28, the flag is 0x00101110
LOS_LowBitGet: The lowest one bit is 4, the flag is 0x00101110
```

