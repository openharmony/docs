# HAP编译构建指导

## 概述

### 基本概念
| 术语 | 含义 |
| -------------- | ---------------------- |
| HAP            | Harmony Ability Package，一个HAP文件包含应用的所有内容，由代码、资源、三方库及应用配置文件组成，其文件后缀名为.hap。 |
| Ability        | 应用的重要组成部分，是应用所具备能力的抽象。Ability是系统调度应用的最小单元，是能够完成一个独立功能的组件，一个应用可以包含一个或多个Ability。 |
| FA             | Feature Ability，是FA模型的Ability框架下具有UI界面的Ability类型，用于与用户进行交互。Feature Ability唯一对应一种模板，即Page模板（Page Ability）。 |
| PA             | Particle Ability，是在FA模型的Ability框架下无界面的Ability，主要为Feature Ability提供服务与支持，例如作为后台服务提供计算能力，或作为数据仓库提供数据访问能力。Particle Ability有三种模板，分别为Service模板（Service Ability）、Data模板（Data Ability）、以及Form模板（Form Ability）。 |
| FA模型         | 两种Ability框架模型结构的其中一种。是Ability框架在API 8及更早版本采用FA模型。FA模型将Ability分为FA（Feature Ability）和PA（Particle Ability）两种类型，其中FA支持Page Ability模板，PA支持Service ability、Data ability、以及Form ability模板。详情可参考[FA模型综述](../../application-dev/quick-start/application-package-structure-fa.md)。 |
| Stage模型 | 两种Ability框架模型结构的其中一种。从API 9开始支持。Stage模型将Ability分为Ability和ExtensionAbility两大类，其中ExtensionAbility又被扩展为ServiceExtensionAbility、FormExtensionAbility、DataShareExtensionAbility等等一系列ExtensionAbility。 |

### 功能简介
提供HAP编译构建功能，支持FA模型、Stage模型。

## 开发指导

### 编译子系统提供的模板
#### ohos_hap

声明一个HAP目标，该目标会生成一个HAP，最终将会打包到system镜像中。

| 支持的变量 | 说明 |
| --------- | ---- |
| hap_profile | HAP的config.json，Stage模型对应module.json。 |
| raw_assets | 原始assets，这些assets会直接拷贝到HAP的assets目录下。 |
| resources | 资源文件，编译后放置在assets/entry/resources目录下 |
| js_assets | js资源，编译后放置在assets/js/default目录下。|
| ets_assets | ets资源，编译后放置在assets/js/default目录下 |
| deps | 当前目标的依赖 |
| shared_libraries | 当前目标依赖的native库 |
| hap_name | HAP的名字，可选，默认为目标名 |
| final_hap_path | 用户可以制定生成的HAP的位置，可选，final_hap_path中会覆盖hap_name。|
| subsystem_name | HAP从属的子系统名，需要和ohos.build中的名字对应，否则将导致无法安装到system镜像中。|
| part_name | HAP从属的部件名，同subsystem_name。|
| js2abc | 是否需要将该HAP的js代码转换为ARK的字节码。|
| ets2abc | 是否需要将该HAP的ets代码转换为ARK的字节码。|
| certificate_profile | HAP对应的授权文件，用于签名。|
| certificate_file | 证书文件，证书文件和授权文件，应用开发者需要去OpenHarmony官网申请。|
| keystore_path | keystore文件，用于签名。|
| keystore_password | keystore的密码，用于签名。|
| key_alias | key的别名。|
| module_install_name | 安装时的HAP名称。|
| module_install_dir | 安装到system中的位置，默认安装在system/app目录下。|
| js_build_mode | 可选，用于配置HAP是“release”还是“debug”模型编译，默认“release”。|

#### ohos_app_scope
声明一个HAP的AppScope模块，该目标的app_profile和sources会在编译时拼接到具体的entry内编译，该模板只在Stage模型下使用。

| 支持的变量 | 说明 |
| --------- | ---- |
| app_profile | HAP的AppScope中的app.json，只在Stage模型下使用。|
| sources | HAP的AppScope中的资源resources，只在Stage模型下使用。|

#### ohos_js_assets
js或ets代码，编译后放置在assets/js/default目录下，stage模型根据代码分别放置到js或ets目录。

| 支持的变量 | 说明 |
| --------- | ---- |
| hap_profile | HAP的config.json，Stage模型对应module.json。|
| source_dir | js或ets代码路径，兼容FA模型的单ability配置到ability目录。|
| ets2abc | 当前为ets代码，主要用于卡片配置，其他应用可不配，使用ohos_hap中的配置。|
| js2abc | 当前为js代码，主要用于卡片配置，其他应用可不配，使用ohos_hap中的配置。|

#### ohos_assets
原始assets，这些assets会直接拷贝到HAP的assets目录下。

| 支持的变量 | 说明 |
|---------- | ---- |
| sources | 原始assets的路径。|

#### ohos_resources
资源文件，FA模型编译后放置在assets/entry/resources目录下，Stage模型编译后放置在resources目录下。

| 支持的变量 | 说明 |
| --------- | ---- |
| hap_profile | HAP的config.json，Stage模型对应module.json。|
| sources | 资源文件路径。|
| deps | 当前目标的依赖。Stage模型需要配置对ohos_app_scope目标的依赖。|

### 操作步骤

1. 将开发完成的应用example放到applications/standard/目录下。

2. 配置gn脚本applications/standard/example/BUILD.gn，FA模型简单示例如下（更多BUILD.gn配置见[gn脚本配置示例](#gn脚本配置示例)）：
   ```
   import("//build/ohos.gni") # 引用ohos.gni

   ohos_hap("example") {
     hap_profile = "./src/main/config.json" # config.json
     js_assets = ["./src/main/js/default"]
     raw_assets = ["./raw_assets"]
     resources = ["./src/main/resources"]
     shared_libraries = [
       "//third_party/libpng:libpng", # native库
     ]
     certificate_profile = "../signature/systemui.p7b" # Cer文件
     hap_name = "SystemUI-NavigationBar" # 名字
     part_name = "prebuilt_hap"
     subsystem_name = "applications"
   }
   ```

3. 修改applications/standard/hap/ohos.build，示例如下：
   ```
   {
     "subsystem": "applications",
     "parts": {
       "prebuilt_hap": {
         "module_list": [
           ...
           "//applications/standard/example:example" # 添加编译目标
         ]
       }
     }
   }
   ```

4. 编译命令：
   ```
   # 全量编译
   ./build.sh --product-name {product_name}

   # 单独编译HAP
   ./build.sh --product-name {product_name} --build-target applications/standard/example:example
   ```

5. 编译产物，FA模型简单例子HAP解压视图如下：
   ```
     Length      Date    Time    Name
   ---------  ---------- -----   ----
        1439  2009-01-01 00:00   assets/raw_assets                                 -----> raw_assets
         354  2009-01-01 00:00   assets/entry/resources.index                      ------> resources
           1  2009-01-01 00:00   assets/entry/resources/base/media/attributes.key  ------> resources
           1  2009-01-01 00:00   assets/entry/resources/base/media/constants.key   ------> resources
           1  2009-01-01 00:00   assets/entry/resources/base/media/contents.key    ------> resources
        6790  2009-01-01 00:00   assets/entry/resources/base/media/icon.png        ------> resources
           1  2009-01-01 00:00   assets/entry/resources/base/media/nodes.key       ------> resources
       11170  2009-01-01 00:00   assets/js/default/app.js                          ------> js_assets
          48  2009-01-01 00:00   assets/js/default/i18n/en-US.json                 ------> js_assets
          50  2009-01-01 00:00   assets/js/default/i18n/zh-CN.json                 ------> js_assets
         224  2009-01-01 00:00   assets/js/default/manifest.json                   ------> js_assets
       41481  2009-01-01 00:00   assets/js/default/pages/index/index.js            ------> js_assets
         909  2009-01-01 00:00   config.json                                       ------> hap_profile
      266248  2009-01-01 00:00   libs/libpng.z.so                                  ------> shared_libraries
   ```

### gn脚本配置示例
- FA模型多ability示例

   ```
   import("//build/ohos.gni")

   ohos_hap("dataability") {
     hap_profile = "entry/src/main/config.json"
     deps = [
       ":dataability_js_assets",
       ":dataability_resources",
     ]
     certificate_profile = "signature/openharmony_sx.p7b"
     hap_name = "dataability"
     part_name = "prebuilt_hap"
     subsystem_name = "applications"
   }

   ohos_js_assets("dataability_js_assets") {
     ets2abc = true
     source_dir = "entry/src/main/ets"
     hap_profile = "entry/src/main/config.json"
   }

   ohos_resources("dataability_resources") {
     sources = [
       "entry/src/main/resources",
     ]
     hap_profile = "entry/src/main/config.json"
   }

   ```

- FA模型Js卡片示例

   ```
   import("//build/ohos.gni")
   
   ohos_hap("FormOfFaJs") {
     hap_profile = "entry/src/main/config.json"
     deps = [
       ":FormOfFaJs_js_assets",
       ":FormOfFaJs_resources",
     ]
     certificate_profile = "signature/openharmony_sx.p7b"
     hap_name = "FormOfFaJs"
     part_name = "prebuilt_hap"
     subsystem_name = "applications"
   }
   
   ohos_js_assets("FormOfFaJs_js_assets") {
     hap_profile = "entry/src/main/config.json"
     js2abc = true
     source_dir = "entry/src/main/js"
   }
   
   ohos_resources("FormOfFaJs_resources") {
     sources = [
       "entry/src/main/resources",
     ]
     hap_profile = "entry/src/main/config.json"
   }
   ```

- FA模型Ets卡片示例

   ```
   import("//build/ohos.gni")
   
   ohos_hap("FormOfFaEts") {
     hap_profile = "entry/src/main/config.json"
     deps = [
       ":FormOfFaEts_js_assets",
       ":FormOfFaEts_form_js_assets",
       ":FormOfFaEts_resources",
     ]
     certificate_profile = "signature/openharmony_sx.p7b"
     hap_name = "FormOfFaEts"
     part_name = "prebuilt_hap"
     subsystem_name = "applications"
   }
   
   ohos_js_assets("FormOfFaEts_js_assets") {
     hap_profile = "entry/src/main/config.json"
     ets2abc = true
     source_dir = "entry/src/main/ets"
   }
   
   ohos_js_assets("FormOfFaEts_form_js_assets") {
     hap_profile = "entry/src/main/config.json"
     js2abc = true
     source_dir = "entry/src/main/js"
   }
   
   ohos_resources("FormOfFaEts_resources") {
     sources = [
       "entry/src/main/resources",
     ]
     hap_profile = "entry/src/main/config.json"
   }
   ```

- Stage模型简单示例

   ```
   import("//build/ohos.gni")
   
   ohos_hap("actmoduletest") {
     hap_profile = "entry/src/main/module.json"
     deps = [
       ":actmoduletest_js_assets",
       ":actmoduletest_resources",
     ]
     certificate_profile = "signature/openharmony_sx.p7b"
     hap_name = "actmoduletest"
     part_name = "prebuilt_hap"
     subsystem_name = "applications"
   }
   
   ohos_app_scope("actmoduletest_app_profile") {
     app_profile = "AppScope/app.json"
     sources = [ "AppScope/resources" ]
   }
   
   ohos_js_assets("actmoduletest_js_assets") {
     ets2abc = true
     source_dir = "entry/src/main/ets"
   }
   
   ohos_resources("actmoduletest_resources") {
     sources = [
       "entry/src/main/resources",
     ]
     deps = [
       ":actmoduletest_app_profile",
     ]
     hap_profile = "entry/src/main/module.json"
   }
   ```

- Stage模型卡片示例

   ```
   import("//build/ohos.gni")
   
   ohos_hap("FormOfStageEts") {
     hap_profile = "entry/src/main/module.json"
     deps = [
       ":FormOfStageEts_js_assets",
       ":FormOfStageEts_form_js_assets",
       ":FormOfStageEts_resources",
     ]
     js_build_mode = "debug"  # 默认release
     certificate_profile = "signature/openharmony_sx.p7b"
     hap_name = "FormOfStageEts"
     part_name = "prebuilt_hap"
     subsystem_name = "applications"
   }
   
   ohos_js_assets("FormOfStageEts_js_assets") {
     hap_profile = "entry/src/main/module.json"
     ets2abc = true
     source_dir = "entry/src/main/ets"
   }
   
   ohos_js_assets("FormOfStageEts_form_js_assets") {
     hap_profile = "entry/src/main/module.json"
     js2abc = true
     source_dir = "entry/src/main/js"
   }
   
   ohos_app_scope("FormOfStageEts_app_profile") {
     app_profile = "AppScope/app.json"
     sources = [ "AppScope/resources" ]
   }
   
   ohos_resources("FormOfStageEts_resources") {
     sources = [
       "entry/src/main/resources",
     ]
     deps = [
       ":FormOfStageEts_app_profile",
     ]
     hap_profile = "entry/src/main/module.json"
   }
   ```
