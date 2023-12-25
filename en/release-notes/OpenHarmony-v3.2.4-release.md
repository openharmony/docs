# OpenHarmony 3.2.4 Release


## Version Description

OpenHarmony 3.2.4 Release provides enhanced system security over OpenHarmony 3.2.3 Release by rectifying memory leak issues, certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues. The matching SDK version is also updated.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool                             | Version                                            | Remarks                                                        |
| --------------------------------- | ------------------------------------------------ | ------------------------------------------------------------ |
| OpenHarmony                       | 3.2.4 Release                                    | NA                                                           |
| Public SDK                        | Ohos_sdk_public 3.2.15.4 (API Version 9 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
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
 repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2.4-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

Obtain the source code from the version tag, which is the same as that released with the version.
 ```
 repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2.4-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                             | Version | Mirror                                                | SHA-256 Checksum                                            |
| ------------------------------------- | ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base (for mini, small, and standard systems)     | 3.2.4 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/code-v3.2.4-Release_20231113.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/code-v3.2.4-Release_20231113.tar.gz.sha256) |
| Hi3861 solution (binary)             | 3.2.4 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_pegasus.tar.gz.sha256) |
| Hi3516 solution-LiteOS (binary)      | 3.2.4 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516 solution-Linux (binary)       | 3.2.4 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568 standard system solution (binary)     | 3.2.4 Release | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/dayu200_standard_arm32_20231129.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/dayu200_standard_arm32_20231129.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)          | 3.2.15.4      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/ohos-sdk-mac-public.tar.gz.sha256) |
| Public SDK package for the standard system (macOS-M1)       | 3.2.15.4      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) |
| Public SDK package for the standard system (Windows\Linux)| 3.2.15.4      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.4/ohos-sdk-windows_linux-public.tar.gz.sha256) |

## What's New

### API 

This version does not involve API updates.

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).

## Resolved Issues

**Table 3** Resolved issues

| Issue No.                                                       | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I7C8QM](https://gitee.com/open_harmony/dashboard?issue_id=I7C8QM) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [Low probability: 2/10] [wukong] A C++ crash occurs in libability_manager.z.so of the com.ohos.contact thread in the com.ohos.contacts process. This problem occurs twice.|
| [I7GFN1](https://gitee.com/open_harmony/dashboard?issue_id=I7GFN1) | [OpenHarmony 3.2.13.5] [Application subsystem] [RK3568] [Inevitability: 5/5] In the Contacts application, the word "Telephone" is displayed across lines.|
| [I7GFWZ](https://gitee.com/open_harmony/dashboard?issue_id=I7GFWZ) | [OpenHarmony 3.2.13.5] [Application subsystem] [RK3568] [Inevitability: 5/5] The default date displayed in the contact's birthday dialog box is January 31, 2000.|
| [I7GG5K](https://gitee.com/open_harmony/dashboard?issue_id=I7GG5K) | [OpenHarmony 3.2.13.5] [Application subsystem] [RK3568] [Inevitability: 5/5] When creating a contact, a user selects a date in the birthday column. When the user accesses the page again to select another date, the default date is displayed.|
| [I7GGCV](https://gitee.com/open_harmony/dashboard?issue_id=I7GGCV) | [OpenHarmony 3.2.13.5] [Application subsystem] [RK3568] [Inevitability: 5/5] On the contact editing page, a user adds a text box for the email field. When the user clicks the delete button next to the new line, the system does not respond.|
| [I7IJNI](https://gitee.com/open_harmony/dashboard?issue_id=I7IJNI) | [OpenHarmony 3.2.14.1] [Web subsystem] [RK3568] [Inevitability: 5/5] A user clicks **Basic Web Component Functions & Callbacks** and enters **hilog \**| **grep WebRedo**. The log **The request header key is : xxx -- value is : xxx** is not displayed as expected.|
| [I7OODS](https://gitee.com/open_harmony/dashboard?issue_id=I7OODS) | [OpenHarmony 3.2.14.5] [RK3568] [Pressure test] [ToC] [Low probability: 1/10] [wukong] A JS crash occurs in the aboutToDisappear stack of the com.ohos.callui process. This problem occurs twice.|
| [I7P9T5](https://gitee.com/open_harmony/dashboard?issue_id=I7P9T5) | [OpenHarmony 3.2.14.5] [RK3568] [Pressure test] [Inevitability: 10/10] Memory leakage occurs in ElementRegister::RemoveItem and ElementRegister::ClearRemovedItems when a user repeatedly touches an image folder in Gallery to browse images in grid form and then exits.|
| [I7P9VS](https://gitee.com/open_harmony/dashboard?issue_id=I7P9VS) | [OpenHarmony 3.2.14.5] [RK3568] [Pressure test] [Inevitability: 10/10] Memory leakage occurs in ElementRegister::ClearRemovedItems when a user repeatedly touches an image in Gallery to maximize it and then exits.|
| [I7PASS](https://gitee.com/open_harmony/dashboard?issue_id=I7PASS) | [OpenHarmony 3.2.14.5] [RK3568] [Pressure test] [ToC] [Low probability] [wukong] A C++ crash occurs in libcamera_pipeline_core.z.so of the offlinepipeline thread in the camera_host process. This problem occurs twice.|
| [I7WQX1](https://gitee.com/open_harmony/dashboard?issue_id=I7WQX1) | [OpenHarmony 3.2.14.6] [Graphics subsystem] [Standard system] [High probability: 8/20] In video recording mode, when a user presses the Home key to return to the home screen and enters the camera mode from an FA widget, a blue bar is displayed under the preview area.|
| [I80MCW](https://gitee.com/open_harmony/dashboard?issue_id=I80MCW) | [OpenHarmony 3.2.14.6] [Application subsystem] [RK3568] [Inevitable: 5/5] The **Recents** page blinks.|
| [I822E8](https://gitee.com/open_harmony/dashboard?issue_id=I822E8) | [OpenHarmony 3.2.15.1] [Multimedia subsystem] [Standard system] [Inevitability: 5/5] When the camera starts recording, the user kills media_service, returns to the background, and accesses the camera again. In this case, an error message is displayed.|
| [I82H3V](https://gitee.com/open_harmony/dashboard?issue_id=I82H3V) | [OpenHarmony 3.2.15.1] [Multimedia subsystem] [RK3568] [Inevitability] When a user accesses the image editing page in Gallery, returns to the previous page, and flicks images, the image details are abnormal. When the user restarts the Gallery application, the deleted images cannot be cleared.|
| [I82LYJ](https://gitee.com/open_harmony/dashboard?issue_id=I82LYJ) | [OpenHarmony 3.2.15.1] [Globalization subsystem] [RK3568] [Inevitability] A user accesses an application under control, sets enterprise information, restarts the application, and views the information again. The information before the setting is displayed.|
| [I836GY](https://gitee.com/open_harmony/dashboard?issue_id=I836GY) | [OpenHarmony 3.2.15.1] [Application subsystem] [RK3568] [Inevitability: 5/5] When a large video in Gallery is being played in immersive mode, the navigation bar is displayed at the bottom, blocking the progress bar.|
| [I8407H](https://gitee.com/open_harmony/dashboard?issue_id=I8407H) | [OpenHarmony 3.2.15.1] [RK3568] [Pressure test] [ToC] [Low probability] [wukong] A JS crash occurs in initDb of the com.ohos.smartperf process. This problem occurs once.|
| [I844Q9](https://gitee.com/open_harmony/dashboard?issue_id=I844Q9) | [OpenHarmony 3.2.15.2] [Application subsystem] [RK3568] [Inevitability: 5/5] Gallery widget covers cannot be automatically refreshed.|
| [I84F9F](https://gitee.com/open_harmony/dashboard?issue_id=I84F9F) | [OpenHarmony 3.2.15.2] [Application subsystem] [Standard system] [Inevitability: 5/5] The selection status on the large image browsing page is inconsistent with that on the grid page.|
| [I84FAO](https://gitee.com/open_harmony/dashboard?issue_id=I84FAO) | [OpenHarmony 3.2.15.2] [Application subsystem] [RK3568] [Inevitability: 5/5] When the RK screen is locked, no SMS notification is displayed on the locked screen.|
| [I84IB2](https://gitee.com/open_harmony/dashboard?issue_id=I84IB2) | [OpenHarmony 3.2.15.2] [Application subsystem] [RK3568] [Inevitability: 5/5] When a user opens a recent task during camera recording, the camera does not display the screenshot of the running page in **Recents**.|
| [I86PMC](https://gitee.com/open_harmony/dashboard?issue_id=I86PMC) | [OpenHarmony 3.2.15.3] [Application subsystem] [Standard system] [Inevitability: 5/5] Photos in Gallery are inconsistent in size and resolution after being mirrored.|
| [I86Y2L](https://gitee.com/open_harmony/dashboard?issue_id=I86Y2L) | [OpenHarmony3.2] [acts] [3568] [Inevitability: 5/5] The ActsDeqpgles2TestSuite suite fails to be executed.|
| [I88A1G](https://gitee.com/open_harmony/dashboard?issue_id=I88A1G) | [OpenHarmony 3.2.15.3] [RK3568] [Pressure test] [ToC] [Low probability] [wukong] A C++ crash occurs in libaudio_client.z.so of the IPC_3_10819 thread in the media_service process. This problem occurs once.|
| [I89423](https://gitee.com/open_harmony/dashboard?issue_id=I89423) | [OpenHarmony 3.2.15.3] [Application subsystem] [RK3568] [Inevitability: 5/5] During a call, a user presses the Back key to return to the home screen, and then touches the green bar on the status bar to return to the call screen. After the user ends the call, the call screen does not disappear.|
| [I8952L](https://gitee.com/open_harmony/dashboard?issue_id=I8952L) | [OpenHarmony 3.2.15.3] [Application subsystem] [RK3568] [Inevitability: 5/5] In the daily view of Gallery, photos from 00:00 to 07:59 of one day and photos from 08:00 to 23:59 of the previous day are displayed under the same date.|
| [I89FCI](https://gitee.com/open_harmony/dashboard?issue_id=I89FCI) | [OpenHarmony 3.2.15.3] [RK3568] [Pressure test] [ToC] [Low probability] [wukong] A C++ crash occurs in libfeatureability.z.so of the jsThread-1 thread in the ohos.samples.distributedmusicplayer process. This problem occurs once.|
| [I8EJ62](https://gitee.com/open_harmony/dashboard?issue_id=I8EJ62) | [OpenHarmony 3.2.15.3] [netmanager_base] [RK3568] [Inevitability] AVC alarm logs of netmanager are generated.|
| [I8EQPY](https://gitee.com/open_harmony/dashboard?issue_id=I8EQPY) | [OpenHarmony 3.2.15.4] [Application subsystem] [RK3568] [Inevitability: 5/5] New albums are not displayed in Gallery.|

## Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.                                                       | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I73C2J](https://gitee.com/open_harmony/dashboard?issue_id=I73C2J) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2513          |
| [I7HIH8](https://gitee.com/open_harmony/dashboard?issue_id=I7HIH8) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1206          |
| [I7JBBQ](https://gitee.com/open_harmony/dashboard?issue_id=I7JBBQ) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-37453         |
| [I7QH9Y](https://gitee.com/open_harmony/dashboard?issue_id=I7QH9Y) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-4911          |
| [I7QHAP](https://gitee.com/open_harmony/dashboard?issue_id=I7QHAP) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-4908          |
| [I7QR3I](https://gitee.com/open_harmony/dashboard?issue_id=I7QR3I) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0541812|
| [I7U56X](https://gitee.com/open_harmony/dashboard?issue_id=I7U56X) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4357          |
| [I7U57G](https://gitee.com/open_harmony/dashboard?issue_id=I7U57G) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4351          |
| [I7U57L](https://gitee.com/open_harmony/dashboard?issue_id=I7U57L) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4354          |
| [I7U583](https://gitee.com/open_harmony/dashboard?issue_id=I7U583) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4353          |
| [I7U59K](https://gitee.com/open_harmony/dashboard?issue_id=I7U59K) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4362          |
| [I7U5A4](https://gitee.com/open_harmony/dashboard?issue_id=I7U5A4) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0547797|
| [I7U5A9](https://gitee.com/open_harmony/dashboard?issue_id=I7U5A9) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4352          |
| [I7U7HY](https://gitee.com/open_harmony/dashboard?issue_id=I7U7HY) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4355          |
| [I7UZ5X](https://gitee.com/open_harmony/dashboard?issue_id=I7UZ5X) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-40283         |
| [I7V73B](https://gitee.com/open_harmony/dashboard?issue_id=I7V73B) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4385          |
| [I7V74X](https://gitee.com/open_harmony/dashboard?issue_id=I7V74X) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4387          |
| [I7V8FJ](https://gitee.com/open_harmony/dashboard?issue_id=I7V8FJ) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4427          |
| [I7VS48](https://gitee.com/open_harmony/dashboard?issue_id=I7VS48) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4459          |
| [I7W2OE](https://gitee.com/open_harmony/dashboard?issue_id=I7W2OE) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-0850          |
| [I7W6NH](https://gitee.com/open_harmony/dashboard?issue_id=I7W6NH) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0557737|
| [I7XPVH](https://gitee.com/open_harmony/dashboard?issue_id=I7XPVH) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0566914|
| [I7XT56](https://gitee.com/open_harmony/dashboard?issue_id=I7XT56) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-3777          |
| [I7XXDW](https://gitee.com/open_harmony/dashboard?issue_id=I7XXDW) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4572          |
| [I7ZATO](https://gitee.com/open_harmony/dashboard?issue_id=I7ZATO) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4208          |
| [I7ZATV](https://gitee.com/open_harmony/dashboard?issue_id=I7ZATV) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4207          |
| [I7ZATY](https://gitee.com/open_harmony/dashboard?issue_id=I7ZATY) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4206          |
| [I7ZBXP](https://gitee.com/open_harmony/dashboard?issue_id=I7ZBXP) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4623          |
| [I7ZBXS](https://gitee.com/open_harmony/dashboard?issue_id=I7ZBXS) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4622          |
| [I7ZLCB](https://gitee.com/open_harmony/dashboard?issue_id=I7ZLCB) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0568539|
| [I7ZV0X](https://gitee.com/open_harmony/dashboard?issue_id=I7ZV0X) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4762          |
| [I7ZV0Z](https://gitee.com/open_harmony/dashboard?issue_id=I7ZV0Z) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4763          |
| [I7ZVJW](https://gitee.com/open_harmony/dashboard?issue_id=I7ZVJW) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4807          |
| [I819HJ](https://gitee.com/open_harmony/dashboard?issue_id=I819HJ) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4921          |
| [I81J37](https://gitee.com/open_harmony/dashboard?issue_id=I81J37) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4863          |
| [I81T8G](https://gitee.com/open_harmony/dashboard?issue_id=I81T8G) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4904          |
| [I82FGR](https://gitee.com/open_harmony/dashboard?issue_id=I82FGR) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0572429|
| [I83HEM](https://gitee.com/open_harmony/dashboard?issue_id=I83HEM) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2163          |
| [I83SS5](https://gitee.com/open_harmony/dashboard?issue_id=I83SS5) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-39615         |
| [I84KG1](https://gitee.com/open_harmony/dashboard?issue_id=I84KG1) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2020-24187         |
| [I84N7U](https://gitee.com/open_harmony/dashboard?issue_id=I84N7U) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-42753         |
| [I84PVS](https://gitee.com/open_harmony/dashboard?issue_id=I84PVS) | [Vulnerability] [OpenHarmony-3.2-Release] LJ-2023-0102259        |
| [I86CNK](https://gitee.com/open_harmony/dashboard?issue_id=I86CNK) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0577967|
| [I86KSB](https://gitee.com/open_harmony/dashboard?issue_id=I86KSB) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-38545         |
| [I86P29](https://gitee.com/open_harmony/dashboard?issue_id=I86P29) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-39194         |
| [I86WMZ](https://gitee.com/open_harmony/dashboard?issue_id=I86WMZ) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-4128          |
| [I86WNG](https://gitee.com/open_harmony/dashboard?issue_id=I86WNG) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-3420          |
| [I86WNW](https://gitee.com/open_harmony/dashboard?issue_id=I86WNW) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-5217          |
| [I86WOQ](https://gitee.com/open_harmony/dashboard?issue_id=I86WOQ) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-45322         |
| [I870HM](https://gitee.com/open_harmony/dashboard?issue_id=I870HM) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-44487         |
| [I873CB](https://gitee.com/open_harmony/dashboard?issue_id=I873CB) | [Vulnerability] [OpenHarmony-3.2-Release] LJ-2023-0105149        |
| [I877V3](https://gitee.com/open_harmony/dashboard?issue_id=I877V3) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204699-0582367|
| [I877V6](https://gitee.com/open_harmony/dashboard?issue_id=I877V6) | [Vulnerability] [OpenHarmony-3.2-Release] LJ-2023-0105164        |
| [I87AR1](https://gitee.com/open_harmony/dashboard?issue_id=I87AR1) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-38545         |
| [I87BZG](https://gitee.com/open_harmony/dashboard?issue_id=I87BZG) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-38546         |
| [I87CVV](https://gitee.com/open_harmony/dashboard?issue_id=I87CVV) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-42754         |
| [I87CWV](https://gitee.com/open_harmony/dashboard?issue_id=I87CWV) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-39189         |
| [I87CX1](https://gitee.com/open_harmony/dashboard?issue_id=I87CX1) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-39193         |
| [I87CX3](https://gitee.com/open_harmony/dashboard?issue_id=I87CX3) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-39192         |
| [I87QBZ](https://gitee.com/open_harmony/dashboard?issue_id=I87QBZ) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0583126|
| [I87ZQ2](https://gitee.com/open_harmony/dashboard?issue_id=I87ZQ2) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-5218          |
| [I87ZQT](https://gitee.com/open_harmony/dashboard?issue_id=I87ZQT) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-5484          |
| [I8846X](https://gitee.com/open_harmony/dashboard?issue_id=I8846X) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-45853         |
| [I88GIQ](https://gitee.com/open_harmony/dashboard?issue_id=I88GIQ) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0611977|
| [I88GIS](https://gitee.com/open_harmony/dashboard?issue_id=I88GIS) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0611988|
| [I894HL](https://gitee.com/open_harmony/dashboard?issue_id=I894HL) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-40474         |
| [I894IR](https://gitee.com/open_harmony/dashboard?issue_id=I894IR) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-40475         |
| [I894JL](https://gitee.com/open_harmony/dashboard?issue_id=I894JL) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-40476         |
| [I8B1VW](https://gitee.com/open_harmony/dashboard?issue_id=I8B1VW) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-5717          |
| [I8BB0I](https://gitee.com/open_harmony/dashboard?issue_id=I8BB0I) | [Vulnerability] [OpenHarmony-3.2-Release] lj-linux-131204684-0620866|
| [I8BKEB](https://gitee.com/open_harmony/dashboard?issue_id=I8BKEB) | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-5472          |

## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| ----- | -------- | ---- | ------------ |
| /     | /        | /    | /            |
