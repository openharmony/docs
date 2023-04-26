# OpenHarmony 1.1.4 LTS (停止维护)

## 版本概述

此版本为OpenHarmony-v1.1.3-LTS分支上的维护版本，基于OpenHarmony-v1.1.3-LTS版本修复一些缺陷及安全问题，通过集成验证后发布最新且稳定的tag版本。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 1.1.4&nbsp;LTS | NA |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 2.2&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 |


## 源码获取


### 通过repo获取

**方式一（推荐）**：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.4-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.4-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

**表2** 获取源码路径

| 版本源码 | 版本信息 | 下载站点 | SHA256校验码 |
| -------- | -------- | -------- | -------- |
| 全量代码 | 1.1.4 | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.4/code-v1.1.4-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.4/code-v1.1.4-LTS.tar.gz.sha256) |
| 轻量级设备Hi3861解决方案（二进制） | 1.1.4 | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.4/wifiiot-1.1.4.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.4/wifiiot-1.1.4.tar.gz.sha256) |
| 小型设备Hi3518解决方案（二进制） | 1.1.4 | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.4/ipcamera_hi3518ev300-1.1.4.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.4/ipcamera_hi3518ev300-1.1.4.tar.gz.sha256) |
| 小型设备Hi3516解决方案（二进制） | 1.1.4 | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.4/ipcamera_hi3516dv300-1.1.4.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.4/ipcamera_hi3516dv300-1.1.4.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony v1.1.3 LTS的基础上有如下变更。


### 特性变更

当前维护版本不涉及新需求及新特性的接纳与变更。


### API变更

此版本不涉及API变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表3** 已修复的安全漏洞列表

| ISSUE单号 | 问题描述 |
| -------- | -------- |
| [I4AJEN](https://gitee.com/openharmony/third_party_freetype/issues/I4AJEN) | 修复third_party_freetype组件的CVE-2020-15999安全漏洞 |
| [I4AJ6T](https://gitee.com/openharmony/third_party_mbedtls/issues/I4AJ6T) | 修复third_party_mbedtls组件的CVE-2020-36475和CVE-2020-36478安全漏洞 |
| I4AIYJ | 修复third_party_uboot组件的CVE-2021-27138和CVE-2021-27097安全漏洞 |
| [I4HUM6](https://gitee.com/openharmony/third_party_lwip/issues/I4HUM6?from=project-issue) | 修复third_party_lwip组件的CVE-2020-22284安全漏洞 |
| I4QTVZ | 修复third_party_mbedtls组件的CVE-2021-44732和CVE-2021-45450安全漏洞 |
| [I46RRM](https://gitee.com/openharmony/third_party_wpa_supplicant/issues/I46RRM?from=project-issue) | 修复P2P客户端的辅助设备类型的复制存在的一个安全漏洞 |

**表4** 已修复的缺陷列表

| ISSUE单号 | 问题描述 |
| -------- | -------- |
| [I457ZZ](https://gitee.com/openharmony/kernel_liteos_a/issues/I457ZZ) | 解决OsLockDepCheckIn异常处理中存在锁嵌套调用导致死锁输出异常信息问题 |
| [I3WU8Y](https://gitee.com/openharmony/kernel_liteos_a/issues/I3WU8Y) | 解决轻内核子系统集成测试中fs模块storage下有失败用例的问题 |
| [I4AJI2](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/issues/I4AJI2) | 升级ffmpeg版本到4.3.1版本 |
| [I3HXIX](https://gitee.com/openharmony/third_party_NuttX/issues/I3HXIX?from=project-issue) | 修复多进程情况下，pipe的内核操作节点存在使用脏私有字段dev，导致系统概率异常的问题 |
| [I4QO9B](https://gitee.com/openharmony/communication_wifi_lite/issues/I4QO9B?from=project-issue) | 修复WLAN从列表退出到桌面卡住的问题 |
| [I4EPVL](https://gitee.com/openharmony/xts_acts/issues/I4EPVL?from=project-issue) | CMSIS的代码与第三方芯片不兼容，暂时下架ActsCMSISTest测试用例 |
| [I4QQU9](https://gitee.com/openharmony/xts_acts/issues/I4QQU9) | 小型设备Hi3516&amp;Hi3518执行xts测试套ActsNetTest时串口日志出现板端IP和mac地址 |


## 遗留缺陷列表

无
