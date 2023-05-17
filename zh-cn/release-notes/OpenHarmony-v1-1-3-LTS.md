# OpenHarmony v1.1.3 LTS (停止维护)

## 版本概述

更新发布LTS（long-term support）长期支持版本OpenHarmony v1.1.3 LTS，本版本在OpenHarmony v1.1.2 LTS版本的基础上新增了一些特性和修复了部分缺陷。

## 配套关系

**表 1**  版本软件和工具配套关系

| 软件                              | 版本                                  | 备注                                      |
| --------------------------------- | ------------------------------------- | ----------------------------------------- |
| OpenHarmony                       | 1.1.3 LTS                             | NA                                        |
| HUAWEI DevEco Device Tool（可选） | HUAWEI DevEco Device Tool 2.1 Release | OpenHarmony智能设备集成开发环境推荐使用。 |


## 源码获取

通过repo下载

方式一（推荐）：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

方式二：通过repo + https 下载。

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.3-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### 通过镜像站点获取

**表 2**  源码获取路径

| 版本源码                 | 版本信息 | 下载站点                                                     | SHA256校验码                                                 |
| ------------------------ | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码                 | 1.1.3    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.3/code-v1.1.3-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.3/code-v1.1.3-LTS.tar.gz.sha256) |
| Hi3861解决方案（二进制） | 1.1.3    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.3/wifiiot-1.1.3.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.3/wifiiot-1.1.3.tar.gz.sha256) |
| Hi3518解决方案（二进制） | 1.1.3    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3518ev300-1.1.3.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3518ev300-1.1.3.tar.gz.sha256) |
| Hi3516解决方案（二进制） | 1.1.3    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3516dv300-1.1.3.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.3/ipcamera_hi3516dv300-1.1.3.tar.gz.sha256) |
| Release Notes            | 1.1.3    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.3/OpenHarmony-Release-Notes-1.1.3-LTS.zip) | -                                                            |


## 更新说明

本版本完全继承了OpenHarmony v1.1.2 LTS的所有特性，并在OpenHarmony v1.1.2 LTS版本的基础上，新增了轻量设备可以在windows环境下的编译版本的特性（请参考[windows开发环境准备](https://device.harmonyos.com/cn/docs/documentation/guide/ide-install-windows-0000001050164976)）。

**表 3**  特性更新说明

| 子系统   | 新增特性                                                     | 修改特性 | 删除特性 |
| -------- | ------------------------------------------------------------ | -------- | -------- |
| 芯片平台 | 支持了轻量设备在windows环境下编译版本（[pulls/60](https://gitee.com/openharmony/device_hisilicon_hispark_pegasus/pulls/60)） | N/A      | N/A      |


## 已修复缺陷列表

在OpenHarmony v1.1.2 LTS版本的基础上，解决并修复的问题见下表。

**表 4**  已修复问题列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I43MZK](https://gitee.com/openharmony/startup_syspara_lite/issues/I43MZK?from=project-issue) | release1.0.1分支命名中出现空格字符，与外部接口标准不符       |
| [I44ZGK](https://gitee.com/openharmony/device_hisilicon_third_party_ffmpeg/issues/I44ZGK?from=project-issue) | 组件ffmpeg 4.2.2存在未修复的漏洞                             |
| [I41ZMV](https://gitee.com/openharmony/graphic_utils/issues/I41ZMV?from=project-issue) | HI3516刷机之后，在系统bin目录下存在module_ActsUiInterfaceTest1.bin测试文件 |
| [I3ZOIO](https://gitee.com/openharmony/kernel_liteos_a/issues/I3ZOIO?from=project-issue) | los_disk_deinit 资源释放失败                                 |
| [I43WLG](https://gitee.com/openharmony/kernel_liteos_a/issues/I43WLG?from=project-issue) | OsMountRootfs启动失败                                        |
| [I48FKQ](https://gitee.com/openharmony/kernel_liteos_m/issues/I48FKQ?from=project-issue) | osEventFlagsGet传NULL时应该返回0                             |
| [I48FL1](https://gitee.com/openharmony/kernel_liteos_m/issues/I48FL1?from=project-issue) | osThreadNew函数attr为NULL时，创建线程失败                    |
| [I48FLX](https://gitee.com/openharmony/kernel_liteos_a/issues/I48FLX?from=project-issue) | shell命令中使用rm -r指令尝试删除dev下节点时会导致系统出错    |
| [I48FMK](https://gitee.com/openharmony/kernel_liteos_a/issues/I48FMK?from=project-issue) | 小型系统的ActsProcessApiTest/UidGidTest/testGetgroup测试用例失败 |
| [I48FMT](https://gitee.com/openharmony/kernel_liteos_a/issues/I48FMT?from=project-issue) | nanosleep函数实现存在缺陷                                    |


