# EAWorker（独占线程任务执行器）(ArkTS)

EAWorker类为开发者提供了以独占线程模式执行异步任务的接口。通过创建EAWorker实例，系统会自动分配专属工作线程，开发者可复用该实例执行不同任务，有效提升线程资源利用率。  
> **说明：**
>
> 使用完毕后必须显式调用[join](#join)方法释放线程资源，避免内存泄漏。

文档中涉及到概念以及解释：
- 互操作（interop）：ArkTS1.2和ArkTS1.1代码相互操作。由于ArkTS1.1运行时为单线程实例，因此支持互操作的EAWorker会持有不同的ArkTS1.1运行时实例用于执行ArkTS1.1字节码，对应的ArkTS1.1中全局变量在不同的线程中也对应不同的实例。

## constructor
constructor(needInterop: boolean = false)

EAWorker的构造器，用于创建支持或者不支持interop能力的EAWorker。

**ArkTS 版本：** 本接口仅支持ArkTS1.2。

**参数:**
| 参数名         | 类型      | 必填| 说明                                                                        |
|----------------|-----------|-------|----------------------------------------------------------------------------|
| needInterop  | boolean | 否    | 参数用于控制创建的EAWorker实例是否支持interop。true表示支持互操作，false表示不支持互操作。默认值为false。 |

**示例：**
```ts
// 创建基础实例（不开启互操作）
let worker = new EAWorker();

// 创建支持ArkTS1.1互操作的实例
let interopWorker = new EAWorker(true);
```
## run
run\<R\>(task: Function, ...args: NullishType[]): Job\<R\>

向当前Worker线程提交异步任务。需通过已创建的EAWorker实例调用，任务将在该实例绑定的独占线程中执行。

**ArkTS 版本：** 该接口仅适用于ArkTS1.2。

**参数：**
| 参数名  | 类型              | 必填  | 说明           |
| ---- | --------------- | --- | ------------ |
| task | Function        | 是   | 开发者期望执行的任务函数。 |
| args | NullishType[]   | 否   |  任务函数的参数列表。默认值undefined。 |

**返回值：**
| 类型       | 说明                 |
| -------- | ------------------ |
| Job\<R\>   | 任务执行句柄，可通过[Await](./job.md#await)获取异步结果。 |

**示例：**

基础任务执行。
```ts
import hilog from '@ohos.hilog'
// 定义任务函数
function logNumber(arg: int): int {
    hilog.info(0x0000, "testTag", "Received number: " + arg);
    return arg * 2;
}

// 创建 Worker 并提交任务
const worker = new EAWorker();
const job = worker.run<int>(logNumber, 42);

// 获取异步结果
hilog.info(0x0000, "testTag", "Result: " + job.Await());  // 输出：Result: 84
```
创建支持与ArkTS1.1互操作的EAWorker并执行任务。
```ts
// ArkTS1.1 文件 taskFile.ets
import hilog from '@ohos.hilog'

export function task(a: number): string {
    hilog.info(0x0000, "testTag", "ArkTS 1.1 task called: " + a); // 输出：ArkTS 1.1 task called: 1
    return "success";
}
```

```ts
// ArkTS1.2 文件
import hilog from '@ohos.hilog'

let eaw = new EAWorker(true);

let job = eaw.run<string>((a:number): string => {
    let arg = ESObject.wrapInt(a);
    let mod = ESObject.load("taskFile");
    return mod.getProperty("task").invoke(arg).toString()
}, 1)
hilog.info(0x0000, "testTag", "res: " + job.Await()); // 输出：res: success
```

## join
join(): void

主动销毁Worker线程资源。调用此接口会向EAWorker提交任务请求释放当前EAWorker实例绑定的工作线程，停止接收新任务并回收系统资源。

> **说明：**
> 
> 开发者调用join之后，EAWorker实例仍旧存活不会立即被回收，但是对应的系统线程资源已经销毁，因此开发者在调用[join](#join)之后，不应该继续使用EAWorker实例提交任务。

**ArkTS 版本：** 该接口仅适用于ArkTS1.2。

**示例：**
```ts
import hilog from '@ohos.hilog'

let eaw = new EAWorker();
eaw.run<void>(() => {
    hilog.info(0x0000, "testTag", "hello");
});

eaw.join();
```