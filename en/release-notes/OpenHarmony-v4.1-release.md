# OpenHarmony 4.1 Release


## Version Description

With the release of OpenHarmony 4.1 Release, the development suite is upgraded to API Version 11 Release. Compared with OpenHarmony Release 4.0, OpenHarmony 4.1 Release comes with more than 4000 new APIs to enrich your application development capabilities. Open application development capabilities are presented as kits, delivering a clearer logic and scenario-specific perspectives. ArkUI component openness and animation capabilities are further enhanced. Web capabilities are continuously supplemented. Distributed capabilities improve networking stability and connection security. The multimedia subsystem supports richer encoding capabilities and more refined playback control capabilities. You are welcome to use this version and provide valuable suggestions.

You can read this document to learn more about key feature and capability updates provided by this version.

### SDK

The open capabilities provided by the SDK are presented by kit. You can search for and use the capabilities by kit. These scenario-specific capabilities offer a clearer programming logic.

In addition, the development guide and API reference are reconstructed by kit for better understanding and easier use.


### ArkUI

- The **\<NodeContainer>** component is provided to enhance custom drawing.

- The text and container components are enhanced as follows:
   - The **\<TextInput>** and **\<Text>** components support character-based truncation.
   - The **\<TextInput>** and **\<TextArea>** components support obtaining of the caret position.
   - Intelligent word segmentation is supported. The logic for inserting the caret based on the word segmentation result is added, and a new word segmentation algorithm is used.
   - The **\<ImageSpan>** component supports custom long-press menu events as well as component indentation and alignment.
   - Through **ScrollToIndex**, the **\<List>** component can specify the target list item to scroll to in the list item group.

- The components have the AI access capabilities enhanced as follows:
   - The **\<TextInput>** component and related text components support visual input.
   - The **\<Text>**, **\<RichEditor>**, and related text components support text entity recognition.

- Status management is enhanced as follows:
   - The undefined, null, and union types are supported.
   - The **\<ListItem>** component can update methods in the **ForEach** and **LazyForEach** attributes.
   - The **@LocalStorageLink** and **@LocalStorageProp** decorators are not updated when they are not activated.

- The chip component is added. The following components have their style, interaction, and animation enhanced: **\<TextInput>**, **\<TextArea>**, **\<List>**, **\<Grid>**, **\<Search>**, **\<CheckBox>**, **\<Slider>**, **\<Image>**, **\<Menu>**, and semi-modal pop-up are enhanced.

- The customization capability of the pop-up components and navigation components is enhanced as follows:
   - The rounded corners, shadows, and popup arrows of pop-up menus can be customized.
   - The **isShow** parameter is added in the **bindContextMenu** method.
   - The navigation bar in the **\<Navigation>** component can be hidden.
   - The **\<Navigation>** component provides the function of obtaining detailed information about each page of the route stack and destroying or displaying pages based on the page information.

- New style objects and component style attribute methods are provided to support style reuse and dynamic switching.
   - The universal attribute style supports **Style** objects.
   - Component-specific attribute styles support objects derived from **Style**.
   - The polymorphic style is switched to the **Style** object. 


### Application Framework

- When an application exits normally, the **temp** directory is cleared to improve security and reduce system storage space consumption.

- Enhanced ExtensionAbility management capabilities: Background management and unified timeout are provided for ServiceExtensionAbilities.

- Enhanced ArkTS widget capabilities: Transparent widgets, data proxy refresh, single-color mode, and lock-screen widgets are added.


### Bundle Management

- The system-level HSP supports OTA upgrades.

- A guide is provided to optimize the size of the modular development package.


### DSoftBus

- The QoS interface capability is constructed for DSoftBus transmission to better manage bottom-layer link resources and provide route selection decisions, improving distributed service experience.

- The subsystem specifications are continuously enhanced. The connection reliability confirmation capability is added to route selection, and connection parameters can be dynamically set based on resource conditions.

- The DFX mechanism is enhanced. For example, the subsystem supports service process dotting, upper-layer distributed service statistics, and service alarms for network monitoring events.

- The IPC provides APIs for querying reference counts and timestamps, and the maintenance and debugging capabilities are enhanced.


### Distributed Data Management

- Standard data definitions and descriptors of the Unified Data Management Framework (UDMF), query of standard data types, data access authorization and management, and application-defined data types are supported.

- Cross-device synchronization is not allowed for data without security levels.

- The preferences data supports modification, query, and persistence of data streams in Uint8Array format.

- An RDB can be created in the subdirectory of the specified application sandbox path.


### Graphics and Window Manager

**Graphics**

- The system supports variable frame rates and provides APIs for service access.

- HDR Vivid videos can be rendered and displayed.

- The graphics NDK capability is enhanced. The **OnFrameAvailableListener** callback is provided for native Image APIs. Primary colors can be set for the native window. The OpenGL ES extension APIs are supported, and the drawing capabilities are further enhanced.

- You can specify a window not to be recorded during screen recording. A privacy window can be recorded as a pure black image.

- The system resolution can be adjusted.

- APIs are provided to adjust the system frame rate based on the animation and adjust the application frame rate.

- The animation capability is enhanced. The cut-out and rounded screen are supported, and navigation transition animation supports element sharing.

- The graphics rendering pipeline supports the Vulkan backend.

- The graphics subsystem provides drawing APIs.

- The native window APIs support the metadata setting to adapt to the transmission of dynamic metadata with frames in HDR video scenarios.

**Window Manager**

- Interactive status notifications are provided for the window stage.

- Global search of the window type is supported.


### Multimedia

**Audio/Video**

- Calling applications are allowed to access media sessions.

- The color of the AVCastPicker component can be customized, and the component status can be listened.

- Historical albums and playlists of applications can be displayed on the media controller.

- The system supports concurrent playback of multiple audio streams with low latency and dynamic adjustment of the callback frequency and data volume.

- Low-latency audio recording is supported.

- Low-power audio playback is available for music and audiobook applications.

- Audio-haptic is provided to support precise synchronous playback of audio and haptic streams.

- AMR/MKV demuxing and AMR decoding are supported.

- Media information about audio and video files can be obtained.

- The video framework is optimized to reduce resource usage. The AVBuffer is used to support full-process data processing and zero copy.

- Digital Rights Management (DRM) is supported. DRM plug-in management, device certificate request and processing, media key request and processing, and DRM program decryption are supported.

**Image**

- Decoding of .ico images is supported.

- Color setting and CSS parsing of .svg images are supported.

- Color Space Conversion (CSC) between sRGB and P3 during decoding is supported.

**Media Library**

- Object-based read and write interfaces are available for media data.

- Multiple access modes, such as fast, balanced, and high-quality, are provided.

### Camera

- The camera NDK APIs are provided for applications to perform secondary processing on camera data.

- The **CameraPicker** class is provided so that third-party applications can wake up or integrate the photographing and video recording capabilities of the camera.

- The basic camera control capabilities, including smooth zoom and flashlight, are enhanced.

- Camera performance is enhanced for smoother switching between the front and rear cameras and between taking photos and recording videos.


### Common Event and Notification

- System applications are allowed to send live view notifications.

- Emitter supports subscription by string type. The serializable data type is supported for data to be transferred in events. The number of subscribers can be obtained.

- Applications can receive only custom common events released by themselves.


### Utils

- Worker threads can be created in the HAR or HSP.

- The task pool can send messages to the host thread during execution.


### Connectivity

- NFC provides Host-based Card Emulation (HCE).

- NFC supports the configuration of the default payment application.

- APIs are provided to check whether the currently connected Wi-Fi hotspot is a mobile phone hotspot.

- APIs are provided to add the STA device connected to a Wi-Fi hotspot to the blocklist.


### Location

- APIs are provided for geocoding, reverse geocoding, and geocoding service status query.


### Power Supply

- The code structure of **DisplayPowerManager** is adjusted. The brightness management module is changed to an independent module.

- An animation with the updatable battery level is displayed during the charging of a device in the powered-off state.


### Security

- Certificate management: The CA certificate path is opened.

- Certificate framework: Certificate chain verification, revocation check, and certificate chain construction are supported.

- The crypto framework supports the PBKDF2 algorithm, optional AAD parameters for symmetric keys, variable-length key HMAC, DH/25519 algorithm, Brainpool curve, SM2 key parsing and parameter processing, and curve name-based key generation.

### Access Control

**Permission Management**

- A permission dialog box can be displayed on a UIExtensionAbility page.

- Screen lock status records are added to permission usage records.

- The option of allowing permissions can be displayed when an application is in use.

### ArkCompiler

- The dynamic import capability supports variables as parameters.

- Runtime APIs are provided for instrumentation and replacement of class methods.

- The number sign (#) can be used to declare private members of a class.

- Cross-thread serialization is provided for the **Sendable** class.

- The TSC is upgraded from 4.2.3 to 4.9.5.

- The incremental compilation speed is enhanced for ArkTS applications.

- The obfuscation function is enhanced. File names and folder names can be obfuscated. Comments in declaration files can be deleted. Exportable object names and their attribute names can be obfuscated.

- libc: Security hardening interfaces such as **dlopen** and **dlclose** are added, and multi-thread reentrant is supported. The performance of some frequently used C APIs is optimized. The following lib interfaces are added to the DK: random number arc4random*, stack-related backtrace, shared memory shm_open, and shell mode matching wordexp. The header files **execinfo.h**, **queue.h**, and **cdefs.h** are supported.

- C++ debugging: The debugging speed in scenarios such as application startup and .so loading is optimized. Standalone LLDB debugging is supported.


### Resource Manager

- Resource indexes can be added through the shortcut menu in the **module.json** file.

- The **resfile** directory can be packaged and compiled.

- The resource ID can be obtained based on the resource name.


### USB

- The USB device management capability is supplemented. The USB service can be enabled or disabled for all devices or a given device, or by device type. In addition, the disabling policy can be persistent in restart and hot swap scenarios.

- The USB service authentication mode is optimized by adding access control permissions and refining the permissions of system services and system applications to call the USB service.

- The vulnerabilities of the bulk transfer and control transfer interfaces are fixed. Interfaces for E2E transfer are available, and the performance meets the requirements.


### Multimodal Input

- Users can double-touch the power button to start an ability.

- The mouse cursor can be customized.

- The setting of the mouse cursor style in the multimodal input scenario is optimized.

- APIs are provided for processing key press events by priority.

- The mouse cursor size and color can be set, and the animation cursor style is supported.


### Pan-Sensor

- Sensor data precision can be reported so that the system can detect the sensor precision of different devices for better application adaptation.

- C APIs are added for sensors and vibrators.

- The custom vibration format is extended. The **curve** field is added to describe the complex continuous vibration effect.


### Device Management

APIs related to \@ohos.deviceInfo.d.ts are provided for small-system devices.


### Test Framework

**Automated Test Framework arkXtest**

- Simulation of UI operations, such as scrolling the mouse wheel and double-clicking the left or right mouse button, is supported.

- Using shell commands to simulate UI operations, such as click, scroll, double-click, and text input, is supported.

- The efficiency of searching for component information in the UI test framework is improved.

- The information about the text size and color is added in the dump information.

- The asynchronous listening capability is added to listen for system dialog box events and obtain text information.

**Test Scheduling Framework xDevice**

- The capability of automatically retesting failed items during a single test is provided. The number of retest times can be configured, and only one test report is generated.

- The test report is optimized by unifying the test report header information for mini-system, small-system, and standard-system devices.

- A remote download address can be configured when the test resources are unavailable on the local host.

**Stability Test Tool WuKong**

- The capability of configuring pages and ability pages is added. Page shielding can be configured during the test to speed up test.

- The single-scenario pressure test capability is provided. Operation events can be cyclically injected to a component, and the number of cycles can be configured.

**Performance Development Tool SmartPerf Host**

- Collection, analysis, and display of HiLog and HiSysEvent are supported.

- The hiperf event count can be analyzed and displayed.

- Trace capture can be dynamically paused and debugged.

- The thread wakeup relationship tree can be quickly traced.

**Performance Test Tool SmartPerf Device**

- The capability of capturing memory and CPU data is optimized.

- Commands are provided for starting or stopping collection.

- The capability of periodically obtaining screenshots, resolutions, and refresh rates is provided.


### DFX

- Collection of CPU, GPU, memory, I/O, network, and trace data is supported.

- The fault type data is open.

- HiDebug supports resource information collection during application running.

- HiProfiler supports in-depth tuning of the CPU, GPS, audio, display, and GPU for power-intensive applications, time consumption analysis in animation scenarios (start, exit, screen switch, transition, and sliding), and lightweight ftrace data collection.

- HiProfiler and HiDumper work together to collect the extended memory information of the memory process.

- HiTrace supports lightweight, long-term data collection.

- HiPerf supports symbol parsing and stack aggregation.


### Upload/Download

- Foreground tasks and background tasks can share the number of tasks.

- The status and progress of background tasks can be monitored.

- Task priorities are supported. Foreground or background tasks can be executed based on their respective priorities.

- The system-level proxy is automatically used.


### Input Method Framework

- The input method experience is optimized when the WebView gains focus.

- The input method experience is optimized when the focus switches between windows.

- The input method in security mode is supported.

- The input method can be switched by pressing the logo key and the **Space** bar.

- The **inputMethodList** module is provided.


### Time and Time Zone

- The NTP server address can be configured through system parameters. A maximum of five NTP server addresses can be configured.

- The switch of automatic time and time zone synchronization can be configured through system parameters.


### Globalization

- The preferred language of an application can be set and obtained.

- The text time and phone number formats can be recognized.

- Quick date calculation is supported.

### AI

MindSpore Lite provides C APIs for on-device machine learning.


### Update

- Differential multi-thread update is supported.

- A retry mechanism is added for hardware faults during an update to improve update reliability.

- The language parameters in normal mode can be synchronized to the updater used in the update.


### Web

- The web-based accessibility node query and reporting capabilities are added.

- APIs are provided for reporting page redirection events.

- Application and network proxy, and application certificate management are supported.

- Rendering at the same layer is supported. (This enhancement is available only for certain components such as **\<XComponent>** and **\<button>**).

- The component supports the execution of JS scripts injected in advance after DOM building is complete.

- C APIs **registerJavaScriptProxy** and **runJavaScript** are available.

- Resource interception supports the ArrayBuffer data type.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool | Version | Remarks | 
| -------- | -------- | -------- |
| OpenHarmony | 4.1 Release | NA | 
| Public SDK | Ohos_sdk_public 4.1.7.5 (API Version 11 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. | 
| (Optional) HUAWEI DevEco Studio | 4.1 Release | Recommended for developing OpenHarmony applications How to obtain:<br><br>SHA-256 checksum: c46be4f3cfde27af1806cfc9860d9c366e66a20e31e15180cf3a90ab05464650<br><br>SHA-256 checksum: 15d6136959b715e4bb2160c41d405b889820ea26ceadbb416509a43e59ed7f09<br><br>SHA-256 checksum: ac04ca7c2344ec8f27531d5a59261ff037deed2c5a3d42ef88e6f90f4ed45484  | 
| (Optional) HUAWEI DevEco Device Tool | 4.0 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide#download). | 


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version | Mirror                                                | SHA-256 Checksum                                            | Software Package Size |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/code-v4.1-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/code-v4.1-Release.tar.gz.sha256) | 31.6 GB |
| Hi3861 solution (binary)       | 4.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_pegasus.tar.gz.sha256) | 29.2 MB |
| Hi3516 solution-LiteOS (binary) | 4.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_taurus_LiteOS.tar.gz)  | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 318.7 MB |
| Hi3516 solution-Linux (binary) | 4.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_taurus_Linux.tar.gz.sha256) | 215.8 MB |
| RK3568 standard system solution (binary)       | 4.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| Public SDK package for the standard system (macOS)            | 4.1.7.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/ohos-sdk-mac-public-signed.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/ohos-sdk-mac-public-signed.tar.gz.sha256) | 1.1 GB |
| Public SDK package for the standard system (macOS-M1)            | 4.1.7.5  | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/L2-SDK-MAC-M1-PUBLIC-signed.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/L2-SDK-MAC-M1-PUBLIC-signed.tar.gz.sha256) | 1.1 GB |
| Public SDK package for the standard system (Windows\Linux)  | 4.1.7.5   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/ohos-sdk-windows_linux-public.tar.gz)  | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Release/ohos-sdk-windows_linux-public.tar.gz.sha256)  | 2.2 GB |


## Update Description

This version has the following updates to OpenHarmony 4.1 Beta1.

### API Updates

- For details about the API changes over OpenHarmony 4.1 Beta1, see [API Differences](http://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Release/en/release-notes/api-diff/v4.1-Release-vs-v4.1-beta1/Readme-EN.md).
- For details about the API changes over OpenHarmony 4.0 Release, see [API Differences](http://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Release/en/release-notes/api-diff/v4.1-Release-vs-v4.0-Release/Readme-EN.md).

A few API changes over OpenHarmony 4.1 Beta1 may cause your application projects to be incompatible. For details about these changes, see [Changelogs](http://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Release/en/release-notes/changelogs/v4.1-Release/Readme-EN.md).

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).


## Resolved Issues

**Table 4** Resolved issues

| Issue No. | Description | 
| -------- | -------- |
| I8PEOF | A system freeze may occur due to LIFECYCLE_TIMEOUT of the com.ohos.mms process. As such, a white screen is displayed. |
| I8QET3 | A C++ crash may occur in libbluetooth_server.z.so of the OS_IPC_10_25363 thread of the bluetooth_servi process. As such, the Bluetooth service is abnormal. |
| I8QH9S | A C++ crash may occur in libnative_appdatafwk.z.so of the os.settingsdata thread of the com.ohos.settingsdata process. As such, the background data management process stops. |
| I8QNI7 | A system freeze may occur due to SERVICE_BLOCK of the foundation process. |
| I8QSZ1 | An app freeze occurs in libsamgr_proxy.z.so of the com.ohos.systemui process, due to THREAD_BLOCK_6S. |
| Vulnerabilities (such as I7TYTF) in 43 open-source components | 43 open-source component vulnerabilities, such as protection_fault in the errseq_set function of the kernel |
| I78THF | The maligpu version in the RK3568 kernel patch is too old (11.29), and a large number of CVE vulnerabilities are not fixed. |
| I83D6I | If Bluetooth is repeatedly enabled and disabled in Settings, there is a possibility that an app freeze occurs. |
| I827LU | Memory leakage occurs when Bluetooth is repeatedly enabled and disabled in Settings. A memory leak of 15 MB occurs within one hour. |
| I82V2W | Memory leakage occurs when Bluetooth is repeatedly enabled and disabled in Settings. The memory usage of Settings increases to 180 MB within one hour. |



## Known Issues

**Table 5** Known issues

| Issue No. | Description | Impact | To Be Resolved By | 
| -------- | -------- | -------- | -------- |
| I8WP8M | Create a large folder by moving an application icon on the home screen to overlap with another application icon, and then move an application icon out of the folder. Repeat this operation. Five minutes later, a total of about 25 MB memory is leaked on the launcher, that is, a 673.68 KB memory leak for each operation. | The system freezes when the memory leak reaches a certain amount.<br>Workaround: Close background applications or restart the device. | April 30 |
| I98AV0 | Repeatedly turn on and then turn off the location information switch. When this operation lasts for 5 minutes, a total of about 14 MB memory is leaked on the distributeddata process, that is, a 95.57 KB memory leak for each operation. | The system freezes when the memory leak reaches a certain amount.<br>Workaround: Exit the current page. | April 30 |
| I9A9NO | Repeatedly touch the upper right corner of the SMS application to create an SMS message and then touch **Back**. When this operation lasts for 5 minutes, a total of about 50 MB memory is leaked, that is, a 341.33 KB memory leak for each operation. | The system freezes when the memory leak reaches a certain amount.<br>Workaround: Exit the application. | April 30 |
| I8QLRO | There is a low probability that a C++ crash occurs in libbtstack.z.so of the stack thread of the bluetooth_servi process. | The Bluetooth service automatically recovers, and users are unaware of the exception. | April 30 |
| I8TLYJ | There is a low probability that a C++ crash occurs in libbtstack.z.so of the SaInit1 thread of the bluetooth_servi process. | The Bluetooth service automatically recovers, and users are unaware of the exception. | April 30 |
| I8TM99 | There is a low probability that a C++ crash occurs in libbtframework.z.so of the softbus_server thread of the softbus_server process. | The DSoftBus service automatically recovers, and users are unaware of the exception. | April 30 |
| I8VFJS | There is a low probability that a JS crash occurs in ObservedPropertyAbstractPU of the com.ohos.settings process. | There is a low probability that the Settings application crashes. Users can exit the application to reclaim the memory. | April 30 |
| I98NGO | There is a low probability that an app freeze occurs in the com.ohos.settings process because THREAD_BLOCK_6S is stuck in the libbtframework.z.so stack. | There is a low probability that the Settings application crashes. Users can exit the application to reclaim the memory. | April 30 |
| I90A2N | There is a possibility that an app freeze occurs in the com.ohos.systemui process because THREAD_BLOCK_6S is stuck in the libeventhandler.z.so stack. | There is no response when users touches or swipes on the phone. This issue can be resolved when users access the control panel or notification center again. | May 30 |
| I963UO | There is a possibility that a C++ crash occurs in libEGL.so of the RSRenderThread thread in the com.ohos.systemui process. | The screen automatically locks. The issue does not persist after users unlock the screen. | May 30 |
| I9A089 | There is a moderate probability that a system freeze occurs in the foundation process due to SERVICE_BLOCK. | After the system freezes for 5 seconds, a 1-second startup animation is played, and the screen is locked. The issue does not persist after users unlock the screen. | April 15 |
| I9AYM2 | There is a low possibility that an app freeze occurs in the com.ohos.note process because THREAD_BLOCK_6S is stuck in the libweb_engine.so stack. | The Notes application freezes. The issue does not persist after the application is restarted. | May 30 |
| I9CGOZ | There is a high probability that an app freeze occurs in the com.ohos.camera process because THREAD_BLOCK_6S is stuck in the libcamera_framework.z.so stack. | The Camera application does not respond. The issue does not persist after the application is restarted. | April 30 |
| I9AEO0 | There is a low probability that an app freeze occurs in the com.ohos.settings process due to APP_INPUT_BLOCK. | The Settings application does not respond. The issue does not persist after the application is restarted. | April 30 |
| I8QH9S | There is a low probability that a C++ crash occurs in libnative_appdatafwk.z.so of the os.settingsdata thread of the com.ohos.settingsdata process. | The settingsdata service breaks down. It automatically starts when users access the data again. This has no impact on users. | April 15 |
| I963TL | There is a low probability that a C++ crash occurs in libark_jsruntime.so of the com.ohos.mms thread of the com.ohos.mms process. | The SMS application does not respond or automatically exits. The issue does not persist after the application is restarted. | April 30 |
| I9635I | There is a low probability that the device automatically restarts. | The impact is controllable. No workaround is required. | April 30 |
| I96JJ7 | There is a low probability that a C++ crash occurs in libace_compatible.z.so of the com.ohos.note thread of the com.ohos.note process. | The Notes application may crash. The issue does not persist after the application is restarted. | April 30 |
| I993H9 | There is a possibility that an app freeze occurs in the com.ohos.smartperf process because THREAD_BLOCK_6S is stuck in the libglobal_resmgr.z.so stack. | When users use the SmartPerf application to view real-time performance data of other applications, the application freezes.<br>Workaround: The system automatically clears the application process. The issue does not persist after the application is restarted. | April 30 |
| I97U6G | There is a low possibility that an app freeze occurs in the com.ohos.certmanager process because THREAD_BLOCK_6S is stuck in the librender_service_client.z.so stack. | The system automatically exits the certificate management application when it is frozen. The impact is controllable. | April 30 |
| I98KIG | There is a low probability that an app freeze occurs in the com.ohos.camera process because THREAD_BLOCK_6S is stuck in the libcamera_framework.z.so stack. | The Camera application freezes. The issue does not persist after users exit the application, clear the memory, and open the application again. | April 15 |
| I98NFR | There is a low probability that a C++ crash occurs in libwm.z.so of the ohos.smartperf thread of the com.ohos.smartperf process. | There is a low probability that the application exits. The issue does not persist after the application is restarted. | April 30 |
| I98AWP | There is a low probability that a C++ crash occurs in libweb_engine.so of the com.ohos.note thread of the com.ohos.note process. | The Notes application may crash. The issue does not persist after the application is restarted. | April 30 |
| I96ZWB | The peer device cannot be found after device networking. | When using the distributed audio service, OpenHarmony 4.0 and 4.1 devices cannot be compatible or interoperate with each other. The impact is controllable. | May 30 |
| I96CJL | The networking between mini-system devices fails. | The impact is controllable, and no workaround is available. | May 30 |
