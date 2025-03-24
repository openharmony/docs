# OpenHarmony 5.0.1 Release


## Version Description

OpenHarmony 5.0.1 Release continuously improves the capabilities of the standard system, rolling out API 13 via quick iteration. Compared with 5.0.0 Release, OpenHarmony 5.0.1 Release has the following new or enhanced features:

The C API capabilities are enriched, including but not limited to application queries of the application framework, ArkTS node customization, preferences data management, file management, AVSession integration, event notification, and toggle queries for Wi-Fi, Bluetooth, and location features, as well as cellular network-related capability and pasteboard management. Other improvements include camera enhancements with a wider range of shooting modes and optimizations to **Web** component functionalities.

A more detailed description of the enhancements is as follows:


### Application Framework

- New ArkTS and C APIs are introduced for creating application child processes.

- C APIs are added to obtain application information like the cache path, file encryption settings, and bundle name.

- Adjustment of application-level font scaling is supported.


### ArkUI

- C API functionalities are enhanced for custom node attributes and ArkTS capabilities to access custom attributes of any target node.

- The **Navigation** component now allows for customizable title bar positions and font styles for main titles and subtitle. The **NavDestination** component allows you to set the style of the bottom toolbar and control its visibility status.

- Multiple components have been adapted for aging-friendly design, adjusting font sizes and component dimensions in line with system aging-friendly settings. Involved components include **Dialog**, **SeletTitleBar**, **SwipeRefresher**, **SplitLayout**, **ComposeTitleBar**, **ExceptionPrompt**, **TreeView**, **Filter**, **GridObjectSortComponent**, **ProgressButton**, **ToolBar**, and **TabTitleBar**.

- The **RichEditor** component has been enhanced with features such as scrollbar visibility settings, image drag-and-drop support, and a more comprehensive set of shortcut keys.


### Bundle Manager

- New C APIs are added to query the MainElement information.

- Third-party HAR now supports the retrieval of startup **want** parameters for launching the host application.


### Distributed Data Management

AC APIs are added to obtain, store, and delete preferences key-value data.


### File Management

- C APIs are now available for applications to obtain file names (including extensions) or the names of the last folder based on an URI.

- Backup and restore are now supported for applications leveraging the application clone feature.


### Graphics and Window Manager

**Graphics**

- C APIs are added to the Pixelmap module for manipulating the color space.

- NativeImage now provides APIs to define the default read/write mode and preset sizes for geometric shapes.

- When a UIAbility transitions to the background, animations with a set number of loops stops and invoke a complete callback, whereas those set to loop indefinitely continues regardless of whether the UIAbility is running in the foreground or background.

**Window Manager**

System applications can now proactively request focus.


### Media

**Audio**

- C APIs are added to facilitate basic interaction with AVSession.

- The error codes in the casting scenario are refined.

- The device information attributes returned during casting are improved.

**Camera**
- General lens control features have been expanded to include lens cleanliness checks, tripod detection, and ring light compensation control.

- Capabilities specific to foldable screen lenses have been introduced, allowing for the reporting of front and rear lens statuses based on the device's folding state and enabling automatic lens switching.

- The feature of capturing HDR photos in HEIF format is introduced.

- Cloud-based enhancements for shooting effects are integrated into the system.

- The video segmentation feature is supported. After a video recording operating, a video is quickly generated for preview purposes, which is subsequently deleted once a high-quality video is processed and stored in Gallery, thereby optimizing preview performance.

- The system now supports camera metadata detection, which supports detection and reporting of smiles, human faces, human eyes, cat eyes, and dog eyes.

- The capability of outputting depth stream and photographic depth data is added.

**Image**

The picture type is added. The picture type allows the decoding of certain images with special information into multi-image objects. Multi-image object encoding and decoding and primary and secondary image management are supported. It applies to JPEG and HEIC images.


### Common Event and Notification

- C APIs are added to query the notification enabling status and subscribe to and unsubscribe from common events.

- Applications can now start the system's semi-modal notification setting page.


### Communications

C APIs are introduced for checking the on/off status of Wi-Fi and Bluetooth.


### Location

C APIs are added to query the on/off status of geolocation, initiate and terminate location services, and report locations.


### Telephony Service

- C APIs are added to obtain the camping information of cellular networks, including the network registration status and access mode.

- C APIs are added to obtain information about the default data SIM card.


### Power Supply

- The system can now obtain the current charging current, introducing the **nowCurrent** API for this purpose.

- The airplane mode can be associated with temperature control. You can customize a temperature control policy to enable the device to enter the airplane mode.

- The WorkSource proxy running lock can assist the resource scheduler in power consumption control.

- Devices in a low-battery state can now automatically transition to a deeper sleep state (S4) after being woken up from a lighter sleep state (S3), facilitating extended standby periods.


### Startup

APIs are provided to query distributionOsApiName to obtain API version information.


### ArkCompiler

- ASON can parse strings and return collections.Map.

- Template-based TaskPool APIs are optimized to refine return value structures, eliminating the need for explicit type conversion.


### Multimodal Input

- Key values are added to support custom common events for screen reading.

- The system can now detect the consecutive pressing of the power button five times as a combined operation.

- Event listening for the power and volume buttons is now supported.

- APIs for querying and configuring infrared frequencies are now provided.


### Resource Scheduler

The VoIP continuous task type is introduced, allowing for audio and video call services even when the application is running in the background.


### Pasteboard

- C APIs are added to copy and paste multiple types of data and report cross-device data changes.

- The system can now check whether the pasteboard contains data in a specific format.


### Web

- The capability to obtain the current scrolling offset of a web page is now available.

- The WebResourceResponse object can check whether the response data is ready for the following data types: string, number, ArrayBuffer, and object.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 5.0.1 Release | NA |
| Public SDK | Ohos_sdk_public 5.0.1.111 (API Version 13 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio| 5.0.1 Release | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices|


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 5.0.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/code-v5.0.1-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/code-v5.0.1-Release.tar.gz.sha256) | 42.7 GB |
| Hi3861 solution (binary)       | 5.0.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_pegasus.tar.gz.sha256) | 27.2 MB |
| Hi3516 solution-LiteOS (binary)| 5.0.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.4 MB |
| Hi3516 solution-Linux (binary) | 5.0.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_taurus_Linux.tar.gz.sha256) | 221.1 MB |
| RK3568 standard system solution (binary)       | 5.0.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/dayu200_standard_arm32.tar.gz.sha256) | 12.7 GB |
| Public SDK package for the standard system (macOS)            | 5.0.1.111 | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| Public SDK package for the standard system (macOS-M1)            | 5.0.1.111  | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| Public SDK package for the standard system (Windows/Linux)  | 5.0.1.111   | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.5 GB |


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Issue Description |
| -------- | -------- |
| I9S5ZN | There is a low probability that app freezing occurs in libunwind.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.|
| I9S600 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.settings process.|
| IAB2U3<br>IAK2J2 | There is a low probability that a C++ crash occurs in libaudio_client.z.so of the OS_APAsyncRunne thread of the audio_server process.|
| IAIRFB | There is a low probability that a C++ crash occurs in libweb_engine.so of the com.ohos.note thread of the com.ohos.note process.|
| IAKLLD | There is a low probability that a C++ crash occurs in libaudio_policy_service.z.so of the SaInit2 thread of the audio_server process.|
| IA56CU | There is a low probability that a C++ crash occurs in libweb_engine.so of the com.ohos.note thread of the com.ohos.note process.|
| IA5AMJ | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.launcher process.|
| IA5AIT | There is a low probability that system freezing occurs in render_service due to SERVICE_BLOCK.|
| IA6RFX | There is a high probability that a C++ crash occurs in libbtservice.z.so of the OSaInit0 thread in the bluetooth_service process.|
| IA8KGR | There is a low probability that a C++ crash occurs in libbluetooth_server.z.so of the OS_IPC_12_22172 thread of the bluetooth_service process.|
| IAQC64 | Randomly open several applications and then open the Settings application. When you return to the home screen and repeatedly access the background interface, the Settings application may encounter a memory leakage of 32 KB for each operation.|
| IASE04 | In the memory test of OpenHarmony on the RK3568 development board, the resident memory of the render_service process exceeds the baseline (31 MB).|

## Known Issues

**Table 4** Known issues

| Issue No. | Issue Description | Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I9SXZ8 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.contacts process.| The application freezes when you open the Contacts application to query call records. This issue can be resolved by restarting the Contacts application.| December 15|
| IA6RH6 | There is a high probability that app freezing occurs in libbtframework.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.| The Settings application might not respond. This issue can be resolved by restarting the Settings application.| December 15|
| IASDWO | The sliding frame rate for accessing the Weibo home page through a browser is lower than the specification baseline.| Browsing experience is affected.| December 15|
| IAZYOO | The RK3568 development board frequently encounters freezing issues during the WuKong comprehensive random pressure testing.| The SystemUI process fails to log main thread activities for a long period of time, and the absence of multi-modal event distributions on the lock screen side contributes to this problem. This issue can be resolved by pressing the power button. It has limited impact on users, and therefore no specific workaround is necessary.| December 15|
| IANQF3 | There is a high probability that the system restarts during the WuKong pressure test.| This issue leads to the device restarting<br>and is currently not preventable.| December 15|
| IB4L3E | There is a high probability that app freezing occurs in libcamera_framework.z.so due to LIFECYCLE_TIMEOUT in the com.ohos.camera process.| This issue is caused by the camera_host process. Restart the app to resolve the issue.| December 15|
| IAP85P | There is a low probability that a process with a low startup priority is terminated preferentially, resulting in a system freeze.| This can lead to the application being shut down, but restarting the application can address the issue.| December 15|
| I9SXZ8 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.contacts process.| This issue occurs because the Contacts application is stuck in the **windowStage.loadContent()** API. Restarting the application can resolve the issue.| December 15|
| IB36B2 | There is a low probability that a JS crash occurs in the com.ohos.mms process, and the problem stack is identified as close.| This issue may cause the Messaging application to exit unexpectedly. Restarting the application can resolve the issue.| December 15|
