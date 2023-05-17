# OpenHarmony v1.1.3 LTS (EOL)

## Overview

This is an updated long-term support \(LTS\) version of OpenHarmony. It supports more functions than and fixes some bugs in OpenHarmony 1.1.2.

## Version Mapping

**Table  1**  Version mapping of software and tools

| Software                             | Version                               | Remarks                                              |
| ------------------------------------ | ------------------------------------- | ---------------------------------------------------- |
| OpenHarmony                          | 1.1.3 LTS                             | N/A                                                  |
| (Optional) HUAWEI DevEco Device Tool | HUAWEI DevEco Device Tool 2.1 Release | Recommended for developing OpenHarmony smart devices |

## Source Code Acquisition

### Acquiring Source Code Using the repo Tool

Method 1 \(recommended\): Use the  **repo**  tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)


```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the  **repo**  tool to download the source code over HTTPS.

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### Acquiring Source Code from Mirrors

**Table  2**  Mirrors for acquiring source code

| Source Code              | Version Information | Mirror                                                       | SHA-256 Checksum                                             |
| ------------------------ | ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base           | 1.1.3               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/code-v1.1.3-LTS.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/code-v1.1.3-LTS.tar.gz.sha256) |
| Hi3861 solution (binary) | 1.1.3               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/wifiiot-1.1.3.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/wifiiot-1.1.3.tar.gz.sha256) |
| Hi3518 solution (binary) | 1.1.3               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3518ev300-1.1.3.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3518ev300-1.1.3.tar.gz.sha256) |
| Hi3516 solution (binary) | 1.1.3               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3516dv300-1.1.3.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3516dv300-1.1.3.tar.gz.sha256) |
| Release Notes            | 1.1.3               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.3/OpenHarmony-Release-Notes-1.1.3-LTS.zip) | N/A                                                          |

## What's New

This version inherits all the features of OpenHarmony v1.1.2 and adds the support for version compilation for mini-system devices in the Windows environment. For details, see  [Setting Up the Windows Build Environment](https://device.harmonyos.com/en/docs/documentation/guide/ide-install-windows-0000001050164976).

**Table  3**  Feature updates

| Subsystem     | New Feature                                                  | Modified Feature | Deleted Feature |
| ------------- | ------------------------------------------------------------ | ---------------- | --------------- |
| Chip platform | Supports version compilation for mini-system devices in the Windows environment ([pulls/60](https://gitee.com/openharmony/device_hisilicon_hispark_pegasus/pulls/60)). | N/A              | N/A             |

## Resolved Issues

The following table lists the known issues with OpenHarmony 1.1.2 that have been resolved in this version.

**Table  4**  Resolved issues

| Issue No.                                                    | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I43MZK](https://gitee.com/openharmony/startup_syspara_lite/issues/I43MZK?from=project-issue) | The release 1.0.1 branch name contains spaces, which does not comply with the external interface standard. |
| [I44ZGK](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/issues/I44ZGK?from=project-issue) | The FFmpeg 4.2.2 component has an unfixed vulnerability.     |
| [I41ZMV](https://gitee.com/openharmony/graphic_utils/issues/I41ZMV?from=project-issue) | After ROM flashing on the Hi3516 chip, the **module_ActsUiInterfaceTest1.bin** test file exists in the **bin** directory. |
| [I3ZOIO](https://gitee.com/openharmony/kernel_liteos_a/issues/I3ZOIO?from=project-issue) | Releasing the **los_disk_deinit** resource fails.            |
| [I43WLG](https://gitee.com/openharmony/kernel_liteos_a/issues/I43WLG?from=project-issue) | Starting OsMountRootfs fails.                                |
| [I48FKQ](https://gitee.com/openharmony/kernel_liteos_m/issues/I48FKQ?from=project-issue) | A value other than **0** is returned when **osEventFlagsGet** is set to **NULL**. |
| [I48FL1](https://gitee.com/openharmony/kernel_liteos_m/issues/I48FL1?from=project-issue) | Thread creation fails when **attr** of the **osThreadNew** function is set to **NULL**. |
| [I48FLX](https://gitee.com/openharmony/kernel_liteos_a/issues/I48FLX?from=project-issue) | A system error occurs when the shell command **rm -r** is run to delete a node under **dev**. |
| [I48FMK](https://gitee.com/openharmony/kernel_liteos_a/issues/I48FMK?from=project-issue) | The **ActsProcessApiTest/UidGidTest/testGetgroup** test case of small-system devices fails. |
| [I48FMT](https://gitee.com/openharmony/kernel_liteos_a/issues/I48FMT?from=project-issue) | The implementation of the **nanosleep** function has a defect. |

