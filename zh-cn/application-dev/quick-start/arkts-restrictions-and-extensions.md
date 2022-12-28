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

## 自定义组件成员变量初始化的方式与约束

组件的成员变量可以通过两种方式初始化：

- 本地初始化：

  ```ts
  @State counter: Counter = new Counter()
  ```
- 在构造组件时通过构造参数初始化：

  ```ts
  MyComponent({counter: $myCounter})
  ```

具体允许哪种方式取决于状态变量的装饰器：

| 装饰器类型        | 本地初始化 | 通过构造函数参数初始化 |
| ------------ | ----- | ----------- |
| @State       | 必须    | 可选          |
| @Prop        | 禁止    | 必须          |
| @Link        | 禁止    | 必须          |
| @StorageLink | 必须    | 禁止          |
| @StorageProp | 必须    | 禁止          |
| @Provide     | 必须    | 可选          |
| @Consume     | 禁止    | 禁止          |
| @ObjectLink  | 禁止    | 必须          |
| 常规成员变量       | 推荐    | 可选          |

从上表中可以看出：

- @State变量需要本地初始化，初始化的值可以被构造参数覆盖。

- @Prop和@Link变量必须且仅通过构造函数参数进行初始化。

通过构造函数方法初始化成员变量，需要遵循如下规则：

| 从父组件中的变量（下）到子组件中的变量（右） | @State | @Link  | @Prop  | 常规变量 |
| -------------------------------------------- | ------ | ------ | ------ | -------- |
| @State                                       | 不允许 | 允许   | 允许   | 允许     |
| @Link                                        | 不允许 | 允许   | 不推荐 | 允许     |
| @Prop                                        | 不允许 | 不允许 | 允许   | 允许     |
| @StorageLink                                 | 不允许 | 允许   | 不允许 | 不允许   |
| @StorageProp                                 | 不允许 | 不允许 | 不允许 | 允许     |
| 常规变量                                     | 允许   | 不允许 | 不允许 | 允许     |

从上表中可以看出：

- 父组件的常规变量可以用于初始化子组件的@State变量，但不能用于初始化@Link或@Prop变量。

- 父组件的@State变量可以初始化子组件的@Prop、@Link（通过$）或常规变量，但不能初始化子组件的@State变量。

- 父组件的@Link变量可以初始化子组件的@Link或常规变量。但是初始化子组件的@State成员是语法错误，此外不建议初始化@Prop。

- 父组件的@Prop变量可以初始化子组件的常规变量或@Prop变量，但不能初始化子组件的@State或@Link变量。

- @StorageLink和@StorageProp不允许由父组件中传递到子组件。

- 除了上述规则外，还需要遵循TS的强类型规则。