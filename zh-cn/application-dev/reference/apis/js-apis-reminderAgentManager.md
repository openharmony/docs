# 后台代理提醒

本模块提供后台代理提醒的能力。

开发应用时，开发者可以调用后台提醒发布的接口创建定时提醒，包括倒计时、日历、闹钟三种提醒类型。使用后台代理提醒能力后，应用可以被冻结或退出，计时和弹出提醒的功能将被后台系统服务代理。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import reminderAgentManager from'@ohos.reminderAgentManager';
```


## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback&lt;number&gt;): void

发布一个后台代理提醒，使用callback方式实现异步调用，该方法需要申请通知弹窗[Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8)后才能调用。

**需要权限**： ohos.permission.PUBLISH_AGENT_REMINDER

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | 是 | 需要发布的提醒实例。 |
  | callback | AsyncCallback&lt;number&gt; | 是 | 异步回调，返回当前发布的提醒的reminderId。 |

**错误码：**

以下错误码的详细介绍请参见[@ohos.reminderAgentManager（后台代理提醒）](../errorcodes/errorcode-reminderAgentManager.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**示例**：
```js
let timer = {
    reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
    triggerTimeInSeconds: 10
}
try {
    reminderAgentManager.publishReminder(timer, (err, reminderId) => {
        if (err) {
            console.log("callback err code:" + err.code + " message:" + err.message);
        } else {
            console.log("callback, reminderId = " + reminderId);
        }
    });
} catch (error) {
    console.log("publishReminder code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest): Promise&lt;number&gt;

发布一个后台代理提醒，使用Promise方式实现异步调用，该方法需要申请通知弹窗[Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8)后才能调用。

**需要权限**： ohos.permission.PUBLISH_AGENT_REMINDER

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | 是 | 需要发布的提醒实例。 |

**返回值**：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | 返回提醒的reminderId。 |

**错误码：**

以下错误码的详细介绍请参见[@ohos.reminderAgentManager（后台代理提醒）](../errorcodes/errorcode-reminderAgentManager.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**示例**：
```js
let timer = {
    reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
    triggerTimeInSeconds: 10
}
try {
    reminderAgentManager.publishReminder(timer).then((reminderId) => {
        console.log("promise, reminderId = " + reminderId);
    }).catch(err => {
        console.log("promise err code:" + err.code + " message:" + err.message);
    });
} catch (error) {
    console.log("publishReminder code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.cancelReminder

cancelReminder(reminderId: number, callback: AsyncCallback&lt;void&gt;): void

取消指定id的提醒，使用callback方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderId | number | 是 | 目标reminder的id号。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步回调。 |

**错误码：**

以下错误码的详细介绍请参见[@ohos.reminderAgentManager（后台代理提醒）](../errorcodes/errorcode-reminderAgentManager.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**示例**：

```js
try {
    reminderAgentManager.cancelReminder(1, (err, data) => {
        if (err) {
            console.log("callback err code:" + err.code + " message:" + err.message);
        } else {
            console.log("cancelReminder callback");
        }
    });
} catch (error) {
    console.log("cancelReminder code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.cancelReminder

cancelReminder(reminderId: number): Promise&lt;void&gt;

取消指定id的提醒，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderId | number | 是 | 目标reminder的id号。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise类型异步回调。 |

**错误码：**

以下错误码的详细介绍请参见[@ohos.reminderAgentManager（后台代理提醒）](../errorcodes/errorcode-reminderAgentManager.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**示例**：

```js
try {
    reminderAgentManager.cancelReminder(1).then(() => {
        console.log("cancelReminder promise");
    }).catch(err => {
        console.log("promise err code:" + err.code + " message:" + err.message);
    });
} catch (error) {
    console.log("cancelReminder code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.getValidReminders

getValidReminders(callback: AsyncCallback&lt;Array&lt;ReminderRequest&gt;&gt;): void

获取当前应用已设置的所有有效（未过期）的提醒，使用callback方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[ReminderRequest](#reminderrequest)&gt;&gt; | 是 | 异步回调，返回当前应用已设置的所有有效（未过期）的提醒。 |

**错误码：**

以下错误码的详细介绍请参见[@ohos.reminderAgentManager（后台代理提醒）](../errorcodes/errorcode-reminderAgentManager.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**示例**：

```js
try {
    reminderAgentManager.getValidReminders((err, reminders) => {
        if (err) {
            console.log("callback err code:" + err.code + " message:" + err.message);
        } else {
            console.log("callback, getValidReminders length = " + reminders.length);
            for (let i = 0; i < reminders.length; i++) {
                console.log("getValidReminders = " + reminders[i]);
                console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
                for (let j = 0; j < reminders[i].actionButton.length; j++) {
                    console.log("getValidReminders, actionButton.title = " + reminders[i].actionButton[j].title);
                    console.log("getValidReminders, actionButton.type = " + reminders[i].actionButton[j].type);
                }
                console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent.pkgName);
                console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent.abilityName);
                console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent.pkgName);
                console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent.abilityName);
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
    })
} catch (error) {
    console.log("getValidReminders code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.getValidReminders

getValidReminders(): Promise&lt;Array&lt;ReminderRequest&gt;&gt;

获取当前应用已设置的所有有效（未过期）的提醒，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[ReminderRequest](#reminderrequest)&gt;&gt; | 返回当前应用已设置的所有有效（未过期）的提醒。 |

**错误码：**

以下错误码的详细介绍请参见[@ohos.reminderAgentManager（后台代理提醒）](../errorcodes/errorcode-reminderAgentManager.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**示例**：

```js
try {
    reminderAgentManager.getValidReminders().then((reminders) => {
        console.log("promise, getValidReminders length = " + reminders.length);
        for (let i = 0; i < reminders.length; i++) {
            console.log("getValidReminders = " + reminders[i]);
            console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
            for (let j = 0; j < reminders[i].actionButton.length; j++) {
                console.log("getValidReminders, actionButton.title = " + reminders[i].actionButton[j].title);
                console.log("getValidReminders, actionButton.type = " + reminders[i].actionButton[j].type);
            }
            console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent.pkgName);
            console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent.abilityName);
            console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent.pkgName);
            console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent.abilityName);
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
    }).catch(err => {
        console.log("promise err code:" + err.code + " message:" + err.message);
    });
} catch (error) {
    console.log("getValidReminders code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.cancelAllReminders

cancelAllReminders(callback: AsyncCallback&lt;void&gt;): void

取消当前应用所有的提醒，使用callback方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步回调。 |

**错误码：**

以下错误码的详细介绍请参见[@ohos.reminderAgentManager（后台代理提醒）](../errorcodes/errorcode-reminderAgentManager.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**示例**：

```js
try {
    reminderAgentManager.cancelAllReminders((err, data) =>{
        if (err) {
            console.log("callback err code:" + err.code + " message:" + err.message);
        } else {
            console.log("cancelAllReminders callback")
        }
    })
} catch (error) {
    console.log("cancelAllReminders code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.cancelAllReminders

cancelAllReminders(): Promise&lt;void&gt;

取消当前应用所有的提醒，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise类型异步回调。 |

**错误码：**

以下错误码的详细介绍请参见[@ohos.reminderAgentManager（后台代理提醒）](../errorcodes/errorcode-reminderAgentManager.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**示例**：

```js
try {
    reminderAgentManager.cancelAllReminders().then(() => {
        console.log("cancelAllReminders promise")
    }).catch(err => {
        console.log("promise err code:" + err.code + " message:" + err.message);
    });
} catch (error) {
    console.log("cancelAllReminders code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.addNotificationSlot

addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback&lt;void&gt;): void

添加一个NotificationSlot，使用callback方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](js-apis-notification.md#notificationslot) | 是 | notification&nbsp;slot实例，仅支持设置其type属性。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步回调。 |

**示例**：

```js
import notification from '@ohos.notification'

let mySlot = {
    type: notification.SlotType.SOCIAL_COMMUNICATION
}
try {
    reminderAgentManager.addNotificationSlot(mySlot, (err, data) => {
        if (err) {
            console.log("callback err code:" + err.code + " message:" + err.message);
        } else {
            console.log("addNotificationSlot callback");
        }
    });
} catch (error) {
    console.log("addNotificationSlot code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.addNotificationSlot

addNotificationSlot(slot: NotificationSlot): Promise&lt;void&gt;

添加一个NotificationSlot，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](js-apis-notification.md#notificationslot) | 是 | notification&nbsp;slot实例，仅支持设置其type属性。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise类型异步回调。 |

**示例**：

```js
import notification from '@ohos.notification'

let mySlot = {
    type: notification.SlotType.SOCIAL_COMMUNICATION
}
try {
    reminderAgentManager.addNotificationSlot(mySlot).then(() => {
        console.log("addNotificationSlot promise");
    }).catch(err => {
        console.log("promise err code:" + err.code + " message:" + err.message);
    });
} catch (error) {
    console.log("addNotificationSlot code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback&lt;void&gt;): void

删除目标NotificationSlot，使用callback方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | 是 | 目标notification&nbsp;slot的类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步回调。 |

**示例**：

```js
import notification from '@ohos.notification'

try {
    reminderAgentManager.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION, (err, data) => {
        if (err) {
            console.log("callback err code:" + err.code + " message:" + err.message);
        } else {
            console.log("removeNotificationSlot callback");
        }
    });
} catch (error) {
    console.log("removeNotificationSlot code:" + error.code + " message:" + error.message);
};
```


## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType): Promise&lt;void&gt;

删除目标NotificationSlot，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Notification.ReminderAgent

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | 是 | 目标notification&nbsp;slot的类型。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise类型异步回调。 |

**示例**：

```js
import notification from '@ohos.notification'

try {
    reminderAgentManager.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {
        console.log("removeNotificationSlot promise");
    }).catch(err => {
        console.log("promise err code:" + err.code + " message:" + err.message);
    });
} catch (error) {
    console.log("removeNotificationSlot code:" + error.code + " message:" + error.message);
};
```

## ActionButtonType

按钮的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | 表示关闭提醒的按钮。 |
| ACTION_BUTTON_TYPE_SNOOZE | 1 | 表示延迟提醒的按钮。 |


## ReminderType

提醒的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| REMINDER_TYPE_TIMER | 0 | 表示提醒类型：倒计时。 |
| REMINDER_TYPE_CALENDAR | 1 | 表示提醒类型：日历。 |
| REMINDER_TYPE_ALARM | 2 | 表示提醒类型：闹钟。 |


## ActionButton

用于设置弹出的提醒通知信息上显示的按钮类型和标题。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| title | string | 是 | 按钮显示的标题。 |
| type | [ActionButtonType](#actionbuttontype) | 是 | 按钮的类型。 |


## WantAgent

点击提醒通知后跳转的目标ability信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 指明点击提醒通知栏后跳转的目标hap包名。 |
| abilityName | string | 是 | 指明点击提醒通知栏后跳转的目标ability名称。 |


## MaxScreenWantAgent

全屏显示提醒到达时自动拉起的目标ability信息，该接口预留。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 指明提醒到达时自动拉起的目标hap包名（如果设备在使用中，则只弹出通知横幅框）。 |
| abilityName | string | 是 | 指明提醒到达时自动拉起的目标ability名（如果设备在使用中，则只弹出通知横幅框）。 |


## ReminderRequest

提醒实例对象，用于设置提醒类型、响铃时长等具体信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reminderType | [ReminderType](#remindertype) | 是 | 指明提醒类型。 |
| actionButton | [ActionButton](#actionbutton) | 否 | 弹出的提醒通知栏中显示的按钮（参数可选，支持0/1/2个按钮）。 |
| wantAgent | [WantAgent](#wantagent) | 否 | 点击通知后需要跳转的目标ability信息。 |
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagent) | 否 | 提醒到达时跳转的目标包。如果设备正在使用中，则弹出一个通知框。 |
| ringDuration | number | 否 | 指明响铃时长（单位：秒）。 |
| snoozeTimes | number | 否 | 指明延迟提醒次数。 |
| timeInterval | number | 否 | 执行延迟提醒间隔（单位：秒）。 |
| title | string | 否 | 指明提醒标题。 |
| content | string | 否 | 指明提醒内容。 |
| expiredContent | string | 否 | 指明提醒过期后需要显示的内容。 |
| snoozeContent | string | 否 | 指明延迟提醒时需要显示的内容。 |
| notificationId | number | 否 | 指明提醒使用的通知的id号，相同id号的提醒会覆盖。 |
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | 否 | 指明提醒的slot类型。 |


## ReminderRequestCalendar

ReminderRequestCalendar extends ReminderRequest

日历实例对象，用于设置提醒的时间。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| dateTime | [LocalDateTime](#localdatetime) | 是 | 指明提醒的目标时间。 |
| repeatMonths | Array&lt;number&gt; | 否 | 指明重复提醒的月份。 |
| repeatDays | Array&lt;number&gt; | 否 | 指明重复提醒的日期。 |


## ReminderRequestAlarm

ReminderRequestAlarm extends ReminderRequest

闹钟实例对象，用于设置提醒的时间。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| hour | number | 是 | 指明提醒的目标时刻。 |
| minute | number | 是 | 指明提醒的目标分钟。 |
| daysOfWeek | Array&lt;number&gt; | 否 | 指明每周哪几天需要重复提醒。范围为周一到周末，对应数字为1到7。 |


## ReminderRequestTimer

ReminderRequestTimer extends ReminderRequest

倒计时实例对象，用于设置提醒的时间。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| triggerTimeInSeconds | number | 是 | 指明倒计时的秒数。 |


## LocalDateTime

用于日历类提醒设置时指定时间信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.ReminderAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| year | number | 是 | 年 |
| month | number | 是 | 月 |
| day | number | 是 | 日 |
| hour | number | 是 | 时 |
| minute | number | 是 | 分 |
| second | number | 否 | 秒 |
