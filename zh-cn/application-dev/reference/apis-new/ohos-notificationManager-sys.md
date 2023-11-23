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
    
- publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- publish(request: NotificationRequest, userId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | NotificationRequest | true | 用于设置要发布通知的内容和相关配置信息。 |  
| userId | number | true | 用户ID。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600004 | Notification is not enabled. |  
| 1600005 | Notification slot is not enabled. |  
| 1600008 | The user is not exist. |  
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
  
    
## publishAsBundle    
发布代理通知  
 **调用形式：**     
    
- publishAsBundle(     request: NotificationRequest,     representativeBundle: string,     userId: number,     callback: AsyncCallback\<void>   ): void    
起始版本： 9    
- publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER and ohos.permission.NOTIFICATION_AGENT_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | NotificationRequest | true | 用于设置要发布通知的内容和相关配置信息。 |  
| representativeBundle | string | true | 被代理应用的包名。 |  
| userId | number | true | 用户ID。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 发布代理通知的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600004 | Notification is not enabled. |  
| 1600005 | Notification slot is not enabled. |  
| 1600008 | The user is not exist. |  
| 1600009 | Over max number notifications per second. |  
| 1600012 | No memory space. |  
    
 **示例代码1：**   
示例callback：  
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
        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,  
        normal: {  
            title: "test_title",  
            text: "test_text",  
            additionalText: "test_additionalText"  
        }  
    }  
};  
  
notificationManager.publishAsBundle(request, representativeBundle, userId, callback);  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
// 被代理应用的包名let representativeBundle: string = "com.example.demo";// 用户IDlet userId: number = 100;// NotificationRequest对象let request: notificationManager.NotificationRequest = {    id: 1,    content: {        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,        normal: {            title: "test_title",            text: "test_text",            additionalText: "test_additionalText"        }    }};  
notificationManager.publishAsBundle(request, representativeBundle, userId).then(() => {console.info("publishAsBundle success");}).catch((err: Base.BusinessError) => {    console.error(`publishAsBundle fail: ${JSON.stringify(err)}`);});    
```    
  
    
## cancelAsBundle    
取消代理通知  
 **调用形式：**     
    
- cancelAsBundle(     id: number,     representativeBundle: string,     userId: number,     callback: AsyncCallback\<void>   ): void    
起始版本： 9    
- cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER and ohos.permission.NOTIFICATION_AGENT_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | number | true |  通知ID。     |  
| representativeBundle | string | true | 被代理应用的包名。 |  
| userId | number | true | 用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消代理通知的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600007 | The notification is not exist. |  
| 1600008 | The user is not exist. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
// 被代理应用的包名let representativeBundle: string = "com.example.demo";// 用户IDlet userId: number = 100;  
notificationManager.cancelAsBundle(0, representativeBundle, userId).then(() => {console.info("cancelAsBundle success");}).catch((err: Base.BusinessError) => {    console.error(`cancelAsBundle fail: ${JSON.stringify(err)}`);});    
```    
  
    
## addSlot    
创建指定类型的通知通道  
 **调用形式：**     
    
- addSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void    
起始版本： 9    
- addSlot(slot: NotificationSlot): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slot | NotificationSlot | true | 要创建的通知通道对象。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
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
  
    
## addSlots    
创建多个通知通道  
 **调用形式：**     
    
- addSlots(slots: Array\<NotificationSlot>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- addSlots(slots: Array\<NotificationSlot>): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slots | Array<NotificationSlot> | true | 要创建的通知通道对象数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600012 | No memory space. |  
    
 **示例代码1：**   
示例callback：  
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
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION  
};  
// 通知slot array 对象  
let notificationSlotArray: notificationManager.NotificationSlot[] = new Array();  
notificationSlotArray[0] = notificationSlot;  
  
notificationManager.addSlots(notificationSlotArray, addSlotsCallBack);  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
// 通知slot对象let notificationSlot: notificationManager.NotificationSlot = {    type: notificationManager.SlotType.SOCIAL_COMMUNICATION};// 通知slot array 对象let notificationSlotArray: notificationManager.NotificationSlot[] = new Array();notificationSlotArray[0] = notificationSlot;  
notificationManager.addSlots(notificationSlotArray).then(() => {console.info("addSlots success");}).catch((err: Base.BusinessError) => {    console.error(`addSlot fail: ${JSON.stringify(err)}`);});    
```    
  
    
## setNotificationEnable    
设定指定应用的通知使能状态  
 **调用形式：**     
    
- setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setNotificationEnable(bundle: BundleOption, enable: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 指定应用的包信息。 |  
| enable | boolean | true | 使能状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设定通知使能回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {    bundle: "bundleName1",};notificationManager.setNotificationEnable(bundle, false).then(() => {console.info("setNotificationEnable success");}).catch((err: Base.BusinessError) => {    console.error(`setNotificationEnable fail: ${JSON.stringify(err)}`);});    
```    
  
    
## isNotificationEnabled    
获取指定应用的通知使能状态  
 **调用形式：**     
    
- isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isNotificationEnabled(bundle: BundleOption): Promise\<boolean>    
起始版本： 9    
- isNotificationEnabled(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isNotificationEnabled(): Promise\<boolean>    
起始版本： 9    
- isNotificationEnabled(userId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isNotificationEnabled(userId: number): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 指定应用的包信息。 |  
| userId | number | true |  指定的用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取通知使能状态回调函数。 |  
| Promise<boolean> | 以Promise形式返回获取指定应用的通知使能状态的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
| 1600008 | The user is not exist. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {    bundle: "bundleName1",};notificationManager.isNotificationEnabled(bundle).then((data: boolean) => {console.info("isNotificationEnabled success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);});    
```    
  
    
## displayBadge    
设定指定应用的角标使能状态  
 **调用形式：**     
    
- displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- displayBadge(bundle: BundleOption, enable: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 指定应用的包信息。 |  
| enable | boolean | true |  使能状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设定角标使能回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {    bundle: "bundleName1",};notificationManager.displayBadge(bundle, false).then(() => {console.info("displayBadge success");}).catch((err: Base.BusinessError) => {    console.error(`displayBadge fail: ${JSON.stringify(err)}`);});    
```    
  
    
## isBadgeDisplayed    
获取指定应用的角标使能状态  
 **调用形式：**     
    
- isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isBadgeDisplayed(bundle: BundleOption): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 指定应用的包信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取角标使能状态回调函数。 |  
| Promise<boolean> | 以Promise形式返回获取指定应用的角标使能状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {  bundle: "bundleName1",};notificationManager.isBadgeDisplayed(bundle).then((data: boolean) => {console.info("isBadgeDisplayed success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`isBadgeDisplayed fail: ${JSON.stringify(err)}`);    
```    
  
    
## setSlotByBundle    
设定指定应用的通知通道  
 **调用形式：**     
    
- setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setSlotByBundle(bundle: BundleOption, slot: NotificationSlot): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 指定应用的包信息。     |  
| slot | NotificationSlot | true | 通知通道。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设定通知通道回调函数 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
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
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION  
};  
notificationManager.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {    bundle: "bundleName1",};  
let notificationSlot: notificationManager.NotificationSlot = {    type: notificationManager.SlotType.SOCIAL_COMMUNICATION};  
notificationManager.setSlotByBundle(bundle, notificationSlot).then(() => {console.info("setSlotByBundle success");}).catch((err: Base.BusinessError) => {    console.error(`setSlotByBundle fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getSlotsByBundle    
获取指定应用的所有通知通道  
 **调用形式：**     
    
- getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback\<Array\<NotificationSlot>>): void    
起始版本： 9    
- getSlotsByBundle(bundle: BundleOption): Promise\<Array\<NotificationSlot>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 指定应用的包信息。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取通知通道回调函数。 |  
| Promise<Array<NotificationSlot>> | 以Promise形式返回获取指定应用的通知通道。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
  
```ts    
import Base from '@ohos.base';  
  
let getSlotsByBundleCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationSlot>): void => {  
    if (err) {  
        console.error(`getSlotByBundle failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info(`getSlotsByBundle success, data is ${JSON.stringify(data)}`);  
    }  
}  
let bundle: notificationManager.BundleOption = {  
    bundle: "bundleName1",  
};  
notificationManager.getSlotsByBundle(bundle, getSlotsByBundleCallback);  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {    bundle: "bundleName1",};  
notificationManager.getSlotsByBundle(bundle).then((data: Array<notificationManager.NotificationSlot>) => {console.info("getSlotsByBundle success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getSlotsByBundle fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getSlotNumByBundle    
获取指定应用的通知通道数量  
 **调用形式：**     
    
- getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getSlotNumByBundle(bundle: BundleOption): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 指定应用的包信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取通知通道数量回调函数。 |  
| Promise<number> | 以Promise形式返回获取指定应用的通知通道数量。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
```ts    
import Base from '@ohos.base';  
  
let getSlotNumByBundleCallback = (err: Base.BusinessError, data: number): void => {  
    if (err) {  
        console.error(`getSlotByBundle failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info(`getSlotNumByBundle success data is ${JSON.stringify(data)}`);  
    }  
}  
  
let bundle: notificationManager.BundleOption = {  
  bundle: "bundleName1",  
};  
  
notificationManager.getSlotNumByBundle(bundle, getSlotNumByBundleCallback)  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {  bundle: "bundleName1",};  
notificationManager.getSlotNumByBundle(bundle).then((data: number) => {console.info("getSlotNumByBundle success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getSlotsByBundle fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getAllActiveNotifications    
获取当前未删除的所有通知  
 **调用形式：**     
    
- getAllActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void    
起始版本： 9    
- getAllActiveNotifications(): Promise\<Array\<NotificationRequest>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取活动通知回调函数。 |  
| Promise<Array<NotificationRequest>> | 以Promise形式返回获取活动通知。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
notificationManager.getAllActiveNotifications().then((data: Array<notificationManager.NotificationRequest>) => {console.info("getAllActiveNotifications success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getAllActiveNotifications fail: ${JSON.stringify(err)}`);});```    
```    
  
    
## removeGroupByBundle    
删除指定应用的指定组下的通知  
 **调用形式：**     
    
- removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 应用的包信息。       |  
| groupName | string | true | 通知组名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 删除指定应用指定组下通知的回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let bundleOption: notificationManager.BundleOption = { bundle: "Bundle" };let groupName: string = "GroupName";  
notificationManager.removeGroupByBundle(bundleOption, groupName).then(() => {console.info("removeGroupByBundle success");}).catch((err: Base.BusinessError) => {    console.error(`removeGroupByBundle fail: ${JSON.stringify(err)}`);});    
```    
  
    
## setDoNotDisturbDate    
设置免打扰时间  
 **调用形式：**     
    
- setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void>    
起始版本： 9    
- setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | DoNotDisturbDate | true | 免打扰时间选项。 |  
| userId | number | true | 设置免打扰时间的用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设置免打扰时间回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600012 | No memory space. |  
| 1600008 | The user is not exist. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let doNotDisturbDate: notificationManager.DoNotDisturbDate = {    type: notificationManager.DoNotDisturbType.TYPE_ONCE,    begin: new Date(),    end: new Date(2021, 11, 15, 18, 0)};  
let userId: number = 1;  
notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {console.info("setDoNotDisturbDate success");}).catch((err: Base.BusinessError) => {    console.error(`setDoNotDisturbDate fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getDoNotDisturbDate    
查询免打扰时间  
 **调用形式：**     
    
- getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate>): void    
起始版本： 9    
- getDoNotDisturbDate(): Promise\<DoNotDisturbDate>    
起始版本： 9    
- getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate>): void    
起始版本： 9    
- getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId | number | true | 用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 查询免打扰时间回调函数。 |  
| Promise<DoNotDisturbDate> | 以Promise形式返回获取查询到的免打扰时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600012 | No memory space. |  
| 1600008 | The user is not exist. |  
    
 **示例代码1：**   
示例callback：  
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
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
let userId: number = 1;  
notificationManager.getDoNotDisturbDate(userId).then((data: notificationManager.DoNotDisturbDate) => {console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getDoNotDisturbDate fail: ${JSON.stringify(err)}`);});    
```    
  
    
## isSupportDoNotDisturbMode    
查询是否支持免打扰功能  
 **调用形式：**     
    
- isSupportDoNotDisturbMode(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isSupportDoNotDisturbMode(): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 查询是否支持免打扰功能回调函数。 |  
| Promise<boolean> | 以Promise形式返回获取是否支持免打扰功能的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
```ts    
import Base from '@ohos.base';  
  
let isSupportDoNotDisturbModeCallback = (err: Base.BusinessError, data: boolean): void => {  
    if (err) {  
        console.error(`isSupportDoNotDisturbMode failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info("isSupportDoNotDisturbMode success");  
    }  
}  
  
notificationManager.isSupportDoNotDisturbMode(isSupportDoNotDisturbModeCallback)  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
```ts    
import Base from '@ohos.base';  
notificationManager.isSupportDoNotDisturbMode().then((data: boolean) => {console.info("supportDoNotDisturbMode success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`supportDoNotDisturbMode fail: ${JSON.stringify(err)}`);});    
```    
  
    
## setDistributedEnable    
设置设备是否支持分布式通知  
 **调用形式：**     
    
- setDistributedEnable(enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDistributedEnable(enable: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 是否支持。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设置设备是否支持分布式通知的回调函数。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600010 | Distributed operation failed. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
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
  
notificationManager.setDistributedEnable(enable, setDistributedEnableCallback)  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
let enable: boolean = true;  
notificationManager.setDistributedEnable(enable).then(() => {    console.info("setDistributedEnable success");}).catch((err: Base.BusinessError) => {    console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);});    
```    
  
    
## setDistributedEnableByBundle    
设置指定应用是否支持分布式通知  
 **调用形式：**     
    
- setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDistributedEnableByBundle(bundle: BundleOption, enable: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 应用的包信息。   |  
| enable | boolean | true | 是否支持。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 应用程序是否支持分布式通知的回调函数。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600010 | Distributed operation failed. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {    bundle: "bundleName1",};  
let enable: boolean = true;  
notificationManager.setDistributedEnableByBundle(bundle, enable).then(() => {    console.info("setDistributedEnableByBundle success");}).catch((err: Base.BusinessError) => {    console.error(`setDistributedEnableByBundle fail: ${JSON.stringify(err)}`);});    
```    
  
    
## isDistributedEnabledByBundle    
根据应用的包获取应用程序是否支持分布式通知  
 **调用形式：**     
    
- isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 查询指定应用是否支持分布式通知的回调函数。 |  
| Promise<boolean> | Promise方式返回指定应用是否支持分布式通知的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | 应用的包。 |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600010 | Distributed operation failed. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
let bundle: notificationManager.BundleOption = {    bundle: "bundleName1",};  
notificationManager.isDistributedEnabledByBundle(bundle).then((data: boolean) => {    console.info("isDistributedEnabledByBundle success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`isDistributedEnabledByBundle fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getDeviceRemindType    
获取通知的提醒方式  
 **调用形式：**     
    
- getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType>): void    
起始版本： 9    
- getDeviceRemindType(): Promise\<DeviceRemindType>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取通知提醒方式的回调函数。 |  
| Promise<DeviceRemindType> | Promise方式返回获取通知提醒方式的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
```null    
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
  
    
 **示例代码2：**   
示例Promise：  
  
```null    
import Base from '@ohos.base';  
notificationManager.getDeviceRemindType().then((data: notificationManager.DeviceRemindType) => {    console.info("getDeviceRemindType success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`getDeviceRemindType fail: ${JSON.stringify(err)}`);});    
```    
  
    
## setNotificationEnableSlot    
设置指定应用的指定渠道类型的使能状态  
 **调用形式：**     
    
- setNotificationEnableSlot(     bundle: BundleOption,     type: SlotType,     enable: boolean,     callback: AsyncCallback\<void>   ): void    
起始版本： 9    
- setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 应用的包信息。  |  
| type | SlotType | true | 指定渠道类型。 |  
| enable | boolean | true | 使能状态。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设置渠道使能回调函数。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
// setNotificationEnableSlotnotificationManager.setNotificationEnableSlot(    { bundle: "ohos.samples.notification", },    notificationManager.SlotType.SOCIAL_COMMUNICATION,    true).then(() => {        console.info("setNotificationEnableSlot success");    }).catch((err: Base.BusinessError) => {        console.error(`setNotificationEnableSlot fail: ${JSON.stringify(err)}`);    });    
```    
  
    
## isNotificationSlotEnabled    
获取指定应用的指定渠道类型的使能状态  
 **调用形式：**     
    
- isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle | BundleOption | true | 应用的包信息。 |  
| type | SlotType | true | 渠道类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取渠道使能状态回调函数。 |  
| Promise<boolean> | 以Promise形式返回指定类型的渠道使能状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 17700001 | The specified bundle name was not found. |  
    
 **示例代码1：**   
示例callback：  
  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
// isNotificationSlotEnablednotificationManager.isNotificationSlotEnabled({ bundle: "ohos.samples.notification", },    notificationManager.SlotType.SOCIAL_COMMUNICATION).then((data: boolean) => {    console.info("isNotificationSlotEnabled success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {    console.error(`isNotificationSlotEnabled fail: ${JSON.stringify(err)}`);});    
```    
  
    
## setSyncNotificationEnabledWithoutApp    
设置是否将通知同步到未安装应用程序的设备  
 **调用形式：**     
    
- setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId | number | true | 用户ID。 |  
| enable | boolean | true | 是否启用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设置是否将通知同步到未安装应用程序的设备的回调函数。 |  
| Promise<void> | 以Promise形式返回设置是否将通知同步到未安装应用程序的设备的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600008 | The user is not exist. |  
    
 **示例代码1：**   
示例callback：  
  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
let userId: number = 100;let enable: boolean = true;  
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable).then(() => {    console.info('setSyncNotificationEnabledWithoutApp success');}).catch((err: Base.BusinessError) => {    console.error(`setSyncNotificationEnabledWithoutApp fail: ${JSON.stringify(err)}`);});    
```    
  
    
## getSyncNotificationEnabledWithoutApp    
获取同步通知到未安装应用程序设备的开关是否开启  
 **调用形式：**     
    
- getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- getSyncNotificationEnabledWithoutApp(userId: number): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId | number | true | 用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取同步通知到未安装应用程序设备的开关是否开启的回调函数。 |  
| Promise<boolean> | 以Promise形式返回获取同步通知到未安装应用程序设备的开关是否开启的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
| 1600002 | Marshalling or unmarshalling error. |  
| 1600003 | Failed to connect service. |  
| 1600008 | The user is not exist. |  
    
 **示例代码1：**   
示例callback：  
  
  
  
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
  
    
 **示例代码2：**   
示例Promise：  
  
```ts    
import Base from '@ohos.base';  
let userId: number = 100;  
notificationManager.getSyncNotificationEnabledWithoutApp(userId).then((data: boolean) => {  console.info('getSyncNotificationEnabledWithoutApp, data:' + data);}).catch((err: Base.BusinessError) => {    console.error(`getSyncNotificationEnabledWithoutApp fail: ${JSON.stringify(err)}`);});    
```    
  
    
## on('checkNotification')<sup>(10+)</sup>    
注册通知监听回调。通知服务将通知信息回调给校验程序，校验程序返回校验结果决定该通知是否发布，如营销类通知发布频率控制等。  
 **调用形式：**     
    
- on(type: 'checkNotification', callback: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER and ohos.permission.NOTIFICATION_AGENT_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 回调函数类型名，固定为'checkNotification'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 消息验证函数指针。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
    
 **示例代码：**   
示例callback：  
  
  
```ts    
import Base from '@ohos.base';  
  
let OnCheckNotification = (info : notificationManager.NotificationCheckInfo): notificationManager.NotificationCheckResult => {  
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
    notificationManager.on("checkNotification", OnCheckNotification);  
} catch (error){  
    console.info(`notificationManager.on error: ${JSON.stringify(error as Base.BusinessError)}`);  
}  
    
```    
  
    
## off('checkNotification')<sup>(10+)</sup>    
取消通知监听回调。  
 **调用形式：**     
    
- off(     type: 'checkNotification',     callback?: (checkInfo: NotificationCheckInfo) => NotificationCheckResult   ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER and ohos.permission.NOTIFICATION_AGENT_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 回调函数类型名，固定为'checkNotification'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 消息验证函数指针，默认为空。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 1600001 | Internal error. |  
    
 **示例代码：**   
示例callback：  
  
  
```ts    
import Base from '@ohos.base';  
try{    notificationManager.off("checkNotification");} catch (error){    console.info(`notificationManager.off error: ${JSON.stringify(error as Base.BusinessError)}`);}    
```    
  
    
## NotificationCheckInfo<sup>(10+)</sup>  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName<sup>(10+)</sup> | string | false | true | bundle名称。 |  
| notificationId<sup>(10+)</sup> | number | false | true | 通知Id。 |  
| contentType<sup>(10+)</sup> | ContentType | false | true | 通知类型。 |  
    
## NotificationCheckResult<sup>(10+)</sup>  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER 和 ohos.permission.NOTIFICATION_AGENT_CONTROLLER    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| code<sup>(10+)</sup> | number | false | true | 0-display, 1-no display。 |  
| message<sup>(10+)</sup> | string | false | true | 结果信息。  |  
    
## DoNotDisturbType    
    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_NONE | 0 |  非通知勿扰类型。   |  
| TYPE_ONCE | 1 | 以设置时间段(只看小时和分钟)一次执行勿扰 |  
| TYPE_DAILY | 2 | 以设置时间段(只看小时和分钟)每天执行勿扰。 |  
| TYPE_CLEARLY | 3 | 以设置时间段(明确年月日时分)执行勿扰。  |  
    
## DoNotDisturbDate  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | DoNotDisturbType | false | true | 免打扰设置的时间类型。 |  
| begin | Date | false | true | 免打扰设置的起点时间。 |  
| end | Date | false | true |  免打扰设置的终点时间。  |  
    
## DeviceRemindType    
    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IDLE_DONOT_REMIND | 0 | 设备未被使用，无需提醒。   |  
| IDLE_REMIND | 1 | 提醒设备未被使用。      |  
| ACTIVE_DONOT_REMIND | 2 | 设备正在使用，无需提醒。 |  
| ACTIVE_REMIND | 3 | 提醒设备正在使用。 |  
    
## SourceType    
    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_NORMAL | 0 | 一般通知。  。 |  
| TYPE_CONTINUOUS | 1 | 连续通知。 |  
| TYPE_TIMER | 2 | 计划通知。  |  
