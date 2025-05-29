# 安装库和工具集


使用命令行进行设备开发时，可以通过以下步骤安装编译OpenHarmony需要的库和工具。


相应操作在Ubuntu环境中进行。


1. 使用如下apt-get命令安装后续操作所需的库和工具：
   
   ```
   sudo apt-get update; sudo apt-get install binutils; sudo apt-get install binutils-dev; sudo apt-get install git; sudo apt-get install git-lfs; sudo apt-get install gnupg; sudo apt-get install flex; sudo apt-get install bison; sudo apt-get install gperf; sudo apt-get install build-essential; sudo apt-get install zip; sudo apt-get install curl; sudo apt-get install zlib1g-dev; sudo apt-get install gcc-multilib; sudo apt-get install g++-multilib; sudo apt-get install gcc-arm-linux-gnueabi; sudo apt-get install libc6-dev-i386; sudo apt-get install libc6-dev-amd64; sudo apt-get install lib32ncurses5-dev; sudo apt-get install x11proto-core-dev; sudo apt-get install libx11-dev; sudo apt-get install lib32z1-dev; sudo apt-get install ccache; sudo apt-get install libgl1-mesa-dev; sudo apt-get install libxml2-utils; sudo apt-get install xsltproc; sudo apt-get install unzip; sudo apt-get install m4; sudo apt-get install bc; sudo apt-get install gnutls-bin; sudo apt-get install python3.9; sudo apt-get install python3-pip; sudo apt-get install ruby; sudo apt-get install genext2fs; sudo apt-get install device-tree-compilersudo apt-get install make; sudo apt-get install libffi-dev; sudo apt-get install e2fsprogs; sudo apt-get install pkg-config; sudo apt-get install perl; sudo apt-get install openssl; sudo apt-get install libssl-dev; sudo apt-get install libelf-dev; sudo apt-get install libdwarf-dev; sudo apt-get install u-boot-tools; sudo apt-get install mtd-utils; sudo apt-get install cpio; sudo apt-get install doxygen; sudo apt-get install liblz4-tool; sudo apt-get install openjdk-8-jre; sudo apt-get install gcc; sudo apt-get install g++; sudo apt-get install texinfo; sudo apt-get install dosfstools; sudo apt-get install mtools; sudo apt-get install default-jre; sudo apt-get install default-jdk; sudo apt-get install libncurses5; sudo apt-get install apt-utils; sudo apt-get install wget; sudo apt-get install scons; sudo apt-get install python3.9-distutils; sudo apt-get install tar; sudo apt-get install rsync; sudo apt-get install git-core; sudo apt-get install libxml2-dev; sudo apt-get install lib32z-dev; sudo apt-get install grsync; sudo apt-get install xxd; sudo apt-get install libglib2.0-dev; sudo apt-get install libpixman-1-dev; sudo apt-get install kmod; sudo apt-get install jfsutils; sudo apt-get install reiserfsprogs; sudo apt-get install xfsprogs; sudo apt-get install squashfs-tools; sudo apt-get install pcmciautils; sudo apt-get install quota; sudo apt-get install ppp; sudo apt-get install libtinfo-dev; sudo apt-get install libtinfo5; sudo apt-get install libncurses5-dev; sudo apt-get install libncursesw5; sudo apt-get install libstdc++6; sudo apt-get install gcc-arm-none-eabi; sudo apt-get install vim; sudo apt-get install ssh; sudo apt-get install locales; sudo apt-get install libxinerama-dev; sudo apt-get install libxcursor-dev; sudo apt-get install libxrandr-dev; sudo apt-get install libxi-dev
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   >
   > - 以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。其中：
   > 
   >   - Python要求安装Python 3.8及以上版本，此处以Python 3.8为例。
   > 
   >   - Java要求java8及以上版本，此处以java8为例。
   >
   > - 若您使用的是Ubuntu20及以上版本，由于gcc-multilib和gcc-arm-linux-gnueabi互斥，请勿安装gcc-arm-linux-gnueabi。
   > 
   > - 执行过程中需要多次点击回车以确认安装所需的库和工具。

2. 将Python 3.8设置为默认Python版本。
   
   查看Python 3.8的位置：

   ```
   which python3.8
   ```

   如果无输出请在环境中安装python3.8或以上版本，以下安装命令可作为python3安装的参考：
   
   ```
   sudo apt-get install python3
   sudo apt-get install python-is-python3
   ```
   查询python是否可用符合版本要求：

   ```
   python --version
   ```
   如果输出高于3.8，则版本符合要求，若低于3.8可用以下方式安装Python3.8：
   
   ```
   cd
   mkdir python_install     #新建路径，存储python的安装包
   cd python_install
   
   wget https://mirrors.huaweicloud.com/python/3.8.10/Python-3.8.10.tgz    #从官网获取Python3.8安装包，此处以3.8.10版本为例
   tar -xzf Python-3.8.10.tgz 
   cd Python-3.8.10
   
   ./configure --enable-optimizations --prefix=/usr/local/python3.8    #编译和安装python3.8
   make -j$(nproc)
   sudo make install

   /usr/local/python3.8/bin/python3.8 --version    #确认python3.8是否安装成功
   
   sudo update-alternatives --install /usr/bin/python python /usr/local/python3.8/bin/python3.8 1     #将Python和Python3切换为Python 3.8：
   sudo update-alternatives --install /usr/bin/python3 python3 /usr/local/python3.8/bin/python3.8 1
   ```
