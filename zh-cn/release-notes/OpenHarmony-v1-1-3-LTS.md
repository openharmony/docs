# OpenHarmony v1.1.3 LTS<a name="ZH-CN_TOPIC_0000001207124067"></a>

-   [版本概述](#section1846294912228)
-   [配套关系](#section395983762117)
-   [源码获取](#section84808293211)
    -   [通过镜像站点获取](#section8394142222113)

-   [更新说明](#section175225345334)
-   [已修复缺陷列表](#section11935243172612)

## 版本概述<a name="section1846294912228"></a>

更新发布LTS（long-term support）长期支持版本OpenHarmony v1.1.3 LTS，本版本在OpenHarmony v1.1.2 LTS版本的基础上新增了一些特性和修复了部分缺陷。

## 配套关系<a name="section395983762117"></a>

**表 1**  版本软件和工具配套关系

<a name="table17656123892412"></a>
<table><thead align="left"><tr id="row36572038122410"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p63988321828"><a name="p63988321828"></a><a name="p63988321828"></a>软件</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p7398133211216"><a name="p7398133211216"></a><a name="p7398133211216"></a>版本</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1239913216212"><a name="p1239913216212"></a><a name="p1239913216212"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row2065873818240"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p33994328215"><a name="p33994328215"></a><a name="p33994328215"></a>OpenHarmony</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p61561339133315"><a name="p61561339133315"></a><a name="p61561339133315"></a>1.1.3 LTS</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7316162554817"><a name="p7316162554817"></a><a name="p7316162554817"></a>NA</p>
</td>
</tr>
<tr id="row11660638162415"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17708321495"><a name="p17708321495"></a><a name="p17708321495"></a>HUAWEI DevEco Device Tool（可选）</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p145078181321"><a name="p145078181321"></a><a name="p145078181321"></a>HUAWEI DevEco Device Tool 2.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1139765711198"><a name="p1139765711198"></a><a name="p1139765711198"></a>OpenHarmony智能设备集成开发环境推荐使用。</p>
</td>
</tr>
</tbody>
</table>

## 源码获取<a name="section84808293211"></a>

通过repo下载

方式一（推荐）：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

方式二：通过repo + https 下载。

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 通过镜像站点获取<a name="section8394142222113"></a>

**表 2**  源码获取路径

<a name="table14394152217216"></a>
<table><thead align="left"><tr id="row15394132214217"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p15394122214219"><a name="p15394122214219"></a><a name="p15394122214219"></a>版本源码</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p10394112292119"><a name="p10394112292119"></a><a name="p10394112292119"></a>版本信息</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p039562213211"><a name="p039562213211"></a><a name="p039562213211"></a>下载站点</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1039572272110"><a name="p1039572272110"></a><a name="p1039572272110"></a>SHA256校验码</p>
</th>
</tr>
</thead>
<tbody><tr id="row9395722182111"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p039514225215"><a name="p039514225215"></a><a name="p039514225215"></a>全量代码</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p839514220217"><a name="p839514220217"></a><a name="p839514220217"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15931114016546"><a name="p15931114016546"></a><a name="p15931114016546"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/code-v1.1.3-LTS.tar.gz" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p3770144281415"><a name="p3770144281415"></a><a name="p3770144281415"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/code-v1.1.3-LTS.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256校验码</a></p>
</td>
</tr>
<tr id="row1739512225217"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1839592272117"><a name="p1839592272117"></a><a name="p1839592272117"></a>Hi3861解决方案（二进制）</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p7395722112113"><a name="p7395722112113"></a><a name="p7395722112113"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p29291940175415"><a name="p29291940175415"></a><a name="p29291940175415"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/wifiiot-1.1.3.tar.gz" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p134864584147"><a name="p134864584147"></a><a name="p134864584147"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/wifiiot-1.1.3.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256校验码</a></p>
</td>
</tr>
<tr id="row16395122262110"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p12395172242118"><a name="p12395172242118"></a><a name="p12395172242118"></a>Hi3518解决方案（二进制）</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p12395182210215"><a name="p12395182210215"></a><a name="p12395182210215"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p125681045181518"><a name="p125681045181518"></a><a name="p125681045181518"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3518ev300-1.1.3.tar.gz" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p4607175915149"><a name="p4607175915149"></a><a name="p4607175915149"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3518ev300-1.1.3.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256校验码</a></p>
</td>
</tr>
<tr id="row1839592272117"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p8395322182113"><a name="p8395322182113"></a><a name="p8395322182113"></a>Hi3516解决方案（二进制）</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p20395152262114"><a name="p20395152262114"></a><a name="p20395152262114"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p10455184661518"><a name="p10455184661518"></a><a name="p10455184661518"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3516dv300-1.1.3.tar.gz" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p84951102150"><a name="p84951102150"></a><a name="p84951102150"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3516dv300-1.1.3.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256校验码</a></p>
</td>
</tr>
<tr id="row3396822162120"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p18506191313914"><a name="p18506191313914"></a><a name="p18506191313914"></a>Release Notes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p10396102282110"><a name="p10396102282110"></a><a name="p10396102282110"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p88931840195416"><a name="p88931840195416"></a><a name="p88931840195416"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/OpenHarmony-Release-Notes-1.1.3-LTS.zip" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p039662242117"><a name="p039662242117"></a><a name="p039662242117"></a>-</p>
</td>
</tr>
</tbody>
</table>

## 更新说明<a name="section175225345334"></a>

本版本完全继承了OpenHarmony v1.1.2 LTS的所有特性，并在OpenHarmony v1.1.2 LTS版本的基础上，新增了轻量设备可以在windows环境下的编译版本的特性（请参考[windows开发环境准备](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-lite-env-setup-windows.md)）。

**表 3**  特性更新说明

<a name="table143385853320"></a>
<table><thead align="left"><tr id="row53375863312"><th class="cellrowborder" valign="top" width="16.650000000000002%" id="mcps1.2.5.1.1"><p id="p20331858193317"><a name="p20331858193317"></a><a name="p20331858193317"></a>子系统</p>
</th>
<th class="cellrowborder" valign="top" width="41.21%" id="mcps1.2.5.1.2"><p id="p1133115820331"><a name="p1133115820331"></a><a name="p1133115820331"></a>新增特性</p>
</th>
<th class="cellrowborder" valign="top" width="17.71%" id="mcps1.2.5.1.3"><p id="p162468531345"><a name="p162468531345"></a><a name="p162468531345"></a>修改特性</p>
</th>
<th class="cellrowborder" valign="top" width="24.43%" id="mcps1.2.5.1.4"><p id="p9985141863716"><a name="p9985141863716"></a><a name="p9985141863716"></a>删除特性</p>
</th>
</tr>
</thead>
<tbody><tr id="row333115812331"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.5.1.1 "><p id="p15480923174611"><a name="p15480923174611"></a><a name="p15480923174611"></a>芯片平台</p>
</td>
<td class="cellrowborder" valign="top" width="41.21%" headers="mcps1.2.5.1.2 "><p id="p474222917578"><a name="p474222917578"></a><a name="p474222917578"></a>支持了轻量设备在windows环境下编译版本（<a href="https://gitee.com/openharmony/device_hisilicon_hispark_pegasus/pulls/60" target="_blank" rel="noopener noreferrer">pulls/60</a>）</p>
</td>
<td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.2.5.1.3 "><p id="p94461923104618"><a name="p94461923104618"></a><a name="p94461923104618"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="24.43%" headers="mcps1.2.5.1.4 "><p id="p1460857115614"><a name="p1460857115614"></a><a name="p1460857115614"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## 已修复缺陷列表<a name="section11935243172612"></a>

在OpenHarmony v1.1.2 LTS版本的基础上，解决并修复的问题见下表。

**表 4**  已修复问题列表

<a name="table5308291018"></a>
<table><tbody><tr id="row73101295119"><td class="cellrowborder" valign="top" width="13.59%"><p id="p1845502010211"><a name="p1845502010211"></a><a name="p1845502010211"></a>ISSUE</p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p845516201624"><a name="p845516201624"></a><a name="p845516201624"></a>问题描述</p>
</td>
</tr>
<tr id="row78547572268"><td class="cellrowborder" valign="top" width="13.59%"><p id="p141901219281"><a name="p141901219281"></a><a name="p141901219281"></a><a href="https://gitee.com/openharmony/startup_syspara_lite/issues/I43MZK?from=project-issue" target="_blank" rel="noopener noreferrer">I43MZK</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p8660192092913"><a name="p8660192092913"></a><a name="p8660192092913"></a>release1.0.1分支命名中出现空格字符，与外部接口标准不符</p>
</td>
</tr>
<tr id="row680373152713"><td class="cellrowborder" valign="top" width="13.59%"><p id="p1519061122812"><a name="p1519061122812"></a><a name="p1519061122812"></a><a href="https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/issues/I44ZGK?from=project-issue" target="_blank" rel="noopener noreferrer">I44ZGK</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p466010208291"><a name="p466010208291"></a><a name="p466010208291"></a>组件ffmpeg 4.2.2存在未修复的漏洞</p>
</td>
</tr>
<tr id="row75041084274"><td class="cellrowborder" valign="top" width="13.59%"><p id="p101912112816"><a name="p101912112816"></a><a name="p101912112816"></a><a href="https://gitee.com/openharmony/graphic_utils/issues/I41ZMV?from=project-issue" target="_blank" rel="noopener noreferrer">I41ZMV</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p11661520172917"><a name="p11661520172917"></a><a name="p11661520172917"></a>HI3516刷机之后，在系统bin目录下存在module_ActsUiInterfaceTest1.bin测试文件</p>
</td>
</tr>
<tr id="row8505381278"><td class="cellrowborder" valign="top" width="13.59%"><p id="p219120113281"><a name="p219120113281"></a><a name="p219120113281"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3ZOIO?from=project-issue" target="_blank" rel="noopener noreferrer">I3ZOIO</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p13661720132914"><a name="p13661720132914"></a><a name="p13661720132914"></a>los_disk_deinit 资源释放失败</p>
</td>
</tr>
<tr id="row73421521112712"><td class="cellrowborder" valign="top" width="13.59%"><p id="p819116112288"><a name="p819116112288"></a><a name="p819116112288"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I43WLG?from=project-issue" target="_blank" rel="noopener noreferrer">I43WLG</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p10661920202920"><a name="p10661920202920"></a><a name="p10661920202920"></a>OsMountRootfs启动失败</p>
</td>
</tr>
<tr id="row334482119275"><td class="cellrowborder" valign="top" width="13.59%"><p id="p319271112813"><a name="p319271112813"></a><a name="p319271112813"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I48FKQ?from=project-issue" target="_blank" rel="noopener noreferrer">I48FKQ</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p2662122011293"><a name="p2662122011293"></a><a name="p2662122011293"></a>osEventFlagsGet传NULL时应该返回0</p>
</td>
</tr>
<tr id="row13445213279"><td class="cellrowborder" valign="top" width="13.59%"><p id="p519211112814"><a name="p519211112814"></a><a name="p519211112814"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I48FL1?from=project-issue" target="_blank" rel="noopener noreferrer">I48FL1</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p16662122072913"><a name="p16662122072913"></a><a name="p16662122072913"></a>osThreadNew函数attr为NULL时，创建线程失败</p>
</td>
</tr>
<tr id="row2870132842718"><td class="cellrowborder" valign="top" width="13.59%"><p id="p119213142815"><a name="p119213142815"></a><a name="p119213142815"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I48FLX?from=project-issue" target="_blank" rel="noopener noreferrer">I48FLX</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p1122204643118"><a name="p1122204643118"></a><a name="p1122204643118"></a>shell命令中使用rm -r指令尝试删除dev下节点时会导致系统出错</p>
</td>
</tr>
<tr id="row687215281272"><td class="cellrowborder" valign="top" width="13.59%"><p id="p1719211152813"><a name="p1719211152813"></a><a name="p1719211152813"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I48FMK?from=project-issue" target="_blank" rel="noopener noreferrer">I48FMK</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p20662112012294"><a name="p20662112012294"></a><a name="p20662112012294"></a>小型系统的ActsProcessApiTest/UidGidTest/testGetgroup测试用例失败</p>
</td>
</tr>
<tr id="row6873128172716"><td class="cellrowborder" valign="top" width="13.59%"><p id="p111921413286"><a name="p111921413286"></a><a name="p111921413286"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I48FMT?from=project-issue" target="_blank" rel="noopener noreferrer">I48FMT</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p1866222062911"><a name="p1866222062911"></a><a name="p1866222062911"></a>nanosleep函数实现存在缺陷</p>
</td>
</tr>
</tbody>
</table>

