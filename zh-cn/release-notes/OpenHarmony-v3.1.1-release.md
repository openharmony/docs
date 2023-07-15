# OpenHarmony 3.1.1 Release


## 版本概述

当前版本在OpenHarmony 3.1 Release的基础上，更新支持以下能力：

**标准系统基础能力增强**

系统服务管理能力增强，新增添加群组校验机制；电源管理新增支持亮度调节和电池信息查询；Misc软件服务补齐兼容http文件下载接口能力。

位置服务支持基本定位接口能力；窗口支持窗口属性设置；媒体补齐音频焦点、音频解码能力相关接口能力。

网络管理支持以太网连接，新增WebSocket JS API，兼容\@system.fetch和\@system.network接口能力。

**标准系统分布式能力增强**

分布式数据管理支持兼容\@system.storage接口能力。

**标准系统应用程序框架能力增强**

包管理支持查询指定应用是否安装；事件通知实现通知发送和取消的接口能力。

元能力支持FA模型支持查询/设置组件横竖屏状态、组件锁屏显示和组件启动亮屏，新增ANR(Application Not Response)、应用主线程卡死检测等DFX功能，完善部分FA卡片基础能力。

**标准系统应用能力增强**

联系人支持第三方应用调用系统通话能力，提供用户基础通信能力。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.1.1&nbsp;Release | NA |
| Public SDK | Ohos_sdk_public&nbsp;3.1.6.6 (API&nbsp;Version&nbsp;8&nbsp;Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>DevEco Studio 3.0 Beta4版本起，通过DevEco Studio获取的SDK默认为Public SDK。<br/>该版本Public SDK于7月6日单独更新发布。 |
| Full SDK | Ohos_sdk_full&nbsp;3.1.6.5 (API&nbsp;Version&nbsp;8&nbsp;Release) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full SDK时需要手动从镜像站点获取，并在DevEco Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta3&nbsp;for&nbsp;OpenHarmony | OpenHarmony应用开发推荐使用。 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.0&nbsp;Release | OpenHarmony智能设备集成开发环境推荐使用。 |


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

**方式一（推荐）**

通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）        | 3.1.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/code-v3.1.1-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/code-v3.1.1-Release.tar.gz.sha256) |
| Hi3516标准系统解决方案（二进制）        | 3.1.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_hi3516.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_hi3516.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）        | 3.1.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_rk3568.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制）        | 3.1.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_pegasus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-LiteOS（二进制） | 3.1.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_taurus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-Linux（二进制）  | 3.1.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统Full SDK包（Mac）               | 3.1.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-mac-full.tar.gz.sha256) |
| 标准系统Full SDK包（Windows\Linux）     | 3.1.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-full.tar.gz.sha256) |
| 标准系统Public SDK包（Mac） | 3.1.1 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public SDK包（Windows\Linux） | 3.1.1 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.1.1/ohos-sdk-public.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony 3.1 Release的基础上有如下变更。


### 特性变更

**表3** 版本新增特性表

| 子系统名称 | 标准系统 | 轻量、小型系统 |
| -------- | -------- | -------- |
| SDK | SDK区分Full SDK和Public SDK进行发布。<br/>*说明：API Version 8的Public SDK首次于7月6日单独更新发布。* | NA |
| 系统服务管理 | 新增添加群组校验机制。<br/>主要涉及如下需求：<br/>I52G5Q&nbsp;添加群组校验机制 | NA |
| 电源管理 | 实现兼容亮度调节和电池信息查询API接口能力。<br/>主要涉及如下需求：<br/>I526UP&nbsp;支持\@system.brightness亮度调节接口<br/>I526UP&nbsp;支持\@system.battery电池信息查询接口 | NA |
| 包管理 | 实现查询指定应用是否安装接口能力。<br/>主要涉及如下需求：<br/>I56EWD&nbsp;支持对测试框架的配置<br/>I55RZJ&nbsp;查询指定应用是否安装 | NA |
| 位置服务 | 实现兼容基本定位API接口能力。<br/>主要涉及如下需求：<br/>I53WFP&nbsp;支持基本定位能力，兼容system&nbsp;API | NA |
| 元能力 | 实现FA模型支持查询/设置组件横竖屏状态、组件锁屏显示和组件启动亮屏。<br/>主要涉及如下需求：<br/>I56EH7&nbsp;FA模型支持查询/设置组件横竖屏状态<br/>I50D5Y&nbsp;FA模型支持组件锁屏显示<br/>I56EH7&nbsp;FA模型支持组件启动亮屏<br/>I55WB0&nbsp;卡片数据支持携带图片<br/>I55WB0&nbsp;FA卡片能力补齐-formManager重构<br/>I55WB0&nbsp;FA卡片能力补齐-支持卡片状态查询<br/>I55WB0&nbsp;FA卡片能力补齐-支持删除无效卡片<br/>I55WB0&nbsp;FA卡片能力补齐-支持卡片可见状态与更新状态单独设置<br/>I50D8H&nbsp;支持拦截uncatchedexception<br/>I50D91&nbsp;支持ANR(Application&nbsp;Not&nbsp;Response)处理 | NA |
| 媒体 | 实现音频焦点、音频解码能力相关API接口能力。<br/>主要涉及如下需求：<br/>I56REO&nbsp;音频部件焦点/设备接口OH补齐<br/>I522W0&nbsp;支持amr格式音频编码枚举类型 | NA |
| 窗口 | 支持对窗口属性进行设置。<br/>主要涉及如下需求：<br/>I56EH7&nbsp;支持窗口属性设置 | NA |
| 网络管理 | 实现兼容WebSocket、fetch等API接口能力，支持以太网连接。<br/>主要涉及如下需求：<br/>I53CKH&nbsp;支持兼容\@system.fetch<br/>I53CJX&nbsp;支持兼容\@system.network<br/>I53CKT&nbsp;支持WebSocket<br/>I580PC&nbsp;支持以太网连接 | NA |
| Misc软件服务 | 实现兼容http文件下载API接口能力。<br/>主要涉及如下需求：<br/>I56Q4X&nbsp;支持文件下载接口 | NA |
| 事件通知 | 实现通知发送和取消的API接口能力。<br/>主要涉及如下需求：<br/>I50EEW&nbsp;通知发送和取消功能的接口能力补齐 | NA |
| 分布式数据管理 | 实现兼容\@system.storage&nbsp;API接口能力。<br/>主要涉及如下需求：<br/>I56RF3&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;支持\@system.storage接口 | NA |
| 启动恢复 | 实现兼容\@system.device&nbsp;API接口能力。<br/>主要涉及如下需求：<br/>I56GBS&nbsp;支持\@system.device相关API | NA |
| 应用 | 联系人支持第三方应用调用系统通话能力，提供用户基础通信能力。<br/>主要涉及如下需求：<br/>I58ZQ4&nbsp;联系人支持第三方应用调用系统通话能力 | NA |

### API变更

3.1.1 Release对比3.1 Release API接口无变更。



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

## 修复缺陷列表

**表4** 修复缺陷ISSUE列表

| ISSUE单                                                      | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I4UUFR](https://gitee.com/openharmony/third_party_e2fsprogs/issues/I4UUFR) | 本地编译构建Hi3516开发板版本镜像                             |
| I4WDD3 | 【RK3568】录像后无法查看视频                                 |
| [I50EBB](https://gitee.com/openharmony/docs/issues/I50EBB)   | 【Hi3516烧录】标准系统Hi3516镜像无法通过IDE烧录              |


## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE                                                        | 问题描述                                                   | 影响                                              | 计划解决日期 |
| ------------------------------------------------------------ | ---------------------------------------------------------- | ------------------------------------------------- | ------------ |
| [I4Z3G9](https://gitee.com/openharmony/graphic_graphic_2d/issues/I4Z3G9) | 【RK3568】打开沉浸式主窗口和在主窗口上打开辅助窗口出现闪屏 | 影响开发者体验。                                  | 2022-06-15   |
| [I58GFY](https://gitee.com/openharmony/communication_wifi/issues/I58GFY) | 【RK3568】 2.4G/5G频段WPA+TKIP/AES加密方式均连接失败       | TP-Link AX50型号路由器无法正常连接WiFi。          | 2022-06-30   |
| [I59P32](https://gitee.com/openharmony/distributedhardware_device_manager/issues/I59P32) | 【RK3568】设备信任周期超期后无法重新PIN码认证              | 长时间不输入PIN码导致超时后触发，重启设备可恢复。 | 2022-06-15   |
