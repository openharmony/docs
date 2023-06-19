# Atomic Service

## Pre-loading by HAP Type

### HAP File Implementation

To speed up the initial startup of an atomic service, you can configure it to load on demand with the use of HAP files. HAP files of an atomic service are classified as entry-type or feature-type. The entry-type HAP file contains the page code and related resources required for starting up the atomic service. The feature-type HAP files contain the rest of the code and resources. To start the atomic service, the user only needs to download and install the entry-type HAP file, which minimizes the time for downloading the atomic service.

#### How to Use

You create HAP files of an atomic service by creating an atomic service project in DevEco Studio. The basic project directory structure is as follows:

```
├── AppScope
|    ├── resources
|    └── app.json5
├── entry
|    └── src/main
|       ├── ets
|       ├── resources
|       └── module.json5
├── feature
|    └── src/main
|       ├── ets
|       ├── resources
|       └── module.json5
├── library
|    └── src/main
|       ├── ets
|       ├── resources
|       └── module.json5
├── node_modules
```

Note that you must set the **bundleType** field to **atomicService** in the [app.json5](app-configuration-file.md) file, which is located in the **AppScope** folder. The following is an example of the file content:

```json
{
  "app": {
    "bundleName": "com.example.hmservice",
    "bundleType":"atomicService",
    "vendor": "example",
    "versionCode": 1000000,
    "versionName": "1.0.0",
    "icon": "$media:app_icon",
    "label": "$string:app_name",
    "targetAPIVersion": 9
  }
}
```

For details about HAP files, see [Multi-HAP Design Objectives](multi-hap-objective.md).

#### Restrictions

1. The **installationFree** field must be set to **true** in each module-specific configuration file [module.json5](module-configuration-file.md) file.

2. When packaging an atomic service, comply with the following size rules:

- The total size of HAP files cannot exceed 10 MB.

- The size of a HAP file itself and all its dependent [HSP](in-app-hsp.md) cannot exceed 2 MB.


### Pre-loading Implementation

You can configure the system to automatically pre-download required modules when the atomic service enters a module, thereby speeding up module access.

Currently, pre-loading can be implemented only through configuration, not by invoking APIs.

#### How to Use

Pre-loading is triggered after the first frame of the newly accessed module is rendered. You can configure what to pre-load for a module, by setting the **preloads** field under **atomicService** in the [module.json5](module-configuration-file.md) file of the module. The following is an example of the **module.json5** file of the **entry** module, saved in **entry/src/main**:

```json
{
  "module": {
    "name": "entry",
    "type": "entry",
    "srcEntry": "./ets/Application/MyAbilityStage.ts",
    "description": "$string:entry_desc",
    "mainElement": "MainAbility",
    "deviceTypes": [
      "default",
      "tablet"
    ],
    "deliveryWithInstall": true,
    "installationFree": true,
    "pages": "$profile:main_pages",
    "atomicService": {
      "preloads": [
        {
          "moduleName": "feature"
        }
      ]
    },
    "abilities": [
      {
        "name": "MainAbility",
        "srcEntry": "./ets/MainAbility/MainAbility.ts",
        "description": "$string:MainAbility_desc",
        "icon": "$media:icon",
        "label": "$string:MainAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:white",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      }
    ]
  }
}
```

In this example, the system automatically pre-loads the **feature** module after the first frame of the **entry** module is rendered.

#### Restrictions

[moduleType](../reference/apis/js-apis-bundleManager.md#moduletype) corresponding to moduleName in the **preloads** list cannot be entry.

## Using Dynamic Shared Packages in Atomic Services

A [Harmony Shared Package (HSP)](shared-guide.md) is a dynamic shared package for sharing code, C++ libraries, resources, and configuration files among modules.
For details about how to use the HSP within an atomic service, see [In-Application HSP Development](in-app-hsp.md).

#### How to Use

Assume that the project directory structure is as follows:
```
├── AppScope
|    ├── resources
|    └── app.json5
├── entry
|    └── src/main
|       ├── ets
|           ├── entryAbility
|           └── pages
|               └── Index.ets
|       ├── resources
|       └── module.json5
├── feature
|    └── src/main
|       ├── ets
|       ├── resources
|       └── module.json5
├── library
|    └── src/main
|       ├── ets
|           └── pages
|               └── menu.ets
|       ├── resources
|       └── module.json5
├── node_modules
```

If you want to add a button in the **entry** module to jump to the menu page (**library/src/main/ets/pages/menu.ets**) in the **library** module, you can write the following code in the **entry/src/main/ets/MainAbility/Index.ets** file of the **entry** module:

```ts
import router from '@ohos.router';

@Entry
@Component
struct Index {
    @State message: string = 'Hello World';

    build() {
    Row() {
        Column() {
        Text(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        // Add a button to respond to user clicks.
        Button() {
            Text('click to menu')
            .fontSize(30)
            .fontWeight(FontWeight.Bold)
        }
        .type(ButtonType.Capsule)
        .margin({
            top: 20
        })
        .backgroundColor('#0D9FFB')
        .width('40%')
        .height('5%')
        // Bind click events.
        .onClick(() => {
            router.pushUrl({
              url: '@bundle:com.example.hmservice/library/ets/pages/menu'
            }).then(() => {
              console.log("push page success");
            }).catch(err => {
              console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);
            })
        })
      .width('100%')
    }
    .height('100%')
    }
  }
}
```

The input parameter **url** of the **router.pushUrl** API is as follows:
```ts
'@bundle:com.example.hmservice/library/ets/pages/menu'
```
The **url** content template is as follows:
```ts
'@bundle:bundle name/module name/path/page file name (without the extension .ets)'
```
