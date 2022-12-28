# OpenHarmony应用模型解读


## OpenHarmony应用模型概况

随着系统的演进发展，OpenHarmony先后提供了两种应用模型：

- FA（Feature Ability）模型：OpenHarmony API 7开始支持的模型，已经不再主推。

- Stage模型：OpenHarmony API 9开始新增的模型，是目前主推且会长期演进的模型。在该模型中，由于提供了AbilityStage、WindowStage等类作为应用组件和Window窗口的“舞台”，因此称这种应用模型为Stage模型。

Stage模型之所以成为主推模型，源于其设计思想。Stage模型的设计基于如下4个出发点。

1. **为复杂应用而设计**
   - 多个应用组件共享同一个ArkTS引擎（运行ArkTS语言的虚拟机）实例，应用组件之间可以方便的共享对象和状态，同时减少复杂应用运行对内存的占用。
   - 采用面向对象的开发方式，使得复杂应用代码可读性高、易维护性好、可扩展性强。

2. **原生支持应用组件级的[跨端迁移](hop-cross-device-migration.md)和[多端协同](hop-multi-device-collaboration.md)**

   Stage模型实现了应用组件与UI解耦：

   - 在跨端迁移场景下，系统在多设备的应用组件之间迁移数据/状态后，UI便可利用ArkUI的声明式特点，通过应用组件中保存的数据/状态恢复用户界面，便捷实现跨端迁移。

   - 在多端协同场景下，应用组件具备组件间通信的RPC调用能力，天然支持跨设备应用组件的交互。

3. **支持多设备和多窗口形态**

   应用组件管理和窗口管理在架构层面解耦：

   - 便于系统对应用组件进行裁剪（无屏设备可裁剪窗口）。

   - 便于系统扩展窗口形态。

   - 在多设备（如桌面设备和移动设备）上，应用组件可使用同一套生命周期。

4. **平衡应用能力和系统管控成本**

   Stage模型重新定义应用能力的边界，平衡应用能力和系统管控成本。

   - 提供特定场景（如卡片、输入法）的应用组件，以便满足更多的使用场景。
   - 规范化后台进程管理：为保障用户体验，Stage模型对后台应用进程进行了有序治理，应用程序不能随意驻留在后台，同时应用后台行为受到严格管理，防止恶意应用行为。


## 通过对比认识FA模型与Stage模型

**Stage模型与FA模型最大的区别在于**：Stage模型中，多个应用组件共享同一个ArkTS引擎实例；而FA模型中，每个应用组件独享一个ArkTS引擎实例。因此在Stage模型中，应用组件之间可以方便的共享对象和状态，同时减少复杂应用运行对内存的占用。Stage模型作为主推的应用模型，开发者通过它能够更加便利地开发出分布式场景下的复杂应用。

可通过如下对比表格了解两种模型的整体概况。

  **表1** FA模型与Stage模型差异概览

| 项目 | FA模型 | Stage模型 |
| -------- | -------- | -------- |
| **应用组件** | 1.&nbsp;组件分类<br/>&nbsp;&nbsp;&nbsp;-&nbsp;PageAbility组件：包含UI界面，提供展示UI的能力。详细介绍请参见[PageAbility组件概述](pageability-overview.md)。<br/>&nbsp;&nbsp;&nbsp;-&nbsp;ServiceAbility组件：提供后台服务的能力，无UI界面。详细介绍请参见[ServiceAbility组件概述](serviceability-overview.md)。<br/>&nbsp;&nbsp;&nbsp;-&nbsp;DataAbility组件：提供数据分享的能力，无UI界面。详细介绍请参见[DataAbility组件概述](dataability-overview.md)。<br/>2.&nbsp;开发方式<br/>&nbsp;&nbsp;&nbsp;通过导出匿名对象、固定入口文件的方式指定应用组件。开发者无法进行派生，不利于扩展能力。 | 1.&nbsp;组件分类<br/>&nbsp;&nbsp;&nbsp;-&nbsp;UIAbility组件：包含UI界面，提供展示UI的能力，主要用于和用户交互。详细介绍请参见[UIAbility组件概述](uiability-overview.md)。<br/>&nbsp;&nbsp;&nbsp;-&nbsp;ExtensionAbility组件：提供特定场景（如卡片、输入法）的扩展能力，满足更多的使用场景。详细介绍请参见[ExtensionAbility组件概述](extensionability-overview.md)。<br/>2.&nbsp;开发方式<br/>&nbsp;&nbsp;&nbsp;采用面向对象的方式，将应用组件以类接口的形式开放给开发者，可以进行派生，利于扩展能力。 |
| **进程模型** | 有两类进程：<br/>1.&nbsp;主进程<br/>2.&nbsp;渲染进程<br/>详细介绍请参见[进程模型](process-model-fa.md)。 | 有三类进程：<br/>1.&nbsp;主进程<br/>2.&nbsp;ExtensionAbility进程<br/>3.&nbsp;渲染进程<br/>详细介绍请参见[进程模型](process-model-stage.md)。 |
| **线程模型** | 1.&nbsp;ArkTS引擎实例的创建<br/>&nbsp;&nbsp;&nbsp;一个进程可以运行多个应用组件实例，每个应用组件实例运行在一个单独的ArkTS引擎实例中。<br/>2.&nbsp;线程模型<br/>&nbsp;&nbsp;&nbsp;每个ArkTS引擎实例都在一个单独线程（非主线程）上创建，主线程没有ArkTS引擎实例。<br/>3.&nbsp;进程内对象共享：不支持。<br/>详细介绍请参见[线程模型](thread-model-fa.md)。 | 1.&nbsp;ArkTS引擎实例的创建<br/>&nbsp;&nbsp;&nbsp;一个进程可以运行多个应用组件实例，所有应用组件实例共享一个ArkTS引擎实例。<br/>2.&nbsp;线程模型<br/>&nbsp;&nbsp;&nbsp;ArkTS引擎实例在主线程上创建。<br/>3.&nbsp;进程内对象共享：支持。<br/>详细介绍请参见[线程模型](thread-model-stage.md)。 |
| **任务管理模型** | -&nbsp;每个PageAbility组件实例创建一个任务。<br/>-&nbsp;任务会持久化存储，直到超过最大任务个数（根据产品配置自定义）或者用户主动删除任务。<br/>-&nbsp;PageAbility组件之间不会形成栈的结构。<br/>详细介绍请参见[任务管理场景介绍](mission-management-overview.md)。 | -&nbsp;每个UIAbility组件实例创建一个任务。<br/>-&nbsp;任务会持久化存储，直到超过最大任务个数（根据产品配置自定义）或者用户主动删除任务。<br/>-&nbsp;UIAbility组件之间不会形成栈的结构。<br/>详细介绍请参见[任务管理场景介绍](mission-management-overview.md)。 |
| **应用配置文件** | 使用config.json描述应用信息、HAP信息和应用组件信息。<br/>详细介绍请参见[应用配置文件概述（FA模型）](../quick-start/application-configuration-file-overview-fa.md)。 | 使用app.json5描述应用信息，module.json5描述HAP信息、应用组件信息。<br/>详细介绍请参见[应用配置文件概述（Stage模型）](../quick-start/application-configuration-file-overview-stage.md)。 |
