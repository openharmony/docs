# Compilation and Building Guidelines<a name="EN-US_TOPIC_0000001060378721"></a>

-   [Directory Structure](#section56731811102915)
-   [Component-based Building Procedure](#section4207112818418)

## Directory Structure<a name="section56731811102915"></a>

```
build/lite                      # Primary directory for compilation and building
├── components                  # Component description file
├── hb                          # hb pip installation package
├── make_rootfs                 # make script for the file system
├── config                      # Compilation configuration items
│   ├── component               # Definitions of component-related templates, including static libraries, dynamic libraries, extension components, and emulator libraries
│   ├── kernel                  # Compilation configuration parameters of the kernel
│   └── subsystem               # Subsystem template
├── ndk                         # NDK-related compilation scripts and configuration parameters
├── product                     # Full configuration tables of the product, which contain configuration units, the subsystem list, and the compiler
└── toolchain                   # Compilation toolchains, which contain the compiler directories, compilation options, and linking options
```

## Component-based Building Procedure<a name="section4207112818418"></a>

1.  Add the component compilation script.

    The compilation script language for the component is GN. For details about its basic usage, see the  [GN Quick Start Guide](https://gn.googlesource.com/gn/+/master/docs/quick_start.md). In GN, a component is a compilation unit, which can be a static library, a dynamic library, or an executable file.

    The following example adds a script to compile the  **hello\_world**  component \(as an executable file\).

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

    The added script is used to compile  **hello\_world**  that can run on OpenHarmony.

2.  Add the component description.

    The component description is stored in the  **build/lite/components**  directory. New components must be added to the JSON file of the corresponding subsystem. A component description must contain the following fields:

    -   **component**: name of the component
    -   **description**: one-sentence description of the component
    -   **optional**: whether the component is optional
    -   **dirs**: source code directory of the component
    -   **targets**: component compilation entry

    For example, to add the  **hello\_world**  component to the application subsystem, add the  **hello\_world**  object to the  **applications.json**  file.

    ```
    {
      "components": [
        {
          "component": hello_world",
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

3.  Configure the component for the product.

    The product configuration file is stored in the  **vendor/company/**  directory. The file must contain the product name, OpenHarmony version, device vendor, development board name, kernel type, kernel version, and the subsystem and component to configure. The following example adds the  **hello\_world**  component to the  **my\_product.json**  configuration file:

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

4.  Compile the component or product.
    1.  Run  **hb set**  and select  **hello\_world\_test@hisilicon**.
    2.  To build the  **hello\_world**  component, run the following command:

        **hb build hello\_world**

        To build the  **hello\_world\_test**  product, run the following command:

        **hb build**



