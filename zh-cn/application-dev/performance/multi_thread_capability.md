# OpenHarmony多线程能力场景化示例实践

## 简介

在OpenHarmony应用中，每个[进程](../application-models/process-model-stage.md)都会有一个主线程，主线程主要承担执行UI绘制操作、管理ArkTS引擎实例的创建和销毁、分发和处理事件、管理Ability生命周期等职责，具体可参见[线程模型概述](../application-models/thread-model-stage.md)。因此，开发应用时应当尽量避免将耗时的操作放在主线程中执行。ArkTS提供了**Worker**和**TaskPool**两种多线程并发能力，多线程并发允许在同一时间段内同时执行多段代码，这两个并发的基本能力可参见[TaskPool和Worker的对比](../arkts-utils/taskpool-vs-worker.md)。

在介绍**Worker**和**TaskPool**的详细使用方法前，我们先简单介绍并发模型的相关概念，以便于大家的理解。

## 并发模型概述

并发的意思是多个任务同时执行。并发模型分为两大类：基于内存共享的并发模型和基于消息传递的并发模型。

在基于内存共享的并发模型中，并发线程通过读写内存中的共享对象来进行交互。基于共享内存的并发编程需要满足三条性质：

- 原子性：指一个操作是不可中断的，要么全部执行成功要么全部执行失败。

- 有序性：指程序执行的顺序必须符合预期，不能出现乱序的情况。

- 可见性：指当一个线程修改了共享变量后，其他线程能够立即得知这个修改。

现代程序语言一般通过锁、内存屏障、原子指令来满足这三条性质。基于内存共享的并发模型与底层硬件接近，在能正确撰写并发代码的情况下，可以最大发挥底层硬件性能，实现性能优秀的多线程程序。但是这种并发模型难以掌握，即使资深的程序员也非常容易犯错。典型的基于内存共享并发模型的程序语言有C++ 、Swift和Java等。

在基于消息传递的并发模型中，并发线程的内存相互隔离，需要通过通信通道相互发送消息来进行交互。典型的基于消息传递的并发模型一般有两种：CSP和Actor。

CSP（Communicating Sequential Processes，通信顺序进程）中的计算单元并不能直接互相发送信息。需要通过通道（Channel）作为媒介进行消息传递：发送方需要将消息发送到Channel，而接收方需要从Channel读取消息。与CSP不同，在Actor模型中，每个Actor可以看做一个独立的计算单元，并且相互之间内存隔离，每个Actor中存在信箱（Mail Box），Actor之间可以直接进行消息传递，如下图所示：  

**图1**  Actor消息传递示意图  

![Actor消息传递图](figures/actor-message-post.png)

CSP与Actor之间的主要区别：

- Actor需要明确指定消息接收方，而CSP中处理单元不用关心这些，只需要把消息发送给Channel，而接收方只需要从Channel读取消息。

- 由于在默认情况下Channel是没有缓存的，因此对Channel的发送（Send）动作是同步阻塞的，直到另外一个持有该Channel引用的执行块取出消息，而Actor模型中信箱本质是队列，因此消息的发送和接收可以是异步的。

典型的基于消息传递的并发模型的程序语言有：Dart、JS和ArkTS。OpenHarmony中Worker和TaskPool都是基于Actor并发模型实现的并发能力。

## Worker

### 基本概念和运作原理

OpenHarmony中的Worker是一个独立的线程，基本概念可参见[TaskPool和Worker的对比](../arkts-utils/taskpool-vs-worker.md)。Worker拥有独立的运行环境，每个Worker线程和主线程一样拥有自己的内存空间、消息队列（MessageQueue）、事件轮询机制（EventLoop）、调用栈（CallStack）等。线程之间通过消息（Massage）进行交互，如下图所示：  

**图2**  线程交互示意图

![线程交互图](figures/worker-thread-message.png)

在多核的情况下（下图中的CPU 1和CPU 2同时工作），多个Worker线程（下图中的worker thread1和worker thread2）可以同时执行，因此Worker线程做到了真正的并发，如下图所示：  

**图3**  Worker线程并发示意图  

![Worker线程并发图](figures/worker-thread-concurrent.png)

### 使用场景和开发示例

对于Worker，有以下适用场景：

- 运行时间超过3分钟的任务，需要使用Worker。

- 有关联的一系列同步任务，例如数据库增、删、改、查等，要保证同一个句柄，需要使用Worker。

以视频解压的场景为例，点击右上角下载按钮，该示例会执行网络下载并监听，下载完成后自动执行解压操作。当视频过大时，可能会出现解压时长超过3分钟耗时的情况，因此我们选用该场景来说明如何使用Worker。

场景预览图如下所示：  

**图4**  场景预览图

![场景预览图](figures/video-preview.jpg)

使用步骤如下：

1. 宿主线程创建一个Worker线程。通过`new worker.ThreadWorker()`创建Worker实例，示例代码如下：

    ```typescript
    // 引入worker模块
    import worker, { MessageEvents } from '@ohos.worker';
    import type common from '@ohos.app.ability.common';
            
    let workerInstance: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/pages/workers/worker.ts', { 
      name: 'FriendsMoments Worker'
    });
    ```

2. 宿主线程给Worker线程发送任务消息。宿主线程通过postMessage方法来发送消息给Worker线程，启动下载解压任务，示例代码如下：   

    ```typescript
    // 请求网络数据
    let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
    // 参数中mediaData和isImageData是根据开发者自己的业务需求添加的，其中mediaData为数据路径、isImageData为判断图片或视频的标识
    workerInstance.postMessage({ context, mediaData: this.mediaData, isImageData: this.isImageData });
    ```

3. Worker线程监听宿主线程发送的消息。Worker线程在onmessage中接收到宿主线程的postMessage请求，执行下载解压任务，示例代码如下：

    ```typescript
    // 引入worker模块
    import worker, { MessageEvents } from '@ohos.worker';
        
    let workerPort = worker.workerPort;
    // 接收宿主线程的postMessage请求
    workerPort.onmessage = (e: MessageEvents): void => {
      // 下载视频文件
      let context: common.UIAbilityContext = e.data.context;
      let filesDir: string = context.filesDir;
      let time: number = new Date().getTime();
      let inFilePath: string = `${filesDir}/${time.toString()}.zip`;
      let mediaDataUrl: string = e.data.mediaData;
      let urlPart: string = mediaDataUrl.split('.')[1];
      let length: number = urlPart.split('/').length;
      let fileName: string = urlPart.split('/')[length-1];
      let options: zlib.Options = {
        level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION
      };
      request.downloadFile(context, {
        url: mediaDataUrl,
        filePath: inFilePath
      }).then((downloadTask) => {
        downloadTask.on('progress', (receivedSize: number, totalSize: number) => {
          Logger.info(`receivedSize:${receivedSize},totalSize:${totalSize}`);
        });
        downloadTask.on('complete', () => {
          // 下载完成之后执行解压操作
          zlib.decompressFile(inFilePath, filesDir, options, (errData: BusinessError) => {
            if (errData !== null) {
              ...
              // 异常处理
            }
            let videoPath: string = `${filesDir}/${fileName}/${fileName}.mp4`;
            workerPort.postMessage({ 'isComplete': true, 'filePath': videoPath });
          })
        });
        downloadTask.on('fail', () => {
          ...
          // 异常处理
        });
      }).catch((err) => {
        ...
        // 异常处理
      });
    };
    ```

4. 宿主线程监听Worker线程发送的信息。宿主线程通过onmessage接收到Worker线程发送的消息，并执行下载的结果通知。

5. 释放Worker资源。在业务完成或者页面销毁时，调用workerPort.close()接口主动释放Worker资源，示例代码如下所示：

    ```typescript
    workerInstance.onmessage = (e: MessageEvents): void => {
      if (e.data) {
        this.downComplete = e.data['isComplete'];
        this.filePath = e.data['filePath'];
        workerInstance.terminate();
        setTimeout(() => {
          this.downloadStatus = false;
        }, LOADING_DURATION_OPEN);
      }
    };
    ```

## TaskPool

### 基本概念和运作原理

相比使用Worker实现多线程并发，TaskPool更加易于使用，创建开销也少于Worker，并且Worker线程有个数限制，需要开发者自己掌握，TaskPool的基本概念可参见[TaskPool和Worker的对比](../arkts-utils/taskpool-vs-worker.md)。TaskPool作用是为应用程序提供一个多线程的运行环境。TaskPool在Worker之上实现了调度器和Worker线程池，TaskPool根据任务的优先级，将其放入不同的优先级队列，调度器会依据自己实现的调度算法（优先级，防饥饿），从优先级队列中取出任务，放入TaskPool中的Worker线程池，执行相关任务，流程图如下所示：

**图5**  TaskPool流程示意图

![TaskPool流程图](figures/taskpool-process.png)

TaskPool有如下的特点：

- 轻量化的并行机制。

- 降低整体资源的消耗。

- 提高系统的整体性能。

- 无需关心线程实例的生命周期。

- 可以使用TaskPool API创建后台任务（Task），并对所创建的任务进行如任务执行、任务取消的操作。

- 根据任务负载动态调节TaskPool工作线程的数量，以使任务按照预期时间完成任务。

- 可以设置任务的优先级。

- 可以设置任务组（TaskGroup）将任务关联起来。

### 使用场景和开发示例

TaskPool的适用场景主要分为如下三类：

- 需要设置优先级的任务。

- 需要频繁取消的任务。

- 大量或者调度点较分散的任务。

因为朋友圈场景存在不同好友同时上传视频图片，在频繁滑动时将多次触发下载任务，所以下面将以使用朋友圈加载网络数据并且进行解析和数据处理的场景为例，来演示如何使用TaskPool进行大量或调度点较分散的任务开发和处理。场景的预览图如下所示：  

**图6**  朋友圈场景预览图  

![朋友圈场景预览图](figures/friendmoment-preview.jpg)

使用步骤如下：

1. 首先import引入TaskPool模块，TaskPool的API介绍可参见[@ohos.taskpool（启动TaskPool）](../reference/apis/js-apis-taskpool.md)。

    ```typescript
    import taskpool from '@ohos.taskpool';
    ```

2. new一个task对象，其中传入被调用的方法和参数。

    ```typescript
    ... 
    // 创建task任务项，参数1.任务执行需要传入函数 参数2.任务执行传入函数的参数 （本示例中此参数为被调用的网络地址字符串）
    let task: taskpool.Task = new taskpool.Task(getWebData, jsonUrl);
    ...
    
    // 获取网络数据
    @Concurrent
    async function getWebData(url: string): Promise<Array<FriendMoment>> {
      try {
        let webData: http.HttpResponse = await http.createHttp().request(
          url,
          { header: {
              'Content-Type': 'application/json'
          },
            connectTimeout: 60000, readTimeout: 60000
          })
        if (typeof (webData.result) === 'string') {
          // 解析json字符串
          let jsonObj: Array<FriendMoment> = await JSON.parse(webData.result).FriendMoment;
          let friendMomentBuckets: Array<FriendMoment> = new Array<FriendMoment>();
          // 下方源码省略，主要为数据解析和耗时操作处理
          ...
          return friendMomentBuckets;
        } else {
          // 异常处理
          ...
        }
      } catch (err) {
        // 异常处理
        ...
      }
    }
    ```
3. 之后使用taskpool.execute执行TaskPool任务，将待执行的函数放入TaskPool内部任务队列等待执行。execute需要两个参数：创建的任务对象、等待执行的任务组的优先级，默认值是Priority.MEDIUM。在TaskPool中执行完数据下载、解析和处理后，再返回给主线程中。

    ```typescript
    let friendMomentArray: Array<FriendMoment> = await taskpool.execute(task, taskpool.Priority.MEDIUM) as Array<FriendMoment>;
    ```

4. 将新获取的momentData通过AppStorage.setOrCreate传入页面组件中。

    ```typescript
    // 获取页面组件中的momentData对象，其中是组件所需的username、image、video等数据
    let momentData = AppStorage.get<FriendMomentsData>('momentData');
    // 循环遍历对象并依次传入momentData
    for (let i = 0; i < friendMomentArray.length; i++) {
      momentData.pushData(friendMomentArray[i]);
    }
    // 将更新的momentData返回给页面组件
    AppStorage.setOrCreate('momentData', momentData);
    ```

## 其他场景示例和方案思考

在日常开发过程中，我们还会碰到一些其他并发场景问题，下面我们介绍了常用并发场景的示例方案推荐。

### Worker线程调用主线程类型的方法

我们在主线程中创建了一个对象，假如类型为MyMath，我们需要把这个对象传递到Worker线程中，然后在Worker线程中执行该类型中的一些耗时操作方法，比如Math中的compute方法，类结构示例代码如下：

```typescript
class MyMath {
  a: number = 0;
  b: number = 1;

  constructor(a: number, b: number) {
    this.a = a;
    this.b = b;
  }

  compute(): number {
    return this.a + this.b;
  }
}
```

主线程代码：

```typescript
private math: MyMath = new MyMath(2, 3); // 初始化a和b的值为2和3
private workerInstance: worker.ThreadWorker;

this.workerInstance = new worker.ThreadWorker("entry/ets/worker/MyWorker.ts");
this.workerInstance.postMessage(this.math); // 发送到Worker线程中，期望执行MyMath中的compute方法，预期值是2+3=5
```

MyMath对象在进行线程传递后，会丢失类中的方法属性，导致我们只是在Worker线程中可以获取到MyMath的数据，但是无法在子系统中直接调用MyMath的compute方法，示意代码如下：

```typescript
const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
  let a = e.data.a;
  let b = e.data.b;
}
```

这种情况下我们可以怎么去实现在Worker线程中调用主线程中类的方法呢？

首先，我们尝试使用强制转换的方式把Worker线程接收到数据强制转换成MyMath类型，示例代码如下：

```typescript
const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
  let math = e.data as MyMath; // 方法一：强制转换
  console.log('math compute:' + math.compute()); // 执行失败，不会打印此日志
}
```

强制转换后执行方法失败，不会打印此日志。因为序列化传输普通对象时，仅支持传递属性，不支持传递其原型及方法。接下来我们尝试第二种方法，根据数据重新初始化一个MyMath对象，然后执行compute方法，示例代码如下：

```typescript
const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
  // 重新构造原类型的对象
  let math = new MyMath(0, 0);
  math.a = e.data.a;
  math.b = e.data.b;
  console.log('math compute:' + math.compute()); // 成功打印出结果：5
}
```

第二种方法成功在Worker线程中调用了MyMath的compute方法。但是这种方式还有弊端，比如每次使用到这个类进行传递，我们就得重新进行构造初始化，而且构造的代码会分散到工程的各处，很难进行维护，于是我们有了第三种改进方案。

第三种方法，我们需要构造一个接口类，包含了我们需要线程间调用的基础方法，这个接口类主要是管理和约束MyMath类的功能规格，保证MyMath类和它的代理类MyMathProxy类在主线程和子线程的功能一致性，示例代码如下：

```typescript
interface MyMathInterface {
  compute():number;
}
```

然后，我们把MyMath类继承这个方法，并且额外构造一个代理类，继承MyMath类，示例代码如下：

```typescript
class MyMath implements MyMathInterface {
  a: number = 0;
  b: number = 1;

  constructor(a: number, b: number) {
    console.log('MyMath constructor a:' + a + ' b:' + b)
    this.a = a;
    this.b = b;
  }

  compute(): number {
    return this.a + this.b;
  }
}
        
class MyMathProxy implements MyMathInterface {
  private myMath: MyMath;
  constructor(math: MyMath) {
    this.myMath = new MyMath(math.a, math.b);
  }  
  // 代理MyMath类的compute方法
  compute(): number {
    return this.myMath.compute();
  }
}
```

我们在主线程构造并且传递MyMath对象后，在Worker线程中转换成MyMathProxy，即可调用到MyMath的compute方法了，并且无需在多处进行初始化构造，只要把构造逻辑放到MyMathProxy或者MyMath的构造函数中，Worker线程中的示例代码如下：

```typescript
const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
  // 方法三：使用代理类构造对象
  let proxy = new MyMathProxy(e.data)
  console.log('math compute:' + proxy.compute()); // 成功打印出结果：5
}
```

大家可以根据实际场景选择第二种或者第三种方案。

## 相关实例
针对多线程并发，有以下相关实例可供参考：  
* [聊天实例应用（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/IM/Chat)
