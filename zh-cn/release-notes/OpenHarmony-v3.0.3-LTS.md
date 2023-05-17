# OpenHarmony 3.0.3 LTS


## 版本概述

此版本为OpenHarmony-3.0-LTS分支上的维护版本，基于OpenHarmony-v3.0.2-LTS版本修复一些缺陷及安全问题，通过集成验证后发布最新且稳定的标签版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 3.0.3&nbsp;LTS | NA | 
| SDK | 3.0.0.0(API&nbsp;Version&nbsp;7&nbsp;release) | NA | 
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta1 | OpenHarmony应用开发推荐使用。 | 
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 2.2&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 | 


## 源码获取


### 通过repo获取

**方式一（推荐）**：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

  
```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。

  
```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

  **表2** 获取源码路径

| **LTS版本源码** | **版本信息** | **下载站点** | **SHA256校验码** | 
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.0.3 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.3/code-v3.0.3-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.3/code-v3.0.3-LTS.tar.gz.sha256) | 
| 标准系统Hi3516解决方案（二进制） | 3.0.3 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.3/standard.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.3/standard.tar.gz.sha256) | 
| 轻量系统Hi3861解决方案（二进制） | 3.0.3 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_pegasus.tar.gz.sha256) | 
| 小型系统Hi3516解决方案-LiteOS（二进制） | 3.0.3 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_taurus.tar.gz.sha256) | 
| 小型系统Hi3516解决方案-Linux（二进制） | 3.0.3 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0.3/hispark_taurus_linux.tar.gz.sha256) | 


## 更新说明

本版本在OpenHarmony-v3.0.2-LTS的基础上有如下变更。


### 特性变更

当前维护版本不涉及新需求及新特性的接纳与变更。


### API变更

此版本不涉及API变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

  **表3** 解决的缺陷ISSUE列表

| ISSUE单号 | 问题描述 | 
| -------- | -------- |
| [I4TUSX](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4TUSX) | 轻量系统Hi3516DV300打开系统相机拍照时，图片两端会出现截断。 | 
| [I4TYOP](https://gitee.com/openharmony/drivers_peripheral/issues/I4TYOP) | 轻量系统Hi3516DV300插入U盘后&nbsp;DMA超时，U盘不可用。 | 
| [I4SM0J](https://gitee.com/openharmony/third_party_harfbuzz/issues/I4SM0J) | third_party_harfbuzz仓内使用了&nbsp;CC&nbsp;BY-NC-SA-3.0&nbsp;许可证，该许可证限制了内容的商业使用。 | 
| [I4WPQW](https://gitee.com/openharmony/device_hisilicon_hardware/issues/I4WPQW) | device_hisilicon_hardware仓同步更新libdisplay_layer.so二进制文件。 | 
| [I4WIVF](https://gitee.com/openharmony/third_party_boost/issues/I4WIVF) | third_party_boost仓下一些文件存在开源协议不兼容的风险。 | 
| I4WRWM | aafwk_aafwk_lite仓新增TDD测试用例。 | 
| [I4VPVY](https://gitee.com/openharmony/applications_sample_camera/issues/I4VPVY) | 轻量系统Hi3516DV300从设置菜单搜索WLAN，然后点击2次返回键返回到桌面后，无法从桌面启动应用。 | 
| [I4UTY0](https://gitee.com/openharmony/applications_photos/issues/I4UTY0) | demos&nbsp;路径下的&nbsp;1.jpg&nbsp;图片文件元数据中存在HP的版权声明。 | 
| [I4TP6D](https://gitee.com/openharmony/xts_acts/issues/I4TP6D) | 标准系统Hi3516新增acts测试套ActsWorkerJSTest无法正常执行。 | 

  **表4** 解决的安全漏洞ISSUE列表

| ISSUE单号 | 问题描述 | 
| -------- | -------- |
| I4U8VB | 修复third_party_lz4组件CVE-2021-3520安全漏洞 | 
| I4UX33 | 修复third_party_protobuf组件CVE-2021-22569、CVE-2021-22570安全漏洞 | 
| I4VRR7 | 修复third_party_libxml2组件CVE-2022-23308安全漏洞 | 


  **表5** 遗留的ISSUE列表

| ISSUE单号 | 问题描述 | 影响 | 解决计划 | 
| -------- | -------- | -------- | -------- |
| [I4YBB0](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YBB0) | 小型系统3516DV300-Linux在系统相机拍照录像后，无图片生成，录制的视频无法播放 | 仅针对此开发板，影响相机录像功能 | 2022/4/1 | 
| [I4YB87](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YB87) | 小型系统3516DV300-Linux在系统相机拍照录像后，图库中无显示 | 仅针对此开发板，影响相机拍照功能 | 2022/4/1 | 
| [I4YAGS](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YAGS?from=project-issue) | 小型系统3516DV300-Linux进入系统相机，画面蓝屏 | 仅针对此开发板，影响相机预览功能 | 2022/4/1 | 
| I4WLBU | 标准系统3516DV300在acts测试过程中烧录后找不到设备，报Device&nbsp;not&nbsp;founded&nbsp;or&nbsp;connected | HDC工具导致acts测试概率报错，对实际功能无影响 | 2022/4/10 | 
