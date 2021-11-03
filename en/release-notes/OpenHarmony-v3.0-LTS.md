# OpenHarmony 3.0 LTS<a name="EN-US_TOPIC_0000001206934917"></a>

-   [Version Description](#section672305419147)
-   [Version Mapping](#section1736016220124)
-   [Source Code Acquisition](#section17116307121)
-   [What's New](#section16315133431213)
    -   [Feature Updates](#section14825161544419)
    -   [API Updates](#section10338601455)
    -   [Chip and Development Board Adaptation](#section16410114834516)

-   [Resolved Issues](#section622710385121)

## Version Description<a name="section672305419147"></a>

This version has updates for the standard system, mini system, and small system on the basis of OpenHarmony 2.2 Beta2.

The feature updates for the standard system are as follows:

-   The application framework supports the Service ability, Data ability, and thread model.
-   Secure file access is supported, which means that a file object can be converted into a URI and a URI can be parsed to open a file.
-   PIN authentication is supported for the distributed device management service.
-   Relational databases and distributed data management are supported.
-   The ARK JS compiler toolchain and runtime are supported, and the OpenHarmony JS UI framework application development and running are also supported.
-   Remote binding of a Service ability and cross-device FA migration are supported.
-   Application pub/sub and redirection of application notifications are supported.
-   The input method framework is supported, and basic English letters, special characters, and digits can be entered.
-   The camera module supports preview, photographing, and video recording.
-   The CS basic call and GSM SMS capabilities are supported.
-   The timer capability and the scheduled time zone management capability are supported.
-   In the distributed networking of standard-system devices, permission verification is provided for applications to access peer-end resources or capabilities.

The feature updates for the mini and small systems are as follows:

-   The lightweight distributed capability is enhanced so that the ability on a standard-system device can be started from a mini-system device.
-   The DSoftBus capability is enhanced to support transmission of authentication channels for device binding.
-   The lightweight globalization capability is enhanced to support 31 more languages.
-   The permission attribute field and its write interface are added for the mini system. Upper-layer applications can use this field to implement related services.

## Version Mapping<a name="section1736016220124"></a>

**Table  1**  Version mapping of software and tools

<a name="table07701628141714"></a>
<table><thead align="left"><tr id="row1577132818177"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p63988321828"><a name="p63988321828"></a><a name="p63988321828"></a>Software</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p7398133211216"><a name="p7398133211216"></a><a name="p7398133211216"></a>Version</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1239913216212"><a name="p1239913216212"></a><a name="p1239913216212"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row377102811716"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p33994328215"><a name="p33994328215"></a><a name="p33994328215"></a>OpenHarmony</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p61561339133315"><a name="p61561339133315"></a><a name="p61561339133315"></a>3.0 LTS</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7316162554817"><a name="p7316162554817"></a><a name="p7316162554817"></a>N/A</p>
</td>
</tr>
<tr id="row177711128151719"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p193286111669"><a name="p193286111669"></a><a name="p193286111669"></a>(Optional) HUAWEI DevEco Studio</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p83711419141513"><a name="p83711419141513"></a><a name="p83711419141513"></a>3.0 Beta1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p12457193617153"><a name="p12457193617153"></a><a name="p12457193617153"></a>Recommended for developing OpenHarmony applications</p>
</td>
</tr>
<tr id="row77441334132012"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17708321495"><a name="p17708321495"></a><a name="p17708321495"></a>(Optional) HUAWEI DevEco Device Tool</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p145502371612"><a name="p145502371612"></a><a name="p145502371612"></a>2.2 Beta2</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1139765711198"><a name="p1139765711198"></a><a name="p1139765711198"></a>Recommended for developing OpenHarmony smart devices</p>
</td>
</tr>
</tbody>
</table>

## Source Code Acquisition<a name="section17116307121"></a>

**Method 1 \(recommended\)**

Use the  **repo**  tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the  **repo**  tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## What's New<a name="section16315133431213"></a>

This version has the following updates to OpenHarmony 2.2 Beta2.

### Feature Updates<a name="section14825161544419"></a>

**Table  2**  New and enhanced features

<a name="table1245216262111"></a>
<table><thead align="left"><tr id="row1345212220213"><th class="cellrowborder" valign="top" width="16.5016501650165%" id="mcps1.2.4.1.1"><p id="p6763997509"><a name="p6763997509"></a><a name="p6763997509"></a>Subsystem</p>
</th>
<th class="cellrowborder" valign="top" width="50.16501650165017%" id="mcps1.2.4.1.2"><p id="p1176418919506"><a name="p1176418919506"></a><a name="p1176418919506"></a>Standard System</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p05751656182510"><a name="p05751656182510"></a><a name="p05751656182510"></a>Mini and Small Systems</p>
</th>
</tr>
</thead>
<tbody><tr id="row204521922216"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p1345210282116"><a name="p1345210282116"></a><a name="p1345210282116"></a>Distributed Scheduler</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul1853112675717"></a><a name="ul1853112675717"></a><ul id="ul1853112675717"><li>Remote Service ability binding is supported.</li><li>Cross-device FA migration is supported.</li><li>Permission verification is added for the <strong id="b18393929153216"><a name="b18393929153216"></a><a name="b18393929153216"></a>visible</strong> attribute of a component.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p182791322171519"><a name="p182791322171519"></a><a name="p182791322171519"></a>The ability on a standard-system device can be started from a mini-system device.</p>
</td>
</tr>
<tr id="row134521421215"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p445222182116"><a name="p445222182116"></a><a name="p445222182116"></a>Graphics</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><p id="p13452182112114"><a name="p13452182112114"></a><a name="p13452182112114"></a>For chip platforms with GPU modules, GPUs can be used for rendering and composition to improve graphics performance and reduce CPU load.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p10452172202111"><a name="p10452172202111"></a><a name="p10452172202111"></a>N/A</p>
</td>
</tr>
<tr id="row178911828125610"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p7891728115620"><a name="p7891728115620"></a><a name="p7891728115620"></a>Distributed Hardware</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul338236132519"></a><a name="ul338236132519"></a><ul id="ul338236132519"><li>The formal PIN authentication scheme based on DSoftBus authentication channels is supported.</li><li>A pop-up window is displayed for PIN authentication.</li><li>A pop-up window is displayed to show a PIN.</li><li>A pop-up window is displayed for the user to enter a PIN.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p128921028175615"><a name="p128921028175615"></a><a name="p128921028175615"></a>N/A</p>
</td>
</tr>
<tr id="row039911442569"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p103995446567"><a name="p103995446567"></a><a name="p103995446567"></a>Event Notification</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul23738200572"></a><a name="ul23738200572"></a><ul id="ul23738200572"><li>Application notification subscription and unsubscription are supported.</li><li>Local text and picture-attached notifications can be published or canceled on the application side.</li><li>Application notification redirection is supported.</li><li>Notification slots can be added or removed on the application side.</li><li>Notification flow control and death monitor are supported.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1439964445616"><a name="p1439964445616"></a><a name="p1439964445616"></a>N/A</p>
</td>
</tr>
<tr id="row9868104825620"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p88684484568"><a name="p88684484568"></a><a name="p88684484568"></a>DSoftBus</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul133051157577"></a><a name="ul133051157577"></a><ul id="ul133051157577"><li>CoAP-based active discovery and passive discovery are supported, and active discovery and connection through BLE are supported.</li><li>WLAN-based manual network access and self-networking are supported.</li><li>WLAN-based message, byte, and file transfer is supported.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><a name="ul587883019579"></a><a name="ul587883019579"></a><ul id="ul587883019579"><li>CoAP-based active discovery and passive discovery are supported.</li><li>WLAN-based manual network access and self-networking are supported.</li><li>WLAN-based message, byte, and file transfer is supported.</li></ul>
</td>
</tr>
<tr id="row46631532105615"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p1766313217563"><a name="p1766313217563"></a><a name="p1766313217563"></a>Globalization</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><p id="p7286510163012"><a name="p7286510163012"></a><a name="p7286510163012"></a>The capability of obtaining the language, region, and locale information configured in the system and obtaining the localized names of the language and region.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1566343215563"><a name="p1566343215563"></a><a name="p1566343215563"></a>The lightweight globalization capability is enhanced to support 31 more languages.</p>
</td>
</tr>
<tr id="row947420448184"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p44741844131811"><a name="p44741844131811"></a><a name="p44741844131811"></a>System Applications</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><p id="p243373311194"><a name="p243373311194"></a><a name="p243373311194"></a>Home Screen:</p>
<a name="ul19419182845817"></a><a name="ul19419182845817"></a><ul id="ul19419182845817"><li>A new architecture is introduced.</li></ul>
<p id="p2433103313191"><a name="p2433103313191"></a><a name="p2433103313191"></a>SystemUI:</p>
<a name="ul230123375812"></a><a name="ul230123375812"></a><ul id="ul230123375812"><li>Notification center and common text notification are optimized.</li><li>WLAN, airplane mode, brightness adjustment, and volume adjustment in the Control Panel are optimized.</li><li>A new architecture is introduced.</li></ul>
<p id="p184337336191"><a name="p184337336191"></a><a name="p184337336191"></a>Settings:</p>
<a name="ul16511936195812"></a><a name="ul16511936195812"></a><ul id="ul16511936195812"><li>A new architecture is introduced.</li></ul>
<p id="p1343316338196"><a name="p1343316338196"></a><a name="p1343316338196"></a>Camera:</p>
<a name="ul647017398585"></a><a name="ul647017398585"></a><ul id="ul647017398585"><li>Photographing and video recording are supported.</li><li>Distributed collaboration: Users can now start the peer camera to take photos.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p94741044131820"><a name="p94741044131820"></a><a name="p94741044131820"></a>N/A</p>
</td>
</tr>
<tr id="row97067412181"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p1970614431819"><a name="p1970614431819"></a><a name="p1970614431819"></a>Programming Language Runtime</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><p id="p177069414187"><a name="p177069414187"></a><a name="p177069414187"></a>The ARK JS compiler toolchain and runtime are added, and the OpenHarmony JS UI framework application development and running are also supported.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p13706343187"><a name="p13706343187"></a><a name="p13706343187"></a>N/A</p>
</td>
</tr>
<tr id="row12245042141811"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p1924504210184"><a name="p1924504210184"></a><a name="p1924504210184"></a>Media</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul58647361607"></a><a name="ul58647361607"></a><ul id="ul58647361607"><li>The video recording function is added to the camera module.</li><li>The audio recording API is added.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p152451142141817"><a name="p152451142141817"></a><a name="p152451142141817"></a>MP3 files can be played.</p>
</td>
</tr>
<tr id="row108061739151817"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p16510154306"><a name="p16510154306"></a><a name="p16510154306"></a>JS UI Framework</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul517013575587"></a><a name="ul517013575587"></a><ul id="ul517013575587"><li>Migration-related lifecycle management is supported.</li><li>Pop-up windows are added for system services.</li><li>JS can be used to develop Service and Data abilities.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p280612391183"><a name="p280612391183"></a><a name="p280612391183"></a>N/A</p>
</td>
</tr>
<tr id="row483817378184"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p383816375182"><a name="p383816375182"></a><a name="p383816375182"></a>Kernel</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><p id="p110521762320"><a name="p110521762320"></a><a name="p110521762320"></a>OpenHarmony Common Linux Kernel 5.10 is supported.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p28381437131819"><a name="p28381437131819"></a><a name="p28381437131819"></a>OpenHarmony Common Linux Kernel 5.10 is supported for the mini system.</p>
</td>
</tr>
<tr id="row0748113519189"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p1774893501813"><a name="p1774893501813"></a><a name="p1774893501813"></a>DFX</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul63201038598"></a><a name="ul63201038598"></a><ul id="ul63201038598"><li>JS APIs are added for HiAppEvent event logging.</li><li>The HiCollie suspension detection framework is provided.</li><li>The HiTrace distributed call chain basic library is provided.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1974823513185"><a name="p1974823513185"></a><a name="p1974823513185"></a>N/A</p>
</td>
</tr>
<tr id="row340107101910"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p18408711190"><a name="p18408711190"></a><a name="p18408711190"></a>Driver</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><p id="p440474196"><a name="p440474196"></a><a name="p440474196"></a>The I2S, gyroscope, pressure, and Hall driver models are added.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7405716196"><a name="p7405716196"></a><a name="p7405716196"></a>N/A</p>
</td>
</tr>
<tr id="row104885541915"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p184891581915"><a name="p184891581915"></a><a name="p184891581915"></a>Security</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><p id="p1748919517196"><a name="p1748919517196"></a><a name="p1748919517196"></a>In the distributed networking of standard-system devices, permission verification is provided for applications to access peer-end resources or capabilities.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p104891059198"><a name="p104891059198"></a><a name="p104891059198"></a>The permission attribute field and its write interface are added for the mini system. Upper-layer applications can use this field to implement related services. (When a pop-up window is used to request authorization, no dialog box is displayed after the user rejects the authorization.)</p>
</td>
</tr>
<tr id="row3328431192"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p2328123171910"><a name="p2328123171910"></a><a name="p2328123171910"></a>Telephony Service</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul20269131055912"></a><a name="ul20269131055912"></a><ul id="ul20269131055912"><li>Network search module: supports airplane mode setting, network search mode setting (manual and automatic network search), and LTE signal strength retrieval.</li><li>SIM module: supports PIN/PUK unlocking, SIM card file information retrieval, card account information storage and retrieval, and card status retrieval.</li><li>Cellular call module: supports foreground/background switchover, incoming call muting, call holding and resuming, three-party call, and DTMF.</li><li>SMS and MMS modules: support addition, deletion, modification, and query of SMS and MMS messages on the SIM card.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p73291381910"><a name="p73291381910"></a><a name="p73291381910"></a>N/A</p>
</td>
</tr>
<tr id="row731019011916"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p3310180131916"><a name="p3310180131916"></a><a name="p3310180131916"></a>Distributed File</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul1771117214112"></a><a name="ul1771117214112"></a><ul id="ul1771117214112"><li>Mounting of partitions with different parameter settings is supported for the F2FS and EXT4 file systems.</li><li>Secure file access is supported, which means that a file object can be converted into a URI and a URI can be parsed to open a file.</li><li>System applications can now access public directories.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p231012011913"><a name="p231012011913"></a><a name="p231012011913"></a>N/A</p>
</td>
</tr>
<tr id="row103717585182"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p8371458101812"><a name="p8371458101812"></a><a name="p8371458101812"></a>Distributed Data Management</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul292119281430"></a><a name="ul292119281430"></a><ul id="ul292119281430"><li>Basic JS capabilities (such as adding, deleting, modifying, and querying) are added for relational databases.</li><li>Basic JS capabilities (such as adding, deleting, modifying, and querying) are added for distributed data management.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p73718587187"><a name="p73718587187"></a><a name="p73718587187"></a>N/A</p>
</td>
</tr>
<tr id="row17701155315183"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p57011153171817"><a name="p57011153171817"></a><a name="p57011153171817"></a>Compilation and Building</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul139401635135919"></a><a name="ul139401635135919"></a><ul id="ul139401635135919"><li>Compilation of ARM64 products is supported.</li><li>Compilation of ohos-sdk is supported.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1470105381818"><a name="p1470105381818"></a><a name="p1470105381818"></a>N/A</p>
</td>
</tr>
<tr id="row1199455518187"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p599565514187"><a name="p599565514187"></a><a name="p599565514187"></a>Application Framework</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><a name="ul20633124421"></a><a name="ul20633124421"></a><ul id="ul20633124421"><li>JS based Service ability development is supported.</li><li>JS based Data ability development is supported.</li><li>The HAP supports multiple ability statements.</li><li>Ability migration to a remote device is supported.</li><li>The application task stack can be saved and restored.</li><li>JS can now use ZIP Library to compress and decompress files.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p149951755161813"><a name="p149951755161813"></a><a name="p149951755161813"></a>N/A</p>
</td>
</tr>
<tr id="row9405135525511"><td class="cellrowborder" valign="top" width="16.5016501650165%" headers="mcps1.2.4.1.1 "><p id="p164052055205512"><a name="p164052055205512"></a><a name="p164052055205512"></a>Misc Services</p>
</td>
<td class="cellrowborder" valign="top" width="50.16501650165017%" headers="mcps1.2.4.1.2 "><p id="p194051755155510"><a name="p194051755155510"></a><a name="p194051755155510"></a>The timer capability and the scheduled time zone management capability are supported.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p134058551559"><a name="p134058551559"></a><a name="p134058551559"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

### API Updates<a name="section10338601455"></a>

For details, see JS API Differences.

### Chip and Development Board Adaptation<a name="section16410114834516"></a>

For details about the adaptation status, see  [SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig-devboard/sig_devboard.md).

## Resolved Issues<a name="section622710385121"></a>

**Table  3**  Issues resolved for mini and small systems

<a name="table1957725018219"></a>
<table><thead align="left"><tr id="row14578185032111"><th class="cellrowborder" valign="top" width="17.37%" id="mcps1.2.3.1.1"><p id="p4846113915184"><a name="p4846113915184"></a><a name="p4846113915184"></a>Issue No.</p>
</th>
<th class="cellrowborder" valign="top" width="82.63000000000001%" id="mcps1.2.3.1.2"><p id="p4846039111815"><a name="p4846039111815"></a><a name="p4846039111815"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row95781450142113"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p7578050172110"><a name="p7578050172110"></a><a name="p7578050172110"></a><a href="https://gitee.com/openharmony/hiviewdfx_hilog/issues/I45AVP" target="_blank" rel="noopener noreferrer">I45AVP</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p757875010217"><a name="p757875010217"></a><a name="p757875010217"></a>The <strong id="b4288144422114"><a name="b4288144422114"></a><a name="b4288144422114"></a>hilog</strong> command fails to be executed after a flush operation.</p>
</td>
</tr>
<tr id="row8671673224"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p96721472224"><a name="p96721472224"></a><a name="p96721472224"></a><a href="https://gitee.com/openharmony/appexecfwk_appexecfwk_lite/issues/I47EPA?from=project-issue" target="_blank" rel="noopener noreferrer">I47EPA</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p9310114823218"><a name="p9310114823218"></a><a name="p9310114823218"></a><strong id="b132001339142311"><a name="b132001339142311"></a><a name="b132001339142311"></a>GetBundleSize</strong> returns an error when the input parameter is null or invalid.</p>
</td>
</tr>
<tr id="row148104610315"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p134844616317"><a name="p134844616317"></a><a name="p134844616317"></a><a href="https://gitee.com/openharmony/multimedia_camera_lite/issues/I434AD" target="_blank" rel="noopener noreferrer">I434AD</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p754313633418"><a name="p754313633418"></a><a name="p754313633418"></a>For Hi3516DV300, the resident memory of the mini system exceeds the baseline.</p>
</td>
</tr>
<tr id="row462454303113"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p1562414319313"><a name="p1562414319313"></a><a name="p1562414319313"></a><a href="https://gitee.com/openharmony/multimedia_camera_lite/issues/I434P1" target="_blank" rel="noopener noreferrer">I434P1</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p1376219542345"><a name="p1376219542345"></a><a name="p1376219542345"></a>For Hi3518EV300, the resident memory of the mini system exceeds the baseline.</p>
</td>
</tr>
<tr id="row90241183118"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p4064117314"><a name="p4064117314"></a><a name="p4064117314"></a><a href="https://gitee.com/openharmony/multimedia_media_lite/issues/I46I6K?from=project-issue" target="_blank" rel="noopener noreferrer">I46I6K</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p163549913716"><a name="p163549913716"></a><a name="p163549913716"></a>There are security coding defects in the code of the multimedia subsystem.</p>
</td>
</tr>
<tr id="row11672071229"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p5672371229"><a name="p5672371229"></a><a name="p5672371229"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I46E6S?from=project-issue" target="_blank" rel="noopener noreferrer">I46E6S</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p649713255389"><a name="p649713255389"></a><a name="p649713255389"></a>The <strong id="b14981114152816"><a name="b14981114152816"></a><a name="b14981114152816"></a>-Werror</strong> compilation option is unavailable for the lightweight kernel module compilation.</p>
</td>
</tr>
<tr id="row89811336123116"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p09811536193115"><a name="p09811536193115"></a><a name="p09811536193115"></a><a href="https://gitee.com/openharmony/appexecfwk_appexecfwk_lite/issues/I47ETO?from=project-issue -" target="_blank" rel="noopener noreferrer">I47ETO</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p154479194394"><a name="p154479194394"></a><a name="p154479194394"></a>The permission verification does not take effect. When the test .bin file is used to invoke the HAP that has not obtained the <strong id="b10338123714498"><a name="b10338123714498"></a><a name="b10338123714498"></a>ohos.permission.GET_BUNDLE_INFO</strong> permission, the query is successful. The expected result is a query failure with <strong id="b92481742172317"><a name="b92481742172317"></a><a name="b92481742172317"></a>0</strong> returned.</p>
</td>
</tr>
<tr id="row178061127163919"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p128073272391"><a name="p128073272391"></a><a name="p128073272391"></a><a href="https://gitee.com/openharmony/drivers_peripheral/issues/I48A2I" target="_blank" rel="noopener noreferrer">I48A2I</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p11236161312425"><a name="p11236161312425"></a><a name="p11236161312425"></a>The board is suspended when the Hi3516DV300 lightweight version calls <strong id="b143881194328"><a name="b143881194328"></a><a name="b143881194328"></a>AllocMem</strong>.</p>
</td>
</tr>
<tr id="row2034964353918"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p123493437397"><a name="p123493437397"></a><a name="p123493437397"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I42LCU" target="_blank" rel="noopener noreferrer">I42LCU</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p19623635184415"><a name="p19623635184415"></a><a name="p19623635184415"></a>The method of checking thread insufficiency and the method of configuring the number of threads are unavailable in the integration test and development board migration guide.</p>
</td>
</tr>
<tr id="row31644408391"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p8164134015394"><a name="p8164134015394"></a><a name="p8164134015394"></a><a href="https://gitee.com/openharmony/kernel_liteos_m/issues/I3IPD7" target="_blank" rel="noopener noreferrer">I3IPD7</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p41641403392"><a name="p41641403392"></a><a name="p41641403392"></a>A description indicating that the <strong id="b143401752183614"><a name="b143401752183614"></a><a name="b143401752183614"></a>osThreadExit</strong> and <strong id="b1227565516366"><a name="b1227565516366"></a><a name="b1227565516366"></a>join</strong> functions are not supported is missing in the header file.</p>
</td>
</tr>
<tr id="row196841035123917"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p1268553543918"><a name="p1268553543918"></a><a name="p1268553543918"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I3M12H" target="_blank" rel="noopener noreferrer">I3M12H</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p2695192515471"><a name="p2695192515471"></a><a name="p2695192515471"></a>During the integration test, two different signals are sent, but <strong id="b76841027153811"><a name="b76841027153811"></a><a name="b76841027153811"></a>sigwait</strong> receives the first signal twice.</p>
</td>
</tr>
<tr id="row1164723416377"><td class="cellrowborder" valign="top" width="17.37%" headers="mcps1.2.3.1.1 "><p id="p1664883420373"><a name="p1664883420373"></a><a name="p1664883420373"></a><a href="https://gitee.com/openharmony/kernel_liteos_a/issues/I47X2Z?from=project-issue" target="_blank" rel="noopener noreferrer">I47X2Z</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.63000000000001%" headers="mcps1.2.3.1.2 "><p id="p761852093814"><a name="p761852093814"></a><a name="p761852093814"></a>When the <strong id="b1925184618394"><a name="b1925184618394"></a><a name="b1925184618394"></a>ActsIpcShmTest.bin</strong> script is executed during the integration test, a large amount of shared memory is not released.</p>
</td>
</tr>
</tbody>
</table>

**Table  4**  Issues resolved for the standard system

<a name="table11749193814402"></a>
<table><thead align="left"><tr id="row17491638104012"><th class="cellrowborder" valign="top" width="17.16%" id="mcps1.2.3.1.1"><p id="p10241204182617"><a name="p10241204182617"></a><a name="p10241204182617"></a>Issue No.</p>
</th>
<th class="cellrowborder" valign="top" width="82.84%" id="mcps1.2.3.1.2"><p id="p18241741112610"><a name="p18241741112610"></a><a name="p18241741112610"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row37491383402"><td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.2.3.1.1 "><p id="p147491538114012"><a name="p147491538114012"></a><a name="p147491538114012"></a><a href="https://gitee.com/openharmony/ace_ace_engine/issues/I46A6H" target="_blank" rel="noopener noreferrer">I46A6H</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.84%" headers="mcps1.2.3.1.2 "><p id="p88319410276"><a name="p88319410276"></a><a name="p88319410276"></a>During the XTS pressure test, the <strong id="b16731027154110"><a name="b16731027154110"></a><a name="b16731027154110"></a>libace.z.so</strong> file is abnormal. As a result, the <strong id="b16761113834113"><a name="b16761113834113"></a><a name="b16761113834113"></a>ohos.samples.flashlight</strong> file encounters the cppcrash exception.</p>
</td>
</tr>
<tr id="row67494389407"><td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.2.3.1.1 "><p id="p207491838164014"><a name="p207491838164014"></a><a name="p207491838164014"></a><a href="https://gitee.com/openharmony/app_samples/issues/I48HLN" target="_blank" rel="noopener noreferrer">I48HLN</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.84%" headers="mcps1.2.3.1.2 "><p id="p1629465022713"><a name="p1629465022713"></a><a name="p1629465022713"></a>Bug-[Demo &amp; application subsystem] [JsCanvas] The <strong id="b14368152018325"><a name="b14368152018325"></a><a name="b14368152018325"></a>Clear</strong> button does not take effect.</p>
</td>
</tr>
<tr id="row16749238204015"><td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.2.3.1.1 "><p id="p19749838184019"><a name="p19749838184019"></a><a name="p19749838184019"></a><a href="https://gitee.com/openharmony/drivers_peripheral/issues/I46HH7" target="_blank" rel="noopener noreferrer">I46HH7</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.84%" headers="mcps1.2.3.1.2 "><p id="p715101272813"><a name="p715101272813"></a><a name="p715101272813"></a>[OpenHarmony 3.0.0.3] [Driver subsystem] The WLAN test case of the standard-system board fails.</p>
</td>
</tr>
<tr id="row15749173824019"><td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.2.3.1.1 "><p id="p97491338184016"><a name="p97491338184016"></a><a name="p97491338184016"></a><a href="https://gitee.com/openharmony/communication_dsoftbus/issues/I4312A" target="_blank" rel="noopener noreferrer">I4312A</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.84%" headers="mcps1.2.3.1.2 "><p id="p177495387403"><a name="p177495387403"></a><a name="p177495387403"></a>[OpenHarmony 2.2 Beta2] [DSoftBus] When multiple devices are networked and one of them is disconnected, self-networking fails for the disconnected device (<strong id="b19707198485"><a name="b19707198485"></a><a name="b19707198485"></a>GetAllNodeDeviceInfo</strong> returns null).</p>
</td>
</tr>
<tr id="row37491738104015"><td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.2.3.1.1 "><p id="p14750103814010"><a name="p14750103814010"></a><a name="p14750103814010"></a><a href="https://gitee.com/openharmony/communication_dsoftbus/issues/I43WIJ" target="_blank" rel="noopener noreferrer">I43WIJ</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.84%" headers="mcps1.2.3.1.2 "><p id="p275010388404"><a name="p275010388404"></a><a name="p275010388404"></a>[OpenHarmony 2.2 Beta2] [DSoftBus] When multiple devices are networked and one of them is switched to another network and then switched back, the device remains online during this switchover (no callback indicating that the device goes offline or goes online is invoked).</p>
</td>
</tr>
<tr id="row475011388407"><td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.2.3.1.1 "><p id="p1675093816401"><a name="p1675093816401"></a><a name="p1675093816401"></a><a href="https://gitee.com/openharmony/communication_dsoftbus/issues/I43KLC" target="_blank" rel="noopener noreferrer">I43KLC</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.84%" headers="mcps1.2.3.1.2 "><p id="p175053824010"><a name="p175053824010"></a><a name="p175053824010"></a>[OpenHarmony 2.2 Beta2] [DSoftBus] A listener for the node status is registered. When a device goes online and then offline, the callback indicating the offline state is invoked twice.</p>
</td>
</tr>
<tr id="row5750183894012"><td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.2.3.1.1 "><p id="p2075023854018"><a name="p2075023854018"></a><a name="p2075023854018"></a><a href="https://gitee.com/openharmony/communication_dsoftbus/issues/I47WTY" target="_blank" rel="noopener noreferrer">I47WTY</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.84%" headers="mcps1.2.3.1.2 "><p id="p12750538184016"><a name="p12750538184016"></a><a name="p12750538184016"></a>[OpenHarmony 3.0 Beta1] [DSoftBus-Transmission] The verification of the session ID range is incorrect. The valid range is 1-16, but the verification result is greater than 17.</p>
</td>
</tr>
</tbody>
</table>

