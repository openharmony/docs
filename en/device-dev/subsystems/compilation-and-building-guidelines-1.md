# Compilation and Building Guidelines<a name="EN-US_TOPIC_0000001076420631"></a>

-   [Directory Structure](#section56731811102915)
-   [Building](#section1069873833818)
    -   [Build Command](#section2740182614395)

-   [How to Develop](#section4207112818418)

## Directory Structure<a name="section56731811102915"></a>

```
/build                               # Primary directory
├── config                        # Build configuration items
├── core
│   └── gn                       # Build entry configuration
├── loader                        # Loader of module configuration, which also generates a template for the module
├── ohos                          # Configuration of the process for building and packaging OpenHarmony
│   ├── kits                     # Build and packaging templates and processing flow for kits
│   ├── ndk                      # NDK template and processing flow
│   ├── notice                   # Notice template and processing flow
│   ├── packages                 # Distribution packaging template and processing flow
│   ├── sa_profile               # SA template and processing flow
│   ├── sdk                      # SDK template and processing flow, which contains the module configuration in the SDK
│   └── testfwk                   # Processing flow related to the test
├── scripts                      # Build-related Python script
├── templates                    # C/C++ build templates
└── toolchain                    # Toolchain configuration
```

## Building<a name="section1069873833818"></a>

### Build Command<a name="section2740182614395"></a>

-   Run the following command in the root directory of the source code to build the full distribution:

    ```
    ./build.sh --product-name {product_name}
    ```

    **product\_name**  indicates the product supported by the current distribution, for example, Hi3516D V300.

    The image generated after build is stored in the  **out/ohos-arm-release/packages/phone/images/**  directory.

-   The build command supports the following options:

    ```
      --product-name    # (Mandatory) Name of the product to build, for example, Hi3516D V300
      --build-target    # (Optional) One or more build targets
      --gn-args         # (Optional) One or more gn parameters
      --ccache          # (Optional) Use of Ccache for build. This option takes effect only when Ccache is installed on the local PC.
    ```


## How to Develop<a name="section4207112818418"></a>

1.  Add a module.

    The following steps use a custom module as an example to describe how to build the module, including build a library, an executable file, and a configuration file.

    The example module  **partA**  consists of  **feature1**,  **feature2**, and  **feature3**. The target of  **feature1**  is a dynamic library, that of  **feature2**  is an executable file, and that of  **feature3**  is an etc configuration file.

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

    Example 4: Adding the module configuration file  **test/examples/ohos.build**  to the  **ohos.build**  file of this subsystem. Each subsystem has an  **ohos.build**  file in its root directory.

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

    Add  **"subsystem\_examples:partA"**  to the configuration file  **productdefine/common/products/\{product-name\}.json**  to build and package  **partA**  into the distribution.

3.  Build the module, including the library, executable file, and etc configuration file.

    For example, run the following command to build Hi3516D V300:

    ```
    ./build.sh --product-name Hi3516DV300 --ccache
    ```

4.  Obtain the build result.

    Files generated during the build are stored in the  **out/ohos-arm-release/**  directory, and the generated image is stored in the  **out/ohos-arm-release/packages/phone/images/**  directory.


