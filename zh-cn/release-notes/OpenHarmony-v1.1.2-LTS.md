# OpenHarmony v1.1.2 LTS (停止维护)

## 版本概述

更新发布LTS（long-term support）长期支持版本OpenHarmony v1.1.2 LTS，本版本在v1.1.1 LTS版本的基础上新增了一些特性和修复了部分缺陷。

## 配套关系

**表 1**  版本软件和工具配套关系

| 软件                              | 版本                        | 备注                                      |
| --------------------------------- | --------------------------- | ----------------------------------------- |
| OpenHarmony                       | 1.1.2 LTS                   | NA                                        |
| HUAWEI DevEco Device Tool（可选） | Deveco DeviceTool 2.2 Beta1 | OpenHarmony智能设备集成开发环境推荐使用。 |


## 源码获取

### 通过镜像站点获取

**表 2**  源码获取路径

| 版本源码                 | 版本信息 | 下载站点                                                     | SHA256校验码                                                 |
| ------------------------ | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码                 | 1.1.2    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.2/code-v1.1.2-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.2/code-v1.1.2-LTS.tar.gz.sha256) |
| Hi3861解决方案（二进制） | 1.1.2    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.2/wifiiot-1.1.2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.2/wifiiot-1.1.2.tar.gz.sha256) |
| Hi3518解决方案（二进制） | 1.1.2    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3518ev300-1.1.2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3518ev300-1.1.2.tar.gz.sha256) |
| Hi3516解决方案（二进制） | 1.1.2    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3516dv300-1.1.2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.2/ipcamera_hi3516dv300-1.1.2.tar.gz.sha256) |
| Release Notes            | 1.1.2    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.2/OpenHarmony-Release-Notes-1.1.2-LTS.zip) | -                                                            |


### 通过repo下载

方式一（推荐）：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

方式二：通过repo + https 下载。

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## 更新说明

本版本完全继承了OpenHarmony 1.1.1的所有特性，并在OpenHarmony 1.1.1版本的基础上，对部分模块进行了功能扩展和优化，详情请参考下表。

**表 3**  特性更新说明

| 子系统 | 新增特性                                                     | 修改特性         | 删除特性 |
| ------ | ------------------------------------------------------------ | ---------------- | -------- |
| 轻图形 | 新增滑动条修改，支持了滑块样式的设置                         | none             | none     |
| 升级   | 适配升级包rsa3072长度的签名算法                              | none             | none     |
| 驱动   | 新增了一些osal内部接口                                       | sensor模型的优化 | none     |
| 全球化 | 新增数字开关、星期等相关数据功能新增Get12HourTimeWithoutAmpm接口 | none             | none     |


## 已修复缺陷列表

在OpenHarmony 1.1.1版本的基础上，解决并修复的问题见下表。

**表 4**  已修复问题列表

| 子系统       | PR NO.                                                       | 问题描述                                                     |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 用户程序框架 | aafwk_aafwk_lite/pulls/35 | 解決linux系统上小概率无法关机的问题                          |
| AI           | [ai_engine/pulls/50](https://gitee.com/openharmony/ai_engine/pulls/50) | 修复测试用例client端未释放问题                               |
|              | [ai_engine/pulls/46](https://gitee.com/openharmony/ai_engine/pulls/46) | 修复类成员未初始化的问题                                     |
| IOT硬件      | [applications_sample_wifi_iot/pulls/12](https://gitee.com/openharmony/applications_sample_wifi_iot/pulls/12) | 修复编译构建错误的问题                                       |
| 编译构建     | [build_lite/pulls/151](https://gitee.com/openharmony/build_lite/pulls/151) | 开发的测试用例加入到编译流程                                 |
| 芯片平台     | [third_party_ffmpeg/pulls/9](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/pulls/9) | 修复CVE-2020-22025安全漏洞                                   |
|              | [third_party_ffmpeg/pulls/6](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/pulls/6) | 修复部分环境依赖valgrind，导致编译失败问题                   |
|              | [vendor_hisilicon/pulls/39](https://gitee.com/openharmony/vendor_hisilicon/pulls/39) | 解决release版本编译失败的问题                                |
| 分布式调度   | distributedschedule_dms_fwk_lite/pulls/23 | 测试用例名称更换                                             |
|              | distributedschedule_samgr_lite/pulls/25 | 修复CVE-2021-22478安全漏洞                                   |
| 全球化       | [global_i18n_lite/pulls/24](https://gitee.com/openharmony/global_i18n_lite/pulls/24) | 代码重构，优化全球化i18n.dat资源加载                         |
|              | [third_party_jerryscript/pulls/22](https://gitee.com/openharmony/third_party_jerryscript/pulls/22) | 修复mac版本上debug调试时断点概率性无法停住的问题             |
| 轻图形       | [graphic_ui/pulls/220](https://gitee.com/openharmony/graphic_ui/pulls/220) | 修复Add和Remove未配套使用问题，修改后UIViewGroup析构不清理子节点 |
|              | [graphic_ui/pulls/199](https://gitee.com/openharmony/graphic_ui/pulls/199) | 修复图片更新路径之后不刷新的问题                             |
| 轻内核       | [kernel_liteos_a/pulls/385](https://gitee.com/openharmony/kernel_liteos_a/pulls/385) | 修复CVE-2021-22479安全漏洞                                   |
|              | [kernel_liteos_a/pulls/299](https://gitee.com/openharmony/kernel_liteos_a/pulls/299) | 删除PRINTK多余的维测日志                                     |
|              | [third_party_musl/pulls/44](https://gitee.com/openharmony/third_party_musl/pulls/44) | 修复设置随机数种子函数srand的实现的问题                      |
| 启动         | [startup_syspara_lite/pulls/31](https://gitee.com/openharmony/startup_syspara_lite/pulls/31) | 修改安全补丁日期                                             |
| 驱动         | [drivers_adapter_khdf_linux/pulls/28](https://gitee.com/openharmony/drivers_adapter_khdf_linux/pulls/28) | 修复CVE-2021-22441安全漏洞                                   |
|              | [drivers_adapter/pulls/50](https://gitee.com/openharmony/drivers_adapter/pulls/50) | 修复CVE-2021-22480安全漏洞                                   |
| 测试         | [xts_acts/pulls/294](https://gitee.com/openharmony/xts_acts/pulls/294) | 删除fs_posix模块的不稳定测试用例                             |
|              | [xts_acts/pulls/287](https://gitee.com/openharmony/xts_acts/pulls/287) | 修复acts测试失败的相关问题                                   |
|              | [xts_acts/pulls/283](https://gitee.com/openharmony/xts_acts/pulls/283) | 修复CMSIS测试部分用例概率失败问题                            |
|              | [xts_acts/pulls/270](https://gitee.com/openharmony/xts_acts/pulls/270) | 修改不稳定用例：shared_memory 模块ShmTest.cpp用例ShmTest.testShmatSHM_REMAP 未按照预想逻辑运行问题。 |
|              | [xts_acts/pulls/314](https://gitee.com/openharmony/xts_acts/pulls/314) | 修复net_posix模块测试卡死问题                                |


