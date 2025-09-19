# 安装库和工具集


使用命令行进行设备开发时，可以通过以下步骤安装编译OpenHarmony需要的库和工具。


相应操作在Ubuntu环境中进行。


1. 使用如下apt-get命令安装后续操作所需的库和工具：
   
   ```
   sudo apt-get update; yes | sudo apt-get install binutils; yes | sudo apt-get install binutils-dev; yes | sudo apt-get install git; yes | sudo apt-get install git-lfs; yes | sudo apt-get install gnupg; yes | sudo apt-get install flex; yes | sudo apt-get install bison; yes | sudo apt-get install gperf; yes | sudo apt-get install build-essential; yes | sudo apt-get install zip; yes | sudo apt-get install curl; yes | sudo apt-get install zlib1g-dev; yes | sudo apt-get install gcc-multilib; yes | sudo apt-get install g++-multilib; yes | sudo apt-get install gcc-arm-linux-gnueabi; yes | sudo apt-get install libc6-dev-i386; yes | sudo apt-get install libc6-dev-amd64; yes | sudo apt-get install lib32ncurses5-dev; yes | sudo apt-get install x11proto-core-dev; yes | sudo apt-get install libx11-dev; yes | sudo apt-get install lib32z1-dev; yes | sudo apt-get install ccache; yes | sudo apt-get install libgl1-mesa-dev; yes | sudo apt-get install libxml2-utils; yes | sudo apt-get install xsltproc; yes | sudo apt-get install unzip; yes | sudo apt-get install m4; yes | sudo apt-get install bc; yes | sudo apt-get install gnutls-bin; yes | sudo apt-get install python3.9; yes | sudo apt-get install python3-pip; yes | sudo apt-get install ruby; yes | sudo apt-get install genext2fs; yes | sudo apt-get install device-tree-compilersudo apt-get install make; yes | sudo apt-get install libffi-dev; yes | sudo apt-get install e2fsprogs; yes | sudo apt-get install pkg-config; yes | sudo apt-get install perl; yes | sudo apt-get install openssl; yes | sudo apt-get install libssl-dev; yes | sudo apt-get install libelf-dev; yes | sudo apt-get install libdwarf-dev; yes | sudo apt-get install u-boot-tools; yes | sudo apt-get install mtd-utils; yes | sudo apt-get install cpio; yes | sudo apt-get install doxygen; yes | sudo apt-get install liblz4-tool; yes | sudo apt-get install openjdk-8-jre; yes | sudo apt-get install gcc; yes | sudo apt-get install g++; yes | sudo apt-get install texinfo; yes | sudo apt-get install dosfstools; yes | sudo apt-get install mtools; yes | sudo apt-get install default-jre; yes | sudo apt-get install default-jdk; yes | sudo apt-get install libncurses5; yes | sudo apt-get install apt-utils; yes | sudo apt-get install wget; yes | sudo apt-get install scons; yes | sudo apt-get install python3.9-distutils; yes | sudo apt-get install tar; yes | sudo apt-get install rsync; yes | sudo apt-get install git-core; yes | sudo apt-get install libxml2-dev; yes | sudo apt-get install lib32z-dev; yes | sudo apt-get install grsync; yes | sudo apt-get install xxd; yes | sudo apt-get install libglib2.0-dev; yes | sudo apt-get install libpixman-1-dev; yes | sudo apt-get install kmod; yes | sudo apt-get install jfsutils; yes | sudo apt-get install reiserfsprogs; yes | sudo apt-get install xfsprogs; yes | sudo apt-get install squashfs-tools; yes | sudo apt-get install pcmciautils; yes | sudo apt-get install quota; yes | sudo apt-get install ppp; yes | sudo apt-get install libtinfo-dev; yes | sudo apt-get install libtinfo5; yes | sudo apt-get install libncurses5-dev; yes | sudo apt-get install libncursesw5; yes | sudo apt-get install libstdc++6; yes | sudo apt-get install gcc-arm-none-eabi; yes | sudo apt-get install vim; yes | sudo apt-get install ssh; yes | sudo apt-get install locales; yes | sudo apt-get install libxinerama-dev; yes | sudo apt-get install libxcursor-dev; yes | sudo apt-get install libxrandr-dev; yes | sudo apt-get install libxi-dev
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
