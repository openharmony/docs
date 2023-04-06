# Writing a Hello World Program


The following exemplifies how to create a program by modifying the source code. The created program outputs the message "Hello world." Perform the steps below in the source code directory.


## Prerequisites

A project for the Hi3861 development board has been created as instructed in [Creating a Project and Obtaining Source Code](quickstart-ide-import-project.md).


## Procedure

1. Determine the directory structure.

   Before writing service code, you must create a directory (or a directory structure) in **./applications/sample/wifi-iot/app** to store source code files.

   For example, to add the **my_first_app** service to the **app** directory, where the **hello_world.c** file stores the service code and **BUILD.gn** is the compilation script, the directory structure can be planned as follows:

   
   ```
   .
   └── applications
       └── sample
           └── wifi-iot
               └── app
                   └── my_first_app
                     │── hello_world.c
                     └── BUILD.gn
   ```

2. Write the service code.

   Create the **hello_world.c** file in **./applications/sample/wifi-iot/app/my_first_app**. Then, create the entry point function **HelloWorld** in **hello_world.c** and implement service logic. Call **SYS_RUN()** of OpenHarmony to start the service. (**SYS_RUN** is defined in the **ohos_init.h** file.)
   
   ```
   #include <stdio.h>
   #include "ohos_init.h"
   #include "ohos_types.h"
   
   void HelloWorld(void)
   {
       printf("[DEMO] Hello world.\n");
   }
   SYS_RUN(HelloWorld);
   ```

3. Compile the **BUILD.gn** file for building services into a static library.
   
   Create the **BUILD.gn** file in **./applications/sample/wifi-iot/app/my_first_app** and configure the file as follows:

   The **BUILD.gn** file consists of three parts, including target, source file, and header file path. You need to fill in all of these parts.

   
   ```
   static_library("myapp") {
       sources = [
           "hello_world.c"
       ]
       include_dirs = [
           "//utils/native/lite/include"
       ]
   }
   ```

   - Specify the compilation result named **libmyapp.a** in **static_library**. You can fill in this part based on your need.
   - Specify the .c file on which a file depends and its path in **sources**. The path that contains **//** represents an absolute path (the code root path). The path that does not contain **//** is a relative path.
   - Specify the path of .h file on which **sources** depends in **include_dirs**.

4. Add a component.
   
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
           "applications/sample/wifi-iot/app/my_first_app"
         ],
         "targets": [
           "//applications/sample/wifi-iot/app/my_first_app:myapp"
         ],
         "rom": "",
         "ram": "",
         "output": [],
         "adapted_kernel": [ "liteos_m" ],
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

5. Modify the board configuration file.
   
   Modify the **vendor/hisilicon/hispark_pegasus/config.json** file and add an entry for the **hello_world_app** component. The following code snippet is the configuration of the **applications** subsystem, where the configuration between **\#\#start\#\#** and **\#\#end\#\#** is the new entry. (The **\#\#start\#\#** and **\#\#end\#\#** lines are only used to identify the location. After the configuration is complete, delete these lines.)

   
   ```
         {
           "subsystem": "applications",
           "components": [
   ##start##
             { "component": "hello_world_app", "features":[] },
   ##end##
             { "component": "wifi_iot_sample_app", "features":[] }
           ]
         },
   ```
