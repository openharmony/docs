# Building Source Code


You can build source code with hb or the **build.sh** script. This topic describes how to build source code with hb. For details about how to use the **build.sh** script, see [Building Source Code Using the build.sh Script](quickstart-pkg-common-build.md).


For details about the functions of the OpenHarmony compilation and building module, see [Compilation and Building Guide](../subsystems/subsys-build-all.md).


## Prerequisites

- The [required libraries and tools](quickstart-pkg-install-package.md) have been installed.

- The [compilation tools](quickstart-pkg-install-tool.md) have been installed.

- The Hello World program is ready for use.

- The access to the Ubuntu environment is normal.


## Procedure

Go to the root directory of the source code in the Ubuntu environment and perform the following steps:

1. Set the build path.
   
   ```
   hb set
   ```

2. Select the current path.
   
   ```
   .
   ```

3. Select **rk3568** under **hihope** and press **Enter**.
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > When adapting the development board to a specific use case, select an appropriate build form factor, that is, **product** settings. For details, see [Build Form Factors](quickstart-appendix-compiledform.md).

     **Figure 1** RK3568 build settings 
  
   ![quickstart-standard-rk3568-build](figures/quickstart-standard-rk3568-build.png)

4. If you are building the source code into a 32-bit system, skip this step.
   
   If you are building the source code into a 64-bit system, run the following command:

   
   ```
   hb build --target-cpu arm64
   ```

5. Start building.
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

6. Check the build result. If "rk3568 build success" is displayed, the building is successful.
   > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **NOTICE**
   >
   > The build result and log files are stored in **out/rk3568**.
