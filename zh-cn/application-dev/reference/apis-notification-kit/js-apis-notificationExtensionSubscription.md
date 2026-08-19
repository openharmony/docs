# @ohos.notificationExtensionSubscription (notificationExtensionSubscription模块)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

本模块提供管理通知扩展的能力，具体包括：打开通知扩展订阅设置界面、订阅和取消订阅通知扩展、获取和设置[通知授权](../../notification/notification-glossary.md#notification-authorization通知授权)状态。

> **说明：**
>
> 本模块首批接口从API version 22开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
## 导入模块

```ts
import { notificationExtensionSubscription } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

## notificationExtensionSubscription.openSubscriptionSettings

openSubscriptionSettings(context: UIAbilityContext): Promise\<void\>

打开应用的通知扩展订阅授权页面，以半模态弹窗形式显示。用户可在该页面授权“允许获取本机通知”开关与“已获取的本机通知”应用开关。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.SUBSCRIBE_NOTIFICATION

**参数：**

| 参数名   | 类型                     | 必填 | 说明                 |
| -------- | ------------------------ | ---- |--------------------|
| context | [UIAbilityContext](../../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是   | [通知设置](../../notification/notification-glossary.md#notification-setting通知设置)页面绑定Ability的上下文。 |

**返回值：**

| 类型     | 说明 | 
| ------- |--|
| Promise\<void\> | Promise对象，无返回结果。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied or current device not supported.     |
| 1600001  | Internal error.                     |
| 1600018  | The notification settings window is already displayed.           |
| 1600023  | The application does not implement the NotificationSubscriberExtensionAbility.           |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

try {
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  notificationExtensionSubscription.openSubscriptionSettings(context).then(() => {
    console.info(`openSubscriptionSettings success`);
  }).catch((e: Error) => {
    let error = e as BusinessError
    console.error(`failed to call openSubscriptionSettings, code is ${error.code}, message is ${error.message}`)
  });
} catch (error) {
  console.error(`failed to call openSubscriptionSettings, code is ${error.code}, message is ${error.message}`)
}
```

## notificationExtensionSubscription.openSubscriptionSettingsWithResult

openSubscriptionSettingsWithResult(context: UIAbilityContext): Promise\<UserGrantSetting\>

打开应用的通知扩展订阅授权页面，以半模态弹窗形式显示。用户可在该页面授权“允许获取本机通知”开关与“已获取的本机通知”应用开关。使用Promise异步回调，当半模态窗口关闭时返回用户设置的授权的结果。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.SUBSCRIBE_NOTIFICATION

**参数：**

| 参数名   | 类型                     | 必填 | 说明                 |
| -------- | ------------------------ | ---- |--------------------|
| context | [UIAbilityContext](../../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是   | [通知设置](../../notification/notification-glossary.md#notification-setting通知设置)页面绑定Ability的上下文。 |

**返回值：**

| 类型     | 说明 | 
| ------- |--|
| Promise\<[UserGrantSetting](#usergrantsetting)\> | Promise对象，返回用户设置的授权的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied or current device not supported.     |
| 1600001  | Internal error.                     |
| 1600018  | The notification settings window is already displayed.           |
| 1600023  | The application does not implement the NotificationSubscriberExtensionAbility.           |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

try {
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  notificationExtensionSubscription.openSubscriptionSettingsWithResult(context).then((data) => {
    console.info(`openSubscriptionSettingsWithResult success, data: ${JSON.stringify(data)}`);
  }).catch((e: Error) => {
    let error = e as BusinessError
    console.error(`failed to call openSubscriptionSettingsWithResult, code is ${error.code}, message is ${error.message}`)
  });
} catch (error) {
  console.error(`failed to call openSubscriptionSettingsWithResult, code is ${error.code}, message is ${error.message}`)
}
```

## notificationExtensionSubscription.subscribe

subscribe(info: NotificationExtensionSubscriptionInfo[]): Promise\<void\>

订阅通知扩展。使用[蓝牙模块](../../connectivity/connectivity-kit-intro.md#蓝牙简介)相关接口获取蓝牙设备的唯一地址后方可订阅。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.SUBSCRIBE_NOTIFICATION

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| info  | [NotificationExtensionSubscriptionInfo[]](js-apis-inner-notificationExtensionSubscriptionInfo.md) | 是   | 订阅的信息列表（数组）。 |

**返回值：**

| 类型     | 说明 | 
| ------- |--|
| Promise\<void\> | Promise对象，无返回结果。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](errorcode-notification.md)。

| 错误码ID | 错误信息                                              |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied or current device not supported. |
| 1600001  | Internal error.                                      |
| 1600003  | Failed to connect to the service.                    |
| 1600023  | The application does not implement the NotificationSubscriberExtensionAbility.           |

**示例：**

```ts

let infos: notificationExtensionSubscription.NotificationExtensionSubscriptionInfo[] = [
  {
    addr: '01:23:45:67:89:AB', // 使用动态获取的蓝牙地址
    type: notificationExtensionSubscription.SubscribeType.BLUETOOTH
  }
];
notificationExtensionSubscription.subscribe(infos).then(() => {
  console.info(`subscribe success`);
}).catch((err: BusinessError) => {
  console.error(`subscribe fail, code is ${err.code}, message is ${err.message}`);
});

```

## notificationExtensionSubscription.unsubscribe

unsubscribe(): Promise\<void\>

取消通知扩展的订阅。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.SUBSCRIBE_NOTIFICATION

**返回值：**

| 类型     | 说明 | 
| ------- |--|
| Promise\<void\> | Promise对象，无返回结果。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied or current device not supported. |
| 1600001  | Internal error.                     |
| 1600003  | Failed to connect to the service. |

**示例：**

```ts

notificationExtensionSubscription.unsubscribe().then(() => {
  console.info(`unsubscribe success`);
}).catch((err: BusinessError) => {
  console.error(`unsubscribe fail, code is ${err.code}, message is ${err.message}`);
});
```

## notificationExtensionSubscription.getSubscribeInfo

getSubscribeInfo(): Promise\<NotificationExtensionSubscriptionInfo[]\>

获取当前应用的通知扩展订阅信息。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.SUBSCRIBE_NOTIFICATION

**返回值：**

| 类型     | 说明        | 
| ------- |-----------|
| Promise\<[NotificationExtensionSubscriptionInfo[]](js-apis-inner-notificationExtensionSubscriptionInfo.md)\> | Promise对象，返回一个[NotificationExtensionSubscriptionInfo[]](js-apis-inner-notificationExtensionSubscriptionInfo.md)对象数组，表示应用的订阅信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied or current device not supported. |
| 1600001  | Internal error.                     |
| 1600003  | Failed to connect to the service. |

**示例：**

```ts

notificationExtensionSubscription.getSubscribeInfo().then((data: notificationExtensionSubscription.NotificationExtensionSubscriptionInfo[]) => {
  console.info(`getSubscribeInfo successfully. Data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getSubscribeInfo fail, code is ${err.code}, message is ${err.message}`);
});
```

## notificationExtensionSubscription.isUserGranted

isUserGranted(): Promise\<boolean\>

查询“允许获取本机通知”的开关状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.SUBSCRIBE_NOTIFICATION

**返回值：**

| 类型     | 说明        | 
| ------- |-----------|
| Promise\<boolean\> | Promise对象。返回true表示功能已启用；返回false表示功能未启用。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](errorcode-notification.md)。

| 错误码ID | 错误信息                                              |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied or current device not supported. |
| 1600001  | Internal error.                                      |
| 1600003  | Failed to connect to the service.                           |

**示例：**

```ts

notificationExtensionSubscription.isUserGranted().then((isOpen: boolean) => {
  if (isOpen) {
    console.info('isUserGranted true');
  } else {
    console.info('isUserGranted false');
  }
}).catch((err: BusinessError) => {
  console.error(`isUserGranted fail, code is ${err.code}, message is ${err.message}`);
});
```

## notificationExtensionSubscription.getUserGrantedEnabledBundles

getUserGrantedEnabledBundles(): Promise\<GrantedBundleInfo[]\>

获取本应用中“已获取的本机通知”通知开关开启的应用列表。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.SUBSCRIBE_NOTIFICATION

**返回值：**

| 类型     | 说明        |
| ------- |-----------|
| Promise\<[GrantedBundleInfo](js-apis-inner-notification-notificationCommonDef.md#grantedbundleinfo22)[]\>   | Promise对象，返回本应用中“已获取的本机通知”通知开关开启的应用列表。        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied or current device not supported.     |
| 1600001  | Internal error.                     |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts

notificationExtensionSubscription.getUserGrantedEnabledBundles().then((data: notificationExtensionSubscription.GrantedBundleInfo[]) => {
  console.info(`getUserGrantedEnabledBundles successfully. Data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getUserGrantedEnabledBundles fail, code is ${err.code}, message is ${err.message}`);
});
```

## NotificationExtensionSubscriptionInfo

type NotificationExtensionSubscriptionInfo = _NotificationExtensionSubscriptionInfo

用于描述通知扩展订阅的信息。

**系统能力**：SystemCapability.Notification.Notification

| 类型 | 说明 |
| --- | --- |
| [_NotificationExtensionSubscriptionInfo](js-apis-inner-notificationExtensionSubscriptionInfo.md) | 用于描述通知扩展订阅的信息。 |

## NotificationInfo

type NotificationInfo = _NotificationInfo

[通知订阅](../../notification/notification-glossary.md#notification-subscription通知订阅)扩展能力中[onReceiveMessage](js-apis-notificationSubscriberExtensionAbility.md#onreceivemessage)回调的通知信息。

**系统能力**：SystemCapability.Notification.Notification

| 类型 | 说明 |
| --- | --- |
| [_NotificationInfo](js-apis-inner-notification-notificationInfo.md) |通知订阅扩展能力中[onReceiveMessage](js-apis-notificationSubscriberExtensionAbility.md#onreceivemessage)回调的通知信息。|

## SubscribeType

表示通知扩展订阅的类型。

**系统能力**：SystemCapability.Notification.Notification

| 名称                 | 值       | 说明       |
| -------------------- | -------- | ---------- |
| BLUETOOTH          | 0 | 通过蓝牙订阅通知。 |

## BundleOption

type BundleOption = _BundleOption

指定应用的包信息。

**系统能力**：SystemCapability.Notification.Notification

| 类型 | 说明 |
| --- | --- |
| [_BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 指定应用的包信息。 |

## GrantedBundleInfo

type GrantedBundleInfo = _GrantedBundleInfo

授权应用的包信息。

**系统能力**：SystemCapability.Notification.Notification

| 类型 | 说明 |
| --- | --- |
| [_GrantedBundleInfo](js-apis-inner-notification-notificationCommonDef.md#grantedbundleinfo22) | 授权应用的包信息。 |

## UserGrantSetting

type UserGrantSetting = _UserGrantSetting

用户授权的设置信息。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Notification.Notification

| 类型 | 说明 |
| --- | --- |
| [_UserGrantSetting](js-apis-inner-notification-notificationCommonDef.md#usergrantsetting) | 用户授权的设置信息。 |
