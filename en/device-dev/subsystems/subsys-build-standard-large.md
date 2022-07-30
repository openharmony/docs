# Building the Standard System

## Overview

The Compilation and Building subsystem provides a build framework based on Generate Ninja (GN) and Ninja. This subsystem allows you to:

- Build products based on different chipset platforms, for example, hispark_taurus_standard.

- Package capabilities required by a product by assembling components based on the product configuration.

### Basic Concepts

Learn the following basic concepts before you start:

- Platform
  
  A platform consists of the development board and kernel. The supported subsystems and components vary with the platform.

- Subsystem
  
  OpenHarmony is designed with a layered architecture, which consists of the kernel layer, system service layer, framework layer, and application layer from the bottom up. System functions are developed by levels, from system to subsystem and then to component. In a multi-device deployment scenario, you can customize subsystems and components as required. A subsystem, as a logical concept, consists of the least required components.

- Component
  
  A component is a reusable software unit that contains source code, configuration files, resource files, and build scripts. Integrated in binary mode, a component can be built and tested independently.

- GN
  
  GN is short for Generate Ninja. It is used to build Ninja files.

- Ninja
  
  Ninja is a small high-speed building system.

### Working Principles

The process for building an OpenHarmony system is as follows:

- Parsing commands: Parse the name of the product to build and load related configurations.

- Running GN: Configure the toolchain and global options based on the product name and compilation type.

- Running Ninja: Start building and generate a product distribution.

### Constraints

- You need to obtain the source code using method 3 described in [Obtaining Source Code](../get-code/sourcecode-acquire.md).

- Ubuntu 18.04 or later must be used.

- You must install the software packages required for build.
    The command is as follows:
  
  ```
  # Run the script in the home directory.
  # ./build/build_scripts/env_setup.sh
  # Do not run the command as the **root** user. Otherwise, the environment variables will be added to the **root** user. If your **shell** is not **bash** or **Zsh**, you need to manually configure the following content to your environment variables after the execution. To view your environment variables, run the **cd** command to go to your home directory and view the hidden files.
  # export PATH=/home/tools/llvm/bin:$PATH
  # export PATH=/home/tools/hc-gen:$PATH
  # export PATH=/home/tools/gcc_riscv32/bin:$PATH
  # export PATH=/home/tools/ninja:$PATH
  # export PATH=/home/tools/node-v12.20.0-linux-x64/bin:$PATH
  # export PATH=/home/tools/gn:$PATH
  # export PATH=/root/.local/bin:$PATH
  
  # If you do not need to run the script, you need to install the following:
  apt-get update -y 
  apt-get install -y apt-utils binutils bison flex bc build-essential make mtd-utils gcc-arm-linux-gnueabi u-boot-tools python3.9.2 python3-pip git zip unzip curl wget gcc g++ ruby dosfstools mtools default-jre default-jdk scons python3-distutils perl openssl libssl-dev cpio git-lfs m4 ccache zlib1g-dev tar rsync liblz4-tool genext2fs binutils-dev device-tree-compiler e2fsprogs git-core gnupg gnutls-bin gperf lib32ncurses5-dev libffi-dev zlib* libelf-dev libx11-dev libgl1-mesa-dev lib32z1-dev xsltproc x11proto-core-dev libc6-dev-i386 libxml2-dev lib32z-dev libdwarf-dev 
  apt-get install -y grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools  pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5 libncurses5-dev libncursesw5 libstdc++6 python2.7 gcc-arm-none-eabi vim ssh locales doxygen
  # Install the following modules for Python:
  chmod +x /usr/bin/repo 
  pip3 install --trusted-host https://repo.huaweicloud.com -i https://repo.huaweicloud.com/repository/pypi/simple requests setuptools pymongo kconfiglib pycryptodome ecdsa ohos-build pyyaml prompt_toolkit==1.0.14 redis json2html yagmail python-jenkins 
  pip3 install esdk-obs-python --trusted-host pypi.org 
  pip3 install six --upgrade --ignore-installed six
  #You also need to install LLVM, hc-gen, gcc_riscv32, Ninja, node-v14.15.4-linux-x64, and GN, and import the non-bash or non-Zsh configuration in the shell to your environment variables.
  ```



## Building Guidelines

### Directory Structure

```

/build                          # Directory for build

├── __pycache__                   
├── build_scripts/               # Python scripts for build
├── common/                      
├── config/                      # Build-related configurations
├── core
│   └── gn/                      # BUILD.gn configuration
    └── build_scripts/           
├── docs                          
gn_helpers.py*                    
lite/                            # hb and preloader entry                     
misc/
├── ohos                         # Process for building and packaging OpenHarmony
│   ├── kits                     # Kits build and packaging templates and processing
│   ├── ndk                      # NDK templates and processing
│   ├── notice                   # Notice templates and processing
│   ├── packages                 # Distribution packaging templates and processing
│   ├── sa_profile               # SA profiles and processing
│   ├── sdk                      # SDK templates and processing, which contains the module configuration in the SDK
│   └── testfwk                  # Testing-related processing
├── ohos.gni*                    # Common .gni files for importing a module at a time.
├── ohos_system.prop             
├── ohos_var.gni*                 
├── prebuilts_download.sh*        
├── print_python_deps.py*         
├── scripts/                      
├── subsystem_config.json         
├── subsystem_config_example.json 
├── templates/                   # C/C++ build templates
├── test.gni*                     
├── toolchain                    # Build toolchain configuration
├── tools                        # Common tools
├── version.gni                   
├── zip.py*                       


```

### Build Command

- Run the following command in the root directory of the source code to build a full distribution:

  ```

  ./build.sh --product-name {product_name}
  
  ```

  **{product_name}** specifies the product platform supported by the current distribution, for example, **hispark_taurus_standard**.

  The image generated is stored in the **out/{device_name}/packages/phone/images/** directory.

- The **./build.sh** command supports the following options:

  ```
  -h, --help                                        # Display help information and exit.
  --source-root-dir=SOURCE_ROOT_DIR                 # Specify the path.
  --product-name=PRODUCT_NAME                       # Specify the product name.
  --device-name=DEVICE_NAME                         # Specify the device name.
  --target-cpu=TARGET_CPU                           # Specify the CPU.
  --target-os=TARGET_OS                             # Specify the operating system.
  -T BUILD_TARGET, --build-target=BUILD_TARGET      # specifies one or more targets to build.
  --gn-args=GN_ARGS                                 # Specify GN parameters.
  --ninja-args=NINJA_ARGS                           # Specify Ninja parameters. 
  -v, --verbose                                     # Display all commands used.
  --keep-ninja-going                                # Keep Ninja going until 1,000,000 jobs fail.
  --sparse-image
  --jobs=JOBS
  --export-para=EXPORT_PARA
  --build-only-gn                                   # Perform GN parsing and does not run Ninja.
  --ccache                                          # (Optional) Use ccache for build. You need to install ccache locally.
  --fast-rebuild                                    # Whether to use fast rebuild. The default value is False.
  --log-level=LOG_LEVEL                             # Specify the log level during the build. The options are debug, info, and error. The default value is info.
  --device-type=DEVICE_TYPE                         # Specify the device type. The default value is default.
  --build-variant=BUILD_VARIANT                     # Specify the device operation mode. The default value is user.

  ```

### How to Develop

1. Add a component.
   
   The following use a custom component as an example to describe how to write .gn scripts for a library, an executable file, and a configuration file.
   
   In this example, **partA** consists of **feature1**, **feature2**, and **feature3**, which represent a dynamic library, an executable file, and an etc configuration file, respectively.
   
   Add **partA** to a subsystem, for example, **subsystem_examples** (defined in the **test/examples/** directory).
   

The directory structure of **partA** is as follows:

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

(a) Write **test/examples/partA/feature1/BUILD.gn** for the dynamic library.

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

(b) Write **test/examples/partA/feature2/BUILD.gn** for the executable file.

```
   
   ohos_executable("helloworld_bin") {
     sources = [
       "src/helloworld2.cpp"
     ]
     include_dirs = [ "include" ]
     deps = [                                # Dependent modules in the component
       "../feature1:helloworld_lib"
     ]
     external_deps = [ "partB:module1" ]     # (Optional) Dependent modules of another component are named in Component name:Module name format.
     install_enable = true                   # By default, the executable file is not installed. You need to set this parameter to true for installation.
     part_name = "partA"
}
   
```

(c) Write **test/examples/partA/feature3/BUILD.gn** for the etc module.

```
   
   ohos_prebuilt_etc("feature3_etc") {
     source = "src/config.conf"
     relative_install_dir = "init"    # (Optional) Relative directory for installing the module. The default installation directory is **/system/etc**.
     part_name = "partA"
}
   
```

   (d) Add the module configuration **test/examples/bundle.json** to the **bundle.json** file of the component. Each component has a **bundle.json** file in the root directory of the component. The sample code is as follows:

   ```
   {
       "name": "@ohos/<component_name>,                # OpenHarmony Package Manager (HPM) component name, in the "@Organization/Component name" format.
       "description": "xxxxxxxxxxxxxxxxxxx",           # Description of the component functions.
       "version": "3.1",                               # Version, which must be the same as the version of OpenHarmony.
       "license": "MIT",                               # Component license.
       "publishAs": "code-segment",                    # Mode for publishing the HPM package. The default value is code-segment.
       "segment": {
           "destPath": ""
       },                                              # Set the code restoration path (source code path) when publishAs is code-segment.
       "dirs": {},                                     # Directory structure of the HPM package. This field is mandatory and can be left empty.
       "scripts": {},                                  # Scripts to be executed. This field is mandatory and can be left empty.
       "licensePath": "COPYING",                       # Path of the module's license.
       "readmePath": {
           "en": "README.rst"
       },                                              # Path of module's reademe.opensource.
       "component": {                                  # Component attributes.
           "name": "<component_name>",                 # Component name.
           "subsystem": "",                            # Subsystem to which the component belongs.
           "syscap": [],                               # System capabilities provided by the component for applications.
           "features": [],                             # List of the component's configurable features. Generally, this parameter corresponds to sub_component in build and can be configured.
           "adapted_system_type": [],                  # Adapted system types, which can be mini, small, and standard. Multiple values are allowed.
           "rom": "xxxKB"                              # ROM baseline. If there is no baseline, enter the current value.
           "ram": "xxxKB",                             # RAM baseline. If there is no baseline, enter the current value.
           "deps": {
               "components": [],                       # Other components on which this component depends.
               "third_party": []                       # Third-party open-source software on which this component depends.
           },
           "build": {                                  # Build-related configurations.
               "sub_component": [],                    # Component build entry. Configure the module here.
               "inner_kits": [],                       # APIs between components.
               "test": []                              # Entry for building the component's test cases.
           }
       }
   }
   ```

2. Add the component to the product configuration file.
   Add the component to **//vendor/{*product_company*}/{*product-name*}/config.json**.

   For example, add "subsystem_examples:partA" to the product **config.json** file. **partA** will be built and packaged into the distribution.

3. Start the build.
   For example, run the following command to build **hispark_taurus_standard**:

   ```
   
   ./build.sh --product-name hispark_taurus_standard --ccache
   
   ```

4. Obtain the build result.
   You can obtain the generated files from the **out/hispark_taurus/** directory and the image in the **out/hispark_taurus/packages/phone/images/** directory.

## FAQs

### How Do I Build a Module and Package It into a Distribution?

- Set **part_name** for the module. A module can belong to only one part.

- Add the module to **component.build.sub_component** of the component, or define the dependency between the module and the modules in **component.build.sub_component**.

- Add the component to the component list of the product.

### How Do I Set deps and external_deps?

When adding a module, you need to declare its dependencies in **BUILD.gn**. **deps** specifies dependent modules in the same component, and **external_deps** specifies dependent modules between components.

The dependency between modules can be classified into:

**deps**: The dependent module to be added belongs to the same component with the current module. For example, module 2 depends on module 1, and modules 1 and 2 belong to the same component.

**external_deps**: The dependent module to be added belongs to another component. For example, module 2 depends on module 1, and modules 1 and 2 belong to different components.

- Example of **deps**:

   ```
   import("//build/ohos.gni")
   ohos_shared_library("module1") {
     ...
     part_name = "part1"   # (Mandatory) Name of the component to which the module belongs.
     ...
   }
   ```

   ```
   import("//build/ohos.gni")
   ohos_shared_library("module2") {
     ...
     deps = [
       "GN target of module 1",
     ...
    ]                      # Intra-component dependency
   part_name = "part1"   # (Mandatory) Name of the part to which the module belongs.
   }
   ```

- Example of **external_deps**:

   ```
   import("//build/ohos.gni")
   ohos_shared_library("module1") {
     ...
     part_name = "part1"   # (Mandatory) Name of the component to which the module belongs.
     ...
   }
   ```

- **bundle.json** file of the component to which module 1 belongs

   ```
   {
       "name": "@ohos/<component_name>",             # HPM component name, in the "@Organization/Component name" format.
       "description": "xxxxxxxxxxxxxxxx",            # Description of the component functions.
       "version": "3.1",                             # Version, which must be the same as the version of OpenHarmony.
       "license": "MIT",                             # Component license.
       "publishAs": "code-segment",                  # Mode for publishing the HPM package. The default value is code-segment.
       "segment": {
           "destPath": ""
       },                                           # Code restoration path (source code path) when publishAs is code-segment.
       "dirs": {},                                  # Directory structure of the HPM package. This field is mandatory and can be left empty.
       "scripts": {},                               # Scripts to be executed. This field is mandatory and can be left empty.
       "licensePath    "licensePath": "COPYING",
   ": "COPYING",
       "readmePath": {
       "en": "README.rst"
       },
       "component": {                               # Component attributes.
           "name": "<component_name>",              # Component name.
           "subsystem": "",                         # Subsystem to which the component belongs.
           "syscap": [],                            # System capabilities provided by the component for applications.
           "features": [],                          # List of the component's configurable features. Generally, this parameter corresponds to sub_component in build and can be configured.
           "adapted_system_type": [],               # Adapted system types, which can be mini, small, and standard. Multiple values are allowed.
           "rom": "xxxKB"                           # ROM baseline. If there is no baseline, enter the current value.
           "ram": "xxxKB",                          # RAM baseline. If there is no baseline, enter the current value.
           "deps": {
               "components": [],                    # Other components on which this component depends.
               "third_party": []                    # Third-party open-source software on which this component depends.
           },
           "build": {                                # Build-related configurations.
               "sub_component": ["part1"],           # Component build entry. All modules of the component are listed here.
               "inner_kits": [],                    # APIs between components.
           {
             "header": {
               "header_base": "Header file directory",       # Directory of the header files.
               "header_files": [
                   "Header file name"
                 ]                                   # List of header file names.
               },
               "name": "GN target of module 1"
           },
         ],
               "test": []                            # Entry for building the component's test cases.
           }
       }
   }
   ```

   ```
   import("//build/ohos.gni")
   ohos_shared_library("module2") {
     ...
     external_deps = [
       "part1:module1",
     ...
     ]                      # Inter-component dependency. The dependent module must be declared in **inner_kits** by the dependent component.
     part_name = "part2"    # (Mandatory) Name of the component to which the module belongs.
   }

   ```

> ![icon-caution.gif](../public_sys-resources/icon-caution.gif) **CAUTION**<br/>
> The values of **external_deps** are in the *Component name*:*Module name* format. The module name must exist in **inner_kits** of the dependent component.





### How Do I Add a Module to a Standard System?

You may need to:

- Add a module to an existing component.

- Add a module to a new component.

- Add a module to a new subsystem.

#### Adding a Module to an Existing Component

1. Configure the **BUILD.gn** file in the module directory and select the corresponding template.
   
   Follow the procedure for adding a module to an existing component. Note that **part_name** in the **BUILD.gn** file is the name of the existing component.
2. Modify the **bundle.json** file. "GN target of the module in the component"

   ```
   {
       "name": "@ohos/<component_name>,                # HPM component name, in the "@Organization/Component name" format.
       "description": "xxxxxxxxxxxxxxxxxxx",           # Description of the component functions.
       "version": "3.1",                               # Version, which must be the same as the version of OpenHarmony.
       "license": "MIT",                               # Component license.
       "publishAs": "code-segment",                    # Mode for publishing the HPM package. The default value is code-segment.
       "segment": {
           "destPath": "third_party/nghttp2"
       },                                              # Code restoration path (source code path) when publishAs is code-segment.
       "dirs": {},                                     # Directory structure of the HPM package. This field is mandatory and can be left empty.
       "scripts": {},                                  # Scripts to be executed. This field is mandatory and can be left empty.
       "licensePath": "COPYING",
       "readmePath": {
           "en": "README.rst"
       },
       "component": {                                  # Component attributes.
           "name": "<component_name>",                 # Component name.
           "subsystem": "",                            # Subsystem to which the component belongs.
           "syscap": [],                               # System capabilities provided by the component for applications.
           "features": [],                             # List of the component's configurable features. Generally, this parameter corresponds to sub_component in build and can be configured.
           "adapted_system_type": [],                  # Adapted system types, which can be mini, small, and standard. Multiple values are allowed.
           "rom": "xxxKB"                              # ROM baseline. If there is no baseline, enter the current value.
           "ram": "xxxKB",                             # RAM baseline. If there is no baseline, enter the current value.
           "deps": {
               "components": [],                       # Other components on which this component depends.
               "third_party": []                       # Third-party open-source software on which this component depends.
           },
        
           "build": {                                            # Build-related configurations
               "sub_component": [
                   "//foundation/arkui/napi:napi_packages",      # Existing module 1
                   "//foundation/arkui/napi:napi_packages_ndk"   # Existing module 2
                   "//foundation/arkui/napi:new"                 # Module to add
               ],                                                # Component build entry. Configure the module here.
               "inner_kits": [],                                 # APIs between components
               "test": []                                        # Entry for building the component's test cases.
           }
       }
   }
   ```

   Note that the **bundle.json** file must be in the folder of the corresponding subsystem.

#### Creating a Component and Adding a Module

1. Configure the **BUILD.gn** file in the module directory and select the corresponding template. Note that **part_name** in the **BUILD.gn** file is the name of the newly added component.

2. Create a **bundle.json** file in the folder of the corresponding subsystem. 

   The **bundle.json** file consists of two parts: **subsystem** and **parts**. Add the component information to **parts**. When adding a component, you need to specify the **sub_component** of the component. If there are APIs provided for other components, add them in **inner_kits**. If there are test cases, add them in **test**.

3. Add the new component to the end of existing components in **//vendor/{product_company}/{product-name}/config.json**.

   ```
    "subsystems": [
         {
           "subsystem": "Name of the subsystem to which the component belongs",
           "components": [
             {"component": "Component 1 name", "features":[]},        # Existing component 1 in the subsystem
             { "component": "Component 2 name", "features":[] },      # Existing component 2 in the subsystem
             {"component": "New component name", "features":[]}       # New component in the subsystem
           ]
         },
         ...
    ]
   ```

#### Creating a Subsystem and Adding a Module

1. Configure the **BUILD.gn** file in the module directory and select the corresponding template. 

   Note that **part_name** in the **BUILD.gn** file is the name of the newly added component.

2. Create a **bundle.json** file in the folder of the component of the subsystem. 

   This step is the same as the step in "Creating a Component and Adding a Module."

3. Modify the **subsystem_config.json** file in the **build** directory.

   ```
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
   ...
   }
   ```

   This file defines the subsystems and their paths. To add a subsystem, specify **path** and **name** for the subsystem.

4. If **product-name** in the **//vendor/{product_company}/{product-name}** directory is **hispark_taurus_standard**, add the new component information to the end of existing components in the **config.json** file.

   ```
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
           "component": "component_new1",         # Name of the new component added to the existing subsystem
           "features": []
         }
      ]
     },
     {
       "subsystem": "subsystem_new",              # Name of the new subsystem to add
       "components": [
         {
           "component": "component_new2",         # Name of the component added to the new subsystem
           "features": []
         }
       ]
     },
    ...
    ]
   ```
    Verification:
    - Check that **module_list** in the **BUILD.gn** file in the component directory under the corresponding subsystem directory contains the target defined in the **BUILD.gn** file of the new module.
    - Check the .so file or binary file generated in the image created.

#### Configuration Files

There are four OpenHarmony configuration files.

1. **vendor\Product vendor\Product name\config.json**

   ```
   {
      "product_name": "MyProduct",
      "version": "3.0",
      "type": "standard",
      "target_cpu": "arm",
      "ohos_version": "OpenHarmony 1.0",
      "device_company": "MyProductVendor",
      "board": "MySOC",
      "enable_ramdisk": true,
      "subsystems": [
        {
          "subsystem": "ace",
          "components": [
            { "component": "ace_engine_lite", "features":[""] }
          ]
        },
        ...
      ]
   }

   ```
   This file specifies the name, manufacturer, device, version, type of system to be built, and subsystems of the product.

2. **subsystem_config.json** in the **build** directory

   ```
   {
     "arkui": {
       "path": "foundation/arkui",
       "name": "arkui"
     },
     "ai": {
       "path": "foundation/ai",
       "name": "ai"
     },
 	......
    }
   ```
   This file contains subsystem information. You need to configure **name** and **path** for each subsystem.

3. **bundle.json** of a subsystem

   ```
   {
       "name": "@ohos/<component_name>,                # HPM component name, in the "@Organization/Component name" format.
       "description": "xxxxxxxxxxxxxxxxxxx",           # Description of the component functions.
       "version": "3.1",                               # Version, which must be the same as the version of OpenHarmony.
       "license": "MIT",                               # Component license.
       "publishAs": "code-segment",                    # Mode for publishing the HPM package. The default value is code-segment.
       "segment": {
           "destPath": ""
       },                                              # Code restoration path (source code path) when publishAs is code-segment.
       "dirs": {},                                     # Directory structure of the HPM package. This field is mandatory and can be left empty.
       "scripts": {},                                  # Scripts to be executed. This field is mandatory and can be left empty.
       "licensePath": "COPYING",
       "readmePath": {
           "en": "README.rst"
       },
       "component": {                                  # Component attributes.
           "name": "<component_name>",                 # Component name.
           "subsystem": "",                            # Subsystem to which the component belongs.
           "syscap": [],                               # System capabilities provided by the component for applications.
           "features": [],                             # List of the component's configurable features. Generally, this parameter corresponds to sub_component in build and can be configured.
           "adapted_system_type": [],                  # Adapted system types, which can be mini, small, and standard. Multiple values are allowed.
           "rom": "xxxKB"                              # ROM baseline. If there is no baseline, enter the current value.
           "ram": "xxxKB",                             # RAM baseline. If there is no baseline, enter the current value.
           "deps": {
               "components": [],                       # Other components on which this component depends.
               "third_party": []                       # Third-party open-source software on which this component depends.
           },
           "build": {                                  # Build-related configurations.
               "sub_component": ["gn target of the module"], # Component build entry
               "inner_kits": [],                       # APIs between components.
               "test": []                              # Entry for building the component's test cases.
           }
       }
   }
   ```
   The **bundle.json** file defines the components of a subsystem.
   
   Each component contains the module's target **component.build.sub_component**, **component.build.inner_kits** for interaction between components, and test cases **component.build.test_list**. The **component.build.sub_component** is mandatory.

4. **BUILD.gn** of each module
   
   You can create **BUILD.gn** from a template or using the GN syntax.

### How Do I Build a HAP?

#### **HAP Description**

An OpenHarmony Ability Package (HAP) includes resources, raw assets, JS assets, native libraries, and **config.json**.

#### **Templates**

The compilation and build subsystem provides four templates for building HAPs. The templates are integrated in **ohos.gni**. Before using the templates, import **build/ohos.gni**.

1. **ohos_resources**

   This template declares resource targets. After a target is built by restool, an index file is generated. The resource source file and index file are both packaged into the HAP.

   A **ResourceTable.h** file is also generated after resource building. This header file can be referenced if the resource target is relied on.

   The resource target name must end with **resources**, **resource**, or **res**. Otherwise, a build error may occur.

   The following variables are supported:

   - **sources**: a list of resource paths.
   - **hap_profile**: **config.json** of the HAP required for resource building.
   - **deps**: (optional) dependency of the current target.

2. **ohos_assets**

   This template declares asset targets. 

   Beware that the spelling is "assets" as opposed to "assert".

   The asset target name must end with **assets** or **asset**.

   The following variables are supported:

   - **sources**: a list for raw asset paths.
   - **deps**: (optional) dependency of the current target.

3. **ohos_js_assets**

   This template declares a JS resource target. The JS resource is the executable part of an L2 HAP.

   The JS asset target name must end with **assets** or **asset**.

   The following variables are supported:

   - **source_dir**: JS resource path, which is of the string type.
   - **deps**: (optional) dependency of the current target.

4. **ohos_hap**

   This template declares a HAP target. A HAP that will be generated and packaged into the system image.

   The following variables are supported:

   - **hap_profile**: **config.json** of the HAP.
   - **deps**: dependency of the current target.
   - **shared_libraries**: native libraries on which the current target depends.
   - **hap_name**: (optional) name of the HAP. The default value is the target name.
   - **final_hap_path**: (optional) destination path of the HAP. It takes precedence over **hap_name**.
   - **subsystem_name**: name of the subsystem to which the HAP belongs. The value must be the same as that in **bundle.json**. Otherwise, the HAP will fail to be installed in the system image.
   - **part_name**: name of the component to which the HAP belongs. The value must be the same as that in **bundle.json**.
   - **js2abc**: whether to convert the HAP into ARK bytecode. 
   - **certificate_profile**: certificate profile of the HAP, which is used for signature. For details about signatures, see [Configuring Signature Information](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-debugging-and-running-0000001263040487#section17660437768).
   - **certificate_file**: Certificate file. You must apply for the certificate and its profile from the official OpenHarmony website.
   - **keystore_path**: keystore file, which is used for signature.
   - **keystore_password**: keystore password, which is used for signature.
   - **key_alias**: key alias.
   - **module_install_name**: name of the HAP used during installation.
   - **module_install_dir**: installation path. The default path is **system/app**.

**HAP Example**

    ```
    import("//build/ohos.gni") # Import **ohos.gni**.
    ohos_hap("clock") {
      hap_profile = "./src/main/config.json" # config.json
      deps = [
        ":clock_js_assets", # JS assets
        ":clock_resources", # Resources
      ]
      shared_libraries = [
        "//third_party/libpng:libpng", # Native library
      ]
      certificate_profile = "../signature/systemui.p7b" # Certificate profile
      hap_name = "SystemUI-NavigationBar" # HAP name
      part_name = "prebuilt_hap"
      subsystem_name = "applications"
    }
    ohos_js_assets("clock_js_assets") {
      source_dir = "./src/main/js/default"
    }
    ohos_resources("clock_resources") {
      sources = [ "./src/main/resources" ]
      hap_profile = "./src/main/config.json"
    }
    ```

### What Does an Open-Source Software Notice Collect?

#### Information to Collect

The notice collects only the licenses of the modules packaged in the image. For example, the licenses of the tools (such as Clang, Python, and Ninja) used during the build process are not collected.

A static library itself is not packaged. However, if it is packaged into the system as part of a dynamic library or executable file, the license of the static library will be collected for completeness.

The final **Notice.txt** file must include all licenses used by the files in the image and the mapping between modules and licenses.

The **Notice.txt** file is located in the **/system/etc/** directory.

#### Rules for Collecting Information

Licenses are collected by priority.

1. Licenses that are directly declared in a module's **BUILD.gn** are given the top priority. The following is an example:

   ```
      ohos_shared_library("example") {
          ...
          license_file = "path-to-license-file"
          ...
      }
   ```

2. If there is no explicitly declared license, the build script searches for the **Readme.OpenSource** file in the directory of **BUILD.gn**, parses the file, and collects the obtained licenses.
   If the **Readme.OpenSource** file does not contain license information, an error will be reported.

3. If the **Readme.OpenSource** file does not exist, the build script searches for the **License**, **Copyright**, and **Notice** files from the current directory to the root directory of the source code by default. If obtained license information will be used as the licenses of the module.

4. If no license is found, the default license (Apache License 2.0) will be used.

Check items:

1. For third-party open-source software, such as OpenSSL and ICU, **Readme.OpenSource** must be configured in the source code directory. Check whether **Readme.OpenSource** is in the same directory as **BUILD.gn** and whether the license configured in **Readme.OpenSource** is valid.

2. If the source code is not licensed under the Apache License 2.0, the corresponding license file must be provided in the source code directory or declared by **license_file** for the module.

3. If the source code file added to **BUILD.gn** is not from the current directory, check whether the license in the repository where the source code file is located is the same as that in the repository of **BUILD.gn**. License inconsistency entails follow-up operations.
