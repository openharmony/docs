# Running


## Starting the System

After burning is completed, you need to configure the bootloader to run the OpenHarmony system.

1. In the Hi3516D V300 task, click **Configure bootloader (Boot OS)** to configure the bootloader.

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > The bootloader configuration in DevEco Device Tool has been adapted to Hi3516D V300. Therefore, no manual modification is needed.

   ![en-us_image_0000001226794644](figures/en-us_image_0000001226794644.png)

2. When the message shown below is displayed, restart the development board. If "SUCCESS" is displayed, it indicates that the configuration is successful.

   ![en-us_image_0000001227114584](figures/en-us_image_0000001227114584.png)

3. Click **Monitor** on the taskbar to start the serial port tool.

   ![en-us_image_0000001271234705](figures/en-us_image_0000001271234705.png)

4. When the command output is displayed, press **Enter** until **OHOS #** is displayed, indicating that the system is started successfully.

   ![en-us_image_0000001271594709](figures/en-us_image_0000001271594709.png)


## Running a Hello World Program

After the system is started, perform the following steps to run the Hello World program:

1. Go to the **bin** directory on the startup page.
   
   ```
   cd bin
   ```

2. Run the following command to run the **helloworld** program:
   
   ```
   ./helloworld
   ```

   If the message "Hello World!" is displayed, the program runs successfully.

   ![en-us_image_0000001271354693](figures/en-us_image_0000001271354693.png)


## Next

Congratulations! You have finished all steps! Proceed to [develop a sample camera with a screen](../guide/device-camera-control-overview.md) to better familiarize yourself with OpenHarmony development.
