# Screen Lock Management

The **screenlock** module is a system module in OpenHarmony. It provides APIs for screen lock applications to subscribe to screen lock status changes as well as callbacks for them to receive the results. It also provides APIs for third-party applications to unlock the screen, obtain the screen locked status, and check whether a lock screen password has been set.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import screenlock from '@ohos.screenLock';
```

## screenlock.isScreenLocked

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the screen is locked. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
>This API is supported since API version 7 and deprecated since API version 9. You are advised to use [screenlock.isLocked<sup>9+</sup>](#screenlockislocked9) instead.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type                        | Mandatory| Description                                                       |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is locked, and **false** means the opposite.|

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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [screenlock.isLocked<sup>9+</sup>](#screenlockislocked9) instead.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type                  | Description                                        |
| ---------------------- | ------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is locked, and **false** means the opposite.|

**Example**

```js
screenlock.isScreenLocked().then((data) => {
    console.log('isScreenLocked success: data -> ${JSON.stringify(data)}');
}).catch((err) => {
    console.error('isScreenLocked fail, promise: err -> ${JSON.stringify(err)}');
});
```

## screenlock.isLocked<sup>9+</sup>

isLocked(): boolean

Checks whether the screen is locked. This API returns the result synchronously.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the screen is locked; returns **false** otherwise.|

**Example**

```js
let isLocked = screenlock.isLocked();
```

## screenlock.isSecureMode

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the device is in secure mode. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [screenlock.isSecure<sup>9+</sup>](#screenlockissecure9) instead.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type           | Mandatory| Description                             |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the device is in secure mode, and **false** means the opposite.|

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

Checks whether the device is in secure mode. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [screenlock.isSecure<sup>9+</sup>](#screenlockissecure9) instead.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the device is in secure mode, and **false** means the opposite.|

**Example**

```js
screenlock.isSecureMode().then((data) => {
    console.log('isSecureMode success: data->${JSON.stringify(data)}');
}).catch((err) => {
    console.error('isSecureMode fail, promise: err->${JSON.stringify(err)}');
});
```

## screenlock.isSecure<sup>9+</sup>

isSecure(): boolean

Checks whether the device is in secure mode.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** means that the device is in secure mode, and **false** means the opposite.|

**Example**

```js
let isSecure = screenlock.isSecure();
```

## screenlock.unlockScreen

unlockScreen(callback: AsyncCallback&lt;void&gt;): void

Unlocks the screen. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [screenlock.unlock<sup>9+</sup>](#screenlockunlock9) instead.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type             | Mandatory| Description            |
| -------- | ------------- | ---- | --------------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation fails, an error message is returned.|

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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [screenlock.unlock<sup>9+</sup>](#screenlockunlock9) instead.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
screenlock.unlockScreen().then(() => {
    console.log('unlockScreen success');
}).catch((err) => {
    console.error('unlockScreen fail, promise: err->${JSON.stringify(err)}');
});
```

## screenlock.unlock<sup>9+</sup>

unlock(callback: AsyncCallback&lt;boolean&gt;): void

Unlocks the screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | --------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is unlocked successfully, and **false** means the opposite.|

**Example**

```js
screenlock.unlock((err,data) => {      
    if (err) {
        console.error('unlock  error -> ${JSON.stringify(err)}');
        return;    
    }
    console.info('unlock  success data -> ${JSON.stringify(data)}');
});
```

## screenlock.unlock<sup>9+</sup>

unlock(): Promise&lt;boolean&gt;

Unlocks the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is unlocked successfully, and **false** means the opposite.|

**Example**

```js
screenlock.unlock().then((data) => {
    console.log('unlock success');
}).catch((err) => {
    console.error('unlock fail, : err->${JSON.stringify(err)}');
});
```

## screenlock.lock<sup>9+</sup>

lock(callback: AsyncCallback&lt;boolean&gt;): void

Locks the screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name  | Type         | Mandatory| Description                     |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is locked successfully, and **false** means the opposite.|

**Example**

```js
screenlock.lock((err,data) => {      
    if (err) {
        console.error('lock callback error -> ${JSON.stringify(err)}');
        return;    
    }
    console.info('lock callback success');
});
```

## screenlock.lock<sup>9+</sup>

lock(): Promise&lt;boolean&gt;

Locks the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is locked successfully, and **false** means the opposite.|

**Example**

```js
screenlock.lock().then((data) => {
    console.log('lock success');
}).catch((err) => {
    console.error('lock fail, promise: err->${JSON.stringify(err)}');
});
```

## EventType

Defines the system event type.

**System capability**: SystemCapability.MiscServices.ScreenLock

| Event Type           | Description                    |
| ------------------ | ------------------------ |
| beginWakeUp        | Wakeup starts when the event starts.|
| endWakeUp          | Wakeup ends when the event ends.|
| beginScreenOn      | Screen turn-on starts when the event starts.|
| endScreenOn        | Screen turn-on ends when the event ends.|
| beginScreenOff     | Screen turn-off starts when the event starts.|
| endScreenOff       | Screen turn-off ends when the event ends.|
| unlockScreen       | The screen is unlocked.      |
| lockScreen         | The screen is locked.      |
| beginExitAnimation | Animation starts to exit.      |
| beginSleep         | The screen enters sleep mode.          |
| endSleep           | The screen exits sleep mode.          |
| changeUser         | The user is switched.          |
| screenlockEnabled  | Screen lock is enabled.      |
| serviceRestart     | The screen lock service is restarted.  |


## SystemEvent

Defines the structure of the system event callback.

**System capability**: SystemCapability.MiscServices.ScreenLock

| Name   | Type  | Mandatory|       Description       |
| --------- | ------ | ---- | ------------- |
| eventType   | [EventType](#eventtype) | Yes  | System event type.|
| params | string | Yes  | System event parameters.|

## screenlock.onSystemEvent<sup>9+</sup>

onSystemEvent(callback: Callback\<SystemEvent\>): boolean

Registers a callback for system events related to screen locking.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name  | Type                                  | Mandatory| Description                        |
| -------- | -------------------------------------- | ---- | ---------------------------- |
| callback | Callback\<[SystemEvent](#systemevent)> | Yes  | Callback for system events related to screen locking.|

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the callback is registered successfully; returns **false** otherwise.|

**Example**

```js
let isSuccess = screenlock.onSystemEvent((event)=>{
    console.log(`onSystemEvent:callback:${event.eventType}`)
});
if (!isSuccess) {
    console.log(`onSystemEvent result is false`)
}
```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void

Sends an event to the screen lock service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name   | Type           | Mandatory| Description                            |
| --------- | ------------------------ | ---- | -------------------- |
| event     | String                   | Yes  | Event type.<br>- **"unlockScreenResult"**: Screen unlock result.<br>- **"screenDrawDone"**: Screen drawing is complete.|
| parameter | number                   | Yes  | Screen unlock status.<br>- **0**: The unlock is successful.<br>- **1**: The unlock failed.<br>- **2**: The unlock was canceled.|
| callback  | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the operation is successful, and **false** means the opposite.                |

**Example**

```js
screenlock.sendScreenLockEvent('unlockScreenResult', 0, (err, result) => {
    console.log('sending result:' + result);
});
```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>

Sends an event to the screen lock service. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name   | Type  | Mandatory| Description                                      |
| --------- | ------ | ---- | --------------------------------------- |
| event     | String | Yes  | Event type.<br>- **"unlockScreenResult"**: Screen unlock result.<br>- **"screenDrawDone"**: Screen drawing is complete.|
| parameter | number | Yes  | Screen unlock status.<br>- **0**: The unlock is successful.<br>- **1**: The unlock failed.<br>- **2**: The unlock was canceled.|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the operation is successful, and **false** means the opposite.|

**Example**

```js
screenlock.sendScreenLockEvent('unlockScreenResult', 0).then((result) => {
    console.log('sending result:' + result);
});
```
