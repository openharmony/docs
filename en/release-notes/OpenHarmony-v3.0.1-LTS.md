# OpenHarmony 3.0.1 LTS

## Version Description

OpenHarmony 3.0.1 LTS is a maintenance version with a tag of OpenHarmony 3.0 LTS. This version has rectified certain issues detected in OpenHarmony 3.0 LTS.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.0.1&nbsp;LTS | NA |
| SDK | 3.0.0.0 (API&nbsp;Version&nbsp;7&nbsp;release) | NA |
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Studio| 3.0&nbsp;Beta1 | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool| 2.2&nbsp;Beta2 | Recommended for developing OpenHarmony smart devices|


## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

Method 1 \(recommended\): Use the **repo** tool to download the source code over SSH. \(You must have an SSH public key for access to Gitee.\)

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.1-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the **repo** tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.1-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| LTS Code| Version| Mirror| SHA-256 Checksum|
| -------- | -------- | -------- | -------- |
| Full code base (for mini, small, and standard systems)| 3.0.1 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/code-v3.0.1-LTS.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/code-v3.0.1-LTS.tar.gz.sha256) |
| Standard system solution (binary)| 3.0.1 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/standard.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/standard.tar.gz.sha256) |
| Hi3861 solution (binary)| 3.0.1 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_pegasus.tar.gz.sha256) |
| Hi3518 solution (binary)| 3.0.1 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_aries.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_aries.tar.gz.sha256) |
| Hi3516 solution-LiteOS (binary)| 3.0.1 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_taurus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_taurus.tar.gz.sha256) |
| Hi3516 solution-Linux (binary)| 3.0.1 | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_taurus_linux.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_taurus_linux.tar.gz.sha256) |



## What's New

This version has the following updates to OpenHarmony 3.0 LTS.


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
| [I4BJFU](https://gitee.com/openharmony/kernel_liteos_a/issues/I4BJFU) | An error occurs when the dyload_posix module removes a file.|
| [I42N33](https://gitee.com/openharmony/third_party_mksh/issues/I42N33) | During the integration test, the Ctrl+C operation does not function after the **cat** command is run. A device restart is required.|
| [I4C8BO](https://gitee.com/openharmony/docs/issues/I4C8BO?from=project-issue) | The basic functions of the media subsystem (on a mini- or small-system device) are abnormal when Hi3516D V300 or Hi3518E V300 is burnt and configured by following the instructions in the official website.|
| I4BWKC | The camera driver on the Hi3516D V300 board does not function properly in the pressure test.|
| I4BW0G | The **ResetDriver** interface of the Hi3516D V300 board fails to be called.|
| [I4C7ZK](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4C7ZK) | For Hi3516D V300, the resident memory of the small system exceeds the baseline.|
| [I434P1](https://gitee.com/openharmony/multimedia_camera_lite/issues/I434P1) | For Hi3518E V300, the resident memory exceeds the baseline.|
| [I48IM7](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I48IM7) | During the HiLog pressure test, the hilogd restarts unexpectedly, and the hilog commands cannot be used.|
| I4EGMD | The serialization and deserialization methods of **Want** are defective.|
| [I4CED3](https://gitee.com/openharmony/account_os_account/issues/I4CED3) | The JS API returns both "err" and "data" in one message.|
| I4BXZ1 | The **\<Picker>** component does not respond to clicks.|
| I4CMMH | The display effect of the **\<Toggle>** component is abnormal.|
| I4CE7D | The response time of the edit box is inappropriate.|
| [I4HI4C](https://gitee.com/openharmony/ai_engine/issues/I4HI4C) | There is a failed item of the TDD test on a small-system device. This failure is caused by the inappropriate test case comparison time range.|
| [I4EUOW](https://gitee.com/openharmony/ai_engine/issues/I4EUOW) | The number of case execution threads is inappropriate.|
| I4HTFS | BMS adaptation for the mini system is not supported.|
| [I4C3BE](https://gitee.com/openharmony/communication_dsoftbus/issues/I4C3BE) | During passive Bluetooth Low Energy (BLE) discovery, the Bluetooth advertisement is frequently updated and, when the Bluetooth resources are used up, automatically disabled.|
| [I4I7QL](https://gitee.com/openharmony/developtools_packing_tool/issues/I4I7QL) | Packing fails when an ability has two widgets.|
| I4BW0G | There is a possibility that the Wi-Fi **ResetDriver** interface fails to be called.|
| [I4GBB6](https://gitee.com/openharmony/device_qemu/issues/I4GBB6) | The RISC-V QEMU emulator fails to run.|
| [I4CE7E](https://gitee.com/openharmony/kernel_liteos_a/issues/I4CE7E) | **drivers/mtd/multi_partition/** in the LiteOS-A kernel is implemented by using the driver functions in **device/hisilicon**.|
| I4JBEH | Memory leakage occurs when the DMA transmission interface of HDF is repeatedly used.|
| I4IGQ0 | Resources are released after component detection fails.|
| I4JPCG | The PWM backlight cannot be set to 0.|
| [I4ERM4](https://gitee.com/openharmony/drivers_peripheral/issues/I4ERM4) | A test case fails to be displayed.|
| [I4CMUY](https://gitee.com/openharmony/drivers_adapter_khdf_linux/issues/I4CMUY) | The hdf\_peripheral\_wlan\_test\_performance.bin test suite fails to run.|
| [I4FIP2](https://gitee.com/openharmony/kernel_liteos_a/issues/I4FIP2) | The **ioctl** function of the LiteOS_A kernel does not support the **SIOCGIFBRDADDR** option.|
| [I4GVF7](https://gitee.com/openharmony/kernel_liteos_a/issues/I4GVF7) | The permissions on the files and folders generated by the blackbox are inappropriate.|
| [I4EV8U](https://gitee.com/openharmony/kernel_liteos_a/issues/I4EV8U) | Three test cases, including IO_TEST_PPOLL_001, fail in the liteos\_a\_io\_unittest.bin\#IoTest module.|
| [I4EV3X](https://gitee.com/openharmony/kernel_liteos_a/issues/I4EV3X) | Seven test cases, including ItTestSys018, fail in the liteos\_a\_sys\_unittest.bin\#SysTest module.|
| [I4EVG0](https://gitee.com/openharmony/kernel_liteos_a/issues/I4EVG0) | The test case ItTestMisc009 fails in the liteos\_a\_misc\_unittest.bin\#MiscTest module.|
| [I4JYAX](https://gitee.com/openharmony/kernel_liteos_a/issues/I4JYAX) | The jffs2 adaptation layer incorrectly releases the lock.|
| [I4FIQW](https://gitee.com/openharmony/kernel_liteos_m/issues/I4FIQW) | The **ioctl** function of the LiteOS_M kernel does not support the **SIOCGIFBRDADDR** option.|
| [I4ELVA](https://gitee.com/openharmony/kernel_liteos_m/issues/I4ELVA) | The **read** interface at the VFS layer of the file system incorrectly determines whether **g_fs** is null.|
| [I4C6P2](https://gitee.com/openharmony/kernel_liteos_m/issues/I4C6P2) | The **LOS_QueueInfoGet** function incorrectly counts the tasks waiting to be read and written.|
| [I4C5RW](https://gitee.com/openharmony/kernel_liteos_m/issues/I4C5RW) | The error indicating that the **OS_TASK_STACK_PROTECT_SIZE** macro is not defined occurs when the MPU is enabled to protect the task stack.|
| [I4G4VK](https://gitee.com/openharmony/kernel_liteos_m/issues/I4G4VK) | Some macros are inappropriate. If they (for example, **inet_addr**) are changed to functions, the lwIP header file is not required for external calling.|
| [I4FVGV](https://gitee.com/openharmony/kernel_liteos_m/issues/I4FVGV) | The default lwIP configuration of the LiteOS_M kernel is inappropriate.|
| I4CE7D | There is no necessary to start the input method after a 3-second delay.|
| [I4CFOO](https://gitee.com/openharmony/multimedia_media_lite/issues/I4CFOO) | After an application running on the Linux system records videos for multiple times, the size of the last recording file is 0 when the system is restarted without exiting the application.|
| [I4CLGW](https://gitee.com/openharmony/kernel_liteos_a/issues/I4CLGW) | The page cache is inappropriate.|
| [I4HKQ2](https://gitee.com/openharmony/vendor_hisilicon/issues/I4HKQ2) | The mechanism for the LiteOS running on a mini-system board to obtain the UDID is inappropriate.|
| [I4FVJN](https://gitee.com/openharmony/startup_syspara_lite/issues/I4FVJN) | Mini system compilation fails because the dependency to mbedTLS is not added.|
| [I4CE7E](https://gitee.com/openharmony/kernel_liteos_a/issues/I4CE7E) | **drivers/mtd/multi_partition/** in the LiteOS-A kernel is implemented by using the driver functions in **device/hisilicon**.|

**Table 4** Issues resolved for the standard system

| Issue No.| Description|
| -------- | -------- |
| [I4BX4J](https://gitee.com/openharmony/hiviewdfx_hicollie/issues/I4BX4J?from=project-issue) | The Hi3516D V300 board fails to call the **hicollie** interface.|
| [I4BX1X](https://gitee.com/openharmony/hiviewdfx_hitrace/issues/I4BX1X?from=project-issue) | The Hi3516D V300 board fails to call the **hitrace** interface.|
| [I4BVUL](https://gitee.com/openharmony/communication_wifi/issues/I4BVUL?from=project-issue) | When access points (APs) are changed, the success rate for networking between standard-system devices and mobile phones is 91%, lower than the expected value (98%).|
| I4BW6E | During the test for networking between standard-system devices and mobile phones, when the mobile phone disables and enables the network access repeatedly for around 30 times, the networking fails.|
| [I4BVVW](https://gitee.com/openharmony/communication_dsoftbus/issues/I4BVVW) | During the test for networking between standard-system devices and mobile phones, when the Wi-Fi switch is turned on and off repeatedly, the networking success rate is 97%, lower than the expected value.|
| I48YPH | During the test for discovery and networking performance, 3 out of 110 networking attempts fails.|
| [I4492M](https://gitee.com/openharmony/communication_dsoftbus/issues/I4492M) | The offline device detection takes about 30s longer than the specifications.|
| I44W7U | The child window does not support zooming. As a result, the progress bar is hidden during video playback.|
| [I480Z1](https://gitee.com/openharmony/communication_dsoftbus/issues/I480Z1?from=project-issue) | Softbus_server crashes when executing **socketfuzz**.|
| I4BGLS | The key imported by using `import_signed_auth_info_hilink` is used for identifying the HiChain connection. After the key is imported, it is encrypted and stored in the file and is not cleared from the heap after being returned.|
| [I4A10Q](https://gitee.com/openharmony/startup_appspawn/issues/I4A10Q?from=project-issue) | The performance of Hi3516 3.0.0.6 static KPIs deteriorates severely.|
| I4BXYT | After device restart, developers must run the **hdc_std kill** command to discover the device again.|
| I4KUTY | There are invalid return values.|
| I4DMFV | The conversion from UTF-16 to UTF-8 is inappropriate.|
| [I4HGVM](https://gitee.com/openharmony/communication_dsoftbus/issues/I4HGVM) | The dependency on mbedTLS is missing for the standard system.|
| I4DLV2 | An invalid memory access error occurs due to the HidInfo\* type.|
| [I4CIJJ](https://gitee.com/openharmony/third_party_flutter/issues/I4CIJJ) | ACE does not support GPU rendering.|
| [I4G31Z](https://gitee.com/openharmony/third_party_freetype/issues/I4G31Z) | An update for the font engine version from 2.10.1 to 2.10.4 is unavailable.|
| [I4H06M](https://gitee.com/openharmony/third_party_harfbuzz/issues/I4H06M) | An update for the OpenType text shaping engine from 2.6.1 to 2.8.1 is unavailable.|
| [I4FS7V](https://gitee.com/openharmony/third_party_lwip/issues/I4FS7V) | The **LWIP\_NETCONN\_FULLDUPLEX** macro is not used to control the initialization of **conn-&gt;mbox\_threads\_waiting**.|
| I43KL7 | The synthesizer does not support GPU synthesis.|


## Known Issues

**Table 5** Known issues

| Issue No.| Description| Impact| To Be Resolved On|
| -------- | -------- | -------- | -------- |
| [I4NMXQ](https://gitee.com/openharmony/xts_acts/issues/I4NMXQ?from=project-issue) | The XTS test suites storagefileioperformancejstest and storagefilestabilityjstest cannot be automatically executed on a standard-system device.| This issue is caused by the XTS test suite framework. The test suites can only be manually executed. This issue does not affect functions.| 2022/01/30 |
| [I4NU92](https://gitee.com/openharmony/communication_wifi/issues/I4NU92) | Mini-system Hi3516_Linux: The ActsLwipTest.bin test suite has a failed test item.| The automatic test case fails to invoke the kernel to read time_out. This issue does not affect the communication function.| 2022/01/15 |
| [I4NTKG](https://gitee.com/openharmony/xts_acts/issues/I4NTKG) | Two failed items are displayed when the XTS test suite WeekPluralNumberTest is executed.| This is a test case issue and does not affect functions.| 2022/01/15 |
| [I4OWWM](https://gitee.com/openharmony/xts_acts/issues/I4OWWM) | The JSON file corresponding to the WeekPluralNumbertest module is incorrectly configured. During case execution, the error message "required device does not exist" is displayed.| The JSON file configuration is incorrect. This issue does not affect functions.| 2022/01/15 |
| [I4MSVV](https://gitee.com/openharmony/xts_acts/issues/I4MSVV?from=project-issue) | During the XTS test on the standard system, there are three failed items of the HiCollieCppTest cases in the ActsHiCollieCppTest module.| The test suite name is changed. As a result, the test case with the text verification function fails. This issue does not affect functions.| 2022/01/15 |
| [I4MSWM](https://gitee.com/openharmony/xts_acts/issues/I4MSWM?from=project-issue) | During the XTS test on the standard system, there is one failed item for faultloggertest in the ActsFaultLoggerTest module.| The test suite name is changed. As a result, the test case with the text verification function fails. This issue does not affect functions.| 2022/01/15 |
| I4NODO | During the test for the Hi3516 board running on a standard-system device, the E2E test of the distributed service hopping fails.| The DM component fails to repeatedly create a group. This issue affects the services that use hopping in the same way as that described in the issue details. Other services are not affected.| 2022/01/30 |
