# Notification Kit简介

(产品输出相关介绍)
图片（通知的UI图，锁屏界面以及通知中心）

## 使用场景

本地通知常见的使用场景：

- 显示接收到的即时消息、短消息等。
- 显示当前正在进行的事件，如下载等。


## 能力范围

- 支持应用发布不同基础类型通知。
- 支持应用在发布通知时指定不同的通知渠道类型，以及管理通知发布渠道类型，比如新增或删除渠道、查询渠道使能状态等。
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