# usb_ddk_types.h


## 概述

提供USB DDK中的枚举变量、结构体定义与宏定义。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [UsbControlRequestSetup](_usb_control_request_setup.md) | 控制传输setup包，对应USB协议中的Setup&nbsp;Data。 |
| [UsbDeviceDescriptor](_usb_device_descriptor.md) | 标准设备描述符，对应USB协议中Standard&nbsp;Device&nbsp;Descriptor。 |
| [UsbConfigDescriptor](_usb_config_descriptor.md) | 标准配置描述符，对应USB协议中Standard&nbsp;Configuration&nbsp;Descriptor。 |
| [UsbInterfaceDescriptor](_usb_interface_descriptor.md) | 标准接口描述符，对应USB协议中Standard&nbsp;Interface&nbsp;Descriptor。 |
| [UsbEndpointDescriptor](_usb_endpoint_descriptor.md) | 标准端点描述符，对应USB协议中Standard&nbsp;Endpoint&nbsp;Descriptor。 |
| [UsbDdkEndpointDescriptor](_usb_ddk_endpoint_descriptor.md) | 端点描述符。 |
| [UsbDdkInterfaceDescriptor](_usb_ddk_interface_descriptor.md) | 接口描述符。 |
| [UsbDdkInterface](_usb_ddk_interface.md) | USB接口，是特定接口下备用设置的集合。 |
| [UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md) | 配置描述符。 |
| [UsbRequestPipe](_usb_request_pipe.md) | 请求管道。 |
| [UsbDeviceMemMap](_usb_device_mem_map.md) | 设备内存映射，通过[OH_Usb_CreateDeviceMemMap()](_usb_ddk.md#oh_usb_createdevicememmap)创建设备内存映射，使用内存映射后的缓冲区，获得更好的性能。 |
| [Usb_DeviceArray](_usb_device_array.md) | 设备ID清单，用于存放[OH_Usb_GetDevices()](_usb_ddk.md#oh_usb_getdevices16)接口获取到的设备ID列表和设备数量。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef struct [UsbDdkEndpointDescriptor](_usb_ddk_endpoint_descriptor.md) [UsbDdkEndpointDescriptor](_usb_ddk.md#usbddkendpointdescriptor) | 端点描述符。 |
| typedef struct [UsbDdkInterfaceDescriptor](_usb_ddk_interface_descriptor.md) [UsbDdkInterfaceDescriptor](_usb_ddk.md#usbddkinterfacedescriptor) | 接口描述符。 |
| typedef struct [UsbDdkInterface](_usb_ddk_interface.md) [UsbDdkInterface](_usb_ddk.md#usbddkinterface) | USB接口。 |
| typedef struct [UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md) [UsbDdkConfigDescriptor](_usb_ddk.md#usbddkconfigdescriptor) | 配置描述符。 |
| typedef struct [UsbDeviceMemMap](_usb_device_mem_map.md) [UsbDeviceMemMap](_usb_ddk.md#usbdevicememmap) | 设备内存映射，通过[OH_Usb_CreateDeviceMemMap()](_usb_ddk.md#oh_usb_createdevicememmap)创建设备内存映射，使用内存映射后的缓冲区，获得更好的性能。 |
| typedef struct [Usb_DeviceArray](_usb_device_array.md) [Usb_DeviceArray](_usb_ddk.md#usb_devicearray) | 设备ID清单，用于存放[OH_Usb_GetDevices()](_usb_ddk.md#oh_usb_getdevices16)接口获取到的设备ID列表和设备数量。 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [UsbDdkErrCode](_usb_ddk.md#usbddkerrcode)&nbsp;{<br/>USB_DDK_SUCCESS&nbsp;=&nbsp;0,&nbsp;USB_DDK_FAILED&nbsp;=&nbsp;-1,&nbsp;USB_DDK_INVALID_PARAMETER&nbsp;=&nbsp;-2,&nbsp;USB_DDK_MEMORY_ERROR&nbsp;=&nbsp;-3,<br/>USB_DDK_INVALID_OPERATION&nbsp;=&nbsp;-4,&nbsp;USB_DDK_NULL_PTR&nbsp;=&nbsp;-5,&nbsp;USB_DDK_DEVICE_BUSY&nbsp;=&nbsp;-6,&nbsp;USB_DDK_TIMEOUT&nbsp;=&nbsp;-7<br/>} | USB&nbsp;DDK&nbsp;错误码定义。 |


### 变量

| 名称 | 描述 |
| -------- | -------- |
| [bmRequestType](#bmrequesttype) | 请求类型。 |
| [bRequest](#brequest) | 具体的请求。 |
| [wValue](#wvalue) | 具体的请求不同，其代表的含义不一样。 |
| [wIndex](#windex) | 具体的请求不同，其代表的含义不一样，通常用来传递索引或者偏移量。 |
| [wLength](#wlength) | 如果有数据阶段的传输，其代表传输的字节个数。 |
| [bLength](#blength) | 该描述符的大小，单位为字节。 |
| [bDescriptorType](#bdescriptortype) | 描述符类型。 |
| [bcdUSB](#bcdusb) | USB协议发布号。 |
| [bDeviceClass](#bdeviceclass) | 由USB标准化组织（USB-IF）分配的设备类代码。 |
| [bDeviceSubClass](#bdevicesubclass) | 由USB标准化组织（USB-IF）分配的子类代码，其值由[bDeviceClass](#bdeviceclass)的值限定。 |
| [bDeviceProtocol](#bdeviceprotocol) | 由USB标准化组织（USB-IF）分配的协议代码，其值由[bDeviceClass](#bdeviceclass)和[bDeviceSubClass](#bdevicesubclass)的值限定。 |
| [bMaxPacketSize0](#bmaxpacketsize0) | 端点零的最大包大小，只有8、16、32、64是合法的。 |
| [idVendor](#idvendor) | 由USB标准化组织（USB-IF）分配的厂商编号。 |
| [idProduct](#idproduct) | 由厂商分配的产品编号。 |
| [bcdDevice](#bcddevice) | 设备发布编号。 |
| [iManufacturer](#imanufacturer) | 描述厂商的字符串描述符的索引。 |
| [iProduct](#iproduct) | 描述产品的字符串描述符的索引。 |
| [iSerialNumber](#iserialnumber) | 描述设备序列号的字符串描述符的索引。 |
| [bNumConfigurations](#bnumconfigurations) | 配置数量。 |
| [wTotalLength](#wtotallength) | 该配置描述符的总长度，包含配置、接口、端点和特定于类或供应商的描述符。 |
| [bNumInterfaces](#bnuminterfaces) | 该配置所支持的接口数量。 |
| [bConfigurationValue](#bconfigurationvalue) | 设置配置所需要的参数，用来选择当前配置。 |
| [iConfiguration](#iconfiguration) | 描述该配置的字符串描述符的索引。 |
| [bmAttributes](#bmattributes) | 配置属性，包含供电模式、远程唤醒等配置。 |
| [bMaxPower](#bmaxpower) | 总线供电的USB设备的最大功耗，以2mA为单位。 |
| [bInterfaceNumber](#binterfacenumber) | 接口编号。 |
| [bAlternateSetting](#balternatesetting) | 用来选择该接口的备用配置的值。 |
| [bNumEndpoints](#bnumendpoints) | 该接口所使用的端点数量（不包括端点零）。 |
| [bInterfaceClass](#binterfaceclass) | 由USB标准化组织（USB-IF）分配的设备类代码。 |
| [bInterfaceSubClass](#binterfacesubclass) | 由USB标准化组织（USB-IF）分配的子类代码，其值由[bInterfaceClass](#binterfaceclass)的值限定。 |
| [bInterfaceProtocol](#binterfaceprotocol) | 由USB标准化组织（USB-IF）分配的协议代码，其值由[bInterfaceClass](#binterfaceclass)和[bInterfaceSubClass](#binterfacesubclass)的值限定。 |
| [iInterface](#iinterface) | 描述该接口的字符串描述符的索引。 |
| [bEndpointAddress](#bendpointaddress) | 端点地址，包含端点编号以及端点方向。 |
| [bmAttributes](#bmattributes) | 端点属性，包括传输类型、同步类型、使用类型。 |
| [wMaxPacketSize](#wmaxpacketsize) | 该端点所能承载的最大包的大小。 |
| [bInterval](#binterval) | 数据传输轮询端点的时间间隔。 |
| [bRefresh](#brefresh) | 用于音频类设备，同步反馈的速率。 |
| [bSynchAddress](#bsynchaddress) | 用于音频类设备，同步端点的地址。 |
| [interfaceHandle](#interfacehandle) | 接口操作句柄。 |
| [endpoint](#endpoint) | 要通信的端点的地址。 |
| [timeout](#timeout) | 超时时间，单位是毫秒。 |
| [deviceIds](#deviceids) | 开发者申请好的设备数组首地址。 |
| [num](#num) | 实际返回的设备数量。 |


## 变量说明


### bAlternateSetting


```
uint8_t bAlternateSetting
```

**描述:**

用来选择该接口的备用配置的值。


### bcdDevice


```
uint16_t bcdDevice
```

**描述:**

设备发布编号。


### bcdUSB


```
uint16_t bcdUSB
```

**描述:**

USB协议发布号。


### bConfigurationValue


```
uint8_t bConfigurationValue
```

**描述:**

设置配置所需要的参数，用来选择当前配置。


### bDescriptorType


```
uint8_t bDescriptorType
```

**描述:**

描述符类型。


### bDeviceClass


```
uint8_t bDeviceClass
```

**描述:**

由USB标准化组织（USB-IF）分配的设备类代码。


### bDeviceProtocol


```
uint8_t bDeviceProtocol
```

**描述:**

由USB标准化组织（USB-IF）分配的协议代码，其值由[bDeviceClass](#bdeviceclass)和[bDeviceSubClass](#bdevicesubclass)的值限定。


### bDeviceSubClass


```
uint8_t bDeviceSubClass
```

**描述:**

由USB标准化组织（USB-IF）分配的子类代码，其值由[bDeviceClass](#bdeviceclass)的值限定。


### bEndpointAddress


```
uint8_t bEndpointAddress
```

**描述:**

端点地址，包含端点编号以及端点方向。


### bmAttributes


```
uint8_t bmAttributes
```

**描述:**

端点属性，包括传输类型、同步类型、使用类型。


### bInterfaceClass


```
uint8_t bInterfaceClass
```

**描述:**

由USB标准化组织（USB-IF）分配的设备类代码。


### bInterfaceNumber


```
uint8_t bInterfaceNumber
```

**描述:**

接口编号。


### bInterfaceProtocol


```
uint8_t bInterfaceProtocol
```

**描述:**

由USB标准化组织（USB-IF）分配的协议代码，其值由[bInterfaceClass](#binterfaceclass)和[bInterfaceSubClass](#binterfacesubclass)的值限定。


### bInterfaceSubClass


```
uint8_t bInterfaceSubClass
```

**描述:**

由USB标准化组织（USB-IF）分配的子类代码，其值由[bInterfaceClass](#binterfaceclass)的值限定。


### bInterval


```
uint8_t bInterval
```

**描述:**

数据传输轮询端点的时间间隔。


### bLength


```
uint8_t bLength
```

**描述:**

该描述符的大小，单位为字节。


### bmAttributes


```
uint8_t bmAttributes
```

**描述:**

配置属性，包含供电模式、远程唤醒等配置。


### bMaxPacketSize0


```
uint8_t bMaxPacketSize0
```

**描述:**

端点零的最大包大小，只有8、16、32、64是合法的。


### bMaxPower


```
uint8_t bMaxPower
```

**描述:**

总线供电的USB设备的最大功耗，以2mA为单位。


### bNumConfigurations


```
uint8_t bNumConfigurations
```

**描述:**

配置数量。


### bNumEndpoints


```
uint8_t bNumEndpoints
```

**描述:**

该接口所使用的端点数量（不包括端点零）。


### bNumInterfaces


```
uint8_t bNumInterfaces
```

**描述:**

该配置所支持的接口数量。


### bRefresh


```
uint8_t bRefresh
```

**描述:**

用于音频类设备，同步反馈的速率。


### bSynchAddress


```
uint8_t bSynchAddress
```

**描述:**

用于音频类设备，同步端点的地址。


### endpoint


```
uint8_t endpoint
```

**描述:**

要通信的端点的地址。


### iConfiguration


```
uint8_t iConfiguration
```

**描述:**

描述该配置的字符串描述符的索引。


### idProduct


```
uint16_t idProduct
```

**描述:**

由厂商分配的产品编号。


### idVendor


```
uint16_t idVendor
```

**描述:**

由USB标准化组织（USB-IF）分配的厂商编号。


### iInterface


```
uint8_t iInterface
```

**描述:**

描述该接口的字符串描述符的索引。


### iManufacturer


```
uint8_t iManufacturer
```

**描述:**

描述厂商的字符串描述符的索引。


### wIndex


```
uint16_t wIndex
```

**描述:**

具体的请求不同，其代表的含义不一样，通常用来传递索引或者偏移量。


### interfaceHandle


```
uint64_t interfaceHandle
```

**描述:**

接口操作句柄。


### iProduct


```
uint8_t iProduct
```

**描述:**

描述产品的字符串描述符的索引。


### iSerialNumber


```
uint8_t iSerialNumber
```

**描述:**

描述设备序列号的字符串描述符的索引。


### wLength


```
uint16_t wLength
```

**描述:**

如果有数据阶段的传输，其代表传输的字节个数。


### bRequest


```
uint8_t bRequest
```

**描述:**

具体的请求。


### bmRequestType


```
uint8_t bmRequestType
```

**描述:**

请求类型。


### timeout


```
uint32_t timeout
```

**描述:**

超时时间，单位是毫秒。


### wValue


```
uint16_t wValue
```

**描述:**

具体的请求不同，其代表的含义不一样。


### wMaxPacketSize


```
uint16_t wMaxPacketSize
```

**描述:**

该端点所能承载的最大包的大小。


### wTotalLength


```
uint16_t wTotalLength
```

**描述:**

该配置描述符的总长度，包含配置、接口、端点和特定于类或供应商的描述符。


### deviceIds

```
uint64_t* deviceIds
```

**描述:**

开发者申请好的设备数组首地址，申请的大小不超过128个设备ID。
### num


```
uint32_t num
```

**描述:**

实际返回的设备数量，根据数量遍历deviceIds获得设备ID。当该值为0时，表示不存在USB设备。