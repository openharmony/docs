# 安装库和工具集


使用命令行进行设备开发时，可以通过以下步骤安装编译OpenHarmony需要的库和工具。


相应操作在Ubuntu环境中进行。


1. 使用如下apt-get命令安装后续操作所需的库和工具：
   
   ```
   sudo apt-get update && sudo apt-get install binutils binutils-dev git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib gcc-arm-linux-gnueabi libc6-dev-i386 libc6-dev-amd64 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby genext2fs device-tree-compiler make libffi-dev e2fsprogs pkg-config perl openssl libssl-dev libelf-dev libdwarf-dev u-boot-tools mtd-utils cpio doxygen liblz4-tool openjdk-8-jre gcc g++ texinfo dosfstools mtools default-jre default-jdk libncurses5 apt-utils wget scons python3.8-distutils tar rsync git-core libxml2-dev lib32z-dev grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5-dev libncursesw5 libstdc++6 gcc-arm-none-eabi vim ssh locales libxinerama-dev libxcursor-dev libxrandr-dev libxi-dev
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。其中：
   > 
   > - Python要求安装Python 3.8及以上版本，此处以Python 3.8为例。
   > 
   > - Java要求java8及以上版本，此处以java8为例。

2. 将Python 3.8设置为默认Python版本。
   
   查看Python 3.8的位置：

   
   ```
   which python3.8
   ```

   将Python和Python3切换为Python 3.8：
   
   ```
   sudo update-alternatives --install /usr/bin/python python {Python 3.8 路径} 1    #{Python 3.8 路径}为上一步查看的Python 3.8的位置
   sudo update-alternatives --install /usr/bin/python3 python3 {Python 3.8 路径} 1   #{Python 3.8 路径}为上一步查看的Python 3.8的位置
   ```
