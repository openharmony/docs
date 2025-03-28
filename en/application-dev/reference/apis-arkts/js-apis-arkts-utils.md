# @arkts.utils (ArkTS Utils)

The Utils module provides a variety of ArkTS utility functions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

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
    throw new Error('Test failed: At least one state is expected, but what got is ' + states.length);
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

### ConditionVariable<sup>18+</sup>

A class that implements asynchronous waiting, enabling asynchronous wait and notify operations.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

#### constructor<sup>18+</sup>

constructor()

Default constructor used to create an object for asynchronous wait and notify operations.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let conditionVariable = new ArkTSUtils.locks.ConditionVariable();
```

#### request<sup>18+</sup>

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
let conditionVariable = ArkTSUtils.locks.ConditionVariable.request("conditionName");
```

#### wait<sup>18+</sup>

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
let conditionVariable = ArkTSUtils.locks.AsyncLock.ConditionVariable();
conditionVariable.wait().then(() => {
  console.info(`Thread being awakened, then continue...`); // Output logs upon awakening.
});
```

#### waitFor<sup>18+</sup>

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
let conditionVariable = ArkTSUtils.locks.AsyncLock.ConditionVariable();
conditionVariable.waitFor(3000).then(() => {
  console.info(`Thread being awakened, then continue...`); // Output logs upon awakening.
});
```

#### notifyAll<sup>18+</sup>

notifyAll() : void

Notifies all waiting threads.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let conditionVariable = ArkTSUtils.locks.AsyncLock.ConditionVariable();
conditionVariable.waitFor(3000).then(() => {
  console.info(`Thread being awakened, then continue...`); // Output logs upon awakening.
});
conditionVariable.notifyAll();
```

#### notifyOne<sup>18+</sup>

notifyOne() : void

Notifies the first waiting thread.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let conditionVariable = ArkTSUtils.locks.AsyncLock.ConditionVariable();
conditionVariable.waitFor(3000).then(() => {
  console.info(`Thread a being awakened, then continue...`); // Output logs upon awakening.
});
conditionVariable.waitFor().then(() => {
  console.info(`Thread twob being awakened, then continue...`); // Output logs upon awakening.
});
conditionVariable.notifyOne();
```

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

### stringify<sup>18+</sup>

stringify(value: Object | null | undefined): string

Converts ArkTS object data into a JSON string, with additional support for Map and Set types.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | Object \| null \| undefined  | Yes| ArkTS object data.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | JSON string.|

**Example**

```ts
import { ArkTSUtils, collections, HashMap, HashSet } from '@kit.ArkTS';

let hashMap = new HashMap<string,string>();
hashMap.set("ha","a");
hashMap.set("sh","b");
hashMap.set("map","c");
let str1 = ArkTSUtils.ASON.stringify(hashMap);
console.info(str1);
// Expected output: '{"sh":"b","ha":"a","map":"c"}'
let hashSet = new HashSet<string>();
hashSet.add("ha");
hashSet.add("sh");
hashSet.add("set");
let str2 = ArkTSUtils.ASON.stringify(hashSet);
console.info(str2);
// Expected output: '["set","sh","ha"]'
let map = new Map<string,string>();
map.set("m","a");
map.set("a","b");
map.set("p","c");
let str3 = ArkTSUtils.ASON.stringify(map);
console.info(str3);
// Expected output: '{"m":"a","a":"b","p":"c"}'
let set = new Set<string>();
set.add("s");
set.add("e");
set.add("t");
let str4 = ArkTSUtils.ASON.stringify(set);
console.info(str4);
// Expected output: '["s","e","t"]'
let sendableMap = new collections.Map<string,string>();
sendableMap.set("send","a");
sendableMap.set("able","b");
sendableMap.set("map","c");
let str5 = ArkTSUtils.ASON.stringify(sendableMap);
console.info(str5);
// Expected output: '{"send":"a","able":"b","map":"c"}'
let sendableSet = new collections.Set<string>();
sendableSet.add("send");
sendableSet.add("able");
sendableSet.add("set");
let str6 = ArkTSUtils.ASON.stringify(sendableSet);
console.info(str6);
// Expected output: '["send","able","set"]'
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
function sendableFunc() {
  console.info("sendableFunc")
}

if (ArkTSUtils.isSendable(sendableFunc)) {
  console.info("sendableFunc is Sendable");
} else {
  console.info("sendableFunc is not Sendable");
}
// Expected output: 'SendableFunc is Sendable'
```

## SendableLruCache<K, V><sup>18+</sup>

Provides APIs to discard the least recently used data to make rooms for new elements when the cache is full. This class uses the Least Recently Used (LRU) algorithm, which believes that the recently used data may be accessed again in the near future and the least accessed data is the least valuable data and should be removed from the cache. **SendableLruCache** supports the Sendable feature, allowing it to store Sendable objects, which can be accessed safely across threads.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

| Name  | Type  | Readable| Writable| Description                  |
| ------ | ------ | ---- | ---- | ---------------------- |
| length | number | Yes  | No  | Total number of values in this cache.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.put(1, 8);
let result = pro.length;
console.info('result = ' + result);
// Expected output: result = 2
```

### constructor<sup>18+</sup>

constructor(capacity?: number)

A constructor used to create a **SendableLruCache** instance. The default capacity of the cache is 64.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type  | Mandatory| Description                        |
| -------- | ------ | ---- | ---------------------------- |
| capacity | number | No  | Capacity of the cache to create. The default value is **64**, and the maximum value is **2147483647**.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
```

### updateCapacity<sup>18+</sup>

updateCapacity(newCapacity: number): void

Changes the cache capacity. If the total number of values in the cache is greater than the specified capacity, the least used key-value pairs are deleted.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name     | Type  | Mandatory| Description                        |
| ----------- | ------ | ---- | ---------------------------- |
| newCapacity | number | Yes  | New capacity of the cache. The maximum value is 2147483647. If the value is less than or equal to 0, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                   |
| -------- | ------------------------------------------|
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.updateCapacity(100);
```

### toString<sup>18+</sup>

toString(): string

Obtains the string representation of this cache.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | String representation of the cache, in the format of SendableLruCache[ maxSize = (maxSize), hits = (hitCount), misses = (missCount), hitRate = (hitRate) ], where **(maxSize)** indicates the maximum size of the cache, **(hitCount)** indicates the number of matched queries, **(missCount)** indicates the number of times that the number of mismatched queries, and **(hitRate)** indicates the matching rate.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.get(2);
pro.get(3);
console.info(pro.toString());
// Expected output: SendableLruCache[ maxSize = 64, hits = 1, misses = 1, hitRate = 50% ]
// maxSize: maximum size of the cache. hits: number of matched queries. misses: number of mismatched queries. hitRate: matching rate.
```

### getCapacity<sup>18+</sup>

getCapacity(): number

Obtains the capacity of this cache.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| number | Capacity of the cache.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
let result = pro.getCapacity();
console.info('result = ' + result);
// Expected output: result = 64
```

### clear<sup>18+</sup>

clear(): void

Clears all key-value pairs from this cache.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.length;
pro.clear();
let res = pro.length;
console.info('result = ' + result);
console.info('res = ' + res);
// Expected output: result = 1
// Expected output: res = 0
```

### getCreateCount<sup>18+</sup>

getCreateCount(): number

Obtains the number of times that the **createDefault** API is called to create objects.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description               |
| ------ | -------------------|
| number | Number of times that the **createDefault** API is called.|

**Example**

```ts
@Sendable
class ChildLRUCache extends ArkTSUtils.SendableLruCache<number, number> {
  constructor() {
    super();
  }
  createDefault(key: number): number {
    return key;
  }
}

let lru = new ChildLRUCache();
lru.put(2, 10);
lru.get(3);
lru.get(5);
let res = lru.getCreateCount();
console.info('res = ' + res);
// Expected output: res = 2
// When the get operation is performed, if the key does not exist, call the createDefault API to check whether the return value is undefined.
// If the return value is not undefined, add the key and return value to the cache as a new entry and increase the creation count by one.
```

### getMissCount<sup>18+</sup>

getMissCount(): number

Obtains the number of times that the queried values are mismatched.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | Number of times that the queried values are mismatched.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.get(2);
let result = pro.getMissCount();
console.info('result = ' + result);
// Expected output: result = 0
```

### getRemoveCount<sup>18+</sup>

getRemoveCount(): number

Obtains the number of times that key-value pairs in the cache are recycled. When the size of the cache exceeds the capacity limit, the least used key-value pairs will be recycled.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Number of times that key-value pairs in the cache are recycled.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.updateCapacity(2);
pro.put(50, 22);
let result = pro.getRemoveCount();
console.info('result = ' + result);
// Expected output: result = 0
```

### getMatchCount<sup>18+</sup>

getMatchCount(): number

Obtains the number of times that the queried values are matched.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Number of times that the queried values are matched.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.get(2);
let result = pro.getMatchCount();
console.info('result = ' + result);
// Expected output: result = 1
```

### getPutCount<sup>18+</sup>

getPutCount(): number

Obtains the number of additions to this cache.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| number | Number of additions to the cache.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.getPutCount();
console.info('result = ' + result);
// Expected output: result = 1
```

### isEmpty<sup>18+</sup>

isEmpty(): boolean

Checks whether this cache is empty.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Check result. The value **true** means that the cache is empty and does not contain any key-value pairs, and **false** means the opposite.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.isEmpty();
console.info('result = ' + result);
// Expected output: result = false
```

### get<sup>18+</sup>

get(key: K): V | undefined

Obtains the value of a key.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description        |
| ------ | ---- | ---- | ------------ |
| key    | K    | Yes  | Key based on which the value is queried.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| V \| undefined | If the specified key exists in the cache, the return value is the value associated with that key. If not, the **createDefault** API is called. If **createDefault** returns undefined, the return value is undefined; otherwise, the return value is whatever **createDefault** comes up with.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result  = pro.get(2);
console.info('result = ' + result);
// Expected output: result = 10
```

### put<sup>18+</sup>

put(key: K,value: V): V

Adds a key-value pair to this cache and returns the value associated with the key. If the total number of values in the cache is greater than the specified capacity, the deletion operation is performed.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                      |
| ------ | ---- | ---- | -------------------------- |
| key    | K    | Yes  | Key of the key-value pair to add.            |
| value  | V    | Yes  | Value of the key-value pair to add.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| V    | Value of the key-value pair added. If the key or value is empty, error code 401 is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
let result = pro.put(2, 10);
console.info('result = ' + result);
// Expected output: result = 10
```

### values<sup>18+</sup>

values(): V[]

Obtains all values in this cache, listed from the most to the least recently accessed, where the most recently accessed indicates the key-value pair with the latest operation.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| V&nbsp;[] | All values in the cache, listed from the most to the least recently accessed.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number|string,number|string>();
pro.put(2, 10);
pro.put(2, "anhu");
pro.put("afaf", "grfb");
let result = pro.values();
console.info('result = ' + result);
// Expected output: result = anhu,grfb
```

### keys<sup>18+</sup>

keys(): K[]

Obtains all keys in this cache, listed from the most to the least recently accessed.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| K&nbsp;[] | All keys in the cache, listed from the most to the least recently accessed.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.put(3, 1);
let result = pro.keys();
console.info('result = ' + result);
// Expected output: result = 2,3
```

### remove<sup>18+</sup>

remove(key: K): V | undefined

Removes a key and its associated value from this cache and returns the value associated with the key. If the key does not exist, undefined is returned.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description          |
| ------ | ---- | ---- | -------------- |
| key    | K    | Yes  | Key to remove.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| V&nbsp;\|&nbsp;undefined | Returns an **Optional** object containing the removed key-value pair if the key exists in the cache; returns undefined if the key does not exist; throws an error if **null** is passed in for **key**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.remove(20);
console.info('result = ' + result);
// Expected output: result = undefined
```

### contains<sup>18+</sup>

contains(key: K): boolean

Checks whether the cache contains the specified key.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| key    | K      | Yes  | Key to check.|

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | Check result. The value **true** means that the cache contains the specified key, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.contains(2);
console.info('result = ' + result);
// Expected output: result = true
```

### entries<sup>18+</sup>

entries(): IterableIterator&lt;[K,V]&gt;

Obtains a new iterator object that contains all key-value pairs in this object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type       | Description                |
| ----------- | -------------------- |
| IterableIterator<[K,&nbsp;V]> | Iterable array.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.put(3, 15);
let pair:Iterable<Object[]> = pro.entries();
let arrayValue = Array.from(pair);
for (let value of arrayValue) {
  console.info(value[0]+ ', '+ value[1]);
  // Expected output:
  // 2, 10
  // 3, 15
}
```
