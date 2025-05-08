# UsbPortStatus


## 概述

USB设备端口状态参数

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int [currentMode](#currentmode) | 当前模式。 | 
| int [currentPowerRole](#currentpowerrole) | 当前供电角色。 | 
| int [currentDataRole](#currentdatarole) | 当前角色数据。 | 


## 结构体成员变量说明


### currentDataRole

```
int UsbPortStatus::currentDataRole
```

**描述**

当前角色数据。


### currentMode

```
int UsbPortStatus::currentMode
```

**描述**

当前模式。


### currentPowerRole

```
int UsbPortStatus::currentPowerRole
```

**描述**

当前供电角色。
