# @ohos.taskpool（使用任务池）

taskpool作用是为应用程序提供一个多线程的运行环境，可以降低整体资源的消耗、提高系统的整体性能，且用户无需关心线程实例的生命周期。

## 导入模块

```js
import taskpool from '@ohos.taskpool';
```

## 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称     | 可读 | 可写 | 说明                                                       |
| -------- | ---- | ---- | ---------------------------------------------------------- |
| taskpool | 是   | 是   | taskpool对象用于管理Task（任务），可以创建、执行和取消Task |

## Task

使用以下方法前，需要先构造Task。

| 名称 | 类型 | 可读 | 可写 | 说明                                                     |
| ---- | ---- | ---- | ---- | -------------------------------------------------------- |
| Task | Task | 是   | 是   | 待执行的任务。需要创建Task再放入taskpool（任务池）中执行 |

### constructor

constructor(func: Function, ...args: unknown[])

Task构造函数

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型      | 必填 | 说明                                           |
| ------ | --------- | ---- | ---------------------------------------------- |
| func   | Function  | 是   | Task执行的逻辑需要传入Function                 |
| args   | unknown[] | 否   | Task执行逻辑的Function如果需要入参，则需要传递 |

**返回值：**

| 类型 | 说明                                                |
| ---- | --------------------------------------------------- |
| Task | 执行Task构造函数生成的Task对象，失败则返回undefined |

**错误码：**

| 错误码   | 错误说明                                |
| -------- | --------------------------------------- |
| 401      | the input parameters are invalid.       |
| 10200014 | the function is not mark as concurrent. |

**示例：**

```js
import taskpool from '@ohos.taskpool';

function func(args) {
    console.log("func: " + args);
    return args;
}
var task = new taskpool.Task(func, "this is first Task");
```



## execute

execute(func: Function, ...args: unknown[]): Promise<unknown>

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型      | 必填 | 说明                                       |
| ------ | --------- | ---- | ------------------------------------------ |
| func   | Function  | 是   | 执行的逻辑需要传入Function                 |
| args   | unknown[] | 否   | 执行逻辑的Function如果需要入参，则需要传递 |

**返回值：**

| 类型             | 说明                           |
| ---------------- | ------------------------------ |
| Promise<unknown> | execute是异步方法，返回Promise |

**错误码：**

| 错误码   | 错误说明                                |
| -------- | --------------------------------------- |
| 401      | the input parameters are invalid.       |
| 10200014 | the function is not mark as concurrent. |

**示例：**

```js
import taskpool from '@ohos.taskpool';

function func(args) {
    console.log("func: " + args);
    return args;
}
async function asyncCall() {
    let value = await taskpool.execute(func, 100);
}
```



execute(task: Task, priority?: Priority): Promise<unknown>;

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型     | 必填 | 说明                             |
| -------- | -------- | ---- | -------------------------------- |
| task     | Task     | 是   | 需要在taskpool中执行的任务       |
| priority | Priority | 否   | 等待执行的Task的优先级，暂未实现 |

**返回值：**

| 类型             | 说明                           |
| ---------------- | ------------------------------ |
| Promise<unknown> | execute是异步方法，返回Promise |

**错误码：**

| 错误码   | 错误说明                                |
| -------- | --------------------------------------- |
| 401      | the input parameters are invalid.       |
| 10200014 | the function is not mark as concurrent. |

**示例：**

```js
import taskpool from '@ohos.taskpool';

function func(args) {
    console.log("func: " + args);
    return args;
}
var task = new taskpool.Task(func, "this is first Task");
async function asyncCall() {
    let value = await taskpool.execute(task);
}
```



## cancel

cancel(task: Task): void

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                           |
| ------ | ---- | ---- | ------------------------------ |
| task   | Task | 是   | 需要在taskpool中取消执行的任务 |

**返回值：**

| 类型 | 说明     |
| ---- | -------- |
| void | 无返回值 |

**错误码：**

| 错误码   | 错误信息              |
| -------- | --------------------- |
| 10200015 | the task is not exist |
| 10200016 | the task is running   |

**示例：**

```js
import taskpool from '@ohos.taskpool';

function func(args) {
    console.log("func: " + args);
    return args;
}
var task = new taskpool.Task(func, "this is first Task");
let value = taskpool.execute(task);
taskpool.cancel(task);
```