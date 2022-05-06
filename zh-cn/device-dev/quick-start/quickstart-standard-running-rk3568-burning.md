# 烧录


在Windows环境下通过以下步骤进行RK3568的烧录：


### 导入源码

在编译完成后，[保证Windows系统可以远程访问Ubuntu环境](../quick-start/quickstart-standard-env-setup.md)的情况下，您还需要通过以下步骤导入源码后，方可进行烧录。

1. 打开DevEco Device Tool，进入Home页，点击**Import Project**打开工程。

   ![zh-cn_image_0000001171426014](figures/zh-cn_image_0000001171426014.png)

2. 选择要导入的源码目录（需要访问Ubuntu下的源码目录），点击**Import**打开。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 工程存储路径不能包含中文字符、空格。如果工程存储路径包含中文字符或空格，可能导致编译失败。

   ![zh-cn_image_0000001272032361](figures/zh-cn_image_0000001272032361.png)

3. 如果您打开的目录不是DevEco Device Tool工程，则会出现如下提示框，点击**Import**。

   ![zh-cn_image_0000001135394334](figures/zh-cn_image_0000001135394334.png)

4. 在Select Project type界面，选择**Import from OpenHarmony Source**。

   ![zh-cn_image_0000001215743910](figures/zh-cn_image_0000001215743910.png)

5. 在Import Project界面，选择**Product**后，会自动填充对应的MCU、Board、company和kernel信息，然后**ohosVersion**选择对应的OpenHarmony源码版本。此处选择rk3568。

   ![zh-cn_image_0000001227712350](figures/zh-cn_image_0000001227712350.png)

6. 点击**Open**打开工程或源码。


### 烧录

完成源码导入后，通过以下步骤进行烧录：

1. [下载](https://gitee.com/hihope_iot/docs/blob/master/HiHope_DAYU200/%E7%83%A7%E5%86%99%E5%B7%A5%E5%85%B7%E5%8F%8A%E6%8C%87%E5%8D%97/windows/DriverAssitant_v5.1.1.zip)并安装驱动DriverInstall.exe，双击DriverInstall.exe打开安装程序，点击“驱动安装”按钮，按提示安装USB驱动。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果已经安装旧版本的烧写工具，请先点击"驱动卸载"按钮卸载驱动，然后再点击"驱动安装"按钮安装驱动。

2. 请连接好电脑和待烧录开发板，连接USB接口。

3. 在DevEco Device Tool中，选择REMOTE DEVELOPMENT &gt; Local PC，查看远程计算机（Ubuntu开发环境）与本地计算机（Windows开发环境）的连接状态。

   - 如果Local PC右边连接按钮为![zh-cn_image_0000001261315939](figures/zh-cn_image_0000001261315939.png)，则远程计算机与本地计算机为已连接状态，不需要执行其他操作。
   - 如果Local PC右边连接按钮为![zh-cn_image_0000001261515989](figures/zh-cn_image_0000001261515989.png)，则点击绿色连接进行按钮。

   ![zh-cn_image_0000001261395999](figures/zh-cn_image_0000001261395999.png)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 该操作仅在远程模式（Windows+Ubuntu混合开发环境）中需要设置，如果采用本地模式（Windows开发环境或Ubuntu开发环境），则请跳过该步骤。

4. 打开DevEco Device Tool，在QUICK ACCESS &gt; DevEco Home &gt; Projects中，点击**Settings**打开工程配置界面。

   ![zh-cn_image_0000001239661509](figures/zh-cn_image_0000001239661509.png)

5. 在“hh_scdy200”页签，设置烧录选项，包括upload_partitions和upload_protocol。

   - upload_partitions：选择待烧录的文件。
   - upload_protocol：选择烧录协议，固定选择“upgrade”。

   ![zh-cn_image_0000001194504874](figures/zh-cn_image_0000001194504874.png)

6. 分别检查待烧录文件的烧录信息，DevEco Device Tool已预置默认的烧录文件信息，可根据实际情况进行调整。待烧录文件包括：loader、parameter、uboot、boot_linux、system、vendor和userdata。

   1. 在“hh_scdy200_loader”页签，在New Option选项中选择需要修改的项，例如partition_bin（烧录文件路径）、partition_addr（烧录文件起始地址）、partition_length（烧录文件分区长度）等。

       ![zh-cn_image_0000001224173270](figures/zh-cn_image_0000001224173270.png)

   2. 然后在Partition Options中，分别修改上述步骤中选择的修改项。

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
       > 在设置烧录分区起始地址和分区长度时，应根据实际待烧录文件的大小进行设置，要求设置的烧录分区大小，要大于待烧录文件的大小；同时，各烧录文件的分区地址设置不能出现重叠。

       ![zh-cn_image_0000001268653461](figures/zh-cn_image_0000001268653461.png)

   3. 按照相同的方法修改parameter、uboot、boot_linux、system、vendor和userdata的烧录文件信息。

7. 所有的配置都修改完成后，在工程配置页签的顶部，点击**Save**进行保存。

8. 点击工程的Open按钮，打开工程文件，点击![zh-cn_image_0000001239221905](figures/zh-cn_image_0000001239221905.png)图标，打开DevEco Device Tool界面，在“PROJECT TASKS”中，点击hh_scdy200下的**Upload**按钮，启动烧录。

   ![zh-cn_image_0000001194821710](figures/zh-cn_image_0000001194821710.png)

9. 当屏幕提示“Operation paused，Please press Enter key to continue”，请按回车键继续。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果开发板未处于烧录模式，屏幕会提示“The boad is not in Loader mode.Please Hold on the VOL+key...”，此时，请长按音量+键，3秒后点击RESET键，然后再过3秒放开音量+键，使开发板进入烧录模式。

10. 等待开发板烧录完成，当屏幕提示如下信息时，表示烧录成功。

   ![zh-cn_image_0000001194984912](figures/zh-cn_image_0000001194984912.png)
