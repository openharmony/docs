# Applying Patches on OpenHarmony Development Boards<a name="EN-US_TOPIC_0000001081980461"></a>

1. Apply HDF patches.

	Apply the HDF kernel patches matching your kernel version. For details, see the method in **kernel.mk** in the **kernel/linux/build** repository.
	
	```
	$(OHOS_BUILD_HOME)/drivers/adapter/khdf/linux/patch_hdf.sh $(OHOS_BUILD_HOME) $(KERNEL_SRC_TMP_PATH) $(HDF_PATCH_FILE)
	```

2. Apply the chip driver patches.

	The following uses Hi3516D V300 as an example.
	
	Place the patches for the chip component in the corresponding path based on the path and naming rules for the patches of the chip component in **kernel.mk** in the **kernel/linux/build** repository.
	
	```
	DEVICE_PATCH_DIR := $(OHOS_BUILD_HOME)/kernel/linux/patches/${KERNEL_VERSION}/$(DEVICE_NAME)_patch
	DEVICE_PATCH_FILE := $(DEVICE_PATCH_DIR)/$(DEVICE_NAME).patch
	```

3. Modify the **config** file to build.

	Place the **config** file for the chip component in the corresponding path based on the path and naming rules of the chip component in **kernel.mk** in the **kernel/linux/build** repository.
	
	```
	KERNEL_CONFIG_PATH := $(OHOS_BUILD_HOME)/kernel/linux/config/${KERNEL_VERSION}
	DEFCONFIG_FILE := $(DEVICE_NAME)_$(BUILD_TYPE)_defconfig
	```

	> **Note**:
	>
	>In the OpenHarmony project build process, patches are installed after **kernel/linux/linux-\*\.\*** is copied. Before using the version-level build command of OpenHarmony, ensure that the **kernel/linux/linux-\*\.\*** source code is available.
	>
	>The kernel built is generated in the **kernel** directory under the **out** directory. Modify the **config** file based on the kernel built, and copy the generated **.config** file to the corresponding path in the **config** repository. Then, the configuration takes effect.
