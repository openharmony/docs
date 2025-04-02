# TaskPool简介

TaskPool为应用程序提供多线程环境，降低资源消耗、提高系统性能，无需管理线程生命周期。具体接口信息及使用方法详情请见[TaskPool](../reference/apis-arkts/js-apis-taskpool.md)。

## TaskPool运作机制

TaskPool运作机制示意图

![zh-cn_image_0000001964858368](figures/zh-cn_image_0000001964858368.png)

TaskPool支持开发者在宿主线程提交任务到任务队列，系统选择合适的工作线程执行任务，再将结果返回给宿主线程。接口易用，支持任务执行、取消和指定优先级，同时通过系统统一线程管理，结合动态调度及负载均衡算法，可以节约系统资源。系统默认启动一个任务工作线程，任务多时会扩容。工作线程数量上限取决于设备的物理核数，内部管理具体数量，确保调度和执行效率最优。长时间无任务分发时会缩容，减少工作线程数量。

## TaskPool注意事项

- 实现任务的函数需要使用[@Concurrent装饰器](#concurrent装饰器)标注，且仅支持在.ets文件中使用。

- 从API version 11开始，跨并发实例传递带方法的实例对象时，该类必须使用装饰器[@Sendable装饰器](arkts-sendable.md#sendable装饰器)标注，且仅支持在.ets文件中使用。

- 任务函数在TaskPool工作线程的执行耗时不能超过3分钟（不包含Promise和async/await异步调用的耗时，例如网络下载、文件读写等I/O任务的耗时）。否则，任务将被强制终止。

- 实现任务的函数入参需满足序列化支持的类型，详情请参见[线程间通信对象](interthread-communication-overview.md)。

- ArrayBuffer参数在TaskPool中默认转移，需要设置转移列表的话可通过接口[setTransferList()](../reference/apis-arkts/js-apis-taskpool.md#settransferlist10)设置。

- 由于不同线程中上下文对象是不同的，因此TaskPool工作线程只能使用线程安全的库，例如UI相关的非线程安全库不能使用。

- 序列化传输的数据量限制为16MB。

- [Priority](../reference/apis-arkts/js-apis-taskpool.md#priority)的IDLE优先级是用来标记需要在后台运行的耗时任务（例如数据同步、备份），它的优先级别是最低的。这种优先级的任务只在所有线程都空闲时触发执行，并且只会占用一个线程。

- Promise不支持跨线程传递。TaskPool返回pending或rejected状态的Promise时失败，返回fulfilled状态的Promise时TaskPool会解析返回的结果，如果结果可以跨线程传递，则返回成功。

- 不支持在TaskPool工作线程中使用[AppStorage](../quick-start/arkts-appstorage.md)。

- TaskPool支持开发者在宿主线程封装任务并提交给任务队列，理论上支持的任务数量没有上限。然而，任务的执行效率受限于任务的优先级和系统资源。当工作线程达到最大数量时，任务的执行效率可能会下降。

- TaskPool不支持指定任务所运行的线程，任务会被分配到空闲的线程中执行。如果需要指定任务所运行的线程，建议使用[Worker](worker-introduction.md)。

## \@Concurrent装饰器

在使用[TaskPool](../reference/apis-arkts/js-apis-taskpool.md)时，执行的并发函数需要使用该装饰器修饰，否则无法通过相关校验。

> **说明：**
>
> 从API version 9开始，支持使用\@Concurrent装饰器声明并校验并发函数。

### 装饰器说明

| \@Concurrent并发装饰器 | 说明 |
| -------- | -------- |
| 装饰器参数 | 无。 |
| 使用场景 | 仅支持在Stage模型的工程中使用。仅支持在.ets文件中使用。 |
| 装饰的函数类型 | 允许标注async函数或普通函数。禁止标注generator、箭头函数、类方法。不支持类成员函数或者匿名函数。 |
| 装饰的函数内的变量类型 | 允许使用local变量、入参和通过import引入的变量。禁止使用闭包变量。 |
| 装饰的函数内的返回值类型 | 支持的类型请查[线程间通信对象](interthread-communication-overview.md)。 |

> **说明：**
>
> 由于\@Concurrent标记的函数不能访问闭包，因此函数内部不能调用当前文件的其他函数，例如：
>
> ```ts
> function bar() {
> }
> 
> @Concurrent
> function foo() {
> bar(); // 违反闭包原则，报错
> }
> ```

### 装饰器使用示例

#### 并发函数一般使用

并发函数为一个计算两数之和的普通函数，taskpool执行该函数并返回结果。

示例：

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function add(num1: number, num2: number): number {
  return num1 + num2;
}

async function ConcurrentFunc(): Promise<void> {
  try {
    let task: taskpool.Task = new taskpool.Task(add, 1, 2);
    console.info("taskpool res is: " + await taskpool.execute(task));
  } catch (e) {
    console.error("taskpool execute error is: " + e);
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            ConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

#### 并发函数返回Promise

并发函数中返回Promise时需要特别关注。如示例所示，testPromise和testPromise1等并发同步函数会处理该Promise并返回结果。

示例：

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function testPromise(args1: number, args2: number): Promise<number> {
  return new Promise<number>((resolve, reject)=>{
    resolve(args1 + args2);
  });
}

@Concurrent
async function testPromise1(args1: number, args2: number): Promise<number> {
  return new Promise<number>((resolve, reject)=>{
    resolve(args1 + args2);
  });
}

@Concurrent
async function testPromise2(args1: number, args2: number): Promise<number> {
  return await new Promise<number>((resolve, reject)=>{
    resolve(args1 + args2);
  });
}

@Concurrent
function testPromise3() {
  return Promise.resolve(1);
}

@Concurrent
async function testPromise4(): Promise<number> {
  return 1;
}

@Concurrent
async function testPromise5(): Promise<string> {
  return await new Promise((resolve) => {
    setTimeout(()=>{
      resolve("Promise setTimeout after resolve");
    }, 1000)
  });
}

async function testConcurrentFunc() {
  let task1: taskpool.Task = new taskpool.Task(testPromise, 1, 2);
  let task2: taskpool.Task = new taskpool.Task(testPromise1, 1, 2);
  let task3: taskpool.Task = new taskpool.Task(testPromise2, 1, 2);
  let task4: taskpool.Task = new taskpool.Task(testPromise3);
  let task5: taskpool.Task = new taskpool.Task(testPromise4);
  let task6: taskpool.Task = new taskpool.Task(testPromise5);

  taskpool.execute(task1).then((d:object)=>{
    console.info("task1 res is: " + d);
  }).catch((e:object)=>{
    console.info("task1 catch e: " + e);
  })
  taskpool.execute(task2).then((d:object)=>{
    console.info("task2 res is: " + d);
  }).catch((e:object)=>{
    console.info("task2 catch e: " + e);
  })
  taskpool.execute(task3).then((d:object)=>{
    console.info("task3 res is: " + d);
  }).catch((e:object)=>{
    console.info("task3 catch e: " + e);
  })
  taskpool.execute(task4).then((d:object)=>{
    console.info("task4 res is: " + d);
  }).catch((e:object)=>{
    console.info("task4 catch e: " + e);
  })
  taskpool.execute(task5).then((d:object)=>{
    console.info("task5 res is: " + d);
  }).catch((e:object)=>{
    console.info("task5 catch e: " + e);
  })
  taskpool.execute(task6).then((d:object)=>{
    console.info("task6 res is: " + d);
  }).catch((e:object)=>{
    console.info("task6 catch e: " + e);
  })
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            testConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

#### 并发函数中使用自定义类或函数

在并发函数中使用自定义类或函数时，需将其定义在不同的文件中，否则会被认为是闭包。如以下示例所示。

示例：

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';
import { testAdd, MyTestA, MyTestB } from './Test';

function add(arg: number) {
  return ++arg;
}

class TestA {
  constructor(name: string) {
    this.name = name;
  }
  name: string = 'ClassA';
}

class TestB {
  static nameStr: string = 'ClassB';
}

@Concurrent
function TestFunc() {
  // case1：在并发函数中直接调用同文件内定义的类或函数

  // 直接调用同文件定义的函数add()，add飘红报错：Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>
  // add(1);
  // 直接使用同文件定义的TestA构造，TestA飘红报错：Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>
  // let a = new TestA("aaa");
  // 直接访问同文件定义的TestB的成员nameStr，TestB飘红报错：Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>
  // console.info("TestB name is: " + TestB.nameStr);

  // case2：在并发函数中调用定义在Test.ets文件并导入当前文件的类或函数

  // 输出结果：res1 is: 2
  console.info("res1 is: " + testAdd(1));
  let tmpStr = new MyTestA("TEST A");
  // 输出结果：res2 is: TEST A
  console.info("res2 is: " + tmpStr.name);
  // 输出结果：res3 is: MyTestB
  console.info("res3 is: " + MyTestB.nameStr);
}


@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          let task = new taskpool.Task(TestFunc);
          taskpool.execute(task).then(() => {
            console.info("taskpool: execute task success!");
          }).catch((e:BusinessError) => {
            console.error(`taskpool: execute: Code: ${e.code}, message: ${e.message}`);
          })
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

```ts
// Test.ets
export function testAdd(arg: number) {
  return ++arg;
}

@Sendable
export class MyTestA {
  constructor(name: string) {
    this.name = name;
  }
  name: string = 'MyTestA';
}

export class MyTestB {
  static nameStr:string = 'MyTestB';
}
```

#### 并发异步函数中使用Promise

在并发异步函数中使用Promise时，建议搭配await使用。这样TaskPool可以捕获Promise中的异常。推荐使用示例如下。

示例：

```ts
import { taskpool } from '@kit.ArkTS'

@Concurrent
async function testPromiseError() {
  await new Promise<number>((resolve, reject) => {
    resolve(1);
  }).then(()=>{
    throw new Error("testPromise Error");
  })
}

@Concurrent
async function testPromiseError1() {
  await new Promise<string>((resolve, reject) => {
    reject("testPromiseError1 Error msg");
  })
}

@Concurrent
function testPromiseError2() {
  return new Promise<string>((resolve, reject) => {
    reject("testPromiseError2 Error msg");
  })
}

async function testConcurrentFunc() {
  let task1: taskpool.Task = new taskpool.Task(testPromiseError);
  let task2: taskpool.Task = new taskpool.Task(testPromiseError1);
  let task3: taskpool.Task = new taskpool.Task(testPromiseError2);

  taskpool.execute(task1).then((d:object)=>{
    console.info("task1 res is: " + d);
  }).catch((e:object)=>{
    console.info("task1 catch e: " + e);
  })
  taskpool.execute(task2).then((d:object)=>{
    console.info("task2 res is: " + d);
  }).catch((e:object)=>{
    console.info("task2 catch e: " + e);
  })
  taskpool.execute(task3).then((d:object)=>{
    console.info("task3 res is: " + d);
  }).catch((e:object)=>{
    console.info("task3 catch e: " + e);
  })
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            testConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
