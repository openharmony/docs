# OpenHarmony 3.0.1 LTS

## 版本概述

此版本为OpenHarmony-3.0-LTS分支上的维护版本，基于OpenHarmony-v3.0-LTS版本修复一些缺陷及安全问题，通过集成验证后发布最新的稳定的tag版本。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.0.1&nbsp;LTS | NA |
| SDK | 3.0.0.0(API&nbsp;Version&nbsp;7&nbsp;release) | NA |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta1 | OpenHarmony应用开发推荐使用。 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 2.2&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 |


## 源码获取


### 通过repo获取

**方式一（推荐）**：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.1-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.1-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

**表2** 获取源码路径

| **LTS版本源码** | **版本信息** | **下载站点** | **SHA256校验码** |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.0.1 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.1/code-v3.0.1-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.1/code-v3.0.1-LTS.tar.gz.sha256) |
| 标准系统解决方案（二进制） | 3.0.1 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.1/standard.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.1/standard.tar.gz.sha256) |
| Hi3861解决方案（二进制） | 3.0.1 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_pegasus.tar.gz.sha256) |
| Hi3518解决方案（二进制） | 3.0.1 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_aries.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_aries.tar.gz.sha256) |
| Hi3516解决方案-LiteOS（二进制） | 3.0.1 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_taurus.tar.gz.sha256) |
| Hi3516解决方案-Linux（二进制） | 3.0.1 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.1/hispark_taurus_linux.tar.gz.sha256) |



## 更新说明

本版本在OpenHarmony v3.0 LTS的基础上有如下变更。


### 特性变更

当前维护版本不涉及新需求及新特性的接纳与变更。


### API变更

此版本不涉及API变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表3** 轻量和小型系统解决的缺陷ISSUE列表

| ISSUE单号 | 问题描述 |
| -------- | -------- |
| [I4BJFU](https://gitee.com/openharmony/kernel_liteos_a/issues/I4BJFU) | dyload_posix模块在removefile的时候出现错误 |
| [I42N33](https://gitee.com/openharmony/third_party_mksh/issues/I42N33) | 集成测试直接执行cat后无法退出，需要重启设备恢复 |
| [I4C8BO](https://gitee.com/openharmony/docs/issues/I4C8BO?from=project-issue) | 3516DV300/3518EV300&nbsp;使用官网烧写配置媒体子系统(轻量小型)基本功能异常 |
| I4BWKC | 3516DV300单板camera驱动压测问题 |
| I4BW0G | 3516DV300单板ResetDriver接口失败 |
| [I4C7ZK](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4C7ZK) | HI3516DV300&nbsp;小型系统常驻内存超基线 |
| [I434P1](https://gitee.com/openharmony/multimedia_camera_lite/issues/I434P1) | HI3518EV300常驻内存超基线 |
| [I48IM7](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I48IM7) | 运行hilog的压测，hilogd异常重启，且hilog命令一直无法使用 |
| I4EGMD | 修改want的序列化和反序列化方法 |
| [I4CED3](https://gitee.com/openharmony/account_os_account/issues/I4CED3) | 修复JS&nbsp;API接口返回只有一个内容的问题 |
| I4BXZ1 | 修复[&nbsp;Picker]&nbsp;组件点击无响应问题 |
| I4CMMH | 解决toggle显示异常问题 |
| I4CE7D | 优化编辑框响应时间 |
| [I4HI4C](https://gitee.com/openharmony/ai_engine/issues/I4HI4C) | 解决小型系统TDD&nbsp;用例失败问题，调整用例比较时间范围 |
| [I4EUOW](https://gitee.com/openharmony/ai_engine/issues/I4EUOW) | 更改用例执行线程数 |
| I4HTFS | 轻量系统bms适配 |
| [I4C3BE](https://gitee.com/openharmony/communication_dsoftbus/issues/I4C3BE) | 修复了BLE被动发现频繁更新蓝牙广播，导致蓝牙资源消耗完自动关闭的问题 |
| [I4I7QL](https://gitee.com/openharmony/developtools_packing_tool/issues/I4I7QL) | 修复一个ability有2张卡片的时候打包报错问题 |
| I4BW0G | 解决WiFi&nbsp;ResetDriver概率性失败问题 |
| [I4GBB6](https://gitee.com/openharmony/device_qemu/issues/I4GBB6) | 修复risc-v&nbsp;qemu模拟器运行系统异常问题 |
| [I4CE7E](https://gitee.com/openharmony/kernel_liteos_a/issues/I4CE7E) | liteos-a内核drivers/mtd/multi_partition/用到了device/hisilicon下的驱动函数实现 |
| I4JBEH | 修复了反复使用HDF的DMA传输接口，发生内存泄漏的问题 |
| I4IGQ0 | 解决器件探测失败后导致资源释放问题 |
| I4JPCG | 解决pwm背光无法设置0的问题 |
| [I4ERM4](https://gitee.com/openharmony/drivers_peripheral/issues/I4ERM4) | 解决显示用例失败的问题 |
| [I4CMUY](https://gitee.com/openharmony/drivers_adapter_khdf_linux/issues/I4CMUY) | hdf_peripheral_wlan_test_performance.bin测试套执行失败 |
| [I4FIP2](https://gitee.com/openharmony/kernel_liteos_a/issues/I4FIP2) | a核ioctl支持SIOCGIFBRDADDR选项 |
| [I4GVF7](https://gitee.com/openharmony/kernel_liteos_a/issues/I4GVF7) | 修改blackbox生成的文件和文件夹权限 |
| [I4EV8U](https://gitee.com/openharmony/kernel_liteos_a/issues/I4EV8U) | liteos_a_io_unittest.bin\#IoTest模块失败3条用例：IO_TEST_PPOLL_001等 |
| [I4EV3X](https://gitee.com/openharmony/kernel_liteos_a/issues/I4EV3X) | liteos_a_sys_unittest.bin\#SysTest模块失败7条用例：ItTestSys018等 |
| [I4EVG0](https://gitee.com/openharmony/kernel_liteos_a/issues/I4EVG0) | liteos_a_misc_unittest.bin\#MiscTest模块失败1条用例ItTestMisc009 |
| [I4JYAX](https://gitee.com/openharmony/kernel_liteos_a/issues/I4JYAX) | jffs2适配层错误释放锁 |
| [I4FIQW](https://gitee.com/openharmony/kernel_liteos_m/issues/I4FIQW) | liteos_m核ioctl支持SIOCGIFBRDADDR选项 |
| [I4ELVA](https://gitee.com/openharmony/kernel_liteos_m/issues/I4ELVA) | 修复文件系统VFS层read接口未正确判空g_fs的问题 |
| [I4C6P2](https://gitee.com/openharmony/kernel_liteos_m/issues/I4C6P2) | LOS_QueueInfoGet函数统计等待读写任务有误 |
| [I4C5RW](https://gitee.com/openharmony/kernel_liteos_m/issues/I4C5RW) | 开启MPU保护任务栈时，遇到OS_TASK_STACK_PROTECT_SIZE宏未定义的错误 |
| [I4G4VK](https://gitee.com/openharmony/kernel_liteos_m/issues/I4G4VK) | 修改inet_addr等宏为函数，外层调用可不包含lwip头文件 |
| [I4FVGV](https://gitee.com/openharmony/kernel_liteos_m/issues/I4FVGV) | liteos_m核优化lwip默认配置 |
| I4CE7D) | 删除延迟3秒拉起输入法 |
| [I4CFOO](https://gitee.com/openharmony/multimedia_media_lite/issues/I4CFOO) | linux多次录像后，不退出应用，重启最后一个录像文件大小为0 |
| [I4CLGW](https://gitee.com/openharmony/kernel_liteos_a/issues/I4CLGW) | pagecache优化 |
| [I4HKQ2](https://gitee.com/openharmony/vendor_hisilicon/issues/I4HKQ2) | 测试轻量系统liteOs&nbsp;获取udid |
| [I4FVJN](https://gitee.com/openharmony/startup_syspara_lite/issues/I4FVJN) | 轻量系统编译依赖mbedtls，却没有加依赖，导致编译不过 |
| [I4CE7E](https://gitee.com/openharmony/kernel_liteos_a/issues/I4CE7E) | liteos-a内核drivers/mtd/multi_partition/用到了device/hisilicon下的驱动函数实现 |

**表4** 标准系统解决的缺陷ISSUE列表

| ISSUE单号 | 问题描述 |
| -------- | -------- |
| [I4BX4J](https://gitee.com/openharmony/hiviewdfx_hicollie/issues/I4BX4J?from=project-issue) | 3516DV300单板调用hicollie接口失败 |
| [I4BX1X](https://gitee.com/openharmony/hiviewdfx_hitrace/issues/I4BX1X?from=project-issue) | 3516DV300单板调用hitrace接口失败 |
| [I4BVUL](https://gitee.com/openharmony/communication_wifi/issues/I4BVUL?from=project-issue) | 标准系统与手机切换AP场景发现组网成功率低(91%)，不达98% |
| I4BW6E| 标准系统与手机_手机侧循环开关网络_30次左右开始组网失败不再成功 |
| [I4BVVW](https://gitee.com/openharmony/communication_dsoftbus/issues/I4BVVW) | 标准系统与手机_L2开关网络自组网成功率97%_失败3次_需分析失败原因 |
| I48YPH | 测试发现和组网性能(循环离网-发现-组网)_110次组网失败3次 |
| [I4492M](https://gitee.com/openharmony/communication_dsoftbus/issues/I4492M) | 组网10分钟自动下线规格，实际测试不准确，耗时多了30s左右 |
| I44W7U | SubWindow窗口大小不支持缩放，导致播放Video过程中会盖住进度条 |
| [I480Z1](https://gitee.com/openharmony/communication_dsoftbus/issues/I480Z1?from=project-issue) | Softbus_server在执行socketfuzz时，出现crash |
| I4BGLS | import_signed_auth_info_hilink导入的key用于HiChain连接时的身份标志，导入后加密存储在文件中，属于敏感数据，在返回后没有从堆中清除 |
| [I4A10Q](https://gitee.com/openharmony/startup_appspawn/issues/I4A10Q?from=project-issue) | 性能测试3516&nbsp;3.0.0.6静态KPI劣化严重 |
| I4BXYT | hdc_std在设备重启之后，需要hdc_std&nbsp;kill才能重新发现设备 |
| I4KUTY | 删除无效的结果返回 |
| I4DMFV | 修复utf16到utf8的转换 |
| [I4HGVM](https://gitee.com/openharmony/communication_dsoftbus/issues/I4HGVM) | 增加标准系统对mbedtls的依赖 |
| I4DLV2 | 修复HidInfo\*类型导致非法内存访问错误的问题 |
| [I4CIJJ](https://gitee.com/openharmony/third_party_flutter/issues/I4CIJJ) | ArkUI支持GPU渲染 |
| [I4G31Z](https://gitee.com/openharmony/third_party_freetype/issues/I4G31Z) | 字体引擎版本从2.10.1升级到2.10.4 |
| [I4H06M](https://gitee.com/openharmony/third_party_harfbuzz/issues/I4H06M) | OpenType&nbsp;文本整形引擎版本从2.6.1升级到2.8.1 |
| [I4FS7V](https://gitee.com/openharmony/third_party_lwip/issues/I4FS7V) | 使用LWIP_NETCONN_FULLDUPLEX宏来管控conn-&gt;mbox_threads_waiting的初始化 |
| I43KL7 | 修改了合成器支持GPU合成 |


## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| [I4NMXQ](https://gitee.com/openharmony/xts_acts/issues/I4NMXQ?from=project-issue) | 标准系统XTS执行storagefileioperformancejstest和storagefilestabilityjstest测试套无法自动执行 | XTS测试套框架问题，分布式文件子系统自动化x-device无法执行测试套，可以手动执行，对功能无影响 | 2022/1/30 |
| [I4NU92](https://gitee.com/openharmony/communication_wifi/issues/I4NU92) | 轻量系统3516_Linux&nbsp;ActsLwipTest.bin测试套测试存在一条失败项 | 自动化测试用例调用内核读取time_out失败，对通信功能无影响 | 2022/1/15 |
| [I4NTKG](https://gitee.com/openharmony/xts_acts/issues/I4NTKG) | 执行XTS测试套WeekPluralNumberTest出现两条失败项 | 测试套用例问题，不影响实际功能 | 2022/1/15 |
| [I4OWWM](https://gitee.com/openharmony/xts_acts/issues/I4OWWM) | WeekPluralNumbertest模块对应json文件配置的有问题，执行用例时报"required&nbsp;device&nbsp;does&nbsp;not&nbsp;exist"导致UN | json文件配置问题，不影响功能 | 2022/1/15 |
| [I4MSVV](https://gitee.com/openharmony/xts_acts/issues/I4MSVV?from=project-issue) | 标准系统XTS测试执行测试ActsHiCollieCppTest模块HiCollieCppTest用例3条失败项 | 测试套名称变更导致存在文本校验功能的测试用例不通过，对功能无影响 | 2022/1/15 |
| [I4MSWM](https://gitee.com/openharmony/xts_acts/issues/I4MSWM?from=project-issue) | 标准系统XTS测试执行测试ActsFaultLoggerTest模块faultloggertest用例1条失败项 | 测试套名称变更导致存在文本校验功能的测试用例不通过，对功能无影响 | 2022/1/15 |
| I4NODO| 标准系统3516分布式业务流转端到端测试失败，无法完成流转 | DM组件_重复创建群组失败，影响使用流转功能（按照issue中提到的操作步骤）的业务，对其他应用无影响 | 2022/1/30 |
