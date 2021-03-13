# OpenHarmony开源项目<a name="ZH-CN_TOPIC_0000001064024128"></a>

## 项目介绍<a name="section1270210396435"></a>

OpenHarmony是开放原子开源基金会（OpenAtom Foundation）旗下开源项目，定位是一款面向全场景的开源分布式操作系统。

OpenHarmony在传统的单设备系统能力的基础上，创造性地提出了基于同一套系统能力、适配多种终端形态的理念，支持多种终端设备上运行，第一个版本支持128K\~128M设备上运行，欢迎参加开源社区一起持续演进。针对设备开发者，OpenHarmony采用了组件化的设计方案，可以根据设备的资源能力和业务特征进行灵活裁剪，满足不同形态的终端设备对于操作系统的要求。可运行在百K级别的资源受限设备和穿戴类设备，也可运行在百M级别的智能家用摄像头/行车记录仪等相对资源丰富的设备。

## 技术架构<a name="section2502124574318"></a>

OpenHarmony整体遵从分层设计，从下向上依次为：内核层、系统服务层、框架层和应用层。系统功能按照“系统 \> 子系统 \> 功能/模块”逐级展开，在多设备部署场景下，支持根据实际需求裁剪某些非必要的子系统或功能/模块。OpenHarmony技术架构如下所示。

![](zh-cn/readme/figures/1.png)

**内核层**

-   内核子系统：采用多内核（Linux内核或者LiteOS）设计，支持针对不同资源受限设备选用适合的OS内核。内核抽象层（KAL，Kernel Abstract Layer）通过屏蔽多内核差异，对上层提供基础的内核能力，包括进程/线程管理、内存管理、文件系统、网络管理和外设管理等。

-   驱动子系统：驱动框架（HDF）是系统硬件生态开放的基础，提供统一外设访问能力和驱动开发、管理框架。


**系统服务层**

系统服务层是OpenHarmony的核心能力集合，通过框架层对应用程序提供服务。该层包含以下几个部分：

-   系统基本能力子系统集：为分布式应用在多设备上的运行、调度、迁移等操作提供了基础能力，由分布式软总线、分布式数据管理、分布式任务调度、公共基础库、多模输入、图形、安全、AI等子系统组成。

-   基础软件服务子系统集：提供公共的、通用的软件服务，由事件通知、电话、多媒体、DFX（Design For X） 等子系统组成。

-   增强软件服务子系统集：提供针对不同设备的、差异化的能力增强型软件服务，由智慧屏专有业务、穿戴专有业务、IoT专有业务等子系统组成。

-   硬件服务子系统集：提供硬件服务，由位置服务、生物特征识别、穿戴专有硬件服务、IoT专有硬件服务等子系统组成。


根据不同设备形态的部署环境，基础软件服务子系统集、增强软件服务子系统集、硬件服务子系统集内部可以按子系统粒度裁剪，每个子系统内部又可以按功能粒度裁剪。

**框架层**

框架层为应用开发提供了Java/C/C++/JS等多语言的用户程序框架和Ability框架，两种UI框架（包括适用于Java语言的Java UI框架、适用于JS语言的JS UI框架），以及各种软硬件服务对外开放的多语言框架API。根据系统的组件化裁剪程度，设备支持的API也会有所不同。

**应用层**

应用层包括系统应用和第三方非系统应用。应用由一个或多个FA（Feature Ability）或PA（Particle Ability）组成。其中，FA有UI界面，提供与用户交互的能力；而PA无UI界面，提供后台运行任务的能力以及统一的数据访问抽象。基于FA/PA开发的应用，能够实现特定的业务功能，支持跨设备调度与分发，为用户提供一致、高效的应用体验。

## 特点<a name="section12212842173518"></a>

1.  硬件互助，资源共享

    主要通过下列模块达成

    -   分布式软总线

        分布式软总线是多设备终端的统一基座，为“[1+8+N](zh-cn_topic_0000000000029587.md#li7594174334311)”设备的无缝互联提供了统一的分布式通信能力，能够快速发现并连接设备，高效地传输任务和数据。


    -   分布式数据管理
    
        分布式数据管理位于基于分布式软总线之上的能力，实现了应用程序数据和用户数据的分布式管理。用户数据不再与单一物理设备绑定，业务逻辑与数据存储分离，应用跨设备运行时数据无缝衔接，为打造一致、流畅的用户体验创造了基础条件


    -   分布式任务调度
    
        分布式任务调度基于分布式软总线、分布式数据管理、分布式Profile等技术特性，构建统一的分布式服务管理（发现、同步、注册、调用）机制，支持对跨设备的应用进行远程启动、远程调用、绑定/解绑、以及迁移等操作，能够根据不同设备的能力、位置、业务运行状态、资源使用情况并结合用户的习惯和意图，选择最合适的设备运行分布式任务


    -   设备虚拟化
    
        分布式设备虚拟化平台可以实现不同设备的资源融合、设备管理、数据处理，将周边设备作为手机能力的延伸，共同形成一个超级虚拟终端。


2.  一次开发，多端部署

    OpenHarmony提供用户程序框架、Ability框架以及UI框架，能够保证开发的应用在多终端运行时保证一致性。一次开发、多端部署。

    多终端软件平台API具备一致性，确保用户程序的运行兼容性。

    -   支持在开发过程中预览终端的能力适配情况（CPU/内存/外设/软件资源等）。
    -   支持根据用户程序与软件平台的兼容性来调度用户呈现。

3.  统一OS，弹性部署

    OpenHarmony通过组件化和组件弹性化等设计方法，做到硬件资源的可大可小，在多种终端设备间，按需弹性部署，全面覆盖了ARM、RISC-V、x86等各种CPU，从百KB到GB级别的RAM。


## **设备类型**<a name="section145241459142416"></a>

OpenHarmony支持如下几种设备类型：

-   **轻量系统类设备（参考内存≥128KB）**

    面向MCU类处理器，例如Arm Cortex-M、RISC-V 32位的设备，资源极其有限，参考内存≥128KB，提供丰富的近距连接能力以及丰富的外设总线访问能力。典型产品有智能家居领域的联接类模组、传感器设备等。联接类模组通常应用在智能物联网设备中，负责实现联接部分的硬件模块，在智能家居领域由厂家集成到其设备中。例如：联接类模组提供WLAN/Bluetooth的接入和数据的联接，模组与厂家家居的芯片通常通过UART或GPIO等总线接口进行通信。

-   **小型系统类设备（参考内存≥1MB）**

    面向应用处理器，例如Arm Cortex-A的设备，参考内存≥1MB，提供更高的安全能力，提供标准的图形框架，提供视频编解码的多媒体能力。典型产品有智能家居领域的IPCamera、电子猫眼、路由器以及智慧出行域的行车记录仪等。


-   **标准系统类设备（参考内存≥128MB）**

    面向应用处理器，例如Arm Cortex-A的设备，参考内存≥128MB，提供增强的交互能力，提供3D GPU以及硬件合成能力，提供更多控件以及动效更丰富的图形能力，提供完整的应用框架。典型产品有高端的冰箱显示屏等。

-   **大型系统类设备（参考内存≥1GB）**

    面向应用处理器，例如Arm Cortex-A的设备，参考内存≥1GB，提供完整的兼容应用框架。典型的产品有智慧屏、智能手表等。


## 详细特征<a name="section25831825174419"></a>

入口：[https://gitee.com/openharmony/docs/tree/master/zh-cn/readme](https://gitee.com/openharmony/docs/tree/master/zh-cn/readme)

\*本次开源部分主要支持百K级，百M级设备，以下内容主要介绍涉及到的相关子系统内容。

**表 1**  子系统

<a name="table18981149155318"></a>
<table><thead align="left"><tr id="row69811925313"><th class="cellrowborder" valign="top" width="13.381338133813381%" id="mcps1.2.4.1.1"><p id="p9143172718537"><a name="p9143172718537"></a><a name="p9143172718537"></a>系 统</p>
</th>
<th class="cellrowborder" valign="top" width="75.85758575857585%" id="mcps1.2.4.1.2"><p id="p6143122775319"><a name="p6143122775319"></a><a name="p6143122775319"></a>简 介</p>
</th>
<th class="cellrowborder" valign="top" width="10.76107610761076%" id="mcps1.2.4.1.3"><p id="p914352775312"><a name="p914352775312"></a><a name="p914352775312"></a>链 接</p>
</th>
</tr>
</thead>
<tbody><tr id="row4981119185313"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p1114318271534"><a name="p1114318271534"></a><a name="p1114318271534"></a>JS应用开发框架</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p1314313275533"><a name="p1314313275533"></a><a name="p1314313275533"></a>作为JS应用开发框架的轻量实现，提供一套跨平台的类web应用开发框架，通过Toolkit将开发者编写的HTML、CSS和JS 文件编译打包成JS Bundle，然后再将JS Bundle解析运行成C++ UIKit的View 组件进行渲染。通过支持三方开发者使用声明式的API进行应用开发，以数据驱动视图变化，避免了大量的视图操作，大大降低了应用开发难度，提升开发者开发体验。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p614352711533"><a name="p614352711533"></a><a name="p614352711533"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/JS应用开发框架.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row119815917532"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p514412715318"><a name="p514412715318"></a><a name="p514412715318"></a>DFX</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p91441275533"><a name="p91441275533"></a><a name="p91441275533"></a>针对不同硬件架构和资源提供组件化且可定制的DFX框架。根据RISC-V、Cortex-M、Cortex-A不同硬件平台，提供两种不同的轻量级DFX框架。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p1014412277533"><a name="p1014412277533"></a><a name="p1014412277533"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/DFX子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1698219916532"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p1144327125310"><a name="p1144327125310"></a><a name="p1144327125310"></a>XTS认证</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p314432725311"><a name="p314432725311"></a><a name="p314432725311"></a>XTS是OpenHarmony生态认证测试套件的集合，当前包括acts（application compatibility test suite）应用兼容性测试套，后续会拓展dcts（device compatibility test suite）设备兼容性测试套等。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p6144142785310"><a name="p6144142785310"></a><a name="p6144142785310"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/XTS认证子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1998212985315"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p214412714534"><a name="p214412714534"></a><a name="p214412714534"></a>全球化</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p81444277538"><a name="p81444277538"></a><a name="p81444277538"></a>全球化资源管理子系统主要提供语言资源回溯和多偏好语言支持的能力，包括多语言资源回溯和多偏好语言支持。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p18144227185311"><a name="p18144227185311"></a><a name="p18144227185311"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/全球化子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1398249165320"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p13144192712533"><a name="p13144192712533"></a><a name="p13144192712533"></a>公共基础</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p91441027175313"><a name="p91441027175313"></a><a name="p91441027175313"></a>公共基础库存放OpenHarmony通用的基础组件。这些基础组件可被OpenHarmony各业务子系统及上层应用所使用。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p9144112795314"><a name="p9144112795314"></a><a name="p9144112795314"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/公共基础.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row209823955313"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p17144192718536"><a name="p17144192718536"></a><a name="p17144192718536"></a>内核</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p314519273533"><a name="p314519273533"></a><a name="p314519273533"></a>OpenHarmony内核是面向IoT领域的实时操作系统内核，它具备类似RTOS般轻快和Linux般易用的特点。包括功能组件部分：进程和线程调度、内存管理、IPC机制、timer管理等操作系统基础组件。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p91453278539"><a name="p91453278539"></a><a name="p91453278539"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/内核子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1982159115313"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p1014542719537"><a name="p1014542719537"></a><a name="p1014542719537"></a>分布式任务调度</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p1214542745310"><a name="p1214542745310"></a><a name="p1214542745310"></a>分布式任务调度模块负责跨设备组件管理，提供访问和控制远程组件的能力，支持分布式场景下的应用协同。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p141451927135317"><a name="p141451927135317"></a><a name="p141451927135317"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/分布式任务调度子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row998219914538"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p61451927155312"><a name="p61451927155312"></a><a name="p61451927155312"></a>分布式软总线</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p1145327135320"><a name="p1145327135320"></a><a name="p1145327135320"></a>实现近场设备间统一的分布式通信能力管理，提供不区分链路的设备发现和传输接口。包含服务发布、数据传输、安全等功能。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p12145627125320"><a name="p12145627125320"></a><a name="p12145627125320"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/分布式软总线子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row89839920531"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p5145327155315"><a name="p5145327155315"></a><a name="p5145327155315"></a>启动恢复</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p1214562745311"><a name="p1214562745311"></a><a name="p1214562745311"></a>启动恢复负责在内核启动之后，应用启动之前的操作系统中间层的启动。支持使用LiteOS-A内核的平台，当前包括：Hi3516DV300平台和Hi3518EV300平台。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p12145627135313"><a name="p12145627135313"></a><a name="p12145627135313"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/启动恢复子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1598389185315"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p1714520273532"><a name="p1714520273532"></a><a name="p1714520273532"></a>图形</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p19145132713537"><a name="p19145132713537"></a><a name="p19145132713537"></a>主要包括UI组件、布局、动画、字体、输入事件、窗口管理、渲染绘制等模块，构建基于轻量OS的应用框架，满足硬件资源较小的物联网设备的OpenHarmony系统应用开发。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p101451927175314"><a name="p101451927175314"></a><a name="p101451927175314"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/图形子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row179834916539"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p21461127105314"><a name="p21461127105314"></a><a name="p21461127105314"></a>媒体</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p1114632715314"><a name="p1114632715314"></a><a name="p1114632715314"></a>为多媒体应用开发者提供统一的开发接口，使得开发者可以专注于应用业务的开发，轻松使用多媒体的资源。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p714682716530"><a name="p714682716530"></a><a name="p714682716530"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/媒体子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1698317918532"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p7146152711532"><a name="p7146152711532"></a><a name="p7146152711532"></a>安全</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p6146172719537"><a name="p6146172719537"></a><a name="p6146172719537"></a>主要提供样例给开发者展示如何去使用已有的安全机制来提升系统的安全能力，包括安全启动、应用权限管理、IPC通信鉴权、HUKS、HiChain、应用签名验签。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p314610277534"><a name="p314610277534"></a><a name="p314610277534"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/安全子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row198318945311"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p131461727135311"><a name="p131461727135311"></a><a name="p131461727135311"></a>测试</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p15146192795315"><a name="p15146192795315"></a><a name="p15146192795315"></a>开发过程采用测试驱动开发模式，开发者基于系统新增特性可以通过开发者自己开发用例保证，对于系统已有特性的修改，也可通过修改项目中原有自测试用例保证，旨在帮助开发者在开发阶段就能开发出高质量代码。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p141465270538"><a name="p141465270538"></a><a name="p141465270538"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/测试子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row99837975315"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p1614682714531"><a name="p1614682714531"></a><a name="p1614682714531"></a>用户程序框架</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p01461827195315"><a name="p01461827195315"></a><a name="p01461827195315"></a>包含两个模块：Ability子系统和包管理子系统。Ability子系统，是OpenHarmony为开发者提供的一套开发OpenHarmony应用的开发框架。包管理子系统，是OpenHarmony为开发者提供的安装包管理框架。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p2146152765317"><a name="p2146152765317"></a><a name="p2146152765317"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/用户程序框架子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row098416935318"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p15190115891319"><a name="p15190115891319"></a><a name="p15190115891319"></a>AI子系统</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p719011584139"><a name="p719011584139"></a><a name="p719011584139"></a>AI业务子系统是提供原生的分布式AI能力的子系统，提供了统一的AI引擎框架，实现算法能力快速插件化集成。框架中主要包含插件管理、模块管理和通信管理等模块，对AI算法能力进行生命周期管理和按需部署。后续，会逐步定义统一的AI能力接口，便于AI能力的分布式调用。同时，提供适配不同推理框架层级的统一推理接口。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p855814271615"><a name="p855814271615"></a><a name="p855814271615"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/AI业务子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row11522144014127"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p25221640111212"><a name="p25221640111212"></a><a name="p25221640111212"></a>泛Sensor</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p952264071216"><a name="p952264071216"></a><a name="p952264071216"></a>泛Sensor中包含传感器和小器件，传感器用于侦测环境中所发生事件或变化，并将此消息发送至其他电子设备，小器件用于向外传递信号的设备，包括马达和LED灯，对开发者提供控制马达振动和LED灯开关的能力。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p49561445181217"><a name="p49561445181217"></a><a name="p49561445181217"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/泛Sensor子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row6966123741719"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p99671837101720"><a name="p99671837101720"></a><a name="p99671837101720"></a>电源管理</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p13967237151716"><a name="p13967237151716"></a><a name="p13967237151716"></a>电源管理子系统主要提供了电池、充放电状态查询能力和系统电源管理服务能力，目前主要包括电量查询和亮灭屏控制锁的能力。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p782825121818"><a name="p782825121818"></a><a name="p782825121818"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/轻量级电源管理子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row163116577176"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p143265731720"><a name="p143265731720"></a><a name="p143265731720"></a>升级服务</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p9321157121712"><a name="p9321157121712"></a><a name="p9321157121712"></a>升级服务是提供设备远程升级的能力，可以让你的设备轻松支持OTA升级能力。目前仅支持全量包升级方式，全量包是将新系统全部内容做成升级包，进行升级。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p299962571810"><a name="p299962571810"></a><a name="p299962571810"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/升级服务子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row99841913538"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p514822710539"><a name="p514822710539"></a><a name="p514822710539"></a>编译构建</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p614816270536"><a name="p614816270536"></a><a name="p614816270536"></a>编译构建提供了一个在GN与ninja基础上的编译构建框架。支持以下功能：1.构建不同芯片平台的产品。如：Hi3518EV300平台的ipcamera产品，Hi3516DV300平台的ipcamera产品，Hi3861平台的WLAN模组产品。2.构建HPM包管理配置生成的自定义产品。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p51480270531"><a name="p51480270531"></a><a name="p51480270531"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/编译构建子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row199841792533"><td class="cellrowborder" valign="top" width="13.381338133813381%" headers="mcps1.2.4.1.1 "><p id="p7148627185312"><a name="p7148627185312"></a><a name="p7148627185312"></a>驱动</p>
</td>
<td class="cellrowborder" valign="top" width="75.85758575857585%" headers="mcps1.2.4.1.2 "><p id="p1148627185317"><a name="p1148627185317"></a><a name="p1148627185317"></a>OpenHarmony驱动子系统采用C面向对象编程模型构建，通过平台解耦、内核解耦，兼容不同内核，提供了归一化的驱动平台底座，旨在为开发者提供更精准、更高效的开发环境，力求做到一次开发，多系统部署。</p>
</td>
<td class="cellrowborder" valign="top" width="10.76107610761076%" headers="mcps1.2.4.1.3 "><p id="p9148132705317"><a name="p9148132705317"></a><a name="p9148132705317"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/驱动子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
</tbody>
</table>

## 快速入门<a name="section44681652104210"></a>

入口：[https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/Readme-CN.md](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/Readme-CN.md)

**表 2**  快速入门

<a name="table783094717597"></a>
<table><thead align="left"><tr id="row19831154715595"><th class="cellrowborder" valign="top" width="13.861386138613863%" id="mcps1.2.4.1.1"><p id="p10268195211411"><a name="p10268195211411"></a><a name="p10268195211411"></a>开发板类型</p>
</th>
<th class="cellrowborder" valign="top" width="76.03760376037604%" id="mcps1.2.4.1.2"><p id="p7268165244115"><a name="p7268165244115"></a><a name="p7268165244115"></a>简述</p>
</th>
<th class="cellrowborder" valign="top" width="10.101010101010102%" id="mcps1.2.4.1.3"><p id="p426845294110"><a name="p426845294110"></a><a name="p426845294110"></a>链 接</p>
</th>
</tr>
</thead>
<tbody><tr id="row14831174716590"><td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.2.4.1.1 "><p id="p119624458418"><a name="p119624458418"></a><a name="p119624458418"></a>Hi3861开发板</p>
</td>
<td class="cellrowborder" valign="top" width="76.03760376037604%" headers="mcps1.2.4.1.2 "><p id="p7962114519415"><a name="p7962114519415"></a><a name="p7962114519415"></a>Hi3861 WLAN模组是一片大约2cm*5cm大小的开发板，是一款高度集成的2.4GHz WLAN SoC芯片，集成IEEE 802.11b/g/n基带和RF（Radio Frequency）电路。支持OpenHarmony/Huawei LiteOS和第三方组件。</p>
</td>
<td class="cellrowborder" valign="top" width="10.101010101010102%" headers="mcps1.2.4.1.3 "><p id="p7963045154116"><a name="p7963045154116"></a><a name="p7963045154116"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/Hi3861开发板.md" target="_blank" rel="noopener noreferrer">快速入门</a></p>
</td>
</tr>
<tr id="row58311547175915"><td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.2.4.1.1 "><p id="p896334514411"><a name="p896334514411"></a><a name="p896334514411"></a>Hi3516开发板</p>
</td>
<td class="cellrowborder" valign="top" width="76.03760376037604%" headers="mcps1.2.4.1.2 "><p id="p18963104514115"><a name="p18963104514115"></a><a name="p18963104514115"></a>Hi3516DV300作为新一代行业专用Smart HD IP摄像机SOC，集成新一代ISP、业界最新的H.265视频压缩编码器，同时集成高性能NNIE引擎。</p>
</td>
<td class="cellrowborder" valign="top" width="10.101010101010102%" headers="mcps1.2.4.1.3 "><p id="p2963545124111"><a name="p2963545124111"></a><a name="p2963545124111"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/Hi3516开发板.md" target="_blank" rel="noopener noreferrer">快速入门</a></p>
</td>
</tr>
<tr id="row28310478595"><td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.2.4.1.1 "><p id="p296304510417"><a name="p296304510417"></a><a name="p296304510417"></a>Hi3518开发板</p>
</td>
<td class="cellrowborder" valign="top" width="76.03760376037604%" headers="mcps1.2.4.1.2 "><p id="p149631545114114"><a name="p149631545114114"></a><a name="p149631545114114"></a>Hi3518EV300作为新一代智慧视觉处理SOC，集成新一代ISP(Image Signal Processor)以及业界最新的H.265视频压缩编码器。</p>
</td>
<td class="cellrowborder" valign="top" width="10.101010101010102%" headers="mcps1.2.4.1.3 "><p id="p4963104516411"><a name="p4963104516411"></a><a name="p4963104516411"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/Hi3518开发板.md" target="_blank" rel="noopener noreferrer">快速入门</a></p>
</td>
</tr>
</tbody>
</table>

## 开发者文档<a name="section21031470109"></a>

简体中文：[OpenHarmony开发者文档](Readme-zh-cn.md)

English Version：[OpenHarmony Documentation](docs/Readme-en.md)

## 源码下载<a name="section39011923144212"></a>

获取OpenHarmony源码：[下载说明](https://openharmony.gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/get-code/%E6%BA%90%E7%A0%81%E8%8E%B7%E5%8F%96.md)

## 如何参与<a name="section19611528174215"></a>

参与社区：[社区介绍链接](https://gitee.com/openharmony/community/blob/master/README.md)

参与贡献：[如何贡献链接](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/%E5%8F%82%E4%B8%8E%E8%B4%A1%E7%8C%AE.md)

## 许可协议<a name="section1245517472115"></a>

OpenHarmony是一种开源软件，参考各仓下LICENSE文本。

## 联系方式<a name="section61728335424"></a>

网站：

[https://openharmony.gitee.com](https://openharmony.gitee.com/)

邮箱:

contact@openharmony.io

