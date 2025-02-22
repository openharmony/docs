# Building Source Code Using the build.sh Script


1. Go to the root directory of the source code and run the build command.
   
   > For x86 systems:
   
   ```
   ./build.sh --product-name {product_name} --ccache
   ```

   > For Arm systems:
   
   ```
   ./build.sh --product-name {product_name} --ccache --target-cpu arm64 
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > In the preceding command, *product-name* indicates the product name, for example, **Hi3516DV300** and **rk3568**.
   
2. Check the build result. If the build is successful, the following information is displayed in the log:
   
   ```
   post_process
   =====build name successful.
   ```

   Files generated during the build are stored in the **out/{*device_name*}/** directory, and the generated image is stored in the **out/{*device_name*}/packages/phone/images/** directory.
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > For details about other modular compilation operations, see [Compilation and Building Guide](../subsystems/subsys-build-all.md).
