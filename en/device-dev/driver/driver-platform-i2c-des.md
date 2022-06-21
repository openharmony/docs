# I2C<a name="EN-US_TOPIC_0000001206171515"></a>

## Overview<a name="section5361140416"></a>

The Inter-Integrated Circuit \(I2C\) is a simple, bidirectional, and synchronous serial bus that uses merely two wires.

In an I2C communication, one controller communicates with one or more devices through the serial data line \(SDA\) and serial clock line \(SCL\), as shown in the figure below.

I2C data transfer must begin with a  **START**  condition and end with a  **STOP**  condition. Data is transmitted byte-by-byte from the most significant bit to the least significant bit.

Each I2C node is recognized by a unique address and can serve as either a controller or a device. When the controller needs to communicate with a device, it writes the device address to the bus through broadcast. A device matching this address sends a response to set up a data transfer channel.

The I2C APIs define a set of common functions for I2C data transfer, including:

-   I2C controller management: opening or closing an I2C controller
-   I2C message transfer: custom transfer by using a message array

**Figure  1**  Physical connection diagram for I2C<br/>![](figures/physical-connection-diagram-for-i2c.png "physical-connection-diagram-for-i2c")


## Available APIs<a name="section545869122317"></a>

**Table  1**  APIs available for the I2C driver

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="18.63%" id="mcps1.2.4.1.1"><p id="p641050105320"><a name="p641050105320"></a><a name="p641050105320"></a>Capability</p>
</th>
<th class="cellrowborder" valign="top" width="28.03%" id="mcps1.2.4.1.2"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="53.339999999999996%" id="mcps1.2.4.1.3"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row34145016535"><td class="cellrowborder" rowspan="2" valign="top" width="18.63%" headers="mcps1.2.4.1.1 "><p id="p229610227124"><a name="p229610227124"></a><a name="p229610227124"></a>I2C controller management</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%" headers="mcps1.2.4.1.2 "><p id="p19389143041518"><a name="p19389143041518"></a><a name="p19389143041518"></a>I2cOpen</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p8738101941716"><a name="p8738101941716"></a><a name="p8738101941716"></a>Opens an I2C controller.</p>
</td>
</tr>
<tr id="row5632152611414"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p143890309153"><a name="p143890309153"></a><a name="p143890309153"></a>I2cClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p573815197171"><a name="p573815197171"></a><a name="p573815197171"></a>Closes an I2C controller.</p>
</td>
</tr>
<tr id="row15108165391412"><td class="cellrowborder" valign="top" width="18.63%" headers="mcps1.2.4.1.1 "><p id="p91084533141"><a name="p91084533141"></a><a name="p91084533141"></a>I2C message transfer</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%" headers="mcps1.2.4.1.2 "><p id="p13901730101511"><a name="p13901730101511"></a><a name="p13901730101511"></a>I2cTransfer</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p12738111912171"><a name="p12738111912171"></a><a name="p12738111912171"></a>Performs a custom transfer.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>All functions provided in this document can be called only in kernel mode.

## Usage Guidelines<a name="section1695201514281"></a>

### How to Use<a name="section1338373417288"></a>

The figure below illustrates how to use the APIs.

**Figure  2**  Using I2C driver APIs

![](figures/using-i2c-process.png "process-of-using-an-i2c-device")

### Opening an I2C Controller<a name="section13751110132914"></a>

Call the **I2cOpen()** function to open an I2C controller.

DevHandle I2cOpen\(int16\_t number\);

**Table  2**  Description of I2cOpen

<a name="table7603619123820"></a>
<table><thead align="left"><tr id="row1060351914386"><th class="cellrowborder" valign="top" width="20.66%" id="mcps1.2.3.1.1"><p id="p14603181917382"><a name="p14603181917382"></a><a name="p14603181917382"></a><strong id="b72871132125714"><a name="b72871132125714"></a><a name="b72871132125714"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.34%" id="mcps1.2.3.1.2"><p id="p36031519183819"><a name="p36031519183819"></a><a name="p36031519183819"></a><strong id="b1721203713577"><a name="b1721203713577"></a><a name="b1721203713577"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1960431983813"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.2.3.1.1 "><p id="p3604719123817"><a name="p3604719123817"></a><a name="p3604719123817"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.2.3.1.2 "><p id="p221392414442"><a name="p221392414442"></a><a name="p221392414442"></a>I2C controller ID.</p>
</td>
</tr>
<tr id="row11410612183019"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.2.3.1.1 "><p id="p460381915385"><a name="p460381915385"></a><a name="p460381915385"></a><strong id="b14182113945714"><a name="b14182113945714"></a><a name="b14182113945714"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.2.3.1.2 "><p id="p96031619153812"><a name="p96031619153812"></a><a name="p96031619153812"></a><strong id="b92161640145714"><a name="b92161640145714"></a><a name="b92161640145714"></a>Description</strong></p>
</td>
</tr>
<tr id="row15410111273017"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.2.3.1.1 "><p id="p1060418195389"><a name="p1060418195389"></a><a name="p1060418195389"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.2.3.1.2 "><p id="p760471912388"><a name="p760471912388"></a><a name="p760471912388"></a>Failed to open the I2C controller.</p>
</td>
</tr>
<tr id="row1241081213303"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.2.3.1.1 "><p id="p5604719133811"><a name="p5604719133811"></a><a name="p5604719133811"></a>Device handle</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.2.3.1.2 "><p id="p3604181933818"><a name="p3604181933818"></a><a name="p3604181933818"></a>Handle of the I2C controller.</p>
</td>
</tr>
</tbody>
</table>

This example assumes that the system has eight I2C controllers \(numbered from 0 to 7\) and I2C controller 3 is to open.

```
DevHandle i2cHandle = NULL; /* I2C controller handle */

/* Open an I2C controller. */
i2cHandle = I2cOpen(3);
if (i2cHandle == NULL) {
    HDF_LOGE("I2cOpen: failed\n");
    return;
}
```

### Performing I2C Communication<a name="section9202183372916"></a>

Call the **I2cTransfer()** function to transfer messages.

int32\_t I2cTransfer\(DevHandle handle, struct I2cMsg \*msgs, int16\_t count\);

**Table  3**  Description of I2cTransfer

<a name="table1934414174212"></a>
<table><thead align="left"><tr id="row1134415176216"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p13295152320217"><a name="p13295152320217"></a><a name="p13295152320217"></a><strong id="b16680203655712"><a name="b16680203655712"></a><a name="b16680203655712"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p1295112352115"><a name="p1295112352115"></a><a name="p1295112352115"></a><strong id="b183651837145710"><a name="b183651837145710"></a><a name="b183651837145710"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row5344101702113"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p19295132382111"><a name="p19295132382111"></a><a name="p19295132382111"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1051172572919"><a name="p1051172572919"></a><a name="p1051172572919"></a>Handle of an I2C controller.</p>
</td>
</tr>
<tr id="row17344171722117"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9295122332113"><a name="p9295122332113"></a><a name="p9295122332113"></a>msgs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p202951238218"><a name="p202951238218"></a><a name="p202951238218"></a>Message array of the data to transfer.</p>
</td>
</tr>
<tr id="row45812466213"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1659246112117"><a name="p1659246112117"></a><a name="p1659246112117"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p259124622119"><a name="p259124622119"></a><a name="p259124622119"></a>Length of the message array.</p>
</td>
</tr>
<tr id="row04701426105110"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17295142322113"><a name="p17295142322113"></a><a name="p17295142322113"></a><strong id="b9681123965720"><a name="b9681123965720"></a><a name="b9681123965720"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p142959232211"><a name="p142959232211"></a><a name="p142959232211"></a><strong id="b1159414403579"><a name="b1159414403579"></a><a name="b1159414403579"></a>Description</strong></p>
</td>
</tr>
<tr id="row74701226125110"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p929532313211"><a name="p929532313211"></a><a name="p929532313211"></a>Positive integer</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p829512237217"><a name="p829512237217"></a><a name="p829512237217"></a>Number of message structures that are successfully transmitted.</p>
</td>
</tr>
<tr id="row204701126195115"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12958234217"><a name="p12958234217"></a><a name="p12958234217"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1295192312112"><a name="p1295192312112"></a><a name="p1295192312112"></a>Failed to perform the message transfer.</p>
</td>
</tr>
</tbody>
</table>

The type of an I2C message transfer is defined by  **I2cMsg**. Each message structure indicates a read or write operation. Multiple read or write operations can be performed by using a message array.

```
int32_t ret;
uint8_t wbuff[2] = { 0x12, 0x13 };
uint8_t rbuff[2] = { 0 };
struct I2cMsg msgs[2]; /* Custom message array for transfer */
msgs[0].buf = wbuff;    /* Data to write */
msgs[0].len = 2;        /* The length of the data to write is 2. */
msgs[0].addr = 0x5A;    /* The address of the device to write the data is 0x5A. */
msgs[0].flags = 0;      /* The flag is 0, indicating the write operation. */
msgs[1].buf = rbuff;    /* Data to read */
msgs[1].len = 2;        /* The length of the data to read is 2. */
msgs[1].addr = 0x5A;    /* The address of the device to read is 0x5A. */
msgs[1].flags = I2C_FLAG_READ /* I2C_FLAG_READ is configured, indicating the read operation. */
/* Perform a custom transfer to transfer two messages. */
ret = I2cTransfer(i2cHandle, msgs, 2);
if (ret != 2) {
    HDF_LOGE("I2cTransfer: failed, ret %d\n", ret);
    return;
}
```

>![](../public_sys-resources/icon-caution.gif) **CAUTION**<br/>
>-   The device address in the  **I2cMsg**  structure does not contain the read/write flag bit. The read/write information is transferred by the read/write control bit in the member variable  **flags**.
>-   The  **I2cTransfer**  function does not limit the number of message structures and the data length of each message structure, which are determined by the I2C controller.
>-   The  **I2cTransfer**  function may cause the system to sleep and therefore cannot be called in the interrupt context.

### Closing an I2C Controller<a name="section19481164133018"></a>

Call the **I2cClose()** function to close the I2C controller after the communication is complete.

void I2cClose\(DevHandle \*handle\); 

**Table  4**  Description of I2cClose

<a name="table72517953115"></a>
<table><thead align="left"><tr id="row1525793312"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p115402031153111"><a name="p115402031153111"></a><a name="p115402031153111"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p65406313319"><a name="p65406313319"></a><a name="p65406313319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1926109193116"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p105419317318"><a name="p105419317318"></a><a name="p105419317318"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1213245577"><a name="p1213245577"></a><a name="p1213245577"></a>Handle of the I2C controller to close.</p>
</td>
</tr>
</tbody>
</table>


```
I2cClose(i2cHandle); /* Close the I2C controller. */
```

## Usage Example<a name="section5302202015300"></a>

This example describes how to use I2C APIs with an I2C device on a development board.

This example shows a simple register read/write operation on TouchPad on a Hi3516D V300 development board. The basic hardware information is as follows:

-   SoC: hi3516dv300

-   Touch IC: The I2C address is 0x38, and the bit width of Touch IC's internal register is 1 byte.

-   Schematic diagram: TouchPad is mounted to I2C controller 3. The reset pin of Touch IC is GPIO3.

In this example, first we reset Touch IC. \(The development board supplies power to Touch IC by default after being powered on, and this use case does not consider the power supply\). Then, we perform a read/write operation on an internal register to test whether the I2C channel is normal.

>![](../public_sys-resources/icon-note.gif) **NOTE** <br/>
>The example focuses on I2C device access and verifies the I2C channel. The read and write values of the device register are not concerned. The behavior caused by the read and write operations on the register is determined by the device itself.

Example:

```
#include "i2c_if.h"          /* Header file of I2C APIs */
#include "gpio_if.h"         /* Header file of GPIO APIs */
#include "hdf_log.h"         /* Header file for log APIs */
#include "osal_io.h"         /* Header file of I/O read and write APIs */
#include "osal_time.h"       /* Header file of delay and sleep APIs */

/* Define a TP device structure to store I2C and GPIO hardware information. */
struct TpI2cDevice {
    uint16_t rstGpio;             /* Reset pin */
    uint16_t busId;               /* I2C bus ID */
    uint16_t addr;                /* I2C device address */
    uint16_t regLen;              /* Register bit width */
    DevHandle i2cHandle;  /* I2C controller handle */
};

/* I2C pin I/O configuration. For details, see the SoC register manual. */
#define I2C3_DATA_REG_ADDR 0x112f008c /* Address of the SDA pin configuration register of I2C controller 3
#define I2C3_CLK_REG_ADDR 0x112f0090 /* Address of the SCL pin configuration register of I2C controller 3
#define I2C_REG_CFG 0x5f1             /* Configuration values of SDA and SCL pins of I2C controller 3

static void TpSocIoCfg(void)
{
    /* Set the I/O function of the two pins corresponding to I2C controller 3 to I2C. */
    OSAL_WRITEL(I2C_REG_CFG, IO_DEVICE_ADDR(I2C3_DATA_REG_ADDR));
    OSAL_WRITEL(I2C_REG_CFG, IO_DEVICE_ADDR(I2C3_CLK_REG_ADDR));
}

/* Initialize the reset pin of the TP. Pull up the pin for 20 ms, pull down the pin for 50 ms, and then pull up the pin for 20 ms to complete the resetting. */
static int32_t TestCaseGpioInit(struct TpI2cDevice *tpDevice)
{
    int32_t ret;

    /* Set the output direction for the reset pin. */
    ret = GpioSetDir(tpDevice->rstGpio, GPIO_DIR_OUT);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set rst dir fail!:%d", __func__, ret);
        return ret;
    }

    ret = GpioWrite(tpDevice->rstGpio, GPIO_VAL_HIGH);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set rst hight fail!:%d", __func__, ret);
        return ret;
    }
    OsalMSleep(20);

    ret = GpioWrite(tpDevice->rstGpio, GPIO_VAL_LOW);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set rst low fail!:%d", __func__, ret);
        return ret;
    }
    OsalMSleep(50);

    ret = GpioWrite(tpDevice->rstGpio, GPIO_VAL_HIGH);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set rst high fail!:%d", __func__, ret);
        return ret;
    }
    OsalMSleep(20);

    return HDF_SUCCESS;
}

/* Use I2cTransfer to encapsulate a register read/write auxiliary function. Use flag to indicate the read or write operation. */
static int TpI2cReadWrite(struct TpI2cDevice *tpDevice, unsigned int regAddr,
    unsigned char *regData, unsigned int dataLen, uint8_t flag)
{
    int index = 0;
    unsigned char regBuf[4] = {0};
    struct I2cMsg msgs[2] = {0};

    /* Perform length adaptation for the single- or dual-byte register. */
    if (tpDevice->regLen == 1) { 
        regBuf[index++] = regAddr & 0xFF;
    } else {
        regBuf[index++] = (regAddr >> 8) & 0xFF;
        regBuf[index++] = regAddr & 0xFF;
    }

    /* Fill in the I2cMsg message structure. */
    msgs[0].addr = tpDevice->addr;
    msgs[0].flags = 0; /* The flag is 0, indicating the write operation. */
    msgs[0].len = tpDevice->regLen;
    msgs[0].buf = regBuf;

    msgs[1].addr = tpDevice->addr;
    msgs[1].flags = (flag == 1)? I2C_FLAG_READ: 0; /* Add the read flag. */
    msgs[1].len = dataLen;
    msgs[1].buf = regData;

    if (I2cTransfer(tpDevice->i2cHandle, msgs, 2) != 2) {
        HDF_LOGE("%s: i2c read err", __func__);
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}

/* TP register read function */
static inline int TpI2cReadReg(struct TpI2cDevice *tpDevice, unsigned int regAddr,
    unsigned char *regData, unsigned int dataLen)
{
    return TpI2cReadWrite(tpDevice, regAddr, regData, dataLen, 1);
}

/* TP register write function */
static inline int TpI2cWriteReg(struct TpI2cDevice *tpDevice, unsigned int regAddr,
    unsigned char *regData, unsigned int dataLen)
{
    return TpI2cReadWrite(tpDevice, regAddr, regData, dataLen, 0);
}

/* Main entry of I2C */
static int32_t TestCaseI2c(void)
{
    int32_t i;
    int32_t ret;
    unsigned char bufWrite[7] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xA, 0xB, 0xC };
    unsigned char bufRead[7] = {0};
    static struct TpI2cDevice tpDevice;

    /* I/O pin function configuration */
    TpSocIoCfg();

    /* Initialize TP device information. */
    tpDevice.rstGpio = 3;
    tpDevice.busId = 3;
    tpDevice.addr = 0x38;
    tpDevice.regLen = 1;
    tpDevice.i2cHandle = NULL;

    /* Initialize the GPIO pin. */
    ret = TestCaseGpioInit(&tpDevice);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: gpio init fail!:%d", __func__, ret);
        return ret;
    }

    /* Open an I2C controller. */
    tpDevice.i2cHandle = I2cOpen(tpDevice.busId);
    if (tpDevice.i2cHandle == NULL) {
        HDF_LOGE("%s: Open I2c:%u fail!", __func__, tpDevice.busId);
        return -1;
    }

    /* Continuously write 7-byte data to register 0xD5 of TP-IC. */
    ret = TpI2cWriteReg(&tpDevice, 0xD5, bufWrite, 7);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: tp i2c write reg fail!:%d", __func__, ret);
        I2cClose(tpDevice.i2cHandle);
        return -1;
    }
    OsalMSleep(10);

    /* Continuously read 7-byte data from register 0xD5 of TP-IC. */
    ret = TpI2cReadReg(&tpDevice, 0xD5, bufRead, 7);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: tp i2c read reg fail!:%d", __func__, ret);
        I2cClose(tpDevice.i2cHandle);
        return -1;
    }

    HDF_LOGE("%s: tp i2c write&read reg success!", __func__);
    for (i = 0; i < 7; i++) {
        HDF_LOGE("%s: bufRead[%d] = 0x%x", __func__, i, bufRead[i]);
    }

    /* Close the I2C controller. */
    I2cClose(tpDevice.i2cHandle);
    return ret;
}
```

