# Building the Standard System<a name="EN-US_TOPIC_0000001076490572"></a>

## Overview<a name="section17466112012244"></a>

The compilation and building subsystem provides a framework based on Generate Ninja \(GN\) and Ninja. This subsystem allows you to:

-   Build products based on different chipset platforms, for example, Hi3516D V300.

-   Package capabilities required by a product by assembling modules based on the product configuration.

### Basic Concepts<a name="section445513507246"></a>

It is considered best practice to learn the following basic concepts before you start building:

-   **Platform**

    A platform is a combination of development boards and kernels.

    Supported subsystems and modules vary according to the platform.

-   **Subsystems**

    OpenHarmony is designed with a layered architecture, which from bottom to top consists of the kernel layer, system service layer, framework layer, and application layer. System functions are expanded by levels, from system to subsystem, and further to module. In a multi-device deployment scenario, unnecessary subsystems and modules can be excluded from the system as required. A subsystem is a logical concept and is a flexible combination of functions.

-   **Module**

    A module is a reusable software binary unit that contains source code, configuration files, resource files, and build scripts. A module can be built independently, integrated in binary mode, and then tested independently.

-   **GN**

    GN is short for Generate Ninja, which is used to generate Ninja files.

-   **Ninja**

    Ninja is a small high-speed build system.


### Working Principles<a name="section12541217142510"></a>

The process to build OpenHarmony is as follows:

-   Parsing commands: Parse the name of the product to build and load related configurations.
-   Running GN: Configure toolchains and global options based on the parsed product name and compilation type.
-   Running Ninja: Start building and generate a product distribution.

### Limitations and Constraints<a name="section886933762513"></a>

-   You must download the source code using method 3 described in  [Source Code Acquisition](../get-code/sourcecode-acquire.md).
-   The build environment must be Ubuntu 18.04 or later.
-   You must install the software package required for build.

    The installation command is as follows:

    ```
    sudo apt-get install binutils git-core gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4
    ```


## Compilation and Building Guidelines<a name="section16901215262"></a>

### Directory Structure<a name="section109065332264"></a>

```
/build                           # Primary directory
├── config                       # Build configuration items
├── core
│   └── gn                       # Build entry BUILD.gn configuration
├── loader                       # Loader of module configuration, which also generates a template for the module
├── ohos                         # Configuration of the process for building and packaging OpenHarmony
│   ├── kits                     # Build and packaging templates and processing flow for kits
│   ├── ndk                      # NDK template and processing flow
│   ├── notice                   # Notice template and processing flow
│   ├── packages                 # Distribution packaging template and processing flow
│   ├── sa_profile               # SA template and processing flow
│   ├── sdk                      # SDK template and processing flow, which contains the module configuration in the SDK
│   └── testfwk                  # Processing flow related to the test
├── scripts                      # Build-related Python script
├── templates                    # C/C++ build templates
└── toolchain                    # Toolchain configuration
```

### Build Command<a name="section123265539266"></a>

-   Run the following command in the root directory of the source code to build the full distribution:

    ```
    ./build.sh --product-name {product_name}
    ```

    **product\_name**  indicates the product supported by the current distribution, for example, hispark_taurus_standard.

    The image generated after build is stored in the  **out/{device_name}/packages/phone/images/**  directory.

-   The build command supports the following options:

    ```
      --product-name    # (Mandatory) Name of the product to build, for example, Hi3516D V300
      --build-target    # (Optional) One or more build targets
      --gn-args         # (Optional) One or more gn parameters
      --ccache          # (Optional) Use of Ccache for build. This option takes effect only when Ccache is installed on the local PC.
    ```


### How to Develop<a name="section591084422719"></a>

1.  Add a module.

    The following steps use a custom module as an example to describe how to build the module, including build a library, an executable file, and a configuration file.

    The example module  **partA**  consists of  **feature1**,  **feature2**, and  **feature3**. The target is a dynamic library for  **feature1**, an executable file for  **feature2**, and an etc configuration file for  **feature3**.

    Add  **partA**  to a subsystem, for example,  **subsystem\_examples**  \(defined in the  **test/examples/**  directory\).

    The complete directory structure of  **partA**  is as follows:

    ```
    test/examples/partA
    ├── feature1
    │   ├── BUILD.gn
    │   ├── include
    │   │   └── helloworld1.h
    │   └── src
    │       └── helloworld1.cpp
    ├── feature2
    │   ├── BUILD.gn
    │   ├── include
    │   │   └── helloworld2.h
    │   └── src
    │       └── helloworld2.cpp
    └── feature3
        ├── BUILD.gn
        └── src
            └── config.conf
    ```

    Example 1: GN script \(**test/examples/partA/feature1/BUILD.gn**\) for building a dynamic library

    ```
    config("helloworld_lib_config") {
     include_dirs = [ "include" ]
    }
    
    ohos_shared_library("helloworld_lib") {
      sources = [
        "include/helloworld1.h",
        "src/helloworld1.cpp",
      ]
      public_configs = [ ":helloworld_lib_config" ]
      part_name = "partA"
    }
    ```

    Example 2: GN script \(**test/examples/partA/feature2/BUILD.gn**\) for building an executable file

    ```
    ohos_executable("helloworld_bin") {
      sources = [
        "src/helloworld2.cpp"
      ]
      include_dirs = [ "include" ]
      deps = [                                # Dependent submodule
        "../feature1:helloworld_lib"
      ]
      external_deps = [ "partB:module1" ]     # (Optional) If there is a cross-module dependency, the format is "module name: submodule name"
      install_enable = true                   # By default, the executable file is not installed. You need to set this parameter to true for installation.
      part_name = "partA"
    }
    ```

    Example 3: GN script \(**test/examples/partA/feature3/BUILD.gn**\) for building the etc configuration file \(submodule\).

    ```
    ohos_prebuilt_etc("feature3_etc") {
      source = "src/config.conf"
      relative_install_dir = "init"    # (Optional) Directory for installing the submodule, which is relative to the default installation directory (/system/etc)
      part_name = "partA"
    }
    ```

    Example 4: Adding the module configuration file  **test/examples/ohos.build**  to the  **ohos.build**  file of this subsystem. Each subsystem has an  **ohos.build**  file in its root directory. Example:

    ```
    "partA": {
        "module_list": [
          "//test/examples/partA/feature1:helloworld_lib",
          "//test/examples/partA/feature2:helloworld_bin",
          "//test/examples/partA/feature3:feature3_etc",
        ],
        "inner_kits": [
    
        ],
        "system_kits": [
    
        ],
        "test_list": [
    
        ]
      }
    ```

    The declaration of a module contains the following parts:

    -   **module\_list**: submodule list of the module
    -   **inner\_kits**: APIs for other modules that depend on this module through  **external\_deps**
    -   **system\_kits**: APIs for developers
    -   **test\_list**: test cases for the submodules of the module

2.  Add the module to the product configuration file.

    Add the module to the product configuration file  **//vendor/{product_company}/{product-name}/config.json**.

    Add "subsystem\_examples:partA" to the product configuration file.  **partA**  will be built and packaged into the distribution.

3.  Build the module.

    For example, run the following command to build hispark_taurus_standard:

    ```
    ./build.sh --product-name hispark_taurus_standard --ccache
    ```

4.  Obtain the build result.

    Files generated during the build process are stored in the  **out/hispark_taurus/**  directory, and the generated image is stored in the  **out/hispark_taurus/packages/phone/images/**  directory.


