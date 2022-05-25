# PWM


## Overview

Pulse width modulation (PWM) is a technology that digitally encodes analog signal levels and converts them into pulses. It can be used for motor control and backlight brightness adjustment.

  The PWM APIs provide a set of functions for operating a PWM device, including those for:
- Opening or closing a PWM device handle

- Setting the PWM period, signal ON-state time, and polarity

- Enabling and disabling a PWM device

- Obtaining and setting PWM parameters


### PwmConfig Structure

  **Table 1** PwmConfig structure

| Parameter| Description| 
| -------- | -------- |
| duty | Time that a signal is in the ON state, in ns.| 
| period | Time for a signal to complete an on-and-off cycle, in ns.| 
| number | Number of square waves to generate.<br>-&nbsp;Positive value: indicates the number of square waves to generate.<br>-&nbsp;**0**: indicates that square waves are generated continuously.| 
| polarity | PWM signal polarity, which can be positive or reverse.| 
| status | PWM device status, which can be enabled or disabled.| 


## Available APIs

  **Table 2** PWM driver APIs

| Category| Description| 
| -------- | -------- |
| Operating PWM handles| -&nbsp;**PwmOpen**: opens the device handle of a PWM device.<br>-&nbsp;**PwmClose**: closes the device handle of a PWM device.| 
| Enabling or disabling PWM| -&nbsp;**PwmEnable**: enables a PWM device.<br>-&nbsp;**PwmDisable**: disables a PWM device.| 
| Setting PWM| -&nbsp;**PwmSetPeriod**: sets the PWM period.<br>-&nbsp;**PwmSetDuty**: sets the signal ON-state time.<br>-&nbsp;**PwmSetPolarity**: sets the PWM signal polarity.| 
| Setting or obtaining PWM configuration| -&nbsp;**PwmSetConfig**: sets PWM device parameters.<br>-&nbsp;**PwmGetConfig**: obtains PWM device parameters.| 

> ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**<br/>
> All APIs described in this document can be called only in the kernel space.


## Usage Guidelines


### How to Use

The figure below illustrates how to use the APIs.

**Figure 1** Using the PWM driver APIs

![](figures/using-PWM-process.png)


### Opening a PWM Device Handle

Before performing operations on a PWM device, call **PwmOpen** to open the device handle.


```
DevHandle PwmOpen(uint32_t num);
```

  **Table 3** Description of PwmOpen

| **Parameter**| **Description**|
| -------- | -------- |
| num        | PWM device number.            |
| **Return Value** | **Description**         |
| handle     | Handle of the PWM device obtained.|
| NULL       | The operation failed.             |

Example: Open the device handle of PWM device 0.


```
uint32_t num = 0;             /* PWM device number. */
DevHandle handle = NULL;

/* Obtain the PWM device handle. */
handle = PwmOpen(num);
if (handle  == NULL) {
    /* Error handling. */
}
```


### Closing a PWM Device Handle

Call **PwmClose()** to close a PWM device handle to release resources.


```
voidPwmClose(DevHandle handle);
```

  **Table 4** Description of PwmClose

| **Parameter**| **Description**|
| -------- | -------- |
| handle   | PWM device handle to close. |


```
/* Close a PWM device handle. */
PwmClose(handle);
```


### Enabling a PWM Device

Call **PwmEnable()** to enable a PWM device.


```
int32_t PwmEnable(DevHandle handle);
```

  **Table 5** Description of PwmEnable

| **Parameter**| **Description**|
| -------- | -------- |
| handle     | PWM device handle.   |
| **Return Value** | **Description** |
| 0          | The operation is successful.      |
| Negative number      | The operation failed.    |


```
int32_t ret;

/* Enable a PWM device. */
ret = PwmEnable(handle);
if (ret != 0) {
	/* Error handling. */
}
```


### Disabling a PWM Device

Call **PwmDisable()** to disable a PWM device.


```
int32_t PwmDisable(DevHandle handle);
```

  **Table 6** Description of PwmDisable

| **Parameter**| **Description**|
| -------- | -------- |
| handle     | PWM device handle.   |
| **Return Value** | **Description** |
| 0          | The operation is successful.      |
| Negative number      | The operation failed.     |


```
int32_t ret;

/* Disable a PWM device. */
ret = PwmDisable(handle);
if (ret != 0) {
	/* Error handling. */
}
```


### Setting the PWM Period

Call **PwmSetPeriod()** to set the PWM period.


```
int32_t PwmSetPeriod(DevHandle handle, uint32_t period);
```

  **Table 7** Description of PwmSetPeriod

| **Parameter**| **Description**|
| -------- | -------- |
| handle     | PWM device handle.             |
| period     | PWM period to set, in ns.|
| **Return Value**| **Description**           |
| 0          | The operation is successful.                |
| Negative number      | The operation failed.              |


```
int32_t ret;

/* Set the PWM period to 50000000 ns.*/
ret = PwmSetPeriod(handle, 50000000);
if (ret != 0) {
	/* Error handling. */
}
```


### Setting the PWM Signal ON-State Time

Call **PwmSetDuty()** to set the time that the PWM signal is in the ON state.


```
int32_t PwmSetDuty(DevHandle handle, uint32_t duty);
```

  **Table 8** Description of PwmSetDuty

| **Parameter**| **Description**|
| -------- | -------- |
| handle     | PWM device handle.                 |
| duty       | Time that the signal is in the ON state, in ns.|
| **Return Value**| **Description**               |
| 0          | The operation is successful.                    |
| Negative number      | The operation failed.                  |


```
int32_t ret;

/* Set the signal ON-state time to 25000000 ns. */
ret = PwmSetDuty(handle, 25000000);
if (ret != 0) {
	/* Error handling. */
}
```


### Setting the PWM Signal Polarity

Call **PwmSetPolarity()** to set the signal polarity for a PWM device.


```
int32_t PwmSetPolarity(DevHandle handle, uint8_t polarity);
```

  **Table 9** Description of PwmSetPolarity

| **Parameter**| **Description**|
| -------- | -------- |
| handle     | PWM device handle.        |
| polarity   | Polarity to set, which can be **PWM\_NORMAL\_POLARITY** or **PWM\_INVERTED\_POLARITY**.|
| **Return Value**| **Description**      |
| 0          | The operation is successful.           |
| Negative number      | The operation failed.          |


```
int32_t ret;

/* Set the PWM polarity to PWM_INVERTED_POLARITY. */
ret = PwmSetPolarity(handle, PWM_INVERTED_POLARITY);
if (ret != 0) {
	/* Error handling. */
}
```


### Setting PWM Device Parameters

Call **PwmSetConfig()** to set PWM device parameters.


```
int32_t PwmSetConfig(DevHandle handle, struct PwmConfig *config);
```

  **Table 10** Description of PwmSetConfig

| **Parameter**| **Description**|
| -------- | -------- |
| handle     | PWM device handle to close.   |
| \*config   | Pointer to PWM parameters.      |
| **Return Value**| **Description** |
| 0          | The operation is successful.      |
| Negative number      | The operation failed.    |


```
int32_t ret;
struct PwmConfig pcfg;
pcfg.duty = 25000000;			/* Set the signal ON-state time to 25000000 ns. */                 
pcfg.period = 50000000;			/* Set the PWM period to 50000000 ns. */
pcfg.number = 0;			/* Generate square waves repeatedly. */
pcfg.polarity = PWM_INVERTED_POLARITY;	/* Set the PWM polarity to PWM_INVERTED_POLARITY. */
pcfg.status = PWM_ENABLE_STATUS;	/* Set the running status to Enabled. */

/* Set PWM device parameters. */
ret = PwmSetConfig(handle, &pcfg);
if (ret != 0) {
	/* Error handling. */
}
```


### Obtaining PWM Device Parameters

Call **PwmGetConfig()** to obtain PWM device parameters.


```
int32_t PwmGetConfig(DevHandle handle, struct PwmConfig *config);
```

  **Table 11** Description of PwmGetConfig

| **Parameter**| **Description**|
| -------- | -------- |
| handle     | PWM device handle to close.   |
| \*config   | Pointer to PWM parameters.      |
| **Return Value**| **Description** |
| 0          | The operation is successful.      |
| Negative number      | The operation failed.    |


```
int32_t ret;
struct PwmConfig pcfg;

/* Obtain PWM device parameters. */
ret = PwmGetConfig(handle, &pcfg);
if (ret != 0) {
	/* Error handling. */
}
```


## Development Example

The following example shows how to use the APIs to implement a PWM driver and manage the PWM device.


```
void PwmTestSample(void)
{
    int32_t ret;
    uint32_t num;
    DevHandle handle = NULL;

    struct PwmConfig pcfg;
    pcfg.duty = 20000000;			/* Set the signal ON-state time to 20000000 ns. */                 
    pcfg.period = 40000000;			/* Set the PWM period to 40000000 ns. */
    pcfg.number = 100;				/* Generate 100 square waves. */
    pcfg.polarity = PWM_NORMAL_POLARITY;	/* Set the polarity to PWM_NORMAL_POLARITY. */
    pcfg.status = PWM_ENABLE_STATUS;		/* Set the running status to Enabled. */

    /* Enter the PWM device number. */
    num = 1; 

    /* Open the PWM device handle. */
    handle = PwmOpen(num);
    if (handle == NULL) {
        HDF_LOGE("PwmOpen: failed!\n");
        return;
    }

    /* Set the PWM period to 50000000 ns.*/
    ret = PwmSetPeriod(handle, 50000000);
    if (ret != 0) {
        HDF_LOGE("PwmSetPeriod: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* Set the signal ON-state time to 25000000 ns. */
    ret = PwmSetDuty(handle, 25000000);
    if (ret != 0) {
        HDF_LOGE("PwmSetDuty: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* Set the PWM polarity to PWM_INVERTED_POLARITY. */
    ret = PwmSetPolarity(handle, PWM_INVERTED_POLARITY);
    if (ret != 0) {
        HDF_LOGE("PwmSetPolarity: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* Obtain PWM device parameters. */
    ret = PwmGetConfig(handle, &pcfg);
    if (ret != 0) {
        HDF_LOGE("PwmGetConfig: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* Enable the PWM device. */
    ret = PwmEnable(handle);
    if (ret != 0) {
	    HDF_LOGE("PwmEnable: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* Set PWM device parameters. */
    ret = PwmSetConfig(handle, &pcfg);
    if (ret != 0) {
        HDF_LOGE("PwmSetConfig: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* Disable the PWM device. */
    ret = PwmDisable(handle);
    if (ret != 0) {
        HDF_LOGE("PwmDisable: failed, ret %d\n", ret);
        goto _ERR;
    }

_ERR:
    /* Close the PWM device handle. */
    PwmClose(handle); 
}
```
