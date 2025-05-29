# 编写“Hello World”程序


下方将通过修改源码的方式展示如何编写简单程序，输出“Hello world”。请在下载的源码目录中进行下述操作。


## 前提条件

已参考[创建工程并获取源码](quickstart-ide-import-project.md)，创建Hi3861开发板的源码工程。


## 操作步骤

1. 确定目录结构。

   开发者编写业务代码时，务必先在./applications/sample/wifi-iot/app路径下新建一个目录（或一套目录结构），用于存放业务源码文件。

   例如：在app下新增业务my_first_app，其中hello_world.c为业务代码，BUILD.gn为编译脚本，具体规划目录结构如下：

   
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

2. 编写业务代码。

   新建./applications/sample/wifi-iot/app/my_first_app下的hello_world.c文件，在hello_world.c中新建业务入口函数HelloWorld，并实现业务逻辑。并在代码最下方，使用OpenHarmony启动恢复模块接口SYS_RUN()启动业务，SYS_RUN定义在ohos_init.h文件中。
     
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

3. 编写用于将业务构建成静态库的BUILD.gn文件。
   
   新建./applications/sample/wifi-iot/app/my_first_app下的BUILD.gn文件，并完成如下配置。

   如步骤1所述，BUILD.gn文件由三部分内容（目标、源文件、头文件路径）构成，需由开发者完成填写。

   
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

   - static_library中指定业务模块的编译结果，为静态库文件libmyapp.a，开发者根据实际情况完成填写。
   - sources中指定静态库.a所依赖的.c文件及其路径，若路径中包含"//"则表示绝对路径（此处为代码根路径），若不包含"//"则表示相对路径。
   - include_dirs中指定source所需要依赖的.h文件路径。

4. 添加新组件。
   
   修改文件build/lite/components/applications.json，添加组件hello_world_app的配置。如下所示为applications.json文件片段，"\#\#start\#\#"和"\#\#end\#\#"之间为新增配置（"\#\#start\#\#"和"\#\#end\#\#"仅用来标识位置，添加完配置后删除这两行）：

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 本章节操作是以OpenHarmony-v3.1-Release版本为例进行操作的，该版本中，组件配置文件为build/lite/components/applications.json；若源码版本大于等于OpenHarmony 3.2 Beta2时，组件配置文件为build/lite/components/communication.json。

   
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

5. 修改单板配置文件。
   
   修改文件vendor/hisilicon/hispark_pegasus/config.json，新增hello_world_app组件的条目。如下所示代码片段为applications子系统配置，"\#\#start\#\#"和"\#\#end\#\#"之间为新增条目（"\#\#start\#\#"和"\#\#end\#\#"仅用来标识位置，添加完配置后删除这两行）：

   
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
