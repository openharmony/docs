# 术语

## A

- ### Ability

    应用的重要组成部分，是应用所具备能力的抽象。Ability是系统调度应用的最小单元，是能够完成一个独立功能的组件，一个应用可以包含一个或多个Ability。 


- ### AMS

    Ability Manager Service，Ability管理服务。
    
- ### ArkCompiler

    方舟编译器，是OpenHarmony内置的组件化、可配置的多语言编译和运行平台，包含编译器、工具链、运行时等关键部件，支持高级语言在多种芯片平台的编译与运行，并支撑OpenHarmony标准操作系统及其应用和服务运行在手机、个人电脑、平板、电视、汽车和智能穿戴等多种设备上的需求。

- ### ArkUI

  方舟开发框架，是一套极简、高性能、跨设备应用设计研发的UI开发框架，支撑开发者高效地构建跨设备应用UI界面。详情可参考[方舟开发框架开发指导](application-dev/ui/arkui-overview.md)。


## B

- ### BMS

    Bundle Manager Service，包管理服务。


## D

- ### DevEco Device Tool

    面向智能设备开发者，提供一站式的开发环境、一站式资源获取通道，实现了从芯片模板工程创建到开发资源挑选定制，再到编码、编译、调试、调优、烧录环节的全流程覆盖，帮助开发者实现智能硬件设备的高效开发。

- ### DMS

    Distributed Management Service，分布式管理服务。


## F

- ### FA

    Feature Ability，是FA模型的Ability框架下具有UI界面的Ability类型，用于与用户进行交互。Feature Ability唯一对应一种模板，即Page模板（Page Ability）。
    
- ### FA模型

    两种Ability框架模型结构的其中一种。是Ability框架在API 8及更早版本采用FA模型。FA模型将Ability分为[FA（Feature Ability）](#fa)和[PA（Particle Ability）](#pa)两种类型，其中FA支持Page Ability模板，PA支持Service ability、Data ability、以及Form ability模板。详情可参考[FA模型综述](application-dev/ability/fa-brief.md)。


## H

- ### HAP

    OpenHarmony Ability Package，一个HAP文件包含应用的所有内容，由代码、资源、三方库及应用配置文件组成，其文件后缀名为.hap。

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

    Particle Ability，是在FA模型的Ability框架下无界面的Ability，主要为Feature Ability提供服务与支持，例如作为后台服务提供计算能力，或作为数据仓库提供数据访问能力。Particle Ability有三种模板，分别为Service模板（Service Ability）、Data模板（Data Ability）、以及Form模板（Form Ability）。


## S

- ### Super virtual device，超级虚拟终端

    亦称超级终端，通过分布式技术将多个终端的能力进行整合，存放在一个虚拟的硬件资源池里，根据业务需要统一管理和调度终端能力，来对外提供服务。

- ### Stage模型

    两种Ability框架模型结构的其中一种。从API 9开始支持。Stage模型将Ability分为Ability和ExtensionAbility两大类，其中ExtensionAbility又被扩展为ServiceExtensionAbility、FormExtensionAbility、DataShareExtensionAbility等等一系列ExtensionAbility。

- ### System Type，系统类型
    - Mini System，轻量系统：面向MCU类处理器，例如ARM Cortex-M、RISC-V 32位的设备，资源极其有限，参考内存≥128KiB，提供丰富的近距连接能力以及丰富的外设总线访问能力。典型产品有智能家居领域的联接类模组、传感器设备等。
    - Small System，小型系统：面向应用处理器，例如Arm Cortex-A的设备，参考内存≥1MiB，提供更高的安全能力，提供标准的图形框架，提供视频编解码的多媒体能力。典型产品有智能家居领域的IPCamera、电子猫眼、路由器以及智慧出行域的行车记录仪等。
    - Standard System，标准系统：面向应用处理器，例如Arm Cortex-A的设备，参考内存≥128MiB，提供增强的交互能力，提供3D GPU以及硬件合成能力，提供更多控件以及动效更丰富的图形能力，提供完整的应用框架。典型产品有高端的冰箱显示屏等。
