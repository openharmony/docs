# Overview<a name="EN-US_TOPIC_0000001152533331"></a>

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

    A standard system runs on the devices whose memory is greater than or equal to 128 MiB and that are equipped with application processors such as Arm Cortex-A. This system provides a complete application framework supporting the enhanced interaction, 3D GPU, hardware composer, diverse components, and rich animations. This system applies to high-end refrigerator displays.


In addition, OpenHarmony provides a series of optional system components that can be configured as required to support feature extension and customization. These system components are combined to form a series of system capabilities that, for better understanding, are described as features or functions for you to choose.

## Document Outline<a name="section19810171681218"></a>

-   [Mini and Small System Development Guidelines](#table3762949121211)
-   [Standard System Development Guidelines](#table17667535516)

**Table  1**  Mini and small system development guidelines \(reference memory < 128 MB\)

<a name="table3762949121211"></a>
<table><thead align="left"><tr id="row18762649161218"><th class="cellrowborder" valign="top" width="28.472847284728473%" id="mcps1.2.4.1.1"><p id="p1750131161313"><a name="p1750131161313"></a><a name="p1750131161313"></a>Topic</p>
</th>
<th class="cellrowborder" valign="top" width="35.61356135613561%" id="mcps1.2.4.1.2"><p id="p8501411141319"><a name="p8501411141319"></a><a name="p8501411141319"></a>Development Scenario</p>
</th>
<th class="cellrowborder" valign="top" width="35.91359135913591%" id="mcps1.2.4.1.3"><p id="p050181111314"><a name="p050181111314"></a><a name="p050181111314"></a>Documents</p>
</th>
</tr>
</thead>
<tbody><tr id="row317979135310"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p119871717125320"><a name="p119871717125320"></a><a name="p119871717125320"></a>About <span id="text64714522207"><a name="text64714522207"></a><a name="text64714522207"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p14987151715312"><a name="p14987151715312"></a><a name="p14987151715312"></a>Getting familiar with <span id="text9808161615252"><a name="text9808161615252"></a><a name="text9808161615252"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul59871171533"></a><a name="ul59871171533"></a><ul id="ul59871171533"><li><a href="https://gitee.com/openharmony" target="_blank" rel="noopener noreferrer">About OpenHarmony</a></li><li><a href="glossary/glossary.md">Glossary</a></li></ul>
</td>
</tr>
<tr id="row69521557115217"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p69873174536"><a name="p69873174536"></a><a name="p69873174536"></a>Development resources</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p39871917185313"><a name="p39871917185313"></a><a name="p39871917185313"></a>Preparing for your development</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul59871117135314"></a><a name="ul59871117135314"></a><ul id="ul59871117135314"><li><a href="get-code/sourcecode-acquire.md">Obtaining Source Code</a></li><li><a href="get-code/gettools.md">Tool Acquisition</a></li></ul>
</td>
</tr>
<tr id="row11602937131510"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p457713717150"><a name="p457713717150"></a><a name="p457713717150"></a>Quick start</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p55771237111517"><a name="p55771237111517"></a><a name="p55771237111517"></a>Getting started with setup, build, burning, debugging, and running of <span id="text203751321355"><a name="text203751321355"></a><a name="text203751321355"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><p id="p10832159115410"><a name="p10832159115410"></a><a name="p10832159115410"></a><a href="quick-start/quickstart-lite.md">Mini and Small Systems</a></p>
</td>
</tr>
<tr id="row11602103701514"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p16577163716159"><a name="p16577163716159"></a><a name="p16577163716159"></a>Basic capabilities</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p857711379158"><a name="p857711379158"></a><a name="p857711379158"></a>Using basic capabilities of <span id="text8928941123820"><a name="text8928941123820"></a><a name="text8928941123820"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul1577103716159"></a><a name="ul1577103716159"></a><ul id="ul1577103716159"><li><a href="kernel/kernel-mini.md">Kernel for Mini Systems</a></li><li><a href="kernel/kernel-small.md">Kernel for Small Systems</a></li><li><a href="driver/Readme-EN.md">Drivers</a></li><li><a href="subsystems/Readme-EN.md">Subsystems</a></li><li><a href="security/security-guidelines-overall.md">Security Guidelines</a></li><li><a href="security/security-privacy-protection.md">Privacy Protection</a></li></ul>
</td>
</tr>
<tr id="row10602193719152"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p857873713152"><a name="p857873713152"></a><a name="p857873713152"></a>Advanced development</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p155782037201518"><a name="p155782037201518"></a><a name="p155782037201518"></a>Developing smart devices based on system capabilities</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul257883731519"></a><a name="ul257883731519"></a><ul id="ul257883731519"><li><a href="guide/device-wlan.md">WLAN-connected Products</a></li><li><a href="guide/device-iotcamera-control.md">Cameras Without a Screen</a></li><li><a href="guide/device-camera.md">Cameras with a Screen</a></li></ul>
</td>
</tr>
<tr id="row360273716155"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p12579163711513"><a name="p12579163711513"></a><a name="p12579163711513"></a>Porting and adaptation</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><a name="ul12579137121512"></a><a name="ul12579137121512"></a><ul id="ul12579137121512"><li>Porting and adapting the <span id="text1415622205014"><a name="text1415622205014"></a><a name="text1415622205014"></a>OpenHarmony</span> to an SoC</li><li>Porting and adapting the <span id="text82061719165013"><a name="text82061719165013"></a><a name="text82061719165013"></a>OpenHarmony</span> to a third-party library</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul157903731520"></a><a name="ul157903731520"></a><ul id="ul157903731520"><li><a href="porting/porting-minichip.md">Mini System SoC Porting Guide</a></li><li><a href="porting/porting-smallchip.md">Small System SoC Porting Guide</a></li><li><a href="porting/porting-thirdparty.md">Third-Party Library Porting Guide for Mini and Small Systems</a></li></ul>
</td>
</tr>
<tr id="row9601737181517"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p25791037131519"><a name="p25791037131519"></a><a name="p25791037131519"></a>Contributing components</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p45798376158"><a name="p45798376158"></a><a name="p45798376158"></a>Contributing components to <span id="text207913212498"><a name="text207913212498"></a><a name="text207913212498"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul957919379156"></a><a name="ul957919379156"></a><ul id="ul957919379156"><li><a href="hpm-part/hpm-part-about.md">HPM Part Overview</a></li><li><a href="hpm-part/hpm-part-development.md">HPM Part Development</a></li><li><a href="hpm-part/hpm-part-reference.md">HPM Part Reference</a></li></ul>
</td>
</tr>
<tr id="row260193701512"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p95794372155"><a name="p95794372155"></a><a name="p95794372155"></a>Reference</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p458073721519"><a name="p458073721519"></a><a name="p458073721519"></a>Referring to development specifications</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul175808372155"></a><a name="ul175808372155"></a><ul id="ul175808372155"><li><a href="https://device.harmonyos.com/en/docs/apiref/js-framework-file-0000000000616658" target="_blank" rel="noopener noreferrer">API References</a></li><li><a href="faqs/Readme-EN.md" target="_blank" rel="noopener noreferrer">FAQs</a></li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2**  Standard system development guidelines \(reference memory ≥ 128 MB\)

<a name="table17667535516"></a>
<table><thead align="left"><tr id="row206665375119"><th class="cellrowborder" valign="top" width="27.872787278727873%" id="mcps1.2.4.1.1"><p id="p4661053145115"><a name="p4661053145115"></a><a name="p4661053145115"></a>Topic</p>
</th>
<th class="cellrowborder" valign="top" width="36.053605360536054%" id="mcps1.2.4.1.2"><p id="p126685315112"><a name="p126685315112"></a><a name="p126685315112"></a>Development Scenario</p>
</th>
<th class="cellrowborder" valign="top" width="36.07360736073608%" id="mcps1.2.4.1.3"><p id="p26695395112"><a name="p26695395112"></a><a name="p26695395112"></a>Documents</p>
</th>
</tr>
</thead>
<tbody><tr id="row9662532514"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p066105317513"><a name="p066105317513"></a><a name="p066105317513"></a>About <span id="text70243343"><a name="text70243343"></a><a name="text70243343"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p16673531512"><a name="p16673531512"></a><a name="p16673531512"></a>Getting familiar with <span id="text897788591"><a name="text897788591"></a><a name="text897788591"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul10673531517"></a><a name="ul10673531517"></a><ul id="ul10673531517"><li><a href="https://gitee.com/openharmony/docs/blob/master/en/OpenHarmony-Overview.md" target="_blank" rel="noopener noreferrer">About OpenHarmony</a></li><li><a href="glossary/glossary.md">Glossary</a></li></ul>
</td>
</tr>
<tr id="row267155313513"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p13671853205113"><a name="p13671853205113"></a><a name="p13671853205113"></a>Development resources</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p0671053115115"><a name="p0671053115115"></a><a name="p0671053115115"></a>Preparing for your development</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul06732078273"></a><a name="ul06732078273"></a><ul id="ul06732078273"><li><a href="get-code/sourcecode-acquire.md">Obtaining Source Code</a></li><li><a href="get-code/gettools.md">Tool Acquisition</a></li></ul>
</td>
</tr>
<tr id="row13671253165120"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p166795345112"><a name="p166795345112"></a><a name="p166795345112"></a>Quick start</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p1167135345112"><a name="p1167135345112"></a><a name="p1167135345112"></a>Getting started with setup, build, burning, debugging, and running of <span id="text687119202170"><a name="text687119202170"></a><a name="text687119202170"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><p id="p1114162510521"><a name="p1114162510521"></a><a name="p1114162510521"></a><a href="quick-start/quickstart-standard.md">Standard System</a></p>
</td>
</tr>
<tr id="row1168155365119"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p96810536514"><a name="p96810536514"></a><a name="p96810536514"></a>Basic capabilities</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p136812535511"><a name="p136812535511"></a><a name="p136812535511"></a>Using basic capabilities of <span id="text1468659507"><a name="text1468659507"></a><a name="text1468659507"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul1954915235272"></a><a name="ul1954915235272"></a><ul id="ul1954915235272"><li><a href="kernel/kernel-standard.md">Kernel for Standard Systems</a></li><li><a href="driver/Readme-EN.md">Drivers</a></li><li><a href="subsystems/Readme-EN.md">Subsystems</a></li><li><a href="security/security-guidelines-overall.md">Security Guidelines</a></li><li><a href="security/security-privacy-protection.md">Privacy Protection</a></li></ul>
</td>
</tr>
<tr id="row10602193719152"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p857873713152"><a name="p857873713152"></a><a name="p857873713152"></a>Advanced development</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p155782037201518"><a name="p155782037201518"></a><a name="p155782037201518"></a>Developing smart devices based on system capabilities</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul257883731519"></a><a name="ul257883731519"></a><ul id="ul257883731519"><li><a href="guide/device-clock-guide.md">Development Guidelines on Clock Apps</a></li><li><a href="guide/device-driver-demo.md">Development Example for Platform Drivers</a></li><li><a href="guide/device-outerdriver-demo.md">Development Example for Peripheral Drivers</a></li></ul>
</td>
</tr>
<tr id="row66915375119"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p4696535512"><a name="p4696535512"></a><a name="p4696535512"></a>Porting and adaptation</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p185185615284"><a name="p185185615284"></a><a name="p185185615284"></a>Porting and adapting the <span id="text1434016533511"><a name="text1434016533511"></a><a name="text1434016533511"></a>OpenHarmony</span> to a third-party library</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul14724164204819"></a><a name="ul14724164204819"></a><ul id="ul14724164204819"><li><a href="porting/standard-system-porting-guide.md">Standard System Porting Guide</a></li><li><a href="porting/porting-linux-kernel.md">A Method for Rapidly Porting the OpenHarmony Linux Kernel </a></li></ul>
</td>
</tr>
<tr id="row869853125119"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p3691530511"><a name="p3691530511"></a><a name="p3691530511"></a>Contributing components</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p1469115335113"><a name="p1469115335113"></a><a name="p1469115335113"></a>Contributing components to <span id="text1180831622"><a name="text1180831622"></a><a name="text1180831622"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul44949625110"></a><a name="ul44949625110"></a><ul id="ul44949625110"><a href="hpm-part/hpm-part-about.md">HPM Part Overview</a></li><li><a href="hpm-part/hpm-part-development.md">HPM Part Development</a></li><li><a href="hpm-part/hpm-part-reference.md">HPM Part Reference</a></li></ul>
</td>
</tr>
<tr id="row1170153125110"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p16701253195118"><a name="p16701253195118"></a><a name="p16701253195118"></a>Reference</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p670135335116"><a name="p670135335116"></a><a name="p670135335116"></a>Referring to development specifications</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul177016538519"></a><a name="ul177016538519"></a><ul id="ul177016538519"><li><a href="https://device.harmonyos.com/en/docs/apiref/js-framework-file-0000000000616658" target="_blank" rel="noopener noreferrer">API References</a></li><li><a href="faqs/Readme-EN.md" target="_blank" rel="noopener noreferrer">FAQs</a></li></ul>
</td>
</tr>
</tbody>
</table>

