# ADC<a name="1"></a>

## Overview<a name="section1"></a>

An analog-to-digital converter (ADC) is a device that converts analog signals into digital signals.

The ADC APIs provide a set of common functions for ADC data transfer, including:
- Opening or closing an ADC device

-   Obtaining the analog-to-digital (AD) conversion result

    **Figure 1** ADC physical connection
	
    ![](figures/ADC_physical_connection.png "ADC_physical_connection")

## Available APIs<a name="section2"></a>

**Table 1** APIs of the ADC driver

<a name="table1"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.63%"><p>Category</p>
</th>
<th class="cellrowborder" valign="top" width="28.03%"><p>API</p>
</th>
<th class="cellrowborder" valign="top" width="53.339999999999996%"><p>Description</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="2" valign="top" width="18.63%"><p>Managing ADC devices</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>AdcOpen</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">Opens an ADC device.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>AdcClose</p>
</td>
<td valign="top"><p>Closes an ADC device.</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" valign="top" width="18.63%"><p>Obtaining the conversion result</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>AdcRead</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%"><p>Reads the AD conversion result.</p>
</td>
</tr>
</table>

## Usage Guidelines<a name="section3"></a>

### How to Use<a name="section4"></a>

The figure below illustrates how to use the APIs.

 **Figure 2** Using ADC driver APIs

![](figures/using-ADC-process.png "using-ADC-process.png")

### Opening an ADC Device<a name="section5"></a>

Call **AdcOpen** to open an ADC device.

```c
DevHandle AdcOpen(int16_t number);
```

**Table 2** Description of AdcOpen

<a name="table2"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.66%"><p> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.34%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.66%"><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>ADC device number.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>Failed to open the ADC device.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p>Device handle</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>Handle of the ADC device opened.</p>
</td>
</tr>
</tbody>
</table>

For example, open device 1 of the two ADCs (numbered 0 and 1) in the system.

```c
DevHandle adcHandle = NULL; /* ADC device handle /

/* Open the ADC device. */
adcHandle = AdcOpen(1);
if (adcHandle == NULL) {
    HDF_LOGE("AdcOpen: failed\n");
    return;
}
```

### Obtaining the AD Conversion Result<a name="section6"></a>

```c
int32_t AdcRead(DevHandle handle, uint32_t channel, uint32_t *val);
```

**Table 3** Description of AdcRead

<a name="table3"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>ADC device handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>channel</p>
</td>
<td class="cellrowborder"valign="top" width="50%"><p>ADC device channel number.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>val</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>AD conversion result.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Failed to obtain the AC conversion result.</p>
</td>
</tr>
</tbody>
</table>

### Closing an ADC Device<a name="section7"></a>

Call **AdcClose** to close the ADC device after the ADC communication is complete.
```c
void AdcClose(DevHandle handle); 
```
**Table 4** Description of AdcClose

<a name="table4"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p> Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p>Description</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>ADC device handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>No value is returned if the ADC device is closed.</p>
</td>
</tr>
</tbody>
</table>

Example:

```c
AdcClose(adcHandle); /* Close the ADC device. */
```

## Example<a name="section8"></a>

This following example shows how to use ADC APIs to manage an ADC device on a Hi3516D V300 development board.

The basic hardware information is as follows:

-   SoC: hi3516dv300

-   The potentiometer is connected to channel 1 of ADC device 0.

Perform continuous read operations on the ADC device to check whether the ADC is functioning.

Example:

```c
#include "adc_if.h"          /* Header file for ADC APIs */
#include "hdf_log.h"         /* Header file for log APIs */

/* Define device 0, channel 1. */
#define ADC_DEVICE_NUM 0
#define ADC_CHANNEL_NUM 1

/* Main entry of ADC routines. */
static int32_t TestCaseAdc(void)
{
    int32_t i;
    int32_t ret;
    DevHandle adcHandle;
    uint32_t readBuf[30] = {0};

    /* Open the ADC device. */
    adcHandle = AdcOpen(ADC_DEVICE_NUM);
    if (adcHandle == NULL) {
        HDF_LOGE("%s: Open ADC%u fail!", __func__, ADC_DEVICE_NUM);
        return -1;
    }

    /* Perform 30 times of AD conversions continuously and read the conversion results. */
    for (i = 0; i < 30; i++) {
        ret = AdcRead(adcHandle, ADC_CHANNEL_NUM, &readBuf[i]);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: tp ADC write reg fail!:%d", __func__, ret);
            AdcClose(adcHandle);
            return -1;
        }
    }
    HDF_LOGI("%s: ADC read successful!", __func__);

    /* Close the ADC device. */
    AdcClose(adcHandle);

    return 0;
}
```
