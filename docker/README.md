# OpenHarmony Docker镜像

### Docker镜像简介

OpenHarmony的Docker镜像托管在**HuaweiCloud SWR**上，开发者可以通过该镜像在很大程度上简化编译前的环境配置。 目前容器化构建选项支持情况如下：

 | 硬件平台   | Docker镜像仓库                | 标签                       | 说明                                       |
 | :----- | :------------------------ | :----------------------- | :--------------------------------------- |
 | 3861/3516/3518    | `swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker` | `0.0.2`                  | 已经预安装Openharmony `0.0.2` 版本的编译环境。       |


### 使用方式及步骤
 开发者在配置好开发环境后，可以通过以下步骤来使用我们提供的Docker环境，支持Ubuntu/Windows平台，下文将以Ubuntu系统为例进行使用介绍。

#### 方式一：从**HuaweiCloud SWR**上直接获取Docker镜像进行构建：

1. 获取Docker镜像
     ```
     docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.2
     ```
2. 进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境
     ```
     docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.2
     ```
3. 通过如下编译脚本启动wifiiot、ipcamera_hi3516dv300、ipcamera_hi3518ev300不同平台的编译
     ```
     python build.py wifiiot/ipcamera_hi3516dv300/ipcamera_hi3518ev300
     ```
 
 #### 方式二：通过Dockerfile 构建本地Docker镜像进行构建
1. 获取Dockerfile脚本文件，用来构建本地Docker镜像
     ```
     git clone https://gitee.com/openharmony/docs.git
     ```
2. 进入Dockerfile代码目录路径执行Docker镜像构建命令
     ```
     cd docs/docker
     ./build.sh
     ```
4. 进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境
     ```
     docker run -it -v $(pwd):/home/openharmony openharmony-docker:0.0.2
     ```
5. 通过如下编译脚本启动wifiiot、ipcamera_hi3516dv300、ipcamera_hi3518ev300不同平台的编译
     ```
     python build.py wifiiot/ipcamera_hi3516dv300/ipcamera_hi3518ev300
     ```
