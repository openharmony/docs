# USB DDK


## 概述

提供USB DDK接口，包括主机侧打开和关闭接口、管道同步异步读写通信、控制传输、中断传输等。

**系统能力：** SystemCapability.Driver.USB.Extension

**起始版本：**

10

## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [usb_ddk_api.h](usb__ddk__api_8h.md) | 声明用于主机侧访问设备的USB DDK接口。<br/>引用文件：&lt;usb/usb_ddk_api.h&gt; <br/>库： libusb_ndk.z.so|
| [usb_ddk_types.h](usb__ddk__types_8h.md) | 提供USB DDK中的枚举变量、结构体定义与宏定义。<br/>引用文件：&lt;usb/usb_ddk_types.h&gt; <br/>库： libusb_ndk.z.so|


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [UsbControlRequestSetup](_usb_control_request_setup.md) | 控制传输setup包，对应USB协议中的Setup Data。 |
| [UsbDeviceDescriptor](_usb_device_descriptor.md) | 标准设备描述符，对应USB协议中Standard Device Descriptor。 |
| [UsbConfigDescriptor](_usb_config_descriptor.md) | 标准配置描述符，对应USB协议中Standard Configuration Descriptor。 |
| [UsbInterfaceDescriptor](_usb_interface_descriptor.md) | 标准接口描述符，对应USB协议中Standard Interface Descriptor。 |
| [UsbEndpointDescriptor](_usb_endpoint_descriptor.md) | 标准端点描述符，对应USB协议中Standard Endpoint Descriptor。 |
| [UsbDdkEndpointDescriptor](_usb_ddk_endpoint_descriptor.md) | 端点描述符。 |
| [UsbDdkInterfaceDescriptor](_usb_ddk_interface_descriptor.md) | 接口描述符。 |
| [UsbDdkInterface](_usb_ddk_interface.md) | USB接口，是特定接口下备用设置的集合。 |
| [UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md) | 配置描述符。 |
| [UsbRequestPipe](_usb_request_pipe.md) | 请求管道。 |
| [UsbDeviceMemMap](_usb_device_mem_map.md) | 设备内存映射，通过[OH_Usb_CreateDeviceMemMap()](#oh_usb_createdevicememmap)创建设备内存映射，使用内存映射后的缓冲区，获得更好的性能。 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [UsbDdkErrCode](#usbddkerrcode) {<br/>USB_DDK_SUCCESS = 0, USB_DDK_FAILED = -1, USB_DDK_INVALID_PARAMETER = -2, USB_DDK_MEMORY_ERROR = -3,<br/>USB_DDK_INVALID_OPERATION = -4, USB_DDK_NULL_PTR = -5, USB_DDK_DEVICE_BUSY = -6, USB_DDK_TIMEOUT = -7<br/>} | USB DDK 错误码定义。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Usb_Init](#oh_usb_init) (void) | 初始化DDK。 |
| [OH_Usb_Release](#oh_usb_release) (void) | 释放DDK。 |
| [OH_Usb_GetDeviceDescriptor](#oh_usb_getdevicedescriptor) (uint64_t deviceId, struct [UsbDeviceDescriptor](_usb_device_descriptor.md) \*desc) | 获取设备描述符。 |
| [OH_Usb_GetConfigDescriptor](#oh_usb_getconfigdescriptor) (uint64_t deviceId, uint8_t configIndex, struct [UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md) \*\*const config) | 获取配置描述符。请在描述符使用完后使用[OH_Usb_FreeConfigDescriptor()](#oh_usb_freeconfigdescriptor)释放描述符，否则会造成内存泄露。 |
| [OH_Usb_FreeConfigDescriptor](#oh_usb_freeconfigdescriptor) (const struct [UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md) \*const config) | 释放配置描述符，请在描述符使用完后释放描述符，否则会造成内存泄露。 |
| [OH_Usb_ClaimInterface](#oh_usb_claiminterface) (uint64_t deviceId, uint8_t interfaceIndex, uint64_t \*[interfaceHandle](usb__ddk__types_8h.md#interfacehandle)) | 声明接口。 |
| [OH_Usb_ReleaseInterface](#oh_usb_releaseinterface) (uint64_t [interfaceHandle](usb__ddk__types_8h.md#interfacehandle)) | 释放接口。 |
| [OH_Usb_SelectInterfaceSetting](#oh_usb_selectinterfacesetting) (uint64_t [interfaceHandle](usb__ddk__types_8h.md#interfacehandle), uint8_t settingIndex) | 激活接口的备用设置。 |
| [OH_Usb_GetCurrentInterfaceSetting](#oh_usb_getcurrentinterfacesetting) (uint64_t [interfaceHandle](usb__ddk__types_8h.md#interfacehandle), uint8_t \*settingIndex) | 获取接口当前激活的备用设置。 |
| [OH_Usb_SendControlReadRequest](#oh_usb_sendcontrolreadrequest) (uint64_t [interfaceHandle](usb__ddk__types_8h.md#interfacehandle), const struct [UsbControlRequestSetup](_usb_control_request_setup.md) \*setup, uint32_t [timeout](usb__ddk__types_8h.md#timeout), uint8_t \*data, uint32_t \*dataLen) | 发送控制读请求，该接口为同步接口。 |
| [OH_Usb_SendControlWriteRequest](#oh_usb_sendcontrolwriterequest) (uint64_t [interfaceHandle](usb__ddk__types_8h.md#interfacehandle), const struct [UsbControlRequestSetup](_usb_control_request_setup.md) \*setup, uint32_t [timeout](usb__ddk__types_8h.md#timeout), const uint8_t \*data, uint32_t dataLen) | 发送控制写请求，该接口为同步接口。 |
| [OH_Usb_SendPipeRequest](#oh_usb_sendpiperequest) (const struct [UsbRequestPipe](_usb_request_pipe.md) \*pipe, [UsbDeviceMemMap](_usb_device_mem_map.md) \*devMmap) | 发送管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。 |
| [OH_Usb_SendPipeRequestWithAshmem](#oh_usb_sendpiperequestwithashmem) (const struct [UsbRequestPipe](_usb_request_pipe.md) \*pipe, [DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | 发送共享内存管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。 |
| [OH_Usb_CreateDeviceMemMap](#oh_usb_createdevicememmap) (uint64_t deviceId, size_t size, [UsbDeviceMemMap](_usb_device_mem_map.md) \*\*devMmap) | 创建缓冲区。请在缓冲区使用完后，调用[OH_Usb_DestroyDeviceMemMap()](#oh_usb_destroydevicememmap)销毁缓冲区，否则会造成资源泄露。 |
| [OH_Usb_DestroyDeviceMemMap](#oh_usb_destroydevicememmap) ([UsbDeviceMemMap](_usb_device_mem_map.md) \*devMmap) | 销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。 |

#### 函数参数deviceId说明

设备ID（deviceId）的获取可通过外设查询接口queryDevices()查询。
具体请查阅[扩展外设管理开发指导](../../device/driver/externaldevice-guidelines.md)。

#### 函数参数deviceId转换指导

通过外设查询接口queryDevices()获取到的deviceId，还需要通过数据转换，才能得到[OH_Usb_GetDeviceDescriptor](#oh_usb_getdevicedescriptor) 等函数的入参deviceId。
<p>转换原理：提取queryDevices()获取到的deviceId的前32位作为C_API的deviceId。</p>
<p>以下代码仅供参考：</p>

 ~~~
uint64_t JsDeviceIdToNative(uint64_t deviceId)
{
    uint32_t busNum = (uint32_t)(deviceId >> 48);
    uint32_t devNum = (uint32_t)((deviceId & 0x0000FFFF00000000) >> 32);
    return (((static_cast<uint64_t>(busNum)) << 32) | devNum);
}
~~~

## 枚举类型说明


### UsbDdkErrCode


```
enum UsbDdkErrCode
```

**描述:**

USB DDK 错误码定义。

| 枚举值 | 描述 |
| -------- | -------- |
| USB_DDK_SUCCESS | 操作成功。 |
| USB_DDK_FAILED | 操作失败。 |
| USB_DDK_INVALID_PARAMETER | 非法参数。 |
| USB_DDK_MEMORY_ERROR | 内存相关的错误，包括：内存不足、内存数据拷贝失败、内存申请失败等。 |
| USB_DDK_INVALID_OPERATION | 非法操作。 |
| USB_DDK_NULL_PTR | 空指针异常。 |
| USB_DDK_DEVICE_BUSY | 设备忙。 |
| USB_DDK_TIMEOUT | 传输超时。 |


## 函数说明


### OH_Usb_ClaimInterface()


```
int32_t OH_Usb_ClaimInterface (uint64_t deviceId, uint8_t interfaceIndex, uint64_t * interfaceHandle )
```

**描述:**

声明接口。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| deviceId | 设备ID，代表要操作的设备。 |
| interfaceIndex | 接口索引，对应USB协议中的[bInterfaceNumber](_usb_interface_descriptor.md#binterfacenumber)。 |
| interfaceHandle | 接口操作句柄，接口声明成功后，该参数将会被赋值。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参interfaceHandle为空指针。


### OH_Usb_CreateDeviceMemMap()


```
int32_t OH_Usb_CreateDeviceMemMap (uint64_t deviceId, size_t size, UsbDeviceMemMap ** devMmap )
```

**描述:**

创建缓冲区。请在缓冲区使用完后，调用[OH_Usb_DestroyDeviceMemMap()](#oh_usb_destroydevicememmap)销毁缓冲区，否则会造成资源泄露。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| deviceId | 设备ID，代表要创建缓冲区的设备。 |
| size | 缓冲区的大小。 |
| devMmap | 创建的缓冲区通过该参数返回给调用者。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参devMmap为空指针。
- [USB_DDK_MEMORY_ERROR](#usbddkerrcode)：表示mmap失败或者申请devMmap的内存空间失败。


### OH_Usb_DestroyDeviceMemMap()


```
void OH_Usb_DestroyDeviceMemMap (UsbDeviceMemMap * devMmap)
```

**描述:**

销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| devMmap | 销毁由[OH_Usb_CreateDeviceMemMap()](#oh_usb_createdevicememmap)创建的缓冲区。 |


### OH_Usb_FreeConfigDescriptor()


```
void OH_Usb_FreeConfigDescriptor (struct UsbDdkConfigDescriptor *const config)
```

**描述:**

释放配置描述符，请在描述符使用完后释放描述符，否则会造成内存泄露。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| config | 配置描述符，通过[OH_Usb_GetConfigDescriptor()](#oh_usb_getconfigdescriptor)获得的配置描述符。 |


### OH_Usb_GetConfigDescriptor()


```
int32_t OH_Usb_GetConfigDescriptor (uint64_t deviceId, uint8_t configIndex, struct UsbDdkConfigDescriptor **const config )
```

**描述:**

获取配置描述符。请在描述符使用完后使用[OH_Usb_FreeConfigDescriptor()](#oh_usb_freeconfigdescriptor)释放描述符，否则会造成内存泄露。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| deviceId | 设备ID，代表要获取配置描述符的设备。 |
| configIndex | 配置id，对应USB协议中的[bConfigurationValue](_usb_config_descriptor.md#bconfigurationvalue)。 |
| config | 配置描述符，包含USB协议中定义的标准配置描述符，以及与其关联的接口描述符和端点描述符。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参config为空指针。


### OH_Usb_GetCurrentInterfaceSetting()


```
int32_t OH_Usb_GetCurrentInterfaceSetting (uint64_t interfaceHandle, uint8_t * settingIndex )
```

**描述:**

获取接口当前激活的备用设置。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| interfaceHandle | 接口操作句柄，代表要操作的接口。 |
| settingIndex | 备用设置索引，对应USB协议中的[bAlternateSetting](_usb_interface_descriptor.md#balternatesetting)。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参settingIndex为空指针。


### OH_Usb_GetDeviceDescriptor()


```
int32_t OH_Usb_GetDeviceDescriptor (uint64_t deviceId, struct UsbDeviceDescriptor * desc )
```

**描述:**

获取设备描述符。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| deviceId | 设备ID，代表要获取描述符的设备。 |
| desc | 设备描述符，详细定义请参考[UsbDeviceDescriptor](_usb_device_descriptor.md)。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参desc为空指针。

### OH_Usb_Init()


```
int32_t OH_Usb_Init (void )
```

**描述:**

初始化DDK。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败、连接usb_ddk服务失败或者内部错误失败。

### OH_Usb_Release()


```
void OH_Usb_Release (void )
```

**描述:**

释放DDK。

**需要权限**：ohos.permission.ACCESS_DDK_USB


### OH_Usb_ReleaseInterface()


```
int32_t OH_Usb_ReleaseInterface (uint64_t interfaceHandle)
```

**描述:**

释放接口。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| interfaceHandle | 接口操作句柄，代表要释放的接口。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。


### OH_Usb_SelectInterfaceSetting()


```
int32_t OH_Usb_SelectInterfaceSetting (uint64_t interfaceHandle, uint8_t settingIndex )
```

**描述:**

激活接口的备用设置。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| interfaceHandle | 接口操作句柄，代表要操作的接口。 |
| settingIndex | 备用设置索引，对应USB协议中的[bAlternateSetting](_usb_interface_descriptor.md#balternatesetting)。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。


### OH_Usb_SendControlReadRequest()


```
int32_t OH_Usb_SendControlReadRequest (uint64_t interfaceHandle, const struct UsbControlRequestSetup * setup, uint32_t timeout, uint8_t * data, uint32_t * dataLen )
```

**描述:**

发送控制读请求，该接口为同步接口。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| interfaceHandle | 接口操作句柄，代表要操作的接口。 |
| setup | 请求相关的参数，详细定义请参考 [UsbControlRequestSetup](_usb_control_request_setup.md)。 |
| timeout | 超时时间，单位为毫秒。 |
| data | 要传输的数据。 |
| dataLen | 表示data的数据长度，在函数返回后，表示实际读取到的数据的长度。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参setup、data或者dataLen为空指针，亦或datalen小于读取到的数据长度。
- [USB_DDK_MEMORY_ERROR](#usbddkerrcode)：表示拷贝读取数据的内存失败。


### OH_Usb_SendControlWriteRequest()


```
int32_t OH_Usb_SendControlWriteRequest (uint64_t interfaceHandle, const struct UsbControlRequestSetup * setup, uint32_t timeout, const uint8_t * data, uint32_t dataLen )
```

**描述:**

发送控制写请求，该接口为同步接口。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| interfaceHandle | 接口操作句柄，代表要操作的接口。 |
| setup | 请求相关的参数，详细定义请参考 [UsbControlRequestSetup](_usb_control_request_setup.md)。 |
| timeout | 超时时间，单位为毫秒。 |
| data | 要传输的数据。 |
| dataLen | 表示data的数据长度。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参setup或者data为空指针。


### OH_Usb_SendPipeRequest()


```
int32_t OH_Usb_SendPipeRequest (const struct UsbRequestPipe * pipe, UsbDeviceMemMap * devMmap )
```

**描述:**

发送管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pipe | 要传输数据的管道信息。 |
| devMmap | 数据缓冲区，可以通过[OH_Usb_CreateDeviceMemMap()](#oh_usb_createdevicememmap)获得。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参pipe、devMmap或者devMmap的地址为空指针。


### OH_Usb_SendPipeRequestWithAshmem()


```
int32_t OH_Usb_SendPipeRequestWithAshmem(const struct UsbRequestPipe *pipe, DDK_Ashmem *ashmem);
```

**描述:**

发送共享内存的管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。

**需要权限**：ohos.permission.ACCESS_DDK_USB

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pipe | 要传输数据的管道信息。 |
| ashmem | 共享内存，可以通过[OH_DDK_CreateAshmem()](_base_ddk.md#oh_ddk_createashmem)获得。 |

**返回:**

- [USB_DDK_SUCCESS](#usbddkerrcode)：表示调用接口成功。
- [USB_DDK_FAILED](#usbddkerrcode)：表示权限校验失败或者内部错误失败。
- [USB_DDK_INVALID_OPERATION](#usbddkerrcode)：表示连接usb_ddk服务失败。
- [USB_DDK_INVALID_PARAMETER](#usbddkerrcode)：表示入参pipe、ashmem或者ashmem的地址为空指针。

