# OpenHarmony 3.0.2 LTS


## Version Description

OpenHarmony 3.0.2 LTS is a maintenance version of OpenHarmony 3.0 LTS. This version has rectified certain issues and security vulnerabilities detected in OpenHarmony 3.0.1 LTS. It is the latest stable release with a tag.


## Version Mapping

  **Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.0.2&nbsp;LTS | NA |
| SDK | 3.0.0.0 (API&nbsp;Version&nbsp;7&nbsp;release) | NA |
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Studio| 3.0&nbsp;Beta1 | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool| 2.2&nbsp;Beta2 | Recommended for developing OpenHarmony smart devices|


## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

Method 1 \(recommended\): Use the **repo** tool to download the source code over SSH. \(You must have an SSH public key for access to Gitee.\)


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the **repo** tool to download the source code over HTTPS.


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

  **Table 2** Mirrors for acquiring source code

| LTS Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.0.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/code-v3.0.2-LTS.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/code-v3.0.2-LTS.tar.gz.sha256)|
| Standard system solution (binary)| 3.0.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/standard.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/standard.tar.gz.sha256) |
| Mini system Hi3861 solution (binary)| 3.0.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_pegasus.tar.gz.sha256) |
| Small system Hi3516 solution - LiteOS (binary)| 3.0.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_taurus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_taurus.tar.gz.sha256) |
| Small system Hi3516 solution - Linux (binary)| 3.0.2 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_taurus_linux.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_taurus_linux.tar.gz.sha256) |


## What's New

This version has the following updates to OpenHarmony 3.0.1 LTS.


### Feature Updates

This version does not involve feature updates.


### API Updates

This version does not involve API updates.


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


## Resolved Issues

  **Table 3** Issues resolved for the mini and small systems

| Issue No.| Description|
| -------- | -------- |
| [I4UZ7U](https://gitee.com/openharmony/xts_acts/issues/I4UZ7U?from=project-issue) | There may be 35 failed items during the XTS test on a small-system device.|
| [I4V2DN](https://gitee.com/openharmony/xts_acts/issues/I4V2DN?from=project-issue) | The execution of two test cases times out during the ActsLwipTest module test.|
| [I4V3KC](https://gitee.com/openharmony/xts_acts/issues/I4V3KC?from=project-issue) | The test case testPublish0010 fails in the Distributed Scheduler.|
| [I4URGA](https://gitee.com/openharmony/applications_sample_camera/issues/I4URGA?from=project-issue) | A blue screen may appear when users search for WLAN signals on the **Settings** page.|
| I4SDCK | An empty path or garbled characters are returned when users run **GetSrcPath** or **GetDataPath** on the Hi3516 development board of a small-system device.|
| [I4T6KZ](https://gitee.com/openharmony/communication_dsoftbus/issues/I4T6KZ) | The execution of **SendMessage** and **SendData4Data** fails during the transmission test.|
| I4UOUS | Plaintext passwords are printed in the logs of the serial port interface on the Hi3516 development board of a small-system device.|
| [I4OWZO](https://gitee.com/openharmony/third_party_toybox/issues/I4OWZO) | An error message is displayed when the **toybox mv** command is run to move a file in the NFS path.|
| [I4NCSF](https://gitee.com/openharmony/graphic_ui/issues/I4NCSF) | In the UI module of the Graphics subsystem, the linear pointer does not refresh in real time.|
| [I4NU92](https://gitee.com/openharmony/communication_wifi/issues/I4NU92) | There is one failed test item in the Hi3516 Linux ActsLwipTest.bin test suite.|
| [I4NVCK](https://gitee.com/openharmony/applications_sample_camera/issues/I4NVCK) | Audio capture does not function properly.|
| [I4NESQ](https://gitee.com/openharmony/kernel_liteos_a/issues/I4NESQ) | An error occurs during the los_disk_cache_clear conditional compilation.|
| [I4O67U](https://gitee.com/openharmony/kernel_liteos_a/issues/I4O67U) | All processes are terminated when **Ctrl+C** is pressed.|
| [I4R4D3](https://gitee.com/openharmony/kernel_liteos_m/issues/I4R4D3) | The **detach** attribute is not set for the thread created by **pthread_create**. After the thread proactively exits and **OsGetAllTskInfo** is invoked, the related task name contains garbled characters.|
| [I4R4A5](https://gitee.com/openharmony/kernel_liteos_m/issues/I4R4A5) | Compute overflow occurs in the implementation of the **pthread_cond_timedwait** interface.|
| [I4QJT4](https://gitee.com/openharmony/drivers_adapter_khdf_linux/issues/I4QJT4) | The UartRead test case fails.|
| I4U1DM | No lock is added when the LFQUE_Pop function is invoked by the QUEUE_Popfunction of samgr, causing potential data competition.|

  **Table 4** Issues resolved for the standard system

| Issue No.| Description|
| -------- | -------- |
| [I4UJNU](https://gitee.com/openharmony/applications_settings/issues/I4UJNU) | The WLAN password is displayed in plaintext in the hilog when the WLAN is connected.|
| [I4MSWM](https://gitee.com/openharmony/xts_acts/issues/I4MSWM?from=project-issue) | During the XT test, there is one failed item in the faultloggertest case of the ActsFaultLoggerTest module.|
| [I4MSVV](https://gitee.com/openharmony/xts_acts/issues/I4MSVV?from=project-issue) | During the XTS test, there are three failed items in the HiCollieCppTest case of the ActsHiCollieCppTest module.|
| I4PPXV | The application icon is missing after a user opens an application, exits the application, and then returns to the home screen.|
| [I4OF9A](https://gitee.com/openharmony/distributeddatamgr_file/issues/I4OF9A?from=project-issue) | The **text** value read by the **file.readText** interface is unstable.|
| [I4OWWM](https://gitee.com/openharmony/xts_acts/issues/I4OWWM) | The JSON file corresponding to the WeekPluralNumbertest module is incorrectly configured. When a test case is executed, "required device does not exist" is reported, and the test suite cannot be executed.|
| [I4OUVQ](https://gitee.com/openharmony/xts_tools/issues/I4OUVQ?from=project-issue) | During repeated pressure tests of XTS JS cases, the system stops responding and the test cannot continue.|
| [I4NMXQ](https://gitee.com/openharmony/xts_acts/issues/I4NMXQ?from=project-issue) | The storagefileioperformancejstest and storagefilestabilityjstest test suites fail to run on XTS.|
| [I4NTKG](https://gitee.com/openharmony/xts_acts/issues/I4NTKG) | Two failed items are displayed when the XTS test suite WeekPluralNumberTest is executed.|
| [I4NPHG](https://gitee.com/openharmony/xts_acts/issues/I4NPHG?from=project-issue) | The timer test suite TimerJSApiTest.hap is not compiled with the version.|


  **Table 5** Fixed security vulnerabilities

| Issue No.| Description|
| -------- | -------- |
| I4QT0K | Fixed the CVE-2021-44732 and CVE-2021-45450 security vulnerabilities of the third_party_mbedtls component.|
| I4NZ16 | Upgraded the third_party_sqlite component to 3.36.0, and fixed the CVE-2021-36690 security vulnerability.|
| I4NW0B | Fixed the CVE-2021-3522 security vulnerability of the third_party_gstreamer component.|
| I4SR8C | Fixed the CVE-2021-4160 security vulnerability of the third_party_openssl component.|
| I4U4B0 | Upgraded the third_party_expat component to 2.4.1, and fixed the security vulnerabilities such as CVE-2022-25313/25314/25315/25235/252256/23990/23852/22827/46143/45960.|
