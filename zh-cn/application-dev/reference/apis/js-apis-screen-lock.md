# 锁屏管理

锁屏管理服务是OpenHarmony中系统服务，为锁屏应用提供注册亮屏、灭屏、开启屏幕、结束休眠、退出动画、请求解锁结果监听，并提供回调结果给锁屏应用。锁屏管理服务向三方应用提供请求解锁、查询锁屏状态、查询是否设置锁屏密码的能力。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import screenlock from '@ohos.screenLock';
```


## screenlock.isScreenLocked

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

判断屏幕是否锁屏，使用callback作为异步方法。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**参数**：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，返回true表示屏幕已锁屏，返回false表示屏幕未锁屏。 | 

**示例**：
  
  ```js
  screenlock.isScreenLocked((err, data)=>{      
     if (err) {
          console.error('isScreenLocked callback error -> ${JSON.stringify(err)}');
          return;    
     }
     console.info('isScreenLocked callback success data -> ${JSON.stringify(data)}');
  });
  ```


## screenlock.isScreenLocked

isScreenLocked(): Promise&lt;boolean&gt;

判断屏幕是否锁屏，使用Promise作为异步方法。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**返回值**：
  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 以Promise形式返回结果。 | 

**示例**：

  ```js
  screenlock.isScreenLocked().then((data) => {
      console.log('isScreenLocked success: data -> ${JSON.stringify(data)}');
  }).catch((err) => {
      console.error('isScreenLocked fail, promise: err -> ${JSON.stringify(err)}');
  });
  ```


## screenlock.isSecureMode

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void


判断设备是否处于安全模式下，使用callback作为异步方法。


**系统能力**: SystemCapability.MiscServices.ScreenLock


**参数**：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示屏幕处于安全模式下，返回false表示屏幕当前不在安全模式下。 | 

**示例**：
  
  ```js
  screenlock.isSecureMode((err, data)=>{      
     if (err) {
          console.error('isSecureMode callback error -> ${JSON.stringify(err)}');
          return;    
     }
     console.info('isSecureMode callback success data -> ${JSON.stringify(err)}');
  });
  ```


## screenlock.isSecureMode

isSecureMode(): Promise&lt;boolean&gt;

判断设备是否处于安全模式下，使用Promise作为异步方法。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**返回值**：
  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 以Promise形式返回结果。 | 

**示例**：

  ```js
  screenlock.isSecureMode().then((data) => {
      console.log('isSecureMode success: data->${JSON.stringify(data)}');
  }).catch((err) => {
      console.error('isSecureMode fail, promise: err->${JSON.stringify(err)}');
  });
  ```


## screenlock.unlockScreen

unlockScreen(callback: AsyncCallback&lt;void&gt;): void


解锁屏幕，使用callback作为异步方法。


**系统能力**: SystemCapability.MiscServices.ScreenLock


**参数**：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，失败时返回错误信息。 | 

**示例**：
  
  ```js
  screenlock.unlockScreen((err) => {      
     if (err) {
          console.error('unlockScreen callback error -> ${JSON.stringify(err)}');
          return;    
     }
     console.info('unlockScreen callback success');
  });
  ```


## screenlock.unlockScreen

unlockScreen(): Promise&lt;void&gt;

解锁屏幕，使用Promise作为异步方法。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**返回值**：
    | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果。 | 

**示例**：
  
  ```js
  screenlock.unlockScreen().then(() => {
      console.log('unlockScreen success');
  }).catch((err) => {
      console.error('unlockScreen fail, promise: err->${JSON.stringify(err)}');
  });
  ```

## screenlock.on<sup>9+</sup>

on(type: 'beginWakeUp' | 'endWakeUp' | 'beginScreenOn' | 'endScreenOn' | 'beginScreenOff' | 'endScreenOff' | 'unlockScreen' | 'beginExitAnimation', callback: Callback\<void\>): void

注册锁屏状态变化回调。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。<br/>- type为"beginWakeUp"，表示事件开始时开始唤醒。<br/>- type为"endWakeUp"，表示事件结束时结束唤醒。<br/>- type为"beginScreenOn"，表示事件开始时开始亮屏。<br/>- type为"endScreenOn"，表示事件结束时结束亮屏。<br/>- type为"beginScreenOff"，表示事件开始时开始灭屏。<br/>- type为"endScreenOff"，表示事件结束时结束灭屏。<br/>- type为"unlockScreen"，表示请求解锁。<br/>- type为"beginExitAnimation"，表示动画开始退场。 |
  | callback | Callback\<void\> | 是 | 事件回调方法。 |

**示例**：
  
  ```js
  screenlock.on('beginWakeUp', () => {
      console.log('beginWakeUp triggered');
  });
  ```

## screenlock.on<sup>9+</sup>

on(type: 'beginSleep' | 'endSleep' | 'changeUser', callback: Callback\<number\>): void

注册锁屏状态变化回调。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。<br/>- type为"beginSleep"，表示开始休眠。<br/>- type为"endSleep"，表示结束休眠。<br/>- type为"changeUser"，表示切换用户。 |
  | callback | Callback\<number\> | 是 | 事件回调方法。<br/>返回事件相应的状态。 |

**示例**：
  
  ```js
  screenlock.on('beginSleep', (why) => {
      console.log('beginSleep triggered:' + why);
  });
  ```
## screenlock.on<sup>9+</sup>

on(type: 'screenlockEnabled', callback: Callback\<boolean\>): void

注册锁屏状态变化回调。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。<br/>- type为"screenlockEnabled"，表示锁屏是否启用。 |
  | callback | Callback\<boolean\> | 是 | 注册成功的回调。<br/>回调结果用true/false表示。 |

**示例**：
  
  ```js
  screenlock.on('screenlockEnabled', (isEnabled) => {
      console.log('screenlockEnabled triggered, result:' + isEnabled);
  });
  ```

## screenlock.off<sup>9+</sup>

off(type: 'beginWakeUp' | 'endWakeUp' | 'beginScreenOn' | 'endScreenOn' | 'beginScreenOff' | 'endScreenOff' 
      | 'unlockScreen' | 'beginExitAnimation' | 'screenlockEnabled' | 'beginSleep' | 'endSleep' | 'changeUser', callback: Callback\<void\>): void

取消注册锁屏状态变化回调。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。<br/>- type为"beginWakeUp"，表示事件开始时开始唤醒。<br/>- type为"endWakeUp"，表示事件结束时结束唤醒。<br/>- type为"beginScreenOn"，表示事件开始时开始亮屏。<br/>- type为"endScreenOn"，表示事件结束时结束亮屏。<br/>- type为"beginScreenOff"，表示事件开始时开始灭屏。<br/>- type为"endScreenOff"，表示事件结束时结束灭屏。<br/>- type为"unlockScreen"，表示请求解锁。<br/>- type为"beginExitAnimation"，表示动画开始退场。<br/>- type为"screenlockEnabled"，表示锁屏是否启用。<br/>- type为"beginSleep"，表示开始休眠。<br/>- type为"endSleep"，表示结束休眠。<br/>- type为"changeUser"，表示切换用户。 |
  | callback | Callback\<void\> | 是 | 注册成功的回调。 |

**示例**：
  
  ```js
  screenlock.off('beginWakeUp', () => {
      console.log("callback");
  });
  ```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean\>): void

应用发送事件到锁屏服务，异步方法。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | String | 是 | 事件类型，支持如下取值:<br/>- "unlockScreenResult"，表示解锁结果。<br/>- "screenDrawDone"，表示屏幕绘制完成。 |
  | parameter | number | 是 | 解锁状态。<br/>- parameter为0，表示解锁成功。<br/>- parameter为1，表示解锁失败。<br/>- parameter为2，表示解锁取消。 |
  | callback | AsyncCallback\<boolean\> | 是 | 表示执行结果。 |

**示例**：
  
  ```js
  screenlock.sendScreenLockEvent('unlockScreenResult', 0, (err, result) => {
      console.log('sending result:' + result);
  });
  ```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number): Promise<boolean>

应用发送事件到锁屏服务，异步方法。

**系统能力**: SystemCapability.MiscServices.ScreenLock

**参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | String | 是 | 事件类型，支持如下取值:<br/>- "unlockScreenResult"，表示解锁结果。<br/>- "screenDrawDone"，表示屏幕绘制完成。 |
  | parameter | number | 是 | 解锁状态。<br/>- parameter为0，表示解锁成功。<br/>- parameter为1，表示解锁失败。<br/>- parameter为2，表示解锁取消。 |

**返回值**：
  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise\<boolean\> | 以Promise形式返回执行结果。 | 

**示例**：
  
  ```js
  screenlock.sendScreenLockEvent('unlockScreenResult', 0).then((err, result) => {
      console.log('sending result:' + result);
  });
  ```
