# wrapBuilder：封装全局@Builder

  当在一个struct内使用多个全局@Builder函数实现UI的不同效果时，代码维护将变得非常困难，且页面不够整洁。此时，可以使用wrapBuilder封装全局@Builder。

  在阅读本文档前，建议提前阅读：[\@Builder](./arkts-builder.md)。

> **说明：**
>
> 从API version 11开始使用。

当@Builder方法赋值给变量或者数组后，在UI方法中无法使用。

```ts
@Builder
function builderElement() {}

let builderArr: Function[] = [builderElement];
@Builder
function testBuilder() {
  ForEach(builderArr, (item: Function) => {
    item();
  })
}
```

在上述代码中，`builderArr`是一个由`@Builder`方法组成的数组。在`ForEach`循环中取每个`@Builder`方法时，会出现`@Builder`方法在UI方法中无法使用的问题。

为了解决这一问题，引入`wrapBuilder`作为全局`@Builder`封装函数。`wrapBuilder`返回`WrappedBuilder`对象，实现[全局\@Builder](arkts-builder.md#全局自定义构建函数)可以进行赋值和传递。 

## 接口说明

wrapBuilder是一个模板函数，返回一个`WrappedBuilder`对象。

```ts
declare function wrapBuilder<Args extends Object[]>(builder: (...args: Args) => void): WrappedBuilder<Args>;
```
同时 `WrappedBuilder`对象也是一个模板类。

```ts
declare class WrappedBuilder<Args extends Object[]> {
  builder: (...args: Args) => void;

  constructor(builder: (...args: Args) => void);
}
```


>说明：模板参数`Args extends Object[]`是需要包装的builder函数的参数列表

使用方法：

```ts
let builderVar: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);
let builderArr: WrappedBuilder<[string, number]>[] = [wrapBuilder(MyBuilder)]; //可以放入数组
```



## 限制条件

1. wrapBuilder方法只能传入[全局\@Builder](arkts-builder.md#全局自定义构建函数)方法。

2. wrapBuilder方法返回的WrappedBuilder对象的builder属性方法只能在struct内部使用。

## @Builder方法赋值给变量

使用`@Builder`装饰器装饰的方法`MyBuilder`作为`wrapBuilder`的参数，再将`wrapBuilder`函数的返回值赋值给变量`globalBuilder`，以解决`@Builder`方法赋值给变量后无法使用的问题。

```ts
@Builder
function MyBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}

let globalBuilder: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
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

```
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

const builderArr: WrappedBuilder<[string, number]>[] = [wrapBuilder(MyBuilder), wrapBuilder(YourBuilder)];


@Entry
@Component
struct Index {
  @Builder
  testBuilder() {
    ForEach(builderArr, (item: WrappedBuilder<[string, number]>) => {
      item.builder('Hello World', 30)
    }

    )
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
class Tmp {
  paramA2: string = 'hello';
}

@Builder
function overBuilder(param: Tmp) {
  Column() {
    Text(`wrapBuildervalue:${param.paramA2}`)
  }
}

const wBuilder: WrappedBuilder<[Tmp]> = wrapBuilder(overBuilder);

@Entry
@Component
struct Parent {
  @State label: Tmp = new Tmp();

  build() {
    Column() {
      wBuilder.builder({ paramA2: this.label.paramA2 })
      Button('Click me').onClick(() => {
        this.label.paramA2 = 'ArkUI';
      })
    }
  }
}
```

## 常见问题

### 重复定义wrapBuilder失效

在同一个自定义组件内，同一个`wrapBuilder`只能初始化一次。示例中，`builderObj`通过`wrapBuilder(MyBuilderFirst)`初始化定义后，再次对`builderObj`赋值`wrapBuilder(MyBuilderSecond)`不会生效。

```ts
@Builder
function MyBuilderFirst(value: string, size: number) {
  Text('MyBuilderFirst：' + value)
    .fontSize(size)
}

@Builder
function MyBuilderSecond(value: string, size: number) {
  Text('MyBuilderSecond：' + value)
    .fontSize(size)
}

interface BuilderModel {
  globalBuilder: WrappedBuilder<[string, number]>;
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  @State builderObj: BuilderModel = { globalBuilder: wrapBuilder(MyBuilderFirst) };

  aboutToAppear(): void {
    setTimeout(() => {
      // wrapBuilder(MyBuilderSecond) 不会生效
      this.builderObj.globalBuilder = wrapBuilder(MyBuilderSecond);
    }, 1000);
  }

  build() {
    Row() {
      Column() {
        this.builderObj.globalBuilder.builder(this.message, 20)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```