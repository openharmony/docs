# In-Application HSP Development

An in-application Harmony Shared Package (HSP) is a file used for code and resource sharing within an application (called the host application) and can only be invoked by a HAP or HSP of the same application.
The in-application HSP is released with the Application Package (App Pack) of the host application, shares a process with the host application, and has the same bundle name and lifecycle as the host application.

## Developing an In-Application HSP

[Create an HSP module in DevEco Studio](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/hsp-0000001521396322-V3#section7717162312546). In this example, an HSP module named **library** is created. The basic project directory structure is as follows:
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
In the **module.json5** file, set **type** to **shared** for the HSP.
```json
{
    "type": "shared"
}
```

The HSP provides capabilities for external systems by exporting APIs in the entry file. Specify the entry file in **main** in the **oh-package.json5** file. For example:
```json
{
    "main": "./src/main/ets/index.ets"
}
```

### Exporting TS Classes and Methods
Use **export** to export TS classes and methods. The sample code is as follows:
```ts
// library/src/main/ets/utils/test.ts
export class Log {
    static info(msg) {
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
In the entry file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { Log, add, minus } from './utils/test'
```

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
In the entry file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { MyTitleBar } from './components/MyTitleBar'
```
#### About Using Resources in the HSP
To reference resources in the **resources** directory of the current HSP module, use **$r** or **$rawfile**.
If a relative path is used, the resources in the HSP caller are referenced instead. For example,
if **Image("common/example.png")** is used in the HSP module, the **\<Image>** component will reference the resource **entry/src/main/ets/common/example.png** in the HSP caller (which is **entry** in this example).

### Exporting Native Methods
The HSP can contain .so files compiled in C++. The HSP indirectly exports the native method in the .so file. In this example, the **multi** method in the **libnative.so** file is exported.
```ts
// library/src/main/ets/utils/nativeTest.ts
import native from "libnative.so"

export function nativeMulti(a: number, b: number) {
    return native.multi(a, b);
}
```

In the entry file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { nativeMulti } from './utils/nativeTest'
```

## Using the In-Application HSP
To use APIs in the HSP, first [configure the dependency](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/hsp-0000001521396322-V3#section6161154819195) on the HSP in the **oh-package.json5** file of the module that needs to call the APIs (called the invoking module).
You can then call the external APIs of the HSP in the same way as calling the APIs in the HAR. In this example, the external APIs are the following ones exported from **library**:

```ts
// library/src/main/ets/index.ets
export { Log, add, minus } from './utils/test'
export { MyTitleBar } from './components/MyTitleBar'
export { nativeMulti } from './utils/nativeTest'
```
The APIs can be used as follows in the code of the invoking module:
```ts
// entry/src/main/ets/pages/index.ets
import { Log, add, MyTitleBar, nativeMulti } from "library"

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
```ets
'@bundle:com.example.hmservice/library/ets/pages/menu'
```
The **url** content template is as follows:
```ets
'@bundle:bundle name/module name/path/page file name (without the extension .ets)'
```
