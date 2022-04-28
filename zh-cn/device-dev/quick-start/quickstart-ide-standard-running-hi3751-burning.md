# 烧录


在Windows下采用网口烧录方式进行Hi3751V350的烧录。


1. 请使用串口连接好电脑和待烧录开发板，同时需要连接开发板和电脑到同一个局域网中

2. 在DevEco Device Tool中，选择REMOTE DEVELOPMENT &gt; Local PC，查看远程计算机（Ubuntu开发环境）与本地计算机（Windows开发环境）的连接状态。

   - 如果Local PC右边连接按钮为![zh-cn_image_0000001261315939](figures/zh-cn_image_0000001261315939.png)，则远程计算机与本地计算机为已连接状态，不需要执行其他操作。
   - 如果Local PC右边连接按钮为![zh-cn_image_0000001261515989](figures/zh-cn_image_0000001261515989.png)，则点击绿色连接进行按钮。

   ![zh-cn_image_0000001261395999](figures/zh-cn_image_0000001261395999.png)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 该操作仅在远程模式（Windows+Ubuntu混合开发环境）中需要设置，如果采用本地模式（Windows开发环境或Ubuntu开发环境），则请跳过该步骤。

3. 在DevEco Device Tool中，点击QUICK ACCESS &gt; DevEco Home &gt; Device，查看并记录对应的串口号。

   ![zn-cn_image_20220428191331](figures/zn-cn_image_20220428191331.png)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果对应的串口异常，请根据[Hi3516DV300/Hi3518EV300开发板串口驱动安装指导](https://device.harmonyos.com/cn/docs/documentation/guide/hi3516_hi3518-drivers-0000001050743695)安装USB转串口的驱动程序。

4. 在QUICK ACCESS &gt; DevEco Home &gt; Projects中，点击**Settings**打开工程配置界面。

   ![zn-cn_image_20220428191437](figures/zn-cn_image_20220428191437.png)

5. 在“hi3751v350”页签，设置烧录选项，包括upload_partitions、upload_port和upload_protocol。

   - upload_partitions：指定选择待烧录的文件，默认情况下会同时烧录fastboot,bootargs,bootargsbak,slaveboot等全部分区
   - upload_port：选择已查询到的串口号。
   - upload_protocol：选择烧录协议，固定选择“hiburn-net”。

   ![zn-cn_image_20220428192044](figures/zn-cn_image_20220428192044.png)
   ![zn-cn_image_20220428192120](figures/zn-cn_image_20220428192120.png)
   ![zn-cn_image_20220428192217](figures/zn-cn_image_20220428192217.png)

6. 分别检查待烧录文件的烧录信息，DevEco Device Tool已预置默认的烧录文件信息，可根据实际情况进行调整。待烧录文件包括：atf.bin  bootargs.bin  boot.img  dtbo.img  fastboot.bin  Hi3751V350-slaveboot-emmc.xml  logo.img  panel.img  slaveboot.bin  system.img  uImage  updater.img  userdata.img  vendor.img  zImage-dtb和ramdisk.img

   1. 在“hi3751v350”页签中的“Partitions Options”，选择需要修改的分区，点击右侧的展开按钮，可配置如partition_type（分区类型）、partition_addr（烧录文件起始地址）、partition_length（烧录文件分区长度）等。

       ![zn-cn_image_20220428192849](figures/zn-cn_image_20220428192849.png)

   2. 选中partition_bin，可自定义指定烧写文件，默认已配置。

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
       > 在设置烧录分区起始地址和分区长度时，应根据实际待烧录文件的大小进行设置，要求设置的烧录分区大小，要大于待烧录文件的大小；同时，各烧录文件的分区地址设置不能出现重叠。

   3. 按照相同的方法调整修改剩余烧录文件信息。

7. 在保证开发板和电脑连接到同一个局域网后，进行Hiburn_net网络配置

   1. 选择“Network Upload Options”配置upload_net_server_ip，工具将自动检测host的ip地址，然后需要手动选择ip

   2. 默认情况下upload_net_client_mask、upload_net_client_gw和upload_net_client_ip会在前一步选择ip后自动配置，不过需要依据当前局域网配置信息进行调整。

      ![zn-cn_image_20220428194317](figures/zn-cn_image_20220428194317.png)

8. 所有的配置都调整修改完成后，在工程配置页签的顶部，点击**Save**进行保存。

9. 断开电脑与单板的COM交互窗口，点击“PROJECT TASKS”下hi3751v350的**Upload**按钮，启动烧录。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果您是第一次在工作台烧录Hi3516DV300/Hi3518EV300/Hi3751V350开发板，可能烧录失败，提示“not find the Devices”，然后根据[Hi3516DV300/Hi3518EV300开发板USB驱动安装](https://device.harmonyos.com/cn/docs/documentation/guide/usb_driver-0000001058690393)进行处理后再重新烧录。

   ![zn-cn_image_20220428195249](figures/zn-cn_image_20220428195249.png)

10. 在终端窗口显示如下提示信息时，单板(下电并)上电，启动烧录。

      ![zn-cn_image_20220428201119](figures/zn-cn_image_20220428201119.png)

      启动烧录后，界面提示如下信息时，表示烧录成功。

      ![zn-cn_image_20220428202139](figures/zn-cn_image_20220428202139.png)

11. 烧录成功后，请根据镜像运行章节进行操作，启动系统。
