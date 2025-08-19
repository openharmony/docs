# 应用程序包术语
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## E

### ExtensionAbility 

Stage模型中的组件类型名，即ExtensionAbility组件，提供特定场景（如卡片、输入法）的扩展能力，满足更多的使用场景。

## F

### FA 

Feature Ability，在FA模型中代表有界面的Ability，用于与用户进行交互。

### FA模型 

API version 8及更早版本支持的应用模型，已经不再主推。建议使用新的Stage模型进行开发。

## H

### HAP 

Harmony Ability Package，一个HAP文件包含应用的所有内容，由代码、资源、三方库及应用配置文件组成，其文件后缀名为.hap。

### HAR 

Harmony Archive，静态共享包，编译态复用。可以包含代码、C++库、资源和配置文件，其文件后缀名为.har，用于实现代码和资源的共享。

### HSP 

Harmony Shared Package，动态共享包，运行时复用。可以包含代码、C++库、资源和配置文件，其文件后缀名为.hsp，用于实现代码和资源的共享。

## M

### Module

模块，应用的一部分，每个模块都有单独的module.json5配置文件。项目工程中，Entry、Feature、HSP和HAR均为应用的一个模块。

## P

### PA

Particle Ability，在FA模型中代表无界面的Ability，主要为Feature Ability提供支持，例如作为后台服务提供计算能力，或作为数据仓库提供数据访问能力。

## S

### Stage模型

API version 9开始新增的应用模型，提供UIAbility、ExtensionAbility两大类应用组件。由于该模型还提供了AbilityStage、WindowStage等类作为应用组件和Window窗口的“舞台”，因此称之为Stage模型。

## U

### UIAbility

Stage模型中的组件类型名，即UIAbility组件，包含UI，提供展示UI的能力，主要用于和用户交互。

<!--Del-->
## X

### 系统级HSP

由OEM厂商预置到系统中的HSP，作为Kit的底层实现，被三方应用间接依赖，运行在三方进程空间。
<!--DelEnd-->
