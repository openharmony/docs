# 运行<a name="ZH-CN_TOPIC_0000001216535389"></a>

-   [镜像运行](#section11324753143912)
-   [下一步学习](#section9712145420182)

## 镜像运行<a name="section11324753143912"></a>

在完成Hi3516DV300的烧录后，还需要设置BootLoader引导程序，才能运行OpenHarmony系统。

1.  在Hi3516DV300任务中，点击**Configure bootloader（Boot OS）**进行配置即可。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >DevEco Device Tool针对Hi3516DV300开发板的BootLoader设置进行了适配，无需开发者手动修改。

    ![](figures/bootloader.png)

2.  提示如下图中的重启开发板的提示信息时，重启开发板，然后在控制台输出“SUCCESS”表示设置成功。

    ![](figures/reset_success.png)

3.  在任务栏点击**Monitor**按钮，启动串口工具。

    ![](figures/monitor.png)

4.  当界面打印回显信息，点击Enter按钮，直到界面显示OHOS \#信息，表示系统启动成功。

    ![](figures/reboot_success.png)


## 下一步学习<a name="section9712145420182"></a>

恭喜您，已完成Hi3516的快速上手！建议您下一步进入[带屏摄像头产品开发](../guide/device-iotcamera.md)的学习 。

