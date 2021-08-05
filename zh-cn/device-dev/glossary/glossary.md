# 术语<a name="ZH-CN_TOPIC_0000001050749051"></a>

-   [A](#section1679023922312)
-   [B](#section62182102017)
-   [D](#section1670294920236)
-   [F](#section5406185415236)
-   [H](#section891816813243)
-   [I](#section10124052142516)
-   [P](#section779354121411)
-   [S](#section25661636182615)

## A<a name="section1679023922312"></a>

-   **Ability**

    应用的重要组成部分，是应用所具备能力的抽象。Ability分为两种类型，Feature Ability和Particle Ability。


-   **AbilitySlice**

    切片，是单个可视化界面及其交互逻辑的总和，是Feature Ability的组成单元。一个Feature Ability可以包含一组业务关系密切的可视化界面，每一个可视化界面对应一个AbilitySlice。

-   **AMS**

    Ability Manager Service，Ability管理服务。


## B<a name="section62182102017"></a>

-   **BMS**

    Bundle Manager Service，包管理服务。


## D<a name="section1670294920236"></a>

-   **DevEco Studio for Embedded**

    嵌入式设备开发IDE。

-   **DMS**

    Distributed Management Service，分布式管理服务。


## F<a name="section5406185415236"></a>

-   **FA**

    Feature Ability，代表有界面的Ability，用于与用户进行交互。


## H<a name="section891816813243"></a>

-   **HAP**

    OpenHarmony Ability Package，一个HAP文件包含应用的所有内容，由代码、资源、三方库及应用配置文件组成，其文件后缀名为.hap。

-   **HCS**

    HDF Configuration Source是HDF驱动框架的配置描述语言，是为了实现配置代码与驱动代码解耦，以及便于配置的管理而设计的一种Key-Value为主体的文本格式。


-   **HC-GEN**

    HDF Configuration Generator是HCS配置转换工具，可以将HDF配置文件转换为软件可读取的文件格式。


-   **HDF**

    Hardware Driver Foundation，硬件驱动框架，用于提供统一外设访问能力和驱动开发、管理框架。


## I<a name="section10124052142516"></a>

-   **IDN**

    Intelligent Distributed Networking，是OpenHarmony特有的分布式组网能力单元。开发者可以通过IDN获取分布式网络内的设备列表和设备状态信息，以及注册分布式网络内设备的在网状态变化信息。


## P<a name="section779354121411"></a>

-   **PA**

    Particle Ability，代表无界面的Ability，主要为Feature Ability提供支持，例如作为后台服务提供计算能力，或作为数据仓库提供数据访问能力。


## S<a name="section25661636182615"></a>

-   **Super virtual device，超级虚拟终端**

    亦称超级终端，通过分布式技术将多个终端的能力进行整合，存放在一个虚拟的硬件资源池里，根据业务需要统一管理和调度终端能力，来对外提供服务。

-   **System Type，系统类型**
    -   Mini System，轻量系统：面向MCU类处理器，例如ARM Cortex-M、RISC-V 32位的设备，资源极其有限，参考内存≥128KiB，提供丰富的近距连接能力以及丰富的外设总线访问能力。典型产品有智能家居领域的联接类模组、传感器设备等。
    -   Small System，小型系统：面向应用处理器，例如Arm Cortex-A的设备，参考内存≥1MiB，提供更高的安全能力，提供标准的图形框架，提供视频编解码的多媒体能力。典型产品有智能家居领域的IPCamera、电子猫眼、路由器以及智慧出行域的行车记录仪等。
    -   Standard System，标准系统：面向应用处理器，例如Arm Cortex-A的设备，参考内存≥128MiB，提供增强的交互能力，提供3D GPU以及硬件合成能力，提供更多控件以及动效更丰富的图形能力，提供完整的应用框架。典型产品有高端的冰箱显示屏等。


