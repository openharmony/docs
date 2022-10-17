# HdfNetDeviceInfo


## **概述**

网络设备信息。

**相关模块:**

[WLAN](wlan.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [index](#index) | 网络设备索引。 | 
| [ifName](#ifname) | 网卡名称。 | 
| [ifNameLen](#ifnamelen) | 网卡名称长度。 | 
| [iftype](#iftype) | 网卡类型。 | 
| [mac](#mac) | 网络设备MAC地址。 | 


## **类成员变量说明**


### ifName

  
```
String HdfNetDeviceInfo::ifName
```

**描述：**

网卡名称。


### ifNameLen

  
```
unsigned int HdfNetDeviceInfo::ifNameLen
```

**描述：**

网卡名称长度。


### iftype

  
```
unsigned char HdfNetDeviceInfo::iftype
```

**描述：**

网卡类型。


### index

  
```
unsigned int HdfNetDeviceInfo::index
```

**描述：**

网络设备索引。


### mac

  
```
unsigned char [] HdfNetDeviceInfo::mac
```

**描述：**

网络设备MAC地址。
