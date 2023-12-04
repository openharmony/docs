# OpenHarmony 3.2.3 Release


## Version Description

OpenHarmony 3.2.3 Release provides enhanced system security over OpenHarmony 3.2.2 Release by rectifying memory leak issues, certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues. The matching SDK version is also updated.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool                             | Version                                            | Remarks                                                        |
| --------------------------------- | ------------------------------------------------ | ------------------------------------------------------------ |
| OpenHarmony                       | 3.2.3 Release                                    | NA                                                           |
| Public SDK                        | Ohos_sdk_public 3.2.14.6 (API Version 9 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio     | 3.1 Release                                      | Recommended for developing OpenHarmony applications<br>[Click here](https://developer.harmonyos.com/en/develop/deveco-studio#download)|
| (Optional) HUAWEI DevEco Device Tool| 3.1 Release                                      | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide/).|

## Source Code Acquisition


### **Prerequisites**

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
 repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2.3-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

Obtain the source code from the version tag, which is the same as that released with the version.
 ```
 repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2.3-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                             | Version | Mirror                                                | SHA-256 Checksum                                            |
| ------------------------------------- | ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base (for mini, small, and standard systems)     | 3.2.3 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/code-v3.2.3-Release_20230904.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/code-v3.2.3-Release_20230904.tar.gz.sha256) |
| Hi3861 solution (binary)             | 3.2.3 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_pegasus.tar.gz.sha256) |
| Hi3516 solution-LiteOS (binary)      | 3.2.3 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516 solution-Linux (binary)       | 3.2.3 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568 standard system solution (binary)     | 3.2.3 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/dayu200_standard_arm32_20230904.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/dayu200_standard_arm32_20230904.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)          | 3.2.14.6      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/ohos-sdk-mac-public.tar.gz.sha256) |
| Public SDK package for the standard system (macOS-M1)       | 3.2.14.6      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) |
| Public SDK package for the standard system (Windows\Linux)| 3.2.14.6      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.3/ohos-sdk-windows_linux-public.tar.gz.sha256) |

## What's New

### API 

This version does not involve API updates.

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).

## Resolved Issues

**Table 3** Resolved issues

| Issue No.                                                       | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I76UCD](https://gitee.com/open_harmony/dashboard?issue_id=I76UCD) | [OpenHarmony 3.2.12.5] [3.2 Release] [Multimedia subsystem] [RK3568] [Inevitably: 10/10] When a recording file is played in Gallery, the image freezes for the last 2 seconds.|
| [I7B07F](https://e.gitee.com/open_harmony/issues/table/?issue=I7B07F) | [OpenHarmony 3.2.12.5] [Softbus] [Discovery] [rk3568] [Inevitably: 3/3] Bluetooth discovery fails.|
| [I7BZ4F](https://e.gitee.com/open_harmony/issues/table/?issue=I7BZ4F) | [OpenHarmony 3.2.13.1] [RK3568] [Discovery] [Probability: 3/42] CoAP discovery fails occasionally.|
| [I7C98S](https://e.gitee.com/open_harmony/issues/table/?issue=I7C98S) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [Low probability: 2/10] [wukong] A JavaScript crash occurs in the initializeConsume stack of com.ohos.photos. This issue occurs twice.|
| [I7FO8I](https://e.gitee.com/open_harmony/issues/table/?issue=I7FO8I) | [OpenHarmony 3.2 0620 daily] [RK3568] [Pressure test] [Low probability: 1/10] [wukong] A C++ crash occurs in libabilitykit_native.z.so of the IPC_3_14056 thread in com.ohos.adminprovisioning. This problem occurs once.|
| [I7FR03](https://e.gitee.com/open_harmony/issues/table/?issue=I7FR03) | [OpenHarmony 3.2 0620 daily] [RK3568] [Pressure test] [Low probability: 1/10] [wukong] Rosenweb on consumer occurs in RSRenderThread of the com.ohos.note process. As a result, a C++ crash occurs in libmali-bifrost-g52-g2p0-ohos.so. This problem occurs once.|
| [I7WJ2I](https://gitee.com/open_harmony/dashboard?issue_id=I7WJ2I) | [OpenHarmony master/3.2 Release] [Driver subsystem] [rk3568] [Inevitably: 5/5] Dynamic stream allocation fails.|
| [I6UYP6](https://gitee.com/open_harmony/dashboard?issue_id=I6UYP6) | [OpenHarmony 3.2 Release] When the **put** and **putSync** APIs are called to set the **key** length and **value** length that exceed the maximum number of bytes, the APIs do not throw any exception.|
| [I72P5E](https://gitee.com/open_harmony/dashboard?issue_id=I72P5E) | [OpenHarmony 3.2.12.2] [RK3568] [Pressure test] [Inevitably: 10/10] Memory leakage occurs in libace.z.so when a user repeatedly touches an image in Gallery to maximize it and then exits.|
| [I72P5I](https://gitee.com/open_harmony/dashboard?issue_id=I72P5I) | [OpenHarmony 3.2.12.2] [RK3568] [Pressure test] [Inevitably: 10/10] Memory leakage occurs in libace.z.so when a user repeatedly touches an image folder in Gallery to browse images in grid form and then exits.|
| [I76N0Y](https://gitee.com/open_harmony/dashboard?issue_id=I76N0Y) | [OpenHarmony 3.2.12.2] [RK3568] [Pressure test] [Inevitably: 10/10] Memory leakage occurs in libace.z.so when an application is repeatedly added to and then removed from the dock bar.|
| [I7FNXR](https://gitee.com/open_harmony/dashboard?issue_id=I7FNXR) | [OpenHarmony 3.2.13.5] [RK3568] [Pressure test] [Low probability: 1/10] [wukong] A C++ crash occurs in libipc_core.z.so of the IPC_7_15380 thread in the camera_service process. This problem occurs once.|
| [I7GATH](https://gitee.com/open_harmony/dashboard?issue_id=I7GATH) | [OpenHarmony 3.2.13.5] [Input method] [Inevitably: 5/5] A C++crash occurs in the input method selection box after an injection test is performed on the DevecoTesting service interface.|
| [I7HDQP](https://gitee.com/open_harmony/dashboard?issue_id=I7HDQP) | [OpenHarmony 3.2.13.5] [Application subsystem] [RK3568] [Inevitably: 5/5] After the language is switched to English, some application names on the home screen are still displayed in Chinese. They are displayed in English only after a system restart.|
| [I7HFEO](https://gitee.com/open_harmony/dashboard?issue_id=I7HFEO) | [OpenHarmony 3.2.14.1] [Test subsystem] [3861] [Inevitably: 5/5] A test item fails in the ActsUiTest module.|
| [I7HX8E](https://gitee.com/open_harmony/dashboard?issue_id=I7HX8E) | [OpenHarmony 3.2.14.1] [RK3568] [XTS pressure test] [Low probability] A C++ crash occurs in librpc.z.so of the jsThread-1 thread in the com.ohos.rpctest process. This issue occurs twice.|
| [I7IV88](https://gitee.com/open_harmony/dashboard?issue_id=I7IV88) | [OpenHarmony 3.2.14.1] [RK3568] [Pressure test] [Low probability] [wukong] A JavaScript crash occurs in clickToGroupDetail of the key process com.ohos.mms. This issue occurs four times.|
| [I7KZKQ](https://gitee.com/open_harmony/dashboard?issue_id=I7KZKQ) | [OpenHarmony 3.2.14.2] [RK3568] [Pressure test] [Low probability] [wukong] A JavaScript crash occurs in clickInfoToConversation of the key process com.ohos.mms. This issue occurs 13 times.|
| [I7KZLX](https://gitee.com/open_harmony/dashboard?issue_id=I7KZLX) | [OpenHarmony 3.2.14.2] [RK3568] [Pressure test] [Low probability] [wukong] A JavaScript crash occurs in dealSessionDraft of com.ohos.mms. This issue occurs once.|
| [I7KZN7](https://gitee.com/open_harmony/dashboard?issue_id=I7KZN7) | [OpenHarmony 3.2.14.2] [RK3568] [Pressure test] [Low probability] [wukong] A JavaScript crash occurs in menuChange of the key process com.ohos.contact. This issue occurs 18 times.|
| [I7PAL6](https://gitee.com/open_harmony/dashboard?issue_id=I7PAL6) | [OpenHarmony 3.2.14.5] [RK3568] [Pressure test] [Low probability] [wukong] A C++ crash occurs in libhap_restorecon.z.so of the IPC_1_643 thread in /system/bin/installs. This issue occurs once.|
| [I7Q85E](https://gitee.com/open_harmony/dashboard?issue_id=I7Q85E) | [OpenHarmony 3.2.14.5] [RK3568] [Pressure test] [wukong] The memory usage is too high during the pressure test.|
| [I7VAB8](https://gitee.com/open_harmony/dashboard?issue_id=I7VAB8) | [OpenHarmony 3.2.14.6] [RK3568] [Pressure test] [Low probability] [wukong] A C++ crash occurs in libcamera_napi.z.so of the com.ohos.camera thread in the com.ohos.camera process. This issue occurs 24 times.|
| [I7VBCV](https://gitee.com/open_harmony/dashboard?issue_id=I7VBCV) | [OpenHarmony 3.2.14.6] [RK3568] [Pressure test] [Low frequency] A JavaScript crash occurs in the cancelTimer stack of the ohos.samples.distributedmusicplayer process. This issue occurs three times.|
| [I7BL13](https://gitee.com/open_harmony/dashboard?issue_id=I7BL13) | [OpenHarmony 3.2 Release] [Power subsystem] [rk3568] [Inevitably: 5/5] A global thread is created using a local variable.|
| [I7BY2N](https://gitee.com/open_harmony/dashboard?issue_id=I7BY2N) | [OpenHarmony 3.2 Release] An empty file can be compiled.|
| [I7CREK](https://gitee.com/open_harmony/dashboard?issue_id=I7CREK) | [OpenHarmony 3.2 Release] JSON parameter verification needs an adjustment.|

## Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No. | Description                                           |
| ------ | --------------------------------------------------- |
| I71KHW | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-32233 |
| I6QYW7 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-4095|
| I6RZV9 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-4744|
| I6TCVF | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-1838|
| I6TCVR | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-1855|
| I6TCW0 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-1582|
| I6U82D | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-30456|
| I6UW4X | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-29581|
| I6UW4Y | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-1158|
| I6VHE0 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-1990|
| I6VVQJ | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-1859|
| I6W9EQ | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-30772|
| I6YK8O | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2008|
| I6ZH6E | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-0458|
| I6ZJDL | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-31436|
| I6ZK8X | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2177|
| I6ZK92 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2194|
| I6ZQRA | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-28328|
| I6ZQRH | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2166|
| I6ZQRM | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-28327|
| I6ZUT4 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2248|
| I6ZZDJ | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-1998|
| I70B1G | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2483|
| I72GRH | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-32269|
| I73Z2O | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2124|
| I76VW0 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-0459|
| I78R44 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-33203|
| I79YE0 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-34256|
| I7HIGZ | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-41858|
| I7HIH1 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3421|
| I7HIH4 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3268|
| I7HIHC | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-35788|
| I7HIHE | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3161|
| I7HIHF | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3220|
| I7HIHG | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3159|
| I7HIHN | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-35823|
| I7HIHP | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-35828|
| I7HIHQ | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-35824|
| I7HIHR | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-35829|
| I7HIHT | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3141|
| I7HIHV | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3216|
| I7HIHW | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3215|
| I7HII0 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3212|
| I7HII2 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2002|
| I7HII3 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-2970|
| I7HII8 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3079|
| I7I5J3 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22597|
| I7JKP5 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-37327|
| I7MTCB | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22039|
| I7MTCL | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-12284|
| I7MTCU | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22044|
| I7MTD1 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22021|
| I7MTD8 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22040|
| I7MTDG | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22037|
| I7MTDN | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22041|
| I7MTDX | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22026|
| I7MTE2 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22043|
| I7MTE9 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22042|
| I7MTEM | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22035|
| I7MTEX | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22036|
| I7MTFZ | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22048|
| I7MTGL | [Vulnerability] [OpenHarmony 3.2 Release] lj-c-131450017-9125433|
| I7MTML | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3446|
| I7N91T | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-25636|
| I7NU2Z | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22028|
| I7NU35 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22019|
| I7NU3C | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-22020|
| I7NVP2 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-41409|
| I7OWF7 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-27777|
| I7OWFA | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2020-25668|
| I7OY06 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-4912|
| I7OY0E | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-4909|
| I7OZ6F | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-36191|
| I7P791 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3598|
| I7PTFP | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3567|
| I7Q3I0 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3812|
| I7QFUC | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-3817|
| I7QR0J | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-1729|
| I7QR0S | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-3202|
| I7QR0V | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-3564|
| I7QR1U | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2021-4083|
| I7QRFE | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-4072|
| I7QRFQ | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-4071|
| I7QRFT | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-4076|
| I7S222 | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-4273|
| I7T5YY | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2023-4194|
| I7UE6S | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-3623|
| I7UE6U | [Vulnerability] [OpenHarmony 3.2 Release] CVE-2022-2196|

## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| ----- | -------- | ---- | ------------ |
| [I7HW2C](https://e.gitee.com/open_harmony/dashboard?issue=I7E931) | [OpenHarmony 3.2.14.1] [RK3568] [Pressure test] [ToC] [Low probability] [wukong] A C++ crash occurs in libace.z.so of the com.ohos.note thread in the key process com.ohos.note. This problem occurs 20 times.| Impact on application development (especially APIs) and user experience: The note application may break down in some scenarios. This issue occurs 15 times during the pressure test on multiple devices within 10,000 hours. From the HiLog analysis, there is a high probability that this issue occurs in extreme scenarios and has little impact on normal use. It has no impact on the chip platform and subsystem communities.| 2023-10-31|
| [I7E931](https://e.gitee.com/open_harmony/dashboard?issue=I7E931) | Memory leakage issues in OpenHarmony 3.2 Release.| When a JavaScript application calls the IPC, the NAPIRemoteObject process needs to be created, and 1.2 KB memory occurs during the creation. However, the process can be used repeatedly once created, and the memory is released when the application process exits.| 2023-10-31|
| [I7P9VS](https://e.gitee.com/open_harmony/issues/table/?issue=I7P9VS) |[OpenHarmony 3.2.14.5] [RK3568] [Pressure test] [Inevitably: 10/10] Memory leakage occurs in ElementRegister::ClearRemovedItems when a user repeatedly touches an image in Gallery to maximize it and then exits.| The leaked memory size is reduced from several KBs to 72 bytes. This issue has little impact on the system.| 2023-10-31|
| [I7P9T5](https://e.gitee.com/open_harmony/issues/table/?issue=I7P9T5) |[OpenHarmony 3.2.14.5] [RK3568] [Pressure test] [Inevitably: 10/10] Memory leakage occurs in ElementRegister::RemoveItem and ElementRegister::ClearRemovedItems when a user repeatedly touches an image folder in Gallery to browse images in grid form and then exits.| The leaked memory size is reduced from several KBs to 144 bytes. This issue has little impact on the system.| 2023-10-31|
