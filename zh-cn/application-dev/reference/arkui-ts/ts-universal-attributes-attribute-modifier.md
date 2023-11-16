# 动态属性设置

动态设置组件的属性，支持开发者在属性设置时使用if/else语法。

>  **说明：**
>
>  从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 属性

| 名称              | 参数类型                                        | 描述                                                         |
| ----------------- | ----------------------------------------------- | ------------------------------------------------------------ |
| attributeModifier | modifier:&nbsp;AttributeModifier\<T> | 在当前组件上，动态设置属性方法，支持使用if/else语法。<br/>modifier: 属性修改器，开发者需要自定义class实现AttributeModifier接口。 <br/> 当前仅支持Button组件的backgroundColor属性。|

## AttributeModifier\<T>

开发者需要自定义class实现AttributeModifier接口。

### applyNormalAttribute
applyNormalAttribute(instance: T) : void

开发者需要自定义实现该方法，通过传入的参数识别组件类型，对instance设置属性，支持使用if/else语法进行动态设置。

**参数**：

| 参数             | 参数类型    | 描述                                                         |
| -------------------- | ----------------- | ------------------------------------------------------------ |
| instance | T | 组件的属性类，用来标识进行属性设置的组件的类型，比如Button组件的ButtonAttribute，Text组件的TextAttribute等。|

## 示例

```ts
// xxx.ets
class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  isDark: boolean = false
  applyNormalAttribute(instance: ButtonAttribute): void {
    if (this.isDark) {
      instance.backgroundColor(Color.Black)
    } else {
      instance.backgroundColor(Color.Red)
    }
  }
}

@Entry
@Component
struct attributeDemo {
  @State modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
          .onClick(() => {
            this.modifier.isDark = !this.modifier.isDark
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![attributeModifier_ifelse](figures/attributeModifier_ifelse.gif)