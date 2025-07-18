# wrapBuilder：封装全局@Builder（ArkTS1.2）

  当在一个struct内使用多个全局@Builder函数实现UI的不同效果时，代码维护将变得非常困难，且页面不够整洁。此时，可以使用wrapBuilder封装全局@Builder。

  在阅读本文档前，建议提前阅读：[\@Builder](./arkts-builder.md)。

> **说明：**
>
> 从API version 20开始使用。

> **说明：**
>
> 在ArkTS1.2中，可以将@Builder函数赋值给一个用@Builder装饰的函数类型的变量，参考[\@Builder: 用变量存储@Builder函数](./arkts-builder.md#用变量存储builder函数（arkts12）)

## 导入模块

```js
import { WrappedBuilder, wrapBuilder } from '@ohos.arkui.component';
```

## 接口说明

wrapBuilder是一个模板函数，返回一个`WrappedBuilder`对象。

```ts
declare function wrapBuilder<T>(builder: T): WrappedBuilder<T>;
```

同时 `WrappedBuilder`对象也是一个模板类。

```ts
declare class WrappedBuilder<T> {
  builder: T;

  constructor(builder: T);
}
```

> **说明：**
>
> 模板参数`T`是需要包装的builder函数的类型声明。

使用方法：

```ts
let builderVar: WrappedBuilder<@Builder (p1: string, p2: number) => void> = wrapBuilder(MyBuilder)
let builderArr: WrappedBuilder<@Builder (p1: string, p2: number) => void>[] = [wrapBuilder(MyBuilder)] //可以放入数组
```

## 限制条件

> **说明：**
>
> ArkTS1.2去除了wrapBuilder方法只能传入全局@Builder方法的限制。

wrapBuilder方法返回的WrappedBuilder对象的builder属性方法只能在struct内部使用。

## @Builder方法赋值给变量

使用`@Builder`装饰器装饰的方法`MyBuilder`作为`wrapBuilder`的参数，再将`wrapBuilder`函数的返回值赋值给变量`globalBuilder`，以解决`@Builder`方法赋值给变量后无法使用的问题。

```ts
import { Builder, Component, Column, Entry, Row, Text, WrappedBuilder, wrapBuilder} from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';

@Builder
function MyBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}

// 使用wrapBuilder封装@Builder函数
let globalBuilder: WrappedBuilder<@Builder (p1: string, p2: number) => void> = wrapBuilder(MyBuilder);

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        //使用WrappedBuilder类builder属性方法构建UI组件
        globalBuilder.builder(this.message, 50)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

##  @Builder方法赋值给变量在UI语法中使用

自定义组件Index使用`ForEach`进行不同`@Builder`函数的渲染，可以使用`builderArr`声明的`wrapBuilder`数组来实现不同的`@Builder`函数效果。整体代码会更加整洁。

```ts
import { Builder, Color, Column, Component, Entry, 
         ForEach, Row, Text, WrappedBuilder, wrapBuilder } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';

@Builder
function MyBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}

@Builder
function YourBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
    .fontColor(Color.Pink)
}

// 使用wrapBuilder封装@Builder函数列表，包含的@Builder函数需要有相同的签名
const builderArr: WrappedBuilder<@Builder (p1: string, p2: number) => void>[] = [wrapBuilder(MyBuilder), wrapBuilder(YourBuilder)];


@Entry
@Component
struct Index {
  @Builder testBuilder() {
    // 使用ForEach展开WrappedBuilder列表
    ForEach(builderArr, (item: WrappedBuilder<@Builder (p1: string, p2: number) => void>) => {
      item.builder('Hello World', 30)
    })
  }

  build() {
    Row() {
      Column() {
        this.testBuilder()
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 引用传递

按引用传递参数时，传递的状态变量的改变会引起@Builder方法内的UI刷新。

```ts
import { Builder, Button, ClickEvent, Column, Component,
         Entry, Text, WrappedBuilder, wrapBuilder } from '@ohos.arkui.component';
import { Observed, State } from '@ohos.arkui.stateManagement';

@Observed
class Tmp {
  paramA2: string = 'hello';
}

@Builder function overBuilder(param: () => Tmp) {
  Column(){
    Text(`wrapBuildervalue:${param().paramA2}`)
  }
}

const wBuilder: WrappedBuilder<@Builder (param: () => Tmp) => void> = wrapBuilder(overBuilder);

@Entry
@Component
struct Parent{
  @State label: Tmp = new Tmp();
  build(){
    Column(){
      // ArkTS1.2中，字面量声明需要以lambda函数传递
      wBuilder.builder(() => { return {paramA2: this.label.paramA2};})
      Button('Click me').onClick((e: ClickEvent) => {
        this.label.paramA2 = 'ArkUI';
      })
    }
  }
}
```
