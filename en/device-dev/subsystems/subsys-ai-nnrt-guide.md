# NNRt Development

## Overview

### Function Introduction

Neural Network Runtime (NNRt) functions as a bridge to connect the upper-layer AI inference framework and bottom-layer acceleration chips, implementing cross-chip inference computing of AI models.

With the open APIs provided by NNRt, chip vendors can connect their dedicated acceleration chips to NNRt to access the OpenHarmony ecosystem.

### Basic Concepts
Before you get started, it would be helpful for you to have a basic understanding of the following concepts:

- Hardware Device Interface (HDI): defines APIs for cross-process communication between services in OpenHarmony.
- Interface Description Language (IDL): defines the HDI language format.

### Constraints
- System version: OpenHarmony trunk version.
- Development environment: Ubuntu 18.04 or later.
- Access device: a chip with AI computing capabilities.

### Working Principles
NNRt connects to device chips through HDIs, which implement cross-process communication between services.

**Figure 1** NNRt architecture

![NNRt architecture](./figures/nnrt_arch_diagram.png)

The NNRt architecture consists of three layers: AI applications at the application layer, AI inference framework and NNRt at the system layer, and device services at the chip layer. To use a dedicated acceleration chip model for inference, an AI application needs to call the dedicated acceleration chip at the bottom layer through the AI inference framework and NNRt. NNRt is responsible for adapting to various dedicated acceleration chips at the bottom layer. It opens standard and unified HDIs for various chips to access the OpenHarmony ecosystem.

During program running, the AI application, AI inference framework, and NNRt reside in the user process, and the underlying device services reside in the service process. NNRt implements the HDI client and the service side implements HDI Service to fulfill cross-process communication.

## How to Develop

### Application Scenario
Suppose you are connecting an AI acceleration chip, for example, RK3568, to NNRt. The following describes how to connect the RK3568 chip to NNRt through the HDI to implement AI model inference.
> **NOTE**<br>In this application scenario, the connection of the RK3568 chip to NNRt is implemented by utilizing the CPU operator of MindSpore Lite, instead of writing the CPU driver. This is the reason why the following development procedure depends on the dynamic library and header file of MindSpore Lite. In practice, the development does not depend on any library or header file of MindSpore Lite.

### Development Flowchart
The following figure shows the process of connecting a dedicated acceleration chip to NNRt.

**Figure 2** NNRt development flowchart

![NNRt development flowchart](./figures/nnrt_dev_flow.png)

### Development Procedure
To connect the acceleration chip to NNRt, perform the development procedure below.
#### Generating the HDI Header File
Download the OpenHarmony source code from the open source community, build the `drivers_interface` component, and generate the HDI header file.

1. [Download the source code](../get-code/sourcecode-acquire.md).

2. Build the IDL file of the HDI.
    ```shell
    ./build.sh --product-name productname –ccache --build-target drivers_interface_nnrt
    ```
    > **NOTE**<br>**productname** indicates the product name. In this example, the product name is **RK3568**.

    When the build is complete, the HDI header file is generated in `out/rk3568/gen/drivers/interface/nnrt`. The default programming language is C++. To generate a header file for the C programming language, run the following command to set the `language` field in the `drivers/interface/nnrt/v1_0/BUILD.gn` file before starting the build:

    ```shell
    language = "c"
    ```

    The directory of the generated header file is as follows:
    ```text
    out/rk3568/gen/drivers/interface/nnrt
    └── v1_0
        ├── drivers_interface_nnrt__libnnrt_proxy_1.0_external_deps_temp.json
        ├── drivers_interface_nnrt__libnnrt_stub_1.0_external_deps_temp.json
        ├── innrt_device.h                        # Header file of the HDI
        ├── iprepared_model.h                     # Header file of the AI model
        ├── libnnrt_proxy_1.0__notice.d
        ├── libnnrt_stub_1.0__notice.d
        ├── model_types.cpp                       # Implementation file for AI model structure definition
        ├── model_types.h                         # Header file for AI model structure definition
        ├── nnrt_device_driver.cpp                # Device driver implementation example
        ├── nnrt_device_proxy.cpp
        ├── nnrt_device_proxy.h
        ├── nnrt_device_service.cpp               # Implementation file for device services
        ├── nnrt_device_service.h                 # Header file for device services
        ├── nnrt_device_stub.cpp
        ├── nnrt_device_stub.h
        ├── nnrt_types.cpp                        # Implementation file for data type definition
        ├── nnrt_types.h                          # Header file for data type definition
        ├── node_attr_types.cpp                   # Implementation file for AI model operator attribute definition
        ├── node_attr_types.h                     # Header file for AI model operator attribute definition
        ├── prepared_model_proxy.cpp
        ├── prepared_model_proxy.h
        ├── prepared_model_service.cpp            # Implementation file for AI model services
        ├── prepared_model_service.h              # Header file for AI model services
        ├── prepared_model_stub.cpp
        └── prepared_model_stub.h
    ```

#### Implementing the HDI Service

1. Create a development directory in `drivers/peripheral`. The structure of the development directory is as follows:
    ```text
    drivers/peripheral/nnrt
    ├── BUILD.gn                                  # Code build script
    ├── bundle.json
    └── hdi_cpu_service                           # Customized directory
        ├── BUILD.gn                              # Code build script
        ├── include
        │   ├── nnrt_device_service.h             # Header file for device services
        │   ├── node_functions.h                  # Optional, depending on the actual implementation
        │   ├── node_registry.h                   # Optional, depending on the actual implementation
        │   └── prepared_model_service.h          # Header file for AI model services
        └── src
            ├── nnrt_device_driver.cpp            # Implementation file for the device driver
            ├── nnrt_device_service.cpp           # Implementation file for device services
            ├── nnrt_device_stub.cpp              # Optional, depending on the actual implementation
            ├── node_attr_types.cpp               # Optional, depending on the actual implementation
            ├── node_functions.cpp                # Optional, depending on the actual implementation
            ├── node_registry.cpp                 # Optional, depending on the actual implementation
            └── prepared_model_service.cpp        # Implementation file for AI model services
    ```

2. Implement the device driver. Unless otherwise required, you can directly use the `nnrt_device_driver.cpp` file generated in step 1.

3. Implement service APIs. For details, see the `nnrt_device_service.cpp` and `prepared_model_service.cpp` implementation files. For details about the API definition, see [NNRt HDI Definitions](https://gitee.com/openharmony/drivers_interface/tree/master/nnrt).

4. Build the implementation files for device drivers and services as shared libraries.

    Create the `BUILD.gn` file with the following content in `drivers/peripheral/nnrt/hdi_cpu_service/`. For details about how to set related parameters, see [Compilation and Building](https://gitee.com/openharmony/build).

    ```shell
    import("//build/ohos.gni")
    import("//drivers/hdf_core/adapter/uhdf2/uhdf.gni")

    ohos_shared_library("libnnrt_service_1.0") {
      include_dirs = []
      sources = [
        "src/nnrt_device_service.cpp",
        "src/prepared_model_service.cpp",
        "src/node_registry.cpp",
        "src/node_functions.cpp",
        "src/node_attr_types.cpp"
      ]
      public_deps = [ "//drivers/interface/nnrt/v1_0:nnrt_idl_headers" ]
      external_deps = [
        "hdf_core:libhdf_utils",
        "hiviewdfx_hilog_native:libhilog",
        "ipc:ipc_single",
        "c_utils:utils",
      ]

      install_images = [ chipset_base_dir ]
      subsystem_name = "hdf"
      part_name = "drivers_peripheral_nnrt"
    }

    ohos_shared_library("libnnrt_driver") {
      include_dirs = []
      sources = [ "src/nnr_device_driver.cpp" ]
      deps = [ "//drivers/peripheral/nnrt/hdi_cpu_service:libnnrt_service_1.0" ]

      external_deps = [
        "hdf_core:libhdf_host",
        "hdf_core:libhdf_ipc_adapter",
        "hdf_core:libhdf_utils",
        "hiviewdfx_hilog_native:libhilog",
        "ipc:ipc_single",
        "c_utils:utils",
      ]

      install_images = [ chipset_base_dir ]
      subsystem_name = "hdf"
      part_name = "drivers_peripheral_nnrt"
    }

    group("hdf_nnrt_service") {
      deps = [
        ":libnnrt_driver",
        ":libnnrt_service_1.0",
      ]
    }
    ```

    Add `group("hdf_nnrt_service")` to the `drivers/peripheral/nnrt/BUILD.gn` file so that it can be referenced at a higher directory level.
    ```shell
    if (defined(ohos_lite)) {
      group("nnrt_entry") {
        deps = [ ]
      }
    } else {
      group("nnrt_entry") {
        deps = [
          "./hdi_cpu_service:hdf_nnrt_service",
        ]
      }
    }
    ```

    Create the `drivers/peripheral/nnrt/bundle.json` file to define the new `drivers_peripheral_nnrt` component.
    ```json
    {
      "name": "drivers_peripheral_nnrt",
      "description": "Neural network runtime device driver",
      "version": "3.2",
      "license": "Apache License 2.0",
      "component": {
        "name": "drivers_peripheral_nnrt",
        "subsystem": "hdf",
        "syscap": [""],
        "adapter_system_type": ["standard"],
        "rom": "1024KB",
        "ram": "2048KB",
        "deps": {
          "components": [
            "ipc",
            "hdf_core",
            "hiviewdfx_hilog_native",
            "c_utils"
          ],
          "third_part": [
            "bounds_checking_function"
          ]
        },
        "build": {
          "sub_component": [
            "//drivers/peripheral/nnrt:nnrt_entry"
          ],
          "test": [
          ],
          "inner_kits": [
          ]
        }
      }
    }
    ```

#### Declaring the HDI Service

  In the uhdf directory, declare the user-mode driver and services in the **.hcs** file of the corresponding product. For example, for the RK3568 chip, add the following configuration to the `vendor/hihope/rk3568/hdf_config/uhdf/device_info.hcs` file:
  ```text
  nnrt :: host {
      hostName = "nnrt_host";
      priority = 50;
      uid = "";
      gid = "";
      caps = ["DAC_OVERRIDE", "DAC_READ_SEARCH"];
      nnrt_device :: device {
          device0 :: deviceNode {
              policy = 2;
              priority = 100;
              moduleName = "libnnrt_driver.z.so";
              serviceName = "nnrt_device_service";
          }
      }
  }
  ```
> **NOTE**<br>After modifying the `.hcs` file, you need to delete the `out` directory and build the file again for the modification to take effect.

#### Configuring the User ID and Group ID of the Host Process
  In the scenario of creating an nnrt_host process, you need to configure the user ID and group ID of the corresponding process. The user ID is configured in the `base/startup/init/services/etc/passwd` file, and the group ID is configured in the `base/startup/init/services/etc/group` file.
  ```text
  # Add the user ID in base/startup/init/services/etc/passwd.
  nnrt_host:x:3311:3311:::/bin/false

  # Add the group ID in base/startup/init/services/etc/group.
  nnrt_host:x:3311:
  ```

#### Configuring SELinux

The SELinux feature has been enabled for the OpenHarmony. You need to configure SELinux rules for the new processes and services so that they can run the host process to access certain resources and release HDI services.

1. Configure the security context of the **nnrt_host** process in the `base/security/selinux/sepolicy/ohos_policy/drivers/adapter/vendor/type.te` file.
    ```text
    # Add the security context configuration.
    type nnrt_host, hdfdomain, domain;
    ```
    > In the preceding command, **nnrt_host** indicates the process name previously configured.

2. Configure access permissions because SELinux uses the trustlist access permission mechanism. Upon service startup, run the `dmesg` command to view the AVC alarm,
which provides a list of missing permissions. For details about the SELinux configuration, see [security_selinux] (https://gitee.com/openharmony/security_selinux/blob/master/README-en.md).
    ```shell
    hdc_std shell
    dmesg | grep nnrt
    ```

3. Create the `nnrt_host.te` file.
    ```shell
    # Create the nnrt folder.
    mkdir base/security/selinux/sepolicy/ohos_policy/drivers/peripheral/nnrt

    # Create the vendor folder.
    mkdir base/security/selinux/sepolicy/ohos_policy/drivers/peripheral/nnrt/vendor

    # Create the nnrt_host.te file.
    touch base/security/selinux/sepolicy/ohos_policy/drivers/peripheral/nnrt/vendor/nnrt_host.te
    ```

4. Add the required permissions to the `nnrt_host.te` file. For example:
    ```text
    allow nnrt_host dev_hdf_kevent:chr_file { ioctl };
    allow nnrt_host hilog_param:file { read };
    allow nnrt_host sh:binder { transfer };
    allow nnrt_host dev_ashmem_file:chr_file { open };
    allow sh nnrt_host:fd { use };
    ```

#### Configuring the Component Build Entry
Access the `chipset_common.json` file.
```shell
vim //productdefine/common/inherit/chipset_common.json
```
Add the following to `"subsystems"`, `"subsystem":"hdf"`, `"components"`:
```shell
{
  "component": "drivers_peripheral_foo",
  "features": []
}
```

#### Deleting the out Directory and Building the Entire System
```shell
# Delete the out directory.
rm -rf ./out

# Build the entire system.
./build.sh --product-name rk3568 –ccache --jobs=4
```


### Commissioning and Verification
On completion of service development, you can use XTS to verify its basic functions and compatibility.

1. Build the **hats** test cases of NNRt in the `test/xts/hats/hdf/nnrt` directory.
    ```shell
    # Go to the hats directory.
    cd test/xts/hats

    # Build the hats test cases.
    ./build.sh suite=hats system_size=standard --product-name rk3568

    # Return to the root directory.
    cd -
    ```
    The hats test cases are exported to `out/rk3568/suites/hats/testcases/HatsHdfNnrtFunctionTest` in the relative code root directory.

2. Push the test cases to the device.
    ```shell
    # Push the executable file of test cases to the device. In this example, the executable file is HatsHdfNnrtFunctionTest.
    hdc_std file send out/rk3568/suites/hats/testcases/HartsHdfNnrtFunctionTest /data/local/tmp/

    # Grant required permissions to the executable file of test cases.
    hdc_std shell "chmod +x /data/local/tmp/HatsHdfNnrtFunctionTest"
    ```

3. Execute the test cases and view the result.
    ```shell
    # Execute the test cases.
    hdc_std shell "/data/local/tmp/HatsHdfNnrtFunctionTest"
    ```

    The test report below shows that all 47 test cases are successful, indicating that the service has passed the compatibility test.
    ```text
    ...
    [----------] Global test environment tear-down
    Gtest xml output finished
    [==========] 47 tests from 3 test suites ran. (515 ms total)
    [  PASSED  ] 47 tests.
    ```

### Development Example
For the complete demo code, see [NNRt Service Implementation Example](https://gitee.com/openharmony/ai_neural_network_runtime/tree/master/example/drivers).

1. Copy the `example/driver/nnrt` directory to `drivers/peripheral`.
    ```shell
    cp -r example/driver/nnrt drivers/peripheral
    ```

2. Add the `bundle.json` file to `drivers/peripheral/nnrt`. For details about the `bundle.json` file, see [Development Procedure](#development-procedure).

3. Add the dependency files of MindSpore Lite because the demo depends on the CPU operator of MindSpore Lite.
    - Download the header file of [MindSpore Lite 1.5.0](https://ms-release.obs.cn-north-4.myhuaweicloud.com/1.5.0/MindSpore/lite/release/linux/mindspore-lite-1.5.0-linux-x64.tar.gz).
    - Create the `mindspore` directory in `drivers/peripheral/nnrt`.
      ```shell
      mkdir drivers/peripheral/nnrt/mindspore
      ```
    - Decompress the `mindspore-lite-1.5.0-linux-x64.tar.gz` file, and copy the `runtime/include` directory to `drivers/peripheral/nnrt/mindspore`.
    - Create and copy the `schema` file of MindSpore Lite.
      ```shell
      # Create the mindspore_schema directory.
      mkdir drivers/peripheral/nnrt/hdi_cpu_service/include/mindspore_schema

      # Copy the schema file of MindSpore Lite.
      cp third_party/mindspore/mindspore/lite/schema/* drivers/peripheral/nnrt/hdi_cpu_service/include/mindspore_schema/
      ```
    - Build the dynamic library of MindSpore Lite, and put the dynamic library in the `mindspore`directory.
      ```shell
      # Build the dynamic library of MindSpore Lite.
      ./build.sh --product-name rk3568 -ccaache --jobs 4 --build-target mindspore_lib

      # Create the mindspore subdirectory.
      mkdir drivers/peripheral/nnrt/mindspore/mindspore

      # Copy the dynamic library to drivers/peripheral/nnrt/mindspore/mindspore.
      cp out/rk3568/package/phone/system/lib/libmindspore-lite.huawei.so drivers/peripheral/nnrt/mindspore/mindspore/
      ```
4. Follow the [development procedure](#development-procedure) to complete other configurations.
