# OpenHarmony 3.1.2 Release


## Version Description

OpenHarmony 3.1.2 Release provides the following enhancements over OpenHarmony 3.1.1 Release:

Rectified the execution failure of ACTS test cases on certain subsystems, and supplemented ACTS test cases for certain subsystems.

Fixed known vulnerabilities in third-party components such as Linux kernel, OpenSSL, curl, and node.

Fixed certain known defects in system applications, such as Notepad, Settings, and Notification Panel.

Fixed known SDK defects, and released the latest SDK version.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.1.2 Release| N/A|
| Full SDK | Ohos_sdk_full 3.1.7.7 (API Version 8 Relese)<br>Ohos_sdk_full 3.1.7.5 (API Version 8 Relese) | This toolkit is intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.<br>To use the full SDK, manually obtain it from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../application-dev/faqs/full-sdk-switch-guide.md).|
| Public SDK | Ohos_sdk_public&nbsp;3.1.7.7&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release)<br>Ohos_sdk_public 3.1.7.5 (API Version 8 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio 3.0 Beta4 or later.|
| (Optional) HUAWEI DevEco Studio| 3.0 Beta4 for OpenHarmony | Recommended for developing OpenHarmony applications.|
| (Optional) HUAWEI DevEco Device Tool| 3.0 Release | Recommended for developing OpenHarmony devices.|


## Source Code Acquisition


### Prerequisites

1. Register your account with Gitee.

2. Register an SSH public key for access to Gitee.

3. Install the [Git client](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) and [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading), and configure basic user information.
   
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.2-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.2-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.1.2 Release | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/code-v3.1.2-Release.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/code-v3.1.2-Release.tar.gz.sha256)|
| Hi3516 standard system solution (binary)| 3.1.2 Release | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/standard_hi3516.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/standard_hi3516.tar.gz.sha256)|
| RK3568 standard system solution (binary)| 3.1.2 Release | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/standard_rk3568.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/standard_rk3568.tar.gz.sha256)|
| Hi3861 mini system solution (binary)| 3.1.2 Release | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_pegasus.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_pegasus.tar.gz.sha256)|
| Hi3516 small system solution - LiteOS (binary)| 3.1.2 Release | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_taurus.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_taurus.tar.gz.sha256)|
| Hi3516 small system solution - Linux (binary)| 3.1.2 Release | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_taurus_linux.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_taurus_linux.tar.gz.sha256)|
| Full SDK package for the standard system (macOS)| 3.1.7.5 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-mac-full.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-mac-full.tar.gz.sha256)|
| Full SDK package for the standard system (Windows/Linux)| 3.1.7.5 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-full.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-full.tar.gz.sha256)|
| Public SDK package for the standard system (macOS)| 3.1.7.5 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-mac-public.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-mac-public.tar.gz.sha256)|
| Public SDK package for the standard system (Windows/Linux)| 3.1.7.5 | [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-public.tar.gz)| [Download](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-public.tar.gz.sha256)|
| Full SDK package for the standard system (macOS)| 3.1.7.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-mac-full.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-mac-full.tar.gz.sha256)|
| Full SDK package for the standard system (Windows/Linux)| 3.1.7.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-full.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-full.tar.gz.sha256)|
| Public SDK package for the standard system (macOS)| 3.1.7.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-mac-public.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-mac-public.tar.gz.sha256)|
| Public SDK package for the standard system (Windows/Linux)| 3.1.7.7 | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-public.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-public.tar.gz.sha256)|


## What's New

This version has the following updates to OpenHarmony 3.1.1 Release.


### Feature Updates

There are no new features or changes in this version.

API Updates


This version does not involve API updates.



### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

**Table 3** Resolved issues

| Subsystem| Description|
| -------- | -------- |
| ACTS subsystem| - One test case of the ActsFeatureAbilityTest module fails to run. ([I5G8Q5](https://gitee.com/openharmony/xts_acts/issues/I5G8Q5))<br>- The **target** parameter in the USB SDK is not covered. ([I5FU0F](https://gitee.com/openharmony/xts_acts/issues/I5FU0F))<br>- Test cases in **graphic/webGL/src/main/js/default/test** are not covered. ([I5FMJJ](https://gitee.com/openharmony/xts_acts/issues/I5FMJJ))<br>- Twenty-two test cases of the ActsFeatureAbilityTest module fail to run. ([I5FILR](https://gitee.com/openharmony/xts_acts/issues/I5FILR))<br>- The reference '\@ohos.napi_context' of **graphic/webGL/src/main/js/default/test** in the WebGL is not used. ([I5FAF7](https://gitee.com/openharmony/xts_acts/issues/I5FAF7))<br>- The **Test.json** file of the ActsAudioManagerJsTest module is incorrectly configured. ([I5EJPP](https://gitee.com/openharmony/xts_acts/issues/I5EJPP))<br>- The capitalization of the **ohos.multimedia.mediaLibrary** test case package is incorrect. ([I5EJ3W](https://gitee.com/openharmony/xts_acts/issues/I5EJ3W))<br>- Four test suites corresponding to the common event and notification subsystem fail to run. ([I5EA00](https://gitee.com/openharmony/xts_acts/issues/I5EA00))<br>- There is an API exception of the test suite introduced by the **index.js** source code of the ActsUpdateJsTest module. ([I5D5BV](https://gitee.com/openharmony/xts_acts/issues/I5D5BV))<br>- The command configured in **Test.json** cannot create a directory for push resources. ([I5D50G](https://gitee.com/openharmony/xts_acts/issues/I5D50G))<br>- Certain test cases of the ActsAnsActiveTest test suite are incompatible. ([I5BQB0](https://gitee.com/openharmony/xts_acts/issues/I5BQB0))<br>- Five test cases of the ActsStServiceAbilityClientCaseTest module fail to run. ([I5GHRE](https://gitee.com/openharmony/xts_acts/issues/I5GHRE))<br>- Two test cases of the ActsSubscriberTestUnorderSystemTest module fail to run. ([I5GHP5](https://gitee.com/openharmony/xts_acts/issues/I5GHP5))<br>- The test suites of the ActsAudioRecorderJsTest and ActsMediaLibraryJsTest modules cannot be executed. ([I5H431](https://gitee.com/openharmony/xts_acts/issues/I5H431))|
| SDK subsystem| - There are bugs related to the Previewer.<br>- There are bugs related to C++ project debugging.|
| Application subsystem| - Notification management does not function as expected. ([I5FLLB](https://gitee.com/openharmony/applications_systemui/issues/I5FLLB))<br>- Notepad has certain bugs. ([5FJGJ](https://gitee.com/openharmony/applications_notes/issues/I5FJGJ), [I5FJ9L](https://gitee.com/openharmony/applications_notes/issues/I5FJ9L), [I5FJCS](https://gitee.com/openharmony/applications_notes/issues/I5FJCS))|


## Fixed Security Vulnerabilities

**Table 4** List of fixed security vulnerabilities

| Issue No.| Description| PR Link|
| -------- | -------- | -------- |
| I5FZTU | Security vulnerabilities of the Linux kernel 5.10 component: CVE-2022-21125, CVE-2022-2153, and CVE-2022-32296| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/307) |
| I5FZT0 | Security vulnerabilities of the Linux kernel 5.10 component: CVE-2022-1508, CVE-2022-1972, CVE-2022-1998, CVE-2022-21499, and CVE-2022-32981| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/301) |
| I5FZSH | Security vulnerabilities of the Linux kernel 5.10 component: CVE-2022-1974, CVE-2022-1975, CVE-2022-20153, CVE-2022-20154, and CVE-2022-20132| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/302) |
| I5FZQS | Security vulnerabilities of the Linux kernel 5.10 component: CVE-2022-1729 and CVE-2022-29581| [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/299) |
| I5CQMC | Security vulnerabilities of the third_party_chromium component: CVE-2022-2158, CVE-2022-2161, CVE-2022-2163, CVE-2022-2164, CVE-2022-2157, CVE-2022-2165, CVE-2022-2160, CVE-2022-2156, CVE-2022-1501, CVE-2022-2008, CVE-2022-2010, CVE-2022-2011, CVE-2022-1857, CVE-2022-1874, CVE-2022-0311, and CVE-2022-1314| [PR](https://gitee.com/openharmony/third_party_chromium/pulls/29) |
| I5GG74 | Security vulnerability of the third_party_openssl component: CVE-2022-2097| [PR](https://gitee.com/openharmony/third_party_openssl/pulls/64) |
| I5GQI2 | Security vulnerabilities of the third_party_curl component: CVE-2022-22576, CVE-2022-27775, CVE-2022-27774, and CVE-2022-27776| [PR](https://gitee.com/openharmony/third_party_curl/pulls/51) |
| I5H1HU | Security vulnerability of the libjpeg-turbo component under the third_party_flutter component: CVE-2021-46822| [PR](https://gitee.com/openharmony/third_party_flutter/pulls/117) |
| I5KI54 | Security vulnerability of the third_party_freetype component: CVE-2022-27405| [PR](https://gitee.com/openharmony/third_party_freetype/pulls/32) |
| I5J8V2 | Security vulnerabilities of the third_party_node component: CVE-2022-32212, CVE-2022-32213, CVE-2022-2097, and CVE-2022-32215| [PR](https://gitee.com/openharmony/third_party_node/pulls/29) |
| I59ZPI | Security vulnerabilities of the third_party_ntfs-3g component in version 2021.8.22.| [PR](https://gitee.com/openharmony/third_party_ntfs-3g/pulls/18) |
| I5EEXE | Security vulnerabilities of the third_party_pcre2 component: CVE-2022-1586 and CVE-2022-1587| [PR](https://gitee.com/openharmony/third_party_pcre2/pulls/24) |
| I5I9YX | Security vulnerabilities of the third_party_selinux component: CVE-2021-36085, CVE-2021-36084, and CVE-2021-36087| [PR](https://gitee.com/openharmony/third_party_selinux/pulls/31) |


## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| [I5M0GH](https://gitee.com/openharmony/applications_notes/issues/I5M0GH) | Notepad does not respond when a user attempts to restore a recently deleted note.| User experience is affected.| September 30, 2022|
