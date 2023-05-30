# OpenHarmony 3.2 Beta2


## 版本概述

当前版本在OpenHarmony 3.2 Beta1的基础上，更新支持以下能力：

**标准系统基础能力增强**

新增支持窗口多热区分发机制。

支持电源管理重启恢复机制。

多模输入新增支持Input手写笔压感合成、倾角、按键输入。

安全域支持预置应用预授权机制、指纹录入/认证/识别框架。

驱动支持录像模式自拍镜像功能、音频音效控制、红外设备输入、音频USB插拔识别及事件上报。

**标准系统应用程序框架能力增强**

元能力支持卡片提供方添加静态和动态卡片、组件支持本地免安装启动、系统SA启动和访问组件、支持单实例Ability迁移、运行管理支持打开沙箱应用、系统应用Ability不在最新任务列表显示。

包管理支持获取当前包的包名和证书指纹信息NDK接口能力、查询指定应用的PackInfo信息、原子化服务老化卸载。

**标准系统应用开发样例**

新增五子棋人机对战、二维码生成和解析、卡片使用、多媒体、短视频、面部识别能力等Demo样例，为开发者提供SDK使用的样例程序，方便开发者快速上手使用OpenHarmony系统基础能力。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.2 Beta2 | NA |
| Public SDK | Ohos_sdk_public 3.2.5.5 (API Version 9 Beta2)<br>Ohos_sdk_public 3.2.5.6 (API Version 9 Beta2) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>通过DevEco Studio默认获取的SDK为Public SDK。 |
| Full SDK | Ohos_sdk_full 3.2.5.5 (API Version 9 Beta2)<br/>Ohos_sdk_full 3.2.5.6 (API Version 9 Beta2) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full SDK时需要手动从镜像站点获取，并在DevEco Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| HUAWEI DevEco Studio（可选） | 3.0 Beta4 | OpenHarmony应用开发推荐使用。 |
| HUAWEI DevEco Device Tool（可选） | 3.0 Release | OpenHarmony智能设备集成开发环境推荐使用。 |


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta2 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）        | 3.2 Beta2    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/code-v3.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/code-v3.2-Beta2.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制）        | 3.2 Beta2    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/hispark_pegasus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-LiteOS（二进制） | 3.2 Beta2    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-Linux（二进制）  | 3.2 Beta2    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus_linux.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）        | 3.2 Beta2    | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/dayu200_standard_arm64.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/dayu200_standard_arm64.tar.gz.sha256) |
| 标准系统Full SDK包（Mac）               | 3.2.5.5      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-mac-full.tar.gz.sha256) |
| 标准系统Full SDK包（Windows\Linux）     | 3.2.5.5      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-windows_linux-full.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-windows_linux-full.tar.gz.sha256) |
| 标准系统Public SDK包（Mac）             | 3.2.5.5      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public SDK包（Windows\Linux）   | 3.2.5.5      | [站点](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta2/ohos-sdk-windows_linux-public.tar.gz.sha256) |
| 标准系统Full SDK包（Mac）               | 3.2.5.6      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-mac-full_20220913.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-mac-full_20220913.tar.gz.sha256) |
| 标准系统Full SDK包（Windows\Linux）     | 3.2.5.6      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-windows_linux-full_20220913.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-windows_linux-full_20220913.tar.gz.sha256) |
| 标准系统Public SDK包（Mac）             | 3.2.5.6      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public SDK包（Windows\Linux）   | 3.2.5.6      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta2/sdk-patch/ohos-sdk-windows_linux-public.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony 3.2 Beta1的基础上有如下变更。

### SDK变更
从本版本起，SDK会同时提供Public SDK和Full SDK。通过DevEco Studio默认获取的SDK为Public SDK。

已使用较早版本SDK开发的应用如果使用到了系统API，升级本版本后需要[手动替换SDK为Full SDK](../application-dev/faqs/full-sdk-switch-guide.md)才可以保证应用工程可编译通过。

### 特性变更

  **表3** 版本特性变更表

| 子系统名称 | 标准系统 | 轻量、小型系统 |
| -------- | -------- | -------- |
| 元能力 | - 为支持IoT设备无UI应用开发，对graphics和power模块进行解耦。<br/>- 对DFX能力、任务管理能力、应用线程模型管理能力等基础能力进行了增强。<br/>主要涉及如下需求：<br/>I57ZUI 【新增特性】支持IoT设备无UI应用开发-graphics模块解耦<br/>I57ZVC 【新增特性】支持IoT设备无UI应用开发-power模块解耦<br/>I5805B 【增强特性】AMS ANR功能优化<br/>I581M3 【新增特性】应用选择框<br/>I580JM 【新增特性】支持系统应用ability不在最新任务列表显示<br/>I5FHNH 【增强特性】Stage模型Context对象支持向worker传递<br/>I58034 【增强特性】使用libuv统一JS Looper机制<br/>I57ZZH 【新增特性】提供创建不同Hap包上下文能力 | NA |
| 包管理 | 新增默认应用管理能力，支持众测应用、获取包指纹信息等基础能力。<br/>主要涉及如下需求：<br/>I56WD7 【新增特性】支持查询默认应用<br/>I56WDJ 【新增特性】支持更改默认应用<br/>I56WDR 【新增特性】支持恢复系统默认应用<br/>I56WEK 【新增特性】支持按文件类型设置默认应用<br/>I59ZMR 【新增特性】包管理支持众测应用<br/>I5A7OV 【新增特性】包管理提供NDK接口，获取当前包的包名和证书指纹信息 | NA |
| 电源子系统 | 新增热管理的资源管控和日志，功耗统计支持更多模块。<br/>主要涉及如下需求：<br/>I5AOM8 【新增特性】增加Action Hub功能<br/>I5DC5E 【增强特性】Camera耗电统计<br/>I5DC7M 【增强特性】Audio耗电统计<br/>I5DC8L 【增强特性】Timer功耗DFX<br/>I5DC9H 【增强特性】分布式任务调度功耗DFX<br/>I5DOP4 【新增特性】热维测DFX<br/>I5DONL 【新增特性】充电资源管控框架<br/>I5DOLA 【新增特性】适配SOC资源管控框架 | NA |
| 系统服务管理子系统 | - 持续构建分布式基础能力。<br/>- 加固系统服务进程稳定性、安全性，优化进程内存。<br/>主要涉及如下需求：<br/>I5FLTY 【新增特性】组件协同关系管理<br/>I5DP1O 【新增特性】DMS提供系统事件、SA dump、trace打点<br/>I5CEMN 【新增特性】startAbilityForResult支持免安装<br/>I5BAP0 【新增特性】startAbility支持跨设备免安装<br/>I5B2PK 【新增特性】跨端迁移适配分布式对象持久化保存<br/>I59XYB 【新增特性】添加群组校验机制<br/>I592I5 【新增特性】distributedsche进程内存基线<br/>I5E4KV 【新增特性】SAMGR提供系统事件、SA dump、trace打点 | NA |
| 事件通知子系统 | - 新增支持工具适配多用户。<br/>- 公共事件和通知基础能力增强。<br/>主要涉及如下需求：<br/>I582V2 【新增规格】支持点对点发送事件​<br/>I582XB 【新增规格】工具适配多用户<br/>I582UL 【增强特性】分布式通知同步增强<br/>I582QQ 【新增规格】通知发送支持设置未读角标<br/>I582XB 【新增规格】工具适配多用户<br/>I582SD 【DFX】【增强特性】通知DFX能力增强<br/>I582ST 【新增规格】支持配置通知清理事件<br/>I582TF 【增强特性】通知渠道信息设置和查询增强<br/>I58418 【新增规格】【事件通知子系统】事件通知子系统的SELinux策略配置<br/>I582Y4 【DFX打点】【事件通知子系统】提供系统事件、SA dump、trace打点 | NA |
| 分布式硬件子系统 | 新增DeviceManager支持同帐号凭据参数请求和导入等特性。<br/>I5IUUS  【DFX打点】【分布式硬件子系统】提供系统事件、SA dump、trace打点<br/>I5IUVN  【新增特性】支持同帐号凭据参数请求和导入 | NA |
| 用户IAM子系统 | - 持续增强用户认证的基础能力。<br/>- 新增用户IAM框架，支持指纹录入、认证、识别、删除功能。<br/>I5EPCD 支持完成指定用户的指纹录入【框架】<br/>I5EPCM 支持完成指定用户的指纹认证和指纹识别【框架】<br/>I5EPCU 支持完成指定用户的指纹认证删除【框架】 | NA |
| 编译构建子系统 | - 对python和gn进行版本升级。<br/>- 新增系统组件拆分独立编译。<br/>- 在模块依赖、编译功能开关及ccache方面提升编译性能。<br/>主要涉及如下需求：<br/>I5IZC2 【编译构建子系统】支持系统组件与芯片组件独立构建<br/>I5IZD9 【集成优化】模块依赖优化<br/>I5IZI0 【集成优化】提供编译功能选项开关<br/>I5IZH2 【集成优化】ccache优化 | NA |
| 多模输入子系统 | - 提供通过JS API访问输入设备信息。<br/>- 新增支持手写笔作为输入设备。<br/>- 新增支持按键自动重复的事件上报。<br/>- 新增支持SELinux。<br/>主要涉及如下需求：<br/>I530UN 【新增特性】窗口多热区分发机制<br/>I530UT 【新增特性】JS API Mock<br/>I530VY 【新增特性】支持通过JS API查看手写笔输入设备基础信息<br/>I530W0 【新增特性】支持通过JS API 查看鼠标输入设备扩展信息<br/>I530WA 【新增特性】支持通过JS API查看触摸板输入设备扩展信息<br/>I530WD 【新增特性】支持通过JS API查看触摸屏输入设备扩展信息<br/>I530WH 【新增特性】支持Linux Input手写笔功能按键输入事件接收并分发<br/>I530WI 【新增特性】支持Linux Input手写笔压感合成<br/>I530WJ 【新增特性】支持Linux Input手写笔倾角<br/>I530WK 【新增特性】支持触摸点压力属性<br/>I530WM 【新增特性】支持触摸点触摸区域属性<br/>I530WO 【新增特性】支持触摸点工具区域属性<br/>I530WP 【新增特性】支持触摸点工具类型属性<br/>I530X8 【新增特性】支持通过配置文件配置按键映射规则<br/>I530XH 【新增特性】支持系统按键通过配置文件配置按键映射规则<br/>I530XJ 【新增特性】支持系统按键自动重复<br/>I530XK 【新增特性】支持键盘类型识别<br/>I530XL 【新增特性】支持按键能力识别<br/>I530XM 【新增特性】支持键盘通过配置文件配置按键映射规则<br/>I530XN 【新增特性】支持键盘按键自动重复<br/>I530XT 【新增特性】支持通过C++ API按照相对坐标调整鼠标位置<br/>I530XX 【新增特性】支持触摸点压力属性<br/>I530XZ 【新增特性】支持触摸点触摸区域属性<br/>I530Y1 【新增特性】支持触摸点工具区域属性<br/>I530Y2 【新增特性】支持触摸点工具类型属性<br/>I530Y7 【新增规格】多模输入子系统支持64位<br/>I530YB 【DFX打点】【多模输入子系统】提供系统事件、SA dump、trace打点<br/>I530YF 【新增规格】【多模输入】【input】SELinux策略配置<br/>I5HMBS 【input部件】键鼠自适应布局适配 | NA |
| 泛Sensor服务子系统 | - 支持更多类型的传感器上报。<br/>- 支持SELinux。<br/>主要涉及如下需求：<br/>I53SFI 【DFX打点】【泛Sensor服务子系统】提供系统事件、SA dump、trace打点<br/>I537CB 【新增规格】泛Sensor能力持续集成-旋转矢量传感器<br/>I537AN 【新增规格】泛Sensor能力持续集成-重力传感器<br/>I5379T 【新增规格】泛Sensor能力持续集成-地磁传感器<br/>I5379C 【新增规格】泛Sensor能力持续集成-方向传感器<br/>I53784 【新增规格】泛Sensor能力持续集成-环境光传感器<br/>I53SFS 【新增规格】【泛Sensor服务】SELinux策略配置 | NA |
| 分布式数据管理子系统 | data_share支持多种数据类型。<br/>主要涉及如下需求：<br/>I5EHGF 【DataShare】DataShare支持多种数据储存类型 | NA |
| web子系统 | - 新增支持JS相关交互能力。<br/>- 新增支持网络、键鼠、webstorage、SELinux策略等能力。<br/>主要涉及如下需求：<br/>I5DM1E 【新增规格】web组件的JS窗口管理<br/>I5DNG2 【新增规格】JS侧提供全量hittest接口以及DefaultUserAgent获取<br/>I5EK53 【新增规格】【web子系统】web组件http验证管理<br/>I5EGBB 【新增规格】【web子系统】【web部件】web子系统的SELinux策略配置<br/>I5EBG1 【新增规格】【web子系统】web子系统适配w3c network information api<br/>I5EVEC 【新增规格】【web子系统】web内核对接鼠标、键盘等外设能力<br/>I5FF2L 【新增规格】【web子系统】web组件支持webstorage | NA |
| 驱动子系统 | - 支持内核态驱动动态加载及DFX能力。<br/>- 提供Codec2.0接口及codec驱动模型。<br/>- Camera、Display、Audio、Sensor、WLAN等模块驱动能力增强。<br/>主要涉及如下需求：<br/>I536FN 【新增特性】【驱动子系统】支持HDI passthrough模式<br/>I5DJE5 【增强特性】兼容Linux uevent事件上报机制，增强设备即插即用功能<br/>I550OL 【新增特性】提供DFX跟踪定位，获取信息能力<br/>I544XP 【新增特性】支持HDF服务SELinux权限检查 标准系统<br/>I528DG 【新增特性】支持Codec 2.0参考实现，简化适配难度<br/>I50I6S 【新增特性】Audio新增IPC模式与直调模式接口调用统一<br/>I5A6H6 【增强特性】增强显示设备管理,支持多屏显示能力<br/>I5B0C5 【新增特性】Camera支持实现Meta类型的流<br/>I5B0BR 【新增特性】录像模式自拍镜像功能<br/>I5AJW1 【新增特性】支持Linux libALSA音频接口兼容<br/>I56V2N 【新增特性】HDF WLAN DAL HDI功率模式相关接口的定义与开发<br/>I5F411 【增强特性】马达效果能力增强 | NA |
| USB服务子系统 | - 支持USB服务广播消息。<br/>- 增加SELinux安全策略。<br/>主要涉及如下需求：<br/>I59MYK 【新增特性】USB服务广播消息<br/>I5AR8N 【新增规格】【USB服务子系统】USB服务子系统的SELinux策略配置 | NA |
| 内核子系统 | - 新增支持内存精细化管控特性。<br/>- 新增支持关联服务adj调整机制。<br/>主要涉及如下需求：<br/>I58LOD 【新增特性】支持关联服务adj调整机制<br/>I54Y5J 【新增特性】支持memtrack内存占用和进程维度adj查询接口特性<br/>I56B3Q 【新增特性】支持OnMemoryLevel特性<br/>I5B694 【新增特性】支持新型内存精细化管控特性<br/>I59O8H 【新增特性】支持purgeable memory特性<br/>I5CXOK 【新增特性】支持hyperhold可靠性提升特性 | NA |


### 


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

  **表4** 新增Samples

| 子系统 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| 元能力 | MissionManager | 本示例通过调用系统任务管理的能力，对系统任务执行锁定、解锁、清理、切换到前台等操作。 | ArkTS |
| 网络管理 | AirQuality | 空气质量（Air quality）的好坏反映了空气污染程度，它是依据空气中污染物浓度的高低来判断的。空气污染是一个复杂的现象，在特定时间和地点空气污染物浓度受到许多因素影响。来自固定和流动污染源的人为污染物排放大小是影响空气质量的最主要因素之一，本示例实现了一个简单空气质量应用，使用折行显示能力显示空气质量信息，使用柱形图展示历史记录。 | ArkTS |
| ArkUI | TransitionAnimation | 本示例展示了转场动画的使用，包括页面间转场、组件内转场和共享元素转场。 | ArkTS |
| 应用程序包管理 | ZipLib | 本示例通过构建解压，压缩文件场景，向用户展示\@ohos.zlib接口。 | ArkTS |
| 工程能力 | Npm | 本示例展示了npm引用第三方js类库和本地库，主要展示了mathjs、dayjs和本地库应用。 | ArkTS |
| 数据管理 | DistributedMusicPlayer | 本示例使用fileIo获取指定音频文件，并通过AudioPlayer完成了音乐的播放完成了基本的音乐播放、暂停、上一曲、下一曲功能；并使用DeviceManager完成了分布式设备列表的显示和分布式能力完成了音乐播放状态的跨设备迁移。 | ArkTS |
| ArkUI | PatternLock | 本示例展示了图案密码锁组件的使用，实现了密码设置、验证和重置功能。 | ArkTS |
| 安全 | UserAuth | 本示例展示了用户认证中人脸识别功能。 | ArkTS |
| 安全 | Cipher | 本示例展示了加解密算法，包括RSA加密算法与AES加密算法。 | ArkTS |
| 图形图像 | Screen | 本示例监听屏幕数量变化，创建、销毁虚拟屏幕模拟屏幕增减，读取屏幕属性并显示。 | ArkTS |
| ArkUI | Search | 本示例展示了Search组件的使用，使用Search组件实现一个搜索界面。 | ArkTS |
| 设备管理 | USBManager | 本示例展示了USB设备管理的使用，包括USB设备插拔状态监听和USB设备信息显示。 | ArkTS |
| 数据管理 | DistributedDataGobang | 五子棋是一款比较流行的棋类游戏，此游戏使用分布式数据管理功能进行开发完成的。 | ArkTS |
| 媒体 | Image | 本示例仿照相册应用，读取本地设备中图片，获取图片信息，可对图片进行旋转操作。 | ArkTS |
| 安全 | AbilityAccessCtrl | 本示例通过模拟应用申请权限场景，向用户展示@ohos.abilityAccessCtrl接口。 | ArkTS |
| 网络管理 | WebSocket | 本示例展示了WebSocket的使用，包括客户端与服务端的连接和断开以及客户端数据的接收和发送。 | ArkTS |
| 通信与连接 | Bluetooth | 蓝牙技术是一种无线数据和语音通信开放的全球规范，它是基于低成本的近距离无线连接，为固定和移动设备建立通信环境的一种特殊的近距离无线技术连接。本示例实现蓝牙设备发现，配对，取消配对功能。 | ArkTS |
| 媒体 | GamePuzzle | 拼图Demo是基于Grid组件进行开发，通过image (图片处理)和medialibrary (媒体库管理)接口实现获取图片，以及图片裁剪分割。 | ArkTS |
| 网络管理 | UploadDownload | 上传就是将文件从个人终端设备传送至远程服务器，下载是将文件从远程服务器传送至个人终端设备，进而实现文件的存储，该示例使用上传下载的接口实现文件的上传下载。 | ArkTS |
| 设备管理 | Location | 本示例使用方向传感器及GPS，实现获取当前位置信息。 | ArkTS |
| 电话服务 | Observer | 本示例通过observer接口订阅网络状态、信号状态、通话状态、蜂窝数据、sim状态等事件，并获取状态变化返回的结果。 | ArkTS |
| ArkUI | AdaptiveCapabilities | 此Demo展示在ArkTS中的多设备自适应能力，包括资源限定词、原子布局和响应式布局。 | ArkTS |
| ArkUI | JsAdaptiveCapabilities | 此Demo展示在JS中的多设备自适应能力，包括资源限定词、原子布局和响应式布局。 | JS |

请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。


## 修复缺陷列表

  **表5** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [I4Z3G9](https://gitee.com/openharmony/graphic_graphic_2d/issues/I4Z3G9) | 【RK3568】打开沉浸式主窗口和在主窗口上打开辅助窗口出现闪屏 |
| [I59M4Q](https://gitee.com/openharmony/developtools_hdc/issues/I59M4Q) | API9 hdc_std连接设备低概率断连 |
| [I54D32](https://gitee.com/openharmony/multimedia_camera_framework/issues/I54D32) | 【RK3568】【必现】相机连续多次录像出现黑屏 |


## 遗留缺陷列表

  **表6** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I5I4GJ | 通过IDE连接rk3568设备概率断连 | DevEco Studio进行应用的运行和调试，通过hdc连接设备概率断连，断连概率1/25，断连后可以重连上，影响可控 | 2022年8月15号 |
| I5HTGF | 相机拍出来照片跟预览相比顺时针旋转90度 | 影响拍照后的图片的体验效果 | 2022年8月15号 |
| I5FUNB | linux内核漏洞同步<br/>CVE-2022-1462 | 内核CVE漏洞当前社区无补丁，待内核社区补丁发布后同步到Beta2分支 | 跟随内核社区补丁发布时间 |
| I5FUO1 | linux内核漏洞同步<br/>CVE-2022-21127 | 内核CVE漏洞当前社区无补丁，待内核社区补丁发布后同步到Beta2分支 | 跟随内核社区补丁发布时间 |
