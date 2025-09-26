# @ohos.reminderAgent (后台代理提醒)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @cheng-shichang-->
<!--Designer: @zhouben25-->
<!--Tester: @fenglili18-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供后台代理提醒的能力。

开发应用时，开发者可以调用相关接口创建定时提醒，包括倒计时、日历、闹钟这三类提醒类型。使用后台代理提醒能力后，应用被冻结或退出后，计时和弹出提醒的功能将被后台系统服务代理。

> **说明：**
>
> 从API Version 9 开始，该接口不再维护，推荐使用新接口[@ohos.reminderAgentManager （后台代理提醒）](js-apis-reminderAgentManager.md)
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import reminderAgent from'@ohos.reminderAgent';
```


## reminderAgent.publishReminder<sup>(deprecated)</sup>

publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void

发布一个后台代理提醒，使用回调的方式实现异步调用，该方法需要申请通知弹窗权限[Notification.requestEnableNotification](../apis-notification-kit/js-apis-notification.md#notificationrequestenablenotification8)后才能调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.publishReminder](js-apis-reminderAgentManager.md#reminderagentmanagerpublishreminder)替代。

**需要权限**：ohos.permission.PUBLISH_AGENT_REMINDER

**系统能力**：SystemCapability.Notification.ReminderAgent

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequestdeprecated) | 是 | 需要发布的提醒实例。 |
  | callback | AsyncCallback\<number> | 是 | 异步回调，返回当前发布的提醒的id。 |

**示例**：
```ts
import { BusinessError } from '@ohos.base';

let timer:reminderAgent.ReminderRequestTimer = {
  reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgent.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  console.log("callback, reminderId = " + reminderId);
});
```


## reminderAgent.publishReminder<sup>(deprecated)</sup>

publishReminder(reminderReq: ReminderRequest): Promise\<number>

发布一个后台代理提醒，使用Promise方式实现异步调用，该方法需要申请通知弹窗权限[Notification.requestEnableNotification](../apis-notification-kit/js-apis-notification.md#notificationrequestenablenotification8)后才能调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.publishReminder](js-apis-reminderAgentManager.md#reminderagentmanagerpublishreminder-1)替代。

**需要权限**：ohos.permission.PUBLISH_AGENT_REMINDER

**系统能力**：SystemCapability.Notification.ReminderAgent

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequestdeprecated) | 是 | 需要发布的提醒实例。 |

**返回值**：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise\<number> | 返回提醒的Id。 |

**示例**：
```ts
let timer:reminderAgent.ReminderRequestTimer = {
  reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgent.publishReminder(timer).then((reminderId: number) => {
  console.log("promise, reminderId = " + reminderId);
});
```


## reminderAgent.cancelReminder<sup>(deprecated)</sup>

cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void

取消指定id的提醒，使用回调的方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.cancelReminder](js-apis-reminderAgentManager.md#reminderagentmanagercancelreminder)替代。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderId | number | 是 | 目标reminder的id号。 |
| callback | AsyncCallback\<void> | 是 | 异步回调。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

reminderAgent.cancelReminder(1, (err: BusinessError, data: void) => {
  console.log("cancelReminder callback");
});
```


## reminderAgent.cancelReminder<sup>(deprecated)</sup>

cancelReminder(reminderId: number): Promise\<void>

取消指定id的提醒，使用Promise方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.cancelReminder](js-apis-reminderAgentManager.md#reminderagentmanagercancelreminder-1)替代。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderId | number | 是 | 目标reminder的id号。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise类型异步回调。 |

**示例**：

```ts
reminderAgent.cancelReminder(1).then(() => {
    console.log("cancelReminder promise");
});
```

## reminderAgent.getValidReminders<sup>(deprecated)</sup>

getValidReminders(callback: AsyncCallback\<Array\<ReminderRequest>>): void

获取当前应用已设置的所有有效（未过期）的提醒，使用回调的方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.getValidReminders](js-apis-reminderAgentManager.md#reminderagentmanagergetvalidreminders)替代。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ReminderRequest](#reminderrequestdeprecated)>> | 是 | 异步回调，返回当前应用已设置的所有有效（未过期）的提醒。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

reminderAgent.getValidReminders((err: BusinessError, reminders: Array<reminderAgent.ReminderRequest>) => {
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
})
```


## reminderAgent.getValidReminders<sup>(deprecated)</sup>

getValidReminders(): Promise\<Array\<ReminderRequest>>

获取当前应用已设置的所有有效（未过期）的提醒，使用Promise方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.getValidReminders](js-apis-reminderAgentManager.md#reminderagentmanagergetvalidreminders-1)替代。

**系统能力**： SystemCapability.Notification.ReminderAgent

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ReminderRequest](#reminderrequestdeprecated)>> | 返回当前应用已设置的所有有效（未过期）的提醒。 |

**示例**：

```ts
reminderAgent.getValidReminders().then((reminders: Array<reminderAgent.ReminderRequest>) => {
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
})

```


## reminderAgent.cancelAllReminders<sup>(deprecated)</sup>

cancelAllReminders(callback: AsyncCallback\<void>): void

取消当前应用所有的提醒，使用回调的方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.cancelAllReminders](js-apis-reminderAgentManager.md#reminderagentmanagercancelallreminders)替代。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<void> | 是 | 异步回调。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';

reminderAgent.cancelAllReminders((err: BusinessError, data: void) =>{
  console.log("cancelAllReminders callback")
})
```


## reminderAgent.cancelAllReminders<sup>(deprecated)</sup>

cancelAllReminders(): Promise\<void>

取消当前应用所有的提醒，使用Promise方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.cancelAllReminders](js-apis-reminderAgentManager.md#reminderagentmanagercancelallreminders-1)替代。

**系统能力**： SystemCapability.Notification.ReminderAgent

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise类型异步回调。 |

**示例**：

```ts
reminderAgent.cancelAllReminders().then(() => {
    console.log("cancelAllReminders promise")
})
```

## reminderAgent.addNotificationSlot<sup>(deprecated)</sup>

addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void

添加一个NotificationSlot，使用回调的方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.addNotificationSlot](js-apis-reminderAgentManager.md#reminderagentmanageraddnotificationslot)替代。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](../apis-notification-kit/js-apis-notification.md#notificationslot) | 是 | notification\.slot实例，仅支持设置其type属性。 |
| callback | AsyncCallback\<void> | 是 | 异步回调。 |

**示例**：

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

let mySlot:notification.NotificationSlot = {
  type: notification.SlotType.SOCIAL_COMMUNICATION
}
reminderAgent.addNotificationSlot(mySlot, (err: BusinessError, data: void) => {
  console.log("addNotificationSlot callback");
});
```


## reminderAgent.addNotificationSlot<sup>(deprecated)</sup>

addNotificationSlot(slot: NotificationSlot): Promise\<void>

添加一个NotificationSlot，使用Promise方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.addNotificationSlot](js-apis-reminderAgentManager.md#reminderagentmanageraddnotificationslot-1)替代。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](../apis-notification-kit/js-apis-notification.md#notificationslot) | 是 | notification\.slot实例，仅支持设置其type属性。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise类型异步回调。 |

**示例**：

```ts
import notification from '@ohos.notificationManager'

let mySlot:notification.NotificationSlot = {
  type: notification.SlotType.SOCIAL_COMMUNICATION
}
reminderAgent.addNotificationSlot(mySlot).then(() => {
  console.log("addNotificationSlot promise");
});
```


## reminderAgent.removeNotificationSlot<sup>(deprecated)</sup>

removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void

删除目标NotificationSlot，使用callback方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.removeNotificationSlot](js-apis-reminderAgentManager.md#reminderagentmanagerremovenotificationslot)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | 是 | 目标notification\.slot的类型。 |
| callback | AsyncCallback\<void> | 是 | 异步回调。 |

**示例**：

```ts
import notification from '@ohos.notification'
import { BusinessError } from '@ohos.base';

reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION, (err: BusinessError, data: void) => {
  console.log("removeNotificationSlot callback");
});
```


## reminderAgent.removeNotificationSlot<sup>(deprecated)</sup>

removeNotificationSlot(slotType: notification.SlotType): Promise\<void>

删除目标NotificationSlot，使用Promise方式实现异步调用。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.removeNotificationSlot](js-apis-reminderAgentManager.md#reminderagentmanagerremovenotificationslot-1)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | 是 | 目标notification\.slot的类型。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise类型异步回调。 |

**示例**：

```ts
import notification from '@ohos.notification'

reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {
    console.log("removeNotificationSlot promise");
});
```


## ActionButtonType<sup>(deprecated)</sup>

按钮的类型。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.ActionButtonType](js-apis-reminderAgentManager.md#actionbuttontype)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | 表示关闭提醒的按钮。 |
| ACTION_BUTTON_TYPE_SNOOZE | 1 | 表示延迟提醒的按钮。 |


## ReminderType<sup>(deprecated)</sup>

提醒的类型。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.ReminderType](js-apis-reminderAgentManager.md#remindertype)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| REMINDER_TYPE_TIMER | 0 | 表示提醒类型：倒计时。 |
| REMINDER_TYPE_CALENDAR | 1 | 表示提醒类型：日历。 |
| REMINDER_TYPE_ALARM | 2 | 表示提醒类型：闹钟。 |


## ActionButton<sup>(deprecated)</sup>

用于设置弹出的提醒通知信息上显示的按钮类型和标题。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.ActionButton](js-apis-reminderAgentManager.md#actionbutton)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| title | string | 是 | 按钮显示的标题。 |
| type | [ActionButtonType](#actionbuttontypedeprecated) | 是 | 按钮的类型。 |


## WantAgent<sup>(deprecated)</sup>

点击提醒通知后跳转的目标ability信息。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.WantAgent](js-apis-reminderAgentManager.md#wantagent)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 指明点击提醒通知栏后跳转的目标HAP名。 |
| abilityName | string | 是 | 指明点击提醒通知栏后跳转的目标ability名称。 |


## MaxScreenWantAgent<sup>(deprecated)</sup>

全屏显示提醒到达时自动拉起的目标ability信息，该接口预留。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.MaxScreenWantAgent](js-apis-reminderAgentManager.md#maxscreenwantagent)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 指明提醒到达时自动拉起的目标HAP名（如果设备在使用中，则只弹出通知横幅框）。 |
| abilityName | string | 是 | 指明提醒到达时自动拉起的目标ability名（如果设备在使用中，则只弹出通知横幅框）。 |


## ReminderRequest<sup>(deprecated)</sup>

提醒实例对象，用于设置提醒类型、响铃时长等具体信息。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.ReminderRequest](js-apis-reminderAgentManager.md#reminderrequest)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderType | [ReminderType](#remindertypedeprecated) | 是 | 指明提醒类型。 |
| actionButton | [[ActionButton?, ActionButton?]](#actionbuttondeprecated) | 否 | 弹出的提醒通知栏中显示的按钮（参数可选，支持0/1/2个按钮）。 |
| wantAgent | WantAgent | 否 | 点击通知后需要跳转的目标ability信息。 |
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagentdeprecated) | 否 | 提醒到达时跳转的目标包。如果设备正在使用中，则弹出一个通知框。 |
| ringDuration | number | 否 | 指明响铃时长（单位：秒），默认1秒。 |
| snoozeTimes | number | 否 | 指明延迟提醒次数，默认0次。 |
| timeInterval | number | 否 | 执行延迟提醒间隔（单位：秒），默认0秒。 |
| title | string | 否 | 指明提醒标题。 |
| content | string | 否 | 指明提醒内容。 |
| expiredContent | string | 否 | 指明提醒过期后需要显示的内容。 |
| snoozeContent | string | 否 | 指明延迟提醒时需要显示的内容。 |
| notificationId | number | 否 | 指明提醒使用的通知的id号，相同id号的提醒会覆盖。 |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | 否 | 指明提醒的slot类型。 |


## ReminderRequestCalendar<sup>(deprecated)</sup>


日历实例对象，用于设置提醒的时间。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.ReminderRequestCalendar](js-apis-reminderAgentManager.md#reminderrequestcalendar)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| dateTime | [LocalDateTime](#localdatetimedeprecated) | 是 | 指明提醒的目标时间。 |
| repeatMonths | Array\<number> | 否 | 指明重复提醒的月份。 |
| repeatDays | Array\<number> | 否 | 指明重复提醒的日期。 |


## ReminderRequestAlarm<sup>(deprecated)</sup>


闹钟实例对象，用于设置提醒的时间。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.ReminderRequestAlarm](js-apis-reminderAgentManager.md#reminderrequestalarm)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| hour | number | 是 | 指明提醒的目标时刻。 |
| minute | number | 是 | 指明提醒的目标分钟。 |
| daysOfWeek | Array\<number> | 否 | 指明每周哪几天需要重复提醒。范围为周一到周末，对应数字为1到7。 |


## ReminderRequestTimer<sup>(deprecated)</sup>

倒计时实例对象，用于设置提醒的时间。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.ReminderRequestTimer](js-apis-reminderAgentManager.md#reminderrequesttimer)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| triggerTimeInSeconds | number | 是 | 指明倒计时的秒数。 |


## LocalDateTime<sup>(deprecated)</sup>

用于日历类提醒设置时指定时间信息。

> **说明：**
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[reminderAgentManager.LocalDateTime](js-apis-reminderAgentManager.md#localdatetime)替代。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| year | number | 是 | 年 |
| month | number | 是 | 月 |
| day | number | 是 | 日 |
| hour | number | 是 | 时 |
| minute | number | 是 | 分 |
| second | number | 否 | 秒 |
