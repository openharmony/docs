# IInputCallback


## 概述

定义Input模块的回调函数。

当设备进行数据上报、插拔等操作时，上层服务可以调用如下回调函数，处理对应的数据信息。

**起始版本：** 3.2

**相关模块：**[HdiInput](_hdi_input.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [EventPkgCallback](#eventpkgcallback) ([in] struct [EventPackage](_event_package_v10.md)[] pkgs, [in] unsigned int devIndex) | 输入事件数据上报的回调函数。  | 
| [HotPlugCallback](#hotplugcallback) ([in] struct [HotPlugEvent](_hot_plug_event_v10.md) event) | 热插拔事件上报的回调函数。  | 


## 成员函数说明


### EventPkgCallback()

```
IInputCallback::EventPkgCallback ([in] struct EventPackage[] pkgs, [in] unsigned int devIndex )
```
**描述**

输入事件数据上报的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pkgs | 驱动上报的Input事件数据，具体参考[EventPackage](_event_package_v10.md)。  | 
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。 | 


### HotPlugCallback()

```
IInputCallback::HotPlugCallback ([in] struct HotPlugEvent event)
```
**描述**

热插拔事件上报的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 上报的热插拔事件数据，具体参考[HotPlugEvent](_hot_plug_event_v10.md)。 | 
