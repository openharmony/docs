# Compilation and Building Guidelines<a name="EN-US_TOPIC_0000001060378721"></a>

-   [Prerequisites](#section13333171022312)
-   [How to Use the hb Command Line Tool](#section477242204612)
-   [Adding a Module](#section4207112818418)
-   [Adding a Chipset Solution](#section2737141421917)
-   [Adding a Product Solution](#section720881917199)

## Prerequisites<a name="section13333171022312"></a>

Ensure that the development environment has GN, Ninja, Python 3.7.4 or later, and hb commands. For details about installation methods, see  [Basic OS Environment Setup](../quick-start/environment-setup.md).

## How to Use the hb Command Line Tool<a name="section477242204612"></a>

hb is a command line tool for OpenHarmony to execute build commands. Common hb commands are described as follows:

1.  **hb set**

    ```
    hb set -h
    usage: hb set [-h] [-root [ROOT_PATH]] [-p]
    
    optional arguments:
      -h, --help            show this help message and exit
      -root [ROOT_PATH], --root_path [ROOT_PATH]
                            Set OHOS root path
      -p, --product         Set OHOS board and kernel
    ```

    -   If you run  **hb set**  with no argument, the default setting process starts.
    -   You can run  **hb set -root** _dir_  to set the root directory of the source code.
    -   **hb set -p**  is used to set the product to build.

2.  **hb env**

    View the current configuration.

    ```
    hb env
    [OHOS INFO] root path: xxx
    [OHOS INFO] board: hispark_taurus
    [OHOS INFO] kernel: liteos
    [OHOS INFO] product: ipcamera
    [OHOS INFO] product path: xxx/vendor/hisilicon/ipcamera
    [OHOS INFO] device path: xxx/device/hisilicon/hispark_taurus/sdk_linux_4.19
    ```

3.  **hb build**

    ```
    hb build -h
    usage: hb build [-h] [-b BUILD_TYPE] [-c COMPILER] [-t [TEST [TEST ...]]]
                    [--dmverity] [-p PRODUCT] [-f] [-n]
                    [component [component ...]]
    
    positional arguments:
      component             name of the component
    
    optional arguments:
      -h, --help            show this help message and exit
      -b BUILD_TYPE, --build_type BUILD_TYPE
                            release or debug version
      -t [TEST [TEST ...]], --test [TEST [TEST ...]]
                            compile test suit
      --dmverity            Enable dmverity
      -p PRODUCT, --product PRODUCT
                            build a specified product with
                            {product_name}@{company}, eg: ipcamera@hisilcon
      -f, --full            full code compilation
      -T [TARGET [TARGET ...]], --target [TARGET [TARGET ...]]
                            Compile single target
    ```

    -   If you run  **hb build**  with no argument, the previously configured code directory, product, and options are used for the build. The  **-f**  option will delete all products to be built, which is equivalent to running  **hb clean**  and  **hb build**.
    -   You can run  **hb build** _\{module\_name\}_  to build product modules separately based on the development board and kernel set for the product, for example,  **hb build kv\_store**.
    -   You can run  **hb build -p ipcamera@hisilicon**  to skip the setting step and compile the product directly.
    -   You can run  **hb build**  in  **device/device\_company/board**  to select the kernel and start the build based on the current development board and the selected kernel to generate an image that contains the kernel and driver only.

4.  **hb clean**

    Clear the build result of the product in the  **out**  directory, and retain the  **args.gn**  and  **build.log**  files only. To clear files in a specified directory, add the directory parameter to the command, for example,  **hb clean out/xxx/xxx**.

    ```
    hb clean
    usage: hb clean [-h] [out_path]
    
    positional arguments:
      out_path    clean a specified path.
    
    optional arguments:
      -h, --help  show this help message and exit
    ```


## Adding a Module<a name="section4207112818418"></a>

To add a module, determine the subsystem to which the module belongs and the module name, and then perform the following steps:

1.  Add the module build script after the source code development is complete.

    The following example adds the  **BUILD.gn**  script \(stored in the  **applications/sample/hello\_world**  directory\) to build the  **hello\_world**  module \(as an executable file\).

    ```
    executable("hello_world") {
      include_dirs = [
        "include",
       ]
      sources = [
        "src/hello_world.c"
      ]
    }
    ```

    The added script is used to build  **hello\_world**  that can run on OpenHarmony.

    To build the preceding module separately, select a product via the  **hb set**  command and run the  **-T**  command.

    ```
    hb build -f -T //applications/sample/hello_world
    ```

    After the module functions are verified based on the development board, perform steps 2 to 5 to configure the module for the product.

2.  Add the module description.

    The module description is stored in the  **build/lite/components**  directory. New modules must be added to the JSON file of the corresponding subsystem. A module description must contain the following fields:

    -   **module**: name of the module
    -   **description**: brief description of the module
    -   **optional**: whether the module is optional
    -   **dirs**: source code directory of the module
    -   **targets**: module build entry

    For example, to add the  **hello\_world**  module to the application subsystem, add the  **hello\_world**  object to the  **applications.json**  file.

    ```
    {
      "components": [
        {
          "component": "hello_world",
          "description": "Hello world.",
          "optional": "true",
          "dirs": [
            "applications/sample/hello_world"
          ],
          "targets": [
            "//applications/sample/hello_world"
          ]
        },
        ...
       ]
    }
    ```

3.  Configure the module for the product.

    The  **config.json**  file is stored in the  **vendor/company/product/**  directory. The file must contain the product name, OpenHarmony version, device vendor, development board, kernel type, kernel version, and the subsystem and module to configure. The following example adds the  **hello\_world**  module to the  **my\_product.json**  configuration file:

    ```
    {
        "product_name": "hello_world_test",
        "ohos_version": "OpenHarmony 1.0",
        "device_company": "hisilicon",
        "board": "hispark_taurus",
        "kernel_type": "liteos_a",
        "kernel_version": "1.0.0",
        "subsystems": [
          {
            "subsystem": "applications",
            "components": [
              { "component": "hello_world", "features":[] }
            ]
          },
          ...
        ]
    }
    ```

4.  Build the product.

    1. Run the  **hb set**  command in the root code directory to select the corresponding product.

    2. Run the  **hb build**  command.


## Adding a Chipset Solution<a name="section2737141421917"></a>

The Compilation and Building subsystem allows you to add a chipset solution. Detailed operations are as follows:

1.  Create a directory for the chipset solution.

    Taking the RTL8720 development board of chipset provider Realtek for example, you need to run the following command in the root code directory to create a directory for the chipset solution based on  [1-Configuration Rules for Modules, Chipset Solutions, and Product Solutions](compilation-and-building-overview.md#section1625463413327).

    ```
    mkdir -p device/realtek/rtl8720
    ```

2.  Create a directory for kernel adaptation and build the  **config.gni**  file of the development board.

    The following example adapts the LiteOS Cortex-M kernel to the RTL8720 development board of Realtek. The  **device/realtek/rtl8720/liteos\_a/config.gni**  file is configured as follows:

    ```
    # Kernel type, e.g. "linux", "liteos_a", "liteos_m".
    kernel_type = "liteos_a"
    
    # Kernel version.
    kernel_version = "3.0.0"
    
    # Board CPU type, e.g. "cortex-a7", "riscv32".
    board_cpu = "real-m300"
    
    # Board arch, e.g. "armv7-a", "rv32imac".
    board_arch = ""
    
    # Toolchain name used for system compiling.
    # E.g. gcc-arm-none-eabi, arm-linux-harmonyeabi-gcc, ohos-clang, riscv32-unknown-elf.
    # Note: The default toolchain is "ohos-clang". It's not mandatory if you use the default toochain.
    board_toolchain = "gcc-arm-none-eabi"
    
    # The toolchain path instatlled, it's not mandatory if you have added toolchian path to your ~/.bashrc.
    board_toolchain_path =
        rebase_path("//prebuilts/gcc/linux-x86/arm/gcc-arm-none-eabi/bin",
                    root_build_dir)
    
    # Compiler prefix.
    board_toolchain_prefix = "gcc-arm-none-eabi-"
    
    # Compiler type, "gcc" or "clang".
    board_toolchain_type = "gcc"
    
    # Board related common compile flags.
    board_cflags = []
    board_cxx_flags = []
    board_ld_flags = []
    ```

3.  Build the script.

    Create the  **BUILD.gn**  file in the development board directory. The target name must be the same as that of the development board. Taking the RTL8720 development board of Realtek as an example, the content in the  **device/realtek/rtl8720/BUILD.gn**  file is configured as follows:

    ```
    group("rtl8720") { # The target can be shared_library, static_library, or an executable file.
      # Content
      ......
    }
    ```

4.  Build the chipset solution.

    Run the  **hb build**  command in the development board directory to start the build.


## Adding a Product Solution<a name="section720881917199"></a>

The Compilation and Building subsystem supports flexible assembly of chipset solutions and modules to customize desired product solutions. The operation procedure is as follows:

1.  Create a product directory.

    Taking the Wi-Fi IoT module based on the RTL8720 development board as an example, you need to run the following command in the root code directory to create a product directory based on  [1-Configuration Rules for Modules, Chipset Solutions, and Product Solutions](compilation-and-building-overview.md#section1625463413327).

    ```
    mkdir -p vendor/my_company/wifiiot
    ```

2.  Assemble the product.

    Create the  **config.json**  file in the product directory. Taking the Wi-Fi IoT module as an example, the  **vendor/my\_company/wifiiot/config.json**  file is as follows:

    ```
    {
        "product_name": "wifiiot",                        # Product name
        "ohos_version": "OpenHarmony 1.0",                # In-use OS version
        "device_company": "realtek",                      # Name of the chipset solution vendor
        "board": "rtl8720",                               # Name of the development board
        "kernel_type": "liteos_m",                        # Selected kernel type
        "kernel_version": "3.0.0",                        # Selected kernel version
        "subsystems": [                            
          {
            "subsystem": "kernel",                        # Selected subsystem
            "components": [
              { "component": "liteos_m", "features":[] }  # Selected module and its features
            ]
          },
          ...
          {
             More subsystems and modules
          }
        ]
    }
    ```

    Before the build, the Compilation and Building subsystem will check the validity of fields, including  **device\_company**,  **board**,  **kernel\_type**,  **kernel\_version**,  **subsystem**, and  **component**. The first four fields and the latter two fields must match the current chipset solution and the module description in the  **build/lite/components**  file, respectively.

3.  Implement adaptation of OS APIs.

    Create the  **hals**  directory in the product directory and store the source code as well as the build script for OS adaptation in this directory.

4.  Configure the system service.

    Create the  **init\_configs**  directory in the product directory and then the  **init.cfg**  file in the newly created directory. You can configure the system service to be started on demand.

5.  Configure the init process \(only for the Linux kernel\).

    You need to create the  **etc**  directory in the  **init\_configs**  directory, and then the  **init.d**  folder as well as the  **fstab**  file in the newly created directory. In addition, you need to create the  **rcS**  and  **Sxxx**  files in the  **init.d**  file and edit them based on product requirements.

6.  Configure the file system image \(required only for the development board that supports the file system\).

    Create the  **fs.yml**  file in the product directory and configure it as required. A typical  **fs.yml**  file is configured as follows:

    ```
    -
      fs_dir_name: rootfs # Image name
      fs_dirs:
        -
          # Copy the files in the out/my_board/my_product/bin directory to the rootfs/bin directory and ignore the .bin files related to testing.
          source_dir: bin
          target_dir: bin
          ignore_files:
            - Test.bin
            - TestSuite.bin
        -
          # Copy the files in the out/my_board/my_product/libs directory to the rootfs/lib directory, ignore all .a files, and set the permissions on the files and folders to 644 and 755, respectively.
          source_dir: libs
          target_dir: lib
          ignore_files:
            - .a
          dir_mode: 755
          file_mode: 644
        -
          source_dir: usr/lib
          target_dir: usr/lib
          ignore_files:
            - .a
          dir_mode: 755
          file_mode: 644
        -
          source_dir: config
          target_dir: etc
        -
          source_dir: system
          target_dir: system
        -
          source_dir: sbin
          target_dir: sbin
        -
          source_dir: usr/bin
          target_dir: usr/bin
        -
          source_dir: usr/sbin
          target_dir: usr/sbin
        -
          # Create an empty proc directory.
          target_dir: proc
        -
          target_dir: mnt
        -
          target_dir: opt
        -
          target_dir: tmp
        -
          target_dir: var
        -
          target_dir: sys
        -
          source_dir: etc
          target_dir: etc
        -
          source_dir: vendor
          target_dir: vendor
        -
          target_dir: storage
    
      fs_filemode:
        -
          file_dir: lib/ld-uClibc-0.9.33.2.so
          file_mode: 555
        -
          file_dir: lib/ld-2.24.so
          file_mode: 555
        -
          file_dir: etc/init.cfg
          file_mode: 400
      fs_symlink:
        -
          # Create the soft link ld-musl-arm.so.1 -> libc.so in the rootfs/lib directory.
          source: libc.so
          link_name: ${fs_dir}/lib/ld-musl-arm.so.1
        -
          source: mksh
          link_name: ${fs_dir}/bin/sh
        -
          source: mksh
          link_name: ${fs_dir}/bin/shell
      fs_make_cmd:
        # Create an ext4 image for the rootfs directory using the script.
        - ${root_path}/build/lite/make_rootfs/rootfsimg_linux.sh ${fs_dir} ext4
    -
      fs_dir_name: userfs
      fs_dirs:
        -
          source_dir: storage/etc
          target_dir: etc
        -
          source_dir: data
          target_dir: data
      fs_make_cmd:
        - ${root_path}/build/lite/make_rootfs/rootfsimg_linux.sh ${fs_dir} ext4
    ```

7.  Build the script.

    Create the  **BUILD.gn**  file in the product directory and build the script based on your requirements. Taking the Wi-Fi IoT module in step 1 as an example, the  **BUILD.gn**  is configured as follows:

    ```
    group("wifiiot") { # The target name must be the same as the product name.
      deps = []
      # Copy the init configuration.
      deps += [ "init_configs" ]
      # Build the hals directory.
      deps += [ "hals" ]
      # Others
      ......
    }
    ```

8.  Build the product.

    Run the  **hb set**  command in the root code directory to select the new product as prompted, and then run the  **hb build**  command to start the build.


