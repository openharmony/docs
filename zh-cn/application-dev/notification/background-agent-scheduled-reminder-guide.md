# 开发指导

## 场景介绍

后台代理提醒主要提供后台提醒发布接口，开发者在应用开发时，可以调用这些接口去创建定时提醒，包括倒计时、日历、闹钟三种提醒类型。使用后台代理提醒能力后，应用可以被冻结或退出，计时和弹出提醒的功能将被后台系统服务代理。


## 接口说明

reminderAgent：封装了发布、取消提醒类通知的方法

**表1** reminderAgent主要接口

| 接口名 | 描述 |
| -------- | -------- |
| function&nbsp;publishReminder(reminderReq:&nbsp;ReminderRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void;<br/>function&nbsp;publishReminder(reminderReq:&nbsp;ReminderRequest):&nbsp;Promise&lt;number&gt;; | 发布一个定时提醒类通知。<br/>单个应用有效的提醒个数最多支持30个（不包括已经超时，即后续不会再提醒的提醒实例）<br/>整个系统有效的提醒个数最多支持2000个（不包括已经超时，即后续不会再提醒的提醒实例） |
| function&nbsp;cancelReminder(reminderId:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void;<br/>function&nbsp;cancelReminder(reminderId:&nbsp;number):&nbsp;Promise&lt;void&gt;; | 取消一个指定的提醒类通知。(reminderId从publishReminder的返回值获取) |
| function&nbsp;getValidReminders(callback:&nbsp;AsyncCallback&lt;Array&lt;ReminderRequest&gt;&gt;):&nbsp;void;<br/>function&nbsp;getValidReminders():&nbsp;Promise&lt;Array&lt;ReminderRequest&gt;&gt;; | 获取当前应用设置的所有有效的提醒。 |
| function&nbsp;cancelAllReminders(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void;<br/>function&nbsp;cancelAllReminders():&nbsp;Promise&lt;void&gt;; | 取消当前应用设置的所有提醒 |
| function&nbsp;addNotificationSlot(slot:&nbsp;NotificationSlot,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void;<br/>function&nbsp;addNotificationSlot(slot:&nbsp;NotificationSlot):&nbsp;Promise&lt;void&gt;; | 注册一个提醒类需要使用的NotificationSlot |
| function&nbsp;removeNotificationSlot(slotType:&nbsp;notification.SlotType,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void;<br/>function&nbsp;removeNotificationSlot(slotType:&nbsp;notification.SlotType):&nbsp;Promise&lt;void&gt;; | 删除指定类型的NotificationSlot |

enum ActionButtonType: 在提醒弹出的通知界面上的按钮的类型。

**表2** ActionButtonType 枚举类型

| 枚举名 | 描述 |
| -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 指明是close按钮，点击后关闭当前提醒的铃声（如果正在响铃），关闭提醒的通知，取消延迟提醒。 |

enum ReminderType: 提醒类型

**表3** ReminderType 提醒类型枚举

| 枚举名 | 描述 |
| -------- | -------- |
| REMINDER_TYPE_TIMER | 指明是倒计时类型 |
| REMINDER_TYPE_CALENDAR | 指明是日历类型 |
| REMINDER_TYPE_ALARM | 指明是闹钟类型 |

interface ActionButton：在提醒弹出的通知界面上的按钮实例

**表4** ActionButton

| 参数名 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| title | string | 是 | 按钮上显示的名称 |
| type | ActionButtonType | 是 | 按钮的类型 |

interface WantAgent: 设置点击通知后需要跳转的目标ability信息

**表5** WantAgent

| 参数名 | 类型 | 是否必选 | 描述 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 目标包的名称 |
| abilityName | string | 是 | 目标ability的名称 |

interface MaxScreenWantAgent: 设置提醒到达时跳转的目标包。如果设备正在使用中，则弹出一个通知框

**表6** MaxScreenWantAgent

| 参数名 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| pkgName | string | 是 | 目标包的名称 |
| abilityName | string | 是 | 目标ability的名称 |

interface ReminderRequest: 需要发布的提醒实例的信息

**表7** ReminderRequest

| 参数名 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| reminderType | ReminderType | 是 | 提醒的类型 |
| actionButton | [ActionButton?,ActionButton?] | 否 | 弹出的提醒通知栏中显示的按钮 |
| wantAgent | WantAgent | 否 | 点击通知后需要跳转的目标ability信息 |
| maxScreenWantAgent | MaxScreenWantAgent | 否 | 提醒到达时跳转的目标包。如果设备正在使用中，则弹出一个通知框 |
| ringDuration | number | 否 | 响铃时长 |
| snoozeTimes | number | 否 | 延迟提醒次数 |
| timeInterval | number | 否 | 延迟提醒间隔 |
| title | string | 否 | 提醒的标题 |
| content | string | 否 | 提醒的内容 |
| expiredContent | string | 否 | 提醒“过期”时显示的扩展内容 |
| snoozeContent | string | 否 | 提醒“再响”时显示的扩展内容 |
| notificationId | number | 否 | 提醒使用的notificationRequest的id，参见NotificationRequest::SetNotificationId(int32_t&nbsp;id) |
| slotType | SlotType | 否 | 提醒使用的slot类型 |

interface ReminderRequestCalendar extends ReminderRequest: 日历类提醒实例。

如果没有指定重复的月或天，那么第一次指定的目标时间必须大于当前时间，否则应用将异常退出。

**表8** ReminderRequestCalendar

| 参数名 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| dateTime | LocalDateTime | 是 | 设置目标时间(精确到分钟级别) |
| repeatMonths | Array&lt;number&gt; | 否 | 设置重复提醒的月份，范围从 1 到 12 |
| repeatDays | Array&lt;number&gt; | 否 | 设置重复提醒的日期，范围从 1 到 31 |

interface ReminderRequestAlarm extends ReminderRequest: 闹钟类提醒实例。

**表9** ReminderRequestAlarm

| 参数名 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| hour | number | 是 | 设置目标时间（小时），范围从 0 到 23 |
| minute | number | 是 | 设置目标时间（分钟），范围从 0 到 59 |
| daysOfWeek | Array&lt;number&gt; | 否 | 设置每个星期哪一天重复提醒，范围从 1 到 7 |

interface ReminderRequestTimer extends ReminderRequest：倒计时提醒实例

**表10** ReminderRequestTimer

| 参数名 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| triggerTimeInSeconds | number | 是 | 设置倒计时秒数 |

interface LocalDateTime：时间信息实例

**表11** LocalDateTime

| 参数名 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| year | number | 是 | 年 |
| month | number | 是 | 月 |
| day | number | 是 | 日 |
| hour | number | 是 | 时 |
| minute | number | 是 | 分 |
| second | number | 否 | 秒 |


## 开发步骤

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 应用需要配置权限：ohos.permission.PUBLISH_AGENT_REMINDER

发布一个10秒倒计时提醒

1. 定义一个倒计时实例
   ```
   import reminderAgent from '@ohos.reminderAgent';
   import notification from '@ohos.notification';
   export default {
       // JS工程写法：
       // timer: {
       // eTS工程写法：
       let timer : reminderAgent.ReminderRequestTimer = {
           reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
           triggerTimeInSeconds: 10,
           actionButton: [
               {
                   title: "close",
                   type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
               }
           ],
           wantAgent: {
               pkgName: "com.example.device",
               abilityName: "com.example.device.MainAbility"
           },
           maxScreenWantAgent: {
               pkgName: "com.example.device",
               abilityName: "com.example.device.MainAbility"
           },
           title: "this is title",
           content: "this is content",
           expiredContent: "this reminder has expired",
           notificationId: 100,
           slotType: notification.SlotType.SOCIAL_COMMUNICATION
       }
   }
   ```

2. 发布提醒
   ```
   startTimer() {
       reminderAgent.publishReminder(this.timer, (err, reminderId) =>{
           this.printInfo(JSON.stringify(err));
           this.printInfo("reminderId:" + reminderId);
       });
   }
   ```

   HML页面：
   ```
   <div class="container">
       <button type="text" value="publishReminder" onclick="startTimer"></button>
   </div>
   ```

日历实例定义：

```
// JS工程写法：
// calendar: {
// eTS工程写法：
let calendar : reminderAgent.ReminderRequestCalendar = {
    reminderType: reminderAgent.ReminderType.REMINDER_TYPE_CALENDAR,
    dateTime: {
        year: 2050,
        month: 7,
        day: 30,
        hour: 11,
        minute: 14,
        second: 30
    },
    repeatMonths: [1],
    repeatDays: [1],
    actionButton: [
        {
            title: "close",
            type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        },
        {
            title: "snooze",
            type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
        },
    ],
    wantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    maxScreenWantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    ringDuration: 5,
    snoozeTimes: 2,
    timeInterval: 5,
    title: "this is title",
    content: "this is content",
    expiredContent: "this reminder has expired",
    snoozeContent: "remind later",
    notificationId: 100,
    slotType: notification.SlotType.SOCIAL_COMMUNICATION
}
```

闹钟实例定义：

```
// JS工程写法：
// alarm: {
// eTS工程写法：
let alarm : reminderAgent.ReminderRequestAlarm = {
    reminderType: reminderAgent.ReminderType.REMINDER_TYPE_ALARM,
    hour: 11,
    minute: 14,
    daysOfWeek: [0],
    actionButton: [
        {
            title: "close",
            type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        },
        {
            title: "snooze",
            type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
        },
    ],
    wantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    maxScreenWantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    ringDuration: 5,
    snoozeTimes: 2,
    timeInterval: 5,
    title: "this is title",
    content: "this is content",
    expiredContent: "this reminder has expired",
    snoozeContent: "remind later",
    notificationId: 100,
    slotType: notification.SlotType.SOCIAL_COMMUNICATION
}
```


## 相关实例

基于后台代理提醒开发，有以下相关实例可供参考：

- [`AlarmClock`：后台代理提醒（eTS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/Notification/AlarmClock)

