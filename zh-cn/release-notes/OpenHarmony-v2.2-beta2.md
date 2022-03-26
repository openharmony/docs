# OpenHarmony v2.2 Beta2 <a name="ZH-CN_TOPIC_0000001182379069"></a>

-   [版本概述](#section1677664815431)
-   [配套关系](#section13201781528)
-   [源码获取](#section1350215462116)
-   [更新说明](#section11256141314463)
-   [修复缺陷列表](#section3442123281619)

## 版本概述<a name="section1677664815431"></a>

当前版本在OpenHarmony 2.0 Canary的基础上，针对轻量系统、小型系统和标准系统都有增加新的特性：

标准系统新增特性功能如下：

-   新增分布式远程拉起能力端到端的构建。
-   新增系统基础应用的拖拽能力和新增若干Sample应用。
-   新增媒体三大服务能力，提供更好的媒体系统功能。

轻量和小型系统新增特性功能如下：

-   新增小型系统linux版本构建能力。
-   新增轻量级内核能力增强，包括文件系统增强、内核调试工具增强支持、内核模块支持可配置、三方芯片适配支持、支持ARM9架构等。
-   轻量级图形能力增强支持，包括支持多语言字体对齐、支持显示控件轮廓、支持点阵字体、供统一多后端框架支持多芯片平台等。
-   DFX能力增强支持，包括HiLog功能增强、HiEvent功能增强，提供轻量级系统信息dump工具、提供重启维侧框架等。
-   AI能力增强支持，包括新增linux内核适配支持、AI引擎支持基于共享内存的数据传输。

## 配套关系<a name="section13201781528"></a>

**表 1**  版本软件和工具配套关系

<a name="table3398163217210"></a>
<table><thead align="left"><tr id="row1339820327212"><th class="cellrowborder" valign="top" width="28.622862286228624%" id="mcps1.2.4.1.1"><p id="p63988321828"><a name="p63988321828"></a><a name="p63988321828"></a>软件</p>
</th>
<th class="cellrowborder" valign="top" width="30.003000300030003%" id="mcps1.2.4.1.2"><p id="p7398133211216"><a name="p7398133211216"></a><a name="p7398133211216"></a>版本</p>
</th>
<th class="cellrowborder" valign="top" width="41.37413741374137%" id="mcps1.2.4.1.3"><p id="p1239913216212"><a name="p1239913216212"></a><a name="p1239913216212"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row113991632528"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p33994328215"><a name="p33994328215"></a><a name="p33994328215"></a>OpenHarmony</p>
</td>
<td class="cellrowborder" valign="top" width="30.003000300030003%" headers="mcps1.2.4.1.2 "><p id="p61561339133315"><a name="p61561339133315"></a><a name="p61561339133315"></a>2.2 Beta2</p>
</td>
<td class="cellrowborder" valign="top" width="41.37413741374137%" headers="mcps1.2.4.1.3 "><p id="p7316162554817"><a name="p7316162554817"></a><a name="p7316162554817"></a>NA</p>
</td>
</tr>
<tr id="row239911321527"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p193286111669"><a name="p193286111669"></a><a name="p193286111669"></a>HUAWEI DevEco Studio（可选）</p>
</td>
<td class="cellrowborder" valign="top" width="30.003000300030003%" headers="mcps1.2.4.1.2 "><p id="p83711419141513"><a name="p83711419141513"></a><a name="p83711419141513"></a>DevEco Studio 2.2 Beta1</p>
</td>
<td class="cellrowborder" valign="top" width="41.37413741374137%" headers="mcps1.2.4.1.3 "><p id="p12457193617153"><a name="p12457193617153"></a><a name="p12457193617153"></a>OpenHarmony应用开发推荐使用。</p>
</td>
</tr>
<tr id="row153991032926"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p17708321495"><a name="p17708321495"></a><a name="p17708321495"></a>HUAWEI DevEco Device Tool（可选）</p>
</td>
<td class="cellrowborder" valign="top" width="30.003000300030003%" headers="mcps1.2.4.1.2 "><p id="p145502371612"><a name="p145502371612"></a><a name="p145502371612"></a>Deveco DeviceTool 2.2 Beta1</p>
</td>
<td class="cellrowborder" valign="top" width="41.37413741374137%" headers="mcps1.2.4.1.3 "><p id="p1139765711198"><a name="p1139765711198"></a><a name="p1139765711198"></a>OpenHarmony智能设备集成开发环境推荐使用。</p>
</td>
</tr>
</tbody>
</table>

## 源码获取<a name="section1350215462116"></a>

### 通过repo下载

**方式一（推荐）**

通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v2.2-Beta2 --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v2.2-Beta2 --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 通过镜像站点下载

**表2** 源码获取路径

| 版本源码 | 版本信息 | 下载站点 | SHA256校验码 | 
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/code-v2.2-beta2_20210730.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/code-v2.2-beta2_20210730.tar.gz.sha256) | 
| 标准系统解决方案（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/standard-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/standard-2.2-Beta2.tar.gz.sha256) | 
| Hi3861解决方案（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_pegasus-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_pegasus-2.2-Beta2.tar.gz.sha256) | 
| Hi3518解决方案（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_aries-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_aries-2.2-Beta2.tar.gz.sha256) | 
| Hi3516解决方案-LiteOS（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus-2.2-Beta2.tar.gz.sha256) | 
| Hi3516解决方案-Linux（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus_linux-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus_linux-2.2-Beta2.tar.gz.sha256) | 
| Release&nbsp;Notes | 2.2 | [站点](https://gitee.com/openharmony/docs/blob/master/zh-cn/release-notes/OpenHarmony-v2.2-beta2.md) | - | 


## 更新说明<a name="section11256141314463"></a>

本版本在继承了OpenHarmony 2.0 Canary的基础上有如下变更。

### 特性变更

**表 3**  版本新增特性表

<a name="table1976311913503"></a>
<table><thead align="left"><tr id="row127631916501"><th class="cellrowborder" valign="top" width="23.04%" id="mcps1.2.4.1.1"><p id="p6763997509"><a name="p6763997509"></a><a name="p6763997509"></a>子系统名称</p>
</th>
<th class="cellrowborder" valign="top" width="41.6%" id="mcps1.2.4.1.2"><p id="p1176418919506"><a name="p1176418919506"></a><a name="p1176418919506"></a>标准系统</p>
</th>
<th class="cellrowborder" valign="top" width="35.36%" id="mcps1.2.4.1.3"><p id="p05751656182510"><a name="p05751656182510"></a><a name="p05751656182510"></a>轻量、小型系统</p>
</th>
</tr>
</thead>
<tbody><tr id="row12618619217"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p1626368217"><a name="p1626368217"></a><a name="p1626368217"></a>分布式文件</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p753217119019"><a name="p753217119019"></a><a name="p753217119019"></a>提供本地system.file异步文件操作JS API，包括文件读写、目录访问、增删等接口。</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p1257515560253"><a name="p1257515560253"></a><a name="p1257515560253"></a>NA</p>
</td>
</tr>
<tr id="row1697324472115"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p19973154462114"><a name="p19973154462114"></a><a name="p19973154462114"></a>驱动</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p178202347481"><a name="p178202347481"></a><a name="p178202347481"></a><a href="https://gitee.com/openharmony/drivers_framework/issues/I3QE85" target="_blank" rel="noopener noreferrer">3QE85</a>：新增Audio、Camera、USB、马达、ADC驱动模型。</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p18438192992613"><a name="p18438192992613"></a><a name="p18438192992613"></a>LiteOS-M支持HDF框架。</p>
</td>
</tr>
<tr id="row472717219225"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p147281129226"><a name="p147281129226"></a><a name="p147281129226"></a>电源管理服务</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p4668144017319"><a name="p4668144017319"></a><a name="p4668144017319"></a>新增系统电源状态机、休眠运行锁、休眠唤醒功能。</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul33391443142616"></a><a name="ul33391443142616"></a><ul id="ul33391443142616"><li>新增充放电状态查询接口、电量查询接口。</li><li>提供低功耗模式支持，并提供低功耗模式统一API支持。</li></ul>
</td>
</tr>
<tr id="row620911170236"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p162091917182319"><a name="p162091917182319"></a><a name="p162091917182319"></a>升级服务</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p18451433239"><a name="p18451433239"></a><a name="p18451433239"></a>新增恢复出厂功能。</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p7576205613250"><a name="p7576205613250"></a><a name="p7576205613250"></a>NA</p>
</td>
</tr>
<tr id="row271213617373"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p716961115372"><a name="p716961115372"></a><a name="p716961115372"></a>媒体</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><a name="ul108105123910"></a><a name="ul108105123910"></a><ul id="ul108105123910"><li>新增音频服务，提供音频基础控制能力。</li><li>新增相机服务，提供预览、拍照等基础功能力。</li><li>新增媒体服务，提供音频、视频播放能力。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p8576165610250"><a name="p8576165610250"></a><a name="p8576165610250"></a>NA</p>
</td>
</tr>
<tr id="row776714945019"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p0767179135017"><a name="p0767179135017"></a><a name="p0767179135017"></a>JS UI框架</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p1128414013613"><a name="p1128414013613"></a><a name="p1128414013613"></a>支持使用JS与C/C++混合开发JS API。</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p45762056192514"><a name="p45762056192514"></a><a name="p45762056192514"></a>NA</p>
</td>
</tr>
<tr id="row188861132252"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p18866362511"><a name="p18866362511"></a><a name="p18866362511"></a>事件通知</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p2024302141016"><a name="p2024302141016"></a><a name="p2024302141016"></a>支持应用本地发送、取消多行文本通知能力。</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p85761556122515"><a name="p85761556122515"></a><a name="p85761556122515"></a>NA</p>
</td>
</tr>
<tr id="row32413714262"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p424237152616"><a name="p424237152616"></a><a name="p424237152616"></a>分布式软总线</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p17236217843"><a name="p17236217843"></a><a name="p17236217843"></a>新增软总线自组网功能，可信设备接入到局域网中（ETH\WiFi）后可自发现、无感知的接入到软总线。</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p1857675611252"><a name="p1857675611252"></a><a name="p1857675611252"></a>NA</p>
</td>
</tr>
<tr id="row6307237105110"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p24971139185111"><a name="p24971139185111"></a><a name="p24971139185111"></a>分布式数据管理</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><a name="ul1411113817529"></a><a name="ul1411113817529"></a><ul id="ul1411113817529"><li>新增分布式数据管理能力，支持分布式数据库在本地加密存储</li><li>支持轻量级偏好数据库</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul59217181020"></a><a name="ul59217181020"></a><ul id="ul59217181020"><li>提供数据库内容的删除能力。</li><li>提供统一的HAL文件系统操作函数实现。</li><li>提供相关数据存储的原子操作能力。</li><li>提供二进制Value的写入读取能力。</li></ul>
</td>
</tr>
<tr id="row161918529268"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p066763616286"><a name="p066763616286"></a><a name="p066763616286"></a>系统应用</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p1490153195610"><a name="p1490153195610"></a><a name="p1490153195610"></a>桌面:</p>
<a name="ul16239155595614"></a><a name="ul16239155595614"></a><ul id="ul16239155595614"><li>桌面设置界面UX优化。</li><li>新增桌面图标拖拽特性。</li></ul>
<p id="p20905319564"><a name="p20905319564"></a><a name="p20905319564"></a>设置：</p>
<a name="ul245041017582"></a><a name="ul245041017582"></a><ul id="ul245041017582"><li>新增Wlan设置功能。</li></ul>
<p id="p1090143112566"><a name="p1090143112566"></a><a name="p1090143112566"></a>SystemUI：</p>
<a name="ul1027287584"></a><a name="ul1027287584"></a><ul id="ul1027287584"><li>新增卡信号图标显示功能。</li></ul>
<p id="p14903318562"><a name="p14903318562"></a><a name="p14903318562"></a>图库：</p>
<a name="ul172792055205811"></a><a name="ul172792055205811"></a><ul id="ul172792055205811"><li>新增图片、视频资源的查看、移动、复制、删除、重命名等功能。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p6576125602513"><a name="p6576125602513"></a><a name="p6576125602513"></a>NA</p>
</td>
</tr>
<tr id="row377318915507"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p777349105012"><a name="p777349105012"></a><a name="p777349105012"></a>全球化子系统</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><a name="ul18119906123"></a><a name="ul18119906123"></a><ul id="ul18119906123"><li>完善时间日期格式化能力。</li><li>支持时间段的格式化。</li><li>新增数字格式化能力。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul33981411321"></a><a name="ul33981411321"></a><ul id="ul33981411321"><li>新增构建自定义数据编译能力。</li><li>新增构建星期、单复数、数字开关国际化能力。</li><li>新增构建应用资源解析和加载机制。</li><li>新增构建资源回溯机制。</li></ul>
</td>
</tr>
<tr id="row20979141410276"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p129791114102719"><a name="p129791114102719"></a><a name="p129791114102719"></a>Sample应用</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><a name="ul3397818122718"></a><a name="ul3397818122718"></a><ul id="ul3397818122718"><li>计算器中新增分布式功能，组网后支持拉起另一台组网设备上的计算器，两台设备可协同计算，计算数据实时同步。</li><li>新增音频播放器应用，支持本地音频播放，组网后可将音乐播放接续至其他组网设备上。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p0576125692520"><a name="p0576125692520"></a><a name="p0576125692520"></a>NA</p>
</td>
</tr>
<tr id="row1474114139329"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p6741131317321"><a name="p6741131317321"></a><a name="p6741131317321"></a>分布式设备管理</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p143617933314"><a name="p143617933314"></a><a name="p143617933314"></a>新增设备管理系统服务，提供分布式设备账号无关的认证组网能力。</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p264113419105"><a name="p264113419105"></a><a name="p264113419105"></a>NA</p>
</td>
</tr>
<tr id="row832191324615"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p3331113194616"><a name="p3331113194616"></a><a name="p3331113194616"></a>DFX</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p47911168336"><a name="p47911168336"></a><a name="p47911168336"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul1469920194511"></a><a name="ul1469920194511"></a><ul id="ul1469920194511"><li>提供LiteOS内核系统信息dump工具。</li><li>提供LiteOS内核死机重启维测框架。</li><li>新增数字格式化能力。</li><li>HiLog功能增强。</li><li>HiEvent功能增强。</li></ul>
</td>
</tr>
<tr id="row1336310497544"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p173649490544"><a name="p173649490544"></a><a name="p173649490544"></a>内核</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p1300552183317"><a name="p1300552183317"></a><a name="p1300552183317"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul191101631555"></a><a name="ul191101631555"></a><ul id="ul191101631555"><li>支持轻量级Linux版本。</li><li>proc文件系统增强。</li><li>新增mksh命令解析器。</li><li>文件系统维测增强。</li><li>LiteOS-A內核模块支持可配置。</li><li>支持LiteOS-A小系统三方芯片适配。</li><li>LiteOS-M支持三方组件Mbedtls编译。</li><li>LiteOS-M支持三方组件curl编译。</li><li>支持轻量级shell框架和常用调测命令。</li><li>LiteOS-M支持ARM9架构。</li><li>支持基于NOR Flash的littlefs文件系统。</li><li>LiteOS-M对外提供统一的文件系统操作接口。</li><li>新增Namecache模块、Vnode管理、Lookup模块。</li></ul>
</td>
</tr>
<tr id="row192410715819"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p32567175813"><a name="p32567175813"></a><a name="p32567175813"></a>图形图像</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p182587563419"><a name="p182587563419"></a><a name="p182587563419"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul1742414363415"></a><a name="ul1742414363415"></a><ul id="ul1742414363415"><li>支持A4\A8、LUT8、TSC图片格式作为输入。</li><li>支持多语言字体对齐。</li><li>UIKit支持显示控件轮廓。</li><li>ScrollView/List支持通过弧形进度条展示滑动进度。</li><li>支持开关按钮/复选框/单选按钮动效。</li><li>UIKit支持点阵字体产品化解耦。</li><li>UI框架提供统一多后端框架支持多芯片平台。</li><li>UIKit组件支持margin/padding。</li><li>圆形/胶囊按钮支持缩放和白色蒙层动效。</li></ul>
</td>
</tr>
<tr id="row115211202598"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p11531320165912"><a name="p11531320165912"></a><a name="p11531320165912"></a>编译构建</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p2071212873418"><a name="p2071212873418"></a><a name="p2071212873418"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p1920101163411"><a name="p1920101163411"></a><a name="p1920101163411"></a>支持开源软件的通用patch框架。</p>
</td>
</tr>
<tr id="row63749231472"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p83746237713"><a name="p83746237713"></a><a name="p83746237713"></a>启动恢复</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p1261941520343"><a name="p1261941520343"></a><a name="p1261941520343"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p11807317133420"><a name="p11807317133420"></a><a name="p11807317133420"></a>支持恢复出厂设置支持多语言字体对齐。</p>
</td>
</tr>
<tr id="row1225911481986"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p1926017488814"><a name="p1926017488814"></a><a name="p1926017488814"></a>分布式调度</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p19901119123410"><a name="p19901119123410"></a><a name="p19901119123410"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p172611227345"><a name="p172611227345"></a><a name="p172611227345"></a>支持轻量设备启动富设备上的Ability。</p>
</td>
</tr>
<tr id="row1167365771317"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p0674357171314"><a name="p0674357171314"></a><a name="p0674357171314"></a>AI</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p8313182513345"><a name="p8313182513345"></a><a name="p8313182513345"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul16276418181411"></a><a name="ul16276418181411"></a><ul id="ul16276418181411"><li>AI子系统添加Linux内核适配，编译选项支持。</li><li>AI引擎支持基于共享内存的数据传输。</li></ul>
</td>
</tr>
</tbody>
</table>

### API变更

API变更请参考：

[JS API 差异报告](api-change/v2.2-beta2/js-apidiff-v2.2-beta2.md)

[Native API 差异报告](api-change/v2.2-beta2/native-apidiff-v2.2-beta2.md)

## 修复缺陷列表<a name="section3442123281619"></a>

**表 4** **解决的缺陷ISSUE列表**

<a name="table158451039191811"></a>

<table><thead align="left"><tr id="row178461539111814"><th class="cellrowborder" valign="top" width="13.15%" id="mcps1.2.3.1.1"><p id="p4846113915184"><a name="p4846113915184"></a><a name="p4846113915184"></a>ISSUE单号</p>
</th>
<th class="cellrowborder" valign="top" width="86.85000000000001%" id="mcps1.2.3.1.2"><p id="p4846039111815"><a name="p4846039111815"></a><a name="p4846039111815"></a>问题描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row8846163911187"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p18127341171919"><a name="p18127341171919"></a><a name="p18127341171919"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3I31W" target="_blank" rel="noopener noreferrer">I3I31W</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p01271941121913"><a name="p01271941121913"></a><a name="p01271941121913"></a>ActsNFSTest.bin会引起内核crash</p>
</td>
</tr>
<tr id="row1846113981818"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p14127174118199"><a name="p14127174118199"></a><a name="p14127174118199"></a><a href="https://gitee.com/openharmony/docs/issues/I3D49E" target="_blank" rel="noopener noreferrer">I3D49E</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p141271541131915"><a name="p141271541131915"></a><a name="p141271541131915"></a>uboot的路径不对</p>
</td>
</tr>
<tr id="row5846103901815"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p181274412195"><a name="p181274412195"></a><a name="p181274412195"></a><a href="https://gitee.com/openharmony-retired/drivers_adapter_khdf_liteos/issues/I3D71U" target="_blank" rel="noopener noreferrer">I3D71U</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p131271341151912"><a name="p131271341151912"></a><a name="p131271341151912"></a>【驱动子系统】反复reset，启动到hmac_main_init SUCCESSULLY后，高概率出现系统挂死</p>
</td>
</tr>
<tr id="row48467394184"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p812718412194"><a name="p812718412194"></a><a name="p812718412194"></a><a href="https://gitee.com/openharmony/aafwk_aafwk_lite/issues/I3DGZW" target="_blank" rel="noopener noreferrer">I3DGZW</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p3127164121913"><a name="p3127164121913"></a><a name="p3127164121913"></a>【应用程序框架子系统】HI3516开源板进入屏保后 ，点击触摸屏，出现蓝屏问题</p>
</td>
</tr>
<tr id="row984633901815"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1912812411199"><a name="p1912812411199"></a><a name="p1912812411199"></a><a href="https://gitee.com/openharmony/community/issues/I3DHIL" target="_blank" rel="noopener noreferrer">I3DHIL</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1412854111192"><a name="p1412854111192"></a><a name="p1412854111192"></a>【系统问题】HI3518开源板剩余空间不足，导致ACTS用例大量失败</p>
</td>
</tr>
<tr id="row984623913181"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1128184171917"><a name="p1128184171917"></a><a name="p1128184171917"></a><a href="https://gitee.com/openharmony/appexecfwk_appexecfwk_lite/issues/I3DU36" target="_blank" rel="noopener noreferrer">I3DU36</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p17128104114191"><a name="p17128104114191"></a><a name="p17128104114191"></a>【应用程序框架子系统】ipcamera bm 查询命令失效</p>
</td>
</tr>
<tr id="row4846193919186"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p16128174171917"><a name="p16128174171917"></a><a name="p16128174171917"></a><a href="https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU" target="_blank" rel="noopener noreferrer">I3EALU</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p8128184191914"><a name="p8128184191914"></a><a name="p8128184191914"></a>【媒体子系统】cameraActs 用例执行时，找不到相机配置文件，初始失败</p>
</td>
</tr>
<tr id="row851624131915"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1412814111917"><a name="p1412814111917"></a><a name="p1412814111917"></a><a href="https://gitee.com/openharmony/release-management/issues/I3EGUX" target="_blank" rel="noopener noreferrer">I3EGUX</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p161282419194"><a name="p161282419194"></a><a name="p161282419194"></a>【可靠性问题】反复reset，出现一次KIdle进程crash，系统挂死无法启动</p>
</td>
</tr>
<tr id="row1151162411915"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p181280416199"><a name="p181280416199"></a><a name="p181280416199"></a><a href="https://gitee.com/openharmony/community/issues/I3EH4E" target="_blank" rel="noopener noreferrer">I3EH4E</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p2128841121919"><a name="p2128841121919"></a><a name="p2128841121919"></a>【流水线问题】高概率出现：uname无响应，然后执行reset也无响应</p>
</td>
</tr>
<tr id="row051182419198"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p20128204114190"><a name="p20128204114190"></a><a name="p20128204114190"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3EQJA" target="_blank" rel="noopener noreferrer">I3EQJA</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1112813418191"><a name="p1112813418191"></a><a name="p1112813418191"></a>【文件系统】cat /proc/mounts功能不可用</p>
</td>
</tr>
<tr id="row451132491912"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1012844171912"><a name="p1012844171912"></a><a name="p1012844171912"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3EQRC" target="_blank" rel="noopener noreferrer">I3EQRC</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1612884110194"><a name="p1612884110194"></a><a name="p1612884110194"></a>磁盘文件映射延迟测试：并发3个测试进程，系统crash</p>
</td>
</tr>
<tr id="row551124141912"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1212854112194"><a name="p1212854112194"></a><a name="p1212854112194"></a><a href="https://gitee.com/openharmony/docs/issues/I3HVL0" target="_blank" rel="noopener noreferrer">I3HVL0</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p2128241151910"><a name="p2128241151910"></a><a name="p2128241151910"></a>3861编译失败，报错[OHOS ERROR] Fatal error: invalid -march= option:rv32imac</p>
</td>
</tr>
<tr id="row2065132419197"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1767317453201"><a name="p1767317453201"></a><a name="p1767317453201"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3TS1Y" target="_blank" rel="noopener noreferrer">I3TS1Y</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1667354518204"><a name="p1667354518204"></a><a name="p1667354518204"></a>压力场景下文件相关Vnode资源耗尽</p>
</td>
</tr>
<tr id="row1269122413190"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p13674845202014"><a name="p13674845202014"></a><a name="p13674845202014"></a><a href="https://gitee.com/openharmony/startup_init_lite/issues/I3TXT8" target="_blank" rel="noopener noreferrer">I3TXT8</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1267414592020"><a name="p1267414592020"></a><a name="p1267414592020"></a>孤儿进程无法回收，压力场景下TCB资源耗尽</p>
</td>
</tr>
<tr id="row1233105621912"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p176741745112010"><a name="p176741745112010"></a><a name="p176741745112010"></a><a href="https://gitee.com/openharmony/applications_sample_wifi_iot/issues/I3UWXI" target="_blank" rel="noopener noreferrer">I3UWXI</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p56742457209"><a name="p56742457209"></a><a name="p56742457209"></a>libwap.so 存在已知一般漏洞： CVE-2021-30004，CVSS：5.3；漏洞发布日期：2021-04-02，不符合产品发布要求，需要解决。</p>
</td>
</tr>
<tr id="row1723765610198"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p166741945122011"><a name="p166741945122011"></a><a name="p166741945122011"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3SWY2" target="_blank" rel="noopener noreferrer">I3SWY2</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p96741945132014"><a name="p96741945132014"></a><a name="p96741945132014"></a>高概率出现KProcess进程挂死，质量不达标</p>
</td>
</tr>
<tr id="row1359138112017"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p156744454206"><a name="p156744454206"></a><a name="p156744454206"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I3YJRO" target="_blank" rel="noopener noreferrer">I3YJRO</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p2067419456205"><a name="p2067419456205"></a><a name="p2067419456205"></a>liteos-a內核模块可配置编译失败</p>
</td>
</tr>
<tr id="row1635963862010"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p11674245202010"><a name="p11674245202010"></a><a name="p11674245202010"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3YNWM" target="_blank" rel="noopener noreferrer">I3YNWM</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p136742452208"><a name="p136742452208"></a><a name="p136742452208"></a>文件系统维测增强功能在该版本有问题</p>
</td>
</tr>
<tr id="row8360183892010"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p6674154522014"><a name="p6674154522014"></a><a name="p6674154522014"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3VEOG" target="_blank" rel="noopener noreferrer">I3VEOG</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p156747457204"><a name="p156747457204"></a><a name="p156747457204"></a>bin目录下没有mksh和toybox，导致已转测的toybox命令集无法测试</p>
</td>
</tr>
</tbody>
</table>

