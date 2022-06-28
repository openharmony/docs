# 标准系统编译构建指导

## 概述

编译构建子系统提供了一个基于gn和ninja的编译构建框架。主要提供以下功能：

- 构建不同芯片平台的产品。如：hispark_taurus_standard平台。

- 根据产品配置，按照部件组装并打包产品特性的能力。

### 基本概念

在了解编译构建子系统的能力前，应了解如下基本概念：

- 平台
  开发板和内核的组合，不同平台支持的子系统和部件不同。

- 子系统
  OpenHarmony整体遵从分层设计，从下向上依次为：内核层、系统服务层、框架层和应用层。系统功能按照“系统 &gt; 子系统 &gt; 部件”逐级展开，在多设备部署场景下，支持根据实际需求裁剪某些非必要的子系统或部件。子系统是一个逻辑概念，它具体由对应的部件构成。

- 部件
  对子系统的进一步拆分，可复用的软件单元，它包含源码、配置文件、资源文件和编译脚本；能独立构建，以二进制方式集成，具备独立验证能力的二进制单元。

- gn
  Generate ninja的缩写，用于产生ninja文件。

- ninja
  ninja是一个专注于速度的小型构建系统。

### 运作机制

OpenHarmony侧的编译构建流程主要包括编译命令行解析，调用gn，执行ninja：

- 命令行解析：解析待编译的产品名称，加载相关配置。

- 调用gn: 根据命令行解析的产品名称和编译类型，配置编译工具链和全局的编译选项。

- 执行ninja：启动编译并生成对应的产品版本。

### 约束与限制

- 需按照[源码获取](../get-code/sourcecode-acquire.md)指导下载全量源码（采用方式三获取）。

- 编译环境需要Ubuntu18.04及以上版本。

- 安装编译所需的程序包。
    安装命令：
  
  ```
  # 推荐使用脚本,在家目录执行
  # ./build/build_scripts/env_setup.sh
  # 不要用root执行，会将环境变量加到root。如果你的sheel不是bash或者zsh，执行完还需要你手动配置以下内容到你的环境变量中，cd ~到你用户家目录查看隐藏文件能显示你的用户环境变量文件。
  # export PATH=/home/tools/llvm/bin:$PATH
  # export PATH=/home/tools/hc-gen:$PATH
  # export PATH=/home/tools/gcc_riscv32/bin:$PATH
  # export PATH=/home/tools/ninja:$PATH
  # export PATH=/home/tools/node-v12.20.0-linux-x64/bin:$PATH
  # export PATH=/home/tools/gn:$PATH
  # export PATH=/root/.local/bin:$PATH
  
  # 如果不用脚本执行，则需要安装以下内容
  apt-get update -y 
  apt-get install -y apt-utils binutils bison flex bc build-essential make mtd-utils gcc-arm-linux-gnueabi u-boot-tools python3.9.2 python3-pip git zip unzip curl wget gcc g++ ruby dosfstools mtools default-jre default-jdk scons python3-distutils perl openssl libssl-dev cpio git-lfs m4 ccache zlib1g-dev tar rsync liblz4-tool genext2fs binutils-dev device-tree-compiler e2fsprogs git-core gnupg gnutls-bin gperf lib32ncurses5-dev libffi-dev zlib* libelf-dev libx11-dev libgl1-mesa-dev lib32z1-dev xsltproc x11proto-core-dev libc6-dev-i386 libxml2-dev lib32z-dev libdwarf-dev 
  apt-get install -y grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools  pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5 libncurses5-dev libncursesw5 libstdc++6 python2.7 gcc-arm-none-eabi vim ssh locales doxygen
  # python需要安装以下模块
  chmod +x /usr/bin/repo 
  pip3 install --trusted-host https://repo.huaweicloud.com -i https://repo.huaweicloud.com/repository/pypi/simple requests setuptools pymongo kconfiglib pycryptodome ecdsa ohos-build pyyaml prompt_toolkit==1.0.14 redis json2html yagmail python-jenkins 
  pip3 install esdk-obs-python --trusted-host pypi.org 
  pip3 install six --upgrade --ignore-installed six
  #还需要安装llvm，hc-gen，gcc_riscv32，ninja，node-v14.15.4-linux-x64，gn并将上述shell环境非bash或者zsh的配置内容导入到你用户的环境变量中
  ```



## 编译构建使用指导

### 目录结构

```

/build                           # 编译构建主目录

├── __pycache__                   # ----------------------
├── build_scripts/                # 编译相关的python脚本
├── common/                       # ----------------------
├── config/                       # 编译相关的配置项
├── core
│   ├── gn/                       # 编译入口BUILD.gn配置
    └── build_scripts/            # ----------------------
├── docs                          # ----------------------
gn_helpers.py*                    # ----------------------
lite/                             # hb和preloader入口                      
misc/
├── ohos                          # OpenHarmony编译打包流程配置
│   ├── kits                      # kits编译打包模板和处理流程
│   ├── ndk                       # ndk模板和处理流程
│   ├── notice                    # notice模板和处理流程
│   ├── packages                  # 版本打包模板和处理流程
│   ├── sa_profile                # sa模板和处理流程
│   ├── sdk                       # sdk模板和处理流程，包括sdk中包含的模块配置
│   └── testfwk                   # 测试相关的处理
├── ohos.gni*                     # 汇总了常用的gni文件，方便各个模块一次性import
├── ohos_system.prop              # ----------------------
├── ohos_var.gni*                 # ----------------------
├── prebuilts_download.sh*        # ----------------------
├── print_python_deps.py*         # ----------------------
├── scripts/                      # ----------------------
├── subsystem_config.json         # ----------------------
├── subsystem_config_example.json # ----------------------
├── templates/                    # c/c++编译模板定义
├── test.gni*                     # ----------------------
├── toolchain                     # 编译工具链配置
├── tools                         # 常用工具
├── version.gni                   # ----------------------
├── zip.py*                       # ----------------------


```

### 编译命令

- 代码根目录下执行全量版本的编译命令：

  ```

  ./build.sh --product-name {product_name}
  
  ```

  {product_name}为当前版本支持的平台。比如：hispark_taurus_standard等。

  编译完成后，结果镜像保存在 out/{device_name}/packages/phone/images/ 目录下。

- 编译命令支持选项：./build.sh -h

  ```
  -h, --help                                        # 显示帮助信息并退出
  --source-root-dir=SOURCE_ROOT_DIR                 # 指定路径
  --product-name=PRODUCT_NAME                       # 指定产品名
  --device-name=DEVICE_NAME                         # 指定装置名称
  --target-cpu=TARGET_CPU                           # 指定cpu
  --target-os=TARGET_OS                             # 指定操作系统
  -T BUILD_TARGET, --build-target=BUILD_TARGET      # 指定编译目标，可以指定多个
  --gn-args=GN_ARGS                                 # gn参数，支持指定多个
  --ninja-args=NINJA_ARGS                           # ninja参数，支持指定多个
  -v, --verbose                                     # 生成时显示所有命令行
  --keep-ninja-going                                # 让ninja持续到1000000个工作失败
  --sparse-image
  --jobs=JOBS
  --export-para=EXPORT_PARA
  --build-only-gn                                   # 只做gn解析，不运行ninja
  --ccache                                          # 可选  编译使用ccache，需要本地安装ccache
  --fast-rebuild                                    # 快速重建，default=False
  --log-level=LOG_LEVEL                             # 指定编译期间的日志级别'，'三个级别可选：debug, info and error，default='info'
  --device-type=DEVICE_TYPE                         # 指定设备类型，default='default'
  --build-variant=BUILD_VARIANT                     # 指定设备操作模式，default='user'

  ```

### 开发步骤

1. 添加部件。
   本节以添加一个自定义的部件为例，描述如何编译部件，编译库、编译可执行文件等。
   
   示例部件partA由feature1、feature2和feature3组成，feature1的编译目标为一个动态库，feature2的目标为一个可执行程序，feature3的目标为一个etc配置文件。
   
   示例部件partA的配置需要添加到一个子系统中，本次示例将添加到subsystem_examples子系统中（subsystem_examples子系统定义在test/examples/目录）。
   
   示例部件partA的完整目录结构如下：

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
     deps = [                                # 依赖部件内模块
       "../feature1:helloworld_lib"
     ]
     external_deps = [ "partB:module1" ]     # （可选）如果有跨部件的依赖，格式为“部件名:模块名”
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

   示例4：在部件的bundle.json中添加模块配置：test/examples/bundle.json。每个部件都有一个bundle.json配置文件，在部件的根目录下。示例如下：
   
    ```
   {
       "name": "@ohos/<component_name>",               # HPM部件英文名称，格式"@组织/部件名称"
       "description": "xxxxxxxxxxxxxxxxxxx",           # 部件功能一句话描述
       "version": "3.1",                               # 版本号，版本号与OpenHarmony版本号一致
       "license": "MIT",                               # 部件License
       "publishAs": "code-segment",                    # HPM包的发布方式，当前默认都为code_segment
       "segment": {
           "destPath": ""
       },                                              # 发布类型为code_segment时为必填项，定义发布类型code_segment的代码还原路径（源码路径）
       "dirs": {},                                     # HPM包的目录结构，字段必填内容可以留空
       "scripts": {},                                  # HPM包定义需要执行的脚本，字段必填，值非必填
       "licensePath": "COPYING",                       # 指定该模块的版权申明路径
       "readmePath": {
           "en": "README.rst"
       },                                              # 该模块的reademe.opensource的路径
       "component": {                                  # 部件属性
           "name": "<component_name>",                 # 部件名称
           "subsystem": "",                            # 部件所属子系统
           "syscap": [],                               # 部件为应用提供的系统能力
           "features": [],                             # 部件对外的可配置特性列表，一般与build中的sub_component对应，可供产品配置
           "adapted_system_type": [],                  # 轻量(mini)小型(small)和标准(standard)，可以是多个
           "rom": "xxxKB",                             # ROM基线，没有基线写当前值
           "ram": "xxxKB",                             # RAM基线，没有基线写当前值
           "deps": {
               "components": [],                       # 部件依赖的其他部件
               "third_party": []                       # 部件依赖的三方开源软件
           },
           "build": {                                  # 编译相关配置
               "sub_component": [],                    # 部件编译入口，模块在此处配置
               "inner_kits": [],                       # 部件间接口
               "test": []                              # 部件测试用例编译入口
           }
       }
   }
   ```

2. 将部件添加到产品配置中。
   在产品的配置中添加部件，产品对应的配置文件：//vendor/{product_company}/{product-name}/config.json。
   
   在产品配置文件中添加 "subsystem_examples:partA"，表示该产品中会编译并打包partA到版本中。

3. 编译。
   以编译hispark_taurus_standard为例，编译命令如下：

   ```

   ./build.sh --product-name hispark_taurus_standard --ccache

   ```

4. 编译输出。
   编译所生成的文件都归档在out/hispark_taurus/目录下，结果镜像输出在 out/hispark_taurus/packages/phone/images/ 目录下。

## 常见问题

### 如何将一个模块编译并打包到版本中？

- 模块要指定part_name，指定它归属的部件，一个模块只能属于一个部件；

- 部件的模块，要在部件配置的component.build.sub_component中，或者可以被component.build.sub_component中的模块依赖到；

- 部件要加到对应产品的部件列表中。

### 关于deps、external_deps的使用

在添加一个模块的时候，需要在BUILD.gn中声明它的依赖，为了便于后续处理部件间依赖关系，我们将依赖分为两种——部件内依赖deps和部件间依赖external_deps。

### 依赖分类：

- 1.部件内依赖： 现有模块module1属于部件part1，要添加一个属于部件part1的模块module2，module2依赖于module1，这种情况就属于部件内依赖。

- 2.部件间依赖： 现有模块module1属于部件part1，要添加一个模块module2，module2依赖于module1，module2属于部件part2。模块module2与模块module1分属于两个不同的部件，这种情况就属于部件间依赖。

- 部件内依赖示例：

   ```
   import("//build/ohos.gni")
   ohos_shared_library("module1") {
     ……
     part_name = "part1"   # 必选，所属部件名称
     ……
   }
   ```

   ```
   import("//build/ohos.gni")
   ohos_shared_library("module2") {
     ……
     deps = [
       "module1的gn target",
     ……
    ]                      # 部件内模块依赖
   part_name = "part1"   # 必选，所属部件名称
   }
   ```

- 部件间依赖示例：

   ```
   import("//build/ohos.gni")
   ohos_shared_library("module1") {
     ……
     part_name = "part1"   # 必选，所属部件名称
     ……
   }
   ```

- 模块1所属部件的bundle.json文件

   ```
   {
       "name": "@ohos/<component_name>",             # HPM部件英文名称，格式"@组织/部件名称"
       "description": "xxxxxxxxxxxxxxxx",            # 部件功能一句话描述
       "version": "3.1",                             # 版本号，版本号与OpenHarmony版本号一致
       "license": "MIT",                             # 部件License
       "publishAs": "code-segment",                  # HPM包的发布方式，当前默认都为code_segment
       "segment": {
           "destPath": ""
       },                                            # 发布类型为code_segment时为必填项，定义发布类型code_segment的代码还原路径（源码路径）
       "dirs": {},                                   # HPM包的目录结构，字段必填内容可以留空
       "scripts": {},                                # HPM包定义需要执行的脚本，字段必填，值非必填
       "licensePath    "licensePath": "COPYING",
   ": "COPYING",
       "readmePath": {
       "en": "README.rst"
       },
       "component": {                                # 部件属性
           "name": "<component_name>",               # 部件名称
           "subsystem": "",                          # 部件所属子系统
           "syscap": [],                             # 部件为应用提供的系统能力
           "features": [],                           # 部件对外的可配置特性列表，一般与build中的sub_component对应，可供产品配置
           "adapted_system_type": [],                # 轻量(mini)小型(small)和标准(standard)，可以是多个
           "rom": "xxxKB"                            # ROM基线，没有基线写当前值
           "ram": "xxxKB",                           # RAM基线，没有基线写当前值
           "deps": {
               "components": [],                     # 部件依赖的其他部件
               "third_party": []                     # 部件依赖的三方开源软件
           },
           "build": {                                # 编译相关配置
               "sub_component": ["part1"],           # 部件编译入口,部件所有模块在此列表
               "inner_kits": [                       # 部件间接口
           {
             "header": {
               "header_base": "头文件所属目录",       # 头文件所属目录
               "header_files": [
                   "头文件名"
                 ]                                   # 头文件名列表
               },
               "name": "module1的gn target"
           },
         ],
               "test": []                            # 部件测试用例编译入口
           }
       }
   }
   ```

   ```
   import("//build/ohos.gni")
   ohos_shared_library("module2") {
     ……
     external_deps = [
       "part1:module1",
     ……
     ]                      # 部件间模块依赖，这里依赖的模块必须是依赖的部件声明在inner_kits中的模块
     part_name = "part2"    # 必选，所属部件名称
   }

   ```

> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> 部件间依赖要写在external_deps里面，格式为”部件名:模块名"的形式，并且依赖的模块必须是依赖的部件声明在inner_kits中的模块。





### 标准系统如何添加一个模块

要添加的模块可以分为以下三种情况，对原有的配置文件进行不同程度的修改。

- 在原有部件中添加一个模块

- 新建部件并在其中添加模块

- 新建子系统并在该子系统的部件下添加模块

**在原有部件中添加一个模块**

1. 在模块目录下配置BUILD.gn，根据类型选择对应的模板。
   这一步与在原有部件中添加一个模块的方法基本一致，只需注意该模块对应BUILD.gn文件中的part_name为新建部件的名称即可。

2. 修改bundle.json配置文件。"部件包含模块的gn目标"

    ```
   {
       "name": "@ohos/<component_name>",                 # HPM部件英文名称，格式"@组织/部件名称"
       "description": "xxxxxxxxxxxxxxxxxxx",             # 部件功能一句话描述
       "version": "3.1",                                 # 版本号，版本号与OpenHarmony版本号一致
       "license": "MIT",                                 # 部件License
       "publishAs": "code-segment",                      # HPM包的发布方式，当前默认都为code_segment
       "segment": {
           "destPath": "third_party/nghttp2"
       },                                                # 发布类型为code_segment时为必填项，定义发布类型code_segment的代码还原路径（源码路径）
       "dirs": {},                                       # HPM包的目录结构，字段必填内容可以留空
       "scripts": {},                                    # HPM包定义需要执行的脚本，字段必填，值非必填
       "licensePath": "COPYING",
       "readmePath": {
           "en": "README.rst"
       },
       "component": {                                    # 部件属性
           "name": "<component_name>",                   # 部件名称
           "subsystem": "",                              # 部件所属子系统
           "syscap": [],                                 # 部件为应用提供的系统能力
           "features": [],                               # 部件对外的可配置特性列表，一般与build中的sub_component对应，可供产品配置
           "adapted_system_type": [],                    # 轻量(mini)小型(small)和标准(standard)，可以是多个
           "rom": "xxxKB"                                # ROM基线，没有基线写当前值
           "ram": "xxxKB",                               # RAM基线，没有基线写当前值
           "deps": {
               "components": [],                         # 部件依赖的其他部件
               "third_party": []                         # 部件依赖的三方开源软件
           },
        
           "build": {                                            # 编译相关配置
               "sub_component": [
                   "//foundation/arkui/napi:napi_packages",      # 原有模块1
                   "//foundation/arkui/napi:napi_packages_ndk"   # 原有模块2
                   "//foundation/arkui/napi:new"                 # 新增模块new
               ],                                                # 部件编译入口，模块在此处配置
               "inner_kits": [],                                 # 部件间接口
               "test": []                                        # 部件测试用例编译入口
           }
       }
   }
   ```

   注意无论哪种方式该bundle.json文件均在对应子系统所在文件夹下。

**新建部件并在其中添加一个模块**

1. 在模块目录下配置BUILD.gn，根据类型选择对应的模板。这一步与新建部件并在其中添加模块中对应的步骤并无区别。

2. 新建一个bundle.json文件，bundle.json文件均在对应子系统所在文件夹下。bundle.json文件包含两个部分，第一部分subsystem说明了子系统的名称，parts定义了该子系统包含的部件，要添加一个部件，需要把该部件对应的内容添加进parts中去。添加的时候需要指明该部件包含的模块sub_component，假如有提供给其它部件的接口，需要在inner_kits中说明，假如有测试用例，需要在test中说明，inner_kits与test没有也可以不添加。

2. 在//vendor/{product_company}/{product-name}/config.json中添加对应的部件，直接添加到原有部件后即可。

   ```
    "subsystems": [
         {
           "subsystem": "部件所属子系统名",
           "components": [
             { "component": "部件名1", "features":[] },        # 子系统下的原有部件1
             { "component": "部件名2", "features":[] }，       # 子系统下的原有部件2
             { "component": "部件名new", "features":[] }       # 子系统下的新增部件new
           ]
         },
         .......
    ]
   ```

**新建子系统并在该子系统的部件下添加模块**

1. 在模块目录下配置BUILD.gn，根据类型选择对应的模板。这一步与新建部件并在其中添加模块中对应的步骤并无区别。

2. 在新建的子系统目录下每个部件对应的文件夹下创建bundle.json文件，定义部件信息。这一步与新建部件并在其中添加模块中对应的步骤并无区别。

3. 修改build目录下的subsystem_config.json文件。

   ```
   {
    "子系统名1": {                     # 原有子系统1
      "path": "子系统目录1",
      "name": "子系统名1"
    },
     "子系统名2": {                    # 原有子系统2
      "path": "子系统目录2",
      "name": "子系统名2"
    },
    "子系统名new": {                   # 新增子系统new
      "path": "子系统目录new",
      "name": "子系统名new"
    },
   ...
   }
   ```

   该文件定义了有哪些子系统以及这些子系统所在文件夹路径，添加子系统时需要说明子系统path与name，分别表示子系统路径和子系统名。

4. 在//vendor/{product_company}/{product-name}目录下的产品配置如product-name是hispark_taurus_standard时，在config.json中添加对应的部件，直接添加到原有部件后即可。

   ```
   "subsystems": [
     {
       "subsystem": "arkui",                      # 原有的子系统名
       "components": [                            # 单个子系统下的所有部件集合
         {
           "component": "ace_engine_standard",    # 原有的部件名
           "features": []
         },
         {
           "component": "napi",                   # 原有的部件名
           "features": []
         }
          {
           "component": "component_new1",         # 原有子系统新增的的部件名component_new1
           "features": []
         }
      ]
     },
     {
       "subsystem": "subsystem_new",              #  新增的子系统名
       "components": [
         {
           "component": "component_new2",         # 新增子系统新增的的部件名component_new2
           "features": []
         }
       ]
     },
    ...
    ]
   ```
    成功添加验证：
    - 在输出文件夹的对应子系统文件夹下的部件文件夹下的BUILD.gn文件中module_list包含了新建模块的BUILD.gn中定义的目标。
    - 编译完成后打包到image中去，生成对应的so文件或者二进制文件。

**配置文件说明**

OpenHarmony的配置文件主要有四个。

1. vendor\产品厂商\产品名\config.json

   ```
   {
      "product_name": "MyProduct",
      "version": "3.0",
      "type": "standard",
      "target_cpu": "arm",
      "ohos_version": "OpenHarmony 1.0",
      "device_company": "MyProductVendor",
      "board": "MySOC",
      "enable_ramdisk": true,
      "subsystems": [
        {
          "subsystem": "ace",
          "components": [
            { "component": "ace_engine_lite", "features":[""] }
          ]
        }，
        ...
      ]
   }

   ```
   指明了产品名，产品厂商，产品设备，版本，要编译的系统类型，以及产品包含的子系统。

2. build目录下的subsystem_config.json文件。

   ```
   {
     "arkui": {
       "path": "foundation/arkui",
       "name": "arkui"
     },
     "ai": {
       "path": "foundation/ai",
       "name": "ai"
     },
 	......
    }
   ```
   该文件对子系统进行了说明，我们需要该子系统定义中的name与path，分别表示子系统的名称和所在文件夹路径。

3. 子系统中bundle.json文件。

   ```
   {
       "name": "@ohos/<component_name>",                 # HPM部件英文名称，格式"@组织/部件名称"
       "description": "xxxxxxxxxxxxxxxxxxx",             # 部件功能一句话描述
       "version": "3.1",                                 # 版本号，版本号与OpenHarmony版本号一致
       "license": "MIT",                                 # 部件License
       "publishAs": "code-segment",                      # HPM包的发布方式，当前默认都为code_segment
       "segment": {
           "destPath": ""
       },                                                # 发布类型为code_segment时为必填项，定义发布类型code_segment的代码还原路径（源码路径）
       "dirs": {},                                       # HPM包的目录结构，字段必填内容可以留空
       "scripts": {},                                    # HPM包定义需要执行的脚本，字段必填，值非必填
       "licensePath": "COPYING",
       "readmePath": {
           "en": "README.rst"
       },
       "component": {                                    # 部件属性
           "name": "<component_name>",                   # 部件名称
           "subsystem": "",                              # 部件所属子系统
           "syscap": [],                                 # 部件为应用提供的系统能力
           "features": [],                               # 部件对外的可配置特性列表，一般与build中的sub_component对应，可供产品配置
           "adapted_system_type": [],                    # 轻量(mini)小型(small)和标准(standard)，可以是多个
           "rom": "xxxKB"                                # ROM基线，没有基线写当前值
           "ram": "xxxKB",                               # RAM基线，没有基线写当前值
           "deps": {
               "components": [],                         # 部件依赖的其他部件
               "third_party": []                         # 部件依赖的三方开源软件
           },
           "build": {                                    # 编译相关配置
               "sub_component": ["部件包含模块的gn目标"],  # 部件编译入口
               "inner_kits": [],                         # 部件间接口
               "test": []                                # 部件测试用例编译入口
           }
       }
   }
   ```
   bundle.json文件定义了子系统包含的部件。
   
   每个部件定义它所包含的模块目标component.build.sub_component，以及部件间交互的接口component.build.inner_kits，测试用例component.build.test_list。部件包含的 
   模块目标component.build.sub_component是必须要说明的。

4. 每个模块对应的BUILD.gn文件。
   可以使用提供的模板，也可以使用gn语法规则自定义编写。

### hap的编译

**hap包的构成**

OpenHarmony上的hap包由资源，raw assets，js assets，native库，config.json等部分构成。

**编译系统提供的模板**

编译系统提供了4个模板，用来编译hap包。

模板集成在ohos.gni中，使用之前需要引用build/ohos.gni

ohos_resources

- 声明一个资源目标。资源目标被restool编译之后会生成index文件，hap中会打包资源源文件和index文件。

- 该目标会同时生成资源编译后的ResourceTable.h，直接依赖该目标就可以引用该头文件

- 资源目标的目标名必须以"resources"或"resource"或"res"结尾，否则编译检查时会报错

- 支持的变量:
  
  1. sources: 资源的路径，变量类型是list，可以写多个路径
  2. hap_profile: 编译资源时需要提供对应hap包的config.json
  3. deps: 当前目标的依赖，可选

ohos_assets

- 声明一个资产目标

- 注意拼写：assets不是assert

- assets目标的目标名必须以"assets"或"asset"结尾

- 支持的变量：
  
  1. sources：raw assets所在路径，变量类型是list，可以写多个路径
  2. deps： 当前目标的依赖，可选

ohos_js_assets

- 声明一个JS 资源目标，JS资源是L2 hap包的可执行部分

- JS assets目标的目标名必须以"assets"或"asset"结尾

- 支持的变量：
  
  1. source_dir: JS 资源的路径，变量类型是string，只能写一个
  2. deps: 当前目标的依赖，可选

ohos_hap

- 声明一个hap目标，该目标会生成一个hap包，最终将会打包到system镜像中

- 支持的变量：
  
  1. hap_profile: hap包的config.json
  2. deps: 当前目标的依赖
  3. shared_libraries: 当前目标依赖的native库
  4. hap_name: hap包的名字，可选，默认为目标名
  5. final_hap_path: 用户可以制定生成的hap的位置，可选，final_hap_path中会覆盖hap_name
  6. subsystem_name: hap包从属的子系统名，需要和bundle.json中的名字对应，否则将导致无法安装到system镜像中
  7. part_name: hap包从属的部件名，同subsystem_name
  8. js2abc: 是否需要将该hap包转换为ARK的字节码
     签名篇见：[配置应用签名]( https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-debugging-and-running-0000001263040487#section17660437768)
  9. certificate_profile: hap对应的授权文件，用于签名
  10. certificate_file: 证书文件，证书文件和授权文件，应用开发者需要去openharmony官网申请
  11. keystore_path: keystore文件，用于签名
  12. keystore_password: keystore的密码，用于签名
  13. key_alias: key的别名
  14. module_install_name:安装时的hap包名称
  15. module_install_dir: 安装到system中的位置，默认安装在system/app目录下
  
  **hap开发示例**

    ```
    import("//build/ohos.gni") # 引用ohos.gni
    ohos_hap("clock") {
      hap_profile = "./src/main/config.json" # config.json
      deps = [
        ":clock_js_assets", # JS assets
        ":clock_resources", # 资源
      ]
      shared_libraries = [
        "//third_party/libpng:libpng", # native库
      ]
      certificate_profile = "../signature/systemui.p7b" # Cer文件
      hap_name = "SystemUI-NavigationBar" # 名字
      part_name = "prebuilt_hap"
      subsystem_name = "applications"
    }
    ohos_js_assets("clock_js_assets") {
      source_dir = "./src/main/js/default"
    }
    ohos_resources("clock_resources") {
      sources = [ "./src/main/resources" ]
      hap_profile = "./src/main/config.json"
    }
    ```

### 开源软件Notice收集策略说明

**收集目标**

只收集打包到镜像里面的模块对应的License；不打包的都不收集，比如构建过程使用的工具（如clang/python/ninja等）。

静态库本身是不会被打包的，一般是作为动态库或者可执行程序的一部分被打包到系统中的，为了确保完备，静态库的都会收集。

最终合并的NOTICE.txt要体现出镜像中每个文件都是用了哪些License，模块和License要有对应关系。

最终合并的NOTICE.txt文件在/system/etc/ 目录下。

**收集规则**

按照优先级收集License

1. 模块在BUILD.gn中直接声明自己使用的License文件，优先级最高。如下图示例：

   ```
      ohos_shared_library("example") {
          ...
          license_file = "path-to-license-file"
          ...
      }
   ```

2. 如果模块没有显式声明，那么编译脚本会在BUILD.gn所在的当前目录中查找Readme.OpenSource文件，解析该文件，找出该文件中声明的license，将其作为模块的License。
   如果Readme.OpenSource文件中配置的license文件不存在，直接报错。

3. 如果Readme.OpenSource文件不存在，编译脚本会从当前目录开始，向上层目录寻找（一直找到源码的根目录），默认查找License/Copyright/Notice三个文件，如果找到，则将其作为模块的License。

4. 如果上面三种方式都未找到license，则使用默认的license作为该模块的license；默认license是Apache2.0 License。

需要注意及检查的问题

1. 三方的开源软件，比如openssl，icu等，这部分软件基本上在源码目录下都是要求配置Readme.OpenSource，要检查Readme.OpenSource文件是否和BUILD.gn文件在同一个目录，以及Reame.OpenSource文件中配置的License文件是否存在以及真是有效。

2. 代码目录下，如果代码使用的不是Apache2.0 License，需要在目录下提供对应的License文件，或者直接在模块中指定license_file。

3. 如果BUILD.gn中添加的源码文件不是当前目录的，需要检查下源码文件所在仓下的license是否和BUILD.gn文件所在仓的一致，不一致的需要处理。