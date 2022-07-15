# Applying Patches on Development Boards

1.  Apply the HDF patches.

    Apply the HDF patches based on the kernel version in the  **kernel/linux/build**  repository. For details, see the method for applying the HDF patch in  **kernel.mk**.

    ```
    $(OHOS_BUILD_HOME)/drivers/hdf_core/adapter/khdf/linux/patch_hdf.sh $(OHOS_BUILD_HOME) $(KERNEL_SRC_TMP_PATH) $(KERNEL_PATCH_PATH) $(DEVICE_NAME)
    ```

2.  Apply the chip driver patches.

    The following uses Hi3516D V300 as an example:

    In the  **kernel/linux/build**  repository, place the chip module patches in the corresponding path based on the patch path and naming rules for the chip module in  **kernel.mk**.

    ```
    DEVICE_PATCH_DIR := $(OHOS_BUILD_HOME)/kernel/linux/patches/${KERNEL_VERSION}/$(DEVICE_NAME)_patch
    DEVICE_PATCH_FILE := $(DEVICE_PATCH_DIR)/$(DEVICE_NAME).patch
    ```

    ```

    ```

3.  Modify the  **config**  file to be built.

    In the  **kernel/linux/build**  repository, place the chip module  **config**  file in the corresponding path based on the file path and naming rules for the chip module in  **kernel.mk**.

    ```
    KERNEL_CONFIG_PATH := $(OHOS_BUILD_HOME)/kernel/linux/config/${KERNEL_VERSION}
    DEFCONFIG_FILE := $(DEVICE_NAME)_$(BUILD_TYPE)_defconfig
    ```

    >![](../public_sys-resources/icon-notice.gif) **NOTICE**<br/> 
    >In the OpenHarmony project build process, patches are applied after the code environment of  **kernel/linux/linux-\*.\***  is copied. Before running the OpenHarmony version-level build command, ensure that the source code environment of  **kernel/linux/linux-\*.\***  is available.
    >After the build is complete, the kernel is generated in the kernel directory in the  **out**  directory. Modify the  **config**  file based on the kernel generated, and copy the generated  **.config**  file to the corresponding path in the  **config**  repository. Then, the configuration takes effect.


