# Notification Kit简介

Notification Kit（用户通知服务）为开发者提供在本地即时发布用户通知的能力，本地通知可出现在通知中心、横幅、锁屏、熄屏显示等系统入口，帮助开发者实现在应用界面外与用户完成交互。

## 使用场景

本地通知常见的使用场景：

- 显示接收到的即时消息、短消息等。
- 显示当前正在进行的事件，如下载等。

## 框架原理

通知业务流程由通知子系统、通知发送端、通知订阅端组成。一条通知从通知发送端产生，通过[IPC通信](../connectivity/ipc-rpc-overview.md)发送到通知子系统，再由通知子系统分发给通知订阅端。

* 通知发送端：可以是三方应用或系统应用。开发者重点关注。

* 通知订阅端：只能为系统应用，比如通知中心。通知中心默认会订阅手机上所有应用对当前用户的通知。开发者无需关注。

**图1** 通知业务流程  

![zh-cn_image_0000001466582017](figures/zh-cn_image_0000001466582017.png)


## 能力范围

- 支持应用发布不同基础类型通知。
- 支持应用在发布通知时指定不同的通知渠道类型。并且管理通知发布渠道类型，比如新增或删除渠道、查询渠道使能状态等。
- 支持应用管理自己发布的通知，比如取消已发布的通知、查询所有已发布通知等操作。
- 支持应用请求通知授权、查询通知授权状态。
- 支持应用管理通知角标。
- 支持应用设置用户点击通知后的行为意图，包括跳转到应用的UIAbility或者发布自定义公共事件。


## 与相关Kit的关系

- Notification Kit创建的通知会即时显示在通知中心等系统入口，如果开发者希望在应用退到后台或进程终止后仍然有一些提醒用户的定时类通知，例如购物类应用抢购提醒等，可通过`BackGroundTask Kit`创建，目前支持基于倒计时、日历、闹钟等类型的通知提醒功能。
- 开发者可通过`Push Kit`远程推送用户通知到本地。
- 开发者可通过`Ability Kit`设置用户点击通知后的行为意图。


## 约束限制

- 单个应用已发布的通知在通知中心等系统入口的留存数量有限（当前规格最多24条）。
- 基础类型通知的长度不能超过200KB（跨进程序列化大小限制）。
- 系统所有应用发布新通知的频次累计不能超过每秒10条。


## 相关实例

基于通知的开发，有以下相关实例可供参考：

- [公共事件的订阅和发布（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomCommonEvent)

- [自定义通知推送（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotificationPush)

- [自定义通知角标（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotificationBadge)

- [自定义通知（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotification)

- [自定义Emitter（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomEmitter)