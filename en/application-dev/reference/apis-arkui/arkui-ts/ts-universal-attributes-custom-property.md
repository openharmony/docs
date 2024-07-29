# Custom Property

If you want to set customized attributes on a component, you can use the customized attribute setting function to set customized attributes on the component. These customized attributes can be obtained from the corresponding FrameNode to implement more flexible component management.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## customProperty

customProperty(name: string, value: Optional\<Object>)

Sets the custom property of the component. This API does not work for [custom components](../../../quick-start/arkts-create-custom-components.md#creating-a-custom-component).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Parameter | Type                                                | Mandatory | Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name  | string | Yes  | Name of the custom property. |
| value  | Optional\<Object> | Yes  | Value of the custom property. |


## Optional<sup>12+</sup>

Optional\<T>

Defines an optional type. The value can be **undefined**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

## Example
```ts
// xxx.ets
import { FrameNode, UIContext } from '@kit.ArkUI';

@Entry
@Component
struct CustomPropertyExample {
  build() {
    Column() {
      Text('text')
      Button('print').onClick(() => {
        const uiContext: UIContext = this.getUIContext();
        if (uiContext) {
          const node: FrameNode | null = uiContext.getFrameNodeById("Test_Column") || null;
          if (node) {
            for (let i = 1; i < 4; i++) {
              const key = 'customProperty' + i;
              const property = node.getCustomProperty(key);
              console.log(key, JSON.stringify(property));
            }
          }
        }
      })
    }
    .id('Test_Column')
    .customProperty('customProperty1', {
      'number': 10,
      'string': 'this is a string',
      'bool': true,
      'object': {
        'name': 'name',
        'value': 100
      }
    })
    .customProperty('customProperty2', {})
    .customProperty('customProperty2', undefined)
    .width('100%')
    .height('100%')
  }
}
```
