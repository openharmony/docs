# @arkts.utils (ArkTS Utils)

The Utils module provides a variety of ArkTS utility functions.

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
| 10200030 | The lock does not exist. |

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
| 10200030 | The lock does not exist. |

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

### AsyncLockMode

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
    console.log('shared0');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.SHARED);
// shared1 can acquire the lock and start execution without waiting for shared0.
lock.lockAsync(async () => {
    console.log('shared1');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.SHARED);
// exclusive0 can acquire the lock and start execution after shared0 and shared1 are executed.
lock.lockAsync(async () => {
    console.log('exclusive0');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE);
// shared2 can acquire the lock and start execution after exclusive0 is executed.
lock.lockAsync(async () => {
    console.log('shared2');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.SHARED);
// shared3 can acquire the lock and start execution after exclusive0 is executed, but not after shared2 is executed.
lock.lockAsync(async () => {
    console.log('shared3');
    await new Promise<void>((resolve) => setTimeout(resolve, 1000));
}, ArkTSUtils.locks.AsyncLockMode.SHARED);
```

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

A utility class used to parse JSON strings into [sendable data](../../arkts-utils/arkts-sendable.md#sendable-data-types). ASON allows you to parse JSON strings and generate data that can be passed across concurrency domains. It also supports conversion from sendable data into JSON strings.

### ISendable

type ISendable = lang.ISendable

**ISendable** is the parent type of all sendable types except null and undefined. It does not have any necessary methods or properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Type| Description  |
| ------ | ------ |
| [lang.ISendable](js-apis-arkts-lang.md#langisendable)   | Parent type of all sendable types.|

### Transformer

type Transformer = (this: ISendable, key: string, value: ISendable | undefined | null) => ISendable | undefined | null

Defines the type of the conversion result function.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| this   | [ISendable](#isendable) | Yes| Object to which the key-value pair to parse belongs.|
| key  | string | Yes| Key to parse.|
| value  | [ISendable](#isendable) | Yes| Value of the key.|

**Return value**

| Type| Description|
| -------- | -------- |
| [ISendable](#isendable) \| undefined \| null | **ISendable** object, undefined, or null.|

### BigIntMode

Enumerates the modes for processing BigInt.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Value| Description           |
| ------ | ------ | --------------- |
| DEFAULT   | 0 |BigInt is not supported.|
| PARSE_AS_BIGINT   | 1 |Parses an integer that is less than -(2^53-1) or greater than (2^53-1) as BigInt.|
| ALWAYS_PARSE_AS_BIGINT   | 2 |Parses all integers as BigInt.|

### ParseReturnType

Enumerates the return types of the parsing result.

**System capability**: SystemCapability.Utils.Lang

| Name| Value| Description           |
| ------ | ------ | --------------- |
| OBJECT   | 0 |Returns a **SendableObject** object.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| MAP<sup>13+</sup>   | 1 |Returns a **SendableMap** object.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|

### ParseOptions

Describes the parsing options, which defines the BigInt processing mode and the return type of the parsing result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| bigIntMode   | [BigIntMode](#bigintmode) | Yes|Mode for processing BigInt.|
| parseReturnType   | [ParseReturnType](#parsereturntype) | Yes|Return type of the parsing result.|

### parse

parse(text: string, reviver?: Transformer, options?: ParseOptions): ISendable | null

Parses a JSON string to generate ISendable data or null.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| text   | string | Yes| Valid JSON string.|
| reviver   | [Transformer](#transformer) | No| Conversion function. This parameter can be used to modify the value generated after parsing. The default value is undefined. Currently, only undefined can be passed in.|
| options   | [ParseOptions](#parseoptions) | No| Parsing options. This parameter is used to control the type of the parsing result. The default value is undefined.|

**Return value**

| Type| Description|
| -------- | -------- |
| [ISendable](#isendable) \| null | ISendable data or **null** (if **null** is passed in).|

**Example**

```ts
import { lang } from '@kit.ArkTS';
import { collections } from '@kit.ArkTS';

type ISendable = lang.ISendable;
let jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = ArkTSUtils.ASON.parse(jsonText) as ISendable;
console.info((obj as object)?.["name"]);
// Expected output: 'John'
console.info((obj as object)?.["age"]);
// Expected output: 30
console.info((obj as object)?.["city"]);
// Expected output: 'ChongQing'

let options: ArkTSUtils.ASON.ParseOptions = {
  bigIntMode: ArkTSUtils.ASON.BigIntMode.PARSE_AS_BIGINT,
  parseReturnType: ArkTSUtils.ASON.ParseReturnType.OBJECT,
}
let numberText = '{"largeNumber":112233445566778899}';
let numberObj = ArkTSUtils.ASON.parse(numberText,undefined,options) as ISendable;

console.info((numberObj as object)?.["largeNumber"]);
// Expected output: 112233445566778899

let options2: ArkTSUtils.ASON.ParseOptions = {
    bigIntMode: ArkTSUtils.ASON.BigIntMode.PARSE_AS_BIGINT,
    parseReturnType: ArkTSUtils.ASON.ParseReturnType.MAP,
  }
let mapText = '{"largeNumber":112233445566778899}';
let map  = ArkTSUtils.ASON.parse(mapText,undefined,options2);
console.info("map is " + map);
// Expected output: map is [object SendableMap]
console.info("largeNumber is " + (map as collections.Map<string,bigint>).get("largeNumber"));
// Expected output: largeNumber is 112233445566778899
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

### isSendable

isSendable(value: Object | null | undefined): boolean

Checks whether the passed-in value is of the sendable data type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | Object \| null \| undefined  | Yes| Object to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** means that the passed-in value is of the sendable data type, and **false** means the opposite.|

**Example**

```ts
import { ArkTSUtils } from '@kit.ArkTS'

@Sendable
function sendableFunc()
{
  console.info("sendableFunc")
}

if (ArkTSUtils.isSendable(sendableFunc)) {
  console.info("sendableFunc is Sendable");
} else {
  console.info("sendableFunc is not Sendable");
}
// Expected output: 'SendableFunc is Sendable'
```
