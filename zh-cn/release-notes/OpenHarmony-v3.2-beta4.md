# OpenHarmony 3.2 Beta4


## 版本概述

当前版本在OpenHarmony 3.2 Beta3的基础上，更新支持或优化增强的能力如下：

**标准系统基础能力增强**

程序访问控制子系统支持前向CFI、API异常处理优化等；

内核子系统支持Hyperhold内存扩展特性增强、F2FS末端性能增强优化；

多模输入子系统支持键盘功能按键使能去使能、输入设备相关的多热区支持；

图形子系统支持基于共享内存机制传输图形数据、支持YUV图层、RS侧支持GPU合成、虚拟屏支持旋转和动态分辨率等；

升级子系统支持AB热升级功能、flashd升级支持AB分区设备升级、SD/OTG升级支持AB分区设备升级；

全球化子系统支持设备管理事件按需订阅、系统资源支持overlay差分、资源管理支持跨OS平台能力；

Misc软件子系统支持PUT方式上传文件、下载管理支持配置下载任务、输入法框架优化和增强，支持打印服务框架；

DFX子系统支持功耗数据采集、系统事件数据采集、perf数据采集等；

ArkTS API新增支持错误码的上报，帮助开发者快速捕捉异常，提升异常处理的效率。

**标准系统应用开发框架增强**

支持动态库隔离，运行管理支持待处置应用拦截；

支持窗口属性设置、支持ArkTS卡片交互、XComponent提供容器组件能力等；

支持配置应用的依赖关系，支持对应用安装及卸载的名单进行增、删、查操作，支持对禁止运行的应用名单进行增、删、查操作。

**标准系统分布式能力增强**

分布式硬件支持同帐号凭据参数请求和导入。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.2 Beta4 | NA |
| Public SDK | Ohos_sdk_public 3.2.9.2 (API Version 9 Beta4) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
| Full SDK | Ohos_sdk_full 3.2.9.2 (API Version 9 Beta4) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。使用Full SDK时需要手动从镜像站点获取，并在DevEco Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| HUAWEI DevEco Studio（可选） | 3.1 Canary1 | OpenHarmony应用开发推荐使用。 |
| HUAWEI DevEco Device Tool（可选） | 3.1 Beta1 | OpenHarmony智能设备集成开发环境推荐使用。 |


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta4 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta4 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta4 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta4 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 3.2 Beta4    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/code-v3.2-Beta4.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/code-v3.2-Beta4.tar.gz.sha256) | 19.0 GB |
| Hi3861轻量系统解决方案（二进制）        | 3.2 Beta4    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/hispark_pegasus.tar.gz.sha256) | 22.6 MB |
| Hi3516轻量系统解决方案-LiteOS（二进制） | 3.2 Beta4    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta4/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta4/hispark_taurus_LiteOS.tar.gz.sha256) | 293.9 MB |
| Hi3516轻量系统解决方案-Linux（二进制）  | 3.2 Beta4    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta4/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta4/hispark_taurus_Linux.tar.gz.sha256) | 173.2 MB |
| RK3568标准系统解决方案（二进制）        | 3.2 Beta4    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/dayu200_standard_arm32.tar.gz.sha256) | 3.2 GB |
| 标准系统Full SDK包（Mac）               | 3.2.9.2      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-mac-full.tar.gz.sha256) | 662.5 MB |
| 标准系统Full SDK包（Windows\Linux）     | 3.2.9.2      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-windows_linux-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-windows_linux-full.tar.gz.sha256) | 1.5 GB |
| 标准系统Public SDK包（Mac）             | 3.2.9.2      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-mac-public.tar.gz.sha256) | 622.2 MB |
| 标准系统Public SDK包（Windows\Linux）   | 3.2.9.2      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta4/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.5 GB |


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

## 更新说明

本版本在OpenHarmony 3.2 Beta3的基础上有如下变更。


### 特性变更

  **表3** 版本特性变更表

| 子系统名称 | 标准系统 | 轻量、小型系统 |
| -------- | -------- | -------- |
| 公共 | ArkTS API新增支持错误码的上报，帮助开发者快速捕捉异常，提升异常处理的效率。 | NA |
| 元能力子系统 | 运行管理弹框整改，优化了应用弹框的合理性。<br/>主要涉及需求：<br/>I5X5J9 【ability_runtime部件】运行管理弹框整改 | NA |
| ArkUI子系统 | - Navigation组件分栏场景、单页面场景重构<br/>- XComponent提供容器组件能力<br/>主要涉及需求：<br/>I5X5GE 交互归一能力增强<br/>I5X5FX 支持ArkTS卡片交互<br/>I5X5G3 Navigation组件分栏场景重构<br/>I5X5G4 Navigation组件单页面场景重构<br/>I5X5GG XComponent提供容器组件能力 | NA |
| 程序访问控制 | 新增对于敏感资源使用的隐私管控。<br/>主要涉及需求：<br/>I5RWXF 【新增特性】麦克风的全局开关设置管理<br/>I5RWX8 【新增特性】麦克风使用状态管理 | NA |
| 系统服务管理子系统 | 新增分布式调用组件管控，禁止应用在后台恶意拉起应用、保活。<br/>主要涉及需求：<br/>I5T6GJ 【分布式组件管理】【DMS】ability组件启动管控<br/>I5T6HF 【分布式组件管理】【DMS】ServiceAbility/ServiceExtension组件启动管控 | NA |
| 媒体子系统 | - 新增对于敏感资源使用的隐私管控。<br/>- 支持音量根据设备分组设置、DTMF拨号音。<br/>主要涉及需求：<br/>I5X5HT 【增强特性】支持音量根据设备分组设置<br/>I5X5IF 【新增特性】支持语音播报播放类型和语音识别录音类型<br/>I5X48J 【新增特性】支持DTMF拨号音 | NA |
| 测试子系统 | SmartPerf-Host工具新增内核内存事件分析能力，增强性能问题定位能力。<br/>主要涉及需求：<br/>I5X55J 【新增特性】内核内存事件分析 | NA |
| 包管理子系统 | 支持应用的安装管控和启动管控<br/>主要涉及需求：<br/>I5MZ8K 【新增特性】支持增、删、查应用禁止运行的名单<br/>I5MZ8Q 【新增特性】支持增、删、查应用安装和卸载的应用名单 | NA |
| 事件通知子系统 | 使用自定义的系统hap弹窗替换原有UIService弹窗，达到降低ArkUI内存目的。<br/>主要涉及需求:<br/>I5X5L0 替换UIService弹框方案，通过预置应用实现通知使能弹窗 | NA |
| 分布式硬件子系统 | 通过优化PIN码弹框的实现，提高模块稳定性。<br/>主要涉及需求：<br/>I5X5KX 【增强特性】优化PIN码弹框实现，提高弹框稳定性 | NA |
| 升级子系统 | 新增AB热升级特性<br/>主要涉及需求：<br/>I5X4RO【增强特性】update_service部件支持AB升级功能<br/>I5X4RQ【updater部件】AB热升级功能资料输出<br/>I5X4RR【新增特性】flashd升级支持AB分区设备升级<br/>I5X4RT【新增特性】SD/OTG升级支持AB分区设备升级<br/>I5X4RU【新增特性】支持AB热升级 | NA |
| 内核子系统 | ARM64 CPU新增支持限制特权用户访问非特权用户可访问的内存。如果特权用户尝试访问非特权用户可以访问的内存，会抛出异常。<br/>Hyperhold内存通过高速交换分区技术以及对应策略配合，支撑应用后台保活能力。<br/>主要涉及需求：<br/>I5X5AR 【新增特性】ARM64支持PAN<br/>I5X5AS 【新增特性】ARM64支持PXN<br/>I5X5B9 【新增特性】Hyperhold内存扩展特性：通过高速交换分区技术以及对应策略配合，支撑应用后台保活能力 | NA |
| 图形图像 | 新增支持窗口拖拽场景光标样式设置。<br/>主要涉及需求：<br/>I5X5D9 窗口拖拽场景光标样式设置 | NA |
| 语言编译运行时子系统 | Runtime新增支持生成AOT的PGO文件。<br/>主要涉及需求：<br/>I5X5K3 【新增规格】 Runtime支持生成AOT的PGO文件<br/>I5X5K2 【新增规格】 AOT支持 PGO配置 | NA |
| web子系统 | - webview新增支持页面图文混排内容的选中和复制。<br/>- web组件支持窗口事件、全屏事件、以及url的获取。<br/>主要涉及需求：<br/>I5QA3D 【新增特性】webview支持页面图文混排内容的选中和复制<br/>I5X53B 【增强特性】web组件支持url获取<br/>I5R6E0 【新增规格】web组件全屏事件支持<br/>I5X53C 【新增规格】web组件窗口事件支持 | NA |
| Misc软件服务子系统 | - 输入法框架新增支持输入法和输入法子类型切换及变更的监听<br/>- 上传下载能力新增支持PUT方式上传文件。<br/>主要涉及需求：<br/>I5X5LA 【input_method_fwk部件】输入法框架支持输入法和输入法子类型切换及变更监听<br/>I5X5LR 【request部件】支持PUT方式上传文件 | NA |
| USB服务子系统 | USB请求权限弹窗适配新的系统弹窗方案。<br/>主要涉及需求：<br/>I5UYX4【新增特性】USB请求权限弹窗适配系统弹窗新方案 | NA |
| 文件管理子系统 | 文件打开读写等高频API跨平台兼容。<br/>主要涉及需求：<br/>I5X5E5 【fileAPI部件】【能力桥接】目标平台fileIO能力桥接<br/>I5X5E6 【fileAPI部件】【能力桥接】目标平台fileIO能力桥接<br/>I5X4P2 【filePicker】适配文件访问框架接口修改 | NA |
| DFX | - 对HiTrace的打点接口、调用链接口从底层概念进行统一。<br/>- 新增支持功耗数据、系统事件数据的采集。<br/>- 新增支持JS HAP在启动过程中及时采集perf数据。<br/>主要涉及需求：<br/>I5X4TY 【新增特性】支持HiTrace统一概念的HiTraceMeter打点接口<br/>I5X4U1 【新增特性】支持HiTrace统一概念的HiTraceChain调用链接口<br/>I5X4TD 【新增特性】功耗数据采集<br/>I5X4TE 【新增特性】系统事件数据采集<br/>I5X4TL 【新增特性】支持JS HAP启动过程及时采集perf数据 | NA |



API变更请参考：

[*API差异报告*](api-diff/v3.2-beta4/js-apidiff-ability.md)



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

### Samples

本版本在ArkTS语言下新增如下Samples：

  **表4** 新增Samples

| 子系统<div style="width:100px"></div> | 名称 | 简介 |
| -------- | -------- | -------- |
| 事件通知 | [CustomEmitter: 事件通知](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomEmitter) | 本示例主要展示进程内事件通知，用户通过选择对应商品并提交订单后在订单列表显示所选商品。 |
| 数据管理 | [CrossAppDataShare: 跨应用数据共享](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DataManagement/CrossAppDataShare) | 本示例实现了一个跨应用数据共享实例，分为联系人（数据提供方）和联系人助手（数据使用方）两部分：联系人支持联系人数据的增、删、改、查等功能；联系人助手支持同步联系人数据，当联系人与联系人助手数据不一致时，支持合并重复数据。 |
| 资源调度 | [ReminderAgentManager: 后台代理提醒](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/ReminderAgentManager) | 本示例通过使用后台代理提醒的能力，创建闹钟、日历、计时器三种类型的定时提醒，保证应用被冻结或退出时，计时和弹出提醒的功能可以被后台系统服务代理。 |
| 文件管理 | [StorageStatistic: 存储空间统计](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/StorageStatistic) | 本示例通过应用程序包管理、应用空间统计与卷管理模块，实现了查看当前设备存储空间信息、所有安装的应用的存储信息、所有可用卷的存储信息的功能。 |
| 窗口 | [Screenshot: 截屏](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/Screenshot) | 本示例通过screenshot模块实现屏幕截图 ，通过window模块实现隐私窗口切换，通过display模块查询当前隐私窗口。 |
| 包管理 | [MultiHap: 多HAP](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Project/ApplicationHap/MultiHap) | 本示例展示多HAP开发，简单介绍了多HAP的使用场景，应用包含了一个entry HAP和两个feature HAP，两个feature HAP分别提供了音频和视频播放组件，entry中使用了音频和视频播放组件。 |
| 元能力 | [AbilityStartMode: Ability的启动模式](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/AbilityStartMode) | 本示例展示了在一个Stage模型中，实现standard、singleton、specified多种模式场景。 |
| 资源管理 | [ApplicationThemeSwitch: 应用主题切换](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Project/ResourceAllocation/ApplicationThemeSwitch) | 本示例通过创建base同级资源文件夹dark和light完成深色浅色主题相关资源配置，实现深色浅色主题切换，在ThemeConst文件中配置自定义主题文件，通过控制变量实现多主题切换。 |

请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。



## 修复缺陷列表

  **表5** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| I5S40B | 联系人列表滑动帧率标准值：54fps，实际值：30.3fps，较基线少23.7fps |
| I5MVDK | 对 /data/data/.pulse_dir/runtime/cli 进行socketfuzz出现crash |
| I5M3UO | [TTE WRC team] New line injection via Wi-Fi SSID name in wifi_manager_service |
| I5SXXR | 轻量级图形存在高权限进程 |


## 遗留缺陷列表

  **表6** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I5KMQX | 【rk3568】【ToC】【概率：必现】联系人-拨号子Tab切换完成时延标准值：440ms，实际值：1770.8ms，超基线1330ms | 静态KPI和负载整体已达标，影响可控 | 2022年12月30号 |
| I61M6T | 在RK3568设备上对Openharmony 进行常驻内存测试，com.ohos.launcher 进程基线值84279KB，实测值 99514KB,超基线14.8M | 整机内存已达标，影响可控 | 2022年12月30号 |
| I59QII | 在RK3568设备上对Openharmony 进行常驻内存测试，netmanager进程 基线值1241KB，实测值3884KB,超基线2.58Mony 进行内存测试，netmanager进程 基线值1241KB，超基线1M | 整机内存已达标，影响可控 | 2022年12月30号 |
| I5Q5PR | 在RK3568设备上对Openharmony 进行常驻内存测试，wifi_hal_service进程 基线值 829KB，实测值4374KB,超基线3.4M | 整机内存已达标，影响可控 | 2022年12月30号 |
| I61E1I | RK3568间BR引导P2P传输失败 | 软总线通过蓝牙传输和局域网传输可以成功、BR引导P2P传输会概率失败 | 2022年12月30号 |
| I63DX6 | RK3568间wifi引导P2P传输字节失败 | 软总线通过蓝牙传输和局域网传输可以成功、wifi引导P2P传输会概率失败 | 2022年12月30号 |
| I63FEA | 【rk3568】启动系统相机应用，预览画面逆时针90度旋转 | 硬件适配问题，8G内存的RK3568有相机转角问题，4G内存的RK3568无此问题 | 2022年12月30号 |
| I62EW1 | L1,media_server进程使用root权限，进程权限过高，请整改 | media_server进程中跑了部分芯片组件的业务，当前需要root权限，需要解耦优化 | 2022年12月30号 |
| I5XYRX、I5YTYX、I5YU16、I5YUB4、I5YUBS | 蓝牙协议栈模块相关函数存在越界读漏洞 | 蓝牙协议栈模块相关函数存在越界读漏洞 | 2022年12月30号 |
| I5SSEW、I5UFS1、I5ICMZ、I5ICM7、I5QC6H、I5R2L5、I5R2LI、I5SQO0、I5UDY5、I5YPMZ | 组件giflib、组件das u-boot，内核：I5ICMZ、I5ICM7、I5QC6H、I5R2L5、I5R2LI、I5SQO0、I5UDY5、I5YPMZ等漏洞 | 待三方组件及内核官网漏洞发布后进行同步，目前无补丁方案 | 2022年12月30号 |
