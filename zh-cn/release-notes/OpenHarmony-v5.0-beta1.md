# OpenHarmony 5.0 Beta1


## 版本概述

OpenHarmony 5.0 Beta1版本标准系统能力持续完善，ArkUI完善了组件通过C API调用的能力；应用框架细化了生命周期管理能力，完善了应用拉起、跳转的能力；分布式软总线连接能力和规格进一步增强；媒体完善了框架能力、视频编解码能力、音视频的应用能力，媒体库丰富了使用场景，提供更好的使用体验。

OpenHarmony 5.0 Beta1版本开始提供首批API Level 12接口。


### 应用框架

- 新增AppStartUp应用并行化启动框架，提供一种在应用启动时初始化组件的简单而高效的方法，有效提升启动性能。

- 新增原子化服务启动API，提供跳出式和嵌入式两种启动方式。

- 自动填充能力增强：开发者在使用TextInput组件时支持更多类型数据的自动保存和自动填充能力。

- 卡片能力增强：提供单色模式、反色能力、渐变撞色、卡片视觉呈现精致（模糊、投影、圆角等）、展示背景自然融合，高端精致。

- aa工具支持隐式启动应用.

- 统一DeepLink和AppLinking跳转技术方案，降低开发者使用成本，提高跳转安全性。

- 提供安全的应用重启应用能力。

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

- 针对三方框架场景提供组件NDK接口，涵盖组件创建、属性设置、事件注册、自定义能力、组件树构建。

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

- 业务模块（HSP/HAR）支持配置router_map.json路由表，实现模块间动态路由解耦。

- 支持集成态HSP，集团内部的多个应用之间，可以使用集成态HSP实现代码和资源共享。

- 支持卸载更新的能力，通过应用市场更新的预置应用，可以通过卸载更新恢复到系统预设的版本。

- 提供In-House应用的安装及查询能力，支持In-House应用管理。

- 统一资源缓存，支持overlay和主题切换场景。

- 支持gzip格式文件解压缩能力。

- 支持resfile目录，resfile目录开发者可以自由放置各类资源文件，应用安装时，资源会被解压到应用沙箱路径。


### 分布式软总线

- BR/BLE连接新增传输优先级控制，提升BLE发现广播成功率。

- 支持BR/BLE链路复用能力，同时确保复用流程不被业务打断，提升复用成功率。

- 组网支持多介质组网归一，避免重复认证，提升认证效率。

- 支持逻辑通道与物理链路解耦，增加连接成功率。

- 传输模块提供加解密接口，并支持Bind接口中途取消、超时可配置等能力。

- IPC支持异步消息发送方信息、并提供高性能读写共享内存的JS北向接口能力。

- IPC_Core和IPC_Single公共部分解耦，持续优化内存使用。


### 分布式数据管理

- Preferences支持可序列化为JSON的Object类型，及基于key的精准订阅。

- relational_store支持TS同步接口。

- UDMF支持批量事务，新增4种常用数据结构标准化定义，40种UTD数据类型。

- data_share 在资源占用、访问控制、访问精度等方面进行了优化。


### 分布式硬件

- 支持管理可信和非可信设备资源，对应用提供设备信息的查询、筛选、排序和监听等功能。

- 提供PIN码、碰、扫、靠等设备认证框架，支持对接各种认证交互入口。

- 为设备资源管理提供设备组网 、上下线、扫描周边设备的能力。


### 分布式DeviceProfile

- 支持为系统服务提供跨设备可信关系、可信设备信息、设备系统信息、服务信息和服务特征信息的增删改查和订阅数据变化通知的服务。

- 支持跨设备数据端端按需同步和蓝牙心跳广播同步，支持数据按照开关类、静态类和动态类数据进行分级，供业务方根据自身数据特点定义、操作不同类型数据。


### 文件管理

- 支持文件增量备份，支撑云空间增量的特性。

- 提供备份应用获取备份数据量详情接口，打通备份应用与待备份应用间的感知通路，支持备份恢复过程中的异常事件上报。

- 新增支持SA接入备份恢复框架。

- 增强picker能力，提供audio picker一次多选的能力，新增download picker，补齐浏览器下载体验。


### 图形图像及窗口

**图形图像**

- Drawing能力增强，支持矢量图元绘制、位图绘制及样式视效等，支持对文本绘制施加阴影效果。

- 位图ArkTS和C API能力增强，支持转换格式、透明度预乘、效果处理等接口。

- 文本引擎NDK能力增强，支持设置行间距、多种换行策略等。

- surfaceNDK能力增强，支持获取YUV数据的位置、获取surfaceid、Attach和Detach和获取BufferQueueSize的C API。

- 提供LTPO控帧能力。

- 3D组件能力增强，支持加载编辑控制3D场景。

- 提供OpenGL ES扩展接口。

- 性能能效进一步优化。

**窗口**

- 支持应用获取状态栏的颜色属性。

- 跨平台能力增强，loadContentByName、windowSizeChange等接口适配跨平台能力。


### 媒体

**播放器（AVPlayer）**

- 支持在播放时选择更多的倍速（0.5/1.5倍速）。

- 支持更多格式的播放能力（如AMR）。

- 提供更多的音频编码参数供用户进行呈现（如位深）。

- 提供低功耗的音频播放能力（Offload）供用户选择。

- 支持精准SEEK能力。

- 视频播放过程中，用户可以将视频切换到其他窗口。

- 提供自定义Header能力，便于用户在流媒体播放时添加自定义信息。

- 支持FLV网络直播能力。

- 网络播放下，根据网络质量自动切换到适合的码率下播放。

**录像（AVRecorder）**

- 支持动态配置画面旋转参数。

- 支持视频录制分层编码功能。

**媒体元数据（AVMetadata）**

提供HDR Vivid视频的识别能力。

**录屏服务（AVScreenCapture）**

- 支持使用C API录制系统屏幕和声音。

- 支持使用Surface模式获取录屏数据。

- 支持配置录屏内容跟随屏幕旋转。

- 录屏不与蜂窝通话并发。

- 支持麦克风和系统音同时录制。

- 录屏提供隐私弹窗，由用户授权启动录屏。

- 录屏支持排除指定windowID的窗口画面。

- 录屏支持排除应用自身音频。

**数字版权保护服务（DRM）**

- 支持DRM插件管理和DRM解决方案的集成。

- 支持DRM证书下载。

- 支持DRM节目在线及离线授权。

- 支持DRM节目解密，支持安全、非安解密。

- 支持安全视频通路；

- 支持HLS+TS/DASH+fMP4协议DRM节目授权及解密播放。

- 支持AVPlayer及AVCodec播放框架集成。

**音视频编解码(AVCodec)**

- 支持ape解码和解封装。

- 支持mp3编码和封装。

- 支持SRT格式字幕解析。

- H.264/H.265硬件编码支持随帧设置长期参考帧，参考帧编码，依赖硬件芯片能力。

- H.264/H.265硬件编码支持随帧设置编码QP，依赖硬件芯片能力。

- H.264/H.265硬件编解码支持低时延出帧（one-in-one-out），依赖硬件芯片能力。

- H.264/H.265硬件编码支持重置码率和帧率，依赖硬件芯片能力。

- H.264/H.265硬件编码支持分级P分层编码，依赖硬件芯片能力。

- 支持fmp4文件解析。

- surface模式下，硬件解码支持surface切换 。

**相机**

- 相机模式增强，新增专业、超级微距、超级慢动作、安全等模式。

- 相机拍照增强，支持动态照片、HDR Vivid拍摄，开放分段式拍照。

- 相机效果增强，支持黑白色彩、人像虚化等效果。

- 相机控制增强，支持动态配置帧率，支持动效焦距、环境亮度等信息返回。

**音频**

- 音频内录功能支持按流类型、应用过滤。

- 音频低功耗播放支持变速、音效处理。

- 有线耳机和蓝牙耳机支持音频高清播放。

- 空间音频支持外放空间音频渲染。

- VOIP语音通话支持低时延通路。

- 系统音管理新增支持获取系统音列表和自定义系统音。

**图片**

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

- HTTP协议栈支持自动读取系统和用户安装的证书。

- HTTP代理支持安全存储用户名和密码、自动更新代理认证凭据，还支持在使用预览器时自动读取代理配置。

- WebSocket支持获取Header信息、设置代理等能力，同时降低了WebSocket的功耗开销。

- TLSSocket支持发送ArrayBuffer数据类型，支持使用系统默认证书。

- 网络管理进程负载及DFX优化，包括独立编译部署、使能FFRT降低线程数、降低内存开销、提升可定位性，同时提升了异常崩溃后自动恢复的能力。


### 电源

- 支持DIM显示状态，超时进入DIM状态后再灭屏，提升灭屏用户体验。

- 支持预亮屏能力，屏幕上电但是不显示。

- 支持设置超时灭屏时间。

- 支持温度模拟调试功能。

- 提供休眠相关的ArkTS、C API接口。

- 电源服务独立为powermgr进程。


### USB

- 支持获取USB设备传输速度、USB接口激活状态信息。

- 建立USB有线外围接口连接确认机制。

- 支持USB默认端口预设置。

- 支持多用户并发场景。

- 增强DFX能力，优化USB服务异常重启机制。

- 增强应用访问安全防御能力。


### 启动恢复

- 支持查询ODID信息，应用可以获取到真实的ODID信息。

- 扩展维护命令，支持查看各个服务进程运行状态、looper中的fd状态以及定时器信息。

- appspawn支持运行bftpd命令，提供指定应用沙箱内目录访问及读写能力。

- 应用孵化时支持限制应用可fork进程数。

- 应用孵化时支持为应用进程设置env信息。

- 应用孵化时支持元服务随账号隔离沙盒数据。

- foundation进程异常重启后，init可以重新投票，确保可以重新发起BOOTCOMPLETE事件。


### 全球化

- 提供C API支持icu4c开放为国际化能力。

- 国际化格式化处理支持屏幕大小自适应。

- 全面支持伪本地化测试。

- 提供C API支持资源文件管理能力。

- 字符串资源支持可翻译性的标记。

- 提供小语种字库能力。


### 安全

- 加解密算法库框架支持HKDF密钥派生算法，提供RSA私钥加密、公钥解密的算法能力，提供算法库相关JS同步调用接口。

- 证书算法库提供系统业务证书凭据管理界面及服务接口。


### 程序访问控制

**访问控制**

支持权限管理的设置界面展示一键开关，用于管控该权限能否通过动态弹窗进行申请

**DLP**

- 支持查询当前系统是否提供DLP特性。

- 支持DLP文件管控打印功能。

- 支持对批量用户的复制粘贴授权。

**SElinux**

- 支持递归打标签时忽略指定目录的能力。

- 增加SELinux策略管控规则：新增ioctl权限需使用allowxperm进行精细化管控。

**代码签名**

- 签名工具支持开发态的HQF包签名。

- 签名工具支持应用包内libs下非so后缀elf文件代码签名。

- 签名工具支持应用包内Native包（.hnp）代码签名。


### 用户IAM

- 用户身份认证支持跨设备口令认证。

- 支持人脸和指纹嵌入式身份认证控件。

- 支持对注册口令的复杂度进行检查。

- 支持跨用户的凭据信息录入、查询和认证。

- 支持设置和检查口令有效期。

- DFX能力增强，支持调用者（应用）切换到后台或结束生命周期后，自动取消认证。


### 帐号

- 支持多帐号并发运行（一个前台运行的帐号，多个后台运行的帐号）。

- 支持配置可同时登录的系统帐号数量。

- 支持创建隐私类型帐号。

- 提供跨帐号的凭据添加和认证接口。

- 提供跨设备的凭据认证接口。

- 支持南向扩展域帐号认证协议。

- 支持配置域服务器信息。


### ArkCompiler

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

- 提供了更为精致的拖拽动效视觉体验，支持透明度、投影、圆角等效果。

- 支持多对象拖拽及拖拽加选能力，丰富了拖拽体验。

- 支持自定义拖拽行为，根据快捷键决定当前拖拽行为为剪切/复制。

- 采用轻量化日志打印，提升了DFX能力。

**键鼠穿越**

- 优化了业务架构，提升了稳定性、可靠性和性能体验。

- 提供了性能打点工具，提升了DFX能力。


### 多模输入

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

- 新增预置一组简单通用的振动效果HapticFeedback，在支持振动强度等级调节的设备上还可对其进行强度调节下发。

- 新增查询类接口、振动停止的同步调用形式。

**sensor**

- 传感器查询类接口增加同步调用形式。

- sensor新增错误码14500102，表示查询的sensor类型在设备上不被支持。

- 环境光上报数据扩展红外及色温参数。


### 无障碍服务

- 颜色反转能力，将显示颜色进行反转处理，满足部分视力障碍人群的使用场景。

- 高对比度文字，增强文字显示的对比度。

- 单声道音频，将左右声道音量进行合并输出，满足部分听力障碍人群的使用场景。

- 音量平衡能力，可调节左右耳的输出音量平衡度，满足部分听力障碍人群的使用场景。

- 屏幕触控能力，支持点击持续时间、忽略重复点击。

- 触摸浏览模式，视力障碍人群采用触摸浏览的交互方式进行智能设备屏幕的操控。

- 为屏幕朗读提供多指交互手势的识别能力，借助多指交互手势，可提升视力障碍人群在读屏状态下的交互体验。

- 主动播报能力，应用适配屏幕朗读时，在一些动态变化的场景下，可支持通过无障碍进行变化信息的主动播报。

- 主动聚焦能力，应用适配屏幕朗读时，在某些场景下，可对组件请求主动聚焦。


### 资源调度

后台代理提醒：

- 新增查询接口，支持获取reminderId。

- WantAgent支持携带parameters参数。

- 重复类型的日历提醒，支持添加ExcludeDate来指定不提醒日期。

- 日历提醒（ReminderRequestCalendar）支持设置提醒的结束时间。


### 测试框架

- UItest测试框架DFX能力增强与效率提升优化。

- Smartperf host支持微观指标分析。

- Smartpef device支持卡顿trace、进程级内存、CPU、网络信息采集。

- Wukong稳定性测试工具支持用户压测设置与内存信息采集。


### DFX

- 提供FFRT协程和分布式场景下的HiTrace调优能力。

- Hiprofiler内存分析支持JS-native混合栈。

- PerformanceAnalysisKit质量数据、性能功耗数据面向生态开放。

- CppCrash支持异步跟踪能力。

- 支持hdc调试应用数据沙箱内文件访问的能力。

- 应用支持TSAN检测能力。


### 内核

提供C API接口支持基于用户交互的QoS调度。


### 上传下载

- 后台任务通知栏效果优化。

- 上传/下载任务的目录支持指定到base目录内的任意位置。

- 下载任务失败后可以选择重新开始，任务从中断的位置继续传输。

- 支持监听上传/下载任务的响应。

- 在上传下载时支持证书锁定功能。

- 前端模式的上传/下载任务可以指定到用户文件（需要提前获得读写权限）。

- 优化任务数量，可以同时存在更多的未完成的任务。


### 输入法框架

- 支持输入法的基础模式/完整体验模式。

- 支持自动大小写模式。

- 支持预上屏功能。

- 优化屏幕旋转时输入法面板的旋转体验。

- 支持新的统一的输入法面板。


### 时间时区

废弃了异步获取系统时间的接口，以同步接口（getTime、getUptime）替代原来的功能。


### 剪贴板

- 剪贴板的读取接口增加权限管控，使用剪贴板安全控件时不需要额外申请权限，可以直接去读剪贴板数据；使用自定义控件时，需要用户授权，权限申请通过后才能读取剪贴板数据。

- 剪贴板接入UMDF标准数据类型，支持更多标准数据类型放入剪贴板。


### Web

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


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 5.0 Beta1 | NA |
| Public SDK | Ohos_sdk_public 5.0.0.25 (API Version 12 Beta1) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。 |
| HUAWEI DevEco Studio（可选） | 5.0 Beta1 | OpenHarmony应用开发推荐使用。获取方式：<br />[点击跳转至下载页面](https://developer.huawei.com/consumer/cn/download/) |
| HUAWEI DevEco Device Tool（可选） | 4.0 Release | OpenHarmony智能设备集成开发环境推荐使用。获取方式：<br />[点击跳转至下载页面](https://device.harmonyos.com/cn/develop/ide#download) |


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 5.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/code-v5.0-Beta1.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/code-v5.0-Beta1.tar.gz.sha256) | 40.2 GB |
| Hi3861解决方案（二进制）        | 5.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/hispark_pegasus.tar.gz.sha256) | 29.8 MB |
| Hi3516解决方案-LiteOS（二进制） | 5.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/hispark_taurus_LiteOS.tar.gz.sha256) | 326.6 MB |
| Hi3516解决方案-Linux（二进制）  | 5.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/hispark_taurus_Linux.tar.gz.sha256) | 215.5 MB |
| RK3568标准系统解决方案（二进制）        | 5.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/dayu200_standard_arm32.tar.gz.sha256) | 10.1 GB |
| 标准系统Public SDK包（Mac）             | 5.0.0.25      | [站点](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/ohos-sdk-mac-public.tar.gz.sha256) | 	1.2 GB |
| 标准系统Public SDK包（Mac-M1）             | 5.0.0.25     | [站点](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.1 GB |
| 标准系统Public SDK包（Windows/Linux）   | 5.0.0.25      | [站点](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0-Beta1/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.4 GB |

## 更新说明

本版本在OpenHarmony 4.1 Release的基础上有如下变更。

### 特性变更

详见版本概述部分的特性变更说明。

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| -------- | -------- |
| I8WP8M | 移动桌面一个图标使之与另一图标重叠创建大文件夹，之后选中文件夹内的一个应用移出文件夹，重复此操作，launcher出现内存泄露，操作五分钟，内存泄漏约25M，操作一次泄露约673.68KB。 | 
| I9A9NO | 不停执行点击短信界面右上角新建短信和返回操作，5分钟短信应用内存上涨约50M，操作一次泄露约341.33KB。 | 
| I8TM99 | 小概率在进程softbus_server下的softbus_server线程出现cppcrash，崩溃栈：libbtframework.z.so。 | 
| I90A2N | 一定概率下，进程com.ohos.systemui由于THREAD_BLOCK_6S卡在libeventhandler.z.so出现appfreeze。 | 
| I9A089 | 中等概率下进程foundation由于SERVICE_BLOCK出现sysfreeze。 | 
| I9CGOZ | 有较高概率，进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze。 | 
| I8QH9S | 小概率在进程com.ohos.settingsdata下的os.settingsdata线程出现cppcrash，崩溃栈：libnative_appdatafwk.z.so。 | 
| I963TL | 小概率因进程com.ohos.mms下的com.ohos.mms线程导致libark_jsruntime.so出现cppcrash。 | 
| I97U6G | 小概率下进程com.ohos.certmanager由于THREAD_BLOCK_6S卡在librender_service_client.z.so出现appfreeze。 | 
| I98KIG | 小概率下进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze。 | 
| I96CJL | 轻量级设备之间组网失败。 | 


## 遗留缺陷列表

**表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| IA686U | 进程com.ohos.photos下的OS_FFRT_2_0线程有较高概率导致libace_napi.z.so出现cppcrash。 | 相册应用概率性闪退。<br/>规避措施：重启相册应用。 | 6月30日 | 
| I9YC9X | 进程com.ohos.camera有较高概率由于LIFECYCLE_TIMEOUT卡在libark_jsruntime.so出现sysfreeze。 | 相机应用概率性闪退。<br/>规避措施：在操作相机应用的时候避免反复切换前后台操作。 | 6月30日 | 
| I9TE52 | 进程com.ohos.photos有一定概率由于THREAD_BLOCK_6S卡在libark_jsruntime.so出现appfreeze。 | 图库应用卡住3秒以上。<br/>规避措施：重启图库应用。 | 6月30日 | 
| I9TDUU | 关键应用: ohos.samples.distributedcalc小概率由于THREAD_BLOCK_6S卡在libace_compatible.z.so出现appfrreze问题。 | 使用计算器可能卡住并闪退 。<br/>规避措施：重启计算器应用。 | 7月15日 | 
| I9S5ZN | 关键应用: com.ohos.settings极小概率由于THREAD_BLOCK_6S卡在libunwind.z.so出现appfrreze问题。 | 设置页面卡顿。<br/>规避措施：重启设置应用。 | 6月30日 | 
| I9TE5K | 进程com.ohos.photos小概率由于THREAD_BLOCK_6S卡在libunwind.z.so出现appfreeze。 | 图库应用卡住3秒以上。<br/>规避措施：重启图库应用。 | 6月30日 | 
| I9TJGB | 进程com.ohos.camera下的RSRenderThread进程有小概率导致libmali-bifrost-g52-g7p0-ohos.so出现cppcrash。 | 相册应用概率性闪退。<br/>规避措施：重启相册应用。 | 6月30日 | 
| IA5EC3 | 进程com.ohos.updateapp小概率由于THREAD_BLOCK_6S卡在libskia_canvaskit.z.so出现appfreeze。 | 升级页面可能会卡顿。<br/>规避措施： 重新进入软件更新。 | 7月15日 | 
| IA5I3D | 进程com.ohos.smartperf小概率由于THREAD_BLOCK_6S卡在librender_service_base.z.so出现appfreeze。 | 对用户无影响，开发者用户使用该app测试应用时，点击悬浮球开始测试后如果测试时间过久可能在保存时出现闪退。<br/>​规避措施​：可终止后台进程后重新进入该app。 | 6月30日 | 
| IA4G47 | 进程av_codec_service下的av_codec_service线程极小概率出现cppcrash，崩溃栈：libhcodec.z.so。 | Wukong测试工具随机压测出现crash，用户无影响。 | 6月30日 | 
| I9SXZ8 | 进程com.ohos.contacts小概率由于THREAD_BLOCK_6S卡在libark_jsruntime.so出现appfreeze。 | 联系人应用进入通话记录查询通话记录时卡顿。<br/>规避措施：重启联系人应用。 | 6月30日 | 
| I9TDMQ | 关键应用: com.ohos.settings极小概率由于THREAD_BLOCK_6S卡在libskia_canvaskit.z.so出现appfrreze问题。 | 设置页面卡顿。<br/>规避措施：重启设置应用。 | 6月30日 | 
| I9S5ZN | 关键应用: com.ohos.settings极小概率由于THREAD_BLOCK_6S卡在libunwind.z.so出现appfrreze问题。 | 设置页面卡顿。<br/>规避措施：重启设置应用。 | 7月30日 | 
| I9S600 | 关键应用: com.ohos.settings极小概率由于THREAD_BLOCK_6S卡在libark_jsruntime.so出现appfrreze问题。 | 设置页面卡顿。<br/>规避措施：重启设置应用。 | 7月30日 | 