# AsyncLock (异步锁)

ArkTS1.2支持并发与内存共享，为了解决多并发实例间的数据竞争问题，引入异步锁能力。由于ArkTS1.2支持异步操作，阻塞锁容易产生死锁问题，因此我们在ArkTS1.2中仅支持异步锁（非阻塞式锁）。

使用异步锁的方法需要标记为async，调用方需要await修饰调用，才能保证时序正确。因此会导致外层调用函数全部标记成async。

> **说明：**
>
> ArkTS版本：该标准库接口仅适用于ArkTS1.2。

## AsyncLockCallback\<T>

type AsyncLockCallback\<T> = () => T | Promise\<T>

这是一个补充类型别名，表示[lockAsync](#lockasync)函数所有重载中的回调。

**返回值：**

| 类型             | 说明                            |
| ---------------- | ------------------------------ |
| T \| Promise\<T> | T类型的值或泛型为T的Promise对象。 |

## AsyncLock

实现异步锁功能的类，允许在锁下执行异步操作。

### 属性

| 名称 | 类型    | 只读 | 可选 | 说明                         |
| ---- | ------ | ---- | ---- | --------------------------- |
| name | string | 是   | 否   | 锁的名称，开发者可自定义填写。 |

### constructor

constructor()

默认构造函数，创建一个异步锁。

**示例：**

```ts
let lock = new AsyncLock();
```

### request

static request(name: string): AsyncLock

使用指定的名称查找或创建（如果未找到）异步锁实例。

**参数：**

| 参数名 | 类型    | 必填 | 说明                                             |
| ------ | ------ | ---- | ----------------------------------------------- |
| name   | string | 是   | 按指定名称查找或创建异步锁实例。开发者可自定义填写。 |

**返回值：**

| 类型                    | 说明                           |
| ----------------------- | ----------------------------- |
| [AsyncLock](#asynclock) | 返回查找到或创建后的异步锁实例。 |

**示例：**

```ts
let lockName = "isAvailableLock";
let lock = AsyncLock.request(lockName);
```

### query

static query(name: string): AsyncLockState

查询指定异步锁的信息。

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ----- | ------ | ---- | ----------------------------------------------------- |
| name  | string | 是   | 锁的名称。使用[request](#request)方法创建锁时设置的名称。 |

**返回值：**

| 类型                               | 说明                            |
| --------------------------------- | ------------------------------- |
| [AsyncLockState](#asynclockstate) | 一个包含状态描述的异步锁状态实例。 |

**示例：**

```ts
// 你已经在别的地方创建了一个锁。
// let lock = AsyncLock.request("queryTestLock");
let state = AsyncLock.query("queryTestLock");
if (!state) {
  throw new Error("测试失败：期望有效的状态，但得到的是 " + state);
}
let pending: AsyncLockInfo[] = state.pending;
let held: AsyncLockInfo[] = state.held;
```

### queryAll

static queryAll(): AsyncLockState[]

查询所有现有锁的信息。

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ---------------------------- |
| [AsyncLockState](#asynclockstate)[] | 包含锁状态信息的异步锁状态数组。 |

**示例：**

```ts
let states: AsyncLockState[] = AsyncLock.queryAll();
if (states.length === 0) {
  throw new Error("测试失败：期望至少有1个状态，但得到的是 " + states.length);
}
```

### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>): Promise\<T>

在获取的锁下执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用[lockAsync](#lockasync)的同一线程中以异步方式执行。使用Promise异步回调。

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                 |
| -------- | --------------------------------------- | ---- | ------------------ |
| callback | [AsyncLockCallback\<T>](#asynclockcallbackt) | 是   | 获取锁后要调用的函数。|

**返回值：**

| 类型        | 说明                          |
| ----------- | ----------------------------- |
| Promise\<T> | Promise对象，返回回调函数结果。 |

**示例：**

```ts
let lock = new AsyncLock();
let p1 = lock.lockAsync<void>(() => {
  // 执行某些操作
});
```

### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode): Promise\<T>

在获取的锁下执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用[lockAsync](#lockasync)的同一线程中以异步方式执行。使用Promise异步回调。

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                  |
| -------- | --------------------------------------- | ---- | -------------------- |
| callback | [AsyncLockCallback\<T>](#asynclockcallbackt) | 是   | 获取锁后要调用的函数。 |
| mode     | [AsyncLockMode](#asynclockmode)         | 是   | 锁的操作模式。        |

**返回值：**

| 类型        | 说明                          |
| ----------- | ---------------------------- |
| Promise\<T> | Promise对象，返回回调函数结果。|

**示例：**

```ts
let lock = new AsyncLock();
let p1 = lock.lockAsync<void>(() => {
  // 执行某些操作
}, AsyncLockMode.EXCLUSIVE);
```

### lockAsync

lockAsync\<T, U>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode, options: AsyncLockOptions\<U>): Promise\<T>

在获取的锁下执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用[lockAsync](#lockasync)的同一线程中以异步方式执行。在[AsyncLockOptions](#asynclockoptionst)中可以提供一个可选的超时值。在这种情况下，如果超时前未能获取锁，lockAsync将拒绝返回的Promise并带上一个Error实例，携带超时异常信息。使用Promise异步回调。

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                   |
| -------- | ----------------------------------------- | ---- | --------------------- |
| callback | [AsyncLockCallback\<T>](#asynclockcallbackt)   | 是   | 获取锁后要调用的函数。 |
| mode     | [AsyncLockMode](#asynclockmode)           | 是   | 锁的操作模式。         |
| options  | [AsyncLockOptions\<U>](#asynclockoptionst) | 是   | 锁的操作选项。         |

**返回值：**

| 类型        | 说明                                                |
| ----------- | -------------------------------------------------- |
| Promise\<T> | Promise对象，返回回调函数结果，或者在超时情况下被拒绝。 |

**示例：**

```ts
let lock = new AsyncLock();
let options = new AsyncLockOptions<void>();
options.timeout = 1000;
let p: Promise<void> = lock.lockAsync<void, void>(
  () => {
    // 执行某些操作
  },
  AsyncLockMode.EXCLUSIVE,
  options
);
```

## AsyncLockMode

锁操作对应的模式枚举。

| 名称      | 值  | 说明                                                 |
| --------- | --- | --------------------------------------------------- |
| SHARED    | 1   | 共享锁模式。如果指定了此模式，可以在任意线程同时执行。   |
| EXCLUSIVE | 2   | 独占锁模式。如果指定了此模式，仅在独占获取锁时才能执行。 |

**示例：**

```ts
import hilog from '@ohos.hilog'

let lock = new AsyncLock();
// shared0可获取锁并开始执行
lock.lockAsync(async () => {
  hilog.info(0x0000, 'testTag', "shared0");
  await new Promise<number>((resolve) => { setTimeout(resolve, 1000, 1.0) });
}, AsyncLockMode.SHARED);
// shared1可获取锁并开始执行，无需等待shared0
lock.lockAsync(async () => {
  hilog.info(0x0000, 'testTag', "shared1");
  await new Promise<number>((resolve) => { setTimeout(resolve, 1000, 1.0) });
}, AsyncLockMode.SHARED);
// exclusive0需等待shared0、1执行完后才可获取锁并执行
lock.lockAsync(async () => {
  hilog.info(0x0000, 'testTag', "exclusive0");
  await new Promise<number>((resolve) => { setTimeout(resolve, 1000, 1.0) });
}, AsyncLockMode.EXCLUSIVE);
// shared2需等待exclusive0执行完后才可获取锁并执行
lock.lockAsync(async () => {
  hilog.info(0x0000, 'testTag', "shared2");
  await new Promise<number>((resolve) => { setTimeout(resolve, 1000, 1.0) });
}, AsyncLockMode.SHARED);
// shared3需等待exclusive0执行完后才可获取锁并执行，无需等待shared2
lock.lockAsync(async () => {
  hilog.info(0x0000, 'testTag', "shared3");
  await new Promise<number>((resolve) => { setTimeout(resolve, 1000, 1.0) });
}, AsyncLockMode.SHARED);
```

## AsyncLockOptions\<T>

表示锁操作选项的类。

### 属性

| 参数名      | 类型                                  | 只读 | 可选 | 说明                                                                                                                                                                 |
| ----------- | ------------------------------------- | ---- | ---- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| isAvailable | boolean                               | 否   | 否   | 当前锁是否可用。取值为true，则只有在尚未持有锁定请求时才会授予该锁定请求；为false则表示将等待当前锁被释放。默认为 false。                                            |
| signal      | [AbortSignal\<T>](#abortsignalt) \| null | 否   | 否   | 用于中止异步操作的对象。当signal.aborted 为true时，锁请求将被丢弃；当signal.aborted为false时，请求会继续等待获取锁；当signal为null时，请求正常排队运行。默认为null。 |
| timeout     | number                                | 否   | 否   | 锁操作的超时时间（毫秒）。如果该值大于零，且运行超过该时间，[lockAsync](#lockasync)将返回被拒绝的 Promise。默认为0。                                                 |

### constructor

constructor()

默认构造函数。创建一个所有属性均具有默认值的异步锁配置项实例。

**示例：**

```ts
let s: AbortSignal<string> = { aborted: false, reason: "Aborted" };
let options = new AsyncLockOptions<string>();
options.isAvailable = false;
options.signal = s;
```

### constructor

constructor(isAvailable: boolean, signal: AbortSignal\<T> | null, timeout: number)

有参构造函数。根据输入参数创建异步锁配置项实例。

**参数：**

| 参数名      | 类型                                    | 必填 | 说明                      |
| ----------- | --------------------------------------- | ---- | ------------------------ |
| isAvailable | boolean                                 | 是   | 当前锁是否可用。取值为true，则只有在尚未持有锁定请求时才会授予该锁定请求；为false则表示将等待当前锁被释放。           |
| signal      | [AbortSignal\<T>](#abortsignalt) \| null | 是   | 用于中止异步操作的对象。当signal.aborted 为true时，锁请求将被丢弃；当signal.aborted为false时，请求会继续等待获取锁；当signal为null时，请求正常排队运行。   |
| timeout     | number                                  | 是   | 锁操作的超时时间（毫秒）。如果该值大于零，且运行超过该时间，[lockAsync](#lockasync)将返回被拒绝的 Promise。 |

**示例：**

```ts
let s: AbortSignal<string> = { aborted: false, reason: "Aborted" };
let options = new AsyncLockOptions<string>(false, s, 0);
```

## AsyncLockState

用于存储特定异步锁实例上当前执行的所有锁操作的信息的类。

### 属性

| 名称    | 类型                               | 只读 | 可选 | 说明                 |
| ------- | --------------------------------- | ---- | ---- | -------------------- |
| held    | [AsyncLockInfo](#asynclockinfo)[] | 否   | 否   | 持有的锁信息列表。   |
| pending | [AsyncLockInfo](#asynclockinfo)[] | 否   | 否   | 等待中的锁信息列表。 |

## AsyncLockInfo

封装锁信息的类。

### 属性

| 名称      | 类型                             | 只读 | 可选 | 说明                                                                   |
| --------- | ------------------------------- | ---- | ---- | ---------------------------------------------------------------------- |
| name      | string                          | 是   | 否   | 锁的名称。                                                             |
| mode      | [AsyncLockMode](#asynclockmode) | 是   | 否   | 锁的模式。                                                             |
| contextId | number                          | 是   | 否   | [AsyncLockMode](#asynclockmode)调用者的执行上下文标识符。大于0的整数。 |

## AbortSignal\<T>

用于中止异步操作的对象。该类的实例必须在其创建的同一线程中访问。从其他线程访问此类的字段会导致未定义的行为。

### 属性

| 名称    | 类型    | 只读 | 可选 | 说明                                                                          |
| ------- | ------- | ---- | ---- | --------------------------------------------------------------------------- |
| aborted | boolean | 否   | 否   | 锁请求终止标志。设置为true时，锁请求将被丢弃；设置为false时，请求会继续等待获取锁。|
| reason  | T       | 否   | 否   | 中止的原因。此值将用于拒绝[lockAsync](#lockasync)返回的Promise。               |
