#  Pin


## Overview<a name="section1"></a>

### Pin<a name="section2"></a>

The pin module, also called pin controller, manages pin resources of system on a chip (SoC) vendors and provides the pin multiplexing function.
The module defines a set of common methods for managing pins, including:
    -   Obtaining or releasing the pin description handle: The kernel compares the pin name passed in with the pin names of each controller in the linked list. If a match is found, a pin description handle is obtained. After the operation on the pin is complete, the pin description handle will be released.
-   Setting or obtaining the pull type of a pin: The pull type can be pull-up, pull-down, or floating.
-   Setting or obtaining the pull strength of a pin: You can set the pull strength as required.
-   Setting or obtaining the functions of a pin to implement pin multiplexing

### Basic Concepts<a name="section3"></a>
Pin, as a software concept, provides APIs for uniformly managing the pins from different SoC vendors, providing the pin multiplexing function, and configuring the electrical features of pins.

- SoC

  An SOC is a chip that integrates microprocessors, analog IP cores, digital IP cores, and memory for specific purposes.

- Pin multiplexing

  When the number of pins of a chip cannot handle the increasing connection requests, you can set the software registers to make the pins to work in different states.

### Working Principles<a name="section4"></a>

In the HDF, the pin module does not support the user mode and therefore does not need to publish services. It uses the service-free mode in interface adaptation. The service-free mode applies to the devices that do not provide user-mode APIs or the OS that does not distinguish the user mode and the kernel mode. The **DevHandle**, a void pointer, directly points to the kernel mode address of the device object.

The pin module is divided into the following layers:
-   Interface layer: provides APIs for obtaining a pin, setting or obtaining the pull type, pull strength, and functions of a pin, and releasing a pin.
-   Core layer: provides the capabilities of matching pin resources and adding, removing, and managing pin controllers. The core layer interacts with the adaptation layer by using hooks.
-   Adaptation layer: instantiates hooks to implement specific functions.

**Figure 1** Service-free mode<a name="fig14423182615525"></a> 
![](figures/service-free-mode.png "pin service-free mode")

### Constraints<a name="section5"></a>

 Currently, the pin module supports only the kernels (LiteOS) of mini and small systems.

 ## Usage Guidelines<a name="section6"></a>

 ### When to Use<a name="7"></a>

  The pin module is a software concept and is used to manage pin resources. You can set the functions, pull type, and pull strength of pins to implement pin multiplexing.

### Available APIs<a name="section8"></a>

The table below describes the APIs of the pin module. For more details, see API Reference.

**Table 1** Pin driver APIs
<a name="table1"></a>

| **API**                                                 | **Description**       |
| ------------------------------------------------------------ | ---------------- |
| DevHandle PinGet(const char *pinName);                       | Obtains the pin description handle.|
| void PinPut(DevHandle handle);                               | Releases the pin description handle.|
| int32_t PinSetPull(DevHandle handle, enum PinPullType pullType); | Sets the pull type of a pin.|
| int32_t PinGetPull(DevHandle handle, enum PinPullType *pullType); | Obtains the pull type of a pin.|
| int32_t PinSetStrength(DevHandle handle, uint32_t strength); | Sets the pull strength of a pin.|
| int32_t PinGetStrength(DevHandle handle, uint32_t *strength); | Obtains the pull strength of a pin.|
| int32_t PinSetFunc(DevHandle handle, const char *funcName);  | Sets the pin function.    |
| int32_t PinGetFunc(DevHandle handle, const char **funcName); | Obtains the pin functions.    |

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/>
>All APIs described in this document can be called only in the kernel space.

### How to Develop<a name="section9"></a>

The figure below illustrates how to use the APIs.

 **Figure 2** Using the pin driver APIs 
 
![](figures/using-pin-process.png "Process of using the pin module")

#### Obtaining the Pin Description Handle

Before performing an operation on a pin, call **PinGet** to obtain the pin description handle. This API returns the pin description handle that matches the input pin name.

```
DevHandle PinGet(const char *pinName);
```

**Table 2** Description of PinGet

<a name="table2"></a>

| Parameter      | Description               |
| ---------- | ----------------------- |
| pinName    | Pointer to the pin name.                 |
| **Return Value**| **Description**        |
| NULL       | Failed to obtain the pin description handle.|
| handle     | Pin description handle obtained.        |

Example: Obtain the handle of P18.

```
DevHandle handle = NULL;               /* Pin description handle */
char pinName = "P18";                 /* Pin name. */
handle = PinGet(pinName);
if (handle == NULL) {
    HDF_LOGE("PinGet: get handle failed!\n");
    return;
}
```

#### Setting the Pull Type of a Pin

Call **PinSetPull** to set the pull type of a pin. 

```
int32_t PinSetPull(DevHandle handle, enum PinPullType pullType);
```

**Table 3** Description of PinSetPull

<a name="table3"></a>

| Parameter      | Description               |
| ---------- | ----------------------- |
| handle     | Pin description handle.        |
| pullType   | Pull type to set.        |
| **Return Value**| **Description**        |
| 0          | The operation is successful.|
| Negative value      | The operation failed.|

Example: Set the pull type to pull-up.

```
int32_t ret;
enum PinPullType pullTypeNum;
/* Set the pull type of a pin. */
pullTypeNum = 1;
ret = PinSetPull(handle, pullTypeNum);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PinSetPull: failed, ret %d\n", ret);
    return ret;
}
```

#### Obtaining the Pull Type of a Pin

Call **PinGetPull** to obtain the pull type of a pin.

```
int32_t PinGetPull(DevHandle handle, enum PinPullType *pullType);
```

**Table 4** Description of PinGetPull

<a name="table4"></a>

| Parameter      | Description                 |
| ---------- | ------------------------- |
| handle     | Pin description handle.          |
| pullType   | Pointer to the pull type obtained.|
| **Return Value**| **Description**          |
| 0          | The operation is successful.  |
| Negative value      | The operation failed.  |

Example: Obtain the pull type of a pin.

```
int32_t ret;
enum PinPullType pullTypeNum;
/* Obtain the pull type of a pin.  */
ret = PinGetPull(handle, &pullTypeNum);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PinGetPull: failed, ret %d\n", ret);
    return ret;
}
```

#### Setting the Pull Strength of a Pin

Call **PinSetStrength** to set the pull type of a pin.

```
int32_t PinSetStrength(DevHandle handle, uint32_t strength);
```

**Table 5** Description of PinSetStrength

<a name="table5"></a>

| Parameter      | Description               |
| ---------- | ----------------------- |
| handle     | Pin description handle.           |
| strength   | Pull strength to set.        |
| **Return Value**| **Description**        |
| 0          | The operation is successful.|
| Negative value      | The operation failed.|

Example: Set the pull strength of the pin to 2. 

```
int32_t ret;
uint32_t strengthNum;
/* Set the pull strength of the pin. */
strengthNum = 2;
ret = PinSetStrength(handle, strengthNum);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PinSetStrength: failed, ret %d\n", ret);
    return ret;
}
```

#### Obtaining the Pull Strength of a Pin

Call **PinGetStrength** to obtain the pull strength set.

```
int32_t PinGetStrength(DevHandle handle, uint32_t *strength);
```

**Table 6** Description of PinGetStrength

<a name="table6"></a>

| Parameter      | Description                 |
| ---------- | ------------------------- |
| handle     | Pin description handle.             |
| strength   | Pointer to the pull strength obtained.|
| **Return Value**| **Description**          |
| 0          | The operation is successful.  |
| Negative value      | The operation failed.  |

Example: Obtain the pull strength of a pin.

```
int32_t ret;
uint32_t strengthNum;
/* Obtain the pull strength of the pin. */
ret = PinGetStrength(handle, &strengthNum);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PinGetStrength: failed, ret %d\n", ret);
    return ret;
}
```

#### Setting the Pin Function

The pin function refers to the pin multiplexing function. The function of each pin is different. For details about the pin functions, see [pin_config.hcs](https://gitee.com/openharmony/device_soc_hisilicon/blob/master/hi3516dv300/sdk_liteos/hdf_config/pin/pin_config.hcs).

Call **PinSetFunc** to set the pin function.

```
int32_t PinSetFunc(DevHandle handle, const char *funcName);
```

**Table 7** Description of PinSetFunc

<a name="table7"></a>

| Parameter      | Description           |
| ---------- | ------------------- |
| handle     | Pin description handle.       |
| funcName   | Pointer to the pin function to set.      |
| **Return Value**| **Description**    |
| 0          | The operation is successful.|
| Negative value      | The operation failed.|

Example: Set the pin function to LSADC_CH1 (ADC channel 1).

```
int32_t ret;
char funcName = "LSADC_CH1";
/* Sets the pin function. */
ret = PinSetFunc(handle, funcName);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PinSetFunc: failed, ret %d\n", ret);
    return ret;
}
```

#### Obtaining the Pin Function

Call **PinGetFunc** to obtain the pin function set.

```
int32_t PinGetFunc(DevHandle handle, const char **funcName);
```

**Table 8** Description of PinGetFunc

<a name="table8"></a>

| Parameter      | Description             |
| ---------- | --------------------- |
| handle     | Pin description handle.         |
| funcName   | Pointer to the function name obtained.|
| **Return Value**| **Description**      |
| 0          | The operation is successful.  |
| Negative value      | The operation failed.  |

Example: Obtain the pin function. 

```
int32_t ret;
char *funcName;
/* Obtain the pin function. */
ret = PinGetFunc(handle,&funcName);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PinGetFunc: failed, ret %d\n", ret);
    return ret;
}
```

####  Releasing a Pin Description Handle

After the operations on a pin are complete, call **PinPut** to release the pin description handle.

```
void PinPut(DevHandle handle);
```

**Table 9** Description of PinPut

<a name="table9"></a>

| Parameter      | Description      |
| ---------- | -------------- |
| handle     | Pin description handle.  |
| **Return Value**| **Description**|
| NA         | No value is returned.      |

Example: Release a pin description handle.

``` 
PinPut(handle);
```

## Development Example<a name="section10"></a>

The procedure is as follows:
1. Pass in the pin name to obtain the pin description handle.
2. Set the pull type of the pin. If the operation fails, release the pin description handle.
3. Obtain the pull type of the pin. If the operation fails, release the pin description handle.
4. Set the pull strength of the pin. If the operation fails, release the pin description handle.
5. Obtain the pin pull strength. If the operation fails, release the pin description handle.
5. Set the pin function. If the operation fails, release the pin description handle.
6. Obtain the pin function. If the operation fails, release the pin description handle.
7. Release the pin description handle if no operation needs to be performed on the pin.

```
#include "hdf_log.h"         /* Header file for log APIs */
#include "pin_if.h"   /* Header file for standard pin APIs */

int32_t PinTestSample(void)
{
    int32_t ret;
    uint32_t strengthNum;
    enum PinPullType pullTypeNum;
    char pinName;
    char *funName;
    DevHandle handle = NULL;

    /* Pin name. Set it to the actual pin name. */
    pinName = "P18"; 
    /* Obtain the pin description handle. */
    handle = PinGet(pinName);
    if (handle == NULL) {
        HDF_LOGE("PinGet: failed!\n");
        return;
    }
    /* Set the pull type to pull-up for the pin. */
    pullTypeNum = 1;
    ret = PinSetPull(handle, pullTypeNum);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PinSetPull: failed, ret %d\n", ret);
        goto ERR;
    }
    /* Obtain the pull type of the pin. */
    ret = PinGetPull(handle, &pullTypeNum);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PinGetPull: failed, ret %d\n", ret);
        goto ERR;
    }
    /* Set the pull strength of the pin to 2. */
    strengthNum = 2;
    ret = PinSetStrength(handle, strengthNum);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PinSetStrength: failed, ret %d\n", ret);
        goto ERR;
    }
    /* Obtain the pull strength of the pin. */
    ret = PinGetStrength(handle, &strengthNum);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PinGetStrength: failed, ret %d\n", ret);
        goto ERR;
    }
    /* Set the pin function to LSADC_CH1. */
    funName = "LSADC_CH1";
    ret = PinSetFunc(handle, funName);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PinSetFunc: failed, ret %d\n", ret);
        goto ERR;
    }
    /* Obtain the pin function. */
    ret = PinGetFunc(handle, &funcName);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PinGetFunc: failed, ret %d\n", ret);
        goto ERR;
    }
ERR:
    /* Release the pin description handle. */
    PinPut(handle); 
    return ret;
}