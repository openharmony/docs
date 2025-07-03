# OpenHarmony 4.1.3 Release


## Version Overview

OpenHarmony 4.1.3 Release provides enhanced system security over OpenHarmony 4.1.2 Release by rectifying certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues.

## Mapping Relationship

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.1.3 Release | NA |
| Public SDK | Ohos_sdk_public 4.1.9.4 (API Version 11 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.|
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1.3-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

Obtain the source code from the specified version tag, which is the same as that released with the version.
```
repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1.3-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.1.3 Release   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/code-v4.1.3-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/code-v4.1.3-Release.tar.gz.sha256) | 34.8 GB |
| Hi3861 solution (binary)       | 4.1.3 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_pegasus.tar.gz.sha256) | 27.1 MB |
| Hi3516 solution-LiteOS (binary)| 4.1.3Release   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 320.1 MB |
| Hi3516 solution-Linux (binary) | 4.1.3 Release   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_taurus_Linux.tar.gz.sha256) | 215.1 MB |
| RK3568 standard system solution (binary)       | 4.1.3 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| Public SDK package for the standard system (macOS)            | 4.1.9.4 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/ohos-sdk-mac-public.tar.gz.sha256) | 913.3 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.1.9.4 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 884.0 MB |
| Public SDK package for the standard system (Windows/Linux)  | 4.1.9.4 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |


## What's New

 N/A

## Fixed Bugs and Security Issues

**Table 3** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [IAOH0J](https://gitee.com/openharmony/useriam_user_auth_framework/issues/IAOH0J?from=project-issue) | [RK3568] The libuserauth_client.z.so process crashes due to the OS_IPC_2_834 thread in the foundation process.|
| [IBE7FX](https://gitee.com/openharmony/third_party_musl/issues/IBE7FX?from=project-issue) | [RK3568] The cppcrash occurs in the OS_IPC_6_936 thread under the foundation process once. The crash stack is libdistributed_ability_manager_svr.z.so.|
| [IB7TVH](https://gitee.com/openharmony/communication_netmanager_base/issues/IB7TVH?from=project-issue) | [RK3568] The OS_IPC_2_784 thread under the Process name:foundation process crashes twice. The crash stack is libnet_manager_common.z.so.|
| [IBBNLR](https://gitee.com/openharmony/commonlibrary_ets_utils/issues/IBBNLR?from=project-issue) | [RK3568] Fixed the worker memory leak.                                |
| [IAPG6G](https://gitee.com/openharmony/filemanagement_dfs_service/issues/IAPG6G?from=project-issue) | [RK3568] CloudFileService is a non-resident process and is started by the Wi-Fi scanning event loop.|
| [IAAB5R](https://gitee.com/openharmony/arkui_ace_engine/issues/IAAB5R?from=project-issue) | [RK3568] [10/10] The editable component that is set to.enabled (false) is dragged to the text component area. The component center is 8 vp above the top.|
| [I9BKLO](https://gitee.com/openharmony/applications_mms/issues/I9BKLO?from=project-issue) | [RK3568] jscrash is displayed under the com.ohos.mms process twice, and the stack name is nameClick.|
| [IAVSNL](https://gitee.com/openharmony/web_webview/issues/IAVSNL?from=project-issue) | [RK3568] Verifying the UID when processing the edm event                        |
| [IBH4N7](https://gitee.com/openharmony/distributedhardware_device_manager/issues/IBH4N7?from=project-issue) | [RK3568] UX modification of the 4.1 release branch                              |
| [IBJL5T](https://gitee.com/openharmony/web_webview/issues/IBJL5T?from=project-issue) | [RK3568] The rendering function is unavailable when nodelesses.hap is installed for the same-layer rendering test.|
| [IBJ6EC](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBJ6EC?from=project-issue) | [RK3568] Cherry-Pick 10577 to 4.1 Release                  |
| [IBJ7R4](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBJ7R4?from=project-issue) | [RK3568] Cherry-Pick 10642 to 4.1 Release                  |
| [IBKK6D](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBKK6D?from=project-issue) | [RK3568] Join Issue After Cherry-Picking PR 10501 to 4.1 Release     |
| [IBJ90O](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBJ90O?from=project-issue) | [RK3568] Cherry-pick 10670 to 4.1Release                   |
| [IBH1E9](https://gitee.com/openharmony/window_window_manager/issues/IBH1E9?from=project-issue) | [RK3568] A C++ crash occurs on libmodal_system_ui_extension_client.z.so due to an error of the OS_FFRT_2_0 thread of the foundation process. This issue occurs twice.|
| [IBIZ14](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBIZ14?from=project-issue) | [RK3568] The vulnerability is incorporated into the OpenHarmony-4.1-Release branch.               |
| [IBIWKU](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBIWKU?from=project-issue) | [RK3568] Cherry-Pick bug fix to 4.1                        |
| [IBI74E](https://gitee.com/openharmony/communication_dsoftbus/issues/IBI74E?from=project-issue) | [RK3568] Fixed risky vulnerabilities.                                      |
| [IBGUBD](https://gitee.com/openharmony/applications_app_samples/issues/IBGUBD?from=project-issue) | [RK3568] Deleted redundant binary files from WorkScheduler.                  |
| [IBGHNE](https://gitee.com/openharmony/applications_app_samples/issues/IBGHNE?from=project-issue) | [RK3568] Upgrading the HapBuild Project, Deleting Redundant Files, and Replacing the Signing Tool|
| [IBGJHO](https://gitee.com/openharmony/arkui_ace_engine/issues/IBGJHO?from=project-issue) | [RK3568] The editable component that is set to.enabled(false) is dragged to the text component area. The component is 8 vp from the top center of the component. |

**Table 4** Fixed security vulnerabilities

| Issue No.                                                     | Description                                                    |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| [IBHYAM](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBHYAM?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-871978016102682624|
| [IBISRC](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISRC?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56605 in the Linux kernel component|
| [IBLGDX](https://gitee.com/openharmony/third_party_NuttX/issues/IBLGDX?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-884973832148881408 |
| [IBISTN](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISTN?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56647 in the Linux kernel component|
| [IBISOU](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISOU?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56583 in the Linux kernel component|
| [IBISPT](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISPT?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-53171 in the Linux kernel component|
| [IBISSV](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISSV?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56606 in the Linux kernel component|
| [IBISUH](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISUH?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56658 in the Linux kernel component|
| [IBISV2](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISV2?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56688 in the Linux kernel component|
| [IBISWH](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISWH?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56692 in the Linux kernel component|
| [IBISXD](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISXD?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56720 in the Linux kernel component|
| [IBISYG](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISYG?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56739 in the Linux kernel component|
| [IBISZC](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISZC?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56756 in the Linux kernel component|
| [IBIT1N](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBIT1N?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56763 in the Linux kernel component|
| [IBIT2H](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBIT2H?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56769 in the Linux kernel component|
| [IBIT3K](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBIT3K?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56770 in the Linux kernel component|
| [IBK84G](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBK84G?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE patches incorporated  |
| [IBJSHR](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBJSHR?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-53173 in the Linux kernel component|
| [IBJSIV](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBJSIV?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-56369 in the Linux kernel component|
| [IBKPCV](https://gitee.com/openharmony/kernel_liteos_a/issues/IBKPCV?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-887050703653048320 |
| [IBINMH](https://gitee.com/openharmony/communication_dsoftbus/issues/IBINMH?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-871975948294033408 |
| [IBINMC](https://gitee.com/openharmony/communication_dsoftbus/issues/IBINMC?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-871976081169584128 |
| [IBG37W](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBG37W?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE patches incorporated             |
| [IBIKDC](https://gitee.com/openharmony/kernel_liteos_a/issues/IBIKDC?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-879923376297086976  |
| [IBI1JO](https://gitee.com/openharmony/communication_dsoftbus/issues/IBI1JO?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] RecvMessageDeinit in Disc_ble.c is not locked, and no upper limit is set in disc_manager.c, which poses security risks.|
| [IBHTM4](https://gitee.com/openharmony/kernel_liteos_a/issues/IBHTM4?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-879883602844717056  |
| [IBFEJ7](https://gitee.com/openharmony/applications_app_samples/issues/IBFEJ7?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] Problematic axios 1.6.2 referenced|
| [IBFEWO](https://gitee.com/openharmony/applications_app_samples/issues/IBFEWO?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] Problematic body-parser 1.20.1 and 1.20.2 referenced|
| [IBFF0F](https://gitee.com/openharmony/applications_app_samples/issues/IBFF0F?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] Problematic braces (dev) 3.0.2 referenced|
| [IBGB67](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBGB67?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE patches incorporated                |
| [IB8M92](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8M92?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-50256 in the Linux kernel component|
| [IB8L2B](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8L2B?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-38594 in the Linux kernel component|
| [IBE44O](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBE44O?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE patches incorporated             |
| [IBERYF](https://gitee.com/openharmony/kernel_liteos_a/issues/IBERYF?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-873354661225041920 |
| [IBEB48](https://gitee.com/openharmony/kernel_liteos_a/issues/IBEB48?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-872272903297568768 |
| [IBDWNM](https://gitee.com/openharmony/kernel_liteos_a/issues/IBDWNM?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-871586908591886336 |
| [IBJESO](https://gitee.com/openharmony/third_party_openssl/issues/IBJESO?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-13176          |
| [IBFN54](https://gitee.com/openharmony-sig/chromium_src/issues/IBFN54?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2023-6112           |

## Known Issues

**Table 5** Known issues

| ISSUE | Description| Impact| To Be Resolved By|
| :------- | :------- | :------- | :------- |
| / | /        | /    | /            |

<!--no_check-->