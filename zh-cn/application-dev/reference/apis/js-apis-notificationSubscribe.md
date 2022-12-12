# NotificationSubscribe模块

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

| 名称       | 类型                      | 必填 | 描述             |
| ---------- | ------------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | 是   | 通知订阅对象。     |
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | 是   | 订阅信息。         |
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

订阅通知并指定订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称       | 类型                   | 必填 | 描述             |
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

| 名称       | 类型                      | 必填 | 描述         |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | 是   | 通知订阅对象。 |
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | 否   | 订阅信息。     |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function onConsumeCallback(data) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe success");
    }
}
var subscriber = {
    onConsume: onConsumeCallback
};
NotificationSubscribe.subscribe(subscriber).then(() => {
	console.info("subscribe sucess");
});
```



## NotificationSubscribe.unsubscribe

unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

取消订阅（callbcak形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称       | 类型                   | 必填 | 描述                 |
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
function onCancelCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onCancel: onCancelCallback
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

| 名称       | 类型                   | 必填 | 描述         |
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
function onCancelCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onCancel: onCancelCallback
};
NotificationSubscribe.unsubscribe(subscriber).then(() => {
	console.info("unsubscribe sucess");
});
```



## NotificationSubscribe.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称            | 类型                                | 必填 | 说明                 |
| --------------- |   ----------------------------------| ---- | -------------------- |
| bundle          | [BundleOption](#bundleoption)       | 是   | 指定包信息。           |
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

| 名称            | 类型            | 必填 | 说明       |
| --------------- | --------------- | ---- | ---------- |
| bundle          | [BundleOption](#bundleoption)    | 是   | 指定包信息。 |
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
	console.info("remove sucess");
});
```



## NotificationSubscribe.remove

remove(hashCode: string, reason: RemoveReason, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| hashCode | string                | 是   | 通知唯一ID。           |
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

| 名称     | 类型       | 必填 | 说明       |
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
	console.info("remove sucess");
});
```



## NotificationSubscribe.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

删除指定包的所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 名称     | 类型                  | 必填 | 描述                         |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。                   |
| callback | AsyncCallback\<void\> | 是   | 删除指定包的所有通知回调函数。 |

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

| 名称     | 类型                  | 必填 | 描述                 |
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

删除所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 否   | 指定包信息。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
NotificationSubscribe.removeAll().then(() => {
	console.info("removeAll sucess");
});
```

## NotificationSubscribe.removeAll

removeAll(userId: number, callback: AsyncCallback\<void>): void

删除所有通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 接收通知用户的Id。 |
| callback | AsyncCallback\<void\> | 是   | 删除所有通知回调函数。 |

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

删除所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 接收通知用户的Id。 |

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

提供订阅者接收到新通知或取消通知时的回调方法。

**系统API**：此接口为系统接口，三方应用不支持调用。

### onConsume

onConsume?: (data: [SubscribeCallbackData](#subscribecallbackdata)) => void

接收通知回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](#subscribecallbackdata) | 是 | 回调返回接收到的通知信息。 |

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

删除通知回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](#subscribecallbackdata) | 是 | 回调返回接收到的通知信息。 |

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

更新通知排序回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](#notificationsortingmap) | 是 | 回调返回接收到的通知信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err) {
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

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onConnect

onConnect?:() => void

注册订阅回调函数。

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

取消订阅回调函数。

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

function onDisconnectCallback() {
    console.info('===> onDisconnect in test');
}

var subscriber = {
    onDisconnect: onDisconnectCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
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

免打扰时间选项变更回调函数。

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

function onDoNotDisturbDateChangeCallback() {
    console.info('===> onDoNotDisturbDateChange in test');
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

| 名称   | 可读 | 可写 | 类型   | 说明     |
| ------ | ---- | ---- | ------ | -------- |
| bundle | 是   | 是   | string | 包名。   |
| uid    | 是   | 是   | number | 用户id。 |

## NotificationKey

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称  | 可读 | 可写 | 类型   | 说明       |
| ----- | ---- | ---- | ------ | ---------- |
| id    | 是   | 是   | number | 通知ID。   |
| label | 是   | 是   | string | 通知标签。 |

## SubscribeCallbackData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称            | 可读 | 可写 | 类型                                              | 说明     |
| --------------- | ---- | --- | ------------------------------------------------- | -------- |
| request         | 是  | 否  | [NotificationRequest](js-apis-notificationManager.md#notificationrequest) | 通知内容。 |
| sortingMap      | 是  | 否  | [NotificationSortingMap](#notificationsortingmap) | 排序信息。 |
| reason          | 是  | 否  | number                                            | 删除原因。 |
| sound           | 是  | 否  | string                                            | 通知声音。 |
| vibrationValues | 是  | 否  | Array\<number\>                                   | 通知震动。 |


## EnabledNotificationCallbackData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称   | 可读 | 可写 | 类型    | 描述             |
| ------ | ---- | --- | ------- | ---------------- |
| bundle | 是  | 否  | string  | 应用的包名。       |
| uid    | 是  | 否  | number  | 应用的uid。        |
| enable | 是  | 否  | boolean | 应用通知使能状态。 |


## NotificationSorting

提供有关活动通知的排序信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称     | 可读 | 可写 | 类型                                  | 说明         |
| -------- | ---- | --- | ------------------------------------- | ------------ |
| slot     | 是  | 否  | [NotificationSlot](js-apis-notificationManager.md#notificationslot) | 通知通道内容。 |
| hashCode | 是  | 否  | string                                | 通知唯一标识。 |
| ranking  | 是  | 否  | number                                | 通知排序序号。 |


## NotificationSortingMap

提供关于已订阅的所有通知中活动通知的排序信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称           | 可读 | 可写 | 类型                                                         | 说明             |
| -------------- | ---- | --- | ------------------------------------------------------------ | ---------------- |
| sortings       | 是  | 否  | {[key: string]: [NotificationSorting](#notificationsorting)} | 通知排序信息数组。 |
| sortedHashCode | 是  | 否  | Array\<string\>                                              | 通知唯一标识数组。 |


## NotificationSubscribeInfo

设置订阅所需通知的发布者的信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称        | 可读 | 可写 | 类型            | 描述                            |
| ----------- | --- | ---- | --------------- | ------------------------------- |
| bundleNames | 是  | 是  | Array\<string\> | 指定订阅哪些包名的APP发来的通知。 |
| userId      | 是  | 是  | number          | 指定订阅哪个用户下发来的通知。    |


## NotificationUserInput

保存用户输入的通知消息。

**系统能力**：SystemCapability.Notification.Notification

| 名称     | 可读 | 可写 | 类型   | 描述                          |
| -------- | --- | ---- | ------ | ----------------------------- |
| inputKey | 是  | 是  | string | 用户输入时用于标识此输入的key。 |

## RemoveReason

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 描述                  |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | 点击通知后删除通知。    |
| CANCEL_REASON_REMOVE | 2   | 用户删除通知。         |