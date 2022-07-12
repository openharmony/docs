# 使用HiTool烧录代码


针对Hi3516DV300开发板，除了DevEco Device Tool外，还可以使用HiTool进行烧录。


## 前提条件

- 开发板相关源码已编译完成，已形成烧录文件。

- 客户端（操作平台，例如Windows系统）已下载并安装[HiTool工具](http://www.hihope.org/download/download.aspx)。

- 客户端（操作平台，例如Windows系统）已安装USB驱动，可参考[Hi3516DV300/Hi3518EV300开发板USB驱动安装指导](https://device.harmonyos.com/cn/docs/documentation/guide/usb_driver-0000001058690393)。

- 客户端已安装串口终端工具（例如IPOP）。

- 使用USB线缆、串口线缆连接客户端与开发板。


## 操作步骤

1. 准备烧录相关文件。

   1. 在客户端新建用于保存烧录文件的文件夹，例如D:\L2。

   2. 将编译完成的源码包下载至客户端并解压，将烧录相关文件拷贝至步骤1中新建的文件夹。

       Hi3516DV300开发板烧写所需文件为：boot.img、Hi3516DV300-emmc.xml、system.img、u-boot-hi3516dv300_emmc.bin、uImage、updater.img、userdata.img、vendor.img。

2. 使用HiTool烧录。

   1. 打开HiTool。

   2. 设置HiTool参数。

      传输方式选择USB口，烧写方式选择烧写eMMC（单板的存储介质为eMMC）。

   3. 单击浏览在步骤1创建的文件夹中选择烧写配置文件（例如Hi3516DV300-emmc.xml）。

       ![zh-cn_image_0000001249937194](figures/zh-cn_image_0000001249937194.png)

   4. 单击烧写后，按住开发板上串口旁的按钮（Update键），并拔插USB线（上下电）。

       烧录开始后，可以在HiTool工具下方的控制台区域观察到烧录过程中的打印信息。

       烧录完成后，HiTool弹出提示框显示烧写成功。

   5. 单击确定。

3. 导入启动参数。

   1. 使用终端工具打开串口。

   2. 拔插开发板电源使其重启，3s内在串口终端输入回车。

       终端界面中出现hisilicon \#表示已连接开发板串口。

   3. 在串口终端拷贝如下启动参数后，按回车完成配置。
         
       ```
       setenv bootargs 'mem=640M console=ttyAMA0,115200 mmz=anonymous,0,0xA8000000,384M clk_ignore_unused androidboot.selinux=permissive rootdelay=10 hardware=Hi3516DV300 init=/init root=/dev/ram0 rw blkdevparts=mmcblk0:1M(boot),15M(kernel),20M(updater),2M(misc),3307M(system),256M(vendor),-(userdata)';setenv bootcmd 'mmc read 0x0 0x82000000 0x800 0x4800; bootm 0x82000000'
       
       saveenv
       
       reset
       ```

       > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
       > 输入启动参数时，请勿自行删除其中的空行。
