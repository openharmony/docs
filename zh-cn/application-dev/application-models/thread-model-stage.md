# 线程模型

## 线程类型
Stage模型下的线程主要有如下三类：
- 主线程
  - 执行UI绘制。
  - 管理主线程的ArkTS引擎实例，使多个UIAbility组件能够运行在其之上。
  - 管理其他线程的ArkTS引擎实例，例如使用TaskPool（任务池）创建任务或取消任务、启动和终止Worker线程。
  - 分发交互事件。
  - 处理应用代码的回调，包括事件处理和生命周期管理。
  - 接收TaskPool以及Worker线程发送的消息。
- [TaskPool Worker线程](../reference/apis-arkts/js-apis-taskpool.md)
  - 用于执行耗时操作，支持设置调度优先级、负载均衡等功能，推荐使用。
- [Worker线程](../reference/apis-arkts/js-apis-worker.md)
  - 用于执行耗时操作，支持线程间通信。
TaskPool与Worker的运作机制、通信手段和使用方法可以参考[TaskPool和Worker的对比](../arkts-utils/taskpool-vs-worker.md)。
![thread-model-stage](figures/thread-model-stage.png)

> **说明：**
>
> - TaskPool自行管理线程数量，其生命周期由TaskPool统一管理。[Worker](../arkts-utils/worker-introduction.md)线程的生命周期由开发者自行维护。
> - 同一线程中存在多个组件，例如UIAbility组件和UI组件都存在于主线程中。在Stage模型中目前主要使用[EventHub](#使用eventhub进行线程内通信)进行数据通信。
> - 执行`hdc shell`命令，进入设备的shell命令行。在shell命令行中，执行`ps -p <pid> -T`命令，可以查看指定应用进程的线程信息。其中，`<pid>`为需要指定的应用进程的[进程ID](process-model-stage.md)。



## 使用EventHub进行线程内通信

[EventHub](../reference/apis-ability-kit/js-apis-inner-application-eventHub.md)提供了线程内发送和处理事件的能力，包括对事件订阅、取消订阅、触发事件等。以UIAbility组件与UI之间的数据同步为例，具体使用方法可以参考[UIAbility组件与UI的数据同步](uiability-data-sync-with-ui.md#使用eventhub进行数据通信)。
