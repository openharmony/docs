# OpenHarmony 4.0.3 Release


## Version Description

OpenHarmony 4.0.3 Release provides enhanced system security over OpenHarmony 4.0.2 Release by rectifying certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues.


## Mapping relationship

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.0.3 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.12.4 (API Version 10 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.0.3 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/code-v4.0.3-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/code-v4.0.3-Release.tar.gz.sha256) | 31.5 GB |
| Hi3861 solution (binary)       | 4.0.3 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_pegasus.tar.gz.sha256) | 25.2 MB |
| Hi3516 solution-LiteOS (binary)| 4.0.3 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 304.1 MB |
| Hi3516 solution-Linux (binary) | 4.0.3 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_taurus_Linux.tar.gz.sha256) | 195.4 MB |
| RK3568 standard system solution (binary)       | 4.0.3 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/dayu200_standard_arm32.tar.gz.sha256) | 5.2 GB |
| Public SDK package for the standard system (macOS)            | 4.0.12.4 | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.1 GB |
| Public SDK package for the standard system (macOS-M1)            | 4.0.12.4 | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 800.7 MB |
| Public SDK package for the standard system (Windows\Linux)  | 4.0.12.4 | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.0 GB |

## Description

This version has the following updates to OpenHarmony 4.0.2 Release.


### API Changes

N/A


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [I9TEYD](https://e.gitee.com/open_harmony/issues/list?issue=I9TEYD) | Failed to compile the light kernel container test version.          |
| [IAJDXD](https://e.gitee.com/open_harmony/issues/list?issue=IAJDXD) | The IPC_3_1346 thread in the composer_host process has encountered a C++ crash twice, and the crash stack involves the library libdisplay_composer_vdi_impl.z.so.|
| [IA7R8Z](https://e.gitee.com/open_harmony/issues/list?issue=IA7R8Z) | The sensor_host thread in the sensor_host process has encountered a C++ crash once, and the crash stack involves the library libhdf_utils.z.so.|
| [I9UEWK](https://e.gitee.com/open_harmony/issues/list?issue=I9UEWK) | The audio_host thread in the audio_host process has encountered a C++ crash five times, and the crash stack involves the library libhdi_audio_pnp_server.z.so.|
| [I97YSN](https://e.gitee.com/open_harmony/issues/list?issue=I97YSN) | The **onStateChange** callback does not take effect when **NavRouter** redirects to or exits a page.|
| [I93ZB9](https://e.gitee.com/open_harmony/issues/list?issue=I93ZB9) | During the installation, sys_installer crashes and fails to throw an installation timeout, and the page is suspended.|
| [I9EWLM](https://e.gitee.com/open_harmony/issues/list?issue=I9EWLM) | When the text entered in the search field exceeds the allotted space, it will cover the clear (X) icon on the extreme right.                |
| [I9F3MR](https://e.gitee.com/open_harmony/issues/list?issue=I9F3MR) | If you create a message and then delete the contact, the message content in the editing area below is deleted.    |
| [I9FQD5](https://e.gitee.com/open_harmony/issues/list?issue=I9FQD5) | When the global animation is changed to 5X or 10X, the status bar in the download dialog box automatically exits.         |
| [I9GRCL](https://e.gitee.com/open_harmony/issues/list?issue=I9GRCL) | When a user slides to the top of the SMS chat screen and receives a message from the peer device, the SMS chat screen does not automatically slide back to the latest message.|
| [IAIKP6](https://e.gitee.com/open_harmony/issues/list?issue=IAIKP6) | The links in the Picker application of **FileShare**, **fileFs.ts**, and **show.ets** are invalid.          |
| [IAFCN5](https://e.gitee.com/open_harmony/issues/list?issue=IAFCN5) | 4.0 Release UT failure.                                       |
| [IAF9R7](https://e.gitee.com/open_harmony/issues/list?issue=IAF9R7) | 4.0 Release TDD.                                      |
| [IADVF8](https://e.gitee.com/open_harmony/issues/list?issue=IADVF8) | After turning on the Wi-Fi toggle in Control Panel, the **Settings** page shows a successful Wi-Fi connection, but Control Panel temporarily does not display the connected Wi-Fi network.|
| [IACY4V](https://e.gitee.com/open_harmony/issues/list?issue=IACY4V) | hmdfs fix skip tls init                                      |

## Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.                                                       | Description                                                   |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [IAI3SL](https://e.gitee.com/open_harmony/issues/list?issue=IAI3SL) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36031        |
| [IAI3YH](https://e.gitee.com/open_harmony/issues/list?issue=IAI3YH) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42161        |
| [IAI3XW](https://e.gitee.com/open_harmony/issues/list?issue=IAI3XW) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42154        |
| [IAI3VQ](https://e.gitee.com/open_harmony/issues/list?issue=IAI3VQ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-41012        |
| [IAI3VA](https://e.gitee.com/open_harmony/issues/list?issue=IAI3VA) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-41087        |
| [IAI3TH](https://e.gitee.com/open_harmony/issues/list?issue=IAI3TH) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42160        |
| [IAI3SZ](https://e.gitee.com/open_harmony/issues/list?issue=IAI3SZ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52672        |
| [IAEK1H](https://e.gitee.com/open_harmony/issues/list?issue=IAEK1H) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-39495        |
| [IAI3SZ](https://e.gitee.com/open_harmony/issues/list?issue=IAI3SZ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52672        |
| [IAEK1H](https://e.gitee.com/open_harmony/issues/list?issue=IAEK1H) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-39495        |
| [IABPBB](https://e.gitee.com/open_harmony/issues/list?issue=IABPBB) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36971        |
| [IAAC06](https://e.gitee.com/open_harmony/issues/list?issue=IAAC06) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-38577        |
| [IAABZS](https://e.gitee.com/open_harmony/issues/list?issue=IAABZS) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-38588        |
| [IALLOV](https://e.gitee.com/open_harmony/issues/list?issue=IALLOV) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-825178265344806912|
| [IALD0O](https://e.gitee.com/open_harmony/issues/list?issue=IALD0O) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-826547532216668160|
| [IAKL82](https://e.gitee.com/open_harmony/issues/list?issue=IAKL82) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26984         |
| [IAJW6P](https://e.gitee.com/open_harmony/issues/list?issue=IAJW6P) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-41035         |
| [IAJW65](https://e.gitee.com/open_harmony/issues/list?issue=IAJW65) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-41072         |
| [IAJW5Y](https://e.gitee.com/open_harmony/issues/list?issue=IAJW5Y) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-41063         |
| [IAJW5T](https://e.gitee.com/open_harmony/issues/list?issue=IAJW5T) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35947         |
| [IAJW5L](https://e.gitee.com/open_harmony/issues/list?issue=IAJW5L) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42115         |
| [IAJW4P](https://e.gitee.com/open_harmony/issues/list?issue=IAJW4P) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42084         |
| [IAJW4H](https://e.gitee.com/open_harmony/issues/list?issue=IAJW4H) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42082         |
| [IAJW3M](https://e.gitee.com/open_harmony/issues/list?issue=IAJW3M) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35884         |
| [IAJW2W](https://e.gitee.com/open_harmony/issues/list?issue=IAJW2W) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-41020         |
| [IAIRKT](https://e.gitee.com/open_harmony/issues/list?issue=IAIRKT) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-26966         |
| [IAIKJM](https://e.gitee.com/open_harmony/issues/list?issue=IAIKJM) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42084         |
| [IAI79Y](https://e.gitee.com/open_harmony/issues/list?issue=IAI79Y) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42068        |
| [IAI79K](https://e.gitee.com/open_harmony/issues/list?issue=IAI79K) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42229         |
| [IAI795](https://e.gitee.com/open_harmony/issues/list?issue=IAI795) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42226        |
| [IAI3WS](https://e.gitee.com/open_harmony/issues/list?issue=IAI3WS) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-39501        |
| [IAI3W8](https://e.gitee.com/open_harmony/issues/list?issue=IAI3W8) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-40959        |
| [IAI3VH](https://e.gitee.com/open_harmony/issues/list?issue=IAI3VH) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-40960         |
| [IAI3UT](https://e.gitee.com/open_harmony/issues/list?issue=IAI3UT) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2022-48797         |
| [IAI3UM](https://e.gitee.com/open_harmony/issues/list?issue=IAI3UM) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-40961         |
| [IAI3TM](https://e.gitee.com/open_harmony/issues/list?issue=IAI3TM) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-40905         |
| [IAHRT0](https://e.gitee.com/open_harmony/issues/list?issue=IAHRT0) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-40912         |
| [IAFG57](https://e.gitee.com/open_harmony/issues/list?issue=IAFG57) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36286         |
| [IAFG4Y](https://e.gitee.com/open_harmony/issues/list?issue=IAFG4Y) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-38780         |
| [IAFG4I](https://e.gitee.com/open_harmony/issues/list?issue=IAFG4I) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36270         |
| [IAE0GE](https://e.gitee.com/open_harmony/issues/list?issue=IAE0GE) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-39475         |
| [IAE0G7](https://e.gitee.com/open_harmony/issues/list?issue=IAE0G7) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2021-47582         |
| [IAE0G0](https://e.gitee.com/open_harmony/issues/list?issue=IAE0G0) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-39472         |
| [IAE0FT](https://e.gitee.com/open_harmony/issues/list?issue=IAE0FT) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-34027         |
| [IAE0FI](https://e.gitee.com/open_harmony/issues/list?issue=IAE0FI) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36489         |
| [IABPAU](https://e.gitee.com/open_harmony/issues/list?issue=IABPAU) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-38596         |
| [IABPAG](https://e.gitee.com/open_harmony/issues/list?issue=IABPAG) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-38601         |
| [IAAC00](https://e.gitee.com/open_harmony/issues/list?issue=IAAC00) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-38564         |
| [IAA6AF](https://e.gitee.com/open_harmony/issues/list?issue=IAA6AF) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-39276         |
| [IA7RS0](https://e.gitee.com/open_harmony/issues/list?issue=IA7RS0) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36929         |
| [IA7RRT](https://e.gitee.com/open_harmony/issues/list?issue=IA7RRT) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36941         |
| [IA7RPQ](https://e.gitee.com/open_harmony/issues/list?issue=IA7RPQ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-35984         |
| [IA7RPD](https://e.gitee.com/open_harmony/issues/list?issue=IA7RPD) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52730         |
| [IA7A3F](https://e.gitee.com/open_harmony/issues/list?issue=IA7A3F) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52791         |
| [IA74SA](https://e.gitee.com/open_harmony/issues/list?issue=IA74SA) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36938         |
| [IA74RC](https://e.gitee.com/open_harmony/issues/list?issue=IA74RC) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36905         |
| [IA74QZ](https://e.gitee.com/open_harmony/issues/list?issue=IA74QZ) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36902         |
| [IAJW57](https://e.gitee.com/open_harmony/issues/list?issue=IAJW57) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-42236         |
| [IAJW4Y](https://e.gitee.com/open_harmony/issues/list?issue=IAJW4Y) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-41041         |
| [IAI3X0](https://e.gitee.com/open_harmony/issues/list?issue=IAI3X0) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-40942         |
| [IAI3WV](https://e.gitee.com/open_harmony/issues/list?issue=IAI3WV) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-40971         |
| [IAI3WK](https://e.gitee.com/open_harmony/issues/list?issue=IAI3WK) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-39509         |
| [IAHRH2](https://e.gitee.com/open_harmony/issues/list?issue=IAHRH2) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-38615         |
| [IA7RR1](https://e.gitee.com/open_harmony/issues/list?issue=IA7RR1) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52835         |
| [IA7RQC](https://e.gitee.com/open_harmony/issues/list?issue=IA7RQC) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52739         |
| [IA74VS](https://e.gitee.com/open_harmony/issues/list?issue=IA74VS) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2023-52881         |
| [IA74RP](https://e.gitee.com/open_harmony/issues/list?issue=IA74RP) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2024-36883        |
| [IAHB13](https://e.gitee.com/open_harmony/issues/list?issue=IAHB13) | [Vulnerability] [OpenHarmony 4.0 Release] CVE-2022-48805         |

## Unfixed Vulnerabilities

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| /     | /        | /    | /            |

 <!--no_check--> 