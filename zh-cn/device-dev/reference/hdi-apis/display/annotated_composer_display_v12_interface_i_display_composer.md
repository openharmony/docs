# IDisplayComposer


## 概述

显示合成接口声明。

主要提供注册热插拔事件回调、获取显示设备能力集等功能，在v1_1.IDisplayComposer基础上新增注册更改VBlankIdle事件回调、清除缓冲区、硬光标特性等功能，具体方法使用详见函数说明。

**起始版本：** 5.0

**相关模块：**[Display](index_composer_display_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegDisplayVBlankIdleCallback](#regdisplayvblankidlecallback) ([in] [IVBlankIdleCallback](annotated_composer_display_v12_interface_i_v_blank_idle_callback.md) cb) | 注册更改VBlankIdle时调用的回调。 | 
| [ClearClientBuffer](#clearclientbuffer) ([in] unsigned int devId) | 表示清除所有客户端缓冲区。 | 
| [ClearLayerBuffer](#clearlayerbuffer) ([in] unsigned int devId, [in] unsigned int layerId) | 表示清除所有图层缓冲区。 | 
| [SetHardwareCursorPosition](#sethardwarecursorposition) ([in] unsigned int devId, [in] int x, [in] int y) | 设置硬光标位置。 | 
| [EnableHardwareCursorStats](#enablehardwarecursorstats) ([in] unsigned int devId, [in] boolean enable) | 启用硬光标。 | 
| [GetHardwareCursorStats](#gethardwarecursorstats) ([in] unsigned int devId, [out] unsigned int frameCount, [out] unsigned int vsyncCount) | 获取硬光标状态。 | 
| [SetDisplayActiveRegion](#setdisplayactiveregion) ([in] unsigned int devId, [in] struct IRect rect) | 设置显示活动区域。 | 
| [FastPresent](#fastpresent) ([in] unsigned int devId, [in] struct [PresentParam](annotated_composer_display_v12_present_param.md) param, [in] NativeBuffer[] inHandles) | 根据设备ID、显示参数以及缓冲区句柄快速显示。 | 


## 成员函数说明


### ClearClientBuffer()

```
IDisplayComposer::ClearClientBuffer([in] unsigned int devId)
```

**描述**

表示清除所有客户端缓冲区。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示设备ID。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### ClearLayerBuffer()

```
IDisplayComposer::ClearLayerBuffer([in] unsigned int devId, [in] unsigned int layerId)
```

**描述**

表示清除所有图层缓冲区。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示设备ID。 | 
| layerId | 表示图层ID。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### EnableHardwareCursorStats()

```
IDisplayComposer::EnableHardwareCursorStats([in] unsigned int devId, [in] boolean enable)
```

**描述**

启用硬光标。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示设备ID。 | 
| enable | 表示是否启用硬光标。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### FastPresent()

```
IDisplayComposer::FastPresent([in] unsigned int devId, [in] struct PresentParam param, [in] NativeBuffer[] inHandles)
```

**描述**

根据设备ID、显示参数以及缓冲区句柄快速显示。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示设备ID。 | 
| param | 表示当前参数的数据结构。 | 
| inHandles | 表示输入缓冲区句柄。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetHardwareCursorStats()

```
IDisplayComposer::GetHardwareCursorStats([in] unsigned int devId, [out] unsigned int frameCount, [out] unsigned int vsyncCount)
```

**描述**

获取硬光标状态。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示设备ID。 | 
| frameCount | 表示硬光标帧数。 | 
| vsyncCount | 表示硬光标同步计数。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### RegDisplayVBlankIdleCallback()

```
IDisplayComposer::RegDisplayVBlankIdleCallback([in] IVBlankIdleCallback cb)
```

**描述**

注册更改VBlankIdle时调用的回调。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cb | 表示用于通知图形服务已准备好更改 VBlankIdle 的实例。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayActiveRegion()

```
IDisplayComposer::SetDisplayActiveRegion([in] unsigned int devId, [in] struct IRect rect)
```

**描述**

设置显示活动区域。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示设备ID。 | 
| rect | 表示指向客户端缓冲区裁剪区域的指针。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetHardwareCursorPosition()

```
IDisplayComposer::SetHardwareCursorPosition([in] unsigned int devId, [in] int x, [in] int y)
```

**描述**

设置硬光标位置。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示设备ID。 | 
| x | 表示硬光标的横坐标。 | 
| y | 表示硬光标的纵坐标。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
