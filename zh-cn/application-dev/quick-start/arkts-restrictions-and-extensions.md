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

1. 所有的状态装饰器变量需要显式声明变量类型，不允许声明any，不支持Date数据类型。

    示例：

    ```ts
    // xxx.ets
    @Entry
    @Component
    struct DatePickerExample {
      //错误写法: @State isLunar: any = false
      @State isLunar: boolean = false
      //错误写法: @State selectedDate: Date = new Date('2021-08-08')
      private selectedDate: Date = new Date('2021-08-08')

      build() {
        Column() {
          Button('切换公历农历')
            .margin({ top: 30 })
            .onClick(() => {
              this.isLunar = !this.isLunar
            })
          DatePicker({
            start: new Date('1970-1-1'),
            end: new Date('2100-1-1'),
            selected: this.selectedDate
          })
            .lunar(this.isLunar)
            .onChange((value: DatePickerResult) => {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
              console.info('select current date is: ' + JSON.stringify(value))
            })

        }.width('100%')
      }
    }
    ```

    ![datePicker](../../application-dev/reference/arkui-ts/figures/datePicker.gif)

2. @State、@Provide、 @Link和@Consume四种状态变量的数据类型声明只能由简单数据类型或引用数据类型的其中一种构成。

    类型定义中的Length、Resource、ResourceColor三个类型是简单数据类型或引用数据类型的组合，所以不能被以上四种状态装饰器变量使用。
    Length、Resource、ResourceColor的定义请看文档[arkui-ts类型定义](../../application-dev/reference/arkui-ts/ts-types.md)。

    示例：

    ```ts
    // xxx.ets
    @Entry
    @Component
    struct IndexPage {
      //错误写法: @State message: string | Resource = 'Hello World'
      @State message: string = 'Hello World'
      //错误写法: @State message: ResourceStr = $r('app.string.hello')
      @State resourceStr: Resource = $r('app.string.hello')

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
| @LocalStorageLink | 必须    | 禁止          |
| @LocalStorageProp | 必须    | 禁止          |
| @Provide     | 必须    | 可选          |
| @Consume     | 禁止    | 禁止          |
| @ObjectLink  | 禁止    | 必须          |
| 常规成员变量       | 推荐    | 可选          |

从上表中可以看出：

- @State变量需要本地初始化，初始化的值可以被构造参数覆盖。

- @Prop和@Link变量必须且仅通过构造函数参数进行初始化。

通过构造函数方法初始化成员变量，需要遵循如下规则：

| **从父组件中的变量(右)到子组件中的变量(下)** | **regular** | **@State** | **@Link** | **@Prop** | **@Provide** | **@Consume** | **@ObjectLink** |
|---------------------------------|----------------------------|------------|-----------|-----------|--------------|--------------|------------------|
| **regular**                    | 支持                         | 支持         | 支持        | 支持        | 不支持            | 不支持            | 支持               |
| **@State**                     | 支持                         | 支持         | 支持        | 支持        | 支持           | 支持           | 支持               |
| **@Link**                      | 不支持                          | 支持(1)      | 支持(1)     | 支持(1)     | 支持(1)        | 支持(1)        | 支持(1)            |
| **@Prop**                      | 支持                         | 支持         | 支持        | 支持        | 支持           | 支持           | 支持               |
| **@Provide**                   | 支持                         | 支持         | 支持        | 支持        | 支持           | 支持           | 支持               |
| **@Consume**                   | 不支持                          | 不支持          | 不支持         | 不支持         | 不支持            | 不支持            | 不支持                |
| **@ObjectLink**                | 不支持                          | 不支持      | 不支持         | 不支持         | 不支持            | 不支持            | 不支持                |

| **从父组件中的变量(右)到子组件中的变量(下)** | **@StorageLink** | **@StorageProp** | **@LocalStorageLink** | **@LocalStorageProp** |
|------------------|------------------|------------------|-----------------------|------------------------|
| **regular**                   | 支持               | 不支持                | 不支持                     | 不支持              |
| **@State**                    | 支持               | 支持               | 支持                    | 支持                     |
| **@Link**                     | 支持(1)            | 支持(1)            | 支持(1)                 | 支持(1)                  |
| **@Prop**                     | 支持               | 支持               | 支持                    | 支持                     |
| **@Provide**                  | 支持               | 支持               | 支持                    | 支持                     |
| **@Consume**                  | 不支持             | 不支持              | 不支持                  | 不支持                   |
| **@ObjectLink**               | 不支持             | 不支持              | 不支持                  | 不支持                   |

> **说明**
>
> **支持(1)**：必须使用`$`, 例如 `this.$varA`。  
> **regular**：未加修饰的常规变量。

从上表中可以看出：

- 子组件的@ObjectLink变量不支持父组件装饰器变量的直接赋值，其父组件的源必须是数组的项或对象的属性，该数组或对象必现用`@State`、`@Link`、`@Provide`、`@Consume`或`@ObjectLink`装饰器修饰。

- 父组件的常规变量可以用于初始化子组件的`@State`变量，但不能用于初始化`@Link`、`@Consume`和`@ObjectLink`变量。

- 父组件的@State变量可以初始化子组件的`@Prop`、`@Link`（通过$）或常规变量，但不能初始化子组件的@Consume变量。

- 父组件的@Link变量不可以初始化子组件的`@Consume`和`@ObjectLink`变量。

- 父组件的@Prop变量不可以初始化子组件的`@Consume`和`@ObjectLink`变量。

- 不允许从父组件初始化`@StorageLink`, `@StorageProp`, `@LocalStorageLink`, `@LocalStorageProp`修饰的变量。

- 除了上述规则外，还需要遵循TS的强类型规则。

示例：
```ts
@Entry
@Component
struct Parent {
  message: string = "Hello World"
  build() {
    Column() {
      Child({
        stateMessage: this.message,
        /* ArkTS:ERROR The regular property 'message' cannot be assigned  
           to the @Link property 'linkMessage'.*/
        linkMessage: this.$message
      })
    }
    .width('100%')
  }
}

@Component
struct Child {
  @State stateMessage: string = "Hello World"
  @Link linkMessage: string
  build() {
    Column() {
      Text(this.stateMessage)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
    .width('100%')
  }
}
```
