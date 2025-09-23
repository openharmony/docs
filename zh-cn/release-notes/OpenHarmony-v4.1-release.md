# OpenHarmony 4.1 Release


## 版本概述

OpenHarmony 4.1 Release版本标准系统能力持续完善。相比OpenHarmony 4.0 Release版本做出了如下特性新增或增强：

新增4000多个API，应用开发能力更加丰富；应用开发的开放能力以Kit维度呈现，提供给开发者更清晰的逻辑和场景化视角；ArkUI组件开放性和动效能力、组件能力和效果得到进一步增强；Web能力持续补齐，便于开发者利用Web能力快速构建应用；图形窗口增强了动效和窗口适配能力；应用框架增强了Extension能力；分布式能力进一步增强了组网稳定性、连接安全性，分布式软总线连接能力和规格进一步增强等；媒体支持更丰富的编码，支持更精细的播控能力，进一步增强音频/相机框架的能力；测试框架多个工具能力增强等。欢迎开发者踊跃使用并给我们提出宝贵意见。

OpenHarmony 4.1 Release版本为API Level 11的正式Release版本。

更详细的特性新增与增强的说明如下：


### SDK

SDK提供的开放能力以Kit维度呈现给开发者。开发者可按Kit查找和使用能力特性，使用场景化的开放能力，体验更清晰的编程逻辑。

与此同时，开发指南和API参考也已按照Kit粒度进行罗列，方便开发者对Kit进行更进一步的了解和使用。


### ArkUI

- 新增NodeContainer开放命令式的渲染节点，提升自定义绘制能力。

- 文本和容器类组件能力增强：
   - TextInput/Text支持按字符截断。
   - TextInput和TextArea提供获取光标位置接口。
   - 支持智能分词、新增依据分词结果插入光标逻辑以及替换分词算法。
   - ImageSpan支持自定义长按菜单事件、控件支持缩进/对齐。
   - List：ScrollToIndex支持滚动到ListItemGroup中指定ListItem的能力。
   - TextArea支持定制回车键行为。
   - Swiper组件支持嵌套滚动。
   - Grid/WaterFlow组件支持列表项滑动到指定位置并有过渡动画。
   - 滚动类组件支持在内容区域不满一屏时使能回弹效果。

- 控件接入AI能力增强：
   - TextInput及相关文本输入控件支持视觉输入。
   - Text/RichEditor相关文本控件支持文本实体识别。

- 状态管理功能增强：
   - 支持undefined和null，以及联合类型。
   - ListItem组件在ForEach/LazyForEach中属性可更新方法。
   - 支持@LocalStorageLink/LocalStorageProp 在非激活状态不更新。

- 新增Chips操作块组件，TextInput、TextArea、List、Grid、Search、CheckBox、Slider、Image、Menu、半模态弹窗等组件的样式、交互和动效增强。

- 弹窗类和导航类组件自定义能力增强：
   - 支持开发者自定义弹出菜单的圆角、阴影、气泡箭头。
   - bindContextMenu支持isShow参数控制显隐。
   - Navigation支持隐藏NavBar。
   - Navigation组件提供获取路由栈每个页面详细信息，支持根据页面信息销毁或显示页面。

- 提供全新Style样式对象和组件Style样式属性方法，支持样式复用和动态切换能力，包括：
   - 通用属性样式支持Style样式对象。
   - 组件特有属性样式支持Style样式派生对象。
   - 多态样式切换到Style样式对象。 


### 应用框架

- 应用正常退出时会清理temp目录，提升安全性并减少系统存储空间消耗。

- Extension管控能力增强：新增了ServiceExtension的后台管控以及统一超时机制。

- ArkTS卡片能力增强：新增了透明卡片、数据代理刷新、单色模式和锁屏卡片能力。

- 提供Autofill自动填充框架，系统应用可以通过该框架来实现密码保险箱等功能为用户提供免密登录功能。

- 支持通过Context获取resFile资源目录，提升应用开发便利性。

- 增强UIExtension能力：提供SetReceiveDataForResultCallback接口及其同步回调；提供StartAsCaller接口；支持多实例。

- 启动UIAbility和UIExtension时，支持Uri批量授权。

- 支持应用定制系统环境参数，应用可选择是否跟随系统配置更新变化显示效果。

- 支持意图框架能力，支持UIAbility、UIExtension、ServiceExtension等绑定意图。

- 支持在import时引入abc文件。

- 增强卡片能力：支持卡片点击回调；支持卡片点击跳转deeplink；支持查询未使用的卡片；新增锁屏卡片尺寸的规格；支持锁屏卡片设置为单色模式；支持状态保存及恢复能力，提供更好的显示接续效果。


### 应用包管理

- 系统级HSP支持OTA升级。

- 新增了模块化开发包大小优化指导。

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

- 构建软总线传输QoS接口能力，更优管控底层链路资源并提供选路决策，提升分布式业务体验。

- 连接能力和规格进一步增强，如：支持P2Pv2协商；支持按业务策略的被动发布；链路选择增加连接可靠性确认能力；支持感知资源情况并动态设置连接参数。

- 完成子系统DFX机制增强，如：支持业务流程打点、支持上层分布式业务统计以及支持对组网监控事件进行业务告警。

- IPC支持引用计数查询和时间戳查询的接口，以及维测能力增强。


### 分布式数据管理

- UDMF支持数据类型标准化定义与描述、支持标准数据类型查询、支持数据访问授权与管理、支持应用自定义数据类型。

- 新增限制数据不打分类分级标签则不允许跨设备同步。

- preferences支持uint8Array格式数据流的修改、查询和持久化。

- RDB支持在应用指定的沙箱路径子目录下创建数据库。


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

- 系统支持可变帧率，提供API供业务接入。

- 图形NDK能力增强，支持为NativeImage添加OnFrameAvailableListener回调，支持为NativeWindow设置色域，新增支持opengles扩展接口，Drawing能力进一步完善等。

- 支持录屏不录制特定窗口，以及隐私窗口录制成全黑帧画面的能力。

- 支持调整系统分辨率。

- 支持系统根据动画调节帧率，支持开发者调节应用业务帧率。

- 动效能力增强，支持硬件挖孔，屏幕圆角，Navigation导航转场动画支持共享元素等。

- 图形渲染管线支持vulkan后端。

- 图形接入Drawing接口。

- nativeWindow支持设置metadata，适配HDR视频场景动态元数据随帧传递。

**窗口**

- 提供Window stage可交互状态通知。

- 提供全局搜索窗口类型。

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

**音视频**

- 支持通话类应用接入媒体会话。

- 支持投播组件的颜色自定义和状态监听。

- 媒体播控支持展示应用历史专辑、歌单信息。

- 支持音频低时延多流并发播放，以及动态调整回调频率和数据量。

- 支持音频低时延录制。

- 支持音乐、听书类应用音频低功耗播放。

- 提供音振协同能力，支持音频及振动流的精准同步播放。

- 新增支持amr/MKV解封装，支持amr解码。

- 支持获取音视频文件媒体信息。

- 视频框架优化，减少资源占用，使用AVBuffer支持全流程数据处理，支持零拷贝。

- 新增数字版权管理（DRM）支持，支持DRM插件管理，支持证书请求及处理，支持许可证请求及处理，支持DRM节目的解密。

- 支持蜂窝网络通话时进行录音。

- 支持音振协同。新增振动HDI接口，可查询设备振动信息；新增震动类型和时延字段的设置接口；支持高清振动的数据下发。

**图像**

- 支持.ico图片解码。

- svg格式支持颜色设置和css解析。

- 支持解码时完成sRGB和P3色域转换。

**媒体库**

- 支持媒体数据对象化读写接口。

- 支持快速、平衡、高质量等多种访问模式。

**相机**

- 提供相机NDK接口，支持应用对相机数据做二次加工处理。

- 提供CameraPicker，支持应用直接唤起或集成相机拍照和录像功能，简化三方使用相机。

- 相机基础控制能力增强，包括平滑变焦、手电筒等能力。

- 优化相机性能，提升前后置切换、拍照与录像切换的流畅性。

- 支持相机框架及应用完成从当前变焦值平滑过渡到目标变焦值的能力。

- 支持手电筒打开关闭控制、手电筒可用通知、手电筒状态变化通知。

- 支持运动防抖模式，达成在录像过程中图像稳定。

- 支持相机扫码模式，支撑扫码服务业务功能。

- 支持底层识别系统状态（如跌落状态），使相机的相对脆弱器件（如光圈）可在手机跌落状态时关闭，对其进行保护。


### 事件通知

- 支持系统应用发送实况窗类型的通知。

- Emitter：支持订阅字符串类型事件；发送事件时传递的数据支持可序列化类型；支持获取订阅者数量。

- 支持应用只接收自身发布的自定义公共事件。

- 支持设置为每周重复提醒。

- 支持同一个日程下的同组提醒按groupId统一取消。

- 支持通知按钮自动多语言切换。通过设置按钮资源ID，可实现通知到达后，提醒内的按钮标题语言依据系统环境语言自动切换。


### 公共基础类库

- 支持在HAR/HSP中创建Worker。

- TaskPool支持在执行过程中往宿主线程发送消息。


### 通信与连接

- NFC提供HCE卡模拟能力。

- NFC支持默认支付应用的配置能力。

- Wi-Fi提供热点类型的查询，可查询当前连接热点是否为手机热点。

- Wi-Fi作为热点支持将接入的STA设备添加到黑名单的能力。

- 蓝牙支持BLE广播的动态启停，支持MDM调用蓝牙接口强制关闭蓝牙功能，并限制开启蓝牙；支持查询设备是否处于可发现状态；支持根据设备地址获取设备的配对状态。


### 位置

- 支持地理编码，逆地理编码，查询地理编码服务状态等接口。

- 支持通过sendCommand接口删除辅助数据，用于支持冷热启动测试。

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

- 对DisplayPowerManager的代码结构进行了调整，亮度管理功能模块变为独立的模块。

- 新增支持设备关机状态下充电动画显示，充电电量可变化更新。

- 支持驱动上报事件并触发对应动作的执行。

- 支持查询和上报应用持有CPU锁信息。可通过电源服务的接口回调或hisysevent上报应用持有CPU锁的情况，同时可调用接口查询应用持有CPU锁的情况。支持Nap服务订阅上述信息。


### 安全

- 密钥管理支持“设置密码时有效”的访问控制方式。

- 证书管理：支持开放用户ca证书路径。

- 证书算法库框架：支持证书链校验和吊销检查能力、支持证书链构造的能力。

- 加解密算法库框架支持PBKDF2算法、支持对称密钥可选AAD参数、支持可变长度密钥HMAC、支持DH/25519算法、支持brainpool曲线、支持SM2密钥解析和参数处理能力、支持基于曲线名的密钥生成能力。

- 新增应用私有证书凭据管理接口支持指定签名填充方式和Hash算法。


### 用户IAM

- 支持清理冗余用户身份凭据。

- 支持认证失败振动反馈。

- 支持动态指纹禁用功能。


### 程序访问控制

**权限管理**

- 支持在UIExtensionAbility界面上拉起权限弹窗。

- 权限使用记录增加锁屏状态记录

- 支持应用在使用期间弹出允许权限的选项。

### ArkCompiler

- 动态import能力支持变量作为参数。

- 提供运行时对类方法插桩和替换的API。

- 支持用“#”声明类的私有成员。

- 支持Sendable类的跨线程序列化传输。

- TSC版本升级，从4.2.3升级到4.9.5

- 优化ArkTS应用的增量编译速度

- 混淆功能增强: 支持文件名称和文件夹名称混淆，支持声明文件注释删除，支持导出对象的名称及其属性名称的混淆。

- libc: 安全加固dlopen, dlclose等接口，支持多线程重入功能。优化部分高频使用的C标注库接口性能。DK中增加随机数arc4random*，回栈相关backtrace，共享内存shm_open，shell模式匹配wordexp等lib接口，新增对头文件execinfo.h queue.h cdefs.h的支持。

- C++调试:优化应用启动和so加载等场景的调试速度。支持Standalone lldb调试。

- SmartGC支持90帧场景，支持对性能高度敏感的场景的GC控制。

- Taskpool支持中断退出线程，支持精准import导入，支持默认transfer机制。

- 提供C++的异常捕获机制。


### 内核

支持内核树外独立构建ko模块能力，并提供独立ko分区chip_ckm。


### 资源管理

- 支持module.json配置文件中通过右键菜单添加资源索引。

- 支持对resfile资源目录打包编译。

- 支持基于资源名称返回资源id。


### USB

- 补齐USB服务设备管理能力，支持全设备、按设备类型、指定设备的禁用和解禁，并支持重启、热插拔场景下的禁用策略持久化能力。

- 优化USB服务鉴权方式，新增访问控制权限，细化系统服务、系统应用的USB调用权限。

- 修复USB服务批量传输、控制传输的接口漏洞，支持传输接口端到端可用，性能满足要求。


### 多模输入

- 支持双击按压电源键拉起Ability。

- 支持自定义鼠标光标。

- 多模输入设置鼠标样式优化。

- 支持按键监听按优先级处理的能力。

- 支持光标大小、颜色的设置，支持动画光标样式。

- 新增接口支持自定义光标交互坐标和更新鼠标显示位置的注入功能。

- 支持按键监听按优先级处理的能力。

- 支持鼠标指针热区检测功能。

- 支持双指捏合、旋转手势的识别。

- 支持三指轻点手势识别。

- 支持全局组合键的管理和监听功能。


### 泛Sensor

- 支持传感器数据精度的上报，使系统可感知不同设备传感器精度，优化应用适配。

- 新增传感器、振动相关能力的C API接口。

- 自定义振动格式进行扩展，新增支持curve字段描述复杂的连续振动效果。

- 支持传感器和触觉控制的Native API接口。

- 支持上报设备折叠状态、空间音频头部姿态数据等。

- 支持振感的动态静态调节。

- 支持触觉控制的开关。


### 设备管理

小型设备平台上支持\@ohos.deviceInfo.d.ts的相关API。


### 测试框架

**自动化测试框架arkxtest**

- 支持模拟鼠标滚轮滑动、滑动左右键双击等模拟UI操作能力。

- 支持Shell命令方式进行UI模拟操作能力，支持点击、滑动、双击、文本输入等常用操作能力。

- 提升UI测试框架查找控件信息效率。

- 增强dump信息内容，新增文字大小、文字颜色信息。

- 增加异步监听能力，监听系统弹框事件，获取其文本信息并返回。

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

- 提供CPU、GPU、内存、IO、网络、trace采集能力。

- 故障类型数据生态开放。

- HiDebug支持应用运行时资源信息采集。

- HiProfiler支持高功耗应用在CPU、GPS、AUDIO、DISPLAY、GPU的深入调优；支持动效场景耗时分析（启动、退出、转屏、转场、滑动）；支持ftrace数据轻量化采集。

- HiProfiler/HiDumper联合提供内存进程扩展内存信息的采集与增强。

- HiTrace支持轻量化及长时间采集。

- HiPerf支持符号解析和栈聚合能力。

- 提升功耗异常的识别速度与准确度，主要器件的耗电相关信息更丰富，易于问题定位.对应用导致的器件耗电异常场景，可对器件的耗电使用进行深度分析。

- 支持系统内存详情采集插件，用于ION，GPU/Skia，purgeable内存信息的采集（hidumper hiprofiler）。

- 支持动效场景耗时分析，可采集动效（启动、退出、转屏、转场、滑动）设置的信息数据、动效起止打点、以及和图形帧关联。


### 上传下载

- 支持多个前端模式任务与后台模式任务共享任务数量的能力。

- 支持监听后台任务的状态和进度。

- 支持任务的优先级，同样是前端（或者后台）模式的任务，也可以使用优先级来调整执行顺序。

- 自动使用系统级代理。

- 支持上传场景返回超过IPC限制的Response Body。

- 支持文件片段上传。

- 支持后台任务进度更新及状态变化的回调。

- 支持上传下载任务状态变化事件的上报。

- 应用或后台Service Ability重启后可以继续操作上传下载任务。

- 支持优先级策略：高优先级应用（焦点应用）的高优先级任务优先执行并且占据跟多网络带宽资源。


### 输入法框架

- 优化了Webview获焦场景的输入法体验。

- 优化了窗口焦点切换场景下的输入法体验。

- 新增支持安全模式输入法。

- 新增支持Logo键+Space切换输入法。

- 新增输入法切换列表控件。

- 支持输入法应用代理功能​。

- 支持输入法框的视觉输入。

- 提供查询输入法窗口显示状态的接口。

- 支持系统安全键盘。


### 时间时区

- 支持通过系统参数配置NTP服务器地址，最多支持配置5个。

- 支持通过系统参数配置时间时区自动同步开关。

- 支持感知用户配置开关。

- 支持自定义NTP服务器。


### 全球化

- 支持设置和获取应用偏好语言。

- 支持文本时间和电话号码格式的识别。

- 支持日期快速计算。

### AI

- MindSpore Lite轻量化端侧学习能力开放C API。

- 新增Native的设备端侧的AI训练接口。

- 新增配置NNRt后端的ArkTS接口。


### 升级

- 支持差分多线程升级的能力。

- 增加升级过程中硬件故障重试机制，提升升级可靠性。

- 正常模式下的语言参数能同步更新到升级阶段使用的updater简化系统中。


### Web

- 新增支持Web的无障碍节点查询和上报能力。

- 新增页面跳转事件上报接口。

- 支持应用及网络代理、应用证书管理。

- 支持同层渲染能力（仅限xcomponent、button等部分组件）。

- 组件支持DOM构建完成后执行提前被注入的JS脚本。

- 开放RegisterJavaScriptProxy、RunJavaScript能力的C API。

- 资源拦截特性支持设置为ArrayBuffer数据类型。

- 完善WebRTC能力，支持入会、共享、发言、摄像头等能力。

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
| OpenHarmony | 4.1 Release | NA | 
| Public SDK | Ohos_sdk_public 4.1.7.5 (API Version 11 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。 | 
| HUAWEI DevEco Studio（可选） | 4.1 Release | OpenHarmony应用开发推荐使用。获取方式：<br />[Windows(64-bit)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/ee/v3/HqJ-6O2FQny86xtk_dg9HQ/devecostudio-windows-4.1.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20240409T033730Z&HW-CC-Expire=315360000&HW-CC-Sign=BFA444BC43A041331E695AE2CFA9035A957AF107E06C97E793FD3D31D7096A0D)  <br />SHA256校验码：c46be4f3cfde27af1806cfc9860d9c366e66a20e31e15180cf3a90ab05464650<br />[Mac(X86)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/3b/v3/JgGp8n0bShOkm1MpBFJ73w/devecostudio-mac-4.1.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20240409T034037Z&HW-CC-Expire=315360000&HW-CC-Sign=35C1F8B3FC19325EBBC32D8E11106DDB074A8ECC6BB3A77FF2EADBA2A8A223DA)  <br />SHA256校验码：15d6136959b715e4bb2160c41d405b889820ea26ceadbb416509a43e59ed7f09<br />[Mac(ARM)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/21/v3/D7Jy1StbTwSLUXaA20VrAw/devecostudio-mac-arm-4.1.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20240409T034235Z&HW-CC-Expire=315360000&HW-CC-Sign=19598AAC650D2AB24CAC6DFDF0DBD312188FB0438A8233B7687E6ACDC43A51F8)  <br />SHA256校验码：ac04ca7c2344ec8f27531d5a59261ff037deed2c5a3d42ef88e6f90f4ed45484 | 
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Release/code-v4.1-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Release/code-v4.1-Release.tar.gz.sha256) | 31.6 GB |
| Hi3861解决方案（二进制）        | 4.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_pegasus.tar.gz.sha256) | 29.2 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 318.7 MB |
| Hi3516解决方案-Linux（二进制）  | 4.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Release/hispark_taurus_Linux.tar.gz.sha256) | 215.8 MB |
| RK3568标准系统解决方案（二进制）        | 4.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| 标准系统Public SDK包（Mac）             | 4.1.7.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Release/ohos-sdk-mac-public-signed.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Release/ohos-sdk-mac-public-signed.tar.gz.sha256) | 1.1 GB |
| 标准系统Public SDK包（Mac-M1）             | 4.1.7.5  | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Release/L2-SDK-MAC-M1-PUBLIC-signed.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Release/L2-SDK-MAC-M1-PUBLIC-signed.tar.gz.sha256) | 1.1 GB |
| 标准系统Public SDK包（Windows/Linux）   | 4.1.7.5   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |


## 更新说明

本版本在OpenHarmony 4.1 Beta1的基础上有如下变更。

### API变更

- OpenHarmony 4.1 Release相比4.1 Beta1的API差异请[点击这里查看](http://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Release/zh-cn/release-notes/api-diff/v4.1-Release-vs-v4.1-beta1/Readme-CN.md)。
- OpenHarmony 4.1 Release相比4.0 Release的API差异请[点击这里查看](http://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Release/zh-cn/release-notes/api-diff/v4.1-Release-vs-v4.0-Release/Readme-CN.md)。

此外，从4.1 Beta1至今，有少量接口变更可能影响此前应用工程的兼容性或需要您关注，详细的变更说明请[点击这里查看](http://gitee.com/openharmony/docs/blob/OpenHarmony-4.1-Release/zh-cn/release-notes/changelogs/v4.1-Release/Readme-CN.md)

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。


## 修复缺陷列表

**表4** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| -------- | -------- |
| [107](https://gitcode.com/openharmony/applications_mms/issues/107) | 进程com.ohos.mms有一定概率出现因为LIFECYCLE_TIMEOUT导致的sysfreeze问题。 |
| [152](https://gitcode.com/openharmony/communication_bluetooth_service/issues/152) | 进程bluetooth_servi下的OS_IPC_10_25363线程有一定概率出现因libbluetooth_server.z.so导致的cppcrash。 |
| [639](https://gitcode.com/openharmony/distributeddatamgr_relational_store/issues/639) | 进程com.ohos.settingsdata下的os.settingsdata线程小概率出现因libnative_appdatafwk.z.so导致的cppcrash。 |
| [884](https://gitcode.com/openharmony/communication_netmanager_base/issues/884) | 进程foundation由于SERVICE_BLOCK小概率出现因netsysnative导致的sysfreeze。 |
| [119](https://gitcode.com/openharmony/applications_systemui/issues/119) | 进程com.ohos.systemui有一定概率出现由于THREAD_BLOCK_6S卡在libsamgr_proxy.z.so导致的appfreeze。 |
| [2468](https://gitcode.com/openharmony/kernel_linux_5.10/issues/2468)等43个开源组件漏洞 | 内核errseq_set函数protection_fault 等43个开源组件漏洞。 |
| [211](https://gitcode.com/openharmony/vendor_hihope/issues/211) | RK3568 kernel patch中的maligpu版本过旧（11.29），存在大量未修复CVE漏洞。 |
| [246](https://gitcode.com/openharmony/applications_settings/issues/246) | 进入设置反复打开关闭蓝牙，有一定概率会导致设置出现appfreeze。 |
| [471](https://gitcode.com/openharmony/communication_bluetooth/issues/471) | 进入设置反复打开关闭蓝牙开关会出现内存泄漏，经测试一个小时泄露15MB。 |
| [251](https://gitcode.com/openharmony/applications_settings/issues/251) | 进入设置反复打开关闭蓝牙开关出现内存泄漏，经测试“设置”一个小时内存涨幅到180M。 |



## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| [100](https://gitcode.com/openharmony/applications_launcher/issues/100) | 移动桌面一个图标使之与另一图标重叠创建大文件夹，之后选中文件夹内的一个应用移出文件夹，重复此操作，launcher出现内存泄露，操作五分钟，内存泄漏约25M，操作一次泄露约673.68KB。 | 泄漏达到一定程度后造成系统卡顿。<br/>规避措施：清理后台应用或重启可释放。 | 4月30日 |
| [120](https://gitcode.com/openharmony/applications_settings/issues/120) | 点击设置里的位置信息开关，重复此操作，distributeddata进程出现内存泄露，操作五分钟，泄露约14M，操作一次泄露约95.57KB。 | 泄漏达到一定程度后造成系统卡顿。<br/>规避措施：退出当前界面内存可释放。 | 4月30日 |
| [63](https://gitcode.com/openharmony/applications_mms/issues/63) | 不停执行点击短信界面右上角新建短信和返回操作，5分钟短信应用内存上涨约50M，操作一次泄露约341.33KB。 | 泄漏达到一定程度后造成系统卡顿。<br/>规避措施：退出应用内存可释放。 | 4月30日 |
| [346](https://gitcode.com/openharmony/communication_bluetooth/issues/346) | 小概率在进程bluetooth_servi下的Stack线程出现cppcrash，崩溃栈：libbtstack.z.so。 | 蓝牙服务出现异常后服务自动恢复，用户无异常感知。 | 4月30日 |
| [339](https://gitcode.com/openharmony/communication_bluetooth/issues/339) | 小概率在进程bluetooth_servi下的SaInit1线程出现cppcrash，崩溃栈：libbtstack.z.so。 | 蓝牙服务出现异常后服务自动恢复，用户无异常感知。 | 4月30日 |
| [338](https://gitcode.com/openharmony/communication_bluetooth/issues/338) | 小概率在进程softbus_server下的softbus_server线程出现cppcrash，崩溃栈：libbtframework.z.so。 | 软总线服务出现异常后服务自动恢复，用户无异常感知。 | 4月30日 |
| [143](https://gitcode.com/openharmony/applications_settings/issues/143) | 小概率在进程com.ohos.settings下出现jscrash，栈名：ObservedPropertyAbstractPU。 | settings应用小概率出现闪退，退出应用内存可释放。 | 4月30日 |
| [104](https://gitcode.com/openharmony/communication_bluetooth_service/issues/104) | 小概率下进程com.ohos.settings由于THREAD_BLOCK_6S卡在libbtframework.z.so发生appfreeze。 | settings应用小概率出现闪退，退出应用内存可释放。 | 4月30日 |
| [104](https://gitcode.com/openharmony/applications_systemui/issues/104) | 一定概率下，进程com.ohos.systemui由于THREAD_BLOCK_6S卡在libeventhandler.z.so出现appfreeze。 | 点击或滑动无响应，重新进入控制中心或通知中心可恢复。 | 5月30日 |
| [5789](https://gitcode.com/openharmony/graphic_graphic_2d/issues/5789) | 一定概率下，进程com.ohos.systemui下的RSRenderThread线程导致libEGL.so出现cppcrash。 | 系统会自动进入锁屏界面，重新解锁可恢复。 | 5月30日 |
| [3830](https://gitcode.com/openharmony/window_window_manager/issues/3830) | 中等概率下进程foundation由于SERVICE_BLOCK出现sysfreeze。 | 卡顿5秒后会播放1秒开机动画，然后进入锁屏。此时重新解锁可恢复。 | 4月15日 |
| [1983](https://gitcode.com/openharmony/web_webview/issues/1983) | 小概率下进程com.ohos.note由于THREAD_BLOCK_6S卡在libweb_engine.so出现appfreeze。 | 备忘录应用界面卡顿。重启备忘录应用可恢复。 | 5月30日 |
| [1249](https://gitcode.com/openharmony/drivers_peripheral/issues/1249) | 有较高概率，进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze。 | 相机应用拍照/预览无响应，重新打开相机应用可恢复。 | 4月30日 |
| [102](https://gitcode.com/openharmony/applications_settings/issues/102) | 小概率在进程com.ohos.settings出现APP_INPUT_BLOCK的appfreeze。 | settings应用无响应，重启应用可恢复。 | 4月30日 |
| [639](https://gitcode.com/openharmony/distributeddatamgr_relational_store/issues/639) | 小概率在进程com.ohos.settingsdata下的os.settingsdata线程出现cppcrash，崩溃栈：libnative_appdatafwk.z.so。 | settingsdata服务崩溃，再次访问数据时会自行启动。对用户无影响。 | 4月15日 |
| [77](https://gitcode.com/openharmony/applications_mms/issues/77) | 小概率因进程com.ohos.mms下的com.ohos.mms线程导致libark_jsruntime.so出现cppcrash。 | 短信应用无响应或自动退出，重启应用可恢复。 | 4月30日 |
| [1852](https://gitcode.com/openharmony/kernel_linux_5.10/issues/1852) | 设备极小概率自动重启。 | 影响可控，无需规避。 | 4月30日 |
| [443](https://gitcode.com/openharmony/developtools_profiler/issues/443) | 一定概率下进程com.ohos.smartperf由于THREAD_BLOCK_6S卡在libglobal_resmgr.z.so出现appfreeze。 | 用户在使用smartperf应用测试其他应用性能数据时，触发查看实时性能数据功能时，应用有卡顿。<br/>规避措施：系统会自动清理掉应用进程，重启smartperf可恢复。 | 4月30日 |
| [101](https://gitcode.com/openharmony/security_certificate_manager/issues/101) | 小概率下进程com.ohos.certmanager由于THREAD_BLOCK_6S卡在librender_service_client.z.so出现appfreeze。 | 证书管理应用Freeze后系统自动退出该应用。影响可控。 | 4月30日 |
| [1323](https://gitcode.com/openharmony/drivers_peripheral/issues/1323) | 小概率下进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze。 | 点击相机应用后出现卡顿。退出应用，清理内存后重新打开相机可恢复。 | 4月15日 |
| [3876](https://gitcode.com/openharmony/window_window_manager/issues/3876) | 小概率在进程com.ohos.smartperf下的ohos.smartperf线程出现cppcrash，崩溃栈：libwm.z.so。 | 会有很低概率导致应用退出，退出后重启应用可恢复。 | 4月30日 |
| [2044](https://gitcode.com/openharmony/web_webview/issues/2044) | 小概率在进程com.ohos.note下的com.ohos.note线程出现cppcrash，崩溃栈：libweb_engine.so。 | 备忘录可能出现闪退。重启应用可恢复。 | 4月30日 |
| [239](https://gitcode.com/openharmony/distributedhardware_distributed_hardware_fwk/issues/239) | 设备组网后查不到对端设备。 | OpenHarmony 4.0设备和4.1设备使用分布式音频无法兼容和互通。影响可控。 | 5月30日 |
| [2541](https://gitcode.com/openharmony/communication_dsoftbus/issues/2541) | 轻量级设备之间组网失败。 | 影响可控，暂无规避措施。 | 5月30日 |
