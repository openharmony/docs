# Building


1. In **Projects**, click **Settings**. The HH-SCDY200 configuration page is displayed.

   ![en-us_image_0000001221036768](figures/en-us_image_0000001221036768.png)

2. On the **toolchain** tab page, DevEco Device Tool automatically checks whether the dependent compilation toolchain is complete. If a message is displayed indicating that some tools are missing, click **SetUp** to automatically install the required tools.

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > If the pip component fails to be installed, [change the Python](https://device.harmonyos.com/en/docs/documentation/guide/ide-set-python-source-0000001227639986) source and try again.

   ![en-us_image_0000001221356692](figures/en-us_image_0000001221356692.png)

   After the toolchain is automatically installed, the figure below is displayed.

   ![en-us_image_0000001265676877](figures/en-us_image_0000001265676877.png)

3. On the **hh_scdy200** tab page, set **build_type**. The default value is **debug**. Click **Save** to save the settings.

   ![en-us_image_0000001265956897](figures/en-us_image_0000001265956897.png)

4. Choose **PROJECT TASKS** > **hi3861** > **Build** to start building.

   ![en-us_image_0000001265516901](figures/en-us_image_0000001265516901.png)

5. Wait until **SUCCESS** is displayed in the **TERMINAL** window, indicating that the compilation is complete.

   ![en-us_image_0000001222361042](figures/en-us_image_0000001222361042.png)

   After the building is complete, go to the out directory of the project to view the generated files, which are needed in [burning](https://device.harmonyos.com/en/docs/documentation/guide/ide-rk3568-upload-0000001239220669).
