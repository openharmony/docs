# 新建应用程序<a name="ZH-CN_TOPIC_0000001216535387"></a>

下方将通过修改源码的方式展示如何编写简单程序，输出“Hello world.”。请在[获取源码](quickstart-lite-sourcecode-acquire.md)章节下载的源码目录中进行下述操作。

1.  <a name="li5479332115116"></a>确定目录结构。

    开发者编写业务时，务必先在./applications/sample/wifi-iot/app路径下新建一个目录（或一套目录结构），用于存放业务源码文件。

    例如：在app下新增业务my\_first\_app，其中hello\_world.c为业务代码，BUILD.gn为编译脚本，具体规划目录结构如下：

    ```
    .
    └── applications
        └── sample
            └── wifi-iot
                └── app
                    │── my_first_app
                    │  │── hello_world.c
                    │  └── BUILD.gn
                    └── BUILD.gn
    ```

2.  编写业务代码。

    新建./applications/sample/wifi-iot/app/my\_first\_app下的hello\_world.c文件，在hello\_world.c中新建业务入口函数HelloWorld，并实现业务逻辑。并在代码最下方，使用OpenHarmony启动恢复模块接口SYS\_RUN\(\)启动业务。（SYS\_RUN定义在ohos\_init.h文件中）

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

3.  编写用于将业务构建成静态库的BUILD.gn文件。

    新建./applications/sample/wifi-iot/app/my\_first\_app下的BUILD.gn文件，并完成如下配置。

    如[步骤1](#li5479332115116)所述，BUILD.gn文件由三部分内容（目标、源文件、头文件路径）构成，需由开发者完成填写。

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

    -   static\_library中指定业务模块的编译结果，为静态库文件libmyapp.a，开发者根据实际情况完成填写。
    -   sources中指定静态库.a所依赖的.c文件及其路径，若路径中包含"//"则表示绝对路径（此处为代码根路径），若不包含"//"则表示相对路径。
    -   include\_dirs中指定source所需要依赖的.h文件路径。

4.  编写模块BUILD.gn文件，指定需参与构建的特性模块。

    配置./applications/sample/wifi-iot/app/BUILD.gn文件，在features字段中增加索引，使目标模块参与编译。features字段指定业务模块的路径和目标，以my\_first\_app举例，features字段配置如下。

    ```
    import("//build/lite/config/component/lite_component.gni")
    
    lite_component("app") {
        features = [
            "my_first_app:myapp",
        ]
    }
    ```

    -   my\_first\_app是相对路径，指向./applications/sample/wifi-iot/app/my\_first\_app/BUILD.gn。
    -   myapp是目标，指向./applications/sample/wifi-iot/app/my\_first\_app/BUILD.gn中的static\_library\("myapp"\)。


