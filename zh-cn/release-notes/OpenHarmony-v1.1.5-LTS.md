# OpenHarmony 1.1.5 LTS (停止维护)


## 版本概述

此版本为OpenHarmony 1.0.1 Release分支上的维护版本，基于OpenHarmony-v1.1.4-LTS版本修复一些缺陷及安全问题，通过集成验证后发布最新且稳定的标签版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 1.1.5&nbsp;LTS | NA | 
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 2.2&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 | 


## 源码获取


### 通过repo获取

**方式一（推荐）**：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

  
```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.5-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。

  
```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.5-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码 | 版本信息 | 下载站点 | SHA256校验码 | 
| -------- | -------- | -------- | -------- |
| 全量代码 | 1.1.5 | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.5/code-v1.1.5-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.5/code-v1.1.5-LTS.tar.gz.sha256) | 
| 轻量级设备Hi3861解决方案（二进制） | 1.1.5 | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.5/wifiiot-1.1.5.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.5/wifiiot-1.1.5.tar.gz.sha256) | 
| 小型设备Hi3518解决方案（二进制） | 1.1.5 | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.5/ipcamera_hi3518ev300-1.1.5.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.5/ipcamera_hi3518ev300-1.1.5.tar.gz.sha256) | 
| 小型设备Hi3516解决方案（二进制） | 1.1.5 | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.5/ipcamera_hi3516dv300-1.1.5.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.5/ipcamera_hi3516dv300-1.1.5.tar.gz.sha256) | 


## 更新说明

本版本在OpenHarmony v1.1.4 LTS的基础上有如下变更。


### 特性变更

当前维护版本不涉及新需求及新特性的接纳与变更。


### API变更

此版本不涉及API变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

  **表3** 已修复的安全漏洞列表

| ISSUE单号 | 问题描述 | 合入链接 | 
| -------- | -------- | -------- |
| I58X0S | 修复curl组件的CVE-2022-27781、CVE-2022-27782安全漏洞 | [PR](https://gitee.com/openharmony/third_party_curl/pulls/60) | 
| I56PV4 | 修复curl组件的CVE-2022-22576、CVE-2022-27775、CVE-2022-27774、CVE-2022-27776安全漏洞 | [PR](https://gitee.com/openharmony/third_party_curl/pulls/54) | 
| NA | 修复curl组件的CVE-2021-22945、CVE-2021-22946、CVE-2021-22947安全漏洞 | [PR](https://gitee.com/openharmony/third_party_curl/pulls/56) | 
| I4QT0K/I56GI9 | 修复mbed&nbsp;tls组件的CVE-2021-44732、CVE-2021-45450安全漏洞 | [PR](https://gitee.com/openharmony/third_party_mbedtls/pulls/30) | 
| I5F0WG | 修复freetype组件的CVE-2022-27404、CVE-2022-27406安全漏洞 | [PR](https://gitee.com/openharmony/third_party_freetype/pulls/22) | 
| I4TLI9 | 修复freetype组件的CVE-2020-15999安全漏洞 | [PR](https://gitee.com/openharmony/third_party_freetype/pulls/7) | 
| I51D98 | 修复zlib组件的CVE-2018-25032安全漏洞 | [PR](https://gitee.com/openharmony/third_party_zlib/pulls/31) | 
| I5F13F/I4UHO4 | 修复ffmpeg组件的CVE-2020-35964、CVE-2022-1475、CVE-2021-38291、CVE-2020-35965、CVE-2020-22042、CVE-2020-22038、CVE-2020-22037、CVE-2020-22021、CVE-2020-22019安全漏洞 | [PR](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/pulls/17) | 

  **表4** 已修复的缺陷列表

| ISSUE单号 | 问题描述 | 
| -------- | -------- |
| [I4VKNM](https://gitee.com/openharmony/xts_acts/issues/I4VKNM) | 小型系统Hi3518开发板执行testSigtimedwaitBlock用例时概率性失败 | 
| [I4S098](https://gitee.com/openharmony/applications_sample_camera/issues/I4S098) | 小型系统Hi3516开发板点击设置-WiFi，进入WiFi列表界面后退出，重复此操作会使开发板概率性无响应 | 
