# OpenHarmony 2.0 Canary \(2021-06-02\)<a name="EN-US_TOPIC_0000001102397706"></a>

-   [Version Description](#section1677664815431)
-   [Version Mapping](#section13201781528)
-   [What's New](#section11256141314463)

## Version Description<a name="section1677664815431"></a>

On the basis of OpenHarmony 1.1.0, OpenHarmony 2.0 adds the version for the standard system, which delivers the following functions:

-   Twenty-two subsystems have been added to support comprehensive OS capabilities and app development for screened devices with a memory greater than 128 MB.
-   Three preset apps, Launcher, Settings, and SystemUI, have been provided.
-   A brand-new OpenHarmony application framework and JS UI framework have been provided.
-   JavaScript app development capabilities have been provided.
-   A media framework has been provided to support the development of audio and video functions.
-   The Java UI framework has been provided to support window management, image synthesis, and GPU rendering capabilities.

## Version Mapping<a name="section13201781528"></a>

**Table  1**  Version mapping of software and tools

<a name="table3398163217210"></a>
<table><thead align="left"><tr id="row1339820327212"><th class="cellrowborder" valign="top" width="28.622862286228624%" id="mcps1.2.4.1.1"><p id="p63988321828"><a name="p63988321828"></a><a name="p63988321828"></a>Software</p>
</th>
<th class="cellrowborder" valign="top" width="29.972997299729975%" id="mcps1.2.4.1.2"><p id="p7398133211216"><a name="p7398133211216"></a><a name="p7398133211216"></a>Version</p>
</th>
<th class="cellrowborder" valign="top" width="41.4041404140414%" id="mcps1.2.4.1.3"><p id="p1239913216212"><a name="p1239913216212"></a><a name="p1239913216212"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row113991632528"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p33994328215"><a name="p33994328215"></a><a name="p33994328215"></a>OpenHarmony</p>
</td>
<td class="cellrowborder" valign="top" width="29.972997299729975%" headers="mcps1.2.4.1.2 "><p id="p966216165485"><a name="p966216165485"></a><a name="p966216165485"></a>2.0 Canary</p>
</td>
<td class="cellrowborder" valign="top" width="41.4041404140414%" headers="mcps1.2.4.1.3 "><p id="p7316162554817"><a name="p7316162554817"></a><a name="p7316162554817"></a>N/A</p>
</td>
</tr>
<tr id="row239911321527"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p193286111669"><a name="p193286111669"></a><a name="p193286111669"></a>(Optional) HUAWEI DevEco Studio</p>
</td>
<td class="cellrowborder" valign="top" width="29.972997299729975%" headers="mcps1.2.4.1.2 "><p id="p83711419141513"><a name="p83711419141513"></a><a name="p83711419141513"></a>DevEco Studio 2.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="41.4041404140414%" headers="mcps1.2.4.1.3 "><p id="p12457193617153"><a name="p12457193617153"></a><a name="p12457193617153"></a>It is recommended for developing OpenHarmony apps.</p>
</td>
</tr>
<tr id="row153991032926"><td class="cellrowborder" valign="top" width="28.622862286228624%" headers="mcps1.2.4.1.1 "><p id="p17708321495"><a name="p17708321495"></a><a name="p17708321495"></a>(Optional) HUAWEI DevEco Device Tool</p>
</td>
<td class="cellrowborder" valign="top" width="29.972997299729975%" headers="mcps1.2.4.1.2 "><p id="p145502371612"><a name="p145502371612"></a><a name="p145502371612"></a>Deveco DeviceTool 2.2 Beta1</p>
</td>
<td class="cellrowborder" valign="top" width="41.4041404140414%" headers="mcps1.2.4.1.3 "><p id="p1139765711198"><a name="p1139765711198"></a><a name="p1139765711198"></a>It is recommended for OpenHarmony smart devices.</p>
</td>
</tr>
</tbody>
</table>


## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**: Use the **repo** tool to download the source code over SSH. (You must have registered an SSH public key for access to Gitee.)

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-2.0-Canary --no-repo-verify
repo sync-c
repo forall -c'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-2.0-Canary --no-repo-verify
repo sync-c
repo forall -c'git lfs pull'
```


### Acquiring Source Code from Image Sites

**Table  2** Sites for acquiring source code

| Source&nbsp;Code | Version | Site | SHA-256&nbsp;Checksum | 
| -------- | -------- | -------- | -------- |
| Full&nbsp;code&nbsp;base | 2.0 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary_20210601.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary_20210601.tar.gz.sha256) | 
| Release&nbsp;Notes | 2.0 | [Download](https://gitee.com/openharmony/docs/blob/master/en/release-notes/openharmony-2-0-canary.md) | - | 


## What's New<a name="section11256141314463"></a>

This version inherits all the features of OpenHarmony 1.1.0 and adds the version form for the standard system. The following table describes the specific features added for the version form.

**Table  3**  New features

<a name="table1976311913503"></a>
<table><thead align="left"><tr id="row127631916501"><th class="cellrowborder" valign="top" width="24.94%" id="mcps1.2.3.1.1"><p id="p6763997509"><a name="p6763997509"></a><a name="p6763997509"></a>Subsystem</p>
</th>
<th class="cellrowborder" valign="top" width="75.06%" id="mcps1.2.3.1.2"><p id="p1176418919506"><a name="p1176418919506"></a><a name="p1176418919506"></a>New Feature</p>
</th>
</tr>
</thead>
<tbody><tr id="row37646915015"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p87641995507"><a name="p87641995507"></a><a name="p87641995507"></a>Kernel</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p0750218142312"><a name="p0750218142312"></a><a name="p0750218142312"></a>The OpenHarmony kernel is built based on the open-source Linux kernel LTS release and forms a complete kernel baseline by merging the common vulnerabilities and exposures (CVE) patches and features for OpenHarmony upper-layer adaptation.</p>
</td>
</tr>
<tr id="row12618619217"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1626368217"><a name="p1626368217"></a><a name="p1626368217"></a>Distributed File</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p17116387289"><a name="p17116387289"></a><a name="p17116387289"></a>Provided JavaScript APIs for local file synchronization, including reading and writing files, accessing directories, and collecting file statistics.</p>
</td>
</tr>
<tr id="row855742119216"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1557921172115"><a name="p1557921172115"></a><a name="p1557921172115"></a>Graphics</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul6736012132813"></a><a name="ul6736012132813"></a><ul id="ul6736012132813"><li>Provided window management functions, including creating and destroying windows and managing window stacks.</li><li>Added the synthesizer function, which implements CPU, GPU, and TDE synthesis.</li><li>Added the BufferQueue function to support inter-process communication.</li><li>Added the VSync management function.</li></ul>
</td>
</tr>
<tr id="row1697324472115"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p19973154462114"><a name="p19973154462114"></a><a name="p19973154462114"></a>Driver</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p55681444121518"><a name="p55681444121518"></a><a name="p55681444121518"></a>Added the user-space driver framework.</p>
</td>
</tr>
<tr id="row472717219225"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p147281129226"><a name="p147281129226"></a><a name="p147281129226"></a>Power Management</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p68761043171814"><a name="p68761043171814"></a><a name="p68761043171814"></a>Added power management capabilities, including powering off the device, turning on/off the device screen, adjusting the brightness, querying the battery status, and managing the system power and running lock.</p>
</td>
</tr>
<tr id="row19203133032216"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p23098422221"><a name="p23098422221"></a><a name="p23098422221"></a>Multimodal Input</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p122255019161"><a name="p122255019161"></a><a name="p122255019161"></a>Added the single-touch input capability.</p>
</td>
</tr>
<tr id="row147681792310"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1440215238292"><a name="p1440215238292"></a><a name="p1440215238292"></a>Startup</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p311264101619"><a name="p311264101619"></a><a name="p311264101619"></a>Added JavaScript APIs for managing system attributes.</p>
</td>
</tr>
<tr id="row620911170236"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p162091917182319"><a name="p162091917182319"></a><a name="p162091917182319"></a>Update</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1758215644919"></a><a name="ul1758215644919"></a><ul id="ul1758215644919"><li>Added the OTA update using a full package.</li><li>Added the OTA update using a differential package.</li><li>Added JavaScript APIs for managing system attributes.</li></ul>
</td>
</tr>
<tr id="row13634133172314"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p136341733162314"><a name="p136341733162314"></a><a name="p136341733162314"></a>Account</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p742721918165"><a name="p742721918165"></a><a name="p742721918165"></a>Provided login status management of distributed cloud accounts.</p>
</td>
</tr>
<tr id="row101761542112310"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1417634216237"><a name="p1417634216237"></a><a name="p1417634216237"></a>Compilation and Building</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul52391642195617"></a><a name="ul52391642195617"></a><ul id="ul52391642195617"><li>Added building of targets by module name or submodule name.</li><li>Supported access of different chip platforms and configuration of the product module list.</li></ul>
</td>
</tr>
<tr id="row13162195114238"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p19162451172317"><a name="p19162451172317"></a><a name="p19162451172317"></a>Testing</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p1279162291610"><a name="p1279162291610"></a><a name="p1279162291610"></a>Added the developer test capability of conducting C++ API unit tests and API performance tests.</p>
</td>
</tr>
<tr id="row104841456182316"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p2484115622319"><a name="p2484115622319"></a><a name="p2484115622319"></a>Data Management</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p11417133545113"><a name="p11417133545113"></a><a name="p11417133545113"></a>Provided lightweight key-value operations for local apps to store a small amount of data. As the stored data is already loaded in the memory, the faster data access speed achieves a higher work efficiency.</p>
</td>
</tr>
<tr id="row3363151082416"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1536351042411"><a name="p1536351042411"></a><a name="p1536351042411"></a>Programming Language Runtime</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p136651126161615"><a name="p136651126161615"></a><a name="p136651126161615"></a>Provided the compilation and execution environment for programs developed with JavaScript, and C/C++, basic libraries that support the runtime, and the runtime-associated APIs, compilers, and auxiliary tools.</p>
</td>
</tr>
<tr id="row76812381241"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p15686388241"><a name="p15686388241"></a><a name="p15686388241"></a>Distributed Scheduler</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p725263113167"><a name="p725263113167"></a><a name="p725263113167"></a>Provided the capabilities of starting, registering, querying, and managing system services.</p>
</td>
</tr>
<tr id="row776714945019"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p0767179135017"><a name="p0767179135017"></a><a name="p0767179135017"></a>JS UI framework</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul2726340105915"></a><a name="ul2726340105915"></a><ul id="ul2726340105915"><li>Provided more than 40 basic UI components and container components.</li><li>Provided standard CSS animations.</li><li>Provided the atomic layout and grid layout.</li><li>Provided a UI programming framework that supports the web-development-like paradigm.</li><li>Provided the JavaScript API extension mechanism.</li></ul>
</td>
</tr>
<tr id="row18427151814124"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p14427151814129"><a name="p14427151814129"></a><a name="p14427151814129"></a>Multimedia</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul258211290236"></a><a name="ul258211290236"></a><ul id="ul258211290236"><li>Added basic functions of media playback and recording.</li><li>Added basic functions of camera management and sampling.</li><li>Added basic functions of audio volume and device management.</li></ul>
</td>
</tr>
<tr id="row188861132252"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p18866362511"><a name="p18866362511"></a><a name="p18866362511"></a>Event Notification</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p15273861617"><a name="p15273861617"></a><a name="p15273861617"></a>Added basic functions of publishing, subscribing to, and receiving common events.</p>
</td>
</tr>
<tr id="row15926131110258"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p17926161172514"><a name="p17926161172514"></a><a name="p17926161172514"></a>Misc Services</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p11712144071610"><a name="p11712144071610"></a><a name="p11712144071610"></a>Added the function of setting the time.</p>
</td>
</tr>
<tr id="row23492013257"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p1935122022515"><a name="p1935122022515"></a><a name="p1935122022515"></a>Application framework</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p179997533484"><a name="p179997533484"></a><a name="p179997533484"></a>Provided bundle installation, uninstallation, running, and management capabilities.</p>
</td>
</tr>
<tr id="row4594164382519"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p15594164382518"><a name="p15594164382518"></a><a name="p15594164382518"></a>Telephony</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1781485014812"></a><a name="ul1781485014812"></a><ul id="ul1781485014812"><li>Provided the capabilities of obtaining the signal strength and the network registration status.</li><li>Provided the capability of obtaining the SIM card status.</li><li>Provided the capabilities of making, rejecting, and ending calls.</li><li>Provided the capabilities of sending and receiving SMS messages.</li></ul>
</td>
</tr>
<tr id="row5772750122518"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p177245072517"><a name="p177245072517"></a><a name="p177245072517"></a>Utils</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p183220493311"><a name="p183220493311"></a><a name="p183220493311"></a>Provides some common enhanced APIs for development using C and C++.</p>
</td>
</tr>
<tr id="row691575819259"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p6915175810253"><a name="p6915175810253"></a><a name="p6915175810253"></a>Development Tools</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1477582715386"></a><a name="ul1477582715386"></a><ul id="ul1477582715386"><li>Provided the device connection debugger.</li><li>Provided the performance tracing capability.</li><li>Provided real-time memory analysis, trace, and device-side plug-ins.</li></ul>
</td>
</tr>
<tr id="row32413714262"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p424237152616"><a name="p424237152616"></a><a name="p424237152616"></a>Intelligent Soft Bus</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul03096914278"></a><a name="ul03096914278"></a><ul id="ul03096914278"><li>Provided inter-process communication (IPC) and remote procedure call (RPC) capabilities.</li><li>Provided soft bus services including device discovery, networking, and transmission.</li><li>Provided basic WLAN capabilities, including enabling/disabling, scanning, and connecting to a station.</li></ul>
</td>
</tr>
<tr id="row0309184419277"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p18309844112717"><a name="p18309844112717"></a><a name="p18309844112717"></a>XTS</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p5545123182116"><a name="p5545123182116"></a><a name="p5545123182116"></a>Provided test case suites for maintaining the compatibility of common APIs for subsystems.</p>
</td>
</tr>
<tr id="row161918529268"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p066763616286"><a name="p066763616286"></a><a name="p066763616286"></a>System Apps</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><p id="p1622081485920"><a name="p1622081485920"></a><a name="p1622081485920"></a>Launcher</p>
<a name="ul683613349018"></a><a name="ul683613349018"></a><ul id="ul683613349018"><li>Provided the capabilities of displaying all app icons, starting an app, and uninstalling an app.</li><li>Provided the Launcher system app that allows switching between the grid layout and list layout.</li><li>Provided recent task management to support hot start and task deletion.</li></ul>
<p id="p2099221819011"><a name="p2099221819011"></a><a name="p2099221819011"></a>Settings</p>
<a name="ul18614124113017"></a><a name="ul18614124113017"></a><ul id="ul18614124113017"><li>Provided the Settings system app that allows users to set the brightness and time and to query app and device information.</li></ul>
<p id="p0801430707"><a name="p0801430707"></a><a name="p0801430707"></a>SystemUI</p>
<a name="ul320210441907"></a><a name="ul320210441907"></a><ul id="ul320210441907"><li>Provided the system status bar to display time and battery information.</li><li>Provided the display of system navigation.</li></ul>
</td>
</tr>
<tr id="row11882513277"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p5881950273"><a name="p5881950273"></a><a name="p5881950273"></a>DFX</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul240818173613"></a><a name="ul240818173613"></a><ul id="ul240818173613"><li>Provided the logging function.</li><li>Provided fault information collection and subscription.</li><li>Provided APIs for logging system events.</li><li>Provided the framework and APIs for logging app events.</li></ul>
</td>
</tr>
<tr id="row377318915507"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p777349105012"><a name="p777349105012"></a><a name="p777349105012"></a>Globalization</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1815672517363"></a><a name="ul1815672517363"></a><ul id="ul1815672517363"><li>Provided the capability of parsing and reading i18n resources.</li><li>Provided the capability of formatting the date and time.</li></ul>
</td>
</tr>
<tr id="row20979141410276"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.3.1.1 "><p id="p129791114102719"><a name="p129791114102719"></a><a name="p129791114102719"></a>Security</p>
</td>
<td class="cellrowborder" valign="top" width="75.06%" headers="mcps1.2.3.1.2 "><a name="ul1992964853616"></a><a name="ul1992964853616"></a><ul id="ul1992964853616"><li>Provided system permission management, including system permission declaration, parsing of the permissions requested or declared during app installation, permission query, and permission granting.</li><li>Provided the app signature and signature verification capabilities.</li><li>Provided mutual authentication and device group management for trusted P2P devices.</li></ul>
</td>
</tr>
</tbody>
</table>

