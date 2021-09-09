# 镜像运行<a name="ZH-CN_TOPIC_0000001142160948"></a>

-   [\#ZH-CN\_TOPIC\_0000001142160948/section153991115191314](#section153991115191314)

烧录完成后通过以下步骤运行系统：

>![](../public_sys-resources/icon-note.gif) **说明：** 
>初次烧写标准系统，需要完成以下配置，后续烧写或者启动，可以跳过以下操作。

1.  在DevEco Device Tool中，点击Monitor，打开串口工具。

    ![](figure/open-the-serial-port-tool.png)

2.  重启开发板，在倒计时结束前，按任意键进入系统。

    ![](figure/press-any-key-to-enter-the-system.gif)

3.  通过以下两条命令设置启动参数。

    ```
    setenv bootargs 'mem=640M console=ttyAMA0,115200 mmz=anonymous,0,0xA8000000,384M clk_ignore_unused androidboot.selinux=permissive skip_initramfs rootdelay=5 init=/init root=/dev/mmcblk0p5 rootfstype=ext4 rw blkdevparts=mmcblk0:1M(boot),15M(kernel),20M(updater),1M(misc),3307M(system),256M(vendor),-(userdata)'
    ```

    ```
    setenv bootcmd "mmc read 0x0 0x80000000 0x800 0x4800; bootm 0x80000000";
    ```

    ![](figure/start.png)

4.  保存参数设置。

    ```
    save
    ```

    ![](figure/Save-the-parameter-settings.png)

5.  重启开发板，完成系统启动。

    ```
    reset
    ```

    ![](figure/start-the-system.png)


