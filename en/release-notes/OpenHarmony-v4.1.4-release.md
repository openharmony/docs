# OpenHarmony 4.1.4 Release


## Version Overview

OpenHarmony 4.1.4 Release provides enhanced system security over OpenHarmony 4.1.3 Release by rectifying certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues.

## Mapping relationship

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.1.4 Release | NA |
| Public SDK | Ohos_sdk_public 4.1.10.5 (API Version 11 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.|
| (Optional) HUAWEI DevEco Studio| 4.1 Release | Recommended for developing OpenHarmony applications. How to obtain:<br><br>SHA-256 checksum: c46be4f3cfde27af1806cfc9860d9c366e66a20e31e15180cf3a90ab05464650<br><br>SHA-256 checksum: 15d6136959b715e4bb2160c41d405b889820ea26ceadbb416509a43e59ed7f09<br><br>SHA-256 checksum: ac04ca7c2344ec8f27531d5a59261ff037deed2c5a3d42ef88e6f90f4ed45484 |
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide#download). |


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

4. Install the **repo** tool.
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the permission, download the tool to another directory and add that directory to environment variables. chmod a+x /usr/local/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### Acquiring Source Code Using the repo Tool

**Method 1: Using SSH (Recommended)**

This method requires an SSH public key for access to Gitee.


Obtain the source code from the specified version tag, which is the same as that released with the version.
```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1.4-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

Obtain the source code from the specified version tag, which is the same as that released with the version.
```
repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1.4-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.1.4 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/code-v4.1.4-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/code-v4.1.4-Release.tar.gz.sha256) | 36.4 GB |
| Hi3861 solution (binary)       | 4.1.4 Release   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_pegasus.tar.gz.sha256) | 27.1 MB |
| Hi3516 solution-LiteOS (binary)| 4.1.4 Release | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 320.2 MB |
| Hi3516 solution-Linux (binary) | 4.1.4 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_taurus_Linux.tar.gz.sha256) | 215.1 MB |
| RK3568 standard system solution (binary)       | 4.1.4 Release   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| Public SDK package for the standard system (macOS)            | 4.1.10.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/ohos-sdk-mac-public.tar.gz.sha256) | 913.3 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.1.10.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 884.0 MB |
| Public SDK package for the standard system (Windows/Linux)  | 4.1.10.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |


## What's New

 N/A

## Fixed Bugs and Security Issues

**Table 3** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [IC3RPF](https://gitee.com/openharmony/communication_dsoftbus/issues/IC3RPF?from=project-issue) | Added null detection and deinitialization.                          |
| [IC4D1Q](https://gitee.com/openharmony/communication_ipc/issues/IC4D1Q?from=project-issue) | Addressed IPC security issues.                                             |
| [IC4FOW](https://gitee.com/openharmony/communication_dsoftbus/issues/IC4FOW?from=project-issue) | [DSoftBus] Fixed security vulnerabilities in transmission code.                      |
| [IBLSXD](https://gitee.com/openharmony-sig/security_security_component_manager/issues/IBLSXD?from=project-issue) | Resolved the issue of repeated use of security control scId.                                    |
| [IC2SOO](https://gitee.com/openharmony/kernel_linux_5.10/issues/IC2SOO?from=project-issue) | Code updated to 4.1.                                                 |
| [IC2V5S](https://gitee.com/openharmony/communication_ipc/issues/IC2V5S?from=project-issue) | Synchronized RemoteObjectTranslateWhenRcv issue to 4.1.                 |
| [IC1FQC](https://gitee.com/openharmony/arkui_ace_engine/issues/IC1FQC?from=project-issue) | Addressed security coding issues (0415).                                           |
| [IC179F](https://gitee.com/openharmony/arkui_ace_engine/issues/IC179F?from=project-issue) | Modified scrollbar compilation warnings.                                       |
| [IC14FS](https://gitee.com/openharmony/arkui_ace_engine/issues/IC14FS?from=project-issue) | Fixed array out-of-bounds in Dialog.                                              |
| [IBYLBN](https://gitee.com/openharmony/developtools_syscap_codec/issues/IBYLBN?from=project-issue) | Fixed stack overflow issues for 4.1.                                           |
| [IBTUSR](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBTUSR?from=project-issue) | Integrated fixes for three vulnerabilities into 4.1.                                  |
| [IBGXUO](https://gitee.com/openharmony/filemanagement_dfs_service/issues/IBGXUO?from=project-issue) | [RK3568] Addressed the issue where the cloudfileservice process does not automatically exit after being triggered by a camera recording event.|
| [IBT30S](https://gitee.com/openharmony/multimedia_av_codec/issues/IBT30S?from=project-issue) | Fixed nullptr bug in 4.1.                               |
| [IBQY5G](https://gitee.com/openharmony/arkui_ace_engine/issues/IBQY5G?from=project-issue) | Addressed FD leak issues.                                           |
| [IBQTJP](https://gitee.com/openharmony/bundlemanager_bundle_framework/issues/IBQTJP?from=project-issue) | Fixed multithreading issues for zero-service installation in 4.1.                             |
| [IBR3V5](https://gitee.com/openharmony/communication_dsoftbus/issues/IBR3V5?from=project-issue) | [DSoftBus] [Transmission] Optimized FD leakage.                          |
| [IBP0R4](https://gitee.com/openharmony/startup_init/issues/IBP0R4?from=project-issue) | Rectified array out-of-bounds in init_group_manager.c for 4.1.          |

**Table 4** Fixed security vulnerabilities

| Issue No.                                                     | Description                                                    |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| [IC50QY](https://gitee.com/openharmony/kernel_linux_5.10/issues/IC50QY?from=project-issue) | [Vulnerability] 4.1-Release CVE patch synchronized                           |
| [IBXXSV](https://gitee.com/openharmony/third_party_freetype/issues/IBXXSV?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-27363 in the openeuler:freetype component|
| [IC1YRZ](https://gitee.com/openharmony/kernel_linux_5.10/issues/IC1YRZ?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE patches incorporated                                |
| [IBXXSW](https://gitee.com/openharmony/third_party_skia/issues/IBXXSW?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-8176 in the openeuler:expat component|
| [IBXWML](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWML?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-57981 in the Linux kernel component|
| [IBXWN5](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWN5?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-21764 in the Linux kernel component|
| [IBXWNB](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWNB?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-21785 in the Linux kernel component|
| [IBT0OJ](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0OJ?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2022-48657 in the Linux kernel component|
| [IBT0UG](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0UG?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-57798 in the Linux kernel component|
| [IBT0XE](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0XE?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-57884 in the Linux kernel component|
| [IBT0Z1](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0Z1?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-57888 in the Linux kernel component|
| [IBT0ZN](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0ZN?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-57913 in the Linux kernel component|
| [IBT11B](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT11B?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-58005 in the Linux kernel component|
| [IBT12A](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT12A?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-21648 in the Linux kernel component|
| [IBT12Y](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT12Y?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-21728 in the Linux kernel component|
| [IBT13J](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT13J?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-21814 in the Linux kernel component|
| [IBXWM0](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM0?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2022-49046 in the Linux kernel component|
| [IBXWM2](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM2?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2022-49135 in the Linux kernel component|
| [IBXWM4](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM4?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2022-49443 in the Linux kernel component|
| [IBXWM6](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM6?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2022-49630 in the Linux kernel component|
| [IBXWM7](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM7?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2022-49632 in the Linux kernel component|
| [IBXWMB](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMB?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2022-49651 in the Linux kernel component|
| [IBXWMC](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMC?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-57977 in the Linux kernel component|
| [IBXWMJ](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMJ?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-57980 in the Linux kernel component|
| [IBXWMP](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMP?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-58017 in the Linux kernel component|
| [IBXWMQ](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMQ?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-58020 in the Linux kernel component|
| [IBXWMT](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMT?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-58058 in the Linux kernel component|
| [IBXWMY](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMY?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-21760 in the Linux kernel component|
| [IBXWN1](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWN1?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-21762 in the Linux kernel component|
| [IBXWN7](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWN7?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2025-21776 in the Linux kernel component|
| [IBW4JQ](https://gitee.com/openharmony/kernel_liteos_m/issues/IBW4JQ?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] vul-901221769187168256 |
| [IBZWP0](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBZWP0?from=project-issue) | [Vulnerability] CVE synchronized from master to 4.1-Release                        |
| [IBZA9I](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBZA9I?from=project-issue) | [Vulnerability] CVE synchronized from master to 4.1-Release                        |
| [IBVOLV](https://gitee.com/openharmony/web_webview/issues/IBVOLV?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] vul-901929006431997952 |
| [IBY0M9](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBY0M9?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE patches incorporated                                |
| [IBWHEH](https://gitee.com/openharmony/kernel_liteos_a/issues/IBWHEH?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] vul-905293076359024640 |
| [IBWHG7](https://gitee.com/openharmony/kernel_liteos_a/issues/IBWHG7?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] vul-905292975204995072 |
| [IBWHIW](https://gitee.com/openharmony/kernel_liteos_a/issues/IBWHIW?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] vul-905292389982146560 |
| [IBT05Z](https://gitee.com/openharmony/third_party_cJSON/issues/IBT05Z?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-31755 in the third_party_cJSONl component|
| [IBRFCU](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBRFCU?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE patches incorporated                                |
| [IBIH4L](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBIH4L?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-864686037719322624 |
| [IBIH4V](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBIH4V?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-864685912552902656 |

## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| :------- | :------- | :------- | :------- |
| / | /        | /    | /            |

<!--no_check-->