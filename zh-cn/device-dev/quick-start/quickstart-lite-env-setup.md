# 搭建轻量与小型系统环境


## 系统要求

- Windows系统要求：Windows10 64位系统。

- Ubuntu系统要求：Ubuntu18.04及以上版本，内存推荐16 GB及以上。

- Windows系统和Ubuntu系统的用户名不能包含中文字符。

- Windows和Ubuntu上安装的DevEco Device Tool为3.0 Release版本。


## 安装必要的库和工具

编译OpenHarmony需要一些库和工具，可以通过以下步骤进行安装。

相应操作在Ubuntu环境中进行。

1. 使用如下apt-get命令安装后续操作所需的库和工具：
     
   ```
   sudo apt-get update && sudo apt-get install binutils binutils-dev git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib gcc-arm-linux-gnueabi libc6-dev-i386 libc6-dev-amd64 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby genext2fs device-tree-compiler make libffi-dev e2fsprogs pkg-config perl openssl libssl-dev libelf-dev libdwarf-dev u-boot-tools mtd-utils cpio doxygen liblz4-tool openjdk-8-jre gcc g++ texinfo dosfstools mtools default-jre default-jdk libncurses5 apt-utils wget scons python3.8-distutils tar rsync git-core libxml2-dev lib32z-dev grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5-dev libncursesw5 libstdc++6 gcc-arm-none-eabi vim ssh locales
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。其中：
   > 
   > - Python要求安装Python 3.8及以上版本，此处以Python 3.8为例。
   > 
   > - Java要求java8及以上版本，此处以java8为例。

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

通过Windows系统远程访问Ubuntu环境进行烧录等操作，需要先在Windows和Ubuntu下分别安装DevEco Device Tool。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> DevEco Device Tool是OpenHarmony的一站式开发工具，支持源码开发、编译、烧录，调测等，本文主要用其远端连接Ubuntu环境进行烧录和运行。


### 安装Window版本DevEco Device Tool

1. 下载[DevEco Device Tool 3.0 Release](https://device.harmonyos.com/cn/ide#download)Windows版。

2. 解压DevEco Device Tool压缩包，双击安装包程序，点击Next进行安装。

3. 设置DevEco Device Tool的安装路径，请注意安装路径不能包含中文字符，同时建议安装到非系统盘符，点击**Next**。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果您已安装DevEco Device Tool 3.0 Beta2及以前的版本，则在安装新版本时，会先卸载旧版本，卸载过程中出现如下错误提示时，请点击“Ignore”继续安装，该错误不影响新版本的安装。
   > 
   > ![zh-cn_image_0000001239275843](figures/zh-cn_image_0000001239275843.png)

   ![zh-cn_image_0000001270076961](figures/zh-cn_image_0000001270076961.png)

4. 根据安装向导提示，勾选要自动安装的软件。

   1. 在弹出VSCode installation confirm页面，勾选“Install VScode 1.62.2automatically”，点击**Next**。

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
       > 如果检测到Visual Studio Code已安装，且版本为1.62及以上，则会跳过该步骤。

       ![zh-cn_image_0000001237801283](figures/zh-cn_image_0000001237801283.png)

   2. 在弹出的Python select page选择“Download from Huawei mirror”，点击**Next**。

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
       > 如果系统已安装可兼容的Python版本（Python 3.8~3.9版本），可选择“Use one of compatible on your PC”。


       ![zh-cn_image_0000001193983334](figures/zh-cn_image_0000001193983334.png)

5. 在以下界面点击**Next**。

   ![zh-cn_image_0000001259180828](figures/zh-cn_image_0000001259180828.png)

6. 请详细阅读以下界面的用户协议和隐私声明，这里须勾选"I accept the licenses"，然后点击Next，安装向导才会继续进行软件下载和安装。

   ![zh-cn_image_0000001307019009](figures/zh-cn_image_0000001307019009.png)

7. 继续等待DevEco Device Tool安装向导自动安装DevEco Device Tool插件，直至安装完成，点击**Finish**，关闭DevEco Device Tool安装向导。

   ![zh-cn_image_0000001239650137](figures/zh-cn_image_0000001239650137.png)

8. 打开Visual Studio Code，进入DevEco Device Tool工具界面。至此，DevEco Device Tool Windows开发环境安装完成。

   ![zh-cn_image_0000001225760456](figures/zh-cn_image_0000001225760456.png)


### 安装Ubuntu版本DevEco Device Tool

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

2. 下载[DevEco Device Tool 3.0 Release](https://device.harmonyos.com/cn/ide#download) Linux版本。

3. 解压DevEco Device Tool软件包并对解压后的文件夹进行赋权。

   1. 进入DevEco Device Tool软件包目录，执行如下命令解压软件包，其中devicetool-linux-tool-3.0.0.401.zip为软件包名称，请根据实际进行修改。
         
       ```
       unzip devicetool-linux-tool-3.0.0.401.zip
       ```
   2. 进入解压后的文件夹，执行如下命令，赋予安装文件可执行权限，其中devicetool-linux-tool-3.0.0.401.sh请根据实际进行修改。
         
       ```
       chmod u+x devicetool-linux-tool-3.0.0.401.sh
       ```

4. 执行如下命令，安装DevEco Device Tool，其中devicetool-linux-tool-3.0.0.401.sh请根据实际进行修改。
     
   ```
   sudo ./devicetool-linux-tool-3.0.0.401.sh
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   >
   > 安装过程中，会自动检查Python是否安装，且要求Python为3.8~3.9版本。如果不满足，则安装过程中会自动安装，提示“Do you want to continue?”，请输入“Y”后继续安装。
   > 
   > 安装过程中，会弹出用户协议和隐私声明签署的页面，请详细阅读用户协议和隐私声明，需签署同意用户协议和隐私声明才能进行下一步的安装。
   > 
   > 如果未弹出用户协议和隐私声明签署的页面，而直接退出了安装，请先执行apt-get install whiptail，然后再执行安装命令。

   安装完成后，当界面输出“Deveco Device Tool successfully installed.”时，表示DevEco Device Tool安装成功。

   ![zh-cn_image_0000001198722374](figures/zh-cn_image_0000001198722374.png)


## 配置Windows远程访问Ubuntu环境


### 安装SSH服务并获取远程访问的IP地址

1. 在Ubuntu系统中，打开终端工具，执行如下命令安装SSH服务。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果执行该命令失败，提示openssh-server和openssh-client依赖版本不同，请根据CLI界面提示信息，安装openssh-client相应版本后（例如：sudo apt-get install openssh-client=1:8.2p1-4），再重新执行该命令安装openssh-server。

     
   ```
   sudo apt-get install openssh-server
   ```

2. 执行如下命令，启动SSH服务。
     
   ```
   sudo systemctl start ssh
   ```

3. 执行如下命令，获取当前用户的IP地址，用于Windows系统远程访问Ubuntu环境。
     
   ```
   ifconfig
   ```

   ![zh-cn_image_0000001215737140](figures/zh-cn_image_0000001215737140.png)


### 安装Remote SSH

1. 打开Windows系统下的Visual Studio Code，点击![zh-cn_image_0000001239080359](figures/zh-cn_image_0000001239080359.png)，在插件市场的搜索输入框中输入“remote-ssh”。

   ![zh-cn_image_0000001193920448](figures/zh-cn_image_0000001193920448.png)

2. 点击Remote-SSH的**Install**按钮，安装Remote-SSH。安装成功后，在**INSTALLED**下可以看到已安装Remote-SSH。

   ![zh-cn_image_0000001238880335](figures/zh-cn_image_0000001238880335.png)


### 远程连接Ubuntu环境

1. 打开Windows系统的Visual Studio Code，点击![zh-cn_image_0000001238760373](figures/zh-cn_image_0000001238760373.png)，在REMOTE EXOPLORER页面点击+按钮。
  
   ![zh-cn_image_0000001215878922](figures/zh-cn_image_0000001215878922.png)

2. 在弹出的SSH连接命令输入框中输入“ssh _username_\@_ip_address_”，其中ip_address为要连接的远程计算机的IP地址，username为登录远程计算机的帐号。

   ![zh-cn_image_0000001215879750](figures/zh-cn_image_0000001215879750.png)

3. 在弹出的输入框中，选择SSH configuration文件，选择默认的第一选项即可。

   ![zh-cn_image_0000001260519729](figures/zh-cn_image_0000001260519729.png)

4. 在SSH TARGETS中，找到远程计算机，点击![zh-cn_image_0000001194080414](figures/zh-cn_image_0000001194080414.png)，打开远程计算机。

   ![zh-cn_image_0000001215720398](figures/zh-cn_image_0000001215720398.png)

5. 在弹出的输入框中，选择**Linux**，然后在选择**Continue**，然后输入登录远程计算机的密码，连接远程计算机 。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 在Windows系统远程访问Ubuntu过程中，需要频繁的输入密码进行连接，为解决该问题，您可以使用SSH公钥来进行设置，设置方法请参考[注册远程访问Ubuntu环境的公钥](https://device.harmonyos.com/cn/docs/documentation/guide/ide-registering-public-key-0000001247162706)。

   ![zh-cn_image_0000001215897530](figures/zh-cn_image_0000001215897530.png)

   连接成功后，等待在远程计算机.vscode-server文件夹下自动安装插件，安装完成后，根据界面提示在Windows系统下重新加载Visual Studio Code，便可以在Windows的DevEco Device Tool界面进行源码开发、编译、烧录等操作。


## 获取源码

在Ubuntu环境下通过以下步骤获取OpenHarmony源码。


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


### 获取方式

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

相关操作在Ubuntu环境下进行。


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
