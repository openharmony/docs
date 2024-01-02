# @ohos.reminderAgentManager (后台代理提醒)

本模块提供后台代理提醒的能力，即当应用被冻结或应用退出时，计时和提醒的功能将被系统服务代理。在开发过程中，开发者可以调用本模块接口创建定时提醒，提醒类型支持倒计时、日历、闹钟三种。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';
```

## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void

发布后台代理提醒。使用callback异步回调。

> **说明：**
>
> 该接口需要申请通知弹窗权限[Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8)后调用。

**需要权限**： ohos.permission.PUBLISH_AGENT_REMINDER

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | 是 | 需要发布的代理提醒实例。 |
  | callback | AsyncCallback\<number> | 是 | 回调函数，返回当前发布提醒的id。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](../errorcodes/errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**示例**：
```ts
import { BusinessError } from '@ohos.base';

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
> 该接口需要申请通知弹窗权限[Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8)后调用。

**需要权限**： ohos.permission.PUBLISH_AGENT_REMINDER

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | 是 | 需要发布的代理提醒实例。 |

**返回值**：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise\<number> | Promise对象，返回提醒的id。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](../errorcodes/errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**示例**：
```ts
import { BusinessError } from '@ohos.base';

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

取消指定Id的代理提醒。使用callback异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderId | number | 是 | 需要取消的代理提醒的Id。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，取消代理提醒成功，err为undefined，否则返回err信息。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](../errorcodes/errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

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

取消指定Id的代理提醒。使用Promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderId | number | 是 | 需要取消的代理提醒的Id。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](../errorcodes/errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

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
> 当到达设置的提醒时间点时，通知中心会弹出相应提醒的通知卡片（通知栏消息）。若未点击通知卡片上的关闭/CLOSE按钮，则代理提醒是有效/未过期的；若点击了关闭/CLOSE按钮，则代理提醒过期。
>
> 当代理提醒类型是闹钟时，若设置每天提醒，无论是否点击关闭/CLOSE按钮，代理提醒都是有效的。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ReminderRequest](#reminderrequest)>> | 是 | 回调函数，返回当前应用设置的所有有效的代理提醒。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](../errorcodes/errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

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
> 当到达设置的提醒时间点时，通知中心会弹出相应提醒的通知卡片（通知栏消息）。若未点击通知卡片上的关闭/CLOSE按钮，则代理提醒是有效/未过期的；若点击了关闭/CLOSE按钮，则代理提醒过期。
>
> 当代理提醒类型是闹钟时，若设置每天提醒，无论是否点击关闭/CLOSE按钮，代理提醒都是有效的。

**系统能力**： SystemCapability.Notification.ReminderAgent

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ReminderRequest](#reminderrequest)>> | Promise对象，返回当前应用设置的所有有效的代理提醒。 |

**错误码：**

以下错误码的详细介绍请参见[reminderAgentManager错误码](../errorcodes/errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

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

以下错误码的详细介绍请参见[reminderAgentManager错误码](../errorcodes/errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

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

以下错误码的详细介绍请参见[reminderAgentManager错误码](../errorcodes/errorcode-reminderAgentManager.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

reminderAgentManager.cancelAllReminders().then(() => {
  console.log("cancelAllReminders promise")
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```


## reminderAgentManager.addNotificationSlot

addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void

添加NotificationSlot（通知槽）。使用callback异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](js-apis-notification.md#notificationslot) | 是 | notification\.slot实例，仅支持设置其type属性。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，添加NotificationSlot成功时，err为undefined，否则err为错误对象。 |

**示例**：

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

let mySlot: notification.NotificationSlot = {
  type: notification.SlotType.SOCIAL_COMMUNICATION
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

添加NotificationSlot（通知槽）。使用promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](js-apis-notification.md#notificationslot) | 是 | notification\.slot实例，仅支持设置其type属性。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例**：

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

let mySlot: notification.NotificationSlot = {
  type: notification.SlotType.SOCIAL_COMMUNICATION
}
reminderAgentManager.addNotificationSlot(mySlot).then(() => {
  console.log("addNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```


## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void

删除目标NotificationSlot（通知槽），使用callback异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | 是 | 目标notification\.slot的类型。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当删除成功时，err为undefined，否则为错误对象。 |

**示例**：

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

reminderAgentManager.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION,
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

删除目标NotificationSlot（通知槽）。使用Promise异步回调。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | 是 | 目标notification\.slot的类型。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例**：

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

reminderAgentManager.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {
  console.log("removeNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## ActionButtonType

按钮的类型。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | 表示关闭提醒的按钮。 |
| ACTION_BUTTON_TYPE_SNOOZE | 1 | 表示延迟提醒的按钮。 |
| ACTION_BUTTON_TYPE_CUSTOM<sup>10+</sup>  | 2 | 表示自定义的按钮。<br>**系统接口**: 系统接口，三方应用不支持调用。 |


## ReminderType

提醒的类型。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| REMINDER_TYPE_TIMER | 0 | 表示提醒类型：倒计时。 |
| REMINDER_TYPE_CALENDAR | 1 | 表示提醒类型：日历。 |
| REMINDER_TYPE_ALARM | 2 | 表示提醒类型：闹钟。 |


## ActionButton

弹出的提醒通知中按钮的类型和标题。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| title | string | 是 | 按钮显示的标题。 |
| titleResource<sup>11+</sup> | string | 否 | 标题的资源ID，用于切换系统语言后读取对应标题信息。 |
| type | [ActionButtonType](#actionbuttontype) | 是 | 按钮的类型。 |
| wantAgent<sup>10+</sup> | [WantAgent](#wantagent) | 否 | 点击按钮跳转的ability信息。<br>**系统接口**: 系统接口，三方应用不支持调用。 |
| dataShareUpdate<sup>11+</sup> | [DataShareUpdate](#datashareupdate11) | 否 | 点击按钮将更新应用数据库。<br>**系统接口**: 系统接口，三方应用不支持调用。 |


## WantAgent

跳转目标的ability信息。

**系统能力**：SystemCapability.Notification.ReminderAgent


| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 指明跳转目标的包名。 |
| abilityName | string | 是 | 指明跳转目标的ability名称。 |
| uri<sup>10+</sup> | string | 否 | 指明跳转目标的uri信息。<br>**系统接口**: 系统接口，三方应用不支持调用。 |

## DataShareUpdate<sup>11+</sup>

更新数据库需要的参数信息。<br/>
数据提供方需要在module.json5中的proxyDatas节点定义要共享的表的标识，读写权限和基本信息。配置方式请见[数据代理](../../database/share-data-by-silent-access.md)。

**系统能力**：SystemCapability.Notification.ReminderAgent


| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 数据使用的URI，是跨应用数据访问的唯一标识。<br>**系统接口**: 系统接口，三方应用不支持调用。 |
| equalTo | [key: string]: number \| string \| boolean | 是 | 指示筛选条件，当前仅支持通过等于筛选。<br>**系统接口**: 系统接口，三方应用不支持调用。 |
| value | [ValueBucket](js-apis-data-valuesBucket.md#valuesbucket) | 是 | 指示要更新的数据。<br>**系统接口**: 系统接口，三方应用不支持调用。 |


## MaxScreenWantAgent

提醒到达时，全屏显示自动拉起目标的ability信息。该接口为预留接口，暂不支持使用。

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
| actionButton | [[ActionButton?, ActionButton?, ActionButton?]](#actionbutton) | 否 | 弹出的提醒通知栏中显示的按钮。<br>-普通应用：最多支持两个按钮。<br>-系统应用：API9最多支持两个按钮，在API10开始最多支持三个按钮。 |
| wantAgent | [WantAgent](#wantagent) | 否 | 点击通知后需要跳转的目标ability信息。 |
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagent) | 否 | 提醒到达时，全屏显示自动拉起目标的ability信息。如果设备正在使用中，则弹出一个通知框。 <br> 说明：该接口为预留接口，暂不支持使用。|
| ringDuration | number | 否 | 指明响铃时长（单位：秒），默认1秒。 |
| snoozeTimes | number | 否 | 指明延迟提醒次数，默认0次(不适用于倒计时提醒类型)。 |
| timeInterval | number | 否 | 执行延迟提醒间隔（单位：秒），最少5分钟(不适用于倒计时提醒类型)。 |
| title | string | 否 | 指明提醒标题。 |
| content | string | 否 | 指明提醒内容。 |
| expiredContent | string | 否 | 指明提醒过期后需要显示的内容。 |
| snoozeContent | string | 否 | 指明延迟提醒时需要显示的内容(不适用于倒计时提醒类型)。 |
| notificationId | number | 否 | 指明提醒使用的通知的id号，相同id号的提醒会覆盖。 |
| groupId<sup>11+</sup> | string | 否 | 指明提醒使用相同的组id。相同组id中，一个提醒被点击不在提醒后，组内其他提醒也会被取消。 |
| slotType | [notification.SlotType](js-apis-notificationManager.md#slottype) | 否 | 指明提醒的slot类型。 |
| tapDismissed<sup>10+</sup> | boolean | 否 | 通知是否自动清除，具体请参考[NotificationRequest.tapDismissed](js-apis-inner-notification-notificationRequest.md#notificationrequest)。  |
| autoDeletedTime<sup>10+</sup> | number | 否 | 自动清除的时间，具体请参考[NotificationRequest.autoDeletedTime](js-apis-inner-notification-notificationRequest.md#notificationrequest)。 |


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
