# 搭建系统环境


DevEco Device Tool Ubuntu版本是OpenHarmony的一站式开发工具，支持源码开发、编译、烧录，调测等。下文介绍如何在Ubuntu环境下安装DevEco Device Tool。


## 系统要求

- Ubuntu20.04及以上版本，内存推荐16 GB及以上。

- 系统的用户名不能含有中文字符。


## 安装DevEco Device Tool

DevEco Device Tool基于Visual Studio Code进行扩展，在Visual Studio Code上以插件方式运行，Visual Studio Code版本为1.62及以上。同时，DevEco Device Tool还依赖Python工具，并要求Python为3.8~3.9版本。

在安装过程中，DevEco Device Tool会自动检查Visual Studio Code和Python，如果检测到Visual Studio Code、Python未安装或版本不符合要求，安装程序会自动安装Visual Studio Code和Python。

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

2. 下载[DevEco Device Tool 3.0 Release](https://device.harmonyos.com/cn/ide#download)Linux版本。

3. 解压DevEco Device Tool软件包并对解压后的文件夹进行赋权。
   1. 进入DevEco Device Tool软件包目录，执行如下命令解压软件包，其中devicetool-linux-tool-3.0.0.400.zip为软件包名称，请根据实际进行修改。
         
       ```
       unzip devicetool-linux-tool-3.0.0.400.zip
       ```
   2. 进入解压后的文件夹，执行如下命令，赋予安装文件可执行权限，其中devicetool-linux-tool-3.0.0.400.sh请根据实际进行修改。
         
       ```
       chmod u+x devicetool-linux-tool-3.0.0.400.sh
       ```

4. 执行如下命令，安装DevEco Device Tool，其中devicetool-linux-tool-3.0.0.300.sh请根据实际进行修改。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 安装过程中，会自动检查Visual Studio Code和Python是否安装，且版本符合要求，其中Visual Studio Code为1.62及以上版本，Python为3.8~3.9版本。如果不满足，则安装过程中会自动安装，提示“Do you want to continue?”，请输入“Y”后继续安装。

     
   ```
   sudo ./devicetool-linux-tool-3.0.0.300.sh -- --install-plugins
   ```

   安装完成后，当界面输出“Deveco Device Tool successfully installed.”时，表示DevEco Device Tool安装成功。

   ![zh-cn_image_0000001243282363](figures/zh-cn_image_0000001243282363.png)

5. 安装完成后，启动Visual Studio Code。

6. 打开Visual Studio Code，进入DevEco Device Tool工具界面。至此，DevEco Device Tool Ubuntu开发环境安装完成。
   ![zh-cn_image_0000001243284745](figures/zh-cn_image_0000001243284745.png)
