# 烧录


Hi3861V100开发板支持串口烧录方式，在Windows下通过以下步骤进行烧录：

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 
> 当前文档中匹配的是DevEco Device Tool 3.0 Release版本。不同版本的界面和使用方法略有差异，若您使用的是最新版本的DevEco Device Tool，可参考[轻量系统（基于Hi3861开发板）烧录](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-ide-3861-burn.md)。



1. 请连接好电脑和待烧录开发板，需要连接USB口，具体可参考[Hi3861V100开发板介绍](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-lite-introduction-hi3861.md)。

2. 在DevEco Device Tool中，选择REMOTE DEVELOPMENT &gt; Local PC，查看远程计算机（Ubuntu开发环境）与本地计算机（Windows开发环境）的连接状态。

   - 如果Local PC右边连接按钮为![zh-cn_image_0000001261315939](figures/zh-cn_image_0000001261315939.png)，则远程计算机与本地计算机为已连接状态，不需要执行其他操作。
   - 如果Local PC右边连接按钮为![zh-cn_image_0000001261515989](figures/zh-cn_image_0000001261515989.png)，则点击绿色连接进行按钮。

   ![zh-cn_image_0000001261395999](figures/zh-cn_image_0000001261395999.png)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 该操作仅在远程模式（Windows+Ubuntu混合开发环境）中需要设置，如果采用本地模式（Windows开发环境或Ubuntu开发环境），则请跳过该步骤。

3. 在DevEco Device Tool中，点击QUICK ACCESS &gt; DevEco Home &gt; Device，查看并记录对应的串口号。

   ![zh-cn_image_0000001216274840](figures/zh-cn_image_0000001216274840.png)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果对应的串口异常，请根据[Hi3861V100开发板串口驱动安装](https://device.harmonyos.com/cn/docs/documentation/guide/hi3861-drivers-0000001058153433)安装USB转串口的驱动程序。

4. 在QUICK ACCESS &gt; DevEco Home &gt; Projects中，点击**Settings**打开工程配置界面。

   ![zh-cn_image_0000001198943768](figures/zh-cn_image_0000001198943768.png)

5. 在“hi3861”页签，设置烧录选项，包括upload_port、upload_protocol和upload_partitions。

   - upload_port：选择已查询的串口号。
   - upload_protocol：选择烧录协议，选择“hiburn-serial”。
   - upload_partitions：选择待烧录的文件，默认选择hi3861_app。

   ![zh-cn_image_0000001243704061](figures/zh-cn_image_0000001243704061.png)

6. 检查待烧录文件的烧录信息，DevEco Device Tool已预置默认的烧录文件信息，可根据实际情况进行调整。
   在“hi3861_app”页签，在New Option选项中选择partition_bin（烧录文件路径），然后设置待烧录文件的地址。

   ![zh-cn_image_0000001260919759](figures/zh-cn_image_0000001260919759.png)

7. 所有的配置都修改完成后，在工程配置页签的顶部，点击**Save**进行保存。

8. 点击**Open**打开工程文件，然后在“PROJECT TASKS”中，点击hi3861下的**Upload**按钮，启动烧录。

   ![zh-cn_image_0000001216440138](figures/zh-cn_image_0000001216440138.png)

9. 启动烧录后，显示如下提示信息时，请按开发板上的RST按钮重启开发板。

   ![zh-cn_image_0000001198466090](figures/zh-cn_image_0000001198466090.png)

10. 重新上电后，界面提示如下信息时，表示烧录成功。
   
    ![zh-cn_image_0000001216761476](figures/zh-cn_image_0000001216761476.png)
