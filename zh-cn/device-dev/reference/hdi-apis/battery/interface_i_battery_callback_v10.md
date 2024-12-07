# IBatteryCallback


## 概述

电池信息的回调。

服务创建此回调对象后，可以调用[IBatteryInterface](interface_i_battery_interface_v10.md)的接口注册回调，从而订阅电池信息的变化。

**起始版本：** 3.1

**相关模块：**[Battery](battery_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Update](#update) ([in] struct [BatteryInfo](_battery_info_v10.md) event) | 电池信息的回调方法。 | 


## 成员函数说明


### Update()

```
IBatteryCallback::Update ([in] struct BatteryInfo event)
```

**描述**

电池信息的回调方法。

当电池信息发生变化时，将通过此方法的参数返回给服务。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 电池信息，如电量，电压，健康状态等。 | 

**参见：**

[BatteryInfo](_battery_info_v10.md)
