# CLOCK

## Overview

### Function

CLOCK，The clock serves as the cornerstone of all components in a system. Taking the CPU clock as an example, the CPU clock refers to the internal clock generator within the CPU. It operates in the form of frequency to synchronize and control the various operations within the CPU.

The CLOCK interface delineates a compendium of universal methodologies to accomplish -  - CLOCK operations, encompassing:

-  CLOCK device administration: enabling the initiation or cessation of CLOCK devices.

-  CLOCK rate modulation: extracting or configuring CLOCK speeds.

-  CLOCK gating: facilitating or disabling CLOCK functionality.

-  CLOCK parent-clock supervision: acquiring or configuring the parent clock.

### Basic Concepts

The clock signal of a device refers to a signal used to synchronize and control the operations of various modules or components within electronic devices. It serves as a fundamental signal source within the device, ensuring the proper functioning and accurate data transmission.

### Working Principles

In the Hardware Driver Foundation (HDF), the CLOCK module uses the unified service mode for API adaptation. In this mode, a service is used as the CLOCK manager to handle external access requests in a unified manner. The unified service mode applies when the system has multiple device objects of the same type. If the independent service mode is used in this case, more device nodes need to be configured and more memory resources will be consumed.

## Usage Guidelines

### When to Use

CLOCK provides chip-level clock management: The clock functionality can be utilized to regulate internal clock division, clock multiplication, clock source selection, and clock gating within the chip. By implementing a prudent clock management strategy, chip efficiency can be enhanced while ensuring proper coordination and synergy among all functional components.

### Available APIs

The following table describes the APIs of the CLOCK module. For more information, see **//drivers/hdf_core/framework/include/platform/clock_if.h**.

**Table 1** APIs of the CLOCK driver

| API | Description  | Return value description                          | Special case description                            |
| ---------------------------------------------------------- | ------------- | ----------------------------------- | --------------------------------------- |
| DevHandle ClockOpen(uint32_t number);                      | Opens an CLOCK device. | NULL：Fail，Other：Success |                                         |
| int32_t ClockClose(DevHandle handle);                      | Closes an CLOCK device. | Zero：Success，Other：Fail |                                         |
| int32_t ClockEnable(DevHandle handle);                     | Enable Clock.     | Zero：Success，Other：Fail |                                         |
| int32_t ClockDisable(DevHandle handle);                    | Disable Clock.   | Zero：Success，Other：Fail |                                         |
| int32_t ClockSetRate(DevHandle handle, uint32_t rate);     | Set Clock rate.  | Zero：Success，Other：Fail | If it fails, check whether the Clock corresponding to the passed rate is supported. |
| int32_t ClockGetRate(DevHandle handle, uint32_t *rate);    | Get Clock rate.   | Zero：Success，Other：Fail |                                         |
| int32_t ClockSetParent(DevHandle child, DevHandle parent); | Set Clock parent.    | Zero：Success，Other：Fail | When the parent clock is set repeatedly, it does not report an error and returns success directly. |
| DevHandle ClockGetParent(DevHandle handle);                | Get Clock parent.    | Zero：Success，Other：Fail |                                         |

### How to Develop

The following figure illustrates how to use CLOCK APIs.

**Figure 2** Process of using CLOCK APIs
![Process of using CLOCK APIs](figures/using-CLOCK-process.png) 

### Example

The intention at hand is to perform a simple reading operation on the CLOCK device of the RK3568 development board. Here are the fundamental hardware details:

-   SOC：RK3568

This program performs a test on various interfaces.

Example:

```c
#include "clock_if.h"          // Header file for CLOCK APIs
#include "hdf_log.h"           // Header file for log APIs
#define CLOCK_NUM 1

static int32_t TestCaseClock(void)
{
    int ret = 0;
    DevHandle handle = NULL;
    DevHandle parent = NULL;
    uint32_t rate = 0;

    handle = ClockOpen(CLOCK_NUM);
    if (handle == NULL) {
        HDF_LOGE("Failed to open CLOCK_NUM %d \n", CLOCK_NUM);
        return HDF_FAILURE;
    }

    ret = ClockEnable(handle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("Failed to ClockEnable ret = %d \n",ret);
        return ret;
    }
   

    ret = ClockGetRate(handle, &rate);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("Failed to ClockGetRate ret = %d \n",ret);
        return ret;
    }
    
    ret = ClockSetRate(handle, set_rate);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("Failed to ClockSetRate ret = %d \n",ret);
        return ret;
    }

    ret = ClockDisable(handle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("Failed to ClockDisable ret = %d \n",ret);
        return ret;
    }

    parent = ClockGetParent(handle);    
    if (parent != NULL) {
        ret = ClockSetParent(handle, parent);
        ClockClose(parent);
    } else {
        HDF_LOGE("Failed to ClockGetParent ret = %d \n",ret);
    }

    ret = ClockClose(handle);
    return ret;
}
```