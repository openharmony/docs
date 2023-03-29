# Applying Patches on Development Boards

1. Apply HDF patches.
   Apply the HDF patches based on the kernel version. For details, see [kernel.mk](https://gitee.com/openharmony/kernel_linux_build/blob/master/kernel.mk).
   ```makefile
   $(OHOS_BUILD_HOME)/drivers/hdf_core/adapter/khdf/linux/patch_hdf.sh $(OHOS_BUILD_HOME) $(KERNEL_SRC_TMP_PATH) $(KERNEL_PATCH_PATH) $(DEVICE_NAME)
   ```

2. Apply the chip driver patch. The following uses Hi3516D V300 as an example.
   Place the chip component patches in the related directory. For details about the patch directory and naming rules, see [kernel.mk](https://gitee.com/openharmony/kernel_linux_build/blob/master/kernel.mk).
   ```makefile
   DEVICE_PATCH_DIR := $(OHOS_BUILD_HOME)/kernel/linux/patches/${KERNEL_VERSION}/$(DEVICE_NAME)_patch
   DEVICE_PATCH_FILE := $(DEVICE_PATCH_DIR)/$(DEVICE_NAME).patch
   ```

3. Modify the **config** file to build.
   Place the chip component **config** in the related directory. For details about the patch directory and naming rules, see [kernel.mk](https://gitee.com/openharmony/kernel_linux_build/blob/master/kernel.mk).
   ```makefile
   KERNEL_CONFIG_PATH := $(OHOS_BUILD_HOME)/kernel/linux/config/${KERNEL_VERSION}
   DEFCONFIG_FILE := $(DEVICE_NAME)_$(BUILD_TYPE)_defconfig
   ```

   > **NOTICE**<br>
   > In the OpenHarmony project build process, patches are installed after "kernel/linux/linux-\*.\*" is copied. Before using the version-level build command of OpenHarmony, ensure that the "kernel/linux/linux-\*.\*" source code is available.
   > 
   > After the build is complete, the kernel is generated in the kernel directory in the **out** directory. Modify the **config** file for the target platform based on the kernel generated, and copy the generated **.config** file to the corresponding path of the platform in the **config** repository. Then, the configuration takes effect.
