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
        .id('library')
        .fontFamily('HarmonyHeiTi')
        .fontWeight(FontWeight.Bold)
        .fontSize(32)
        .fontWeight(700)
        .fontColor($r('app.color.text_color'))
    }
    .width('100%')
  }
}
```
In the entry point file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { MyTitleBar } from './components/MyTitleBar';
```


### Exporting TS Classes and Methods
Use **export** to export TS classes and methods. The sample code is as follows:
```ts
// library/src/main/ets/utils/test.ts
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
In the entry point file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { Log, add, minus } from './utils/test';
```
### Exporting Native Methods
The HSP can contain .so files compiled in C++. The HSP indirectly exports the native method in the .so file. In this example, the **multi** API in the **libnative.so** file is exported.
```ts
// library/src/main/ets/utils/nativeTest.ts
import native from 'liblibrary.so';

export function nativeMulti(a: number, b: number): number {
  let result: number = native.multi(a, b);
  return result;
}
```

In the entry point file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { nativeMulti } from './utils/nativeTest';
```

### Accessing Resources in an HSP Through $r
More often than not, you may need to use resources, such as strings and images, in components. For components in an HSP, such resources are typically placed in the HSP package, rather than in the package where the HSP is invoked, for the purpose of complying with the principle of high cohesion and low coupling.

In a project, application resources are referenced in the $r/$rawfile format. You can use **$r**/**$rawfile** to access resources in the **resources** directory of the current module. For example, you can use **$r("app.media.example")** to access the **src/main/resources/base/media/example.png** image stored in the **resources** directory. For details about how to use **$r**/**$rawfile**, see [Resource Access: Application Resources](./resource-categories-and-access.md#application-resources).

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

The implementation is as follows:  
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

In the entry point file **index.ets**, declare the APIs to be exposed.
```ts
// library/src/main/ets/index.ets
export { ResManager } from './ResManager';
```


## Referencing HSP
To use APIs in the HSP, first configure the dependency on the HSP in the **oh-package.json5** file of the module that needs to call the APIs (called the invoking module).
You can then call the external APIs of the HSP in the same way as calling the APIs in the HAR. In this example, the external APIs are the following ones exported from **library**:

```ts
// library/src/main/ets/index.ets
export { Log, add, minus } from './utils/test';
export { MyTitleBar } from './components/MyTitleBar';
export { ResManager } from './ResManager';
export { nativeMulti } from './utils/nativeTest';
```
The APIs can be used as follows in the code of the invoking module:
```ts
// entry/src/main/ets/pages/index.ets
import { Log, add, MyTitleBar, ResManager, nativeMulti } from 'library';
import { BusinessError } from '@ohos.base';
import Logger from '../logger/Logger';
import router from '@ohos.router';

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
          Text($r('app.string.get_string_value'))
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
          // Obtain the context of the HSP module based on the current context, obtain the resourceManager object of the HSP module, and then call the API of resourceManager to obtain resources.
          getContext()
            .createModuleContext('library')
            .resourceManager
            .getStringValue(ResManager.getDesc())
            .then(value => {
              Logger.info(TAG, `getStringValue is ${value}`);
              this.message = 'getStringValue is ' + value;
            })
            .catch((err: BusinessError) => {
              Logger.info(TAG, `getStringValue promise error is ${err}`);
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

### Redirecting to a Page

If you want to add a button in the **entry** module to jump to the menu page (**library/src/main/ets/pages/menu.ets**) in the **library** module, you can write the following code in the **entry/src/main/ets/MainAbility/Index.ets** file of the **entry** module:
```ts
import { Log, add, MyTitleBar, ResManager, nativeMulti } from 'library';
import { BusinessError } from '@ohos.base';
import Logger from '../logger/Logger';
import router from '@ohos.router';

const TAG = 'Index';

@Entry
@Component
struct Index {
  @State message: string = '';

  build() {
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
        .padding({ left: 12, right: 12, top: 4, bottom: 4 })
        .onClick(() => {
          router.pushUrl({
            url: '@bundle:com.samples.hspsample/library/ets/pages/Menu'
          }).then(() => {
            console.log('push page success');
            Logger.info(TAG, 'push page success');
          }).catch((err: BusinessError) => {
            Logger.error(TAG, `pushUrl failed, code is ${err.code}, message is ${err.message}`);
          })
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
The input parameter **url** of the **router.pushUrl** API is as follows:
```ets
'@bundle:com.samples.hspsample/library/ets/pages/Menu'
```
The **url** content template is as follows:
```ets
'@bundle:bundleName/moduleName/path/page file name (without the extension .ets)'
```
### Going Back to Previous Page with Router
You can use the **router.back** method to go back, from a page in the HSP, to the previous page, under the prerequisite that the target page is in the redirection path of the source page.
```ts
import router from '@ohos.router';

@Entry
@Component
struct Index3 {// The path is `library/src/main/ets/pages/Back.ets.
  @State message: string = 'HSP back page';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontFamily('HarmonyHeiTi')
          .fontWeight(FontWeight.Bold)
          .fontSize(32)
          .fontWeight(700)
          .fontColor($r('app.color.text_color'))
          .margin({ top: '32px' })
          .width('624px')

        Button($r('app.string.back_to_HAP'))
          .id('backToHAP')
          .fontFamily('HarmonyHeiTi')
          .height(48)
          .width('624px')
          .margin({ top: 550 })
          .type(ButtonType.Capsule)
          .borderRadius($r('sys.float.ohos_id_corner_radius_button'))
          .backgroundColor($r('app.color.button_background'))
          .fontColor($r('sys.color.ohos_id_color_foreground_contrary'))
          .fontSize($r('sys.float.ohos_id_text_size_button1'))
            // Bind click events.
          .onClick(() => {
            router.back({ // Go back to the HAP page.
              url: 'pages/Index' // The path is `entry/src/main/ets/pages/Index.ets`.
            })
          })

        Button($r('app.string.back_to_HSP'))
          .id('backToHSP')
          .fontFamily('HarmonyHeiTi')
          .height(48)
          .width('624px')
          .margin({ top: '4%' , bottom: '6%' })
          .type(ButtonType.Capsule)
          .borderRadius($r('sys.float.ohos_id_corner_radius_button'))
          .backgroundColor($r('app.color.button_background'))
          .fontColor($r('sys.color.ohos_id_color_foreground_contrary'))
          .fontSize($r('sys.float.ohos_id_text_size_button1'))
            // Bind click events.
          .onClick(() => {
            router.back({ // Go back to the HSP page.
              url: '@bundle:com.samples.hspsample/library/ets/pages/Menu' // The path is `library/src/main/ets/pages/Menu.ets.
            })
          })
      }
      .width('100%')
    }
    .backgroundColor($r('app.color.page_background'))
    .height('100%')
  }
}
```

The **url** parameter in the **router.back** method is described as follows:

* In this example, the URL for going back from the HSP page to the HAP page is as follows:

    ```ets
    'pages/Index'
    ```
    The **url** content template is as follows:
    ```ets
    'Page file name (without the extension .ets)
    ```

* In this example, the URL for going back from the HSP page to the HSP page is as follows:

    ```ets
    '@bundle:com.samples.hspsample/library/ets/pages/Menu'
    ```
    The **url** content template is as follows:
    ```ets
    '@bundle:bundleName/moduleName/path/page file name (without the extension .ets)'
    ```
