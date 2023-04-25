# OpenHarmony 1.1.0 LTS \(2021-04-01\) (EOL)

## Overview

This is the first long-term support \(LTS\) version of OpenHarmony. It supports more functions and fixes some bugs in OpenHarmony 1.0.

-   OpenHarmony1.1.0 supports more subsystems, including the AI, power management, pan-sensor, and update subsystems.
-   OpenHarmony1.1.0 provides a unified AI engine framework.
-   The LiteOS Cortex-M kernel has been reconstructed for porting third-party chips to OpenHarmony.
-   The driver subsystem provides models for the WLAN, sensor, input, and display drivers.
-   The graphics subsystem has been optimized for an enhanced UI and improved performance and memory for the JS application framework.
-   The directory structure and module repositories have been significantly improved.

## Source Code Acquisition

### Acquiring Source Code from Mirrors

**Table  1**  Mirrors for acquiring source code

| Source Code              | Version Information | Mirror                                                       | SHA-256 Checksum                                             |
| ------------------------ | ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base           | 1.1.0               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz.sha256) |
| Hi3861 solution (binary) | 1.1.0               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz.sha256) |
| Hi3518 solution (binary) | 1.1.0               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz.sha256) |
| Hi3516 solution (binary) | 1.1.0               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz.sha256) |
| Release Notes            | 1.1.0               | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.0/OpenHarmony_Release_Notes_zh_cn.zip) | N/A                                                          |

### Acquiring Source Code Using the repo Tool

Run the following commands to download the source code:


```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony_release_v1.1.0 --no-repo-verify
repo sync -c
```

## What's New

This version inherits all features of OpenHarmony 1.0, and adds and optimizes features for different modules based on OpenHarmony 1.0. The following table lists the feature updates.

**Table  2**  Feature updates

| Type                     | New Features                                                 | Modified Features                                            | Deleted Features                                             |
| ------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Kernel                   | - The LiteOS Cortex-M kernel supports the Cortex-M7, Cortex-M33, and RISC-V chip architecture, and the corresponding samples are provided.<br/>- The LiteOS Cortex-M kernel supports the memory protection unit (MPU).<br/>- The LiteOS Cortex-M kernel supports some POSIX APIs.<br/>- The LiteOS Cortex-M kernel supports the FatFS file system.<br/>- The LiteOS Cortex-M kernel supports the registration of exception callbacks.<br/>- The architecture of the LiteOS Cortex-M kernel has been adjusted for third-party chips to adapt to OpenHarmony.<br/>- The LiteOS Cortex-M and LiteOS Cortex-A kernels support the heap memory debugging functionalities, covering memory leakage, illegal access to the memory, and memory statistics.<br/>- The LiteOS Cortex-M and LiteOS Cortex-A kernels support the TLSF heap memory algorithm, which improves the efficiency of memory application and release and reduces the fragmentation rate. | LiteOS Cortex-A scheduling has been optimized.               | None                                                         |
| Pan-sensor               | A sensor module has been added. You can now query the sensor list, enable or disable a sensor, subscribe to or unsubscribe from sensor data, set the data reporting mode of a sensor, and set sensor options such as the data sampling interval. | None                                                         | None                                                         |
| Globalization            | C/C++ APIs have been added for number, date, time, and singular-plural formatting in 79 languages. | None                                                         | None                                                         |
| JS Application Framework | - A global JavaScript UI attribute, **opacity**, has been added.<br/>- A **prompt.showDialog** API has been added.<br/>- A QR code component **qrcode** has been added.<br/>- Event pop-ups have been added. | - Internationalization has been improved, with quicker page redirections. Number internationalization and time/date conversions are now available.<br/>- The UI layout has been enhanced, with percentage values supported for some styles.<br/>- The size adaptation capabilities of the **input** and **switch** components have been enhanced.<br/>- The **image** component supports access to images in an application's private directory.<br/>- The **image-animator** component allows you to specify the end frame.<br/>- Some APIs have been made available for the **canvas** component.<br/>- Some return fields have been added for the **device.getInfo** API.<br/>- DFX can trace methods that encounter exceptions and output a list of such methods. | Backtracking is no longer supported for internationalization functions. |
| Testing                  | - The testing tool can filter test cases to execute based on the case level.<br/>- Demo test cases have been added. | None                                                         | None                                                         |
| Graphics                 | - Component rotation, scaling, and opacity management have been added.<br/>- Event pop-ups and the crown rotation event have been added.<br/>- There is now GIF image parsing and display, percentage-based width and height layout, and video and QR code components. | Partial rendering and SIMD performance have been optimized.  | None                                                         |
| Utils                    | - System attribute dumping is supported.<br/>- Memory pool management APIs have been added for upper-layer modules. | None                                                         | None                                                         |
| Driver                   | - The sensor, input, and display driver models have been added.<br/>- The MIPI DSI and pulse width modulation (PWM) have been added.<br/>- Hardware Device Interfaces (HDIs) and Wi-Fi flow control have been added.<br/>- The I/O service grouping feature has been added for the Hardware Driver Foundation (HDF). | Driver loading has been optimized. It can now be accomplished in segmented parts. | None                                                         |
| DSoftBus                 | - A Wi-Fi Aware module has been added.<br/>- IPC supports non-aligned marshalling. | None                                                         | None                                                         |
| Security                 | - HUKS provides the SHA-256, RSA-3072, RSA-2048, AES-128, and ECC security algorithms and APIs, as well as key management and storage.<br/>- The lightweight HiChain is available for managing and authenticating device groups without requiring login to devices using the same account, and for ensuring the communication security based on the Intelligent Soft Bus. It also provides APIs for system services and applications.<br/>- A unified permission management system has been added to manage permissions for lightweight devices. | None                                                         | None                                                         |
| AI                       | - A unified AI engine framework has been added to implement quick integration of AI algorithm plug-ins. The framework consists of plug-in management, module management, and communications management modules. This framework provides lifecycle management and allows for on-demand deployment of AI algorithms.<br/>- A developer guide, and two AI capability plug-ins developed based on the AI engine framework and two AI application samples are provided for you to quickly integrate AI algorithms in the AI engine framework. | None                                                         | None                                                         |
| Update                   | An update capability framework for mini-system devices has been added. It provides APIs for update package verification, parsing, and installation. | None                                                         | None                                                         |
| XTS                      | AI, DFX, globalization, and OTA compatibility test cases have been added. | Capabilities for the application framework, Intelligent Soft Bus, distributed scheduler, IoT, and kernel have been enhanced. | None                                                         |
| Compilation and Building | - The command line tool hb has been added. It provides the **hb set** and **hb build** commands for building in the source code directory or any subdirectory.<br/>- Components provided by independent chip vendors are supported.<br/>- Components can be built independently based on the component name.<br/>- The build toolchain and options can be customized for different development boards. | The product configuration has been decoupled from the **build_lite** repository and is stored in **vendor/solution vendor/product/config.json**. | None                                                         |
| Power Management         | - Battery level query is now supported.<br/>- Always-on screen functionalities have been added, along with corresponding APIs. | None                                                         | None                                                         |

The following table describes the optimization of repositories.

> **NOTE:** 
>-   Read-only archiving means archiving a module repository to the  **openharmony-retired**  organization and setting the repository to read-only.
>-   Code for third-party chips has been decoupled from the OS. HiSilicon chip SDKs have been moved from the  **vendor**  directory to the  **device/hisilicon**  directory.

**Table  3**  Optimization of repositories

| OpenHarmony1.0                                               | OpenHarmony1.1.0                              | Optimization                          |
| ------------------------------------------------------------ | --------------------------------------------- | ------------------------------------- |
| ace_lite_jsfwk                                               | ace_engine_lite                               | Repository renamed |
| ace_interfaces_innerkits_builtin                             | N/A                                           | Read-only archiving                   |
| N/A                                                          | ai_engine                                     | New module                            |
| hiviewdfx_frameworks_hievent_lite                            | hiviewdfx_hievent_lite                        | Repository renamed |
| hiviewdfx_frameworks_hilog_lite                              | hiviewdfx_hilog_lite                          | Repository renamed |
| hiviewdfx_utils_lite                                         | hiviewdfx_hiview_lite                         | Repository renamed |
| hiviewdfx_frameworks_ddrdump_lite                            | N/A                                           | Read-only archiving                   |
| hiviewdfx_interfaces_innerkits_hievent_<br/>lite             | N/A                                           | Read-only archiving                   |
| hiviewdfx_interfaces_innerkits_hilog                         | N/A                                           | Read-only archiving                   |
| hiviewdfx_interfaces_kits_hilog                              | N/A                                           | Read-only archiving                   |
| hiviewdfx_interfaces_kits_hilog_lite                         | N/A                                           | Read-only archiving                   |
| hiviewdfx_services_hilogcat_lite                             | N/A                                           | Read-only archiving                   |
| hiviewdfx_services_hiview_lite                               | N/A                                           | Read-only archiving                   |
| iothardware_hals_wifiiot_lite                                | N/A                                           | Read-only archiving                   |
| iothardware_interfaces_kits_wifiiot_lite                     | N/A                                           | Read-only archiving                   |
| iothardware_frameworks_wifiiot_lite                          | iothardware_peripheral                        | Repository renamed |
| N/A                                                          | applications_camera_sample_<br/>communication | New module                            |
| N/A                                                          | applications_camera_screensaver_<br/>app      | New module                            |
| N/A                                                          | sensors_miscdevice_lite                       | New module                            |
| N/A                                                          | sensors_sensor_lite                           | New module                            |
| xts_tools_lite                                               | xts_tools                                     | Repository renamed |
| security_services_iam_lite                                   | security_permission                           | Repository renamed |
| security_interfaces_innerkits_iam_lite                       | N/A                                           | Read-only archiving                   |
| security_interfaces_kits_iam_lite                            | N/A                                           | Read-only archiving                   |
| security_services_secure_os                                  | security_itrustee_ree_lite                    | Repository renamed |
| security_interfaces_innerkits_secure_os                      | N/A                                           | Read-only archiving                   |
| security_frameworks_secure_os                                | N/A                                           | Read-only archiving                   |
| security_services_app_verify                                 | security_appverify                            | Repository renamed |
| security_interfaces_innerkits_app_verify                     | N/A                                           | Read-only archiving                   |
| security_services_hichainsdk_lite                            | security_deviceauth                           | Repository renamed |
| security_interfaces_innerkits_hichainsdk_<br/>lite           | N/A                                           | Read-only archiving                   |
| security_services_huks_lite                                  | security_huks                                 | Repository renamed |
| security_interfaces_innerkits_huks_lite                      | N/A                                           | Read-only archiving                   |
| security_frameworks_crypto_lite                              | N/A                                           | Read-only archiving                   |
| security_interfaces_innerkits_crypto_lite                    | N/A                                           | Read-only archiving                   |
| N/A                                                          | signcenter_tool                               | New module                            |
| N/A                                                          | third_party_cryptsetup                        | New module                            |
| N/A                                                          | third_party_JSON-C                            | New module                            |
| N/A                                                          | third_party_libuuid                           | New module                            |
| N/A                                                          | third_party_LVM2                              | New module                            |
| N/A                                                          | third_party_popt                              | New module                            |
| communication_interfaces_kits_wifi_lite                      | N/A                                           | Read-only archiving                   |
| communication_frameworks_wifi_lite                           | N/A                                           | Read-only archiving                   |
| N/A                                                          | communication_wifi_lite                       | New module                            |
| N/A                                                          | powermgr_powermgr_lite                        | New module                            |
| distributedschedule_services_<br/>dtbschedmgr_lite           | distributedschedule_dms_fwk_lite              | Repository renamed |
| distributedschedule_services_safwk_lite                      | distributedschedule_safwk_lite                | Repository renamed |
| distributedschedule_services_samgr_lite                      | distributedschedule_samgr_lite                | Repository renamed |
| distributedschedule_interfaces_innerkits_<br/>samgr_lite     | N/A                                           | Read-only archiving                   |
| distributedschedule_interfaces_kits_samgr_<br/>lite          | N/A                                           | Read-only archiving                   |
| multimedia_frameworks_audio_lite                             | multimedia_audio_lite                         | Repository renamed |
| multimedia_frameworks_camera_lite                            | multimedia_camera_lite                        | Repository renamed |
| multimedia_frameworks_player_lite                            | multimedia_media_lite                         | Repository renamed |
| multimedia_hals_camera_lite                                  | N/A                                           | Read-only archiving                   |
| multimedia_frameworks_recorder_lite                          | N/A                                           | Read-only archiving                   |
| multimedia_interfaces_kits_audio_lite                        | N/A                                           | Read-only archiving                   |
| multimedia_interfaces_kits_camera_lite                       | N/A                                           | Read-only archiving                   |
| multimedia_interfaces_kits_player_lite                       | N/A                                           | Read-only archiving                   |
| multimedia_interfaces_kits_recorder_lite                     | N/A                                           | Read-only archiving                   |
| multimedia_services_media_lite                               | N/A                                           | Read-only archiving                   |
| kernel_liteos_a_huawei_proprietary_fs_<br/>proc              | N/A                                           | Read-only archiving                   |
| N/A                                                          | third_party_mksh                              | New module                            |
| N/A                                                          | third_party_optimized_routines                | New module                            |
| N/A                                                          | third_party_toybox                            | New module                            |
| vendor_huawei_camera                                         | N/A                                           | Read-only archiving                   |
| vendor_huawei_wifi_iot                                       | N/A                                           | Read-only archiving                   |
| startup_services_bootstrap_lite                              | startup_bootstrap_lite                        | Repository renamed |
| startup_frameworks_syspara_lite                              | startup_syspara_lite                          | Repository renamed |
| startup_hals_syspara_lite                                    | N/A                                           | Read-only archiving                   |
| startup_interfaces_kits_syspara_lite                         | N/A                                           | Read-only archiving                   |
| graphic_lite                                                 | graphic_surface_lite                          | Repository renamed |
| N/A                                                          | arkui_ui_lite                                 | Repository renamed module             |
| N/A                                                          | graphic_graphic_utils_lite                    | Repository renamed module             |
| N/A                                                          | window_manager_lite                           | Repository renamed module             |
| N/A                                                          | third_party_giflib                            | New module                            |
| N/A                                                          | third_party_qrcodegen                         | New module                            |
| N/A                                                          | drivers_adapter_khdf_linux                    | New module                            |
| drivers_hdf_lite                                             | drivers_adapter_khdf_liteos                   | Repository renamed |
| N/A                                                          | drivers_adapter_uhdf                          | New module                            |
| drivers_hdf_frameworks                                       | drivers_framework                             | Repository renamed |
| N/A                                                          | drivers_peripheral_audio                      | New module                            |
| N/A                                                          | drivers_peripheral_codec                      | New module                            |
| N/A                                                          | drivers_peripheral_display                    | New module                            |
| N/A                                                          | drivers_peripheral_format                     | New module                            |
| N/A                                                          | drivers_peripheral_input                      | New module                            |
| N/A                                                          | drivers_peripheral_sensor                     | New module                            |
| N/A                                                          | drivers_peripheral_wlan                       | New module                            |
| N/A                                                          | global_cust_lite                              | New module                            |
| N/A                                                          | global_i18n_lite                              | New module                            |
| global_frameworks_resmgr_lite                                | global_resmgr_lite                            | Repository renamed |
|                                                              | third_party_icu                               | New module                            |
| global_interfaces_innerkits_resmgr_lite                      | N/A                                           | Read-only archiving                   |
| communication_frameworks_ipc_lite                            | communication_ipc_lite                        | Repository renamed |
| communication_interfaces_kits_ipc_lite                       | N/A                                           | Read-only archiving                   |
| communication_interfaces_kits_<br/>softbuskit_lite           | N/A                                           | Read-only archiving                   |
| communication_hals_wifi_lite                                 | N/A                                           | Read-only archiving                   |
| communication_services_softbus_lite                          | communication_softbus_lite                    | Repository renamed |
| N/A                                                          | communication_wifi_aware                      | New module                            |
| N/A                                                          | update_sys_installer_lite                     | New module                            |
| vendor_hisi_hi35xx_hi35xx_init                               | device_hisilicon_build                        | Repository renamed |
| vendor_hisi_hi35xx_platform                                  | device_hisilicon_drivers                      | Repository renamed |
| vendor_hisi_hi35xx_hardware                                  | device_hisilicon_hardware                     | Repository renamed |
| vendor_hisi_hi35xx_hi3518ev300                               | device_hisilicon_hispark_aries                | Repository renamed |
| vendor_hisi_hi3861_hi3861                                    | device_hisilicon_hispark_pegasus              | Repository renamed |
| vendor_hisi_hi35xx_hi3516dv300                               | device_hisilicon_hispark_taurus               | Repository renamed |
| vendor_hisi_hi35xx_middleware                                | device_hisilicon_modules                      | Repository renamed |
| vendor_hisi_hi35xx_middleware_source_<br/>third_party_ffmpeg | device_hisilicon_third_party_ffmpeg           | Repository renamed |
| vendor_hisi_hi35xx_thirdparty_uboot_src                      | device_hisilicon_third_party_uboot            | Repository renamed |
| N/A                                                          | vendor_hisilicon                              | New module                            |
| vendor_hisi_hi35xx_hi3516dv300_uboot                         | N/A                                           | Read-only archiving                   |
| vendor_hisi_hi35xx_hi3518ev300_uboot                         | N/A                                           | Read-only archiving                   |
| aafwk_interfaces_innerkits_abilitykit_lite                   | N/A                                           | Read-only archiving                   |
| aafwk_interfaces_innerkits_intent_lite                       | aafwk_aafwk_lite                              | Repository renamed |
| aafwk_interfaces_innerkits_abilitymgr_<br/>lite              | N/A                                           | Read-only archiving                   |
| appexecfwk_kits_appkit_lite                                  | appexecfwk_appexecfwk_lite                    | Repository renamed |
| aafwk_frameworks_kits_ability_lite                           | -                                             | Read-only archiving                   |
|                                                              | developtools_packing_tool                     | New module                            |
| aafwk_interfaces_kits_ability_lite                           | N/A                                           | Read-only archiving                   |
| appexecfwk_frameworks_bundle_lite                            | N/A                                           | Read-only archiving                   |
| aafwk_services_abilitymgr_lite                               | N/A                                           | Read-only archiving                   |
| appexecfwk_interfaces_innerkits_<br/>appexecfwk_lite         | N/A                                           | Read-only archiving                   |
| appexecfwk_interfaces_innerkits_<br/>bundlemgr_lite          | N/A                                           | Read-only archiving                   |
| appexecfwk_services_bundlemgr_lite                           | N/A                                           | Read-only archiving                   |
| aafwk_frameworks_kits_content_lite                           | N/A                                           | Read-only archiving                   |

## Resolved Issues

The following table lists the issues known in OpenHarmony 1.0, which have been resolved in this version.

**Table  4**  Resolved issues

| Issue                                                        | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I3EALU](https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU) | [Multimedia] During execution of the cameraActs case, the camera configuration file cannot be found, and the initialization fails. |
| [I3EGUX](https://gitee.com/openharmony/release-management/issues/I3EGUX) | [Reliability] When the system is reset repeatedly, and the KIdle process crashes once, the system is suspended and cannot be started. |
| [I3DHIL](https://gitee.com/openharmony/community/issues/I3DHIL) | [System] The remaining space of the Hi3518 development board is insufficient, causing a failure in executing a large number of ACTS test cases. |

