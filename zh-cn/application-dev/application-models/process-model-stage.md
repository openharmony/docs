# 进程模型


OpenHarmony的进程模型如下图所示：


- 应用中（同一包名）的所有UIAbility、ServiceExtensionAbility、DataShareExtensionAbility运行在同一个独立进程中，即图中绿色部分的“Main Process”。

- 应用中（同一包名）的同一类型ExtensionAbility（除ServiceExtensionAbility和DataShareExtensionAbility外）运行在一个独立进程中，即图中蓝色部分的“FormExtensionAbility Process”、“InputMethodExtensionAbility Process”、其他ExtensionAbility Process。

- WebView拥有独立的渲染进程，即图中黄色部分的“Render Process”。

  **图1** 进程模型示意图  
![process-model](figures/process-model.png)

> 说明：
>
> 仅系统应用支持构建ServiceExtensionAbility和DataShareExtensionAbility。

在上述模型基础上，对于系统应用可以通过申请多进程权限（如下图所示），为指定HAP配置一个自定义进程名，该HAP中的UIAbility、DataShareExtensionAbility、ServiceExtensionAbility就会运行在自定义进程中。不同的HAP可以通过配置不同的进程名运行在不同进程中。

  **图2** 多进程示意图  
![multi-process](figures/multi-process.png)


基于OpenHarmony的进程模型，系统中应用间和应用内都会存在多个进程的情况，因此系统提供了如下两种进程间通信机制：


- [公共事件机制](common-event-overview.md)：多用于一对多的通信场景，公共事件发布者可能存在多个订阅者同时接收事件。

- [后台服务机制](background-services.md)：当前主要通过[ServiceExtensionAbility](serviceextensionability.md)的能力实现。
