# OpenHarmony 4.0 Beta2

## 版本概述

OpenHarmony 4.0版本标准系统能力持续完善：ArkUI进一步增强基础组件能力，应用框架支持ArkTS卡片代理刷新，应用包支持应用、支持原子化服务数据共享、支持企业应用的安装管理，分布式软总线支持会话级的传输能力协商，分布式数据管理UDMF（统一数据管理框架）支持跨设备拖拽场景下对分布式目录的文件临时授权、文件管理支持公共图片文件在设备端和云端进行同步，媒体进一步增强音频/媒体播放/音视频编解码能力，图形渲染库升级至Skia 0310新版本，窗口控件化能力继续增强，事件通知支持选定通知并批量删除通知，安全基础提供DSA数字签名算法能力，ArkCompiler方舟运行时支持JSContext功能、支持动态PGO功能，DFX提供统一的采集框架能力，方便开发者对应用的调试调测。

## 特性说明


### 应用框架

- 更新ArkTS卡片刷新方式，支持通过数据代理的方式刷新内容。

- ArkTS卡片支持静态卡片配置、静态图展示。


### ArkUI

- Xcomponent组件支持Texture模式绘制、popup支持位置自定义、弹框支持通过键盘ESC键逐层退出、ListItem支持长距离左滑删除手势、ArkTS/JS卡片支持渲染完成回调、Image/Text组件支持隐私遮罩、ContextMenu支持分段显示能力。

- 动画效果增强，包括：布局属性、背景图片大小位置属性、显隐属性支持隐式动效，list支持scrollToIndex动效、Tabs模糊动效、popup出现/消失动效，支持自定义动画，满足开发者多种多样动画诉求。

- 开发效率增强：支持命名路由的能力，借助此能力可针对不同页面设置不同的切换动效；轻量级ArkUI框架支持定义全局数据对象，可进行应用内页面间的数据共享。

- 全局API支持Stage模型多实例场景。


### 应用包管理

- 支持对应用分发类型和附件信息的设置和查询。

- 支持通过文件扩展名列出支持打开该文件的应用列表，实现了文件扩展名与应用的匹配关系。

- 支持企业应用的安装管理，对于证书类型为“enterprise”的应用，安装需要申请“ohos.permission.INSTALL_ENTERPRISE_BUNDLE”。


### 分布式数据管理

- UDMF（统一数据管理框架）支持跨设备拖拽场景下对分布式目录的文件临时授权。

- 提供RDBstore NDK接口 ：包含增/删/改/查/事务、数据加密、数据分级保护、备份/恢复能力。

- Key-Value和分布式数据对象支持根据数据量自动选择数据同步的通道。系统会根据数据量大小自动选择蓝牙通道或基于WiFi的P2P通道进行数据的同步。


### 分布式软总线

- 支持对基于软总线连接的link信息进行管理。

- 支持会话级的传输能力协商，可通过协商确定设备间传输的能力。


### 分布式硬件

- 分布式场景下的音频录制时延性能得到优化。

- 分布式文件系统支持在以蓝牙引导的P2P连接环境下进行文件互访。

- 支持组网设备名称变化的监听。


### 文件管理

- 支持公共图片文件在设备端和云端进行同步（设备登录的帐号需开通云端服务），支持通过picker选择云端的图片。

- 支持应用定制备份恢复的目录。

- 支持公共图片的分类管理，用户可以在图库中通过相册对用户图片进行组织分类。

- 支持应用监听沙箱内的文件的增改删。

- 支持应用跨设备分享沙箱内的文件。


### 图形显示及窗口

**图形**

- 支持对选定区域取色，可选定区域后获得该区域的主色值、平均色值等参数并按需使用。

- 支持设置旋转中心在Z轴锚点的偏移，允许在旋转过程中修改渲染的锚点。

- 图形处理依赖的渲染库升级至Skia 0310新版本，提升了显示性能。

**窗口**

- 优化了display模块的参数值获取方式，从原先软件方式优化为从硬件直接获取真实值。

- 窗口控件化能力增强：窗口以控件化的方式支持窗口属性、子窗口、模态窗口、窗口效果、窗口装饰、亮灭屏流程、截屏录屏。


### 媒体

**音频**

- 支持音效框架：设备厂商可配置音效策略和加载自定义音效；应用可查询音频输出的音效模式，切换或关闭音效模式。

- 支持系统内录音能力：可根据音频场景属性筛选，录制系统内播放的音频数据。

- 支持获取音频设备显示名：播放对象详细信息内可获取当前播放输出归属的设备名。

**媒体播放**

支持音效参数配置，可以在音频框架支持音效的能力基础上进一步配置音效。

**音视频编解码**

- 支持通过Native API查询系统的音视频编解码能力。

- 支持通过Native API完成音视频封装，即将音频、视频等编码后的媒体数据，按一定的格式存储到文件里。

- 支持通过Native API完成音视频解封装，即从比特流数据中取出音频、视频等媒体帧数据。


### 事件通知

- 支持选定通知并批量删除通知。

- emitter支持取消按条件指定订阅回调能力。


### 基础通信

- WiFi支持后台扫描的能力。

- WiFi支持STA模式下的随机MAC能力。


### 网络与通信

- 支持与服务器端通过TCP Socket进行通信。

- 支持用户将数据传送到远程服务器。

- 支持HTTPS证书的管理适配。

- 支持网卡代理。


### 系统服务管理

- 支持系统服务按需启动，例如外部调用、事件触发，同时支持在设备空闲时自动退出系统服务。

- 系统服务配置格式优化，使用JSON格式替代XML格式。


### 电源

- 新增接口，支持设置系统立即进入睡眠状态。

- 新增休眠源定制能力，支持根据不同的休眠源定制事件及行为。

- 新增唤醒源定制能力，支持根据不同的唤醒源定制唤醒事件。


### 多模输入

- 支持将键盘输入设备的原始事件映射为归一化交互的意图事件，使开发者在开发应用时无需关注输入行为是来自触控还是键盘。

- 支持用户根据个人习惯设置触控板功能的个性化配置：
  - 支持两种触发模式映射鼠标左键功能： 按压、轻点。
  - 支持两种触发模式映射鼠标右键功能：点按左/右下角、双指点按或轻点。
  - 跟踪速度：支持10档速度调节。
  - 支持两种交互模式映射鼠标滚轮功能：内容随手指移动方向、内容随手指反向移动。


### 主题框架

- 锁屏管理服务支持锁屏事件回调机制、静态/动态壁纸、查询锁屏时的业务状态。

- 壁纸管理服务支持自定义壁纸、锁屏/解锁操作、重置壁纸。


### 上传下载

支持查询上传和下载的任务、任务状态信息同步和任务记录持久化、任务状态查询和异常的恢复。


### 安全

**加解密算法库框架**

- 提供DSA数字签名算法能力。

- 提供DSA、ECC、RSA密钥解析和密钥参数的获取能力。

- 提供安全随机数生成算法类型的获取能力。

- 提供SM4密钥的随机生成与转换，以及加密解密能力。

- 提供SM3密钥的HMAC和HASH的能力。

- 提供SM2密钥的随机生成与转换、签名及验签、以及加密解密能力。

**密钥管理**

- 支持HUKS密钥加密保护。

- 支持KeyAttestation公钥证书中增加对密钥所属业务身份字段。

- 支持标准HDI南向接口。

**设备互信认证**

支持在以下两种场景的设备间互信认证流程中生成假名，支持识别及和标识设备的假名化名称。

- 对使用同帐号登录的多个设备进行互信认证。

- 对非同帐号的点对点互联的两个设备进行互信认证。


### 程序访问控制

- 优化权限管理的菜单呈现，拆分媒体和文件的权限组，相应权限的授权粒度更加精细化。

- 支持treble架构下对SELinux的兼容能力。


### 帐号

- 支持帐号授权能力扩展和三方应用使用帐号授权能力。

- 支持对域帐号插件的管理，从而支持域帐号管理和认证能力。


### WebView

- W3C能力补充完善：补充Web Camera能力，以及bindContextMenu、Select、date类型input等H5标签能力。

- 支持多渲染进程的进程拆分。

- 支持文字、图片基础拖拽能力。

- 支持WebRTC的视频会议能力（不含摄像头共享）。

- 支持渲染进程独立SELinux标签，增强安全基础能力。


### ArkCompiler

- 方舟运行时支持JSContext功能；支持动态PGO功能，可采集运行期的类型和函数热点信息，并生成AP文件；支持动态import加载NAPI库。

- 方舟编译器type编译模式下前端编译工具链切换到es2abc。

- NAPI buffer、object、arraybuffer、object type接口功能补齐。

- Taskpool支持任务中断和取消，支持定义任务组（TaskGroup），支持对任务的状态和调度信息进行打点，支持超长等待的任务进行识别和恢复。

- 编译构建能力提供OpenHarmony系统user和root不同权限版本的构建，user版本能力同步支持Wukong测试工具和XTS测试能力。

- 编译工具链支持预览器上的调试能力。


### DFX

- 提供统一的采集框架能力，方便开发者对应用的调试调测。

- 提供统一的trace采集能力。

- 提供Native的HiTraceMeter打点接口。

- 性能雷达提供工具类，方便各业务模块（子系统）在业务流程上传递性能埋点记录及结算性能数据。


### 内核

代码执行权限管控能力增强，新增了以下能力：

- 支持安全内存机制。

- 提供满足不同场景的代码执行权限管控策略。

- 提供代码执行权限管控的全生命周期管理能力。

- 支持解析可执行文件获取代码段信息。

- 支持代码页的完整性保护能力。


### 驱动

- 扩展设备驱动框架提供以下能力：
  - 扩展设备驱动框架基于“驱动扩展Ability（DriverExtensionAbility）”的能力，构建应用态扩展驱动包的开发、部署、安装、更新、卸载、运行能力，开放全流程生命周期管理能力。
  - 支持三方设备厂商开发的非标准协议的可插拔USB设备扩展驱动包，正常安装到OpenHarmony系统。插入USB设备后，能正常识别USB设备并与扩展驱动包匹配。
  - 支持三方应用通过扩展外部设备管理框架查询并绑定USB设备扩展驱动包，完成对扩展驱动包定制功能的操作。

- 相机驱动提供以下能力：
  - 提供USB相机热插拔识别能力，支持开机启动检查识别和启动后热插拔识别。
  - 支持USB相机的预览、拍照、录像能力，提供相机格式、分辨率查询和配置能力。

- 编解码驱动提供JPEG图片硬件解码加速能力，包括获取硬件解码信息，初始化/去初始化，解码，申请/释放buffer，提升用户浏览图片流畅度体验。

- 传感器驱动提供温湿度传感器设备驱动能力，支持小型设备温湿度器件查询，器件使能/去使能，数据查询能力，丰富智能设备传感器能力。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.0 Beta2 | NA |
| Public SDK | Ohos_sdk_public 4.0.9.6 (API Version 10 Beta2) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
| HUAWEI DevEco Studio（可选） | 4.0 Beta2 | OpenHarmony应用开发推荐使用。获取方式：<br />[Windows(64-bit)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/9b/v3/2g1w9tlbQPevu9IkTNRhNw/devecostudio-windows-4.0.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20230804T022932Z&HW-CC-Expire=315360000&HW-CC-Sign=23242113800451447FF87450B938F6B3A3B27A7360C10FBF7BCAB10B24473326)  <br />SHA256校验码：ae9b228fb1f79e99441e10bdcf347ebfc42266be8b170bbce3c9764ba32d82a4<br />[Mac(X86)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/38/v3/RTDABg5YQt69xo6_WHnI3Q/devecostudio-mac-4.0.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20230804T022845Z&HW-CC-Expire=315360000&HW-CC-Sign=4229D218C19968570755D8853840C8E2128E871EE895BCA45160743352191975)  <br />SHA256校验码：5c9afc5b1262868b58376155f1e8576d33c1ade8b01091edc4d7d397cd34026c<br />[Mac(ARM)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/5d/v3/d1TVEw9GTLaps_3giDK4NQ/devecostudio-mac-arm-4.0.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20230804T023035Z&HW-CC-Expire=315360000&HW-CC-Sign=B088BE6D5E2A28E21512F8396D09DDD4C6C41E75E03DFF32830ECC8E7B467D42)  <br />SHA256校验码：ea6c98cafd5036e4a6fd46b0b1cde3a306953b1eef423d5940f1af7c632205d6 |
| HUAWEI DevEco Device Tool（可选） | 4.0 Beta1 | OpenHarmony智能设备集成开发环境推荐使用。获取方式：<br />[点击跳转至下载页面](https://device.harmonyos.com/cn/develop/ide#download) |


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.0 Beta2    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/code-v4.0-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/code-v4.0-Beta2.tar.gz.sha256) | 27.7 GB |
| Hi3861解决方案（二进制）        | 4.0 Beta2    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_pegasus.tar.gz.sha256) | 27.5 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.0 Beta2    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_taurus_LiteOS.tar.gz.sha256) | 300.9 MB |
| Hi3516解决方案-Linux（二进制）  | 4.0 Beta2    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/hispark_taurus_Linux.tar.gz.sha256) | 192.4 MB |
| RK3568标准系统解决方案（二进制）        | 4.0 Beta2    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/dayu200_standard_arm32.tar.gz.sha256) | 	5.2 GB |
| 标准系统Public SDK包（Mac）             | 4.0.9.6      | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/ohos-sdk-mac-public.tar.gz.sha256) | 832.3 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.0.9.6     | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 788.4 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.0.9.6      | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta2/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.0 GB |


## 更新说明

本版本在OpenHarmony 4.0 Beta1的基础上有如下变更:

### API 

OpenHarmony 4.0 Beta2的API范围相比4.0 Beta1，API变更的清单请参见“[API差异报告](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Beta2/zh-cn/release-notes/api-diff/v4.0-beta2/Readme-CN.md)”。极少量接口的变更可能影响到已开发的应用（使用API 9或更早版本API开发的应用），变更影响的说明和接口的适配指导请参见“[changelogs](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Beta2/zh-cn/release-notes/changelogs/v4.0-beta2/Readme-CN.md)”。


### 特性变更

详见[版本概述](#版本概述)。

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

**表3** 新增Samples

| 子系统 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| 网络与连接 | [上传和下载](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/BasicFeature/Connectivity/UploadAndDownLoad) | 本示例使用\@ohos.request接口创建上传和下载任务，实现上传、下载功能，hfs作为服务器，实现了文件的上传和下载和任务的查询功能。 | ArkTS |
| 文件管理 | [应用接入数据备份恢复](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/BasicFeature/FileManagement/FileBackupExtension)<br/>（Full SDK） | 应用接入数据备份恢复需要通过配置BackupExtensionAbility实现。<br/>BackupExtensionAbility，是Stage模型中扩展组件ExtensionAbility的派生类。开发者可以通过修改配置文件定制备份恢复框架的行为，包括是否允许备份恢复，备份哪些文件等。<br/>本sample主要给备份流程提供应用，用于生成数据和显示数据。 | ArkTS |
| 事件通知 | [自定义通知角标](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/BasicFeature/Notification/CustomNotificationBadge) | 本示例主要展示了设定应用的桌面图标角标的功能，使用\@ohos.notificationManager 接口，进行桌面角标的设置，通知的发送，获取等。 | ArkTS |
| 事件通知 | [自定义通知推送](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/BasicFeature/Notification/CustomNotificationPush)<br/>（Full SDK） | 本示例主要展示了通知过滤回调管理的功能，使用\@ohos.notificationManager 接口，进行通知监听回调，决定应用通知是否发送。 | ArkTS |
| NDK | [Native Xcomponent](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkXComponent)<br/>（Native SDK） | 本示例中主要介绍开发者如何使用Native XComponent接口来获取NativeWindow实例、获取布局/事件信息、注册事件回调并通过OpenGL/EGL实现在页面上绘制形状。功能主要包括点击按钮绘制一个五角星，并可以通过点击XComponent区域改变五角星的颜色。 | Native C++ |
| 应用模型 | [数据代理卡片-数据库刷新](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/PersistentProxyForm)<br/>（Full SDK） | 本示例主要展示了数据代理卡片的功能，使用\@ohos.application.DataShareExtensionAbility、\@ohos.data.dataShare、\@ohos.data.dataSharePredicates等接口，实现了修改卡片订阅信息后，当rdb数据库中的数据发生变化时，卡片中对应信息也发生相应变化的功能。 | ArkTS |
| 应用模型 | [数据代理卡片-仿push应用刷新](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/ProcessProxyForm)<br/>（Full SDK） | 本示例主要展示了使用push应用形式的数据代理卡片功能，使用\@ohos.data.dataShare等接口，实现了数据代理卡片的修改订阅条件功能及卡片的发布数据功能。 | ArkTS |
| 应用模型 | [编辑应用](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/Receiver) | 本示例主要实现了基于UIExtension实现简单的分享功能。支持取消分享，点击“返回Share”按钮，返回调用方应用；支持完成分享，点击“留在编辑应用”按钮，留在当前接收分享结果应用。 | ArkTS |
| 应用模型 | [发起分享应用](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/Share)<br/>（Full SDK） | 本示例主要实现了点击“分享”按钮发起分享，显示出分享文本应用图标和分享编辑应用图标，点击相对应应用图标可以发起分享并跳转到其对应应用显示。 | ArkTS |
| 应用模型 | [文本应用](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta2/code/SystemFeature/ApplicationModels/Template)<br/>（Full SDK） | 本示例主要实现了基于UIExtension实现简单的分享功能。支持取消分享，点击“返回Share”按钮，返回调用方应用；支持完成分享，点击“留在文本应用”按钮，留在当前文本应用。 | ArkTS |

请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。


## 修复缺陷列表

**表4** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| I6U4ZT | 拍照后立刻断电源，图库的第一张图片点击打不开。 |
| I79752 | 中概率由进程com.ohos.smartperf下的.ohos.smartperf线程导致libark_jsruntime.so出现cppcrash。 |
| I79P3K | 低概率由进程com.ohos.callui导致jscrash，栈名：onDestroy。 |
| I79TCB | 低概率由进程com.ohos.note下的VizCompositorTh线程导致libweb_engine.soTh出现cppcrash。 |
| I78CBC | 反复进入某相册的图片宫格浏览界面，导致libace.z.so出现内存泄露。 |
| I78CH7 | 反复在dock栏添加/移除应用，导致libace.z.so出现内存泄露。 |


## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I78C9W | 反复进入大图浏览界面后返回，导致libace.z.so出现内存泄露。 | 非常用场景，应用重启后泄露问题消失，影响可控。 | 2023年8月30日 |
| I7BF3M | 长时间运行测试，launcher进程概率性出现appfreeze，原因是STRINGID:APPLICATION_BLOCK_INPUT卡在libeventhandler.z.so。 | 该问题不会引起系统重启，整体影响可控。 | 2023年8月30日 |
| I7M51R | 低概率出现进程com.ohos.systemui下的线程render_service出现cppcrash。 | 低概率问题，且render_service进程出现cppcrash后，系统会自动重新启动render_service进程，对业务影响可控。 | 2023年8月30日 |
| I7NWF3	| 因兼容性问题，使用3.2.x版本的设备和4.0.x版本的设备通过Wi-Fi引导P2P连接时开启会话失败。	| 在使用4.0.x版本的设备间此问题不存在，影响可控。	| 2023年8月30日  |
| I7BOAO	| 三方仓GLES3多个测试用例执行失败。	| 三方仓问题，厂商正在适配修改。	| 2023年8月30日  |