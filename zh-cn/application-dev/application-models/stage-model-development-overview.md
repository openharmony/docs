# Stage模型开发概述


## 基本概念

下图展示了Stage模型中的基本概念。

  **图1** Stage模型概念图  
![stage-concepts](figures/stage-concepts.png)

- [UIAbility组件](uiability-overview.md)和[ExtensionAbility组件](extensionability-overview.md)
  
  Stage模型提供UIAbility和ExtensionAbility两种类型的组件，这两种组件都有具体的类承载，支持面向对象的开发方式。他们是Ability抽象概念在Stage模型上的具体实现。他们是Ability管理服务调度的单元，其生命周期都是由Ability管理服务进行调度的。
  
  - UIAbility组件是一种包含UI界面的应用组件，主要用于和用户交互。例如，图库类应用可以在UIAbility组件中展示图片瀑布流，在用户选择某个图片后，在新的页面中展示图片的详细内容。同时用户可以通过返回键返回到瀑布流页面。UIAbility的生命周期只包含创建/销毁/前台/后台等状态，与显示相关的状态通过WindowStage的事件暴露给开发者。
  
  - ExtensionAbility组件是一种面向特定场景的应用组件。开发者并不直接从ExtensionAbility派生，而是需要使用ExtensionAbility的派生类。目前ExtensionAbility有用于卡片场景的FormExtensionAbility，用于输入法场景的InputMethodExtensionAbility，用于闲时任务场景的WorkSchedulerExtensionAbility等多种派生类，这些派生类都是基于特定场景提供的。例如，用户在桌面创建应用的卡片，需要应用开发者从FormExtensionAbility派生，实现其中的回调函数，并在配置文件中配置该能力。ExtensionAbility派生类实例由用户触发创建，并由系统管理生命周期。在Stage模型上，普通应用开发者不能开发自定义服务，而需要根据自身的业务场景通过ExtensionAbility的派生类来实现。
- [WindowStage](../windowmanager/application-window-stage.md)

  每个UIAbility类实例都会与一个WindowStage类实例绑定，该类提供了应用进程内窗口管理器的作用。它包含一个主窗口。也就是说UIAbility通过WindowStage持有了一个窗口，该窗口为ArkUI提供了绘制区域。

- [Context](application-context-stage.md)

  在Stage模型上，Context及其派生类向开发者提供在运行期可以调用的各种能力。UIAbility组件和各种ExtensionAbility派生类都有各自不同的Context类，他们都继承自基类Context，但是各自又根据所属组件，提供不同的能力。

- [AbilityStage](abilitystage.md)

  每个Entry类型或者Feature类型的HAP在运行期都有一个AbilityStage类实例，当HAP中的代码首次被加载到进程中的时候，系统会先创建AbilityStage实例。每个在该HAP中定义的UIAbility类，在实例化后都会与该实例产生关联。开发者可以使用AbilityStage获取该HAP中UIAbility实例的运行时信息。


## 开发流程

基于Stage模型开发应用时，在应用模型部分，涉及如下开发过程。

  **表1** Stage模型开发流程

| 任务 | 简介 | 相关指导 |
| -------- | -------- | -------- |
| 应用组件开发 | 本章节介绍了如何使用Stage模型的UIAbility组件和ExtensionAbility组件开发应用。 | -&nbsp;[应用/组件级配置](application-component-configuration-stage.md)<br/>-&nbsp;[UIAbility组件](uiability-overview.md)<br/>-&nbsp;[ExtensionAbility组件](extensionability-overview.md)<br/>-&nbsp;[AbilityStage组件容器](abilitystage.md)<br/>-&nbsp;[应用上下文Context](application-context-stage.md)<br/>-&nbsp;[组件启动规则](component-startup-rules.md) |
| 应用配置文件 | 本章节介绍了Stage模型的配置文件中所有的字段以及各个字段的说明。 | -&nbsp;[app.json5配置文件](../quick-start/app-configuration-file.md)<br/>-&nbsp;[module.json5配置文件](../quick-start/module-configuration-file.md) |
| 进程间通信 | 本章节介绍了Stage模型的进程模型以及几种常用的进程间通信方式。 | -&nbsp;[公共事件](common-event-overview.md)<br/>-&nbsp;[后台服务](background-services.md) |
| 线程间通信 | 本章节介绍了Stage模型的线程模型以及几种常用的线程间通信方式。 | -&nbsp;[Emitter](itc-with-emitter.md)<br/>-&nbsp;[Worker](itc-with-worker.md) |
| 任务管理 | 本章节介绍了Stage模型中任务管理的基本概念和典型场景。 | -&nbsp;[任务管理场景介绍](mission-management-overview.md)<br/>-&nbsp;[任务管理与启动模式](mission-management-launch-type.md)<br/>-&nbsp;[页面栈和任务链](page-mission-stack.md) |
