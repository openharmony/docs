# OpenHarmony v2.2 Beta2

## Version Description

This release provides new and enhanced features for the mini system, small system, and standard system based on OpenHarmony 2.0 Canary.

The feature updates for the standard system are as follows:

-   Added the distributed remote startup feature.
-   Added several sample apps and the drag-and-drop feature for basic system applications.
-   Added three media services for the media system.

The feature updates for the mini system and small system are as follows:

-   Added Linux version building for the small system.
-   Enhanced the lightweight kernel capabilities, including enhancements to the file system and kernel debugging tool, and support for configurable kernel modules, third-party chip adaptation, and ARM9 architecture.
-   Enhanced the lightweight graphics capabilities, including support for multi-language text alignment, component outline display, dot-matrix fonts, and multiple chip platforms for the unified backend framework.
-   Enhanced the design for X \(DFX\) capabilities, including enhanced HiLog and HiEvent features, a lightweight tool to dump system information, and the maintenance and test framework upon system restart.
-   Enhanced the AI capabilities, including Linux kernel adaptation and support for shared memory-based data transmission by the AI engine.

## Version Mapping

**Table  1**  Version mapping of software and tools

| Software                             | Version                     | Remarks                                              |
| ------------------------------------ | --------------------------- | ---------------------------------------------------- |
| OpenHarmony                          | 2.2 Beta2                   | N/A                                                  |
| (Optional) HUAWEI DevEco Studio      | DevEco Studio 2.2 Beta1     | Recommended for developing OpenHarmony apps          |
| (Optional) HUAWEI DevEco Device Tool | Deveco DeviceTool 2.2 Beta1 | Recommended for developing OpenHarmony smart devices |

## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**: Use the **repo** tool to download the source code over SSH. (You must have registered an SSH public key for access to Gitee.)


```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v2.2-Beta2 --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.


```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v2.2-Beta2 --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table  2** Mirrors for acquiring source code

| Source Code | Version | Mirror | SHA-256 Checksum |
| -------- | -------- | -------- | -------- |
| Full code (for mini, small, and standard systems) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/code-v2.2-beta2_20210730.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/code-v2.2-beta2_20210730.tar.gz.sha256) |
| Standard system solution (binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/standard-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/standard-2.2-Beta2.tar.gz.sha256) |
| Hi3861 solution (binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_pegasus-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_pegasus-2.2-Beta2.tar.gz.sha256) |
| Hi3518 solution (binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_aries-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_aries-2.2-Beta2.tar.gz.sha256) |
| Hi3516 solution-LiteOS (binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus-2.2-Beta2.tar.gz.sha256) |
| Hi3516 solution-Linux (binary) | 2.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus_linux-2.2-Beta2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus_linux-2.2-Beta2.tar.gz.sha256) |
| Release Notes | 2.2 | [Download](https://gitee.com/openharmony/docs/blob/master/en/release-notes/OpenHarmony-v2.2-beta2.md) | - |

## What's New

This release provides the following new and enhanced features based on OpenHarmony 2.0 Canary.

**Table  3**  New and enhanced features

| Subsystem                     | Standard System                                              | Mini and Small Systems                                       |
| ----------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Distributed File              | Provided JS APIs in the **system.file** class for asynchronous file operations, including file read/write, directory access, and directory addition/deletion. | NA                                                           |
| Driver                        | Added the audio, camera, USB, motor, and Analog to Digital Converter (ADC) driver models. | Enabled LiteOS-M to support the Hardware Driver Foundation (HDF). |
| Power Management              | Added the system power state machine, running lock, and sleep/wakeup features. | - Added the APIs for querying the battery charging/discharging status and the battery level.<br/>- Added the support for the low-power mode with unified APIs. |
| Update                        | Added the feature of restoring factory settings.             | NA                                                           |
| Media                         | - Added the audio service to provide basic audio control.<br/>- Added the camera service to provide basic functions such as preview and photographing.<br/>- Added the media service to support audio and video playback. | NA                                                           |
| JS UI Framework               | Added support for the hybrid use of both JS and C/C++ for JS API development. | NA                                                           |
| Common Event and Notification | Enabled applications to locally send and cancel a notification that includes multiple lines of text. | NA                                                           |
| DSoftBus                      | Added self-networking for DSoftBus. After a trusted device is connected to a LAN (either through Ethernet or Wi-Fi), the device can be automatically detected and connected to the DSoftBus. The device is not aware of this connection. | NA                                                           |
| Distributed Data Management   | - Added distributed data management to support locally encrypted storage of distributed databases.<br/>- Added support for lightweight preferences databases. | - Implemented data deletion from databases.<br/>- Added unified functions to operate the Hardware Abstraction Layer (HAL) file system.<br/>- Implemented atomic operations related to data storage.<br/>- Implemented read/write of binary values. |
| System Apps                   | Home screen:<br/>- Optimized UX for the home screen setting page.<br/>- Added support for icon dragging on the home screen.<br/>Settings:<br/>- Added WLAN settings.<br/>SystemUI:<br/>- Implemented the display of the signal icon of SIM cards.<br/>Photos:<br/>- Added the features of viewing, moving, copying, deleting, and renaming images and videos. | NA                                                           |
| Globalization                 | - Optimized time and date formatting.<br/>- Added support for time segment formatting.<br/>- Added support for number formatting. | - Added custom data compilation.<br/>- Added internationalization for the week, singular and plural forms, and numbers.<br/>- Added the mechanism for parsing and loading build resources.<br/>- Added the build resource backtracking mechanism. |
| Sample Apps                   | - Added the distributed calculator feature, which allows the calculator on one device to start the calculator on another networked device to perform collaborative calculation and synchronize the calculation data in real time.<br/>- Added the audio player app that supports audio playback on any networked devices. | NA                                                           |
| Distributed Device Management | Added the device management system service that provides authentication and networking irrelevant to distributed device accounts. | NA                                                           |
| DFX                           | NA                                                           | - Provided a tool to dump LiteOS kernel information.<br/>- Implemented a maintenance and test framework for the LiteOS kernel upon restarting after a breakdown.<br/>- Added number formatting.<br/>- Enhanced HiLog.<br/>- Enhanced HiEvent. |
| Kernel                        | NA                                                           | - Added support for the lightweight Linux version.<br/>- Enhanced support for the proc file system.<br/>- Added the mksh command interpreter.<br/>- Enhanced file system maintenance and testing.<br/>- Added support for configuration of LiteOS-A kernel modules.<br/>- Enabled the LiteOS-A small system to adapt to third-party chips.<br/>- Enabled LiteOS-M to support Mbed TLS compilation of third-party components.<br/>- Enabled LiteOS-M to support Curl compilation of third-party components.<br/>- Added support for the lightweight shell framework and common debugging commands.<br/>- Enabled LiteOS-M to support the ARM9 architecture.<br/>- Added support for the little file system (LittleFS) setup on the NOR flash.<br/>- Enabled LiteOS-M to provide unified file system operation APIs for external systems.<br/>- Added the Namecache, Vnode, and Lookup modules. |
| Graphics                      | NA                                                           | - Added support for input of A4, A8, LUT8, and TSC images.<br/>- Added support for multi-language text alignment.<br/>- Added component outline display for UIKit.<br/>- Enabled the **ScrollView** or **List** component to display the swiping progress using an arc progress bar.<br/>- Implemented animation for the switch, check box, and radio button.<br/>- Enabled UIKit to support the decoupling of dot-matrix fonts from products.<br/>- Provided a unified multi-backend framework to support multiple chip platforms.<br/>- Enabled UIKit to support margin and padding.<br/>- Implemented zoom and white layer animations for the round and capsule buttons. |
| Compilation and Building      | NA                                                           | Added support for the general patch framework of open-source software. |
| Startup                       | NA                                                           | Added support for factory setting restoration and multi-language text alignment. |
| Distributed Scheduler         | NA                                                           | Added support for the start of an ability on the rich device from a mini-system device. |
| AI                            | NA                                                           | - Added support for Linux kernel adaptation with related compilation options.<br/>- Enabled shared memory-based data transmission. |

### API Updates

For details, see:

-   [JS API Differences](api-diff/v2.2-beta2/js-apidiff-v2.2-beta2.md)

-   [Native API Differences](api-diff/v2.2-beta2/native-apidiff-v2.2-beta2.md)

## Resolved Issues

**Table  4** **Resolved issues**

| Issue No.                                                    | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I3I31W](https://gitee.com/openharmony/kernel_liteos_a/issues/I3I31W) | **ActsNFSTest.bin** causes a kernel crash.                   |
| [I3D49E](https://gitee.com/openharmony/docs/issues/I3D49E)   | The U-Boot path is incorrect.                                |
| [I3D71U](https://gitee.com/openharmony-retired/drivers_adapter_khdf_liteos/issues/I3D71U) | Driver subsystem] During repeated system reset, there is a high possibility that the system is suspended after successful **hmac_main_init** startup. |
| I3DGZW                                                       | [Application Framework subsystem] After the Hi3516 development board enters screen saver mode, a blue screen is displayed upon a tap on the touchscreen. |
| [I3DHIL](https://gitee.com/openharmony/community/issues/I3DHIL) | [System] The remaining space of the Hi3518 development board is insufficient, causing a failure in executing a large number of ACTS test cases. |
| I3DU36                                                       | [Application Framework subsystem] The query command **ipcamera bm** does not take effect. |
| [I3EALU](https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU) | [Multimedia subsystem] During the execution of the **cameraActs** test case, the camera configuration file cannot be found and the initialization fails. |
| [I3EGUX](https://gitee.com/openharmony/release-management/issues/I3EGUX) | [Reliability] When the KIdle process crashes once during repeated system reset, the system is suspended and cannot be started. |
| [I3EH4E](https://gitee.com/openharmony/community/issues/I3EH4E) | [Pipeline] There is a high probability that the system does not respond after the **uname** and **reset** commands are executed. |
| [I3EQJA](https://gitee.com/openharmony/kernel_liteos_a/issues/I3EQJA) | [File system] The **cat /proc/mounts** command does not take effect. |
| [I3EQRC](https://gitee.com/openharmony/kernel_liteos_a/issues/I3EQRC) | The system crashes when three concurrent test processes are run during disk file mapping delay testing. |
| [I3HVL0](https://gitee.com/openharmony/docs/issues/I3HVL0)   | The Hi3861 development board compilation fails and the error message "[OHOS ERROR] Fatal error: invalid -march= option:rv32imac" is displayed. |
| [I3TS1Y](https://gitee.com/openharmony/kernel_liteos_a/issues/I3TS1Y) | File-specific Vnode resources are exhausted in stress testing. |
| [I3TXT8](https://gitee.com/openharmony/startup_init_lite/issues/I3TXT8) | Orphan processes cannot be reclaimed, and TCB resources are exhausted in stress testing. |
| [I3UWXI](https://gitee.com/openharmony/applications_sample_wifi_iot/issues/I3UWXI) | The **libwap.so** file is prone to the following vulnerability: CVE-2021-30004, CVSS: 5.3, released on 2021-04-02. |
| [I3SWY2](https://gitee.com/openharmony/kernel_liteos_a/issues/I3SWY2) | There is a high probability that the KProcess is suspended.  |
| [I3YJRO](https://gitee.com/openharmony/kernel_liteos_m/issues/I3YJRO) | The compilation of configurable LiteOS-A kernel modules fails. |
| [I3YNWM](https://gitee.com/openharmony/kernel_liteos_a/issues/I3YNWM) | The enhanced file system maintenance and test feature is defective. |
| [I3VEOG](https://gitee.com/openharmony/kernel_liteos_a/issues/I3VEOG) | The **bin** directory does not contain the **mksh** and **toybox** commands, leading to a failure to test the **toybox** command set. |
