# OpenHarmony 3.1.7 Release


## Version Description

OpenHarmony 3.1.7 Release provides enhanced system security over OpenHarmony 3.1.6 Release by rectifying memory leak issues, certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues. The matching SDK version is also updated.

## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool                                            | Version                                                        | Remarks                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| OpenHarmony                                      | 3.1.7 Release                                          | NA                                                           |
| Full SDK                                   | Ohos_sdk_full 3.1.13.6 (API Version 8 Release) | This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the full SDK, manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| Public SDK                                  | Ohos_sdk_public 3.1.13.6 (API Version 8 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio 3.0 Beta4 or later.|
| (Optional) HUAWEI DevEco Studio          | 3.1 Preview for OpenHarmony                  | Recommended for developing OpenHarmony applications                               |
| (Optional) HUAWEI DevEco Device Tool| 3.0 Release                                            | Recommended for developing OpenHarmony smart devices                   |


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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.7-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.7-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                                  | Version      | Mirror                                                | SHA-256 Checksum                                            |
| ------------------------------------------ | ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base (for mini, small, and standard systems)          | 3.1.7 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/code-v3.1.7-Release.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/code-v3.1.7-Release.tar.gz.sha256) |
| Hi3516 standard system solution (binary)          | 3.1.7 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/standard_hi3516.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/standard_hi3516.tar.gz.sha256) |
| RK3568 standard system solution (binary)          | 3.1.7 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/standard_rk3568.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/standard_rk3568.tar.gz.sha256) |
| Hi3861 mini system solution (binary)          | 3.1.7 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_pegasus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_pegasus.tar.gz.sha256) |
| Hi3516 small system solution - LiteOS (binary)   | 3.1.7 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_taurus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_taurus.tar.gz.sha256) |
| Hi3516 small system solution - Linux (binary)    | 3.1.7 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_taurus_linux.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_taurus_linux.tar.gz.sha256) |
| Full SDK package for the standard system (macOS)            | 3.1.13.6           | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-mac-full-3.1.13.6.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-mac-full-3.1.13.6.tar.gz.sha256) |
| Full SDK package for the standard system (Windows/Linux)  | 3.1.13.6           | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-full-3.1.13.6.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-full-3.1.13.6.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)          | 3.1.13.6           | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-mac-public-3.1.13.6.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-mac-public-3.1.13.6.tar.gz.sha256) |
| Public SDK package for the standard system (Windows/Linux)| 3.1.13.6           | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-public-3.1.13.6.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-public-3.1.13.6.tar.gz.sha256) |


## What's New

This version has the following updates to OpenHarmony 3.1.7 Release.


### Feature Update

This version does not involve feature updates.

### Change APIs

This version does not involve API updates.

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Resolved Issues

**Table 3** Resolved issues

| Subsystem      | Description                                                    |
| ------------ | ------------------------------------------------------------ |
| Application subsystem  | When a user accesses **Contacts**, the default page **No contacts** flashes and the contact list is displayed. ([I5ET9R](https://gitee.com/openharmony/applications_contacts/issues/I5ET9R))<br>A widget is created and pushed to the RK3568 development board. It is then added to the home screen. When a user holds the widget on the home screen, the page showing **Service widget** and **Remove** is displayed, and the application is opened. ([I5YB1O](https://gitee.com/openharmony/applications_hap/issues/I5YB1O))<br>A cpp crash issue is detected using the tool. ([I65H83](https://gitee.com/openharmony/applications_permission_manager/issues/I65H83)).<br>A cpp crash issue is detected using the tool. ([I65TVW](https://gitee.com/openharmony/applications_permission_manager/issues/I65TVW)).<br>Memory leakage occurs when a user repeatedly clicks **Recent** on **Launcher**. ([I67SRG](https://gitee.com/openharmony/xts_acts/issues/I67SRG))|
| Multimedia subsystem  | There is a high probability that the home screen crashes when a user opens **Gallery**, touches the **Albums** tab, and then touches **Camera**. ([I5QUSZ](https://gitee.com/openharmony/applications_hap/issues/I5QUSZ))<br>A cpp crash issue is detected using the tool. ([I65GZ1](https://gitee.com/openharmony/multimedia_medialibrary_standard/issues/I65GZ1))|
| Globalization subsystem| A cpp crash issue is detected using the tool. ([I65GR8](https://gitee.com/openharmony/global_resmgr_standard/issues/I65GR8))|
| Accessibility subsystem| The test report of an injection attack test shows that the **ohos.accessibility.IAccessibleAbilityManagerServiceClient** API has an injection exception. ([I65PHE](https://gitee.com/openharmony/accessibility/issues/I65PHE))|
| ArkUI development framework | The image effect function is invalid. ([I65UID](https://gitee.com/openharmony/arkui_ace_engine/issues/I65UID))<br>Adaptation to the multi-resource build package is required for mini-, small- and stardard-system devices. ([I78S6M](https://gitee.com/openharmony/developtools_ace_js2bundle/issues/I78S6M))|
| Ability framework| After two windows are paired in split-screen mode, if one window is closed, the other window is also closed. ([I6AF0Y](https://gitee.com/openharmony/ability_ability_runtime/issues/I6AF0Y))|
| DFX subsystem   | **libhilog.z.so** crashes in **ohos.samples.distributedmusicplayer**. ([I6DCSL](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I6DCSL))|


### Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No. | Description                                                    | PR Link                                                    |
| ------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| I67XCL | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-3640.          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/659) |
| I6A56Q | Security vulnerability of the kernel_linux_5.10 component: CVE-2023-20928         | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/653) |
| I6B0K7 | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-4696          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/663) |
| I6BNVW | Security vulnerabilities of the mbedtls component: CVE-2021-44732 and CVE-2021-45450   | [PR](https://gitee.com/openharmony/third_party_mbedtls/pulls/78) |
| I6BTZM | Security vulnerability of the flutter component: CVE-2022-37434                   | [PR](https://gitee.com/openharmony/third_party_flutter/pulls/247) |
| I6BXT0 | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2023-23559, CVE-2023-0179, CVE-2023-23454, and CVE-2023-23455| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/661) |
| I6DQAH | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2023-0590 and CVE-2022-3707| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/687) |
| I6DTV8 | Security vulnerability of the libexif component: CVE-2019-9278                    | [PR](https://github.com/libexif/libexif/commit/75aa73267fdb1e0ebfbc00369e7312bac43d0566) |
| I6E5KA | Security vulnerability of the openssl component: CVE-2023-0286                    | [PR](https://gitee.com/openharmony/third_party_openssl/pulls/83) |
| I6FFUV | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2023-20938, CVE-2023-0045, and CVE-2023-0615| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/696) |
| I6FZ3A | Security vulnerability of the cares component: CVE-2022-4904                      | [PR](https://gitee.com/openharmony/third_party_cares/pulls/12) |
| I6HYRO | Security vulnerability of the kernel_linux_4.19 component: CVE-2022-3028          | [PR](https://gitee.com/openharmony/kernel_linux_4.19/pulls/98) |
| I6JH1I | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2023-0461, CVE-2023-23004, CVE-2023-23000, CVE-2023-1078, CVE-2023-1076, CVE-2023-1118, CVE-2023-22995, and CVE-2023-26545| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/725) |
| I6JH1L | Security vulnerabilities of the kernel_linux_4.19 component: CVE-2023-0461, CVE-2023-26545, CVE-2022-0480, CVE-2023-1118, CVE-2022-1652, and CVE-2021-3760| [PR](https://gitee.com/openharmony/kernel_linux_4.19/pulls/107) |
| I6JH2L | Security vulnerabilities of the kernel_linux_4.19 component: CVE-2023-23559, CVE-2022-47929, CVE-2022-2873, and CVE-2023-23455| [PR](https://gitee.com/openharmony/kernel_linux_4.19/pulls/103) |
| I6LCHO | Security vulnerability of the kernel_linux_4.19 component: CVE-2023-0030          | [PR](https://gitee.com/openharmony/kernel_linux_4.19/pulls/111) |

## Known Issues 

**Table 5** Known issues

| Issue No.                                                       | Description                              | Impact          | To Be Resolved By|
| ------------------------------------------------------------ | -------------------------------------- | -------------- | ------------ |
| [I6HAUC](https://gitee.com/openharmony/xts_acts/issues/I6HAUC) | [3.1] When the Windows API is called, the mouse is distorted in landscape/portrait mode.| Developer experience is affected.| 2023-04-28   |
