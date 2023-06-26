# Burning an Image


Burning is the process of downloading compiled program files to a development board to provide a basis for subsequent debugging. With the one-click burning function of DevEco Device Tool, you can burn images on development boards quickly and efficiently.


The images of RK3568 are burnt in the Windows environment. After burning is initiated, DevEco Device Tool copies the target program files generated in the Ubuntu environment to the specified Windows directory in remote mode, and then burns the program files to RK3568 using the Windows burning tool.


## Preparations

[Download](https://gitee.com/hihope_iot/docs/blob/master/HiHope_DAYU200/%E7%83%A7%E5%86%99%E5%B7%A5%E5%85%B7%E5%8F%8A%E6%8C%87%E5%8D%97/windows/DriverAssitant_v5.1.1.zip) and install **DriverInstall.exe**. If a message is displayed to indicate that the driver has been installed, you can proceed to the burning steps.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> If the burning tool of an earlier version has been installed, uninstall it first.


## Procedure

1. Connect the computer and the target development board through the USB port. For details, see [RK3568 Development Board](quickstart-appendix-rk3568.md).

2. In DevEco Device Tool, choose **REMOTE DEVELOPMENT** > **Local PC** to check the connection status between the remote computer (Ubuntu build environment) and the local computer (Windows build environment).

   - If ![en-us_image_0000001326512673](figures/en-us_image_0000001326512673.png) is displayed on the right of **Local PC**, the remote computer is connected to the local computer. In this case, no further action is required.
   - If ![en-us_image_0000001275432904](figures/en-us_image_0000001275432904.png) is displayed, click the connect icon. During the connection, DevEco Device Tool will restart. Therefore, to avoid task interruptions, do not connect to DevEco Device Tool when downloading or building source code.

   ![en-us_image_0000001285658392](figures/en-us_image_0000001285658392.png)

3. Click **Project Settings** on the menu bar to access the RK3568 project configuration page.

   ![en-us_image_0000001330777737](figures/en-us_image_0000001330777737.png)

4. On the **Tool Chain** tab page, DevEco Device Tool automatically checks for the uploader tool.

   - If any tool is indicated as **uninstalled** (![status_uninstall](figures/status_uninstall.png)), click **Download Uninstalled Tools** to install all the required tools, or click **Download** next to a tool to install the specific tool.
   - If **Download** is not available for a missing tool, it is not cataloged in DevEco Device Tool. In this case, you need to download the tool to the local host and click **Import** to import it.

   ![rk3568_false](figures/rk3568_false.png)

5. On the **rk3568** tab page, set the burning options. The settings are automatically saved.

   - **upload_partitions_profile**: Select the burning profile file, which specifies the files to be burnt, start address and length of the partition, and other burning settings. In addition, select **Enable to use upload_partitions_profile**.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
      >
      > In the burning profile file, you can change the start address and length of the partition based on the size of the files to be burnt. Make sure the size of the partition is greater than that of the files to be burnt and the partition addresses of the files do not overlap.
      > 
      > If this is the first time you burn files to the development board, select **Enable to use upload_partitions_profile for upload** so that the upload_partitions file will be automatically generated. Afterward, select **Enable to use upload_partitions_profile for upload** only when you need to generate a new **upload_partitions** file.
   - **upload_protocol**: Select the burning protocol **upgrade**.

   ![en-us_image_0000001338663697](figures/en-us_image_0000001338663697.png)

6. Choose **PROJECT TASKS** > **rk3568** > **Upload** to start burning.

   ![en-us_image_0000001280147358](figures/en-us_image_0000001280147358.png)

7. If the message "Operation paused, Please press Enter key to continue" is displayed, press **Enter**.
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > If the message "The board is not in Loader mode. Please Hold on the VOL+key..." is displayed, place the development board in Loader mode as follows: Press and hold the Volume+ key for 3 seconds, press the RESET key, wait for 3 seconds, and then release the Volume+ key.

   Wait until the burning is complete. If the following message is displayed, the burning is successful.

   ![en-us_image_0000001327549705](figures/en-us_image_0000001327549705.png)
