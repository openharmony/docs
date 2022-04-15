# Running Lock

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Running Lock module provides APIs for creating, querying, holding, and releasing running locks.


## Modules to Import

```
import runningLock from '@ohos.runningLock';
```


## RunningLockType

Enumerates the types of **RunningLock** objects.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

| Name                      | Default Value | Description                 |
| ------------------------ | ---- | ------------------- |
| BACKGROUND               | 1    | A lock that prevents the system from hibernating when the screen is off.          |
| PROXIMITY_SCREEN_CONTROL | 2    | A lock that determines whether to turn on or off the screen based on the distance away from the screen.|


## isRunningLockTypeSupported

isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a specified type of **RunningLock** is supported. This function uses an asynchronous callback to return the result.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description                                      |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| type     | RunningLockType              | Yes   | Type of the **RunningLock** object.                              |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to obtain the return value.<br>Return value: The value **true** indicates that the specified type of **RunningLock** is supported, and the value **false** indicates the opposite.|

**Example**

```
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND, (error, supported) => {
    if (typeof error === "undefined") {
        console.info('BACKGROUND support status is ' + supported);
    } else {
        console.log('error: ' + error);
    }
})
```


## isRunningLockTypeSupported

isRunningLockTypeSupported(type: RunningLockType): Promise&lt;boolean&gt;

Checks whether a specified type of **RunningLock** is supported. This function uses an asynchronous callback to return the result.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name | Type             | Mandatory  | Description        |
| ---- | --------------- | ---- | ---------- |
| type | RunningLockType | Yes   | Type of the **RunningLock** object.|

**Return Value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to asynchronously obtain the return value.<br/>Return value: The value **true** indicates that the specified type of **RunningLock** is supported, and the value **false** indicates the opposite.|

**Example**

```
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL)
.then(supported => {
    console.info('PROXIMITY_SCREEN_CONTROL support status is ' + supported);
})
.catch(error => {
    console.log('error: ' + error);
});
```


## createRunningLock

createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void

Creates a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                    |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| name     | string                                   | Yes   | Name of the **RunningLock** object.                                 |
| type     | RunningLockType                          | Yes   | Type of the **RunningLock** object to be created.                             |
| callback | AsyncCallback&lt;[RunningLock](#runninglock)&gt; | Yes   | Callback used to obtain the return value.|

**Example**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND, (error, lockIns) => {
    if (typeof error === "undefined") {
        var used = lockIns.isUsed();
        console.info('runninglock is used: ' + used);
        lockIns.lock(500);
        used = lockIns.isUsed();
        console.info('after lock runninglock is used ' + used);
    } else {
        console.log('create runningLock test error: ' + error);
    }
})
```


## createRunningLock

createRunningLock(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;

Creates a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Parameters**

| Name | Type             | Mandatory  | Description       |
| ---- | --------------- | ---- | --------- |
| name | string          | Yes   | Name of the **RunningLock** object.    |
| type | RunningLockType | Yes   | Type of the **RunningLock** object to be created.|

**Return Value**

| Type                                      | Description                                |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;[RunningLock](#runninglock)&gt; | Promise used to asynchronously obtain the returned **RunningLock** object.|

**Example**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runninglock => {
    console.info('create runningLock success');
})
.catch(error => {
    console.log('create runningLock test error: ' + error);
})
```


## RunningLock

Defines a **RunningLock** object.


### lock

lock(timeout: number): void

Locks and holds a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Parameters**

| Name    | Type    | Mandatory  | Description                        |
| ------- | ------ | ---- | -------------------------- |
| timeout | number | No   | Duration for locking and holding the **RunningLock** object, in ms.|

**Example**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runningLock => {
    runningLock.lock(100)
    console.info('create runningLock success')
})
.catch(error => {
    console.log('create runningLock test error: ' + error)
});
```


### unlock

unlock(): void

Releases a **Runninglock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Example**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runningLock => {
    runningLock.unlock()
    console.info('create and unLock runningLock success')
})
.catch(error => {
    console.log('create runningLock test error: ' + error)
});
```


### isUsed

isUsed(): boolean

Checks the status of the **Runninglock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Return Value**
| Type     | Description                                   |
| ------- | ------------------------------------- |
| boolean | Returns **true** if the **Runninglock** object is held; returns **false** if the **Runninglock** object is released.|

**Example**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runningLock => {
    var used = runningLock.isUsed()
    console.info('runningLock used status: ' + used)
})
.catch(error => {
    console.log('runningLock isUsed test error: ' + error)
});
```
