# OpenHarmony 5.0.0 Release


## 版本概述

OpenHarmony 5.0.0 Release版本标准系统能力持续完善。相比OpenHarmony 4.1 Release版本做出了如下特性新增或增强：

应用框架新增更多生命周期管理能力、提供子进程相关能力，可以对应用运行时的任务执行进行更精细的调度和管理，细化了生命周期管理能力，完善了应用拉起、跳转的能力；ArkUI进一步开放自定义节点的渲染能力，完善了组件通过C API调用的能力；应用包管理提升了应用打包效率，丰富了终端用户使用应用时的可操作场景（如创建应用分身、创建桌面快捷方式等）；分布式软总线连接能力和规格进一步增强；分布式数据管理能力进一步增强，在保证数据合理共享的前提下增强安全性，其他模块能力适配Sendable机制也得到了增强；文件管理进一步完善Picker的能力，对文件资源做到合理管控权限和合理使用；媒体在音视频播放、录制方面能力进一步增强，新增支持多个音视频、图片的编码格式，支持更细节的播控操作，相机提供更强大的能力，丰富终端用户拍照场景，完善了框架能力、视频编解码能力、音视频的应用能力，媒体库丰富了使用场景，提供更好的使用体验。

多个子系统进一步对标ArkTS能力补齐NDK的C API能力，如ArkUI适配三方框架的能力、数据管理UDMF、图形绘制、播放框架、相机、图形编解码、网络管理、国际化、时间时区、输入法框架、剪贴板等。

OpenHarmony 5.0.0 Release版本为API Level 12的正式Release版本。

更详细的特性新增与增强的说明如下：


### 应用框架

- 支持创建JS / Native子进程，开发者可以把耗时操作放到子进程中执行。

- Ability生命周期监听支持onNewWant等更多生命周期。

- 支持Ability在不主动销毁自己的情况下，将AbilityResult结果返回给调用方。

- Context支持Sendable对象转换，用于多线程传递Context。

- 支持应用级别的字体设置。

- 新增AppStartUp应用并行化启动框架，提供一种在应用启动时初始化组件的简单而高效的方法，有效提升启动性能。

- 新增原子化服务启动API，提供跳出式和嵌入式两种启动方式。

- 自动填充能力增强：开发者在使用TextInput组件时支持更多类型数据的自动保存和自动填充能力。

- 卡片能力增强：提供单色模式、反色能力、渐变撞色、卡片视觉呈现精致（模糊、投影、圆角等）、展示背景自然融合，高端精致。

- aa工具支持隐式启动应用。

- 统一DeepLink和AppLinking跳转技术方案，降低开发者使用成本，提高跳转安全性。

- 提供安全的应用重启能力。

- 系统环境新增字体大小和粗细变化通知。

- UIAbilityContext上下文能力增强：
  - 提供获取WindowStage能力。
  - 提供应用主动把UIAbility移到后台的能力。

- 新增应用生命周期：
  - AbilityStage新增OnDestroy生命周期。
  - UIAbility新增onWindowStageWillDestroy生命周期。

- 新增应用等待调试模式。

- 支持跨端迁移时，同应用跨Ability迁移。

- 支持跨端迁移时，应用使用异步接口保存数据。

- 支持跨端迁移时，应用通过配置立即启动字段，在pull场景下提前启动可迁移应用。


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

- 自定义节点能力增强，提供FrameNode的自定义能力以及节点代理能力：
  - 支持节点的动态增加、删除。
  - 支持节点设置通用属性和事件。
  - 支持遍历节点树的能力。
  - 支持通过节点访问组件的信息、注册额外的事件监听回调。
  - 支持节点的自定义测量、布局、绘制。

- 自定义扩展能力增强，提供各类Modifier能力：
  - 提供基础组件的Modifier，支持链式调用和参数传递，可继承实现自定义的Modifier。
  - 提供AttributeUpdater支持属性直通更新的能力。
  - 提供GestureModifier支持手势的动态设置。
  - 提供DrawModifier支持扩展原生组件的绘制内容。
  - 部分组件提供ContentModifier，支持使用自定义的Builder方法定制组件的内容样式。

- Navigation能力增强：
  - 新增页面生命周期：支持onWillShow和onWillHide页面生命周期。
  - 转场动画支持打断和接续。
  - 页面内容扩展到状态栏。
  - 单例跳转能力。
  - 自定义动效能力增强。

- 文本类高阶能力增强：
  - 文本类组件支持属性字符串。
  - 支持WebView应用和ArkUI应用之间的图文混排拖拽。
  - RichEditor支持设置提示信息hint。


### 应用包管理

- 支持应用分身的接入和管理，应用可以通过简单的配置即可接入应用分身。

- 支持桌面快捷方式，用户可以动态添加快捷方式到桌面。

- 支持系统级HSP和ArkWeb独立升级能力，支持独立更新预置的应用。

- 支持OTA升级异常中断后恢复机制，OTA升级流程中出现断电、服务crash，重启时恢复OTA流程，继续安装、更新应用；

- 提供cache目录自动清理能力，支持存储管理在设备空间不足时自动清理cache目录。

- 支持Native软件包，提供Native软件包的打包、安装和卸载能力。

- 打包工具打包app时，对app包整体压缩，减少上架app的包大小。

- 业务模块（HSP/HAR）支持配置router_map.json路由表，实现模块间动态路由解耦。

- 支持集成态HSP，集团内部的多个应用之间，可以使用集成态HSP实现代码和资源共享。

- 支持卸载更新的能力，通过应用市场更新的预置应用，可以通过卸载更新恢复到系统预设的版本。

- 提供In-House应用的安装及查询能力，支持In-House应用管理。

- 统一资源缓存，支持overlay和主题切换场景。

- 支持gzip格式文件解压缩能力。

- 支持resfile目录，resfile目录开发者可以自由放置各类资源文件，应用安装时，资源会被解压到应用沙箱路径。


### 分布式软总线

- IPC提供CAPI基础接口能力，包括序列化/反序列化、消息收发处理接口等。

- BR/BLE连接新增传输优先级控制，提升BLE发现广播成功率。

- 支持BR/BLE链路复用能力，同时确保复用流程不被业务打断，提升复用成功率。

- 组网支持多介质组网归一，避免重复认证，提升认证效率。

- 支持逻辑通道与物理链路解耦，增加连接成功率。

- 传输模块提供加解密接口，并支持Bind接口中途取消、超时可配置等能力。

- IPC支持异步消息发送方信息、并提供高性能读写共享内存的JS北向接口能力。

- IPC_Core和IPC_Single公共部分解耦，持续优化内存使用。


### 分布式数据管理

- RelationalStore&amp;Preferences支持共沙箱数据的访问方式。

- RDB支持只读方式打开。

- UDMF支持UTD与MIME Type的兼容性查询。

- 迁移场景数据资产同步优化。

- 支持E类加密的分布式数据管理。

- 倒排索引构建场景，支持应用指定外挂分词器。

- 基于NDK的C API支持UDMF数据跨设备拖拽能力。

- Preferences支持可序列化为JSON的Object类型，及基于key的精准订阅。

- relational_store支持TS同步接口。

- UDMF支持批量事务，新增4种常用数据结构标准化定义，40种UTD数据类型。

- data_share在资源占用、访问控制、访问精度等方面进行了优化。


### 分布式硬件

- 提供ACL精细化管理：根据业务的设备、用户、账号、包名对ACL进行精细的增、删、改、查操作。

- 质量加固，提高功能稳定性和可靠性。

- 支持管理可信和非可信设备资源，对应用提供设备信息的查询、筛选、排序和监听等功能。

- 提供PIN码、碰、扫、靠等设备认证框架，支持对接各种认证交互入口。

- 为设备资源管理提供设备组网 、上下线、扫描周边设备的能力。


### 分布式DeviceProfile

- 设备数据分级重构，提高对数据增删改查的执行效率。

- 质量加固，后台建立链接功能优化，提高稳定性和可靠性。

- 支持为系统服务提供跨设备可信关系、可信设备信息、设备系统信息、服务信息和服务特征信息的增删改查和订阅数据变化通知的服务。

- 支持跨设备数据端端按需同步和蓝牙心跳广播同步，支持数据按照开关类、静态类和动态类数据进行分级，供业务方根据自身数据特点定义、操作不同类型数据。


### 文件管理

- 支持文件增量备份，支撑云空间增量的特性。

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

- Drawing能力增强，支持矢量图元绘制、位图绘制及样式视效等，支持对文本绘制施加阴影效果。

- 位图ArkTS和C API能力增强，支持转换格式、透明度预乘、效果处理等接口。

- 文本引擎NDK能力增强，支持设置行间距、多种换行策略等。

- surfaceNDK能力增强，支持获取YUV数据的位置、获取surfaceid、Attach和Detach和获取BufferQueueSize的C API。

- 提供LTPO控帧能力。

- 3D组件能力增强，支持加载编辑控制3D场景。

- 提供OpenGL ES扩展接口。

- 性能能效进一步优化。

**窗口**

- 提供display.getDisplayByIdSync接口配合多屏特性使用，支持应用通过id同步获取Ability所在屏幕信息 。

- 支持获取屏幕可用区信息。

- 支持在ArkUI中根据页面颜色设置状态栏文本颜色。

- 支持应用获取状态栏的颜色属性。

- 跨平台能力增强，loadContentByName、windowSizeChange等接口适配跨平台能力。


### 媒体

**音频**

- 音频焦点增强：支持焦点会话，允许应用设置与其他应用的并发播放策略，允许应用静音播放时不打断后台播放中的音频。

- 新增支持DP、USB耳机等更多的音频发声设备，支持切换默认发声设备功能（听筒和扬声器）。

- 新增视频通话的音频流类型，优化该场景下的音频流播放体验。

- 新增统一音量组件，方便使用、降低开发复杂度。

- 支持应用内投播组件样式的自定义。

- 支持铃音列表查询和自定义铃音设置。

- 音频内录功能支持按流类型、应用过滤。

- 音频低功耗播放支持变速、音效处理。

- 有线耳机和蓝牙耳机支持音频高清播放。

- 空间音频支持外放空间音频渲染。

- VOIP语音通话支持低时延通路。

- 系统音管理新增支持获取系统音列表和自定义系统音。

**播放**

- 播放器起播、Seek性能优化，降低时延。

- 新增多种播放协议或格式：支持DASH流媒体协议播放；支持AMR、APE、WAV PCM-MULAW格式音频播放。

- 新增多种播放控制的能力：支持多音轨视频播放、播放视频过程更换输出Surface、静音播放、精准Seek、设置播放区间、字幕。

- 支持配置流媒体缓冲大小；支持音频Offload模式。 

- 流媒体播放能力增强：优化流媒体缓存策略，减少卡顿。

- 支持在播放时选择更多的倍速（0.5/1.5倍速）。

- 支持更多格式的播放能力（如AMR）。

- 提供更多的音频编码参数供用户进行呈现（如位深）。

- 提供低功耗的音频播放能力（Offload）供用户选择。

- 支持精准SEEK能力。

- 视频播放过程中，用户可以将视频切换到其他窗口。

- 提供自定义Header能力，便于用户在流媒体播放时添加自定义信息。

- 支持FLV网络直播能力。

- 网络播放下，根据网络质量自动切换到适合的码率下播放。

**录制**

- 音频录制能力增强：支持mp3 、WAV  PCM -MULAW格式音频录制。

- 支持动态配置画面旋转参数。

- 支持视频录制分层编码功能。

**媒体元数据**

提供HDR Vivid视频的识别能力。

**录屏**

- 支持对应用自身隐私窗口豁免录屏保护，提供隐私确认窗口和录屏状态提示。

- 支持录屏时排除指定窗口的画面。

- 支持配置屏幕旋转并可动态调整旋转参数。

- 支持麦克风和系统音同时录制。

- 支持使用C API录制系统屏幕和声音。

- 支持使用Surface模式获取录屏数据。

- 支持配置录屏内容跟随屏幕旋转。

- 录屏不与蜂窝通话并发。

- 支持麦克风和系统音同时录制。

- 录屏提供隐私弹窗，由用户授权启动录屏。

- 录屏支持排除指定windowID的窗口画面。

- 录屏支持排除应用自身音频。

**数字版权保护服务**

- 支持DRM插件管理和DRM解决方案的集成。

- 支持DRM证书下载。

- 支持DRM节目在线及离线授权。

- 支持DRM节目解密，支持安全、非安解密。

- 支持安全视频通路；

- 支持HLS+TS/DASH+fMP4协议DRM节目授权及解密播放。

- 支持AVPlayer及AVCodec播放框架集成。

**音视频编解码**

- 新增AVTranscoder转码接口，支持降低码率，输出视频编码AVC、音频编码AAC、封装格式MP4的视频文件，减少传输/存储数据量。

- 支持ape解码和解封装。

- 支持mp3编码和封装。

- 支持SRT格式字幕解析。

- H.264/H.265硬件编码支持随帧设置长期参考帧，参考帧编码，依赖硬件芯片能力。

- H.264/H.265硬件编码支持随帧设置编码QP，依赖硬件芯片能力。

- H.264/H.265硬件编解码支持低时延出帧（one-in-one-out），依赖硬件芯片能力。

- H.264/H.265硬件编码支持重置码率和帧率，依赖硬件芯片能力。

- H.264/H.265硬件编码支持分级P分层编码，依赖硬件芯片能力。

- 支持fmp4文件解析。

- surface模式下，硬件解码支持surface切换。

**DRM**

- AVPlayer/AVCodec支持DASH协议节目的DRM信息解析、支持TS封装的H265视频格式的解密、支持音频解密。

- AVCodec DRM适配增加解密参数设置。

**相机**

- 新增模式化能力，包括：延时摄影、全景、流光快门、大光圈录像、荧光摄影。

- 新增相机PerConfig一键配置机制，确保相机效果一致，降低开发复杂度。

- 优化分段式流程，提升拍照/录像的性能与质量。

- 对标ArkTS API能力，补齐相关C API。

- 增强相机使用体验，包括：镜像、变焦、防抖、连拍、相机状态通知等。

- 相机模式增强，新增专业、超级微距、超级慢动作、安全等模式。

- 相机拍照增强，支持动态照片、HDR Vivid拍摄，开放分段式拍照。

- 相机效果增强，支持黑白色彩、人像虚化等效果。

- 相机控制增强，支持动态配置帧率，支持动效焦距、环境亮度等信息返回。

**图片**

- EXIF读写能力增强，支持EXIF批量读写，GIF支持获取播放次数信息。

- 支持HDR能力：HDR双层编解码、HDR与SDR互转。

- 编解码格式增强，支持HEIF编解码，DNG解码。

- 编创框架基于NDK的C API补齐，包括：效果器基类、滤镜基类、自定义算法。

- 图片编解码新增Heif解码

- 图片编解码新增DNG解码。

- 图片编解码C API支持。

- 图片编解码支持HDR效果（依赖平台能力）。

- 图片编解码增加exif覆盖范围和批量读写exif能力。

- 支持图片解码为YUV格式（当前Heif，Jpeg支持）

- GIF解码能力增强，支持获取播放次数、帧过渡模式。

- webp格式支持帧时延时间获取。

- Jpeg编解码硬件加速性能优化（依赖平台能力）。

- 图片编辑NDK接口开放，支持管线编排、效果器、滤镜链。

**媒体库**

- 支持全新的分段式拍照流程，支持应用拍照后只消费、直接保存、编辑保存等行为。

- 支持开发者模式下使用hdc命令读取媒体库公共存储区的图片和视频能力。

- 支持开发者模式下使用hdc命令解析媒体库加密的图片和视频文件名称。

- 支持root模式下使用mediatool进行图片和视频资源预制能力。

- 支持应用识别HDR图片和视频类型，提供HDR的LCD缩略图。

- 增强了图片视频被删除时及时刷新搜索索引的能力。

- 新增了视频标签、自然语义、检测人头和宠物头能力的存储和开放。

- 支持应用读取图片OCR信息时的及时生成能力。

- 支持应用查找图片和视频资产在智慧相册中的位置。

- 支持解析视频资产经纬度的能力。

- 权限优化，支持应用长期持有自身保存的图片和视频的读写权限。

- 支持应用导出视频资产至应用沙箱。

- 增强恶意应用访问云图时的流控机制。

- 机制优化，云图变化时通过媒体库发布变更通知。

- 支持分段式拍照图片水印和滤镜的编辑和可回退特性16.机制优化，精准识别应用访问图片、视频原文件的行为并进行上报统计。

- 机制优化，用户图片和视频占用存储空间统计缩略图占用空间。

- 支持应用通过C API读取图片和视频。

- 支持应用查询已命名的人像信息。

- 媒体库支持动态照片的拍摄、保存、读取能力；支持应用设置动态照片封面帧信息，支持应用设置动态照片效果模式。

- 新增铃音库部分，支持系统预制铃音和用户自定义铃音。

- 支持拍摄模式信息上云。

- DFX能力增强，包含用户静态数据、耗时行为、删除行为、应用行为统计等。


### 事件通知

- CEM工具新增支持发布自定义公共事件。

- Emitter新增泛型接口，可以用来直接传递Sendable对象。

- 支持同步查询通知的使能状态。

- 支持有权限的应用自定义通知铃声。

- 支持应用通过系统代理方式创建进度条类型的实况通知。

- 支持不同分身应用发布通知。

- 提供查询通知授权状态的同步接口。

- 支持系统应用批量查询已授权通知、实况窗的应用列表及状态。

- 支持系统应用发布紧急事件提醒类型通知。

- 支持系统应用按设备类型订阅通知，在手机和其他设备间进行通知协同提醒。

- 支持系统应用代理其他应用设置角标。

- 通知勿扰模式下支持配置应用白名单，白名单内应用不受勿扰模式影响。

- 支持系统应用在运行时删除、重新添加静态订阅的公共事件。


### 基础通信

- 支持三方应用通过网络管理连接热点。

- DHCP服务能力优化，支持获取对端名称、IP地址等信息。

- 已保存热点密码信息保护安全优化。

- WLAN服务的线程数&amp;架构优化。


### 位置

- 在持续定位过程中，支持监听影响定位的错误码信息。

- GNSS卫星状态信息以及持续定位等相关API优化。

- 位置服务的安全编译选项增强。

- 服务卡片使用位置权限策略优化。


### 电话服务

- 支持获取国际移动设备软件识别版本（IMEISV）和驻留基站的PLMN编码。

- 电话服务进程负载及DFX优化，包括独立编译部署、可定位性提升、稳定性提升。


### 网络管理

**网络管理能力**

- 支持通过创建NetConnection对象连接目标指定Wi-Fi热点。

- 提供网络管理状态监听、应用级代理监听等能力的基于NDK的C API。

- 网络管理进程负载及DFX优化，包括独立编译部署、使能FFRT降低线程数、降低内存开销、提升可定位性，同时提升了异常崩溃后自动恢复的能力。

**网络协议栈能力**

- 支持将TCP Socket升级成TLS Socket，提升通信安全性。

- TLS Socket支持跳过证书校验，避免特殊情况下无法校验证书的场景。

- 所有Socket均支持获取本地IP与端口。

- HTTP支持配置证书锁定信息。

- HTTP支持brotli压缩算法。

- HTTP协议栈支持自动读取系统和用户安装的证书。

- HTTP代理支持安全存储用户名和密码、自动更新代理认证凭据，还支持在使用预览器时自动读取代理配置。

- WebSocket支持获取Header信息、设置代理等能力，同时降低了WebSocket的功耗开销。

- TLSSocket支持发送ArrayBuffer数据类型，支持使用系统默认证书。


### 电源

- 支持获取当前充电电流，三方应用可以通过nowCurrent获取当前设备电流。

- 支持飞行模式的温度管控动作，开发者可定制温控策略控制设备进入飞行模式。

- 支持根据WorkSource代理运行锁辅助资源调度模块进行功耗控制。

- 支持低电量时从S3睡眠状态唤醒后自动进入S4休眠，实现超长待机特性。

- 支持系统启动后读取并广播设备壳/套的在位信息，电池信息内核节点和是否发广播等支持开发者配置。

- 支持DIM显示状态，超时进入DIM状态后再灭屏，提升灭屏用户体验。

- 支持预亮屏能力，屏幕上电但是不显示。

- 支持设置超时灭屏时间。

- 支持温度模拟调试功能。

- 提供休眠相关的ArkTS、C API接口。

- 电源服务独立为powermgr进程。


### USB

- USB DEVICE配置管理安全访问控制增强。

- USB标准数据传输模式(中断传输、Bulk传输)功能增强。

- 支持标准类型USB外设安全管控。

- 支持获取USB设备传输速度、USB接口激活状态信息。

- 建立USB有线外围接口连接确认机制。

- 支持USB默认端口预设置。

- 支持多用户并发场景。

- 增强DFX能力，优化USB服务异常重启机制。

- 增强应用访问安全防御能力。


### 启动恢复

- 支持Native软件包打包、安装、运行和卸载，搭建Native软件包开发和发布系统，有助于生产力软件生态能力的快速构建，也有助于系统开发者提升开发效率。

- 提供可重置的开发者匿名设备标识符ODID，代替UDID以及其他的硬件标识符。

- 支持运行bftpd命令，支持user模式下调试应用沙箱数据访问。

- 支持查询ODID信息，应用可以获取到真实的ODID信息。

- 扩展维护命令，支持查看各个服务进程运行状态、looper中的fd状态以及定时器信息。

- appspawn支持运行bftpd命令，提供指定应用沙箱内目录访问及读写能力。

- 应用孵化时支持限制应用可fork进程数。

- 应用孵化时支持为应用进程设置env信息。

- 应用孵化时支持元服务随账号隔离沙盒数据。

- foundation进程异常重启后，init可以重新投票，确保可以重新发起BOOTCOMPLETE事件。


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

- 加解密算法库框架支持HKDF密钥派生算法，提供RSA私钥加密、公钥解密的算法能力，提供算法库相关JS同步调用接口。

**证书管理**

- 提供拉起证书管理界面的API。

- 提供获取应用私有证书列表的API。

- 证书算法库提供系统业务证书凭据管理界面及服务接口。

**程序访问控制**

- 访问控制：
  - 地理位置权限支持单次授权选项。
  - 支持拉起设置页面的权限管理应用界面。

- DLP：
  - 支持查询当前系统是否提供DLP特性。
  - 支持DLP文件管控打印功能。
  - 支持对批量用户的复制粘贴授权。

- SELinux：
  - 支持递归打标签时忽略指定目录的能力。
  - 增加SELinux策略管控规则：新增ioctl权限需使用allowxperm进行精细化管控。

- 代码签名：
  - 签名工具支持开发态的HQF包签名。
  - 签名工具支持应用包内libs下非so后缀elf文件代码签名。
  - 签名工具支持应用包内Native包（.hnp）代码签名。

**用户IAM**

- 支持口令有效期检查。

- 支持恢复密钥。

- 用户身份认证支持跨设备口令认证。

- 支持人脸和指纹嵌入式身份认证控件。

- 支持对注册口令的复杂度进行检查。

- 支持跨用户的凭据信息录入、查询和认证。

- 支持设置和检查口令有效期。

- DFX能力增强，支持调用者（应用）切换到后台或结束生命周期后，自动取消认证。

**账号**

- 支持注销本地账号。

- 支持创建本地账号时，指定账号短名称（用作个人文件夹名称）。

- 支持查询本地账号名称。

- 新增隐私账号类型。

- 新增解锁认证意图。

- 新增图形、四位PIN凭据类型。

- 支持多帐号并发运行（一个前台运行的帐号，多个后台运行的帐号）。

- 支持配置可同时登录的系统帐号数量。

- 支持创建隐私类型帐号。

- 提供跨帐号的凭据添加和认证接口。

- 提供跨设备的凭据认证接口。

- 支持南向扩展域帐号认证协议。

- 支持配置域服务器信息。


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

**前端编译工具链**

- 前端提供方舟字节码文件格式和指令集规格文档。

- 前端支持加载配置在DevEco Studio的编译器插件。

- 前端编译器支持本函数内常量/变量以及跨文件常量时的无用分支消除。

- 前端编译工具效率优化，缩短编译时间。

- 前端支持闭源HAR包异常回栈和debug调试。

- TypeScript Compiler的target选项配置由ES2017切换至ES2021。

**代码混淆**

- 时间性能优化、内存优化。

- 支持对HAP包文件名进行混淆。

- 支持配置部分文件不混淆。

- 支持使用通配符配置不混淆白名单。

- 支持nameCache文件保留行列号，以支撑DevEco Studio堆栈解析。

**并发能力增强**

- 支持Sendable共享内存的数据类型，包括Sendable类、Sendable容器（Array、Map、Set、Int8Array、Int16Array、Int32Array、Uint8Array、Uint16Array、Uint32Array）、JSON解析成Sendable对象、异步锁功能。

- Worker数量放宽到64个，进程总JS内存上限为1.5GB。

- TaskPool支持任务监控的能力，可以监听任务分发、开始执行、执行成功、执行失败的事件。

- TaskPool提供接口判断一个函数是不是Concurrent函数。

- TaskPool支持长时任务，可以长时间执行。

- TaskPool支持串行队列功能，可以保证任务执行顺序。

- TaskPool支持延时执行任务。

- TaskPool支持统计执行的耗时信息，包括CPU耗时及I/O耗时。

**模块化能力增强**

支持同版本HAR包的运行时的单例，即被HAP/HSP同时依赖时，运行时只加载一份。

**维测能力**

- 支持时光调试。

- 支持hiperf/profiler混合回栈。

- 调试功能支持CallFunctionOn协议。

- 多实例HeapDump。

- 支持ApplyChange快速冷启动。

- 调试功能支持选择函数的smart step into功能。

**LLVM/Rust编译器：**

- 应用支持tsan功能选项。

- Rust社区支持编译鸿蒙平台target。

**LLDB调试器：**

支持解析minidebug。

**Linter：**

在DevEco Studio新支持14条ArkTS规则自动修复功能。

**Musl C库：**

- C基础库locale支持zh_CN或zh_CN.UTF-8。

- 支持fdsan能力，开放fdsan相关接口。

- 开放C库接口fopencookie到NDK中。

**标准JS引擎：**

- 支持在编译JS脚本时传递sourcemap文件地址信息，在出现异常时提供经sourcemap转换的源信息。

- 支持JS对象判断是否属于JS基础类型。

- 支持JS宽松相等（“==”操作）。

- 支持创建字符串引用，可持久化使用字符串。


### 综合传感处理平台

**拖拽框架**

- 支持随着窗口旋转，旋转拖拽窗口。

- 支持应用自定义配置拖拽过程中不显示数量角标。

- 支持数据接收方自定义剪切与复制行为。

- 提供了更为精致的拖拽动效视觉体验，支持透明度、投影、圆角等效果。

- 支持多对象拖拽及拖拽加选能力，丰富了拖拽体验。

- 支持自定义拖拽行为，根据快捷键决定当前拖拽行为为剪切/复制。

- 采用轻量化日志打印，提升了DFX能力。

**键鼠穿越**

- 管控双端同时发起activate接口调用。

- 键鼠穿越时序问题优化，减少系统依赖，消除多进程间时序问题。

- 提高穿越管理性能，提高成功率，降低穿越时延。

- 优化了业务架构，提升了稳定性、可靠性和性能体验。

- 提供了性能打点工具，提升了DFX能力。


### 多模输入

- 提供C API支持设备信息查询等相关能力。

- 支持上报从底部上滑亮屏解锁按键事件。

- 支持异形窗口事件上报，异形窗口透明区域透传鼠标事件，非透明区域不透传鼠标事件。

- 支持指关节事件相关功能包括：指关节轨迹绘制，指关节轨迹动效，指关节画圈拉起截屏，指关节画S拉起长截屏，双指指关节双击触发录屏等操作。

- 提供智灵键功能，对现有指纹键能力进行增强。

- 支持红外能力，给调用方设备支持的外频率数据。

- 提供鼠标及触控板适配窗口旋转能力，在事件分发模块中根据窗口同步的窗口旋转信息，进行鼠标坐标旋转，将旋转后的坐标分发到正确的窗口。

- 提供组合键拉起系统应用能力，支持灭屏场景组合键不拉起截屏应用；锁屏状态下组合键由短按变为长按拉起截屏应用，防止误触；支持同一按键的长按和短按拉起不同应用；支持通过接口屏蔽组合键的能力。

- 支持手写笔息屏双击拉起速记，灭屏场景，手写笔在屏幕上双击，识别是手写笔双击。

- 适配触控板显控比曲线模型，多模输入数据预处理模块按照人因分析提供的触控板显控比曲线模型对接受到的触控板单点触控数据进行加工处理。

- 支持手写笔连续摘录功能，用户使用手写笔进行输入操作，使用触摸屏进行触摸操作；批注窗口响应手写笔输入，底部应用窗口响应用户触摸屏的操作。

- 支持显示指针位置信息，支持动态开关，打开开关，显示触控Pointer数量，触控位置，移动速度等信息。

- 支持电源键和音量键事件监听，通话应用接受到音量键或者电源键，触发来电铃声静音。

- 提供了性能打点工具，关键业务关键流水日志，demonID区分业务日志，补齐/新增故障打点，确保本领域所有故障都有对应的事件打点，提升了DFX能力。

- 新增KeyCode，支持屏幕朗读自定义公共事件能力。


### 泛Sensor

**vibrator**

- 部分异步查询接口提供同步版本API。

- 系统可以根据不同的器件能力等级更好的使用马达器件触发振感。

- 新增预置一组简单通用的振动效果HapticFeedback，在支持振动强度等级调节的设备上还可对其进行强度调节下发。

- 新增查询类接口、振动停止的同步调用形式。

**sensor**

- 部分异步查询接口提供同步版本API。

- 提供C API支持线性加速度、游戏旋转向量传感器。

- 传感器查询类接口增加同步调用形式。

- sensor新增错误码14500102，表示查询的sensor类型在设备上不被支持。

- 环境光上报数据扩展红外及色温参数。


### 无障碍服务

- 放大手势，支持通过手势对屏幕内容进行放大显示操作。

- 主动播报能力，应用适配屏幕朗读时，在一些动态变化的场景下，可支持通过无障碍进行变化信息的主动播报。

- 主动聚焦能力，应用适配屏幕朗读时，在某些场景下，可对组件请求主动聚焦。

- 颜色反转能力，将显示颜色进行反转处理，满足部分视力障碍人群的使用场景。

- 高对比度文字，增强文字显示的对比度。

- 单声道音频，将左右声道音量进行合并输出，满足部分听力障碍人群的使用场景。

- 音量平衡能力，可调节左右耳的输出音量平衡度，满足部分听力障碍人群的使用场景。

- 屏幕触控能力，支持点击持续时间、忽略重复点击。

- 触摸浏览模式，视力障碍人群采用触摸浏览的交互方式进行智能设备屏幕的操控。

- 为屏幕朗读提供多指交互手势的识别能力，借助多指交互手势，可提升视力障碍人群在读屏状态下的交互体验。


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

**后台代理提醒**

- 新增查询接口，支持获取reminderId。

- WantAgent支持携带parameters参数。

- 重复类型的日历提醒，支持添加ExcludeDate来指定不提醒日期。

- 日历提醒（ReminderRequestCalendar）支持设置提醒的结束时间。


### 测试框架

- 支持跨平台接口的兼容性测试。

- UItest测试框架DFX能力增强与效率提升优化。

- Smartperf host支持微观指标分析。

- Smartpef device支持卡顿trace、进程级内存、CPU、网络信息采集。

- Wukong稳定性测试工具支持用户压测设置与内存信息采集。


### DFX

- 提供判断HDC调试器是否连接的API。

- 支持在开发者模式打开trace功能。

- 开放主线程超时事件的感知。

- errorManager支持TaskPool和Worker监听未处理的Reject事件。

- 提供FFRT协程和分布式场景下的HiTrace调优能力。

- Hiprofiler内存分析支持JS-native混合栈。

- PerformanceAnalysisKit质量数据、性能功耗数据面向生态开放。

- CppCrash支持异步跟踪能力。

- 支持hdc调试应用数据沙箱内文件访问的能力。

- 应用支持TSAN检测能力。


### 内核

- 提供基于用户交互关系的线程QoS等级标注和调度。
- 提供C API接口支持基于用户交互的QoS调度。


### 上传下载

- request.agent.Fault 细化了错误类型，便于开发者快速定位接口使用问题。

- request.agent.Config 新增 proxy 成员，支持设置任务的网络代理地址。

- request.agent.Task.start 支持重新启动已经失败\停止的任务，便于开发者快速恢复失败任务。

- request.agent.Task 支持使用 network.json 配置文件配置 TLS 证书锁定指纹。

- request.agent.FileSpec 支持指定应用沙箱 base 目录下的所有文件路径，便于开发者管理沙箱文件；同时支持前台上传公共文件，例如图库文件、相册文件等，减少额外拷贝带来的开销。

- 后台任务通知栏效果优化。

- 上传/下载任务的目录支持指定到base目录内的任意位置。

- 下载任务失败后可以选择重新开始，任务从中断的位置继续传输。

- 支持监听上传/下载任务的响应。

- 在上传下载时支持证书锁定功能。

- 前端模式的上传/下载任务可以指定到用户文件（需要提前获得读写权限）。

- 优化任务数量，可以同时存在更多的未完成的任务。


### 输入法框架

- 基于NDK的C API新增支持自绘UI组件使用输入法，包括拉起、退出输入法，处理文字上屏请求等操作。

- 优化拉起键盘时回调时序，输入法应用可根据输入框属性及时调整键盘显示内容。

- 支持输入法的基础模式/完整体验模式。

- 支持自动大小写模式。

- 支持预上屏功能。

- 优化屏幕旋转时输入法面板的旋转体验。

- 支持新的统一的输入法面板。


### 时间时区

- 提供NTP时间强制刷新和获取当前NTP时间的系统API。

- 基于NDK的C API提供获取时区的能力。

- 废弃了异步获取系统时间的接口，以同步接口（getTime、getUptime）替代原来的功能。


### 剪贴板

- 基于NDK的C API支持剪贴板的能力。

- 提供跨设备剪贴板开关。

- 在应用升级到API 12及以后，对读取剪贴板接口增加读权限校验。

- 剪贴板的读取接口增加权限管控，使用剪贴板安全控件时不需要额外申请权限，可以直接去读剪贴板数据；使用自定义控件时，需要用户授权，权限申请通过后才能读取剪贴板数据。

- 剪贴板接入UMDF标准数据类型，支持更多标准数据类型放入剪贴板。


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

- W3C支持自定义光标样式。

- W3C支持datalist元素。

- Web内核支持识别HEIF图片。

- 提供离线资源的免拦截注入。

- 支持应用自定义DNS。

- 支持UniversalLink。

- 支持异步jsbridge。

- 支持expandSafeArea。

- 支持避让区查询能力。

- 支持JS线程ANR感知能力。

- 支持网页input元素文件上传。

- 支持自定义文本选择菜单。

- 网络接管支持获取被拦截请求的ResourceType，支持获取请求的FrameUrl。


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
| 全量代码（标准、轻量和小型系统）        | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/code-v5.0.0-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/code-v5.0.0-Release.tar.gz.sha256) | 41.8 GB |
| Hi3861解决方案（二进制）        | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_pegasus.tar.gz.sha256) | 27.1 MB |
| Hi3516解决方案-LiteOS（二进制） | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.3 MB |
| Hi3516解决方案-Linux（二进制）  | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 220.4 MB |
| RK3568标准系统解决方案（二进制）        | 5.0.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/dayu200_standard_arm32_20240929.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/dayu200_standard_arm32_20240929.tar.gz.sha256) | 11.7 GB |
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
