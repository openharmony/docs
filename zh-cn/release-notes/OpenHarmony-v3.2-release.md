# OpenHarmony 3.2 Release

## 版本概述
OpenHarmony 3.2版本标准系统能力进一步完善，支持采用ArkTS语言+Stage应用模型进行大型应用、原子化服务开发。[ArkCompiler](#arkcompiler)的优化、Taskpool机制提升应用运行性能；ArkUI组件能力增强，强化图形渲染能力和系统安全能力，丰富分布式业务开发；OpenHarmony 3.2 Release版本提供API Level 9稳定接口，在OpenHarmony 3.1 Release版本的基础上，进一步提升系统的整体性能、稳定性和安全性。


OpenHarmony 3.2版本完整里程碑如下图所示，阅读本文档了解更多关键特性及能力。


  **图1** OpenHarmony 3.2社区版本里程碑  
![release](figures/release.png)

## 特性更新
### ArkUI


 **组件能力增强** 

- 支持XComponent控件，可用于EGL/OpenGL ES和媒体数据写入，并在XComponent组件显示；通过XComponent组件，配合NDK能力，构建C++/ArkTS混合开发能力，支持游戏、媒体应用开发
- 支持AbilityComponent控件，支持嵌入其他应用作为控件（Component）显示。
- 增加基础的ArkTS卡片开发能力：支持卡片交互、能动态更新内容；统一卡片和页面的开发范式，页面的布局可以直接复用到卡片布局中，提升卡片开发体验和开发效率。
- 系统默认支持纯文本、纯图片复制、粘贴、拖拽，无需开发者处理复制、粘贴、拖拽事件。
- 支持多级菜单和分组菜单。

 **UI界面开发支持一次开发适配多屏幕规格** 

- 交互归一能力增强，交互归一事件对接TP、鼠标、键盘、触摸板、手写笔，ArkUI原生组件支持归一化的操作方式。
- 响应式布局能力优化，增强了媒体查询能力，栅格系统重构且对接自由窗口。
- 走焦能力增强，支持Tab键和方向键走焦，支持配置组件是否可获焦。
- 支持增强分栏与侧边栏组件能力，支持拖拽自动隐藏等能力。

详细内容请参考[ArkUI指南](../application-dev/ui/arkui-overview.md)。


### 应用框架

- Stage模型，OpenHarmony API 9新增模型，提供了应用程序必备的组件和运行机制。开发者可以基于该模型进行复杂应用开发，使应用开发更简单、高效。
  - 以类形式提供组件开发，方便开发者基于类扩展。
  - 进程内共享虚拟机实例，减少应用内存占用。
  - 支持在进程内共享数据对象，方便开发者在多模块间共享状态。
  - Ability生命周期和窗口显示/焦点事件分离，统一了多设备形态下组件的生命周期，有利于多设备应用开发。
  - Ability与UI职责分离且具备RPC调用能力，原生支持组件级的跨设备迁移与协同，有利于分布式应用开发。

- 提供Extension机制，借助Extension，应用在与其他应用或系统进行交互时向他们提供自定义功能和内容，例如：应用可以作为卡片显示在系统桌面或者系统闲时执行后台任务等。当前支持的常用Extension有：FormExtensionAbility、WorkSchedulerExtensionAbility、InputMethodExtensionAbility、AccessibilityExtensionAbility等。

- 原子化服务支持分包预加载，提升服务首次加载性能。

- 支持HSP（Harmony Shared Package）动态共享包，支持应用内代码和资源的共享。


详细内容请参考[应用模型指南](../application-dev/application-models/application-model-composition.md)。


### 应用包管理

- 支持选择默认应用，例如用户使用应用程序打开文件或url地址时选择了默认程序，后续将自动打开该应用程序操作文件。

- 支持对部分预置应用如Launcher、SystemUI、Settings等，系统事先授予权限（如定位、电话联系人等权限）、简化设备开箱后的授权过程，提升用户体验。详细请参考[user_grant权限预授权](../application-dev/security/accesstoken-guidelines.md)。

- 支持预置应用配置是否可常驻、是否可以多进程，是否允许使用Service类型的ExtensionAbility等能力，加强对预置应用的权限管控。详细请参考[应用特权配置指南](../device-dev/subsystems/subsys-app-privilege-config-guide.md)。

- 支持动态修改和更新应用程序的代码，提供快速修复程序包便于应用快速响应需求和修复问题（此能力依赖设备厂商构建应用市场并提供分发能力）。详细请参考[快速修复介绍](../application-dev/quick-start/quickfix-principles.md)。

- 支持so基于hap包的隔离，方便开发者在不同的模块中部署so文件，避免了不同模块so重名的问题。


### 系统应用

 **Launcher应用增强**

提供长按应用图标添加服务卡片的能力（当前支持相机、图库应用）。


 **SystemUI应用增强** 

- 支持控制中心打开和退出。

- 支持通知中心打开和退出；通知显示、删除、组展开与收起；横幅通知的显示与隐藏。


 **Settings应用增强** 

- 提供在隐私设置菜单设置权限的能力。

- 开发者选项增加布局边界调试、过渡动画调试、过渡绘制调试开关。


 **Photos应用增强** 

- 新增PhotoPicker能力。PhotoPicker是系统向用户提供图片和视频文件选择的统一入口，避免用户向应用授权文件权限，图片文件使用权限最小化控制提升应用安全。

- 支持相册服务卡片，提供相册浏览能力。

- 支持图片编辑能力，如自由裁剪图片、旋转图片等操作。
  详细请参考[Application Photos](https://gitee.com/openharmony/applications_photos)。


 **FilePicker** 

新增FilePicker能力。FilePicker是系统向用户提供文件（媒体文件除外）选择的统一入口，避免用户向应用授权文件权限，确保文件使用权限最小化控制提升应用安全。


 **浏览器**

当前版本未内置浏览器应用。可手动安装[浏览器应用示例](https://gitee.com/openharmony/applications_app_samples/tree/samples_3.2_Release/code/BasicFeature/Web/Browser)后进行网络内容浏览等场景的体验。



### 分布式技术

支持元服务和卡片跨设备流转，包括：跨设备查询、添加、刷新、删除等。


#### 分布式软总线

- 提供基于蓝牙链路的文件传输能力，蓝牙数据传输通道相比OpenHarmony 3.1版本性能提升约10%。

- 通过为每个进程分别建立Message和Byte高低优先级队列，确保在Message和Byte并发的情况下，优先保障消息队列的数据发送，同时也能保障Byte得到有效传输，解决了在字节数据拥塞的情况下，消息数据不能及时传输的问题。

- 在支持RAW流的基础上，新增COMMON流传输能力，将未加密音视频流交由软总线进行加解密，调用者只需要把原始的音视频流数据传递给软总线，软总线保障数据的安全传输。

- 支持传输链路（WLAN/WiFi P2P/蓝牙BR）动态选择。根据双端设备支持的传输链路以及业务调用软总线传输接口（SendFile、SendStream、SendMessage、SendBytes）进行链路选择。例如当需要传输流数据时，优先选择WLAN（5G频段）进行传输，如果WLAN不可用，则选择其它链路（例如WiFi P2P）进行传输。



#### 分布式硬件

- 分布式相机拍照支持设置拍摄地理位置信息和照片质量级别（影响照片的压缩比和画质清晰度）。

- 分布式相机支持录像功能。

- 设备管理Native APIs支持将帐号认证信息导入到设备安全认证系统中，相同帐号的设备可以自动完成设备认证和组网。


#### 分布式数据管理

 **跨应用数据访问** 

- 通过代理方式实现同设备内跨应用数据访问，避免频繁拉起数据源应用。

- 支持同设备内关系型数据库、键值型数据库的跨应用数据访问。

 **本地数据库** 

- 支持键值型数据库和关系型数据库。

- 支持对数据库文件的加密保存。

- 支持数据库的异常损坏检测以及异常重建。

- 支持应用通过客户端进行备份和恢复数据库。

- 支持自动备份键值型数据库。

- 支持同应用跨设备对关系型数据库远程查询。

- 支持元数据库异常损坏检测和自动重建。

- 键值型数据库从统一的系统沙箱切换到各应用沙箱，缩小应用数据的访问权限，提升了应用数据的安全性。

 **数据同步** 

- 支持按条件（时间段、时间排序、同步时长）同步键值型数据，实现高能效、精准数据同步。

- 设备上线优先同步系统数据，缩短设备唤醒时间。

- 支持多用户场景下的跨设备数据同步。

 **分布式对象：** 支持对象数据持久化。

 **沙箱应用：** 支持键值型数据库、关系型数据库、分布式对象的持久化。


#### 分布式调度

增强Ability流转能力，通过支持数据结构自动序列化降低应用程序适配复杂度；支持使用分布式对象传输流转的业务数据；在流转过程中可自动免安装原子化服务。


### 文件管理

- 增强文件加密特性，支持用户级文件加密。

- 新增按应用空间统计接口，支持获取应用各级目录空间大小。

- 增强应用文件共享能力，提供跨应用文件打开能力。

- 支持应用文件备份恢复能力。

- 支持文件系统外置存储挂载卸载、格式化等能力，支持外置存储读写访问能力。

- 增强文件管理IO接口能力，新增list file接口提供目录遍历能力。


### 图形显示 &amp; 窗口

- 提升多窗口场景的显示帧率。

- 增强属性动画，支持动画自定义属性。

- 增强Native层图形开发能力，SurfaceImage接口支持buffer管理、内容更新、变换矩阵等接口能力；Vsync支持请求下一帧、回调等接口能力；Hardwarebuffer接口支持申请、释放、获取、访问等接口能力 ，NativeWindow接口支持设置缩放模式。

- 构建EGL层，增强南向GPU适配能力。

- 提供窗口阴影、模糊、圆角等视觉效果的能力。

- 提供一镜到底、输入法切换、应用切换、转屏等转场动效能力。

- 支持窗口属性设置，窗口隐私图层避免截屏、录屏时泄露用户隐私。


### 媒体


 **音频** 

- 提供选择蓝牙设备进行音频播放和通话的能力。

- 支持生成DTMF拨号音并进行播放。

- 支持OpenSL ES基础录音接口。

- 支持应用查询当前可用的音频设备列表，并携带具体设备信息，比如设备采样率、通道数、通道掩码。

- 支持查询系统中已建立的播放流和录音流信息。


 **播放** 

- 媒体播放支持fd格式输入的本地播放、支持HTTPS、HLS协议网络点播功能。媒体播放支持基于HDI的H264硬解播放能力。

- 提供音视频编解码能力，基于HDI codec接口的视频硬编码/硬解码能力。


 **相机** 

- 支持相机拍照配置：格式、分辨率、质量（影响照片的压缩比和画质清晰度）、地理位置等。支持录像和录像中抓拍。

- 支持相机精准隐私保护策略，仅允许前台使用（包含相机悬浮窗场景）；支持系统服务后台使用相机，不允许第三方APP后台静默使用相机。提供系统接口，供相机全局开关开启、禁用调用。


 **图片** ：增加支持raw、Webp图片格式。




### 事件通知

- 支持应用设置显示在桌面上的角标数量。

- 支持系统应用移除粘性事件，某个粘性事件移除后，新的订阅者将不再收到对应的事件。

- 支持系统应用使能/去使能静态订阅，静态订阅事件去使能后，StaticSubscriberExtensionAbility不再被关联拉起。

- 补齐静态订阅Extension上下文的能力，StaticSubscriberExtensionAbility运行时可以通过上下文获取安装包的静态信息（如包路径、包名等）。

### Web

- 支持配置Web组件，包括网络加载拦截配置、字体管理配置、滚动条配置、fetch自定义拦截配置。

- 支持网页操作，包括获取历史记录和前进后退列表、获取源URL、支持滚动、判断页面中是否有图片。

- 支持网页事件处理，支持页面加载各类事件上报、支持原始输入事件上报。

- 支持处理网页与应用的互通，消息互通支持ArrayBuffer类型。

- 增强Web性能，支持渲染进程的只读数据段共享节省内存、支持预读动态库加速网页加载。


### 通信与连接

- 支持NFC卡读写能力。

- 支持蓝牙音频通话和蓝牙视频播放。

- 提供网络管理多网并发、网络协议栈http/https增强及TLSSocket ArkTS API能力。
  - 多网并发：
     - 支持基于socket的路由绑定。
     - 支持基于网卡的路由绑定。
  - http/https：
     - 支持http2.0。
     - 支持http缓存。
     - 支持http并发框架。
     - 支持gzip压缩、指定数据返回格式。
  - TLSSocket：
     - 支持客户端指定证书、密钥、CA等安全传输选项，向服务器发起连接，建立TLSSocket连接。
     - 支持TLSv1.2和TLSv1.3。
  - WebSocket。
  - 以太网连接、网络热点。

- 蜂窝通信框架能力（如需提供完整蜂窝通信能力需芯片厂商适配支持HDI接口）：
  - 支持双卡管理，双卡通话、短信、搜网等基础能力接口和框架。
  - 支持VoLTE语音通话接口和框架。（需要芯片厂商实现IMS服务（含HDI））
  - 支持IMS短信收发接口和框架。（需要芯片厂商实现IMS服务（含HDI））
  - 支持蜂窝数据漫游，蜂窝数据自愈接口和框架。
  - 支持双卡数据切换接口和框架。


### 设备管理

位置服务支持模糊位置、后台定位显性化等隐私增强特性。


 **DeviceProfile**

开放基础系统服务的KV数据的保存、查询、端端同步的能力。


 **电源**

- 支持从系统参数中读取系统的最大、最小和默认亮度值。

- 支持进入挂起状态和从挂起状态唤醒的系统接口。

- 支持电池的电量等级接口。

- 支持预估充电剩余时间、瞬时电流、剩余电量和总电量的系统接口。

- 支持相机、音频、通话和短距等软硬件特性的耗电统计。

- 支持设备发热时，对CPU频率、音量和系统亮度的管控动作。


### 安全

- 提供系统级的证书管理能力，支撑OpenHarmony生态应用和系统应用，实现证书管理全生命周期（生成，存储，使用，销毁）的管理和安全使用。

- 提供加解密算法库框架，实现对openssl加解密库对应能力的封装，提供统一的加解密算法库相关的ArkTS接口。

- HUKS支持国密SM2/SM3/SM4的部分算法。

- 提供基于帐号管理的分布式设备互信认证能力。


### 程序访问控制

- 实现应用和系统进程的权限管理框架，提供如下应用权限的操作接口：
  - 提供权限的校验、权限的授予、权限的撤销功能。
  - 提供权限的授权变化监听功能。
  - 提供拉起权限弹窗的接口，应用可以通过该接口拉起弹窗，向用户申请授权。

- 提供权限弹窗应用以及Setting应用的隐私权限管理功能。

- 提供隐私报告功能，支持添加/查询权限访问记录、监听权限使用状态变化接口。

- 提供隐私保护增强特性，提升用户的隐私保护体验，包括：
  - 相机使用提醒，在相机使用时，通知systemUI在右上角显示小圆点，提示用户。
  - 一键开关功能，提供用户一键开关，管控设备麦克风/相机敏感资源的使用。

- 提供SELinux功能的permissive模式。


### ArkCompiler

 **语言特性增强：**  支持严格模式的Ecma2021规范。

 **编译器运行时功能** 

- 提供es2abc编译器，优化字节码编译性能、缩短编译时间。

- 提供汇编解释器提升应用高级语言运行性能。

- 提供基于PGO配置文件的Host AOT优化编译器，提升应用高级语言高负载性能。

- 支持模块化能力，更好、更规范的支持复杂应用工程开发。

- 支持热补丁机制，提供应用热修复运行时技术底座。

- 调试增强，支持多实例调试、热重载调试，提升开发者开发效率。

- 支持基于CDP协议的CPU Profiler/Heap Profiler调优能力，提供应用性能调优和内存调优能力。

 **语言基础库** 

- utils功能增强，支持uuid提供通用统一标识符功能，支持Buffer提供缓冲区读写比较查找功能。

- Concurrent并发库增加并发API TaskPool基础版，提供并发任务接口。任务池（Taskpool）作用是为应用程序提供一个多线程的运行环境，降低整体资源的消耗、提高系统的整体性能。

 **C/C++工具链** 

- 工具链升级：LLVM升级到12.0.0，支持MIPS架构、RISC-V架构。

- 功能增强：支持stack pageguard保护，地址随机化，namespace隔离，CFI功能，Fortify功能，时区数据更新等，提升C/C++库安全。

- 性能优化：实现高频函数性能优化提升c库基础性能，实现linker优化提升库加载性能。

- 支持locale提供时区设置刷新功能。


### 内核

- 支持ASLR内核地址随机化、KASAN地址检测能力、CFI等，减少系统攻击面，提升内核安全性。

- 提升musl内存分配器安全，提高堆内存安全性，有效避免堆溢出、double-free、UAF等危险。

- 支持内存管理精细化管控，OnMemoryLevel特性针对不同内存压力进行通知，应用根据不同压力场景进行相应回调处理；同时对系统资源进行系统化、集中化管理，对应用资源占用及时监控与管理。

- 本地存储增强，F2FS特性优化末端性能，通过存储空闲时自动碎片回收、分级SSR等手段降低系统碎片，恢复系统性能。

### 驱动

 **HDF驱动框架能力** 
  
  - 支持内核态驱动动态加载、外接设备即插即用事件上报、驱动安全策略配置，为开发者提供更稳定、安全的驱动平台底座。
  
  - HDI接口支持IPC调用和直通调用两种通路模式，开发者可根据实际业务灵活使用，提升业务性能。
  
  - 支持HDI服务化代码自动生成能力、模板化驱动代码生成能力、HCS宏式解析及配置可视化编辑等能力，降低驱动开发门槛，提高开发效率。
  
  - Platform平台驱动支持用户态中断、新增CAN总线HDF驱动框架、MMC驱动实现优化等。

 **外设驱动模型能力** 
  
  - Camera驱动模型支持自拍镜像、镜头控制、JPEG位置信息添加、Sensor捕获角查询、人脸识别Meta流支持，简化相机驱动开发难度。
  
  - Audio的ADM模型增加耳机接入、听筒和喇叭切换控制、通话音量设置、通话静音等关键控制能力，支撑音频硬件生态拓展。
  
  - Display驱动模型支持多屏管理、软件Vsync机制、兼容FrameBuffer架构，支持不同显示架构高效接入。
  
  - 支持标准系统的Codec硬件编解码驱动模型、提供Codec HDI 2.0接口及参考实现，支持更完备的硬件编解码能力。
  
  - 支持马达驱动模型，包括马达振动启停、基础马达效果控制，为用户提供丰富的振感体验。
  
  - 支持手势驱动模型，包括状态事件、设备状态事件上报；支持手势启停、功能状态配置。
  
  - USB驱动模型支持设备模式和主机模式，新增支持设备模式下RNDIS网络驱动等DDK能力。
  
  - 支持WLAN驱动能力抗干扰能力，提供最优P2P信道选择能力，持续提升WLAN信号质量。

### 工具提升

 **DevEco Studio代码开发** 

- 支持应用/服务开发环境的诊断功能，能够检测开发环境是否完备，确保开发者拥有良好的开发体验。若检查结果中存在不满足的检查项，建议您根据修复建议进行调整。

- 提供基础模板和卡片模板，支持在基于Stage模型的应用中添加ArkTS卡片。

- 支持OpenHarmony工程添加Extension Ability模板，具体请参考在模块中添加Ability。

- 支持按照ArkUI新语法和新规范，检查代码提示错误；新增Code Linter代码检查功能，支持配置检查规则，修复检查结果。

- 支持C++代码Quick Fix基础能力，具体请参考代码Quick Fix快速修复。

- 提供全新的OHPM CLI（OpenHarmony Package Manager Command-line Interface） 生态三方库包管理工具，支持OpenHarmony共享包发布、安装和依赖管理。支持API 9的历史工程迁移为OHPM工程，详细参考历史工程手动迁移。

- 支持构建闭源HAR，并支持配置HAR的混淆能力。

- 支持AOT编译模式，提供高负载TS性能选择和构建能力，提升应用运行性能，具体请参考开启AOT编译模式。

- API 9的Stage工程默认开启模块化编译，可有效缩短增量编译时间、减小编译后的包体积。

- 支持并发编译提升编译速度。

 **DevEco Studio应用调试调优** 

- 支持ArkTS/JS与C/C++跨语言调试特性，在C/C++工程中，采用ArkTS/JS与C/C++进行混合开发，能够在ArkTS或JS调用C/C++方法处，直接进入C/C++代码中进行调试，方便开发者快速发现并解决跨语言调用相关代码问题。具体请参考ArkTS/JS与C/C++工程跨语言调试。

- 支持Hot Reload热重载，支持保存代码后在真机上使用最新的代码而无需重启应用。

- 支持OpenHarmony多包推送和多实例调试功能。

- 支持OpenHarmony API 9 C/C++工程的内存错误检测。

- OpenHarmony日志功能支持打印FaultLog，便于应用开发者快速查询、定位、导出应用故障信息。

- 测试框架能力增强，针对JS/ArkTS API Version 8和9的工程，测试框架的执行效率显著提升；同时优化了测试框架模板，提升模板代码的可读性。

详细内容请参考[DevEco Studio版本说明](https://developer.harmonyos.com/cn/docs/documentation/doc-releases/release_notes-0000001057597449)及[使用指南](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ide_versions_overview-0000001356521213)。


 **调试工具** 

- hdc文件传输支持目录接收发送、权限同步、同网段CS文件发送，提升调试调优、自动化测试效率。


### 测试能力

- 新增测试用例筛选执行能力，支持在用例中配置指定字段如用例类型、级别等参数，通过命令执行筛选后的用例，帮助开发者提升测试执行效率，详细请参考[指导](https://gitee.com/openharmony/testfwk_arkxtest#%E5%9F%BA%E7%A1%80%E6%B5%81%E7%A8%8B)。

- 新增测试用例驱动执行能力，可将相似测试逻辑的不同输入输出数据配置到辅助文件中使用，帮助开发者减少测试代码量，详细请参考[指导](https://gitee.com/openharmony/testfwk_arkxtest#%E6%95%B0%E6%8D%AE%E9%A9%B1%E5%8A%A8)。

- 新增多窗口、双指捏合、抛滑等UI场景模拟操作能力，提升UI自动化支持范围，详细请参考[API说明](../application-dev/reference/apis/js-apis-uitest.md)。

- 新增OpenHarmony应用质量要求兼容性测试规范，涵盖UX、性能、功耗、稳定性、兼容性和安全六大方面，规范OpenHarmony应用基础质量要求，详细请参考[官网说明](https://www.openharmony.cn/certification/moreStandard)。

- [SmartPerf-Host](https://gitee.com/openharmony-sig/smartperf/tree/master)性能功耗调试调优工具，为开发者提供一套性能调优平台，支持GUI（图形用户界面）操作进行详细数据分析。3.2版本新增：
  - 支持功耗分析能力，展示应用各子类别功耗占比信息、资源申请使用记录、功耗异常事件、功耗与系统状态关联信息，详细请参考HiSystemEvent[指导](https://gitee.com/openharmony-sig/smartperf/blob/master/host/ide/src/doc/md/quickstart_hisystemevent.md)。
  - 支持Web端抓取trace，详细请参考[指导](https://gitee.com/openharmony-sig/smartperf/blob/master/host/ide/src/doc/md/quickstart_web_record.md)。
  - 支持SQL查询和Metrics说明，详细请参考[指导](https://gitee.com/openharmony-sig/smartperf/blob/master/host/ide/src/doc/md/quickstart_sql_metrics.md)。
  - 支持内核内存事件分析，详细请参考[指导](https://gitee.com/openharmony-sig/smartperf/blob/master/host/ide/src/doc/md/quickstart_page_fault.md)。

- [wukong](https://gitee.com/openharmony/ostest_wukong)软件稳定性工具能力增强：
  - 支持注入滑动、鼠标、字符、系统按键、控件事件，模拟用户多样化随机操作，覆盖真实用户操作场景，挖掘更多稳定性问题。
  - 支持设置运行总时长、应用黑白名单，实现个性化测试。
  - 支持控件顺序遍历测试，测试过程中支持界面截图；支持休眠唤醒测试。

## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.2 Release | NA |
| Public SDK | Ohos_sdk_public 3.2.11.9 (API Version 9 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
| HUAWEI DevEco Studio（可选） | 3.1 Release | OpenHarmony应用开发推荐使用。获取方式：<br /> [Windows(64-bit)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/16/v3/YO_7mAQNTbS8jekrvez5IA/devecostudio-windows-3.1.0.500.zip?HW-CC-KV=V1&HW-CC-Date=20230512T073650Z&HW-CC-Expire=315360000&HW-CC-Sign=90814E421B9A6D8DB4757FAFC21A965CF890A387DF9A2633B4AB797AD77E6485) <br />[Mac(X86)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/d8/v3/zRt_WN3iRZiJ6nmb0mII2g/devecostudio-mac-3.1.0.500.zip?HW-CC-KV=V1&HW-CC-Date=20230512T073549Z&HW-CC-Expire=315360000&HW-CC-Sign=11DF6C7F2EE8C5CA5F5F44CE7441EBF2E24824FC7ECD5D961329C9575A8326AF) <br />[Mac(ARM)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/7d/v3/EEGHWfBmR_29a-xjAQJZqA/devecostudio-mac-arm-3.1.0.500.zip?HW-CC-KV=V1&HW-CC-Date=20230512T074142Z&HW-CC-Expire=315360000&HW-CC-Sign=92C9A7380140C8363D6B853A3898B31674144C2C809ED47F154EC450B714DBC0) |
| HUAWEI DevEco Device Tool（可选） | 3.1 Release | OpenHarmony智能设备集成开发环境推荐使用。<br />[点击此处获取](https://device.harmonyos.com/cn/develop/ide/) |

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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 3.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Release/code-v3.2-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Release/code-v3.2-Release.tar.gz.sha256) | 21.8 GB |
| Hi3861解决方案（二进制）        | 3.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Release/hispark_pegasus.tar.gz.sha256) | 22.9 MB |
| Hi3516解决方案-LiteOS（二进制） | 3.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 294.3 MB |
| Hi3516解决方案-Linux（二进制）  | 3.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Release/hispark_taurus_Linux.tar.gz.sha256) | 174.3 MB |
| RK3568标准系统解决方案（二进制）        | 3.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Release/dayu200_standard_arm32.tar.gz.sha256) | 3.9 GB |
| 标准系统Public SDK包（Mac）             | 3.2.11.9      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Release/ohos-sdk-mac-public.tar.gz.sha256) | 712.7 MB |
| 标准系统Public SDK包（Mac-M1）             | 3.2.11.9      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 671.1 MB |
| 标准系统Public SDK包（Windows/Linux）   | 3.2.11.9      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.6 GB |

## 更新说明

本版本在OpenHarmony 3.2 Beta5的基础上有如下变更:

### API 

API变更请参考:
- [*OpenHarmony 3.2 Release相比3.2 Beta5的API差异报告*](api-diff/Beta5%20to%20v3.2-Release)
- [*OpenHarmony 3.2 Release相比3.1 Release的API差异报告*](api-diff/v3.2-Release)

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

### Samples

  **表3** 新增Samples

| 子系统 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| 无障碍 | [AccessibilityExtensionAbility示例](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/AccessibilityExtAbility) | 本示例展示了AccessibilityExtensionAbility的简单应用，使用多个辅助功能接口实现了一些快捷的交互方式。 | ArkTS |
| 企业管理 | [企业设备管理ExtensionAbility](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/EnterpriseAdminExtensionAbility) | 企业设备管理扩展能力，是MDM应用必备组件。当开发者为企业开发MDM（Mobile Device Management）应用时，需继承EnterpriseAdminExtensionAbility，在EnterpriseAdminExtensionAbility实例中实现MDM业务逻辑，EnterpriseAdminExtensionAbility实现了系统管理状态变化通知功能，并定义了管理应用激活、去激活、应用安装、卸载事件等回调接口。 | ArkTS |
| 任务管理 | [任务延时调度](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/WorkScheduler) | 本示例使用\@ohos.WorkSchedulerExtensionAbility 、\@ohos.net.http 、\@ohos.notification 、\@ohos.bundle 、\@ohos.fileio 等接口，实现了设置后台任务、下载更新包 、保存更新包、发送通知 、安装更新包实现升级的功能。 | ArkTS |


请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。


## 修复缺陷列表

  **表4** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| I6ATXO | 【RK3568】XTS执行测试，OpenGL测试套执行结果存在失败项 |
| I6BJ9Z<br/>I6BJ82 | alloc_file_pseudo 内存泄漏问题跟踪 |
| I6BRTS | 调用rdb::executeSql接口会引起内存泄漏风险 |
| I6AZ4T | 带textinput输入框组件的应用存在内存泄漏风险 |


## 遗留缺陷列表

  **表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I6AB3T | 首次启动联系人应用的用时超出预期基线。 | 设备启动后，联系人进程为非常驻进程，启动联系人应用时需要拉启联系人数据库进程导致有时延偏长。 | 遗留挂起 |
| I6SMQA | 浏览器加载微博，滑动过程中出现抖动。 | 通过浏览器加载微博web网页后，快速滑动时，内容会闪现未加载，然后很快能加载出来，影响滑动体验。 | 2023年5月15日 |
| I6TRE6 | 进程com.ohos.contacts下的com.ohos.contacts线程导致libdatashare_consumer.z.so低概率出现crash。 | 联系人应用快速启动和退出场景，发现在启动后600ms内退出，联系人进程低概率出现crash，出现crash后联系人进程会被重新拉起，影响可控。 | 2023年4月30日 |
| I6SXBI | wukong的ohos.samples.distributedcalc进程下的libdistributeddata.z.so低概率出现cppcrash。 | 计算器应用快速启动和退出场景，启动后1秒内退出，计算器应用低概率出现cppcrash，出现crash后计算器进程会被重新拉起，影响可控。 | 2023年4月30日 |
| I6U00Q | RK3568使用3.5mm耳机播放音频文件，存在pop音。 | 影响设备使用体验，影响可控。 | 2023年5月30日 |
| I6TNY9 | 通话记录处于充满记录的状态时，向上滑动时拨号键盘无法隐藏。 | 影响拨号键盘的隐藏体验。 | 2023年4月30日 |
| I6TOTV | tabs组件中tabs_animation在反复切换过程中，两种颜色同时显示在界面。 | tabs_animation在反复切换场景下，影响tabs组件的颜色显示。 | 2023年4月30日 |
| I6TOV2 <br/>I6TOYV <br/>I6TOQO <br/>I6TOK5 | WiFi或BLE组网引导P2P循环发送100次linktype为stream的通路，会概率性失败。 | WiFi组网引导P2P压测100次，成功率大于80%。而在低概率P2P组网失败后，重新触发组网时高概率能成功，影响可控。 | 2023年5月30日 |
| I6TMP3 | 长按应用进入图片预览，向后滑动150张卡片左右，点击添加卡片，桌面不显示卡片。 | 图片较多的场景下，进入图形预览，添加卡片，桌面概率不显示卡片，影响使用体验，影响可控。 | 2023年4月30日 |
| I6B4U3 | 压力测试出现进程com.ohos.launcher出现appfreeze。 | 安装应用较多（测试场景安装超过40个应用），且内存较小的设备场景下，低概率出现appfreeze，但桌面功能正常，不影响整体功能和使用。 | 2023年5月30日 |
| I64726 <br/>I641A2 | 蓝牙功能接口bluetooth.pairDevice在与其他设备配对时无配对提示，与其他设备静默配对后通过蓝牙键盘、鼠标完全可控制设备。 | 无配对弹窗提示，但能配对成功，不影响软总线的配对组网功能，已在新版本规划需求完成对此功能的支持。 | 2023年6月30日日 |
| I6U1H9 | GridCol的属性 gridColOffset 在预览器未包含。 | 影响预览inspector的属性显示，不影响预览器整体效果。 | 2023年4月30日 |
