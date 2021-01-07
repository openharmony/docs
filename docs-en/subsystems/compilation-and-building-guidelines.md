# Compilation and Building Guidelines<a name="EN-US_TOPIC_0000001060378721"></a>

-   [Directory Structure](#section56731811102915)
-   [Compilation Commands](#section1475192018291)
-   [How to Develop](#section4207112818418)

## Directory Structure<a name="section56731811102915"></a>

```
build/lite                          # Primary directory for compilation and building
├── config                       # Compilation configuration items
│   ├── boards                  # Declaration of development board–related variables, including its name, target architecture, and target CPU
│   ├── component               # Definition of templates related to OpenHarmony components, including static libraries, dynamic libraries, extension components, and emulator libraries
│   ├── kernel                  # Compilation variable declaration and configuration parameters for the OpenHarmony kernel
│   └── subsystem               # OpenHarmony subsystem list
├── ndk                          # NDK-related compilation scripts and configuration parameters
├── platform                     # Platform-related configuration files
│   ├── hi3516dv300_liteos_a    # Hi3516DV300 and LiteOS_A platform files, including full configuration tables and boot files
│   ├── hi3518ev300_liteos_a    # Hi3518EV300 and LiteOS_A platform files, including full configuration tables and boot files
│   └── hi3861v100_liteos_riscv # Hi3861V100 and LiteOS_RISCV platform files, including full configuration tables and boot files
├── product                      # Full configuration tables of the product, including configuration units, the subsystem list, and the compiler
├── toolchain                    # Compilation toolchains, which contain the compiler paths, compilation options, and link options
└── tools                        # Tools on which compilation and building depend, for example, mkfs
```

## Compilation Commands<a name="section1475192018291"></a>

-   Usage

    ```
    python build.py product [options]
    ```

    Replace  **product**  with  **build/lite/produc/**_xxx_**.json**. Both the product name and components configured in the JSON file can be customized. By default, all components supported by the corresponding platform are contained in the JSON file.

-   Compilation options

    **-b, --build\_type**                    Debug or release

    **-t, --test**                                Build with test suit

    **-T, --target**                           Build single target

-   Output directory:  _root directory of the code_**/out/product**


## How to Develop<a name="section4207112818418"></a>

1.  Add a component.

    This step takes a custom component as an example to describe how to compile components, libraries, and executable files.

    The example component consists of two features:  **feature1**  and  **feature2**. The target of  **feature1**  is a dynamic library, and that of  **feature2**  is an executable file. The complete directory structure of the example component is as follows:

    ```
    example                         # Custom component
    ├── BUILD.gn                 # GN script of the component. The name is fixed.
    ├── feature1                 # Custom unit 1
    │   ├── BUILD.gn            # GN script of feature1. The name is fixed.
    │   ├── include             # Header file folder
    │   │   └── helloworld1.h  # Header file 1
    │   └── src                 # Source file folder
    │       └── helloworld1.c   # Source file 1
    ├── feature2                 # Custom unit 2
    │   ├── BUILD.gn            # GN script of feature2. The name is fixed.
    │   ├── include             # Header file folder
    │   │   └── helloworld2.h  # Header file 2
    │   └── src                 # Source file folder
    │       └── helloworld2.c   # Source file 2
    ├── build.sh                 # (Optional) build.sh script of the custom component
    └── Makefile                 # (Optional) Makefile script of the custom component
    ```

    Example 1: GN script \(**example/feature1/BUILD.gn**\) for dynamic library compilation.

    ```
    # Example for compiling the helloworld dynamic library
    # Build.gn script of helloworld
    shared_library("helloworld_lib") {
      sources = [
        "src/helloworld1.c"
      ]
      include_dirs = [
        "include",
        "../feature2_example/include" # (Optional) Add feature2_example to this include if needed.
      ]
    }
    ```

    Example 2: GN script \(**example/feature2/BUILD.gn**\) for executable file compilation

    The built-in  **executable**  function generates the executable file. Sample code is as follows:

    ```
    # Compile the executable .bin file.
    executable("hello_world_bin") {
      sources = [
        "src/helloworld2.c"
      ]
      include_dirs = [
        "include",
        "../feature2_example/include"    # (Optional) Add feature2_example to this include if needed.
      ]
      # (Optional) Add feature1_example to this deps if needed.
      deps = [
          "../feature1_example:helloworld1"
      ]
    }
    ```

    Example 3: GN script \(**example/BUILD.gn**\) for component compilation

    ```
    import("//build/lite/config/component/lite_component.gni")
    lite_component("example_gn") {
      features = [
        "feature_example1:helloworld_lib",
        "feature_example2:hello_world_bin",
      ]
    }
    ```

    Example 4: GN script for compiling  **build.sh**  or the  **Makefile**  project of a third-party open-source software

    ```
    build_ext_component("example_mk") {
      exec_path = rebase_path(rebase_path(".", root_build_dir))
      outdir = rebase_path(get_path_info(".", "out_dir"))
      prebuilts = "sh build.sh"
      command = "make clean && make"
    }
    ```

    Global variables are defined in  **build/lite/ohos\_var.gni.**

    The following table describes common global variables.

    **Table  1**  Global variables

    <a name="table520317612613"></a>
    <table><thead align="left"><tr id="row13203861262"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p2203368619"><a name="p2203368619"></a><a name="p2203368619"></a>Variable</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p15203765620"><a name="p15203765620"></a><a name="p15203765620"></a>Value Range</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p6203669616"><a name="p6203669616"></a><a name="p6203669616"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row42036617616"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1643814011561"><a name="p1643814011561"></a><a name="p1643814011561"></a>ohos_kernel_type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p114385019568"><a name="p114385019568"></a><a name="p114385019568"></a>"liteos_a", "liteos_riscv"</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p820396265"><a name="p820396265"></a><a name="p820396265"></a>Kernel type</p>
    </td>
    </tr>
    <tr id="row62033619614"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p134381805564"><a name="p134381805564"></a><a name="p134381805564"></a>board_name</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p9203161968"><a name="p9203161968"></a><a name="p9203161968"></a>"hi3516dv300", "hi3518ev300", "hi3861v100"</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p172031169619"><a name="p172031169619"></a><a name="p172031169619"></a>Development board</p>
    </td>
    </tr>
    <tr id="row1620318610614"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1143880135612"><a name="p1143880135612"></a><a name="p1143880135612"></a>ohos_build_compiler</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p22041613618"><a name="p22041613618"></a><a name="p22041613618"></a>"gcc", "clang"</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p9204861469"><a name="p9204861469"></a><a name="p9204861469"></a>Compilation toolchain type</p>
    </td>
    </tr>
    <tr id="row6392114583815"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p539294514383"><a name="p539294514383"></a><a name="p539294514383"></a>ohos_build_type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p7392144510388"><a name="p7392144510388"></a><a name="p7392144510388"></a>"debug", "release"</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p53921145123819"><a name="p53921145123819"></a><a name="p53921145123819"></a>Compilation type</p>
    </td>
    </tr>
    </tbody>
    </table>

    The following example code configures  **ohos\_kernel\_type**  in  **component\_example/feature2\_example/BUILD.gn**

    ```
    lite_library("helloworld") {
      if (ohos_kernel_type == "liteos_a") {
        target_type = "shared_library"
      }
      else if (ohos_kernel_type == "liteos_riscv") {
        target_type = "static_library"
      }
      sources = [
        "src/helloworld1.c"
      ]
      include_dirs = [
        "include"
      ]
    }
    ```

2.  Compile the product solution.

    The configuration of the product solution is stored in a JSON file \(for example,  **ipcamera\_hi3516dv300.json**\) under the  **build/lite/product**  directory. During the construction, the system reads the configuration file, which contains custom subsystems and components. To compile  **ipcamera\_hi3516dv30**, for example, run the following command:

    ```
    python build.py ipcamera_hi3516dv30
    ```

3.  Obtain the compilation result.

    Files generated after compilation are archived in the  **out**  directory. For example, run  **python build.py wifiiot -b debug**  in the directory where the code is located. After  **wifiiot**  is compiled, the following result is generated:

    ```
    out/
    └── wifiiot                               # Product name
    ├── args.gn                               # Custom variables for GN compilation
    ├── build.log                             # Compilation log
    ├── build.ninja
    ├── build.ninja.d
    ├── gen
    ├── Hi3861_boot_signed_B.bin              # Signed bootloader backup file
    ├── Hi3861_boot_signed.bin                # Signed bootloader file
    ├── Hi3861_loader_signed.bin              # Loader file used by the burning tool
    ├── Hi3861_wifiiot_app_allinone.bin       # Production line tooling burning file, which contains the independent burning program and loader program
    ├── Hi3861_wifiiot_app.asm                # Kernel asm file
    ├── Hi3861_wifiiot_app_burn.bin           # Burning file
    ├── Hi3861_wifiiot_app_flash_boot_ota.bin # Flash Boot upgrade file
    ├── Hi3861_wifiiot_app.map                # Kernel map file
    ├── Hi3861_wifiiot_app_ota.bin            # Kernel upgrade file
    ├── Hi3861_wifiiot_app.out                # Kernel output file
    ├── Hi3861_wifiiot_app_vercfg.bin         # Configuration with secure boot and kernel versions to prevent version rollback
    ├── libs                                  # Library folder
    ├── NOTICE_FILE
    ├── obj
    ├── suites
    └── toolchain.ninja
    ```

    Note: You are advised to use the  **Hi3861\_wifiiot\_app\_allinone.bin**  program to burn files.

    Run  **python build.py ipcamera\_hi3518ev300 -b debug**. After the compilation is complete, the following result is generated \(similar to that for  **ipcamera\_hi3516dv300**\):

    ```
    out/
    └── ipcamera_hi3518ev300            # Product name
    ├── args.gn                         # Custom variables for GN compilation
    ├── bin                             # Link to the folder where the .bin file locates
    ├── bm_tool.map                     # map file
    ├── build.log                       # Compilation log
    ├── build.ninja
    ├── build.ninja.d
    ├── bundle_daemon_tool.map          # map file
    ├── data                            # Configuration file of media resources on which the camera depends.
    ├── dev_tools                       # R&D self-testing
    ├── foundation.map                  # map file
    ├── gen
    ├── libaudio_api.so
    ├── libs                            # Library files
    ├── liteos.bin                      # Basic kernel file for LiteOS
    ├── media_server.map                # map file
    ├── NOTICE_FILE
    ├── obj                             # Compilation result folder containing binary files
    ├── OHOS_Image                      # Unstriped .bin file of the LiteOS package
    ├── OHOS_Image.asm                  # Assembly code
    ├── OHOS_Image.bin                  # LiteOS package for burning
    ├── OHOS_Image.map                  # map file
    ├── rootfs.img                      # Compiled library and application image
    ├── rootfs.tar                      # Compressed rootfs
    ├── suites                          # XTS compilation result
    ├── test                            # Test case compilation result
    ├── toolchain.ninja
    ├── userfs                          # User-readable and -writable partition
    ├── userfs.img                      # User-readable and -writable partition in .img format, corresponding to the /storage directory after system startup.
    └── vendor                          # Firmware and configuration files of the chip
    ```


