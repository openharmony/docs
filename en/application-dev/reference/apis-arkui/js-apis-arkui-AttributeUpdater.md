# AttributeUpdater

The attribute is directly set to the component, and the UI update can be directly triggered without being marked as a state variable.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>


## Import modules.

```ts
import { AttributeUpdater } from '@ohos.arkui.modifier'
```

>  **Instructions**
>  
>  1. When the attribute method is set at the same time or the applyNormalAttribute method is implemented in the AttributeUpdater, the status management update mechanism is used at the same time, which may cause confusion. Therefore, you are not advised to use the two methods to set the same attribute on the same component at the same time.
>  
>  2. When this parameter is set together with the attribute method, the attribute that is set later takes effect.
>  If the attribute straight-through update is performed first, and then the attribute method is updated by using the status management mechanism, the attribute method updated later takes effect.
>  If the attribute method is updated first by using the status management mechanism, and then the attribute passthrough update is performed, the attribute passthrough update takes effect.
>  
>  3. An AttributeUpdater object can be associated with only one component at a time. Otherwise, the configured attributes take effect only on one component.
>  
>  4. Developers need to ensure that the T and C types in AttributeUpdater match. For example, if T is ImageAttribute, C must be ImageInterface. Otherwise,
>  The function is abnormal when updateConstructorParams is used.
>  
>  5. Currently, updateConstructorParams supports only the Image, Text, and Span components.

## Initializer
type Initializer\<T> = () => T

You can update properties to a local modifier.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## AttributeUpdater<T, C = Initializer\<T>>
is the implementation class of [AttributeModifier](arkui-ts/ts-universal-attributes-attribute-modifier.md#AttributeModifier). Developers need to customize a class to inherit AttributeUpdater.

C indicates the constructor type of the component, for example, TextInterface of the Text component and ImageInterface of the Image component. The C type needs to be transferred only when updateConstructorParams is used.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### applyNormalAttribute
applyNormalAttribute?(instance: T): void

Defines the function for updating attributes in normal state.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters

| Parameter | Type  | Mandatory/Optional | Note:                                                                    |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| instance | T | M | Component attribute class, which identifies the type of component to which attributes will be applied, for example, **ButtonAttribute** for the **\<Button>** component and **TextAttribute** for the **\<Text>** component.|

### initializeModifier
initializeModifier(instance: T): void

Style provided when the AttributeUpdater is set for the component for the first time.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters

| Parameter | Type  | Mandatory/Optional | Note:                                                                    |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| instance | T | Supported | Component attribute class, which identifies the type of component to which attributes will be applied, for example, **ButtonAttribute** for the **\<Button>** component and **TextAttribute** for the **\<Text>** component.|

**Example** 

The initializeModifier method is used to initialize and set attribute values.

```ts
// xxx.ets
import { AttributeUpdater } from '@ohos.arkui.modifier'

class MyButtonModifier extends AttributeUpdater<ButtonAttribute> {
  initializeModifier(instance: ButtonAttribute): void {
    instance.backgroundColor('#ff2787d9')
      .width('50%')
      .height(30)
  }
}

@Entry
@Component
struct updaterDemo1 {
  modifier: MyButtonModifier = new MyButtonModifier()

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
![attributeUpdater1](figures/attribute-updater1.PNG)


### attribute
get attribute(): T | undefined

Obtains the attribute class instance corresponding to the component in AttributeUpdater and implements the attribute passthrough update function through the instance.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Returns:**

| Type            | Description                                                        |
| -------------------- | ------------------------------------------------------------ |
| T \| undefined |If the attribute class instance of the component in AttributeUpdater exists, the attribute class instance of the corresponding component is returned. Otherwise, undefined is returned.|

**Example** 

Update the attribute value in attribute pass-through setting mode.

```ts
// xxx.ets
import { AttributeUpdater } from '@ohos.arkui.modifier'

class MyButtonModifier extends AttributeUpdater<ButtonAttribute> {
  initializeModifier(instance: ButtonAttribute): void {
    instance.backgroundColor('#ffd5d5d5')
      .width('50%')
      .height(30)
  }
}

@Entry
@Component
struct updaterDemo2 {
  modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
          .onClick(() => {
            this.modifier.attribute?.backgroundColor('#ff2787d9').width('30%')
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![attributeUpdater2](figures/attribute-updater2.gif)

### updateConstructorParams
updateConstructorParams: C

This API is used to modify the construction input parameter of a gadget. C indicates the constructor type of the component.

C indicates the constructor type of the component, for example, TextInterface of the Text component and ImageInterface of the Image component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example** 

Use updateConstructorParams to update the gadget to construct input parameters.

```ts
// xxx.ets
import { AttributeUpdater } from '@ohos.arkui.modifier'

class MyTextModifier extends AttributeUpdater<TextAttribute, TextInterface> {
  initializeModifier(instance: TextAttribute) {
  }
}

@Entry
@Component
struct attributeDemo3 {
  private modifier: MyTextModifier = new MyTextModifier()

  build() {
    Row() {
      Column() {
        Text("Initialize")
          .attributeModifier(this.modifier)
          .fontSize(14).border({ width: 1 }).textAlign(TextAlign.Center).lineHeight(20)
          .width(200).height(50)
          .backgroundColor('#fff7f7f7')
          .onClick(() => {
            this.modifier.updateConstructorParams("Updated")
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![attributeUpdater3](figures/attribute-updater3.gif)
