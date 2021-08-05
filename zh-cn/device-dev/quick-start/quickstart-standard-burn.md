# 镜像烧录<a name="ZH-CN_TOPIC_0000001119964704"></a>

-   [标准系统镜像烧录](#section105761398576)
    -   [前提条件](#section1458192114718)
    -   [使用网口烧录](#section13755191035815)

-   [下一步](#section5600113114323)

## 标准系统镜像烧录<a name="section105761398576"></a>

注;:此版本是引用的

标准系统烧录，在V2.2 Beta1及以上版本支持。

Hi3516DV300支持烧录标准系统，其烧录方式包括网口烧录和串口烧录三种方式，其中：

-   **Windows系统：支持USB烧录、网口烧录和串口烧录**
-   **Linux系统：支持串口烧录和网口烧录。**

同一种烧录方式（如网口烧录），在Windows和Linux环境下的烧录操作完全一致，区别仅在于DevEco Device Tool环境搭建不同。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>当前Hi3516DV300开发板支持通过网口、USB、串口三种方式烧录OpenHarmony标准系统。本文以网口方式为例讲解烧录操作，其他两种烧录方式请参照[Hi3516DV300烧录指导](https://device.harmonyos.com/cn/docs/ide/user-guides/hi3516_upload-0000001052148681)。

### 前提条件<a name="section1458192114718"></a>

在DevEco Device Tool中，选择**Import Project**打开待烧录文件所在文件夹，其中MCU选择**HiSilicon\_Arm\_Linux**下的Hi3516DV300，Framework选择“Hb”。

![](figure/zh-cn_image_0000001141572584.png)

### 使用网口烧录<a name="section13755191035815"></a>

Hi3516DV300开发板使用网口录方式，支持Windows和Linux系统。

1.  请连接好电脑和待烧录开发板，需要同时连接串口、网口和电源，具体可参考[Hi3516DV300开发板介绍](https://device.harmonyos.com/cn/docs/start/introduce/quickstart-lite-introduction-hi3516-0000001152041033)。
2.  <a name="zh-cn_topic_0000001056443961_li1050616379507"></a>打开电脑的设备管理器，查看并记录对应的串口号。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >如果对应的串口异常，请根据[Hi3516DV300/Hi3518EV300开发板串口驱动安装指导](https://device.harmonyos.com/cn/docs/ide/user-guides/hi3516_hi3518-drivers-0000001050743695)安装USB转串口的驱动程序。

    ![](figure/zh-cn_image_0000001114129428.png)

3.  打开DevEco Device Tool，在Projects中，点击**Settings**打开工程配置界面。

    ![](figure/2021-01-27_170334-17.png)

4.  在“hi3516dv300”页签，设置烧录选项，包括upload\_port、upload\_partitions和upload\_protocol。

    -   upload\_port：选择步骤[2](#zh-cn_topic_0000001056443961_li1050616379507)中查询的串口号。
    -   upload\_protocol：选择烧录协议，固定选择“hiburn-net”。
    -   upload\_partitions：选择待烧录的文件，默认情况下会同时烧录fastboot、boot、updater、misc、system、vendor和userdata。

    ![](figure/zh-cn_image_0000001117621400.png)

5.  检查和设置连接开发板后的网络适配器的IP地址信息，设置方法请参考[设置Hi3516DV300网口烧录的IP地址信息](https://device.harmonyos.com/cn/docs/ide/user-guides/set_ipaddress-0000001141825075)。
6.  设置网口烧录的IP地址信息，设置如下选项：

    -   upload\_net\_server\_ip：选择步骤6中设置的IP地址信息。例如192.168.1.2
    -   upload\_net\_client\_mask：设置开发板的子网掩码，工具会自动根据选择的upload\_net\_server\_ip进行设置。例如255.255.255.0
    -   upload\_net\_client\_gw：设置开发板的网关，工具会自动根据选择的upload\_net\_server\_ip进行设置。例如192.168.1.1
    -   upload\_net\_client\_ip：设置开发板的IP地址，工具会自动根据选择的upload\_net\_server\_ip进行设置。例如192.168.1.3

    ![](figure/zh-cn_image_0000001117463460.png)

7.  所有的配置都修改完成后，在工程配置页签的顶部，点击**Save**进行保存。
8.  启动烧录后，显示如下提示信息时，请重启开发板（下电再上电）。

    ![](figure/zh-cn_image_0000001114129432.png)

9.  重新上电后，启动烧录，界面提示如下信息时，表示烧录成功。

    ![](figure/zh-cn_image_0000001113969542.png)


## 下一步<a name="section5600113114323"></a>

恭喜！您已经完成了OpenHarmony标准系统的快速入门，接下来可[开发一个小示例](../guide/device-clock-guide.md)，进一步熟悉OpenHarmony的开发。

