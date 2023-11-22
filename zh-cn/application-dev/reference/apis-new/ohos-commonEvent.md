# @ohos.commonEvent    
本模块提供了公共事件的能力，包括公共事件的权限列表，发布公共事件，订阅或取消订阅公共事件，获取或修改公共事件结果代码、结果数据等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import commonEvent from '@ohos.commonEvent'    
```  
    
## publish<sup>(deprecated)</sup>    
发布公共事件（回调形式）。  
 **调用形式：**     
- publish(event: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.commonEventManager/commonEventManager#publish。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 表示要发送的公共事件。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
  
//发布公共事件回调  
function publishCB(err:Base.BusinessError) {  
	if (err.code) {  
        console.error(`publish failed, code is ${err.code}`);  
    } else {  
        console.info("publish");  
    }  
}  
  
//发布公共事件  
CommonEvent.publish("event", publishCB);  
    
```    
  
    
## publish<sup>(deprecated)</sup>    
以回调的形式发布公共事件。  
 **调用形式：**     
- publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.commonEventManager/commonEventManager#publish。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 表示要发布的公共事件。 |  
| options<sup>(deprecated)</sup> | CommonEventPublishData | true | 表示发布公共事件的属性。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
import CommonEventManager from '@ohos.commonEventManager';  
  
//公共事件相关信息  
let options:CommonEventManager.CommonEventPublishData = {  
	code: 0,			 //公共事件的初始代码  
	data: "initial data",//公共事件的初始数据  
	isOrdered: true	 //有序公共事件  
}  
  
//发布公共事件回调  
function publishCB(err:Base.BusinessError) {  
	if (err.code) {  
        console.error(`publish failed, code is ${err.code}`);  
    } else {  
        console.info("publish");  
    }  
}  
  
//发布公共事件  
CommonEvent.publish("event", options, publishCB);  
    
```    
  
    
## createSubscriber<sup>(deprecated)</sup>    
以回调形式创建订阅者。  
 **调用形式：**     
- createSubscriber(     subscribeInfo: CommonEventSubscribeInfo,     callback: AsyncCallback\<CommonEventSubscriber>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.commonEventManager/commonEventManager#createSubscriber。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscribeInfo<sup>(deprecated)</sup> | CommonEventSubscribeInfo | true | 表示订阅信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<CommonEventSubscriber> | true | 表示创建订阅者的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
import CommonEventManager from '@ohos.commonEventManager';  
  
let subscriber:CommonEventManager.CommonEventSubscriber; // 用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
  
// 订阅者信息  
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {  
    events: ["event"]  
};  
  
// 创建订阅者回调  
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {  
    if (err.code) {  
        console.error(`createSubscriber failed, code is ${err.code}`);  
    } else {  
        console.info("createSubscriber");  
        subscriber = commonEventSubscriber;  
    }  
}  
  
// 创建订阅者  
CommonEvent.createSubscriber(subscribeInfo, createCB);  
    
```    
  
    
## createSubscriber<sup>(deprecated)</sup>    
以Promise形式创建订阅者。  
 **调用形式：**     
- createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.commonEventManager/commonEventManager#createSubscriber。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscribeInfo<sup>(deprecated)</sup> | CommonEventSubscribeInfo | true | 表示订阅信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<CommonEventSubscriber> | 返回订阅者对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import Base from '@ohos.base';import CommonEventManager from '@ohos.commonEventManager';  
let subscriber:CommonEventManager.CommonEventSubscriber; // 用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
// 订阅者信息let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {    events: ["event"]};  
// 创建订阅者CommonEvent.createSubscriber(subscribeInfo).then((commonEventSubscriber:CommonEventManager.CommonEventSubscriber) => {    console.info("createSubscriber");    subscriber = commonEventSubscriber;}).catch((err:Base.BusinessError) => {    console.error(`createSubscriber failed, code is ${err.code}`);});    
```    
  
    
## subscribe<sup>(deprecated)</sup>    
以回调形式订阅公共事件。  
 **调用形式：**     
- subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.commonEventManager/commonEventManager#subscribe。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber<sup>(deprecated)</sup> | CommonEventSubscriber | true | 表示订阅者对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<CommonEventData> | true | 表示接收公共事件数据的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
import CommonEventManager from '@ohos.commonEventManager';  
  
let subscriber:CommonEventManager.CommonEventSubscriber;// 用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
  
// 订阅者信息  
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {  
    events: ["event"]  
};  
  
// 订阅公共事件回调  
function subscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {  
    if (err.code) {  
        console.error(`subscribe failed, code is ${err.code}`);  
    } else {  
        console.info("subscribe " + JSON.stringify(data));  
    }  
}  
  
// 创建订阅者回调  
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {  
    if (err.code) {  
        console.error(`createSubscriber failed, code is ${err.code}`);  
    } else {  
        console.info("createSubscriber");  
        subscriber = commonEventSubscriber;  
        // Subscribe to a common event.  
        CommonEvent.subscribe(subscriber, subscribeCB);  
    }  
}  
  
// 创建订阅者  
CommonEvent.createSubscriber(subscribeInfo, createCB);  
    
```    
  
    
## unsubscribe<sup>(deprecated)</sup>    
以回调形式取消订阅公共事件。  
 **调用形式：**     
- unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.commonEventManager/commonEventManager#unsubscribe。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber<sup>(deprecated)</sup> | CommonEventSubscriber | true | 表示订阅者对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | false | 表示取消订阅的回调方法。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
import CommonEventManager from '@ohos.commonEventManager';  
  
let subscriber:CommonEventManager.CommonEventSubscriber;	// 用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
  
// 订阅者信息  
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {  
    events: ["event"]  
};  
  
// 订阅公共事件回调  
function subscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {  
    if (err.code) {  
        console.error(`subscribe failed, code is ${err.code}`);  
    } else {  
        console.info("subscribe " + JSON.stringify(data));  
    }  
}  
  
// 创建订阅者回调  
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {  
    if (err.code) {  
        console.error(`createSubscriber failed, code is ${err.code}`);  
    } else {  
        console.info("createSubscriber");  
        subscriber = commonEventSubscriber;  
        // Subscribe to a common event.  
        CommonEvent.subscribe(subscriber, subscribeCB);  
    }  
}  
  
// 取消订阅公共事件回调  
function unsubscribeCB(err:Base.BusinessError) {  
    if (err.code) {  
        console.error(`unsubscribe failed, code is ${err.code}`);  
    } else {  
        console.info("unsubscribe");  
    }  
}  
  
// 创建订阅者  
CommonEvent.createSubscriber(subscribeInfo, createCB);  
  
// 取消订阅公共事件  
CommonEvent.unsubscribe(subscriber, unsubscribeCB);  
    
```    
  
    
## Support<sup>(deprecated)</sup>    
系统公共事件是指由系统服务或系统应用发布的事件，订阅这些系统公共事件需要特定的权限。发布或订阅这些事件需要使用如下链接中的枚举定义。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager#Support替代。    
    
 **系统能力:**  SystemCapability.Notification.CommonEvent    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COMMON_EVENT_BOOT_COMPLETED<sup>(deprecated)</sup> | usual.event.BOOT_COMPLETED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BOOT_COMPLETED替代。<br>提示用户已完成引导并加载系统。  - 值：usual.event.BOOT_COMPLETED  - 订阅者所需权限：ohos.permission.RECEIVER_STARTUP_COMPLETED |  
| COMMON_EVENT_LOCKED_BOOT_COMPLETED<sup>(deprecated)</sup> | usual.event.LOCKED_BOOT_COMPLETED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_LOCKED_BOOT_COMPLETED替代。<br>（预留事件，暂未支持）提示用户已完成引导，系统已加载，但屏幕仍锁定。  - 值：usual.event.LOCKED_BOOT_COMPLETED  - 订阅者所需权限：ohos.permission.RECEIVER_STARTUP_COMPLETED |  
| COMMON_EVENT_SHUTDOWN<sup>(deprecated)</sup> | usual.event.SHUTDOWN | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_SHUTDOWN替代。<br>提示设备正在关闭并将继续直至最终关闭。  - 值：usual.event.SHUTDOWN  - 订阅者所需权限：无 |  
| COMMON_EVENT_BATTERY_CHANGED<sup>(deprecated)</sup> | usual.event.BATTERY_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BATTERY_CHANGED替代。<br>提示电池充电状态、电量和其他信息发生变化。  - 值：usual.event.BATTERY_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_BATTERY_LOW<sup>(deprecated)</sup> | usual.event.BATTERY_LOW | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BATTERY_LOW替代。<br>提示电池电量低。  - 值：usual.event.BATTERY_LOW  - 订阅者所需权限：无 |  
| COMMON_EVENT_BATTERY_OKAY<sup>(deprecated)</sup> | usual.event.BATTERY_OKAY | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BATTERY_OKAY替代。<br>提示电池退出低电量状态。  - 值：usual.event.BATTERY_OKAY  - 订阅者所需权限：无。 |  
| COMMON_EVENT_POWER_CONNECTED<sup>(deprecated)</sup> | usual.event.POWER_CONNECTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_POWER_CONNECTED替代。<br>提示设备连接到外部电源。  - 值：usual.event.POWER_CONNECTED  - 订阅者所需权限：无 |  
| COMMON_EVENT_POWER_DISCONNECTED<sup>(deprecated)</sup> | usual.event.POWER_DISCONNECTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_POWER_DISCONNECTED替代。<br>提示设备与外部电源断开。  - 值：usual.event.POWER_DISCONNECTED  - 订阅者所需权限：无 |  
| COMMON_EVENT_SCREEN_OFF<sup>(deprecated)</sup> | usual.event.SCREEN_OFF | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_SCREEN_OFF替代。<br>提示设备屏幕关闭且设备处于睡眠状态。  - 值：usual.event.SCREEN_OFF  - 订阅者所需权限：无 |  
| COMMON_EVENT_SCREEN_ON<sup>(deprecated)</sup> | usual.event.SCREEN_ON | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_SCREEN_ON替代。<br>提示设备屏幕打开且设备处于交互状态。  - 值：usual.event.SCREEN_ON  - 订阅者所需权限：无。 |  
| COMMON_EVENT_THERMAL_LEVEL_CHANGED<sup>(deprecated)</sup> | usual.event.THERMAL_LEVEL_CHANGED | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_THERMAL_LEVEL_CHANGED替代。<br>提示设备热状态（温度等级）发生变化。  - 值：usual.event.THERMAL_LEVEL_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_USER_PRESENT<sup>(deprecated)</sup> | usual.event.USER_PRESENT | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_PRESENT替代。<br>（预留事件，暂未支持）提示用户解锁了设备。  - 值：usual.event.USER_PRESENT  - 订阅者所需权限：无 |  
| COMMON_EVENT_TIME_TICK<sup>(deprecated)</sup> | usual.event.TIME_TICK | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_TIME_TICK替代。<br>提示系统时间发生更改（指时间正常流逝）。  - 值：usual.event.TIME_TICK  - 订阅者所需权限：无 |  
| COMMON_EVENT_TIME_CHANGED<sup>(deprecated)</sup> | usual.event.TIME_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_TIME_CHANGED替代。<br>提示系统时间被被重新设置。  - 值：usual.event.TIME_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_DATE_CHANGED<sup>(deprecated)</sup> | usual.event.DATE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DATE_CHANGED替代。<br>（预留事件，暂未支持）提示系统日期已更改。  - 值：usual.event.DATE_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_TIMEZONE_CHANGED<sup>(deprecated)</sup> | usual.event.TIMEZONE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_TIMEZONE_CHANGED替代。<br>提示系统时区发生变更。  - 值：usual.event.TIMEZONE_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_CLOSE_SYSTEM_DIALOGS<sup>(deprecated)</sup> | usual.event.CLOSE_SYSTEM_DIALOGS | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_CLOSE_SYSTEM_DIALOGS替代。<br>（预留事件，暂未支持）提示用户关闭临时系统对话框。  - 值：usual.event.CLOSE_SYSTEM_DIALOGS  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_ADDED<sup>(deprecated)</sup> | usual.event.PACKAGE_ADDED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_ADDED替代。<br>提示设备上已安装新应用程序包。  - 值：usual.event.PACKAGE_ADDED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_REPLACED<sup>(deprecated)</sup> | usual.event.PACKAGE_REPLACED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_REPLACED替代。<br>（预留事件，暂未支持）提示设备上已安装的旧版本应用程序已被新版本所替换。  - 值：usual.event.PACKAGE_REPLACED  - 订阅者所需权限：无 |  
| COMMON_EVENT_MY_PACKAGE_REPLACED<sup>(deprecated)</sup> | usual.event.MY_PACKAGE_REPLACED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_MY_PACKAGE_REPLACED替代。<br>（预留事件，暂未支持）提示应用程序包的新版本已取代前一个版本。  - 值：usual.event.MY_PACKAGE_REPLACED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_REMOVED<sup>(deprecated)</sup> | usual.event.PACKAGE_REMOVED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_REMOVED替代。<br>提示已安装的应用程序已从设备卸载，但应用程序数据得到保留的。  - 值：usual.event.PACKAGE_REMOVED  - 订阅者所需权限：无 |  
| COMMON_EVENT_BUNDLE_REMOVED<sup>(deprecated)</sup> | usual.event.BUNDLE_REMOVED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BUNDLE_REMOVED替代。<br>（预留事件，暂未支持）提示已从设备中卸载已安装应用程序的附加包，但应用程序数据得到保留。  - 值：usual.event.BUNDLE_REMOVED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_FULLY_REMOVED<sup>(deprecated)</sup> | usual.event.PACKAGE_FULLY_REMOVED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_FULLY_REMOVED替代。<br>（预留事件，暂未支持）提示已从设备中完全卸载已安装的应用程序（包括应用程序数据和代码）。  - 值：usual.event.PACKAGE_FULLY_REMOVED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_CHANGED<sup>(deprecated)</sup> | usual.event.PACKAGE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_CHANGED替代。<br>提示应用程序包已发生更改（例如，包中的组件已启用或禁用）。  - 值：usual.event.PACKAGE_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_RESTARTED<sup>(deprecated)</sup> | usual.event.PACKAGE_RESTARTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_RESTARTED替代。<br>提示用户终止了应用程序的所有进程并重启应用程序。  - 值：usual.event.PACKAGE_RESTARTED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_DATA_CLEARED<sup>(deprecated)</sup> | usual.event.PACKAGE_DATA_CLEARED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_DATA_CLEARED替代。<br>提示用户清除了应用包数据。  - 值：usual.event.PACKAGE_DATA_CLEARED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGES_SUSPENDED<sup>(deprecated)</sup> | usual.event.PACKAGES_SUSPENDED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGES_SUSPENDED替代。<br>（预留事件，暂未支持）提示应用程序已挂起。  - 值：usual.event.PACKAGES_SUSPENDED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGES_UNSUSPENDED<sup>(deprecated)</sup> | usual.event.PACKAGES_UNSUSPENDED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGES_UNSUSPENDED替代。<br>（预留事件，暂未支持）提示应用HAP包未挂起（从挂起状态恢复）。  - 值：usual.event.PACKAGES_UNSUSPENDED  - 订阅者所需权限：无 |  
| COMMON_EVENT_MY_PACKAGE_SUSPENDED<sup>(deprecated)</sup> | usual.event.MY_PACKAGE_SUSPENDED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_MY_PACKAGE_SUSPENDED替代。<br>提示应用HAP包被挂起的。  - 值：usual.event.MY_PACKAGE_SUSPENDED  - 订阅者所需权限：无。 |  
| COMMON_EVENT_MY_PACKAGE_UNSUSPENDED<sup>(deprecated)</sup> | usual.event.MY_PACKAGE_UNSUSPENDED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_MY_PACKAGE_UNSUSPENDED替代。<br>提示应用包未挂起。  - 值：usual.event.MY_PACKAGE_UNSUSPENDED  - 订阅者所需权限：无 |  
| COMMON_EVENT_UID_REMOVED<sup>(deprecated)</sup> | usual.event.UID_REMOVED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_UID_REMOVED替代。<br>（预留事件，暂未支持）提示用户ID已从系统中删除。  - 值：usual.event.UID_REMOVED  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_FIRST_LAUNCH<sup>(deprecated)</sup> | usual.event.PACKAGE_FIRST_LAUNCH | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_FIRST_LAUNCH替代。<br>（预留事件，暂未支持）提示首次启动已安装的应用程序。  - 值：usual.event.PACKAGE_FIRST_LAUNCH  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION<sup>(deprecated)</sup> | usual.event.PACKAGE_NEEDS_VERIFICATION | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION替代。<br>（预留事件，暂未支持）提示应用需要系统校验。  - 值：usual.event.PACKAGE_NEEDS_VERIFICATION  - 订阅者所需权限：无 |  
| COMMON_EVENT_PACKAGE_VERIFIED<sup>(deprecated)</sup> | usual.event.PACKAGE_VERIFIED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_PACKAGE_VERIFIED替代。<br>（预留事件，暂未支持）提示应用已被系统校验。  - 值：usual.event.PACKAGE_VERIFIED  - 订阅者所需权限：无 |  
| COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE<sup>(deprecated)</sup> | usual.event.EXTERNAL_APPLICATIONS_AVAILABLE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE替代。<br>（预留事件，暂未支持）提示安装在外部存储上的应用程序对系统可用。  - 值：usual.event.EXTERNAL_APPLICATIONS_AVAILABLE  - 订阅者所需权限：无 |  
| COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE<sup>(deprecated)</sup> | usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManage/commonEventManager.Support#COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE替代。<br>（预留事件，暂未支持）提示安装在外部存储上的应用程序对系统不可用。  - 值：usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE  - 订阅者所需权限：无 |  
| COMMON_EVENT_CONFIGURATION_CHANGED<sup>(deprecated)</sup> | usual.event.CONFIGURATION_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_CONFIGURATION_CHANGED替代。<br>（预留事件，暂未支持）提示设备状态（例如，方向、区域设置等）已更改。  - 值：usual.event.CONFIGURATION_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_LOCALE_CHANGED<sup>(deprecated)</sup> | usual.event.LOCALE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_LOCALE_CHANGED替代。<br>（预留事件，暂未支持）提示设备区域设置已更改。  - 值：usual.event.LOCALE_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_MANAGE_PACKAGE_STORAGE<sup>(deprecated)</sup> | usual.event.MANAGE_PACKAGE_STORAGE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_MANAGE_PACKAGE_STORAGE替代。<br>（预留事件，暂未支持）提示设备存储空间不足。  - 值：usual.event.MANAGE_PACKAGE_STORAGE  - 订阅者所需权限：无 |  
| COMMON_EVENT_DRIVE_MODE<sup>(deprecated)</sup> | common.event.DRIVE_MODE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DRIVE_MODE替代。<br>（预留事件，暂未支持）提示系统处于驾驶模式。  - 值：common.event.DRIVE_MODE  - 订阅者所需权限：无 |  
| COMMON_EVENT_HOME_MODE<sup>(deprecated)</sup> | common.event.HOME_MODE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_HOME_MODE替代。<br>（预留事件，暂未支持）提示系统处于HOME模式。  - 值：common.event.HOME_MODE  - 订阅者所需权限：无 |  
| COMMON_EVENT_OFFICE_MODE<sup>(deprecated)</sup> | common.event.OFFICE_MODE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_OFFICE_MODE替代。<br>（预留事件，暂未支持）提示系统处于办公模式。  - 值：common.event.OFFICE_MODE  - 订阅者所需权限：无 |  
| COMMON_EVENT_USER_STARTED<sup>(deprecated)</sup> | usual.event.USER_STARTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_STARTED替代。<br>（预留事件，暂未支持）提示用户已启动。  - 值：usual.event.USER_STARTED  - 订阅者所需权限：无 |  
| COMMON_EVENT_USER_BACKGROUND<sup>(deprecated)</sup> | usual.event.USER_BACKGROUND | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_BACKGROUND替代。<br>（预留事件，暂未支持）提示用户已被带到后台。  - 值：usual.event.USER_BACKGROUND  - 订阅者所需权限：无 |  
| COMMON_EVENT_USER_FOREGROUND<sup>(deprecated)</sup> | usual.event.USER_FOREGROUND | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_FOREGROUND替代。<br>（预留事件，暂未支持）提示用户已被带到前台。  - 值：usual.event.USER_FOREGROUND  - 订阅者所需权限：无 |  
| COMMON_EVENT_USER_SWITCHED<sup>(deprecated)</sup> | usual.event.USER_SWITCHED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_SWITCHED替代。<br>提示用户正在切换。  - 值：usual.event.USER_SWITCHED  - 订阅者所需权限：  - 订阅者所需权限：ohos.permission.MANAGE_LOCAL_ACCOUNTS |  
| COMMON_EVENT_USER_STARTING<sup>(deprecated)</sup> | usual.event.USER_STARTING | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_STARTING替代。<br>（预留事件，暂未支持）提示用户正在启动。  - 值：usual.event.USER_STARTING  - 订阅者所需权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS。 |  
| COMMON_EVENT_USER_UNLOCKED<sup>(deprecated)</sup> | usual.event.USER_UNLOCKED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_UNLOCKED替代。<br>（预留事件，暂未支持）在重启后解锁时，提示当前用户的凭据加密存储已解锁。  - 值：usual.event.USER_UNLOCKED  - 订阅者所需权限：无 |  
| COMMON_EVENT_USER_STOPPING<sup>(deprecated)</sup> | usual.event.USER_STOPPING | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_STOPPING替代。<br>（预留事件，暂未支持）提示要停止用户。  - 值：usual.event.USER_STOPPING  - 订阅者所需权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS |  
| COMMON_EVENT_USER_STOPPED<sup>(deprecated)</sup> | usual.event.USER_STOPPED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_STOPPED替代。<br>（预留事件，暂未支持）提示用户已停止。  - 值：usual.event.USER_STOPPED  - 订阅者所需权限：无 |  
| COMMON_EVENT_HWID_LOGIN<sup>(deprecated)</sup> | common.event.HWID_LOGIN | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_HWID_LOGIN替代。 |  
| COMMON_EVENT_HWID_LOGOUT<sup>(deprecated)</sup> | common.event.HWID_LOGOUT | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_HWID_LOGOUT替代。 |  
| COMMON_EVENT_HWID_TOKEN_INVALID<sup>(deprecated)</sup> | common.event.HWID_TOKEN_INVALID | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_HWID_TOKEN_INVALID替代。 |  
| COMMON_EVENT_HWID_LOGOFF<sup>(deprecated)</sup> | common.event.HWID_LOGOFF | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_HWID_LOGOFF替代。 |  
| COMMON_EVENT_WIFI_POWER_STATE<sup>(deprecated)</sup> | usual.event.wifi.POWER_STATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_POWER_STATE替代。<br>提示Wi-Fi功能状态的变更，如启用或禁用。  - 值：usual.event.wifi.POWER_STATE  - 订阅者所需权限：无 |  
| COMMON_EVENT_WIFI_SCAN_FINISHED<sup>(deprecated)</sup> | usual.event.wifi.SCAN_FINISHED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_SCAN_FINISHED替代。<br>提示Wi-Fi接入点已被扫描并证明可用。  - 值：usual.event.wifi.SCAN_FINISHED  - 订阅者所需权限：ohos.permission.LOCATION |  
| COMMON_EVENT_WIFI_RSSI_VALUE<sup>(deprecated)</sup> | usual.event.wifi.RSSI_VALUE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_RSSI_VALUE替代。<br>提示Wi-Fi信号强度（RSSI）改变。  - 值：usual.event.wifi.RSSI_VALUE  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO。 |  
| COMMON_EVENT_WIFI_CONN_STATE<sup>(deprecated)</sup> | usual.event.wifi.CONN_STATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_CONN_STATE替代。<br>提示Wi-Fi连接状态发生改变。  - 值：usual.event.wifi.CONN_STATE  - 订阅者所需权限：无 |  
| COMMON_EVENT_WIFI_HOTSPOT_STATE<sup>(deprecated)</sup> | usual.event.wifi.HOTSPOT_STATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_HOTSPOT_STATE替代。<br>提示Wi-Fi热点功能状态的变更，如启用或禁用。  - 值：usual.event.wifi.HOTSPOT_STATE  - 订阅者所需权限：无 |  
| COMMON_EVENT_WIFI_AP_STA_JOIN<sup>(deprecated)</sup> | usual.event.wifi.WIFI_HS_STA_JOIN | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_AP_STA_JOIN替代。<br>提示有客户端加入当前设备Wi-Fi热点。  - 值：usual.event.wifi.WIFI_HS_STA_JOIN  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO |  
| COMMON_EVENT_WIFI_AP_STA_LEAVE<sup>(deprecated)</sup> | usual.event.wifi.WIFI_HS_STA_LEAVE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_AP_STA_LEAVE替代。<br>提示客户端已断开与当前设备Wi-Fi热点的连接。  - 值：usual.event.wifi.WIFI_HS_STA_LEAVE  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO |  
| COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE<sup>(deprecated)</sup> | usual.event.wifi.mplink.STATE_CHANGE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE替代。<br>提示MPLink（增强Wi-Fi功能）状态已更改。  - 值：usual.event.wifi.mplink.STATE_CHANGE  - 订阅者所需权限：ohos.permission.MPLINK_CHANGE_STATE |  
| COMMON_EVENT_WIFI_P2P_CONN_STATE<sup>(deprecated)</sup> | usual.event.wifi.p2p.CONN_STATE_CHANGE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_P2P_CONN_STATE替代。<br>提示Wi-Fi P2P连接状态改变。  - 值：usual.event.wifi.p2p.CONN_STATE_CHANGE  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION |  
| COMMON_EVENT_WIFI_P2P_STATE_CHANGED<sup>(deprecated)</sup> | usual.event.wifi.p2p.STATE_CHANGE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_P2P_STATE_CHANGED替代。<br>提示Wi-Fi P2P连接状态改变。  - 值：usual.event.wifi.p2p.CONN_STATE_CHANGE  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION |  
| COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED<sup>(deprecated)</sup> | usual.event.wifi.p2p.DEVICES_CHANGE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED替代。<br>提示Wi-Fi P2P对等体状态变化。  - 值：usual.event.wifi.p2p.DEVICES_CHANGE  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO |  
| COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED<sup>(deprecated)</sup> | usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED替代。<br>提示Wi-Fi P2P发现状态变化。  - 值：usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO |  
| COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED<sup>(deprecated)</sup> | usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED替代。<br>提示Wi-Fi P2P当前设备状态变化。  - 值：usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO |  
| COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED<sup>(deprecated)</sup> | usual.event.wifi.p2p.GROUP_STATE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED替代。<br>提示Wi-Fi P2P群组信息已更改。  - 值：usual.event.wifi.p2p.GROUP_STATE_CHANGED  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO |  
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙免提通信连接状态。  - 值：usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE替代。<br>（预留事件，暂未支持）提示连接到具有蓝牙免提功能的设备处于活动状态。  - 值：usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙A2DP连接状态已更改。  - 值：usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙A2DP连接状态。  - 值：usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE替代。<br>（预留事件，暂未支持）提示使用蓝牙A2DP连接的设备处于活动状态。  - 值：usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙A2DP播放状态发生改变。  - 值：usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙A2DP的AVRCP连接状态已更改。  - 值：usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙A2DP音频编解码状态更改。  - 值：usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.DISCOVERED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED替代。<br>（预留事件，暂未支持）提示发现远程蓝牙设备。  - 值：usual.event.bluetooth.remotedevice.DISCOVERED  - 订阅者所需权限：ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE替代。<br>（预留事件，暂未支持）提示已与远程蓝牙设备建立低级别（ACL）连接。  - 值：usual.event.bluetooth.remotedevice.ACL_CONNECTED  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.ACL_CONNECTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED替代。<br>（预留事件，暂未支持）提示已与远程蓝牙设备建立低级别（ACL）连接。  - 值：usual.event.bluetooth.remotedevice.ACL_CONNECTED  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.ACL_DISCONNECTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED替代。<br>（预留事件，暂未支持）提示低级别（ACL）连接已从远程蓝牙设备断开。  - 值：usual.event.bluetooth.remotedevice.ACL_DISCONNECTED  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.NAME_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE替代。<br>（预留事件，暂未支持）提示远程蓝牙设备的友好名称首次被检索或自上次检索以来被更改。  - 值：usual.event.bluetooth.remotedevice.NAME_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.PAIR_STATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE替代。<br>（预留事件，暂未支持）提示远程蓝牙设备连接状态更改。  - 值：usual.event.bluetooth.remotedevice.PAIR_STATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE替代。<br>（预留事件，暂未支持）提示远程蓝牙设备的电池电量首次被检索或自上次检索以来被更改。  - 值：usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.SDP_RESULT | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT替代。<br>（预留事件，暂未支持）提示远程蓝牙设备SDP状态。  - 值：usual.event.bluetooth.remotedevice.SDP_RESULT  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.UUID_VALUE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE替代。<br>（预留事件，暂未支持）提示远程蓝牙设备UUID连接状态。  - 值：usual.event.bluetooth.remotedevice.UUID_VALUE  - 订阅者所需权限：ohos.permission.DISCOVER_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.PAIRING_REQ | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ替代。<br>（预留事件，暂未支持）提示远程蓝牙设备配对请求。  - 值：usual.event.bluetooth.remotedevice.PAIRING_REQ  - 订阅者所需权限：ohos.permission.DISCOVER_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.PAIRING_CANCEL | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL替代。<br>（预留事件，暂未支持）提示取消蓝牙配对。  - 值：usual.event.bluetooth.remotedevice.PAIRING_CANCEL  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.CONNECT_REQ | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ替代。<br>（预留事件，暂未支持）提示远程蓝牙设备连接请求。  - 值：usual.event.bluetooth.remotedevice.CONNECT_REQ  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.CONNECT_REPLY | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY替代。<br>（预留事件，暂未支持）提示远程蓝牙设备连接请求响应。  - 值：usual.event.bluetooth.remotedevice.CONNECT_REPLY  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL<sup>(deprecated)</sup> | usual.event.bluetooth.remotedevice.CONNECT_CANCEL | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL替代。<br>（预留事件，暂未支持）提示取消与远程蓝牙设备的连接。  - 值：usual.event.bluetooth.remotedevice.CONNECT_CANCEL  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙免提连接状态已更改。  - 值：usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙免提音频状态已更改。  - 值：usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT<sup>(deprecated)</sup> | usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT替代。<br>（预留事件，暂未支持）提示蓝牙免提音频网关状态已更改。  - 值：usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙免提呼叫状态已更改。  - 值：usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.host.STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙适配器状态已更改，例如蓝牙已打开或关闭。  - 值：usual.event.bluetooth.host.STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE<sup>(deprecated)</sup> | usual.event.bluetooth.host.REQ_DISCOVERABLE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE替代。<br>（预留事件，暂未支持）提示用户允许扫描蓝牙请求。  - 值：usual.event.bluetooth.host.REQ_DISCOVERABLE  - 订阅者所需权限：无 |  
| COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE<sup>(deprecated)</sup> | usual.event.bluetooth.host.REQ_ENABLE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE替代。<br>（预留事件，暂未支持）提示用户打开蓝牙请求。  - 值：usual.event.bluetooth.host.REQ_ENABLE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE<sup>(deprecated)</sup> | usual.event.bluetooth.host.REQ_DISABLE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE替代。<br>（预留事件，暂未支持）提示用户关闭蓝牙请求。  - 值：usual.event.bluetooth.host.REQ_DISABLE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.host.SCAN_MODE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE替代。<br>（预留事件，暂未支持）提示设备蓝牙扫描模式更改。  - 值：usual.event.bluetooth.host.SCAN_MODE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED<sup>(deprecated)</sup> | usual.event.bluetooth.host.DISCOVERY_STARTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED替代。<br>（预留事件，暂未支持）提示设备上已启动蓝牙扫描。  - 值：usual.event.bluetooth.host.DISCOVERY_STARTED  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED<sup>(deprecated)</sup> | usual.event.bluetooth.host.DISCOVERY_FINISHED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED替代。<br>（预留事件，暂未支持）提示设备上蓝牙扫描完成。  - 值：usual.event.bluetooth.host.DISCOVERY_FINISHED  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.host.NAME_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE替代。<br>（预留事件，暂未支持）提示设备蓝牙适配器名称已更改。  - 值：usual.event.bluetooth.host.NAME_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙A2DP宿的连接状态已更改。  - 值：usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙A2DP宿的播放状态发生改变。  - 值：usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE<sup>(deprecated)</sup> | usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE替代。<br>（预留事件，暂未支持）提示蓝牙A2DP宿的音频状态已更改。  - 值：usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED<sup>(deprecated)</sup> | usual.event.nfc.action.ADAPTER_STATE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED替代。<br>（预留事件，暂未支持）提示设备NFC适配器状态已更改。  - 值：usual.event.nfc.action.ADAPTER_STATE_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED<sup>(deprecated)</sup> | usual.event.nfc.action.RF_FIELD_ON_DETECTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED替代。<br>（预留事件，暂未支持）提示检测到NFC设备RF字段处于使能状态。  - 值：usual.event.nfc.action.RF_FIELD_ON_DETECTED  - 订阅者所需权限：ohos.permission.MANAGE_SECURE_SETTINGS |  
| COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED<sup>(deprecated)</sup> | usual.event.nfc.action.RF_FIELD_OFF_DETECTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED替代。<br>（预留事件，暂未支持）提示检测到NFC设备RF字段处于关闭状态。  - 值：usual.event.nfc.action.RF_FIELD_OFF_DETECTED  - 订阅者所需权限：ohos.permission.MANAGE_SECURE_SETTINGS |  
| COMMON_EVENT_DISCHARGING<sup>(deprecated)</sup> | usual.event.DISCHARGING | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DISCHARGING替代。<br>提示系统停止为电池充电。  - 值：usual.event.DISCHARGING  - 订阅者所需权限：无 |  
| COMMON_EVENT_CHARGING<sup>(deprecated)</sup> | usual.event.CHARGING | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_CHARGING替代。<br>提示系统开始为电池充电。  - 值：usual.event.CHARGING  - 订阅者所需权限：无 |  
| COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED<sup>(deprecated)</sup> | usual.event.DEVICE_IDLE_MODE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED替代。<br>（预留事件，暂未支持）提示系统空闲模式已更改。  - 值：usual.event.DEVICE_IDLE_MODE_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_POWER_SAVE_MODE_CHANGED<sup>(deprecated)</sup> | usual.event.POWER_SAVE_MODE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_POWER_SAVE_MODE_CHANGED替代。<br>提示系统节能模式更改。  - 值：usual.event.POWER_SAVE_MODE_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_USER_ADDED<sup>(deprecated)</sup> | usual.event.USER_ADDED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_ADDED替代。<br>提示用户已添加到系统中。  - 值：usual.event.USER_ADDED  - 订阅者所需权限：ohos.permission.MANAGE_LOCAL_ACCOUNTS |  
| COMMON_EVENT_USER_REMOVED<sup>(deprecated)</sup> | usual.event.USER_REMOVED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USER_REMOVED替代。<br>提示用户已从系统中删除。  - 值：usual.event.USER_REMOVED  - 订阅者所需权限：ohos.permission.MANAGE_LOCAL_ACCOUNTS |  
| COMMON_EVENT_ABILITY_ADDED<sup>(deprecated)</sup> | common.event.ABILITY_ADDED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_ABILITY_ADDED替代。<br>（预留事件，暂未支持）提示有某个能力已被添加。  - 值：usual.event.ABILITY_ADDED  - 订阅者所需权限：ohos.permission.LISTEN_BUNDLE_CHANGE |  
| COMMON_EVENT_ABILITY_REMOVED<sup>(deprecated)</sup> | common.event.ABILITY_REMOVED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_ABILITY_REMOVED替代。<br>（预留事件，暂未支持）提示已删除某个能力。  - 值：usual.event.ABILITY_REMOVED  - 订阅者所需权限：ohos.permission.LISTEN_BUNDLE_CHANGE |  
| COMMON_EVENT_ABILITY_UPDATED<sup>(deprecated)</sup> | common.event.ABILITY_UPDATED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_ABILITY_UPDATED替代。<br>（预留事件，暂未支持）提示能力已更新。  - 值：usual.event.ABILITY_UPDATED  - 订阅者所需权限：ohos.permission.LISTEN_BUNDLE_CHANGE |  
| COMMON_EVENT_LOCATION_MODE_STATE_CHANGED<sup>(deprecated)</sup> | usual.event.location.MODE_STATE_CHANGED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_LOCATION_MODE_STATE_CHANGED替代。<br>（预留事件，暂未支持）提示系统定位模式已更改。  - 值：usual.event.location.MODE_STATE_CHANGED  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_SLEEP<sup>(deprecated)</sup> | common.event.IVI_SLEEP | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_SLEEP替代。<br>（预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统正在休眠。  - 值：common.event.IVI_SLEEP  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_PAUSE<sup>(deprecated)</sup> | common.event.IVI_PAUSE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_PAUSE替代。<br>（预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统已休眠，并通知应用程序停止播放。  - 值：common.event.IVI_PAUSE  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_STANDBY<sup>(deprecated)</sup> | common.event.IVI_STANDBY | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_STANDBY替代。<br>（预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统中的第三方应用暂停当前工作。  - 值：common.event.IVI_STANDBY  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_LASTMODE_SAVE<sup>(deprecated)</sup> | common.event.IVI_LASTMODE_SAVE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_LASTMODE_SAVE替代。<br>（预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统中的第三方应用保存其最后一个模式。  - 值：common.event.IVI_LASTMODE_SAVE  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_VOLTAGE_ABNORMAL<sup>(deprecated)</sup> | common.event.IVI_VOLTAGE_ABNORMAL | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_VOLTAGE_ABNORMAL替代。<br>（预留事件，暂未支持）提示车辆电源系统电压异常。  - 值：common.event.IVI_VOLTAGE_ABNORMAL  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_HIGH_TEMPERATURE<sup>(deprecated)</sup> | common.event.IVI_HIGH_TEMPERATURE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_HIGH_TEMPERATURE替代。<br>（预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统温度过高。  - 值：common.event.IVI_HIGH_TEMPERATURE  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_EXTREME_TEMPERATURE<sup>(deprecated)</sup> | common.event.IVI_EXTREME_TEMPERATURE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_EXTREME_TEMPERATURE替代。<br>（预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统温度极高。  - 值：common.event.IVI_EXTREME_TEMPERATURE  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL<sup>(deprecated)</sup> | common.event.IVI_TEMPERATURE_ABNORMAL | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL替代。<br>（预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统具有极端温度。  - 值：common.event.IVI_TEMPERATURE_ABNORMAL  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_VOLTAGE_RECOVERY<sup>(deprecated)</sup> | common.event.IVI_VOLTAGE_RECOVERY | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_VOLTAGE_RECOVERY替代。<br>（预留事件，暂未支持）提示车辆电源系统电压恢复正常。  - 值：common.event.IVI_VOLTAGE_RECOVERY  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_TEMPERATURE_RECOVERY<sup>(deprecated)</sup> | common.event.IVI_TEMPERATURE_RECOVERY | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_TEMPERATURE_RECOVERY替代。<br>（预留事件，暂未支持）提示车载系统温度恢复正常。  - 值：common.event.IVI_TEMPERATURE_RECOVERY  - 订阅者所需权限：无 |  
| COMMON_EVENT_IVI_ACTIVE<sup>(deprecated)</sup> | common.event.IVI_ACTIVE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_IVI_ACTIVE替代。<br>（预留事件，暂未支持）提示车载系统电池服务处于活动状态。  - 值：common.event.IVI_ACTIVE  - 订阅者所需权限：无 |  
| COMMON_EVENT_USB_DEVICE_ATTACHED<sup>(deprecated)</sup> | usual.event.hardware.usb.action.USB_DEVICE_ATTACHED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USB_DEVICE_ATTACHED替代。<br>当用户设备作为USB主机时，提示USB设备已挂载。  - 值：usual.event.hardware.usb.action.USB_DEVICE_ATTACHED  - 订阅者所需权限：无 |  
| COMMON_EVENT_USB_DEVICE_DETACHED<sup>(deprecated)</sup> | usual.event.hardware.usb.action.USB_DEVICE_DETACHED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USB_DEVICE_DETACHED替代。<br>当用户设备作为USB主机时，提示USB设备被卸载。  - 值：usual.event.hardware.usb.action.USB_DEVICE_DETACHED  - 订阅者所需权限：无 |  
| COMMON_EVENT_USB_ACCESSORY_ATTACHED<sup>(deprecated)</sup> | usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USB_ACCESSORY_ATTACHED替代。<br>（预留事件，暂未支持）提示已连接USB附件。  - 值：usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED  - 订阅者所需权限：无 |  
| COMMON_EVENT_USB_ACCESSORY_DETACHED<sup>(deprecated)</sup> | usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_USB_ACCESSORY_DETACHED替代。<br>（预留事件，暂未支持）提示USB附件被卸载。  - 值：usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED  - 订阅者所需权限：无 |  
| COMMON_EVENT_DISK_REMOVED<sup>(deprecated)</sup> | usual.event.data.DISK_REMOVED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DISK_REMOVED替代。<br>（预留事件，暂未支持）提示外部存储设备状态变更为移除。  - 值：usual.event.data.DISK_REMOVED  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_UNMOUNTED<sup>(deprecated)</sup> | usual.event.data.DISK_UNMOUNTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DISK_UNMOUNTED替代。<br>（预留事件，暂未支持）提示外部存储设备状态变更为卸载。  - 值：usual.event.data.DISK_UNMOUNTED  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_MOUNTED<sup>(deprecated)</sup> | usual.event.data.DISK_MOUNTED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DISK_MOUNTED替代。<br>（预留事件，暂未支持）提示外部存储设备状态变更为挂载。  - 值：usual.event.data.DISK_MOUNTED  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_BAD_REMOVAL<sup>(deprecated)</sup> | usual.event.data.DISK_BAD_REMOVAL | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DISK_BAD_REMOVAL替代。<br>（预留事件，暂未支持）提示外部存储设备在挂载状态下被移除。  - 值：usual.event.data.DISK_BAD_REMOVAL  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_UNMOUNTABLE<sup>(deprecated)</sup> | usual.event.data.DISK_UNMOUNTABLE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DISK_UNMOUNTABLE替代。<br>（预留事件，暂未支持）提示外部存储设备在插卡情况下无法挂载。  - 值：usual.event.data.DISK_UNMOUNTABLE  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_EJECT<sup>(deprecated)</sup> | usual.event.data.DISK_EJECT | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_DISK_EJECT替代。<br>（预留事件，暂未支持）提示用户已作出弹出外部存储介质的操作（系统软件层面的交互操作，非直接物理弹出）。  - 值：usual.event.data.DISK_EJECT  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED<sup>(deprecated)</sup> | usual.event.data.VISIBLE_ACCOUNTS_UPDATED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED替代。<br>（预留事件，暂未支持）提示帐户发生可见性的更改。  - 值：usual.event.data.VISIBLE_ACCOUNTS_UPDATED  - 订阅者所需权限：ohos.permission.GET_APP_ACCOUNTS |  
| COMMON_EVENT_ACCOUNT_DELETED<sup>(deprecated)</sup> | usual.event.data.ACCOUNT_DELETED | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_ACCOUNT_DELETED替代。<br>（预留事件，暂未支持）提示有帐户被删除。  - 值：usual.event.data.ACCOUNT_DELETED  - 订阅者所需权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS |  
| COMMON_EVENT_FOUNDATION_READY<sup>(deprecated)</sup> | common.event.FOUNDATION_READY | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_FOUNDATION_READY替代。<br>（预留事件，暂未支持）提示foundation已准备好。  - 值：usual.event.data.FOUNDATION_READY  - 订阅者所需权限：ohos.permission.RECEIVER_STARTUP_COMPLETED |  
| COMMON_EVENT_AIRPLANE_MODE_CHANGED<sup>(deprecated)</sup> | usual.event.AIRPLANE_MODE | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_AIRPLANE_MODE_CHANGED替代。<br>提示设备飞行模式发生了切换。  - 值：usual.event.AIRPLANE_MODE  - 订阅者所需权限：无 |  
| COMMON_EVENT_SPLIT_SCREEN<sup>(deprecated)</sup> | common.event.SPLIT_SCREEN | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.commonEventManager/commonEventManager.Support#COMMON_EVENT_SPLIT_SCREEN替代。<br>提示分屏。 |  
