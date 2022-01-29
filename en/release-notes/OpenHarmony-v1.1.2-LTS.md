# OpenHarmony v1.1.2 LTS<a name="EN-US_TOPIC_0000001131799132"></a>

-   [Overview](#section1846294912228)
-   [Version Mapping](#section395983762117)
-   [Source Code Acquisition](#section84808293211)
    -   [Acquiring Source Code from Mirrors](#section8394142222113)
    -   [Acquiring Source Code Using the repo Tool](#section7180193542317)

-   [What's New](#section175225345334)
-   [Resolved Issues](#section11935243172612)

## Overview<a name="section1846294912228"></a>

This is an updated long-term support \(LTS\) version of OpenHarmony. It supports more functions and fixes some bugs in OpenHarmony 1.1.1.

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
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p61561339133315"><a name="p61561339133315"></a><a name="p61561339133315"></a>1.1.2 LTS</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7316162554817"><a name="p7316162554817"></a><a name="p7316162554817"></a>N/A</p>
</td>
</tr>
<tr id="row11660638162415"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17708321495"><a name="p17708321495"></a><a name="p17708321495"></a>(Optional) HUAWEI DevEco Device Tool</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p145502371612"><a name="p145502371612"></a><a name="p145502371612"></a>Deveco DeviceTool 2.2 Beta1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1139765711198"><a name="p1139765711198"></a><a name="p1139765711198"></a>Recommended for developing OpenHarmony smart devices</p>
</td>
</tr>
</tbody>
</table>

## Source Code Acquisition<a name="section84808293211"></a>

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
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p839514220217"><a name="p839514220217"></a><a name="p839514220217"></a>1.1.2</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15931114016546"><a name="p15931114016546"></a><a name="p15931114016546"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/code-v1.1.2-LTS.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p3770144281415"><a name="p3770144281415"></a><a name="p3770144281415"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/code-v1.1.2-LTS.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row1739512225217"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1839592272117"><a name="p1839592272117"></a><a name="p1839592272117"></a>Hi3861 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p7395722112113"><a name="p7395722112113"></a><a name="p7395722112113"></a>1.1.2</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p29291940175415"><a name="p29291940175415"></a><a name="p29291940175415"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/wifiiot-1.1.2.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p134864584147"><a name="p134864584147"></a><a name="p134864584147"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/wifiiot-1.1.2.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row16395122262110"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p12395172242118"><a name="p12395172242118"></a><a name="p12395172242118"></a>Hi3518 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p12395182210215"><a name="p12395182210215"></a><a name="p12395182210215"></a>1.1.2</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p125681045181518"><a name="p125681045181518"></a><a name="p125681045181518"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3518ev300-1.1.2.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p4607175915149"><a name="p4607175915149"></a><a name="p4607175915149"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3518ev300-1.1.2.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row1839592272117"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p8395322182113"><a name="p8395322182113"></a><a name="p8395322182113"></a>Hi3516 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p20395152262114"><a name="p20395152262114"></a><a name="p20395152262114"></a>1.1.2</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p10455184661518"><a name="p10455184661518"></a><a name="p10455184661518"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3516dv300-1.1.2.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p84951102150"><a name="p84951102150"></a><a name="p84951102150"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3516dv300-1.1.2.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row3396822162120"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p18506191313914"><a name="p18506191313914"></a><a name="p18506191313914"></a>Release Notes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p10396102282110"><a name="p10396102282110"></a><a name="p10396102282110"></a>1.1.2</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p88931840195416"><a name="p88931840195416"></a><a name="p88931840195416"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.2/OpenHarmony-Release-Notes-1.1.2-LTS.zip" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p039662242117"><a name="p039662242117"></a><a name="p039662242117"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

### Acquiring Source Code Using the repo Tool<a name="section7180193542317"></a>

Method 1 \(recommended\): Use the  **repo**  tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the  **repo**  tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## What's New<a name="section175225345334"></a>

This version inherits all features of OpenHarmony 1.1.1, and adds and optimizes features for different modules based on OpenHarmony 1.1.1. The following table lists the feature updates.

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
<tbody><tr id="row333115812331"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.5.1.1 "><p id="p15480923174611"><a name="p15480923174611"></a><a name="p15480923174611"></a>Graphics</p>
</td>
<td class="cellrowborder" valign="top" width="41.21%" headers="mcps1.2.5.1.2 "><p id="p474222917578"><a name="p474222917578"></a><a name="p474222917578"></a>Added settings for the slider style.</p>
</td>
<td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.2.5.1.3 "><p id="p94461923104618"><a name="p94461923104618"></a><a name="p94461923104618"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="24.43%" headers="mcps1.2.5.1.4 "><p id="p1460857115614"><a name="p1460857115614"></a><a name="p1460857115614"></a>None</p>
</td>
</tr>
<tr id="row173335873311"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.5.1.1 "><p id="p7439172318467"><a name="p7439172318467"></a><a name="p7439172318467"></a>Update</p>
</td>
<td class="cellrowborder" valign="top" width="41.21%" headers="mcps1.2.5.1.2 "><p id="p129592820576"><a name="p129592820576"></a><a name="p129592820576"></a>Added the 3072-bit RSA signature algorithm for update packages.</p>
</td>
<td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.2.5.1.3 "><p id="p643022354612"><a name="p643022354612"></a><a name="p643022354612"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="24.43%" headers="mcps1.2.5.1.4 "><p id="p12427162324610"><a name="p12427162324610"></a><a name="p12427162324610"></a>None</p>
</td>
</tr>
<tr id="row15331058133314"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.5.1.1 "><p id="p1242515232463"><a name="p1242515232463"></a><a name="p1242515232463"></a>Driver</p>
</td>
<td class="cellrowborder" valign="top" width="41.21%" headers="mcps1.2.5.1.2 "><p id="p7561726135710"><a name="p7561726135710"></a><a name="p7561726135710"></a>Added certain internal OSAL APIs.</p>
</td>
<td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.2.5.1.3 "><p id="p2531623195714"><a name="p2531623195714"></a><a name="p2531623195714"></a>Optimized the sensor model.</p>
</td>
<td class="cellrowborder" valign="top" width="24.43%" headers="mcps1.2.5.1.4 "><p id="p218315461210"><a name="p218315461210"></a><a name="p218315461210"></a>None</p>
</td>
</tr>
<tr id="row1034145820330"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.5.1.1 "><p id="p75692287467"><a name="p75692287467"></a><a name="p75692287467"></a>Globalization</p>
</td>
<td class="cellrowborder" valign="top" width="41.21%" headers="mcps1.2.5.1.2 "><a name="ul1590163816572"></a><a name="ul1590163816572"></a><ul id="ul1590163816572"><li>Added data functions such as the digital switch and weekday.</li></ul>
<a name="ul9521944105716"></a><a name="ul9521944105716"></a><ul id="ul9521944105716"><li>Added the <strong id="b0745145255415"><a name="b0745145255415"></a><a name="b0745145255415"></a>Get12HourTimeWithoutAmpm</strong> API.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.2.5.1.3 "><p id="p332116531219"><a name="p332116531219"></a><a name="p332116531219"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="24.43%" headers="mcps1.2.5.1.4 "><p id="p1355966141215"><a name="p1355966141215"></a><a name="p1355966141215"></a>None</p>
</td>
</tr>
</tbody>
</table>

## Resolved Issues<a name="section11935243172612"></a>

The following table lists the issues known in OpenHarmony 1.1.1 that have been resolved in this version.

**Table  4**  Resolved issues

<a name="table5308291018"></a>
<table><thead align="left"><tr id="row73101295119"><th class="cellrowborder" valign="top" width="10.95%" id="mcps1.2.4.1.1"><p id="p174377490554"><a name="p174377490554"></a><a name="p174377490554"></a>Subsystem</p>
</th>
<th class="cellrowborder" valign="top" width="23.74%" id="mcps1.2.4.1.2"><p id="p1845502010211"><a name="p1845502010211"></a><a name="p1845502010211"></a>PR NO.</p>
</th>
<th class="cellrowborder" valign="top" width="65.31%" id="mcps1.2.4.1.3"><p id="p845516201624"><a name="p845516201624"></a><a name="p845516201624"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1931118918112"><td class="cellrowborder" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p1343813499552"><a name="p1343813499552"></a><a name="p1343813499552"></a>Application Framework</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p4370163591620"><a name="p4370163591620"></a><a name="p4370163591620"></a><a href="https://gitee.com/openharmony/aafwk_aafwk_lite/pulls/35" target="_blank" rel="noopener noreferrer">aafwk_aafwk_lite/pulls/35</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p1033846256"><a name="p1033846256"></a><a name="p1033846256"></a>There is a low probability that the Linux system cannot be shut down.</p>
</td>
</tr>
<tr id="row431169617"><td class="cellrowborder" rowspan="2" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p1983174111912"><a name="p1983174111912"></a><a name="p1983174111912"></a></p>
<p id="p740195117415"><a name="p740195117415"></a><a name="p740195117415"></a>AI</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p1338196554"><a name="p1338196554"></a><a name="p1338196554"></a><a href="https://gitee.com/openharmony/ai_engine/pulls/50" target="_blank" rel="noopener noreferrer">ai_engine/pulls/50</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p43391361256"><a name="p43391361256"></a><a name="p43391361256"></a>The test case for the client is not released.</p>
</td>
</tr>
<tr id="row1131210911110"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7339961255"><a name="p7339961255"></a><a name="p7339961255"></a><a href="https://gitee.com/openharmony/ai_engine/pulls/46" target="_blank" rel="noopener noreferrer">ai_engine/pulls/46</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p8339156259"><a name="p8339156259"></a><a name="p8339156259"></a>Class members are not initialized.</p>
</td>
</tr>
<tr id="row1631289517"><td class="cellrowborder" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p2438124912555"><a name="p2438124912555"></a><a name="p2438124912555"></a>IoT Hardware</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p1135391101919"><a name="p1135391101919"></a><a name="p1135391101919"></a><a href="https://gitee.com/openharmony/applications_sample_wifi_iot/pulls/12" target="_blank" rel="noopener noreferrer">applications_sample_wifi_iot/pulls/12</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p10340186457"><a name="p10340186457"></a><a name="p10340186457"></a>A build fails.</p>
</td>
</tr>
<tr id="row914520251031"><td class="cellrowborder" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p3439114916554"><a name="p3439114916554"></a><a name="p3439114916554"></a>Compilation and Building</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p734006452"><a name="p734006452"></a><a name="p734006452"></a><a href="https://gitee.com/openharmony/build_lite/pulls/151" target="_blank" rel="noopener noreferrer">build_lite/pulls/151</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p53401863516"><a name="p53401863516"></a><a name="p53401863516"></a>The test case is not available in the build process.</p>
</td>
</tr>
<tr id="row6950141911318"><td class="cellrowborder" rowspan="3" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p35148434112"><a name="p35148434112"></a><a name="p35148434112"></a></p>
<p id="p5688226135"><a name="p5688226135"></a><a name="p5688226135"></a></p>
<p id="p1747415559616"><a name="p1747415559616"></a><a name="p1747415559616"></a>Chip Platform</p>
<p id="p1887210172118"><a name="p1887210172118"></a><a name="p1887210172118"></a></p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p43401361057"><a name="p43401361057"></a><a name="p43401361057"></a><a href="https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/pulls/9" target="_blank" rel="noopener noreferrer">third_party_ffmpeg/pulls/9</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p43401261757"><a name="p43401261757"></a><a name="p43401261757"></a>The CVE-2020-22025 vulnerability is detected.</p>
</td>
</tr>
<tr id="row11412117731"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p73401461056"><a name="p73401461056"></a><a name="p73401461056"></a><a href="https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/pulls/6" target="_blank" rel="noopener noreferrer">third_party_ffmpeg/pulls/6</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15341461657"><a name="p15341461657"></a><a name="p15341461657"></a>A build fails due to the dependency on valgrind in some environments.</p>
</td>
</tr>
<tr id="row14871121710115"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p860172714115"><a name="p860172714115"></a><a name="p860172714115"></a><a href="https://gitee.com/openharmony/vendor_hisilicon/pulls/39" target="_blank" rel="noopener noreferrer">vendor_hisilicon/pulls/39</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p13602270118"><a name="p13602270118"></a><a name="p13602270118"></a>Building the release fails.</p>
</td>
</tr>
<tr id="row17992137318"><td class="cellrowborder" rowspan="2" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p1865613818918"><a name="p1865613818918"></a><a name="p1865613818918"></a></p>
<p id="p1015214181970"><a name="p1015214181970"></a><a name="p1015214181970"></a>Distributed Scheduler</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p1634176153"><a name="p1634176153"></a><a name="p1634176153"></a><a href="https://gitee.com/openharmony/distributedschedule_dms_fwk_lite/pulls/23" target="_blank" rel="noopener noreferrer">distributedschedule_dms_fwk_lite/pulls/23</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p0341186251"><a name="p0341186251"></a><a name="p0341186251"></a>The test case name is inappropriate.</p>
</td>
</tr>
<tr id="row9303111136"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p10341862052"><a name="p10341862052"></a><a name="p10341862052"></a><a href="https://gitee.com/openharmony/distributedschedule_samgr_lite/pulls/25" target="_blank" rel="noopener noreferrer">distributedschedule_samgr_lite/pulls/25</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p153421063520"><a name="p153421063520"></a><a name="p153421063520"></a>The CVE-2021-22478 vulnerability is detected.</p>
</td>
</tr>
<tr id="row86521981233"><td class="cellrowborder" rowspan="2" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p166461134290"><a name="p166461134290"></a><a name="p166461134290"></a></p>
<p id="p10439154945514"><a name="p10439154945514"></a><a name="p10439154945514"></a>Globalization</p>
<p id="p154115410817"><a name="p154115410817"></a><a name="p154115410817"></a></p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p53426610512"><a name="p53426610512"></a><a name="p53426610512"></a><a href="https://gitee.com/openharmony/global_i18n_lite/pulls/24" target="_blank" rel="noopener noreferrer">global_i18n_lite/pulls/24</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p193421661056"><a name="p193421661056"></a><a name="p193421661056"></a>Resource loading of <strong id="b22607367315"><a name="b22607367315"></a><a name="b22607367315"></a>i18n.dat</strong> is defective.</p>
</td>
</tr>
<tr id="row15365419810"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p193591990914"><a name="p193591990914"></a><a name="p193591990914"></a><a href="https://gitee.com/openharmony/third_party_jerryscript/pulls/22" target="_blank" rel="noopener noreferrer">third_party_jerryscript/pulls/22</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p855154481"><a name="p855154481"></a><a name="p855154481"></a>There is a possibility that the breakpoint cannot be stopped during debugging of the macOS version.</p>
</td>
</tr>
<tr id="row11445061638"><td class="cellrowborder" rowspan="2" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p1566811358714"><a name="p1566811358714"></a><a name="p1566811358714"></a>Graphics</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p123431367513"><a name="p123431367513"></a><a name="p123431367513"></a><a href="https://gitee.com/openharmony/graphic_ui/pulls/220" target="_blank" rel="noopener noreferrer">graphic_ui/pulls/220</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p143431862513"><a name="p143431862513"></a><a name="p143431862513"></a>The Remove function is provided, but the Add function is not. After the modification, the child nodes are not cleared when the <strong id="b15412153013526"><a name="b15412153013526"></a><a name="b15412153013526"></a>UIViewGroup</strong> is destructed.</p>
</td>
</tr>
<tr id="row7221525314"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19343062056"><a name="p19343062056"></a><a name="p19343062056"></a><a href="https://gitee.com/openharmony/graphic_ui/pulls/199" target="_blank" rel="noopener noreferrer">graphic_ui/pulls/199</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p634416757"><a name="p634416757"></a><a name="p634416757"></a>The image is not updated after the image path is updated.</p>
</td>
</tr>
<tr id="row1781613591222"><td class="cellrowborder" rowspan="3" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p171166114117"><a name="p171166114117"></a><a name="p171166114117"></a></p>
<p id="p173221646678"><a name="p173221646678"></a><a name="p173221646678"></a>Lite Kernel</p>
<p id="p155544359109"><a name="p155544359109"></a><a name="p155544359109"></a></p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p2344262056"><a name="p2344262056"></a><a name="p2344262056"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/pulls/385" target="_blank" rel="noopener noreferrer">kernel_liteos_a/pulls/385</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p1134586957"><a name="p1134586957"></a><a name="p1134586957"></a>The CVE-2021-22479 vulnerability is detected.</p>
</td>
</tr>
<tr id="row69181756923"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p73450618511"><a name="p73450618511"></a><a name="p73450618511"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/pulls/299" target="_blank" rel="noopener noreferrer">kernel_liteos_a/pulls/299</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p103451361258"><a name="p103451361258"></a><a name="p103451361258"></a>There are unnecessary maintenance and test logs of the PRINTK function.</p>
</td>
</tr>
<tr id="row555363512104"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1779044015109"><a name="p1779044015109"></a><a name="p1779044015109"></a><a href="https://gitee.com/openharmony/third_party_musl/pulls/44" target="_blank" rel="noopener noreferrer">third_party_musl/pulls/44</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1979174013109"><a name="p1979174013109"></a><a name="p1979174013109"></a>The implementation of the srand function for setting random number seeds is inappropriate.</p>
</td>
</tr>
<tr id="row20161052824"><td class="cellrowborder" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p5440124912557"><a name="p5440124912557"></a><a name="p5440124912557"></a>Startup</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p3346126155"><a name="p3346126155"></a><a name="p3346126155"></a><a href="https://gitee.com/openharmony/startup_syspara_lite/pulls/31" target="_blank" rel="noopener noreferrer">startup_syspara_lite/pulls/31</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p3346126458"><a name="p3346126458"></a><a name="p3346126458"></a>The date of the security patch is incorrect.</p>
</td>
</tr>
<tr id="row524818551734"><td class="cellrowborder" rowspan="2" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p54616528128"><a name="p54616528128"></a><a name="p54616528128"></a></p>
<p id="p169514472123"><a name="p169514472123"></a><a name="p169514472123"></a>Driver</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p634966451"><a name="p634966451"></a><a name="p634966451"></a><a href="https://gitee.com/openharmony/drivers_adapter_khdf_linux/pulls/28" target="_blank" rel="noopener noreferrer">drivers_adapter_khdf_linux/pulls/28</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p18350146554"><a name="p18350146554"></a><a name="p18350146554"></a>The CVE-2021-22441 vulnerability is detected.</p>
</td>
</tr>
<tr id="row165387521936"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p183501362519"><a name="p183501362519"></a><a name="p183501362519"></a><a href="https://gitee.com/openharmony/drivers_adapter/pulls/50" target="_blank" rel="noopener noreferrer">drivers_adapter/pulls/50</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p183501761654"><a name="p183501761654"></a><a name="p183501761654"></a>The CVE-2021-22480 vulnerability is detected.</p>
</td>
</tr>
<tr id="row762018491032"><td class="cellrowborder" rowspan="5" valign="top" width="10.95%" headers="mcps1.2.4.1.1 "><p id="p327110851312"><a name="p327110851312"></a><a name="p327110851312"></a></p>
<p id="p187591488132"><a name="p187591488132"></a><a name="p187591488132"></a></p>
<p id="p1734816901310"><a name="p1734816901310"></a><a name="p1734816901310"></a></p>
<p id="p275011231315"><a name="p275011231315"></a><a name="p275011231315"></a>Testing</p>
</td>
<td class="cellrowborder" valign="top" width="23.74%" headers="mcps1.2.4.1.2 "><p id="p20827142419323"><a name="p20827142419323"></a><a name="p20827142419323"></a><a href="https://gitee.com/openharmony/xts_acts/pulls/294" target="_blank" rel="noopener noreferrer">xts_acts/pulls/294</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.31%" headers="mcps1.2.4.1.3 "><p id="p1035111611516"><a name="p1035111611516"></a><a name="p1035111611516"></a>Certain test cases of the fs_posix module are unstable.</p>
</td>
</tr>
<tr id="row957119491343"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p163341234193213"><a name="p163341234193213"></a><a name="p163341234193213"></a><a href="https://gitee.com/openharmony/xts_acts/pulls/287" target="_blank" rel="noopener noreferrer">xts_acts/pulls/287</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p173511661150"><a name="p173511661150"></a><a name="p173511661150"></a>The acts test fails.</p>
</td>
</tr>
<tr id="row14264154720415"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14352462518"><a name="p14352462518"></a><a name="p14352462518"></a><a href="https://gitee.com/openharmony/xts_acts/pulls/283" target="_blank" rel="noopener noreferrer">xts_acts/pulls/283</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p193522060518"><a name="p193522060518"></a><a name="p193522060518"></a>Certain CMSIS test cases fail occasionally.</p>
</td>
</tr>
<tr id="row17732544845"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1535212610517"><a name="p1535212610517"></a><a name="p1535212610517"></a><a href="https://gitee.com/openharmony/xts_acts/pulls/270" target="_blank" rel="noopener noreferrer">xts_acts/pulls/270</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19352661858"><a name="p19352661858"></a><a name="p19352661858"></a>The ShmTest.testShmatSHM_REMAP function in the ShmTest.cpp test case of the shared_memory module does not run as expected.</p>
</td>
</tr>
<tr id="row8376421348"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p735211613511"><a name="p735211613511"></a><a name="p735211613511"></a><a href="https://gitee.com/openharmony/xts_acts/pulls/314" target="_blank" rel="noopener noreferrer">xts_acts/pulls/314</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p7353162513"><a name="p7353162513"></a><a name="p7353162513"></a>The test of the net_posix module fails.</p>
</td>
</tr>
</tbody>
</table>

