# @ohos.notificationManager (NotificationManager模块)(系统接口)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知渠道，获取通知的使能状态、角标使能状态，获取通知的相关信息等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[NotificationManager](./js-apis-notificationManager.md)。

## 导入模块

```ts
import { notificationManager } from '@kit.NotificationKit';
```

## notificationManager.publish

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

发布通知给指定的用户。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 或 ohos.permission.SEND_NOTIFICATION_CROSS_USER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| userId   | number                                      | 是   | 用户ID。                           |
| callback | AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[HTTP错误码](../apis-network-kit/errorcode-net-http.md)。

| 错误码ID | 错误信息                                              |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                                      |
| 1600002  | Marshalling or unmarshalling error.                  |
| 1600003  | Failed to connect to the service.                    |
| 1600004  | Notification disabled.                               |
| 1600005  | Notification slot disabled.                    |
| 1600007  | The notification does not exist.                       |
| 1600008  | The user does not exist.                               |
| 1600009  | The notification sending frequency reaches the upper limit.            |
| 1600012  | No memory space.                                     |
| 1600014  | No permission.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// publish回调
let publishCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish success");
    }
}
// 用户ID，使用时需替换为真实的userId。
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

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER  或 ohos.permission.SEND_NOTIFICATION_CROSS_USER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     |  类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| userId   | number                                      | 是   | 用户ID。                           |

**返回值：**

| 类型     | 说明        | 
| ------- |-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[HTTP错误码](../apis-network-kit/errorcode-net-http.md)。

| 错误码ID | 错误信息                                              |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                                      |
| 1600002  | Marshalling or unmarshalling error.                  |
| 1600003  | Failed to connect to the service.                           |
| 1600004  | Notification disabled.                         |
| 1600005  | Notification slot disabled.                    |
| 1600007  | The notification does not exist.                       |
| 1600008  | The user does not exist.                               |
| 1600009  | The notification sending frequency reaches the upper limit.            |
| 1600012  | No memory space.                                     |
| 1600014  | No permission.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

// 用户ID，使用时需替换为真实的userId。
let userId: number = 1;

notificationManager.publish(notificationRequest, userId).then(() => {
	console.info("publish success");
}).catch((err: BusinessError) => {
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

创建通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)       | 是   | 要创建的通知渠道对象。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定通道的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// addSlot回调
let addSlotCallBack = (err: BusinessError): void => {
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

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型             | 必填 | 说明                 |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md) | 是   | 要创建的通知渠道对象。 |

**返回值：**

| 类型     | 说明        | 
| ------- |-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 通知slot对象
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot).then(() => {
	console.info("addSlot success");
}).catch((err: BusinessError) => {
    console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

创建多个通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)\> | 是   | 要创建的通知渠道对象数组。数组中的元素个数为0~5。 |
| callback | AsyncCallback\<void\>     | 是   | 表示被指定通道的回调方法。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// addSlots回调
let addSlotsCallBack = (err: BusinessError): void => {
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

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名  | 类型                      | 必填 | 说明                     |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)\> | 是   | 要创建的通知渠道对象数组。数组中的元素个数为0~5。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 通知slot对象
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// 通知slot array 对象
let notificationSlotArray: notificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray).then(() => {
	console.info("addSlots success");
}).catch((err: BusinessError) => {
    console.error(`addSlots failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定应用的通知使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)   | 是   | 指定应用的包信息。        |
| enable   | boolean               | 是   | 使能状态（true：使能，false：禁止）。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知使能回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setNotificationEnableCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`setNotificationEnable failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnable success");
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

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enable | boolean      | 是   | 使能状态（true：使能，false：禁止）。   |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.setNotificationEnable(bundle, false).then(() => {
	console.info("setNotificationEnable success");
}).catch((err: BusinessError) => {
    console.error(`setNotificationEnable failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getAllNotificationEnabledBundles<sup>12+</sup>

getAllNotificationEnabledBundles(): Promise<Array<BundleOption\>>

获取允许通知的应用程序列表。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise<Array<[BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)\>> | 返回允许通知的应用程序列表。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getAllNotificationEnabledBundles().then((data: Array<notificationManager.BundleOption>) => {
    console.info(`Enable bundle data is ${JSON.stringify(data)}`);
    data.forEach(element => {
        console.info(`Enable uid is ${JSON.stringify(element.uid)}`);
        console.info(`Enable bundle is ${JSON.stringify(element.bundle)}`);
    });
}).catch((err: BusinessError) => {
    console.error(`getAllNotificationEnabledBundles failed, code is ${err.code}, message is ${err.message}`);
})
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定应用的通知使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。            |
| callback | AsyncCallback\<boolean\> | 是   | 获取通知使能状态回调函数（true：使能，false：禁止）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isNotificationEnabledCallback = (err: BusinessError, data: boolean): void => {
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

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型               | 说明                                                |
| ------------------ | --------------------------------------------------- |
| Promise\<boolean\> | 以Promise形式返回获取指定应用的通知使能状态的结果（true：使能，false：禁止）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isNotificationEnabled(bundle).then((data: boolean) => {
	console.info(`isNotificationEnabled success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(userId: number, callback: AsyncCallback\<boolean\>): void

获取指定用户ID下的通知使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| userId   | number                | 是   | 指定的用户ID。 |
| callback | AsyncCallback\<boolean\> | 是   | 获取通知使能状态回调函数（true：使能，false：禁止）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isNotificationEnabledCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationEnabled success, data is ${JSON.stringify(data)}`);
    }
}

// 用户ID，使用时需替换为真实的userId。
let userId: number = 1;

notificationManager.isNotificationEnabled(userId, isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(userId: number): Promise\<boolean\>

获取指定用户下的通知使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number       | 是   | 指定的用户ID。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取通知使能状态的结果（true：使能，false：禁止）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600008  | The user does not exist.                  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 用户ID，使用时需替换为真实的userId。
let userId: number = 1;

notificationManager.isNotificationEnabled(userId).then((data: boolean) => {
	console.info(`isNotificationEnabled success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定应用的角标使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。           |
| enable   | boolean               | 是   | 使能状态（true：使能，false：禁止）。             |
| callback | AsyncCallback\<void\> | 是   | 设定角标使能回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801 | Capability not supported. | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayBadgeCallback = (err: BusinessError): void => {
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

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enable | boolean      | 是   | 使能状态（true：使能，false：禁止）。   |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.displayBadge(bundle, false).then(() => {
	console.info("displayBadge success");
}).catch((err: BusinessError) => {
    console.error(`displayBadge failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定应用的角标使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。               |
| callback | AsyncCallback\<boolean\> | 是   | 获取角标使能状态回调函数（true：使能，false：禁止）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isBadgeDisplayedCallback = (err: BusinessError, data: boolean): void => {
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

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取指定应用的角标使能状态（true：使能，false：禁止）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.isBadgeDisplayed(bundle).then((data: boolean) => {
	console.info(`isBadgeDisplayed success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isBadgeDisplayed failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setSlotFlagsByBundle<sup>11+</sup>

setSlotFlagsByBundle(bundle: BundleOption, slotFlags: number): Promise\<void\>

设定指定应用的通知渠道。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| slotFlags   | number | 是   | 通知渠道标识位。<br>- bit0：铃声提示。0表示关闭，1表示开启。 <br>- bit1：锁屏。0表示关闭，1表示开启。 <br>- bit2：横幅。0表示关闭，1表示开启。 <br>- bit3：亮屏。0表示关闭，1表示开启。 <br>- bit4：振动。0表示关闭，1表示开启。 <br>- bit5：状态栏通知图标。0表示关闭，1表示开启。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let slotFlags: number = 1;

notificationManager.setSlotFlagsByBundle(bundle, slotFlags).then(() => {
	console.info("setSlotFlagsByBundle success");
}).catch((err: BusinessError) => {
    console.error(`setSlotFlagsByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

设置指定应用的通知渠道。使用callback异步回调。

设置前需要先通过[addSlot](#notificationmanageraddslot)创建通知渠道。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。           |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)      | 是   | 通知渠道。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知渠道回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setSlotByBundleCallback = (err: BusinessError): void => {
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

设置指定应用的通知渠道。使用Promise异步回调。

设置前需要先通过[addSlot](#notificationmanageraddslot)创建通知渠道。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| slot   | [NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md) | 是   | 通知渠道。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};

notificationManager.setSlotByBundle(bundle, notificationSlot).then(() => {
	console.info("setSlotByBundle success");
}).catch((err: BusinessError) => {
    console.error(`setSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getSlotFlagsByBundle<sup>11+</sup>

getSlotFlagsByBundle(bundle: BundleOption): Promise\<number\>

获取指定应用的通知渠道标识位。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
|  Promise\<number\>| 以Promise形式返回获取指定应用的通知渠道标识位。<br>- bit0：铃声提示。0表示关闭，1表示开启。 <br>- bit1：锁屏。0表示关闭，1表示开启。 <br>- bit2：横幅。0表示关闭，1表示开启。 <br>- bit3：亮屏。0表示关闭，1表示开启。 <br>- bit4：振动。0表示关闭，1表示开启。 <br>- bit5：状态栏通知图标。0表示关闭，1表示开启。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.getSlotFlagsByBundle(bundle).then((data : number) => {
	console.info(`getSlotFlagsByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSlotFlagsByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback\<Array\<NotificationSlot>>): void

获取指定应用的所有通知渠道。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                                     | 必填 | 说明                 |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)                             | 是   | 指定应用的包信息。           |
| callback | AsyncCallback\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)>> | 是   | 获取通知渠道回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getSlotsByBundleCallback = (err: BusinessError, data: Array<notificationManager.NotificationSlot>): void => {
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

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)>> | 以Promise形式返回获取指定应用的通知渠道。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

notificationManager.getSlotsByBundle(bundle).then((data: Array<notificationManager.NotificationSlot>) => {
	console.info(`getSlotsByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSlotsByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

获取指定应用的通知渠道数量。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)              | 是   | 指定应用的包信息。             |
| callback | AsyncCallback\<number\> | 是   | 获取通知渠道数量回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getSlotNumByBundleCallback = (err: BusinessError, data: number): void => {
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

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取指定应用的通知渠道数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.getSlotNumByBundle(bundle).then((data: number) => {
	console.info(`getSlotNumByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSlotNumByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void

获取当前未删除的所有通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)>> | 是   | 获取活动通知回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getAllActiveNotificationsCallback = (err: BusinessError, data: Array<notificationManager.NotificationRequest>): void => {
    if (err) {
        console.error(`getAllActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getAllActiveNotifications success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.getAllActiveNotifications(getAllActiveNotificationsCallback);
```

## notificationManager.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<NotificationRequest\>\>

获取当前未删除的所有通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)\>\> | 以Promise形式返回获取活动通知。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getAllActiveNotifications().then((data: Array<notificationManager.NotificationRequest>) => {
	console.info(`getAllActiveNotifications success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getAllActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getActiveNotificationByFilter<sup>11+</sup>

getActiveNotificationByFilter(filter: NotificationFilter, callback: AsyncCallback\<NotificationRequest\>): void

获取满足条件的普通实况通知信息。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。


**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| filter   | [NotificationFilter](js-apis-inner-notification-notificationRequest-sys.md#notificationfilter11) | 是   | 查询普通实况窗的过滤条件。 |
| callback | AsyncCallback\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)> | 是   | 获取满足条件的普通实况通知信息的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                  |
| -------- | ---------------------------------------- | 
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600007  | The notification does not exist.           |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { notificationSubscribe } from '@kit.NotificationKit';

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
let getActiveNotificationByFilterCallback = (err: BusinessError, data: notificationManager.NotificationRequest): void => {
    if (err) {
        console.error(`getActiveNotificationByFilter failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getActiveNotificationByFilter success");
    }
}
notificationManager.getActiveNotificationByFilter(filter, getActiveNotificationByFilterCallback);
```

## notificationManager.getActiveNotificationByFilter<sup>11+</sup>

getActiveNotificationByFilter(filter: NotificationFilter): Promise\<NotificationRequest\>

获取满足条件的普通实况通知信息。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。


**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| filter   | [NotificationFilter](js-apis-inner-notification-notificationRequest-sys.md#notificationfilter11) | 是   | 查询普通实况窗的过滤条件。 |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)\> | 以Promise形式返回获取的满足条件的普通实况通知信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                  |
| -------- | ---------------------------------------- | 
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600007  | The notification does not exist.         |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { notificationSubscribe } from '@kit.NotificationKit';

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
	console.info(`getActiveNotificationByFilter success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getActiveNotificationByFilter failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

删除指定应用的指定组下的通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名      | 类型                  | 必填 | 说明                         |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 应用的包信息。                   |
| groupName | string                | 是   | 通知组名称。               |
| callback  | AsyncCallback\<void\> | 是   | 删除指定应用指定组下通知的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let removeGroupByBundleCallback = (err: BusinessError): void => {
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

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名      | 类型         | 必填 | 说明           |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。     |
| groupName | string       | 是   | 通知组名称。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundleOption: notificationManager.BundleOption = { bundle: "Bundle" };
let groupName: string = "GroupName";

notificationManager.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle success");
}).catch((err: BusinessError) => {
    console.error(`removeGroupByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

设置免打扰时间。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | 是   | 免打扰时间选项。         |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setDoNotDisturbDateCallback = (err: BusinessError): void => {
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

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型             | 必填 | 说明           |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate) | 是   | 免打扰时间选项。 |


**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};
notificationManager.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: BusinessError) => {
    console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

指定用户设置免打扰时间。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | 是   | 免打扰时间选项。         |
| userId   | number                | 是   | 设置免打扰时间的用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setDoNotDisturbDateCallback = (err: BusinessError): void => {
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

// 用户ID，使用时需替换为真实的userId。
let userId: number = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId, setDoNotDisturbDateCallback);
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

指定用户设置免打扰时间。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate) | 是   | 免打扰时间选项。 |
| userId | number           | 是   | 设置免打扰时间的用户ID。 |

**返回值：**

| 类型      | 说明        | 
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

// 用户ID，使用时需替换为真实的userId。
let userId: number = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: BusinessError) => {
    console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

查询免打扰时间。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | 是   | 查询免打扰时间回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getDoNotDisturbDateCallback = (err: BusinessError, data: notificationManager.DoNotDisturbDate): void => {
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

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                                             | 说明                                      |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | 以Promise形式返回获取查询到的免打扰时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getDoNotDisturbDate().then((data: notificationManager.DoNotDisturbDate) => {
  console.info(`getDoNotDisturbDate success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

查询指定用户的免打扰时间。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | 是   | 查询免打扰时间回调函数。 |
| userId   | number                            | 是   | 用户ID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getDoNotDisturbDateCallback = (err: BusinessError, data: notificationManager.DoNotDisturbDate): void => {
    if (err) {
        console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getDoNotDisturbDate success, data is ${JSON.stringify(data)}`);
    }
}

// 用户ID，使用时需替换为真实的userId。
let userId: number = 1;

notificationManager.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```

## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

查询指定用户的免打扰时间。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| userId   | number                            | 是   | 用户ID。 |

**返回值：**

| 类型                                             | 说明                                      |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | 以Promise形式返回获取查询到的免打扰时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 用户ID，使用时需替换为真实的userId。
let userId: number = 1;

notificationManager.getDoNotDisturbDate(userId).then((data: notificationManager.DoNotDisturbDate) => {
	console.info(`getDoNotDisturbDate success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.isSupportDoNotDisturbMode

 isSupportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

查询是否支持免打扰功能。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                     | 必填 | 说明                             |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 查询是否支持免打扰功能回调函数（true：支持，false：不支持）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                             |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isSupportDoNotDisturbModeCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isSupportDoNotDisturbMode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isSupportDoNotDisturbMode success, data: ${JSON.stringify(data)}`);
    }
}

notificationManager.isSupportDoNotDisturbMode(isSupportDoNotDisturbModeCallback);
```

## notificationManager.isSupportDoNotDisturbMode

isSupportDoNotDisturbMode(): Promise\<boolean\>

查询是否支持免打扰功能。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取是否支持免打扰功能的结果（true：支持，false：不支持）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.isSupportDoNotDisturbMode().then((data: boolean) => {
	console.info(`isSupportDoNotDisturbMode success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isSupportDoNotDisturbMode failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean, callback: AsyncCallback\<void\>): void

设置设备是否支持分布式通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持（true：支持，false：不支持）。 |
| callback | AsyncCallback\<void\> | 是   | 设置设备是否支持分布式通知的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setDistributedEnableCallback = (err: BusinessError): void => {
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

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持（true：支持，false：不支持）。 |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;
notificationManager.setDistributedEnable(enable).then(() => {
    console.info("setDistributedEnable success");
}).catch((err: BusinessError) => {
    console.error(`setDistributedEnable failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

设置指定应用是否支持分布式通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包信息。                   |
| enable   | boolean                  | 是   | 指定应用是否支持分布式通知（true：支持，false：不支持）。|
| callback | AsyncCallback\<void\> | 是   | 应用程序是否支持分布式通知的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setDistributedEnableByBundleCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`setDistributedEnableByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDistributedEnableByBundle success");
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

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                |
| enable   | boolean                  | 是   | 指定应用是否支持分布式通知（true：支持，false：不支持）。                  |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
let enable: boolean = true;
notificationManager.setDistributedEnableByBundle(bundle, enable).then(() => {
    console.info("setDistributedEnableByBundle success");
}).catch((err: BusinessError) => {
    console.error(`setDistributedEnableByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

根据应用的包获取应用程序是否支持分布式通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                     |
| callback | AsyncCallback\<boolean\> | 是   | 查询指定应用是否支持分布式通知的回调函数（true：支持，false：不支持）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isDistributedEnabledByBundleCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isDistributedEnabledByBundle success, data: ${JSON.stringify(data)}`);
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

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                |

**返回值：**

| 类型               | 说明                                              |
| ------------------ | ------------------------------------------------- |
| Promise\<boolean\> | Promise方式返回指定应用是否支持分布式通知的结果（true：支持，false：不支持）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isDistributedEnabledByBundle(bundle).then((data: boolean) => {
    console.info(`isDistributedEnabledByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.getDeviceRemindType

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

获取通知的提醒方式。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                               | 必填 | 说明                       |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype)\> | 是   | 获取通知提醒方式的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getDeviceRemindTypeCallback = (err: BusinessError, data: notificationManager.DeviceRemindType): void => {
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

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype)\> | Promise方式返回获取通知提醒方式的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getDeviceRemindType().then((data: notificationManager.DeviceRemindType) => {
    console.info(`getDeviceRemindType success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDeviceRemindType failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

发布代理通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名               | 类型                                        | 必填 | 说明                                     |
| -------------------- | ------------------------------------------- | ---- | ---------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| representativeBundle | string                                      | 是   | 被代理应用的包名。                       |
| userId               | number                                      | 是   | 用户ID。                                 |
| callback             | AsyncCallback\<void\>                        | 是   | 发布代理通知的回调方法。                 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[HTTP错误码](../apis-network-kit/errorcode-net-http.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect to the service.                |
| 1600004  | Notification disabled.              |
| 1600005  | Notification slot disabled.         |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.                    |
| 1600009  | The notification sending frequency reaches the upper limit. |
| 1600012  | No memory space.                          |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

//publishAsBundle回调
let callback = (err: BusinessError): void => {
    if (err) {
        console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsBundle success");
    }
}
// 被代理应用的包名
let representativeBundle: string = "com.example.demo";
// 用户ID，使用时需替换为真实的userId。
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

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**


| 参数名               | 类型                                        | 必填 | 说明                                          |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| representativeBundle | string                                      | 是   | 被代理应用的包名。                            |
| userId               | number                                      | 是   | 用户ID。                            |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[HTTP错误码](../apis-network-kit/errorcode-net-http.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect to the service.                |
| 1600004  | Notification disabled.                    |
| 1600005  | Notification slot disabled.         |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.                    |
| 1600009  | The notification sending frequency reaches the upper limit. |
| 1600012  | No memory space.                          |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 被代理应用的包名
let representativeBundle: string = "com.example.demo";
// 用户ID，使用时需替换为真实的userId。
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
}).catch((err: BusinessError) => {
    console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.publishAsBundle<sup>12+</sup>

publishAsBundle(representativeBundle: BundleOption, request: NotificationRequest): Promise\<void\>

发布代理通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**


| 参数名               | 类型                                        | 必填 | 说明                                          |
|----------------------|--------------------------------------------|------|-----------------------------------------------|
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  | 是   | 被代理应用的包信息。                            |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[HTTP错误码](../apis-network-kit/errorcode-net-http.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect to the service.                |
| 1600004  | Notification disabled.              |
| 1600005  | Notification slot disabled.         |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.                    |
| 1600009  | The notification sending frequency reaches the upper limit. |
| 1600012  | No memory space.                          |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
}).catch((err: BusinessError) => {
    console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

取消代理通知。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名               | 类型          | 必填 | 说明                     |
| -------------------- | ------------- | ---- | ------------------------ |
| id                   | number        | 是   | 通知ID。                 |
| representativeBundle | string        | 是   | 被代理应用的包名。       |
| userId               | number        | 是   | 用户ID。       |
| callback             | AsyncCallback\<void\> | 是   | 取消代理通知的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.              |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// cancelAsBundle
let cancelAsBundleCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelAsBundle success");
    }
}
// 被代理应用的包名
let representativeBundle: string = "com.example.demo";
// 用户ID，使用时需替换为真实的userId。
let userId: number = 100;
notificationManager.cancelAsBundle(0, representativeBundle, userId, cancelAsBundleCallback);
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void\>

取消代理通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名               | 类型   | 必填 | 说明               |
| -------------------- | ------ | ---- | ------------------ |
| id                   | number | 是   | 通知ID。           |
| representativeBundle | string | 是   | 被代理应用的包名。 |
| userId               | number | 是   | 用户ID。 |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.              |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 被代理应用的包名
let representativeBundle: string = "com.example.demo";
// 用户ID，使用时需替换为真实的userId。
let userId: number = 100;
notificationManager.cancelAsBundle(0, representativeBundle, userId).then(() => {
	console.info("cancelAsBundle success");
}).catch((err: BusinessError) => {
    console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.cancelAsBundle<sup>12+</sup>

cancelAsBundle(representativeBundle: BundleOption, id: number): Promise\<void\>

取消代理通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**


| 参数名               | 类型                                        | 必填 | 说明                                          |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  |是   | 被代理应用的包信息。 |
| id                   | number                                     | 是   | 通知ID。           |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect to the service.                |
| 1600007  | The notification does not exist.            |
| 1600008  | The user does not exist.                    |
| 1600012  | No memory space.                          |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let representativeBundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
notificationManager.cancelAsBundle(representativeBundle, 1).then(() => {
	console.info("cancelAsBundle success");
}).catch((err: BusinessError) => {
    console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.cancel<sup>12+</sup>

cancel(representativeBundle: BundleOption, id: number): Promise\<void\>

代理取消当前用户其他应用的通知。使用Promise异步回调。

需要当前应用与其他应用存在代理关系，或者当前应用有ohos.permission.NOTIFICATION_AGENT_CONTROLLER权限。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

**参数：**

| 参数名               | 类型   | 必填 | 说明               |
| -------------------- | ------ | ---- | ------------------ |
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。           |
|       id             | number | 是   | 通知ID。 |

**返回值：**

| 类型              | 说明        | 
|-----------------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification does not exist.      |
| 1600012  | No memory space.                    |
| 1600017  | There is no corresponding agent relationship configuration.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName"
};
let id: number = 1;
notificationManager.cancel(bundle, id).then(() => {
  console.info("cancel success");
}).catch((err: BusinessError) => {
  console.error(`cancel failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setNotificationEnableSlot 

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

设置指定应用的指定渠道类型的使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// setNotificationEnableSlot
let setNotificationEnableSlotCallback = (err: BusinessError): void => {
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

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                          | 必填 | 说明                     |
| -------- | ----------------------------- | ---- | ----------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。|
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | 是   | 指定渠道类型。           |
| enable   | boolean                       | 是   | 使能状态（true：使能，false：禁止）。               |
| isForceControl<sup>11+</sup> | boolean                 | 是   | 渠道开关是否受通知授权开关影响（false：受影响，true：不受影响）。 |
| callback | AsyncCallback\<void\>         | 是   | 设置渠道使能回调函数。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setNotificationEnableSlotCallback = (err: BusinessError): void => {
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

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。   |
| type   | [SlotType](./js-apis-notificationManager.md#slottype)         | 是   | 渠道类型。 |
| enable | boolean                       | 是   | 使能状态（true：使能，false：禁止）。     |
| isForceControl<sup>11+</sup> | boolean               | 否   | 渠道开关是否受通知总开关影响（false：受总开关影响，true：不受总开关影响）。默认为false。     |

**返回值：**

| 类型     | 说明         |
| ------- |------------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// setNotificationEnableSlot
notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true).then(() => {
        console.info("setNotificationEnableSlot success");
    }).catch((err: BusinessError) => {
        console.error(`setNotificationEnableSlot failed, code is ${err.code}, message is ${err.message}`);
    });
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean\>): void

获取指定应用的指定渠道类型的使能状态。使用callback异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名   | 类型                          | 必填 | 说明                   |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。           |
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | 是   | 渠道类型。         |
| callback | AsyncCallback\<boolean\>         | 是   | 获取渠道使能状态回调函数（true：使能，false：禁止）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// isNotificationSlotEnabledCallback
let isNotificationSlotEnabledCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationSlotEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationSlotEnabled success, data is ${JSON.stringify(data)}`);
    }
};

notificationManager.isNotificationSlotEnabled(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    isNotificationSlotEnabledCallback);
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise\<boolean\>  

获取指定应用的指定渠道类型的使能状态。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// isNotificationSlotEnabled
notificationManager.isNotificationSlotEnabled({ bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION).then((data: boolean) => {
    console.info(`isNotificationSlotEnabled success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isNotificationSlotEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void\>): void

设置是否将通知同步到未安装应用程序的设备(callback形式)。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |
| enable | boolean | 是   | 是否启用（true：使能，false：禁止）。   |
| callback | AsyncCallback\<void\>    | 是   | 设置是否将通知同步到未安装应用程序的设备的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 用户ID，使用时需替换为真实的userId。
let userId: number = 100;
let enable: boolean = true;
let setSyncNotificationEnabledWithoutAppCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`setSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setSyncNotificationEnabledWithoutApp success");
    }
}
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable, setSyncNotificationEnabledWithoutAppCallback);
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>

设置是否将通知同步到未安装应用程序的设备(Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 用户ID，使用时需替换为真实的userId。
let userId: number = 100;
let enable: boolean = true;
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable).then(() => {
    console.info('setSyncNotificationEnabledWithoutApp success');
}).catch((err: BusinessError) => {
    console.error(`setSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 用户ID，使用时需替换为真实的userId。
let userId: number = 100;
let getSyncNotificationEnabledWithoutAppCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`getSyncNotificationEnabledWithoutAppCallback failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getSyncNotificationEnabledWithoutAppCallback success, data: ${JSON.stringify(data)}`);
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 用户ID，使用时需替换为真实的userId。
let userId: number = 100;
notificationManager.getSyncNotificationEnabledWithoutApp(userId).then((data: boolean) => {
  console.info(`getSyncNotificationEnabledWithoutApp, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.on<sup>10+</sup>

on(type: 'checkNotification', callback: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void

注册通知监听回调。通知服务将通知信息回调给校验程序，校验程序返回校验结果决定该通知是否发布，如营销类通知发布频率控制等。

系统中每个[SlotType](./js-apis-notificationManager.md#slottype)只允许存在一个注册者。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                                                                                                                      | 必填 | 说明           |
| ------ |-------------------------------------------------------------------------------------------------------------------------| ---- | -------------- |
| type | string                                                                                                                  | 是   | 回调函数类型名，固定为'checkNotification'。 |
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo10)) =>  [NotificationCheckResult](#notificationcheckresult10) | 是   | 消息验证函数指针。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- | 
| 202      | Not system application.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
} catch (err){
    console.error(`notificationManager.on failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.on<sup>11+</sup>

on(type: 'checkNotification', checkRequest: NotificationCheckRequest, callback: (checkInfo: NotificationCheckInfo) => Promise\<NotificationCheckResult\>): void

注册通知监听回调。通知服务将通知信息回调给校验程序，校验程序返回校验结果决定该通知是否发布，如营销类通知发布频率控制等。使用Promise异步回调。

系统中每个[SlotType](./js-apis-notificationManager.md#slottype)只允许存在一个注册者。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try{
  notificationManager.on('checkNotification',{
    contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_LIVE_VIEW,
    slotType: notificationManager.SlotType.LIVE_VIEW ,
    extraInfoKeys: ["event"],
  },
    async (checkInfo)=>{
      return { code: 1, message: "INVALID_PARAMETERS"};
  },);
} catch (err) {
  console.error(`notificationManager.on failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.off<sup>10+</sup>

off(type: 'checkNotification', callback?: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Not system application.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try{
    notificationManager.off("checkNotification");
} catch (err){
    console.error(`notificationManager.off failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.triggerSystemLiveView<sup>11+</sup>

triggerSystemLiveView(bundle: BundleOption, notificationId: number, buttonOptions: ButtonOptions): Promise\<void>

触发系统实况窗。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

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
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification does not exist.      |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
}).catch((err: BusinessError) => {
  console.error(`triggerSystemLiveView failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.subscribeSystemLiveView<sup>11+</sup>

subscribeSystemLiveView(subscriber: SystemLiveViewSubscriber): Promise\<void>

订阅系统实况窗。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                   | 必填 | 说明           |
| -------------- | ------------- | ---- | -------------- |
| subscriber | [SystemLiveViewSubscriber](#systemliveviewsubscriber11)  | 是   | 系统实况窗订阅者。|

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onResponseCallback = (id:number, option:notificationManager.ButtonOptions) => {
    console.info(`notificationId: ${id},onResponseCallback: ${JSON.stringify(option)}`);
}
let subscriber: notificationManager.SystemLiveViewSubscriber  = {
    onResponse: onResponseCallback,
};
notificationManager.subscribeSystemLiveView(subscriber).then(() => {
	console.info("subscribeSystemLiveView success");
}).catch((err: BusinessError) => {
    console.error(`subscribeSystemLiveView failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDistributedEnabledByBundle<sup>12+</sup>

setDistributedEnabledByBundle(bundle: BundleOption, deviceType: string, enable: boolean): Promise<void\>

设置指定应用是否支持跨设备协同。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包信息。                   |
| deviceType | string | 是   | 设备类型。|
| enable   | boolean                  | 是   | 指定应用是否支持跨设备协同（true：支持，false：不支持）。|

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
    uid: 1
};
let enable: boolean = true;
let deviceType: string = "phone";
notificationManager.setDistributedEnabledByBundle(bundle, deviceType, enable).then(() => {
    console.info("setDistributedEnabledByBundle success");
}).catch((err: BusinessError) => {
    console.error(`setDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isDistributedEnabledByBundle<sup>12+</sup>

isDistributedEnabledByBundle(bundle: BundleOption, deviceType: string): Promise<boolean\>

获取指定应用是否支持跨设备协同。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包信息。                   |
| deviceType | string | 是   | 设备类型。 |

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<boolean\> | 以Promise形式返回指定应用是否支持跨设备协同的开关是否开启的结果（true：开启，false：未开启）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
    uid: 1
};
let deviceType: string = "phone";
notificationManager.isDistributedEnabledByBundle(bundle, deviceType).then((data: boolean) => {
    console.info(`isDistributedEnabledByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setSmartReminderEnabled<sup>12+</sup>

setSmartReminderEnabled(deviceType: string, enable: boolean): Promise<void\>

设置设备是否与其他设备协同智能提醒。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| deviceType | string | 是   | 设备类型。 |
| enable   | boolean                  | 是   | 指定应用是否支持设备是否与其他设备协同智能提醒（true：支持，false：不支持）。|

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let deviceType: string = "phone";
let enable: boolean = true;
notificationManager.setSmartReminderEnabled(deviceType, enable).then(() => {
    console.info("setSmartReminderEnabled success");
}).catch((err: BusinessError) => {
    console.error(`setSmartReminderEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isSmartReminderEnabled<sup>12+</sup>

isSmartReminderEnabled(deviceType: string): Promise<boolean\>

获取设备是否与其他设备协同智能提醒。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| deviceType | string | 是   | 设备类型。 |

**返回值：**

| 类型 | 说明 |
| ---- | ----|
| Promise\<boolean\> | 以Promise形式返回设备与其他设备协同智能提醒的开关是否开启的结果（true：开启，false：未开启）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let deviceType: string = "phone";
notificationManager.isSmartReminderEnabled(deviceType).then((data: boolean) => {
    console.info(`isSmartReminderEnabled success， data:${data}`);
}).catch((err: BusinessError) => {
    console.error(`isSmartReminderEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setBadgeNumberByBundle<sup>12+</sup>

setBadgeNumberByBundle(bundle: BundleOption, badgeNumber: number): Promise\<void\>

代理其他应用设定角标个数。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| bundle | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| badgeNumber | number | 是   | 角标个数。 |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |
| 1600017  | There is no corresponding agent relationship configuration.     |
| 17700001 | The specified bundle name was not found.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: 'com.example.bundleName',
};
let badgeNumber: number = 10;

notificationManager.setBadgeNumberByBundle(bundle, badgeNumber).then(() => {
    console.info('setBadgeNumberByBundle success');
}).catch((err: BusinessError) => {
    console.error(`setBadgeNumberByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getSlotByBundle<sup>12+</sup>

getSlotByBundle(bundle: BundleOption, slotType: SlotType): Promise\<NotificationSlot>

获取指定应用指定类型的通知渠道。使用Promise异步回调。

获取前需要先通过[addSlot](#notificationmanageraddslot)创建通知渠道。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| slotType | [SlotType](././js-apis-notificationManager.md#slottype) | 是   | 渠道类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)> | 以Promise形式返回获取指定应用指定类型的通知渠道。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let slotType = notificationManager.SlotType.LIVE_VIEW;

notificationManager.getSlotByBundle(bundle, slotType).then((data: notificationManager.NotificationSlot) => {
	console.info(`getSlotByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.addDoNotDisturbProfile<sup>12+</sup>

addDoNotDisturbProfile(templates: Array\<DoNotDisturbProfile>): Promise\<void\>

添加勿扰模式配置信息。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| templates   | Array\<[DoNotDisturbProfile](#donotdisturbprofile12)> | 是 | 勿扰模式的配置信息。 |

**返回值：**

| 类型      | 说明        |
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let trustlist: Array<notificationManager.BundleOption> = [
  {
    bundle: 'com.example.bundleName',
    uid: 0
  },
  {
    bundle: 'com.example.bundleName1',
    uid: 1
  }
]
let templates: Array<notificationManager.DoNotDisturbProfile> = [
  {
    id: 3,
    name: '工作模式',
    trustlist: trustlist
  }
]

notificationManager.addDoNotDisturbProfile(templates).then(() => {
  console.info("addDoNotDisturbProfile success.");
}).catch((err: BusinessError) => {
  console.error(`addDoNotDisturbProfile failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.removeDoNotDisturbProfile<sup>12+</sup>

removeDoNotDisturbProfile(templates: Array\<DoNotDisturbProfile>): Promise\<void\>

删除勿扰模式配置。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| templates   | Array\<[DoNotDisturbProfile](#donotdisturbprofile12)> | 是  | 勿扰模式的配置信息。 |

**返回值：**

| 类型      | 说明        |
|---------|-----------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let templates: Array<notificationManager.DoNotDisturbProfile> = [
  {
    id: 3,
    name: '工作模式'
  }
]
notificationManager.removeDoNotDisturbProfile(templates).then(() => {
  console.info("removeDoNotDisturbProfile success.");
}).catch((err: BusinessError) => {
  console.error(`removeDoNotDisturbProfile failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setAdditionalConfig<sup>12+</sup>

setAdditionalConfig(key: string, value: string): Promise\<number\>

设置通知的系统附加配置信息。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| key   | string | 是  | 附加配置键。目前仅支持`RING_TRUSTLIST_PKG`，表示应用支持使用[自定义铃声](./js-apis-inner-notification-notificationRequest.md#notificationrequest-1)。 |
| value   | string | 是  | 附加配置值。参数示例：[bundleName1,bundleName2]。 |

**返回值：**

| 类型      | 说明        |
|---------|-----------|
| Promise\<number\> | Promise对象，返回0表示设置成功，返回其他值表示设置失败。 |

**错误码：**

以下错误码的详细介绍请参见[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.setAdditionalConfig('RING_TRUSTLIST_PKG','[bundleName1,bundleName2]').then((data: number) => {
  console.info(`setAdditionalConfig success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`setAdditionalConfig failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getDoNotDisturbProfile<sup>13+</sup>

getDoNotDisturbProfile(id: number): Promise\<DoNotDisturbProfile\>

查询勿扰模式配置信息。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable、TV中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| id   | number | 是  | 勿扰模式编号。 |

**返回值：**

| 类型      | 说明        |
|---------|-----------|
| Promise\<[DoNotDisturbProfile](#donotdisturbprofile12)\> | Promise对象，返回勿扰模式的配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |
| 202      | Not system application to call the interface.                                      |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600019  | The do-not-disturb profile does not exist.                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getDoNotDisturbProfile(1).then((data: notificationManager.DoNotDisturbProfile) => {
  console.info(`getDoNotDisturbProfile success: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getDoNotDisturbProfile failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.disableNotificationFeature<sup>18+</sup>

disableNotificationFeature(disabled: boolean, bundleList: Array\<string\>): Promise\<void\>

将应用包名添加到通知发布权限管控名单，以阻止应用发布通知。支持启用或关闭该功能。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 或 ohos.permission.MANAGE_EDM_POLICY

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| disabled | boolean | 是   | 是否启用通知发布权限管控名单（true：开启，false：关闭）。 |
| bundleList | Array\<string\> | 是   | 指定通知发布权限管控名单的应用列表，使用包名代表应用。 |

**返回值：**

| 类型            | 说明                     | 
|-----------------|-------------------------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application to call the interface. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 1600001      | Internal error.                     |
| 1600002      | Marshalling or unmarshalling error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let disabled: boolean = true;
let bundleList: Array<string> = ["com.example.myapplication"];
try {
  notificationManager.disableNotificationFeature(disabled, bundleList).then(() => {
    hilog.info(0x0000, 'testTag', '%{public}s', `disableNotificationFeature success.`);
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `disableNotificationFeature failed, code is ${err.code}, message is ${err.message}`);
  });
} catch (err) {
  hilog.error(0x0000, 'testTag', '%{public}s', `testTag failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.disableNotificationFeature<sup>20+</sup>

disableNotificationFeature(disabled: boolean, bundleList: Array\<string\>, userId: number): Promise\<void\>

将应用包名添加到通知发布权限管控名单，以阻止应用发布通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**设备行为差异**：该接口在Wearable中返回801错误码，在其他设备类型中可正常调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 或 ohos.permission.MANAGE_EDM_POLICY

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| disabled | boolean | 是   | 表示是否启用通知发布权限管控名单。true表示启用，false表示关闭。 |
| bundleList | Array\<string\> | 是   | 指定通知发布权限管控名单的应用列表，使用包名表示应用。 |
| userId | number | 是   | 表示用户ID。 |

**返回值：**

| 类型            | 说明                     | 
|-----------------|-------------------------|
| Promise\<void\> | Promise对象，无返回结果。 | 

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[通知错误码](./errorcode-notification.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 1600001      | Internal error.                     |
| 1600002      | Marshalling or unmarshalling error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let disabled: boolean = true;
let bundleList: Array<string> = ["com.example.myapplication"];
let userId: number = 1;
try {
  notificationManager.disableNotificationFeature(disabled, bundleList, userId).then(() => {
    hilog.info(0x0000, 'testTag', '%{public}s', `disableNotificationFeature success.`);
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `disableNotificationFeature failed, code is ${err.code}, message is ${err.message}`);
  });
} catch (err) {
  hilog.error(0x0000, 'testTag', '%{public}s', `testTag failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.setTargetDeviceStatus<sup>18+</sup>

setTargetDeviceStatus(deviceType: string, status: number): Promise\<void\>

设置设备配对成功后的状态。当发布通知时，会根据各个设备的状态来确定当前设备的通知提醒方式。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| deviceType | string | 是   | 设备类型。当前仅支持`headset`（可穿戴式音频设备）、`liteWearable`（轻量级智能穿戴设备）、`wearable`（智能穿戴设备）、`current`（本设备）。 |
| status | number | 是   | 设备状态。<br>- bit0：设备是否正在被使用。0表示未使用，1表示使用中。<br>- bit1：当前设备使用者是否为机主。0表示为非机主，1表示为机主。<br>- bit2：设备是否处于勿扰模式。0表示处于非勿扰模式，1表示处于勿扰模式。 |

**返回值：**

| 类型            | 说明                     | 
|-----------------|-------------------------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application to call the interface. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.setTargetDeviceStatus("current", 1).then(() => {
  console.info(`Succeeded in setting target device status.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set target device status. Code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDistributedEnabledBySlot<sup>18+</sup>

setDistributedEnabledBySlot(slot: SlotType, deviceType: string, enabled: boolean): Promise\<void\>

设置指定渠道的通知是否支持通知跨设备协同至指定类型设备。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| slot | [SlotType](js-apis-notificationManager.md#slottype) | 是   | 通知渠道类型。 |
| deviceType | string | 是   | 设备类型。<br>从API version 18开始，支持的设备类型如下：<br>- headset（可穿戴式音频设备）。<br>- liteWearable（轻量级智能穿戴设备）。<br>- wearable（智能穿戴设备）。<br>从API version 20开始，支持的设备类型如下：<br>- headset（可穿戴式音频设备）。<br>- liteWearable（轻量级智能穿戴设备）。<br>- wearable（智能穿戴设备）。<br>- current（本设备）。<br>- 2in1（PC设备）。<br>- tablet（平板）。 |
| enabled | boolean | 是   | 是否开启通知跨设备协同开关。取值为true表示打开，取值为false表示关闭。 |

**返回值：**

| 类型            | 说明                     | 
|-----------------|-------------------------|
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 | 

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application to call the interface. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let slot: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
let deviceType: string = 'wearable';
let enabled: boolean = true;

notificationManager.setDistributedEnabledBySlot(slot, deviceType, enabled).then(() => {
    hilog.info(0x0000, 'testTag', '%{public}s', `setDistributedEnabledBySlot success.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `setDistributedEnabledBySlot failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isDistributedEnabledBySlot<sup>18+</sup>

isDistributedEnabledBySlot(slot: SlotType, deviceType: string): Promise\<boolean\>

查询指定渠道的通知是否支持通知跨设备协同至指定类型设备。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| slot | [SlotType](js-apis-notificationManager.md#slottype) | 是   | 通知渠道类型。 |
| deviceType | string | 是   | 设备类型。<br>从API version 18开始，支持的设备类型如下：<br>- headset（可穿戴式音频设备）。<br>- liteWearable（轻量级智能穿戴设备）。<br>- wearable（智能穿戴设备）。<br>从API version 20开始，支持的设备类型如下：<br>- headset（可穿戴式音频设备）。<br>- liteWearable（轻量级智能穿戴设备）。<br>- wearable（智能穿戴设备）。<br>- current（本设备）。<br>- 2in1（PC设备）。<br>- tablet（平板）。 |

**返回值：**

| 类型            | 说明                     | 
|-----------------|-------------------------|
| Promise\<boolean\> | Promise对象，返回true表示指定渠道的通知支持通知跨设备协同至指定类型设备；返回false表示指定渠道的通知不支持通知跨设备协同至指定类型设备。 | 

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application to call the interface. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let slot: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
let deviceType: string = 'wearable';

notificationManager.isDistributedEnabledBySlot(slot, deviceType).then((data: boolean) => {
    hilog.info(0x0000, 'testTag', '%{public}s', `isDistributedEnabledBySlot success.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `isDistributedEnabledBySlot failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setSilentReminderEnabled<sup>20+</sup>

setSilentReminderEnabled(bundle: BundleOption, enabled: boolean): Promise\<void\>

设置静默提醒的开关状态。使用Promise进行异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enabled | boolean | 是   | 表示是否开启通知静默提醒开关。true表示打开，false表示关闭。 |

**返回值：**

| 类型            | 说明                     | 
|-----------------|-------------------------|
| Promise\<void\> | Promise对象，无返回结果。 | 

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName",
};
notificationManager.setSilentReminderEnabled(bundle, true).then(() => {
    hilog.info(0x0000, 'testTag', '%{public}s', `setSilentReminderEnabled success.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `setSilentReminderEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isSilentReminderEnabled<sup>20+</sup>

isSilentReminderEnabled(bundle: BundleOption): Promise\<SwitchState\>

查询静默提醒的开关状态。使用Promise进行异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型            | 说明                     | 
|-----------------|-------------------------|
| Promise\<[SwitchState](#switchstate20)\> | Promise对象，返回指定应用的通知静默提醒开关状态。 | 

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[通知错误码](./errorcode-notification.md)、[包管理子系统通用错误码](../../reference/apis-ability-kit/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isSilentReminderEnabled(bundle).then((data: notificationManager.SwitchState) => {
    hilog.info(0x0000, 'testTag', '%{public}s', `isSilentReminderEnabled success, switchState:  ${JSON.stringify(data)}.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `isSilentReminderEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isDistributedEnabled<sup>20+</sup>

isDistributedEnabled(deviceType: string): Promise\<boolean\>

查询设备是否支持跨设备协同通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| deviceType | string | 是   | 设备类型。当前仅支持以下类型：<br>- headset（可穿戴式音频设备）。<br>- liteWearable（轻量级智能穿戴设备）。<br>- wearable（智能穿戴设备）。<br>- current（本设备）。<br>- 2in1（PC设备）。<br>- tablet（平板）。 |

**返回值：**

| 类型            | 说明                     |
|-----------------|-------------------------|
| Promise\<boolean\> | 返回设备是否支持跨设备协同通知的结果，返回true表示支持；返回false表示不支持。Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application to call the interface. |

**示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
  }

  onForeground(): void {
    try {
      let deviceType: string = "wearable";
      notificationManager.isDistributedEnabled(deviceType).then((data: boolean) => {
        console.info('isDistributedEnabled succeeded, result = ' + data);
      }).catch((err: BusinessError) => {
        console.error(`isDistributedEnabled failed. Code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      console.error(`isDistributedEnabled failed. Code is ${err.code}, message is ${err.message}`);
    }
  }
}
```

## notificationManager.setDistributedEnabled<sup>20+</sup>

setDistributedEnabled(enable: boolean, deviceType: string): Promise\<void\>

设置设备是否支持跨设备协同通知。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| enable   | boolean | 是   | 表示指定设备类型是否支持跨设备协同通知。true表示支持，false表示不支持。 |
| deviceType | string | 是   | 设备类型。当前仅支持以下类型：<br>- headset（可穿戴式音频设备）。<br>- liteWearable（轻量级智能穿戴设备）。<br>- wearable（智能穿戴设备）。<br>- current（本设备）。<br>- 2in1（PC设备）。<br>- tablet（平板）。 |

**返回值：**

| 类型            | 说明                     |
|-----------------|-------------------------|
| Promise\<void\> | 无返回结果。Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application to call the interface. |

**示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
  }

  onForeground(): void {
    try {
      let isEnable: boolean = true;
      let deviceType: string = "wearable";
      notificationManager.setDistributedEnabled(isEnable, deviceType).then(() => {
        console.info('setDistributedEnabled succeeded.');
      }).catch((err: BusinessError) => {
        console.error(`setDistributedEnabled failed. Code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      console.error(`setDistributedEnabled failed. Code is ${err.code}, message is ${err.message}`);
    }
  }
}
```

## notificationManager.getDistributedDeviceList<sup>20+</sup>

getDistributedDeviceList(): Promise\<Array\<string\>\>

查询支持跨设备协同通知的设备类型。使用Promise异步回调。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**系统接口**：此接口为系统接口。

**返回值：**

| 类型            | 说明                     |
|-----------------|-------------------------|
| Promise\<Array\<string\>\> | 返回支持跨设备协同通知的设备列表。Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application to call the interface. |

**示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
  }

  onForeground(): void {
    try {
      notificationManager.getDistributedDeviceList().then((data: Array<string>) => {
        console.info('getDistributedDeviceList succeeded, result = ' + data);
      }).catch((err: BusinessError) => {
        console.error(`getDistributedDeviceList failed. Code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      console.error(`getDistributedDeviceList failed. Code is ${err.code}, message is ${err.message}`);
    }
  }
}
```

## DoNotDisturbDate

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称  | 类型                                  | 必填 | 说明                   |
| ----- | ------------------------------------- | ---- | ---------------------- |
| type  | [DoNotDisturbType](#donotdisturbtype) | 是   | 免打扰设置的时间类型。 |
| begin | Date                                  | 是   | 免打扰设置的起点时间。 |
| end   | Date                                  | 是   | 免打扰设置的终点时间。 |

## DoNotDisturbType

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称         | 值               | 说明                                       |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | 0 | 非通知勿扰类型。                           |
| TYPE_ONCE    | 1 | 以设置时间段(只看小时和分钟)一次执行勿扰。 |
| TYPE_DAILY   | 2 | 以设置时间段(只看小时和分钟)每天执行勿扰。 |
| TYPE_CLEARLY | 3 | 以设置时间段(明确月日时)执行勿扰。     |


## DeviceRemindType

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | 设备未被使用，无需提醒。            |
| IDLE_REMIND          | 1   | 提醒设备未被使用。                 |
| ACTIVE_DONOT_REMIND  | 2   | 设备正在使用，无需提醒。            |
| ACTIVE_REMIND        | 3   | 提醒设备正在使用。                 |


## SourceType

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | 一般通知。            |
| TYPE_CONTINUOUS      | 1   | 连续通知。            |
| TYPE_TIMER           | 2   | 计划通知。            |

## NotificationCheckInfo<sup>10+</sup>

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

| 名称                         | 类型                          | 只读 | 可选 | 说明            |
| ---------------------------- | ---------------------------- | ---- | ---- |--------------- |
| bundleName                   | string                       |  否  | 否   | Bundle名称。    |
| notificationId               | number                       |  否  | 否   | 通知ID。        |
| label<sup>11+</sup>          | string                       |  否  | 是   | 通知标签。      |
| contentType                  | [ContentType](./js-apis-notificationManager.md#contenttype)  |  否  | 否   | 通知类型。      |
| creatorUserId<sup>11+</sup>  | number                       |  否  | 否   | 通知的user ID。 |
| slotType<sup>11+</sup>       | [SlotType](./js-apis-notificationManager.md#slottype)        |  否  | 否   | 渠道类型。      |
| extraInfos<sup>11+</sup>     | Record<string, Object>       |  否  | 是   | 实况通知的附加信息。 |

## NotificationCheckResult<sup>10+</sup>

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

| 名称    | 类型     | 只读 | 可选 | 说明                     |
| ------- | ------- | ---- | ---- | ----------------------- |
| code    | number  |  否  | 否   | 0-display，1-no display。|
| message | string  |  否  | 否   | 结果信息。                |


## ButtonOptions<sup>11+</sup>

描述触发按钮信息。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统接口**：此接口为系统接口。

| 名称       |   类型  | 只读 | 可选 | 说明                    |
| ---------- | ------ | ---- | ---- | ---------------------- |
| buttonName | string |  否  | 否   | 按钮名称。              |


## SystemLiveViewSubscriber<sup>11+</sup>

系统实况窗订阅者。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。


| 名称    | 类型                                  | 必填 | 说明                   |
| ------- | ------------------------------------ | ---- | ---------------------- |
| onResponse    | (notificationId: number, buttonOptions: [ButtonOptions](#buttonoptions11)) => void                         | 否   | 点击按钮的回调。 |


## SlotType

**系统能力**：SystemCapability.Notification.Notification

| 名称                                | 值     | 说明                                                         |
| ----------------------------------- | ------ | ------------------------------------------------------------ |
| EMERGENCY_INFORMATION<sup>12+</sup> | 10     | 紧急事件。**系统接口**：此接口为系统接口。                               |


## NotificationControlFlagStatus<sup>12+</sup>
每个bit位都可以控制通知的提示方式。当notificationControlFlags和下表中枚举值进行按位或操作，则表示关闭其提示方式。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                                 | 值   | 说明     |
| ------------------------------------ | ---- | -------- |
| NOTIFICATION_STATUS_CLOSE_SOUND      | 1<<0 | 关闭声音提示功能。 |
| NOTIFICATION_STATUS_CLOSE_LOCKSCREEN |  1<<1    |     关闭锁屏提示功能。     |
| NOTIFICATION_STATUS_CLOSE_BANNER     |    1<<2   |     关闭横幅提示功能。     |
| NOTIFICATION_STATUS_CLOSE_LIGHT_SCREEN     |   1<<3   |     关闭亮屏提示功能。     |
| NOTIFICATION_STATUS_CLOSE_VIBRATION     |   1<<4   |     关闭振动提示功能。     |
| NOTIFICATION_STATUS_CLOSE_STATUSBAR_ICON     |  1<<5    |     关闭状态栏图标提示功能。     |

## DoNotDisturbProfile<sup>12+</sup>

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称  | 类型                                  | 必填 | 说明                   |
| ----- | ------------------------------------- | ---- | ---------------------- |
| id | number | 是 | 勿扰模式编号。 |
| name | string  | 是 | 勿扰模式名称。 |
| trustlist | Array\<[BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)> | 否 | 勿扰模式的信任列表。 |

## NotificationLiveViewContent<sup>11+</sup>

type NotificationLiveViewContent = _NotificationLiveViewContent

描述普通实况通知。

**系统能力：** SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 类型 | 说明 |
| --- | --- |
| [_NotificationLiveViewContent](js-apis-inner-notification-notificationContent-sys.md#notificationliveviewcontent11) | 描述普通实况通知。 |

## SwitchState<sup>20+</sup>

描述通知相关开关的设置状态。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                 | 值  | 说明                               |
| --------------------| --- | --------------------------------- |
| USER_MODIFIED_OFF   | 0   | 表示用户设置的关闭状态。            |
| USER_MODIFIED_ON    | 1   | 表示用户设置的开启状态。                 |
| SYSTEM_DEFAULT_OFF  | 2   | 表示在用户设置前的初始关闭状态。            |
| SYSTEM_DEFAULT_ON   | 3   | 表示在用户设置前的初始开启状态。                 |
