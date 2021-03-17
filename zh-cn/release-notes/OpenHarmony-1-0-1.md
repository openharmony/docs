# OpenHarmony 1.0.1（2021-03-15）<a name="ZH-CN_TOPIC_0000001125880475"></a>

-   [版本概述](#section1677664815431)
-   [内核](#section11256141314463)
    -   [新增特性](#section1834713384464)
    -   [修改特性](#section6894155811483)

-   [泛Sensor](#section457103914819)
    -   [新增特性](#section1157114391480)

-   [全球化](#section13453154420488)
    -   [新增特性](#section7453174417481)

-   [JS应用开发框架](#section146946144818)
    -   [新增特性](#section16654654819)
    -   [修改特性](#section16114654811)
    -   [删除特性](#section7634619486)

-   [测试](#section5857174710485)
    -   [新增特性](#section4857247154819)

-   [图形](#section116345457492)
    -   [新增特性](#section526413158501)
    -   [修改特性](#section112652156501)

-   [公共基础](#section981315393543)
    -   [新增特性](#section168131939145418)

-   [驱动](#section1793134012548)
    -   [新增特性](#section69313406541)
    -   [修改特性](#section10931340175420)

-   [分布式通信](#section11286194113540)
    -   [新增特性](#section14286104112546)

-   [安全](#section4535841205411)
    -   [新增特性](#section35351941175420)

-   [AI子系统](#section11847124175419)
    -   [新增特性](#section148472413546)

-   [升级服务](#section09814210543)
    -   [新增特性](#section7981542105417)

-   [XTS认证](#section429384295416)
    -   [新增特性](#section929316426547)
    -   [修改特性](#section829419420543)

-   [编译构建](#section104691342105411)
    -   [新增特性](#section34699428546)
    -   [修改特性](#section946974210546)

-   [电源管理](#section13166639141617)
    -   [新增特性](#section313912368292)

-   [组件仓优化](#section13139145855718)

## 版本概述<a name="section1677664815431"></a>

OpenHarmony1.0.1扩充组件能力，新增AI子系统、电源管理子系统、泛Sensor子系统、升级子系统。OpenHarmony有了统一AI引擎框架。liteos-m内核完成三方可移植性重构。驱动子系统完善了WIFI、Sensor、Input、Display的驱动模型。图形子系统针对UI能力及JS框架性能和内存得到优化。同时对目录结构及组件仓做了大幅优化。

## 内核<a name="section11256141314463"></a>

### 新增特性<a name="section1834713384464"></a>

-   LiteOS-M支持Cortex-M7、Cortex-M33和RISC-V芯片架构，新增对应的单板target样例。
-   LiteOS-M支持MPU功能。
-   LiteOS-M支持部分POSIX接口。
-   LiteOS-M支持FatFS文件系统。
-   LiteOS-M支持异常回调函数注册机制。
-   LiteOS-M三方芯片易适配性架构调整。
-   LiteOS-M、LiteOS-A支持堆内存调测功能，包括内存泄漏、踩内存、内存统计。
-   LiteOS-M、LiteOS-A支持TLSF堆内存算法，提高内存申请和释放效率，降低碎片率。

### 修改特性<a name="section6894155811483"></a>

-   LiteOS-A调度优化。

## 泛Sensor<a name="section457103914819"></a>

### 新增特性<a name="section1157114391480"></a>

-   新增Sensor组件，提供了Sensor列表查询、Sensor启停、Sensor订阅/去订阅、设置数据上报模式、设置采样间隔等功能。

## 全球化<a name="section13453154420488"></a>

### 新增特性<a name="section7453174417481"></a>

-   新增79种语言的数字格式化、日期和时间格式化、单复数C/C++国际化接口。

## JS应用开发框架<a name="section146946144818"></a>

### 新增特性<a name="section16654654819"></a>

-   新增JS前端opacity全局属性支持。
-   新增prompt.showDialog API。
-   新增二维码组件qrcode。
-   新增事件冒泡机制。

### 修改特性<a name="section16114654811"></a>

-   国际化性能优化，加速页面跳转，支持数字国际化及时间日期转换。
-   前端布局能力增强，部分样式值支持设置百分比。
-   input及switch组件尺寸自适应能力增强。
-   image组件能力增强，支持显示应用私有数据目录图片。
-   image-animator组件能力增强，支持结束帧指定。
-   canvas组件能力增强，新增部分API。
-   device.getInfo API增强，新增部分返回字段。
-   DFX能力增强，支持跟踪异常的方法栈。

### 删除特性<a name="section7634619486"></a>

-   国际化功能不再支持回溯特性。

## 测试<a name="section5857174710485"></a>

### 新增特性<a name="section4857247154819"></a>

-   新增测试工具按照用例级别筛选要执行的测试用例。
-   新增测试demo用例。

## 图形<a name="section116345457492"></a>

### 新增特性<a name="section526413158501"></a>

-   新增组件级旋转缩放、组件级透明度。
-   新增事件冒泡机制，新增旋转表冠事件。
-   新增GIF图片解析显示，新增百分比宽高布局，新增Video和二维码控件。

### 修改特性<a name="section112652156501"></a>

-   局部渲染和SIMD性能优化。

## 公共基础<a name="section981315393543"></a>

### 新增特性<a name="section168131939145418"></a>

-   新增dump系统属性功能。
-   为上层各模块新增内存池管理接口。

## 驱动<a name="section1793134012548"></a>

### 新增特性<a name="section69313406541"></a>

-   新增sensor、input、display驱动模型。
-   新增mipi dsi以及pwm（脉冲宽度调制）。
-   新增WIFI HDI接口以及WIFI的流控。
-   新增驱动框架IO服务分组特性。

### 修改特性<a name="section10931340175420"></a>

-   优化驱动加载流程，支持分段加载。

## 分布式通信<a name="section11286194113540"></a>

### 新增特性<a name="section14286104112546"></a>

-   新增WiFi Aware特性模块。
-   IPC新增对非对齐序列化的支持。

## 安全<a name="section4535841205411"></a>

### 新增特性<a name="section35351941175420"></a>

-   新增HUKS提供SHA256/RSA3072/RSA2048/AES128/ECC安全算法以及接口，以及提供密钥管理和存储能力。
-   HiChain提供轻量非账号的轻量级组件，用于设备群组管理和认证，支撑软总线通讯安全；提供API给系统服务与应用。
-   权限管理新增统一的权限管理机制，满足轻量设备权限授权需求。

## AI子系统<a name="section11847124175419"></a>

### 新增特性<a name="section148472413546"></a>

-   新增统一的AI引擎框架，实现算法能力快速插件化集成。框架中主要包含插件管理、模块管理和通信管理等模块，对AI算法能力进行生命周期管理和按需部署
-   为开发者提供开发指南，并提供2个基于AI引擎框架开发的AI能力插件和对应的AI应用Sample，方便开发者在AI引擎框架中快速集成AI算法能力。

## 升级服务<a name="section09814210543"></a>

### 新增特性<a name="section7981542105417"></a>

-   新增轻量级设备升级能力框架，框架包括升级包的效验和解析能力，以及安装的接口，统一轻设备升级能力框架。

## XTS认证<a name="section429384295416"></a>

### 新增特性<a name="section929316426547"></a>

-   增加AI、DFX、global、OTA兼容性测试用例。

### 修改特性<a name="section829419420543"></a>

-   应用程序框架、公共通信、分布式任务调度、IOT、内核等测试能力增强。

## 编译构建<a name="section104691342105411"></a>

### 新增特性<a name="section34699428546"></a>

-   新增命令行工具hb, 采用hb set和hb build方式构建，并支持在源码目录下及任意子目录下构建。
-   支持独立芯片厂商组件。
-   支持使用组件名单独构建组件。
-   支持按开发板自定义编译工具链和编译选项。

### 修改特性<a name="section946974210546"></a>

-   产品配置与build\_lite仓解耦，修改为“vendor/解决方案厂商/产品/config.json”。

## 电源管理<a name="section13166639141617"></a>

### 新增特性<a name="section313912368292"></a>

-   电量查询功能。
-   亮屏锁管理功能及接口。

## 组件仓优化<a name="section13139145855718"></a>

<a name="table135021051501"></a>
<table><thead align="left"><tr id="row128991056015"><th class="cellrowborder" valign="top" width="34%" id="mcps1.1.4.1.1"><p id="p78991551504"><a name="p78991551504"></a><a name="p78991551504"></a>OpenHarmony1.0</p>
</th>
<th class="cellrowborder" valign="top" width="32.79%" id="mcps1.1.4.1.2"><p id="p11899135701"><a name="p11899135701"></a><a name="p11899135701"></a>OpenHarmony1.0 .1</p>
</th>
<th class="cellrowborder" valign="top" width="33.21%" id="mcps1.1.4.1.3"><p id="p20899554011"><a name="p20899554011"></a><a name="p20899554011"></a>优化方式</p>
</th>
</tr>
</thead>
<tbody><tr id="row18991355019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p38991651802"><a name="p38991651802"></a><a name="p38991651802"></a>ace_lite_jsfwk</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p28991051202"><a name="p28991051202"></a><a name="p28991051202"></a>ace_engine_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4899851503"><a name="p4899851503"></a><a name="p4899851503"></a>仓名变更</p>
</td>
</tr>
<tr id="row38991351015"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1989910515019"><a name="p1989910515019"></a><a name="p1989910515019"></a>ace_interfaces_innerkits_builtin</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p48991551507"><a name="p48991551507"></a><a name="p48991551507"></a>只读归档</p>
</td>
</tr>
<tr id="row16899454019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p2899351009"><a name="p2899351009"></a><a name="p2899351009"></a>ai_engine</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p58991256010"><a name="p58991256010"></a><a name="p58991256010"></a>新增组件</p>
</td>
</tr>
<tr id="row14899155409"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1789916520011"><a name="p1789916520011"></a><a name="p1789916520011"></a>hiviewdfx_frameworks_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p9899551909"><a name="p9899551909"></a><a name="p9899551909"></a>hiviewdfx_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p18991851203"><a name="p18991851203"></a><a name="p18991851203"></a>仓名变更</p>
</td>
</tr>
<tr id="row789911515019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p4900651807"><a name="p4900651807"></a><a name="p4900651807"></a>hiviewdfx_frameworks_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1900151503"><a name="p1900151503"></a><a name="p1900151503"></a>hiviewdfx_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19001258015"><a name="p19001258015"></a><a name="p19001258015"></a>仓名变更</p>
</td>
</tr>
<tr id="row090015516018"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p189001351400"><a name="p189001351400"></a><a name="p189001351400"></a>hiviewdfx_utils_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p89001953019"><a name="p89001953019"></a><a name="p89001953019"></a>hiviewdfx_hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p89007519012"><a name="p89007519012"></a><a name="p89007519012"></a>仓名变更</p>
</td>
</tr>
<tr id="row8900351206"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p18900185100"><a name="p18900185100"></a><a name="p18900185100"></a>hiviewdfx_frameworks_ddrdump_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1490018511020"><a name="p1490018511020"></a><a name="p1490018511020"></a>只读归档</p>
</td>
</tr>
<tr id="row169001451604"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p179001854019"><a name="p179001854019"></a><a name="p179001854019"></a>hiviewdfx_interfaces_innerkits_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p390011512017"><a name="p390011512017"></a><a name="p390011512017"></a>只读归档</p>
</td>
</tr>
<tr id="row1990015602"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p129001151404"><a name="p129001151404"></a><a name="p129001151404"></a>hiviewdfx_interfaces_innerkits_hilog</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p590025106"><a name="p590025106"></a><a name="p590025106"></a>只读归档</p>
</td>
</tr>
<tr id="row09002051508"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p390095603"><a name="p390095603"></a><a name="p390095603"></a>hiviewdfx_interfaces_kits_hilog</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1390025504"><a name="p1390025504"></a><a name="p1390025504"></a>只读归档</p>
</td>
</tr>
<tr id="row1900454019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p690013514012"><a name="p690013514012"></a><a name="p690013514012"></a>hiviewdfx_interfaces_kits_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p15900956013"><a name="p15900956013"></a><a name="p15900956013"></a>只读归档</p>
</td>
</tr>
<tr id="row13900951602"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p18900051106"><a name="p18900051106"></a><a name="p18900051106"></a>hiviewdfx_services_hilogcat_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p12900155602"><a name="p12900155602"></a><a name="p12900155602"></a>只读归档</p>
</td>
</tr>
<tr id="row59001951809"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1190095906"><a name="p1190095906"></a><a name="p1190095906"></a>hiviewdfx_services_hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p69001951103"><a name="p69001951103"></a><a name="p69001951103"></a>只读归档</p>
</td>
</tr>
<tr id="row149001453013"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p179001152013"><a name="p179001152013"></a><a name="p179001152013"></a>iothardware_hals_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2901859018"><a name="p2901859018"></a><a name="p2901859018"></a>只读归档</p>
</td>
</tr>
<tr id="row199011654015"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1490115301"><a name="p1490115301"></a><a name="p1490115301"></a>iothardware_interfaces_kits_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p7901653019"><a name="p7901653019"></a><a name="p7901653019"></a>只读归档</p>
</td>
</tr>
<tr id="row2090125101"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p190117513010"><a name="p190117513010"></a><a name="p190117513010"></a>iothardware_frameworks_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p189011351501"><a name="p189011351501"></a><a name="p189011351501"></a>iothardware_peripheral</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1190119515013"><a name="p1190119515013"></a><a name="p1190119515013"></a>仓名变更</p>
</td>
</tr>
<tr id="row5901175902"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p109011755019"><a name="p109011755019"></a><a name="p109011755019"></a>applications_camera_sample_communication</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p209011455011"><a name="p209011455011"></a><a name="p209011455011"></a>新增组件</p>
</td>
</tr>
<tr id="row12901251206"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p12901051000"><a name="p12901051000"></a><a name="p12901051000"></a>applications_camera_screensaver_app</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p15901758014"><a name="p15901758014"></a><a name="p15901758014"></a>新增组件</p>
</td>
</tr>
<tr id="row79011551003"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1090111513011"><a name="p1090111513011"></a><a name="p1090111513011"></a>sensors_miscdevice_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19011152018"><a name="p19011152018"></a><a name="p19011152018"></a>新增组件</p>
</td>
</tr>
<tr id="row18901751205"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p7901051301"><a name="p7901051301"></a><a name="p7901051301"></a>sensors_sensor_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p7901252014"><a name="p7901252014"></a><a name="p7901252014"></a>新增组件</p>
</td>
</tr>
<tr id="row1990114512019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p10901135405"><a name="p10901135405"></a><a name="p10901135405"></a>xts_tools_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p16901551807"><a name="p16901551807"></a><a name="p16901551807"></a>xts_tools</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p169011451706"><a name="p169011451706"></a><a name="p169011451706"></a>仓名变更</p>
</td>
</tr>
<tr id="row49019510016"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p390113517013"><a name="p390113517013"></a><a name="p390113517013"></a>security_services_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p590112515010"><a name="p590112515010"></a><a name="p590112515010"></a>security_permission</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p179011251300"><a name="p179011251300"></a><a name="p179011251300"></a>仓名变更</p>
</td>
</tr>
<tr id="row1190120511014"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p29021551601"><a name="p29021551601"></a><a name="p29021551601"></a>security_interfaces_innerkits_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p99021751009"><a name="p99021751009"></a><a name="p99021751009"></a>只读归档</p>
</td>
</tr>
<tr id="row15902153011"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1390216512012"><a name="p1390216512012"></a><a name="p1390216512012"></a>security_interfaces_kits_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p189021551008"><a name="p189021551008"></a><a name="p189021551008"></a>只读归档</p>
</td>
</tr>
<tr id="row5902757019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p3902750014"><a name="p3902750014"></a><a name="p3902750014"></a>security_services_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p89021451008"><a name="p89021451008"></a><a name="p89021451008"></a>security_itrustee_ree_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p790295805"><a name="p790295805"></a><a name="p790295805"></a>仓名变更</p>
</td>
</tr>
<tr id="row13902158011"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p15902185306"><a name="p15902185306"></a><a name="p15902185306"></a>security_interfaces_innerkits_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p18902459015"><a name="p18902459015"></a><a name="p18902459015"></a>只读归档</p>
</td>
</tr>
<tr id="row2902651507"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p2090295504"><a name="p2090295504"></a><a name="p2090295504"></a>security_frameworks_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4902252003"><a name="p4902252003"></a><a name="p4902252003"></a>只读归档</p>
</td>
</tr>
<tr id="row12902115409"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p390214518017"><a name="p390214518017"></a><a name="p390214518017"></a>security_services_app_verify</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p159021851709"><a name="p159021851709"></a><a name="p159021851709"></a>security_appverify</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p209021751609"><a name="p209021751609"></a><a name="p209021751609"></a>仓名变更</p>
</td>
</tr>
<tr id="row790215515011"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p17902165204"><a name="p17902165204"></a><a name="p17902165204"></a>security_interfaces_innerkits_app_verify</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p3902145906"><a name="p3902145906"></a><a name="p3902145906"></a>只读归档</p>
</td>
</tr>
<tr id="row189021251020"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p39021051909"><a name="p39021051909"></a><a name="p39021051909"></a>security_services_hichainsdk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p99021551601"><a name="p99021551601"></a><a name="p99021551601"></a>security_deviceauth</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4902755017"><a name="p4902755017"></a><a name="p4902755017"></a>仓名变更</p>
</td>
</tr>
<tr id="row69024513016"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p11902151703"><a name="p11902151703"></a><a name="p11902151703"></a>security_interfaces_innerkits_hichainsdk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p16902135004"><a name="p16902135004"></a><a name="p16902135004"></a>只读归档</p>
</td>
</tr>
<tr id="row7902751304"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p290217510010"><a name="p290217510010"></a><a name="p290217510010"></a>security_services_huks_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p129030517016"><a name="p129030517016"></a><a name="p129030517016"></a>security_huks</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1590311518017"><a name="p1590311518017"></a><a name="p1590311518017"></a>仓名变更</p>
</td>
</tr>
<tr id="row39036518019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p49031354014"><a name="p49031354014"></a><a name="p49031354014"></a>security_interfaces_innerkits_huks_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p159031151900"><a name="p159031151900"></a><a name="p159031151900"></a>只读归档</p>
</td>
</tr>
<tr id="row11903951002"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p119032510018"><a name="p119032510018"></a><a name="p119032510018"></a>security_frameworks_crypto_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p99031516017"><a name="p99031516017"></a><a name="p99031516017"></a>只读归档</p>
</td>
</tr>
<tr id="row179032052011"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p4903155907"><a name="p4903155907"></a><a name="p4903155907"></a>security_interfaces_innerkits_crypto_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p39031451709"><a name="p39031451709"></a><a name="p39031451709"></a>只读归档</p>
</td>
</tr>
<tr id="row790305404"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p13903756014"><a name="p13903756014"></a><a name="p13903756014"></a>signcenter_tool</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2090355800"><a name="p2090355800"></a><a name="p2090355800"></a>新增组件</p>
</td>
</tr>
<tr id="row14903155009"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p12903155709"><a name="p12903155709"></a><a name="p12903155709"></a>third_party_cryptsetup</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1390315517010"><a name="p1390315517010"></a><a name="p1390315517010"></a>新增组件</p>
</td>
</tr>
<tr id="row1290315709"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1903951609"><a name="p1903951609"></a><a name="p1903951609"></a>third_party_JSON-C</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p18903851808"><a name="p18903851808"></a><a name="p18903851808"></a>新增组件</p>
</td>
</tr>
<tr id="row169031550016"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1090318516019"><a name="p1090318516019"></a><a name="p1090318516019"></a>third_party_libuuid</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2090313517013"><a name="p2090313517013"></a><a name="p2090313517013"></a>新增组件</p>
</td>
</tr>
<tr id="row1290305509"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p139031053012"><a name="p139031053012"></a><a name="p139031053012"></a>third_party_LVM2</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p119039519019"><a name="p119039519019"></a><a name="p119039519019"></a>新增组件</p>
</td>
</tr>
<tr id="row189031351503"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p16904652008"><a name="p16904652008"></a><a name="p16904652008"></a>third_party_popt</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p690417513011"><a name="p690417513011"></a><a name="p690417513011"></a>新增组件</p>
</td>
</tr>
<tr id="row13904135302"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p390410516020"><a name="p390410516020"></a><a name="p390410516020"></a>communication_interfaces_kits_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1490425305"><a name="p1490425305"></a><a name="p1490425305"></a>只读归档</p>
</td>
</tr>
<tr id="row59041451107"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p13904145808"><a name="p13904145808"></a><a name="p13904145808"></a>communication_frameworks_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p99045513014"><a name="p99045513014"></a><a name="p99045513014"></a>只读归档</p>
</td>
</tr>
<tr id="row179049518012"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p13904751702"><a name="p13904751702"></a><a name="p13904751702"></a>communication_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p390410514013"><a name="p390410514013"></a><a name="p390410514013"></a>新增组件</p>
</td>
</tr>
<tr id="row890412510020"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p99046513011"><a name="p99046513011"></a><a name="p99046513011"></a>powermgr_powermgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1990445707"><a name="p1990445707"></a><a name="p1990445707"></a>新增组件</p>
</td>
</tr>
<tr id="row1390495903"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1390405403"><a name="p1390405403"></a><a name="p1390405403"></a>distributedschedule_services_dtbschedmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p18904359010"><a name="p18904359010"></a><a name="p18904359010"></a>distributedschedule_dms_fwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p59041515012"><a name="p59041515012"></a><a name="p59041515012"></a>仓名变更</p>
</td>
</tr>
<tr id="row89041511017"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p4904185205"><a name="p4904185205"></a><a name="p4904185205"></a>distributedschedule_services_safwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p169041051601"><a name="p169041051601"></a><a name="p169041051601"></a>distributedschedule_safwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p16904558011"><a name="p16904558011"></a><a name="p16904558011"></a>仓名变更</p>
</td>
</tr>
<tr id="row129041051309"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1990418519016"><a name="p1990418519016"></a><a name="p1990418519016"></a>distributedschedule_services_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p7904451500"><a name="p7904451500"></a><a name="p7904451500"></a>distributedschedule_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p69041515016"><a name="p69041515016"></a><a name="p69041515016"></a>仓名变更</p>
</td>
</tr>
<tr id="row29041654012"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p6904251409"><a name="p6904251409"></a><a name="p6904251409"></a>distributedschedule_interfaces_innerkits_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p49054519014"><a name="p49054519014"></a><a name="p49054519014"></a>只读归档</p>
</td>
</tr>
<tr id="row490519515016"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1590518513015"><a name="p1590518513015"></a><a name="p1590518513015"></a>distributedschedule_interfaces_kits_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p590512516020"><a name="p590512516020"></a><a name="p590512516020"></a>只读归档</p>
</td>
</tr>
<tr id="row390515106"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p189051352019"><a name="p189051352019"></a><a name="p189051352019"></a>multimedia_frameworks_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p13905651405"><a name="p13905651405"></a><a name="p13905651405"></a>multimedia_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1390511520013"><a name="p1390511520013"></a><a name="p1390511520013"></a>仓名变更</p>
</td>
</tr>
<tr id="row29051051303"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p2090535308"><a name="p2090535308"></a><a name="p2090535308"></a>multimedia_frameworks_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p6905753013"><a name="p6905753013"></a><a name="p6905753013"></a>multimedia_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2090510511013"><a name="p2090510511013"></a><a name="p2090510511013"></a>仓名变更</p>
</td>
</tr>
<tr id="row1890565703"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p69051651509"><a name="p69051651509"></a><a name="p69051651509"></a>multimedia_frameworks_player_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p89051758015"><a name="p89051758015"></a><a name="p89051758015"></a>multimedia_media_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p109052513016"><a name="p109052513016"></a><a name="p109052513016"></a>仓名变更</p>
</td>
</tr>
<tr id="row19051050015"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p139051156020"><a name="p139051156020"></a><a name="p139051156020"></a>multimedia_hals_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1190555805"><a name="p1190555805"></a><a name="p1190555805"></a>只读归档</p>
</td>
</tr>
<tr id="row15905451704"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p20905651702"><a name="p20905651702"></a><a name="p20905651702"></a>multimedia_frameworks_recorder_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p39051251013"><a name="p39051251013"></a><a name="p39051251013"></a>只读归档</p>
</td>
</tr>
<tr id="row209051950012"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p159051559016"><a name="p159051559016"></a><a name="p159051559016"></a>multimedia_interfaces_kits_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p129051653013"><a name="p129051653013"></a><a name="p129051653013"></a>只读归档</p>
</td>
</tr>
<tr id="row7905851019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p109054519019"><a name="p109054519019"></a><a name="p109054519019"></a>multimedia_interfaces_kits_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p79063518015"><a name="p79063518015"></a><a name="p79063518015"></a>只读归档</p>
</td>
</tr>
<tr id="row79061552006"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p59062516015"><a name="p59062516015"></a><a name="p59062516015"></a>multimedia_interfaces_kits_player_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p5906195601"><a name="p5906195601"></a><a name="p5906195601"></a>只读归档</p>
</td>
</tr>
<tr id="row9906651205"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1190613512010"><a name="p1190613512010"></a><a name="p1190613512010"></a>multimedia_interfaces_kits_recorder_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19061551016"><a name="p19061551016"></a><a name="p19061551016"></a>只读归档</p>
</td>
</tr>
<tr id="row32651402491"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p15265194016496"><a name="p15265194016496"></a><a name="p15265194016496"></a>multimedia_services_media_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4377165314916"><a name="p4377165314916"></a><a name="p4377165314916"></a>只读归档</p>
</td>
</tr>
<tr id="row19061253012"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p6906651108"><a name="p6906651108"></a><a name="p6906651108"></a>kernel_liteos_a_huawei_proprietary_fs_proc</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p190635804"><a name="p190635804"></a><a name="p190635804"></a>只读归档</p>
</td>
</tr>
<tr id="row09064517018"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p109061459014"><a name="p109061459014"></a><a name="p109061459014"></a>third_party_mksh</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p7906257017"><a name="p7906257017"></a><a name="p7906257017"></a>新增组件</p>
</td>
</tr>
<tr id="row690635003"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p9906551104"><a name="p9906551104"></a><a name="p9906551104"></a>third_party_optimized_routines</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1690655209"><a name="p1690655209"></a><a name="p1690655209"></a>新增组件</p>
</td>
</tr>
<tr id="row4906951707"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1290685708"><a name="p1290685708"></a><a name="p1290685708"></a>third_party_toybox</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19062051309"><a name="p19062051309"></a><a name="p19062051309"></a>新增组件</p>
</td>
</tr>
<tr id="row15906451400"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p990625604"><a name="p990625604"></a><a name="p990625604"></a>vendor_huawei_camera</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p129061251702"><a name="p129061251702"></a><a name="p129061251702"></a>只读归档</p>
</td>
</tr>
<tr id="row1490614514010"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1190655105"><a name="p1190655105"></a><a name="p1190655105"></a>vendor_huawei_wifi_iot</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p149071354015"><a name="p149071354015"></a><a name="p149071354015"></a>只读归档</p>
</td>
</tr>
<tr id="row1290715517015"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p29071151309"><a name="p29071151309"></a><a name="p29071151309"></a>startup_services_bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p119075510011"><a name="p119075510011"></a><a name="p119075510011"></a>startup_bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p9907255016"><a name="p9907255016"></a><a name="p9907255016"></a>仓名变更</p>
</td>
</tr>
<tr id="row2907165707"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p9907451206"><a name="p9907451206"></a><a name="p9907451206"></a>startup_frameworks_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1490712516010"><a name="p1490712516010"></a><a name="p1490712516010"></a>startup_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p59072514018"><a name="p59072514018"></a><a name="p59072514018"></a>仓名变更</p>
</td>
</tr>
<tr id="row9907053012"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p159076513015"><a name="p159076513015"></a><a name="p159076513015"></a>startup_hals_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p09081451600"><a name="p09081451600"></a><a name="p09081451600"></a>只读归档</p>
</td>
</tr>
<tr id="row17908751903"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p39084514010"><a name="p39084514010"></a><a name="p39084514010"></a>startup_interfaces_kits_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1490818519019"><a name="p1490818519019"></a><a name="p1490818519019"></a>只读归档</p>
</td>
</tr>
<tr id="row10908125707"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p990814513015"><a name="p990814513015"></a><a name="p990814513015"></a>graphic_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p15908951808"><a name="p15908951808"></a><a name="p15908951808"></a>graphic_surface</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4908135408"><a name="p4908135408"></a><a name="p4908135408"></a>仓名变更</p>
</td>
</tr>
<tr id="row199081551901"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p199081051301"><a name="p199081051301"></a><a name="p199081051301"></a>graphic_ui</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p179086517016"><a name="p179086517016"></a><a name="p179086517016"></a>新增组件</p>
</td>
</tr>
<tr id="row199086519015"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p169081751402"><a name="p169081751402"></a><a name="p169081751402"></a>graphic_utils</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p990815906"><a name="p990815906"></a><a name="p990815906"></a>新增组件</p>
</td>
</tr>
<tr id="row1908155706"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p12908851907"><a name="p12908851907"></a><a name="p12908851907"></a>graphic_wms</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p139084511017"><a name="p139084511017"></a><a name="p139084511017"></a>新增组件</p>
</td>
</tr>
<tr id="row13908751904"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p16909151205"><a name="p16909151205"></a><a name="p16909151205"></a>third_party_giflib</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p89091851807"><a name="p89091851807"></a><a name="p89091851807"></a>新增组件</p>
</td>
</tr>
<tr id="row890914518017"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p090913519020"><a name="p090913519020"></a><a name="p090913519020"></a>third_party_qrcodegen</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p8909453015"><a name="p8909453015"></a><a name="p8909453015"></a>新增组件</p>
</td>
</tr>
<tr id="row14909954015"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p5909758010"><a name="p5909758010"></a><a name="p5909758010"></a>drivers_adapter_khdf_linux</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1590975106"><a name="p1590975106"></a><a name="p1590975106"></a>新增组件</p>
</td>
</tr>
<tr id="row16909251302"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p199097510018"><a name="p199097510018"></a><a name="p199097510018"></a>drivers_hdf_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p790955108"><a name="p790955108"></a><a name="p790955108"></a>drivers_adapter_khdf_liteos</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p20909251301"><a name="p20909251301"></a><a name="p20909251301"></a>仓名变更</p>
</td>
</tr>
<tr id="row16909256018"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p09101651205"><a name="p09101651205"></a><a name="p09101651205"></a>drivers_adapter_uhdf</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p18910251107"><a name="p18910251107"></a><a name="p18910251107"></a>新增组件</p>
</td>
</tr>
<tr id="row13910559012"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1891011517010"><a name="p1891011517010"></a><a name="p1891011517010"></a>drivers_hdf_frameworks</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p6910954011"><a name="p6910954011"></a><a name="p6910954011"></a>drivers_framework</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p89102518017"><a name="p89102518017"></a><a name="p89102518017"></a>仓名变更</p>
</td>
</tr>
<tr id="row39101851804"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p119101951909"><a name="p119101951909"></a><a name="p119101951909"></a>drivers_peripheral_audio</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p79105515016"><a name="p79105515016"></a><a name="p79105515016"></a>新增组件</p>
</td>
</tr>
<tr id="row49101352014"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p29101751908"><a name="p29101751908"></a><a name="p29101751908"></a>drivers_peripheral_codec</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p29109516013"><a name="p29109516013"></a><a name="p29109516013"></a>新增组件</p>
</td>
</tr>
<tr id="row69101651604"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p79101552020"><a name="p79101552020"></a><a name="p79101552020"></a>drivers_peripheral_display</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1910756017"><a name="p1910756017"></a><a name="p1910756017"></a>新增组件</p>
</td>
</tr>
<tr id="row16910125109"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p19911651009"><a name="p19911651009"></a><a name="p19911651009"></a>drivers_peripheral_format</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p39113518019"><a name="p39113518019"></a><a name="p39113518019"></a>新增组件</p>
</td>
</tr>
<tr id="row179119516018"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p139111651602"><a name="p139111651602"></a><a name="p139111651602"></a>drivers_peripheral_input</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1491114519013"><a name="p1491114519013"></a><a name="p1491114519013"></a>新增组件</p>
</td>
</tr>
<tr id="row189114517010"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p09115513010"><a name="p09115513010"></a><a name="p09115513010"></a>drivers_peripheral_sensor</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p59111558013"><a name="p59111558013"></a><a name="p59111558013"></a>新增组件</p>
</td>
</tr>
<tr id="row159111853017"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p19911555019"><a name="p19911555019"></a><a name="p19911555019"></a>drivers_peripheral_wlan</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p791113512014"><a name="p791113512014"></a><a name="p791113512014"></a>新增组件</p>
</td>
</tr>
<tr id="row99111150015"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p09118516019"><a name="p09118516019"></a><a name="p09118516019"></a>global_cust_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p109118512013"><a name="p109118512013"></a><a name="p109118512013"></a>新增组件</p>
</td>
</tr>
<tr id="row1191135703"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p59111551405"><a name="p59111551405"></a><a name="p59111551405"></a>global_i18n_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1491175703"><a name="p1491175703"></a><a name="p1491175703"></a>新增组件</p>
</td>
</tr>
<tr id="row11911115801"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p159111553016"><a name="p159111553016"></a><a name="p159111553016"></a>global_frameworks_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p149111851608"><a name="p149111851608"></a><a name="p149111851608"></a>global_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p16911456013"><a name="p16911456013"></a><a name="p16911456013"></a>仓名变更</p>
</td>
</tr>
<tr id="row17911257010"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1991211515015"><a name="p1991211515015"></a><a name="p1991211515015"></a>third_party_icu</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p17912175808"><a name="p17912175808"></a><a name="p17912175808"></a>新增组件</p>
</td>
</tr>
<tr id="row69121257015"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p139129511011"><a name="p139129511011"></a><a name="p139129511011"></a>global_interfaces_innerkits_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19121651105"><a name="p19121651105"></a><a name="p19121651105"></a>只读归档</p>
</td>
</tr>
<tr id="row129122051305"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1691295602"><a name="p1691295602"></a><a name="p1691295602"></a>communication_frameworks_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1091210518012"><a name="p1091210518012"></a><a name="p1091210518012"></a>communication_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19912458020"><a name="p19912458020"></a><a name="p19912458020"></a>仓名变更</p>
</td>
</tr>
<tr id="row291295508"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p209121510017"><a name="p209121510017"></a><a name="p209121510017"></a>communication_interfaces_kits_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1291217511018"><a name="p1291217511018"></a><a name="p1291217511018"></a>只读归档</p>
</td>
</tr>
<tr id="row199121951509"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p119125517016"><a name="p119125517016"></a><a name="p119125517016"></a>communication_interfaces_kits_softbuskit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p199127511014"><a name="p199127511014"></a><a name="p199127511014"></a>只读归档</p>
</td>
</tr>
<tr id="row69127510010"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p209129510013"><a name="p209129510013"></a><a name="p209129510013"></a>communication_hals_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p13912851018"><a name="p13912851018"></a><a name="p13912851018"></a>只读归档</p>
</td>
</tr>
<tr id="row12912351309"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p16912559013"><a name="p16912559013"></a><a name="p16912559013"></a>communication_services_softbus_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p17912151808"><a name="p17912151808"></a><a name="p17912151808"></a>communication_softbus_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p20912051904"><a name="p20912051904"></a><a name="p20912051904"></a>仓名变更</p>
</td>
</tr>
<tr id="row99128517010"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p139126520013"><a name="p139126520013"></a><a name="p139126520013"></a>communication_wifi_aware</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p891385705"><a name="p891385705"></a><a name="p891385705"></a>新增组件</p>
</td>
</tr>
<tr id="row159139518017"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p391365808"><a name="p391365808"></a><a name="p391365808"></a>update_ota_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p69131252020"><a name="p69131252020"></a><a name="p69131252020"></a>新增组件</p>
</td>
</tr>
<tr id="row139135511018"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1691317511019"><a name="p1691317511019"></a><a name="p1691317511019"></a>vendor_hisi_hi35xx_hi35xx_init</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p199131956012"><a name="p199131956012"></a><a name="p199131956012"></a>device_hisilicon_build</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p79133512013"><a name="p79133512013"></a><a name="p79133512013"></a>仓名变更</p>
</td>
</tr>
<tr id="row29131151901"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1913125306"><a name="p1913125306"></a><a name="p1913125306"></a>vendor_hisi_hi35xx_platform</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p15913054011"><a name="p15913054011"></a><a name="p15913054011"></a>device_hisilicon_drivers</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p139139512019"><a name="p139139512019"></a><a name="p139139512019"></a>仓名变更</p>
</td>
</tr>
<tr id="row19913251008"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p17913655013"><a name="p17913655013"></a><a name="p17913655013"></a>vendor_hisi_hi35xx_hardware</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p16913151004"><a name="p16913151004"></a><a name="p16913151004"></a>device_hisilicon_hardware</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1191316520013"><a name="p1191316520013"></a><a name="p1191316520013"></a>仓名变更</p>
</td>
</tr>
<tr id="row199135511012"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p179131051804"><a name="p179131051804"></a><a name="p179131051804"></a>vendor_hisi_hi35xx_hi3518ev300</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1291319518016"><a name="p1291319518016"></a><a name="p1291319518016"></a>device_hisilicon_hispark_aries</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p5913125106"><a name="p5913125106"></a><a name="p5913125106"></a>仓名变更</p>
</td>
</tr>
<tr id="row139131351308"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p10913457011"><a name="p10913457011"></a><a name="p10913457011"></a>vendor_hisi_hi3861_hi3861</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p16913165403"><a name="p16913165403"></a><a name="p16913165403"></a>device_hisilicon_hispark_pegasus</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1191365602"><a name="p1191365602"></a><a name="p1191365602"></a>仓名变更</p>
</td>
</tr>
<tr id="row99131651908"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1191365000"><a name="p1191365000"></a><a name="p1191365000"></a>vendor_hisi_hi35xx_hi3516dv300</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p2913195102"><a name="p2913195102"></a><a name="p2913195102"></a>device_hisilicon_hispark_taurus</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1491320518015"><a name="p1491320518015"></a><a name="p1491320518015"></a>仓名变更</p>
</td>
</tr>
<tr id="row11913651308"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p19913955017"><a name="p19913955017"></a><a name="p19913955017"></a>vendor_hisi_hi35xx_middleware</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p89132513013"><a name="p89132513013"></a><a name="p89132513013"></a>device_hisilicon_modules</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p17913115909"><a name="p17913115909"></a><a name="p17913115909"></a>仓名变更</p>
</td>
</tr>
<tr id="row1913252013"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p29141351408"><a name="p29141351408"></a><a name="p29141351408"></a>vendor_hisi_hi35xx_middleware_source_third_party_ffmpeg</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p791420518016"><a name="p791420518016"></a><a name="p791420518016"></a>device_hisilicon_third_party_ffmpeg</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1391418512014"><a name="p1391418512014"></a><a name="p1391418512014"></a>仓名变更</p>
</td>
</tr>
<tr id="row19914251203"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p69141751009"><a name="p69141751009"></a><a name="p69141751009"></a>vendor_hisi_hi35xx_thirdparty_uboot_src</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p12914751907"><a name="p12914751907"></a><a name="p12914751907"></a>device_hisilicon_third_party_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2914350011"><a name="p2914350011"></a><a name="p2914350011"></a>仓名变更</p>
</td>
</tr>
<tr id="row791405607"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p1191410510011"><a name="p1191410510011"></a><a name="p1191410510011"></a>vendor_hisilicon</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2914451805"><a name="p2914451805"></a><a name="p2914451805"></a>新增组件</p>
</td>
</tr>
<tr id="row1491415901"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p8914951407"><a name="p8914951407"></a><a name="p8914951407"></a>vendor_hisi_hi35xx_hi3516dv300_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2091415516011"><a name="p2091415516011"></a><a name="p2091415516011"></a>只读归档</p>
</td>
</tr>
<tr id="row119143517013"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1491495903"><a name="p1491495903"></a><a name="p1491495903"></a>vendor_hisi_hi35xx_hi3518ev300_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p159141551304"><a name="p159141551304"></a><a name="p159141551304"></a>只读归档</p>
</td>
</tr>
<tr id="row12914651909"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p13914851607"><a name="p13914851607"></a><a name="p13914851607"></a>aafwk_interfaces_innerkits_abilitykit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p12914115109"><a name="p12914115109"></a><a name="p12914115109"></a>只读归档</p>
</td>
</tr>
<tr id="row29141957010"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p139141657020"><a name="p139141657020"></a><a name="p139141657020"></a>aafwk_interfaces_innerkits_intent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p2091435204"><a name="p2091435204"></a><a name="p2091435204"></a>aafwk_aafwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p391418514016"><a name="p391418514016"></a><a name="p391418514016"></a>仓名变更</p>
</td>
</tr>
<tr id="row19144513010"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p49153516011"><a name="p49153516011"></a><a name="p49153516011"></a>aafwk_interfaces_innerkits_abilitymgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p9915952001"><a name="p9915952001"></a><a name="p9915952001"></a>只读归档</p>
</td>
</tr>
<tr id="row11915115409"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p11915751906"><a name="p11915751906"></a><a name="p11915751906"></a>appexecfwk_kits_appkit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p159151651909"><a name="p159151651909"></a><a name="p159151651909"></a>appexecfwk_appexecfwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p15915195103"><a name="p15915195103"></a><a name="p15915195103"></a>仓名变更</p>
</td>
</tr>
<tr id="row10915551806"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p159152051602"><a name="p159152051602"></a><a name="p159152051602"></a>aafwk_frameworks_kits_ability_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p11915135109"><a name="p11915135109"></a><a name="p11915135109"></a>只读归档</p>
</td>
</tr>
<tr id="row119151456011"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 "><p id="p139151754014"><a name="p139151754014"></a><a name="p139151754014"></a>developtools_packing_tool</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p13915251019"><a name="p13915251019"></a><a name="p13915251019"></a>新增组件</p>
</td>
</tr>
<tr id="row1291575909"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p79156518010"><a name="p79156518010"></a><a name="p79156518010"></a>aafwk_interfaces_kits_ability_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p189155518018"><a name="p189155518018"></a><a name="p189155518018"></a>只读归档</p>
</td>
</tr>
<tr id="row6915155303"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p5915125206"><a name="p5915125206"></a><a name="p5915125206"></a>appexecfwk_frameworks_bundle_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p3915751018"><a name="p3915751018"></a><a name="p3915751018"></a>只读归档</p>
</td>
</tr>
<tr id="row209151159020"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p891585809"><a name="p891585809"></a><a name="p891585809"></a>aafwk_services_abilitymgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p791585006"><a name="p791585006"></a><a name="p791585006"></a>只读归档</p>
</td>
</tr>
<tr id="row209156517018"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p09151755010"><a name="p09151755010"></a><a name="p09151755010"></a>appexecfwk_interfaces_innerkits_appexecfwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p09151551700"><a name="p09151551700"></a><a name="p09151551700"></a>只读归档</p>
</td>
</tr>
<tr id="row491614520017"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p69161151506"><a name="p69161151506"></a><a name="p69161151506"></a>appexecfwk_interfaces_innerkits_bundlemgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p791618511016"><a name="p791618511016"></a><a name="p791618511016"></a>只读归档</p>
</td>
</tr>
<tr id="row59162058016"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p1991645809"><a name="p1991645809"></a><a name="p1991645809"></a>appexecfwk_services_bundlemgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1091605202"><a name="p1091605202"></a><a name="p1091605202"></a>只读归档</p>
</td>
</tr>
<tr id="row2916054019"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.1.4.1.1 "><p id="p169164515019"><a name="p169164515019"></a><a name="p169164515019"></a>aafwk_frameworks_kits_content_lite</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p991617517013"><a name="p991617517013"></a><a name="p991617517013"></a>只读归档</p>
</td>
</tr>
</tbody>
</table>

\* 只读归档：组件仓归档到新的组织并设置为只读（openharmony-retired）。

\* 三方芯片代码与OS解耦，海思芯片SDK由Vendor目录迁移到device/hisilicon。

