# Writing a Hello World Program


The following exemplifies how to run the first program on the development board. The created program outputs the message "Hello World!"


## Example Directory

The complete code directory is as follows:


```
applications/sample/hello
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

Perform the steps below in the source code directory:

1. Create a directory and write the service code.
   
   Create the **applications/sample/hello/src/helloworld.c** directory and file whose code is shown in the following example. You can customize the content to be printed. For example, you can change **World** to **OHOS**. Declare the string printing function **HelloPrint** in the **helloworld.h** file. You can use either C or C++ to develop a program.

   
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

   Add the header file **applications/sample/hello/include/helloworld.h**. The sample code is as follows:

   
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
   1. Create the **applications/sample/hello/BUILD.gn** file. The file content is as follows:
      
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
   2. Create the **applications/sample/hello/bundle.json** file and add the description of the **sample** component. The content is as follows:
      
       ```
       {
           "name": "@ohos/hello",
           "description": "Hello world example.",
           "version": "3.1",
           "license": "Apache License 2.0",
           "publishAs": "code-segment",
           "segment": {
               "destPath": "applications/sample/hello"
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
                       "//applications/sample/hello:helloworld"
                   ],
                   "inner_kits": [],
                   "test": []
               }
           }
       }
       ```

       The **bundle.json** file consists of two parts. The first part describes the information about the subsystem to which the component belongs, and the second part defines the build configuration for the component. When adding a component, you must specify the **sub_component** of the component. If there are APIs provided for other components, add them in **inner_kits**. If there are test cases, add them in **test**.

3. Modify the subsystem configuration file.
   
   Add the configuration of the new subsystem to the **build/subsystem_config.json** file.

   
   ```
   "sample": {
       "path": "applications/sample/hello",
       "name": "sample"
     },
   ```

4. Modify the product configuration file.
   
   In the **vendor/hihope/rk3568/config.json** file, add the **hello** part after the existing part.
   
   ```
       "usb:usb_manager_native":{},
       "applications:prebuilt_hap":{},
       "sample:hello":{},
       "wpa_supplicant-2.9:wpa_supplicant-2.9":{},
   ```
