# OpenHarmony v1.1.2 LTS (EOL)

## Overview

This is an updated long-term support \(LTS\) version of OpenHarmony. It supports more functions and fixes some bugs in OpenHarmony 1.1.1.

## Version Mapping

**Table  1**  Version mapping of software and tools

| Software                             | Version                     | Remarks                                              |
| ------------------------------------ | --------------------------- | ---------------------------------------------------- |
| OpenHarmony                          | 1.1.2 LTS                   | N/A                                                  |
| (Optional) HUAWEI DevEco Device Tool | Deveco DeviceTool 2.2 Beta1 | Recommended for developing OpenHarmony smart devices |


## Source Code Acquisition

### Acquiring Source Code from Mirrors

**Table  2**  Mirrors for acquiring source code

| Source Code              | Version Information | Mirror                                                       | SHA-256 Checksum                                             |
| ------------------------ | ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base           | 1.1.2               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/code-v1.1.2-LTS.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/code-v1.1.2-LTS.tar.gz.sha256) |
| Hi3861 solution (binary) | 1.1.2               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/wifiiot-1.1.2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/wifiiot-1.1.2.tar.gz.sha256) |
| Hi3518 solution (binary) | 1.1.2               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3518ev300-1.1.2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3518ev300-1.1.2.tar.gz.sha256) |
| Hi3516 solution (binary) | 1.1.2               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3516dv300-1.1.2.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3516dv300-1.1.2.tar.gz.sha256) |
| Release Notes            | 1.1.2               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.2/OpenHarmony-Release-Notes-1.1.2-LTS.zip) | N/A                                                          |

### Acquiring Source Code Using the repo Tool

Method 1 \(recommended\): Use the  **repo**  tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)


```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the  **repo**  tool to download the source code over HTTPS.

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## What's New

This version inherits all features of OpenHarmony 1.1.1, and adds and optimizes features for different modules based on OpenHarmony 1.1.1. The following table lists the feature updates.

**Table  3**  Feature updates

| Subsystem     | New Feature                                                  | Modified Feature            | Deleted Feature |
| ------------- | ------------------------------------------------------------ | --------------------------- | --------------- |
| Graphics      | Added settings for the slider style.                         | None                        | None            |
| Update        | Added the 3072-bit RSA signature algorithm for update packages. | None                        | None            |
| Driver        | Added certain internal OSAL APIs.                            | Optimized the sensor model. | None            |
| Globalization | - Added data functions such as the digital switch and weekday.<br/>- Added the **Get12HourTimeWithoutAmpm** API. | None                        | None            |

## Resolved Issues

The following table lists the issues known in OpenHarmony 1.1.1 that have been resolved in this version.

**Table  4**  Resolved issues

| Subsystem                | PR No.                                                       | Description                                                  |
| ------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Application Framework    | aafwk_aafwk_lite/pulls/35                                    | There is a low probability that the Linux system cannot be shut down. |
| AI                       | [ai_engine/pulls/50](https://gitee.com/openharmony/ai_engine/pulls/50) | The test case for the client is not released.                |
| AI                       | [ai_engine/pulls/46](https://gitee.com/openharmony/ai_engine/pulls/46) | Class members are not initialized.                           |
| IoT Hardware             | [applications_sample_wifi_iot/pulls/12](https://gitee.com/openharmony/applications_sample_wifi_iot/pulls/12) | A build fails.                                               |
| Compilation and Building | [build_lite/pulls/151](https://gitee.com/openharmony/build_lite/pulls/151) | The test case is not available in the build process.         |
| Chip Platform            | [third_party_ffmpeg/pulls/9](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/pulls/9) | The CVE-2020-22025 vulnerability is detected.                |
| Chip Platform            | [third_party_ffmpeg/pulls/6](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/pulls/6) | A build fails due to the dependency on valgrind in some environments. |
| Chip Platform            | [vendor_hisilicon/pulls/39](https://gitee.com/openharmony/vendor_hisilicon/pulls/39) | Building the release fails.                                  |
| Distributed Scheduler    | distributedschedule_dms_fwk_lite/pulls/23                    | The test case name is inappropriate.                         |
| Distributed Scheduler    | distributedschedule_samgr_lite/pulls/25                      | The CVE-2021-22478 vulnerability is detected.                |
| Globalization            | [global_i18n_lite/pulls/24](https://gitee.com/openharmony/global_i18n_lite/pulls/24) | Resource loading of **i18n.dat** is defective.               |
| Globalization            | [third_party_jerryscript/pulls/22](https://gitee.com/openharmony/third_party_jerryscript/pulls/22) | There is a possibility that the breakpoint cannot be stopped during debugging of the macOS version. |
| Graphics                 | [graphic_ui/pulls/220](https://gitee.com/openharmony/graphic_ui/pulls/220) | The Remove function is provided, but the Add function is not. After the modification, the child nodes are not cleared when the **UIViewGroup** is destructed. |
| Graphics                 | [graphic_ui/pulls/199](https://gitee.com/openharmony/graphic_ui/pulls/199) | The image is not updated after the image path is updated.    |
| Lite Kernel              | [kernel_liteos_a/pulls/385](https://gitee.com/openharmony/kernel_liteos_a/pulls/385) | The CVE-2021-22479 vulnerability is detected.                |
| Lite Kernel              | [kernel_liteos_a/pulls/299](https://gitee.com/openharmony/kernel_liteos_a/pulls/299) | There are unnecessary maintenance and test logs of the PRINTK function. |
| Lite Kernel              | [third_party_musl/pulls/44](https://gitee.com/openharmony/third_party_musl/pulls/44) | The implementation of the srand function for setting random number seeds is inappropriate. |
| Startup                  | [startup_syspara_lite/pulls/31](https://gitee.com/openharmony/startup_syspara_lite/pulls/31) | The date of the security patch is incorrect.                 |
| Driver                   | [drivers_adapter_khdf_linux/pulls/28](https://gitee.com/openharmony/drivers_adapter_khdf_linux/pulls/28) | The CVE-2021-22441 vulnerability is detected.                |
| Driver                   | [drivers_adapter/pulls/50](https://gitee.com/openharmony/drivers_adapter/pulls/50) | The CVE-2021-22480 vulnerability is detected.                |
| Testing                  | [xts_acts/pulls/294](https://gitee.com/openharmony/xts_acts/pulls/294) | Certain test cases of the fs_posix module are unstable.      |
| Testing                  | [xts_acts/pulls/287](https://gitee.com/openharmony/xts_acts/pulls/287) | The acts test fails.                                         |
| Testing                  | [xts_acts/pulls/283](https://gitee.com/openharmony/xts_acts/pulls/283) | Certain CMSIS test cases fail occasionally.                  |
| Testing                  | [xts_acts/pulls/270](https://gitee.com/openharmony/xts_acts/pulls/270) | The ShmTest.testShmatSHM_REMAP function in the ShmTest.cpp test case of the shared_memory module does not run as expected. |
| Testing                  | [xts_acts/pulls/314](https://gitee.com/openharmony/xts_acts/pulls/314) | The test of the net_posix module fails.                      |

