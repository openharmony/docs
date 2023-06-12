# NotificationSubscriber

作为订阅通知接口[subscribe](js-apis-notificationSubscribe.md)的入参，提供订阅者接收到新通知、取消通知等的回调方法。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import notificationSubscribe from '@ohos.notificationSubscribe';
```

**系统API**：此接口为系统接口，三方应用不支持调用。

### onConsume

onConsume?: (data: [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata)) => void

接收到新通知的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata) | 是 | 新接收到的通知信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onConsumeCallback(data) {
    console.info('===> onConsume in test');
    let req = data.request;
    console.info('===> onConsume callback req.id:' + req.id);
};

let subscriber = {
    onConsume: onConsumeCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onCancel

onCancel?:(data: [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata)) => void

取消通知的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata) | 是 | 需要取消的通知信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onCancelCallback(data) {
    console.info('===> onCancel in test');
    let req = data.request;
    console.info('===> onCancel callback req.id:' + req.id);
}

let subscriber = {
    onCancel: onCancelCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onUpdate

onUpdate?:(data: [NotificationSortingMap](js-apis-notification.md#notificationsortingmap)) => void

更新通知排序的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](js-apis-notification.md#notificationsortingmap) | 是 | 最新的通知排序列表。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onUpdateCallback(map) {
    console.info('===> onUpdateCallback map:' + JSON.stringify(map));
}

let subscriber = {
    onUpdate: onUpdateCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onConnect

onConnect?:() => void

订阅完成的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onConnectCallback() {
    console.info('===> onConnect in test');
}

let subscriber = {
    onConnect: onConnectCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDisconnect

onDisconnect?:() => void

取消订阅的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};
function unsubscribeCallback(err) {
    if (err.code) {
        console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("unsubscribeCallback");
    }
};

function onConnectCallback() {
    console.info('===> onConnect in test');
}
function onDisconnectCallback() {
    console.info('===> onDisconnect in test');
}

let subscriber = {
    onConnect: onConnectCallback,
    onDisconnect: onDisconnectCallback
};

// 订阅通知后会收到onConnect回调
notificationSubscribe.subscribe(subscriber, subscribeCallback);
// 取消订阅后会收到onDisconnect回调
notificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
```

### onDestroy

onDestroy?:() => void

服务失联回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onDestroyCallback() {
    console.info('===> onDestroy in test');
}

let subscriber = {
    onDestroy: onDestroyCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbDateChange<sup>8+</sup>

onDoNotDisturbDateChange?:(mode: notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate)) => void

免打扰时间选项发生变更时的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | notification.[DoNotDisturbDate](js-apis-notificationManager.md#DoNotDisturbDate) | 是 | 回调返回免打扰时间选项变更。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onDoNotDisturbDateChangeCallback(mode) {
    console.info('===> onDoNotDisturbDateChange:' + mode);
}

let subscriber = {
    onDoNotDisturbDateChange: onDoNotDisturbDateChangeCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```


### onEnabledNotificationChanged<sup>8+</sup>

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](js-apis-notification.md#enablednotificationcallbackdata)) => void

监听应用通知使能变化。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](js-apis-notification.md#enablednotificationcallbackdata)\> | 是 | 回调返回监听到的应用信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onEnabledNotificationChangedCallback(callbackData) {
    console.info("bundle: ", callbackData.bundle);
    console.info("uid: ", callbackData.uid);
    console.info("enable: ", callbackData.enable);
};

let subscriber = {
    onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onBadgeChanged<sup>10+</sup>

 onBadgeChanged?:(data: [BadgeNumberCallbackData](#badgenumbercallbackdata10)) => void

监听应用角标个数变化。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[BadgeNumberCallbackData](#badgenumbercallbackdata10)\> | 是   | 回调返回监听到的应用信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onBadgeChangedCallback(data) {
    console.info("bundle: ", data.bundle);
    console.info("uid: ", data.uid);
    console.info("badgeNumber: ", data.badgeNumber);
};

let subscriber = {
    onBadgeChanged: onBadgeChangedCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

## SubscribeCallbackData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称            | 类型                                              | 只读 | 必传 | 说明     |
| --------------- | ------------------------------------------------- | ---- | --- | -------- |
| request         | [NotificationRequest](js-apis-inner-notification-notificationRequest#notificationrequest)       | 是  | 是  | 通知内容。 |
| sortingMap      | [NotificationSortingMap](js-apis-inner-notification-notificationSortingMap.md) | 是  | 否  | 通知排序信息。 |
| reason          | number                                            | 是  | 否  | 删除原因。 |
| sound           | string                                            | 是  | 否  | 通知声音。 |
| vibrationValues | Array\<number\>                                   | 是  | 否  | 通知震动。 |


## EnabledNotificationCallbackData<sup>8+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称   | 类型    | 只读 | 必传 | 说明             |
| ------ | ------- | ---- | --- | ---------------- |
| bundle | string  | 是  | 是  | 应用的包名。       |
| uid    | number  | 是  | 是  | 应用的uid。        |
| enable | boolean | 是  | 是  | 应用通知使能状态。 |


## BadgeNumberCallbackData<sup>10+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称        | 类型   | 只读 | 必传 | 描述         |
| ----------- | ------ | ---- | ---- | ------------ |
| bundle      | string | 是   | 是   | 应用的包名。 |
| uid         | number | 是   | 是   | 应用的uid。  |
| badgeNumber | number | 是   | 是   | 角标个数。   |

