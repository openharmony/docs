# @ohos.screenLock (Screen Lock) (System API)

The **screenLock** module is a system module in OpenHarmony. It provides APIs for screen lock applications to subscribe to screen lock status changes as well as callbacks for them to receive the results. It also provides APIs for third-party applications to unlock the screen, obtain the screen locked status, and check whether a lock screen password has been set.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.screenLock (Screen Lock)](js-apis-screen-lock.md).

## Modules to Import

```ts
import { screenLock } from '@kit.BasicServicesKit';
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202  | permission verification failed, application which is not a system application uses system API.         |

**Example**

```ts
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
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is unlocked successfully, and **false** means that screen unlocked is canceled.|

**Error codes**

For details about error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Lock Error Codes](errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202  | permission verification failed, application which is not a system application uses system API.         |
| 13200002  | the screenlock management service is abnormal.         |
| 13200003  | illegal use.         |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  screenLock.unlock((err: BusinessError, data: Boolean) => {
    if (err) {
      console.error(`Failed to unlock the screen, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in unlocking the screen. result: ${data}`);
  });
  ```

> **NOTE**
>
> The error code **13200003 illegal use** is added since API version 11.

## screenLock.unlock<sup>9+</sup>

unlock(): Promise&lt;boolean&gt;

Unlocks the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**System API**: This is a system API.

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is unlocked successfully, and **false** means that screen unlocked is canceled.|

**Error codes**

For details about error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Lock Error Codes](errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202  | permission verification failed, application which is not a system application uses system API.         |
| 13200002  | the screenlock management service is abnormal.         |
| 13200003  | illegal use.         |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  screenLock.unlock().then((data: Boolean) => {
    console.info(`Succeeded in unlocking the screen. result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to unlock the screen, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **NOTE**
>
> The error code **13200003 illegal use** is added since API version 11.

## screenLock.lock<sup>9+</sup>

lock(callback: AsyncCallback&lt;boolean&gt;): void

Locks the screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Required permissions**: ohos.permission.ACCESS_SCREEN_LOCK_INNER

**System API**: This is a system API.

**Parameters**

| Name  | Type         | Mandatory| Description                     |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is locked successfully, and **false** means the opposite.|

**Error codes**

For details about error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Lock Error Codes](errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 201  | permission denied.         |
| 202  | permission verification failed, application which is not a system application uses system API.         |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  screenLock.lock((err: BusinessError, data: Boolean) => {
    if (err) {
      console.error(`Failed to lock the screen, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in locking the screen. result: ${data}`);
  });
  ```

## screenLock.lock<sup>9+</sup>

lock(): Promise&lt;boolean&gt;

Locks the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Required permissions**: ohos.permission.ACCESS_SCREEN_LOCK_INNER

**System API**: This is a system API.

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is locked successfully, and **false** means the opposite.|

**Error codes**

For details about error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Lock Error Codes](errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201  | permission denied.         |
| 202  | permission verification failed, application which is not a system application uses system API.         |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  screenLock.lock().then((data: Boolean) => {
    console.info(`Succeeded in locking the screen. result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to lock the screen, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## screenLock.onSystemEvent<sup>9+</sup>

onSystemEvent(callback: Callback&lt;SystemEvent&gt;): boolean

Registers a callback for system events related to screen locking. This API can be called only by screen lock applications.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Required permissions**: ohos.permission.ACCESS_SCREEN_LOCK_INNER

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

For details about error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Lock Error Codes](errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 201  | permission denied.         |
| 202  | permission verification failed, application which is not a system application uses system API.         |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  try {
    let isSuccess = screenLock.onSystemEvent((event: screenLock.SystemEvent) => {
      console.info(`Succeeded in Registering the system event which related to screenlock. eventType: ${event.eventType}`);
    });
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to register the system event which related to screenlock, Code: ${error.code}, message: ${error.message}`);
  }
  ```

## screenLock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback&lt;boolean&gt;): void

Sends an event to the screen lock service. This API can be called only by screen lock applications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Required permissions**: ohos.permission.ACCESS_SCREEN_LOCK_INNER

**System API**: This is a system API.

**Parameters**

| Name   | Type           | Mandatory| Description                                                                                                               |
| --------- | ------------------------ | ---- |-------------------------------------------------------------------------------------------------------------------|
| event     | String                   | Yes  | Event type. Options are as follows:<br>- **"unlockScreenResult"**: Screen unlock result.<br>- **"lockScreenResult"**: Screen lock result.<br>- **"screenDrawDone"**: Screen drawing is complete.|
| parameter | number                   | Yes  | Result.<br>- **0**: The operation is successful. For example, the screen is locked or unlocked successfully.<br>- **1**: The operation fails. For example, screen locking or unlocking fails.<br>- **2**: The operation is canceled. For example, screen locking or unlocking is canceled. |
| callback  | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The **value** true means that the event is sent successfully, and **false** means the opposite.                                                                             |

**Error codes**

For details about error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Lock Error Codes](errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 201  | permission denied.         |
| 202  | permission verification failed, application which is not a system application uses system API.         |
| 13200002  |the screenlock management service is abnormal.         |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  screenLock.sendScreenLockEvent('unlockScreenResult', 0, (err: BusinessError, result: Boolean) => {
    if (err) {
      console.error(`Failed to send screenlock event, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in Sending screenlock event. result: ${result}`);
  });
  ```

## screenLock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number): Promise&lt;boolean&gt;

Sends an event to the screen lock service. This API can be called only by screen lock applications. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Required permissions**: ohos.permission.ACCESS_SCREEN_LOCK_INNER

**System API**: This is a system API.

**Parameters**

| Name   | Type  | Mandatory| Description                                                                                                               |
| --------- | ------ | ---- |-------------------------------------------------------------------------------------------------------------------|
| event     | String | Yes  | Event type. Options are as follows:<br>- **"unlockScreenResult"**: Screen unlock result.<br>- **"lockScreenResult"**: Screen lock result.<br>- **"screenDrawDone"**: Screen drawing is complete.|
| parameter | number | Yes  | Result.<br>- **0**: The operation is successful. For example, the screen is locked or unlocked successfully.<br>- **1**: The operation fails. For example, screen locking or unlocking fails.<br>- **2**: The operation is canceled. For example, screen locking or unlocking is canceled. |

**Return value**

| Type              | Description                                          |
| ----------------- | ---------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The **value** true means that the event is sent successfully, and **false** means the opposite.|

**Error codes**

For details about error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Lock Error Codes](errorcode-screenlock.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 201  | permission denied.         |
| 202  | permission verification failed, application which is not a system application uses system API.         |
| 13200002  | the screenlock management service is abnormal.         |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  screenLock.sendScreenLockEvent('unlockScreenResult', 0).then((result: Boolean) => {
    console.info(`Succeeded in Sending screenlock event. result: ${result}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to send screenlock event, Code: ${err.code}, message: ${err.message}`);
  });
  ```
