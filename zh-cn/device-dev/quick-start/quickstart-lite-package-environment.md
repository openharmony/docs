# 使用安装包方式搭建编译环境<a name="ZH-CN_TOPIC_0000001171615528"></a>


使用安装包方式搭建Ubuntu编译环境步骤如下：

1.  安装必要的库和工具：编译所需的必要工具和库（如打包、镜像制作等）。
2.  执行prebuilts。
3.  安装hb：OpenHarmony编译构建命令行工具。
4.  安装LLVM\(仅OpenHarmony\_v1.x分支/标签需要\)。

想要详细了解OpenHarmony编译构建模块功能的开发者可参考[编译构建使用指南](../subsystems/subsys-build-mini-lite.md)。

## 安装必要的库和工具<a name="section108201740181219"></a>

1. 使用如下apt-get命令安装后续操作所需的库和工具：
     
   ```
   sudo apt-get update && sudo apt-get install binutils binutils-dev git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib gcc-arm-linux-gnueabi libc6-dev-i386 libc6-dev-amd64 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby genext2fs device-tree-compiler make libffi-dev e2fsprogs pkg-config perl openssl libssl-dev libelf-dev libdwarf-dev u-boot-tools mtd-utils cpio doxygen liblz4-tool openjdk-8-jre gcc g++ texinfo dosfstools mtools default-jre default-jdk libncurses5 apt-utils wget scons python3.8-distutils tar rsync git-core libxml2-dev lib32z-dev grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5-dev libncursesw5 libstdc++6 gcc-arm-none-eabi vim ssh locales
   ```

   > ![](../public_sys-resources/icon-note.gif) **说明：**
   > 以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。其中：
   > 
   > - Python要求安装Python 3.8及以上版本，此处以Python 3.8为例。
   > 
   > - java要求java8及以上版本，此处以java8为例。

2. 将python 3.8设置为默认python版本。
   查看python 3.8的位置：

     
   ```
   which python3.8
   ```

     将python和python3切换为python3.8：
     
   ```
   sudo update-alternatives --install /usr/bin/python python {python3.8 路径} 1    #{python3.8 路径}为上一步查看的python3.8的位置
   sudo update-alternatives --install /usr/bin/python3 python3 {python3.8 路径} 1   #{python3.8 路径}为上一步查看的python3.8的位置
   ```

## 执行prebuilts

在源码根目录下执行prebuilts脚本，安装编译器及二进制工具。
  
```
bash build/prebuilts_download.sh
```

## 安装hb<a name="section15794154618411"></a>

1.  运行如下命令安装hb并更新至最新版本

    ```
    pip3 install --user build/lite
    ```

2.  设置环境变量

    ```
    vim ~/.bashrc
    ```

    将以下命令拷贝到.bashrc文件的最后一行，保存并退出。

    ```
    export PATH=~/.local/bin:$PATH
    ```

    执行如下命令更新环境变量。

    ```
    source ~/.bashrc
    ```

3.  在源码目录执行"hb -h"，界面打印以下信息即表示安装成功：

    ```
    usage: hb
    
    OHOS build system
    
    positional arguments:
      {build,set,env,clean}
        build               Build source code
        set                 OHOS build settings
        env                 Show OHOS build env
        clean               Clean output
    
    optional arguments:
      -h, --help            show this help message and exit
    ```


>![](../public_sys-resources/icon-notice.gif) **须知：** 
>若安装hb的过程中遇到问题，请参见下文[常见问题](quickstart-lite-env-setup-faqs.md)进行解决。

## 安装LLVM\(仅OpenHarmony\_v1.x分支/标签需要\)<a name="section711117144296"></a>

>![](../public_sys-resources/icon-notice.gif) **须知：** 
>如果下载的源码为OpenHarmony\_v1.x分支/标签, 请按下面的步骤安装9.0.0版本的llvm。
>如果下载的源码为Master及非OpenHarmony\_v1.x分支/标签，可直接跳过本小节，hb会自动下载最新的llvm。

1.  打开Linux编译服务器终端。
2.  [下载LLVM工具](https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar)。
3.  解压LLVM安装包至\~/llvm路径下。

    ```
    tar -zxvf llvm.tar -C ~/
    ```

4.  设置环境变量。

    ```
    vim ~/.bashrc
    ```

    将以下命令拷贝到.bashrc文件的最后一行，保存并退出。

    ```
    export PATH=~/llvm/bin:$PATH
    ```

5.  生效环境变量。

    ```
    source ~/.bashrc
    ```


