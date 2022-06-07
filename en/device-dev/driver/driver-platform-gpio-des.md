# GPIO


## Overview

A general-purpose input/output (GPIO) controller manages all GPIO pins by group. Each group of GPIO pins is associated with one or more registers. The GPIO controller manages the pins by reading data from and writing data to the registers.

The GPIO APIs define a set of standard functions for performing operations on GPIO pins, including:

- Setting the pin direction, which can be input or output (high impedance is not supported currently)

- Reading and writing the pin level, which can be low or high

- Setting the interrupt service routine (ISR) function and interrupt trigger mode for a pin

- Enabling or disabling interrupts for a pin


## Available APIs

  **Table 1** GPIO driver APIs

| Category| Description| 
| -------- | -------- |
| GPIO read/write| -&nbsp;**GpioRead**: reads the pin level.<br>-&nbsp;**GpioWrite**: writes the pin level.| 
| GPIO settings| -&nbsp;**GpioSetDir**: sets the pin direction.<br>-&nbsp;**GpioGetDir**: obtains the pin direction.| 
| GPIO interrupt settings| -&nbsp;**GpioSetIrq**: sets the ISR function for a GPIO pin.<br>-&nbsp;**GpioUnsetIrq**: cancels the ISR function setting for a GPIO pin.<br>-&nbsp;**GpioEnableIrq**: enables interrupts for a pin.<br>-&nbsp;**GpioDisableIrq**: disables interrupts for a pin.| 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> All APIs described in this document can be called only in kernel mode.


## Usage Guidelines


### How to Use

The figure below shows the general GPIO development process. In the APIs, a GPIO pin is specified by the pin number.

**Figure  1** Using GPIO driver APIs

![](figures/using-GPIO-process.png "using-gpio-process.png")


### Determining the GPIO Pin Number

The method for determining the GPIO pin number varies depending on the GPIO controller model, parameters, and controller driver of the system on chip (SoC).

- Hi3516D V300
  A controller manages 12 groups of GPIO pins. Each group contains 8 GPIO pins. The group number ranges from 0 to 11. 

  GPIO pin number = GPIO group number x Number of GPIO pins in each group + Offset in the group

  Example: 

  GPIO pin number of GPIO10_3 = 10 x 8 + 3 = 83
  
- Hi3518E V300
  A controller manages 10 groups of GPIO pins. Each group contains 10 GPIO pins. The group number ranges from 0 to 9. 

  GPIO pin number = GPIO group number x Number of GPIO pins in each group + Offset in the group

  Example: 
  
  GPIO pin number of GPIO7_3 = 7 x 10 + 3 = 73


### Using APIs to Operate GPIO Pins

- Set the GPIO pin direction.
  Before performing read/write operations on a GPIO pin, call **GpioSetDir()** to set the pin direction.

  ```c
  int32_t GpioSetDir(uint16_t gpio, uint16_t dir);
  ```

    **Table 2** Description of GpioSetDir
  
  | **Parameter**| **Description**|
  | -------- | -------- |
  | gpio | GPIO pin number.| 
  | dir | Direction to set.| 
  | **Return Value**| **Description**| 
  | 0 | The operation is successful.| 
  | Negative value| The operation failed.| 

- Read or write the pin level.

  Call **GpioRead()** to read the level of a GPIO pin.

  ```c
  int32_t GpioRead(uint16_t gpio, uint16_t *val);
  ```

    **Table 3** Description of GpioRead
  
  | **Parameter**| **Description**| 
  | -------- | -------- | 
  | gpio | GPIO pin number.| 
  | val | Pointer to the level to read.| 
  | **Return Value**| **Description**| 
  | 0 | The operation is successful.| 
  | Negative value| The operation failed.| 

  Call **GpioWrite()** to write the level for a GPIO pin.

  ```c
  int32_t GpioWrite(uint16_t gpio, uint16_t val);
  ``` 
 
    **Table 4** Description of GpioWrite
  
  | **Parameter**| **Description**| 
  | -------- | -------- |
  | gpio | GPIO pin number.| 
  | val | Level to write.| 
  | **Return Value**| **Description**| 
  | 0 | The operation is successful.| 
  | Negative value| The operation failed.| 

  Sample code:

  
  ```
  int32_t ret;
  uint16_t val;
  /* Set the direction of GPIO pin 3 to output. */
  ret = GpioSetDir(3, GPIO_DIR_OUT);
  if (ret != 0) {
      HDF_LOGE("GpioSerDir: failed, ret %d\n", ret);
      return;
  }
  /* Write the low level GPIO_VAL_LOW for GPIO pin 3. */
  ret = GpioWrite(3, GPIO_VAL_LOW);
  if (ret != 0) {
      HDF_LOGE("GpioWrite: failed, ret %d\n", ret);
      return;
  }
  /* Set the direction of GPIO pin 6 to input. */
  ret = GpioSetDir(6, GPIO_DIR_IN);
  if (ret != 0) {
      HDF_LOGE("GpioSetDir: failed, ret %d\n", ret);
      return;
  }
  /* Read the level of GPIO pin 6. */
  ret = GpioRead(6, &val);
  ```

- Set the ISR function for a GPIO pin.

  Call **GpioSetIrq()** to set the ISR function for a GPIO pin.

  ```c
  int32_t GpioSetIrq(uint16_t gpio, uint16_t mode, GpioIrqFunc func, void *arg);
  ``` 
 
    **Table 5** Description of GpioSetIrq
  
  | **Parameter**| **Description**| 
  | -------- | -------- |
  | gpio | GPIO pin number.| 
  | mode | Interrupt trigger mode.| 
  | func | ISR function to set.| 
  | arg | Pointer to the parameters passed to the ISR function.| 
  | **Return Value**| **Description**| 
  | 0 | The operation is successful.| 
  | Negative value| The operation failed.| 

  > ![icon-caution.gif](../public_sys-resources/icon-caution.gif) **CAUTION**<br/>
  > Only one ISR function can be set for a GPIO pin. If **GpioSetIrq** is called repeatedly, the previous IRS function will be replaced.

  If the ISR function is no longer required, call **GpioUnsetIrq()** to cancel it.

  ```c
  int32_t GpioUnsetIrq(uint16_t gpio, void *arg);
  ``` 

    **Table 6** Description of GpioUnsetIrq
  
  | **Parameter**| **Description**| 
  | -------- | -------- |
  | gpio | GPIO pin number.| 
  | arg  | Pointer to the GPIO interrupt parameters.| 
  | **Return Value**| **Description**| 
  | 0 | The operation is successful.| 
  | Negative value| The operation failed.| 

  After the ISR function is set, call **GpioEnableIrq()** to enable interrupts for the GPIO pin.

  ```c
  int32_t GpioEnableIrq(uint16_t gpio);
  ``` 

    **Table 7** Description of GpioEnableIrq
  
  | **Parameter**| **Description**| 
  | -------- | -------- |
  | gpio | GPIO pin number.| 
  | **Return Value**| **Description**| 
  | 0 | The operation is successful.| 
  | Negative value| The operation failed.| 

  > ![icon-caution.gif](../public_sys-resources/icon-caution.gif) **CAUTION**<br/>
  > The configured ISR function can be responded only after interrupts are enabled for the GPIO pin.

  You can call **GpioDisableIrq** to disable interrupts for the pin.

  ```c
  int32_t GpioDisableIrq(uint16_t gpio);
  ``` 

    **Table 8** Description of GpioDisableIrq
  
  | **Parameter**| **Description**| 
  | -------- | -------- |
  | gpio | GPIO pin number.| 
  | **Return Value**| **Description**| 
  | 0 | The operation is successful.| 
  | Negative value| The operation failed.| 

  Sample code:

  
  ```
  /* Set the ISR function. */
  int32_t MyCallBackFunc(uint16_t gpio, void *data)
  {
      HDF_LOGI("%s: gpio:%u interrupt service in! data=%p\n", __func__, gpio, data);
      return 0;
  }
  
  int32_t ret;
  /* Set the ISR function to MyCallBackFunc, with input parameter of NULL and the interrupt trigger mode of rising edge. */
  ret = GpioSetIrq(3, OSAL_IRQF_TRIGGER_RISING, MyCallBackFunc, NULL);
  if (ret != 0) {
      HDF_LOGE("GpioSetIrq: failed, ret %d\n", ret);
      return;
  }
  
  /* Enable interrupts for GPIO pin 3. */
  ret = GpioEnableIrq(3);
  if (ret != 0) {
      HDF_LOGE("GpioEnableIrq: failed, ret %d\n", ret);
      return;
  }
  
  /* Disable interrupts for GPIO pin 3. */
  ret = GpioDisableIrq(3);
  if (ret != 0) {
      HDF_LOGE("GpioDisableIrq: failed, ret %d\n", ret);
      return;
  }
  
  /* Cancel the ISR function setting for GPIO pin 3. */
  ret = GpioUnsetIrq(3, NULL);
  if (ret != 0) {
      HDF_LOGE("GpioUnSetIrq: failed, ret %d\n", ret);
      return;
  }
  ```


## Development Example

The procedure is as follows:

1. Select an idle GPIO pin, for example, pin GPIO10\_3 on a Hi3516D V300 development board. 

   The pin number is 83. 

   GPIO pin number of GPIO10_3 = 10 x 8 + 3 = 83

   You can select an idle GPIO pin as required.

2. Set the ISR function for the pin, with the trigger mode of rising edge and failing edge.
  
3. Write high and low levels to the pin alternately, and observe the execution of the ISR function.
```
#include "gpio_if.h"
#include "hdf_log.h"
#include "osal_irq.h"
#include "osal_time.h"

static uint32_t g_irqCnt;

/* ISR function */
static int32_t TestCaseGpioIrqHandler(uint16_t gpio, void *data)
{
    HDF_LOGE("%s: irq triggered! on gpio:%u, data=%p", __func__, gpio, data);
    g_irqCnt++; /* If the ISR function is triggered, the global interrupt counter is incremented by 1. */
    return GpioDisableIrq(gpio);
}

/* Test case function */
static int32_t TestCaseGpioIrqEdge(void)
{
    int32_t ret;
    uint16_t valRead;
    uint16_t mode;
    uint16_t gpio = 83; /* Number of the GPIO pin to test */
    uint32_t timeout;

    /* Set the pin direction to output. */
    ret = GpioSetDir(gpio, GPIO_DIR_OUT);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set dir fail! ret:%d\n", __func__, ret);
        return ret;
    }

    /* Disable interrupts of the pin. */
    ret = GpioDisableIrq(gpio);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: disable irq fail! ret:%d\n", __func__, ret);
        return ret;
    }

    /* Set the ISR function for the pin. The trigger mode is both rising edge and falling edge. */
    mode = OSAL_IRQF_TRIGGER_RISING | OSAL_IRQF_TRIGGER_FALLING;
    HDF_LOGE("%s: mode:%0x\n", __func__, mode);
    ret = GpioSetIrq(gpio, mode, TestCaseGpioIrqHandler, NULL);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set irq fail! ret:%d\n", __func__, ret);
        return ret;
    }

    /* Enable interrupts for the pin. */
    ret = GpioEnableIrq(gpio);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: enable irq fail! ret:%d\n", __func__, ret);
        (void)GpioUnsetIrq(gpio, NULL);
        return ret;
    }

    g_irqCnt = 0; /* Reset the global interrupt counter. */
    timeout = 0;  /* Clear the waiting time. */
    /* Wait for the ISR function to trigger for this pin. The timeout duration is 1000 ms. */
    while (g_irqCnt <= 0 && timeout < 1000) {
        (void)GpioRead(gpio, &valRead);
        (void)GpioWrite(gpio, (valRead == GPIO_VAL_LOW) ? GPIO_VAL_HIGH : GPIO_VAL_LOW);
        HDF_LOGE("%s: wait irq timeout:%u\n", __func__, timeout);
        OsalMDelay(200); /* wait for irq trigger */
        timeout += 200;
    }
    (void)GpioUnsetIrq(gpio, NULL);
    return (g_irqCnt > 0) ? HDF_SUCCESS : HDF_FAILURE;
}
```
