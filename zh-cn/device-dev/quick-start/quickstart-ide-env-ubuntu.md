# 搭建Ubuntu环境

在嵌入式开发中，很多开发者习惯于使用Windows进行代码的编辑，比如使用Windows的Visual Studio Code进行OpenHarmony代码的开发。但当前阶段，大部分的开发板源码还不支持在Windows环境下进行编译，如Hi3861、Hi3516系列开发板。因此，建议使用Ubuntu的编译环境对源码进行编译。

在以上的设备开发场景中，可以搭建一套Windows+Ubuntu混合开发的环境，其中使用Windows平台的DevEco Device Tool可视化界面进行相关操作，通过远程连接的方式对接Ubuntu下的DevEco Device Tool（可以不安装Visual Studio Code），然后对Ubuntu下的源码进行开发、编译、烧录等操作。

本章节介绍开发所需Ubuntu环境的搭建方法。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 如果没有Ubuntu系统，可在Windows系统中通过虚拟机方式搭建Ubuntu系统，具体请参考[Ubuntu系统安装指导](https://developer.huawei.com/consumer/cn/training/course/video/C101639987816176315)。Ubuntu系统安装完成后，请根据指导完成[Ubuntu基础环境配置](https://developer.huawei.com/consumer/cn/training/course/video/C101639988048536240)，然后再根据本章节进行DevEco Device Tool工具的安装。


## 系统要求

- Ubuntu系统要求：Ubuntu18.04~21.10版本，内存推荐16 GB及以上。

- Ubuntu系统的用户名不能包含中文字符。


## 操作步骤

1. 将Ubuntu Shell环境修改为bash。
   1. 执行如下命令，确认输出结果为bash。如果输出结果不是bash，请根据子步骤2，将Ubuntu shell修改为bash。
      
       ```
       ls -l /bin/sh
       ```

       ![zh-cn_image_0000001226764302](figures/zh-cn_image_0000001226764302.png)
   2. 打开终端工具，执行如下命令，输入密码，然后选择**No**，将Ubuntu shell由dash修改为bash。
      
       ```
       sudo dpkg-reconfigure dash
       ```

       ![ubuntu-dash-to-bash](figures/ubuntu-dash-to-bash.png)

2. 下载[DevEco Device Tool 3.0 Release](https://device.harmonyos.com/cn/ide#download) Linux版本。

3. 解压DevEco Device Tool软件包并对解压后的文件夹进行赋权。
   1. 进入DevEco Device Tool软件包目录，执行如下命令解压软件包，其中devicetool-linux-tool-3.1.0.200.zip为软件包名称，请根据实际进行修改。
      
       ```
       unzip devicetool-linux-tool-3.1.0.200.zip
       ```
   2. 进入解压后的文件夹，执行如下命令，赋予安装文件可执行权限，其中devicetool-linux-tool-3.1.0.200.sh请根据实际进行修改。
      
       ```
       chmod u+x devicetool-linux-tool-3.1.0.200.sh
       ```

4. 执行如下命令，安装DevEco Device Tool，其中devicetool-linux-tool-3.1.0.200.sh请根据实际进行修改。
   
   ```
   sudo ./devicetool-linux-tool-3.1.0.200.sh
   ```

5. 在用户协议和隐私声明签署界面，请详细阅读用户协议和隐私声明，需签署同意用户协议和隐私声明才能进行下一步的安装，可通过键盘的上下按键进行选择。

   ![zh-cn_image_0000001340557741](figures/zh-cn_image_0000001340557741.png)

   安装完成后，当界面输出“DevEco Device Tool successfully installed.”时，表示DevEco Device Tool安装成功。

   ![zh-cn_image_0000001338201457](figures/zh-cn_image_0000001338201457.png)

6. 使用如下apt-get命令安装后续操作所需的库和工具。
   
   ```
   sudo apt-get update && sudo apt-get install binutils binutils-dev git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib gcc-arm-linux-gnueabi libc6-dev-i386 libc6-dev-amd64 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby genext2fs device-tree-compiler make libffi-dev e2fsprogs pkg-config perl openssl libssl-dev libelf-dev libdwarf-dev u-boot-tools mtd-utils cpio doxygen liblz4-tool openjdk-8-jre gcc g++ texinfo dosfstools mtools default-jre default-jdk libncurses5 apt-utils wget scons python3.8-distutils tar rsync git-core libxml2-dev lib32z-dev grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5-dev libncursesw5 libstdc++6 gcc-arm-none-eabi vim ssh locales libxinerama-dev libxcursor-dev libxrandr-dev libxi-dev
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   >
   > 以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。其中：
   > 
   > - Python要求安装Python 3.8及以上版本，此处以Python 3.8为例。
   > 
   > - Java要求java8及以上版本，此处以java8为例。
