# Setting Up the Ubuntu Environment

In embedded development, Windows-based tools, such as Visual Studio Code, are widely used in code editing. Yet, because the source code of most development boards, such as Hi3861 and Hi3516, cannot be built in Windows, these development boards require the Ubuntu build environment.

In the Windows+Ubuntu hybrid build environment, you can enjoy the benefits of both DevEco Device Tool for Windows and DevEco Device Tool for Ubuntu (where Visual Studio Code is optional).

The following describes how to set up the Ubuntu environment.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> If the Ubuntu system has not been set up yet, set it up on a virtual machine running Windows. For details, see [Ubuntu Installation Guide](https://developer.huawei.com/consumer/cn/training/course/video/C101639987816176315). Then, [configure the Ubuntu basic environment](https://developer.huawei.com/consumer/cn/training/course/video/C101639988048536240).


## System Requirements

- Ubuntu: Ubuntu 18.04 to 21.10; version 20.04 with 16 GB or larger memory is recommended

- User name (Ubuntu): cannot contain Chinese characters


## Procedure

1. Make sure the Ubuntu shell environment is **bash**.
   1. Run the following command and check whether the command output is **bash**. If the command output is not **bash**, go to step 2.
      
       ```shell
       ls -l /bin/sh
       ```

       ![en-us_image_0000001226764302](figures/en-us_image_0000001226764302.png)
   2. Start the command-line tool, run the following command, enter your password, and select **No** to set **Ubuntu shell** to **bash**.
      
       ```shell
       sudo dpkg-reconfigure dash
       ```

       ![ubuntu-dash-to-bash](figures/ubuntu-dash-to-bash.png)

2. Download the [DevEco Device Tool 3.0 Release](https://device.harmonyos.com/cn/ide#download) Linux edition.

3. Decompress the DevEco Device Tool software package and assign permission on the folder obtained from the decompression.
   1. Go to the directory where the DevEco Device Tool software package is stored and run the following command to decompress the software package. In the command, change **devicetool-linux-tool-3.1.0.300.zip** to the actual software package name.
      
       ```shell
       unzip devicetool-linux-tool-3.1.0.300.zip
       ```
   2. Open the folder of the decompressed software package and run the following command to grant the execute permission on the installation file. In the command, change **devicetool-linux-tool-3.1.0.300.sh** to the actual installation file name.
      
       ```shell
       chmod u+x devicetool-linux-tool-3.1.0.300.sh
       ```

4. Run the following command to install DevEco Device Tool, where **devicetool-linux-tool-3.1.0.300.sh** indicates the installation file name.
   
   ```shell
   sudo ./devicetool-linux-tool-3.1.0.300.sh
   ```

5. On the page for agreeing to the user agreement and privacy statement, read and agree to the user agreement and privacy statement. You can scroll through the options by pressing the up and down arrow keys on the keyboard.

   ![en-us_image_0000001340557741](figures/en-us_image_0000001340557741.png)

   Wait until the "DevEco Device Tool successfully installed." message is displayed.

   ![en-us_image_0000001338201457](figures/en-us_image_0000001338201457.png)


6. Run the following **apt-get** command:
   
   ```shell
   sudo apt-get update && sudo apt-get install binutils binutils-dev git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib gcc-arm-linux-gnueabi libc6-dev-i386 libc6-dev-amd64 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby genext2fs device-tree-compiler make libffi-dev e2fsprogs pkg-config perl openssl libssl-dev libelf-dev libdwarf-dev u-boot-tools mtd-utils cpio doxygen liblz4-tool openjdk-8-jre gcc g++ texinfo dosfstools mtools default-jre default-jdk libncurses5 apt-utils wget scons python3.8-distutils tar rsync git-core libxml2-dev lib32z-dev grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5-dev libncursesw5 libstdc++6 gcc-arm-none-eabi vim ssh locales libxinerama-dev libxcursor-dev libxrandr-dev libxi-dev
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > The preceding command is applicable to Ubuntu 18.04. For other Ubuntu versions, modify the preceding installation command based on the installation package name.
   > 
   > - Python 3.8 or a later version is required. In this example, Python 3.8 is used.
   > 
   > - Java 8 or later is required. In this example, Java 8 is used.
