# OpenHarmony 3.2 Beta3


## Version Description

OpenHarmony 3.2 Beta3 provides the following enhancements over OpenHarmony 3.2 Beta2:

**Enhanced basic capabilities for the standard system**

The pan-sensor subsystem adds vibrator priority management.

The multimodal input subsystem adds mouse pointer style and speed setting, configuration of sequential ability startup, and ScreenHop; and enhances mouse event reporting.

The Misc services subsystem adds the following basic features: pasteboard, upload and download, screen lock, and input method framework.

The kernel subsystem adds the following basic capabilities: memory level notification to Ability Manager Service (AMS), reclaim priority management for resident system services, and reclaim priority management based on different Extension ability states.

In the Design For X (DFX) subsystem, the faultloggerd component supports print in the hybrid JS and native stacks; the hilog component provides domain trustlist management and log statistics; the hisysevent and hiappeventssh components provide enhanced event capabilities; the hidumper component provides more detailed memory classification information.

The parameterized data driver capability is added to the unit test framework. APIs related to fling and complex gestures (such as two-finger pinch) are added to the UI test framework. The xdevice component adds device-level DFX log collection upon task execution.

The multi-language runtime subsystem adds the following capabilities: ES2021 in strict mode, modularization, runtime debugging and tuning enhancement, and bytecode hot reload.

User identity authentication is added to the IAM account subsystem. The permission service supports precise positioning and fuzzy positioning, and other capabilities are enhanced. The privacy management service is provided.

The multimedia subsystem adds native APIs for audio decoding, audio encoding, video decoding, and video encoding; audio and video synchronization; playback start time optimization; video hardware encoding and decoding based on the HDI codec interface; distributed audio, volume, and device status management; device listening and projection; preview, photographing, and video recording using distributed cameras.

**Enhanced application development framework for the standard system**

The common event and notification subsystem provides DLP adaptation. Subsystems can send notifications.

The webview component supports copy and paste. Basic audio/video playback and HTTPS bidirectional authentication are supported.

Permission verification, startup rules, and quick repair are added for the ability framework, and widgets can be flexibly separated and combined.

The following capabilities are enhanced: ArkUI component, resource and media query, DFX, and toolchain. The memory and performance are optimized.

The DeviceProfile subsystem supports adaptation to the automatic synchronization policy of the distributed database and supplements the type of information that can be collected.

For the bundle management framework, Extension abilities are added for the thumbnail and preview. Certain features become tailorable. Foolproof and quick repair are added. Specific capabilities of preset applications can be managed. Applications can be installed without decompressing HAP files.

For the system ability management subsystem (SAMGR), system services can be loaded across devices. The restart and recovery mechanism is provided for the foundation process. Distributed component management supports multi-user, cross-device invoking. Singleton ability continuation is supported.

**Enhanced distributed capabilities for the standard system**

The distributed database supports cross-device and cross-application sharing. The relational database (RDB) supports remote query, database encryption, and app twin. The KVDB supports backup and restore, condition-based synchronization, and centralized system data synchronization when the device goes online.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.2 Beta3| NA |
| Public SDK | Ohos_sdk_public 3.2.7.5 (API Version 9 Beta3)<br>Ohos_sdk_public&nbsp;3.2.7.6&nbsp;(API&nbsp;Version&nbsp;9&nbsp;Beta3) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio.|
| Full SDK | Ohos_sdk_full 3.2.7.5 (API Version 9 Beta3)<br>Ohos_sdk_full&nbsp;3.2.7.6&nbsp;(API&nbsp;Version&nbsp;9&nbsp;Beta3) | This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the full SDK, manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| (Optional) HUAWEI DevEco Studio| 3.0 Release| Recommended for developing OpenHarmony applications.|
| (Optional) HUAWEI DevEco Device Tool| 3.0 Release| Recommended for developing OpenHarmony devices.|


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta3 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta3 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta3 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta3 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base (for mini, small, and standard systems)       | 3.2 Beta3    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/code-v3.2-Beta3.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/code-v3.2-Beta3.tar.gz.sha256)|
| Hi3861 mini system solution (binary)       | 3.2 Beta3    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/hispark_pegasus.tar.gz.sha256) |
| Hi3516 mini system solution - LiteOS (binary)| 3.2 Beta3    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta3/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta3/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516 mini system solution - Linux (binary) | 3.2 Beta3    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta3/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta3/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568 standard system solution (binary)       | 3.2 Beta3    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/dayu200_standard_arm32.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/dayu200_standard_arm32.tar.gz.sha256) |
| Full SDK package for the standard system (macOS)              | 3.2.7.5      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-mac-full.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-mac-full.tar.gz.sha256) |
| Full SDK package for the standard system (Windows/Linux)    | 3.2.7.5      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-windows_linux-full.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-windows_linux-full.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)            | 3.2.7.5      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-mac-public.tar.gz.sha256) |
| Public SDK package for the standard system (Windows/Linux)  | 3.2.7.5      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-windows_linux-public.tar.gz.sha256) |
| Full SDK package for the standard system (macOS)              | 3.2.7.6      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/mac-sdk-full.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/mac-sdk-full.tar.gz.sha256)|
| Full SDK package for the standard system (Windows/Linux)    | 3.2.7.6      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/ohos-sdk-full.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/ohos-sdk-full.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)            | 3.2.7.6      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/mac-sdk-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/mac-sdk-public.tar.gz.sha256) |
| Public SDK package for the standard system (Windows/Linux)  | 3.2.7.6      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/ohos-sdk-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/ohos-sdk-public.tar.gz.sha256) |



## Updates

This version has the following updates to OpenHarmony 3.2 Beta2.


### Feature Updates

  **Table 3** New and enhanced features

| Subsystem| Standard System| Mini and Small Systems|
| -------- | -------- | -------- |
| Ability framework| Permission verification, startup rules, and quick repair are added, and widgets can be flexibly separated and combined.<br>The following requirements are involved:<br>I581RO [New feature] Adaptation of **Recents** to the sandbox process of encrypted files<br>I581SE [New feature] AMS permission verification for the sandbox process<br>I581XD [New feature] Capturing of JavaScript crashes by application<br>I581YL [New feature] Widget sharing<br>I58213 [Enhanced feature] APIs for listening for the association between Service, Data, and Extension abilities<br>I5824D [New feature] Worker thread of JS runtime<br>I5825N [New feature] Application code loading without HAP decompression<br>I5826I [New feature] Application resource loading without HAP decompression<br>I5826Y [New feature] Loading of code in the dependency HAP file<br>I5HQEM [New feature] Listening for the window stage lifecycle by context<br>I5MVKZ [New feature] Intra-application widget loading<br>I5OD2E [New feature] Quick repair service - patch installation<br>I5ODCD [New feature] Quick repair service - patch query<br>I5PXW4 [Enhanced feature] Querying and listening for process and component visibility<br>I5Q8IU [New feature] Forcible intra-application widget refresh<br>I5QGMS [New feature] Intra-application widget event management| NA |
| Bundle management framework| Extension abilities are added for the thumbnail and preview. Certain features become tailorable. Foolproof and quick repair are added. Specific capabilities of preset applications can be managed. Applications can be installed without decompressing HAP files.<br>The following requirements are involved:<br>I5MZ33 [New feature] Extension abilities for the thumbnail and preview<br>I56WAY [New feature] Tailorable bundle management<br>I56WA0 [New feature] Foolproof<br>I56W8O [New feature] Capability management for preset applications<br>I56WGB [New Feature] Application installation without HAP decompression<br>I5N7AD [New feature] Patch installation<br>I5MZ6Z [New feature] Patch package scan upon startup| NA |
| DFX | The faultloggerd component supports print in the hybrid JS and native stacks. The hilog component provides domain trustlist management and log statistics. The hisysevent and hiappeventssh components provide enhanced event capabilities. The hidumper component provides more detailed memory classification information.<br>The following requirements are involved:<br>I5PJ9O [New specifications] [faultloggerd] Print in the hybrid JS and native stacks<br>I5OA3F [New specifications] [hisysevent] Improved usability of the HiSysEvent subscription and query interfaces<br>I5NU4L [New feature] [hilog] System domain trustlist management<br>I5NU71 [New feature] [hilog] Log statistics<br>I5NU7F [New feature] [hilog] Log service permission management<br>I5KDIG [New specifications] [hisysevent] Handling system event storms of the subscription interface<br>I5L2RV [New specifications] [hisysevent] Handling system event storms of the query interface<br>I5LFCZ [New specifications] [hisysevent] Handling of system event storms of the system event storage and processing interface<br>I5FNPQ [New specifications] [hisysevent] Handling system event storms of the system event dotting interface<br>I5NTOS [New specifications] [hiappevent] Event clearance<br>I5NTOD [New specifications] [hiappevent] Event query<br>I5LB4N [New specifications] [hiappevent] Event subscription<br>I5KYYI [New specifications] [hiappevent] Event distribution<br>I5K0X6 [New specifications] [hiappevent] Event management<br>I5NULM [New specifications] [hiview] Reading kernel events<br>I5NWZQ [New feature] Further smaps classification of processes; display of more detailed classification information in the exported hidumper information<br>I5GXTG [New feature] Optimized hidumper permission privacy| NA |
| Test subsystem| The parameterized data driver capability is added to the unit test framework. APIs related to fling and complex gestures (such as two-finger pinch) are added to the UI test framework. The xdevice component adds device-level DFX log collection upon task execution.<br>The following requirements are involved:<br>I5LI56 [New specifications] DFX integration for log collection<br>I5LUI8 [New specifications] Parameterized data driver for the unit test framework<br>I5L5DL [New specifications] APIs related to fling and complex gestures of the UI test framework<br>I5K2LZ [New specifications] Updated readme file for the unit test framework and UI test framework<br>I5MQTL [New feature] Updated readme files for WuKong| NA |
| SAMGR| System services can be loaded across devices. The restart and recovery mechanism is provided for the foundation process. Distributed component management supports multi-user, cross-device invoking. Singleton ability continuation is supported.<br>The following requirements are involved:<br>I5KMF7 [samgr] [Enhanced feature] Remote loading of system services<br>I5IZ7R [safwk] [New Feature] Restart and recovery for the foundation process<br>I5LO67 [dmsfwk] [New feature] Multi-user adaptation<br>I5I5FV [dmsfwk] [New feature] Singleton ability continuation<br>I5OJD [dmsfwk] [New feature] Automatic component status continuation<br>I5NOA1 [dmsfwk] [New feature] Application information reporting by DMS on the target device| NA |
| DeviceProfile subsystem| The DeviceProfile subsystem supports adaptation to the automatic synchronization policy of the distributed database and supplements the type of information that can be collected.<br>The following requirements are involved:<br>I5QPGN [device_profile] [Enhanced feature] Adaptation to the automatic database synchronization policy<br>I5J7PW [device_profile] [Enhanced feature] Basic DeviceProfile information supplementation| NA |
| Common event and notification subsystem| DLP adaptation is added. Subsystems can send notifications.<br>The following requirements are involved:<br>I582TY [New specifications] DLP adaptation for notifications<br>I582VA [New specifications] DLP adaptation for events<br>I5P1GU [distributed_notification_service] Sending notifications by subsystems| NA |
| Multimodal input subsystem| The following features are added: mouse pointer style and speed setting, configuration of sequential ability startup, and ScreenHop. Mouse event reporting is enhanced.<br>The following requirements are involved:<br>I530UX [New feature] Changing the mouse pointer speed<br>I530VT [New feature] Displaying or hiding the mouse pointer<br>I530XP [New feature] Mouse acceleration algorithm<br>I530XS [New feature] Multiple mouse pointer styles<br>I530UQ [New feature] Distributed input<br>I5HMF3 [Enhanced feature] Event reporting when the mouse pointer leaves the window<br>I5HMEF [Enhanced feature] Enhancement of mouse events<br>I5HMD9 [input] Ability startup based on the configuration of the key event sequence<br>I5P6TG Adaptive display of the mouse pointer in ScreenHop<br>I5P6UW ScreenHop status management<br>I5HMCX [New feature] Enabling or disabling keys on the keyboard<br>I5HMCB [input] Multiple touch targets related to the input device| NA |
| Pan-sensor subsystem| Vibrator priority management is supported.<br>The following requirement is involved:<br>I53SGE [New specifications] Vibrator priority management| NA |
| Distributed data management subsystem| Cross-device and cross-application sharing is supported. The RDB supports remote query, database encryption, and app twin. The KVDB supports backup and restore, condition-based synchronization, and centralized system data synchronization when the device goes online.<br>The following requirements are involved:<br>I5JV75 [New feature] [relational_store] Remote query<br>I5LBDS [New feature] [kv_store] Independent isolation of DLP sandbox application data<br>I5JZM1 [data_object] App twin<br>I5OM83 [kv_store] Condition-based synchronization<br>I5OE57 [New feature] [relational_store] Encrypted database storage<br>I5QN1E [kv_store] Centralized system data synchronization when the device goes online| NA |
| Web subsystem| The webview component supports copy and paste. Basic audio/video playback and HTTPS bidirectional authentication are supported.<br>The following requirements are involved:<br>I5QA3D [New feature] [webview] Content selection and copy on a page with both texts and images<br>I5P97S [Enhanced feature] Input method binding when the W3C input tag is set to autofocus<br>I5P001 [Enhanced feature] [webview] Selecting of multiple texts by holding down Shift<br>I5OZZ8 [New feature] [webview] Text selection by clicking and sliding the left mouse button<br>I5OURV [Enhanced feature] [webview] Optimization of the soft keyboard pop-up effect<br>I5ORNO [New feature] [webview] HTTPS bidirectional verification<br>I5OESN [Enhanced feature] [webview] W3C draggable attribute<br>I5O4BN [New feature] [webview] Connection between the webview pasteboard and system pasteboard<br>I5O4BB [New feature] [webview] Obtaining page images (rendered images)<br>I5O4B5 [New feature] [webview] Pasting plain text based on the input tag<br>I5O4AZ [New feature] [webview] Obtaining plain text on the page<br>I5NXG9 [New specifications] [web] Support for the touch, scroll, and gesture events<br>I5LIL6 [New feature] [web] Message exchange between applications and HTML5<br>I5JTLQ [New specifications] [web] Handle event notification<br>I5HRX9 [New feature] [webview] Basic multimedia playback capabilities| NA |
| Kernel subsystem| The following basic capabilities are added: memory level notification to AMS, reclaim priority management for resident system services, and reclaim priority management based on different Extension ability states.<br>Forward edge CFI is added.<br>The clang compiler is used for kernel compilation.<br>The following requirements are involved:<br>I5K0VE Memory level notification to AMS<br>I5BND4 Reporting to the adj module whether a system application can be restarted after being killed<br>I5BNEC Listening for the association between Service, Data, and Extension abilities<br>I5MXBS Forward edge CFI<br>I5P4FB Enable CFI configurations<br>I5LX3A Building Linux with Clang/LLVM| NA |
| Multimedia subsystem| The following features are added: distributed audio, volume, and device status management; device listening and projection; preview, photographing, and video recording using distributed cameras; metadata management. Connection to 3.5 mm headsets is supported.<br>I5NYBJ [Performance] Media playback start time<br>I5NYCF [New feature] Video hardware encoding based on the HDI codec interface<br>I5NYCP [New feature] Video hardware decoding based on the HDI codec interface<br>I5OOKN [New feature] H.265 video hardware decoding<br>I5OOKW [New feature] H.265 video hardware encoding<br>I5OWXY [New feature] Native audio decoding APIs<br>I5OXCD [New feature] Native audio encoding APIs<br>I5P8N0 [New feature] Native video encoding APIs<br>I5O336 [New feature] Projection of a single-application audio stream or all audio streams in the system<br>I5OEWG [New feature] Setting and obtaining the volume of a single audio stream by system applications| NA |
| Multi-language runtime subsystem| The front-end compilation performance is improved, for example, by using the es2abc component.<br>Runtime performance is improved through ISA reconstruction, assembly interpreter, and TS Ahead of Time (AOT) compiler.<br>New functions are added, such as ES2021 in strict mode, modularization, runtime debugging and tuning enhancement, and bytecode hot reload.<br>The following requirements are involved:<br>I5MYM9 [New specifications] Merging and adaptation of the abc file for multiple modules<br>I59TAQ [New specifications] Standard compilation lowering of the TS AOT compiler and pass description optimization<br>I5OJ8Q [New specifications] Displaying the attribute types defined ES2021 in DevEco Studio<br>I5ODV4 [New feature] Uninstalling bytecode patch files<br>I5OXSC [New feature] Installing bytecode patch files<br>I5HNNZ [New feature] Enabling the namespace of the loader<br>I5HVQE [New feature] Product-specific stack size setting of the thread, and stack page guard<br>I5MCUF [Enhanced feature] New CAPIs of libc and support for symbols such as pthread<br>I5HVNH [New feature] RM.006. Enhanced dynamic library symbol management<br>I5HVQ0 [New feature] RM.008. Fortify supported by musl<br>I5KT7X [New feature] RM.002. API detection for API header files<br>I5TB3Y [New feature] ABI using emutls by default<br>I5R119 [Enhanced feature] Separated use of memory for loader and libc<br>Open-source Clang toolchain<br>I5MYM9 [New specifications] Modular compilation supported by the front-end compiler toolchain<br>I5IKO1 [New specifications] Compiling Commonjs module with the es2abc component<br>I5RRAJ [New specifications] Patch file source code identification tool<br>I5PRFT [New specifications] Patch bytecode compiler<br>I5RHDH [New specifications] Hot loading of ArkCompiler bytecode<br>I5RA7C [New specifications] Support for ES2021 in strict mode<br>I5HRUY [New specifications] Converting from JS code to ArkCompiler bytecode by the es2abc component| NA |
| IAM account subsystem and program access control subsystem| User identity authentication is added to the IAM account subsystem. The permission service supports precise positioning and fuzzy positioning, and other capabilities are enhanced. The privacy management service is provided.<br>The following requirements are involved:<br>I5N90B [New specifications] Application accounts adaptation to sandbox applications<br>I5N90O [New specifications] User identity authentication of the IAM account subsystem<br>I5NOQI [New feature] Precise positioning and fuzzy positioning of the permission service<br>I5NT1X [New feature] Enhanced permission usage record management<br>I5NU8U [New feature] Improved UX effect for the permission request dialog box<br>I5P4IU [New feature] Privacy management<br>I5P530 [New feature] Location service usage status management| NA |
| Globalization subsystem| The pseudo-localization capability is added.<br>The following requirement is involved:<br>I4WLSJ [New feature] Pseudo-localization| NA |
| Misc services subsystem| The following basic module features are added: pasteboard, upload and download, screen lock, and input method framework.<br>The following requirements are involved:<br>I5JPMG [request] [download] Background task notification<br>I5NXHK [input_method_fwk] Binding of only the innerkits interface of the input method and the JS interface that independently controls the display and hiding of the soft keyboard<br>I5NG2X [theme_screenlock] Screen lock requested by specific system applications<br>I5IU1Z Adding image data to pasteboard data<br>I5OGA3 Pasteboard plugin loading switch<br>I5NMKI [pasteboard] Adding binary data to pasteboard data<br>I5MAMN Limiting the pasteboard data range to within the application<br>I5OX20 [input_method_fwk] Added the API for obtaining the input method| NA |
| ArkUI development framework| The following capabilities are enhanced: ArkUI component, resource and media query, DFX, and toolchain. The memory and performance are optimized.<br>The following requirements are involved:<br>I5IZZ7 [ace_engine_standard] Separate **borderRadius** setting for each corner by the **\<panel>** component<br>I5JQ1R [ace_engine_standard] Image copy and paste<br>I5JQ3F [ace_engine_standard] Enhanced text box capabilities<br>I5JQ3J [ace_engine_standard] Event topology of the **\<stack>** component<br>I5JQ54 [ace_engine_standard] Specifying a component to get the focus<br>I5MX7J [ace_engine_standard] Left sliding, right sliding, and rebound effect of the **\<list>** component<br>I5MWS0 [ace_engine_standard] Height notification of the **\<panel>** component<br>I5IZVY [ace_engine_standard] Component refresh upon the keyboard and mouse connection<br>I5JQ5Y [ace_engine_standard] Enhanced focus navigation<br>I5IY7K [New requirement] [ace_engine_standard] Theme capability<br>I5MWTB [ace_engine_standard] vp query for media<br>I5IZU9 [ace_engine_standard] Optimization of the resident memory of ui_service<br>I5JQ26 [ace_engine_standard] Optimized Vsync request mechanism<br>I5JQ2O [ace_engine] Preloading of public resources<br>I5JQ2D [ace_engine_standard] Optimized resampling of move events<br>I5IZXS [toolchain] Display of the plaintext of the developer variable name in the DFX error stack print<br>I5IZYG [toolchain] Display of the plaintext of the developer variable name in the DFX error stack print<br>I5IZX0 [toolchain] Adding the **bundleName** and **moduleName** parameters to **$r** during compilation<br>I5J09I [toolchain] Export of \@Builder| NA |

For details about the API changes, see the following:

[API Differences](api-diff/v3.2-beta3/js-apidiff-ability.md)


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

  **Table 4** New samples

| Subsystem| Name| Introduction| Programming Language|
| -------- | -------- | -------- | -------- |
| ArkUI development framework| [HealthyDiet](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/HealthyDiet)| This sample app helps you keep food records and view food information. After you add food records, including the food type, weight, and meal time, the app can calculate nutrition data (calories, proteins, fats, and carbon water) for the meals and display the data in a bar chart.| ArkTS |
| ArkUI development framework| [MusicAlbum](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/MusicAlbum)| This sample shows the home page of a music album app. The adaptive layout and responsive layout are used to ensure that the app can be properly displayed on devices irrespective of screen sizes.| ArkTS |
| Ability framework and file management subsystem| [CustomShare](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/CustomShare) | Using this sample app, you can share texts, links, and images with third-party applications and display them in these applications.| ArkTS |
| Ability framework| [GalleryForm](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/FormExtAbility) | This sample demonstrates the display of **Gallery** images in a widget and periodic update of the widget.| ArkTS |
| ArkUI development framework| [AppMarket](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/AppMarket) | This sample shows the home page of an application market, which contains the tab bar, banner, featured apps, and featured games.| ArkTS |
| ArkUI development framework| [Weather](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Weather) | This sample demonstrates one-time development for multi-device deployment by showing how to develop a weather app and deploy it across different devices. The demo app includes the following: home page, **Manage City** page, **Add City** page, and **Update Time** page.| ArkTS |
| Multimedia subsystem| [MediaCollections](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/MediaCollections) | This sample shows the capabilities of online streaming, audio and video playback control, and volume adjustment.| ArkTS |

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).


## Resolved Issues

  **Table 5** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| I5I4GJ | There is a possibility that the RK3568 device is disconnected from DevEco Studio.|
| I5HTGF | The photo taken is rotated by 90 degrees clockwise when compared with the preview image.|
| I5FUNB | There are no patches for the known Linux kernel vulnerabilities yet.<br>CVE-2022-1462 |



## Known Issues

  **Table 6** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I59PWR | In the memory usage test performed on the RK3568 device, the actual value of the com.ohos.launcher process is 84279 KB, which exceeds the baseline value by 200 MB.| Though the process consumes more memory than what is expected, it does not affect the overall memory usage of the system.| October 20|
| I59QII | In the resident memory test performed on the RK3568 device, the actual value of the netmanager process is 3884 KB, which exceeds the baseline value (1241 KB) by 2.58 MB. In the memory test, the actual value of the netmanager process exceeds the baseline value (1241 KB) by 1 MB.| Though the process consumes more memory than what is expected, it does not affect the overall memory usage of the system.| October 20|
| I5LH57 | In the resident memory test performed on the RK3568 device, the actual value of the telephony process is 10329 KB, which exceeds the baseline value (8434 KB) by 1.85 MB.| Though the process consumes more memory than what is expected, it does not affect the overall memory usage of the system.| October 20|
| I5Q5PR | In the resident memory test performed on the RK3568 device, the actual value of the wifi_hal_service process is 4374 KB, which exceeds the baseline value (829 KB) by 3.4 MB.| The memory usage exceeds the expected value, but the memory usage of the entire system is not affected. The baseline value has been met, and no function is affected.| October 20|
| I5T71O | In the dynamic memory test performed on the RK3568 device, the actual value of the com.ohos.settings process is 76123 KB, which exceeds the baseline value (15824 KB) by 58.8 MB.| Though the process consumes more memory than what is expected, it does not affect the overall memory usage of the system.| October 20|
| I5S40B | The actual sliding frame rate of **Contacts** is 30.3 fps, which is less than the baseline value (54 fps) by 23.7 fps.| The load success rate is affected. This issue depends on the ArkUI framework reconstruction.| October 15|
| I5MVDK | A crash occurs when a socket fuzz test is performed on **/data/data/.pulse_dir/runtime/cli**.| The process crashes during the test.| October 18|
| I5M3UO | [TTE WRC team] There is new line injection via the Wi-Fi SSID in the wifi_manager_service.| If the Wi-Fi SSID contains invalid characters (\n), an exception occurs when saving or parsing the configuration file.| October 12|
| I5T8FV | The verification permission is not defined in the system and does not take effect.| The authentication fails. No process can request the permission. Currently, no service uses this permission.| October 18|
