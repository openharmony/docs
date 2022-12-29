# 进程模型


OpenHarmony的进程模型如下图所示：


- 应用中（同一包名）的所有PageAbility、ServiceAbility、DataAbility、FormAbility运行在同一个独立进程中，即图中绿色部分的“Main Process”。

- WebView拥有独立的渲染进程，即图中黄色部分的“Render Process”。

  **图1** 进程模型示意图  
![process-model-fa](figures/process-model-fa.png)


基于OpenHarmony的进程模型，应用间存在多个进程的情况，因此系统提供了如下两种进程间通信机制：


- [公共事件机制](common-event-fa.md)：多用于一对多的通信场景，公共事件发布者可能存在多个订阅者同时接收事件。

- [后台服务机制](rpc.md)：当前主要通过[ServiceAbility](serviceability-overview.md)的能力实现。
