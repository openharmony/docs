# UsbPipe


## 概述

USB设备管道信息。

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| unsigned char [intfId](#intfid) | USB设备接口ID。 | 
| unsigned char [endpointId](#endpointid) | USB设备端点ID。 | 


## 结构体成员变量说明


### endpointId

```
unsigned char UsbPipe::endpointId
```

**描述**

USB设备端点ID。


### intfId

```
unsigned char UsbPipe::intfId
```

**描述**

USB设备接口ID。
