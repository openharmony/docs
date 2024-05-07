# 术语

## A

- ### abc文件

    方舟字节码（ArkCompiler Bytecode）文件，是ArkCompiler的编译工具链以源代码作为输入编译生成的产物，其文件后缀名为.abc。在发布态，abc文件会被打包到HAP中。

- ### AppLinking

    AppLinking是基于操作系统基础能力（DeepLink/URL Scheme等技术），为开发者提供的用户增长服务。在目标方本地已安装的场景下，可以直达内容，未安装时，开发者可以定制跳转目标。而且，该服务可以保证跳转的安全性，目标方不会被仿冒。

- ### ArkCompiler

    方舟编译器，是OpenHarmony内置的组件化、可配置的多语言编译和运行平台，包含编译器、工具链、运行时等关键部件，支持高级语言在多种芯片平台的编译与运行，并支撑OpenHarmony标准操作系统及其应用和服务运行在手机、个人电脑、平板、电视、汽车和智能穿戴等多种设备上的需求。

- ### ArkTS

    OpenHarmony生态的应用开发语言。它在TypeScript（简称 TS）的基础上，扩展了声明式UI、状态管理等能力，让开发者可以以更简洁、更自然的方式开发应用。

- ### ArkUI

  OpenHarmony上原生UI框架。是一套极简、高性能、跨设备应用设计研发的UI开发框架，支撑开发者高效地构建跨设备应用UI界面。详情可参考[方舟开发框架开发指导](application-dev/ui/arkui-overview.md)。


## B

- ### BMS

    Bundle Manager Service，包管理服务。

## C

- ### CES

    Common Event Service，OpenHarmony中负责处理公共事件的订阅、发布和退订的系统服务。


## D

- ### DMS

    Distributed Management Service，分布式管理服务。


## E

- ### ExtensionAbility

    Stage模型中的组件类型名，即ExtensionAbility组件，提供特定场景（如卡片、输入法）的扩展能力，满足更多的使用场景。


## F

- ### FA

    Feature Ability，在FA模型中代表有界面的Ability，用于与用户进行交互。
    
- ### FA模型

    API version 8及更早版本支持的应用模型，已经不再主推。建议使用新的Stage模型进行开发。


## H

- ### HAP

    Harmony Ability Package，一个HAP文件包含应用的所有内容，由代码、资源、三方库及应用配置文件组成，其文件后缀名为.hap。


- ### HCS

    HDF Configuration Source是HDF驱动框架的配置描述语言，是为了实现配置代码与驱动代码解耦，以及便于配置的管理而设计的一种Key-Value为主体的文本格式。


- ### HC-GEN

    HDF Configuration Generator是HCS配置转换工具，可以将HDF配置文件转换为软件可读取的文件格式。


- ### HDF

    Hardware Driver Foundation，硬件驱动框架，用于提供统一外设访问能力和驱动开发、管理框架。

- ### Hypium

    Hyper Automation + ium 的组合词，OpenHarmony自动化测试框架名称，以超自动化测试为理想目标，ium意指稳定、可靠的测试框架能力底座。


## I

- ### IDN

    Intelligent Distributed Networking，是OpenHarmony特有的分布式组网能力单元。开发者可以通过IDN获取分布式网络内的设备列表和设备状态信息，以及注册分布式网络内设备的在网状态变化信息。


## P

- ### PA

    Particle Ability，在FA模型中代表无界面的Ability，主要为Feature Ability提供支持，例如作为后台服务提供计算能力，或作为数据仓库提供数据访问能力。


## S

- ### Service widget，服务卡片

    将用户应用程序的重要信息以服务卡片的形式展示在桌面，用户可通过快捷手势使用卡片，以达到服务直达、减少层级跳转的目的。

- ### Stage模型

    API version 9开始新增的应用模型，提供UIAbility、ExtensionAbility两大类应用组件。由于该模型还提供了AbilityStage、WindowStage等类作为应用组件和Window窗口的“舞台”，因此称之为Stage模型。

- ### Super virtual device，超级虚拟终端

    亦称超级终端，通过分布式技术将多个终端的能力进行整合，存放在一个虚拟的硬件资源池里，根据业务需要统一管理和调度终端能力，来对外提供服务。

- ### SysCap

    全称System Capability，即系统能力。不同值用于指代OpenHarmony中各个相对独立的特性/系统能力，如蓝牙、Wi-Fi、NFC等。每个特性/系统能力对应多个API，每个API定义上包含了相应的SysCap标签。

- ### System Type，系统类型
    - Mini System，轻量系统：面向MCU（Microcontroller Unit，微控制单元）类处理器，例如ARM Cortex-M、RISC-V 32位的设备，资源极其有限，参考内存≥128KiB，提供丰富的近距连接能力以及丰富的外设总线访问能力。典型产品有智能家居领域的联接类模组、传感器设备等。
    - Small System，小型系统：面向应用处理器，例如Arm Cortex-A的设备，参考内存≥1MiB，提供更高的安全能力，提供标准的图形框架，提供视频编解码的多媒体能力。典型产品有智能家居领域的IPCamera、电子猫眼、路由器以及智慧出行域的行车记录仪等。
    - Standard System，标准系统：面向应用处理器，例如Arm Cortex-A的设备，参考内存≥128MiB，提供增强的交互能力，提供3D GPU以及硬件合成能力，提供更多控件以及动效更丰富的图形能力，提供完整的应用框架。典型产品有高端的冰箱显示屏等。

## U

- ### UIAbility

    Stage模型中的组件类型名，即UIAbility组件，包含UI，提供展示UI的能力，主要用于和用户交互。
