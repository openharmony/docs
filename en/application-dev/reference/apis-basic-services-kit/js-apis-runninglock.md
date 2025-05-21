# @ohos.runningLock (Running Lock)

The **runningLock** module provides APIs for creating, querying, holding, and releasing running locks.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import {runningLock} from '@kit.BasicServicesKit';
```

## runningLock.isSupported<sup>9+</sup>

isSupported(type: RunningLockType): boolean;

Checks whether the specified type of running locks is supported.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type                               | Mandatory| Description                |
| ------ | ----------------------------------- | ---- | -------------------- |
| type   | [RunningLockType](#runninglocktype) | Yes  | Type of the running lock. The value must be an enum.|

**Return value**

| Type   | Description                                   |
| ------- | --------------------------------------- |
| boolean | The value **true** indicates that the specified type of running locks is supported, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](errorcode-runninglock.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**Example**

```js
try {
    let isSupported = runningLock.isSupported(runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL);
    console.info('BACKGROUND type supported: ' + isSupported);
} catch(err) {
    console.error('check supported failed, err: ' + err);
}
```

## runningLock.create<sup>9+</sup>

create(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void

Creates a **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Required permission**: ohos.permission.RUNNING_LOCK

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| name     | string                                     | Yes  | Name of the running lock. The value must be a string.                                                  |
| type     | [RunningLockType](#runninglocktype)        | Yes  | Type of the running lock. The value must be an enum.                                          |
| callback | AsyncCallback<[RunningLock](#runninglock)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and data is the created **RunningLock** object. Otherwise, **err** is an error object. **AsyncCallback** has encapsulated an API of the **RunningLock** class.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](errorcode-runninglock.md).

| ID  | Error Message   |
|---------|---------|
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 201     | If the permission is denied.|

**Example**

```js

runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL, (err: Error, lock: runningLock.RunningLock) => {
    if (typeof err === 'undefined') {
        console.info('created running lock: ' + lock);
    } else {
        console.error('create running lock failed, err: ' + err);
    }
});
```

## runningLock.create<sup>9+</sup>

create(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;

Creates a **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Required permission**: ohos.permission.RUNNING_LOCK

**Parameters**

| Name| Type                               | Mandatory| Description              |
| ------ | ----------------------------------- | ---- | ------------------ |
| name   | string                              | Yes  | Name of the running lock. The value must be a string.|
| type   | [RunningLockType](#runninglocktype) | Yes  | Type of the running lock. The value must be an enum.|

**Return value**

| Type                                      | Description                                |
| ------------------------------------------ | ------------------------------------ |
| Promise&lt;[RunningLock](#runninglock)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](errorcode-runninglock.md).

| ID  | Error Message   |
|---------|---------|
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 201     | If the permission is denied.|

**Example**

```js

runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL)
.then((lock: runningLock.RunningLock) => {
    console.info('created running lock: ' + lock);
})
.catch((err: Error) => {
    console.error('create running lock failed, err: ' + err);
});
```

## runningLock.isRunningLockTypeSupported<sup>(deprecated)</sup>

isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback&lt;boolean&gt;): void

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [runningLock.isSupported](#runninglockissupported9).

Checks whether the specified type of running locks is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [RunningLockType](#runninglocktype) | Yes  | Type of the **RunningLock** object.                                        |
| callback | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the query result obtained, where the value **true** indicates that the specified type of **RunningLock** is supported and **false** indicates the opposite. Otherwise, **err** is an error object.|

**Example**

```js
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND, (err: Error, data: boolean) => {
    if (typeof err === 'undefined') {
        console.info('BACKGROUND lock support status: ' + data);
    } else {
        console.log('check BACKGROUND lock support status failed, err: ' + err);
    }
});
```

## runningLock.isRunningLockTypeSupported<sup>(deprecated)</sup>

isRunningLockTypeSupported(type: RunningLockType): Promise&lt;boolean>

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [runningLock.isSupported](#runninglockissupported9).

Checks whether the specified type of running locks is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type                               | Mandatory| Description                |
| ------ | ----------------------------------- | ---- | -------------------- |
| type   | [RunningLockType](#runninglocktype) | Yes  | Type of the **RunningLock** object.|

**Return value**

| Type                  | Description                                                |
| ---------------------- | ---------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the specified type of **RunningLock** is supported, and the value **false** indicates the opposite.|

**Example**

```js
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND)
.then((data: boolean) => {
    console.info('BACKGROUND lock support status: ' + data);
})
.catch((err: Error) => {
    console.log('check BACKGROUND lock support status failed, err: ' + err);
});
```

## runningLock.createRunningLock<sup>(deprecated)</sup>

createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [runningLock.create](#runninglockcreate9).

Creates a **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Required permission**: ohos.permission.RUNNING_LOCK

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| name     | string                                     | Yes  | Name of the **RunningLock** object.                                                  |
| type     | [RunningLockType](#runninglocktype)        | Yes  | Type of the **RunningLock** object to be created.                                          |
| callback | AsyncCallback<[RunningLock](#runninglock)> | Yes  | Callback used to return the result. If a lock is successfully created, **err** is **undefined** and **data** is the created **RunningLock**. Otherwise, **err** is an error object.|

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND, (err: Error, lock: runningLock.RunningLock) => {
    if (typeof err === 'undefined') {
        console.info('created running lock: ' + lock);
    } else {
        console.error('create running lock failed, err: ' + err);
    }
});
```

## runningLock.createRunningLock<sup>(deprecated)</sup>

createRunningLock(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [runningLock.create](#runninglockcreate9).

Creates a **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Required permission**: ohos.permission.RUNNING_LOCK

**Parameters**

| Name| Type                               | Mandatory| Description              |
| ------ | ----------------------------------- | ---- | ------------------ |
| name   | string                              | Yes  | Name of the **RunningLock** object.        |
| type   | [RunningLockType](#runninglocktype) | Yes  | Type of the **RunningLock** object to be created.|

**Return value**

| Type                                      | Description                                |
| ------------------------------------------ | ------------------------------------ |
| Promise&lt;[RunningLock](#runninglock)&gt; | Promise used to return the result.|

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then((lock: runningLock.RunningLock) => {
    console.info('created running lock: ' + lock);
})
.catch((err: Error) => {
    console.log('create running lock failed, err: ' + err);
});
```

## RunningLock

Defines a **RunningLock** object.

### hold<sup>9+</sup>

hold(timeout: number): void

Locks and holds a **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Required permission**: ohos.permission.RUNNING_LOCK

**Parameters**

| Name | Type  | Mandatory| Description                                     |
| ------- | ------ | ---- | ----------------------------------------- |
| timeout | number | Yes  | Duration for locking and holding the **RunningLock** object, in ms.<br>The value must be a number:<br>**-1**: The lock is permanently held and needs to be released automatically.<br>**0**: The lock is released 3 seconds after the timer expires by default.<br>> 0: The lock is released based on the input value after the timer expires.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](errorcode-runninglock.md).

| ID  | Error Message    |
|---------|----------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1. Incorrect parameter types; |
| 201     | If the permission is denied.|

**Example**

```ts
// RunningLockTest.ets
class RunningLockTest {
    public static recordLock: runningLock.RunningLock;

    public static holdRunningLock(): void {
        if (RunningLockTest.recordLock) {
            RunningLockTest.recordLock.hold(500);
            console.info('hold running lock success');
        } else {
            runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL, (err: Error, lock: runningLock.RunningLock) => {
                if (typeof err === 'undefined') {
                    console.info('create running lock: ' + lock);
                    RunningLockTest.recordLock = lock;
                    try {
                        lock.hold(500);
                        console.info('hold running lock success');
                    } catch(err) {
                        console.error('hold running lock failed, err: ' + err);
                    }
                } else {
                    console.error('create running lock failed, err: ' + err);
                }
            });
        }
    }
}
```

### unhold<sup>9+</sup>

unhold(): void

Releases a **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Required permission**: ohos.permission.RUNNING_LOCK

**Error codes**

For details about the error codes, see [RunningLock Error Codes](errorcode-runninglock.md).

| ID  | Error Message    |
|---------|----------|
| 4900101 | Failed to connect to the service. |
| 201     | If the permission is denied.|


**Example**

```ts
// RunningLockTest.ets
class RunningLockTest {
    public static recordLock: runningLock.RunningLock;

    public static unholdRunningLock(): void {
        if (RunningLockTest.recordLock) {
            RunningLockTest.recordLock.unhold();
            console.info('hold running lock success');
        } else {
            runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL, (err: Error, lock: runningLock.RunningLock) => {
                if (typeof err === 'undefined') {
                    console.info('create running lock: ' + lock);
                    RunningLockTest.recordLock = lock;
                    try {
                        lock.unhold();
                        console.info('unhold running lock success');
                    } catch(err) {
                        console.error('unhold running lock failed, err: ' + err);
                    }
                } else {
                    console.error('create running lock failed, err: ' + err);
                }
            });
        }
    }
}
```

### isHolding<sup>9+</sup>

isHolding(): boolean

Checks the hold status of the **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** indicates that the **RunningLock** object is held; and the value **false** indicates that the **RunningLock** object is released.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](errorcode-runninglock.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |

**Example**

```ts
// RunningLockTest.ets
class RunningLockTest {
    public static recordLock: runningLock.RunningLock;

    public static isHoldingRunningLock(): void {
        if (RunningLockTest.recordLock) {
            let isHolding = RunningLockTest.recordLock.isHolding();
            console.info('check running lock holding status: ' + isHolding);
        } else {
            runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL, (err: Error, lock: runningLock.RunningLock) => {
                if (typeof err === 'undefined') {
                    console.info('create running lock: ' + lock);
                    RunningLockTest.recordLock = lock;
                    try {
                        let isHolding = lock.isHolding();
                        console.info('check running lock holding status: ' + isHolding);
                    } catch(err) {
                        console.error('check running lock holding status failed, err: ' + err);
                    }
                } else {
                    console.error('create running lock failed, err: ' + err);
                }
            });
        }
    }
}
```

### lock<sup>(deprecated)</sup>

lock(timeout: number): void

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [RunningLock.hold](#hold9).

Locks and holds a **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Required permission**: ohos.permission.RUNNING_LOCK

**Parameters**

| Name | Type  | Mandatory| Description                                     |
| ------- | ------ | ---- | ----------------------------------------- |
| timeout | number | Yes  | Duration for locking and holding the **RunningLock** object, in ms.|

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then((lock: runningLock.RunningLock) => {
    lock.lock(500);
    console.info('create running lock and lock success');
})
.catch((err: Error) => {
    console.error('create running lock failed, err: ' + err);
});
```

### unlock<sup>(deprecated)</sup>

unlock(): void

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [RunningLock.unhold](#unhold9).

Releases a **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Required permission**: ohos.permission.RUNNING_LOCK

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then((lock: runningLock.RunningLock) => {
    lock.unlock();
    console.info('create running lock and unlock success');
})
.catch((err: Error) => {
    console.error('create running lock failed, err: ' + err);
});
```

### isUsed<sup>(deprecated)</sup>

isUsed(): boolean

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [RunningLock.isHolding](#isholding9).

Checks the hold status of the **RunningLock** object.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Return value**
| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** indicates that the **RunningLock** object is held; and the value **false** indicates that the **RunningLock** object is released.|

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then((lock: runningLock.RunningLock) => {
    let isUsed = lock.isUsed();
    console.info('check running lock used status: ' + isUsed);
})
.catch((err: Error) => {
    console.error('check running lock used status failed, err: ' + err);
});
```

## RunningLockType

Enumerates the types of **RunningLock** objects.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

| Name                             | Value  | Description                                                        |
| --------------------------------- | ---- | ------------------------------------------------------------ |
| BACKGROUND<sup>(deprecated)</sup> | 1    | A lock that prevents the system from hibernating when the screen is off.<br>**NOTE**<br>This parameter is supported since API version 7 and deprecated since API version 10.|
| PROXIMITY_SCREEN_CONTROL          | 2    | A lock that enables the proximity sensor and turns on or off the screen based on the distance between the sensor and the obstacle. |
