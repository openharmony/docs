# @ohos.notificationSubscribe (NotificationSubscribe模块)(系统接口)

本模块提供通知订阅、取消订阅、通知移除等，一般情况下，只有系统应用具有这些操作权限。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口均为系统接口。

## 导入模块

```ts
import { notificationSubscribe } from '@kit.NotificationKit';
```

## notificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

订阅通知并指定订阅信息。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber)    | 是   | 通知订阅对象。     |
| info       | [NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo) | 是   | 通知订阅信息。 |
| callback   | AsyncCallback\<void\>     | 是   | 订阅动作回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                             |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

//subscribe回调
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
//不会对bundleNames进行校验，开发者自己确定需要订阅哪些bundleName
let info: notificationSubscribe.NotificationSubscribeInfo = {
  bundleNames: ["bundleName1","bundleName2"]
};
notificationSubscribe.subscribe(subscriber, info, subscribeCallback);
```

## notificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

订阅当前用户下所有应用的通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                   | 必填 | 说明             |
| ---------- | ---------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | 是   | 通知订阅对象。     |
| callback   | AsyncCallback\<void\>  | 是   | 订阅动作回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

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

订阅通知并指定订阅信息。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                      | 必填 | 说明         |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber)    | 是   | 通知订阅对象。 |
| info       | [NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo) | 否   | 通知订阅信息，默认为空（当为空时，表示订阅当前用户下所有应用的通知，否则表示订阅通知并指定订阅信息）。   |

**返回值：**

| 类型     | 说明               | 
| ------- |------------------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

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

订阅本应用的通知并指定订阅信息。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                      | 必填 | 说明         |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber)    | 是   | 通知订阅对象。 |

**返回值：**

| 类型     | 说明               | 
| ------- |------------------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- | 
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

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

取消订阅。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                   | 必填 | 说明                 |
| ---------- | ---------------------- | ---- | -------------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | 是   | 通知订阅对象。         |
| callback   | AsyncCallback\<void\>  | 是   | 取消订阅动作回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

取消订阅。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                   | 必填 | 说明         |
| ---------- | ---------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | 是   | 通知订阅对象。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

根据应用的包信息和通知键值，删除指定通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名            | 类型                                | 必填 | 说明                 |
| --------------- |   ----------------------------------| ---- | -------------------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)       | 是   | 指定应用的包信息。           |
| notificationKey | [NotificationKey](#notificationkey) | 是   | 通知键值。             |
| reason          | [RemoveReason](#removereason)      | 是   | 通知删除原因。         |
| callback        | AsyncCallback\<void\>               | 是   | 删除指定通知回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

根据应用的包信息和通知键值，删除指定通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名            | 类型            | 必填 | 说明       |
| --------------- | --------------- | ---- | ---------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)    | 是   | 指定应用的包信息。 |
| notificationKey | [NotificationKey](#notificationkey) | 是   | 通知键值。   |
| reason          | [RemoveReason](#removereason) | 是   | 通知删除原因。         |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

通过通知的唯一ID，删除指定通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| hashCode | string                | 是   | 通知唯一ID。可以通过[onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume)回调的入参[SubscribeCallbackData](js-apis-inner-notification-notificationSubscriber-sys.md#subscribecallbackdata)获取其内部[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)对象中的hashCode。 |
| reason   | [RemoveReason](#removereason) | 是   | 通知删除原因。         |
| callback | AsyncCallback\<void\> | 是   | 删除指定通知回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

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

通过通知的唯一ID，删除指定通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型       | 必填 | 说明       |
| -------- | ---------- | ---- | ---------- |
| hashCode | string | 是   | 通知唯一ID。可以通过[onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume)回调的入参[SubscribeCallbackData](js-apis-inner-notification-notificationSubscriber-sys.md#subscribecallbackdata)获取其内部[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)对象中的hashCode。 |
| reason   | [RemoveReason](#removereason) | 是   | 通知删除原因。         |

**返回值：**

| 类型     | 说明 | 
| ------- |--|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

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

批量删除指定通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                            | 必填 | 说明                                                                                                                                                                                                                                                                                  |
|-----------|-------------------------------| ---- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| hashCodes | Array\<String\>               | 是   | 通知唯一ID数组集合。可以通过[onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume)回调的入参[SubscribeCallbackData](js-apis-inner-notification-notificationSubscriber-sys.md#subscribecallbackdata)获取其内部[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)对象中的hashCode。 |
| reason    | [RemoveReason](#removereason) | 是   | 通知删除原因。                                                                                                                                                                                                                                                                             |
| callback  | AsyncCallback\<void\>         | 是   | 删除指定通知回调函数。                                                                                                                                                                                                                                                                         |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

批量删除指定通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                            | 必填 | 说明          |
|-----------|-------------------------------| ---- |-------------|
| hashCodes | Array\<String\>               | 是   | 通知唯一ID数组集合。 |
| reason    | [RemoveReason](#removereason) | 是   | 通知删除原因。     |

**返回值：**

| 类型     | 说明               | 
| ------- |------------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

删除指定应用的所有通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                         |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)        | 是   | 指定应用的包信息。                   |
| callback | AsyncCallback\<void\> | 是   | 删除指定应用的所有通知回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

删除所有通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 删除所有通知回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

删除指定应用的所有通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 否   | 指定应用的包信息。默认为空，表示删除所有通知。 |

**返回值：**

| 类型     | 说明         | 
| ------- |------------|
| Promise\<void\> | 无返回结果的Promise对象。 |  

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 不指定应用时，删除所有通知
notificationSubscribe.removeAll().then(() => {
	console.info("removeAll success");
}).catch((err: BusinessError) => {
  console.error("removeAll fail: " + JSON.stringify(err));
});
```

## notificationSubscribe.removeAll

removeAll(userId: number, callback: AsyncCallback\<void>): void

删除指定用户下的所有通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 删除指定用户所有通知回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let removeAllCallback = (err: BusinessError) => {
  if (err) {
    console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("removeAll success");
  }
}
// 用户ID，使用时需替换为真实的userId。
let userId: number = 1;
notificationSubscribe.removeAll(userId, removeAllCallback);
```

## notificationSubscribe.removeAll

removeAll(userId: number): Promise\<void>

删除指定用户下的所有通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 用户ID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let userId: number = 1;
notificationSubscribe.removeAll(userId).then(() => {
	console.info("removeAll success");
}).catch((err: BusinessError) => {
  console.error("removeAll fail: " + JSON.stringify(err));
});
```

## NotificationKey

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

| 名称  | 类型   | 必填 | 说明     |
| ----- | ------ | --- | -------- |
| id    | number | 是  | 通知ID。   |
| label | string | 否  | 通知标签，默认为空。 |

## RemoveReason

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | 点击通知后删除通知。    |
| CANCEL_REASON_REMOVE | 2   | 用户删除通知。         |
