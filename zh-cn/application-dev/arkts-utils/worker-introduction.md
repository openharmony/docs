# Worker简介

Worker主要作用是为应用程序提供一个多线程的运行环境，可满足应用程序在执行过程中与主线程分离，在后台线程中运行一个脚本操作耗时操作，极大避免类似于计算密集型或高延迟的任务阻塞主线程的运行。具体接口信息及使用方法详情请见[Worker](../reference/apis/js-apis-worker.md)。


## Worker运作机制

**图1** Worker运作机制示意图

![worker](figures/worker.png)

创建Worker的线程称为宿主线程（不一定是主线程，工作线程也支持创建Worker子线程），Worker自身的线程称为Worker子线程（或Actor线程、工作线程）。每个Worker子线程与宿主线程拥有独立的实例，包含基础设施、对象、代码段等。Worker子线程和宿主线程之间的通信是基于消息传递的，Worker通过序列化机制与宿主线程之间相互通信，完成命令及数据交互。


## Worker注意事项

- 创建Worker时，传入的Worker.ts路径在不同版本有不同的规则，详情请参见[文件路径注意事项](#文件路径注意事项)。

- Worker创建后需要手动管理生命周期，且最多同时运行的Worker子线程数量为8个，详情请参见[生命周期注意事项](#生命周期注意事项)。

- [Ability类型](../quick-start/application-package-structure-stage.md)的Module支持使用Worker，[Library类型](../quick-start/application-package-structure-stage.md)的Module不支持使用Worker。

- 创建Worker不支持使用其他Module的Worker.ts文件，即不支持跨模块调用Worker。

- 由于不同线程中上下文对象是不同的，因此Worker线程只能使用线程安全的库，例如UI相关的非线程安全库不能使用。

- 序列化传输的数据量大小限制为16MB。

- 使用Worker模块时，需要在主线程中注册onerror接口，否则当worker线程出现异常时会发生jscrash问题。


### 文件路径注意事项

  当使用Worker模块具体功能时，均需先构造Worker实例对象，其构造函数与API版本相关。

```ts
// 导入模块
import worker from '@ohos.worker';

// API 9及之后版本使用：
const worker1: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/MyWorker.ts');
// API 8及之前版本使用：
const worker2: worker.Worker = new worker.Worker('entry/ets/workers/MyWorker.ts');
```

构造函数需要传入Worker的路径（scriptURL），Worker文件存放位置默认路径为Worker文件所在目录与pages目录属于同级。

**Stage模型**

构造函数中的scriptURL示例如下：


```ts
// 导入模块
import worker from '@ohos.worker';

// 写法一
// Stage模型-目录同级（entry模块下，workers目录与pages目录同级）
const worker1: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/MyWorker.ts', {name:"first worker in Stage model"});
// Stage模型-目录不同级（entry模块下，workers目录是pages目录的子目录）
const worker2: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/pages/workers/MyWorker.ts');

// 写法二
// Stage模型-目录同级（entry模块下，workers目录与pages目录同级），假设bundlename是com.example.workerdemo
const worker3: worker.ThreadWorker = new worker.ThreadWorker('@bundle:com.example.workerdemo/entry/ets/workers/worker');
// Stage模型-目录不同级（entry模块下，workers目录是pages目录的子目录），假设bundlename是com.example.workerdemo
const worker4: worker.ThreadWorker = new worker.ThreadWorker('@bundle:com.example.workerdemo/entry/ets/pages/workers/worker');
```


- 基于Stage模型工程目录结构，写法一的路径含义：
  - entry：module.json5文件中module的name属性对应值。
  - ets：用于存放ets源码，固定目录。
  - workers/MyWorker.ts：worker源文件在ets目录下的路径。

- 基于Stage模型工程目录结构，写法二的路径含义：
  - \@bundle：固定标签。
  - bundlename：当前应用包名。
  - entryname：module.json5文件中module的name属性对应值。
  - ets：用于存放ets源码，固定目录。
  - workerdir/workerfile：worker源文件在ets目录下的路径，可不带文件后缀名。


**FA模型**


  构造函数中的scriptURL示例如下：

```ts
// 导入模块
import worker from '@ohos.worker';

// FA模型-目录同级（entry模块下，workers目录与pages目录同级）
const worker1: worker.ThreadWorker = new worker.ThreadWorker('workers/worker.js', {name:'first worker in FA model'});
// FA模型-目录不同级（entry模块下，workers目录与pages目录的父目录同级）
const worker2: worker.ThreadWorker = new worker.ThreadWorker('../workers/worker.js');
```


### 生命周期注意事项

- Worker的创建和销毁耗费性能，建议开发者合理管理已创建的Worker并重复使用。Worker空闲时也会一直运行，因此当不需要Worker时，可以调用[terminate()](../reference/apis/js-apis-worker.md#terminate9)接口或[parentPort.close()](../reference/apis/js-apis-worker.md#close9)方法主动销毁Worker。若Worker处于已销毁或正在销毁等非运行状态时，调用其功能接口，会抛出相应的错误。


- Worker存在数量限制，支持最多同时存在8个Worker。
  - 在API version 8及之前的版本，当Worker数量超出限制时，会抛出“Too many workers, the number of workers exceeds the maximum.”错误。
  - 从API version 9开始，当Worker数量超出限制时，会抛出“Worker initialization failure, the number of workers exceeds the maximum.”错误。
