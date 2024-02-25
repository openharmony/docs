# OpenHarmony 4.1 Beta1


## Version Description

OpenHarmony 4.1 Beta1 further enhances the standard system capabilities. ArkUI improves component capabilities and effects. The graphics subsystem and window manager subsystem enhance animation and window adaptation. The application framework provides enhanced ExtensionAbilities. DSoftBus enhances its connection capability and specifications. The multimedia subsystem improves audio and camera framework capabilities. The test framework enhances the capabilities of multiple tools.

OpenHarmony 4.1 Beta1 provides the first batch of API version 11 interfaces.


### Application Framework

- The AutoFill framework is provided, which enables system applications to implement the password safe feature and provide password-free login for users.

- The **resFile** directory can be obtained through context.

- The UIExtensionAbility capability is enhanced. The **SetReceiveDataForResultCallback** API and its synchronous callback are provided. The **StartAsCaller** API is provided. Multi-instances are supported.

- Batch URI authorization is supported during the launch of the UIAbility and UIExtensionAbility.

- Applications can customize system environment parameters and choose whether to update the display effect according to the system configuration.

- The InsightIntent framework capability is supported. The UIAbility, UIExtensionAbility, and ServiceExtensionAbility can bind with an InsightIntent.

- Import of .abc files is supported.

- The widget capability is enhanced. The on-click callback, redirection to deep-link upon click, query of unused widgets, single-color mode for lock-screen widgets, and status saving and restoration are supported, and new lock-screen widget specifications are provided.


### ArkUI

NodeContainer is added to enhance custom drawing.

The text and container components are enhanced as follows:

- The **\<TextInput>** and **\<Text>** components support character-based truncation.

- The **\<TextArea>** component supports custom behavior of the **Enter** key.

- The **\<TextInput>** and **\<TextArea>** components support obtaining of the caret position.

- Intelligent word segmentation is supported. The logic for inserting the caret based on the word segmentation result is added, and the word segmentation algorithm is replaced.

- The **\<ImageSpan>** component supports custom long-press menu events as well as component indentation and alignment.

- The **\<Swiper>** component supports nested scrolling.

- Through **ScrollToIndex**, the **\<List>** component can specify the target list item to scroll to in the list item group.

- The **\<Grid>** and **\<WaterFlow>** components support scrolling to the target list item, with a transition animation displayed during the scrolling.

- A bounce effect can be enabled for scrollable components when there is less than one screen of content.

The AI capabilities of the components are enhanced as follows:

- The **\<TextInput>** component and its related components support visual input.

- The **\<Text>**, **\<RichEditor>**, and related components support text entity recognition.

Status management is enhanced as follows:

- The undefined, null, and union types are supported.

- The **\<ListItem>** component can update methods in the **ForEach** and **LazyForEach** attributes.

- The **\@LocalStorageLink** and **\@LocalStorageProp** decorators are not updated when they are not activated.


### Bundle Management

- Unified access to basic resources is supported. You can query application icons and names.

- The quick fix capability can be used during application debugging.

- Driver applications can be installed, updated, and uninstalled.

- Menus can be configured and queried.

- Signature transfer is supported. The app-identifier in the signing certificate is used as the unique identifier of an application.

- The validity of .abc files can be verified. Only .abc files that pass the verification can run on a restricted VM.

- Connection to the unified file preview framework is provided. Files can be opened using this framework.

- A package scanning tool is provided to scan for large files and duplicate files, and collect statistics on the size and proportion by file type.

- The packing tool can pack files with the specified version number.


### DSoftBus

- The connection capability and specifications are further enhanced. For example, P2Pv2 is supported; passive release based on service policies is supported; connection reliability confirmation is added for link selection; resource awareness and dynamic connection parameter setting are supported.

- The IPC reference technology query interface and timestamp query interface are supported to enhance maintenance and debugging.


### Distributed Data Management

- An RDB can be created in the subdirectory of the specified application sandbox path, which further improves the flexibility of data usage while securing application data.

- Standard data definitions and descriptors of the Unified Data Management Framework (UDMF), query of standard data types, data access authorization and management, and application-defined data types are supported.

- Cross-device synchronization is not allowed for data without security levels.

- The preferences data supports modification, query, and persistence of data streams in Uint8Array format.


### Distributed Hardware

- Key status management in special distributed input scenarios is optimized.

- Service reliability is enhanced for distributed camera, audio, display, and input scenarios.


### File Management

- System applications, such as Gallery, support group query by year, month, and day.

- System applications, such as Gallery, support reversion of file edits, file hiding, and private albums.

- The thumbnail access performance of Gallery in sliding scenarios is improved by more than 20%.

- The application access framework is enhanced, and APIs such as readline() and lseek() are supported.


### Graphics and Window Manager

**Graphics**

- HDR Vivid videos can be rendered and displayed.

- The graphics NDK capability is enhanced. The **OnFrameAvailableListener** callback is provided for native Image APIs. Primary colors can be set for the native window. The OpenGL extension APIs are supported.

- You can specify a window not to be recorded during screen recording. A privacy window can be recorded as a pure black image.

- The system resolution can be adjusted.

- APIs are provided to adjust the system frame rate based on the animation and adjust the application frame rate.

- The animation capability is enhanced. The cut-out and rounded screen are supported, and navigation transition animation supports element sharing.

- The graphics rendering pipeline supports the Vulkan backend.

- The native buffer APIs support the metadata setting to adapt to the transmission of dynamic metadata with frames in HDR video scenarios.

**Window Manager**

- The global window resolution can be adjusted. Notifications about the window blocking status and window interactive/non-interactive status can be sent. The window mode change can be listened for. The watermark capability is supported.

- APIs are provided to set the initial size and position of a window, zoom in, zoom out, stretch, and drag a subwindow, minimize or hide a window, query the minimum and maximum sizes supported by a window, drag a window to the top, set a window not be blocked by a floating window, and query the size of the rectangle that can be drawn in the window.

- The window focus can be shifted to a target window in the same application.

- Window events can be distributed on multiple screens, multi-modal pop-up windows are supported, click events outside the window can be listened for, and the input method area can be excluded from the listening.

- The animation of switching the window form, multi-task linkage animation of the soft keyboard, and animations of entering and exiting the input method soft keyboard are supported.

- The multi-window feature supports PiP and allows users to exchange the positions of split-screen windows.

- Basic screen management APIs are provided to power on or off a screen and query available areas on the screen.

- APIs are provided for setting the color space, HDR, format, and window filters of the virtual screen, updating the virtual screen size, and disabling screen capture and mirroring of the virtual screen.

- The multi-screen management framework provides APIs for setting the window display, migrating windows between screens, and displaying windows from different sources.


### Multimedia

A batch of device-oriented HDI interfaces is provided, including interfaces for the camera framework and audio.

The camera framework and applications can smoothly transition from the current zoom value to the target zoom value.

APIs are provided to turn on or off the flashlight, query the flashlight status, and obtain flashlight status changes.

The video stabilization mode is supported to ensure image stability during video recording.

The camera supports the QR code scan mode.

The bottom layer can identify the system status (such as the falling status) so that the relatively fragile components (such as the aperture) of the camera can be turned off when the device is falling down.

Audio calls on cellular networks can be recorded.

The audio-haptic feature is supported. Vibrator HDI interfaces are provided to query vibration information, set the vibration type and delay, and deliver HD vibration data.


### Common Event and Notification

- Emitter supports subscription by string type. The number of subscribers can be obtained. The serializable data type is supported. The maximum data size is increased to 16 MB.

- An application can subscribe to custom events sent by itself.

- System applications can create system live view notifications.

- A reminder can be set to repeat every week.

- Reminders of the same group in the same schedule can be canceled by group ID.

- The notification button supports automatic language switching. When a button resource ID is set, the button title in the notification can be automatically switched to the system language.


### Connectivity

- NFC supports HCE card emulation and allows users to set the default payment application.

- BLE broadcast can be dynamically enabled or disabled. MDM applications can call Bluetooth APIs to forcibly disable Bluetooth and restrict Bluetooth enabling. APIs are also provided to check whether a device is discoverable and obtain the Bluetooth pairing status based on the device address.

- Wi-Fi APIs are provided to check whether the currently connected hotspot is a phone hotspot, set a device as a hotspot, and add a STA device to the blocklist.


### Location Service

- The **sendCommand** API can be used to delete auxiliary data, thereby providing support for cold and warm start tests.

- APIs are provided for geocoding, reverse geocoding, and geocoding service status query.

- MDM applications can call the location service APIs to forcibly enable or disable the location service.


### Telephony Service

- SMS messages can be added, deleted, modified, and queried by SIM card.

- Roaming admission requirements are supported. The names of the visited network and home network can be displayed. Special processing of emergency calls in roaming scenarios is supported.

- APIs are provided to receive cell broadcast messages reported by operators.

- Call interception is supported. The call interception framework is provided to support three-party access. A number blocklist is used.

- Management of multiple time zone sources is supported. For a country with multiple time zones, the time zone can be updated based on the NITZ, geographical location, and priority. For a country with a single time zone, the time zone can be updated based on the NITZ, country code, geographical location, and priority.

- Other mobile communication-related capabilities and specifications are improved as follows:
  - SIM cards of China Broadnet (a carrier in China) are supported.
  - TDM/Dual SIM Dual Active (DSDA) is supported. In dual-SIM scenarios, when there is a new call to one SIM card while the other SIM card is engaged in a call, the ongoing call is automatically placed on hold and the phone rings. When one SIM card is engaged in a call, you can make a new call from the other SIM card.
  - Dual SIM Dual Standby (DSDS) is supported. In dual-SIM scenarios, when there is a new call to one SIM card while the other SIM card is engaged in a call, the ongoing call automatically ends and the phone rings.
  - APN matching based on SPNs, IMSI prefixes, GIDs, or ICCIDs is provided for virtual cards.
  - The network search performance is improved when the phone is powered on and the airplane mode is disabled.


### Network Management

- LAN route management is supported, and you can configure attributes such as the IP address of the network adapter, route, and static ARP table.

- In addition to the complete UDP socket capabilities, the following capabilities are supported: joining or leaving a group, setting and obtaining the TTL, and sending data.

- Applications can obtain socket-based traffic statistics through the network management APIs.

- APIs are provided to read the configuration file of an application-level network proxy.

- The network connectivity detection mechanism is optimized, including the detection period and detection protocol. The detection state machine is reconstructed.


### Power Supply

**Power Management**

- You can set the operation of pressing the power button or closing the cover to make your device sleep or turn off the screen.

- When a device is woken up, the wakeup reason can be obtained by reading a specific system node, and the corresponding action, such as power-off, can be performed based on the wakeup reason.

- The processing of screen on/off behavior such as pressing the power button in multi-device collaboration mode is supported. Hardware input and software injection can be distinguished and processed differently.

- APIs are provided to control the power status and process related states when multi-device collaboration is successful or disconnected.

- APIs are provided to support the display status and related state processing when the screen is turned off but the image output is not stopped.

- The LCD is not powered off when the AOD is configured and the device screen is locked.

- Normal shutdown can be triggered in low-voltage scenarios.

- You can press and hold the power button to trigger vibration of the power-off dialog box. You can also disable vibration on specific devices.

- The device vibrates when it starts charging. You can disable vibration on specific devices.

**Thermal Management**

- New scenarios and status can be customized for temperature control decision-making.

- The thermal escape level is added. A notification is sent when the escape temperature is reached.

- Custom temperature control actions can be configured for drive nodes. When temperature control is triggered, the action value is written to the corresponding node.

**Other**

- Drivers can report events and trigger actions.

- An application can query and report information about the CPU lock it holds. The CPU lock status can be reported through the callback of the power service APIs or HiSysEvent, and can be queried through the APIs. The NAP service can subscribe to the preceding information.


### Security

- KMS supports the access control mode of **valid when a password is set**.

- The crypto framework supports the PBKDF2 algorithm, optional AAD parameters for symmetric keys, variable-length key HMAC, DH/25519 algorithm, Brainpool curve, SM2 key parsing and parameter processing, and curve name-based key generation.

- Private certificate credential management APIs are provided to specify the signature padding mode and hash algorithm.


### User IAM

- Redundant user identity credentials can be deleted.

- Haptic feedbacks are provided upon authentication failure.

- The fingerprint feature can be disabled.


### ArkCompiler

- SmartGC supports 90-frame scenarios and GC control in performance-sensitive scenarios.

- TaskPool supports thread interruption and exit, precise import, and default transfer mechanism.

- C++ exception capture is supported.


### Kernel

The ko module can be independently built outside the kernel tree, and an independent ko partition chip_ckm is provided.


### Multimodal Input

- APIs are provided to customize the pointer interaction coordinates and update the pointer position.

- APIs are provided for processing key press events by priority.

- Touch target detection is supported for the mouse pointer.

- Recognition of the two-finger pinch gesture and rotation gesture is supported.

- Recognition of the three-finger tap gesture is supported.

- APIs are provided for management and listening of global combination keys.

- Users can double-tap the power button to start a specified ability.

- The UX attributes (size and color, currently) of the mouse pointer can be set.

- The animation style of the mouse pointer can be set.


### Pan-Sensor

- The sensor precision can be reported.

- Native APIs are provided for sensor and haptic control.

- The device folding status and spatial audio status can be reported.

- Dynamic and static adjustment of vibration is supported.

- A haptic control switch is provided.


### Test Framework

**Automated Test Framework arkXtest**

- Simulation of UI operations, such as scrolling the mouse wheel and double-clicking the left or right mouse button, is supported.

- Using shell commands to simulate UI operations, such as click, scroll, double-click, and text input, is supported.

- The efficiency of searching for component information in the UI test framework is improved.

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

- The speed and accuracy of identifying power consumption exceptions are improved. Richer power consumption information is provided for main components to facilitate fault locating. In-depth analysis is supported for component-specific power consumption exceptions caused by applications.

- The system memory details collection plug-in is supported to collect ION, GPU/Skia, and purgeable memory information (hidumper hiprofiler).

- Time consumption analysis in animation scenarios is supported. You can collect information about animation settings (start, exit, screen switch, transition, and sliding), animation start and end dotting, and associated graphics frames.


### Upload/Download

- The response body that exceeds the IPC limit can be returned in upload scenarios.

- File segments can be uploaded.

- The background task progress can be updated, and a callback is provided for status changes.

- The status change event of an upload or download task can be reported.

- An upload or download task can be continued after an application or a background Service ability is restarted.

- Priority is supported. High-priority tasks of the high-priority application (application that has focus) are executed first and occupy more network bandwidth.


### Input Method Framework

- The **inputMethodList** module is provided.

- The input method application proxy is supported.

- Visual input is supported for the input method framework.

- APIs are provided for querying the display status of the input method keyboard window.

- The system security keyboard is supported.

- The security mode is supported.


### Time and Time Zone

- User awareness configuration is provided.

- The NTP server can be customized.


### AI

- Native AI training interfaces on the device side are provided.

- ArkTS APIs are provided for configuring the NNRt backend.


### Web

- WebRTC capabilities are optimized to support meeting participation, sharing, speaking, and camera capabilities.

- APIs are provided for obtaining W3C time zone and sensing the virtual keyboard.

- The CSS cursor style is optimized.

- The over-scrolling effect is provided for web pages.

- Injection scripts can be executed when a document is started.

- PostURL is supported.

- Nested scrolling is supported.

- AVCodec hardware decoding can be used for videos played on web pages.

- WebCookieManager can be used independently from the **\<Web>** component.

- The **\<Web>** component supports interconnection with the accessibility feature.

- The **\<Web>** component kernel is upgraded from Chromium 99 to Chromium 114.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 4.1 Beta1 | NA | 
| Public SDK | Ohos_sdk_public 4.1.5.3 (API Version 11 Beta1) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.| 
| (Optional) HUAWEI DevEco Studio| 4.1 Beta1 | Recommended for developing OpenHarmony applications<br>*To be provided*| 
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.1-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.1-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.1 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/code-v4.1-Beta1.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/code-v4.1-Beta1.tar.gz.sha256)| 31.0 GB |
| Hi3861 solution (binary)       | 4.1 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_pegasus.tar.gz.sha256)| 28.7 MB |
| Hi3516 solution-LiteOS (binary)| 4.1 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_taurus_LiteOS.tar.gz.sha256)| 316 MB |
| Hi3516 solution-Linux (binary) | 4.1 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_taurus_Linux.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_taurus_Linux.tar.gz.sha256)| 213 MB |
| RK3568 standard system solution (binary)       | 4.1 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/dayu200_standard_arm32.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/dayu200_standard_arm32.tar.gz.sha256)| 	7.9 GB |
| Public SDK package for the standard system (macOS)            | 4.1.5.3      | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/ohos-sdk-mac-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/ohos-sdk-mac-public.tar.gz.sha256)| 926 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.1.5.3     | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 883 MB |
| Public SDK package for the standard system (Windows\Linux)  | 4.1.5.3      | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |

## What's New

This version has the following updates to OpenHarmony 4.0 Release.

### API Updates

For details about the API changes over OpenHarmony 4.0 Release, see [API Differences](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Beta1/en/release-notes/api-diff/v4.1-beta1/Readme-EN.md).

A few API changes over OpenHarmony 4.0 Release may cause your application projects to be incompatible. For details about these changes, see [Changelogs](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Beta1/en/release-notes/changelogs/v4.1-beta1/Readme-EN.md).


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

**Table 3** New samples

| Feature| Name| Introduction| Programming Language| 
| -------- | -------- | -------- | -------- |
| Basic capabilities| [Basic Capability Enhancement](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/Ability/AbilityFeatureSystem) (Full SDK; API level: system_basic)| This sample uses APIs such as [ohos.app.ability.appManager](../application-dev/reference/apis/js-apis-app-ability-appManager.md), [UIAbilityContext](../application-dev/reference/apis/js-apis-inner-application-uiAbilityContext.md), and [UIExtensionContentSession](../application-dev/reference/apis/js-apis-app-ability-uiExtensionContentSession.md) to implement the following features: querying whether an application is running; creating a UIExtensionAbility for a model system or model application; synchronously returning data; implicitly starting the UIExtensionAbility; providing StartAsCaller.| ArkTS | 
| System functions| [AutoFill](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/AutoFill/AutoFill) (Full SDK; API level: system_basic)| This sample uses APIs such as [application/AutoFillRequest](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/AutoFillRequest.d.ts), [@ohos.app.ability.AutoFillExtensionAbility](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.AutoFillExtensionAbility.d.ts), [application/ViewData](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/ViewData.d.ts), and [@ohos.app.ability.autoFillManager](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.autoFillManager.d.ts) to show how to use the AutoFill framework.| ArkTS | 
| Widget| [ArkTS Widget Capability Enhancement](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/ArkTSCard/ArkTSCard) (Full SDK; API level: system_basic)| This sample demonstrates dynamic and static lock-screen widgets/deep-link widgets. (In the **form_config.json** file, if **isDynamic** is set to **false**, the widget is static; if **isDynamic** is set to **true**, the widget is dynamic.)| ArkTS | 
| System functions| [InsightIntent Execution](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/InsightIntent/IntentExecute)<br>(Full SDK; API level: system_basic)| This sample uses APIs such as [@ohos.app.ability.InsightIntentExecutor](../application-dev/reference/apis/js-apis-app-ability-insightIntentExecutor.md), [@ohos.app.ability.insightIntent](../application-dev/reference/apis/js-apis-app-ability-insightIntent.md), and [@ohos.app.ability.insightIntentDriver](../application-dev/reference/apis/js-apis-app-ability-insightIntentDriver.md) to demonstrate two InsightIntent execution methods: binding an InsightIntent to a foreground UIAbility and binding an InsightIntent to a ServiceExtension. The methods include constructing an InsightIntent configuration file, constructing InsightIntent execution parameters, triggering InsightIntent execution, and obtaining the InsightIntent invoking result.| ArkTS | 
| Basic features| [Native Window](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/BasicFeature/Native/NdkNativeWindow) | This sample describes how to use the [native XComponent](../application-dev/reference/native-apis/native__interface__xcomponent_8h.md) to obtain a [native window](../application-dev/reference/native-apis/_native_window.md) and change the rectangle color by filling data. It also demonstrates how to obtain a native window from a [native image](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/native-apis/_o_h___native_image.md) for buffer rotation. The native window is used to generate the buffer to trigger the callback of available frames of the native image.| ArkTS | 
| Basic features| [Standardized Data Definition and Description](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/BasicFeature/DataManagement/UDMF/UniformTypeDescriptor/UTDType) (Full SDK)| This sample demonstrates the standard data definitions and descriptors. It uses APIs such as [@ohos.data.uniformTypeDescriptor](../application-dev/reference/apis/js-apis-data-uniformTypeDescriptor.md), [@ohos.file.fs](../application-dev/reference/apis/js-apis-file-fs.md), and [@ohos.router](../application-dev/reference/apis/js-apis-router.md) to implement the following features: adding preset media files, obtaining the UTD standard type of media files, querying the UTD type, obtaining the default icon of the UTD type corresponding to a file, and customizing data types.| ArkTS | 
| Multimedia| [Audio Management](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/Media/Audio) (Full SDK; API level: system_basic)| This sample demonstrates how to use the following [spatial audio APIs](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.multimedia.audio.d.ts):<br>isSpatializationSupported(): checks whether the system supports spatial audio.<br>isHeadTrackingSupported(): checks whether the system supports head tracking,<br>isSpatializationSupportedForDevice(deviceDescriptor: AudioDeviceDescriptor): checks whether the device supports spatial audio.<br>isHeadTrackingSupportedForDevice(deviceDescriptor: AudioDeviceDescriptor): checks whether the device supports head tracking.<br>isSpatializationEnabled(): checks whether spatial audio is enabled.<br>isHeadTrackingEnabled(): checks whether head tracking is enabled.<br>setSpatializationEnabled(enable: boolean): enables or disables spatial audio.<br>setHeadTrackingEnabled(enable: boolean): enables or disables head tracking.| ArkTS | 
| Basic capabilities| [Basic Capability Enhancement](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/BasicFeature/Ability/AbilityFeature)| This sample uses APIs such as [ApplicationContext](../application-dev/reference/apis/js-apis-inner-application-applicationContext.md), [ohos.ability.wantConstant](../application-dev/reference/apis/js-apis-ability-wantConstant.md), and [ohos.app.ability.StartOptions](../application-dev/reference/apis/js-apis-app-ability-startOptions.md) to implement the following features: customizing system environment parameters; not displaying a dialog box when the number of implicit launches is 0; adding a flag; clearing up application data; using the ability startup parameters to transfer the initial position, initial size, and animation.| ArkTS | 

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).


## Resolved Issues

**Table 4** Resolved issues

| Issue No.| Description| 
| -------- | -------- |
| I80TOB | There is a possibility that the com.ohos.settings process (application: Settings) encounters an app freeze because THREAD_BLOCK_6S is stuck in libbtframework.z.so.| 
| I89F06 | There is a low probability that the com.ohos.note thread in the com.ohos.note process (application: Notepad) encounters a C++ crash in the libweb_engine.so stack.| 
| I7SCU4 | There is a possibility that the com.ohos.photos process (application: Album) encounters an app freeze because THREAD_BLOCK_6S is stuck in libark_jsruntime.so.| 
| Vulnerabilities (such as I86CNJ) in 38 open-source components| Vulnerabilities (such as lj-linux-131204684-0577967) in 38 open-source components.| 
| I86YLD | There is a low probability that the m.ohos.contacts thread of the com.ohos.contacts process (application: Contacts) encounters a C++ crash in the libipc_core.z.so stack.| 
| I88UKM | There is a low probability that the ffrtwk/CPU-2-3 thread of the ohos.samples.distributedmusicplayer process (application: music player) encounters a C++ crash in the libuv.so stack.| 
| I89CLG | There is a low probability that the com.ohos.camera thread in the com.ohos.camera process (application: Camera) encounters a C++ crash in the libcamera_napi.z.so stack.| 
| I86M99<br>I88UV6<br>I88UVQ | A memory leak of 40 MB occurs during the long-term stability pressure test on foundation within 24 hours.| 
| 31 kernel issues, such as I7TZ3V| 31 kernel issues, such as the kernel_bug function of the kernel btrfs_free_tree_block.| 
| I82NVZ | The image rendered by the GPU driver does not comply with the standard.| 


## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By| 
| -------- | -------- | -------- | -------- |
| I8PEOF | A system freeze may occur due to LIFECYCLE_TIMEOUT of the com.ohos.mms process. As such, a white screen is displayed.| This issue occurs occasionally. It can be resolved by restarting the device. The impact is controllable.| January 15| 
| I8QET3 | A C++ crash may occur in libbluetooth_server.z.so of the OS_IPC_10_25363 thread of the bluetooth_servi process. As such, the Bluetooth service is abnormal.| This issue occurs occasionally. It can be automatically restored, and users are unaware of the exception.| February 28| 
| I8QH9S | A C++ crash may occur in libnative_appdatafwk.z.so of the os.settingsdata thread of the com.ohos.settingsdata process. As such, the background data management process stops.| This issue occurs rarely. The process automatically restarts when a new access request is received. Users are unaware of the exception.| January 15| 
| I8QNI7 | A system freeze may occur due to SERVICE_BLOCK of the foundation process.| This issue occurs rarely. Users are unaware of the exception.| February 28| 
| I8QSZ1 | An app freeze occurs in libsamgr_proxy.z.so of the com.ohos.systemui process, due to THREAD_BLOCK_6S.| This issue occurs occasionally. There is an extremely low probability that the system UI does not respond when the user slides down, and the user has to turn on and off Bluetooth on the Settings screen or restart the phone. The impact is controllable.| February 28| 
| Vulnerabilities (such as I7TYTF) in 43 open-source components| 43 open-source component vulnerabilities, such as protection_fault in the errseq_set function of the kernel| The vulnerabilities are being analyzed and will be resolved based on the vulnerability management process SLA of the community.| By vulnerability SLA| 
| I78THF | The maligpu version in the RK3568 kernel patch is too old (11.29), and a large number of CVE vulnerabilities are not fixed.| The GPU Mali driver of RK3568 has many unfixed CVE vulnerabilities, such as CVE-2021-28663 and CVE-2021-39793. These vulnerabilities can be exploited to obtain the kernel UAF and escalate privileges.| February 10| 
| I83D6I | If Bluetooth is repeatedly enabled and disabled in Settings, there is a possibility that an app freeze occurs.| This issue occurs occasionally. It can be resolved by restarting the device. The impact is controllable.| February 28| 
| I827LU | Memory leakage occurs when Bluetooth is enabled and disabled repeatedly in Settings. A memory leak of 15 MB occurs within one hour.| A memory leak of 8.3 KB occurs for one Bluetooth enable/disable operation. This issue can be resolved by restarting the device. The impact is controllable.| February 28| 
| I82V2W | Memory leakage occurs when Bluetooth is repeatedly enabled and disabled in Settings. The memory usage of Settings increases to 180 MB within one hour.| You are advised to use the protocol stack of the Bluetooth module built in the chip or hardware to avoid this issue.<br>A memory leak of 0.2 MB occurs for one Bluetooth enable/disable operation. The issue can be resolved by re-opening Settings. The impact is controllable.<br>You are advised to use the protocol stack of the Bluetooth module built in the chip or hardware to avoid this issue.| February 28| 
