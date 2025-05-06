# usb_ddk_api.h


## 概述

声明用于主机侧访问设备的USB DDK接口。

**起始版本：**

10

**相关模块：**

[USB DDK](_usb_ddk.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Usb_Init](_usb_ddk.md#oh_usb_init)&nbsp;(void) | 初始化DDK。 |
| [OH_Usb_Release](_usb_ddk.md#oh_usb_release)&nbsp;(void) | 释放DDK。 |
| [OH_Usb_ReleaseResource](_usb_ddk.md#oh_usb_releaseresource)&nbsp;(void) | 释放DDK。 |
| [OH_Usb_GetDeviceDescriptor](_usb_ddk.md#oh_usb_getdevicedescriptor)&nbsp;(uint64_t&nbsp;deviceId,&nbsp;struct&nbsp;[UsbDeviceDescriptor](_usb_device_descriptor.md)&nbsp;\*desc) | 获取设备描述符。 |
| [OH_Usb_GetConfigDescriptor](_usb_ddk.md#oh_usb_getconfigdescriptor)&nbsp;(uint64_t&nbsp;deviceId,&nbsp;uint8_t&nbsp;configIndex,&nbsp;struct&nbsp;[UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md)&nbsp;\*\*const&nbsp;config) | 获取配置描述符。请在描述符使用完后使用[OH_Usb_FreeConfigDescriptor()](_usb_ddk.md#oh_usb_freeconfigdescriptor)释放描述符，否则会造成内存泄露。 |
| [OH_Usb_FreeConfigDescriptor](_usb_ddk.md#oh_usb_freeconfigdescriptor)&nbsp;(const&nbsp;struct&nbsp;[UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md)&nbsp;\*const&nbsp;config) | 释放配置描述符，请在描述符使用完后释放描述符，否则会造成内存泄露。 |
| [OH_Usb_ClaimInterface](_usb_ddk.md#oh_usb_claiminterface)&nbsp;(uint64_t&nbsp;deviceId,&nbsp;uint8_t&nbsp;interfaceIndex,&nbsp;uint64_t&nbsp;\*[interfaceHandle](usb__ddk__types_8h.md#interfacehandle)) | 声明接口。 |
| [OH_Usb_ReleaseInterface](_usb_ddk.md#oh_usb_releaseinterface)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle)) | 释放接口。 |
| [OH_Usb_SelectInterfaceSetting](_usb_ddk.md#oh_usb_selectinterfacesetting)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle),&nbsp;uint8_t&nbsp;settingIndex) | 激活接口的备用设置。 |
| [OH_Usb_GetCurrentInterfaceSetting](_usb_ddk.md#oh_usb_getcurrentinterfacesetting)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle),&nbsp;uint8_t&nbsp;\*settingIndex) | 获取接口当前激活的备用设置。 |
| [OH_Usb_SendControlReadRequest](_usb_ddk.md#oh_usb_sendcontrolreadrequest)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle),&nbsp;const&nbsp;struct&nbsp;[UsbControlRequestSetup](_usb_control_request_setup.md)&nbsp;\*setup,&nbsp;uint32_t&nbsp;[timeout](usb__ddk__types_8h.md#timeout),&nbsp;uint8_t&nbsp;\*data,&nbsp;uint32_t&nbsp;\*dataLen) | 发送控制读请求，该接口为同步接口。 |
| [OH_Usb_SendControlWriteRequest](_usb_ddk.md#oh_usb_sendcontrolwriterequest)&nbsp;(uint64_t&nbsp;[interfaceHandle](usb__ddk__types_8h.md#interfacehandle),&nbsp;const&nbsp;struct&nbsp;[UsbControlRequestSetup](_usb_control_request_setup.md)&nbsp;\*setup,&nbsp;uint32_t&nbsp;[timeout](usb__ddk__types_8h.md#timeout),&nbsp;const&nbsp;uint8_t&nbsp;\*data,&nbsp;uint32_t&nbsp;dataLen) | 发送控制写请求，该接口为同步接口。 |
| [OH_Usb_SendPipeRequest](_usb_ddk.md#oh_usb_sendpiperequest)&nbsp;(const&nbsp;struct&nbsp;[UsbRequestPipe](_usb_request_pipe.md)&nbsp;\*pipe,&nbsp;[UsbDeviceMemMap](_usb_device_mem_map.md)&nbsp;\*devMmap) | 发送管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。 |
| [OH_Usb_SendPipeRequestWithAshmem](_usb_ddk.md#oh_usb_sendpiperequestwithashmem)&nbsp;(const&nbsp;struct&nbsp;[UsbRequestPipe](_usb_request_pipe.md)&nbsp;\*pipe,&nbsp;[DDK_Ashmem](_ddk_ashmem.md)&nbsp;\*ashmem) | 发送共享内存的管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。 |
| [OH_Usb_CreateDeviceMemMap](_usb_ddk.md#oh_usb_createdevicememmap)&nbsp;(uint64_t&nbsp;deviceId,&nbsp;size_t&nbsp;size,&nbsp;[UsbDeviceMemMap](_usb_device_mem_map.md)&nbsp;\*\*devMmap) | 创建缓冲区。请在缓冲区使用完后，调用[OH_Usb_DestroyDeviceMemMap()](_usb_ddk.md#oh_usb_destroydevicememmap)销毁缓冲区，否则会造成资源泄露。 |
| [OH_Usb_DestroyDeviceMemMap](_usb_ddk.md#oh_usb_destroydevicememmap)&nbsp;([UsbDeviceMemMap](_usb_device_mem_map.md)&nbsp;\*devMmap) | 销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。 |
| [OH_Usb_GetDevices](_usb_ddk.md#oh_usb_getdevices)&nbsp;([Usb_DeviceArray](_usb_device_array.md)&nbsp;\*devices) | 获取USB设备ID列表。请保证传入的指针参数是有效的，申请设备的数量不要超过128个，在使用完结构之后，释放成员内存，否则造成资源泄露。获取到的USB设备ID，已通过驱动配置信息中的vid进行筛选过滤。 |
