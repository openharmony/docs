# @ohos.screenLock

The **screenlock** module is a system module in OpenHarmony. It provides APIs for screen lock applications to subscribe to screen lock status changes as well as callbacks for them to receive the results. It also provides APIs for third-party applications to unlock the screen, obtain the screen locked status, and check whether a lock screen password has been set.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import screenlock from '@ohos.screenLock';
```

## EventType

Defines the system event type.

**System capability**: SystemCapability.MiscServices.ScreenLock

| Event Type           | Description                    |
| ------------------ | ------------------------ |
| beginWakeUp        | Wakeup starts.|
| endWakeUp          | Wakeup ends.|
| beginScreenOn      | Screen turn-on starts.|
| endScreenOn        | Screen turn-on ends.|
| beginScreenOff     | Screen turn-off starts.|
| endScreenOff       | Screen turn-off ends.|
| unlockScreen       | The screen is unlocked.      |
| lockScreen         | The screen is locked.      |
| beginExitAnimation | Exit animation starts.      |
| beginSleep         | The device enters sleep mode.          |
| endSleep           | The device exits sleep mode.          |
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

## screenlock.isLocked<sup>9+</sup>

isLocked(): boolean

Checks whether the screen is locked.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the screen is locked; returns **false** otherwise.|

**Example**

```js
let isLocked = screenlock.isLocked();
```

## screenlock.isSecure<sup>9+</sup>

isSecure(): boolean

Checks whether the device is in secure mode. When the device is in secure mode, its screen requires a password, unlock pattern, or other user credentials to unlock.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the device is in secure mode; returns **false** otherwise.|

**Example**

```js
let isSecure = screenlock.isSecure();
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
screenlock.unlock((err, data) => {      
    if (err) {
        console.error(`Failed to unlock the screen, because: ${err.message}`);
        return;    
    }
    console.info(`unlock the screen successfully. result: ${data}`);
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
    console.info(`unlock the screen successfully. result: ${data}`);
}).catch((err) => {
    console.error(`Failed to unlock the screen, because: ${err.message}`);
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
screenlock.lock((err, data) => {      
    if (err) {
        console.error(`Failed to lock the screen, because: ${err.message}`);
        return;    
    }
    console.info(`lock the screen successfully. result: ${data}`);
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
    console.info(`lock the screen successfully. result: ${data}`);
}).catch((err) => {
    console.error(`Failed to lock the screen, because: ${err.message}`);
});
```

## screenlock.onSystemEvent<sup>9+</sup>

onSystemEvent(callback: Callback&lt;SystemEvent&gt;): boolean

Registers a callback for system events related to screen locking.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name  | Type                       | Mandatory| Description              |
| -------- | ------------------------- | ---- | ----------------- |
| callback | Callback\<[SystemEvent](#systemevent)> | Yes  | Callback for system events related to screen locking.|

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the callback is registered successfully; returns **false** otherwise.|

**Example**

```js
try {
    let isSuccess = screenlock.onSystemEvent((event) => {
        console.log(`Register the system event which related to screenlock successfully. eventType: ${event.eventType}`)
    });
} catch (err) {
    console.error(`Failed to register the system event which related to screenlock, because: ${err.message}`)
}
```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: string, parameter: number, callback: AsyncCallback&lt;boolean&gt;): void

Sends an event to the screen lock service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name   | Type           | Mandatory| Description                            |
| --------- | ------------------------ | ---- | -------------------- |
| event     | string                   | Yes  | Event type.<br>- **"unlockScreenResult"**: Screen unlock result.<br>- **"lockScreenResult"**: Screen lock result.<br>- **"screenDrawDone"**: Screen drawing is complete.|
| parameter | number                   | Yes  | Result.<br>- **0**: The operation is successful. For example, the screen is locked or unlocked successfully.<br>- **1**, the operation fails. For example, screen locking or unlocking fails.<br>- **2**: The operation is canceled. For example, screen locking or unlocking is canceled.|
| callback  | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The **value** true means that the event is sent successfully, and **false** means the opposite.                |

**Example**

```js
screenlock.sendScreenLockEvent('unlockScreenResult', 0, (err, result) => {
    if (err) {
        console.error(`Failed to send screenlock event, because: ${err.message}`);
        return;
    }
    console.info(`Send screenlock event successfully. result: ${result}`);
});
```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: string, parameter: number): Promise&lt;boolean&gt;

Sends an event to the screen lock service. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name   | Type  | Mandatory| Description                                      |
| --------- | ------ | ---- | --------------------------------------- |
| event     | string | Yes  | Event type.<br>- **"unlockScreenResult"**: Screen unlock result.<br>- **"lockScreenResult"**: Screen lock result.<br>- **"screenDrawDone"**: Screen drawing is complete.|
| parameter | number | Yes  | Result.<br>- **0**: The operation is successful. For example, the screen is locked or unlocked successfully.<br>- **1**, the operation fails. For example, screen locking or unlocking fails.<br>- **2**: The operation is canceled. For example, screen locking or unlocking is canceled.|

**Return value**

| Type              | Description                                          |
| ----------------- | ---------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The **value** true means that the event is sent successfully, and **false** means the opposite.|

**Example**

```js
screenlock.sendScreenLockEvent('unlockScreenResult', 0).then((result) => {
    console.info(`Send screenlock event successfully. result: ${result}`);
}).catch((err) => {
    console.error(`Failed to send screenlock event, because: ${err.message}`);
});
```

## screenlock.isScreenLocked<sup>(deprecated)</sup>

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the screen is locked. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [screenlock.isLocked<sup>9+</sup>](#screenlockislocked9) instead.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type                        | Mandatory| Description                                                       |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is locked, and **false** means the opposite.|

**Example**

```js
screenlock.isScreenLocked((err, data)=>{      
    if (err) {
        console.error(`Failed to obtain whether the screen is locked, because: ${err.message}`);
        return;    
    }
    console.info(`Obtain whether the screen is locked successfully. result: ${data}`);
});
```

## screenlock.isScreenLocked<sup>(deprecated)</sup>

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
    console.info(`Obtain whether the screen is locked successfully. result: ${data}`);
}).catch((err) => {
    console.error(`Failed to obtain whether the screen is locked, because: ${err.message}`);
});
```

## screenlock.isSecureMode<sup>(deprecated)</sup>

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the device is in secure mode. When the device is in secure mode, its screen requires a password, unlock pattern, or other user credentials to unlock. This API uses an asynchronous callback to return the result.

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
        console.error(`Failed to obtain whether the device is in secure mode, because: ${err.message}`);
        return;
    }
    console.info(`Obtain whether the device is in secure mode successfully. result: ${data}`);
});
```

## screenlock.isSecureMode<sup>(deprecated)</sup>

isSecureMode(): Promise&lt;boolean&gt;

Checks whether the device is in secure mode. When the device is in secure mode, its screen requires a password, unlock pattern, or other user credentials to unlock. This API uses a promise to return the result.

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
    console.info(`Obtain whether the device is in secure mode successfully. result: ${data}`);
}).catch((err) => {
    console.error(`Failed to obtain whether the device is in secure mode, because: ${err.message}`);
});
```
## screenlock.unlockScreen<sup>(deprecated)</sup>

unlockScreen(callback: AsyncCallback&lt;void&gt;): void

Unlocks the screen. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [screenlock.unlock<sup>9+</sup>](#screenlockunlock9) instead.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type             | Mandatory| Description            |
| -------- | ------------- | ---- | --------------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the screen is unlocked successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```js
screenlock.unlockScreen((err) => {      
    if (err) {
        console.error(`Failed to unlock the screen, because: ${err.message}`);
        return;    
    }
    console.info('unlock the screen successfully.');
});
```

## screenlock.unlockScreen<sup>(deprecated)</sup>

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
    console.info('unlock the screen successfully.');
}).catch((err) => {
    console.error(`Failed to unlock the screen, because: ${err.message}`);
});
```
