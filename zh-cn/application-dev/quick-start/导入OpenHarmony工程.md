# 导入OpenHarmony工程<a name="ZH-CN_TOPIC_0000001163914943"></a>

OpenHarmony SDK配置完成后，便可以启动应用开发。针对OpenHarmony应用开发，**只能通过导入Sample工程的方式来创建一个新工程**。

1.  在DevEco Studio的欢迎页，点击**Import HarmonyOS Sample**按钮，导入Sample工程。

    ![](figures/zh-cn_image_0000001163835551.png)

2.  选择ability下的**HelloWorld**工程，然后点击**Next**。

    ![](figures/zh-cn_image_0000001117635678.png)

3.  设置**App Name**和**Project Location**，然后点击**Finish**，等待Sample工程导入完成。

    ![](figures/zh-cn_image_0000001163915521.png)

4.  Sample导入后，等待工程同步完成，此时工程会同步失败。请打开工程下的build.gradle，修改hap插件的版本号为“2.4.4.3-RC”。

    ![](figures/zh-cn_image_0000001117475776.png)

5.  修改完成后，点击右上角Gradle中的![](figures/zh-cn_image_0000001163835553.png)按钮，重新同步工程。

    ![](figures/zh-cn_image_0000001117635680.png)

6.  等待工程同步完成，同步成功后，便可以进行OpenHarmony应用开发了。

    ![](figures/zh-cn_image_0000001163915523.png)


