# Burning


Burning is the process of downloading compiled program files to a development board to provide a basis for subsequent debugging. With the one-click burning function of DevEco Device Tool, you can burn images on development boards quickly and efficiently.


> ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**
> - If you are using source code from the master branch released since May 9, 2022, use HiTool for burning.
> 
> - DevEco Device Tool currently does not support burning of source code released before May 9, 2022. This feature will be introduced in the coming version.


To burn source code to Hi3516D V300 through the USB port in Windows, perform the following steps.


## Importing Source Code

[Ensure that the Windows system can remotely access the Ubuntu environment](../quick-start/quickstart-standard-env-setup.md), and then perform the following steps to import source code:

1. Open DevEco Device Tool, go to the home page, and click **Import Project** to open your project or source code.

   ![en-us_image_0000001278358765](figures/en-us_image_0000001278358765.png)

2. Select the target directory (in the Ubuntu environment) and click **Import**.
   > ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**
   > Make sure the selected directory does not contain Chinese characters or spaces.

   ![en-us_image_0000001235266636](figures/en-us_image_0000001235266636.png)

3. If this is the first time you import the source code, the following dialog box will be displayed. Click **Import** when prompted.

   ![en-us_image_0000001314076609](figures/en-us_image_0000001314076609.png)

4. On the **Select Project type** page, select **Import from OpenHarmony Source**.

   ![en-us_image_0000001215743910](figures/en-us_image_0000001215743910.png)

5. On the **Import Project** page, select **Hi3516DV300** for **Product**, and the MCU, board, company, and kernel fields will be automatically populated. Then, select the OpenHarmony source code version for **Ohos Ver**.

   ![en-us_image_0000001279426717](figures/en-us_image_0000001279426717.png)

6. Click **Open** to open the project or source code.


## Burning

After the source code is imported, perform the following steps:

> ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**
> This feature is available in DevEco Device Tool 2.2 Beta2 and later versions.

1. Connect the computer and the target development board through the serial port and USB port. For details, see [Introduction to the Hi3516D V300 Development Board](https://gitee.com/openharmony/docs/blob/master/en/device-dev/quick-start/quickstart-lite-introduction-hi3516.md).
   > ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**
   > If you are using the remote access mode (Windows + Ubuntu on the local VM), disable the USB control of the VM as follows to ensure that the development board is connected to the USB port of the host:
   > 
   > - VMware: Configure the device to connect to the host under **Preferences** > **USB** and remove the USB controller from the VM settings.
   > 
   > - VirtualBox: Deselect **Enable USB Controller** in the USB device options under Ubuntu settings.

2. If your computer does not have the USB port driver or USB-to-serial driver, install it by following the instructions in [Installing the USB Port Driver on the Hi3516D V300 or Hi3518E V300 Development Board](Installing the USB Port Driver on the Hi3516D V300 or Hi3518E V300 Development Board) or [Installing the Serial Port Driver on the Hi3516D V300 or Hi3518E V300 Development Board](https://device.harmonyos.com/en/docs/documentation/guide/hi3516_hi3518-drivers-0000001050743695), depending on the missing driver.

3. In DevEco Device Tool, choose **REMOTE DEVELOPMENT** > **Local PC** to check the connection status between the remote computer (Ubuntu build environment) and the local computer (Windows build environment).
   - If ![en-us_image_0000001261315939](figures/en-us_image_0000001261315939.png) is displayed on the right of **Local PC**, the remote computer is connected to the local computer. In this case, no further action is required.
   - If ![en-us_image_0000001261515989](figures/en-us_image_0000001261515989.png) is displayed, click the connect icon.

   ![en-us_image_0000001261395999](figures/en-us_image_0000001261395999.png)

   > ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**
   > This operation is required only in remote access mode (in the Windows+Ubuntu hybrid build environment). If the local access mode (Windows or Ubuntu build environment) is used, skip this step.

4. Check the serial port number in **QUICK ACCESS** > **DevEco Home** > **Device** in DevEco Device Tool.

   ![en-us_image_0000001315910101](figures/en-us_image_0000001315910101.png)

5. Choose **QUICK ACCESS** > **DevEco Home** > **Projects**, and then click **Settings**.

   ![en-us_image_0000001198566364](figures/en-us_image_0000001198566364.png)

6. On the **hi3516dv300** tab page, set the burning options.
   - **upload_partitions**: Select the files to be burnt. By default, **fastboot**, **boot**, **updater**, **misc**, **system**, **vendor**, and **userdata** are burnt at the same time.
   - **upload_port**: Select the serial port number obtained.
   - **upload_protocol**: Select the burning protocol **hiburn-usb**.

   ![en-us_image_0000001177478136](figures/en-us_image_0000001177478136.png)

7. In **Partitions**, check the preset burning settings of the files to be burnt.

   ![en-us_image_0000001312541849](figures/en-us_image_0000001312541849.png)

     To modify the burning settings for a specific file, click ![en-us_image_0000001265361888](figures/en-us_image_0000001265361888.png) next to the file.
   > ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**
   > Set the start address and length of the partition based on the size of the files to be burnt. Make sure the size of the partition is greater than that of the files to be burnt and the partition addresses of the files to be burnt do not overlap.

   ![en-us_image_0000001264982466](figures/en-us_image_0000001264982466.png)

8. When you finish modifying, click **Save** on the top.

9. Go to **hi3516dv300** > **Upload** to transfer the files to be burnt from Ubuntu to Windows. When the "Operation paused, Please press Enter key to continue" message is displayed, which indicates that the transfer is complete, press **Enter** to start burning.

   ![en-us_image_0000001315932049](figures/en-us_image_0000001315932049.png)

10. When the following information is displayed in the **TERMINAL** window, press and hold the reset button within 15 seconds, remove and insert the USB cable, and release the reset button to start burning.

    ![en-us_image_0000001114129426](figures/en-us_image_0000001114129426.png)

    If the following message is displayed, it indicates that the burning is successful.

    ![en-us_image_0000001160649343](figures/en-us_image_0000001160649343.png)

11. When the burning is successful, perform the operations in Running to start the system.
