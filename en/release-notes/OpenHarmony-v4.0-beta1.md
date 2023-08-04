# OpenHarmony 4.0 Beta1


## Version Description

The standard system capabilities of OpenHarmony 4.0 are continuously improved. ArkUI further improves component capabilities and effects. The application framework optimizes ExtensionAbilities. Application packages can be installed without decompression and shared across applications. The unified data management framework (UDMF) is provided for distributed data management. The audio, media playback, media control, and camera capabilities of the multimedia subsystem are further enhanced. Badge management is added to the common event and notification subsystem. More key management capabilities are provided for the security subsystem. ArkCompiler updates the tool versions related to the C++ toolchain. The capabilities of multiple tools in the test framework are enhanced.

OpenHarmony 4.0 Beta1 provides the first batch of API version 10 interfaces.


### Application Framework

- ExtensionAbilities adopt minimal management. APIs of the ExtensionAbilities are provided based on service scenarios to prevent calling of sensitive APIs.

- Temporary, URI-based authorization is provided for data or files. An application can grant the read and write permissions of its own files to other applications.

- UIExtensionAbilities are provided. The UI provided by a UIExtensionAbility can be embedded in the window of the invoker application for display. Currently, the following basic UIExtensionAbility capabilities have been built:
  - Unified UIExtensionAbility template, with clear API definitions
  - Display of the native default ExtensionAbility page, as well as UI customization

  Templates such as Share and Picker will be gradually provided in later versions.

- Atomic services can be shared. You can use the **UIAbility.onShare()** lifecycle provided by the UIAbility component to set the data to share. Users can share atomic services and widgets to another device through the sharing box.


### ArkUI

Addition or enhancement of basic components:

- The ExtensionAbility component is provided so that you can embed the extended feature of an application into another application.

- The drawing components **\<Rect>**, **\<Circle>**, **\<Ellipse>**, **\<Line>**, **\<Polyline>**, **\<Polygon>**, **\<Path>**, **\<Rect>**, and **\<Shape>** support universal attributes such as translating, cropping, and masking.

- The mask color and animation can be customized for custom dialog boxes. For example, you can set parameters related to the animation effect.

- The **bindContextMenu** and **bindMenu** methods allow you to set menu positions.

- The divider set by the **\<ColumnSplit>** component can be dragged.

- The **\<Refresh>** component allows you to set the content to be displayed during pulling down to refresh.

- The width and height of the input string in the **\<Text>** component can be returned. If the string is not fully displayed, a dialog box showing the complete string is displayed when the mouse pointer is hovered over.

Addition or enhancement of the animation effect:

- Transition animation can be used for component attribute changes, for example, when the **\<Divider>** component is used to set the divider color and color attributes.

- You can set the spherical attributes, lower edge pixel stretching, adaptive color, G2 rounded corners, shadows, and gradient attributes for components to implement advanced animation effect.

Development efficiency improvement:

- You can hold the **\<Text>**, **\<Image>**, **\<Video>**, **\<ListItem>**, and **\<GridItem>** components and drag them to the desired position. You can also disable this feature so that no dragging will be triggered upon holding.


### Application Package Management

- Application packages can be installed without being decompressed, optimizing the system startup performance and application installation performance.

- Application packages can be shared across applications. System applications can provide their own capabilities to third-party applications. In addition, third-party applications do not need to integrate related content (including code, resources, and .so files) into their installation packages, reducing the integration and update costs.

- Enterprise applications can be installed. The installation permission of enterprise applications is verified to prevent unauthorized distribution and installation of enterprise applications. In addition, the enterprise application certificate information can be queried, facilitating the management and revocation of enterprise applications in the application market.


### Distributed Data Management

- System applications can silently access DataShareExtension data of other system applications through the data management service agent. That is, system applications can access DataShareExtension data of another system application without starting that application.

- System applications can access DataShareExtension data in single mode through the data management service agent.

- The DataShare client provides the capability of subscribing to DataShareExtension data changes by URI prefix. The DataShare client will be notified of any DataShareExtension data change under the subscribed URI prefix.

- The UDMF is added to support data standardization models, intra-device data dragging, UDMF data storage adaptation, permission management, and lifecycle management.


### File Management

- File category view management is supported. Gallery and other related applications manage media files in albums, indicating that images and videos do not need to pay attention to their storage locations. Functions such as adding and removing files in albums do not involve file I/O operations. Related APIs will be available in later versions.

- Enhanced file I/O access capabilities are provided, including **randomAccessFile**, **moveDir**, **copyDir**, and **watcher**.

- URI-based temporarily authorized file access and authorization revocation capabilities are supported, and cross-application local authorization or cross-device authorization are provided for files.


### Graphics & Window

**Graphics**

- Property animations with custom content are supported.

- Transition animation is provided when a component appears or disappears.

- The performance of the unified rendering mode is optimized, including IPC performance optimization (for example, transferring rendering resources in shared memory mode to reduce IPC traffic), component-level rendering optimization (only upper-layer components are rendered to reduce GPU rendering workload), and the use of hardware synthesizer.

- SVG decoding is supported for image encoding and decoding. Parameters, such as the total number of frames and time interval, are parsed for .gif files.

**Window**

- Listening for the focus status of a window is supported. In earlier versions, you can listen for the focus status of the window stage, but not that of system windows and application child windows. Now, you can register **'windowEvent'** to listen for the focused, out-of-focus, and hidden states of a window.

- The z-order of child windows can be adjusted to the top layer. In earlier versions, for multiple sub-windows created in an application, the system always displays the last window displayed at the top of all the other windows. In addition, a window that is last touched or clicked is displayed at the top by default. Now, by using the **aiseToAppTop** method of the window object, you can adjust any child window to the top of the child windows of the window stage.

- The immersive implementation mode is reconstructed to optimize the animation effect when an application is opened, exited, or redirected. In earlier versions, when an application is opened, the size of the full-screen application window does not contain the area of the status bar and navigation bar by default, unless the application calls **setWindowLayoutFullScreen** or **setSystemBarEnable** to enable immersive display. If an immersive application calls either APIs when it is being opened, the opening animation is displayed abnormally. In the new version, regardless of whether immersive display is enabled, the full-screen application window includes the status bar and navigation bar. The status bar and navigation bar of non-immersive applications are avoided by restricting the application display area through ArkUI.

- The **sourceMode** field is added to the **Screen** attribute so that the system application can determine whether the screen is used as the primary screen, mirror of the primary screen, or extended screen.

- The **stopMirror** and **stopExpand** APIs are added to the **Screen** module for you to stop screen mirroring or the extended mode.


### Multimedia 

**Audio Capability**

- You can use native APIs to implement audio playback and recording.

- You can query and listen for the playback device with the highest priority.

- You can adjust the alarm volume independently.

- Audio focus is supported. When playing an audio, an application does not need to apply for the focus. Instead, the system automatically applies for the focus in the background and executes the focus policy (such as pause, fade-out, and fade-out recovery). The application only needs to register a listener to receive focus interruption events and update the status, for example, stopping the progress bar when the program is paused.

**Playback Control Framework**

- Custom media information can be transmitted between the media provider and controller. The application can extend the media content display mode. For example, the controller can require the provider to display songs and lyrics in a special form.

- The framework capability of the media playlist is supported. The provider provides the playlist content, and the controller obtains the playlist content and selects any media content to play.

- The framework capability of historical playback records is supported. The AVSession framework provides the list of historical playback applications, sorted by playback sequence (including the applications that are being played and the applications that have exited).

- A transmission channel is provided for custom media events, for example, a transmission channel for lyric content. Through this channel, the provider provides the lyric content, and the controller obtains the lyric content.

- A transmission channel is provided for custom control commands. Through this channel, the controller sends custom control commands to the provider, for example, to require the provider to display bullet comments.

**Media Playback**

- HLS-based live streaming and data source-based streaming playback are supported.

- HDI-based H.265 video hardware decoding and playback are supported.

- Audio playback attributes can be set. Users can select the output audio type when using the player.

- Automatic rotation is supported for videos with rotation angles.

**Camera**

- The error codes and exception handling mechanism of ArkTS APIs are optimized so that you can use error codes to locate error information.

- The front camera provides preview mirroring. By default, the preview image on the front camera is mirrored.

- You can query the main device attributes of a distributed camera, including the device name and type.

- More refined resolution query is supported. You can query the supported size, format, and frame rate by preview, photographing, and recording usage.

- The camera framework provides a horizontal coordinate system [0, 0, 1, 1]. All coordinate-related operations are performed based on this coordinate system.

- When different camera applications use the same physical camera, the camera framework use priority control and mutual exclusion policies.


### Common Event and Notification

- Applications can enable or disable static event subscription.

- System applications can remove sticky events that have been published.

- Applications can set badges that represent the number of notifications.


### Communication & Connectivity

- NFC eSE card emulation is supported.

- A random MAC address can be used for connection to an AP through Wi-Fi.

- A static IP address can be used for connection to an API through Wi-Fi.


### Security

- The following key management capabilities are provided:
  - Deriving chip-level keys based on the GID
  - Import of the Chinese cryptography key
  - Fine-grained access control for secondary identity authentication
  - NO HASH mode for key management signature
  - Specifying key parameters during calculation

- The security levels of other devices can be queried on a small-system device.

- The RSA key signature digest and padding can be specified for signature and signature verification.


### Ability Access Control

- An application-specific permission management page can be opened.

- Identity verification is provided for system applications.


### ArkCompiler

- The task pool supports priority setting and automatic scaling algorithms.

- Hot reloading performance is optimized, and the multi-HAP scenario is supported.

- Multi-instance debugging is supported.

- CFG construction of abnormal functions is supported.

- The C++ compilation toolchain is updated as follows:
  - The Clang/LLVM toolchain is upgraded to 15.0.4.
  - The libc version is upgraded to 1.2.3. The interface performance of the libc library is optimized.
  - The sigaction function provides the sigchain function.


### Kernel

- The HCK framework is supported.

- Hierarchical configuration is provided for the Linux kernel.


### Driver

- The display hardware synthesis driver is decoupled from the chip platform, VDIs are provided, and an independent hardware synthesis process is used.

- The display driver process provides the dead event listener to improve system fault recovery.

- Detection of hot swap events and obtaining of camera modules are provided for USB cameras.

- The preview drive capability is provided for USB cameras.

- APIs are provided for querying audio effect capabilities, obtaining audio effect descriptors, and creating and destroying audio effect instances.

- The capabilities of control flows and data flows are enhanced for sensors and motions.


### Power Supply

- The capability of querying and reporting the system power level is enhanced. The power level can be customized.

- Wired and wireless charging types, including standard charging, fast charging, and super fast charging, can be reported.

- The management mechanism of the running lock is enhanced, and the system power status and level are specified.

- You can set the wakeup source, which can be the power button, mouse, keyboard, touchpad, screen, stylus, or leather case.

- You can set the sleep source, which can be the power button, leather case, or auto-sleep upon timeout.

- Development guides are provided for the management of power, battery, display brightness, power consumption statistics, and thermal.


### Pan-Sensor

- You can query the preset vibration effects supported by a device and check whether a vibration effect (specified by **EffectID**) is supported by the device.

- An API is provided for stopping the vibrator in any mode, so that you do not need to find the vibration mode in use in order to stop the vibrator.


### Test Framework

**Test Framework arkXtest**

- The definition capability is provided in the automatic script test suite for more flexible script design.

- The object-level assertion capability is provided for test scripts.

- The simulation of Chinese input, mouse operations, and area screenshots is provided.

**Self-Test Execution Framework developer_test**

- Test task management is improved. Now you can execute historical tasks by task ID.

- The precise test capability is provided. Now you can filter and execute test cases at the subsystem, component, test suite, and test case levels.

- You can execute HATS test cases.

**Stability Test Tool wukong**

Rotation event injection is supported.

**Performance Development Tool smartperf_host**

- Frame timeline capture and display capabilities are provided for you to capture and display frame freezing and frame loss data.

- Scheduling analysis capture and display capabilities are provided for you to capture and display data related to CPU scheduling analysis and thread scheduling analysis.

- Call stack visualization is used to display the symbolic results of .so files compiled. The proportions of functions in different libraries are displayed in pie charts.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.0 Beta1| NA |
| Public SDK | Ohos_sdk_public 4.0.7.5 (API Version 10 Beta1)| This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio| 4.0 Beta1| Recommended for developing OpenHarmony applications<br/>How to Obtain<br><br>SHA-256 checksum: 7d2885b052afb92af8eb2d28ce2704515cd5fdbe7dd01f874bcdd876e11b890a<br><br>SHA-256 checksum: ce2582eac70e8e15abcded00065ae0047f3815fe2b0c90d56c0bdbc5561a51c3<br><br>SHA-256 checksum: 5da2baad7475857a1c59315663b7dcdf85219ffd652d5a7be160c8d2225358a7 |
| (Optional) HUAWEI DevEco Device Tool| 3.1 Release| Recommended for developing OpenHarmony smart devices<br/>How to Obtain<br>[Click here to go to the download page](https://device.harmonyos.com/cn/develop/ide#download). |


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.0 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/code-v4.0-Beta1.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/code-v4.0-Beta1.tar.gz.sha256) | 26.2 GB |
| Hi3861 solution (binary)       | 4.0 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_pegasus.tar.gz.sha256) | 25.1 MB |
| Hi3516 solution-LiteOS (binary)| 4.0 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_taurus_LiteOS.tar.gz.sha256) | 287.6 MB |
| Hi3516 solution-Linux (binary) | 4.0 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_taurus_Linux.tar.gz.sha256) | 186.4 MB |
| RK3568 standard system solution (binary)       | 4.0 Beta1    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/dayu200_standard_arm32.tar.gz.sha256) | 4.5 GB |
| Public SDK package for the standard system (macOS)            | 4.0.7.5      | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/ohos-sdk-mac-public-20230605.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/ohos-sdk-mac-public-20230605.tar.gz.sha256) | 718.2 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.0.7.5      | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/L2-SDK-MAC-M1-PUBLIC-20230605.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/L2-SDK-MAC-M1-PUBLIC-20230605.tar.gz.sha256) | 673.2 MB |
| Public SDK package for the standard system (Windows\Linux)  | 4.0.7.5      | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/ohos-sdk-windows_linux-public-20230605.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/ohos-sdk-windows_linux-public-20230605.tar.gz.sha256) | 1.8 GB |

## What's New

This version has the following updates to OpenHarmony 3.2 Release.

### APIs

For details about the API changes over OpenHarmony 3.2 Release, see [API Differences](api-diff/v4.0-beta1/Readme-EN.md). A few API changes may affect applications developed using API version 9 or earlier. For details about the change impact and adaptation guide, see [Changelogs](changelogs/v4.0-beta1/Readme-EN.md).


### Feature Updates

[Version Description](#version-description)

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

**Table 3** New samples

| Subsystem| Name| Introduction| Programming Language|
| -------- | -------- | -------- | -------- |
| Multimedia | [AVSession - Controller](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta1/code/BasicFeature/Media/AVSession/MediaController) (for system applications only)| This sample shows the features of MediaController. It uses \@ohos.multimedia.avsession to implement custom information exchange between the provider and controller.| ArkTS |
| Multimedia | [AVSession - Provider](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta1/code/BasicFeature/Media/AVSession/MediaProvider)| This sample shows the features of MediaProvider. It uses \@ohos.multimedia.avsession to implement custom information exchange between the provider and controller.| ArkTS |
| Multimedia | [Audio Management](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta1/code/BasicFeature/Media/Audio)| This sample demonstrates audio-related features. It uses \@ohos.multimedia.audio to switch and query the audio device and implement audio interruption.| ArkTS |

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).


## Resolved Issues

**Table 4** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| I70PRZ | The avoid area for non-immersive UI is invalid.|
| I72F9P | There is a high probability that the IPC_2_29472 thread in the ohos.samples.distributedcalc process causes a C++ crash in libwindow_native_kit.z.so.|
| I6W7ZX | Non-immersive windows penetrate the home screen.|
| I76QTN | There is a high probability that the IPC_0_18272 thread in the ohos.samples.distributedmusicplayer process causes a C++ crash in libruntime.z.so.|
| I71TCX | When a call is made without a SIM card, the call is not automatically disconnected after the CallUI is started.|
| I77PZK | There is a high probability that the RSRenderThread thread in the com.ohos.systemui process causes a C++ crash in libmali-bifrost-g52-g2p0-ohos.so.|
| I73CUZ | Competition exists in prepare_to_wait_event, leading to UAF.|
| I770WV | Preview images cannot be backed up.|
| I6ZDHJ | If **undefined** is passed in for an optional parameter of a globalization API, the default value is not used.|
| I71KZA | If **null** is passed in for an optional parameter of a globalization API, the default value is not used.|
| I6YT0U | There is a high probability that the libeventhandler.z.so stack encounters app freezing in the com.ohos.launcher process.|
| I6YSE5 | There is a high probability that the com.ohos.photos thread in the com.ohos.photos process causes a C++ crash in librender_service_base.z.so.|
| I77AUK | Calling **connectAbility** fails in distributed scheduling scenarios.|
| I78J10 | The home screen does not respond when a large folder is dragged repeatedly.|
| I7975U | When a user opens an image in a gallery application and returns to the previous page, a blank page is displayed.|


## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I78CH7 | Memory leakage occurs in libace.z.so when applications are repeatedly added to or removed from the dock bar.| Each time a widget is moved to a valid area, 99 KB memory of the ArkUI module leaks. This operation scenario is uncommon, and the leak issue disappears after the application is restarted. The impact is controllable.| 2023-07-15|
| I78CBC | Memory leakage occurs in libace.z.so when a user touches an image folder in Gallery to browse images in grid form and then exits repeatedly.| Each time the user touches an image folder in Gallery to browse images in grid form and then exits, 19 KB memory of the ArkUI module leaks. When the user touches Back on the application, the leak issue disappears. The impact is controllable.| 2023-07-15|
| I78C9W | Memory leakage occurs in libace.z.so when a user touches an image in Gallery to maximize it and then exits repeatedly.| Each time the user touches an image in Gallery to maximize it and then exits, 10 KB memory of the ArkUI module leaks. When the user touches Back on the application, the leak issue disappears. The impact is controllable.| 2023-07-15|
| I6U4ZT | The first photo in Gallery cannot be opened when the power supply is disconnected immediately after the photo is taken.| This problem occurs only in the immediate power-off scenario. A new set of mediaLibrary APIs needs to be adapted. The impact is controllable.| 2023-06-30|
| I79752 | There is a medium probability that the .ohos.smartperf thread of the com.ohos.smartperf process causes a C++ crash in libark_jsruntime.so.| This issue neither occurs in core applications nor affects ARP indicators. The impact is controllable.| 2023-06-30|
| I79P3K | There is a low probability that the onDestroy stack encounters a JS crash in the com.ohos.callui process.| The application will be reinstalled after the JS crash. This issue does not affect the use of the Call application.| 2023-06-30|
| I79TCB | There is a low probability that the VizCompositorTh thread of the com.ohos.note process causes a C++ crash in libweb_engine.soTh.| The application will be reinstalled after the JS crash. This issue does not affect the use of the Note application.| 2023-06-30|
