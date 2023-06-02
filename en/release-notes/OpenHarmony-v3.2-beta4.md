# OpenHarmony 3.2 Beta4


## Version Description

OpenHarmony 3.2 Beta4 provides the following enhancements over OpenHarmony 3.2 Beta3:

**Enhanced basic capabilities for the standard system**

The program access control subsystem supports forward-edge Control Flow Integrity (CFI) and provides enhanced API exception handling.

The kernel subsystem provides enhanced HyperHold memory expansion and F2FS device performance optimization.

The multimodal input subsystem allows applications to enable or disable keys on the keyboard and supports multi-hotspot related to input devices.

The graphics subsystem supports graphics data transmission based on shared memory, YUV graphics layers, GPU compositing on RenderService, and rotation and dynamic resolution of the virtual screen.

The update subsystem supports A/B hot updates, and A/B partition device updates for flashd and SD/OTG.

The globalization subsystem supports on-demand subscription of device management events, overlay differentiation of system resources, and cross-OS resource management.

The Misc services subsystem supports file upload in PUT mode, download task configuration, input method framework optimization and enhancement, and printing service framework.

The DFX subsystem supports collection of power consumption data, system event data, and perf data.

ArkTS APIs support error code reporting, which delivers higher exception handling efficiency.

**Enhanced application development framework for the standard system**

Dynamic library isolation is supported, and applications to be disposed can be interrupted during runtime management.

Window property setting and ArkTS widget interaction are supported. The **\<XComponent>** provides the container component capability.

Application dependencies can be configured. The list of installed and uninstalled applications can be added, deleted, and queried. The list of applications that are forbidden to run can be added, deleted, and queried.

**Enhanced distributed capabilities for the standard system**

The distributed hardware supports the request and import of credential parameters of the same account.


## Version mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.2 Beta4 | NA |
| Public SDK | Ohos_sdk_public 3.2.9.2 (API Version 9 Beta4) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| Full SDK | Ohos_sdk_full 3.2.9.2 (API Version 9 Beta4) | This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions. To use the Full SDK, you must manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| (Optional) HUAWEI DevEco Studio| 3.1 Canary1 | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI DevEco Device Tool| 3.1 Beta1 | Recommended for developing OpenHarmony smart devices|


## Source Code Acquisition


### Prerequisites

1. Register your account with Gitee.

2. Register an SSH public key for access to Gitee.

3. Install the [git client](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) and [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading), and configure user information.
  
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

4. Run the following commands to install the **repo** tool:
  
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the permission, download the tool to another directory and configure it as an environment variable by running the chmod a+x /usr/local/bin/repo command.
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**

Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta4 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta4 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta4 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta4 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 3.2 Beta4    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/code-v3.2-Beta4.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/code-v3.2-Beta4.tar.gz.sha256) | 19.0 GB |
| Hi3861 mini system solution (binary)       | 3.2 Beta4    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/hispark_pegasus.tar.gz.sha256) | 22.6 MB |
| Hi3516 mini system solution - LiteOS (binary)| 3.2 Beta4    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta4/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta4/hispark_taurus_LiteOS.tar.gz.sha256) | 293.9 MB |
| Hi3516 mini system solution - Linux (binary) | 3.2 Beta4    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta4/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta4/hispark_taurus_Linux.tar.gz.sha256) | 173.2 MB |
| RK3568 standard system solution (binary)       | 3.2 Beta4    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/dayu200_standard_arm32.tar.gz.sha256) | 3.2 GB |
| Full SDK package for the standard system (macOS)              | 3.2.9.2      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-mac-full.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-mac-full.tar.gz.sha256) | 662.5 MB |
| Full SDK package for the standard system (Windows\Linux)    | 3.2.9.2      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-windows_linux-full.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-windows_linux-full.tar.gz.sha256) | 1.5 GB |
| Public SDK package for the standard system (macOS)            | 3.2.9.2      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-mac-public.tar.gz.sha256) | 622.2 MB |
| Public SDK package for the standard system (Windows\Linux)  | 3.2.9.2      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.5 GB |


### Prerequisites

1. Register your account with Gitee.

2. Register an SSH public key for access to Gitee.

3. Install the [git client](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) and [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading), and configure user information.
  
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

4. Run the following commands to install the **repo** tool:
  
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the permission, download the tool to another directory and configure it as an environment variable by running the chmod a+x /usr/local/bin/repo command.
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```

## What's New

This version has the following updates to OpenHarmony 3.2 Beta3.


### Feature Updates

  **Table 3** New and enhanced features

| Subsystem| Standard System| Mini and Small Systems|
| -------- | -------- | -------- |
| Common| ArkTS APIs support error code reporting, which delivers higher exception handling efficiency.| NA |
| Ability framework| The runtime management dialog box is optimized.<br>The following requirement is involved:<br>I5X5J9 [ability_runtime] Optimized runtime management dialog box| NA |
| ArkUI development framework| - The **\<Navigation>** component is reconstructed in the split-column scenario and single-page scenario.<br>- The **\<XComponent>** provides the container component capability.<br>The following requirements are involved:<br>I5X5GE Enhanced interaction normalization capability<br>I5X5FX ArkTS widget interaction<br>I5X5G3 Reconstructed **\<Navigation>** component in the split-column scenario<br>I5X5G4 Reconstructed **\<Navigation>** component in the single-page scenario<br>I5X5GG Container component capability of the **\<XComponent>**| NA |
| Program access control subsystem| Privacy control is provided for the use of sensitive resources.<br>The following requirements are involved:<br>I5RWXF [New feature] Global microphone setting management<br>I5RWX8 [New feature] Microphone usage status management| NA |
| SAMGR| Distributed invoking component management is added to prevent malicious application startup or keepalive.<br>The following requirements are involved:<br>I5T6GJ [Distributed component management] [DMS] Ability component launch management<br>I5T6HF [Distributed component management] [DMS] ServiceAbility/ServiceExtensionAbility component launch management| NA |
| Multimedia subsystem| - Privacy control is provided for the use of sensitive resources.<br>- The volume can be set based on the device group, and the DTMF dial tone can be played.<br>The following requirements are involved:<br>I5X5HT [Enhanced feature] Device group based volume setting<br>I5X5IF [New feature] Voice broadcast playback type and voice recognition recording type<br>I5X48J [New feature] Support for the DTMF dial tone| NA |
| Test subsystem| The kernel memory event analysis capability is added to SmartPerf-Host to enhance performance fault locating.<br>The following requirement is involved:<br>I5X55J [New feature] Kernel memory event analysis| NA |
| Bundle management framework| Application installation and startup management is added.<br>The following requirements are involved:<br>I5MZ8K [New feature] Adding, deleting, and querying the list of applications that are forbidden to run<br>I5MZ8Q [New Feature] Adding, deleting, and querying the list of installed and uninstalled applications| NA |
| Common event and notification subsystem| The custom system HAP dialog box is used to replace the original **UIService** dialog box, reducing the ArkUI memory usage.<br>The following requirement is involved:<br>I5X5L0 Using a preset application instead of **UIService** to display a notification dialog box| NA |
| Distributed hardware subsystem| The implementation of the PIN dialog box is optimized for higher module stability.<br>The following requirement is involved:<br>I5X5KX [Enhanced feature] Optimized implementation of the PIN dialog box| NA |
| Update subsystem| The A/B hot upgrade feature is added.<br>The following requirements are involved:<br>I5X4RO [Enhanced feature] A/B update support for the update_service component<br>I5X4RQ [Updater] Output of the A/B hot update documents<br>I5X4RR [New feature] A/B partition device update for flashd<br>I5X4RT [New feature] A/B partition device update for SD/OTG<br>I5X4RU [New feature] Support for A/B hot update| NA |
| Kernel subsystem| The ARM 64 CPU can restrict privileged users from accessing memory that can be accessed by non-privileged users. If a privileged user attempts to access such memory, an exception is thrown.<br>The HyperHold memory uses the high-speed swap partition technology and corresponding policies to support application keepalive.<br>The following requirements are involved:<br>I5X5AR [New feature] ARM 64 support for PAN<br>I5X5AS [New feature] ARM 64 support for PXN<br>I5X5B9 [New feature] HyperHold memory expansion: The high-speed swap partition technology and corresponding policies are used to support application keepalive.| NA |
| Graphics subsystem| The pointer style can be set in the window drag-and-drop scenario.<br>The following requirement is involved:<br>I5X5D9 Setting the pointer style in the window drag-and-drop scenario| NA |
| Multi-language runtime subsystem| AOT PGO files can be generated.<br>The following requirements are involved:<br>I5X5K3 [New specifications] Generation of AOT PGO files<br>I5X5K2 [New specifications] AOT PGO configuration| NA |
| Web subsystem| - The webview component allows users to select and copy both text and text on pages.<br>- The web component supports window events, full-screen events, and URL obtaining.<br>The following requirements are involved:<br>I5QA3D [New feature] [webview] Content selection and copy on a page with both texts and images<br>I5X53B [Enhanced feature] URL obtaining support by the web component<br>I5R6E0 [New specifications] Full-screen event support by the web component<br>I5X53C [New specifications] Window event support by the web component| NA |
| Misc services subsystem| - The input method framework supports listening for the switching of input methods and input method subtypes.<br>- Files can be uploaded in PUT mode.<br>The following requirements are involved:<br>I5X5LA [input_method_fwk] Listening for the switching of input methods and input method subtypes<br>I5X5LR [request] File uploading in PUT mode| NA |
| USB subsystem| The dialog box displayed for permission request is adapted to the new system dialog box solution.<br>The following requirement is involved:<br>I5UYX4 [New feature] Adaptation of the permission request dialog box to the new system dialog box solution| NA |
| File management subsystem| High-frequency APIs, such as APIs for opening and reading a file, are compatible across platforms.<br>The following requirements are involved:<br>I5X5E5 [fileAPI] [Capability bridging] Bridging the file I/O capability of the target platform<br>I5X5E6 [fileAPI] [Capability bridging] Bridging the file I/O capability of the target platform<br>I5X4P2 [filePicker] Modification to the file access framework interface| NA |
| DFX | - HiTrace provides a unified dotting interface and call link interface.<br>- The power consumption data and system event data can be collected.<br>- Perf data can be collected during the startup of the JS HAP.<br>The following requirements are involved:<br>I5X4TY [New feature] Unified dotting interface of HiTrace: HiTraceMeter<br>I5X4U1 [New feature] Unified call link interface of HiTrace: HiTraceChain<br>I5X4TD [New feature] Power consumption data collection<br>I5X4TE [New feature] System event data collection<br>I5X4TL [New feature] Collection of perf data during JS HAP startup| NA |



For details about the API changes, see the following:

[API Differences](api-diff/v3.2-beta4/js-apidiff-ability.md)



### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).

### Samples

The following samples written in ArkTS are added.

  **Table 4** New samples

| Subsystem<div style="width:100px"></div>| Name| Introduction|
| -------- | -------- | -------- |
| Common event and notification subsystem| [Event Notification](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomEmitter)| This sample shows the in-process event notification. After a user selects an offering and submits an order, the selected offering is displayed in the order list.|
| Data management subsystem| [Cross-Application Data Sharing](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DataManagement/CrossAppDataShare)| This sample implements cross-application data sharing. It provides contacts (data provider) and contacts assistant (data user). Contacts support functionalities such as adding, deleting, modifying, and querying contacts data. Contacts assistant supports contacts data synchronization and merging of duplicate data.|
| Resource scheduler subsystem| [Agent-Powered Scheduled Reminder](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/ReminderAgentManager)| This sample uses agent-powered scheduled reminder to create three types of scheduled reminders: alarm clocks, calendar events, and countdown timers. Agent-powered scheduled reminder ensures that the timing and pop-up notification functions will be performed by the system service agent in the background when the application is frozen or exits.|
| File management subsystem| [Storage Space Statistics](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/StorageStatistic)| This sample uses the application package management, application space statistics, and volume management modules to implement the viewing of storage space information of the current device, all installed applications, and all available volumes.|
| Window manager| [Screenshot](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/Screenshot)| This sample uses the screenshot, window, and display modules to take screenshots, switch the privacy window, and query the privacy window, in sequence.|
| Bundle management framework| [Multi-HAP](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Project/ApplicationHap/MultiHap)| This sample shows the development of multi-HAP. The sample app includes one entry HAP and two feature HAPs. The two feature HAPs provide audio and video playback components, respectively. The two components are also used in the entry component.|
| Ability framework| [Ability Launch Mode](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/AbilityStartMode)| This sample shows how to implement the standard, singleton, and specified ability launch modes in the stage model.|
| Resource management| [Application Theme Switch](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Project/ResourceAllocation/ApplicationThemeSwitch)| This sample creates the **dark** and **light** folders at the same level as the **base** folder to configure resources related to the dark and light themes. The custom theme file is configured in the **ThemeConst** file to implement multi-theme switching by controlling variables.|

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).



## Resolved Issues

  **Table 5** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| I5S40B | The actual sliding frame rate of **Contacts** is 30.3 fps, which is less than the baseline value (54 fps) by 23.7 fps.|
| I5MVDK | A crash occurs when a socket fuzz test is performed on **/data/data/.pulse_dir/runtime/cli**.|
| I5M3UO | [TTE WRC team] There is new line injection via the Wi-Fi SSID in the wifi_manager_service.|
| I5SXXR | High-privilege processes exist in lightweight graphics.|


## Known Issues

  **Table 6** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I5KMQX | [rk3568] [ToC] [Probability: inevitably] The actual delay for a switch between the contacts and dialing subtabs is 1770.8 ms, which is 1330 ms longer than the baseline value (440 ms).| The overall static KPIs and load meet the requirements, and the impact is controllable.| 2022-12-30|
| I61M6T | In the resident memory test performed on the RK3568 device, the actual value of the com.ohos.launcher process is 99514 KB, which exceeds the baseline value (84279 KB) by 14.8 MB.| The entire system memory meets the requirement, and the impact is controllable.| 2022-12-30|
| I59QII | In the resident memory test performed on the RK3568 device, the actual value of the netmanager process is 3884 KB, which exceeds the baseline value (1241 KB) by 2.58 MB. In the memory test, the actual value of the netmanager process exceeds the baseline value (1241 KB) by 1 MB.| The entire system memory meets the requirement, and the impact is controllable.| 2022-12-30|
| I5Q5PR | In the resident memory test performed on the RK3568 device, the actual value of the wifi_hal_service process is 4374 KB, which exceeds the baseline value (829 KB) by 3.4 MB.| The entire system memory meets the requirement, and the impact is controllable.| 2022-12-30|
| I61E1I | BR P2P transmission fails between RK3568 devices.| DSoftBus can transmit data through Bluetooth and LAN, but fails to do so using BR P2P.| 2022-12-30|
| I63DX6 | Wi-Fi P2P transmission fails between RK3568 devices| DSoftBus can transmit data through Bluetooth and LAN, but fails to do so using Wi-Fi P2P.| 2022-12-30|
| I63FEA | [rk3568] When the system camera application is started, the preview image rotates 90 degrees counterclockwise.| This is a hardware adaptation problem. It occurs on RK3568 devices with 8 GB memory, but not on RK3568 devices with 4 GB memory| 2022-12-30|
| I62EW1 | The media_server (L1) processes use the root permission.| Some chip component services are running in the media_server process, and therefore the root permission is required. Decoupling is required.| 2022-12-30|
| I5XYRX, I5YTYX, I5YU16, I5YUB4, I5YUBS| The functions related to the Bluetooth protocol stack module have an out-of-bounds read vulnerability.| The functions have an out-of-bounds read vulnerability.| 2022-12-30|
| I5SSEW, I5UFS1, I5ICMZ, I5ICM7, I5QC6H, I5R2L5, I5R2LI, I5SQO0, I5UDY5, I5YPMZ| The giflib component, das u-boot component, and kernel have known vulnerabilities.| The solutions to the vulnerabilities will be synchronized after they are released on the official website. No patch solution is available by now.| 2022-12-30|
