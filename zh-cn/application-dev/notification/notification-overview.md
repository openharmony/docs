# 通知概述


## 通知简介

所有系统服务以及应用都可以通过通知接口发送通知消息，用户可以通过通知栏查看通知内容，也可以点击通知来打开应用。

通知常见的使用场景：

- 显示接收到的短消息、即时消息等。

- 显示应用的推送消息，如广告、版本更新等。

- 显示当前正在进行的事件，如下载等。

通过ANS（Advanced Notification Service，通知系统服务）可以对通知类型的消息进行管理，支持多种通知类型，例如基础类型通知、进度条类型通知、后台代理提醒。


## 通知业务流程

通知业务流程由通知子系统、通知发送端、通知订阅端组成。一条通知从通知发送端产生，通过[IPC通信](../connectivity/ipc-rpc-overview.md)发送到通知子系统，再由通知子系统分发给通知订阅端。

* 通知发送端：可以是三方应用或系统应用。开发者重点关注。

* 通知订阅端：只能为系统应用，比如通知中心。通知中心默认会订阅手机上所有应用对当前用户的通知。开发者无需关注。

**图1** 通知业务流程  
![zh-cn_image_0000001466582017](figures/zh-cn_image_0000001466582017.png)

## 相关实例

基于通知的开发，有以下相关实例可供参考：

- [公共事件的订阅和发布（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/Notification/CustomCommonEvent)

- [自定义通知推送（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/Notification/CustomNotificationPush)

- [自定义通知角标（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/Notification/CustomNotificationBadge)

- [自定义通知（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/Notification/CustomNotification)

- [自定义Emitter（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/Notification/CustomEmitter)