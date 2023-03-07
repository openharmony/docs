# 应用内HSP开发指导

应用内`HSP`指的是专门为某一应用开发的`HSP`，只能被该应用内部其他`HAP`/`HSP`使用，用于应用内部代码、资源的共享。
应用内`HSP`跟随其宿主应用的APP包一起发布，与该宿主应用具有相同的包名和生命周期。

## 开发应用内HSP

`HSP`模块可以在`DevEco Studio`中由指定模板创建，我们以创建一个名为`library`的`HSP`模块为例。基本的工程目录结构大致如下：
```
library
├── src
│   └── main
│       ├── ets
│       │   ├── pages
│       │   └── index.ets
│       ├── resources
│       └── module.json5
└── package.json
```
模块`module.json5`中的`"type"`标识模块类型，`HSP`的`"type"`是`"shared"`。
```json
{
    "type": "shared"
}
```

`HSP`通过在入口文件中导出接口，对外提供能力。入口文件在模块`package.json`的`"main"`中配置。例如：
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
// ibrary/src/main/ets/utils/nativeTest.ts
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
要使用`HSP`中的接口，首先需要在使用方的`package.json`中配置对它的依赖。如果应用内`HSP`和使用方在同一工程下，可以直接本地引用，例如：
```json
// entry/src/main/module.json5
"dependencies": {
    "library": "file:../library"
}
```
然后就可以像使用`HAR`包一样调用`HSP`的对外接口了。
例如，上面的`library`已经导出了下面这些接口：
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