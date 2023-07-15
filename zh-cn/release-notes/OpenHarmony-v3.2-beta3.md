# OpenHarmony 3.2 Beta3


## 版本概述

当前版本在OpenHarmony 3.2 Beta2的基础上，更新支持或优化增强的能力如下：

**标准系统基础能力增强**

泛sensor提供马达优先级管理能力。

多模输入提供鼠标样式和速度设置、鼠标上报事件增强，配置序列拉起应用，键鼠穿越等特性。

Misc服务新增剪贴板、上传下载、锁屏、输入法框架等模块基础特性。

内核子系统新增内存压力通知AMS、回收优先级管理支持常驻系统服务，回收优先级管理支持区分extension状态等基础能力。

DFX支持faultloggerd混合JS/Native栈打印，hilog domain白名单管理和日志统计功能，hisysevent、hiappeventssh事件能力增强，hidumper内存分类信息优化。

单元测试框架新增参数化数据驱动能力；UI测试框架新增抛滑及复杂手势如双指捏合能力接口；xdevice增加任务执行完成后搜集设备DFX日志能力等。

编译运行时新增支持严格模式的ES2021、模块化支持、Runtime 调试调优增强、字节码热重载等。

帐号服务新增用户身份认证服务；权限服务新增支持精准定位或模糊定位，以及其他能力增强；新增隐私管理服务。

媒体子系统新增支持音频解码、音频编码、视频解码、视频编码native接口、支持播放音画同步和启动时间优化、支持基于HDI codec接口的视频硬件编解码能力、支持分布式音频，音量、设备状态管理，设备监听和投播功能、支持分布式相机预览，拍照和录像。

**标准系统应用开发框架增强**

事件和通知新增适配DLP；新增支持子系统发送通知。

支持webview复制粘贴，支持基础音视频播放，支持https双向认证等能力。

元能力新增权限校验整改、启动规则、快速修复、卡片可分可合。

ArkUI组件能力增强；资源、媒体查询能力增强；内存、性能优化；DFX能力增强；工具链能力增强。

DeviceProfile适配分布式数据库自动同步策略，以及采集信息补齐。

包管理新增支持缩略图、预览Extension，部分特性新增支持可裁剪配置、支持防呆机制、支持预置应用特定能力管理，安装流程支持hap包不解压，支持快速修复机制。

系统服务管理支持跨设备加载系统服务，foundation进程重启恢复机制，分布式组件管理支持多用户跨设备调用，迁移框架支持单实例Ability迁移等。

**标准系统分布式能力增强**

分布式数据库支持跨设备跨应用分享、RDB支持远程查询/数据库加密特性、支持应用分身，KVDB支持备份恢复/按条件同步/设备上线优先集中同步系统数据。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.2&nbsp;Beta3 | NA |
| Public SDK | Ohos_sdk_public&nbsp;3.2.7.5&nbsp;(API&nbsp;Version&nbsp;9&nbsp;Beta3)<br>Ohos_sdk_public&nbsp;3.2.7.6&nbsp;(API&nbsp;Version&nbsp;9&nbsp;Beta3) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>通过DevEco Studio默认获取的SDK为Public SDK。 |
| Full SDK | Ohos_sdk_full&nbsp;3.2.7.5&nbsp;(API&nbsp;Version&nbsp;9&nbsp;Beta3)<br>Ohos_sdk_full&nbsp;3.2.7.6&nbsp;(API&nbsp;Version&nbsp;9&nbsp;Beta3) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full SDK时需要手动从镜像站点获取，并在DevEco Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Release | OpenHarmony应用开发推荐使用 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.0&nbsp;Release | OpenHarmony智能设备集成开发环境推荐使用 |


## 源码获取


### 前提条件

1. 注册码云gitee帐号。

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

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta3 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta3 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta3 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta3 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）        | 3.2 Beta3    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/code-v3.2-Beta3.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/code-v3.2-Beta3.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制）        | 3.2 Beta3    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/hispark_pegasus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-LiteOS（二进制） | 3.2 Beta3    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta3/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta3/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516轻量系统解决方案-Linux（二进制）  | 3.2 Beta3    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta3/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta3/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）        | 3.2 Beta3    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/dayu200_standard_arm32.tar.gz.sha256) |
| 标准系统Full SDK包（Mac）               | 3.2.7.5      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-mac-full.tar.gz.sha256) |
| 标准系统Full SDK包（Windows\Linux）     | 3.2.7.5      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-windows_linux-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-windows_linux-full.tar.gz.sha256) |
| 标准系统Public SDK包（Mac）             | 3.2.7.5      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public SDK包（Windows\Linux）   | 3.2.7.5      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/ohos-sdk-windows_linux-public.tar.gz.sha256) |
| 标准系统Full SDK包（Mac）               | 3.2.7.6      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/mac-sdk-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/mac-sdk-full.tar.gz.sha256) |
| 标准系统Full SDK包（Windows\Linux）     | 3.2.7.6      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/ohos-sdk-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/ohos-sdk-full.tar.gz.sha256) |
| 标准系统Public SDK包（Mac）             | 3.2.7.6      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/mac-sdk-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/mac-sdk-public.tar.gz.sha256) |
| 标准系统Public SDK包（Windows\Linux）   | 3.2.7.6      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/ohos-sdk-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta3/sdk-patch/ohos-sdk-public.tar.gz.sha256) |



## 更新说明

本版本在OpenHarmony 3.2 Beta2的基础上有如下变更。


### 特性变更

  **表3** 版本特性变更表

| 子系统名称 | 标准系统 | 轻量、小型系统 |
| -------- | -------- | -------- |
| 元能力 | 新增权限校验整改、启动规则、快速修复、卡片可分可合。<br/>主要涉及如下需求：<br/>I581RO&nbsp;【新增特性】最近任务列表适配加密文件沙箱进程<br/>I581SE&nbsp;【新增特性】AMS对沙箱进程增加权限校验<br/>I581XD&nbsp;【新增特性】应用捕获JS&nbsp;Crash异常<br/>I581YL&nbsp;【新增特性】支持卡片分享<br/>I58213&nbsp;【增强特性】提供监听Service/Data/Extension关联关系状态能力<br/>I5824D&nbsp;【新增特性】JS&nbsp;runtime支持worker<br/>I5825N&nbsp;【新增特性】不解压HAP加载应用代码<br/>I5826I&nbsp;【新增特性】不解压HAP加载应用资源<br/>I5826Y&nbsp;【新增特性】加载依赖HAP包中的代码<br/>I5HQEM&nbsp;【新增特性】上下文支持监听WindowStage生命周期<br/>I5MVKZ&nbsp;【新增特性】应用内加载卡片<br/>I5OD2E&nbsp;【新增特性】快速修复服务&nbsp;-&nbsp;安装补丁<br/>I5ODCD&nbsp;【新增特性】快速修复服务&nbsp;-&nbsp;查询补丁<br/>I5PXW4&nbsp;【特性增强】支持查询监听进程/组件可见性等状态能力<br/>I5Q8IU&nbsp;【新增特性】应用内卡片强制刷新<br/>I5QGMS&nbsp;【新增特性】应用内卡片事件管理 | NA |
| 包管理 | 新增支持缩略图、预览Extension，部分特性新增支持可裁剪配置、支持防呆机制、支持预置应用特定能力管理，安装流程支持hap包不解压，支持快速修复机制。<br/>主要涉及如下需求：<br/>I5MZ33&nbsp;【新增特性】支持extension的类型为缩略图、预览<br/>I56WAY【新增特性】包管理特性可裁剪配置<br/>I56WA0【新增特性】防呆机制<br/>I56W8O【新增特性】预置应用特定能力管理<br/>I56WGB【新增特性】安装流程适配hap包不解压<br/>I5N7AD【新增特性】支持补丁包的部署<br/>I5MZ6Z【新增特性】支持补丁包的开机扫描 | NA |
| DFX | 支持faultloggerd混合JS/Native栈打印，hilog&nbsp;domain白名单管理和日志统计功能，hisysevent、hiappeventssh事件能力增强，hidumper内存分类信息优化。<br/>主要涉及如下需求：<br/>I5PJ9O&nbsp;【新增规格】【faultloggerd部件】混合JS/Native栈打印<br/>I5OA3F&nbsp;【新增规格】【DFX子系统】【hisysevent部件】提升HiSysEvent的订阅查询接口易用性<br/>I5NU4L&nbsp;【新增特性】【hilog部件】系统domain白名单管理<br/>I5NU71&nbsp;【新增特性】【hilog部件】日志统计功能<br/>I5NU7F&nbsp;【新增特性】【hilog部件】日志服务权限管理<br/>I5KDIG&nbsp;【新增规格】【DFX子系统】【hisysevent部件】订阅功能提供应对系统事件风暴能力<br/>I5L2RV&nbsp;【新增规格】【DFX子系统】【hisysevent部件】查询功能提供应对系统事件风暴能力<br/>I5LFCZ&nbsp;【新增规格】【DFX子系统】【hisysevent部件】系统事件存储处理提供应用系统事件风暴能力<br/>I5FNPQ&nbsp;【新增规格】【DFX子系统】【hisysevent部件】系统事件打点接口提供应对事件风暴能力<br/>I5NTOS&nbsp;【新增规格】【DFX子系统】【hiappevent部件】hiappevent的事件清理能力<br/>I5NTOD&nbsp;【新增规格】【DFX子系统】【hiappevent部件】hiappevent的事件查询能力<br/>I5LB4N&nbsp;【新增规格】【DFX子系统】【hiappevent部件】hiappevent的事件订阅能力<br/>I5KYYI&nbsp;【新增规格】【DFX子系统】【hiappevent部件】hiappevent的事件分发能力<br/>I5K0X6&nbsp;【新增规格】【DFX子系统】【hiappevent部件】hiappevent的事件管理能力<br/>I5NULM&nbsp;【新增规格】【DFX子系统】【hiview部件】提供读取内核事件处理能力<br/>I5NWZQ&nbsp;【新增特性】对进程SMAPS进一步进行分类，在hidumper信息导出时候展示更加细致的分类信息<br/>I5GXTG&nbsp;【新增特性】hidumper权限隐私优化 | NA |
| 测试子系统 | 单元测试框架新增参数化数据驱动能力；UI测试框架新增抛滑及复杂手势如双指捏合能力接口；xdevice增加任务执行完成后搜集设备DFX日志能力等。<br/>主要涉及如下需求：<br/>I5LI56&nbsp;【新增规格】集成DFX提供日志采集工具<br/>I5LUI8&nbsp;【新增规格】单元测试框架增加参数化驱动能力<br/>I5L5DL&nbsp;【新增规格】UI测试框架新增fling和复杂手势相关接口<br/>I5K2LZ&nbsp;【新增规格】单元/UI测试框架资料刷新<br/>I5MQTL&nbsp;【新增特性】wukong稳定性工具基础能力资料开发readme更新 | NA |
| 系统服务管理子系统 | 支持跨设备加载系统服务，foundation进程重启恢复机制，分布式组件管理支持多用户跨设备调用，迁移框架支持单实例Ability迁移等。<br/>主要涉及如下需求：<br/>I5KMF7【samgr】【增强特性】远程加载系统服务<br/>I5IZ7R【safwk】【新增特性】foundation进程重启恢复机制<br/>I5LO67【分布式组件管理】【新增特性】DMS适配多用户<br/>I5I5FV【分布式组件管理】【新增特性】支持单实例Ability迁移<br/>I5OJD【分布式组件管理】【新增特性】支持组件状态自动迁移<br/>I5NOA1【分布式组件管理】【新增特性】目标端设备上DMS上报应用信息 | NA |
| DeviceProfile子系统 | DeviceProfile适配分布式数据库自动同步策略，以及采集信息补齐。<br/>主要涉及如下需求：<br/>I5QPGN【device_profile部件】【增强特性】DP适配数据库自动同步策略<br/>I5J7PW【device_profile部件】【增强特性】补齐DP基础信息 | NA |
| 事件通知子系统 | 事件和通知新增适配DLP；新增支持子系统发送通知。<br/>主要涉及如下需求：<br/>I582TY【新增规格】通知适配DLP<br/>I582VA&nbsp;【新增规格】事件适配DLP<br/>I5P1GU【distributed_notification_service部件】支持子系统发送通知 | NA |
| 多模输入子系统 | 提供鼠标样式和速度设置、鼠标上报事件增强，配置序列拉起应用，键鼠穿越等特性。<br/>主要涉及如下需求：<br/>I530UX&nbsp;【新增特性】支持修改鼠标移动速度<br/>I530VT&nbsp;【新增特性】支持显示/隐藏鼠标图标<br/>I530XP&nbsp;【新增特性】支持鼠标加速算法<br/>I530XS&nbsp;&nbsp;【新增特性】支持多种鼠标样式<br/>I530UQ&nbsp;【新增特性】分布式输入<br/>I5HMF3&nbsp;【增强特性】支持鼠标离开窗口时上报事件<br/>I5HMEF&nbsp;【增强特性】鼠标上报事件增强<br/>I5HMD9&nbsp;【input部件】配置按键序列拉起Ability<br/>I5P6TG&nbsp;键鼠穿越鼠标光标自适应显示<br/>I5P6UW&nbsp;键鼠穿越状态管理<br/>I5HMCX&nbsp;【新增特性】支持键盘功能按键使能去使能<br/>I5HMCB&nbsp;【input部件】输入设备相关的多热区 | NA |
| 泛sensor服务子系统 | 提供马达优先级管理能力。<br/>主要涉及如下需求：<br/>I53SGE&nbsp;【新增规格】支持马达优先级管理 | NA |
| 分布式数据管理子系统 | 支持跨设备跨应用分享、RDB支持远程查询/数据库加密特性、支持应用分身，KVDB支持备份恢复/按条件同步/设备上线优先集中同步系统数据。<br/>主要涉及如下需求：<br/>I5JV75【新增特性】【relational_store部件】支持远程查询特性<br/>I5LBDS【新增特性】【kv_store部件】支持DLP沙箱应用的数据独立隔离<br/>I5JZM1【data_object部件】分布式数据对象支持应用分身<br/>I5OM83【kv_store部件】支持按条件同步数据<br/>I5OE57【新增特性】【relational_store部件】数据库加密保存<br/>I5QN1E【kv_store部件】设备上线优先集中同步系统数据 | NA |
| web子系统 | 支持webview复制粘贴，支持基础音视频播放，支持https双向认证等能力。<br/>主要涉及如下需求：<br/>I5QA3D【新增特性】webview支持页面图文混排内容的选中和复制<br/>I5P97S【增强特性】web支持w3c&nbsp;input标签自动获焦下绑定输入法<br/>I5P001【增强特性】webview支持shift连选多个文字<br/>I5OZZ8【新增特性】webview支持鼠标左键滑动选词<br/>I5OURV【增强特性】webview支持软键盘弹出效果优化<br/>I5ORNO【新增特性】支持webview的https的双向校验<br/>I5OESN【增强特性】webview支持w3c&nbsp;draggable属性<br/>I5O4BN【新增特性】webview剪切板对接系统剪切板<br/>I5O4BB【新增特性】webview支持页面图片（渲染图）的获取<br/>I5O4B5【新增特性】webview支持页面input标签粘贴纯文本<br/>I5O4AZ【新增特性】webview支持页面纯文本的获取<br/>I5NXG9【新增规格】web组件touch、scroll、gesture事件支持<br/>I5LIL6【新增特性】web组件的应用和h5的消息交互<br/>I5JTLQ【新增规格】web组件长按区域手柄绘制事件通知<br/>I5HRX9【新增特性】webview支持多媒体播放基础能力 | NA |
| 内核子系统 | 新增内存压力通知AMS、回收优先级管理支持常驻系统服务，回收优先级管理支持区分extension状态等基础能力。<br/>新增前向CFI保护。<br/>内核编译切换为CLANG编译器。<br/>主要涉及如下需求：<br/>I5K0VE&nbsp;&nbsp;通知AMS内存等级<br/>I5BND4&nbsp;&nbsp;上报adj模块系统应用被查杀后是否能够重启<br/>I5BNEC&nbsp;&nbsp;提供监听Service/Data/Extension关联关系转态能力<br/>I5MXBS&nbsp;&nbsp;Forward-Edge&nbsp;CFI，内核新增前向CFI能力<br/>I5P4FB&nbsp;&nbsp;使能前向CFI<br/>I5LX3A&nbsp;&nbsp;Building&nbsp;Linux&nbsp;with&nbsp;Clang/LLVM | NA |
| 媒体子系统 | 支持分布式音频、音量、设备状态管理，设备监听和投播功能；支持3.5mm耳机设备；支持分布式相机预览、拍照和录像功能，meta信息管理支持。<br/>I5NYBJ&nbsp;【性能】媒体播放启动时间<br/>I5NYCF&nbsp;【新增特性】支持基于HDI&nbsp;codec接口的视频硬编码能力<br/>I5NYCP&nbsp;【新增特性】支持基于HDI&nbsp;codec接口的视频硬解码能力<br/>I5OOKN&nbsp;【新增特性】支持h.265格式视频硬解码<br/>I5OOKW&nbsp;【新增特性】支持h.265格式视频硬编码<br/>I5OWXY&nbsp;【新增特性】支持音频解码native接口<br/>I5OXCD&nbsp;【新增特性】支持音频编码native接口<br/>I5P8N0&nbsp;【新增特性】支持视频编码native接口<br/>I5O336&nbsp;【新增特性】支持单应用音频投播和系统所有音频投播<br/>I5OEWG&nbsp;【新增特性】支持系统应用设置和获取单个音频流的音量 | NA |
| 语言编译运行时子系统 | 前端编译性能提升，如es2abc。<br/>运行时性能提升优化，如ISA重构优化、汇编解释器、TSAOT等。<br/>新增功能，如支持严格模式的ES2021、模块化支持、Runtime&nbsp;调试调优增强、字节码热重载等。<br/>具体如下：<br/>I5MYM9&nbsp;【新增规格】运行时多模块单abc文件合并适配<br/>I59TAQ【新增规格】支持TSAOT优化编译器标准编译lowering和优化pass（规格）描述<br/>I5OJ8Q【新增规格】IDE属性查看功能补齐已支持的2021规范定义的类型<br/>I5ODV4&nbsp;【新增特性】&nbsp;支持字节码补丁文件卸载功能<br/>I5OXSC&nbsp;【新增特性】&nbsp;支持字节码补丁文件加载功能<br/>I5HNNZ&nbsp;【新增特性】使能加载器的命名空间<br/>I5HVQE&nbsp;&nbsp;【新增特性】线程stacksize根据产品配置，增加stack&nbsp;pageguard保护<br/>I5MCUF【增强特性】libc增加CAPI接口，支持pthread等符号<br/>I5HVNH【新增特性】RM.006.增强动态库符号管理<br/>I5HVQ0&nbsp;【新增特性】RM.008.musl支持fortify功能<br/>I5KT7X&nbsp;【新增特性】RM.002.提供API头文件API检测功能<br/>I5TB3Y&nbsp;【新增特性】ABI默认使用emutls特性<br/>I5R119&nbsp;&nbsp;【增强特性】拆分加载器与libc内存使用<br/>支持clang工具链的开源构建<br/>I5MYM9【新增规格】前端编译工具链支持模块化编译<br/>I5IKO1【新增规格】前端abc支持commonjs模块<br/>I5RRAJ【新增规格】补丁文件源码识别工具<br/>I5PRFT【新增规格】补丁字节码编译工具<br/>I5RHDH【新增规格】支持方舟字节码热加载<br/>I5RA7C【新增规格】支持strict模式2021<br/>I5HRUY【新增规格】es2abc支持js转换方舟字节码 | NA |
| 帐号&amp;程序访问控制子系统 | 帐号服务新增用户身份认证服务；权限服务新增支持精准定位或模糊定位，以及其他能力增强；新增隐私管理服务。<br/>主要涉及如下需求：<br/>I5N90B【新增规格】应用帐号适配沙箱应用<br/>I5N90O【新增规格】帐号子系统新增用户身份认证服务<br/>I5NOQI【新增特性】权限服务支持精准定位或模糊定位<br/>I5NT1X【新增特性】权限使用记录管理增强<br/>I5NU8U【新增特性】权限弹框UX界面增强<br/>I5P4IU【新增特性】新增隐私管理服务<br/>I5P530【新增特性】位置服务使用状态管理 | NA |
| 全球化子系统 | 新增支持翻译伪本地化能力。<br/>涉及如下需求：<br/>I4WLSJ&nbsp;【新增特性】翻译伪本地化能力 | NA |
| Misc服务子系统 | 新增剪贴板、上传下载、锁屏、输入法框架等模块基础特性。<br/>主要涉及如下需求：<br/>I5JPMG&nbsp;【request部件】【download】后台任务通知<br/>I5NXHK&nbsp;【input_method_fwk部件】输入法框架支持仅绑定输入法innerkits接口和独立控制软键盘显隐的js接口<br/>I5NG2X&nbsp;【theme_screenlock部件】支持特定系统应用请求锁定屏幕<br/>I5IU1Z&nbsp;&nbsp;支持向剪贴板数据增加图片内容的数据项<br/>I5OGA3&nbsp;&nbsp;支持剪贴板插件加载开关<br/>I5NMKI&nbsp;【pasteboard部件】支持向剪贴板数据增加二进制数据<br/>I5MAMN&nbsp;&nbsp;支持剪贴板数据范围限制在应用内<br/>I5OX20&nbsp;【input_method_fwk部件】输入法框架支持获取输入法扩展 | NA |
| ArkUI子系统 | ArkUI组件能力增强；资源、媒体查询能力增强；内存、性能优化；DFX能力增强；工具链能力增强。<br/>主要涉及如下需求：<br/>I5IZZ7&nbsp;【ace_engine_standard部件】panel组件支持单独设置每个角的borderRadius<br/>I5JQ1R&nbsp;【ace_engine_standard部件】支持图片复制粘贴<br/>I5JQ3F&nbsp;【ace_engine_standard部件】输入框能力增强<br/>I5JQ3J&nbsp;【ace_engine_standard部件】stack组件新增事件拓传机制<br/>I5JQ54&nbsp;【ace_engine_standard部件】指定控件获取焦点<br/>I5MX7J&nbsp;【ace_engine_standard部件】list列表支持左滑/右滑及回弹效果<br/>I5MWS0&nbsp;【ace_engine_standard部件】panel组件弹出高度通知给开发者<br/>I5IZVY&nbsp;【ace_engine_standard部件】键鼠接入时支持组件刷新<br/>I5JQ5Y&nbsp;【ace_engine_standard部件】走焦能力增强<br/>I5IY7K&nbsp;【新增需求】【ace_engine_standard部件】主题能力支持<br/>I5MWTB&nbsp;【ace_engine_standard部件】媒体查询支持vp查询<br/>I5IZU9&nbsp;【ace_engine_standard部件】ui_service常驻内存优化<br/>I5JQ26&nbsp;【ace_engine_standard部件】Vsync请求机制流程优化<br/>I5JQ2O&nbsp;【ace_engine部件】公共资源预加载<br/>I5JQ2D&nbsp;【ace_engine_standard部件】Move事件重采样优化<br/>I5IZXS&nbsp;【toolchain部件】DFX打印错误堆栈时支持显示开发者变量名称原文<br/>I5IZYG&nbsp;【toolchain部件】DFX打印错误堆栈时支持显示开发者变量名称原文<br/>I5IZX0&nbsp;【toolchain部件】编译支持解析$r新增bundleName和moduleName参数<br/>I5J09I&nbsp;【toolchain部件】\@Builder&nbsp;支持export导出 | NA |

API变更请参考：

[*API差异报告*](api-diff/v3.2-beta3/js-apidiff-ability.md)


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

  **表4** 新增Samples

| 子系统 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| ArkUI | [HealthyDiet：健康饮食](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/HealthyDiet) | 这是一个记录饮食和查看食物信息的应用，主要用于管理饮食健康。可以添加饮食信息，包括食物的种类、重量以及用餐时间，如早餐、&nbsp;午餐、晚餐和夜宵，并能统计得到相应用餐时间的总热量值、总蛋白质、总脂肪和总碳水值，并且用柱状图的形式展示出来。 | ArkTS |
| ArkUI | [MusicAlbum：一多音乐专辑主页](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/MusicAlbum) | 本示例展示了音乐专辑主页，使用一次开发多端部署中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示。 | ArkTS |
| 元能力、文件管理 | [CustomShare：自定义分享](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/CustomShare) | 分享的主要工作是实现：发送方将文本，链接，图片文件三种类型分享给三方应用,同时能够在三方应用中分别呈现出来。 | ArkTS |
| 元能力 | [FormExtAbility：Stage模型卡片](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/FormExtAbility) | 本示例展示了Stage模型卡片提供方的创建与使用。 | ArkTS |
| ArkUI | [AppMarket：一多应用市场首页](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/AppMarket) | 本示例展示了应用市场首页，页面中包括Tab栏、运营横幅、精品应用、精品游戏等。 | ArkTS |
| ArkUI | [Weather：一多天气](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Weather) | 本示例展示一个天气应用界面，包括首页、城市管理、添加城市、更新时间弹窗，体现一次开发，多端部署的能力。 | ArkTS |
| 媒体 | [MediaCollections：媒体管理合集](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/MediaCollections) | 本示例展示了网络流播放能力、音视频播控能力、音量调节能力等。 | ArkTS |

请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。


## 修复缺陷列表

  **表5** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| I5I4GJ | 通过IDE连接RK3568设备概率断连。 |
| I5HTGF | 相机拍出来照片跟预览相比顺时针旋转90度。 |
| I5FUNB | linux内核漏洞同步<br/>CVE-2022-1462 |



## 遗留缺陷列表

  **表6** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I59PWR | 在RK3568设备上对Openharmony&nbsp;进行内存测试，com.ohos.launcher基线值84279KB，超基线200MB | 占用内存超过预期，但不影响整机内存的正常使用。 | 10月20号 |
| I59QII | 在RK3568设备上对Openharmony&nbsp;进行常驻内存测试，netmanager进程&nbsp;基线值1241KB，实测值3884KB,超基线2.58Mony&nbsp;进行内存测试，netmanager进程&nbsp;基线值1241KB，超基线1MB | 占用内存超过预期，但不影响整机内存的正常使用。 | 10月20号 |
| I5LH57 | 在RK3568设备上对Openharmony&nbsp;进行常驻内存测试，telephony&nbsp;进程&nbsp;基线值8434KB，实测值10329KB,超基线1.85MB | 占用内存超过预期，但不影响整机内存的正常使用。 | 10月20号 |
| I5Q5PR | 在RK3568设备上对Openharmony&nbsp;进行常驻内存测试，wifi_hal_service进程&nbsp;基线值&nbsp;829KB，实测值4374KB,超基线3.4MB | 占用内存超过预期，但不影响整机内存的正常使用。已达成，无功能影响 | 10月20号 |
| I5T71O | 在RK3568设备上对Openharmony&nbsp;进行动态内存测试，com.ohos.settings进程&nbsp;基线值&nbsp;15824&nbsp;KB，实测值&nbsp;76123KB，超基线58.8MB | 占用内存超过预期，但不影响整机内存的正常使用。 | 10月20号 |
| I5S40B | 联系人列表滑动帧率标准值：54fps，实际值：30.3fps，较基线少23.7fps | 影响负载胜率指标，依赖于ArkUI框架重构，重构需求交付时间10月15号。 | 10月15号 |
| I5MVDK | 对&nbsp;/data/data/.pulse_dir/runtime/cli&nbsp;进行socketfuzz出现crash | 进行socketfuzz测试，发生进程crash。 | 10月18日 |
| I5M3UO | [TTE&nbsp;WRC&nbsp;team]&nbsp;New&nbsp;line&nbsp;injection&nbsp;via&nbsp;Wi-Fi&nbsp;SSID&nbsp;name&nbsp;in&nbsp;wifi_manager_service | WIFI的SSID输入非法字符（\n）,&nbsp;配置文件存储并解析会出现异常。 | 10月12日 |
| I5T8FV | 校验权限在系统中未定义未真实生效 | 权限未在系统中定义，鉴权时不通过，无进程可申请该权限，当前无业务调用。 | 10月18日 |
