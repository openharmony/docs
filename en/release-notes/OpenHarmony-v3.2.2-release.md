# OpenHarmony 3.2.2 Release


## Version Description

OpenHarmony 3.2.2 Release provides enhanced system security over OpenHarmony 3.2.1 Release by rectifying memory leak issues, certain known vulnerabilities in open-source components such as Linux kernel, and system stability issues. The matching SDK version is also updated.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool                             | Version                                            | Remarks                                                        |
| --------------------------------- | ------------------------------------------------ | ------------------------------------------------------------ |
| OpenHarmony                       | 3.2.2 Release                                    | NA                                                           |
| Public SDK                        | Ohos_sdk_public 3.2.13.5 (API Version 9 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio     | 3.1 Release                                      | Recommended for developing OpenHarmony applications<br>[Click here](https://developer.harmonyos.com/en/develop/deveco-studio#download)|
| (Optional) HUAWEI DevEco Device Tool| 3.1 Release                                      | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/en/develop/ide/).|

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

 ```
 repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2.2-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

Obtain the source code from the version tag, which is the same as that released with the version.
 ```
 repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2.2-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                             | Version | Mirror                                                | SHA-256 Checksum                                            |
| ------------------------------------- | ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base (for mini, small, and standard systems)     | 3.2.2 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/code-v3.2.2-Release_20230628.tar.gz)| [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/code-v3.2.2-Release.tar.gz_20230628.sha256) |
| Hi3861 solution (binary)             | 3.2.2 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_pegasus.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_pegasus.tar.gz.sha256) |
| Hi3516 solution-LiteOS (binary)      | 3.2.2 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_LiteOS.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516 solution-Linux (binary)       | 3.2.2 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_Linux.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568 standard system solution (binary)     | 3.2.2 Release | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/dayu200_standard_arm32.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/dayu200_standard_arm32.tar.gz.sha256) |
| Public SDK package for the standard system (macOS)          | 3.2.13.5      | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-mac-public.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-mac-public.tar.gz.sha256) |
| Public SDK package for the standard system (macOS-M1)       | 3.2.13.5      | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) |
| Public SDK package for the standard system (Windows\Linux)| 3.2.13.5      | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-windows_linux-public.tar.gz.sha256) |

## What's New

### API 

This version does not involve API updates.

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).

## Resolved Issues

**Table 3** Resolved issues

| Issue No.                                                    | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I70T6E](https://gitee.com/openharmony/web_webview/issues/I70T6E) | [OpenHarmony 3.2.12.2] [RK3568] [Pressure test] [ToC] [Low probability 1/10] [wukong] A C++ crash occurs in libweb_engine.so of the Chrome_IOThread thread in the com.ohos.note process. This problem occurs once. |
| [I76JRL](https://gitee.com/openharmony/drivers_peripheral/issues/I76JRL) | [OpenHarmony 3.2.11.9] [RK3568] [Pressure test] [ToC] [Low probability 1/10] [wukong] A C++ crash occurs in libcamera_pipeline_core.z.so of the offlinepipeline thread in the camera_host process. This problem occurs once. |
| [I7C0LX](https://gitee.com/openharmony/developtools_profiler/issues/I7C0LX) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [High probability 6/10] [wukong] A JS crash occurs in initDb of the com.ohos.smartperf process. This problem occurs 650 times. |
| [I7C0SA](https://gitee.com/openharmony/vendor_hihope/issues/I7C0SA) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [High probability] [wukong] A C++ crash occurs in libmali-bifrost-g52-g2p0-ohos.so of the RSRenderThread thread in the com.ohos.systemui process. This problem occurs 27 times. |
| [I7C10M](https://gitee.com/openharmony/security_privacy_center/issues/I7C10M) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [High probability 6/10] [wukong] A JS crash occurs in saveAllMaps of the com.ohos.certmanager process. This problem occurs 39 times. |
| I7CA2W                                                       | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [High probability] [wukong] A C++ crash occurs in libmedialibrary_data_extension.z.so of the com.ohos.medial thread in the com.ohos.medialibrary.medialibrarydata process. This problem occurs 358 times. |
| [I7CA7A](https://gitee.com/openharmony/distributeddatamgr_relational_store/issues/I7CA7A) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [High probability 8/10] [wukong] A C++ crash occurs in librdb_data_share_adapter.z.so of the IPC_2_4692 thread in the com.ohos.contactsdataability process. This problem occurs 1131 times. |
| [I7CBLV](https://gitee.com/openharmony/bundlemanager_bundle_framework/issues/I7CBLV) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [High probability] [wukong] A JS crash occurs in getFolderText and createRdbStore of the com.ohos.note process. This problem occurs 1249 times. |
| [I7CBWQ](https://gitee.com/openharmony/applications_mms/issues/I7CBWQ) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [Low probability] [wukong] Due to STRINGID: APPLICATION_BLOCK_INPUT, libeventhandler.z.so in the key process com.ohos.mms is stuck. This problem occurs 6 times. |
| [I7CWA0](https://gitee.com/openharmony/communication_ipc/issues/I7CWA0) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [Low probability] [wukong] A C++ crash occurs in libipc_core.z.so of the IPC_3_17363 thread in the key process com.ohos.contacts. This problem occurs once. |
| [I7CYM3](https://gitee.com/openharmony/applications_camera/issues/I7CYM3) | [OpenHarmony 3.2.13.1] [RK3568] [Pressure test] [ToC] [High probability 8/10] [wukong] A JS crash occurs in getInstance of the com.ohos.camera process. This problem occurs 1800 times. |


## Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.                                                       | Description                                           |
| ------------------------------------------------------------ | --------------------------------------------------- |
| I6QYVO | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2021-3923|
| I6QYVZ | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-28772|
| I6QYWE | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1281|
| I6RAW6 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-0590|
| I6UW4T | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-29156|
| I6UW51 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-2978|
| I6UW52 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-3176|
| I6UW55 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-45934|
| I6UW56 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-47521|
| I6VUAY | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2004|
| I6XC4Y | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2162|
| I6ZM02 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-0179|
| I70CNH | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2459|
| I70SLA | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1078|
| I722JK | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-0326|
| I722JP | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-0240|
| I722K2 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-42915|
| I722K4 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-42916|
| I722K6 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-32207|
| I722K8 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-32221|
| I722UD | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-32206|
| I722UL | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-25313|
| I722UN | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-25314|
| I722UP | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-25315|
| I722UV | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-25235|
| I722V1 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-25236|
| I722V6 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-23990|
| I722VB | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-23852|
| I722VJ | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2021-45960|
| I722VL | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2021-46143|
| I722VN | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-22822|
| I722VP | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-22824|
| I722VR | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-22823|
| I722VU | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-22827|
| I722WC | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-22825|
| I722WM | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-22826|
| I722WV | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2021-39275|
| I722X0 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2021-36160|
| I722X4 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2021-33193|
| I722XQ | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-21538|
| I72RUE | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-47518|
| I72SDD | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-3545|
| I72SDF | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-4696|
| I72SKQ | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-47519|
| I73C2J | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2513|
| I73C2O | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-28893|
| I73MW6 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-23222|
| I73MWI | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-32250|
| I73MWQ | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-34918|
| I73MX2 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-36946|
| I73PF6 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2726|
| I749IX | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2721|
| I74HC1 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-28320|
| I74HCG | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-28322|
| I74HD3 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-28321|
| I76NLQ | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2724|
| I76NLT | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2722|
| I77U26 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2021-43389|
| I77XID | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-25375|
| I78I9U | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-2588|
| I78R59 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-3635|
| I78R5B | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-3649|
| I79CK8 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2021-3600|
| I79LH8 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2650|
| I79NDI | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2936|
| I79NEF | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2937|
| I7A1M8 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-3006|
| I7AJ6J | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2935|
| I7AJ6M | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2933|
| I7AJ6P | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2931|
| I7AJ6S | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2932|
| I7AJ6W | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2929|
| I7AJHL | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2940|
| I7AJHO | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2941|
| I7AJHR | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2938|
| I7AJHU | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2939|
| I7AJHX | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2930|
| I7AJI0 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-2934|
| I7B049 | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-32643|
| I7B04Z | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-32636|
| I7B05A | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-32611|
| I7B05I | [Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-32665|


## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| ----- | -------- | ---- | ------------ |
| I6SXBI | [OpenHarmony 3.2.11.6] [RK3568] [Pressure test] [ToC] [Low probability] [wukong] A C++ crash occurs in libdistributeddata.z.so of the ohos.samples.distributedcalc process.| When a user exits the Calculator application within 1 second after opening it, the JS object is destructed before it is successfully read from the database. An error is recorded in the log, but the user is unaware of the error. End users are not affected.| 2023-07-15|
| I6TRE6 | There is a low probability that libdatashare_consumer.z.so crashes due to the com.ohos.contacts thread in the com.ohos.contacts process.| When a user exits the Contacts application within 600 ms after opening it, there is a low probability that the contacts process crashes. The contacts process will be automatically restarted after the crash. The impact is controllable.| 2023-07-15|
| I72P5E | Memory leakage occurs in libace.z.so when a user touches an image in Gallery to maximize it and then exits repeatedly.| Each time the user touches an image in Gallery to maximize it and then exits, 10 KB memory of the ArkUI module leaks. When the user touches Back on the application, the memory is reclaimed.| 2023-07-15|
| I72P5I | Memory leakage occurs in libace.z.so when a user touches an image folder in Gallery to browse images in grid form and then exits repeatedly.| Each time the user touches an image folder in Gallery to browse images in grid form and then exits, 19 KB memory of the ArkUI module leaks. When the user touches Back on the application, the memory is reclaimed.| 2023-07-15|
| I76N0Y | Memory leakage occurs in libace.z.so when applications are repeatedly added to or removed from the dock bar.| Each time a widget is moved to a valid area, 99 KB memory of the ArkUI module leaks. This operation scenario is uncommon, and the memory is reclaimed after the application is restarted.| 2023-07-15|
| I6XHE7 | Memory leakage occurs on the NAPIRemoteObject module.| When the JS application calls the IPC, the NAPIRemoteObject process needs to be created, and 1.2 KB memory occurs during the creation. However, the process can be used repeatedly once created, and the memory is released when the application process exits.| 2023-07-15|
| I7D4CH |  [OpenHarmony] [Experience test] [3.2.13.1] [RK3568] [ToC] [Probability: inevitably] The actual delay for starting the SMS application for the first time is 2537 ms, which is 237 ms longer than the baseline value (2300 ms).| To resolve the stability issue I7CBSM, the RDB data lock protection range is modified. As a result, the contacts loading time increases by about 9% on average. The impact is controllable, and this issue will be optimized in later versions.| 2023-07-15|
