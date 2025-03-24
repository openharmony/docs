# Building Source Code


For details about the functions of the OpenHarmony compilation and building module, see [Compilation and Building Guide](../subsystems/subsys-build-all.md).


## Prerequisites

- The [required libraries and tools](quickstart-pkg-install-package.md) have been installed.

- The [compilation tools](quickstart-pkg-install-tool.md) have been installed.

- The [tools specially required by Hi3861](quickstart-pkg-3861-tool.md) have been installed.

- The Hello World program is ready for use.

- The access to the Ubuntu environment is normal.


## Procedure

Method 1: using hb for compilation (install [compilation tools](quickstart-pkg-install-tool.md) first)

Go to the root directory of the source code in the Ubuntu environment and perform the following steps:

1. Set the build path.
   
   ```
   hb set
   ```

2. Select the current path.
   
   ```
   .
   ```

3. Select **wifiiot_hispark_pegasus** under **hisilicon** and press **Enter**.
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > When adapting the development board to a specific use case, select an appropriate build form factor, that is, **product** settings. For details, see [Build Form Factors](quickstart-appendix-compiledform.md).

   **Figure 1** Hi3861 build settings 

   ![quickstart-lite-3861-build](figures/quickstart-lite-3861-build.png)

4. Start building.
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > - To build a component (for example, **hello**), run the **hb build -T *targetName*** command.
   > 
   > - To build a product incrementally, run the **hb build** command.
   > 
   > - To build a product from the scratch, run the **hb build -f** command.
   > 
   > This example builds a product from the scratch.

   
   ```
   hb build -f
   ```

5. Check the build result. If "build success" is displayed, the building is successful.
   > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **NOTICE**
   >
   > The build result and log files are stored in **out/hispark_pegasus/wifiiot_hispark_pegasus**.

Method 2: using the **build.sh** script for compilation

For details, see [Building Source Code Using the build.sh Script](quickstart-pkg-common-build.md).