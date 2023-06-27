# Burning an Image


Burning is the process of downloading compiled program files to a development board to provide a basis for subsequent debugging. With the one-click burning function of DevEco Device Tool, you can burn images on development boards quickly and efficiently.


The images of Hi3861V100 are burnt in the Windows environment. After burning is initiated, DevEco Device Tool copies the target program files generated in the Ubuntu environment to the specified Windows directory in remote mode, and then burns the program files to Hi3861V100 using the Windows burning tool.


## Prerequisites

- [Source code building](quickstart-ide-3861-build.md) has been completed.

- The USB-serial adapter driver has been installed. For details, see [Installing the USB-Serial Adapter Driver](https://device.harmonyos.com/en/docs/documentation/guide/hi3861-drivers-0000001058153433).


## Procedure

1. Connect the computer and the target development board through the USB port. For details, see [Hi3861 Development Board](quickstart-appendix-hi3861.md).

2. In DevEco Device Tool, choose **REMOTE DEVELOPMENT** > **Local PC** to check the connection status between the remote computer (Ubuntu build environment) and the local computer (Windows build environment).
   - If ![en-us_image_0000001326512673](figures/en-us_image_0000001326512673.png) is displayed on the right of **Local PC**, the remote computer is connected to the local computer. In this case, no further action is required.
   - If ![en-us_image_0000001275432904](figures/en-us_image_0000001275432904.png) is displayed, click the connect icon. During the connection, DevEco Device Tool will restart. Therefore, to avoid task interruptions, do not connect to DevEco Device Tool when downloading or building source code.

   ![en-us_image_0000001285658392](figures/en-us_image_0000001285658392.png)

3. Click **Project Settings** on the menu bar to access the Hi3861 V100 project configuration page.

   ![en-us_image_0000001333802045](figures/en-us_image_0000001333802045.png)

4. On the **Tool Chain** tab page, DevEco Device Tool automatically checks for the uploader tool.

   - If any tool is indicated as **uninstalled** (![status_uninstall](figures/status_uninstall.png)), click **Download Uninstalled Tools** to install all the required tools, or click **Download** next to a tool to install the specific tool.
   - If **Download** is not available for a missing tool, it is not cataloged in DevEco Device Tool. In this case, you need to download the tool to the local host and click **Import** to import it.

   ![3861_false](figures/3861_false.png)

5. On the **wifiiot_hispark_pegasus** tab page, set the burning options. The settings are automatically saved.
   - **upload_port**: Select the serial port number obtained.
   - **upload_protocol**: Select the burning protocol **hiburn-serial**.
   - **upload_partitions**: Select the file for burning. To modify the burning settings for a specific file, click ![en-us_image_0000001333642545](figures/en-us_image_0000001333642545.png) next to the file.

   ![en-us_image_0000001345770181](figures/en-us_image_0000001345770181.png)

6. Choose **PROJECT TASKS** > **hi3861** > **Upload** to start burning.

   ![en-us_image_0000001333322693](figures/en-us_image_0000001333322693.png)

7. When the following information is displayed, press the RST key on the development board within 15 seconds to restart it.

   ![hi3861-upload-restart](figures/hi3861-upload-restart.png)

   Wait until the burning is complete. When the following message is displayed, the burning is successful.

   ![en-us_image_0000001281002722](figures/en-us_image_0000001281002722.png)
