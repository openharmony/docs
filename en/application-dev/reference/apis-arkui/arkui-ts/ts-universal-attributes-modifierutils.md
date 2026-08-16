# Attribute Modifier Utility

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sunbees-->
<!--Designer: @sunbees-->
<!--Tester: @khq-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=4da4cab88c5c9e987b28cefe3239aadd52f84dba translatedAt=2026-08-11T01:48:09.305Z pushedAt=2026-08-13T09:55:13.345Z -->

## ModifierUtils

**ModifierUtils** is a utility class for [AttributeModifier](../../../ui/arkts-user-defined-extension-attributeModifier.md), used to provide methods for attribute operations. For example, it can determine whether a given instance is of a specified component type. This is applicable to scenarios where different component types need to be distinguished and differentiated attribute settings need to be applied within a unified **AttributeModifier**.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

### isInstanceOf\<T extends CommonMethod\<T>>

isInstanceOf\<T extends CommonMethod\<T>>(instance: T, componentName: string): boolean

Checks whether a given instance is of a specified component type. For example, when implementing unified attribute modification logic for multiple component types in a custom **AttributeModifier**, this method can be used to determine the component type of the current instance, so that different attribute settings can be applied to different components.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name        | Type                        | Mandatory | Description                                                         |
| ----------- | --------------------------- | --------- | ------------------------------------------------------------ |
| instance    | T                           | Yes       | Instance to check. T is the component attribute type that inherits from [universal attributes](./ts-component-general-attributes.md) (CommonMethod).               |
| componentName | string                    | Yes       | Name of the component type to check. The value is the component class name (such as 'Text' or 'Button') and must exactly match the component class name (case-sensitive). Returns **false** if an invalid or nonexistent component class name is passed in.                                        |

**Return value**

| Type    | Description                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the instance is of the specified component type; returns **false** otherwise. |

**Example**  

```ts
// xxx.ets
// Click the button and check the log to determine whether the component enters the exclusive branch.
import { ModifierUtils } from '@kit.ArkUI';

class MyModifier implements AttributeModifier<TextAttribute | ButtonAttribute> {
  isDark: boolean = false;

  constructor(dark?: boolean) {
    this.isDark = dark ?? false;
  }

  applyNormalAttribute(instance: TextAttribute | ButtonAttribute): void {
    if (ModifierUtils.isInstanceOf(instance, 'Text')) {
      console.info('This is TextAttribute');
      const textInstance = instance as TextAttribute;
      if (this.isDark) {
        textInstance.backgroundColor(Color.Blue);
      } else {
        textInstance.backgroundColor(Color.Green);
      }
    } else if (ModifierUtils.isInstanceOf(instance, 'Button')) {
      console.info('This is ButtonAttribute');
      const buttonInstance = instance as ButtonAttribute;
      if (this.isDark) {
        buttonInstance.type(ButtonType.Circle);
        buttonInstance.backgroundColor(Color.Blue);
      } else {
        buttonInstance.type(ButtonType.Normal);
        buttonInstance.backgroundColor(Color.Green);
      }
    }
  }
}

@Entry
@Component
struct MultiComponentAttributeDemo {
  @State myModifier: MyModifier = new MyModifier();

  build() {
    Column() {
      Text('Text')
        .fontSize(50)
        .attributeModifier(this.myModifier)
        .onClick(() => {
          this.myModifier.isDark = !this.myModifier.isDark;
        })
      Button('Button')
        .attributeModifier(this.myModifier)
        .onClick(() => {
          this.myModifier.isDark = !this.myModifier.isDark;
        })
    }
    .justifyContent(FlexAlign.SpaceEvenly)
    .width('100%')
    .height('50%')
  }
}
```