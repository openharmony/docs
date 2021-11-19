# 标准系统编译构建指导<a name="ZH-CN_TOPIC_0000001076490572"></a>

-   [概述](#section17466112012244)
    -   [基本概念](#section445513507246)
    -   [运作机制](#section12541217142510)
    -   [约束与限制](#section886933762513)

-   [编译构建使用指导](#section16901215262)
    -   [目录结构](#section109065332264)
    -   [编译命令](#section123265539266)
    -   [开发步骤](#section591084422719)


## 概述<a name="section17466112012244"></a>

编译构建子系统提供了一个基于gn和ninja的编译构建框架。主要提供以下功能：

-   构建不同芯片平台的产品。如：Hi3516DV300平台。

-   根据产品配置可以按照组件组装打包产品需要的能力。

### 基本概念<a name="section445513507246"></a>

在了解编译构建子系统的能力前，应了解如下基本概念：

-   平台

    开发板和内核的组合，不同平台支持的子系统和组件不同。

-   子系统

    OpenHarmony整体遵从分层设计，从下向上依次为：内核层、系统服务层、框架层和应用层。系统功能按照“系统 \> 子系统 \> 组件”逐级展开，在多设备部署场景下，支持根据实际需求裁剪某些非必要的子系统或组件。子系统是一个逻辑概念，它具体由对应的组件构成。

-   组件

    对子系统的进一步拆分，可复用的软件单元，它包含源码、配置文件、资源文件和编译脚本；能独立构建，以二进制方式集成，具备独立验证能力的二进制单元。

-   gn

    Generate ninja的缩写，用于产生ninja文件。

-   ninja

    ninja是一个专注于速度的小型构建系统。


### 运作机制<a name="section12541217142510"></a>

OpenHarmony侧的编译构建流程主要包括编译命令行解析，调用gn，执行ninja：

-   命令行解析：解析待编译的产品名称，加载相关配置。
-   调用gn: 根据命令行解析的产品名称和编译类型，配置编译工具链和全局的编译选项。
-   执行ninja：启动编译并生成对应的产品版本。

### 约束与限制<a name="section886933762513"></a>

-   需按照[源码获取](../get-code/sourcecode-acquire.md)指导下载全量源码（采用方式三获取）。
-   编译环境需要Ubuntu18.04及以上版本。
-   安装编译所需的程序包。

    安装命令：

    ```
    sudo apt-get install binutils git-core gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4
    ```


## 编译构建使用指导<a name="section16901215262"></a>

### 目录结构<a name="section109065332264"></a>

```
/build                           # 编译构建主目录
├── config                       # 编译相关的配置项
├── core
│   └── gn                       # 编译入口BUILD.gn配置
├── loader                       # 各个组件配置加载、模板生成
├── ohos                         # OpenHarmony编译打包流程配置
│   ├── kits                     # kits编译打包模板和处理流程
│   ├── ndk                      # ndk模板和处理流程
│   ├── notice                   # notice模板和处理流程
│   ├── packages                 # 版本打包模板和处理流程
│   ├── sa_profile               # sa模板和处理流程
│   ├── sdk                      # sdk模板和处理流程，包括sdk中包含的模块配置
│   └── testfwk                  # 测试相关的处理
├── scripts                      # 编译相关的python脚本
├── templates                    # c/c++编译模板定义
└── toolchain                    # 编译工具链配置
```

### 编译命令<a name="section123265539266"></a>

-   代码根目录下执行全量版本的编译命令：

    ```
    ./build.sh --product-name {product_name}
    ```

    \{product\_name\}为当前版本支持的平台。比如：Hi3516DV300等。

    编译完成后，结果镜像保存在 out/{device_name}/packages/phone/images/ 目录下。

-   编译命令支持选项：

    ```
      --product-name    # 必须  编译的产品名称，如：Hi3516DV300
      --build-target    # 可选  指定编译目标，可以指定多个
      --gn-args         # 可选  gn参数，支持指定多个
      --ccache          # 可选  编译使用ccache，需要本地安装ccache
    ```


### 开发步骤<a name="section591084422719"></a>

1.  添加组件。

    本节以添加一个自定义的组件为例，描述如何编译组件，编译库、编译可执行文件等。

    示例组件partA由feature1、feature2和feature3组成，feature1的编译目标为一个动态库，feature2的目标为一个可执行程序，feature3的目标为一个etc配置文件。

    示例组件partA的配置需要添加到一个子系统中，本次示例将添加到subsystem\_examples子系统中（subsystem\_examples子系统定义在test/examples/目录）。

    示例组件partA的完整目录结构如下：

    ```
    test/examples/partA
    ├── feature1
    │   ├── BUILD.gn
    │   ├── include
    │   │   └── helloworld1.h
    │   └── src
    │       └── helloworld1.cpp
    ├── feature2
    │   ├── BUILD.gn
    │   ├── include
    │   │   └── helloworld2.h
    │   └── src
    │       └── helloworld2.cpp
    └── feature3
        ├── BUILD.gn
        └── src
            └── config.conf
    ```

    示例1：编写动态库gn脚本test/examples/partA/feature1/BUILD.gn，示例如下：

    ```
    config("helloworld_lib_config") {
     include_dirs = [ "include" ]
    }
    
    ohos_shared_library("helloworld_lib") {
      sources = [
        "include/helloworld1.h",
        "src/helloworld1.cpp",
      ]
      public_configs = [ ":helloworld_lib_config" ]
      part_name = "partA"
    }
    ```

    示例2：编写可执行文件gn脚本test/examples/partA/feature2/BUILD.gn，示例如下：

    ```
    ohos_executable("helloworld_bin") {
      sources = [
        "src/helloworld2.cpp"
      ]
      include_dirs = [ "include" ]
      deps = [                                # 依赖组件内模块
        "../feature1:helloworld_lib"
      ]
      external_deps = [ "partB:module1" ]     # （可选）如果有跨组件的依赖，格式为“组件名:模块名”
      install_enable = true                   # 可执行程序缺省不安装，需要安装时需要指定
      part_name = "partA"
    }
    ```

    示例3：编写etc模块gn脚本test/examples/partA/feature3/BUILD.gn，示例如下：

    ```
    ohos_prebuilt_etc("feature3_etc") {
      source = "src/config.conf"
      relative_install_dir = "init"    #可选，模块安装相对路径，相对于默认安装路径；默认在/system/etc目录
      part_name = "partA"
    }
    ```

    示例4：在子系统的ohos.build中添加组件配置：test/examples/ohos.build。每个子系统有一个ohos.build配置文件，在子系统的根目录下。示例如下：

    ```
    "partA": {
        "module_list": [
          "//test/examples/partA/feature1:helloworld_lib",
          "//test/examples/partA/feature2:helloworld_bin",
          "//test/examples/partA/feature3:feature3_etc",
        ],
        "inner_kits": [
    
        ],
        "system_kits": [
    
        ],
        "test_list": [
    
        ]
      }
    ```

    一个组件包含module\_list、inner\_kits、system\_kits、test\_list四个部分的声明，其中：

    -   module\_list：组件所包含的模块列表；
    -   inner\_kits：组件提供给其它组件调用的接口，其他组件的模块可以在external\_deps中添加依赖的模块；
    -   system\_kits：组件提供给开发者开发应用的接口；
    -   test\_list：组件中对应模块的测试用例；

2.  将组件添加到产品配置中。

    在产品的配置中添加组件，产品对应的配置文件：productdefine/common/products/\{product-name\}.json。

    在产品配置文件中添加 "subsystem\_examples:partA"，表示该产品中会编译并打包partA到版本中。

3.  编译。

    以编译Hi3516DV300为例，编译命令如下：

    ```
    ./build.sh --product-name Hi3516DV300 --ccache
    ```

4.  编译输出。

    编译所生成的文件都归档在out/hi3516dv300/目录下，结果镜像输出在 out/hi3516dv300/packages/phone/images/ 目录下。


