# HSP

HSP（Harmony Shared Package）是动态共享包，按照使用场景可以分为应用内HSP和应用间HSP。由于当前暂不支持应用间HSP，提到HSP时特指应用内HSP。
应用内HSP指的是专门为某一应用开发的HSP，只能被该应用内部其他HAP/HSP使用，用于应用内部代码、资源的共享。应用内HSP跟随其宿主应用的APP包一起发布，与宿主应用同进程，具有相同的包名和生命周期。

## 开发应用内HSP

通过DevEco Studio创建一个HSP模块，创建方式可[参考](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/hsp-0000001521396322-V3#section7717162312546)，我们以创建一个名为`library`的HSP模块为例。基本的工程目录结构如下：
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

### 导出ts类和方法
通过`export`导出ts类和方法，例如：
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
对外暴露的接口，需要在入口文件`index.ets`中声明：
```ts
// library/src/main/ets/index.ets
export { Log, add, minus } from './utils/test'
```

### 导出ArkUI组件
ArkUI组件也可以通过`export`导出，例如：
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
对外暴露的接口，需要在入口文件`index.ets`中声明：
```ts
// library/src/main/ets/index.ets
export { MyTitleBar } from './components/MyTitleBar'
```

### 通过$r访问HSP中的资源
在组件中，经常需要使用字符串、图片等资源。HSP中的组件需要使用资源时，一般将其所用资源放在HSP包内，而非放在HSP的使用方处，以符合高内聚低耦合的原则。

在工程中，常通过`$r`/`$rawfile`的形式引用应用资源。可以用`$r`/`$rawfile`访问本模块`resources`目录下的资源，如访问`resources`目录下定义的图片`src/main/resources/base/media/example.png`时，可以用`$r("app.media.example")`。有关`$r`/`$rawfile`的详细使用方式，请参阅文档[资源分类与访问](./resource-categories-and-access.md)中“资源访问-应用资源”小节。

不推荐使用相对路径的方式，容易引用错误路径。例如：
当要引用上述同一图片资源时，在HSP模块中使用`Image("../../resources/base/media/example.png")`，实际上该`Image`组件访问的是HSP调用方（如`entry`）下的资源`entry/src/main/resources/base/media/example.png`。

```ts
// library/src/main/ets/pages/Index.ets
// 正确用例
Image($r("app.media.example"))
  .width("100%")
// 错误用例
Image("../../resources/base/media/example.png")
  .width("100%")
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
    return $r("app.media.pic");
  }
  static getDesc(): Resource{
    return $r("app.string.shared_desc");
  }
}
```

对外暴露的接口，需要在入口文件`index.ets`中声明：
```ts
// library/src/main/ets/index.ets
export { ResManager } from './ResManager'
```

### 导出native方法
在HSP中也可以包含C++编写的`so`。对于`so`中的`native`方法，HSP通过间接的方式导出，以导出`libnative.so`的乘法接口`multi`为例：
```ts
// library/src/main/ets/utils/nativeTest.ts
import native from "libnative.so"

export function nativeMulti(a: number, b: number) {
    let result: number = native.multi(a, b);
    return result;
}
```

对外暴露的接口，需要在入口文件`index.ets`中声明：
```ts
// library/src/main/ets/index.ets
export { nativeMulti } from './utils/nativeTest'
```

## 使用应用内HSP
要使用HSP中的接口，首先需要在使用方的oh-package.json5中配置对它的依赖，配置方式可[参考](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/hsp-0000001521396322-V3#section6161154819195)。
依赖配置成功后，就可以像使用HAR一样调用HSP的对外接口了。 例如，上面的library已经导出了下面这些接口：

```ts
// library/src/main/ets/index.ets
export { Log, add, minus } from './utils/test'
export { MyTitleBar } from './components/MyTitleBar'
export { ResManager } from './ResManager'
export { nativeMulti } from './utils/nativeTest'
```
在使用方的代码中，可以这样使用：
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
        // ResManager返回的Resource对象，可以传给组件直接使用，也可以从中取出资源来使用
        Image(ResManager.getPic())
          .width("100%")
        Button('getStringValue')
          .onClick(()=> {
            // 先通过当前上下文获取hsp模块的上下文，再获取hsp模块的resourceManager，然后再调用resourceManager的接口获取资源
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

### 页面路由跳转

若开发者想在entry模块中，添加一个按钮跳转至library模块中的menu页面（路径为：`library/src/main/ets/pages/menu.ets`），那么可以在使用方的代码（entry模块下的Index.ets，路径为：`entry/src/main/ets/MainAbility/Index.ets`）里这样使用：
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
        // 添加按钮，以响应用户点击
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
        // 绑定点击事件
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
其中`router.pushUrl`方法的入参中`url`的内容为：
```ets
'@bundle:com.example.hmservice/library/ets/pages/menu'
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
struct Index3 { // 路径为：`library/src/main/ets/pages/Index3.ets
  @State message: string = 'Hello World'

  build() {
    Row() {
        Column() {
        Button('back to HAP page')
        .width('40%')
        .height('5%')
        // 绑定点击事件
        .onClick(() => {
          router.back({ //  返回HAP的页面
            url: 'pages/Index'    // 路径为：`entry/src/main/ets/pages/Index.ets`
          })
        })
        .width('100%')

        Button('back to HSP page')
        .width('40%')
        .height('5%')
        // 绑定点击事件
        .onClick(() => {
          router.back({ //  返回HSP的页面
            url: '@bundle:com.example.hmservice/library/ets/pages/Index2'  //路径为：`library/src/main/ets/pages/Index2.ets
          })
        })
        .width('100%')
      }
      .height('100%')
    }
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

* 如果从HSP页面返回HSP页面，url的内容为：

    ```ets
    '@bundle:com.example.hmservice/library/ets/pages/Index2'
    ```
    `url`内容的模板为：
    ```ets
    '@bundle:包名（bundleName）/模块名（moduleName）/路径/页面所在的文件名(不加.ets后缀)'
    ```