# 搭建轻量与小型系统环境


## 系统要求

- Ubuntu18及以上版本，内存推荐16GB及以上。

- 系统的用户名不能含有中文字符。

- Ubuntu下只能使用普通用户角色安装DevEco Device Tool。


## 安装必要的库和工具

1. 使用如下apt-get命令安装后续操作所需的库和工具：
     
   ```
   sudo apt-get update && sudo apt-get install binutils binutils-dev git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib gcc-arm-linux-gnueabi libc6-dev-i386 libc6-dev-amd64 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby genext2fs device-tree-compiler make libffi-dev e2fsprogs pkg-config perl openssl libssl-dev libelf-dev libdwarf-dev u-boot-tools mtd-utils cpio doxygen liblz4-tool openjdk-8-jre gcc g++ texinfo dosfstools mtools default-jre default-jdk libncurses5 apt-utils wget scons python3.8-distutils tar rsync git-core libxml2-dev lib32z-dev grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5-dev libncursesw5 libstdc++6 gcc-arm-none-eabi vim ssh locales
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
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


## 安装DevEco Device Tool

DevEco Device Tool Ubuntu版本是OpenHarmony的一站式开发工具，支持源码开发、编译、烧录，调测等，本文主要用其进行烧录和运行。下文介绍如何安装DevEco Device Tool。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> DevEco Device Tool基于Visual Studio Code进行扩展，在Visual Studio Code上以插件方式运行，Visual Studio Code版本为1.62及以上。同时，DevEco Device Tool还依赖Python工具，并要求Python为3.8~3.9版本。
> 
> 在安装过程中，DevEco Device Tool会自动检查Visual Studio Code和Python，如果检测到Visual Studio Code、Python未安装或版本不符合要求，安装程序会自动安装Visual Studio Code和Python。


1. 将Ubuntu Shell环境修改为bash。
   1. 执行如下命令，确认输出结果为bash。如果输出结果不是bash，请根据步骤2，将Ubuntu shell修改为bash。
         
       ```
       ls -l /bin/sh
       ```

       ![zh-cn_image_0000001226764302](figures/zh-cn_image_0000001226764302.png)
   2. 打开终端工具，执行如下命令，输入密码，然后选择**No**，将Ubuntu shell由dash修改为bash。
         
       ```
       sudo dpkg-reconfigure dash
       ```

       ![zh-cn_image_0000001243641075](figures/zh-cn_image_0000001243641075.png)

2. 下载[DevEco Device Tool 3.0 Release](https://device.harmonyos.com/cn/ide#download)Linux版本。

3. 解压DevEco Device Tool软件包并对解压后的文件夹进行赋权。
   1. 进入DevEco Device Tool软件包目录，执行如下命令解压软件包，其中devicetool-linux-tool-3.0.0.400.zip为软件包名称，请根据实际进行修改。
         
       ```
       unzip devicetool-linux-tool-3.0.0.400.zip
       ```
   2. 进入解压后的文件夹，执行如下命令，赋予安装文件可执行权限，其中devicetool-linux-tool-3.0.0.400.sh请根据实际进行修改。
         
       ```
       chmod u+x devicetool-linux-tool-3.0.0.400.sh
       ```

4. 执行如下命令，安装DevEco Device Tool，其中devicetool-linux-tool-3.0.0.300.sh请根据实际进行修改。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 安装过程中，会自动检查Visual Studio Code和Python是否安装，且版本符合要求，其中Visual Studio Code为1.62及以上版本，Python为3.8~3.9版本。如果不满足，则安装过程中会自动安装，提示“Do you want to continue?”，请输入“Y”后继续安装。

     
   ```
   sudo ./devicetool-linux-tool-3.0.0.300.sh -- --install-plugins
   ```

   安装完成后，当界面输出“Deveco Device Tool successfully installed.”时，表示DevEco Device Tool安装成功。

   ![zh-cn_image_0000001243282363](figures/zh-cn_image_0000001243282363.png)

5. 安装完成后，启动Visual Studio Code。

6. 打开Visual Studio Code，进入DevEco Device Tool工具界面。至此，DevEco Device Tool Ubuntu开发环境安装完成。
   ![zh-cn_image_0000001243284745](figures/zh-cn_image_0000001243284745.png)


## 获取源码


### 准备工作

1. 注册码云gitee帐号。

2. 注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。

3. 安装git客户端和git-lfs。（上述工具已在安装必要的库和工具小节安装。如已安装，请忽略）
     更新软件源：
     
   ```
   sudo apt-get update
   ```

     通过以下命令安装：
     
   ```
   sudo apt-get install git git-lfs
   ```

4. 配置用户信息。
     
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

5. 执行如下命令安装码云repo工具。
     
   ```
   curl https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 -o /usr/local/bin/repo  #如果没有权限，可下载至其他目录，并将其配置到环境变量中
   chmod a+x /usr/local/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### 获取源码

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> Master主干为开发分支，开发者可通过Master主干获取最新特性。发布分支代码相对比较稳定，开发者可基于发布分支代码进行商用功能开发。

- **OpenHarmony主干代码获取**
    方式一（推荐）：通过repo + ssh下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。
    
  ```
  repo init -u git@gitee.com:openharmony/manifest.git -b master --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

  方式二：通过repo + https下载。

    
  ```
  repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

- **OpenHarmony发布分支代码获取**
  OpenHarmony各个版本发布分支的源码获取方式请参考[Release-Notes](../../release-notes/Readme.md)。


### 执行prebuilts

  在源码根目录下执行prebuilts脚本，安装编译器及二进制工具。
  
```
bash build/prebuilts_download.sh
```


## 安装编译工具

想要详细了解OpenHarmony编译构建模块功能的开发者可参考[编译构建指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-build.md)。


### 安装hb

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 如需安装代理，请参考[配置代理](../quick-start/quickstart-lite-reference.md#配置代理)。

1. 运行如下命令安装hb并更新至最新版本
     
   ```
   pip3 install --user build/lite
   ```

2. 设置环境变量
     
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

3. 在源码目录执行"hb -h"，界面打印以下信息即表示安装成功：
     
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

> ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
> - 可采用以下命令卸载hb：
>     
>   ```
>   pip3 uninstall ohos-build
>   ```
> 
> - 若安装hb的过程中遇到问题，请参见下文[常见问题](../quick-start/quickstart-lite-faq-hb.md)进行解决。


### 安装LLVM(仅OpenHarmony_v1.x分支/标签需要)

> ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
> 如果下载的源码为OpenHarmony_v1.x分支/标签，请按下面的步骤安装9.0.0版本的llvm。
> 
> 如果下载的源码为Master及非OpenHarmony_v1.x分支/标签，可直接跳过本小节，hb会自动下载最新的llvm。

1. 打开Linux编译服务器终端。

2. [下载LLVM工具](https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar)。

3. 解压LLVM安装包至~/llvm路径下。
     
   ```
   tar -zxvf llvm.tar -C ~/
   ```

4. 设置环境变量。
     
   ```
   vim ~/.bashrc
   ```

   将以下命令拷贝到.bashrc文件的最后一行，保存并退出。

     
   ```
   export PATH=~/llvm/bin:$PATH
   ```

5. 生效环境变量。
     
   ```
   source ~/.bashrc
   ```
