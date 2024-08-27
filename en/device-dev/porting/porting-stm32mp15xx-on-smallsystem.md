# Small System STM32MP1 SoC Porting Case

This document describes how to port small development boards with screens based on the [BearPi-HM Micro development board](https://gitee.com/openharmony/device_board_bearpi) of the `STM32MP157` SoC from STMicroelectronics, so as to adapt components such as `ace_engine_lite`, `arkui_ui_lite`, `aafwk_lite`, `appexecfwk_lite`, and `HDF` to the `OpenHarmony LiteOS-A` kernel. The porting architecture uses the solution where `Board` and `SoC` are separated.

## Compilation and Building

### Directory Planning

This solution designs the directory structure using the [board and SoC decoupling idea](https://gitee.com/openharmony-sig/sig-content/blob/master/devboard/docs/board-soc-arch-design.md), and plans the SoC adaptation directory as follows:

```
device
├── board                               --- Board vendor directory
│   └── bearpi                          --- Board vendor: BearPi
│       └── bearpi_hm_micro             --- Board name: bearpi_hm_micro
└── soc                                 --- SoC vendor directory
    └── common                          --- Directory storing common HDF drivers.
    └── st                              --- SoC vendor: STMicroelectronics
        └── stm32mp1xx                  --- SoC series: stm32mp1xx
```

The planned product demo directory is as follows:

```
vendor
└── bearpi                              --- Vendor of the product demo, which is BearPi here
    └── bearpi_hm_micro                 --- Product name: bearpi_hm_micro development board
```

### Precompilation Adaptation

Before porting, you need to perform precompilation adaptation.

The precompilation adaptation process mainly uses the `hb set` command to set environment variables such as the project root directory, board directory, product directory, and board vendor name, to make preparations for compilation.

The procedure is as follows:

1. Add the `config.json` file to the `vendor/bearpi/bearpi_hm_micro` directory to describe board and kernel information used by the product demo. The sample code is as follows:

    ```
    {
      "product_name": "bearpi_hm_micro",    --- Product name displayed when the **hb set** command is used.
      "version": "3.0",                     --- Version of the system, which can be 1.0, 2.0, or 3.0.
      "type": "small",                      --- System type, which can be mini, small, or standard.
      "ohos_version": "OpenHarmony 3.0",    --- OpenHarmony system version.
      "device_company": "bearpi",           --- Board vendor name, which is used to find the /device/board/bearpi directory during compilation.
      "board": "bearpi_hm_micro",           --- Board name, which is used to find the /device/board/bearpi/bearpi_hm_micro directory during compilation.
      "kernel_type": "liteos_a",            --- Kernel type. OpenHarmony supports multiple kernels, and one board may adapt to multiple kernels. Therefore, you need to specify a kernel for compilation.
      "kernel_version": "",                 --- Kernel version. One board may adapt to multiple Linux kernel versions. Therefore, you need to specify a kernel version for compilation.
      "subsystems": [ ]                     --- Subsystem to be built.
    }
    ```

2. Add the `config.gni` file to the `device/board/bearpi/bearpi_hm_micro/liteos_a` directory to describe board and kernel information used by the product demo. The sample code is as follows:

    ```
    # Kernel type, e.g. "linux", "liteos_a", "liteos_m".
    kernel_type = "liteos_a"

    # Kernel version.
    kernel_version = ""

    # Board CPU type, e.g. "cortex-a7", "riscv32".
    board_cpu = "cortex-a7"

    # Board arch, e.g.  "armv7-a", "rv32imac".
    board_arch = ""

    # Toolchain name used for system compiling.
    # E.g. gcc-arm-none-eabi, arm-linux-harmonyeabi-gcc, ohos-clang,  riscv32-unknown-elf.
    # Note: The default toolchain is "ohos-clang". It's not mandatory if you use the default toolchain.
    board_toolchain = ""

    # The toolchain path installed, it's not mandatory if you have added toolchain path to your ~/.bashrc.
    board_toolchain_path = ""

    # Compiler prefix.
    board_toolchain_prefix = ""

    # Compiler type, "gcc" or "clang".
    board_toolchain_type = "clang"

    # Board related common compile flags.
    board_cflags = [
    "-mfloat-abi=softfp",
    "-mfpu=neon-vfpv4",
    ]
    board_cxx_flags = [
    "-mfloat-abi=softfp",
    "-mfpu=neon-vfpv4",
    ]
    board_ld_flags = []

    # Board related headfiles search path.
    board_include_dirs = []

    # Board adapter dir for OHOS components.
    board_adapter_dir = "//device/board/bearpi/bearpi_hm_micro/hal"

    # Sysroot path.
    board_configed_sysroot = ""

    # Board storage type, it used for file system generation.
    storage_type = "emmc"
    ```

3. Verify that the `hb set` configuration is correct. The `hb set` configuration is correct if the output information is as shown in the following figure.

   Run `hb set`, enter the project root directory, and press **Enter**. The `hb` command will traverse all `config.json` files in the `//vendor/<product_company>/<product_name>` directory and list all available product compilation options. In `config.json`, `product_name` is used to display the product name, and `device_company` and `board` are used to associate the `//device/board/<device_company>/<board>` directory and match the `<any_dir_name>/config.gni` file. If multiple files are matched, the board adapts to multiple kernels. Then, `kernel_type` and `kernel_version` in `config.json` can be used to uniquely match `kernel_type` and `kernel_version` in `config.gni`, thus determining the board with a kernel to be compiled.

    ![hb set](figures/bearpi_hm_micro_hb_set.png)

    After you select a product and press **Enter**, a **ohos_config.json** file will be generated in the root directory. The file will list the product information to be compiled. You can also run the `hb env` command to view the selected precompilation environment variables.

    ![hb env](figures/bearpi_hm_micro_hb_env.png)



## Kernel Porting

Kernel porting requires `LiteOS-A Kconfig` adaptation, `gn` compilation and building, and minimum kernel startup adaptation.

For details about the porting procedure, see [LiteOS-A kernel porting](porting-smallchip-kernel-a.md).
### Kconfig Adaptation
1. Add the chip, product name, and vendor name configurations to **//device/board/bearpi/bearpi_hm_micro/liteos_a/drivers/Kconfig**.
    ```
    source "../../device/soc/st/common/platform/Kconfig"

    config PLATFORM
        string
        default "stm32mp157"      if PLATFORM_STM32MP157

    config PRODUCT_NAME
        string "product name"
        default "bearpi_hm_micro" if PRODUCT_BEARPI_HM_MICRO

    config DEVICE_COMPANY
        string "vendor name"
        default "st" if PLATFORM_STM32MP157
        
    config TEE_ENABLE
        bool "Enable TEE"
        default n
        depends on  PLATFORM_STM32MP157
        help
            Enable teeos in platform
    ```
2. Add driver configurations to **//device/soc/st/common/platform/Kconfig**.
    ```
    config DRIVERS_MMC
        depends on DRIVERS
        bool "Enable MMC"
        default y
        depends on DRIVERS && FS_VFS
        help
        Answer Y to enable LiteOS support MMC driver.

    config DRIVERS_EMMC
        depends on DRIVERS_MMC && PLATFORM_STM32MP157 
        bool "Enable MMC0 support eMMC type"

    config DRIVERS_HI3881
        bool "Enable Hi3881 Host driver"
        default n
        depends on DRIVERS_HDF_WIFI
        help
            Answer Y to enable Hi3881 Host driver.
    config HW_RANDOM_ENABLE
            depends on DRIVERS_RANDOM 
            bool "Select hw random"
            default y
            help
            Answer Y to select hw random.
    ```
3. Enable related configurations in **//vendor/bearpi/bearpi_hm_micro/kernel_configs/debug_tee.config**.
    ```
    ...
    LOSCFG_PLATFORM="stm32mp157"
    LOSCFG_PRODUCT_NAME="bearpi_hm_micro"
    LOSCFG_DEVICE_COMPANY="st"
    # LOSCFG_PLATFORM_HI3516DV300 is not set
    # LOSCFG_PLATFORM_HI3518EV300 is not set
    # LOSCFG_PLATFORM_QEMU_ARM_VIRT_CA7 is not set
    LOSCFG_PLATFORM_STM32MP157=y
    LOSCFG_PRODUCT_BEARPI_HM_MICRO=y
    LOSCFG_BOARD_CONFIG_PATH="device/board/bearpi/bearpi_hm_micro/liteos_a/board"
    LOSCFG_TEE_ENABLE=y
    ...
    ```
### GN Build Adaptation
1. Create **BUILD.gn** in **//device/board/bearpi/bearpi_hm_micro/liteos_a** and add the following code. This module depends on **board**, **drivers**, and **hdf_config**.
    ```
    cmd = "if [ -f $product_path/hdf_config/BUILD.gn ]; then echo true; else echo false; fi"
    HAVE_PRODUCT_CONFIG =
        exec_script("//build/lite/run_shell_cmd.py", [ cmd ], "value")
    
    group("liteos_a") {
      deps = [
        "board",
        "drivers",
      ]
      if (HAVE_PRODUCT_CONFIG) {
        deps += [ "$product_path/hdf_config" ]
      } else {
        deps += [ "hdf_config" ]
      }
    }
    
    config("public") {
      configs = [
        "board:public",
        "drivers:public",
      ]
    }
    ```
2. Create **BUILD.gn** in **//device/board/bearpi/bearpi_hm_micro/liteos_a/board** and add the following code: Compile **os_adapt.c** kernel startup code into the system.
    ```
    import("//kernel/liteos_a/liteos.gni")
    
    module_name = "bsp_config"
    
    kernel_module(module_name) {
      sources = []
      if (defined(LOSCFG_PLATFORM_ADAPT)) {
        sources += [ "os_adapt/os_adapt.c" ]
      }
    }
    
    config("public") {
      include_dirs = [ "." ]
      include_dirs += [ "include" ]
      include_dirs += [ "$LITEOSTOPDIR/drivers/block/disk/include" ]
      include_dirs +=
          [ "$LITEOSTOPDIR/../../drivers/adapter/khdf/liteos/osal/include" ]
    }
    ```
3. Create **BUILD.gn** in **//device/board/bearpi/bearpi_hm_micro/liteos_a/drivers**, add the following code, and compile the HDF driver under **device/soc/st/common/platform** into the system:
    ```
    import("//drivers/adapter/khdf/liteos/hdf.gni")
    
    group("drivers") {
      public_deps = [ "//device/soc/st/common/platform:drivers" ]
    }
    
    config("public") {
      configs = [ "//device/soc/st/common/platform:public" ]
    }
    
    ```
4. Create **BUILD.gn** in **//vendor/bearpi/bearpi_hm_micro/hdf_config**, add the following code, and compile the HCS configuration file into the system:
    ```
    module_switch = defined(LOSCFG_DRIVERS_HDF) && !defined(LOSCFG_DRIVERS_HDF_TEST)
    module_name = "libhdf_config"
    hdf_driver(module_name) {
      hcs_sources = [ "hdf.hcs" ]
    }
    
    group("hdf_config") {
      public_deps = [ ":$module_name" ]
      deps = [
        "hdf_test",
        "hdf_test/hcs_macro_test",
      ]
    }
    ```
### Kernel Startup Adaptation
1. Add the following kernel startup code to **//device/board/bearpi/bearpi_hm_micro/liteos_a/board/os_adapt.c**. For details, see [LiteOS-A kernel porting](porting-smallchip-kernel-a.md).
    ```
    ...
    void SystemInit(void)
    {
    #ifdef LOSCFG_DRIVERS_RANDOM
        dprintf("dev random init ...\n");
        Mp1xxRngInit();
    #endif
    #ifdef LOSCFG_DRIVERS_MEM
        dprintf("mem dev init ...\n");
        extern int mem_dev_register(void);
        mem_dev_register();
    #endif

        dprintf("Date:%s.\n", __DATE__);
        dprintf("Time:%s.\n", __TIME__);

    #ifdef LOSCFG_DRIVERS_HDF
        dprintf("DeviceManagerStart start ...\n");
        if (DeviceManagerStart()) {
            PRINT_ERR("No drivers need load by hdf manager!");
        }
        dprintf("DeviceManagerStart end ...\n");
    #endif
        net_init();

    #ifdef LOSCFG_PLATFORM_ROOTFS
        dprintf("OsMountRootfs start ...\n");
        if (LOS_GetCmdLine()) {
            dprintf("get cmdline error!\n");
        }
        if (LOS_ParseBootargs()) {
            dprintf("parse bootargs error!\n");
        }
        if (OsMountRootfs()) {
            dprintf("mount rootfs error!\n");
        }
        dprintf("OsMountRootfs end ...\n");
    #endif

        dprintf("Before PLATFORM_UART ...\n");

    #ifdef LOSCFG_DRIVERS_HDF_PLATFORM_UART
        if (virtual_serial_init(TTY_DEVICE) != 0) {
            PRINT_ERR("virtual_serial_init failed");
        }
        if (system_console_init(SERIAL) != 0) {
            PRINT_ERR("system_console_init failed\n");
        }
    #endif

        dprintf("After PLATFORM_UART ...\n");

        if (OsUserInitProcess()) {
            PRINT_ERR("Create user init process failed!\n");
            return;
        }
        dprintf("cat log shell end\n");
        return;
    }
    ...
    ```


## Board-Level OS Porting

### Porting the HDF Driver for the SoC Platform

Driver adaptation files are stored in `device/soc/st/common/platform` and are loaded using the `HDF` mechanism. This section uses GPIO driver adaptation as an example.

1. Describe the building adaptation of the stm32mp1xx `gpio` driver in the `//device/soc/st/common/platform/gpio/BUILD.gn` file. The sample code is as follows:

    ```
    module_switch = defined(LOSCFG_DRIVERS_HDF_PLATFORM_GPIO)	 --- If the GPIO configuration switch of the HDF is enabled, the following is built:
    module_name = get_path_info(rebase_path("."), "name")
    
    hdf_driver("hdf_gpio") {
        sources = [ "stm32mp1_gpio.c" ]        --- GPIO driver source file
        include_dirs = [                       --- Dependent .h path
          "." ,
          "../stm32mp1xx_hal/STM32MP1xx_HAL_Driver/Inc",
        ]
    }
    ```

2. Describe the source code adaptation of the stm32mp1xx `gpio` driver in the `//device/soc/st/common/platform/gpio/stm32mp1_gpio.c` file. 
    First, load the basic driver adaptation framework based on the `HDF` driver framework of `OpenHarmony`, as shown below:

    ```
    struct HdfDriverEntry g_GpioDriverEntry = {
        .moduleVersion = 1,
        .moduleName = "HDF_PLATFORM_GPIO",
        .Bind = GpioDriverBind,
        .Init = GpioDriverInit,
        .Release = GpioDriverRelease,
    };
    HDF_INIT(g_GpioDriverEntry); 	 --- Load the GPIO driver using HDF_INIT.
    ```
3. Add the GPIO hardware description file **gpio_config.hcs** to **//device/soc/st/stm32mp1xx/sdk_liteos/hdf_config/gpio**, and add private configuration information of the driver to the file.
    ```
    root {
        platform {
            gpio_config {
                controller_0x50002000 {
                    match_attr = "st_stm32mp1_gpio";
                    groupNum = 11;
                    bitNum = 16;
                    gpioRegBase = 0x50002000;
                    gpioRegStep = 0x1000;
                    irqRegBase = 0x5000D000;
                    irqRegStep = 0x400;
                }
            }
        }
    }
    ```
4. Configure the product load driver. All device information of the product is defined in the source code file **//vendor/bearpi/bearpi_hm_micro/hdf_config/device_info/device_info.hcs**.

   Add the platform driver to the host of the platform.

   > **NOTE**
   >
   > **moduleName** must be the same as that defined in the driver file, and **deviceMatchAttr** must be the same as **match_attr** defined in the driver's private configuration information file **gpio_config.hcs**.


   ```
   root {
       ...
       platform :: host {
            device_gpio :: device {
                device0 :: deviceNode {
                    policy = 2;
                    priority = 10;
                    permission = 0644;
                    moduleName = "HDF_PLATFORM_GPIO_MANAGER";
                    serviceName = "HDF_PLATFORM_GPIO_MANAGER";
                }
                device1 :: deviceNode {
                    policy = 0;
                    priority = 10;
                    permission = 0644;
                    moduleName = "HDF_PLATFORM_GPIO";
                    serviceName = "HDF_PLATFORM_GPIO";
                    deviceMatchAttr = "st_stm32mp1_gpio";
                }
            }
       }
   }
   ```
5. Complete driver code. Configuration information in **gpio_config.hcs** will be loaded in **GpioDriverInit**.
    ```
    static int32_t GpioDriverInit(struct HdfDeviceObject *device)
    {
    
        int32_t ret;
        struct Mp1xxGpioCntlr *stm32gpio = &g_Mp1xxGpioCntlr;
    
        dprintf("%s: Enter", __func__);
        if (device == NULL || device->property == NULL) {
            HDF_LOGE("%s: device or property NULL!", __func__);
            return HDF_ERR_INVALID_OBJECT;
        }
        // Obtain property data.
        ret = Mp1xxGpioReadDrs(stm32gpio, device->property);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: get gpio device resource fail:%d", __func__, ret);
            return ret;
        }
        ...
    }
    ```

### OpenHarmony Subsystem Adaptation

To adapt `OpenHarmony` subsystems, you only need to add related subsystems and components to `config.json`, so that the components can be included in the compilation by the compilation system.

#### Startup Subsystem Adaptation

For the startup subsystem, adapt the `bootstrap_lite`, `syspara_lite`, `appspawn_lite`, and `init` components. Add the corresponding configuration items to the `vendor/bearpi/bearpi_hm_micro/config.json` file, as shown below:

```
    {
    "subsystem": "startup",
    "components": [
        { "component": "syspara_lite", "features":[] },
        { "component": "bootstrap_lite", "features":[] },
        { "component": "appspawn_lite", "features":[] },
        { "component": "init", "features":[] }
     ]
    },
```
The system will be started according to startup configurations in the **//vendor/bearpi/bearpi_hm_micro/init_configs** file.


#### DFX Subsystem Adaptation

To adapt the `DFX` subsystem, you need to add the `hilog_featured_lite` and `hidumper_lite` components to the `config.json` file.

```
    {
        "subsystem": "hiviewdfx",
        "components": [
            { "component": "hilog_featured_lite", "features":[] },
            { "component": "hidumper_lite", "features":[] }
        ]
    },
```

#### System Service Management Subsystem Adaptation

To adapt the system service management subsystem, you need to add the `samgr_lite`, `safwk_lite`, and `dmsfwk_lite` components to the `config.json` file.

```
    {
    "subsystem": "distributed_schedule",
    "components": [
        { "component": "samgr_lite", "features":[] },
        { "component": "safwk_lite", "features":[] },
        { "component": "dmsfwk_lite", "features":[] }
    ]
    },
```

#### Security Subsystem Adaptation

To adapt the security subsystem, you need to add the `permission_lite`, `appverify`, `device_auth`, and `huks` components to the `config.json` file.

```
    {
    "subsystem": "security",
    "components": [
        { "component": "permission_lite", "features":[] },
        { "component": "appverify", "features":[] },
        { "component": "device_auth", "features":[] },
        { "component": "huks", "features":
        [
            "huks_config_file = \"hks_config_small.h\""
        ]
        }
    ]
    },
```


#### utils Subsystem Adaptation

To adapt the utils subsystem, you need to add the `kv_store` and `os_dump` components to the `config.json` file.

```
      {
        "subsystem": "utils",
        "components": [
          { "component": "kv_store", "features":[] },
          { "component": "os_dump", "features":[] }
        ]
      },
```

#### Graphics Subsystem Adaptation

To adapt the graphics subsystem, you need to add the `graphic_utils` component to the `config.json` file.

```
      {
        "subsystem": "graphic",
        "components": [
          { "component": "graphic_utils",           
            "features": [ "enable_ohos_graphic_utils_product_config = true"
             ]
          },
          { "component": "graphic_hals", "features":[] },
          { "component": "ui", "features":[ "enable_graphic_font = true","enable_video_component=false"] },
          { "component": "surface", "features":[] },
          { "component": "wms", "features":[] }
        ]
      },
```

For details about `graphic` configuration, see `//vendor/bearpi/bearpi_hm_micro/graphic_config/product_graphic_lite_config.h`.


####  ArkUI Subsystem Adaptation

To adapt the  ArkUI subsystem, you need to add the `ace_engine_lite` component to the `config.json` file.

```
    {
        "subsystem": "arkui",
        "components": [
        {
            "component": "ace_engine_lite",
            "features": [
            "ace_engine_lite_feature_product_config = true"
            ]
        }
        ]
    },
```
For details about `ace_engine_lite` configuration, see `//vendor/bearpi/bearpi_hm_micro/ace_lite_config/product_acelite_config.h`.

#### aafwk Subsystem Adaptation

To adapt the aafwk subsystem, you need to add the `aafwk_lite` component to the `config.json` file.

```
    {
    "subsystem": "aafwk",
    "components": [
        {
        "component": "aafwk_lite",
        "features": [
            "ability_lite_enable_ohos_appexecfwk_feature_ability = true"	 --- The FA feature is supported, that is, the graphics capability is included.
        ]
        }
    ]
    },
```


#### appexecfwk Subsystem Adaptation

To adapt the appexecfwk subsystem, you need to add the `appexecfwk_lite` component to the `config.json` file.

```
    {
    "subsystem": "appexecfwk",
    "components": [
        {
        "component": "appexecfwk_lite"
        }
    ]
    },
```
