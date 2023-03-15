# Building Source Code


With DevEco Device Tool, you can easily build source code of the Hi3861V100 development board, thanks to its productivity-boosting features, such as the compiler toolchain, detection of the build environment dependencies, and one-click installation of the dependencies.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> The build environment of Hi3861V100 is Ubuntu.


1. Click **Project Settings** on the menu bar to access the Hi3861V100 project configuration page.

   ![en-us_image_0000001275483042](figures/en-us_image_0000001275483042.png)

2. On the **Tool Chain** tab page, DevEco Device Tool automatically checks whether the dependent compiler toolchain is complete. If a message is displayed indicating that some tools are missing, click **Install** to automatically install the required tools.

   ![en-us_image_0000001333256741](figures/en-us_image_0000001333256741.png)

3. Install the toolchain related to Hi3861V100. Certain tools may require the root access to install. In this case, enter the user password in the **TERMINAL** window.
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > - If pip fails to be installed, [change the Python source](https://device.harmonyos.com/en/docs/documentation/guide/ide-set-python-source-0000001227639986) and try again.
   > - If APT fails to be installed, [change the APT source](https://device.harmonyos.com/en/docs/documentation/guide/faq-toolchain-install-0000001301623822) and try again.

   ![en-us_image_0000001280938208](figures/en-us_image_0000001280938208.png)

   After the toolchain is automatically installed, the figure below is displayed.

   ![en-us_image_0000001281378224](figures/en-us_image_0000001281378224.png)

4. On the **wifiiot_hispark_pegasus** tab page, set **build_type**, whose default value is **debug**.

   ![en-us_image_0000001333581089](figures/en-us_image_0000001333581089.png)

5. Choose **PROJECT TASKS** > **wifiiot_hispark_pegasus** > **Build** to start building.

   ![en-us_image_0000001281221352](figures/en-us_image_0000001281221352.png)

6. Wait until **SUCCESS** is displayed in the **TERMINAL** window, indicating that the build is complete.

   ![en-us_image_0000001405938781](figures/en-us_image_0000001405938781.png)

   After the building is complete, go to the **out** directory of the project to view the generated files, which are needed for [burning an image](quickstart-ide-3861-burn.md).
