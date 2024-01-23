# ArkTS语言基础类库开发常见问题


## TaskPool、Worker和各个ArkTS引擎实例之间是否内存隔离

TaskPool和Worker基于Actor模型实现并发，Actor模型具备内存隔离的特性，所以TaskPool、Worker和各个ArkTS引擎实例之间是内存隔离的。


## 在TaskPool的生命周期中TaskPool线程什么时候会被销毁

TaskPool的生命周期无需开发者手动去管理。有一定时间没有执行新的任务，或者在TaskPool线程上没有执行监听任务的情况下，线程可能会被销毁。


## TaskPool对于任务时间有没有限制

任务时常上限3分钟（不包含Promise和async/await异步调用的耗时）。


## 对于预加载任务量大的场景推荐使用Worker还是TaskPool

Worker存在数量限制，支持最多同时存在8个Worker。所以针对预加载任务量大的场景，推荐使用TaskPool。更多TaskPool和Worker的特点和场景选择，可见[Worker和TaskPool的对比](../arkts-utils/taskpool-vs-worker.md#实现特点对比)。


## 存在线程复用的并发场景，推荐使用Worker还是TaskPool

同一个Worker无法执行不同的任务，所以针对线程复用的并发场景，推荐使用TaskPool。

## 是否可以在TaskPool中动态加载模块（Har、Hsp、So）？(API 10)

**解决方案**

可以，TaskPool动态加载能力跟主线程能力一致。但是TaskPool线程加载后，由于模块化线程隔离的缘故，不能给主线程复用。

## 如何实现多线程数据共享？(API 10)

**原理澄清**

由于ArkTS是单线程模型，内存隔离，因此大部分普通对象跨线程均采用序列化方式。

**解决方案**

目前部分支持共享的对象如下:
通过ArrayBuffer的转移传输和SharedArrayBuffer进行共享。

**参考资料**

1. [多线程并发概述 (TaskPool和Worker)](../arkts-utils/multi-thread-concurrency-overview.md)

## 线程间JS对象的数据通信依赖序列化方式，是否存在性能问题？(API 10)

**原理澄清**

目前线程间对象的数据通信依赖序列化、反序列化，耗时与数据量相关，需要控制传输的数据量，或者采用ArrayBuffer或者SharedArrayBuffer的转移或者共享。


## Worker可用线程数量少，无法满足应用平移适配需求，部分应用可能超过200个线程。 TaskPool和Worker都无法提供对等的线程数量，应该如何设计大量线程并发方案？(API 10)

**解决方案**

系统采用ArkTS作为开发语言，由于底层线程模型对接了libuv，因此在应用进程启动后，会有多个I/O线程用于I/O操作，JS线程的I/O异步操作，会在I/O线程执行，JS线程可以同时执行其他操作，不存在阻塞等待问题。
同时，ArkTS提供了TaskPool并发API，类似GCD的线程池能力，可以执行任务，而且不需要开发者进行线程生命周期管理。
因此针对需要大量线程的问题，开发建议如下:
将多线程任务转变为并发任务，通过TaskPool分发执行
I/O型任务不需要单独开启线程，而是在当前线程（可以是TaskPool线程）执行
少量需要常驻的CPU密集型任务，采用Worker，并且需要控制在8个及以下。

**参考链接**

1. [TaskPool和Worker的对比 (TaskPool和Worker)](../arkts-utils/taskpool-vs-worker.md)

## 并发任务的调度及实时性问题，如何设置Task优先级，各个优先级的调度策略有什么区别，原理是什么，分别推荐在什么场景使用？(API 10)

**解决方案**

当前支持设置任务优先级，示例如下

**代码示例**

```ts
@Concurrent
function printArgs(args: number): number {
  console.log("printArgs: " + args);
  return args;
}

let task: taskpool.Task = new taskpool.Task(printArgs, 100); // 100: test number
let highCount = 0;
let mediumCount = 0;
let lowCount = 0;
let allCount = 100;
for (let i: number = 0; i < allCount; i++) {
  taskpool.execute(task, taskpool.Priority.LOW).then((res: number) => {
    lowCount++;
    console.log("taskpool lowCount is :" + lowCount);
  });
  taskpool.execute(task, taskpool.Priority.MEDIUM).then((res: number) => {
    mediumCount++;
    console.log("taskpool mediumCount is :" + mediumCount);
  });
  taskpool.execute(task, taskpool.Priority.HIGH).then((res: number) => {
    highCount++;
    console.log("taskpool highCount is :" + highCount);
  });
}
```

**参考链接**

1. [Priority](../reference/apis/js-apis-taskpool.md)

## 如何将类Java语言的线程模型（内存共享）在各场景的实现方式，转换成在ArkTS的线程模型下（内存隔离）的实现方式？(API 11)

**解决方案**

可以利用TaskPool接口转换，大概可以分为如下五个场景。

场景一：主线程将独立的耗时任务放到子线程执行  
代码示例：  
共享内存写法

```ts
class Task {
  static run(args) {
    // Do some independent task
  }
}

let thread = new Thread(() => {
  let result = Task.run(args)
  // deal with result
})
```

ArkTS写法

```ts
import taskpool from '@ohos.taskpool'
@Concurrent
function run(args: string) {
  // Do some independent task
}

let args: string = '';
let task = new taskpool.Task(run, args)
taskpool.execute(task).then((ret: string) => {
  // Return result
})
```

场景二：主线程将创建的类对象实例在子线程使用  
代码示例：  
共享内存写法  

```ts
class Material {
  action(args) {
    // Do some independent task
  }
}

let material = new Material()
let thread = new Thread(() => {
  let result = material.action(args)
  // deal with result
})
```

ArkTS写法

```ts
import taskpool from '@ohos.taskpool'
@Concurrent
function runner(material: Material, args: string): void {
  return material.action(args);
}
@Sendable
class Material {
  action(args: string) {
    // Do some independent task
  }
}

let material = new Material()
taskpool.execute(runner, material).then((ret: string) => {
  // Return result
})
```

场景三：主线程将独立的耗时任务放到子线程执行  
代码示例：

```ts
class Task {
  run(args) {
    // Do some independent task
    task.result = true
  }
}

let task = new Task()
let thread = new Thread(() => {
  let result = task.run(args)
  // deal with result
})
```

ArkTS写法

```ts
import taskpool from '@ohos.taskpool'
@Concurrent
function runner(task: Task) {
  let args: string = '';
  task.run(args);
}
@Sendable
class Task {
  result: string = '';

  run(args: string) {
    // Do some independent task
    return true;
  }
}

let task = new Task();
taskpool.execute(runner, task).then((ret: string) => {
  task.result = ret;
})
```

场景四：子线程主动更新主线程状态  
代码示例：

```ts
class Task {
  run(args) {
    // Do some independent task
    runOnUiThread(() => {
      UpdateUI(result)
    })
  }
}

let task = new Task()
let thread = new Thread(() => {
  let result = task.run(args)
  // deal with result
})
```

ArkTS写法

```ts
import taskpool from '@ohos.taskpool'
@Concurrent
function runner(task) {
  task.run()
}

@Sendable
class Task {
  run(args) {
    // Do some independent task
    taskpool.Task.sendData(result)
  }
}

let task = new Task()
let run = new taskpool.Task(runner, task)
run.onReceiveData((result) => {
  UpdateUI(result)
})
taskpool.execute(run).then((ret) => {
  // Return result
})
```

场景五：子线程同步调用主线程的接口  
代码示例：

```ts
class SdkU3d {
  static getInst() {
    return SdkMgr.getInst();
  }

  getPropStr(str: string) {
    return xx;
  }
}

let thread = new Thread(() => {
  // 游戏线程
  let sdk = SdkU3d.getInst()
  let ret = sdk.getPropStr("xx")
})
```

ArkTS写法

```ts
// 主线程
class SdkU3d {
  static getInst() {
    return SdkMgr.getInst();
  }

  getPropStr(str: string) {
  }
}

const workerInstance = new
worker.ThreadWorker("xx/worker.ts");
let sdk = SdkU3d.getInst()
workerInstance.registerGlobalCallObject("instance_xx", sdk);
workerInstance.postMessage("start");
const mainPort = worker.workerPort;
mainPort.onmessage = (e: MessageEvents): void => {
  let ret = mainPort.callGlobalCallObjectMethod("instance_xx", "getPropStr", "xx");
}
```
**参考链接**

1. [并发概述](../arkts-utils/concurrency-overview.md)

## TaskPool和Worker的区别是什么，分别推荐在什么场景下使用？(API 10)

**概念澄清**

两者是不同颗粒度的并发API，Worker更像Thread或者Service维度，Task就是单一任务维度。  
同时TaskPool简化开发者开发并发程序，支持优先级和取消，并且通过统一管理节省系统资源优化调度。  

相同点是：在JS相关的线程间交互上，二者本质都是内存隔离模型，参数与范围值的限制是一致的，也有开销。（需注意并发任务粒度）

**参考链接**

1. [TaskPool和Worker的对比 (TaskPool和Worker)](../arkts-utils/taskpool-vs-worker.md)

## Worker和TaskPool的线程数量是否都有限制，如果超过会如何？在使用时，是否会相互影响，如Worker在达到上限数量时，会影响TaskPool吗？(API 10)

**规格澄清**

TaskPool内部会动态调整线程个数，不支持设置数量，只需要往线程池中抛任务，确保高优先级任务的及时执行。  
Worker的线程个数最多8个，如果Worker超过规定个数，会创建失败。  
TaskPool与Worker不影响。两者独立，Worker是固定数量，当前是8个。TaskPool线程池的数量会根据硬件条件、任务负载等情况动态调整。

**参考链接**

1. [TaskPool和Worker的对比 (TaskPool和Worker)](../arkts-utils/taskpool-vs-worker.md)

## 是否有线程安全的容器类？(API 10)

**原理澄清**

因为没有对象直接共享，所以容器都是线程安全的

**参考链接**

1. [异步并发概述 (Promise和async/await)](../arkts-utils/async-concurrency-overview.md)

## TaskPool，Worker中任务调度机制是什么？是否和JS单线程的事件循环机制一样的？先执行完微任务队列，再执行宏任务？(API 10)

**原理澄清**

TaskPool与Worker采用事件事件循环接收线程间通信的消息。
Worker不支持消息的优先级。
TaskPool中的任务支持优先级设置，会影响消息的处理优先级。

## 系统多线程模型是什么样的？(API 10)

**解决方案**

ArkTS主要提供TaskPool API支持多线程开发，常驻耗时任务还可以使用Worker，但是Worker有数量限制，当前最大数量是8个Worker。
Native侧建议使用FFRT线程池，pthread暂无限制。

## 是否支持Context跨线程传递？(API 10)

**规格澄清**

支持，可以直接将Context作为参数传递

**参考链接**

1. [可共享对象](../arkts-utils/serialization-support-types.md)

## 在多线程并发场景中，如何实现安全访问同一块共享内存？(API 10)

**规格澄清**
	
可以使用共享对象SharedArrayBuffer实现。SharedArrayBuffer对象存储的数据在同时被修改时，需要通过Atomics原子操作保证其同步性，即下个操作开始之前务必需要等到上个操作已经结束。

**代码示例**

```ts
// index.ets
let sab = new SharedArrayBuffer(32);
// int32 buffer view for sab
let i32a = new Int32Array(sab);
i32a[0] = 0;

let producer = new worker.ThreadWorker("entry/ets/workers/worker_producer.ts");
producer.postMessage(sab);

function consumection(e: MessageEvents) {
  let sab: SharedArrayBuffer = e.data;
  let i32a = new Int32Array(sab);
  console.info("Customer: received sab");
  while (true) {
    Atomics.wait(i32a, 0, 0); //blocked here until be waked.
    let length = i32a.length;
    for (let i = length - 1; i > 0; i--) {
      console.info("arraybuffer " + i + " value is " + i32a[i]);
      i32a[i] = i;
    }
  }
}
```

## 子线程和主线程相比，谁的优先级更高，任务执行策略是什么？(API 10)

**原理澄清**

主线程作为UI线程，拥有最高优先级。在负载较高时，执行会更快；负载较低时，效率差别不大。
子线程可以通过优先级设置，任务优先级等影响调度。

## ArkTS是否有全局强制切换线程执行和调度的接口？(API 10)

**规格澄清**

Worker支持通过PostMessage往父线程抛任务。TaskPool支持往父线程发消息，触发任务。

**参考链接**

1. [@ohos.taskpool（启动任务池）](../reference/apis/js-apis-taskpool.md)
2. [@ohos.worker (启动一个Worker)](../reference/apis/js-apis-worker.md)

## ArkTS是否支持类似Java的共享内存模型进行多线程开发吗？(API 10)

**规格澄清**

无法做到通过加锁的方式实现多个线程同时对同一个内存对象的同时操作。ArkTS是Actor并发模型，线程间内存隔离，当前只支持SharedArrayBuffer或者Native层对象的共享。

**参考链接**

1. [多线程并发概述 (TaskPool和Worker)](../arkts-utils/multi-thread-concurrency-overview.md)

## ArkTS的SendableClass对象内存共享的原理是什么？有什么限制？如何使用？(API 11)

**原理澄清**

SendableClass是基于Actor内存隔离并发模型的扩展，Sendable对象的内存是线程间共享的，但是仍然需要满足单线程无锁化运行。因此，要保证同一个Sendable实例不能多线程并发访问，开发者需要通过同步机制保证线程安全。

**规格澄清**

Sendable对象需要满足一定的规格：
1. 成员属性为 Sendable类 或者基础类型（string number boolean等，Array等容器类待扩展后支持）
2. 成员属性必须显式初始化
3. 成员函数不能使用闭包，只能使用入参 或者 this成员 或者 import导入的变量
4. 只允许Sendable类继承Sendable类
5. @Sendable只能写在ArkTS(ets)文件中
6. 不支持#定义私有属性，要用private
7. 导出Sendable类的文件，不能导出非Sendable属性
8. 传输方式有如下两种：
    8.1 序列化传递：深拷贝到其他线程，非共享模式。
    8.2 共享模式：可以跨线程引用传递，多线程可同时读写，开发者需要自行采用同步机制避免多线程竞争。

**参考链接**

1. [多线程并发概述 (TaskPool和Worker)](../arkts-utils/multi-thread-concurrency-overview.md)

## ArkTs类的方法是否支持重载？怎么实现？(API 10)

**解决方案**

当前ArkTS支持TS中的重载，即多个重载签名 + 实现签名 + 函数体的形式。函数签名只用在编译期进行类型检查，不保留到运行时。
ArkTS不支持多个函数体实现的重载。

示例：

```ts
class User {
  age: number

  constructor(age: number) {
    this.age = age
  }
}

// 声明
function test(param: User): number;

function test(param: number, flag: boolean): number;

// 实现
function test(param: User | number, flag?: boolean) {
  if (typeof param === 'number') {
    return param + (flag ? 1 : 0)
  } else {
    return param.age
  }
}
```

##  系统里的线程机制是怎么样的？每个线程是一个单独的JS引擎吗？如果每个线程开销比较小的话，为啥要限制线程数量？(API 10)

**原理澄清**

设备的核数有限，线程数泛滥引起调度开销和内存开销。  
系统提供了ArkTS任务池和FFRT任务池支持系统统一调度。  
系统ArkTS线程中JS部分是基于内存隔离的Actor模型实现，每个线程拥有单独的JS环境实例，因此开启线程会有较大的内存开销。  
另外设备的核数有限，其他系统应用线程数开得过多是因为同步锁、同步I/O编程的方式导致。  
系统提供的异步I/O调用均分发到I/O线程池，不会阻塞应用线程，因此不需要独占线程调用I/O，所需的线程数量远小于其他操作系统。  

##  TaskPool在任务执行过程中如何跟主线程进行通信？如何操作同一块内存变量？(API 10)

**解决方案**

TaskPool的任务支持通过sendData接口触发主线程的onReceiveData回调。  
当前多个线程之间支持通过SharedArrayBuffer进行同一块内存的操作。

##  对于多线程操作首选项和数据库是不是线程安全的？还是每一个线程独立的？(API 10)

**解决方案**

是线程安全的。

##  如果在ArkTS中大部分后台任务（计算、埋点、入库）都使用异步并发的方式，会不会使主线程越来越慢，引起卡顿丢帧问题？(API 10)

**解决方案**

ArkTS层接口的异步如果不涉及I/O操作，则异步任务会在主线程的微任务执行时机触发，仍然占用主线程。推荐使用TaskPool，分发到后台任务池进行。

##  synchronized在java中可以修饰方法，从而简单地实现函数的同步调用。在系统ets开发中，如何简单实现该功能?(API 10)

**解决方案**

当前不支持关键字修饰的同步机制。后续会支持AsyncLock形式的同步机制，支持将需要同步的代码块放到异步代码块中。

##  在ArkTS的主线程中使用await会堵塞主线程吗？（API 10）

比如如下代码在主线程中执行：  
``const response = await reqeust.buildCall().execute<string>();``  
这种写法会导致主线程堵塞吗？

**解决方案**

并不会。await会挂起当前异步任务，等异步任务满足条件后再唤醒执行，主线程可以处理其他任务。

##  当使用C/C++进行开发时，如何实现在子线程中直接调用H系统 SDK提供的TS接口，而不是post到主线程上？请提供实现步骤和代码示例。（API 10）

**解决方案**

当前还不支持。
