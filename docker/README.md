# OpenHarmony Docker镜像

### Docker镜像简介

本文为OpenHarmony的Docker编译环境使用指导。

OpenHarmony的Docker镜像托管在**HuaweiCloud SWR**上，开发者可以通过该镜像在很大程度上简化编译前的环境配置。 目前容器化构建选项支持情况如下：

| Docker镜像仓库                                               | 标签    | 说明                                  |
| :----------------------------------------------------------- | :------ | :------------------------------------ |
| `swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker` | `1.0.0` | 已经预安装OpenHarmony版本的编译环境。 |

### 使用方式及步骤

 开发者在下载好源码后，可以通过以下步骤来使用我们提供的Docker环境。详情请参见[Docker编译环境](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/get-code/gettools-acquire.md)。

1. 获取Docker镜像
     ```
     docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:1.0.0
     ```
2. 进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境
     ```
     docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:1.0.0
     ```
3. 通过如下命令启动不同平台的编译
     ```
     hb set #在显示的页面中通过键盘上下键选择需要编译的平台，通过回车确定选择。
     hb build -f #执行编译。
     ```

