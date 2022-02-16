# 使用Docker方式搭建编译环境<a name="ZH-CN_TOPIC_0000001171455558"></a>

-   [安装Docker](#section7337134183512)
-   [获取Docker环境](#section15666113905015)

使用安装包方式搭建Ubuntu编译环境步骤如下：

1.  安装Docker
2.  获取Docker环境：

想要详细了解OpenHarmony编译构建模块功能的开发者可参考[编译构建使用指南](../subsystems/subsys-build-mini-lite.md)。

## 安装Docker<a name="section7337134183512"></a>

-   请参考[官方指导](https://docs.docker.com/engine/install/)。

## 获取Docker环境<a name="section15666113905015"></a>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>不同的源码版本要匹配使用对应版本的Docker环境，本文以Master主干代码为例进行说明。

OpenHarmony的Docker镜像托管在[HuaweiCloud SWR](https://console.huaweicloud.com/swr/?region=cn-south-1#/app/warehouse/warehouseMangeDetail/goldensir/openharmony-docker/openharmony-docker?type=ownImage)上。开发者可以通过该镜像在很大程度上简化编译前的环境配置。下文将介绍具体使用步骤。

1.  获取Docker镜像。

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.7
    ```

2.  进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境。

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.7
    ```
