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

- 参数：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，返回true表示屏幕已锁屏，返回false表示屏幕未锁屏。 | 

- 示例：
  
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

- 返回值：
  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 以Promise形式返回结果。 | 

- 示例：

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


- 参数：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示屏幕处于安全模式下，返回false表示屏幕当前不在安全模式下。 | 

- 示例：
  
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

- 返回值：
  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 以Promise形式返回结果。 | 

- 示例：

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


- 参数：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，失败时返回错误信息。 | 

- 示例：
  
  ```js
  screenlock.unlockScreen((err)=>{      
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

- 返回值：
    | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果。 | 

- 示例：
  
  ```js
  screenlock.unlockScreen().then(() => {
      console.log('unlockScreen success');
  }).catch((err) => {
      console.error('unlockScreen fail, promise: err->${JSON.stringify(err)}');
  });
  ```
