# Running on the Device<a name="EN-US_TOPIC_0000001054809161"></a>

For details about the development board, compilation, burning, and image running process, see  [Getting Started with Hi3516](../quick-start/introduction-to-the-hi3516-development-board.md). After image running is executed and the system is started normally, perform the following steps to install or uninstall the third-party application:

1.  Store the unsigned application installation package and installation tool compiled by the IDE in an SD card. \(IP camera applications currently do not support signature.\) The installation tool is in  **idev\_tools**  in the directory where the image file is generated.
2.  Run the  **./sdcard/dev\_tools/bin/bm set -s disable**  command to disable signature verification.
3.  Run the  **./sdcard/dev\_tools/bin/bm install -p /sdcard/airquality.hap**  command to install the application.

    The  **dev\_tools**  directory stores the installation tool, and  **airquality.hap**  is the application installation package.

4.  After the application is installed, touch the application icon on the home screen to start the application.

    **Figure  1**  Home screen<a name="fig146361926155516"></a>  
    ![](figures/home-screen.png "home-screen")

5.  \(Optional\) Uninstall the application.

    Touch and hold the application icon on the home screen, and touch the uninstall button in the displayed menu.


