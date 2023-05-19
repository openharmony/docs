# @ohos.notificationSubscribe (NotificationSubscribe模块)

本模块提供通知订阅、取消订阅、通知移除等，一般情况下，只有系统应用具有这些操作权限。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import notificationSubscribe from '@ohos.notificationSubscribe';
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
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber)    | 是   | 通知订阅对象。     |
| info       | [NotificationSubscribeInfo](js-apis-notification.md#notificationsubscribeinfo) | 是   | 通知订阅信息。 |
| callback   | AsyncCallback\<void\>     | 是   | 订阅动作回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

```js
//subscribe回调
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber = {
    onConsume: onConsumeCallback
};
let info = {
    bundleNames: ["bundleName1","bundleName2"]
};
notificationSubscribe.subscribe(subscriber, info, subscribeCallback);
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
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber) | 是   | 通知订阅对象。     |
| callback   | AsyncCallback\<void\>  | 是   | 订阅动作回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

```js
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber = {
    onConsume: onConsumeCallback
};
notificationSubscribe.subscribe(subscriber, subscribeCallback);
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
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber)    | 是   | 通知订阅对象。 |
| info       | [NotificationSubscribeInfo](js-apis-notification.md#notificationsubscribeinfo) | 否   | 通知订阅信息。   |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

```js
function onConsumeCallback(data) {
    console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber = {
    onConsume: onConsumeCallback
};
notificationSubscribe.subscribe(subscriber).then(() => {
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
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber) | 是   | 通知订阅对象。         |
| callback   | AsyncCallback\<void\>  | 是   | 取消订阅动作回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function unsubscribeCallback(err) {
    if (err) {
        console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("unsubscribe success");
    }
}
function onDisconnectCallback() {
	console.info("subscribe disconnect");
}
let subscriber = {
    onDisconnect: onDisconnectCallback
};
notificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
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
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber) | 是   | 通知订阅对象。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function onDisconnectCallback() {
	console.info("subscribe disconnect");
}
let subscriber = {
    onDisconnect: onDisconnectCallback
};
notificationSubscribe.unsubscribe(subscriber).then(() => {
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
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)       | 是   | 指定应用的包信息。           |
| notificationKey | [NotificationKey](js-apis-notification.md#notificationkey) | 是   | 通知键值。             |
| reason          | [RemoveReason](#removereason)      | 是   | 通知删除原因。         |
| callback        | AsyncCallback\<void\>               | 是   | 删除指定通知回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function removeCallback(err) {
    if (err) {
        console.error(`remove failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("remove success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
let notificationKey = {
    id: 0,
    label: "label",
};
let reason = notificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(bundle, notificationKey, reason, removeCallback);
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
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)    | 是   | 指定应用的包信息。 |
| notificationKey | [NotificationKey]((js-apis-notification.md#notificationkey)) | 是   | 通知键值。   |
| reason          | [RemoveReason](#removereason) | 是   | 通知删除原因。         |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
let bundle = {
    bundle: "bundleName1",
};
let notificationKey = {
    id: 0,
    label: "label",
};
let reason = NotificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(bundle, notificationKey, reason).then(() => {
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
| hashCode | string                | 是   | 通知唯一ID。可以通过[onConsume](#onconsume)回调的入参[SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata)获取其内部[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)对象中的hashCode。 |
| reason   | [RemoveReason](#removereason) | 是   | 通知删除原因。         |
| callback | AsyncCallback\<void\> | 是   | 删除指定通知回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```js
let hashCode = 'hashCode';

function removeCallback(err) {
    if (err) {
        console.error(`remove failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("remove success");
    }
}
let reason = NotificationSubscribe.RemoveReason.CANCEL_REASON_REMOVE;
notificationSubscribe.remove(hashCode, reason, removeCallback);
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

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```js
let hashCode = 'hashCode';
let reason = notificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(hashCode, reason).then(() => {
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
| bundle   | [BundleOption]((js-apis-inner-notification-notificationCommonDef.md#bundleoption))          | 是   | 指定应用的包信息。                   |
| callback | AsyncCallback\<void\> | 是   | 删除指定应用的所有通知回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function removeAllCallback(err) {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
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

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function removeAllCallback(err) {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}

notificationSubscribe.removeAll(removeAllCallback);
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
| bundle | [BundleOption]((js-apis-inner-notification-notificationCommonDef.md#bundleoption)) | 否   | 指定应用的包信息。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
// 不指定应用时，删除所有通知
notificationSubscribe.removeAll().then(() => {
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

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
function removeAllCallback(err) {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}

let userId = 1;

notificationSubscribe.removeAll(userId, removeAllCallback);
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

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
function removeAllCallback(err) {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}

let userId = 1;

notificationSubscribe.removeAll(userId, removeAllCallback);
```

## NotificationSubscriber

作为订阅通知接口[subscribe](#notificationsubscribe)的入参，提供订阅者接收到新通知、取消通知等的回调方法。

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
| data | [NotificationSortingMap](js-apis-notification.md#notificationsortingmap)) | 是 | 最新的通知排序列表。 |

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


### onEnabledNotificationChanged

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

 onBadgeChanged?:(data: [BadgeNumberCallbackData](#badgenumbercallbackdata)) => void

监听应用角标个数变化。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[BadgeNumberCallbackData](#badgenumbercallbackdata)\> | 是   | 回调返回监听到的应用信息。 |

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


## RemoveReason

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | 点击通知后删除通知。    |
| CANCEL_REASON_REMOVE | 2   | 用户删除通知。         |

## BadgeNumberCallbackData<sup>10+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称        | 类型   | 可读 | 可写 | 描述         |
| ----------- | ------ | ---- | ---- | ------------ |
| bundle      | string | 是   | 否   | 应用的包名。 |
| uid         | number | 是   | 否   | 应用的uid。  |
| badgeNumber | number | 是   | 否   | 角标个数。   |
