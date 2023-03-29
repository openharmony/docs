# 真机运行<a name="ZH-CN_TOPIC_0000001054809161"></a>

应用编译打包后即可安装到开发板。安装应用前需要先完成[DevEco Device Tool的安装配置](https://device.harmonyos.com/cn/docs/ide/user-guides/service_introduction-0000001050166905)，然后将OpenHarmony烧录到开发板并运行。编译烧录、运行镜像的基本操作请参考快速入门手册：[小型系统快速入门](../quick-start/quickstart-overview.md)。完成镜像运行，系统正常启动后，执行如下步骤安装或卸载三方应用。

1.  将IDE编译的未签名应用安装包和安装工具（镜像文件生成目录中的dev\_tools）放在sdcard中，将sdcard插入开发板卡槽。
2.  应用安装默认要校验签名，需要执行以下命令，关闭签名校验。

    ```
    ./sdcard/dev_tools/bin/bm set -s disable
    ```

3.  执行以下命令，安装应用。

    ```
    ./sdcard/dev_tools/bin/bm install -p /sdcard/airquality.hap 
    ```

    其中dev\_tools目录中是安装工具，airquality.hap为应用安装包，此处替换为实际工程的安装包名称。

4.  应用安装完成后，可点击桌面应用图标启动应用，进行操作。

    **图 1**  桌面<a name="fig146361926155516"></a>  
    ![](figures/桌面.png "桌面")

5.  卸载应用（可选）。

    长按桌面应用图标，在弹出的菜单中点击“卸载”按钮即可卸载应用。


