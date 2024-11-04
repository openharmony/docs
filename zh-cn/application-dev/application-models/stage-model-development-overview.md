# Stage模型开发概述


## 基本概念

下图展示了Stage模型中的基本概念。

**图1** Stage模型概念图  
![stage-concepts](figures/stage-concepts.png)


- [AbilityStage](abilitystage.md)

  每个Entry类型或者Feature类型的[HAP](../quick-start/hap-package.md)在运行期都有一个AbilityStage类实例，当[HAP](../quick-start/hap-package.md)中的代码首次被加载到进程中的时候，系统会先创建AbilityStage实例。
  
- [UIAbility组件](uiability-overview.md)和[ExtensionAbility组件](extensionability-overview.md)
  
  Stage模型提供UIAbility和ExtensionAbility两种类型的组件，这两种组件都有具体的类承载，支持面向对象的开发方式。
  
  - UIAbility组件是一种包含UI的应用组件，主要用于和用户交互。例如，图库类应用可以在UIAbility组件中展示图片瀑布流，在用户选择某个图片后，在新的页面中展示图片的详细内容。同时用户可以通过返回键返回到瀑布流页面。UIAbility组件的生命周期只包含创建/销毁/前台/后台等状态，与显示相关的状态通过WindowStage的事件暴露给开发者。
  
  - ExtensionAbility组件是一种面向特定场景的应用组件。开发者并不直接从ExtensionAbility组件派生，而是需要使用ExtensionAbility组件的派生类。目前ExtensionAbility组件有用于卡片场景的FormExtensionAbility，用于输入法场景的InputMethodExtensionAbility，用于闲时任务场景的WorkSchedulerExtensionAbility等多种派生类，这些派生类都是基于特定场景提供的。例如，用户在桌面创建应用的卡片，需要应用开发者从FormExtensionAbility派生，实现其中的回调函数，并在配置文件中配置该能力。ExtensionAbility组件的派生类实例由用户触发创建，并由系统管理生命周期。在Stage模型上，三方应用开发者不能开发自定义服务，而需要根据自身的业务场景通过ExtensionAbility组件的派生类来实现。
- [WindowStage](../windowmanager/application-window-stage.md)

  每个UIAbility实例都会与一个WindowStage类实例绑定，该类起到了应用进程内窗口管理器的作用。它包含一个主窗口。也就是说UIAbility实例通过WindowStage持有了一个主窗口，该主窗口为ArkUI提供了绘制区域。

- [Context](application-context-stage.md)

  在Stage模型上，Context及其派生类向开发者提供在运行期可以调用的各种资源和能力。UIAbility组件和各种ExtensionAbility组件的派生类都有各自不同的Context类，他们都继承自基类Context，但是各自又根据所属组件，提供不同的能力。




## 开发流程

基于Stage模型开发应用时，在应用模型部分，涉及如下开发过程。

**表1** Stage模型开发流程

| 任务 | 简介 | 相关指导 |
| -------- | -------- | -------- |
| 应用组件开发 | 本章节介绍了如何使用Stage模型的UIAbility组件和ExtensionAbility组件开发应用。 | -&nbsp;[应用/组件级配置](application-component-configuration-stage.md)<br/>-&nbsp;[UIAbility组件](uiability-overview.md)<br/>-&nbsp;[ExtensionAbility组件](extensionability-overview.md)<br/>-&nbsp;[AbilityStage组件容器](abilitystage.md)<br/>-&nbsp;[应用上下文Context](application-context-stage.md)<br/>-&nbsp;[组件启动规则](component-startup-rules.md) |
| 了解进程模型 | 本章节介绍了Stage模型的进程模型以及几种常用的进程间通信方式。 | [进程模型概述](process-model-stage.md)|
| 了解线程模型 | 本章节介绍了Stage模型的线程模型以及几种常用的线程间通信方式。 | [线程模型概述](thread-model-stage.md) |
| 应用配置文件 | 本章节介绍Stage模型中应用配置文件的开发要求。 | [Stage模型应用配置文件](config-file-stage.md) |

## 相关实例

针对Stage模型开发，有以下相关实例可供参考：

- [Stage模型（ArkTS）（Full SDK）(API10)](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.1-Release/code/SystemFeature/ApplicationModels/StageModel)