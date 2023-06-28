# OpenHarmony 3.1.6 Release


## Version Description

OpenHarmony 3.1.6 Release provides enhanced system security over OpenHarmony 3.1.5 Release by rectifying memory leak issues, certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues. The matching SDK version is also updated.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.1.6 Release | NA |
| Full SDK | Ohos_sdk_full 3.1.12.5 (API Version 8 Release)| This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the Full SDK, you must manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| Public SDK | Ohos_sdk_public 3.1.12.5 (API Version 8 Release)| This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio 3.0 Beta4 or later.|
| (Optional) HUAWEI DevEco Studio| 3.1 Preview for OpenHarmony| Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI DevEco Device Tool| 3.0 Release| Recommended for developing OpenHarmony smart devices|


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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.6-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.6-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.1.6 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/code-v3.1.6-Release.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/code-v3.1.6-Release.tar.gz.sha256) |
| Hi3516 standard system solution (binary)| 3.1.6 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/standard_hi3516.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/standard_hi3516.tar.gz.sha256) |
| RK3568 standard system solution (binary)| 3.1.6 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/standard_rk3568.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/standard_rk3568.tar.gz.sha256) |
| Hi3861 mini system solution (binary)| 3.1.6 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_pegasus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_pegasus.tar.gz.sha256) |
| Hi3516 small system solution - LiteOS (binary)| 3.1.6 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_taurus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_taurus.tar.gz.sha256) |
| Hi3516 small system solution - Linux (binary)| 3.1.6 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_taurus_linux.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_taurus_linux.tar.gz.sha256) |
| Full SDK package for the standard system (macOS)| 3.1.12.5 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-mac-full.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-mac-full.tar.gz.sha256) |
| Full SDK package for the standard system (Windows/Linux)| 3.1.12.5 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-full.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-full.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)| 3.1.12.5 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-mac-public.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-mac-public.tar.gz.sha256) |
| Public SDK package for the standard system (Windows/Linux)| 3.1.12.5 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-public.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-public.tar.gz.sha256) |


## What's New

This version has the following updates to OpenHarmony 3.1.5 Release.


### Feature Updates

This version does not involve feature updates.

### API Updates

This version does not involve API updates.

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Resolved Issues

**Table 3** Resolved issues

| Subsystem            | Description                                                    |
| ------------------ | ------------------------------------------------------------ |
| Application subsystem        | The JS crash occurs multiple times in the updateCallTimeList stack of the com.ohos.callui application. ([I5LWIW](https://gitee.com/openharmony/applications_call/issues/I5LWIW))|
| Globalization subsystem      | The exception stack libglobal_resmgr.z.so occurs multiple times in the com.ohos.launch thread of the key process com.ohos.launcher. ([I5LT0M](https://gitee.com/openharmony/global_resource_management/issues/I5LT0M))<br>The exception stack libglobal_resmgr.z.so occurs multiple times in the 2.ui thread of the com.ohos.permissionmanager process. ([I68J7P](https://gitee.com/openharmony/global_resource_management/issues/I68J7P))|
| Misc services subsystem| The CPP crash occurs in the com.example.kikakeyboard process of libinputmethod_client.z.so. ([I66W3B](https://gitee.com/openharmony/inputmethod_imf/issues/I66W3B))<br>The CPP crash occurs during a pressure test using a tool. ([I65K13](https://gitee.com/openharmony/inputmethod_imf/issues/I65K13))|
| Distributed hardware        | The JS crash occurs multiple times in com.ohos.devicemanagerui. ([I69LD9](https://gitee.com/openharmony/distributedhardware_device_manager/issues/I69LD9))|
| DSoftBus      | Media resources of the peer device cannot be displayed after the distributed Gallery network is restarted. ([I674LD](https://gitee.com/openharmony/applications_photos/issues/I674LD))|


### Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.| Description| PR Link|
| -------- | -------- | -------- |
| I5UI5A | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-41218, CVE-2022-3424, CVE-2022-42328, CVE-2022-3643, and CVE-2022-47946| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/646) |
| I69WX6 | Security vulnerability of the ffmpeg component: CVE-2022-3341                   | [PR](https://gitee.com/openharmony/third_party_ffmpeg/pulls/74) |
| I68JS0 | Security vulnerability of the ffmpeg component: CVE-2022-3109                   | [PR](https://gitee.com/openharmony/third_party_ffmpeg/pulls/71) |
| I671DT | Security vulnerabilities of the curl component: CVE-2022-43551 and CVE-2022-43552    | [PR](https://gitee.com/openharmony/third_party_curl/pulls/99) |
| I6A4YJ | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-20568       | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/629) |
| I6A55C | Security vulnerability of the kernel_linux_5.10 component: CVE-2023-0047        | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/631) |

##  Known Issues

**Table 5** Known issues

| Issue No.                                                       | Description                                                  | Impact            | To Be Resolved By|
| ------------------------------------------------------------ | ---------------------------------------------------------- | ---------------- | ------------ |
| [I6AF0Y](https://gitee.com/openharmony/ability_ability_runtime/issues/I6AF0Y) | When two windows are paired in split-screen mode, if one window is closed, the other window is also closed.| Exiting the split-screen mode does not take effect.| 2023/02/15        |
