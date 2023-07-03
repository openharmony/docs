# OpenHarmony 4.0 Beta1


## 版本概述

OpenHarmony 4.0版本标准系统能力持续完善，ArkUI进一步完善组件能力和效果、应用框架优化了Extension能力、应用包支持不解压安装和跨应用共享、分布式数据管理新增统一数据管理框架（UDMF）、媒体进一步增强音频/媒体播放/媒体控制/相机的能力、事件通知新增应用角标管理、安全基础能力支持更多密钥管理的能力、ArkCompiler更新了c++工具链的相关工具版本、测试框架多个工具能力增强。

OpenHarmony 4.0 Beta1版本开始提供首批API Level 10接口。


### 应用框架

- Extension能力最小化管理，支持各类Extension根据业务场景开放API，防止敏感API的调用。

- 支持数据或文件的URI临时授权，应用可以把自己文件的读写权限授权给其他应用。

- 支持了UIExtension机制，用于实现有界面的Extension，UIExtension的界面可以嵌入到调用方应用的窗口上显示。目前已构建UIExtension基础能力：
  - 支持统一的UIExtension模板，接口含义清晰，服务开发标准化。
  - 支持原生默认的Extension界面展示，方便开发者快速实现Extension功能，同时也提供界面定制能力。

  后续版本会逐步提供Share、Picker等模板。

- 支持原子化服务的分享，应用开发者可以使用UIAbility组件提供的UIAbility.onShare()生命周期方法，设置要分享的数据。用户可以通过分享框把原子化服务和卡片分享到另外一台终端设备。


### ArkUI

基础组件增加或增强：

- 提供Extension组件，用于将一个应用的扩展功能，嵌入显示到另一个应用内，新增组件能力。

- 绘制组件Rect/Circle/Ellipse/Line/Polyline/Polygon/Path/Rect/Shape支持偏移、裁剪、遮罩等通用属性，增强绘制组件基础功能。

- 自定义弹框支持蒙层颜色及弹出动画自定义如允许开发者设置弹出动画效果的相关参数，增强弹框的开发者自定义功能。

- bindContextMenu/bindMenu支持自定义位置，允许开发者设置菜单的位置，增强菜单基础功能。

- ColumnSplit分隔线支持可拖动，增强组件基础功能。

- Refresh组件支持自定义下拉刷新能力，允许开发者设置下拉刷新时的显示内容，增强组件基础能力。

- 支持文本组件中返回输入字符串宽高的能力，用于字符串折叠显示时，鼠标悬浮可弹出字符串完整提示框，增强文本组件基础功能。

动画效果增加或增强：

- 组件属性变化支持过渡动效，如Divider组件配置分割条颜色和颜色属性时支持过渡动效，提升组件属性变化时动画效果的能力。

- 支持给组件设置球面高阶属性、下边缘像素扩展、取色模糊、G2圆角、阴影、渐变高阶图形属性，丰富开发者开发高阶动画效果的能力。

开发效率提升：

- Text/Image/Video/ListItem/GridItem组件支持用户长按组件默认进入拖拽行为，支持开发者关闭默认拖拽，提升开发者开发效率。


### 应用包管理

- 支持应用包不解压安装的特性，优化了系统启动性能和应用安装性能。

- 支持跨应用共享包，用于不同应用间的代码、资源共享。系统应用可以把自身的能力提供给三方生态应用使用，同时三方应用不需要在自身的安装包里集成相关内容（包括代码、资源以及.so文件等），从而达到减少生态应用的集成成本以及更新成本的目的。

- 支持企业应用的安装。校验企业应用的安装权限防止企业应用被随意的分发安装；提供企业应用证书信息查询以方便应用市场对企业应用的管理和吊销。


### 分布式数据管理

- 系统应用支持通过数据管理服务代理静默访问其他系统应用的DataShareExtension数据，即不拉起DataShareExtension所在的应用即可访问应用DataShareExtension的数据。

- 系统应用支持通过数据管理服务代理访问Single模式应用DataShareExtension的数据。

- DataShare客户端提供按URI前缀订阅DataShareExtension数据变化的能力，被订阅的URI前缀下任何DataShareExtension数据发生变化都会通知DataShare客户端。

- 新增统一数据管理框架（Unified Data Management Framework, UDMF），支持数据标准化模型、设备内数据拖拽、UDMF数据存储适配、权限管理、生命周期管理。


### 文件管理

- 支持文件分类视图管理能力，图库等应用以相册方式管理媒体文件（图片、视频无需关注具体存储位置），提供相册内添加、移除文件等功能不涉及具体的FileIO行为。API接口待后续版本开放。

- 提供增强的FileIO访问能力，支持randomAccessFile、moveDir、copyDir、watcher能力。

- 提供基于URI的文件临时授权访问及取消授权能力，支持文件的跨应用本地授权或跨设备授权。


### 图形显示、窗口

**图形**

- 支持组件自绘制内容的属性动画。

- 支持组件出现消失转场动画。

- 对统一渲染模式进行了性能优化，包含IPC性能优化（如通过共享内存方式传递渲染资源降低IPC通信量）、支持控件级别遮挡剔除仅需渲染上层控件降低GPU渲染工作量，使能硬件合成器提高合成能效等。

- 图片编解码支持SVG解码，GIF格式完善参数解析，如总帧数，时间间隔等。

**窗口**

- 支持监听窗口的获焦状态：之前版本，应用开发者仅可以监听WindowStage的获焦状态，但针对系统窗口和应用子窗口的获焦事件无法监听。现在，应用开发者可以通过在window上注册windowEvent的方式，监听单个窗口的获焦、失焦和显示隐藏状态。

- 支持将子窗口z轴顺序调整到顶层：之前版本对于应用中创建的多个子窗口，系统总是将最后显示窗口显示在所有子窗口的最顶层。同时，当前系统中默认会将用户触摸或者鼠标点击的窗口提升至所有子窗口的最顶层。现在，通过window对象的aiseToAppTop方法，应用开发者可以自行将某个子窗口调整至WindowStage多个子窗中的最顶层。

- 重构沉浸式实现方式，优化应用打开、退出、跳转下的动画效果：之前版本，应用打开时全屏应用窗口大小默认不包含状态栏和导航栏的区域，除非应用调用沉浸式接口（通过setWindowLayoutFullScreen或者setSystemBarEnable）。沉浸式应用在打开的过程中调用上述接口，会导致打开动画出现跳变，影响应用打开和应用间跳转动画的体验。新版本上，无论是否设置沉浸式显示，全屏显示的应用窗口大小都包含状态栏和导航栏的区域，而非沉浸式应用的状态栏、导航栏避让会通过ArkUI限制应用显示区域完成。

- 支持查询屏幕的显示模式：在Screen属性中增加了sourceMode字段，支持系统应用判断此屏幕是作为主屏幕显示、还是主屏幕的镜像或者扩展。

- 提供停止镜像和停止扩展API：在Screen中增加了stopMirror和stopExpand方法，除了可以设定镜像或者扩展显示虚拟屏幕、辅助屏幕，也可以设置停止镜像或者扩展模式显示。


### 媒体

**音频能力**

- 支持通过native接口进行音频播放和录制。

- 支持查询或监听当前优先级最高的播放设备。

- 闹钟音量支持独立调整。

- 支持音频焦点，应用播放音频时无需手动申请焦点，系统会在后台自动申请焦点，并自动执行焦点策略（如暂停、淡出、淡出恢复等）；应用仅需要注册焦点事件监听函数，以接收焦点事件并更新状态，如暂停时停止进度条。

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

- 支持带旋转角度视频的自动旋转播放功能。

**相机**

- 完善ArkTS API的错误码和异常处理机制，使开发者可以通过查询错误码定位错误信息。

- 支持前置预览镜像能力，默认情况下，前置预览画面呈镜像状态。

- 支持分布式摄像头查询该摄像头的主设备属性，包括设备名称和设备类型。

- 支持更精细化的分辨率查询，可以按照预览、拍照、录像用途查询支持的尺寸、格式和帧率信息。

- 相机框架提供横向归一化坐标系[0, 0, 1, 1]，所有与坐标相关的操作都基于这套坐标系完成。

- 不同相机应用使用同一个摄像头场景下，相机框架具备优先级管控和互斥策略。


### 事件通知

- 支持应用设置静态事件订阅的开关。

- 系统应用支持删除已发布的粘性事件。

- 支持应用设置代表通知数量的数字角标。


### 通信与连接

- 支持NFC eSE卡模拟能力。

- 支持WIFI连接AP时使用随机MAC的能力。

- 支持WIFI通过静态IP连接AP的能力。


### 安全

- 密钥管理提供如下能力：
  - 基于GID派生芯片级密钥的能力。
  - 支持国密密钥进行安全导入。
  - 支持二次身份认证的细粒度访问控制。
  - 密钥管理签名支持签名NO HASH模式。
  - 密钥管理算法支持运算时指定密钥参数。

- 支持小型设备查询其它设备的设备安全等级信息。

- 证书管理支持外部指定RSA密钥签名摘要及填充进行签名和验签能力。


### 程序访问控制

- 支持拉起应用维度的权限管理界面。

- 支持对系统应用的身份校验。


### ArkCompiler

- Taskpool支持优先级设置及自动扩缩容算法。

- 热重载增强，优化性能，支持多hap等场景。

- 支持多实例调优 。

- 支持异常函数的CFG构建。

- c++编译工具链更新：
  - clang/llvm工具链升级到15.0.4版本。
  - libc版本升级到1.2.3版本，libc库接口性能优化。
  - sigaction函数提供sigchain功能。


### 内核

- 支持HCK内核接口框架。

- 支持Linux内核config多级分层配置。


### 驱动

- 实现显示硬件合成驱动与芯片平台解耦，提供VDI接口，并独立出硬件合成进程。

- 提供显示驱动进程的死亡监听能力，提升系统故障恢复能力。

- 支持USB相机的热插拔事件检测、相机模组设备能力获取。

- 支持USB相机的预览驱动能力。

- 支持音频音效能力查询、音效描述符获取、创建及销毁音效实例等。

- 支持Sensor和Motion控制流及数据流的能力增强。


### 电源

- 增强系统电量等级查询及上报能力，电量等级支持裁剪和定制。

- 提供有线和无线充电类型上报，提供的充电类型包括普通充电、快速充电和超级快速充电。

- 增强运行锁的管控机制，明确系统电源状态和等级。

- 提供唤醒源设置能力，支持通过电源键、鼠标、键盘、触控板、屏幕、手写笔、皮套等方式唤醒设备。

- 提供休眠源设置能力，支持通过电源键、皮套、及超时自动休眠等方式设置设备休眠。

- 提供电源管理、电池管理、显示亮度管理、耗电统计及热管理的开发指南。


### 泛Sensor

- 1. 新增对设备所支持的预置振动效果进行查询的功能，开发者可通过EffectId查询某个振动效果在设备上是否被支持。

- 2. 新增振动全停接口，开发者无需传入对应的振动模式，可直接停止当前任意模式的振动。


### 测试框架

**测试框架arkxtest**

- 自动化脚本测试套嵌套定义能力，提升开发者脚本设计灵活性。

- 对象级断言能力，提升测试脚本断言能力。

- 模拟中文输入、模拟鼠标操作、区域截图能力。

**自测试执行框架developer_test**

- 测试任务管理能力，开发者通过任务ID执行历史任务，提升开发者自测试效率。

- 精准测试能力，支持子系统、部件、测试套、测试用例级测试用例筛选执行能力，提升开发者自测试效率。

- 对接执行hats用例，丰富执行用例范围。

**稳定性测试工具wukong**

支持旋转事件注入，增强注入能力。

**性能开发工具smartperf_host**

- Frame timeline抓取和展示能力，开发者可以抓取和展示卡顿丢帧检测的数据。

- Scheduling analysis抓取和展示能力，开发者可以抓取和展示CPU调度分析，线程调度分析相关数据。

- 调用栈可视化和不同库函数调用占比展示能力，调用栈可视化可以将开发者编译的so符号化结果展示出来，不同库函数的占比通过饼图的方式展示出来。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.0&nbsp;Beta1 | NA |
| Public&nbsp;SDK | Ohos_sdk_public&nbsp;4.0.7.5&nbsp;(API&nbsp;Version&nbsp;10&nbsp;Beta1) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco&nbsp;Studio默认获取的SDK为Public&nbsp;SDK。 |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 4.0&nbsp;Beta1 | OpenHarmony应用开发推荐使用。获取方式：<br />[Windows(64-bit)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/38/v3/efALRNm3TJuKHfv-1xzjew/devecostudio-windows-4.0.0.201.zip?HW-CC-KV=V1&HW-CC-Date=20230613T085338Z&HW-CC-Expire=315360000&HW-CC-Sign=49E7D85C8A485D5D1F04944DFE1AFCFEE3F60E03D25A01BEFE12BA6CEADD19E0)  <br />SHA256校验码：7d2885b052afb92af8eb2d28ce2704515cd5fdbe7dd01f874bcdd876e11b890a<br />[Mac(X86)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/71/v3/A3thi3-kRTSeO4Jp0DSigA/devecostudio-mac-4.0.0.201.zip?HW-CC-KV=V1&HW-CC-Date=20230613T085132Z&HW-CC-Expire=315360000&HW-CC-Sign=BA233FE054A7D07F4B1C3ED80C84F9DD29112E49BB6D5D1506C5A5A0238741AD)  <br />SHA256校验码：ce2582eac70e8e15abcded00065ae0047f3815fe2b0c90d56c0bdbc5561a51c3<br />[Mac(ARM)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/ed/v3/IFYYMuT9SbCPCHZntvlrKQ/devecostudio-mac-arm-4.0.0.201.zip?HW-CC-KV=V1&HW-CC-Date=20230613T085231Z&HW-CC-Expire=315360000&HW-CC-Sign=8F98E23E393E3D0D104BDBF7F33684D36C48613303909E6D04D016DB0E7E8696)  <br />SHA256校验码：5da2baad7475857a1c59315663b7dcdf85219ffd652d5a7be160c8d2225358a7 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.1&nbsp;Release | OpenHarmony智能设备集成开发环境推荐使用。获取方式：<br />[点击跳转至下载页面](https://device.harmonyos.com/cn/develop/ide#download) |


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0-Beta1 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/code-v4.0-Beta1.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/code-v4.0-Beta1.tar.gz.sha256) | 26.2 GB |
| Hi3861解决方案（二进制）        | 4.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_pegasus.tar.gz.sha256) | 25.1 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_taurus_LiteOS.tar.gz.sha256) | 287.6 MB |
| Hi3516解决方案-Linux（二进制）  | 4.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/hispark_taurus_Linux.tar.gz.sha256) | 186.4 MB |
| RK3568标准系统解决方案（二进制）        | 4.0 Beta1    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/dayu200_standard_arm32.tar.gz.sha256) | 4.5 GB |
| 标准系统Public SDK包（Mac）             | 4.0.7.5      | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/ohos-sdk-mac-public-20230605.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/ohos-sdk-mac-public-20230605.tar.gz.sha256) | 718.2 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.0.7.5      | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/L2-SDK-MAC-M1-PUBLIC-20230605.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/L2-SDK-MAC-M1-PUBLIC-20230605.tar.gz.sha256) | 673.2 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.0.7.5      | [站点](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/ohos-sdk-windows_linux-public-20230605.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0-Beta1/ohos-sdk-windows_linux-public-20230605.tar.gz.sha256) | 1.8 GB |

## 更新说明

本版本在OpenHarmony 3.2 Release的基础上有如下变更:

### API 

OpenHarmony 4.0 Beta1的API范围相比3.2 Release，API变更的清单请参见“[API差异报告](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Beta1/zh-cn/release-notes/api-diff/v4.0-beta1/Readme-CN.md)”。极少量接口的变更可能影响到已开发的应用（使用API 9或更早版本API开发的应用），变更影响的说明和接口的适配指导请参见“[changelogs](https://gitee.com/openharmony/docs/blob/OpenHarmony-4.0-Beta1/zh-cn/release-notes/changelogs/v4.0-beta1/Readme-CN.md)”。


### 特性变更

详见[版本概述](#版本概述)。

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

  **表3** 新增Samples

| 子系统 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| 媒体 | [媒体会话——控制方](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta1/code/BasicFeature/Media/AVSession/MediaController)（仅对系统应用开放） | 本示例主要展示了媒体会话（媒体控制方，MediaController）的相关功能，使用\@ohos.multimedia.avsession等接口实现媒体提供方与媒体控制方自定义信息的交互功能。 | ArkTS |
| 媒体 | [媒体会话——提供方](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta1/code/BasicFeature/Media/AVSession/MediaProvider) | 本示例主要展示了媒体会话（媒体提供方，MediaProvider）的相关功能，使用\@ohos.multimedia.avsession等接口实现媒体提供方与媒体控制方自定义信息的交互功能。 | ArkTS |
| 媒体 | [音频管理](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Beta1/code/BasicFeature/Media/Audio) | 本示例主要展示了音频的相关功能，使用\@ohos.multimedia.audio等接口实现音频的发声设备的切换与查询和音频焦点功能。 | ArkTS |

请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。


## 修复缺陷列表

  **表4** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| I70PRZ | 非沉浸式UI避让失效。 |
| I72F9P | 高概率由进程ohos.samples.distributedcalc下的IPC_2_29472线程导致libwindow_native_kit.z.so出现cppcrash。 |
| I6W7ZX | 非沉浸式窗口透桌面。 |
| I76QTN | 高概率由进程ohos.samples.distributedmusicplayer下的IPC_0_18272线程导致libruntime.z.so出现cppcrash |
| I71TCX | 无卡拨打电话，拉起CallUI不自动挂断。 |
| I77PZK | 高概率由进程com.ohos.systemui下的RSRenderThread线程导致libmali-bifrost-g52-g2p0-ohos.so出现cppcrash。 |
| I73CUZ | prepare_to_wait_event存在竞争，导致UAF。 |
| I770WV | 预览图片不能备份。 |
| I6ZDHJ | 全球化接口可选参数传入undefined需要按照默认值处理。 |
| I71KZA | 全球化接口可选参数传入null时，没有按照默认值处理。 |
| I6YT0U | 高概率由进程com.ohos.launcher下出现栈为libeventhandler.z.so出现appfreeze问题。 |
| I6YSE5 | 高概率由进程com.ohos.photos下的com.ohos.photos线程导致librender_service_base.z.so出现cppcrash。 |
| I77AUK | 分布式任务调度场景connectAbility绑定失败。 |
| I78J10 | 反复拖拽大文件夹导致桌面无响应。 |
| I7975U | 打开仿图库应用里的图片再返回的时候页面显示空白。 |


## 遗留缺陷列表

  **表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I78CH7 | 反复在dock栏添加/移除应用，导致libace.z.so出现内存泄露。 | 移动卡片到合法区域，ArkUI每次泄露99KB，非常用场景，应用重启后泄露问题消失，影响可控。 | 2023年7月15日 |
| I78CBC | 反复进入某相册的图片宫格浏览界面，导致libace.z.so出现内存泄露。 | 进入某相册的图片宫格浏览界面后返回，ArkUI每次泄露19KB，在应用上点击返回后，泄露问题消失，影响可控。 | 2023年7月15日 |
| I78C9W | 反复进入大图浏览界面后返回，导致libace.z.so出现内存泄露。 | 从图库进入大图浏览界面后返回，ArkUI模块每次泄露10KB，在应用上点击返回后，泄露问题消失，影响可控。 | 2023年7月15日 |
| I6U4ZT | 拍照后立刻断电源，图库的第一张图片点击打不开。 | 只有立刻断电场景有问题，需要适配一套新的媒体库接口，影响可控。 | 2023年6月30日 |
| I79752 | 中概率由进程com.ohos.smartperf下的.ohos.smartperf线程导致libark_jsruntime.so出现cppcrash。 | 非核心应用，&nbsp;不影响ARP指标，影响可控。 | 2023年6月30日 |
| I79P3K | 低概率由进程com.ohos.callui导致jscrash，栈名：onDestroy。 | 低概率，出现jscrash后，应用会被重新安装，不影响电话应用正常功能和使用。 | 2023年6月30日 |
| I79TCB | 低概率由进程com.ohos.note下的VizCompositorTh线程导致libweb_engine.soTh出现cppcrash。 | 低概率，出现jscrash后，应用会被重新安装，不影响note应用正常功能和使用。 | 2023年6月30日 |
