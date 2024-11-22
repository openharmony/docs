# OpenHarmony 5.0.1 Release


## 版本概述

OpenHarmony 5.0.1 Release版本对标准系统的能力进行持续完善，以快速迭代的方式推出API 13，相比5.0.0 Release版本，重点做出了如下特性新增或增强：

大量丰富了C API的能力，包括但不限于应用框架的应用查询能力、ArkTS的节点自定义属性设置能力、Preferences数据管理能力、文件管理能力、AVSession、事件通知、Wi-Fi/蓝牙/位置功能开关查询能力、蜂窝网络相关能力、剪贴板等。此外，还包括其他特性的优化和增强，例如优化了相机的能力，提供更丰富的拍摄场景；丰富和优化了Web组件的能力，等等。

更详细的特性新增与增强的说明如下：


### 应用框架

- 新增ArkTS和C API，用于支持创建应用子进程的能力。

- 新增C API，用于获取应用的信息，如缓存路径、文件加密模式、包名等。

- 支持设置应用级别的字体放大倍数。


### ArkUI

- 新增C API的节点自定义属性设置能力，以及ArkTS侧获取任意目标节点的自定义属性的能力。

- Navigation组件支持自定义标题栏位置、主副标题的字体样式。NavDestination组件支持设置底部工具栏样式，以及控制工具栏的显示与隐藏。

- 多个组件适配适老化场景，可随系统适老化的设置进行字体和组件尺寸的相应变化。涉及的组件包括：Dialog、SeletTitleBar、SwipeRefresher、SplitLayout、ComposeTitleBar、ExceptionPrompt、TreeView、Filter、GridObjectSortComponent、ProgressButton、ToolBar、TabTitleBar等。

- 增强RichEditor组件能力，包括可配置滚动条显隐状态、支持图片拖拽，以及完善了通用快捷键。


### 应用包管理

- 新增C API，用于查询应用入口呃MainElement信息。

- 支持三方HAR获取应用启动的want参数，用于启动宿主应用。


### 分布式数据管理

新增C API，支持获取、存储、删除Preferences键值对数据。


### 文件管理

- 提供C API，支持应用通过传入的URI获取文件名（带后缀）或者最后一层文件夹的名称。

- 支持对使用应用分身能力的应用进行备份恢复。


### 图形图像及窗口

**图形图像**

- Pixelmap模块新增C API，支持对colorspace执行操作。

- NativeImage新增支持设置默认读写方式和几何图形默认尺寸。

- 动画机制优化，在UIAbility退至后台时，有限循环动画停止至终止态并触发结束回调；无限循环动画不受UIAbility前后台影响，继续执行。

**窗口**

支持系统应用主动请求焦点。


### 媒体

**音频**

- 新增C API，支持AVSession的基础接入能力。

- 完善投播场景的错误码。

- 完善投播中返回的设备信息属性。

**相机**
- 新增镜头通用控制能力，包括镜头脏污检测、脚架检测、环形补光控制。

- 新增折叠屏镜头控制能力，包括按折叠状态上报前后置镜头状态以及支持自动切换镜头。

- 新增HDR拍照按HEIF格式输出的能力。

- 新增云端增强拍摄效果的系统能力。

- 新增视频分段式能力，拍摄视频后生成可供快速预览的视频，待高质量视频处理并存储到图库后删除快速预览视频，提升视频预览效率。

- 新增相机Meta检测的系统能力，支持笑脸、人脸/人眼及猫狗眼等检测上报。

- 新增深度流、拍照深度信息输出能力。

**图片**

新增Picture类型（一些包含特殊信息的图片可以解码为多图对象，即Picture类型），支持多图对象编解码和主辅图管理。适用于JPEG和HEIC图片。


### 事件通知

- 新增C API，支持查询通知使能状态、以及订阅、退订公共事件。

- 支持应用拉起系统的半模态通知设置页面。


### 基础通信

新增C API，支持查询Wi-Fi、蓝牙开关状态。


### 位置服务

新增C API，支持查询定位开关状态、启动定位、结束定位、位置上报。


### 电话服务

- 新增C API，支持获取蜂窝网络的驻网信息，包含网络注册状态、接入制式等。

- 新增C API，支持获取默认数据业务卡的信息。


### 电源

- 支持系统获取当前充电电流，新增用于获取当前设备电流的接口nowCurrent。

- 支持飞行模式关联温控管控的能力，开发者可通过定制温控策略来设置设备进入飞行模式。

- 支持根据WorkSource代理运行锁，辅助资源调度模块进行功耗控制。

- 对于低电量状态的设备，支持将其从睡眠状态（S3）唤醒后自动进入休眠状态（S4），实现超长待机的特性。


### 启动恢复

支持查询distributionOsApiName，获取API版本信息。


### ArkCompiler

- ASON支持解析字符串返回collections.Map。

- 提供带模板的taskpool接口，优化返回值结构，使返回值不需要做强行转换。


### 多模输入

- 新增键值，支持屏幕朗读自定义公共事件能力。

- 支持对连按5次电源键的组合操作进行检测的能力。

- 支持电源键和音量键事件监听。

- 提供红外频率查询和设置接口。


### 资源调度

新增VOIP长时任务类型，支持应用退至后台后进行音视频通话服务。


### 剪贴板

- 新增C API，支持复制和粘贴多种类型的数据、上报跨设备的数据变化。

- 支持检测剪贴板中是否存在指定格式的数据。


### Web

- 支持获取网页当前的滚动偏移量。

- Web组件资源响应对象（WebResourceResponse）支持检测响应数据是否已准备就绪，并新增了string、number、ArrayBuffer、object四种类型的资源响应数据。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 5.0.1 Release | NA | 
| Public SDK | Ohos_sdk_public 5.0.1.111 (API Version 13 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 | 
| HUAWEI DevEco Studio（可选） | 5.0.1 Release | OpenHarmony应用开发推荐使用。 | 
| HUAWEI DevEco Device Tool（可选） | 4.0 Release | OpenHarmony智能设备集成开发环境推荐使用。 | 


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 5.0.1 Release    | *上传中* | *上传中* | -- |
| Hi3861解决方案（二进制）        | 5.0.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_pegasus.tar.gz.sha256) | 28 MB |
| Hi3516解决方案-LiteOS（二进制） | 5.0.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 329 MB |
| Hi3516解决方案-Linux（二进制）  | 5.0.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/hispark_taurus_Linux.tar.gz.sha256) | 222 MB |
| RK3568标准系统解决方案（二进制）        | 5.0.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/dayu200_standard_arm32.tar.gz.sha256) | 13 GB |
| 标准系统Public SDK包（Mac）             | 5.0.1.111 | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.4 GB |
| 标准系统Public SDK包（Mac-M1）             | 5.0.1.111  | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.3 GB |
| 标准系统Public SDK包（Windows/Linux）   | 5.0.1.111   | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.1-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.5 GB |


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| -------- | -------- |
| I9S5ZN | 进程com.ohos.settings小概率出现因THREAD_BLOCK_6S卡在libunwind.z.so导致的appfrreze。 |
| I9S600 | 进程com.ohos.settings小概率出现因THREAD_BLOCK_6S卡在libark_jsruntime.so导致的appfrreze。 |
| IAB2U3<br>IAK2J2 | 进程audio_server下的OS_APAsyncRunne线程小概率出现因libaudio_client.z.so崩溃导致的cppcrash。 |
| IAIRFB | 进程com.ohos.note下的com.ohos.note线程小概率出现因libweb_engine.so崩溃导致的cppcrash。 |
| IAKLLD | 进程audio_server下的SaInit2线程小概率出现因libaudio_policy_service.z.so崩溃导致的cppcrash。 |
| IA56CU | 进程com.ohos.note下的com.ohos.note线程小概率出现因libweb_engine.so导致的cppcrash。 |
| IA5AMJ | 进程com.ohos.launcher小概率出现因THREAD_BLOCK_6S卡在libark_jsruntime.so导致的appfreeze。 |
| IA5AIT | render_service小概率出现因SERVICE_BLOCK导致的sysfreeze。 |
| IA6RFX | 进程bluetooth_service下的OSaInit0线程有较高概率出现因libbtservice.z.so崩溃导致的cppcrash。 |
| IA8KGR | 进程bluetooth_service下的OS_IPC_12_22172线程小概率出现因libbluetooth_server.z.so崩溃导致的cppcrash。 |
| IAQC64 | 随机打开几个应用，再打开设置。返回到桌面，再反复进入后台界面，设置会出现泄露，操作1次大概增长32KB。 |
| IASE04 | 在RK3568开发板对OpenHarmony进行内存测试，render_service进程的常驻内存实测值超规格基线31 MB。 |



## 遗留缺陷列表

**表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| I9SXZ8 | 进程com.ohos.contacts小概率出现因THREAD_BLOCK_6S卡在libark_jsruntime.so导致的appfreez。 | 异常出现后联系人应用进入通话记录查询通话记录卡顿，重启联系人应用可恢复。 | 12月15日 | 
| IA6RH6 | 进程com.ohos.settings有较高概率出现因THREAD_BLOCK_6S卡在libbtframework.z.so导致的appfreeze。 | 会又低概率造成“设置”应用卡死，重新打开“设置”可恢复。 | 12月15日 | 
| IASDWO | 通过浏览器访问微博首页的滑动帧率低于规格基线。 | 影响浏览体验。 | 12月15日 | 
| IAZYOO | RK3568开发板在执行WuKong整机随机压力测试过程有较高概率出现卡死现象。 | SystemUI进程长时间没有主线程日志打印，锁屏侧未收到多模相关事件分发导致该问题，按电源键可恢复，对用户影响有限，无需规避。 | 12月15日 | 
| IANQF3 | 在执行WuKong压测过程有较高概率出现重启现象。 | 问题出现会导致设备重启。<br/>该问题暂时无法规避。 | 12月15日 | 
| IB4L3E | 进程com.ohos.camera有较高概率出现因LIFECYCLE_TIMEOUT卡在libcamera_framework.z.so导致的appfreeze。 | 该问题因camera_host进程导致应用卡死，重启应用可解决。 | 12月15日 | 
| IAP85P | 启动进程优先级过低有小概率会被优先kill掉导致出现sysfreeze。 | 该问题会导致应用被关闭，重启应用可解决。 | 12月15日 | 
| I9SXZ8 | 进程com.ohos.contacts小概率因THREAD_BLOCK_6S卡在libark_jsruntime.so出现appfreeze。 | 该问题因联系人应用卡在了窗口的 windowStage.loadContent()方法产生，会导致应用卡死，重启应用可解决。 | 12月15日 | 
| IB36B2 | 进程com.ohos.mms小概率出现jscrash，问题栈为close。 | 该问题会导致短信应用闪退，重启应用可解决。 | 12月15日 | 

