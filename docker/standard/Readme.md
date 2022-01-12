## 独立Docker环境

本文为标准系统类设备Docker使用指导，[点此查看](https://gitee.com/openharmony/docs/blob/master/docker/README.md)小型和轻量系统类设备使用指导。

OpenHarmony的Docker镜像托管在HuaweiCloud SWR上。开发者可以通过该镜像在很大程度上简化编译前的环境配置。开发者在配置好开发环境后，通过以下步骤来使用Docker环境。本Docker支持Ubuntu/Windows平台，下文将以Ubuntu系统为例进行使用介绍。

### 搭建Docker环境-标准系统类设备（参考内存≥128MB）

##### 方式一：从HuaweiCloud SWR上直接获取Docker镜像进行构建：

1. 获取Docker镜像。
```
docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.7
```
2. 进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境。
```
docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.7
```

##### 方式二：通过Dockerfile 构建本地Docker镜像进行构建

1. 获取Dockerfile脚本文件，用来构建本地Docker镜像。
```
git clone https://gitee.com/openharmony/docs.git
```
2. 进入Dockerfile代码目录路径执行Docker镜像构建命令。
```
cd docs/docker/standard
./build.sh
```
3. 进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境。
```
docker run -it -v $(pwd):/home/openharmony openharmony-docker-standard:0.0.7
```

### 编译源码-标准系统类设备（参考内存≥128MB）
通过如下编译脚本启动标准系统类设备（参考内存≥128MB）的编译。

```
./build.sh --product-name {product_name} --ccache
```
{product_name}为当前版本支持的平台。比如：Hi3516DV300、rk3568等。
编译所生成的文件都归档在out/{device_name}/目录下，结果镜像输出在 out/{device_name}/packages/phone/images/ 目录下。



**说明**

 退出Docker执行exit命令即可。