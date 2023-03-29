# OpenHarmony开发板Patch使用指导

1. 合入HDF补丁。
   按照[kernel.mk](https://gitee.com/openharmony/kernel_linux_build/blob/master/kernel.mk)中HDF的补丁合入方法，合入不同内核版本对应的HDF内核补丁：
   ```makefile
   $(OHOS_BUILD_HOME)/drivers/hdf_core/adapter/khdf/linux/patch_hdf.sh $(OHOS_BUILD_HOME) $(KERNEL_SRC_TMP_PATH) $(KERNEL_PATCH_PATH) $(DEVICE_NAME)
   ```

2. 合入芯片平台驱动补丁，以Hi3516DV300为例。
   按照[kernel.mk](https://gitee.com/openharmony/kernel_linux_build/blob/master/kernel.mk)中的芯片组件所对应的patch路径规则及命名规则，将对应的芯片组件patch放到对应路径下：
   ```makefile
   DEVICE_PATCH_DIR := $(OHOS_BUILD_HOME)/kernel/linux/patches/${KERNEL_VERSION}/$(DEVICE_NAME)_patch
   DEVICE_PATCH_FILE := $(DEVICE_PATCH_DIR)/$(DEVICE_NAME).patch
   ```

3. 修改自己所需要编译的config。
   按照[kernel.mk](https://gitee.com/openharmony/kernel_linux_build/blob/master/kernel.mk)中的芯片组件所对应的patch路径规则及命名规则，将对应的芯片组件config放到对应路径下：
   ```makefile
   KERNEL_CONFIG_PATH := $(OHOS_BUILD_HOME)/kernel/linux/config/${KERNEL_VERSION}
   DEFCONFIG_FILE := $(DEVICE_NAME)_$(BUILD_TYPE)_defconfig
   ```

   > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
   > 由于OpenHarmony工程的编译构建流程中会拷贝kernel/linux/linux-\*.\*的代码环境后进行打补丁动作，在使用OpenHarmony的版本级编译命令前，需要kernel/linux/linux-\*.\*原代码环境。
   > 
   > 根据不同系统工程，编译完成后会在out目录下的kernel目录中生成对应实际编译的内核，基于此目录的内核，进行对应平台的config修改，将最后生成的.config文件cp到config仓对应平台的路径文件里，即可生效。
