# ArkTS语言基础类库开发常见问题
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kir175; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->


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

系统采用ArkTS作为开发语言，由于底层线程模型对接了libuv，因此在应用进程启动后，会有多个I/O线程用于I/O操作，JS线程的I/O异步操作，会在I/O线程执行，JS线程可以同时执行其他操作，不存在阻塞等待问题。同时，ArkTS提供了TaskPool并发API，类似GCD的线程池能力，可以执行任务，而且不需要开发者进行线程生命周期管理。因此针对需要大量线程的问题，开发建议如下:将多线程任务转变为并发任务，通过TaskPool分发执行I/O型任务不需要单独开启线程，而是在当前线程（可以是TaskPool线程）执行。少量需要常驻的CPU密集型任务，采用Worker，并且需要控制在8个及以下。

**参考链接**

1. [TaskPool和Worker的对比 (TaskPool和Worker)](../arkts-utils/taskpool-vs-worker.md)

## 并发任务的调度及实时性问题，如何设置Task优先级，各个优先级的调度策略有什么区别，原理是什么，分别推荐在什么场景使用？(API 10)

**解决方案**

当前支持设置任务优先级，同一任务重复执行的顺序和优先级没关系，主要看任务执行的顺序，不同任务指定不同优先级示例如下：

**代码示例**

```ts
@Concurrent
function printArgs(args: number): number {
  let t: number = Date.now();
  while (Date.now() - t < 1000) { // 1000: delay 1s
    continue;
  }
  console.info("printArgs: " + args);
  return args;
}

let allCount = 100; // 100: test number
let taskArray: Array<taskpool.Task> = [];
// 创建300个任务并添加至taskArray
for (let i: number = 0; i < allCount; i++) {
  let task1: taskpool.Task = new taskpool.Task(printArgs, i);
  taskArray.push(task1);
  let task2: taskpool.Task = new taskpool.Task(printArgs, i + 100); // 100: test number
  taskArray.push(task2);
  let task3: taskpool.Task = new taskpool.Task(printArgs, i + 200); // 200: test number
  taskArray.push(task3);
}

// 从taskArray中获取不同的任务并给定不同优先级执行
for (let i: number = 0; i < allCount; i++) { // 每次执行3个任务
  taskpool.execute(taskArray[i], taskpool.Priority.HIGH);
  taskpool.execute(taskArray[i + 100], taskpool.Priority.LOW);
  taskpool.execute(taskArray[i + 200], taskpool.Priority.MEDIUM);
}
```

**参考链接**

1. [Priority](../reference/apis-arkts/js-apis-taskpool.md)

## 如何将内存共享的线程模型，转换成在ArkTS的线程模型下（内存隔离）的实现方式？(API 11)

**解决方案**

可以利用TaskPool接口转换，大概可以分为如下五个场景。

场景一：主线程将独立的耗时任务放到子线程执行  
伪代码示例：  
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
伪代码示例：  
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
taskpool.execute(runner, material).then(() => {
  // Return result
})
```

场景三：主线程将独立的耗时任务放到子线程执行  
伪代码示例：

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
taskpool.execute(runner, task).then((ret) => {
  task.result = ret as string;
})
```

场景四：子线程主动更新主线程状态  
伪代码示例：

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
伪代码示例：

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

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
let sdk = SdkU3d.getInst()
workerInstance.registerGlobalCallObject("instance_xx", sdk);
workerInstance.postMessage("start");
// 工作线程
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

1. [可共享对象](../arkts-utils/arkts-sendable.md)

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

function consumer(e: MessageEvents) {
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

1. [@ohos.taskpool（启动任务池）](../reference/apis-arkts/js-apis-taskpool.md)
2. [@ohos.worker (启动一个Worker)](../reference/apis-arkts/js-apis-worker.md)

## ArkTS是否支持共享内存模型进行多线程开发吗？(API 10)

**规格澄清**

无法做到通过加锁的方式实现多个线程同时对同一个内存对象的同时操作。ArkTS是Actor并发模型，线程间内存隔离，当前只支持SharedArrayBuffer或者Native层对象的共享。

**参考链接**

1. [多线程并发概述 (TaskPool和Worker)](../arkts-utils/multi-thread-concurrency-overview.md)

## ArkTS的SendableClass对象内存共享的原理是什么？有什么限制？如何使用？(API 11)

**原理澄清**

SendableClass是基于Actor内存隔离并发模型的扩展，Sendable对象的内存是线程间共享的，但是仍然需要满足单线程无锁化运行。因此，要保证同一个Sendable实例不能多线程并发访问，开发者需要通过同步机制保证线程安全。

**规格澄清**

Sendable对象需要满足一定的规格：
1. 成员属性为Sendable类，或者基础类型（string number boolean等，Array等容器类待扩展后支持）
2. 成员属性必须显式初始化
3. 成员函数不能使用闭包，只能使用入参、this成员或者import导入的变量
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

##  对于多线程操作首选项和数据库是不是线程安全的？(API 10)

**解决方案**

是线程安全的。

##  如果在ArkTS中大部分后台任务（计算、埋点、入库）都使用异步并发的方式，会不会使主线程越来越慢，引起卡顿丢帧问题？(API 10)

**解决方案**

ArkTS层接口的异步如果不涉及I/O操作，则异步任务会在主线程的微任务执行时机触发，仍然占用主线程。推荐使用TaskPool，分发到后台任务池进行。

##  如何简单实现函数的同步调用功能?(API 10)

**解决方案**

当前不支持关键字修饰的同步机制。后续会支持AsyncLock形式的同步机制，支持将需要同步的代码块放到异步代码块中。

##  在ArkTS的主线程中使用await会堵塞主线程吗？（API 10）

比如如下代码在主线程中执行：  
`const response = await reqeust.buildCall().execute<string>();`  
这种写法会导致主线程堵塞吗？

**解决方案**

并不会。await会挂起当前异步任务，等异步任务满足条件后再唤醒执行，主线程可以处理其他任务。

##  当使用C/C++进行开发时，如何实现在子线程中直接调用H系统SDK提供的TS接口，而不是post到主线程上？（API 10）

**解决方案**

当前还不支持。

## 系统使用了ArkTS作为开发语言，那这些代码的在底层的解释运行的环境是自研的还是用的开源的？另外系统也适配了React Native引擎，是不是也是复用的这个运行环境？（API 10）

**解决方案**

1. 系统ArkTS语言运行在自研的方舟编译运行时，运行的是应用包中经过方舟编译工具链编译ArkTS/TS/JS源码后生成的字节码。
2. 系统适配的React Native引擎目前仍是运行JS源码，运行在系统提供的V8引擎。

## ArkTS里的数据类型转换方法有哪些？和TS是一致的吗？（API 10）

**解决方案**

ArkTS支持TS语义的as类型转换，不支持使用<>运算符进行类型转换。当前as类型转换只用在编译时，无法通过as在运行时进行类型转换。
ArkTS支持内置的类型转换函数，例如Number(), String(), Boolean()等。

**参考资料**

1. [从TypeScript到ArkTS的适配规则](../quick-start/typescript-to-arkts-migration-guide.md)

## TaskPool后台I/O任务池，应用能否自行做管控？有无方法开放管理机制？（API 10）

**解决方案**

1. TaskPool后台线程是根据负载及硬件决定的，无法开放管理，只能支持串行队列，任务组等机制进行任务管控。
2. I/O任务池有底层进行调度，无法自行管控。

## 操作系统对TS文件开发后续还支持吗？（API 10）

**问题描述**

基础库实现基于TS实现后续能否兼容？比如TS支持any，以及运行时动态类型转换，但是ets文件不支持。

**解决方案**

操作系统将持续支持标准TS语法，兼容现有TS实现的三方库。

## 是否支持模块的动态加载？如何实现？（API 10）

**解决方案**

当前不支持动态加载设备侧的二进制包；可以使用动态import进行异步加载，达到类似于Class.forName()反射的效果。
实例如下，hap动态import harlibrary，并调用静态成员函数staticAdd()、实例成员函数instanceAdd()，以及全局方法addHarLibrary()  

```ts
// harlibrary的src/main/ets/utils/Calc.ets
export class Calc {
  public constructor() {}
  public static staticAdd(a: number, b: number): number {
    let c = a + b;
    console.log("DynamicImport I'm harLibrary in staticAdd, %d + %d = %d", a, b, c);
    return c;
  }
  public instanceAdd(a: number, b: number): number {
    let c = a + b;
    console.log("DynamicImport I'm harLibrary in instanseAdd, %d + %d = %d", a, b, c);
    return c;
  }
}

export function addHarLibrary(a: number, b: number): number {
  let c = a + b;
  console.log("DynamicImport I'm harLibrary in addHarLibrary, %d + %d = %d", a, b, c);
  return c;
}

// harlibrary的index.ets
export { Calc, addHarLibrary } from './src/main/ets/utils/Calc';

// hap的index.ets
let harLibrary = 'harlibrary';
import(harLibrary).then((ns: ESObject) => {  // 动态import变量是新增特性，入参换成字符串'harlibrary'是现有特性。也可使用await import方式。
  ns.Calc.staticAdd(7, 8);  // 反射调用静态成员函数staticAdd()
  let calc: ESObject = new ns.Calc();  // 实例化类Calc
  calc.instanceAdd(8, 9);  // 调用实例成员函数instanceAdd()
  ns.addHarLibrary(6, 7);  // 调用全局方法addHarLibrary()
});
```

## ArkTS是否可以开发AST数据结构或者接口？(API 11)

**解决方案**

AST属于编译器编译过程中间数据结构，该数据本身不稳定，可能会随着语言或者编译器的演进发生变化，暂无计划开放给开发者。

开发者如果有二进制扫描相关需求，可以参考下方链接。

**参考资料**

1. [基于方舟字节码文件的安全扫描接口](https://gitcode.com/openharmony/arkcompiler_runtime_core/blob/master/libark_defect_scan_aux/README.md)

## 目前系统的多线程内存占用大，每个线程需要一个ArkTS引擎，意味着更多的内存占用。如何解决应用需要避免开辟过多线程，并发处理任务数量受限，无法充分发挥设备性能的问题？

**原理澄清**

当前ArkTS创建线程(worker)会创建一个新的ArkTS引擎实例，会占用额外的内存。

同时，ArkTS提供了TaskPool并发API，类似GCD的线程池能力，可以执行任务，而且不需要开发者进行线程生命周期管理。Task会被调度到有限数量的工作线程执行，多个task会共享这些工作线程（ArkTS引擎实例），系统会根据负载情况扩容/缩容工作线程的数量，充分发挥硬性性能。

**解决方案**

因此针对需要大量线程的问题，应用的开发建议如下:
1. 将多线程任务转变为并发任务，通过TaskPool分发执行。
2. I/O型任务不需要单独开启线程，而是在当前线程（可以是TaskPool线程）执行。
3. 少量需要常驻的CPU密集型任务，采用Worker，并且需要控制在8个及以下。

**参考链接**

1. [TaskPool和Worker的对比 (TaskPool和Worker)](../arkts-utils/taskpool-vs-worker.md)

## taskpool线程中是否可以使用emitter.on等长时间监听接口

不推荐。

**原理澄清**

1. 由于长时间的监听，可能会影响线程回收或复用。
2. 如果线程被回收会导致线程回调失效或者发生不可预期的错误。
3. 如果任务函数多次执行，可能会在不同的线程产生监听，导致结果不符合预期。

**解决方案**

建议使用[长时任务](../reference/apis-arkts/js-apis-taskpool.md#longtask12)。

## taskpool中监听任务的接口onEnqueued、onStartExecution、onExecutionFailed、onExecutionSucceeded是否有调用顺序(API 12)

**解决方案**

上述四个接口可独立使用，无调用的先后顺序。

## 如何在HAR中使用Sendable class

**解决方案**

使用TS HAR，具体内容参考以下文档。

**参考链接**

[编译生成TS文件](../quick-start/har-package.md#编译生成ts文件)

## 使用TS HAR中的UI组件时编译报错 "'UI组件' does not meet UI component syntax"

**解决方案**

依赖TS HAR时，不允许引用其中的UI组件。
需要使用HAR中的UI组件，请使用源码HAR或者JS HAR。

**参考链接**

[HAR开发文档](../quick-start/har-package.md)

## hdc属性开关

1. 默认：hdc shell param set persist.ark.properties 0x105c
2. 关闭多线程检测并打印异常栈帧：hdc shell param set persist.ark.properties -1
3. GC状态打印：hdc shell param set persist.ark.properties 0x105e
4. 多线程检测：hdc shell param set persist.ark.properties 0x107c
5. 同时开启多线程检测并打印异常栈：hdc shell param set persist.ark.properties 0x127c
6. 全局对象内存泄露检查：hdc shell param set persist.ark.properties 0x145c
7. 全局原始值内存泄露检查：hdc shell param set persist.ark.properties 0x185C
8. 打开GC共享堆信息：hdc shell param set persist.ark.properties 0x905c
9. 微任务打点，包含入队及执行过程：hdc shell param set persist.ark.properties 0x8105c
10. 增加ArkProperties控制是否启用旧的socket调试器：hdc shell param set persist.ark.properties 0x10105C
11. 使用 DISABLE 适应测试脚本中现有的 ArkProperties：hdc shell param set persist.ark.properties 0x40105C
12. 模块加载so异常报错信息增强：hdc shell param set persist.ark.properties 0x80105C
13. 模块化打点：hdc shell param set persist.ark.properties 100105C
14. 日志打印执行的模块：hdc shell param set persist.ark.properties 200105C
### CPU Profiler性能数据采集
1. 仅采集主线程冷启动：hdc shell param set persist.ark.properties 0x705c
2. 仅采集worker线程冷启动：hdc shell param set persist.ark.properties 0x1505c
3. 同时采集主线程及worker线程冷启动：hdc shell param set persist.ark.properties 0x1705c
4. 仅采集主线程任意阶段：hdc shell param set persist.ark.properties 0x2505c
5. 仅采集worker线程任意阶段：hdc shell param set persist.ark.properties 0x4505c
6. 同时采集主线程及worker线程任意阶段：hdc shell param set persist.ark.properties 0x6505c

## 当前ArkTS是否采用类Node.js的异步I/O机制

**解决方案**

是的。Node.js使用了事件循环机制来处理异步操作，在Node.js中，异步操作通过回调函数或Promise来处理。ArkTS使用了基于协程的异步I/O机制，I/O事件会分发到I/O线程，不阻塞JS线程，可以通过回调函数或Promise/async/await语法来处理异步操作。

## 对于网络请求这I/O密集型任务是否需要使用多线程进行处理

**解决方案**

根据具体业务场景和实现决定。若I/O操作不频繁，对UI主线程其他业务没有影响，则无需使用多线程。若有频繁I/O请求导致UI主线程分发请求的耗时过长，则需要使用多线程用以提高程序的性能和响应速度，具体需要根据Profiler情况决定。

## 对于@ohos.net.http网络框架是否需要使用TaskPool处理

**解决方案**

根据具体业务场景和实现决定。如果业务的网络请求较少或者后续网络数据的处理耗时不长，则无需使用TaskPool去承担额外的线程开启回收及数据传递耗时。如果业务中需要处理大量的网络请求并且对获取的数据进行二次加工耗时长，可以使用TaskPool进行网络请求及数据处理，降低UI主线程负载。