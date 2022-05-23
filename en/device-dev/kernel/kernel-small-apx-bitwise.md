# Bitwise Operation



## Basic Concepts

A bitwise operation operates on a binary number at the level of its individual bits. For example, a variable can be set as a program status word \(PSW\), and each bit \(flag bit\) in the PSW can have a self-defined meaning.

## Available APIs<a name="section848334511411"></a>

The system provides operations for setting the flag bit to  **1**  or  **0**, changing the flag bit content, and obtaining the most significant bit and least significant bit of the flag bit 1 in a PSW. You can also perform bitwise operations on system registers. The following table describes the APIs available for the bitwise operation module. For more details about the APIs, see the API reference.

**Table  1**  Bitwise operation module APIs

<a name="table148791521769"></a>
<table><thead align="left"><tr id="row13880624615"><th class="cellrowborder" valign="top" width="16.89168916891689%" id="mcps1.2.4.1.1"><p id="p1587119571763"><a name="p1587119571763"></a><a name="p1587119571763"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="35.54355435543554%" id="mcps1.2.4.1.2"><p id="p38714577610"><a name="p38714577610"></a><a name="p38714577610"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="47.56475647564757%" id="mcps1.2.4.1.3"><p id="p108711657563"><a name="p108711657563"></a><a name="p108711657563"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18801722069"><td class="cellrowborder" rowspan="2" valign="top" width="16.89168916891689%" headers="mcps1.2.4.1.1 "><p id="p108717579612"><a name="p108717579612"></a><a name="p108717579612"></a>Setting the flag bit to <strong id="b129301229122320"><a name="b129301229122320"></a><a name="b129301229122320"></a>1</strong> or <strong id="b1899463182312"><a name="b1899463182312"></a><a name="b1899463182312"></a>0</strong></p>
</td>
<td class="cellrowborder" valign="top" width="35.54355435543554%" headers="mcps1.2.4.1.2 "><p id="p88717574616"><a name="p88717574616"></a><a name="p88717574616"></a>LOS_BitmapSet</p>
</td>
<td class="cellrowborder" valign="top" width="47.56475647564757%" headers="mcps1.2.4.1.3 "><p id="p16871957668"><a name="p16871957668"></a><a name="p16871957668"></a>Sets a flag bit of a PSW to <strong id="b1283195411179"><a name="b1283195411179"></a><a name="b1283195411179"></a>1</strong>.</p>
</td>
</tr>
<tr id="row38805219612"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p68713574610"><a name="p68713574610"></a><a name="p68713574610"></a>LOS_BitmapClr</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14871155718618"><a name="p14871155718618"></a><a name="p14871155718618"></a>Sets a flag bit of a PSW to <strong id="b15267438112312"><a name="b15267438112312"></a><a name="b15267438112312"></a>0</strong>.</p>
</td>
</tr>
<tr id="row16880112663"><td class="cellrowborder" rowspan="2" valign="top" width="16.89168916891689%" headers="mcps1.2.4.1.1 "><p id="p158710579615"><a name="p158710579615"></a><a name="p158710579615"></a>Obtaining the bit whose flag bit is <strong id="b58742415239"><a name="b58742415239"></a><a name="b58742415239"></a>1</strong></p>
</td>
<td class="cellrowborder" valign="top" width="35.54355435543554%" headers="mcps1.2.4.1.2 "><p id="p1787145718612"><a name="p1787145718612"></a><a name="p1787145718612"></a>LOS_HighBitGet</p>
</td>
<td class="cellrowborder" valign="top" width="47.56475647564757%" headers="mcps1.2.4.1.3 "><p id="p168713571468"><a name="p168713571468"></a><a name="p168713571468"></a>Obtains the most significant bit of <strong id="b485014714235"><a name="b485014714235"></a><a name="b485014714235"></a>1</strong> in the PSW.</p>
</td>
</tr>
<tr id="row138803219613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15871957467"><a name="p15871957467"></a><a name="p15871957467"></a>LOS_LowBitGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p148719571569"><a name="p148719571569"></a><a name="p148719571569"></a>Obtains the least significant bit of <strong id="b9907125542319"><a name="b9907125542319"></a><a name="b9907125542319"></a>1</strong> in the PSW.</p>
</td>
</tr>
<tr id="row0880182168"><td class="cellrowborder" rowspan="3" valign="top" width="16.89168916891689%" headers="mcps1.2.4.1.1 "><p id="p10871957265"><a name="p10871957265"></a><a name="p10871957265"></a>Operating continuous bits</p>
</td>
<td class="cellrowborder" valign="top" width="35.54355435543554%" headers="mcps1.2.4.1.2 "><p id="p787185717616"><a name="p787185717616"></a><a name="p787185717616"></a>LOS_BitmapSetNBits</p>
</td>
<td class="cellrowborder" valign="top" width="47.56475647564757%" headers="mcps1.2.4.1.3 "><p id="p10871135714613"><a name="p10871135714613"></a><a name="p10871135714613"></a>Sets the continuous flag bits of a PSW to <strong id="b145631313234"><a name="b145631313234"></a><a name="b145631313234"></a>1</strong>.</p>
</td>
</tr>
<tr id="row12881728619"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18710575615"><a name="p18710575615"></a><a name="p18710575615"></a>LOS_BitmapClrNBits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1387145711610"><a name="p1387145711610"></a><a name="p1387145711610"></a>Sets the continuous flag bits of a PSW to <strong id="b185031722103115"><a name="b185031722103115"></a><a name="b185031722103115"></a>0</strong>.</p>
</td>
</tr>
<tr id="row4881192262"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1987155714611"><a name="p1987155714611"></a><a name="p1987155714611"></a>LOS_BitmapFfz</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p187115571369"><a name="p187115571369"></a><a name="p187115571369"></a>Obtains the first 0 bit starting from the least significant bit (LSB).</p>
</td>
</tr>
</tbody>
</table>

## Development Example<a name="section67569495514"></a>

### Example Description<a name="section33551554391"></a>

This example implements the following:

1.  Set a flag bit to  **1**.
2.  Obtain the most significant bit of flag bit 1.
3.  Set a flag bit to  **0**.
4.  Obtain the least significant bit of the flag bit 1.

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

### Verification

The development is successful if the return result is as follows:

```
Bitmap Sample!
The flag is 0x10101010
LOS_BitmapSet: pos : 8,  the flag is 0x10101110
LOS_HighBitGet:The highest one bit is 28, the flag is 0x10101110
LOS_BitmapClr: pos : 28, the flag is 0x00101110
LOS_LowBitGet: The lowest one bit is 4, the flag is 0x00101110
```

