# OpenHarmony v2.2 Beta2 

## 版本概述

当前版本在OpenHarmony 2.0 Canary的基础上，针对轻量系统、小型系统和标准系统都有增加新的特性：

标准系统新增特性功能如下：

-   新增分布式远程拉起能力端到端的构建。
-   新增系统基础应用的拖拽能力和新增若干Sample应用。
-   新增媒体三大服务能力，提供更好的媒体系统功能。

轻量和小型系统新增特性功能如下：

-   新增小型系统linux版本构建能力。
-   新增轻量级内核能力增强，包括文件系统增强、内核调试工具增强支持、内核模块支持可配置、三方芯片适配支持、支持ARM9架构等。
-   轻量级图形能力增强支持，包括支持多语言字体对齐、支持显示控件轮廓、支持点阵字体、供统一多后端框架支持多芯片平台等。
-   DFX能力增强支持，包括HiLog功能增强、HiEvent功能增强，提供轻量级系统信息dump工具、提供重启维侧框架等。
-   AI能力增强支持，包括新增linux内核适配支持、AI引擎支持基于共享内存的数据传输。

## 配套关系

**表 1**  版本软件和工具配套关系

| 软件                              | 版本                        | 备注                                      |
| --------------------------------- | --------------------------- | ----------------------------------------- |
| OpenHarmony                       | 2.2 Beta2                   | NA                                        |
| HUAWEI DevEco Studio（可选）      | DevEco Studio 2.2 Beta1     | OpenHarmony应用开发推荐使用。             |
| HUAWEI DevEco Device Tool（可选） | Deveco DeviceTool 2.2 Beta1 | OpenHarmony智能设备集成开发环境推荐使用。 |


## 源码获取

### 通过repo下载

**方式一（推荐）**

通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v2.2-Beta2 --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v2.2-Beta2 --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 通过镜像站点下载

**表2** 源码获取路径

| 版本源码 | 版本信息 | 下载站点 | SHA256校验码 |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/code-v2.2-beta2_20210730.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/code-v2.2-beta2_20210730.tar.gz.sha256) |
| 标准系统解决方案（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/standard-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/standard-2.2-Beta2.tar.gz.sha256) |
| Hi3861解决方案（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_pegasus-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_pegasus-2.2-Beta2.tar.gz.sha256) |
| Hi3518解决方案（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_aries-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_aries-2.2-Beta2.tar.gz.sha256) |
| Hi3516解决方案-LiteOS（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus-2.2-Beta2.tar.gz.sha256) |
| Hi3516解决方案-Linux（二进制） | 2.2 | [站点](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus_linux-2.2-Beta2.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/2.2-Beta2/hispark_taurus_linux-2.2-Beta2.tar.gz.sha256) |
| Release&nbsp;Notes | 2.2 | [站点](https://gitee.com/openharmony/docs/blob/master/zh-cn/release-notes/OpenHarmony-v2.2-beta2.md) | - |


## 更新说明

本版本在继承了OpenHarmony 2.0 Canary的基础上有如下变更。

### 特性变更

**表 3**  版本新增特性表

| 子系统名称     | 标准系统                                                     | 轻量、小型系统                                               |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 分布式文件     | 提供本地system.file异步文件操作JS API，包括文件读写、目录访问、增删等接口。 | NA                                                           |
| 驱动           | 新增Audio、Camera、USB、马达、ADC驱动模型。 | LiteOS-M支持HDF框架。                                        |
| 电源管理服务   | 新增系统电源状态机、休眠运行锁、休眠唤醒功能。               | - 新增充放电状态查询接口、电量查询接口。<br/>- 提供低功耗模式支持，并提供低功耗模式统一API支持。 |
| 升级服务       | 新增恢复出厂功能。                                           | NA                                                           |
| 媒体           | - 新增音频服务，提供音频基础控制能力。<br/>- 新增相机服务，提供预览、拍照等基础功能力。<br/>- 新增媒体服务，提供音频、视频播放能力。 | NA                                                           |
| JS UI框架      | 支持使用JS与C/C++混合开发JS API。                            | NA                                                           |
| 事件通知       | 支持应用本地发送、取消多行文本通知能力。                     | NA                                                           |
| 分布式软总线   | 新增软总线自组网功能，可信设备接入到局域网中（ETH\WiFi）后可自发现、无感知的接入到软总线。 | NA                                                           |
| 分布式数据管理 | - 新增分布式数据管理能力，支持分布式数据库在本地加密存储<br/>- 支持轻量级偏好数据库 | - 提供数据库内容的删除能力。<br/>- 提供统一的HAL文件系统操作函数实现。<br/>- 提供相关数据存储的原子操作能力。<br/>- 提供二进制Value的写入读取能力。 |
| 系统应用       | 桌面:<br/>- 桌面设置界面UX优化。<br/>- 新增桌面图标拖拽特性。<br/>设置：<br/>- 新增Wlan设置功能。<br/>SystemUI：<br/>- 新增卡信号图标显示功能。<br/>图库：<br/>- 新增图片、视频资源的查看、移动、复制、删除、重命名等功能。 | NA                                                           |
| 全球化子系统   | - 完善时间日期格式化能力。<br/>- 支持时间段的格式化。<br/>- 新增数字格式化能力。 | - 新增构建自定义数据编译能力。<br/>- 新增构建星期、单复数、数字开关国际化能力。<br/>- 新增构建应用资源解析和加载机制。<br/>- 新增构建资源回溯机制。 |
| Sample应用     | - 计算器中新增分布式功能，组网后支持拉起另一台组网设备上的计算器，两台设备可协同计算，计算数据实时同步。<br/>- 新增音频播放器应用，支持本地音频播放，组网后可将音乐播放接续至其他组网设备上。 | NA                                                           |
| 分布式设备管理 | 新增设备管理系统服务，提供分布式设备账号无关的认证组网能力。 | NA                                                           |
| DFX            | NA                                                           | - 提供LiteOS内核系统信息dump工具。<br/>- 提供LiteOS内核死机重启维测框架。<br/>- 新增数字格式化能力。<br/>- HiLog功能增强。<br/>- HiEvent功能增强。 |
| 内核           | NA                                                           | - 支持轻量级Linux版本。<br/>- proc文件系统增强。<br/>- 新增mksh命令解析器。<br/>- 文件系统维测增强。<br/>- LiteOS-A內核模块支持可配置。<br/>- 支持LiteOS-A小系统三方芯片适配。<br/>- LiteOS-M支持三方组件Mbedtls编译。<br/>- LiteOS-M支持三方组件curl编译。<br/>- 支持轻量级shell框架和常用调测命令。<br/>- LiteOS-M支持ARM9架构。<br/>- 支持基于NOR Flash的littlefs文件系统。<br/>- LiteOS-M对外提供统一的文件系统操作接口。<br/>- 新增Namecache模块、Vnode管理、Lookup模块。 |
| 图形图像       | NA                                                           | - 支持A4\A8、LUT8、TSC图片格式作为输入。<br/>- 支持多语言字体对齐。<br/>- UIKit支持显示控件轮廓。<br/>- ScrollView/List支持通过弧形进度条展示滑动进度。<br/>- 支持开关按钮/复选框/单选按钮动效。<br/>- UIKit支持点阵字体产品化解耦。<br/>- UI框架提供统一多后端框架支持多芯片平台。<br/>- UIKit组件支持margin/padding。<br/>- 圆形/胶囊按钮支持缩放和白色蒙层动效。 |
| 编译构建       | NA                                                           | 支持开源软件的通用patch框架。                                |
| 启动恢复       | NA                                                           | 支持恢复出厂设置支持多语言字体对齐。                         |
| 分布式调度     | NA                                                           | 支持轻量设备启动富设备上的Ability。                          |
| AI             | NA                                                           | - AI子系统添加Linux内核适配，编译选项支持。<br/>- AI引擎支持基于共享内存的数据传输。 |


### API变更

API变更请参考：

[JS API 差异报告](api-diff/v2.2-beta2/js-apidiff-v2.2-beta2.md)

[Native API 差异报告](api-diff/v2.2-beta2/native-apidiff-v2.2-beta2.md)

## 修复缺陷列表

**表 4** **解决的缺陷ISSUE列表**

| ISSUE单号                                                    | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I3I31W](https://gitee.com/openharmony/kernel_liteos_a/issues/I3I31W) | ActsNFSTest.bin会引起内核crash                               |
| [I3D49E](https://gitee.com/openharmony/docs/issues/I3D49E)   | uboot的路径不对                                              |
| [I3D71U](https://gitee.com/openharmony-retired/drivers_adapter_khdf_liteos/issues/I3D71U) | 【驱动子系统】反复reset，启动到hmac_main_init SUCCESSULLY后，高概率出现系统挂死 |
| I3DGZW | 【应用程序框架子系统】HI3516开源板进入屏保后 ，点击触摸屏，出现蓝屏问题 |
| [I3DHIL](https://gitee.com/openharmony/community/issues/I3DHIL) | 【系统问题】HI3518开源板剩余空间不足，导致ACTS用例大量失败   |
| I3DU36 | 【应用程序框架子系统】ipcamera bm 查询命令失效               |
| [I3EALU](https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU) | 【媒体子系统】cameraActs 用例执行时，找不到相机配置文件，初始失败 |
| [I3EGUX](https://gitee.com/openharmony/release-management/issues/I3EGUX) | 【可靠性问题】反复reset，出现一次KIdle进程crash，系统挂死无法启动 |
| [I3EH4E](https://gitee.com/openharmony/community/issues/I3EH4E) | 【流水线问题】高概率出现：uname无响应，然后执行reset也无响应 |
| [I3EQJA](https://gitee.com/openharmony/kernel_liteos_a/issues/I3EQJA) | 【文件系统】cat /proc/mounts功能不可用                       |
| [I3EQRC](https://gitee.com/openharmony/kernel_liteos_a/issues/I3EQRC) | 磁盘文件映射延迟测试：并发3个测试进程，系统crash             |
| [I3HVL0](https://gitee.com/openharmony/docs/issues/I3HVL0)   | 3861编译失败，报错[OHOS ERROR] Fatal error: invalid -march= option:rv32imac |
| [I3TS1Y](https://gitee.com/openharmony/kernel_liteos_a/issues/I3TS1Y) | 压力场景下文件相关Vnode资源耗尽                              |
| [I3TXT8](https://gitee.com/openharmony/startup_init_lite/issues/I3TXT8) | 孤儿进程无法回收，压力场景下TCB资源耗尽                      |
| [I3UWXI](https://gitee.com/openharmony/applications_sample_wifi_iot/issues/I3UWXI) | libwap.so 存在已知一般漏洞： CVE-2021-30004，CVSS：5.3；漏洞发布日期：2021-04-02，不符合产品发布要求，需要解决。 |
| [I3SWY2](https://gitee.com/openharmony/kernel_liteos_a/issues/I3SWY2) | 高概率出现KProcess进程挂死，质量不达标                       |
| [I3YJRO](https://gitee.com/openharmony/kernel_liteos_m/issues/I3YJRO) | liteos-a內核模块可配置编译失败                               |
| [I3YNWM](https://gitee.com/openharmony/kernel_liteos_a/issues/I3YNWM) | 文件系统维测增强功能在该版本有问题                           |
| [I3VEOG](https://gitee.com/openharmony/kernel_liteos_a/issues/I3VEOG) | bin目录下没有mksh和toybox，导致已转测的toybox命令集无法测试  |


