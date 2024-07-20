# @arkts.utils (ArkTS Utils)

The ArkTSUtils module provides a variety of ArkTS utility functions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { ArkTSUtils } from '@kit.ArkTS'
```

## ArkTSUtils.locks

To avoid data races between concurrent instances, the ArkTS common library introduces **AsyncLock**. Passing **AsyncLock** objects by reference across concurrent instances is supported.

ArkTS supports asynchronous operations, and blocking locks are prone to deadlocks. Therefore, only asynchronous locks (non-blocking locks) are used in ArkTS.

The method that uses an asynchronous lock must be marked as **async**, and the caller must use **await** in the call to ensure the correct call sequence. As a result, all outer functions are marked as **async**.

### AsyncLockCallback

type AsyncLockCallback\<T> = () => T | Promise\<T>

A supplementary type alias that represents the callback in all the overloads of [lockAsync](#lockasync).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

### AsyncLock

A class that implements an asynchronous lock and allows asynchronous operations to be performed under a lock.

#### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type  | Readable| Writable| Description      |
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

#### constructor

constructor()

Default constructor used to create an asynchronous lock.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                   | Description              |
| ----------------------- | ------------------ |
| [AsyncLock](#asynclock) | **AsyncLock** instance created.|

**Example**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
```

#### request

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

#### query

static query(name: string): AsyncLockState

Queries information about an asynchronous lock.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description      |
| ---- | ------ | ---- | ---------- |
| name | string | Yes  | Name of the lock.|

**Return value**

| Type                             | Description                              |
| --------------------------------- | ---------------------------------- |
| [AsyncLockState](#asynclockstate) | **AsyncLockState** instance that contains the lock state information.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message     |
| -------- | ------------- |
| 10200030 | No such lock. |

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

#### queryAll

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
if (states.length == 0) {
    throw new Error ('Test failed: At least one state is expected, but what got is ' + states.length);
}
```

#### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>): Promise\<T>

Performs an operation exclusively under a lock. This API acquires the lock, executes the callback, and releases the lock. The callback is executed asynchronously in the same thread where [lockAsync](#lockasync) was called.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                   | Mandatory| Description                  |
| -------- | --------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback](#asynclockcallback) | Yes  | Callback to be executed after a lock is acquired.|

**Return value**

| Type       | Description                       |
| ----------- | --------------------------- |
| Promise\<T> | Promise that will be resolved after the callback is executed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message     |
| -------- | ------------- |
| 10200030 | No such lock. |

**Example**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
let p1 = lock.lockAsync<void>(() => {
    // Perform an operation.
});
```

#### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode): Promise\<T>

Performs an operation under a lock. This API acquires the lock, executes the callback, and releases the lock. The callback is executed asynchronously in the same thread where [lockAsync](#lockasync) was called.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                   | Mandatory| Description                  |
| -------- | --------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback](#asynclockcallback) | Yes  | Callback to be executed after a lock is acquired.|
| mode     | [AsyncLockMode](#asynclockmode)         | Yes  | Mode of the lock.        |

**Return value**

| Type       | Description                       |
| ----------- | --------------------------- |
| Promise\<T> | Promise that will be resolved after the callback is executed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message     |
| -------- | ------------- |
| 10200030 | No such lock. |

**Example**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
let p1 = lock.lockAsync<void>(() => {
    // Perform an operation.
}, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE);
```

#### lockAsync

lockAsync\<T, U>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode, options: AsyncLockOptions\<U>): Promise\<T | U>

Performs an operation under a lock. This API acquires the lock, executes the callback, and releases the lock. The callback is executed asynchronously in the same thread where [lockAsync](#lockasync) was called. An optional timeout value can be provided in [AsyncLockOptions](#asynclockoptions). If a lock is not acquired before timeout, **lockAsync** returns a projected Promise with a **BusinessError** instance. In this instance, the error message contains information about the locks being held and in the waiting state, as well as possible deadlock warnings.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                     | Mandatory| Description                  |
| -------- | ----------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback](#asynclockcallback)   | Yes  | Callback to be executed after a lock is acquired.|
| mode     | [AsyncLockMode](#asynclockmode)           | Yes  | Mode of the lock.        |
| options  | [AsyncLockOptions\<U>](#asynclockoptions) | Yes  | Options of the lock.        |

**Return value**

| Type            | Description                                              |
| ---------------- | -------------------------------------------------- |
| Promise\<T \| U> | Promise that will be resolved after the callback is executed, or rejected in the case of timeout.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message         |
| -------- | ----------------- |
| 10200030 | No such lock.     |
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

### AsyncLockMode

Enumerates the modes of an asynchronous lock.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name     | Value | Description                                                    |
| --------- | --- | -------------------------------------------------------- |
| SHARED    | 1   | Shared lock. An operation can be reentrant in the same thread.|
| EXCLUSIVE | 2   | Exclusive lock. An operation is performed only when the lock is exclusively acquired.|

### AsyncLockOptions

class AsyncLockOptions\<T>

Class that implements the asynchronous lock options.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

#### constructor

constructor()

Default constructor used to create an **AsyncLockOptions** instance with the default values for all attributes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                                 | Description                  |
| ------------------------------------- | ---------------------- |
| [AsyncLockOptions](#asynclockoptions) | **AsyncLockOptions** instance created.|

**Example**

```ts
let s: ArkTSUtils.locks.AbortSignal<string> = { aborted: false, reason: 'Aborted' };
let options = new ArkTSUtils.locks.AsyncLockOptions<string>();
options.isAvailable = false;
options.signal = s;
```

#### Attributes

| Name       | Type                                 | Readable| Writable| Description                                                                                                                     |
| ----------- | ------------------------------------- | ---- | ---- | ------------------------------------------------------------------------------------------------------------------------- |
| isAvailable | boolean                               | Yes  | Yes  | Whether the lock is available. If the value is **true**, a lock is granted only when it is not held. If the value is **false**, a lock is granted once it is released. The default value is **false**.|
| signal      | [AbortSignal\<T>](#abortsignal)\|null | Yes  | Yes  | Signal used to abort an asynchronous operation. If **signal.aborted** is **true**, the lock request is discarded. If **signal.aborted** is **null**, the request is queued normally. The default value is **null**.              |
| timeout     | number                                | Yes  | Yes  | Timeout interval of the lock request, in milliseconds. If the value is greater than zero and a lock is not acquired before time, [lockAsync](#lockasync) returns a rejected Promise. The default value is **0**.     |

### AsyncLockState

A class used to store information about all lock operations currently performed on an **AsyncLock** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

#### Attributes

| Name   | Type                             | Readable| Writable| Description            |
| ------- | --------------------------------- | ---- | ---- | ---------------- |
| held    | [AsyncLockInfo[]](#asynclockinfo) | Yes  | Yes  | Information about the lock being held.  |
| pending | [AsyncLockInfo[]](#asynclockinfo) | Yes  | Yes  | Information about the lock in the waiting state.|

### AsyncLockInfo

Describes the information about a lock.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

#### Attributes

| Name     | Type                           | Readable| Writable| Description                                                     |
| --------- | ------------------------------- | ---- | ---- | --------------------------------------------------------- |
| name      | string                          | Yes  | Yes  | Name of the lock.                                               |
| mode      | [AsyncLockMode](#asynclockmode) | Yes  | Yes  | Mode of the lock.                                               |
| contextId | number                          | Yes  | Yes  | Context identifier of the caller of [AsyncLockMode](#asynclockmode).|

### AbortSignal

A class that implements a signal used to abort an asynchronous operation. An instance of this class must be accessed in the same thread it creates. Otherwise, undefined behavior occurs.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

#### Attributes

| Name   | Type   | Readable| Writable| Description                                                            |
| ------- | ------- | ---- | ---- | ---------------------------------------------------------------- |
| aborted | boolean | Yes  | Yes  | Whether to abort the operation. The value **true** means to abort the operation, and **false** means the opposite.                                          |
| reason  | \<T>    | Yes  | Yes  | Reason for abort. This value will be used in the rejected Promise returned by [lockAsync](#lockasync).|

## ArkTSUtils.ASON

A utility class used to parse JSON strings into sendable data. ASON allows you to parse JSON strings and generate data that can be passed across concurrency domains. It also supports conversion from sendable data into JSON strings.

### ISendable

type ISendable = lang.ISendable

**ISendable** is the parent type of all sendable types except null and undefined. It does not have any necessary methods or properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Type| Description  |
| ------ | ------ |
| [lang.ISendable](js-apis-arkts-lang.md#langisendable)   | Parent type of all sendable types.|

### parse

parse(text: string): ISendable | null

Parses a JSON string to generate ISendable data or null.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| text   | string | Yes| Valid JSON string.|

**Return value**

| Type| Description|
| -------- | -------- |
| [ISendable](#isendable) \| null | ISendable data or **null** (if **null** is passed in).|

**Example**

```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;
let jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = ArkTSUtils.ASON.parse(jsonText) as ISendable;
console.info((obj as object)?.["name"]);
// Expected output: 'John'
console.info((obj as object)?.["age"]);
// Expected output: 30
console.info((obj as object)?.["city"]);
// Expected output: 'ChongQing'
```

### stringify

stringify(value: ISendable | null | undefined): string

Converts ISendable data into a JSON string.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | [ISendable](#isendable) \| null \| undefined  | Yes| ISendable data.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | JSON string.|

**Example**

```ts
import { collections } from '@kit.ArkTS';

let arr = new collections.Array(1, 2, 3);
let str = ArkTSUtils.ASON.stringify(arr);
console.info(str);
// Expected output: '[1,2,3]'
```
