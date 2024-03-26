# Hid_Device


## 概述

设备基本信息。

**起始版本：**

11

**相关模块：**

[HID DDK](_hid_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [deviceName](#devicename) | 设备名称 | 
| [vendorId](#vendorid) | 厂商ID | 
| [productId](#productid) | 产品ID | 
| [version](#version) | 版本号 | 
| [bustype](#bustype) | 总线类型 | 
| [properties](#properties) | 设备特性 | 
| [propLength](#proplength) | 设备特性数量 | 


## 结构体成员变量说明


### deviceName


```
const char Hid_Device::deviceName
```

**描述:**

设备名称


### vendorId


```
uint16_t Hid_Device::vendorId
```

**描述:**

厂商ID


### productId


```
uint16_t  Hid_Device::productId
```

**描述:**

产品ID


### version


```
uint16_t Hid_Device::version
```

**描述:**

版本号


### bustype


```
uint16_t Hid_Device::bustype
```

**描述:**

总线类型


### properties


```
Hid_DeviceProp Hid_Device::properties
```

**描述:**

设备特性


### propLength


```
uint16_t Hid_Device::propLength
```

**描述:**

设备特性数量
