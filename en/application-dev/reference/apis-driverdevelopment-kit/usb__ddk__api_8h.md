# usb_ddk_api.h


## Overview

Declares the USB DDK APIs used by the USB host to access USB devices.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Usb_Init](_usb_ddk.md#oh_usb_init)&nbsp;(void) | Initializes the DDK.|
| [OH_Usb_Release](_usb_ddk.md#oh_usb_release)&nbsp;(void) | Releases the USB DDK.|
| [OH_Usb_ReleaseResource](_usb_ddk.md#oh_usb_releaseresource14)&nbsp;(void) | Releases the USB DDK.|
| [OH_Usb_GetDeviceDescriptor](_usb_ddk.md#oh_usb_getdevicedescriptor)&nbsp;(uint64_t&nbsp;deviceId,&nbsp;struct&nbsp;[UsbDeviceDescriptor](_usb_device_descriptor.md)&nbsp;\*desc) | Obtains the device descriptor.|
| [OH_Usb_GetConfigDescriptor](_usb_ddk.md#oh_usb_getconfigdescriptor)&nbsp;(uint64_t&nbsp;deviceId,&nbsp;uint8_t&nbsp;configIndex,&nbsp;struct&nbsp;[UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md)&nbsp;\*\*const&nbsp;config) | Obtains the configuration descriptor. To avoid memory leakage, use [OH_Usb_FreeConfigDescriptor()](_usb_ddk.md#oh_usb_freeconfigdescriptor) to release a descriptor after use.|
| [OH_Usb_FreeConfigDescriptor](_usb_ddk.md#oh_usb_freeconfigdescriptor)&nbsp;(const&nbsp;struct&nbsp;[UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md)&nbsp;\*const&nbsp;config) | Releases the configuration descriptor. To avoid memory leakage, release a descriptor after use.|
| [OH_Usb_ClaimInterface](_usb_ddk.md#oh_usb_claiminterface)&nbsp;(uint64_t&nbsp;deviceId,&nbsp;uint8_t&nbsp;interfaceIndex,&nbsp;uint64_t&nbsp;\*[interfaceHandle](usb__ddk__types_8h.md#interfacehandle)) | Declares a USB interface.|
| [OH_Usb_ReleaseInterface](_usb_ddk.md#oh_usb_releaseinterface)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle)) | Releases a USB interface.|
| [OH_Usb_SelectInterfaceSetting](_usb_ddk.md#oh_usb_selectinterfacesetting)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle),&nbsp;uint8_t&nbsp;settingIndex) | Activates the alternate setting of a USB interface.|
| [OH_Usb_GetCurrentInterfaceSetting](_usb_ddk.md#oh_usb_getcurrentinterfacesetting)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle),&nbsp;uint8_t&nbsp;\*settingIndex) | Obtains the activated alternate setting of a USB interface.|
| [OH_Usb_SendControlReadRequest](_usb_ddk.md#oh_usb_sendcontrolreadrequest)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle),&nbsp;const&nbsp;struct&nbsp;[UsbControlRequestSetup](_usb_control_request_setup.md)&nbsp;\*setup,&nbsp;uint32_t&nbsp;[timeout](usb__ddk__types_8h.md#timeout),&nbsp;uint8_t&nbsp;\*data,&nbsp;uint32_t&nbsp;\*dataLen) | Sends a control read transfer request. This API works in a synchronous manner.|
| [OH_Usb_SendControlWriteRequest](_usb_ddk.md#oh_usb_sendcontrolwriterequest)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle),&nbsp;const&nbsp;struct&nbsp;[UsbControlRequestSetup](_usb_control_request_setup.md)&nbsp;\*setup,&nbsp;uint32_t&nbsp;[timeout](usb__ddk__types_8h.md#timeout),&nbsp;const&nbsp;uint8_t&nbsp;\*data,&nbsp;uint32_t&nbsp;dataLen) | Sends a control write transfer request. This API works in a synchronous manner.|
| [OH_Usb_SendPipeRequest](_usb_ddk.md#oh_usb_sendpiperequest)&nbsp;(const&nbsp;struct&nbsp;[UsbRequestPipe](_usb_request_pipe.md)&nbsp;\*pipe,&nbsp;[UsbDeviceMemMap](_usb_device_mem_map.md)&nbsp;\*devMmap) | Sends a pipe request. This API works in a synchronous manner. It applies to interrupt transfer and bulk transfer.|
| [OH_Usb_SendPipeRequestWithAshmem](_usb_ddk.md#oh_usb_sendpiperequestwithashmem12)&nbsp;(const&nbsp;struct&nbsp;[UsbRequestPipe](_usb_request_pipe.md)&nbsp;\*pipe,&nbsp;[DDK_Ashmem](_ddk_ashmem.md)&nbsp;\*ashmem) | Sends a pipe request for the shared memory. This API returns the result synchronously. It applies to interrupt transfer and bulk transfer.|
| [OH_Usb_CreateDeviceMemMap](_usb_ddk.md#oh_usb_createdevicememmap)&nbsp;(uint64_t&nbsp;deviceId,&nbsp;size_t&nbsp;size,&nbsp;[UsbDeviceMemMap](_usb_device_mem_map.md)&nbsp;\*\*devMmap) | Creates a buffer. To avoid memory leakage, use [OH_Usb_DestroyDeviceMemMap()](_usb_ddk.md#oh_usb_destroydevicememmap) to destroy a buffer after use.|
| [OH_Usb_DestroyDeviceMemMap](_usb_ddk.md#oh_usb_destroydevicememmap)&nbsp;([UsbDeviceMemMap](_usb_device_mem_map.md)&nbsp;\*devMmap) | Destroys a buffer. To avoid resource leakage, destroy a buffer in time after use.|
| [OH_Usb_GetDevices](_usb_ddk.md#oh_usb_getdevices16)&nbsp;([Usb_DeviceArray](_usb_device_array.md)&nbsp;\*devices) | Obtains the USB device ID list. Ensure that the input pointer is valid and the number of devices does not exceed 128. To prevent resource leakage, release the member memory after usage. Besides, make sure that the obtained USB device ID has been filtered by **vid** in the driver configuration information.|
