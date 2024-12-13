# @ohos.reminderAgentManager (后台代理提醒)

本模块提供后台代理提醒的能力，即当应用被冻结或应用退出时，计时和提醒的功能将被系统服务代理。开发者可以调用本模块接口创建定时提醒，提醒类型支持倒计时、日历、闹钟三种。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { reminderAgentManager } from '@kit.BackgroundTasksKit';
```

## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void

发布后台代理提醒。使用callback异步回调。

> **说明：**
>
> 该接口需要申请通知弹窗权限[NotificationManager.requestEnableNotification](../apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10)后调用。
>
> <!--RP1--><!--RP1End-->

**需要权限**： ohos.permission.PUBLISH_AGENT_REMINDER

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | 是 | 需要发布的代理提醒实例。 |
  | callback | AsyncCallback\<number> | 是 | 回调函数，返回当前发布提醒的id。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**示例**：
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("callback, reminderId = " + reminderId);
  }
});
```

## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest): Promise\<number>

发布后台代理提醒。使用promise异步回调。

> **说明：**
>
> 该接口需要申请通知弹窗权限[NotificationManager.requestEnableNotification](../apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10)后调用。
>
> <!--RP1--><!--RP1End-->

**需要权限**： ohos.permission.PUBLISH_AGENT_REMINDER

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | 是 | 需要发布的代理提醒实例。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | Promise对象，返回当前发布提醒的id。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**示例**：
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer).then((reminderId: number) => {
  console.log("promise, reminderId = " + reminderId);
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```


## reminderAgentManager.cancelReminder

cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void

取消指定id的代理提醒。使用callback异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderId | number | 是 | 需要取消的代理提醒的id。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，取消代理提醒成功，err为undefined，否则返回err信息。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.cancelReminder(reminderId, (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("cancelReminder callback");
  }
});
```

## reminderAgentManager.cancelReminder

cancelReminder(reminderId: number): Promise\<void>

取消指定id的代理提醒。使用Promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderId | number | 是 | 需要取消的代理提醒的id。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.cancelReminder(reminderId).then(() => {
  console.log("cancelReminder promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.getValidReminders

getValidReminders(callback: AsyncCallback<Array\<ReminderRequest>>): void

获取当前应用设置的所有有效（未过期）的代理提醒。使用callback异步回调。

> **说明：**
>
> 当到达设置的提醒时间点时，通知中心会弹出相应提醒。若未点击提醒上的关闭/CLOSE按钮，则代理提醒是有效/未过期的；若点击了关闭/CLOSE按钮，则代理提醒过期。
>
> 当代理提醒类型是闹钟时，若设置每天提醒，无论是否点击关闭/CLOSE按钮，代理提醒都是有效的。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ReminderRequest](#reminderrequest)>> | 是 | 回调函数，返回当前应用设置的所有有效（未过期）的代理提醒。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.getValidReminders((err: BusinessError, reminders: Array<reminderAgentManager.ReminderRequest>) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("callback, getValidReminders length = " + reminders.length);
    for (let i = 0; i < reminders.length; i++) {
      console.log("getValidReminders = " + reminders[i]);
      console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
      const actionButton = reminders[i].actionButton || [];
      for (let j = 0; j < actionButton.length; j++) {
        console.log("getValidReminders, actionButton.title = " + actionButton[j]?.title);
        console.log("getValidReminders, actionButton.type = " + actionButton[j]?.type);
      }
      console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent?.pkgName);
      console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent?.abilityName);
      console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent?.pkgName);
      console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent?.abilityName);
      console.log("getValidReminders, ringDuration = " + reminders[i].ringDuration);
      console.log("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);
      console.log("getValidReminders, timeInterval = " + reminders[i].timeInterval);
      console.log("getValidReminders, title = " + reminders[i].title);
      console.log("getValidReminders, content = " + reminders[i].content);
      console.log("getValidReminders, expiredContent = " + reminders[i].expiredContent);
      console.log("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);
      console.log("getValidReminders, notificationId = " + reminders[i].notificationId);
      console.log("getValidReminders, slotType = " + reminders[i].slotType);
    }
  }
});
```

## reminderAgentManager.getValidReminders

getValidReminders(): Promise\<Array\<ReminderRequest>>

获取当前应用设置的所有有效（未过期）的代理提醒。使用promise异步回调。

> **说明：**
>
> 当到达设置的提醒时间点时，通知中心会弹出相应提醒。若未点击提醒上的关闭/CLOSE按钮，则代理提醒是有效/未过期的；若点击了关闭/CLOSE按钮，则代理提醒过期。
>
> 当代理提醒类型是闹钟时，若设置每天提醒，无论是否点击关闭/CLOSE按钮，代理提醒都是有效的。

**系统能力**： SystemCapability.Notification.ReminderAgent

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ReminderRequest](#reminderrequest)>> | Promise对象，返回当前应用设置的所有有效（未过期）的代理提醒。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.getValidReminders().then((reminders: Array<reminderAgentManager.ReminderRequest>) => {
  console.log("promise, getValidReminders length = " + reminders.length);
  for (let i = 0; i < reminders.length; i++) {
    console.log("getValidReminders = " + reminders[i]);
    console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
    const actionButton = reminders[i].actionButton || [];
    for (let j = 0; j < actionButton.length; j++) {
      console.log("getValidReminders, actionButton.title = " + actionButton[j]?.title);
      console.log("getValidReminders, actionButton.type = " + actionButton[j]?.type);
    }
    console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent?.pkgName);
    console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent?.abilityName);
    console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent?.pkgName);
    console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent?.abilityName);
    console.log("getValidReminders, ringDuration = " + reminders[i].ringDuration);
    console.log("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);
    console.log("getValidReminders, timeInterval = " + reminders[i].timeInterval);
    console.log("getValidReminders, title = " + reminders[i].title);
    console.log("getValidReminders, content = " + reminders[i].content);
    console.log("getValidReminders, expiredContent = " + reminders[i].expiredContent);
    console.log("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);
    console.log("getValidReminders, notificationId = " + reminders[i].notificationId);
    console.log("getValidReminders, slotType = " + reminders[i].slotType);
  }
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
}); 
```

## reminderAgentManager.cancelAllReminders

cancelAllReminders(callback: AsyncCallback\<void>): void

取消当前应用设置的所有代理提醒。使用callback异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<void> | 是 | 回调函数，取消代理提醒成功，err为undefined，否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.cancelAllReminders((err: BusinessError) =>{
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("cancelAllReminders callback")
  }
});
```

## reminderAgentManager.cancelAllReminders

cancelAllReminders(): Promise\<void>

取消当前应用设置的所有代理提醒。使用Promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.cancelAllReminders().then(() => {
  console.log("cancelAllReminders promise")
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```


## reminderAgentManager.addNotificationSlot

addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void

添加通知槽。使用callback异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](../apis-notification-kit/js-apis-inner-notification-notificationSlot.md#notificationslot) | 是 | notificationManager\.slot实例，仅支持设置其notificationType属性。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，添加NotificationSlot成功时，err为undefined，否则err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 401      | If the input parameter is not valid parameter. |

**示例**：

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mySlot: notificationManager.NotificationSlot = {
  notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
}

reminderAgentManager.addNotificationSlot(mySlot, (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("addNotificationSlot callback");
  }
});
```


## reminderAgentManager.addNotificationSlot

addNotificationSlot(slot: NotificationSlot): Promise\<void>

添加通知槽。使用promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](../apis-notification-kit/js-apis-inner-notification-notificationSlot.md#notificationslot) | 是 | notificationManager\.slot实例，仅支持设置其notificationType属性。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 401      | If the input parameter is not valid parameter. |

**示例**：

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mySlot: notificationManager.NotificationSlot = {
  notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
}
reminderAgentManager.addNotificationSlot(mySlot).then(() => {
  console.log("addNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```


## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void

删除目标通知槽，使用callback异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | 是 | 目标notification\.slot的类型。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当删除成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 401      | If the input parameter is not valid parameter. |

**示例**：

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.removeNotificationSlot(notificationManager.SlotType.CONTENT_INFORMATION,
  (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("removeNotificationSlot callback");
  }
});
```


## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType): Promise\<void>

删除目标通知槽，使用Promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | 是 | 目标notification\.slot的类型。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 401      | If the input parameter is not valid parameter. |

**示例**：

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.removeNotificationSlot(notificationManager.SlotType.CONTENT_INFORMATION).then(() => {
  console.log("removeNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.getAllValidReminders<sup>12+</sup>

getAllValidReminders(): Promise\<Array\<ReminderInfo>>

获取当前应用设置的所有有效（未过期）的代理提醒。使用promise异步回调。

> **说明：**
>
> 当到达设置的提醒时间点时，通知中心会弹出相应提醒。若未点击提醒上的关闭/CLOSE按钮，则代理提醒是有效/未过期的；若点击了关闭/CLOSE按钮，则代理提醒过期。
>
> 当代理提醒类型是闹钟时，若设置每天提醒，无论是否点击关闭/CLOSE按钮，代理提醒都是有效的。

**系统能力**： SystemCapability.Notification.ReminderAgent

**返回值**：

| 类型                                              | 说明                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[ReminderInfo](#reminderinfo12)>> | Promise对象，返回当前应用设置的所有有效（未过期）的代理提醒。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.getAllValidReminders().then((reminders: Array<reminderAgentManager.ReminderInfo>) => {
  console.log("promise, getAllValidReminders length = " + reminders.length);
  for (let i = 0; i < reminders.length; i++) {
    console.log("getAllValidReminders, reminderId = " + reminders[i].reminderId);
    console.log("getAllValidReminders, reminderType = " + reminders[i].reminderReq.reminderType);
    const actionButton = reminders[i].reminderReq.actionButton || [];
    for (let j = 0; j < actionButton.length; j++) {
      console.log("getAllValidReminders, actionButton.title = " + actionButton[j]?.title);
      console.log("getAllValidReminders, actionButton.type = " + actionButton[j]?.type);
    }
    console.log("getAllValidReminders, wantAgent.pkgName = " + reminders[i].reminderReq.wantAgent?.pkgName);
    console.log("getAllValidReminders, wantAgent.abilityName = " + reminders[i].reminderReq.wantAgent?.abilityName);
    console.log("getAllValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].reminderReq.maxScreenWantAgent?.pkgName);
    console.log("getAllValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].reminderReq.maxScreenWantAgent?.abilityName);
    console.log("getAllValidReminders, ringDuration = " + reminders[i].reminderReq.ringDuration);
    console.log("getAllValidReminders, snoozeTimes = " + reminders[i].reminderReq.snoozeTimes);
    console.log("getAllValidReminders, timeInterval = " + reminders[i].reminderReq.timeInterval);
    console.log("getAllValidReminders, title = " + reminders[i].reminderReq.title);
    console.log("getAllValidReminders, content = " + reminders[i].reminderReq.content);
    console.log("getAllValidReminders, expiredContent = " + reminders[i].reminderReq.expiredContent);
    console.log("getAllValidReminders, snoozeContent = " + reminders[i].reminderReq.snoozeContent);
    console.log("getAllValidReminders, notificationId = " + reminders[i].reminderReq.notificationId);
    console.log("getAllValidReminders, slotType = " + reminders[i].reminderReq.slotType);
  }
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
}); 
```

## reminderAgentManager.addExcludeDate<sup>12+</sup>

addExcludeDate(reminderId: number, date: Date): Promise\<void>

为指定id的周期性的日历提醒，添加不提醒日期（如每天提醒的日历，设置周二不提醒）。使用Promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | ---------------------------------- |
| reminderId | number | 是   | 需要添加不提醒日期的周期性日历id。 |
| date       | Date   | 是   | 不提醒的日期。                     |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 201      | Permission denied.                             |
| 401      | If the input parameter is not valid parameter. |
| 1700003  | The reminder does not exist.                   |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
let date = new Date();
reminderAgentManager.addExcludeDate(reminderId, date).then(() => {
  console.log("addExcludeDate promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.deleteExcludeDates<sup>12+</sup>

deleteExcludeDates(reminderId: number): Promise\<void>

为指定id的周期性的日历提醒，删除设置的所有不提醒日期。使用Promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | ---------------------------------- |
| reminderId | number | 是   | 需要删除不提醒日期的周期性日历id。 |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                     |
| -------- | ---------------------------- |
| 201      | Permission denied.           |
| 1700003  | The reminder does not exist. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.deleteExcludeDates(reminderId).then(() => {
  console.log("deleteExcludeDates promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.getExcludeDates<sup>12+</sup>

getExcludeDates(reminderId: number): Promise\<Array\<Date>>

为指定id的周期性的日历提醒，查询设置的所有不提醒日期。使用Promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | ---------------------------------- |
| reminderId | number | 是   | 需要查询不提醒日期的周期性日历id。 |

**返回值**：

| 类型                   | 说明                              |
| ---------------------- | --------------------------------- |
| Promise\<Array\<Date>> | Promise对象。返回特定日历设置的所有不提醒日期。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](errorcode-reminderAgentManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                     |
| -------- | ---------------------------- |
| 201      | Permission denied.           |
| 1700003  | The reminder does not exist. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.getExcludeDates(reminderId).then((dates) => {
  console.log("getExcludeDates promise length: " + dates.length);
  for (let i = 0; i < dates.length; i++) {
	console.log("getExcludeDates promise date is: " + dates[i].toString());
  }
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## ActionButtonType

提醒上的按钮的类型。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | 表示关闭提醒的按钮。 |
| ACTION_BUTTON_TYPE_SNOOZE | 1 | 表示延时提醒的按钮，提醒次数和间隔通过 [ReminderRequest](#reminderrequest) 中snoozeTimes和timeInterval设置。 |

## ReminderType

提醒的类型。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| REMINDER_TYPE_TIMER | 0 | 表示提醒类型：倒计时。 |
| REMINDER_TYPE_CALENDAR | 1 | 表示提醒类型：日历。 |
| REMINDER_TYPE_ALARM | 2 | 表示提醒类型：闹钟。 |


## ActionButton

弹出的提醒中按钮的类型和标题。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| title | string | 是 | 按钮显示的标题。 |
| titleResource<sup>11+</sup> | string | 否 | 标题的资源ID，用于切换系统语言后读取对应标题信息。 |
| type | [ActionButtonType](#actionbuttontype) | 是 | 按钮的类型。 |


## WantAgent

跳转目标的ability信息。

**系统能力**：SystemCapability.Notification.ReminderAgent


| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 指明跳转目标的包名。 |
| abilityName | string | 是 | 指明跳转目标的ability名称。 |
| parameters<sup>12+</sup> | Record\<string, Object> | 否 | 需要传递到目标的参数。 |
| uri<sup>12+</sup> | string | 否 | 指明跳转目标的uri信息。 |


## MaxScreenWantAgent

通知中心弹出提醒时，全屏显示自动拉起目标的ability信息。该接口为预留接口，暂不支持使用。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 指明提醒到达时自动拉起的目标包名（如果设备在使用中，则只弹出通知横幅框）。 |
| abilityName | string | 是 | 指明提醒到达时自动拉起的目标ability名（如果设备在使用中，则只弹出通知横幅框）。 |


## ReminderRequest

代理提醒对象，用于设置提醒类型、响铃时长等具体信息。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderType | [ReminderType](#remindertype) | 是 | 指明代理提醒类型。 |
| actionButton | [[ActionButton?, ActionButton?, ActionButton?]](#actionbutton) | 否 | 弹出的提醒通知中显示的按钮。<br>-普通应用：最多支持两个按钮。<br>-系统应用：API9最多支持两个按钮，在API10开始最多支持三个按钮。 |
| wantAgent | [WantAgent](#wantagent) | 否 | 点击通知后需要跳转的目标ability信息。 |
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagent) | 否 | 提醒到达时，全屏显示自动拉起目标的ability信息。如果设备正在使用中，则弹出一个通知横幅框。 <br> 说明：该接口为预留接口，暂不支持使用。|
| ringDuration | number | 否 | 指明响铃时长（单位：秒），默认1秒。 |
| snoozeTimes | number | 否 | 指明延时提醒次数，默认0次(不适用于倒计时提醒类型)。 |
| timeInterval | number | 否 | 执行延时提醒间隔（单位：秒），最少5分钟(不适用于倒计时提醒类型)。 |
| title | string | 否 | 指明提醒标题。 |
| content | string | 否 | 指明提醒内容。 |
| expiredContent | string | 否 | 指明提醒过期后需要显示的内容。 |
| snoozeContent | string | 否 | 指明延时提醒时需要显示的内容(不适用于倒计时提醒类型)。 |
| notificationId | number | 否 | 指明提醒使用的通知的id号，需开发者传入，相同id号的提醒会覆盖。 |
| groupId<sup>11+</sup> | string | 否 | 指明提醒使用相同的组id。相同组id中，一个提醒被点击不在提醒后，组内其他提醒也会被取消。 |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notificationManager.md#slottype) | 否 | 指明提醒的通道渠道类型。 |
| tapDismissed<sup>10+</sup> | boolean | 否 | 通知是否自动清除，具体请参考[NotificationRequest.tapDismissed](../apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest)。  |
| autoDeletedTime<sup>10+</sup> | number | 否 | 自动清除的时间，具体请参考[NotificationRequest.autoDeletedTime](../apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest)。 |
| snoozeSlotType<sup>11+</sup> | [notification.SlotType](../apis-notification-kit/js-apis-notificationManager.md#slottype) | 否 | 指明延时提醒的通道渠道类型(不适用于倒计时提醒类型)。 |
| customRingUri<sup>11+</sup> | string | 否 | 指明自定义提示音的uri，提示音文件必须放在resources/rawfile目录下，支持m4a、aac、mp3、ogg、wav、flac、amr等格式。 |

## ReminderRequestCalendar

ReminderRequestCalendar extends ReminderRequest

日历实例对象，用于设置提醒的时间。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| dateTime | [LocalDateTime](#localdatetime) | 是 | 指明提醒的目标时间。 |
| repeatMonths | Array\<number> | 否 | 指明重复提醒的月份。 |
| repeatDays | Array\<number> | 否 | 指明重复提醒的日期。 |
| daysOfWeek<sup>11+</sup> | Array\<number> | 否 | 指明每周哪几天需要重复提醒。范围为周一到周日，对应数字为1到7。 |
| endDateTime<sup>12+</sup> | [LocalDateTime](#localdatetime) | 否 | 指明提醒的结束时间。 |


## ReminderRequestAlarm

ReminderRequestAlarm extends ReminderRequest

闹钟实例对象，用于设置提醒的时间。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| hour | number | 是 | 指明提醒的目标时刻。 |
| minute | number | 是 | 指明提醒的目标分钟。 |
| daysOfWeek | Array\<number> | 否 | 指明每周哪几天需要重复提醒。范围为周一到周日，对应数字为1到7。 |


## ReminderRequestTimer

ReminderRequestTimer extends ReminderRequest

倒计时实例对象，用于设置提醒的时间。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| triggerTimeInSeconds | number | 是 | 指明倒计时的秒数。 |


## LocalDateTime

用于日历类提醒设置时指定时间信息。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| year | number | 是 | 年 |
| month | number | 是 | 月，取值范围是[1, 12]。 |
| day | number | 是 | 日，取值范围是[1, 31]。 |
| hour | number | 是 | 时，取值范围是[0, 23]。 |
| minute | number | 是 | 分，取值范围是[0, 59]。 |
| second | number | 否 | 秒，取值范围是[0, 59]。 |

## ReminderInfo<sup>12+</sup>

代理提醒信息，包含 ReminderRequest 和 ReminderId。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称        | 类型                                | 只读 | 可选 | 说明                 |
| ----------- | ----------------------------------- | ---- | ---- | -------------------- |
| reminderId  | number                              | 否   | 否   | 发布提醒后返回的id。 |
| reminderReq | [ReminderRequest](#reminderrequest) | 否   | 否   | 代理提醒对象。       |

