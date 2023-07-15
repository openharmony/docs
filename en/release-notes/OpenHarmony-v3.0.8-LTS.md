# OpenHarmony 3.0.8 LTS


## Version Description

OpenHarmony 3.0.8 LTS is a maintenance version of OpenHarmony 3.0 LTS. It has rectified certain issues detected in OpenHarmony 3.0.7 LTS.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.0.8 LTS | NA |
| (Optional) HUAWEI DevEco Studio| 3.0 Beta3 for OpenHarmony | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI DevEco Device Tool| 3.0 Release | Recommended for developing OpenHarmony smart devices|


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

**Method 1 (recommended)**: Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.8-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.8-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

  **Table 2** Mirrors for acquiring source code

| LTS Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.0.8 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/code-v3.0.8-LTS.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/code-v3.0.8-LTS.tar.gz.sha256) |
| Standard system Hi3516 solution (binary)| 3.0.8 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/standard.tar.gz) | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/standard.tar.gz.sha256) |
| Mini system Hi3861 solution (binary)| 3.0.8 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_pegasus.tar.gz) | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_pegasus.tar.gz.sha256) |
| Small system Hi3516 solution - LiteOS (binary)| 3.0.8 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_taurus.tar.gz) | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_taurus.tar.gz.sha256) |
| Small system Hi3516 solution - Linux (binary)| 3.0.8 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_taurus_linux.tar.gz) | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_taurus_linux.tar.gz.sha256) |


## What's New


### Feature Updates

This version does not involve feature updates.


### API Updates

This version does not involve API updates.


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Fixed Security Vulnerabilities

  **Table 3** Fixed security vulnerabilities

| Issue No.| Description| PR Link|
| -------- | -------- | -------- |
| I5UHRW | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-41218, CVE-2022-3424, CVE-2022-42328, CVE-2022-3643, and CVE-2022-47946| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/647) |
| I648XK | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-3169| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/561) |
| I5QBIA    | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-1184          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/475) |
| I62G8K | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-42895 and CVE-2022-42896| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/545) |
| I63VI6 | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-41858| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/570) |
| I63VID    | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-45934, CVE-2022-4129, CVE-2022-4378, CVE-2022-3108, CVE-2022-47518, CVE-2022-47521, CVE-2022-47519, and CVE-2022-47520| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/587) |
| I65INV    | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-4139          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/568) |
| I66Y94    | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-3105, CVE-2022-3104, CVE-2022-3115, CVE-2022-3113, and CVE-2022-3112 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/580) |
| I66Y9Y    | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-3106          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/593) |
| I66YAD    | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-3107          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/591) |
| I6A4HN | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-20568| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/630) |
| I6A4IZ | Security vulnerability of the kernel_linux_5.10 component: CVE-2023-20928| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/654) |
| I6B0AN | Security vulnerability of the kernel_linux_5.10 component: CVE-2022-4696| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/664) |
| I6B0B4 | Security vulnerability of the kernel_linux_5.10 component: CVE-2023-23559, CVE-2023-0179, CVE-2023-23454, and CVE-2023-23455| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/662) |
| I65R5Q | Security vulnerability of the third_party_python component: CVE-2022-45061| [PR](https://gitee.com/openharmony/third_party_python/pulls/40) |
| I6494T | Security vulnerabilities of the third_party_libxml2 component: CVE-2022-40303 and CVE-2022-40304| [PR](https://gitee.com/openharmony/third_party_libxml2/pulls/32) |
| I5ZYY3 | Security vulnerability of the third_party_pixman component: CVE-2022-44638| [PR](https://gitee.com/openharmony/third_party_pixman/pulls/12) |
| I5UHVA | Security vulnerability of the third_party_u-boot component: CVE-2022-2347| [PR](https://gitee.com/openharmony/third_party_u-boot/pulls/63) |
