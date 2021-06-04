# Ubuntu编译环境准备<a name="ZH-CN_TOPIC_0000001161257591"></a>

-   [Docker方式准备Ubuntu编译环境](#section1643363843714)
    -   [获取系统源码](#section58448331029)
    -   [Docker环境安装使用](#section22916211916)

-   [安装包方式准备Ubuntu编译环境](#section25961010189)
    -   [安装依赖工具](#section109262032104819)
    -   [获取标准系统源码](#section6325556113718)
    -   [获取prebuilts](#section16453104219209)
    -   [配置NodeJS环境和获取Node\_modules依赖包](#section133741330192119)
    -   [安装hc-gen工具](#section149281248182116)


OpenHarmony为开发者提供了Docker和安装包两种方式来搭建Ubuntu编译环境。接下来将分别针对这两种方式进行介绍。

## Docker方式准备Ubuntu编译环境<a name="section1643363843714"></a>

OpenHarmony标准系统为开发者提供的Docker环境已经将对应的编译工具链进行了封装，开发者可省略对应工具的安装。具体Docker使用分为如下几步：

1.  获取系统源码。
2.  Docker环境安装使用。

### 获取系统源码<a name="section58448331029"></a>

具体获取方式请参考[获取标准系统源码](../get-code/源码获取.md)。

### Docker环境安装使用<a name="section22916211916"></a>

具体Docker环境的安装和使用请参考[Docker环境安装使用指导](../get-code/获取工具.md)。

## 安装包方式准备Ubuntu编译环境<a name="section25961010189"></a>

安装包方式具体操作分为如下几步：

1.  安装依赖工具。
2.  获取系统源码。
3.  获取prebuilts。
4.  配置NodeJS环境和获取Node\_modules依赖包。
5.  安装hc-gen工具。

### 安装依赖工具<a name="section109262032104819"></a>

安装命令如下：

```
sudo apt-get install binutils git-core git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4
```

>![](public_sys-resources/icon-note.gif) **说明：** 
>以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。

### 获取标准系统源码<a name="section6325556113718"></a>

具体获取方式请参考[获取标准系统源码](../get-code/源码获取.md)。

### 获取prebuilts<a name="section16453104219209"></a>

1.  切换到OpenHarmony工作目录。

    ```
    cd OpenHarmony
    ```

2.  下载脚本。

    ```
    curl https://gitee.com/landwind/script-tools/raw/master/Shell/OpenHarmony/OpenHarmony_2.0_canary_prebuilts_download.sh >./prebuilts_download.sh
    ```

3.  下载并解压prebuilts压缩包到指定位置。

    ```
    bash ./prebuilts_download.sh
    ```

    二进制默认存放在与OpenHarmony同目录下的OpenHarmony\_2.0\_canary\_prebuilts下，如需修改默认位置，请编辑prebuilts\_download.sh修改bin\_dir值。

4.  切换到之前的目录。

    ```
    cd -
    ```


### 配置NodeJS环境和获取Node\_modules依赖包<a name="section133741330192119"></a>

为了编译JS Framework，开发者需要在Linux服务器下载配置NodeJS（注意：步骤中OpenHarmony目录指代当前工程的根目录，可自定义），具体操作如下：

1.  开发者在Linux服务器下载Nodejs。

    ```
    mkdir -p OpenHarmony/prebuilts/build-tools/common/nodejs                                #创建nodejs目录
    cd OpenHarmony/prebuilts/build-tools/common/nodejs                                      #进入nodejs目录
    wget --no-check-certificate https://nodejs.org/download/release/v12.18.4/node-v12.18.4-linux-x64.tar.gz #下载nodejs
    tar -zxvf node-v12.18.4-linux-x64.tar.gz                                                #解压nodejs压缩包
    cd -                                                                                    #切换到之前的目录
    ```

2.  配置NodeJS环境变量，下载node\_modules包。

    ```
    cd OpenHarmony/third_party/jsframework                  #进入jsframework目录
    export PATH=../../prebuilts/build-tools/common/nodejs/node-v12.18.4-linux-x64/bin:${PATH} #设置NodeJS环境变量
    npm install                                             #下载node_modules包
    cd -                                                    #切换到之前的目录
    ```

3.  把下载的node\_modules包放入OpenHarmony代码的prebuilts/build-tools/common/js-framework目录下。

    ```
    mkdir -p OpenHarmony/prebuilts/build-tools/common/js-framework          #创建js-framework目录
    cp -rp OpenHarmony/third_party/jsframework/node_modules OpenHarmony/prebuilts/build-tools/common/js-framework/
    ```


### 安装hc-gen工具<a name="section149281248182116"></a>

hc-gen用于进行驱动编译，具体安装步骤如下：

1.  打开Linux编译服务器终端。
2.  [下载hc-gen工具](https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar)。
3.  解压hc-gen安装包到Linux服务器\~/hc-gen路径下。

    ```
    tar -xvf hc-gen-0.65-linux.tar -C ~/
    ```

4.  设置环境变量。

    ```
    vim ~/.bashrc
    ```

    将以下命令拷贝到.bashrc文件的最后一行，保存并退出。

    ```
    export PATH=~/hc-gen:$PATH
    ```

5.  生效环境变量。

    ```
    source ~/.bashrc
    ```


