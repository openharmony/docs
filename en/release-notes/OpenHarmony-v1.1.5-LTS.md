# OpenHarmony 1.1.5 LTS (EOL)


## Version Description

OpenHarmony 1.1.5 LTS is a maintenance version of OpenHarmony 1.0.1 Release. This version has rectified certain issues and security vulnerabilities detected in OpenHarmony 1.1.4 LTS. It is the latest stable release with a tag.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 1.1.5 LTS | N/A| 
| (Optional) HUAWEI DevEco Device Tool| 2.2 Beta2 | Recommended for developing OpenHarmony smart devices| 


## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**: Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)

  
```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.5-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.

  
```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.5-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

  **Table 2** Mirrors for acquiring source code

| Source Code| Version| Mirror| SHA-256 Checksum| 
| -------- | -------- | -------- | -------- |
| Full code base| 1.1.5 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.5/code-v1.1.5-LTS.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.5/code-v1.1.5-LTS.tar.gz.sha256)| 
| Hi3861 solution (binary) for the mini system| 1.1.5 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.5/wifiiot-1.1.5.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.5/wifiiot-1.1.5.tar.gz.sha256)| 
| Hi3518 solution (binary) for the small system| 1.1.5 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.5/ipcamera_hi3518ev300-1.1.5.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.5/ipcamera_hi3518ev300-1.1.5.tar.gz.sha256)| 
| Hi3516 solution (binary) for the small system| 1.1.5 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.5/ipcamera_hi3516dv300-1.1.5.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.5/ipcamera_hi3516dv300-1.1.5.tar.gz.sha256)| 


## What's New

This version has the following updates to OpenHarmony 1.1.4 LTS.


### Feature Updates

This version does not involve feature updates.


### API Updates

This version does not involve API updates.


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

  **Table 3** Resolved security vulnerabilities

| Issue No.| Description| PR Link| 
| -------- | -------- | -------- |
| I58X0S | Security vulnerabilities of the curl component: CVE-2022-27781 and CVE-2022-27782| [PR](https://gitee.com/openharmony/third_party_curl/pulls/60) | 
| I56PV4 | Security vulnerabilities of the curl component: CVE-2022-22576, CVE-2022-27775, CVE-2022-27774, and CVE-2022-27776| [PR](https://gitee.com/openharmony/third_party_curl/pulls/54) | 
| NA | Security vulnerabilities of the curl component: CVE-2021-22945, CVE-2021-22946, and CVE-2021-22947| [PR](https://gitee.com/openharmony/third_party_curl/pulls/56) | 
| I4QT0K/I56GI9 | Security vulnerabilities of the Mbed TLS component: CVE-2021-44732 and CVE-2021-45450| [PR](https://gitee.com/openharmony/third_party_mbedtls/pulls/30) | 
| I5F0WG | Security vulnerabilities of the freetype component: CVE-2022-27404 and CVE-2022-27406| [PR](https://gitee.com/openharmony/third_party_freetype/pulls/22) | 
| I4TLI9 | Security vulnerability of the freetype component: CVE-2020-15999| [PR](https://gitee.com/openharmony/third_party_freetype/pulls/7) | 
| I51D98 | Security vulnerability of the zlib component: CVE-2018-25032| [PR](https://gitee.com/openharmony/third_party_zlib/pulls/31) | 
| I5F13F/I4UHO4 | Security vulnerabilities of the FFmpeg component: CVE-2020-35964, CVE-2022-1475, CVE-2021-38291, CVE-2020-35965, CVE-2020-22042, CVE-2020-22038, CVE-2020-22037, CVE-2020-22021, and CVE-2020-22019| [PR](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/pulls/17) | 

  **Table 4** Resolved issues

| Issue No.| Description| 
| -------- | -------- |
| [I4VKNM](https://gitee.com/openharmony/xts_acts/issues/I4VKNM) | There is a possibility that the testSigtimedwaitBlock test case fails to run on the Hi3518 development board in the small system.| 
| [I4S098](https://gitee.com/openharmony/applications_sample_camera/issues/I4S098) | The system may stop responding when you repeat the following operations on the Hi3516 development board in the small system: Choose **Settings > Wi-Fi**, enter the Wi-Fi list page, and exit.| 
