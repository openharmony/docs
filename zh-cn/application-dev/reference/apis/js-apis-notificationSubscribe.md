# @ohos.notificationSubscribe (NotificationSubscribe模块)

本模块提供通知订阅、取消订阅、通知移除等，一般情况下，只有系统应用具有这些操作权限。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import NotificationSubscribe from '@ohos.notificationSubscribe';
```



## NotificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

订阅通知并指定订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | 是   | 通知订阅对象。     |
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | 是   | 通知订阅信息。 |
| callback   | AsyncCallback\<void\>     | 是   | 订阅动作回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//subscribe回调
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
var subscriber = {
    onConsume: onConsumeCallback
}
var info = {
    bundleNames: ["bundleName1","bundleName2"]
}
NotificationSubscribe.subscribe(subscriber, info, subscribeCallback);
```



## NotificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

订阅当前用户下所有应用的通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明             |
| ---------- | ---------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。     |
| callback   | AsyncCallback\<void\>  | 是   | 订阅动作回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
var subscriber = {
    onConsume: onConsumeCallback
}
NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```



## NotificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo): Promise\<void\>

订阅通知并指定订阅信息（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                      | 必填 | 说明         |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | 是   | 通知订阅对象。 |
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | 否   | 通知订阅信息。   |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function onConsumeCallback(data) {
    console.info("Consume callback: " + JSON.stringify(data));
}
var subscriber = {
    onConsume: onConsumeCallback
};
NotificationSubscribe.subscribe(subscriber).then(() => {
	console.info("subscribe success");
});
```



## NotificationSubscribe.unsubscribe

unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

取消订阅（callbcak形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明                 |
| ---------- | ---------------------- | ---- | -------------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。         |
| callback   | AsyncCallback\<void\>  | 是   | 取消订阅动作回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function unsubscribeCallback(err) {
    if (err) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe success");
    }
}
function onDisconnectCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onDisconnect: onDisconnectCallback
}
NotificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
```



## NotificationSubscribe.unsubscribe

unsubscribe(subscriber: NotificationSubscriber): Promise\<void\>

取消订阅（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明         |
| ---------- | ---------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function onDisconnectCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onDisconnect: onDisconnectCallback
};
NotificationSubscribe.unsubscribe(subscriber).then(() => {
	console.info("unsubscribe success");
});
```



## NotificationSubscribe.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名            | 类型                                | 必填 | 说明                 |
| --------------- |   ----------------------------------| ---- | -------------------- |
| bundle          | [BundleOption](#bundleoption)       | 是   | 指定应用的包信息。           |
| notificationKey | [NotificationKey](#notificationkey) | 是   | 通知键值。             |
| reason          | [RemoveReason](#removereason)      | 是   | 通知删除原因。         |
| callback        | AsyncCallback\<void\>               | 是   | 删除指定通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function removeCallback(err) {
    if (err) {
        console.info("remove failed " + JSON.stringify(err));
    } else {
        console.info("remove success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
var reason = NotificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
NotificationSubscribe.remove(bundle, notificationKey, reason, removeCallback);
```



## NotificationSubscribe.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason): Promise\<void\>

删除指定通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名            | 类型            | 必填 | 说明       |
| --------------- | --------------- | ---- | ---------- |
| bundle          | [BundleOption](#bundleoption)    | 是   | 指定应用的包信息。 |
| notificationKey | [NotificationKey](#notificationkey) | 是   | 通知键值。   |
| reason          | [RemoveReason](#removereason) | 是   | 通知删除原因。         |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
var reason = NotificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
NotificationSubscribe.remove(bundle, notificationKey, reason).then(() => {
	console.info("remove success");
});
```



## NotificationSubscribe.remove

remove(hashCode: string, reason: RemoveReason, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| hashCode | string                | 是   | 通知唯一ID。可以通过[onConsume](#onconsume)回调的入参[SubscribeCallbackData](#subscribecallbackdata)获取其内部[NotificationRequest](#notificationrequest)对象中的hashCode。 |
| reason   | [RemoveReason](#removereason) | 是   | 通知删除原因。         |
| callback | AsyncCallback\<void\> | 是   | 删除指定通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```js
var hashCode = 'hashCode'

function removeCallback(err) {
    if (err) {
        console.info("remove failed " + JSON.stringify(err));
    } else {
        console.info("remove success");
    }
}
var reason = NotificationSubscribe.RemoveReason.CANCEL_REASON_REMOVE;
NotificationSubscribe.remove(hashCode, reason, removeCallback);
```



## NotificationSubscribe.remove

remove(hashCode: string, reason: RemoveReason): Promise\<void\>

删除指定通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型       | 必填 | 说明       |
| -------- | ---------- | ---- | ---------- |
| hashCode | string | 是   | 通知唯一ID。 |
| reason   | [RemoveReason](#removereason) | 是   | 通知删除原因。         |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```js
var hashCode = 'hashCode'
var reason = NotificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
NotificationSubscribe.remove(hashCode, reason).then(() => {
	console.info("remove success");
});
```



## NotificationSubscribe.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

删除指定应用的所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名     | 类型                  | 必填 | 说明                         |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定应用的包信息。                   |
| callback | AsyncCallback\<void\> | 是   | 删除指定应用的所有通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function removeAllCallback(err) {
    if (err) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
NotificationSubscribe.removeAll(bundle, removeAllCallback);
```



## NotificationSubscribe.removeAll

removeAll(callback: AsyncCallback\<void\>): void

删除所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 删除所有通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function removeAllCallback(err) {
    if (err) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

NotificationSubscribe.removeAll(removeAllCallback);
```



## NotificationSubscribe.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

删除指定应用的所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 否   | 指定应用的包信息。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
// 不指定应用时，删除所有通知
NotificationSubscribe.removeAll().then(() => {
	console.info("removeAll success");
});
```

## NotificationSubscribe.removeAll

removeAll(userId: number, callback: AsyncCallback\<void>): void

删除指定用户下的所有通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 删除指定用户所有通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
function removeAllCallback(err) {
    if (err) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

var userId = 1

NotificationSubscribe.removeAll(userId, removeAllCallback);
```

## Notification.removeAll

removeAll(userId: number): Promise\<void>

删除指定用户下的所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 用户ID。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
function removeAllCallback(err) {
    if (err) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

var userId = 1

NotificationSubscribe.removeAll(userId, removeAllCallback);
```



## NotificationSubscriber

作为订阅通知接口[subscribe](#notificationsubscribe)的入参，提供订阅者接收到新通知、取消通知等的回调方法。

**系统API**：此接口为系统接口，三方应用不支持调用。

### onConsume

onConsume?: (data: [SubscribeCallbackData](#subscribecallbackdata)) => void

接收到新通知的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](#subscribecallbackdata) | 是 | 新接收到的通知信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onConsumeCallback(data) {
    console.info('===> onConsume in test');
    let req = data.request;
    console.info('===> onConsume callback req.id:' + req.id);
};

var subscriber = {
    onConsume: onConsumeCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onCancel

onCancel?:(data: [SubscribeCallbackData](#subscribecallbackdata)) => void

取消通知的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](#subscribecallbackdata) | 是 | 需要取消的通知信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
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

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onUpdate

onUpdate?:(data: [NotificationSortingMap](#notificationsortingmap)) => void

更新通知排序的回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](#notificationsortingmap) | 是 | 最新的通知排序列表。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onUpdateCallback(map) {
    console.info('===> onUpdateCallback map:' + JSON.stringify(map));
}

var subscriber = {
    onUpdate: onUpdateCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
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

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
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
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};
function unsubscribeCallback(err) {
    if (err.code) {
        console.info("unsubscribe failed " + JSON.stringify(err));
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

var subscriber = {
    onConnect: onConnectCallback,
    onDisconnect: onDisconnectCallback
};

// 订阅通知后会收到onConnect回调
NotificationSubscribe.subscribe(subscriber, subscribeCallback);
// 取消订阅后会收到onDisconnect回调
NotificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
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

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbDateChange

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
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onDoNotDisturbDateChangeCallback(mode) {
    console.info('===> onDoNotDisturbDateChange:' + mode);
}

var subscriber = {
    onDoNotDisturbDateChange: onDoNotDisturbDateChangeCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```


### onEnabledNotificationChanged

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](#enablednotificationcallbackdata)) => void

监听应用通知使能变化。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](#enablednotificationcallbackdata)\> | 是 | 回调返回监听到的应用信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onEnabledNotificationChangedCallback(callbackData) {
    console.info("bundle: ", callbackData.bundle);
    console.info("uid: ", callbackData.uid);
    console.info("enable: ", callbackData.enable);
};

var subscriber = {
    onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

## BundleOption

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称   | 类型   | 可读 | 可写 | 说明   |
| ------ | ------ |---- | --- |  ------ |
| bundle | string | 是  | 是  | 应用的包信息。 |
| uid    | number | 是  | 是  | 用户ID。 |

## NotificationKey

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称  | 类型   | 可读 | 可写 | 说明     |
| ----- | ------ | ---- | --- | -------- |
| id    | number | 是  | 是  | 通知ID。   |
| label | string | 是  | 是  | 通知标签。 |

## SubscribeCallbackData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称            | 类型                                              | 可读                                            | 可写                                            | 说明     |
| --------------- | ------------------------------------------------- | -------- | -------- | -------- |
| request         | [NotificationRequest](js-apis-notificationManager.md#notificationrequest) | 是 | 否 | 通知内容。 |
| sortingMap      | [NotificationSortingMap](#notificationsortingmap) | 是 | 否 | 排序信息。 |
| reason          | number                                            | 是                                           | 否                                           | 删除原因。 |
| sound           | string                                            | 是                                           | 否                                           | 通知声音。 |
| vibrationValues | Array\<number\>                                   | 是                                  | 否                                  | 通知震动。 |


## EnabledNotificationCallbackData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称   | 类型    | 可读  | 可写  | 描述             |
| ------ | ------- | ---------------- | ---------------- | ---------------- |
| bundle | string  | 是 | 否 | 应用的包名。       |
| uid    | number  | 是 | 否 | 应用的uid。        |
| enable | boolean | 是 | 否 | 应用通知使能状态。 |


## NotificationSorting

提供有关活动通知的排序信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称     | 类型                                  | 可读 | 可写 | 说明         |
| -------- | ------------------------------------- | ---- | --- | ------------ |
| slot     | [NotificationSlot](js-apis-notificationManager.md#notificationslot) | 是  | 否  | 通知通道内容。 |
| hashCode | string                                | 是  | 否  | 通知唯一标识。 |
| ranking  | number                                | 是  | 否  | 通知排序序号。 |


## NotificationSortingMap

提供关于已订阅的所有通知中活动通知的排序信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称           | 类型                                                         | 可读 | 可写 | 说明             |
| -------------- | ------------------------------------------------------------ | ---- | --- | ---------------- |
| sortings       | {[key: string]: [NotificationSorting](#notificationsorting)} | 是  | 否  | 通知排序信息数组。 |
| sortedHashCode | Array\<string\>                                              | 是  | 否  | 通知唯一标识数组。 |


## NotificationSubscribeInfo

设置订阅所需通知的发布者的信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称        | 类型            | 可读 | 可写 | 说明                            |
| ----------- | --------------- | --- | ---- | ------------------------------- |
| bundleNames | Array\<string\> | 是  | 是  | 指定订阅哪些包名的APP发来的通知。 |
| userId      | number          | 是  | 是  | 指定订阅哪个用户下发来的通知。    |


## NotificationUserInput

保存用户输入的通知消息。

**系统能力**：SystemCapability.Notification.Notification

| 名称     | 类型   | 可读 | 可写 | 说明                          |
| -------- | ------ | --- | ---- | ----------------------------- |
| inputKey | string | 是  | 是  | 用户输入时用于标识此输入的key。 |

## RemoveReason

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | 点击通知后删除通知。    |
| CANCEL_REASON_REMOVE | 2   | 用户删除通知。         |