# OpenHarmony 3.0.3 LTS


## Version Description

OpenHarmony 3.0.3 LTS is a maintenance version of OpenHarmony 3.0 LTS. This version has rectified certain issues and security vulnerabilities detected in OpenHarmony 3.0.2 LTS. It is the latest stable release with a tag.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.0.3&nbsp;LTS | NA |
| SDK | 3.0.0.0(API&nbsp;Version&nbsp;7&nbsp;release) | NA |
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Studio| 3.0&nbsp;Beta1 | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool| 2.2&nbsp;Beta2 | Recommended for developing OpenHarmony smart devices|


## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**: Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

  **Table 2** Mirrors for acquiring source code

| LTS Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.0.3 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/code-v3.0.3-LTS.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/code-v3.0.3-LTS.tar.gz.sha256)|
| Standard system Hi3516 solution (binary)| 3.0.3 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/standard.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/standard.tar.gz.sha256) |
| Mini system Hi3861 solution (binary)| 3.0.3 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_pegasus.tar.gz.sha256) |
| Small system Hi3516 solution - LiteOS (binary)| 3.0.3 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_taurus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_taurus.tar.gz.sha256) |
| Small system Hi3516 solution - Linux (binary)| 3.0.3 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_taurus_linux.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_taurus_linux.tar.gz.sha256) |


## What's New

This version has the following updates to OpenHarmony 3.0.2 LTS.


### Feature Updates

This version does not involve feature updates.


### API Updates

This version does not involve API updates.


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

  **Table 3** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [I4TUSX](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4TUSX) | When the system camera is used to take a photo in the Hi3516D V300 development board running on a mini-system device, the two edges of the image are truncated.|
| [I4TYOP](https://gitee.com/openharmony/drivers_peripheral/issues/I4TYOP) | After a USB flash drive is inserted into the Hi3516D V300 development board running on a mini-system device, DMA times out and the USB flash drive is unavailable.|
| [I4SM0J](https://gitee.com/openharmony/third_party_harfbuzz/issues/I4SM0J) | The **third_party_harfbuzz** repository uses the CC BY-NC-SA-3.0 license, which restricts the commercial use of the content in the repository.|
| [I4WPQW](https://gitee.com/openharmony/device_hisilicon_hardware/issues/I4WPQW) | The **libdisplay_layer.so** binary file is not updated in the **device_hisilicon_hardware** repository.|
| [I4WIVF](https://gitee.com/openharmony/third_party_boost/issues/I4WIVF) | Some files in the **third_party_boost** repository are incompatible with open-source protocols.|
| I4WRWM | Some TDD test cases are unavailable in the **aafwk_aafwk_lite** repository.|
| [I4VPVY](https://gitee.com/openharmony/applications_sample_camera/issues/I4VPVY) | In the Hi3516D V300 development board running on a mini-system device, a user searches for Wi-Fi in **Settings** and touches the back button twice to return to the home screen. No application can be started from the home screen.|
| [I4UTY0](https://gitee.com/openharmony/applications_photos/issues/I4UTY0) | The HP copyright statement exists in the metadata of the **1.jpg** file in **demos**.|
| [I4TP6D](https://gitee.com/openharmony/xts_acts/issues/I4TP6D) | The ActsWorkerJSTest test suite newly added for the Hi3516 development board running on a standard-system device cannot be executed properly.|

  **Table 4** Resolved security vulnerabilities

| Issue No.| Description|
| -------- | -------- |
| I4U8VB | CVE-2021-3520 security vulnerability of the third_party_lz4 component.|
| I4UX33 | CVE-2021-22569 and CVE-2021-22570 security vulnerabilities of the third_party_protobuf component.|
| I4VRR7 | CVE-2022-23308 security vulnerability of the third_party_libxml2 component.|


  **Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved On|
| -------- | -------- | -------- | -------- |
| [I4YBB0](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YBB0) | No image is generated and the recorded video cannot be played when the system camera is used to take a photo and record a video. This issue occurs only for the Hi3516D V300 development board running on a small-system device (Linux).| Camera recording does not function.| 2022/04/01 |
| [I4YB87](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YB87) | No image is generated when the system camera is used to take a photo. This issue occurs only for the Hi3516D V300 development board running on a small-system device (Linux).| Camera photographing does not function.| 2022/04/01 |
| [I4YAGS](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YAGS?from=project-issue) | A blue screen is displayed when the system camera is accessed. This issue occurs only for the Hi3516D V300 development board running on a small-system device (Linux).| Camera preview does not function.| 2022/04/01 |
| I4WLBU | In the Hi3516D V300 development board running on a standard-system device, the device cannot be found after burning during the ACTS test, and the message "Device not founded or connected" is reported.| The HDC tool causes the ACTS test to report this error occasionally. The error does not affect the actual function.| 2022/04/10 |
