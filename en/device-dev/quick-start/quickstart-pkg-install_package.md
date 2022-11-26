# Installing Libraries and Tools


Before using the CLI for device development, perform the following steps on Ubuntu to install the required libraries and tools.


On Ubuntu:


1. Run the following **apt-get** command:
   
   ```
   sudo apt-get update && sudo apt-get install binutils binutils-dev git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib gcc-arm-linux-gnueabi libc6-dev-i386 libc6-dev-amd64 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby genext2fs device-tree-compiler make libffi-dev e2fsprogs pkg-config perl openssl libssl-dev libelf-dev libdwarf-dev u-boot-tools mtd-utils cpio doxygen liblz4-tool openjdk-8-jre gcc g++ texinfo dosfstools mtools default-jre default-jdk libncurses5 apt-utils wget scons python3.8-distutils tar rsync git-core libxml2-dev lib32z-dev grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5-dev libncursesw5 libstdc++6 gcc-arm-none-eabi vim ssh locales libxinerama-dev libxcursor-dev libxrandr-dev libxi-dev
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > The preceding command is applicable to Ubuntu 18.04. For other Ubuntu versions, modify the preceding installation command based on the installation package name. The details are as follows:
   >
   > - Python 3.8 or a later version is required. This section uses Python 3.8 as an example.
   >
> - Java 8 or later is required. This section uses Java 8 as an example.
   
2. Set Python 3.8 as the default Python version.
   
   Check the location of Python 3.8.

   
   ```
   which python3.8
   ```

   Switch Python and Python3 to Python 3.8.
   
   ```
   sudo update-alternatives --install /usr/bin/python python {Python 3.8 path} 1    #{Python 3.8 path} is the location of Python 3.8 obtained in the previous step.
   sudo update-alternatives --install /usr/bin/python3 python3 {Python 3.8 path} 1   #{Python 3.8 path} is the location of Python 3.8 obtained in the previous step.
   ```
