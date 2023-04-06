# OpenHarmony 1.0（2020-09-10）(停止维护)


## 版本概述

首次发布OpenHarmony 1.0。

## 版本源码获取

### 通过镜像站点获取

**表 1**  源码获取路径

| 版本源码                 | 版本信息 | 下载站点                                                     | SHA256校验码                                                 |
| ------------------------ | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码                 | 1.0      | [站点](https://repo.huaweicloud.com/harmonyos/os/1.0/code-1.0.tar.gz) | [SHA256 校验码](https://repo.huaweicloud.com/harmonyos/os/1.0/code-1.0.tar.gz.sha256) |
| Hi3861解决方案（二进制） | 1.0      | [站点](https://repo.huaweicloud.com/harmonyos/os/1.0/wifiiot-1.0.tar.gz) | [SHA256 校验码](https://repo.huaweicloud.com/harmonyos/os/1.0/wifiiot-1.0.tar.gz.sha256) |
| Hi3518解决方案（二进制） | 1.0      | [站点](https://repo.huaweicloud.com/harmonyos/os/1.0/ipcamera_hi3518ev300-1.0.tar.gz) | [SHA256 校验码](https://repo.huaweicloud.com/harmonyos/os/1.0/ipcamera_hi3518ev300-1.0.tar.gz.sha256) |
| Hi3516解决方案（二进制） | 1.0      | [站点](https://repo.huaweicloud.com/harmonyos/os/1.0/ipcamera_hi3516dv300-1.0.tar.gz) | [SHA256 校验码](https://repo.huaweicloud.com/harmonyos/os/1.0/ipcamera_hi3516dv300-1.0.tar.gz.sha256) |
| RELEASE-NOTES            | 1.0      | [站点](https://repo.huaweicloud.com/harmonyos/os/1.0/RELEASE-NOTES.txt) | -                                                            |


### 通过repo命令获取

方式一（推荐）：通过repo下载

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
repo sync -c
```

方式二：通过git clone单个代码仓库

进入[代码仓库主页](https://gitee.com/openharmony)，选择需要克隆的代码仓库，执行命令，如：

```shell
git clone https://gitee.com/openharmony/manifest.git -b master
```
