# OpenHarmony 4.1 Beta1


## 版本概述

OpenHarmony 4.1 Beta1版本标准系统能力持续完善，ArkUI进一步完善组件能力和效果、图形窗口增强了动效和窗口适配能力、应用框架增强了Extension能力、分布式软总线连接能力和规格进一步增强、媒体进一步增强音频/相机框架的能力、测试框架多个工具能力增强。

OpenHarmony 4.1 Beta1版本开始提供首批API Level 11接口。


### 应用框架

- 提供Autofill自动填充框架，系统应用可以通过该框架来实现密码保险箱等功能为用户提供免密登录功能。

- 支持通过Context获取resFile资源目录，提升应用开发便利性。

- 增强UIExtension能力：提供SetReceiveDataForResultCallback接口及其同步回调；提供StartAsCaller接口；支持多实例。

- 启动UIAbility和UIExtension时，支持Uri批量授权。

- 支持应用定制系统环境参数，应用可选择是否跟随系统配置更新变化显示效果。

- 支持意图框架能力，支持UIAbility、UIExtension、ServiceExtension等绑定意图。

- 支持在import时引入abc 文件。

- 增强卡片能力：支持卡片点击回调；支持卡片点击跳转deeplink；支持查询未使用的卡片；新增锁屏卡片尺寸的规格；支持锁屏卡片设置为单色模式；支持状态保存及恢复能力，提供更好的显示接续效果。


### ArkUI

新增NodeContainer开放命令式的渲染节点，提升自定义绘制能力。

文本和容器类组件能力增强：

- 支持TextInput/Text按字符截断;

- 支持TextArea定制回车键行为；

- 支持TextInput和Textarea获取光标位置；

- 支持智能分词，新增依据分词结果插入光标逻辑，以及替换分词算法；

- 支持ImageSpan自定义长按菜单事件、支持控件缩进/对齐;

- 支持Swiper组件的嵌套滚动；

- 支持List组件在通过ScrollToIndex滚动到ListItemGroup中时指定ListItem的能力；

- 支持Grid/WaterFlow组件列表项滑动到指定位置并有过渡动画；

- 支持滚动类组件在内容区域不满一屏时使能回弹效果。

控件AI化能力增强：

- 支持TextInput及相关文本输入控件的视觉输入；

- 支持Text/RichEditor相关文本控件的文本实体识别。

状态管理功能增强：

- 支持undefined和null，以及联合类型；

- 支持ListItem组件在ForEach/LazyForEach中属性中更新方法；

- 支持\@LocalStorageLink/LocalStorageProp在非激活状态不更新。


### 应用包管理

- 提供了基础资源统一访问的能力，支持查询应用的图标和名称。

- 支持在调试状态使用快速修复能力，支撑大型应用快速调试。

- 支持驱动应用的安装、更新、卸载。

- 支持菜单的配置及查询能力。

- 支持签名的流转，使用签名证书中的app-identifier作为应用的唯一标识。

- 支持abc文件的合法性校验，校验通过的abc文件，才允许在受限虚拟机中运行。

- 接入统一文件预览框架，支持使用统一文件预览框架打开文件。

- 提供了包扫描检测工具，支持扫描大文件、重复文件和各种文件类型大小占比情况等功能。

- 支持使用打包工具指定统一的版本号进行打包。


### 分布式软总线

- 连接能力和规格进一步增强，如：支持P2Pv2协商；支持按业务策略的被动发布；链路选择增加连接可靠性确认能力；支持感知资源情况并动态设置连接参数。

- 支持IPC引用技术查询的接口和时间戳查询的接口，增强维测能力。


### 分布式数据管理

- 支持RDB在应用指定的沙箱路径子目录下创建数据库，在保证应用数据安全的前提下进一步提升数据使用的灵活性。

- 支持UDMF的数据类型标准化定义与描述、支持标准数据类型查询、支持数据访问授权与管理、支持应用自定义数据类型。

- 限制数据不打分类分级标签时不允许跨设备同步。

- 支持preferences的uint8Array格式数据流的修改、查询和持久化。


### 分布式硬件

- 优化分布式输入特殊场景下的按键状态管理。

- 增强分布式相机、分布式音频、分布式屏幕和分布式输入的业务可靠性。


### 文件管理

- 图库等系统应用支持按照年月日视图进行分组查询。

- 图库等系统应用支持文件编辑可还原能力、文件隐藏及隐私相册能力。

- 提升图库滑动场景下缩略图的访问性能，缩略图访问性能整体提升20%以上。

- 应用访问框架及API能力增强，支持readline、lseek等接口。


### 图形图像及窗口

**图形图像**

- 支持HDR Vivid视频的渲染与显示。

- 图形NDK能力增强，支持为NativeImage添加OnFrameAvailableListener回调，支持为NativeWindow设置色域，新增支持OpenGL扩展接口等。

- 支持录屏不录制特定窗口，以及隐私窗口录制成纯黑色帧画面的能力。

- 支持调整系统分辨率。

- 支持系统根据动画调节帧率，支持开发者调节应用帧率。

- 动效能力增强，支持硬件挖空，屏幕圆角，Navigation导航转场动画支持共享元素等。

- 图形渲染管线支持vulkan后端。

- nativeBuffer支持设置metadata，适配HDR视频场景动态元数据随帧传递。

**窗口**

- 窗口属性支持调整全局窗口分辨率，支持窗口遮挡状态的通知，支持窗口模式变化的监听，支持窗口可交互和不和交互的通知，支持水印窗口能力。

- 窗口布局和层级，支持设置窗口的初始化尺寸和位置，支持缩放拉、拉伸和拖拽移动子窗口，支持设置窗口最小化和窗口隐藏，支持查询窗口支持的最小和最大尺寸，支持窗口间拖拽被拖入窗口置顶，支持设置窗口防悬浮窗遮挡，支持提供窗口的可绘制区域大小。

- 窗口焦点支持同应用下的窗口指定目标窗口转移焦点。

- 窗口事件支持多屏下的事件的分发，支持多模态弹窗，支持窗口外点击事件的监听以及对此类监听排除输入法区域。

- 窗口动效支持窗口形态切换的动画能力，支持软键盘多任务联动动画，支持配置输入法软键盘进入退出动画。

- 智慧多窗支持画中画能力，支持分屏窗口位置交换。

- 屏幕基础功能管理支持指定屏幕上下电，支持提供屏幕可用区域。

- 虚拟屏支持虚拟屏色域、HDR和format的设置，支持虚拟屏窗口过滤设置，支持虚拟屏更新尺寸规格，支持设置禁用截屏，支持禁用虚拟屏镜像能力。

- 多屏管理框架支持设置窗口显示屏，支持窗口在屏幕间迁移，支持异源显示模式。


### 媒体

新增一批面向设备开发的HDI接口能力，包括相机框架、音频等，如：

支持相机框架及应用完成从当前变焦值平滑过渡到目标变焦值的能力。

支持手电筒打开关闭控制、手电筒可用通知、手电筒状态变化通知。

支持运动防抖模式，达成在录像过程中图像稳定。

支持相机扫码模式，支撑扫码服务业务功能。

支持底层识别系统状态（如跌落状态），使相机的相对脆弱器件（如光圈）可在手机跌落状态时关闭，对其进行保护。

支持蜂窝网络通话时进行录音。

支持音振协同。新增振动HDI接口，可查询设备振动信息；新增震动类型和时延字段的设置接口；支持高清振动的数据下发。


### 事件通知

- Emitter支持按string类型订阅；支持获取订阅者数量；支持可序列化类型，数据大小限制放开到16MB。

- 支持应用设置仅订阅本应用发送的自定义事件。

- 支持系统应用创建系统实况窗类型通知。

- 支持设置为每周重复提醒。

- 支持同一个日程下的同组提醒按groupId统一取消。

- 支持通知按钮自动多语言切换。通过设置按钮资源ID，可实现通知到达后，提醒内的按钮标题语言依据系统环境语言自动切换。


### 通信与连接

- NFC支持HCE卡模拟能力，支持设置默认支付应用。

- 蓝牙支持BLE广播的动态启停，支持MDM调用蓝牙接口强制关闭蓝牙功能，并限制开启蓝牙；支持查询设备是否处于可发现状态；支持根据设备地址获取设备的配对状态。

- Wi-Fi支持识别当前连接的热点是否手机热点；支持将设备作为热点，并支持添加STA设备到黑名单。


### 位置

- 支持通过sendCommand接口删除辅助数据，用于支持冷热启动测试。

- 支持地理编码，逆地理编码，查询地理编码服务状态等接口。

- 支持MDM调用位置服务接口强制开启或关闭位置服务功能。


### 电话服务

- 支持SIM卡短信增删改查功能。

- 支持异网漫游准入要求：支持异网漫游拜访网络和归属网络名称同时显示；支持异网漫游场景紧急呼叫的特殊处理。

- 支持接收运营商上报的小区广播消息。

- 支持通话拦截：提供通话拦截框架，支持三方接入；提供号码黑名单机制。

- 支持多时区来源的管理：多时区国家可以通过NITZ、地理位置更新时区，并且根据不同的优先级更新；单时区国家可以通过NITZ、国家码、地理位置更新时区，并且根据不同的优先级更新。

- 其他移动通信相关能力和规格提升：
  - 支持广电（运营商）SIM卡；
  - 支持TDM/DSDA双卡双通。双卡场景下，一张卡通话过程中，第二张卡来电正常响铃，第一路通话自动hold；可以在一张卡通话时，使用另一张卡拨打电话。
  - 支持DSDS一卡通话一卡可来电。双卡场景下，一张卡通话过程中，第二张卡来电正常响铃，第一路通话挂断。
  - 支持虚拟卡APN匹配，虚拟卡支持根据SPN/IMSI前缀/GID/ICCID匹配APN。
  - 开机搜索网络和关闭飞行模式后搜索网络性能提升。


### 网络管理

- 支持局域网路由管理，可配置网卡IP地址、路由、静态ARP表等属性。

- 在支持UDP Socket完整能力的基础上，新增支持加入/退出组、TTL设置与获取、数据发送等能力。

- 支持基于socket的流量统计，应用通过网络管理接口，可获取基于socket粒度的流量统计结果。

- 支持读取应用级网络代理配置文件。

- 优化网络连通性检测机制，包括探测周期、探测协议，同时重构了探测状态机。


### 电源

**电源管理**

- 支持将按动电源键或合盖操作配置为睡眠或熄屏。

- 支持设备在睡眠状态被唤醒后，根据读取特定系统节点获取唤醒原因，并根据唤醒原因执行对应动作，如关机。

- 支持多端协同状态下按动电源键等亮灭屏的行为处理，以及硬件输入和软件注入的区分和处理。

- 支持多端协同成功/断开的屏幕电源状态控制及其相关状态机处理。

- 支持灭屏但不停止图像输出的显示状态及其相关状态机处理。

- 支持在用户已配置AOD且设备锁屏时，LCD不下电。

- 支持在低电压场景触发正常关机。

- 支持长按电源键触发关机弹框的振动效果，并支持在特定设备上关闭振动效果。

- 支持开始充电时的振动提示效果，并支持在特定设备上关闭振动效果。

**热管理**

- 支持定制新场景/状态用于温控决策。

- 新增热逃生档位，触发热逃生温度会发出通知。

- 支持向驱动节点配置温控的定制动作，当触发温控时，动作的值会写入相应节点。

**其他**

- 支持驱动上报事件并触发对应动作的执行。

- 支持查询和上报应用持有CPU锁信息。可通过电源服务的接口回调或hisysevent上报应用持有CPU锁的情况，同时可调用接口查询应用持有CPU锁的情况。支持Nap服务订阅上述信息。


### 安全

- 密钥管理支持“设置密码时有效”的访问控制方式。

- 加解密算法库框架支持PBKDF2算法、支持对称密钥可选AAD参数、支持可变长度密钥HMAC、支持DH/25519算法、支持brainpool曲线、支持SM2密钥解析和参数处理能力、支持基于曲线名的密钥生成能力。

- 新增应用私有证书凭据管理接口支持指定签名填充方式和Hash算法。


### 用户IAM

- 支持清理冗余用户身份凭据。

- 支持认证失败振动反馈。

- 支持动态指纹禁用功能。


### ArkCompiler

- SmartGC支持90帧场景，支持对性能高度敏感的场景的GC控制。

- Taskpool支持中断退出线程，支持精准import导入，支持默认transfer机制。

- 提供C++的异常捕获机制。


### 内核

支持内核树外独立构建ko模块能力，并提供独立ko分区chip_ckm。


### 多模输入

- 新增接口支持自定义光标交互坐标和更新鼠标显示位置的注入功能。

- 支持按键监听按优先级处理的能力。

- 支持鼠标指针热区检测功能。

- 支持双指捏合、旋转手势的识别。

- 支持三指轻点手势识别。

- 支持全局组合键的管理和监听功能。

- 支持双击按压电源键拉起指定Ability的能力。

- 支持鼠标光标UX属性的设置，当前支持设置大小和颜色。

- 支持鼠标动画光标样式的设置。


### 泛Sensor

- 支持传感器精度的上报。

- 支持传感器和触觉控制的Native API接口。

- 支持上报设备折叠状态、空间音频头部姿态数据等。

- 支持振感的动态静态调节。

- 支持触觉控制的开关。


### 测试框架

**自动化测试框架arkxtest**

- 支持模拟鼠标滚轮滑动、滑动左右键双击等模拟UI操作能力。

- 支持Shell命令方式进行UI模拟操作能力，支持点击、滑动、双击、文本输入等常用操作能力。

- 提升UI测试框架查找控件信息效率。

**测试调度框架xDevice**

- 新增单次测试过程中自动复测失败项能力，并支持配置复测次数，最终生成一份测试报告。

- 优化测试报告，统一轻量系统、小型系统、标准系统的测试报告头信息。

- 新增支持测试套测试资源本地不存在时，可配置远程下载地址。

**稳定性测试工具WuKong**

- 新增page页面和Ability页面的配置能力，支持在测试过程中配置页面屏蔽，提升测试效率。

- 新增单一场景压测能力，支持针对某一控件循环注入操作事件，并支持配置循环次数。

**性能开发工具SmartPerf Host**

- 新增支持hilog、hisysevent的采集、分析和展示。

- 新增支持hiperf event count的分析和展示。

- 提升抓取trace的能力，动态可暂停可调试。

- 新增支持线程唤醒关系树的快速跟踪。

**性能测试工具 SmartPerf Device**

- 优化已有抓取内存、CPU数据的能力。

- 新增启动停止采集的命令。

- 新增定时获取截图、分辨率和刷新率的采集能力。


### DFX

- 提升功耗异常的识别速度与准确度，主要器件的耗电相关信息更丰富，易于问题定位.对应用导致的器件耗电异常场景，可对器件的耗电使用进行深度分析。

- 支持系统内存详情采集插件，用于ION，GPU/Skia，purgeable内存信息的采集（hidumper hiprofiler）。

- 支持动效场景耗时分析，可采集动效（启动、退出、转屏、转场、滑动）设置的信息数据、动效起止打点、以及和图形帧关联。


### 上传下载

- 支持上传场景返回超过IPC限制的Response Body。

- 支持文件片段上传。

- 支持后台任务进度更新及状态变化的回调。

- 支持上传下载任务状态变化事件的上报。

- 应用或后台Service Ability重启后可以继续操作上传下载任务。

- 支持优先级策略：高优先级应用（焦点应用）的高优先级任务优先执行并且占据跟多网络带宽资源。


### 输入法框架

- 支持输入法切换列表控件。

- 支持输入法应用代理功能​。

- 支持输入法框的视觉输入。

- 提供查询输入法窗口显示状态的接口。

- 支持系统安全键盘。

- 支持安全模式。


### 时间时区

- 支持感知用户配置开关。

- 支持自定义NTP服务器。


### AI

- 新增Native的设备端侧的AI训练接口。

- 新增配置NNRt后端的ArkTS接口。


### Web

- 完善WebRTC能力，支持入会、共享、发言、摄像头等能力

- 支持W3C获取时区、感知VirtualKeyboard。

- 完善CSS光标样式。

- 支持网页过滚动效果。

- 支持在文档启动时执行注入脚本。

- 支持PostURL能力。

- 支持嵌套滚动。

- 支持网页视频播放使用AVCodec硬解。

- 新增WebCookieManager不依赖Web组件独立使用的能力。

- 支持Web对接无障碍能力。

- Web内核升级：从Chromium 99升级至Chromium 114。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 4.1 Beta1 | NA | 
| Public SDK | Ohos_sdk_public 4.1.5.3 (API Version 11 Beta1) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 | 
| HUAWEI DevEco Studio（可选） | 4.1 Beta1 | OpenHarmony应用开发推荐使用。<br />*获取方式待补充。* | 
| HUAWEI DevEco Device Tool（可选） | 4.0 Release | OpenHarmony智能设备集成开发环境推荐使用。<br />[请点击这里获取](https://device.harmonyos.com/cn/develop/ide#download)。 | 


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.1-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.1-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.1 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/code-v4.1-Beta1.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/code-v4.1-Beta1.tar.gz.sha256) | 31.0 GB |
| Hi3861解决方案（二进制）        | 4.1 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_pegasus.tar.gz.sha256) | 28.7 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.1 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_taurus_LiteOS.tar.gz.sha256) | 316 MB |
| Hi3516解决方案-Linux（二进制）  | 4.1 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/hispark_taurus_Linux.tar.gz.sha256) | 213 MB |
| RK3568标准系统解决方案（二进制）        | 4.1 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/dayu200_standard_arm32.tar.gz.sha256) | 	7.9 GB |
| 标准系统Public SDK包（Mac）             | 4.1.5.3      | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/ohos-sdk-mac-public.tar.gz.sha256) | 926 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.1.5.3     | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 883 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.1.5.3      | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Beta1/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |

## 更新说明

本版本在OpenHarmony 4.0 Release的基础上有如下变更。

### API变更

OpenHarmony 4.1 Beta1相比4.0 Release的API差异请[点击这里查看](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Beta1/zh-cn/release-notes/api-diff/v4.1-beta1/Readme-CN.md)。

此外，从4.0 Release至今，有少量接口变更可能影响此前应用工程的兼容性或需要您关注，详细的变更说明请[点击这里查看](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Beta1/zh-cn/release-notes/changelogs/v4.1-beta1/Readme-CN.md)。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

**表3** 新增Samples

| 特性 | 名称 | 简介 | 开发语言 | 
| -------- | -------- | -------- | -------- |
| 基础能力 | [基础能力增强](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/Ability/AbilityFeatureSystem)（fullSDK,API等级为system_basic） | 本示例使用 [ohos.app.ability.appManager](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-app-ability-appManager.md), [UIAbilityContext](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-inner-application-uiAbilityContext.md) , [UIExtensionContentSession](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-app-ability-uiExtensionContentSession.md) 等接口实现了以下功能：提供查询单个应用是否正在运行接口;新增系统接口请求创建模系统或模应用的UIExtension;UIExtension支持同步返回数据的能力；提供隐式启动UIExtension接口;UIExtension提供StartAsCaller接口; | ArkTS | 
| 系统功能 | [AutoFill自动填充能力](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/AutoFill/AutoFill)（fullSDK,API等级为system_basic） | 本示例使用[application/AutoFillRequest](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/AutoFillRequest.d.ts)，[@ohos.app.ability.AutoFillExtensionAbility](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.AutoFillExtensionAbility.d.ts)，[application/ViewData](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/ViewData.d.ts)，[@ohos.app.ability.autoFillManager ](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.autoFillManager.d.ts)等接口，展示了如何使用AutoFill自动填充框架。 | ArkTS | 
| 卡片 | [ArkTS卡片能力增强](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/ArkTSCard/ArkTSCard)（fullSDK,API等级为system_basic） | 本示例使用动态和静态(form_config.json中isDynamic字段false为静态，true为动态)两种状态的锁屏卡片/deeplink卡片。 | ArkTS | 
| 系统功能 | [意图执行](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/InsightIntent/IntentExecute)<br/>（fullSDK,API等级为system_basic） | 本示例使用[@ohos.app.ability.InsightIntentExecutor](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-app-ability-insightIntentExecutor.md)、[@ohos.app.ability.insightIntent](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-app-ability-insightIntent.md)、[@ohos.app.ability.insightIntentDriver](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-app-ability-insightIntentDriver.md)等接口，展示了意图绑定到UIAbility前台执行、意图绑定到ServiceExtension执行两种意图执行方法，主要包括构造意图配置文件、构造意图调用执行参数、触发意图调用的执行、取得意图调用结果等。 | ArkTS | 
| 基础特性 | [Native Window](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/BasicFeature/Native/NdkNativeWindow) | 本示例中主要介绍开发者在利用[Native XComponent](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/native-apis/native__interface__xcomponent_8h.md)来获取[NativeWindow](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/native-apis/_native_window.md)实例，通过数据填充改变矩形框颜色。并提供从[NativeImage](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/native-apis/_o_h___native_image.md)中获取NativeWindow进行buffer轮转的案例，通过NativeWindow生产buffer来触发NativeImage的可用帧回调。 | ArkTS | 
| 基础特性 | [标准化数据定义与描述](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/BasicFeature/DataManagement/UDMF/UniformTypeDescriptor/UTDType)（fullSDK） | 本示例主要展示了标准化数据定义与描述的功能 ，使用[@ohos.data.uniformTypeDescriptor](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-data-uniformTypeDescriptor.md) 、[@ohos.file.fs](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-file-fs.md) 、[@ohos.router](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-router.md)等接口，实现了增添预制媒体文件、媒体文件的utd标准类型获取、utd类型归属类型查询、获取文件对应的utd类型的默认图标、支持自定义数据类型等功能。 | ArkTS | 
| 媒体 | [音频管理](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/SystemFeature/Media/Audio)（fullSDK,API等级为system_basic） | 此Sample展示 [空间音频API](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.multimedia.audio.d.ts) 的用法，相关API包括:<br/>isSpatializationSupported(): 查询系统是否支持空间音频，<br/>isHeadTrackingSupported()：查询系统是否支持头动跟踪，<br/>isSpatializationSupportedForDevice(deviceDescriptor: AudioDeviceDescriptor)：查询设备是否支持空间音频，<br/>isHeadTrackingSupportedForDevice(deviceDescriptor: AudioDeviceDescriptor)：查询设备是否支持头动跟踪，<br/>isSpatializationEnabled()：查询空间音频是否开启，<br/>isHeadTrackingEnabled(): 查询头动跟踪是否开启，<br/>setSpatializationEnabled(enable: boolean)：设置空间音频开启状态，<br/>setHeadTrackingEnabled(enable: boolean)：设置头动跟踪开启状态， | ArkTS | 
| 基础能力 | [基础能力增强](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.1-Beta1/code/BasicFeature/Ability/AbilityFeature) | 本示例使用 [ApplicationContext](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-inner-application-applicationContext.md) ,[ohos.ability.wantConstant](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-ability-wantConstant.md) ,[ohos.app.ability.StartOptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-app-ability-startOptions.md)等接口实现了以下功能：支持应用定制系统环境参数;支持隐式启动个数为0时不触发提示弹框--增加了一个flag;支持应用清理自己的数据;Ability启动参数支持传递初始位置/初始大小/是否携带动效; | ArkTS | 

请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。


## 修复缺陷列表

**表4** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| -------- | -------- |
| I80TOB | 进程com.ohos.settings（所属应用：设置）有一定概率出现由于THREAD_BLOCK_6S卡在libbtframework.z.so而发生appfreeze。 | 
| I89F06 | 进程com.ohos.note（所属应用：备忘录）下的com.ohos.note线程低概率出现cppcrash，导致该现象的崩溃栈为libweb_engine.so。 | 
| I7SCU4 | 进程com.ohos.photos（所属应用：相册）有一定概率由于THREAD_BLOCK_6S卡在libark_jsruntime.so而发生appfreeze。 | 
| I86CNJ等38个开源组件漏洞 | lj-linux-131204684-0577967 等38个开源组件漏洞。 | 
| I86YLD | 低概率出现进程com.ohos.contacts（所属应用：联系人）下的m.ohos.contacts线程导致libipc_core.z.so出现cppcrash。 | 
| I88UKM | 进程ohos.samples.distributedmusicplayer（所属应用：音乐播放器）下的ffrtwk/CPU-2-3线程低概率出现cppcrash，导致该现象的崩溃栈为libuv.so。 | 
| I89CLG | 进程com.ohos.camera（所属应用：相机）下的com.ohos.camera线程小概率会导致libcamera_napi.z.so出现cppcrash。 | 
| I86M99<br/>I88UV6<br/>I88UVQ | 长时间稳定性压力测试出现foundation内存泄漏，24小时泄露40MB。 | 
| I7TZ3V等31个内核问题 | 内核btrfs_free_tree_block函数kernel_bug等31个内核问题。 | 
| I82NVZ | GPU驱动渲染出的图像与标准不符问题。 | 


## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| I8PEOF | 进程com.ohos.mms有一定概率出现因为LIFECYCLE_TIMEOUT导致的sysfreeze问题。 | 概率问题，会导致页面白屏，重启设备可恢复正常，影响可控。 | 1月15日 | 
| I8QET3 | 进程bluetooth_servi下的OS_IPC_10_25363线程有一定概率出现因libbluetooth_server.z.so导致的cppcrash。 | 概率问题，会导致蓝牙服务出现异常，异常后服务可自动恢复，用户无异常感知。 | 2月28日 | 
| I8QH9S | 进程com.ohos.settingsdata下的os.settingsdata线程小概率出现因libnative_appdatafwk.z.so导致的cppcrash。 | 小概率问题，会导致后台数据管理进程停止，但有新的访问请求时进程会自动重启，用户无感知。 | 1月15日 | 
| I8QNI7 | 进程foundation由于SERVICE_BLOCK小概率出现因netsysnative导致的sysfreeze。 | 小概率问题，影响后台进程foundation，用户无感知。 | 2月28日 | 
| I8QSZ1 | 进程com.ohos.systemui有一定概率出现由于THREAD_BLOCK_6S卡在libsamgr_proxy.z.so导致的appfreeze。 | 概率问题，问题出现后会有极小的概率下拉systemui无响应。可通过在设置界面开关蓝牙，或重启手机恢复。影响可控。 | 2月28日 | 
| I7TYTF等43个开源组件漏洞 | 内核errseq_set函数protection_fault 等43个开源组件漏洞 | 分析解决中，跟随社区漏洞管理流程SLA修复 | 按漏洞SLA | 
| I78THF | RK3568 kernel patch中的maligpu版本过旧（11.29），存在大量未修复CVE漏洞。 | RK3568主板的GPU Mali驱动存在多个未修复CV漏洞E，比如CVE-2021-28663，CVE-2021-39793，利用这些漏洞可以得到内核UAF，进而提权。 | 2月10日 | 
| I83D6I | 进入设置反复打开关闭蓝牙，有一定概率会导致设置出现appfreeze。 | 概率问题，出现设置无响应后可通过重启设备恢复正常，影响可控。 | 2月28日 | 
| I827LU | 进入设置反复打开关闭蓝牙开关会出现内存泄漏，经测试一个小时泄露15MB。 | 开关一次蓝牙系统内存泄露8.3KB，重启设备后可恢复，影响可控。 | 2月28日 | 
| I82V2W | 进入设置反复打开关闭蓝牙开关出现内存泄漏，经测试“设置”一个小时内存涨幅到180M。 | 对于需要使用OpenHarmony进行商业开发的伙伴，建议使用芯片或硬件自带蓝牙模块的协议栈以规避此问题。<br/>开关一次蓝牙应用内存泄露0.2MB，重新打开“设置”卡恢复，影响可控。<br/>对于需要使用OpenHarmony进行商业开发的伙伴，建议使用芯片或硬件自带蓝牙模块的协议栈以规避此问题。 | 2月28日 | 
