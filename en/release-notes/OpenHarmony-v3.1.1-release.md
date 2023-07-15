# OpenHarmony 3.1.1 Release


## Version Description

OpenHarmony 3.1.1 Release provides the following enhancements over OpenHarmony 3.1 Release:

**Enhanced basic capabilities for the standard system**

System service management is enhanced to support group verification. Power management now supports brightness adjustment and battery information query. The Misc services subsystem supports HTTP file download APIs.

The location service subsystem now implements basic positioning APIs. The window manager subsystem supports setting of window properties. The multimedia subsystem provides APIs related to audio focus and audio decoding.

Network management supports Ethernet connections. WebSocket JS APIs are added, which are compatible with the **\@system.fetch** and **\@system.network** APIs.

**Enhanced distributed capabilities for the standard system**

Distributed data management is now compatible with the **\@system.storage** APIs.

**Enhanced application framework capabilities for the standard system**

Bundle management supports application-specific installation status query. The common event and notification subsystem provides APIs for sending and canceling notifications.

The Feature Ability (FA) model supports ability-level screen orientation query and setting, lock screen display, and screen-on during ability startup. DFX features, such as Application Not Response and suspension detection for an application's main thread, are added. More basic capabilities are added for FA widgets.

**Enhanced application capabilities for the standard system**

The Contacts application allows third-party applications to invoke the system call capability, so end users can use the basic communication capabilities of devices.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.1.1 Release | NA |
| Public SDK | Ohos_sdk_public 3.1.6.6 (API Version 8 Release)| This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio 3.0 Beta4 or later.<br>The public SDK of API version 8 was released on July 6, 2022.|
| Full SDK | Ohos_sdk_full 3.1.6.5 (API Version 8 Release) | This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the full SDK, manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| (Optional) HUAWEI DevEco Studio| 3.0 Beta3 for OpenHarmony | This tool is recommended for developing OpenHarmony applications.|
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


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base (for mini, small, and standard systems)       | 3.1.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/code-v3.1.1-Release.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/code-v3.1.1-Release.tar.gz.sha256)|
| Hi3516 standard system solution (binary)       | 3.1.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_hi3516.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_hi3516.tar.gz.sha256)|
| RK3568 standard system solution (binary)       | 3.1.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_rk3568.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_rk3568.tar.gz.sha256)|
| Hi3861 mini system solution (binary)       | 3.1.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_pegasus.tar.gz.sha256) |
| Hi3516 mini system solution - LiteOS (binary)| 3.1.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_taurus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_taurus.tar.gz.sha256) |
| Hi3516 mini system solution - Linux (binary) | 3.1.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_taurus_linux.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_taurus_linux.tar.gz.sha256) |
| Full SDK package for the standard system (macOS)              | 3.1.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-mac-full.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-mac-full.tar.gz.sha256)|
| Full SDK package for the standard system (Windows/Linux)    | 3.1.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-full.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-full.tar.gz.sha256)|
| Public SDK package for the standard system (macOS)| 3.1.1 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-mac-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-mac-public.tar.gz.sha256)|
| Public SDK package for the standard system (Windows/Linux)| 3.1.1 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-public.tar.gz.sha256)|


## What's New

This version has the following updates to OpenHarmony 3.1 Release.


### Feature Updates

**Table 3** New and enhanced features

| Subsystem| Standard System| Mini and Small Systems|
| -------- | -------- | -------- |
| SDK | SDKs are classified into full SDKs and public SDKs.<br>Note: The public SDK of API version 8 was released on July 6, 2022.| NA |
| System service management| Added group verification.<br>The following requirement is involved:<br>I52G5Q Adding group verification| NA |
| Power management| Added the APIs for brightness adjustment and battery information query.<br>The following requirements are involved:<br>I526UP Supporting the **\@system.brightness** APIs<br>I526UP Supporting the **\@system.battery** APIs| NA |
| Bundle management| Added the APIs for querying whether a specified application is installed.<br>The following requirements are involved:<br>I56EWD Test framework configuration<br>I55RZJ Querying whether a specified application is installed| NA |
| Location service| Added compatibility with basic positioning APIs.<br>The following requirement is involved:<br>I53WFP Basic positioning capabilities and system APIs| NA |
| Ability| Added the following features to the FA model: ability-level screen orientation query and setting, lock screen display, and screen-on upon startup.<br>The following requirements are involved:<br>I56EH7 Querying and setting the landscape/portrait mode for an ability in the FA model<br>I50D5Y Lock screen display for an ability in the FA model<br>I56EH7 Screen-on during ability startup in the FA model<br>I55WB0 Carrying images in widget data<br>I55WB0 FA widget capability supplement - formManager reconstruction<br>I55WB0 FA widget capability supplement - widget status query<br>I55WB0 FA widget capability supplement - deleting invalid widgets<br>I55WB0 FA widget capability supplement - separate setting of the visibility and update status of widgets<br>I50D8H Interception of uncatched exceptions<br>I50D91 Application Not Response processing| NA |
| Media| Added APIs related to audio focus and audio decoding.<br>The following requirements are involved:<br>I56REO Supplementing audio focus/device APIs<br>I522W0 AMR audio encoding| NA |
| Window manager| Added support for setting window properties.<br>The following requirement is involved:<br>I56EH7 Window property setting| NA |
| Network management| Added support for WebSocket and fetch APIs and Ethernet connections.<br>The following requirements are involved:<br>I53CKH Supporting the **\@system.fetch** APIs<br>I53CJX Supporting the **\@system.network** APIs<br>I53CKT WebSocket support<br>I580PC Ethernet connections| NA |
| Misc services| Added compatibility with HTTP file download APIs.<br>The following requirement is involved:<br>I56Q4X Supporting file download APIs| NA |
| Common event and notification| Added the APIs for sending and canceling notifications.<br>The following requirements are involved:<br>I50EEW APIs for sending and canceling notifications| NA |
| Distributed data management| Added compatibility with the **\@system.storage** APIs.<br>The following requirement is involved:<br>I56RF3 Supporting the **\@system.storage** APIs| NA |
| Startup| Added compatibility with the **\@system.device** APIs.<br>The following requirement is involved:<br>I56GBS Supporting the **\@system.device** APIs| NA |
| System applications| The Contacts application allows third-party applications to invoke the system call capability.<br>The following requirements are involved:<br>I58ZQ4 The Contacts application allows third-party applications to invoke the system call capability.| NA |

### API Updates

This version does not involve API updates.



### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).

## Resolved Issues

**Table 4** Resolved issues

| Issue No.                                                    | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I4UUFR](https://gitee.com/openharmony/third_party_e2fsprogs/issues/I4UUFR) | Local image compilation and build may fail for the Hi3516 development board. |
| I4WDD3                                                       | [RK3568] A recorded video cannot be viewed.                  |
| [I50EBB](https://gitee.com/openharmony/docs/issues/I50EBB)   | [Hi3516 burning] Images of the Hi3516 development board on a standard-system device cannot be burnt by using DevEco Device Tool. |


## Known Issues

**Table 5** Known issues

| Issue No.                                                       | Description                                                  | Impact                                             | To Be Resolved By|
| ------------------------------------------------------------ | ---------------------------------------------------------- | ------------------------------------------------- | ------------ |
| [I4Z3G9](https://gitee.com/openharmony/graphic_graphic_2d/issues/I4Z3G9) | [RK3568] Screen flickering occurs when the secondary window is opened in the immersive primary window.| Developer experience is affected.                                 | 2022-06-15   |
| [I58GFY](https://gitee.com/openharmony/communication_wifi/issues/I58GFY) | [RK3568] On the 2.4 GHz and 5 GHz frequency bands, connections fail in WPA+TKIP/AES encryption mode.      | The TP-Link AX50 router cannot connect to the Wi-Fi network.         | 2022-06-30   |
| [I59P32](https://gitee.com/openharmony/distributedhardware_device_manager/issues/I59P32) | [RK3568] After the trust period of a device expires, PIN authentication cannot be performed.             | This issue occurs when the timer waiting for the PIN code input times out. It can be resolved by restarting the device.| 2022-06-15   |
