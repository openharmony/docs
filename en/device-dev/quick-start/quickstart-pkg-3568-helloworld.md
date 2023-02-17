# Writing a Hello World Program


The following exemplifies how to run the first program on the development board. The created program outputs the message "Hello World!".



## Example Directory

Obtain the OpenHarmony project code. From the source code root directory, add the **sample/hello** directory, and then create therein the **hello** source code directory, the build file **BUILD.gn**, and the component configuration file **bundle.json**.
The complete code directory is as follows:


```
sample/hello
│── BUILD.gn
│── include
│   └── helloworld.h
│── src
│   └── helloworld.c
├── bundle.json
build
└── subsystem_config.json
vendor/hihope
└── rk3568
    └── config.json
```


## How to Develop

Perform the steps below in the source code root directory:

1. Create a directory and write the service code.
   
   Create the **sample/hello/src/helloworld.c** file, with the sample code as follows. In this example, the content to be printed is **World**, which you can change to any string that you prefer, for example, **OHOS**. The print function **HelloPrint** is declared in the included **helloworld.h** file. You can use either C or C++ to develop a program.

   
   ```
   #include <stdio.h>
   #include "helloworld.h"
   
   int main(int argc, char **argv)
   {
       HelloPrint();
       return 0;
   }
   
   void HelloPrint()
   {
       printf("\n\n");
       printf("\n\t\tHello World!\n");
       printf("\n\n");
   }
   ```

   Add the header file **sample/hello/include/helloworld.h**. The sample code is as follows:

   
   ```
   #ifndef HELLOWORLD_H
   #define HELLOWORLD_H
   #ifdef __cplusplus
   #if __cplusplus
   extern "C" {
   #endif
   #endif
   
   void HelloPrint();
   
   #ifdef __cplusplus
   #if __cplusplus
   }
   #endif
   #endif
   #endif // HELLOWORLD_H
   ```

2. Create a build file.

   Create the **sample/hello/BUILD.gn** file. For details, see [Module](../subsystems/subsys-build-module.md).
   
   The content of the **BUILD.gn** file is as follows:
   
   ```
   import("//build/ohos.gni") # Import the build template.
   ohos_executable("helloworld") {# Executable module.
     sources = [       # Source code of the module.
       "src/helloworld.c"
     ]
     include_dirs = [  # Directory of header files on which the module depends.
       "include" 
     ]
     cflags = []
     cflags_c = []
     cflags_cc = []
     ldflags = []
     configs = []
     deps =[]    # Internal dependencies of a component.
     part_name = "hello"    # Component name. This parameter is mandatory.
     install_enable = true # Whether to install the software by default. This parameter is optional. By default, the software is not installed.
   }
   ```

3. Create a component configuration file.

   Create the **sample/hello/bundle.json** file and add the **sample** component description therein. For details, see [Component](../subsystems/subsys-build-component.md).
   
   The content of the **bundle.json** file is as follows:
   
   ```
   {
       "name": "@ohos/hello",
       "description": "Hello world example.",
       "version": "3.1",
       "license": "Apache License 2.0",
       "publishAs": "code-segment",
       "segment": {
           "destPath": "sample/hello"
       },
       "dirs": {},
       "scripts": {},
       "component": {
           "name": "hello",
           "subsystem": "sample",
           "syscap": [],
           "features": [],
           "adapted_system_type": [ "mini", "small", "standard" ],
           "rom": "10KB",
           "ram": "10KB",
           "deps": {
               "components": [],
               "third_party": []
           },
           "build": {
               "sub_component": [
                   "//sample/hello:helloworld"
               ],
               "inner_kits": [],
               "test": []
           }
       }
   }
   ```

   The **bundle.json** file consists of two parts. The first part describes the information about the subsystem to which the component belongs, and the second part defines the build configuration for the component. When adding a component, you must specify the **sub_component** of the component. Add the APIs provided for other components, if any, in **inner_kits**. Add the test cases, if any, in **test**.

4. Modify the subsystem configuration file.
   
   Add the configuration of the new subsystem to the **build/subsystem_config.json** file. For details, see [Subsystem](../subsystems/subsys-build-subsystem.md).
                                                                                                                                                       
   The configuration of the new subsystem is as follows:
   
   ```
   "sample": {
       "path": "sample",
       "name": "sample"
     },
   ```

5. Modify the product configuration file.

      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
      >
      > In versions earlier than OpenHarmony-v3.2-Beta2, the RK3568 configuration file is **productdefine/common/products/rk3568.json**. In OpenHarmony-v3.2-Beta2 and later versions, the RK3568 configuration file is **vendor/hihope/rk3568/config.json**.
   
   - Versions earlier than OpenHarmony-v3.2-Beta2
                                                                                                                                                       
      In the **productdefine/common/products/rk3568.json** file, add the **hello** part after the existing part.
   
       ```
       "usb:usb_manager_native":{},
       "applications:prebuilt_hap":{},
       "sample:hello":{},
       "wpa_supplicant-2.9:wpa_supplicant-2.9":{},
       ```
   
   - OpenHarmony-v3.2-Beta2 and later versions
                                                                                                                                                       
     
     In the **vendor/hihope/rk3568/config.json** file, add the **hello** part after the existing part.
     
         ```
         {
           "subsystem": "sample",
           "components": [
             {
               "component": "hello",
               "features": []
             }
           ]
         },     
         ```
