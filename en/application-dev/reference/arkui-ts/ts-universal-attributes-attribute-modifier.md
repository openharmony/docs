# Attribute Modifier

With the attribute modifier, you can dynamically set component attributes, complete with the **if/else** syntax.

>  **NOTE**
>
>  This feature is supported since API Version 11. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

| Name             | Type                                       | Description                                                        |
| ----------------- | ----------------------------------------------- | ------------------------------------------------------------ |
| attributeModifier | modifier:&nbsp;AttributeModifier\<T> | Modifier for dynamically setting attributes on the current component. The **if/else** syntax is supported.<br>**modifier**: attribute modifier. You need to customize classes to implement the **AttributeModifier** API.<br>Currently, this API only works with the **backgroundColor** attribute of the **\<Button>** component. |

## AttributeModifier\<T>

You need to customize classes to implement the **AttributeModifier** API.

### applyNormalAttribute
applyNormalAttribute(instance: T) : void

Applies the attributes to the component type specified by **instance**. This method can be used with the **if/else** syntax. You must customize this method.

**Parameters**

| Name            | Type   | Description                                                        |
| -------------------- | ----------------- | ------------------------------------------------------------ |
| instance | T | Component attribute class, which identifies the type of component to which attributes will be applied, for example, **ButtonAttribute** for the **\<Button>** component and **TextAttribute** of the **\<Text>** component.|

## Example

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
