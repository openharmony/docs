# IPowerInterface


## **概述**

休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。

服务获取此对象后，可以调用相关的接口对设备进行休眠/唤醒、订阅休眠/唤醒状态和管理运行锁。

**Since：**

3.1

**相关模块:**

[Power](power.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [RegisterCallback](#registercallback)&nbsp;([in]&nbsp;[IPowerHdiCallback](interface_i_power_hdi_callback.md)&nbsp;ipowerHdiCallback) | 注册休眠/唤醒状态的回调。 | 
| [StartSuspend](#startsuspend)&nbsp;() | 执行设备休眠操作。 | 
| [StopSuspend](#stopsuspend)&nbsp;() | 执行设备唤醒操作。 | 
| [ForceSuspend](#forcesuspend)&nbsp;() | 执行设备强制休眠操作。 | 
| [SuspendBlock](#suspendblock)&nbsp;([in]&nbsp;String&nbsp;name) | 打开运行锁，阻止休眠。 | 
| [SuspendUnblock](#suspendunblock)&nbsp;([in]&nbsp;String&nbsp;name) | 关闭运行锁，取消阻止休眠。 | 
| [PowerDump](#powerdump)&nbsp;([out]&nbsp;String&nbsp;info) | 获取电源的Dump信息。 | 


## **成员函数说明**


### ForceSuspend()

  
```
IPowerInterface::ForceSuspend ()
```

**描述：**

执行设备强制休眠操作。

**返回:**

HDF_SUCCESS 表示操作成功。


### PowerDump()

  
```
IPowerInterface::PowerDump ([out] String info)
```

**描述：**

获取电源的Dump信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| info | 输出参数，电源的Dump信息。 | 

**返回:**

HDF_SUCCESS 表示操作成功。


### RegisterCallback()

  
```
IPowerInterface::RegisterCallback ([in] IPowerHdiCallback ipowerHdiCallback)
```

**描述：**

注册休眠/唤醒状态的回调。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ipowerHdiCallback | 输入参数，服务注册的回调。 | 

**返回:**

HDF_SUCCESS 表示注册成功。

**参见:**

[IPowerHdiCallback](interface_i_power_hdi_callback.md)


### StartSuspend()

  
```
IPowerInterface::StartSuspend ()
```

**描述：**

执行设备休眠操作。

**返回:**

HDF_SUCCESS 表示操作成功。


### StopSuspend()

  
```
IPowerInterface::StopSuspend ()
```

**描述：**

执行设备唤醒操作。

**返回:**

HDF_SUCCESS 表示操作成功。


### SuspendBlock()

  
```
IPowerInterface::SuspendBlock ([in] String name)
```

**描述：**

打开运行锁，阻止休眠。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| name | 输入参数，运行锁的名称。 | 

**返回:**

HDF_SUCCESS 表示操作成功。


### SuspendUnblock()

  
```
IPowerInterface::SuspendUnblock ([in] String name)
```

**描述：**

关闭运行锁，取消阻止休眠。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| name | 输入参数，运行锁的名称。 | 

**返回:**

HDF_SUCCESS 表示操作成功。
