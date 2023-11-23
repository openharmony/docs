# @ohos.reminderAgentManager    
本模块提供后台代理提醒的能力，即当应用被冻结或应用退出时，计时和提醒的功能将被系统服务代理。在开发过程中，开发者可以调用本模块接口创建定时提醒，提醒类型支持倒计时、日历、闹钟三种。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import reminderAgentManager from '@ohos.reminderAgentManager'    
```  
    
## publishReminder    
发布后台代理提醒。  
 **调用形式：**     
    
- publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void    
起始版本： 9    
- publishReminder(reminderReq: ReminderRequest): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.ReminderAgent  
 **需要权限：** ohos.permission.PUBLISH_AGENT_REMINDER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reminderReq | ReminderRequest | true | 需要发布的代理提醒实例。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前发布提醒的id。 |  
| Promise<number> | Promise对象，返回提醒的id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1700001 | Notification is not enabled. |  
| 1700002 | The number of reminders exceeds the limit. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let timer: reminderAgentManager.ReminderRequestTimer = {  
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,  
  triggerTimeInSeconds: 10  
}  
  
reminderAgentManager.publishReminder(timer, (err: BusinessError, reminderId: number) => {  
  if (err) {  
    console.log("callback err code:" + err.code + " message:" + err.message);  
  } else {  
    console.log("callback, reminderId = " + reminderId);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let timer: reminderAgentManager.ReminderRequestTimer = {  
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,  
  triggerTimeInSeconds: 10  
}  
  
reminderAgentManager.publishReminder(timer).then((reminderId: number) => {  
  console.log("promise, reminderId = " + reminderId);  
}).catch((err: BusinessError) => {  
  console.log("promise err code:" + err.code + " message:" + err.message);  
});  
    
```    
  
    
## cancelReminder    
取消指定Id的代理提醒。  
 **调用形式：**     
    
- cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- cancelReminder(reminderId: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reminderId | number | true | 需要取消的代理提醒的Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，取消代理提醒成功，err为undefined，否则返回err信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1700003 | The reminder does not exist. |  
| 1700004 | The bundle name does not exist. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let reminderId: number = 1;  
reminderAgentManager.cancelReminder(reminderId, (err: BusinessError, data: void) => {  
  if (err) {  
    console.log("callback err code:" + err.code + " message:" + err.message);  
  } else {  
    console.log("cancelReminder callback");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let reminderId: number = 1;  
reminderAgentManager.cancelReminder(reminderId).then(() => {  
  console.log("cancelReminder promise");  
}).catch((err: BusinessError) => {  
  console.log("promise err code:" + err.code + " message:" + err.message);  
});  
    
```    
  
    
## getValidReminders    
获取当前应用设置的所有有效（未过期）的代理提醒。  
 **调用形式：**     
    
- getValidReminders(callback: AsyncCallback\<Array\<ReminderRequest>>): void    
起始版本： 9    
- getValidReminders(): Promise\<Array\<ReminderRequest>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前应用设置的所有有效的代理提醒。 |  
| Promise<Array<ReminderRequest>> | Promise对象，返回当前应用设置的所有有效的代理提醒。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1700004 | The bundle name does not exist. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
reminderAgentManager.getValidReminders((err: BusinessError, reminders: Array<reminderAgentManager.ReminderRequest>) => {  
  if (err) {  
    console.log("callback err code:" + err.code + " message:" + err.message);  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
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
  console.log("promise err code:" + err.code + " message:" + err.message);  
});  
    
```    
  
    
## cancelAllReminders    
取消当前应用设置的所有代理提醒。  
 **调用形式：**     
    
- cancelAllReminders(callback: AsyncCallback\<void>): void    
起始版本： 9    
- cancelAllReminders(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，取消代理提醒成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1700004 | The bundle name does not exist. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
reminderAgentManager.cancelAllReminders((err: BusinessError, data: void) =>{  
  if (err) {  
    console.log("callback err code:" + err.code + " message:" + err.message);  
  } else {  
    console.log("cancelAllReminders callback")  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
reminderAgentManager.cancelAllReminders().then(() => {  
  console.log("cancelAllReminders promise")  
}).catch((err: BusinessError) => {  
  console.log("promise err code:" + err.code + " message:" + err.message);  
});  
    
```    
  
    
## addNotificationSlot    
添加NotificationSlot（通知槽）。  
 **调用形式：**     
    
- addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void    
起始版本： 9    
- addNotificationSlot(slot: NotificationSlot): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slot | NotificationSlot | true | notification\.slot实例，仅支持设置其type属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，添加NotificationSlot成功时，err为undefined，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import notification from '@ohos.notificationManager'  
import { BusinessError } from '@ohos.base';  
  
let mySlot: notification.NotificationSlot = {  
  type: notification.SlotType.SOCIAL_COMMUNICATION  
}  
  
reminderAgentManager.addNotificationSlot(mySlot, (err: BusinessError, data: void) => {  
  if (err) {  
    console.log("callback err code:" + err.code + " message:" + err.message);  
  } else {  
    console.log("addNotificationSlot callback");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import notification from '@ohos.notificationManager'  
import { BusinessError } from '@ohos.base';  
  
let mySlot: notification.NotificationSlot = {  
  type: notification.SlotType.SOCIAL_COMMUNICATION  
}  
reminderAgentManager.addNotificationSlot(mySlot).then(() => {  
  console.log("addNotificationSlot promise");  
}).catch((err: BusinessError) => {  
  console.log("promise err code:" + err.code + " message:" + err.message);  
});  
    
```    
  
    
## removeNotificationSlot    
删除目标NotificationSlot（通知槽）  
 **调用形式：**     
    
- removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void    
起始版本： 9    
- removeNotificationSlot(slotType: notification.SlotType): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType | notification.SlotType | true | 目标notification\.slot的类型。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当删除成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import notification from '@ohos.notificationManager'  
import { BusinessError } from '@ohos.base';  
  
reminderAgentManager.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION,  
  (err: BusinessError, data: void) => {  
  if (err) {  
    console.log("callback err code:" + err.code + " message:" + err.message);  
  } else {  
    console.log("removeNotificationSlot callback");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import notification from '@ohos.notificationManager'  
import { BusinessError } from '@ohos.base';  
  
reminderAgentManager.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {  
  console.log("removeNotificationSlot promise");  
}).catch((err: BusinessError) => {  
  console.log("promise err code:" + err.code + " message:" + err.message);  
});  
    
```    
  
    
## ActionButtonType    
按钮的类型。    
    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACTION_BUTTON_TYPE_CLOSE | 0 | 表示关闭提醒的按钮。 |  
| ACTION_BUTTON_TYPE_SNOOZE | 1 | 表示延迟提醒的按钮。 |  
    
## ReminderType    
提醒的类型。    
    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| REMINDER_TYPE_TIMER | 0 | 表示提醒类型：倒计时。 |  
| REMINDER_TYPE_CALENDAR | 1 | 表示提醒类型：日历。 |  
| REMINDER_TYPE_ALARM | 2 | 表示提醒类型：闹钟。 |  
    
## ActionButton    
弹出的提醒通知中按钮的类型和标题。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | string | false | true | 按钮显示的标题。 |  
| type | ActionButtonType | false | true | 按钮的类型。 |  
    
## WantAgent    
跳转目标的ability信息。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pkgName | string | false | true | 指明跳转目标的包名。 |  
| abilityName | string | false | true | 指明跳转目标的ability名称。 |  
    
## MaxScreenWantAgent    
提醒到达时，全屏显示自动拉起目标的ability信息。该接口为预留接口，暂不支持使用  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pkgName | string | false | true | 指明提醒到达时自动拉起的目标包名（如果设备在使用中，则只弹出通知横幅框）。  |  
| abilityName | string | false | true | 指明提醒到达时自动拉起的目标ability名（如果设备在使用中，则只弹出通知横幅框）。 |  
    
## ReminderRequest    
代理提醒对象，用于设置提醒类型、响铃时长等具体信息。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| reminderType | ReminderType | false | true | 指明代理提醒类型。 |  
| actionButton | [ActionButton?, ActionButton?, ActionButton?] | false | false | 弹出的提醒通知栏中显示的按钮。<br>-普通应用：最多支持两个按钮。<br>-系统应用：API9最多支持两个按钮，在API10开始最多支持三个按钮。 |  
| wantAgent | WantAgent | false | false | 点击通知后需要跳转的目标ability信息。 |  
| maxScreenWantAgent | MaxScreenWantAgent | false | false | 提醒到达时，全屏显示自动拉起目标的ability信息。如果设备正在使用中，则弹出一个通知框。 <br> 说明：该接口为预留接口，暂不支持使用。 |  
| ringDuration | number | false | false | 指明响铃时长（单位：秒），默认1秒。 |  
| snoozeTimes | number | false | false | 指明延迟提醒次数，默认0次。 |  
| timeInterval | number | false | false | 执行延迟提醒间隔（单位：秒），最少5分钟。 |  
| title | string | false | false | 指明提醒标题。 |  
| content | string | false | false | 指明提醒内容。 |  
| expiredContent | string | false | false |  指明提醒过期后需要显示的内容。 |  
| snoozeContent | string | false | false | 指明延迟提醒时需要显示的内容。  |  
| notificationId | number | false | false | 指明提醒使用的通知的id号，相同id号的提醒会覆盖。 |  
| slotType | notification.SlotType | false | false | 指明提醒的slot类型。  |  
| tapDismissed<sup>(10+)</sup> | boolean | false | false | 通知是否自动清除，具体请参考[NotificationRequest.tapDismissed](js-apis-inner-notification-notificationRequest.md#notificationrequest)。  |  
| autoDeletedTime<sup>(10+)</sup> | number | false | false |  自动清除的时间，具体请参考[NotificationRequest.autoDeletedTime](js-apis-inner-notification-notificationRequest.md#notificationrequest)。  |  
    
## ReminderRequestCalendar    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| dateTime | LocalDateTime | false | true |  |  
| repeatMonths | Array<number> | false | false |  |  
| repeatDays | Array<number> | false | false |  |  
    
## ReminderRequestAlarm    
闹钟实例对象，用于设置提醒的时间。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| hour | number | false | true | 指明提醒的目标时刻。 |  
| minute | number | false | true | 指明提醒的目标分钟。 |  
| daysOfWeek | Array<number> | false | false | 指明每周哪几天需要重复提醒。范围为周一到周日，对应数字为1到7。 |  
    
## ReminderRequestTimer    
倒计时实例对象，用于设置提醒的时间。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| triggerTimeInSeconds | number | false | true |  |  
    
## LocalDateTime    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| year | number | false | true |  |  
| month | number | false | true |  |  
| day | number | false | true |  |  
| hour | number | false | true |  |  
| minute | number | false | true |  |  
| second | number | false | false |  |  
