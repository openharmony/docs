# OpenHarmony 4.0 Release


## 版本概述

OpenHarmony 4.0版本如期而至，开发套件同步升级到API 10。相比3.2 Release版本，新增4000多个API，应用开发能力更加丰富；HDF新增200多个HDI接口，硬件适配更加便捷；我们持续优化图形框架和方舟编译器（ArkCompiler），用户交互体验得到进一步提升；ArkUI组件定制化能力和组件动效能力也得到进一步增强；分布式硬件支持的范围扩大到音频和输入领域；分布式数据为开发者数据分享带来了全新的统一数据管理框架。另外，该版本在媒体、安全和隐私保护等方面也得到了进一步增强，欢迎开发者踊跃使用并给我们提出宝贵意见。

您可以阅读本文档了解更多关键特性及能力。


## 特性说明


### 应用框架

Stage模型完善了以下特性：

- 新增Extension能力最小化管理，支持各类Extension满足业务场景需要。

- 新增UIExtension机制，用于实现有界面的Extension，UIExtension的界面可以通过UIExtension组件的方式嵌入到调用方应用的窗口上显示。
  - 支持统一的UIExtension模板，定义基础的生命周期和上下文能力。
  - 支持原生默认的Extension界面展示，方便开发者快速实现Extension功能，同时也提供界面定制能力。

  - 提供连接和断连ExtensionAbility的能力。
  - 支持对UIExtensionAbility页面设置背景色。
  - 支持对UIExtensionAbility页面隐私属性，设置了隐私的页面不能被录屏或截屏。
  - 支持通过UIExtensionAbility连接Service。

- 提供自定义操作业务的ActionExtension、分享业务的ShareExtension、备份恢复业务的BackupExtension、驱动业务的DriverExtension、打印业务的PrintExtension。

- ArkTS卡片能力增强，支持静态卡片配置、静态图展示，有效降低卡片内存资源占用，支持通过数据代理的方式刷新内容，有效降低卡片功耗。

- 支持元服务的分享，应用开发者可以使用UIAbility组件提供的UIAbility.onShare()生命周期方法，设置要分享的数据。用户可以通过分享框把元服务和卡片分享到另外一台终端设备。

- 跨端迁移能力增强，支持调用接口来动态打开和关闭迁移能力。应用可动态选择迁移成功后是否迁移页面栈，以及源端是否退出。


### 应用包管理

- 支持应用安装包免解压特性，优化系统启动性能和应用安装性能。

- 支持应用、元服务数据共享，在应用安装时，解析证书文件中的data-group-ids列表，建立映射关系，创建数据共享路径，实现应用与元服务数据共享。

- 支持应用安装时设置分发类型和附加信息，提供ArkTS接口实现应用分发类型和附加信息的设置和查询。

- 支持根据文件扩展名查询打开文件的应用列表，实现通过文件扩展名打开文件。

- 支持企业应用，提供企业MDM应用和企业normal应用的安装，以及对企业应用的管理和吊销。

- 支持overlay能力，针对不同产品的显示风格，开发者可以在不重新编译打包情况下，新增资源文件overlay包，实现应用界面风格变换。

- 拆包工具支持多语言，应用市场可查询包中的多语言信息，支持在不同的语言环境下分发应用。

- 支持so文件不解压使用，即不解压so文件到单独目录，运行期直接从包中读取加载so文件，提升安装速度和减少占用的ROM空间。


### ArkUI

- **基础组件增加或增强：**
  - 新增UIExtension组件，用于将一个应用通过UIExtensionAbility的方式，嵌入显示到另一个应用内。
  - 绘制组件Rect/Circle/Ellipse/Line/Polyline/Polygon/Path/Rect/Shape支持偏移、裁剪、遮罩等通用属性，增强绘制组件基础功能。
  - 自定义弹框支持蒙层颜色及弹出动画自定义，如允许设置弹出动画效果的相关参数，增强弹框的开发者自定义功能。
  - bindContextMenu/bindMenu支持自定义位置，允许设置菜单的位置，增强菜单基础功能。
  - ColumnSplit分隔线支持可拖动，增强组件基础功能。
  - Refresh组件支持自定义下拉刷新能力，允许设置下拉刷新时的显示内容，增强组件基础能力。
  - 支持文本组件中返回输入字符串的宽高，用于字符串折叠显示时，鼠标悬浮可弹出字符串完整提示框，增强文本组件基础功能。
  - Xcomponent组件支持Texture模式绘制。
  - Popup组件支持自定义位置。
  - ArkTS/JS卡片支持UI渲染完成的回调，方便获取渲染完成的状态并进行下一步处理。
  - Image/Text组件支持设置隐私遮罩的属性。
  - 基础组件特性增强，提升终端用户的体验，包括弹框支持通过键盘ESC键逐层退出、ListItem支持长距离左滑删除手势、ContextMenu支持分段显示能力等。
  - Grid组件支持设置布局信息。
  - Menu组件支持设置圆角。
  - 半模态组件支持设置高度自适应。

- **动画效果增加或增强：**
  - 支持组件属性变化的过渡动效，如组件的尺寸、背景色、透明度等属性发生变化时通过过渡动效衔接变化前后的状态，提升组件属性变化时的动画体验。
  - 支持给组件设置球面高阶属性、下边缘像素扩展、取色模糊、G2圆角、阴影、渐变等高阶图形属性，丰富高阶动画效果。
  - 布局属性、背景图片大小位置属性、显隐属性支持隐式动效。
  - List新增支持scrollToIndex动效、Tabs模糊动效、Popup出现/消失动效。
  - 支持自定义动画，满足多种多样的动画诉求。

- 开发效率增强：支持命名路由的能力，借助此能力可针对不同页面设置差异化的切换动效；轻量级ArkUI框架支持定义全局数据对象，可进行应用内页面间的数据共享。

- 框架能力增强，包括：全局API支持Stage模型多实例场景，支持Rosen渲染后端等。

- 对富文本的交互能力增强：新增支持手势长按选中文本、支持鼠标拖动选中文本、支持设置文本可编辑（通过通用属性设置富文本框是否使能编辑）、支持对输入事件的监听。

- 弹窗功能增强，新增错误、信息和询问三种消息弹窗接口，完善警告弹窗三按钮场景和交互优化。


### ArkCompiler

**高级语言调试调优：**

- 热重载性能优化，支持多hap等场景。

- 支持多实例调优。

**高级语言并发增强：**

- TaskPool支持任务中断和取消，支持定义任务组（TaskGroup），支持对任务的状态和调度信息进行打点，支持超长等待的任务进行识别和恢复。

- TaskPool支持优先级设置及自动扩缩容算法。

**高级语言优化编译：**

- 正式定义ArkTS语法规则并新增ArkTS语法检查，在使用DevEco Studio进行代码编译时会对不符合ArkTS语法规则的代码进行告警。语法检查的规则详见[从TypeScript到ArkTS的迁移指导](../application-dev/quick-start/typescript-to-arkts-migration-guide.md)。

- AOT优化编译支持端侧闲时编译，增强编译优化进一步提升性能。

- PGO支持采集运行期的类型和函数热点信息，支持AOT优化编译JS代码，提升动态JS代码的运行性能。

**高级语言运行时其它功能：**

- 支持动态import加载NAPI库。

- NAPI buffer、object、arraybuffer、object type接口功能补齐。

**编译工具链更新：**

- clang/llvm工具链升级到15.0.4版本。

- libc版本升级到1.2.3版本，libc库接口性能优化。

- sigaction函数提供sigchain功能。


### 分布式数据管理

- DataShare客户端提供按URI前缀订阅DataShareExtension数据变化的能力，被订阅的URI前缀下任何DataShareExtension数据发生变化都会通知DataShare客户端。

- 新增统一数据管理框架（Unified Data Management Framework, UDMF），支持数据标准化模型、设备内数据拖拽、UDMF数据存储适配、权限管理、生命周期管理。UDMF框架下支持应用的跨设备拖拽，在此过程中允许对分布式目录中的文件临时授权。

- 提供RDBstore NDK接口 ：包含增/删/改/查/事务、数据加密、数据分级保护、备份/恢复能力。

- Key-Value和分布式数据对象支持根据数据量自动选择数据同步的通道。系统会根据数据量大小自动选择蓝牙通道或基于Wi-Fi的P2P通道进行数据的同步。

- 支持系统应用通过数据管理服务代理静默访问其他系统应用的DataShareExtension数据，即不拉起DataShareExtension所在的应用即可访问应用DataShareExtension的数据。


### 分布式软总线

- 支持对基于软总线连接的link信息进行管理。

- 支持会话级的传输能力协商，可通过协商确定设备间传输的能力。


### 分布式硬件

- 分布式音频支持扬声器（speaker），麦克风（mic）的资源池化管理，可以在native系统服务中跨设备使用远端设备的扬声器和麦克风，并支持控制远端设备的扬声器音量。

- 分布式输入支持键盘，鼠标，触摸板的资源池化管理，可以在系统应用中触发跨设备的键盘、鼠标和触摸板的使用。


### 文件管理

- 支持文件分类视图管理能力，图库等应用以相册方式管理媒体文件（图片、视频无需关注具体存储位置），相册内添加、移除文件等功能不涉及具体的File IO行为。支持三方应用通过PhotoAccessHelper接口获取相册列表，访问相册内图片、视频等文件。

- 提供增强的FileIO访问能力，支持randomAccessFile、moveDir、copyDir能力。

- 提供基于URI的文件临时授权访问及取消授权能力，支持文件的跨应用本地授权或跨设备授权。

- 支持公共图片文件在设备端和云端进行同步（设备登录的帐号需开通云端服务），支持通过picker选择云端的图片。

- 支持应用定制备份恢复的目录。

- 支持应用监听沙箱内的文件变化。


### 图形显示及窗口

**图形**

稳定流畅：

- 对统一渲染模式进行了性能优化，包含基于共享内存的IPC性能优化、基于遮挡剔除和缓存等技术的渲染性能优化、基于硬件合成器能力的能效提升等。

- 图形处理依赖的渲染库升级至Skia 0310新版本，提升了渲染性能。

极致动效：

- 支持组件自绘制内容的属性动画。支持组件设置出现和消失的转场动画。

- 支持取色能力，支持渐变模糊，支持边缘像素扩展，支持渐亮效果，支持多种模糊材质能力。

图片能力增强：

- 图片编解码能力增强：支持SVG格式图片解码，ico格式图片解码，GIF增量解码，jpeg_IDCT缩放解码，png图片编码，图片exif信息拓展。

- 图片接口能力增强：支持Pixelmap JS侧的序列化反序列化，提供ImageReceiver和图片解码NDK接口。

**窗口**

- 支持监听窗口的获焦状态，可以监听单个窗口的获焦、失焦和显示隐藏状态。

- 支持应用将子窗口z轴顺序调整到当前应用窗口中的顶层。

- 支持查询屏幕的显示模式（镜像、扩展），提供停止镜像和停止扩展API。

- 优化了display模块的参数值获取方式，从原先软件方式优化为从硬件直接获取真实值。

- 支持通过窗口设置将屏幕亮度恢复默认值。

- 重构沉浸式实现方式，优化应用打开、退出、跳转下的动画效果。


### 媒体

**音频**

- 支持通过Native接口（OHAudio）进行音频播放和录制。对于音频录制和播放的时延比较敏感的场景，使用Native接口可实现更低的时延。

- 支持查询或监听当前优先级最高的播放设备。

- 支持闹钟音量的独立调整。

- 支持通过物理按键设置静音。

- 支持音频焦点：应用播放音频时无需手动申请焦点，系统会在后台自动申请焦点，并自动执行焦点策略（如暂停、淡出、淡出恢复等）；应用仅需要注册焦点事件监听函数，以接收焦点事件并更新状态，如暂停时停止进度条。支持短音播放。

- 支持音效模式：应用可查询音频输出的音效模式，切换或关闭音效模式。

- 支持系统内录音能力：可根据音频场景属性筛选，录制系统内播放的音频数据，支持对录音设备进行查询。

- 音频设备能力增强：支持获取音频设备显示名，播放对象详细信息内可获取当前播放输出归属的设备名。支持对蓝牙连接的多个可用于音频播放的设备进行查询并选择音频播放的设备。支持标准USB协议的音频外设。

**播控框架**

- 支持媒体提供方和控制方之间传递自定义媒体信息，应用可扩展媒体内容展示方式，如媒体控制方可要求媒体提供方按特殊形式显示歌曲歌词。

- 支持媒体播放列表的框架能力，媒体提供方提供播放列表内容，媒体控制方获取播放列表内容并可以选择任一媒体内容进行播放。

- 支持播放历史记录的框架能力，媒体会话框架提供查询历史播放应用的列表，列表项按播放先后顺序排序（包含当前播放的和已退出的应用）。

- 提供自定义媒体事件的传输通道，如歌词内容的传输通道，媒体提供方提供歌词内容，媒体控制方获取歌词内容。

- 提供自定义的媒体控制命令的传输通道，媒体控制方可以利用该自定义命令传输通道向媒体提供方发送自定义控制命令，如媒体控制方要求媒体提供方显示弹幕信息。

**媒体播放**

- 支持基于HLS协议的网络直播功能以及基于datasource的流式播放功能。

- 支持基于HDI的H.265视频硬解播放能力。

- 支持播放音频属性设置，用户在使用播放器的时候可以选择输出声音的类型。

- 支持视频自带的旋转播放功能。

- 支持音效参数配置，可以在音频框架支持音效的能力基础上进一步配置音效。

**相机**

- 支持前置预览镜像能力，默认情况下，前置预览画面呈镜像状态。

- 支持分布式摄像头查询该摄像头的主设备属性，包括设备名称和设备类型。

- 支持更精细化的分辨率查询，可以按照预览、拍照、录像用途查询支持的尺寸、格式和帧率信息。

- 相机框架提供横向归一化坐标系[0, 0, 1, 1]，所有与坐标相关的操作都基于这套坐标系完成。

- 不同相机应用使用同一个摄像头场景下，相机框架具备优先级管控和互斥策略。

**音视频编解码**

- 支持获取系统的音视频编解码，可以调用本模块的Native API接口，查询系统编解码能力的支持情况。

- 支持音视频封装，可以调用本模块的Native API接口，完成音视频封装，即将音频、视频等编码后的媒体数据，按一定的格式存储到文件里。

- 支持音视频解封装，可以调用本模块的Native API接口，完成音视频解封装，即从比特流数据中取出音频、视频等媒体帧数据。


### 事件通知

- 支持应用设置静态事件订阅的开关。

- 支持系统应用删除已发布的粘性事件。

- 支持应用设置代表通知数量的数字角标。

- 支持将通知设置为不可移除。

- 支持选定通知并批量删除通知。

- 应用内事件处理模块支持取消已按条件指定订阅的回调。


### 通信与连接

- 支持NFC eSE卡模拟能力。

- 支持Wi-Fi连接AP时使用随机MAC。

- 支持Wi-Fi通过静态IP连接AP。


### 系统服务管理

- 支持系统服务按需启动机制，例如外部调用、事件触发，同时支持在设备空闲时自动退出系统服务。

- 系统服务配置格式优化，使用JSON格式替代XML格式。


### 电源

- 增强系统电量等级查询及上报能力，支持电量等级的裁剪和定制。

- 支持有线和无线充电类型上报，充电类型包括普通充电、快速充电和超级快速充电。

- 增强运行锁的管控机制，明确系统电源状态和等级。

- 提供唤醒源设置能力，支持通过电源键、鼠标、键盘、触控板、屏幕、手写笔、皮套等方式唤醒设备。

- 提供休眠源设置能力，支持通过电源键、皮套、及超时自动休眠等方式设置设备休眠。

- 提供电源管理、电池管理、显示亮度管理、耗电统计及热管理的开发指南。

- 新增系统接口，支持设置系统立即进入睡眠状态。


### 多模输入

- 支持将键盘输入设备的原始事件映射为归一化交互的意图事件。

- 支持用户根据个人习惯设置触控板功能的个性化配置：
  - 支持两种触发模式映射鼠标左键功能：按压、轻点。
  - 支持两种触发模式映射鼠标右键功能：点按左/右下角、双指点按或轻点。
  - 跟踪速度：支持10档速度调节。
  - 支持两种交互模式映射鼠标滚轮功能：内容随手指移动方向、内容随手指反向移动。


### 主题框架

- 锁屏管理服务：支持锁屏事件回调机制、支持静态/动态壁纸、支持查询锁屏时的业务状态。

- 壁纸管理服务：支持自定义壁纸、支持锁屏/解锁操作、支持重置壁纸。


### 上传下载

新增接口，使用统一配置参数与接口完成上传下载业务任务创建执行，完善业务流程。

- 支持任务信息持久化记录，查询方式灵活多样，任务信息更加全面，支持按过滤条件查询任务信息。

- 增强安全隐私保护，增加系统管理接口权限。

- 支持文件覆盖下载、分片上传下载、自定义token任务创建。

- 支持服务按需启停，应用调用相关接口时启动，任务空闲时自动退出。


### 时间时区

- 获取系统时间、系统启动时间提供同步接口。获取到的时间更精准，且提供较好的开发者体验。

- 获取日期接口废弃，由ArkTS公共库new Date()接口替代。


### 输入法

新增同步接口，用于获取编辑框信息。


### 网络管理

- 提供IPv6基础能力，包括DNS解析、应用通过http/https/socket联网，蜂窝/Wi-Fi/有线网络下均可支持IPv4/IPv6双栈接入。

- 新增同步接口，针对\@ohos.net.connection模块的高频接口，在原有异步接口基础上新增了对应的同步接口。


### 打印

提供打印服务功能，应用可以通过print接口触发打印业务。打印服务提供了系统默认的打印预览界面和任务管理界面，可以管理网络打印机设备连接。


### 安全

**加解密算法库框架**

- 提供DSA数字签名算法能力。

- 提供DSA、ECC、RSA密钥解析和密钥参数的获取能力。

- 提供安全随机数生成算法类型的获取能力。

- 提供SM4密钥的随机生成与转换，以及加密解密能力。

- 提供SM3密钥的HMAC和HASH的能力。

- 提供SM2密钥的随机生成与转换、签名及验签、以及加密解密能力。

**密钥管理**

- 基于GID派生芯片级密钥的能力。

- 支持国密密钥的安全导入。

- 支持二次身份认证的细粒度访问控制。

- 密钥管理签名支持签名NO HASH模式。

- 密钥管理算法支持运算时指定密钥参数。

- 支持HUKS密钥加密保护。

- 支持KeyAttestation公钥证书中增加对密钥所属业务身份字段。

- 支持标准HDI南向接口。

**设备互信认证**

支持在以下两种场景的设备间互信认证流程中生成假名，支持识别及标识设备的假名化名称。

- 对同帐号登录的多个设备进行互信认证。

- 对非同帐号的点对点互联的两个设备进行互信认证。

**安全基础能力**

支持小型设备查询其它设备的设备安全等级信息。

**证书管理**

支持外部指定RSA密钥签名摘要及填充签名和验签能力。


### 程序访问控制

- 支持拉起应用粒度的权限管理界面。

- 支持对系统应用的所属身份进行校验。

- 优化权限管理的菜单呈现，拆分媒体和文件的权限组，相应权限的授权粒度更加精细化。


### 帐号

- 支持帐号授权能力扩展和三方应用使用帐号授权能力。

- 支持域帐号插件管理、域帐号管理、域帐号认证能力。


### 用户IAM

- 提供统一身份认证控件，完善用户身份认证能力，方便系统开发者调用身份认证能力并且生态体验统一。

- 统一身份认证控件提供了系统默认的用户身份认证界面，选择使用带控件的接口getUserAuthInstance, AuthParam指定认证参数，WidgetParam指定控件显示参数。为确保用户在系统上有统一的身份认证体验，建议开发者使用API version 10提供的新用户身份认证接口。


### WebView

- W3C能力补充完善：补充Web camera能力，以及bindContextMenu、Select、date类型input等H5标签能力。

- 支持多渲染进程的进程拆分。

- 支持文字、图片基础拖拽能力。

- 支持WebRTC的视频会议能力（不含摄像头共享）。

- 支持渲染进程独立SELinux标签，增强安全基础能力。

- 支持识别Web组件渲染进程、显示线程和场景信息，并通知系统资源调度进行CPU管控。


### 内核

- 支持HCK内核接口框架。

- 支持Linux内核config多级分层配置。

- 代码执行权限管控能力增强，新增了以下能力：
  - 支持安全内存机制。
  - 支持不同场景的代码执行权限管控策略。
  - 支持代码执行权限管控的全生命周期管理能力。
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


### 泛Sensor

- 支持对设备所支持的预置振动效果进行查询，可通过EffectId查询某个振动效果在设备上是否被支持。

- 新增振动全停接口，无需传入对应的振动模式，可直接停止当前任意模式所设置的振动。

- 新增播放振动配置文件接口，支持从文件播放自定义触觉的控制模式，播放执行结果依赖设备的振感器件能力。


### 测试

**测试框架arkxtest**

- 支持自动化脚本测试套嵌套定义能力，提升开发者脚本设计灵活性。

- 支持对象级断言能力，提升测试脚本断言能力。

- 支持模拟中文输入、模拟鼠标操作、区域截图的能力。

**自测试执行框架developer_test**

- 支持测试任务管理能力，开发者通过任务ID执行历史任务，提升开发者自测试效率。

- 支持精准测试能力，支持子系统、部件、测试套、测试用例级测试用例筛选执行能力，提升开发者自测试效率。

- 支持对接执行hats用例，丰富执行用例范围。

- 支持稳定性测试能力，支持测试用例乱序执行。

- 支持覆盖率统计能力，支持开发者本地一键式生成代码覆盖率数据。

**稳定性测试工具wukong**

支持旋转事件注入，增强注入能力。

**性能调试开发工具SmartPerf Host**

- 支持Frame timeline抓取和展示能力，开发者可以抓取和展示卡顿丢帧检测的数据。

- 支持Scheduling analysis抓取和展示能力，开发者可以抓取和展示CPU调度分析，线程调度分析相关数据。

- 支持调用栈可视化和不同库函数调用占比展示能力，开发者可以抓取并通过饼图的方式展示调用栈及不同库函数的占比

**性能数据采集SmartPerf Device**

- 支持应用冷热启、页面内切换、滑动帧率测试能力，开发者可以测试应用冷热启动时延、页面切换时延、滑动帧率测试能力。

- 支持端侧测试数据对接云端看板能力，开发者可以将端侧测试报告上传云端查看或下载云端数据到本地。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.0 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.10.13 (API Version 10 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
| HUAWEI DevEco Studio（可选） | 4.0 Release | OpenHarmony应用开发推荐使用。获取方式：<br />[Windows(64-bit)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/9a/v3/HBD3TfhiT_GFqeX44Qcwtg/devecostudio-windows-4.0.0.600.zip?HW-CC-KV=V1&HW-CC-Date=20231027T004333Z&HW-CC-Expire=315360000&HW-CC-Sign=279824A013505EFC063997614DC1B6AB1C3A2EE5AC48CEF15DDB3E1F79DA435A)  <br />SHA256校验码：2c88cf43e1ef6ba722aac31eccc8ef92f07a9b72e43a9c1df127017828a22137<br />[Mac(X86)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/e0/v3/y3Qc4UHsTn6i1M7yr3hVYg/devecostudio-mac-4.0.0.600.zip?HW-CC-KV=V1&HW-CC-Date=20231027T004531Z&HW-CC-Expire=315360000&HW-CC-Sign=07F14E7173D87ABF73777BA0CF7ADF1C1264A7D94909976471AC420C1932E8A6)  <br />SHA256校验码：25e491458eec50b4abddf5bed6aa85893801d70afbce02958f17bd904619405a<br />[Mac(ARM)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/94/v3/b0yynFMFSGGvbe--AQQR9w/devecostudio-mac-arm-4.0.0.600.zip?HW-CC-KV=V1&HW-CC-Date=20231027T004429Z&HW-CC-Expire=315360000&HW-CC-Sign=451E5B5C6B6E721A6C35E96FD67791D50ADEC56E987D87CD61E9E5152F8D6626)  <br />SHA256校验码：284cb01f7b819e0da1d4fcacbbbbe8017ba220b5e3b9b1d5e4cc59ea30456acc |
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Release/code-v4.0-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/code-v4.0-Release.tar.gz.sha256) | 27.6 GB |
| Hi3861解决方案（二进制）        | 4.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_pegasus.tar.gz.sha256) | 27.3 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 302 MB |
| Hi3516解决方案-Linux（二进制）  | 4.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 194 MB |
| RK3568标准系统解决方案（二进制）        | 4.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/dayu200_standard_arm32.tar.gz.sha256) | 	5.1 GB |
| 标准系统Public SDK包（Mac）             | 4.0.10.13      | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | 841 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.0.10.13     | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 797 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.0.10.13      | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.0 GB |

## 更新说明

本版本在OpenHarmony 4.0 Beta2的基础上有如下变更：


### API变更

- OpenHarmony 4.0 Release相比4.0 Beta2的API差异请[点击这里查看](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Release/zh-cn/release-notes/api-diff/v4.0-Release-vs-v4.0-beta2/Readme-CN.md)。
- OpenHarmony 4.0 Release相比3.2 Release的API差异请[点击这里查看](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Release/zh-cn/release-notes/api-diff/v4.0-Release-vs-v3.2-Release/Readme-CN.md)。

此外，从4.0 Beta2至今，有少量接口变更可能影响此前应用工程的兼容性或需要您关注，详细的变更说明请[点击这里查看](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Release/zh-cn/release-notes/changelogs/v4.0-Release/Readme-CN.md)


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

**表3** 新增Samples

| 特性 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| 文件管理 | [选择并查看文档与媒体文件](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/FileManagement/FileShare/Picker)（APL等级需为system_basic） | 本示例展示了应用使用\@ohos.file.picker、\@ohos.multimedia.mediaLibrary、\@ohos.file.fs 等接口，实现了picker拉起文档编辑保存、拉起系统相册图片查看、拉起视频并播放的功能。 | ArkTS |
| 一次开发，多端部署 | [一多导航栏](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/SuperFeature/MultiDeviceAppDev/MultiNavBar) | 本示例展示了导航组件在不同设备形态下的样式。<br/>在小型/轻量级设备上，以tabs形式展示，内容、导航为上下样式布局，通过点击底部tabs切换内容；<br/>在标准设备上，以SideBarContainer形式展示，内容、导航为左右布局，通过点击侧边一二级菜单进行内容切换。<br/>本示例使用一次开发多端部署 中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，主要通过组件提供窗口断点事件，保证应用在不同设备或不同窗口尺寸下可以正常显示。 | ArkTS |
| 卡片 | [应用主动添加数据代理卡片到桌面](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/SuperFeature/Widget/RequestAddForm)（Full SDK） | 本示例主要展示了使用\@ohos.app.form.formBindingData、\@ohos.app.form.formProvider等接口，实现了在com.ohos.hag.famanager应用上，主动添加数据代理卡片到桌面的功能。 | ArkTS |
| 安全 | [安全控件类型的UI控件](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/SystemFeature/Security/AuthorizedButton)（Full SDK） | 本示例提供了安全控件类型的UI控件，支撑应用开发者集成安全控件做临时授权场景，当用户实际点击了某种类型的安全控件时，会对应用进行相应的临时授权，减少权限弹窗对用户的干扰，同时提供更小的授权范围。 | ArkTS |

请访问[Samples](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/)仓了解更多信息。


## 修复缺陷列表

**表4** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [267](https://gitcode.com/openharmony/applications_launcher/issues/267) | 长时间运行测试，launcher进程概率性出现appfreeze，原因是STRINGID:APPLICATION_BLOCK_INPUT卡在libeventhandler.z.so。 |
| [9123](https://gitcode.com/openharmony/graphic_graphic_2d/issues/9123) | 低概率出现进程com.ohos.systemui下的线程render_service出现cppcrash。 |
| [31597](https://gitcode.com/openharmony/arkui_ace_engine/issues/31597) | 反复进入大图浏览界面后返回，导致libace.z.so出现内存泄露。 |
| [3871](https://gitcode.com/openharmony/communication_dsoftbus/issues/3871) | 因兼容性问题，使用3.2.x版本的设备和4.0.x版本的设备通过Wi-Fi引导P2P连接时开启会话失败。 |
| [9502](https://gitcode.com/openharmony/graphic_graphic_2d/issues/9502) | 三方仓GLES3多个测试用例执行失败。 |


## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| [473](https://gitcode.com/openharmony/communication_bluetooth/issues/473) | 进程com.ohos.settings（所属应用：设置）有一定概率出现由于THREAD_BLOCK_6S卡在libbtframework.z.so而发生appfreeze。 | 概率问题，重新打开设置后可恢复正常，影响可控。 | 12月30日 |
| [246](https://gitcode.com/openharmony/applications_settings/issues/246) | 进入设置反复打开关闭蓝牙，有一定概率会导致设置出现appfreeze。 | 概率问题，出现设置无响应后可通过重启设备恢复正常，影响可控。 | 12月30日 |
| [115](https://gitcode.com/openharmony/applications_contacts/issues/115) | 低概率出现进程com.ohos.contacts（所属应用：联系人）下的m.ohos.contacts线程导致libipc_core.z.so出现cppcrash。 | 小概率问题，重启联系人应用可恢复正常，影响可控。 | 12月30日 |
| [88](https://gitcode.com/openharmony/third_party_libuv/issues/88) | 进程ohos.samples.distributedmusicplayer（所属应用：音乐播放器）下的ffrtwk/CPU-2-3线程低概率出现cppcrash，导致该现象的崩溃栈为libuv.so。 | 小概率问题，重启音乐播放器可恢复正常，影响可控。 | 11月30日 |
| [377](https://gitcode.com/openharmony/third_party_llvm-project/issues/377) | 进程com.ohos.camera（所属应用：相机）下的com.ohos.camera线程小概率会导致libcamera_napi.z.so出现cppcrash。 | 小概率问题，重启相机可恢复正常，影响可控。 | 12月30日 |
| [2454](https://gitcode.com/openharmony/web_webview/issues/2454) | 进程com.ohos.note（所属应用：备忘录）下的com.ohos.note线程低概率出现cppcrash，导致该现象的崩溃栈为libweb_engine.so。 | 小概率问题，重启备忘录可恢复正常，影响可控。 | 12月30日 |
| [223](https://gitcode.com/openharmony/applications_photos/issues/223) | 进程com.ohos.photos（所属应用：相册）有一定概率由于THREAD_BLOCK_6S卡在libark_jsruntime.so而发生appfreeze。 | 概率问题，重启相册可恢复正常，影响可控。 | 11月30日 |
| [471](https://gitcode.com/openharmony/communication_bluetooth/issues/471) | 进入设置反复打开关闭蓝牙开关会出现内存泄漏，经测试一个小时泄露15MB。 | 开关一次蓝牙系统内存泄露8.3KB，重启设备后可恢复，影响可控。<br />对于需要使用OpenHarmony进行商业开发的伙伴，建议使用芯片或硬件自带蓝牙模块的协议栈以规避此问题。 | 12月30日 |
| [251](https://gitcode.com/openharmony/applications_settings/issues/251) | 进入设置反复打开关闭蓝牙开关出现内存泄漏，经测试“设置”一个小时内存涨幅到180M。 | 开关一次蓝牙应用内存泄露0.2MB，重新打开“设置”卡恢复，影响可控。<br />对于需要使用OpenHarmony进行商业开发的伙伴，建议使用芯片或硬件自带蓝牙模块的协议栈以规避此问题。 | 12月30日 |
| [110](https://gitcode.com/openharmony/powermgr_thermal_manager/issues/110)<br/>[4139](https://gitcode.com/openharmony/ability_ability_runtime/issues/4139)<br/>[5046](https://gitcode.com/openharmony/window_window_manager/issues/5046) | 长时间稳定性压力测试出现foundation内存泄漏，24小时泄露40MB。 | 重启设备可恢复。影响可控。 | 12月30日 |
| [2461](https://gitcode.com/openharmony/kernel_linux_5.10/issues/2461)等31个内核问题 | 内核btrfs_free_tree_block函数kernel_bug等31个内核问题。 | linux原生问题且当前linux社区无补丁，跟随linux社区补丁节奏修复。不影响功能正常使用。 | 跟随linux社区修复 |
| [126](https://gitcode.com/openharmony/third_party_chromium/issues/126)等38个开源组件漏洞 | lj-linux-131204684-0577967 等38个开源组件漏洞。 | 分析解决中，跟随社区漏洞管理流程SLA修复。不影响功能正常使用。 | 按漏洞SLA修复 |
| [8322](https://gitcode.com/openharmony/graphic_graphic_2d/issues/8322) | GPU驱动渲染出的图像与标准不符问题。 | 该问题为RK3568驱动特有问题，非系统兼容性问题，不影响其他产品和硬件的兼容性认证。 | 12月30日 |
