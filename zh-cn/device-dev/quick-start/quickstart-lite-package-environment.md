# 使用安装包方式搭建编译环境<a name="ZH-CN_TOPIC_0000001171615528"></a>

-   [安装必要的库和工具](#section108201740181219)
-   [安装hb](#section15794154618411)
-   [安装LLVM\(仅OpenHarmony\_v1.x分支/标签需要\)](#section711117144296)

使用安装包方式搭建Ubuntu编译环境步骤如下：

1.  安装必要的库和工具：编译所需的必要工具和库（如打包、镜像制作等）
2.  安装hb：OpenHarmony编译构建命令行工具
3.  安装LLVM\(仅OpenHarmony\_v1.x分支/标签需要\)

想要详细了解OpenHarmony编译构建模块功能的开发者可参考[编译构建使用指南](../subsystems/subsys-build-mini-lite.md)。

## 安装必要的库和工具<a name="section108201740181219"></a>

使用如下apt-get命令安装编译所需的必要的库和工具：

```
sudo apt-get install build-essential gcc g++ make zlib* libffi-dev e2fsprogs pkg-config flex bison perl bc openssl libssl-dev libelf-dev libc6-dev-amd64 binutils binutils-dev libdwarf-dev u-boot-tools mtd-utils gcc-arm-linux-gnueabi cpio device-tree-compiler
```

## 安装hb<a name="section15794154618411"></a>

1.  运行如下命令安装hb

    ```
    python3 -m pip install --user ohos-build
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

3.  执行"hb -h"，界面打印以下信息即表示安装成功：

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


