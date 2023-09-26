# Component
### Configuration Rules

The **bundle.json** file of a component is stored in the root directory of the component source code. The following example shows how to configure the sensor service component of the pan-sensor subsystem:

```shell
{
    "name": "@ohos/sensor_lite",		                                 # OpenHarmony Package Manager (HPM) component name, in the "@Organization/Component name" format.
    "description": "Sensor services",		                             # Description of the component function.
    "version": "3.1",			                                         # Version, which must be the same as the version of OpenHarmony.
    "license": "MIT",			                                         # Component license.
    "publishAs": "code-segment", 		                                 # HPM package release mode. The default value is code-segment.
    "segment": {										
        "destPath": ""			
    },					                                                 # Code restoration path (source code path) set when publishAs is code-segment.
    "dirs": {"base/sensors/sensor_lite"},	                             # Directory structure of the HPM package. This field is mandatory and can be left empty.
    "scripts": {},			                                             # Scripts to be executed. This field is mandatory and can be left empty.
    "licensePath": "COPYING",			
    "readmePath": {
        "en": "README.rst"
    },
    "component": { 			                                             # Component attributes.
        "name": "sensor_lite",			                                 # Component name.
        "subsystem": "",		                                         # Subsystem to which the component belongs.
        "syscap": [], 				                                     # System capabilities provided by the component for applications.
        "features": [],                                                  # List of external configurable features of the component. Generally, this parameter corresponds to sub_component in build.
        "adapted_system_type": [],		                                 # Types of adapted systems, which can be mini, small, standard, or their combinations.
        "rom": "92KB",                                                   # Component ROM size.
        "ram": "~200KB",                                                 # Component RAM size.
        "deps": {                      
        "components": [                                                  # Other components on which this component depends.
          "samgr_lite",
          "ipc_lite"
        ],
        "third_party": [                                                 # Third-party open-source software on which this component depends.
          "bounds_checking_function"
        ],
        "hisysevent_config": []                                          # Build entry of the HiSysEvent configuration file.
      }         
        "build": {				                                         # Build-related configurations.
            "sub_component": [
                ""//base/sensors/sensor_lite/services:sensor_service"",  # Component build entry.
            ],			                                                 # Component build entry. Configure modules here.
            "inner_kits": [],						                     # APIs between components.
            "test": [] 						                             # Entry for building the component's test cases.
        }
    }
 }
```

> **CAUTION**
>
> Existing components on the LiteOS are configured in the JSON file of the corresponding subsystem in the **build/lite/components** directory. The directory is named in the **{Domain}/{Subsystem}/{Component}** format. The component directory structure is as follows:

```shell
component
├── interfaces
│   ├── innerkits  # APIs exposed internally among components
│   └── kits       # APIs provided for application developers
├── frameworks     # Framework implementation
├── services       # Service implementation
├── BUILD.gn       # Build script
```

You need to configure the component name, source code path, function description, mandatory or not, build target, RAM, ROM, output, adapted kernel, configurable features, and dependencies.

> **NOTE**
>
> For details about how to use the HiSysEvent configuration file in component configuration, see [HiSysEvent Logging Configuration](subsys-dfx-hisysevent-logging-config.md).

When adding a component, you must add the component definition to the JSON file of the corresponding subsystem. The component configured for a product must have been defined in a subsystem. Otherwise, the verification will fail.

### Adding and Building a Component

1. Add a component.

   The following use a custom component as an example to describe how to compile a library, executable file, and configuration file.

   In this example, **partA** consists of **feature1**, **feature2**, and **feature3**, which represent a dynamic library, an executable file, and an etc configuration file, respectively.

   Add **partA** to a subsystem, for example, **subsystem_examples** (defined in the **test/examples/** directory).

   The directory structure of **partA** is as follows:

   ```shell
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

   (a) Configure **test/examples/partA/feature1/BUILD.gn** for the dynamic library.

   ```shell
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

   (b) Configure **test/examples/partA/feature2/BUILD.gn** for the executable file.

   ```shell
   ohos_executable("helloworld_bin") {
     sources = [
       "src/helloworld2.cpp"
     ]
     include_dirs = [ "include" ]
     deps = [                                # Dependent modules in the component
       "../feature1:helloworld_lib"
     ]
     external_deps = [ "partB:module1" ]     # (Optional) Dependent modules of another component are named in the Component name:Module name format.
     install_enable = true                   # By default, executable programs are not installed. Set this parameter to true if an executable program needs to be installed.
     part_name = "partA"
   }
   ```

   (c) Configure **test/examples/partA/feature3/BUILD.gn** for the etc module.

   ```shell
   ohos_prebuilt_etc("feature3_etc") {
     source = "src/config.conf"
     relative_install_dir = "init"    # (Optional) Relative directory for installing the module. The default installation directory is /system/etc.
     part_name = "partA"
   }
   ```

   (d) Add the module configuration **test/examples/bundle.json** to the **bundle.json** file of the component. Each component has a **bundle.json** file in the root directory of the component. For details, see the [component bundle.json file](subsys-build-component.md#configuration-rules).

2. Add the component to the product configuration file.

    Add the component to **//vendor/{*product_company*}/{*product_name*}/config.json**.

    The following uses **vendor/hisilicon/hispark_taurus_standard/config.json** as an example:

    ```shell
      {
        "product_name": "hispark_taurus_standard",
        "device_company": "hisilicon",
        "device_build_path": "device/board/hisilicon/hispark_taurus/linux",
        "target_cpu": "arm",
        "type": "standard",
        "version": "3.0",
        "board": "hispark_taurus",
        "inherit": [ "productdefine/common/base/standard_system.json",
                    "productdefine/common/inherit/ipcamera.json"
        ],
        "enable_ramdisk": true,
        "subsystems": [
          {
            "subsystem": "subsystem_examples",                              # Subsystem to which the component belongs.
            "components": [
              {
                "component": "partA",                                       # Component name.
                "features": []                                              # Configurable features of the component.
              }
            ]
          },
        ···
      }
    ```

    The configuration file contains information about the the product name and chip vendor. **inherit** specifies the dependent, and **subsystems** specifies the components other than the common components.

    For example, add "subsystem_examples:partA" to the product **config.json** file. Then, **partA** will be built and packaged into the distribution.

3. Start the build.

   You can start the build by using the [CLI or hb tool](subsys-build-all.md#build-commands). The following uses the CLI as an example:

   You can run '**--build-target *componentName***' to build a component separately. For example, to build the musl component of hispark_taurus_standard, run the following command:

   ```
   ./build.sh --product-name hispark_taurus_standard --build-target musl --ccache
   ```

   You can also build a product. For example, to build hispark_taurus_standard, run the following command:

   ```shell
   ./build.sh --product-name hispark_taurus_standard --ccache
   ```

4. Obtain the build result.

    You can obtain the generated files from the **out/hispark_taurus/** directory and the image in the **out/hispark_taurus/packages/phone/images/** directory.
