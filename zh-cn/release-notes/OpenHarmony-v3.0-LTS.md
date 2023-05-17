# OpenHarmony 3.0 LTS

## 版本概述

当前版本在OpenHarmony 2.2 Beta2的基础上，针对标准系统、轻量系统和小型系统更新内容：

标准系统新增特性功能：

- 用户程序框架支持服务能力(ServiceAbility，DataAbility)和线程模型。

- 支持文件安全访问，即文件转成URI和解析URI打开文件的能力。

- 支持设备管理PIN码认证的基本能力。

- 支持关系型数据库、分布式数据管理基础能力。

- 支持方舟JS编译工具链和运行时，支持OpenHarmony JS UI框架应用开发和运行。

- 支持远程绑定ServiceAbility、FA跨设备迁移能力。

- 支持应用通知订阅与应用通知消息跳转能力。

- 支持输入法框架及支持输入基础英文字母、符号和数字。

- 相机应用支持预览、拍照和录像基础能力。

- 支持CS基础通话、GSM短信能力。

- 支持定时器能力，提供定时时区管理能力。

- 在标准设备间的分布式组网下，提供应用跨设备访问对端资源或能力时的权限校验功能。

轻量和小型系统新增特性功能：

- 新增轻量级分布式能力增强，支持从轻量级系统启动标准系统上的Ability。

- 软总线能力增强支持，提供认证通道传输能力，用于设备绑定。

- 轻量级全球化能力增强支持，新增31种语言支持。

- 轻量系统上新增权限属性字段及其写入接口，上层应用可通过该字段实现相关业务。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 3.0&nbsp;LTS | NA | 
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta1 | OpenHarmony应用开发推荐使用。 | 
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 2.2&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 | 


## 源码获取


### 通过repo获取

**方式** **一（推荐）**

通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 从镜像站点获取

**表2** 获取源码路径

| **LTS版本源码** | **版本信息** | **下载站点** | **SHA256校验码** | 
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.0 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0/code-v3.0-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0/code-v3.0-LTS.tar.gz.sha256) | 
| 标准系统解决方案（二进制） | 3.0 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0/standard.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0/standard.tar.gz.sha256) | 
| Hi3861解决方案（二进制） | 3.0 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_pegasus.tar.gz.sha256) | 
| Hi3518解决方案（二进制） | 3.0 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_aries.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_aries.tar.gz.sha256) | 
| Hi3516解决方案-LiteOS（二进制） | 3.0 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus.tar.gz.sha256) | 
| Hi3516解决方案-Linux（二进制） | 3.0 | [站点](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus_linux.tar.gz.sha256) | 
| Release&nbsp;Notes | 3.0 | [站点](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.0-LTS/zh-cn/release-notes/OpenHarmony-v3.0-LTS.md) | - | 


## 更新说明

本版本在OpenHarmony 2.2 Beta2的基础上有如下变更。


### 特性变更

**表3** 版本新增特性表

| 子系统名称 | 标准系统 | 轻量、小型系统 | 
| -------- | -------- | -------- |
| 分布式任务调度 | -&nbsp;新增远程绑定ServiceAbility基本功能<br/>-&nbsp;新增FA跨设备迁移功能<br/>-&nbsp;新增组件visible属性权限校验功能 | 新增小型系统启动HarmonyOS Ability的功能 | 
| 图形 | 对于带有GPU模块的芯片平台，支持使用GPU进行渲染合成，以提升图形性能，降低CPU负载 | NA | 
| 分布式硬件 | -&nbsp;支持基于分布式软总线认证通道的PIN码认证方案<br/>-&nbsp;支持PIN码认证授权提示弹窗<br/>-&nbsp;支持PIN码显示弹窗<br/>-&nbsp;支持PIN码输入弹窗 | NA | 
| 事件通知 | -&nbsp;支持应用通知订阅&nbsp;&amp;&nbsp;取消订阅<br/>-&nbsp;支持应用侧发布&amp;取消本地文本、图片通知<br/>-&nbsp;支持应用通知消息跳转能力<br/>-&nbsp;支持应用侧增加&amp;删除slot<br/>-&nbsp;支持通知流控处理、死亡监听能力 | NA | 
| 分布式软总线 | 软总线:<br/>-&nbsp;支持基于CoAP的主动发现和被动发现，支持通过BLE主动发现连接<br/>-&nbsp;支持基于WLAN网络的手动入网和自组网<br/>-&nbsp;支持基于WLAN网络，直通模式下的消息、字节、文件传输<br/>IPC:<br/>-&nbsp;支持设备内基于linux内核binder协议的进程间通信能力<br/>-&nbsp;支持对象和序列化数据通信<br/>RPC：<br/>-&nbsp;支持设备间基于分布式软总线的进程间通信能力<br/>-&nbsp;支持对象和序列化数据通信<br/>-&nbsp;接口与IPC保持一致 | 软总线:<br/>-&nbsp;支持基于CoAP的主动发现和被动发现<br/>-&nbsp;支持基于WLAN网络的手动入网和自组网<br/>-&nbsp;支持基于WLAN网络，直通模式下的消息、字节、文件传输<br/>IPC:<br/>-&nbsp;支持设备内基于Linux/LiteOS内核binder协议的进程间通信<br/>-&nbsp;支持char/int/long基础数据接口的序列化通信 | 
| 全球化 | 提供获取系统设置的语言、地区、区域信息，以及获取语言和地区的本地化名称的能力 | 轻量级全球化能力增强支持，新增31种语言支持 | 
| 系统应用 | -&nbsp;桌面：全新架构优化<br/>-&nbsp;SystemUI：<br/>&nbsp;&nbsp;-&nbsp;通知中心以及普通文本通知功能<br/>&nbsp;&nbsp;-&nbsp;控制中心：WLAN、飞行模式开关、亮度调节、声音调节<br/>&nbsp;&nbsp;-&nbsp;全新架构优化<br/>-&nbsp;设置：全新架构优化<br/>-&nbsp;相机：<br/>&nbsp;&nbsp;-&nbsp;支持基础拍照、录像功能<br/>&nbsp;&nbsp;-&nbsp;分布式协同：拉起对端相机并拍照 | NA | 
| 语言编译运行时 | 新增方舟JS编译工具链和运行时，支持OpenHarmony&nbsp;JS&nbsp;UI框架应用开发和运行 | NA | 
| 媒体 | -&nbsp;相机组件中新增录像功能<br/>-&nbsp;新增音频录制功能接口 | 新增支持播放mp3格式文件 | 
| JS&nbsp;UI框架 | -&nbsp;支持迁移相关生命周期<br/>-&nbsp;支持系统服务弹窗<br/>-&nbsp;支持使用JS开发service类型和data类型的Ability | NA | 
| 内核 | 新增支持OpenHarmony&nbsp;Common&nbsp;Linux&nbsp;Kernel&nbsp;5.10 | 小型系统新增支持OpenHarmony&nbsp;Common&nbsp;Linux&nbsp;Kernel&nbsp;5.10 | 
| DFX | -&nbsp;提供HiAppEvent应用事件打点的JS&nbsp;API<br/>-&nbsp;提供HiCollie卡死检测框架<br/>-&nbsp;提供HiTrace分布式调用链基础库 | NA | 
| 驱动 | 新增I2S、陀螺仪、压力、霍尔驱动模型 | NA | 
| 安全 | 在标准设备间的分布式组网下，提供应用跨设备访问对端资源或能力时的权限校验功能 | 轻量系统上新增权限属性字段及其写入接口，上层应用可通过该字段实现相关业务（如弹框授权场景下，用户拒绝授权后不再弹框） | 
| 电话服务 | -&nbsp;搜网功能模块：支持飞行模式设置、搜网模式设置（包括手动搜网和自动搜网）、LTE制式信号强度获取<br/>-&nbsp;SIM功能模块：支持PIN/PUK解锁、卡文件信息获取、卡账户信息的存取、卡状态获取<br/>-&nbsp;蜂窝通话功能模块：支持通话前后台切换、来电静音、呼叫保持与恢复、三方通话、DTMF<br/>-&nbsp;短彩信功能模块：支持SIM卡短信的增删改查 | NA | 
| 分布式文件 | -&nbsp;支持f2fs、ext4文件系统不同参数设置的分区挂载能力<br/>-&nbsp;支持文件安全访问，即文件转成URI和解析URI打开文件的能力<br/>-&nbsp;支持系统应用访问公共目录的能力 | NA | 
| 分布式数据管理 | -&nbsp;支持关系型数据库JS基础能力（增删改查等）<br/>-&nbsp;支持分布式数据管理JS基础能力（增删改查等） | NA | 
| 编译构建 | -&nbsp;支持编译arm64形态产品<br/>-&nbsp;支持编译ohos-sdk | NA | 
| 用户程序框架 | -&nbsp;支持ServiceAbility&nbsp;JS开发能力<br/>-&nbsp;支持DataAbility&nbsp;JS开发能力<br/>-&nbsp;HAP支持多Ability声明<br/>-&nbsp;本地Ability迁移到远程设备<br/>-&nbsp;应用任务栈保存与恢复<br/>-&nbsp;JS&nbsp;利用Zip库实现文件压缩和解压缩 | NA | 
| 杂散软件服务 | 支持定时器能力，提供定时时区管理能力 | NA | 


### API变更

API变更请参考：[JS API 差异报告](api-diff/v3.0-LTS/js-apidiff-v3.0-lts.md)


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表4** 轻量和小型系统解决的缺陷ISSUE列表

| ISSUE单号 | 问题描述 | 
| -------- | -------- |
| [I45AVP](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I45AVP) | 执行hilog落盘之后hilog命令执行失败 | 
| I47EPA | 入参为空或无效时，GetBundleSize接口返回错误 | 
| [I434AD](https://gitee.com/openharmony/multimedia_camera_lite/issues/I434AD) | Hi3516DV300轻量级系统常驻内存超基线 | 
| [I434P1](https://gitee.com/openharmony/multimedia_camera_lite/issues/I434P1) | Hi3518EV300轻量级系统常驻内存超基线 | 
| [I46I6K](https://gitee.com/openharmony/multimedia_media_lite/issues/I46I6K?from=project-issue) | 多媒体子系统相关代码存在安全编码问题 | 
| [I46E6S](https://gitee.com/openharmony/kernel_liteos_m/issues/I46E6S?from=project-issue) | 轻量级内核模块编译添加-Werror编译选项 | 
| I47ETO | 权限校验没有生效，使用测试&nbsp;bin&nbsp;直接调用无权限&nbsp;hap，期望查询失败返回&nbsp;0，结果查询成功 | 
| [I48A2I](https://gitee.com/openharmony/drivers_peripheral/issues/I48A2I) | Hi3516DV300轻量级版本调用AllocMem接口测试，单板挂死 | 
| [I42LCU](https://gitee.com/openharmony/kernel_liteos_m/issues/I42LCU) | 集成测试开发板移植指导中需增加线程不足的确认方法和配置线程个数的方法 | 
| [I3IPD7](https://gitee.com/openharmony/kernel_liteos_m/issues/I3IPD7) | 不支持osThreadExit/join函数需要在头文件中说明 | 
| [I3M12H](https://gitee.com/openharmony/kernel_liteos_a/issues/I3M12H) | 集成测试发送两个不同的信号，sigwait第二次等到的仍是第一个信号 | 
| [I47X2Z](https://gitee.com/openharmony/kernel_liteos_a/issues/I47X2Z?from=project-issue) | 集成测试&nbsp;在执行ActsIpcShmTest.bin脚本，出现大量未释放的共享内存 | 
| [I4BL3S](https://gitee.com/openharmony/kernel_liteos_a/issues/I4BL3S) | 集成测试fs_posix模块nfs用例跑多次会出现不停打印申请内存失败问题 | 
| [I490KZ](https://gitee.com/openharmony/kernel_liteos_a/issues/I490KZ) | FutexTest.testPthreadTimdOutRWlockWR用例执行失败 | 
| [I44SFO](https://gitee.com/openharmony/third_party_toybox/issues/I44SFO) | 集成测试在某个目录下mv一个文件后，再在此目录下创建同名文件并二次mv该文件失败，提示此文件不存在 | 

**表5** 标准系统解决的缺陷ISSUE列表

| ISSUE单号 | 问题描述 | 
| -------- | -------- |
| I46A6H | XTS子系统压力测试过程中libace.z.so异常导致ohos.samples.flashlight出现cppcrash异常 | 
| I48HLN | Demo&amp;应用子系统-&nbsp;[&nbsp;JsCanvas]&nbsp;清除的button功能未生效 | 
| [I46HH7](https://gitee.com/openharmony/drivers_peripheral/issues/I46HH7) | 驱动子系统-标准系统单板WLAN测试用例失败 | 
| [I4312A](https://gitee.com/openharmony/communication_dsoftbus/issues/I4312A) | 【2.2&nbsp;Beta2】【软总线】已组网，断1端网络后，自组网失败(GetAllNodeDeviceInfo返回null) | 
| [I43WIJ](https://gitee.com/openharmony/communication_dsoftbus/issues/I43WIJ) | 【2.2&nbsp;Beta2】【软总线】已组网，一端切换网络再切回，过程中组网未下线(无上下线回调) | 
| [I43KLC](https://gitee.com/openharmony/communication_dsoftbus/issues/I43KLC) | 【2.2&nbsp;Beta2】【软总线】注册节点状态监听，设备上线，设备再离线，offline回调调用了2次 | 
| [I47WTY](https://gitee.com/openharmony/communication_dsoftbus/issues/I47WTY) | 【3.0&nbsp;beta1】【软总线-传输】session&nbsp;id范围校验不严谨（有效范围1-16，校验时判断的是&gt;17） | 


## 遗留缺陷列表

**表6** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| [I48IM7](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I48IM7) | 运行hilog压力测试，hilogd异常重启，且hilog命令一直无法使用 | 压力测试下，低概率出现日志输出异常，调测场景可正常使用。 | 10月30日 | 
| I48YPH | 【软总线-组网】测试发现和组网性能(循环离网-发现-组网)110次组网失败3次 | 低概率3/110，失败后重新发起组网即可。 | 10月30日 | 
| [I4BVVW](https://gitee.com/openharmony/communication_dsoftbus/issues/I4BVVW) | 【软总线-组网】标准系统与手机开关网络自组网成功率97%失败3次需分析失败原因 | 低概率出现组网失败。 | 10月30日 | 
| I4BXWY | Hi3516音频录制后播放有杂音 | 仅在使用此开发板时，影响录制音频的播放体验效果。 | 10月30日 | 
| I4BXY1 | 视频录制后前几秒没声音，播放声画不同步，在板子播放会卡顿，音源较远时，有杂音 | 仅在使用此开发板时，影响录制视频的播放体验效果。 | 10月30日 | 
| [3ZJ1D](https://gitee.com/openharmony/kernel_liteos_a/issues/I3ZJ1D) | XTS权限用例压测用户态概率失败 | 仅在重复创建子进程的XTS压力测试场景，设置子进程uid失败，低概率问题。 | 10月30日 | 
