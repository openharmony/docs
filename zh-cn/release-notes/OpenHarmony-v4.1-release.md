# OpenHarmony 4.1 Release


## 版本概述

随着OpenHarmony 4.1 Release的发布，开发套件同步升级到API 11 Release。相比4.0 Release版本，新增4000多个API，应用开发能力更加丰富；应用开发的开放能力以Kit维度呈现，提供给开发者更清晰的逻辑和场景化视角；ArkUI组件开放性和动效能力得到进一步增强；Web能力持续补齐，便于开发者利用Web能力快速构建应用；分布式能力进一步增强了组网稳定性、连接安全性等；媒体支持更丰富的编码，支持更精细的播控能力等等。欢迎开发者踊跃使用并给我们提出宝贵意见。

您可以阅读本文档了解更多关键特性及能力。

### SDK

SDK提供的开放能力以Kit维度呈现给开发者。开发者可按Kit查找和使用能力特性，使用场景化的开放能力，体验更清晰的编程逻辑。

与此同时，开发指南和API参考也已按照Kit粒度进行罗列，方便开发者对Kit进行更进一步的了解和使用。


### ArkUI

- 新增NodeContainer开放命令式的渲染节点，提升自定义绘制能力。

- 文本和容器类组件能力增强：
   - TextInput/Text支持按字符截断;
   - TextInput和TextArea提供获取光标位置接口；
   - 支持智能分词、新增依据分词结果插入光标逻辑以及替换分词算法；
   - ImageSpan支持自定义长按菜单事件、控件支持缩进/对齐;
   - List：ScrollToIndex支持滚动到ListItemGroup中指定ListItem的能力；

- 控件接入AI能力增强：
   - TextInput及相关文本输入控件支持视觉输入。
   - Text/RichEditor相关文本控件支持文本实体识别。

- 状态管理功能增强：
   - 支持undefined和null，以及联合类型。
   - ListItem组件在ForEach/LazyForEach中属性可更新方法。
   - 支持@LocalStorageLink/LocalStorageProp 在非激活状态不更新。

- 新增Chips操作块组件，TextInput、TextArea、List、Grid、Search、CheckBox、Slider、Image、Menu、半模态弹窗等组件的样式、交互和动效增强。

- 弹窗类和导航类组件自定义能力增强：
   - 支持开发者自定义弹出菜单的圆角、阴影、气泡箭头；
   - bindContextMenu支持isShow参数控制显隐；
   - Navigation支持隐藏NavBar；
   - Navigation组件提供获取路由栈每个页面详细信息，支持根据页面信息销毁或显示页面。

- 提供全新Style样式对象和组件Style样式属性方法，支持样式复用和动态切换能力，包括：
   - 通用属性样式支持Style样式对象；
   - 组件特有属性样式支持Style样式派生对象；
   - 多态样式切换到Style样式对象。 


### 应用框架

- 应用正常退出时会清理temp目录，提升安全性并减少系统存储空间消耗。

- Extension管控能力增强：新增了ServiceExtension的后台管控以及统一超时机制。

- ArkTS卡片能力增强：新增了透明卡片、数据代理刷新、单色模式和锁屏卡片能力。


### 应用包管理

- 系统级HSP 支持OTA升级；

- 新增了模块化开发包大小优化指导。


### 分布式软总线

- 构建软总线传输QoS接口能力，更优管控底层链路资源并提供选路决策，提升分布式业务体验。

- 子系统规格能力持续增强，选路增加连接可靠性确认能力、支持感知资源情况动态设置连接参数等。

- 完成子系统DFX机制增强，如：支持业务流程打点、支持上层分布式业务统计以及支持对组网监控事件进行业务告警。

- IPC支持引用计数查询和时间戳查询的接口，以及维测能力增强。


### 分布式数据管理

- UDMF支持数据类型标准化定义与描述、支持标准数据类型查询、支持数据访问授权与管理、支持应用自定义数据类型。

- 新增限制数据不打分类分级标签则不允许跨设备同步。

- preferences支持uint8Array格式数据流的修改、查询和持久化。

- RDB支持在应用指定的沙箱路径子目录下创建数据库。


### 图形图像及窗口

**图形图像**

- 系统支持可变帧率，提供API供业务接入。

- 支持HDR Vivid视频的渲染与显示。

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

- 新增数字版权管理（DRM）支持，支持DRM插件管理，支持证书请求及处理，支持许可证请求及处理，支持DRM节目的解密

**图像**

- 支持.ico图片解码。

- svg格式支持颜色设置和css解析。

- 支持解码时完成sRGB和P3色域转换。

**媒体库**

- 支持媒体数据对象化读写接口。

- 支持快速、平衡、高质量等多种访问模式。

### 相机

- 提供相机NDK接口，支持应用对相机数据做二次加工处理。

- 提供CameraPicker，支持应用直接唤起或集成相机拍照和录像功能，简化三方使用相机。

- 相机基础控制能力增强，包括平滑变焦、手电筒等能力。

- 优化相机性能，提升前后置切换、拍照与录像切换的流畅性。


### 事件通知

- 支持系统应用发送实况窗类型的通知。

- Emitter：支持订阅字符串类型事件；发送事件时传递的数据支持可序列化类型；支持获取订阅者数量。

- 支持应用只接收自身发布的自定义公共事件。


### 公共基础类库

- 支持在HAR/HSP中创建Worker。

- TaskPool支持在执行过程中往宿主线程发送消息。


### 通信与连接

- NFC提供HCE卡模拟能力。

- NFC支持默认支付应用的配置能力。

- Wi-Fi提供热点类型的查询，可查询当前连接热点是否为手机热点。

- Wi-Fi作为热点支持将接入的STA设备添加到黑名单的能力。


### 位置

- 支持地理编码，逆地理编码，查询地理编码服务状态等接口。


### 电源

- 对DisplayPowerManager的代码结构进行了调整，亮度管理功能模块变为独立的模块。

- 新增支持设备关机状态下充电动画显示，充电电量可变化更新。


### 安全

- 证书管理：支持开放用户ca证书路径。

- 证书算法库框架：支持证书链校验和吊销检查能力、支持证书链构造的能力。

- 加解密算法库框架支持PBKDF2算法、支持对称密钥可选AAD参数、支持可变长度密钥HMAC、支持DH/25519算法、支持brainpool曲线、支持SM2密钥解析和参数处理能力、支持基于曲线名的密钥生成能力。

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


### 资源管理

- 支持module.json配置文件中通过右键菜单添加资源索引。

- 支持对resfile资源目录打包编译。

- 支持基于资源名称返回资源id。


### USB

- 补齐USB服务设备管理能力，支持全设备、按设备类型、指定设备的禁用和解禁，并支持重启、热插拔场景下的禁用策略持久化能力。

- 优化USB服务鉴权方式，新增访问控制权限，细化系统服务、系统应用的USB调用权限。

- 修复USB服务批量传输、控制传输的接口漏洞，支持传输接口端到端可用，性能满足要求。


### 多模输入

- 支持双击按压电源键拉起ability。

- 支持自定义鼠标光标。

- 多模输入设置鼠标样式优化。

- 支持按键监听按优先级处理的能力。

- 支持光标大小、颜色的设置，支持动画光标样式。


### 泛Sensor

- 支持传感器数据精度的上报，使系统可感知不同设备传感器精度，优化应用适配。

- 新增传感器、振动相关能力的C API接口。

- 自定义振动格式进行扩展，新增支持curve字段描述复杂的连续振动效果。


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


### 上传下载

- 支持多个前端模式任务与后台模式任务共享任务数量的能力。

- 支持监听后台任务的状态和进度。

- 支持任务的优先级，同样是前端（或者后台）模式的任务，也可以使用优先级来调整执行顺序。

- 自动使用系统级代理。


### 输入法框架

- 优化了Webview获焦场景的输入法体验。

- 优化了窗口焦点切换场景下的输入法体验。

- 新增支持安全模式输入法。

- 新增支持Logo键+Space切换输入法。

- 新增输入法切换列表控件。


### 时间时区

- 支持通过系统参数配置NTP服务器地址，最多支持配置5个。

- 支持通过系统参数配置时间时区自动同步开关。


### 全球化

- 支持设置和获取应用偏好语言。

- 支持文本时间和电话号码格式的识别。

- 支持日期快速计算。

### AI

MindSpore Lite轻量化端侧学习能力开放C API。


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
| I8PEOF | 进程com.ohos.mms有一定概率出现因为LIFECYCLE_TIMEOUT导致的sysfreeze问题。 |
| I8QET3 | 进程bluetooth_servi下的OS_IPC_10_25363线程有一定概率出现因libbluetooth_server.z.so导致的cppcrash。 |
| I8QH9S | 进程com.ohos.settingsdata下的os.settingsdata线程小概率出现因libnative_appdatafwk.z.so导致的cppcrash。 |
| I8QNI7 | 进程foundation由于SERVICE_BLOCK小概率出现因netsysnative导致的sysfreeze。 |
| I8QSZ1 | 进程com.ohos.systemui有一定概率出现由于THREAD_BLOCK_6S卡在libsamgr_proxy.z.so导致的appfreeze。 |
| I7TYTF等43个开源组件漏洞 | 内核errseq_set函数protection_fault 等43个开源组件漏洞。 |
| I78THF | RK3568 kernel patch中的maligpu版本过旧（11.29），存在大量未修复CVE漏洞。 |
| I83D6I | 进入设置反复打开关闭蓝牙，有一定概率会导致设置出现appfreeze。 |
| I827LU | 进入设置反复打开关闭蓝牙开关会出现内存泄漏，经测试一个小时泄露15MB。 |
| I82V2W | 进入设置反复打开关闭蓝牙开关出现内存泄漏，经测试“设置”一个小时内存涨幅到180M。 |



## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| I8WP8M | 移动桌面一个图标使之与另一图标重叠创建大文件夹，之后选中文件夹内的一个应用移出文件夹，重复此操作，launcher出现内存泄露，操作五分钟，内存泄漏约25M，操作一次泄露约673.68KB。 | 泄漏达到一定程度后造成系统卡顿。<br/>规避措施：清理后台应用或重启可释放。 | 4月30日 |
| I98AV0 | 点击设置里的位置信息开关，重复此操作，distributeddata进程出现内存泄露，操作五分钟，泄露约14M，操作一次泄露约95.57KB。 | 泄漏达到一定程度后造成系统卡顿。<br/>规避措施：退出当前界面内存可释放。 | 4月30日 |
| I9A9NO | 不停执行点击短信界面右上角新建短信和返回操作，5分钟短信应用内存上涨约50M，操作一次泄露约341.33KB。 | 泄漏达到一定程度后造成系统卡顿。<br/>规避措施：退出应用内存可释放。 | 4月30日 |
| I8QLRO | 小概率在进程bluetooth_servi下的Stack线程出现cppcrash，崩溃栈：libbtstack.z.so。 | 蓝牙服务出现异常后服务自动恢复，用户无异常感知。 | 4月30日 |
| I8TLYJ | 小概率在进程bluetooth_servi下的SaInit1线程出现cppcrash，崩溃栈：libbtstack.z.so。 | 蓝牙服务出现异常后服务自动恢复，用户无异常感知。 | 4月30日 |
| I8TM99 | 小概率在进程softbus_server下的softbus_server线程出现cppcrash，崩溃栈：libbtframework.z.so。 | 软总线服务出现异常后服务自动恢复，用户无异常感知。 | 4月30日 |
| I8VFJS | 小概率在进程com.ohos.settings下出现jscrash，栈名：ObservedPropertyAbstractPU。 | settings应用小概率出现闪退，退出应用内存可释放。 | 4月30日 |
| I98NGO | 小概率下进程com.ohos.settings由于THREAD_BLOCK_6S卡在libbtframework.z.so发生appfreeze。 | settings应用小概率出现闪退，退出应用内存可释放。 | 4月30日 |
| I90A2N | 一定概率下，进程com.ohos.systemui由于THREAD_BLOCK_6S卡在libeventhandler.z.so出现appfreeze。 | 点击或滑动无响应，重新进入控制中心或通知中心可恢复。 | 5月30日 |
| I963UO | 一定概率下，进程com.ohos.systemui下的RSRenderThread线程导致libEGL.so出现cppcrash。 | 系统会自动进入锁屏界面，重新解锁可恢复。 | 5月30日 |
| I9A089 | 中等概率下进程foundation由于SERVICE_BLOCK出现sysfreeze。 | 卡顿5秒后会播放1秒开机动画，然后进入锁屏。此时重新解锁可恢复。 | 4月15日 |
| I9AYM2 | 小概率下进程com.ohos.note由于THREAD_BLOCK_6S卡在libweb_engine.so出现appfreeze。 | 备忘录应用界面卡顿。重启备忘录应用可恢复。 | 5月30日 |
| I9CGOZ | 有较高概率，进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze。 | 相机应用拍照/预览无响应，重新打开相机应用可恢复。 | 4月30日 |
| I9AEO0 | 小概率在进程com.ohos.settings出现APP_INPUT_BLOCK的appfreeze。 | settings应用无响应，重启应用可恢复。 | 4月30日 |
| I8QH9S | 小概率在进程com.ohos.settingsdata下的os.settingsdata线程出现cppcrash，崩溃栈：libnative_appdatafwk.z.so。 | settingsdata服务崩溃，再次访问数据时会自行启动。对用户无影响。 | 4月15日 |
| I963TL | 小概率因进程com.ohos.mms下的com.ohos.mms线程导致libark_jsruntime.so出现cppcrash。 | 短信应用无响应或自动退出，重启应用可恢复。 | 4月30日 |
| I9635I | 设备极小概率自动重启。 | 影响可控，无需规避。 | 4月30日 |
| I96JJ7 | 小概率在进程com.ohos.note下的com.ohos.note线程出现cppcrash，崩溃栈：libace_compatible.z.so。 | 使用备忘录应用时可能出现闪退，重启应用可恢复。 | 4月30日 |
| I993H9 | 一定概率下进程com.ohos.smartperf由于THREAD_BLOCK_6S卡在libglobal_resmgr.z.so出现appfreeze。 | 用户在使用smartperf应用测试其他应用性能数据时，触发查看实时性能数据功能时，应用有卡顿。<br/>规避措施：系统会自动清理掉应用进程，重启smartperf可恢复。 | 4月30日 |
| I97U6G | 小概率下进程com.ohos.certmanager由于THREAD_BLOCK_6S卡在librender_service_client.z.so出现appfreeze。 | 证书管理应用Freeze后系统自动退出该应用。影响可控。 | 4月30日 |
| I98KIG | 小概率下进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze。 | 点击相机应用后出现卡顿。退出应用，清理内存后重新打开相机可恢复。 | 4月15日 |
| I98NFR | 小概率在进程com.ohos.smartperf下的ohos.smartperf线程出现cppcrash，崩溃栈：libwm.z.so。 | 会有很低概率导致应用退出，退出后重启应用可恢复。 | 4月30日 |
| I98AWP | 小概率在进程com.ohos.note下的com.ohos.note线程出现cppcrash，崩溃栈：libweb_engine.so。 | 备忘录可能出现闪退。重启应用可恢复。 | 4月30日 |
| I96ZWB | 设备组网后查不到对端设备。 | OpenHarmony 4.0设备和4.1设备使用分布式音频无法兼容和互通。影响可控。 | 5月30日 |
| I96CJL | 轻量级设备之间组网失败。 | 影响可控，暂无规避措施。 | 5月30日 |
