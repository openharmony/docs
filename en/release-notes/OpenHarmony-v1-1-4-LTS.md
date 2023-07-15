# OpenHarmony 1.1.4 LTS (EOL)

## Version Description

OpenHarmony 1.1.4 LTS is a maintenance version with a tag of OpenHarmony 1.1.3 LTS. This version has rectified certain issues and security vulnerabilities detected in OpenHarmony 1.1.3 LTS.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 1.1.4&nbsp;LTS | NA |
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool| 2.2&nbsp;Beta2 | Recommended for developing OpenHarmony smart devices|


## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

Method 1 \(recommended\): Use the **repo** tool to download the source code over SSH. \(You must have an SSH public key for access to Gitee.\)

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.4-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the **repo** tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.4-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base| 1.1.4 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.4/code-v1.1.4-LTS.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.4/code-v1.1.4-LTS.tar.gz.sha256)|
| Hi3861 solution (binary) for the mini system| 1.1.4 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.4/wifiiot-1.1.4.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.4/wifiiot-1.1.4.tar.gz.sha256)|
| Hi3518 solution (binary) for the small system| 1.1.4 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.4/ipcamera_hi3518ev300-1.1.4.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.4/ipcamera_hi3518ev300-1.1.4.tar.gz.sha256)|
| Hi3516 solution (binary) for the small system| 1.1.4 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.4/ipcamera_hi3516dv300-1.1.4.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.4/ipcamera_hi3516dv300-1.1.4.tar.gz.sha256)|


## What's New

This version has the following updates to OpenHarmony 1.1.3 LTS.


### Feature Updates

This version does not involve feature updates.


### Change

This version does not involve API updates.


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

**Table 3** Resolved security vulnerabilities

| Issue No.| Description|
| -------- | -------- |
| [I4AJEN](https://gitee.com/openharmony/third_party_freetype/issues/I4AJEN) | Fixed the CVE-2020-15999 security vulnerability of the third_party_freetype component.|
| [I4AJ6T](https://gitee.com/openharmony/third_party_mbedtls/issues/I4AJ6T) | Fixed the CVE-2020-36475 and CVE-2020-36478 security vulnerabilities of the third_party_mbedtls component.|
| I4AIYJ | Fixed the CVE-2021-27138 and CVE-2021-27097 security vulnerabilities of the third_party_uboot component.|
| [I4HUM6](https://gitee.com/openharmony/third_party_lwip/issues/I4HUM6?from=project-issue) | Fixed the CVE-2020-22284 security vulnerability of the third_party_lwip component.|
| I4QTVZ | Fixed the CVE-2021-44732 and CVE-2021-45450 security vulnerabilities of the third_party_mbedtls component.|
| [I46RRM](https://gitee.com/openharmony/third_party_wpa_supplicant/issues/I46RRM?from=project-issue) | Fixed copying of secondary device types for the P2P group client.|

**Table 4** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [I457ZZ](https://gitee.com/openharmony/kernel_liteos_a/issues/I457ZZ) | Fixed nested locking in the OsLockDepCheckIn exception handling.|
| [I3WU8Y](https://gitee.com/openharmony/kernel_liteos_a/issues/I3WU8Y) | Fixed the failed test cases in the storage directory of the FS module during the integration test of the lightweight kernel subsystem.|
| [I4AJI2](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/issues/I4AJI2) | Upgraded the FFmpeg version to 4.3.1.|
| [I3HXIX](https://gitee.com/openharmony/third_party_NuttX/issues/I3HXIX?from=project-issue) | Fixed the possible system error in the case of multiple processes, which is caused because the kernel operation node of the pipe uses the dirty private field dev.|
| [I4QO9B](https://gitee.com/openharmony/communication_wifi_lite/issues/I4QO9B?from=project-issue) | Fixed freezing when returning from the WLAN list to the home screen.|
| [I4EPVL](https://gitee.com/openharmony/xts_acts/issues/I4EPVL?from=project-issue) | Temporarily removed the ActsCMSISTest test case since the CMSIS code is not yet compatible with third-party chips.|
| [I4QQU9](https://gitee.com/openharmony/xts_acts/issues/I4QQU9) | Fixed the issue where the serial port logs contain the board IP address and MAC address when the XTS test suite ActsNetTest is executed on the Hi3516 or Hi3518 board of a small-system device.|


## Known Issues

N/A
