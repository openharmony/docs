# IBatteryCallback


## 概述

表示电池信息的回调。

创建回调对象后，电池服务可调用 [IBatteryInterface](interface_i_battery_interface_v11.md) 接口注册回调，订阅电池信息变更。

**起始版本：** 3.1

**相关模块：**[Battery](battery_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Update](#update) ([in] struct [BatteryInfo](_battery_info_v11.md) event) | 电池更改信息回调。 | 


## 成员函数说明


### Update()

```
IBatteryCallback::Update ([in] struct BatteryInfo event)
```

**描述**

电池更改信息回调。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 输入参数，电池信息，如电池电量、电压和健康状态。 | 

**参见：**

[BatteryInfo](_battery_info_v11.md)
