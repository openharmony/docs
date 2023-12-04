# HSP

A Harmony Shared Package (HSP) is a dynamic shared package. It can be classified as intra-application HSP or inter-application HSP (not supported yet). An intra-application Harmony Shared Package (HSP) is a file used for code and resource sharing within an application (called the host application) and can only be invoked by a HAP or HSP of the same application. The intra-application HSP is released with the Application Package (App Pack) of the host application, shares a process with the host application, and has the same bundle name and lifecycle as the host application.
> **NOTE**
> 
> As the inter-application HSP is not supported yet, unless otherwise specified, the HSP refers to the intra-application HSP.

## Creating an HSP Module
Create an HSP module in DevEco Studio. In this example, an HSP module named **library** is created. The basic project directory structure is as follows:
```
library
├── src
│   └── main
│       ├── ets
│       │   ├── pages
│       │   └── index.ets
│       ├── resources
│       └── module.json5
└── oh-package.json5
```

## Exporting ArkUI Components, APIs, and Resources from HSP

### Exporting ArkUI Components
Use **export** to export ArkUI components. The sample code is as follows:
```ts
// library/src/main/ets/components/MyTitleBar.ets
@Component
export struct MyTitleBar {
  build() {
    Row() {
      Text($r('app.string.library_title'))
        .fontColor($r('app.color.white'))
        .fontSize(25)
        .margin({left:15})
    }
    .width('100%')
    .height(50)
    .padding({left:15})
    .backgroundColor('#0D9FFB')
  }
}
```
In the entry point file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { MyTitleBar } from './components/MyTitleBar'
```


### Exporting TS Classes and Methods
Use **export** to export TS classes and methods. The sample code is as follows:
```ts
// library/src/main/ets/utils/test.ts
export class Log {
    static info(msg: string) {
        console.info(msg);
    }
}

export function add(a: number, b: number) {
  return a + b;
}

export function minus(a: number, b: number) {
  return a - b;
}
```
In the entry point file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { Log, add, minus } from './utils/test'
```
### Exporting Native Methods
The HSP can contain .so files compiled in C++. The HSP indirectly exports the native method in the .so file. In this example, the **multi** API in the **libnative.so** file is exported.
```ts
// library/src/main/ets/utils/nativeTest.ts
import native from "libnative.so"

export function nativeMulti(a: number, b: number) {
    let result: number = native.multi(a, b);
    return result;
}
```

In the entry point file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { nativeMulti } from './utils/nativeTest'
```

### Accessing Resources in an HSP Through $r
More often than not, you may need to use resources, such as strings and images, in components. For components in an HSP, such resources are typically placed in the HSP package, rather than in the package where the HSP is invoked, for the purpose of complying with the principle of high cohesion and low coupling.

In a project, application resources are referenced in the $r/$rawfile format. You can use **$r**/**$rawfile** to access resources in the **resources** directory of the current module. For example, you can use **$r("app.media.example")** to access the **src/main/resources/base/media/example.png** image stored in the **resources** directory. For details about how to use **$r**/**$rawfile**, see [Resource Access: Application Resources](./resource-categories-and-access.md#application-resources).

To avoid reference errors, do not use relative paths. For example,
if you use **Image("../../resources/base/media/example.png")**, the image actually used will be the one in the directory of the module that invokes the HSP. That is, if the module that invokes the HSP is **entry**, then the image used will be **entry/src/main/resources/base/media/example.png**.

```ts
// library/src/main/ets/pages/Index.ets
// Correct
Image($r("app.media.example"))
  .width("100%")
// Incorrect
Image("../../resources/base/media/example.png")
  .width("100%")
```

### Exporting Resources from HSP
When resources in an HSP need to be exported for cross-package access, it is recommended that a resource manager class be implemented to encapsulate the exported resources. In this way:
- You can keep resources well under your control, eliminating the need for exporting resources that do not need to be exposed.
- The invoking module does not need to be aware of the internal resource names of the HSP, or make adaptation to changes in these internal resource names.

The implementation is as follows:

The implementation is as follows:  
```ts
// library/src/main/ets/ResManager.ets
export class ResManager{
  static getPic(): Resource{
    return $r("app.media.pic");
  }
  static getDesc(): Resource{
    return $r("app.string.shared_desc");
  }
}
```

In the entry point file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { ResManager } from './ResManager'
```


## Referencing HSP
To use APIs in the HSP, first configure the dependency on the HSP in the **oh-package.json5** file of the module that needs to call the APIs (called the invoking module).
You can then call the external APIs of the HSP in the same way as calling the APIs in the HAR. In this example, the external APIs are the following ones exported from **library**:

```ts
// library/src/main/ets/index.ets
export { Log, add, minus } from './utils/test'
export { MyTitleBar } from './components/MyTitleBar'
export { ResManager } from './ResManager'
export { nativeMulti } from './utils/nativeTest'
```
The APIs can be used as follows in the code of the invoking module:
```ts
// entry/src/main/ets/pages/index.ets
import { Log, add, MyTitleBar, ResManager, nativeMulti } from "library"
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        MyTitleBar()
        Text(this.message)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
        Button('add(1, 2)')
          .onClick(()=>{
            Log.info("add button click!");
            this.message = "result: " + add(1, 2);
          })
        // Resource object returned by ResManager, which can be passed to a component for direct use or be extracted.
        Image(ResManager.getPic())
          .width("100%")
        Button('getStringValue')
          .onClick(()=> {
            // Obtain the context of the HSP module based on the current context, obtain the resourceManager object of the HSP module, and then call the API of resourceManager to obtain resources.
            getContext().createModuleContext('library').resourceManager.getStringValue(ResManager.getDesc())
              .then(value => {
                console.log("getStringValue is " + value);
              })
              .catch((err: BusinessError) => {
                console.log("getStringValue promise error is " + err);
              });
          })
          .width("50%")
        Button('nativeMulti(3, 4)')
          .onClick(()=>{
            Log.info("nativeMulti button click!");
            this.message = "result: " + nativeMulti(3, 4);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Redirecting to a Page

If you want to add a button in the **entry** module to jump to the menu page (**library/src/main/ets/pages/menu.ets**) in the **library** module, you can write the following code in the **entry/src/main/ets/MainAbility/Index.ets** file of the **entry** module:
```ts
import router from '@ohos.router';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Index {
    @State message: string = 'Hello World'

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
            }).catch((err: BusinessError) => {
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
```ets
'@bundle:com.example.hmservice/library/ets/pages/menu'
```
The **url** content template is as follows:
```ets
'@bundle:bundle name/module name/path/page file name (without the extension .ets)'
```
