# usb_ddk_api.h

## Overview

Declares the USB DDK APIs used by the USB host to access USB devices.

**File to include**: <usb/usb_ddk_api.h>

**Library**: libusb_ndk.z.so

**System capability**: SystemCapability.Driver.USB.Extension

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_Usb_Init(void)](#oh_usb_init) | Initializes the DDK.|
| [void OH_Usb_Release(void)](#oh_usb_release) | Releases the USB DDK.|
| [int32_t OH_Usb_ReleaseResource(void)](#oh_usb_releaseresource) | Releases the USB DDK.|
| [int32_t OH_Usb_GetDeviceDescriptor(uint64_t deviceId, struct UsbDeviceDescriptor *desc)](#oh_usb_getdevicedescriptor) | Obtains the device descriptor.|
| [int32_t OH_Usb_GetConfigDescriptor(uint64_t deviceId, uint8_t configIndex, struct UsbDdkConfigDescriptor ** const config)](#oh_usb_getconfigdescriptor) | Obtains the configuration descriptor. To avoid memory leakage, use [OH_Usb_FreeConfigDescriptor](capi-usb-ddk-api-h.md#oh_usb_freeconfigdescriptor) to release a descriptor after use.|
| [void OH_Usb_FreeConfigDescriptor(const struct UsbDdkConfigDescriptor * const config)](#oh_usb_freeconfigdescriptor) | Releases the configuration descriptor. To avoid memory leakage, release a descriptor after use.|
| [int32_t OH_Usb_ClaimInterface(uint64_t deviceId, uint8_t interfaceIndex, uint64_t *interfaceHandle)](#oh_usb_claiminterface) | Declares a USB interface.|
| [int32_t OH_Usb_ReleaseInterface(uint64_t interfaceHandle)](#oh_usb_releaseinterface) | Releases a USB interface.|
| [int32_t OH_Usb_SelectInterfaceSetting(uint64_t interfaceHandle, uint8_t settingIndex)](#oh_usb_selectinterfacesetting) | Activates the alternate setting of a USB interface.|
| [int32_t OH_Usb_GetCurrentInterfaceSetting(uint64_t interfaceHandle, uint8_t *settingIndex)](#oh_usb_getcurrentinterfacesetting) | Obtains the activated alternate setting of a USB interface.|
| [int32_t OH_Usb_SendControlReadRequest(uint64_t interfaceHandle, const struct UsbControlRequestSetup *setup,uint32_t timeout, uint8_t *data, uint32_t *dataLen)](#oh_usb_sendcontrolreadrequest) | Sends a control read transfer request. This API works in a synchronous manner.|
| [int32_t OH_Usb_SendControlWriteRequest(uint64_t interfaceHandle, const struct UsbControlRequestSetup *setup,uint32_t timeout, const uint8_t *data, uint32_t dataLen)](#oh_usb_sendcontrolwriterequest) | Sends a control write transfer request. This API works in a synchronous manner.|
| [int32_t OH_Usb_SendPipeRequest(const struct UsbRequestPipe *pipe, UsbDeviceMemMap *devMmap)](#oh_usb_sendpiperequest) | Sends a pipe request. This API works in a synchronous manner. It applies to interrupt transfer and bulk transfer.|
| [int32_t OH_Usb_SendPipeRequestWithAshmem(const struct UsbRequestPipe *pipe, DDK_Ashmem *ashmem)](#oh_usb_sendpiperequestwithashmem) | Sends a pipe request. This API works in a synchronous manner. It applies to interrupt transfer and bulk transfer.|
| [int32_t OH_Usb_CreateDeviceMemMap(uint64_t deviceId, size_t size, UsbDeviceMemMap **devMmap)](#oh_usb_createdevicememmap) | Creates a buffer. To avoid resource leakage, use [OH_Usb_DestroyDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_destroydevicememmap) to destroy a buffer after use.|
| [void OH_Usb_DestroyDeviceMemMap(UsbDeviceMemMap *devMmap)](#oh_usb_destroydevicememmap) | Destroys a buffer. To avoid resource leakage, destroy a buffer in time after use.|
| [int32_t OH_Usb_GetDevices(struct Usb_DeviceArray *devices)](#oh_usb_getdevices) | Obtains the USB device ID list. Ensure that the input pointer is valid and the number of devices does not exceed 128. To prevent resource leakage, release the member memory after usage. Besides, make sure that the obtained USB device ID has been filtered by **vid** in the driver configuration information.|

## Function Description

### OH_Usb_Init()

```
int32_t OH_Usb_Init(void)
```

**Description**

Initializes the DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode): The memory allocation fails.|

### OH_Usb_Release()

```
void OH_Usb_Release(void)
```

**Description**

Releases the USB DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10

### OH_Usb_ReleaseResource()

```
int32_t OH_Usb_ReleaseResource(void)
```

**Description**

Releases the USB DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 18

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.|

### OH_Usb_GetDeviceDescriptor()

```
int32_t OH_Usb_GetDeviceDescriptor(uint64_t deviceId, struct UsbDeviceDescriptor *desc)
```

**Description**

Obtains the device descriptor.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t deviceId | Device ID.|
| [struct UsbDeviceDescriptor](capi-usbddk-usbdevicedescriptor.md) *desc | Device descriptor. For details, see [UsbDeviceDescriptor](capi-usbddk-usbdevicedescriptor.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **desc** is a null pointer.|

### OH_Usb_GetConfigDescriptor()

```
int32_t OH_Usb_GetConfigDescriptor(uint64_t deviceId, uint8_t configIndex, struct UsbDdkConfigDescriptor ** const config)
```

**Description**

Obtains the configuration descriptor. To avoid memory leakage, use [OH_Usb_FreeConfigDescriptor](capi-usb-ddk-api-h.md#oh_usb_freeconfigdescriptor) to release a descriptor after use.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name                                              | Description|
|---------------------------------------------------| -- |
| uint64_t deviceId                                 | Device ID.|
| uint8_t configIndex                               | Configuration index, which corresponds to {@link bConfigurationValue} in the USB protocol.|
| struct [UsbDdkConfigDescriptor](capi-usbddk-usbddkconfigdescriptor.md) ** const config | Configuration descriptor, which includes the standard configuration descriptor defined in the USB protocol and the associated interface descriptor and endpoint descriptor.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **config** is a null pointer.<br>         {@link USB_DDK_IO_FAILED}: An I/O exception occurs.<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode): The memory allocation fails.|

### OH_Usb_FreeConfigDescriptor()

```
void OH_Usb_FreeConfigDescriptor(const struct UsbDdkConfigDescriptor * const config)
```

**Description**

Releases the configuration descriptor. To avoid memory leakage, release a descriptor after use.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const struct [UsbDdkConfigDescriptor](capi-usbddk-usbddkconfigdescriptor.md) * const config | Configuration descriptor, which is obtained by calling [OH_Usb_GetConfigDescriptor](capi-usb-ddk-api-h.md#oh_usb_getconfigdescriptor).|

### OH_Usb_ClaimInterface()

```
int32_t OH_Usb_ClaimInterface(uint64_t deviceId, uint8_t interfaceIndex, uint64_t *interfaceHandle)
```

**Description**

Declares a USB interface.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t deviceId | Device ID.|
| uint8_t interfaceIndex | Interface index, which corresponds to [bInterfaceNumber](capi-usbddk-usbinterfacedescriptor.md) in the USB protocol.|
| uint64_t *interfaceHandle | Interface operation handle. After the interface is claimed successfully, a value will be assigned to this parameter.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **interfaceHandle** is a null pointer.<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode): The memory to be allocated exceeds the limit.|

### OH_Usb_ReleaseInterface()

```
int32_t OH_Usb_ReleaseInterface(uint64_t interfaceHandle)
```

**Description**

Releases a USB interface.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t interfaceHandle | Interface operation handle.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): One or more parameters are invalid.|

### OH_Usb_SelectInterfaceSetting()

```
int32_t OH_Usb_SelectInterfaceSetting(uint64_t interfaceHandle, uint8_t settingIndex)
```

**Description**

Activates the alternate setting of a USB interface.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t interfaceHandle | Interface operation handle.|
| uint8_t settingIndex | Index of the alternate setting, which corresponds to {@link bAlternateSetting} in the USB protocol.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) Incorrect parameter.|

### OH_Usb_GetCurrentInterfaceSetting()

```
int32_t OH_Usb_GetCurrentInterfaceSetting(uint64_t interfaceHandle, uint8_t *settingIndex)
```

**Description**

Obtains the activated alternate setting of a USB interface.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t interfaceHandle | Interface operation handle.|
| uint8_t *settingIndex | Index of the alternate setting, which corresponds to {@link bAlternateSetting} in the USB protocol.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **settingIndex** is a null pointer.|

### OH_Usb_SendControlReadRequest()

```
int32_t OH_Usb_SendControlReadRequest(uint64_t interfaceHandle, const struct UsbControlRequestSetup *setup,uint32_t timeout, uint8_t *data, uint32_t *dataLen)
```

**Description**

Sends a control read transfer request. This API works in a synchronous manner.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t interfaceHandle | Interface operation handle.|
| [const struct UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md) *setup | Request parameters. For details, see [UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md).|
| uint32_t timeout | Timeout duration, in ms.|
| uint8_t *data | Data to transfer.|
| uint32_t *dataLen | Data length. The return value indicates the length of the actually read data.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         [USB_DDK_FAILED](capi-usb-ddk-types-h.md#usbddkerrcode): The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **setup**, **data**, or **dataLen** is a null pointer, or the value of **datalen** is less than the length of the read data.<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode): The attempt to copy the memory that stores the read data fails.<br>         USB_DDK_IO_FAILED: An I/O exception occurs.<br>         [USB_DDK_TIMEOUT](capi-usb-ddk-types-h.md#usbddkerrcode): The operation times out.|

### OH_Usb_SendControlWriteRequest()

```
int32_t OH_Usb_SendControlWriteRequest(uint64_t interfaceHandle, const struct UsbControlRequestSetup *setup,uint32_t timeout, const uint8_t *data, uint32_t dataLen)
```

**Description**

Sends a control write transfer request. This API works in a synchronous manner.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t interfaceHandle | Interface operation handle.|
| [const struct UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md) *setup | Request parameters. For details, see [UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md).|
| uint32_t timeout | Timeout duration, in ms.|
| const uint8_t *data | Data to transfer.|
| uint32_t dataLen | Data length.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         [USB_DDK_FAILED](capi-usb-ddk-types-h.md#usbddkerrcode): The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **setup** or **data** is a null pointer.<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode): The attempt to copy the memory that stores the read data fails.<br>         USB_DDK_IO_FAILED: An I/O exception occurs.<br>         [USB_DDK_TIMEOUT](capi-usb-ddk-types-h.md#usbddkerrcode): The operation times out.|

### OH_Usb_SendPipeRequest()

```
int32_t OH_Usb_SendPipeRequest(const struct UsbRequestPipe *pipe, UsbDeviceMemMap *devMmap)
```

**Description**

Sends a pipe request. This API works in a synchronous manner. It applies to interrupt transfer and bulk transfer.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [const struct UsbRequestPipe](capi-usbddk-usbrequestpipe.md) *pipe | Pipe used to transfer data.|
| [UsbDeviceMemMap](capi-usbddk-usbdevicememmap.md) *devMmap | Data buffer, which can be obtained by calling [OH_Usb_CreateDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_createdevicememmap).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **pipe** or **devMmap** is a null pointer, or the **devMmap** address is null.<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode): The attempt to copy the memory that stores the read data fails.<br>         USB_DDK_IO_FAILED: An I/O exception occurs.<br>         [USB_DDK_TIMEOUT](capi-usb-ddk-types-h.md#usbddkerrcode): The operation times out.|

### OH_Usb_SendPipeRequestWithAshmem()

```
int32_t OH_Usb_SendPipeRequestWithAshmem(const struct UsbRequestPipe *pipe, DDK_Ashmem *ashmem)
```

**Description**

Sends a pipe request. This API works in a synchronous manner. It applies to interrupt transfer and bulk transfer.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 12


**Parameters**

| Name                                                        | Description|
|-------------------------------------------------------------| -- |
| [const struct UsbRequestPipe](capi-usbddk-usbrequestpipe.md) *pipe | Pipe used to transfer data.|
| [DDK_Ashmem](capi-baseddk-ddk-ashmem.md) *ashmem            | Shared memory, which can be obtained by calling {@link OH_DDK_CreateAshmem}.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **pipe** or **ashmem** is a null pointer, or the **ashmem** address is null.<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode): The attempt to copy the memory that stores the read data fails.<br>         USB_DDK_IO_FAILED: An I/O exception occurs.<br>         [USB_DDK_TIMEOUT](capi-usb-ddk-types-h.md#usbddkerrcode): The operation times out.|

### OH_Usb_CreateDeviceMemMap()

```
int32_t OH_Usb_CreateDeviceMemMap(uint64_t deviceId, size_t size, UsbDeviceMemMap **devMmap)
```

**Description**

Creates a buffer. To avoid resource leakage, use [OH_Usb_DestroyDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_destroydevicememmap) to destroy a buffer after use.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t deviceId | Device ID.|
| size_t size | Buffer size.|
| [UsbDeviceMemMap](capi-usbddk-usbdevicememmap.md) **devMmap | Data memory map, through which the created buffer is returned to the caller.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **devMmap** is a null pointer.<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode): The memory mapping fails, or the memory allocation of **devMmap** fails.|

### OH_Usb_DestroyDeviceMemMap()

```
void OH_Usb_DestroyDeviceMemMap(UsbDeviceMemMap *devMmap)
```

**Description**

Destroys a buffer. To avoid resource leakage, destroy a buffer in time after use.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [UsbDeviceMemMap](capi-usbddk-usbdevicememmap.md) *devMmap | Destroys the buffer created by calling [OH_Usb_CreateDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_createdevicememmap).|

### OH_Usb_GetDevices()

```
int32_t OH_Usb_GetDevices(struct Usb_DeviceArray *devices)
```

**Description**

Obtains the USB device ID list. Ensure that the input pointer is valid and the number of devices does not exceed 128. To prevent resource leakage, release the member memory after usage. Besides, make sure that the obtained USB device ID has been filtered by **vid** in the driver configuration information.

**Required permissions**: ohos.permission.ACCESS_DDK_USB

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [struct Usb_DeviceArray](capi-usbddk-usb-devicearray.md) *devices | Device memory address, which is used to store the obtained device ID list and quantity.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode): The operation is successful.<br>         USB_DDK_NO_PERM: The permission check fails.<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode): The USB DDK service connection fails, or an internal error occurs.<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode): The input **devices** is a null pointer.|
