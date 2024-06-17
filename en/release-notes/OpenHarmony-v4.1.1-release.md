# OpenHarmony 4.1.1 Release


## Version Description

OpenHarmony 4.1.1 Release provides enhanced system stability over OpenHarmony 4.1 Release by rectifying certain known issues. The matching SDK version is also updated.

## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 4.1.1 Release | NA | 
| Public SDK | Ohos_sdk_public 4.1.7.8 (API Version 11 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.| 
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

Obtain the source code from the version tag, which is the same as that released with the version.
```
repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 4.1.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/code-v4.1.1-Release.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/code-v4.1.1-Release.tar.gz.sha256)| 31.9 GB |
| Hi3861 solution (binary)       | 4.1.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_pegasus.tar.gz.sha256)| 29.2 MB |
| Hi3516 solution-LiteOS (binary)| 4.1.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_taurus_LiteOS.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_taurus_LiteOS.tar.gz.sha256)| 318.7 MB |
| Hi3516 solution-Linux (binary) | 4.1.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_taurus_Linux.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_taurus_Linux.tar.gz.sha256)| 215.7 MB |
| RK3568 standard system solution (binary)       | 4.1.1 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/dayu200_standard_arm32.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/dayu200_standard_arm32.tar.gz.sha256)| 8.4 GB |
| Public SDK package for the standard system (macOS)            | 4.1.7.8 | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/ohos-sdk-mac-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/ohos-sdk-mac-public.tar.gz.sha256)| 841 MB |
| Public SDK package for the standard system (macOS-M1)            | 4.1.7.8  | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256)| 897.8 MB |
| Public SDK package for the standard system (Windows\Linux)  | 4.1.7.8   | [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/ohos-sdk-windows_linux-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/ohos-sdk-windows_linux-public.tar.gz.sha256)| 2.2 GB |


## What's New

This version does not involve API updates.

## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description| 
| -------- | -------- |
| I8WP8M | Create a large folder by moving an application icon on the home screen to overlap with another application icon, and then move an application icon out of the folder. Repeat this operation. Five minutes later, a total of about 25 MB memory is leaked on the launcher, that is, a 673.68 KB memory leak for each operation.|
| I9A089 | There is a moderate probability that system freezing occurs in the foundation process due to SERVICE_BLOCK.|
| I90A2N | There is a possibility that app freezing occurs in the com.ohos.systemui process because THREAD_BLOCK_6S is stuck in the libeventhandler.z.so stack.|
| I9CGOZ | There is a high probability that app freezing occurs in the com.ohos.camera process because THREAD_BLOCK_6S is stuck in the libcamera_framework.z.so stack.|
| I8QH9S | There is a low probability that a C++ crash occurs in libnative_appdatafwk.z.so of the os.settingsdata thread of the com.ohos.settingsdata process.|
| I963TL | There is a low probability that a C++ crash occurs in libark_jsruntime.so of the com.ohos.mms thread of the com.ohos.mms process.|
| I98KIG | There is a low probability that app freezing occurs in the com.ohos.camera process because THREAD_BLOCK_6S is stuck in the libcamera_framework.z.so stack.|

## Known Issues

**Table 4** Known issues

| Issue No.| Description| Impact| To Be Resolved By| 
| -------- | -------- | -------- | -------- |
| I98AV0 | Repeatedly turn on and then turn off the location information switch. When this operation lasts for 5 minutes, a total of about 14 MB memory is leaked on the distributeddata process, that is, a 95.57 KB memory leak for each operation.| The system freezes when the memory leak reaches a certain amount.<br>Workaround: Exit the current page.| June 30|
| I9A9NO | Repeatedly touch the upper right corner of the SMS application to create an SMS message and then touch **Back**. When this operation lasts for 5 minutes, a total of about 50 MB memory is leaked, that is, a 341.33 KB memory leak for each operation.| The system freezes when the memory leak reaches a certain amount.<br>Workaround: Exit the application.| June 30|
| I8QLRO | There is a low probability that a C++ crash occurs in libbtstack.z.so of the stack thread of the bluetooth_servi process.| The Bluetooth service automatically recovers, and users are unaware of the exception.| June 30|
| I8TLYJ | There is a low probability that a C++ crash occurs in libbtstack.z.so of the SaInit1 thread of the bluetooth_servi process.| The Bluetooth service automatically recovers, and users are unaware of the exception.| June 30|
| I8TM99 | There is a low probability that a C++ crash occurs in libbtframework.z.so of the softbus_server thread of the softbus_server process.| The DSoftBus service automatically recovers, and users are unaware of the exception.| June 30|
| I8VFJS | There is a low probability that a JS crash occurs in ObservedPropertyAbstractPU of the com.ohos.settings process.| There is a low probability that the Settings application crashes. Users can exit the application to reclaim the memory.| June 30|
| I98NGO | There is a low probability that app freezing occurs in the com.ohos.settings process because THREAD_BLOCK_6S is stuck in the libbtframework.z.so stack.| There is a low probability that the Settings application crashes. Users can exit the application to reclaim the memory.| June 30|
| I963UO | There is a possibility that a C++ crash occurs in libEGL.so of the RSRenderThread thread in the com.ohos.systemui process.| The screen automatically locks. The issue does not persist after users unlock the screen.| June 30|
| I9AYM2 | There is a low possibility that app freezing occurs in the com.ohos.note process because THREAD_BLOCK_6S is stuck in the libweb_engine.so stack.| The Notes application freezes. The issue does not persist after the application is restarted.| June 30|
| I9AEO0 | There is a low probability that app freezing occurs in the com.ohos.settings process due to APP_INPUT_BLOCK.| The Settings application does not respond. The issue does not persist after the application is restarted.| June 30|
| I9635I | There is a low probability that the device automatically restarts.| The impact is controllable. No workaround is required.| June 30|
| I96JJ7 | There is a low probability that a C++ crash occurs in libace_compatible.z.so of the com.ohos.note thread of the com.ohos.note process.| The Notes application may crash. The issue does not persist after the application is restarted.| June 30|
| I993H9 | There is a possibility that app freezing occurs in the com.ohos.smartperf process because THREAD_BLOCK_6S is stuck in the libglobal_resmgr.z.so stack.| When users use the SmartPerf application to view real-time performance data of other applications, the application freezes.<br>Workaround: The system automatically clears the application process. The issue does not persist after the application is restarted.| June 30|
| I97U6G | There is a low possibility that app freezing occurs in the com.ohos.certmanager process because THREAD_BLOCK_6S is stuck in the librender_service_client.z.so stack.| The system automatically exits the certificate management application when it is frozen. The impact is controllable.| June 30|
| I98NFR | There is a low probability that a C++ crash occurs in libwm.z.so of the ohos.smartperf thread of the com.ohos.smartperf process.| There is a low probability that the application exits. The issue does not persist after the application is restarted.| June 30|
| I98AWP | There is a low probability that a C++ crash occurs in libweb_engine.so of the com.ohos.note thread of the com.ohos.note process.| The Notes application may crash. The issue does not persist after the application is restarted.| June 30|
| I96ZWB | The peer device cannot be found after device networking.| When using the distributed audio service, OpenHarmony 4.0 and 4.1 devices cannot be compatible or interoperate with each other. The impact is controllable.| June 30|
| I96CJL | The networking between mini-system devices fails.| The impact is controllable, and no workaround is available.| June 30|
