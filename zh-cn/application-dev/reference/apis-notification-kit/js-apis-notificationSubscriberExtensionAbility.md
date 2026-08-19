# @ohos.application.NotificationSubscriberExtensionAbility (通知订阅扩展能力)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

NotificationSubscriberExtensionAbility是[通知订阅](../../notification/notification-glossary.md#notification-subscription通知订阅)者扩展能力的基类，提供通知订阅的相关功能。三方穿戴类应用（如手表配套应用）通过继承此类实现回调逻辑，在本机发布通知时接收通知信息并通过蓝牙转发给穿戴设备，在本机通知被取消时接收取消通知的回调并转发给穿戴设备删除对应通知。

当穿戴类应用需要获取本机通知并同步到配对的穿戴设备时，使用本模块。本模块与notificationExtensionSubscription模块配合使用，本模块负责在回调中接收和处理通知数据，notificationExtensionSubscription模块负责授权、订阅和取消订阅等管理操作。

> **说明：**
>
> 本模块首批接口从API version 22开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { notificationExtensionSubscription, NotificationSubscriberExtensionAbility } from '@kit.NotificationKit';
```

## NotificationSubscriberExtensionAbility

**系统能力**：SystemCapability.Notification.Notification


| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [NotificationSubscriberExtensionContext](js-apis-notificationSubscriberExtensionContext.md)  | 否 | 否 | NotificationSubscriberExtensionAbility的上下文环境。|


### onDestroy

onDestroy(): void

[通知订阅](../../notification/notification-glossary.md#notification-subscription通知订阅)扩展被销毁时的回调。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```ts
const TAG = 'NotificationSubscriberExtAbility';

export default class NotificationSubscriberExtAbility extends NotificationSubscriberExtensionAbility {
  onDestroy(): void {
    console.info(`${TAG} onDestroy`);
  }
}
```

### onReceiveMessage

onReceiveMessage(notificationInfo: NotificationInfo): void

收到通知时回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| notificationInfo |  [NotificationInfo](../apis-notification-kit/js-apis-inner-notification-notificationInfo.md) | 是 | 通知订阅扩展能力中收到通知的回调信息。|

**示例：**

```ts
const TAG = 'NotificationSubscriberExtAbility';

export default class NotificationSubscriberExtAbility extends NotificationSubscriberExtensionAbility {
  onReceiveMessage(notificationInfo: notificationExtensionSubscription.NotificationInfo): void {
    console.info(`${TAG} onReceiveMessage. notificationInfo: ${JSON.stringify(notificationInfo)}`);
  }
}
```

### onCancelMessages

onCancelMessages(hashCodes: Array\<string>): void

取消通知时的回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| hashCodes |  Array\<string\>| 是 | 要取消的通知的哈希码列表。通过[onReceiveMessage](#onreceivemessage)获取。|

**示例：**

```ts
const TAG = 'NotificationSubscriberExtAbility';

export default class NotificationSubscriberExtAbility extends NotificationSubscriberExtensionAbility {
  onCancelMessages(hashCodes: Array<string>): void {
    console.info(`${TAG} onCancelMessages. hashCodes: ${JSON.stringify(hashCodes)}`);
  }
}
```