# OpenHarmony 3.2 Beta1

## Version Description

OpenHarmony 3.2 Beta1 provides the following enhancements over OpenHarmony 3.1 Release:

**Enhanced basic capabilities for the mini system**

The inter-process communication (IPC) mechanism is normalized for LiteOS and Linux running on the mini system.

**Enhanced basic capabilities for the standard system**

ARM64 build is supported.

The graphics system supports secure screen capturing and screen recording. It also supports application window display over other applications.

The window manager subsystem supports quick switching to the home screen and restoration of application windows. It also supports screen wakeup, screen always-on, and screen brightness adjustment from the window, as well as security layer.

Ark VMs support multi-instance debugging, conditional breakpoints, and watch expressions.

The multimodal input subsystem supports hot swap listening of the remote control, mouse, and keyboard.

The security subsystem supports mutual authentication between OpenHarmony devices using the same account.

**Enhanced distributed capabilities for the standard system**

System service management is enhanced to support group verification.

**Enhanced application framework capabilities for the standard system**

ArkUI allows an ability to be displayed in other applications as a component. The **\<Column>** and **\<SideBarContainer>** components are enhanced to support automatic hiding.

Bundle management supports installation, uninstall, and query of sandbox applications. The unpacking tool supports the stage model.

The stage model supports the Worker mechanism. DFX features, such as Application Not Response (ANR) and suspension detection of an application's main thread, are added.

**Enhanced application capabilities for the standard system**

The Gallery application supports basic dynamic effects, image editing and saving, and OEM customization.

**Application development samples for the standard system** 

Multiple sample apps, including GPU drawing, minesweeper game, and 2048 game, are provided to help developers quickly use the basic capabilities of OpenHarmony.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.2&nbsp;Beta1 | NA |
| SDK | Ohos_sdk_full&nbsp;3.2.2.5 (API&nbsp;Version&nbsp;9 Beta1) | NA |
| (Optional) HUAWEI DevEco Studio| 3.0 Beta3 for&nbsp;OpenHarmony | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI DevEco Device Tool| 3.0 Release | Recommended for developing OpenHarmony devices|


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
  repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta1 --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

- Obtain the source code from the version tag, which is the same as that released with the version.
  ```
  repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta1 --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
  ```
  repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta1 --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```
- Obtain the source code from the version tag, which is the same as that released with the version.
  ```
  repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta1 --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base (for mini, small, and standard systems)       | 3.2 Beta1  | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/code-v3.2-Beta1.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/code-v3.2-Beta1.tar.gz.sha256)|
| RK3568 standard system solution (binary)       | 3.2 Beta1  | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/standard_rk3568.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_rk3568.tar.gz.sha256)|
| Hi3861 mini system solution (binary)       | 3.2 Beta1  | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_pegasus.tar.gz.sha256) |
| Hi3516 mini system solution - LiteOS (binary)| 3.2 Beta1  | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus.tar.gz.sha256) |
| Hi3516 mini system solution - Linux (binary) | 3.2 Beta1  | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus_linux.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus_linux.tar.gz.sha256) |
| Standard system SDK package (macOS)                   | 3.2 Beta1  | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/ohos-sdk-mac.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/ohos-sdk-mac.tar.gz.sha256)|
| Standard system SDK package (Windows/Linux)         | 3.2 Beta1  | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/ohos-sdk.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/ohos-sdk.tar.gz.sha256)|

## What's New

This version has the following updates to OpenHarmony 3.1 Release.


### Feature Updates

**Table 3** New and enhanced features

| Subsystem| Standard System| Mini and Small Systems|
| -------- | -------- | -------- |
| Common| ARM64 build is supported.| The same set of IPC APIs is provided for the mini and small systems.|
| Resource scheduling| Statistics on widget usage can be collected.<br>The following requirements are involved:<br>I531ST Deleting the usage records of a widget once it is uninstalled<br>I531SU Querying and obtaining widget usage records<br>I531SV Recording the widget usage count and usage duration| NA |
| Multimodal input| Listening for hot swap events of the remote control, mouse, and keyboard is supported<br>The following requirements are involved:<br>I530U7 Third-party JSON version upgrade<br>I530UH Startup optimization<br>I530UU Tailoring the mouse cursor display<br>I530UL Non-touchable window<br>I530W5 Using JS APIs to listen for hot swap events of the remote control<br>I530W9 Using JS APIs to listen for hot swap events of the mouse<br>I530WB Using JS APIs to query extended information about the touchpad<br>I530W9 Using JS APIs to listen for hot swap events of the keyboard<br>I530UW Tailoring the configuration of combined keys| NA |
| System service management| Group verification is supported.<br>The following requirements are involved:<br>I59XYB Adding group verification<br>I53NZQ Processing the installation status and version number of a remote application<br>I568AO Reporting the association between distributed components by DMS<br>I58ZSB Collecting OS type information| NA |
| Bundle management| - Installation, uninstall, and query of sandbox applications are supported.<br>- The unpacking tool supports the stage model, and the capability of the packing tool is enhanced.<br>The following requirements are involved:<br>I524WG Specifying whether data of system applications can be cleared<br>I524WP Querying whether a specified application is installed<br>I524UF Supporting the update of system features (with entry installed)<br>I524VP Supporting ability priority for implicit query<br>I56W2U Supporting the BackupExtension type<br>I56W68 Packing pack.info into the HAP file<br>I56W6W Packing the old and new HAP files into the same APP Pack<br>I56W4O Extracting the rpcid file using the unpacking tool<br>I56W59 Parsing the stage model package using the unpacking tool<br>I56W7H Sending a scanning complete event after BMS scanning is complete<br>I56WIG Installation of sandbox applications<br>I56WIS Uninstall of sandbox applications<br>I56WJ7 Sandbox application information query| NA |
| Basic communications| Access from human-machine interface devices is supported.<br>The following requirement is involved:<br>I58ZUA Access from human-machine interface devices, such as Bluetooth keyboard, mouse, and game controller| NA |
| Ability| - The FA model supports ability-level screen orientation query and setting, lock screen display, and screen-on during ability startup.<br>- More DFX features are added, including ANR and suspension detection of an application's main thread.<br>- The stage model supports the Worker mechanism.<br>The following requirements are involved:<br>I58ZRH Ability-level screen orientation query and setting in the FA model<br>I58ZRI Lock screen display for an ability in the FA model<br>I58ZRJ Screen-on during ability startup in the FA model<br>I58ZRD Automatic generation of Extension JS server and client interface files using the ZIDL tool<br>I58ZR5 Interception of uncatched exceptions<br>I58ZR6 ANR processing<br>I58ZR7 Thread suspension detection of the ability manager service<br>I58ZR9 Suspension detection of an application's main thread<br>I58ZRA Timeout detection of ability lifecycle transition<br>I58ZR1 FA widget capability supplement - deleting invalid widgets<br>I58ZR2 FA widget capability supplement - separate setting of the visibility status and update status of widgets<br>I58ZQR Ability listeners<br>I58ZQW APIs related to the scheduling component lifecycle<br>I50DOL Worker mechanism in the stage model| NA |
| Multimedia| - The OpenSL ES recording APIs are added.<br>- The HiStreamer engine supports audio playback for the standard system.<br>The following requirements are involved:<br>I58ZOI Settings and obtaining the total volume<br>I58ZOJ Audio-related user permission control<br>I58ZOM OpenSL ES basic recording APIs<br>I59H9F Audio playback supported by the HiStreamer engine for the standard system| NA |
| Graphics| - Secure screen capturing and screen recording are supported.<br>- An application's window can be displayed in other applications.<br>The following requirements are involved:<br>I58ZOX GPU compositing supported by RenderService<br>I58ZOU Secure screen capturing and screen recording (security layer)<br>I58ZOW Cross-screen window display in the case of extended screens and splicing screens<br>I58ZOT Window embedding into other applications| NA |
| Window manager| - Quick switching to the home screen and restoration of application windows are supported.<br>- Screen wakeup by window is supported.<br>- The window can be used to keep the screen always on and adjusts the screen brightness.<br>- The security layer is supported.<br>- The window focusable and touchable attributes are added.<br>- The window orientation can be set.<br>- The window of an application can be displayed on a locked screen.<br>- Window decoration is supported.<br>- The main window of an application can be displayed in full screen.<br>- An application can exit window control.<br>- The application UI combination capability is provided for system applications.<br>The following requirements are involved:<br>I58ZP0 Setting of the display density<br>I58ZP1 Quick switching to the home screen and restoration of application windows<br>I58ZP4 Screen wakeup by window<br>I58ZP5 Screen always-on and screen brightness adjustment by window<br>I58ZP6 Security layer<br>I58ZP7 Obtaining the window focusable and touchable attributes<br>I58ZP8 Window orientation setting<br>I58ZPA Window display on a locked screen<br>I58ZPD Window decoration<br>I58ZPE Full-screen display for the main window<br>I58ZPG Exit window control by application<br>I58ZPI Window launch by application<br>I58ZPJ Application UI combination capability for system applications| NA |
| Network management| - WebSocket JS APIs are added.<br>- The **system.fetch** APIs are now compatible.<br>- The **system.network** APIs are now compatible.<br>The following requirements are involved:<br>I53CKH Supporting the **system.fetch** APIs<br>I53CKT WebSocket support<br>I53CJX Supporting the **system.network** APIs| NA |
| Globalization| - APIs for synchronously obtaining resources are provided. Resources can be obtained by resource name. Resources of the float type can be obtained.<br>- MCC/MNC qualifiers are supported.<br>- Independent compilation of different modules in an application is supported.<br>- The locale-specific date format is supported.<br>- Transliteration is supported, for example, converting Chinese characters into Hanyu Pinyin.<br>The following requirements are involved:<br>I596AO Supporting MCC/MNC qualifiers<br>I58ZSE Enhanced resource management APIs<br>I58ZSG Resource ID generation<br>I4WM02 Transliteration<br>I4WK2O Date format| NA |
| ArkUI | - The layout boundaries can be displayed for different components.<br>- The mouse operation of the **XComponent** is enhanced, the layout adjustment when the input method is displayed is optimized, and the application performance is optimized.<br>- The **\<Column>** and **\<SideBarContainer>** components can be automatically hidden when they are dragged to a width that is less than the minimum width.<br>- The **\<AbilityComponent>** component is added so an ability can be embedded into other applications as a component for display.<br>The following requirements are involved:<br>I58ZPY Decoding down-sampled images for higher performance<br>I58ZPX CPU frequency increase to optimize the animation performance<br>I58ZPW **\<AbilityComponent>** component support<br>I58ZPS **XComponent** mouse event<br>I58ZPR Automatic layout when the input method app is started from the text box<br>I58ZPQ Automatically hiding of the **\<Column>** and **\<SideBarContainer>** components when they are dragged to a width that is less than the minimum width<br>I58ZPP Layout boundary display for the drawing and auxiliary components<br>I58ZPO Layout boundary display for the button, selection, information display, and dynamic effect components<br>I58ZPN Layout boundary display for text, input, image, video, and media components| NA |
| Program access control| - Security Enhanced Linux (SELinux, also known as label protection) is provided for service and hdf_service.<br>- Permission configuration and validation capabilities are provided for native services.<br>The following requirements are involved:<br>I58ZO1 SELinux for service<br>I58ZO2 SELinux for hdf_service<br>I58ZO3 accessToken-based permission verification for native services| NA |
| Utils| TypedArray and SharedArrayBuffer support ECMAScript 2021.<br>The following requirements are involved:<br>I58ZPZ TypedArray ECMAScript 2021 support<br>I58ZQ0 SharedArrayBuffer ECMAScript 2021 support| NA |
| Multi-language runtime| Ark VMs support multi-instance debugging, conditional breakpoints, and watch expressions.<br>The following requirements are involved:<br>I58ZQE Multi-instance debugging<br>I58ZQD Conditional breakpoints<br>I58ZQB Watch variables and expressions<br>I58ZQ8 Code generated by the Ahead of Time (TSAOT) compiler supporting the garbage collector (GC) of ArkCompiler JS Runtime<br>I58ZQ7 Quality back-end machine code generated by the TSAOT compiler| NA |
| Update| Adaptation to RK3568 is added.<br>The following requirements are involved:<br>I58ZSM RK 3568 update adaptation support by update_service<br>I58ZSO RK 3568 update adaptation support by updater| NA |
| Misc services| The HTTP file upload and download APIs that were available before API version 6 are supplemented.<br>The following requirements are involved:<br>I58ZSC [download] Supporting the **\@system.request** APIs<br>I53J82 [upload] Supporting the **\@system.request** APIs| NA |
| File management| - Configuration of special sandboxes is supported.<br>- Third-party applications are provided with the storage query capability.<br>The following requirements are involved:<br>I58ZS6 Differentiated configuration of application sandboxes<br>I58ZS9 Storage query capability for third-party applications<br>I58ZSA Adaptation to new HUKS HAL APIs<br>I58ZS3 Version update of the distributed user data access framework| NA |
| Common event and notification| - Agent-powered notification is added to support sending of notifications on behalf of third-party applications.<br>- The notification slot query and setting capabilities are enhanced.<br>The following requirements are involved:<br>I582UB Agent-powered notification<br>I582TF Enhancement of notification slot setting and query| NA |
| Pan-sensor| The adaptation to the ambient light sensor is added.<br>The following requirements are involved:<br>I53784 Continuous integration of pan-sensor capabilities - ambient light sensor<br>I538PX System API synchronization| NA |
| Distributed data management| Distributed data object samples are added.<br>The following requirement is involved:<br>I4WO0S Distributed data object samples| NA |
| Driver| - Kernel drivers can be dynamically loaded.<br>- The HAL capability of the peripheral module is enhanced and the HDIs are optimized.<br>The following requirements are involved:<br>I4UD9W Dynamic driver loading in the kernel space to improve the device driver development and debugging efficiency<br>I54566 Rectification of the camera service and HDI cyclic dependency<br>I50I6S Unified audio APIs for the IPC mode and direct debugging mode<br>I54FQG Driver model of codec devices<br>I544XP SELinux permission check for the HDF service<br>I4UL98 ADC adaptation to the IIO framework of the Linux kernel| NA |
| Build| - The HAP files provided by the stage model can be compiled along with the code.<br>- Third-party open-source software can be used as an independent part. When other parts depend on this software, the build subsystem automatically installs the software to the image, without the need for the configuration in the product list.<br>- Python, Jinja2, and MarkupSafe are updated.<br>- The device type can be customized during build.<br>- The user and root versions are built separately.<br>- The strip operation can be configured for the precompiled module.<br>- The product configurations are normalized for different device types.<br>The following requirements are involved:<br>I53FCL The HAP files provided by the stage model can be compiled along with the code.<br>I54ZLX Third-party open-source software can be used as an independent part. When other parts depend on this software, the build subsystem automatically installs the software to the image, without the need for the configuration in the product list.<br>I54ERB/I52MRL/I52KTV Updating the open-source software that is identified as EOM by cleansource 3.1.<br>I5714O Customization of ohos.para<br>I4Q9MI Strip operation for the precompiled modules<br>I56M93 Normalized product configurations for different device types| - Python, Jinja2, and MarkupSafe are updated.<br>- The user and root versions are built separately.<br>The following requirements are involved:<br>I54ZLX Third-party open-source software can be used as an independent part. When other parts depend on this software, the build subsystem automatically installs the software to the image, without the need for the configuration in the product list.<br>I54ERB/I52MRL/I52KTV Updating the open-source software that is identified as EOM by cleansource 3.1.<br>I4Q9MI Strip operation for the precompiled modules|
| Test| - Test cases to be executed can be filtered by type, granularity, and level.<br>- The UI test framework provides APIs such as sliding search.<br>- The executor supports component-based execution and re-test of failed cases.<br>- The stability tool supports report parsing, generation, and display, and component injection.<br>The following requirements are involved:<br>I58ZUJ Test case filtering<br>I58ZUK Enhanced UI test framework capability: more APIs<br>I58ZUM Enhanced UI test framework capability: UI-dump function<br>I58ZUR Enhanced UI test framework capability: customized UI operation parameters<br>I58ZUS Configuration of the test scheduling framework<br>I58ZUU Componentization of the test scheduling framework<br>I58ZUV Parsing, generating, and displaying of stability reports by the stability tool<br>I58ZUW Component injection of the stability tool| NA |
| Basic security capabilities| Mutual authentication is now available between OpenHarmony devices based on the sample login account.<br>The following requirements are involved:<br>I58ZNS Mutual authentication between OpenHarmony devices based on the same login account<br>I58ZNR Removing account authentication credentials from OpenHarmony devices after an account is logged out or removed<br>I58ZNP Importing and removing of trust records of accounts from different vendors (same vendor or OEM vendor) for OpenHarmony devices<br>I58ZNT Importing of account authentication credentials (asymmetric credentials) to OpenHarmony devices after an account is logged in or bound| NA |
| System applications| The Gallery application supports image editing and dynamic effects.<br>The following requirements are involved:<br>I58ZQ3 [Gallery] Image editing<br>I58ZQ1 [Gallery] Dynamic effects<br>I58ZQ4 [Contacts] Basic capability - 2D capability| NA |

### API Updates

*[API Differences](api-diff/v3.2-beta1/Readme-EN.md)*

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

**Table 4** New samples

| Subsystem| Sample| Introduction| Programming Language|
| -------- | -------- | -------- | -------- |
| ArkUI | [Vibrator](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator) | This sample simulates the countdown scenario to show the use of the vibrator APIs.| ArkTS |
| DFX | [FaultLogger](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/FaultLogger) | This sample illustrates how to obtain fault information of an application in ArkTS.| ArkTS |
| ArkUI | [ComponentCollection](https://gitee.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentClollection/ComponentCollection) | This sample illustrates all the components, animations, and global methods of ArkUI.| ArkTS |
| ArkUI | [ArkTSClock](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/ArkTSClock) | This sample exemplifies how to implement a simple clock application using the ArkTS UI capability. | ArkTS |
| Network management| [Http](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Http) | This sample simulates Postman, which requires the input of an API address and outputs the data obtained, to show the use of the data request APIs.| ArkTS |
| Network management| [Socket](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Socket) | This sample demonstrates the application of Socket in network communication, including connection authentication and chat communication between two devices.| ArkTS |
| Distributed data management| [DistributedRdb](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedRdb) | This sample shows how to add, delete, modify, query, and synchronize data in the distributed relational database with ArkTS.| ArkTS |
| Ability| [WorkScheduler](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/WorkScheduler) | This sample simulates the update process starting from downloading and saving an update package to sending a notification and installing the update package. Being processed by the background task management, the download task continues after the application exits. It stops until the download is complete.| ArkTS |
| Ability| [AbilityStartMode](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/AbilityStartMode) | This sample shows how to implement the standard, singleton, and specified ability launch modes in the stage model.| ArkTS |
| Multimedia| [MediaCollections](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/MediaCollections) | This sample illustrates media management in ArkTS, including network stream playback, audio and video playback control, and volume adjustment.| ArkTS |
| Ability| [ArkTSDistributedCalc](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/ArkTSDistributedCalc) | This sample implements a simple calculator application using JS distributed features. The calculator can perform simple numerical calculations and start a remote calculator FA to perform collaborative calculation.| ArkTS |
| Web | [Browser](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser) | This sample uses the stage model and related APIs to show a simple browser.| ArkTS |
| Ability| [DeviceUsageStatistics](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceUsageStatistics/DeviceUsageStatistics) | This sample shows the device usage statistics.| ArkTS |
| ArkUI | [AdaptiveCapabilities](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/AdaptiveCapabilities) | This sample shows multi-device adaptation in ArkTS, including resource qualifiers, atomic layouts, and responsive layouts.| ArkTS |
| ArkUI | [Game2048](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Game/Game2048) | This sample shows how to develop a 2048 game using the **\<Grid>** component.| ArkTS |
| Typical Setting Page of One-Time Development for Multi-Device Deployment| [Settings](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Settings) | This sample shows a typical page for setting an application. The page has different display effects in the small window and large window, reflecting the capability of one-time development for multi-device deployment.| ArkTS |
| Distributed data management| [Preference](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DataManagement/Preferences) | This sample shows the theme switching function of preferences.| ArkTS |
| Globalization| [International](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Internationalnation/International) | This sample shows how to use APIs related to i18n, intl, and resourceManager in ArkTS to set the system language, region, time, and time zone. It also provides locale setting examples.| ArkTS |

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).

## Resolved Issues

**Table 5** Resolved issues

| Issue No.                                                     | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I4NRS5](https://gitee.com/openharmony/kernel_linux_5.10/issues/I4NRS5) | [Kernel subsystem] A CVE vulnerability exists.                                   |


## Known Issues

**Table 6** Known issues

| Issue No.                                                       | Description                                                  | Impact                                                        | To Be Resolved By|
| ------------------------------------------------------------ | ---------------------------------------------------------- | ------------------------------------------------------------ | ------------ |
| [I4Z3G9](https://gitee.com/openharmony/graphic_graphic_2d/issues/I4Z3G9) | [RK3568] Screen flickering occurs when the secondary window is opened in the immersive primary window.| Developer experience is affected.                                              | 2022-06-15   |
| [I59M4Q](https://gitee.com/openharmony/developtools_hdc/issues/I59M4Q) | There is a low probability that the device is disconnected when hdc_std of API version 9 is used to connect to the device.                      | This issue occurs at a low probability (less than 1/30). It can be resolved by restarting the IDE or hdc_std.| 2022-06-30   |
