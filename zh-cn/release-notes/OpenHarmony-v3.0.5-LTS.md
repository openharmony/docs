# OpenHarmony 3.0.5 LTS


## 版本概述

此版本为OpenHarmony-3.0-LTS分支上的维护版本，基于OpenHarmony-v3.0.3-LTS版本修复一些缺陷及安全问题，并更新支持以下能力：

**小型系统能力增强**

DFX提供native崩溃信息采集能力和整机重启故障检测定位能力。基础通信增加STA基础能力。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 3.0.5&nbsp;LTS | NA | 
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta1 | OpenHarmony应用开发推荐使用。 | 
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 2.2&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 | 


## 源码获取


### 前提条件

1. 注册码云gitee账号。

2. 注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。

3. 安装[git客户端](https://gitee.com/link?target=https%3A%2F%2Fgit-scm.com%2Fbook%2Fzh%2Fv2%2F%25E8%25B5%25B7%25E6%25AD%25A5-%25E5%25AE%2589%25E8%25A3%2585-Git)和[git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading)并配置用户信息。
     
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

4. 安装码云repo工具，可以执行如下命令。
     
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  #如果没有权限，可下载至其他目录，并将其配置到环境变量中chmod a+x /usr/local/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### 通过repo获取

**方式一（推荐）**：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

  
```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.5-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。

  
```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.5-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

  **表2** 获取源码路径

| **LTS版本源码** | **版本信息** | **下载站点** | **SHA256校验码** | 
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.0.5 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.5/code-v3.0.5-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.5/code-v3.0.5-LTS.tar.gz.sha256) | 
| 标准系统Hi3516解决方案（二进制） | 3.0.5 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.5/standard.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.5/standard.tar.gz.sha256) | 
| 轻量系统Hi3861解决方案（二进制） | 3.0.5 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.5/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.5/hispark_pegasus.tar.gz.sha256) | 
| 小型系统Hi3516解决方案-LiteOS（二进制） | 3.0.5 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.5/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.5/hispark_taurus.tar.gz.sha256) | 
| 小型系统Hi3516解决方案-Linux（二进制） | 3.0.5 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.5/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.5/hispark_taurus_linux.tar.gz.sha256) | 


## 更新说明


### 特性变更

  **表3** 版本新增特性表

| 子系统名称 | 标准系统 | 轻量、小型系统 | 
| -------- | -------- | -------- |
| 基础通信子系统 | NA | Linux版小型系统增加STA基础能力。<br/>主要涉及如下需求：<br/>I5AAFQ&nbsp;&nbsp;支持WIFI开关，扫描、连接、自动重连等STA特性的编译使能。<br/>I5AAFQ&nbsp;&nbsp;STA连接支持动态获取IPv4地址能力的编译使能。 | 
| DFX子系统 | NA | Linux版小型系统提供native崩溃信息采集能力和整机重启故障检测定位能力。<br/>主要涉及如下需求：<br/>I57I8Y/I57TOE&nbsp;&nbsp;提供native崩溃信息采集能力。<br/>I5C0QR&nbsp;在linux5.10上提供整机重启故障检测定位能力。 | 


### API变更

此版本不涉及API变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## <sup>修复缺陷列表</sup>

  **表4** 解决的缺陷ISSUE列表

| ISSUE单号 | 问题描述 | 
| -------- | -------- |
| [I4YBB0](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YBB0) | 小型系统3516DV300-Linux在系统相机拍照录像后，无图片生成，录制的视频无法播放。 | 
| [I4YB87](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YB87) | 小型系统3516DV300-Linux在系统相机拍照录像后，图库中无显示。 | 
| [I4YAGS](https://gitee.com/openharmony/multimedia_camera_lite/issues/I4YAGS?from=project-issue) | 小型系统3516DV300-Linux进入系统相机，画面蓝屏。 | 
| [I59FZ7](https://gitee.com/openharmony/telephony_core_service/issues/I59FZ7) | 标准系统电话测试用例无法进行测试验证。 | 
| [I4Z2MI](https://gitee.com/openharmony/xts_acts/issues/I4Z2MI) | 标准系统执行acts测试用例异常，actsWifiJSApiTest、ActsHotSpotJSApiTest、ActsP2PJSApiTest模块用例全部失败。 | 


## <sup>修复安全漏洞列表</sup>

如下漏洞为本项目组内上报漏洞，漏洞修复补丁及受影响版本详情请参考社区[安全漏洞披露](https://gitee.com/openharmony/security/tree/master/zh/security-disclosure/2022)。

  **表5** 修复的安全漏洞列表

| 漏洞编号 | 漏洞描述 | 漏洞影响 | 受影响的仓库 | 
| -------- | -------- | -------- | -------- |
| OpenHarmony-SA-2022-0501 | 软总线子系统存在堆溢出漏洞。 | 攻击者可在本地发起攻击，造成内存访问越界，可获取系统控制权。 | communication_dsoftbus | 
| OpenHarmony-SA-2022-0502 | 软总线子系统在接收TCP消息时存在堆溢出漏洞。 | 攻击者可在局域网内发起攻击，进行远程代码执行，获得系统控制权。 | communication_dsoftbus | 
| OpenHarmony-SA-2022-0503 | 软总线处理设备同步消息时存在越界访问漏洞。 | 攻击者可在局域网内发起攻击，可造成内存访问越界，造成DoS攻击。 | communication_dsoftbus | 
| OpenHarmony-SA-2022-0504 | Lock类包含的一个指针成员存在重复释放问题。 | 攻击者可在本地发起攻击，可获取系统控制权。 | global_resmgr_standard | 
| OpenHarmony-SA-2022-0601 | 事件通知子系统反序列化对象时会绕过认证机制。 | 攻击者可在本地发起攻击，造成权限绕过，导致服务端进程崩溃。 | notification_ces_standard | 
| OpenHarmony-SA-2022-0602 | 事件通知子系统存在校验绕过漏洞，可发起SA中继攻击。 | 攻击者可在本地发起攻击，造成校验绕过，获得系统控制权。 | notification_ces_standard | 
| OpenHarmony-SA-2022-0603 | 升级服务组件存在校验绕过漏洞，可发起SA中继攻击。 | 攻击者可在本地发起攻击，造成校验绕过，获得系统控制权。 | update_updateservice | 
| OpenHarmony-SA-2022-0604 | 多媒体子系统存在校验绕过漏洞，可发起SA中继攻击。 | 攻击者可在本地发起攻击，造成校验绕过，获取系统控制权。 | multimedia_media_standard | 


