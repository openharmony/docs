# HSP
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

A Harmony Shared Package (HSP) is a dynamic shared package that can contain code, C++ libraries, resource files, and configuration files (also called profiles) and allows for code and resource sharing. An HSP is released with the Application Package (App Pack) of the host application, shares a process with the host application, and has the same bundle name and lifecycle as the host application.
> **NOTE**
> 
> In-app HSP: a type of HSP that is closely coupled with an application bundle name (**bundleName**) during compilation and can be used only by the specified application. This topic mainly describes in-app HSP.
> 
> [Integrated HSP](integrated-hsp.md): a type of HSP that is not coupled with specific application bundle names during building and publishing. The toolchain can automatically replace the bundle name of the integrated HSP with that of the host application and generate a new HSP as the installation package of the host application. The new HSP also belongs to the in-app HSP of the host application.

## Use Scenarios
- By storing code and resource files shared by multiple HAPs/HSPs in one place, the HSP significantly improves the reusability and maintainability of the code and resource files. Better yet, because only one copy of the HSP code and resource files is retained during building and packaging, the size of the application package is effectively controlled.

- The HSP is [loaded on demand](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-modular-design#section28312051291) during application running, which helps improve application performance.

- The integrated HSP allows for code and resource sharing across applications in the same organization.

## Constraints

- An HSP must be installed and run with the HAP that depends on it. It cannot be installed or run independently on a device. Since API version 18, the HAP version must be later than or equal to the HSP version. For API version 17 and earlier versions, the HSP version must be the same as the HAP version.
- Since API version 14, HSP supports the declaration of the [UIAbility](../application-models/uiability-overview.md#declaration-configuration) component in the configuration file. However, UIAbility with entry capabilities (that is, **entity.system.home** and **ohos.want.action.home** are configured for the **skill** tag) is not supported. For details about how to configure a UIAbility, see [Adding a UIAbility to a Module](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-add-new-ability#section18658758104318). The method of starting a UIAbility in an HSP is the same as that described in [Starting UIAbility in the Same Application](../application-models/uiability-intra-device-interaction.md). For API version 13 and earlier versions, the [UIAbility](../application-models/uiability-overview.md#declaration-configuration) component cannot be declared in the configuration file.
- Since API version 18, HSP supports the declaration of the [ExtensionAbility](../application-models/extensionability-overview.md) component in the configuration file. However, ExtensionAbility with entry capabilities (that is, **entity.system.home** and **ohos.want.action.home** are configured for the **skill** tag) is not supported. For details about how to configure an ExtensionAbility in an HSP, see [Adding an ExtensionAbility to a Module](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-add-new-ability#section18891639459). For API version 17 and earlier versions, the [ExtensionAbility](../application-models/extensionability-overview.md) component cannot be declared in the configuration file.
- An HSP can depend on other HARs or HSPs, and can be depended on or integrated by HAPs or HSPs. However, cyclic dependency and dependency transfer are not supported.

> **NOTE**
> 
> Cyclic dependency: For example, there are three HSPs. HSP-A depends on HSP-B, HSP-B depends on HSP-C, and HSP-C depends on HSP-A.
>
> Dependency transfer: For example, there are three HSPs. HSP-A depends on HSP-B, and HSP-B depends on HSP-C. Dependency transfer is not supported indicating that HSP-A can use the methods and components of HSP-B, but cannot directly use that of HSP-C.


## Creating an HSP
Create an HSP module for calling C++ code on DevEco Studio and turn on **Enable native** on the **Configure New Module** page. For details, see [Creating an HSP Module](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hsp#section7717162312546). The following uses the **library** module as an example. The basic project directory structure is as follows:
```
MyApplication
├── library
│   ├── src
│   │   └── main
|   |       ├── cpp
|   |       |   ├── CMakeLists.txt    // Configuration file for compiling native C++ code
|   |       |   └── napi_init.cpp     // C++ file for initializing the NAPI module
│   │       ├── ets
│   │       │   └── pages
│   │       │       └── index.ets     // Page file of the library module
│   │       ├── resources             // Resources of the library module
│   │       └── module.json5          // Configuration file of the library module
│   ├── oh-package.json5              // Module-level configuration file
│   ├── index.ets                     // Entry file
│   └── build-profile.json5           // Module-level configuration file
└── build-profile.json5               // Project-level configuration file
```

## Developing an HSP


You can export the ArkUI components, APIs, and other resources of an HSP for other HAPs or HSPs in the same application to reference.

### Exporting ArkUI Components
Use **export** to export ArkUI components. The sample code is as follows:
```ts
// library/src/main/ets/components/MyTitleBar.ets
@Component
export struct MyTitleBar {
  build() {
    Row() {
      Text($r('app.string.library_title'))
        .id('library')
        .fontFamily('HarmonyHeiTi')
        .fontWeight(FontWeight.Bold)
        .fontSize(32)
        .fontColor($r('app.color.text_color'))
    }
    .width('100%')
  }
}
```
Declare the APIs exposed to external systems in the entry file **index.ets**.
```ts
// library/index.ets
export { MyTitleBar } from './src/main/ets/components/MyTitleBar';
```


### Exporting Classes and Methods
Use **export** to export classes and methods. The sample code is as follows:
```ts
// library/src/main/ets/utils/test.ets
export class Log {
  static info(msg: string): void {
    console.info(msg);
  }
}

export function add(a: number, b: number): number {
  return a + b;
}

export function minus(a: number, b: number): number {
  return a - b;
}
```
Declare the APIs exposed to external systems in the entry file **index.ets**.
```ts
// library/index.ets
export { Log, add, minus } from './src/main/ets/utils/test';
```
### Exporting Native Methods
The HSP can contain .so files compiled in C++. The HSP indirectly exports the native method in the .so file. In this example, the **multi** API in the **liblibrary.so** file is exported.
```ts
// library/src/main/ets/utils/nativeTest.ets
import native from 'liblibrary.so';

export function nativeMulti(a: number, b: number): number {
  let result: number = native.multi(a, b);
  return result;
}
```

Declare the APIs exposed to external systems in the entry file **index.ets**.
```ts
// library/index.ets
export { nativeMulti } from './src/main/ets/utils/nativeTest';
```

### Accessing Resources in an HSP Through $r
More often than not, you may need to use resources, such as strings and images, in components. For components in an HSP, such resources are typically placed in the HSP package, rather than in the package where the HSP is invoked, for the purpose of complying with the principle of high cohesion and low coupling.

In a project, application resources are referenced in the $r/$rawfile format. You can use **$r**/**$rawfile** to access resources in the **resources** directory of the current module. For example, you can use **$r("app.media.example")** to access the **src/main/resources/base/media/example.png** image stored in the **resources** directory. For details about how to use **$r**/**$rawfile**, see [Resource Categories and Access](./resource-categories-and-access.md).

To avoid reference errors, do not use relative paths. For example,
if you use **Image("../../resources/base/media/example.png")**, the image actually used will be the one in the directory of the module that invokes the HSP. That is, if the module that invokes the HSP is **entry**, then the image used will be **entry/src/main/resources/base/media/example.png**.

```ts
// library/src/main/ets/pages/Index.ets
// Correct
Image($r('app.media.example'))
  .id('example')
  .borderRadius('48px')
// Incorrect
Image("../../resources/base/media/example.png")
  .id('example')
  .borderRadius('48px')
```

### Exporting Resources from HSP
When resources in an HSP need to be exported for cross-package access, it is recommended that a resource manager class be implemented to encapsulate the exported resources. In this way:
- You can keep resources well under your control, eliminating the need for exporting resources that do not need to be exposed.
- The invoking module does not need to be aware of the internal resource names of the HSP, or make adaptation to changes in these internal resource names.

The implementation is as follows:

Encapsulate the resources that need to be published into a resource management class.  
```ts
// library/src/main/ets/ResManager.ets
export class ResManager{
  static getPic(): Resource{
    return $r('app.media.pic');
  }
  static getDesc(): Resource{
    return $r('app.string.shared_desc');
  }
}
```

Declare the APIs exposed to external systems in the entry file **index.ets**.
```ts
// library/index.ets
export { ResManager } from './src/main/ets/ResManager';
```



## Using an HSP

You can reference APIs in an HSP and implement page redirection in the HSP through page routing.

### Referencing APIs
To use APIs in the HSP, first configure the dependency on the HSP in the **oh-package.json5** file of the module that needs to call the APIs (called the invoking module). For details, see [Referencing a Shared Package](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-har-import).
You can then call the external APIs of the HSP in the same way as calling the APIs in the HAR. In this example, the external APIs are the following ones exported from **library**:

```ts
// library/index.ets
export { Log, add, minus } from './src/main/ets/utils/test';
export { MyTitleBar } from './src/main/ets/components/MyTitleBar';
export { ResManager } from './src/main/ets/ResManager';
export { nativeMulti } from './src/main/ets/utils/nativeTest';
```
The APIs can be used as follows in the code of the invoking module:
```ts
// entry/src/main/ets/pages/index.ets
import { Log, add, MyTitleBar, ResManager, nativeMulti } from 'library';
import { BusinessError } from "@kit.BasicServicesKit";
import { application} from '@kit.AbilityKit';

const TAG = 'Index';

@Entry
@Component
struct Index {
  @State message: string = '';

  build() {
    Column() {
      List() {
        ListItem() {
          MyTitleBar()
        }
        .margin({ left: '35px', top: '32px' })

        ListItem() {
          Text(this.message)
            .fontFamily('HarmonyHeiTi')
            .fontSize(18)
            .textAlign(TextAlign.Start)
            .width('100%')
            .fontWeight(FontWeight.Bold)
        }
        .width('685px')
        .margin({ top: 30, bottom: 10 })

        ListItem() {
          // Resource object returned by ResManager, which can be passed to a component for direct use or be extracted.
          Image(ResManager.getPic())
            .id('image')
            .borderRadius('48px')
        }
        .width('685px')
        .margin({ top: 10, bottom: 10 })
        .padding({ left: 12, right: 12, top: 4, bottom: 4 })

        ListItem() {
          Text($r('app.string.add'))
            .fontSize(18)
            .textAlign(TextAlign.Start)
            .width('100%')
            .fontWeight(500)
            .height('100%')
        }
        .id('add')
        .borderRadius(24)
        .width('685px')
        .height('84px')
        .backgroundColor($r('sys.color.ohos_id_color_foreground_contrary'))
        .margin({ top: 10, bottom: 10 })
        .padding({ left: 12, right: 12, top: 4, bottom: 4 })
        .onClick(() => {
          Log.info('add button click!');
          this.message = 'result: ' + add(1, 2);
        })

        ListItem() {
          Text(ResManager.getDesc())
            .fontSize(18)
            .textAlign(TextAlign.Start)
            .width('100%')
            .fontWeight(500)
            .height('100%')
        }
        .id('getStringValue')
        .borderRadius(24)
        .width('685px')
        .height('84px')
        .backgroundColor($r('sys.color.ohos_id_color_foreground_contrary'))
        .margin({ top: 10, bottom: 10 })
        .padding({ left: 12, right: 12, top: 4, bottom: 4 })
        .onClick(() => {
          // Obtain the context of the HSP module through application.createModuleContext and the resourceManager object of the HSP module, and call the API of resourceManager to obtain resources.
          application.createModuleContext(this.getUIContext()?.getHostContext(), "library").then((context:Context)=>{
              context.resourceManager.getStringValue(ResManager.getDesc().id)
              .then(value => {
                console.log('getStringValue is ' + value);
                this.message = 'getStringValue is ' + value;
              })
              .catch((err: BusinessError) => {
                console.error('getStringValue promise error is ' + err);
              });
          }).catch((err: BusinessError) => {
            console.error('createModuleContext promise error is ' + err);
          });
        })

        ListItem() {
          Text($r('app.string.native_multi'))
            .fontSize(18)
            .textAlign(TextAlign.Start)
            .width('100%')
            .fontWeight(500)
            .height('100%')
        }
        .id('nativeMulti')
        .borderRadius(24)
        .width('685px')
        .height('84px')
        .backgroundColor($r('sys.color.ohos_id_color_foreground_contrary'))
        .margin({ top: 10, bottom: 10 })
        .padding({ left: 12, right: 12, top: 4, bottom: 4 })
        .onClick(() => {
          Log.info('nativeMulti button click!');
          this.message = 'result: ' + nativeMulti(3, 4);
        })
      }
      .alignListItem(ListItemAlign.Center)
    }
    .width('100%')
    .backgroundColor($r('app.color.page_background'))
    .height('100%')
  }
}
```

### Page Redirection and Return

To add a button in the **entry** module to jump to the menu page (**library/src/main/ets/pages/library_menu.ets**) in the **library** module, write the following code in the **entry/src/main/ets/pages/Index.ets** file of the **entry** module:
```ts
// entry/src/main/ets/pages/Index.ets

@Entry
@Component
struct Index {
  @State message: string = '';
  pathStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pathStack) {
      Column() {
        List() {
          ListItem() {
            Text($r('app.string.click_to_menu'))
              .fontSize(18)
              .textAlign(TextAlign.Start)
              .width('100%')
              .fontWeight(500)
              .height('100%')
          }
          .id('clickToMenu')
          .borderRadius(24)
          .width('685px')
          .height('84px')
          .backgroundColor($r('sys.color.ohos_id_color_foreground_contrary'))
          .margin({ top: 10, bottom: 10 })
          .padding({
            left: 12,
            right: 12,
            top: 4,
            bottom: 4
          })
          .onClick(() => {
            this.pathStack.pushPathByName('library_menu', null)
          })
        }
        .alignListItem(ListItemAlign.Center)
      }
      .width('100%')
      .backgroundColor($r('app.color.page_background'))
      .height('100%')
    }.title("Navigation_index")
    .mode(NavigationMode.Stack)
  }
}
```

Add a page file (**library/src/main/ets/pages/library_menu.ets**) to the **library** module. The **back_to_index** button on the page can be used to return to the previous page.
```
// library/src/main/ets/pages/library_menu.ets
@Builder
export function PageOneBuilder() {
  Library_Menu()
}

@Entry
@Component
export struct Library_Menu {
  @State message: string = 'Hello World';
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Row() {
        Column() {
          Text(this.message)
            .fontSize($r('app.float.page_text_font_size'))
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              this.message = 'Welcome';
            })
          Button("back_to_index").fontSize(50).onClick(() => {
            this.pathStack.pop();
          })
        }
        .width('100%')
      }
      .height('100%')
    }.title('Library_Menu')
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack
    })
  }
}
```

Add the **route_map.json** file (**library/src/main/resources/base/profile/route_map.json**) to the **library** module.
```
{
  "routerMap": [
    {
      "name": "library_menu",
      "pageSourceFile": "src/main/ets/pages/library_menu.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is library_menu"
      }
    }
  ]
}
```

Configure the **route_map.json** file in the **library/src/main/module.json5** file of the **library** module.
```
{
  "module": {
    "name": "library",
    "type": "shared",
    "description": "$string:shared_desc",
    "deviceTypes": [
      "phone",
      "tablet",
      "2in1"
    ],
    "deliveryWithInstall": true,
    "pages": "$profile:main_pages",
    "routerMap": "$profile:route_map" // Added file.
  }
}
```

The navigation feature is used for page redirection and return. For details, see [Page Navigation](../ui/arkts-navigation-navigation.md#routing-operations).
