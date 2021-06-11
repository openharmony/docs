# OpenHarmony 1.1.0 LTS \(2021-04-01\)<a name="EN-US_TOPIC_0000001095652840"></a>

-   [Overview](#section1846294912228)
-   [Source Code Acquisition](#section84808293211)
    -   [Acquiring Source Code from Image Sites](#section8394142222113)
    -   [Acquiring Source Code Using the repo Tool](#section7180193542317)

-   [What's New](#section175225345334)
-   [Resolved Issues](#section11935243172612)

## Overview<a name="section1846294912228"></a>

This is the first long-term support \(LTS\) version of OpenHarmony. It supports more functions and fixes some bugs in OpenHarmony 1.0.

-   OpenHarmony1.1.0 supports more subsystems, including the AI, power management, pan-sensor, and update subsystems.
-   OpenHarmony1.1.0 provides a unified AI engine framework.
-   The LiteOS Cortex-M kernel has been reconstructed for porting third-party chips to OpenHarmony.
-   The driver subsystem provides models for the WLAN, sensor, input, and display drivers.
-   The graphics subsystem has been optimized for an enhanced UI and improved performance and memory for the JS application framework.
-   The directory structure and module repositories have been significantly improved.

## Source Code Acquisition<a name="section84808293211"></a>

### Acquiring Source Code from Image Sites<a name="section8394142222113"></a>

**Table  1**  Sites for acquiring source code

<a name="table14394152217216"></a>
<table><thead align="left"><tr id="row15394132214217"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p15394122214219"><a name="p15394122214219"></a><a name="p15394122214219"></a>Source Code</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p10394112292119"><a name="p10394112292119"></a><a name="p10394112292119"></a>Version Information</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p039562213211"><a name="p039562213211"></a><a name="p039562213211"></a>Site</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1039572272110"><a name="p1039572272110"></a><a name="p1039572272110"></a>SHA-256 Verification Code</p>
</th>
</tr>
</thead>
<tbody><tr id="row9395722182111"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p039514225215"><a name="p039514225215"></a><a name="p039514225215"></a>Full code base</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p839514220217"><a name="p839514220217"></a><a name="p839514220217"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p339552222120"><a name="p339552222120"></a><a name="p339552222120"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p19395142202117"><a name="p19395142202117"></a><a name="p19395142202117"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA-256 verification code</a></p>
</td>
</tr>
<tr id="row1739512225217"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1839592272117"><a name="p1839592272117"></a><a name="p1839592272117"></a>Hi3861 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p7395722112113"><a name="p7395722112113"></a><a name="p7395722112113"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p53957224215"><a name="p53957224215"></a><a name="p53957224215"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p183959226211"><a name="p183959226211"></a><a name="p183959226211"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA-256 verification code</a></p>
</td>
</tr>
<tr id="row16395122262110"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p12395172242118"><a name="p12395172242118"></a><a name="p12395172242118"></a>Hi3518 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p12395182210215"><a name="p12395182210215"></a><a name="p12395182210215"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p133952022162113"><a name="p133952022162113"></a><a name="p133952022162113"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p2039542211214"><a name="p2039542211214"></a><a name="p2039542211214"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA-256 verification code</a></p>
</td>
</tr>
<tr id="row1839592272117"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p8395322182113"><a name="p8395322182113"></a><a name="p8395322182113"></a>Hi3516 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p20395152262114"><a name="p20395152262114"></a><a name="p20395152262114"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1639552272118"><a name="p1639552272118"></a><a name="p1639552272118"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p12396132216212"><a name="p12396132216212"></a><a name="p12396132216212"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256 verification code</a></p>
</td>
</tr>
<tr id="row3396822162120"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p18506191313914"><a name="p18506191313914"></a><a name="p18506191313914"></a>Release Notes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p10396102282110"><a name="p10396102282110"></a><a name="p10396102282110"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15396192232119"><a name="p15396192232119"></a><a name="p15396192232119"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/OpenHarmony_Release_Notes_zh_cn.zip" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p039662242117"><a name="p039662242117"></a><a name="p039662242117"></a>N/A</p>
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

## What's New<a name="section175225345334"></a>

This version inherits all features of OpenHarmony 1.0, and adds and optimizes features for different modules based on OpenHarmony 1.0. The following table lists the feature updates.

**Table  2**  Feature updates

<a name="table143385853320"></a>
<table><thead align="left"><tr id="row53375863312"><th class="cellrowborder" valign="top" width="13.38%" id="mcps1.2.5.1.1"><p id="p20331858193317"><a name="p20331858193317"></a><a name="p20331858193317"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="38.54%" id="mcps1.2.5.1.2"><p id="p1133115820331"><a name="p1133115820331"></a><a name="p1133115820331"></a>New Features</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.2.5.1.3"><p id="p162468531345"><a name="p162468531345"></a><a name="p162468531345"></a>Modified Features</p>
</th>
<th class="cellrowborder" valign="top" width="19.67%" id="mcps1.2.5.1.4"><p id="p9985141863716"><a name="p9985141863716"></a><a name="p9985141863716"></a>Deleted Features</p>
</th>
</tr>
</thead>
<tbody><tr id="row333115812331"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p31751943143520"><a name="p31751943143520"></a><a name="p31751943143520"></a>Kernel</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul4760125719351"></a><a name="ul4760125719351"></a><ul id="ul4760125719351"><li>The LiteOS Cortex-M kernel supports the Cortex-M7, Cortex-M33, and RISC-V chip architecture, and the corresponding samples are provided.</li><li>The LiteOS Cortex-M kernel supports the memory protection unit (MPU).</li><li>The LiteOS Cortex-M kernel supports some POSIX APIs.</li><li>The LiteOS Cortex-M kernel supports the FatFS file system.</li><li>The LiteOS Cortex-M kernel supports the registration of exception callbacks.</li><li>The architecture of the LiteOS Cortex-M kernel has been adjusted for third-party chips to adapt to OpenHarmony.</li><li>The LiteOS Cortex-M and LiteOS Cortex-A kernels support the heap memory debugging functionalities, covering memory leakage, illegal access to the memory, and memory statistics.</li><li>The LiteOS Cortex-M and LiteOS Cortex-A kernels support the TLSF heap memory algorithm, which improves the efficiency of memory application and release and reduces the fragmentation rate.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p207894916364"><a name="p207894916364"></a><a name="p207894916364"></a>LiteOS Cortex-A scheduling has been optimized.</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p2098521893713"><a name="p2098521893713"></a><a name="p2098521893713"></a>None</p>
</td>
</tr>
<tr id="row173335873311"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p8294101513612"><a name="p8294101513612"></a><a name="p8294101513612"></a>Pan-sensor</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><p id="p29882273369"><a name="p29882273369"></a><a name="p29882273369"></a>A sensor module has been added. You can now query the sensor list, enable or disable a sensor, subscribe to or unsubscribe from sensor data, set the data reporting mode of a sensor, and set sensor options such as the data sampling interval.</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p175171027115517"><a name="p175171027115517"></a><a name="p175171027115517"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p555482725510"><a name="p555482725510"></a><a name="p555482725510"></a>None</p>
</td>
</tr>
<tr id="row15331058133314"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p135282348360"><a name="p135282348360"></a><a name="p135282348360"></a>Globalization</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><p id="p127721442123615"><a name="p127721442123615"></a><a name="p127721442123615"></a>C/C++ APIs have been added for number, date, time, and singular-plural formatting in 79 languages.</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p5589227195515"><a name="p5589227195515"></a><a name="p5589227195515"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p156111127125519"><a name="p156111127125519"></a><a name="p156111127125519"></a>None</p>
</td>
</tr>
<tr id="row1034145820330"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p194507512361"><a name="p194507512361"></a><a name="p194507512361"></a>JS Application Framework</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul156745563613"></a><a name="ul156745563613"></a><ul id="ul156745563613"><li>A global JavaScript UI attribute, <strong id="b40015098265425"><a name="b40015098265425"></a><a name="b40015098265425"></a>opacity</strong>, has been added.</li><li>A <strong id="b139407671265425"><a name="b139407671265425"></a><a name="b139407671265425"></a>prompt.showDialog</strong> API has been added.</li><li>A QR code component <strong id="b114058780865425"><a name="b114058780865425"></a><a name="b114058780865425"></a>qrcode</strong> has been added.</li><li>Event pop-ups have been added.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><a name="ul1521675183713"></a><a name="ul1521675183713"></a><ul id="ul1521675183713"><li>Internationalization has been improved, with quicker page redirections. Number internationalization and time/date conversions are now available.</li><li>The UI layout has been enhanced, with percentage values supported for some styles.</li><li>The size adaptation capabilities of the <strong id="b78224172965425"><a name="b78224172965425"></a><a name="b78224172965425"></a>input</strong> and <strong id="b112869515165425"><a name="b112869515165425"></a><a name="b112869515165425"></a>switch</strong> components have been enhanced.</li><li>The <strong id="b116867139365425"><a name="b116867139365425"></a><a name="b116867139365425"></a>image</strong> component supports access to images in an application's private directory.</li><li>The <strong id="b99826682565425"><a name="b99826682565425"></a><a name="b99826682565425"></a>image-animator</strong> component allows you to specify the end frame.</li><li>Some APIs have been made available for the <strong id="b154107982665425"><a name="b154107982665425"></a><a name="b154107982665425"></a>canvas</strong> component.</li><li>Some return fields have been added for the <strong id="b186271557165425"><a name="b186271557165425"></a><a name="b186271557165425"></a>device.getInfo</strong> API.</li><li>DFX can trace methods that encounter exceptions and output a list of such methods.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p86015315379"><a name="p86015315379"></a><a name="p86015315379"></a>Backtracking is no longer supported for internationalization functions.</p>
</td>
</tr>
<tr id="row334175803317"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p243416212389"><a name="p243416212389"></a><a name="p243416212389"></a>Testing</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul46498614381"></a><a name="ul46498614381"></a><ul id="ul46498614381"><li>The testing tool can filter test cases to execute based on the case level.</li><li>Demo test cases have been added.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p18996183216557"><a name="p18996183216557"></a><a name="p18996183216557"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p153093375512"><a name="p153093375512"></a><a name="p153093375512"></a>None</p>
</td>
</tr>
<tr id="row834358143319"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p104871716123812"><a name="p104871716123812"></a><a name="p104871716123812"></a>Graphics</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul164401121203816"></a><a name="ul164401121203816"></a><ul id="ul164401121203816"><li>Component rotation, scaling, and opacity management have been added.</li><li>Event pop-ups and the crown rotation event have been added.</li><li>There is now GIF image parsing and display, percentage-based width and height layout, and video and QR code components.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p5908129143819"><a name="p5908129143819"></a><a name="p5908129143819"></a>Partial rendering and SIMD performance have been optimized.</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p29561057105519"><a name="p29561057105519"></a><a name="p29561057105519"></a>None</p>
</td>
</tr>
<tr id="row2216639113811"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p11452451173813"><a name="p11452451173813"></a><a name="p11452451173813"></a>Utils</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul139511255113815"></a><a name="ul139511255113815"></a><ul id="ul139511255113815"><li>System attribute dumping is supported.</li><li>Memory pool management APIs have been added for upper-layer modules.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1770461785620"><a name="p1770461785620"></a><a name="p1770461785620"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p998117571553"><a name="p998117571553"></a><a name="p998117571553"></a>None</p>
</td>
</tr>
<tr id="row119944512385"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p20115719395"><a name="p20115719395"></a><a name="p20115719395"></a>Driver</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul100191223919"></a><a name="ul100191223919"></a><ul id="ul100191223919"><li>The sensor, input, and display driver models have been added.</li><li>The MIPI DSI and pulse width modulation (PWM) have been added.</li><li>Hardware Driver Interfaces (HDIs) and Wi-Fi flow control have been added.</li><li>The I/O service grouping feature has been added for the Hardware Driver Foundation (HDF).</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p460532073911"><a name="p460532073911"></a><a name="p460532073911"></a>Driver loading has been optimized. It can now be accomplished in segmented parts.</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p7319581551"><a name="p7319581551"></a><a name="p7319581551"></a>None</p>
</td>
</tr>
<tr id="row18711154213388"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p185909284392"><a name="p185909284392"></a><a name="p185909284392"></a>Intelligent Soft Bus</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul126884329393"></a><a name="ul126884329393"></a><ul id="ul126884329393"><li>A Wi-Fi Aware module has been added.</li><li>IPC supports non-aligned marshalling.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p114241375617"><a name="p114241375617"></a><a name="p114241375617"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p6261458185513"><a name="p6261458185513"></a><a name="p6261458185513"></a>None</p>
</td>
</tr>
<tr id="row933514718399"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p15353948123912"><a name="p15353948123912"></a><a name="p15353948123912"></a>Security</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul16110105811391"></a><a name="ul16110105811391"></a><ul id="ul16110105811391"><li>HUKS provides the SHA-256, RSA-3072, RSA-2048, AES-128, and ECC security algorithms and APIs, as well as key management and storage.</li><li>The lightweight HiChain is available for managing and authenticating device groups without requiring login to devices using the same account, and for ensuring the communication security based on the Intelligent Soft Bus. It also provides APIs for system services and applications.</li><li>A unified permission management system has been added to manage permissions for lightweight devices.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p10854883569"><a name="p10854883569"></a><a name="p10854883569"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p848858175517"><a name="p848858175517"></a><a name="p848858175517"></a>None</p>
</td>
</tr>
<tr id="row1413119125400"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p57091617134017"><a name="p57091617134017"></a><a name="p57091617134017"></a>AI</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul327962215408"></a><a name="ul327962215408"></a><ul id="ul327962215408"><li>A unified AI engine framework has been added to implement quick integration of AI algorithm plug-ins. The framework consists of plug-in management, module management, and communications management modules. This framework provides lifecycle management and allows for on-demand deployment of AI algorithms.</li><li>A developer guide, and two AI capability plug-ins developed based on the AI engine framework and two AI application samples are provided for you to quickly integrate AI algorithms in the AI engine framework.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p7131191264012"><a name="p7131191264012"></a><a name="p7131191264012"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p1170145845518"><a name="p1170145845518"></a><a name="p1170145845518"></a>None</p>
</td>
</tr>
<tr id="row98001376403"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p16588112824019"><a name="p16588112824019"></a><a name="p16588112824019"></a>Update</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><p id="p163773464015"><a name="p163773464015"></a><a name="p163773464015"></a>An update capability framework for mini-system devices has been added. It provides APIs for update package verification, parsing, and installation.</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1080010712403"><a name="p1080010712403"></a><a name="p1080010712403"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p119211587555"><a name="p119211587555"></a><a name="p119211587555"></a>None</p>
</td>
</tr>
<tr id="row3104039184016"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p12573854134019"><a name="p12573854134019"></a><a name="p12573854134019"></a>XTS</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><p id="p15893189204113"><a name="p15893189204113"></a><a name="p15893189204113"></a>AI, DFX, globalization, and OTA compatibility test cases have been added.</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1170111714112"><a name="p1170111714112"></a><a name="p1170111714112"></a>Capabilities for the application framework, Intelligent Soft Bus, distributed scheduler, IoT, and kernel have been enhanced.</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p3114115820554"><a name="p3114115820554"></a><a name="p3114115820554"></a>None</p>
</td>
</tr>
<tr id="row95402484401"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p1031291510411"><a name="p1031291510411"></a><a name="p1031291510411"></a>Compilation and Building</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul061324164112"></a><a name="ul061324164112"></a><ul id="ul061324164112"><li>The command line tool hb has been added. It provides the <strong id="b195385132665425"><a name="b195385132665425"></a><a name="b195385132665425"></a>hb set</strong> and <strong id="b174540041565425"><a name="b174540041565425"></a><a name="b174540041565425"></a>hb build</strong> commands for building in the source code directory or any subdirectory.</li><li>Components provided by independent chip vendors are supported.</li><li>Components can be built independently based on the component name.</li><li>The build toolchain and options can be customized for different development boards.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1167916358411"><a name="p1167916358411"></a><a name="p1167916358411"></a>The product configuration has been decoupled from the <strong id="b35679808065425"><a name="b35679808065425"></a><a name="b35679808065425"></a>build_lite</strong> repository and is stored in <strong id="b10419560965425"><a name="b10419560965425"></a><a name="b10419560965425"></a>vendor/solution vendor/product/config.json</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p16136758125519"><a name="p16136758125519"></a><a name="p16136758125519"></a>None</p>
</td>
</tr>
<tr id="row16281465401"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p0889841174116"><a name="p0889841174116"></a><a name="p0889841174116"></a>Power Management</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul175961462411"></a><a name="ul175961462411"></a><ul id="ul175961462411"><li>Battery level query is now supported.</li><li>Always-on screen functionalities have been added, along with corresponding APIs.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p3628746194013"><a name="p3628746194013"></a><a name="p3628746194013"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p3158165885517"><a name="p3158165885517"></a><a name="p3158165885517"></a>None</p>
</td>
</tr>
</tbody>
</table>

The following table describes the optimization of repositories.

> **NOTE:** 
>-   Read-only archiving means archiving a module repository to the  **openharmony-retired**  organization and setting the repository to read-only.
>-   Code for third-party chips has been decoupled from the OS. HiSilicon chip SDKs have been moved from the  **vendor**  directory to the  **device/hisilicon**  directory.

**Table  3**  Optimization of repositories

<a name="table91984129177"></a>
<table><thead align="left"><tr id="row51981312101713"><th class="cellrowborder" valign="top" width="33.64%" id="mcps1.2.4.1.1"><p id="p194252040214"><a name="p194252040214"></a><a name="p194252040214"></a>OpenHarmony1.0</p>
</th>
<th class="cellrowborder" valign="top" width="37.059999999999995%" id="mcps1.2.4.1.2"><p id="p242515412216"><a name="p242515412216"></a><a name="p242515412216"></a>OpenHarmony1.1.0</p>
</th>
<th class="cellrowborder" valign="top" width="29.299999999999997%" id="mcps1.2.4.1.3"><p id="p5425144729"><a name="p5425144729"></a><a name="p5425144729"></a>Optimization</p>
</th>
</tr>
</thead>
<tbody><tr id="row21528111414"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p14614112117"><a name="p14614112117"></a><a name="p14614112117"></a>ace_lite_jsfwk</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p8619114115"><a name="p8619114115"></a><a name="p8619114115"></a>ace_engine_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1661811711"><a name="p1661811711"></a><a name="p1661811711"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1152121117112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p57121115112"><a name="p57121115112"></a><a name="p57121115112"></a>ace_interfaces_innerkits_builtin</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1771119118"><a name="p1771119118"></a><a name="p1771119118"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p127161115114"><a name="p127161115114"></a><a name="p127161115114"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row191521611211"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12711117113"><a name="p12711117113"></a><a name="p12711117113"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p9711112118"><a name="p9711112118"></a><a name="p9711112118"></a>ai_engine</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p15714118113"><a name="p15714118113"></a><a name="p15714118113"></a>New module</p>
</td>
</tr>
<tr id="row20151011611"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p2715118118"><a name="p2715118118"></a><a name="p2715118118"></a>hiviewdfx_frameworks_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1751117113"><a name="p1751117113"></a><a name="p1751117113"></a>hiviewdfx_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2710111617"><a name="p2710111617"></a><a name="p2710111617"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row61511511213"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1276111112"><a name="p1276111112"></a><a name="p1276111112"></a>hiviewdfx_frameworks_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p37191115116"><a name="p37191115116"></a><a name="p37191115116"></a>hiviewdfx_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p19711111311"><a name="p19711111311"></a><a name="p19711111311"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row111511011014"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p9713112114"><a name="p9713112114"></a><a name="p9713112114"></a>hiviewdfx_utils_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p14718119112"><a name="p14718119112"></a><a name="p14718119112"></a>hiviewdfx_hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p579111716"><a name="p579111716"></a><a name="p579111716"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row101511711311"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p187711715"><a name="p187711715"></a><a name="p187711715"></a>hiviewdfx_frameworks_ddrdump_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1173111319"><a name="p1173111319"></a><a name="p1173111319"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p18741118112"><a name="p18741118112"></a><a name="p18741118112"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row111517117112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1385115116"><a name="p1385115116"></a><a name="p1385115116"></a>hiviewdfx_interfaces_innerkits_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1881111212"><a name="p1881111212"></a><a name="p1881111212"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1987112018"><a name="p1987112018"></a><a name="p1987112018"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row015131111115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p128121116110"><a name="p128121116110"></a><a name="p128121116110"></a>hiviewdfx_interfaces_innerkits_hilog</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p17817111017"><a name="p17817111017"></a><a name="p17817111017"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12819111216"><a name="p12819111216"></a><a name="p12819111216"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row215161113114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1981611219"><a name="p1981611219"></a><a name="p1981611219"></a>hiviewdfx_interfaces_kits_hilog</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p198121115114"><a name="p198121115114"></a><a name="p198121115114"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p20812111817"><a name="p20812111817"></a><a name="p20812111817"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row41513111818"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p58111119112"><a name="p58111119112"></a><a name="p58111119112"></a>hiviewdfx_interfaces_kits_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p9812111313"><a name="p9812111313"></a><a name="p9812111313"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p281211415"><a name="p281211415"></a><a name="p281211415"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row71516112112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p287112011"><a name="p287112011"></a><a name="p287112011"></a>hiviewdfx_services_hilogcat_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p14813119111"><a name="p14813119111"></a><a name="p14813119111"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2817111113"><a name="p2817111113"></a><a name="p2817111113"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row12151611714"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1786119114"><a name="p1786119114"></a><a name="p1786119114"></a>hiviewdfx_services_hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p129111112115"><a name="p129111112115"></a><a name="p129111112115"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p3991111116"><a name="p3991111116"></a><a name="p3991111116"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row31517113116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p695111118"><a name="p695111118"></a><a name="p695111118"></a>iothardware_hals_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p797111718"><a name="p797111718"></a><a name="p797111718"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p6911119115"><a name="p6911119115"></a><a name="p6911119115"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row815112117113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p0941110120"><a name="p0941110120"></a><a name="p0941110120"></a>iothardware_interfaces_kits_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1291711016"><a name="p1291711016"></a><a name="p1291711016"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p79211318"><a name="p79211318"></a><a name="p79211318"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row4151161119118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p6910115120"><a name="p6910115120"></a><a name="p6910115120"></a>iothardware_frameworks_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p17961117116"><a name="p17961117116"></a><a name="p17961117116"></a>iothardware_peripheral</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p11912117114"><a name="p11912117114"></a><a name="p11912117114"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row31511111415"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p159411316"><a name="p159411316"></a><a name="p159411316"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p09111113114"><a name="p09111113114"></a><a name="p09111113114"></a>applications_camera_sample_communication</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1599111217"><a name="p1599111217"></a><a name="p1599111217"></a>New module</p>
</td>
</tr>
<tr id="row1015115110114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p20914113110"><a name="p20914113110"></a><a name="p20914113110"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p17917119110"><a name="p17917119110"></a><a name="p17917119110"></a>applications_camera_screensaver_app</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1101911618"><a name="p1101911618"></a><a name="p1101911618"></a>New module</p>
</td>
</tr>
<tr id="row91511211912"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p151017111018"><a name="p151017111018"></a><a name="p151017111018"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1510101119117"><a name="p1510101119117"></a><a name="p1510101119117"></a>sensors_miscdevice_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1910101116115"><a name="p1910101116115"></a><a name="p1910101116115"></a>New module</p>
</td>
</tr>
<tr id="row61519111318"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1108111919"><a name="p1108111919"></a><a name="p1108111919"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1510131119115"><a name="p1510131119115"></a><a name="p1510131119115"></a>sensors_sensor_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p4101611813"><a name="p4101611813"></a><a name="p4101611813"></a>New module</p>
</td>
</tr>
<tr id="row121512111715"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1010011814"><a name="p1010011814"></a><a name="p1010011814"></a>xts_tools_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p41018111019"><a name="p41018111019"></a><a name="p41018111019"></a>xts_tools</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p5100111114"><a name="p5100111114"></a><a name="p5100111114"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row61512111110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p16101113112"><a name="p16101113112"></a><a name="p16101113112"></a>security_services_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p15106119117"><a name="p15106119117"></a><a name="p15106119117"></a>security_permission</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p141041112120"><a name="p141041112120"></a><a name="p141041112120"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row131518112113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p11103112120"><a name="p11103112120"></a><a name="p11103112120"></a>security_interfaces_innerkits_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p510011411"><a name="p510011411"></a><a name="p510011411"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p610211215"><a name="p610211215"></a><a name="p610211215"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row101511611812"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p14111911619"><a name="p14111911619"></a><a name="p14111911619"></a>security_interfaces_kits_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p91121113116"><a name="p91121113116"></a><a name="p91121113116"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p131111111115"><a name="p131111111115"></a><a name="p131111111115"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row6151161119116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p10112111511"><a name="p10112111511"></a><a name="p10112111511"></a>security_services_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p911181119116"><a name="p911181119116"></a><a name="p911181119116"></a>security_itrustee_ree_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p0111111212"><a name="p0111111212"></a><a name="p0111111212"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row7151151116115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p111118115118"><a name="p111118115118"></a><a name="p111118115118"></a>security_interfaces_innerkits_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p141110111714"><a name="p141110111714"></a><a name="p141110111714"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p31112111813"><a name="p31112111813"></a><a name="p31112111813"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row3151011618"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p13111411519"><a name="p13111411519"></a><a name="p13111411519"></a>security_frameworks_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p3111116118"><a name="p3111116118"></a><a name="p3111116118"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p311131113119"><a name="p311131113119"></a><a name="p311131113119"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row315171112116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12111611410"><a name="p12111611410"></a><a name="p12111611410"></a>security_services_app_verify</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p311161117112"><a name="p311161117112"></a><a name="p311161117112"></a>security_appverify</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1611111412"><a name="p1611111412"></a><a name="p1611111412"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1715116111215"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p101116112118"><a name="p101116112118"></a><a name="p101116112118"></a>security_interfaces_innerkits_app_verify</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1412141112111"><a name="p1412141112111"></a><a name="p1412141112111"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p31251119116"><a name="p31251119116"></a><a name="p31251119116"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row61514112110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p201218117114"><a name="p201218117114"></a><a name="p201218117114"></a>security_services_hichainsdk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1512101119119"><a name="p1512101119119"></a><a name="p1512101119119"></a>security_deviceauth</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p612161111119"><a name="p612161111119"></a><a name="p612161111119"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row17151161117116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p121217111515"><a name="p121217111515"></a><a name="p121217111515"></a>security_interfaces_innerkits_hichainsdk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p18127113119"><a name="p18127113119"></a><a name="p18127113119"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p121220116110"><a name="p121220116110"></a><a name="p121220116110"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row191501611710"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p17121114120"><a name="p17121114120"></a><a name="p17121114120"></a>security_services_huks_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1412811119"><a name="p1412811119"></a><a name="p1412811119"></a>security_huks</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p14129117112"><a name="p14129117112"></a><a name="p14129117112"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row6150191115118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p412181117112"><a name="p412181117112"></a><a name="p412181117112"></a>security_interfaces_innerkits_huks_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p191201115110"><a name="p191201115110"></a><a name="p191201115110"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p31281110114"><a name="p31281110114"></a><a name="p31281110114"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row16150161113118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p01212110114"><a name="p01212110114"></a><a name="p01212110114"></a>security_frameworks_crypto_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p10132115118"><a name="p10132115118"></a><a name="p10132115118"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1138111015"><a name="p1138111015"></a><a name="p1138111015"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row415015111419"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12131011513"><a name="p12131011513"></a><a name="p12131011513"></a>security_interfaces_innerkits_crypto_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p61315112013"><a name="p61315112013"></a><a name="p61315112013"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p413141116112"><a name="p413141116112"></a><a name="p413141116112"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row615012111417"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p613121110118"><a name="p613121110118"></a><a name="p613121110118"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p31341114116"><a name="p31341114116"></a><a name="p31341114116"></a>signcenter_tool</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p9136119111"><a name="p9136119111"></a><a name="p9136119111"></a>New module</p>
</td>
</tr>
<tr id="row915021114110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p141381118111"><a name="p141381118111"></a><a name="p141381118111"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p11331113111"><a name="p11331113111"></a><a name="p11331113111"></a>third_party_cryptsetup</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p101391111113"><a name="p101391111113"></a><a name="p101391111113"></a>New module</p>
</td>
</tr>
<tr id="row1515010111813"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p17135111112"><a name="p17135111112"></a><a name="p17135111112"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p41313111116"><a name="p41313111116"></a><a name="p41313111116"></a>third_party_JSON-C</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p16134113114"><a name="p16134113114"></a><a name="p16134113114"></a>New module</p>
</td>
</tr>
<tr id="row1815031117116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p0133113116"><a name="p0133113116"></a><a name="p0133113116"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1014171117120"><a name="p1014171117120"></a><a name="p1014171117120"></a>third_party_libuuid</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p914171117112"><a name="p914171117112"></a><a name="p914171117112"></a>New module</p>
</td>
</tr>
<tr id="row51501611515"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p191418111412"><a name="p191418111412"></a><a name="p191418111412"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p0147111618"><a name="p0147111618"></a><a name="p0147111618"></a>third_party_LVM2</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1814181111112"><a name="p1814181111112"></a><a name="p1814181111112"></a>New module</p>
</td>
</tr>
<tr id="row151504111413"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p15143119111"><a name="p15143119111"></a><a name="p15143119111"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p121413112115"><a name="p121413112115"></a><a name="p121413112115"></a>third_party_popt</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1114311312"><a name="p1114311312"></a><a name="p1114311312"></a>New module</p>
</td>
</tr>
<tr id="row1215061120115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p4142114111"><a name="p4142114111"></a><a name="p4142114111"></a>communication_interfaces_kits_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p161441110113"><a name="p161441110113"></a><a name="p161441110113"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p101419116115"><a name="p101419116115"></a><a name="p101419116115"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row131502115117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p14141611315"><a name="p14141611315"></a><a name="p14141611315"></a>communication_frameworks_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p514181112117"><a name="p514181112117"></a><a name="p514181112117"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p414151119114"><a name="p414151119114"></a><a name="p414151119114"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row715010118116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p71551114114"><a name="p71551114114"></a><a name="p71551114114"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p5151711312"><a name="p5151711312"></a><a name="p5151711312"></a>communication_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p181512118118"><a name="p181512118118"></a><a name="p181512118118"></a>New module</p>
</td>
</tr>
<tr id="row14150121110113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1215711419"><a name="p1215711419"></a><a name="p1215711419"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p151515117117"><a name="p151515117117"></a><a name="p151515117117"></a>powermgr_powermgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1015191116115"><a name="p1015191116115"></a><a name="p1015191116115"></a>New module</p>
</td>
</tr>
<tr id="row12150511311"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p8152011815"><a name="p8152011815"></a><a name="p8152011815"></a>distributedschedule_services_dtbschedmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p815811918"><a name="p815811918"></a><a name="p815811918"></a>distributedschedule_dms_fwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p18151113120"><a name="p18151113120"></a><a name="p18151113120"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row2015061110115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p191516111514"><a name="p191516111514"></a><a name="p191516111514"></a>distributedschedule_services_safwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p19151111512"><a name="p19151111512"></a><a name="p19151111512"></a>distributedschedule_safwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p11581116114"><a name="p11581116114"></a><a name="p11581116114"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row51509113120"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p111531111115"><a name="p111531111115"></a><a name="p111531111115"></a>distributedschedule_services_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p20151711418"><a name="p20151711418"></a><a name="p20151711418"></a>distributedschedule_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p111541118116"><a name="p111541118116"></a><a name="p111541118116"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1115018112114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p516171112110"><a name="p516171112110"></a><a name="p516171112110"></a>distributedschedule_interfaces_innerkits_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4163112118"><a name="p4163112118"></a><a name="p4163112118"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p61621110114"><a name="p61621110114"></a><a name="p61621110114"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row13150311413"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p416211212"><a name="p416211212"></a><a name="p416211212"></a>distributedschedule_interfaces_kits_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1116171111117"><a name="p1116171111117"></a><a name="p1116171111117"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p716161119113"><a name="p716161119113"></a><a name="p716161119113"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1515017111511"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p6162117115"><a name="p6162117115"></a><a name="p6162117115"></a>multimedia_frameworks_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p13166111112"><a name="p13166111112"></a><a name="p13166111112"></a>multimedia_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p0163112120"><a name="p0163112120"></a><a name="p0163112120"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1115081110117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p21619111411"><a name="p21619111411"></a><a name="p21619111411"></a>multimedia_frameworks_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p3168113114"><a name="p3168113114"></a><a name="p3168113114"></a>multimedia_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p4161011316"><a name="p4161011316"></a><a name="p4161011316"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row415010116114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1161111410"><a name="p1161111410"></a><a name="p1161111410"></a>multimedia_frameworks_player_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p151691115110"><a name="p151691115110"></a><a name="p151691115110"></a>multimedia_media_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p31720110114"><a name="p31720110114"></a><a name="p31720110114"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row61502116111"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p141751114116"><a name="p141751114116"></a><a name="p141751114116"></a>multimedia_hals_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p01720119111"><a name="p01720119111"></a><a name="p01720119111"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p81717111213"><a name="p81717111213"></a><a name="p81717111213"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row915010112116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p2177111117"><a name="p2177111117"></a><a name="p2177111117"></a>multimedia_frameworks_recorder_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p71712119117"><a name="p71712119117"></a><a name="p71712119117"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p17171111015"><a name="p17171111015"></a><a name="p17171111015"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1615019111111"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p91710114111"><a name="p91710114111"></a><a name="p91710114111"></a>multimedia_interfaces_kits_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1917411114"><a name="p1917411114"></a><a name="p1917411114"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1173111914"><a name="p1173111914"></a><a name="p1173111914"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1815012111119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p0171111214"><a name="p0171111214"></a><a name="p0171111214"></a>multimedia_interfaces_kits_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p11717111819"><a name="p11717111819"></a><a name="p11717111819"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1017811112"><a name="p1017811112"></a><a name="p1017811112"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row715020117112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p71716113114"><a name="p71716113114"></a><a name="p71716113114"></a>multimedia_interfaces_kits_player_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p12189114114"><a name="p12189114114"></a><a name="p12189114114"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p21811111319"><a name="p21811111319"></a><a name="p21811111319"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row8150151118120"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p17188116110"><a name="p17188116110"></a><a name="p17188116110"></a>multimedia_interfaces_kits_recorder_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p81813118110"><a name="p81813118110"></a><a name="p81813118110"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1518111114110"><a name="p1518111114110"></a><a name="p1518111114110"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row201491811815"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p171831118117"><a name="p171831118117"></a><a name="p171831118117"></a>multimedia_services_media_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p18188111815"><a name="p18188111815"></a><a name="p18188111815"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p71812111316"><a name="p71812111316"></a><a name="p71812111316"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row141493116113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p14189112013"><a name="p14189112013"></a><a name="p14189112013"></a>kernel_liteos_a_huawei_proprietary_fs_proc</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p201817111115"><a name="p201817111115"></a><a name="p201817111115"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1918611618"><a name="p1918611618"></a><a name="p1918611618"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row101495114110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1418101116111"><a name="p1418101116111"></a><a name="p1418101116111"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p171818117118"><a name="p171818117118"></a><a name="p171818117118"></a>third_party_mksh</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2018121120115"><a name="p2018121120115"></a><a name="p2018121120115"></a>New module</p>
</td>
</tr>
<tr id="row1614917113112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p5191111414"><a name="p5191111414"></a><a name="p5191111414"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1419201115118"><a name="p1419201115118"></a><a name="p1419201115118"></a>third_party_optimized_routines</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p18191711211"><a name="p18191711211"></a><a name="p18191711211"></a>New module</p>
</td>
</tr>
<tr id="row7149121120114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p151918117112"><a name="p151918117112"></a><a name="p151918117112"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p181916111611"><a name="p181916111611"></a><a name="p181916111611"></a>third_party_toybox</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p121914111618"><a name="p121914111618"></a><a name="p121914111618"></a>New module</p>
</td>
</tr>
<tr id="row151491117117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p171911112114"><a name="p171911112114"></a><a name="p171911112114"></a>vendor_huawei_camera</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p7191111814"><a name="p7191111814"></a><a name="p7191111814"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p219191115110"><a name="p219191115110"></a><a name="p219191115110"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row614919115118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p101919111111"><a name="p101919111111"></a><a name="p101919111111"></a>vendor_huawei_wifi_iot</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1119101111111"><a name="p1119101111111"></a><a name="p1119101111111"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1919111114115"><a name="p1919111114115"></a><a name="p1919111114115"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row12149811717"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p10198119114"><a name="p10198119114"></a><a name="p10198119114"></a>startup_services_bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p72031119117"><a name="p72031119117"></a><a name="p72031119117"></a>startup_bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1320121116111"><a name="p1320121116111"></a><a name="p1320121116111"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row114991110114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p420161112113"><a name="p420161112113"></a><a name="p420161112113"></a>startup_frameworks_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p122018111319"><a name="p122018111319"></a><a name="p122018111319"></a>startup_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1420711016"><a name="p1420711016"></a><a name="p1420711016"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1914981112110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p82041113119"><a name="p82041113119"></a><a name="p82041113119"></a>startup_hals_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p8204110113"><a name="p8204110113"></a><a name="p8204110113"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p5203116116"><a name="p5203116116"></a><a name="p5203116116"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row714910111119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p102011112114"><a name="p102011112114"></a><a name="p102011112114"></a>startup_interfaces_kits_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p132081116113"><a name="p132081116113"></a><a name="p132081116113"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p02016111419"><a name="p02016111419"></a><a name="p02016111419"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row614917115119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p02081112120"><a name="p02081112120"></a><a name="p02081112120"></a>graphic_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p5201011512"><a name="p5201011512"></a><a name="p5201011512"></a>graphic_surface</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p320111116119"><a name="p320111116119"></a><a name="p320111116119"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row7149101110119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1621711214"><a name="p1621711214"></a><a name="p1621711214"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p32118113119"><a name="p32118113119"></a><a name="p32118113119"></a>graphic_ui</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p152161111110"><a name="p152161111110"></a><a name="p152161111110"></a>New module</p>
</td>
</tr>
<tr id="row121496111617"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1021211311"><a name="p1021211311"></a><a name="p1021211311"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p9211611416"><a name="p9211611416"></a><a name="p9211611416"></a>graphic_utils</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p221161120115"><a name="p221161120115"></a><a name="p221161120115"></a>New module</p>
</td>
</tr>
<tr id="row1214911111518"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p102112111216"><a name="p102112111216"></a><a name="p102112111216"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p2217117111"><a name="p2217117111"></a><a name="p2217117111"></a>graphic_wms</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p3211911717"><a name="p3211911717"></a><a name="p3211911717"></a>New module</p>
</td>
</tr>
<tr id="row51493111319"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p9219111514"><a name="p9219111514"></a><a name="p9219111514"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p62116115113"><a name="p62116115113"></a><a name="p62116115113"></a>third_party_giflib</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p4214116111"><a name="p4214116111"></a><a name="p4214116111"></a>New module</p>
</td>
</tr>
<tr id="row1714912115118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p4211911616"><a name="p4211911616"></a><a name="p4211911616"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p15223111413"><a name="p15223111413"></a><a name="p15223111413"></a>third_party_qrcodegen</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p622811418"><a name="p622811418"></a><a name="p622811418"></a>New module</p>
</td>
</tr>
<tr id="row191496119117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p172251120118"><a name="p172251120118"></a><a name="p172251120118"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p42212114119"><a name="p42212114119"></a><a name="p42212114119"></a>drivers_adapter_khdf_linux</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p5222111619"><a name="p5222111619"></a><a name="p5222111619"></a>New module</p>
</td>
</tr>
<tr id="row8149911112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p52261114112"><a name="p52261114112"></a><a name="p52261114112"></a>drivers_hdf_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p12211113115"><a name="p12211113115"></a><a name="p12211113115"></a>drivers_adapter_khdf_liteos</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p10221811516"><a name="p10221811516"></a><a name="p10221811516"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row201491111616"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1221011413"><a name="p1221011413"></a><a name="p1221011413"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p192216111512"><a name="p192216111512"></a><a name="p192216111512"></a>drivers_adapter_uhdf</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p15221211811"><a name="p15221211811"></a><a name="p15221211811"></a>New module</p>
</td>
</tr>
<tr id="row1414910111413"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p142241114118"><a name="p142241114118"></a><a name="p142241114118"></a>drivers_hdf_frameworks</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p11222112113"><a name="p11222112113"></a><a name="p11222112113"></a>drivers_framework</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2236111911"><a name="p2236111911"></a><a name="p2236111911"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row17149201118115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p423111617"><a name="p423111617"></a><a name="p423111617"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p123121110114"><a name="p123121110114"></a><a name="p123121110114"></a>drivers_peripheral_audio</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p52317112119"><a name="p52317112119"></a><a name="p52317112119"></a>New module</p>
</td>
</tr>
<tr id="row141491711613"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12236117112"><a name="p12236117112"></a><a name="p12236117112"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p182317115110"><a name="p182317115110"></a><a name="p182317115110"></a>drivers_peripheral_codec</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12231311617"><a name="p12231311617"></a><a name="p12231311617"></a>New module</p>
</td>
</tr>
<tr id="row1414916111017"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p5234119116"><a name="p5234119116"></a><a name="p5234119116"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p11231411813"><a name="p11231411813"></a><a name="p11231411813"></a>drivers_peripheral_display</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12351119113"><a name="p12351119113"></a><a name="p12351119113"></a>New module</p>
</td>
</tr>
<tr id="row3149511414"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p82315117116"><a name="p82315117116"></a><a name="p82315117116"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p16230111914"><a name="p16230111914"></a><a name="p16230111914"></a>drivers_peripheral_format</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p32313119113"><a name="p32313119113"></a><a name="p32313119113"></a>New module</p>
</td>
</tr>
<tr id="row914981120116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p52412111819"><a name="p52412111819"></a><a name="p52412111819"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p6248114114"><a name="p6248114114"></a><a name="p6248114114"></a>drivers_peripheral_input</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1724191113119"><a name="p1724191113119"></a><a name="p1724191113119"></a>New module</p>
</td>
</tr>
<tr id="row1114961117118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p62471111120"><a name="p62471111120"></a><a name="p62471111120"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p182414112011"><a name="p182414112011"></a><a name="p182414112011"></a>drivers_peripheral_sensor</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p11243112120"><a name="p11243112120"></a><a name="p11243112120"></a>New module</p>
</td>
</tr>
<tr id="row151491611914"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p16244113118"><a name="p16244113118"></a><a name="p16244113118"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p124171117113"><a name="p124171117113"></a><a name="p124171117113"></a>drivers_peripheral_wlan</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p124151114115"><a name="p124151114115"></a><a name="p124151114115"></a>New module</p>
</td>
</tr>
<tr id="row1314817111011"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p18248111615"><a name="p18248111615"></a><a name="p18248111615"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p10241911211"><a name="p10241911211"></a><a name="p10241911211"></a>global_cust_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p16242011718"><a name="p16242011718"></a><a name="p16242011718"></a>New module</p>
</td>
</tr>
<tr id="row101482011311"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p122520111815"><a name="p122520111815"></a><a name="p122520111815"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1625181116113"><a name="p1625181116113"></a><a name="p1625181116113"></a>global_i18n_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1725111617"><a name="p1725111617"></a><a name="p1725111617"></a>New module</p>
</td>
</tr>
<tr id="row171486113113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1325191119117"><a name="p1325191119117"></a><a name="p1325191119117"></a>global_frameworks_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p22518111418"><a name="p22518111418"></a><a name="p22518111418"></a>global_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p3254112113"><a name="p3254112113"></a><a name="p3254112113"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row111489112012"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p0254111118"><a name="p0254111118"></a><a name="p0254111118"></a>third_party_icu</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12571116118"><a name="p12571116118"></a><a name="p12571116118"></a>New module</p>
</td>
</tr>
<tr id="row11148141118119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p102581116119"><a name="p102581116119"></a><a name="p102581116119"></a>global_interfaces_innerkits_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4251711817"><a name="p4251711817"></a><a name="p4251711817"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p13251511916"><a name="p13251511916"></a><a name="p13251511916"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row6148151110115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12615112116"><a name="p12615112116"></a><a name="p12615112116"></a>communication_frameworks_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p3262011110"><a name="p3262011110"></a><a name="p3262011110"></a>communication_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p326911918"><a name="p326911918"></a><a name="p326911918"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1914816117116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p92617119117"><a name="p92617119117"></a><a name="p92617119117"></a>communication_interfaces_kits_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p19262113112"><a name="p19262113112"></a><a name="p19262113112"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p426181116113"><a name="p426181116113"></a><a name="p426181116113"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row014821113115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p92621113111"><a name="p92621113111"></a><a name="p92621113111"></a>communication_interfaces_kits_softbuskit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1926121111115"><a name="p1926121111115"></a><a name="p1926121111115"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p112612115114"><a name="p112612115114"></a><a name="p112612115114"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1914861120118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p8261111817"><a name="p8261111817"></a><a name="p8261111817"></a>communication_hals_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p182616115114"><a name="p182616115114"></a><a name="p182616115114"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p16262113119"><a name="p16262113119"></a><a name="p16262113119"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row214812111114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p32710114119"><a name="p32710114119"></a><a name="p32710114119"></a>communication_services_softbus_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p2272116112"><a name="p2272116112"></a><a name="p2272116112"></a>communication_softbus_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p172712113120"><a name="p172712113120"></a><a name="p172712113120"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row16148161112119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p15271011110"><a name="p15271011110"></a><a name="p15271011110"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p12741115115"><a name="p12741115115"></a><a name="p12741115115"></a>communication_wifi_aware</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p527141115118"><a name="p527141115118"></a><a name="p527141115118"></a>New module</p>
</td>
</tr>
<tr id="row111487119113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p11274111517"><a name="p11274111517"></a><a name="p11274111517"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1927811318"><a name="p1927811318"></a><a name="p1927811318"></a>update_ota_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p16271112014"><a name="p16271112014"></a><a name="p16271112014"></a>New module</p>
</td>
</tr>
<tr id="row20148151117114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1027131119119"><a name="p1027131119119"></a><a name="p1027131119119"></a>vendor_hisi_hi35xx_hi35xx_init</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p102712111813"><a name="p102712111813"></a><a name="p102712111813"></a>device_hisilicon_build</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p152716117114"><a name="p152716117114"></a><a name="p152716117114"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1314861117110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1028511716"><a name="p1028511716"></a><a name="p1028511716"></a>vendor_hisi_hi35xx_platform</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4281411410"><a name="p4281411410"></a><a name="p4281411410"></a>device_hisilicon_drivers</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p8287111119"><a name="p8287111119"></a><a name="p8287111119"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row121481911218"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p15281211918"><a name="p15281211918"></a><a name="p15281211918"></a>vendor_hisi_hi35xx_hardware</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p128111118119"><a name="p128111118119"></a><a name="p128111118119"></a>device_hisilicon_hardware</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p7283111416"><a name="p7283111416"></a><a name="p7283111416"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row11148171116110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p42810113116"><a name="p42810113116"></a><a name="p42810113116"></a>vendor_hisi_hi35xx_hi3518ev300</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1282111814"><a name="p1282111814"></a><a name="p1282111814"></a>device_hisilicon_hispark_aries</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p22817111716"><a name="p22817111716"></a><a name="p22817111716"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row614813111113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p182811116114"><a name="p182811116114"></a><a name="p182811116114"></a>vendor_hisi_hi3861_hi3861</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4285112119"><a name="p4285112119"></a><a name="p4285112119"></a>device_hisilicon_hispark_pegasus</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12821110110"><a name="p12821110110"></a><a name="p12821110110"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row214821119120"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p3291811612"><a name="p3291811612"></a><a name="p3291811612"></a>vendor_hisi_hi35xx_hi3516dv300</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p13291811715"><a name="p13291811715"></a><a name="p13291811715"></a>device_hisilicon_hispark_taurus</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p11294111615"><a name="p11294111615"></a><a name="p11294111615"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1314820111319"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p19297115119"><a name="p19297115119"></a><a name="p19297115119"></a>vendor_hisi_hi35xx_middleware</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p202961117117"><a name="p202961117117"></a><a name="p202961117117"></a>device_hisilicon_modules</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p329151119110"><a name="p329151119110"></a><a name="p329151119110"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row214814111719"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p162920111814"><a name="p162920111814"></a><a name="p162920111814"></a>vendor_hisi_hi35xx_middleware_source_third_party_ffmpeg</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p12294111112"><a name="p12294111112"></a><a name="p12294111112"></a>device_hisilicon_third_party_ffmpeg</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p18291011915"><a name="p18291011915"></a><a name="p18291011915"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row131486110119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12291611916"><a name="p12291611916"></a><a name="p12291611916"></a>vendor_hisi_hi35xx_thirdparty_uboot_src</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1293111018"><a name="p1293111018"></a><a name="p1293111018"></a>device_hisilicon_third_party_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p22914111616"><a name="p22914111616"></a><a name="p22914111616"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row181487111915"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p43013110113"><a name="p43013110113"></a><a name="p43013110113"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p03019111017"><a name="p03019111017"></a><a name="p03019111017"></a>vendor_hisilicon</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p4303114118"><a name="p4303114118"></a><a name="p4303114118"></a>New module</p>
</td>
</tr>
<tr id="row111481411211"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p11301411119"><a name="p11301411119"></a><a name="p11301411119"></a>vendor_hisi_hi35xx_hi3516dv300_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1330151111112"><a name="p1330151111112"></a><a name="p1330151111112"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p20304119111"><a name="p20304119111"></a><a name="p20304119111"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row714841112111"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p33014114112"><a name="p33014114112"></a><a name="p33014114112"></a>vendor_hisi_hi35xx_hi3518ev300_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p5303111218"><a name="p5303111218"></a><a name="p5303111218"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1230611911"><a name="p1230611911"></a><a name="p1230611911"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row614841113116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p530811415"><a name="p530811415"></a><a name="p530811415"></a>aafwk_interfaces_innerkits_abilitykit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p2030511717"><a name="p2030511717"></a><a name="p2030511717"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p93061110118"><a name="p93061110118"></a><a name="p93061110118"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row181482111119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p203191115119"><a name="p203191115119"></a><a name="p203191115119"></a>aafwk_interfaces_innerkits_intent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p831141113117"><a name="p831141113117"></a><a name="p831141113117"></a>aafwk_aafwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p3312112015"><a name="p3312112015"></a><a name="p3312112015"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row2147191115115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1331611912"><a name="p1331611912"></a><a name="p1331611912"></a>aafwk_interfaces_innerkits_abilitymgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1431111419"><a name="p1431111419"></a><a name="p1431111419"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p331911211"><a name="p331911211"></a><a name="p331911211"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1114718115118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p33191113118"><a name="p33191113118"></a><a name="p33191113118"></a>appexecfwk_kits_appkit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p631151110111"><a name="p631151110111"></a><a name="p631151110111"></a>appexecfwk_appexecfwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1312111915"><a name="p1312111915"></a><a name="p1312111915"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row161475111210"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p7311111417"><a name="p7311111417"></a><a name="p7311111417"></a>aafwk_frameworks_kits_ability_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4311711515"><a name="p4311711515"></a><a name="p4311711515"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p831171111119"><a name="p831171111119"></a><a name="p831171111119"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row14147411211"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p163241112114"><a name="p163241112114"></a><a name="p163241112114"></a>developtools_packing_tool</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p432151112116"><a name="p432151112116"></a><a name="p432151112116"></a>New module</p>
</td>
</tr>
<tr id="row4147191110114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p23217111112"><a name="p23217111112"></a><a name="p23217111112"></a>aafwk_interfaces_kits_ability_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p183215111713"><a name="p183215111713"></a><a name="p183215111713"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1323111015"><a name="p1323111015"></a><a name="p1323111015"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row16147121116119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1532141113116"><a name="p1532141113116"></a><a name="p1532141113116"></a>appexecfwk_frameworks_bundle_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p153216111015"><a name="p153216111015"></a><a name="p153216111015"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2323113117"><a name="p2323113117"></a><a name="p2323113117"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row914731112115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p632811312"><a name="p632811312"></a><a name="p632811312"></a>aafwk_services_abilitymgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p93218111018"><a name="p93218111018"></a><a name="p93218111018"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p163231112115"><a name="p163231112115"></a><a name="p163231112115"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1614741113117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p33321115113"><a name="p33321115113"></a><a name="p33321115113"></a>appexecfwk_interfaces_innerkits_appexecfwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p23313111314"><a name="p23313111314"></a><a name="p23313111314"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1933181110113"><a name="p1933181110113"></a><a name="p1933181110113"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row201471911116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p103316111314"><a name="p103316111314"></a><a name="p103316111314"></a>appexecfwk_interfaces_innerkits_bundlemgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p14339111417"><a name="p14339111417"></a><a name="p14339111417"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p193314114117"><a name="p193314114117"></a><a name="p193314114117"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row121474111718"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p93317112013"><a name="p93317112013"></a><a name="p93317112013"></a>appexecfwk_services_bundlemgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p0331211910"><a name="p0331211910"></a><a name="p0331211910"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p43318111120"><a name="p43318111120"></a><a name="p43318111120"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row61471111819"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p103361113118"><a name="p103361113118"></a><a name="p103361113118"></a>aafwk_frameworks_kits_content_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1133611212"><a name="p1133611212"></a><a name="p1133611212"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p123411115112"><a name="p123411115112"></a><a name="p123411115112"></a>Read-only archiving</p>
</td>
</tr>
</tbody>
</table>

## Resolved Issues<a name="section11935243172612"></a>

The following table lists the issues known in OpenHarmony 1.0, which have been resolved in this version.

**Table  4**  Resolved issues

<a name="table1934113413913"></a>
<table><thead align="left"><tr id="row4341334203914"><th class="cellrowborder" valign="top" width="22.650000000000002%" id="mcps1.2.3.1.1"><p id="p711564410397"><a name="p711564410397"></a><a name="p711564410397"></a>Issue</p>
</th>
<th class="cellrowborder" valign="top" width="77.35%" id="mcps1.2.3.1.2"><p id="p411564416397"><a name="p411564416397"></a><a name="p411564416397"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row934223410393"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p133271454113911"><a name="p133271454113911"></a><a name="p133271454113911"></a><a href="https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU" target="_blank" rel="noopener noreferrer">I3EALU</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p1132775483917"><a name="p1132775483917"></a><a name="p1132775483917"></a>[Multimedia] During execution of the cameraActs case, the camera configuration file cannot be found, and the initialization fails.</p>
</td>
</tr>
<tr id="row0342133417396"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p153278540395"><a name="p153278540395"></a><a name="p153278540395"></a><a href="https://gitee.com/openharmony/drivers_adapter_khdf_liteos/issues/I3D71U" target="_blank" rel="noopener noreferrer">I3D71U</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p93271254153915"><a name="p93271254153915"></a><a name="p93271254153915"></a>[Driver] When the system is reset repeatedly before it is started successfully by hmac_main_init, there is a high possibility that it would be suspended after the startup.</p>
</td>
</tr>
<tr id="row8342934173920"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p7328145410392"><a name="p7328145410392"></a><a name="p7328145410392"></a><a href="https://gitee.com/openharmony/community/issues/I3EGUX" target="_blank" rel="noopener noreferrer">I3EGUX</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p9328654193918"><a name="p9328654193918"></a><a name="p9328654193918"></a>[Reliability] When the system is reset repeatedly, and the KIdle process crashes once, the system is suspended and cannot be started.</p>
</td>
</tr>
<tr id="row034213453916"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p132875473912"><a name="p132875473912"></a><a name="p132875473912"></a><a href="https://gitee.com/openharmony/community/issues/I3DHIL" target="_blank" rel="noopener noreferrer">I3DHIL</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p17328105420391"><a name="p17328105420391"></a><a name="p17328105420391"></a>[System] The remaining space of the Hi3518 development board is insufficient, causing a failure in executing a large number of ACTS test cases.</p>
</td>
</tr>
</tbody>
</table>

