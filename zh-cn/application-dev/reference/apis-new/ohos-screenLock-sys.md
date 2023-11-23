# @ohos.screenLock    
锁屏管理服务是OpenHarmony中的系统服务，为锁屏应用提供注册亮屏、灭屏、开启屏幕、结束休眠、退出动画、请求解锁结果监听，并提供回调结果给锁屏应用。锁屏管理服务向三方应用提供请求解锁、查询锁屏状态、查询是否设置锁屏密锁屏管理服务是OpenHarmony中的系统服务，为锁屏应用提供注册亮屏、灭屏、开启屏幕、结束休眠、退出动画、请求解锁结果监听，并提供回调结果给锁屏应用。锁屏管理服务向三方应用提供请求解锁、查询锁屏状态、查询是否设置锁屏密。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import screenLock from '@ohos.screenLock'    
```  
    
## isLocked<sup>(9+)</sup>    
判断屏幕是否锁屏。  
 **调用形式：**     
- isLocked(): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.ScreenLock    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示屏幕已锁屏；返回false表示屏幕未锁屏。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
let isLocked = screenLock.isLocked();    
```    
  
    
## unlock<sup>(9+)</sup>    
解锁屏幕。  
 **调用形式：**     
    
- unlock(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- unlock(): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.ScreenLock    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示屏幕解锁成功；返回false表示取消解锁。 |  
| Promise<boolean> | Promise对象。返回true表示屏幕解锁成功；返回false表示取消解锁。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 13200002 | the screenlock management service is abnormal. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  screenLock.unlock((err: BusinessError, data: Boolean) => {  
    if (err) {  
      console.error(`Failed to unlock the screen, Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    console.info(`Succeeded in unlocking the screen. result: ${data}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  screenLock.unlock().then((data: Boolean) => {  
    console.info(`Succeeded in unlocking the screen. result: ${data}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to unlock the screen, Code: ${err.code}, message: ${err.message}`);  
  });  
    
```    
  
    
## lock<sup>(9+)</sup>    
锁定屏幕  
 **调用形式：**     
    
- lock(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- lock(): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.ScreenLock  
 **需要权限：** ohos.permission.ACCESS_SCREEN_LOCK_INNER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示屏幕锁定成功；返回false表示屏幕锁定失败。 |  
| Promise<boolean> | Promise对象。返回true表示屏幕锁定成功；返回false表示屏幕锁定失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 13200002 | the screenlock management service is abnormal. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  screenLock.lock((err: BusinessError, data: Boolean) => {  
    if (err) {  
      console.error(`Failed to lock the screen, Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    console.info(`Succeeded in locking the screen. result: ${data}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  screenLock.lock().then((data: Boolean) => {  
    console.info(`Succeeded in locking the screen. result: ${data}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to lock the screen, Code: ${err.code}, message: ${err.message}`);  
  });  
  ```  
    
```    
  
    
## EventType<sup>(9+)</sup>    
定义系统事件类型。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.ScreenLock    
    
| 取值范围 | 说明 |  
| --------| --------|  
| beginWakeUp | 表示设备开始唤醒。 |  
| endWakeUp | 表示设备结束唤醒。 |  
| beginScreenOn | 表示设备开始亮屏。 |  
| endScreenOn | 表示设备结束亮屏。 |  
| beginScreenOff | 表示设备开始灭屏。 |  
| endScreenOff | 表示设备结束灭屏。 |  
| unlockScreen | 表示请求屏幕解锁。 |  
| lockScreen | 表示请求屏幕锁定。 |  
| beginExitAnimation | 表示开始退场动画。 |  
| beginSleep | 表示设备开始休眠。 |  
| endSleep | 表示设备结束休眠。 |  
| changeUser | 表示切换用户。 |  
| screenlockEnabled | 表示锁屏是否启用。 |  
| serviceRestart | 表示锁屏服务进行重启。 |  
    
## SystemEvent<sup>(9+)</sup>    
定义系统事件回调参数结构。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.ScreenLock    
## onSystemEvent<sup>(9+)</sup>    
注册锁屏相关的系统事件，仅支持锁屏应用使用。  
 **调用形式：**     
    
- onSystemEvent(callback: Callback\<SystemEvent>): boolean    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.ScreenLock  
 **需要权限：** ohos.permission.ACCESS_SCREEN_LOCK_INNER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 锁屏相关的系统事件回调函数。 |  
| boolean | 返回true表示锁屏相关系统事件注册成功；返回false表示锁屏相关系统事件注册失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 13200002 | the screenlock management service is abnormal. |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
try {  
    let isSuccess = screenLock.onSystemEvent((event: screenLock.SystemEvent) => {  
      console.log(`Succeeded in Registering the system event which related to screenlock. eventType: ${event.eventType}`)  
    });  
  } catch (err) {  
    let error = err as BusinessError;  
    console.error(`Failed to register the system event which related to screenlock, Code: ${error.code}, message: ${error.message}`)  
  }  
    
```    
  
    
## sendScreenLockEvent<sup>(9+)</sup>    
应用发送事件到锁屏服务，仅支持锁屏应用使用。  
 **调用形式：**     
    
- sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.ScreenLock  
 **需要权限：** ohos.permission.ACCESS_SCREEN_LOCK_INNER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | String | true | 事件类型，支持如下取值:<br/>- "unlockScreenResult"，表示解锁结果。<br/>- "lockScreenResult"，表示锁屏结果。<br/>- "screenDrawDone"，表示屏幕绘制完成。 |  
| parameter | number | true |  事件结果。<br/>- parameter为0，表示成功。例如解锁成功或锁屏成功。<br/>- parameter为1，表示失败。例如解锁失败或锁屏失败。<br/>- parameter为2，表示取消。例如锁屏取消或解锁取消。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示发送事件成功；返回false表示发送事件失败。 |  
| Promise<boolean> | Promise对象。返回true表示发送事件成功；返回false表示发送事件失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 13200002 | the screenlock management service is abnormal. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  screenLock.sendScreenLockEvent('unlockScreenResult', 0, (err: BusinessError, result: Boolean) => {  
    if (err) {  
      console.error(`Failed to send screenlock event, Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    console.info(`Succeeded in Sending screenlock event. result: ${result}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  screenLock.sendScreenLockEvent('unlockScreenResult', 0).then((result: Boolean) => {  
    console.info(`Succeeded in Sending screenlock event. result: ${result}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to send screenlock event, Code: ${err.code}, message: ${err.message}`);  
  });  
    
```    
  
