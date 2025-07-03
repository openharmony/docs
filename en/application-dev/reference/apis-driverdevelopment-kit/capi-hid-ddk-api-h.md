# hid_ddk_api.h

## Overview

Declares the HID DDK functions for accessing an input device from the host.

**File to include**: <hid/hid_ddk_api.h>

**Library**: libhid.z.so

**System capability**: SystemCapability.Driver.HID.Extension

**Since**: 11

**Related module**: [HidDdk](capi-hidddk.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_Hid_CreateDevice(Hid_Device *hidDevice, Hid_EventProperties *hidEventProperties)](#oh_hid_createdevice) | Creates a device.|
| [int32_t OH_Hid_EmitEvent(int32_t deviceId, const Hid_EmitItem items[], uint16_t length)](#oh_hid_emitevent) | Sends an event list to a device.|
| [int32_t OH_Hid_DestroyDevice(int32_t deviceId)](#oh_hid_destroydevice) | Destroys a device.|
| [int32_t OH_Hid_Init(void)](#oh_hid_init) | Initializes an HID DDK.|
| [int32_t OH_Hid_Release(void)](#oh_hid_release) | Releases an HID DDK.|
| [int32_t OH_Hid_Open(uint64_t deviceId, uint8_t interfaceIndex, Hid_DeviceHandle **dev)](#oh_hid_open) | Opens the device specified by **deviceId** and **interfaceIndex**.|
| [int32_t OH_Hid_Close(Hid_DeviceHandle **dev)](#oh_hid_close) | Closes an HID device.|
| [int32_t OH_Hid_Write(Hid_DeviceHandle *dev, uint8_t *data, uint32_t length, uint32_t *bytesWritten)](#oh_hid_write) | Writes reports to an HID device.|
| [int32_t OH_Hid_ReadTimeout(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize, int timeout, uint32_t *bytesRead)](#oh_hid_readtimeout) | Reads reports from the HID device within the specified timeout interval.|
| [int32_t OH_Hid_Read(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize, uint32_t *bytesRead)](#oh_hid_read) | Reads reports from the HID device. The blocking mode (that is, blocking remains active until data can be read) is used by default. You can call [OH_Hid_SetNonBlocking](capi-hid-ddk-api-h.md#oh_hid_setnonblocking) to change the mode.|
| [int32_t OH_Hid_SetNonBlocking(Hid_DeviceHandle *dev, int nonBlock)](#oh_hid_setnonblocking) | Sets the device read mode to non-blocking mode.|
| [int32_t OH_Hid_GetRawInfo(Hid_DeviceHandle *dev, Hid_RawDevInfo *rawDevInfo)](#oh_hid_getrawinfo) | Obtains the original device information.|
| [int32_t OH_Hid_GetRawName(Hid_DeviceHandle *dev, char *data, uint32_t bufSize)](#oh_hid_getrawname) | Obtains the original device name.|
| [int32_t OH_Hid_GetPhysicalAddress(Hid_DeviceHandle *dev, char *data, uint32_t bufSize)](#oh_hid_getphysicaladdress) | Obtains the physical address of the HID device.|
| [int32_t OH_Hid_GetRawUniqueId(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize)](#oh_hid_getrawuniqueid) | Obtains the original unique identifier of a device.|
| [int32_t OH_Hid_SendReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, const uint8_t *data, uint32_t length)](#oh_hid_sendreport) | Sends reports to the HID device.|
| [int32_t OH_Hid_GetReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, uint8_t *data, uint32_t bufSize)](#oh_hid_getreport) | Obtains reports from the HID device.|
| [int32_t OH_Hid_GetReportDescriptor(Hid_DeviceHandle *dev, uint8_t *buf, uint32_t bufSize, uint32_t *bytesRead)](#oh_hid_getreportdescriptor) | Obtains the report descriptor of the HID device.|

## Function Description

### OH_Hid_CreateDevice()

```
int32_t OH_Hid_CreateDevice(Hid_Device *hidDevice, Hid_EventProperties *hidEventProperties)
```

**Description**

Creates a device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 11


**Parameters**

| Name                                                                          | Description|
|-------------------------------------------------------------------------------| -- |
| [Hid_Device](capi-hidddk-hid-device.md) *hidDevice                            | Pointer to the basic information about the device to create, including the device name, vendor ID, and product ID.|
| [Hid_EventProperties](capi-hidddk-hid-eventproperties.md) *hidEventProperties | Pointer to the event properties related to the device to create, including the event type, key event properties, absolute coordinate event properties, and relative coordinate event properties.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | deviceID (a non-negative number) if the API call is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): The hid_ddk service connection fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. The input **hidDevice** is a null pointer.<br>         2. The input **hidEventProperties** is a null pointer. 3. The length of **properties** exceeds 7 characters. 4. The length of **hidEventTypes** exceeds 5 characters.<br>         5. The length of **hidKeys** exceeds 100 characters. 6. The length of **hidAbs** exceeds 26 characters. 7. The length of **hidRelBits** exceeds 13 characters.<br>         8. The length of **hidMiscellaneous** exceeds 6 characters.<br>         [HID_DDK_FAILURE](capi-hid-ddk-types-h.md#hid_ddkerrcode): The number of devices reaches the maximum value 200.|

### OH_Hid_EmitEvent()

```
int32_t OH_Hid_EmitEvent(int32_t deviceId, const Hid_EmitItem items[], uint16_t length)
```

**Description**

Sends an event list to a device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| int32_t deviceId | Device ID.|
| items | List of the events to send. The event information includes the event type (**Hid_EventType**), code (**Hid_SynEvent**, **Hid_KeyCode**, **HidBtnCode**, **Hid_AbsAxes**, **Hid_RelAxes**, or **Hid_MscEvent**), and value (depending on the actual device input).|
| uint16_t length | Length of the event list (number of events to be sent at a time).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The API call is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): The hid_ddk service connection fails or the caller is not the device creator.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. The device ID is less than 0.<br>         2. The length of the input parameter length exceeds 7 characters. 3. The input parameter items is a null pointer.<br>         [HID_DDK_NULL_PTR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The input device is a null pointer.<br>         [HID_DDK_FAILURE](capi-hid-ddk-types-h.md#hid_ddkerrcode): The corresponding device does not exist.|

### OH_Hid_DestroyDevice()

```
int32_t OH_Hid_DestroyDevice(int32_t deviceId)
```

**Description**

Destroys a device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| int32_t deviceId | Device ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The API call is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): The hid_ddk service connection fails or the caller is not the device creator.<br>         [HID_DDK_FAILURE](capi-hid-ddk-types-h.md#hid_ddkerrcode): The corresponding device does not exist.|

### OH_Hid_Init()

```
int32_t OH_Hid_Init(void)
```

**Description**

Initializes an HID DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.|

### OH_Hid_Release()

```
int32_t OH_Hid_Release(void)
```

**Description**

Releases an HID DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.|

### OH_Hid_Open()

```
int32_t OH_Hid_Open(uint64_t deviceId, uint8_t interfaceIndex, Hid_DeviceHandle **dev)
```

**Description**

Opens the device specified by **deviceId** and **interfaceIndex**.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name                       | Description|
|----------------------------| -- |
| uint64_t deviceId          | Device ID.|
| uint8_t interfaceIndex     | Interface index for the API of the HID device.|
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) **dev | Device operation handle.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Memory allocation for the device fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The input **dev** is empty.<br>         [HID_DDK_DEVICE_NOT_FOUND](capi-hid-ddk-types-h.md#hid_ddkerrcode): No device is found based on **deviceId** and **interfaceIndex**.|

### OH_Hid_Close()

```
int32_t OH_Hid_Close(Hid_DeviceHandle **dev)
```

**Description**

Closes an HID device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) **dev | Device operation handle.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The dev parameter is empty.|

### OH_Hid_Write()

```
int32_t OH_Hid_Write(Hid_DeviceHandle *dev, uint8_t *data, uint32_t length, uint32_t *bytesWritten)
```

**Description**

Writes reports to an HID device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| uint8_t *data | Data to be written.|
| uint32_t length | Length of the data to be written, in bytes. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|
| uint32_t *bytesWritten | Number of written bytes.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **data** is empty. 3. The value of **length** is **0**; 4. The value of **length** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>             5. **bytesWritten** is empty.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.|

### OH_Hid_ReadTimeout()

```
int32_t OH_Hid_ReadTimeout(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize, int timeout, uint32_t *bytesRead)
```

**Description**

Reads reports from the HID device within the specified timeout interval.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| uint8_t *data | Buffer for storing the read data.|
| uint32_t bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|
| int timeout | Timeout interval, in ms. The value **-1** indicates block waiting.|
| uint32_t *bytesRead | Number of bytes to read.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>             5. **bytesRead** is empty.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The memory data copy fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_TIMEOUT](capi-hid-ddk-types-h.md#hid_ddkerrcode): The read operation times out.|

### OH_Hid_Read()

```
int32_t OH_Hid_Read(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize, uint32_t *bytesRead)
```

**Description**

Reads reports from the HID device. The blocking mode (that is, blocking remains active until data can be read) is used by default. You can call [OH_Hid_SetNonBlocking](capi-hid-ddk-api-h.md#oh_hid_setnonblocking) to change the mode.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| uint8_t *data | Buffer for storing the read data.|
| uint32_t bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|
| uint32_t *bytesRead | Number of bytes to read.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>             5. **bytesRead** is empty.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The memory data copy fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_TIMEOUT](capi-hid-ddk-types-h.md#hid_ddkerrcode): The read operation times out.|

### OH_Hid_SetNonBlocking()

```
int32_t OH_Hid_SetNonBlocking(Hid_DeviceHandle *dev, int nonBlock)
```

**Description**

Sets the device read mode to non-blocking mode.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| int nonBlock | Whether to enable the non-blocking mode for reading data. - **1**: The non-blocking mode is enabled. When [OH_Hid_Read](capi-hid-ddk-api-h.md#oh_hid_read) is called, if the device has readable data, [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) is returned;<br>                 if the device has no readable data, [HID_DDK_TIMEOUT](capi-hid-ddk-types-h.md#hid_ddkerrcode) is returned. - **0**: The non-blocking mode is disabled.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. The value of **nonBlock** is not **1** or **0**.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.|

### OH_Hid_GetRawInfo()

```
int32_t OH_Hid_GetRawInfo(Hid_DeviceHandle *dev, Hid_RawDevInfo *rawDevInfo)
```

**Description**

Obtains the original device information.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name                                                        | Description|
|-------------------------------------------------------------| -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev                                       | Device operation handle.|
| [Hid_RawDevInfo](capi-hidddk-hid-rawdevinfo.md) *rawDevInfo | Original device information, including the vendor ID, product ID, and bus type.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **rawDevInfo** is empty.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): This operation is not supported.|

### OH_Hid_GetRawName()

```
int32_t OH_Hid_GetRawName(Hid_DeviceHandle *dev, char *data, uint32_t bufSize)
```

**Description**

Obtains the original device name.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| char *data | Buffer for storing the read data.|
| uint32_t bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The memory data copy fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): This operation is not supported.|

### OH_Hid_GetPhysicalAddress()

```
int32_t OH_Hid_GetPhysicalAddress(Hid_DeviceHandle *dev, char *data, uint32_t bufSize)
```

**Description**

Obtains the physical address of the HID device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| char *data | Buffer for storing the read data.|
| uint32_t bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The memory data copy fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): This operation is not supported.|

### OH_Hid_GetRawUniqueId()

```
int32_t OH_Hid_GetRawUniqueId(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize)
```

**Description**

Obtains the original unique identifier of a device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| uint8_t *data | Buffer for storing the read data.|
| uint32_t bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The memory data copy fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): This operation is not supported.|

### OH_Hid_SendReport()

```
int32_t OH_Hid_SendReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, const uint8_t *data, uint32_t length)
```

**Description**

Sends reports to the HID device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description                                                                                               |
| -- |---------------------------------------------------------------------------------------------------|
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.                                                                                          |
| [Hid_ReportType](capi-hid-ddk-types-h.md#hid_reporttype) reportType | Report type.                                                                                            |
| const uint8_t *data | Data to be sent.                                                                                          |
| uint32_t length | Length of the data to be sent, in bytes. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **data** is empty. 3. The value of **length** is **0**; 4. The value of **length** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): This operation is not supported.|

### OH_Hid_GetReport()

```
int32_t OH_Hid_GetReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, uint8_t *data, uint32_t bufSize)
```

**Description**

Obtains reports from the HID device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| [Hid_ReportType](capi-hid-ddk-types-h.md#hid_reporttype) reportType | Report type.|
| uint8_t *data | Buffer for storing the read data.|
| uint32_t bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The memory data copy fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): This operation is not supported.|

### OH_Hid_GetReportDescriptor()

```
int32_t OH_Hid_GetReportDescriptor(Hid_DeviceHandle *dev, uint8_t *buf, uint32_t bufSize, uint32_t *bytesRead)
```

**Description**

Obtains the report descriptor of the HID device.

**Required permissions**: ohos.permission.ACCESS_DDK_HID

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | Device operation handle.|
| uint8_t *buf | Buffer for storing descriptors.|
| uint32_t bufSize | Buffer size, in bytes. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).|
| uint32_t *bytesRead | Number of bytes to read.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode): The operation is successful.<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode): The permission verification fails.<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode): The parameter check fails. Possible causes: 1. **dev** is empty.<br>             2. **buf** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size).<br>             5. **bytesRead** is empty.<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The DDK initialization fails.<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): Communication with the DDK server fails.<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The memory data copy fails.<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode): The I/O operation fails.<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode): This operation is not supported.|
