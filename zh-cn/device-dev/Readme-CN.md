# 导读<a name="ZH-CN_TOPIC_0000001152533331"></a>

-   [系统类型](#section767218232110)
-   [文档导读](#section19810171681218)

为了方便开发者正确获取内容，本导读基于OpenHarmony学习路径同时结合开发者具体业务对相关资料资源进行了分类。

## 系统类型<a name="section767218232110"></a>

在正式学习OpenHarmony开发前，开发者需要先了解系统类型，方便后续根据自身业务匹配对应的系统及对应文档资源。

OpenHarmony是一款面向全场景的开源分布式操作系统，采用组件化设计，支持在128KiB到xGiB RAM资源的设备上运行系统组件，设备开发者可基于目标硬件能力自由选择系统组件进行集成。

为了保证在不同硬件上集成的易用性，OpenHarmony当前定义了三种基础系统类型，设备开发者通过选择基础系统类型完成必选组件集配置后，便可实现其最小系统的开发。这三种基础系统类型的参考定义如下：

-   轻量系统（mini system）

    面向MCU类处理器例如Arm Cortex-M、RISC-V 32位的设备，硬件资源极其有限，支持的设备最小内存为128KiB，可以提供多种轻量级网络协议，轻量级的图形框架，以及丰富的IOT总线读写部件等。可支撑的产品如智能家居领域的连接类模组、传感器设备、穿戴类设备等。

-   小型系统（small system）

    面向应用处理器例如Arm Cortex-A的设备，支持的设备最小内存为1MiB，可以提供更高的安全能力、标准的图形框架、视频编解码的多媒体能力。可支撑的产品如智能家居领域的IP Camera、电子猫眼、路由器以及智慧出行域的行车记录仪等。

-   标准系统（standard system）

    面向应用处理器例如Arm Cortex-A的设备，支持的设备最小内存为128MiB，可以提供增强的交互能力、3D GPU以及硬件合成能力、更多控件以及动效更丰富的图形能力、完整的应用框架。可支撑的产品如高端的冰箱显示屏。


OpenHarmony也提供了一系列可选的系统组件，方便设备开发者按需配置，以支撑其特色功能的扩展或定制开发。系统将这些可选的系统组件组合为一系列描述为特性或功能的系统能力，以方便设备开发者理解和选择。

## 文档导读<a name="section19810171681218"></a>

-   [轻量和小型系统开发指导](#table3762949121211)
-   [标准系统开发指导](#table17667535516)

**表 1**  轻量和小型系统开发指导（参考内存<128MB）

<a name="table3762949121211"></a>
<table><thead align="left"><tr id="row18762649161218"><th class="cellrowborder" valign="top" width="28.472847284728473%" id="mcps1.2.4.1.1"><p id="p1750131161313"><a name="p1750131161313"></a><a name="p1750131161313"></a>学习路径</p>
</th>
<th class="cellrowborder" valign="top" width="35.61356135613561%" id="mcps1.2.4.1.2"><p id="p8501411141319"><a name="p8501411141319"></a><a name="p8501411141319"></a>开发者业务</p>
</th>
<th class="cellrowborder" valign="top" width="35.91359135913591%" id="mcps1.2.4.1.3"><p id="p050181111314"><a name="p050181111314"></a><a name="p050181111314"></a>相关文档</p>
</th>
</tr>
</thead>
<tbody><tr id="row317979135310"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p119871717125320"><a name="p119871717125320"></a><a name="p119871717125320"></a>了解<span id="text398721719533"><a name="text398721719533"></a><a name="text398721719533"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p14987151715312"><a name="p14987151715312"></a><a name="p14987151715312"></a>整体认知<span id="text209871317105315"><a name="text209871317105315"></a><a name="text209871317105315"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul59871171533"></a><a name="ul59871171533"></a><ul id="ul59871171533"><li><a href="https://gitee.com/openharmony" target="_blank" rel="noopener noreferrer">OpenHarmony概述</a></li><li><a href="glossary/glossary.md">术语</a></li></ul>
</td>
</tr>
<tr id="row69521557115217"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p69873174536"><a name="p69873174536"></a><a name="p69873174536"></a>获取开发资源</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p39871917185313"><a name="p39871917185313"></a><a name="p39871917185313"></a>准备开发前相关资源</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul59871117135314"></a><a name="ul59871117135314"></a><ul id="ul59871117135314"><li><a href="get-code/sourcecode-acquire.md">获取源码</a></li><li><a href="get-code/gettools.md">获取工具</a></li></ul>
</td>
</tr>
<tr id="row11602937131510"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p457713717150"><a name="p457713717150"></a><a name="p457713717150"></a>快速入门</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p55771237111517"><a name="p55771237111517"></a><a name="p55771237111517"></a>快速熟悉<span id="text15577123719154"><a name="text15577123719154"></a><a name="text15577123719154"></a>OpenHarmony</span>环境搭建、编译、烧录、调测、运行。</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><p id="p10832159115410"><a name="p10832159115410"></a><a name="p10832159115410"></a><a href="quick-start/quickstart-lite.md">轻量和小型系统快速入门</a></p>
</td>
</tr>
<tr id="row11602103701514"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p16577163716159"><a name="p16577163716159"></a><a name="p16577163716159"></a>基础能力使用</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p857711379158"><a name="p857711379158"></a><a name="p857711379158"></a>使用<span id="text5577237181514"><a name="text5577237181514"></a><a name="text5577237181514"></a>OpenHarmony</span>提供的基础能力</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul1577103716159"></a><a name="ul1577103716159"></a><ul id="ul1577103716159"><li><a href="kernel/kernel-mini.md">轻量系统内核开发指南</a></li><li><a href="kernel/kernel-small.md">小型系统内核开发指南</a></li><li><a href="driver/Readme-CN.md">驱动开发指南</a></li><li><a href="subsystems/Readme-CN.md">子系统开发指南</a></li><li><a href="security/security-guidelines-overall.md">安全指南</a></li><li><a href="security/security-privacy-protection.md">隐私保护</a></li></ul>
</td>
</tr>
<tr id="row10602193719152"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p857873713152"><a name="p857873713152"></a><a name="p857873713152"></a>进阶开发</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p155782037201518"><a name="p155782037201518"></a><a name="p155782037201518"></a>结合系统能力开发智能设备</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul257883731519"></a><a name="ul257883731519"></a><ul id="ul257883731519"><li><a href="guide/device-wlan.md">WLAN连接类产品</a></li><li><a href="guide/device-iotcamera-control.md">无屏摄像头类产品</a></li><li><a href="guide/device-camera.md">带屏摄像头类产品</a></li></ul>
</td>
</tr>
<tr id="row360273716155"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p12579163711513"><a name="p12579163711513"></a><a name="p12579163711513"></a>移植适配</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><a name="ul12579137121512"></a><a name="ul12579137121512"></a><ul id="ul12579137121512"><li>针对特定芯片做移植适配</li><li>对三方库进行移植适配</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul157903731520"></a><a name="ul157903731520"></a><ul id="ul157903731520"><li><a href="porting/porting-minichip.md">轻量系统芯片移植指导</a></li><li><a href="porting/porting-smallchip.md">小型系统芯片移植指导</a></li><li><a href="porting/porting-thirdparty.md">轻量和小型系统三方库移植指导</a></li></ul>
</td>
</tr>
<tr id="row9601737181517"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p25791037131519"><a name="p25791037131519"></a><a name="p25791037131519"></a>贡献组件</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p45798376158"><a name="p45798376158"></a><a name="p45798376158"></a>为<span id="text16579133741518"><a name="text16579133741518"></a><a name="text16579133741518"></a>OpenHarmony</span>贡献功能组件</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul957919379156"></a><a name="ul957919379156"></a><ul id="ul957919379156"><li><a href="bundles/oem_bundle_standard_des.md">HPM Bundle 开发规范</a></li><li><a href="bundles/bundles-guide.md">HPM Bundle 开发指南</a></li><li><a href="bundles/bundles-demo.md">HPM Bundle 开发示例</a></li></ul>
</td>
</tr>
<tr id="row260193701512"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p95794372155"><a name="p95794372155"></a><a name="p95794372155"></a>参考</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p458073721519"><a name="p458073721519"></a><a name="p458073721519"></a>开发参考</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul175808372155"></a><a name="ul175808372155"></a><ul id="ul175808372155"><li><a href="https://device.harmonyos.com/cn/docs/develop/apiref/js-framework-file-0000000000611396" target="_blank" rel="noopener noreferrer">API参考</a></li><li><a href="faqs/readme.md" target="_blank" rel="noopener noreferrer">常见问题</a></li></ul>
</td>
</tr>
</tbody>
</table>

**表 2**  标准系统开发指导（参考内存≥128MB）

<a name="table17667535516"></a>
<table><thead align="left"><tr id="row206665375119"><th class="cellrowborder" valign="top" width="27.872787278727873%" id="mcps1.2.4.1.1"><p id="p4661053145115"><a name="p4661053145115"></a><a name="p4661053145115"></a>学习路径</p>
</th>
<th class="cellrowborder" valign="top" width="36.053605360536054%" id="mcps1.2.4.1.2"><p id="p126685315112"><a name="p126685315112"></a><a name="p126685315112"></a>开发者业务</p>
</th>
<th class="cellrowborder" valign="top" width="36.07360736073608%" id="mcps1.2.4.1.3"><p id="p26695395112"><a name="p26695395112"></a><a name="p26695395112"></a>相关文档</p>
</th>
</tr>
</thead>
<tbody><tr id="row9662532514"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p066105317513"><a name="p066105317513"></a><a name="p066105317513"></a>了解<span id="text1167105317518"><a name="text1167105317518"></a><a name="text1167105317518"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p16673531512"><a name="p16673531512"></a><a name="p16673531512"></a>整体认知<span id="text196765319515"><a name="text196765319515"></a><a name="text196765319515"></a>OpenHarmony</span></p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul10673531517"></a><a name="ul10673531517"></a><ul id="ul10673531517"><li><a href="https://gitee.com/openharmony" target="_blank" rel="noopener noreferrer">OpenHarmony概述</a></li><li><a href="glossary/glossary.md">术语</a></li></ul>
</td>
</tr>
<tr id="row267155313513"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p13671853205113"><a name="p13671853205113"></a><a name="p13671853205113"></a>获取开发资源</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p0671053115115"><a name="p0671053115115"></a><a name="p0671053115115"></a>准备开发前相关资源</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul06732078273"></a><a name="ul06732078273"></a><ul id="ul06732078273"><li><a href="get-code/sourcecode-acquire.md">获取源码</a></li><li><a href="get-code/gettools.md">获取工具</a></li></ul>
</td>
</tr>
<tr id="row13671253165120"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p166795345112"><a name="p166795345112"></a><a name="p166795345112"></a>快速入门</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p1167135345112"><a name="p1167135345112"></a><a name="p1167135345112"></a>快速熟悉<span id="text1567115355115"><a name="text1567115355115"></a><a name="text1567115355115"></a>OpenHarmony</span>环境搭建、编译、烧录、调测、运行。</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><p id="p1114162510521"><a name="p1114162510521"></a><a name="p1114162510521"></a><a href="quick-start/quickstart-standard.md">标准系统快速入门</a></p>
</td>
</tr>
<tr id="row1168155365119"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p96810536514"><a name="p96810536514"></a><a name="p96810536514"></a>基础能力使用</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p136812535511"><a name="p136812535511"></a><a name="p136812535511"></a>使用<span id="text1068553195119"><a name="text1068553195119"></a><a name="text1068553195119"></a>OpenHarmony</span>提供的基础能力</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul1954915235272"></a><a name="ul1954915235272"></a><ul id="ul1954915235272"><li><a href="kernel/kernel-standard.md">内核开发指南</a></li><li><a href="driver/Readme-CN.md">驱动开发指南</a></li><li><a href="subsystems/Readme-CN.md">子系统开发指南</a></li><li><a href="security/security-guidelines-overall.md">安全指南</a></li><li><a href="security/security-privacy-protection.md">隐私保护</a></li></ul>
</td>
</tr>
<tr id="row10602193719152"><td class="cellrowborder" valign="top" width="28.472847284728473%" headers="mcps1.2.4.1.1 "><p id="p857873713152"><a name="p857873713152"></a><a name="p857873713152"></a>进阶开发</p>
</td>
<td class="cellrowborder" valign="top" width="35.61356135613561%" headers="mcps1.2.4.1.2 "><p id="p155782037201518"><a name="p155782037201518"></a><a name="p155782037201518"></a>结合系统能力开发智能设备</p>
</td>
<td class="cellrowborder" valign="top" width="35.91359135913591%" headers="mcps1.2.4.1.3 "><a name="ul257883731519"></a><a name="ul257883731519"></a><ul id="ul257883731519"><li><a href="guide/device-clock-guide.md">时钟应用开发指导</a></li><li><a href="guide/device-driver-demo.md">平台驱动开发示例</a></li><li><a href="guide/device-outerdriver-demo.md">外设驱动开发示例</a></li></ul>
</td>
</tr>
<tr id="row66915375119"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p4696535512"><a name="p4696535512"></a><a name="p4696535512"></a>移植适配</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p185185615284"><a name="p185185615284"></a><a name="p185185615284"></a>对三方库进行移植适配</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul14724164204819"></a><a name="ul14724164204819"></a><ul id="ul14724164204819"><li><a href="porting/standard-system-porting-guide.md">标准系统芯片移植指导</a></li><li><a href="porting/porting-linux-kernel.md">一种快速移植OpenHarmony Linux内核的方法</a></li></ul>
</td>
</tr>
<tr id="row869853125119"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p3691530511"><a name="p3691530511"></a><a name="p3691530511"></a>贡献组件</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p1469115335113"><a name="p1469115335113"></a><a name="p1469115335113"></a>为<span id="text6691253155112"><a name="text6691253155112"></a><a name="text6691253155112"></a>OpenHarmony</span>贡献功能组件</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul44949625110"></a><a name="ul44949625110"></a><ul id="ul44949625110"><li><a href="bundles/oem_bundle_standard_des.md">HPM Bundle 开发规范</a></li><li><a href="bundles/bundles-guide.md">HPM Bundle 开发指南</a></li><li><a href="bundles/bundles-demo.md">HPM Bundle 开发示例</a></li></ul>
</td>
</tr>
<tr id="row1170153125110"><td class="cellrowborder" valign="top" width="27.872787278727873%" headers="mcps1.2.4.1.1 "><p id="p16701253195118"><a name="p16701253195118"></a><a name="p16701253195118"></a>参考</p>
</td>
<td class="cellrowborder" valign="top" width="36.053605360536054%" headers="mcps1.2.4.1.2 "><p id="p670135335116"><a name="p670135335116"></a><a name="p670135335116"></a>开发参考</p>
</td>
<td class="cellrowborder" valign="top" width="36.07360736073608%" headers="mcps1.2.4.1.3 "><a name="ul177016538519"></a><a name="ul177016538519"></a><ul id="ul177016538519"><li><a href="https://device.harmonyos.com/cn/docs/develop/apiref/js-framework-file-0000000000611396" target="_blank" rel="noopener noreferrer">API参考</a></li><li><a href="faqs/readme.md" target="_blank" rel="noopener noreferrer">常见问题</a></li></ul>
</td>
</tr>
</tbody>
</table>

