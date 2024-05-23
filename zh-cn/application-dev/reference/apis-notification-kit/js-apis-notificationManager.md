# @ohos.notificationManager (NotificationManager模块)

本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知渠道，获取通知的使能状态、角标使能状态，获取通知的相关信息等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import notificationManager from '@ohos.notificationManager';
```

## notificationManager.publish

publish(request: NotificationRequest, callback: AsyncCallback\<void\>): void

发布通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| callback | AsyncCallback\<void\>                       | 是   | 发布通知的回调方法。                        |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                              |
| -------- | ---------------------------------------------------- |
| 1600001  | Internal error.                                      |
| 1600002  | Marshalling or unmarshalling error.                  |
| 1600003  | Failed to connect service.                           |
| 1600004  | Notification is not enabled.                         |
| 1600005  | Notification slot is not enabled.                    |
| 1600007  | The notification is not exist.                       |
| 1600009  | Over max number notifications per second.            |
| 1600012  | No memory space.                                     |
| 1600014  | No relevant right.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 2300007  | Network is unreachable.                              |

**示例：**

```ts
import Base from '@ohos.base';

//publish回调
let publishCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish success");
    }
}
//通知Request对象
let notificationRequest: notificationManager.NotificationRequest = {
    id: 1,
    content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};
notificationManager.publish(notificationRequest, publishCallback);
```

## notificationManager.publish

publish(request: NotificationRequest): Promise\<void\>

发布通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |

**返回值：**

| 类型     | 说明 | 
| ------- |--|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                              |
| -------- | ---------------------------------------------------- |
| 1600001  | Internal error.                                      |
| 1600002  | Marshalling or unmarshalling error.                  |
| 1600003  | Failed to connect service.                           |
| 1600004  | Notification is not enabled.                         |
| 1600005  | Notification slot is not enabled.                    |
| 1600007  | The notification is not exist.                       |
| 1600009  | Over max number notifications per second.            |
| 1600012  | No memory space.                                     |
| 1600014  | No relevant right.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 2300007  | Network is unreachable.                              |

**示例：**

```ts
import Base from '@ohos.base';

// 通知Request对象
let notificationRequest: notificationManager.NotificationRequest = {
    id: 1,
    content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};
notificationManager.publish(notificationRequest).then(() => {
	console.info("publish success");
}).catch((err: Base.BusinessError) => {
    console.error(`publish fail: ${JSON.stringify(err)}`);
});

```

## notificationManager.cancel

cancel(id: number, label: string, callback: AsyncCallback\<void\>): void

通过通知ID和通知标签取消已发布的通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | 是   | 通知ID。               |
| label    | string                | 是   | 通知标签。             |
| callback | AsyncCallback\<void\> | 是   | 表示被指定通知的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```ts
import Base from '@ohos.base';

// cancel回调
let cancelCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancel failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancel success");
    } 
}
notificationManager.cancel(0, "label", cancelCallback);
```

## notificationManager.cancel

cancel(id: number, label?: string): Promise\<void\>

通过通知ID和通知标签取消已发布的通知，若label为空表示取消与指定通知ID相匹配的已发布通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名  | 类型   | 必填 | 说明     |
| ----- | ------ | ---- | -------- |
| id    | number | 是   | 通知ID。   |
| label | string | 否   | 通知标签，默认为空。 |

**返回值：**

| 类型     | 说明        | 
| ------- |-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.cancel(0).then(() => {
	console.info("cancel success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancel fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.cancel

cancel(id: number, callback: AsyncCallback\<void\>): void

取消与指定通知ID相匹配的已发布通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | 是   | 通知ID。               |
| callback | AsyncCallback\<void\> | 是   | 表示被指定通知的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```ts
import Base from '@ohos.base';

// cancel回调
let cancelCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancel failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancel success");
    }
}
notificationManager.cancel(0, cancelCallback);
```

## notificationManager.cancelAll

cancelAll(callback: AsyncCallback\<void\>): void

取消当前应用所有已发布的通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 表示被指定通知的回调方法。 |

**示例：**

```ts
import Base from '@ohos.base';

// cancel回调
let cancelAllCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancelAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelAll success");
    }
}
notificationManager.cancelAll(cancelAllCallback);
```

## notificationManager.cancelAll

cancelAll(): Promise\<void\>

取消当前应用所有已发布的通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型     | 说明        | 
| ------- |-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.cancelAll().then(() => {
	console.info("cancelAll success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancelAll fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.addSlot

addSlot(type: SlotType, callback: AsyncCallback\<void\>): void

创建指定类型的通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | [SlotType](#slottype)              | 是   | 要创建的通知渠道的类型。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定通道的回调方法。   |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

```ts
import Base from '@ohos.base';

// addslot回调
let addSlotCallBack = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlot success");
    }
}
notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack);
```

## notificationManager.addSlot

addSlot(type: SlotType): Promise\<void\>

创建指定类型的通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型     | 必填 | 说明                   |
| ---- | -------- | ---- | ---------------------- |
| type | [SlotType](#slottype) | 是   | 要创建的通知渠道的类型。 |

**返回值：**

| 类型     | 说明        | 
| ------- |-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION).then(() => {
	console.info("addSlot success");
}).catch((err: Base.BusinessError) => {
    console.error(`addSlot fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlot

getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void

获取一个指定类型的通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                                        |
| -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)                          | 是   | 通知渠道类型，目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | AsyncCallback\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | 是   | 表示被指定通道的回调方法。                                        |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

// getSlot回调
let getSlotCallback = (err: Base.BusinessError, data: notificationManager.NotificationSlot): void => {
    if (err) {
        console.error(`getSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getSlot success, data is ${JSON.stringify(data)}`);
    }
}
let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.getSlot(slotType, getSlotCallback);
```

## notificationManager.getSlot

getSlot(slotType: SlotType): Promise\<NotificationSlot\>

获取一个指定类型的通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | 是   | 通知渠道类型，目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | 以Promise形式返回获取一个通知渠道。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;

notificationManager.getSlot(slotType).then((data: notificationManager.NotificationSlot) => {
    console.info("getSlot success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlot fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlots

getSlots(callback: AsyncCallback\<Array\<NotificationSlot>>): void

获取此应用程序的所有通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                              | 必填 | 说明                 |
| -------- | --------------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\>\> | 是   | 以callback形式返回获取此应用程序的所有通知渠道的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。


| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

// getSlots回调
let getSlotsCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationSlot>): void => {
  if (err) {
    console.error(`getSlots failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`getSlots success, data is ${JSON.stringify(data)}`);
  }
}
notificationManager.getSlots(getSlotsCallback);
```

## notificationManager.getSlots

getSlots(): Promise\<Array\<NotificationSlot>>

获取此应用程序的所有通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\>\> | 以Promise形式返回获取此应用程序的所有通知渠道的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.getSlots().then((data: Array<notificationManager.NotificationSlot>) => {
	console.info("getSlots success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlots fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.removeSlot

removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>): void

删除此应用程序指定类型的通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                                                        |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)              | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定通道的回调方法。                                        |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

// removeSlot回调
let removeSlotCallback = (err: Base.BusinessError): void => {
  if (err) {
    console.error(`removeSlot failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("removeSlot success");
  }
}
let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.removeSlot(slotType, removeSlotCallback);
```

## notificationManager.removeSlot

removeSlot(slotType: SlotType): Promise\<void\>

删除此应用程序指定类型的通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.removeSlot(slotType).then(() => {
	console.info("removeSlot success");
}).catch((err: Base.BusinessError) => {
    console.error(`removeSlot fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.removeAllSlots

removeAllSlots(callback: AsyncCallback\<void\>): void

删除此应用程序所有通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 表示被指定通道的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let removeAllCallBack = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`removeAllSlots failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAllSlots success");
    }
}
notificationManager.removeAllSlots(removeAllCallBack);
```

## notificationManager.removeAllSlots

removeAllSlots(): Promise\<void\>

删除此应用程序所有通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.removeAllSlots().then(() => {
	console.info("removeAllSlots success");
}).catch((err: Base.BusinessError) => {
    console.error(`removeAllSlots fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(callback: AsyncCallback\<boolean\>): void

获取通知使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<boolean\> | 是   | 获取通知使能状态回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600008  | The user does not exist.                   |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationEnabled success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.isNotificationEnabled(isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(): Promise\<boolean\>

获取通知使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取通知使能状态的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600008  | The user does not exist.                   |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.isNotificationEnabled().then((data: boolean) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setBadgeNumber<sup>10+</sup>

setBadgeNumber(badgeNumber: number): Promise\<void\>

设定角标个数，在应用的桌面图标上呈现。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| badgeNumber | number | 是   | 角标个数。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

let badgeNumber: number = 10;

notificationManager.setBadgeNumber(badgeNumber).then(() => {
	console.info("displayBadge success");
}).catch((err: Base.BusinessError) => {
    console.error(`displayBadge fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setBadgeNumber<sup>10+</sup>

setBadgeNumber(badgeNumber: number, callback: AsyncCallback\<void\>): void

设定角标个数，在应用的桌面图标上呈现。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型                  | 必填 | 说明               |
| ----------- | --------------------- | ---- | ------------------ |
| badgeNumber | number                | 是   | 角标个数。         |
| callback    | AsyncCallback\<void\> | 是   | 设定角标回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

let setBadgeNumberCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.info(`displayBadge failed code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("displayBadge success");
    }
}

let badgeNumber: number = 10;
notificationManager.setBadgeNumber(badgeNumber, setBadgeNumberCallback);
```

## notificationManager.getActiveNotificationCount

getActiveNotificationCount(callback: AsyncCallback\<number\>): void

获取当前应用未删除的通知数。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<number\> | 是   | 获取未删除通知数回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let getActiveNotificationCountCallback = (err: Base.BusinessError, data: number): void => {
    if (err) {
        console.error(`getActiveNotificationCount failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getActiveNotificationCount success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.getActiveNotificationCount(getActiveNotificationCountCallback);
```

## notificationManager.getActiveNotificationCount

getActiveNotificationCount(): Promise\<number\>

获取当前应用未删除的通知数。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型              | 说明                                        |
| ----------------- | ------------------------------------------- |
| Promise\<number\> | 以Promise形式返回获取当前应用未删除通知数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.getActiveNotificationCount().then((data: number) => {
	console.info("getActiveNotificationCount success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getActiveNotificationCount fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getActiveNotifications

getActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void

获取当前应用未删除的通知列表。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>> | 是   | 获取当前应用通知列表回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let getActiveNotificationsCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationRequest>): void => {
    if (err) {
        console.error(`getActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getActiveNotifications success");
    }
}

notificationManager.getActiveNotifications(getActiveNotificationsCallback);
```

## notificationManager.getActiveNotifications

getActiveNotifications(): Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\>

获取当前应用未删除的通知列表。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\> | 以Promise形式返回获取当前应用通知列表。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.getActiveNotifications().then((data: Array<notificationManager.NotificationRequest>) => {
	console.info("removeGroupByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getActiveNotificationCount fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.cancelGroup

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

取消本应用指定组下的通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型                  | 必填 | 说明                         |
| --------- | --------------------- | ---- | ---------------------------- |
| groupName | string                | 是   | 通知组名称，此名称需要在发布通知时通过[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)对象指定。 |
| callback  | AsyncCallback\<void\> | 是   | 取消本应用指定组下通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let cancelGroupCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancelGroup failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelGroup success");
    }
}

let groupName: string = "GroupName";

notificationManager.cancelGroup(groupName, cancelGroupCallback);
```

## notificationManager.cancelGroup

cancelGroup(groupName: string): Promise\<void\>

取消本应用指定组下的通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型   | 必填 | 说明           |
| --------- | ------ | ---- | -------------- |
| groupName | string | 是   | 通知组名称。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let groupName: string = "GroupName";
notificationManager.cancelGroup(groupName).then(() => {
	console.info("cancelGroup success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancelGroup fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isSupportTemplate

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

查询模板是否存在。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名       | 类型                     | 必填 | 说明                       |
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | 是   | 模板名称。当前仅支持'downloadTemplate'。                   |
| callback     | AsyncCallback\<boolean\> | 是   | 查询模板是否存在的回调函数（true：存在，false：不存在）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let templateName: string = 'process';
let isSupportTemplateCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isSupportTemplate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isSupportTemplate success");
    }
}

notificationManager.isSupportTemplate(templateName, isSupportTemplateCallback);
```

## notificationManager.isSupportTemplate

isSupportTemplate(templateName: string): Promise\<boolean\>

查询模板是否存在。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名       | 类型   | 必填 | 说明     |
| ------------ | ------ | ---- | -------- |
| templateName | string | 是   | 模板名称。当前仅支持'downloadTemplate'。 |

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise方式返回模板是否存在的结果（true：存在，false：不存在）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let templateName: string = 'process';
notificationManager.isSupportTemplate(templateName).then((data: boolean) => {
    console.info("isSupportTemplate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isSupportTemplate fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.requestEnableNotification

requestEnableNotification(callback: AsyncCallback\<void\>): void

应用请求通知使能。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<void\> | 是   | 应用请求通知使能的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600004  | Notification is not enabled.          |
| 1600013  | Enable Notification Dialog has been popping already.          |

**示例：**

```ts
import Base from '@ohos.base';

let requestEnableNotificationCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("requestEnableNotification success");
    }
};
notificationManager.requestEnableNotification(requestEnableNotificationCallback);
```

## notificationManager.requestEnableNotification

requestEnableNotification(): Promise\<void\>

应用请求通知使能。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600004  | Notification is not enabled.          |
| 1600013  | Enable Notification Dialog has been popping already.          |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.requestEnableNotification().then(() => {
    console.info("requestEnableNotification success");
}).catch((err: Base.BusinessError) => {
    console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.requestEnableNotification<sup>10+<sup>

requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void\>): void

应用请求通知使能模态弹窗。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                 |
| -------- | ------------------------ | ---- |--------------------|
| context | UIAbilityContext | 是   | 通知弹窗绑定Ability的上下文。 |
| callback | AsyncCallback\<void\> | 是   | 应用请求通知使能的回调函数。     |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600004  | Notification is not enabled.          |
| 1600013  | Enable Notification Dialog has been popping already.          |

**示例：**

```ts
import Base from '@ohos.base';
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.Window';

class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let requestEnableNotificationCallback = (err: Base.BusinessError): void => {
      if (err) {
        console.error(`requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info("requestEnableNotification success");
      }
    };
    notificationManager.requestEnableNotification(this.context, requestEnableNotificationCallback);
  }
}
```

## notificationManager.requestEnableNotification<sup>10+<sup>

requestEnableNotification(context: UIAbilityContext): Promise\<void\>

应用请求通知使能模态弹窗。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                 |
| -------- | ------------------------ | ---- |--------------------|
| context | UIAbilityContext | 是   | 通知弹窗绑定Ability的上下文。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600004  | Notification is not enabled.          |
| 1600013  | Enable Notification Dialog has been popping already.          |

**示例：**

```ts
import Base from '@ohos.base';
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.Window';

class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    notificationManager.requestEnableNotification(this.context).then(() => {
      console.info("requestEnableNotification success");
    }).catch((err: Base.BusinessError) => {
      console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
    });
  }
}
```

## notificationManager.isDistributedEnabled

isDistributedEnabled(callback: AsyncCallback\<boolean>): void

查询设备是否支持分布式通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 设备是否支持分布式通知的回调函数（true：支持，false：不支持）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```ts
import Base from '@ohos.base';

let isDistributedEnabledCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isDistributedEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isDistributedEnabled success " + JSON.stringify(data));
    }
};
notificationManager.isDistributedEnabled(isDistributedEnabledCallback);
```

## notificationManager.isDistributedEnabled

isDistributedEnabled(): Promise\<boolean>

查询设备是否支持分布式通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型               | 说明                                          |
| ------------------ | --------------------------------------------- |
| Promise\<boolean\> | Promise方式返回设备是否支持分布式通知的结果（true：支持，false：不支持）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```ts
import Base from '@ohos.base';

notificationManager.isDistributedEnabled()
.then((data: boolean) => {
    console.info("isDistributedEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isDistributedEnabled fail: ${JSON.stringify(err)}`);
});
```

## ContentType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                              | 值          | 说明               |
| --------------------------------- | ----------- |------------------|
| NOTIFICATION_CONTENT_BASIC_TEXT   | 0          | 普通类型通知。          |
| NOTIFICATION_CONTENT_LONG_TEXT    | 1          | 长文本类型通知。         |
| NOTIFICATION_CONTENT_PICTURE      | 2          | 图片类型通知。（预留能力，暂未支持）。          |
| NOTIFICATION_CONTENT_CONVERSATION | 3          | 社交类型通知。（预留能力，暂未支持）。 |
| NOTIFICATION_CONTENT_MULTILINE    | 4          | 多行文本类型通知。        |
| NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW<sup>11+</sup>    | 5 | 实况窗类型通知。（预留能力，暂未支持）。        |
| NOTIFICATION_CONTENT_LIVE_VIEW<sup>11+</sup>    | 6 | 普通实况窗类型通知。（预留能力，暂未支持）。  |

## SlotLevel

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                              | 值          | 说明               |
| --------------------------------- | ----------- | ------------------ |
| LEVEL_NONE                        | 0           | 表示关闭通知功能。     |
| LEVEL_MIN                         | 1           | 表示通知功能已启用，但状态栏中不显示通知图标，且没有横幅或提示音。 |
| LEVEL_LOW                         | 2           | 表示通知功能已启用，且状态栏中显示通知图标，但没有横幅或提示音。 |
| LEVEL_DEFAULT                     | 3           | 表示通知功能已启用，状态栏中显示通知图标，没有横幅但有提示音。 |
| LEVEL_HIGH                        | 4           | 表示通知功能已启用，状态栏中显示通知图标，有横幅和提示音。 |


## SlotType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                 | 值       | 说明       |
| -------------------- | -------- | ---------- |
| UNKNOWN_TYPE         | 0 | 未知类型。 |
| SOCIAL_COMMUNICATION | 1 | 社交通信。 |
| SERVICE_INFORMATION  | 2 | 服务提醒。 |
| CONTENT_INFORMATION  | 3 | 内容资讯。 |
| LIVE_VIEW<sup>11+</sup>            | 4 | 实况窗。（预留能力，暂未支持）。 |
| CUSTOMER_SERVICE<sup>11+</sup>     | 5 | 客服消息。该类型用于用户与商家之间的客服消息，需由用户主动发起。  |
| OTHER_TYPES          | 0xFFFF | 其他。 |
