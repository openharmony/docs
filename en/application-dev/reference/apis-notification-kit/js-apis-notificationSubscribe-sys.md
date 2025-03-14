# @ohos.notificationSubscribe (NotificationSubscribe) (System API)

The **notificationSubscribe** module provides APIs for notification subscription, notification unsubscription, subscription removal, and more. In general cases, only system applications can call these APIs.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { notificationSubscribe } from '@kit.NotificationKit';
```

## notificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

Subscribes to a notification with the subscription information specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name      | Type                     | Mandatory| Description            |
| ---------- | ------------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber)    | Yes  | Notification subscriber.    |
| info       | [NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo) | Yes  | Notification subscription information.|
| callback   | AsyncCallback\<void\>     | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// subscribe callback
let subscribeCallback = (err: BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribe success");
  }
}
let onConsumeCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: notificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
// Bundle names are not verified. You need to determine the target bundle names.
let info: notificationSubscribe.NotificationSubscribeInfo = {
  bundleNames: ["bundleName1","bundleName2"]
};
notificationSubscribe.subscribe(subscriber, info, subscribeCallback);
```

## notificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

Subscribes to notifications of all applications under this user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name      | Type                  | Mandatory| Description            |
| ---------- | ---------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | Yes  | Notification subscriber.    |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let subscribeCallback = (err: BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribe success");
  }
}
let onConsumeCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: notificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
notificationSubscribe.subscribe(subscriber, subscribeCallback);
```



## notificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo): Promise\<void\>

Subscribes to a notification with the subscription information specified. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name      | Type                     | Mandatory| Description        |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber)    | Yes  | Notification subscriber.|
| info       | [NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo) | No  | Notification subscription information. By default, this parameter is left empty, which means to subscribe to notifications of all applications under this user.  |

**Return value**

| Type    | Description              | 
| ------- |------------------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onConsumeCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: notificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
notificationSubscribe.subscribe(subscriber).then(() => {
  console.info("subscribe success");
}).catch((err: BusinessError) => {
  console.error("subscribe fail: " + JSON.stringify(err));
});
```


## notificationSubscribe.subscribeSelf<sup>11+</sup>

subscribeSelf(subscriber: NotificationSubscriber): Promise\<void\>

Subscribes to notifications of the application and specifies subscription information. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

**Parameters**

| Name      | Type                     | Mandatory| Description        |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber)    | Yes  | Notification subscriber.|

**Return value**

| Type    | Description              | 
| ------- |------------------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- | 
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onConsumeCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: notificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
notificationSubscribe.subscribeSelf(subscriber).then(() => {
  console.info("subscribeSelf success");
}).catch((err: BusinessError) => {
  console.error("subscribeSelf fail: " + JSON.stringify(err));
});
```



## notificationSubscribe.unsubscribe

unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

Unsubscribes from a notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name      | Type                  | Mandatory| Description                |
| ---------- | ---------------------- | ---- | -------------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | Yes  | Notification subscriber.        |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let unsubscribeCallback = (err: BusinessError) => {
  if (err) {
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("unsubscribe success");
  }
}
let onDisconnectCallback = () => {
  console.info("subscribe disconnect");
}
let subscriber: notificationSubscribe.NotificationSubscriber = {
  onDisconnect: onDisconnectCallback
};
notificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
```

## notificationSubscribe.unsubscribe

unsubscribe(subscriber: NotificationSubscriber): Promise\<void\>

Unsubscribes from a notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name      | Type                  | Mandatory| Description        |
| ---------- | ---------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | Yes  | Notification subscriber.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onDisconnectCallback = () => {
  console.info("subscribe disconnect");
}
let subscriber: notificationSubscribe.NotificationSubscriber = {
  onDisconnect: onDisconnectCallback
};
notificationSubscribe.unsubscribe(subscriber).then(() => {
  console.info("unsubscribe success");
}).catch((err: BusinessError) => {
  console.error("unsubscribe fail: " + JSON.stringify(err));
});
```

## notificationSubscribe.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason, callback: AsyncCallback\<void\>): void

Removes a notification based on the bundle information and notification key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name           | Type                               | Mandatory| Description                |
| --------------- |   ----------------------------------| ---- | -------------------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)       | Yes  | Bundle information of the application.          |
| notificationKey | [NotificationKey](#notificationkey) | Yes  | Notification key.            |
| reason          | [RemoveReason](#removereason)      | Yes  | Reason for removing the notification.        |
| callback        | AsyncCallback\<void\>               | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { notificationManager } from '@kit.NotificationKit';

let removeCallback = (err: BusinessError) => {
  if (err) {
    console.error(`remove failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("remove success");
  }
}
let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: notificationSubscribe.NotificationKey = {
  id: 0,
  label: "label",
};
let reason: notificationSubscribe.RemoveReason = notificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(bundle, notificationKey, reason, removeCallback);
```



## notificationSubscribe.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason): Promise\<void\>

Removes a notification based on the bundle information and notification key. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name           | Type           | Mandatory| Description      |
| --------------- | --------------- | ---- | ---------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)    | Yes  | Bundle information of the application.|
| notificationKey | [NotificationKey](#notificationkey) | Yes  | Notification key.  |
| reason          | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.        |

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { notificationManager } from '@kit.NotificationKit';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: notificationSubscribe.NotificationKey = {
  id: 0,
  label: "label",
};
let reason: notificationSubscribe.RemoveReason = notificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(bundle, notificationKey, reason).then(() => {
  console.info("remove success");
}).catch((err: BusinessError) => {
  console.error("remove fail: " + JSON.stringify(err));
});
```

## notificationSubscribe.remove

remove(hashCode: string, reason: RemoveReason, callback: AsyncCallback\<void\>): void

Removes a notification based on the specified unique notification ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| hashCode | string                | Yes  | Unique notification ID. It is the value of **hashCode** in the [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) object of [SubscribeCallbackData](js-apis-inner-notification-notificationSubscriber-sys.md#subscribecallbackdata) in the [onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume) callback.|
| reason   | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification is not exist.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let hashCode: string = 'hashCode';
let removeCallback = (err: BusinessError) => {
  if (err) {
    console.error(`remove failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("remove success");
  }
}
let reason: notificationSubscribe.RemoveReason = notificationSubscribe.RemoveReason.CANCEL_REASON_REMOVE;
notificationSubscribe.remove(hashCode, reason, removeCallback);
```

## notificationSubscribe.remove

remove(hashCode: string, reason: RemoveReason): Promise\<void\>

Removes a notification based on the specified unique notification ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type      | Mandatory| Description      |
| -------- | ---------- | ---- | ---------- |
| hashCode | string | Yes  | Unique notification ID. It is the value of **hashCode** in the [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) object of [SubscribeCallbackData](js-apis-inner-notification-notificationSubscriber-sys.md#subscribecallbackdata) in the [onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume) callback.|
| reason   | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.        |

**Return value**

| Type    | Description| 
| ------- |--|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification is not exist.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let hashCode: string = 'hashCode';
let reason: notificationSubscribe.RemoveReason = notificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(hashCode, reason).then(() => {
	console.info("remove success");
}).catch((err: BusinessError) => {
  console.error("remove fail: " + JSON.stringify(err));
});
```

## notificationSubscribe.remove<sup>10+</sup>

remove(hashCodes: Array\<String\>, reason: RemoveReason, callback: AsyncCallback\<void\>): void

Removes specified notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name      | Type                           | Mandatory| Description                                                                                                                                                                                                                                                                                 |
|-----------|-------------------------------| ---- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| hashCodes | Array\<String\>               | Yes  | Array of unique notification IDs. It is the value of **hashCode** in the [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) object of [SubscribeCallbackData](js-apis-inner-notification-notificationSubscriber-sys.md#subscribecallbackdata) in the [onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume) callback.|
| reason    | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.                                                                                                                                                                                                                                                                            |
| callback  | AsyncCallback\<void\>         | Yes  | Callback used to return the result.                                                                                                                                                                                                                                                                        |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let hashCodes: string[] = ['hashCode1', 'hashCode2'];
let removeCallback = (err: BusinessError) => {
  if (err) {
    console.error(`remove failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("remove success");
  }
}
let reason: notificationSubscribe.RemoveReason = notificationSubscribe.RemoveReason.CANCEL_REASON_REMOVE;
notificationSubscribe.remove(hashCodes, reason, removeCallback);
```

## notificationSubscribe.remove<sup>10+</sup>

remove(hashCodes: Array\<String\>, reason: RemoveReason): Promise\<void\>

Removes specified notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name      | Type                           | Mandatory| Description         |
|-----------|-------------------------------| ---- |-------------|
| hashCodes | Array\<String\>               | Yes  | Array of unique notification IDs.|
| reason    | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.    |

**Return value**

| Type    | Description              | 
| ------- |------------------|
| Promise\<void\> | Promise that returns no value.|  

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let hashCodes: string[] = ['hashCode1','hashCode2'];
let reason: notificationSubscribe.RemoveReason = notificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(hashCodes, reason).then(() => {
  console.info("remove success");
}).catch((err: BusinessError) => {
  console.error("remove fail: " + JSON.stringify(err));
});
```

## notificationSubscribe.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

Removes all notifications for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                        |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)        | Yes  | Bundle information of the application.                  |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let removeAllCallback = (err: BusinessError) => {
  if (err) {
    console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("removeAll success");
  }
}
let bundle: notificationSubscribe.BundleOption = {
  bundle: "bundleName1",
};
notificationSubscribe.removeAll(bundle, removeAllCallback);
```

## notificationSubscribe.removeAll

removeAll(callback: AsyncCallback\<void\>): void

Removes all notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let removeAllCallback = (err: BusinessError) => {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}
notificationSubscribe.removeAll(removeAllCallback);
```

## notificationSubscribe.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

Removes all notifications for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | No  | Bundle information of the application. By default, this parameter is left empty, indicating that all notifications will be removed.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// If no application is specified, notifications of all applications are deleted.
notificationSubscribe.removeAll().then(() => {
	console.info("removeAll success");
}).catch((err: BusinessError) => {
  console.error("removeAll fail: " + JSON.stringify(err));
});
```

## notificationSubscribe.removeAll

removeAll(userId: number, callback: AsyncCallback\<void>): void

Removes all notifications for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| userId | number | Yes  | User ID.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let removeAllCallback = (err: BusinessError) => {
  if (err) {
    console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("removeAll success");
  }
}
// Use the actual user ID when calling the API.
let userId: number = 1;
notificationSubscribe.removeAll(userId, removeAllCallback);
```

## notificationSubscribe.removeAll

removeAll(userId: number): Promise\<void>

Removes all notifications for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| userId | number | Yes  | User ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let userId: number = 1;
notificationSubscribe.removeAll(userId).then(() => {
	console.info("removeAll success");
}).catch((err: BusinessError) => {
  console.error("removeAll fail: " + JSON.stringify(err));
});
```

## notificationSubscribe.distributeOperation<sup>18+</sup>

distributeOperation(hashcode: string, operationInfo?: OperationInfo): Promise\<void>

Triggers a notification for cross-device operations, such as tap-to-redirect and quick reply. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| hashcode | string | Yes  | Unique notification ID.|
| operationInfo | [OperationInfo](#operationinfo18) | Yes  | Cross-device operation information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600010  | Distributed operation failed.                     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let hashcode: string = 'hashcode';
let operationInfo: notificationSubscribe.OperationInfo = {
  actionName: "actionName",
  userInput: "userInput",
};
notificationSubscribe.distributeOperation(hashcode, operationInfo).then(() => {
	console.info("distributeOperation success");
}).catch((err: BusinessError) => {
  console.error("distributeOperation fail: " + JSON.stringify(err));
});
```

## NotificationKey

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name | Type  | Mandatory| Description    |
| ----- | ------ | --- | -------- |
| id    | number | Yes | Notification ID.  |
| label | string | No | Notification label. This parameter is left empty by default.|

## RemoveReason

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | The notification is removed after a click on it.   |
| CANCEL_REASON_REMOVE | 2   | The notification is removed by the user.        |

## OperationInfo<sup>18+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name | Type  | Mandatory| Description    |
| ----- | ------ | --- | -------- |
| actionName    | string | Yes | Operation button displayed in the notification. The value must be the same as that of **title** in [NotificationActionButton](js-apis-inner-notification-notificationActionButton.md#notificationactionbutton).  |
| userInput | string | No | User input, used to apply quick reply across devices. The value must be the same as that of **inputKey** in [NotificationUserInput](js-apis-inner-notification-notificationUserInput.md#notificationuserinput).|
