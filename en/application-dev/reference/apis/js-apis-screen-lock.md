# Screen Lock Management

> **NOTE**
>
> The initial APIs of this module are supported since API version … Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import screenlock from '@ohos.screenLock';
```


## screenlock.isScreenLocked

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the screen is locked. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Returns **true** if the screen is locked; returns **false** otherwise.|

**Example**

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

Checks whether the screen is locked. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  screenlock.isScreenLocked().then((data) => {
      console.log('isScreenLocked success: data -> ${JSON.stringify(data)}');
  }).catch((err) => {
      console.error('isScreenLocked fail, promise: err -> ${JSON.stringify(err)}');
  });
  ```


## screenlock.isSecureMode

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void


Checks whether a device is in secure mode. This API uses an asynchronous callback to return the result.


**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Returns **true** if the device is in secure mode; returns **false** otherwise.|

**Example**

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

Checks whether a device is in secure mode. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  screenlock.isSecureMode().then((data) => {
      console.log('isSecureMode success: data->${JSON.stringify(data)}');
  }).catch((err) => {
      console.error('isSecureMode fail, promise: err->${JSON.stringify(err)}');
  });
  ```


## screenlock.unlockScreen

unlockScreen(callback: AsyncCallback&lt;void&gt;): void


Unlocks the screen. This API uses an asynchronous callback to return the result.


**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation failed, an error message is returned.|

**Example**

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

Unlocks the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  screenlock.unlockScreen().then(() => {
      console.log('unlockScreen success');
  }).catch((err) => {
      console.error('unlockScreen fail, promise: err->${JSON.stringify(err)}');
  });
  ```

## screenlock.on<sup>9+</sup>

on(type: 'beginWakeUp' | 'endWakeUp' | 'beginScreenOn' | 'endScreenOn' | 'beginScreenOff' | 'endScreenOff' | 'unlockScreen' | 'beginExitAnimation', callback: Callback\<void\>): void

Subscribes to screen lock status changes.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **'beginWakeUp'**: Wakeup starts.<br>- **'endWakeUp'**: Wakeup ends.<br>- **'beginScreenOn'**: Screen turn-on starts.<br>- **'endScreenOn'**: Screen turn-on ends.<br>- **'beginScreenOff'**: Screen turn-off starts.<br>- **'endScreenOff'**: Screen turn-off ends.<br>- **'unlockScreen'**: The screen is unlocked.<br>- **'beginExitAnimation'**: Animation starts to exit. |
| callback | Callback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  screenlock.on('beginWakeUp', () => {
      console.log('beginWakeUp triggered');
  });
  ```

## screenlock.on<sup>9+</sup>

on(type: 'beginSleep' | 'endSleep' | 'changeUser', callback: Callback\<number\>): void

Subscribes to screen lock status changes.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **'beginSleep'**: The screen enters sleep mode.<br>- **'endSleep'**: The screen exits sleep mode.<br>- **'changeUser'**: The user is switched.|
| callback | Callback\<number\> | Yes| Callback used to return the result. |

**Example**

  ```js
  screenlock.on('beginSleep', (why) => {
      console.log('beginSleep triggered:' + why);
  });
  ```
## screenlock.on<sup>9+</sup>

on(type: 'screenlockEnabled', callback: Callback\<boolean\>): void

Subscribes to screen lock status changes.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **'screenlockEnabled'**: Screen lock is enabled.|
| callback | Callback\<boolean\> | Yes| Callback used to return the result. |

**Example**

  ```js
  screenlock.on('screenlockEnabled', (isEnabled) => {
      console.log('screenlockEnabled triggered, result:' + isEnabled);
  });
  ```

## screenlock.off<sup>9+</sup>

off(type: 'beginWakeUp' | 'endWakeUp' | 'beginScreenOn' | 'endScreenOn' | 'beginScreenOff' | 'endScreenOff' 
      | 'unlockScreen' | 'beginExitAnimation' | 'screenlockEnabled' | 'beginSleep' | 'endSleep' | 'changeUser', callback: Callback\<void\>): void

Unsubscribes from screen lock status changes.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **'beginWakeUp'**: Wakeup starts.<br>- **'endWakeUp'**: Wakeup ends.<br>- **'beginScreenOn'**: Screen turn-on starts.<br>- **'endScreenOn'**: Screen turn-on ends.<br>- **'beginScreenOff'**: Screen turn-off starts.<br>- **'endScreenOff'**: Screen turn-off ends.<br>- **'unlockScreen'**: The screen is unlocked.<br>- **'beginExitAnimation'**: Animation starts to exit.<br>- **'screenlockEnabled'**: Screen lock is enabled.<br>- **'beginSleep'**: The screen enters sleep mode.<br>- **'endSleep'**: The screen exits sleep mode.<br>- **'changeUser'**: The user is switched.|
| callback | Callback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  screenlock.off('beginWakeUp', () => {
      console.log("callback");
  });
  ```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean\>): void

Sends an event to the screen lock service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | String | Yes| Event type.<br>- **'unlockScreenResult'**: Screen unlock result.<br>- **'screenDrawDone'**: Screen drawing is complete.|
| parameter | number | Yes| Screen unlock status.<br>- **0**: The unlock is successful.<br>- **0**: The unlock failed.<br>- **2**: The unlock was canceled.|
| callback | AsyncCallback\<boolean\> | Yes| Callback used to return the result.|

**Example**

  ```js
  screenlock.sendScreenLockEvent('unlockScreenResult', 0, (err, result) => {
      console.log('sending result:' + result);
  });
  ```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number): Promise<boolean>

Sends an event to the screen lock service. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | String | Yes| Event type.<br>- **'unlockScreenResult'**: Screen unlock result.<br>- **'screenDrawDone'**: Screen drawing is complete.|
| parameter | number | Yes| Screen unlock status.<br>- **0**: The unlock is successful.<br>- **0**: The unlock failed.<br>- **2**: The unlock was canceled.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

  ```js
  screenlock.sendScreenLockEvent('unlockScreenResult', 0).then((err, result) => {
      console.log('sending result:' + result);
  });
  ```
