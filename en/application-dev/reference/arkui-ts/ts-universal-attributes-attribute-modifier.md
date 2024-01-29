# Attribute Modifier

With the attribute modifier, you can dynamically set component attributes, complete with the **if/else** syntax and polymorphic style.

>  **NOTE**
>
>  This feature is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.

## attributeModifier

attributeModifier(modifier: AttributeModifier\<T>)

Creates an attribute modifier.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| modifier | AttributeModifier\<T> | Yes  | Modifier for dynamically setting attributes on the current component. The **if/else** syntax is supported.<br>**modifier**: attribute modifier. You need to customize classes to implement the **AttributeModifier** API.<br> Currently, this API only works with the **backgroundColor** attribute of the **\<Button>** component.|

## AttributeModifier\<T>

You need to customize classes to implement the **AttributeModifier** API.

### applyNormalAttribute
applyNormalAttribute(instance: T) : void

Applies the style of a component in the normal state.

### applyPressedAttribute
applyPressedAttribute(instance: T) : void

Applies the style of a component in the pressed state.

### applyFocusedAttribute
applyFocusedAttribute(instance: T) : void

Applies the style of a component in the focused state.

### applyDisabledAttribute
applyDisabledAttribute(instance: T) : void

Applies the style of a component in the disabled state.

### applySelectedAttribute
applySelectedAttribute(instance: T) : void

Applies the style of a component in the selected state.

In the preceding APIs, **instance** indicates the component type. You can customize these APIs and use them with the **if/else **syntax.

**Parameters**

| Name            | Description                                                        |
| -------------------- | ------------------------------------------------------------ |
| instance |Component attribute class, which identifies the type of component to which attributes will be applied, for example, **ButtonAttribute** for the **\<Button>** component and **TextAttribute** of the **\<Text>** component.|

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



```ts
// xxx.ets
class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  applyNormalAttribute(instance: ButtonAttribute): void {
    instance.backgroundColor(Color.Black)
  }

  applyPressedAttribute(instance: ButtonAttribute): void {
    instance.backgroundColor(Color.Red)
  }
}

@Entry
@Component
struct attributePressedDemo {
  @State modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![attributeModifier_ifelse](figures/attributeModifier_ifelse.gif)
