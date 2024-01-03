# wrapBuilder：封装全局@Builder


 全局\@Builder作为wrapBuilder的参数返回WrappedBuilder对象，实现[全局\@Builder](arkts-builder.md#全局自定义构建函数)可以进行赋值和传递。 


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
  builder: (...args: Args): void;

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

自定义组件Index使用了全局globalBuilder声明的wrapBuilder，当点击Text()组件时，globalBuilder重新赋值新的wrapBuilder，可以实现不同效果的切换。

```ts
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

let globalBuilder: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        globalBuilder.builder(this.message, 50)
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() =>{
            this.message = 'Test wrapBuilder';
            globalBuilder = wrapBuilder(YourBuilder);
          })

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



## 错误场景

```
function MyBuilder() {

}

// wrapBuilder必须传入被@Builder修饰的全局函数。
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

