# @arkts.utils (ArkTS工具库)

本模块提供了各种ArkTS实用工具函数。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { ArkTSUtils } from '@kit.ArkTS'
```

## ArkTSUtils.locks

为了解决多并发实例间的数据竞争问题，ArkTS语言基础库引入了异步锁能力。为了开发者的开发效率，AsyncLock对象支持跨并发实例引用传递。

由于ArkTS语言支持异步操作，阻塞锁容易产生死锁问题，因此我们在ArkTS中仅支持异步锁（非阻塞式锁）。

使用异步锁的方法需要标记为async，调用方需要await修饰调用，才能保证时序正确。因此会导致外层调用函数全部标记成async。

### AsyncLockCallback

type AsyncLockCallback\<T> = () => T | Promise\<T>

这是一个补充类型别名，表示[lockAsync](#lockasync)函数所有重载中的回调。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

### AsyncLock

实现异步锁功能的类，允许在锁下执行异步操作。

#### 属性

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型   | 可读 | 可写 | 说明       |
| ---- | ------ | ---- | ---- | ---------- |
| name | string | 是   | 否   | 锁的名称。 |

**示例：**

```ts
// 示例一：
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

// 示例二：
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

默认构造函数。创建一个匿名锁。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                    | 说明               |
| ----------------------- | ------------------ |
| [AsyncLock](#asynclock) | 创建的匿名锁实例。 |

**示例：**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
```

#### request

static request(name: string): AsyncLock

使用指定的名称查找或创建（如果未找到）异步锁实例。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 名称 | 类型   | 必填 | 说明                             |
| ---- | ------ | ---- | -------------------------------- |
| name | string | 是   | 按指定名称查找或创建异步锁实例。 |

**返回值：**

| 类型                    | 说明                             |
| ----------------------- | -------------------------------- |
| [AsyncLock](#asynclock) | 返回查找到或创建后的异步锁实例。 |

**示例：**

```ts
let lockName = 'isAvailableLock';
let lock = ArkTSUtils.locks.AsyncLock.request(lockName);
```

#### query

static query(name: string): AsyncLockState

查询指定异步锁的信息。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 名称 | 类型   | 必填 | 说明       |
| ---- | ------ | ---- | ---------- |
| name | string | 是   | 锁的名称。 |

**返回值：**

| 类型                              | 说明                               |
| --------------------------------- | ---------------------------------- |
| [AsyncLockState](#asynclockstate) | 一个包含状态描述的异步锁状态实例。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 10200030 | No such lock. |

**示例：**

```ts
// 你已经在别的地方创建了一个锁。
// let lock = ArkTSUtils.locks.AsyncLock.request("queryTestLock");
let state = ArkTSUtils.locks.AsyncLock.query('queryTestLock');
if (!state) {
    throw new Error('测试失败：期望有效的状态，但得到的是 ' + state);
}
let pending: ArkTSUtils.locks.AsyncLockInfo[] = state.pending;
let held: ArkTSUtils.locks.AsyncLockInfo[] = state.held;
```

#### queryAll

static queryAll(): AsyncLockState[]

查询所有现有锁的信息。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                                | 说明                             |
| ----------------------------------- | -------------------------------- |
| [AsyncLockState](#asynclockstate)[] | 包含锁状态信息的异步锁状态数组。 |

**示例：**

```ts
let states: ArkTSUtils.locks.AsyncLockState[] = ArkTSUtils.locks.AsyncLock.queryAll();
if (states.length == 0) {
    throw new Error('测试失败：期望至少有1个状态，但得到的是 ' + states.length);
}
```

#### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>): Promise\<T>

在获取的锁下独占执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用[lockAsync](#lockasync)的同一线程中以异步方式执行。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback](#asynclockcallback) | 是   | 获取锁后要调用的函数。 |

**返回值：**

| 类型        | 说明                        |
| ----------- | --------------------------- |
| Promise\<T> | 回调执行后将解决的Promise。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 10200030 | No such lock. |

**示例：**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
let p1 = lock.lockAsync<void>(() => {
    // 执行某些操作
});
```

#### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode): Promise\<T>

在获取的锁下执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用[lockAsync](#lockasync)的同一线程中以异步方式执行。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback](#asynclockcallback) | 是   | 获取锁后要调用的函数。 |
| mode     | [AsyncLockMode](#asynclockmode)         | 是   | 锁的操作模式。         |

**返回值：**

| 类型        | 说明                        |
| ----------- | --------------------------- |
| Promise\<T> | 回调执行后将解决的Promise。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 10200030 | No such lock. |

**示例：**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
let p1 = lock.lockAsync<void>(() => {
    // 执行某些操作
}, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE);
```

#### lockAsync

lockAsync\<T, U>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode, options: AsyncLockOptions\<U>): Promise\<T | U>

在获取的锁下执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用 lockAsync 的同一线程中以异步方式执行。在[AsyncLockOptions](#asynclockoptions)中可以提供一个可选的超时值。在这种情况下，如果超时前未能获取锁，lockAsync将拒绝返回的Promise并带上一个BusinessError实例。这种情况下，错误信息将包含持有的锁和等待的锁的信息以及可能的死锁警告。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 名称     | 类型                                      | 必填 | 说明                   |
| -------- | ----------------------------------------- | ---- | ---------------------- |
| callback | [AsyncLockCallback](#asynclockcallback)   | 是   | 获取锁后要调用的函数。 |
| mode     | [AsyncLockMode](#asynclockmode)           | 是   | 锁的操作模式。         |
| options  | [AsyncLockOptions\<U>](#asynclockoptions) | 是   | 锁的操作选项。         |

**返回值：**

| 类型             | 说明                                               |
| ---------------- | -------------------------------------------------- |
| Promise\<T \| U> | 回调执行后解决的 Promise，或者在超时情况下被拒绝。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 10200030 | No such lock.     |
| 10200031 | Timeout exceeded. |

**示例：**

```ts
let lock = new ArkTSUtils.locks.AsyncLock();
let options = new ArkTSUtils.locks.AsyncLockOptions<void>();
options.timeout = 1000;
let p: Promise<void> = lock.lockAsync<void, void>(
    () => {
        // 执行某些操作
    },
    ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE,
    options
);
```

### AsyncLockMode

锁操作对应的模式枚举。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称      | 值  | 说明                                                     |
| --------- | --- | -------------------------------------------------------- |
| SHARED    | 1   | 共享锁操作。如果指定了此模式，操作可以在同一线程中重入。 |
| EXCLUSIVE | 2   | 独占锁操作。如果指定了此模式，仅在独占获取锁时执行操作。 |

### AsyncLockOptions

class AsyncLockOptions\<T>

表示锁操作选项的类。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

#### constructor

constructor()

默认构造函数。创建一个所有属性均具有默认值的异步锁配置项实例。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                                  | 说明                   |
| ------------------------------------- | ---------------------- |
| [AsyncLockOptions](#asynclockoptions) | 新的异步锁配置项实例。 |

**示例：**

```ts
let s: ArkTSUtils.locks.AbortSignal<string> = { aborted: false, reason: 'Aborted' };
let options = new ArkTSUtils.locks.AsyncLockOptions<string>();
options.isAvailable = false;
options.signal = s;
let p: Promise<void> = lock.lockAsync<void, string>(
    () => {
        // 执行某些操作
    },
    utils.locks.AsyncLockMode.EXCLUSIVE,
    options
);
```

#### 属性

| 名称        | 类型                                  | 可读 | 可写 | 说明                                                                                                               |
| ----------- | ------------------------------------- | ---- | ---- | ------------------------------------------------------------------------------------------------------------------ |
| isAvailable | boolean                               | 是   | 是   | 当前锁是否可用。取值为true表示如果无法立即获取锁，则操作将被取消；为false时表示将等待当前锁被释放。默认为 false。                                   |
| signal      | [AbortSignal\<T>](#abortsignal)\|null | 是   | 是   | 用于中止异步操作的对象。如果signal.aborted为true，则不会调用回调；为null时表示会调用回调。默认为 null。                                    |
| timeout     | number                                | 是   | 是   | 锁操作的超时时间（毫秒）。如果该值大于零，且运行超过该时间，[lockAsync](#lockasync)将返回拒绝的Promise。默认为 0。 |

### AsyncLockState

用于存储特定异步锁实例上当前执行的所有锁操作的信息的类。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

#### 属性

| 名称    | 类型                              | 可读 | 可写 | 说明             |
| ------- | --------------------------------- | ---- | ---- | ---------------- |
| held    | [AsyncLockInfo[]](#asynclockinfo) | 是   | 是   | 持有的锁信息。   |
| pending | [AsyncLockInfo[]](#asynclockinfo) | 是   | 是   | 等待中的锁信息。 |

### AsyncLockInfo

关于锁的信息。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

#### 属性

| 名称      | 类型                            | 可读 | 可写 | 说明                                                      |
| --------- | ------------------------------- | ---- | ---- | --------------------------------------------------------- |
| name      | string                          | 是   | 是   | 锁的名称。                                                |
| mode      | [AsyncLockMode](#asynclockmode) | 是   | 是   | 锁的模式。                                                |
| contextId | number                          | 是   | 是   | [AsyncLockMode](#asynclockmode)调用者的执行上下文标识符。 |

### AbortSignal

用于中止异步操作的对象。该类的实例必须在其创建的同一线程中访问。从其他线程访问此类的字段会导致未定义的行为。

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

#### 属性

| 名称    | 类型    | 可读 | 可写 | 说明                                                             |
| ------- | ------- | ---- | ---- | ---------------------------------------------------------------- |
| aborted | boolean | 是   | 是   | 设置为true以中止操作。                                           |
| reason  | \<T>    | 是   | 是   | 中止的原因。此值将用于拒绝[lockAsync](#lockasync)返回的Promise。 |

## ArkTSUtils.ASON

为支持将JSON字符串解析成共享数据，ArkTS语言基础库新增了ASON工具。ASON支持开发者解析JSON字符串，并生成共享数据进行跨并发域传输，同时ASON也支持将共享数据转换成JSON字符串。

### ISendable

type ISendable = lang.ISendable

ISendable是所有Sendable类型（除`null`和`undefined`）的父类型。自身没有任何必须的方法和属性。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 类型 | 说明   |
| ------ | ------ |
| [lang.ISendable](js-apis-arkts-lang.md#langisendable)   | 所有Sendable类型的父类型。 |

### parse

parse(text: string): ISendable | null

用于解析JSON字符串生成Isendable数据或null。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| text   | string | 是 | 有效的JSON字符串。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ISendable](#isendable) \| null | 返回Isendable数据或null。当入参是null时，返回null。|

**示例：**

```ts
let jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = ArkTSUtils.ASON.parse(jsonText);
console.info(obj.name);
// 期望输出: 'John'
console.info(obj.age);
// 期望输出: 30
console.info(obj.city);
// 期望输出: 'ChongQing'
```

### stringify

stringify(value: ISendable): string

该方法将ISendable数据转换为JSON字符串。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [ISendable](#isendable)  | 是 | ISendable数据。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 转换后的JSON字符串。|

**示例：**

```ts
import { collections } from '@kit.ArkTS';

let arr = new collections.Array(1, 2, 3);
let str = ArkTSUtils.ASON.stringify(arr);
console.info(str);
// 期望输出: '[1,2,3]'
```
