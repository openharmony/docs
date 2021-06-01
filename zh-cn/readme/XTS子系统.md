# XTS子系统<a name="ZH-CN_TOPIC_0000001117409671"></a>

-   [简介](#section465982318513)
-   [系统类型](#section125090457443)
-   [目录](#section161941989596)
-   [约束](#section119744591305)
-   [使用说明](#section137768191623)
-   [用例开发指导](#section3695134065513)
    -   [C语言用例开发编译指导（适用于轻量系统产品用例开发）](#section198193336544)
    -   [C语言用例执行指导（适用于轻量系统产品用例开发）](#section13820233175418)
    -   [C++语言用例开发编译指导（适用于小型系统、标准系统用例开发）](#section3822123311540)
    -   [C++语言用例执行指导（适用于小型系统、标准系统用例开发）](#section128222336544)
    -   [JS语言用例开发指导（适用于标准系统）](#section159801435165220)
    -   [JS语言用例编译打包指导（适用于标准系统）](#section445519106559)

-   [相关仓](#section1371113476307)

## 简介<a name="section465982318513"></a>

XTS子系统是OpenHarmony生态认证测试套件的集合，当前包括acts（application compatibility test suite）应用兼容性测试套件，后续会拓展dcts（device compatibility test suite）设备兼容性测试套件等。

XTS子系统当前包括acts与tools软件包：

-   acts，存放acts相关测试用例源码与配置文件，其目的是帮助终端设备厂商尽早发现软件与OpenHarmony的不兼容性，确保软件在整个开发过程中满足OpenHarmony的兼容性要求。
-   tools，存放acts相关测试用例开发框架。

## 系统类型<a name="section125090457443"></a>

OpenHarmony支持如下几种系统类型：

-   轻量系统（mini system）

    面向MCU类处理器例如Arm Cortex-M、RISC-V 32位的设备，硬件资源极其有限，支持的设备最小内存为128KiB，可以提供多种轻量级网络协议，轻量级的图形框架，以及丰富的IOT总线读写部件等。可支撑的产品如智能家居领域的连接类模组、传感器设备、穿戴类设备等。

-   小型系统（small system）

    面向应用处理器例如Arm Cortex-A的设备，支持的设备最小内存为1MiB，可以提供更高的安全能力、标准的图形框架、视频编解码的多媒体能力。可支撑的产品如智能家居领域的IP Camera、电子猫眼、路由器以及智慧出行域的行车记录仪等。

-   标准系统（standard system）

    面向应用处理器例如Arm Cortex-A的设备，支持的设备最小内存为128MiB，可以提供增强的交互能力、3D GPU以及硬件合成能力、更多控件以及动效更丰富的图形能力、完整的应用框架。可支撑的产品如高端的冰箱显示屏。


## 目录<a name="section161941989596"></a>

```
/test/xts
├── acts                 # 测试代码存放目录
│   └── subsystem       # 标准系统子系统测试用例源码存放目录
│   └── subsystem_lite  # 轻量系统、小型系统子系统测试用例源码存放目录
│   └── BUILD.gn        # 标准系统测试用例编译配置
│   └── build_lite      # 轻量系统、小型系统测试用例编译配置存放目录
│       └── BUILD.gn    # 轻量系统、小型系统测试用例编译配置
└── tools                # 测试工具代码存放目录
```

## 约束<a name="section119744591305"></a>

轻量系统用例开发语言是C，小型系统用例开发语言是C++。

## 使用说明<a name="section137768191623"></a>

**表 1**  用例级别说明

<a name="table12856113719456"></a>
<table><thead align="left"><tr id="row88561737114517"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.1"><p id="p54711456452"><a name="p54711456452"></a><a name="p54711456452"></a>级别名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.283328332833285%" id="mcps1.2.4.1.2"><p id="p114834544518"><a name="p114834544518"></a><a name="p114834544518"></a>基本定义</p>
</th>
<th class="cellrowborder" valign="top" width="33.383338333833386%" id="mcps1.2.4.1.3"><p id="p348154574518"><a name="p348154574518"></a><a name="p348154574518"></a>测试范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row78561137134514"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p17481345124512"><a name="p17481345124512"></a><a name="p17481345124512"></a>Level0</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p1548945204514"><a name="p1548945204514"></a><a name="p1548945204514"></a>冒烟</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p174824517456"><a name="p174824517456"></a><a name="p174824517456"></a>验证关键功能点基本功能/最基本DFX属性在最常见输入下的表现，通过表示功能基本可运行。</p>
</td>
</tr>
<tr id="row28563372451"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p448445144512"><a name="p448445144512"></a><a name="p448445144512"></a>Level1</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p44813452452"><a name="p44813452452"></a><a name="p44813452452"></a>基本</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p648184584514"><a name="p648184584514"></a><a name="p648184584514"></a>验证各功能点基本功能/基本DFX属性在常见输入下的表现，通过表示功能基本可测试。</p>
</td>
</tr>
<tr id="row12856137204514"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p164834520453"><a name="p164834520453"></a><a name="p164834520453"></a>Level2</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p148245184511"><a name="p148245184511"></a><a name="p148245184511"></a>重要</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p348945124510"><a name="p348945124510"></a><a name="p348945124510"></a>验证各功能点的基本功能/基本DFX属性在常规输入/常见异常情况下的表现，通过表示功能基本正常可用，可开展Beta。</p>
</td>
</tr>
<tr id="row48571137204514"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p7481545184513"><a name="p7481545184513"></a><a name="p7481545184513"></a>Level3</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p1748184514455"><a name="p1748184514455"></a><a name="p1748184514455"></a>一般</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p8481245104519"><a name="p8481245104519"></a><a name="p8481245104519"></a>验证各功能点的全部功能/全部DFX属性在各种常规/非常规输入组合下，或各种正常/异常预置条件组合下的表现。</p>
</td>
</tr>
<tr id="row14857133712451"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1248144515456"><a name="p1248144515456"></a><a name="p1248144515456"></a>Level4</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p94804514519"><a name="p94804514519"></a><a name="p94804514519"></a>生僻</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p1248445164516"><a name="p1248445164516"></a><a name="p1248445164516"></a>验证关键功能点在极端异常预置条件下、用户难以触及的异常输入组合下的表现。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  用例粒度说明

<a name="table1690733521014"></a>
<table><thead align="left"><tr id="row9907143516105"><th class="cellrowborder" valign="top" width="19.591959195919593%" id="mcps1.2.4.1.1"><p id="p1141312416102"><a name="p1141312416102"></a><a name="p1141312416102"></a>用例规模</p>
</th>
<th class="cellrowborder" valign="top" width="35.17351735173517%" id="mcps1.2.4.1.2"><p id="p34131416109"><a name="p34131416109"></a><a name="p34131416109"></a>被测试对象</p>
</th>
<th class="cellrowborder" valign="top" width="45.23452345234523%" id="mcps1.2.4.1.3"><p id="p12413141171010"><a name="p12413141171010"></a><a name="p12413141171010"></a>测试环境</p>
</th>
</tr>
</thead>
<tbody><tr id="row2907335181017"><td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.2.4.1.1 "><p id="p6414134117109"><a name="p6414134117109"></a><a name="p6414134117109"></a>LargeTest</p>
</td>
<td class="cellrowborder" valign="top" width="35.17351735173517%" headers="mcps1.2.4.1.2 "><p id="p20414104113101"><a name="p20414104113101"></a><a name="p20414104113101"></a>业务功能/全场景特性/整机及场景级DFX</p>
</td>
<td class="cellrowborder" valign="top" width="45.23452345234523%" headers="mcps1.2.4.1.3 "><p id="p5414841121013"><a name="p5414841121013"></a><a name="p5414841121013"></a>尽量使用贴近真实的环境设备</p>
</td>
</tr>
<tr id="row10907635131015"><td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.2.4.1.1 "><p id="p19414134117104"><a name="p19414134117104"></a><a name="p19414134117104"></a>MediumTest</p>
</td>
<td class="cellrowborder" valign="top" width="35.17351735173517%" headers="mcps1.2.4.1.2 "><p id="p114141241141018"><a name="p114141241141018"></a><a name="p114141241141018"></a>模块/子系统集成至设备后的功能/DFX</p>
</td>
<td class="cellrowborder" valign="top" width="45.23452345234523%" headers="mcps1.2.4.1.3 "><p id="p14414941111015"><a name="p14414941111015"></a><a name="p14414941111015"></a>使用真实的单设备进行验证，可进行消息模拟，尽量不对函数进行MOCK</p>
</td>
</tr>
<tr id="row1990713353100"><td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.2.4.1.1 "><p id="p641414110109"><a name="p641414110109"></a><a name="p641414110109"></a>SmallTest</p>
</td>
<td class="cellrowborder" valign="top" width="35.17351735173517%" headers="mcps1.2.4.1.2 "><p id="p54141541181018"><a name="p54141541181018"></a><a name="p54141541181018"></a>模块/类/函数</p>
</td>
<td class="cellrowborder" valign="top" width="45.23452345234523%" headers="mcps1.2.4.1.3 "><p id="p1841494131013"><a name="p1841494131013"></a><a name="p1841494131013"></a>在开发者个人环境进行测试，尽量不依赖其他模块，存在大量的MOCK</p>
</td>
</tr>
</tbody>
</table>

**表 3**  测试类型说明

<a name="table18811230124619"></a>
<table><thead align="left"><tr id="row48163019466"><th class="cellrowborder" valign="top" width="19.040000000000003%" id="mcps1.2.3.1.1"><p id="p1791784418465"><a name="p1791784418465"></a><a name="p1791784418465"></a>测试类型名称</p>
</th>
<th class="cellrowborder" valign="top" width="80.96%" id="mcps1.2.3.1.2"><p id="p2917164444614"><a name="p2917164444614"></a><a name="p2917164444614"></a>测试类型定义</p>
</th>
</tr>
</thead>
<tbody><tr id="row682630104615"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p1091784414469"><a name="p1091784414469"></a><a name="p1091784414469"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p16917344104618"><a name="p16917344104618"></a><a name="p16917344104618"></a>验证被测对象提供给用户的业务功能实现正确性的测试项，这里的“用户”可以是终端用户或开发者，功能包括业务功能及平台功能</p>
</td>
</tr>
<tr id="row1821930154611"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p591714474612"><a name="p591714474612"></a><a name="p591714474612"></a>Performance</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p15917154410463"><a name="p15917154410463"></a><a name="p15917154410463"></a>验证被测对象在特定预置条件/负载模型下的处理能力的测试项，“处理能力”一般以单位时间内可处理的业务量来衡量，如呼叫/秒，帧率/秒，事件处理量/秒等</p>
</td>
</tr>
<tr id="row13821030104616"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p691711440467"><a name="p691711440467"></a><a name="p691711440467"></a>Power</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p159171544104616"><a name="p159171544104616"></a><a name="p159171544104616"></a>验证被测对象在特定预置条件/负载模型下在一定时间内能源消耗量的测试项</p>
</td>
</tr>
<tr id="row6821330114618"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p13917164454612"><a name="p13917164454612"></a><a name="p13917164454612"></a>Reliability</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p11917194416465"><a name="p11917194416465"></a><a name="p11917194416465"></a>验证被测对象在正常/异常输入情况下，或业务量压力和长时间连续运行压力情况下业务表现的测试项，含稳定性、压力、故障注入、Monkey测试项</p>
</td>
</tr>
<tr id="row11821930184612"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p1691774474618"><a name="p1691774474618"></a><a name="p1691774474618"></a>Security</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p1791784410463"><a name="p1791784410463"></a><a name="p1791784410463"></a>验证系统对恶意威胁的防护能力，威胁包括但不限于未授权访问、使用、泄露、破坏、修改、毁灭，以保障信息的机密性、完整性和可用性; 验证系统对用户隐私的保护能力，保障用户的隐私数据被收集、使用、保有、披露和处置符合法律规范，保障用户的隐私权; 验证对各类安全规范的遵从情况，如安全设计规范、安全红线、工信部安全认证规范等，保障安全相关法律法规的合规。</p>
</td>
</tr>
<tr id="row16825307467"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p129188444462"><a name="p129188444462"></a><a name="p129188444462"></a>Global</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p179186444465"><a name="p179186444465"></a><a name="p179186444465"></a>验证被测对象在是否具有国际化数据支持和本地化能力的测试项，包括语言显示、输入/输出习惯、时间显示、区域特性如货币时间禁忌等等</p>
</td>
</tr>
<tr id="row08211308464"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p191814447465"><a name="p191814447465"></a><a name="p191814447465"></a>Compatibility</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p99181344144613"><a name="p99181344144613"></a><a name="p99181344144613"></a>当被测对象为应用时，包括被测对象对于自身数据的后向兼容性、对于系统的前后向兼容性、对于不同用户数据(如播放器之音频文件格式/智能短信之用户短信内容)的兼容性测试项； 当被测对象为系统时，包括被测系统对于系统自身数据的后向兼容性、以及对于生态中常用应用的兼容性测试项；当被测对象为软件时，包括被测系统对于相关的硬件的兼容性；</p>
</td>
</tr>
<tr id="row1782730124618"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p13918144134614"><a name="p13918144134614"></a><a name="p13918144134614"></a>User</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p1291844494611"><a name="p1291844494611"></a><a name="p1291844494611"></a>验证被测对象在真实用户场景下的用户体验感受的测试项，注意此种情况下没有客观的“正确”与“失败”，所有的结论及评价都应该来自于用户</p>
</td>
</tr>
<tr id="row58243024617"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p1291884474614"><a name="p1291884474614"></a><a name="p1291884474614"></a>Standard</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p0918124424614"><a name="p0918124424614"></a><a name="p0918124424614"></a>验证被测对象对于行业及公司内标准/协议/规范的遵从情况的测试项，注意此处的“标准”不包含任何安全标准，针对安全标准的测试项划归为“安全测试”类型</p>
</td>
</tr>
<tr id="row382830124619"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p119181044164619"><a name="p119181044164619"></a><a name="p119181044164619"></a>Safety</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p1291818443468"><a name="p1291818443468"></a><a name="p1291818443468"></a>验证被测对象的Safety属性，避免产品可能对人身安全、健康以及产品本身带来的危害。</p>
</td>
</tr>
<tr id="row1083153014465"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p39187441469"><a name="p39187441469"></a><a name="p39187441469"></a>Resilience</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p891815444462"><a name="p891815444462"></a><a name="p891815444462"></a>验证被测对象的韧性属性，确保系统受攻击时承受并保持在有定义的运行状态（包括降级）、恢复并适应攻击以保障Mission达成。</p>
</td>
</tr>
</tbody>
</table>

## 用例开发指导<a name="section3695134065513"></a>

根据测试系统选择测试框架和对应测试用例语言。

**表 4**  系统和测试框架、开发语言对应关系

<a name="table4418343171415"></a>
<table><thead align="left"><tr id="row34183435145"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p941874311148"><a name="p941874311148"></a><a name="p941874311148"></a>系统</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1841804341413"><a name="p1841804341413"></a><a name="p1841804341413"></a>测试框架</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p2418104311148"><a name="p2418104311148"></a><a name="p2418104311148"></a>语言</p>
</th>
</tr>
</thead>
<tbody><tr id="row8419164319148"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p7419194312143"><a name="p7419194312143"></a><a name="p7419194312143"></a>轻量系统</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10419124312145"><a name="p10419124312145"></a><a name="p10419124312145"></a>hctest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11419643191410"><a name="p11419643191410"></a><a name="p11419643191410"></a>c</p>
</td>
</tr>
<tr id="row141915438147"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p441911436141"><a name="p441911436141"></a><a name="p441911436141"></a>小型系统</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p541916432142"><a name="p541916432142"></a><a name="p541916432142"></a>hcpptest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p54191643131416"><a name="p54191643131416"></a><a name="p54191643131416"></a>c++</p>
</td>
</tr>
<tr id="row4419134341417"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p341964313143"><a name="p341964313143"></a><a name="p341964313143"></a>标准系统</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10419443171416"><a name="p10419443171416"></a><a name="p10419443171416"></a>HJSUnit、hcpptest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p9419143181414"><a name="p9419143181414"></a><a name="p9419143181414"></a>js、c++</p>
</td>
</tr>
</tbody>
</table>

### C语言用例开发编译指导（适用于轻量系统产品用例开发）<a name="section198193336544"></a>

**示例：轻量系统测试用例开发**

当前使用的测试框架是hctest，hctest测试框架支持使用C语言编写测试用例，是在开源测试框架unity的基础上进行增强和适配。

1.  用例目录规范：测试用例存储到test/xts/acts仓中

    ```
    ├── acts
    │ └──subsystem_lite
    │ │ └── module_hal
    │ │ │ └── BUILD.gn
    │ │ │ └── src
    │ └──build_lite
    │ │ └── BUILD.gn
    ```

2.  src目录下用例编写样例。

    1.引用测试框架

    ```
    #include "hctest.h"
    ```

    2. 使用宏定义LITE\_TEST\_SUIT定义子系统、模块、测试套件名称

    ```
    /**  
    * @brief  register a test suit named "IntTestSuite"  
    * @param  test subsystem name  
    * @param  example module name  
    * @param  IntTestSuite test suit name  
    */
    LITE_TEST_SUIT(test, example, IntTestSuite);
    ```

    3. 定义Setup与TearDown

    命名方式：测试套件名称+Setup，测试套件名称+TearDown。

    Setup与TearDown必须存在，可以为空函数。

    4. 使用宏定义LITE\_TEST\_CASE写测试用例

    包括三个参数：测试套件名称，测试用例名称，用例属性（测试类型、用例粒度、用例级别）。

    ```
    LITE_TEST_CASE(IntTestSuite, TestCase001, Function | MediumTest | Level1) 
    {  
      //do something 
    };
    ```

    5. 使用宏定义 RUN\_TEST\_SUITE注册测试套件

    ```
    RUN_TEST_SUITE(IntTestSuite);
    ```

3.  测试模块的配置文件（BUILD.gn）样例：

    在每个测试模块目录下新建BUILD.gn编译文件，用于指定编译后静态库的名称、依赖的头文件、依赖的库等；具体写法如下：

    ```
    import("//test/xts/tools/lite/build/suite_lite.gni")
    hctest_suite("ActsDemoTest") {
        suite_name = "acts"
        sources = [
            "src/test_demo.c",
        ]
        include_dirs = [ ]
        cflags = [ "-Wno-error" ]
    }
    ```

4.  acts下BUILD.gn增加编译选项。

    需要将测试模块加入到acts目录下的编译脚本中，编译脚本路径：test/xts/acts/build\_lite/BUILD.gn。

    ```
    lite_component("acts") {  
        ...
        if(board_name == "liteos_m") {
            features += [    
                ...
                "//xts/acts/subsystem_lite/module_hal:ActsDemoTest"
            ]    
        }
    }
    ```

5.  测试套件编译命令。

    随版本编译，debug版本编译时会同步编译acts测试套件

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >acts测试套件编译中间件为静态库，最终链接到版本镜像中 。


### C语言用例执行指导（适用于轻量系统产品用例开发）<a name="section13820233175418"></a>

**示例：轻量系统测试用例执行**

将版本镜像烧录进开发板。

**测试步骤**

1.  使用串口工具登录开发板，并保存串口打印信息。
2.  重启设备，查看串口日志。

**测试结果分析指导**

基于串口打印日志进行分析；

每个测试套件执行以Start to run test suite开始，以xx Tests xx Failures xx Ignored结束。

### C++语言用例开发编译指导（适用于小型系统、标准系统用例开发）<a name="section3822123311540"></a>

**示例：小型系统测试用例开发**（标准系统参考具体样例目录：global/i18n\_standard）

当前使用的测试框架是hcpptest，hcpptest测试框架是在开源的googletest测试框架的基础上进行的增强和适配。

1.  规范用例目录：测试用例存储到test/xts/acts仓中。

    ```
    ├── acts
    │ └──subsystem_lite
    │ │ └── module_posix
    │ │ │ └── BUILD.gn
    │ │ │ └── src
    │ └──build_lite
    │ │ └── BUILD.gn
    ```

2.  测试模块src下用例编写样例：

    1. 引用测试框架：

    需要引用gtest.h  如：\#include "gtest/gtest.h"

    ```
    #include "gtest/gtest.h"
    ```

    2. 定义Setup与TearDown

    ```
    using namespace std;
    using namespace testing::ext;
    class TestSuite: public testing::Test {
    protected:
    // Preset action of the test suite, which is executed before the first test case
    static void SetUpTestCase(void){
    }
    // Test suite cleanup action, which is executed after the last test case
    static void TearDownTestCase(void){
    }
    // Preset action of the test case
    virtual void SetUp()
    {
    }
    // Cleanup action of the test case
    virtual void TearDown()
    {
    }
    };
    ```

    3. 使用宏定义HWTEST或HWTEST\_F写测试用例

    普通测试用例的定义：HWTEST（测试套名称， 测试用例名称， 用例标注）。

    包含SetUp和TearDown的测试用例的定义 ：HWTEST\_F（测试套名称， 测试用例名称，用例标注）。

    宏定义包括三个参数：测试套件名称，测试用例名称，用例属性（测试类型、用例粒度、用例级别）。

    ```
    HWTEST_F(TestSuite, TestCase_0001, Function | MediumTest | Level1) {
    // do something
    }
    ```

3.  测试模块下用例配置文件（BUILD.gn）样例：

    每个测试模块目录下新建BUILD.gn编译文件，用于指定编译后可执行文件的名称、依赖的头文件、依赖的库等；具体写法如下。每个测试模块将独立编译成.bin可执行文件， 该文件可直接push到单板上进行测试。

    举例：

    ```
    import("//test/xts/tools/lite/build/suite_lite.gni")
    hcpptest_suite("ActsDemoTest") {
        suite_name = "acts"
        sources = [
            "src/TestDemo.cpp"
        ]
    
        include_dirs = [
            "src",
            ...
        ]
        deps = [
            ...
        ]
        cflags = [ "-Wno-error" ]
    }
    
    ```

4.  acts目录下增加编译选项（BUILD.gn）样例：

    将测试模块加入到acts目录下的编译脚本中，编译脚本为：test/xts/acts/build\_lite/BUILD.gn。

    ```
     lite_component("acts") {  
    ...
    else if(board_name == "liteos_a") {
            features += [
                ...
                "//xts/acts/subsystem_lite/module_posix:ActsDemoTest"
            ]
        }
    }
    ```

5.  测试套件编译命令。

    随版本编译，debug版本编译时会同步编译acts测试套件

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >小型系统acts独立编译成可执行文件（bin格式）， 在编译产物的suites\\acts目录下归档。


### C++语言用例执行指导（适用于小型系统、标准系统用例开发）<a name="section128222336544"></a>

**示例：小型系统测试用例执行**

目前的用例执行采用nfs共享的方式，mount到单板去执行。

**环境搭建**

1.  使用有限网线或无线将开发板与PC进行连接。
2.  开发板配置IP、子网掩码、网关，确保开发板与PC处于同一个网段。
3.  PC安装nfs服务器并完成注册，启动nfs服务。
4.  开发板配置mount命令，确保开发板可以访问PC端的nfs共享文件。

    格式：mount \[nfs服务器IP\]:\[/nfs共享目录\] \[/开发板目录\] nfs

    举例：

    ```
    mount 192.168.1.10:/nfs /nfs nfs
    ```


**用例执行**

测试套件执行 ActsDemoTest.bin 触发用例执行，基于串口打印日志进行分析。

### JS语言用例开发指导（适用于标准系统）<a name="section159801435165220"></a>

当前使用的测试框架是HJSUnit，用于支撑OpenHarmony application测试（特指基于JS应用框架使用 Javascript 语言开发的 APP）进行自动化测试。

**用例编写基础语法**

测试用例为 js 语言，必须满足 JavaScript 语言编程规范:

**表 5** 

<a name="table13980103565212"></a>
<table><thead align="left"><tr id="row1098093545218"><th class="cellrowborder" valign="top" width="17.92179217921792%" id="mcps1.2.4.1.1"><p id="p49811235135214"><a name="p49811235135214"></a><a name="p49811235135214"></a>用例语法</p>
</th>
<th class="cellrowborder" valign="top" width="68.88688868886888%" id="mcps1.2.4.1.2"><p id="p898183565220"><a name="p898183565220"></a><a name="p898183565220"></a>描述</p>
</th>
<th class="cellrowborder" valign="top" width="13.19131913191319%" id="mcps1.2.4.1.3"><p id="p17981143512526"><a name="p17981143512526"></a><a name="p17981143512526"></a>要求</p>
</th>
</tr>
</thead>
<tbody><tr id="row1598183515528"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p139810358527"><a name="p139810358527"></a><a name="p139810358527"></a>beforeAll</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p198111352526"><a name="p198111352526"></a><a name="p198111352526"></a>测试套级别的预置条件，在所有测试用例开始前执行且仅执行一次，支持一个参数：预置动作函数</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p298114355529"><a name="p298114355529"></a><a name="p298114355529"></a>可选</p>
</td>
</tr>
<tr id="row11981103512529"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p20981135135215"><a name="p20981135135215"></a><a name="p20981135135215"></a>afterAll</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p39811935115217"><a name="p39811935115217"></a><a name="p39811935115217"></a>测试套级别的清理条件，在所有测试用例结束后执行且仅执行一次，支持一个参数：清理动作函数</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p998110354527"><a name="p998110354527"></a><a name="p998110354527"></a>可选</p>
</td>
</tr>
<tr id="row1298116359526"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p898112359526"><a name="p898112359526"></a><a name="p898112359526"></a>beforeEach</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p149811335175215"><a name="p149811335175215"></a><a name="p149811335175215"></a>测试用例级别的预置条件，在每条测试用例开始前执行，执行次数与 it 定义的测试用例数一致，支持一个参数：预置动作函数</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p13981133585212"><a name="p13981133585212"></a><a name="p13981133585212"></a>可选</p>
</td>
</tr>
<tr id="row6982435115219"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p19982133517525"><a name="p19982133517525"></a><a name="p19982133517525"></a>afterEach</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p1398213575219"><a name="p1398213575219"></a><a name="p1398213575219"></a>测试用例级别的清理条件，在每条测试用例结束后执行，执行次数与 it 定义的测试用例数一致，支持一个参数：清理动作函数</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p159821535195219"><a name="p159821535195219"></a><a name="p159821535195219"></a>可选</p>
</td>
</tr>
<tr id="row16982143513521"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p598203510527"><a name="p598203510527"></a><a name="p598203510527"></a>describe</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p5982123595215"><a name="p5982123595215"></a><a name="p5982123595215"></a>定义一个测试套，支持两个参数：测试套名称和测试套函数； describe 支持嵌套，每个 describe 内均可以定义 beforeAll 、beforeEach 、afterEach 和 afterAll</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p898217352527"><a name="p898217352527"></a><a name="p898217352527"></a>必选</p>
</td>
</tr>
<tr id="row6982113518526"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p17982123510526"><a name="p17982123510526"></a><a name="p17982123510526"></a>it</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p598211352522"><a name="p598211352522"></a><a name="p598211352522"></a>定义一条测试用例，支持三个参数：用例名称，过滤参数和用例函数</p>
<p id="p5205769588"><a name="p5205769588"></a><a name="p5205769588"></a>备注：</p>
<p id="p6965058101"><a name="p6965058101"></a><a name="p6965058101"></a>过滤参数：过滤参数为一个 32 位的 Int 类型参数，0 位 置1表示不筛选、默认执行；0-10 位 置1表示<strong id="b9169154410212"><a name="b9169154410212"></a><a name="b9169154410212"></a>测试用例类型</strong>；16-18 位 置1表示<strong id="b1427947428"><a name="b1427947428"></a><a name="b1427947428"></a>测试用例规模</strong>；24-28 位 置1表示<strong id="b289818491213"><a name="b289818491213"></a><a name="b289818491213"></a>测试层级</strong>。</p>
<p id="p7965165151011"><a name="p7965165151011"></a><a name="p7965165151011"></a><strong id="b69449534215"><a name="b69449534215"></a><a name="b69449534215"></a>测试用例类型</strong>。置位0-10分别表示：FUNCTION 方法类测试、PERFORMANCE 性能类测试、POWER 功耗类测试、RELIABILITY 可靠性测试、SECURITY 安全合规测试、GLOBAL 整体性测试、COMPATIBILITY 兼容性测试、USER 用户测试、STANDARD 标准测试、SAFETY 安全特性测试，RESILIENCE 压力测试。</p>
<p id="p199651555102"><a name="p199651555102"></a><a name="p199651555102"></a><strong id="b10114125712211"><a name="b10114125712211"></a><a name="b10114125712211"></a>测试用例规模</strong>。置位16-18分别表示：SMALL 小型测试、MEDIUM 中型测试、LARGE 大型测试。</p>
<p id="p296545151020"><a name="p296545151020"></a><a name="p296545151020"></a><strong id="b167975581223"><a name="b167975581223"></a><a name="b167975581223"></a>测试层级</strong>。置位24-28分别表示：LEVEL0-0 级测试、LEVEL1-1 级测试、LEVEL2-2 级测试、LEVEL3-3 级测试、LEVEL4-4 级测试。</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p17601752115716"><a name="p17601752115716"></a><a name="p17601752115716"></a>必选</p>
</td>
</tr>
</tbody>
</table>

用例编写语法采用 jasmine 的标准语法，格式支持ES6格式。

1.  规范用例目录：测试用例存储到entry/src/main/js/test目录。

    ```
    ├── BUILD.gn   
    │ └──entry
    │ │ └──src
    │ │ │ └──main
    │ │ │ │ └──js
    │ │ │ │ │ └──default               
    │ │ │ │ │ │ └──pages
    │ │ │ │ │ │ │ └──index             
    │ │ │ │ │ │ │ │ └──index.js        # 入口文件
    │ │ │ │ │ └──test                  # 测试代码存放目录  
    │ │ │ └── resources                # hap资源存放目录
    │ │ │ └── config.json              # hap配置文件
    ```

2.  index.js示例

    ```
    // 拉起js测试框架，加载测试用例
    import {Core, ExpectExtend} from 'deccjsunit/index'
    
    export default {
        data: {
            title: ""
        },
        onInit() {
            this.title = this.$t('strings.world');
        },
        onShow() {
            console.info('onShow finish')
            const core = Core.getInstance()
            const expectExtend = new ExpectExtend({
                'id': 'extend'
            })
            core.addService('expect', expectExtend)
            core.init()
            const configService = core.getDefaultService('config')
            configService.setConfig(this)
            require('../../../test/List.test')
            core.execute()
        },
        onReady() {
        },
    }
    ```

3.  单元测试用例示例

    ```
    // Example1: 使用HJSUnit进行单元测试
    describe('appInfoTest', function () {    
        it('app_info_test_001', 0, function () {
            var info = app.getInfo()
            expect(info.versionName).assertEqual('1.0')
            expect(info.versionCode).assertEqual('3')
        })
    }) 
    ```


### JS语言用例编译打包指导（适用于标准系统）<a name="section445519106559"></a>

hap包编译请参考[标准系统js应用开发指导](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/build_overview-0000001055075201)。

## 相关仓<a name="section1371113476307"></a>

xts\_acts

xts\_tools

