# usb_ddk_api.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明用于主机侧访问设备的USB DDK接口。

**引用文件：** <usb/usb_ddk_api.h>

**库：** libusb_ndk.z.so

**系统能力：** SystemCapability.Driver.USB.Extension

**起始版本：** 10

**相关模块：** [UsbDDK](capi-usbddk.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_Usb_Init(void)](#oh_usb_init) | 初始化DDK。 |
| [void OH_Usb_Release(void)](#oh_usb_release) | 释放DDK。 |
| [int32_t OH_Usb_ReleaseResource(void)](#oh_usb_releaseresource) | 释放DDK。 |
| [int32_t OH_Usb_GetDeviceDescriptor(uint64_t deviceId, struct UsbDeviceDescriptor *desc)](#oh_usb_getdevicedescriptor) | 获取设备描述符。 |
| [int32_t OH_Usb_GetConfigDescriptor(uint64_t deviceId, uint8_t configIndex, struct UsbDdkConfigDescriptor ** const config)](#oh_usb_getconfigdescriptor) | 获取配置描述符。请在描述符使用完后使用[OH_Usb_FreeConfigDescriptor](capi-usb-ddk-api-h.md#oh_usb_freeconfigdescriptor)释放描述符，否则会造成内存泄露。 |
| [void OH_Usb_FreeConfigDescriptor(const struct UsbDdkConfigDescriptor * const config)](#oh_usb_freeconfigdescriptor) | 释放配置描述符，请在描述符使用完后释放描述符，否则会造成内存泄露。 |
| [int32_t OH_Usb_ClaimInterface(uint64_t deviceId, uint8_t interfaceIndex, uint64_t *interfaceHandle)](#oh_usb_claiminterface) | 声明接口。 |
| [int32_t OH_Usb_ReleaseInterface(uint64_t interfaceHandle)](#oh_usb_releaseinterface) | 释放接口。 |
| [int32_t OH_Usb_SelectInterfaceSetting(uint64_t interfaceHandle, uint8_t settingIndex)](#oh_usb_selectinterfacesetting) | 激活接口的备用设置。 |
| [int32_t OH_Usb_GetCurrentInterfaceSetting(uint64_t interfaceHandle, uint8_t *settingIndex)](#oh_usb_getcurrentinterfacesetting) | 获取接口当前激活的备用设置。 |
| [int32_t OH_Usb_SendControlReadRequest(uint64_t interfaceHandle, const struct UsbControlRequestSetup *setup,uint32_t timeout, uint8_t *data, uint32_t *dataLen)](#oh_usb_sendcontrolreadrequest) | 发送控制读请求，该接口为同步接口。 |
| [int32_t OH_Usb_SendControlWriteRequest(uint64_t interfaceHandle, const struct UsbControlRequestSetup *setup,uint32_t timeout, const uint8_t *data, uint32_t dataLen)](#oh_usb_sendcontrolwriterequest) | 发送控制写请求，该接口为同步接口。 |
| [int32_t OH_Usb_SendPipeRequest(const struct UsbRequestPipe *pipe, UsbDeviceMemMap *devMmap)](#oh_usb_sendpiperequest) | 发送管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。 |
| [int32_t OH_Usb_SendPipeRequestWithAshmem(const struct UsbRequestPipe *pipe, DDK_Ashmem *ashmem)](#oh_usb_sendpiperequestwithashmem) | 发送管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。 |
| [int32_t OH_Usb_CreateDeviceMemMap(uint64_t deviceId, size_t size, UsbDeviceMemMap **devMmap)](#oh_usb_createdevicememmap) | 创建缓冲区。请在缓冲区使用完后，调用[OH_Usb_DestroyDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_destroydevicememmap)销毁缓冲区，否则会造成资源泄露。 |
| [void OH_Usb_DestroyDeviceMemMap(UsbDeviceMemMap *devMmap)](#oh_usb_destroydevicememmap) | 销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。 |
| [int32_t OH_Usb_GetDevices(struct Usb_DeviceArray *devices)](#oh_usb_getdevices) | 获取USB设备ID列表。请保证传入的指针参数是有效的，申请设备的数量不要超过128个，在使用完结构之后，释放成员内存，否则造成资源泄露。获取到的USB设备ID，已通过驱动配置信息中的vid进行筛选过滤。 |

## 函数说明

### OH_Usb_Init()

```
int32_t OH_Usb_Init(void)
```

**描述**

初始化DDK。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接 USB DDK 服务失败或内部错误。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode) 内存分配失败。 |

### OH_Usb_Release()

```
void OH_Usb_Release(void)
```

**描述**

释放DDK。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10

### OH_Usb_ReleaseResource()

```
int32_t OH_Usb_ReleaseResource(void)
```

**描述**

释放DDK。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接 USB DDK 服务失败。 |

### OH_Usb_GetDeviceDescriptor()

```
int32_t OH_Usb_GetDeviceDescriptor(uint64_t deviceId, struct UsbDeviceDescriptor *desc)
```

**描述**

获取设备描述符。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t deviceId | 设备ID，代表要获取描述符的设备。 |
| [struct UsbDeviceDescriptor](capi-usbddk-usbdevicedescriptor.md) *desc | 设备描述符，详细定义请参考[UsbDeviceDescriptor](capi-usbddk-usbdevicedescriptor.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接usb_ddk服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参desc为空指针。 |

### OH_Usb_GetConfigDescriptor()

```
int32_t OH_Usb_GetConfigDescriptor(uint64_t deviceId, uint8_t configIndex, struct UsbDdkConfigDescriptor ** const config)
```

**描述**

获取配置描述符。请在描述符使用完后使用[OH_Usb_FreeConfigDescriptor](capi-usb-ddk-api-h.md#oh_usb_freeconfigdescriptor)释放描述符，否则会造成内存泄露。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项                                               | 描述 |
|---------------------------------------------------| -- |
| uint64_t deviceId                                 | 设备ID，代表要获取配置描述符的设备。 |
| uint8_t configIndex                               | 配置id，对应USB协议中的{@link bConfigurationValue}。 |
| struct [UsbDdkConfigDescriptor](capi-usbddk-usbddkconfigdescriptor.md) ** const config | 配置描述符，包含USB协议中定义的标准配置描述符，以及与其关联的接口描述符和端点描述符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参config为空指针。<br>         {@link USB_DDK_IO_FAILED} 数据IO异常。<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode) 内存分配失败。 |

### OH_Usb_FreeConfigDescriptor()

```
void OH_Usb_FreeConfigDescriptor(const struct UsbDdkConfigDescriptor * const config)
```

**描述**

释放配置描述符，请在描述符使用完后释放描述符，否则会造成内存泄露。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [UsbDdkConfigDescriptor](capi-usbddk-usbddkconfigdescriptor.md) * const config | 配置描述符，通过[OH_Usb_GetConfigDescriptor](capi-usb-ddk-api-h.md#oh_usb_getconfigdescriptor)获得的配置描述符。 |

### OH_Usb_ClaimInterface()

```
int32_t OH_Usb_ClaimInterface(uint64_t deviceId, uint8_t interfaceIndex, uint64_t *interfaceHandle)
```

**描述**

声明接口。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t deviceId | 设备ID，代表要操作的设备。 |
| uint8_t interfaceIndex | 接口索引，对应USB协议中的[bInterfaceNumber](capi-usbddk-usbinterfacedescriptor.md)。 |
| uint64_t *interfaceHandle | 接口操作句柄，接口声明成功后，该参数将会被赋值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参interfaceHandle为空指针。<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode) 内存超出限制。 |

### OH_Usb_ReleaseInterface()

```
int32_t OH_Usb_ReleaseInterface(uint64_t interfaceHandle)
```

**描述**

释放接口。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t interfaceHandle | 接口操作句柄，代表要释放的接口。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 参数错误。 |

### OH_Usb_SelectInterfaceSetting()

```
int32_t OH_Usb_SelectInterfaceSetting(uint64_t interfaceHandle, uint8_t settingIndex)
```

**描述**

激活接口的备用设置。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t interfaceHandle | 接口操作句柄，代表要操作的接口。 |
| uint8_t settingIndex | 备用设置索引，对应USB协议中的{@link bAlternateSetting}。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 参数错误。 |

### OH_Usb_GetCurrentInterfaceSetting()

```
int32_t OH_Usb_GetCurrentInterfaceSetting(uint64_t interfaceHandle, uint8_t *settingIndex)
```

**描述**

获取接口当前激活的备用设置。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t interfaceHandle | 接口操作句柄，代表要操作的接口。 |
| uint8_t *settingIndex | 备用设置索引，对应USB协议中的{@link bAlternateSetting}。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参settingIndex为空指针。 |

### OH_Usb_SendControlReadRequest()

```
int32_t OH_Usb_SendControlReadRequest(uint64_t interfaceHandle, const struct UsbControlRequestSetup *setup,uint32_t timeout, uint8_t *data, uint32_t *dataLen)
```

**描述**

发送控制读请求，该接口为同步接口。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t interfaceHandle | 接口操作句柄，代表要操作的接口。 |
| [const struct UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md) *setup | 请求相关的参数，详细定义请参考[UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md)。 |
| uint32_t timeout | 超时时间，单位为毫秒。 |
| uint8_t *data | 要传输的数据。 |
| uint32_t *dataLen | 表示data的数据长度，在函数返回后，表示实际读取到的数据的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         [USB_DDK_FAILED](capi-usb-ddk-types-h.md#usbddkerrcode) 权限校验失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参setup或者data或者dataLen为空指针，或者datalen小于读取到的数据长度。<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode) 拷贝读取数据的内存失败。<br>         USB_DDK_IO_FAILED 数据IO异常。<br>         [USB_DDK_TIMEOUT](capi-usb-ddk-types-h.md#usbddkerrcode) 接口调用超时。 |

### OH_Usb_SendControlWriteRequest()

```
int32_t OH_Usb_SendControlWriteRequest(uint64_t interfaceHandle, const struct UsbControlRequestSetup *setup,uint32_t timeout, const uint8_t *data, uint32_t dataLen)
```

**描述**

发送控制写请求，该接口为同步接口。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t interfaceHandle | 接口操作句柄，代表要操作的接口。 |
| [const struct UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md) *setup | 请求相关的参数，详细定义请参考[UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md)。 |
| uint32_t timeout | 超时时间，单位为毫秒。 |
| const uint8_t *data | 要传输的数据。 |
| uint32_t dataLen | 表示data数据长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         [USB_DDK_FAILED](capi-usb-ddk-types-h.md#usbddkerrcode) 权限校验失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参setup或者data为空指针。<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode) 内存拷贝失败。<br>         USB_DDK_IO_FAILED 数据IO异常。<br>         [USB_DDK_TIMEOUT](capi-usb-ddk-types-h.md#usbddkerrcode) 接口调用超时。 |

### OH_Usb_SendPipeRequest()

```
int32_t OH_Usb_SendPipeRequest(const struct UsbRequestPipe *pipe, UsbDeviceMemMap *devMmap)
```

**描述**

发送管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct UsbRequestPipe](capi-usbddk-usbrequestpipe.md) *pipe | 要传输数据的管道信息。 |
| [UsbDeviceMemMap](capi-usbddk-usbdevicememmap.md) *devMmap | 数据缓冲区，可以通过[OH_Usb_CreateDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_createdevicememmap)获得。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参pipe为空指针或devMmap为空指针或devMmap的地址为空。<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode) 读取数据的内存拷贝失败。<br>         USB_DDK_IO_FAILED 数据 IO 异常。<br>         [USB_DDK_TIMEOUT](capi-usb-ddk-types-h.md#usbddkerrcode) 接口超时。 |

### OH_Usb_SendPipeRequestWithAshmem()

```
int32_t OH_Usb_SendPipeRequestWithAshmem(const struct UsbRequestPipe *pipe, DDK_Ashmem *ashmem)
```

**描述**

发送管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 12


**参数：**

| 参数项                                                         | 描述 |
|-------------------------------------------------------------| -- |
| [const struct UsbRequestPipe](capi-usbddk-usbrequestpipe.md) *pipe | 要传输数据的管道信息。 |
| [DDK_Ashmem](capi-baseddk-ddk-ashmem.md) *ashmem            | 共享内存，可以通过 {@link OH_DDK_CreateAshmem}获得。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode)入参pipe为空指针或ashmem为空指针或ashmem的地址为空。<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode) 读取数据的内存拷贝失败。<br>         USB_DDK_IO_FAILED 数据 IO 异常。<br>         [USB_DDK_TIMEOUT](capi-usb-ddk-types-h.md#usbddkerrcode) 接口超时。 |

### OH_Usb_CreateDeviceMemMap()

```
int32_t OH_Usb_CreateDeviceMemMap(uint64_t deviceId, size_t size, UsbDeviceMemMap **devMmap)
```

**描述**

创建缓冲区。请在缓冲区使用完后，调用[OH_Usb_DestroyDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_destroydevicememmap)销毁缓冲区，否则会造成资源泄露。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t deviceId | 设备ID，代表要创建缓冲区的设备。 |
| size_t size | 缓冲区的大小。 |
| [UsbDeviceMemMap](capi-usbddk-usbdevicememmap.md) **devMmap | 创建的缓冲区通过该参数返回给调用者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode)调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参devMmap为空指针。<br>         [USB_DDK_MEMORY_ERROR](capi-usb-ddk-types-h.md#usbddkerrcode) 内存映射失败或devMmap的内存分配失败。 |

### OH_Usb_DestroyDeviceMemMap()

```
void OH_Usb_DestroyDeviceMemMap(UsbDeviceMemMap *devMmap)
```

**描述**

销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbDeviceMemMap](capi-usbddk-usbdevicememmap.md) *devMmap | 销毁由[OH_Usb_CreateDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_createdevicememmap)创建的缓冲区。 |

### OH_Usb_GetDevices()

```
int32_t OH_Usb_GetDevices(struct Usb_DeviceArray *devices)
```

**描述**

获取USB设备ID列表。请保证传入的指针参数是有效的，申请设备的数量不要超过128个，在使用完结构之后，释放成员内存，否则造成资源泄露。获取到的USB设备ID，已通过驱动配置信息中的vid进行筛选过滤。

**需要权限：** ohos.permission.ACCESS_DDK_USB

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct Usb_DeviceArray](capi-usbddk-usb-devicearray.md) *devices | 已申请好的设备内存地址，用于存放获取到的设备ID列表及数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_DDK_SUCCESS](capi-usb-ddk-types-h.md#usbddkerrcode) 调用接口成功。<br>         USB_DDK_NO_PERM 权限检查失败。<br>         [USB_DDK_INVALID_OPERATION](capi-usb-ddk-types-h.md#usbddkerrcode) 连接USB DDK服务失败。<br>         [USB_DDK_INVALID_PARAMETER](capi-usb-ddk-types-h.md#usbddkerrcode) 入参devices为空指针。 |


