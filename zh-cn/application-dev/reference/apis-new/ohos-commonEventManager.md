# @ohos.commonEventManager    
本模块提供了公共事件相关的能力，包括发布公共事件、订阅公共事件、以及退订公共事件。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import commonEventManager from '@ohos.commonEventManager'    
```  
    
## publish    
发布公共事件，并在发布后执行相应的回调函数。  
 **调用形式：**     
    
- publish(event: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 表示要发送的公共事件。 |  
| options | CommonEventPublishData | true | 表示发布公共事件的属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1500004 | not System services. |  
| 1500007 | error sending message to Common Event Service. |  
| 1500008 | Common Event Service does not complete initialization. |  
| 1500009 | error obtaining system parameters. |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
  
//发布公共事件回调  
function publishCB(err:Base.BusinessError) {  
    if (err) {  
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info("publish");  
    }  
}  
  
//发布公共事件  
try {  
    CommonEventManager.publish("event", publishCB);  
} catch (error) {  
    let err:Base.BusinessError = error as Base.BusinessError;  
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);  
}  
    
```    
  
    
## createSubscriber    
以Promise形式创建订阅者。  
 **调用形式：**     
    
- createSubscriber(     subscribeInfo: CommonEventSubscribeInfo,     callback: AsyncCallback\<CommonEventSubscriber>   ): void    
起始版本： 9    
- createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscribeInfo | CommonEventSubscribeInfo | true | 表示订阅信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示创建订阅者的回调方法。 |  
| Promise<CommonEventSubscriber> | 返回订阅者对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
  
let subscriber:CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
  
//订阅者信息  
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {  
    events: ["event"]  
};  
  
//创建订阅者回调  
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {  
    if(!err) {  
        console.info("createSubscriber");  
        subscriber = commonEventSubscriber;  
    } else {  
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);  
    }  
}  
  
//创建订阅者  
try {  
    CommonEventManager.createSubscriber(subscribeInfo, createCB);  
} catch (error) {  
    let err:Base.BusinessError = error as Base.BusinessError;  
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import Base from '@ohos.base';  
let subscriber:CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
//订阅者信息let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {events: ["event"]};  
//创建订阅者CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:CommonEventManager.CommonEventSubscriber) => {    console.info("createSubscriber");    subscriber = commonEventSubscriber;}).catch((err:Base.BusinessError) => {    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);});    
```    
  
    
## createSubscriberSync<sup>(10+)</sup>    
createSubscriber的同步接口。  
 **调用形式：**     
- createSubscriberSync(subscribeInfo: CommonEventSubscribeInfo): CommonEventSubscriber  
  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscribeInfo | CommonEventSubscribeInfo | true | 表示订阅信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CommonEventSubscriber | 返回订阅者对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
  
let subscriber: CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
  
//订阅者信息  
let subscribeInfo: CommonEventManager.CommonEventSubscribeInfo = {  
  events: ["event"]  
};  
  
//创建订阅者  
try {  
    subscriber = CommonEventManager.createSubscriberSync(subscribeInfo);  
} catch (error) {  
    let err:Base.BusinessError = error as Base.BusinessError;  
    console.error(`createSubscriberSync failed, code is ${err.code}, message is ${err.message}`);  
}  
    
```    
  
    
## subscribe    
以回调形式订阅公共事件。  
 **调用形式：**     
    
- subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber | CommonEventSubscriber | true | 表示订阅者对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示接收公共事件数据的回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 1500007 | error sending message to Common Event Service. |  
| 1500008 | Common Event Service does not complete initialization. |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
  
let subscriber:CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
  
//订阅者信息  
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {  
    events: ["event"]  
};  
  
//订阅公共事件回调  
function SubscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {  
    if (err) {  
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info("subscribe ");  
    }  
}  
  
//创建订阅者回调  
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {  
    if(!err) {  
        console.info("createSubscriber");  
        subscriber = commonEventSubscriber;  
        //订阅公共事件  
        try {  
            CommonEventManager.subscribe(subscriber, SubscribeCB);  
        } catch (error) {  
            let err:Base.BusinessError = error as Base.BusinessError;  
            console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);  
        }  
    } else {  
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);  
    }  
}  
  
//创建订阅者  
try {  
    CommonEventManager.createSubscriber(subscribeInfo, createCB);  
} catch (error) {  
    let err:Base.BusinessError = error as Base.BusinessError;  
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);  
}  
    
```    
  
    
## unsubscribe    
以回调形式取消订阅公共事件。  
 **调用形式：**     
    
- unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscriber | CommonEventSubscriber | true | 表示订阅者对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示取消订阅的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 1500007 | error sending message to Common Event Service. |  
| 1500008 | Common Event Service does not complete initialization. |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
  
let subscriber:CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作  
//订阅者信息  
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {  
    events: ["event"]  
};  
//订阅公共事件回调  
function subscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {  
    if (err) {  
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info("subscribe");  
    }  
}  
//创建订阅者回调  
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {  
    if (err) {  
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info("createSubscriber");  
        subscriber = commonEventSubscriber;  
        //订阅公共事件  
        try {  
            CommonEventManager.subscribe(subscriber, subscribeCB);  
        } catch (error) {  
            let err:Base.BusinessError = error as Base.BusinessError;  
            console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);  
        }  
    }  
}  
//取消订阅公共事件回调  
function unsubscribeCB(err:Base.BusinessError) {  
    if (err) {  
        console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info("unsubscribe");  
    }  
}  
//创建订阅者  
try {  
    CommonEventManager.createSubscriber(subscribeInfo, createCB);  
} catch (error) {  
    let err:Base.BusinessError = error as Base.BusinessError;  
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);  
}  
  
//取消订阅公共事件  
//等待异步接口subscribe执行完毕，开发者根据实际业务选择是否需要添加setTimeout  
setTimeout(() => {  
  try {  
    CommonEventManager.unsubscribe(subscriber, unsubscribeCB);  
  } catch (error) {  
    let err:Base.BusinessError = error as Base.BusinessError;  
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);  
  }  
}, 500);  
    
```    
  
    
## Support    
    
 **系统能力:**  SystemCapability.Notification.CommonEvent    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COMMON_EVENT_BOOT_COMPLETED | usual.event.BOOT_COMPLETED | 表示用户已完成引导并加载系统的公共事件的操作。 |  
| COMMON_EVENT_LOCKED_BOOT_COMPLETED | usual.event.LOCKED_BOOT_COMPLETED | （预留事件，暂未支持）表示用户已完成引导，系统已加载，但屏幕仍锁定的公共事件的操作。  - 值： usual.event.LOCKED_BOOT_COMPLETED  - 订阅者所需权限： ohos.permission.RECEIVER_STARTUP_COMPLETED |  
| COMMON_EVENT_SHUTDOWN | usual.event.SHUTDOWN | 表示设备正在关闭并将继续最终关闭的公共事件的操作。 |  
| COMMON_EVENT_BATTERY_CHANGED | usual.event.BATTERY_CHANGED | 表示电池充电状态、电平和其他信息发生变化的公共事件的动作。 |  
| COMMON_EVENT_BATTERY_LOW | usual.event.BATTERY_LOW | 表示电池电量低的普通事件的动作。 |  
| COMMON_EVENT_BATTERY_OKAY | usual.event.BATTERY_OKAY | 表示电池退出低电平状态的公共事件的动作。 |  
| COMMON_EVENT_POWER_CONNECTED | usual.event.POWER_CONNECTED | 设备连接到外部电源的公共事件的动作。 |  
| COMMON_EVENT_POWER_DISCONNECTED | usual.event.POWER_DISCONNECTED | 设备与外部电源断开的公共事件的动作。 |  
| COMMON_EVENT_SCREEN_OFF | usual.event.SCREEN_OFF | 表示设备屏幕关闭且设备处于睡眠状态的普通事件的动作。 |  
| COMMON_EVENT_SCREEN_ON | usual.event.SCREEN_ON | 表示设备屏幕打开且设备处于交互状态的公共事件的操作。 |  
| COMMON_EVENT_THERMAL_LEVEL_CHANGED | usual.event.THERMAL_LEVEL_CHANGED | 表示设备热状态的公共事件的动作。 |  
| COMMON_EVENT_USER_PRESENT<sup>(deprecated)</sup> | usual.event.USER_PRESENT | 从API version 9 开始支持，从API version 10 开始废弃。<br>（预留事件，暂未支持）用户解锁设备的公共事件的动作。  - 值： usual.event.USER_PRESENT  - 订阅者所需权限： 无 |  
| COMMON_EVENT_TIME_TICK | usual.event.TIME_TICK | 表示系统时间更改的公共事件的动作。 |  
| COMMON_EVENT_TIME_CHANGED | usual.event.TIME_CHANGED | 设置系统时间的公共事件的动作。 |  
| COMMON_EVENT_DATE_CHANGED | usual.event.DATE_CHANGED | （预留事件，暂未支持）表示系统日期已更改的公共事件的动作。  - 值： usual.event.DATE_CHANGED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_TIMEZONE_CHANGED | usual.event.TIMEZONE_CHANGED | 表示系统时区更改的公共事件的动作。 |  
| COMMON_EVENT_CLOSE_SYSTEM_DIALOGS | usual.event.CLOSE_SYSTEM_DIALOGS | （预留事件，暂未支持）表示用户关闭临时系统对话框的公共事件的动作。  - 值： usual.event.CLOSE_SYSTEM_DIALOGS  - 订阅者所需权限： 无 |  
| COMMON_EVENT_PACKAGE_ADDED | usual.event.PACKAGE_ADDED | 设备上已安装新应用包的公共事件的动作。 |  
| COMMON_EVENT_PACKAGE_REPLACED | usual.event.PACKAGE_REPLACED | （预留事件，暂未支持）表示已安装的应用程序包的新版本已替换设备上的旧版本的公共事件的操作。  - 值： usual.event.PACKAGE_REPLACED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_MY_PACKAGE_REPLACED | usual.event.MY_PACKAGE_REPLACED | （预留事件，暂未支持）表示应用程序包的新版本已取代前一个版本的公共事件的操作。  - 值： usual.event.MY_PACKAGE_REPLACED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_PACKAGE_REMOVED | usual.event.PACKAGE_REMOVED | 表示已从设备卸载已安装的应用程序，但应用程序数据保留的公共事件的操作。 |  
| COMMON_EVENT_BUNDLE_REMOVED | usual.event.BUNDLE_REMOVED | （预留事件，暂未支持）表示已从设备中卸载已安装的捆绑包，但应用程序数据仍保留的公共事件的操作。  - 值： usual.event.BUNDLE_REMOVED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_PACKAGE_FULLY_REMOVED | usual.event.PACKAGE_FULLY_REMOVED | （预留事件，暂未支持）表示已从设备中完全卸载已安装的应用程序（包括应用程序数据和代码）的公共事件的操作。  - 值： usual.event.PACKAGE_FULLY_REMOVED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_PACKAGE_CHANGED | usual.event.PACKAGE_CHANGED | 表示应用包已更改的公共事件的动作（例如，包中的组件已启用或禁用）。 |  
| COMMON_EVENT_PACKAGE_RESTARTED | usual.event.PACKAGE_RESTARTED | 表示用户重启应用包并杀死其所有进程的普通事件的动作。 |  
| COMMON_EVENT_PACKAGE_DATA_CLEARED | usual.event.PACKAGE_DATA_CLEARED | 用户清除应用包数据的公共事件的动作。 |  
| COMMON_EVENT_PACKAGE_CACHE_CLEARED | usual.event.PACKAGE_CACHE_CLEARED | 用户清除应用包缓存数据的公共事件的动作。 |  
| COMMON_EVENT_PACKAGES_SUSPENDED | usual.event.PACKAGES_SUSPENDED | （预留事件，暂未支持）表示应用包已挂起的公共事件的动作。  - 值： usual.event.PACKAGES_SUSPENDED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_PACKAGES_UNSUSPENDED | usual.event.PACKAGES_UNSUSPENDED | （预留事件，暂未支持）表示应用包未挂起的公共事件的动作。  - 值： usual.event.PACKAGES_UNSUSPENDED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_MY_PACKAGE_SUSPENDED | usual.event.MY_PACKAGE_SUSPENDED | 应用包被挂起的公共事件的动作。  - 值： usual.event.MY_PACKAGE_SUSPENDED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_MY_PACKAGE_UNSUSPENDED | usual.event.MY_PACKAGE_UNSUSPENDED | 表示应用包未挂起的公共事件的动作。  - 值： usual.event.MY_PACKAGE_UNSUSPENDED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_UID_REMOVED | usual.event.UID_REMOVED | （预留事件，暂未支持）表示用户ID已从系统中删除的公共事件的动作。  - 值： usual.event.UID_REMOVED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_PACKAGE_FIRST_LAUNCH | usual.event.PACKAGE_FIRST_LAUNCH | （预留事件，暂未支持）表示首次启动已安装应用程序的公共事件的动作。  - 值： usual.event.PACKAGE_FIRST_LAUNCH  - 订阅者所需权限： 无 |  
| COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION | usual.event.PACKAGE_NEEDS_VERIFICATION | （预留事件，暂未支持）表示应用需要系统校验的公共事件的动作。  - 值： usual.event.PACKAGE_NEEDS_VERIFICATION  - 订阅者所需权限： 无。 |  
| COMMON_EVENT_PACKAGE_VERIFIED | usual.event.PACKAGE_VERIFIED | （预留事件，暂未支持）表示应用已被系统校验的公共事件的动作。  - 值： usual.event.PACKAGE_VERIFIED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE | usual.event.EXTERNAL_APPLICATIONS_AVAILABLE | （预留事件，暂未支持）表示安装在外部存储上的应用程序对系统可用的公共事件的操作。  - 值： usual.event.EXTERNAL_APPLICATIONS_AVAILABLE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE | usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE | （预留事件，暂未支持）表示安装在外部存储上的应用程序对系统不可用的公共事件的操作。  - 值： usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_CONFIGURATION_CHANGED | usual.event.CONFIGURATION_CHANGED | （预留事件，暂未支持）表示设备状态（例如，方向和区域设置）已更改的公共事件的操作。  - 值： usual.event.CONFIGURATION_CHANGED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_LOCALE_CHANGED | usual.event.LOCALE_CHANGED | 表示设备区域设置已更改的公共事件的操作。  - 值： usual.event.LOCALE_CHANGED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_MANAGE_PACKAGE_STORAGE | usual.event.MANAGE_PACKAGE_STORAGE | （预留事件，暂未支持）设备存储空间不足的公共事件的动作。  - 值： usual.event.MANAGE_PACKAGE_STORAGE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_DRIVE_MODE | common.event.DRIVE_MODE | （预留事件，暂未支持）表示系统处于驾驶模式的公共事件的动作。  - 值： common.event.DRIVE_MODE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_HOME_MODE | common.event.HOME_MODE | （预留事件，暂未支持）表示系统处于HOME模式的公共事件的动作。  - 值： common.event.HOME_MODE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_OFFICE_MODE | common.event.OFFICE_MODE | （预留事件，暂未支持）表示系统处于办公模式的公共事件的动作。  - 值： common.event.OFFICE_MODE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_USER_STARTED | usual.event.USER_STARTED | （预留事件，暂未支持）表示用户已启动的公共事件的动作。  - 值： usual.event.USER_STARTED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_USER_BACKGROUND | usual.event.USER_BACKGROUND | （预留事件，暂未支持）表示用户已被带到后台的公共事件的动作。  - 值： usual.event.USER_BACKGROUND  - 订阅者所需权限： 无 |  
| COMMON_EVENT_USER_FOREGROUND | usual.event.USER_FOREGROUND | （预留事件，暂未支持）表示用户已被带到前台的公共事件的动作。  - 值： usual.event.USER_FOREGROUND  - 订阅者所需权限： 无 |  
| COMMON_EVENT_USER_SWITCHED | usual.event.USER_SWITCHED | 表示用户切换正在发生的公共事件的动作。 |  
| COMMON_EVENT_USER_STARTING | usual.event.USER_STARTING | （预留事件，暂未支持）表示要启动用户的公共事件的动作。  - 值： usual.event.USER_STARTING  - 订阅者所需权限： ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS |  
| COMMON_EVENT_USER_UNLOCKED | usual.event.USER_UNLOCKED | 设备重启后解锁时，当前用户的凭据加密存储已解锁的公共事件的动作。  - 值： usual.event.USER_UNLOCKED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_USER_STOPPING | usual.event.USER_STOPPING | （预留事件，暂未支持）表示要停止用户的公共事件的动作。  - 值： usual.event.USER_STOPPING  - 订阅者所需权限： ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS |  
| COMMON_EVENT_USER_STOPPED | usual.event.USER_STOPPED | （预留事件，暂未支持）表示用户已停止的公共事件的动作。  - 值： usual.event.USER_STOPPED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN | common.event.DISTRIBUTED_ACCOUNT_LOGIN | （预留事件，暂未支持）表示分布式帐号登录成功的动作。 |  
| COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT | common.event.DISTRIBUTED_ACCOUNT_LOGOUT | （预留事件，暂未支持）表示分布式帐号登出成功的动作。 |  
| COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID | common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID | （预留事件，暂未支持）表示分布式帐号token令牌无效的动作。 |  
| COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF | common.event.DISTRIBUTED_ACCOUNT_LOGOFF | （预留事件，暂未支持）表示分布式帐号注销的动作。 |  
| COMMON_EVENT_WIFI_POWER_STATE | usual.event.wifi.POWER_STATE | Wi-Fi状态公共事件的动作，如启用和禁用。 |  
| COMMON_EVENT_WIFI_SCAN_FINISHED | usual.event.wifi.SCAN_FINISHED | 表示Wi-Fi接入点已被扫描并证明可用的公共事件的操作。 |  
| COMMON_EVENT_WIFI_RSSI_VALUE | usual.event.wifi.RSSI_VALUE | 表示Wi-Fi信号强度（RSSI）改变的公共事件的动作。 |  
| COMMON_EVENT_WIFI_CONN_STATE | usual.event.wifi.CONN_STATE | Wi-Fi连接状态发生改变的公共事件的动作 |  
| COMMON_EVENT_WIFI_HOTSPOT_STATE | usual.event.wifi.HOTSPOT_STATE | Wi-Fi热点状态的公共事件的动作，如启用或禁用。 |  
| COMMON_EVENT_WIFI_AP_STA_JOIN | usual.event.wifi.WIFI_HS_STA_JOIN | 客户端加入当前设备Wi-Fi热点的普通事件的动作。 |  
| COMMON_EVENT_WIFI_AP_STA_LEAVE | usual.event.wifi.WIFI_HS_STA_LEAVE | 客户端已断开与当前设备Wi-Fi热点的连接的公共事件的动作。 |  
| COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE | usual.event.wifi.mplink.STATE_CHANGE | 表示MPLink（增强Wi-Fi功能）状态已更改的公共事件的动作。 |  
| COMMON_EVENT_WIFI_P2P_CONN_STATE | usual.event.wifi.p2p.CONN_STATE_CHANGE | Wi-Fi P2P连接状态改变的公共事件的动作。 |  
| COMMON_EVENT_WIFI_P2P_STATE_CHANGED | usual.event.wifi.p2p.STATE_CHANGE | Wi-Fi P2P状态公共事件的动作，如启用和禁用。 |  
| COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED | usual.event.wifi.p2p.DEVICES_CHANGE | Wi-Fi P2P对等体状态变化。 |  
| COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED | usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE | Wi-Fi P2P发现状态变化。 |  
| COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED | usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE | Wi-Fi P2P当前设备状态变化。 |  
| COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED | usual.event.wifi.p2p.GROUP_STATE_CHANGED | Wi-Fi P2P群组信息已更改。 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE | usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE | （预留事件，暂未支持）蓝牙免提通信连接状态公共事件的动作。  - 值： usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE | usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE | （预留事件，暂未支持）表示连接到蓝牙免提的设备处于活动状态的公共事件的动作。  - 值： usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE | usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE | （预留事件，暂未支持）表示蓝牙A2DP连接状态已更改的公共事件的动作。  - 值： usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE | usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE | （预留事件，暂未支持）蓝牙A2DP连接状态公共事件的动作。  - 值： usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE | usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE | （预留事件，暂未支持）表示使用蓝牙A2DP连接的设备处于活动状态的公共事件的动作。  - 值： usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE | usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE | （预留事件，暂未支持）蓝牙A2DP播放状态改变的普通事件的动作。  - 值： usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE | usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE | （预留事件，暂未支持）表示蓝牙A2DP的AVRCP连接状态已更改的公共事件的动作。  - 值： usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE | usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE | （预留事件，暂未支持）表示蓝牙A2DP音频编解码状态更改的公共事件的动作。  - 值： usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED | usual.event.bluetooth.remotedevice.DISCOVERED | （预留事件，暂未支持）表示发现远程蓝牙设备的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.DISCOVERED  - 订阅者所需权限： ohos.permission.LOCATION和ohos.permission.USE_BLUETOOTH。 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE | usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE | （预留事件，暂未支持）表示远程蓝牙设备的蓝牙类别已更改的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED | usual.event.bluetooth.remotedevice.ACL_CONNECTED | （预留事件，暂未支持）表示已与远程蓝牙设备建立低级别（ACL）连接的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.ACL_CONNECTED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED | usual.event.bluetooth.remotedevice.ACL_DISCONNECTED | （预留事件，暂未支持）表示低电平（ACL）连接已从远程蓝牙设备断开的普通事件的动作。  - 值： usual.event.bluetooth.remotedevice.ACL_DISCONNECTED  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE | usual.event.bluetooth.remotedevice.NAME_UPDATE | （预留事件，暂未支持）表示远程蓝牙设备的友好名称首次被检索或自上次检索以来被更改的公共事件的操作。  - 值： usual.event.bluetooth.remotedevice.NAME_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE | usual.event.bluetooth.remotedevice.PAIR_STATE | （预留事件，暂未支持）远程蓝牙设备连接状态更改的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.PAIR_STATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE | usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE | （预留事件，暂未支持）表示远程蓝牙设备的电池电量首次被检索或自上次检索以来被更改的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT | usual.event.bluetooth.remotedevice.SDP_RESULT | （预留事件，暂未支持）远程蓝牙设备SDP状态公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.SDP_RESULT  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE | usual.event.bluetooth.remotedevice.UUID_VALUE | （预留事件，暂未支持）远程蓝牙设备UUID连接状态公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.UUID_VALUE  - 订阅者所需权限： ohos.permission.DISCOVER_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ | usual.event.bluetooth.remotedevice.PAIRING_REQ | （预留事件，暂未支持）表示远程蓝牙设备配对请求的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.PAIRING_REQ  - 订阅者所需权限： ohos.permission.DISCOVER_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL | usual.event.bluetooth.remotedevice.PAIRING_CANCEL | （预留事件，暂未支持）取消蓝牙配对的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.PAIRING_CANCEL  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ | usual.event.bluetooth.remotedevice.CONNECT_REQ | （预留事件，暂未支持）表示远程蓝牙设备连接请求的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.CONNECT_REQ  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY | usual.event.bluetooth.remotedevice.CONNECT_REPLY | （预留事件，暂未支持）表示远程蓝牙设备连接请求响应的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.CONNECT_REPLY  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL | usual.event.bluetooth.remotedevice.CONNECT_CANCEL | （预留事件，暂未支持）表示取消与远程蓝牙设备的连接的公共事件的动作。  - 值： usual.event.bluetooth.remotedevice.CONNECT_CANCEL  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE | usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE | （预留事件，暂未支持）表示蓝牙免提连接状态已更改的公共事件的动作。  - 值： usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE | usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE | （预留事件，暂未支持）表示蓝牙免提音频状态已更改的公共事件的动作。  - 值： usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT | usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT | （预留事件，暂未支持）表示蓝牙免提音频网关状态已更改的公共事件的动作。  - 值： usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE | usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE | （预留事件，暂未支持）表示蓝牙免提呼叫状态已更改的公共事件的动作。  - 值： usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE | usual.event.bluetooth.host.STATE_UPDATE | （预留事件，暂未支持）表示蓝牙适配器状态已更改的公共事件的操作，例如蓝牙已打开或关闭。  - 值： usual.event.bluetooth.host.STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE | usual.event.bluetooth.host.REQ_DISCOVERABLE | （预留事件，暂未支持）表示用户允许扫描蓝牙请求的公共事件的动作。  - 值： usual.event.bluetooth.host.REQ_DISCOVERABLE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE | usual.event.bluetooth.host.REQ_ENABLE | （预留事件，暂未支持）表示用户打开蓝牙请求的公共事件的动作  - 值： usual.event.bluetooth.host.REQ_ENABLE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH。 |  
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE | usual.event.bluetooth.host.REQ_DISABLE | （预留事件，暂未支持）表示用户关闭蓝牙请求的公共事件的动作。  - 值： usual.event.bluetooth.host.REQ_DISABLE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE | usual.event.bluetooth.host.SCAN_MODE_UPDATE | （预留事件，暂未支持）设备蓝牙扫描模式更改的公共事件的动作。  - 值： usual.event.bluetooth.host.SCAN_MODE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED | usual.event.bluetooth.host.DISCOVERY_STARTED | （预留事件，暂未支持）设备上已启动蓝牙扫描的公共事件的动作。  - 值： usual.event.bluetooth.host.DISCOVERY_STARTED  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED | usual.event.bluetooth.host.DISCOVERY_FINISHED | （预留事件，暂未支持）设备上蓝牙扫描完成的公共事件的动作。  - 值： usual.event.bluetooth.host.DISCOVERY_FINISHED  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE | usual.event.bluetooth.host.NAME_UPDATE | （预留事件，暂未支持）指示设备蓝牙适配器名称已更改的公共事件的操作。  - 值： usual.event.bluetooth.host.NAME_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE | usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE | （预留事件，暂未支持）表示蓝牙A2DP宿连接状态已更改的公共事件的动作。  - 值： usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE | usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE | （预留事件，暂未支持）蓝牙A2DP宿播放状态改变的普通事件的动作。  - 值： usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE | usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE | （预留事件，暂未支持）表示蓝牙A2DP宿的音频状态已更改的公共事件的动作。  - 值： usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE  - 订阅者所需权限： ohos.permission.USE_BLUETOOTH |  
| COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED | usual.event.nfc.action.ADAPTER_STATE_CHANGED | 指示设备NFC状态已更改的公共事件的操作。 |  
| COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED | usual.event.nfc.action.RF_FIELD_ON_DETECTED | 检测到NFC场强进入的公共事件。 |  
| COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED | usual.event.nfc.action.RF_FIELD_OFF_DETECTED | 检测到NFC场强离开的公共事件。 |  
| COMMON_EVENT_DISCHARGING | usual.event.DISCHARGING | 表示系统停止为电池充电的公共事件的动作。 |  
| COMMON_EVENT_CHARGING | usual.event.CHARGING | 表示系统开始为电池充电的公共事件的动作。 |  
| COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED | usual.event.DEVICE_IDLE_MODE_CHANGED | 表示设备进入充电空闲模式的公共事件的动作。 |  
| COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED<sup>(10+)</sup> | usual.event.CHARGE_IDLE_MODE_CHANGED | 表示系统待机空闲模式已更改的公共事件的动作。 |  
| COMMON_EVENT_POWER_SAVE_MODE_CHANGED | usual.event.POWER_SAVE_MODE_CHANGED | 表示系统节能模式更改的公共事件的动作。 |  
| COMMON_EVENT_USER_ADDED | usual.event.USER_ADDED | 表示用户已添加到系统中的公共事件的动作。 |  
| COMMON_EVENT_USER_REMOVED | usual.event.USER_REMOVED | 表示用户已从系统中删除的公共事件的动作。 |  
| COMMON_EVENT_ABILITY_ADDED | common.event.ABILITY_ADDED | （预留事件，暂未支持）表示已添加能力的公共事件的动作。  - 值： usual.event.ABILITY_ADDED  - 订阅者所需权限： ohos.permission.LISTEN_BUNDLE_CHANGE |  
| COMMON_EVENT_ABILITY_REMOVED | common.event.ABILITY_REMOVED | （预留事件，暂未支持）表示已删除能力的公共事件的动作。  - 值： usual.event.ABILITY_REMOVED  - 订阅者所需权限： ohos.permission.LISTEN_BUNDLE_CHANGE |  
| COMMON_EVENT_ABILITY_UPDATED | common.event.ABILITY_UPDATED | （预留事件，暂未支持）表示能力已更新的公共事件的动作。  - 值： usual.event.ABILITY_UPDATED  - 订阅者所需权限： ohos.permission.LISTEN_BUNDLE_CHANGE |  
| COMMON_EVENT_LOCATION_MODE_STATE_CHANGED | usual.event.location.MODE_STATE_CHANGED | （预留事件，暂未支持）表示系统定位模式已更改的公共事件的动作。  - 值： usual.event.location.MODE_STATE_CHANGED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_SLEEP | common.event.IVI_SLEEP | （预留事件，暂未支持）表示表示车辆的车载信息娱乐（IVI）系统正在休眠的常见事件的动作。  - 值： common.event.IVI_SLEEP  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_PAUSE | common.event.IVI_PAUSE | （预留事件，暂未支持）表示IVI已休眠，并通知应用程序停止播放。  - 值： common.event.IVI_PAUSE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_STANDBY | common.event.IVI_STANDBY | （预留事件，暂未支持）表示第三方应用暂停当前工作的公共事件的动作。  - 值： common.event.IVI_STANDBY  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_LASTMODE_SAVE | common.event.IVI_LASTMODE_SAVE | （预留事件，暂未支持）表示第三方应用保存其最后一个模式的公共事件的动作。  - 值： common.event.IVI_LASTMODE_SAVE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_VOLTAGE_ABNORMAL | common.event.IVI_VOLTAGE_ABNORMAL | （预留事件，暂未支持）表示车辆电源系统电压异常的公共事件的动作。  - 值： common.event.IVI_VOLTAGE_ABNORMAL  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_HIGH_TEMPERATURE | common.event.IVI_HIGH_TEMPERATURE | （预留事件，暂未支持）表示IVI温度过高。  - 值： common.event.IVI_HIGH_TEMPERATURE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_EXTREME_TEMPERATURE | common.event.IVI_EXTREME_TEMPERATURE | （预留事件，暂未支持）表示IVI温度极高。  - 值： common.event.IVI_EXTREME_TEMPERATURE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL | common.event.IVI_TEMPERATURE_ABNORMAL | （预留事件，暂未支持）表示车载系统具有极端温度的常见事件的动作。  - 值： common.event.IVI_TEMPERATURE_ABNORMAL  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_VOLTAGE_RECOVERY | common.event.IVI_VOLTAGE_RECOVERY | （预留事件，暂未支持）表示车辆电源系统电压恢复正常的公共事件的动作。  - 值： common.event.IVI_VOLTAGE_RECOVERY  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_TEMPERATURE_RECOVERY | common.event.IVI_TEMPERATURE_RECOVERY | （预留事件，暂未支持）表示车载系统温度恢复正常的公共事件的动作。  - 值： common.event.IVI_TEMPERATURE_RECOVERY  - 订阅者所需权限： 无 |  
| COMMON_EVENT_IVI_ACTIVE | common.event.IVI_ACTIVE | （预留事件，暂未支持）表示电池服务处于活动状态的公共事件的动作。  - 值： common.event.IVI_ACTIVE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_USB_STATE | usual.event.hardware.usb.action.USB_STATE | 表示USB设备状态发生变化的公共事件。 |  
| COMMON_EVENT_USB_PORT_CHANGED | usual.event.hardware.usb.action.USB_PORT_CHANGED | 表示用户设备的USB端口状态发生改变的公共事件。 |  
| COMMON_EVENT_USB_DEVICE_ATTACHED | usual.event.hardware.usb.action.USB_DEVICE_ATTACHED | 当用户设备作为USB主机时，USB设备已挂载的公共事件的动作。 |  
| COMMON_EVENT_USB_DEVICE_DETACHED | usual.event.hardware.usb.action.USB_DEVICE_DETACHED | 当用户设备作为USB主机时，USB设备被卸载的公共事件的动作。 |  
| COMMON_EVENT_USB_ACCESSORY_ATTACHED | usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED | （预留事件，暂未支持）表示已连接USB附件的公共事件的动作。 |  
| COMMON_EVENT_USB_ACCESSORY_DETACHED | usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED | （预留事件，暂未支持）表示USB附件被卸载的公共事件的动作。 |  
| COMMON_EVENT_DISK_REMOVED | usual.event.data.DISK_REMOVED | （预留事件，暂未支持）外部存储设备状态变更为移除时发送此公共事件。  - 值： usual.event.data.DISK_BAD_REMOVAL  - 订阅者所需权限： ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_UNMOUNTED | usual.event.data.DISK_UNMOUNTED | （预留事件，暂未支持）部存储设备状态变更为卸载时发送此公共事件。  - 值： usual.event.data.DISK_UNMOUNTABLE  - 订阅者所需权限： ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_MOUNTED | usual.event.data.DISK_MOUNTED | （预留事件，暂未支持）外部存储设备状态变更为挂载时发送此公共事件。  - 值： usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED  - 订阅者所需权限： ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_BAD_REMOVAL | usual.event.data.DISK_BAD_REMOVAL | （预留事件，暂未支持）外部存储设备状态变更为挂载状态下移除时发送此公共事件。  - 值： usual.event.data.DISK_REMOVED  - 订阅者所需权限： ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_UNMOUNTABLE | usual.event.data.DISK_UNMOUNTABLE | （预留事件，暂未支持）外部存储设备状态变更为插卡情况下无法挂载时发送此公共事件。  - 值： usual.event.data.DISK_UNMOUNTED  - 订阅者所需权限： ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_DISK_EJECT | usual.event.data.DISK_EJECT | （预留事件，暂未支持）用户已表示希望删除外部存储介质时发送此公共事件。  - 值： usual.event.data.DISK_EJECT  - 订阅者所需权限： ohos.permission.STORAGE_MANAGER |  
| COMMON_EVENT_VOLUME_REMOVED | usual.event.data.VOLUME_REMOVED | 外部存储设备状态变更为移除时发送此公共事件。 |  
| COMMON_EVENT_VOLUME_UNMOUNTED | usual.event.data.VOLUME_UNMOUNTED | 外部存储设备状态变更为卸载时发送此公共事件。 |  
| COMMON_EVENT_VOLUME_MOUNTED | usual.event.data.VOLUME_MOUNTED | 外部存储设备状态变更为挂载时发送此公共事件。 |  
| COMMON_EVENT_VOLUME_BAD_REMOVAL | usual.event.data.VOLUME_BAD_REMOVAL | 外部存储设备状态变更为挂载状态下移除时发送此公共事件。 |  
| COMMON_EVENT_VOLUME_EJECT | usual.event.data.VOLUME_EJECT | 用户已表示希望删除外部存储介质时发送此公共事件。 |  
| COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED | usual.event.data.VISIBLE_ACCOUNTS_UPDATED | （预留事件，暂未支持）表示帐户可见更改的公共事件的动作。  - 值： usual.event.data.VISIBLE_ACCOUNTS_UPDATED  - 订阅者所需权限： ohos.permission.GET_APP_ACCOUNTS |  
| COMMON_EVENT_ACCOUNT_DELETED | usual.event.data.ACCOUNT_DELETED | （预留事件，暂未支持）删除帐户的公共事件的动作。  - 值： usual.event.data.ACCOUNT_DELETED  - 订阅者所需权限： ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS |  
| COMMON_EVENT_FOUNDATION_READY | common.event.FOUNDATION_READY | （预留事件，暂未支持）表示foundation已准备好的公共事件的动作。  - 值： usual.event.data.FOUNDATION_READY  - 订阅者所需权限： ohos.permission.RECEIVER_STARTUP_COMPLETED |  
| COMMON_EVENT_AIRPLANE_MODE_CHANGED | usual.event.AIRPLANE_MODE | 表示设备飞行模式已更改的公共事件的动作。  - 值： usual.event.AIRPLANE_MODE  - 订阅者所需权限： 无 |  
| COMMON_EVENT_SPLIT_SCREEN | common.event.SPLIT_SCREEN | 表示分屏的公共事件的动作。  - 值： usual.event.SPLIT_SCREEN  - 订阅者所需权限： ohos.permission.RECEIVER_SPLIT_SCREEN |  
| COMMON_EVENT_SLOT_CHANGE | usual.event.SLOT_CHANGE | 表示通知通道更新的动作。 |  
| COMMON_EVENT_SPN_INFO_CHANGED | usual.event.SPN_INFO_CHANGED | 表示spn显示信息已更新的公共事件的动作。  - 值： usual.event.SPN_INFO_CHANGED  - 订阅者所需权限： 无 |  
| COMMON_EVENT_QUICK_FIX_APPLY_RESULT | usual.event.QUICK_FIX_APPLY_RESULT | 表示快速修复应用的动作。 |  
| COMMON_EVENT_QUICK_FIX_REVOKE_RESULT<sup>(10+)</sup> | usual.event.QUICK_FIX_REVOKE_RESULT | 指示撤销快速修复的动作。 |  
| COMMON_EVENT_USER_INFO_UPDATED | usual.event.USER_INFO_UPDATED | 表示用户信息已更新。 |  
| COMMON_EVENT_HTTP_PROXY_CHANGE<sup>(10+)</sup> | usual.event.HTTP_PROXY_CHANGE | 提示网络Http代理配置信息更新。 |  
| COMMON_EVENT_SIM_STATE_CHANGED<sup>(10+)</sup> | usual.event.SIM_STATE_CHANGED | 提示SIM卡状态更新。 |  
| COMMON_EVENT_CALL_STATE_CHANGED<sup>(10+)</sup> | usual.event.CALL_STATE_CHANGED | 提示呼叫状态更新。 |  
| COMMON_EVENT_NETWORK_STATE_CHANGED<sup>(10+)</sup> | usual.event.NETWORK_STATE_CHANGED | 提示网络状态更新。 |  
| COMMON_EVENT_SIGNAL_INFO_CHANGED<sup>(10+)</sup> | usual.event.SIGNAL_INFO_CHANGED | 提示信号信息更新。 |  
| COMMON_EVENT_SCREEN_UNLOCKED<sup>(10+)</sup> | usual.event.SCREEN_UNLOCKED | 表示屏幕解锁的公共事件。 |  
| COMMON_EVENT_SCREEN_LOCKED<sup>(10+)</sup> | usual.event.SCREEN_LOCKED | 表示屏幕锁定的公共事件。 |  
| COMMON_EVENT_CONNECTIVITY_CHANGE<sup>(10+)</sup> | usual.event.CONNECTIVITY_CHANGE | 提示网络连接状态变化。 |  
