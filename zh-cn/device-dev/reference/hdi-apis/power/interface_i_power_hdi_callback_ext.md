# IPowerHdiCallbackExt


## 概述

带标记的休眠/唤醒状态的回调。

服务创建此回调对象后，可以调用[IPowerInterface](interface_i_power_interface.md)的接口注册回调，从而订阅带标记的休眠/唤醒状态的变化。

这个回调必须通过调用[IPowerInterface](interface_i_power_interface.md)的RegisterPowerCallbackExt接口与UnRegisterPowerCallbackExt接口进行注册回调与注销回调。

**起始版本：** 6.0

**相关模块：**[Power](power-v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnSuspendWithTag](#onsuspendwithtag) ([in] String tag) | 带标记的休眠状态的回调方法。当设备进入带标记的休眠状态时，将通过此方法通知给电源服务；这个接口是对老版本接口OnSuspend的功能增强。 | 
| [OnWakeupWithTag](#onwakeupwithtag) ([in] String tag) | 带标记的唤醒状态的回调方法。当设备进入带标记的唤醒状态时，将通过此方法通知给电源服务；这个接口是对老版本接口OnWakeup的功能增强。 | 


## 成员函数说明


### OnSuspendWithTag()

```
IPowerHdiCallbackExt::OnSuspendWithTag([in] String tag)
```

**描述**

带标记的休眠状态的回调方法。

当设备进入带标记的休眠状态时，将通过此方法通知给电源服务；这个接口是对老版本接口OnSuspend的功能增强。

**起始版本：** 6.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tag | 休眠标记。 | 


### OnWakeupWithTag()

```
IPowerHdiCallbackExt::OnWakeupWithTag ([in] String tag)
```

**描述**

带标记的唤醒状态的回调方法。

当设备进入带标记的唤醒状态时，将通过此方法通知给电源服务；这个接口是对老版本接口OnWakeup的功能增强。

**起始版本：** 6.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tag | 唤醒标记。 | 
