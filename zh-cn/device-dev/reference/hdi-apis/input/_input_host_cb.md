# InputHostCb


## 概述

此结构体定义了热插拔事件上报回调函数并提供给Input服务使用。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| void(\* [HotPlugCallback](#hotplugcallback) )(const [InputHotPlugEvent](_input_hot_plug_event.md) \*event) | 热插拔事件上报的回调函数。  | 


## 类成员变量说明


### HotPlugCallback

```
void(* InputHostCb::HotPlugCallback) (const InputHotPlugEvent *event)
```
**描述**

热插拔事件上报的回调函数。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 输入参数，上报的热插拔事件数据。 | 
