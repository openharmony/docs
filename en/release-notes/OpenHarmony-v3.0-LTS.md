# OpenHarmony 3.0 LTS

## Version Description

This version has updates for the standard system, mini system, and small system on the basis of OpenHarmony 2.2 Beta2.

The feature updates for the standard system are as follows:

- The application framework supports the Service ability, Data ability, and thread model.

- Secure file access is supported, which means that a file object can be converted into a URI and a URI can be parsed to open a file.

- PIN authentication is supported for the distributed device management service.

- Relational databases and distributed data management are supported.

- The ARK JS compiler toolchain and runtime are supported, and the OpenHarmony JS UI framework application development and running are also supported.

- Remote binding of a Service ability and cross-device FA migration are supported.

- Application pub/sub and redirection of application notifications are supported.

- The input method framework is supported, and basic English letters, special characters, and digits can be entered.

- The camera module supports preview, photographing, and video recording.

- The CS basic call and GSM SMS capabilities are supported.

- The timer capability and the scheduled time zone management capability are supported.

- In the distributed networking of standard-system devices, permission verification is provided for applications to access peer-end resources or capabilities.

The feature updates for the mini and small systems are as follows:

- The lightweight distributed capability is enhanced so that the ability on a standard-system device can be started from a mini-system device.

- The DSoftBus capability is enhanced to support transmission of authentication channels for device binding.

- The lightweight globalization capability is enhanced to support 31 more languages.

- The permission attribute field and its write interface are added for the mini system. Upper-layer applications can use this field to implement related services.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.0&nbsp;LTS | N/A|
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Studio| 3.0&nbsp;Beta1 | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool| 2.2&nbsp;Beta2 | Recommended for developing OpenHarmony smart devices|


## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**: Use the **repo** tool to download the source code over SSH. (You must have registered an SSH public key for access to Gitee.)


```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.


```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| LTS&nbsp;Code | Version&nbsp;Information | Mirror | SHA-256 Checksum |
| -------- | -------- | -------- | -------- |
| Full&nbsp;code&nbsp;(for&nbsp;mini,&nbsp;small,&nbsp;and&nbsp;standard&nbsp;systems) | 3.0 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/code-v3.0-LTS.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/code-v3.0-LTS.tar.gz.sha256) |
| Standard&nbsp;system&nbsp;solution&nbsp;(binary) | 3.0 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/standard.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/standard.tar.gz.sha256) |
| Hi3861&nbsp;solution&nbsp;(binary) | 3.0 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_pegasus.tar.gz.sha256) |
| Hi3518&nbsp;solution&nbsp;(binary) | 3.0 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_aries.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_aries.tar.gz.sha256) |
| Hi3516&nbsp;solution-LiteOS&nbsp;(binary) | 3.0 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus.tar.gz.sha256) |
| Hi3516&nbsp;solution-Linux&nbsp;(binary) | 3.0 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus_linux.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus_linux.tar.gz.sha256) |
| Release&nbsp;Notes | 3.0 | [Download](https://gitee.com/openharmony/docs/blob/master/en/release-notes/OpenHarmony-v3.0-LTS.md) | N/A |



## What's New

This version has the following updates to OpenHarmony 2.2 Beta2.


### Feature Updates

**Table 3** New and enhanced features

| Subsystem| Standard System| Mini and Small Systems|
| -------- | -------- | -------- |
| Distributed Scheduler| -&nbsp;Remote Service ability binding is supported.<br/>-&nbsp;Cross-device FA migration is supported.<br/>-&nbsp;Permission verification is added for the visible attribute of a component. | The small system can now start HarmonyOS abilities.|
| Graphics| For chip platforms with GPU modules, GPUs can be used for rendering and composition to improve graphics performance and reduce CPU load.| N/A|
| Distributed Hardware| -&nbsp;The formal PIN authentication scheme based on DSoftBus authentication channels is supported.<br/>-&nbsp;A pop-up window is displayed for PIN authentication.<br/>-&nbsp;A pop-up window is displayed to show a PIN.<br/>-&nbsp;A pop-up window is displayed for the user to enter a PIN.| N/A|
| Event Notification| -&nbsp;Application notification subscription and unsubscription are supported.<br/>-&nbsp;Local text and picture-attached notifications can be published or canceled on the application side.<br/>-&nbsp;Application notification redirection is supported.<br/>-&nbsp;Notification slots can be added or removed on the application side.<br/>-&nbsp;Notification flow control and death monitor are supported.| N/A|
| DSoftBus| DSoftBus:<br/>-&nbsp;CoAP-based active discovery and passive discovery are supported, and active discovery and connection through BLE are supported.<br/>-&nbsp;WLAN-based manual network access and self-networking are supported.<br/>-&nbsp;WLAN-based message, byte, and file transfer is supported.<br/>IPC:<br/>-&nbsp;Intra-device IPC based on Linux kernel's binder protocol is supported.<br/>-&nbsp;Object-oriented data communication and serialized data communication are supported.<br/>RPC:<br/>-&nbsp;Inter-device IPC based on DSoftBus is supported.<br/>-&nbsp;Object-oriented data communication and serialized data communication are supported.<br/>-&nbsp;The APIs are the same as those of the IPC.| DSoftBus:<br/>-&nbsp;CoAP-based active discovery and passive discovery are supported.<br/>-&nbsp;WLAN-based manual network access and self-networking are supported.<br/>-&nbsp;WLAN-based message, byte, and file transfer is supported.<br/>IPC:<br/>-&nbsp;Intra-device IPC based on the Linux/LiteOS kernel's binder protocol is supported.<br/>-&nbsp;Serialized communication of char/int/long data APIs is supported.|
| Globalization| The capability of obtaining the language, region, and locale information configured in the system and obtaining the localized names of the language and region.| The lightweight globalization capability is enhanced to support 31 more languages.|
| System Applications| -&nbsp;Home Screen: A new architecture is introduced.<br/>-&nbsp;SystemUI:<br/>&nbsp;&nbsp;-&nbsp;Notification center and common text notification are optimized.<br/>&nbsp;&nbsp;-&nbsp;WLAN, airplane mode, brightness adjustment, and volume adjustment in the Control Panel are optimized.<br/>&nbsp;&nbsp;-&nbsp;A new architecture is introduced.<br/>-&nbsp;Settings: A new architecture is introduced.<br/>-&nbsp;Camera:<br/>&nbsp;&nbsp;-&nbsp;Photographing and video recording are supported.<br/>&nbsp;&nbsp;-&nbsp;Distributed collaboration: Users can now start the peer camera to take photos.| N/A|
| Multi-language Runtime| The ARK JS compiler toolchain and runtime are added, and the OpenHarmony JS UI framework application development and running are also supported.| N/A|
| Media| -&nbsp;The video recording function is added to the camera module.<br/>-&nbsp;The audio recording API is added. | MP3 files can be played.|
| JS UI Framework| -&nbsp;Migration-related lifecycle management is supported.<br/>-&nbsp;Pop-up windows are added for system services.<br/>-&nbsp;JS can be used to develop Service and Data abilities.| N/A|
| Kernel| OpenHarmony Common Linux Kernel 5.10 is supported.| OpenHarmony Common Linux Kernel 5.10 is supported for the small system.|
| DFX | -&nbsp;JS APIs are added for HiAppEvent event logging.<br/>-&nbsp;The HiCollie suspension detection framework is provided.<br/>-&nbsp;The HiTrace distributed call chain basic library is provided.| N/A|
| Driver| The I2S, gyroscope, pressure, and Hall driver models are added.| N/A|
| Security| In the distributed networking of standard-system devices, permission verification is provided for applications to access peer-end resources or capabilities.| The permission attribute field and its write interface are added for the mini system. Upper-layer applications can use this field to implement related services. (When a pop-up window is used to request authorization, no dialog box is displayed after the user rejects the authorization.)|
| Telephony Service| -&nbsp;Network search module: supports airplane mode setting, network search mode setting (manual and automatic network search), and LTE signal strength retrieval.<br/>-&nbsp;SIM module: supports PIN/PUK unlocking, SIM card file information retrieval, card account information storage and retrieval, and card status retrieval.<br/>-&nbsp;Cellular call module: supports foreground/background switchover, incoming call muting, call holding and resuming, three-party call, and DTMF.<br/>-&nbsp;SMS and MMS modules: support addition, deletion, modification, and query of SMS and MMS messages on the SIM card.| N/A|
| Distributed File| -&nbsp;Mounting of partitions with different parameter settings is supported for the F2FS and EXT4 file systems.<br/>-&nbsp;Secure file access is supported, which means that a file object can be converted into a URI and a URI can be parsed to open a file.<br/>-&nbsp;System applications can now access public directories.| N/A|
| Distributed Data Management| -&nbsp;Basic JS capabilities (such as adding, deleting, modifying, and querying) are added for relational databases.<br/>-&nbsp;Basic JS capabilities (such as adding, deleting, modifying, and querying) are added for distributed data management.| N/A|
| Compilation and Building| -&nbsp;Compilation of ARM64 products is supported.<br/>-&nbsp;Compilation of ohos-sdk is supported.| N/A|
| Application Framework| -&nbsp;JS based Service ability development is supported.<br/>-&nbsp;JS based Data ability development is supported.<br/>-&nbsp;The HAP supports multiple ability statements.<br/>-&nbsp;Ability migration to a remote device is supported.<br/>-&nbsp;The application task stack can be saved and restored.<br/>-&nbsp;JS&nbsp;JS can now use ZIP Library to compress and decompress files.| N/A|
| Misc Services| The timer capability and the scheduled time zone management capability are supported.| N/A|


### API Updates

For details, see [JS API Differences](api-diff/v3.0-LTS/js-apidiff-v3.0-lts.md).


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

**Table 4** Issues resolved for mini and small systems

| Issue No.| Description|
| -------- | -------- |
| [I45AVP](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I45AVP) | The **hilog** command fails to be executed after a flush operation.|
| I47EPA | **GetBundleSize** returns an error when the input parameter is null or invalid.|
| [I434AD](https://gitee.com/openharmony/multimedia_camera_lite/issues/I434AD) | For Hi3516DV300, the resident memory of the mini system exceeds the baseline.|
| [I434P1](https://gitee.com/openharmony/multimedia_camera_lite/issues/I434P1) | For Hi3518EV300, the resident memory of the mini system exceeds the baseline.|
| [I46I6K](https://gitee.com/openharmony/multimedia_media_lite/issues/I46I6K?from=project-issue) | There are security coding defects in the code of the multimedia subsystem.|
| [I46E6S](https://gitee.com/openharmony/kernel_liteos_m/issues/I46E6S?from=project-issue) | The **-Werror** compilation option is unavailable for the lightweight kernel module compilation.|
| I47ETO | The permission verification does not take effect. When the test .bin file is used to invoke the HAP that has not obtained the **ohos.permission.GET_BUNDLE_INFO** permission, the query is successful. The expected result is a query failure with **0** returned.|
| [I48A2I](https://gitee.com/openharmony/drivers_peripheral/issues/I48A2I) | The board is suspended when the Hi3516DV300 lightweight version calls **AllocMem**.|
| [I42LCU](https://gitee.com/openharmony/kernel_liteos_m/issues/I42LCU) | The method of checking thread insufficiency and the method of configuring the number of threads are unavailable in the integration test and development board migration guide.|
| [I3IPD7](https://gitee.com/openharmony/kernel_liteos_m/issues/I3IPD7) | A description indicating that the **osThreadExit** and **join** functions are not supported is missing in the header file.|
| [I3M12H](https://gitee.com/openharmony/kernel_liteos_a/issues/I3M12H) | During the integration test, two different signals are sent, but **sigwait** receives the first signal twice.|
| [I47X2Z](https://gitee.com/openharmony/kernel_liteos_a/issues/I47X2Z?from=project-issue) | When the **ActsIpcShmTest.bin** script is executed during the integration test, a large amount of shared memory is not released.|
| [I4BL3S](https://gitee.com/openharmony/kernel_liteos_a/issues/I4BL3S) | When the **nfs** cases of the fs_posix module are executed multiple times during the integration test, the message indicating a failure to apply for memory is repeatedly printed.|
| [I490KZ](https://gitee.com/openharmony/kernel_liteos_a/issues/I490KZ) | The **FutexTest.testPthreadTimdOutRWlockWR** case fails to be executed.|
| [I44SFO](https://gitee.com/openharmony/third_party_toybox/issues/I44SFO) | During the integration test, a file in a directory is moved to another directory, and then a file with the same name is created in the first directory. When the user attempts to move the new file, a message is displayed, indicating that the file does not exist.|

Table 5 Issues resolved for the standard system

| Issue No.| Description|
| -------- | -------- |
| I46A6H | During the X test suite (XTS) subsystem pressure test, the **libace.z.so** file is abnormal. As a result, the **ohos.samples.flashlight** file encounters the cppcrash exception.|
| I48HLN | Bug-[Demo & application subsystem] [JsCanvas] The Clear button does not take effect.|
| [I46HH7](https://gitee.com/openharmony/drivers_peripheral/issues/I46HH7) | Driver Subsystem - WLAN test cases fail for a standard-system board.|
| [I4312A](https://gitee.com/openharmony/communication_dsoftbus/issues/I4312A) | [OpenHarmony 2.2 Beta2] [DSoftBus] When multiple devices are networked and one of them is disconnected, self-networking fails for the disconnected device (**GetAllNodeDeviceInfo** returns null).|
| [I43WIJ](https://gitee.com/openharmony/communication_dsoftbus/issues/I43WIJ) | [OpenHarmony 2.2 Beta2] [DSoftBus] When multiple devices are networked and one of them is switched to another network and then switched back, the device remains online during this switchover (no callback indicating that the device goes offline or goes online is invoked).|
| [I43KLC](https://gitee.com/openharmony/communication_dsoftbus/issues/I43KLC) | [OpenHarmony 2.2 Beta2] [DSoftBus] A listener for the node status is registered. When a device goes online and then offline, the callback indicating the offline state is invoked twice.|
| [I47WTY](https://gitee.com/openharmony/communication_dsoftbus/issues/I47WTY) | [OpenHarmony 3.0 Beta1] [DSoftBus-Transmission] The verification of the session ID range is incorrect. The valid range is 1-16, but the verification result is greater than 17.|


## Known Issues

**Table 6** Known issues

| Issue| Description| Impact| To Be Resolved On|
| -------- | -------- | -------- | -------- |
| [I48IM7](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I48IM7) | During the hilog pressure test, **hilogd** restarts unexpectedly, and the **hilog** command cannot be used.| In the pressure test, there is a low probability that the log output is abnormal. The log output is normal in the commissioning scenario.| October 30|
| I48YPH | [DSoftBus - Networking] During the testing of the getting-offline - discovery - networking cycle, there are 3 failures among all the 110 attempts.| There is a low probability that this issue occurs. If a networking failure occurs, initiate the networking again.| October 30|
| [I4BVVW](https://gitee.com/openharmony/communication_dsoftbus/issues/I4BVVW) | [DSoftBus - Networking] The success rate of self-networking between a standard-system device and mobile phone is 97%.| There is a low probability that the networking fails.| October 30|
| I4BXWY | For Hi3516, noises occur during playback of an audio recording.| This issue occurs only when this development board is used.| October 30|
| I4BXY1 | There is no sound in the first few seconds of a video recording, the sound and image are out of sync, frame freezing occurs, and noises occur when the audio source was far away during recording.| This issue occurs only when this development board is used.| October 30|
| [3ZJ1D](https://gitee.com/openharmony/kernel_liteos_a/issues/I3ZJ1D) | There is a possibility that the user mode fails in the XTS pressure test of the permission case.| There is a low probability that the UID of a child process fails to be set in the XTS pressure test scenario where child processes are repeatedly created.| October 30|
