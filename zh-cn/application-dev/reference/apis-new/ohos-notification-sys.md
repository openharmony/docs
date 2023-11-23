# @ohos.notification    
本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知通道，订阅、取消订阅通知，获取通知的使能状态、角标使能状态，获取通知的相关信息等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import notification from '@ohos.notification'    
```  
    
## publish<sup>(deprecated)</sup>    
发布通知给指定的用户（callback形式）。  
 **调用形式：**     
- publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#publish。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | NotificationRequest | true | 用于设置要发布通知的内容和相关配置信息。 |  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 被指定的回调方法。  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import NotificationManager from '@ohos.notificationManager';  
import Base from '@ohos.base';  
  
// publish回调  
let publishCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.error(`publish failed, code is ${err.code}`);  
  } else {  
    console.info("publish success");  
  }  
}  
// 用户ID  
let userId: number = 1;  
// 通知Request对象  
let notificationRequest: NotificationManager.NotificationRequest = {  
  id: 1,  
  content: {  
    contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,  
    normal: {  
      title: "test_title",  
      text: "test_text",  
      additionalText: "test_additionalText"  
    }  
  }  
};  
Notification.publish(notificationRequest, userId, publishCallback);  
    
```    
  
    
## publish<sup>(deprecated)</sup>    
发布通知给指定的用户（Promise形式）。  
 **调用形式：**     
- publish(request: NotificationRequest, userId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#publish。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | NotificationRequest | true | 用于设置要发布通知的内容和相关配置信息。 |  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import NotificationManager from '@ohos.notificationManager';import Base from '@ohos.base';  
let notificationRequest: NotificationManager.NotificationRequest = {  id: 1,  content: {    contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,    normal: {      title: "test_title",      text: "test_text",      additionalText: "test_additionalText"    }  }};  
let userId: number = 1;  
Notification.publish(notificationRequest, userId).then(() => {  console.info("publish success");}).catch((err: Base.BusinessError) => {  console.error(`publish failed, code is ${err}`);});    
```    
  
    
## addSlot<sup>(deprecated)</sup>    
创建通知通道（callback形式）。  
 **调用形式：**     
- addSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#addSlot。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slot<sup>(deprecated)</sup> | NotificationSlot | true | 要创建的通知通道对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import NotificationManager from '@ohos.notificationManager';  
import Base from '@ohos.base';  
  
// addslot回调  
let addSlotCallBack = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("addSlot failed " + JSON.stringify(err));  
  } else {  
    console.info("addSlot success");  
  }  
}  
// 通知slot对象  
let notificationSlot: NotificationManager.NotificationSlot = {  
  type: Notification.SlotType.SOCIAL_COMMUNICATION  
};  
Notification.addSlot(notificationSlot, addSlotCallBack);  
    
```    
  
    
## addSlot<sup>(deprecated)</sup>    
创建通知通道（Promise形式）。  
 **调用形式：**     
- addSlot(slot: NotificationSlot): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#addSlot。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slot<sup>(deprecated)</sup> | NotificationSlot | true | 要创建的通知通道对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import NotificationManager from '@ohos.notificationManager';import Base from '@ohos.base';  
// 通知slot对象let notificationSlot: NotificationManager.NotificationSlot = {    type: Notification.SlotType.SOCIAL_COMMUNICATION};Notification.addSlot(notificationSlot).then(() => {console.info("addSlot success");}).catch((err: Base.BusinessError) => {  console.error(`addSlot failed, code is ${err}`);});    
```    
  
    
## addSlots<sup>(deprecated)</sup>    
创建多个通知通道（callback形式）。  
  
  
 **调用形式：**     
- addSlots(slots: Array\<NotificationSlot>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#addSlots。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slots<sup>(deprecated)</sup> | Array<NotificationSlot> | true | 要创建的通知通道对象数组。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import NotificationManager from '@ohos.notificationManager';  
import Base from '@ohos.base';  
  
// addSlots回调  
let addSlotsCallBack = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("addSlots failed " + JSON.stringify(err));  
  } else {  
    console.info("addSlots success");  
  }  
}  
// 通知slot对象  
let notificationSlot: NotificationManager.NotificationSlot = {  
  type: Notification.SlotType.SOCIAL_COMMUNICATION  
};  
// 通知slot array 对象  
let notificationSlotArray: NotificationManager.NotificationSlot[] = new Array();  
notificationSlotArray[0] = notificationSlot;  
  
Notification.addSlots(notificationSlotArray, addSlotsCallBack);  
    
```    
  
    
## addSlots<sup>(deprecated)</sup>    
创建多个通知通道（Promise形式）。  
 **调用形式：**     
- addSlots(slots: Array\<NotificationSlot>): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#addSlots。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slots<sup>(deprecated)</sup> | Array<NotificationSlot> | true | 要创建的通知通道对象数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import NotificationManager from '@ohos.notificationManager';import Base from '@ohos.base';  
// 通知slot对象let notificationSlot: NotificationManager.NotificationSlot = {  type: Notification.SlotType.SOCIAL_COMMUNICATION};// 通知slot array 对象let notificationSlotArray: NotificationManager.NotificationSlot[] = new Array();notificationSlotArray[0] = notificationSlot;  
Notification.addSlots(notificationSlotArray).then(() => {  console.info("addSlots success");}).catch((err: Base.BusinessError) => {  console.error(`addSlot failed, code is ${err}`);});    
```    
  
    
## subscribe<sup>(deprecated)</sup>    
订阅当前用户下所有应用的通知（callback形式）。  
 **调用形式：**     
- subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#subscribe。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber<sup>(deprecated)</sup> | NotificationSubscriber | true | 通知订阅对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 订阅动作回调函数。  |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
import NotificationSubscribe from '@ohos.notificationSubscribe';  
  
let subscribeCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("subscribe failed " + JSON.stringify(err));  
  } else {  
    console.info("subscribe success");  
  }  
}  
function onConsumeCallback(data: NotificationSubscribe.SubscribeCallbackData) {  
  console.info("Consume callback: " + JSON.stringify(data));  
}  
let subscriber: NotificationSubscribe.NotificationSubscriber = {  
  onConsume: onConsumeCallback  
};  
Notification.subscribe(subscriber, subscribeCallback);  
    
```    
  
    
## subscribe<sup>(deprecated)</sup>    
订阅通知并指定订阅信息。  
 **调用形式：**     
- subscribe(     subscriber: NotificationSubscriber,     info: NotificationSubscribeInfo,     callback: AsyncCallback\<void>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#subscribe。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber<sup>(deprecated)</sup> | NotificationSubscriber | true | 通知订阅对象。<br/> |  
| info<sup>(deprecated)</sup> | NotificationSubscribeInfo | true | 通知订阅信息。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 订阅动作回调函数。<br/> |  
    
 **示例代码：**   
示例（callback）  
```ts    
import Base from '@ohos.base';  
import NotificationSubscribe from '@ohos.notificationSubscribe';  
  
// subscribe回调  
let subscribeCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("subscribe failed " + JSON.stringify(err));  
  } else {  
    console.info("subscribe success");  
  }  
}  
let onConsumeCallback = (data: NotificationSubscribe.SubscribeCallbackData) => {  
  console.info("Consume callback: " + JSON.stringify(data));  
}  
let subscriber: NotificationSubscribe.NotificationSubscriber = {  
  onConsume: onConsumeCallback  
};  
let info: NotificationSubscribe.NotificationSubscribeInfo = {  
  bundleNames: ["bundleName1", "bundleName2"]  
};  
Notification.subscribe(subscriber, info, subscribeCallback);  
    
```    
  
    
## subscribe<sup>(deprecated)</sup>    
订阅通知并指定订阅信息（Promise形式）。  
 **调用形式：**     
- subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#subscribe。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber<sup>(deprecated)</sup> | NotificationSubscriber | true | 通知订阅对象。 |  
| info<sup>(deprecated)</sup> | NotificationSubscribeInfo | false | 通知订阅信息，默认为空。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';import NotificationSubscribe from '@ohos.notificationSubscribe';  
function onConsumeCallback(data: NotificationSubscribe.SubscribeCallbackData) {  console.info("Consume callback: " + JSON.stringify(data));}let subscriber: NotificationSubscribe.NotificationSubscriber = {  onConsume: onConsumeCallback};Notification.subscribe(subscriber).then(() => {  console.info("subscribe success");}).catch((err: Base.BusinessError) => {  console.error(`subscribe failed, code is ${err}`);});    
```    
  
    
## unsubscribe<sup>(deprecated)</sup>    
取消订阅（callbcak形式）。  
 **调用形式：**     
- unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#unsubscribe。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber<sup>(deprecated)</sup> | NotificationSubscriber | true | 通知订阅对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 取消订阅动作回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
import NotificationSubscribe from '@ohos.notificationSubscribe';  
  
let unsubscribeCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("unsubscribe failed " + JSON.stringify(err));  
  } else {  
    console.info("unsubscribe success");  
  }  
}  
let onDisconnectCallback = () => {  
  console.info("subscribe disconnect");  
}  
let subscriber: NotificationSubscribe.NotificationSubscriber = {  
  onDisconnect: onDisconnectCallback  
};  
Notification.unsubscribe(subscriber, unsubscribeCallback);  
    
```    
  
    
## unsubscribe<sup>(deprecated)</sup>    
取消订阅（Promise形式）。  
 **调用形式：**     
- unsubscribe(subscriber: NotificationSubscriber): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#unsubscribe。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber<sup>(deprecated)</sup> | NotificationSubscriber | true | 通知订阅对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';import NotificationSubscribe from '@ohos.notificationSubscribe';  
function onDisconnectCallback() {  console.info("subscribe disconnect");}let subscriber: NotificationSubscribe.NotificationSubscriber = {  onDisconnect: onDisconnectCallback};Notification.unsubscribe(subscriber).then(() => {  console.info("unsubscribe success");}).catch((err: Base.BusinessError) => {  console.error(`unsubscribe failed, code is ${err}`);});    
```    
  
    
## enableNotification<sup>(deprecated)</sup>    
设定指定应用的通知使能状态（Callback形式）。  
 **调用形式：**     
- enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setNotificationEnable。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。  |  
| enable<sup>(deprecated)</sup> | boolean | true | 使能状态。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 设定通知使能回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let enableNotificationCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("enableNotification failed " + JSON.stringify(err));  
  } else {  
    console.info("enableNotification success");  
  }  
}  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
Notification.enableNotification(bundle, false, enableNotificationCallback);  
    
```    
  
    
## enableNotification<sup>(deprecated)</sup>    
设定指定应用的通知使能状态（Promise形式）。  
 **调用形式：**     
- enableNotification(bundle: BundleOption, enable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setNotificationEnable。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
| enable<sup>(deprecated)</sup> | boolean | true | 使能状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};Notification.enableNotification(bundle, false).then(() => {  console.info("enableNotification success");}).catch((err: Base.BusinessError) => {  console.error(`enableNotification failed, code is ${err}`);});    
```    
  
    
## isNotificationEnabled<sup>(deprecated)</sup>    
获取指定应用的通知使能状态（Callback形式）。  
 **调用形式：**     
- isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isNotificationEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 获取通知使能状态回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean) => {  
  if (err) {  
    console.info("isNotificationEnabled failed " + JSON.stringify(err));  
  } else {  
    console.info("isNotificationEnabled success");  
  }  
}  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
Notification.isNotificationEnabled(bundle, isNotificationEnabledCallback);  
    
```    
  
    
## isNotificationEnabled<sup>(deprecated)</sup>    
获取指定应用的通知使能状态（Promise形式）。  
 **调用形式：**     
- isNotificationEnabled(bundle: BundleOption): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isNotificationEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回获取指定应用的通知使能状态的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};Notification.isNotificationEnabled(bundle).then((data) => {  console.info("isNotificationEnabled success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`isNotificationEnabled failed, code is ${err}`);});    
```    
  
    
## isNotificationEnabled<sup>(deprecated)</sup>    
获取通知使能状态（Callback形式）。  
 **调用形式：**     
- isNotificationEnabled(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isNotificationEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 获取通知使能状态回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean) => {  
  if (err) {  
    console.info("isNotificationEnabled failed " + JSON.stringify(err));  
  } else {  
    console.info("isNotificationEnabled success");  
  }  
}  
  
Notification.isNotificationEnabled(isNotificationEnabledCallback);  
    
```    
  
    
## isNotificationEnabled<sup>(deprecated)</sup>    
获取通知使能状态（Promise形式）。  
 **调用形式：**     
- isNotificationEnabled(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isNotificationEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回获取指定应用的通知使能状态的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.isNotificationEnabled().then((data: boolean) => {  console.info("isNotificationEnabled success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`isNotificationEnabled failed, code is ${err}`);});    
```    
  
    
## isNotificationEnabled<sup>(deprecated)</sup>  
 **调用形式：**     
- isNotificationEnabled(userId: number, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isNotificationEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true |  |  
    
## isNotificationEnabled<sup>(deprecated)</sup>  
 **调用形式：**     
- isNotificationEnabled(userId: number): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isNotificationEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> |  |  
    
## displayBadge<sup>(deprecated)</sup>    
设定指定应用的角标使能状态（Callback形式）。  
 **调用形式：**     
- displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#displayBadge。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true |  指定应用的包信息。 |  
| enable<sup>(deprecated)</sup> | boolean | true | 使能状态。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 设定角标使能回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let displayBadgeCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("displayBadge failed " + JSON.stringify(err));  
  } else {  
    console.info("displayBadge success");  
  }  
}  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
Notification.displayBadge(bundle, false, displayBadgeCallback);  
    
```    
  
    
## displayBadge<sup>(deprecated)</sup>    
设定指定应用的角标使能状态（Promise形式）。  
 **调用形式：**     
- displayBadge(bundle: BundleOption, enable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#displayBadge。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true |  指定应用的包信息。 |  
| enable<sup>(deprecated)</sup> | boolean | true | 使能状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};Notification.displayBadge(bundle, false).then(() => {  console.info("displayBadge success");}).catch((err: Base.BusinessError) => {  console.error(`displayBadge failed, code is ${err}`);});    
```    
  
    
## isBadgeDisplayed<sup>(deprecated)</sup>    
获取指定应用的角标使能状态（Callback形式）。  
 **调用形式：**     
- isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isBadgeDisplayed。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 获取角标使能状态回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let isBadgeDisplayedCallback = (err: Base.BusinessError, data: boolean) => {  
  if (err) {  
    console.info("isBadgeDisplayed failed " + JSON.stringify(err));  
  } else {  
    console.info("isBadgeDisplayed success");  
  }  
}  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
Notification.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);  
    
```    
  
    
## isBadgeDisplayed<sup>(deprecated)</sup>    
获取指定应用的角标使能状态（Promise形式）。  
 **调用形式：**     
- isBadgeDisplayed(bundle: BundleOption): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isBadgeDisplayed。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回获取指定应用的角标使能状态。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};Notification.isBadgeDisplayed(bundle).then((data) => {  console.info("isBadgeDisplayed success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`isBadgeDisplayed failed, code is ${err}`);});    
```    
  
    
## setSlotByBundle<sup>(deprecated)</sup>    
设定指定应用的通知通道（Callback形式）。  
 **调用形式：**     
- setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setSlotByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
| slot<sup>(deprecated)</sup> | NotificationSlot | true | 通知通道。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 设定通知通道回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
import NotificationManager from '@ohos.notificationManager';  
  
let setSlotByBundleCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("setSlotByBundle failed " + JSON.stringify(err));  
  } else {  
    console.info("setSlotByBundle success");  
  }  
}  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
let notificationSlot: NotificationManager.NotificationSlot = {  
  type: Notification.SlotType.SOCIAL_COMMUNICATION  
};  
Notification.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);  
    
```    
  
    
## setSlotByBundle<sup>(deprecated)</sup>    
设定指定应用的通知通道（Promise形式）。  
 **调用形式：**     
- setSlotByBundle(bundle: BundleOption, slot: NotificationSlot): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setSlotByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
| slot<sup>(deprecated)</sup> | NotificationSlot | true | 通知通道。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';import NotificationManager from '@ohos.notificationManager';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};let notificationSlot: NotificationManager.NotificationSlot = {  type: Notification.SlotType.SOCIAL_COMMUNICATION};Notification.setSlotByBundle(bundle, notificationSlot).then(() => {  console.info("setSlotByBundle success");}).catch((err: Base.BusinessError) => {  console.error(`setSlotByBundle failed, code is ${err}`);});    
```    
  
    
## getSlotsByBundle<sup>(deprecated)</sup>    
获取指定应用的所有通知通道（Callback形式）。  
 **调用形式：**     
- getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback\<Array\<NotificationSlot>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getSlotsByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<NotificationSlot>> | true | 获取通知通道回调函数。  |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
import NotificationManager from '@ohos.notificationManager';  
  
let getSlotsByBundleCallback = (err: Base.BusinessError, data: NotificationManager.NotificationSlot[]) => {  
  if (err) {  
    console.info("getSlotsByBundle failed " + JSON.stringify(err));  
  } else {  
    console.info("getSlotsByBundle success");  
  }  
}  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
Notification.getSlotsByBundle(bundle, getSlotsByBundleCallback);  
    
```    
  
    
## getSlotsByBundle<sup>(deprecated)</sup>    
获取指定应用的所有通知通道（Promise形式）。  
 **调用形式：**     
- getSlotsByBundle(bundle: BundleOption): Promise\<Array\<NotificationSlot>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getSlotsByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<NotificationSlot>> | 以Promise形式返回获取指定应用的通知通道。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';import NotificationManager from '@ohos.notificationManager';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};Notification.getSlotsByBundle(bundle).then((data: NotificationManager.NotificationSlot[]) => {  console.info("getSlotsByBundle success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getSlotsByBundle failed, code is ${err}`);});    
```    
  
    
## getSlotNumByBundle<sup>(deprecated)</sup>    
获取指定应用的通知通道数量（Callback形式）。  
 **调用形式：**     
- getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getSlotNumByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 获取通知通道数量回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
import NotificationManager from '@ohos.notificationManager';  
  
let getSlotNumByBundleCallback = (err: Base.BusinessError, data: number) => {  
  if (err) {  
    console.info("getSlotNumByBundle failed " + JSON.stringify(err));  
  } else {  
    console.info("getSlotNumByBundle success");  
  }  
}  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
Notification.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);  
    
```    
  
    
## getSlotNumByBundle<sup>(deprecated)</sup>    
获取指定应用的通知通道数量（Promise形式）。  
 **调用形式：**     
- getSlotNumByBundle(bundle: BundleOption): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getSlotNumByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 以Promise形式返回获取指定应用的通知通道数量。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';import NotificationManager from '@ohos.notificationManager';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};Notification.getSlotNumByBundle(bundle).then((data: number) => {  console.info("getSlotNumByBundle success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getSlotNumByBundle failed, code is ${err}`);});    
```    
  
    
## remove<sup>(deprecated)</sup>    
删除指定通知  
  
 **调用形式：**     
- remove(     bundle: BundleOption,     notificationKey: NotificationKey,     reason: RemoveReason,     callback: AsyncCallback\<void>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#remove。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。<br/> |  
| notificationKey<sup>(deprecated)</sup> | NotificationKey | true | 通知键值。<br/> |  
| reason<sup>(deprecated)</sup> | RemoveReason | true | 通知删除原因。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 删除指定通知回调函数。<br/> |  
    
## remove<sup>(deprecated)</sup>    
删除指定通知（Promise形式）。  
。  
 **调用形式：**     
- remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#remove。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。 |  
| notificationKey<sup>(deprecated)</sup> | NotificationKey | true | 通知键值。 |  
| reason<sup>(deprecated)</sup> | RemoveReason | true | 通知删除原因。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};let notificationKey: Notification.NotificationKey = {  id: 0,  label: "label",};let reason: Notification.RemoveReason = Notification.RemoveReason.CLICK_REASON_REMOVE;Notification.remove(bundle, notificationKey, reason).then(() => {  console.info("remove success");}).catch((err: Base.BusinessError) => {  console.error(`remove failed, code is ${err}`);});    
```    
  
    
## remove<sup>(deprecated)</sup>    
删除指定通知（Callback形式）。  
 **调用形式：**     
- remove(hashCode: string, reason: RemoveReason, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#remove。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hashCode<sup>(deprecated)</sup> | string | true | 通知唯一ID。可以通过[onConsume](js-apis-inner-notification-notificationSubscriber.md#onconsume)回调的入参[SubscribeCallbackData](#subscribecallbackdata)获取其内部[NotificationRequest](#notificationrequest)对象中的hashCode。  |  
| reason<sup>(deprecated)</sup> | RemoveReason | true | 通知删除原因。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 删除指定通知回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let hashCode: string = 'hashCode';  
  
let removeCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("remove failed " + JSON.stringify(err));  
  } else {  
    console.info("remove success");  
  }  
}  
let reason: Notification.RemoveReason = Notification.RemoveReason.CANCEL_REASON_REMOVE;  
Notification.remove(hashCode, reason, removeCallback);  
    
```    
  
    
## remove<sup>(deprecated)</sup>    
删除指定通知（Promise形式）。  
 **调用形式：**     
- remove(hashCode: string, reason: RemoveReason): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#remove。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hashCode<sup>(deprecated)</sup> | string | true |  通知唯一ID。 |  
| reason<sup>(deprecated)</sup> | RemoveReason | true | 通知删除原因。      |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import Base from '@ohos.base';  
let hashCode: string = 'hashCode';let reason: Notification.RemoveReason = Notification.RemoveReason.CLICK_REASON_REMOVE;Notification.remove(hashCode, reason).then(() => {  console.info("remove success");}).catch((err: Base.BusinessError) => {  console.error(`remove failed, code is ${err}`);});    
```    
  
    
## removeAll<sup>(deprecated)</sup>    
删除指定应用的所有通知（Callback形式）。  
 **调用形式：**     
- removeAll(bundle: BundleOption, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#removeAll。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 指定应用的包信息。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  删除指定应用的所有通知回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let removeAllCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("removeAll failed " + JSON.stringify(err));  
  } else {  
    console.info("removeAll success");  
  }  
}  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
Notification.removeAll(bundle, removeAllCallback);  
    
```    
  
    
## removeAll<sup>(deprecated)</sup>    
删除所有通知（Callback形式）。  
 **调用形式：**     
- removeAll(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#removeAll。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 删除所有通知回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import Base from '@ohos.base';  
  
let removeAllCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("removeAll failed " + JSON.stringify(err));  
  } else {  
    console.info("removeAll success");  
  }  
}  
  
Notification.removeAll(removeAllCallback);  
    
```    
  
    
## removeAll<sup>(deprecated)</sup>    
删除指定用户下的所有通知（callback形式）。  
。  
 **调用形式：**     
- removeAll(userId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#removeAll。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 删除指定用户所有通知回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import Base from '@ohos.base';  
  
function removeAllCallback(err: Base.BusinessError) {  
  if (err) {  
    console.info("removeAll failed " + JSON.stringify(err));  
  } else {  
    console.info("removeAll success");  
  }  
}  
  
let userId: number = 1;  
Notification.removeAll(userId, removeAllCallback);  
    
```    
  
    
## removeAll<sup>(deprecated)</sup>    
删除指定用户下的所有通知（Promise形式）。  
。  
 **调用形式：**     
- removeAll(userId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#removeAll。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import Base from '@ohos.base';  
let userId: number = 1;Notification.removeAll(userId).then(() => {  console.info("removeAll success");}).catch((err: Base.BusinessError) => {  console.error(`removeAll failed, code is ${err}`);});    
```    
  
    
## removeAll<sup>(deprecated)</sup>    
删除指定应用的所有通知（Promise形式）。  
 **调用形式：**     
- removeAll(bundle?: BundleOption): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationSubscribe/notificationSubscribe#removeAll。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | false | 指定应用的包信息。默认为空，表示删除所有通知。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import Base from '@ohos.base';  
// 不指定应用时，删除所有通知Notification.removeAll().then(() => {  console.info("removeAll success");}).catch((err: Base.BusinessError) => {  console.error(`removeAll failed, code is ${err}`);});    
```    
  
    
## getAllActiveNotifications<sup>(deprecated)</sup>    
获取当前未删除的所有通知（Callback形式）。  
 **调用形式：**     
- getAllActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getAllActiveNotifications。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<NotificationRequest>> | true | 获取活动通知回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
import NotificationManager from '@ohos.notificationManager';  
  
function getAllActiveNotificationsCallback(err: Base.BusinessError, data: NotificationManager.NotificationRequest[]) {  
  if (err) {  
    console.info("getAllActiveNotifications failed " + JSON.stringify(err));  
  } else {  
    console.info("getAllActiveNotifications success");  
  }  
}  
  
Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);  
    
```    
  
    
## getAllActiveNotifications<sup>(deprecated)</sup>    
获取当前未删除的所有通知（Promise形式）。  
 **调用形式：**     
- getAllActiveNotifications(): Promise\<Array\<NotificationRequest>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getAllActiveNotifications。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<NotificationRequest>> | 以Promise形式返回获取活动通知。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';import NotificationManager from '@ohos.notificationManager';  
Notification.getAllActiveNotifications().then((data: NotificationManager.NotificationRequest[]) => {  console.info("getAllActiveNotifications success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getAllActiveNotifications failed, code is ${err}`);});    
```    
  
    
## removeGroupByBundle<sup>(deprecated)</sup>    
删除指定应用的指定组下的通知（Callback形式）。  
。  
 **调用形式：**     
- removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#removeGroupByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 应用的包信息。 |  
| groupName<sup>(deprecated)</sup> | string | true | 通知组名称。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 删除指定应用指定组下通知的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let removeGroupByBundleCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("removeGroupByBundle failed " + JSON.stringify(err));  
  } else {  
    console.info("removeGroupByBundle success");  
  }  
}  
  
let bundleOption: Notification.BundleOption = {bundle: "Bundle"};  
let groupName: string = "GroupName";  
    
```    
  
    
## removeGroupByBundle<sup>(deprecated)</sup>    
删除指定应用的指定组下的通知（Promise形式）。  
 **调用形式：**     
- removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#removeGroupByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true |  应用的包信息。  |  
| groupName<sup>(deprecated)</sup> | string | true | 通知组名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let bundleOption: Notification.BundleOption = {bundle: "Bundle"};let groupName: string = "GroupName";Notification.removeGroupByBundle(bundleOption, groupName).then(() => {  console.info("removeGroupByBundle success");}).catch((err: Base.BusinessError) => {  console.error(`removeGroupByBundle failed, code is ${err}`);});    
```    
  
    
## setDoNotDisturbDate<sup>(deprecated)</sup>    
设置免打扰时间（Callback形式）。  
 **调用形式：**     
- setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setDoNotDisturbDate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date<sup>(deprecated)</sup> | DoNotDisturbDate | true | 免打扰时间选项。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 设置免打扰时间回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let setDoNotDisturbDateCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("setDoNotDisturbDate failed " + JSON.stringify(err));  
  } else {  
    console.info("setDoNotDisturbDate success");  
  }  
}  
  
let doNotDisturbDate: Notification.DoNotDisturbDate = {  
  type: Notification.DoNotDisturbType.TYPE_ONCE,  
  begin: new Date(),  
  end: new Date(2021, 11, 15, 18, 0)  
};  
  
Notification.setDoNotDisturbDate(doNotDisturbDate, setDoNotDisturbDateCallback);  
    
```    
  
    
## setDoNotDisturbDate<sup>(deprecated)</sup>    
设置免打扰时间（Promise形式）。  
 **调用形式：**     
- setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setDoNotDisturbDate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date<sup>(deprecated)</sup> | DoNotDisturbDate | true | 免打扰时间选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let doNotDisturbDate: Notification.DoNotDisturbDate = {    type: Notification.DoNotDisturbType.TYPE_ONCE,    begin: new Date(),    end: new Date(2021, 11, 15, 18, 0)};Notification.setDoNotDisturbDate(doNotDisturbDate).then(() => {console.info("setDoNotDisturbDate success");}).catch((err: Base.BusinessError) => {  console.error(`setDoNotDisturbDate failed, code is ${err}`);});    
```    
  
    
## setDoNotDisturbDate<sup>(deprecated)</sup>    
指定用户设置免打扰时间（Callback形式）。  
 **调用形式：**     
- setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setDoNotDisturbDate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date<sup>(deprecated)</sup> | DoNotDisturbDate | true | 免打扰时间选项。  |  
| userId<sup>(deprecated)</sup> | number | true | 设置免打扰时间的用户ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 设置免打扰时间回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let setDoNotDisturbDateCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("setDoNotDisturbDate failed " + JSON.stringify(err));  
  } else {  
    console.info("setDoNotDisturbDate success");  
  }  
}  
  
let doNotDisturbDate: Notification.DoNotDisturbDate = {  
  type: Notification.DoNotDisturbType.TYPE_ONCE,  
  begin: new Date(),  
  end: new Date(2021, 11, 15, 18, 0)  
};  
  
let userId: number = 1;  
Notification.setDoNotDisturbDate(doNotDisturbDate, userId, setDoNotDisturbDateCallback);  
    
```    
  
    
## setDoNotDisturbDate<sup>(deprecated)</sup>    
指定用户设置免打扰时间（Promise形式）。  
 **调用形式：**     
- setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setDoNotDisturbDate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date<sup>(deprecated)</sup> | DoNotDisturbDate | true | 免打扰时间选项。 |  
| userId<sup>(deprecated)</sup> | number | true | 设置免打扰时间的用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let doNotDisturbDate: Notification.DoNotDisturbDate = {  type: Notification.DoNotDisturbType.TYPE_ONCE,  begin: new Date(),  end: new Date(2021, 11, 15, 18, 0)};  
let userId: number = 1;  
Notification.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {  console.info("setDoNotDisturbDate success");}).catch((err: Base.BusinessError) => {  console.error(`setDoNotDisturbDate failed, code is ${err}`);});    
```    
  
    
## getDoNotDisturbDate<sup>(deprecated)</sup>    
查询免打扰时间（Callback形式）。  
 **调用形式：**     
- getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getDoNotDisturbDate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<DoNotDisturbDate> | true | 查询免打扰时间回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: Notification.DoNotDisturbDate) => {  
  if (err) {  
    console.info("getDoNotDisturbDate failed " + JSON.stringify(err));  
  } else {  
    console.info("getDoNotDisturbDate success");  
  }  
}  
  
Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);  
    
```    
  
    
## getDoNotDisturbDate<sup>(deprecated)</sup>    
查询免打扰时间（Promise形式）。  
 **调用形式：**     
- getDoNotDisturbDate(): Promise\<DoNotDisturbDate>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getDoNotDisturbDate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<DoNotDisturbDate> | 以Promise形式返回获取查询到的免打扰时间。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.getDoNotDisturbDate().then((data: Notification.DoNotDisturbDate) => {  console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getDoNotDisturbDate failed, code is ${err}`);});    
```    
  
    
## getDoNotDisturbDate<sup>(deprecated)</sup>    
查询指定用户的免打扰时间（Callback形式）。  
 **调用形式：**     
- getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getDoNotDisturbDate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<DoNotDisturbDate> | true |  查询免打扰时间回调函数 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: Notification.DoNotDisturbDate) => {  
  if (err) {  
    console.info("getDoNotDisturbDate failed " + JSON.stringify(err));  
  } else {  
    console.info("getDoNotDisturbDate success");  
  }  
}  
  
let userId: number = 1;  
  
Notification.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);  
    
```    
  
    
## getDoNotDisturbDate<sup>(deprecated)</sup>    
查询指定用户的免打扰时间（Promise形式）。  
 **调用形式：**     
- getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getDoNotDisturbDate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<DoNotDisturbDate> | 以Promise形式返回获取查询到的免打扰时间。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let userId: number = 1;  
Notification.getDoNotDisturbDate(userId).then((data: Notification.DoNotDisturbDate) => {  console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getDoNotDisturbDate failed, code is ${err}`);});    
```    
  
    
## supportDoNotDisturbMode<sup>(deprecated)</sup>    
查询是否支持免打扰功能（Callback形式）。  
 **调用形式：**     
- supportDoNotDisturbMode(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isSupportDoNotDisturbMode。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 查询是否支持免打扰功能回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let supportDoNotDisturbModeCallback = (err: Base.BusinessError, data: boolean) => {  
  if (err) {  
    console.info("supportDoNotDisturbMode failed " + JSON.stringify(err));  
  } else {  
    console.info("supportDoNotDisturbMode success");  
  }  
}  
  
Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);  
    
```    
  
    
## supportDoNotDisturbMode<sup>(deprecated)</sup>    
查询是否支持免打扰功能（Promise形式）。  
 **调用形式：**     
- supportDoNotDisturbMode(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isSupportDoNotDisturbMode。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回获取是否支持免打扰功能的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.supportDoNotDisturbMode().then((data: boolean) => {  console.info("supportDoNotDisturbMode success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`supportDoNotDisturbMode failed, code is ${err}`);});    
```    
  
    
## enableDistributed<sup>(deprecated)</sup>    
设置设备是否支持分布式通知（Callback形式）。  
 **调用形式：**     
- enableDistributed(enable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setDistributedEnable。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable<sup>(deprecated)</sup> | boolean | true | 是否支持。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 设置设备是否支持分布式通知的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let enabledNotificationCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("enableDistributed failed " + JSON.stringify(err));  
  } else {  
    console.info("enableDistributed success");  
  }  
};  
    
```    
  
    
## enableDistributed<sup>(deprecated)</sup>    
设置设备是否支持分布式通知（Promise形式）。  
 **调用形式：**     
- enableDistributed(enable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setDistributedEnable。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable<sup>(deprecated)</sup> | boolean | true | 是否支持。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let enable: boolean = true;Notification.enableDistributed(enable).then(() => {  console.info("enableDistributed success");}).catch((err: Base.BusinessError) => {  console.error(`enableDistributed failed, code is ${err}`);});    
```    
  
    
## enableDistributedByBundle<sup>(deprecated)</sup>    
设置指定应用是否支持分布式通知（Callback形式）。  
 **调用形式：**     
- enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setDistributedEnableByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 应用的包信息。 |  
| enable<sup>(deprecated)</sup> | boolean | true | 是否支持。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 应用程序是否支持分布式通知的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let enableDistributedByBundleCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("enableDistributedByBundle failed " + JSON.stringify(err));  
  } else {  
    console.info("enableDistributedByBundle success");  
  }  
};  
  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
  
let enable: boolean = true;  
  
Notification.enableDistributedByBundle(bundle, enable, enableDistributedByBundleCallback);  
    
```    
  
    
## enableDistributedByBundle<sup>(deprecated)</sup>    
设置指定应用是否支持分布式通知（Promise形式）。  
。  
 **调用形式：**     
- enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#setDistributedEnableByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true |  应用的包。 |  
| enable<sup>(deprecated)</sup> | boolean | true | 是否支持。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let enable: boolean = true;  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};  
Notification.enableDistributedByBundle(bundle, enable).then(() => {  console.info("enableDistributedByBundle success");}).catch((err: Base.BusinessError) => {  console.error(`enableDistributedByBundle failed, code is ${err}`);});    
```    
  
    
## isDistributedEnabledByBundle<sup>(deprecated)</sup>    
根据应用的包获取应用程序是否支持分布式通知（Callback形式）。  
 **调用形式：**     
- isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isDistributedEnabledByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 应用的包。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 查询指定应用是否支持分布式通知的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let isDistributedEnabledByBundleCallback = (err: Base.BusinessError, data: boolean) => {  
  if (err) {  
    console.info("isDistributedEnabledByBundle failed " + JSON.stringify(err));  
  } else {  
    console.info("isDistributedEnabledByBundle success" + JSON.stringify(data));  
  }  
};  
  
let bundle: Notification.BundleOption = {  
  bundle: "bundleName1",  
};  
  
Notification.isDistributedEnabledByBundle(bundle, isDistributedEnabledByBundleCallbac  
    
```    
  
    
## isDistributedEnabledByBundle<sup>(deprecated)</sup>    
查询指定应用是否支持分布式通知（Promise形式）。  
 **调用形式：**     
- isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isDistributedEnabledByBundle。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | BundleOption | true | 应用的包。               |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise方式返回指定应用是否支持分布式通知的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let bundle: Notification.BundleOption = {  bundle: "bundleName1",};  
Notification.isDistributedEnabledByBundle(bundle).then((data: boolean) => {  console.info("isDistributedEnabledByBundle success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`isDistributedEnabledByBundle failed, code is ${err}`);});    
```    
  
    
## getDeviceRemindType<sup>(deprecated)</sup>    
获取通知的提醒方式（Callback形式）。  
 **调用形式：**     
- getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getDeviceRemindType。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<DeviceRemindType> | true | 获取通知提醒方式的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let getDeviceRemindTypeCallback = (err: Base.BusinessError, data: Notification.DeviceRemindType) => {  
  if (err) {  
    console.info("getDeviceRemindType failed " + JSON.stringify(err));  
  } else {  
    console.info("getDeviceRemindType success");  
  }  
};  
  
Notification.getDeviceRemindType(getDeviceRemindTypeCallback);  
    
```    
  
    
## getDeviceRemindType<sup>(deprecated)</sup>    
获取通知的提醒方式（Promise形式）。  
 **调用形式：**     
- getDeviceRemindType(): Promise\<DeviceRemindType>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getDeviceRemindType。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification  
 **需要权限：** ohos.permission.NOTIFICATION_CONTROLLER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<DeviceRemindType> | Promise方式返回获取通知提醒方式的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.getDeviceRemindType().then((data: Notification.DeviceRemindType) => {  console.info("getDeviceRemindType success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getDeviceRemindType failed, code is ${err}`);});    
```    
  
    
## DoNotDisturbType<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#DoNotDisturbType替代。    
    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_NONE<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DoNotDisturbType#TYPE_NONE替代。<br> 非通知勿扰类型。 |  
| TYPE_ONCE<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DoNotDisturbType#TYPE_ONCE替代。<br>以设置时间段(只看小时和分钟)一次执行勿扰。 |  
| TYPE_DAILY<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DoNotDisturbType#TYPE_DAILY替代。<br>以设置时间段(只看小时和分钟)每天执行勿扰。 |  
| TYPE_CLEARLY<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DoNotDisturbType#TYPE_CLEARLY替代。<br>以设置时间段(明确年月日时分)执行勿扰。 |  
    
## DoNotDisturbDate<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#DoNotDisturbDate替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | DoNotDisturbType | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DoNotDisturbDate#type替代。<br>免打扰设置的时间类型。 |  
| begin<sup>(deprecated)</sup> | Date | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DoNotDisturbDate#begin替代。<br>免打扰设置的起点时间。 |  
| end<sup>(deprecated)</sup> | Date | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DoNotDisturbDate#end替代。<br>免打扰设置的终点时间。 |  
    
## DeviceRemindType<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#DeviceRemindType替代。    
    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IDLE_DONOT_REMIND<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DeviceRemindType#IDLE_DONOT_REMIND替代。<br>设备未被使用，无需提醒。   |  
| IDLE_REMIND<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DeviceRemindType#IDLE_REMIND替代。<br>提醒设备未被使用。 |  
| ACTIVE_DONOT_REMIND<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DeviceRemindType#ACTIVE_DONOT_REMIND替代。<br>设备正在使用，无需提醒。 。 |  
| ACTIVE_REMIND<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.DeviceRemindType#ACTIVE_REMIND替代。<br>提醒设备正在使用。 |  
    
## SourceType<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#SourceType替代。    
    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_NORMAL<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SourceType#TYPE_NORMAL替代。<br>一般通知。   |  
| TYPE_CONTINUOUS<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SourceType#TYPE_CONTINUOUS替代。<br>连续通知。   |  
| TYPE_TIMER<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SourceType#TYPE_TIMER替代。<br>计划通知。 |  
    
## RemoveReason<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationSubscribe/notificationSubscribe#RemoveReason替代。    
    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CLICK_REASON_REMOVE<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationSubscribe/notificationSubscribe.RemoveReason#CLICK_REASON_REMOVE替代。<br>点击通知后删除通知。 |  
| CANCEL_REASON_REMOVE<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationSubscribe/notificationSubscribe.RemoveReason#CANCEL_REASON_REMOVE替代。<br>用户删除通知。  |  
