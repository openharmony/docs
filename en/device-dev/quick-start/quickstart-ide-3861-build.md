# Building Source Code


With DevEco Device Tool, you can easily build source code of the Hi3861V100 development board, thanks to its productivity-boosting features, such as the compiler toolchain, detection of the build environment dependencies, and one-click installation of the dependencies.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> The build environment of Hi3861V100 is Ubuntu.


1. Click **Project Settings** on the menu bar to access the Hi3861V100 project configuration page.

   ![en-us_image_0000001275483042](figures/en-us_image_0000001275483042.png)

2. On the **Tool Chain** tab page, DevEco Device Tool automatically checks whether the dependent compiler toolchain is complete.

   - If any tool is indicated as **uninstalled** (![status_uninstall](figures/status_uninstall.png)), click **Download Uninstalled Tools** to install all the required tools, or click **Download** next to a tool to install the specific tool.
   - If some tool types are missing, click **Add Utility** to add them.
   - If **Download** is not available for a missing tool, it is not cataloged in DevEco Device Tool. In this case, you need to download the tool to the local host and click **Import** to import it.
   - If the status of **OpenHarmony Environment Dependency** is abnormal (![status_uninstall](figures/status_uninstall.png), click **Install**.

   ![en-us_image_0000001333256741](figures/en-us_image_0000001333256741.png)

   Certain tools may require the root access to install. For these tools, enter the user password in the **TERMINAL** window as prompted.

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > - If pip fails to be installed, [change the Python source](https://device.harmonyos.com/en/docs/documentation/guide/ide-set-python-source-0000001227639986) and try again.
   > - If APT fails to be installed, [change the APT source](https://device.harmonyos.com/en/docs/documentation/guide/faq-toolchain-install-0000001301623822) and try again.

   ![en-us_image_0000001280938208](figures/en-us_image_0000001280938208.png)

   After the installation is complete, the status of the tools and environment dependencies is displayed as ![status_install](figures/status_install.png).

3. On the **wifiiot_hispark_pegasus** tab page, set **build_type**, whose default value is **debug**.

   ![en-us_image_0000001333581089](figures/en-us_image_0000001333581089.png)

4. Choose **PROJECT TASKS** > **wifiiot_hispark_pegasus** > **Build** to start building.

   ![en-us_image_0000001281221352](figures/en-us_image_0000001281221352.png)

5. Wait until **SUCCESS** is displayed in the **TERMINAL** window, indicating that the build is complete.

   ![en-us_image_0000001405938781](figures/en-us_image_0000001405938781.png)

   After the building is complete, go to the **out** directory of the project to view the generated files, which are needed for [burning an image](quickstart-ide-3861-burn.md).
