# OpenHarmony 4.0.1 Release


## Version Description

OpenHarmony 4.0.1 Release provides enhanced system security over OpenHarmony 4.0 Release by rectifying functional issues, memory leak issues, and vulnerabilities in open-source components, and system stability issues. The matching SDK version is also updated.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 4.0.1 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.10.19 (API Version 10 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.0.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/code-v4.0.1-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/code-v4.0.1-Release.tar.gz.sha256) | 30.5 GB |
| Hi3861 solution (binary)       | 4.0.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_pegasus.tar.gz.sha256) | 27.3 MB |
| Hi3516 solution-LiteOS (binary)| 4.0.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 302.5 MB |
| Hi3516 solution-Linux (binary) | 4.0.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_taurus_Linux.tar.gz.sha256) | 193.2 MB |
| RK3568 standard system solution (binary)       | 4.0.1 Release  | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/dayu200_standard_arm32.tar.gz.sha256) | 5.2 GB |
| Public SDK package for the standard system (macOS)            | 4.0.10.19     | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/ohos-sdk-mac-public.tar.gz.sha256) | 2.0 GB |
| Public SDK package for the standard system (macOS-M1)            | 4.0.10.19    | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 800.7 MB |
| Public SDK package for the standard system (Windows\Linux)  | 4.0.10.19     | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.1 GB |

## Description

This version has the following updates to OpenHarmony 4.0 Release.

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [I7BF3M](https://gitee.com/open_harmony/dashboard?issue_id=I7BF3M) | [OpenHarmony 4.0.7.5] App freezing occurs on launcher because STRINGID:APPLICATION_BLOCK_INPUT is stuck in libeventhandler.z.so. This issue occurs 194 times.|
| [I7BFAQ](https://gitee.com/open_harmony/dashboard?issue_id=I7BFAQ) | [OpenHarmony 4.0.9.5] A C++ crash occurs on librender_service_base.z.so due to an error of the RSRenderThread thread in the com.ohos.photos process. This issue occurs 8 times.|
| [I7BFCE](https://gitee.com/open_harmony/dashboard?issue_id=I7BFCE) | [OpenHarmony 4.0.9.5] A C++ crash occurs on librender_service_base.z.so due to an error of the com.ohos.mms thread in the com.ohos.mms process. This issue occurs 8 times.|
| [I7HZKG](https://gitee.com/open_harmony/dashboard?issue_id=I7HZKG) | [OpenHarmony 4.0.8.3] A C++ crash occurs on libskia_canvaskit.z.so due to an error of the RSRenderThread thread in the msdp process. This issue occurs 10 times.|
| [I7QP4W](https://gitee.com/open_harmony/dashboard?issue_id=I7QP4W) | [OpenHarmony 4.0.9.6] A JS crash occurs on setShowContactName of the com.ohos.mms process. This issue occurs 10 times.|
| [I7QPBJ](https://gitee.com/open_harmony/dashboard?issue_id=I7QPBJ) | [OpenHarmony 4.0.9.6] A JS crash occurs on setReceiveContactValue of the com.ohos.mms process. This issue occurs 24 times.|
| [I7RBGF](https://gitee.com/open_harmony/dashboard?issue_id=I7RBGF) | [OpenHarmony 4.0.9.6] App freezing occurs on the com.ohos.camera process because THREAD_BLOCK_6S is stuck in libsamgr_proxy.z.so. This issue occurs 202 times.|
| [I7RSJJ](https://gitee.com/open_harmony/dashboard?issue_id=I7RSJJ) | [OpenHarmony 4.0.10.1] A C++ crash occurs on libgstreamer.z.so due to an error of the PlayerEngine thread of the media_service process. This issue occurs 12 times.|
| [I7S75S](https://gitee.com/open_harmony/dashboard?issue_id=I7S75S) | [OpenHarmony 4.0.10.1] A C++ crash occurs on libipc_core.z.so due to an error of the IPC_1_28750 thread of the wifi_manager_se process. This issue occurs 8 times.|
| [I7SAIU](https://gitee.com/open_harmony/dashboard?issue_id=I7SAIU) | [OpenHarmony 4.0.10.1] A C++ crash occurs on librender_service_base.z.so due to an error of the com.ohos.photos thread of the com.ohos.photos process. This issue occurs on 12 times.|
| [I7SCU4](https://gitee.com/open_harmony/dashboard?issue_id=I7SCU4) | [OpenHarmony 4.0.10.1] App freezing occurs on the com.ohos.photos process because THREAD_BLOCK_6S is stuck in libark_jsruntime.so. This issue occurs 20 times.|
| [I7TGTW](https://gitee.com/open_harmony/dashboard?issue_id=I7TGTW) | [OpenHarmony 4.0.10.2] A C++ crash occurs on libace.z.so due to an error of the com.ohos.photos thread of the com.ohos.photos process. This issue occurs on 443 times.|
| [I7UUBH](https://gitee.com/open_harmony/dashboard?issue_id=I7UUBH) | [OpenHarmony 4.0.10.3] [Application subsystem] [ToC] [RK3568] [High probability 5/10] When Airplane mode is quickly enabled and disabled for multiple times in Settings, the WLAN icon on Control Panel is on while WLAN is disabled in Settings.|
| [I7VBL8](https://gitee.com/open_harmony/dashboard?issue_id=I7VBL8) | [OpenHarmony 4.0.10.3] A C++ crash occurs on libcontactsdataability.z.so due to an error of the IPC_0_20828 thread of the com.ohos.contactsdataability process. This issue occurs 8 times.|
| [I7X7N7](https://gitee.com/open_harmony/dashboard?issue_id=I7X7N7) | [OpenHarmony 4.0.10.3] A C++ crash occurs on libsurface.z.so due to an error of the IPC_0_645 thread of the render_service process. This issue occurs 11 times.|
| [I7XKYN](https://gitee.com/open_harmony/dashboard?issue_id=I7XKYN) | [OpenHarmony 4.0.10.5] A C++ crash occurs on libweb_engine.so due to an error of the com.ohos.note thread of the com.ohos.note process. This issue occurs on 6 times.|
| [I7YRQG](https://gitee.com/open_harmony/dashboard?issue_id=I7YRQG) | [OpenHarmony_4.0.10.6] [USB service subsystem] [ToC] [RK3568] [Inevitable] The test_request test suite of the HDI interface is interrupted after eight test cases are executed.|
| [I814ML](https://gitee.com/open_harmony/dashboard?issue_id=I814ML) | [OpenHarmony 4.0.10.6] A C++ crash occurs on libmedia_service.z.so due to an error of the IPC_0_648 thread of the media_service process. This issue occurs 22 times.|
| [I815FD](https://gitee.com/open_harmony/dashboard?issue_id=I815FD) | [OpenHarmony 4.0.10.6] A C++ crash occurs on the ffrtwk/CPU-2-0 thread of the /system/bin/hdcd process. This issue occurs 14 times.|
| [I82CA5](https://gitee.com/open_harmony/dashboard?issue_id=I82CA5) | [OpenHarmony 4.0.10.7] A C++ crash occurs on libipc_core.z.so due to an error of the IPC_4_12571 thread of the wifi_manager_se process. This issue occurs 15 times.|
| [I82Q8W](https://gitee.com/open_harmony/dashboard?issue_id=I82Q8W) | [OpenHarmony 4.0.10.7] A C++ crash occurs on libsocket.z.so due to an error of the WorkerThread thread of the com.ohos.smartperf process. This issue occurs 8 times.|
| [I81MUU](https://gitee.com/open_harmony/dashboard?issue_id=I81MUU) | [OpenHarmony 4.0.10.7] [RK3568] [Pressure test] [ToC] [Inevitable 10/10] Memory leakage occurs when a user touches an image folder in Gallery to browse images in grid form and then exits repeatedly. The memory usage increases to 200 MB within 8 hours.|
| [I82DBO](https://gitee.com/open_harmony/dashboard?issue_id=I82DBO) | [OpenHarmony 4.0.10.7] [RK3568] [Pressure test] [ToC] [Inevitable 10/10] Memory leakage occurs when Wi-Fi is repeatedly enabled and disabled in Settings. The memory usage increases to 50 MB within 2 hours.|
| [I82HFQ](https://gitee.com/open_harmony/dashboard?issue_id=I82HFQ) | [OpenHarmony 4.0.10.7sp5] App freezing occurs on the ohos.samples.distributedmusicplayer process because the UI_BLOCK_6S thread is stuck in libmedia_client.z.so. This issue occurs 50 times.|
| [I82J4V](https://gitee.com/open_harmony/dashboard?issue_id=I82J4V) | [OpenHarmony 4.0.10.7] [RK3568] [Pressure test] [ToC] [High probability] [Manual] When an icon is dragged back and forth, a C++ crash occurs on libskia_canvaskit.z.so in the RSRenderThread thread of the msdp process.|
| [I84866](https://gitee.com/open_harmony/dashboard?issue_id=I84866) | [OpenHarmony 4.0.10.9sp1] The com.ohos.smartperf process is stuck in libace.z.so due to APP_INPUT_BLOCK. This issue occurs 61 times.|
| [I84QZZ](https://gitee.com/open_harmony/dashboard?issue_id=I84QZZ) | [OpenHarmony 4.0.10.9sp1] A C++ crash occurs on libcamera_pipeline_core.z.so due to an error of the collect#2 thread in the camera_host process. This issue occurs 9 times.|
| [I84R11](https://gitee.com/open_harmony/dashboard?issue_id=I84R11) | [OpenHarmony 4.0.10.9sp1] A C++ crash occurs on libcamera_host_vdi_impl_1.0.z.so due to an error of the IPC_5_24615 thread in the camera_host process. This issue occurs 16 times.|
| [I8661O](https://gitee.com/open_harmony/dashboard?issue_id=I8661O) | [OpenHarmony 4.0.10.10] App freezing occurs on the com.ohos.camera process because THREAD_BLOCK_6S is stuck in libsamgr_proxy.z.so. This issue occurs 335 times.|
| [I869MO](https://gitee.com/open_harmony/dashboard?issue_id=I869MO) | [OpenHarmony 4.0.10.10] [RK3568] [Pressure test] [ToC] [Inevitable 10/10] Memory leakage occurs in libmediaquery when a user repeatedly touches an image in Gallery to maximize it and then exits. The memory usage increases to 180 MB within 12 hours.|
| [I869WH](https://gitee.com/open_harmony/dashboard?issue_id=I869WH) | [OpenHarmony 4.0.10.10] A JS crash occurs in drawHighlighted of the com.ohos.smartperf process. This issue occurs 17 times.|
| [I86M99](https://gitee.com/open_harmony/dashboard?issue_id=I86M99) | [OpenHarmony 4.0.10.10] [RK3568] [Pressure test] [ToC] [Inevitable 10/10] Memory leak occurs on Foundation during the wukong test.|
| [I87XCI](https://gitee.com/open_harmony/dashboard?issue_id=I87XCI) | [OpenHarmony 4.1.2.1] App freezing occurs in the clock application. This issue occurs 16 times.       |
| [I88UHY](https://gitee.com/open_harmony/dashboard?issue_id=I88UHY) | [OpenHarmony 4.0.10.11sp1] The com.ohos.photos process is stuck in libmediaquery.z.so due to THREAD_BLOCK_6S. This issue occurs 8 times.|
| [I88UVQ](https://gitee.com/open_harmony/dashboard?issue_id=I88UVQ) | [OpenHarmony 4.0.10.10] [RK3568] [Pressure test] [ToC] [Inevitable 10/10] Memory leak occurs on WMS when Foundation is split during the wukong test.|
| [I890O6](https://gitee.com/open_harmony/dashboard?issue_id=I890O6) | [OpenHarmony_4.0.10.11] [Kernel subsystem] [ToC] [RK3568] [Inevitable 3/3] When traces are captured in the application sliding scenario, the stub point (H: HandleEndScene) in the trace is lost.|
| [I89EUH](https://gitee.com/open_harmony/dashboard?issue_id=I89EUH) | [OpenHarmony 4.0.10.11sp2] App freezing occurs on the com.ohos.camera process because THREAD_BLOCK_6S is stuck in libsamgr_proxy.z.so. This issue occurs 732 times.|
| [I89FA5](https://gitee.com/open_harmony/dashboard?issue_id=I89FA5) | [Weekly Branch] [RK3568] [Distributed Data] [ToC] [Inevitable 3/3] The DctsDistributedObjectDisJsTest test case fails.|
| [I89JHP](https://gitee.com/open_harmony/dashboard?issue_id=I89JHP) | [OpenHarmony 4.0 Release] [RK3568] [DSoftBus] [ToC] [Inevitable 3/3] The SUB_Softbus_Trans_Comp_SendBytes_Fun_0800 test case provides the same function but is not compatible with earlier versions.|
| [I8A7Y4](https://gitee.com/open_harmony/dashboard?issue_id=I8A7Y4) | [OpenHarmony_4.1.2.2] [USB service subsystem] [ToC] [RK3568] [Inevitable] The broadcast listening test case about port function switching used by test_usbevent cannot be executed, and an error is reported when the UT test suite is executed.|
| [I8AR1A](https://gitee.com/open_harmony/dashboard?issue_id=I8AR1A) | [OpenHarmony 4.0.10.11sp2] [4.0 Release] [Application subsystem] [RK3568] [Inevitable] The Gallery application functions abnormally.|
| [I8DD5M](https://gitee.com/open_harmony/dashboard?issue_id=I8DD5M) | [OpenHarmony 4.0.10.15] [Application subsystem] [RK3568] [Inevitable 5/5] Gallery widget covers cannot be automatically refreshed.|
| [I8DM2R](https://gitee.com/open_harmony/dashboard?issue_id=I8DM2R) | [OpenHarmony 4.0.10.13] App freezing occurs on the com.ohos.camera process because THREAD_BLOCK_6S is stuck in libcamera_framework.z.so. This issue occurs 924 times.|
| [I92HFJ](https://gitee.com/open_harmony/dashboard?issue_id=I92HFJ) | [OpenHarmony 4.0.10.16sp2] A C++ crash occurs on libipc_core.z.so in the wifi_manager_se process. This issue occurs 77 times.|
| [I957IR](https://gitee.com/open_harmony/dashboard?issue_id=I957IR) | [OpenHarmony 4.0.10.16sp2] App freezing occurs on THREAD_BLOCK_6S in the ohos.samples.etsclock process. This issue occurs 43 times.|
| [I9H8J6](https://gitee.com/open_harmony/dashboard?issue_id=I9H8J6) | It takes a longer time for the file management subsystem to call the OpenSSL interface during startup than that in 4.0.10.11.|
| [I90FM1](https://gitee.com/open_harmony/dashboard?issue_id=I90FM1) | [Pressure test] A C++ crash occurs on libipc_core.z.so due to an error of the IPC_2_2577 thread of the wifi_manager_se process. This issue occurs 42 times.|

## Fixed Security Vulnerabilities

**Table 4** Fixed security vulnerabilities

| Issue No.                                                       | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I6U81V](https://gitee.com/open_harmony/dashboard?issue_id=I6U81V) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-30456          |
| [I6V7QA](https://gitee.com/open_harmony/dashboard?issue_id=I6V7QA) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-1829            |
| [I6V7V2](https://gitee.com/open_harmony/dashboard?issue_id=I6V7V2) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-1872            |
| [I6X3GE](https://gitee.com/open_harmony/dashboard?issue_id=I6X3GE) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-2002           |
| [I6Y8IE](https://gitee.com/open_harmony/dashboard?issue_id=I6Y8IE) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-2194            |
| [I6ZJDC](https://gitee.com/open_harmony/dashboard?issue_id=I6ZJDC) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-31436          |
| [I6ZUSY](https://gitee.com/open_harmony/dashboard?issue_id=I6ZUSY) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-2248           |
| [I708T3](https://gitee.com/open_harmony/dashboard?issue_id=I708T3) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-2124            |
| [I70B17](https://gitee.com/open_harmony/dashboard?issue_id=I70B17) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-2483           |
| [I71KHX](https://gitee.com/open_harmony/dashboard?issue_id=I71KHX) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-32233          |
| [I7FM6A](https://gitee.com/open_harmony/dashboard?issue_id=I7FM6A) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-35788            |
| [I7SZTB](https://gitee.com/open_harmony/dashboard?issue_id=I7SZTB) | [Vulnerability][OpenHarmony_4.0.10.2] CVE-2015-8955               |
| [I7SZWH](https://gitee.com/open_harmony/dashboard?issue_id=I7SZWH) | [Vulnerability][OpenHarmony_4.0.10.2] CVE-2023-4128               |
| [I7XCCQ](https://gitee.com/open_harmony/dashboard?issue_id=I7XCCQ) | [Vulnerability][OpenHarmony_4.0.10.5] CVE-2022-40982              |
| [I934PZ](https://gitee.com/open_harmony/dashboard?issue_id=I934PZ) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2024-23775          |
| [I93ART](https://gitee.com/open_harmony/dashboard?issue_id=I93ART) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-43615          |
| [I944MQ](https://gitee.com/open_harmony/dashboard?issue_id=I944MQ) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2024-25062          |
| [I94IJY](https://gitee.com/open_harmony/dashboard?issue_id=I94IJY) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2024-24806          |
| [I952U8](https://gitee.com/open_harmony/dashboard?issue_id=I952U8) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2024-762126596168486912|
| [I966TM](https://gitee.com/open_harmony/dashboard?issue_id=I966TM) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2024-762126168387227648|
| [I966UT](https://gitee.com/open_harmony/dashboard?issue_id=I966UT) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2024-762133623825502208|
| [I9BS9L](https://gitee.com/open_harmony/dashboard?issue_id=I9BS9L) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-52444           |
| [I9BUAF](https://gitee.com/open_harmony/dashboard?issue_id=I9BUAF) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2019-19768          |
| [I9C46A](https://gitee.com/open_harmony/dashboard?issue_id=I9C46A) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2023-52438          |
| [I9F1XE](https://gitee.com/open_harmony/dashboard?issue_id=I9F1XE) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2021-45485          |
| [I9FE7O](https://gitee.com/open_harmony/dashboard?issue_id=I9FE7O) | [Vulnerability][OpenHarmony 4.0 Release] CVE-2022-3566            |
| [I818FO](https://gitee.com/open_harmony/dashboard?issue_id=I818FO) | [Vulnerability][OpenHarmony 4.0.10.7] CVE-2023-21636              |
| [I818G7](https://gitee.com/open_harmony/dashboard?issue_id=I818G7) | [Vulnerability][OpenHarmony_4.0.10.7] CVE-2023-4881               |

## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I827LU | Memory leakage occurs when Bluetooth is repeatedly enabled and disabled in Settings. A memory leak of 15 MB occurs within one hour.| A memory leak of 8.3 KB occurs for one Bluetooth enable/disable operation. This issue can be resolved by restarting the device. The impact is controllable.<br>You are advised to use the protocol stack of the Bluetooth module built in the chip or hardware to avoid this issue.| May 30|
