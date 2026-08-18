# ChipV2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @song-song-song-->
<!--Designer: @fenglinbailu-->
<!--Tester: @weixin_45530366-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=9aa812250f4e9aa6e205822b2fc097b3c5b2a47d translatedAt=2026-07-21T01:24:12.300Z pushedAt=2026-07-24T01:47:23.171Z -->

The **ChipV2** component is a chip component that delivers rich styles and interaction capabilities. It provides features such as prefix icons, suffix icons, active states, and close buttons, supports the symbol and image icon types, and offers comprehensive accessibility capabilities. This component is suitable for scenarios such as search history, email recipient lists, tag selection, filters, and contact display.

This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), state management V2 delivers enhanced capabilities for deep observation and management of data objects, and is no longer limited to the component level. With state management V2, you can control component data and state more flexibly, achieving more efficient UI refresh.

> **NOTE**
>
> The APIs of this module can only be used in the stage model.
>

**Since:** 26.0.0

## Modules to Import

```ts
import { ChipV2, ChipV2Options, ChipV2Size } from '@kit.ArkUI';
```

## Child Components

None

## ChipV2

ChipV2({ chipV2Options: ChipV2Options })

**Since:** 26.0.0

**Decorator:** @ComponentV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name    | Type                        | Mandatory | Decorator Type | Description                 |
| ------- | --------------------------- | ---- | ---- | -------------------- |
| chipV2Options | [ChipV2Options](#chipv2options) | Yes | @Require<br>@Param | Parameters of the **ChipV2** component, which are used to customize the appearance and behavior of the **ChipV2** component, including configuration options such as **label**, **prefixIcon**, **suffixIcon**, **allowClose**, **activated**, **backgroundColor**, and **size**. |

### build

build(): void

Constructs the UI structure of the advanced **ChipV2** component.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

## ChipV2Options

Defines the style and specific style parameters of the **ChipV2** component.

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

| Name            | Type                                                         | Read-only | Optional | Description                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| label            | [ChipV2Label](#chipv2label) | No   | No  | Text of **ChipV2**.<br>**Decorator:** @Trace |
| prefixIcon      | [ChipV2Icon](#chipv2icon)                      | No  | Yes  | Prefix icon of **ChipV2**.<br>Default value: no prefix icon is displayed.<br>If the value is **undefined**, the default value is used.<br>For the symbol icon, the default **fontColor** values are as follows: **normalFontColor**: `[$r('sys.color.chip_usually_icon_color')]`, **activatedFontColor**: `[$r('sys.color.chip_active_icon_color')]`. The default **fontSize** is 16.<br>For the image icon, the default **fillColor** is `$r('sys.color.chip_usually_icon_color')`, and the default **activatedFillColor** is `$r('sys.color.chip_active_icon_color')`. The color parsing of **fillColor** and **activatedFillColor** is consistent with that of the **Image** component. The **fillColor** and **activatedFillColor** attributes take effect only when the image format is SVG; for non-SVG images, the default values are not applied.<br>**Decorator:** @Trace |
| suffixIcon      | [ChipV2Icon](#chipv2icon)                      | No  | Yes  | Suffix icon of **ChipV2**.<br>Default value: no suffix icon is displayed.<br>If the value is **undefined**, the default value is used.<br>Note: When a value is passed in **suffixIcon**, the **allowClose** attribute does not take effect.<br>For the symbol icon, the default **fontColor** values are as follows: **normalFontColor**: `[$r('sys.color.chip_usually_icon_color')]`, **activatedFontColor**: `[$r('sys.color.chip_active_icon_color')]`. The default **fontSize** is 16.<br>For the image icon, the default **fillColor** is `$r('sys.color.chip_usually_icon_color')`, and the default **activatedFillColor** is `$r('sys.color.chip_active_icon_color')`. The color parsing of **fillColor** and **activatedFillColor** is consistent with that of the **Image** component. The **fillColor** and **activatedFillColor** attributes take effect only when the image format is SVG.<br>**Decorator:** @Trace |
| allowClose      | boolean                                                      | No  | Yes  | Whether to display the close icon.<br>When a value is passed in **suffixIcon**, **allowClose** does not take effect. When no value is passed in **suffixIcon**, **allowClose** determines whether the close icon is displayed.<br>Default value: **true**<br>**true**: Display the close icon. **false**: The close icon is not displayed.<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| closeIcon | [ChipV2CloseIcon](#chipv2closeicon) | No | Yes | Configuration of the close icon, including accessibility configuration. Set this attribute when you need to customize the size or accessibility of the close icon.<br>Default values:<br>- Default size: When **size** is **ChipV2Size.SMALL**, the default value is `$r('sys.float.chip_small_font_size')`. In other cases, the default value is `$r('sys.float.chip_normal_font_size')`.<br>- Default accessibility: No accessibility description.<br>**fontSize** does not support percentage setting. If an invalid value is passed, the default value will be used.<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| enabled         | boolean                                                      | No  | Yes  | Whether **ChipV2** is available.<br>Default value: **true**<br>**true**: **ChipV2** is available. **false**: **ChipV2** is unavailable.<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| activated    | boolean                                        | No  | Yes  | Whether **ChipV2** is activated.<br>Default value: **false**<br>**true**: **ChipV2** is activated. **false**: **ChipV2** is not activated.<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| backgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)                   | No  | Yes  | Background color of **ChipV2**.<br>Default value: **$r('sys.color.chip_background_color')**<br>If the value is **undefined**, the default value is used.<br>If the value is invalid, the background color is transparent.<br>**Decorator:** @Trace |
| activatedBackgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)          | No  | Yes  | Background color of **ChipV2** when activated.<br>Default value: **$r('sys.color.chip_container_activated_color')**<br>If the value is **undefined**, the default value is used.<br>If the value is invalid, the background color is transparent.<br>**Decorator:** @Trace |
| borderRadius    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)                         | No  | Yes  | Rounded corner radius of the **ChipV2** background. Percentage values are not supported. If a percentage value is passed, the default value is used.<br>Default values:<br>When **size** is **ChipV2Size.NORMAL**, the default **borderRadius** is **$r('sys.float.chip_border_radius_normal')**.<br>When **size** is **ChipV2Size.SMALL**, the default **borderRadius** is **$r('sys.float.chip_border_radius_small')**.<br>Unit: vp<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| size            | [ChipV2Size](#chipv2size) \| [SizeT](../js-apis-arkui-graphics.md#sizett12)\<[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)> | No  | Yes  | Size of **ChipV2**.<br>Default value: **ChipV2Size.NORMAL**<br>The **SizeT\<LengthMetrics\>** type does not support percentage setting. If an invalid value is passed, the default value will be used.<br>**NOTE**<br>[Aging-friendly design](../../../ui/arkui-support-for-aging-adaptation.md) does not take effect when **size** specifies a specific width and height, except when **size** is set to **{ height: 0, width: 0 }**.<br>**Decorator:** @Trace |
| direction | [Direction](ts-appendix-enums.md#direction) | No | Yes | Layout direction.<br>Default value: **Direction.Auto**<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the **ChipV2** component. This description is used to explain the current component to users in detail. You should provide a thorough text description for this attribute to help users understand the operation to be performed and its possible results, especially when such results cannot be directly inferred from the component's attributes and accessibility text. When the component that is selected has both a text attribute and an accessibility description attribute, the system first reads the text attribute, followed by the content of the accessibility description attribute.<br>Default value: empty string.<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| accessibilityLevel | string | No | Yes | Accessibility level of the **ChipV2** component. This parameter controls whether the component can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: The attribute value of the component is converted to **"yes"**.<br>**"yes"**: The component can be recognized by accessibility services.<br>**"no"**: The component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: The component and all its child components cannot be recognized by accessibility services.<br>Default value: **"auto"**<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| accessibilitySelectedType | [ChipV2AccessibilitySelectedType](#chipv2accessibilityselectedtype) | No | Yes | Selected state type of the **ChipV2** component.<br>Default value: When the **activated** attribute is **true** but **accessibilitySelectedType** is not specified, the **CHECKED** type is used by default. When the **activated** attribute is **false** or not set, the **CLICKED** type is used by default.<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| maxFontScale | number \| [Resource](ts-types.md#resource) | No | Yes | Maximum font scale factor for the text and icons of the **ChipV2** component.<br>Value range: [1, +∞)<br>If the set value is less than 1, the value **1** is used. Abnormal values do not take effect by default.<br>Default value: **1**<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| minFontScale | number \| [Resource](ts-types.md#resource) | No | Yes | Minimum font scale factor for the text and icons of the **ChipV2** component.<br>Value range: [0, 1]<br>If the set value is less than 0, the value **0** is used. If the set value is greater than 1, the value **1** is used. Abnormal values do not take effect by default.<br>Default value: **1**<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| padding | [LocalizedPadding](ts-types.md#localizedpadding12) | No | Yes | Padding of the **ChipV2** component.<br>Default values:<br>- When **size** is **ChipV2Size.SMALL** and **activated** is **true**, the default value is: `{ start: LengthMetrics.resource('sys.float.chip_activated_small_text_padding'), end: LengthMetrics.resource('sys.float.chip_activated_small_text_padding'), top: LengthMetrics.vp(4), bottom: LengthMetrics.vp(4)}`.<br>- When **size** is **ChipV2Size.SMALL** and **activated** is **false**, the default value is: `{ start: LengthMetrics.resource('sys.float.chip_small_text_padding'), end: LengthMetrics.resource('sys.float.chip_small_text_padding'), top: LengthMetrics.vp(4), bottom: LengthMetrics.vp(4)}`.<br>- When **size** is not **ChipV2Size.SMALL** and **activated** is **true**, the default value is: `{ start: LengthMetrics.resource('sys.float.chip_activated_normal_text_padding'), end: LengthMetrics.resource('sys.float.chip_activated_normal_text_padding'), top: LengthMetrics.vp(4), bottom: LengthMetrics.vp(4)}`.<br>- When **size** is not **ChipV2Size.SMALL** and **activated** is **false**, the default value is: `{ start: LengthMetrics.resource('sys.float.chip_normal_text_padding'), end: LengthMetrics.resource('sys.float.chip_normal_text_padding'), top: LengthMetrics.vp(4), bottom: LengthMetrics.vp(4)}`.<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| fontSize | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Uniformly sets the font size of the text and icons of the **ChipV2** component. Percentage values are not supported. If a percentage value is passed, the default value is used.<br>The priority of this **fontSize** is lower than that of the **fontSize** attributes in **prefixIcon**, **label**, **suffixIcon**, and **closeIcon**.<br>Default values:<br>- When **size** is **ChipV2Size.SMALL**, the default text value is `$r('sys.float.chip_small_font_size')`, and the default icon value is `$r('sys.float.chip_small_icon_size')`.<br>- In other cases, the default text value is `$r('sys.float.chip_normal_font_size')`, and the default icon value is `$r('sys.float.chip_normal_icon_size')`.<br>Unit: fp<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| backgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | Yes | System material style of the component. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, meaning no material style is applied.<br>**Decorator:** @Trace |
| activatedBackgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | Yes | System material style of the activated component. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, meaning no material style is applied.<br>**Decorator:** @Trace |
| onClose         | [VoidCallback](ts-types.md#voidcallback12)  | No  | Yes  | Callback for the default close icon tap event.<br>When **allowClose** is **true** and no value is passed to **suffixIcon**, this callback is invoked when the close icon is tapped.<br>Default value: The callback is not executed.<br>If the value is **undefined**, the default value is used. |
| onClicked     | [Callback](ts-types.md#callback12)\<void> | No  | Yes  | Callback for the **ChipV2** tap event.<br>When **enabled** is **true**, tapping **ChipV2** triggers the tap event. When **enabled** is **false**, the tap event is not triggered.<br>Default value: The callback is not executed.<br>If the value is **undefined**, the default value is used. |

### constructor

constructor(config: IChipV2OptionsConfig)

A constructor used to create a **ChipV2Options** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [IChipV2OptionsConfig](#ichipv2optionsconfig) | Yes | Style configuration of **ChipV2**, which is used to customize the appearance and behavior of the **ChipV2** component, including configuration options such as **label**, **prefixIcon**, **suffixIcon**, **allowClose**, **activated**, and **backgroundColor**. |

## IChipV2OptionsConfig

Defines the configuration API of **ChipV2** options.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | --- | ---- | ---- |
| label | [ChipV2Label](#chipv2label) | No | No | Text of **ChipV2**. |
| prefixIcon | [ChipV2Icon](#chipv2icon) | No | Yes | Prefix icon of **ChipV2**.<br>Default value: no prefix icon is displayed.<br>If the value is **undefined**, the default value is used. |
| suffixIcon | [ChipV2Icon](#chipv2icon) | No | Yes | Suffix icon of **ChipV2**.<br>Default value: no suffix icon is displayed.<br>If the value is **undefined**, the default value is used.<br>Note: When a value is passed in **suffixIcon**, the **allowClose** attribute does not take effect. |
| allowClose | boolean | No | Yes | Whether to display the close icon.<br>When a value is passed in **suffixIcon**, **allowClose** does not take effect. When no value is passed in **suffixIcon**, **allowClose** determines whether the close icon is displayed.<br>Default value: **true**<br>**true**: Display the close icon. **false**: The close icon is not displayed.<br>If the value is **undefined**, the default value is used. |
| closeIcon | [ChipV2CloseIcon](#chipv2closeicon) | No | Yes | Configuration of the close icon, including accessibility configuration. Set this attribute when you need to customize the size or accessibility of the close icon.<br>Default values:<br>- Default size: When **size** is **ChipV2Size.SMALL**, the default value is `$r('sys.float.chip_small_font_size')`. In other cases, the default value is `$r('sys.float.chip_normal_font_size')`.<br>- Default accessibility: No accessibility description.<br>If the value is **undefined**, the default value is used. |
| enabled | boolean | No | Yes | Whether **ChipV2** is available.<br>Default value: **true**<br>**true**: **ChipV2** is available. **false**: **ChipV2** is unavailable.<br>If the value is **undefined**, the default value is used. |
| activated | boolean | No | Yes | Whether **ChipV2** is activated.<br>Default value: **false**<br>**true**: **ChipV2** is activated. **false**: **ChipV2** is not activated.<br>If the value is **undefined**, the default value is used. |
| backgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Background color of **ChipV2**.<br>Default value: **$r('sys.color.chip_background_color')**<br>If the value is **undefined**, the default value is used.<br>If the value is invalid, the background color is transparent. |
| activatedBackgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Background color of **ChipV2** when activated.<br>Default value: **$r('sys.color.chip_container_activated_color')**<br>If the value is **undefined**, the default value is used.<br>If the value is invalid, the background color is transparent. |
| borderRadius | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Rounded corner radius of the **ChipV2** background. Percentage values are not supported. If a percentage value is passed, the default value is used.<br>Default values:<br>When **size** is **ChipV2Size.NORMAL**, the default **borderRadius** is **$r('sys.float.chip_border_radius_normal')**.<br>When **size** is **ChipV2Size.SMALL**, the default **borderRadius** is **$r('sys.float.chip_border_radius_small')**.<br>Unit: vp<br>If the value is **undefined**, the default value is used. |
| size | [ChipV2Size](#chipv2size) \| [SizeT](../js-apis-arkui-graphics.md#sizett12)\<[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)> | No | Yes | Size of **ChipV2**.<br>Default value: **ChipV2Size.NORMAL**<br>The **SizeT\<LengthMetrics\>** type does not support percentage setting. If an invalid value is passed, the default value will be used.<br>**NOTE**<br>[Aging-friendly design](../../../ui/arkui-support-for-aging-adaptation.md) does not take effect when **size** specifies a specific width and height, except when **size** is set to **{ height: 0, width: 0 }**. |
| direction | [Direction](ts-appendix-enums.md#direction) | No | Yes | Layout direction.<br>Default value: **Direction.Auto**<br>If the value is **undefined**, the default value is used. |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the **ChipV2** component. This description is used to explain the current component to users in detail. You should provide a thorough text description for this attribute to help users understand the operation to be performed and its possible results, especially when such results cannot be directly inferred from the component's attributes and accessibility text. When a component that is selected has both a text attribute and an accessibility description attribute, the system first reads the text attribute, followed by the content of the accessibility description attribute.<br>Default value: empty string.<br>If the value is **undefined**, the default value is used. |
| accessibilityLevel | string | No | Yes | Accessibility level of the **ChipV2** component. This parameter controls whether the component can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: The attribute value of the component is converted to **"yes"**.<br>**"yes"**: The component can be recognized by accessibility services.<br>**"no"**: The component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: The component and all its child components cannot be recognized by accessibility services.<br>Default value: **"auto"**<br>If the value is **undefined**, the default value is used. |
| accessibilitySelectedType | [ChipV2AccessibilitySelectedType](#chipv2accessibilityselectedtype) | No | Yes | Selected state type of the **ChipV2** component.<br>Default value: When the **activated** attribute is **true** but **accessibilitySelectedType** is not specified, the **CHECKED** type is used by default. When the **activated** attribute is **false** or not set, the **CLICKED** type is used by default.<br>If the value is **undefined**, the default value is used. |
| maxFontScale | number \| [Resource](ts-types.md#resource) | No | Yes | Maximum font scale factor for the text and icons of the **ChipV2** component.<br>Value range: [1, +∞)<br>If the set value is less than 1, the value **1** is used. Abnormal values do not take effect by default.<br>Default value: **1**<br>If the value is **undefined**, the default value is used. |
| minFontScale | number \| [Resource](ts-types.md#resource) | No | Yes | Minimum font scale factor for the text and icons of the **ChipV2** component.<br>Value range: [0, 1]<br>If the set value is less than 0, the value **0** is used. If the set value is greater than 1, the value **1** is used. Abnormal values do not take effect by default.<br>Default value: **1**<br>If the value is **undefined**, the default value is used. |
| padding | [LocalizedPadding](ts-types.md#localizedpadding12) | No | Yes | Padding of the **ChipV2** component.<br>Default values:<br>- When **size** is **ChipV2Size.SMALL** and **activated** is **true**, the default value is: `{ start: LengthMetrics.resource('sys.float.chip_activated_small_text_padding'), end: LengthMetrics.resource('sys.float.chip_activated_small_text_padding'), top: LengthMetrics.vp(4), bottom: LengthMetrics.vp(4)}`.<br>- When **size** is **ChipV2Size.SMALL** and **activated** is **false**, the default value is: `{ start: LengthMetrics.resource('sys.float.chip_small_text_padding'), end: LengthMetrics.resource('sys.float.chip_small_text_padding'), top: LengthMetrics.vp(4), bottom: LengthMetrics.vp(4)}`.<br>- When **size** is not **ChipV2Size.SMALL** and **activated** is **true**, the default value is: `{ start: LengthMetrics.resource('sys.float.chip_activated_normal_text_padding'), end: LengthMetrics.resource('sys.float.chip_activated_normal_text_padding'), top: LengthMetrics.vp(4), bottom: LengthMetrics.vp(4)}`.<br>- When **size** is not **ChipV2Size.SMALL** and **activated** is **false**, the default value is: `{ start: LengthMetrics.resource('sys.float.chip_normal_text_padding'), end: LengthMetrics.resource('sys.float.chip_normal_text_padding'), top: LengthMetrics.vp(4), bottom: LengthMetrics.vp(4)}`.<br>If the value is **undefined**, the default value is used. |
| fontSize | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Uniformly sets the font size of the text and icons of the **ChipV2** component. Percentage values are not supported. If a percentage value is passed, the default value is used.<br>The priority of this **fontSize** is lower than that of the **fontSize** attributes in **prefixIcon**, **label**, **suffixIcon**, and **closeIcon**.<br>Default values:<br>- When **size** is **ChipV2Size.SMALL**, the default text value is `$r('sys.float.chip_small_font_size')`, and the default icon value is `$r('sys.float.chip_small_icon_size')`.<br>- In other cases, the default text value is `$r('sys.float.chip_normal_font_size')`, and the default icon value is `$r('sys.float.chip_normal_icon_size')`.<br>Unit: fp<br>If the value is **undefined**, the default value is used. |
| backgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | Yes | System material style of the component. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, meaning no material style is applied. |
| activatedBackgroundSystemMaterial | uiMaterial.[Material](../arkts-apis-uimaterial.md#material) | No | Yes | System material style of the activated component. Different materials have different effects, which can affect the component's [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [borderColor](ts-universal-attributes-border.md#bordercolor), [borderWidth](ts-universal-attributes-border.md#borderwidth), [shadow](ts-universal-attributes-image-effect.md#shadow) effect, and [materialFilter](ts-universal-attributes-filter-effect.md#materialfilter23) effect.<br>Default value: **undefined**, meaning no material style is applied. |
| onClose | [VoidCallback](ts-types.md#voidcallback12) | No | Yes | Callback for the default close icon tap event.<br>When **allowClose** is **true** and no value is passed to **suffixIcon**, this callback is invoked when the close icon is tapped.<br>Default value: The callback is not executed.<br>If the value is **undefined**, the default value is used. |
| onClicked | [Callback](ts-types.md#callback12)\<void> | No | Yes | Callback for the **ChipV2** tap event.<br>When **enabled** is **true**, tapping **ChipV2** triggers the tap event. When **enabled** is **false**, the tap event is not triggered.<br>Default value: The callback is not executed.<br>If the value is **undefined**, the default value is used. |

## ChipV2Label

Defines the text attribute class.

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
| text | string | No | No | Text content.<br>**Decorator:** @Trace |
| fontSize | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Font size. Percentage values are not supported. When a percentage value is passed, the default value is used.<br>Default values:<br>When **size** is **ChipV2Size.SMALL**, the default value is **$r('sys.float.chip_small_font_size')**.<br>In other cases, the default value is **$r('sys.float.chip_normal_font_size')**<br>Unit: fp<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| fontColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Font color.<br>Default value: **$r('sys.color.chip_font_color')**<br>When the value is **undefined**, the default value is used.<br>When the value is invalid, the default value is used.<br>**Decorator:** @Trace |
| activatedFontColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Font color when **ChipV2** is activated.<br>Default value: **$r('sys.color.chip_activated_fontcolor')**<br>When the value is **undefined**, the default value is used.<br>When the value is invalid, the default value is used.<br>**Decorator:** @Trace |
| fontFamily | string | No | Yes | Font family.<br>Default value: **"HarmonyOS Sans"**<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| labelMargin | [ChipV2LabelMarginConfig](#chipv2labelmarginconfig) | No | Yes | Spacing between the text and the left/right icons.<br>Default values:<br>When **size** is **ChipV2Size.SMALL**, the default value is **{ left: 4, right: 4 }**.<br>When **size** is **ChipV2Size.NORMAL**, the default value is **{ left: 6, right: 6 }**.<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| localizedLabelMargin | [ChipV2LocalizedLabelMarginConfig](#chipv2localizedlabelmarginconfig) | No | Yes | Spacing between the localized text and the left/right icons.<br>Default values:<br>When **size** is **ChipV2Size.SMALL**, default value: `{  start: LengthMetrics.resource($r('sys.float.chip_small_text_margin')),  end: LengthMetrics.resource($r('sys.float.chip_small_text_margin')) }`.<br>When **size** is **ChipV2Size.NORMAL**, default value:<br>`{  start: LengthMetrics.resource($r('sys.float.chip_normal_text_margin')),  end: LengthMetrics.resource($r('sys.float.chip_normal_text_margin')) }`.<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| modifier | [TextModifier](ts-universal-attributes-attribute-modifier.md#custom-modifier) | No | Yes | Text modifier, which is used to set common text attributes. Pass this parameter when you need to dynamically modify text attributes (such as **fontWeight** and **fontStyle**) through the modifier. When no value or **undefined** is passed in, the modifier is not applied and the text uses default attribute settings.<br>Default value: **undefined**, meaning that the modifier is not applied.<br>**Decorator:** @Trace |

### constructor

constructor(config: ChipV2LabelConfig)

A constructor used to create a **ChipV2Label** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2LabelConfig](#chipv2labelconfig) | Yes | Text attribute configuration, which is used to set the text display attributes of **ChipV2**, including configuration options such as **text**, **fontSize**, **fontColor**, **activatedFontColor**, and **fontFamily**. |

## ChipV2LabelConfig

Defines the text attribute configuration.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| text | string | No | No | Text content. |
| fontSize | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Font size. Percentage values are not supported. When a percentage value is passed, the default value is used.<br>Default values:<br>When **size** is **ChipV2Size.SMALL**, the default value is **$r('sys.float.chip_small_font_size')**.<br>In other cases, the default value is **$r('sys.float.chip_normal_font_size')**<br>Unit: fp<br>When the value is **undefined**, the default value is used. |
| fontColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Font color.<br>Default value: **$r('sys.color.chip_font_color')**<br>When the value is **undefined**, the default value is used.<br>When the value is invalid, the default value is used. |
| activatedFontColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Font color when **ChipV2** is activated.<br>Default value: **$r('sys.color.chip_activated_fontcolor')**<br>When the value is **undefined**, the default value is used.<br>When the value is invalid, the default value is used. |
| fontFamily | string | No | Yes | Font family.<br>Default value: **"HarmonyOS Sans"**<br>When the value is **undefined**, the default value is used. |
| labelMargin | [ChipV2LabelMarginConfig](#chipv2labelmarginconfig) | No | Yes | Spacing between the text and the left/right icons.<br>Default values:<br>When **size** is **ChipV2Size.SMALL**, the default value is **{ left: 4, right: 4 }**.<br>When **size** is **ChipV2Size.NORMAL**, the default value is **{ left: 6, right: 6 }**.<br>When the value is **undefined**, the default value is used. |
| localizedLabelMargin | [ChipV2LocalizedLabelMarginConfig](#chipv2localizedlabelmarginconfig) | No | Yes | Spacing between the localized text and the left/right icons.<br>Default values:<br>When **size** is **ChipV2Size.SMALL**, default value:<br>`{  start: LengthMetrics.resource($r('sys.float.chip_small_text_margin')),  end: LengthMetrics.resource($r('sys.float.chip_small_text_margin')) }`.<br>When **size** is **ChipV2Size.NORMAL**, default value:<br>`{  start: LengthMetrics.resource($r('sys.float.chip_normal_text_margin')),  end: LengthMetrics.resource($r('sys.float.chip_normal_text_margin')) }`.<br>When the value is **undefined**, the default value is used. |
| modifier | [TextModifier](ts-universal-attributes-attribute-modifier.md#custom-modifier) | No | Yes | Text modifier, which is used to set common text attributes. Pass this parameter when you need to dynamically modify text attributes (such as **fontWeight** and **fontStyle**) through the modifier. When no value or **undefined** is passed in, the modifier is not applied and the text uses default attribute settings.<br>Default value: **undefined**, meaning that the modifier is not applied. |

## ChipV2LabelMarginConfig

Defines the margin configuration between the text and the left and right icons.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name  | Type                                 | Read-only | Optional | Description                                                         |
| ----- | ------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| left  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No   | Yes   | Margin between the text and the left icon. Percentage values are not supported. If a percentage value is passed in, the default value is used.<br>Default values:<br>When there is no left icon, the default value of **left** is **0**.<br>When there is a left icon and **size** is **ChipV2Size.SMALL**, the default value of **left** is **4**.<br>When there is a left icon and **size** is **ChipV2Size.NORMAL**, the default value of **left** is **6**.<br>Unit: vp<br>If the value is out of range, the default value is used.<br>Value range: [0, +∞) |
| right | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No   | Yes   | Margin between the text and the right icon. Percentage values are not supported. If a percentage value is passed in, the default value is used.<br>Default values:<br>When there is no right icon, the default value of **right** is **0**.<br>When there is a right icon and **size** is **ChipV2Size.SMALL**, the default value of **right** is **4**.<br>When there is a right icon and **size** is **ChipV2Size.NORMAL**, the default value of **right** is **6**.<br>Unit: vp<br>If the value is out of range, the default value is used.<br>Value range: [0, +∞) |

## ChipV2LocalizedLabelMarginConfig

Defines the margin configuration between the localized text and the left and right icons.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| start | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Margin between the text and the start-side icon. Percentage values are not supported. If a percentage value is passed in, the default value is used.<br>Default values:<br>When **size** is **ChipV2Size.SMALL**, the default value of **start** is:<br>`LengthMetrics.resource($r('sys.float.chip_small_text_margin'))`.<br>When **size** is **ChipV2Size.NORMAL**, the default value of **start** is:<br>`LengthMetrics.resource($r('sys.float.chip_normal_text_margin'))`.<br>Unit: vp<br>Value range: [0, +∞)<br>If the value is out of range, the default value is used.<br>If the value is **undefined**, the default value is used. |
| end | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Margin between the text and the end-side icon. Percentage values are not supported. If a percentage value is passed in, the default value is used.<br>Default values:<br>When **size** is **ChipV2Size.SMALL**, the default value of **end** is:<br>`LengthMetrics.resource($r('sys.float.chip_small_text_margin'))`.<br>When **size** is **ChipV2Size.NORMAL**, the default value of **end** is:<br>`LengthMetrics.resource($r('sys.float.chip_normal_text_margin'))`.<br>Unit: vp<br>Value range: [0, +∞)<br>If the value is out of range, the default value is used.<br>If the value is **undefined**, the default value is used. |

## ChipV2Icon

Defines the base class of icons.

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### constructor

constructor()

A constructor used to create a **ChipV2Icon** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

## ChipV2SymbolIcon

Defines the symbol icon class.

This API inherits from [ChipV2Icon](#chipv2icon).

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| normal | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Icon settings in the inactive state.<br>Default value: **undefined**, which means no prefix icon or suffix icon is displayed. When the value is **undefined**, the default value is used.<br>Modifying the animation type using [SymbolEffect](ts-basic-components-symbolGlyph.md#symboleffect12-2) and setting the animation effect using [effectStrategy](ts-basic-components-symbolGlyph.md#effectstrategy) are not supported.<br>**Decorator:** @Trace |
| activated | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Icon settings in the active state.<br>Default value: **undefined**, which means no prefix icon or suffix icon is displayed. When the value is **undefined**, the default value is used.<br>Modifying the animation type using [SymbolEffect](ts-basic-components-symbolGlyph.md#symboleffect12-2) and setting the animation effect using [effectStrategy](ts-basic-components-symbolGlyph.md#effectstrategy) are not supported.<br>**Decorator:** @Trace |

### constructor

constructor(config: ChipV2SymbolIconConfig)

A constructor used to create a **ChipV2SymbolIcon** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2SymbolIconConfig](#chipv2symboliconconfig) | Yes | Attribute configuration of the symbol icon, which is used to set the display attributes of the symbol icon in different states, including configuration options such as **normal** and **activated**. |

## ChipV2SymbolIconConfig

Defines the attribute configuration of the symbol icon.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| normal | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Icon settings in the inactive state.<br>Default value: no prefix icon or suffix icon is displayed. When the value is **undefined**, the default value is used.<br>Modifying the animation type using [SymbolEffect](ts-basic-components-symbolGlyph.md#symboleffect12-2) and setting the animation effect using [effectStrategy](ts-basic-components-symbolGlyph.md#effectstrategy) are not supported. |
| activated | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Icon settings in the active state.<br>Default value: **undefined**, which means no prefix icon or suffix icon is displayed. When the value is **undefined**, the default value is used.<br>Modifying the animation type using [SymbolEffect](ts-basic-components-symbolGlyph.md#symboleffect12-2) and setting the animation effect using [effectStrategy](ts-basic-components-symbolGlyph.md#effectstrategy) are not supported. |

## ChipV2PrefixSymbolIcon

Defines the prefix symbol icon class.

This API inherits from [ChipV2SymbolIcon](#chipv2symbolicon).

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### constructor

constructor(config: ChipV2PrefixSymbolIconConfig)

A constructor used to create a **ChipV2PrefixSymbolIcon** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2PrefixSymbolIconConfig](#chipv2prefixsymboliconconfig) | Yes | Attribute configuration of the prefix symbol icon, which is used to set the display attributes of the prefix symbol icon. This parameter inherits from **ChipV2SymbolIconConfig** and includes configuration options such as **normal** and **activated**. |

## ChipV2PrefixSymbolIconConfig

Defines the attribute configuration of the prefix symbol icon.

Inherits from [ChipV2SymbolIconConfig](#chipv2symboliconconfig).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

## ChipV2SuffixSymbolIcon

Defines the suffix symbol icon class.

This API inherits from [ChipV2SymbolIcon](#chipv2symbolicon).

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| normalAccessibility | [ChipV2Accessibility](#chipv2accessibility) | No | Yes | Accessibility attribute in the inactive state.<br>Default value: **undefined**, meaning no content is read aloud.<br>**Decorator:** @Trace |
| activatedAccessibility | [ChipV2Accessibility](#chipv2accessibility) | No | Yes | Accessibility attribute in the active state.<br>Default value: **undefined**, meaning no content is read aloud.<br>**Decorator:** @Trace |
| action | [VoidCallback](ts-types.md#voidcallback12) | No | Yes | Callback for the suffix icon tap event, which is triggered when the suffix icon is tapped.<br>Default value: no suffix icon event is set.<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |

### constructor

constructor(config: ChipV2SuffixSymbolIconConfig)

A constructor used to create a **ChipV2SuffixSymbolIcon** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2SuffixSymbolIconConfig](#chipv2suffixsymboliconconfig) | Yes | Attribute configuration of the suffix symbol icon, which is used to set the display attributes and accessibility features of the suffix symbol icon. This parameter inherits from **ChipV2SymbolIconConfig** and includes configuration options such as **normal**, **activated**, **normalAccessibility**, **activatedAccessibility**, and **action**. |

## ChipV2SuffixSymbolIconConfig

Defines the attribute configuration of the suffix symbol icon.

This API inherits from [ChipV2SymbolIconConfig](#chipv2symboliconconfig).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| normalAccessibility | [ChipV2AccessibilityConfig](#chipv2accessibilityconfig) | No | Yes | Accessibility attribute in the inactive state.<br>Default value: **undefined**, meaning no content is read aloud. |
| activatedAccessibility | [ChipV2AccessibilityConfig](#chipv2accessibilityconfig) | No | Yes | Accessibility attribute in the active state.<br>Default value: **undefined**, meaning no content is read aloud. |
| action | [VoidCallback](ts-types.md#voidcallback12) | No | Yes | Callback for the suffix icon tap event, which is triggered when the suffix icon is tapped.<br>Default value: no suffix icon event is set.<br>When the value is **undefined**, the default value is used. |

## ChipV2ImageIcon

Defines the base class of icon images.

This API inherits from [ChipV2Icon](#chipv2icon).

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
| src | [ResourceStr](ts-types.md#resourcestr) | No | No | Icon image or image address reference.<br>**Decorator:** @Trace |
| size | [SizeT](../js-apis-arkui-graphics.md#sizett12)\<[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)> | No | Yes | Icon size. Percentage values are not supported. If an invalid value is passed, the default value will be used.<br>Default value:<br>- When **ChipV2Options.size** is **ChipV2Size.SMALL**, the default value is **{width: $r('sys.float.chip_small_icon_size'), height: $r('sys.float.chip_small_icon_size')}**.<br>- When **ChipV2Options.size** is **ChipV2Size.NORMAL**, the default value is **{width: $r('sys.float.chip_normal_icon_size'), height: $r('sys.float.chip_normal_icon_size')}**.<br>Unit: vp<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| fillColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Icon fill color.<br>Default value: **$r('sys.color.chip_usually_icon_color')**. The default value is not applied to non-SVG images.<br>If the value is **undefined**, the default value is used.<br>This attribute takes effect only when the image format is SVG.<br>**Decorator:** @Trace |
| activatedFillColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Icon fill color when **ChipV2** is activated.<br>Default value: **$r('sys.color.chip_active_icon_color')**. The default value is not applied to non-SVG images.<br>If the value is **undefined**, the default value is used.<br>This attribute takes effect only when the image format is SVG.<br>**Decorator:** @Trace |
| modifier | [ImageModifier](ts-universal-attributes-attribute-modifier.md#custom-modifier) | No | Yes | Icon modifier, which is used to set common attributes of the icon. Pass this parameter when you need to dynamically modify icon attributes (such as **opacity** and **objectFit**) through the modifier. If this parameter is not passed or is **undefined**, the modifier is not applied, and the icon uses the default attribute settings.<br>Default value: **undefined**, meaning the modifier is not applied.<br>**Decorator:** @Trace |

### constructor

constructor(config: ChipV2ImageIconConfig)

A constructor used to create a **ChipV2ImageIcon** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2ImageIconConfig](#chipv2imageiconconfig) | Yes | Common icon attribute configuration, which is used to set the basic display attributes of the image icon, including configuration options such as **src**, **size**, **fillColor**, **activatedFillColor**. |

## ChipV2ImageIconConfig

Defines the common icon attribute configuration.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| src | [ResourceStr](ts-types.md#resourcestr) | No | No | Icon image or image address reference.<br>**Decorator:** @Trace |
| size | [SizeT](../js-apis-arkui-graphics.md#sizett12)\<[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)> | No | Yes | Icon size. Percentage values are not supported. If an invalid value is passed, the default value will be used.<br>Default value:<br>- When **ChipV2Options.size** is **ChipV2Size.SMALL**, the default value is **{width: $r('sys.float.chip_small_icon_size'), height: $r('sys.float.chip_small_icon_size')}**.<br>- When **ChipV2Options.size** is **ChipV2Size.NORMAL**, the default value is **{width: $r('sys.float.chip_normal_icon_size'), height: $r('sys.float.chip_normal_icon_size')}**.<br>Unit: vp<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| fillColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Icon fill color.<br>Default value: **$r('sys.color.chip_usually_icon_color')**. The default value is not applied to non-SVG images.<br>If the value is **undefined**, the default value is used.<br>This attribute takes effect only when the image format is SVG.<br>**Decorator:** @Trace |
| activatedFillColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | Yes | Icon fill color when **ChipV2** is activated.<br>Default value: **$r('sys.color.chip_active_icon_color')**. The default value is not applied to non-SVG images.<br>If the value is **undefined**, the default value is used.<br>This attribute takes effect only when the image format is SVG.<br>**Decorator:** @Trace |
| modifier | [ImageModifier](ts-universal-attributes-attribute-modifier.md#custom-modifier) | No | Yes | Icon modifier, which is used to set common attributes of the icon. Pass this parameter when you need to dynamically modify icon attributes (such as **opacity** and **objectFit**) through the modifier. If this parameter is not passed or is **undefined**, the modifier is not applied, and the icon uses the default attribute settings.<br>Default value: **undefined**, meaning the modifier is not applied.<br>**Decorator:** @Trace |

## ChipV2PrefixImageIcon

Defines the prefix icon class.

This API inherits from [ChipV2ImageIcon](#chipv2imageicon).

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

### constructor

constructor(config: ChipV2PrefixImageIconConfig)

A constructor used to create a **ChipV2PrefixImageIcon** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2PrefixImageIconConfig](#chipv2prefiximageiconconfig) | Yes | Attribute configuration of the prefix icon, which is used to set the display attributes of the prefix Image icon. This parameter inherits from **ChipV2ImageIconConfig** and includes configuration options such as **src**, **size**, and **fillColor**. |

## ChipV2PrefixImageIconConfig

Defines the attribute configuration of the prefix icon.

This API inherits from [ChipV2ImageIconConfig](#chipv2imageiconconfig).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

## ChipV2SuffixImageIcon

Defines the suffix icon class.

This API inherits from [ChipV2ImageIcon](#chipv2imageicon).

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
| accessibilityLevel | string | No | Yes | Accessibility level. This attribute controls whether the suffix icon can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: The attribute value of the current component is converted to **"yes"**.<br>**"yes"**: The current component can be recognized by accessibility services.<br>**"no"**: The current component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by accessibility services.<br>Default value: **"auto"**<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text. When a component has no text attribute, the screen reader does not read it aloud when this component is selected, making it difficult for users to identify the currently selected component. You can set accessibility text for such components so that the screen reader reads the text aloud, helping users identify the selected component.<br>Default value: empty string.<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description. This description is used to explain the current component to users in detail. You should provide comprehensive text descriptions to help users understand the actions to be performed and their consequences, especially when these consequences cannot be directly inferred from the component's attributes and accessibility text. When a component that is selected has both a text attribute and an accessibility description attribute, the system first reads the component's text attribute, followed by the accessibility description.<br>Default value: empty string.<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| action | [VoidCallback](ts-types.md#voidcallback12) | No | Yes | Callback for the suffix icon tap event. This callback is invoked when the suffix icon is tapped.<br>Default value: no suffix icon event is set.<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |

### constructor

constructor(config: ChipV2SuffixImageIconConfig)

A constructor used to create a **ChipV2SuffixImageIcon** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2SuffixImageIconConfig](#chipv2suffiximageiconconfig) | Yes | Attribute configuration of the suffix icon, which is used to set the display attributes, accessibility functions, and tap events of the suffix Image icon. This parameter inherits from **ChipV2ImageIconConfig** and **ChipV2AccessibilityConfig** and includes configuration options such as **src**, **size**, **accessibilityLevel**, and **action**. |

## ChipV2SuffixImageIconConfig

Defines the attribute configuration of the suffix icon.

This API inherits from [ChipV2ImageIconConfig](#chipv2imageiconconfig) and [ChipV2AccessibilityConfig](#chipv2accessibilityconfig).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name   | Type       | Read-only | Optional | Description               |
| ------ | ---------- | ---- | ------------------ | ------------------ |
| action | [VoidCallback](ts-types.md#voidcallback12) | No  | Yes  | Callback for the suffix icon tap event. Pass in this callback when you need to bind a tap event to the suffix icon and perform a custom operation (such as triggering a specific function or opening a dialog box). This callback is invoked when the suffix icon is tapped.<br>Default value: **undefined**, meaning no suffix icon event is set. When **undefined** or no value is passed, tapping the suffix icon triggers no custom response. |

## ChipV2CloseIcon

Defines the functional attribute class for the close icon of the **ChipV2** component, including accessibility attribute.

This API inherits from [ChipV2Accessibility](#chipv2accessibility).

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
| fontSize | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Size of the default close icon of the **ChipV2** component. Percentage values are not supported. If a percentage value is passed, the default value is used.<br>Default values:<br> When **size** is **ChipV2Size.SMALL**, the default value is `$r('sys.float.chip_small_font_size')`.<br> When **size** is not **ChipV2Size.SMALL**, the default value is `$r('sys.float.chip_normal_font_size')`.<br>Unit: fp<br>If the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |

### constructor

constructor(config: ChipV2CloseConfig)

A constructor used to create a **ChipV2CloseIcon** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2CloseConfig](#chipv2closeconfig) | Yes | Close icon configuration, which is used to customize the size and accessibility attribute of the close icon. This parameter inherits from **ChipV2AccessibilityConfig** and includes configuration options such as **fontSize**, **accessibilityText**, and **accessibilityDescription**. |

## ChipV2CloseConfig

Defines the functional attribute configuration for the close icon of the **ChipV2** component, including accessibility attribute.

This API inherits from [ChipV2AccessibilityConfig](#chipv2accessibilityconfig).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| fontSize | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | Yes | Size of the default close icon of the **ChipV2** component. Percentage values are not supported. If a percentage value is passed, the default value is used.<br>Default values:<br> When **size** is **ChipV2Size.SMALL**, the default value is `$r('sys.float.chip_small_font_size')`.<br> When **size** is not **ChipV2Size.SMALL**, the default value is `$r('sys.float.chip_normal_font_size')`.<br>Unit: fp<br>If the value is **undefined**, the default value is used. |

## ChipV2Accessibility

Defines the accessibility attribute class of **ChipV2**.

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
| accessibilityLevel | string | No | Yes | Accessibility level. This attribute controls whether the component can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: The attribute value of the current component is converted to **"yes"**.<br>**"yes"**: The current component can be recognized by accessibility services.<br>**"no"**: The current component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by accessibility services.<br>Default value: **"auto"**<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text. When a component has no text attribute, the screen reader does not read it aloud when this component is selected, making it difficult for users to identify the currently selected component. You can set accessibility text for such components so that the screen reader reads the text aloud, helping users identify the selected component.<br>Default value: empty string.<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description. This description is used to explain the current component to users in detail. You should provide comprehensive text descriptions to help users understand the actions to be performed and their consequences, especially when these consequences cannot be directly inferred from the component's attributes and accessibility text. When a component that is selected has both a text attribute and an accessibility description attribute, the system first reads the component's text attribute, followed by the accessibility description.<br>Default value: empty string.<br>When the value is **undefined**, the default value is used.<br>**Decorator:** @Trace |

### constructor

constructor(config: ChipV2AccessibilityConfig)

A constructor used to create a **ChipV2Accessibility** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| config | [ChipV2AccessibilityConfig](#chipv2accessibilityconfig) | Yes | Accessibility attribute configuration of the component, including configuration options such as **accessibilityText**, **accessibilityDescription**, and **accessibilityLevel**. |

## ChipV2AccessibilityConfig

Defines the accessibility attribute configuration.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Type | Read-only | Optional | Description |
| ------ | ---------- | ---- | ------------------ | ------------------ |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text. When a component has no text attribute, the screen reader does not read it aloud when this component is selected, making it difficult for users to identify the currently selected component. You can set accessibility text for such components so that the screen reader reads the text aloud, helping users identify the selected component.<br>Default value: empty string.<br>When the value is **undefined**, the default value is used. |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description. This description is used to explain the current component to users in detail. You should provide comprehensive text descriptions to help users understand the actions to be performed and their consequences, especially when these consequences cannot be directly inferred from the component's attributes and accessibility text. When a component that is selected has both a text attribute and an accessibility description attribute, the system first reads the component's text attribute, followed by the accessibility description.<br>Default value: empty string.<br>When the value is **undefined**, the default value is used. |
| accessibilityLevel | string | No | Yes | Accessibility level. This attribute controls whether the component can be recognized by accessibility services.<br>Supported values:<br>**"auto"**: The attribute value of the current component is converted to **"yes"**.<br>**"yes"**: The current component can be recognized by accessibility services.<br>**"no"**: The current component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by accessibility services.<br>Default value: **"auto"**<br>When the value is **undefined**, the default value is used. |

## ChipV2Size

Defines the size type that can be specified for the **ChipV2** component, such as a normal **ChipV2**.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name   | Value    | Description              |
| ------ | -------- | ------------------------ |
| NORMAL | 'NORMAL' | Normal **ChipV2**.     |
| SMALL  | 'SMALL'  | Small **ChipV2**.      |

## ChipV2AccessibilitySelectedType

Defines the selected state types that can be specified for **ChipV2**. This API is used to control how the accessibility service conveys the selected state of the component to users. Different selected state types provide different semantics and user experiences.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name | Value | Description |
| ---- | -- | ---- |
| CLICKED | 0 | Click type. The component does not report any selected state to the accessibility service and is used only as a clickable component. This is suitable for scenarios where an action is performed but no state is maintained, such as a regular button. |
| CHECKED | 1 | Check type. The component reports its selected state to the accessibility service through the [accessibilityChecked](ts-universal-attributes-accessibility.md#accessibilitychecked13) attribute. This is suitable for multi-select scenarios, such as tag filtering and attribute selection.|
| SELECTED | 2 | Select type. The component reports its selected state to the accessibility service through the [accessibilitySelected](ts-universal-attributes-accessibility.md#accessibilityselected13) attribute. This is suitable for scenarios indicating the currently selected item, such as navigation bar tabs and single-select list items.|

## Example

### Example 1: Setting a Custom Icon

This example sets custom icons through the **prefixIcon** and **suffixIcon** attributes of [ChipV2Options](#chipv2options).

Since API version 26.0.0, **ChipV2Options** supports the prefixIcon and suffixIcon attributes.

```ts
import { ChipV2, ChipV2Options, ChipV2Label, ChipV2PrefixImageIcon, ChipV2SuffixImageIcon, LengthMetrics, ColorMetrics } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  build() {
    Column({ space: 10 }) {
      ChipV2({
        chipV2Options: new ChipV2Options({
          // Set the prefix icon attribute.
          prefixIcon: new ChipV2PrefixImageIcon({
            // Replace 'app.media.chips' with your actual icon resource.
            src: $r('app.media.chips'),
            size: { width: LengthMetrics.fp(16), height: LengthMetrics.fp(16) },
            fillColor: ColorMetrics.resourceColor(Color.Red)
          }),
          // Set the text attribute.
          label: new ChipV2Label({
            text: 'Chip',
            fontSize: LengthMetrics.fp(12),
            fontColor: ColorMetrics.resourceColor(Color.Blue),
            fontFamily: 'HarmonyOS Sans',
            labelMargin: { left: LengthMetrics.fp(20), right: LengthMetrics.fp(30) }
          }),
          // Set the suffix icon attribute.
          suffixIcon: new ChipV2SuffixImageIcon({
            // Replace 'app.media.close' with your actual icon resource.
            src: $r('app.media.close'),
            size: { width: LengthMetrics.fp(16), height: LengthMetrics.fp(16) },
            fillColor: ColorMetrics.resourceColor(Color.Red)
          }),
          size: { width: LengthMetrics.fp(160), height: LengthMetrics.fp(36) },
          enabled: true,
          backgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_button_normal')),
          borderRadius: LengthMetrics.resource($r('sys.float.ohos_id_corner_radius_button')),
          minFontScale: 0.2,
          maxFontScale: 2,
          padding: {
            start: LengthMetrics.fp(20),
            end: LengthMetrics.fp(20)
          },
          fontSize: LengthMetrics.fp(12)
        })
      })
    }
  }
}
```

![](figures/chipv2_1.png)

### Example 2: Setting the Active State of ChipV2

This example sets the active state of [ChipV2](#chipv2-1) through the **activated** attribute of [ChipV2Options](#chipv2options).

Since API version 26.0.0, **ChipV2Options** supports the **activated** attribute.

```ts
import { ChipV2, ChipV2Options, ChipV2Label, ChipV2PrefixImageIcon, ChipV2CloseIcon, LengthMetrics, ColorMetrics } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local isActivated: boolean = false;

  build() {
    Column({ space: 10 }) {
      ChipV2({
        chipV2Options: new ChipV2Options({
          // Set the prefix icon attribute.
          prefixIcon: new ChipV2PrefixImageIcon({
            // Replace 'app.media.icon' with your actual icon resource.
            src: $r('app.media.chips'),
            size: { width: LengthMetrics.fp(16), height: LengthMetrics.fp(16) },
            fillColor: ColorMetrics.resourceColor(Color.Blue),
            activatedFillColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary_contrary'))
          }),
          // Set the text attribute.
          label: new ChipV2Label({
            text: 'Chip',
            fontSize: LengthMetrics.fp(12),
            fontColor: ColorMetrics.resourceColor(Color.Blue),
            activatedFontColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary_contrary')),
            fontFamily: 'HarmonyOS Sans',
            labelMargin: { left: LengthMetrics.fp(20), right: LengthMetrics.fp(30) }
          }),
          size: { width: LengthMetrics.fp(160), height: LengthMetrics.fp(36) },
          allowClose: true,
          enabled: true,
          activated: this.isActivated,
          backgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_button_normal')),
          activatedBackgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_emphasize')),
          borderRadius: LengthMetrics.resource($r('sys.float.ohos_id_corner_radius_button')),
          closeIcon: new ChipV2CloseIcon({
            fontSize: LengthMetrics.fp(12)
          }),
          onClose: () => {
            console.info('chip on close');
          },
          onClicked: () => {
            console.info('chip on clicked');
          }
        })
      })
      // Tap "Change active state" to activate and deactivate ChipV2.
      Button('Change active state')
        .onClick(() => {
          this.isActivated = !this.isActivated;
        })
    }
  }
}
```

![](figures/chipv2_2.gif)

### Example 3: Setting a Symbol Icon

This example uses [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) to set a symbol icon for [ChipV2](#chipv2-1).

Since API version 26.0.0, **ChipV2** is introduced.

```ts
import { ChipV2, ChipV2Options, ChipV2Label, ChipV2PrefixSymbolIcon, SymbolGlyphModifier, LengthMetrics, ColorMetrics } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local isActivated: boolean = false;

  build() {
    Column({ space: 10 }) {
      ChipV2({
        chipV2Options: new ChipV2Options({
          // Set the prefix symbol icon attribute.
          prefixIcon: new ChipV2PrefixSymbolIcon({
            normal: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontSize(16).fontColor([Color.Green]),
            activated: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontSize(16).fontColor([Color.Red]),
          }),
          // Set the text attribute.
          label: new ChipV2Label({
            text: 'Chip',
            fontSize: LengthMetrics.fp(12),
            fontColor: ColorMetrics.resourceColor(Color.Blue),
            activatedFontColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_text_primary_contrary')),
            fontFamily: 'HarmonyOS Sans',
            labelMargin: { left: LengthMetrics.fp(20), right: LengthMetrics.fp(30) },
          }),
          size: { width: LengthMetrics.fp(160), height: LengthMetrics.fp(36) },
          allowClose: true,
          enabled: true,
          activated: this.isActivated,
          backgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_button_normal')),
          activatedBackgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_emphasize')),
          borderRadius: LengthMetrics.resource($r('sys.float.ohos_id_corner_radius_button')),
          onClose: () => {
            console.info('chip on close');
          },
          onClicked: () => {
            console.info('chip on clicked');
          }
        })
      })

      Button('Change active state')
        .onClick(() => {
          this.isActivated = !this.isActivated;
        })
    }
  }
}
```

![](figures/chipv2_3.gif)

### Example 4: Listening for Internal Attribute Changes of Object-Type Attributes in ChipV2Options

[ChipV2Options](#chipv2options) uses the @ObservedV2 decorator, and the [ChipV2](#chipv2-1) component receives the **ChipV2Options** object through **@Param**. For primitive type attributes decorated by **@Trace**, **@Param** can already observe attribute changes and trigger UI refresh. However, for internal attributes (such as **start** and end of **padding**) of object-type attributes (such as **padding** and **labelMargin** of **label**), these object types themselves are not decorated by **@ObservedV2**. Therefore, changes to their internal attributes cannot be perceived by **@Param**, and the UI is not automatically refreshed when internal attributes are changed. Using [makeObserved](../js-apis-stateManagement.md#makeobserved) to wrap object-type attributes (such as **padding**) can supplement deep observation capability for their internal attributes. In this way, when internal attributes (such as **start** and **end**) are changed, the framework can listen for the changes and trigger UI refresh. For detailed description of the **makeObserved** API, see [makeObserved API: Changing Unobservable Data to Observable Data](../../../ui/state-management/arkts-new-makeObserved.md).

The following example uses **makeObserved** to wrap **padding**, and changes the **start** and **end** attributes of **padding** through a button, to verify that changes to internal attributes of object-type attributes can trigger UI refresh of **ChipV2**.

```ts
import { ChipV2, ChipV2Options, ChipV2Label, LengthMetrics, ColorMetrics, UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local chipV2Options: ChipV2Options = new ChipV2Options({
    // Set the text attribute.
    label: new ChipV2Label({ text: 'Chip' }),
    // Use UIUtils.makeObserved to wrap padding so that the internal attributes start and end are observable.
    padding: UIUtils.makeObserved({ start: LengthMetrics.fp(20), end: LengthMetrics.fp(20) }),
    backgroundColor: ColorMetrics.resourceColor($r('sys.color.ohos_id_color_button_normal')),
    borderRadius: LengthMetrics.resource($r('sys.float.ohos_id_corner_radius_button')),
    enabled: true,
  });
  @Local currentPadding: number = 20;

  build() {
    Column({ space: 10 }) {
      ChipV2({ chipV2Options: this.chipV2Options })
      Button('Change padding')
        .onClick(() => {
          if (this.chipV2Options.padding) {
            this.currentPadding = this.currentPadding === 20 ? 10 : 20;
            // Change the internal attributes of padding. The UI is automatically refreshed because padding is wrapped with makeObserved.
            this.chipV2Options.padding.start = LengthMetrics.fp(this.currentPadding);
            this.chipV2Options.padding.end = LengthMetrics.fp(this.currentPadding);
          }
        })
    }
    .padding(20)
  }
}
```

![chipv2-sample4](figures/chipv2-make-observed.gif)
<!--no_check-->