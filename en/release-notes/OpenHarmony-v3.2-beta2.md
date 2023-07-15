# OpenHarmony 3.2 Beta2


## Version Description

OpenHarmony 3.2 Beta2 provides the following enhancements over OpenHarmony 3.2 Beta1:

**Enhanced basic capabilities for the standard system**

Added the multi-hotspot distribution mechanism for the window.

Added the restart recovery mechanism for power management.

Added the stylus pressure and tilt in events, and added key input support for multimodal input.

Added the preset application pre-authorization mechanism and fingerprint enrolling/authentication/identification framework to the security domain.

Added selfie mirroring in recording mode, audio control and audio effect control, infrared device input, audio USB insertion/removal identification, and event reporting to the driver.

**Enhanced application framework capabilities for the standard system**

The ability allows addition of static and dynamic widgets, startup of abilities that are not locally installed, SA-initiated ability startup and access, singleton ability continuation, sandbox application opening during running management, and no display of system application abilities in the latest mission list.

Bundle management provides NDK interfaces for obtaining the bundle name and certificate fingerprint information of the current bundle, querying the pack information of a specified application, and aging and uninstalling atomic services.

**Application development samples for the standard system** 

Added samples such as Gobang, QR code generation and parsing, widget usage, multimedia, short video, and facial recognition, helping developers quickly use basic capabilities of OpenHarmony.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.2 Beta2 | NA |
| Public SDK | Ohos_sdk_public 3.2.5.5 (API Version 9 Beta2)<br>Ohos_sdk_public 3.2.5.6 (API Version 9 Beta2) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio.|
| Full SDK | Ohos_sdk_full 3.2.5.5 (API Version 9 Beta2)<br>Ohos_sdk_full 3.2.5.6 (API Version 9 Beta2) | This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the full SDK, manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| (Optional) HUAWEI DevEco Studio| 3.0 Beta4 | This tool is recommended for developing OpenHarmony applications.|
| (Optional) HUAWEI DevEco Device Tool| 3.0 Release | This tool is recommended for developing OpenHarmony smart devices.|


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base (for mini, small, and standard systems)       | 3.2 Beta2    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/code-v3.2-Beta2.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/code-v3.2-Beta2.tar.gz.sha256)|
| Hi3861 mini system solution (binary)       | 3.2 Beta2    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/hispark_pegasus.tar.gz.sha256)|
| Hi3516 mini system solution - LiteOS (binary)| 3.2 Beta2    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus.tar.gz.sha256)|
| Hi3516 mini system solution - Linux (binary) | 3.2 Beta2    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus_linux.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus_linux.tar.gz.sha256)|
| RK3568 standard system solution (binary)       | 3.2 Beta2    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/dayu200_standard_arm64.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/dayu200_standard_arm64.tar.gz.sha256)|
| Full SDK package for the standard system (macOS)              | 3.2.5.5      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-mac-full.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-mac-full.tar.gz.sha256)|
| Full SDK package for the standard system (Windows/Linux)    | 3.2.5.5      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-windows_linux-full.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-windows_linux-full.tar.gz.sha256)|
| Public SDK package for the standard system (macOS)            | 3.2.5.5      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-mac-public.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-mac-public.tar.gz.sha256)|
| Public SDK package for the standard system (Windows/Linux)  | 3.2.5.5      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-windows_linux-public.tar.gz.sha256)|
| Full SDK package for the standard system (macOS)              | 3.2.5.6      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-mac-full_20220913.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-mac-full_20220913.tar.gz.sha256)|
| Full SDK package for the standard system (Windows/Linux)    | 3.2.5.6      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-windows_linux-full_20220913.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-windows_linux-full_20220913.tar.gz.sha256)|
| Public SDK package for the standard system (macOS)            | 3.2.5.6      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-mac-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-mac-public.tar.gz.sha256)|
| Public SDK package for the standard system (Windows/Linux)  | 3.2.5.6      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-windows_linux-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-windows_linux-public.tar.gz.sha256)|


## What's New

This version has the following updates to OpenHarmony 3.2 Beta1.

### SDK Updates
From this version onwards, both the Public SDK and Full SDK are provided. The Public SDK is provided as standard in DevEco Studio.

If an application developed using the SDK of an earlier version calls system APIs, you must manually switch to the Full SDK by following the instructions provided in [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md) after the version upgrade. This operation ensures successful build of your application project.

### Feature Updates

  **Table 3** New and enhanced features

| Subsystem| Standard System| Mini and Small Systems|
| -------- | -------- | -------- |
| Ability| - To support UI-free application development for IoT devices, the graphics and power modules are decoupled.<br>- Basic capabilities such as DFX, mission management, and application thread model management are enhanced.<br>The following requirements are involved:<br>I57ZUI [New feature] UI-free application development for IoT devices - graphics module decoupling<br>I57ZVC [New feature] UI-free application development for IoT devices - power module decoupling<br>I5805B [Enhanced feature] AMS ANR optimization<br>I581M3 [New feature] Application selection box<br>I580JM [New feature] No display of abilities of system applications in the latest mission list<br>I5FHNH [Enhanced feature] Passing the **Context** object of the stage model to the worker<br>I58034 [Enhanced feature] Using JS looper of libuv<br>I57ZZH [New feature] Providing APIs to create context for different HAP files| NA |
| Bundle management| The default application management capability is added, and basic capabilities such as crowdtesting applications and obtaining bundle fingerprint information are also provided.<br>The following requirements are involved:<br>I56WD7 [New feature] Querying the default application<br>I56WDJ [New feature] Changing the default application<br>I56WDR [New feature] Restoring the default system application<br>I56WEK [New feature] Setting the default application by file type<br>I59ZMR [New feature] Crowdtesting applications<br>I5A7OV [New feature] Providing NDK interfaces to obtain the bundle name and certificate fingerprint information of the current bundle| NA |
| Power subsystem| Resource management and logs are added for thermal management. Power consumption statistics is now available for more modules.<br>The following requirements are involved:<br>I5AOM8 [New feature] Action hub<br>I5DC5E [Enhanced feature] Camera power consumption statistics<br>I5DC7M [Enhanced feature] Audio power consumption statistics<br>I5DC8L [Enhanced feature] Timer power consumption DFX<br>I5DC9H [Enhanced feature] Distributed Scheduler power consumption DFX<br>I5DOP4 [New feature] Thermal maintenance and debugging DFX<br>I5DONL [New feature] Charging resource management framework<br>I5DOLA [New feature] Adaptation to the SOC resource management framework| NA |
| System Ability Management Subsystem (SAMGR)| - The basic distributed capabilities are continuously built.<br>- The stability and security of system service processes are hardened, and the process memory is optimized.<br>The following requirements are involved:<br>I5FLTY [New feature] Component collaboration relationship management<br>I5DP1O [New feature] System events, SA dump, and tracing provided by DMS<br>I5CEMN [New feature] Installation-free feature of **startAbilityForResult**<br>I5BAP0 [New Feature] Cross-device installation-free feature of **startAbility**<br>I5B2PK [New feature] Adaptation of cross-device migration to persistent storage of distributed objects<br>I59XYB [New feature] Group verification<br>I592I5 [New feature] Memory baseline of the distributedsche process<br>I5E4KV [New feature] System events, SA dump, and tracing provided by SAMGR| NA |
| Common event and notification subsystem| - The tool supports multi-user scenarios.<br>- The basic capabilities of the common event and notification subsystems are enhanced.<br>The following requirements are involved:<br>I582V2 [New specifications] Sending events in point-to-point mode<br>I582XB [New specifications] Multi-user support of the tool<br>I582UL [Enhanced feature] Enhancement of distributed notification synchronization<br>I582QQ [New specifications] Carrying application icon badges in notifications<br>I582XB [New specifications] Multi-user support of the tool<br>I582SD [DFX] [Enhanced feature] Enhanced notification DFX capability<br>I582ST [New specifications] Configuration of notification clearance events<br>I582TF [Enhanced feature] Enhancement of notification slot setting and query<br>I58418 [New specifications] SELinux policy configuration<br>I582Y4 [DFX dotting] System events, SA dump, and tracing| NA |
| Distributed hardware subsystem| DeviceManager supports requesting and importing of credential parameters of the same account.<br>I5IUUS [DFX dotting] System events, SA dump, and tracing<br>I5IUVN [New feature] Requesting and importing credential parameters of the same account| NA |
| User IAM subsystem| - The basic capabilities of user authentication are continuously enhanced.<br>- The user IAM framework now supports fingerprint enrolling, authentication, identification, and deletion.<br>I5EPCD [Framework] Fingerprint enrolling for specified users<br>I5EPCM [Framework] Fingerprint authentication and identification for specified users <br>I5EPCU [Framework] Fingerprint deletion for specified users| NA |
| Build subsystem| - The Python and Gn versions are updated.<br>- System components can be independently built.<br>- The module dependency and compiler cache (ccache) are optimized, and a compilation function switch is provided.<br>The following requirements are involved:<br>I5IZC2 Independent build of system components and chip components<br>I5IZD9 [Integration optimization] Optimized module dependency<br>I5IZI0 [Integration optimization] Compilation function switch<br>I5IZH2 [Integration optimization] Optimized ccache| NA |
| Multimode input subsystem| - JS APIs are provided for obtaining input device information.<br>- The stylus can be used as an input device.<br>- An event can be reported to indicate that a key is repeatedly pressed.<br>- SELinux is now supported.<br>The following requirements are involved:<br>I530UN [New feature] Multi-hotspot distribution of the window<br>I530UT [New feature] JS API Mock<br>I530VY [New feature] Using JS APIs to obtain basic information about the stylus input device<br>I530W0 [New feature] Using JS APIs to obtain extended information about the mouse input device<br>I530WA [New feature] Using JS APIs to obtain extended information about the touchpad input device<br>I530WD [New feature] Using JS APIs to obtain extended information about the touchscreen input device<br>I530WH [New feature] Receiving and distributing key input events of the Linux stylus input<br>I530WI [New Feature] Carrying the pressure of the Linux stylus input in events<br>I530WJ [New Feature] Carrying the tilt of the Linux stylus input in events<br>I530WK [New Feature] Providing the pressure attribute of the touch point<br>I530WM [New Feature] Providing the touch area attribute of the touch point<br>I530WO [New feature] Providing the tool area attribute of the touch point<br>I530WP [New feature] Providing the tool type attribute of the touch point<br>I530X8 [New feature] Setting of key mapping rules in the configuration file<br>I530XH [New feature] Setting of key mapping rules for system keys in the configuration file<br>I530XJ [New feature] Automatic repeat of system keys<br>I530XK [New feature] Keyboard type identification<br>I530XL [New feature] Key capability identification<br>I530XM [New feature] Setting of key mapping rules for the keyboard in the configuration file<br>I530XN [New feature] Automatic repeat of keys on the keyboard<br>I530XT [New feature] Using C++ APIs to adjust the mouse cursor position based on relative coordinates<br>I530XX [New feature] Providing the pressure attribute of the touch point<br>I530XZ [New feature] Providing the touch area attribute of the touch point<br>I530Y1 [New feature] Providing the tool area attribute of the touch point<br>I530Y2 [New feature] Providing the tool type attribute of the touch point<br>I530Y7 [New specifications] Support for 64-bit<br>I530YB [DFX dotting] System events, SA dump, and tracing<br>I530YF [New specifications] [Input] SELinux policy configuration<br>I5HMBS [Input] Adaptive keyboard and mouse layout adaptation| NA |
| Pan-sensor subsystem| - Data of more types of sensors can be reported.<br>- SELinux is supported.<br>The following requirements are involved:<br>I53SFI [DFX dotting] System events, SA dump, and tracing<br>I537CB [New specifications] Continuous integration of pan-sensor capabilities - rotation vector sensor<br>I537AN [New specifications] Continuous integration of pan-sensor capabilities - gravity sensor<br>I5379T [New specifications] Continuous integration of pan-sensor capabilities - geomagnetic sensor<br>I5379C [New specifications] Continuous integration of pan-sensor capabilities - orientation sensor<br>I53784 [New specifications] Continuous integration of pan-sensor capabilities - ambient light sensor<br>I53SFS [New specifications] SELinux policy configuration| NA |
| Distributed data management subsystem| Multiple data types are supported by DataShare.<br>The following requirement is involved:<br>I5EHGF [DataShare] Support for multiple data types.| NA |
| Web subsystem| - JS-related interaction capabilities are supported.<br>- The network, keyboard, mouse, web storage, and SELinux policies are supported.<br>The following requirements are involved:<br>I5DM1E [New specifications] JS window management of web components<br>I5DNG2 [New specifications] Full set of JS hit-testing interfaces and APIs for obtaining the default user agent<br>I5EK53 [New specifications] [Web components] HTTP verification management<br>I5EGBB [New specifications] [Web components] SELinux policy configuration<br>I5EBG1 [New specifications] Adaptation to the W3C network information APIs<br>I5EVEC [New specifications] Web kernel connection to peripherals such as the mouse and keyboard<br>I5FF2L [New specifications] [Web components] Web storage| NA |
| Driver subsystem| - Dynamic loading of kernel-mode drivers and DFX capabilities are supported.<br>- Codec 2.0 interfaces and codec driver models are provided.<br>- The driver capabilities of the camera, display, audio, sensor, and WLAN modules are enhanced.<br>The following requirements are involved:<br>I536FN [New feature] HDI passthrough<br>I5DJE5 [Enhanced feature] Compatibility with Linux uevent reporting, and enhancement to device plug-and-play<br>I550OL [New feature] DFX tracing and locating<br>I544XP [New feature] SELinux permission check for the HDF service<br>I528DG [New feature] Implementation of Codec 2.0 interfaces<br>I50I6S [New feature] Unified audio HDIs for the IPC mode and direct calling mode<br>I5A6H6 [Enhanced feature] Enhanced display management, and support for multi-screen display<br>I5B0C5 [New feature] Support for the metadata streams of the camera<br>I5B0BR [New feature] Selfie mirroring in recording mode<br>I5AJW1 [New feature] Linux libALSA audio interface compatibility<br>I56V2N [New feature] Definition and development of interfaces related to the HDF WLAN DAL HDI power mode<br>I5F411 [Enhanced feature] Enhanced vibrator effect capability| NA |
| USB subsystem| - Broadcast messages are provided for USB service events.<br>- The SELinux security policy is enhanced.<br>The following requirements are involved:<br>I59MYK [New feature] Broadcast messages for USB service events<br>I5AR8N [New specifications] SELinux policy configuration| NA |
| Kernel subsystem| - Refined memory management is supported.<br>- The adjustment mechanism is added for associated services.<br>The following requirements are involved:<br>I58LOD [New feature] Adjustment mechanism of associated services<br>I54Y5J [New feature] memtrack memory usage and adj query interface by process<br>I56B3Q [New feature] OnMemoryLevel<br>I5B694 [New feature] Refined memory management<br>I59O8H [New feature] Purgeable memory<br>I5CXOK [New feature] Hyperhold for reliability improvement| NA |

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

  **Table 4** New samples

| Subsystem| Name| Introduction| Programming Language|
| -------- | -------- | -------- | -------- |
| Ability| MissionManager | This sample calls APIs related to the mission manager to lock, unlock, and clear missions, and switch them to the foreground.| ArkTS |
| Network management| AirQuality |   This sample implements a simple air quality app using JS. The app displays air quality information using line wrapping and historical data in a bar chart.| ArkTS |
| ArkUI | TransitionAnimation | This sample shows how to implement page transition, component transition, and transition of shared elements.| ArkTS |
| Application package management| ZipLib | This sample demonstrates the use of **\@ohos.zlib** by constructing the compression and decompression scenarios.| ArkTS |
| Engineering capabilities| Npm | This sample shows how npm references third-party JS class libraries (mathjs and dayjs) and local libraries.| ArkTS |
| Data management| DistributedMusicPlayer | In this sample, **fileIo** is used to obtain an audio file; **AudioPlayer** is used to play music, pause the playback, and play the next or previous song; **DeviceManager** is used to display the distributed device list and hop music playback across devices.| ArkTS |
| ArkUI | PatternLock | This sample shows how to use the **\<PatternLock>** component to implement password setting, verification, and resetting.| ArkTS |
| Security| UserAuth | This sample shows how to implement facial authentication.| ArkTS |
| Security| Cipher | This sample shows how to use cipher algorithms, including Rivest-Shamir-Adleman (RSA) and Advanced Encryption Standard (AES).| ArkTS |
| Graphics| Screen | This sample shows how to use APIs to listen for screen quantity changes, create and destroy virtual screens, and read and display screen attributes.| ArkTS |
| ArkUI | Search | This sample shows how to use the **\<Search>** component to implement a search page.| ArkTS |
| Device management| USBManager | This sample shows how to use USB device management, including listening for USB device insertion and removal events and display of USB device information.| ArkTS |
| Data management| DistributedDataGobang | This sample shows Gobang, a popular game played with black and white stones on a go board, developed using the distributed data management function. | ArkTS |
| Multimedia| Image | This sample provides an Image Processing app, using which you can read images from the local device, obtain image information, and rotate images.| ArkTS |
| Security| AbilityAccessCtrl | This sample shows how **@ohos.abilityAccessCtrl** works to implement application permission control.| ArkTS |
| Network management| WebSocket | This sample shows how to use WebSocket, including the connection and disconnection between the client and the server, and the receiving and sending of client data.| ArkTS |
| Connectivity| Bluetooth | Bluetooth is a short-range wireless technology used to implement communication between fixed and mobile devices over low-cost short-distance wireless connections. This sample describes how to discover, pair, and unpair Bluetooth devices.| ArkTS |
| Multimedia| GamePuzzle | This puzzle game app is developed based on the **\<Grid>** component. It uses the `Image` and `MediaLibrary` APIs to obtain and crop images.| ArkTS |
| Network management| UploadDownload | This sample uses the upload and download APIs to implement file storage.| ArkTS |
| Device management| Location | This sample uses the orientation sensor and GPS to obtain the current location information.| ArkTS |
| Telephony| Observer | This sample demonstrates how to use observer APIs to subscribe to network status, signal status, call status, cellular data, and SIM card status changes.| ArkTS |
| ArkUI | AdaptiveCapabilities | This sample shows multi-device adaptation in ArkTS, including resource qualifiers, atomic layouts, and responsive layouts.| ArkTS |
| ArkUI | JsAdaptiveCapabilities | This sample shows multi-device adaptation in JS, including resource qualifiers, atomic layouts, and responsive layouts.| JS |

For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).


## Resolved Issues

  **Table 5** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [I4Z3G9](https://gitee.com/openharmony/graphic_graphic_2d/issues/I4Z3G9) | [RK3568] Screen flickering occurs when the secondary window is opened in the immersive primary window.|
| [I59M4Q](https://gitee.com/openharmony/developtools_hdc/issues/I59M4Q) | There is a low probability of device disconnection when hdc_std of API version 9 is used.|
| [I54D32](https://gitee.com/openharmony/multimedia_camera_framework/issues/I54D32) | [RK3568] [Mandatory] A black screen is displayed when the camera has been recording videos for multiple consecutive times.|


## Known Issues

  **Table 6** Known issues

| ISSUE | Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I5I4GJ | There is a possibility that the RK3568 device is disconnected from DevEco Studio.| When DevEco Studio is used for application debugging, there is a possibility (1/25) that the device is disconnected. The device can be reconnected, and therefore the impact is controllable.| August 15, 2022|
| I5HTGF | The photo taken is rotated by 90 degrees clockwise when compared with the preview image.| User experience is affected.| August 15, 2022|
| I5FUNB | There are no patches for the known Linux kernel vulnerabilities yet.<br>CVE-2022-1462 | No patch is available in the kernel community for the kernel CVE vulnerabilities. After the patch is released in the community, it will be synchronized to OpenHarmony 3.2 Beta2.| Subject to the patch release time of the kernel community|
| I5FUO1 | There are no patches for the known Linux kernel vulnerabilities yet.<br>CVE-2022-21127 | No patch is available in the kernel community for the kernel CVE vulnerabilities. After the patch is released in the community, it will be synchronized to OpenHarmony 3.2 Beta2.| Subject to the patch release time of the kernel community|
