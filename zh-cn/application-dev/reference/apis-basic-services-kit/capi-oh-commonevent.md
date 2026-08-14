# OH_CommonEvent
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

## 概述

本模块是[公共事件服务](../../basic-services/common-event/common-event-glossary.md#common-event-service-ces公共事件服务)（Common Event Service）对外开放的 C 语言 API 模块，为应用提供基于"发布—订阅"模型的跨进程事件通信能力：发布者发布一个公共事件后，系统根据事件名称将事件投递给所有已订阅该事件的订阅者，从而实现应用之间、应用与系统之间的解耦通信。

主要提供以下能力：

- **事件订阅与取消订阅**：创建订阅信息、创建订阅者、订阅/取消订阅指定公共事件，并在事件到达时通过回调接收事件数据。
- **事件发布**：发布公共事件，支持设置有序/无序、权限、应用包名称、code数据、data数据及附加信息等发布属性。
- **事件数据访问**：从回调数据中获取事件名、结果码、结果数据、发布者应用包名称及附加信息（Parameters，KV 键值对，支持 int/long/bool/char/double 及其数组类型的读写）。
- **[有序公共事件](../../basic-services/common-event/common-event-glossary.md#ordered-common-event有序公共事件)控制**：对有序公共事件进行终止、清除终止状态、获取/设置结果码与结果数据、完成事件等控制。
- **[系统公共事件](../../basic-services/common-event/common-event-glossary.md#system-common-event系统公共事件)常量**：提供系统已定义的公共事件名称常量（如电量变化、屏幕亮灭、Wi-Fi 状态、USB 状态等），便于订阅系统状态变化。
- **错误码**：统一枚举操作过程中可能返回的错误码。

**适用场景**：当应用需要感知系统状态变化（如电量、屏幕、网络、Wi-Fi、USB、包安装等）或需要在多应用间广播业务消息时，可使用本模块订阅或发布公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**起始版本：** 12

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [oh_commonevent.h](capi-oh-commonevent-h.md) | 提供订阅、取消订阅、发布、事件数据访问、附加信息读写、有序事件控制等全部操作函数，以及错误码枚举与核心数据类型定义。 |
| [oh_commonevent_support.h](capi-oh-commonevent-support-h.md) | 提供系统预定义的公共事件名称常量（如 `COMMON_EVENT_BATTERY_CHANGED`、`COMMON_EVENT_SCREEN_ON` 等），供订阅时引用，本身不提供函数。 |
