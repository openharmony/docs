# Component-based Startup
## Overview
### Function Introduction
Builds four basic component images and provides component-based directories, including:
- System component: **system**
- Common product configuration component: **sys_prod**
- Chipset component: **chipset**
- Hardware configuration component: **chip_prod**

Ensures that system parameters and startup scripts can be scanned and initialized by component priority.
Independently compiles and builds the **system** component and **chipset** component.
### Basic Concepts
- Basic Components

   **system**: serves as the file system mount point, and functions as a platform service irrelevant to the chipset and hardware.
   **sys_prod**: extends and customizes capabilities of the **system** component, bears product-level differentiated capabilities, and stores product-related configuration files.
   **chipset**: serves as the file system mount point, and offers unified hardware abstraction services for the **system** component. Same chipset platforms can use the same **chipset** component.
   **chip_prod**: offers specific hardware capabilities of a peripheral board and product-level differentiated hardware configurations, as well as chipset-related configuration files.

- Component-based compilation and building

  Use **target_cpu** to specify the instruction set of the **system** component. Use **inherit** to inherit the common component set such as **base**, **headless**, and **rich**. Use **subsystems** to define more components for a specific product type.

- System parameters and startup scripts scanned and initialized by component priority

  System parameters and startup scripts include the CFG configuration file, PARAM file, sandbox JSON configuration file, and module plugin library file of a service. The following are related files that are in ascending order in terms of priority: **/system**, **/chipset**, **/sys_prod**, and **/chip_prod**. A file with a higher priority replaces and updates the configuration file with a lower priority.


### Constraints
Standard and small systems support component-based compilation and building. System parameters and startup scripts are scanned and initialized by component priority.

## Vibrator Development
### When to Use
Component-based startup enables vendors and hardware platforms to quickly develop products through modular combination. The following uses RK3568 as an example to illustrate component-based startup in detail.

### Building and Compiling RK3568 Based on Components
The **//vendor/hihope/rk3568/config.json** configuration file implements components required for building the product:

        {
          "product_name": "rk3568",
          "device_company": "rockchip",
          ...
          "target_cpu": "arm",
          ...
          "inherit": [ "productdefine/common/inherit/rich.json", "productdefine/common/inherit/chipset_common.json" ],
          "subsystems": [
            {
              "subsystem": "security",
              "components": [
                {
                  "component": "selinux",
                  "features": []
                }
              ]
            }
          ...
        }

The example above indicates the product name, chipset vendor, supported instruction set, and more. **inherit** indicates the dependent common components, and **subsystems** indicates other components.
The following illustrates the configuration of the **system** component in the **//productdefine/common/inherit/rich.json** file. The **system** component can also include **base.json** (list of minimal components that all products must contain) and **headless.json** (list of minimal components with which products having no UI allow for application installation and management).

    {
      "version": "3.0",
      "subsystems": [
      {
        "subsystem": "arkui",
        "components": [
          {
            "component": "ace_engine",
            "features": []
          },
          {
            "component": "napi",
            "features": []
          }
        ]
      },
      {
        "subsystem": "account",
        "components": [
          {
            "component": "os_account",
            "features": []
          }
        ]
      },
      ...
    }

### Scanning and Initializing System Parameters by Priority
The following are CFG files of a service, which are in ascending order in terms of priority: **/system/etc**, **/system/etc/init**, and **/chipset/etc**. A file with a higher priority replaces and updates the configuration file with a lower priority. The following uses **/system/etc/init/camera_service.cfg** as an example:

      {
        "services" : [{
            "name" : "camera_service",
            "path" : ["/system/bin/sa_main", "/system/profile/camera_service.xml"],
            "uid" : "cameraserver",
            "gid" : ["system", "shell"],
            "secon" : "u:r:camera_service:s0",
            "permission" : ["ohos.permission.GET_SENSITIVE_PERMISSIONS"],
            "permission_acls" : ["ohos.permission.GET_SENSITIVE_PERMISSIONS"]
        }]
      }  

**/chipset/etc/camera_B_service.cfg** exists at the same time.

       {
        "services" : [{
            "name" : "camera_service",
            "path" : ["/system/bin/sa_main", "/system/profile/camera_B_service.xml"],
            "uid" : "cameraserver",
            "gid" : ["system", "shell"],
            "secon" : "u:r:camera_service:s0",
            "permission" : ["ohos.permission.GET_SENSITIVE_PERMISSIONS"],
            "permission_acls" : ["ohos.permission.GET_SENSITIVE_PERMISSIONS"],
            "disabled" : 1
        }]
      }  

Based on the priority requirement, the **path** attribute of the **camera_service** service will be replaced by **["/system/bin/sa_main", "/system/profile/camera_B_service.xml"]** that has a higher priority, and the **disabled** attribute is added.
