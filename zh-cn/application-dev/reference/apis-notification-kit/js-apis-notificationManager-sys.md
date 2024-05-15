# @ohos.notificationManager (NotificationManager模块)(系统接口)

本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知渠道，获取通知的使能状态、角标使能状态，获取通知的相关信息等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[NotificationManager](./js-apis-notificationManager.md)。

## 导入模块

```ts
import notificationManager from '@ohos.notificationManager';
```

## notificationManager.publish

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

发布通知给指定的用户。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| userId   | number                                      | 是   | 用户ID。                           |
| callback | AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                           |

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
| 1600008  | The user does not exist.                               |
| 1600009  | Over max number notifications per second.            |
| 1600012  | No memory space.                                     |
| 1600014  | No relevant right.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 2300007  | Network is unreachable.                              |

**示例：**

```ts
import Base from '@ohos.base';

// publish回调
let publishCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish success");
    }
}
// 用户ID
let userId: number = 1;
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
notificationManager.publish(notificationRequest, userId, publishCallback);
```

## notificationManager.publish

publish(request: NotificationRequest, userId: number): Promise\<void\>

发布通知给指定的用户。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     |  类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| userId   | number                                      | 是   | 用户ID。                           |

**返回值：**

| 类型     | 说明        | 
| ------- |-----------|
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
| 1600008  | The user does not exist.                               |
| 1600009  | Over max number notifications per second.            |
| 1600012  | No memory space.                                     |
| 1600014  | No relevant right.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 2300007  | Network is unreachable.                              |

**示例：**

```ts
import Base from '@ohos.base';

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

let userId: number = 1;

notificationManager.publish(notificationRequest, userId).then(() => {
	console.info("publish success");
}).catch((err: Base.BusinessError) => {
    console.error(`publish fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

创建通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot.md)       | 是   | 要创建的通知渠道对象。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定通道的回调方法。 |

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

// addslot回调
let addSlotCallBack = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlot success");
    }
}
// 通知slot对象
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot, addSlotCallBack);
```

## notificationManager.addSlot

addSlot(slot: NotificationSlot): Promise\<void\>

创建通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型             | 必填 | 说明                 |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | 是   | 要创建的通知渠道对象。 |

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
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

// 通知slot对象
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot).then(() => {
	console.info("addSlot success");
}).catch((err: Base.BusinessError) => {
    console.error(`addSlot fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

创建多个通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | 是   | 要创建的通知渠道对象数组。 |
| callback | AsyncCallback\<void\>     | 是   | 表示被指定通道的回调方法。     |

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

// addSlots回调
let addSlotsCallBack = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`addSlots failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlots success");
    }
}
// 通知slot对象
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// 通知slot array 对象
let notificationSlotArray: notificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray, addSlotsCallBack);
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>): Promise\<void\>

创建多个通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名  | 类型                      | 必填 | 说明                     |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | 是   | 要创建的通知渠道对象数组。 |

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
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

// 通知slot对象
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// 通知slot array 对象
let notificationSlotArray: notificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray).then(() => {
	console.info("addSlots success");
}).catch((err: Base.BusinessError) => {
    console.error(`addSlot fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定应用的通知使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)   | 是   | 指定应用的包信息。        |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知使能回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let setNotificationEnableCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setNotificationEnableCallback failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnableCallback success");
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.setNotificationEnable(bundle, false, setNotificationEnableCallback);
```

## notificationManager.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean): Promise\<void\>

设定指定应用的通知使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.setNotificationEnable(bundle, false).then(() => {
	console.info("setNotificationEnable success");
}).catch((err: Base.BusinessError) => {
    console.error(`setNotificationEnable fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getAllNotificationEnabledBundles<sup>12+</sup>

getAllNotificationEnabledBundles(): Promise<Array<BundleOption>>;

获取允许通知的应用程序列表。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

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

notificationManager.getAllNotificationEnabledBundles().then((data: Array<notificationManager.BundleOption>) => {
    console.info("Enable bundle data is" + JSON.stringify(data));
    data.forEach(element => {
        console.info("Enable uid is " + JSON.stringify(element.uid));
        console.info("Enable bundle is " + JSON.stringify(element.bundle));
    });
}).catch((err: Base.BusinessError) => {
    console.info("getAllNotificationEnabledBundles failed, error is" + JSON.stringify(err));
})
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定应用的通知使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。            |
| callback | AsyncCallback\<boolean\> | 是   | 获取通知使能状态回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
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

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

notificationManager.isNotificationEnabled(bundle, isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption): Promise\<boolean\>

获取指定应用的通知使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型               | 说明                                                |
| ------------------ | --------------------------------------------------- |
| Promise\<boolean\> | 以Promise形式返回获取指定应用的通知使能状态的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isNotificationEnabled(bundle).then((data: boolean) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(userId: number, callback: AsyncCallback\<boolean\>): void

获取指定用户ID下的通知使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| userId   | number                | 是   | 指定的用户ID。 |
| callback | AsyncCallback\<boolean\> | 是   | 获取通知使能状态回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

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

let userId: number = 1;

notificationManager.isNotificationEnabled(userId, isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(userId: number): Promise\<boolean\>

获取指定用户下的通知使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number       | 是   | 指定的用户ID。 |

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
| 1600008  | The user does not exist..                  |

**示例：**

```ts
import Base from '@ohos.base';

let userId: number = 1;

notificationManager.isNotificationEnabled(userId).then((data: boolean) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定应用的角标使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。           |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定角标使能回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let displayBadgeCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`displayBadge failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("displayBadge success");
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.displayBadge(bundle, false, displayBadgeCallback);
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean): Promise\<void\>

设定指定应用的角标使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.displayBadge(bundle, false).then(() => {
	console.info("displayBadge success");
}).catch((err: Base.BusinessError) => {
    console.error(`displayBadge fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定应用的角标使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。               |
| callback | AsyncCallback\<boolean\> | 是   | 获取角标使能状态回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let isBadgeDisplayedCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isBadgeDisplayed failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isBadgeDisplayed success, data is ${JSON.stringify(data)}`);
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);
```

## notificationManager.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption): Promise\<boolean\>

获取指定应用的角标使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取指定应用的角标使能状态。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.isBadgeDisplayed(bundle).then((data: boolean) => {
	console.info("isBadgeDisplayed success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isBadgeDisplayed fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setSlotFlagsByBundle<sup>11+</sup>

setSlotFlagsByBundle(bundle: BundleOption, slotFlags: number): Promise\<void\>

设定指定应用的通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| slotFlags   | number | 是   | 通知渠道标识位。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let slotFlags: number = 1;

notificationManager.setSlotFlagsByBundle(bundle, slotFlags).then(() => {
	console.info("setSlotFlagsByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`setSlotFlagsByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

设定指定应用的通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。           |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot.md)      | 是   | 通知渠道。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知渠道回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let setSlotByBundleCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setSlotByBundle success");
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);
```

## notificationManager.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot): Promise\<void\>

设定指定应用的通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| slot   | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | 是   | 通知渠道。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};

notificationManager.setSlotByBundle(bundle, notificationSlot).then(() => {
	console.info("setSlotByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`setSlotByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlotFlagsByBundle<sup>11+</sup>

getSlotFlagsByBundle(bundle: BundleOption): Promise\<number\>

获取指定应用的通知渠道标识位。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
|  Promise\<number\>| 以Promise形式返回获取指定应用的通知渠道标识位。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.getSlotFlagsByBundle(bundle).then((data : number) => {
	console.info("getSlotFlagsByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlotFlagsByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback\<Array\<NotificationSlot>>): void

获取指定应用的所有通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                                     | 必填 | 说明                 |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)                             | 是   | 指定应用的包信息。           |
| callback | AsyncCallback\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)>> | 是   | 获取通知渠道回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let getSlotsByBundleCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationSlot>): void => {
    if (err) {
        console.error(`getSlotsByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getSlotsByBundle success, data is ${JSON.stringify(data)}`);
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.getSlotsByBundle(bundle, getSlotsByBundleCallback);
```

## notificationManager.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption): Promise\<Array\<NotificationSlot>>

获取指定应用的所有通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)>> | 以Promise形式返回获取指定应用的通知渠道。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

notificationManager.getSlotsByBundle(bundle).then((data: Array<notificationManager.NotificationSlot>) => {
	console.info("getSlotsByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlotsByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

获取指定应用的通知渠道数量。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)              | 是   | 指定应用的包信息。             |
| callback | AsyncCallback\<number\> | 是   | 获取通知渠道数量回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let getSlotNumByBundleCallback = (err: Base.BusinessError, data: number): void => {
    if (err) {
        console.error(`getSlotNumByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getSlotNumByBundle success data is ${JSON.stringify(data)}`);
    }
}

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);
```

## notificationManager.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption): Promise\<number\>

获取指定应用的通知渠道数量。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取指定应用的通知渠道数量。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.getSlotNumByBundle(bundle).then((data: number) => {
	console.info("getSlotNumByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlotNumByBundle fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void

获取当前未删除的所有通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>> | 是   | 获取活动通知回调函数。 |

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

let getAllActiveNotificationsCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationRequest>): void => {
    if (err) {
        console.error(`getAllActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getAllActiveNotifications success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.getAllActiveNotifications(getAllActiveNotificationsCallback);
```

## notificationManager.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\>

获取当前未删除的所有通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\> | 以Promise形式返回获取活动通知。 |

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

notificationManager.getAllActiveNotifications().then((data: Array<notificationManager.NotificationRequest>) => {
	console.info("getAllActiveNotifications success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getAllActiveNotifications fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getActiveNotificationByFilter<sup>11+<sup>

getActiveNotificationByFilter(filter: NotificationFilter, callback: AsyncCallback\<NotificationRequest\>): void

获取满足条件的普通实况通知信息。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。


**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| filter   | [NotificationFilter](js-apis-inner-notification-notificationRequest-sys.md#notificationfilter11) | 是   | 查询普通实况窗的过滤条件。 |
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>> | 是   | 获取满足条件的普通实况通知信息的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ---------------------------------------- |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';
import notificationSubscribe from '@ohos.notificationSubscribe';

let bundleOption: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: notificationSubscribe.NotificationKey = {
    id: 11,
    label: ""
};
let filter: notificationManager.NotificationFilter = {
    bundle: bundleOption,
    notificationKey: notificationKey,
    extraInfoKeys: ['event']
}
let getActiveNotificationByFilterCallback = (err: Base.BusinessError, data: notificationManager.NotificationRequest): void => {
    if (err) {
        console.error(`getActiveNotificationByFilter failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getActiveNotificationByFilter success");
    }
}
notificationManager.getActiveNotificationByFilter(filter, getActiveNotificationByFilterCallback);
```

## notificationManager.getActiveNotificationByFilter<sup>11+<sup>

getActiveNotificationByFilter(filter: NotificationFilter): Promise\<NotificationRequest\>

获取满足条件的普通实况通知信息。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。


**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| filter   | [NotificationFilter](js-apis-inner-notification-notificationRequest-sys.md#notificationfilter11) | 是   | 查询普通实况窗的过滤条件。 |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\> | 以Promise形式返回获取的满足条件的普通实况通知信息。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ---------------------------------------- |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';
import notificationSubscribe from '@ohos.notificationSubscribe';

let bundleOption: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: notificationSubscribe.NotificationKey = {
    id: 11,
    label: ""
};
let filter: notificationManager.NotificationFilter = {
    bundle: bundleOption,
    notificationKey: notificationKey,
    extraInfoKeys: ['event']
}
notificationManager.getActiveNotificationByFilter(filter).then((data: notificationManager.NotificationRequest) => {
	console.info("getActiveNotificationByFilter success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getActiveNotificationByFilter fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

删除指定应用的指定组下的通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                  | 必填 | 说明                         |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 应用的包信息。                   |
| groupName | string                | 是   | 通知组名称。               |
| callback  | AsyncCallback\<void\> | 是   | 删除指定应用指定组下通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let removeGroupByBundleCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`removeGroupByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeGroupByBundle success");
    }
}

let bundleOption: notificationManager.BundleOption = { bundle: "Bundle" };
let groupName: string = "GroupName";

notificationManager.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```

## notificationManager.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

删除指定应用的指定组下的通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名      | 类型         | 必填 | 说明           |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。     |
| groupName | string       | 是   | 通知组名称。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundleOption: notificationManager.BundleOption = { bundle: "Bundle" };
let groupName: string = "GroupName";

notificationManager.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`removeGroupByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

设置免打扰时间。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | 是   | 免打扰时间选项。         |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

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

let setDoNotDisturbDateCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDoNotDisturbDate success");
    }
}

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

notificationManager.setDoNotDisturbDate(doNotDisturbDate, setDoNotDisturbDateCallback);
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void\>

设置免打扰时间。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型             | 必填 | 说明           |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate) | 是   | 免打扰时间选项。 |


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
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};
notificationManager.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: Base.BusinessError) => {
    console.error(`setDoNotDisturbDate fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

指定用户设置免打扰时间。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | 是   | 免打扰时间选项。         |
| userId   | number                | 是   | 设置免打扰时间的用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

let setDoNotDisturbDateCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDoNotDisturbDate success");
    }
}

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

let userId: number = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId, setDoNotDisturbDateCallback);
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

指定用户设置免打扰时间。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate) | 是   | 免打扰时间选项。 |
| userId | number           | 是   | 设置免打扰时间的用户ID。 |

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
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

let userId: number = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: Base.BusinessError) => {
    console.error(`setDoNotDisturbDate fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

查询免打扰时间。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | 是   | 查询免打扰时间回调函数。 |

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

let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: notificationManager.DoNotDisturbDate): void => {
    if (err) {
        console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getDoNotDisturbDate success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```

## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

查询免打扰时间。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**返回值：**

| 类型                                             | 说明                                      |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | 以Promise形式返回获取查询到的免打扰时间。 |

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

notificationManager.getDoNotDisturbDate().then((data: notificationManager.DoNotDisturbDate) => {
  console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getDoNotDisturbDate fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

查询指定用户的免打扰时间。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | 是   | 查询免打扰时间回调函数。 |
| userId   | number                            | 是   | 用户ID。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: notificationManager.DoNotDisturbDate): void => {
    if (err) {
        console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getDoNotDisturbDate success, data is ${JSON.stringify(data)}`);
    }
}

let userId: number = 1;

notificationManager.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```

## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

查询指定用户的免打扰时间。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| userId   | number                            | 是   | 用户ID。 |

**返回值：**

| 类型                                             | 说明                                      |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | 以Promise形式返回获取查询到的免打扰时间。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

let userId: number = 1;

notificationManager.getDoNotDisturbDate(userId).then((data: notificationManager.DoNotDisturbDate) => {
	console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getDoNotDisturbDate fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.isSupportDoNotDisturbMode

 isSupportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

查询是否支持免打扰功能。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名     | 类型                     | 必填 | 说明                             |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 查询是否支持免打扰功能回调函数（true：支持，false：不支持）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                             |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
import Base from '@ohos.base';

let isSupportDoNotDisturbModeCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isSupportDoNotDisturbMode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isSupportDoNotDisturbMode success");
    }
}

notificationManager.isSupportDoNotDisturbMode(isSupportDoNotDisturbModeCallback);
```

## notificationManager.isSupportDoNotDisturbMode

isSupportDoNotDisturbMode(): Promise\<boolean\>

查询是否支持免打扰功能。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取是否支持免打扰功能的结果（true：支持，false：不支持）。 |

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

notificationManager.isSupportDoNotDisturbMode().then((data: boolean) => {
	console.info("supportDoNotDisturbMode success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`supportDoNotDisturbMode fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean, callback: AsyncCallback\<void\>): void

设置设备是否支持分布式通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持（true：支持，false：不支持）。 |
| callback | AsyncCallback\<void\> | 是   | 设置设备是否支持分布式通知的回调函数。 |

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

let setDistributedEnableCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setDistributedEnable failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDistributedEnable success");
    }
};
let enable: boolean = true;
notificationManager.setDistributedEnable(enable, setDistributedEnableCallback);
```

## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean): Promise\<void>

设置设备是否支持分布式通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持（true：支持，false：不支持）。 |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

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

let enable: boolean = true;
notificationManager.setDistributedEnable(enable).then(() => {
    console.info("setDistributedEnable success");
}).catch((err: Base.BusinessError) => {
    console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

设置指定应用是否支持分布式通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包信息。                   |
| enable   | boolean                  | 是   | 指定应用是否支持分布式通知（true：支持，false：不支持）。|
| callback | AsyncCallback\<void\> | 是   | 应用程序是否支持分布式通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let setDistributedEnableByBundleCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setDistributedEnableByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("enableDistributedByBundle success");
    }
};
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
let enable: boolean = true;
notificationManager.setDistributedEnableByBundle(bundle, enable, setDistributedEnableByBundleCallback);
```



## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

设置指定应用是否支持分布式通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                |
| enable   | boolean                  | 是   | 指定应用是否支持分布式通知（true：支持，false：不支持）。                  |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
let enable: boolean = true;
notificationManager.setDistributedEnableByBundle(bundle, enable).then(() => {
    console.info("setDistributedEnableByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`setDistributedEnableByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

根据应用的包获取应用程序是否支持分布式通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                     |
| callback | AsyncCallback\<boolean\> | 是   | 查询指定应用是否支持分布式通知的回调函数（true：支持，false：不支持）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let isDistributedEnabledByBundleCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isDistributedEnabledByBundle success" + JSON.stringify(data));
    }
};
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isDistributedEnabledByBundle(bundle, isDistributedEnabledByBundleCallback);
```

## notificationManager.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

查询指定应用是否支持分布式通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                |

**返回值：**

| 类型               | 说明                                              |
| ------------------ | ------------------------------------------------- |
| Promise\<boolean\> | Promise方式返回指定应用是否支持分布式通知的结果（true：支持，false：不支持）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isDistributedEnabledByBundle(bundle).then((data: boolean) => {
    console.info("isDistributedEnabledByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isDistributedEnabledByBundle fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getDeviceRemindType

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

获取通知的提醒方式。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                               | 必填 | 说明                       |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype)\> | 是   | 获取通知提醒方式的回调函数。 |

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

let getDeviceRemindTypeCallback = (err: Base.BusinessError, data: notificationManager.DeviceRemindType): void => {
    if (err) {
        console.error(`getDeviceRemindType failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getDeviceRemindType success, data is ${JSON.stringify(data)}`);
    }
};
notificationManager.getDeviceRemindType(getDeviceRemindTypeCallback);
```

## notificationManager.getDeviceRemindType

getDeviceRemindType(): Promise\<DeviceRemindType\>

获取通知的提醒方式。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype)\> | Promise方式返回获取通知提醒方式的结果。 |

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

notificationManager.getDeviceRemindType().then((data: notificationManager.DeviceRemindType) => {
    console.info("getDeviceRemindType success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getDeviceRemindType fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

发布代理通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名               | 类型                                        | 必填 | 说明                                     |
| -------------------- | ------------------------------------------- | ---- | ---------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| representativeBundle | string                                      | 是   | 被代理应用的包名。                       |
| userId               | number                                      | 是   | 用户ID。                                 |
| callback             | AsyncCallback\<void\>                        | 是   | 发布代理通知的回调方法。                 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user does not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

//publishAsBundle回调
let callback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsBundle success");
    }
}
// 被代理应用的包名
let representativeBundle: string = "com.example.demo";
// 用户ID
let userId: number = 100;
// NotificationRequest对象
let request: notificationManager.NotificationRequest = {
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
notificationManager.publishAsBundle(request, representativeBundle, userId, callback);
```

## notificationManager.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number): Promise\<void\>

发布代理通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**


| 参数名               | 类型                                        | 必填 | 说明                                          |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| representativeBundle | string                                      | 是   | 被代理应用的包名。                            |
| userId               | number                                      | 是   | 用户ID。                            |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user does not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

// 被代理应用的包名
let representativeBundle: string = "com.example.demo";
// 用户ID
let userId: number = 100;
// NotificationRequest对象
let request: notificationManager.NotificationRequest = {
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
notificationManager.publishAsBundle(request, representativeBundle, userId).then(() => {
	console.info("publishAsBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`publishAsBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.publishAsBundle<sup>12+</sup>

publishAsBundle(representativeBundle: BundleOption, request: NotificationRequest): Promise\<void\>

发布代理通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**


| 参数名               | 类型                                        | 必填 | 说明                                          |
|----------------------|--------------------------------------------|------|-----------------------------------------------|
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  | 是   | 被代理应用的包信息。                            |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user does not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

// 被代理应用的包信息
let representativeBundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
// NotificationRequest对象
let request: notificationManager.NotificationRequest = {
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
notificationManager.publishAsBundle(representativeBundle, request).then(() => {
	console.info("publishAsBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`publishAsBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

取消代理通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名               | 类型          | 必填 | 说明                     |
| -------------------- | ------------- | ---- | ------------------------ |
| id                   | number        | 是   | 通知ID。                 |
| representativeBundle | string        | 是   | 被代理应用的包名。       |
| userId               | number        | 是   | 用户ID。       |
| callback             | AsyncCallback\<void\> | 是   | 取消代理通知的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import Base from '@ohos.base';

// cancelAsBundle
let cancelAsBundleCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelAsBundle success");
    }
}
// 被代理应用的包名
let representativeBundle: string = "com.example.demo";
// 用户ID
let userId: number = 100;
notificationManager.cancelAsBundle(0, representativeBundle, userId, cancelAsBundleCallback);
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void\>

取消代理通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名               | 类型   | 必填 | 说明               |
| -------------------- | ------ | ---- | ------------------ |
| id                   | number | 是   | 通知ID。           |
| representativeBundle | string | 是   | 被代理应用的包名。 |
| userId               | number | 是   | 用户ID。 |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import Base from '@ohos.base';

// 被代理应用的包名
let representativeBundle: string = "com.example.demo";
// 用户ID
let userId: number = 100;
notificationManager.cancelAsBundle(0, representativeBundle, userId).then(() => {
	console.info("cancelAsBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancelAsBundle fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.cancelAsBundle<sup>12+</sup>

cancelAsBundle(representativeBundle: BundleOption, id: number): Promise\<void\>

取消代理通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**


| 参数名               | 类型                                        | 必填 | 说明                                          |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  |是   | 被代理应用的包信息。 |
| id                   | number                                     | 是   | 通知ID。           |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600007  | The notification is not exist.            |
| 1600008  | The user does not exist.                    |
| 1600012  | No memory space.                          |

**示例：**

```ts
import Base from '@ohos.base';

let representativeBundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
notificationManager.cancelAsBundle(representativeBundle, 1).then(() => {
	console.info("cancelAsBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancelAsBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.cancel<sup>12+</sup>

cancel(representativeBundle: BundleOption, id: number): Promise\<void\>

代理取消当前用户其他应用的通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名               | 类型   | 必填 | 说明               |
| -------------------- | ------ | ---- | ------------------ |
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。           |
|       id             | number | 是   | 通知ID。 |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | 无返回结果的Promise对象。 | 

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600012  | No memory space.                    |
| 1600017  | There is no corresponding agent relationship configuration.    |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName"
};
let id: number = 1;
notificationManager.cancel(bundle, id).then(() => {
  console.info("cancel success");
}).catch((err: Base.BusinessError) => {
  console.error(`cancel fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setNotificationEnableSlot 

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

设置指定应用的指定渠道类型的使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                          | 必填 | 说明                   |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。           |
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | 是   | 指定渠道类型。         |
| enable   | boolean                       | 是   | 使能状态（true：使能，false：禁止）。             |
| callback | AsyncCallback\<void\>         | 是   | 设置渠道使能回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

// setNotificationEnableSlot
let setNotificationEnableSlotCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setNotificationEnableSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnableSlot success");
    }
};
notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true,
    setNotificationEnableSlotCallback);
```

## notificationManager.setNotificationEnableSlot<sup>11+</sup>

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, isForceControl: boolean, callback: AsyncCallback\<void>): void

设置指定应用的指定渠道类型的使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                          | 必填 | 说明                     |
| -------- | ----------------------------- | ---- | ----------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。|
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | 是   | 指定渠道类型。           |
| enable   | boolean                       | 是   | 使能状态。               |
| isForceControl<sup>11+</sup> | boolean                 | 是   | 渠道开关是否受通知总开关影响（false：受总开关影响，true：不受总开关影响）。 |
| callback | AsyncCallback\<void\>         | 是   | 设置渠道使能回调函数。    |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let setNotificationEnableSlotCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setNotificationEnableSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnableSlot success");
    }
};

notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true,
    false,
    setNotificationEnableSlotCallback);
```

## notificationManager.setNotificationEnableSlot

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, isForceControl?: boolean): Promise\<void>

设置指定应用的指定渠道类型的使能状态。使用promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。   |
| type   | [SlotType](./js-apis-notificationManager.md#slottype)         | 是   | 渠道类型。 |
| enable | boolean                       | 是   | 使能状态（true：使能，false：禁止）。     |
| isForceControl<sup>11+</sup> | boolean               | 否   | 渠道开关是否受通知总开关影响（false：受总开关影响，true：不受总开关影响）。默认为false。     |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

// setNotificationEnableSlot
notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true).then(() => {
        console.info("setNotificationEnableSlot success");
    }).catch((err: Base.BusinessError) => {
        console.error(`setNotificationEnableSlot fail: ${JSON.stringify(err)}`);
    });
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean\>): void

获取指定应用的指定渠道类型的使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名   | 类型                          | 必填 | 说明                   |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。           |
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | 是   | 渠道类型。         |
| callback | AsyncCallback\<boolean\>         | 是   | 获取渠道使能状态回调函数（true：使能，false：禁止）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

// isNotificationSlotEnabled
let getEnableSlotCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationSlotEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationSlotEnabled success, data is ${JSON.stringify(data)}`);
    }
};

notificationManager.isNotificationSlotEnabled(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    getEnableSlotCallback);
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise\<boolean\>  

获取指定应用的指定渠道类型的使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。   |
| type   | [SlotType](./js-apis-notificationManager.md#slottype)         | 是   | 渠道类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回指定类型的渠道使能状态（true：使能，false：禁止）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

// isNotificationSlotEnabled
notificationManager.isNotificationSlotEnabled({ bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION).then((data: boolean) => {
    console.info("isNotificationSlotEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isNotificationSlotEnabled fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void\>): void

设置是否将通知同步到未安装应用程序的设备(callback形式)。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |
| enable | boolean | 是   | 是否启用（true：使能，false：禁止）。   |
| callback | AsyncCallback\<void\>    | 是   | 设置是否将通知同步到未安装应用程序的设备的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import Base from '@ohos.base';

let userId: number = 100;
let enable: boolean = true;
let callback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setSyncNotificationEnabledWithoutApp success");
    }
}
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable, callback);
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>

设置是否将通知同步到未安装应用程序的设备(Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |
| enable | boolean | 是   | 是否启用（true：使能，false：禁止）。   |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<void\> | 以Promise形式返回设置是否将通知同步到未安装应用程序的设备的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import Base from '@ohos.base';

let userId: number = 100;
let enable: boolean = true;
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable).then(() => {
    console.info('setSyncNotificationEnabledWithoutApp success');
}).catch((err: Base.BusinessError) => {
    console.error(`setSyncNotificationEnabledWithoutApp fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getSyncNotificationEnabledWithoutApp

getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback\<boolean>): void

获取同步通知到未安装应用程序设备的开关是否开启(callback形式)。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |
| callback | AsyncCallback\<boolean\>         | 是   | 获取同步通知到未安装应用程序设备的开关是否开启的回调函数（true：开启，false：未开启）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import Base from '@ohos.base';

let userId: number = 100;
let getSyncNotificationEnabledWithoutAppCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.info('getSyncNotificationEnabledWithoutAppCallback, err:' + err);
    } else {
        console.info('getSyncNotificationEnabledWithoutAppCallback, data:' + data);
    }
}
notificationManager.getSyncNotificationEnabledWithoutApp(userId, getSyncNotificationEnabledWithoutAppCallback);
```


## notificationManager.getSyncNotificationEnabledWithoutApp

getSyncNotificationEnabledWithoutApp(userId: number): Promise\<boolean>

获取同步通知到未安装应用程序设备的开关是否开启(Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取同步通知到未安装应用程序设备的开关是否开启的结果（true：开启，false：未开启）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import Base from '@ohos.base';

let userId: number = 100;
notificationManager.getSyncNotificationEnabledWithoutApp(userId).then((data: boolean) => {
  console.info('getSyncNotificationEnabledWithoutApp, data:' + data);
}).catch((err: Base.BusinessError) => {
    console.error(`getSyncNotificationEnabledWithoutApp fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.on<sup>10+</sup>

on(type: 'checkNotification', callback: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void;

注册通知监听回调。通知服务将通知信息回调给校验程序，校验程序返回校验结果决定该通知是否发布，如营销类通知发布频率控制等。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                                                                                                                      | 必填 | 说明           |
| ------ |-------------------------------------------------------------------------------------------------------------------------| ---- | -------------- |
| type | string                                                                                                                  | 是   | 回调函数类型名，固定为'checkNotification'。 |
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo10)) =>  [NotificationCheckResult](#notificationcheckresult10) | 是   | 消息验证函数指针。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |

**示例：**

```ts
import Base from '@ohos.base';

let onCheckNotification = (info : notificationManager.NotificationCheckInfo): notificationManager.NotificationCheckResult => {
    console.info(`====>OnCheckNotification info: ${JSON.stringify(info)}`);
    if(info.notificationId == 1){
        let result: notificationManager.NotificationCheckResult =  { code: 1, message: "testMsg1"};
        return result;
    } else {
        let result: notificationManager.NotificationCheckResult =   { code: 0, message: "testMsg0"};
        return result;
    }
}
try{
    notificationManager.on("checkNotification", onCheckNotification);
} catch (error){
    console.error(`notificationManager.on error: ${JSON.stringify(error as Base.BusinessError)}`);
}
```

## notificationManager.on<sup>11+</sup>

on(type: 'checkNotification', checkRequest: NotificationCheckRequest, callback: (checkInfo: NotificationCheckInfo) => Promise\<NotificationCheckResult\>): void

注册通知监听回调。通知服务将通知信息回调给校验程序，校验程序返回校验结果决定该通知是否发布，如营销类通知发布频率控制等。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                                                                                                             | 必填 | 说明           |
| ------ |-----------------------------------------------------------------------------------------------------------------| ---- | -------------- |
| type | string                                                                                                            | 是   | 回调函数类型名，固定为'checkNotification'。 |
| checkRequest | [NotificationCheckRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationcheckrequest11)    | 是   | 通知请求验证内容。 |
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo10)) =>  Promise\<[NotificationCheckResult](#notificationcheckresult10)\> | 是   | 消息验证函数指针。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |

**示例：**

```ts
import Base from '@ohos.base';

try{
  notificationManager.on('checkNotification',{
    contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_LIVE_VIEW,
    slotType: notificationManager.SlotType.LIVE_VIEW ,
    extraInfoKeys: ["event"],
  },
    async (checkInfo)=>{
      return { code: 1, message: "INVALID_PARAMETERS"};
  },);
} catch (error) {
  console.error(`notificationManager.on error: ${JSON.stringify(error as Base.BusinessError)}`);
}
```

## notificationManager.off<sup>10+</sup>

off(type: 'checkNotification', callback?: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void;

取消通知监听回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                                                                                                                      | 必填 | 说明           |
| ------ |-------------------------------------------------------------------------------------------------------------------------| ---- | -------------- |
| type | string                                                                                                                  | 是   | 回调函数类型名，固定为'checkNotification'。 |
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo10)) =>  [NotificationCheckResult](#notificationcheckresult10) | 否   | 消息验证函数指针。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |

**示例：**

```ts
import Base from '@ohos.base';

try{
    notificationManager.off("checkNotification");
} catch (error){
    console.error(`notificationManager.off error: ${JSON.stringify(error as Base.BusinessError)}`);
}
```

## notificationManager.triggerSystemLiveView<sup>11+</sup>

triggerSystemLiveView(bundle: BundleOption, notificationId: number, buttonOptions: ButtonOptions): Promise\<void>;

触发系统实况窗。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                   | 必填 | 说明           |
| -------------- | ------------- | ---- | -------------- |
| bundle         | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  | 是   |指定应用的包信息。 |
| notificationId | number        | 是   | 通知ID。 |
| buttonOptions  | [ButtonOptions](#buttonoptions11) | 是   | 按钮信息。 |

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

// 包信息
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
// 通知ID
let notificationId = 1;
// 按钮信息
let buttonOptions: notificationManager.ButtonOptions = {
    buttonName: "buttonName1",
}
notificationManager.triggerSystemLiveView(bundle, notificationId, buttonOptions).then(() => {
  console.info("triggerSystemLiveView success");
}).catch((error: Base.BusinessError) => {
  console.error(`triggerSystemLiveView fail: ${JSON.stringify(error)}`);
});
```


## notificationManager.subscribeSystemLiveView<sup>11+</sup>

subscribeSystemLiveView(subscriber: SystemLiveViewSubscriber): Promise\<void>;

订阅系统实况窗。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                   | 必填 | 说明           |
| -------------- | ------------- | ---- | -------------- |
| subscriber | [SystemLiveViewSubscriber](#systemliveviewsubscriber11)  | 是   | 系统实况窗订阅者。|

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<void> | 无返回结果的Promise对象。 |

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

let onResponseCallback = (id:number, option:notificationManager.ButtonOptions) => {
    console.info("response callback: " + JSON.stringify(option) + "notificationId" + id);
}
let subscriber: notificationManager.SystemLiveViewSubscriber  = {
    onResponse: onResponseCallback,
};
notificationManager.subscribeSystemLiveView(subscriber).then(() => {
	console.info("subscribeSystemLiveView success");
}).catch((error: Base.BusinessError) => {
    console.error(`subscribeSystemLiveView fail: ${JSON.stringify(error)}`);
});
```

## notificationManager.setDistributedEnabledByBundle<sup>12+</sup>

setDistributedEnabledByBundle(bundle: BundleOption, deviceType: string, enable: boolean): Promise<void>

设置指定应用是否支持跨设备协同。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包信息。                   |
| deviceType | string | 是   | 设备类型|
| enable   | boolean                  | 是   | 指定应用是否支持跨设备协同（true：支持，false：不支持）。|

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
    uid: 1
};
let enable: boolean = true;
let deviceType: string = "phone";
notificationManager.setDistributedEnabledByBundle(bundle, deviceType, enable).then(() => {
    console.info("setDistributedEnabledByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`setDistributedEnabledByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isDistributedEnabledByBundle<sup>12+</sup>

isDistributedEnabledByBundle(bundle: BundleOption, deviceType: string): Promise<boolean>

获取指定应用是否支持跨设备协同。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包信息。                   |
| deviceType | string | 是   | 设备类型 |

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<boolean\> | 以Promise形式返回指定应用是否支持跨设备协同的开关是否开启的结果（true：开启，false：未开启）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
    uid: 1
};
let deviceType: string = "phone";
notificationManager.isDistributedEnabledByBundle(bundle, deviceType).then((data: boolean) => {
    console.info("isDistributedEnabledByBundle success, data:" + data);
}).catch((err: Base.BusinessError) => {
    console.error(`isDistributedEnabledByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setSmartReminderEnabled<sup>12+</sup>

setSmartReminderEnabled(deviceType: string, enable: boolean): Promise<void>

设置设备是否与其他设备协同智能提醒。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| deviceType | string | 是   | 设备类型 |
| enable   | boolean                  | 是   | 指定应用是否支持设备是否与其他设备协同智能提醒（true：支持，false：不支持）。|

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let deviceType: string = "phone";
let enable: boolean = true;
notificationManager.setSmartReminderEnabled(deviceType, enable).then(() => {
    console.info("setSmartReminderEnabled success");
}).catch((err: Base.BusinessError) => {
    console.error(`setSmartReminderEnabled fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isSmartReminderEnabled<sup>12+</sup>

isSmartReminderEnabled(deviceType: string): Promise<boolean>

获取设备是否与其他设备协同智能提醒。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| deviceType | string | 是   | 设备类型 |

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<boolean\> | 以Promise形式返回设备与其他设备协同智能提醒的开关是否开启的结果（true：开启，false：未开启）。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let deviceType: string = "phone";
notificationManager.isSmartReminderEnabled(deviceType).then((data: boolean) => {
    console.info("isSmartReminderEnabled success， data:" + data);
}).catch((err: Base.BusinessError) => {
    console.error(`isSmartReminderEnabled fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setBadgeNumberByBundle<sup>12+</sup>

setBadgeNumberByBundle(bundle: bundleOption, badgeNumber: number): Promise\<void\>

代理其他应用设定角标个数。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| bundle | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| badgeNumber | number | 是   | 角标个数。 |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<void\> | 无返回结果的Promise对象。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |
| 1600017  | There is no corresponding agent relationship configuration.     |
| 17700001 | The specified bundle name was not found.   |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: 'com.example.bundleName',
};
let badgeNumber: number = 10;

notificationManager.setBadgeNumberByBundle(bundle, badgeNumber).then(() => {
    console.info('setBadgeNumberByBundle success');
}).catch((err: Base.BusinessError) => {
    console.error(`setBadgeNumberByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlotByBundle<sup>12+</sup>

getSlotByBundle(bundle: BundleOption, slotType: SlotType): Promise\<Array\<NotificationSlot>>

获取指定应用指定类型的通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| slotType | [SlotType](././js-apis-notificationManager.md#slottype) | 是   | 渠道类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)> | 以Promise形式返回获取指定应用指定类型的通知渠道。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let slotType = notificationManager.SlotType.LIVE_VIEW;

notificationManager.getSlotByBundle(bundle, slotType).then((data: notificationManager.NotificationSlot) => {
	console.info("getSlotByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlotByBundle fail: ${JSON.stringify(err)}`);
});
```

## DoNotDisturbDate

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称  | 类型                                  | 必填 | 说明                   |
| ----- | ------------------------------------- | ---- | ---------------------- |
| type  | [DoNotDisturbType](#donotdisturbtype) | 是   | 免打扰设置的时间类型。 |
| begin | Date                                  | 是   | 免打扰设置的起点时间。 |
| end   | Date                                  | 是   | 免打扰设置的终点时间。 |

## DoNotDisturbType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

| 名称         | 值               | 说明                                       |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | 0 | 非通知勿扰类型。                           |
| TYPE_ONCE    | 1 | 以设置时间段(只看小时和分钟)一次执行勿扰。 |
| TYPE_DAILY   | 2 | 以设置时间段(只看小时和分钟)每天执行勿扰。 |
| TYPE_CLEARLY | 3 | 以设置时间段(明确月日时)执行勿扰。     |


## DeviceRemindType

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | 设备未被使用，无需提醒。            |
| IDLE_REMIND          | 1   | 提醒设备未被使用。                 |
| ACTIVE_DONOT_REMIND  | 2   | 设备正在使用，无需提醒。            |
| ACTIVE_REMIND        | 3   | 提醒设备正在使用。                 |


## SourceType

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | 一般通知。            |
| TYPE_CONTINUOUS      | 1   | 连续通知。            |
| TYPE_TIMER           | 2   | 计划通知。            |

## NotificationCheckInfo<sup>10+</sup>

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

| 名称                         | 类型                         | 必填 | 说明            |
| ---------------------------- | ---------------------------- | --- | --------------- |
| bundleName                   | string                       | 是   | Bundle名称。    |
| notificationId               | number                       | 是   | 通知ID。        |
| label<sup>11+</sup>          | string                       | 否   | 通知标签。      |
| contentType                  | [ContentType](./js-apis-notificationManager.md#contenttype)  | 是   | 通知类型。      |
| creatorUserId<sup>11+</sup>  | number                       | 是   | 通知的user ID。 |
| slotType<sup>11+</sup>       | [SlotType](./js-apis-notificationManager.md#slottype)        | 是   | 渠道类型。      |
| extraInfos<sup>11+</sup>     | [key: string]: object        | 否   | 通知的附加信息。 |

## NotificationCheckResult<sup>10+</sup>

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

| 名称    | 类型                                  | 必填 | 说明                   |
| ------- | ------------------------------------ | ---- | ---------------------- |
| code    | number                               | 是   | 0-display, 1-no display。 |
| message | string                               | 是   | 结果信息。    |


## ButtonOptions<sup>11+</sup>

描述触发按钮信息。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

| 名称    | 类型                                  | 必填 | 说明                   |
| ------- | ------------------------------------ | ---- | ---------------------- |
| buttonName    | string                         | 是   | 按钮名称。 |


## SystemLiveViewSubscriber<sup>11+</sup>

系统实况窗订阅者。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。


| 名称    | 类型                                  | 必填 | 说明                   |
| ------- | ------------------------------------ | ---- | ---------------------- |
| onResponse    | (notificationId: number, buttonOptions: ButtonOptions) => void;                         | 否   | 点击按钮的回调。 |


## SlotType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                                | 值     | 说明                                                         |
| ----------------------------------- | ------ | ------------------------------------------------------------ |
| EMERGENCY_INFORMATION<sup>12+</sup> | 10     | 紧急事件。**系统接口**: 此接口为系统接口。                               |


## NotificationControlFlagStatus<sup>12+</sup>
每个bit位都可以控制通知的提示方式。当notificationControlFlags和下表中枚举值进行按位或操作，则表示关闭其提示方式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                                 | 值   | 说明     |
| ------------------------------------ | ---- | -------- |
| NOTIFICATION_STATUS_CLOSE_SOUND      | 1<<0 | 关闭声音提示功能。 |
| NOTIFICATION_STATUS_CLOSE_LOCKSCREEN |  1<<1    |     关闭锁屏提示功能。     |
| NOTIFICATION_STATUS_CLOSE_BANNER     |    1<<2   |     关闭横幅提示功能。     |
| NOTIFICATION_STATUS_CLOSE_LIGHT_SCREEN     |   1<<3   |     关闭亮屏提示功能。     |
| NOTIFICATION_STATUS_CLOSE_VIBRATION     |   1<<4   |     关闭振动提示功能。     |
| NOTIFICATION_STATUS_CLOSE_STATUSBAR_ICON     |  1<<5    |     关闭状态栏图标提示功能。     |

