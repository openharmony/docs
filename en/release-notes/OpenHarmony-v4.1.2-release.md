# OpenHarmony 4.1.2 Release


## Version Description

OpenHarmony 4.1.2 Release provides enhanced system security over OpenHarmony 4.1.1 Release by rectifying certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues.

## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.1.2 Release | NA |
| Public SDK | Ohos_sdk_public 4.1.8.5 (API Version 11 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.|
| (Optional) HUAWEI DevEco Studio| 4.1 Release | Recommended for developing OpenHarmony applications How to obtain:<br><br>SHA-256 checksum: c46be4f3cfde27af1806cfc9860d9c366e66a20e31e15180cf3a90ab05464650<br><br>SHA-256 checksum: 15d6136959b715e4bb2160c41d405b889820ea26ceadbb416509a43e59ed7f09<br><br>SHA-256 checksum: ac04ca7c2344ec8f27531d5a59261ff037deed2c5a3d42ef88e6f90f4ed45484 |
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide#download). |


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


Obtain the source code from the version tag, which is the same as that released with the version.
```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1.2-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

Obtain the source code from the version tag, which is the same as that released with the version.
```
repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1.2-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.1.2 Release   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/code-v4.1.2-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/code-v4.1.2-Release.tar.gz.sha256) | 34.5 GB |
| Hi3861 solution (binary)       | 4.1.2 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_pegasus.tar.gz.sha256) | 27.0 MB |
| Hi3516 solution-LiteOS (binary)| 4.1.2Release   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 320.1 MB |
| Hi3516 solution-Linux (binary) | 4.1.2 Release   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_taurus_Linux.tar.gz.sha256) | 217.4 MB |
| RK3568 standard system solution (binary)       | 4.1.2 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| Public SDK package for the standard system (macOS)            | 4.1.8.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/ohos-sdk-mac-public.tar.gz.sha256) | 913.3 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.1.8.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 884.0 MB |
| Public SDK package for the standard system (Windows/Linux)  | 4.1.8.5 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |


## Change History

 N/A

## Fixed Bugs and Security Issues

**Table 3** Resolved issues

| Issue No.| Issue Description|
| -------- | -------- |
| [IB7R74](https://gitee.com/openharmony/applications_photos/issues/IB7R74?from=project-issue) | [RK3568] When inserting an image from Gallery into the Notepad application, selecting the second image results in the first image being inserted.  |
| [IB7KDL](https://gitee.com/openharmony/applications_screenlock/issues/IB7KDL?from=project-issue) | [RK3568] After canceling the lock screen password, relocking and unlocking still requires a password input, and the previously used password is ineffective.|
| [IB7KDI](https://gitee.com/openharmony/applications_screenlock/issues/IB7KDI?from=project-issue) | [RK3568] On the mixed password unlock screen, the first character entered is not fully displayed.      |
| [IB7KGX](https://gitee.com/openharmony/applications_launcher/issues/IB7KGX?from=project-issue) | [RK3568] After a normal firmware update, the home screen icon layout becomes disordered.                          |
| [IB8YCY](https://gitee.com/openharmony/xts_acts/issues/IB8YCY?from=project-issue) | [RK3568] The ACTS suite ActsNetManagerHttpEtsTest fails to be executed.     |
| [IAPYJN](https://gitee.com/openharmony/multimedia_media_lite/issues/IAPYJN?from=project-issue) | [Small-system LiteOS] After a video in Gallery finishes playing, clicking to replay results in a blue screen.|
| [IB21XU](https://gitee.com/openharmony/xts_hats/issues/IB21XU?from=project-issue) | [RK3568] The HATS suites HatsHdfAudioIdlRenderAdditionalTest and HatsHdfAudioIdlCaptureAdditionalTest fail to be executed.|
| [IB68WS](https://gitee.com/openharmony/xts_acts/issues/IB68WS?from=project-issue) | [RK3568] The ACTS suite ActsAceWebEnhancedTestTwo has one failed test case.|
| [I90N04](https://gitee.com/openharmony/applications_settings/issues/I90N04?from=project-issue) | [RK3568] Under **Settings > System > Factory reset**, upon entering the factory reset page, the text on the screen is disordered and there is no reset button.|
| [IAX7SV](https://gitee.com/openharmony/xts_acts/issues/IAX7SV?from=project-issue) | [RK3568] The ACTS suite ActsAceWebEnhancedTestTwo has one failed test case.|
| [I9PQ6I](https://gitee.com/openharmony-sig/ability_form_runtime/issues/I9PQ6I?from=project-issue) | [RK3568] A static widget becomes transparent a few seconds after it is added.|
| [IATPGW](https://gitee.com/openharmony/xts_acts/issues/IATPGW?from=project-issue) | [RK3568] The ACTS suite ActsRequestAuthorityTest has six failed test cases.|
| [I9NDZE](https://gitee.com/openharmony/accessibility/issues/I9NDZE?from=project-issue) | [RK3568] After restarting the phone, upgrading an application, or switching accounts, services that were previously running cannot be automatically restarted.|
| [I9SI9E](https://gitee.com/openharmony/web_webview/issues/I9SI9E?from=project-issue) | [RK3568] The overscroll function fails.|
| [I9PQFE](https://gitee.com/openharmony/window_window_manager/issues/I9PQFE?from=project-issue) | [RK3568] After the decoration bar is configured, clicking the split-screen button and then clicking the snapshot to be split-screened does not result in a split-screen.|
| [IANK0I](https://gitee.com/openharmony/applications_launcher/issues/IANK0I?from=project-issue) | [RK3568] Failed to add a service widget to the home screen.|
| [I90GOK](https://gitee.com/openharmony/applications_launcher/issues/I90GOK?from=project-issue) | [RK3568] A blank page exists on the home screen. After a user creates a folder and touches the plus sign (+) to add a home screen application to the folder, the blank page disappears.|
| [I9SMPC](https://gitee.com/openharmony/graphic_graphic_2d/issues/I9SMPC?from=project-issue) | [RK3568] Enabling color inversion in accessibility settings does not take effect on the home screen and Settings screen.|
| [I9RMYL](https://gitee.com/openharmony/notification_distributed_notification_service/issues/I9RMYL?from=project-issue) | [RK3568] Clicking a WantAgent notification does not launch another application.|
| [I9RZLH](https://gitee.com/openharmony/multimedia_media_lite/issues/I9RZLH?from=project-issue) | [Small-system LiteOS] After a video in Gallery finishes playing, clicking to replay results in a blue screen.|
| [IAHYNM](https://gitee.com/openharmony/applications_photos/issues/IAHYNM?from=project-issue) | [RK3568] When users manually select and attempt to delete images from various date categories on the photo page, deletion is only successful for images from the earliest selected date category.|
| [I97G7Y](https://gitee.com/openharmony/multimedia_av_session/issues/I97G7Y?from=project-issue) | [RK3568] In the media provider, the previous and next operations only switch the song images without changing the text, which remains as the first music. The media controller fails to obtain music information from the media provider.|
| [I9OF7E](https://gitee.com/openharmony/update_update_app/issues/I9OF7E?from=project-issue) | [RK3568] After a successful or failed upgrade installation, restarting the device does not show any notification in the notification panel.|
| [I9CX99](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/I9CX99?from=project-issue) | [RK3568] Some VM interfaces have deteriorated performance when compared with OpenHarmony 4.0.|
| [I98KLY](https://gitee.com/openharmony/arkui_ace_engine/issues/I98KLY?from=project-issue) | [RK3568] There is an issue with abilityComponent; it should not follow the window pattern's OnAttachToFrameNode.|
| [I966DO](https://gitee.com/openharmony/multimedia_audio_framework/issues/I966DO?from=project-issue) | [RK3568] System services fail fuzz testing.|
| [I9JX99](https://gitee.com/openharmony/arkui_ace_engine/issues/I9JX99?from=project-issue) | [RK3568] In a scenario where Tabs sub-tabs and custom tabs are mixed, the second sub-tab does not display the selected state for the tab text.|
| [IAEQQV](https://gitee.com/openharmony/applications_systemui/issues/IAEQQV?from=project-issue) | [RK3568] A dialog box is displayed indicating that the file cannot be opened after Wi-Fi is connected.|
| [I9TEVB](https://gitee.com/openharmony/window_window_manager/issues/I9TEVB?from=project-issue) | [RK3568] When verifying the capability of restoring the default screen brightness through window settings, clicking the "Default brightness" button results in no change in brightness.|
| [I9R4Y1](https://gitee.com/openharmony/multimodalinput_input/issues/I9R4Y1?from=project-issue) | [RK3568] When the mouse is connected and the screen is switched to landscape mode, the mouse movement direction and click position are inconsistent with the cursor position.|
| [IA9ONV](https://gitee.com/openharmony/window_window_manager/issues/IA9ONV?from=project-issue) | [RK3568] After the Back key is pressed to exit the application, the task widget on the multi-task screen does not show the last running UI screenshot.|
| [I9UKQ3](https://gitee.com/openharmony/applications_app_samples/issues/I9UKQ3?from=project-issue) | [RK3568] In the distributed relational database, clicking to connect a device results in an empty device list.|
| [I9UKNG](https://gitee.com/openharmony/applications_app_samples/issues/I9UKNG?from=project-issue) | [RK3568] [sample] [Browser] The Browser home page lacks a new button.|
| [I8TS8U](https://gitee.com/openharmony/kernel_liteos_a/issues/I8TS8U?from=project-issue) | [RK3568] Container testing is blocked.|
| [I9TJ5N](https://gitee.com/openharmony/multimodalinput_input/issues/I9TJ5N?from=project-issue) | [RK3568] There is a possibility that the volume bar disappears and the physical buttons do not work.|
| [I90FTY](https://gitee.com/openharmony/applications_launcher/issues/I90FTY?from=project-issue) | [RK3568] When renaming a folder on the home screen, the input name is not fully displayed.|
| [I9OETO](https://gitee.com/openharmony/update_update_app/issues/I9OETO?from=project-issue) | [RK3568] The "install later" and countdown buttons display a white screen without text.|
| [IAF5SS](https://gitee.com/openharmony/security_privacy_center/issues/IAF5SS?from=project-issue) | [RK3568] When a user enables or disables a user certificate in a dialog box, the dialog box is moved to the right, exceeding the screen.|
| [I9GLKF](https://gitee.com/openharmony/applications_app_samples/issues/I9GLKF?from=project-issue) | [RK3568] [Sample] During a phone call, detailed information about the call status does not contain the phone number.|
| [I9OZC2](https://gitee.com/openharmony/multimodalinput_input/issues/I9OZC2?from=project-issue) | [RK3568] When the mouse cursor style is set to 41 (corresponding to **pointer.PointerStyle.CURSOR_CIRCLE**), the mouse cursor becomes invisible.|
| [IA5EDU](https://gitee.com/openharmony/xts_acts/issues/IA5EDU?from=project-issue) | [RK3568] The XTS test suite ActsNativeAVScreenCaptureTest fails to execute in version 4.1.|
| [I9UKT8](https://gitee.com/openharmony/ability_dmsfwk/issues/I9UKT8?from=project-issue) | [RK3568] The version compatibility test suite DctsDmsHapTest has failed test cases.|
| [I9VJLA](https://gitee.com/openharmony/multimedia_audio_framework/issues/I9VJLA?from=project-issue) | [RK3568] The system fails to read recorded internal resources.|
| [I9F8M0](https://gitee.com/openharmony/applications_app_samples/issues/I9F8M0?from=project-issue) | [RK3568] In CertificateFramework, a maximum of 100 characters can be entered in the text box. However, the generated data can exceed this limit (for example, 592/100), which is not user-friendly.|
| [I9PK5K](https://gitee.com/openharmony/developtools_profiler/issues/I9PK5K?from=project-issue) | [RK3568] Double-clicking the curve chart in the test report causes the SP application to crash.|
| [I93ONW](https://gitee.com/openharmony/drivers_peripheral/issues/I93ONW?from=project-issue) | [RK3568] The resolution in the image names dumped by rkusb camera does not match the actual resolution.|
| [I9SSRV](https://gitee.com/openharmony/arkcompiler_runtime_core/issues/I9SSRV?from=project-issue) | [RK3568] The UT test runtime_core_host_unittest has failed items.|
| [I9PIQK](https://gitee.com/openharmony/applications_notes/issues/I9PIQK?from=project-issue) | [RK3568] When the indentation of the text in a memo is adjusted, saved, and the application is closed, the text appears without indentation upon reopening.|
| [I9QC3M](https://gitee.com/openharmony/xts_acts/issues/I9QC3M?from=project-issue) | [RK3568] There are defects in the ACTS test suite.|
| [I9R5MJ](https://gitee.com/openharmony/bundlemanager_bundle_framework/issues/I9R5MJ?from=project-issue) | [RK3568] After the **verifyAbc** interface is called to place an invalid .abc file, the abc file remains in the installation directory.|
| [I934K9](https://gitee.com/openharmony/testfwk_arkxtest/issues/I934K9?from=project-issue) | [RK3568]The assertPromiseIs assertion function behaves abnormally.|
| [I9PPPN](https://gitee.com/openharmony/systemabilitymgr_samgr/issues/I9PPPN?from=project-issue) | [RK3568] After log flushing is enabled and the device is restarted, the log "SystemWaitParameter failed!" is printed.|
| [I9Q6OD](https://gitee.com/openharmony/xts_dcts/issues/I9Q6OD?from=project-issue) | [RK3568] There is a possibility that the test suite in OpenHarmony 4.1 Release fails.|
| [I9NCRP](https://gitee.com/openharmony/drivers_hdf_core/issues/I9NCRP?from=project-issue) | [RK3568] The output of the **./hdf_dbg -q -1** command is abnormal.|
| [I9OWYO](https://gitee.com/openharmony/xts_acts/issues/I9OWYO?from=project-issue) | [RK3568] Some test cases in the security components fail.|

**Table 4** Fixed security vulnerabilities

| Issue No.                                                     | Issue Description                                                     |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| [IB3TKK](https://gitee.com/openharmony/third_party_wpa_supplicant/issues/IB3TKK?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-5290 in the wpa supplicant component|
| [IB8L9Y](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8L9Y?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-50150          |
| [IB8LVR](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8LVR?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-50228 in the Linux kernel component|
| [IB8MCA](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8MCA?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-50262 in the Linux kernel component|
| [IB8MEM](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8MEM?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-50301 in the Linux kernel component|
| [IB8NDV](https://gitee.com/openharmony/third_party_skia/issues/IB8NDV?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-8636 in the skia component|
| [IB8ND4](https://gitee.com/openharmony/third_party_skia/issues/IB8ND4?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-43091 in the skia component|
| [IB5RJE](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB5RJE?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-49883 in the Linux kernel component|
| [IB3RXG](https://gitee.com/openharmony/third_party_grpc/issues/IB3RXG?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2023-33953          |
| [IB2ZTU](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB2ZTU?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-50067          |
| [IAX809](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAX809?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-41049          |
| [IAQ16Y](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAQ16Y?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-44987          |
| [IAQ15E](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAQ15E?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-43882          |
| [I9TCEB](https://gitee.com/openharmony/build/issues/I9TCEB?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] Issues related to compiler security options in kosample.origin.ko|
| [I9UV4W](https://gitee.com/openharmony/third_party_openssl/issues/I9UV4W?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2023-4807            |
| [I9UVFZ](https://gitee.com/openharmony/third_party_zlib/issues/I9UVFZ?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2023-45853           |
| [I9UV9E](https://gitee.com/openharmony/third_party_openssl/issues/I9UV9E?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2023-5363            |
| [I9UUVH](https://gitee.com/openharmony/third_party_mbedtls/issues/I9UUVH?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-23775           |
| [IAI3T3](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3T3?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2023-52672          |
| [IAI3TF](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3TF?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-42160          |
| [IAI3VC](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3VC?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-41087          |
| [IAI3VS](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3VS?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-41012          |
| [IAI3XX](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3XX?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-42154          |
| [IAI3YK](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3YK?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-42161          |
| [IAI3SI](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3SI?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-36031          |
| [IAEK1E](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAEK1E?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-39495          |
| [IA4KT2](https://gitee.com/openharmony/kernel_linux_5.10/issues/IA4KT2?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-36894          |
| [IAAC05](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAAC05?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-38577          |
| [IAABZK](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAABZK?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-38588          |
| [IABPB5](https://gitee.com/openharmony/kernel_linux_5.10/issues/IABPB5?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-36971          |
| [I9TCOO](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCOO?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-27043 in the Linux kernel component|
| [I9TCEJ](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCEJ?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-26934          |
| [I9TC6R](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TC6R?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2021-47474          |
| [IA47RU](https://gitee.com/openharmony/kernel_linux_5.10/issues/IA47RU?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-36904          |
| [IA4BS6](https://gitee.com/openharmony/kernel_linux_5.10/issues/IA4BS6?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-36899          |
| [I9UZ0X](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9UZ0X?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2021-46996 in the Linux kernel component|
| [I9UYU0](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9UYU0?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2019-25162 in the Linux kernel component|
| [I9TCDG](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCDG?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2021-47479          |
| [I9TCCK](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCCK?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2021-47521          |
| [I9TCBF](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCBF?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2021-47506          |
| [I9TCAI](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCAI?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2021-47485          |
| [I9TC9M](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TC9M?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2021-47483          |
| [I9O1FB](https://gitee.com/openharmony/third_party_ffmpeg/issues/I9O1FB?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-31578          |
| [I9OU4B](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9OU4B?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-26883          |
| [I9OU4O](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9OU4O?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-26885          |
| [I9OU3Z](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9OU3Z?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-26884          |
| [I9OU3I](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9OU3I?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2022-48655          |
| [I9IVLW](https://gitee.com/openharmony/third_party_curl/issues/I9IVLW?from=project-issue) | [Vulnerability] [OpenHarmony-4.1-Release] CVE-2024-2398           |

## Known Issues

**Table 5** Known issues

| Issue No.| Issue Description | Impact| To Be Resolved By|
| :------- | :------- | :------- | :------- |
| / | /        | /    | /            |

 <!--no_check--> 