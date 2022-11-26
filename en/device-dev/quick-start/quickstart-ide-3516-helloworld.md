# Writing a Hello World Program


The following exemplifies how to run the first program on the development board. The created program outputs the message "Hello World!"


## Prerequisites

A project for the Hi3516 development board has been created as instructed in [Creating a Project and Obtaining Source Code](quickstart-ide-import-project.md).


## Example Directory

The complete code directory is as follows:



```
applications/sample/hello
│── BUILD.gn
└── src
    └── helloworld.c
```


## How to Develop

Perform the steps below in the source code directory:

1. Create a directory and the program source code.
   
   Create the **applications/sample/hello/src/helloworld.c** directory and file whose code is shown in the following example. You can customize the content to be printed. For example, you can change **OHOS** to **World**. You can use either C or C++ to develop a program.

   
   ```
   #include <stdio.h>
   
   int main(int argc, char **argv)
   {
       printf("\n\n");
       printf("\n\t\tHello OHOS!\n");
       printf("\n\n\n");
   
       return 0;
   }
   ```

2. Create a build file.
  
   Create the **applications/sample/hello/BUILD.gn** file. The file content is as follows:

   
   ```
   import("//build/lite/config/component/lite_component.gni")
   lite_component("hello-OHOS") {
     features = [ ":helloworld" ]
   }
   executable("helloworld") {
     output_name = "helloworld"
     sources = [ "src/helloworld.c" ]
   }
   ```

3. Add a component.
   
   Modify the **build/lite/components/applications.json** file and add the configuration of **hello_world_app**. The following code snippet is a snippet of the **applications.json** file, where the configuration between **\#\#start\#\#** and **\#\#end\#\#** is the new entry. (The **\#\#start\#\#** and **\#\#end\#\#** lines are only used to identify the location. After the configuration is complete, delete these lines.)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > In this example, the OpenHarmony-v3.1-Release version is used, where the component configuration file is **build/lite/components/applications.json**. In OpenHarmony-v3.2-Beta2 and later versions, the component configuration file is **build/lite/components/communication.json**.
   
   
   ```
   {
     "components": [
       {
         "component": "camera_sample_communication",
         "description": "Communication related samples.",
         "optional": "true",
         "dirs": [
           "applications/sample/camera/communication"
         ],
         "targets": [
           "//applications/sample/camera/communication:sample"
         ],
         "rom": "",
         "ram": "",
         "output": [],
         "adapted_kernel": [ "liteos_a" ],
         "features": [],
         "deps": {
           "components": [],
           "third_party": []
         }
       },
   ##start##
       {
         "component": "hello_world_app",
         "description": "hello world samples.",
         "optional": "true",
         "dirs": [
           "applications/sample/hello"
         ],
         "targets": [
           "//applications/sample/hello:hello-OHOS"
         ],
         "rom": "",
         "ram": "",
         "output": [],
         "adapted_kernel": [ "liteos_a" ],
         "features": [],
         "deps": {
           "components": [],
           "third_party": []
         }
       },
   ##end##
       {
         "component": "camera_sample_app",
         "description": "Camera related samples.",
         "optional": "true",
         "dirs": [
           "applications/sample/camera/launcher",
           "applications/sample/camera/cameraApp",
           "applications/sample/camera/setting",
           "applications/sample/camera/gallery",
           "applications/sample/camera/media"
         ],
   ```

4. Modify the board configuration file.
   
   Modify the **vendor/hisilicon/hispark_taurus/config.json** file and add an entry for the **hello_world_app** component. The following code snippet is the configuration of the **applications** subsystem, where the configuration between **\#\#start\#\#** and **\#\#end\#\#** is the new entry. (The **\#\#start\#\#** and **\#\#end\#\#** lines are only used to identify the location. After the configuration is complete, delete these lines.)

   
   ```
         {
           "subsystem": "applications",
           "components": [
             { "component": "camera_sample_app", "features":[] },
             { "component": "camera_sample_ai", "features":[] },
   ##start##
             { "component": "hello_world_app", "features":[] },
   ##end##
             { "component": "camera_screensaver_app", "features":[] }
           ]
         },
   ```
