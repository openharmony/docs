# ArkTSUtils.locks
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

To avoid data races between concurrent instances, the ArkTS common library introduces **AsyncLock**. Passing **AsyncLock** objects by reference across concurrent instances is supported.

ArkTS supports asynchronous operations, and blocking locks are prone to deadlocks. Therefore, only asynchronous locks (non-blocking locks) are used in ArkTS.

The method that uses an asynchronous lock must be marked as **async**, and the caller must use **await** in the call to ensure the correct call sequence. As a result, all outer functions are marked as **async**.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

## Modules to Import

```ts
import { ArkTSUtils } from '@kit.ArkTS'
```

## AsyncLockCallback

type AsyncLockCallback\<T> = () => T | Promise\<T>

A supplementary type alias that represents the callback in all the overloads of [lockAsync](#lockasync).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

## AsyncLock

A class that implements an asynchronous lock and allows asynchronous operations to be performed under a lock. This class is decorated by [@Sendable](../../arkts-utils/arkts-sendable.md).

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type  | Read-Only| Optional| Description      |
| ---- | ------ | ---- | ---- | ---------- |
| name | string | Yes  | No  | Name of the lock.|

**Example**

```ts
// Example 1
@Sendable
class A {
  count_: number = 0;
  async getCount(): Promise<number> {
    let lock: ArkTSUtils.locks.AsyncLock = ArkTSUtils.locks.AsyncLock.request("lock_1");
    return lock.lockAsync(() => {
      return this.count_;
    })
  }
  async setCount(count: number) {
    let lock: ArkTSUtils.locks.AsyncLock = ArkTSUtils.locks.AsyncLock.request("lock_1");
    await lock.lockAsync(() => {
      this.count_ = count;
    })
  }
}

// Example 2
@Sendable
class A {
  count_: number = 0;
  lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();
  async getCount(): Promise<number> {
    return this.lock_.lockAsync(() => {
      return this.count_;
    })
  }
  async setCount(count: number) {
    await this.lock_.lockAsync(() => {
      this.count_ = count;
    })
  }
}

@Concurrent
async function foo(a: A) {
  await a.setCount(10)
}
```

### constructor

constructor()

Default constructor used to create an asynchronous lock.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
```

### request

static request(name: string): AsyncLock

Finds or creates (if not found) an **AsyncLock** instance with the specified name.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ---- | ------ | ---- | -------------------------------- |
| name | string | Yes  | Name of the lock.|

**Return value**

| Type                   | Description                            |
| ----------------------- | -------------------------------- |
| [AsyncLock](#asynclock) | **AsyncLock** instance found or created.|

**Example**

```ts
let lockName = 'isAvailableLock';
let lock = ArkTSUtils.locks.AsyncLock.request(lockName);
```

### query

static query(name: string): AsyncLockState

Queries information about an asynchronous lock.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                    |
| ---- | ------ | ---- | ------------------------------------------------------------------------------------------------------------------------ |
| name | string | Yes  | Name of the lock. Only locks obtained through the [request](#request) API can be queried, meaning that the lock name must match the parameter passed to the [request](#request) API.|

**Return value**

| Type                             | Description                              |
| --------------------------------- | ---------------------------------- |
| [AsyncLockState](#asynclockstate) | **AsyncLockState** instance that contains the lock state information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message     |
| -------- | ------------- |
| 401      | The input parameters are invalid. |
| 10200030 | The lock does not exist. |

**Example**

```ts
// You have created a lock somewhere else.
// let lock = ArkTSUtils.locks.AsyncLock.request("queryTestLock");
let state = ArkTSUtils.locks.AsyncLock.query('queryTestLock');
if (!state) {
    throw new Error('Test failed: A valid state is expected, but the obtained state is '+ state);
}
let pending: ArkTSUtils.locks.AsyncLockInfo[] = state.pending;
let held: ArkTSUtils.locks.AsyncLockInfo[] = state.held;
```

### queryAll

static queryAll(): AsyncLockState[]

Queries information about all existing asynchronous locks.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                               | Description                            |
| ----------------------------------- | -------------------------------- |
| [AsyncLockState](#asynclockstate)[] | **AsyncLockState** array that contains the lock state information.|

**Example**

```ts
let states: ArkTSUtils.locks.AsyncLockState[] = ArkTSUtils.locks.AsyncLock.queryAll();
if (states.length === 0) {
    throw new Error('Test failed: At least one state is expected, but what got is ' + states.length);
}
```

### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>): Promise\<T>

Performs an operation under a lock. This API acquires the lock, executes the callback, and releases the lock. The callback is executed asynchronously in the same thread where [lockAsync](#lockasync) was called.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                   | Mandatory| Description                  |
| -------- | --------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback\<T>](#asynclockcallback) | Yes  | Callback to be executed after a lock is acquired.|

**Return value**

| Type       | Description                       |
| ----------- | --------------------------- |
| Promise\<T> | Promise that will be resolved after the callback is executed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message     |
| -------- | ------------- |
| 401      | The input parameters are invalid. |
| 10200030 | The lock does not exist. |

**Example**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
let p1 = lock.lockAsync<void>(() => {
    // Perform an operation.
});
```

### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode): Promise\<T>

Performs an operation under a lock. This API acquires the lock, executes the callback, and releases the lock. The callback is executed asynchronously in the same thread where [lockAsync](#lockasync) was called.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                   | Mandatory| Description                  |
| -------- | --------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback\<T>](#asynclockcallback) | Yes  | Callback to be executed after a lock is acquired.|
| mode     | [AsyncLockMode](#asynclockmode)         | Yes  | Mode of the lock.        |

**Return value**

| Type       | Description                       |
| ----------- | --------------------------- |
| Promise\<T> | Promise that will be resolved after the callback is executed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message     |
| -------- | ------------- |
| 401      | The input parameters are invalid. |
| 10200030 | The lock does not exist. |

**Example**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
let p1 = lock.lockAsync<void>(() => {
    // Perform an operation.
}, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE);
```

### lockAsync

lockAsync\<T, U>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode, options: AsyncLockOptions\<U>): Promise\<T | U>

Performs an operation under a lock. This API acquires the lock, executes the callback, and releases the lock. The callback is executed asynchronously in the same thread where [lockAsync](#lockasync) was called. An optional timeout value can be provided in [AsyncLockOptions](#asynclockoptions). If a lock is not acquired before timeout, **lockAsync** returns a projected Promise with a **BusinessError** instance. In this instance, the error message contains information about the locks being held and in the waiting state, as well as possible deadlock warnings.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                     | Mandatory| Description                  |
| -------- | ----------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback\<T>](#asynclockcallback)   | Yes  | Callback to be executed after a lock is acquired.|
| mode     | [AsyncLockMode](#asynclockmode)           | Yes  | Mode of the lock.        |
| options  | [AsyncLockOptions\<U>](#asynclockoptions) | Yes  | Options of the lock.        |

**Return value**

| Type            | Description                                              |
| ---------------- | -------------------------------------------------- |
| Promise\<T \| U> | Promise that will be resolved after the callback is executed, or rejected in the case of timeout.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message         |
| -------- | ----------------- |
| 401      | The input parameters are invalid. |
| 10200030 | The lock does not exist.     |
| 10200031 | Timeout exceeded. |

**Example**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
let options = new ArkTSUtils.locks.AsyncLockOptions<void>();
options.timeout = 1000;
let p: Promise<void> = lock.lockAsync<void, void>(
    () => {
        // Perform an operation.
    },
    ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE,
    options
);
```

## AsyncLockMode

Enumerates the modes of an asynchronous lock.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name     | Value | Description                                                    |
| --------- | --- | -------------------------------------------------------- |
| SHARED    | 1   | Shared lock mode, in which multiple threads can run at the same time.  |
| EXCLUSIVE | 2   | Exclusive lock mode, in which a thread can run only when it exclusively acquires the lock.|

**Example**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
// shared0 can acquire the lock and start execution.
lock.lockAsync(async () => {
    console.info('shared0');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.SHARED);
// shared1 can acquire the lock and start execution without waiting for shared0.
lock.lockAsync(async () => {
    console.info('shared1');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.SHARED);
// exclusive0 can acquire the lock and start execution after shared0 and shared1 are executed.
lock.lockAsync(async () => {
    console.info('exclusive0');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE);
// shared2 can acquire the lock and start execution after exclusive0 is executed.
lock.lockAsync(async () => {
    console.info('shared2');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.SHARED);
// shared3 can acquire the lock and start execution after exclusive0 is executed, but not after shared2 is executed.
lock.lockAsync(async () => {
    console.info('shared3');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.SHARED);
```

## AsyncLockOptions

class AsyncLockOptions\<T>

Class that implements the asynchronous lock options.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

### constructor

constructor()

Default constructor used to create an **AsyncLockOptions** instance with the default values for all properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let s: ArkTSUtils.locks.AbortSignal<string> = { aborted: false, reason: 'Aborted' };
let options = new ArkTSUtils.locks.AsyncLockOptions<string>();
options.isAvailable = false;
options.signal = s;
let lock = new ArkTSUtils.locks.AsyncLock();
let p = lock.lockAsync<void, string>(
  () => {
    // Perform an operation.
  },
  ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE,
  options,
);
```

### Properties

| Name       | Type                                 | Read-Only| Optional| Description                                                                                                                                                                |
| ----------- | ------------------------------------- | ---- | ---- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| isAvailable | boolean                               | No  | No  | Whether the lock is available. If the value is **true**, a lock is granted only when it is not held. If the value is **false**, a lock is granted once it is released. The default value is **false**.                                           |
| signal      | [AbortSignal\<T>](#abortsignal)\|null | No  | No  | A class that implements a signal used to abort an asynchronous operation. If **signal.aborted** is **true**, the lock request is discarded. If **signal.aborted** is **false**, the request keeps waiting. If **signal.aborted** is **null**, the request is queued normally. The default value is **null**.|
| timeout     | number                                | No  | No  | Timeout of the lock, in milliseconds. If the value is greater than zero and the operation exceeds this duration, [lockAsync](#lockasync) returns a rejected Promise. The default value is **0**.                                          |

## AsyncLockState

A class used to store information about all lock operations currently performed on an **AsyncLock** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

### Properties

| Name   | Type                             | Read-Only| Optional| Description            |
| ------- | --------------------------------- | ---- | ---- | ---------------- |
| held    | [AsyncLockInfo[]](#asynclockinfo) | No  | No  | Information about the lock being held.  |
| pending | [AsyncLockInfo[]](#asynclockinfo) | No  | No  | Information about the lock in the waiting state.|

## AsyncLockInfo

Describes the information about a lock.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

### Properties

| Name     | Type                           | Read-Only| Optional| Description                                                     |
| --------- | ------------------------------- | ---- | ---- | --------------------------------------------------------- |
| name      | string                          | No  | No  | Name of the lock.                                               |
| mode      | [AsyncLockMode](#asynclockmode) | No  | No  | Mode of the lock.                                               |
| contextId | number                          | No  | No  | Context identifier of the caller of [AsyncLockMode](#asynclockmode).|

## AbortSignal

A class that implements a signal used to abort an asynchronous operation. An instance of this class must be accessed in the same thread it creates. Otherwise, undefined behavior occurs.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

### Properties

| Name   | Type   | Read-Only| Optional| Description                                                                       |
| ------- | ------- | ---- | ---- | --------------------------------------------------------------------------- |
| aborted | boolean | No  | No  | Whether to abort the asynchronous operation. The value **true** means to abort the asynchronous operation, and **false** means the opposite.|
| reason  | T       | No  | No  | Reason for aborting the asynchronous operation. This value will be used in the rejected Promise returned by [lockAsync](#lockasync).           |

## ConditionVariable<sup>18+</sup>

A class that implements asynchronous waiting, supporting asynchronous wait and notify operations. This class is decorated by [@Sendable](../../arkts-utils/arkts-sendable.md).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

### constructor<sup>18+</sup>

constructor()

Default constructor used to create an object for asynchronous wait and notify operations.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let conditionVariable = new ArkTSUtils.locks.ConditionVariable();
```

### request<sup>18+</sup>

static request(name: string): ConditionVariable

Looks up or creates (if not found) an object for asynchronous wait and notify operations based on the specified name.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ---- | ------ | ---- | -------------------------------- |
| name | string | Yes  | Name used to identify the object for asynchronous wait and notify operations.|

**Return value**

| Type                   | Description                            |
| ----------------------- | -------------------------------- |
| [ConditionVariable](#conditionvariable18) | Object for asynchronous wait and notify operations.|

**Example**

```ts
let conditionVariable = ArkTSUtils.locks.ConditionVariable.request("conditionName");
```

### wait<sup>18+</sup>

wait(): Promise\<void>

Asynchronously waits until notified. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type       | Description                       |
| ----------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
const conditionVariable: ArkTSUtils.locks.ConditionVariable = new ArkTSUtils.locks.ConditionVariable();
conditionVariable.wait().then(() => {
  console.info(`Thread being awakened, then continue...`); // Output logs upon awakening.
});
```

### waitFor<sup>18+</sup>

waitFor(timeout : number) : Promise\<void>

Asynchronously waits for a specified duration or until notified. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description      |
| -------- | -------- | ---- | ---------- |
| timeout | number | Yes  | Duration to wait, in ms. The value is a positive integer.|

**Return value**

| Type       | Description                       |
| ----------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
const conditionVariable: ArkTSUtils.locks.ConditionVariable = new ArkTSUtils.locks.ConditionVariable();
conditionVariable.waitFor(3000).then(() => {
  console.info(`Thread being awakened, then continue...`); // Output logs upon awakening.
});
```

### notifyAll<sup>18+</sup>

notifyAll() : void

Notifies all waiting threads.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
const conditionVariable: ArkTSUtils.locks.ConditionVariable = new ArkTSUtils.locks.ConditionVariable();
conditionVariable.waitFor(3000).then(() => {
  console.info(`Thread being awakened, then continue...`); // Output logs upon awakening.
});
// Notify all waiting threads.
conditionVariable.notifyAll();
```

### notifyOne<sup>18+</sup>

notifyOne() : void

Notifies the first waiting thread.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
const conditionVariable: ArkTSUtils.locks.ConditionVariable = new ArkTSUtils.locks.ConditionVariable();
conditionVariable.waitFor(3000).then(() => {
  console.info(`Thread a being awakened, then continue...`); // Output logs upon awakening.
});
// Notify the first waiting thread.
conditionVariable.notifyOne();
```
