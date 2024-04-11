# @arkts.utils (ArkTS工具库)

本模块提供了各种ArkTS实用工具函数。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import utils from '@arkts.utils';
```

## utils.locks

为了解决多并发实例间的数据竞争问题，ArkTS语言基础库引入了异步锁能力。为了开发者的开发效率，AsyncLock对象支持跨并发实例引用传递。

由于ArkTS语言支持异步操作，阻塞锁容易产生死锁问题，因此我们在ArkTS中仅支持异步锁（非阻塞式锁）。

使用异步锁的方法需要标记为async，调用方需要await修饰调用，才能保证时序正确。因此会导致外层调用函数全部标记成async。

### AsyncLockCallback

type AsyncLockCallback\<T> = () => T | Promise\<T>

这是一个补充类型别名，表示[lockAsync](#lockasync)函数所有重载中的回调。

**系统能力：** SystemCapability.Utils.Lang

### AsyncLock

实现异步锁功能的类，允许在锁下执行异步操作。

#### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型   | 可读 | 可写 | 说明       |
| ---- | ------ | ---- | ---- | ---------- |
| name | string | 是   | 否   | 锁的名称。 |

**示例：**

```ts
@Sendable
class A {
  // 暂不支持AsyncLock跨线程共享，因此@Sendable不能持有AsyncLock，只能用AsyncLock.request。
  // 如下一行示例代码是错误的。
  // static lock_: utils.locks.AsyncLock = new utils.locks.AsyncLock();
  count_: number = 0;
  async getCount(): Promise<number> {
    let lock: utils.locks.AsyncLock = utils.locks.AsyncLock.request("lock_1");
    return lock.lockAsync(() => {
      return this.count_;
    })
  }
  async setCount(count: number) {
    let lock: utils.locks.AsyncLock = utils.locks.AsyncLock.request("lock_1");
    await lock.lockAsync(() => {
      this.count_ = count;
    })
  }
}

@Concurrent
async function foo(a: A) {
  let unused = utils.locks.AsyncLock; // 4月版本临时规避代码，需要在@Concurrent函数中使用一下，否则后续逻辑使用异步锁会存在加载失败的异常问题。
  await a.setNum(10)
}
```

#### constructor

constructor()

默认构造函数。创建一个匿名锁。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                    | 说明               |
| ----------------------- | ------------------ |
| [AsyncLock](#asynclock) | 创建的匿名锁实例。 |

**示例：**

```ts
let lock = new utils.locks.AsyncLock();
```

#### request

static request(name: string): AsyncLock

使用指定的名称查找或创建（如果未找到）异步锁实例。

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
let lock = utils.locks.AsyncLock.request(lockName);
```

#### query

static query(name: string): AsyncLockState

查询指定异步锁的信息。

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
// let lock = utils.locks.AsyncLock.request("queryTestLock");
let state = utils.locks.AsyncLock.query('queryTestLock');
if (!state) {
    throw new Error('测试失败：期望有效的状态，但得到的是 ' + state);
}
let pending: utils.locks.AsyncLockInfo[] = state.pending;
let held: utils.locks.AsyncLockInfo[] = state.held;
```

#### queryAll

static queryAll(): AsyncLockState[]

查询所有现有锁的信息。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                                | 说明                             |
| ----------------------------------- | -------------------------------- |
| [AsyncLockState](#asynclockstate)[] | 包含锁状态信息的异步锁状态数组。 |

**示例：**

```ts
let states: utils.locks.AsyncLockState[] = utils.locks.AsyncLock.queryAll();
if (states.length == 0) {
    throw new Error('测试失败：期望至少有1个状态，但得到的是 ' + states.length);
}
```

#### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>): Promise\<T>

在获取的锁下独占执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用[lockAsync](#lockasync)的同一线程中以异步方式执行。

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
let lock = new utils.locks.AsyncLock();
let p1 = lock.lockAsync<void>(() => {
    // 执行某些操作
});
```

#### lockAsync

lockAsync\<T>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode): Promise\<T>

在获取的锁下执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用[lockAsync](#lockasync)的同一线程中以异步方式执行。

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
let lock = new utils.locks.AsyncLock();
let p1 = lock.lockAsync<void>(() => {
    // 执行某些操作
}, utils.locks.AsyncLockMode.EXCLUSIVE);
```

#### lockAsync

lockAsync\<T, U>(callback: AsyncLockCallback\<T>, mode: AsyncLockMode, options: AsyncLockOptions\<U>): Promise\<T | U>

在获取的锁下执行操作。该方法首先获取锁，然后调用回调，最后释放锁。回调在调用 lockAsync 的同一线程中以异步方式执行。在[AsyncLockOptions](#asynclockoptions)中可以提供一个可选的超时值。在这种情况下，如果超时前未能获取锁，lockAsync将拒绝返回的Promise并带上一个BusinessError实例。这种情况下，错误信息将包含持有的锁和等待的锁的信息以及可能的死锁警告。

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
let lock = new utils.locks.AsyncLock();
let options = new utils.locks.AsyncLockOptions<void>();
options.timeout = 1000;
let p: Promise<void> = lock.lockAsync<void, void>(
    () => {
        // 执行某些操作
    },
    utils.locks.AsyncLockMode.EXCLUSIVE,
    options
);
```

### AsyncLockMode

锁操作对应的模式枚举。

**系统能力：** SystemCapability.Utils.Lang

| 名称      | 值  | 说明                                                     |
| --------- | --- | -------------------------------------------------------- |
| SHARED    | 1   | 共享锁操作。如果指定了此模式，操作可以在同一线程中重入。 |
| EXCLUSIVE | 2   | 独占锁操作。如果指定了此模式，仅在独占获取锁时执行操作。 |

### AsyncLockOptions

class AsyncLockOptions\<T>

表示锁操作选项的类。

**系统能力：** SystemCapability.Utils.Lang

#### constructor

constructor()

默认构造函数。创建一个所有属性均具有默认值的异步锁配置项实例。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                                  | 说明                   |
| ------------------------------------- | ---------------------- |
| [AsyncLockOptions](#asynclockoptions) | 新的异步锁配置项实例。 |

**示例：**

```ts
let lock = new utils.locks.AsyncLock();
let s: utils.locks.AbortSignal<string> = { aborted: false, reason: 'Aborted' };
let options = new utils.locks.AsyncLockOptions<string>();
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

| 名称    | 类型                              | 可读 | 可写 | 说明             |
| ------- | --------------------------------- | ---- | ---- | ---------------- |
| held    | [AsyncLockInfo[]](#asynclockinfo) | 是   | 是   | 持有的锁信息。   |
| pending | [AsyncLockInfo[]](#asynclockinfo) | 是   | 是   | 等待中的锁信息。 |

**示例：**

```ts
function queryTest() {
    let lockName = 'queryTestLock';
    let lock = utils.locks.AsyncLock.request(lockName);
    let state = utils.locks.AsyncLock.query(lock.name);
    if (!state) {
        throw new Error('测试失败：期望有效的状态，但得到的是 ' + state);
    }
    let p = lock.lockAsync<void>(async () => {
        let states: utils.locks.AsyncLockState[] = utils.locks.AsyncLock.queryAll();
        if (states.length == 0) {
            throw new Error('测试失败：期望至少有1个状态，但得到的是 ' + states.length);
        }
        let state = utils.locks.AsyncLock.query(lock.name);
        let pending: utils.locks.AsyncLockInfo[] = state.pending;
        if (pending.length != 0) {
            throw new Error('测试失败：期望 pending.length=0，但得到的是 ' + pending.length);
        }
        let held: utils.locks.AsyncLockInfo[] = state.held;
        if (held.length != 1) {
            throw new Error('测试失败：期望 held.length=1，但得到的是 ' + held.length);
        }
        if (held[0].name !== lockName) {
            throw new Error('测试失败：期望 held[0].name=' + lockName + '，但得到的是 ' + held[0].name);
        }
        if (held[0].mode !== utils.locks.AsyncLockMode.EXCLUSIVE) {
            throw new Error('测试失败：期望 held[0].mode=EXCLUSIVE，但得到的是 ' + held[0].mode);
        }
    }, utils.locks.AsyncLockMode.EXCLUSIVE);
}
```

### AsyncLockInfo

关于锁的信息。

**系统能力：** SystemCapability.Utils.Lang

#### 属性

| 名称      | 类型                            | 可读 | 可写 | 说明                                                      |
| --------- | ------------------------------- | ---- | ---- | --------------------------------------------------------- |
| name      | string                          | 是   | 是   | 锁的名称。                                                |
| mode      | [AsyncLockMode](#asynclockmode) | 是   | 是   | 锁的模式。                                                |
| contextId | number                          | 是   | 是   | [AsyncLockMode](#asynclockmode)调用者的执行上下文标识符。 |

### AbortSignal

用于中止异步操作的对象。该类的实例必须在其创建的同一线程中访问。从其他线程访问此类的字段会导致未定义的行为。

**系统能力：** SystemCapability.Utils.Lang

#### 属性

| 名称    | 类型    | 可读 | 可写 | 说明                                                             |
| ------- | ------- | ---- | ---- | ---------------------------------------------------------------- |
| aborted | boolean | 是   | 是   | 设置为true以中止操作。                                           |
| reason  | \<T>    | 是   | 是   | 中止的原因。此值将用于拒绝[lockAsync](#lockasync)返回的Promise。 |

**示例：**

```ts
function abortTest() {
    let lock = new utils.locks.AsyncLock();
    let s: utils.locks.AbortSignal<string> = { aborted: false, reason: 'Aborted' };
    let options = new utils.locks.AsyncLockOptions<string>();
    options.isAvailable = false;
    options.signal = s;
    let p: Promise<number | string> = lock.lockAsync<number, string>(
        () => {
            return 5;
        },
        utils.locks.AsyncLockMode.EXCLUSIVE,
        options
    );
    s.aborted = true;
    let p1 = p.then(
        () => {
            throw new Error('Test failed. Promise is fulfilled.');
        },
        (err: string) => {
            if (err !== 'Aborted') {
                throw new Error('Test failed. Wrong error value.');
            }
        }
    );
}
```
