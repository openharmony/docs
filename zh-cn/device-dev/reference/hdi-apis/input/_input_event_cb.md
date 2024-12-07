# InputEventCb


## 概述

此结构体定义了输入事件回调函数并提供给Input服务使用。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| void(\* [EventPkgCallback](#eventpkgcallback) )(const [InputEventPackage](_input_event_package.md) \*\*pkgs, uint32_t count, uint32_t devIndex) | 输入事件数据上报的回调函数。  | 


## 类成员变量说明


### EventPkgCallback

```
void(* InputEventCb::EventPkgCallback) (const InputEventPackage **pkgs, uint32_t count, uint32_t devIndex)
```
**描述**

输入事件数据上报的回调函数。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| eventData | 输入参数，驱动上报的Input事件数据。  | 
| count | 输入参数，Input事件数据包的个数。  | 
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
