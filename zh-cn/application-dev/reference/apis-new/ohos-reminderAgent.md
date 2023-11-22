# @ohos.reminderAgent    
本模块提供后台代理提醒的能力。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import reminderAgent from '@ohos.reminderAgent'    
```  
    
## publishReminder<sup>(deprecated)</sup>    
发布一个后台代理提醒，使用回调的方式实现异步调用，该方法需要申请通知弹窗权限[Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8)后才能调用。  
 **调用形式：**     
- publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.publishReminder。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent  
 **需要权限：** ohos.permission.PUBLISH_AGENT_REMINDER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reminderReq<sup>(deprecated)</sup> | ReminderRequest | true | 需要发布的提醒实例。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步回调，返回当前发布的提醒的id。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
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
  
    
## publishReminder<sup>(deprecated)</sup>    
发布一个后台代理提醒，使用Promise方式实现异步调用，该方法需要申请通知弹窗权限[Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8)后才能调用。  
 **调用形式：**     
- publishReminder(reminderReq: ReminderRequest): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.publishReminder。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent  
 **需要权限：** ohos.permission.PUBLISH_AGENT_REMINDER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reminderReq<sup>(deprecated)</sup> | ReminderRequest | true | 需要发布的提醒实例。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 返回提醒的Id。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
let timer:reminderAgent.ReminderRequestTimer = {  reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,  triggerTimeInSeconds: 10}  
reminderAgent.publishReminder(timer).then((reminderId: number) => {  console.log("promise, reminderId = " + reminderId);});    
```    
  
    
## cancelReminder<sup>(deprecated)</sup>    
取消指定id的提醒，使用回调的方式实现异步调用。  
 **调用形式：**     
- cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.cancelReminder。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reminderId<sup>(deprecated)</sup> | number | true | 目标reminder的id号，[publishReminder](#reminderagentpublishreminder)方法调用成功后获得。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
reminderAgent.cancelReminder(1, (err: BusinessError, data: void) => {  
  console.log("cancelReminder callback");  
});  
    
```    
  
    
## cancelReminder<sup>(deprecated)</sup>    
取消指定id的提醒，使用Promise方式实现异步调用。  
 **调用形式：**     
- cancelReminder(reminderId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.cancelReminder。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reminderId<sup>(deprecated)</sup> | number | true | 目标reminder的id号，[publishReminder](#reminderagentpublishreminder)方法调用成功后获得。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise类型异步回调。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
reminderAgent.cancelReminder(1).then(() => {    console.log("cancelReminder promise");});    
```    
  
    
## getValidReminders<sup>(deprecated)</sup>    
获取当前应用已设置的所有有效（未过期）的提醒，使用回调的方式实现异步调用。  
 **调用形式：**     
- getValidReminders(callback: AsyncCallback\<Array\<ReminderRequest>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.getValidReminders。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<ReminderRequest>> | true | 异步回调，返回当前应用已设置的所有有效（未过期）的提醒。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
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
})  
    
```    
  
    
## getValidReminders<sup>(deprecated)</sup>    
获取当前应用已设置的所有有效（未过期）的提醒，使用Promise方式实现异步调用。  
 **调用形式：**     
- getValidReminders(): Promise\<Array\<ReminderRequest>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.getValidReminders。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<ReminderRequest>> | 返回当前应用已设置的所有有效（未过期）的提醒。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
reminderAgent.getValidReminders().then((reminders: Array<reminderAgent.ReminderRequest>) => {  console.log("promise, getValidReminders length = " + reminders.length);  for (let i = 0; i < reminders.length; i++) {    console.log("getValidReminders = " + reminders[i]);    console.log("getValidReminders, reminderType = " + reminders[i].reminderType);    const actionButton = reminders[i].actionButton || [];    for (let j = 0; j < actionButton.length; j++) {      console.log("getValidReminders, actionButton.title = " + actionButton[j]?.title);      console.log("getValidReminders, actionButton.type = " + actionButton[j]?.type);    }    console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent?.pkgName);    console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent?.abilityName);    console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent?.pkgName);    console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent?.abilityName);    console.log("getValidReminders, ringDuration = " + reminders[i].ringDuration);    console.log("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);    console.log("getValidReminders, timeInterval = " + reminders[i].timeInterval);    console.log("getValidReminders, title = " + reminders[i].title);    console.log("getValidReminders, content = " + reminders[i].content);    console.log("getValidReminders, expiredContent = " + reminders[i].expiredContent);    console.log("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);    console.log("getValidReminders, notificationId = " + reminders[i].notificationId);    console.log("getValidReminders, slotType = " + reminders[i].slotType);  }})    
```    
  
    
## cancelAllReminders<sup>(deprecated)</sup>    
取消当前应用所有的提醒，使用回调的方式实现异步调用。  
 **调用形式：**     
- cancelAllReminders(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.cancelAllReminders。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
reminderAgent.cancelAllReminders((err: BusinessError, data: void) =>{  console.log("cancelAllReminders callback")})    
```    
  
    
## cancelAllReminders<sup>(deprecated)</sup>    
取消当前应用所有的提醒，使用Promise方式实现异步调用。  
 **调用形式：**     
- cancelAllReminders(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.cancelAllReminders。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise类型异步回调。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
reminderAgent.cancelAllReminders().then(() => {    console.log("cancelAllReminders promise")})    
```    
  
    
## addNotificationSlot<sup>(deprecated)</sup>    
添加一个NotificationSlot，使用回调的方式实现异步调用。  
 **调用形式：**     
- addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.addNotificationSlot。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slot<sup>(deprecated)</sup> | NotificationSlot | true | notification\.slot实例，仅支持设置其type属性。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
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
  
    
## addNotificationSlot<sup>(deprecated)</sup>    
添加一个NotificationSlot，使用Promise方式实现异步调用。  
 **调用形式：**     
- addNotificationSlot(slot: NotificationSlot): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.addNotificationSlot。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slot<sup>(deprecated)</sup> | NotificationSlot | true | notification\.slot实例，仅支持设置其type属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise类型异步回调。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import notification from '@ohos.notificationManager'  
let mySlot:notification.NotificationSlot = {  type: notification.SlotType.SOCIAL_COMMUNICATION}reminderAgent.addNotificationSlot(mySlot).then(() => {  console.log("addNotificationSlot promise");});    
```    
  
    
## removeNotificationSlot<sup>(deprecated)</sup>    
删除目标NotificationSlot，使用callback方式实现异步调用。  
 **调用形式：**     
- removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.removeNotificationSlot。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType<sup>(deprecated)</sup> | notification.SlotType | true | 目标notification\.slot的类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步回调。  |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import notification from '@ohos.notification'  
import { BusinessError } from '@ohos.base';  
  
reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION, (err: BusinessError, data: void) => {  
  console.log("removeNotificationSlot callback");  
});  
    
```    
  
    
## removeNotificationSlot<sup>(deprecated)</sup>    
删除目标NotificationSlot，使用Promise方式实现异步调用。  
 **调用形式：**     
- removeNotificationSlot(slotType: notification.SlotType): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: reminderAgentManager.removeNotificationSlot。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType<sup>(deprecated)</sup> | notification.SlotType | true | 目标notification\.slot的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise类型异步回调。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import notification from '@ohos.notification'  
reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {    console.log("removeNotificationSlot promise");});    
```    
  
    
## ActionButtonType<sup>(deprecated)</sup>    
按钮的类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ActionButtonType替代。    
    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACTION_BUTTON_TYPE_CLOSE<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE替代。<br>表示关闭提醒的按钮。 |  
| ACTION_BUTTON_TYPE_SNOOZE<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE替代。<br>表示延迟提醒的按钮。 |  
    
## ReminderType<sup>(deprecated)</sup>    
提醒的类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderType替代。    
    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| REMINDER_TYPE_TIMER<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER替代。<br>表示提醒类型：倒计时。 |  
| REMINDER_TYPE_CALENDAR<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderType.REMINDER_TYPE_CALENDAR替代。<br>表示提醒类型：日历。 |  
| REMINDER_TYPE_ALARM<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderType.REMINDER_TYPE_ALARM替代。<br>表示提醒类型：闹钟。 |  
    
## ActionButton<sup>(deprecated)</sup>    
用于设置弹出的提醒通知信息上显示的按钮类型和标题。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ActionButton替代。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ActionButton.title替代。<br>按钮显示的标题。 |  
| type<sup>(deprecated)</sup> | ActionButtonType | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ActionButton.type替代。<br>按钮的类型。  |  
    
## WantAgent<sup>(deprecated)</sup>    
点击提醒通知后跳转的目标ability信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.WantAgent替代。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pkgName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.WantAgent.pkgName替代。<br>指明点击提醒通知栏后跳转的目标HAP名。 |  
| abilityName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.WantAgent.abilityName替代。<br>指明点击提醒通知栏后跳转的目标ability名称。 |  
    
## MaxScreenWantAgent<sup>(deprecated)</sup>    
全屏显示提醒到达时自动拉起的目标ability信息，该接口预留。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.MaxScreenWantAgent替代。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pkgName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.MaxScreenWantAgent.pkgName替代。<br>指明提醒到达时自动拉起的目标HAP名（如果设备在使用中，则只弹出通知横幅框）。 |  
| abilityName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.MaxScreenWantAgent.abilityName替代。<br>指明提醒到达时自动拉起的目标ability名（如果设备在使用中，则只弹出通知横幅框）。 |  
    
## ReminderRequest<sup>(deprecated)</sup>    
提醒实例对象，用于设置提醒类型、响铃时长等具体信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest替代。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| reminderType<sup>(deprecated)</sup> | ReminderType | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.reminderType替代。<br>指明提醒类型。 |  
| actionButton<sup>(deprecated)</sup> | [ActionButton?, ActionButton?] | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.actionButton替代。<br>弹出的提醒通知栏中显示的按钮（参数可选，支持0/1/2个按钮）。 |  
| wantAgent<sup>(deprecated)</sup> | WantAgent | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.wantAgent替代。<br>点击通知后需要跳转的目标ability信息。 |  
| maxScreenWantAgent<sup>(deprecated)</sup> | MaxScreenWantAgent | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.maxScreenWantAgent替代。<br>提醒到达时跳转的目标包。如果设备正在使用中，则弹出一个通知框。 |  
| ringDuration<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.ringDuration替代。<br>指明响铃时长（单位：秒），默认1秒。 |  
| snoozeTimes<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.snoozeTimes替代。<br>指明延迟提醒次数，默认0次。 |  
| timeInterval<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.timeInterval替代。<br>执行延迟提醒间隔（单位：秒），默认0秒。 |  
| title<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.title替代。<br>指明提醒标题。 |  
| content<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.content替代。<br>指明提醒内容。 |  
| expiredContent<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.expiredContent替代。<br>指明提醒过期后需要显示的内容。 |  
| snoozeContent<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.snoozeContent替代。<br>指明延迟提醒时需要显示的内容。 |  
| notificationId<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.notificationId替代。<br>指明提醒使用的通知的id号，相同id号的提醒会覆盖。 |  
| slotType<sup>(deprecated)</sup> | notification.SlotType | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequest.slotType替代。<br>指明提醒的slot类型。 |  
    
## ReminderRequestCalendar<sup>(deprecated)</sup>    
日历实例对象，用于设置提醒的时间。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestCalendar替代。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| dateTime<sup>(deprecated)</sup> | LocalDateTime | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestCalendar.dateTime替代。<br>指明提醒的目标时间。 |  
| repeatMonths<sup>(deprecated)</sup> | Array<number> | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestCalendar.repeatMonths替代。<br>指明重复提醒的月份。 |  
| repeatDays<sup>(deprecated)</sup> | Array<number> | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestCalendar.repeatDays替代。<br>指明重复提醒的日期。 |  
    
## ReminderRequestAlarm<sup>(deprecated)</sup>    
闹钟实例对象，用于设置提醒的时间。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestAlarm替代。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| hour<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestAlarm.hour替代。<br>指明提醒的目标时刻。 |  
| minute<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestAlarm.minute替代。<br>指明提醒的目标分钟。 |  
| daysOfWeek<sup>(deprecated)</sup> | Array<number> | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestAlarm.daysOfWeek替代。<br>指明每周哪几天需要重复提醒。范围为周一到周末，对应数字为1到7。  |  
    
## ReminderRequestTimer<sup>(deprecated)</sup>    
倒计时实例对象，用于设置提醒的时间。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestTimer替代。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| triggerTimeInSeconds | number | false | true | 指明倒计时的秒数。 |  
    
## LocalDateTime    
用于日历类提醒设置时指定时间信息。    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| year<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestTimer.year替代。<br>年 |  
| month<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestTimer.month替代。<br><span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">月</span> |  
| day<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestTimer.day替代。<br>日 |  
| hour<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestTimer.hour替代。<br>时。 |  
| minute<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestTimer.minute替代。<br>分 |  
| second<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用reminderAgentManager.ReminderRequestTimer.second替代。<br> 秒 |  
