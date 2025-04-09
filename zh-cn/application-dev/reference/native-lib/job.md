# Job（获取EAWorker任务执行结果）
[EAWorker](./eaworker_managed.md#eaworker)执行任务返回值的句柄，用于表征一个任务，可以通过[Await](#await)等待获取任务的返回值。

## Await
Await(): T

用于获得[Job](#job)的值。

**ArkTS 版本：** 本接口仅支持ArkTS1.2。

**返回值：**
| 类型       | 说明                 |
| -------- | ------------------ |
| T   | 开发者提交任务的返回值，其类型和开发者提交任务时候指定的泛型类型一致。 |

**示例：**
```ts
import hilog from '@ohos.hilog'

// 定义任务函数
function logNumber(arg: int): int {
    hilog.info(0x0000, "testTag", "Received number: " + arg);
    return arg * 2;
}

// 创建Worker并提交任务
const worker = new EAWorker();
const job = worker.run<int>(logNumber, 42);

// 获取异步结果
hilog.info(0x0000, "testTag", "Result: " + job.Await());  // 输出：Result: 84
```

# CompletableJob
继承自[Job](#job)，开发者可以手动创建CompletableJob实例，并通过[finish](#finish)以及[fail](#fail)方法给实例赋值。其中finish可用于表征任务执行成功并将结果设置到实例中，fail表示任务执行失败并将失败的原因赋值到实例中。开发者可以通过[Await](#await-1)方法获取任务的执行结果。

## constructor
constructor()

[CompletableJob](#completablejob)的构造器，用于构造一个开发者能够设置任务成功与失败的CompletableJob实例。

**ArkTS 版本：** 本接口仅支持ArkTS1.2。

**示例：**
```ts
// 创建一个能接受String类型作为任务完成值类型的CompletableJob
let job = new CompletableJob<String>()
```

## finish
finish()

用于将一个[CompletableJob](#completablejob)状态置为完成态，并将值设置为undefined。

**ArkTS 版本：** 本接口仅支持ArkTS1.2。

**示例：**
```ts
let job = new CompletableJob<NullishType>();
job.finish();
```

## finish
finish\<T\>(value: T)

用于将一个[CompletableJob](#completablejob)状态设置为完成态，并将其值设置为开发者传入的value。

**ArkTS 版本：** 本接口仅支持ArkTS1.2。

**参数：**
|参数名|类型|必填|说明|
|-----|----|--|----|
|value|T|是|设置CompletableJob的值。|

**示例：**
```ts
let job = new CompletableJob<String>();
job.finish("finished");
```

## fail
fail()

用于将一个[CompletableJob](#completablejob)状态设置为失败，并将值设置为一个空的Error。

**ArkTS 版本：** 本接口仅支持ArkTS1.2。

**示例：**
```ts
let job = new CompletableJob<String>();
job.fail();
```

## fail
fail(error: Error)

用于将一个[CompletableJob](#completablejob)状态设置为失败，并将其值设置为开发者传入的error。

**ArkTS 版本：** 本接口仅支持ArkTS1.2。

**参数：**
|参数名|类型|必填|说明|
|------|----|---|---|
|error| Error|是|设置CompletableJob失败的值。|

**示例：**
```ts
let job = new CompletableJob<String>();
job.fail(new Error("job failed"));
```

## Await
Await(): T

用于获取[CompletableJob](#completablejob)的值。

**ArkTS 版本：** 本接口仅支持ArkTS1.2。

**返回值：**
| 类型       | 说明                 |
| -------- | ------------------ |
| T   | CompletableJob的值，其类型和开发者创建CompletableJob时候指定的泛型类型一致。 |

**示例：**

通过Await获取完成状态的CompletableJob的值。
```ts
import hilog from '@ohos.hilog'

let job = new CompletableJob<String>();
job.finish("job finished");

hilog.info(0x0000, "testTag", job.Await()); // 输出job finished

let job2 = new CompletableJob<int>();
job2.finish(2);

hilog.info(0x0000, "testTag", job2.Await());// 输出 2
```
通过Await获取失败状态的CompletableJob
的值。
```ts
import hilog from '@ohos.hilog'

let job = new CompletableJob<String>();
try {
    job.fail(new Error("job executed error"));
    job.Await();
} catch(e: Error) {
    hilog.error(0x0000, "testTag", e.toString()); // 输出Error: job executed error
}
```