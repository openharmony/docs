# UsbIsoPacketDescriptor


## 概述

USB异步传输用于实时传输的分包描述符。

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v1_2.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int [isoLength](#isolength) | 长度。 | 
| int [isoActualLength](#isoactuallength) | 真实长度。 | 
| int [isoStatus](#isostatus) | 状态。 | 


## 结构体成员变量说明


### isoActualLength

```
int UsbIsoPacketDescriptor::isoActualLength
```

**描述**

真实长度。


### isoLength

```
int UsbIsoPacketDescriptor::isoLength
```

**描述**

长度。


### isoStatus

```
int UsbIsoPacketDescriptor::isoStatus
```

**描述**

状态。
