# OpenHarmony 3.1 Release


## 版本概述

当前版本在OpenHarmony 3.1 Beta的基础上，增强支持以下能力：

**标准系统基础能力增强**

本地基础音视频播放能力、视频硬编解码、相机基础预览、拍摄能力。

RenderService新渲染框架、2D/3D绘制能力、新的动画和显示效果框架。

窗口管理新框架，提供更加灵活的窗口框架能力，支持全屏、分屏、窗口化形态，支持跨窗口拖拽能力。

display管理能力，支持分屏，并增强亮灭屏管理能力；支持窗口动画和效果。

鼠标、键盘、触摸板的基本功能支持，常见传感器加速度、陀螺仪、霍尔、马达振动等的基本能力支持。

语言区域选择、新增/增强国际化特性、系统资源、rawfile资源。

时间时区同步的支持管理能力、新增对剪贴板、锁屏服务、静态壁纸、下载服务管理能力的支持。

系统服务状态监控功能、新增跨设备oncall能力（跨设备启动FA能力）、长时、短时及延迟任务调度能力。

内存管理功能增强、电源管理基本功能支持、增进程调度功能增强等特性。

本地帐号、域帐号与本地帐号绑定功能，分布式帐号ID派生和状态管理功能，本地应用权限管理、分布式权限的管理能力。

Wi-Fi STA、AP、P2P相关基本能力以及JS API、新增蓝牙BR、SPP、BLE相关的能力以及JS API、新增位置服务子系统，提供位置服务框架能力。

**标准系统分布式能力增强**

分布式软总线网络切换组网、P2P连接、流传输、蓝牙等能力。

支持硬件互助 ，资源共享，支持镜像和扩展投屏等。

设备上下线和PIN码认证等增强功能，存储管理、应用沙箱隔离、公共数据沙箱隔离等能力，支持分布式数据库，分布式数据对象，支持本地数据库访问和跨应用数据库访问等能力。

**标准系统应用程序框架能力增强**

ArkUI自定义绘制能力和Lottie动画能力、键盘、鼠标交互操作能力。

声明式Web组件、XComponent组件能力。

卡片能力，提供卡片添加、删除、刷新等基础能力。

多用户能力，提供适应多端的基础JS工具链及运行时能力，对多HAP安装、隐式查询、多用户、权限管理的基本功能支持，支持分布式通知，通知模板功能。

**标准系统应用能力增强**

系统应用构建，包含系统桌面、SystemUI、系统设置、相机、图库、通话、联系人、信息、备忘录、文件选择器、输入法等应用支持。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.1 Release | NA |
| SDK | Ohos_sdk 3.1 Release (API Version 8 Release)<br/> Ohos_sdk 3.2 Canary (API Version 9 Canary) | NA |
| HUAWEI DevEco Studio（可选） | 3.0 Beta3 for OpenHarmony | OpenHarmony应用开发推荐使用 |
| HUAWEI DevEco Device Tool（可选） | 3.0 Release | OpenHarmony智能设备集成开发环境推荐使用 |

>说明： Canary版本为面向特定开发者发布的早期预览版本，不承诺API稳定性。



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


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）        | 3.1 Release  | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/code-v3.1-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/code-v3.1-Release.tar.gz.sha256) |
| Hi3516标准系统解决方案（二进制）        | 3.1 Release  | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/standard_hi3516.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/standard_hi3516.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）        | 3.1 Release  | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/standard_rk3568.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制）        | 3.1 Release  | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_pegasus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-LiteOS（二进制） | 3.1 Release  | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_taurus.tar.gz.sha256) |
| Hi3516轻量系统解决方案-Linux（二进制）  | 3.1 Release  | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统SDK包（Mac）                    | 3.1 Release  | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/ohos-sdk-mac.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/ohos-sdk-mac.tar.gz.sha256) |
| 标准系统SDK包（Windows\Linux）          | 3.1 Release  | [站点](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/ohos-sdk.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/3.1-Release/ohos-sdk.tar.gz.sha256) |
| 标准系统SDK包                          | 3.2 Canary   | 仅支持通过HUAWEI DevEco Studio加载 | NA |
| 编译工具链获取清单                      | -            | [站点](https://repo.huaweicloud.com/harmonyos/os/2.0/tool_chain/) | -                                                            |




## 更新说明

本版本在OpenHarmony 3.1 Beta的基础上有如下变更。


### 特性变更

**表3** 版本特性变更表

| 子系统名称 | 标准系统 | 轻量、小型系统 |
| -------- | -------- | -------- |
| 资源调度 | -&nbsp;新增长时、短时及延迟任务调度能力。<br/>-&nbsp;新增提醒后台代理能力。<br/>主要涉及如下需求：<br/>I4QT41【新增特性】提醒代理管理<br/>I4QU0W【新增特性】短时任务后台管理<br/>I4QT3S【新增特性】长时任务管理<br/>I4QU0P【新增特性】延迟任务调度<br/>I4QT45【新增特性】查询指定时间范围内的应用使用历史统计数据 | NA |
| 多模输入 | -&nbsp;新增对鼠标、键盘、触摸板的基本功能支持。<br/>-&nbsp;新增全屏手势的事件订阅能力。<br/>主要涉及如下需求：<br/>I4WWRZ&nbsp;【多模】鼠标按键功能<br/>I4WWS0&nbsp;【多模】鼠标滚轮功能<br/>I4WWSR&nbsp;【多模】按键基本功能<br/>I4WWT8&nbsp;【多模】触摸板基本功能<br/>I4WWSN&nbsp;【多模】订阅单系统按键输入事件 | NA |
| 系统服务管理 | -&nbsp;新增系统服务状态监控功能。<br/>-&nbsp;增动态加载本地系统服务功能。<br/>-&nbsp;新增DeviceProfile增删改查及同步功能。<br/>-&nbsp;新增DeviceProfile事件注册功能。<br/>-&nbsp;新增迁移框架对分布式对象、应用栈信息迁移的能力。<br/>-&nbsp;新增跨设备oncall能力（跨设备启动FA能力）。<br/>-&nbsp;新增实时获取远端设备任务、快照信息能力。<br/>主要涉及如下需求：<br/>I4MBRV&nbsp;【samgr】系统服务状态监控<br/>I4MBRY&nbsp;【samgr】系统服务进程管理<br/>I4NY1T&nbsp;【device_profile】订阅profile信息变化<br/>I4NY1W&nbsp;【device_profile】向业务端提供同步profile能力<br/>I4NY1X&nbsp;【device_profile】提供查询远程设备profile记录功能<br/>I4OGD1&nbsp;【新增特性】【DMS】支持组件间跨设备的onCall调用<br/>I4OGCK&nbsp;【增强特性】框架等待分布式对象同步完成后返回迁移结果<br/>I4OGCL&nbsp;【增强特性】【框架】迁移数据保存<br/>I4OGCN&nbsp;【增强特性】【DMS】根据指定设备发起迁移能力，接收迁移结果<br/>I4OGCM&nbsp;【新增特性】【任务管理】提供获取实时任务接口 | I4TS0Z&nbsp;【新增】轻量系统samgr支持远程服务管理 |
| 分布式硬件 | -&nbsp;新增分布式硬件子系统，包括分布式硬件管理框架、分布式相机，分布式屏幕三个代码仓。<br/>-&nbsp;完善设备管理功能，提供周边设备发现，上下线和PIN码认证等增强功能。<br/>主要涉及如下需求：<br/>I4PZE7&nbsp;【增强特性】支持周边不可信设备的发现<br/>I4PZDZ&nbsp;【增强特性】支持帐号无关设备的PIN码认证<br/>I4PZDY&nbsp;【增强特性】支持可信设备列表查询、上下线监听<br/>I4WVOC&nbsp;【新增特性】分布式硬件使能/去使能和动态加载<br/>I4WVMX&nbsp;【新增特性】分布式硬件接入管理<br/>I4WW6U&nbsp;【新增特性】支持分布式Screen的镜像/扩展显示 | I4XSUZ&nbsp;【新增特性】轻量系统支持设备管理基础功能 |
| 电源子系统 | 对于标准系统：<br/>新增电源管理、电池管理、热管理、耗电统计的基本功能支持。<br/>主要涉及如下需求：<br/>I40IRO&nbsp;【电源管理】支持休眠和混合睡眠模式<br/>I412F4&nbsp;【电源管理】支持省电模式<br/>I4MBRL&nbsp;【电源管理】支持显示相关的能耗调节<br/>I4MBRM&nbsp;【电源管理】支持接近光控制锁，通话时通过接近光控制亮灭屏的特性<br/>I4OEOZ&nbsp;【电源管理】监控输入亮屏输入事件，并根据输入事件进行亮、灭屏<br/>I4OEQT&nbsp;【电源管理】不亮屏检测<br/>I4QGI0&nbsp;【电源管理】长按power&nbsp;Key弹出关机界面<br/>I410YD&nbsp;【电池管理】支持关机充电特性<br/>I410Y1&nbsp;【电池管理】电池温度异常关机保护<br/>I4GY9U&nbsp;【热管理】支持内核温控服务<br/>I4GYAF&nbsp;【热管理】支持用户层和服务温控服务<br/>I4GYBV&nbsp;【热管理】提供温升监控接口<br/>I4GYCD&nbsp;【耗电统计】支持软件耗电统计<br/>I4GYCN&nbsp;【耗电统计】支持硬件耗电统计<br/>I4GYDQ&nbsp;【耗电统计】支持耗电详情记录 | NA |
| 帐号子系统 | -&nbsp;新增支持本地帐号（也称为系统帐号）的生命周期管理功能，包括本地帐号的创建、切换、删除、订阅、查询、修改等功能<br/>-&nbsp;新增分布式帐号ID派生和状态管理功能，在分布式帐号登录时派生唯一的帐号ID并将其与当前本地帐号唯一绑定，在分布式帐号登出或token失效时解除与本地帐号的绑定关系。<br/>-&nbsp;新增域帐号与本地帐号绑定功能，根据传入的域帐号信息自动创建本地帐号并与其唯一绑定。<br/>-&nbsp;新增本地帐号辅助管理工具：acm命令，可通过acm&nbsp;create/delete/switch/dump等命令对本地帐号进行增删改查，通过acm&nbsp;--help查看对应指令说明。<br/>I4JBFB&nbsp;支持分布式组网帐号状态管理<br/>I4JBEK&nbsp;支持分布式组网帐号ID的派生<br/>I4IU6N&nbsp;支持本地多用户基础信息管理<br/>I4IU5W&nbsp;支持os_account_standard部件本地多用户生命周期管理需求<br/>I4IU5G&nbsp;支持本地多用户辅助管理工具<br/>I4IU3V&nbsp;支持域帐户和本地用户关联<br/>I4IU3B&nbsp;支持本地多用户启动、停止、切换动作<br/>I4IU33&nbsp;支持本地多用户功能设置与内容修改 | NA |
| 内核子系统 | -&nbsp;新增内存管理功能增强特性，提高内存使用效率，包括CMA复用、内存共享接口，增强swap等。<br/>-&nbsp;新增进程调度功能增强特性，提高cpu资源的使用效率，增强滑动场景的资源供给，包括cpu热插拔及轻量级隔离，绘帧线程优先供给机制等。<br/>-&nbsp;支持最新的内核安全漏洞补丁修复，及其他安全增强机制，如支持tokenid配置及查询等。<br/>主要涉及如下需求：<br/>I4MBTN【新增特性】支持CMA复用特性<br/>I4MBTO【新增特性】支持内存占用分类查询<br/>I4LKQ0【新增特性】cpuset与cpu热插拔解耦<br/>I4QE9K【新增特性】提供内核态驱动与用户态之间、用户态与用户态之间的内核共享能力<br/>I4LRGQ【新增特性】OpenHarmony内核基线使能<br/>I4RXQ3【新增特性】内存管理基础特性<br/>I4TEGS【新增特性】F2FS末端性能优化<br/>I4SRVK【新增特性】支持CPU轻量级隔离特性<br/>I4SE2N【新增特性】支持按照用户维度进行内存资源管控的能力<br/>I4VMGZ【新增特性】支持基础FPS智能感知调度功能<br/>I4U089【新增特性】内核调度支持绘帧线程优先供给机制<br/>I4OWTZ【外部依赖】内核实现进程的tokenID设置 | NA |
| 包管理子系统 | -&nbsp;新增对多HAP安装、隐式查询、多用户、权限管理的基本功能支持。<br/>-&nbsp;新增DBMS、跨设备同步等分布式能力的支持<br/>-&nbsp;新增zlib&nbsp;Native&nbsp;SDK支持<br/>主要涉及如下需求：<br/>I4MBSD【新增特性】支持多hap包安装<br/>I4MBSG【增强特性】安装包信息查询<br/>I4PKY7【新增特性】跨设备信息同步<br/>I4PKY8【新增特性】跨设备信息查询<br/>I4PKYK【增强特性】启动扫描<br/>I4PKYI【新增特性】提供清除数据的能力<br/>I4PKYM【新增特性】支持多用户创建<br/>I4QA3D【增强特性】新增zlib解压、压缩数据native接口<br/>I4SIH9【新增特性】应用申请权限管理<br/>(Canary) I4PKYH 【新增特性】支持对Extension的查询<br/>(Canary) I4PKYD 【新增特性】安装能力适配config.json调整<br/>(Canary) I4PKYB 【增强特性】schema适配配置文件重构 | NA |
| 位置服务子系统 | -&nbsp;新增位置服务子系统，提供位置服务框架能力。<br/>-&nbsp;位置服务框架支持GNSS基本定位、GNSS围栏、GNSS&nbsp;Batching、网络定位能力、地理编码转换等能力框架服务。<br/>主要涉及如下需求：<br/>I4XXIH&nbsp;【location_gnss】供GNSS性能提升的相关辅助信息请求和注入能力<br/>I4XXIG&nbsp;【location_gnss】提供GNSS硬件功耗统计以及功耗优化能力<br/>I4XXIF【location_gnss】提供GNSS基本定位功能<br/>I4XXIC【location_gnss】提供GNSS&nbsp;Batching的能力<br/>I4XXIB【location_gnss】支持GNSS参数设置和信息上报功能<br/>I4XXI8【location_locator】支持位置服务的安全管理能力<br/>I4XXI7【location_locator】提供位置服务隐私的安全保障能力<br/>I4XXI5【location_locator】支持管理多个定位请求，支持多应用同时请求定位<br/>I4XXI4【location_locator】支持位置服务定位管理功能<br/>I4XXI3【location_geofence】支持GNSS芯片相关的地理围栏功能<br/>I4XXI0【location_geocode】支持经纬度和地址互相转换<br/>I4XXHZ【location_network】支持网络定位能力<br/>I4XXHW【location_gnss】支持GNSS辅助协议 | NA |
| 基础通信子系统 | -&nbsp;新增WiFi&nbsp;STA、AP、P2P相关基本能力以及JS&nbsp;API，优化了STA、AP、P2P基本能力的连接体验。<br/>-&nbsp;新增蓝牙BR、SPP、BLE相关的能力以及JS&nbsp;API。<br/>主要涉及如下需求：<br/>**WiFi**：<br/>I4XXFG&nbsp;【新增特性】支持WiFi功耗统计以及功耗优化能力<br/>I4XXFF&nbsp;【新增特性】提供WiFi&nbsp;P2P基本能力<br/>I4XXFB【新增特性】支持P2P&nbsp;magiclink连接特性<br/>I4XXF7【新增特性】支持SoftAP&nbsp;5G及信道自动选择<br/>I4MBRI&nbsp;【新增特性】支持SoftAP基础特性<br/>I4MBRH【新增特性】支持STA基础特性<br/>**蓝牙**：<br/>I4XXGC【bluetooth_standard】支持蓝牙BR/EDR的基本能力<br/>I4XXFT【bluetooth_standard】提供A2DP&nbsp;profile相关能力以及JS&nbsp;API<br/>I4XXFP【bluetooth_standard】支持蓝牙BLE相关的基本能力<br/>I4XXFL【bluetooth_standard】支持蓝牙SPP能力，提供BR的数据传输能力<br/> | NA |
| 元能力子系统 | -&nbsp;新增卡片能力、Zidl工具支持C++服务端客户端代码自动生成、元能力测试框架、命令行工具能力增强。<br/>-&nbsp;新增多用户能力、任务栈重构、部件化解耦、应用常驻进程、应用异常检测增强、环境变化通知能力。<br/>主要涉及如下需求：<br/>I4PCM4&nbsp;【新增特性】上下文提供应用/Hap包/组件信息查询能力<br/>I4PCPP&nbsp;【新增特性】上下文适配多用户<br/>I4PCPV&nbsp;【新增特性】提供指定用户启动组件的系统接口<br/>I4PCQP&nbsp;【新增特性】支持singleuser的运行模式<br/>I4PCQU&nbsp;【新增特性】启动初始化默认用户<br/>I4PCGY&nbsp;【增强特性】新增卡片开发基类<br/>I4PCH9&nbsp;【增强特性】通过配置文件配置服务卡片<br/>I4PCLL&nbsp;【新增特性】JS提供的应用级别上下文<br/>I4PCLN&nbsp;【新增特性】Ability的状态恢复<br/>I4PCP1&nbsp;【新增特性】应用运行信息查询<br/>I4PCPG&nbsp;【增强特性】支持系统环境变化通知<br/>I4PCR8&nbsp;【增强特性】支持常驻进程开机启动<br/>I4PCV4&nbsp;【新增特性】支持任务切换<br/>I4PCVZ&nbsp;【新增特性】支持指定displayId启动Ability<br/>I4PCW3&nbsp;【增强特性】pendingwant机制支持跨设备启动通用组件<br/>I4PCH4&nbsp;【新增特性】卡片支持多用户<br/>I4PCM1&nbsp;【新增特性】提供ce/de级上下文<br/>I4PCVN&nbsp;【新增特性】支持任务快照获取和更新<br/>I4PPW6&nbsp;【增强特性】指定窗口模式启动组件<br/>I4PC3R&nbsp;【新增特性】提供卡片开发基础能力<br/>I4PQ0M&nbsp;【增强特性】上下文提供消息发送和监听能力<br/>II4PQ13&nbsp;【增强特性】上下文提供权限校验及权限申请接口<br/>I4PQ1E&nbsp;【增强特性】支持常驻进程异常恢复<br/>I4PQ1O&nbsp;【新增特性】支持NewWant<br/>I4PCPI&nbsp;【增强特性】支持系统环境查询<br/>I4PCRL&nbsp;【新增特性】测试框架整体功能<br/>I4PCVU&nbsp;【新增特性】通用组件call调用<br/>(Canary) I4QU0P【新增特性】延迟任务调度<br/>(Canary) I4PCRL【新增特性】测试框架整体功能<br/>(Canary) I4PCLL【新增特性】JS提供的应用级别上下文<br/>(Canary) I4PC3R【新增特性】提供卡片开发基础能力<br/>(Canary) I4PCS0【新增特性】提供Ability启动停止方法<br/>(Canary) I4PCRQ【新增特性】提供调度组件生命周期相关的功能<br/>(Canary) I4WVBL【增强特性】【AMS】支持跨设备任务迁移<br/>(Canary) I4PCP1【新增特性】应用运行信息查询<br/>(Canary) I4PCPI【增强特性】支持系统环境查询<br/>(Canary) I4PCPG【增强特性】支持系统环境变化通知<br/>(Canary) I4PQ0K【增强特性】扩展Extension独立进程运行<br/>(Canary) I4PPW6【增强特性】指定窗口模式启动组件<br/>(Canary) I4PCVZ【新增特性】支持指定displayId启动Ability<br/>(Canary) I4U457【增强特性】Uri权限校验接口<br/>(Canary) I4S8X4【增强特性】Uri权限动态授权<br/>(Canary) I4VUXP 支持wantAgent获取操作类型 | NA |
| 无障碍软件服务子系统 | -&nbsp;新增界面信息交换机制内部实现；<br/>-&nbsp;新增无障碍配置信息读取。<br/>主要涉及如下需求：<br/>I4X2EM【新增特性&nbsp;信息交换机制】按键拦截<br/>I4X2EN【新增特性&nbsp;信息交换机制】支持上报窗口节点信息<br/>I4X2ET【新增特性&nbsp;信息交换机制】支持控件节点信息上报<br/>I4X2EV【新增特性&nbsp;信息交换机制】焦点查询<br/>I4X2EY【新增特性&nbsp;信息交换机制】无障碍事件列表<br/>I4X2EZ【新增特性&nbsp;信息交换机制】无障碍事件信息<br/>I4X2F0【新增特性&nbsp;信息交换机制】无障碍动作发起<br/>I4X2F1【新增特性&nbsp;信息交换机制】辅助应用列表查询<br/>I4X2F2【新增特性&nbsp;信息交换机制】辅助应用状态查询与监听<br/>I4X2F3【新增特性&nbsp;信息交换机制】手势模拟<br/>I4X2F4【新增特性&nbsp;信息交换机制】触摸拦截<br/>I4X2EO【新增特性&nbsp;无障碍服务管理】目标应用连接<br/>I4X2EP【新增特性&nbsp;无障碍服务管理】辅助应用连接<br/>I4X2ER【新增特性&nbsp;无障碍服务管理】辅助应用更新<br/>I4X2ES【新增特性&nbsp;无障碍服务管理】无障碍字幕配置 | NA |
| 媒体子系统 | -&nbsp;新增支持本地基础音视频播放能力，支持视频硬编解码，支持主流音视频codec与封装格式，并易于生态厂商扩展。<br/>-&nbsp;新增支持相机基础预览、拍摄能力，及分布式相机能力。<br/>主要涉及如下需求：<br/>I4WYPP【audio_standard部件】支持蓝牙音频播放<br/>I4WYK8【audio_standard部件】支持Opensles基础播放接口<br/>I4WYW4【增强特性】支持相机会话管理<br/>I4WYVE【增强特性】支持基础拍照模式下的拍照功能<br/>I4WZ8G【新增特性】图片基础解码框架<br/>I4X5E1【新增特性】支持视频软解功能<br/>I4X552【新增特性】支持本地音视频播放<br/>I4X5Q9【新增特性】分布式媒体库-缩略图同步<br/>I4X5L5【新增特性】基础媒体数据库<br/>(Canary) I4WYOP 【audio_standard部件】音频焦点管理增强<br/>(Canary) I4WZBF 【新增特性】图片接收器<br/>(Canary) I4WYXI 【增强特性】支持相机会话管理<br/>(Canary) I4WYVE 【增强特性】支持基础拍照模式下的拍照功能<br/>(Canary) I4WYSW 【增强特性】支持基础拍照模式下的预览功能<br/>(Canary) I4X59J 【新增特性】支持视频录制 | NA |
| 图形子系统 | -&nbsp;构建了图形RenderService新渲染框架。<br/>-&nbsp;提供了2D/3D绘制能力支持。<br/>-&nbsp;支持新的动画框架。<br/>主要涉及如下需求：<br/>I4MBTY【render_service部件】【新增特性】新增UI框架渲染后端特性<br/>I4RKT3【composer部件】提供合成和送显的能力<br/>I4ZCGG【drawing部件】提供图形Native&nbsp;SDK能力<br/>I4RKSW【drawing部件】提供3D&nbsp;图形能力支持Native&nbsp;SDK能力<br/>I4MBTW【animation部件】提供基础动画框架 | NA |
| 窗口子系统 | -&nbsp;构建了窗口管理新框架，提供更加灵活的窗口框架能力，支持全屏、分屏、窗口化形态，支持跨窗口拖拽能力。<br/>-&nbsp;提供了display管理能力，支持分屏，并增强亮灭屏管理能力。<br/>主要涉及如下需求：<br/>I4R308【增强特性】：提供应用窗口创建管理能力，单个应用的多个Ability实例可以创建多个主窗口<br/>I4R309【增强特性】：提供应用窗口创建管理能力，支持启动窗口时设定窗口显示策略；提供窗口显示策略状态给应用（分屏、全屏、自由窗口）<br/>I4R30D【新增特性】：应用主窗口支持自由窗口显示，平铺和层叠布局<br/>I4R9P0【新增规格】：增强特性：<br/>1.&nbsp;提供Display管理能力<br/>2.&nbsp;提供通过物理屏幕插入拔出创建和销毁Display的能力<br/>3.&nbsp;提供多Display映射管理能力<br/>I4ZEKH【新增特性】：支持亮屏灭屏流程：<br/>1.&nbsp;支持从电源管理发起的休眠、唤醒、亮屏、灭屏请求<br/>2.&nbsp;支持收到请求后调用Render&nbsp;Server接口实现对对应的亮屏、灭屏、调整屏幕亮度操作<br/>(Canary) I4R30B 【新增规格】增强特性：提供应用窗口创建管理能力 | NA |
| 网络管理子系统 | I4XXHU【增强特性】支持TCP/UDP&nbsp;Socket<br/>I4XXHT【增强特性】支持http&nbsp;1.1/https/http2<br/>I4XXHS【增强特性】支持对Wi-Fi/蜂窝网络连接的管理和切换<br/>I4XXHP【增强特性】支持DNS解析和配置<br/>I4XXHN【增强特性】支持网络连接状态查询和网络连接状态变化通知<br/>I4XXHH【wpa_supplicant】提供基于NL80211的wpa、p2p能力<br/>I4XXHG【wpa_supplicant】提供magiclink能力 | NA |
| MSDP子系统 | I4WWRO【msdp】device_status部件标准化 | NA |
| 全球化子系统 | -&nbsp;新增支持语言区域选择。<br/>-&nbsp;新增/增强支持国际化特性（单复数、字符串排序、电话号码处理、日历&amp;本地历法、度量衡体系和格式化、时间段格式化、字母表检索、unicode字符属性、断词断行）。<br/>-&nbsp;新增支持系统资源。<br/>-&nbsp;新增支持rawfile资源。<br/>主要涉及如下需求：<br/>I4MBR0&nbsp;【增强特性】区域表示和属性<br/>I4MBR1&nbsp;【增强特性】单复数支持<br/>I4MBR2&nbsp;【增强特性】字符串排序<br/>I4MBR3&nbsp;【增强特性】电话号码处理<br/>I4MBR7&nbsp;【新增特性】日历&amp;本地历法<br/>I4MBR5&nbsp;【新增特性】度量衡体系和格式化<br/>I4MBQZ&nbsp;【增强特性】时间段格式化<br/>I4MBR4&nbsp;【新增特性】字母表检索<br/>I4MBR8&nbsp;【增强特性】unicode字符属性<br/>I4MBR9&nbsp;【增强特性】断词断行<br/>I4MBRA&nbsp;【新增特性】系统资源管理<br/>I4MBRB&nbsp;【新增特性】rawfile资源管理<br/>I4R2YA&nbsp;【新增特性】新增资源管理Native&nbsp;SDK接口 | NA |
| 软总线子系统 | -&nbsp;新增对网络切换组网能力的支持<br/>-&nbsp;新增对蓝牙能力的支持<br/>-&nbsp;新增对蓝牙文件传输能力的支持<br/>-&nbsp;新增对流传输能力的支持<br/>-&nbsp;新增对P2P连接能力的支持<br/>-&nbsp;支持基于P2P连接的文件和流传输的能力<br/>主要涉及如下需求：<br/>I4MBS0&nbsp;【新增特性】【组网】软总线支持网络切换组网<br/>I4XXEL&nbsp;【增强特性】软总线支持蓝牙<br/>I4XXEX&nbsp;【传输】文件传输（蓝牙)<br/>I4XXEO&nbsp;【增强特性】【传输】文件传输增强（NSTACK组件能力）<br/>I4XXEV&nbsp;【新增特性】【传输】流传输增强（NSTACK组件能力增强）<br/>I4XXEN&nbsp;【新增特性】【组网】软总线组网支持P2P连接<br/>I4XXEP&nbsp;【新增特性】【连接】软总线支持P2P连接<br/>I4XXES&nbsp;【新增特性】【传输】软总线支持P2P文件传输<br/>I4XXET&nbsp;【新增特性】【传输】软总线支持P2P流传输 | NA |
| ArkUI子系统 | -&nbsp;新增键盘、鼠标交互操作<br/>-&nbsp;新增声明式Web组件能力<br/>-&nbsp;新增声明式XComponent组件能力<br/>-&nbsp;新增声明式Canvas2D绘制能力与OffscreenCanvas离屏绘制能力<br/>-&nbsp;新增富文本显示能力<br/>-&nbsp;新增多种功能组件<br/>-&nbsp;增强多种组件自定义能力<br/>-&nbsp;增强调测能力<br/>主要涉及如下需求：<br/>I4MBV7&nbsp;【新增规格】滚动条样式自定义能力<br/>I4MBVO&nbsp;【新增特性】Popup组件增加内容自定义规格<br/>I4MBVP&nbsp;【新增特性】Canvas绘制能力支持<br/>I4MBVR&nbsp;【新增特性】触摸响应热区设置<br/>I4MBVS&nbsp;【新增特性】Lottie动画支持<br/>I4MBVU&nbsp;【新增特性】Menu组件增加内容自定义规格<br/>I4MBVV&nbsp;【新增特性】Swipe手势特性<br/>I4MBV9&nbsp;【新增规格】Tabs组件新增TabBar内容自定义规格<br/>I4MBVA&nbsp;【新增规格】Navigation组件新增标题栏设置规格<br/>I4MBVC&nbsp;【新增规格】工具栏组件增加内容自定义能力规格<br/>I4WTQY&nbsp;【新增特性】线性占比显示控件特性支持<br/>I4MBV3&nbsp;【新增规格】样式设置特性增加组件多态样式设置规格<br/>I4MBV5&nbsp;【新增规格】字母索引条组件增加提示菜单内容扩展规格<br/>I4WTQ2&nbsp;【新增规格】List组件增加内容拖拽能力规格<br/>I4WTQ4&nbsp;【新增规格】Grid组件增加内容拖拽能力规格<br/>I4WYNA&nbsp;【新增规格】Dialog弹窗组件特性增强：支持自定义位置弹窗<br/>I4WTQX&nbsp;【新增特性】图案密码组件特性支持<br/>I4QC4N&nbsp;【新增规格】Select组件支持<br/>I4QC4O&nbsp;【新增规格】TextInput组件能力增强<br/>I4WTPY&nbsp;【新增规格】文本组件支持鼠标拖拽选择文字规格<br/>I4WTRS&nbsp;【新增特性】XComponent组件特性支持声明式范式规格<br/>I4WTR9&nbsp;【新增特性】鼠标按键、滚轮事件支持<br/>I4WTQI&nbsp;【新增规格】拖拽能力增加鼠标拖拽规格<br/>I4RCRC&nbsp;【新增特性】样式状态编译转换支持<br/>I4WTPS&nbsp;【新增规格】新增Touch事件支持多点触控信息<br/>I4RCRF&nbsp;【新增特性】新增自定义组件支持访问子组件数据<br/>I4X27K&nbsp;【新增特性】新增侧边栏组件<br/>I4RA0G&nbsp;【新增规格】卡片支持鼠标悬停事件<br/>I4WTQV&nbsp;【新增特性】增加场景数据存储特性<br/>I4RCRK&nbsp;【DFX】ArkUI&nbsp;框架超时检测机制<br/>I4RCJ8&nbsp;【IDE工具支持】渲染流水线耗时打印<br/>I4RCRM&nbsp;【IDE工具支持】交互事件回调耗时打印<br/>I4WTR7&nbsp;【新增特性】Web组件能力支持<br/>I4WTRA&nbsp;【新增特性】路由信息分布式迁移支持<br/>I4X29K&nbsp;【新增特性】ContextMenu组件支持<br/>I4WTQJ&nbsp;【新增规格】输入组件键盘快捷键支持<br/>I4WTQK&nbsp;【新增特性】鼠标双击选字<br/>I4WTPG&nbsp;【新增规格】基础动画参数配置增强<br/>I4X26M&nbsp;【新增规格】列表容器支持鼠标框选和键盘鼠标组合键多选功能<br/>I4X26Y&nbsp;【新增规格】网格容器支持鼠标框选和键盘鼠标组合键多选功能<br/>I4WTR8&nbsp;【新增特性】焦点设置支持<br/>I4U5XM&nbsp;【新增规格】ArkUI&nbsp;Loader支持JS文件条件编译能力<br/>I4WTQN&nbsp;【新增特性】新增RichText标签<br/>(Canary) I4WTQV 【新增特性】增加场景数据存储特性 | NA |
| 程序访问控制子系统 | -&nbsp;新增对本地应用权限的定义、管理、授权、查询、鉴权功能的支持。<br/>-&nbsp;新增对分布式权限的管理、查询、鉴权、同步功能的支持。<br/>主要涉及如下需求：<br/>I4WVMH&nbsp;【新增规格】系统的应用权限初始化预置定义<br/>I4WVO9&nbsp;&nbsp;【新增规格】应用权限申请列表查询<br/>I4WVPH&nbsp;&nbsp;【新增规格】AT同步服务基本框架<br/>I4WVPV&nbsp;&nbsp;【新增规格】本地权限校验接口和机制<br/>I4WVQT&nbsp;&nbsp;【新增规格】native的Token创建和更新机制<br/>I4WVR3&nbsp;&nbsp;【新增规格】应用权限的设置接口和机制<br/>I4WVRG&nbsp;【新增规格】AT管理服务基本框架<br/>I4WVRR&nbsp;【新增规格】Hap应用token查询接口<br/>I4WVS6&nbsp;&nbsp;【新增规格】Hap应用的Token信息删除机制<br/>I4WVSI&nbsp;&nbsp;&nbsp;【新增规格】Hap应用的Token创建和更新机制<br/>I4TYDA&nbsp;&nbsp;【新增规格】token信息跨设备同步<br/>I4TYCV&nbsp;&nbsp;【新增规格】设备上线时的native进程的token信息同步<br/>I4V02K&nbsp;&nbsp;【新增规格】主体设备上应用授权状态更新同步<br/>I4V02Y&nbsp;&nbsp;【新增规格】主体设备上应用卸载时同步<br/>I4V032&nbsp;&nbsp;【新增规格】应用权限管理界面实现<br/>I4V038&nbsp;&nbsp;【新增规格】实现通过应用权限管理界面设置应用权限<br/>I4TYCK&nbsp;&nbsp;【新增规格】分布式权限校验接口和机制<br/>I4TYDO&nbsp;【新增规格】设备下线时的token信息删除<br/>I4SEZD&nbsp;&nbsp;【新增规格】动态权限弹窗界面实现<br/>I4SEZ7&nbsp;&nbsp;【动态权限设置】实现动态权限授权机制 | NA |
| 语言编译运行时子系统 | -&nbsp;语言编译运行时：提供适应多端的基础JS工具链及运行时，端侧提供JS引擎支撑应用运行。<br/>-&nbsp;TS/JS公共基础库：TS/JS公共基础类库提供基础功能及TS/JS多线程能力<br/>-&nbsp;TS/JS/C/C++工具链：支持开发者开发调试调优的基本需求<br/>-&nbsp;Lite&nbsp;Actor：轻量化Actor模型，共享字节码及虚拟机内部基础设施，优化目前JS引擎的实现，优化内存占用、提升启动性能。<br/>-&nbsp;High&nbsp;Perf&nbsp;Partial&nbsp;GC：方舟GC支持并发标记、并行标记、懒清理，减少50%的GC停顿时间，改善用户体验。<br/>&nbsp;&nbsp;主要涉及如下需求：<br/>&nbsp;&nbsp;I4W7ZR【新增规格】内存管理分配回收功能/HPP&nbsp;GC性能调优<br/>&nbsp;&nbsp;I4P7F7【语言编译运行时，图形图像，DRF】Native&nbsp;SDK整体集成<br/>&nbsp;&nbsp;I4WWKK【增强特性】Actor轻量化1.0 | NA |
| 升级服务子系统 | -&nbsp;升级服务子系统各部件的标准化<br/>-&nbsp;支持syscap机制<br/>主要涉及如下需求：<br/>I4WXHW【部件化专项】升级服务子系统部件标准化<br/>I4XXH6【SysCap】升级服务子系统支持SysCap机制 | NA |
| Misc软件服务子系统 | -&nbsp;新增时间时区同步的支持管理能力的支持<br/>-&nbsp;新增对剪切板数据项进行进行查询、设置、删除、替换等能力的支持<br/>-&nbsp;新增对锁屏服务管理能力的支持<br/>-&nbsp;新增对静态壁纸管理能力的支持<br/>-&nbsp;新增对下载服务管理能力的支持<br/>主要涉及如下需求：<br/>I4U2WR&nbsp;新增特性：时间时区同步管理<br/>I4ZTTE【新增特性】剪贴板数据项-支持将剪贴板数据项强制转换为文本<br/>I4ZTTO【新增特性】剪贴板数据-支持增加获取、删除、替换剪贴板数据中的数据项；支持查询与设置剪贴板数据属性<br/>I4ZTTZ【新增特性】系统剪贴板-支持获取、清理、查询剪贴板的剪贴板数据；支持剪贴板内容变化通知<br/>I4ZTZC【新增特性】锁屏管理服务-支撑多用户场景<br/>I4ZTZT【新增特性】锁屏管理服务-支撑系统开机、亮灭屏场景<br/>I4ZU1S【新增特性】静态壁纸<br/>I4ZTXT【request部件】下载管理-支持新建、移除、修改、查询下载任务、支持暂停、恢复下载任务、支持监听下载任务进度、下载状态变更通知；下载管理服务，提供系统下载管理DataAbility，处理下载任务数据的持久化，提供系统下载管理服务，处理应用接口权限检查、执行http下载和处理下载异常<br/>(Canary) I4ZTZC【新增特性】锁屏管理服务-支撑多用户场景<br/>(Canary) I4ZTZT【新增特性】锁屏管理服务-支撑系统开机、亮灭屏场景 | NA |
| 轻内核子系统 | NA | 对于轻量系统：<br/>I4RD3H&nbsp;M核增加了signal、pipe、poll、select等POSIX接口<br/>I4Q9OQ&nbsp;支持Cortex-M55架构<br/>I4Q9F2&nbsp;支持动态加载机制<br/>I4RD2M&nbsp;内核部件化 |
| 文件管理子系统 | -&nbsp;支持基础文件系统ext4/f2fs能力及相关工具，支持分布式文件系统跨设备文件访问能力。<br/>-&nbsp;支持设备存储管理功能，包括文件加密、空间管理与统计、多用户空间管理、外卡挂载管理等能力。<br/>-&nbsp;增强应用数据保护，建立应用沙箱隔离机制；优化用户数据管理，包括用户数据沙箱隔离安全性增强、用户文件访问框架与接口。<br/>-&nbsp;基础文件操作API能力补齐，包括statfs占用空间统计、文件访问异步接口等能力。<br/>主要涉及如下需求：<br/>I4RDNG【新增特性】【local_file_system】支持ext4/f2fs等用户态工具的能力<br/>I4RFBD【新增特性】【local_file_system】支持fat/exfat/ntfs等可插拔文件系统能力<br/>I4TTN8【新增特性】支持分布式文件系统的基础功能<br/>I4TTNG【新增特性】支持数据分类设备分级，控制数据流转规格<br/>I4TTGR【新增特性】【storage_manager部件】文件加密特性使能<br/>I4TTHQ【新增特性】支持外部存储访问需求<br/>I4TTJN【新增特性】支持外卡设备相关事件分发特性<br/>I4TTJV【新增特性】支持卷信息查询和管理特性<br/>I4XXIR【新增特性】响应多用户创建删除，进行用户目录创建和删除<br/>I4XXIY【新增特性】支持应用占用空间统计特性<br/>I4SNSU【新增特性】支持应用沙箱隔离能力<br/>I4XXIX【新增特性】支持file&nbsp;picker需要的JS&nbsp;API文件接口需求<br/>I4MBS2【新增特性】支持statfs&nbsp;API能力需求<br/>(Canary) I4XXIY 支持应用占用空间统计特性<br/>(Canary) I4TTJV 支持卷信息查询和管理特性<br/>(Canary) I4TTJN 支持外卡设备相关事件分发特性 | NA |
| 事件通知子系统 | -&nbsp;新增支持多用户。<br/>-&nbsp;新增支持分布式通知。<br/>-&nbsp;新增通知模板功能。<br/>主要涉及如下需求：<br/>I4PBOK&nbsp;【新增特性】通知支持多用户<br/>I4PBP7&nbsp;【新增特性】支持应用发送模板通知（调试能力）<br/>I4PBPE&nbsp;【新增特性】支持进度条通知<br/>I4PBPM&nbsp;【增强特性】分布式通知支持流控<br/>I4PBRM&nbsp;【新增特性】支持其他设备的通知点击后在本设备跳转<br/>I4PBRW&nbsp;【新增特性】支持设备级的分布式通知使能控制<br/>I4PBSE&nbsp;【新增特性】支持通知管理应用设置和查询应用级的分布式通知使能<br/>I4PBSP&nbsp;【新增特性】支持应用设置分布式通知能力是否使能<br/>I4PBT7&nbsp;【新增特性】分布式通知同步<br/>I4PBU3&nbsp;【新增特性】分布式通知联动取消<br/>I4PBUU&nbsp;【新增规格】&nbsp;支持通过config.json静态配置公共事件，支持通过wokscheduler静态拉起订阅者<br/>I4PBV9&nbsp;【新增规格】&nbsp;支持静态订阅者管控<br/>I4WTGK&nbsp;【新增特性】支持模板通知注册、查询和发送<br/>I4PBSZ&nbsp;【新增特性】根据设备状态决策通知是否提醒<br/>I4PBBV&nbsp;【新增特性】事件耗时调用<br/>I4PD0O&nbsp;【特性增强】通知发送使能能力增强<br/>I4PBQ1&nbsp;【增强特性】分布式通知能力支持dump命令<br/>I4PBR0&nbsp;【新增特性】支持其他设备的通知点击后在跨设备跳转<br/>I4PC2S&nbsp;【新增特性】公共事件支持多用户特性 | NA |
| 泛Sensor服务子系统 | -&nbsp;新增常见传感器加速度、陀螺仪、霍尔等的数据上报。<br/>-&nbsp;新增马达振动的基本能力。<br/>-&nbsp;新增通用算法能力和地磁场算法能力。<br/>主要涉及如下需求：<br/>I4WWTG【miscdevice部件】Miscdevice支持周边依赖<br/>I4WWTF【sensor部件】Sensor支持周边依赖<br/>I4WWTD【sensor部件】支持通用的算法接口<br/>I4MBRQ【sensor部件】地磁场水平强度、总强度<br/>I4MBRP【sensor部件】地磁场偏角和倾角 | NA |
| 分布式数据管理 | -&nbsp;新增对分布式数据对象能力的支持，分布式能力覆盖内存JS对象；新增分布式关系型数据管理能力，支持直接基于关系型表数据同步<br/>-&nbsp;新增按条件数据同步&amp;订阅能力，数据同步更精准<br/>-&nbsp;新增文件上传功能支持<br/>-&nbsp;构建数据加密和安全分级能力，完善数据流转过程的安全管控，支持多用户同步与隔离<br/>主要涉及如下需求：<br/>I4IBPH【distributed_kv_store】分布式数据服务缺失功能补齐<br/>I4MBRS【distributed_kv_store】分布式数据库支持按谓词查询条件进行数据库记录的跨设备同步和订阅<br/>I4MBRU【RDB】支持数据库加密<br/>I4NZVP【distributed_kv_store】提供分布式数据库JS&nbsp;API<br/>I4HAMI【data_share_ability】支持跨应用订阅数据库的变化<br/>I4NZP6【RDB】增加多表查询能力<br/>I4FZ6B【RDB】提供事务能力<br/>I4HAMI&nbsp;【data_share_ability】支持跨应用订阅数据库的变化<br/>I4PNX7&nbsp;&nbsp;【分布式RDB】数据存储需求<br/>I4HAMD【data_share_ability】支持对数据访问方式的控制<br/>I4H4FH&nbsp;【distributed_kv_store】分布式数据库支持分类分级<br/>I4H3M8【新增特性】分布式数据对象支持复杂类型<br/>I4HAMD【data_share_ability】支持对数据访问方式的控制<br/>I4PO00【分布式RDB】数据同步需求<br/>I4OTW6【distributed_kv_store】分布式数据库Query支持InKeys谓词<br/>I4RGFY【DataShare】基于ExtensionAbility新框架重构并提供单设备上跨应用数据共享能力<br/>I4H4FR【distributed_kv_store】支持多用户数据隔离和共享<br/>I4RGFY【DataShare】基于ExtensionAbility新框架重构并提供单设备上跨应用数据共享能力<br/>I4XXGF【request部件】文件上传功能 | 对于轻量、小型系统：<br/>分布式数据对象支持小型系统设备<br/>主要涉及如下需求：<br/>I4H3JJ分布式对象支持小型系统设备 |
| DFX子系统 | 新增系统和应用Watchdog检测，NativeCrash、JSCrash日志采集能力。<br/>新增JS应用异常行为检测模式能力。<br/>新增系统和进程状态信息导出能力，JS&nbsp;App获取底层内存、CPU、虚拟机信息的能力能力。<br/>新增分布式跟踪调试能力。<br/>增强流水日志、系统事件、应用事件能力。<br/>主要涉及如下需求：<br/>I4PJE3【新增特性】Standard设备上的hidumper框架和工具<br/>I4MBRE【hiperf部件】性能数据计数统计<br/>I4U0KP【profiler部件】cpu&nbsp;profiler功能<br/>I4PJE5【新增特性】支持JS&nbsp;app&nbsp;native内存信息调试调优能力<br/>I4Q6AQ【新增特性】Watchdog机制<br/>I4U0JZ【新增特性】供OpenHarmony&nbsp;hisysevent系统事件管理<br/>I4Q6B6【增强特性】支持HiTrace&nbsp;JS接口<br/>I4Q6AY【新增特性】在OpenHarmony上提供检测模式框架和检测模式基本功能 | NA |
| 驱动子系统 | -&nbsp;持续增强HDF框架能力，包括hcs配置解析、电源管理等机制；<br/>-&nbsp;针对HDI管理框架，新增支持共享内存队列、HDI服务按需启动；<br/>-&nbsp;新增用户态PLATFORM接口，支持用户态驱动开发；<br/>-&nbsp;外设模块扩展200+HDI接口定义，涵盖显示、音频、相机、传感器、电源、USB等功能模块，使设备接口数量达到600+，为系统提供更多的硬件访问能力。<br/>主要涉及如下需求：<br/>I4HPR7【增强特性】提供hcs宏式解析接口<br/>I4LZZF【增强特性】支持同步/异步电源管理调用<br/>I4QEKH【新增特性】提供共享内存相关HDI能力<br/>I4QEKI【新增特性】驱动开发工具支持标准系统驱动开发<br/>I4QEKZ【新增特性】支持用户态平台驱动接口<br/>I4QEKL【新增特性】基于HDF驱动框架构建统一的平台驱动对象模型<br/>I4QELC【新增特性】支持UHDF类进程按需启动<br/>I4QEKJ【新增特性】HDI接口适配linux-input驱动<br/>I4QEKM【新增特性】提供power&nbsp;HDI接口能力<br/>I4QEKK【新增特性】基于HDF驱动框架提供硬件TIMER驱动<br/>I4QEKP【新增特性】基于HDF驱动框架提供light驱动能力<br/>I4MBTP【增强特性】传感器驱动模型能力增强<br/>I4MBTQ【增强特性】传感器器件驱动能力增强<br/>I4MBTR【增强特性】Display&nbsp;HDI针对标准系统的参考实现<br/>I4MBTS【新增特性】HDF-Input设备能力丰富<br/>I4QEKP【新增特性】基于HDF驱动框架提供light驱动能力<br/>I4QEKQ【新增特性】Display&nbsp;HDI接口实现服务化<br/>I4QEL2【增强特性】马达驱动模型能力增强<br/>I4XXGZ【新增特性】基于HDF驱动框架提供计步器Sensor驱动能力 | 对于轻量、小型系统：<br/>提供HCS宏式解析接口，编译节省配置所占内存<br/>主要涉及如下需求：<br/>I4TFTB【新增特性】轻量系统新增HCS宏式解析接口 |
| USB服务子系统 | -&nbsp;构建了完整的USB服务管理框架，包括host、device功能模块。<br/>-&nbsp;支持Port切换功能，实现不同功能模式的切换。<br/>-&nbsp;提供了USB&nbsp;JS&nbsp;API接口，支持应用开发。<br/>-&nbsp;定义并实现了USB&nbsp;HDI，提供规范的USB驱动能力访问接口。<br/>主要涉及如下需求：<br/>I4MBRK【新增特性】USB服务JS接口实现<br/>I4QEKV【新增特性】USB服务&nbsp;HDI接口实现<br/>I4QEKN【新增特性】USB&nbsp;Device功能实现<br/>I4QEKO【新增特性】USB&nbsp;Host功能实现<br/>I4QEL6【新增特性】USB&nbsp;Port功能实现 | NA |
| 编译构建子系统 | -&nbsp;新增归一的部件定义和编译。<br/>-&nbsp;新增统一的编译框架，包括统一的gn模板、统一的部件配置、统一的产品配置、统一的编译命令和统一的编译流程。<br/>-&nbsp;新增支持Native&nbsp;SDK编译发布。<br/>-&nbsp;新增编译系统支持Kconfig配置框架。<br/>-&nbsp;扩展增强了hb能力，包括统一使用hb编译入口、编译构建日志按级别显示和hb命令安装、集成及扩展支持。<br/>-&nbsp;制定gn编码规范和最佳实践指导。 | 对于轻量、小型系统，特性变更同标准系统。 |
| 测试子系统 | -&nbsp;新增OpenHarmony自动化测试框架能力，支持单元/UI基础测试脚本编写运行能力。<br/>-&nbsp;新增OpenHarmony-wukong工具，支持整机/单应用级别随机事件注入压测能力。<br/>-&nbsp;新增SmartPerf性能测试工具，支持基础性能数据如FPS、CPU、内存等采集展示能力。<br/>-&nbsp;完善测试调度框架能力，新增自动化用例执行配置、执行设配管理能力。<br/>-&nbsp;新增DCTS兼容性测试套件，支持分布式软总线、分布式数据兼容测试。<br/>-&nbsp;增强ACTS、HATS兼容性测试套件，覆盖3.1&nbsp;Release新增对外公共JS&nbsp;API和HDF&nbsp;API。<br/>主要涉及如下需求：<br/>I4XXCR&nbsp;【测试框架】界面自动化测试<br/>I4XXCV&nbsp;【测试框架】TS开发者测试框架<br/>I4XXCW&nbsp;【测试框架】JS应用开发者测试框架<br/>I4XXD0&nbsp;【测试框架】执行器设备管理<br/>I4XXCX&nbsp;【测试框架】测试流水线测试套执行报表<br/>I4XXCZ&nbsp;【测试框架】用例配置管理<br/>I4XXD0&nbsp;【测试框架】执行器设备管理<br/>I4XGLQ&nbsp;【新增特性】UI随机压测工具<br/>I4XXD7&nbsp;【兼容性测试】DCTS3.1分布式兼容性测试套件 | NA |
| 启动子系统 | -&nbsp;新增支持进程分组及并行启动。<br/>-&nbsp;新增支持按需启动SA服务、UHDF服务或者根据热插拔事件启动服务。<br/>-&nbsp;新增支持为服务创建socket或者为退出的进程代持fd。<br/>-&nbsp;统一init的维护命令为begetctl。<br/>-&nbsp;完善进程退出后的回收策略，支持核心进程退出后重启；非核心进程频繁挂死时隔离。<br/>主要涉及如下需求：<br/>I4UTCF【新增特性】进程分组及并行启动基础框架<br/>I4UGE9&nbsp;添加bootchart功能<br/>I4UP28&nbsp;动态文件selinux标签适配<br/>I4UTCO&nbsp;【增强特性】支持app进程孵化能力增强<br/>I4UTCY&nbsp;【增强特性】appspawn支持孵化的应用进程回收<br/>I4RXJ2&nbsp;【新增规格】统一init维护命令<br/>I4RXJ9&nbsp;【新增特性】支持服务类进程按需启动<br/>I4TNBV&nbsp;【新增规格】进程启动配置能力增强<br/>I4PD3K&nbsp;进程退出后的回收处理策略配置能力增强 | NA |
| 用户IAM子系统 | -&nbsp;新增实现多用户身份管理和用户身份认证功能特性；<br/>-&nbsp;新增统一用户身体认证框架，支持管理各种认证方式<br/>-&nbsp;新增支持口令认证功能<br/>-&nbsp;新增支持人脸认证功能<br/>主要涉及如下需求：<br/>I4RG55【新增规格】【user_idm】支持用户本地认证凭据信息查询<br/>I4RG5R【新增规格】【user_idm】支持删除用户时，删除该用户的身份认证凭据<br/>I4RG8W&nbsp;【新增规格】【pin_auth】支持用户本地口令录入<br/>I4RG91【新增规格】【pin_auth】支持用户本地口令认证<br/>I4RGWU【新增规格】【pin_auth】支持用户本地口令删除<br/>I4TSK7&nbsp;【新增规格】【face_auth】支持用户本地人脸删除<br/>I4TSJE【新增规格】【face_auth】支持用户本地人脸录入<br/>I4TSJY【新增规格】【face_auth】支持用户本地人脸认证 | NA |
| 安全基础能力子系统 | -&nbsp;新增实现设备安全等级管理框架，提供组网内指定设备的安全等级查询。<br/>-&nbsp;新增数据跨设备流转时的管控策略，满足终端内部数据处理、流转时的数据安全管控提供基础的底座机制。<br/>-&nbsp;新增提供统一的秘钥管理服务，为系统应用和上层业务提供本地秘钥全生命周期的管理。<br/>-&nbsp;新增支持OpenHarmony使能设备互信认证能力，为系统的设备安全连接提供保障。<br/>主要涉及如下需求：<br/>I4RTYU【新增特性】【服务】支持被组网内其它设备查询自己的设备安全等级信息<br/>I4RTYW【新增特性】【服务】支持获取自己或者组网内其它设备的设备安全等级信息<br/>I4TJFZ【增强特性】DeviceAuth部件支持设备间互信关系认证的多用户隔离，使用指定系统用户下管理的互信关系进行认证<br/>I4TJG1【增强特性】DeviceAuth部件实现互信群组数据多实例，支持指定用户的数据查询。<br/>I4TJG3【增强特性】DeviceAuth部件支持帐号无关点对点信任关系建立、解除的多用户数据隔离<br/>I4TT8L【新增规格】HUKS提供三段式密钥管理接口<br/>I4TYEM【新增规格】HUKS支持安全等级凭据的导入签发及验证<br/>I4TYFI【新增规格】HUKS在删除子用户情况下，需要删除相关的密钥数据<br/>I4TYFR【新增规格】HUKS在删除应用的情况下，HUKS需要删除相关的密钥数据<br/>I4TYFA【新增规格】HUKS支持密钥应用基于APP&nbsp;UID的访问隔离<br/>I4TYF1【新增规格】HUKS支持key&nbsp;attestation和id&nbsp;attestation<br/>I4SAI0【新增特性】提供DataTransitMgrLib部件，支持数据跨设备流转时的管控策略 | NA |
| 应用子系统 | 系统应用提供了OpenHarmony标准系统上的部分应用，如桌面、SystemUI、设置等，为开发者提供了构建标准系统应用的具体实例，这些应用支持在所有标准系统设备上使用。<br/>-&nbsp;桌面：提供了基本的已安装应用的展示功能和人机交互界面，是所有应用的入口。<br/>-&nbsp;SystemUI：包含导航栏和系统状态栏两部分，导航栏提供基本页面导航功能、状态栏提供系统状态显示，如时间、充电状态等。<br/>-&nbsp;设置：提供了关于设备，应用管理，亮度设置等功能。<br/>-&nbsp;联系人：提供了拨号盘、通话记录查看/删除、联系人列表、详情查看和新建联系人等功能。<br/>-&nbsp;短信：提供了信息查看、发送短信、接收短信、短信送达报告、删除短信等功能。<br/>-&nbsp;通话：提供了语音通话接听和挂断，移动数据开关等功能。<br/>-&nbsp;相机：提供了预览、拍照、缩略图显示、跳转大图浏览等功能。<br/>-&nbsp;图库：提供了图片、视频和相册的管理、浏览、显示、编辑操作等功能。<br/>-&nbsp;输入法：提供硬键盘输入、编辑框选择文本变化、光标位置变化反馈等功能。<br/>&nbsp;&nbsp;说明：OpenHarmony&nbsp;3.1&nbsp;Release版本，仅图库系统应用代码可配套发布的IDE、SDK编译成功。 | NA |


API变更请参考：


_[API差异报告](api-diff/v3.1-Release/Readme-CN.md)_


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

### Samples & Codelabs

#### 新增Samples

**表4** 新增Samples

| 子系统 | 名称 | 简介 | 开发语言 |
| -------- | -------- | -------- | -------- |
| 电话服务 | [短信服务](https://gitee.com/openharmony/app_samples/tree/master/Telephony/Message) | 本示例展示了电话服务中发送短信的功能。 | ArkTS |
| 电话服务 | [网络搜索](https://gitee.com/openharmony/app_samples/tree/master/Telephony/RadioTech) | 本示例通过ArkTS来展示电话服务中网络搜索功能，包含无线接入技术、网络状态、选网模式、ISO国家码、信号强度信息列表及Radio是否打开。 | ArkTS |
| 设备管理 | [系统电源管理](https://gitee.com/openharmony/app_samples/tree/master/common/PowerManager) | 本示例展示了关机、重启以及检测亮灭屏状态的功能。 | ArkTS |
| 设备管理 | [传感器](https://gitee.com/openharmony/app_samples/tree/master/device/Sensor) | 本示例采用了传感器接口中的方向传感器，实现了指南针的效果。 | ArkTS |
| 设备管理 | [设备管理](https://gitee.com/openharmony/app_samples/tree/master/device/DeviceManager) | 本示例展示了在ArkTS中DeviceManager接口的使用，包括获取授信设备列表，设备扫描，设备认证，设备状态订阅。 | ArkTS |
| 帐号管理 | [应用帐号管理](https://gitee.com/openharmony/app_samples/tree/master/Account/AppAccountManager) | 本示例选择应用进行注册/登录，并设置帐号相关信息，简要说明应用帐号管理相关功能。 | ArkTS |
| ArkUI | [web](https://gitee.com/openharmony/app_samples/tree/master/ETSUI/Web) | 本示例主要展示了web的功能页面。 | ArkTS |
| ArkUI | [拖拽](https://gitee.com/openharmony/app_samples/tree/master/ETSUI/Drag) | 本示例主要展示了拖拽操作的功能。 | ArkTS |
| ArkUI | [动画](https://gitee.com/openharmony/app_samples/tree/master/ETSUI/ArkUIAnimation) | 本示例通过点击按钮触发动画，向用户展示属性动画与显示动画的效果。 | ArkTS |
| 数据管理 | [分布式数据库-结果集和谓词查询](https://gitee.com/openharmony/app_samples/tree/master/data/DDMQuery) | 本示例展示了分布式数据管理中，如何通过构建query对象，&nbsp;查询kvstore中的数据，获取结果集。 | ArkTS |
| 数据管理 | [关系型数据库](https://gitee.com/openharmony/app_samples/tree/master/data/DistributedRdb) | 本示例展示了在ArkTS中关系型数据库的使用，包括增、删、改、查等操作。 | ArkTS |
| 事件 | [后台代理提醒](https://gitee.com/openharmony/app_samples/tree/master/Notification/AlarmClock) | 本示例通过模拟闹钟来展示后台代理提醒的使用方法。 | ArkTS |
| 事件 | [事件通知](https://gitee.com/openharmony/app_samples/tree/master/Notification/Emitter) | 本示例主要展示进程内事件通知，用户通过选择对应商品并提交订单后在订单列表显示所选商品。 | ArkTS |
| 通信与连接 | [RPC通信](https://gitee.com/openharmony/app_samples/tree/master/Communication/RPC) | 本示例展示了同一设备中前后台的数据交互，用户前台选择相应的商品与数目，后台计算出结果，回传给前台展示。 | ArkTS |
| 通信与连接 | [WLAN](https://gitee.com/openharmony/app_samples/tree/master/Communication/Wlan) | 本示例展示了在ArkTS中WLAN的基本使用，包括禁用和启用WLAN、WLAN扫描和获取扫描结果、WLAN状态监听、WiFi连接状态监听、获取IP信息、获取国家码、判断设备是否支持WLAN相关特性。 | ArkTS |
| 媒体服务 | [录音机Demo](https://gitee.com/openharmony/app_samples/tree/master/media/Recorder) | 本示例展示媒体服务中音频录制和播放功能的使用。 | ArkTS |
| 媒体服务 | [多媒体Demo](https://gitee.com/openharmony/app_samples/tree/master/media/MultiMedia) | 本示例展示如何在ArkTS中调用相机拍照，以及如何使用媒体库接口进行媒体文件的增、删、改、查操作。 | ArkTS |

请访问[Samples](https://gitee.com/openharmony/app_samples)仓了解更多信息。

#### 新增Codelabs

**表5** 新增Codelabs

| 项目名称                                                     | 简介                                                         | 开发语言 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| [分布式鉴权](https://gitee.com/openharmony/codelabs/tree/master/Distributed/GameAuthOpenH) | 使用JS开发一个分布式游戏鉴权应用，介绍分布式拉起，设备管理器对象、显示设备属性接口能力的使用。 | JS       |
| [分布式游戏手柄](https://gitee.com/openharmony/codelabs/tree/master/Distributed/HandleGameApplication) | 使用ArkTS开发一个手柄游戏，利用分布式能力，一个开发板作为手柄，一个开发板作为游戏端。 | ArkTS      |
| [分布式亲子教育](https://gitee.com/openharmony/codelabs/tree/master/Distributed/OpenHarmonyPictureGame) | 使用RPC实现跨设备通讯，以及CommonEvent实现ServiceAbility与FA之间通讯，完成分布式拼图游戏。 | ArkTS      |
| [分布式遥控器](https://gitee.com/openharmony/codelabs/tree/master/Distributed/RemoteControllerETS) | 使用ArkTS开发一个分布式遥控器，利用分布式能力，一个开发板作为TV端，一个开发板作为遥控器端。 | ArkTS      |
| [音频录制应用](https://gitee.com/openharmony/codelabs/tree/master/Media/Audio_OH_ETS) | 使用媒体组件AudioRecorder收录当前音频、使用AudioPlayer播放录音的方法。 | ArkTS     |
| [备忘录](https://gitee.com/openharmony/codelabs/tree/master/Data/NotePad_OH_ETS) | 使用ArkTS开发一个简易备忘录，支持新建、删除和收藏笔记功能，轻量级数据库持久化存储数据。 | ArkTS      |
| [分布式邮件编辑](https://gitee.com/openharmony/codelabs/tree/master/Distributed/OHMailETS) | 使用ArkTS开发分布式邮件，利用分布式的能力，在相同局域网及帐号下，拉起另一个设备，实现邮件在不同设备下的编辑流转。 | ArkTS     |


## 修复缺陷列表

**表6** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [I4MGJM](https://gitee.com/openharmony/drivers_peripheral/issues/I4MGJM) | 【hdf/camera】RK3568单板跑camera&nbsp;HDI用例失败 |
| I4OECR | XTS运行报ark异常栈（低概率问题） |
| I4OBTW | 全量执行XTS用例，安装应用后出现批量aa&nbsp;start&nbsp;失败，影响社区流水线稳定性测试 |
| I4OLHF | 【ArkUI子系统】&nbsp;由进程com.amsst.amsMissionSnapshotTest导致测试进程异常 |
| I4OLUK | 【ArkUI子系统】&nbsp;由进程com.ohos.systemui导致进程栈异常 |


## 遗留缺陷列表

**表7** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| [I4NRS5](https://gitee.com/openharmony/kernel_linux_5.10/issues/I4NRS5) | 【内核子系统】存在cve漏洞 | Linux内核还未发布补丁，暂时挂起，待社区发布补丁后升级同步。 | 待社区发布补丁 |
| [I4UUFR](https://gitee.com/openharmony/third_party_e2fsprogs/issues/I4UUFR) | 本地编译构建Hi3516开发板版本镜像 | 编译Hi3516版本时偶现编译失败，重新下载代码可恢复。 | 2022-04-30 |
| [I4RJU8](https://e.gitee.com/open_harmony/issues/list?issue=I4RJU8) | Hi3516标准系统camera&nbsp;预览黑屏 | 影响标准系统Hi3516&nbsp;camera预览功能。 | 2022-05-30 |
| [I4Z3G9](https://e.gitee.com/open_harmony/issues/list?issue=I4Z3G9) | 【图形子系统】【RK3568】打开沉浸式主窗口和在主窗口上打开辅助窗口出现闪屏 | 打开沉浸式主窗口和在主窗口上打开辅助窗口出现闪屏，影响体验。 | 2022-04-15 |
| [I50EBB](https://gitee.com/openharmony/docs/issues/I50EBB?from=project-issue) | 【Hi3516烧录】标准系统Hi3516镜像无法通过IDE烧录 | 仅在IDE版本上Ubuntu环境烧录不成功。<br/>**规避方案：** 通过remote方式在Windows上烧录。<br/>**后续方案：**<br/>改成Windows+Ubuntu混合模式，在Windows界面操作远程的Ubuntu开发、编译、调试；烧录自动回传到Windows上进行。 | 2022-04-30 |
