# OpenHarmony v2.2 Beta2<a name="EN-US_TOPIC_0000001182379069"></a>

## Version Description<a name="section1677664815431"></a>

This release provides new and enhanced features for the mini system, small system, and standard system based on OpenHarmony 2.0 Canary.

The feature updates for the standard system are as follows:

-   Added the distributed remote startup feature.
-   Added several sample apps and the drag-and-drop feature for basic system applications.
-   Added three media services for the media system.

The feature updates for the mini system and small system are as follows:

-   Added Linux version building for the small system.
-   Enhanced the lightweight kernel capabilities, including enhancements to the file system and kernel debugging tool, and support for configurable kernel modules, third-party chip adaptation, and ARM9 architecture.
-   Enhanced the lightweight graphics capabilities, including support for multi-language text alignment, component outline display, dot-matrix fonts, and multiple chip platforms for the unified backend framework.
-   Enhanced the design for X \(DFX\) capabilities, including enhanced HiLog and HiEvent features, a lightweight tool to dump system information, and the maintenance and test framework upon system restart.
-   Enhanced the AI capabilities, including Linux kernel adaptation and support for shared memory-based data transmission by the AI engine.

## Version Mapping<a name="section13201781528"></a>

**Table  1**  Version mapping of software and tools

<a name="table3398163217210"></a>
<table><thead align="left"><tr id="row1339820327212"><th class="cellrowborder" valign="top" width="28.622862286228624%" id="mcps1.2.4.1.1"><p id="p63988321828"><a name="p63988321828"></a><a name="p63988321828"></a>Software</p>
</th>
<th class="cellrowborder" valign="top" width="30.003000300030003%" id="mcps1.2.4.1.2"><p id="p7398133211216"><a name="p7398133211216"></a><a name="p7398133211216"></a>Version</p>
</th>
<th class="cellrowborder" valign="top" width="41.37413741374137%" id="mcps1.2.4.1.3"><p id="p1239913216212"><a name="p1239913216212"></a><a name="p1239913216212"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row113991632528"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p33994328215"><a name="p33994328215"></a><a name="p33994328215"></a>OpenHarmony</p>
</td>
<td class="cellrowborder" valign="top" width="30.003000300030003%" headers="mcps1.2.4.1.2 "><p id="p61561339133315"><a name="p61561339133315"></a><a name="p61561339133315"></a>2.2 Beta2</p>
</td>
<td class="cellrowborder" valign="top" width="41.37413741374137%" headers="mcps1.2.4.1.3 "><p id="p7316162554817"><a name="p7316162554817"></a><a name="p7316162554817"></a>N/A</p>
</td>
</tr>
<tr id="row239911321527"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p193286111669"><a name="p193286111669"></a><a name="p193286111669"></a>(Optional) HUAWEI DevEco Studio</p>
</td>
<td class="cellrowborder" valign="top" width="30.003000300030003%" headers="mcps1.2.4.1.2 "><p id="p83711419141513"><a name="p83711419141513"></a><a name="p83711419141513"></a>DevEco Studio 2.2 Beta1</p>
</td>
<td class="cellrowborder" valign="top" width="41.37413741374137%" headers="mcps1.2.4.1.3 "><p id="p12457193617153"><a name="p12457193617153"></a><a name="p12457193617153"></a>Recommended for developing OpenHarmony apps</p>
</td>
</tr>
<tr id="row153991032926"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p17708321495"><a name="p17708321495"></a><a name="p17708321495"></a>(Optional) HUAWEI DevEco Device Tool</p>
</td>
<td class="cellrowborder" valign="top" width="30.003000300030003%" headers="mcps1.2.4.1.2 "><p id="p145502371612"><a name="p145502371612"></a><a name="p145502371612"></a>Deveco DeviceTool 2.2 Beta1</p>
</td>
<td class="cellrowborder" valign="top" width="41.37413741374137%" headers="mcps1.2.4.1.3 "><p id="p1139765711198"><a name="p1139765711198"></a><a name="p1139765711198"></a>Recommended for developing OpenHarmony smart devices</p>
</td>
</tr>
</tbody>
</table>

## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**: Use the **repo** tool to download the source code over SSH. (You must have registered an SSH public key for access to Gitee.)

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v2.2-Beta2 --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v2.2-Beta2 --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table  2** Mirrors for acquiring source code

| Source&nbsp;Code | Version | Mirror | SHA-256&nbsp;Checksum | 
| -------- | -------- | -------- | -------- |
| Full&nbsp;code&nbsp;(for&nbsp;mini,&nbsp;small,&nbsp;and&nbsp;standard&nbsp;systems) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/code-v2.2-beta2_20210730.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/code-v2.2-beta2_20210730.tar.gz.sha256) | 
| Standard&nbsp;system&nbsp;solution&nbsp;(binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/standard-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/standard-2.2-Beta2.tar.gz.sha256) | 
| Hi3861&nbsp;solution&nbsp;(binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_pegasus-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_pegasus-2.2-Beta2.tar.gz.sha256) | 
| Hi3518&nbsp;solution&nbsp;(binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_aries-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_aries-2.2-Beta2.tar.gz.sha256) | 
| Hi3516&nbsp;solution-LiteOS&nbsp;(binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus-2.2-Beta2.tar.gz.sha256) | 
| Hi3516&nbsp;solution-Linux&nbsp;(binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus_linux-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus_linux-2.2-Beta2.tar.gz.sha256) | 
| Release&nbsp;Notes | 2.2 | [Download](https://gitee.com/openharmony/docs/blob/master/en/release-notes/OpenHarmony-v2.2-beta2.md) | - | 

## What's New<a name="section11256141314463"></a>

This release provides the following new and enhanced features based on OpenHarmony 2.0 Canary.

**Table  3**  New and enhanced features

<a name="table1976311913503"></a>
<table><thead align="left"><tr id="row127631916501"><th class="cellrowborder" valign="top" width="23.04%" id="mcps1.2.4.1.1"><p id="p6763997509"><a name="p6763997509"></a><a name="p6763997509"></a>Subsystem</p>
</th>
<th class="cellrowborder" valign="top" width="41.6%" id="mcps1.2.4.1.2"><p id="p1176418919506"><a name="p1176418919506"></a><a name="p1176418919506"></a>Standard System</p>
</th>
<th class="cellrowborder" valign="top" width="35.36%" id="mcps1.2.4.1.3"><p id="p05751656182510"><a name="p05751656182510"></a><a name="p05751656182510"></a>Mini and Small Systems</p>
</th>
</tr>
</thead>
<tbody><tr id="row12618619217"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p1626368217"><a name="p1626368217"></a><a name="p1626368217"></a>Distributed File</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p753217119019"><a name="p753217119019"></a><a name="p753217119019"></a>Provided JS APIs in the <strong id="b88836012312"><a name="b88836012312"></a><a name="b88836012312"></a>system.file</strong> class for asynchronous file operations, including file read/write, directory access, and directory addition/deletion.</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p1257515560253"><a name="p1257515560253"></a><a name="p1257515560253"></a>NA</p>
</td>
</tr>
<tr id="row1697324472115"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p19973154462114"><a name="p19973154462114"></a><a name="p19973154462114"></a>Driver</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p178202347481"><a name="p178202347481"></a><a name="p178202347481"></a><a href="https://gitee.com/openharmony/drivers_framework/issues/I3QE85" target="_blank" rel="noopener noreferrer">3QE85</a>: Added the audio, camera, USB, motor, and Analog to Digital Converter (ADC) driver models.</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p18438192992613"><a name="p18438192992613"></a><a name="p18438192992613"></a>Enabled LiteOS-M to support the Hardware Driver Foundation (HDF).</p>
</td>
</tr>
<tr id="row472717219225"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p147281129226"><a name="p147281129226"></a><a name="p147281129226"></a>Power Management</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p4668144017319"><a name="p4668144017319"></a><a name="p4668144017319"></a>Added the system power state machine, running lock, and sleep/wakeup features.</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul33391443142616"></a><a name="ul33391443142616"></a><ul id="ul33391443142616"><li>Added the APIs for querying the battery charging/discharging status and the battery level.</li><li>Added the support for the low-power mode with unified APIs.</li></ul>
</td>
</tr>
<tr id="row620911170236"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p162091917182319"><a name="p162091917182319"></a><a name="p162091917182319"></a>Update</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p18451433239"><a name="p18451433239"></a><a name="p18451433239"></a>Added the feature of restoring factory settings.</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p7576205613250"><a name="p7576205613250"></a><a name="p7576205613250"></a>NA</p>
</td>
</tr>
<tr id="row271213617373"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p716961115372"><a name="p716961115372"></a><a name="p716961115372"></a>Media</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><a name="ul108105123910"></a><a name="ul108105123910"></a><ul id="ul108105123910"><li>Added the audio service to provide basic audio control.</li><li>Added the camera service to provide basic functions such as preview and photographing.</li><li>Added the media service to support audio and video playback.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p8576165610250"><a name="p8576165610250"></a><a name="p8576165610250"></a>NA</p>
</td>
</tr>
<tr id="row776714945019"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p0767179135017"><a name="p0767179135017"></a><a name="p0767179135017"></a>JS UI Framework</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p1128414013613"><a name="p1128414013613"></a><a name="p1128414013613"></a>Added support for the hybrid use of both JS and C/C++ for JS API development.</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p45762056192514"><a name="p45762056192514"></a><a name="p45762056192514"></a>NA</p>
</td>
</tr>
<tr id="row188861132252"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p18866362511"><a name="p18866362511"></a><a name="p18866362511"></a>Event Notification</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p2024302141016"><a name="p2024302141016"></a><a name="p2024302141016"></a>Enabled applications to locally send and cancel a notification that includes multiple lines of text.</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p85761556122515"><a name="p85761556122515"></a><a name="p85761556122515"></a>NA</p>
</td>
</tr>
<tr id="row32413714262"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p424237152616"><a name="p424237152616"></a><a name="p424237152616"></a>DSoftBus</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p17236217843"><a name="p17236217843"></a><a name="p17236217843"></a>Added self-networking for DSoftBus. After a trusted device is connected to a LAN (either through Ethernet or Wi-Fi), the device can be automatically detected and connected to the DSoftBus. The device is not aware of this connection.</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p1857675611252"><a name="p1857675611252"></a><a name="p1857675611252"></a>NA</p>
</td>
</tr>
<tr id="row6307237105110"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p24971139185111"><a name="p24971139185111"></a><a name="p24971139185111"></a>Distributed Data Management</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><a name="ul1411113817529"></a><a name="ul1411113817529"></a><ul id="ul1411113817529"><li>Added distributed data management to support locally encrypted storage of distributed databases.</li><li>Added support for lightweight preferences databases.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul59217181020"></a><a name="ul59217181020"></a><ul id="ul59217181020"><li>Implemented data deletion from databases.</li><li>Added unified functions to operate the Hardware Abstraction Layer (HAL) file system.</li><li>Implemented atomic operations related to data storage.</li><li>Implemented read/write of binary values.</li></ul>
</td>
</tr>
<tr id="row161918529268"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p066763616286"><a name="p066763616286"></a><a name="p066763616286"></a>System Apps</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p1490153195610"><a name="p1490153195610"></a><a name="p1490153195610"></a>Home screen:</p>
<a name="ul16239155595614"></a><a name="ul16239155595614"></a><ul id="ul16239155595614"><li>Optimized UX for the home screen setting page.</li><li>Added support for icon dragging on the home screen.</li></ul>
<p id="p20905319564"><a name="p20905319564"></a><a name="p20905319564"></a>Settings:</p>
<a name="ul245041017582"></a><a name="ul245041017582"></a><ul id="ul245041017582"><li>Added WLAN settings.</li></ul>
<p id="p1090143112566"><a name="p1090143112566"></a><a name="p1090143112566"></a>SystemUI:</p>
<a name="ul1027287584"></a><a name="ul1027287584"></a><ul id="ul1027287584"><li>Implemented the display of the signal icon of SIM cards.</li></ul>
<p id="p14903318562"><a name="p14903318562"></a><a name="p14903318562"></a>Photos:</p>
<a name="ul172792055205811"></a><a name="ul172792055205811"></a><ul id="ul172792055205811"><li>Added the features of viewing, moving, copying, deleting, and renaming images and videos.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p6576125602513"><a name="p6576125602513"></a><a name="p6576125602513"></a>NA</p>
</td>
</tr>
<tr id="row377318915507"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p777349105012"><a name="p777349105012"></a><a name="p777349105012"></a>Globalization</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><a name="ul18119906123"></a><a name="ul18119906123"></a><ul id="ul18119906123"><li>Optimized time and date formatting.</li><li>Added support for time segment formatting.</li><li>Added support for number formatting.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul33981411321"></a><a name="ul33981411321"></a><ul id="ul33981411321"><li>Added custom data compilation.</li><li>Added internationalization for the week, singular and plural forms, and numbers.</li><li>Added the mechanism for parsing and loading build resources.</li><li>Added the build resource backtracking mechanism.</li></ul>
</td>
</tr>
<tr id="row20979141410276"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p129791114102719"><a name="p129791114102719"></a><a name="p129791114102719"></a>Sample Apps</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><a name="ul3397818122718"></a><a name="ul3397818122718"></a><ul id="ul3397818122718"><li>Added the distributed calculator feature, which allows the calculator on one device to start the calculator on another networked device to perform collaborative calculation and synchronize the calculation data in real time.</li><li>Added the audio player app that supports audio playback on any networked devices.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p0576125692520"><a name="p0576125692520"></a><a name="p0576125692520"></a>NA</p>
</td>
</tr>
<tr id="row1474114139329"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p6741131317321"><a name="p6741131317321"></a><a name="p6741131317321"></a>Distributed Device Management</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p143617933314"><a name="p143617933314"></a><a name="p143617933314"></a>Added the device management system service that provides authentication and networking irrelevant to distributed device accounts.</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p264113419105"><a name="p264113419105"></a><a name="p264113419105"></a>NA</p>
</td>
</tr>
<tr id="row832191324615"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p3331113194616"><a name="p3331113194616"></a><a name="p3331113194616"></a>DFX</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p47911168336"><a name="p47911168336"></a><a name="p47911168336"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul1469920194511"></a><a name="ul1469920194511"></a><ul id="ul1469920194511"><li>Provided a tool to dump LiteOS kernel information.</li><li>Implemented a maintenance and test framework for the LiteOS kernel upon restarting after a breakdown.</li><li>Added number formatting.</li><li>Enhanced HiLog.</li><li>Enhanced HiEvent.</li></ul>
</td>
</tr>
<tr id="row1336310497544"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p173649490544"><a name="p173649490544"></a><a name="p173649490544"></a>Kernel</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p1300552183317"><a name="p1300552183317"></a><a name="p1300552183317"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul191101631555"></a><a name="ul191101631555"></a><ul id="ul191101631555"><li>Added support for the lightweight Linux version.</li><li>Enhanced support for the proc file system.</li><li>Added the mksh command interpreter.</li><li>Enhanced file system maintenance and testing.</li><li>Added support for configuration of LiteOS-A kernel modules.</li><li>Enabled the LiteOS-A small system to adapt to third-party chips.</li><li>Enabled LiteOS-M to support Mbed TLS compilation of third-party components.</li><li>Enabled LiteOS-M to support Curl compilation of third-party components.</li><li>Added support for the lightweight shell framework and common debugging commands.</li><li>Enabled LiteOS-M to support the ARM9 architecture.</li><li>Added support for the little file system (LittleFS) setup on the NOR flash.</li><li>Enabled LiteOS-M to provide unified file system operation APIs for external systems.</li><li>Added the Namecache, Vnode, and Lookup modules.</li></ul>
</td>
</tr>
<tr id="row192410715819"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p32567175813"><a name="p32567175813"></a><a name="p32567175813"></a>Graphics</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p182587563419"><a name="p182587563419"></a><a name="p182587563419"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul1742414363415"></a><a name="ul1742414363415"></a><ul id="ul1742414363415"><li>Added support for input of A4, A8, LUT8, and TSC images.</li><li>Added support for multi-language text alignment.</li><li>Added component outline display for UIKit.</li><li>Enabled the <strong id="b16643105116133"><a name="b16643105116133"></a><a name="b16643105116133"></a>ScrollView</strong> or <strong id="b1311513553137"><a name="b1311513553137"></a><a name="b1311513553137"></a>List</strong> component to display the swiping progress using an arc progress bar.</li><li>Implemented animation for the switch, check box, and radio button.</li><li>Enabled UIKit to support the decoupling of dot-matrix fonts from products.</li><li>Provided a unified multi-backend framework to support multiple chip platforms.</li><li>Enabled UIKit to support margin and padding.</li><li>Implemented zoom and white layer animations for the round and capsule buttons.</li></ul>
</td>
</tr>
<tr id="row115211202598"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p11531320165912"><a name="p11531320165912"></a><a name="p11531320165912"></a>Compilation and Building</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p2071212873418"><a name="p2071212873418"></a><a name="p2071212873418"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p1920101163411"><a name="p1920101163411"></a><a name="p1920101163411"></a>Added support for the general patch framework of open-source software.</p>
</td>
</tr>
<tr id="row63749231472"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p83746237713"><a name="p83746237713"></a><a name="p83746237713"></a>Startup</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p1261941520343"><a name="p1261941520343"></a><a name="p1261941520343"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p11807317133420"><a name="p11807317133420"></a><a name="p11807317133420"></a>Added support for factory setting restoration and multi-language text alignment.</p>
</td>
</tr>
<tr id="row1225911481986"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p1926017488814"><a name="p1926017488814"></a><a name="p1926017488814"></a>Distributed Scheduler</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p19901119123410"><a name="p19901119123410"></a><a name="p19901119123410"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><p id="p172611227345"><a name="p172611227345"></a><a name="p172611227345"></a>Added support for the start of an ability on the rich device from a mini-system device.</p>
</td>
</tr>
<tr id="row1167365771317"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.2.4.1.1 "><p id="p0674357171314"><a name="p0674357171314"></a><a name="p0674357171314"></a>AI</p>
</td>
<td class="cellrowborder" valign="top" width="41.6%" headers="mcps1.2.4.1.2 "><p id="p8313182513345"><a name="p8313182513345"></a><a name="p8313182513345"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="35.36%" headers="mcps1.2.4.1.3 "><a name="ul16276418181411"></a><a name="ul16276418181411"></a><ul id="ul16276418181411"><li>Added support for Linux kernel adaptation with related compilation options.</li><li>Enabled shared memory-based data transmission.</li></ul>
</td>
</tr>
</tbody>
</table>

### API Updates

For details, see:

-   [JS API Differences](api-change/v2.2-beta2/js-apidiff-v2.2-beta2.md)

-   [Native API Differences](api-change/v2.2-beta2/native-apidiff-v2.2-beta2.md)

## Resolved Issues<a name="section3442123281619"></a>

**Table  4** **Resolved issues**

<a name="table158451039191811"></a>
<table><thead align="left"><tr id="row178461539111814"><th class="cellrowborder" valign="top" width="13.15%" id="mcps1.2.3.1.1"><p id="p4846113915184"><a name="p4846113915184"></a><a name="p4846113915184"></a>Issue No.</p>
</th>
<th class="cellrowborder" valign="top" width="86.85000000000001%" id="mcps1.2.3.1.2"><p id="p4846039111815"><a name="p4846039111815"></a><a name="p4846039111815"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8846163911187"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p18127341171919"><a name="p18127341171919"></a><a name="p18127341171919"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3I31W" target="_blank" rel="noopener noreferrer">I3I31W</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p01271941121913"><a name="p01271941121913"></a><a name="p01271941121913"></a><strong id="b102791322122913"><a name="b102791322122913"></a><a name="b102791322122913"></a>ActsNFSTest.bin</strong> causes a kernel crash.</p>
</td>
</tr>
<tr id="row1846113981818"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p14127174118199"><a name="p14127174118199"></a><a name="p14127174118199"></a><a href="https://gitee.com/openharmony/docs/issues/I3D49E" target="_blank" rel="noopener noreferrer">I3D49E</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p141271541131915"><a name="p141271541131915"></a><a name="p141271541131915"></a>The U-Boot path is incorrect.</p>
</td>
</tr>
<tr id="row5846103901815"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p181274412195"><a name="p181274412195"></a><a name="p181274412195"></a><a href="https://gitee.com/openharmony-retired/drivers_adapter_khdf_liteos/issues/I3D71U" target="_blank" rel="noopener noreferrer">I3D71U</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p131271341151912"><a name="p131271341151912"></a><a name="p131271341151912"></a>[Driver subsystem] During repeated system reset, there is a high possibility that the system is suspended after successful <strong id="b6105185413215"><a name="b6105185413215"></a><a name="b6105185413215"></a>hmac_main_init</strong> startup.</p>
</td>
</tr>
<tr id="row48467394184"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p812718412194"><a name="p812718412194"></a><a name="p812718412194"></a><a href="https://gitee.com/openharmony/aafwk_aafwk_lite/issues/I3DGZW" target="_blank" rel="noopener noreferrer">I3DGZW</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p3127164121913"><a name="p3127164121913"></a><a name="p3127164121913"></a>[Application Framework subsystem] After the Hi3516 development board enters screen saver mode, a blue screen is displayed upon a tap on the touchscreen.</p>
</td>
</tr>
<tr id="row984633901815"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1912812411199"><a name="p1912812411199"></a><a name="p1912812411199"></a><a href="https://gitee.com/openharmony/community/issues/I3DHIL" target="_blank" rel="noopener noreferrer">I3DHIL</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1412854111192"><a name="p1412854111192"></a><a name="p1412854111192"></a>[System] The remaining space of the Hi3518 development board is insufficient, causing a failure in executing a large number of ACTS test cases.</p>
</td>
</tr>
<tr id="row984623913181"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1128184171917"><a name="p1128184171917"></a><a name="p1128184171917"></a><a href="https://gitee.com/openharmony/appexecfwk_appexecfwk_lite/issues/I3DU36" target="_blank" rel="noopener noreferrer">I3DU36</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p17128104114191"><a name="p17128104114191"></a><a name="p17128104114191"></a>[Application Framework subsystem] The query command <strong id="b89711053112415"><a name="b89711053112415"></a><a name="b89711053112415"></a>ipcamera bm</strong> does not take effect.</p>
</td>
</tr>
<tr id="row4846193919186"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p16128174171917"><a name="p16128174171917"></a><a name="p16128174171917"></a><a href="https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU" target="_blank" rel="noopener noreferrer">I3EALU</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p8128184191914"><a name="p8128184191914"></a><a name="p8128184191914"></a>[Media subsystem] During the execution of the <strong id="b18542141872318"><a name="b18542141872318"></a><a name="b18542141872318"></a>cameraActs</strong> test case, the camera configuration file cannot be found and the initialization fails.</p>
</td>
</tr>
<tr id="row851624131915"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1412814111917"><a name="p1412814111917"></a><a name="p1412814111917"></a><a href="https://gitee.com/openharmony/release-management/issues/I3EGUX" target="_blank" rel="noopener noreferrer">I3EGUX</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p161282419194"><a name="p161282419194"></a><a name="p161282419194"></a>[Reliability] When the KIdle process crashes once during repeated system reset, the system is suspended and cannot be started.</p>
</td>
</tr>
<tr id="row1151162411915"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p181280416199"><a name="p181280416199"></a><a name="p181280416199"></a><a href="https://gitee.com/openharmony/community/issues/I3EH4E" target="_blank" rel="noopener noreferrer">I3EH4E</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p2128841121919"><a name="p2128841121919"></a><a name="p2128841121919"></a>[Pipeline] There is a high probability that the system does not respond after the <strong id="b138341354112016"><a name="b138341354112016"></a><a name="b138341354112016"></a>uname</strong> and <strong id="b05351314112113"><a name="b05351314112113"></a><a name="b05351314112113"></a>reset</strong> commands are executed.</p>
</td>
</tr>
<tr id="row051182419198"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p20128204114190"><a name="p20128204114190"></a><a name="p20128204114190"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3EQJA" target="_blank" rel="noopener noreferrer">I3EQJA</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1112813418191"><a name="p1112813418191"></a><a name="p1112813418191"></a>[File system] The <strong id="b13680836111015"><a name="b13680836111015"></a><a name="b13680836111015"></a>cat /proc/mounts</strong> command does not take effect.</p>
</td>
</tr>
<tr id="row451132491912"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1012844171912"><a name="p1012844171912"></a><a name="p1012844171912"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3EQRC" target="_blank" rel="noopener noreferrer">I3EQRC</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1612884110194"><a name="p1612884110194"></a><a name="p1612884110194"></a>The system crashes when three concurrent test processes are run during disk file mapping delay testing.</p>
</td>
</tr>
<tr id="row551124141912"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1212854112194"><a name="p1212854112194"></a><a name="p1212854112194"></a></a><a href="https://gitee.com/openharmony/docs/issues/I3HVL0" target="_blank" rel="noopener noreferrer">I3HVL0</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p2128241151910"><a name="p2128241151910"></a><a name="p2128241151910"></a>The Hi3861 development board compilation fails and the error message "[OHOS ERROR] Fatal error: invalid -march= option:rv32imac" is displayed.</p>
</td>
</tr>
<tr id="row2065132419197"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p1767317453201"><a name="p1767317453201"></a><a name="p1767317453201"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3TS1Y" target="_blank" rel="noopener noreferrer">I3TS1Y</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1667354518204"><a name="p1667354518204"></a><a name="p1667354518204"></a>File-specific Vnode resources are exhausted in stress testing.</p>
</td>
</tr>
<tr id="row1269122413190"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p13674845202014"><a name="p13674845202014"></a><a name="p13674845202014"></a><a href="https://gitee.com/openharmony/startup_init_lite/issues/I3TXT8" target="_blank" rel="noopener noreferrer">I3TXT8</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p1267414592020"><a name="p1267414592020"></a><a name="p1267414592020"></a>Orphan processes cannot be reclaimed, and TCB resources are exhausted in stress testing.</p>
</td>
</tr>
<tr id="row1233105621912"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p176741745112010"><a name="p176741745112010"></a><a name="p176741745112010"></a><a href="https://gitee.com/openharmony/applications_sample_wifi_iot/issues/I3UWXI" target="_blank" rel="noopener noreferrer">I3UWXI</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p56742457209"><a name="p56742457209"></a><a name="p56742457209"></a>The <strong id="b12822201841520"><a name="b12822201841520"></a><a name="b12822201841520"></a>libwap.so</strong> file is prone to the following vulnerability: CVE-2021-30004, CVSS: 5.3, released on 2021-04-02.</p>
</td>
</tr>
<tr id="row1723765610198"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p166741945122011"><a name="p166741945122011"></a><a name="p166741945122011"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3SWY2" target="_blank" rel="noopener noreferrer">I3SWY2</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p96741945132014"><a name="p96741945132014"></a><a name="p96741945132014"></a>There is a high probability that the KProcess is suspended.</p>
</td>
</tr>
<tr id="row1359138112017"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p156744454206"><a name="p156744454206"></a><a name="p156744454206"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I3YJRO" target="_blank" rel="noopener noreferrer">I3YJRO</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p2067419456205"><a name="p2067419456205"></a><a name="p2067419456205"></a>The compilation of configurable LiteOS-A kernel modules fails.</p>
</td>
</tr>
<tr id="row1635963862010"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p11674245202010"><a name="p11674245202010"></a><a name="p11674245202010"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3YNWM" target="_blank" rel="noopener noreferrer">I3YNWM</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p136742452208"><a name="p136742452208"></a><a name="p136742452208"></a>The enhanced file system maintenance and test feature is defective.</p>
</td>
</tr>
<tr id="row8360183892010"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.2.3.1.1 "><p id="p6674154522014"><a name="p6674154522014"></a><a name="p6674154522014"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3VEOG" target="_blank" rel="noopener noreferrer">I3VEOG</a></p>
</td>
<td class="cellrowborder" valign="top" width="86.85000000000001%" headers="mcps1.2.3.1.2 "><p id="p156747457204"><a name="p156747457204"></a><a name="p156747457204"></a>The <strong id="b20744135541017"><a name="b20744135541017"></a><a name="b20744135541017"></a>bin</strong> directory does not contain the <strong id="b73096151112"><a name="b73096151112"></a><a name="b73096151112"></a>mksh</strong> and <strong id="b3797123191113"><a name="b3797123191113"></a><a name="b3797123191113"></a>toybox</strong> commands, leading to a failure to test the <strong id="b58221324111118"><a name="b58221324111118"></a><a name="b58221324111118"></a>toybox</strong> command set.</p>
</td>
</tr>
</tbody>
</table>

