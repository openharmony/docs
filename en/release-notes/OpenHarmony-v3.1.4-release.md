# OpenHarmony 3.1.4 Release


## Version Description

OpenHarmony 3.1.4 Release provides enhanced system security over OpenHarmony 3.1.3 Release by rectifying certain known vulnerabilities in open-source components such as Linux kernel. It also provides new SDK versions and resolves previewer issues.


## Mapping relationship

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.1.4 Release| NA |
| Full SDK | Ohos_sdk_full 3.1.9.7 (API Version 8 Relese) | This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the Full SDK, you must manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| Public SDK | Ohos_sdk_public 3.1.9.7 (API Version 8 Release)| This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio 3.0 Beta4 or later.|
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.4-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.4-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.1.4 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/code-v3.1.4-Release-2022-12-12.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/code-v3.1.4-Release-2022-12-12.tar.gz.sha256)|
| Hi3516 standard system solution (binary)| 3.1.4 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/standard_hi3516.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/standard_hi3516.tar.gz.sha256) |
| RK3568 standard system solution (binary)| 3.1.4 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/standard_rk3568.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/standard_rk3568.tar.gz.sha256) |
| Hi3861 mini system solution (binary)| 3.1.4 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_pegasus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_pegasus.tar.gz.sha256) |
| Hi3516 small system solution - LiteOS (binary)| 3.1.4 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_taurus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_taurus.tar.gz.sha256) |
| Hi3516 small system solution - Linux (binary)| 3.1.4 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_taurus_linux.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_taurus_linux.tar.gz.sha256) |
| Full SDK package for the standard system (macOS)| 3.1.9.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-mac-full.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-mac-full.tar.gz.sha256) |
| Full SDK package for the standard system (Windows/Linux)| 3.1.9.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-full.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-full.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)| 3.1.9.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-mac-public.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-mac-public.tar.gz.sha256) |
| Public SDK package for the standard system (Windows/Linux)| 3.1.9.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-public.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-public.tar.gz.sha256) |


## What's New

This version has the following updates to OpenHarmony 3.1.3 Release.


### Feature Updates

This version does not involve feature updates.

### API Updates

This version does not involve API updates.



### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Resolved Issues

**Table 3** Resolved issues

| Subsystem   | Description                                                    |
| --------- | ------------------------------------------------------------ |
| SDK subsystem| Previewer issues. ([I59433](https://gitee.com/openharmony/arkui_ace_engine/issues/I59433), [I5K6B1](https://gitee.com/openharmony/arkui_ace_engine/issues/I5K6B1), [I5C9XJ](https://gitee.com/openharmony/arkui_ace_engine/issues/I5C9XJ), and [I5AVZT](https://gitee.com/openharmony/arkui_ace_engine/issues/I5AVZT))|
| Demo application | Applications become inaccessible after you exit **Settings** on a small-system device. ([I5KTI8](https://gitee.com/openharmony/applications_sample_camera/issues/I5KTI8))|




### Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.| Description| PR Link|
| -------- | -------- | -------- |
| I5SD5S | Security vulnerability of the expat component: CVE-2022-40674.                     | [PR](https://gitee.com/openharmony/third_party_expat/pulls/20) |
| I5XTS9 | Security vulnerability of the expat component: CVE-2022-43680.| [PR](https://gitee.com/openharmony/third_party_expat/pulls/23) |
| I5VNM9 | Security vulnerability of the skia component: CVE-2022-27405.                      | [PR](https://gitee.com/openharmony/third_party_skia/pulls/24) |
| I5VGM0 | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-20421, CVE-2022-42719, CVE-2022-42720, CVE-2022-42721, CVE-2022-42722, CVE-2022-41674, CVE-2022-3535, CVE-2022-3521, CVE-2022-3565, CVE-2022-3594, CVE-2022-3435, CVE-2022-41849, CVE-2022-3524, CVE-2022-3542, and CVE-2022-3534.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/502) |
| I5SBWK | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-3202 and CVE-2022-40307.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/463) |
| I5QBUR | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-1184.          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/474) |
| I5WSJ5 | Security vulnerabilities of the chromium component: CVE-2022-3199, CVE-2022-3046, CVE-2022-3041, CVE-2022-3040, CVE-2022-3039, CVE-2022-3038, CVE-2022-3057, CVE-2022-3195, CVE-2022-3054, and CVE-2022-3075. The webview HAP file is updated.| [PR](https://gitee.com/openharmony/web_webview/pulls/349) |
| I5UF8Z | MAC addresses are leaked in **dhd_linux.c** on the standard system.| [PR](https://gitee.com/openharmony/kernel_linux_patches/pulls/315) |
| I5VISW | MAC addresses are displayed in plaintext in Bluetooth logs on the standard system.           | [PR](https://gitee.com/openharmony/communication_bluetooth/pulls/626) |
| I5WJU0 | Device UDIDs are displayed in distributed networking logs of the standard system.    | [PR](https://gitee.com/openharmony/security_access_token/pulls/761) |
