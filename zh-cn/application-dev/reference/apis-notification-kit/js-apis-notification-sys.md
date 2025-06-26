# @ohos.notification (Notification模块)(系统应用)

本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知通道，订阅、取消订阅通知，获取通知的使能状态、角标使能状态，获取通知的相关信息等。

> **说明：**
>
> 从API version 9开始，该接口不再维护，推荐使用新接口[@ohos.notificationManager](js-apis-notificationManager.md)。
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[Notification](./js-apis-notification.md)。


## 导入模块

```ts
import Notification from '@ohos.notification';
```

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

发布通知给指定的用户（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| userId   | number                                      | 是   | 用户ID。                           |
| callback | AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                           |

**示例：**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// publish回调
let publishCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`publish failed, code is ${err.code}`);
  } else {
    console.info("publish success");
  }
}
// 用户ID
let userId: number = 1;
// 通知Request对象
let notificationRequest: NotificationManager.NotificationRequest = {
  id: 1,
  content: {
    contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
    normal: {
      title: "test_title",
      text: "test_text",
      additionalText: "test_additionalText"
    }
  }
};
Notification.publish(notificationRequest, userId, publishCallback);
```

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number): Promise\<void\>

发布通知给指定的用户（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     |  类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| userId   | number                                      | 是   | 用户ID。                           |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

let notificationRequest: NotificationManager.NotificationRequest = {
  id: 1,
  content: {
    contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
    normal: {
      title: "test_title",
      text: "test_text",
      additionalText: "test_additionalText"
    }
  }
};

let userId: number = 1;

Notification.publish(notificationRequest, userId).then(() => {
  console.info("publish success");
}).catch((err: Base.BusinessError) => {
  console.error(`publish failed, code is ${err}`);
});
```

## Notification.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

创建通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| slot     | [NotificationSlot](./js-apis-notification.md#notificationslot)       | 是   | 要创建的通知通道对象。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// addslot回调
let addSlotCallBack = (err: Base.BusinessError) => {
  if (err) {
    console.info("addSlot failed " + JSON.stringify(err));
  } else {
    console.info("addSlot success");
  }
}
// 通知slot对象
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
Notification.addSlot(notificationSlot, addSlotCallBack);
```

## Notification.addSlot

addSlot(slot: NotificationSlot): Promise\<void\>

创建通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型             | 必填 | 说明                 |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](./js-apis-notification.md#notificationslot) | 是   | 要创建的通知通道对象。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// 通知slot对象
let notificationSlot: NotificationManager.NotificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
};
Notification.addSlot(notificationSlot).then(() => {
	console.info("addSlot success");
}).catch((err: Base.BusinessError) => {
  console.error(`addSlot failed, code is ${err}`);
});
```

## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

创建多个通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](./js-apis-notification.md#notificationslot)\> | 是   | 要创建的通知通道对象数组。 |
| callback | AsyncCallback\<void\>     | 是   | 表示被指定的回调方法。     |

**示例：**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// addSlots回调
let addSlotsCallBack = (err: Base.BusinessError) => {
  if (err) {
    console.info("addSlots failed " + JSON.stringify(err));
  } else {
    console.info("addSlots success");
  }
}
// 通知slot对象
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
// 通知slot array 对象
let notificationSlotArray: NotificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

Notification.addSlots(notificationSlotArray, addSlotsCallBack);
```

## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>): Promise\<void\>

创建多个通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名  | 类型                      | 必填 | 说明                     |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](./js-apis-notification.md#notificationslot)\> | 是   | 要创建的通知通道对象数组。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// 通知slot对象
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
// 通知slot array 对象
let notificationSlotArray: NotificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

Notification.addSlots(notificationSlotArray).then(() => {
  console.info("addSlots success");
}).catch((err: Base.BusinessError) => {
  console.error(`addSlot failed, code is ${err}`);
});
```

## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

订阅通知并指定订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md)    | 是   | 通知订阅对象。     |
| info       | [NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo) | 是   | 通知订阅信息。 |
| callback   | AsyncCallback\<void\>     | 是   | 订阅动作回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

// subscribe回调
let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("subscribe failed " + JSON.stringify(err));
  } else {
    console.info("subscribe success");
  }
}
let onConsumeCallback = (data: NotificationSubscribe.SubscribeCallbackData) => {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
let info: NotificationSubscribe.NotificationSubscribeInfo = {
  bundleNames: ["bundleName1", "bundleName2"]
};
Notification.subscribe(subscriber, info, subscribeCallback);
```

## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

订阅当前用户下所有应用的通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明             |
| ---------- | ---------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md) | 是   | 通知订阅对象。     |
| callback   | AsyncCallback\<void\>  | 是   | 订阅动作回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("subscribe failed " + JSON.stringify(err));
  } else {
    console.info("subscribe success");
  }
}
function onConsumeCallback(data: NotificationSubscribe.SubscribeCallbackData) {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
Notification.subscribe(subscriber, subscribeCallback);
```

## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo): Promise\<void\>

订阅通知并指定订阅信息（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                      | 必填 | 说明         |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md)    | 是   | 通知订阅对象。 |
| info       | [NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo) | 否   | 通知订阅信息，默认为空。   |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

function onConsumeCallback(data: NotificationSubscribe.SubscribeCallbackData) {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
Notification.subscribe(subscriber).then(() => {
  console.info("subscribe success");
}).catch((err: Base.BusinessError) => {
  console.error(`subscribe failed, code is ${err}`);
});
```

## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

取消订阅（callbcak形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明                 |
| ---------- | ---------------------- | ---- | -------------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md) | 是   | 通知订阅对象。         |
| callback   | AsyncCallback\<void\>  | 是   | 取消订阅动作回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

let unsubscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("unsubscribe failed " + JSON.stringify(err));
  } else {
    console.info("unsubscribe success");
  }
}
let onDisconnectCallback = () => {
  console.info("subscribe disconnect");
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onDisconnect: onDisconnectCallback
};
Notification.unsubscribe(subscriber, unsubscribeCallback);
```

## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber): Promise\<void\>

取消订阅（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明         |
| ---------- | ---------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md) | 是   | 通知订阅对象。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

function onDisconnectCallback() {
  console.info("subscribe disconnect");
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onDisconnect: onDisconnectCallback
};
Notification.unsubscribe(subscriber).then(() => {
  console.info("unsubscribe success");
}).catch((err: Base.BusinessError) => {
  console.error(`unsubscribe failed, code is ${err}`);
});
```

## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定应用的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。        |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知使能回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let enableNotificationCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("enableNotification failed " + JSON.stringify(err));
  } else {
    console.info("enableNotification success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.enableNotification(bundle, false, enableNotificationCallback);
```

## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean): Promise\<void\>

设定指定应用的通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.enableNotification(bundle, false).then(() => {
  console.info("enableNotification success");
}).catch((err: Base.BusinessError) => {
  console.error(`enableNotification failed, code is ${err}`);
});

```

## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定应用的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。            |
| callback | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("isNotificationEnabled failed " + JSON.stringify(err));
  } else {
    console.info("isNotificationEnabled success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.isNotificationEnabled(bundle, isNotificationEnabledCallback);
```

## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption): Promise\<boolean\>

获取指定应用的通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型               | 说明                                                |
| ------------------ | --------------------------------------------------- |
| Promise\<boolean\> | 以Promise形式返回获取指定应用的通知使能状态的结果。 |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.isNotificationEnabled(bundle).then((data) => {
  console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`isNotificationEnabled failed, code is ${err}`);
});
```

## Notification.isNotificationEnabled

isNotificationEnabled(callback: AsyncCallback\<boolean\>): void

获取通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("isNotificationEnabled failed " + JSON.stringify(err));
  } else {
    console.info("isNotificationEnabled success");
  }
}

Notification.isNotificationEnabled(isNotificationEnabledCallback);
```

## Notification.isNotificationEnabled

isNotificationEnabled(): Promise\<boolean\>

获取通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取通知使能状态的结果。 |

**示例：**

```ts
import Base from '@ohos.base';

Notification.isNotificationEnabled().then((data: boolean) => {
  console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`isNotificationEnabled failed, code is ${err}`);
});
```

## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定应用的角标使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。           |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定角标使能回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let displayBadgeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("displayBadge failed " + JSON.stringify(err));
  } else {
    console.info("displayBadge success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.displayBadge(bundle, false, displayBadgeCallback);
```

## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean): Promise\<void\>

设定指定应用的角标使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.displayBadge(bundle, false).then(() => {
  console.info("displayBadge success");
}).catch((err: Base.BusinessError) => {
  console.error(`displayBadge failed, code is ${err}`);
});
```

## Notification.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定应用的角标使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。               |
| callback | AsyncCallback\<void\> | 是   | 获取角标使能状态回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let isBadgeDisplayedCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("isBadgeDisplayed failed " + JSON.stringify(err));
  } else {
    console.info("isBadgeDisplayed success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);
```

## Notification.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption): Promise\<boolean\>

获取指定应用的角标使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取指定应用的角标使能状态。 |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.isBadgeDisplayed(bundle).then((data) => {
  console.info("isBadgeDisplayed success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`isBadgeDisplayed failed, code is ${err}`);
});
```

## Notification.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

设定指定应用的通知通道（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。           |
| slot     | [NotificationSlot](./js-apis-notification.md#notificationslot)      | 是   | 通知通道。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知通道回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let setSlotByBundleCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("setSlotByBundle failed " + JSON.stringify(err));
  } else {
    console.info("setSlotByBundle success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
Notification.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);
```

## Notification.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot): Promise\<void\>

设定指定应用的通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| slot   | [NotificationSlot](./js-apis-notification.md#notificationslot) | 是   | 通知通道。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
Notification.setSlotByBundle(bundle, notificationSlot).then(() => {
  console.info("setSlotByBundle success");
}).catch((err: Base.BusinessError) => {
  console.error(`setSlotByBundle failed, code is ${err}`);
});
```

## Notification.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback\<Array\<NotificationSlot>>): void

获取指定应用的所有通知通道（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                                     | 必填 | 说明                 |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)                             | 是   | 指定应用的包信息。           |
| callback | AsyncCallback\<Array\<[NotificationSlot](./js-apis-notification.md#notificationslot)>> | 是   | 获取通知通道回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let getSlotsByBundleCallback = (err: Base.BusinessError, data: NotificationManager.NotificationSlot[]) => {
  if (err) {
    console.info("getSlotsByBundle failed " + JSON.stringify(err));
  } else {
    console.info("getSlotsByBundle success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.getSlotsByBundle(bundle, getSlotsByBundleCallback);
```

## Notification.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption): Promise\<Array\<NotificationSlot>>

获取指定应用的所有通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](./js-apis-notification.md#notificationslot)>> | 以Promise形式返回获取指定应用的通知通道。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.getSlotsByBundle(bundle).then((data: NotificationManager.NotificationSlot[]) => {
  console.info("getSlotsByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getSlotsByBundle failed, code is ${err}`);
});
```

## Notification.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

获取指定应用的通知通道数量（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)              | 是   | 指定应用的包信息。             |
| callback | AsyncCallback\<number\> | 是   | 获取通知通道数量回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let getSlotNumByBundleCallback = (err: Base.BusinessError, data: number) => {
  if (err) {
    console.info("getSlotNumByBundle failed " + JSON.stringify(err));
  } else {
    console.info("getSlotNumByBundle success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);
```

## Notification.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption): Promise\<number\>

获取指定应用的通知通道数量（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取指定应用的通知通道数量。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.getSlotNumByBundle(bundle).then((data: number) => {
  console.info("getSlotNumByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getSlotNumByBundle failed, code is ${err}`);
});
```

## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名            | 类型                                | 必填 | 说明                 |
| --------------- |   ----------------------------------| ---- | -------------------- |
| bundle          | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)       | 是   | 指定应用的包信息。           |
| notificationKey | [NotificationKey](./js-apis-notification.md#notificationkeydeprecated) | 是   | 通知键值。             |
| reason          | [RemoveReason](#removereason-deprecated)      | 是   | 通知删除原因。         |
| callback        | AsyncCallback\<void\>               | 是   | 删除指定通知回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let removeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("remove failed " + JSON.stringify(err));
  } else {
    console.info("remove success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: Notification.NotificationKey = {
  id: 0,
  label: "label",
};
let reason: Notification.RemoveReason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(bundle, notificationKey, reason, removeCallback);
```

## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason): Promise\<void\>

删除指定通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名            | 类型            | 必填 | 说明       |
| --------------- | --------------- | ---- | ---------- |
| bundle          | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)    | 是   | 指定应用的包信息。 |
| notificationKey | [NotificationKey](./js-apis-notification.md#notificationkeydeprecated) | 是   | 通知键值。   |
| reason          | [RemoveReason](#removereason-deprecated) | 是   | 通知删除原因。         |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: Notification.NotificationKey = {
  id: 0,
  label: "label",
};
let reason: Notification.RemoveReason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(bundle, notificationKey, reason).then(() => {
  console.info("remove success");
}).catch((err: Base.BusinessError) => {
  console.error(`remove failed, code is ${err}`);
});
```

## Notification.remove

remove(hashCode: string, reason: RemoveReason, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| hashCode | string                | 是   | 通知唯一ID。可以通过[onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume)回调的入参[SubscribeCallbackData](js-apis-inner-notification-notificationSubscriber-sys.md#subscribecallbackdata)获取其内部[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)对象中的hashCode。 |
| reason   | [RemoveReason](#removereason-deprecated) | 是   | 通知删除原因。         |
| callback | AsyncCallback\<void\> | 是   | 删除指定通知回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let hashCode: string = 'hashCode';

let removeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("remove failed " + JSON.stringify(err));
  } else {
    console.info("remove success");
  }
}
let reason: Notification.RemoveReason = Notification.RemoveReason.CANCEL_REASON_REMOVE;
Notification.remove(hashCode, reason, removeCallback);
```

## Notification.remove

remove(hashCode: string, reason: RemoveReason): Promise\<void\>

删除指定通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型       | 必填 | 说明       |
| -------- | ---------- | ---- | ---------- |
| hashCode | string | 是   | 通知唯一ID。 |
| reason   | [RemoveReason](#removereason-deprecated) | 是   | 通知删除原因。         |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';

let hashCode: string = 'hashCode';
let reason: Notification.RemoveReason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(hashCode, reason).then(() => {
  console.info("remove success");
}).catch((err: Base.BusinessError) => {
  console.error(`remove failed, code is ${err}`);
});
```

## Notification.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

删除指定应用的所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名     | 类型                  | 必填 | 说明                         |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。                   |
| callback | AsyncCallback\<void\> | 是   | 删除指定应用的所有通知回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let removeAllCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("removeAll failed " + JSON.stringify(err));
  } else {
    console.info("removeAll success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.removeAll(bundle, removeAllCallback);
```

## Notification.removeAll

removeAll(callback: AsyncCallback\<void\>): void

删除所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 删除所有通知回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let removeAllCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("removeAll failed " + JSON.stringify(err));
  } else {
    console.info("removeAll success");
  }
}

Notification.removeAll(removeAllCallback);
```

## Notification.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

删除指定应用的所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 否   | 指定应用的包信息。默认为空，表示删除所有通知。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';

// 不指定应用时，删除所有通知
Notification.removeAll().then(() => {
  console.info("removeAll success");
}).catch((err: Base.BusinessError) => {
  console.error(`removeAll failed, code is ${err}`);
});
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number, callback: AsyncCallback\<void>): void

删除指定用户下的所有通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 删除指定用户所有通知回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

function removeAllCallback(err: Base.BusinessError) {
  if (err) {
    console.info("removeAll failed " + JSON.stringify(err));
  } else {
    console.info("removeAll success");
  }
}

let userId: number = 1;
Notification.removeAll(userId, removeAllCallback);
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number): Promise\<void>

删除指定用户下的所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 用户ID。 |

**示例：**

```ts
import Base from '@ohos.base';

let userId: number = 1;
Notification.removeAll(userId).then(() => {
  console.info("removeAll success");
}).catch((err: Base.BusinessError) => {
  console.error(`removeAll failed, code is ${err}`);
});
```


## Notification.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void

获取当前未删除的所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>> | 是   | 获取活动通知回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

function getAllActiveNotificationsCallback(err: Base.BusinessError, data: NotificationManager.NotificationRequest[]) {
  if (err) {
    console.info("getAllActiveNotifications failed " + JSON.stringify(err));
  } else {
    console.info("getAllActiveNotifications success");
  }
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```

## Notification.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>>

获取当前未删除的所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>> | 以Promise形式返回获取活动通知。 |

**示例：**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

Notification.getAllActiveNotifications().then((data: NotificationManager.NotificationRequest[]) => {
  console.info("getAllActiveNotifications success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getAllActiveNotifications failed, code is ${err}`);
});
```

## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

删除指定应用的指定组下的通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名      | 类型                  | 必填 | 说明                         |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 应用的包信息。                   |
| groupName | string                | 是   | 通知组名称。               |
| callback  | AsyncCallback\<void\> | 是   | 删除指定应用指定组下通知的回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let removeGroupByBundleCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("removeGroupByBundle failed " + JSON.stringify(err));
  } else {
    console.info("removeGroupByBundle success");
  }
}

let bundleOption: Notification.BundleOption = {bundle: "Bundle"};
let groupName: string = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```

## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

删除指定应用的指定组下的通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名      | 类型         | 必填 | 说明           |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。     |
| groupName | string       | 是   | 通知组名称。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';

let bundleOption: Notification.BundleOption = {bundle: "Bundle"};
let groupName: string = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
  console.info("removeGroupByBundle success");
}).catch((err: Base.BusinessError) => {
  console.error(`removeGroupByBundle failed, code is ${err}`);
});
```

## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate8-deprecated)      | 是   | 免打扰时间选项。         |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let setDoNotDisturbDateCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("setDoNotDisturbDate failed " + JSON.stringify(err));
  } else {
    console.info("setDoNotDisturbDate success");
  }
}

let doNotDisturbDate: Notification.DoNotDisturbDate = {
  type: Notification.DoNotDisturbType.TYPE_ONCE,
  begin: new Date(),
  end: new Date(2021, 11, 15, 18, 0)
};

Notification.setDoNotDisturbDate(doNotDisturbDate, setDoNotDisturbDateCallback);
```

## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void\>

设置免打扰时间（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型             | 必填 | 说明           |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate8-deprecated) | 是   | 免打扰时间选项。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';

let doNotDisturbDate: Notification.DoNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};
Notification.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: Base.BusinessError) => {
  console.error(`setDoNotDisturbDate failed, code is ${err}`);
});
```


## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

指定用户设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate8-deprecated)      | 是   | 免打扰时间选项。         |
| userId   | number                | 是   | 设置免打扰时间的用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let setDoNotDisturbDateCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("setDoNotDisturbDate failed " + JSON.stringify(err));
  } else {
    console.info("setDoNotDisturbDate success");
  }
}

let doNotDisturbDate: Notification.DoNotDisturbDate = {
  type: Notification.DoNotDisturbType.TYPE_ONCE,
  begin: new Date(),
  end: new Date(2021, 11, 15, 18, 0)
};

let userId: number = 1;
Notification.setDoNotDisturbDate(doNotDisturbDate, userId, setDoNotDisturbDateCallback);
```

## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

指定用户设置免打扰时间（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate8-deprecated) | 是   | 免打扰时间选项。 |
| userId | number           | 是   | 设置免打扰时间的用户ID。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**示例：**

```ts
import Base from '@ohos.base';

let doNotDisturbDate: Notification.DoNotDisturbDate = {
  type: Notification.DoNotDisturbType.TYPE_ONCE,
  begin: new Date(),
  end: new Date(2021, 11, 15, 18, 0)
};

let userId: number = 1;

Notification.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
  console.info("setDoNotDisturbDate success");
}).catch((err: Base.BusinessError) => {
  console.error(`setDoNotDisturbDate failed, code is ${err}`);
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

查询免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8-deprecated)\> | 是   | 查询免打扰时间回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: Notification.DoNotDisturbDate) => {
  if (err) {
    console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
  } else {
    console.info("getDoNotDisturbDate success");
  }
}

Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```

## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

查询免打扰时间（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                              | 说明                                      |
| ------------------------------------------------- | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8-deprecated)\> | 以Promise形式返回查询到的免打扰时间。 |

**示例：**

```ts
import Base from '@ohos.base';

Notification.getDoNotDisturbDate().then((data: Notification.DoNotDisturbDate) => {
  console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getDoNotDisturbDate failed, code is ${err}`);
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

查询指定用户的免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8-deprecated)\> | 是   | 查询免打扰时间回调函数。 |
| userId   | number                            | 是   | 用户ID。 |

**示例：**

```ts
import Base from '@ohos.base';

let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: Notification.DoNotDisturbDate) => {
  if (err) {
    console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
  } else {
    console.info("getDoNotDisturbDate success");
  }
}

let userId: number = 1;

Notification.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```

## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

查询指定用户的免打扰时间（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| userId   | number                            | 是   | 用户ID。 |

**返回值：**

| 类型                                              | 说明                                      |
| ------------------------------------------------- | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8-deprecated)\> | 以Promise形式返回查询到的免打扰时间。 |

**示例：**

```ts
import Base from '@ohos.base';

let userId: number = 1;

Notification.getDoNotDisturbDate(userId).then((data: Notification.DoNotDisturbDate) => {
  console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getDoNotDisturbDate failed, code is ${err}`);
});
```


## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

查询是否支持免打扰功能（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                     | 必填 | 说明                             |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 查询是否支持免打扰功能回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let supportDoNotDisturbModeCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("supportDoNotDisturbMode failed " + JSON.stringify(err));
  } else {
    console.info("supportDoNotDisturbMode success");
  }
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```

## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(): Promise\<boolean\>

查询是否支持免打扰功能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取是否支持免打扰功能的结果。 |

**示例：**

```ts
import Base from '@ohos.base';

Notification.supportDoNotDisturbMode().then((data: boolean) => {
  console.info("supportDoNotDisturbMode success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`supportDoNotDisturbMode failed, code is ${err}`);
});
```

## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean, callback: AsyncCallback\<void\>): void

设置设备是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。 |
| callback | AsyncCallback\<void\> | 是   | 设置设备是否支持分布式通知的回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let enabledNotificationCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("enableDistributed failed " + JSON.stringify(err));
  } else {
    console.info("enableDistributed success");
  }
};

let enable: boolean = true;

Notification.enableDistributed(enable, enabledNotificationCallback);
```

## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean): Promise\<void>

设置设备是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。 |

**示例：**

```ts
import Base from '@ohos.base';

let enable: boolean = true;
Notification.enableDistributed(enable).then(() => {
  console.info("enableDistributed success");
}).catch((err: Base.BusinessError) => {
  console.error(`enableDistributed failed, code is ${err}`);
});
```

## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

设置指定应用是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包信息。                   |
| enable   | boolean                  | 是   | 是否支持。                       |
| callback | AsyncCallback\<void\> | 是   | 应用程序是否支持分布式通知的回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let enableDistributedByBundleCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("enableDistributedByBundle failed " + JSON.stringify(err));
  } else {
    console.info("enableDistributedByBundle success");
  }
};

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};

let enable: boolean = true;

Notification.enableDistributedByBundle(bundle, enable, enableDistributedByBundleCallback);
```

## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

设置指定应用是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                |
| enable   | boolean                  | 是   | 是否支持。                  |

**示例：**

```ts
import Base from '@ohos.base';

let enable: boolean = true;

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};

Notification.enableDistributedByBundle(bundle, enable).then(() => {
  console.info("enableDistributedByBundle success");
}).catch((err: Base.BusinessError) => {
  console.error(`enableDistributedByBundle failed, code is ${err}`);
});

```

## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

根据应用的包获取应用程序是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                     |
| callback | AsyncCallback\<boolean\> | 是   | 查询指定应用是否支持分布式通知的回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let isDistributedEnabledByBundleCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("isDistributedEnabledByBundle failed " + JSON.stringify(err));
  } else {
    console.info("isDistributedEnabledByBundle success" + JSON.stringify(data));
  }
};

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};

Notification.isDistributedEnabledByBundle(bundle, isDistributedEnabledByBundleCallback);
```

## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

查询指定应用是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                |

**返回值：**

| 类型               | 说明                                              |
| ------------------ | ------------------------------------------------- |
| Promise\<boolean\> | Promise方式返回指定应用是否支持分布式通知的结果。 |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};

Notification.isDistributedEnabledByBundle(bundle).then((data: boolean) => {
  console.info("isDistributedEnabledByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`isDistributedEnabledByBundle failed, code is ${err}`);
});
```


## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

获取通知的提醒方式（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                               | 必填 | 说明                       |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype8-deprecated)\> | 是   | 获取通知提醒方式的回调函数。 |

**示例：**

```ts
import Base from '@ohos.base';

let getDeviceRemindTypeCallback = (err: Base.BusinessError, data: Notification.DeviceRemindType) => {
  if (err) {
    console.info("getDeviceRemindType failed " + JSON.stringify(err));
  } else {
    console.info("getDeviceRemindType success");
  }
};

Notification.getDeviceRemindType(getDeviceRemindTypeCallback);
```

## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(): Promise\<DeviceRemindType\>

获取通知的提醒方式（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统API**：此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype8-deprecated)\> | Promise方式返回获取通知提醒方式的结果。 |

**示例：**

```ts
import Base from '@ohos.base';

Notification.getDeviceRemindType().then((data: Notification.DeviceRemindType) => {
  console.info("getDeviceRemindType success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getDeviceRemindType failed, code is ${err}`);
});
```

## DoNotDisturbDate<sup>8+</sup> <sup>deprecated</sup>

**系统能力**：SystemCapability.Notification.Notification

> **说明：**
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[notificationManager.DoNotDisturbDate](js-apis-notificationManager-sys.md#donotdisturbdate)替代

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称  | 类型                                   | 可读 | 可写 | 说明                   |
| ----- | -------------------------------------- | ---- | ---- | ---------------------- |
| type  | [DoNotDisturbType](./js-apis-notificationManager-sys.md#donotdisturbtype) | 是   | 是   | 免打扰设置的时间类型。 |
| begin | Date                                   | 是   | 是   | 免打扰设置的起点时间。 |
| end   | Date                                   | 是   | 是   | 免打扰设置的终点时间。 |

## DoNotDisturbType<sup>8+</sup> <sup>deprecated</sup>

**系统能力**：SystemCapability.Notification.Notification

> **说明：**
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[notificationManager.DoNotDisturbType](js-apis-notificationManager-sys.md#donotdisturbtype)替代

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称         | 值               | 说明                                       |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | 0 | 非通知勿扰类型。                           |
| TYPE_ONCE    | 1 | 以设置时间段(只看小时和分钟)一次执行勿扰。 |
| TYPE_DAILY   | 2 | 以设置时间段(只看小时和分钟)每天执行勿扰。 |
| TYPE_CLEARLY | 3 | 以设置时间段(明确年月日时分)执行勿扰。     |

## DeviceRemindType<sup>8+</sup> <sup>deprecated</sup>

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

> **说明：**
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[notificationManager.DeviceRemindType](js-apis-notificationManager-sys.md#deviceremindtype)替代

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | 设备未被使用，无需提醒。            |
| IDLE_REMIND          | 1   | 提醒设备未被使用。                 |
| ACTIVE_DONOT_REMIND  | 2   | 设备正在使用，无需提醒。            |
| ACTIVE_REMIND        | 3   | 提醒设备正在使用。                 |


## SourceType<sup>8+</sup> <sup>deprecated</sup>

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

> **说明：**
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[notificationManager.SourceType](js-apis-notificationManager-sys.md#sourcetype)替代

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | 一般通知。            |
| TYPE_CONTINUOUS      | 1   | 连续通知。            |
| TYPE_TIMER           | 2   | 计划通知。            |

## RemoveReason <sup>deprecated</sup>

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[notificationManager.RemoveReason](js-apis-notificationSubscribe-sys.md#removereason)替代

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | 点击通知后删除通知。    |
| CANCEL_REASON_REMOVE | 2   | 用户删除通知。         |