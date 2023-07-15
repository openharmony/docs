# OpenHarmony 3.0.6 LTS


## Version Description

OpenHarmony 3.0.6 LTS is a maintenance version of OpenHarmony 3.0 LTS. It has rectified certain issues detected in OpenHarmony 3.0.5 LTS.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 3.0.6 LTS| NA | 
| (Optional) HUAWEI DevEco Studio| 3.0 Beta1| Recommended for developing OpenHarmony applications| 
| (Optional) HUAWEI DevEco Device Tool| 2.2 Beta2 | Recommended for developing OpenHarmony smart devices| 


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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.6-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.

  
```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.6-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

  **Table 2** Mirrors for acquiring source code

| LTS Code| Version| Mirror| SHA-256 Checksum| 
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.0.6 | [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/code-v3.0.6-LTS.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/code-v3.0.6-LTS.tar.gz.sha256)| 
| Standard system Hi3516 solution (binary)| 3.0.6 | [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/standard.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/standard.tar.gz.sha256)| 
| Mini system Hi3861 solution (binary)| 3.0.6 | [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_pegasus.tar.gz.sha256)| 
| Small system Hi3516 solution - LiteOS (binary)| 3.0.6 | [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_taurus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_taurus.tar.gz.sha256)| 
| Small system Hi3516 solution - Linux (binary)| 3.0.6 | [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_taurus_linux.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_taurus_linux.tar.gz.sha256)| 


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
| I5MTWL | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-36123, CVE-2022-20369, CVE-2022-2588, CVE-2022-2586, CVE-2022-2585, and CVE-2022-20368.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/402) | 
| 5FYFI | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-34918, CVE-2022-2318, and CVE-2022-2380.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/331) | 
| 5FYFI | Security vulnerabilities of the kernel_linux_5.10 component: CVE-2022-26365, CVE-2022-33742, CVE-2022-33743, CVE-2022-33740, and CVE-2022-33741.| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/352) | 
| I5LUE0 | Security vulnerability of the third_party_zlib component: CVE-2022-37434.| [PR](https://gitee.com/openharmony/third_party_zlib/pulls/44) | 
| I5NCH4 | When **/bin/wms_server** is run over the serial port of the Hi3516 development board in the small system, the memory address and layout information are printed.| [PR](https://gitee.com/openharmony/distributedschedule_samgr_lite/pulls/1) | 
