# IPowerRunningLockCallback


## 概述

表示运行中的锁定状态的回调。

创建回调对象后，电源服务可以调用 [IPowerInterface](interface_i_power_interface.md) 来注册回调，以订阅运行锁状态变化。

**起始版本：** 4.1

**相关模块：**[Power](power-v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [HandleRunningLockMessage](#handlerunninglockmessage) ([in] String message) | 运行锁定状态的回调。 | 


## 成员函数说明


### HandleRunningLockMessage()

```
IPowerRunningLockCallback::HandleRunningLockMessage([in] String message)
```

**描述**

运行锁定状态的回调。

此回调用于在设备进入运行锁状态时通知电源服务。

**起始版本：** 4.1

**废弃版本：** 从4.1版本废弃。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| message | 上报运行锁信息。 | 
