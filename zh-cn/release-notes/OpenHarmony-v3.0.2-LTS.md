# OpenHarmony 3.0.2 LTS


## 版本概述

此版本为OpenHarmony-3.0-LTS分支上的维护版本，基于OpenHarmony-v3.0.1-LTS版本修复一些缺陷及安全问题，通过集成验证后发布最新且稳定的标签版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.0.2&nbsp;LTS | NA |
| SDK | 3.0.0.0(API&nbsp;Version&nbsp;7&nbsp;release) | NA |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta1 | OpenHarmony应用开发推荐使用。 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 2.2&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 |


## 源码获取


### 通过repo获取

**方式一（推荐）**：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.2-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

  **表2** 获取源码路径

| **LTS版本源码** | **版本信息** | **下载站点** | **SHA256校验码** |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.0.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.2/code-v3.0.2-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.2/code-v3.0.2-LTS.tar.gz.sha256) |
| 标准系统解决方案（二进制） | 3.0.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.2/standard.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.2/standard.tar.gz.sha256) |
| 轻量系统Hi3861解决方案（二进制） | 3.0.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_pegasus.tar.gz.sha256) |
| 小型系统Hi3516解决方案-LiteOS（二进制） | 3.0.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_taurus.tar.gz.sha256) |
| 小型系统Hi3516解决方案-Linux（二进制） | 3.0.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.2/hispark_taurus_linux.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony v3.0.1 LTS的基础上有如下变更。


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
| [I4UZ7U](https://gitee.com/openharmony/xts_acts/issues/I4UZ7U?from=project-issue) | 小型系统执行XTS测试时概率有35条失败项 |
| [I4V2DN](https://gitee.com/openharmony/xts_acts/issues/I4V2DN?from=project-issue) | ActsLwipTest模块测试中存在两条用例执行超时的失败 |
| [I4V3KC](https://gitee.com/openharmony/xts_acts/issues/I4V3KC?from=project-issue) | 分布式调度子系统testPublish0010测试用例执行失败 |
| [I4URGA](https://gitee.com/openharmony/applications_sample_camera/issues/I4URGA?from=project-issue) | 设置界面搜WLAN信号时概率出现蓝屏 |
| I4SDCK | 小型系统HI&nbsp;3516&nbsp;GetSrcPath&nbsp;/GetDataPath&nbsp;获取路径为空或者乱码 |
| [I4T6KZ](https://gitee.com/openharmony/communication_dsoftbus/issues/I4T6KZ) | 测试传输相关用例时在&nbsp;SendMessage&nbsp;SendData4Data处失败 |
| I4UOUS | Hi3516小型系统&nbsp;串口界面的回显日志打印了明文密码 |
| [I4OWZO](https://gitee.com/openharmony/third_party_toybox/issues/I4OWZO) | toybox&nbsp;mv命令移动nfs路径下的文件出现异常提示 |
| [I4NCSF](https://gitee.com/openharmony/graphic_ui/issues/I4NCSF) | 图形子系统UI模块，直线型指针无法实时刷新 |
| [I4NU92](https://gitee.com/openharmony/communication_wifi/issues/I4NU92) | Hi3516&nbsp;Linux&nbsp;ActsLwipTest.bin测试套测试存在一条失败项 |
| [I4NVCK](https://gitee.com/openharmony/applications_sample_camera/issues/I4NVCK) | audio&nbsp;capture无法正常运行 |
| [I4NESQ](https://gitee.com/openharmony/kernel_liteos_a/issues/I4NESQ) | los_disk_cache_clear有条件编译错误 |
| [I4O67U](https://gitee.com/openharmony/kernel_liteos_a/issues/I4O67U) | 修复Ctrl+C会终止所有进程的问题 |
| [I4R4D3](https://gitee.com/openharmony/kernel_liteos_m/issues/I4R4D3) | pthread_create创建的线程未设置detach属性，主动退出后，OsGetAllTskInfo调用后，相关的任务名为乱码 |
| [I4R4A5](https://gitee.com/openharmony/kernel_liteos_m/issues/I4R4A5) | pthread_cond_timedwait接口实现存在计算溢出的问题 |
| [I4QJT4](https://gitee.com/openharmony/drivers_adapter_khdf_linux/issues/I4QJT4) | 修复UartRead&nbsp;test&nbsp;case&nbsp;失败问题 |
| I4U1DM | samgr&nbsp;的&nbsp;QUEUE_Pop&nbsp;函数在调用&nbsp;LFQUE_Pop&nbsp;函数时未加锁，存在潜在的数据竞争 |

  **表4** 标准系统解决的缺陷ISSUE列表

| ISSUE单号 | 问题描述 |
| -------- | -------- |
| [I4UJNU](https://gitee.com/openharmony/applications_settings/issues/I4UJNU) | 通过设置连接WLAN时，WLAN密码在hilog日志中明文打印 |
| [I4MSWM](https://gitee.com/openharmony/xts_acts/issues/I4MSWM?from=project-issue) | XT测试执行测试ActsFaultLoggerTest模块faultloggertest用例时有1条失败项 |
| [I4MSVV](https://gitee.com/openharmony/xts_acts/issues/I4MSVV?from=project-issue) | XTS测试执行测试ActsHiCollieCppTest模块HiCollieCppTest用例时有3条失败项 |
| I4PPXV | 打开应用后再退出到桌面，桌面应用图标丢失 |
| [I4OF9A](https://gitee.com/openharmony/distributeddatamgr_file/issues/I4OF9A?from=project-issue) | file.readText接口读取的text值不稳定 |
| [I4OWWM](https://gitee.com/openharmony/xts_acts/issues/I4OWWM) | WeekPluralNumbertest模块对应json文件配置问题，执行用例时报"required&nbsp;device&nbsp;does&nbsp;not&nbsp;exist"导致此测试套无法执行 |
| [I4OUVQ](https://gitee.com/openharmony/xts_tools/issues/I4OUVQ?from=project-issue) | XTS&nbsp;JS用例反复压力测试过程中系统卡死，无法进行测试 |
| [I4NMXQ](https://gitee.com/openharmony/xts_acts/issues/I4NMXQ?from=project-issue) | XTS执行storagefileioperformancejstest和storagefilestabilityjstest测试套无法执行起来 |
| [I4NTKG](https://gitee.com/openharmony/xts_acts/issues/I4NTKG) | 执行xts测试套WeekPluralNumberTest出现两条失败项 |
| [I4NPHG](https://gitee.com/openharmony/xts_acts/issues/I4NPHG?from=project-issue) | timer定时器测试套TimerJSApiTest.hap未随版本编译出来 |


  **表5** 安全漏洞合入列表

| ISSUE单号 | 问题描述 |
| -------- | -------- |
| I4QT0K | 修复third_party_mbedtls组件CVE-2021-44732和CVE-2021-45450安全漏洞 |
| I4NZ16 | 更新third_party_sqlite组件到3.36.0版本，同时修复CVE-2021-36690安全漏洞 |
| I4NW0B | 修复third_party_gstreamer组件CVE-2021-3522安全漏洞 |
| I4SR8C | 修复third_party_openssl组件&nbsp;CVE-2021-4160修复 |
| I4U4B0 | 更新third_party_expat组件到2.4.1版本，修复CVE-2022-25313/25314/25315/25235/252256/23990/23852/22827/46143/45960等安全漏洞 |
