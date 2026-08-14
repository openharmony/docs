# Common Event Service术语
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

## C

### Common Event Service (CES)；公共事件服务

系统中提供跨进程事件通信能力的通知子系统服务。基于“发布—订阅”模型，负责根据事件名称将发布者发布的事件投递给已订阅的订阅者，实现应用之间、应用与系统之间的解耦通信。

## O

### Ordered Common Event；有序公共事件

按订阅者优先级依次投递的公共事件。订阅者可在回调中设置传递给后续订阅者的结果码与结果数据，或中止事件向后续订阅者的投递；每次回调处理完成后必须调用结束接口，事件才能继续向下一订阅者传递。

## S

### Static Subscription；静态订阅

应用通过配置声明的公共事件订阅方式，可按需设置其使能或去使能状态，用于控制是否接收所订阅的公共事件。

### Sticky Common Event；粘性公共事件

发布后会被持久存储的公共事件，新订阅者在订阅后仍能收到该事件，适用于需要让后加入的订阅者获取历史事件的场景，仅系统应用或系统服务可发布。

### System Common Event；系统公共事件

由系统预定义并以固定名称常量提供的公共事件（如电量变化、屏幕亮灭、Wi-Fi 状态、USB 状态等）。供应用订阅以感知系统状态变化，无需应用自行定义事件名称。

## U

### Unordered Common Event；无序公共事件

同时投递给所有已订阅订阅者的公共事件。不涉及投递顺序与订阅者优先级，适用于无需按序处理的事件广播场景。