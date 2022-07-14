# OpenHarmony开源项目

-   [项目介绍](#section1270210396435)
-   [技术架构](#section2502124574318)
-   [技术特性](#section12212842173518)
-   [系统类型](#section145241459142416)
-   [详细特征](#section25831825174419)
-   [支持的开发板](#section25831825174123)
-   [快速入门](#section44681652104210)
-   [代码仓地址](#section107651249181914)
-   [开发者文档](#section21031470109)
-   [源码下载](#section39011923144212)
-   [示例教程](#sectionsamples)
-   [如何参与](#section19611528174215)
-   [许可协议](#section1245517472115)
-   [联系方式](#section61728335424)

[View English](https://gitee.com/openharmony/docs/blob/master/en/OpenHarmony-Overview.md)

## 项目介绍<a name="section1270210396435"></a>

OpenHarmony是由开放原子开源基金会（OpenAtom Foundation）孵化及运营的开源项目，目标是面向全场景、全连接、全智能时代，基于开源的方式，搭建一个智能终端设备操作系统的框架和平台，促进万物互联产业的繁荣发展。

## 技术架构<a name="section2502124574318"></a>

OpenHarmony整体遵从分层设计，从下向上依次为：内核层、系统服务层、框架层和应用层。系统功能按照“系统 \> 子系统 \> 组件”逐级展开，在多设备部署场景下，支持根据实际需求裁剪某些非必要的组件。OpenHarmony技术架构如下所示：

![](figures/1.png)

**内核层**

-   内核子系统：采用多内核（Linux内核或者LiteOS）设计，支持针对不同资源受限设备选用适合的OS内核。内核抽象层（KAL，Kernel Abstract Layer）通过屏蔽多内核差异，对上层提供基础的内核能力，包括进程/线程管理、内存管理、文件系统、网络管理和外设管理等。

-   驱动子系统：驱动框架（HDF）是系统硬件生态开放的基础，提供统一外设访问能力和驱动开发、管理框架。


**系统服务层**

系统服务层是OpenHarmony的核心能力集合，通过框架层对应用程序提供服务。该层包含以下几个部分：

-   系统基本能力子系统集：为分布式应用在多设备上的运行、调度、迁移等操作提供了基础能力，由分布式软总线、分布式数据管理、分布式任务调度、公共基础库、多模输入、图形、安全、AI等子系统组成。

-   基础软件服务子系统集：提供公共的、通用的软件服务，由事件通知、电话、多媒体、DFX（Design For X） 等子系统组成。

-   增强软件服务子系统集：提供针对不同设备的、差异化的能力增强型软件服务，由智慧屏专有业务、穿戴专有业务、IoT专有业务等子系统组成。

-   硬件服务子系统集：提供硬件服务，由位置服务、用户IAM、穿戴专有硬件服务、IoT专有硬件服务等子系统组成。


根据不同设备形态的部署环境，基础软件服务子系统集、增强软件服务子系统集、硬件服务子系统集内部可以按子系统粒度裁剪，每个子系统内部又可以按功能粒度裁剪。

**框架层**

框架层为应用开发提供了C/C++/JS等多语言的用户程序框架和Ability框架，适用于JS语言的ArkUI框架，以及各种软硬件服务对外开放的多语言框架API。根据系统的组件化裁剪程度，设备支持的API也会有所不同。

**应用层**

应用层包括系统应用和第三方非系统应用。应用由一个或多个FA（Feature Ability）或PA（Particle Ability）组成。其中，FA有UI界面，提供与用户交互的能力；而PA无UI界面，提供后台运行任务的能力以及统一的数据访问抽象。基于FA/PA开发的应用，能够实现特定的业务功能，支持跨设备调度与分发，为用户提供一致、高效的应用体验。

## 技术特性<a name="section12212842173518"></a>

1.  **硬件互助，资源共享**

    主要通过下列模块达成

    -   分布式软总线

        分布式软总线是多设备终端的统一基座，为设备间的无缝互联提供了统一的分布式通信能力，能够快速发现并连接设备，高效地传输任务和数据。


    -   分布式数据管理
    
        分布式数据管理位于基于分布式软总线之上的能力，实现了应用程序数据和用户数据的分布式管理。用户数据不再与单一物理设备绑定，业务逻辑与数据存储分离，应用跨设备运行时数据无缝衔接，为打造一致、流畅的用户体验创造了基础条件


    -   分布式任务调度
    
        分布式任务调度基于分布式软总线、分布式数据管理、分布式Profile等技术特性，构建统一的分布式服务管理（发现、同步、注册、调用）机制，支持对跨设备的应用进行远程启动、远程调用、绑定/解绑、以及迁移等操作，能够根据不同设备的能力、位置、业务运行状态、资源使用情况并结合用户的习惯和意图，选择最合适的设备运行分布式任务


    -   设备虚拟化
    
        分布式设备虚拟化平台可以实现不同设备的资源融合、设备管理、数据处理，将周边设备作为手机能力的延伸，共同形成一个超级虚拟终端。


2.  **一次开发，多端部署**

    OpenHarmony提供用户程序框架、Ability框架以及UI框架，能够保证开发的应用在多终端运行时保证一致性。一次开发、多端部署。

    多终端软件平台API具备一致性，确保用户程序的运行兼容性。

    -   支持在开发过程中预览终端的能力适配情况（CPU/内存/外设/软件资源等）。
    -   支持根据用户程序与软件平台的兼容性来调度用户呈现。

3.  **统一OS，弹性部署**

    OpenHarmony通过组件化和组件弹性化等设计方法，做到硬件资源的可大可小，在多种终端设备间，按需弹性部署，全面覆盖了ARM、RISC-V、x86等各种CPU，从百KiB到GiB级别的RAM。


## 系统类型<a name="section145241459142416"></a>

OpenHarmony支持如下几种系统类型：

-   轻量系统（mini system）

    面向MCU类处理器例如Arm Cortex-M、RISC-V 32位的设备，硬件资源极其有限，支持的设备最小内存为128KiB，可以提供多种轻量级网络协议，轻量级的图形框架，以及丰富的IOT总线读写部件等。可支撑的产品如智能家居领域的连接类模组、传感器设备、穿戴类设备等。

-   小型系统（small system）

    面向应用处理器例如Arm Cortex-A的设备，支持的设备最小内存为1MiB，可以提供更高的安全能力、标准的图形框架、视频编解码的多媒体能力。可支撑的产品如智能家居领域的IP Camera、电子猫眼、路由器以及智慧出行域的行车记录仪等。

-   标准系统（standard system）

    面向应用处理器例如Arm Cortex-A的设备，支持的设备最小内存为128MiB，可以提供增强的交互能力、3D GPU以及硬件合成能力、更多控件以及动效更丰富的图形能力、完整的应用框架。可支撑的产品如高端的冰箱显示屏。


## 详细特征<a name="section25831825174419"></a>

在介绍OpenHarmony特性前，需要先明确以下两个基本概念：

-   子系统

    OpenHarmony整体遵从分层设计，从下向上依次为：内核层、系统服务层、框架层和应用层。系统功能按照“系统 \> 子系统 \> 组件”逐级展开，在多设备部署场景下，支持根据实际需求裁剪某些非必要的组件。子系统是一个逻辑概念，它具体由对应的组件构成。

-   组件

    对子系统的进一步拆分，可复用的软件单元，它包含源码、配置文件、资源文件和编译脚本；能独立构建，以二进制方式集成，具备独立验证能力的二进制单元。


以下为OpenHarmony中相关的子系统简介，详细介绍见子系统Readme文档，入口：[https://gitee.com/openharmony/docs/tree/master/zh-cn/readme](https://gitee.com/openharmony/docs/tree/master/zh-cn/readme)。

<a name="table18981149155318"></a>

<table><thead align="left"><tr id="row69811925313"><th class="cellrowborder" valign="top" width="11.148885111488852%" id="mcps1.1.4.1.1"><p id="p9143172718537"><a name="p9143172718537"></a><a name="p9143172718537"></a>子系 统</p>
</th>
<th class="cellrowborder" valign="top" width="80.49195080491951%" id="mcps1.1.4.1.2"><p id="p6143122775319"><a name="p6143122775319"></a><a name="p6143122775319"></a>简 介</p>
</th>
<th class="cellrowborder" valign="top" width="8.35916408359164%" id="mcps1.1.4.1.3"><p id="p36827655311"><a name="p36827655311"></a><a name="p36827655311"></a>适用范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row1746235812115"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p84622581117"><a name="p84622581117"></a><a name="p84622581117"></a>内核</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p34626584118"><a name="p34626584118"></a><a name="p34626584118"></a>支持适用于嵌入式设备及资源受限设备，具有小体积、高性能、低功耗等特征的LiteOS内核；支持基于linux kernel演进的适用于标准系统的linux内核。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p31041221121"><a name="p31041221121"></a><a name="p31041221121"></a>小型系统</p>
<p id="p16450192619121"><a name="p16450192619121"></a><a name="p16450192619121"></a>标准系统</p>
</td>
</tr>
<tr id="row4465751131114"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p12465145131117"><a name="p12465145131117"></a><a name="p12465145131117"></a>分布式文件</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p1046615111118"><a name="p1046615111118"></a><a name="p1046615111118"></a>提供本地同步JS文件接口。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p15466135171117"><a name="p15466135171117"></a><a name="p15466135171117"></a>标准系统</p>
</td>
</tr>
<tr id="row14286184818110"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p1328654871112"><a name="p1328654871112"></a><a name="p1328654871112"></a>图形</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p15912684317"><a name="p15912684317"></a><a name="p15912684317"></a>主要包括UI组件、布局、动画、字体、输入事件、窗口管理、渲染绘制等模块，构建基于轻量OS应用框架满足硬件资源较小的物联网设备或者构建基于标准OS的应用框架满足富设备（如平板和轻智能机等）的OpenHarmony系统应用开发。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p228719483115"><a name="p228719483115"></a><a name="p228719483115"></a>所有系统</p>
</td>
</tr>
<tr id="row4981119185313"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p43071335181312"><a name="p43071335181312"></a><a name="p43071335181312"></a>驱动</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p849919919515"><a name="p849919919515"></a><a name="p849919919515"></a>OpenHarmony驱动子系统采用C面向对象编程模型构建，通过平台解耦、内核解耦，兼容不同内核，提供了归一化的驱动平台底座，旨在为开发者提供更精准、更高效的开发环境，力求做到一次开发，多系统部署。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p7909102101420"><a name="p7909102101420"></a><a name="p7909102101420"></a>所有系统</p>
</td>
</tr>
<tr id="row1698219916532"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p183071635131320"><a name="p183071635131320"></a><a name="p183071635131320"></a>电源管理服务</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p1534121801513"><a name="p1534121801513"></a><a name="p1534121801513"></a>电源管理服务子系统提供如下功能：重启系统；管理休眠运行锁；系统电源状态管理和查询；充电和电池状态查询和上报；显示亮灭屏状态管理，包括显示亮度调节。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p0562145615152"><a name="p0562145615152"></a><a name="p0562145615152"></a>标准系统</p>
</td>
</tr>
<tr id="row1998212985315"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p1230718353132"><a name="p1230718353132"></a><a name="p1230718353132"></a>泛Sensor服务</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p114999919515"><a name="p114999919515"></a><a name="p114999919515"></a>泛Sensor中包含传感器和小器件，传感器用于侦测环境中所发生事件或变化，并将此消息发送至其他电子设备，小器件用于向外传递信号的设备，包括马达和LED灯，对开发者提供控制马达振动和LED灯开关的能力。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p7683136135317"><a name="p7683136135317"></a><a name="p7683136135317"></a>小型系统</p>
</td>
</tr>
<tr id="row1398249165320"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p1930743511318"><a name="p1930743511318"></a><a name="p1930743511318"></a>多模输入</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p13832172015162"><a name="p13832172015162"></a><a name="p13832172015162"></a>OpenHarmony旨在为开发者提供NUI（Natural User Interface）的交互方式，有别于传统操作系统的输入，在OpenHarmony上，我们将多种维度的输入整合在一起，开发者可以借助应用程序框架、系统自带的UI组件或API接口轻松地实现具有多维、自然交互特点的应用程序。具体来说，多模输入子系统目前支持传统的输入交互方式，例如按键和触控。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p025515141075"><a name="p025515141075"></a><a name="p025515141075"></a>标准系统</p>
</td>
</tr>
<tr id="row209823955313"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p1030711354137"><a name="p1030711354137"></a><a name="p1030711354137"></a>启动恢复</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p54461340151820"><a name="p54461340151820"></a><a name="p54461340151820"></a>启动恢复负责在内核启动之后，应用启动之前的操作系统中间层的启动。并提供系统属性查询、修改及设备恢复出厂设置的功能。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p8683362533"><a name="p8683362533"></a><a name="p8683362533"></a>所有系统</p>
</td>
</tr>
<tr id="row1982159115313"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p14307173571315"><a name="p14307173571315"></a><a name="p14307173571315"></a>升级服务</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p887484183"><a name="p887484183"></a><a name="p887484183"></a>可支持OpenHarmony设备的OTA（Over The Air）升级。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p10550164995117"><a name="p10550164995117"></a><a name="p10550164995117"></a>标准系统</p>
</td>
</tr>
<tr id="row89839920531"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p123071435151319"><a name="p123071435151319"></a><a name="p123071435151319"></a>帐号</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p2772313127"><a name="p2772313127"></a><a name="p2772313127"></a>支持在端侧对接厂商云帐号应用，提供分布式帐号登录状态查询和更新的管理能力。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p19928023151913"><a name="p19928023151913"></a><a name="p19928023151913"></a>标准系统</p>
</td>
</tr>
<tr id="row1598389185315"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p11473102882017"><a name="p11473102882017"></a><a name="p11473102882017"></a>编译构建</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p22956349202"><a name="p22956349202"></a><a name="p22956349202"></a>编译构建子系统提供了一个基于Gn和ninja的编译构建框架。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p183114819179"><a name="p183114819179"></a><a name="p183114819179"></a>所有系统</p>
</td>
</tr>
<tr id="row179834916539"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p1347382819202"><a name="p1347382819202"></a><a name="p1347382819202"></a>测试</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p1850179125115"><a name="p1850179125115"></a><a name="p1850179125115"></a>开发过程采用测试驱动开发模式，开发者基于系统新增特性可以通过开发者自己开发用例保证，对于系统已有特性的修改，也可通过修改项目中原有的测试用例保证，开发者测试旨在帮助开发者在开发阶段就能开发出高质量代码。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p15458348191719"><a name="p15458348191719"></a><a name="p15458348191719"></a>所有系统</p>
</td>
</tr>
<tr id="row1698317918532"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p11473172817202"><a name="p11473172817202"></a><a name="p11473172817202"></a>数据管理</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p2030983518561"><a name="p2030983518561"></a><a name="p2030983518561"></a>数据管理支持应用本地数据管理和分布式数据管理：</p>
<a name="ul2727156145217"></a><a name="ul2727156145217"></a><ul id="ul2727156145217"><li>支持应用本地数据管理，包括轻量级偏好数据库，关系型数据库。</li><li>支持分布式数据服务，为应用程序提供不同设备间数据库数据分布式的能力。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p193679548203"><a name="p193679548203"></a><a name="p193679548203"></a>标准系统</p>
</td>
</tr>
<tr id="row198318945311"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p14473132812018"><a name="p14473132812018"></a><a name="p14473132812018"></a>语言编译运行时</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p17753537218"><a name="p17753537218"></a><a name="p17753537218"></a>语言运行时提供了JS、C/C++语言程序的编译、执行环境，提供支撑运行时的基础库，以及关联的API接口、编译器和配套工具。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p14593146192111"><a name="p14593146192111"></a><a name="p14593146192111"></a>所有系统</p>
</td>
</tr>
<tr id="row098416935318"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p64731628132015"><a name="p64731628132015"></a><a name="p64731628132015"></a>分布式任务调度</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p55320348170"><a name="p55320348170"></a><a name="p55320348170"></a>提供系统服务的启动、注册、查询及管理能力。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p76835611530"><a name="p76835611530"></a><a name="p76835611530"></a>所有系统</p>
</td>
</tr>
<tr id="row11522144014127"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p847382818209"><a name="p847382818209"></a><a name="p847382818209"></a>JS UI框架</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p18885204913282"><a name="p18885204913282"></a><a name="p18885204913282"></a>JS UI框架是OpenHarmony UI开发框架，支持类Web范式编程。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p18278134513216"><a name="p18278134513216"></a><a name="p18278134513216"></a>所有系统</p>
</td>
</tr>
<tr id="row163116577176"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p9473192862015"><a name="p9473192862015"></a><a name="p9473192862015"></a>媒体</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p17895171152211"><a name="p17895171152211"></a><a name="p17895171152211"></a>提供音频、视频、相机等简单有效的媒体组件开发接口，使得应用开发者轻松使用系统的多媒体资源。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p7683126105314"><a name="p7683126105314"></a><a name="p7683126105314"></a>所有系统</p>
</td>
</tr>
<tr id="row99841913538"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p34736280204"><a name="p34736280204"></a><a name="p34736280204"></a>事件通知</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p1328485917223"><a name="p1328485917223"></a><a name="p1328485917223"></a>公共事件管理实现了订阅、退订、发布、接收公共事件（例如亮灭屏事件、USB插拔事件）的能力。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p19305121815138"><a name="p19305121815138"></a><a name="p19305121815138"></a>标准系统</p>
</td>
</tr>
<tr id="row199841792533"><td class="cellrowborder" align="left" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p6473102817205"><a name="p6473102817205"></a><a name="p6473102817205"></a>杂散软件服务</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p8502149175110"><a name="p8502149175110"></a><a name="p8502149175110"></a>提供设置时间的能力。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p1962012112314"><a name="p1962012112314"></a><a name="p1962012112314"></a>标准系统</p>
</td>
</tr>
<tr id="row176674368222"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p3667203652214"><a name="p3667203652214"></a><a name="p3667203652214"></a>包管理子系统</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p12923326230"><a name="p12923326230"></a><a name="p12923326230"></a>提供包安装、卸载、更新、查询等能力。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p12667123619226"><a name="p12667123619226"></a><a name="p12667123619226"></a>所有系统</p>
</td>
</tr>
<tr id="row65111417226"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p612981114248"><a name="p612981114248"></a><a name="p612981114248"></a>电话服务</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p19521141152212"><a name="p19521141152212"></a><a name="p19521141152212"></a>提供SIM卡、搜网、蜂窝数据、蜂窝通话、短彩信等蜂窝移动网络基础通信能力，可管理多类型通话和数据网络连接，为应用开发者提供便捷一致的通信API。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p124681352134"><a name="p124681352134"></a><a name="p124681352134"></a>标准系统</p>
</td>
</tr>
<tr id="row10194183317227"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p14129311172416"><a name="p14129311172416"></a><a name="p14129311172416"></a>公共基础类库</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p21941533132218"><a name="p21941533132218"></a><a name="p21941533132218"></a>公共基础库存放OpenHarmony通用的基础组件。这些基础组件可被OpenHarmony各业务子系统及上层应用所使用。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p1219413311229"><a name="p1219413311229"></a><a name="p1219413311229"></a>所有系统</p>
</td>
</tr>
<tr id="row9664349242"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p116653462411"><a name="p116653462411"></a><a name="p116653462411"></a>研发工具链</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p15701144517139"><a name="p15701144517139"></a><a name="p15701144517139"></a>提供设备连接调试器hdc；提供了性能跟踪能力和接口；提供了性能调优框架，旨在为开发者提供一套性能调优平台，可以用来分析内存、性能等问题。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p1696110251415"><a name="p1696110251415"></a><a name="p1696110251415"></a>标准系统</p>
</td>
</tr>
<tr id="row1449910380242"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p238324932415"><a name="p238324932415"></a><a name="p238324932415"></a>分布式软总线</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p17499153862420"><a name="p17499153862420"></a><a name="p17499153862420"></a>分布式软总线旨在为OpenHarmony系统提供跨进程或跨设备的通信能力，主要包含软总线和进程间通信两部分。其中，软总线为应用和系统提供近场设备间分布式通信的能力，提供不区分通信方式的设备发现，连接，组网和传输功能；而进程间通信则提供了对设备内或设备间无差别的进程间通信能力。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p5499183812418"><a name="p5499183812418"></a><a name="p5499183812418"></a>所有系统</p>
</td>
</tr>
<tr id="row1733413367244"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p1238318490244"><a name="p1238318490244"></a><a name="p1238318490244"></a>XTS</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p2334113611248"><a name="p2334113611248"></a><a name="p2334113611248"></a>XTS是OpenHarmony兼容性测试套件的集合，当前包括acts（application compatibility test suite）应用兼容性测试套，后续会拓展dcts（device compatibility test suite）设备兼容性测试套等。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p03341936102418"><a name="p03341936102418"></a><a name="p03341936102418"></a>所有系统</p>
</td>
</tr>
<tr id="row1817163212413"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p53831049112416"><a name="p53831049112416"></a><a name="p53831049112416"></a>系统应用</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p91717327249"><a name="p91717327249"></a><a name="p91717327249"></a>系统应用提供了OpenHarmony标准版上的部分系统应用，如桌面、SystemUI、设置等应用，为开发者提供了构建标准版应用的具体实例，这些应用支持在所有标准版系统的设备上使用。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p10171133218245"><a name="p10171133218245"></a><a name="p10171133218245"></a>标准系统</p>
</td>
</tr>
<tr id="row3577428102418"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p93831496249"><a name="p93831496249"></a><a name="p93831496249"></a>DFX</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p8578828122413"><a name="p8578828122413"></a><a name="p8578828122413"></a>DFX是OpenHarmony非功能属性能力，包含日志系统、应用和系统事件日志接口、事件日志订阅服务、故障信息生成采集等功能。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p18578102822411"><a name="p18578102822411"></a><a name="p18578102822411"></a>所有系统</p>
</td>
</tr>
<tr id="row418795214250"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p860151102616"><a name="p860151102616"></a><a name="p860151102616"></a>全球化</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p41871252102515"><a name="p41871252102515"></a><a name="p41871252102515"></a>当OpenHarmony设备或应用在全球不同区域使用时，系统和应用需要满足不同市场用户关于语言、文化习俗的需求。全球化子系统提供支持多语言、多文化的能力，包括资源管理能力和国际化能力。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p201658544174"><a name="p201658544174"></a><a name="p201658544174"></a>所有系统</p>
</td>
</tr>
<tr id="row16870124919255"><td class="cellrowborder" valign="top" width="11.148885111488852%" headers="mcps1.1.4.1.1 "><p id="p136021513265"><a name="p136021513265"></a><a name="p136021513265"></a>安全</p>
</td>
<td class="cellrowborder" valign="top" width="80.49195080491951%" headers="mcps1.1.4.1.2 "><p id="p2871134913255"><a name="p2871134913255"></a><a name="p2871134913255"></a>安全子系统包括系统安全、数据安全、应用安全等模块，为OpenHarmony提供了保护系统和和用户数据的能力。安全子系统当前开源的功能，包括应用完整性保护、应用权限管理、设备认证、密钥管理服务。</p>
</td>
<td class="cellrowborder" valign="top" width="8.35916408359164%" headers="mcps1.1.4.1.3 "><p id="p1487113491251"><a name="p1487113491251"></a><a name="p1487113491251"></a>所有系统</p>
</td>
</tr>
</tbody>
</table>

## 支持的开发板<a name="section25831825174123"></a>

当前OpenHarmony社区支持17款开发板，下表介绍3款（此处选择三种系统类型首款进入OpenHarmony主干的开发板），更多开发板信息，请参考[社区支持的开发板清单](device-dev/dev-board-on-the-master.md)。

| 系统类型 | 开发板型号 | 芯片型号 | 主要能力 | 典型应用场景 | 开发板代码仓及社区每日构建版本获取地址 |
| -------- | -------- | -------- | -------- | -------- | -------- |
| 标准系统 | 润和DAYU200 | RK3568 | 润和HH-SCDAYU200基于Rockchip&nbsp;RK3568，集成双核心架构GPU以及高效能NPU；板载四核64位Cortex-A55&nbsp;处理器采用22nm先进工艺，主频高达2.0GHz；支持蓝牙、Wi-Fi、音频、视频和摄像头等功能，拥有丰富的扩展接口，支持多种视频输入输出接口；配置双千兆自适应RJ45以太网口，可满足NVR、工业网关等多网口产品需求。 | 影音娱乐、智慧出行、智能家居，如烟机、烤箱、跑步机等。 | 代码仓：<br/>[device_soc_rockchip](https://gitee.com/openharmony/device_soc_rockchip)<br/>[device_board_hihope](https://gitee.com/openharmony/device_board_hihope)<br/>[vendor_hihope](https://gitee.com/openharmony/vendor_hihope) <br/> 社区每日构建版本获取地址：<br/>http://ci.openharmony.cn/dailys/dailybuilds |
| 小型系统 | Hispark_Taurus | Hi3516DV300 | Hi3516DV300是新一代Smart&nbsp;HD&nbsp;IP摄像机SOC，集成新一代ISP(Image&nbsp;Signal&nbsp;Processor)、H.265视频压缩编码器、高性能NNIE引擎，在低码率、高画质、智能处理和分析、低功耗等方面有较好的性能。 | 带屏智能硬件，比如带屏冰箱、车机等。 | 代码仓：<br/>[device_soc_hisilicon](https://gitee.com/openharmony/device_soc_hisilicon)<br/>[device_board_hisilicon](https://gitee.com/openharmony/device_board_hisilicon)<br/>[vendor_hisilicon](https://gitee.com/openharmony/vendor_hisilicon) <br/> 社区每日构建版本获取地址：<br/>http://ci.openharmony.cn/dailys/dailybuilds |
| 轻量系统 | 欧智通V200ZR | BES2600 | Multi-modal&nbsp;V200Z-R开发板是基于恒玄科技BES2600WM芯片的一款高性能、多功能、高性价比AIoT&nbsp;SoC开发板Multi-modal&nbsp;V200Z-R开发板，单模组集成四核ARM处理器（最高主频1GHz），集成双频WiFi&nbsp;+&nbsp;双模蓝牙，支持标准的802.11&nbsp;a/b/g/n/协议，支持BT/BLE&nbsp;5.2协议，内建多种容量的RAM（最大42MB）和Flash（最大32MB），支持MIPI&nbsp;DSI及CSI，适用于各种AIoT多模态VUI&nbsp;+&nbsp;GUI交互硬件场景。 | 智能硬件、带屏类模组产品，如音箱、手表等。 | 代码仓：<br/>[device_soc_bestechnic](https://gitee.com/openharmony/device_soc_bestechnic)<br/>[device_board_fnlink](https://gitee.com/openharmony/device_board_fnlink)<br/>[vendor_bestechnic](https://gitee.com/openharmony/vendor_bestechnic) <br/> 社区每日构建版本获取地址：<br/>http://ci.openharmony.cn/dailys/dailybuilds |

## 快速入门<a name="section44681652104210"></a>

- [设备开发快速入门](device-dev/quick-start/quickstart-ide-lite-overview.md)
- [应用开发快速入门](application-dev/quick-start/start-overview.md)



## 代码仓地址<a name="section107651249181914"></a>

OpenHarmony主库组织地址：[https://gitee.com/openharmony](https://gitee.com/openharmony)

OpenHarmonySIG组织地址：[https://gitee.com/openharmony-sig](https://gitee.com/openharmony-sig)

OpenHarmony三方库组织地址：[https://gitee.com/openharmony-tpc](https://gitee.com/openharmony-tpc)

OpenHarmony归档组织地址：[https://gitee.com/openharmony-retired](https://gitee.com/openharmony-retired)

## 开发者文档<a name="section21031470109"></a>

[访问官网](https://www.openharmony.cn/)

简体中文：[OpenHarmony开发者文档](https://gitee.com/openharmony/docs/tree/master/zh-cn)

[English Version](https://gitee.com/openharmony/docs/tree/master/en)

## 源码下载<a name="section39011923144212"></a>

获取OpenHarmony源码：[下载说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/get-code/sourcecode-acquire.md)

## 示例教程<a name="sectionsamples"></a>

Samples：[示例代码](https://gitee.com/openharmony/app_samples)

Codelabs：[教程指导](https://gitee.com/openharmony/codelabs)

## 如何参与<a name="section19611528174215"></a>

参与社区：[社区介绍](https://gitee.com/openharmony/community/blob/master/README.md)

参与贡献：[如何贡献](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/%E5%8F%82%E4%B8%8E%E8%B4%A1%E7%8C%AE.md)

## 许可协议<a name="section1245517472115"></a>

OpenHarmony主要遵循Apache License V2.0协议，详情请参考各代码仓LICENSE声明。

OpenHarmony引用三方开源软件及许可证说明，参考[第三方开源软件说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/%E7%AC%AC%E4%B8%89%E6%96%B9%E5%BC%80%E6%BA%90%E8%BD%AF%E4%BB%B6%E5%8F%8A%E8%AE%B8%E5%8F%AF%E8%AF%81%E8%AF%B4%E6%98%8E.md)。

## 联系方式<a name="section61728335424"></a>

网站：

[https://openharmony.gitee.com](https://openharmony.gitee.com/)

邮箱:

contact@openharmony.io

