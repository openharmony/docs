# 搭建Windows+Ubuntu混合开发环境


通常在嵌入式开发中，很多开发者习惯于使用Windows进行代码的编辑，比如使用Windows的Visual Studio Code进行OpenHarmony代码的开发。但当前阶段，大部分的开发板源码还不支持在Windows环境下进行编译，如Hi3861、Hi3516系列开发板。因此，建议使用Ubuntu的编译环境对源码进行编译。


在以上的设备开发场景中，可以搭建一套Windows+Ubuntu混合开发的环境，其中使用Windows平台的DevEco Device Tool可视化界面进行相关操作，通过远程连接的方式对接Ubuntu下的DevEco Device Tool（可以不安装Visual Studio Code），然后对Ubuntu下的源码进行开发、编译、烧录等操作。


## 系统要求

- Windows系统要求：Windows10 64位系统。

- Ubuntu系统要求：Ubuntu18.04~21.10版本，内存推荐16 GB及以上。

- Ubuntu系统的用户名不能包含中文字符。

- Windows和Ubuntu系统上安装的DevEco Device Tool为3.0 Release版本。


## 搭建Ubuntu环境

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 如果没有Ubuntu系统，可在Windows系统中通过虚拟机方式搭建Ubuntu系统，具体请参考[Ubuntu系统安装指导](https://developer.huawei.com/consumer/cn/training/course/video/C101639987816176315)。Ubuntu系统安装完成后，请根据指导完成[Ubuntu基础环境配置](https://developer.huawei.com/consumer/cn/training/course/video/C101639988048536240)，然后再根据本章节进行DevEco Device Tool工具的安装。

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

5. 在用户协议和隐私声明签署界面，请详细阅读用户协议和隐私声明，需签署同意用户协议和隐私声明才能进行下一步的安装。

   ![zh-cn_image_0000001322167645.png](figures/zh-cn_image_0000001322167645.png)
   
   安装完成后，当界面输出“Deveco Device Tool successfully installed.”时，表示DevEco Device Tool安装成功。
   
   ![zh-cn_image_0000001198722374](figures/zh-cn_image_0000001198722374.png)



## 搭建Windows开发环境

1. 下载[DevEco Device Tool 3.0 Release](https://device.harmonyos.com/cn/ide#download) Windows版。

2. 解压DevEco Device Tool压缩包，双击安装包程序，点击Next进行安装。

3. 设置DevEco Device Tool的安装路径，请注意安装路径不能包含中文字符，同时建议安装到非系统盘符，点击**Next**。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   >
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


## 配置Windows远程访问Ubuntu环境


### 安装SSH服务并获取远程访问的IP地址

1. 在Ubuntu系统中，打开终端工具，执行如下命令安装SSH服务。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   >
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
   >
   > 在Windows系统远程访问Ubuntu过程中，需要频繁的输入密码进行连接，为解决该问题，您可以使用SSH公钥来进行设置，设置方法请参考[注册远程访问Ubuntu环境的公钥](https://device.harmonyos.com/cn/docs/documentation/guide/ide-registering-public-key-0000001247162706)。

   ![zh-cn_image_0000001215897530](figures/zh-cn_image_0000001215897530.png)

   连接成功后，等待在远程计算机.vscode-server文件夹下自动安装插件，安装完成后，根据界面提示在Windows系统下重新加载Visual Studio Code，便可以在Windows的DevEco Device Tool界面进行源码开发、编译、烧录等操作。
