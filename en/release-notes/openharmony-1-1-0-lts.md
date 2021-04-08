# OpenHarmony 1.1.0 LTS \(2021-04-01\)<a name="EN-US_TOPIC_0000001095652840"></a>

-   [Overview](#section1846294912228)
-   [Source Code Acquisition](#section84808293211)
    -   [Acquiring Source Code from Image Sites](#section19634542131218)
    -   [Acquiring Source Code Using the repo Tool](#section7180193542317)

-   [Rectified Issues](#section11935243172612)

## Overview<a name="section1846294912228"></a>

This is the first LTS version of OpenHarmony. This version fixes some bugs in OpenHarmony 1.0.1.

## Source Code Acquisition<a name="section84808293211"></a>

### Acquiring Source Code from Image Sites<a name="section19634542131218"></a>

**Table  1**  Sites for acquiring source code

<a name="table37071442171217"></a>
<table><thead align="left"><tr id="row20705154220120"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p67051342151216"><a name="p67051342151216"></a><a name="p67051342151216"></a>Source Code</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p470519425129"><a name="p470519425129"></a><a name="p470519425129"></a>Version Information</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p8705194271212"><a name="p8705194271212"></a><a name="p8705194271212"></a>Site</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1270594241219"><a name="p1270594241219"></a><a name="p1270594241219"></a>SHA-256 Verification Code</p>
</th>
</tr>
</thead>
<tbody><tr id="row470516428125"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1870564214123"><a name="p1870564214123"></a><a name="p1870564214123"></a>Full code base</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p270504214125"><a name="p270504214125"></a><a name="p270504214125"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1170554201212"><a name="p1170554201212"></a><a name="p1170554201212"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p97051842101210"><a name="p97051842101210"></a><a name="p97051842101210"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA-256 verification code</a></p>
</td>
</tr>
<tr id="row11706164211210"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p77051425121"><a name="p77051425121"></a><a name="p77051425121"></a>Hi3861 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p16705154215126"><a name="p16705154215126"></a><a name="p16705154215126"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p19705194241214"><a name="p19705194241214"></a><a name="p19705194241214"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1570554271214"><a name="p1570554271214"></a><a name="p1570554271214"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA-256 verification code</a></p>
</td>
</tr>
<tr id="row5706142101219"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p10706542191212"><a name="p10706542191212"></a><a name="p10706542191212"></a>Hi3518 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p10706842121215"><a name="p10706842121215"></a><a name="p10706842121215"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p670610421126"><a name="p670610421126"></a><a name="p670610421126"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p47060422121"><a name="p47060422121"></a><a name="p47060422121"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA-256 verification code</a></p>
</td>
</tr>
<tr id="row167061942121218"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p17706442161215"><a name="p17706442161215"></a><a name="p17706442161215"></a>Hi3516 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p170674212126"><a name="p170674212126"></a><a name="p170674212126"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p47061428127"><a name="p47061428127"></a><a name="p47061428127"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p107061642151219"><a name="p107061642151219"></a><a name="p107061642151219"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA-256 verification code</a></p>
</td>
</tr>
<tr id="row7706342101215"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1070654251210"><a name="p1070654251210"></a><a name="p1070654251210"></a>RELEASE-NOTES</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p47061142101217"><a name="p47061142101217"></a><a name="p47061142101217"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p97068428123"><a name="p97068428123"></a><a name="p97068428123"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/OpenHarmony_Release_Notes_zh_cn.zip" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p9706642151212"><a name="p9706642151212"></a><a name="p9706642151212"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

### Acquiring Source Code Using the repo Tool<a name="section7180193542317"></a>

Run the following commands to download the source code:

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony_release_v1.1.0 --no-repo-verify
repo sync -c
```

## Rectified Issues<a name="section11935243172612"></a>

The following table lists the issues that have been resolved in this version.

**Table  2**  Resolved issues

<a name="table1934113413913"></a>
<table><thead align="left"><tr id="row4341334203914"><th class="cellrowborder" valign="top" width="22.650000000000002%" id="mcps1.2.3.1.1"><p id="p711564410397"><a name="p711564410397"></a><a name="p711564410397"></a>Issue</p>
</th>
<th class="cellrowborder" valign="top" width="77.35%" id="mcps1.2.3.1.2"><p id="p411564416397"><a name="p411564416397"></a><a name="p411564416397"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row934223410393"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p133271454113911"><a name="p133271454113911"></a><a name="p133271454113911"></a><a href="https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU" target="_blank" rel="noopener noreferrer">I3EALU</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p1132775483917"><a name="p1132775483917"></a><a name="p1132775483917"></a>[Multimedia] When the cameraActs cases are executed, the camera configuration file cannot be found, and the initialization fails.</p>
</td>
</tr>
<tr id="row0342133417396"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p153278540395"><a name="p153278540395"></a><a name="p153278540395"></a><a href="https://gitee.com/openharmony/drivers_adapter_khdf_liteos/issues/I3D71U" target="_blank" rel="noopener noreferrer">I3D71U</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p93271254153915"><a name="p93271254153915"></a><a name="p93271254153915"></a>[Driver] When the system is reset repeatedly and started successfully by hmac_main_init, there is a high possibility that the system is suspended.</p>
</td>
</tr>
<tr id="row8342934173920"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p7328145410392"><a name="p7328145410392"></a><a name="p7328145410392"></a><a href="https://gitee.com/openharmony/community/issues/I3EGUX" target="_blank" rel="noopener noreferrer">I3EGUX</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p9328654193918"><a name="p9328654193918"></a><a name="p9328654193918"></a>[Reliability issue] When the system is reset repeatedly, and the KIdle process crashes once, the system is suspended and cannot be started.</p>
</td>
</tr>
<tr id="row034213453916"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p132875473912"><a name="p132875473912"></a><a name="p132875473912"></a><a href="https://gitee.com/openharmony/community/issues/I3DHIL" target="_blank" rel="noopener noreferrer">I3DHIL</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p17328105420391"><a name="p17328105420391"></a><a name="p17328105420391"></a>[System issue] The remaining space of the open-source Hi3518 development board is insufficient. As a result, a large number of ACTS test cases fail.</p>
</td>
</tr>
</tbody>
</table>

