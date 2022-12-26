# RunningLock

The RunningLock module provides APIs for creating, querying, holding, and releasing running locks.

> **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import runningLock from '@ohos.runningLock';
```

## runningLock.isSupported<sup>9+</sup>

isSupported(type: RunningLockType): boolean;

Checks whether a specified type of **RunningLock** is supported.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type                               | Mandatory| Description                |
| ------ | ----------------------------------- | ---- | -------------------- |
| type   | [RunningLockType](#runninglocktype) | Yes  | Type of the **RunningLock** object.|

**Return value**

| Type   | Description                                   |
| ------- | --------------------------------------- |
| boolean | The value **true** indicates that the specified type of **RunningLock** is supported, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](../errorcodes/errorcode-runninglock.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    var isSupported = runningLock.isSupported(runningLock.RunningLockType.BACKGROUND);
    console.info('BACKGROUND type supported: ' + isSupported);
} catch(err) {
    console.error('check supported failed, err: ' + err);
}
```

## runningLock.create<sup>9+</sup>

create(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void

Creates a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| name     | string                                     | Yes  | Name of the **RunningLock** object.                                                  |
| type     | [RunningLockType](#runninglocktype)        | Yes  | Type of the **RunningLock** object to be created.                                          |
| callback | AsyncCallback<[RunningLock](#runninglock)> | Yes  | Callback used to return the result. If a lock is successfully created, **err** is **undefined** and **data** is the created **RunningLock**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](../errorcodes/errorcode-runninglock.md).

| Code  | Error Message    |
|---------|----------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND, (err, lock) => {
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

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Parameters**

| Name| Type                               | Mandatory| Description              |
| ------ | ----------------------------------- | ---- | ------------------ |
| name   | string                              | Yes  | Name of the **RunningLock** object.        |
| type   | [RunningLockType](#runninglocktype) | Yes  | Type of the **RunningLock** object to be created.|

**Return value**

| Type                                      | Description                                |
| ------------------------------------------ | ------------------------------------ |
| Promise&lt;[RunningLock](#runninglock)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](../errorcodes/errorcode-runninglock.md).

| Code  | Error Message    |
|---------|----------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then(lock => {
    console.info('created running lock: ' + lock);
})
.catch(err => {
    console.error('create running lock failed, error: ' + err);
});
```

## runningLock.isRunningLockTypeSupported<sup>(deprecated)</sup>

isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback&lt;boolean&gt;): void

> This API is deprecated since API version 9. You are advised to use [runningLock.isSupported](#runninglockissupported9) instead.

Checks whether a specified type of **RunningLock** is supported. This API uses an asynchronous callback to return the result.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [RunningLockType](#runninglocktype) | Yes  | Type of the **RunningLock** object.                                        |
| callback | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the query result obtained, where the value **true** indicates that **RunningLock** is supported and **false** indicates the opposite. Otherwise, **err** is an error object.|

**Example**

```js
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND, (err, data) => {
    if (typeof err === 'undefined') {
        console.info('BACKGROUND lock support status: ' + data);
    } else {
        console.log('check BACKGROUND lock support status failed, err: ' + err);
    }
});
```

## runningLock.isRunningLockTypeSupported<sup>(deprecated)</sup>

isRunningLockTypeSupported(type: RunningLockType): Promise&lt;boolean>

> This API is deprecated since API version 9. You are advised to use [runningLock.isSupported](#runninglockissupported9) instead.

Checks whether a specified type of **RunningLock** is supported. This API uses a promise to return the result.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

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
.then(data => {
    console.info('BACKGROUND lock support status: ' + data);
})
.catch(err => {
    console.log('check BACKGROUND lock support status failed, err: ' + err);
});
```

## runningLock.createRunningLock<sup>(deprecated)</sup>

createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void

> This API is deprecated since API version 9. You are advised to use [runningLock.create](#runninglockcreate9) instead.

Creates a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| name     | string                                     | Yes  | Name of the **RunningLock** object.                                                  |
| type     | [RunningLockType](#runninglocktype)        | Yes  | Type of the **RunningLock** object to be created.                                          |
| callback | AsyncCallback<[RunningLock](#runninglock)> | Yes  | Callback used to return the result. If a lock is successfully created, **err** is **undefined** and **data** is the created **RunningLock**. Otherwise, **err** is an error object.|

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND, (err, lock) => {
    if (typeof err === 'undefined') {
        console.info('created running lock: ' + lock);
    } else {
        console.error('create running lock failed, err: ' + err);
    }
});
```

## runningLock.createRunningLock<sup>(deprecated)</sup>

createRunningLock(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;

> This API is deprecated since API version 9. You are advised to use [runningLock.create](#runninglockcreate9) instead.

Creates a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

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
.then(lock => {
    console.info('created running lock: ' + lock);
})
.catch(err => {
    console.log('create running lock failed, err: ' + err);
});
```

## RunningLock

Represents a **RunningLock** object.

### hold<sup>9+</sup>

hold(timeout: number): void

Locks and holds a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Parameters**

| Name | Type  | Mandatory| Description                                     |
| ------- | ------ | ---- | ----------------------------------------- |
| timeout | number | Yes  | Duration for locking and holding the **RunningLock** object, in ms.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](../errorcodes/errorcode-runninglock.md).

| Code  | Error Message    |
|---------|----------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then(lock => {
    console.info('create running lock success');
    try {
        lock.hold(500);
        console.info('hold running lock success');
    } catch(err) {
        console.error('hold running lock failed, err: ' + err);
    }
})
.catch(err => {
    console.error('create running lock failed, err: ' + err);
});
```

### unhold<sup>9+</sup>

unhold(): void

Releases a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Error codes**

For details about the error codes, see [RunningLock Error Codes](../errorcodes/errorcode-runninglock.md).

| Code  | Error Message    |
|---------|----------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then(lock => {
    console.info('create running lock success');
    try {
        lock.unhold();
        console.info('unhold running lock success');
    } catch(err) {
        console.error('unhold running lock failed, err: ' + err);
    }
})
.catch(err => {
    console.error('create running lock failed, err: ' + err);
});
```

### isHolding<sup>9+</sup>

isHolding(): boolean

Checks the hold status of the **Runninglock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** indicates that the **Runninglock** object is held; and the value **false** indicates that the **Runninglock** object is released.|

**Error codes**

For details about the error codes, see [RunningLock Error Codes](../errorcodes/errorcode-runninglock.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then(lock => {
    console.info('create running lock success');
    try {
        var isHolding = lock.isHolding();
        console.info('check running lock holding status: ' + isHolding);
    } catch(err) {
        console.error('check running lock holding status failed, err: ' + err);
    }
})
.catch(err => {
    console.error('create running lock failed, err: ' + err);
});
```

### lock<sup>(deprecated)</sup>

lock(timeout: number): void

> This API is deprecated since API version 9. You are advised to use [RunningLock.hold](#hold9) instead.

Locks and holds a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Parameters**

| Name | Type  | Mandatory| Description                                     |
| ------- | ------ | ---- | ----------------------------------------- |
| timeout | number | Yes  | Duration for locking and holding the **RunningLock** object, in ms.|

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then(lock => {
    lock.lock(500);
    console.info('create running lock and lock success');
})
.catch(err => {
    console.error('create running lock failed, err: ' + err);
});
```

### unlock<sup>(deprecated)</sup>

unlock(): void

> This API is deprecated since API version 9. You are advised to use [RunningLock.unhold](#unhold9) instead.

Releases a **RunningLock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Required permission:** ohos.permission.RUNNING_LOCK

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then(lock => {
    lock.unlock();
    console.info('create running lock and unlock success');
})
.catch(err => {
    console.error('create running lock failed, err: ' + err);
});
```

### isUsed<sup>(deprecated)</sup>

isUsed(): boolean

> This API is deprecated since API version 9. You are advised to use [RunningLock.isHolding](#isholding9) instead.

Checks the hold status of the **Runninglock** object.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Return value**
| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** indicates that the **Runninglock** object is held; and the value **false** indicates that the **Runninglock** object is released.|

**Example**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then(lock => {
    var isUsed = lock.isUsed();
    console.info('check running lock used status: ' + isUsed);
})
.catch(err => {
    console.error('check running lock used status failed, err: ' + err);
});
```

## RunningLockType

Enumerates the types of **RunningLock** objects.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

| Name                    | Value  | Description                                  |
| ------------------------ | ---- | -------------------------------------- |
| BACKGROUND               | 1    | A lock that prevents the system from hibernating when the screen is off.                    |
| PROXIMITY_SCREEN_CONTROL | 2    | A lock that determines whether to turn on or off the screen based on the distance away from the screen.|
