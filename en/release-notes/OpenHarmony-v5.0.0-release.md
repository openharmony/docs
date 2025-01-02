# OpenHarmony 5.0.0 Release


## Version Description

OpenHarmony 5.0.0 Release continuously improves its standard system capabilities. It provides the following enhancements over OpenHarmony 5.0 Beta1:

The application framework provides more lifecycle management capabilities and child process capabilities, allowing for more refined task scheduling and management during runtime. ArkUI further opens up the rendering capability of custom nodes. The bundle manager improves the efficiency of application packaging and enriches the operable scenarios when end users use applications (such as creating application clones and home screen shortcuts). Distributed data management is further enhanced for higher security while ensuring proper data sharing. Module adaptation to the sendable mechanism is also enhanced. The file manager further improves the picker capability to properly control and use file resources. The media playback and recording capabilities are further enhanced, with new support for multiple audio, video, and image encoding formats, along with more refined playback control operations. The camera provides more powerful capabilities, enriching the scenarios for end users to take photos.

Multiple subsystems have further aligned with ArkTS to enhance NDK C API capabilities, such as ArkUI's adaptability to third-party frameworks, Unified Data Management Framework (UDMF), graphics rendering, playback framework, camera, graphics codec, network management, internationalization, time and time zone, input method framework, and pasteboard.

A more detailed description of the enhancements is as follows:


### Application Framework

- You can create JS or native child processes for time-consuming operations.

- A wider range of lifecycle events, such as **onNewWant**, are provided for abilities.

- An ability can return the AbilityResult to the caller without proactively destroying itself.

- Context supports the conversion of sendable objects for passing the context in multithreading environments.

- Application-level font settings are supported.


### ArkUI

- Component customization is further enhanced with the introduction of **Modifier**, **ContentModifier**, and **DrawModifier**. Attributes can be added to existing components, component content can be customized, and fully custom rendering is supported.

- Custom nodes and native rendering nodes are opened up. [Custom nodes](https://gitee.com/OpenHarmony/docs/blob/master/en/application-dev/ui/arkts-user-defined.md) are node objects with some basic capabilities of underlying entity nodes. They can be mixed and displayed with built-in components through custom placeholder nodes. They have customization capabilities for individual nodes, such as measurement and layout, setting basic attributes, setting event listeners, and custom drawing and rendering content. There are three types of custom objects: FrameNode, RenderNode, and BuilderNode.  
  - **BuilderNode**: provides APIs for a BuilderNode – a custom node that can be used to mount native components.
  - **FrameNode**: provides APIs for a FrameNode, which represents an entity node in the component tree. It can be used by a NodeController to mount a BuilderNode (that holds the FrameNode) to a NodeContainer or mount a RenderNode to another FrameNode.
  - **RenderNode**: provides APIs for creating a RenderNode in custom drawing settings at the native side.
  - **NodeController**: provides APIs for managing custom nodes, such as creating, showing, and updating custom nodes, and APIs for mounting custom nodes to a NodeContainer component.

- The NDK capabilities of components suitable for third-party frameworks are enhanced, covering component creation, attribute setting, event registration, customization, and component tree building.

- The capabilities of the **Navigation** component are enhanced, including the single- and dual-column switching animation, interruption and resumption of transition animations, and listening capabilities for the page lifecycle.

- The visual effect, animation, and interaction refresh of components are supported. Aging, mirror language, and screen reading are supported.

- You can define the color, shape, rounded corner, size, position, and shadow for menu and dialog box components.


### Bundle Manager

- Application clone access and management are supported. Applications can access application clones through simple configuration.

- Home screen shortcuts are supported. Users can dynamically add shortcuts to the home screen.

- The system-level HSP and ArkWeb can be upgraded independently, and preset applications can be updated independently.

- A recovery mechanism is provided upon OTA update interruption. If a power outage or service crash occurs during an OTA update, the OTA process is restored upon restart, continuing to install or update the applications.

- The **cache** directory can be automatically cleared when device space is insufficient.

- Native software packages can be packed, installed, and uninstalled.

- The packaging tool compresses an application package to reduce its size for distribution.


### DSoftBus

IPC provides basic C APIs, including serialization, deserialization, and message sending and receiving.


### Distributed Data Management

- RelationalStore and Preferences support access to shared sandbox data.

- The RDB supports opening in read-only mode.

- UDMF supports compatibility queries for UTD and MIME types.

- Data asset synchronization is optimized in the migration scenario.

- Distributed data management with E-class encryption is supported.

- In the inverted index construction scenario, an external tokenizer can be specified for an application.

- NDK C APIs support UDMF data drag and drop across devices.


### Distributed Hardware

- Refined ACL management is provided. ACLs can be added, deleted, modified, and queried based on devices, users, accounts, and bundle names.

- The quality is hardened to improve the stability and reliability of functions.

### Distributed DeviceProfile

- Device data is restructured at multiple levels to improve the execution efficiency of data addition, deletion, modification, and query.

- The quality is hardened, and background link establishment is optimized to improve stability and reliability.

### File Management

- Incremental file backup is supported.

- APIs are provided for an application to obtain the backup data volume details, allowing an application to report the number of data records to be backed up (for example, the number of short messages) and exception events during backup and restore.

- The SA is allowed to access the backup and restore framework.

- The picker capabilities are enhanced. Audio Picker allows users to select multiple items at a time. Download Picker is added, allowing applications to directly save files to the **Download/*bundleName*** directory. In addition, subsequent access to this directory does not require permission authorization, complementing the download experience of browser applications.

- Applications can obtain the access permission of public directories (**Download**, **Desktop**, and **Document**) by applying for permissions (supported on some devices, subject to **syscap** judgment). Direct access is not allowed without permissions requested.

- Applications can select files or directories through File Picker and obtain temporary access permissions to the files or directories. Persistent access is also supported. Files or directories that are not persisted cannot be accessed after the applications exit.

- Stream file access APIs, such as **CreateStream** and **fdopenStream**, are added.

- The APIs for setting and obtaining extended attributes are added.


### Graphics and Window Manager

**Graphics**

- The native image module supports NativeWindowBuffer.

- The native vsync is supported, supporting multiple callbacks per frame.

- NDK C APIs related to variable frame rates are provided.

- ColorSpaceManager supports the sendable capability.

- The font engine supports the text shadow capability and underline alignment.

- The graphics drawing interface improves drawing capabilities.

**Window Manager**

- The **display.getDisplayByIdSync** API is provided to work with the multi-screen feature, allowing applications to synchronously obtain information about the screen where the ability is located through the ID.

- Information about the available area on the screen can be obtained.

- The text color of the status bar can be set based on the page color in ArkUI.


### Media

**Audio**

- Audio focus enhancement: Audio focus sessions are supported, allowing an application to set concurrent playback policies and to play silently without interrupting background audio playback.

- More audio output devices, such as DP and USB headsets, are supported. Switching of the default output device (earpiece and speaker) is also supported.

- The audio stream type for video calls is added, optimizing the audio stream playback experience in this scenario.

- A unified volume component is added for easy of use, reducing development complexity.

- The style of the in-app casting component can be customized.

- The ringtone list query and custom ringtone settings are supported.

**Playback**

- The playback start and seek performance of the player is optimized to reduce the latency.

- Multiple playback protocols or formats are added: DASH protocol, and AMR, APE, and WAV PCM-MULAW audio formats.

- Multiple playback control capabilities are added: video playback with multiple audio tracks, changing the output surface during video playback, silent playback, precise seek, playback range setting, and subtitle setting.

- The streaming media buffer size can be configured. The audio offload mode is supported.

- Enhanced streaming media playback capability: The streaming media cache policy is optimized, reducing frame freezing.

**Recording**

Enhanced audio recording capability: Audio can be recorded in MP3, WAV, and PCM (µ-law) formats.

**Screen Capture**

- Screen capture protection can be exempted for the application's own privacy windows, providing a privacy confirmation window and screen capture status prompt.

- Images in a specified window can be excluded during screen capture.

- Screen rotation can be configured and rotation parameters can be dynamically adjusted.

- The microphone and system sound can be captured simultaneously.

**Audio/Video Codecs**

AVTranscoder APIs are added to reduce the bit rate and output video files in AVC, AAC, and MP4 formats, reducing the amount of data to be transmitted or stored.

**DRM**

- The AVPlayer and AVCodec can parse DRM information for DASH programs, decrypt H.265 videos encapsulated in TS, and decrypt audio clips.

- AVCodec DRM adaptation now includes settings for decryption parameters.

**Camera**

- The following modes are added: time-lapse, panorama, light painting, wide aperture video, and fluorescence.

- A one-touch PerConfig mechanism is added for cameras to ensure consistent effects and simplifies development.

- The deferred photo delivery process is optimized to improve the performance and quality of photos and videos.

- New C APIs are added to match the capabilities of ArkTS APIs.

- The camera experience is enhanced with features like mirroring, zoom, image stabilization, burst shooting, and camera status notification.

**Image**

- The EXIF read and write capabilities are enhanced, supporting batch read and write operations on EXIF data. The number of playback times can be obtained for GIF files.

- HDR dual-layer codec and conversion between HDR and SDR are supported.

- HEIF encoding and decoding and DNG decoding are supported.

- The compilation framework is supplemented based on NDK C APIs, including base classes for effects and filters, and custom algorithms.


### Common Event and Notification

- The CEM tool supports the release of custom common events.

- A generic interface is added to Emitter to directly transfer sendable objects.

- Synchronous query of the enabled status of notifications is supported.


### Communications

Third-party applications can connect to hotspots through network management.


### Network Management

**Network Management Capabilities**

- You can create a NetConnection object to connect to a specified Wi-Fi hotspot.

- NDK C APIs are provided for network management status listening and application-level proxy listening.

**Network Protocol Stack Capabilities**

- A TCP socket can be upgraded to a TLS socket to improve communication security.

- A TLS socket supports skipping certificate verification to avoid scenarios where certificates cannot be verified.

- All sockets can obtain the local IP address and port number.

- HTTP supports the configuration of certificate pinning information.

- HTTP supports the Brotli compression algorithm.


### Power

- The charging current can be obtained, allowing third-party applications to obtain the current of the device through **nowCurrent**.

- Temperature control actions in airplane mode are supported. You can customize temperature control policies to control devices to enter airplane mode.

- The WorkSource proxy running lock can assist the resource scheduler in power consumption control.

- In low power situations, devices can automatically enter the S4 sleep mode after waking up from the S3 sleep mode, implementing ultra-long standby.

- After system startup, it is now possible to read and broadcast the presence information of device shells or covers, and to configure kernel nodes of battery information and whether to broadcast.


### USB

- Access control is enhanced for USB device configuration management.

- The USB standard data transfer mode (interrupt transfer and bulk transfer) is enhanced.

- Security management of standard USB peripherals is supported.

### Startup

- Native software packages can be packed, installed, run, and uninstalled. A native software package development and release system is now available, facilitating the rapid construction of productivity software ecosystem capabilities and improving development efficiency for system developers.

- A resettable Open Anonymous Device Identifier (ODID) is provided to replace real-world UDIDs and other hardware identifiers.

- The bftpd command can be executed to debug sandbox data access in user mode.

### Globalization

- C APIs are provided to support internationalization capabilities in line with the ICU4C standard.

- The internationalization formatting capability supports screen size adaptation.

- Pseudo-localization testing is fully supported.

- C APIs are provided for resource file management.

- String resources support tags for translatability.

- Support for less common language character sets is now provided.


### Security

**Crypto Framework**

- C APIs are provided for some typical encryption and decryption algorithms to match ArkTS APIs.

- The SM4-GCM algorithm interface is supported.

**Certificate Management**

- APIs are provided to invoke the certificate management page.

- APIs are provided to obtain the private certificate list of an application.

**Access Control**

- The geographical location permission supports one-time authorization options.

- The permission management application page of the Settings page can be displayed.

**User IAM**

- Password validity period check is supported.

- Key recovery is supported.

**Account**

- Local accounts can be deregistered.

- When creating a local account, you can specify a short account name (used as the personal folder name).

- Querying local account names is now supported.

- A new privacy account type is introduced.

- A new unlock authentication intent is introduced.

- New graphical and four-digit PIN credential types are introduced.


### ArkCompiler

**ArkTS Front-end Compiler**

- The syntax is enhanced. The compilation target is switched from es2017 to es2021, and source code files with es2018 to es2021 syntax features can be compiled.

- The code obfuscation capabilities are enhanced: stack restoration, file-level non-obfuscation, obfuscation of HAP and HSP module file names, and trustlist wildcard.

**ArkTS Runtime**

- Module lazy loading is supported. Execution files are loaded synchronously when variables are actually used, improving application startup performance.

- The concurrency capabilities are enhanced. The sendable object sharing mechanism is provided to optimize object communication across threads. TaskPool provides features such as task queues, continuous tasks, and periodic tasks.

- Debugging is enhanced to support reverse debugging and Smart Stepinto.

- Tunning is enhanced to support hiperf/profiler hybrid stack and multi-instance heap dump.

**ArkTS Utility**

- High-precision floating-point operations, StringDecoder (string decoding), stream data processing, and bit vectors are supported.

**JSVM**

- A system JS engine is provided to support high-performance running of JavaScript and WASM.


### MSDP

**Drag Framework**

- You can rotate and drag and drop a window as it rotates.

- You can drag and drop a window between three devices.

- Applications can configure whether to hide the badge during the drag process.

- The data receiver can customize the cut and copy behavior.

**Screen Hopping**

- Control for both ends to initiate **activate** interface calls simultaneously is provided.

- Timing issues of screen hopping are optimized to reduce system dependencies and eliminate timing issues between multiple processes.

- Screen hopping management performance is improved, with a higher success rate and lower latency.


### Multimodal Input

C APIs are provided to support device information query.


### Pan-Sensor

**Vibrator**

- Some asynchronous query APIs offer their synchronous counterparts.

- The system can better use the vibrator component to trigger vibrations based on different component capability levels.

**Sensor**

- Some asynchronous query APIs offer their synchronous counterparts.

- C APIs are provided to support linear acceleration and game rotation vector sensors.


### Accessibility Service

- Zoom-in gestures are supported.

- Proactive broadcast capabilities are provided, allowing for proactive announcements of changing information in some dynamically changing scenarios for applications adapted for screen reading.

- Active focus capabilities are provided, enabling requests for proactive focusing on components in certain scenarios for applications adapted for screen reading.


### Resource Scheduler

**Background Task**

- Applications can request different types of continuous tasks at the same time.

- When an application requests a continuous task of the DATA_TRANSFER type, a download notification can be returned to the application for progress updates.

**Performance, Power, and Thermal Control**

- The system load level is determined based on the current temperature, load, and whether the system is in a high-load scenario. After an application registers the system load callback, the application can adaptively reduce its service load based on the system load level, thereby reducing the overall machine load.

**Agent-powered Reminder**

- When an application requests a duplicate calendar reminder, it is now possible to specify exclusion days when reminders are not made.

- When an application requests a reminder, it can use **wantAgent** to pass **parameters**. When the user touches the reminder, **parameters** is carried to display the target UIAbility.

- When an application queries released reminders, the corresponding reminder ID is returned in the query result.


### Test Framework

Compatibility testing is provided for cross-platform interfaces.


### DFX

- An API is provided to check whether the HDC debugger is connected.

- The trace function can be enabled in developer mode.

- Awareness of the main thread timeout event is now open.

- The errorManager allows TaskPool and Worker to listen for unhandled Reject events.


### Kernel

Thread QoS level marking and scheduling are provided based on user interaction relationships.


### Upload and Download

- **request.agent.Fault** has refined error types to assist you in quickly locating issues with API usage.

- **request.agent.Config** has added a proxy member, supporting the setting of the network proxy address for tasks.

- **request.agent.Task.start** supports restarting of a failed or stopped task.

- **request.agent.Task** supports the setting of the TLS certificate pinning using the **network.json** file.

- **request.agent.FileSpec** allows you to specify all file paths in the **base** directory of the application sandbox, facilitating sandbox file management. It also allows you to upload public files, such as Gallery files and Album files, in the foreground to reduce the overhead caused by extra copy.

### Input Method Framework

- NDK C APIs are provided to support the use of the input method by self-drawn UI components, including starting and exiting the input method and processing text display requests.

- The callback timing when invoking the keyboard is optimized, allowing input method applications to adjust the keyboard display content in a timely manner based on the input box attributes.

### Time and Time Zone

- System APIs are provided for forcibly refreshing the NTP time and obtaining the current NTP time.

- NDK C APIs are provided for obtaining the time zone.


### Pasteboard

- NDK C APIs are provided to offer the pasteboard capability.

- A cross-device pasteboard switch is provided.

- For applications upgraded to API 12 or later, the read permission verification is added to the pasteboard read interface.


### Web

- The network takeover feature is enhanced to obtain the frame URL of a request and the resource type of an intercepted request.

- The pre-display capability of the input method in the web scenario is supported.

- Keyboard hosting of **Web** components is supported.

- Synchronous drawing of **Web** components and native ArkUI components is supported.

- Directories that can be accessed across domains using the File protocol can be set.

- Applications can now specify rendering child processes.

- **Web** components support the acceleration gyroscope.

- **Web** components support intelligent filling of HTML5 pages.

- **Web** component support backward and forward cache.

- The soft keyboard avoidance mechanism of **Web** component has been optimized to support the Resize and Offset modes.


### Theme Framework

- The theme can be enabled through the folder directory. Compared with the compressed package, the theme enabling performance is improved.

- Widget resources can be managed, including the operations to add, delete, modify, and query theme widgets.

- Themes can be enabled for external screen devices.

- The theme enabled feature does not support the switchover of the current **active** directory.


### Build

The version of CMake version used for building is upgraded from 3.16.5 to 3.28.2.


## Mapping relationship

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 5.0.0 Release | NA | 
| Public SDK | Ohos_sdk_public 5.0.0.71 (API Version 12 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.| 
| (Optional) HUAWEI DevEco Studio| 5.0.0 Release | Recommended for developing OpenHarmony applications<br>[Click here](https://developer.huawei.com/consumer/cn/download/).| 
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide#download). | 


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/code-v5.0.0-Release.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/code-v5.0.0-Release.tar.gz.sha256)| 41.8 GB |
| Hi3861 solution (binary)       | 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_pegasus.tar.gz.sha256) | 27.1 MB |
| Hi3516 solution-LiteOS (binary)| 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.3 MB |
| Hi3516 solution-Linux (binary) | 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 220.4 MB |
| RK3568 standard system solution (binary)       | 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/dayu200_standard_arm32_20240929.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/dayu200_standard_arm32_20240929.tar.gz.sha256)| 11.7 GB |
| Public SDK package for the standard system (macOS)            | 5.0.0.71 | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| Public SDK package for the standard system (macOS-M1)            | 5.0.0.71  | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| Public SDK package for the standard system (Windows/Linux)  | 5.0.0.71   | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.5 GB |


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description| 
| -------- | -------- |
| IA686U | There is a high probability that a C++ crash occurs in libace_napi.z.so of the OS_FFRT_2_0 thread in the com.ohos.photos process.|
| I9YC9X | There is a high probability that system freezing occurs in libark_jsruntime.so due to LIFECYCLE_TIMEOUT in the com.ohos.camera process.|
| I9TE52 | There is a possibility that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.photos process.|
| I9TDUU | Key application: There is a low probability that app freezing occurs in libace_compatible.z.so due to THREAD_BLOCK_6S in the ohos.samples.distributedcalc process.|
| I9TE5K | There is a low probability that app freezing occurs in libunwind.z.so due to THREAD_BLOCK_6S in the com.ohos.photos process.|
| I9TJGB | There is a low probability that a C++ crash occurs in libmali-bifrost-g52-g7p0-ohos.so of the RSRenderThread thread in the com.ohos.camera process.|
| IA5EC3 | There is a low probability that app freezing occurs in libskia_canvaskit.z.so due to THREAD_BLOCK_6S in the com.ohos.updateapp process.|
| IA5I3D | There is a low probability that app freezing occurs in librender_service_base.z.so due to THREAD_BLOCK_6S in the com.ohos.smartperf process.|
| IA4G47 | There is an extremely low probability that a C++ crash occurs in libhcodec.z.so of the av_codec_service thread of the av_codec_service process.|
| I9TDMQ | Key application: There is an extremely low probability that app freezing occurs in libskia_canvaskit.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.|


## Unfixed Vulnerabilities

**Table 4** Known issues

| Issue No.| Description| Impact| To Be Resolved By| 
| -------- | -------- | -------- | -------- |
| I9S5ZN | There is a low probability that app freezing occurs in libunwind.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.| The Settings page freezes.<br>Workaround: Restart the Settings application.| 2024-10-15| 
| I9S600 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.settings process.| The Settings page freezes.<br>Workaround: Restart the Settings application.| 2024-10-15| 
| IAB2U3<br>IAK2J2 | There is a low probability that a C++ crash occurs in libaudio_client.z.so of the OS_APAsyncRunne thread of the audio_server process.| This issue does not affect user services. No workaround is required.| 2024-10-15| 
| IAIRFB | There is a low probability that a C++ crash occurs in libweb_engine.so of the com.ohos.note thread of the com.ohos.note process.| The application will exit unexpectedly. This issue can be resolved by restarting the application.| 2024-10-15| 
| I9SXZ8 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.contacts process.| The application freezes when you open the Contacts application to query call records. This issue can be resolved by restarting the Contacts application.| 2024-10-15| 
| IAKLLD | There is a low probability that a C++ crash occurs in libaudio_policy_service.z.so of the SaInit2 thread of the audio_server process.| The process restarts. This issue does not affect user services. No workaround is required.| 2024-10-15| 
| IA56CU | There is a low probability that a C++ crash occurs in libweb_engine.so of the com.ohos.note thread of the com.ohos.note process.| The application will exit unexpectedly. This issue can be resolved by restarting the application.| 2024-09-30| 
| IA5AMJ | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.launcher process.| The screen freezes for about 3 seconds when you access the multi-task screen. After the loading is complete, the screen recovers.| 2024-09-30| 
| IA5AIT | There is a low probability that system freezing occurs in render_service due to SERVICE_BLOCK.| The application screen freezes and does not respond. This issue can be resolved by restarting the device.| 2024-10-15| 
| IA6RH6 | There is a high probability that app freezing occurs in libbtframework.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.| The Settings application might not respond. This issue can be resolved by restarting the Settings application.| 2024-10-15| 
| IA6RFX | There is a high probability that a C++ crash occurs in libbtservice.z.so of the OSaInit0 thread in the bluetooth_service process.| Bluetooth-related application might crash. This issue can be resolved by restarting the application.| 2024-10-15| 
| IA8KGR | There is a low probability that a C++ crash occurs in libbluetooth_server.z.so of the OS_IPC_12_22172 thread of the bluetooth_service process.| Bluetooth-related application might crash. This issue can be resolved by restarting the application.| 2024-10-15| 
| IAQC64 | Randomly open several applications and then open the Settings application. When you return to the home screen and repeatedly access the background interface, the Settings application may encounter a memory leakage of 32 KB for each operation.| The Settings application may exit unexpectedly. This issue can be resolved by restarting the application.| 2024-10-15| 
| IASE04 | In the memory test of OpenHarmony on the RK3568 development board, the resident memory of the render_service process exceeds the baseline (31 MB).| The memory usage of the entire system is higher than expected.| 2024-10-15| 
| IASDWO | The sliding frame rate for accessing the Weibo home page through a browser is lower than the specification baseline.| Browsing experience is affected.| 2024-10-15| 
