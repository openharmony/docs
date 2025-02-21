# HSP

HSP（Harmony Shared Package）是动态共享包，可以包含代码、C++库、资源和配置文件，通过HSP可以实现代码和资源的共享。HSP不支持独立发布，而是跟随其宿主应用的APP包一起发布，与宿主应用同进程，具有相同的包名和生命周期。
> **说明：**
> 
> 应用内HSP：在编译过程中与应用包名（bundleName）强耦合，只能给某个特定的应用使用。
> 
> [集成态HSP](integrated-hsp.md)：构建、发布过程中，不与特定的应用包名耦合；使用时，工具链支持自动将集成态HSP的包名替换成宿主应用包名。

## 使用场景
- 多个HAP/HSP共用的代码和资源放在同一个HSP中，可以提高代码、资源的可重用性和可维护性，同时编译打包时也只保留一份HSP代码和资源，能够有效控制应用包大小。

- HSP在运行时按需加载，有助于提升应用性能。

- 同一个组织内部的多个应用之间，可以使用集成态HSP实现代码和资源的共享。

## 约束限制

- HSP不支持在设备上单独安装/运行，需要与依赖该HSP的HAP一起安装/运行。HAP的版本号须大于等于HSP版本号。
- HSP支持在配置文件中声明[ExtensionAbility](../application-models/extensionability-overview.md)组件和[UIAbility](../application-models/uiability-overview.md)组件，但不支持具有入口能力的ExtensionAbility或UIAbility（即skill标签配置了entity.system.home和ohos.want.action.home）。
- HSP可以依赖其他HAR或HSP，但不支持循环依赖，也不支持依赖传递。

> **说明：**
> 
> 循环依赖：例如有三个HSP，HSP-A、HSP-B和HSP-C，循环依赖指HSP-A依赖HSP-B，HSP-B依赖HSP-C，HSP-C又依赖HSP-A。
>
> 依赖传递：例如有三个HSP，HSP-A、HSP-B和HSP-C，依赖关系是HSP-A依赖HSP-B，HSP-B依赖HSP-C。不支持传递依赖指HSP-A可以使用HSP-B的方法和组件，但是HSP-A不能直接使用HSP-C的方法和组件。


## 创建
通过DevEco Studio创建一个HSP模块，详见[创建HSP模块](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-hsp-V13#section7717162312546)，我们以创建一个名为`library`的HSP模块为例。基本的工程目录结构如下：
```
MyApplication
├── library
│   ├── src
│   │   └── main
│   │       ├── ets
│   │       │   └── pages
│   │       │       └── index.ets
│   │       ├── resources
│   │       └── module.json5
│   ├── oh-package.json5
│   ├── index.ets
│   └── build-profile.json5 //模块级
└── build-profile.json5     //工程级
```

## 开发


介绍如何导出HSP的ArkUI组件、接口、资源，供应用内的其他HAP/HSP引用。

### 导出ArkUI组件
ArkUI组件可以通过`export`导出，例如：
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
对外暴露的接口，需要在入口文件`index.ets`中声明：
```ts
// library/index.ets
export { MyTitleBar } from './src/main/ets/components/MyTitleBar';
```


### 导出ts类和方法
通过`export`导出ts类和方法，例如：
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
对外暴露的接口，需要在入口文件`index.ets`中声明：
```ts
// library/index.ets
export { Log, add, minus } from './src/main/ets/utils/test';
```
### 导出native方法
在HSP中也可以包含C++编写的`so`。对于`so`中的`native`方法，HSP通过间接的方式导出，以导出`liblibrary.so`的乘法接口`multi`为例：
```ts
// library/src/main/ets/utils/nativeTest.ets
import native from 'liblibrary.so';

export function nativeMulti(a: number, b: number): number {
  let result: number = native.multi(a, b);
  return result;
}
```

对外暴露的接口，需要在入口文件`index.ets`中声明：
```ts
// library/index.ets
export { nativeMulti } from './src/main/ets/utils/nativeTest';
```

### 通过$r访问HSP中的资源
在组件中，经常需要使用字符串、图片等资源。HSP中的组件需要使用资源时，一般将其所用资源放在HSP包内，而非放在HSP的使用方处，以符合高内聚低耦合的原则。

在工程中，常通过`$r`/`$rawfile`的形式引用应用资源。可以用`$r`/`$rawfile`访问本模块`resources`目录下的资源，如访问`resources`目录下定义的图片`src/main/resources/base/media/example.png`时，可以用`$r("app.media.example")`。有关`$r`/`$rawfile`的详细使用方式，请参阅文档[资源分类与访问](./resource-categories-and-access.md)中“资源访问-应用资源”小节。

不推荐使用相对路径的方式，容易引用错误路径。例如：
当要引用上述同一图片资源时，在HSP模块中使用`Image("../../resources/base/media/example.png")`，实际上该`Image`组件访问的是HSP调用方（如`entry`）下的资源`entry/src/main/resources/base/media/example.png`。

```ts
// library/src/main/ets/pages/Index.ets
// 正确用例
Image($r('app.media.example'))
  .id('example')
  .borderRadius('48px')
// 错误用例
Image("../../resources/base/media/example.png")
  .id('example')
  .borderRadius('48px')
```

### 导出HSP中的资源
跨包访问HSP内资源时，推荐实现一个资源管理类，以封装对外导出的资源。采用这种方式，具有如下优点：
- HSP开发者可以控制自己需要导出的资源，不需要对外暴露的资源可以不用导出。
- 使用方无须感知HSP内部的资源名称。当HSP内部的资源名称发生变化时，也不需要使用方跟着修改。

其具体实现如下：

将需要对外提供的资源封装为一个资源管理类：   
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

对外暴露的接口，需要在入口文件`index.ets`中声明：
```ts
// library/index.ets
export { ResManager } from './src/main/ets/ResManager';
```



## 使用

介绍如何引用HSP中的接口，以及如何通过页面路由实现HSP的pages页面跳转与返回。

### 引用HSP中的接口
要使用HSP中的接口，首先需要在使用方的oh-package.json5中配置对它的依赖，详见[引用动态共享包](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-har-import-V13)。
依赖配置成功后，就可以像使用HAR一样调用HSP的对外接口了。例如，上面的library已经导出了下面这些接口：

```ts
// library/index.ets
export { Log, add, minus } from './src/main/ets/utils/test';
export { MyTitleBar } from './src/main/ets/components/MyTitleBar';
export { ResManager } from './src/main/ets/ResManager';
export { nativeMulti } from './src/main/ets/utils/nativeTest';
```
在使用方的代码中，可以这样使用：
```ts
// entry/src/main/ets/pages/index.ets
import { Log, add, MyTitleBar, ResManager, nativeMulti } from 'library';
import { BusinessError } from '@ohos.base';
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
          // ResManager返回的Resource对象，可以传给组件直接使用，也可以从中取出资源来使用
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
          // 先通过当前上下文获取hsp模块的上下文，再获取hsp模块的resourceManager，然后再调用resourceManager的接口获取资源
          getContext()
            .createModuleContext('library')
            .resourceManager
            .getStringValue(ResManager.getDesc())
            .then(value => {
              console.log('getStringValue is ' + value);
              this.message = 'getStringValue is ' + value;
            })
            .catch((err: BusinessError) => {
              console.error('getStringValue promise error is ' + err);
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

### 页面路由跳转

若开发者想在entry模块中，添加一个按钮跳转至library模块中的menu页面（路径为：`library/src/main/ets/pages/menu.ets`），那么可以在使用方的代码（entry模块下的Index.ets，路径为：`entry/src/main/ets/pages/Index.ets`）里这样使用：
```ts
import { Log, add, MyTitleBar, ResManager, nativeMulti } from 'library';
import { BusinessError } from '@ohos.base';
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
          }).catch((err: BusinessError) => {
            console.error('pushUrl failed, code is' + err.code + ', message is' + err.message);
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
其中`router.pushUrl`方法的入参中`url`的内容为：
```ets
'@bundle:com.samples.hspsample/library/ets/pages/Menu'
```
`url`内容的模板为：
```ets
'@bundle:包名（bundleName）/模块名（moduleName）/路径/页面所在的文件名(不加.ets后缀)'
```
### 页面路由返回
如果当前处于HSP中的页面，需要返回之前的页面时，可以使用`router.back`方法，但是返回的页面必须是当前页面跳转路径上的页面。
```ts
import router from '@ohos.router';

@Entry
@Component
struct Index3 { // 路径为：`library/src/main/ets/pages/Back.ets
  @State message: string = 'HSP back page';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontFamily('HarmonyHeiTi')
          .fontWeight(FontWeight.Bold)
          .fontSize(32)
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
            // 绑定点击事件
          .onClick(() => {
            router.back({ //  返回HAP的页面
              url: 'pages/Index' // 路径为：`entry/src/main/ets/pages/Index.ets`
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
            // 绑定点击事件
          .onClick(() => {
            router.back({ //  返回HSP的页面
              url: '@bundle:com.samples.hspsample/library/ets/pages/Menu' //路径为：`library/src/main/ets/pages/Menu.ets
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

页面返回`router.back`方法的入参中`url`说明：

* 如果从HSP页面返回HAP页面，url的内容为：

    ```ets
    'pages/Index'
    ```
    `url`内容的模板为：
    ```ets
    '页面所在的文件名(不加.ets后缀)'
    ```

* 如果从HSP1的页面跳到HSP2的页面后，需要返回到HSP1的页面，url的内容为：

    ```ets
    '@bundle:com.samples.hspsample/library/ets/pages/Menu'
    ```
    `url`内容的模板为：
    ```ets
    '@bundle:包名（bundleName）/模块名（moduleName）/路径/页面所在的文件名(不加.ets后缀)'
    ```

