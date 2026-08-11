# ChipGroupV2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @song-song-song-->
<!--Designer: @fenglinbailu-->
<!--Tester: @weixin_45530366-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=b4797ff84520f34081469c8824bbfa37af31b0f1 translatedAt=2026-07-17T10:00:19.510Z pushedAt=2026-07-21T01:04:58.044Z -->

The **ChipGroupV2** component provides a chip group container that supports single or multiple selection, custom styles and spacing, and custom suffix content. It is suitable for scenarios such as file or resource content categorization, tag selection, and filtering, helping you quickly build visually appealing and interactive chip group UIs.

This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), state management V2 delivers enhanced capabilities for deep observation and management of data objects, and is no longer limited to the component level. With state management V2, you can control component data and state more flexibly, achieving more efficient UI refresh.

> **NOTE**
>
> The APIs of this module can be used only in the stage model.
>

**Since:** 26.0.0

## Modules to Import

```ts
import { ChipV2Size, ChipGroupV2 } from '@kit.ArkUI';
```

## Child Components

None

## ChipGroupV2

```ts
ChipGroupV2({
  items: ChipGroupV2Items,
  $items?: Callback<ChipGroupV2Items>,
  itemStyle?: ChipGroupV2ItemStyle,
  selectedIndexes?: Array<number>,
  $selectedIndexes?: Callback<Array<number>>,
  multiple?: boolean,
  chipGroupSpace?: ChipGroupV2Space,
  chipGroupPadding?: ChipGroupV2Padding,
  onChange?: Callback<Array<number>>,
  suffix?: Callback<void>
})
```

**Since:** 26.0.0

**Decorator:** @ComponentV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name            | Type                                            | Mandatory | Decorator Type | Description                                                                                     |
| --------------- | ----------------------------------------------- | ---- | ---------- | ------------------------------------------------------------ |
| items           | [ChipGroupV2Items](#chipgroupv2items) | Yes   | @Require<br>@Param | Specific attributes of a **ChipV2**. For details, see [ChipGroupV2ItemConfig](#chipgroupv2itemconfig).<br>When the value is **undefined** or an empty array, **ChipGroupV2** does not render the internal [ChipV2](ohos-arkui-advanced-ChipV2.md). |
| $items           | [Callback](ts-types.md#callback12)<[ChipGroupV2Items](#chipgroupv2items)> | No   | @Event | Bidirectional binding callback for the **ChipV2** item. Pass in this callback when you need to listen for or modify the **ChipV2** item list.<br>Default value: **undefined**, meaning no callback is triggered. |
| itemStyle       | [ChipGroupV2ItemStyle](#chipgroupv2itemstyle)                 | No   | @Param | Style of **ChipV2**, such as color and size. For details, see [ChipGroupV2ItemStyle](#chipgroupv2itemstyle).<br>Default value:<br>**{ size: ChipV2Size.NORMAL, backgroundColor: $r('sys.color.ohos_id_color_button_normal'), fontColor: $r('sys.color.ohos_id_color_text_primary'), selectedFontColor: $r('sys.color.ohos_id_color_text_primary_contrary'), selectedBackgroundColor: $r('sys.color.ohos_id_color_emphasize') }**<br>When the value is **undefined**, the default value is used.<br>The icon fill colors ([fillColor](./ohos-arkui-advanced-ChipV2.md#chipv2imageiconconfig) and [activatedFillColor](./ohos-arkui-advanced-ChipV2.md#chipv2imageiconconfig)) are consistent with the corresponding font colors: in the unselected state, **fillColor** is consistent with [fontColor](#chipgroupv2itemstyleconfig); in the selected state, **activatedFillColor** is consistent with [selectedFontColor](#chipgroupv2itemstyleconfig). To set different colors, use [prefixSymbolIcon](#chipgroupv2itemconfig) and [suffixSymbolIcon](#chipgroupv2itemconfig) when passing in **items**. |
| selectedIndexes | Array&lt;number&gt;            | No   | @Param | Indexes of the selected **ChipV2** items.<br>Value range: the index value must be an integer greater than or equal to 0 and less than the length of the items array. Indexes outside this range do not take effect.<br>Default value: **[0]**<br>When the value is **undefined**, the default value is used.<br>When **multiple** is **false**, if **selectedIndexes** is not passed in, the first **ChipV2** is selected by default; if the passed in **selectedIndexes** has multiple elements, the **ChipV2** of the first index is selected by default.<br>When **multiple** is **true**, if **selectedIndexes** is not passed in, the first **ChipV2** is selected by default; if the passed in **selectedIndexes** has multiple elements, all **ChipV2** items of the corresponding indexes are selected.  |
| $selectedIndexes | [Callback](ts-types.md#callback12)&lt;Array&lt;number&gt;&gt;                             |No   | @Event | Bidirectional binding callback for the selected **ChipV2** indexes. Pass in this callback when you need to listen for or modify the selected **ChipV2** indexes.<br>Default value: **undefined**, meaning no callback is triggered.  |
| multiple        | boolean                                         | No   | @Param | Whether to select multiple **ChipV2** items.<br>**true**: multiple **ChipV2** items can be selected; **false**: only a single **ChipV2** can be selected.<br>Default value: **false**<br>When the value is **undefined**, the default value is used. |
| chipGroupSpace  | [ChipGroupV2Space](#chipgroupv2space) | No   | @Param | Left and right padding and spacing between ChipV2 items. After setting, you can adjust the left and right padding of **ChipGroupV2** and the spacing between **ChipV2** items. Increasing the spacing makes the layout looser, while decreasing it makes the layout more compact. For details, see [ChipGroupV2Space](#chipgroupv2space).<br>Default value: **{ itemSpace: 8, startSpace: 16, endSpace: 16 }**<br>Unit: vp<br>When the value is **undefined**, the default value is used. |
| chipGroupPadding  | [ChipGroupV2Padding](#chipgroupv2padding) | No   | @Param | Top and bottom padding of **ChipGroupV2**, used to control the overall height. The type is [ChipGroupV2Padding](#chipgroupv2padding).<br>Default value: **{ top: 14, bottom: 14 }**<br>Unit: vp<br>When the value is **undefined**, the default value is used. |
| onChange        | [Callback](ts-types.md#callback12)\<Array\<number>>  | No   | @Event  | Callback invoked when the **ChipV2** state changes, used to respond to changes in the **ChipV2** selection state. Pass in this callback when you need to listen for **ChipV2** selection state changes.<br>Trigger scenario: triggered when the user taps a **ChipV2** to change its selection state, returning the array of indexes of the currently selected **ChipV2** items.<br>Default value: **undefined**, meaning no event is triggered.                                                              |
| suffix          | [Callback](ts-types.md#callback12)\<void\>                                        | No   | @BuilderParam | Custom builder. To display custom content on the far right of the component, configure the **suffix** attribute. When using the **suffix** attribute, reference the [ChipGroupV2IconGroupSuffix](#chipgroupv2icongroupsuffix) API.<br>Default value: **undefined**, meaning no custom content is displayed on the far right. |

### build

build(): void

Constructs an advanced **ChipGroupV2** component.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

## ChipGroupV2Item

Defines a single chip item in the **ChipGroupV2** component.

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearable devices, the app runs abnormally with an error message indicating that the API is undefined. This API is supported on other device types.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearable devices, this API causes the app to run abnormally with an error message indicating that the API is undefined. On other device types, it can be called normally.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| prefixIcon | [ChipV2PrefixImageIcon](ohos-arkui-advanced-ChipV2.md#chipv2prefiximageicon) | No | Yes | Prefix icon, used to display an image icon before the **ChipV2** text. Set this attribute when an icon identifier needs to be displayed on the left side of the **ChipV2**.<br>Default value: no prefix image icon.<br>When the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| prefixSymbolIcon | [ChipV2PrefixSymbolIcon](ohos-arkui-advanced-ChipV2.md#chipv2prefixsymbolicon) | No | Yes | Prefix symbol icon, used to display a symbol icon before the **ChipV2** text. Set this attribute when a symbol icon identifier needs to be displayed on the left side of the **ChipV2**.<br>Default value: no prefix symbol icon.<br>When the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| label | [ChipV2Label](ohos-arkui-advanced-ChipV2.md#chipv2label) | No | No | **ChipV2** text.<br>Decorator: **@Trace** |
| suffixIcon | [ChipV2SuffixImageIcon](ohos-arkui-advanced-ChipV2.md#chipv2suffiximageicon) | No | Yes | Suffix icon, used to display an image icon after the **ChipV2** text. When this attribute is set, the **allowClose** attribute does not take effect.<br>Default value: no suffix image icon displayed.<br>When the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| suffixSymbolIcon | [ChipV2SuffixSymbolIcon](ohos-arkui-advanced-ChipV2.md#chipv2suffixsymbolicon) | No | Yes | Suffix symbol icon, used to display a symbol icon after the **ChipV2** text. When this attribute is set, the **allowClose** attribute does not take effect.<br>Default value: no suffix symbol icon displayed.<br>When the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| allowClose | boolean | No | Yes | Whether to display the close icon. The value **true** means the close icon is displayed, and **false** means the opposite. When **suffixIcon** or **suffixSymbolIcon** is passed in, **allowClose** does not take effect. When neither **suffixIcon** nor **suffixSymbolIcon** is passed in, **allowClose** determines whether the close icon is displayed.<br>Default value: **false**<br>When the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| closeIcon | [ChipV2CloseConfig](ohos-arkui-advanced-ChipV2.md#chipv2closeconfig) | No | Yes | Configuration of the close icon, including accessibility attribute configuration. Set this attribute when you need to customize the size or accessibility attributes of the close icon.<br>Default value:<br>- **fontSize**: when **size** is **ChipV2Size.SMALL**, the default value is `$r('sys.float.chip_small_font_size')`; in other cases, the default value is `$r('sys.float.chip_normal_font_size')`.<br>- Accessibility: no accessibility description.<br>When the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description. This attribute is used to explain the component to users in detail. You should provide a thorough text description for this attribute to help users understand the operation and its possible results, especially when these results cannot be directly inferred from the component's attributes and accessibility text alone. When a component has both a text attribute and an accessibility description attribute and it is selected, the system first reads out the component's text attribute, followed by the content of the accessibility description attribute.<br>Default value: empty string.<br>When the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| accessibilityLevel | string | No | Yes | Accessibility level. This attribute is used to control whether the component can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: the attribute value of the component is converted to **"yes"**.<br>**"yes"**: the component can be recognized by accessibility services.<br>**"no"**: the component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: the component and all its child components cannot be recognized by accessibility services.<br>When a value outside the supported range is passed in, the default value is used.<br>Default value: **"auto"**<br>When the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |

> **NOTE**
>
> 1. If you need to support the close function while displaying a suffix icon (**suffixIcon** or **suffixSymbolIcon**), it is recommended to implement the deletion logic in the click event of **suffixIcon** or **suffixSymbolIcon**, or use other interaction methods as alternatives.

### constructor

constructor(config: ChipGroupV2ItemConfig)

A constructor used to create a **ChipGroupV2Item** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipGroupV2ItemConfig](#chipgroupv2itemconfig) | Yes | Configuration of the **ChipGroupV2** item. |

## ChipGroupV2ItemConfig

Defines the non-common attribute configuration of a **ChipV2**.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name         | Type                           | Read-only | Optional | Description                              |
| ---------- | ----------------------------- | ---- | ----------------------------------- | ----------------------------------- |
| prefixIcon   | [ChipV2PrefixImageIconConfig](ohos-arkui-advanced-ChipV2.md#chipv2prefiximageiconconfig)   | No  | Yes  | Prefix image icon, which is used to display an image icon before the **ChipV2** text. Set this attribute when an icon identifier needs to be displayed on the left side of **ChipV2**.<br>Default value: no prefix image icon.<br>If the value is **undefined**, the default value is used. |
| prefixSymbolIcon | [ChipV2PrefixSymbolIconConfig](ohos-arkui-advanced-ChipV2.md#chipv2prefixsymboliconconfig) | No  | Yes  | Prefix symbol icon, which is used to display a symbol icon before the **ChipV2** text. Set this attribute when a symbol icon identifier needs to be displayed on the left side of **ChipV2**.<br>Default value: no prefix symbol icon.<br>If the value is **undefined**, the default value is used. |
| label        | [ChipV2LabelConfig](ohos-arkui-advanced-ChipV2.md#chipv2labelconfig) | No  | No  | Text attribute.                            |
| suffixIcon   | [ChipV2SuffixImageIconConfig](ohos-arkui-advanced-ChipV2.md#chipv2suffiximageiconconfig) | No | Yes | Suffix image icon, which is used to display an image icon after the **ChipV2** text. When this attribute is set, the **allowClose** attribute does not take effect.<br>Default value: no suffix image icon is displayed.<br>If the value is **undefined**, the default value is used. |
| suffixSymbolIcon | [ChipV2SuffixSymbolIconConfig](ohos-arkui-advanced-ChipV2.md#chipv2suffixsymboliconconfig) | No | Yes | Suffix symbol icon, which is used to display a symbol icon after the **ChipV2** text. When this attribute is set, the **allowClose** attribute does not take effect.<br>Default value: no suffix symbol icon is displayed.<br>If the value is **undefined**, the default value is used. |
| allowClose   | boolean                       | No  | Yes  | Whether to display the close icon. Value rules: **true** means to display the close icon, and **false** means the opposite.<br>When **suffixIcon** or **suffixSymbolIcon** is passed in, **allowClose** does not take effect. When neither **suffixIcon** nor **suffixSymbolIcon** is passed in, **allowClose** determines whether the close icon is displayed.<br>Default value: **false**<br>If the value is **undefined**, the default value is used. |
| closeIcon | [ChipV2CloseConfig](ohos-arkui-advanced-ChipV2.md#chipv2closeconfig) | No | Yes | Configuration of the close icon, including accessibility attribute configuration. Set this attribute when you need to customize the size or accessibility attributes of the close icon.<br>Default value:<br>- **fontSize**: when **size** is **ChipV2Size.SMALL**, the default value is `$r('sys.float.chip_small_font_size')`; in other cases, the default value is `$r('sys.float.chip_normal_font_size')`.<br>- Accessibility: no accessibility description.<br>If the value is **undefined**, the default value is used. |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the **ChipV2** item in **ChipGroupV2**. This description is used to explain the **ChipV2** item in **ChipGroupV2** to users in detail. You should provide a relatively detailed text description for the attributes of the **ChipV2** item in **ChipGroupV2** to help users understand the operation to be performed and its possible results, especially when these results cannot be directly learned from the attributes and accessibility text of the **ChipV2** item in **ChipGroupV2** alone. If the **ChipV2** item in **ChipGroupV2** has both a text attribute and an accessibility description attribute and the item is selected, the system first announces the item's text attribute, and then announces the content of the accessibility description attribute.<br>Default value: empty string.<br>If the value is **undefined**, the default value is used. |
| accessibilityLevel | string | No | Yes | Accessibility level of the **ChipV2** item in **ChipGroupV2**. This attribute is used to control whether the **ChipV2** item in **ChipGroupV2** can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: The attribute value of the **ChipV2** item in **ChipGroupV2** is converted to **"yes"**.<br>**"yes"**: The **ChipV2** item in **ChipGroupV2** can be recognized by accessibility services.<br>"no": The **ChipV2** item in **ChipGroupV2** cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: The **ChipV2** item in **ChipGroupV2** and all its child components cannot be recognized by accessibility services.<br>If a value outside the supported range is passed in, the default value is used.<br>Default value: **"auto"**<br>If the value is **undefined**, the default value is used. |

## ChipGroupV2Items

Defines the array class of the **ChipGroupV2** item, which inherits from Array<[ChipGroupV2Item](#chipgroupv2item)>.

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### constructor

constructor(items: ChipGroupV2ItemConfig[])

A constructor used to create a **ChipGroupV2Items** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| items | [ChipGroupV2ItemConfig](#chipgroupv2itemconfig)[] | Yes | Array of **ChipGroupV2** item configurations. |

## ChipGroupV2ItemStyle

Defines the common attribute class of **ChipV2**.

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| size | [ChipV2Size](ohos-arkui-advanced-ChipV2.md#chipv2size) \| [SizeT](../js-apis-arkui-graphics.md#sizett12)<[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)> | No | Yes | Size of **ChipV2**.<br>Default value: **ChipV2Size.NORMAL**<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| backgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Background color of **ChipV2**.<br>Default value: **$r('sys.color.ohos_id_color_button_normal')**<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| fontColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Font color of **ChipV2**.<br>Default value: **$r('sys.color.ohos_id_color_text_primary')**<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| selectedFontColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Font color of **ChipV2** when selected. After this attribute is set, when the **ChipV2** is selected, the label text is displayed in this color, replacing the **fontColor** in the unselected state.<br>Default value: **$r('sys.color.ohos_id_color_text_primary_contrary')**<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| selectedBackgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Background color of **ChipV2** when selected. After this attribute is set, when the **ChipV2** is selected, the background is filled with this color, replacing the **backgroundColor** in the unselected state.<br>Default value: **$r('sys.color.ohos_id_color_emphasize')**<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| backgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | Yes | System material style of the component. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, no material style is applied.<br>Decorator: **@Trace** |
| selectedBackgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | Yes | System material style of the component in the selected state. After this attribute is set, when the **ChipV2** is selected, this material style is applied, replacing the **backgroundSystemMaterial** in the unselected state. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, no material style is applied.<br>Decorator: **@Trace** |

### constructor

constructor(config: ChipGroupV2ItemStyleConfig)

A constructor used to create a **ChipGroupV2ItemStyle** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipGroupV2ItemStyleConfig](#chipgroupv2itemstyleconfig) | Yes | Style configuration of the **ChipGroupV2** item. |

## ChipGroupV2ItemStyleConfig

Defines the common attribute configuration of **ChipV2**.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name                    | Type                                                         | Read-only | Optional | Description                                                         |
| ----------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| size                    | [ChipV2Size](ohos-arkui-advanced-ChipV2.md#chipv2size) \| [SizeT](../js-apis-arkui-graphics.md#sizett12)<[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)> | No   | Yes   | Size of **ChipV2**. When using this attribute, import the **ChipV2Size** type from the **ChipV2** component.<br>Default value: **ChipV2Size.NORMAL**<br>If the value is **undefined**, the default value is used. |
| backgroundColor         | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)                   | No   | Yes   | Background color of **ChipV2**.<br>Default value: **$r('sys.color.ohos_id_color_button_normal')**<br>If the value is **undefined**, the default value is used. |
| fontColor               | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)                   | No   | Yes   | Font color of **ChipV2**.<br>Default value: **$r('sys.color.ohos_id_color_text_primary')**<br>If the value is **undefined**, the default value is used. |
| selectedFontColor       | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)                   | No   | Yes   | Font color of **ChipV2** when selected. After this attribute is set, when the **ChipV2** is selected, the label text is displayed in this color, replacing the **fontColor** in the unselected state.<br>Default value: **$r('sys.color.ohos_id_color_text_primary_contrary')**<br>If the value is **undefined**, the default value is used. |
| selectedBackgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)                   | No   | Yes   | Background color of **ChipV2** when selected. After this attribute is set, when the **ChipV2** is selected, the background is filled with this color, replacing the **backgroundColor** in the unselected state.<br>Default value: **$r('sys.color.ohos_id_color_emphasize')**<br>If the value is **undefined**, the default value is used. |
| backgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | Yes | System material style of the component. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, no material style is applied. |
| selectedBackgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | Yes | System material style of the component in the selected state. After this attribute is set, when the **ChipV2** is selected, this material style is applied, replacing the **backgroundSystemMaterial** in the unselected state. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, no material style is applied. |

## ChipGroupV2Space

Defines the left and right padding of **ChipGroupV2** and the spacing between **ChipV2** components.

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| itemSpace | string \| number | No | Yes | Spacing between **ChipV2** components (percentage not supported). Increasing the spacing makes adjacent **ChipV2** components more dispersed and the overall layout looser; decreasing the spacing makes **ChipV2** components more compact.<br>Value range:<br>- number type: [0, +∞), for example, 0, 8, 16, 24.5.<br>- string type: a string in fp \| vp \| px \| lpx units with a numeric value greater than or equal to 0, for example, "8vp", "16fp", "12px", "10lpx".<br>- Not supported: negative numbers, percentage units, invalid string formats.<br>If a value outside the valid range or in an unsupported format is passed, the default value is used.<br>Default value: **8**<br>Unit: vp<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| startSpace | [Length](ts-types.md#length) | No | Yes | Left padding (percentage not supported).<br>Default value: **16**<br>Unit: vp<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| endSpace | [Length](ts-types.md#length) | No | Yes | Right padding (percentage not supported).<br>Default value: **16**<br>Unit: vp<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |

### constructor

constructor(config: ChipGroupV2SpaceConfig)

A constructor used to create a **ChipGroupV2Space** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipGroupV2SpaceConfig](#chipgroupv2spaceconfig) | Yes | Spacing configuration of **ChipGroupV2**. |

## ChipGroupV2SpaceConfig

Defines the left and right padding of **ChipGroupV2** and the spacing configuration between **ChipV2** components.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name       | Type            | Read-only | Optional | Description                                             |
| ---------- | -------------- | ---- | ------------------------------------------------ | ------------------------------------------------ |
| itemSpace | string \| number  | No  | Yes  | Spacing between **ChipV2** components (percentage not supported).<br>Value range:<br>- number type: [0, +∞), for example, 0, 8, 16, 24.5.<br>- string type: a string in fp \| vp \| px \| lpx units with a numeric value greater than or equal to 0, for example, "8vp", "16fp", "12px", "10lpx".<br>- Not supported: negative numbers, percentage units, invalid string formats.<br>If a value outside the valid range or in an unsupported format is passed, the default value is used.<br>Default value: **8**<br>Unit: vp<br>If the value is undefined, the default value is used. |
| startSpace | [Length](ts-types.md#length)         | No  | Yes  | Left padding (percentage not supported).<br>Default value: **16**<br>Unit: vp<br>If the value is **undefined**, the default value is used.           |
| endSpace   | [Length](ts-types.md#length)         | No  | Yes  | Right padding (percentage not supported).<br>Default value: **16**<br>Unit: vp<br>If the value is **undefined**, the default value is used. |

## ChipGroupV2Padding

Defines the top and bottom padding of **ChipGroupV2**, which is used to control its overall height.

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| top | [Length](ts-types.md#length) | No | No | Top padding of **ChipGroupV2** (percentage not supported).<br>Default value: **14**<br>Unit: vp<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |
| bottom | [Length](ts-types.md#length) | No | No | Bottom padding of **ChipGroupV2** (percentage not supported).<br>Default value: **14**<br>Unit: vp<br>If the value is **undefined**, the default value is used.<br>Decorator: **@Trace** |

### constructor

constructor(config: ChipGroupV2PaddingConfig)

A constructor used to create a **ChipGroupV2Padding** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipGroupV2PaddingConfig](#chipgroupv2paddingconfig) | Yes | Padding configuration of **ChipGroupV2**. |

## ChipGroupV2PaddingConfig

Defines the top and bottom padding configuration of **ChipGroupV2**, which is used to control its overall height.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name   | Type            | Read-only | Optional | Description                                                      |
| ------ | -------------- | ---- | ------------------------------------------------ | ------------------------------------------------ |
| top    | [Length](ts-types.md#length)         | No  | No  | Top padding of **ChipGroupV2** (percentage not supported).<br>Default value: **14**<br>Unit: vp<br>If the value is **undefined**, the default value is used. |
| bottom | [Length](ts-types.md#length)         | No  | No  | Bottom padding of **ChipGroupV2** (percentage not supported).<br>Default value: **14**<br>Unit: vp<br>If the value is **undefined**, the default value is used. |

## ChipGroupV2IconGroupSuffix

Display custom content on the far right of the **ChipGroupV2** component. It supports configuring image icons, symbol icons, symbol icon configuration items, and icon background material styles. It is suitable for scenarios where an additional operation entry needs to be added at the end of a chip group.

```typescript
ChipGroupV2IconGroupSuffix({
  items: Array<ChipGroupV2IconItemConfig | SymbolGlyphModifier | ChipGroupV2SymbolItemConfig>,
  iconBackgroundSystemMaterial?: uiMaterial.Material
})
```

**Since:** 26.0.0

**Decorator:** @ComponentV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name                        | Type                    | Mandatory | Decorator Type | Description                                                              |
| --------------------------- | ---------------------- | ---- | ---------------------------------------------- | ---------------------------------------------- |
| items                       | Array&lt;[ChipGroupV2IconItemConfig](#chipgroupv2iconitemconfig) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) \| [ChipGroupV2SymbolItemConfig](#chipgroupv2symbolitemconfig)&gt; | Yes   | @Require<br>@Param | Array of custom items displayed in the suffix area, supporting **ChipGroupV2IconItemConfig** (image icon), **SymbolGlyphModifier** (symbol icon), or **ChipGroupV2SymbolItemConfig** (symbol icon configuration) types.<br>When **SymbolGlyphModifier** is passed, using **symbolEffect** to modify the animation type and [effectStrategy](./ts-basic-components-symbolGlyph.md#effectstrategy) to set the animation is not supported.|
| iconBackgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | @Param | System material style of the component. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, meaning no material style is applied. |

### build

build(): void

Constructs a **ChipGroupV2IconGroupSuffix** component.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

## ChipGroupV2IconItemConfig

Defines the configuration of the suffix icon item, which is used to set the style, interaction, and accessibility attributes of the suffix icon.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name     | Type                            | Read-only | Optional | Description                                    |
| -------- | -------------- | ---- | ------------------------------ | ------------------------------ |
| icon     | [ChipV2ImageIconConfig](ohos-arkui-advanced-ChipV2.md#chipv2imageiconconfig)    | No  | No  | Custom suffix icon. After being set, the specified icon is displayed in the suffix area of the **ChipGroupV2**.<br>To dynamically change the icon size, you must use the [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) type when introducing [ChipGroupV2IconGroupSuffix](#chipgroupv2icongroupsuffix), and set the icon size attribute through the methods provided by this type. For example, dynamically adjusting the size value through the **fontSize** or **size** method. |
| action   | [Callback](ts-types.md#callback12)\<void>        | No  | No  | Response event of the custom suffix icon. |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text attribute of the suffix icon. It is used to further explain the suffix icon to users. You can set a relatively detailed explanatory text for this attribute of the suffix icon to help users understand the operation to be performed. For example, it helps users understand the possible consequences of the operation to be performed, especially when these consequences cannot be learned from the suffix icon's attributes and accessibility text. When the suffix icon has both a text attribute and an accessibility description attribute and the icon is selected, the text attribute of the icon is announced first, followed by the content of the accessibility description attribute.<br>Default value: empty string.<br>If the value is **undefined**, the default value is used. |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the suffix icon. This description is used to explain the suffix icon to users in detail. You should provide a relatively detailed text description for this attribute of the suffix icon to help users understand the operation to be performed and its possible consequences, especially when these consequences cannot be directly learned from the suffix icon's attributes and accessibility text. When the suffix icon has both a text attribute and an accessibility description attribute and the icon is selected, the system announces the text attribute of the icon first, followed by the content of the accessibility description attribute.<br>Default value: empty string.<br>If the value is **undefined**, the default value is used. |
| accessibilityLevel | string | No | Yes | Accessibility level of the suffix icon. It is used to control whether the suffix icon can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: The attribute value of the suffix icon is converted to **"yes"**.<br>**"yes"**: The suffix icon can be recognized by accessibility services.<br>**"no"**: The suffix icon cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: The suffix icon and all its child components cannot be recognized by accessibility services.<br>If a value outside the supported range is passed in, the default value is used.<br>Default value: **"auto"**<br>If the value is **undefined**, the default value is used. |

## ChipGroupV2SymbolItemConfig

Defines the configuration type of the suffix symbol icon.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| symbol | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | No | **SymbolGlyphModifier** configuration object for the suffix icon. After being set, the specified symbol icon is displayed in the suffix area of the **ChipGroupV2**, with support for configuring display style, rendering mode, color, and other attributes.<br>**Note:** When **SymbolGlyphModifier** is passed in, using **symbolEffect** to modify the animation type and [effectStrategy](./ts-basic-components-symbolGlyph.md#effectstrategy) to set the animation is not supported.|
| action | [VoidCallback](ts-types.md#voidcallback12) | No | No | Response event for the suffix icon.|
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text attribute of the suffix icon. It is used to provide further explanation of the trailing icon for users. You can set a relatively detailed description text for this attribute of the suffix icon to help users understand the operation to be performed. For example, it helps users understand the possible consequences of the operation to be performed, especially when these consequences cannot be learned from the suffix icon's attributes and accessibility text. When the suffix icon has both a text attribute and an accessibility description attribute and the icon is selected, the text attribute of the icon is announced first, followed by the content of the accessibility description attribute.<br>Default value: empty string.<br>If the value is **undefined**, the default value is used.|
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the suffix icon. This description is used to explain the suffix icon in detail to users. You should provide a relatively detailed text description for this attribute of the suffix icon to help users understand the operation to be performed and its possible consequences, especially when these consequences cannot be directly learned from the trailing icon's attributes and accessibility text. When the suffix icon has both a text attribute and an accessibility description attribute and the icon is selected, the system announces the text attribute of the icon first, followed by the content of the accessibility description attribute.<br>Default value: empty string.<br>If the value is **undefined**, the default value is used.|
| accessibilityLevel | string | No | Yes | Accessibility level of the suffix icon. It is used to control whether the trailing icon can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: The attribute value of the suffix icon is converted to **"yes"**.<br>**"yes"**: The suffix icon can be recognized by accessibility services.<br>**"no"**: The suffix icon cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: The suffix icon and all its child components cannot be recognized by accessibility services.<br>If a value outside the supported range is passed in, the default value is used.<br>Default value: **"auto"**<br>If the value is **undefined**, the default value is used. |

## Examples

### Example 1: Implementing ChipGroupV2 Without the Rightmost Custom Component

This example implements the effect of [ChipGroupV2](#chipgroupv2-1) without the rightmost custom component by not setting the **suffix** parameter.

```ts
import { ChipV2Size, ChipGroupV2, ChipGroupV2Items, ChipGroupV2ItemStyle, ChipGroupV2Space, ChipGroupV2Padding, ColorMetrics } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local selectedIndex: Array<number> = [0];

  build() {
    Column() {
      ChipGroupV2({
        // Each object in items sets the specific attributes of each ChipV2.
        items: new ChipGroupV2Items([
          {
            // Replace $r('app.media.icon') with the image resource file as required.
            prefixIcon: { src: $r('app.media.icon') },
            label: { text: 'Chip 1' },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: 'Chip 2' },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: 'Chip 3' },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: 'Chip 4' },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: 'Chip 5' },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: 'Chip 6' },
            allowClose: true
          },
        ]),
        // Set the style attribute of ChipV2.
        itemStyle: new ChipGroupV2ItemStyle({
          size: ChipV2Size.SMALL,
          backgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_button_normal')),
          fontColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary')),
          selectedBackgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_emphasize')),
          selectedFontColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary_contrary')),
        }),
        selectedIndexes: this.selectedIndex,
        multiple: false,
        chipGroupSpace: new ChipGroupV2Space({ itemSpace: 8, endSpace: 0 }),
        chipGroupPadding: new ChipGroupV2Padding({ top: 10, bottom: 10 }),
        onChange: (activatedChipsIndex: Array<number>) => {
          console.info('chips on clicked, activated index ' + activatedChipsIndex);
        },
      })
    }
  }
}
```

![](figures/chipgroupv2_1.png)

### Example 2: Setting the Rightmost Custom Component of ChipGroupV2

This example implements the rightmost custom component effect of [ChipGroupV2](#chipgroupv2-1) by setting the **suffix** parameter.

Since API version 26.0.0, **ChipGroupV2** supports the **suffix** attribute.

```ts
import { ChipV2Size, ChipGroupV2, ChipGroupV2Items, ChipGroupV2IconGroupSuffix, ChipGroupV2ItemStyle, ChipGroupV2Space, ChipGroupV2Padding, ColorMetrics, LengthMetrics } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local selectedIndex: Array<number> = [0, 1, 2, 3, 4, 5];
  @Local selectedState: boolean = true;

  @Builder
  ChipGroupSuffix(): void {
    // Implement the rightmost custom component effect by referencing ChipGroupV2IconGroupSuffix.
    ChipGroupV2IconGroupSuffix({
      items: [{
        icon: { src: $r('sys.media.ohos_ic_public_search_filled'), size: { width: LengthMetrics.fp(36), height: LengthMetrics.fp(36) } },
        action: () => {
          if (this.selectedState === false) {
            this.selectedIndex = [0, 1, 2, 3, 4, 5];
            this.selectedState = true;
          } else {
            this.selectedIndex = [];
            this.selectedState = false;
          }
        }
      }
      ]
    })
  }

  build() {
    Column() {
      ChipGroupV2({
        // Each object in items sets the specific attributes of each ChipV2.
        items: new ChipGroupV2Items([
          {
            // Replace $r('app.media.icon') with the image resource file as required.
            prefixIcon: { src: $r('app.media.icon') },
            label: { text: 'Chip 1' },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: 'Chip 2' },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: 'Chip 3' },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: 'Chip 4' },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: 'Chip 5' },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: 'Chip 6' },
            allowClose: true
          },
        ]),
        // Set the style attribute of ChipV2.
        itemStyle: new ChipGroupV2ItemStyle({
          size: ChipV2Size.NORMAL,
          backgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_button_normal')),
          fontColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary')),
          selectedBackgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_emphasize')),
          selectedFontColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary_contrary')),
        }),
        selectedIndexes: this.selectedIndex,
        multiple: true,
        chipGroupSpace: new ChipGroupV2Space({ itemSpace: 8, endSpace: 0 }),
        chipGroupPadding: new ChipGroupV2Padding({ top: 10, bottom: 10 }),
        onChange: (activatedChipsIndex: Array<number>) => {
          console.info('chips on clicked, activated index ' + activatedChipsIndex);
        },
        // Rightmost custom component of ChipGroupV2.
        suffix: this.ChipGroupSuffix
      })
    }
  }
}
```

![](figures/chipgroupv2_2.png)

### Example 3: Setting Symbol Icons

This example uses [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) to set symbol icons for [ChipGroupV2IconGroupSuffix](#chipgroupv2icongroupsuffix) and [ChipGroupV2](#chipgroupv2-1).

Since API version 26.0.0, **ChipGroupV2IconGroupSuffix** and **ChipGroupV2** are added.

```ts
import { ChipV2Size, ChipGroupV2, ChipGroupV2Items, ChipGroupV2IconGroupSuffix, SymbolGlyphModifier, ChipGroupV2ItemStyle, ChipGroupV2Space, ChipGroupV2Padding, ColorMetrics } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local selectedIndex: Array<number> = [0, 1, 2, 3, 4, 5];
  @Local selectedState: boolean = true;
  @Local prefixModifierNormal: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_star'));
  @Local prefixModifierActivated: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Red]);
  @Local suffixModifierNormal: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi'));
  @Local suffixModifierActivated: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.ohos_wifi')).fontColor([Color.Red]);

  @Builder
  ChipGroupSuffix(): void {
    // Implement a rightmost custom component of the component by referencing ChipGroupV2IconGroupSuffix.
    ChipGroupV2IconGroupSuffix({
      items: [
        new SymbolGlyphModifier($r('sys.symbol.magnifyingglass'))
          .onClick(() => {
            if (this.selectedState === false) {
              this.selectedIndex = [0, 1, 2, 3, 4, 5];
              this.selectedState = true;
            } else {
              this.selectedIndex = [];
              this.selectedState = false;
            }
          })
      ]
    })
  }

  build() {
    Column() {
      ChipGroupV2({
        // Each object in items sets the specific attributes of each ChipV2.
        items: new ChipGroupV2Items([
          {
            prefixSymbolIcon: { normal: this.prefixModifierNormal, activated: this.prefixModifierActivated },
            label: { text: 'Chip 1' },
            suffixSymbolIcon: { normal: this.suffixModifierNormal, activated: this.suffixModifierActivated },
            allowClose: false,
          },
          {
            prefixSymbolIcon: { normal: this.prefixModifierNormal, activated: this.prefixModifierActivated },
            label: { text: 'Chip 2' },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: 'Chip 3' },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: 'Chip 4' },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: 'Chip 5' },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: 'Chip 6' },
            allowClose: true,
          },
        ]),
        // Set the style attribute of ChipV2.
        itemStyle: new ChipGroupV2ItemStyle({
          size: ChipV2Size.NORMAL,
          backgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_button_normal')),
          fontColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary')),
          selectedBackgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_emphasize')),
          selectedFontColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary_contrary')),
        }),
        selectedIndexes: this.selectedIndex,
        multiple: true,
        chipGroupSpace: new ChipGroupV2Space({ itemSpace: 8, endSpace: 0 }),
        chipGroupPadding: new ChipGroupV2Padding({ top: 10, bottom: 10 }),
        onChange: (activatedChipsIndex: Array<number>) => {
          console.info('chips on clicked, activated index ' + activatedChipsIndex);
        },
        // Rightmost custom component of ChipGroupV2.
        suffix: this.ChipGroupSuffix
      })
    }
  }
}
```

![](figures/chipgroupv2_3.png)

### Example 4: Listening for Internal Attribute Changes of Object-Type Attributes in ChipGroupV2

Classes such as [ChipGroupV2Items](#chipgroupv2items), [ChipGroupV2Item](#chipgroupv2item), and [ChipGroupV2ItemStyle](#chipgroupv2itemstyle) are decorated with **@ObservedV2**, and the **ChipGroupV2** component receives attribute parameters through **@Param**. For primitive-type attributes decorated with **@Trace** (such as **itemSpace** of **ChipGroupV2Space**), **@Param** can already observe attribute changes and trigger UI refresh without additional processing. However, for internal attributes of object-type attributes in these classes (such as the **size** of **prefixIcon** in **ChipGroupV2Item**), the object types themselves are not decorated with **@ObservedV2**, so their internal attribute changes cannot be perceived by **@Param**, causing the UI not to refresh automatically when internal attributes are modified. Using the [makeObserved](../js-apis-stateManagement.md#makeobserved) API to wrap object-type attributes can supplement deep observation capability for the internal attributes of the object. For details about the **makeObserved** API, see [makeObserved API: Changing Unobservable Data to Observable Data](../../../ui/state-management/arkts-new-makeObserved.md).

The following example compares two scenarios: when the **Change itemSpace** button is tapped to modify the **itemSpace** attribute of **chipGroupSpace** (a primitive-type attribute decorated with **@Trace**, which already supports observation), the UI refreshes automatically; when the **Change icon size** button is tapped to modify the internal attribute for **size** of **prefixIcon** in **ChipGroupV2Item** (an internal attribute of an object-type attribute, which is observable when **size** is wrapped with **UIUtils.makeObserved**), the UI also refreshes automatically.

```ts
import {
  ChipGroupV2,
  ChipGroupV2Items,
  ChipGroupV2ItemStyle,
  ChipGroupV2Space,
  ChipGroupV2Padding,
  LengthMetrics,
  UIUtils
} from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local items: ChipGroupV2Items = new ChipGroupV2Items([
    {
      // Use UIUtils.makeObserved to wrap size so that the internal attributes width and height can be observed.
      prefixIcon: {
        src: $r('sys.media.ohos_ic_public_clock'),
        size: UIUtils.makeObserved({ width: LengthMetrics.fp(16), height: LengthMetrics.fp(16) })
      },
      label: { text: 'Chip 1' }
    },
    {
      label: { text: 'Chip 2' }
    },
    {
      label: { text: 'Chip 3' }
    }
  ]);
  // The internal attributes of ChipGroupV2Space are already decorated by @Trace, so makeObserved is not required.
  @Local chipGroupSpace: ChipGroupV2Space = new ChipGroupV2Space({ itemSpace: 8 });
  @Local chipGroupPadding: ChipGroupV2Padding = new ChipGroupV2Padding({ top: 10, bottom: 10 });
  @Local itemStyle: ChipGroupV2ItemStyle = new ChipGroupV2ItemStyle({});
  @Local selectedIndexes: number[] = [];
  @Local currentIconSize: number = 16;
  @Local currentItemSpace: number = 8;

  build() {
    Column({ space: 10 }) {
      ChipGroupV2({
        items: this.items,
        $items: (items: ChipGroupV2Items) => { this.items = items; },
        itemStyle: this.itemStyle,
        chipGroupSpace: this.chipGroupSpace,
        chipGroupPadding: this.chipGroupPadding,
        selectedIndexes: this.selectedIndexes,
        $selectedIndexes: (indexes: number[]) => { this.selectedIndexes = indexes; },
      })
      // When a primitive attribute decorated by @Trace is changed, the UI is automatically refreshed.
      Button('Change itemSpace')
        .onClick(() => {
          this.currentItemSpace = this.currentItemSpace === 8 ? 16 : 8;
          this.chipGroupSpace.itemSpace = this.currentItemSpace;
        })
      // When the internal attributes of an object-type attribute is changed, the UI is also automatically refreshed because it is wrapped by makeObserved.
      Button('Change icon size')
        .onClick(() => {
          if (this.items.length >= 1 && this.items[0] && this.items[0].prefixIcon && this.items[0].prefixIcon.size) {
            this.currentIconSize = this.currentIconSize === 16 ? 30 : 16;
            this.items[0].prefixIcon.size.width = LengthMetrics.fp(this.currentIconSize);
            this.items[0].prefixIcon.size.height = LengthMetrics.fp(this.currentIconSize);
          }
        })
    }
  }
}
```

![chipgroupv2-sample4](figures/chipgroupv2-make-observed.gif)
<!--no_check-->