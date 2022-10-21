# 使用限制与扩展

## 在生成器函数中的使用限制

ArkTS语言的使用在生成器函数中存在一定的限制：

- 表达式仅允许在字符串(${expression})、if/else条件语句、ForEach的参数以及组件的参数中使用。

- 任何表达式都不能导致应用程序中状态变量（@State、@Link、@Prop）的改变，否则会造成未定义和潜在不稳定的框架行为。

- 生成器函数内部不能有局部变量。

上述限制都不适用于事件方法（如onClick）的匿名函数实现。

## 变量的双向绑定

ArkTS支持通过$$双向绑定变量，通常应用于状态值频繁改变的变量。

- 当前$$支持基础类型变量，以及@State、@Link和@Prop装饰的变量。
- 当前$$仅支持[bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md)属性方法的show参数，[Radio](../reference/arkui-ts/ts-basic-components-radio.md)组件的checked属性，[Refresh](../reference/arkui-ts/ts-container-refresh.md)组件的refreshing参数。
- $$绑定的变量变化时，仅渲染刷新当前组件，提高渲染速度。

```ts
// xxx.ets
@Entry
@Component
struct bindPopupPage {
  @State customPopup: boolean = false

  build() {
    Column() {
      Button('Popup')
        .margin(20)
        .onClick(() => {
          this.customPopup = !this.customPopup
        })
        .bindPopup($$this.customPopup, {
          message: "showPopup"
        })
    }
  }
}
```

![popup](figures/popup.gif)

## 状态变量数据类型声明使用限制

@State、@Provide、 @Link和@Consume四种状态变量的数据类型声明只能由简单数据类型或引用数据类型的其中一种构成。

示例：

```ts
// xxx.ets
@Entry
@Component
struct IndexPage {
  //错误写法: @State message: string | Resource = 'Hello World'
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(`${this.message}`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![hello](figures/hello.PNG)