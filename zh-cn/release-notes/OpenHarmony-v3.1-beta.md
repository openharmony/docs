# OpenHarmony 3.1 Beta


## 版本概述

当前版本在OpenHarmony 3.0 LTS的基础上，更新支持了以下能力：

- 标准系统OS基础能力增强：内核提升CMA利用率特性、图形新增支持RenderService渲染后端引擎、短距离通信支持STA（Station）和SoftAP基础特性、支持地磁场的算法接口、传感器驱动模型能力增强、支持应用帐号信息查询和订阅等、全球化特性支持、编译构建支持统一的构建模板、编译运行时提供Windows/MacOS/Linux的前端编译工具链、JS运行时支持预览器、新增支持JSON处理、Eventbus、Vcard、Protobuf、RxJS、LibphoneNumber等6个JS三方库、新增时间时区管理、DFX新增支持HiSysEvent部件提供查询和订阅接口。

- 标准系统分布式能力增强：包括新增支持分布式DeviceProfile特性、分布式数据管理支持跨设备同步和订阅、分布式软总线支持网络切换组网、分布式文件系统支持Statfs API能力等。

- 标准系统应用程序框架能力增强：新增ArkUI自定义绘制能力和Lottie动画能力、新增包管理探秘隐式查询和多hap包安装、事件通知支持权限管理、设置通知振动、通知声音设置和查询、通知免打扰、会话类通知等。

- 标准系统应用能力增强：输入法应用支持文本输入和横屏下布局显示、短信应用信息管理、联系人应用通话记录和拨号盘显示、设置应用更多设置项。

- 轻量系统能力增强：HiStreamer轻量级支持可定制的媒体管线框架、Linux版本init支持热插拔、OS轻内核&amp;驱动启动优化、快速启动能力支持。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.1&nbsp;Beta | NA |
| SDK | Ohos_sdk&nbsp;3.1&nbsp;Beta&nbsp;&nbsp;（API&nbsp;Version&nbsp;8&nbsp;Beta） | NA |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta2 | OpenHarmony应用开发推荐使用。 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.0&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 |


## 源码获取

### 前提条件

1.  注册码云gitee账号。
2.  注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。
3.  安装[git客户端](https://git-scm.com/book/zh/v2/%E8%B5%B7%E6%AD%A5-%E5%AE%89%E8%A3%85-Git)和[git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading)并配置用户信息。

    ```
    git config --global user.name "yourname"
    git config --global user.email "your-email-address"
    git config --global credential.helper store
    ```

4.  安装码云repo工具，可以执行如下命令。

    ```
    curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  #如果没有权限，可下载至其他目录，并将其配置到环境变量中
    chmod a+x /usr/local/bin/repo
    pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
    ```


### 通过repo获取

**方式一（推荐）**

通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1-Beta --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1-Beta --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                         | **版本信息** | **下载站点** | **SHA256校验码** |
| -------------------------------- | ------------ | ------------ | ---------------- |
| 全量代码（标准、轻量和小型系统） | 3.1 Beta     | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/code-v3.1-Beta.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/code-v3.1-Beta.tar.gz.sha256) |
| Hi3516标准系统解决方案（二进制） | 3.1 Beta     | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/standard_hi3516.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/standard_hi3516.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制） | 3.1 Beta     | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/standard_rk3568.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制） | 3.1 Beta     | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_pegasus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-LiteOS（二进制） | 3.1 Beta     | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_taurus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-Linux（二进制） | 3.1 Beta     | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统SDK包（Mac） | 3.1 Beta     | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/ohos-sdk-mac.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/ohos-sdk-mac.tar.gz.sha256) |
| 标准系统SDK包（Windows\Linux） | 3.1 Beta     | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/ohos-sdk.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/ohos-sdk.tar.gz.sha256) |
| 编译工具链获取清单 | - | [站点](https://repo.huaweicloud.com/harmonyos/os/2.0/tool_chain/) | - |


## 更新说明

本版本在OpenHarmony 3.0 LTS的基础上有如下变更。


### 特性变更

**表3** 版本新增特性表

| 子系统名称 | 标准系统 | 轻量、小型系统 |
| -------- | -------- | -------- |
| 包管理子系统 | -&nbsp;I4MBSE：提供桌面包管理客户端<br/>-&nbsp;I4MBSF：支持缓存清除能力<br/>-&nbsp;I4MBSG：支持安装包信息查询<br/>-&nbsp;I4MBSD：支持多hap包安装<br/>-&nbsp;I4MBSH：支持多hap安装的签名校验<br/>-&nbsp;I4MBSC：支持Module和Ability的srcPath字段 | NA |
| 分布式任务调度子系统 | -I4MBRW：SAMGR新增服务进程内的System&nbsp;Ability名单管控<br/>-I4MBRV：SAMGR新增系统服务状态列表维护<br/>-I4MBRZ：SAMGR新增全量服务列表初始化<br/>-I4MBRY：SAMGR新增系统服务进程状态列表维护<br/>-I4MBRX：SAMGR新增加载指定系统服务 | NA |
| DeviceProfile子系统 | -I4NY23：本地设备Profile的插入、删除、查询<br/>-I4NY1X：远程设备Profile的查询<br/>-I4NY1T：订阅远程Profile变化的通知<br/>-I4NY1W：跨设备同步Profile | NA |
| 帐号子系统 | -I4MBQW：支持应用帐号的新增和删除<br/>-I4MBQV：应用帐号基础信息约束<br/>-I4MBQU：支持应用帐号订阅及取消订阅<br/>-I4MBQT：支持应用帐号功能设置与内容修改<br/>-I4MBQS：支持应用帐号信息查询<br/>-I4IT3U：支持应用帐号基础信息管理 | NA |
| 泛sensor服务子系统 | -I3NJ96：加速度传感器数据上报<br/>-I3NJ8H：陀螺仪传感器数据上报<br/>-I3NJ7J：环境光传感器数据上报<br/>-I3NJ76：磁力计传感器数据上报<br/>-I4MBRP：地磁场偏角和倾角<br/>-I4MBRQ：地磁场水平强度、总强度 | NA |
| USB服务子系统 | I410OZ：<br/>-&nbsp;查询已连接的USB设备列表<br/>-&nbsp;获取USB设备临时访问权限<br/>-&nbsp;设置USB设备配置、接口<br/>-&nbsp;与USB设备进行数据传输 | NA |
| 语言编译器运行时子系统 | -&nbsp;I4MBUK：JavaScript/TypeScript默认运行时从quickjs替换为方舟运行时。<br/>-&nbsp;I4MBUJ：方舟运行时内存回收功能增强，支持并发标记算法以及并发压缩算法，支持选择部分region进行压缩GC（Partial&nbsp;CompressionGC），优化GC&nbsp;pause&nbsp;time减少30%。 | NA |
| 全球化子系统 | -&nbsp;支持国际化特性：单复数规则、字符串排序、电话号码处理、日历&amp;本地历法、度量衡体系和格式化、区域表示和属性、时间段格式化、字母表检索、unicode字符属性、断词换行<br/>-&nbsp;支持系统资源、rawfile资源 | NA |
| 分布式软总线子系统 | -I4FZ29：软总线提供传输ExtAPI接口<br/>-I4FZ25：软总线支持网络切换组网 | -I4FZ29：软总线提供传输ExtAPI接口<br/>-I4FZ25：软总线支持网络切换组网 |
| 启动子系统 | NA | -I3XGJH：init基础环境构建<br/>-I3XGKV：system parameter管理<br/>-I3XGLN：init&nbsp;脚本管理<br/>-I3XGMQ：基础权限管理<br/>-I3XGN8：bootimage构建和加载<br/>-I3XGKV：uevent&nbsp;管理<br/>-I3XGNM：烧写模式支持 |
| 媒体子系统 | NA | -I4BX5Z：HiStreamer支持音频播放和控制<br/>-I4BX8A：HiStreamer支持常见音频格式mp3/wav的播放<br/>-I4BX9E：HiStreamer播放引擎框架需求<br/>-I4DK89：HiStreamer插件框架需求<br/>-I4DK8D：HiStreamer性能和DFX需求 |
| 图形子系统 | 全新设计OpenHarmony&nbsp;图形栈：<br/>新增UI框架渲染后端特性支持<br/>新增ArkUI控件接入RenderService渲染后端 | NA |
| 内核子系统 | 内核（Linux&nbsp;5.10）<br/>-I4LUG4&nbsp;CMA内存区域复用（目前仅支持Hi3516DV300，暂不支持RK平台）<br/>-I4LX4G&nbsp;支持anonymous&nbsp;vma命名（目前仅支持Hi3516DV300，暂不支持RK平台） | -I3ND6Y：【性能】OS内核&amp;驱动启动优化 |
| 启动恢复子系统 | NA | -I3NTCT：Linux版本init支持热插拔 |
| 分布式数据对象管理子系统 | NA | -I4H3JJ：分布式对象支持小型系统设备 |
| 电话子系统 | NA | -I4JQ2N：提供Http&nbsp;JS&nbsp;API<br/>-I4JQ3G：提供Http&nbsp;2.0协议 |
| Misc软件服务子系统 | I4MBQE：<br/>支持应用读取时间<br/>支持应用读取时区<br/>支持时间修改通知<br/>支持时区修改通知<br/>支持分钟变化通知 | NA |
| 编译构建子系统 | I4K7E3：支持使用统一的编译命令作为编译入口<br/>- I4KCNB：支持使用统一的gn模板 | -I4MBQN：支持统一的编译入口、支持使用build.sh编译轻量、小型系统<br/>-I4MBQP：支持统一的编译流程<br/>-I4MBQR：支持统一的产品配置 |
| 文件存储子系统 | -I4MBS2：statfs获取设备总空间与剩余空间JS接口 | NA |
| 驱动子系统 | -I4L3KK：传感器器件驱动能力增强，支持传感器采样率动态配置，三轴方向静态可配置，环境光增益调节。<br/>-I4L3LF：传感器驱动模型能力增强，支持传感器HDI跨进程服务获取和调用。<br/>-I4MBTS：HDF-Input设备能力丰富，支持摇杆设备数据上报。<br/>-I4MBTR：Display&nbsp;HDI接口针对标准系统的参考实现，针对DRM显示架构，提供针对标准系统的Display&nbsp;HDI默认参考实现，有助于厂商参考适配HDI。<br/>-I4HPR7：提供hcs宏式解析机制，编译时使用hc-gen工具把驱动的配置参数解析为宏定义参数，驱动通过hcs宏格式的接口访问宏定义参数。<br/>-I4KVJQ：支持linux/liteos内核系统级休眠唤醒。<br/>-I4L3ZZF：支持同步/异步电源管理调用，提供同步/异步的管理HDF设备进入休眠或者被唤醒的机制。 | -I4L3KK：传感器器件驱动能力增强，支持传感器采样率动态配置，三轴方向静态可配置，环境光增益调节。<br/>-HDF-Input设备能力丰富(linux系统)，支持摇杆设备数据上报。<br/>-I4HPR7：提供hcs宏式解析机制，编译时使用hc-gen工具把驱动的配置参数解析为宏定义参数，驱动通过hcs宏格式的接口访问宏定义参数。<br/>-I4KVJQ：支持linux/liteos内核系统级休眠唤醒。<br/>-I4L3ZZF：支持同步/异步电源管理调用，提供同步/异步的管理HDF设备进入休眠或者被唤醒的机制。 |
| ArkUI子系统 | - I4MBUY：事件中增加Target获取尺寸<br/>- I4MBUZ：Swiper组件支持设置缓存cache <br/>- I4MBV1：Image组件支持同步、异步渲染设置 <br/>- I4MBV3：样式设置特性增加组件多态样式设置<br/>- I4MBV5：字母索引条组件增加提示菜单内容扩展<br/>- I4MBV6：组件自定义特性增加自定义容器组件规格<br/>- I4MBV7：滚动条样式自定义能力<br/>- I4MBV8：Swiper组件新增切换禁用规格<br/>- I4MBV9：Tabs组件新增TabBar内容自定义规格<br/>- I4MBVA：Navigation组件新增标题栏设置规格<br/>- I4MBVB：工具栏组件增加工具栏显隐控制规格<br/>- I4MBVC：工具栏组件增加内容自定义能力规格<br/>- I4MBVD：新增SysCap声明编译特性<br/>- I4MBVE：新增JSSDK编译特性 <br/>- I4MBVF：新增Config.json编译特性 <br/>- I4MBVG：新增断点调试特性支持单实例调试<br/>- I4MBVH：新增attach调试特性支持单实例调试<br/>- I4MBVI：新增声明式范式编译特性支持编译和校验规格<br/>- I4MBVJ：新增JS模块共享编译特性<br/>- I4MBVK：新增HAR引用和编译特性 <br/>- I4MBVL：新增NPM引用和编译特性、 <br/>- I4MBVN：纵向显示滑动条组件特性<br/>- I4MBVO：Popup组件增加内容自定义规格 <br/>- I4MBVP：Canvas绘制能力支持<br/>- I4MBVQ：Canvas能力增强<br/>- I4MBVR：触摸响应热区设置<br/>- I4MBVS：Lottie动画支持<br/>- I4MBVT：组件尺寸获取特性<br/>- I4MBVU：Menu组件增加内容自定义规格<br/>- I4MBVV：Swipe手势特性 <br/>- I4MBVW：UI预览支持Inspector能力 <br/>- I4MBVX：新增非路由文件预览特性<br/>- I4MBVY：新增NAPI预览特性<br/>- I4MBVZ：新增声明式范式预览特性。支持基础预览规格<br/>- I4MBW2：新增声明式范式热加载特性，支持已有节点修改规格<br/>- I4MBW3：新增声明式范式热加载特性，支持新增节点规格<br/>- I4MBW4：新增声明式范式热加载特性，支持删除节点规格<br/>- I4MBW5：新增组件预览特性，支持页面组件预览规格<br/>通用属性新增点击控制 touchable：设置组件是否可以被触摸。<br/>基础组件新增Marquee：跑马灯组件。<br/>基础组件新增Gauge：数据量规图表组件。<br/>基础组件新增TextArea：多行文本输入组件。<br/>基础组件新增TextInput：单行文本输入组件。<br/>基础组件新增Toggle：状态组件。<br/>容器组件新增Stepper：步骤导航器组件。<br/>容器组件新增StepperItem：步骤导航器导航项组件。<br/>新增全局UI方法ActionSheet：列表选择弹窗。 | NA |
| DFX子系统 | -I4MBQH：支持HiSysEvent部件，提供查询、订阅接口<br/>-I4MBQJ：提供工具查询或者订阅系统事件<br/>-I4MBQL：支持Hiappevent部件的C接口 | NA |
| 应用子系统 | -I4MBU1：支持Settings数据管理API<br/>-I4MBU3：支持时间设置<br/>- I4MBU5：支持声音管理<br/>-I4MBU6：支持Settings数据管理<br/>-I4MBU7：支持Settings数据默认值管理<br/>-I4MBU8：支持Settings多设备形态差异化构建<br/>-I4MBU9：通知组件化 | NA |


### API变更

API变更请参考：

_[JS API 差异报告](api-diff/v3.1-beta/js-apidiff-v3.1-beta.md)_

_[Native API差异报告](api-diff/v3.1-beta/native-apidiff-v3.1-beta.md)_

_[Changelog](api-diff/v3.1-beta/changelog-v3.1-beta.md)_


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples &amp; Codelabs


#### 新增Samples

**表4** Samples列表

| 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- |
| [Ets公共事件](https://gitee.com/openharmony/app_samples/tree/master/Notification/CommonEvent) | 本示例展示了在ArkTS中如何使用CommonEvent的接口完成创建订阅者、订阅公共事件、发布公共事件、取消订阅的功能。 | ArkTS |
| [空气质量](https://gitee.com/openharmony/app_samples/tree/master/common/AirQuality) | 本示例使用JS实现了一个简单空气质量应用，使用折行显示能力显示空气质量信息，使用柱形图展示历史记录。 | JS |
| [分布式计算器](https://gitee.com/openharmony/app_samples/tree/master/common/DistributeCalc) | 本示例使用JS分布式能力实现了一个简单的计算器应用，可以进行简单的数值计算，支持远程拉起另一个计算器FA，两个FA进行协同计算。 | JS |
| [EtsNotification](https://gitee.com/openharmony/app_samples/tree/master/common/Notification) | 本示例展示了在ArkTS中如何创建和删除Slot通道，如何发布和取消通知。 | ArkTS |
| [Ets资源管理](https://gitee.com/openharmony/app_samples/tree/master/common/ResourceManager) | 本示例展示了在ArkTS中如何调用资源管理的API接口实现字符串和图片资源信息的获取。 | ArkTS |
| [kikainput](https://gitee.com/openharmony/app_samples/tree/master/CompleteApps/KikaInput) | kikainput是一个轻量级的输入法应用，支持在运行OpenHarmony&nbsp;OS的智能终端上。 | JS |
| [ArkTS分布式数据管理](https://gitee.com/openharmony/app_samples/tree/master/data/Kvstore) | 本示例展示了在ArkTS中分布式数据管理的使用，包括KVManager对象实例的创建和KVStore数据流转的使用。 | ArkTS |
| [轻量级数据存储](https://gitee.com/openharmony/app_samples/tree/master/data/LiteStorage) | 轻量级数据存储主要提供轻量级Key-Value操作，支持本地应用存储少量数据。本示例通过对购物车商品的添加和删除并保存退出的操作，使得再次打开应用时依然可以保留退出前的购物车信息，体现了轻量级存储在保存轻量级数据时的作用。 | ArkTS |
| [Ets进程信息](https://gitee.com/openharmony/app_samples/tree/master/ETSUI/Process) | 本示例展示了在ArkTS中如何获取进程信息和启动一个子进程运行一段shell，包括当前系统运行时间、获取进程当前工作目录、更改进程当前工作目录、发送signal到指定的进程、启动一个子进程、关闭子进程、退出当前系统的功能。 | ArkTS |
| [Ets运行锁](https://gitee.com/openharmony/app_samples/tree/master/common/Runninglock) | 本示例展示了阻止系统休眠的运行锁功能，通过黑白色壁纸模拟息屏、亮屏状态，来展示系统的休眠状态，从而对运行锁的功能进行测试，使得该运行锁在打开后可以阻止系统休眠。 | ArkTS |
| [字符串编解码](https://gitee.com/openharmony/app_samples/tree/master/Util/UtilStringCodec) | 本示例对字符串进行了特定格式的输出，对错误码的内容进行了文本输出，对字符串的编码和解码做了演示结果。 | ArkTS |
| [Js音频播放和管理](https://gitee.com/openharmony/app_samples/tree/master/media/JsAudioPlayer) | 本示例展示了JS音频播放的使用方法，以及音频的音量大小设置。 | JS |
| [JsVideo](https://gitee.com/openharmony/app_samples/tree/master/media/JsVideo) | 本示例使用JS&nbsp;UI中的&lt;video/&gt;组件，实现视频播放。可以通过video自带的控制栏进行播放、暂停等操作。 | JS |
| [测试打点](https://gitee.com/openharmony/app_samples/tree/master/DFX/JsDotTest) | 本示例展示了测试打点功能，包括应用打点与性能打点两部分。 | JS |
| [JsWorker](https://gitee.com/openharmony/app_samples/tree/master/thread/JsWorker) | 本示例展示了在JS中如何启动一个worker线程，并实现worker线程和宿主线程的通信。 | JS |
| [画布组件](https://gitee.com/openharmony/app_samples/tree/master/UI/JsCanvas) | &lt;canvas/>组件可以自定义绘制图形，本示例展示了&lt;canvas\>组件的使用方法 | JS |
| [JS页面弹窗](https://gitee.com/openharmony/app_samples/tree/master/UI/JsDialog) | JS中支持用户自定义弹窗，&lt;dialog/&gt;组件作为容器组件，用户可以自定义弹窗的样式和布局。本示例完成了添加和删除联系人功能，在添加和删除时使用自定义弹窗来实现。 | JS |
| [JSList商品列表](https://gitee.com/openharmony/app_samples/tree/master/UI/JsList) | 本示例展示了list控件在商品分类列表中的应用，在listGroup里采用两个list-item分别展示了Group收缩和Group展开的两种列表形态，点击后会弹出相应的list列表。 | JS |
| [JSPanel](https://gitee.com/openharmony/app_samples/tree/master/UI/JsPanel) | JS提供一种轻量级的内容展示面板，此面板可滑动，可自定义触发方式、弹出高度等属性。本示例通过可滑动面板展示了商品详细信息与平台保障。 | JS |
| [JsSvg](https://gitee.com/openharmony/app_samples/tree/master/UI/JsSvg) | 本示例展示了JS中<svg\>组件及其子组件的使用，包括<svg\>、<rect\>、<circle\>、<ellipse\>、<path\>、<line\>、<polygon\>、<polyline\>、<text\>、<animate\>、<animateTransform\> 。 | JS |
| [JS自定义组件](https://gitee.com/openharmony/app_samples/tree/master/UI/JSUICustomComponent) | 自定义组件是用户根据业务需求，将已有的组件组合，封装成的新组件，可以在工程中多次调用，提高代码的可读性。本示例展示了JS中自定义组件的使用，包括基本用法、自定义事件、Props和事件参数。 | JS |


#### 新增Codelabs

**表5** Codelabs列表

| 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- |
| [分布式手写板（ArkTS）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/DistributeDatabaseDrawEts) | 基于分布式能力，实现多设备同步书写互动。 | ArkTS |
| [分布式数据库](https://gitee.com/openharmony/codelabs/tree/master/Data/JsDistributedData) | 基于分布式数据接口，实现多种设备上一致的数据访问体验。 | JS |
| [购物应用（ArkTS）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/ShoppingEts) | 基于OpenHarmony ArkUI丰富的组件实现购物商城应用。 | ArkTS |
| [转场动画的使用（ArkTS）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/TransitionAnimation) | 基于OpenHarmony ArkUI转场动画，实现了页面间转场、组件内转场以及共享元素转场。 | ArkTS |
| [基础组件Slider的使用（ArkTS）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/SliderExample) | 基于OpenHarmony&nbsp;eTS&nbsp;UI，使用slider组件，实现可调节风车大小和转速的动画效果。 | ArkTS |
| [自定义弹窗（ArkTS）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/CustomDialog) | 基于OpenHarmony ArkUI，实现警告弹窗和自定义弹窗。 | ArkTS |


## 修复缺陷列表

**表6** 修复缺陷ISSUE列表

| ISSUE单号 | 问题描述 |
| -------- | -------- |
| [I48IM7](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I48IM7) | 运行hilog压力测试，hilogd异常重启，且hilog命令一直无法使用。 |
| I48YPH | 【软总线-组网】测试发现和组网性能(循环离网-发现-组网)110次组网失败3次。 |
| [I4BVVW](https://gitee.com/openharmony/communication_dsoftbus/issues/I4BVVW) | 【软总线-组网】标准系统与手机开关网络自组网成功率97%失败3次需分析失败原因。 |
| I4BXY1 | 视频录制后前几秒没声音，播放声画不同步，在板子播放会卡顿，音源较远时，有杂音。 |
| [3ZJ1D](https://gitee.com/openharmony/kernel_liteos_a/issues/I3ZJ1D) | XTS权限用例压测用户态概率失败。 |


## 遗留缺陷列表

**表7** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| [I4NRS5](https://gitee.com/openharmony/kernel_linux_5.10/issues/I4NRS5) | 【内核子系统】存在cve漏洞 | Linux内核还未发布补丁，暂时挂起，待社区发布补丁后升级同步。 | 待社区发布补丁 |
| [I4MGJM](https://gitee.com/openharmony/drivers_peripheral/issues/I4MGJM) | 【hdf/camera】RK3568单板跑camera&nbsp;HDI用例失败 | 拍照和预览正常，可以正常录像，点击结束按钮，不能结束。 | 2021/12/31 |
| I4OECR | XTS运行报ark异常栈（低概率问题） | XTS压力测试低概率偶现(48小时出现1次)，仅Log中上报异常栈，对功能无影响。 | 2022/1/5 |
| [I4OBTW](https://gitee.com/openharmony/ability_ability_runtime/issues/I4OBTW) | 全量执行XTS用例，安装应用后出现批量aa&nbsp;start&nbsp;失败，影响社区流水线稳定性测试 | XTS压力测试，短时间内批量安装100个应用包，低概率(2个/100个)出现应用无法启动。用户使用无影响。 | 2022/1/5 |
| I4OLHF | 【Ark子系统】&nbsp;由进程com.amsst.amsMissionSnapshotTest导致测试进程异常 | 低概率、偶现，高压力测试偶现问题。 | 2022/1/5 |
| I4OLUK | 【Ark子系统】&nbsp;由进程com.ohos.systemui导致进程栈异常 | 低概率、偶现，高压力测试偶现问题。 | 2022/1/5 |
