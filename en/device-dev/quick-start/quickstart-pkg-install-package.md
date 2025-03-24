# Installing Libraries and Tools


Before using the CLI for device development, perform the following steps to install the required libraries and tools.


On Ubuntu:


1. Run the following **apt-get** command:
   
   ```
   sudo apt-get update; sudo apt-get install binutils; sudo apt-get install binutils-dev; sudo apt-get install git; sudo apt-get install git-lfs; sudo apt-get install gnupg; sudo apt-get install flex; sudo apt-get install bison; sudo apt-get install gperf; sudo apt-get install build-essential; sudo apt-get install zip; sudo apt-get install curl; sudo apt-get install zlib1g-dev; sudo apt-get install gcc-multilib; sudo apt-get install g++-multilib; sudo apt-get install gcc-arm-linux-gnueabi; sudo apt-get install libc6-dev-i386; sudo apt-get install libc6-dev-amd64; sudo apt-get install lib32ncurses5-dev; sudo apt-get install x11proto-core-dev; sudo apt-get install libx11-dev; sudo apt-get install lib32z1-dev; sudo apt-get install ccache; sudo apt-get install libgl1-mesa-dev; sudo apt-get install libxml2-utils; sudo apt-get install xsltproc; sudo apt-get install unzip; sudo apt-get install m4; sudo apt-get install bc; sudo apt-get install gnutls-bin; sudo apt-get install python3.9; sudo apt-get install python3-pip; sudo apt-get install ruby; sudo apt-get install genext2fs; sudo apt-get install device-tree-compilersudo apt-get install make; sudo apt-get install libffi-dev; sudo apt-get install e2fsprogs; sudo apt-get install pkg-config; sudo apt-get install perl; sudo apt-get install openssl; sudo apt-get install libssl-dev; sudo apt-get install libelf-dev; sudo apt-get install libdwarf-dev; sudo apt-get install u-boot-tools; sudo apt-get install mtd-utils; sudo apt-get install cpio; sudo apt-get install doxygen; sudo apt-get install liblz4-tool; sudo apt-get install openjdk-8-jre; sudo apt-get install gcc; sudo apt-get install g++; sudo apt-get install texinfo; sudo apt-get install dosfstools; sudo apt-get install mtools; sudo apt-get install default-jre; sudo apt-get install default-jdk; sudo apt-get install libncurses5; sudo apt-get install apt-utils; sudo apt-get install wget; sudo apt-get install scons; sudo apt-get install python3.9-distutils; sudo apt-get install tar; sudo apt-get install rsync; sudo apt-get install git-core; sudo apt-get install libxml2-dev; sudo apt-get install lib32z-dev; sudo apt-get install grsync; sudo apt-get install xxd; sudo apt-get install libglib2.0-dev; sudo apt-get install libpixman-1-dev; sudo apt-get install kmod; sudo apt-get install jfsutils; sudo apt-get install reiserfsprogs; sudo apt-get install xfsprogs; sudo apt-get install squashfs-tools; sudo apt-get install pcmciautils; sudo apt-get install quota; sudo apt-get install ppp; sudo apt-get install libtinfo-dev; sudo apt-get install libtinfo5; sudo apt-get install libncurses5-dev; sudo apt-get install libncursesw5; sudo apt-get install libstdc++6; sudo apt-get install gcc-arm-none-eabi; sudo apt-get install vim; sudo apt-get install ssh; sudo apt-get install locales; sudo apt-get install libxinerama-dev; sudo apt-get install libxcursor-dev; sudo apt-get install libxrandr-dev; sudo apt-get install libxi-dev
   ```

   > **NOTE**
   >
   > - The preceding command is applicable to Ubuntu 18.04. For other Ubuntu versions, modify the preceding installation command based on the installation package name.  
   > 
   >   - Python 3.8 or a later version is required. This section uses Python 3.8 as an example.
   > 
   >   - Java 8 or later is required. This section uses Java 8 as an example.
   >
   > - If you are using Ubuntu 20 or later, do not install gcc-arm-linux-gnueabi, because gcc-multilib and gcc-arm-linux-gnueabi are mutually exclusive.
   > 
   > - During the execution, you may need to press **Enter** multiple times to confirm the installation of the required libraries and tools.

2. Set Python 3.8 as the default Python version.
   
   Check the location of Python 3.8.

   ```
   which python3.8
   ```

   If there is no output, install Python 3.8 or a later version in your environment. The following installation commands can be used as a reference for installing Python 3:
   
   ```
   sudo apt-get install python3
   sudo apt-get install python-is-python3
   ```
   Check whether Python meets the version requirement:

   ```
   python --version
   ```
   If the output is higher than 3.8, the version is acceptable. If it is lower than 3.8, you can install Python 3.8 using the following method:
   
   ```
   cd
   mkdir python_install     # Create a directory to store the Python installation package.
   cd python_install
   
   wget https://mirrors.huaweicloud.com/python/3.8.10/Python-3.8.10.tgz    # Download the Python 3.8 installation package from the official website (example version 3.8.10).
   tar -xzf Python-3.8.10.tgz 
   cd Python-3.8.10
   
   ./configure --enable-optimizations --prefix=/usr/local/python3.8    # Compile and install Python 3.8.
   make -j$(nproc)
   sudo make install

   /usr/local/python3.8/bin/python3.8 --version    # Confirm whether Python 3.8 is installed successfully.
   
   sudo update-alternatives --install /usr/bin/python python /usr/local/python3.8/bin/python3.8 1     # Set Python and Python3 to Python 3.8.
   sudo update-alternatives --install /usr/bin/python3 python3 /usr/local/python3.8/bin/python3.8 1
   ```
