# OpenHarmony Docker镜像

### Docker镜像简介

本文为小型和轻量系统类设备Docker使用指导，[点此查看](https://gitee.com/openharmony/docs/blob/master/docker/standard/Readme.md)标准系统类设备使用指导。

OpenHarmony的Docker镜像托管在**HuaweiCloud SWR**上，开发者可以通过该镜像在很大程度上简化编译前的环境配置。 目前容器化构建选项支持情况如下：

| Docker镜像仓库                                               | 标签    | 说明                                                         |
| :----------------------------------------------------------- | :------ | :----------------------------------------------------------- |
| `swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker` | `0.0.6` | 已经预安装OpenHarmony版本的编译环境，支持轻量系统类设备（参考内存≥128KB）和小型系统类设备（参考内存≥1MB）的版本构建。 |

### 使用方式及步骤

 开发者在配置好开发环境后，可以通过以下步骤来使用我们提供的Docker环境。详情请参见[Docker编译环境](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/get-code/gettools-acquire.md)。

1. 获取Docker镜像
     ```
     docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.6
     ```
2. 进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境
     ```
     docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.6
     ```
3. 通过如下命令启动不同平台的编译
     ```
     hb set #设置工作目录。
     . #输入源码所在目录，点(.)表示当前目录。
     在显示的页面中通过键盘上下键选择需要编译的平台，通过回车确定选择。
     hb build -f #执行编译。
     ```
