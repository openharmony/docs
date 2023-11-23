# @ohos.notification    
本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知通道，订阅、取消订阅通知，获取通知的使能状态、角标使能状态，获取通知的相关信息等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import notification from '@ohos.notification'    
```  
    
## publish<sup>(deprecated)</sup>    
发布通知（callback形式）。  
 **调用形式：**     
- publish(request: NotificationRequest, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#publish。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | NotificationRequest | true | 用于设置要发布通知的内容和相关配置信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 发布通知的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import NotificationManager from '@ohos.notificationManager';  
import Base from '@ohos.base';  
  
// publish回调  
let publishCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.error(`publish failed, code is ${err}`);  
  } else {  
    console.info("publish success");  
  }  
}  
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
Notification.publish(notificationRequest, publishCallback);  
    
```    
  
    
## publish<sup>(deprecated)</sup>    
发布通知（Promise形式）。  
 **调用形式：**     
- publish(request: NotificationRequest): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#publish。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | NotificationRequest | true | 用于设置要发布通知的内容和相关配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import NotificationManager from '@ohos.notificationManager';import Base from '@ohos.base';  
// 通知Request对象let notificationRequest: NotificationManager.NotificationRequest = {  id: 1,  content: {    contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,    normal: {      title: "test_title",      text: "test_text",      additionalText: "test_additionalText"    }  }};Notification.publish(notificationRequest).then(() => {  console.info("publish success");}).catch((err: Base.BusinessError) => {  console.error(`publish failed, code is ${err}`);});    
```    
  
    
## cancel<sup>(deprecated)</sup>    
取消与指定通知ID相匹配的已发布通知（callback形式）。  
 **调用形式：**     
- cancel(id: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#cancel。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 通知ID。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import Base from '@ohos.base';  
  
// cancel回调  
let cancelCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("cancel failed " + JSON.stringify(err));  
  } else {  
    console.info("cancel success");  
  }  
}  
Notification.cancel(0, cancelCallback);  
    
```    
  
    
## cancel<sup>(deprecated)</sup>    
通过通知ID和通知标签取消已发布的通知（callback形式）。  
 **调用形式：**     
- cancel(id: number, label: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#cancel。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 通知ID。 |  
| label<sup>(deprecated)</sup> | string | true | 通知标签。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import Base from '@ohos.base';  
  
// cancel回调  
let cancelCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("cancel failed " + JSON.stringify(err));  
  } else {  
    console.info("cancel success");  
  }  
}  
Notification.cancel(0, "label", cancelCallback);  
    
```    
  
    
## cancel<sup>(deprecated)</sup>    
取消与指定通知ID相匹配的已发布通知，label可以指定也可以不指定（Promise形式）。  
 **调用形式：**     
- cancel(id: number, label?: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#cancel。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 通知ID。 |  
| label<sup>(deprecated)</sup> | string | false | 通知标签，默认为空。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import Base from '@ohos.base';  
Notification.cancel(0).then(() => {console.info("cancel success");}).catch((err: Base.BusinessError) => {  console.error(`cancel failed, code is ${err}`);});    
```    
  
    
## cancelAll<sup>(deprecated)</sup>    
取消所有已发布的通知（callback形式）。  
 **调用形式：**     
- cancelAll(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#cancelAll。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import Base from '@ohos.base';  
  
// cancel回调  
let cancelAllCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("cancelAll failed " + JSON.stringify(err));  
  } else {  
    console.info("cancelAll success");  
  }  
}  
Notification.cancelAll(cancelAllCallback);  
    
```    
  
    
## cancelAll<sup>(deprecated)</sup>    
取消所有已发布的通知（Promise形式）。  
 **调用形式：**     
- cancelAll(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#cancelAll。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import Base from '@ohos.base';  
Notification.cancelAll().then(() => {console.info("cancelAll success");}).catch((err: Base.BusinessError) => {  console.error(`cancelAll failed, code is ${err}`);});    
```    
  
    
## addSlot<sup>(deprecated)</sup>    
创建指定类型的通知通道（callback形式）。  
 **调用形式：**     
- addSlot(type: SlotType, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#addSlot。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SlotType | true | 要创建的通知通道的类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import Base from '@ohos.base';  
  
// addslot回调  
let addSlotCallBack = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("addSlot failed " + JSON.stringify(err));  
  } else {  
    console.info("addSlot success");  
  }  
}  
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack);  
    
```    
  
    
## addSlot<sup>(deprecated)</sup>    
创建指定类型的通知通道（Promise形式）。  
 **调用形式：**     
- addSlot(type: SlotType): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#addSlot。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SlotType | true | 要创建的通知通道的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import Base from '@ohos.base';  
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION).then(() => {  console.info("addSlot success");}).catch((err: Base.BusinessError) => {  console.error(`addSlot failed, code is ${err}`);});    
```    
  
    
## getSlot<sup>(deprecated)</sup>    
获取一个指定类型的通知通道（callback形式）。  
 **调用形式：**     
- getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getSlot。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType<sup>(deprecated)</sup> | SlotType | true | 通知渠道类型，目前分为社交通信、服务提醒、内容咨询和其他类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<NotificationSlot> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）  
```ts    
import Base from '@ohos.base';  
  
// getSlot回调  
let getSlotCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("getSlot failed " + JSON.stringify(err));  
  } else {  
    console.info("getSlot success");  
  }  
}  
let slotType: Notification.SlotType = Notification.SlotType.SOCIAL_COMMUNICATION;  
Notification.getSlot(slotType, getSlotCallback);  
    
```    
  
    
## getSlot<sup>(deprecated)</sup>    
获取一个指定类型的通知通道（Promise形式）。  
 **调用形式：**     
- getSlot(slotType: SlotType): Promise\<NotificationSlot>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getSlot。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType<sup>(deprecated)</sup> | SlotType | true |  通知渠道类型，目前分为社交通信、服务提醒、内容咨询和其他类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<NotificationSlot> | 以Promise形式返回获取一个通知通道。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import Base from '@ohos.base';  
let slotType: Notification.SlotType = Notification.SlotType.SOCIAL_COMMUNICATION;Notification.getSlot(slotType).then((data) => {  console.info("getSlot success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getSlot failed, code is ${err}`);});    
```    
  
    
## getSlots<sup>(deprecated)</sup>    
获取此应用程序的所有通知通道（callback形式）。  
 **调用形式：**     
- getSlots(callback: AsyncCallback\<Array\<NotificationSlot>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getSlots。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<NotificationSlot>> | true | callback形式返回获取此应用程序的所有通知通道的结果。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
// getSlots回调  
function getSlotsCallback(err: Base.BusinessError) {  
  if (err) {  
    console.info("getSlots failed " + JSON.stringify(err));  
  } else {  
    console.info("getSlots success");  
  }  
}  
Notification.getSlots(getSlotsCallback);  
    
```    
  
    
## getSlots<sup>(deprecated)</sup>    
获取此应用程序的所有通知通道（Promise形式）。  
 **调用形式：**     
- getSlots(): Promise\<Array\<NotificationSlot>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getSlots。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<NotificationSlot>> | 以Promise形式返回获取此应用程序的所有通知通道的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.getSlots().then((data) => {  console.info("getSlots success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getSlots failed, code is ${err}`);});    
```    
  
    
## removeSlot<sup>(deprecated)</sup>    
删除指定类型的通知通道（callback形式）。  
 **调用形式：**     
- removeSlot(slotType: SlotType, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#removeSlot。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType<sup>(deprecated)</sup> | SlotType | true | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
// removeSlot回调  
let removeSlotCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("removeSlot failed " + JSON.stringify(err));  
  } else {  
    console.info("removeSlot success");  
  }  
}  
let slotType: Notification.SlotType = Notification.SlotType.SOCIAL_COMMUNICATION;  
Notification.removeSlot(slotType, removeSlotCallback);  
    
```    
  
    
## removeSlot<sup>(deprecated)</sup>    
删除指定类型的通知通道（Promise形式）。  
。示例（Promise）：。  
 **调用形式：**     
- removeSlot(slotType: SlotType): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#removeSlot。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotType<sup>(deprecated)</sup> | SlotType | true | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let slotType: Notification.SlotType = Notification.SlotType.SOCIAL_COMMUNICATION;Notification.removeSlot(slotType).then(() => {  console.info("removeSlot success");}).catch((err: Base.BusinessError) => {  console.error(`removeSlot failed, code is ${err}`);});    
```    
  
    
## removeAllSlots<sup>(deprecated)</sup>    
删除所有通知通道（callback形式）。  
 **调用形式：**     
- removeAllSlots(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#removeAllSlots。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let removeAllCallBack = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("removeAllSlots failed " + JSON.stringify(err));  
  } else {  
    console.info("removeAllSlots success");  
  }  
}  
Notification.removeAllSlots(removeAllCallBack);  
    
```    
  
    
## removeAllSlots<sup>(deprecated)</sup>    
删除所有通知通道（Promise形式）。  
 **调用形式：**     
- removeAllSlots(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#removeAllSlots。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.removeAllSlots().then(() => {  console.info("removeAllSlots success");}).catch((err: Base.BusinessError) => {  console.error(`removeAllSlots failed, code is ${err}`);});    
```    
  
    
## SlotType<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#SlotType替代。    
    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN_TYPE<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotType#UNKNOWN_TYPE替代。<br> 未知类型。 |  
| SOCIAL_COMMUNICATION<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotType#SOCIAL_COMMUNICATION替代。<br>社交类型。 |  
| SERVICE_INFORMATION<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotType#SERVICE_INFORMATION替代。<br>服务类型。 |  
| CONTENT_INFORMATION<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotType#CONTENT_INFORMATION替代。<br>内容类型。 |  
| OTHER_TYPES<sup>(deprecated)</sup> | 0xFFFF | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotType#OTHER_TYPES替代。<br>其他类型。 |  
    
## ContentType<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotType#ContentType替代。    
    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOTIFICATION_CONTENT_BASIC_TEXT<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.ContentType#NOTIFICATION_CONTENT_BASIC_TEXT替代。<br>普通类型通知。 |  
| NOTIFICATION_CONTENT_LONG_TEXT<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.ContentType#NOTIFICATION_CONTENT_LONG_TEXT替代。<br>长文本类型通知。 |  
| NOTIFICATION_CONTENT_PICTURE<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.ContentType#NOTIFICATION_CONTENT_PICTURE替代。<br>图片类型通知。   |  
| NOTIFICATION_CONTENT_CONVERSATION<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.ContentType#NOTIFICATION_CONTENT_CONVERSATION替代。<br>社交类型通知。 |  
| NOTIFICATION_CONTENT_MULTILINE<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.ContentType#NOTIFICATION_CONTENT_MULTILINE替代。<br>多行文本类型通知。 |  
    
## SlotLevel<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#SlotLevel替代。    
    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LEVEL_NONE<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotLevel#LEVEL_NONE替代。<br>表示关闭通知功能。  |  
| LEVEL_MIN<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotLevel#LEVEL_MIN替代。<br>表示通知功能已启用，但状态栏中不显示通知图标，且没有横幅或提示音。 |  
| LEVEL_LOW<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotLevel#LEVEL_LOW替代。<br><span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">表示通知功能已启用，且状态栏中显示通知图标，但没有横幅或提示音。</span> |  
| LEVEL_DEFAULT<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotLevel#LEVEL_DEFAULT替代。<br>表示通知功能已启用，状态栏中显示通知图标，没有横幅但有提示音。  |  
| LEVEL_HIGH<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager.SlotLevel#LEVEL_HIGH替代。<br>表示通知功能已启用，状态栏中显示通知图标，有横幅和提示音。 |  
    
## getActiveNotificationCount<sup>(deprecated)</sup>    
获取当前应用未删除的通知数（Callback形式）。  
 **调用形式：**     
- getActiveNotificationCount(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getActiveNotificationCount。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 获取未删除通知数回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let getActiveNotificationCountCallback = (err: Base.BusinessError, data: number) => {  
  if (err) {  
    console.info("getActiveNotificationCount failed " + JSON.stringify(err));  
  } else {  
    console.info("getActiveNotificationCount success");  
  }  
}  
  
Notification.getActiveNotificationCount(getActiveNotificationCountCallback);  
    
```    
  
    
## getActiveNotificationCount<sup>(deprecated)</sup>    
获取当前应用未删除的通知数（Promise形式）。  
 **调用形式：**     
- getActiveNotificationCount(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getActiveNotificationCount。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 以Promise形式返回获取当前应用未删除通知数。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.getActiveNotificationCount().then((data: number) => {  console.info("getActiveNotificationCount success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`getAllActiveNotifications failed, code is ${err}`);});    
```    
  
    
## getActiveNotifications<sup>(deprecated)</sup>    
获取当前应用未删除的通知列表（Callback形式）。  
 **调用形式：**     
- getActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getActiveNotifications。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<NotificationRequest>> | true | 获取当前应用通知列表回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
import NotificationManager from '@ohos.notificationManager';  
  
let getActiveNotificationsCallback = (err: Base.BusinessError, data: NotificationManager.NotificationRequest[]) => {  
  if (err) {  
    console.info("getActiveNotifications failed " + JSON.stringify(err));  
  } else {  
    console.info("getActiveNotifications success");  
  }  
}  
  
Notification.getActiveNotifications(getActiveNotificationsCallback);  
    
```    
  
    
## getActiveNotifications<sup>(deprecated)</sup>    
获取当前应用未删除的通知列表（Promise形式）。  
 **调用形式：**     
- getActiveNotifications(): Promise\<Array\<NotificationRequest>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#getActiveNotifications。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<NotificationRequest>> | 以Promise形式返回获取当前应用通知列表。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';import NotificationManager from '@ohos.notificationManager';  
Notification.getActiveNotifications().then((data: NotificationManager.NotificationRequest[]) => {  console.info("removeGroupByBundle success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`removeGroupByBundle failed, code is ${err}`);});    
```    
  
    
## cancelGroup<sup>(deprecated)</sup>    
取消本应用指定组下的通知（Callback形式）。  
 **调用形式：**     
- cancelGroup(groupName: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#cancelGroup。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| groupName<sup>(deprecated)</sup> | string | true | 通知组名称，此名称需要在发布通知时通过[NotificationRequest](#notificationrequest)对象指定。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 取消本应用指定组下通知的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let cancelGroupCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("cancelGroup failed " + JSON.stringify(err));  
  } else {  
    console.info("cancelGroup success");  
  }  
}  
  
let groupName: string = "GroupName";  
  
Notification.cancelGroup(groupName, cancelGroupCallback);  
    
```    
  
    
## cancelGroup<sup>(deprecated)</sup>    
取消本应用指定组下的通知（Promise形式）。  
 **调用形式：**     
- cancelGroup(groupName: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#cancelGroup。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| groupName<sup>(deprecated)</sup> | string | true |  通知组名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let groupName: string = "GroupName";Notification.cancelGroup(groupName).then(() => {console.info("cancelGroup success");}).catch((err: Base.BusinessError) => {  console.error(`cancelGroup failed, code is ${err}`);});    
```    
  
    
## isSupportTemplate<sup>(deprecated)</sup>    
查询模板是否存在（Callback形式）。  
 **调用形式：**     
- isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isSupportTemplate。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| templateName<sup>(deprecated)</sup> | string | true |  模板名称。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 查询模板是否存在的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let templateName: string = 'process';  
function isSupportTemplateCallback(err: Base.BusinessError, data: boolean) {  
  if (err) {  
    console.info("isSupportTemplate failed " + JSON.stringify(err));  
  } else {  
    console.info("isSupportTemplate success");  
  }  
}  
  
Notification.isSupportTemplate(templateName, isSupportTemplateCallback)  
    
```    
  
    
## isSupportTemplate<sup>(deprecated)</sup>    
查询模板是否存在（Promise形式）。  
 **调用形式：**     
- isSupportTemplate(templateName: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isSupportTemplate。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| templateName<sup>(deprecated)</sup> | string | true | 模板名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise方式返回模板是否存在的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
let templateName: string = 'process';Notification.isSupportTemplate(templateName).then((data: boolean) => {  console.info("isSupportTemplate success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`isSupportTemplate failed, code is ${err}`);});    
```    
  
    
## requestEnableNotification<sup>(deprecated)</sup>    
应用请求通知使能（Callback形式）。  
 **调用形式：**     
- requestEnableNotification(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#requestEnableNotification。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 应用请求通知使能的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let requestEnableNotificationCallback = (err: Base.BusinessError) => {  
  if (err) {  
    console.info("requestEnableNotification failed " + JSON.stringify(err));  
  } else {  
    console.info("requestEnableNotification success");  
  }  
};  
  
Notification.requestEnableNotification(requestEnableNotificationCallback);  
    
```    
  
    
## requestEnableNotification<sup>(deprecated)</sup>    
应用请求通知使能（Promise形式）。  
 **调用形式：**     
- requestEnableNotification(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#requestEnableNotification。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.requestEnableNotification().then(() => {  console.info("requestEnableNotification success");}).catch((err: Base.BusinessError) => {  console.error(`requestEnableNotification failed, code is ${err}`);});    
```    
  
    
## isDistributedEnabled<sup>(deprecated)</sup>    
查询设备是否支持分布式通知（Callback形式）。  
 **调用形式：**     
- isDistributedEnabled(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isDistributedEnabled。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true |  设备是否支持分布式通知的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import Base from '@ohos.base';  
  
let isDistributedEnabledCallback = (err: Base.BusinessError, data: boolean) => {  
  if (err) {  
    console.info("isDistributedEnabled failed " + JSON.stringify(err));  
  } else {  
    console.info("isDistributedEnabled success " + JSON.stringify(data));  
  }  
};  
  
Notification.isDistributedEnabled(isDistributedEnabledCallback);  
    
```    
  
    
## isDistributedEnabled<sup>(deprecated)</sup>    
查询设备是否支持分布式通知（Promise形式）。  
 **调用形式：**     
- isDistributedEnabled(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.notificationManager/notificationManager#isDistributedEnabled。  
 **系统能力:**  SystemCapability.Notification.Notification    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise方式返回设备是否支持分布式通知的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import Base from '@ohos.base';  
Notification.isDistributedEnabled().then((data: boolean) => {    console.info("isDistributedEnabled success, data: " + JSON.stringify(data));}).catch((err: Base.BusinessError) => {  console.error(`isDistributedEnabled failed, code is ${err}`);});    
```    
  
    
## BundleOption<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#BundleOption替代。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundle<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#BundleOption替代。<br>应用的包信息。 |  
| uid<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#BundleOption替代。<br>用户ID，默认为0。 |  
    
## NotificationKey<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#NotificationKey替代。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#NotificationKey替代。<br>通知ID。  |  
| label<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.notificationManager/notificationManager#NotificationKey替代。<br>通知标签。 |  
