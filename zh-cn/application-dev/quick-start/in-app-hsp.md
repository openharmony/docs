# 应用内HSP开发指导

应用内`HSP`指的是专门为某一应用开发的`HSP`，只能被该应用内部其他`HAP`/`HSP`使用，用于应用内部代码、资源的共享。
应用内`HSP`跟随其宿主应用的APP包一起发布，与宿主应用同进程，具有相同的包名和生命周期。

## 开发应用内HSP

通过DevEco Studio创建一个HSP模块，创建方式可[参考](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/hsp-0000001521396322-V3#section7717162312546)，我们以创建一个名为`library`的`HSP`模块为例。基本的工程目录结构大致如下：
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
模块`module.json5`中的`"type"`标识模块类型，`HSP`的`"type"`是`"shared"`。
```json
{
    "type": "shared"
}
```

`HSP`通过在入口文件中导出接口，对外提供能力。入口文件在模块`oh-package.json5`的`"main"`中配置。例如：
```json
{
    "main": "./src/main/ets/index.ets"
}
```

### 导出ts类和方法
通过`export`导出ts类和方法，例如：
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
#### HSP中资源使用说明
注意，在`HSP`中，通过`$r`/`$rawfile`可以使用本模块`resources`目录下的资源。
如果使用相对路径的方式，例如：
在`HSP`模块中使用`Image("common/example.png")`，实际上该`Image`组件访问的是`HSP调用方`（如`entry`）下的资源`entry/src/main/ets/common/example.png`。

### 导出native方法
在`HSP`中也可以包含`C++`编写的`so`。对于`so`中的`native`方法，`HSP`通过间接的方式导出，以导出`libnative.so`的乘法接口`multi`为例：
```ts
// library/src/main/ets/utils/nativeTest.ts
import native from "libnative.so"

export function nativeMulti(a: number, b: number) {
    return native.multi(a, b);
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
export { nativeMulti } from './utils/nativeTest'
```
在使用方的代码中，可以这样使用：
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

### 页面路由跳转

若开发者想在entry模块中，添加一个按钮跳转至library模块中的menu页面（路径为：`library/src/main/ets/pages/menu.ets`），那么可以在使用方的代码（entry模块下的Index.ets，路径为：`entry/src/main/ets/MainAbility/Index.ets`）里这样使用：
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
其中`router.pushUrl`方法的入参中`url`的内容为：
```ets
'@bundle:com.example.hmservice/library/ets/pages/menu'
```
`url`内容的模板为：
```ets
'@bundle:包名（bundleName）/模块名（moduleName）/路径/页面所在的文件名(不加.ets后缀)'
```