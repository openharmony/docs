# OpenHarmony 4.0 Release


## Version Description

OpenHarmony 4.0 Release is launched as scheduled, along with the development kits upgraded to API version 10. Compared with OpenHarmony Release 3.2, OpenHarmony 4.0 Release comes with more than 4000 new APIs to enrich your application development capabilities. More than 200 HDIs are added to HDF for much easier hardware adaptation. The graphics framework and ArkCompiler are continuously optimized to deliver a better-than-ever user interaction experience. ArkUI component customization and animation capabilities are further enhanced. The scope of distributed hardware is expanded to audio and input device fields. A brand-new unified data management framework is provided for data sharing. The capabilities in terms of multimedia, security, and privacy protection are also further enhanced. You are welcome to use this version and provide valuable suggestions.

You can read this document to learn more about key feature and capability updates provided by this version.


## Feature Description


### Application Framework

The following features in the stage model have been enhanced:

- ExtensionAbilities adopt minimal management to cope with diverse service scenarios.

- UIExtension is provided to implement ExtensionAbilities with UIs. The UI of a UIExtensionAbility can be embedded, as a UIExtension component, in the window of the caller application.
  - A unified UIExtension template is provided to define the basic lifecycle and context capabilities.
  - Native default ExtensionAbility pages can be displayed, and UI customization is supported.

  - APIs are provided for connecting to and disconnecting from ExtensionAbilities.
  - The background color can be set for a UIExtensionAbility page.
  - Privacy mode can be set for a UIExtensionAbility page. A page in privacy mode cannot be captured or recorded.
  - ServiceExtensionAbilities can be connected through UIExtensionAbilities.

- The following ExtensionAbilities are provided: ActionExtensionAbility for custom actions, ShareExtensionAbility for sharing, BackupExtensionAbility for backup and restore, DriverExtensionAbility for driver services, and PrintExtensionAbility for the print service.

- The ArkTS widget capability is enhanced. Static widget configuration and static image display are employed to reduce memory usage of widgets. Widget content can be refreshed through data proxy, greatly reducing power consumption of widgets.

- Atomic services can be shared. You can use the **UIAbility.onShare()** lifecycle callback provided by the UIAbility component to set the data to share. Users can share atomic services and widgets to another device through the sharing box.

- APIs can be called to dynamically enable or disable cross-device migration. An application can dynamically determine whether to restore the page stack or exit on the source device after a successful migration.


### Bundle Management

- Application installation packages can be installed without being decompressed, speeding up system startup and application installation.

- Data sharing is available between applications and atomic services. During application installation, the system parses the data-group-ids list in the certificate file, establishes mappings, and creates a data sharing path to implement data sharing.

- ArkTS APIs are provided to set and query the application distribution type and additional information during application installation.

- Applications that can open a file can be queried through the file name extension. In this way, a file can be opened based on its file name extension.

- Enterprise applications are supported. APIs are provided to install enterprise MDM applications and enterprise NORMAL applications. APIs for managing and revoking enterprise applications are also provided.

- The overlay capability is supported. You can add resource file overlay packages to change the application UI style on diverse devices, without rebuilding or repacking.

- The unpacking tool supports multiple languages. AppGallery can query the multi-language information in the package and distribute applications in different language environments.

- .so files can be used without being decompressed. At the runtime, .so files are directly read and loaded from the package, speeding up application installation and reducing ROM usage.


### ArkUI

- **Addition or enhancement of basic components:**
  - The UIExtension component is added so that an application can be embedded into another application in UIExtensionAbility mode.
  - The drawing components **\<Rect>**, **\<Circle>**, **\<Ellipse>**, **\<Line>**, **\<Polyline>**, **\<Polygon>**, **\<Path>**, **\<Rect>**, and **\<Shape>** support universal attributes such as translating, cropping, and masking.
  - The mask color and animation can be customized for custom dialog boxes. For example, you can set parameters related to the animation effect.
  - You can use the **bindContextMenu** and **bindMenu** to set menu positions.
  - The divider set by the **\<ColumnSplit>** component can be dragged.
  - The **\<Refresh>** component allows you to set the content to be displayed in a pull-to-refresh action.
  - The width and height of the input string in the **\<Text>** component can be returned. If the string is not fully displayed, a dialog box showing the complete string is displayed when the mouse pointer is hovered over.
  - **\<XComponent>** supports texture rendering.
  - **\<Popup>** positions can be customized.
  - ArkTS and JavaScript widgets support callbacks upon the completion of UI rendering, so that they can obtain the rendering completion status and perform further processing.
  - The **\<Image>** and **\<Text>** components support obscuring.
  - The basic components are enhanced to improve user experience. For example, popups can be closed layer by layer by pressing the **Esc** key; the **\<ListItem>** component supports the swipe-to-delete gesture, which means that users can long swipe left to delete an element; the **\<ContextMenu>** component supports segment-based display.
  - The **\<Grid>** component supports layout information setting.
  - The **\<Menu>** component supports rounded corner setting.
  - Semi-modal components support height adaptation setting.

- **Addition or enhancement of the animation effect:**
  - Transition animation can be used when the component attributes change, for example, when the size, background color, and opacity of a component change.
  - You can set the spherical attributes, lower edge pixel stretching, adaptive color, G2 rounded corners, shadows, and gradient attributes for components to implement advanced animation effects.
  - Implicit animation is provided for the layout attribute, background image size and position, and show/hide attribute.
  - **scrollToIndex** can be used to set animation effects for lists. Fuzzy animations are provided for tabs, and display/disappearance animations are provided for popups.
  - Custom animations are also supported.

- Named routes are supported so that page-specific animations can be set. The lite ArkUI framework supports global data objects and data sharing between pages within an application.

- Framework capabilities are enhanced, for example, the stage model multiton scenario supported by global APIs, and Rosen rendering backend.

- The interaction capability of rich text is enhanced as follows: Users can touch and hold a text, drag the mouse to select a text, set the text to be editable (whether to enable editing in the rich text box can be set through universal attributes), and listen for input events.

- The dialog box feature is enhanced. APIs for error, information, and confirm dialog boxes are added. The three buttons in the warning dialog box are optimized and the interaction is optimized.


### ArkCompiler

**High-level language debugging:**

- Hot reloading performance is optimized, and the multi-HAP scenario is supported.

- Multiton debugging is supported.

**High-level language concurrency enhancement:**

- **TaskPool** supports task interruption and cancellation, task group definition, task status and scheduling information dotting, and identification and recovery of tasks that wait for a long time.

- **TaskPool** supports priority setting and automatic scaling algorithms.

**High-level language compilation optimized:**

- The ArkTS syntax rules are officially defined and the ArkTS syntax check is added. When DevEco Studio is used to build code, an alarm is generated for the code that does not comply with the ArkTS syntax rules. For details about the syntax check rules, see [TypeScript to ArkTS Cookbook](../application-dev/quick-start/typescript-to-arkts-migration-guide.md).

- The AOT compiler supports off-peak compilation on the device side, which improves performance.

- PGO is supported for collecting type and function hotspot information at runtime, and AOT supports JavaScript code, improving the running performance of dynamic JavaScript code.

**Other features of the high-level language runtime:**

- The NAPI library can be dynamically loaded through **import**.

- New APIs are provided for the NAPI buffer, object, arraybuffer, and object types.

**Compilation toolchain updates:**

- The Clang/LLVM toolchain is upgraded to 15.0.4.

- The libc version is upgraded to 1.2.3. The interface performance of the libc library is optimized.

- The sigaction function provides the sigchain function.


### Distributed Data Management

- The DataShare client provides the capability of subscribing to DataShareExtension data changes by URI prefix. The DataShare client will be notified of any DataShareExtension data change under the subscribed URI prefix.

- The Unified Data Management Framework (UDMF) is added to support data standardization models, intra-device data dragging, UDMF data storage adaptation, permission management, and lifecycle management. The UDMF supports cross-device application dragging and temporary authorization for files in the distributed directories in dragging scenarios.

- RDB store NDK interfaces are provided. These interfaces are used for transaction addition, deletion, modification, and query, data encryption, hierarchical data protection, and data backup and restore.

- The system can automatically select a channel for synchronization of key-value and distributed data objects based on the data volume. The system can automatically select a Bluetooth or Wi-Fi P2P channel for data synchronization based on the data volume.

- System applications can silently access DataShareExtensionAbility data of other system applications through the data management service agent. That is, they can access DataShareExtensionAbility data of another system application without starting that application.


### DSoftBus

- Management of DSoftBus link information is supported.

- Cross-device transmission capability negotiation is provided at the session level.


### Distributed Hardware

- Distributed audio supports pool management of speakers and microphones. Speakers and microphones of remote devices can be used across devices in native system services, and the speaker volume of remote devices can be controlled.

- Distributed input supports pool management of keyboards, mouse devices, and touchpads. Keyboards, mouse devices, and touchpads can be used across devices in system applications.


### File Management

- File category view management is supported. Gallery manages media files in the album, indicating that it does not care about the storage locations of images and videos. Functions such as adding and removing files in the album do not involve file I/O operations. Third-party applications can obtain the album list and access files such as images and videos in the album through the **PhotoAccessHelper** API.

- Enhanced file I/O access capabilities are provided, including **randomAccessFile**, **moveDir**, and **copyDir**.

- URI-based temporarily authorized file access and authorization revocation capabilities are supported, and cross-application local authorization or cross-device authorization are provided for files.

- Public image files can be synchronized between the device and cloud (on the prerequisite that the cloud service is enabled for the login account of the device). Images on the cloud can be selected through the picker.

- Applications can customize the directories to be backed up.

- Applications can listen for file changes in the application sandbox.


### Graphics & Window

**Graphics**

**Stable and smooth:**

- The performance of unified rendering is optimized, including IPC performance optimization based on shared memory, rendering performance optimization based on occlusion culling and cache, and energy efficiency improvement based on of hardware synthesizer.

- The rendering library on which the graphics subsystem depends is upgraded to Skia 0310.

**Ultimate animation effect:**

- Property animations with custom content are supported. Transition animation can be set when a component appears or disappears.

- Color picker, gradient blur, edge pixel stretching, fade-in effect, and multiple blur materials are supported.

**Graphics capability enhancement:**

- Image encoding and decoding capabilities are enhanced. SVG decoding, ICO decoding, GIF incremental decoding, JPEG IDCT scaling and decoding, PNG encoding, and EXIF information extension are supported.

- The image interface capability is enhanced. JavaScript APIs are provided for pixel map serialization and deserialization, and the **ImageReceiver** and image decoding NDK interfaces are provided.

**Window**

- Listening for the focus status of a window is supported. You can listen for the focused, out-of-focus, and hidden states of a window.

- The z-order of a child window can be adjusted to the top layer of the current application window.

- APIs are provided to check whether the screen is used as the primary screen, mirror of the primary screen, or extended screen and to stop screen mirroring or the extended mode.

- The way for obtaining the parameter values of the display module is optimized. Now actual parameter values are directly obtained from the hardware instead of the software.

- The screen brightness can be restored to the default value through window settings.

- The immersive implementation mode is reconstructed to optimize the animation effect when an application is opened, exited, or redirected.


### Multimedia

**Audio**

- You can use native APIs to implement audio playback and recording. In delay-sensitive audio playback and recording scenarios, you can use the native APIs to achieve lower delay.

- You can query and listen for the playback device with the highest priority.

- You can adjust the alarm volume independently.

- You can set the mute mode by pressing a physical button.

- Audio focus is supported. When playing an audio, an application does not need to apply for the focus. Instead, the system automatically applies for the focus in the background and executes the focus policy (such as pause, fade-out, and fade-out recovery). The application only needs to register a listener to subscribe to focus interruption events and update the status, for example, stopping the progress bar when the program is paused. Short tone playback is supported.

- Sound effect mode is supported. Applications can query, switch, or disable the sound effect mode.

- Intra-system recording is supported. Audio data played in the system can be filtered and recorded based on the audio scene attribute. Recording devices can be queried.

- The audio device capability is enhanced. The display name of the audio output device can be obtained from the playback object information. You can query Bluetooth-connected devices that can be used for audio playback and select one of them for audio playback. Audio peripherals that comply with the standard USB protocol are supported.

**Playback Control Framework**

- Custom media information can be transmitted between the media provider and controller. Applications can extend the media content display mode. For example, the controller can require the provider to display songs and lyrics in a special form.

- The framework capability of the media playlist is supported. The provider provides the playlist content, and the controller obtains the playlist content and selects any media content to play.

- The framework capability of historical playback records is supported. The AVSession framework provides the list of historical playback applications, sorted by playback sequence (including the applications that are being played and the applications that have exited).

- A transmission channel is provided for custom media events, for example, a transmission channel for lyric content. Through this channel, the provider provides the lyric content, and the controller obtains the lyric content.

- A transmission channel is provided for custom control commands. Through this channel, the controller sends custom control commands to the provider, for example, to require the provider to display bullet comments.

**Media Playback**

- HLS-based live streaming and data source-based streaming playback are supported.

- HDI-based H.265 video hardware decoding and playback are supported.

- Audio playback attributes can be set. Users can select the output audio type when using the player.

- Rotation playback is supported for videos with rotation angles.

- Audio effect parameters can be configured.

**Camera**

- The front camera provides preview mirroring. By default, the preview image on the front camera is mirrored.

- You can query the main device attributes of a distributed camera, including the device name and type.

- More refined resolution query is supported. You can query the supported size, format, and frame rate by preview, photographing, and recording usage.

- The camera framework provides a horizontal coordinate system [0, 0, 1, 1]. All coordinate-related operations are performed based on this coordinate system.

- When different camera applications use the same physical camera, the camera framework employes priority control and mutual exclusion policies.

**Audio/Video Codecs**

- You can call the native APIs provided by the AVCapability module to query the audio and video codecs of the system.

- Audio and video encapsulation is supported. You can call the native APIs provided by the AVMuxer module to encapsulate audio and video, that is, to store encoded audio and video data to a file in a certain format.

- Audio and video decapsulation is supported. You can call the native APIs provided by the AVDemuxer module to decapsulate audio and video, that is, to extract audio and video frame data from bit stream data.


### Common Event and Notification

- Applications can enable or disable static event subscription.

- System applications can remove sticky events that have been published.

- Applications can set badges that represent the number of notifications.

- Notifications can be set to unremovable.

- Notifications can be deleted in batches.

- The event processing module in the application supports cancellation of callbacks that have been subscribed to by condition.


### Connectivity

- NFC eSE card emulation is supported.

- A random MAC address can be used for connection to an AP through Wi-Fi.

- A static IP address can be used for connection to an API through Wi-Fi.


### System Ability Manager

- System services can be started as required, for example, called by external systems or triggered by events. System services can be automatically stopped when the device is idle.

- The system service configuration format is optimized by using the JSON format instead of the XML format.


### Power Supply

- The capability of querying and reporting the system power level is enhanced. The power level can be customized.

- Wired and wireless charging types, including standard charging, fast charging, and super fast charging, can be reported.

- The management mechanism of the running lock is enhanced, and the system power status and level are specified.

- You can set the wakeup source, which can be the power button, mouse, keyboard, touchpad, screen, stylus, or leather case.

- You can set the sleep source, which can be the power button, leather case, or auto-sleep upon timeout.

- Development guides are provided for the management of power, battery, display brightness, power consumption statistics, and thermal.

- New system APIs are provided to enable the system to enter the sleep state immediately.


### Multimodal Input

- Original events of keyboard input devices are mapped to the intent event of normalized interaction.

- Users can customize the touchpad based on their use habits.
  - Both the press and touch actions can be used to simulate a click on the left mouse button.
  - Both of the following actions can be used to simulate a right-click on the mouse: touching the left or lower right corner, and pressing or touching the left or lower right corner with two fingers.
  - 10 speed levels are supported.
  - Both of the following actions can be used to simulate a scroll with mouse: content moving in the same direction as your finger moves, and content moving in the reverse direction as your finger moves.


### Theme Framework

- The lock screen management service supports lock screen event callbacks, static/dynamic wallpaper, and service status query when the screen is locked.

- The wallpaper management service allows users to customize and reset wallpapers, and lock/unlock the screen.


### Upload/Download

New APIs are provided for the creation and execution of upload and download tasks.

- Task information can be stored persistently. Multiple query modes are provided. Task information is more comprehensive and supports query by condition.

- Security and privacy protection are enhanced, and the system management interface permission is added.

- Files can be downloaded in overwrite mode, and they can be uploaded and downloaded in segments. Custom token tasks can be created.

- Services can be started or stopped on demand. Services are started when applications call related APIs and automatically exit when tasks are idle.


### Time and Time Zone

- Synchronous APIs are provided to obtain the system time and system startup time. The obtained time is more accurate.

- The API for obtaining the date is deprecated and replaced by **new Date()** in the ArkTS public library.


### Input Method

Synchronous APIs are provided to obtain edit box information.


### Network Management

- Basic IPv6 capabilities are supported, including DNS resolution, application networking through HTTP/HTTPS/socket, and IPv4/IPv6 dual-stack access on cellular, Wi-Fi, and wired networks.

- Synchronous APIs are added to the \@ohos.net.connection module.


### Print

The print service is provided. Applications can trigger the print service through the print APIs. The print service provides the default print preview page and task management page, where you can manage network printer connections.


### Security

**Crypto Framework**

- DSA is supported.

- APIs are provided to parse DSA, Elliptic Curve Cryptography (ECC), and Rivest Shamir Adleman (RSA) keys and obtain key parameters.

- APIs are provided to obtain the algorithm type generated by using random numbers.

- APIs are provided to randomly generate, convert, encrypt, and decrypt SM4 keys.

- The Hash-based Message Authentication Code (HMAC) and hash capabilities are provided for SM3 keys.

- APIs are provided to randomly generate, convert, sign, verify, encrypt, and decrypt SM2 keys.

**Key Management**

- Chip-level keys can be derived based on the GID.

- Import of the Chinese cryptography key is supported.

- Fine-grained access control is provided for secondary identity authentication.

- NO HASH mode is provided for key management signature.

- Key parameters can be specified during algorithm calculation.

- HUKS key encryption is supported.

- The service identity field of the key can be added to the Key Attestation public key certificate.

- Standard HDIs are provided.

**Mutual Authentication Between Devices**

Pseudonyms can be generated and identified in the following scenarios:

- Mutual authentication on multiple devices that use the same login account

- Mutual authentication on two devices that are connected in P2P mode using different accounts

**Basic Security Capabilities**

Small-system devices can query the security levels of other devices.

**Certificate Management**

The RSA key signature digest and padding can be specified for signature and signature verification.


### Ability Access Control

- An application-specific permission management page can be opened.

- Identity verification is provided for system applications.

- The display of the permission management menu is optimized. The permission groups of media assets and files are split, and the authorization granularity of the corresponding permissions is more refined.


### Account

- Third-party applications can use the account authorization capability.

- Domain account plugin management, domain account management, and domain account authentication are supported.


### User IAM

- The Authentication Widget is provided, which improving the user identity authentication capability.

- The Authentication Widget provides the default user identity authentication page. You can call **getUserAuthInstance**, with **AuthParam** set to authentication parameters and **WidgetParam** set to widget display parameters. To ensure that users have unified identity authentication experience, you are advised to use the user identity authentication APIs of API version 10.


### WebView

- The web camera capability and HTML5 tag capabilities such as bindContextMenu, Select, and date input are supplemented.

- Multiple render processes can be split.

- Basic text and image dragging capabilities are provided.

- WebRTC video conferencing (excluding camera sharing) is supported.

- Independent SELinux labels are provided for render processes to enhance basic security.

- The render process, display thread, and scenario information of the web component can be identified, and the system resource scheduler module are notified for CPU management.


### Kernel

- The HCK framework is supported.

- Hierarchical configuration is provided for the Linux kernel.

- Code execution permission control is enhanced as follows:
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
  - APIs are provided for USB camera preview, photographing, and recording, as well as query and configuration of the camera format and resolution.

- The codec driver provides hardware decoding acceleration for JPEG images, including obtaining hardware decoding information, initializing and deinitializing instances, decoding JPEG images, and applying for and releasing a buffer.

- The sensor driver provides drivers for temperature and humidity sensors. It supports the query of temperature and humidity components of small-system devices, component enabling/disabling, and data query.


### Pan-Sensor

- You can query the preset vibration effects supported by a device and check whether a vibration effect (specified by **EffectID**) is supported by the device.

- An API is provided for stopping the vibrator in any mode, so that you do not need to find the vibration mode in use in order to stop the vibrator.

- APIs are provided for triggering vibration as defined in the configuration file. The customized tactile control mode can be played from a file. The playback execution result depends on the sensor capability of the device.


### Testing

**Test Framework arkXtest**

- The definition capability is provided in the automatic script test suite for more flexible script design.

- The object-level assertion capability is provided for test scripts.

- The simulation of Chinese input, mouse operations, and area screenshots is provided.

**Self-Test Execution Framework developer_test**

- The test task management capability is enhanced. Now you can execute historical tasks by task ID.

- The precise test capability is provided. Now you can filter and execute test cases at the subsystem, component, test suite, and test case levels.

- You can execute HATS test cases.

- The stability test capability is supported, and test cases can be executed out of order.

- The coverage statistics capability is supported. You can generate code coverage data locally at a few clicks.

**Stability Test Tool wukong**

Rotation event injection is supported.

**Performance Debugging Tool SmartPerf Host**

- Frame timeline capture and display capabilities are provided for you to capture and display frame freezing and frame loss data.

- Scheduling analysis capture and display capabilities are provided for you to capture and display data related to CPU scheduling analysis and thread scheduling analysis.

- Call stacks can be visualized and the proportions of functions in different libraries can be displayed in pie charts.

**Performance Data Collection SmartPerf Device**

- You can test the cold and hot start delay, page switchover delay, and sliding frame rate of applications.

- Test data on the device can be connected to the dashboard on the cloud. You can upload test reports on the device to the cloud and view or download data from the cloud to the local host.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.0 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.10.13 (API Version 10 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio| 4.0 Release | Recommended for developing OpenHarmony applications How to obtain:<br><br>SHA-256 checksum: 2c88cf43e1ef6ba722aac31eccc8ef92f07a9b72e43a9c1df127017828a22137<br><br>SHA-256 checksum: 25e491458eec50b4abddf5bed6aa85893801d70afbce02958f17bd904619405a<br><br>SHA-256 checksum: 284cb01f7b819e0da1d4fcacbbbbe8017ba220b5e3b9b1d5e4cc59ea30456acc |
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide#download).|


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/code-v4.0-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/code-v4.0-Release.tar.gz.sha256) | 27.6 GB |
| Hi3861 solution (binary)       | 4.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_pegasus.tar.gz.sha256) | 27.3 MB |
| Hi3516 solution-LiteOS (binary)| 4.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_taurus_LiteOS.tar.gz.sha256)| 302 MB |
| Hi3516 solution-Linux (binary) | 4.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 194 MB |
| RK3568 standard system solution (binary)       | 4.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/dayu200_standard_arm32.tar.gz.sha256) | 	5.1 GB |
| Public SDK package for the standard system (macOS)            | 4.0.10.13      | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | 841 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.0.10.13     | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 797 MB |
| Public SDK package for the standard system (Windows\Linux)  | 4.0.10.13      | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.0 GB |

## What's New

This version has the following updates.


### Change APIs

- For details about the API changes over OpenHarmony 4.0 Beta2, see [API Differences](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Release/en/release-notes/api-diff/v4.0-Release-vs-v4.0-beta2/Readme-EN.md).
- For details about the API changes over OpenHarmony 3.2 Release, see [API Differences](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Release/en/release-notes/api-diff/v4.0-Release-vs-v3.2-Release/Readme-EN.md).

A few API changes over OpenHarmony 4.0 Beta2 may cause your application projects to be incompatible. For details about these changes, see [Changelogs](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Release/en/release-notes/changelogs/v4.0-Release/Readme-EN.md).


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

**Table 3** New samples

| Feature| Name| Introduction| Programming Language|
| -------- | -------- | -------- | -------- |
| File management| [Selecting and Viewing Documents and Media Files](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/FileManagement/FileShare/Picker) (The APL must be system_basic.)| This sample shows how an application uses APIs such as **\@ohos.file.picker**, **\@ohos.multimedia.mediaLibrary**, and **\@ohos.file.fs** to edit and save documents, view images in the album, and play videos.| ArkTS |
| One-time development for multi-device deployment| [Navigation bar](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/SuperFeature/MultiDeviceAppDev/MultiNavBar)| This sample shows the style of the navigation component in different device forms.<br>On a small- or mini-system device, tabs are used, and the content and navigation components are displayed in top-down style. You can touch tabs at the bottom to switch the content.<br>On a standard-system device, side bars are used, and the content and navigation components are displayed in left-right style. You can touch the level-1 and level-2 menus on the side bar to switch the content.<br>In this sample, the adaptive layout and responsive layout are used for adaptation among multiple devices or multiple window sizes. The component provides window breakpoint events to ensure that applications can be properly displayed on different devices or in different window sizes.| ArkTS |
| Widget| [Application Proactively Adding Data Agent Widgets to the Home Screen](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/SuperFeature/Widget/RequestAddForm) (Full SDK)| This sample shows how the **com.ohos.hag.famanager** application adds a data agent widget to the home screen by calling the **\@ohos.app.form.formBindingData** and **\@ohos.app.form.formProvider** APIs.| ArkTS |
| Security| [Security UI Component](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/SystemFeature/Security/AuthorizedButton) (Full SDK)| This sample shows how to use UI components of the security type for temporary authorization. When a user touches a security component of a certain type, temporary authorization is granted to the application. This eliminates authorization popups and provides a smaller authorization scope.| ArkTS |

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/).


## Resolved Issues

**Table 4** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| I7BF3M | During the long-term running test, the launcher process occasionally encounters app freezing because STRINGID:APPLICATION_BLOCK_INPUT is stuck in libeventhandler.z.so.|
| I7M51R | There is a low probability that a C++ crash occurs in the render_service thread of the com.ohos.systemui process.|
| I78C9W | Memory leakage occurs in libace.z.so when a user touches an image in Gallery to maximize it and then exits repeatedly.|
| I7NWF3 | Due to compatibility issues, the session fails to be enabled for a Wi-Fi P2P connection between a device running 3.2.x and a device running 4.0.x.|
| I7BOAO | Multiple GLES3 test cases of the third-party repository fail to be executed.|


## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I80TOB | There is a possibility that the com.ohos.settings process (application: Settings) encounters app freezing because THREAD_BLOCK_6S is stuck in libbtframework.z.so.| This issue occurs occasionally. It can be resolved by re-opening the Settings application. The impact is controllable.| 2023-12-30|
| I83D6I | If Bluetooth is repeatedly enabled and disabled in Settings, there is a possibility that app freezing occurs.| This issue occurs occasionally. It can be resolved by restarting the device. The impact is controllable.| 2023-12-30|
| I86YLD | There is a low probability that the m.ohos.contacts thread of the com.ohos.contacts process (application: Contacts) encounters a C++ crash in the libipc_core.z.so stack.| This issue occurs at a low probability. It can be resolved by restarting the Contacts application. The impact is controllable.| 2023-12-30|
| I88UKM | There is a low probability that the ffrtwk/CPU-2-3 thread of the ohos.samples.distributedmusicplayer process (application: music player) encounters a C++ crash in the libuv.so stack.| This issue occurs at a low probability. It can be resolved by restarting the music player. The impact is controllable.| 2023-11-30|
| I89CLG | There is a low probability that the com.ohos.camera thread in the com.ohos.camera process (application: Camera) encounters a C++ crash in the libcamera_napi.z.so stack.| This issue occurs at a low probability. It can be resolved by restarting the Camera application. The impact is controllable.| 2023-12-30|
| I89F06 | There is a low probability that the com.ohos.note thread in the com.ohos.note process (application: Notepad) encounters a C++ crash in the libweb_engine.so stack.| This issue occurs at a low probability. It can be resolved by restarting the Notepad application. The impact is controllable.| 2023-12-30|
| I7SCU4 | There is a possibility that the com.ohos.photos process (application: Album) encounters app freezing because THREAD_BLOCK_6S is stuck in libark_jsruntime.so.| This issue occurs occasionally. It can be resolved by restarting the Album application. The impact is controllable.| 2023-11-30|
| I827LU | Memory leakage occurs when Bluetooth is enabled and disabled repeatedly in Settings. A memory leak of 15 MB occurs within one hour.| A memory leak of 8.3 KB occurs for one Bluetooth enable/disable operation. This issue can be resolved by restarting the device. The impact is controllable.<br>You are advised to use the protocol stack of the Bluetooth module built in the chip or hardware to avoid this issue.| 2023-12-30|
| I82V2W | Memory leakage occurs when Bluetooth is repeatedly enabled and disabled in Settings. The memory usage of Settings increases to 180 MB within one hour.| A memory leak of 0.2 MB occurs for one Bluetooth enable/disable operation. The issue can be resolved by re-opening Settings. The impact is controllable.<br>You are advised to use the protocol stack of the Bluetooth module built in the chip or hardware to avoid this issue.| 2023-12-30|
| I86M99<br>I88UV6<br>I88UVQ | A memory leak of 40 MB occurs during the long-term stability pressure test on foundation within 24 hours.| This issue can be resolved by restarting the device. The impact is controllable.| 2023-12-30|
| 31 kernel issues, such as I7TZ3V| 31 kernel issues, such as the kernel_bug function of the kernel btrfs_free_tree_block.| These issues are native Linux issues and no patch is available in the Linux community. These issues will be resolved once a patch is released in the Linux community. The function is not affected.| Following the Linux community|
| Vulnerabilities in 38 open-source components, such as I86CNJ| Vulnerabilities in 38 open-source components, such as lj-linux-131204684-0577967.| The vulnerabilities are being analyzed and will be resolved based on the vulnerability management process SLA of the community. The function is not affected.| Following the vulnerability management process SLA|
| I82NVZ | The image rendered by the GPU driver does not comply with the standard.| This issue is specific to the RK3568 driver and is not a system compatibility problem. It does not affect the compatibility certification of other products and hardware.| 2023-12-30|
