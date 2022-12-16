# 线程模型

OpenHarmony应用中每个进程都会有一个主线程，主线程有如下职责：

1. 负责管理其他线程

2. 同应用多个UIAbility组件共用一个主线程

3. 输入事件分发

4. UI绘制

5. 应用代码回调（事件处理，生命周期）

6. 接收Worker发送的消息

除主线程外，还有一类与主线程并行的独立线程Worker，主要用于执行耗时操作，但不可以直接操作UI。Worker线程在主线程中创建，与主线程相互独立。最多可以创建7个Worker：

![thread-model-stage](figures/thread-model-stage.png)

基于OpenHarmony的线程模型，不同的业务功能运行在不同的线程上，业务功能的交互就需要线程间通信。线程间通信目前主要有Emitter和Worker两种方式，其中Emitter主要适用于线程间的事件同步， Worker主要用于新开一个线程执行耗时任务。

**说明：**

  * Stage模型只提供了主线程和Worker线程，Emitter主要用于主线程内或者主线程和Worker线程的事件同步。