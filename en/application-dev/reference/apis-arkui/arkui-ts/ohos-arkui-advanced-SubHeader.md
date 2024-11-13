# SubHeader


A subheader signifies the top of a list or the beginning a subdivision of content and tells the user what the list or subdivision is about.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { SubHeader } from '@kit.ArkUI'
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are supported.

> **NOTE**
>
> The [universal text attributes](ts-universal-attributes-text-style.md) are not supported.

## SubHeader

SubHeader({icon?: ResourceStr, iconSymbolOptions?: SymbolOptions, primaryTitle?: ResourceStr, secondaryTitle?: ResourceStr, select?: SelectOptions, operationType?: OperationType, operationItem?: Array&lt;OperationOption&gt;, operationSymbolOptions?: Array&lt;SymbolOptions&gt;})

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**


| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| icon | [ResourceStr](ts-types.md#resourcestr) | No| \@Prop | Icon.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| iconSymbolOptions<sup>12+</sup> | [SymbolOptions](#symboloptions12) | No| - | Icon symbol options. This parameter is available when **icon** is set to a [symbol glyph](ts-basic-components-symbolGlyph.md).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| primaryTitle | [ResourceStr](ts-types.md#resourcestr) | No| \@Prop | Primary title.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| secondaryTitle | [ResourceStr](ts-types.md#resourcestr) | No| \@Prop | Secondary title.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| select | [SelectOptions](#selectoptions) | No| - | Content and events for selection.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| operationType | [OperationType](#operationtype) | No| \@Prop | Type of operation in the operation area (right).<br>Default value: **OperationType.BUTTON**<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| operationItem | Array&lt;[OperationOption](#operationoption)&gt; | No| - | Items in the operation area (right).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| operationSymbolOptions<sup>12+</sup> | Array&lt;[SymbolOptions](#symboloptions12)&gt; | No| - | Icon symbol options.<br>This parameter is available when **operationType** is set to **OperationType.ICON_GROUP** and **operationItem** is set to an array of items.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| primaryTitleModifier<sup>12+</sup> | [TextModifier](ts-universal-attributes-attribute-modifier.md) | No| - | Text attributes of the primary title, such as the font color, font size, and font weight.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| secondaryTitleModifier<sup>12+</sup> | [TextModifier](ts-universal-attributes-attribute-modifier.md) | No| - | Text attributes of the secondary title, such as the font color, font size, and font weight.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| titleBuilder<sup>12+</sup> | () => void | No| @BuildParam | Content of the custom title area.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| contentMargin<sup>12+</sup> | [LocalizedMargin](ts-types.md#localizedmargin12) | No| @Prop | Margin of the content. Negative numbers are not supported.<br>Default value:<br> `{start: LengthMetrics.resource(` <br> `$r('sys.float.margin_left'))`, <br> `end: LengthMetrics.resource(` <br> `$r('sys.float.margin_right'))}`<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| contentPadding<sup>12+</sup> | [LocalizedPadding](ts-types.md#localizedpadding12) | No| @Prop | Padding of the content.<br>Default value:<br>If a secondary title, with or without an icon, is displayed on the left:<br> {start: LengthMetircs.vp(12), end: LengthMetrics.vp(12)}<br>**Atomic service API**: This API can be used in atomic services since API version 12.|


## OperationType

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Value| Description|
| -------- | -------- | -------- |
| TEXT_ARROW |  0  | Text button with a right arrow.|
| BUTTON |  1  |  Text button without a right arrow.|
| ICON_GROUP |  2  |  Icon-attached button (A maximum of three icons can be configured.)|
| LOADING |  3  |  Loading animation.|

## SelectOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | Array&lt;[SelectOption](ts-basic-components-select.md#selectoption)&gt; | Yes| Value of an option in the drop-down list box.|
| selected | number | No| Index of the initial selected option in the drop-down list.<br>The index of the first option is 0.<br>If this attribute is not set,<br>the default value **-1** is used, indicating that the option is not selected.|
| value | string | No| Text content of the drop-down list button itself.|
| onSelect | (index: number, value?: string) =&gt; void | No| Invoked when an option in the drop-down list box is selected.<br>- **index**: index of the selected option.<br>- **value**: value of the selected option.|

## OperationOption

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | Yes| Text content.|
| action | ()=&gt;void | No| Event.|

## SymbolOptions<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fontColor | [ResourceStr](ts-types.md#resourcestr) | No| Color of the [symbol glyph](ts-basic-components-symbolGlyph.md).<br>Default value: depending on the rendering strategy|
| fontSize | number \|string \|[Resource](ts-types.md#Resource) | No| Size of the [symbol glyph](ts-basic-components-symbolGlyph.md).<br>Default value: system default value|
| fontWeight | [FontWeight](ts-appendix-enums.md#fontweight)\|number \|string | No| Font weight of the [symbol glyph](ts-basic-components-symbolGlyph.md).<br>For the number type, the value ranges from 100 to 900, at an interval of 100. A larger value indicates a heavier font weight. The default value is **400**.<br>For the string type, only strings of the number type are supported, for example, **"400"**, **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**, which correspond to the enumerated values in **FontWeight**.<br>Default value: **FontWeight.Normal**|
| renderingStrategy | [SymbolRenderingStrategy](ts-basic-components-symbolGlyph.md#symbolrenderingstrategy11) | No| Rendering strategy of the [symbol glyph](ts-basic-components-symbolGlyph.md).<br>Default value: **SymbolRenderingStrategy.SINGLE**<br>**NOTE**<br>For the resources referenced in **$r('sys.symbol.ohos_*')**, only **ohos_trash_circle**, **ohos_folder_badge_plus**, and **ohos_lungs** support the **MULTIPLE_COLOR** modes.|
| effectStrategy | [SymbolEffectStrategy](ts-basic-components-symbolGlyph.md#symboleffectstrategy11) | No| Effect strategy of the [symbol glyph](ts-basic-components-symbolGlyph.md).<br>Default value: **SymbolEffectStrategy.NONE**<br>**NOTE**<br>For the resources referenced in **$r('sys.symbol.ohos_*')**, only **ohos_wifi** supports the hierarchical effect.|

## Events
The [universal events](ts-universal-events-click.md) are supported.

## Example
### Example 1

```ts
import { promptAction, OperationType, SubHeader } from '@kit.ArkUI'

@Entry
@Component
struct SubHeaderExample {
  build() {
    Column() {
      SubHeader({
        icon: $r('app.media.ic_public_community_messages'),
        secondaryTitle: 'Secondary title',
        operationType: OperationType.BUTTON,
        operationItem: [{ value: 'Operation',
          action: () => {
            promptAction.showToast({ message: 'demo' })
          }
        }]
      })
    }
  }
}
```

![Subheader 1](figures/en-us_image_subheader_example01.png)

### Example 2

```ts
import { promptAction, OperationType, SubHeader } from '@kit.ArkUI'

@Entry
@Component
struct SubHeaderExample {
  build() {
    Column() {
      SubHeader({
        primaryTitle: 'Primary title',
        secondaryTitle: 'Secondary title',
        operationType: OperationType.TEXT_ARROW,
        operationItem: [{value:'More',
          action: () => {
            promptAction.showToast({ message: 'demo' })
          }
        }]
      })
    }
  }
}
```

![Subheader 2](figures/en-us_image_subheader_example02.png)

### Example 3

```ts
import { promptAction, OperationType, SubHeader } from '@kit.ArkUI'

@Entry
@Component
struct SubHeaderExample {
  build() {
    Column() {
      SubHeader({
        select: {
          options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }],
          value: 'selectdemo',
          selected: 2,
          onSelect: (index: number, value?: string) => {
            promptAction.showToast({ message: 'demo' })
          }
        },
        operationType: OperationType.ICON_GROUP,
        operationItem: [{
          value: $r('app.media.ic_public_community_messages'),
          action: () => {
            promptAction.showToast({ message: 'demo' })
          }
        }, {
          value: $r('app.media.ic_public_community_messages'),
          action: () => {
            promptAction.showToast({ message: 'demo' })
          }
        }, {
          value: $r('app.media.ic_public_community_messages'),
          action: () => {
            promptAction.showToast({ message: 'demo' })
          }
        }]
      })
    }
  }
}
```

![Subheader 3](figures/en-us_image_subheader_example03.png)

### Example 4

```ts

import { promptAction, OperationType, SubHeader } from '@kit.ArkUI'

@Entry
@Component
struct SubHeaderExample {
  build() {
    Column() {
      SubHeader({
        icon: $r('sys.symbol.ohos_wifi'),
        iconSymbolOptions: {
          effectStrategy: SymbolEffectStrategy.HIERARCHICAL,
        },
        secondaryTitle: 'Title',
        operationType: OperationType.BUTTON,
        operationItem: [{ value: 'Operation',
          action: () => {
            promptAction.showToast({ message: 'demo' })
          }
        }]
      })
    }
  }
}
```

![Subheader 4](figures/en-us_image_subheader_example04.gif)

### Example 5

```ts
import { promptAction, OperationType, SubHeader } from '@kit.ArkUI'

@Entry
@Component
struct SubHeaderExample {
  build() {
    Column() {
      SubHeader({
        select: {
          options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }],
          value: 'selectdemo',
          selected: 2,
          onSelect: (index: number, value?: string) => {
            promptAction.showToast({ message: 'demo' })
          }
        },
        operationType: OperationType.ICON_GROUP,
        operationItem: [{
          value: $r('sys.symbol.ohos_lungs'),
          action: () => {
            promptAction.showToast({ message: 'icon1' })
          }
        }, {
          value: $r('sys.symbol.ohos_lungs'),
          action: () => {
            promptAction.showToast({ message: 'icon2' })
          }
        }, {
          value: $r('sys.symbol.ohos_lungs'),
          action: () => {
            promptAction.showToast({ message: 'icon3' })
          }
        }],
        operationSymbolOptions: [{
          fontWeight: FontWeight.Lighter,
        }, {
          renderingStrategy: SymbolRenderingStrategy.MULTIPLE_COLOR,
          fontColor: [Color.Blue, Color.Grey, Color.Green],
        }, {
          renderingStrategy: SymbolRenderingStrategy.MULTIPLE_OPACITY,
          fontColor: [Color.Blue, Color.Grey, Color.Green],
        }]
      })
    }
  }
}
```

![Subheader 5](figures/en-us_image_subheader_example05.png)

### Example 6

```ts
// This example customizes the title content with a titleBuilder object in the SubHeader component.
import { promptAction, OperationType, SubHeader } from '@kit.ArkUI';

@Entry
@Component
struct SubHeaderExample {
  @Builder
  TitleBuilder(): void {
    Text('Custom title')
      .fontSize(24)
      .fontColor(Color.Red)
      .fontWeight(FontWeight.Bold)
  }

  build() {
    Column() {
      SubHeader({
        titleBuilder: () => {
          this.TitleBuilder();
        },
        primaryTitle: 'Primary title',
        secondaryTitle: 'Secondary title',
        icon: $r('sys.symbol.ohos_star'),
        operationType: OperationType.TEXT_ARROW,
        operationItem: [{
          value: 'More info',
          action: () => {
            promptAction.showToast({ message: 'demo'})
          }
        }]
      })
    }
  }
}
```

![Subheader 6](figures/en-us_image_subheader_example06.png)

### Example 7

```ts
// This example demonstrates how to set the font style, margin, and padding for the primary and secondary titles in the SubHeader component.
import { promptAction, OperationType, SubHeader, LengthMetrics, TextModifier } from '@kit.ArkUI';

@Entry
@Component
struct SubHeaderExample {
  @State primaryModifier: TextModifier = new TextModifier().fontColor(Color.Red);
  @State secondaryModifier: TextModifier = new TextModifier().fontColor(Color.Red);

  build() {
    Column() {
      SubHeader({
        primaryTitle: 'primaryTitle',
        secondaryTitle: 'secondaryTitle',
        primaryTitleModifier: this.primaryModifier,
        secondaryTitleModifier: this.secondaryModifier,
        operationType: OperationType.TEXT_ARROW,
        operationItem: [{
          value: 'More info',
          action: () => {
            promptAction.showToast({ message: 'demo'})
          }
        }],
        contentMargin: { start: LengthMetrics.vp(20), end: LengthMetrics.vp(20) },
        contentPadding: { start: LengthMetrics.vp(20), end: LengthMetrics.vp(20) }
      })
    }
  }
}
```

![Subheader 7](figures/en-us_image_subheader_example07.png)
