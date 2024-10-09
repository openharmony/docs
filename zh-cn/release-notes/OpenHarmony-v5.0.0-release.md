# OpenHarmony 5.0.0 Release


## 版本概述

OpenHarmony 5.0.0 Release版本标准系统能力持续完善。相比OpenHarmony 5.0 Beta1，Release版本做出了如下特性新增或增强：

应用框架新增更多生命周期管理能力、提供子进程相关能力，可以对应用运行时的任务执行进行更精细的调度和管理；ArkUI进一步开放自定义节点的渲染能力；应用包管理提升了应用打包效率，丰富了终端用户使用应用时的可操作场景（如创建应用分身、创建桌面快捷方式等）；分布式数据管理能力进一步增强，在保证数据合理共享的前提下增强安全性，其他模块能力适配Sendable机制也得到了增强；文件管理进一步完善Picker的能力，对文件资源做到合理管控权限和合理使用；媒体在音视频播放、录制方面能力进一步增强，新增支持多个音视频、图片的编码格式，支持更细节的播控操作；相机提供更强大的能力，丰富终端用户拍照场景。

多个子系统进一步对标ArkTS能力补齐NDK的C API能力，如ArkUI适配三方框架的能力、数据管理UDMF、图形绘制、播放框架、相机、图形编解码、网络管理、国际化、时间时区、输入法框架、剪贴板等；

更详细的特性新增与增强的说明如下：


### 应用框架

- 支持创建JS / Native子进程，开发者可以把耗时操作放到子进程中执行。

- Ability生命周期监听支持onNewWant等更多生命周期。

- 支持Ability在不主动销毁自己的情况下，将AbilityResult结果返回给调用方。

- Context支持Sendable对象转换，用于多线程传递Context。

- 支持应用级别的字体设置。


### ArkUI

- 进一步增强了组件自定义能力，新增组件modifier、ContentModifier和DrawModifier，支持基于已有组件新增属性、自定义组件内容和完全自绘制。

- 开放了自定义节点和Native的渲染节点。[自定义节点](https://gitee.com/OpenHarmony/docs/blob/master/zh-cn/application-dev/ui/arkts-user-defined.md)是指具备底层实体节点的部分基础能力的节点对象，这些节点能够通过自定义占位节点与原生组件进行混合显示。自定义节点可以具备单个节点的测算布局、设置基础属性、设置事件监听、自定义绘制渲染内容的自定义能力。包括FrameNode、RenderNode、BuilderNode三类对象。详细如下：
  - BuilderNode：提供能够挂载原生组件的自定义节点BuilderNode。
  - FrameNode：提供自定义节点FrameNode，表示组件树的实体节点。NodeController可通过BuilderNode持有的FrameNode将其挂载到NodeContainer上，也可通过FrameNode获取RenderNode，挂载到其他FrameNode上。
  - RenderNode：提供自绘制渲染节点RenderNode，支持在Native侧完成自定义绘制需求。
  - NodeController：提供NodeController用于实现自定义节点的创建、显示、更新等操作，并负责将自定义节点挂载到NodeContainer上。

- 适用于三方框架的组件NDK能力增强，涵盖组件创建、属性设置、事件注册、自定义能力、组件树构建。

- Navigation组件能力增强，包括单双栏切换动效、转场动画的打断和接续，以及页面生命周期的监听能力。

- 控件视觉、动效和交互刷新，以及支持适老化、镜像语言和屏幕朗读。

- 菜单和弹窗类组件支持开发者组定义颜色、形状、圆角、大小、位置和阴影。


### 应用包管理

- 支持应用分身的接入和管理，应用可以通过简单的配置即可接入应用分身。

- 支持桌面快捷方式，用户可以动态添加快捷方式到桌面。

- 支持系统级HSP和ArkWeb独立升级能力，支持独立更新预置的应用。

- 支持OTA升级异常中断后恢复机制，OTA升级流程中出现断电、服务crash，重启时恢复OTA流程，继续安装、更新应用；

- 提供cache目录自动清理能力，支持存储管理在设备空间不足时自动清理cache目录。

- 支持Native软件包，提供Native软件包的打包、安装和卸载能力。

- 打包工具打包app时，对app包整体压缩，减少上架app的包大小。


### 分布式软总线

IPC提供CAPI基础接口能力，包括序列化/反序列化、消息收发处理接口等。


### 分布式数据管理

- RelationalStore&amp;Preferences支持共沙箱数据的访问方式。

- RDB支持只读方式打开。

- UDMF支持UTD与MIME Type的兼容性查询。

- 迁移场景数据资产同步优化。

- 支持E类加密的分布式数据管理。

- 倒排索引构建场景，支持应用指定外挂分词器。

- 基于NDK的C API支持UDMF数据跨设备拖拽能力。


### 分布式硬件

- 提供ACL精细化管理：根据业务的设备、用户、账号、包名对ACL进行精细的增、删、改、查操作。

- 质量加固，提高功能稳定性和可靠性。

### 分布式DeviceProfile

- 设备数据分级重构，提高对数据增删改查的执行效率。

- 质量加固，后台建立链接功能优化，提高稳定性和可靠性。

### 文件管理

- 支持文件增量备份的能力。

- 提供备份应用获取备份数据量详情的接口，允许应用上报待备份数据记录数（如：短信条数），支持备份恢复过程中的异常事件上报。

- 新增支持SA接入备份恢复框架。

- 增强Picker能力：提供Audio Picker一次多选的能力；新增Download Picker，应用可直接将文件保存到“Download/包名级”目录下，且后续对该目录的访问无需申请权限，补齐浏览器等应用的下载体验。

- 支持应用通过申请权限等方式获取公共目录（Download、Desktop、Document）的访问权限（部分设备支持，需通过syscap判断），未申请权限无法直接访问。

- 支持应用通过FilePicker的方式选择文件或目录并获取对该目录或文件的临时访问权限，并支持持久化访问能力，未持久化的文件或目录，在应用退出后无法再继续访问。

- 新增CreateStream、fdopenStream 等流式的文件访问接口。

- 新增设置和获取扩展属性的接口。


### 图形图像及窗口

**图形图像**

- 基于NDK的C API的NativeImage模块新增支持NativeWindowBuffer。

- 基于NDK的C API新增支持NativeVsync，支持单帧多次回调能力。

- 基于NDK的C API新增支持可变帧率的能力。

- ColorSpaceManager支持sendable能力。

- 字体引擎支持文字阴影能力，支持下划线对齐。

- 图形绘制接口完善绘制相关能力。

**窗口**

- 提供display.getDisplayByIdSync接口配合多屏特性使用，支持应用通过id同步获取Ability所在屏幕信息 。

- 支持获取屏幕可用区信息。

- 支持在ArkUI中根据页面颜色设置状态栏文本颜色。


### 媒体

**音频**

- 音频焦点增强：支持焦点会话，允许应用设置与其他应用的并发播放策略，允许应用静音播放时不打断后台播放中的音频。

- 新增支持DP、USB耳机等更多的音频发声设备，支持切换默认发声设备功能（听筒和扬声器）。

- 新增视频通话的音频流类型，优化该场景下的音频流播放体验。

- 新增统一音量组件，方便使用、降低开发复杂度。

- 支持应用内投播组件样式的自定义。

- 支持铃音列表查询和自定义铃音设置。

**播放**

- 播放器起播、Seek性能优化，降低时延。

- 新增多种播放协议或格式：支持DASH流媒体协议播放；支持AMR、APE、WAV PCM-MULAW格式音频播放。

- 新增多种播放控制的能力：支持多音轨视频播放、播放视频过程更换输出Surface、静音播放、精准Seek、设置播放区间、字幕。

- 支持配置流媒体缓冲大小；支持音频Offload模式。 

- 流媒体播放能力增强：优化流媒体缓存策略，减少卡顿。

**录制**

音频录制能力增强：支持mp3 、WAV  PCM -MULAW格式音频录制。

**录屏**

- 支持对应用自身隐私窗口豁免录屏保护，提供隐私确认窗口和录屏状态提示。

- 支持录屏时排除指定窗口的画面。

- 支持配置屏幕旋转并可动态调整旋转参数。

- 支持麦克风和系统音同时录制。

**音视频编解码**

新增AVTranscoder转码接口，支持降低码率，输出视频编码AVC、音频编码AAC、封装格式MP4的视频文件，减少传输/存储数据量。

**DRM**

- AVPlayer/AVCodec支持DASH协议节目的DRM信息解析、支持TS封装的H265视频格式的解密、支持音频解密。

- AVCodec DRM适配增加解密参数设置。

**相机**

- 新增模式化能力，包括：延时摄影、全景、流光快门、大光圈录像、荧光摄影。

- 新增相机PerConfig一键配置机制，确保相机效果一致，降低开发复杂度。

- 优化分段式流程，提升拍照/录像的性能与质量。

- 对标ArkTS API能力，补齐相关C API。

- 增强相机使用体验，包括：镜像、变焦、防抖、连拍、相机状态通知等。

**图片**

- EXIF读写能力增强，支持EXIF批量读写，GIF支持获取播放次数信息。

- 支持HDR能力：HDR双层编解码、HDR与SDR互转。

- 编解码格式增强，支持HEIF编解码，DNG解码。

- 编创框架基于NDK的C API补齐，包括：效果器基类、滤镜基类、自定义算法。


### 事件通知

- CEM工具新增支持发布自定义公共事件。

- Emitter新增泛型接口，可以用来直接传递Sendable对象。

- 支持同步查询通知的使能状态。


### 基础通信

支持三方应用通过网络管理连接热点。


### 网络管理

**网络管理能力**

- 支持通过创建NetConnection对象连接目标指定Wi-Fi热点。

- 提供网络管理状态监听、应用级代理监听等能力的基于NDK的C API。

**网络协议栈能力**

- 支持将TCP Socket升级成TLS Socket，提升通信安全性。

- TLS Socket支持跳过证书校验，避免特殊情况下无法校验证书的场景。

- 所有Socket均支持获取本地IP与端口。

- HTTP支持配置证书锁定信息。

- HTTP支持brotli压缩算法。


### 电源

- 支持获取当前充电电流，三方应用可以通过nowCurrent获取当前设备电流。

- 支持飞行模式的温度管控动作，开发者可定制温控策略控制设备进入飞行模式。

- 支持根据WorkSource代理运行锁辅助资源调度模块进行功耗控制。

- 支持低电量时从S3睡眠状态唤醒后自动进入S4休眠，实现超长待机特性。

- 支持系统启动后读取并广播设备壳/套的在位信息，电池信息内核节点和是否发广播等支持开发者配置。


### USB

- USB DEVICE配置管理安全访问控制增强。

- USB标准数据传输模式(中断传输、Bulk传输)功能增强。

- 支持标准类型USB外设安全管控。

### 启动恢复

- 支持Native软件包打包、安装、运行和卸载，搭建Native软件包开发和发布系统，有助于生产力软件生态能力的快速构建，也有助于系统开发者提升开发效率。

- 提供可重置的开发者匿名设备标识符ODID，代替UDID以及其他的硬件标识符。

- 支持运行bftpd命令，支持user模式下调试应用沙箱数据访问。

### 全球化

- 提供C API支持ICU4C标准的国际化能力。

- 国际化的格式化处理能力支持屏幕大小自适应。

- 全面支持伪本地化测试。

- 提供C API支持资源文件管理能力。

- 字符串资源支持可翻译性的标记。

- 提供小语种字库能力。


### 安全

**加解密算法库框架**

- 对标部分常用加解密算法能力的ArkTS API，提供对应的C API。

- 支持SM4-GCM算法接口。

**证书管理**

- 提供拉起证书管理界面的API。

- 提供获取应用私有证书列表的API。

**程序访问控制**

- 地理位置权限支持单次授权选项。

- 支持拉起设置页面的权限管理应用界面。

**用户IAM**

- 支持口令有效期检查。

- 支持恢复密钥。

**账号**

- 支持注销本地账号。

- 支持创建本地账号时，指定账号短名称（用作个人文件夹名称）。

- 支持查询本地账号名称。

- 新增隐私账号类型。

- 新增解锁认证意图。

- 新增图形、四位PIN凭据类型。


### ArkCompiler

**ArkTS前端编译器**

- 语法增强，编译目标从es2017切换到es2021，支持编译带有es2018~es2021语法特性的源码文件。

- 混淆能力增强，支持异常堆栈还原的能力、文件粒度不混淆的功能、HAP与HSP模块文件名混淆功能、白名单通配符功能。

**ArkTS运行时**

- 支持模块懒加载，在变量被真正使用时再同步加载执行文件，提升应用启动性能。

- 并发能力增强，提供Sendable对象共享机制，优化对象跨线程通信性能；TaskPool提供任务队列、长时任务、周期任务等功能。

- 调试功能增强，支持反向调试、Smart Stepinto等功能。

- 调优功能增强，支持hiperf/profiler混合回栈、多实例HeapDump功能。

**ArkTS基础库**

- 支持高精度浮点运算功能，提供StringDecoder字符流解码能力、stream数据流处理能力，支持位向量。

**JSVM**

- 提供系统JS引擎，支持高性能运行JS和WASM的能力。


### 综合传感处理平台

**拖拽框架**

- 支持随着窗口旋转，旋转拖拽窗口。

- 支持三设备之间进行拖拽。

- 支持应用自定义配置拖拽过程中不显示数量角标。

- 支持数据接收方自定义剪切与复制行为。

**键鼠穿越**

- 管控双端同时发起activate接口调用。

- 键鼠穿越时序问题优化，减少系统依赖，消除多进程间时序问题。

- 提高穿越管理性能，提高成功率，降低穿越时延。


### 多模输入

提供C API支持设备信息查询等相关能力。


### 泛Sensor

**vibrator**

- 部分异步查询接口提供同步版本API。

- 系统可以根据不同的器件能力等级更好的使用马达器件触发振感。

**sensor**

- 部分异步查询接口提供同步版本API。

- 提供C API支持线性加速度、游戏旋转向量传感器。


### 无障碍服务

- 放大手势，支持通过手势对屏幕内容进行放大显示操作。

- 主动播报能力，应用适配屏幕朗读时，在一些动态变化的场景下，可支持通过无障碍进行变化信息的主动播报。

- 主动聚焦能力，应用适配屏幕朗读时，在某些场景下，可对组件请求主动聚焦。


### 资源调度

**后台任务**

- 应用申请长时任务类型，支持同时申请多种类型的长时任务。

- 应用申请DATA_TRANSFER下载类长时任务，支持返回下载通知给应用进行进度更新。

**性能功耗热融合管控**

- 根据当前温度、负载以及是否处于高负载场景等信息决策出系统负载融合档位，应用注册系统负载回调后，可根据系统负载融合档位的不同等级，自适应降级自身业务负载，从而降低整机负载。

**代理提醒**

- 应用申请重复类型的日历提醒时，支持指定剔除日，在剔除日内不进行提醒。

- 应用申请提醒时，wantAgent 支持传递 parameters 参数，在点击提醒后跳转到目标UIAbility时，携带 parameters 参数。

- 应用查询已发布的提醒时，查询结果中返回对应的 reminderId 。


### 测试框架

支持跨平台接口的兼容性测试。


### DFX

- 提供判断HDC调试器是否连接的API。

- 支持在开发者模式打开trace功能。

- 开放主线程超时事件的感知。

- errorManager支持TaskPool和Worker监听未处理的Reject事件。


### 内核

提供基于用户交互关系的线程QoS等级标注和调度。


### 上传下载

- request.agent.Fault 细化了错误类型，便于开发者快速定位接口使用问题。

- request.agent.Config 新增 proxy 成员，支持设置任务的网络代理地址。

- request.agent.Task.start 支持重新启动已经失败\停止的任务，便于开发者快速恢复失败任务。

- request.agent.Task 支持使用 network.json 配置文件配置 TLS 证书锁定指纹。

- request.agent.FileSpec 支持指定应用沙箱 base 目录下的所有文件路径，便于开发者管理沙箱文件；同时支持前台上传公共文件，例如图库文件、相册文件等，减少额外拷贝带来的开销。

### 输入法框架

- 基于NDK的C API新增支持自绘UI组件使用输入法，包括拉起、退出输入法，处理文字上屏请求等操作。

- 优化拉起键盘时回调时序，输入法应用可根据输入框属性及时调整键盘显示内容。

### 时间时区

- 提供NTP时间强制刷新和获取当前NTP时间的系统API。

- 基于NDK的C API提供获取时区的能力。


### 剪贴板

- 基于NDK的C API支持剪贴板的能力。

- 提供跨设备剪贴板开关。

- 在应用升级到API 12及以后，对读取剪贴板接口增加读权限校验。


### Web

- 网络接管特性增强，支持获取请求的FrameUrl，支持获取被拦截请求的ResourceType。

- 支持Web场景输入法预上屏能力。

- 支持Web组件键盘托管能力。

- 支持Web组件与ArkUI原生组件同步绘制能力。

- 支持设置File协议可跨域访问的白名单目录。

- 支持应用可指定渲染子进程。

- Web组件支持加速度陀螺仪。

- Web组件支持H5页面智能填充。

- Web组件支持BFCache能力。

- 完善Web组件软键盘避让机制，支持Resize和Offset模式。


### 主题框架

- 支持通过文件夹目录使能主题，相比压缩包使能，提升使能主题的性能。

- 支持卡片资源的管理，支持被添加主题卡片的增删改查能力。

- 为外屏设备做特性化功能，支持使能外屏主题。

- 主题使能支持不切换当前“active”目录。


### 编译构建

编译构建依赖的CMake版本从3.16.5升级到3.28.2。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 5.0.0 Release | NA | 
| Public SDK | Ohos_sdk_public 5.0.0.71 (API Version 12 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。 | 
| HUAWEI DevEco Studio（可选） | 5.0.0 Release | OpenHarmony应用开发推荐使用。<br />[请点击这里获取](https://developer.huawei.com/consumer/cn/download/)。 | 
| HUAWEI DevEco Device Tool（可选） | 4.0 Release | OpenHarmony智能设备集成开发环境推荐使用。<br />[请点击这里获取](https://device.harmonyos.com/cn/develop/ide#download)。  | 


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Hi3861解决方案（二进制）        | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_pegasus.tar.gz.sha256) | 27.1 MB |
| Hi3516解决方案-LiteOS（二进制） | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.3 MB |
| Hi3516解决方案-Linux（二进制）  | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 220.4 MB |
| RK3568标准系统解决方案（二进制）        | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/dayu200_standard_arm32.tar.gz.sha256) | 519.7 MB |
| 标准系统Public SDK包（Mac）             | 5.0.0.71 | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| 标准系统Public SDK包（Mac-M1）             | 5.0.0.71  | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| 标准系统Public SDK包（Windows/Linux）   | 5.0.0.71   | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.5 GB |




## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| -------- | -------- |
| IA686U | 进程com.ohos.photos下的OS_FFRT_2_0线程有较高概率导致libace_napi.z.so出现cppcrash。 |
| I9YC9X | 进程com.ohos.camera有较高概率由于LIFECYCLE_TIMEOUT卡在libark_jsruntime.so出现sysfreeze。 |
| I9TE52 | 进程com.ohos.photos有一定概率由于THREAD_BLOCK_6S卡在libark_jsruntime.so出现appfreeze。 |
| I9TDUU | 关键应用: ohos.samples.distributedcalc小概率由于THREAD_BLOCK_6S卡在libace_compatible.z.so出现appfrreze问题。 |
| I9TE5K | 进程com.ohos.photos小概率由于THREAD_BLOCK_6S卡在libunwind.z.so出现appfreeze。 |
| I9TJGB | 进程com.ohos.camera下的RSRenderThread进程有小概率导致libmali-bifrost-g52-g7p0-ohos.so出现cppcrash。 |
| IA5EC3 | 进程com.ohos.updateapp小概率由于THREAD_BLOCK_6S卡在libskia_canvaskit.z.so出现appfreeze。 |
| IA5I3D | 进程com.ohos.smartperf小概率由于THREAD_BLOCK_6S卡在librender_service_base.z.so出现appfreeze。 |
| IA4G47 | 进程av_codec_service下的av_codec_service线程极小概率出现cppcrash，崩溃栈：libhcodec.z.so。 |
| I9TDMQ | 关键应用: com.ohos.settings极小概率由于THREAD_BLOCK_6S卡在libskia_canvaskit.z.so出现appfrreze问题。 |


## 遗留缺陷列表

**表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| I9S5ZN | 进程com.ohos.settings小概率出现因THREAD_BLOCK_6S卡在libunwind.z.so导致的appfrreze。 | 设置页面卡顿。<br/>规避措施：重启设置应用。 | 10.15 | 
| I9S600 | 进程com.ohos.settings小概率出现因THREAD_BLOCK_6S卡在libark_jsruntime.so导致的appfrreze。 | 设置页面卡顿。<br/>规避措施：重启设置应用。 | 10.15 | 
| IAB2U3<br>IAK2J2 | 进程audio_server下的OS_APAsyncRunne线程小概率出现因libaudio_client.z.so崩溃导致的cppcrash。 | 对用户无影响，无需规避。 | 10.15 | 
| IAIRFB | 进程com.ohos.note下的com.ohos.note线程小概率出现因libweb_engine.so崩溃导致的cppcrash。 | 异常出现后应用会闪退，重启应用可恢复。 | 10.15 | 
| I9SXZ8 | 进程com.ohos.contacts小概率出现因THREAD_BLOCK_6S卡在libark_jsruntime.so导致的appfreez。 | 异常出现后联系人应用进入通话记录查询通话记录卡顿，重启联系人应用可恢复。 | 10.15 | 
| IAKLLD | 进程audio_server下的SaInit2线程小概率出现因libaudio_policy_service.z.so崩溃导致的cppcrash。 | 异常出现后进程重启，客户端有自恢复机制，对用户无影响，无需规避。 | 10.15 | 
| IA56CU | 进程com.ohos.note下的com.ohos.note线程小概率出现因libweb_engine.so导致的cppcrash。 | 异常出现后应用会闪退，重启应用可恢复。 | 9.30 | 
| IA5AMJ | 进程com.ohos.launcher小概率出现因THREAD_BLOCK_6S卡在libark_jsruntime.so导致的appfreeze。 | 异常出现后进入多任务界面时会感知到获取应用截图卡顿约3秒左右，加载完成后恢复正常。 | 9.30 | 
| IA5AIT | render_service小概率出现因SERVICE_BLOCK导致的sysfreeze。 | 异常出现后应用页面冻屏无响应，重启设备可恢复。 | 10.15 | 
| IA6RH6 | 进程com.ohos.settings有较高概率出现因THREAD_BLOCK_6S卡在libbtframework.z.so导致的appfreeze。 | 会又低概率造成“设置”应用卡死，重新打开“设置”可恢复。 | 10.15 | 
| IA6RFX | 进程bluetooth_service下的OSaInit0线程有较高概率出现因libbtservice.z.so崩溃导致的cppcrash。 | 会有低概率造成蓝牙相关应用crash，重启应用可恢复。 | 10.15 | 
| IA8KGR | 进程bluetooth_service下的OS_IPC_12_22172线程小概率出现因libbluetooth_server.z.so崩溃导致的cppcrash。 | 会有低概率造成蓝牙相关应用crash，重启应用可恢复。 | 10.15 | 
| IAQC64 | 随机打开几个应用，再打开设置。返回到桌面，再反复进入后台界面，设置会出现泄露，操作1次大概增长32KB。 | 多任务场景下反复切换“设置”应用前后台，可能造成应用闪退。重新打开“设置”可恢复。 | 10.15 | 
| IASE04 | 在RK3568开发板对OpenHarmony进行内存测试，render_service进程的常驻内存实测值超规格基线31 MB。 | 整机内存占用高于预期。 | 10.15 | 
| IASDWO | 通过浏览器访问微博首页的滑动帧率低于规格基线。 | 影响浏览体验。 | 10.15 | 
