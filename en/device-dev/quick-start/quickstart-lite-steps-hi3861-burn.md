# Burning


Burn the source code to Hi3861 through the serial port in Windows.


### Importing Source Code

After the building is complete, ensure that you can [remotely access the Ubuntu environment from Windows](../quick-start/quickstart-lite-env-setup.md). Then, perform the following steps to import the source code before burning:

1. Open DevEco Device Tool, go to the home page, and click **Import Project** to open your project or source code.

   ![en-us_image_0000001171426014](figures/en-us_image_0000001171426014.png)

2. Select the target directory (in the Ubuntu environment) and click **Import**.

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > Make sure the selected directory does not contain Chinese characters or spaces. Otherwise, the building may fail.

   ![en-us_image_0000001227549226](figures/en-us_image_0000001227549226.png)

3. If you select to open the OpenHarmony source code, a message will be displayed indicating that the project is not a DevEco Device Tool project. Click **Import** to continue.

   ![en-us_image_0000001135394334](figures/en-us_image_0000001135394334.png)

4. On the **Select Project type** page, select **Import from OpenHarmony Source**.

   ![en-us_image_0000001215743910](figures/en-us_image_0000001215743910.png)

5. On the **Import Project** page, select a product, and the MCU, board, company, and kernel fields will be automatically populated. Then, select the OpenHarmony source code version for **ohosVersion**. Select **wifiiot_hispark_pegasus**.

   ![en-us_image_0000001272109325](figures/en-us_image_0000001272109325.png)

6. Click **Open** to open the project or source code.


### Burning

After the source code is imported, perform the following steps:

1. Connect the computer and the target development board through the serial port and USB port. For details, see [Introduction to the Hi3861 V100 Development Board](https://gitee.com/openharmony/docs/blob/master/en/device-dev/quick-start/quickstart-lite-introduction-hi3861.md).

2. In DevEco Device Tool, choose **REMOTE DEVELOPMENT** > **Local PC** to check the connection status between the remote computer (Ubuntu development environment) and the local computer (Windows development environment).

   - If ![en-us_image_0000001261315939](figures/en-us_image_0000001261315939.png) is displayed on the right of **Local PC**, the remote computer is connected to the local computer. In this case, no further action is required.
   - If ![en-us_image_0000001261515989](figures/en-us_image_0000001261515989.png) is displayed, click the connect icon.

   ![en-us_image_0000001261395999](figures/en-us_image_0000001261395999.png)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > This operation is required only in remote access mode (in the Windows+Ubuntu hybrid development environment). If the local access mode (Windows or Ubuntu development environment) is used, skip this step.

3. Check the serial port number in **QUICK ACCESS** > **DevEco Home** > **Device** in DevEco Device Tool.

   ![en-us_image_0000001216274840](figures/en-us_image_0000001216274840.png)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > If the serial port number is not displayed correctly, follow the steps described in [Installing the Serial Port Driver on Hi3861 V100](https://device.harmonyos.com/en/docs/documentation/guide/hi3861-drivers-0000001058153433).

4. Choose **QUICK ACCESS** > **DevEco Home** > **Projects**, and then click **Settings**.

   ![en-us_image_0000001198943768](figures/en-us_image_0000001198943768.png)

5. On the **hi3861** tab page, set the burning options.

   - **upload_port**: Select the serial port number obtained.
   - **upload_protocol**: Select the burning protocol **hiburn-serial**.
   - **upload_partitions**: Select the files to be burnt. **hi3861_app** is selected by default.

   ![en-us_image_0000001243704061](figures/en-us_image_0000001243704061.png)

6. Check the preset information of the files to be burnt and modify them when necessary.

   On the **hi3861_app** tab page, select **partition_bin** from **New Option**, and set the path of the file to be burnt.

   ![en-us_image_0000001260919759](figures/en-us_image_0000001260919759.png)

7. When you finish modifying, click **Save** on the top.

8. Click **Open** to open the project file. Then, choose **PROJECT TASKS** > **hi3861** > **Upload** to start burning.

   ![en-us_image_0000001216440138](figures/en-us_image_0000001216440138.png)

9. When the following information is displayed, press the RST button on the development board to restart it.

   ![en-us_image_0000001198466090](figures/en-us_image_0000001198466090.png)

10. Wait until the burning is complete. When the following message is displayed, the burning is successful.

    ![en-us_image_0000001216761476](figures/en-us_image_0000001216761476.png)