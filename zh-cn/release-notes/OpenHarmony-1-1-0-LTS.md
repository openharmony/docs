# OpenHarmony 1.1.0 LTS（2021-04-01）(停止维护)

## 版本概述

首次发布LTS（long-term support）长期支持版本OpenHarmony 1.1.0，本版本在1.0版本的基础上新增了部分功能和修复了部分缺陷。

-   OpenHarmony1.1.0扩充组件能力，新增AI子系统、电源管理子系统、泛Sensor子系统、升级子系统。
-   OpenHarmony1.1.0有了统一AI引擎框架。
-   liteos-m内核完成三方可移植性重构。
-   驱动子系统完善了WIFI、Sensor、Input、Display的驱动模型。
-   图形子系统针对UI能力及JS框架性能和内存得到优化。
-   对目录结构及组件仓做了大幅优化。

## 源码获取

### 通过镜像站点获取

**表 1**  源码获取路径

| 版本源码                 | 版本信息 | 下载站点                                                     | SHA256校验码                                                 |
| ------------------------ | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码                 | 1.1.0    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz) | [SHA256 校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz.sha256) |
| Hi3861解决方案（二进制） | 1.1.0    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz) | [SHA256 校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz.sha256) |
| Hi3518解决方案（二进制） | 1.1.0    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz) | [SHA256 校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz.sha256) |
| Hi3516解决方案（二进制） | 1.1.0    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz) | [SHA256 校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz.sha256) |
| Release Notes            | 1.1.0    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.0/OpenHarmony_Release_Notes_zh_cn.zip) | -                                                            |


### 通过repo下载

下载命令如下：

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony_release_v1.1.0 --no-repo-verify
repo sync -c
```

## 更新说明

本版本完全继承了OpenHarmony 1.0的所有特性，并在OpenHarmony 1.0版本的基础上，对各模块进行了功能扩展和优化，详情请参考下表 。

**表 2**  特性更新说明

| 类别           | 新增特性                                                     | 修改特性                                                     | 删除特性                     |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------- |
| 内核           | - LiteOS-M支持Cortex-M7、Cortex-M33和RISC-V芯片架构，新增对应的单板target样例。<br/>- LiteOS-M支持MPU功能。<br/>- LiteOS-M支持部分POSIX接口。<br/>- LiteOS-M支持FatFS文件系统。<br/>- LiteOS-M支持异常回调函数注册机制。<br/>- LiteOS-M三方芯片易适配性架构调整。<br/>- LiteOS-M、LiteOS-A支持堆内存调测功能，包括内存泄漏、踩内存、内存统计。<br/>- LiteOS-M、LiteOS-A支持TLSF堆内存算法，提高内存申请和释放效率，降低碎片率。 | LiteOS-A调度优化。                                           | None                         |
| 泛Sensor       | 新增Sensor组件，提供了Sensor列表查询、Sensor启停、Sensor订阅/去订阅、设置数据上报模式、设置采样间隔等功能。 | None                                                         | None                         |
| 全球化         | 新增79种语言的数字格式化、日期和时间格式化、单复数C/C++国际化接口。 | None                                                         | None                         |
| JS应用开发框架 | - 新增JS前端opacity全局属性支持。<br/>- 新增prompt.showDialog API。<br/>- 新增二维码组件qrcode。<br/>- 新增事件冒泡机制 | - 国际化性能优化，加速页面跳转，支持数字国际化及时间日期转换。<br/>- 前端布局能力增强，部分样式值支持设置百分比。<br/>- input及switch组件尺寸自适应能力增强。<br/>- image组件能力增强，支持显示应用私有数据目录图片。<br/>- image-animator组件能力增强，支持结束帧指定。<br/>- canvas组件能力增强，新增部分API。<br/>- device.getInfo API增强，新增部分返回字段。<br/>- DFX能力增强，支持跟踪异常的方法栈。 | 国际化功能不再支持回溯特性。 |
| 测试           | - 新增测试工具按照用例级别筛选要执行的测试用例。<br/>- 新增测试demo用例。 | None                                                         | None                         |
| 图形           | - 新增组件级旋转缩放、组件级透明度。<br/>- 新增事件冒泡机制，新增旋转表冠事件。<br/>- 新增GIF图片解析显示，新增百分比宽高布局，新增Video和二维码控件。 | 局部渲染和SIMD性能优化。                                     | None                         |
| 公共基础       | - 新增dump系统属性功能。<br/>- 为上层各模块新增内存池管理接口。 | None                                                         | None                         |
| 驱动           | - 新增sensor、input、display驱动模型。<br/>- 新增mipi dsi以及pwm（脉冲宽度调制）。<br/>- 新增WIFI HDI接口以及WIFI的流控。<br/>- 新增驱动框架IO服务分组特性。 | 优化驱动加载流程，支持分段加载。                             | None                         |
| 分布式通信     | - 新增WiFi Aware特性模块。<br/>- IPC新增对非对齐序列化的支持。 | None                                                         | None                         |
| 安全           | - 新增HUKS提供 SHA256 / RSA3072 / RSA2048 / AES128 / ECC 安全算法以及接口，以及提供密钥管理和存储能力。<br/>- HiChain提供轻量非账号的轻量级组件，用于设备群组管理和认证，支撑软总线通讯安全；<br/>- 提供API给系统服务与应用。权限管理新增统一的权限管理机制，满足轻量设备权限授权需求。 | None                                                         | None                         |
| AI子系统       | - 新增统一的AI引擎框架，实现算法能力快速插件化集成。框架中主要包含插件管理、模块管理和通信管理等模块，对AI算法能力进行生命周期管理和按需部署<br/>- 为开发者提供开发指南，并提供2个基于AI引擎框架开发的AI能力插件和对应的AI应用Sample，方便开发者在AI引擎框架中快速集成AI算法能力。 | None                                                         | None                         |
| 升级服务       | 新增轻量级设备升级能力框架，框架包括升级包的效验和解析能力，以及安装的接口，统一轻设备升级能力框架。 | None                                                         | None                         |
| XTS认证        | 增加AI、DFX、global、OTA兼容性测试用例。                     | 应用程序框架、公共通信、分布式任务调度、IOT、内核等测试能力增强。 | None                         |
| 编译构建       | - 新增命令行工具hb, 采用hb set和hb build方式构建，并支持在源码目录下及任意子目录下构建。<br/>- 支持独立芯片厂商组件。<br/>- 支持使用组件名单独构建组件。<br/>- 支持按开发板自定义编译工具链和编译选项。 | 产品配置与build_lite仓解耦，修改为“vendor/解决方案厂商/产品/config.json”。 | None                         |
| 电源管理       | - 电量查询功能。<br/>- 亮屏锁管理功能及接口。                | None                                                         | None                         |


组件仓优化如下表所示。

> **说明：** 
>-   只读归档：组件仓归档到新的组织并设置为只读（openharmony-retired）。
>-   三方芯片代码与OS解耦，海思芯片SDK由Vendor目录迁移到device/hisilicon。

**表 3**  组建仓库优化

| OpenHarmony1.0                                               | OpenHarmony1.1.0                              | 优化方式 |
| ------------------------------------------------------------ | --------------------------------------------- | -------- |
| ace_lite_jsfwk                                               | ace_engine_lite                               | 仓名变更 |
| ace_interfaces_innerkits_builtin                             | -                                             | 只读归档 |
| -                                                            | ai_engine                                     | 新增组件 |
| hiviewdfx_frameworks_hievent_lite                            | hiviewdfx_hievent_lite                        | 仓名变更 |
| hiviewdfx_frameworks_hilog_lite                              | hiviewdfx_hilog_lite                          | 仓名变更 |
| hiviewdfx_utils_lite                                         | hiviewdfx_hiview_lite                         | 仓名变更 |
| hiviewdfx_frameworks_ddrdump_lite                            | -                                             | 只读归档 |
| hiviewdfx_interfaces_innerkits_hievent_<br/>lite             | -                                             | 只读归档 |
| hiviewdfx_interfaces_innerkits_hilog                         | -                                             | 只读归档 |
| hiviewdfx_interfaces_kits_hilog                              | -                                             | 只读归档 |
| hiviewdfx_interfaces_kits_hilog_lite                         | -                                             | 只读归档 |
| hiviewdfx_services_hilogcat_lite                             | -                                             | 只读归档 |
| hiviewdfx_services_hiview_lite                               | -                                             | 只读归档 |
| iothardware_hals_wifiiot_lite                                | -                                             | 只读归档 |
| iothardware_interfaces_kits_wifiiot_lite                     | -                                             | 只读归档 |
| iothardware_frameworks_wifiiot_lite                          | iothardware_peripheral                        | 仓名变更 |
| -                                                            | applications_camera_sample_<br/>communication | 新增组件 |
| -                                                            | applications_camera_screensaver_<br/>app      | 新增组件 |
| -                                                            | sensors_miscdevice_lite                       | 新增组件 |
| -                                                            | sensors_sensor_lite                           | 新增组件 |
| xts_tools_lite                                               | xts_tools                                     | 仓名变更 |
| security_services_iam_lite                                   | security_permission                           | 仓名变更 |
| security_interfaces_innerkits_iam_lite                       | -                                             | 只读归档 |
| security_interfaces_kits_iam_lite                            | -                                             | 只读归档 |
| security_services_secure_os                                  | security_itrustee_ree_lite                    | 仓名变更 |
| security_interfaces_innerkits_secure_os                      | -                                             | 只读归档 |
| security_frameworks_secure_os                                | -                                             | 只读归档 |
| security_services_app_verify                                 | security_appverify                            | 仓名变更 |
| security_interfaces_innerkits_app_verify                     | -                                             | 只读归档 |
| security_services_hichainsdk_lite                            | security_deviceauth                           | 仓名变更 |
| security_interfaces_innerkits_hichainsdk_<br/>lite           | -                                             | 只读归档 |
| security_services_huks_lite                                  | security_huks                                 | 仓名变更 |
| security_interfaces_innerkits_huks_lite                      | -                                             | 只读归档 |
| security_frameworks_crypto_lite                              | -                                             | 只读归档 |
| security_interfaces_innerkits_crypto_lite                    | -                                             | 只读归档 |
| -                                                            | signcenter_tool                               | 新增组件 |
| -                                                            | third_party_cryptsetup                        | 新增组件 |
| -                                                            | third_party_JSON-C                            | 新增组件 |
| -                                                            | third_party_libuuid                           | 新增组件 |
| -                                                            | third_party_LVM2                              | 新增组件 |
| -                                                            | third_party_popt                              | 新增组件 |
| communication_interfaces_kits_wifi_lite                      | -                                             | 只读归档 |
| communication_frameworks_wifi_lite                           | -                                             | 只读归档 |
| -                                                            | communication_wifi_lite                       | 新增组件 |
| -                                                            | powermgr_powermgr_lite                        | 新增组件 |
| distributedschedule_services_<br/>dtbschedmgr_lite           | distributedschedule_dms_fwk_lite              | 仓名变更 |
| distributedschedule_services_safwk_lite                      | distributedschedule_safwk_lite                | 仓名变更 |
| distributedschedule_services_samgr_lite                      | distributedschedule_samgr_lite                | 仓名变更 |
| distributedschedule_interfaces_innerkits_<br/>samgr_lite     | -                                             | 只读归档 |
| distributedschedule_interfaces_kits_samgr_<br/>lite          | -                                             | 只读归档 |
| multimedia_frameworks_audio_lite                             | multimedia_audio_lite                         | 仓名变更 |
| multimedia_frameworks_camera_lite                            | multimedia_camera_lite                        | 仓名变更 |
| multimedia_frameworks_player_lite                            | multimedia_media_lite                         | 仓名变更 |
| multimedia_hals_camera_lite                                  | -                                             | 只读归档 |
| multimedia_frameworks_recorder_lite                          | -                                             | 只读归档 |
| multimedia_interfaces_kits_audio_lite                        | -                                             | 只读归档 |
| multimedia_interfaces_kits_camera_lite                       | -                                             | 只读归档 |
| multimedia_interfaces_kits_player_lite                       | -                                             | 只读归档 |
| multimedia_interfaces_kits_recorder_lite                     | -                                             | 只读归档 |
| multimedia_services_media_lite                               | -                                             | 只读归档 |
| kernel_liteos_a_huawei_proprietary_fs_<br/>proc              | -                                             | 只读归档 |
| -                                                            | third_party_mksh                              | 新增组件 |
| -                                                            | third_party_optimized_routines                | 新增组件 |
| -                                                            | third_party_toybox                            | 新增组件 |
| vendor_huawei_camera                                         | -                                             | 只读归档 |
| vendor_huawei_wifi_iot                                       | -                                             | 只读归档 |
| startup_services_bootstrap_lite                              | startup_bootstrap_lite                        | 仓名变更 |
| startup_frameworks_syspara_lite                              | startup_syspara_lite                          | 仓名变更 |
| startup_hals_syspara_lite                                    | -                                             | 只读归档 |
| startup_interfaces_kits_syspara_lite                         | -                                             | 只读归档 |
| graphic_lite                                                 | graphic_surface_lite                          | 仓名变更 |
| -                                                            | arkui_ui_lite                                 | 仓名变更 |
| -                                                            | graphic_graphic_utils_lite                    | 仓名变更 |
| -                                                            | window_manager_lite                           | 仓名变更 |
| -                                                            | third_party_giflib                            | 新增组件 |
| -                                                            | third_party_qrcodegen                         | 新增组件 |
| -                                                            | drivers_adapter_khdf_linux                    | 新增组件 |
| drivers_hdf_lite                                             | drivers_adapter_khdf_liteos                   | 仓名变更 |
| -                                                            | drivers_adapter_uhdf                          | 新增组件 |
| drivers_hdf_frameworks                                       | drivers_framework                             | 仓名变更 |
| -                                                            | drivers_peripheral_audio                      | 新增组件 |
| -                                                            | drivers_peripheral_codec                      | 新增组件 |
| -                                                            | drivers_peripheral_display                    | 新增组件 |
| -                                                            | drivers_peripheral_format                     | 新增组件 |
| -                                                            | drivers_peripheral_input                      | 新增组件 |
| -                                                            | drivers_peripheral_sensor                     | 新增组件 |
| -                                                            | drivers_peripheral_wlan                       | 新增组件 |
| -                                                            | global_cust_lite                              | 新增组件 |
| -                                                            | global_i18n_lite                              | 新增组件 |
| global_frameworks_resmgr_lite                                | global_resmgr_lite                            | 仓名变更 |
|                                                              | third_party_icu                               | 新增组件 |
| global_interfaces_innerkits_resmgr_lite                      | -                                             | 只读归档 |
| communication_frameworks_ipc_lite                            | communication_ipc_lite                        | 仓名变更 |
| communication_interfaces_kits_ipc_lite                       | -                                             | 只读归档 |
| communication_interfaces_kits_<br/>softbuskit_lite           | -                                             | 只读归档 |
| communication_hals_wifi_lite                                 | -                                             | 只读归档 |
| communication_services_softbus_lite                          | communication_softbus_lite                    | 仓名变更 |
| -                                                            | communication_wifi_aware                      | 新增组件 |
| -                                                            | update_sysinstaller_lite                      | 新增组件 |
| vendor_hisi_hi35xx_hi35xx_init                               | device_hisilicon_build                        | 仓名变更 |
| vendor_hisi_hi35xx_platform                                  | device_hisilicon_drivers                      | 仓名变更 |
| vendor_hisi_hi35xx_hardware                                  | device_hisilicon_hardware                     | 仓名变更 |
| vendor_hisi_hi35xx_hi3518ev300                               | device_hisilicon_hispark_aries                | 仓名变更 |
| vendor_hisi_hi3861_hi3861                                    | device_hisilicon_hispark_pegasus              | 仓名变更 |
| vendor_hisi_hi35xx_hi3516dv300                               | device_hisilicon_hispark_taurus               | 仓名变更 |
| vendor_hisi_hi35xx_middleware                                | device_hisilicon_modules                      | 仓名变更 |
| vendor_hisi_hi35xx_middleware_source_<br/>third_party_ffmpeg | device_hisilicon_third_party_ffmpeg           | 仓名变更 |
| vendor_hisi_hi35xx_thirdparty_uboot_src                      | device_hisilicon_third_party_uboot            | 仓名变更 |
| -                                                            | vendor_hisilicon                              | 新增组件 |
| vendor_hisi_hi35xx_hi3516dv300_uboot                         | -                                             | 只读归档 |
| vendor_hisi_hi35xx_hi3518ev300_uboot                         | -                                             | 只读归档 |
| aafwk_interfaces_innerkits_abilitykit_lite                   | -                                             | 只读归档 |
| aafwk_interfaces_innerkits_intent_lite                       | aafwk_aafwk_lite                              | 仓名变更 |
| aafwk_interfaces_innerkits_abilitymgr_<br/>lite              | -                                             | 只读归档 |
| appexecfwk_kits_appkit_lite                                  | appexecfwk_appexecfwk_lite                    | 仓名变更 |
| aafwk_frameworks_kits_ability_lite                           | -                                             | 只读归档 |
|                                                              | developtools_packing_tool                     | 新增组件 |
| aafwk_interfaces_kits_ability_lite                           | -                                             | 只读归档 |
| appexecfwk_frameworks_bundle_lite                            | -                                             | 只读归档 |
| aafwk_services_abilitymgr_lite                               | -                                             | 只读归档 |
| appexecfwk_interfaces_innerkits_<br/>appexecfwk_lite         | -                                             | 只读归档 |
| appexecfwk_interfaces_innerkits_<br/>bundlemgr_lite          | -                                             | 只读归档 |
| appexecfwk_services_bundlemgr_lite                           | -                                             | 只读归档 |
| aafwk_frameworks_kits_content_lite                           | -                                             | 只读归档 |

## 已修复缺陷列表

针对OpenHarmony 1.0版本的缺陷列表，解决并修复的问题请参见下表。

**表 4**  修复问题列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I3EALU](https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU) | 【多媒体】cameraActs 用例执行时，找不到相机配置文件，初始失败的问题 |
| [I3EGUX](https://gitee.com/openharmony/release-management/issues/I3EGUX) | 【可靠性问题】反复reset，出现一次KIdle进程crash，系统挂死无法启动 |
| [I3DHIL](https://gitee.com/openharmony/community/issues/I3DHIL) | 【系统问题】HI3518开源板剩余空间不足，导致ACTS用例大量失败   |
