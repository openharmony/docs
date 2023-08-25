# OpenHarmony 4.0 Beta2

## Version Description

The standard system capabilities of OpenHarmony 4.0 are continuously improved. ArkUI further enhances the capabilities of basic components. The application framework supports ArkTS widget updates triggered by agents. The bundle manager subsystem supports data sharing across atomic services, as well as enterprise application installation. The DSoftBus subsystem supports session-level transmission capability negotiation. The Unified Data Management Framework (UDMF) supports temporary authorization for files in distributed directories in cross-device dragging scenarios. The file management subsystem supports device-cloud synchronization of public image files. The multimedia subsystem further enhances the audio, media playback, and audio/video codec capabilities. The graphics rendering library is upgraded to Skia 0310. The window component capability is enhanced. The common event and notification subsystem supports batch notification deletion. The security subsystem supports Digital Signature Algorithm (DSA). ArkCompiler Runtime supports JSContext and dynamic profile guided optimization (PGO). DFX provides a unified collection framework for easier application debugging.

## Feature Description


### Application Framework

- The content of an ArkTS widget can be updated through a data agent.

- Static configuration and static graph display are provided for ArkTS widgets.


### ArkUI

- **\<XComponent>** supports texture rendering. Popup positions can be customized, and popups can be closed layer by layer by pressing the **Esc** key. The **\<ListItem>** component supports the swipe-to-delete gesture, which means that users can long swipe left to delete an element. ArkTS/JS widgets support callbacks triggered upon the completion of rendering. The **\<Image>** and **\<Text>** components support obscuring. The **\<ContextMenu>** component supports segment-based display.

- The animation effect is enhanced, including the layout attribute, background image size and position, and show/hide attribute (implicit animation). **scrollToIndex** can be used to set animation effects for lists. Fuzzy animations are provided for tabs, and display/disappearance animations are provided for popups. Custom animations are also supported.

- Named routes are supported so that page-specific switching animations can be set. The lite ArkUI framework supports global data objects and data sharing between pages within an application.

- Global APIs support the stage model multiton scenario.


### Bundle Management

- APIs are provided to set and query the application distribution type and attachment information.

- Applications that can open a file are identified through the file name extension, implementing the mapping between a file name extension and an application.

- Enterprise applications can be installed. To install an application whose certificate type is **enterprise**, you must request the **ohos.permission.INSTALL_ENTERPRISE_BUNDLE** permission.


### Distributed Data Management

- The UDMF supports temporary authorization for files in distributed directories in cross-device dragging scenarios.

- RDB store NDK interfaces are provided. These interfaces are used for transaction addition, deletion, modification, and query, data encryption, hierarchical data protection, and backup and restore.

- The system can automatically select a Bluetooth or Wi-Fi P2P channel for synchronization of key-value and distributed data objects based on the data volume.


### DSoftBus

- Management of soft bus link information is supported.

- Cross-device transmission capability negotiation is provided at the session level.


### Distributed Hardware

- The audio recording latency in distributed scenarios is optimized.

- The distributed file system supports mutual file access over Bluetooth P2P connections.

- A listener can be provided to listen for device name changes.


### File Management

- Public image files can be synchronized between the device and cloud (on the prerequisite that the cloud service is enabled for the login account of the device). Images on the cloud can be selected through the picker.

- Applications can customize the directories to be backed up.

- Public images can be managed by category. Users can classify user images through albums in Gallery.

- Applications can listen for the addition, modification, and deletion of files in the sandbox.

- Applications can share files in the sandbox across devices.


### Graphics & Window

**Graphics**

- APIs are provided to pick the color of a selected region in an image. Applications can use the APIs to select a region in an image and obtain its dominant color and average color value.

- APIs are provided to set the offset of the rotation center on the z-axis anchor point so that the rendered anchor point can be modified during rotation.

- The rendering library on which the graphics subsystem depends is upgraded to Skia 0310.

**Window**

- The way for obtaining the parameter values of the display module is optimized. Now actual parameter values are directly obtained from the hardware instead of the software.

- The window component capability is enhanced. The window supports window attributes, child windows, modal windows, window effects, window decoration, screen-on/screen-off, screenshot, and screen recording in component mode.


### Multimedia

**Audio**

- The sound effect framework is supported. Device vendors can configure sound effect policies and load custom sound effects. Applications can query, switch, or disable the sound effect mode.

- Intra-system recording is supported. Audio data played in the system can be filtered and recorded based on the audio scene attribute.

- The display name of the audio output device can be obtained from the playback object information.

**Media Playback**

Audio effect parameters can be configured.

**Audio/Video Codecs**

- Native APIs can be used to query the audio and video codecs of the system.

- Native APIs can be used to encapsulate audio and video data, that is, to store encoded media data in files in a certain format.

- Native APIs can be used to decapsulate audio and video data, that is, to extract media frame data from bit stream data.


### Common Event and Notification

- Notifications can be deleted in batches.

- The emitter supports unsubscription of condition-specific callbacks.


### Basic Communications

- The Wi-Fi module supports background scanning.

- The Wi-Fi module supports random MAC addresses in STA mode.


### Network and Communication

- A TCP socket can be used for communication with the server.

- Data transfer to a remote server is supported.

- HTTPS certificate management adaptation is supported.

- The NIC proxy is supported.


### System Service Management

- System services can be started as required, for example, called by external systems or triggered by events. System services can be automatically stopped when the device is idle.

- The system service configuration format is optimized by using the JSON format instead of the XML format.


### Power Supply

- New APIs are provided to enable the system to enter the sleep state immediately.

- Events and behavior can be customized based on the hibernation source.

- Wakeup events can be customized based on the wakeup source.


### Multimodal Input

- Original events of keyboard input devices are mapped to the intent event of normalized interaction, so that you do not need to pay attention to whether the input behavior comes from the touch or keyboard during application development.

- Users can customize the touchpad based on their use habits.
  - Both the press and touch actions can be used to map a click on the left mouse button.
  - Both of the following actions can be used to map a right-click on the mouse: touching the left or lower right corner, and pressing or touching the left or lower right corner with two fingers.
  - 10 speed levels are supported.
  - Both of the following actions can be used to map a scroll with mouse: content moving in the same direction as your finger moves, and content moving in the reverse direction as your finger moves.


### Theme Framework

- The lock screen management service supports lock screen event callbacks, static/dynamic wallpaper, and service status query when the screen is locked.

- The wallpaper management service allows users to customize and reset wallpapers, and lock/unlock the screen.


### Upload and Download

Users can query upload and download tasks, synchronize and query task status, persistently store task records, and rectify exceptions.


### Security

**Crypto Framework**

- DSA is supported.

- APIs are provided to parse DSA, Elliptic Curve Cryptography (ECC), and Rivest Shamir Adleman (RSA) keys and obtain key parameters.

- APIs are provided to obtain the algorithm type used to generate random numbers.

- APIs are provided to randomly generate, convert, encrypt, and decrypt SM4 keys.

- The Hash-based Message Authentication Code (HMAC) and hash capabilities are provided for SM3 keys.

- APIs are provided to randomly generate, convert, sign, verify, encrypt, and decrypt SM2 keys.

**Key Management**

- HUKS key encryption is supported.

- The service identity field of the key can be added to the Key Attestation public key certificate.

- Standard HDIs are provided.

**Mutual Authentication Between Devices**

Pseudonyms can be generated and identified in the following scenarios:

- Mutual authentication on multiple devices that use the same account to log in

- Mutual authentication on two devices that are connected in P2P mode using different accounts


### Ability Access Control

- The display of the permission management menu is optimized. The permission groups of media assets and files are split, and the authorization granularity of corresponding permissions is more refined.

- Compatibility with SELinux in the Treble architecture is supported.


### Account

- Third-party applications can use the account authorization capability.

- Management on domain account plugins is provided to support domain account management and authentication.


### WebView

- The web camera capability and HTML5 tag capabilities such as bindContextMenu, Select, and date input are supplemented.

- Multiple rendering processes can be split.

- Basic text and image dragging capabilities are provided.

- WebRTC video conferencing (excluding camera sharing) is supported.

- Independent SELinux labels are provided for rendering processes to enhance basic security.


### ArkCompiler

- ArkCompiler Runtime supports JSContext and dynamic PGO, which collects type and function hotspot information at runtime and generates AP files. The NAPI library can be dynamically imported and loaded.

- In type compilation mode of ArkCompiler, the front-end compilation toolchain is switched to es2abc.

- New APIs are provided for the NAPI buffer, object, arraybuffer, and object types.

- The task pool supports task interruption and cancellation, task group definition, task status and scheduling information dotting, and identification and recovery of tasks that wait for a long time.

- Different versions can be built for system users and user **root**. The user version supports Wukong and XTS.

- The compiler toolchain supports debugging of the previewer.


### DFX

- A unified collection framework is provided for application debugging.

- Unified trace collection is provided.

- Native HiTraceMeter APIs are provided.

- The performance radar provides tool classes for service modules (subsystems) to transfer performance tracing point records and settlement performance data in service processes.


### Kernel

Code execution permission control is enhanced as follows:

- Secure memory is supported.

- Scenario-specific code execution permission control policies are provided.

- Full lifecycle management is provided for code execution permission control.

- Executable files can be parsed to obtain code segment information.

- Integrity protection is provided for code pages.


### Driver

- The extended device driver framework provides the following capabilities:
  - Based on the DriverExtensionAbility, the extended device driver framework builds lifecycle management capabilities, including developing, deploying, installing, updating, uninstalling, and running extended driver packages in the application state.
  - USB device extension driver packages that are developed by third-party device vendors and do not comply with standard protocols can be installed on OpenHarmony devices. After such a USB device is inserted, the system can identify it and matches an extension driver package.
  - Third-party applications can query and bind to a USB device extension driver package through the extended device management framework.

- The camera driver provides the following capabilities:
  - Identifying USB camera hot swap events during startup check and after startup.
  - Preview, photographing, and video recording of USB cameras, and query and configuration of the camera format and resolution.

- The codec driver provides hardware decoding acceleration for JPEG images, including obtaining hardware decoding information, initializing and deinitializing instances, decoding JPEG images, and applying for and releasing a buffer.

- The sensor driver provides driving for temperature and humidity sensors. It supports the query of temperature and humidity components of small-system devices, component enabling/disabling, and data query.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.0 Beta2 | NA |
| Public SDK | Ohos_sdk_public 4.0.9.6 (API Version 10 Beta2) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio| 4.0 Beta2 | Recommended for developing OpenHarmony applications How to obtain:<br><br>SHA-256 checksum: ae9b228fb1f79e99441e10bdcf347ebfc42266be8b170bbce3c9764ba32d82a4<br><br>SHA-256 checksum: 5c9afc5b1262868b58376155f1e8576d33c1ade8b01091edc4d7d397cd34026c<br><br>SHA-256 checksum: ea6c98cafd5036e4a6fd46b0b1cde3a306953b1eef423d5940f1af7c632205d6 |
| (Optional) HUAWEI DevEco Device Tool| 4.0 Beta1 | Recommended for developing OpenHarmony smart devices How to obtain:<br>[Click here to go to the download page](https://device.harmonyos.com/cn/develop/ide#download).|


## Source Code Acquisition


### **Prerequisites**

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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| **Site**                                                | **SHA-256 Checksum**                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.0 Beta2    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/code-v4.0-Beta2.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/code-v4.0-Beta2.tar.gz.sha256)| 27.7 GB |
| Hi3861 solution (binary)       | 4.0 Beta2    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_pegasus.tar.gz.sha256)| 27.5 MB |
| Hi3516 solution-LiteOS (binary)| 4.0 Beta2    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_taurus_LiteOS.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_taurus_LiteOS.tar.gz.sha256)| 300.9 MB |
| Hi3516 solution-Linux (binary) | 4.0 Beta2    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_taurus_Linux.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_taurus_Linux.tar.gz.sha256)| 192.4 MB |
| RK3568 standard system solution (binary)       | 4.0 Beta2    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/dayu200_standard_arm32.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/dayu200_standard_arm32.tar.gz.sha256)| 	5.2 GB |
| Public SDK package for the standard system (macOS)            | 4.0.9.6      | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/ohos-sdk-mac-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/ohos-sdk-mac-public.tar.gz.sha256)| 832.3 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.0.9.6     | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/L2-SDK-MAC-M1-PUBLIC.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256)| 788.4 MB |
| Public SDK package for the standard system (Windows\Linux)  | 4.0.9.6      | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/ohos-sdk-windows_linux-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/ohos-sdk-windows_linux-public.tar.gz.sha256)| 2.0 GB |


## What's New

This version has the following updates to OpenHarmony 4.0 Beta1.

### API 

For details about the API changes over OpenHarmony 4.0 Beta1, see [API Differences](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Beta2/en/release-notes/api-diff/v4.0-beta2/Readme-EN.md). A few API changes may affect applications developed using API version 9 or earlier. For details about the change impact and adaptation guide, see [Changelogs](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Beta2/en/release-notes/changelogs/v4.0-beta2/Readme-EN.md).


### Feature Updates

[Version Description](#version-description)

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

**Table 3** New samples

| Subsystem| Name| Introduction| Programming Language|
| -------- | -------- | -------- | -------- |
| Connectivity| [Upload and Download](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/BasicFeature/Connectivity/UploadAndDownLoad)| This sample uses the **\@ohos.request** APIs to create and query upload and download tasks. In this sample, an HTTP File Server (HFS) functions as the server.| ArkTS |
| File management| [Application Access Data Backup and Restore](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/BasicFeature/FileManagement/FileBackupExtension)<br>(Full SDK)| The BackupExtensionAbility enables an application to access the backup and restore framework.<br>**BackupExtensionAbility** is a derived class of **ExtensionAbility** in the stage model. You can modify the configuration file to customize the backup and restore framework behavior, including whether to allow backup and restore and specifying the files to be backed up.<br>This sample provides an application for the backup process to generate and display data.| ArkTS |
| Common event and notification| [Custom Badge](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/BasicFeature/Notification/CustomNotificationBadge)| This sample shows how to use the **\@ohos.notificationManager** APIs to set a badge on the home screen and send and obtain notifications.| ArkTS |
| Common event and notification| [Custom Notification Push](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/BasicFeature/Notification/CustomNotificationPush)<br>(Full SDK)| This sample shows how to use the **\@ohos.notificationManager** APIs to listen for callbacks to determine whether to send notifications. It implements notification filtering callback management.| ArkTS |
| NDK | [Native Xcomponent](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkXComponent)<br>(Native SDK)| This sample shows how to use the native XComponent interface to obtain a **NativeWindow** instance, obtain the layout/event information, register an event callback, and draw shapes on the page through OpenGL/EGL. In this sample application, you can click the button to draw a pentagon and click the XComponent area to change the pentagon color.| Native C++ |
| Application Model| [Data Agent Widget - Database Update](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/PersistentProxyForm)<br>(Full SDK)| This sample shows a data agent widget. It uses the **\@ohos.application.DataShareExtensionAbility**, **\@ohos.data.dataShare**, and **\@ohos.data.dataSharePredicates** APIs to implement widget content updates along with RDB changes after widget subscription information is modified.| ArkTS |
| Application Model| [Data Agent Widget - Push Application Update](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/ProcessProxyForm)<br>(Full SDK)| This sample shows how to use the data agent widget in the push application form. It uses the **\@ohos.data.dataShare** APIs to modify subscription conditions of the data agent widget and publish the widget data.| ArkTS |
| Application Model| [Edit Application](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/Receiver)| This sample implements simple sharing, including sharing cancellation and completion, based on the UIExtension. In the sample application, you can touch **Return Share** to return to the calling application; you can also touch **Stay Edit App** to stay in the current application.| ArkTS |
| Application Model| [Initiating Application Sharing](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/Share)<br>(Full SDK)| This sample implements the initiation of sharing through the **Share** button. It provides two application icons: share demo and share edit. You can touch one of them to initiate sharing and redirect to the corresponding application.| ArkTS |
| Application Model| [Text Application](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/Template)<br>(Full SDK)| This sample implements simple sharing, including sharing cancellation and completion, based on the UIExtension. In the sample application, you can touch **Return Share** to return to the calling application; you can also touch **Stay Share Text** to stay in the current application.| ArkTS |

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).


## Resolved Issues

**Table 4** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| I6U4ZT | The first photo in Gallery cannot be opened when the power supply is disconnected immediately after the photo is taken.|
| I79752 | There is a medium probability that the .ohos.smartperf thread of the com.ohos.smartperf process causes a C++ crash in libark_jsruntime.so.|
| I79P3K | There is a low probability that the onDestroy stack encounters a JS crash in the com.ohos.callui process.|
| I79TCB | There is a low probability that the VizCompositorTh thread of the com.ohos.note process causes a C++ crash in libweb_engine.soTh.|
| I78CBC | Memory leakage occurs in libace.z.so when a user touches an image folder in Gallery to browse images in grid form and then exits repeatedly.|
| I78CH7 | Memory leakage occurs in libace.z.so when applications are repeatedly added to or removed from the dock bar.|


## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I78C9W | Memory leakage occurs in libace.z.so when a user touches an image in Gallery to maximize it and then exits repeatedly.| This operation scenario is uncommon, and the leak issue disappears after the application is restarted. The impact is controllable.| 2023-08-30|
| I7BF3M | During the long-term running test, the launcher process occasionally encounters app freezing because STRINGID:APPLICATION_BLOCK_INPUT is stuck in libeventhandler.z.so.| This issue does not cause the system to restart. The impact is controllable.| 2023-08-30|
| I7M51R | There is a low probability that a C++ crash occurs in the render_service thread of the com.ohos.systemui process.| The render_service thread will restart automatically. The impact is controllable.| 2023-08-30|
| I7NWF3	| Due to compatibility issues, the session fails to be enabled for a Wi-Fi P2P connection between a device running 3.2.x and a device running 4.0.x.	| This issue does not occur when both devices run 4.0.x. The impact is controllable.	| 2023-08-30 |
| I7BOAO	| Multiple GLES3 test cases of the third-party repository fail to be executed.	| The third-party vendor is carrying out adaptation.	| 2023-08-30 |
