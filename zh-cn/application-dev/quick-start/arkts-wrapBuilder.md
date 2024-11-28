# wrapBuilder：封装全局@Builder

  当开发者在一个struct内使用了多个全局@Builder函数，来实现UI的不同效果时，多个全局@Builder函数会使代码维护起来非常困难，并且页面不整洁。此时，开发者可以使用wrapBuilder来封装全局@Builder。 


> **说明：**
>
> 从API version 11开始使用。

当@Builder方法赋值给变量或者数组后，赋值的变量或者数组在UI方法中无法使用。

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

在上述代码中，builderArr是一个@Builder方法组成的数组， 在ForEach中取每一项@Builder方法时会出现@Builder方法在UI方法中无法使用的错误。

 为了解决这一问题，引入wrapBuilder作为全局@Builder封装函数。wrapBuilder的参数返回WrappedBuilder对象，实现[全局\@Builder](arkts-builder.md#全局自定义构建函数)可以进行赋值和传递。 

## 接口说明

wrapBuilder是一个模板函数，返回一个`WrappedBuilder`对象。

```ts
declare function wrapBuilder< Args extends Object[]>(builder: (...args: Args) => void): WrappedBuilder;
```
同时 `WrappedBuilder`对象也是一个模板类。

```ts
declare class WrappedBuilder< Args extends Object[]> {
  builder: (...args: Args) => void;

  constructor(builder: (...args: Args) => void);
}
```


>说明：模板参数`Args extends Object[]`是需要包装的builder函数的参数列表

使用方法：

```ts
let builderVar: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder)
let builderArr: WrappedBuilder<[string, number]>[] = [wrapBuilder(MyBuilder)] //可以放入数组
```



## 限制条件

wrapBuilder方法只能传入[全局\@Builder](arkts-builder.md#全局自定义构建函数)方法。

wrapBuilder方法返回的WrappedBuilder对象的builder属性方法只能在struct内部使用。



## @Builder方法赋值给变量

把@Builder装饰器装饰的方法MyBuilder作为wrapBuilder的参数，再将wrapBuilder赋值给变量globalBuilder，用来解决@Builder方法赋值给变量后无法被使用的问题。 

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

自定义组件Index使用ForEach来进行不同\@Builder函数的渲染，可以使用builderArr声明的wrapBuilder数组进行不同\@Builder函数效果体现。整体代码会较整洁。

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
  @Builder testBuilder() {
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

通过按引用传递的方式传入参数，会触发UI的刷新。

```ts
class Tmp {
  paramA2: string = 'hello';
}

@Builder function overBuilder(param: Tmp) {
  Column(){
    Text(`wrapBuildervalue:${param.paramA2}`)
  }
}

const wBuilder: WrappedBuilder<[Tmp]> = wrapBuilder(overBuilder);

@Entry
@Component
struct Parent{
  @State label: Tmp = new Tmp();
  build(){
    Column(){
      wBuilder.builder({paramA2: this.label.paramA2})
      Button('Click me').onClick(() => {
        this.label.paramA2 = 'ArkUI';
      })
    }
  }
}
```

## 错误场景

### 重复定义wrapBuilder失效

通过wrapBuilder(MyBuilderFirst)初始化定义builderObj之后，再次对builderObj进行赋值wrapBuilder(MyBuilderSecond)会不起作用，只生效第一次定义的wrapBuilder(MyBuilderFirst)。

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
      this.builderObj.globalBuilder = wrapBuilder(MyBuilderSecond);
    },1000)
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