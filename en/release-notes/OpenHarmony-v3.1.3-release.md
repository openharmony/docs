# OpenHarmony 3.1.3 Release


## Version Description

OpenHarmony 3.1.3 Release provides enhanced system security over OpenHarmony 3.1.2 Release by rectifying certain known vulnerabilities in open-source components such as Linux kernel and Python.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.1.3 Release | NA |
| Full SDK| Ohos_sdk_full 3.1.7.7 (API Version 8 Release)| This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the Full SDK, you must manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md). |
| Public SDK| Ohos_sdk_public 3.1.7.7 (API Version 8 Release)| This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio 3.0 Beta4 or later.|
| (Optional) HUAWEI DevEco Studio| 3.0 Release for OpenHarmony| Recommended for developing OpenHarmony applications|
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.3-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.3-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.1.3 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/code-v3.1.3-Release.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/code-v3.1.3-Release.tar.gz.sha256)|
| Hi3516 standard system solution (binary)| 3.1.3 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/standard_hi3516.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/standard_hi3516.tar.gz.sha256)|
| RK3568 standard system solution (binary)| 3.1.3 Release| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.3/standard_rk3568.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/standard_rk3568.tar.gz.sha256)|
| Hi3861 mini system solution (binary)| 3.1.3 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_pegasus.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_pegasus.tar.gz.sha256)|
| Hi3516 small system solution - LiteOS (binary)| 3.1.3 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_taurus.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_taurus.tar.gz.sha256)|
| Hi3516 small system solution - Linux (binary)| 3.1.3 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_taurus_linux.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_taurus_linux.tar.gz.sha256)|
| Full SDK package for the standard system (macOS)| 3.1.7.7 | [Download](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-mac-full.tar.gz)| [Download](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-mac-full.tar.gz.sha256) |
| Full SDK package for the standard system (Windows/Linux)| 3.1.7.7 | [Download](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-full.tar.gz)| [Download](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-full.tar.gz.sha256)|
| Public SDK package for the standard system (macOS)| 3.1.7.7 | [Download](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-mac-public.tar.gz)| [Download](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-mac-public.tar.gz.sha256)|
| Public SDK package for the standard system (Windows/Linux)| 3.1.7.7 | [Download](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-public.tar.gz)| [Download](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-public.tar.gz.sha256)|


## What's New

This version has the following updates to OpenHarmony 3.1.2 Release.

### Feature Updates

This version does not involve feature updates.

### API Updates

This version does not involve API updates.

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

**Table 3** Resolved issues

| Subsystem| Description|
| -------- | -------- |
| Multimedia subsystem| There is a possibility that the board restarts unexpectedly when a video in **Gallery** is played in the Hi3516 development board of the standard system. ([I5N70Z](https://gitee.com/openharmony/kernel_linux_config/issues/I5N70Z))|


## Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.| Description| PR Link|
| -------- | -------- | -------- |
| I5QAEX | When the test device connects to a Wi-Fi hotspot provided by a mobile phone, the IP address is printed in the log.| [PR](https://gitee.com/openharmony/communication_netmanager_base/pulls/527) |
| I5QBQD | The startup log of dsoftbus_standard contains plaintext MAC addresses.| [PR](https://gitee.com/openharmony/communication_dsoftbus/pulls/2328) |
| I5R13H | The startup log of dhd contains plaintext MAC addresses.| [PR](https://gitee.com/openharmony/kernel_linux_patches/pulls/304) |
| I5MVEM | Security vulnerability of the css-what component: CVE-2021-33587.| [PR](https://gitee.com/openharmony/third_party_css-what/pulls/8) |
| I5QBNS | Security vulnerability of the curl component: CVE-2022-35252.| [PR](https://gitee.com/openharmony/third_party_curl/pulls/83) |
| I5MR1V | Security vulnerabilities of the linux_kernel component: CVE-2022-2588, CVE-2022-2585, CVE-2022-20369, and CVE-2022-20368.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/426) |
| I5MQS0 | Security vulnerability of the linux_kernel component: CVE-2022-2586.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/427) |
| I5P0W4 | Security vulnerabilities of the linux_kernel component: CVE-2022-2959 and CVE-2022-2991.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/428) |
| I5P0TX | Security vulnerability of the linux_kernel component: CVE-2022-2938.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/430) |
| I5QBWI | Security vulnerabilities of the linux_kernel component: CVE-2022-3028, CVE-2022-2977, and CVE-2022-2964.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/440) |
| I5QC1O | Security vulnerabilities of the linux_kernel component: CVE-2022-39188, CVE-2022-3078, CVE-2022-2905, and CVE-2022-39842.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/450) |
| I5P0WN | Security vulnerability of the linux_kernel component: CVE-2022-26373| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/461) |
| I5NZKV | Security vulnerability of the linux_kernel component: CVE-2022-2503.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/431) |
| I5R2L0 | Security vulnerability of the linux_kernel component: CVE-2022-3061.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/443) |
| I5R2JQ | Security vulnerabilities of the linux_kernel component: CVE-2022-2663, CVE-2022-39190, and CVE-2022-39189.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/445) |
| I5R8X1 | Security vulnerability of the Python component: CVE-2021-29921.| [PR](https://gitee.com/openharmony/third_party_python/pulls/19) |
| I5R8X1 | Security vulnerability of the Python component: CVE-2022-0391.| [PR](https://gitee.com/openharmony/third_party_python/pulls/23) |
| I5R8X1 | Security vulnerability of the Python component: CVE-2021-3737.| [PR](https://gitee.com/openharmony/third_party_python/pulls/20) |
| I5R8X1 | Security vulnerability of the Python component: CVE-2021-4189.| [PR](https://gitee.com/openharmony/third_party_python/pulls/21) |
| I5R8X1 | Security vulnerability of the Python component: CVE-2021-3733.| [PR](https://gitee.com/openharmony/third_party_python/pulls/22) |
| I5R8X1 | Security vulnerability of the Python component: CVE-2021-28861.| [PR](https://gitee.com/openharmony/third_party_python/pulls/24) |
