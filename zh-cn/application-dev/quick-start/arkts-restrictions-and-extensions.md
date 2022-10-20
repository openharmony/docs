# 使用限制与扩展

## 在生成器函数中的使用限制

ArkTS语言的使用在生成器函数中存在一定的限制：

- 表达式仅允许在字符串(${expression})、if条件、ForEach的参数和组件的参数中使用；
- 任何表达式都不能导致任何应用程序状态变量（@State、@Link、@Prop）的改变，否则会导致未定义和潜在不稳定的框架行为；
- 生成器函数内部不能有局部变量。

上述限制都不适用于事件处理函数（例如onClick）的匿函数实现。

## 变量的双向绑定

ArkTS支持通过$$双向绑定变量，通常应用于状态值频繁改变的变量。

- 当前$$支持基础类型变量，以及@State、@Link和@Prop装饰的变量。
- 当前$$仅支持[bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md)属性的show参数和@State变量之间的渲染，Radio组件的checked属性。
- $$绑定的变量变更时，仅渲染当前组件，提高渲染速度。

```ts
// xxx.ets
@Entry
@Component
struct bindPopup {
	@State customPopup: boolean = false
	build() {
		column() {
			button() {
				Text('Popup')
			}
			.onClick(() => {
				this.customPopup = !this.customPopup
			})
			.bindPopup(
				$$this.customPopup, {
				mesage: "showPopup"
				}
			)
		}
	}
}

```

## 状态变量多种数据类型声明使用限制

@State、@Provide、 @Link和@Consume四种状态变量的多种数据类型只能同时由简单数据类型或引用数据类型其中一种构成。

示例：

```ts
// xxx.ets
@Entry
@Component
struct Index {
  //错误写法: @State message: string | Resource = 'Hello World'
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(`${ this.message }`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```