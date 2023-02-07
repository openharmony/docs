# @ohos.taskpool（使用任务池）

任务池（taskpool）作用是为应用程序提供一个多线程的运行环境，降低整体资源的消耗、提高系统的整体性能，且您无需关心线程实例的生命周期。您可以使用任务池API创建后台任务（Task），并对所创建的任务进行如任务执行、任务取消的操作。理论上您可以使用任务池API创建数量不受限制的任务，但是出于内存因素不建议您这样做。此外，不建议您在任务中执行阻塞操作，特别是无限期阻塞操作，长时间的阻塞操作占据工作线程，可能会阻塞其他任务调度，影响您的应用性能。

您所创建的同一优先级任务的执行顺序可以由您决定，任务真实执行的顺序与您调用任务池API提供的任务执行接口顺序一致。任务默认优先级是MEDIUM。（任务优先级机制暂未支持）

当同一时间待执行的任务数量大于任务池工作线程数量，任务池会根据负载均衡机制进行扩容，增加工作线程数量，减少整体等待时长。同样，当执行的任务数量减少，工作线程数量大于执行任务数量，部分工作线程处于空闲状态，任务池会根据负载均衡机制进行缩容，减少工作线程数量。（负载均衡机制暂未支持）

任务池API以数字形式返回错误码。有关各个错误码的更多信息，请参阅文档[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

> **说明：**<br/>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import taskpool from '@ohos.taskpool';
```

## Priority

表示所创建任务（Task）的优先级。（暂未支持）

**系统能力：**  SystemCapability.Utils.Lang

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| HIGH   | 0    | 任务为高优先级。 |
| MEDIUM | 1 | 任务为中优先级。 |
| LOW | 2 | 任务为低优先级。 |

## Task

表示任务。使用以下方法前，需要先构造Task。

### constructor

constructor(func: Function, ...args: unknown[])

Task的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型      | 必填 | 说明                                                                  |
| ------ | --------- | ---- | -------------------------------------------------------------------- |
| func   | Function  | 是   | 任务执行需要传入函数，支持的函数返回值类型请查[序列化支持类型](#序列化支持类型)。   |
| args   | unknown[] | 否   | 任务执行传入函数的参数，支持的参数类型请查[序列化支持类型](#序列化支持类型)。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**示例：**

```js
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}
let task = new taskpool.Task(func, "this is my first Task");
```

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称      | 类型      | 可读 | 可写 | 说明                                                                       |
| --------- | --------- | ---- | ---- | ------------------------------------------------------------------------- |
| function  | Function  | 是   | 是   | 创建任务时需要传入的函数，支持的函数返回值类型请查[序列化支持类型](#序列化支持类型)。   |
| arguments | unknown[] | 是   | 是   | 创建任务传入函数所需的参数，支持的参数类型请查[序列化支持类型](#序列化支持类型)。 |

## taskpool.execute

execute(func: Function, ...args: unknown[]): Promise\<unknown>

任务池执行任务，需要传入待执行的函数和函数所需的参数，此执行模式不可取消任务。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型      | 必填 | 说明                                                                   |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| func   | Function  | 是   | 执行的逻辑需要传入函数，支持的函数返回值类型请查[序列化支持类型](#序列化支持类型)。     |
| args   | unknown[] | 否   | 执行逻辑的函数所需要的参数，支持的参数类型请查[序列化支持类型](#序列化支持类型)。 |

**返回值：**

| 类型              | 说明                                 |
| ----------------- | ------------------------------------ |
| Promise\<unknown> | execute是异步方法，返回Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 10200003 | Worker initialization failure.            |
| 10200006 | Serializing an uncaught exception failed. |
| 10200014 | The function is not mark as concurrent.   |

**示例：**

```js
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}

let value = taskpool.execute(func, 100);
```

## taskpool.execute

execute(task: Task, priority?: Priority): Promise\<unknown>

任务池执行任务，需要传入已创建的任务，此执行模式可取消任务。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                 |
| -------- | --------------------- | ---- | ------------------------------------ |
| task     | [Task](#task)         | 是   | 需要在任务池中执行的任务。           |
| priority | [Priority](#priority) | 否   | 等待执行的任务的优先级（暂未支持）。 |

**返回值：**

| 类型             | 说明                           |
| ---------------- | ------------------------------ |
| Promise\<unknown> | execute是异步方法，返回Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 10200003 | Worker initialization failure.            |
| 10200006 | Serializing an uncaught exception failed. |
| 10200014 | The function is not mark as concurrent.   |

**示例：**

```js
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}
let task = new taskpool.Task(func, "this is my first Task");
let value = taskpool.execute(task);
```

## taskpool.cancel

cancel(task: Task): void

取消任务池中的任务。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| task   | [Task](#task) | 是   | 需要取消执行的任务。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                  |
| -------- | ------------------------- |
| 10200015 | If the task is not exist. |
| 10200016 | If the task is running.   |

**示例：**

```js
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}
let task = new taskpool.Task(func, "this is first Task");
let value = taskpool.execute(task);
taskpool.cancel(task);
```

## 其他说明

### 序列化支持类型
序列化支持类型包括：All Primitive Type(不包括symbol)、Date、String、RegExp、Array、Map、Set、Object、ArrayBuffer、TypedArray。

### 注意事项
taskpool任务只支持引用入参传递或者import的变量，不支持使用闭包变量。

```js
// 1. 引用入参传递
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}

let task = new taskpool.Task(func, "create task, then execute");
let val1 = taskpool.execute(task);

let val2 = taskpool.execute(func, "execute task by func");
```

```js
// 2. 引用import变量

// b.ts
export var c = 2000;

// a.ts
import { c } from './b'

function test(a) {
    "use concurrent"
    console.log(a);
    console.log(c);
    return a;
}

let task = new taskpool.Task(test, "create task, then execute");
let val1 = taskpool.execute(task);

let val2 = taskpool.execute(test, "execute task by func");
```