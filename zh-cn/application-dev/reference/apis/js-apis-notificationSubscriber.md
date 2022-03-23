# 提供在订阅者收到新通知或取消通知时将回调的方法。

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationSubscriber
### onConsume

onConsume?:(data: [SubscribeCallbackData](#subscribecallbackdata))

接收通知回调函数。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | AsyncCallback\<[SubscribeCallbackData](#subscribecallbackdata)\> | 是 | 回调返回接收到的通知信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onConsumeCallback(data) {
    console.info('===> onConsume in test');
    let req = data.request;
    console.info('===> onConsume callback req.id:' + req.id);
    let wantAgent = data.wantAgent;
    wantAgent .getWant(wantAgent)
        .then((data1) => {
            console.log('===> getWant success want:' + JSON.stringfy(data1));
        })
        .catch((err) => {
            console.error('===> getWant failed because' + JSON.stringfy(err));
        });
    console.info('===> onConsume callback req.wantAgent:' + JSON.stringfy(req.wantAgent));
};

var subscriber = {
    onConsume: onConsumeCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onCancel

onCancel?:(data: [SubscribeCallbackData](#subscribecallbackdata))

删除通知回调函数。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | AsyncCallback\<[SubscribeCallbackData](#subscribecallbackdata)\> | 是 | 回调返回接收到的通知信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onCancelCallback(data) {
    console.info('===> onCancel in test');
    let req = data.request;
    console.info('===> onCancel callback req.id:' + req.id);
}

var subscriber = {
    onCancel: onCancelCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onUpdate

onUpdate?:(data: [NotificationSortingMap](#notificationsortingmap))

更新通知排序回调函数。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](#notificationsortingmap) | 是 | 回调返回接收到的通知信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onUpdateCallback() {
    console.info('===> onUpdate in test');
}

var subscriber = {
    onUpdate: onUpdateCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onConnect

onConnect?:void

注册订阅回调函数。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onConnectCallback() {
    console.info('===> onConnect in test');
}

var subscriber = {
    onConnect: onConnectCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onDisconnect

onDisconnect?:void

取消订阅回调函数。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onDisconnectCallback() {
    console.info('===> onDisconnect in test');
}

var subscriber = {
    onDisconnect: onDisconnectCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onDestroy

onDestroy?:void

服务失联回调函数。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onDestroyCallback() {
    console.info('===> onDestroy in test');
}

var subscriber = {
    onDestroy: onDestroyCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbDateChange<sup>8+</sup>

onDoNotDisturbDateChange?:(mode: Notification.[DoNotDisturbDate](#donotdisturbdate))

免打扰时间选项变更回调函数。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | Notification.[DoNotDisturbDate](#donotdisturbdate) | 是 | 回调返回免打扰时间选项变更。 |

**示例：**
```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onDoNotDisturbDateChangeCallback() {
    console.info('===> onDoNotDisturbDateChange in test');
}

var subscriber = {
    onDoNotDisturbDateChange: onDoNotDisturbDateChangeCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```


### onEnabledNotificationChanged<sup>8+</sup>

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](#enablednotificationcallbackdata))

监听应用通知使能变化。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](#enablednotificationcallbackdata)\> | 是 | 回调返回监听到的应用信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onEnabledNotificationChangedCallback(err, callbackData) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("bundle: ", callbackData.bundle);
        console.info("uid: ", callbackData.uid);
        console.info("enable: ", callbackData.enable);
    }
};

var subscriber = {
    onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

## SubscribeCallbackData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称            | 可读 | 可写 | 类型                                              | 必填 | 描述     |
| --------------- | ---- | --- | ------------------------------------------------- | ---- | -------- |
| request         | 是  | 否  | [NotificationRequest](#notificationrequest)       | 是   | 通知内容。 |
| sortingMap      | 是  | 否  | [NotificationSortingMap](#notificationsortingmap) | 否   | 排序信息。 |
| reason          | 是  | 否  | number                                            | 否   | 删除原因。 |
| sound           | 是  | 否  | string                                            | 否   | 通知声音。 |
| vibrationValues | 是  | 否  | Array\<number\>                                   | 否   | 通知震动。 |


## EnabledNotificationCallbackData<sup>8+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称   | 可读 | 可写 | 类型    | 必填 | 描述             |
| ------ | ---- | --- | ------- | ---- | ---------------- |
| bundle | 是  | 否  | string  | 是   | 应用的包名。       |
| uid    | 是  | 否  | number  | 是   | 应用的uid。        |
| enable | 是  | 否  | boolean | 是   | 应用通知使能状态。 |