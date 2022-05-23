# DAC


## Overview

### DAC

A digit-to-analog converter (DAC) is a device that converts a digital signal into an analog signal in electronics.

The DAC APIs provide a set of methods for DAC data transfer, including:

- Opening or closing a DAC device
- Setting the target digital-to-analog (DA) value


### Basic Concepts

The DAC module provides the output channel for the process control computer system. It connects to the executor to implement automatic control of the production process. It is also an important module in the analog-to-digital converter using feedback technologies.

- Resolution

  The number of binary bits that can be converted by a DAC. A greater number of bits indicates a higher resolution.

- Conversion precision

  Difference between the actual output value of the DAC and the theoretical value when the maximum value is added to the input end. The conversion precision of a DAC converter varies depending on the structure of the chip integrated on the DAC and the interface circuit configuration. The ideal conversion precision value should be as small as possible. To achieve optimal DAC conversion precision, the DAC must have high resolution. In addition, errors in the devices or power supply of the interface circuits will affect the conversion precision. When the error exceeds a certain degree, a DAC conversion error will be caused.

- Conversion speed

  The conversion speed is determined by the setup time. The setup time is the period from the time the input suddenly changes from all 0s to all 1s to the time the output voltage remains within the FSR ± ½LSB (or FSR ± x%FSR). It is the maximum response time of the DAC, and hence used to measure the conversion speed.
  
  The full scale range (FSR) is the maximum range of the output signal amplitude of a DAC. Different DACs have different FSRs, which can be limited by positive and negative currents or voltages.
  
  The least significant byte (LSB) refers to bit 0 (the least significant bit) in a binary number.

### Working Principles

In the Hardware Driver Foundation (HDF), the DAC module uses the unified service mode for API adaptation. In this mode, a device service is used as the DAC manager to handle access requests from the devices of the same type in a unified manner. The unified service mode applies to the scenario where there are many device objects of the same type. If the independent service mode is used, more device nodes need to be configured and memory resources will be consumed by services. The figure below shows the unified service mode.

The DAC module is divided into the following layers:
- The interface layer provides APIs for opening or closing a device and writing data.
- The core layer provides the capabilities of binding, initializing, and releasing devices.
- The adaptation layer implements other functions.

>![](../public_sys-resources/icon-note.gif) **NOTE**<br>
>The core layer can call the functions of the interface layer and uses the hook to call functions of the adaptation layer. In this way, the adaptation layer can indirectly call the functions of the interface layer, but the interface layer cannot call the functions of the adaptation layer.

**Figure 1** Unified service mode

![](figures/unified-service-mode.png "DAC-unified-service-mode")

### Constraints

 Currently, the DAC module supports only the kernels (LiteOS) of mini and small systems.

## Development Guidelines

### When to Use

 The DAC module converts digital signals into analog signals in the form of current, voltage, or charge. It is mainly used in audio devices. Audio players and headsets use the DAC module as the digital-to-analog conversion channels.

### Available APIs

The table below describes the APIs of the DAC module. For more details, see API Reference.

**Table 1** DAC driver APIs

| API                                                     | Description        |
| :------------------------------------------------------------| :------------ |
| DevHandle DacOpen(uint32_t number)                           | Opens a DAC device. |
| void DacClose(DevHandle handle)                              | Closes a DAC device. |
| int32_t DacWrite(DevHandle handle, uint32_t channel, uint32_t val) | Sets a target DA value. |

### How to Develop

The figure below illustrates how to use the APIs.

**Figure 2** Using DAC driver APIs

![](figures/using-DAC-process.png "using-DAC-process.png")

#### Opening a DAC Device

Call **DacOpen()** to open a DAC device before performing the DA conversion.

```
DevHandle DacOpen(uint32_t number);
```

**Table 2** Description of DacOpen

| **Parameter**     | Description         |
| ---------- | ----------------- |
| number     | DAC device number.        |
| **Return Value**| **Description**  |
| NULL       | Failed to open the DAC device.  |
| Device handle  | Handle of the DAC device opened.|



Open device 1 of the two ADC devices (numbered 0 and 1) in the system.

```
DevHandle dacHandle = NULL; /* DAC device handle /

/* Open the DAC device. */
dacHandle = DacOpen(1);
if (dacHandle == NULL) {
    HDF_LOGE("DacOpen: failed\n");
    return;
}
```

#### Setting a Target DA Value

```
int32_t DacWrite(DevHandle handle, uint32_t channel, uint32_t val);
```

**Table 3** Description of DacWrite


| **Parameter**     | Description      |
| ---------- | -------------- |
| handle     | DAC device handle.   |
| channel    | DAC channel number. |
| val        | DA value to set.    |
| **Return Value**| **Description**|
| 0          | The operation is successful.      |
| Negative value      | The operation failed.      |

```
/* Write the target DA value through the DAC_CHANNEL_NUM channel. */
    ret = DacWrite(dacHandle, DAC_CHANNEL_NUM, val);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: tp DAC write reg fail!:%d", __func__, ret);
        DacClose(dacHandle);
        return -1;
    }
```

#### Closing a DAC Device

After the DAC communication is complete, call **DacClose()** to close the DAC device.
```
void DacClose(DevHandle handle);
```

**Table 4** Description of DacClose


| **Parameter**     | Description      |
| ---------- | -------------- |
| handle     | DAC device handle.   |
| **Return Value**| **Description**|
| void       | -            |



Example:

```
DacClose(dacHandle); /* Close the DAC device. */
```

## Development Example

The procedure is as follows:

1. Open the DAC device based on the device number and obtain the device handle.
2. Set the DA value. If the operation fails, close the device handle.
3. Close the DAC device handle if the access to the DAC is complete.

You can obtain the operation result by printing the log information based on the **val**.

```
#include "hdmi_if.h"          /* Header file for DAC APIs */
#include "hdf_log.h"         /* Header file for log APIs */

/* Define device 0, channel 1. */
#define DAC_DEVICE_NUM 0
#define DAC_CHANNEL_NUM 1

/* Main entry of DAC routines. */
static int32_t TestCaseDac(void)
{
    // Set the target DA value.
    uint32_t val = 2;
    int32_t ret;
    DevHandle dacHandle;

    /* Open the DAC device. */
    dacHandle = DacOpen(DAC_DEVICE_NUM);
    if (dacHandle == NULL) {
        HDF_LOGE("%s: Open DAC%u fail!", __func__, DAC_DEVICE_NUM);
        return -1;
    }

    /* Write data. */
    ret = DacWrite(dacHandle, DAC_CHANNEL_NUM, val);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: tp DAC write reg fail!:%d", __func__, ret);
        DacClose(dacHandle);
        return -1;
    }

    /* Close the DAC device. */
    DacClose(dacHandle);

    return 0;
}
```