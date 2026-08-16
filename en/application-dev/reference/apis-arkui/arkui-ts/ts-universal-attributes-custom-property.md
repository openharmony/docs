# Custom Property

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022; @jiyujia926-->
<!--Tester: @sally__; @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=32622137964e413dc3b3d2cfcce2fb11c339dbb4 translatedAt=2026-08-13T11:54:30.577Z pushedAt=2026-08-14T09:50:53.684Z -->

When you want to set custom properties on a component, you can use the custom property setting feature. These custom properties can be obtained on the FrameNode corresponding to the component, facilitating component management based on the custom properties.

>  **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## customProperty

customProperty(name: string, value: Optional\<Object>): T

Sets a custom property for this component.

In versions earlier than API 26.0.0, [custom components](../../../ui/state-management/arkts-create-custom-components.md) do not support custom properties.

Since API 26.0.0, custom components support setting and reading custom properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name  | string | Yes  | Name of the custom property.|
| value  | [Optional](#optionalt)\<Object> | Yes  | Value of the custom property.|

**Return value**

| Type| Description|
| --- | --- |
| T | Current component, which can be used for chained calls. |

## Optional\<T>

type Optional\<T> = T | undefined

Defines the Optional type. The value can be **undefined**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

| Type| Description                      |
| ---- | -------------------------- |
| T | Type specified by the generic parameter T. |
| undefined | The object is **undefined**.|

## Example

### Example 1: Setting Custom Properties for a System Component

This example shows how to set custom properties on the [Column](ts-container-column.md) component and obtain the set custom properties from its corresponding [FrameNode](../js-apis-arkui-frameNode.md#framenode-1).

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
        // Obtain the frameNode corresponding to the Column and query the set custom properties.
        const uiContext: UIContext = this.getUIContext();
        if (uiContext) {
          const node: FrameNode | null = uiContext.getFrameNodeById('Test_Column');
          if (node) {
            for (let i = 1; i < 4; i++) {
              const key = 'customProperty' + i;
              const property = node.getCustomProperty(key);
              console.info(key, JSON.stringify(property));
            }
          }
        }
      })
    }
    .id('Test_Column')
    // Set custom properties for the Column component.
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
    .customProperty('customProperty3', undefined)
    .width('100%')
    .height('100%')
  }
}
```

### Example 2: Setting Custom Properties for a Custom Component

Since API version 26.0.0, custom properties can be set for custom components via the [customProperty](#customproperty) API. This example demonstrates a [custom component layout](../../../ui/state-management/arkts-page-custom-components-layout.md) scenario: custom properties are set for a custom component, and their values are obtained from the [onMeasureSize](ts-custom-component-layout.md#onmeasuresize10) callback.

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      CustomLayout({ builder: columnChildren })
        .customProperty('width', 100) // Set custom properties for the custom component.
        .customProperty('height', 400)
    }
  }
}

// Pass multiple components in a builder as level-1 child components of the custom component (excluding container components such as Column).
@Builder
function columnChildren() {
  ForEach([1, 2, 3], (index: number) => {
    Text('S' + index)
      .fontSize(30)
      .width(100)
      .height(100)
      .borderWidth(2)
      .offset({ x: 10, y: 20 })
  })
}

@Component
struct CustomLayout {
  @Builder
  doNothingBuilder() {
  };

  @BuilderParam builder: () => void = this.doNothingBuilder;
  result: SizeResult = {
    width: 0,
    height: 0
  };

  // Calculate the size of each child component.
  onMeasureSize(selfLayoutInfo: GeometryInfo, children: Array<Measurable>, constraint: ConstraintSizeOptions) {
    let size = 100;
    children.forEach((child) => {
      let result: MeasureResult = child.measure({ minHeight: size, minWidth: size, maxWidth: size, maxHeight: size })
      size += result.width / 2;
    })
    let frameNode = this.getUIContext().getFrameNodeByUniqueId(this.getUniqueId());
    // Use getCustomProperty to obtain the custom properties.
    // this.result represents the custom component's own size. The onMeasureSize method returns this.result.
    this.result.width = (frameNode?.getCustomProperty('width') as number) ?? 50;
    this.result.height = (frameNode?.getCustomProperty('height') as number) ?? 50;
    return this.result;
  }
  // Set the position of each child component.
  onPlaceChildren(selfLayoutInfo: GeometryInfo, children: Array<Layoutable>, constraint: ConstraintSizeOptions) {
    let startPos = 300;
    children.forEach((child) => {
      let pos = startPos - child.measureResult.height;
      child.layout({ x: pos, y: pos })
    })
  }

  build() {
    this.builder()
  }
}
```

![getCustomProperty_layout](figures/custom_property_layout.png)