# 源码编译<a name="ZH-CN_TOPIC_0000001188207862"></a>

-   [使用Docker方式获取编译工具链](#section181431248132513)
    -   [执行prebuilts](#section111934551605)
    -   [安装Docker](#section1466184743915)
    -   [获取Docker环境](#section615912103552)

-   [使用安装包方式获取编译工具链](#section65647482593)
    -   [安装依赖工具](#section83441888010)
    -   [执行prebuilts](#section6389714142011)

-   [编译](#section92391739152318)

安装编译工具链后，即可对源码进行编译。在Linux环境下获取编译工具链有以下两种方式，二者选其一即可：

1.  Docker方式

    OpenHarmony标准系统为开发者提供的Docker环境已经将对应的编译工具链进行了封装，开发者可省略对应工具的安装。

2.  安装包方式

    使用安装包方式获取编译工具链时，开发者需自行安装相应的依赖工具。


## 使用Docker方式获取编译工具链<a name="section181431248132513"></a>

### 执行prebuilts<a name="section111934551605"></a>

在源码根目录下执行脚本，安装编译器及二进制工具。

```
bash build/prebuilts_download.sh
```

### 安装Docker<a name="section1466184743915"></a>

请参考[官方指导](https://docs.docker.com/engine/install/)。

### 获取Docker环境<a name="section615912103552"></a>

1.  获取Docker镜像。

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:1.0.0
    ```

2.  进入源码根目录执行如下命令，从而进入Docker构建环境。

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:1.0.0
    ```


## 使用安装包方式获取编译工具链<a name="section65647482593"></a>

### 安装依赖工具<a name="section83441888010"></a>

请在终端中输入如下命令安装编译相关的依赖工具：

```
sudo apt-get update && sudo apt-get install binutils git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby
```

>![](../public_sys-resources/icon-note.gif) **说明：** 
>以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。其中Python要求安装Python 3.7及以上版本，此处以Python 3.8为例。

### 执行prebuilts<a name="section6389714142011"></a>

在源码根目录下执行脚本，安装编译器及二进制工具。

```
bash build/prebuilts_download.sh
```

## 编译<a name="section92391739152318"></a>

1.  进入源码根目录，执行如下命令进行版本编译。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >使用Docker方式获取编译工具链的，请直接通过[获取Docker环境](#section615912103552)最后一步进入的Docker构建环境执行如下命令。

    ```
    ./build.sh --product-name rk3568 --ccache
    ```

2.  检查编译结果。编译完成后，log中显示如下：

    ```
    post_process
    =====build rk3568 successful.
    ```

    编译所生成的文件都归档在out/\{device\_name\}/目录下，结果镜像输出在out/\{device\_name\}/packages/phone/images/ 目录下。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >其他模块化编译操作，可参见[编译构建指导](../subsystems/subsys-build-standard-large.md)。

3.  编译源码完成，请进行镜像烧录，具体请参见[镜像烧录](quickstart-standard-running-hi3516-burn.md)。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>若使用Docker环境进行编译，执行exit命令即可退出Docker。

