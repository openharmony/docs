# OpenHarmony

## Introduction<a name="section1270210396435"></a>

OpenHarmony is an open-source project incubated and operated by the OpenAtom Foundation. It is an open-source operating system with a framework and platform applicable to smart devices in all scenarios of a fully-connected world. It aims to promote the development of the Internet of Everything (IoE).

## Technical Architecture<a name="section2502124574318"></a>

OpenHarmony is designed with a layered architecture, which from bottom to top, consists of the kernel layer, system service layer, framework layer, and application layer. System functions are expanded by levels, from system to subsystem, and further to module. In a multi-device deployment scenario, unnecessary modules can be excluded from the system as required. The following figure shows the technical architecture of OpenHarmony.

![](figures/1.png)

**Kernel Layer**

-   Kernel subsystem: OpenHarmony uses a multi-kernel design \(Linux or LiteOS\) so that different kernels can be selected for devices with different resource limitations. The kernel abstraction layer \(KAL\) hides differences in kernel implementations and provides the upper layer with basic kernel capabilities, including process and thread management, memory management, file system, network management, and peripheral management.

-   Driver subsystem: Hardware Driver Foundation \(HDF\) lays the foundation for an open OpenHarmony hardware ecosystem. It allows for unified access from peripheral devices and provides foundation for driver development and management.


**System Service Layer**

The system service layer provides a complete set of capabilities essential for OpenHarmony to offer services for apps through the framework layer. This layer consists of the following parts:

-   Basic system capability subsystem set: Implements distributed app running, scheduling, and migration across OpenHarmony devices. This subsystem set provides the following basic capabilities: Intelligent Soft Bus, distributed data management, Distributed Scheduler, Utils, multimodal input, graphics, security, and AI.

-   Basic software service subsystem set: Provides OpenHarmony with common universal software services, including common event and notification, telephony, multimedia, and Design For X \(DFX\).

-   Enhanced software service subsystem set: Provides OpenHarmony with differentiated enhanced software services, including those dedicated to smart TVs, wearables, IoT devices, and more.

-   Hardware service subsystem set: Provides OpenHarmony with hardware services, including location, IAM, as well as those dedicated to wearables and IoT devices.


The basic software service, enhanced software service, and hardware service subsystem sets can be modified by the subsystems, and each subsystem can be modified by various functions, depending on the deployment scenario for a particular device form.

**Framework layer**

This layer provides with what you need to develop OpenHarmony apps: application framework and ability framework, specific to multiple languages \(like C, C++, and JS\), ArkUI framework, as well as multi-language APIs for hardware and software services. The APIs designed for different OpenHarmony devices can be modified based on various system components.

**Application layer**

This layer consists of system apps and third-party apps. Each OpenHarmony app is powered by one or more Feature Abilities \(FAs\) or Particle Abilities \(PAs\). An FA provides a UI for user interaction. A PA has no UI and provides background task processing as well as data access. Apps developed based on FAs and PAs provide specific service characteristics and enable cross-device scheduling and distribution, delighting users with consistent and efficient experience.

## Technical Features<a name="section12212842173518"></a>

1.  **Hardware collaboration and resource sharing**

    This feature is implemented through the following modules:

    -   Intelligent Soft Bus

        Intelligent Soft Bus is a unified base for seamless interconnection among devices. It powers OpenHarmony with distributed communication capabilities to quickly discover and connect devices, and efficiently transmit data.


    -   Distributed data management
    
        Intelligent Soft Bus manages apps and user data distributed across different devices. Under such management, user data is no longer bound to a single physical device, and service logic is decoupled from storage. As your apps are running across devices, their data is seamlessly transmitted from one device to another, creating a foundation for a user experience that is smooth and consistent.


    -   Distributed Scheduler
    
        The Distributed Scheduler is designed based on technical features such as Intelligent Soft Bus, distributed data management, and distributed profile. It builds a unified distributed service management mechanism \(including service discovery, synchronization, registration, and invocation\), and supports remote startup, remote invocation, binding/unbinding, and migration of apps across devices. This way, your app can select the most suitable device to perform distributed tasks based on the capabilities, locations, running status, and resource usage of different devices, as well as user habits and intentions.


    -   Device virtualization
    
        A distributed device virtualization platform enables cross-device resource convergence, device management, and data processing so that virtual peripherals can function as capability extensions of smartphones to form a super virtual terminal.


2.  **One-time development for multi-device deployment**

    OpenHarmony provides you with the user application, ability, and UI frameworks. With these frameworks, you can develop your apps once, and then flexibly deploy them across a broad range of different devices.

    Consistent APIs ensure the operational compatibility of apps across devices.

    -   Adaptation of device capabilities \(including CPU, memory, peripheral, and software resources\) can be previewed.
    -   Resources can be scheduled based on the compatibility between user apps and the software platform.

3.  **A unified OS for flexible deployment**

    OpenHarmony enables hardware resources to be scaled with its component-based and small-scale designs. It can be deployed on demand for a diverse range of devices, including ARM, RISC-V, and x86 architectures, and providing RAM volumes ranging from hundreds of KiB to GiB.


## OS Types<a name="section145241459142416"></a>

OpenHarmony supports the following types:

-   Mini system

    A mini system runs on the devices whose memory is greater than or equal to 128 KiB and that are equipped with MCU processors such as Arm Cortex-M and 32-bit RISC-V. This system provides multiple lightweight network protocols and graphics frameworks, and a wide range of read/write components for the IoT bus. Typical products include connection modules, sensors, and wearables for smart home.

-   Small system

    A small system runs on the devices whose memory is greater than or equal to 1 MiB and that are equipped with application processors such as Arm Cortex-A. This system provides higher security capabilities, standard graphics frameworks, and video encoding and decoding capabilities. Typical products include smart home IP cameras, electronic cat eyes, and routers, and event data recorders \(EDRs\) for smart travel.

-   Standard system

    A standard system runs on the devices whose memory is greater than or equal to 128 MiB and that are equipped with application processors such as ARM Cortex-A. This system provides a complete application framework supporting the enhanced interaction, 3D GPU, hardware composer, diverse components, and rich animations. This system applies to high-end refrigerator displays.


## Subsystems<a name="section25831825174419"></a>

You need to understand the following basic concepts related to OpenHarmony:

-   Subsystem

    OpenHarmony is designed with a layered architecture, which from bottom to top consists of the kernel layer, system service layer, framework layer, and application layer. System functions are expanded by levels, from system to subsystem, and further to module. In a multi-device deployment scenario, unnecessary modules can be excluded from the system as required. A subsystem is a logical concept and is a flexible combination of functions.

-   Module

    A module is a reusable software binary unit that contains source code, configuration files, resource files, and build scripts. A module can be built independently, integrated in binary mode, and then tested independently.


The following table describes the subsystems of OpenHarmony. For details about the readme files of these subsystems, see  [https://gitee.com/openharmony/docs/tree/master/en/readme](https://gitee.com/openharmony/docs/tree/master/en/readme).

<a name="table18981149155318"></a>
<table><thead align="left"><tr id="row69811925313"><th class="cellrowborder" valign="top" width="11.111111111111112%" id="mcps1.1.4.1.1"><p id="p9143172718537"><a name="p9143172718537"></a><a name="p9143172718537"></a>Subsystem</p>
</th>
<th class="cellrowborder" valign="top" width="80.80808080808082%" id="mcps1.1.4.1.2"><p id="p6143122775319"><a name="p6143122775319"></a><a name="p6143122775319"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="8.080808080808081%" id="mcps1.1.4.1.3"><p id="p36827655311"><a name="p36827655311"></a><a name="p36827655311"></a>Applicable To</p>
</th>
</tr>
</thead>
<tbody><tr id="row1746235812115"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p84622581117"><a name="p84622581117"></a><a name="p84622581117"></a>Kernel</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p34626584118"><a name="p34626584118"></a><a name="p34626584118"></a>Supports small-sized LiteOS kernels that provide high performance and low power consumption for embedded devices and devices with limited resources, and supports Linux kernels that are applicable to the standard system.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p31041221121"><a name="p31041221121"></a><a name="p31041221121"></a>Small system</p>
<p id="p16450192619121"><a name="p16450192619121"></a><a name="p16450192619121"></a>Standard system</p>
</td>
</tr>
<tr id="row4465751131114"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p12465145131117"><a name="p12465145131117"></a><a name="p12465145131117"></a>DFileSystem</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p1046615111118"><a name="p1046615111118"></a><a name="p1046615111118"></a>Provides APIs for synchronizing local JS files.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p15466135171117"><a name="p15466135171117"></a><a name="p15466135171117"></a>Standard system</p>
</td>
</tr>
<tr id="row14286184818110"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p1328654871112"><a name="p1328654871112"></a><a name="p1328654871112"></a>Graphics</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p15912684317"><a name="p15912684317"></a><a name="p15912684317"></a>Consists of user interface (UI) components, layout, animator, font, input event, window management, and rendering and drawing modules. It is an application framework that can be built on the LiteOS to develop OpenHarmony applications for Internet of Things (IoT) devices with limited hardware resources or on the standard OS to develop OpenHarmony applications for standard- and large-system devices (for example, tablet and lite smart devices).</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p228719483115"><a name="p228719483115"></a><a name="p228719483115"></a>All systems</p>
</td>
</tr>
<tr id="row4981119185313"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p43071335181312"><a name="p43071335181312"></a><a name="p43071335181312"></a>Driver</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p849919919515"><a name="p849919919515"></a><a name="p849919919515"></a>Constructed using the C object-oriented programming (OOP) language. It provides a unified driver platform and is compatible with different kernels by means of platform decoupling and kernel decoupling. This unified driver platform is designed to provide a more precise and efficient development environment, where you develop a driver that can be deployed on different systems supporting Hardware Driver Foundation (HDF).</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p7909102101420"><a name="p7909102101420"></a><a name="p7909102101420"></a>All systems</p>
</td>
</tr>
<tr id="row1698219916532"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p183071635131320"><a name="p183071635131320"></a><a name="p183071635131320"></a>Power Management</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p1534121801513"><a name="p1534121801513"></a><a name="p1534121801513"></a>Provides the following functions: restarting the system, managing running locks, managing and querying the system power status, querying and reporting the charging and battery status, and turning on/off the device screen, including adjusting the screen brightness.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p0562145615152"><a name="p0562145615152"></a><a name="p0562145615152"></a>Standard system</p>
</td>
</tr>
<tr id="row1998212985315"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p1230718353132"><a name="p1230718353132"></a><a name="p1230718353132"></a>Pan-sensor</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p114999919515"><a name="p114999919515"></a><a name="p114999919515"></a>Contains sensors and misc devices. A sensor is a device to detect events or changes in an environment and send messages about the events or changes to another electronic device. Misc devices, including vibrators and LED lights, are used to send signals externally. You can call APIs to control the vibration of vibrators and lighting-on and lighting-off of LED lights.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p7683136135317"><a name="p7683136135317"></a><a name="p7683136135317"></a>Small system</p>
</td>
</tr>
<tr id="row1398249165320"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p1930743511318"><a name="p1930743511318"></a><a name="p1930743511318"></a>Multimodal Input</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p13832172015162"><a name="p13832172015162"></a><a name="p13832172015162"></a>OpenHarmony provides a Natural User Interface (NUI) for you to interact with your users. Unlike conventional categorization of input methods, OpenHarmony combines input methods of different dimensions into multimodal inputs, so you can easily arm your app with multi-dimensional, natural interaction features by using the application framework and system built-in UI components or APIs. Specifically, OpenHarmony currently supports traditional input methods such as key and touch inputs.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p025515141075"><a name="p025515141075"></a><a name="p025515141075"></a>Standard system</p>
</td>
</tr>
<tr id="row209823955313"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p1030711354137"><a name="p1030711354137"></a><a name="p1030711354137"></a>Startup</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p54461340151820"><a name="p54461340151820"></a><a name="p54461340151820"></a>Starts the OS middle layer between the time the kernel is started and the time apps are started. In addition, you can query and modify system attributes and restore factory settings.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p8683362533"><a name="p8683362533"></a><a name="p8683362533"></a>All systems</p>
</td>
</tr>
<tr id="row1982159115313"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p14307173571315"><a name="p14307173571315"></a><a name="p14307173571315"></a>Update</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p887484183"><a name="p887484183"></a><a name="p887484183"></a>Supports over the air (OTA) update of OpenHarmony devices.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p10550164995117"><a name="p10550164995117"></a><a name="p10550164995117"></a>Standard system</p>
</td>
</tr>
<tr id="row89839920531"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p123071435151319"><a name="p123071435151319"></a><a name="p123071435151319"></a>Account</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p2772313127"><a name="p2772313127"></a><a name="p2772313127"></a>Provides interconnection with vendors' cloud account apps on the device side, and query and update of the cloud account login status.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p19928023151913"><a name="p19928023151913"></a><a name="p19928023151913"></a>Standard system</p>
</td>
</tr>
<tr id="row1598389185315"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p11473102882017"><a name="p11473102882017"></a><a name="p11473102882017"></a>Compilation and Building</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p22956349202"><a name="p22956349202"></a><a name="p22956349202"></a>Provides a compilation and building framework based on Generate Ninja (GN) and Ninja.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p183114819179"><a name="p183114819179"></a><a name="p183114819179"></a>All systems</p>
</td>
</tr>
<tr id="row179834916539"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p1347382819202"><a name="p1347382819202"></a><a name="p1347382819202"></a>Testing</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p1850179125115"><a name="p1850179125115"></a><a name="p1850179125115"></a>The test-driven development mode is used during the development process. You can develop new cases or modify existing cases to test new or enhanced system features. The test helps you develop high-quality code in the development phase.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p15458348191719"><a name="p15458348191719"></a><a name="p15458348191719"></a>All systems</p>
</td>
</tr>
<tr id="row1698317918532"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p11473172817202"><a name="p11473172817202"></a><a name="p11473172817202"></a>Data Management</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p2030983518561"><a name="p2030983518561"></a><a name="p2030983518561"></a>Provides local data management and distributed data management:</p>
<a name="ul2727156145217"></a><a name="ul2727156145217"></a><ul id="ul2727156145217"><li>Local app data management for lightweight preference databases and relational databases</li><li>Distributed data service to provide apps with the capability to store data in the databases of different devices</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p193679548203"><a name="p193679548203"></a><a name="p193679548203"></a>Standard system</p>
</td>
</tr>
<tr id="row198318945311"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p14473132812018"><a name="p14473132812018"></a><a name="p14473132812018"></a>Programming Language Runtime</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p17753537218"><a name="p17753537218"></a><a name="p17753537218"></a>Provides the compilation and execution environment for programs developed with JavaScript or C/C++, basic libraries that support the runtime, and the runtime-associated APIs, compilers, and auxiliary tools.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p14593146192111"><a name="p14593146192111"></a><a name="p14593146192111"></a>All systems</p>
</td>
</tr>
<tr id="row098416935318"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p64731628132015"><a name="p64731628132015"></a><a name="p64731628132015"></a>Distributed Scheduler</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p55320348170"><a name="p55320348170"></a><a name="p55320348170"></a>Starts, registers, queries, and manages system services.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p76835611530"><a name="p76835611530"></a><a name="p76835611530"></a>All systems</p>
</td>
</tr>
<tr id="row11522144014127"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p847382818209"><a name="p847382818209"></a><a name="p847382818209"></a>JS UI framework</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p18885204913282"><a name="p18885204913282"></a><a name="p18885204913282"></a>OpenHarmony UI development framework that supports web-development-like paradigm.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p18278134513216"><a name="p18278134513216"></a><a name="p18278134513216"></a>All systems</p>
</td>
</tr>
<tr id="row163116577176"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p9473192862015"><a name="p9473192862015"></a><a name="p9473192862015"></a>Multimedia</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p17895171152211"><a name="p17895171152211"></a><a name="p17895171152211"></a>Provides easy-to-use APIs for developing multimedia components such as audio, video, and camera, and enables apps to use multimedia resources of the system.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p7683126105314"><a name="p7683126105314"></a><a name="p7683126105314"></a>All systems</p>
</td>
</tr>
<tr id="row99841913538"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p34736280204"><a name="p34736280204"></a><a name="p34736280204"></a>Event Notification</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p1328485917223"><a name="p1328485917223"></a><a name="p1328485917223"></a>Provides the common event management capabilities that allow apps to subscribe to, unsubscribe from, publish, and receive common events (such as screen-on/off events and USB device attachment/detachment events).</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p19305121815138"><a name="p19305121815138"></a><a name="p19305121815138"></a>Standard system</p>
</td>
</tr>
<tr id="row199841792533"><td class="cellrowborder" align="left" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p6473102817205"><a name="p6473102817205"></a><a name="p6473102817205"></a>Misc Services</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p8502149175110"><a name="p8502149175110"></a><a name="p8502149175110"></a>Provides the function of setting the time.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p1962012112314"><a name="p1962012112314"></a><a name="p1962012112314"></a>Standard system</p>
</td>
</tr>
<tr id="row176674368222"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p3667203652214"><a name="p3667203652214"></a><a name="p3667203652214"></a>Bundle management</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p12923326230"><a name="p12923326230"></a><a name="p12923326230"></a>Provides bundle installation, uninstallation, update, and query capabilities.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p12667123619226"><a name="p12667123619226"></a><a name="p12667123619226"></a>All systems</p>
</td>
</tr>
<tr id="row65111417226"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p612981114248"><a name="p612981114248"></a><a name="p612981114248"></a>Telephony</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p19521141152212"><a name="p19521141152212"></a><a name="p19521141152212"></a>Provides basic communication capabilities of the cellular network, such as SIM cards, network search, cellular data, cellular calls, SMS, and MMS, as well as easy-to-use APIs for you to manage multiple types of calls and data network connections.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p124681352134"><a name="p124681352134"></a><a name="p124681352134"></a>Standard system</p>
</td>
</tr>
<tr id="row10194183317227"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p14129311172416"><a name="p14129311172416"></a><a name="p14129311172416"></a>Utils</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p21941533132218"><a name="p21941533132218"></a><a name="p21941533132218"></a>Stores basic OpenHarmony components, which can be used by OpenHarmony subsystems and upper-layer apps.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p1219413311229"><a name="p1219413311229"></a><a name="p1219413311229"></a>All systems</p>
</td>
</tr>
<tr id="row9664349242"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p116653462411"><a name="p116653462411"></a><a name="p116653462411"></a>Development Tools</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p15701144517139"><a name="p15701144517139"></a><a name="p15701144517139"></a>Provides a performance profiler platform for you to analyze system issues such as memory and performance, including hdc used for device debugging, APIs for performance tracing, and a performance profiler framework.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p1696110251415"><a name="p1696110251415"></a><a name="p1696110251415"></a>Standard system</p>
</td>
</tr>
<tr id="row1449910380242"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p238324932415"><a name="p238324932415"></a><a name="p238324932415"></a>DSoftBus</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p17499153862420"><a name="p17499153862420"></a><a name="p17499153862420"></a>Provides cross-process or cross-device communication capabilities for the OpenHarmony system and consists of the DSoftBus and IPC modules. The DSoftBus module enables distributed communication between near-field devices and provides device discovery, connection, networking, and data transmission functions, regardless of the communication mode. The IPC module enables communication between processes on a device or across devices.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p5499183812418"><a name="p5499183812418"></a><a name="p5499183812418"></a>All systems</p>
</td>
</tr>
<tr id="row1733413367244"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p1238318490244"><a name="p1238318490244"></a><a name="p1238318490244"></a>XTS</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p2334113611248"><a name="p2334113611248"></a><a name="p2334113611248"></a>Provides a set of OpenHarmony compatibility test suites, including the currently supported application compatibility test suite (ACTS) and the device compatibility test suite (DCTS) that will be supported in the future.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p03341936102418"><a name="p03341936102418"></a><a name="p03341936102418"></a>All systems</p>
</td>
</tr>
<tr id="row1817163212413"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p53831049112416"><a name="p53831049112416"></a><a name="p53831049112416"></a>System Apps</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p91717327249"><a name="p91717327249"></a><a name="p91717327249"></a>Provides system apps that are applicable to the OpenHarmony standard system, such as Launcher, SystemUI, and Settings. It also provides specific examples for you to build standard-system apps, which can be installed on all devices running the standard system.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p10171133218245"><a name="p10171133218245"></a><a name="p10171133218245"></a>Standard system</p>
</td>
</tr>
<tr id="row3577428102418"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p93831496249"><a name="p93831496249"></a><a name="p93831496249"></a>DFX</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p8578828122413"><a name="p8578828122413"></a><a name="p8578828122413"></a>Provides non-functional capabilities of OpenHarmony. It provides a logging system, app and system event logging APIs, the event log subscription service, and fault information generation and collection capabilities.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p18578102822411"><a name="p18578102822411"></a><a name="p18578102822411"></a>All systems</p>
</td>
</tr>
<tr id="row418795214250"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p860151102616"><a name="p860151102616"></a><a name="p860151102616"></a>Globalization</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p41871252102515"><a name="p41871252102515"></a><a name="p41871252102515"></a>If OpenHarmony devices and apps need to be used globally, they must meet the requirements of users in different regions on languages and cultures. The Globalization subsystem provides multi-language and multi-cultural capabilities for global use, including resource management and internationalization (i18n).</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p201658544174"><a name="p201658544174"></a><a name="p201658544174"></a>All systems</p>
</td>
</tr>
<tr id="row16870124919255"><td class="cellrowborder" valign="top" width="11.111111111111112%" headers="mcps1.1.4.1.1 "><p id="p136021513265"><a name="p136021513265"></a><a name="p136021513265"></a>Security</p>
</td>
<td class="cellrowborder" valign="top" width="80.80808080808082%" headers="mcps1.1.4.1.2 "><p id="p2871134913255"><a name="p2871134913255"></a><a name="p2871134913255"></a>Provides system, data, and app security capabilities to protect system and user data of OpenHarmony. Its functions include app integrity verification, app permission management, device authentication, and key management.</p>
</td>
<td class="cellrowborder" valign="top" width="8.080808080808081%" headers="mcps1.1.4.1.3 "><p id="p1487113491251"><a name="p1487113491251"></a><a name="p1487113491251"></a>All systems</p>
</td>
</tr>
</tbody>
</table>

## Getting Started<a name="section44681652104210"></a>

- Device development: [device-dev/quick-start/Readme.md](device-dev/quick-start/Readme-EN.md)
- Application development: [application-dev/quick-start/Readme.md](application-dev/quick-start/Readme-EN.md)

- [Getting Started for Device Development](device-dev/quick-start/quickstart-lite-overview.md)
- [Getting Started for Application Development](application-dev/quick-start/start-overview.md)

## Code Repository Addresses<a name="section107651249181914"></a>

OpenHarmony project:  [https://gitee.com/openharmony](https://gitee.com/openharmony)

OpenHarmony SIG:  [https://gitee.com/openharmony-sig](https://gitee.com/openharmony-sig)

OpenHarmony third-party components:  [https://gitee.com/openharmony-tpc](https://gitee.com/openharmony-tpc)

OpenHarmony archived projects:  [https://gitee.com/openharmony-retired](https://gitee.com/openharmony-retired)

## OpenHarmony Documentation<a name="section21031470109"></a>

[Chinese version](https://gitee.com/openharmony/docs/blob/master/zh-cn/readme.md)

[English version](https://gitee.com/openharmony/docs/blob/master/en/readme.md)

## Source Code Downloading<a name="section39011923144212"></a>

For details about how to obtain the source code of OpenHarmony, see  [Source Code Acquisition](https://gitee.com/openharmony/docs/blob/master/en/device-dev/get-code/sourcecode-acquire.md).

## How to Participate<a name="section19611528174215"></a>

For details about how to join in the OpenHarmony community, see  [OpenHarmony Community](https://gitee.com/openharmony/community/blob/master/README.md).

For details about how to contribute, see  [Contribution](https://gitee.com/openharmony/docs/blob/master/en/contribute/contribution.md).

## License Agreement<a name="section1245517472115"></a>

OpenHarmony complies with Apache License Version 2.0. For details, see the LICENSE in each repository.

OpenHarmony uses third-party open-source software and licenses. For details, see  [Third-Party Open-Source Software](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/%E7%AC%AC%E4%B8%89%E6%96%B9%E5%BC%80%E6%BA%90%E8%BD%AF%E4%BB%B6%E5%8F%8A%E8%AE%B8%E5%8F%AF%E8%AF%81%E8%AF%B4%E6%98%8E.md).

## Contact Info<a name="section61728335424"></a>

Website:

[https://openharmony.gitee.com](https://openharmony.gitee.com/)

Email:

contact@openharmony.io
