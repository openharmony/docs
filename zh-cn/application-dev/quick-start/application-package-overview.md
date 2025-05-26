# 应用程序包概述


在基于[Stage模型](application-configuration-file-overview-stage.md)开发应用之前，开发者需要了解应用的设计机制、应用程序包结构等基础知识。

## 应用与应用程序包

用户应用程序是指运行在设备操作系统之上，为用户提供特定服务的程序，简称“应用”。一个应用所对应的软件包文件，称为“应用程序包”。

系统提供了应用程序包开发、安装、查询、更新、卸载的管理机制，便于开发者开发和管理应用。此外，系统还屏蔽了不同的芯片平台的差异（包括x86/ARM，32位/64位等），保证应用程序包在不同的芯片平台都能够安装运行，使得开发者可以聚焦于应用的功能实现。

## 应用的多Module设计机制

- **支持模块化开发：** 一个应用通常包含多种功能，将不同的功能特性按模块来划分和管理是一种良好的设计方式。在开发过程中，开发者可以将每个功能模块作为一个独立的Module进行开发，Module中可以包含源代码、资源文件、第三方库、配置文件等，每一个Module可以独立编译，实现特定的功能。这种模块化、松耦合的应用管理方式有利于应用的开发、维护与扩展。

- **支持多设备适配：** 一个应用往往需要适配多种设备类型，在采用多Module设计的应用中，每个Module都会标注所支持的设备类型。Module支持的设备类型不同，有的支持全部类型，有的仅支持特定类型（例如平板）。在应用市场分发应用包时，可以根据设备类型进行精准筛选和匹配，从而合理组合和部署不同的包到对应的设备上。


## Module类型

Module按照使用场景可以分为两种类型：

- **Ability类型的Module：** 用于实现应用的功能和特性。每一个Ability类型的Module编译后，会生成一个以.hap为后缀的文件，称为HAP（Harmony Ability Package）包。HAP包可以独立安装和运行，是应用安装的基本单位，一个应用可以包含一个或多个HAP包，包含的HAP包分为以下两种类型。
  - entry类型的Module：应用的主模块，包含应用的入口界面、入口图标和主功能特性，编译后生成entry类型的HAP。每一个应用分发到同一类型的设备上的应用程序包，只能包含唯一一个entry类型的HAP，也可以不包含。
  - feature类型的Module：应用的动态特性模块，编译后生成feature类型的HAP。一个应用中可以包含一个或多个feature类型的HAP，也可以不包含。

- **Library类型的Module：** 用于实现代码和资源的共享。同一个Library类型的Module可以被其他的Module多次引用，合理地使用该类型的Module，能够降低开发和维护成本。Library类型的Module分为Static和Shared两种类型，编译后生成共享包。
  - Static Library：静态共享库。编译后生成一个以.har为后缀的文件，即静态共享包HAR（Harmony Archive）。
  - Shared Library：动态共享库。编译后生成一个以.hsp为后缀的文件，即动态共享包HSP（Harmony Shared Package）。
  
  > **说明：**
  > 
  > 实际上，Shared Library编译后除了会生成一个.hsp文件，还会生成一个.har文件。这个.har文件中包含了HSP对外导出的接口，应用中的其他模块需要通过.har文件来引用HSP的功能。为了表述方便，通常认为编译Shared Library后会生成HSP。
  
  HAR与HSP两种共享包的主要区别体现在：
  | 共享包类型 | 编译和运行方式  | 发布和引用方式 | 
  | --------  | ---- | --- |
  | HAR | HAR中的代码和资源跟随使用方编译，如果有多个使用方，它们的编译产物中会存在多份相同拷贝。<br/>注意：[编译HAR](har-package.md#编译)时，建议开启混淆能力，保护代码资产。 | HAR除了支持应用内引用，还可以独立打包发布，供其他应用引用。 | 
  | HSP  | HSP中的代码和资源可以独立编译，运行时在一个进程中代码也只会存在一份。 | HSP一般随应用进行打包，当前支持应用内和[集成态HSP](integrated-hsp.md)。应用内HSP只支持应用内引用，集成态HSP支持发布到ohpm私仓和跨应用引用。 |  

 
  **图1** HAR和HSP在APP包中的形态示意图
  ![in-app-hsp-har](figures/in-app-hsp-har.png)

## 选择合适的包类型

HAP、HAR、HSP三者的功能和使用场景总结对比如下：

| Module类型 | 包类型 | 说明 |
| -------- | -------- | -------- |
| Ability | [HAP](hap-package.md)| 应用的功能模块，可以独立安装和运行，必须包含一个entry类型的HAP，可选包含一个或多个feature类型的HAP。|
| Static Library | [HAR](har-package.md) | 静态共享包，编译态复用。<br/> - 支持应用内共享，也可以发布后供其他应用使用。<br/> &ensp; - 作为二方库，发布到[OHPM私仓](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-ohpm-repo)，供公司内部其他应用使用。<br/> &ensp; - 作为三方库，发布到[OHPM中心仓](https://ohpm.openharmony.cn/)，供其他应用使用。<br/> - 多包（HAP/HSP）同时引用相同的HAR时，会造成多包间代码和资源的重复拷贝，从而导致应用包增大。<br/> - 注意：[编译HAR](har-package.md#编译)时，建议开启混淆能力，保护代码资产。 |
| Shared Library | [HSP](in-app-hsp.md)| 动态共享包，运行时复用。<br/> - 当多包（HAP/HSP）同时引用同一个共享包时，使用HSP替代HAR，可以避免HAR造成的多包间代码和资源的重复拷贝，从而减小应用包大小。 |

HAP、HSP、HAR支持的规格对比如下，其中“√”表示是，“×”表示否。

开发者可以根据具体的应用需求，选择相应类型的包进行开发。在后续的章节中还会针对如何使用[HAP](hap-package.md)、[HAR](har-package.md)、[HSP](in-app-hsp.md)分别展开详细介绍。

| 规格| HAP | HAR | HSP |
| -------- | ---------- |----------- |----------- |
| 支持在配置文件中声明[UIAbility](../application-models/uiability-overview.md)组件|  √  |  √   |  √   |
| 支持在配置文件中声明[ExtensionAbility](../application-models/extensionability-overview.md)组件  | √ | × | √ |
| 支持在配置文件中声明[pages](./module-configuration-file.md#pages标签)页面| √  |× |√ |
| 支持包含资源文件与.so文件 | √  |√ |√|
| 支持依赖其他HAR文件 | √ |√  |√  |
| 支持依赖其他HSP文件 | √ |√  |√  |
| 支持在设备上独立安装运行 | √ |× |× |

> **说明：**
>
> - 如果HAR支持声明pages页面，那么当HAR被打包到HAP或HSP中时，其内部声明的pages页面可能会与HAP/HSP中的pages页面存在相对路径上的重复，这将导致无法根据相对路径识别特定的路由页面。因此，HAR不支持在配置文件中声明pages页面，但可以包含pages页面，并通过[Navigation跳转](../ui/arkts-navigation-navigation.md#路由操作)的方式进行跳转。
> - 由于HSP仅支持应用内共享，如果HAR依赖了HSP，则该HAR文件仅支持应用内共享，不支持发布到二方仓或三方仓供其他应用使用，否则会导致编译失败。
> - HAR和HSP均不支持循环依赖，也不支持依赖传递，详情说明可以参考[HAR](har-package.md#约束限制)或者[HSP](in-app-hsp.md#约束限制)中约束限制说明。

