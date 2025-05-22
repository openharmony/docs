# 编写“Hello World”程序


下方将展示如何在单板上运行第一个应用程序，其中包括新建应用程序、编译、烧写、运行等步骤，最终输出“Hello World！”。


## 示例目录

示例完整目录如下：



```
applications/sample/hello
│── BUILD.gn
└── src
    └── helloworld.c
```


## 开发步骤

请在源码目录中通过以下步骤创建“Hello World”应用程序。

1. 新建目录及源码。
   
   新建applications/sample/hello/src/helloworld.c目录及文件，代码如下所示，用户可以自定义修改打印内容（例如：修改OHOS为World）。当前应用程序可支持标准C及C++的代码开发。

   
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

2. 新建编译组织文件。
   
   新建applications/sample/hello/BUILD.gn文件，内容如下所示：

   
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

3. 添加新组件。
   
   修改文件build/lite/components/communication.json，添加组件hello_world_app的配置。如下所示为**communication.json**文件片段，"\#\#start\#\#"和"\#\#end\#\#"之间为新增配置（"\#\#start\#\#"和"\#\#end\#\#"仅用来标识位置，添加完配置后删除这两行）：

   
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

4. 修改单板配置文件。
   
   修改文件vendor/hisilicon/hispark_taurus/config.json，新增hello_world_app组件的条目。如下所示代码片段为applications子系统配置，"\#\#start\#\#"和"\#\#end\#\#"之间为新增条目（"\#\#start\#\#"和"\#\#end\#\#"仅用来标识位置，添加完配置后删除这两行）：

   
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
