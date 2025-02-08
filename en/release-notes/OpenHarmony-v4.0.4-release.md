# OpenHarmony 4.0.4 Release


## Version Description

OpenHarmony 4.0.4 Release provides enhanced system security over OpenHarmony 4.0.3 Release by rectifying certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.0.4 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.13.5 (API Version 10 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0.4-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0.4-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0.4-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0.4-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.0.4Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/code-v4.0.4-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/code-v4.0.4-Release.tar.gz.sha256) | 32.7 GB |
| Hi3861 solution (binary)       | 4.0.4Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_pegasus.tar.gz.sha256) | 25.2 MB |
| Hi3516 solution-LiteOS (binary)| 4.0.4Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 304.1 MB |
| Hi3516 solution-Linux (binary) | 4.0.4Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_taurus_Linux.tar.gz.sha256) | 195.9 MB |
| RK3568 standard system solution (binary)       | 4.0.4Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/dayu200_standard_arm32.tar.gz.sha256) | 5.2 GB |
| Public SDK package for the standard system (macOS)            | 4.0.13.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/ohos-sdk-mac-public.tar.gz.sha256) | 844.9 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.0.13.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 797.3 MB |
| Public SDK package for the standard system (Windows/Linux)  | 4.0.13.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.0 GB |

## What's New

This version has the following updates to OpenHarmony 4.0.3 Release.


### Change APIs

- N/A


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Issue Description |
| -------- | -------- |
| [IATPGT](https://e.gitee.com/open_harmony/issues/list?issue=IATPGT) | Six test cases fail when the ActsRequestAuthorityTest suite is executed by acts.           |
| [IAWMVO](https://e.gitee.com/open_harmony/issues/list?issue=IAWMVO) | During the pressure test, the process com.ohos.note experiences 2 JS crash incidents, identified by the stack name isFolderMoveIn. |
| [IAHYHO](https://e.gitee.com/open_harmony/issues/list?issue=IAHYHO) | When users manually select and attempt to delete images from various date categories on the photo page, deletion is only successful for images from the earliest selected date category.|
| [IA4OYK](https://e.gitee.com/open_harmony/issues/list?issue=IA4OYK) | [Reboot] During the pressure test, the render_service thread in the /system/bin/render_service process encounters a C++ crash, with the crash stack librender_service.z.so.|
| [I9AS1J](https://e.gitee.com/open_harmony/issues/list?issue=I9AS1J) | For the **Swiper** component, specifying the arrow size as "100abcd" incorrectly results in an arrow size display of 100 vp.|
| [IAYMZ8](https://gitee.com/openharmony/applications_hap/issues/IAYMZ8?from=project-issue) | JS crash issue in the Notepad application.|
| [IARU3T](https://gitee.com/openharmony/kernel_linux_5.10/issues/IARU3T?from=project-issue) | The command parameter is incorrectly passed during cross-device access to HMDFS.|
| [IATWYZ](https://gitee.com/openharmony/startup_init/issues/IATWYZ?from=project-issue) | Security issues for the init process in OpenHarmony 4.0 Release .|
| [IATKYS](https://gitee.com/openharmony/developtools_profiler/issues/IATKYS?from=project-issue) | Alarms in the host directory of OpenHarmony 4.0 Release.|
| [I9BPOQ](https://gitee.com/openharmony/third_party_musl/issues/I9BPOQ?from=project-issue) | When the **dlopen_impl** function processes missing dependencies, an exception occurs when the .so file is unloaded, leading to a use-after-free (UAF) vulnerability in OpenHarmony 4.0 Release.|
| [IAREWW](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAREWW?from=project-issue) | The patch for CVE-2024-26686 led to the failure of the **top** command.|
| [IAQYHH](https://gitee.com/openharmony/communication_ipc/issues/IAQYHH?from=project-issue) | Anonymization processing for deviceId.|
| [IAPABG](https://gitee.com/openharmony/filemanagement_dfs_service/issues/IAPABG?from=project-issue) | Logs contain user information.|
| [IAMISK](https://gitee.com/openharmony/napi_generator/issues/IAMISK?from=project-issue) | Static warnings of the napi_generator repository in OpenHarmony 4.0 Release.|
| [IAP63C](https://gitee.com/openharmony/arkui_ace_engine/issues/IAP63C?from=project-issue) | There are errors in loading files from absolute paths for plugins.|
| [IANK71](https://gitee.com/openharmony/applications_hap/issues/IANK71?from=project-issue) | Abnormal deletions in the Gallery HAP archiving process.|
| [IALIBN](https://gitee.com/openharmony/xts_hats/issues/IALIBN?from=project-issue) | Defective logic for the test cases of the xts_hats/hdf/INPUT module.|
| [IALKY4](https://gitee.com/openharmony/drivers_peripheral/issues/IALKY4?from=project-issue) | Security compilation option SP for audio_manager_service in OpenHarmony 4.0 Release.|

## Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.                                                    | Issue Description                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [IAW2QM](https://e.gitee.com/open_harmony/issues/list?issue=IAW2QM) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-45492 in the openeuler:expat component |
| [IAW2QF](https://e.gitee.com/open_harmony/issues/list?issue=IAW2QF) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-45491 in the openeuler:expat component |
| [IAW2QE](https://e.gitee.com/open_harmony/issues/list?issue=IAW2QE) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-45490 in the openeuler:expat component |
| [IAX807](https://e.gitee.com/open_harmony/issues/list?issue=IAX807) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-41049     |
| [IAVP6R](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6R) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-8636 in the chromium component |
| [IAVP6O](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6O) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-7971 in the chromium component |
| [IAVP6M](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6M) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-7535 in the chromium component |
| [IAVP6K](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6K) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-7255 in the chromium component |
| [IAVLNU](https://e.gitee.com/open_harmony/issues/list?issue=IAVLNU) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-5290 in the wpa supplicant component |
| [IAQ16Z](https://e.gitee.com/open_harmony/issues/list?issue=IAQ16Z) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-44987     |
| [IAQ15F](https://e.gitee.com/open_harmony/issues/list?issue=IAQ15F) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-43882     |
| [IAO0XJ](https://e.gitee.com/open_harmony/issues/list?issue=IAO0XJ) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-42305     |
| [IAX89Y](https://e.gitee.com/open_harmony/issues/list?issue=IAX89Y) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-42131     |
| [IAX7YW](https://e.gitee.com/open_harmony/issues/list?issue=IAX7YW) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-26720     |
| [IAX7XZ](https://e.gitee.com/open_harmony/issues/list?issue=IAX7XZ) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-27043     |
| [IAX7X1](https://e.gitee.com/open_harmony/issues/list?issue=IAX7X1) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-26684     |
| [IAX7V8](https://e.gitee.com/open_harmony/issues/list?issue=IAX7V8) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-26627     |
| [IAX7QW](https://e.gitee.com/open_harmony/issues/list?issue=IAX7QW) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-46679     |
| [IAVP6Q](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6Q) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-8035 in the chromium component |
| [IAVN2E](https://e.gitee.com/open_harmony/issues/list?issue=IAVN2E) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-46713     |
| [IAUE85](https://e.gitee.com/open_harmony/issues/list?issue=IAUE85) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-45028     |
| [IASJLL](https://e.gitee.com/open_harmony/issues/list?issue=IASJLL) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-832718370087374848 |
| [IAQJNR](https://e.gitee.com/open_harmony/issues/list?issue=IAQJNR) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-45006     |
| [IAQJHL](https://e.gitee.com/open_harmony/issues/list?issue=IAQJHL) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-42276     |
| [IAQ18I](https://e.gitee.com/open_harmony/issues/list?issue=IAQ18I) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-43892     |
| [IAQ16G](https://e.gitee.com/open_harmony/issues/list?issue=IAQ16G) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2022-48877     |
| [IAQ158](https://e.gitee.com/open_harmony/issues/list?issue=IAQ158) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-43871     |
| [IAQ14R](https://e.gitee.com/open_harmony/issues/list?issue=IAQ14R) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-43884     |
| [IAQ12T](https://e.gitee.com/open_harmony/issues/list?issue=IAQ12T) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-43856     |
| [IAQ12G](https://e.gitee.com/open_harmony/issues/list?issue=IAQ12G) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-43828     |
| [IAO0YL](https://e.gitee.com/open_harmony/issues/list?issue=IAO0YL) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-43853     |
| [IAJW36](https://e.gitee.com/open_harmony/issues/list?issue=IAJW36) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-2024-41098     |
| [IAXDG6](https://e.gitee.com/open_harmony/issues/list?issue=IAXDG6) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-844296718181732352 |
| [IAWOD6](https://e.gitee.com/open_harmony/issues/list?issue=IAWOD6) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-844409455574519808 |
| [IAUKDD](https://e.gitee.com/open_harmony/issues/list?issue=IAUKDD) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-840681230440599552 |
| [IAUJWI](https://e.gitee.com/open_harmony/issues/list?issue=IAUJWI) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-840680534400045056 |
| [IAT99G](https://e.gitee.com/open_harmony/issues/list?issue=IAT99G) | [Vulnerability] [OpenHarmony-4.0-Release] CVE-836801068271669248 |

## Known Issues

**Table 5** Known issues

| Issue No.| Issue Description | Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| /     | /        | /    | /            |
