# Ubuntu编译环境准备<a name="ZH-CN_TOPIC_0000001161257591"></a>

-   [方式一：Docker方式准备Ubuntu编译环境](#section1643363843714)
    -   [获取标准系统源码](#section58448331029)
    -   [Docker环境安装使用](#section22916211916)

-   [方式二：安装包方式准备Ubuntu编译环境](#section25961010189)
    -   [安装依赖工具](#section109262032104819)
    -   [获取标准系统源码](#section6325556113718)
    -   [获取prebuilts](#section16453104219209)


OpenHarmony为开发者提供了Docker和安装包两种方式来搭建Ubuntu编译环境。接下来将分别针对这两种方式进行介绍。

## 方式一：Docker方式准备Ubuntu编译环境<a name="section1643363843714"></a>

OpenHarmony标准系统为开发者提供的Docker环境已经将对应的编译工具链进行了封装，开发者可省略对应工具的安装。具体Docker使用分为如下几步：

1.  获取标准系统源码。
2.  Docker环境安装使用。

### 获取标准系统源码<a name="section58448331029"></a>

获取[标准系统源码](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary.tar.gz)。此处获取的源码为静态打包代码，如想获取码云社区最新源码，请采用[repo方式获取](../get-code/源码获取.md)。

### Docker环境安装使用<a name="section22916211916"></a>

具体Docker环境的安装和使用请参考[Docker环境安装使用指导](../get-code/获取工具.md)。

## 方式二：安装包方式准备Ubuntu编译环境<a name="section25961010189"></a>

安装包方式具体操作分为如下几步：

1.  安装依赖工具。
2.  获取标准系统源码。
3.  获取prebuilts。

### 安装依赖工具<a name="section109262032104819"></a>

安装命令如下：

```
sudo apt-get install binutils git-core git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 
```

>![](public_sys-resources/icon-caution.gif) **注意：** 
>以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。如果是Ubuntu18.04以上版本需要安装python2.7 和 python-minimal。

### 获取标准系统源码<a name="section6325556113718"></a>

获取[标准系统源码](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary.tar.gz)。此处获取的源码为静态打包代码，如想获取码云社区最新源码，请采用[repo方式获取](../get-code/源码获取.md)。

### 获取prebuilts<a name="section16453104219209"></a>

1.  切换到OpenHarmony工作目录。

    ```
    cd OpenHarmony
    ```

2.  执行脚本。

    ```
    build/prebuilts_download.sh
    ```

    下载的prebuilts二进制默认存放在与OpenHarmony同目录下的OpenHarmony\_2.0\_canary\_prebuilts下。


