# OpenHarmony 3.2 Beta1

## 版本概述

当前版本在OpenHarmony 3.1 Release的基础上，更新支持以下能力：

**轻量系统基础能力增强**

轻量LiteOS系统和Linux系统IPC归一，构建和完善了进程间通信能力。

**标准系统基础能力增强**

新增支持针对Arm 64位的系统版本编译构建能力。

图形支持安全截图、安全录屏；支持嵌入其他应用界面显示能力。

窗口支持快速切换桌面和恢复应用窗口、窗口唤醒屏幕、保持屏幕常亮/窗口调整屏幕亮度、安全图层等能力。

方舟虚拟机支持多实例调试，以及条件断点和watch表达式能力。

多模输入支持遥控器、鼠标、键盘输入设备热插拔监听能力。

安全支持OpenHarmony跨设备之间的同帐号互信认证能力。

**标准系统分布式能力增强**

系统服务管理支持群组校验机制能力。

**标准系统应用程序框架能力增强**

ArkUI支持AbilityComponent组件将应用界面（Ability）作为控件嵌入其他应用显示；增强分栏与侧边栏组件能力，支持拖拽自动隐藏等能力。

包管理支持沙箱应用的安装、卸载、查询，拆包工具支持Stage模型能力。

元能力支持Stage模型支持Worker机制，新增ANR、应用主线程卡死检测等DFX能力。

**标准系统应用能力增强**

图库支持基础动效，支持图片编辑保存能力，提供OEM定制开发能力。

**标准系统应用开发样例**

新增图形GPU资源绘制、扫雷游戏、2048数字游戏等Demo样例，为开发者提供SDK使用的样例程序，方便开发者快速上手使用OpenHarmony系统基础能力。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.2&nbsp;Beta1 | NA |
| SDK | Ohos_sdk_full&nbsp;3.2.2.5 (API&nbsp;Version&nbsp;9 Beta1) | NA |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0 Beta3 for&nbsp;OpenHarmony | OpenHarmony应用开发推荐使用 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.0 Release | OpenHarmony智能设备集成开发环境推荐使用 |


## 源码获取


### 前提条件

1. 注册码云gitee账号。

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
  repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta1 --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
  ```
  repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta1 --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
  ```
  repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta1 --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
  ```
  repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta1 --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）        | 3.2 Beta1  | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/code-v3.2-Beta1.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/code-v3.2-Beta1.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）        | 3.2 Beta1  | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/standard_rk3568.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制）        | 3.2 Beta1  | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_pegasus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-LiteOS（二进制） | 3.2 Beta1  | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-Linux（二进制）  | 3.2 Beta1  | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统SDK包（Mac）                    | 3.2 Beta1  | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/ohos-sdk-mac.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/ohos-sdk-mac.tar.gz.sha256) |
| 标准系统SDK包（Windows\Linux）          | 3.2 Beta1  | [站点](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/ohos-sdk.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2-Beta1/ohos-sdk.tar.gz.sha256) |

## 更新说明

本版本在OpenHarmony 3.1 Release的基础上有如下变更。


### 特性变更

**表3** 版本特性变更表

| 子系统名称 | 标准系统 | 轻量、小型系统 |
| -------- | -------- | -------- |
| 公共 | 新增支持Arm架构64位版本编译构建。 | 轻量、小型系统IPC接口归一。 |
| 资源调度 | 新增卡片使用记录信息统计能力。<br/>主要涉及如下需求：<br/>I531ST&nbsp;支持卡片卸载时，删除对应的卡片使用记录<br/>I531SU&nbsp;支持查询获取卡片使用记录<br/>I531SV&nbsp;支持记录卡片的使用计数以及使用时间 | NA |
| 多模输入 | 新增遥控器、鼠标、键盘输入设备热插拔监听能力。<br/>主要涉及如下需求：<br/>I530U7&nbsp;三方件json版本升级<br/>I530UH&nbsp;启动优化<br/>I530UU&nbsp;支持裁剪鼠标光标显示特性<br/>I530UL&nbsp;支持不可触摸窗口<br/>I530W5&nbsp;支持通过JS&nbsp;API监听遥控器输入设备的热插拔<br/>I530W9&nbsp;支持通过JS&nbsp;API监听鼠标输入设备的热插拔<br/>I530WB&nbsp;支持通过JS&nbsp;API查看触摸板输入设备扩展信息<br/>I530WF&nbsp;支持通过JS&nbsp;API监听键盘输入设备的热插拔<br/>I530UW&nbsp;支持裁剪配置组合按键特性 | NA |
| 系统服务管理 | 新增群组校验机制。<br/>主要涉及如下需求：<br/>I59XYB&nbsp;添加群组校验机制<br/>I53NZQ&nbsp;处理远端应用安装情况和版本号<br/>I568AO&nbsp;DMS上报分布式组件关联关系<br/>I58ZSB&nbsp;采集OS类型信息 | NA |
| 包管理 | -&nbsp;支持沙箱应用的安装、卸载、查询。<br/>-&nbsp;拆包工具支持Stage模型，打包工具能力增强。<br/>主要涉及如下需求：<br/>I524WG&nbsp;支持系统应用不允许清除的能力<br/>I524WP&nbsp;查询指定应用是否安装<br/>I524UF&nbsp;支持系统feature的升级（已安装entry的情况下）<br/>I524VP&nbsp;支持隐式查询的优先级<br/>I56W2U&nbsp;包管理支持BackupExtension类型<br/>I56W68&nbsp;将pack.info打到hap包中<br/>I56W6W&nbsp;支持将新旧hap包打包到同一个app包中<br/>I56W4O&nbsp;拆包工具将hap包中的rpcid文件提出<br/>I56W59&nbsp;拆包工具对stage模型包的解析<br/>I56W7H&nbsp;bms扫描完成后，发送扫描完成事件<br/>I56WIG&nbsp;包管理模块对外提供沙箱应用的安装能力<br/>I56WIS&nbsp;包管理模块提供对外沙箱应用的卸载能力<br/>I56WJ7&nbsp;包管理模块提供沙箱应用的包信息的查询能力 | NA |
| 基础通信 | 蓝牙支持人机接口设备接入能力。<br/>主要涉及如下需求：<br/>I58ZUA&nbsp;支持人机接口设备接入能力，如蓝牙键盘、鼠标、游戏手柄等 | NA |
| 元能力 | -&nbsp;FA模型支持查询/设置组件横竖屏状态、组件锁屏显示和组件启动亮屏。<br/>-&nbsp;新增ANR、应用主线程卡死检测等DFX功能。<br/>-&nbsp;新增Stage模型支持Worker机制。<br/>主要涉及如下需求：<br/>I58ZRH&nbsp;FA模型支持查询/设置组件横竖屏状态<br/>I58ZRI&nbsp;FA模型支持组件锁屏显示<br/>I58ZRJ&nbsp;FA模型支持组件启动亮屏<br/>I58ZRD&nbsp;ZIDL工具自动生成Extension&nbsp;Js服务端及客户端接口文件<br/>I58ZR5&nbsp;支持拦截uncatchedexception<br/>I58ZR6&nbsp;支持ANR处理<br/>I58ZR7&nbsp;运行管理服务线程卡死检测<br/>I58ZR9&nbsp;应用主线程卡死检测<br/>I58ZRA&nbsp;通用组件生命周期切换超时检测<br/>I58ZR1&nbsp;FA卡片能力补齐-支持删除无效卡片<br/>I58ZR2&nbsp;FA卡片能力补齐-支持卡片可见状态与更新状态单独设置<br/>I58ZQR&nbsp;提供Ability监听器<br/>I58ZQW&nbsp;提供调度组件生命周期相关的功能<br/>I50DOL&nbsp;Stage模型支持Worker机制 | NA |
| 媒体 | -&nbsp;新增OpenSL&nbsp;ES录音接口能力。<br/>-&nbsp;HiStreamer引擎支持标准设备音频播放。<br/>主要涉及如下需求：<br/>I58ZOI&nbsp;支持系统设置和获取总音量<br/>I58ZOJ&nbsp;支持音频用户权限控制<br/>I58ZOM&nbsp;支持OpenSL&nbsp;ES基础录音接口<br/>I59H9F&nbsp;HiStreamer引擎支持标准设备音频播放 | NA |
| 图形 | -&nbsp;支持安全截图、安全录屏。<br/>-&nbsp;支持嵌入其他应用界面显示。<br/>主要涉及如下需求：<br/>I58ZOX&nbsp;RenderService侧支持GPU合成<br/>I58ZOU&nbsp;支持安全截图、安全录屏（安全图层）<br/>I58ZOW&nbsp;支持窗口跨屏的扩展屏、拼接屏<br/>I58ZOT&nbsp;支持嵌入其他应用界面 | NA |
| 窗口 | -&nbsp;支持快速切换桌面和恢复应用窗口功能。<br/>-&nbsp;支持窗口唤醒屏幕。<br/>-&nbsp;支持窗口保持屏幕常亮/窗口调整屏幕亮度。<br/>-&nbsp;支持安全图层。<br/>-&nbsp;支持窗口可获焦属性/窗口可触摸属性。<br/>-&nbsp;支持窗口方向设置。<br/>-&nbsp;支持应用窗口显示在锁屏之上。<br/>-&nbsp;支持窗口装饰（decoration）。<br/>-&nbsp;应用主窗口支持全屏显示。<br/>-&nbsp;支持应用启动退出窗口控制。<br/>-&nbsp;支持为系统应用提供应用界面组合能力。<br/>主要涉及如下需求：<br/>I58ZP0&nbsp;支持Display显示大小（Density）设置<br/>I58ZP1&nbsp;提供快速切换桌面和恢复应用窗口功能<br/>I58ZP4&nbsp;支持窗口唤醒屏幕<br/>I58ZP5&nbsp;支持窗口保持屏幕常亮&nbsp;&nbsp;支持窗口调整屏幕亮度<br/>I58ZP6&nbsp;支持安全图层<br/>I58ZP7&nbsp;支持窗口可获焦属性&nbsp;支持窗口可触摸属性<br/>I58ZP8&nbsp;支持窗口方向设置<br/>I58ZPA&nbsp;支持应用窗口显示在锁屏之上<br/>I58ZPD&nbsp;支持窗口装饰<br/>I58ZPE&nbsp;应用主窗口支持全屏显示<br/>I58ZPG&nbsp;支持应用启动退出窗口控制<br/>I58ZPI&nbsp;支持应用启动窗口<br/>I58ZPJ&nbsp;支持为系统应用提供应用界面组合能力 | NA |
| 网络管理 | -&nbsp;新增WebSocket&nbsp;JS&nbsp;API。<br/>-&nbsp;兼容system.fetch。<br/>-&nbsp;兼容system.network。<br/>主要涉及以下需求：<br/>I53CKH&nbsp;支持兼容system.fetch<br/>I53CKT&nbsp;支持WebSocket<br/>I53CJX&nbsp;支持兼容system.network | NA |
| 全球化 | -&nbsp;支持获取资源的同步接口，支持按资源名称获取资源，支持获取float等类型资源。<br/>-&nbsp;新增对MCC/MNC类型限定词资源的支持。<br/>-&nbsp;支持应用内不同模块独立编译。<br/>-&nbsp;支持获取区域偏好的年月日顺序。<br/>-&nbsp;获取本地文字的读音表达，例如汉字转拼音。<br/>主要涉及如下需求：<br/>I596AO&nbsp;支持MCC/MNC限定词<br/>I58ZSE&nbsp;资源管理接口能力增强<br/>I58ZSG&nbsp;资源ID生成<br/>I4WM02&nbsp;音译<br/>I4WK2O&nbsp;日期顺序获取 | NA |
| ArkUI | -&nbsp;支持组件布局边界显示。<br/>-&nbsp;增强XComponent组件的鼠标操作，并且优化了输入法弹出时的布局调整，在应用性能方面进行了优化。<br/>-&nbsp;增强分栏与侧边栏组件能力，支持拖拽自动隐藏功能。<br/>-&nbsp;AbilityComponent组件支持，支持将应用界面（Ability）作为控件嵌入其他应用显示。<br/>主要涉及需求如下：<br/>I58ZPY&nbsp;支持解码降采样图片性能化<br/>I58ZPX&nbsp;支持CPU提频优化动画性能<br/>I58ZPW&nbsp;新增AbilityComponent组件<br/>I58ZPS&nbsp;XComponent组件鼠标事件<br/>I58ZPR&nbsp;支持输入框拉起输入法应用时自动布局<br/>I58ZPQ&nbsp;分栏、侧边栏支持自由拖拽到小于最小宽度后自动隐藏功能<br/>I58ZPP&nbsp;图形绘制/辅助类组件支持显示布局边界<br/>I58ZPO&nbsp;按钮/选择/信息展示/动效类组件支持显示布局边界<br/>I58ZPN&nbsp;文本/输入/图片/视频/媒体类组件支持显示布局边界 | NA |
| 程序访问控制 | -&nbsp;新增SELinux针对service、hdf_service的标签保护能力。<br/>-&nbsp;新增Native服务的权限配置及校验能力。<br/>主要涉及需求如下：<br/>I58ZO1&nbsp;针对service，提供selinux标签保护能力<br/>I58ZO2&nbsp;针对hdf_service，提供selinux标签保护能力<br/>I58ZO3&nbsp;accessToken支持native服务的权限校验机制 | NA |
| 公共基础类库 | TypedArray和SharedArrayBuffer支持ECMA&nbsp;2021规范。<br/>主要涉及如下需求：<br/>I58ZPZ&nbsp;支持TypedArray&nbsp;2021规范<br/>I58ZQ0&nbsp;支持&nbsp;shard&nbsp;array&nbsp;buffer&nbsp;2021规范 | NA |
| 语言编译运行时 | -&nbsp;方舟虚拟机支持多实例调试，以及条件断点和watch表达式。<br/>主要涉及如下需求：<br/>I58ZQE&nbsp;方舟支持多实例调试<br/>I58ZQD&nbsp;方舟支持条件断点<br/>I58ZQB&nbsp;方舟支持watch变量及表达式<br/>I58ZQ8&nbsp;支持TSAOT优化编译器生成代码支持ArkJS运行时GC特性<br/>I58ZQ7&nbsp;支持TSAOT优化编译器后端机器码生成框架适配 | NA |
| 升级服务 | 新增适配RK&nbsp;3568。<br/>主要涉及如下需求：<br/>I58ZSM&nbsp;update_service部件支持RK&nbsp;3568升级适配<br/>I58ZSO&nbsp;updater部件支持RK&nbsp;3568升级适配 | NA |
| Misc软件服务 | 补齐API6前的http文件上传、下载接口。<br/>主要涉及如下需求：<br/>I58ZSC&nbsp;【download】支持\@system.request接口<br/>I53J82&nbsp;&nbsp;【upload】支持\@system.request接口 | NA |
| 文件管理 | -&nbsp;支持特殊沙箱的可配置能力。<br/>-&nbsp;三方应用存储查询能力。<br/>主要涉及如下需求：<br/>I58ZS6&nbsp;支持应用沙箱差异化配置的能力<br/>I58ZS9&nbsp;支持为三方应用提供存储查询的能力<br/>I58ZSA&nbsp;适配HUKS&nbsp;HAL层新接口<br/>I58ZS3&nbsp;支持分布式公共数据访问框架的版本升级能力 | NA |
| 事件通知 | -&nbsp;新增支持代理通知，提供代理三方应用发送通知能力。<br/>-&nbsp;增强通知渠道信息查询和设置的能力。<br/>主要涉及如下需求：<br/>I582UB&nbsp;支持代理通知<br/>I582TF&nbsp;通知渠道信息设置和查询增强 | NA |
| 泛Sensor服务子系统 | 泛sensor新增适配环境光传感器。<br/>主要涉及如下需求：<br/>I53784&nbsp;泛sensor能力持续集成-环境光传感器<br/>I538PX&nbsp;SystemAPI同步相关实现 | NA |
| 分布式数据管理 | 新增提供分布式对象sample。<br/>主要涉及如下需求：<br/>I4WO0S&nbsp;提供分布式对象sample | NA |
| 驱动 | -&nbsp;支持动态加载内核驱动能力。<br/>-&nbsp;外设模块HAL能力增强及HDI接口完善。<br/>主要涉及如下需求：<br/>I4UD9W&nbsp;支持内核态动态驱动加载机制，提高设备驱动开发、调试效率<br/>I54566&nbsp;相机服务和HDI循环依赖整改<br/>I50I6S&nbsp;Audio新增IPC模式与直调模式接口调用统一<br/>I54FQG&nbsp;提供codec设备驱动模型，支持codec类型设备<br/>I544XP&nbsp;支持HDF服务SELinux权限检查<br/>I4UL98&nbsp;ADC适配Linux内核IIO框架 | NA |
| 编译构建 | -&nbsp;新增支持Stage新模型的各种HAP包随版本代码编译<br/>-&nbsp;支持三方开源软件作为单独部件，当其被其他部件依赖时，编译系统自动安装到镜像，不需要配置到产品列表中<br/>-&nbsp;对python、jinja2、markupsafe做了版本升级<br/>-&nbsp;支持编译时定制设备类型<br/>-&nbsp;支持区分编译user/root版本<br/>-&nbsp;支持预编译的模块配置删除符号表<br/>-&nbsp;归一化轻富设备产品配置<br/>主要涉及如下需求：<br/>I53FCL&nbsp;兼容支持Stage新模型HAP包随版本编译<br/>I54ZLX&nbsp;支持三方开源软件作为单独部件，当其被其他部件依赖时，编译系统自动安装到镜像，不需要配置到产品列表中<br/>I54ERB/I52MRL/I52KTV&nbsp;对被cleansource&nbsp;3.1识别EOM的开源软件进行版本升级<br/>I5714O&nbsp;支持编译定制化ohos.para<br/>I4Q9MI&nbsp;支持预编译的模块配置删除符号表<br/>I56M93&nbsp;归一化轻富设备产品配置 | -&nbsp;对python、jinja2、markupsafe进行版本升级<br/>-&nbsp;支持区分编译user/root版本<br/>主要涉及如下需求：<br/>I54ZLX&nbsp;支持三方开源软件作为单独部件，当其被其他部件依赖时，编译系统自动安装到镜像，不需要配置到产品列表中<br/>I54ERB/I52MRL/I52KTV&nbsp;对被cleansource&nbsp;3.1识别EOM的开源软件进行版本升级<br/>I4Q9MI&nbsp;支持预编译的模块配置删除符号表 |
| 测试 | -&nbsp;测试用例执行支持筛选，按类型、粒度、级别筛选。<br/>-&nbsp;UI测试框架新增滑动查找等接口能力。<br/>-&nbsp;执行器支持部件化执行、支持错误用例复测。<br/>-&nbsp;稳定性工具支持报告解析、生成与展示，支持控件注入。<br/>主要涉及如下需求：<br/>I58ZUJ&nbsp;用例执行筛选能力<br/>I58ZUK&nbsp;UI测试框架能力增强：API接口补充增强<br/>I58ZUM&nbsp;UI测试框架能力增强：UI-dump功能开发<br/>I58ZUR&nbsp;UI测试框架能力增强：自定义UI操作参数支持<br/>I58ZUS&nbsp;测试调度框架支持配置<br/>I58ZUU&nbsp;测试调度框架支持部件化<br/>I58ZUV&nbsp;稳定性工具支持稳定性报告解析、生成与展示<br/>I58ZUW&nbsp;稳定性工具支持控件注入 | NA |
| 安全基础能力 | 新增OpenHarmony跨设备之间的同帐号互信认证能力。<br/>主要涉及如下需求：<br/>I58ZNS&nbsp;支持登录帐号的OpenHarmony设备之间执行同帐号互信认证<br/>I58ZNR&nbsp;支持OpenHarmony设备（登出帐号或被移除帐号后）移除本设备帐号认证凭据<br/>I58ZNP&nbsp;支持OpenHarmony设备导入/移除跨（同厂商或OEM厂商）帐号互信记录<br/>I58ZNT&nbsp;支持OpenHarmony设备（登录帐号或被绑定到帐号后）导入本设备帐号认证凭据（非对称凭据） | NA |
| 应用 | 图库应用支持图片编辑、动效能力。<br/>主要涉及如下需求：<br/>I58ZQ3&nbsp;【图库】图片编辑<br/>I58ZQ1&nbsp;【图库】动效<br/>I58ZQ4&nbsp;【联系人】基础能力-2D能力 | NA |

### API变更


_[API差异报告](api-diff/v3.2-beta1/Readme-CN.md)_

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### Samples

**表4** 新增Samples

| 子系统 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| ArkUI | [Vibrator](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator) | 本示例模拟倒计时场景，展示振动接口的使用方法。 | ArkTS |
| DFX | [FaultLogger](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/FaultLogger) | 本示例展示了在ArkTS中如何获取应用故障相关信息。 | ArkTS |
| ArkUI | [ComponentCollection](https://gitee.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/ComponentCollection) | 本示例为ArkUI中组件、通用、动画、全局方法的集合 | ArkTS |
| ArkUI | [ArkTSClock](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/ArkTSClock) | 本示例使用ArkTS&nbsp;UI能力实现一个简单的时钟应用。 | ArkTS |
| 网络管理 | [Http](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Http) | 本示例仿postman输入API接口地址，获取相应数据，介绍数据请求接口的用法。 | ArkTS |
| 网络管理 | [Socket](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Socket) | 本示例主要演示了Socket在网络通信方面的应用，展示了Socket在两端设备的连接验证、聊天通信方面的应用。 | ArkTS |
| 分布式数据管理 | [DistributedRdb](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedRdb) | 本示例展示了在ArkTS中分布式关系型数据库的使用，在增、删、改、查的基本操作外，还包括分布式数据库的数据同步能力。 | ArkTS |
| 元能力 | [WorkScheduler](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/WorkScheduler) | 本示例模拟下载更新包 、保存更新包、发送通知 、安装更新包实现升级，将下载任务通过后台任务管理进行处理，实现退出应用后任务仍能够执行，直至任务结束。 | ArkTS |
| 元能力 | [AbilityStartMode](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/AbilityStartMode) | 本示例展示了在一个Stage模型中，实现standard、singleton、specified多种模式场景。 | ArkTS |
| 媒体 | [MediaCollections](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/MediaCollections) | 本示例展示了在ArkTS中媒体管理合集，包括网络流播放能力，音视频播控能力以及音量调节能力。 | ArkTS |
| 元能力 | [ArkTSDistributedCalc](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/ArkTSDistributedCalc) | 本示例使用JS分布式能力实现了一个简单的计算器应用，可以进行简单的数值计算，支持远程拉起另一个计算器FA，两个FA进行协同计算。 | ArkTS |
| Web | [Browser](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser) | 本示例运用OpenHarmony系统提供的Stage模型与相关接口展示了一个简易的浏览器。 | ArkTS |
| 元能力 | [DeviceUsageStatistics](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceUsageStatistics/DeviceUsageStatistics) | 本示例主要展示了设备使用信息情况。 | ArkTS |
| ArkUI | [AdaptiveCapabilities](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/AdaptiveCapabilities) | 本示例展示在ArkTS中的多设备自适应能力，包括资源限定词、原子布局和响应式布局。 | ArkTS |
| ArkUI | [Game2048](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Game/Game2048) | 2048是一款比较流行的数字游戏，此游戏demo是grid组件基础上进行开发完成的。 | ArkTS |
| 一多设置典型页面 | [Settings](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Settings) | 本示例展示了设置应用的典型页面，其在小窗口和大窗口有不同的显示效果，体现一次开发、多端部署的能力。 | ArkTS |
| 分布式数据管理 | [Preference](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DataManagement/Preferences) | 本示例主要展示了首选项在主题切换方面的功能。 | ArkTS |
| 全球化 | [International](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Internationalnation/International) | 本示例展示了i18n，intl，resourceManager在ArkTS中的使用，使用相关api实现系统语言和地区设置、时间和时区设置，展示了区域格式化示例。 | ArkTS |

请访问[Samples](https://gitee.com/openharmony/applications_app_samples)仓了解更多信息。

## 修复缺陷列表

**表5** 修复缺陷ISSUE列表

| ISSUE单                                                      | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I4NRS5](https://gitee.com/openharmony/kernel_linux_5.10/issues/I4NRS5) | 【内核子系统】存在cve漏洞                                    |


## 遗留缺陷列表

**表6** 遗留缺陷列表

| ISSUE                                                        | 问题描述                                                   | 影响                                                         | 计划解决日期 |
| ------------------------------------------------------------ | ---------------------------------------------------------- | ------------------------------------------------------------ | ------------ |
| [I4Z3G9](https://gitee.com/openharmony/graphic_graphic_2d/issues/I4Z3G9) | 【RK3568】打开沉浸式主窗口和在主窗口上打开辅助窗口出现闪屏 | 影响开发者体验                                               | 2022-06-15   |
| [I59M4Q](https://gitee.com/openharmony/developtools_hdc/issues/I59M4Q) | 使用API 9的hdc_std连接设备小概率断连                       | 存在低概率断连（几率小于1/30）。可通过重启IDE或者hdc_std恢复。 | 2022-06-30   |