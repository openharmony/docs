# ToolBarV2

The **Toolbar** component is designed to present a set of action options related to the current screen, displayed at the bottom of the screen. It can display up to five child components. If there are six or more child components, the first four are shown directly, and the additional ones are grouped under a **More** item on the rightmost side of the toolbar.<br>
This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), V2 offers a higher level of observation and management over data objects beyond the component level. You can now more easily manage toolbar data and states with greater flexibility, leading to faster UI updates.<br>

> **NOTE**
>
> - This component is supported since API version 18. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { ToolBarV2 } from '@kit.ArkUI';
```

## Child Components

Not supported


## ToolBarV2

ToolbarV2({toolBarList: ToolBarV2Item\[], activatedIndex?: number, dividerModifier: DividerModifier, toolBarModifier: ToolBarV2Modifier})

Creates a toolbar.

**Decorator**: @ComponentV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Type                                                              | Mandatory| Decorator              | Description                                                          |
| -------------------- | ---------------------------------------------------------------- | -- |---------------------|--------------------------------------------------------------|
| toolBarList          | [ToolBarV2Item](#toolbarv2item)\[]                               | Yes | @Param<br>@Require | Toolbar list.                                                      |
| activatedIndex       | number                                                           | No | @Param              | Index of the active item.<br>Default value: **-1**, indicating that no toolbar item is activated<br>Value range: [-1, 4]     |
| dividerModifier<sup> | [DividerModifier](ts-universal-attributes-attribute-modifier.md) | No | @Param              | Modifier for the toolbar header divider, which can be used to customize the divider's height, color, and other attributes.<br>This parameter does not take effect by default.                        |
| toolBarModifier<sup> | [ToolBarV2Modifier](#toolbarv2modifier)                          | No | @Param              | Modifier for the toolbar, which can be used to set the toolbar's height, background color, padding (which only takes effect when there are fewer than five toolbar items), and whether to display the pressed state.<br>This parameter does not take effect by default.|

## ToolBarV2Item
Defines an item in the toolbar.

**Decorator type**: @ObservedV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

| Name                          | Type                                             | Mandatory| Decorator | Description                                                                                                                                                                                                       |
| ---------------------------- | ----------------------------------------------- | -- | :----- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| content                      | [ToolBarV2ItemText](#toolbarv2itemtext)         | Yes | @Trace | Text of the toolbar item.                                                                                                                                                                                                |
| action                       | [ToolBarV2ItemAction](#toolbarv2itemaction)     | No | @Trace | Click event of the toolbar item.<br><br>By default, there is no click event.                                                                                                                                                                                 |
| icon                         | [ToolBarV2ItemIconType](#toolbarv2itemicontype) | No | @Trace | Icon of the toolbar item.<br><br>By default, there is no icon.                                                                                                                                                                                   |
| state                        | [ToolBarV2ItemState](#toolbarv2itemstate)       | No | @Trace | State of the toolbar item.<br>Default value: **ENABLE**<br>                                                                                                                                                                          |
| accessibilityText     | [ResourceStr](ts-types.md#resourcestr)          | No | @Trace | Accessibility text, that is, accessible label name, of the toolbar item. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br><br>Default value: value of **content**            |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr)          | No | @Trace | Accessible description of the toolbar item. You can provide comprehensive text explanations to help users understand the operation they are about to perform and its potential consequences, especially when these cannot be inferred from the component's attributes and accessibility text alone. If a component contains both text information and the accessible description, the text is announced first and then the accessible description, when the component is selected.<br>Default value: **"Double-tap to activate"**             |
| accessibilityLevel  | string                                          | No | @Trace | Accessibility level of the toolbar item. It determines whether the component can be recognized by accessibility services.<br><br>The options are as follows:<br>**"auto"**: It is treated as "yes" by the system.<br>**"yes"**: The component can be recognized by accessibility services.<br>**"no"**: The component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the component nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**<br>|

### constructor

constructor(options: ToolBarV2ItemOptions)

A constructor used to create a **ToolBarV2Item** instance.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                           | Mandatory| Description      |
| :------ |:----------------------------------------------| :- | :------- |
| options | [ToolBarV2ItemOptions](#toolbarv2itemoptions) | Yes | Configuration options of the toolbar item.|

## ToolBarV2ItemOptions

Defines the options for initializing a **ToolBarV2Item** object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                      | Type                                             | Mandatory| Description                                                                                                                                                                                                            |
|:-------------------------| :---------------------------------------------- | :- |:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| content                  | [ToolBarV2ItemText](#toolbarv2itemtext)         | Yes | Text of the toolbar item.                                                                                                                                                                                                     |
| action                   | [ToolBarV2ItemAction](#toolbarv2itemaction)     | No | Click event of the toolbar item.<br>By default, there is no click event.                                                                                                                                                                                      |
| icon                     | [ToolBarV2ItemIconType](#toolbarv2itemicontype) | No | Icon of the toolbar item.<br>By default, there is no icon.                                                                                                                                                                                       |
| state                    | [ToolBarV2ItemState](#toolbarv2itemstate)       | No | State of the toolbar item.<br>Default value: **ENABLE**                                                                                                                                                                               |
| accessibilityText        | [ResourceStr](ts-types.md#resourcestr)          | No | Accessibility text, that is, accessible label name, of the toolbar item. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>Default value: value of **content**                                    |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr)          | No | Accessible description of the toolbar item. You can provide comprehensive text explanations to help users understand the operation they are about to perform and its potential consequences, especially when these cannot be inferred from the component's attributes and accessibility text alone. If a component contains both text information and the accessible description, the text is announced first and then the accessible description, when the component is selected.<br>Default value: **"Double-tap to activate"**                  |
| accessibilityLevel       | string                                          | No | Accessibility level of the toolbar item. It determines whether the component can be recognized by accessibility services.<br>The options are as follows:<br>**"auto"**: It is treated as "yes" by the system.<br>**"yes"**: The component can be recognized by accessibility services.<br>**"no"**: The component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the component nor its child components can be recognized by accessibility services.<br>Default value: **"auto"** |

## ToolBarV2ItemAction

type ToolBarV2ItemAction = (index: number) => void

Defines the callback for the click event of a toolbar item.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type    | Mandatory| Description|
|:------|:-------|:---|----|
| index | number | Yes |Index of the toolbar item that triggers the click event.<br>     |

## ToolBarV2ItemText

Defines the text of a toolbar item.

**Decorator type**: @ObservedV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

| Name                 | Type                                                         | Mandatory| Decorator | Description                                                      |
|:--------------------|:------------------------------------------------------------| :- | :----- |:---------------------------------------------------------|
| text                | [ResourceStr](ts-types.md#resourcestr)                      | Yes | @Trace | Text of the toolbar item.                                               |
| color               | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | @Trace | Font color of the toolbar item.<br>Default value: **$r('sys.color.font_primary')**      |
| activatedColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | @Trace | Font color of the toolbar item in the activated state.<br>Default value: **$r('sys.color.font_emphasize')** |

### constructor

constructor(options: ToolBarV2ItemTextOptions)

A constructor used to create a **ToolBarV2ItemText** instance.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                                   | Mandatory| Description        |
| :------ |:------------------------------------------------------| :- | :--------- |
| options | [ToolBarV2ItemTextOptions](#toolbarv2itemtextoptions) | Yes | Configuration options of the text content.|

## ToolBarV2ItemTextOptions

Defines the options for initializing a **ToolBarV2ItemText** object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                 | Type                                                         | Mandatory| Description                                                      |
| :------------------ |:------------------------------------------------------------| :- |:---------------------------------------------------------|
| text                | [ResourceStr](ts-types.md#resourcestr)                      | Yes | Text of the toolbar item.                                               |
| color          | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Font color of the toolbar item.<br>Default value: **$r('sys.color.font_primary')**      |
| activatedColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Font color of the toolbar item in the activated state.<br>Default value: **$r('sys.color.font_emphasize')**|

## ToolBarV2ItemImage

Defines the icon content of a toolbar item.

**Decorator type**: @ObservedV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

| Name                | Type                                                         | Mandatory| Decorator | Description                                                      |
|:-------------------|:------------------------------------------------------------| :- | :----- |:---------------------------------------------------------|
| src                | [ResourceStr](ts-types.md#resourcestr)                      | Yes | @Trace | Resource path of the icon.                                               |
| color              | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | @Trace | Color of the icon.<br>Default value: **$r('sys.color.icon_primary')**      |
| activatedColor     | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | @Trace | Color of the icon when the toolbar item is activated.<br>Default value: **$r('sys.color.icon_emphasize')**|

### constructor

constructor(options: ToolBarV2ItemImageOptions)

A constructor used to create a **ToolBarV2ItemImage** instance.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                                   | Mandatory| Description        |
| :------ | :------------------------------------------------------ | :- | :--------- |
| options | [ToolBarV2ItemImageOptions](#toolbarv2itemimageoptions) | Yes | Configuration options for the icon content of the toolbar item.|

## ToolBarV2ItemImageOptions

Defines the options for initializing a **ToolBarV2ItemImage** object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                 | Type                                                         | Mandatory| Description                                                      |
|:--------------------|:------------------------------------------------------------| :- |:---------------------------------------------------------|
| src                 | [ResourceStr](ts-types.md#resourcestr)                      | Yes | Resource path of the icon.                                               |
| color               | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Color of the icon.<br>Default value: **$r('sys.color.icon_primary')**      |
| activatedColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Color of the icon when the toolbar item is activated.<br>Default value: **$r('sys.color.icon_emphasize')**|

## ToolBarV2ItemIconType

type ToolBarV2ItemIconType = ToolBarV2ItemImage | ToolBarV2SymbolGlyph

Defines the union type for the icon content of a toolbar item.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                  | Description           |
| :------------------- | :------------ |
| ToolBarV2ItemImage   | Type for defining a common icon.    |
| ToolBarV2SymbolGlyph | Type for defining a symbol icon.|

## ToolBarV2Modifier

Provides APIs for setting the height (**height**), background color (**backgroundColor**), left and right padding (**padding**, which only takes effect when there are fewer than five items) of the toolbar, and whether to display the pressed state effect (**stateEffect**).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### backgroundColor

backgroundColor(backgroundColor: ColorMetrics): ToolBarV2Modifier

Sets the background color of the toolbar. By overriding this API, you can implement custom drawing for the background color of the toolbar.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name            | Type                                                         | Mandatory| Description                                                               |
| --------------- |-------------------------------------------------------------| -- | ----------------------------------------------------------------- |
| backgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | Yes | Toolbar background color<br>Default value: **\$r('sys.color.ohos\_id\_color\_toolbar\_bg')**|
**Return value**

| Type                                     | Description                                     |
|-----------------------------------------|-----------------------------------------|
| [ToolBarV2Modifier](#toolbarv2modifier) | **ToolBarV2Modifier** object after the background color is set.|

### padding

padding(padding: LengthMetrics): ToolBarV2Modifier

Sets the left and right padding of the toolbar. By overriding this API, you can implement custom drawing for the left and right padding of the toolbar.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                                           | Mandatory| Description                                                                 |
| ------- |---------------------------------------------------------------| -- | ------------------------------------------------------------------- |
| padding | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | Yes | Left and right padding of the toolbar, which is effective only when there are fewer than five items.<br><br>By default, the padding is 24 vp when there are fewer than five items and 0 when there are five or more items.|

**Return value**

| Type                                     | Description                             |
|-----------------------------------------|---------------------------------|
| [ToolBarV2Modifier](#toolbarv2modifier) | **ToolBarV2Modifier** object after the padding is set.|
### height

height(height: LengthMetrics): ToolBarV2Modifier

Sets the height of the toolbar. By overriding this API, you can implement custom drawing for the height of the toolbar, which does not include the height of the divider.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                                                | Mandatory| Description                               |
| ------ | ------------------------------------------------------------------ | -- | --------------------------------- |
| height | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | Yes | Height of the toolbar.<br>The default height of the toolbar is 56 vp, which does not include the divider.|

**Return value**

| Type                                     | Description                            |
|-----------------------------------------|--------------------------------|
| [ToolBarV2Modifier](#toolbarv2modifier) | **ToolBarV2Modifier** object after the height is set.|

### stateEffect

stateEffect(stateEffect: boolean): ToolBarV2Modifier

Sets whether to display the pressed state effect.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name        | Type     | Mandatory| Description                                                    |
| ----------- | ------- | -- |--------------------------------------------------------|
| stateEffect | boolean | Yes | Whether to display the pressed state effect on the toolbar.<br>**true**: Display the pressed state effect.<br>**false**: Do not display the pressed state effect.<br> Default value: **true**|

**Return value**

| Type                                     | Description                                 |
|-----------------------------------------|-------------------------------------|
| [ToolBarV2Modifier](#toolbarv2modifier) | **ToolBarV2Modifier** object after the pressed state effect is set.|

## ToolBarV2ItemState

Enumerates the states of the toolbar item.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Value| Description             |
| -------- | - | --------------- |
| ENABLE   | 1 | The toolbar item is enabled. |
| DISABLE  | 2 | The toolbar item is disabled.  |
| ACTIVATE | 3 | The toolbar item is activated.|

## ToolBarV2SymbolGlyph

Defines the configuration options of the symbol icon.

**Decorator type**: @ObservedV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

| Name       | Type                                                                  | Mandatory| Decorator | Description                                                                                  |
| :-------- | :------------------------------------------------------------------- | :- | :----- | :----------------------------------------------------------------------------------- |
| normal    | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | Yes | @Trace | Icon symbol of the toolbar item in normal state.  |
| activated | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | No | @Trace | Icon symbol of the toolbar item in activated state.<br>Default value:<br>**fontColor**: **\$r('sys.color.icon\_emphasize')**, **fontSize**: **24vp**|

### constructor

constructor(options: ToolBarV2SymbolGlyphOptions)

A constructor used to create a **ToolBarV2SymbolGlyph** object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                                       | Mandatory| Description         |
| :------ | :---------------------------------------------------------- | :- | :---------- |
| options | [ToolBarV2SymbolGlyphOptions](#toolbarv2symbolglyphoptions) | Yes | Configuration options of the symbol icon.|

## ToolBarV2SymbolGlyphOptions

Defines the options for initializing a **ToolBarV2SymbolGlyph** object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type                                                                  | Mandatory| Description                                                                                  |
| --------- | -------------------------------------------------------------------- | -- | ------------------------------------------------------------------------------------ |
| normal    | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | Yes | Icon symbol of the toolbar item in normal state.  |
| activated | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | No | Icon symbol of the toolbar item in activated state.<br>Default value:<br>**fontColor**: **\$r('sys.color.icon\_emphasize')**, **fontSize**: **24vp**|

## Example

### Example 1: Setting Toolbar Items to Different States

This example shows the various display effects when the **state** property of toolbar items is set to **ENABLE**, **DISABLE**, or **ACTIVATE**.

```ts
import { ToolBarV2ItemImage, ToolBarV2ItemState, ToolBarV2ItemText, ToolBarV2Item, ToolBarV2 } from '@kit.ArkUI'

@Entry
@ComponentV2
struct Index {
  @Local toolbarList: ToolBarV2Item[] = []

  aboutToAppear() {
    this.toolbarList.push(new ToolBarV2Item({
      content: new ToolBarV2ItemText(
        {
          text: 'Cut Super Long Text'
        }
      ),
      icon: new ToolBarV2ItemImage({
        src: $r('sys.media.ohos_ic_public_share')
      }),
      action: () => {
      },
    }))
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText(
          {
            text: 'Copy'
          }
        ),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_copy')
        }),
        action: () => {
        },
        state: ToolBarV2ItemState.DISABLE
      })
    )
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText(
          {
            text: 'Paste'
          }
        ),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_paste')
        }),
        action: () => {
        },
        state: ToolBarV2ItemState.ACTIVATE
      })
    )
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText(
          {
            text:'Select All'
          }
        ),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_select_all')
        }),
        action: () => {
        },
      })
    )
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText(
          {
            text: 'Share'
          }
        ),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_share')
        }),
        action: () => {
        },
      })
    )
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText(
          {
            text: 'Share'
          }
        ),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_share')
        }),
        action: () => {
        },
      })
    )
  }

  build() {
    Row() {
      Stack() {
        Column() {
          ToolBarV2({
            activatedIndex: 2,
            toolBarList: this.toolbarList,
          })
        }
      }.align(Alignment.Bottom)
      .width('100%').height('100%')
    }
  }
}
```

![en-us\_image\_toolbar\_example01](figures/en-us_image_toolbar_example01.png)

### Example 2: Customizing the Toolbar Style

This example demonstrates how to customize the toolbar's height, background color, and other styles using **ToolBarV2Modifier**.

```ts
import {
  SymbolGlyphModifier,
  DividerModifier,
  LengthMetrics,
  ColorMetrics,
  ToolBarV2Item,
  ToolBarV2Modifier,
  ToolBarV2ItemText,
  ToolBarV2ItemImage,
  ToolBarV2,
  ToolBarV2ItemState,
  ToolBarV2SymbolGlyph
} from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local toolbarList: ToolBarV2Item[] = [];
  private toolBarModifier: ToolBarV2Modifier =
    new ToolBarV2Modifier().height(LengthMetrics.vp(52))
      .backgroundColor(ColorMetrics.resourceColor(Color.Transparent))
      .stateEffect(false);
  @Local dividerModifier: DividerModifier = new DividerModifier().height(0);

  aboutToAppear() {
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Long long long long long long long long text',
          activatedColor: ColorMetrics.resourceColor($r('sys.color.font_primary'))
        }),
        icon: new ToolBarV2SymbolGlyph({
          normal: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Green]),
          activated: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Red]),
        }),
        action: () => {
        },
        state: ToolBarV2ItemState.ACTIVATE,
      })
    )
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Copy',
          activatedColor: ColorMetrics.resourceColor('#ffec5d5d')
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_copy'),
          color: ColorMetrics.resourceColor('#ff18cb53'),
          activatedColor: ColorMetrics.resourceColor('#ffec5d5d'),
        }),
        action: () => {
        },
        state: ToolBarV2ItemState.DISABLE,
      }))
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Paste',
          color: ColorMetrics.resourceColor('#ff18cb53')
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_paste'),
        }),
        action: () => {
        },
        state: ToolBarV2ItemState.ACTIVATE,
      })
    )
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'All',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_select_all'),
        }),
        action: () => {
        },
        state: ToolBarV2ItemState.ACTIVATE,
      }))
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Share',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_share'),
        }),
        action: () => {
        },
      }))
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Share',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_share'),
        }),
        action: () => {
        },
      })
    )
  }

  build() {
    Row() {
      Stack() {
        Column() {
          ToolBarV2({
            toolBarModifier: this.toolBarModifier,
            dividerModifier: this.dividerModifier,
            activatedIndex: 0,
            toolBarList: this.toolbarList,
          })
            .height(52)
        }
      }.align(Alignment.Bottom)
      .width('100%').height('100%')
    }
  }
}
```

![en-us\_image\_toolbar\_example02](figures/en-us_image_toolbar_example02.png)

### Example 3: Implementing Screen Reader Announcement

This example customizes the screen reader announcement text by setting the **accessibilityText**, **accessibilityDescription**, and **accessibilityLevel** properties of the toolbar item.

```ts
import {
  DividerModifier,
  LengthMetrics,
  ColorMetrics,
  ToolBarV2Item,
  ToolBarV2Modifier,
  ToolBarV2ItemText,
  ToolBarV2ItemImage,
  ToolBarV2,
  ToolBarV2ItemState,
} from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local toolbarList: ToolBarV2Item[] = [];
  private toolBarModifier: ToolBarV2Modifier =
    new ToolBarV2Modifier().height(LengthMetrics.vp(52))
      .backgroundColor(ColorMetrics.resourceColor(Color.Transparent))
      .stateEffect(false);
  @Local dividerModifier: DividerModifier = new DividerModifier().height(0);

  aboutToAppear() {
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Cut Super Long Text',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_share')
        }),
        action: () => {
        },
        accessibilityText: 'Clip', // Screen reader announcement for the item.
        accessibilityDescription: 'Double-tap to clip', // Screen reader announcement for the item.
        accessibilityLevel: 'yes'  // Configure this element to be focused by screen readers.
      })
    )
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Copy',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_copy'),
        }),
        action: () => {
        },
        state: ToolBarV2ItemState.DISABLE,
        accessibilityLevel: 'no'  // Configure this button to be not recognizable by screen readers.
      }))
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Paste',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_paste'),
        }),
        action: () => {
        },
        state: ToolBarV2ItemState.ACTIVATE,
      })
    )
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Select All',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_select_all'),
        }),
        action: () => {
        },
      }))
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Share',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_share'),
        }),
        action: () => {
        },
      }))
    this.toolbarList.push(
      new ToolBarV2Item({
        content: new ToolBarV2ItemText({
          text: 'Share',
        }),
        icon: new ToolBarV2ItemImage({
          src: $r('sys.media.ohos_ic_public_share'),
        }),
        action: () => {
        },
      })
    )
  }

  build() {
    Row() {
      Stack() {
        Column() {
          ToolBarV2({
            toolBarModifier: this.toolBarModifier,
            dividerModifier: this.dividerModifier,
            activatedIndex: 0,
            toolBarList: this.toolbarList,
          })
            .height(52)
        }
      }.align(Alignment.Bottom)
      .width('100%').height('100%')
    }
  }
}
```

![en-us\_image\_toolbar\_example01](figures/en-us_image_toolbar_example01.png)
