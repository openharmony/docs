# 烧录


当前DevEco Device Tool Ubuntu版本尚不支持，需要采用Windows版本的DevEco Device Tool进行烧录。具体操作如下：


1. 安装DevEco Device Tool Windows版本，详细操作请参考[DevEco Device Tool Windows版本安装](https://device.harmonyos.com/cn/docs/documentation/guide/ide-install-windows-0000001050164976)。

2. [下载](https://gitee.com/hihope_iot/docs/blob/master/HiHope_DAYU200/%E7%83%A7%E5%86%99%E5%B7%A5%E5%85%B7%E5%8F%8A%E6%8C%87%E5%8D%97/windows/DriverAssitant_v5.1.1.zip)并安装驱动DriverInstall.exe，双击DriverInstall.exe打开安装程序，点击“驱动安装”按钮，按提示安装USB驱动。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果已经安装旧版本的烧写工具，请先点击"驱动卸载"按钮卸载驱动，然后再点击"驱动安装"按钮安装驱动。

3. 请连接好电脑和待烧录开发板，连接USB接口。

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

9. 等待开发板烧录完成，当屏幕提示如下信息时，表示烧录成功。
   ![zh-cn_image_0000001194984912](figures/zh-cn_image_0000001194984912.png)
