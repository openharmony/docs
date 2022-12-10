# Module
## Configuration Rules

The Compilation and Building subsystem implements compilation and packaging by module, component, and product. A module is an target to build. It can be a dynamic library, static library, configuration file, or prebuilt module. A module must belong to a component and can belong to only one component. OpenHarmony uses customized GN templates to configure modules. For details about the GN basics, see https://gn.googlesource.com/gn/+/main/docs/reference.md.

The common templates for module configuration are as follows:

```
# C/C++ templates
ohos_shared_library
ohos_static_library
ohos_executable
ohos_source_set

# Prebuilt templates
ohos_prebuilt_executable
ohos_prebuilt_shared_library
ohos_prebuilt_static_library

# HAP templates
ohos_hap
ohos_app_scope
ohos_js_assets
ohos_resources

# Other templates
# Configuration file
ohos_prebuilt_etc

# SA profile
ohos_sa_profile
```

You are recommended to use the OpenHarmony customized templates.

### C/C++ Template Example

The .gni file corresponding to the templates starting with **ohos** is located in **openharmony/build/templates/cxx/cxx.gni**.

**ohos_shared_library** example:

```shell
import("//build/ohos.gni")
ohos_shared_library("helloworld") {
  sources = ["file"]
  include_dirs = []             # If there are duplicate header files, the header files defined earlier take effect.
  cflags = []                   # If there are duplicate or conflict settings, the settings in cflags take effect.
  cflags_c = []
  cflags_cc = []
  ldflags = []                  # If there are duplicate or conflict definitions, the settings in ohos_template take effect.
  configs = []
  deps = []                     # Define dependent modules that belong to the same component.

  external_deps = [             # Define dependent modules that belong to different components.
  "part_name:module_name",      # The value is in the Component_name:Module_name format.
  ]                             # The dependent modules must be declared in inner_kits by the dependent component.

  output_name = [string]        # Name of the module output.
  output_extension = []         # Extension name of the module.
  module_install_dir = []       # Module installation directory. The default directory is /system/lib64 or /system/lib. Specify the directory from system/ or vendor/.
  relative_install_dir = []     # Relative module installation directory (relative to /system/lib64 or /system/lib). If module_install_dir is configured, the parameter does not take effect.

  part_name = [string]          # (Mandatory) Component name.
  output_dir
  
  # Sanitizer variables
  cfi = [boolean]
  scs = [boolean]
  scudo = []
  ubsan = []
  boundary_sanitize = []
  integer_overflow_sanitize = []
  
  testonly = [boolean]
  license_as_sources = []
  license_file = []             # A .txt file.
  remove_configs = []
  no_default_deps = []
  install_images = []
  install_enable = [boolean]
  symlink_target_name = []
  version_script = []
  use_exceptions = []
}
```

**ohos_static_library** example:

```shell
import("//build/ohos.gni")
ohos_static_library("helloworld") {
  sources = ["file"]            # Source code in .c format.
  include_dirs = ["dir"]        # Directories to be included.
  configs = []                  # Configuration.
  deps = []                     # Define dependent modules that belong to the same component.
  part_name = [string]          # Component name.
  subsystem_name = [string]     # Subsystem name.
  cflags = []

  external_deps = [             # Define dependent modules that belong to different components.
  "part_name:module_name",      # The value is in the Component_name:Module_name format.
  ]                             # The dependent modules must be declared in inner_kits by the dependent component.

  lib_dirs = []
  public_configs = []
  
  # Sanitizer variables
  cfi = [boolean]
  scs = [boolean]
  scudo = []
  ubsan = []
  boundary_sanitize = []
  integer_overflow_sanitize = []
  
  remove_configs = []
  no_default_deps = []
  license_file = []             # A .txt file.
  license_as_sources = []
  use_exceptions = []
}
```

**ohos_executable** example:

```shell
import("//build/ohos.gni")
ohos_executable("helloworld") {
  configs = []                       # Configuration. 
  part_name = [string]               # Component name.
  subsystem_name = [string]          # Subsystem name.
  deps = []                          # Define dependent modules that belong to the same component.

  external_deps = [                  # Define dependent modules that belong to different components.
  "part_name:module_name",           # The value is in the Component_name:Module_name format.
  ]                                  # The dependent modules must be declared in inner_kits by the dependent component.
  ohos_test = []
  test_output_dir = []
  
  # Sanitizer variables
  cfi = [boolean]
  scs = [boolean]
  scudo = []
  ubsan = []
  boundary_sanitize = []
  integer_overflow_sanitize = []
  
  testonly = [boolean]
  license_as_sources = []
  license_file = []                  # A .txt file.
  remove_configs = []
  static_link = []
  install_images = []
  module_install_dir = []            # Module installation directory, starting from system/ or vendor/.
  relative_install_dir = []
  symlink_target_name = []
  output_dir = [directory]           # Directory in which output files are located.
  install_enable = [boolean]
  version_script = []
  use_exceptions = []
}
```

**ohos_source_set** example:

```shell
import("//build/ohos.gni")
ohos_source_set("helloworld") {
  sources = ["file"]           # Source code in .c format.
  include_dirs = []            # Directories to be included.
  configs = []                 # Configuration.
  public = []                  # Header files.
  defines = []
  public_configs = []
  part_name = [string]         # Component name.
  subsystem_name = [string]    # Subsystem name.
  deps = []  # Define dependent modules that belong to the same component.

  external_deps = [            # Define dependent modules that belong to different components.
  "part_name:module_name",     # The value is in the Component_name:Module_name format.
  ]                            # The dependent modules must be declared in inner_kits by the dependent component.
  
  # Sanitizer variables
  cfi = [boolean]
  scs = [boolean]
  scudo = []
  ubsan = []
  boundary_sanitize = []
  integer_overflow_sanitize = []
  
  testonly = [boolean]
  license_as_sources = []
  license_file = []
  remove_configs = []
  no_default_deps = []
  license_file = []              # A .txt file.
  license_as_sources = []
  use_exceptions = []
}
```

![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>Only **sources** and **part_name** are mandatory.

### Prebuilt Template Example

The .gni file of the prebuilt templates is located in **openharmony/build/templates/cxx/prebuilt.gni**.

**ohos_prebuilt_executable** example:

```shell
import("//build/ohos.gni")
ohos_prebuilt_executable("helloworld") {
  sources = ["file"]                      # Source.
  output = []
  install_enable = [boolean]         

  deps = []                               # Define dependent modules that belong to the same component.
  public_configs = []
  subsystem_name = [string]               # Subsystem name.
  part_name = [string]                    # Component name.

  testonly = [boolean]
  visibility = []

  install_images = []
  module_install_dir = []                 # Module installation directory, starting from system/ or vendor/.
  relative_install_dir = []               # Relative module installation directory (relative to system/etc). If module_install_dir is configured, the parameter does not take effect.
  symlink_target_name = []


  license_file = []                       # A .txt file.
  license_as_sources = []
}
```

**ohos_prebuilt_shared_library** example:

```shell
import("//build/ohos.gni")
ohos_prebuilt_shared_library("helloworld") {
  sources = ["file"]                      # .so files.
  output = []
  install_enable = [boolean]

  deps = []                               # Define dependent modules that belong to the same component.
  public_configs = []
  subsystem_name = [string]               # Subsystem name.
  part_name = [string]                    # Component name.

  testonly = [boolean]
  visibility = []

  install_images = []
  module_install_dir = []                 # Module installation directory, starting from system/ or vendor/.
  relative_install_dir = []               # Relative module installation directory (relative to system/etc). If module_install_dir is configured, the parameter does not take effect.
  symlink_target_name = [string]


  license_file = [string]                 # A .txt file.
  license_as_sources = []
}
```

**ohos_prebuilt_static_library** example:

```shell
import("//build/ohos.gni")
ohos_prebuilt_static_library("helloworld") {
  sources = ["file"]              # .so files.
  output = []

  deps = []                       # Define dependent modules that belong to the same component.
  public_configs = []
  subsystem_name = [string]       # Subsystem name.
  part_name = [string]            # Component name.

  testonly = [boolean]
  visibility = []

  license_file = [string]         # A .txt file.
  license_as_sources = []
}
```

![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>Only **sources** and **part_name** are mandatory.

### HAP Templates

See [HAP Build Guide](subsys-build-gn-hap-compilation-guide.md).



### Other Templates

**ohos_prebuilt_etc** example:

```shell
import("//build/ohos.gni")
ohos_prebuilt_etc("helloworld") {
  # The most common attributes of the ohos_prebuilt_etc template.
  sources = ["file"]
  module_install_dir = []                  # Module installation directory, starting from system/ or vendor/.
  subsystem_name = [string]                # Subsystem name.
  part_name = [string]                     # (Mandatory) Component name.
  install_images = []
  relative_install_dir = []                # Relative module installation directory (relative to system/etc). If module_install_dir is configured, the parameter does not take effect.
  
  # Uncommon attributes of the ohos_prebuilt_etc template:
  deps = []                                # Define dependent modules that belong to the same component.
  testonly = [boolean]
  visibility = []
  public_configs = []
  symlink_target_name = [string]
  license_file = [string]
  license_as_sources = []
}
```

**ohos_sa_profile** example:

```shell
import("//build/ohos.gni")
ohos_sa_profile("helloworld") {
  sources = [".xml"]                   # .xml file.
  part_name = [string]                 # Component name.
  subsystem_name = [string]            # Subsystem name.
}
```

![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**: Only **sources** and **part_name** are mandatory.

## Adding and Building a Module

The figure below illustrates the process for adding a module. A module belongs to a component, which belongs to a subsystem. Please note that the chipset solution, as a special component, does not have a subsystem. You may need to:

- Add a module to an existing component.

- Add a module to a new component.

- Add a module to a new subsystem.

  ![](figure/module_addition_process.png)

**Adding a Module to an Existing Component**

1. Configure the **BUILD.gn** file in the module directory and select the GN template.

2. Modify the **bundle.json** file.

   ```shell
   {
      "name": "@ohos/<component_name>,                          # HPM component name, in the "@Organization/Component_name" format.
      "description": "xxxxxxxxxxxxxxxxxxx",                     # Description of the component functions.
      "version": "3.1",                                         # Version, which must be the same as the version of OpenHarmony.
      "license": "MIT",                                         # Component license.
      "publishAs": "code-segment",                              # HPM package release mode. The default value is code-segment.
      "segment": {
          "destPath": "third_party/nghttp2"
      },                                                        # Code restoration path (source code path) set when publishAs is code-segment.
      "dirs": {},                                               # Directory structure of the HPM package. This field is mandatory and can be left empty.
      "scripts": {},                                            # Scripts to be executed. This field is mandatory and can be left empty.
      "licensePath": "COPYING",
      "readmePath": {
          "en": "README.rst"
      },
      "component": {                                            # Component attributes.
          "name": "<component_name>",                           # Component name.
          "subsystem": "",                                      # Subsystem to which the component belongs.
          "syscap": [],                                         # System capabilities provided by the component for applications.
          "features": [],                                       # List of configurable features of the component. Generally, this parameter corresponds to sub_component in build.
          "adapted_system_type": [],                            # Types of adapted systems. The value can be mini, small, standard, or their combinations.
          "rom": "xxxKB"                                        # ROM baseline. If there is no baseline, enter the current value.
          "ram": "xxxKB",                                       # RAM baseline. If there is no baseline, enter the current value.
          "deps": {
              "components": [                                   # Other components on which this component depends.
              "third_party": [                                  # Third-party open-source software on which this component depends.
          },
       
          "build": {                                            # Build-related configuration.
              "sub_component": [
                  "//foundation/arkui/napi:napi_packages",      # Existing module 1.
                  "//foundation/arkui/napi:napi_packages_ndk"   # Existing module 2.
                  "//foundation/arkui/napi:new"                 # Module to add.
              ],                                                # Component build entry. Configure the module here.
              "inner_kits": [],                                 # APIs between components.
              "test": []                                        # Entry for building the component's test cases.
          }
      }
   }
   ```

   ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>The **bundle.json** file must be in the folder of the corresponding subsystem.

3. Start the build and check whether a .so file or binary file is generated.

**Creating a Component and Adding a Module**

1. Configure the **BUILD.gn** file in the module directory and select the corresponding GN template. Note that **part_name** in the **BUILD.gn** file is the name of the component to add.

2. Create a **bundle.json** file in the folder of the corresponding subsystem.

3. Add the new component to the end of existing components in **vendor/{product_company}/{product_name}/config.json**.

   ```shell
    "subsystems": [
         {
           "subsystem": "Subsystem to which the component belongs",
           "components": [
             {"component": "Component 1 name", "features":[]},         # Existing component 1 in the subsystem
             { "component": "Component 2 name", "features":[] },       # Existing component 2 in the subsystem
             {"component": "New component name", "features":[]}        # New component in the subsystem
           ]
         },
         .
    ]
   ```

4. Start the build and check whether a .so file or binary file is generated.
   

**Creating a Subsystem and Adding a Module**

1. Configure the **BUILD.gn** file in the module directory and select the corresponding GN template. This step is the same as Step 1 in "Creating a Component and Adding a Module."

2. Create a **bundle.json** file in the folder of the component of the subsystem. This step is the same as Step 2 in "Creating a Component and Adding a Module."

3. Modify the **subsystem_config.json** file in the **build** directory.

   ```shell
   {
    "Subsystem 1 name": {                     # Existing subsystem 1
      "path": "Subsystem 1 directory",
      "name": "Subsystem 1 name"
    },
     "Subsystem 2 name": {                    # Existing subsystem 2
      "path": "Subsystem 2 directory",
      "name": "Subsystem 2 name"
    },
    "Subsystem name new": {                   # Subsystem to add
      "path": "New subsystem directory",
      "name": "New subsystem name"
    },
   
   }
   ```

   The **subsystem_config.json** file defines the subsystems and their directories. When adding a subsystem, specify **path** and **name** for the subsystem.

4. If **product_name** in the **vendor/{product_company}/{product_name}** directory is **hispark_taurus_standard**, add the new component information to the end of existing components in the **config.json** file.

   ```shell
   "subsystems": [
     {
       "subsystem": "arkui",                      # Name of the existing subsystem
       "components": [                            # All components of the subsystem
         {
           "component": "ace_engine_standard",    # Name of the existing component
           "features": []
         },
         {
           "component": "napi",                   # Name of the existing component
           "features": []
         }
          {
           "component": "component_new1",         # Name of the new component to add
           "features": []
         }
      ]
     },
     {
       "subsystem": "subsystem_new",              # Name of the new subsystem to add
       "components": [
         {
           "component": "component_new2",         # Name of the component to be added to the new subsystem
           "features": []
         }
       ]
     },
    
    ]
   ```

4. Start the build and check whether a .so file or binary file is generated.

**Building a Module**

You can start the build by using the [CLI or hb tool](subsys-build-all.md#build-commands). The following uses the CLI as an example:

You can run the **--build-target** *Module_name* command to build a module separately.

```shell
./build.sh --build-target Module_name
```

You can also build a product. For example, to build hispark_taurus_standard, run the following command:

```shell
./build.sh --product-name hispark_taurus_standard --build-target Module_name --ccache
```

You can also build the component to which the module belongs.

```shell
./build.sh --product-name hispark_taurus_standard --build-target musl --build-target Module_name --ccache
```

