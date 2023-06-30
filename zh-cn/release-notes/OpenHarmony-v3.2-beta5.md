# OpenHarmony 3.2 Beta5


## 版本概述

当前版本在OpenHarmony 3.2 Beta4的基础上，更新支持或优化增强的能力如下：

**标准系统基础能力增强**

webview启动性能优化；配置管理和对输入事件的支持等能力增强；模块化模式下可导入json文件并加载。

支持taskpool；hap包动态库不压缩加载；host版本TS2AOT-tool工具；编译器运行时支持应用内共享包。

支持安装/更新/卸载动态共享库；支持动态共享库打包和拆包；对未配置入口图标的应用，可在桌面显示默认图标；HAR共享包运行期能力可验证。

卡片本地数据库切换；常驻应用异常频繁重启保护；ServiceExtensionAbility支持异步onConnected生命周期。

支持本地帐号与域帐号绑定、认证，以及域帐号管理服务基础框架；支持禁止直接创建本地用户。

支持电源灯、light灯能力控制。

HDI驱动显示图层，可以实现对水平镜像和垂直镜像的支持。

**标准系统应用开发框架增强**

工具链新增编译共享包流程。

ArkUI适配了根据资源名称获取资源的能力。

提供多级菜单和分组菜单的组件能力。

新增编译har包的流程。

新增适配hap编译流程的能力，hap编译时能识别.d.ets声明文件。

**标准系统分布式能力增强**

支持BLE连接参数配置，连接过程优化。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.2 Beta5 | NA |
| Public SDK | Ohos_sdk_public 3.2.10.6 (API Version 9 Beta5) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br />通过DevEco Studio默认获取的SDK为Public SDK。 |
| HUAWEI DevEco Studio（可选） | 3.1 Beta1 | OpenHarmony应用开发推荐使用。 <br />[请点击此处获取](https://developer.harmonyos.com/cn/develop/deveco-studio#download) |
| HUAWEI DevEco Device Tool（可选） | 3.1 Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 <br />[请点击此处获取](https://device.harmonyos.com/cn/develop/ide#download) |


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta5 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta5 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta5 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta5 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 3.2 Beta5    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/code-v3.2-Beta5.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/code-v3.2-Beta5.tar.gz.sha256) | 21.3 GB |
| Hi3861解决方案（二进制）        | 3.2 Beta5    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/hispark_pegasus.tar.gz.sha256) | 22.9 MB |
| Hi3516解决方案-LiteOS（二进制） | 3.2 Beta5    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta5/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta5/hispark_taurus_LiteOS.tar.gz.sha256) | 293.6 MB |
| Hi3516解决方案-Linux（二进制）  | 3.2 Beta5    | [站点](hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta5/hispark_taurus_Linux.tar.gz.sha256) | 174.3 MB |
| RK3568标准系统解决方案（二进制）        | 3.2 Beta5    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/dayu200_standard_arm32_20230201.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/dayu200_standard_arm32_20230201.tar.gz.sha256) | 3.9 GB |
| 标准系统Public SDK包（Mac）             | 3.2.10.6      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/ohos-sdk-mac-public.tar.gz.sha256) | 674.5 MB |
| 标准系统Public SDK包（Mac-M1）             | 3.2.10.6      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 634.5 MB |
| 标准系统Public SDK包（Windows\Linux）   | 3.2.10.6      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.6 GB |



## 更新说明

本版本在OpenHarmony 3.2 Beta4的基础上有如下变更。

### SDK变更

从本版本起，仅发布Public SDK，开发者可从镜像站点获取或通过DevEco Studio下载Public SDK用于应用开发。

包含系统接口的全量SDK（Full SDK）需下载全量代码后编译构建出SDK文件，并在DevEco Studio中替换。通过源码编译Full SDK的指导请参见[Full-SDK编译指南](../application-dev/faqs/full-sdk-compile-guide.md)。


### 特性变更

  **表3** 版本特性变更表

| 子系统名称 | 标准系统 | 轻量、小型系统 |
| -------- | -------- | -------- |
| ArkUI | - 支持通过资源名称获取资源。<br/>- 组件支持多级菜单和分组菜单。<br/>- 编译能力增强。<br/>主要涉及以下需求：<br/>I683Z1 【新增功能】ArkUI适配根据资源名称获取资源<br/>I68DBH 【基础能力】提供多级菜单和分组菜单能力<br/>I68DRY【新增功能】新增编译har包的流程<br/>I68DRY【新增功能】适配hap编译流程，hap编译时能识别.d.ets声明文件<br/>I68DRY【新增功能】工具链新增编译共享包流程 | NA |
| Web子系统 | webview部件新增支持多项能力，包括：<br/>- web页面的加载和显示支持历史记录和前进/后退、支持页面加载各类事件上报、webmessage支持arraybuffer类型、fetch支持自定义协议。<br/>- webview的配置管理支持滚动条和滚动位置、支持网络加载拦截配置、支持判断页面中是否有image、支持获取源url/请求方法/网站图标、支持字体管理。<br/>- 支持web上下文菜单中获取页面选中内容。<br/>- 输入事件支持交互归一、支持原始输入事件。<br/>- 新增支持若干W3C接口。<br/>主要涉及以下需求：<br/>I6BFPR 【功能增强】【webview部件】web页面的加载和显示 （支持历史记录和前进后退列表管理)<br/>I6BFRC 【功能增强】【webview部件】支持W3C接口(html-部分用例)<br/>I6BFS6 【功能增强】【webview部件】支持W3C接口(css-部分用例)<br/>I6BFSK 【功能增强】【webview部件】web页面的加载和显示 （1.webmessage支持arraybuffer类型）<br/>I6BFTS 【功能增强】【webview部件】支持W3C接口( 1.支持appmanifest等)<br/>I6BFUD 【功能增强】【webview部件】web页面的加载和显示（1.fetch支持自定义协议）<br/>I6BFUM 【功能增强】【webview部件】web页面支持状态回调 （1.支持页面加载各类事件上报）<br/>I6BFV4 【功能增强】【webview部件】webview的配置管理 （1.支持滚动条和滚动位置 ）<br/>I6BFXF 【功能增强】【webview部件】webview的配置管理（ 1.支持网络加载拦截配置 2.支持判断页面中是否有image 3.支持获取源url、请求方法以及网站图标）<br/>I6BFXT 【功能增强】【webview部件】webview的配置管理（1.支持字体管理）<br/>I6BFY9 【功能增强】【webview部件】输入事件支持（1.支持交互归一）<br/>I6BG4H 【功能增强】【webview部件】输入事件支持（1.支持原始输入事件）<br/>I6BG59 【功能增强】【webview部件】web页面内容选中和复制（1.支持web上下文菜单中获取页面选中内容） | NA |
| 安全 | - Mini设备支持认证会话取消能力<br/>- HUKS支持RSA 签名增强方案<br/>主要涉及以下需求：<br/>I65VLX【功能增强】Mini设备支持认证会话取消能力<br/>I611S5【新增规格】HUKS支持RSA 签名增强方案 | NA |
| 包管理 | - 隐式查询能力增强。<br/>- 支持TS代码优化目录创建。<br/>- 验签时支持provision中bundleName校验。<br/>- 支持未配置入口图标的应用在桌面显示默认图标。<br/>- 支持打包/拆包OpenHarmony动态共享库、支持安装/更新/卸载动态共享库、HAR共享包运行期能力验证等基础能力。<br/>主要涉及以下需求：<br/>I6BD9G【基础能力】隐式查询能力增强<br/>I6BD9E【基础能力】支持TS代码优化目录创建<br/>I6BD99【基础能力】验签时支持provision中bundleName校验<br/>I6BD8Z【基础能力】支持未配置入口图标的应用在桌面显示默认图标<br/>I6BD92【新增功能】支持打包/拆包OpenHarmony动态共享库<br/>I6BD96【新增规格】支持安装/更新/卸载动态共享库<br/>I6BD9I  HAR共享包运行期能力验证 | NA |
| 编译运行时 | - 新增提供TS/JS高级语言任务池并发API-taskpool。<br/>- 新增支持HOST侧TSAOT功能，tsc支持导出/导入声明文件(.d.ts/.d.ets)<br/>主要涉及如下需求：<br/>I65G6O 【基础能力】【闭源HAR包】tsc支持导出/导入声明文件(.d.ts/.d.ets)<br/>I64QIR【taskpool】高级语言提供任务池并发API<br/>I65HID【功能增强】支持host版本TS2AOT-tool工具 | NA |
| 泛Sensor服务 | 支持light单逻辑灯控制能力。<br/>主要涉及以下需求：<br/>I63TFA 【新增规格】 支持基本light单逻辑灯控制能力 | NA |
| 媒体 | 对播放音视频和录制音视频的接口进行了重构。<br/>主要涉及以下需求：<br/>I63GTA 【重构】播放音视频接口合一<br/>I66VL5  【重构】录制音视频接口合一 | NA |
| 启动恢复 | 对NAPI模块隐藏符号，对依赖静态库模块修改为动态库依赖。<br/>主要涉及以下需求：<br/>I698CV 【符号优化】对NAPI模块隐藏符号，对依赖静态库模块修改为动态库依赖 | NA |
| 事件通知 | 本地通知数据库进行了切换。<br/>主要涉及以下需求：<br/>I67E9A 【基础能力】本地通知数据库切换 | NA |
| 图形图像 | 新增支持相机预览镜像。<br/>主要涉及以下需求：<br/>I6BDOH 【RenderService】【新增功能】支持相机预览镜像 | NA |
| 位置服务 | 新增支持网络定位框架能力。<br/>主要涉及以下需求：<br/>I5X4S9 【新增特性】【位置服务子系统】支持网络定位框架能力 | NA |
| 文件存储 | - 新增应用文件统一URI处理能力。<br/>- 新增支持公共数据的临时授权和统一的打开入口。<br/>主要涉及以下需求：<br/>I687C8【新增能力】支持应用文件统一URI处理能力<br/>I64U8W【基础能力】支持公共数据的临时授权和统一open入口 | NA |
| 元能力 | - 新增常驻进程重启优化。<br/>- 支持卡片数据库切换。<br/>- 支持异步onConnected等能力。<br/>主要涉及以下需求：<br/>I65M3F 【基础能力】执行ShellCommand命令管控<br/>I65V83  【基础能力】ServiceExtensionAbility支持异步onConnected生命周期<br/>I61H21  【基础能力】卡片本地数据库切换<br/>I63UJ5   【元能力】【ability_runtime】API8及以前API 支持异常处理<br/>I6BDCW 【基础能力】应用加载禁止加载data目录下的代码<br/>I6BDDU 【基础能力】FA模型默认启动方式为Standard<br/>I6BDE2 【基础能力】常驻应用异常频繁重启保护 | NA |

API变更清单请参考：[API差异报告](api-diff/v3.2-beta5/Readme-CN.md)

各子系统API详细变更说明请参考：[变更说明](changelogs/v3.2-beta5/Readme.md)



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

  **表4** 新增Samples

| 子系统 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| 媒体子系统 | [二维码扫描](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Beta5/media/Scan) | 本示例展示二维码扫描，从文件中选择二维码图片进行解析和读取，识别二维码信息。 | ArkTs |
| ArkUI | [一多应用市场首页](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Beta5/MultiDeviceAppDev/AppMarket) | 本示例展示了应用市场首页，其在小窗口和大窗口有不同的显示效果，体现一次开发、多端部署的能力。 | ArkTs |
| 文件管理 | [文件管理](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Beta5/FileManager/FileIo) | 本示例主要展示了文件管理相关的功能，使用[mediaLibrary](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-medialibrary.md)、[userFileManager](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-userFileManager.md)、[fileio](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-fileio.md)等接口，实现了媒体库文件、应用沙箱内文件的添加和访问等功能。 | ArkTs |
| 元能力 | [图库卡片](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Beta5/ability/GalleryForm) | 本示例是模拟图库卡片，实现对图库中的照片在卡片中显示，定时刷新卡片内容等功能。 | ArkTs |


请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。


## 修复缺陷列表

  **表5** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| I5KMQX | 【RK3568】联系人到拨号子页签切换动作的完成时延要求未达标 |
| I5UFS1 | 组件das u-boot扫描发现新增漏洞CVE-2022-2347 |
| I5UDY5 | linux kernel漏洞:CVE-2022-41218 |
| I5YPMZ | linux kernel漏洞:CVE-2022-3344 |


## 遗留缺陷列表

  **表6** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I6ATXO | 【RK3568】XTS执行测试，OpenGL测试套执行结果存在失败项 | 用例用于测试OpenGL接口，系统其他模块变更后用例未适配，但使用OpenGL接口的模块/应用不受影响，风险可控。 | 2023年2月5日 |
| I6B1IC | 【RK3568】【低概率1/10】【XTS】进程/vendor/bin/ispserver下的ispserver线程导致librkaiq.z.so出现cppcrash | 压测情况下，低概率出现ipserver线程cppcrash，出现crash后能自动重新启动ipserver线程，业务不受影响。 | 2023年2月5日 |
| I6BJ9Z<br/>I6BJ82 | alloc_file_pseudo 内存泄漏问题跟踪 | accept4引用计数不平衡导致内存泄漏，selinux_netlbl_sock_genattr、new_inode_pseudo、inet_create 内存泄漏，上游社区无补丁，跟随上游社区补丁合入。 | 2023年3月30日 |
| I641A2<br/>I64726 | 蓝牙模块存在静默配对问题，其他设备可以静默配对后通过蓝牙键盘、鼠标完全控制设备 | 蓝牙模块存在静默配对问题。在后续版本以需求跟踪解决。 | 2023年3月30日 |
| I6BRTS | 调用rdb::executeSql接口会引起内存泄漏风险 | 反复初始化调用rdb::executeSql接口出现少量内存泄露，此接口为应用初始化时调用，但不会多次调用，内存泄露影响可控。 | 2023年2月10日 |
| I6AZ4T | 带textinput输入框组件的应用存在内存泄漏风险 | 高频反复调用textinput框出现少量内存泄露，根因为调用三方库flutter库，内存未回收。需排查是否为开源flutter组件问题。 | 2023年2月10日 |
