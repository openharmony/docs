# InputReportEventCb


## **概述**

**所属模块:**

[Input](_input.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| (&nbsp;[ReportEventPkgCallback](#reporteventpkgcallback)&nbsp;)(const&nbsp;[InputEventPackage](_event_package.md)&nbsp;\*\*pkgs,&nbsp;uint32_t&nbsp;count,&nbsp;uint32_t&nbsp;devIndex) | 输入事件数据上报的回调函数。&nbsp;[更多...](#reporteventpkgcallback) | 
| (&nbsp;[ReportHotPlugEventCallback](#reporthotplugeventcallback)&nbsp;)(const&nbsp;HotPlugEvent&nbsp;\*event) | 热插拔事件上报的回调函数。&nbsp;[更多...](#reporthotplugeventcallback) | 


## **详细描述**

此结构体定义了输入事件回调函数并提供给Input服务使用。


## **类成员变量说明**


### ReportEventPkgCallback

  
```
void(* InputReportEventCb::ReportEventPkgCallback) (const InputEventPackage **pkgs, uint32_t count, uint32_t devIndex)
```

**描述：**

输入事件数据上报的回调函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| eventData | 驱动上报的Input事件数据。 | 
| count | Input事件数据包的个数。 | 
| devIndex | Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 


### ReportHotPlugEventCallback

  
```
void(* InputReportEventCb::ReportHotPlugEventCallback) (const HotPlugEvent *event)
```

**描述：**

热插拔事件上报的回调函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| event | 上报的热插拔事件数据 | 
