# OpenHarmony 3.1.5 Release


## Version Description

OpenHarmony 3.1.5 Release provides enhanced system security over OpenHarmony 3.1.4 Release by rectifying memory leak issues, certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues. It also provides new SDK versions and resolves previewer issues.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.1.5 Release| NA |
| Full SDK | Ohos_sdk_full 3.1.11.5 (API Version 8 Release)| This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the Full SDK, you must manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| Public SDK | Ohos_sdk_public 3.1.11.5 (API Version 8 Release)| This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio 3.0 Beta4 or later.|
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.5-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.5-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.1.5 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/OpenHarmony-v3.1.5-Release.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/OpenHarmony-v3.1.5-Release.tar.gz.sha256) |
| Hi3516 standard system solution (binary)| 3.1.5 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/standard_hi3516.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/standard_hi3516.tar.gz.sha256)|
| RK3568 standard system solution (binary)| 3.1.5 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/standard_rk3568.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/standard_rk3568.tar.gz.sha256)|
| Hi3861 mini system solution (binary)| 3.1.5 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_pegasus.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_pegasus.tar.gz.sha256) |
| Hi3516 small system solution - LiteOS (binary)| 3.1.5 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_taurus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_taurus.tar.gz.sha256) |
| Hi3516 small system solution - Linux (binary)| 3.1.5 Release| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_taurus_linux.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_taurus_linux.tar.gz.sha256) |
| Full SDK package for the standard system (macOS)| 3.1.11.4 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-mac-full.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-mac-full.tar.gz.sha256) |
| Full SDK package for the standard system (Windows/Linux)| 3.1.11.4 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-full.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-full.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)| 3.1.11.4 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-mac-public.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-mac-public.tar.gz.sha256) |
| Public SDK package for the standard system (Windows/Linux)| 3.1.11.4 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-public.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-public.tar.gz.sha256) |


## Change History

This version has the following updates to OpenHarmony 3.1.4 Release.


### Feature Update

This version does not involve feature updates.

### API Updates

This version does not involve API updates.



### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Resolved Issues

**Table 3** Resolved issues

| Subsystem        | Description                                                    |
| -------------- | ------------------------------------------------------------ |
| SDK subsystem     | Certain issues related to the previewer.                                |
| Network management subsystem| The exception stack libconnection.z.so occurs in thread 1.ui of the com.ohos.netmanagersocket process. ([I5IXWZ](https://gitee.com/openharmony/communication_netmanager_base/issues/I5IXWZ))|
| Misc subsystem    | There is a possibility that the **complete** event is not reported when **request.download** is called. ([I5WZC6](https://gitee.com/openharmony/request_request/issues/I5WZC6))|
| DFX subsystem     | There is a low probability that cpp_crash occurs in hdcd. ([I65P94](https://gitee.com/openharmony/developtools_hdc/issues/I65P94))|
| ArkUI development framework   | The universal attributes of the focusable component are abnormal. ([I64YLA](https://gitee.com/openharmony/arkui_ace_engine/issues/I64YLA))|




### Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.| Description| PR Link|
| -------- | -------- | -------- |
| I5UHSG | Security vulnerability of the das u-boot component: CVE-2022-2347| [PR](https://gitee.com/openharmony/third_party_u-boot/pulls/62) |
| I5UI3F/I5VGDV | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-3303, CVE-2022-42703, CVE-2022-20422, CVE-2022-41222, CVE-2022-3239, CVE-2022-20423 and CVE-2022-41850 | [PR](https://gitee.com/openharmony/third_party_expat/pulls/23) |
| I5XU3W | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-3586, CVE-2022-3625, CVE-2022-42432, CVE-2022-3633, CVE-2022-3635, CVE-2022-3629, CVE-2022-3623, CVE-2022-3646, CVE-2022-3621, CVE-2022-3567, CVE-2022-43750, CVE-2022-3545, CVE-2022-2978, CVE-2022-3523, CVE-2022-2602, and CVE-2022-3628| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/541) |
| I5XUCJ | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-40768, CVE-2022-3577, CVE-2022-20409, CVE-2022-3566, CVE-2022-3606, CVE-2022-3564 and CVE-2022-3649| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/505) |
| I5VGIU | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-3169| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/553) |
| I63VFW | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-41858| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/569) |
| I63VG7 | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-45934, CVE-2022-4129, CVE-2022-4378, CVE-2022-3108, CVE-2022-47518, CVE-2022-47521, CVE-2022-47519, and CVE-2022-47520| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/586) |
| I66ZCI | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-3105, CVE-2022-3104, CVE-2022-3115, CVE-2022-3113, and CVE-2022-3112 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/579) |
| I66ZHX | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-3111| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/584) |
| I66ZKM | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-3107| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/590) |
| I65T2H | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-20566| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/582) |
| I61HGX | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-42895 and CVE-2022-42896| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/545) |
| I652LY | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-4139| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/567) |
| I65R2K | Security vulnerability of the python component: CVE-2022-42919| [PR](https://gitee.com/openharmony/third_party_python/pulls/36) |
| I65R59 | Security vulnerability of the python component: CVE-2022-45061| [PR](https://gitee.com/openharmony/third_party_python/pulls/37) |
| I65UJ8 | Security vulnerability of the python component: CVE-2022-45061| [PR](https://gitee.com/openharmony/third_party_python/pulls/35) |
| I60GOT | Security vulnerability of the pixman component: CVE-2022-37454| [PR](https://gitee.com/openharmony/third_party_pixman/pulls/11) |
| I5Z39U | Security vulnerabilities of the curl component: CVE-2022-32221, CVE-2022-42915, and CVE-2022-42916| [PR](https://gitee.com/openharmony/third_party_curl/pulls/91) |
| I61I8F | Security vulnerability of the ntfs-3g component: CVE-2022-40284| [PR](https://gitee.com/openharmony/third_party_ntfs-3g/pulls/33) |
| I63V9Z | Security vulnerabilities of the libxml2 component: CVE-2022-40303 and CVE-2022-40304| [PR](https://gitee.com/openharmony/third_party_libxml2/pulls/31) |
