# HAP Build Guide

## Overview

### Basic Concepts
| Term| Description|
| -------------- | ---------------------- |
| HAP            | Harmony Ability Package, released as a HAP file, with the file name extension .hap. One HAP file describes all content of an application, including code, resources, third-party libraries, and an application configuration file.|
| Ability        | An abstraction of a functionality that an application can provide. It is the minimum unit for the system to schedule the application. An application can contain one or more **Ability** instances.|
| FA             | Feature Ability, an ability that provides a UI for user interaction in the ability framework of the FA model. The FA supports only the Page ability template.|
| PA             | Particle Ability, an ability that does not have a UI in the ability framework of the FA model. It provides services and support for FAs. For example, a PA can function as a background service to provide computing power or as a data store to provide data access capabilities. The PA supports three types of templates: Service, Data, and Form ability templates.|
| FA model        | One of the two ability framework models. The FA model applies to application development using API version 8 and earlier versions. The FA model provides FAs and PAs. The FA supports the Page ability template, and the PA supports the Service, Data, and Form ability templates. For details, see [FA Model Overview](../../application-dev/quick-start/application-package-structure-fa.md).|
| Stage model| One of the two ability framework models. The stage model applies to application development using API version 9 and later versions. The stage model provides abilities and Extension abilities. The latter ones are extended to Service Extension abilities, Form Extension abilities, Data Share Extension abilities, and more.|

### Function
The HAP provides HAP build functions and supports FA and stage models.

## How to Develop

### OpenHarmony Templates
#### ohos_hap

This template declares a HAP target, which generates a HAP that will be packaged into the system image.

| Variable| Description|
| --------- | ---- |
| hap_profile | Configuration file of the HAP. It is **config.json** for the FA model and **module.json** for the stage model.|
| raw_assets | Raw assets, which are directly copied to the **assets** directory of the HAP.|
| resources | Resource files, which are stored in the **assets/entry/resources** directory after build.|
| js_assets | JS resources, which are stored in the **assets/js/default** directory after built.|
| ets_assets | eTS resources, which are stored in the **assets/js/default** directory after built.|
| deps | Dependencies of the target.|
| shared_libraries | Native libraries on which the target depends.|
| hap_name | HAP name, which is optional. By default, it is the target name.|
| final_hap_path | Path of the generated HAP. This variable is optional. It takes precedence over **hap_name**.|
| subsystem_name | Name of the subsystem that the HAP belongs to. The name must be consistent with that defined in **ohos.build**. Otherwise, the HAP will fail to be installed in the system image.|
| part_name | Name of the part that the HAP belongs to. The name must be the same as that of **subsystem_name**.|
| js2abc | Whether to convert JS code of the HAP into ARK bytecode.|
| ets2abc | Whether to convert eTS code of the HAP into ARK bytecode.|
| certificate_profile | Certificate profile used to sign the HAP.|
| certificate_file | Certificate file. The certificate and profile must be applies from the official OpenHarmony website.|
| keystore_path | Keystore file, which is used for signature.|
| keystore_password | Keystore password, which is used for signature.|
| key_alias | Alias of a key.|
| module_install_name | Name of the HAP during installation.|
| module_install_dir | Installation path of the HAP in the system. The default path is **system/app**.|
| js_build_mode | Build mode of the HAP, which can be **release** or **debug**. This variable is optional. The default value is **release**.|

#### ohos_app_scope
Declares the AppScope module of the HAP. The **app_profile** and **sources** variables of the target will be concatenated to a specific **entry** for build. This template is used only in the stage model.

| Variable| Description|
| --------- | ---- |
| app_profile | **app.json** file in the AppScope module of the HAP. This variable is used only in the stage model.|
| sources | Resources in the AppScope module of the HAP. This variable is used only in the stage model.|

#### ohos_js_assets
Provides JS or eTS code, which is stored in the **assets/js/default** directory after built. In the stage model, this template is stored in the **assets/js** or **assets/ets** directory, depending on the programming language.

| Variable| Description|
| --------- | ---- |
| hap_profile | Configuration file of the HAP. It is **config.json** for the FA model and **module.json** for the stage model.|
| source_dir | JS or eTS code path, which is compatible with the **ability** directory of the FA model.|
| ets2abc | eTS code path. This variable is used only for widget configuration. In other development scenarios, use the configuration in the **ohos_hap** template.|
| js2abc | JS code path. This variable is used only for widget configuration. In other development scenarios, use the configuration in the **ohos_hap** template.|

#### ohos_assets
Provides raw assets, which are directly copied to the **assets** directory of the HAP.

| Variable| Description|
|---------- | ---- |
| sources | Path of the raw assets.|

#### ohos_resources
Resource files, which are stored in the **assets/entry/resources** directory for the FA model and in the **resources** directory for the stage model.

| Variable| Description|
| --------- | ---- |
| hap_profile | Configuration file of the HAP. It is **config.json** for the FA model and **module.json** for the stage model.|
| sources | Resource file path.|
| deps | Dependencies of the target. You must configure dependencies on the **ohos_app_scope** target for the stage model.|

### Procedure

1. Save the developed application example to the **applications/standard/** directory.

2. Configure the GN script **applications/standard/example/BUILD.gn**.<br>The following is an example of the FA model. For details about more **BUILD.gn** configurations, see [GN Script Configuration Example](#gn-script-configuration-example).
   ```
   import("//build/ohos.gni") # Import ohos.gni.

   ohos_hap("example") {
     hap_profile = "./src/main/config.json" # config.json
     js_assets = ["./src/main/js/default"]
     raw_assets = ["./raw_assets"]
     resources = ["./src/main/resources"]
     shared_libraries = [
       "//third_party/libpng:libpng", # Native library
     ]
     certificate_profile = "../signature/systemui.p7b" # Certificate profile
     hap_name = "SystemUI-NavigationBar" # HAP name
     part_name = "prebuilt_hap"
     subsystem_name = "applications"
   }
   ```

3. Modify the **applications/standard/hap/ohos.build** file.<br>The following is an example:
   ```
   {
     "subsystem": "applications",
     "parts": {
       "prebuilt_hap": {
         "module_list": [
           ...
           "//applications/standard/example:example" # Add a build target.
         ]
       }
     }
   }
   ```

4. Start build.
   ```
   # Perform full building.
   ./build.sh --product-name {product_name}

   # Build the HAP only.
   ./build.sh --product-name {product_name} --build-target applications/standard/example:example
   ```


The build target is generated. The following shows the decompressed HAP in the FA model.
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

### GN Script Configuration Example
- Example of multiple abilities in the FA model

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

- Example of a JS widget in the FA model

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

- Example of an eTS widget in the FA model

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

- Example of the stage model

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

- Example of a widget in the stage model

   ```
   import("//build/ohos.gni")
   
   ohos_hap("FormOfStageEts") {
     hap_profile = "entry/src/main/module.json"
     deps = [
       ":FormOfStageEts_js_assets",
       ":FormOfStageEts_form_js_assets",
       ":FormOfStageEts_resources",
     ]
     js_build_mode = "debug" # The default value is release.
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
