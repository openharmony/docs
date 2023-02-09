# Bitwise Operation


## Basic Concepts

A bitwise operation operates on the bits of a binary number. A variable can be set as a program status word (PSW), and each bit (flag bit) in the PSW can have a self-defined meaning.


## **Available APIs**

The system provides operations for setting the flag bit to **1** or **0**, changing the flag bit content, and obtaining the most significant bit (MSB) and least significant bit (LSB) of the flag bit 1 in a PSW. You can also perform bitwise operations on system registers. The following table describes the APIs available for the bitwise operation module. For more details about the APIs, see the API reference.

  **Table 1** APIs of the bitwise operation module

| Category | API Description |
| -------- | -------- |
| Setting a flag bit| - **LOS_BitmapSet**: sets a flag bit of a PSW to **1**.<br>- **LOS_BitmapClr**: sets a flag bit of a PSW to **0**. |
| Obtaining the bit whose flag bit is **1**| -**LOS_HighBitGet**: obtains the most significant bit of 1 in a PSW.<br>- **LOS_LowBitGet**: obtains the least significant bit of 1 in a PSW. |
| Operating continuous bits| - **LOS_BitmapSetNBits**: sets the consecutive flag bits of a PSW to **1**.<br>- **LOS_BitmapClrNBits**: sets the consecutive flag bits of a PSW to **0**.<br>- **LOS_BitmapFfz**: obtains the first 0 bit starting from the LSB. |


## Development Example


### Example Description

This example implements the following:

1. Set a flag bit to **1**.

2. Obtain the MSB of flag bit 1.

3. Set a flag bit to **0**.

4. Obtain the LSB of flag bit 1.

### Sample Code

The sample code can be compiled and verified in **./kernel/liteos_a/testsuites/kernel/src/osTest.c**. The **BitSample** function is called in **TestTaskEntry**.

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
