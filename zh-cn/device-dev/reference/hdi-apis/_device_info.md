# DeviceInfo


## **概述**

**所属模块:**

[Input](_input.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [devIndex](#devindex) | 设备索引 | 
| [fd](#fd) | 设备对应的文件描述符 | 
| [service](#service) | 设备对应的服务 | 
| [listener](#listener) | 设备对应的事件监听器 | 
| [devType](#devtype) | 设备类型 | 
| [powerStatus](#powerstatus) | 电源状态 | 
| [chipInfo](#chipinfo)&nbsp;[CHIP_INFO_LEN] | 驱动芯片编码信息 | 
| [vendorName](#vendorname)&nbsp;[VENDOR_NAME_LEN] | 模组厂商名 | 
| [chipName](#chipname)&nbsp;[CHIP_NAME_LEN] | 驱动芯片型号 | 
| [devNodePath](#devnodepath)&nbsp;[MAX_NODE_PATH_LEN] | 设备文件路径 | 
| [solutionX](#solutionx) | x方向分辨率 | 
| [solutionY](#solutiony) | y方向分辨率 | 
| [callback](#callback) | 数据上报回调函数&nbsp;[InputReportEventCb](_input_report_event_cb.md) | 


## **详细描述**

input设备基础设备信息


## **类成员变量说明**


### callback

  
```
InputReportEventCb* DeviceInfo::callback
```

**描述：**

数据上报回调函数 [InputReportEventCb](_input_report_event_cb.md)


### chipInfo

  
```
char DeviceInfo::chipInfo[CHIP_INFO_LEN]
```

**描述：**

驱动芯片编码信息


### chipName

  
```
char DeviceInfo::chipName[CHIP_NAME_LEN]
```

**描述：**

驱动芯片型号


### devIndex

  
```
uint32_t DeviceInfo::devIndex
```

**描述：**

设备索引


### devNodePath

  
```
char DeviceInfo::devNodePath[MAX_NODE_PATH_LEN]
```

**描述：**

设备文件路径


### devType

  
```
uint32_t DeviceInfo::devType
```

**描述：**

设备类型


### fd

  
```
int32_t DeviceInfo::fd
```

**描述：**

设备对应的文件描述符


### listener

  
```
void* DeviceInfo::listener
```

**描述：**

设备对应的事件监听器


### powerStatus

  
```
uint32_t DeviceInfo::powerStatus
```

**描述：**

电源状态


### service

  
```
void* DeviceInfo::service
```

**描述：**

设备对应的服务


### solutionX

  
```
uint32_t DeviceInfo::solutionX
```

**描述：**

x方向分辨率


### solutionY

  
```
uint32_t DeviceInfo::solutionY
```

**描述：**

y方向分辨率


### vendorName

  
```
char DeviceInfo::vendorName[VENDOR_NAME_LEN]
```

**描述：**

模组厂商名
