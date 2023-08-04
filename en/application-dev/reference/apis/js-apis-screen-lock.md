# @ohos.screenLock (Screen Lock)

The **screenlock** module is a system module in OpenHarmony. It provides APIs for screen lock applications to subscribe to screen lock status changes as well as callbacks for them to receive the results. It also provides APIs for third-party applications to unlock the screen, obtain the screen locked status, and check whether a lock screen password has been set.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import screenLock from '@ohos.screenLock';
```

## EventType<sup>9+</sup>

Defines the system event type.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

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

## SystemEvent<sup>9+</sup>

Defines the structure of the system event callback.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

| Name   | Type  | Mandatory|       Description       |
| --------- | ------ | ---- | ------------- |
| eventType   | [EventType](#eventtype9) | Yes  | System event type.|
| params | string | Yes  | System event parameters.|

## screenLock.isLocked<sup>9+</sup>

isLocked(): boolean

Checks whether the screen is locked.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the screen is locked; returns **false** otherwise.|

**Example**

```js
let isLocked = screenLock.isLocked();
```

## screenLock.unlock<sup>9+</sup>

unlock(callback: AsyncCallback&lt;boolean&gt;): void

Unlocks the screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | --------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is unlocked successfully, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Screen Lock Management Error Codes](../errorcodes/errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```js
  screenLock.unlock((err, data) => { 
    if (err) {
      console.error(`Failed to unlock the screen. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in unlocking the screen. Result: ${data}`);
  });
  ```

## screenLock.unlock<sup>9+</sup>

unlock(): Promise&lt;boolean&gt;

Unlocks the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is unlocked successfully, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Screen Lock Management Error Codes](../errorcodes/errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```js
  screenLock.unlock().then((data) => {
    console.info(`Succeeded in unlocking the screen. Result: ${data}`);
  }).catch((err) => {
    console.error(`Failed to unlock the screen, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## screenLock.lock<sup>9+</sup>

lock(callback: AsyncCallback&lt;boolean&gt;): void

Locks the screen. This API can be called only by system screen lock applications. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name  | Type         | Mandatory| Description                     |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is locked successfully, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Screen Lock Management Error Codes](../errorcodes/errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```js
  screenLock.lock((err, data) => {
    if (err) {
      console.error(`Failed to lock the screen. Code: ${err.code}, message: ${err.message}`);
      return;  
    }
    console.info(`Succeeded in locking the screen. result: ${data}`);
  });
  ```

## screenLock.lock<sup>9+</sup>

lock(): Promise&lt;boolean&gt;

Locks the screen. This API can be called only by system screen lock applications. It uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is locked successfully, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Screen Lock Management Error Codes](../errorcodes/errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```js
  screenLock.lock().then((data) => {
    console.info(`Succeeded in locking the screen. Result: ${data}`);
  }).catch((err) => {
    console.error(`Failed to lock the screen. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## screenLock.onSystemEvent<sup>9+</sup>

onSystemEvent(callback: Callback&lt;SystemEvent&gt;): boolean

Registers a callback for system events related to screen locking. This API can be called only by system screen lock applications.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name  | Type                       | Mandatory| Description              |
| -------- | ------------------------- | ---- | ----------------- |
| callback | Callback\<[SystemEvent](#systemevent9)> | Yes  | Callback for system events related to screen locking.|

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the callback is registered successfully; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Screen Lock Management Error Codes](../errorcodes/errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```js
  try {
    let isSuccess = screenLock.onSystemEvent((event) => {
      console.log(`Succeeded in registering the system event related to screenlock. eventType: ${event.eventType}`)
    });
  } catch (err) {
    console.error(`Failed to register the system event related to screenlock. Code: ${err.code}, message: ${err.message}`)
  }
  ```

## screenLock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback&lt;boolean&gt;): void

Sends an event to the screen lock service. This API can be called only by system screen lock applications. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name   | Type           | Mandatory| Description                            |
| --------- | ------------------------ | ---- | -------------------- |
| event     | String                   | Yes  | Event type.<br>- **"unlockScreenResult"**: Screen unlock result.<br>- **"lockScreenResult"**: Screen lock result.<br>- **"screenDrawDone"**: Screen drawing is complete.|
| parameter | number                   | Yes  | Result.<br>- **0**: The operation is successful. For example, the screen is locked or unlocked successfully.<br>- **1**, the operation fails. For example, screen locking or unlocking fails.<br>- **2**: The operation is canceled. For example, screen locking or unlocking is canceled.|
| callback  | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The **value** true means that the event is sent successfully, and **false** means the opposite.                |

**Error codes**

For details about the error codes, see [Screen Lock Management Error Codes](../errorcodes/errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13200002  |the screenlock management service is abnormal.         |

**Example**

  ```js
  screenLock.sendScreenLockEvent('unlockScreenResult', 0, (err, result) => {
    if (err) {
      console.error(`Failed to send the screenlock event. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in sending the screenlock event. result: ${result}`);
  });
  ```

## screenLock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number): Promise&lt;boolean&gt;

Sends an event to the screen lock service. This API can be called only by system screen lock applications. It uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Parameters**

| Name   | Type  | Mandatory| Description                                      |
| --------- | ------ | ---- | --------------------------------------- |
| event     | String | Yes  | Event type.<br>- **"unlockScreenResult"**: Screen unlock result.<br>- **"lockScreenResult"**: Screen lock result.<br>- **"screenDrawDone"**: Screen drawing is complete.|
| parameter | number | Yes  | Result.<br>- **0**: The operation is successful. For example, the screen is locked or unlocked successfully.<br>- **1**, the operation fails. For example, screen locking or unlocking fails.<br>- **2**: The operation is canceled. For example, screen locking or unlocking is canceled.|

**Return value**

| Type              | Description                                          |
| ----------------- | ---------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The **value** true means that the event is sent successfully, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Screen Lock Management Error Codes](../errorcodes/errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```js
  screenLock.sendScreenLockEvent('unlockScreenResult', 0).then((result) => {
    console.info(`Succeeded in sending the screenlock event. Result: ${result}`);
  }).catch((err) => {
    console.error(`Failed to send the screenlock event. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## screenLock.isScreenLocked<sup>(deprecated)</sup>

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the screen is locked. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type                        | Mandatory| Description                                                       |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is locked, and **false** means the opposite.|

**Example**

  ```js
  screenLock.isScreenLocked((err, data)=>{       
    if (err) {
      console.error(`Failed to obtain whether the screen is locked. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in obtaining whether the screen is locked. Result: ${data}`);
  });
  ```

## screenLock.isScreenLocked<sup>(deprecated)</sup>

isScreenLocked(): Promise&lt;boolean&gt;

Checks whether the screen is locked. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type                  | Description                                        |
| ---------------------- | ------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is locked, and **false** means the opposite.|

**Example**

  ```js
  screenLock.isScreenLocked().then((data) => {
    console.info(`Succeeded in obtaining whether the screen is locked. Result: ${data}`);
  }).catch((err) => {
    console.error(`Failed to obtain whether the screen is locked. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## screenLock.isSecureMode<sup>(deprecated)</sup>

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the device is in secure mode. When the device is in secure mode, its screen requires a password, unlock pattern, or other user credentials to unlock. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type           | Mandatory| Description                             |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the device is in secure mode, and **false** means the opposite.|

**Example**

  ```js
  screenLock.isSecureMode((err, data)=>{
    if (err) {
      console.error(`Failed to obtain whether the device is in secure mode. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in obtaining whether the device is in secure mode. Result: ${data}`);
  });
  ```

## screenLock.isSecureMode<sup>(deprecated)</sup>

isSecureMode(): Promise&lt;boolean&gt;

Checks whether the device is in secure mode. When the device is in secure mode, its screen requires a password, unlock pattern, or other user credentials to unlock. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the device is in secure mode, and **false** means the opposite.|

**Example**

  ```js
  screenLock.isSecureMode().then((data) => {
    console.info(`Succeeded in obtaining whether the device is in secure mode. Result: ${data}`);
  }).catch((err) => {
    console.error(`Failed to obtain whether the device is in secure mode. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## screenLock.unlockScreen<sup>(deprecated)</sup>

unlockScreen(callback: AsyncCallback&lt;void&gt;): void

Unlocks the screen. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type             | Mandatory| Description            |
| -------- | ------------- | ---- | --------------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the screen is unlocked successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```js
  screenLock.unlockScreen((err) => {    
    if (err) {
      console.error(`Failed to unlock the screen. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in unlocking the screen.`);
  });
  ```

## screenLock.unlockScreen<sup>(deprecated)</sup>

unlockScreen(): Promise&lt;void&gt;

Unlocks the screen. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  screenLock.unlockScreen().then(() => {
    console.info('Succeeded in unlocking the screen.');
  }).catch((err) => {
    console.error(`Failed to unlock the screen. Code: ${err.code}, message: ${err.message}`);
  });
  ```
