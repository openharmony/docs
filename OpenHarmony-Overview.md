# OpenHarmony<a name="EN-US_TOPIC_0000001064024128"></a>

-   [Introduction](#section1270210396435)
-   [Technical Architecture](#section2502124574318)
-   [Technical Features](#section12212842173518)
-   [Device Types](#section145241459142416)
-   [Subsystems](#section25831825174419)
-   [Getting Started](#section44681652104210)
-   [OpenHarmony Documentation](#section21031470109)
-   [Source Code Downloading](#section39011923144212)
-   [How to Participate](#section19611528174215)
-   [License Agreement](#section1245517472115)
-   [Contact Info](#section61728335424)

## Introduction<a name="section1270210396435"></a>

OpenHarmony is an open-source project launched by the OpenAtom Foundation, and serves as an open-source, distributed operating system \(OS\) that is intended to address all conceivable usage scenarios.

Unlike traditional OSs, which are limited to a specific type of device, OpenHarmony provides distributed features that are compatible with a wide range of different devices. The first version supports devices with 128 KB to 128 MB of memory. Join us as we keep updating OpenHarmony versions. For device developers, OpenHarmony uses a component-based design to tailor its features to better suit specific devices, based on each device's capabilities and service characteristics. OpenHarmony can run on devices with limited resources and wearables with just a few hundred KBs of memory, as well as more powerful devices, such as smart home cameras and dashcams with hundreds of MB of memory.

## Technical Architecture<a name="section2502124574318"></a>

OpenHarmony is designed with a layered architecture, which from bottom to top, consists of the kernel layer, system service layer, framework layer, and application layer. System functions are expanded by levels, from system to subsystem, and further to function/module. In multi-device deployment scenario, unnecessary subsystems, functions, or modules can be excluded from the system as required. The following figure shows the technical architecture of OpenHarmony.

![](https://gitee.com/mibo_com/docs/blob/master/en/readme/figures/1-en.png)

**Kernel Layer**

-   Kernel subsystem: OpenHarmony uses a multi-kernel design \(Linux or LiteOS\) so that different kernels can be selected for devices with different resource limitations. The kernel abstraction layer \(KAL\) hides differences in kernel implementations and provides the upper layer with basic kernel capabilities, including process and thread management, memory management, file system, network management, and peripheral management.

-   Driver subsystem: Hardware Driver Foundation \(HDF\) lays the foundation for an open OpenHarmony hardware ecosystem. It allows for unified access from peripheral devices and provides foundation for driver development and management.


**System Service Layer**

The system service layer provides a complete set of capabilities essential for OpenHarmony to offer services for applications through the framework layer. This layer consists of the following parts:

-   Basic system capability subsystem set: Implements distributed application running, scheduling, and migration across OpenHarmony devices. This subsystem set provides the following basic capabilities: Intelligent Soft Bus, distributed data management, Distributed Scheduler, Utils, multimodal input, graphics, security, and AI.

-   Basic software service subsystem set: Provides OpenHarmony with common universal software services, including common event and notification, telephony, multimedia, and Design For X \(DFX\).

-   Enhanced software service subsystem set: Provides OpenHarmony with differentiated enhanced software services, including those dedicated to smart TVs, wearables, IoT devices, and more.

-   Hardware service subsystem set: Provides OpenHarmony with hardware services, including location, biometric recognition, as well as those dedicated to wearables and IoT devices.


The basic software service, enhanced software service, and hardware service subsystem sets can be modified by the subsystems, and each subsystem can be modified by various functions, depending on the deployment scenario for a particular device form.

**Framework layer**

This layer provides with what you need to develop OpenHarmony applications: application framework and ability framework, specific to multiple languages \(like Java, C, C++, and JS\), Java and JS UI frameworks, as well as multi-language APIs for hardware and software services. The APIs designed for different OpenHarmony devices can be modified based on various system components.

**Application layer**

This layer consists of system applications and third-party applications. Each OpenHarmony application is powered by one or more Feature Abilities \(FAs\) or Particle Abilities \(PA\). An FA provides a UI for user interaction. A PA has no UI and provides background task processing as well as data access. Applications developed based on FAs and PAs provide specific service characteristics and enable cross-device scheduling and distribution, delighting users with consistent and efficient experience.

## Technical Features<a name="section12212842173518"></a>

1.  **Hardware collaboration and resource sharing**

    This feature is implemented through the following modules:

    -   Intelligent Soft Bus

        Intelligent Soft Bus is a unified base for seamless interconnection among devices. It powers OpenHarmony with distributed communication capabilities to quickly discover and connect devices, and efficiently transmit data.


    -   Distributed data management

        Intelligent Soft Bus manages applications and user data distributed across different devices. Under such management, user data is no longer bound to a single physical device, and service logic is decoupled from storage. As your applications are running across devices, their data is seamlessly transmitted from one device to another, creating a foundation for a user experience that is smooth and consistent.


    -   Distributed Scheduler

        The Distributed Scheduler is designed based on technical features such as Intelligent Soft Bus, distributed data management, and distributed profile. It builds a unified distributed service management mechanism \(including service discovery, synchronization, registration, and invocation\), and supports remote startup, remote invocation, binding/unbinding, and migration of applications across devices. This way, your applications can select the most suitable device to perform distributed tasks based on the capabilities, locations, running status, and resource usage of different devices, as well as user habits and intentions.


    -   Device virtualization

        A distributed device virtualization platform enables cross-device resource convergence, device management, and data processing so that virtual peripherals can function as capability extensions of smartphones to form a super virtual terminal.


2.  **One-time development for multi-device deployment**

    OpenHarmony provides you with the user application, ability, and UI frameworks. With these frameworks, you can develop your applications once, and then flexibly deploy them across a broad range of different devices.

    Consistent APIs ensure the operational compatibility of applications across devices.

    -   Adaptation of device capabilities \(including CPU, memory, peripheral, and software resources\) can be previewed.
    -   Resources can be scheduled based on the compatibility between user applications and the software platform.

3.  **A unified OS for flexible deployment**

    OpenHarmony enables hardware resources to be scaled with its component-based and small-scale designs. It can be deployed on demand for a diverse range of devices, including ARM, RISC-V, and x86 architectures, and providing RAM volumes ranging from hundreds of KB to GB.


## Device Types<a name="section145241459142416"></a>

OpenHarmony supports the following device types:

-   **Mini-System Devices \(reference memory ≥ 128 KB\)**

    Such devices are equipped with MCU processors such as ARM Cortex-M and 32-bit RISC-V. They provide robust short-distance connection and peripheral bus access capabilities. Typical products include LinkIoT module devices and smart home sensors. The LinkIoT module is usually used as a hardware module that provides connectivity for smart Internet of Things \(IoT\) devices. In the smart home field, the LinkIoT module is integrated into devices by vendors. For example, a LinkIoT module provides WLAN/Bluetooth access and data connection, and it usually communicates with the chip of smart home devices via a universal asynchronous receiver-transmitter \(UART\) or general-purpose input/output \(GPIO\) interface.

-   **Small-System Devices \(reference memory ≥ 1 MB\)**

    Such devices are equipped with application processors such as ARM Cortex-A. They provide improved security, a standard graphics framework, and multimedia capabilities for video encoding and decoding. Typical products include smart home IP cameras, electronic cat eyes, and routers, and event data recorders \(EDRs\) for smart travel.


-   **Standard-System Devices \(reference memory ≥ 128 MB\)**

    Such devices are equipped with application processors such as ARM Cortex-A. They provide a complete application framework supporting enhanced interaction, 3D GPU, hardware composer, a diverse range of components and visual displays, for example the type included on a high-end refrigerator.

-   **Large-System Devices \(reference memory ≥ 1 GB\)**

    Such devices are equipped with application processors such as ARM Cortex-A and provide a complete compatible application framework. Typical products include smart TVs and smart watches.


## Subsystems<a name="section25831825174419"></a>

For details about the subsystems in the following table, see  [https://gitee.com/openharmony/docs/tree/master/zh-cn/readme](https://gitee.com/openharmony/docs/tree/master/zh-cn/readme).

\* The open-source OS, OpenHarmony, is available for devices running on just a few hundred KB to those with megabytes of RAM. The following table describes some of the subsystems.

<a name="table18981149155318"></a>
<table><thead align="left"><tr id="row69811925313"><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.4.1.1"><p id="p9143172718537"><a name="p9143172718537"></a><a name="p9143172718537"></a>Subsystem</p>
</th>
<th class="cellrowborder" valign="top" width="75%" id="mcps1.1.4.1.2"><p id="p6143122775319"><a name="p6143122775319"></a><a name="p6143122775319"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="12%" id="mcps1.1.4.1.3"><p id="p914352775312"><a name="p914352775312"></a><a name="p914352775312"></a>Link</p>
</th>
</tr>
</thead>
<tbody><tr id="row4981119185313"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p449919917515"><a name="p449919917515"></a><a name="p449919917515"></a>JS application framework</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p849919919515"><a name="p849919919515"></a><a name="p849919919515"></a>The JS application framework allows you to develop web-like applications across platforms. The framework uses Toolkit to pack your <strong id="b95377594542"><a name="b95377594542"></a><a name="b95377594542"></a>.html</strong>, <strong id="b35431059185412"><a name="b35431059185412"></a><a name="b35431059185412"></a>.css</strong>, and <strong id="b16543195915545"><a name="b16543195915545"></a><a name="b16543195915545"></a>.js</strong> files into a JavaScript bundle, parses the bundle, and renders it with view components of the C++ UIKit. Developers can use the declarative APIs to develop applications. This allows data to drive view changes and significantly reduces the number of view operations required, which greatly simplifies application development.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p1249916913512"><a name="p1249916913512"></a><a name="p1249916913512"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/js-application-framework.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row119815917532"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p449949135118"><a name="p449949135118"></a><a name="p449949135118"></a>DFX</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p94996915112"><a name="p94996915112"></a><a name="p94996915112"></a>Component-based, customizable DFX frameworks are required for different hardware architectures and resources. Two types of lightweight DFX frameworks (mini and featured) are available for hardware platforms powered by RISC-V, Cortex-M, and Cortex-A.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p1749949125113"><a name="p1749949125113"></a><a name="p1749949125113"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/dfx.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1698219916532"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p249920955119"><a name="p249920955119"></a><a name="p249920955119"></a>XTS</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p1149917935119"><a name="p1149917935119"></a><a name="p1149917935119"></a>X Test Suite (XTS) is a set of OpenHarmony certification test suites, including the currently supported application compatibility test suite (ACTS) and the device compatibility test suite (DCTS) that will be supported in the future.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p2049959175117"><a name="p2049959175117"></a><a name="p2049959175117"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/x-test-suite-certification-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1998212985315"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p349919910512"><a name="p349919910512"></a><a name="p349919910512"></a>Globalization</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p114999919515"><a name="p114999919515"></a><a name="p114999919515"></a>The globalization subsystem provides the bottom-layer resource backtracking and multi-language preference capabilities.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p194991191514"><a name="p194991191514"></a><a name="p194991191514"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/globalization-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1398249165320"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p104991999518"><a name="p104991999518"></a><a name="p104991999518"></a>Utils</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p24999919512"><a name="p24999919512"></a><a name="p24999919512"></a>The Utils repository stores basic components of OpenHarmony. These basic components are used by OpenHarmony subsystems and upper-layer applications.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p64991955113"><a name="p64991955113"></a><a name="p64991955113"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/utils-library.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row209823955313"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p94991894516"><a name="p94991894516"></a><a name="p94991894516"></a>Kernel</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p1049912975117"><a name="p1049912975117"></a><a name="p1049912975117"></a>The OpenHarmony kernel is a real-time OS kernel for IoT devices and is as lightweight as an RTOS and as easy-to-use as Linux. It provides basic kernel functions such as process and thread scheduling, memory management, the IPC mechanism, and timer management.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p150012975117"><a name="p150012975117"></a><a name="p150012975117"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/kernel-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1982159115313"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p4500199155118"><a name="p4500199155118"></a><a name="p4500199155118"></a>Distributed Scheduler</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p5500179195113"><a name="p5500179195113"></a><a name="p5500179195113"></a>The Distributed Scheduler is used for cross-device component management. It allows the local device to access or control remote components, and enables application collaboration in distributed scenarios.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p250069165113"><a name="p250069165113"></a><a name="p250069165113"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/distributed-scheduler.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row998219914538"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p1750089155114"><a name="p1750089155114"></a><a name="p1750089155114"></a>Intelligent Soft Bus</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p750014918518"><a name="p750014918518"></a><a name="p750014918518"></a>Intelligent Soft Bus manages unified distributed communication between near-field devices and provides device discovery and data transmission APIs that apply to all links. It also provides functions such as service publishing, data transmission, and security assurance.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p145004913511"><a name="p145004913511"></a><a name="p145004913511"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/distributed-communication-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row89839920531"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p1050018915515"><a name="p1050018915515"></a><a name="p1050018915515"></a>Startup</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p1500792519"><a name="p1500792519"></a><a name="p1500792519"></a>The startup subsystem is responsible for starting the operating system middle layer between the time the kernel is started and the time applications are started. This module can be used on the Hi3516D V300 and Hi3518E V300 platforms powered by LiteOS Cortex-A.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p55001891518"><a name="p55001891518"></a><a name="p55001891518"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/startup.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1598389185315"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p10500494514"><a name="p10500494514"></a><a name="p10500494514"></a>Graphics</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p195003975118"><a name="p195003975118"></a><a name="p195003975118"></a>The graphics subsystem mainly consists of user interface (UI) components, layout, animator, font, input event, window management, rendering and drawing modules. It is an application framework built on the LiteOS to develop OpenHarmony applications on Internet of Things (IoT) devices with limited hardware resources.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p135001912510"><a name="p135001912510"></a><a name="p135001912510"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/graphics-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row179834916539"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p4501199135114"><a name="p4501199135114"></a><a name="p4501199135114"></a>Multimedia</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p1850179125115"><a name="p1850179125115"></a><a name="p1850179125115"></a>The multimedia subsystem provides unified interfaces for you to develop media applications. With this subsystem, you can easily obtain media resources and stay focused on service development.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p150112917512"><a name="p150112917512"></a><a name="p150112917512"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/media-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row1698317918532"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p750110995113"><a name="p750110995113"></a><a name="p750110995113"></a>Security</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p1750113915514"><a name="p1750113915514"></a><a name="p1750113915514"></a>The security subsystem provides samples about how to use existing security mechanisms to improve system security features, including secure boot, application permission management, inter-process communication (IPC) authentication, Huawei Universal Keystore Service (HUKS), HiChain, and application signature verification.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p350117985114"><a name="p350117985114"></a><a name="p350117985114"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/security-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row198318945311"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p25014935113"><a name="p25014935113"></a><a name="p25014935113"></a>Testing</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p1950149205111"><a name="p1950149205111"></a><a name="p1950149205111"></a>The development process is tset driven. You can develop new cases or modify existing cases to test new or enhanced system features. The test helps you develop high-quality code in the development phase.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p450117935113"><a name="p450117935113"></a><a name="p450117935113"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/testing-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row99837975315"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p105011198515"><a name="p105011198515"></a><a name="p105011198515"></a>Application framework</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p1550118911517"><a name="p1550118911517"></a><a name="p1550118911517"></a>The application framework of OpenHarmony consists of two modules: ability management framework and bundle management framework. The ability management framework is provided by OpenHarmony for you to develop OpenHarmony applications. The bundle management framework is provided by OpenHarmony for you to manage application bundles.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p19501129145117"><a name="p19501129145117"></a><a name="p19501129145117"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/application-framework.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row098416935318"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p75011893510"><a name="p75011893510"></a><a name="p75011893510"></a>AI</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p105013910511"><a name="p105013910511"></a><a name="p105013910511"></a>The AI subsystem is the part of OpenHarmony that provides native distributed AI capabilities. At the heart of the subsystem is a unified AI engine framework, which implements quick integration of AI algorithm plug-ins. The framework consists of the plug-in management, module management, and communication management modules, fulfilling lifecycle management and on-demand deployment of AI algorithms. Under this framework, AI algorithm APIs will be standardized to facilitate distributed calling of AI capabilities. In addition, unified inference APIs will be provided to adapt to different inference framework hierarchies.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p6501097519"><a name="p6501097519"></a><a name="p6501097519"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/AI业务子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row11522144014127"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p850119145113"><a name="p850119145113"></a><a name="p850119145113"></a>Pan-sensor</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p1250116914516"><a name="p1250116914516"></a><a name="p1250116914516"></a>The pan-sensor subsystem contains sensors and misc devices. A sensor is a device to detect events or changes in an environment and send messages about the events or changes to another electronic device. Misc devices, including vibrators and LED lights, are used to send signals externally. You can call APIs to control the vibration of vibrators and lighting-on and lighting-off of LED lights.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p145027935115"><a name="p145027935115"></a><a name="p145027935115"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/泛Sensor子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row6966123741719"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p1502159165116"><a name="p1502159165116"></a><a name="p1502159165116"></a>Power management</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p050219175120"><a name="p050219175120"></a><a name="p050219175120"></a>The power management subsystem provides capabilities such as querying the battery charging/discharging status and managing the system power. Currently, available capabilities include querying the battery level and keeping the device screen always on.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p20502119175116"><a name="p20502119175116"></a><a name="p20502119175116"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/轻量级电源管理子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row163116577176"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p185021915120"><a name="p185021915120"></a><a name="p185021915120"></a>Update</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p45028945119"><a name="p45028945119"></a><a name="p45028945119"></a>The update subsystem provides Over the Air (OTA) updates. Currently, only full package updates are supported. A full package contains all the content of a new system.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p1550214965119"><a name="p1550214965119"></a><a name="p1550214965119"></a><a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/升级服务子系统.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row99841913538"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p35025985115"><a name="p35025985115"></a><a name="p35025985115"></a>Compilation and building</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p15414928193319"><a name="p15414928193319"></a><a name="p15414928193319"></a>The compilation and building subsystem provides a framework based on Generate Ninja (GN) and Ninja. The following functions are supported:</p>
<a name="ul1427216420331"></a><a name="ul1427216420331"></a><ul id="ul1427216420331"><li>Building products based on different chipset platforms. For example, you can build IP camera products on the Hi3518E V300 and Hi3516D V300 development boards and WLAN module product on the Hi3861 development boards.</li><li>Building a customized product that is generated according to HarmonyOS Package Manager (HPM) configurations.</li></ul>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p18502179115118"><a name="p18502179115118"></a><a name="p18502179115118"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/compilation-and-building-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
<tr id="row199841792533"><td class="cellrowborder" align="left" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="p1350214995113"><a name="p1350214995113"></a><a name="p1350214995113"></a>Driver</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="75%" headers="mcps1.1.4.1.2 "><p id="p8502149175110"><a name="p8502149175110"></a><a name="p8502149175110"></a>The OpenHarmony driver subsystem is constructed using the C object-oriented programming (OOP). It provides a unified driver platform through platform decoupling, kernel decoupling, and compatible kernels. This unified driver architecture platform is designed to provide a more precise and efficient development environment, where you develop a driver that can be deployed on different systems supporting Hardware Driver Foundation (HDF).</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="12%" headers="mcps1.1.4.1.3 "><p id="p1750210965118"><a name="p1750210965118"></a><a name="p1750210965118"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/readme/driver-subsystem.md" target="_blank" rel="noopener noreferrer">README</a></p>
</td>
</tr>
</tbody>
</table>

## Getting Started<a name="section44681652104210"></a>

For details, see  [https://gitee.com/openharmony/docs/blob/master/en/device-dev/quick-start/Readme-EN.md](https://gitee.com/openharmony/docs/blob/master/en/device-dev/quick-start/Readme-EN.md).

<a name="table783094717597"></a>
<table><thead align="left"><tr id="row19831154715595"><th class="cellrowborder" valign="top" width="13.861386138613863%" id="mcps1.1.4.1.1"><p id="p10268195211411"><a name="p10268195211411"></a><a name="p10268195211411"></a>Development board</p>
</th>
<th class="cellrowborder" valign="top" width="76.03760376037604%" id="mcps1.1.4.1.2"><p id="p7268165244115"><a name="p7268165244115"></a><a name="p7268165244115"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="10.101010101010102%" id="mcps1.1.4.1.3"><p id="p426845294110"><a name="p426845294110"></a><a name="p426845294110"></a>Link</p>
</th>
</tr>
</thead>
<tbody><tr id="row14831174716590"><td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.4.1.1 "><p id="p119624458418"><a name="p119624458418"></a><a name="p119624458418"></a>Hi3861 development board</p>
</td>
<td class="cellrowborder" valign="top" width="76.03760376037604%" headers="mcps1.1.4.1.2 "><p id="p7962114519415"><a name="p7962114519415"></a><a name="p7962114519415"></a>The Hi3861 WLAN module is a 2 x 5 cm development board. It is a 2.4 GHz WLAN SoC chip that highly integrates the IEEE 802.11b/g/n baseband and radio frequency (RF) circuit. This module is compatible with OpenHarmony, Huawei LiteOS, and third-party components.</p>
</td>
<td class="cellrowborder" valign="top" width="10.101010101010102%" headers="mcps1.1.4.1.3 "><p id="p7963045154116"><a name="p7963045154116"></a><a name="p7963045154116"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/device-dev/quick-start/hi3861-development-board.md" target="_blank" rel="noopener noreferrer">Getting Started</a></p>
</td>
</tr>
<tr id="row58311547175915"><td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.4.1.1 "><p id="p896334514411"><a name="p896334514411"></a><a name="p896334514411"></a>Hi3516 development board</p>
</td>
<td class="cellrowborder" valign="top" width="76.03760376037604%" headers="mcps1.1.4.1.2 "><p id="p18963104514115"><a name="p18963104514115"></a><a name="p18963104514115"></a>Hi3516D V300 is a next-generation system on chip (SoC) designed for the industry-dedicated smart HD IP camera. It introduces a next-generation image signal processor (ISP), the latest H.265 video compression encoder, and a high-performance NNIE engine.</p>
</td>
<td class="cellrowborder" valign="top" width="10.101010101010102%" headers="mcps1.1.4.1.3 "><p id="p2963545124111"><a name="p2963545124111"></a><a name="p2963545124111"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/device-dev/quick-start/hi3516-development-board.md" target="_blank" rel="noopener noreferrer">Getting Started</a></p>
</td>
</tr>
<tr id="row28310478595"><td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.4.1.1 "><p id="p296304510417"><a name="p296304510417"></a><a name="p296304510417"></a>Hi3518 development board</p>
</td>
<td class="cellrowborder" valign="top" width="76.03760376037604%" headers="mcps1.1.4.1.2 "><p id="p149631545114114"><a name="p149631545114114"></a><a name="p149631545114114"></a>Hi3518E V300 is a next-generation system on chip (SoC) designed for the industry-dedicated smart HD IP camera. It introduces a next-generation image signal processor (ISP) and the latest H.265 video compression encoder.</p>
</td>
<td class="cellrowborder" valign="top" width="10.101010101010102%" headers="mcps1.1.4.1.3 "><p id="p4963104516411"><a name="p4963104516411"></a><a name="p4963104516411"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/device-dev/quick-start/hi3518-development-board.md" target="_blank" rel="noopener noreferrer">Getting Started</a></p>
</td>
</tr>
</tbody>
</table>

## OpenHarmony Documentation<a name="section21031470109"></a>

[Chinese version](https://gitee.com/openharmony/docs/blob/master/Readme-zh-cn.md)

[English version](https://gitee.com/openharmony/docs/blob/master/Readme-en.md)

## Source Code Downloading<a name="section39011923144212"></a>

For details about how to obtain the source code of OpenHarmony, see  [Source Code Acquisition](https://gitee.com/openharmony/docs/blob/master/en/device-dev/get-code/source-code-acquisition.md).

## How to Participate<a name="section19611528174215"></a>

For details about how to join in the OpenHarmony community, see  [OpenHarmony Community](https://gitee.com/openharmony/community/blob/master/README.md).

For details about how to contribute, see  [Contribution](https://gitee.com/openharmony/docs/blob/master/en/contribute/contribution.md).

## License Agreement<a name="section1245517472115"></a>

OpenHarmony is open-source. For details, see the LICENSE in each repository.

## Contact Info<a name="section61728335424"></a>

Website:

[https://openharmony.gitee.com](https://openharmony.gitee.com/)

Email:

contact@openharmony.io

