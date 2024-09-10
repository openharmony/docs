# wrapBuilder：封装全局@Builder


 当开发者在一个struct内使用了多个全局@Builder函数，来实现UI的不同效果，但多个全局@Builder函数使用位置会使的代码维护起来困难，页面不整洁。为了解决这些这一问题，引入wrapBuilder作为全局@Builder封装函数。wrapBuilder的参数返回WrappedBuilder对象，实现[全局\@Builder](arkts-builder.md#全局自定义构建函数)可以进行赋值和传递。 


> **说明：**
>
> 从API version 11开始使用。

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



## 使用场景1

将wrapBuilder赋值给globalBuilder，且把MyBuilder作为wrapBuilder参数，用来替代MyBuilder不能直接赋值给globalBuilder。

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

## 使用场景2

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

## 使用场景3

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

### wrapBuilder必须传入被@Builder修饰的全局函数。

```ts
function MyBuilder() {

}

const globalBuilder: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        globalBuilder.builder(this.message, 30)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

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