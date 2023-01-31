# 编写“Hello World”程序


下方将展示如何在单板上运行第一个应用程序，其中包括新建应用程序、编译、烧写、运行等步骤，最终输出“Hello World！”。


## 前提条件

已参考[创建工程并获取源码](quickstart-ide-import-project.md)，创建RK3568开发板的源码工程。


## 示例目录

拉取openharmony项目代码，在代码根目录创建sample子系统文件夹，在子系统目录下创建hello部件文件夹，hello文件夹中创建hello源码目录，构建文件BUILD.gn及部件配置文件bundle.json。
示例完整目录如下。


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


## 开发步骤

请在源码目录中通过以下步骤创建“Hello World”应用程序。

1. 创建目录，编写业务代码。
   
   新建sample/hello/src/helloworld.c目录及文件，代码如下所示，用户可以自定义修改打印内容（例如：修改World为OHOS）。其中helloworld.h包含字符串打印函数HelloPrint的声明。当前应用程序可支持标准C及C++的代码开发。

   
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

   再添加头文件sample/hello/include/helloworld.h，代码如下所示。

   
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

2. 新建编译组织文件。

   新建sample/hello/BUILD.gn，创建方法可参考：[模块配置规则](../subsystems/subsys-build-module.md)。                                                                                                                                           
                                                                                                                                                创建 
   BUILD.gn内容如下所示：
      
   ```
   import("//build/ohos.gni")  # 导入编译模板
   ohos_executable("helloworld") { # 可执行模块
     sources = [       # 模块源码
       "src/helloworld.c"
     ]
     include_dirs = [  # 模块依赖头文件目录
       "include" 
     ]
     cflags = []
     cflags_c = []
     cflags_cc = []
     ldflags = []
     configs = []
     deps =[]    # 部件内部依赖
     part_name = "hello"    # 所属部件名称，必选
     install_enable = true  # 是否默认安装（缺省默认不安装），可选
   }
   ```

3. 新建部件配置规则文件

   新建sample/hello/bundle.json文件，添加sample部件描述，创建方法可参考：[部件配置规则](../subsystems/subsys-build-component.md)。                                                                                                                                                            
                                                                                                                                                       
   bundle.json内容如下所示。
      
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

   bundle.json文件包含两个部分，第一部分描述该部件所属子系统的信息，第二部分component则定义该部件构建相关配置。添加的时候需要指明该部件包含的模块sub_component，假如有提供给其它部件的接口，需要在inner_kits中说明，假如有测试用例，需要在test中说明，inner_kits与test没有也可以不添加。

4. 修改子系统配置文件。
   
   在build/subsystem_config.json中添加新建的子系统的配置。修改方法可参考：[子系统配置规则](../subsystems/subsys-build-subsystem.md)。
                                                                                                                                                       
   新增子系统的配置如下所示。
   
   ```
   "sample": {
       "path": "sample",
       "name": "sample"
     },
   ```

5. 修改产品配置文件。

      > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
      > OpenHarmony-v3.2-Beta2之前版本，RK3568的产品配置文件为productdefine/common/products/rk3568.json；从OpenHarmony-v3.2-Beta2版本开始，RK3568的产品配置文件为vendor/hihope/rk3568/config.json。

   - 3.2-Beta2之前版本
                                                                                                                                                       
      在productdefine/common/products/rk3568.json中添加对应的hello部件，直接添加到原有部件后即可。
   
       ```
       "usb:usb_manager_native":{},
       "applications:prebuilt_hap":{},
       "sample:hello":{},
       "wpa_supplicant-2.9:wpa_supplicant-2.9":{},
       ```

   - 3.2-Beta2及之后版本
                                                                                                                                                       
      在vendor/hihope/rk3568/config.json中添加对应的hello部件，直接添加到原有部件后即可。

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
