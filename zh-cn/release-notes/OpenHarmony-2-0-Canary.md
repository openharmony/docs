# OpenHarmony 2.0 Canary（2021-06-01）<a name="ZH-CN_TOPIC_0000001102397706"></a>

-   [版本概述](#section1677664815431)
-   [配套关系](#section13201781528)
-   [源码获取](#源码获取)
-   [更新说明](#section11256141314463)

## 版本概述<a name="section1677664815431"></a>

当前版本在OpenHarmony 1.1.0的基础上，增加标准系统版本，具备的主要功能如下：

-   新增22个子系统，支持全面的OS能力，支持内存大于128M的带屏设备开发等。
-   提供系统三大应用：桌面、设置和SystemUI。
-   提供全新的OpenHarmony应用框架能力、Ability Cross-platform Engine能力。
-   提供JS应用开发能力。
-   提供媒体框架，支持音视频功能开发。
-   提供图形框架能力，支持窗口管理和合成，支持GPU能力。

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
<td class="cellrowborder" valign="top" width="30.003000300030003%" headers="mcps1.2.4.1.2 "><p id="p966216165485"><a name="p966216165485"></a><a name="p966216165485"></a>2.0 Canary</p>
</td>
<td class="cellrowborder" valign="top" width="41.37413741374137%" headers="mcps1.2.4.1.3 "><p id="p7316162554817"><a name="p7316162554817"></a><a name="p7316162554817"></a>NA</p>
</td>
</tr>
<tr id="row239911321527"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p193286111669"><a name="p193286111669"></a><a name="p193286111669"></a>HUAWEI DevEco Studio（可选）</p>
</td>
<td class="cellrowborder" valign="top" width="30.003000300030003%" headers="mcps1.2.4.1.2 "><p id="p83711419141513"><a name="p83711419141513"></a><a name="p83711419141513"></a>DevEco Studio 2.1 Release</p>
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

## 源码获取<a name="源码获取"></a>


### 通过repo下载

 **方式一（推荐）** 

通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

 ```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-2.0-Canary --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
 ```

 **方式二** 

通过repo + https 下载。

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-2.0-Canary --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 通过镜像站点获取

**表2** 源码获取路径

| 版本源码 | 版本信息 | 下载站点 | SHA256校验码 | 
| -------- | -------- | -------- | -------- |
| 全量代码 | 2.0 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary_20210601.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary_20210601.tar.gz.sha256) | 
| Release&nbsp;Notes | 2.0 | [站点](https://gitee.com/openharmony/docs/blob/master/zh-cn/release-notes/OpenHarmony-2-0-Canary.md) | - | 

## 更新说明<a name="section11256141314463"></a>

本版本完全继承了OpenHarmony 1.1.0的所有特性，并在OpenHarmony 1.1.0版本的基础上，新增标准系统版本形态，详情请参考下表 。

**表 2**  版本新增特性表

<a name="table1976311913503"></a>
<table><thead align="left"><tr id="row127631916501"><th class="cellrowborder" valign="top" width="24.94%" id="mcps1.2.3.1.1"><p id="p6763997509"><a name="p6763997509"></a><a name="p6763997509"></a>子系统名称</p>
</th>
<th class="cellrowborder" valign="top" width="75.06%" id="mcps1.2.3.1.2"><p id="p1176418919506"><a name="p1176418919506"></a><a name="p1176418919506"></a>新增特性</p>
</th>
</tr>
</thead>
<tbody><tr id="row37646915015"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p87641995507"><a name="p87641995507"></a><a name="p87641995507"></a>内核</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p0750218142312"><a name="p0750218142312"></a><a name="p0750218142312"></a>基于Linux Kernel LTS社区开源基线，回合CVE补丁，包含了OpenHarmony上层特性适配。</p>
</td>
</tr>
<tr id="row12618619217"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1626368217"><a name="p1626368217"></a><a name="p1626368217"></a>分布式文件</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p17116387289"><a name="p17116387289"></a><a name="p17116387289"></a>提供本地同步文件 JS 接口，包括文件读写、目录访问以及文件Stat。</p>
</td>
</tr>
<tr id="row855742119216"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1557921172115"><a name="p1557921172115"></a><a name="p1557921172115"></a>图形图像</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul6736012132813"></a><a name="ul6736012132813"></a><ul id="ul6736012132813"><li>新增窗口管理功能，包括创建、销毁和窗口栈管理等。</li><li>新增合成器功能，包括CPU、GPU和TDE合成。</li><li>新增bufferqueue功能，支持进程间传递。</li><li>新增vsync管理功能。</li></ul>
</td>
</tr>
<tr id="row1697324472115"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p19973154462114"><a name="p19973154462114"></a><a name="p19973154462114"></a>驱动</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p55681444121518"><a name="p55681444121518"></a><a name="p55681444121518"></a>新增用户态驱动框架。</p>
</td>
</tr>
<tr id="row472717219225"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p147281129226"><a name="p147281129226"></a><a name="p147281129226"></a>电源管理服务</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p68761043171814"><a name="p68761043171814"></a><a name="p68761043171814"></a>新增电源管理能力，包括关机服务、亮灭屏管理、亮度调节、电池状态查询、系统电源管理、休眠锁管理等功能。</p>
</td>
</tr>
<tr id="row19203133032216"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p23098422221"><a name="p23098422221"></a><a name="p23098422221"></a>多模输入子系统</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p122255019161"><a name="p122255019161"></a><a name="p122255019161"></a>新增支持单指触屏输入能力。</p>
</td>
</tr>
<tr id="row147681792310"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1440215238292"><a name="p1440215238292"></a><a name="p1440215238292"></a>启动恢复子系统</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p311264101619"><a name="p311264101619"></a><a name="p311264101619"></a>系统属性管理新增JS API。</p>
</td>
</tr>
<tr id="row620911170236"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p162091917182319"><a name="p162091917182319"></a><a name="p162091917182319"></a>升级服务</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1758215644919"></a><a name="ul1758215644919"></a><ul id="ul1758215644919"><li>新增recovery系统升级服务能力。</li><li>新增差分包升级能力。</li><li>新增系统属性管理JS API。</li></ul>
</td>
</tr>
<tr id="row13634133172314"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p136341733162314"><a name="p136341733162314"></a><a name="p136341733162314"></a>帐号</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p742721918165"><a name="p742721918165"></a><a name="p742721918165"></a>提供分布式云帐号登录状态管理功能。</p>
</td>
</tr>
<tr id="row101761542112310"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1417634216237"><a name="p1417634216237"></a><a name="p1417634216237"></a>编译构建</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul52391642195617"></a><a name="ul52391642195617"></a><ul id="ul52391642195617"><li>支持按照部件名或模块名编译指定目标。</li><li>支持不同芯片平台接入，配置产品部件列表。</li></ul>
</td>
</tr>
<tr id="row13162195114238"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p19162451172317"><a name="p19162451172317"></a><a name="p19162451172317"></a>测试</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p1279162291610"><a name="p1279162291610"></a><a name="p1279162291610"></a>新增开发者自测试能力，支持C++ API单元测试，API性能测试等。</p>
</td>
</tr>
<tr id="row104841456182316"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p2484115622319"><a name="p2484115622319"></a><a name="p2484115622319"></a>数据管理</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p11417133545113"><a name="p11417133545113"></a><a name="p11417133545113"></a>提供轻量级Key-Value操作，支持本地应用存储少量数据，数据存储在本地文件中，同时也加载在内存中的，所以访问速度更快，效率更高。</p>
</td>
</tr>
<tr id="row3363151082416"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1536351042411"><a name="p1536351042411"></a><a name="p1536351042411"></a>语言编译运行时</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p136651126161615"><a name="p136651126161615"></a><a name="p136651126161615"></a>提供了JS、C/C++语言程序的编译、执行环境，提供支撑运行时的基础库，以及关联的API接口、编译器和配套工具。</p>
</td>
</tr>
<tr id="row76812381241"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p15686388241"><a name="p15686388241"></a><a name="p15686388241"></a>分布式任务调度</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p725263113167"><a name="p725263113167"></a><a name="p725263113167"></a>提供系统服务的启动、注册、查询及管理能力。</p>
</td>
</tr>
<tr id="row776714945019"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p0767179135017"><a name="p0767179135017"></a><a name="p0767179135017"></a>JS UI框架</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul2726340105915"></a><a name="ul2726340105915"></a><ul id="ul2726340105915"><li>提供40+UI基础组件和容器组件。</li><li>提供标准CSS动画。</li><li>支持原子化布局、栅格布局。</li><li>提供类Web开发范式的UI编程框架。</li><li>JS API扩展机制。</li></ul>
</td>
</tr>
<tr id="row18427151814124"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p14427151814129"><a name="p14427151814129"></a><a name="p14427151814129"></a>媒体</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul258211290236"></a><a name="ul258211290236"></a><ul id="ul258211290236"><li>新增媒体播放和录制基本功能。</li><li>新增相机管理和相机采集基本功能。</li><li>新增音频音量和设备管理基本功能。</li></ul>
</td>
</tr>
<tr id="row188861132252"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p18866362511"><a name="p18866362511"></a><a name="p18866362511"></a>事件通知</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p15273861617"><a name="p15273861617"></a><a name="p15273861617"></a>新增发布、订阅、接收公共事件的基本功能。</p>
</td>
</tr>
<tr id="row15926131110258"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p17926161172514"><a name="p17926161172514"></a><a name="p17926161172514"></a>杂散软件服务</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p11712144071610"><a name="p11712144071610"></a><a name="p11712144071610"></a>新增设置时间的能力。</p>
</td>
</tr>
<tr id="row23492013257"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1935122022515"><a name="p1935122022515"></a><a name="p1935122022515"></a>用户程序框架</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p179997533484"><a name="p179997533484"></a><a name="p179997533484"></a>新增包安装、卸载、运行及管理能力。</p>
</td>
</tr>
<tr id="row4594164382519"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p15594164382518"><a name="p15594164382518"></a><a name="p15594164382518"></a>电话服务</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1781485014812"></a><a name="ul1781485014812"></a><ul id="ul1781485014812"><li>新增获得信号强度、获得驻网状态能力。</li><li>新增获得SIM卡状态能力。</li><li>新增拨打电话、拒接电话、挂断电话能力。</li><li>新增发送短信、接收短信能力。</li></ul>
</td>
</tr>
<tr id="row5772750122518"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p177245072517"><a name="p177245072517"></a><a name="p177245072517"></a>公共基础类库</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p183220493311"><a name="p183220493311"></a><a name="p183220493311"></a>提供了一些常用的C、C++开发增强API。</p>
</td>
</tr>
<tr id="row691575819259"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p6915175810253"><a name="p6915175810253"></a><a name="p6915175810253"></a>研发工具链</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1477582715386"></a><a name="ul1477582715386"></a><ul id="ul1477582715386"><li>新增设备连接调试器。</li><li>新增性能跟踪能力。</li><li>新增实时内存和trace调优工具，和端侧插件能力。</li></ul>
</td>
</tr>
<tr id="row32413714262"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p424237152616"><a name="p424237152616"></a><a name="p424237152616"></a>分布式软总线</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul03096914278"></a><a name="ul03096914278"></a><ul id="ul03096914278"><li>新增跨进程通信(IPC)和跨设备的远程过程调用(RPC)能力。</li><li>新增支持设备发现、组网、传输能力的软总线服务。</li><li>新增WiFi服务，可提供STA开关、扫描、连接等基本能力。</li></ul>
</td>
</tr>
<tr id="row0309184419277"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p18309844112717"><a name="p18309844112717"></a><a name="p18309844112717"></a>XTS</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p5545123182116"><a name="p5545123182116"></a><a name="p5545123182116"></a>新增各业务特性公共API兼容性看护用例套件。</p>
</td>
</tr>
<tr id="row161918529268"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p066763616286"><a name="p066763616286"></a><a name="p066763616286"></a>系统应用</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p1622081485920"><a name="p1622081485920"></a><a name="p1622081485920"></a>桌面:</p>
<a name="ul683613349018"></a><a name="ul683613349018"></a><ul id="ul683613349018"><li>新增全量应用图标展示、启动和卸载应用能力。</li><li>新增桌面管理界面，可切换网格布局与列表布局。</li><li>新增最近任务管理能力，可热启动和清理任务。</li></ul>
<p id="p2099221819011"><a name="p2099221819011"></a><a name="p2099221819011"></a>设置：</p>
<a name="ul18614124113017"></a><a name="ul18614124113017"></a><ul id="ul18614124113017"><li>新增设置应用，包括亮度设置，应用信息，时间设置和关于设备。</li></ul>
<p id="p0801430707"><a name="p0801430707"></a><a name="p0801430707"></a>SystemUI：</p>
<a name="ul320210441907"></a><a name="ul320210441907"></a><ul id="ul320210441907"><li>新增系统栏展示，包括时间、电量信息。</li><li>新增系统导航展示。</li></ul>
</td>
</tr>
<tr id="row11882513277"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p5881950273"><a name="p5881950273"></a><a name="p5881950273"></a>DFX</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul240818173613"></a><a name="ul240818173613"></a><ul id="ul240818173613"><li>新增流水日志。</li><li>新增应用故障收集和订阅。</li><li>新增系统事件记录接口。</li><li>新增应用事件记录接口及框架。</li></ul>
</td>
</tr>
<tr id="row377318915507"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p777349105012"><a name="p777349105012"></a><a name="p777349105012"></a>全球化子系统</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1815672517363"></a><a name="ul1815672517363"></a><ul id="ul1815672517363"><li>新增支持资源解析读取能力。</li><li>新增支持时间日期格式化能力。</li></ul>
</td>
</tr>
<tr id="row20979141410276"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p129791114102719"><a name="p129791114102719"></a><a name="p129791114102719"></a>安全</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1992964853616"></a><a name="ul1992964853616"></a><ul id="ul1992964853616"><li>新增系统权限管理，包括系统权限声明，应用安装时申请或申明的权限解析，权限查询，权限授予。</li><li>新增应用签名和验签能力。</li><li>新增点对点设备连接时的互信认证能力和设备群组管理能力。</li></ul>
</td>
</tr>
</tbody>
</table>

