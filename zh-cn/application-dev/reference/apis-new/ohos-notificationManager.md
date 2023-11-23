# @ohos.notificationManager    
本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知通道，获取通知的使能状态、角标使能状态，获取通知的相关信息等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import notificationManager from '@ohos.notificationManager'    
```  
    
## publish    
发布通知给指定的用户  
 **调用形式：**     
    
- publish(request: NotificationRequest, callback: AsyncCallback\<void>): void    
起始版本： 9    
- publish(request: NotificationRequest): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | NotificationRequest | true | 用于设置要发布通知的内容和相关配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600004 | Notification is not enabled. |  
| 1600005 | Notification slot is not enabled. |  
| 1600009 | Over max number notifications per second. |  
| 1600012 | No memory space. |  
    
 **示例代码1：**   
示例callback  
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
        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,  
        normal: {  
            title: "test_title",  
            text: "test_text",  
            additionalText: "test_additionalText"  
        }  
    }  
};  
notificationManager.publish(notificationRequest, userId, publishCallback);<i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let notificationRequest: notificationManager.NotificationRequest = {    id: 1,    content: {        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,        normal: {            title: "test_title",            text: "test_text",            additionalText: "test_additionalText"        }    }};  
let userId: number = 1;  
notificationManager.publish(notificationRequest, userId).then(() => {console.info("publish success");}).catch((err: Base.BusinessError) => {    console.error(`publish fail: ${JSON.stringify(err)}`);});    
```    
  
    
## cancel    
通过通知ID和通知标签取消已发布的通知  
 **调用形式：**     
    
- cancel(id: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- cancel(id: number, label: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- cancel(id: number, label?: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | number | true | 通知ID。   |  
| label | string | true | 通知标签。            |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600007 | The notification is not exist. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
notificationManager.cancel(0).then(() => {console.info("cancel success");}).catch((err: Base.BusinessError) => {    console.error(`cancel fail: ${JSON.stringify(err)}`);});    
```    
  
    
## cancelAll    
取消所有已发布的通知  
 **调用形式：**     
    
- cancelAll(callback: AsyncCallback\<void>): void    
起始版本： 9    
- cancelAll(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
  
notificationManager.cancelAll().then(() => {  
	console.info("cancelAll success");  
}).catch((err: Base.BusinessError) => {  
    console.error(`cancelAll fail: ${JSON.stringify(err)}`);  
});    
```    
  
    
## addSlot    
创建指定类型的通知通道  
 **调用形式：**     
    
- addSlot(type: SlotType, callback: AsyncCallback\<void>): void    
起始版本： 9    
- addSlot(type: SlotType): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SlotType | true |  要创建的通知通道的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600012 | No memory space. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION).then(() => {console.info("addSlot success");}).catch((err: Base.BusinessError) => {    console.error(`addSlot fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getSlot    
获取一个指定类型的通知通道  
 **调用形式：**     
    
- getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot>): void    
起始版本： 9    
- getSlot(slotType: SlotType): Promise\<NotificationSlot>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType | SlotType | true | 通知渠道类型，目前分为社交通信、服务提醒、内容咨询和其他类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<NotificationSlot> | 以Promise形式返回获取一个通知通道。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
```null    
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
  
    
 **示例代码2：**   
示例Promise：  
```null    
import Base from '@ohos.base';  
let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;  
notificationManager.getSlot(slotType).then((data: notificationManager.NotificationSlot) => {    console.info("getSlot success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getSlot fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getSlots    
获取此应用程序的所有通知通道  
 **调用形式：**     
    
- getSlots(callback: AsyncCallback\<Array\<NotificationSlot>>): void    
起始版本： 9    
- getSlots(): Promise\<Array\<NotificationSlot>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback形式返回获取此应用程序的所有通知通道的结果。 |  
| Promise<Array<NotificationSlot>> | 以Promise形式返回获取此应用程序的所有通知通道的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
```null    
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
  
    
 **示例代码2：**   
示例Promise：  
```null    
import Base from '@ohos.base';  
notificationManager.getSlots().then((data: Array<notificationManager.NotificationSlot>) => {console.info("getSlots success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getSlots fail: ${JSON.stringify(err)}`);});    
```    
  
    
## removeSlot    
删除指定类型的通知通道  
 **调用形式：**     
    
- removeSlot(slotType: SlotType, callback: AsyncCallback\<void>): void    
起始版本： 9    
- removeSlot(slotType: SlotType): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType | SlotType | true | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
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
notificationManager.removeSlot(slotType, removeSlotCallback  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;notificationManager.removeSlot(slotType).then(() => {console.info("removeSlot success");}).catch((err: Base.BusinessError) => {    console.error(`removeSlot fail: ${JSON.stringify(err)}`);});    
```    
  
    
## removeAllSlots    
删除所有通知通道  
 **调用形式：**     
    
- removeAllSlots(callback: AsyncCallback\<void>): void    
起始版本： 9    
- removeAllSlots(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
notificationManager.removeAllSlots().then(() => {console.info("removeAllSlots success");}).catch((err: Base.BusinessError) => {    console.error(`removeAllSlots fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getActiveNotificationCount    
获取当前应用未删除的通知数  
 **调用形式：**     
    
- getActiveNotificationCount(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getActiveNotificationCount(): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取未删除通知数回调函数。 |  
| Promise<number> | 以Promise形式返回获取当前应用未删除通知数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
notificationManager.getActiveNotificationCount().then((data: number) => {console.info("getActiveNotificationCount success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getActiveNotificationCount fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getActiveNotifications    
获取当前应用未删除的通知列表  
 **调用形式：**     
    
- getActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void    
起始版本： 9    
- getActiveNotifications(): Promise\<Array\<NotificationRequest>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取当前应用通知列表回调函数。 |  
| Promise<Array<NotificationRequest>> | 以Promise形式返回获取当前应用通知列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
notificationManager.getActiveNotifications().then((data: Array<notificationManager.NotificationRequest>) => {console.info("removeGroupByBundle success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getActiveNotificationCount fail: ${JSON.stringify(err)}`);});    
```    
  
    
## cancelGroup    
取消本应用指定组下的通知  
 **调用形式：**     
    
- cancelGroup(groupName: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- cancelGroup(groupName: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| groupName | string | true | 知组名称，此名称需要在发布通知时通过[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)对象指定。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消本应用指定组下通知的回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let groupName: string = "GroupName";notificationManager.cancelGroup(groupName).then(() => {console.info("cancelGroup success");}).catch((err: Base.BusinessError) => {    console.error(`cancelGroup fail: ${JSON.stringify(err)}`);});    
```    
  
    
## isSupportTemplate    
查询模板是否存在  
 **调用形式：**     
    
- isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isSupportTemplate(templateName: string): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| templateName | string | true | 模板名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 查询模板是否存在的回调函数。 |  
| Promise<boolean> | Promise方式返回模板是否存在的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
let templateName: string = 'process';  
notificationManager.isSupportTemplate(templateName).then((data: boolean) => {    console.info("isSupportTemplate success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`isSupportTemplate fail: ${JSON.stringify(err)}`);});    
```    
  
    
## requestEnableNotification    
应用请求通知使能  
 **调用形式：**     
    
- requestEnableNotification(callback: AsyncCallback\<void>): void    
起始版本： 9    
- requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void>): void    
起始版本： 10    
- requestEnableNotification(): Promise\<void>    
起始版本： 9    
- requestEnableNotification(context: UIAbilityContext): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context<sup>(10+)</sup> | UIAbilityContext | true | 通知弹窗绑定Ability的上下文。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 应用请求通知使能的回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
  
  
```ts    
import Base from '@ohos.base';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import Want from '@ohos.app.ability.Want';  
  
class MyAbility extends UIAbility {  
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import Want from '@ohos.app.ability.Want';  
  
class MyAbility extends UIAbility {  
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
    notificationManager.requestEnableNotification(this.context).then(() => {  
      console.info("requestEnableNotification success");  
    }).catch((err: Base.BusinessError) => {  
      console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);  
    });  
  }  
}  
    
```    
  
    
## isDistributedEnabled    
查询设备是否支持分布式通知  
 **调用形式：**     
    
- isDistributedEnabled(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isDistributedEnabled(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设备是否支持分布式通知的回调函数。 |  
| Promise<boolean> | Promise方式返回设备是否支持分布式通知的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600010 | Distributed operation failed. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
notificationManager.isDistributedEnabled().then((data: boolean) => {    console.info("isDistributedEnabled success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`isDistributedEnabled fail: ${JSON.stringify(err)}`);});    
```    
  
    
## setBadgeNumber<sup>(10+)</sup>    
设定角标个数，在应用的桌面图标上呈现  
 **调用形式：**     
    
- setBadgeNumber(badgeNumber: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setBadgeNumber(badgeNumber: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| badgeNumber | number | true |  角标个数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设定角标回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600012 | No memory space. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
```ts    
import Base from '@ohos.base';  
let badgeNumber: number = 10;  
notificationManager.setBadgeNumber(badgeNumber).then(() => {console.info("displayBadge success");}).catch((err: Base.BusinessError) => {    console.error(`displayBadge fail: ${JSON.stringify(err)}`);});    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
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
  
    
## SlotType    
    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN_TYPE | 0 | 未知类型。 |  
| SOCIAL_COMMUNICATION | 1 | 社交类型。 |  
| SERVICE_INFORMATION | 2 | 服务类型。 |  
| CONTENT_INFORMATION | 3 | 内容类型。 |  
| OTHER_TYPES | 0xFFFF | 其他类型。 |  
    
## ContentType    
    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOTIFICATION_CONTENT_BASIC_TEXT | 0 | 普通类型通知。    |  
| NOTIFICATION_CONTENT_LONG_TEXT | 1 | 长文本类型通知。 |  
| NOTIFICATION_CONTENT_PICTURE | 2 | 图片类型通知。 |  
| NOTIFICATION_CONTENT_CONVERSATION | 3 | 社交类型通知（暂不支持该类型）。 |  
| NOTIFICATION_CONTENT_MULTILINE | 4 |  多行文本类型通知。   |  
    
## SlotLevel    
    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LEVEL_NONE | 0 | 表示关闭通知功能。    |  
| LEVEL_MIN | 1 | 表示通知功能已启用，但状态栏中不显示通知图标，且没有横幅或提示音。 |  
| LEVEL_LOW | 2 | 表示通知功能已启用，且状态栏中显示通知图标，但没有横幅或提示音。 |  
| LEVEL_DEFAULT | 3 | 表示通知功能已启用，状态栏中显示通知图标，没有横幅但有提示音。 |  
| LEVEL_HIGH | 4 | 表示通知功能已启用，状态栏中显示通知图标，有横幅和提示音。 |  
