# Overview<a name="EN-US_TOPIC_0000001152533331"></a>

-   [System Types](#section767218232110)
-   [Document Outline](#section19810171681218)

This topic provides a panorama of all documents for you to obtain helpful information quickly. These documents are classified based on your learning progress and development scenarios of OpenHarmony.

## System Types<a name="section767218232110"></a>

It is good practice to understand the system types for you to find useful documents that can guide your development.

OpenHarmony is an open-source distributed operating system for all scenarios. It uses a component-based design to tailor its features to better suit devices with 128 KiB to GiB-level of RAM. You can integrate a flexible combination of system components based on the hardware capabilities of the device.

To make the integration simple and easy on different hardware, OpenHarmony defines three basic system types. You only need to select a suitable system type and configure the mandatory component set, thereby developing a system for your device at the minimum workload. The definitions of the basic system types are provided as follows for your reference:

-   Mini system

    A mini system runs on the devices whose memory is greater than or equal to 128 KiB and that are equipped with MCU processors such as Arm Cortex-M and 32-bit RISC-V. This system provides multiple lightweight network protocols and graphics frameworks, and a wide range of read/write components for the IoT bus. Typical products include connection modules, sensors, and wearables for smart home.

-   Small system

    A small system runs on the devices whose memory is greater than or equal to 1 MiB and that are equipped with application processors such as Arm Cortex-A. This system provides higher security capabilities, standard graphics frameworks, and video encoding and decoding capabilities. Typical products include smart home IP cameras, electronic cat eyes, and routers, and event data recorders \(EDRs\) for smart travel.

-   Standard system

    A standard system runs on the devices whose memory is greater than or equal to 128 MiB and that are equipped with application processors such as ARM Cortex-A. This system provides a complete application framework supporting the enhanced interaction, 3D GPU, hardware composer, diverse components, and rich animations. This system applies to high-end refrigerator displays.


In addition, OpenHarmony provides a series of optional system components that can be configured as required to support feature extension and customization. These system components are combined to form a series of system capabilities that, for better understanding, are described as features or functions for you to choose.

## Document Outline<a name="section19810171681218"></a>

**Table  1**  Documents outlined based on the learning progress and development scenarios

<a name="table12124241175"></a>
<table><thead align="left"><tr id="row1021316249176"><th class="cellrowborder" valign="top" width="27.872787278727873%" id="mcps1.2.4.1.1"><p id="p162131124191710"><a name="p162131124191710"></a><a name="p162131124191710"></a>Topic</p>
</th>
<th class="cellrowborder" valign="top" width="38.54385438543855%" id="mcps1.2.4.1.2"><p id="p721310243170"><a name="p721310243170"></a><a name="p721310243170"></a>Development Scenario</p>
</th>
<th class="cellrowborder" valign="top" width="33.58335833583358%" id="mcps1.2.4.1.3"><p id="p15213192431712"><a name="p15213192431712"></a><a name="p15213192431712"></a>Documents</p>
</th>
</tr>
</thead>
<tbody><tr id="row82139245176"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p021372418175"><a name="p021372418175"></a><a name="p021372418175"></a>About <span id="text64714522207"><a name="text64714522207"></a><a name="text64714522207"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="38.54385438543855%" headers="mcps1.2.4.1.2 "><p id="p6213142414179"><a name="p6213142414179"></a><a name="p6213142414179"></a>Getting familiar with <span id="text9808161615252"><a name="text9808161615252"></a><a name="text9808161615252"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="33.58335833583358%" headers="mcps1.2.4.1.3 "><a name="ul1979224313222"></a><a name="ul1979224313222"></a><ul id="ul1979224313222"><li><a href="https://gitee.com/openharmony" target="_blank" rel="noopener noreferrer">About OpenHarmony</a></li><li><a href="../glossary/glossary.md">Glossary</a></li></ul>
</td>
</tr>
<tr id="row124015595011"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p132401950505"><a name="p132401950505"></a><a name="p132401950505"></a>Development resources</p>
</td>
<td class="cellrowborder" valign="top" width="38.54385438543855%" headers="mcps1.2.4.1.2 "><p id="p724015515504"><a name="p724015515504"></a><a name="p724015515504"></a>Preparing for your development</p>
</td>
<td class="cellrowborder" valign="top" width="33.58335833583358%" headers="mcps1.2.4.1.3 "><a name="ul13903204717506"></a><a name="ul13903204717506"></a><ul id="ul13903204717506"><li><a href="../get-code/source-code-acquisition.md">Source Code Acquisition</a></li><li><a href="../get-code/tool-acquisition.md">Acquiring Tools</a></li></ul>
</td>
</tr>
<tr id="row11213142451711"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p18213172414174"><a name="p18213172414174"></a><a name="p18213172414174"></a>Quick start</p>
</td>
<td class="cellrowborder" valign="top" width="38.54385438543855%" headers="mcps1.2.4.1.2 "><p id="p3213132491711"><a name="p3213132491711"></a><a name="p3213132491711"></a>Getting started with setup, build, burning, debugging, and running of <span id="text203751321355"><a name="text203751321355"></a><a name="text203751321355"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="33.58335833583358%" headers="mcps1.2.4.1.3 "><a name="ul1222811151378"></a><a name="ul1222811151378"></a><ul id="ul1222811151378"><li><a href="overview-0.md">Getting Started for Mini and Small Systems</a></li><li><a href="overview-7.md">Getting Started for Standard System</a></li></ul>
</td>
</tr>
<tr id="row421315248178"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p0213724191718"><a name="p0213724191718"></a><a name="p0213724191718"></a>Basic capabilities</p>
</td>
<td class="cellrowborder" valign="top" width="38.54385438543855%" headers="mcps1.2.4.1.2 "><p id="p6214112417173"><a name="p6214112417173"></a><a name="p6214112417173"></a>Using basic capabilities of <span id="text8928941123820"><a name="text8928941123820"></a><a name="text8928941123820"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="33.58335833583358%" headers="mcps1.2.4.1.3 "><a name="ul1293915133917"></a><a name="ul1293915133917"></a><ul id="ul1293915133917"><li><a href="../kernel/Readme-EN.md">Kernel</a></li><li><a href="../driver/Readme-EN.md">HDF</a></li><li><a href="../subsystems/Readme-EN.md">Subsystems</a></li><li><a href="../security/security-guidelines.md">Security Guidelines</a></li><li><a href="../security/privacy-protection.md">Privacy Protection</a></li></ul>
</td>
</tr>
<tr id="row14214122410178"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p162142242175"><a name="p162142242175"></a><a name="p162142242175"></a>Advanced development</p>
</td>
<td class="cellrowborder" valign="top" width="38.54385438543855%" headers="mcps1.2.4.1.2 "><p id="p12214624171719"><a name="p12214624171719"></a><a name="p12214624171719"></a>Developing smart devices based on system capabilities</p>
</td>
<td class="cellrowborder" valign="top" width="33.58335833583358%" headers="mcps1.2.4.1.3 "><a name="ul151291418444"></a><a name="ul151291418444"></a><ul id="ul151291418444"><li><a href="../guide/led-peripheral-control.md">LED Peripheral Control</a></li><li><a href="../guide/screen-and-camera-control.md">Screen and Camera Control</a></li><li><a href="../guide/visual-application-development.md"> Development Example for Visual Apps (AirQuality)</a></li><li><a href="../guide/development-example-for-clock-apps.md">Development Example for Clock Apps</a></li><li><a href="../guide/development-example-for-platform-drivers.md">Development Example for Platform Drivers</a></li><li><a href="../guide/development-example-for-peripheral-drivers.md">Development Example for Peripheral Drivers</a></li></ul>
</td>
</tr>
<tr id="row2021462441719"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p521402416177"><a name="p521402416177"></a><a name="p521402416177"></a>Porting and adaptation</p>
</td>
<td class="cellrowborder" valign="top" width="38.54385438543855%" headers="mcps1.2.4.1.2 "><a name="ul151441577479"></a><a name="ul151441577479"></a><ul id="ul151441577479"><li>Porting and adapting the <span id="text1415622205014"><a name="text1415622205014"></a><a name="text1415622205014"></a>OpenHarmony</span> to an SoC</li><li>Porting and adapting the <span id="text82061719165013"><a name="text82061719165013"></a><a name="text82061719165013"></a>OpenHarmony</span> to a third-party library</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.58335833583358%" headers="mcps1.2.4.1.3 "><a name="ul49839175470"></a><a name="ul49839175470"></a><ul id="ul49839175470"><li><a href="../porting/third-party-soc-porting-guide.md" target="_blank" rel="noopener noreferrer">Third-Party SoC Porting Guide</a></li><li><a href="../porting/third-party-library-porting-guide.md">Third-Party Library Porting Guide</a></li></ul>
</td>
</tr>
<tr id="row321442419177"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p102149240175"><a name="p102149240175"></a><a name="p102149240175"></a>Contributing components</p>
</td>
<td class="cellrowborder" valign="top" width="38.54385438543855%" headers="mcps1.2.4.1.2 "><p id="p12142024151711"><a name="p12142024151711"></a><a name="p12142024151711"></a>Contributing components to <span id="text207913212498"><a name="text207913212498"></a><a name="text207913212498"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="33.58335833583358%" headers="mcps1.2.4.1.3 "><a name="ul1675715272499"></a><a name="ul1675715272499"></a><ul id="ul1675715272499"><li><a href="../bundles/development-specifications.md">Component Development Specifications</a></li><li><a href="../bundles/development-guidelines.md">Component Development Guidelines</a></li><li><a href="../bundles/hpm-user-guide.md">HPM User Guide</a></li></ul>
</td>
</tr>
<tr id="row1621492419178"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p10214172414173"><a name="p10214172414173"></a><a name="p10214172414173"></a>Reference</p>
</td>
<td class="cellrowborder" valign="top" width="38.54385438543855%" headers="mcps1.2.4.1.2 "><p id="p122140244172"><a name="p122140244172"></a><a name="p122140244172"></a>Referring to development specifications</p>
</td>
<td class="cellrowborder" valign="top" width="33.58335833583358%" headers="mcps1.2.4.1.3 "><a name="ul14961914175515"></a><a name="ul14961914175515"></a><ul id="ul14961914175515"><li><a href="https://device.harmonyos.com/en/docs/develop/apiref/js-framework-file-0000000000611396" target="_blank" rel="noopener noreferrer">API References</a></li></ul>
</td>
</tr>
</tbody>
</table>

