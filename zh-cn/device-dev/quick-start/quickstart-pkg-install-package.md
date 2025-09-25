# 安装库和工具集


使用命令行进行设备开发时，可以通过以下步骤安装编译OpenHarmony需要的库和工具。


相应操作在Ubuntu环境中进行。


1. 使用如下apt-get命令安装后续操作所需的库和工具：
   
   ```
   sudo apt-get update; y | sudo apt-get install binutils; y | sudo apt-get install binutils-dev; y | sudo apt-get install git; y | sudo apt-get install git-lfs; y | sudo apt-get install gnupg; y | sudo apt-get install flex; y | sudo apt-get install bison; y | sudo apt-get install gperf; y | sudo apt-get install build-essential; y | sudo apt-get install zip; y | sudo apt-get install curl; y | sudo apt-get install zlib1g-dev; y | sudo apt-get install gcc-multilib; y | sudo apt-get install g++-multilib; y | sudo apt-get install gcc-arm-linux-gnueabi; y | sudo apt-get install libc6-dev-i386; y | sudo apt-get install libc6-dev-amd64; y | sudo apt-get install lib32ncurses5-dev; y | sudo apt-get install x11proto-core-dev; y | sudo apt-get install libx11-dev; y | sudo apt-get install lib32z1-dev; y | sudo apt-get install ccache; y | sudo apt-get install libgl1-mesa-dev; y | sudo apt-get install libxml2-utils; y | sudo apt-get install xsltproc; y | sudo apt-get install unzip; y | sudo apt-get install m4; y | sudo apt-get install bc; y | sudo apt-get install gnutls-bin; y | sudo apt-get install python3.9; y | sudo apt-get install python3-pip; y | sudo apt-get install ruby; y | sudo apt-get install genext2fs; y | sudo apt-get install device-tree-compilersudo apt-get install make; y | sudo apt-get install libffi-dev; y | sudo apt-get install e2fsprogs; y | sudo apt-get install pkg-config; y | sudo apt-get install perl; y | sudo apt-get install openssl; y | sudo apt-get install libssl-dev; y | sudo apt-get install libelf-dev; y | sudo apt-get install libdwarf-dev; y | sudo apt-get install u-boot-tools; y | sudo apt-get install mtd-utils; y | sudo apt-get install cpio; y | sudo apt-get install doxygen; y | sudo apt-get install liblz4-tool; y | sudo apt-get install openjdk-8-jre; y | sudo apt-get install gcc; y | sudo apt-get install g++; y | sudo apt-get install texinfo; y | sudo apt-get install dosfstools; y | sudo apt-get install mtools; y | sudo apt-get install default-jre; y | sudo apt-get install default-jdk; y | sudo apt-get install libncurses5; y | sudo apt-get install apt-utils; y | sudo apt-get install wget; y | sudo apt-get install scons; y | sudo apt-get install python3.9-distutils; y | sudo apt-get install tar; y | sudo apt-get install rsync; y | sudo apt-get install git-core; y | sudo apt-get install libxml2-dev; y | sudo apt-get install lib32z-dev; y | sudo apt-get install grsync; y | sudo apt-get install xxd; y | sudo apt-get install libglib2.0-dev; y | sudo apt-get install libpixman-1-dev; y | sudo apt-get install kmod; y | sudo apt-get install jfsutils; y | sudo apt-get install reiserfsprogs; y | sudo apt-get install xfsprogs; y | sudo apt-get install squashfs-tools; y | sudo apt-get install pcmciautils; y | sudo apt-get install quota; y | sudo apt-get install ppp; y | sudo apt-get install libtinfo-dev; y | sudo apt-get install libtinfo5; y | sudo apt-get install libncurses5-dev; y | sudo apt-get install libncursesw5; y | sudo apt-get install libstdc++6; y | sudo apt-get install gcc-arm-none-eabi; y | sudo apt-get install vim; y | sudo apt-get install ssh; y | sudo apt-get install locales; y | sudo apt-get install libxinerama-dev; y | sudo apt-get install libxcursor-dev; y | sudo apt-get install libxrandr-dev; y | sudo apt-get install libxi-dev
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
