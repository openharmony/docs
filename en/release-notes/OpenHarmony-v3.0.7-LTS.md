# OpenHarmony 3.0.7 LTS


## Version Description

OpenHarmony 3.0.7 LTS is a maintenance version of OpenHarmony 3.0 LTS. It has rectified certain issues detected in OpenHarmony 3.0.6 LTS.


## Version mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.0.7 LTS| NA |
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.7-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.7-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

  **Table 2** Mirrors for acquiring source code

| LTS Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.0.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/code-v3.0.7-LTS.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/code-v3.0.7-LTS.tar.gz.sha256)|
| Standard system Hi3516 solution (binary)| 3.0.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/standard.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/standard.tar.gz.sha256)|
| Mini system Hi3861 solution (binary)| 3.0.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_pegasus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_pegasus.tar.gz.sha256) |
| Small system Hi3516 solution - LiteOS (binary)| 3.0.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_taurus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_taurus.tar.gz.sha256) |
| Small system Hi3516 solution - Linux (binary)| 3.0.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_taurus_linux.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_taurus_linux.tar.gz.sha256) |


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
| I5VFI7    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-3303, CVE-2022-42703, CVE-2022-20422, CVE-2022-41222, CVE-2022-3239, CVE-2022-20423 and CVE-2022-41850 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/508) |
| I5UHPU    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-40768, CVE-2022-3577, CVE-2022-20409, CVE-2022-3566, CVE-2022-3606, CVE-2022-3564 and CVE-2022-3649| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/506) |
| I5QBIA    | Security vulnerability of the Kernel_linux_5.10 component: CVE-2022-1184          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/475) |
| I5VFK1    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-20421, CVE-2022-42719, CVE-2022-42720, CVE-2022-42721, CVE-2022-42722, CVE-2022-41674, CVE-2022-3535, CVE-2022-3521, CVE-2022-3565, CVE-2022-3594, CVE-2022-3435, CVE-2022-41849, CVE-2022-3524, CVE-2022-3542, and CVE-2022-3534| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/503) |
| I5OJL9    | Security vulnerability of the Kernel_linux_5.10 component: CVE-2022-26373         | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/495) |
| I5WC2X    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-23816, CVE-2022-29901, and CVE-2022-29900| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/494) |
| I5VQVK    | Security vulnerability of the Kernel_linux_5.10 component: CVE-2022-1462          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/490) |
| I5VP0D    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-39189, CVE-2022-39190, and CVE-2022-2663| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/489) |
| I5QBPW    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-39188, CVE-2022-3078, CVE-2022-2905, and CVE-2022-39842| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/481) |
| I5SCE3    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-3202 and CVE-2022-40307| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/464) |
| I5QBK8    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-3028, CVE-2022-2977, and CVE-2022-2964| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/442) |
| I5RQTK    | Security vulnerability of the Kernel_linux_5.10 component: CVE-2022-3061          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/444) |
| I5R8CM    | Security vulnerabilities of the Kernel_linux_5.10 component: CVE-2022-2959 and CVE-2022-2991| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/436) |
| I5R8BB    | Security vulnerability of the Kernel_linux_5.10 component: CVE-2022-2503          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/435) |
| I5R6VI    | Security vulnerability of the Kernel_linux_5.10 component: CVE-2022-2938          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/434) |
| I5ZA11    | Security vulnerabilities of the curl component: CVE-2022-32221, CVE-2022-42915, and CVE-2022-42916| [PR](https://gitee.com/openharmony/third_party_curl/pulls/90) |
| I5QBFJ    | Security vulnerability of the curl component: CVE-2022-35252                      | [PR](https://gitee.com/openharmony/third_party_curl/pulls/85) |
| I5UHWM    | Security vulnerability of the wayland component: CVE-2021-3782                    | [PR](https://gitee.com/openharmony/third_party_wayland_standard/pulls/22) |
| I5MVPK    | Security vulnerability on the css-what component: CVE-2021-33587                  | [PR](https://gitee.com/openharmony/third_party_css-what/pulls/9) |
| I5YR0H    | Security vulnerability of the gstreamer component: CVE-2021-3185                  | [PR](https://gitee.com/openharmony/third_party_gstreamer/pulls/207) |
| I5XT87    | Security vulnerability of the expat component: CVE-2022-43680                     | [PR](https://gitee.com/openharmony/third_party_expat/pulls/22) |
| I5SD4W    | Security vulnerability of the expat component: CVE-2022-40674                     | [PR](https://gitee.com/openharmony/third_party_expat/pulls/19) |
