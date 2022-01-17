# 创建应用程序<a name="ZH-CN_TOPIC_0000001234205905"></a>

下方将通过修改源码的方式展示如何在单板上运行第一个应用程序，其中包括新建应用程序、编译、烧写、运行等步骤，最终输出“Hello World！”。

这里演示在原有applications子系统下，添加hello部件以及该部件下的helloworld模块。

示例完整目录如下。

```
applications/standard/hello
├── helloworld
│   ├── BUILD.gn
│   ├── include
│   │   └── helloworld.h
│   └── src
│       └── helloworld.c
├── ohos.build
│
productdefine/common
└── products
    └── rk3568.json
```

下方为新建应用程序步骤，请在[获取源码](quickstart-standard-sourcecode-acquire.md)章节下载的源码目录中进行下述操作：

1.  新建目录及源码。

    新建applications/standard/hello/helloworld/src/helloworld.c目录及文件，代码如下所示，用户可以自定义修改打印内容（例如：修改World为OHOS）。其中helloworld.h包含字符串打印函数HelloPrint的声明。当前应用程序可支持标准C及C++的代码开发。

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
        printf("\n************************************************\n");
        printf("\n\t\tHello World!\n");
        printf("\n************************************************\n");
    }
    ```

    再添加头文件applications/standard/hello/helloworld/include/helloworld.h，代码如下所示。

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

2.  新建编译组织文件。
    1.  新建applications/standard/hello/helloworld/BUILD.gn文件，内容如下所示：

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

    2.  新建applications/standard/hello/ohos.build文件，添加hello部件描述，内容如下所示。

        ```
        {
          "subsystem": "applications", # 子系统名
          "parts": { # 包含部件
            "hello": { # 新建部件名
              "version": "1.0.0", # 版本
              "variants": [ # 变种版本
                "wearable",
                "phone"
              ],
              "module_list": [ # 部件包含模块的gn目标
                "//applications/standard/hello/helloworld:helloworld"
              ],
               "inner_kits": [ # 提供给其他部件的接口
              ],
               "test_list": [  # 测试用例
              ]
            }
          }
        }
        ```

        ohos.build文件包含两个部分，第一部分subsystem说明该子系统的名称，parts定义该子系统包含的部件，要添加一个部件，需要把该部件对应的内容添加进parts中去。添加的时候需要指明该部件包含的模块module\_list，假如有提供给其它部件的接口，需要在inner\_kits中说明，假如有测试用例，需要在test\_list中说明，inner\_kits与test\_list没有也可以不添加。

3.  修改产品配置文件。

    在productdefine\\common\\products\\rk3568.json中添加对应的hello部件，直接添加到原有部件后即可。

    ```
    "usb:usb_manager_native":{},
        "applications:prebuilt_hap":{},
        "applications:hello":{},
        "wpa_supplicant-2.9:wpa_supplicant-2.9":{},
    ```


