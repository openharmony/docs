# Running on the Device<a name="EN-US_TOPIC_0000001054809161"></a>

Before you install the application and run it on the development board, install the DevEco Device Tool by following operations provided in [HUAWEI DevEco Device Tool User Guide](https://device.harmonyos.com/en/docs/ide/user-guides/service_introduction-0000001050166905). Burn OpenHarmony into the development board, and run it on the board. For details about how to compile, burn, and run an image, see the [Quick Start Overview](../quick-start/quickstart-overview.md). After the image is running normally and the system is started properly, perform the following steps to install or uninstall the application:

1.  Store the compiled unsigned application installation package and installation tool in an SD card and insert the SD card into the development board slot. The installation tool is in **dev\_tools** of the directory where the image file is generated.
2.  Run the following command to disable signature verification, which is enabled by default for application installation:

    ```
    ./sdcard/dev_tools/bin/bm set -s disable
    ```

3.  Run the following command to install the application:

    ```
    ./sdcard/dev_tools/bin/bm install -p /sdcard/airquality.hap 
    ```

    The **dev\_tools** directory stores the installation tool, and **airquality.hap** is the application installation package. Replace it with actual the package name.

4.  After the application is installed, touch the application icon on the home screen to enter the application.

    **Figure 1** Home screen<a name="fig146361926155516"></a>  
    ![](figures/home-screen.png "home-screen")

5.  \(Optional\) Uninstall the application.

    Touch and hold the application icon on the home screen, and touch the uninstall button in the displayed menu.


