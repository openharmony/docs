# OpenHarmony 3.2.1 Release


## Version Description

OpenHarmony 3.2.1 Release provides the following enhancements over OpenHarmony 3.2 Release:
According to security compliance requirements, UUIDs are used only for system applications and SAs, no longer for common applications. New UUIDs (sha256(appId_uuid)) that can be used by common applications are used in distributed data management.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.2.1 Release | NA |
| Public SDK | Ohos_sdk_public 3.2.12.5 (API Version 9 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio| 3.1 Release | Recommended for developing OpenHarmony applications<br>[Click here](https://developer.harmonyos.com/en/develop/deveco-studio#download)|
| (Optional) HUAWEI DevEco Device Tool| 3.1 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/en/develop/ide/).|

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
 repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2.1-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

Obtain the source code from the version tag, which is the same as that released with the version.
 ```
 repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2.1-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 3.2.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/code-v3.2.1-Release.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/code-v3.2.1-Release.tar.gz.sha256)| 21.8 GB |
| Hi3861 solution (binary)       | 3.2.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_pegasus.tar.gz.sha256)| 22.9 MB |
| Hi3516 solution-LiteOS (binary)| 3.2.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_taurus_LiteOS.tar.gz.sha256)| 293.3 MB |
| Hi3516 solution-Linux (binary) | 3.2.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_taurus_Linux.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_taurus_Linux.tar.gz.sha256)| 174.6 MB |
| RK3568 standard system solution (binary)       | 3.2.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/dayu200_standard_arm32.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/dayu200_standard_arm32.tar.gz.sha256)| 3.9 GB |
| Public SDK package for the standard system (macOS)            | 3.2.12.5      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/ohos-sdk-mac-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/ohos-sdk-mac-public.tar.gz.sha256)| 664.5 MB |
| Public SDK package for the standard system (macOS-M1)            | 3.2.12.5      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/L2-SDK-MAC-M1-PUBLIC.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256)| 623.3 MB |
| Public SDK package for the standard system (Windows\Linux)  | 3.2.12.5      | [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/ohos-sdk-windows_linux-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/3.2.1/ohos-sdk-windows_linux-public.tar.gz.sha256)| 1.6 GB |

## What's New

### API 

This version does not involve API updates.

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).

## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| I6U1H9 | The **gridColOffset** attribute of the **\<GridCol>** component cannot be previewed in the previewer of DevEco Studio.|
| I6TMP3 | When a user holds an application to access image preview, swipes backwards about 150 widgets, and touches to add a widget, the widget may not be displayed on the home screen.|
| I6RJTP | A user touches a Bluetooth headset on the Bluetooth screen of the device for connection. When the status is Connecting, the user cannot disable the Bluetooth feature. The screen does not respond or even crashes.|
| I6TFXF | [Pressure test] [Low probability] The sysevent_service thread in the /system/bin/hiview process causes a crash in libjsoncpp.z.so. This problem occurs once.|
| I6TS20 | [Pressure test] [Low probability] The Chrome_IOThread thread in the com.ohos.note process causes a C++ crash in libweb_engine.so. This problem occurs twice.|
| I6TS25 | [Pressure test] [Low probability] The com.ohos.note thread in the com.ohos.note process causes a C++ crash in libweb_engine.so. This problem occurs once.|
| I6A80S | The Weibo pages loaded by the **\<Web>** component are abnormal.|
| I6VRJ8 | [High probability] [Wukong] The Chrome_IOThread thread in the com.ohos.note process causes a C++ crash in libweb_engine.so. This problem occurs eight times. |
| I6YJHC | [High probability] [Wukong] The com.ohos.note thread in the com.ohos.note process causes a C++ crash in ld-musl-arm.so.1. This problem occurs nine times.|
| I6YT0V | [High probability] [Wukong] The RSRenderThread thread in the com.ohos.note process causes a C++ crash in libeventhandler.z.so. This problem occurs six times. |
| I6YSP4 | [Low probability 1/10] [Wukong] The com.ohos.note thread in the com.ohos.note process causes a crash in librender_service_base.z.so. This problem occurs once.|
| I6Z5XW | [High probability 8/10] When more than 10 drafts are created and then deleted one by one, memory leakage occurs in com.ohos.mms.|
| I6YZGA | [Low probability 1/10] [Wukong] The RSRenderThread thread in the com.ohos.note process causes a C++ crash in libskia_ohos.z.so. This problem occurs four times.|
| I64726<br>I641A2 | When the **bluetooth.pairDevice** API is called, no prompt indicating successful pairing is displayed. The device is paired in silent mode, and the device can be controlled using the Bluetooth keyboard and mouse.|
| I6TRY1 | [Low probability] [Wukong] The com.ohos.note thread in the com.ohos.note process causes a C++ crash in libace.z.so. This problem occurs once.|
| I6TS3O | [Low probability] [Wukong] App freezing occurs in the libace.z.so stack of the com.ohos.contacts process. This problem occurs three times.|
| I6TFT1 | [Low probability] A JS crash occurs in the anonymous/AssertException stack of the com.example.actsgetcurrenttopabilitystageatest process. This problem occurs twice.|
| I6TFUX | [Low probability] [Wukong] The events_emitter thread in the com.open.harmony.acetestfour process causes a crash in libemitter.z.so. This problem occurs once.|
| I6TFXY | [Low probability] A JS crash occurs in the AssertException stack of the com.example.abilitymultiinstance process, and a JS crash occurs in the AssertException stack of the com.example.startabilityforresult process. This problem occurs three times.|
| I6TGJ2 | [Low probability] The usage_event_rep thread in the /system/bin/hiview process causes a crash in libhiviewbase.z.so. This problem occurs twice.|
| I6TR29 | [Low probability] [Wukong] The com.ohos.smartp thread in the com.ohos.smartperf process causes a crash in libace.z.so. This problem occurs once.|
| I6TS0D | [Low probability] The Chrome_IOThread thread in the com.ohos.note process causes a C++ crash in libace.z.so. This problem occurs once.|
| I6TS20 | [Low probability] The Chrome_IOThread thread in the com.ohos.note process causes a C++ crash in libweb_engine.so. This problem occurs twice.|
| I6TS25 | [Low probability] The com.ohos.note thread in the com.ohos.note process causes a C++ crash in libweb_engine.so. This problem occurs once.|
| I6TUR9 | [Pressure test] [High probability] App freezing occurs in the com.ohos.mms process. This problem occurs 10 times.|
| I6TVCX | [Pressure test] [High probability] Memory leakage occurs on the SystemUI and the memory usage increases.|
| I6T09Y | [Pressure test] [Low probability] The com.ohos.camera thread in the com.ohos.camera process causes a crash in libpluginmanager.z.so. This problem occurs once.|
| I6T0EO | [Pressure test] [Low probability] A JS crash occurs twice in the com.ohos.mms process.|
| I6TKQP | [Low probability] [Wukong] The com.ohos.note thread in the com.ohos.note process causes a crash in libace.z.so. This problem occurs once.|
| I6TNY9 | When the call log is full, the dialer cannot be hidden if a user swipes up.|
| I6TRW7<br>I6TRRX<br>I6TRHA<br>I6TRH3<br>I6TRGZ<br>I6TRGO<br>I6TRGJ<br>I6TRGG<br>I6TRGD<br>I6TRG9<br>I6TRG6<br>I6TIFP<br>I6TBIR<br>I6RQLV<br>I6RQLT<br>I6QYZS<br>I6QYZR<br>I6QYZI<br>I6QYZG<br>I6QYZF<br>I6QYZ9<br>I6QYZ7<br>I6TRHE<br>I6TRH7<br>I6TRGV<br>I6TRGS<br>I6TRG2 | [Vulnerability] [OpenHarmony-3.2-Release] lj-oss-fuzz-132<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1652<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1815<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1823<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1817<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1819<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1822<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1816<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1821<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1813<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1814<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-28464<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2022-48434<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-0466<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-0465<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-27535<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-27533<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-27536<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-27538<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-27537<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-27534<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-0464<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1812<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1818<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1811<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1820<br>[Vulnerability] [OpenHarmony-3.2-Release] CVE-2023-1810|


## Known Issues

**Table 4** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I6B4U3 | There is a low probability (3/10) that app freezing occurs in the com.ohos.launcher process.| When a large number of applications are installed (more than 40 applications) and the memory is small, there is a low probability that app freezing occurs. However, the home screen functions are normal and the overall functions and usage are not affected.| 2023-06-15|
| I6SXBI | There is a low probability that libdistributeddata.z.so in the ohos.samples.distributedcalc process causes a C++ crash.| When a user exits the Calculator application within 1 second after opening it, the JS object is destructed before it is successfully read from the database. An error is recorded in the log, but the user is unaware of the error. The impact is controllable.| 2023-07-15|
| I6TRE6 | There is a low probability that libdatashare_consumer.z.so crashes due to the com.ohos.contacts thread in the com.ohos.contacts process.| When a user exits the Contacts application within 600 ms after opening it, there is a low probability that the contacts process crashes. The contacts process will be automatically restarted after the crash. The impact is controllable.| 2023-07-15|
| I6SMQA | When a user uses a browser application to open a WeiBo page and swipes the screen quickly, jitter occurs during swiping.| The content is not loaded during swiping but will be loaded quickly. User experience is affected.| 2023-06-15|
| I72P5E | Memory leakage occurs in libace.z.so when a user touches an image in Gallery to maximize it and then exits repeatedly.| Each time the user touches an image in Gallery to maximize it and then exits, 10 KB memory of the ArkUI module leaks. When the user touches Back on the application, the leak issue disappears. The impact is controllable.| 2023-07-15|
| I72P5I | Memory leakage occurs in libace.z.so when a user touches an image folder in Gallery to browse images in grid form and then exits repeatedly.| Each time the user touches an image folder in Gallery to browse images in grid form and then exits, 19 KB memory of the ArkUI module leaks. When the user touches Back on the application, the leak issue disappears. The impact is controllable.| 2023-07-15|
| I76N0Y | Memory leakage occurs in libace.z.so when applications are repeatedly added to or removed from the dock bar.| Each time a widget is moved to a valid area, 99 KB memory of the ArkUI module leaks. This operation scenario is uncommon, and the leak issue disappears after the application is restarted. The impact is controllable.| 2023-07-15|
| I6XHE7 | Memory leakage occurs on the NAPIRemoteObject module.| When the JS application calls the IPC, the NAPIRemoteObject process needs to be created, and 1.2 KB memory occurs during the creation. However, the process can be used repeatedly once created, and the memory is released when the application process exits.| 2023-07-15|
