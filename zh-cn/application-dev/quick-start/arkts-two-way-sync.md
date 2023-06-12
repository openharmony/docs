# $$语法：内置组件双向同步


$$运算符为系统内置组件提供TS变量的引用，使得TS变量和系统内置组件的内部状态保持同步。


内部状态具体指什么取决于组件。例如，[bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md)属性方法的show参数。


## 使用规则

- 当前$$支持基础类型变量，以及\@State、\@Link和\@Prop装饰的变量。

- 当前$$仅支持[bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md)属性方法的show参数，[Radio](../reference/arkui-ts/ts-basic-components-radio.md)组件的checked属性，[Refresh](../reference/arkui-ts/ts-container-refresh.md)组件的refreshing参数。

- $$绑定的变量变化时，会触发UI的同步刷新。


## 使用示例

以[bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md)属性方法的show参数为例：


```ts
// xxx.ets
@Entry
@Component
struct bindPopupPage {
  @State customPopup: boolean = false;

  build() {
    Column() {
      Button('Popup')
        .margin(20)
        .onClick(() => {
          this.customPopup = !this.customPopup
        })
        .bindPopup($$this.customPopup, {
          message: 'showPopup'
        })
    }
  }
}
```


![popup](figures/popup.gif)
