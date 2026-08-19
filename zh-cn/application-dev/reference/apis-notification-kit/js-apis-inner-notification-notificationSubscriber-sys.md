# NotificationSubscriber (系统接口)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

作为订阅通知接口[subscribeNotification](js-apis-notificationSubscribe-sys.md#notificationsubscribesubscribenotification)的入参，提供订阅者接收到新通知、取消通知等的回调方法。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```js
import { notificationSubscribe } from '@kit.NotificationKit';
```

## NotificationSubscriber

提供订阅者接收到新通知、取消通知等的回调方法。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

### onConsume

onConsume?: (data: SubscribeCallbackData) => void

接收到新通知的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| onConsume | (data: [SubscribeCallbackData](#subscribecallbackdata)) => void | 否 | 新接收到的通知信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onConsumeCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
  console.info('===> onConsume in test');
  let req = data.request;
  console.info('===> onConsume callback req.id:' + req.id);
};

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onCancel

onCancel?: (data: SubscribeCallbackData) => void

取消通知的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| onCancel | (data: [SubscribeCallbackData](#subscribecallbackdata)) => void | 否 | 需要取消的通知信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onCancelCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
  console.info('===> onCancel in test');
  let req = data.request;
  console.info('===> onCancel callback req.id:' + req.id);
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onCancel: onCancelCallback
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onUpdate

onUpdate?: (data: NotificationSortingMap) => void

更新[通知排序](../../notification/notification-glossary.md#notification-sorting通知排序)的回调函数。预留能力，暂未支持。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| onUpdate | (data: [NotificationSortingMap](js-apis-inner-notification-notificationSortingMap-sys.md)) => void | 否 | 最新的通知排序列表。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onUpdate: (map) => {
    console.info(`===> onUpdateCallback map: ${JSON.stringify(map)}`);
  }
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onConnect

onConnect?: () => void

订阅完成的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| onConnect | () => void | 否 | 订阅完成的回调。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectCallback = () => {
  console.info('===> onConnect in test');
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onConnect: onConnectCallback
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onDisconnect

onDisconnect?: () => void

取消订阅的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| onDisconnect | () => void | 否 | 取消订阅的回调。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let unsubscribeCallback = (err: BusinessError) => {
  if (err) {
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info('unsubscribeCallback');
  }
};

let onConnectCallback = () => {
  console.info('===> onConnect in test');
}
let onDisconnectCallback = () => {
  console.info('===> onDisconnect in test');
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onConnect: onConnectCallback,
  onDisconnect: onDisconnectCallback
};

// 订阅通知后会收到onConnect回调
notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
// 取消订阅后会收到onDisconnect回调
notificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
```

### onDestroy

onDestroy?: () => void

服务失联回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| onDestroy | () => void | 否 | 服务失联的回调。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onDestroyCallback = () => {
  console.info('===> onDestroy in test');
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onDestroy: onDestroyCallback
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onDoNotDisturbDateChange<sup>(deprecated)</sup>

onDoNotDisturbDateChange?: (mode: notification.DoNotDisturbDate) => void

免打扰时间选项发生变更时的回调函数。

> **说明：**
>
> 此接口从API version 8开始支持，从API version 11开始不再维护，建议使用[onDoNotDisturbChanged](js-apis-inner-notification-notificationSubscriber-sys.md#ondonotdisturbchanged11)代替。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| onDoNotDisturbDateChange | (mode: notification.[DoNotDisturbDate](js-apis-notification-sys.md#donotdisturbdate8)) => void | 否 | 回调返回免打扰时间选项变更。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import Notification from '@ohos.notification';

let subscribeCallback = (err: BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info('subscribeCallback');
  }
};

let onDoNotDisturbDateChangeCallback = (mode: Notification.DoNotDisturbDate) => {
  console.info('===> onDoNotDisturbDateChange:' + mode);
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onDoNotDisturbDateChange: onDoNotDisturbDateChangeCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbChanged<sup>11+</sup>

onDoNotDisturbChanged?: (mode: notificationManager.DoNotDisturbDate) => void

免打扰时间选项发生变更时的回调函数。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| onDoNotDisturbChanged | (mode: notificationManager.[DoNotDisturbDate](js-apis-notificationManager-sys.md#donotdisturbdate)) => void | 否 | 回调返回免打扰时间选项变更。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { notificationSubscribe, notificationManager } from '@kit.NotificationKit';

let onDoNotDisturbChangedCallback = (mode: notificationManager.DoNotDisturbDate) => {
  console.info(`===> onDoNotDisturbChanged: ${JSON.stringify(mode)}`);
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onDoNotDisturbChanged: onDoNotDisturbChangedCallback
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onEnabledNotificationChanged<sup>8+</sup>

onEnabledNotificationChanged?: (callbackData: EnabledNotificationCallbackData) => void

监听应用通知使能变化。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                                                                                                           | 必填 | 说明 |
| ------------ |--------------------------------------------------------------------------------------------------------------| ---- | -------------------------- |
| onEnabledNotificationChanged | (callbackData: [EnabledNotificationCallbackData](#enablednotificationcallbackdata8)) => void | 否 | 回调返回监听到的应用信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onEnabledNotificationChangedCallback = (callbackData: notificationSubscribe.EnabledNotificationCallbackData) => {
  console.info('bundle: ', callbackData.bundle);
  console.info('uid: ', callbackData.uid);
  console.info('enable: ', callbackData.enable);
};

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onBadgeChanged<sup>10+</sup>

onBadgeChanged?: (data: BadgeNumberCallbackData) => void

监听应用角标数量变化。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| onBadgeChanged | (data: [BadgeNumberCallbackData](#badgenumbercallbackdata10)) => void | 否   | 回调返回监听到的应用角标数量变化。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onBadgeChanged: (data) => {
    console.info('bundle: ', data.bundle);
    console.info('uid: ', data.uid);
    console.info('badgeNumber: ', data.badgeNumber);
  }
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onBatchCancel<sup>11+</sup>

onBatchCancel?: (data: Array<SubscribeCallbackData\>) => void

批量删除的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| onBatchCancel | (data: Array<[SubscribeCallbackData](#subscribecallbackdata)>) => void | 否   | 批量删除的通知信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onBatchCancelCallBack = (data: Array<notificationSubscribe.SubscribeCallbackData>) => {
  console.info('===> onBatchCancel in test');
  let req = data[0].request;
  console.info('===> onBatchCancel callback req.id:' + req.id);
};

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onBatchCancel: onBatchCancelCallBack
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onEnabledPriorityChanged<sup>23+</sup>

onEnabledPriorityChanged?: (callbackData: EnabledPriorityNotificationCallbackData) => void

通知优先级总开关状态变化的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| onEnabledPriorityChanged | (callbackData: [EnabledPriorityNotificationCallbackData](#enabledprioritynotificationcallbackdata23)>) => void | 否   | 返回通知优先级总开关状态。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onEnabledPriorityChanged: (callbackData: notificationSubscribe.EnabledPriorityNotificationCallbackData) => {
    console.info(`onEnabledPriorityChanged: ${JSON.stringify(callbackData)}`);
  }
};
notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### onEnabledPriorityByBundleChanged<sup>23+</sup>

onEnabledPriorityByBundleChanged?: (callbackData: EnabledPriorityNotificationByBundleCallbackData) => void

应用通知优先级开关状态变化的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| onEnabledPriorityByBundleChanged | (callbackData: [EnabledPriorityNotificationByBundleCallbackData](#enabledprioritynotificationbybundlecallbackdata23)>) => void | 否   | 返回应用通知优先级开关状态。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onEnabledPriorityByBundleChanged: (callbackData: notificationSubscribe.EnabledPriorityNotificationByBundleCallbackData) => {
    console.info(`onEnabledPriorityByBundleChanged: ${JSON.stringify(callbackData)}`);
  }
};
notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

### 属性

通知系统属性值变化的回调函数。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称   | 类型    | 只读 | 可选 | 说明             |
| ------ | ------- | ---- | --- | ---------------- |
| onSystemUpdate | [SystemUpdateCallback](#systemupdatecallback23) | 否 | 是 | 返回携带系统属性值的通知信息。 |
| onEnabledSilentReminderChanged | [EnabledSilentReminderChangedCallback](#enabledsilentreminderchangedcallback24) | 否 | 是 | 返回应用通知[静默提醒](../../notification/notification-glossary.md#silent-reminder静默提醒)的使能状态变化。 |
| onBadgeEnabledChanged | [BadgeEnabledChangedCallback](#badgeenabledchangedcallback12) | 否 | 是 | 返回应用角标的使能状态变化。 |
| onNotificationSwitchChanged | [NotificationSwitchChangedCallback](#notificationswitchchangedcallback) | 否 | 是 | 返回由[notificationManager.setNotificationSwitch](js-apis-notificationManager-sys.md#notificationmanagersetnotificationswitch)接口设置的通知开关状态变化。<br> **起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。 |

## SubscribeCallbackData

返回携带系统属性值的通知信息。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称            | 类型                                                                 | 只读 | 可选 | 说明     |
| --------------- |--------------------------------------------------------------------| ---- | --- | -------- |
| request         | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | 是  | 否  | [通知内容](../../notification/notification-glossary.md#notification-content通知内容)。 |
| sortingMap      | [NotificationSortingMap](js-apis-inner-notification-notificationSortingMap-sys.md) | 是  | 是  | [通知排序](../../notification/notification-glossary.md#notification-sorting通知排序)信息。 |
| reason          | number                                                             | 是  | 是  | 删除原因（1:点击通知后删除通知，2:用户删除通知） 。|
| sound           | string                                                             | 是  | 是  | 通知声音。 |
| vibrationValues | Array\<number\>                                                    | 是  | 是  | 通知振动。 |
| voiceContent | [VoiceContent](#voicecontent)                                              | 是  | 是  | 通知语音播报内容。<br> **起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。|
| notificationClassification | [NotificationClassification](#notificationclassification) | 是  | 是  | 通知分类信息。仅在[NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo)中的enableClassification为true时存在。<br> **起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。|

## EnabledNotificationCallbackData<sup>8+</sup>

应用角标使能状态变化的回调函数类型。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称   | 类型    | 只读 | 可选 | 说明             |
| ------ | ------- | ---- | --- | ---------------- |
| bundle | string  | 是  | 否  | 应用的包名。       |
| uid    | number  | 是  | 否  | 应用的uid。        |
| enable | boolean | 是  | 否  | 应用通知使能状态。<br> - true：允许。<br> - false：禁止。 |

## EnabledSilentReminderCallbackData<sup>24+</sup>

应用通知[静默提醒](../../notification/notification-glossary.md#silent-reminder静默提醒)开关状态的回调函数类型。

**系统能力**：SystemCapability.Notification.Notification

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称   | 类型    | 只读 | 可选 | 说明             |
| ------ | ------- | ---- | --- | ---------------- |
| bundle | string  | 是  | 否  | 应用的包名。       |
| uid    | number  | 是  | 否  | 应用的uid。        |
| enableStatus | [notificationManager.SwitchState](js-apis-notificationManager-sys.md#switchstate20) | 是  | 否  | 应用通知的静默提醒开关状态。<br> - USER_MODIFIED_OFF：用户设置的关闭状态。<br> - USER_MODIFIED_ON：用户设置的开启状态。<br> - SYSTEM_DEFAULT_OFF：用户设置前的初始关闭状态。<br> - SYSTEM_DEFAULT_ON：用户设置前的初始开启状态。|

## BadgeNumberCallbackData<sup>10+</sup>

应用角标数量变化的回调函数类型。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称        | 类型   | 只读 | 可选 | 说明         |
| ----------- | ------ | ---- | ---- | ------------ |
| bundle      | string | 是   | 否   | 应用的包名。 |
| uid         | number | 是   | 否   | 应用的uid。  |
| badgeNumber | number | 是   | 否   | 角标个数。   |
| instanceKey<sup>(deprecated)</sup>  | number | 是   | 是   | 应用实例键值。从API version 12开始支持，从API version 15开始废弃，建议使用appInstanceKey替代。   |
| appInstanceKey<sup>15+</sup>  | string | 是   | 是   | 应用实例键值。   |


## EnabledPriorityNotificationCallbackData<sup>23+</sup>

通知优先级总开关状态。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称        | 类型   | 只读 | 可选 | 说明         |
| ----------- | ------ | ---- | ---- | ------------ |
| enable | boolean | 是  | 否  | 所有通知的优先使能状态。<br> - true：允许设置为[优先通知](../../notification/notification-glossary.md#priority-notification优先通知)。<br> - false：禁止设置为优先通知。 |

## EnabledPriorityNotificationByBundleCallbackData<sup>23+</sup>

通知通知优先级开关状态。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称        | 类型   | 只读 | 可选 | 说明         |
| ----------- | ------ | ---- | ---- | ------------ |
| bundle      | string | 是   | 否   | 应用的包名。 |
| uid         | number | 是   | 否   | 应用的uid。  |
| enableStatus | [PriorityEnableStatus](js-apis-notificationManager-sys.md#priorityenablestatus23) | 是  | 否  | 应用通知的优先使能状态。 |

## NotificationSwitchChangedCallbackData

通知开关状态变化的回调函数类型。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Notification.Notification

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称        | 类型   | 只读 | 可选 | 说明         |
| ----------- | ------ | ---- | ---- | ------------ |
| userId | number | 是 | 否 | 用户ID。 |
| switchName | string | 是 | 否 | 通知开关名称。取值为：DEAL（交易类通知聚合开关）、LOGISTICS（物流类通知聚合开关）。 |
| enableStatus | [notificationManager.SwitchState](js-apis-notificationManager-sys.md#switchstate20) | 是 | 否 | 通知开关状态。 |

## VoiceContent

通知语音播报内容。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Notification.Notification

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称            | 类型                                                                 | 只读 | 可选 | 说明     |
| --------------- |--------------------------------------------------------------------| ---- | --- | -------- |
| textContent | string                                             | 是  | 是  | 文本语音播报内容。 |

## NotificationClassification

通知分类信息。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Notification.Notification

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称            | 类型   | 只读 | 可选 | 说明     |
| --------------- | ------ | ---- | --- | -------- |
| classification | string | 是  | 是  | 系统识别的通知分类。 |
| subClassification | string | 是  | 是  | 系统识别的通知子分类。 |

## BadgeEnabledChangedCallback<sup>12+</sup>

type BadgeEnabledChangedCallback = (data: EnabledNotificationCallbackData) => void

注册应用角标使能状态变化的回调函数类型。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | ------------ |
| data        | [EnabledNotificationCallbackData](#enablednotificationcallbackdata8) | 是    |   回调返回监听到的角标使能状态信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let BadgeEnabledChangedCallback = (data: notificationSubscribe.EnabledNotificationCallbackData) => {
  console.info(`onBadgeEnabledChanged, badge enabled state change to: ${JSON.stringify(data)}`);
};
let subscriber: notificationSubscribe.NotificationSubscriber = {
  onBadgeEnabledChanged: BadgeEnabledChangedCallback
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

## SystemUpdateCallback<sup>23+</sup>

type SystemUpdateCallback = (data: SubscribeCallbackData) => void

返回携带系统属性值通知信息的回调函数类型。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数**：

| 参数名       | 类型   | 必填 | 说明         |
| ----------- | ------ | ---- | ------------ |
| data | [SubscribeCallbackData](#subscribecallbackdata) | 是 | 返回携带系统属性值的通知信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onSystemUpdate: (data: notificationSubscribe.SubscribeCallbackData) => {
    let req = data.request;
    console.info(`onSystemUpdate callback req.priorityType: ${req.priorityNotificationType}`);
  }
};
notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

## EnabledSilentReminderChangedCallback<sup>24+</sup>

type EnabledSilentReminderChangedCallback = (callbackData: EnabledSilentReminderCallbackData) => void

注册应用通知[静默提醒](../../notification/notification-glossary.md#silent-reminder静默提醒)使能状态变化的回调函数类型。

**系统能力**：SystemCapability.Notification.Notification

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | ------------ |
| callbackData        | [EnabledSilentReminderCallbackData](#enabledsilentremindercallbackdata24) | 是    |   回调返回监听到的静默提醒使能状态信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onEnabledSilentReminderChangedCallback: notificationSubscribe.EnabledSilentReminderChangedCallback = (callbackData: notificationSubscribe.EnabledSilentReminderCallbackData) => {
  console.info('bundle: ', callbackData.bundle);
  console.info('uid: ', callbackData.uid);
  console.info('enable: ', callbackData.enableStatus);
};

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onEnabledSilentReminderChanged: onEnabledSilentReminderChangedCallback
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```

## NotificationSwitchChangedCallback

type NotificationSwitchChangedCallback = (callbackData: NotificationSwitchChangedCallbackData) => void

注册由[notificationManager.setNotificationSwitch](js-apis-notificationManager-sys.md#notificationmanagersetnotificationswitch)接口设置的通知开关状态变化的回调函数类型。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Notification.Notification

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | ------------ |
| callbackData | [NotificationSwitchChangedCallbackData](#notificationswitchchangedcallbackdata) | 是 | 回调返回由[notificationManager.setNotificationSwitch](js-apis-notificationManager-sys.md#notificationmanagersetnotificationswitch)接口设置的通知开关状态变化信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onNotificationSwitchChanged: (callbackData: notificationSubscribe.NotificationSwitchChangedCallbackData) => {
    console.info(`onNotificationSwitchChanged: ${JSON.stringify(callbackData)}`);
  }
};

notificationSubscribe.subscribeNotification(subscriber).then(() => {
  console.info('subscribeNotification success');
}).catch((err: BusinessError) => {
  console.error(`subscribeNotification failed, code is ${err.code}, message is ${err.message}`);
});
```
