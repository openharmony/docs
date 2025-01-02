# OpenHarmony 4.0.2 Release


## Version Overview

OpenHarmony 4.0.2 Release provides enhanced system security over OpenHarmony 4.0.1 Release by rectifying memory leak issues, certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.0.2 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.11.4 (API Version 10 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio| 4.0 Release | Recommended for developing OpenHarmony applications How to obtain:<br><br>SHA-256 checksum: 2c88cf43e1ef6ba722aac31eccc8ef92f07a9b72e43a9c1df127017828a22137<br><br>SHA-256 checksum: 25e491458eec50b4abddf5bed6aa85893801d70afbce02958f17bd904619405a<br><br>SHA-256 checksum: 284cb01f7b819e0da1d4fcacbbbbe8017ba220b5e3b9b1d5e4cc59ea30456acc |
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide#download).|


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

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.0.2Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/code-v4.0.2-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/code-v4.0.2-Release.tar.gz.sha256) | 30.5 GB |
| Hi3861 solution (binary)       | 4.0.2Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_pegasus.tar.gz.sha256) | 27.3 MB |
| Hi3516 solution-LiteOS (binary)| 4.0.2Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 302.5 MB |
| Hi3516 solution-Linux (binary) | 4.0.2Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_taurus_Linux.tar.gz.sha256) | 193.2 MB |
| RK3568 standard system solution (binary)       | 4.0.2Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/dayu200_standard_arm32.tar.gz.sha256) | 5.2 GB |
| Public SDK package for the standard system (macOS)            | 4.0.11.4  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/ohos-sdk-mac-public.tar.gz.sha256) | 2.0 GB |
| Public SDK package for the standard system (macOS-M1)            | 4.0.11.4 | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 800.7 MB |
| Public SDK package for the standard system (Windows/Linux)  | 4.0.11.4  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.1 GB |

## What's New

This version has the following updates to OpenHarmony 4.0.1 Release.


### API Changes

N/A


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

**Table 4** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [IA7RFU](https://e.gitee.com/open_harmony/issues/table?issue=IA7RFU) | [OpenHarmony 4.0.11.3] A C++ crash occurs on libhdf_host.z.so due to an error of the IPC_0_583 thread of the composer_host process. This issue occurs 263 times.|
| [IA50TF](https://e.gitee.com/open_harmony/issues/table?issue=IA50TF) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libdisplay_composer_vdi_impl.z.so due to an error of the IPC_0_600 thread of the composer_host process. This issue occurs 98 times.|
| [IA4VWD](https://e.gitee.com/open_harmony/issues/table?issue=IA4VWD) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libdisplay_composer_service_1.0.z.so due to an error of the IPC_0_651 thread of the composer_host process. This issue occurs 99 times.|
| [IA4VOG](https://e.gitee.com/open_harmony/issues/table?issue=IA4VOG) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libdisplay_composer_service_1.0.z.so due to an error of the IPC_0_611 thread of the composer_host process. This issue occurs 1207 times.|
| [I9UD63](https://e.gitee.com/open_harmony/issues/table?issue=I9UD63) | [OpenHarmony 4.0.11.1] App freezing occurs on getTimeDetailByCallTime of the com.ohos.contacts process. This issue occurs 11 times.|
| [I9D96I](https://e.gitee.com/open_harmony/issues/table?issue=I9D96I) | [OpenHarmony 4.0.10.18] The input method is not automatically displayed when a user touches the search box. |
| [I9BN09](https://e.gitee.com/open_harmony/issues/table?issue=I9BN09) | [OpenHarmony 4.0.10.18] App freezing occurs due to THREAD_BLOCK_6S in the com.ohos.photos process. This issue occurs 10 times.|
| [I97K8F](https://e.gitee.com/open_harmony/issues/table?issue=I97K8F) | [OpenHarmony 4.0.10.16] The LiteOS DSoftBus process cannot be started.   |
| [IA8XY1](https://e.gitee.com/open_harmony/issues/table?issue=IA8XY1) | [OpenHarmony 4.0.11.4] A JS crash occurs on isFolderMoveIn of the com.ohos.note process. This issue occurs once.|
| [IA8ORN](https://e.gitee.com/open_harmony/issues/table?issue=IA8ORN) | [OpenHarmony 4.0.11.4] A C++ crash occurs on libipc_core.z.so due to an error of the IPC_0_625 thread of the softbus_server process. This issue occurs 17 times.|
| [IA8HPZ](https://e.gitee.com/open_harmony/issues/table?issue=IA8HPZ) | [OpenHarmony 4.0.11.3] The WLAN status cannot be synchronized on the Settings screen after WLAN is enabled and disabled on the Settings screen.|
| [IA56NT](https://e.gitee.com/open_harmony/issues/table?issue=IA56NT) | [OpenHarmony 4.0.11.2] A JS crash occurs on unregisterObserver of the com.ohos.settings process. This issue occurs once.|
| [IA52Z3](https://e.gitee.com/open_harmony/issues/table?issue=IA52Z3) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libclang_rt.ubsan_minimal.so due to an error of the IPC_0_623 thread of the composer_host process. This issue occurs 5 times.|
| [IA52VP](https://e.gitee.com/open_harmony/issues/table?issue=IA52VP) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libdisplay_composer_stub_1.0.z.so due to an error of the IPC_0_610 thread of the composer_host process. This issue occurs 22 times.|
| [IA52OZ](https://e.gitee.com/open_harmony/issues/table?issue=IA52OZ) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libdisplay_composer_vdi_impl.z.so due to an error of the OS_IPC_1_635 thread of the composer_host process. This issue occurs twice.|
| [IA52FF](https://e.gitee.com/open_harmony/issues/table?issue=IA52FF) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libdisplay_composer_vendor.z.so due to an error of the IPC_1_613 thread of the composer_host process. This issue occurs once.|
| [IA5292](https://e.gitee.com/open_harmony/issues/table?issue=IA5292) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libhdf_ipc_adapter.z.so due to an error of the IPC_0_628 thread of the composer_host process. This issue occurs 45 times.|
| [IA521D](https://e.gitee.com/open_harmony/issues/table?issue=IA521D) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libhilog.so due to an error of the IPC_1_588 thread of the composer_host process. This issue occurs 13 times.|
| [IA51QG](https://e.gitee.com/open_harmony/issues/table?issue=IA51QG) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libipc_single.z.so due to an error of the IPC_1_592 thread of the composer_host process. This issue occurs 3 times.|
| [IA51KP](https://e.gitee.com/open_harmony/issues/table?issue=IA51KP) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libnative_rdb.z.so due to an error of the os.settingsdata thread of the com.ohos.settingsdata process.|
| [IA51AZ](https://e.gitee.com/open_harmony/issues/table?issue=IA51AZ) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libdisplay_composer_vdi_impl.z.so due to an error of the OS_IPC_1_626 thread of the composer_host process. This issue occurs 11 times.|
| [IA513N](https://e.gitee.com/open_harmony/issues/table?issue=IA513N) | [OpenHarmony 4.0.11.2] A C++ crash occurs on libnative_appdatafwk.z.so due to an error of the os.settingsdata thread of the com.ohos.settingsdata process. This issue occurs 18 times.|
| [I9UF1I](https://e.gitee.com/open_harmony/issues/table?issue=I9UF1I) | [OpenHarmony 4.0.11.1] A C++ crash occurs on libhdifd_parcelable.z.so due to an error of the IPC_1_625 thread of the composer_host process.|
| [I9UESA](https://e.gitee.com/open_harmony/issues/table?issue=I9UESA) | [OpenHarmony 4.0.11.1] A C++ crash occurs on libdlp_permission_sdk.z.so due to an error of the ffrtwk/CPU-2-0 thread of the foundation process. This issue occurs once.|
| [I9TPH7](https://e.gitee.com/open_harmony/issues/table?issue=I9TPH7) | [OpenHarmony 4.0.11.1] A JS crash occurs on updateActionBar of the com.ohos.photos process. This issue occurs once.|
| [I9TNOU](https://e.gitee.com/open_harmony/issues/table?issue=I9TNOU) | [OpenHarmony 4.0.11.1] The inForm parameter of the hap-sign-tool.jar tool is case insensitive.|
| [I9PITC](https://e.gitee.com/open_harmony/issues/table?issue=I9PITC) | [OpenHarmony 4.0.10.18] When the indentation of the text in a memo is adjusted, saved, and the application is closed, the text appears without indentation upon reopening.|
| [I9K8ZD](https://e.gitee.com/open_harmony/issues/table?issue=I9K8ZD) | [OpenHarmony 4.0.10.18] A C++ crash occurs on libdevicemanagerserviceimpl.z.so due to an error of the TimerRunning thread of the device_manager process. This issue occurs once.|
| [I96SJG](https://e.gitee.com/open_harmony/issues/table?issue=I96SJG) | [OpenHarmony 4.0.10.17] A JS crash occurs on unregisterObserver of the com.ohos.settings process. This issue occurs once.|
| [I920DA](https://e.gitee.com/open_harmony/issues/table?issue=I920DA) | [OpenHarmony 4.0.10.16] A JS crash occurs on AirplaneVM of the com.ohos.systemui process. This issue occurs once.|

## Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.                                                       | Description                                          |
| ------------------------------------------------------------ | -------------------------------------------------- |
| [IA9LC2](https://e.gitee.com/open_harmony/issues/table?issue=IA9LC2) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36939|
| [I9PJJN](https://e.gitee.com/open_harmony/issues/table?issue=I9PJJN) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26733|
| [I9QZR5](https://e.gitee.com/open_harmony/issues/table?issue=I9QZR5) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-27004|
| [I9QZC7](https://e.gitee.com/open_harmony/issues/table?issue=I9QZC7) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52467|
| [I9QZB8](https://e.gitee.com/open_harmony/issues/table?issue=I9QZB8) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26903|
| [I9QZ9J](https://e.gitee.com/open_harmony/issues/table?issue=I9QZ9J) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-27399|
| [I9QW5Y](https://e.gitee.com/open_harmony/issues/table?issue=I9QW5Y) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-51794 |
| [I9QW30](https://e.gitee.com/open_harmony/issues/table?issue=I9QW30) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2017-14058|
| [I9Q65G](https://e.gitee.com/open_harmony/issues/table?issue=I9Q65G) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-51793|
| [I9Q1NE](https://e.gitee.com/open_harmony/issues/table?issue=I9Q1NE) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26862|
| [I9Q1MT](https://e.gitee.com/open_harmony/issues/table?issue=I9Q1MT) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52462|
| [I9OGPC](https://e.gitee.com/open_harmony/issues/table?issue=I9OGPC) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-24863|
| [I9OEZF](https://e.gitee.com/open_harmony/issues/table?issue=I9OEZF) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-46887|
| [I9NQVB](https://e.gitee.com/open_harmony/issues/table?issue=I9NQVB) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26601|
| [I9JE1E](https://e.gitee.com/open_harmony/issues/table?issue=I9JE1E) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2022-2078 |
| [I9JDLS](https://e.gitee.com/open_harmony/issues/table?issue=I9JDLS) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2021-4001 |
| [I9H4QZ](https://e.gitee.com/open_harmony/issues/table?issue=I9H4QZ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-0450 |
| [I9FXHF](https://e.gitee.com/open_harmony/issues/table?issue=I9FXHF) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52160|
| [I9COE3](https://e.gitee.com/open_harmony/issues/table?issue=I9COE3) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52498|
| [I9BU69](https://e.gitee.com/open_harmony/issues/table?issue=I9BU69) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-25739|
| [I952TO](https://e.gitee.com/open_harmony/issues/table?issue=I952TO) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-24858|
| [I950WP](https://e.gitee.com/open_harmony/issues/table?issue=I950WP) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-24857|
| [IA7RSP](https://e.gitee.com/open_harmony/issues/table?issue=IA7RSP) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2021-47469|
| [IA7RR1](https://e.gitee.com/open_harmony/issues/table?issue=IA7RR1) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52835|
| [IA7RQS](https://e.gitee.com/open_harmony/issues/table?issue=IA7RQS) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52879|
| [IA7RQM](https://e.gitee.com/open_harmony/issues/table?issue=IA7RQM) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52868|
| [IA7RQC](https://e.gitee.com/open_harmony/issues/table?issue=IA7RQC) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52739|
| [IA7ROX](https://e.gitee.com/open_harmony/issues/table?issue=IA7ROX) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52869|
| [IA7AZ7](https://e.gitee.com/open_harmony/issues/table?issue=IA7AZ7) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35896|
| [IA7AVQ](https://e.gitee.com/open_harmony/issues/table?issue=IA7AVQ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52781|
| [IA7AUA](https://e.gitee.com/open_harmony/issues/table?issue=IA7AUA) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52832|
| [IA7A6Q](https://e.gitee.com/open_harmony/issues/table?issue=IA7A6Q) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36017|
| [IA7A60](https://e.gitee.com/open_harmony/issues/table?issue=IA7A60) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35822|
| [IA74VS](https://e.gitee.com/open_harmony/issues/table?issue=IA74VS) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52881 |
| [IA74RP](https://e.gitee.com/open_harmony/issues/table?issue=IA74RP) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36883|
| [IA49BH](https://e.gitee.com/open_harmony/issues/table?issue=IA49BH) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-39375|
| [I9UNOT](https://e.gitee.com/open_harmony/issues/table?issue=I9UNOT) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-4906 |
| [I9QZQO](https://e.gitee.com/open_harmony/issues/table?issue=I9QZQO) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-27038|
| [I9QZQB](https://e.gitee.com/open_harmony/issues/table?issue=I9QZQB) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26801|
| [I9QZCJ](https://e.gitee.com/open_harmony/issues/table?issue=I9QZCJ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26923|
| [I9PJK7](https://e.gitee.com/open_harmony/issues/table?issue=I9PJK7) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26735|
| [I9PJJT](https://e.gitee.com/open_harmony/issues/table?issue=I9PJJT) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26805|
| [IA4BSA](https://e.gitee.com/open_harmony/issues/table?issue=IA4BSA) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36899|
| [IA47RY](https://e.gitee.com/open_harmony/issues/table?issue=IA47RY) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36904|
| [I9TCEQ](https://e.gitee.com/open_harmony/issues/table?issue=I9TCEQ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26934|
| [I9TCE6](https://e.gitee.com/open_harmony/issues/table?issue=I9TCE6) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2021-47479 |
| [I9TCBI](https://e.gitee.com/open_harmony/issues/table?issue=I9TCBI) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2021-47506|
| [I9TCAM](https://e.gitee.com/open_harmony/issues/table?issue=I9TCAM) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2021-47485|
| [I9TC9P](https://e.gitee.com/open_harmony/issues/table?issue=I9TC9P) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2021-47483|
| [I9TC7F](https://e.gitee.com/open_harmony/issues/table?issue=I9TC7F) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2021-47474|
| [I9OU4P](https://e.gitee.com/open_harmony/issues/table?issue=I9OU4P) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26885|
| [I9OU4C](https://e.gitee.com/open_harmony/issues/table?issue=I9OU4C) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26883|
| [I9OU42](https://e.gitee.com/open_harmony/issues/table?issue=I9OU42) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26884|
| [I9OU3J](https://e.gitee.com/open_harmony/issues/table?issue=I9OU3J) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2022-48655|
| [I9O3RW](https://e.gitee.com/open_harmony/issues/table?issue=I9O3RW) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-31578|
| [I9JNCO](https://e.gitee.com/open_harmony/issues/table?issue=I9JNCO) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52436|
| [I9H4LS](https://e.gitee.com/open_harmony/issues/table?issue=I9H4LS) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-6597 |
| [IA7RS0](https://e.gitee.com/open_harmony/issues/table?issue=IA7RS0) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36929|
| [IA7RRT](https://e.gitee.com/open_harmony/issues/table?issue=IA7RRT) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36941|
| [IA7RPQ](https://e.gitee.com/open_harmony/issues/table?issue=IA7RPQ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35984 |
| [IA7RPD](https://e.gitee.com/open_harmony/issues/table?issue=IA7RPD) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52730|
| [IA7ROQ](https://e.gitee.com/open_harmony/issues/table?issue=IA7ROQ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36008|
| [IA7RO9](https://e.gitee.com/open_harmony/issues/table?issue=IA7RO9) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35997|
| [IA7BIZ](https://e.gitee.com/open_harmony/issues/table?issue=IA7BIZ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36901|
| [IA7B91](https://e.gitee.com/open_harmony/issues/table?issue=IA7B91) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36903|
| [IA7B81](https://e.gitee.com/open_harmony/issues/table?issue=IA7B81) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35904|
| [IA7B1I](https://e.gitee.com/open_harmony/issues/table?issue=IA7B1I) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-27414|
| [IA7B0N](https://e.gitee.com/open_harmony/issues/table?issue=IA7B0N) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35955|
| [IA7AY5](https://e.gitee.com/open_harmony/issues/table?issue=IA7AY5) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35969|
| [IA7AXC](https://e.gitee.com/open_harmony/issues/table?issue=IA7AXC) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35962|
| [IA7AV3](https://e.gitee.com/open_harmony/issues/table?issue=IA7AV3) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35789|
| [IA7AT2](https://e.gitee.com/open_harmony/issues/table?issue=IA7AT2) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36940|
| [IA7A45](https://e.gitee.com/open_harmony/issues/table?issue=IA7A45) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52803|
| [IA7A3F](https://e.gitee.com/open_harmony/issues/table?issue=IA7A3F) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52791|
| [IA74SA](https://e.gitee.com/open_harmony/issues/table?issue=IA74SA) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36938|
| [IA74RC](https://e.gitee.com/open_harmony/issues/table?issue=IA74RC) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36905|
| [IA74QZ](https://e.gitee.com/open_harmony/issues/table?issue=IA74QZ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36902|
| [IA6W5Z](https://e.gitee.com/open_harmony/issues/table?issue=IA6W5Z) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-48514|
| [I9RKKZ](https://e.gitee.com/open_harmony/issues/table?issue=I9RKKZ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-31755|
| [I9QZSH](https://e.gitee.com/open_harmony/issues/table?issue=I9QZSH) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26852|
| [I9QZS8](https://e.gitee.com/open_harmony/issues/table?issue=I9QZS8) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26901|

## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| /     | /        | /    | /            |

 <!--no_check--> 