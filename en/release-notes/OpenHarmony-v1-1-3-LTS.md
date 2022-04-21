# OpenHarmony v1.1.3 LTS<a name="EN-US_TOPIC_0000001207124067"></a>

## Overview<a name="section1846294912228"></a>

This is an updated long-term support \(LTS\) version of OpenHarmony. It supports more functions than and fixes some bugs in OpenHarmony 1.1.2.

## Version Mapping<a name="section395983762117"></a>

**Table  1**  Version mapping of software and tools

<a name="table17656123892412"></a>
<table><thead align="left"><tr id="row36572038122410"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p63988321828"><a name="p63988321828"></a><a name="p63988321828"></a>Software</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p7398133211216"><a name="p7398133211216"></a><a name="p7398133211216"></a>Version</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1239913216212"><a name="p1239913216212"></a><a name="p1239913216212"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row2065873818240"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p33994328215"><a name="p33994328215"></a><a name="p33994328215"></a>OpenHarmony</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p61561339133315"><a name="p61561339133315"></a><a name="p61561339133315"></a>1.1.3 LTS</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7316162554817"><a name="p7316162554817"></a><a name="p7316162554817"></a>N/A</p>
</td>
</tr>
<tr id="row11660638162415"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17708321495"><a name="p17708321495"></a><a name="p17708321495"></a>(Optional) HUAWEI DevEco Device Tool</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p145078181321"><a name="p145078181321"></a><a name="p145078181321"></a>HUAWEI DevEco Device Tool 2.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1139765711198"><a name="p1139765711198"></a><a name="p1139765711198"></a>Recommended for developing OpenHarmony smart devices</p>
</td>
</tr>
</tbody>
</table>

## Source Code Acquisition<a name="section84808293211"></a>

### Acquiring Source Code Using the repo Tool<a name="section8394142222114"></a>

Method 1 \(recommended\): Use the  **repo**  tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the  **repo**  tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### Acquiring Source Code from Mirrors<a name="section8394142222113"></a>

**Table  2**  Mirrors for acquiring source code

<a name="table14394152217216"></a>
<table><thead align="left"><tr id="row15394132214217"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p15394122214219"><a name="p15394122214219"></a><a name="p15394122214219"></a>Source Code</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p10394112292119"><a name="p10394112292119"></a><a name="p10394112292119"></a>Version Information</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p039562213211"><a name="p039562213211"></a><a name="p039562213211"></a>Mirror</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1039572272110"><a name="p1039572272110"></a><a name="p1039572272110"></a>SHA-256 Checksum</p>
</th>
</tr>
</thead>
<tbody><tr id="row9395722182111"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p039514225215"><a name="p039514225215"></a><a name="p039514225215"></a>Full code base</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p839514220217"><a name="p839514220217"></a><a name="p839514220217"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15931114016546"><a name="p15931114016546"></a><a name="p15931114016546"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/code-v1.1.3-LTS.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p3770144281415"><a name="p3770144281415"></a><a name="p3770144281415"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/code-v1.1.3-LTS.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row1739512225217"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1839592272117"><a name="p1839592272117"></a><a name="p1839592272117"></a>Hi3861 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p7395722112113"><a name="p7395722112113"></a><a name="p7395722112113"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p29291940175415"><a name="p29291940175415"></a><a name="p29291940175415"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/wifiiot-1.1.3.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p134864584147"><a name="p134864584147"></a><a name="p134864584147"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/wifiiot-1.1.3.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row16395122262110"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p12395172242118"><a name="p12395172242118"></a><a name="p12395172242118"></a>Hi3518 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p12395182210215"><a name="p12395182210215"></a><a name="p12395182210215"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p125681045181518"><a name="p125681045181518"></a><a name="p125681045181518"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3518ev300-1.1.3.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p4607175915149"><a name="p4607175915149"></a><a name="p4607175915149"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3518ev300-1.1.3.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row1839592272117"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p8395322182113"><a name="p8395322182113"></a><a name="p8395322182113"></a>Hi3516 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p20395152262114"><a name="p20395152262114"></a><a name="p20395152262114"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p10455184661518"><a name="p10455184661518"></a><a name="p10455184661518"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3516dv300-1.1.3.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p84951102150"><a name="p84951102150"></a><a name="p84951102150"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3516dv300-1.1.3.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row3396822162120"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p18506191313914"><a name="p18506191313914"></a><a name="p18506191313914"></a>Release Notes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p10396102282110"><a name="p10396102282110"></a><a name="p10396102282110"></a>1.1.3</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p88931840195416"><a name="p88931840195416"></a><a name="p88931840195416"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.3/OpenHarmony-Release-Notes-1.1.3-LTS.zip" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p039662242117"><a name="p039662242117"></a><a name="p039662242117"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## What's New<a name="section175225345334"></a>

This version inherits all the features of OpenHarmony v1.1.2 and adds the support for version compilation for mini-system devices in the Windows environment. For details, see  [Setting Up the Windows Build Environment](https://device.harmonyos.com/en/docs/documentation/guide/ide-install-windows-0000001050164976).

**Table  3**  Feature updates

<a name="table143385853320"></a>
<table><thead align="left"><tr id="row53375863312"><th class="cellrowborder" valign="top" width="16.650000000000002%" id="mcps1.2.5.1.1"><p id="p20331858193317"><a name="p20331858193317"></a><a name="p20331858193317"></a>Subsystem</p>
</th>
<th class="cellrowborder" valign="top" width="41.21%" id="mcps1.2.5.1.2"><p id="p1133115820331"><a name="p1133115820331"></a><a name="p1133115820331"></a>New Feature</p>
</th>
<th class="cellrowborder" valign="top" width="17.71%" id="mcps1.2.5.1.3"><p id="p162468531345"><a name="p162468531345"></a><a name="p162468531345"></a>Modified Feature</p>
</th>
<th class="cellrowborder" valign="top" width="24.43%" id="mcps1.2.5.1.4"><p id="p9985141863716"><a name="p9985141863716"></a><a name="p9985141863716"></a>Deleted Feature</p>
</th>
</tr>
</thead>
<tbody><tr id="row333115812331"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.5.1.1 "><p id="p15480923174611"><a name="p15480923174611"></a><a name="p15480923174611"></a>Chip platform</p>
</td>
<td class="cellrowborder" valign="top" width="41.21%" headers="mcps1.2.5.1.2 "><p id="p474222917578"><a name="p474222917578"></a><a name="p474222917578"></a>Supports version compilation for mini-system devices in the Windows environment (<a href="https://gitee.com/openharmony/device_hisilicon_hispark_pegasus/pulls/60" target="_blank" rel="noopener noreferrer">pulls/60</a>).</p>
</td>
<td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.2.5.1.3 "><p id="p94461923104618"><a name="p94461923104618"></a><a name="p94461923104618"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="24.43%" headers="mcps1.2.5.1.4 "><p id="p1460857115614"><a name="p1460857115614"></a><a name="p1460857115614"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Resolved Issues<a name="section11935243172612"></a>

The following table lists the known issues with OpenHarmony 1.1.2 that have been resolved in this version.

**Table  4**  Resolved issues

<a name="table5308291018"></a>
<table><tbody><tr id="row73101295119"><td class="cellrowborder" valign="top" width="13.59%"><p id="p1845502010211"><a name="p1845502010211"></a><a name="p1845502010211"></a><strong id="b3449164525717"><a name="b3449164525717"></a><a name="b3449164525717"></a>Issue</strong></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p845516201624"><a name="p845516201624"></a><a name="p845516201624"></a><strong id="b86724463576"><a name="b86724463576"></a><a name="b86724463576"></a>Description</strong></p>
</td>
</tr>
<tr id="row78547572268"><td class="cellrowborder" valign="top" width="13.59%"><p id="p141901219281"><a name="p141901219281"></a><a name="p141901219281"></a><a href="https://gitee.com/openharmony/startup_syspara_lite/issues/I43MZK?from=project-issue" target="_blank" rel="noopener noreferrer">I43MZK</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p8660192092913"><a name="p8660192092913"></a><a name="p8660192092913"></a>The release 1.0.1 branch name contains spaces, which does not comply with the external interface standard.</p>
</td>
</tr>
<tr id="row680373152713"><td class="cellrowborder" valign="top" width="13.59%"><p id="p1519061122812"><a name="p1519061122812"></a><a name="p1519061122812"></a><a href="https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/issues/I44ZGK?from=project-issue" target="_blank" rel="noopener noreferrer">I44ZGK</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p466010208291"><a name="p466010208291"></a><a name="p466010208291"></a>The FFmpeg 4.2.2 component has an unfixed vulnerability.</p>
</td>
</tr>
<tr id="row75041084274"><td class="cellrowborder" valign="top" width="13.59%"><p id="p101912112816"><a name="p101912112816"></a><a name="p101912112816"></a><a href="https://gitee.com/openharmony/graphic_utils/issues/I41ZMV?from=project-issue" target="_blank" rel="noopener noreferrer">I41ZMV</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p11661520172917"><a name="p11661520172917"></a><a name="p11661520172917"></a>After ROM flashing on the Hi3516 chip, the <strong id="b265419439384"><a name="b265419439384"></a><a name="b265419439384"></a>module_ActsUiInterfaceTest1.bin</strong> test file exists in the <strong id="b677465173814"><a name="b677465173814"></a><a name="b677465173814"></a>bin</strong> directory.</p>
</td>
</tr>
<tr id="row8505381278"><td class="cellrowborder" valign="top" width="13.59%"><p id="p219120113281"><a name="p219120113281"></a><a name="p219120113281"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3ZOIO?from=project-issue" target="_blank" rel="noopener noreferrer">I3ZOIO</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p13661720132914"><a name="p13661720132914"></a><a name="p13661720132914"></a>Releasing the <strong id="b840314566256"><a name="b840314566256"></a><a name="b840314566256"></a>los_disk_deinit</strong> resource fails.</p>
</td>
</tr>
<tr id="row73421521112712"><td class="cellrowborder" valign="top" width="13.59%"><p id="p819116112288"><a name="p819116112288"></a><a name="p819116112288"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I43WLG?from=project-issue" target="_blank" rel="noopener noreferrer">I43WLG</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p10661920202920"><a name="p10661920202920"></a><a name="p10661920202920"></a>Starting OsMountRootfs fails.</p>
</td>
</tr>
<tr id="row334482119275"><td class="cellrowborder" valign="top" width="13.59%"><p id="p319271112813"><a name="p319271112813"></a><a name="p319271112813"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I48FKQ?from=project-issue" target="_blank" rel="noopener noreferrer">I48FKQ</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p2662122011293"><a name="p2662122011293"></a><a name="p2662122011293"></a>A value other than <strong id="b07721660368"><a name="b07721660368"></a><a name="b07721660368"></a>0</strong> is returned when <strong id="b92981718174816"><a name="b92981718174816"></a><a name="b92981718174816"></a>osEventFlagsGet</strong> is set to <strong id="b159112218486"><a name="b159112218486"></a><a name="b159112218486"></a>NULL</strong>.</p>
</td>
</tr>
<tr id="row13445213279"><td class="cellrowborder" valign="top" width="13.59%"><p id="p519211112814"><a name="p519211112814"></a><a name="p519211112814"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I48FL1?from=project-issue" target="_blank" rel="noopener noreferrer">I48FL1</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p16662122072913"><a name="p16662122072913"></a><a name="p16662122072913"></a>Thread creation fails when <strong id="b144161133114813"><a name="b144161133114813"></a><a name="b144161133114813"></a>attr</strong> of the <strong id="b555203710487"><a name="b555203710487"></a><a name="b555203710487"></a>osThreadNew</strong> function is set to <strong id="b721004154817"><a name="b721004154817"></a><a name="b721004154817"></a>NULL</strong>.</p>
</td>
</tr>
<tr id="row2870132842718"><td class="cellrowborder" valign="top" width="13.59%"><p id="p119213142815"><a name="p119213142815"></a><a name="p119213142815"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I48FLX?from=project-issue" target="_blank" rel="noopener noreferrer">I48FLX</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p1122204643118"><a name="p1122204643118"></a><a name="p1122204643118"></a>A system error occurs when the <strong id="b109034916347"><a name="b109034916347"></a><a name="b109034916347"></a>shell</strong> command <strong id="b3156202413337"><a name="b3156202413337"></a><a name="b3156202413337"></a>rm -r</strong> is run to delete a node under <strong id="b20501131173514"><a name="b20501131173514"></a><a name="b20501131173514"></a>dev</strong>.</p>
</td>
</tr>
<tr id="row687215281272"><td class="cellrowborder" valign="top" width="13.59%"><p id="p1719211152813"><a name="p1719211152813"></a><a name="p1719211152813"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I48FMK?from=project-issue" target="_blank" rel="noopener noreferrer">I48FMK</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p20662112012294"><a name="p20662112012294"></a><a name="p20662112012294"></a>The <strong id="b189528524917"><a name="b189528524917"></a><a name="b189528524917"></a>ActsProcessApiTest/UidGidTest/testGetgroup</strong> test case of small-system devices fails.</p>
</td>
</tr>
<tr id="row6873128172716"><td class="cellrowborder" valign="top" width="13.59%"><p id="p111921413286"><a name="p111921413286"></a><a name="p111921413286"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I48FMT?from=project-issue" target="_blank" rel="noopener noreferrer">I48FMT</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.41%"><p id="p1866222062911"><a name="p1866222062911"></a><a name="p1866222062911"></a>The implementation of the <strong id="b4252142319318"><a name="b4252142319318"></a><a name="b4252142319318"></a>nanosleep</strong> function has a defect.</p>
</td>
</tr>
</tbody>
</table>

