# OpenHarmony Docker镜像

### Docker镜像简介

OpenHarmony的Docker镜像托管在**HuaweiCloud SWR**上，开发者可以通过该镜像在很大程度上简化编译前的环境配置。 目前容器化构建选项支持情况如下：

| 硬件平台   | Docker镜像仓库                | 标签                       | 说明                                       |
| :----- | :------------------------ | :----------------------- | :--------------------------------------- |
| ipcamera_hispark_taurus@hisilicon<br>ipcamera_hispark_aries@hisilicon<br>wifiiot_hispark_pegasus@hisilicon   | `swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker` | `0.0.3`                  | 已经预安装Openharmony `0.0.3` 版本的编译环境。       |


### 使用方式及步骤
 开发者在配置好开发环境后，可以通过以下步骤来使用我们提供的Docker环境，支持Ubuntu/Windows平台，下文将以Ubuntu系统为例进行使用介绍。

#### 方式一：从**HuaweiCloud SWR**上直接获取Docker镜像进行构建：

1. 获取Docker镜像
     ```
     docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3
     ```
2. 进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境
     ```
     docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3
     ```
3. 通过如下命令启动不同平台的编译
     ```
     python3 -m pip install --user build/lite  #安装工具hb
     hb set #设置工作目录，输入点(.)表示当前目录
     在显示的页面中通过键盘上下键选择需要编译的平台，通过回车确定选择
     hb build -f #执行编译
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
     docker run -it -v $(pwd):/home/openharmony openharmony-docker:0.0.3
     ```
5. 通过如下命令启动不同平台的编译
     ```
     python3 -m pip install --user build/lite  #安装工具hb
     hb set #设置工作目录，输入点(.)表示当前目录
     在显示的页面中通过键盘上下键选择需要编译的平台，通过回车确定选择
     hb build -f #执行编译
     ```
