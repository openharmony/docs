# USBTransferInfo


## 概述

USB异步传输入参信息。

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v1_2.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int [endpoint](#endpoint) | 端点。 | 
| int [flags](#flags) | 标记位。 | 
| int [type](#type) | 传输类型。 | 
| int [timeOut](#timeout) | 超时时间。 | 
| int [length](#length) | 传输长度。 | 
| unsigned long [userData](#userdata) | 传输数据。 | 
| unsigned int [numIsoPackets](#numisopackets) | 分包数量。 | 


## 结构体成员变量说明


### endpoint

```
int USBTransferInfo::endpoint
```

**描述**

端点。


### flags

```
int USBTransferInfo::flags
```

**描述**

标记位。


### length

```
int USBTransferInfo::length
```

**描述**

传输长度。


### numIsoPackets

```
unsigned int USBTransferInfo::numIsoPackets
```

**描述**

分包数量。


### timeOut

```
int USBTransferInfo::timeOut
```

**描述**

超时时间。


### type

```
int USBTransferInfo::type
```

**描述**

传输类型。


### userData

```
unsigned long USBTransferInfo::userData
```

**描述**

传输数据。
