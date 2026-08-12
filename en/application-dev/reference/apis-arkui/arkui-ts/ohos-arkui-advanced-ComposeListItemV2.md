# ComposeListItemV2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangrunsen-->
<!--Designer: @YanSanzo-->
<!--Tester: @ybhou1993-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=5b2459a0f5dab332a77eeb8a1ae596067198b6bc translatedAt=2026-07-23T02:30:51.108Z pushedAt=2026-07-24T01:55:58.481Z -->

The **ComposeListItemV2** component is used to display a series of list items with the same width, suitable for presenting continuous, multi-row combinations of similar data (such as images and text).

This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), state management V2 delivers enhanced capabilities for deep observation and management of data objects, and is no longer limited to the component level. With state management V2, you can more flexibly control the data and state of list items through this component, achieving more efficient UI refresh.

> **NOTE**
>
> - This component can only be used in the stage model.
>
> - If [universal attributes](ts-component-general-attributes.md) and [universal events](ts-component-general-events.md) are set for **ComposeListItemV2**, the compilation toolchain will generate an additional node __Common__ and mount the universal attributes or universal events on __Common__, rather than directly applying them to **ComposeListItemV2** itself. This may cause the set universal attributes or universal events to not take effect or behave unexpectedly. Therefore, it is not recommended to set universal attributes and universal events on **ComposeListItemV2**.

**Since:** 26.0.0

## Modules to Import

```ts
import { ComposeListItemV2, IconTypeV2, ContentItemV2, OperateItemV2 } from "@kit.ArkUI";
```

## Child Components

None

## ComposeListItemV2

ComposeListItemV2({ contentItemV2?: ContentItemV2, operateItemV2?: OperateItemV2 })

Defines the left element, middle element, and right display content of the list item.

**Since:** 26.0.0

**Decorator:** @ComponentV2

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Mandatory | Decorator Type | Description |
| -------- | -------- | -------- | -------- | -------- |
| contentItemV2 | [ContentItemV2](#contentitemv2) | No | \@Param | Left and middle elements of the list item. |
| operateItemV2 | [OperateItemV2](#operateitemv2) | No | \@Param | Right element of the list item. |

## ContentItemV2

Defines the left icon, icon size, and middle element text content displayed in the list item.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Decorator:** @ObservedV2

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- |---|----|-------------|
| iconStyle | [IconTypeV2](#icontypev2) | No | Yes | Icon style of the left element.<br/>This attribute is not set or set to **undefined** by default, meaning the icon resource is not displayed.<br>**Decorator:** @Trace |
| icon | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Icon resource of the left element.<br/>This attribute is not set or set to **undefined** by default, meaning the icon resource is not displayed.<br>**Decorator:** @Trace |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol icon resource of the left element, which takes precedence over **icon**. If both **icon** and **symbolStyle** are set, only the symbol icon is displayed.<br/>This attribute is not set or set to **undefined** by default, meaning the symbol icon is not displayed.<br>**Decorator:** @Trace |
| primaryText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Title content of the middle element.<br/>This attribute is not set or set to **undefined** by default, meaning the title is not displayed.<br/>**Text processing rule:** Text is displayed with unlimited line wrap when it overflows.<br>**Decorator:** @Trace |
| secondaryText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Subtitle content of the middle element.<br/>This attribute is not set or set to **undefined** by default, meaning the subtitle is not displayed.<br/>**Text processing rule:** Text is displayed with unlimited line wrap when it overflows.<br>**Decorator:** @Trace |
| description | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Description content of the middle element.<br/>This attribute is not set or set to **undefined** by default, meaning the description is not displayed.<br/>**Text processing rule:** Text is displayed with unlimited line wrap when it overflows.<br>**Decorator:** @Trace |

### constructor

constructor(options?: ContentItemV2Options)

A constructor used to create a **ContentItemV2** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| options | [ContentItemV2Options](#contentitemv2options) | No | Configuration of the left element of the list item. |

## ContentItemV2Options

Defines the options for the **ContentItemV2** constructor.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| iconStyle | [IconTypeV2](#icontypev2) | No | Yes | Icon style of the left element. |
| icon | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Icon resource of the left element. |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol icon resource of the left element. |
| primaryText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Title content of the middle element. |
| secondaryText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Subtitle content of the middle element. |
| description | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Description content of the middle element. |

## IconTypeV2

Enumerates icon types for the left element of list items.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Value | Description |
| -------- | -------- | -------- |
| BADGE | 1 | Badge icon, sized 8 × 8 vp. |
| NORMAL_ICON | 2 | Normal icon, sized 16 × 16 vp. |
| SYSTEM_ICON | 3 | System icon, sized 24 × 24 vp. |
| HEAD_SCULPTURE | 4 | Head sculpture icon, sized 40 × 40 vp. |
| APP_ICON | 5 | Application icon, sized 64 × 64 vp. |
| PREVIEW | 6 | Preview icon, sized 96 × 96 vp. |
| LONGITUDINAL | 7 | Icon of special horizontal ratio (width greater than height), with the longest side kept at 96 vp. |
| VERTICAL | 8 | Icon of special vertical ratio (height greater than width), with the longest side kept at 96 vp. |

## OperateItemV2

Defines the element types for the right element of list items.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Decorator:** @ObservedV2

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- |---|---|-----------------|
| arrow | [OperateIconV2](#operateiconv2) | No | Yes | Arrow, sized 12 × 24 vp.<br/>By default, this attribute is not set or set to **undefined**, and the arrow is not displayed.<br>**Decorator:** @Trace |
| icon | [OperateIconV2](#operateiconv2) | No | Yes | First icon, sized 24 × 24 vp.<br/>By default, this attribute is not set or set to **undefined**, and the icon is not displayed.<br>**Decorator:** @Trace |
| subIcon | [OperateIconV2](#operateiconv2) | No | Yes | Second icon, sized 24 × 24 vp.<br/>By default, this attribute is not set or set to **undefined**, and the second icon is not displayed.<br>**Decorator:** @Trace |
| button | [OperateButtonV2](#operatebuttonv2) | No | Yes | Button.<br/>By default, this attribute is not set or set to **undefined**, and the button is not displayed.<br>**Decorator:** @Trace |
| toggle | [OperateCheckV2](#operatecheckv2) | No | Yes | Toggle.<br/>By default, this attribute is not set or set to **undefined**, and the toggle is not displayed.<br>**Decorator:** @Trace |
| checkbox | [OperateCheckV2](#operatecheckv2) | No | Yes | Checkbox, sized 24 × 24 vp.<br/>By default, this attribute is not set or set to **undefined**, and the checkbox is not displayed.<br>**Decorator:** @Trace |
| radio | [OperateCheckV2](#operatecheckv2) | No | Yes | Radio button, sized 24 × 24 vp.<br/>By default, this attribute is not set or set to **undefined**, and the radio button is not displayed.<br>**Decorator:** @Trace |
| image | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Image, sized 48 × 48 vp.<br/>By default, this attribute is not set or set to **undefined**, and the image is not displayed.<br>**Decorator:** @Trace |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol icon resource, sized 48 × 48 vp.<br/>By default, this attribute is not set or set to **undefined**, and the symbol icon is not displayed.<br>**Decorator:** @Trace |
| text | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Text.<br/>By default, this attribute is not set or set to **undefined**, and the text is not displayed.<br>**Decorator:** @Trace |

### constructor

constructor(options?: OperateItemV2Options)

A constructor used to create an **OperateItemV2** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| options | [OperateItemV2Options](#operateitemv2options) | No | Configuration of the right element of the list item. |

## OperateItemV2Options

Defines the options for the **OperateItemV2** constructor.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The device types actually supported by this API (phones, 2-in-1 devices, tablets, and TVs) are a subset of those supported by its system capability (phones, 2-in-1 devices, tablets, TVs, and wearables). Due to hardware limitations, calling this API on wearable devices will result in an exception, with the error message indicating that the API is undefined.

| Name | Type | Read Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| arrow | [OperateIconV2](#operateiconv2) | No | Yes | The right element of the list item is an arrow. |
| icon | [OperateIconV2](#operateiconv2) | No | Yes | First icon of the right element of the list item. |
| subIcon | [OperateIconV2](#operateiconv2) | No | Yes | Second icon of the right element of the list item. |
| button | [OperateButtonV2](#operatebuttonv2) | No | Yes | The right element of the list item is a button. |
| toggle | [OperateCheckV2](#operatecheckv2) | No | Yes | The right element of the list item is a toggle. |
| checkbox | [OperateCheckV2](#operatecheckv2) | No | Yes | The right element of the list item is a checkbox. |
| radio | [OperateCheckV2](#operatecheckv2) | No | Yes | The right element of the list item is a radio button. |
| image | [ResourceStr](ts-types.md#resourcestr) | No | Yes | The right element of the list item is an image. |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | The right element of the list item is a Symbol icon resource. |
| text | [ResourceStr](ts-types.md#resourcestr) | No | Yes | The right element of the list item is text. |

## OperateIconV2

Defines the type of the right icon element of the list item.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Decorator:** @ObservedV2

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- |---|---|------------------|
| value | [ResourceStr](ts-types.md#resourcestr) | No | No | Icon or arrow resource.<br>**Decorator:** @Trace |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol icon or arrow resource, which takes precedence over **value**.<br/>By default, this attribute is not set or is set to **undefined**, and the symbol icon is not displayed.<br>**Decorator:** @Trace |
| action | [OnActionCallback](#onactioncallback) | No | Yes | Tap event of the icon or arrow.<br>**Decorator:** @Trace |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text of the icon or arrow. When a component does not contain a text attribute, the screen reader does not announce it upon selection, leaving users unaware of which component is currently selected. To address this issue, you can set accessibility text for components that do not contain text information. When the screen reader selects such a component, it announces the content of the accessibility text, helping users clearly identify the selected component.<br/>Default value: **""**<br>**Decorator:** @Trace |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the icon or arrow. This description is used to explain the current component to users in detail. You should provide a relatively detailed text description for this attribute to help users understand the action to be performed and its possible consequences, especially when such consequences cannot be directly inferred from the component's attributes and accessibility text. If a component that is selected has both a text attribute and an accessibility description attribute, the system first announces the text attribute and then the content of the accessibility description attribute.<br/>Default value: **"Double-tap with one finger to execute."**<br>**Decorator:** @Trace |
| accessibilityLevel | string | No | Yes | Accessibility level of the icon or arrow. This attribute controls whether the current item can be recognized by accessibility services.<br/>Supported values:<br/>**"auto"**: The attribute value of the current component is converted to **"no"**.<br/>**"yes"**: The current component can be recognized by accessibility services.<br/>**"no"**: The current component cannot be recognized by accessibility services.<br/>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by accessibility services.<br/>Default value: **"auto"**<br>**Decorator:** @Trace |

### constructor

constructor(options?: OperateIconV2Options)

A constructor used to create an **OperateIconV2** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| options | [OperateIconV2Options](#operateiconv2options) | No | Configuration of the right icon element of the list item. |

## OperateIconV2Options

Defines options for the **OperateIconV2** constructor.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Icon or arrow resource. |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol icon or arrow resource. |
| action | [OnActionCallback](#onactioncallback) | No | Yes | Tap event of the icon or arrow. |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text of the icon or arrow. When a component does not contain a text attribute, the screen reader does not announce it upon selection, leaving users unaware of which component is currently selected. To address this scenario, developers can set accessibility text for components that do not contain text information. When the screen reader selects such a component, it announces the content of the accessibility text, helping screen reader users clearly identify the selected component.<br/>Default value: **""** |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the icon or arrow. This description is used to explain the current component to users in detail. You should provide a relatively detailed text description for this attribute to help users understand the action to be performed and its possible consequences, especially when such consequences cannot be directly inferred from the component's attributes and accessibility text. If a component that is selected has both a text attribute and an accessibility description attribute, the system first announces the text attribute and then the content of the accessibility description attribute.<br/>Default value: **"Double-tap with one finger to execute."** |
| accessibilityLevel | string | No | Yes | Accessibility level of the icon or arrow. This attribute controls whether the current item can be recognized by accessibility services.<br/>Supported values:<br/>**"auto"**: The attribute value of the current component is converted to **"no"**.<br/>**"yes"**: The current component can be recognized by accessibility services.<br/>**"no"**: The current component cannot be recognized by accessibility services.<br/>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by accessibility services.<br/>Default value: **"auto"** |

## OperateButtonV2

Defines the type of the right button element of the list item.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Decorator:** @ObservedV2

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- |---|---|-------------------|
| text | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Button text.<br/>Default value: **""**<br>**Decorator:** @Trace |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text of the button. When a component does not contain a text attribute, the screen reader does not announce it upon selection, leaving users unaware of which component is currently selected. To address this issue, you can set accessibility text for components that do not contain text information. When the screen reader selects such a component, it announces the content of the accessibility text, helping screen reader users clearly identify the selected component.<br/>Default value: **""**<br>**Decorator:** @Trace |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the button. This description is used to explain the current component to users in detail. You should provide a relatively detailed text description for this attribute to help users understand the action to be performed and its possible consequences, especially when such consequences cannot be directly inferred from the component's attributes and accessibility text. If a component that is selected has both a text attribute and an accessibility description attribute, the system first announces the text attribute and then the content of the accessibility description attribute.<br/>Default value: **"Double-tap with one finger to execute."**<br>**Decorator:** @Trace |
| accessibilityLevel | string | No | Yes | Accessibility level of the button. This attribute controls whether the current item can be recognized by accessibility services.<br/>Supported values:<br/>**"auto"**: The attribute value of the current component is converted to **"no"**.<br/>**"yes"**: The current component can be recognized by accessibility services.<br/>**"no"**: The current component cannot be recognized by accessibility services.<br/>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by accessibility services.<br/>Default value: **"auto"**<br>**Decorator:** @Trace |

### constructor

constructor(options?: OperateButtonV2Options)

A constructor used to create a **OperateButtonV2** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| options | [OperateButtonV2Options](#operatebuttonv2options) | No | Configuration of the right button element of the list item. |

## OperateButtonV2Options

Defines options for the **OperateButtonV2** constructor.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| text | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Button text. |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text of the button. When a component does not contain a text attribute, the screen reader does not announce it upon selection, leaving users unaware of which component is currently selected. To address this scenario, developers can set accessibility text for components that do not contain text information. When the screen reader selects such a component, it announces the content of the accessibility text, helping screen reader users clearly identify the selected component.<br/>Default value: **""** |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the button. This description is used to explain the current component to users in detail. Developers should provide a relatively detailed text description for this attribute to help users understand the action to be performed and its possible consequences, especially when such consequences cannot be directly inferred from the component's attributes and accessibility text alone. If a component has both a text attribute and an accessibility description attribute, the system first announces the text attribute and then the content of the accessibility description attribute when the component is selected.<br/>Default value: **"Double-tap with one finger to execute."** |
| accessibilityLevel | string | No | Yes | Accessibility importance of the button. This attribute controls whether the current item can be recognized by accessibility services.<br/>Supported values:<br/>**"auto"**: The current component is converted to **"no"**.<br/>**"yes"**: The current component can be recognized by accessibility services.<br/>**"no"**: The current component cannot be recognized by accessibility services.<br/>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by accessibility services.<br/>Default value: **"auto"** |

## OperateCheckV2

Defines the **Switch**, **CheckBox**, and **Radio** types for the right element of the list item. You can set the corresponding attribute based on the type.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Decorator:** @ObservedV2

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description              |
| -------- | -------- |---|----|--------------|
| isCheck | boolean | No | Yes | Whether the right element Switch, CheckBox, or Radio of the list item is selected.<br> The default value of **isCheck** is **false**.<br> The value **true** indicates selected.<br> The value **false** indicates not selected.<br>**Decorator:** @Trace   |
| onChange | [OnChangeCallback](#onchangecallback) | No | Yes | Callback triggered when the selection state of the right element Switch, CheckBox, or Radio of the list item changes.<br> The value **true** indicates that the state changes from not selected to selected.<br> The value **false** indicates that the state changes from selected to not selected.<br>**Decorator:** @Trace   |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text of the right element Switch, CheckBox, or Radio of the list item. When a component does not contain a text attribute, the screen reader does not announce it upon selection, leaving users unaware of which component is currently selected. To address this, you can set accessibility text for components without text information. When the screen reader selects such a component, it announces the accessibility text, helping screen reader users clearly identify the selected component.<br/>Default value: **""**<br>**Decorator:** @Trace   |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the right element Switch, CheckBox, or Radio of the list item. This description is used to explain the current component to users in detail. You should provide a relatively detailed text description for this attribute to help users understand the operation to be performed and its possible consequences, especially when such consequences cannot be directly inferred from the component's attributes and accessibility text. If a component that is selected has both a text attribute and an accessibility description attribute, the system first announces the text attribute, followed by the accessibility description.<br/>By default, the announcement rules of the base components **Switch**, **CheckBox**, and **Radio** are followed.<br>**Decorator:** @Trace |
| accessibilityLevel | string | No | Yes | Accessibility level of the right element Switch, CheckBox, or Radio of the list item. This attribute controls whether the current item can be recognized by accessibility services.<br/>Supported values:<br/>**"auto"**: The attribute value of the component is converted to **"no"**.<br/>**"yes"**: The component can be recognized by accessibility services.<br/>**"no"**: The component cannot be recognized by accessibility services.<br/>**"no-hide-descendants"**: The component and all its child components cannot be recognized by accessibility services.<br/>Default value: **"auto"**<br>**Decorator:** @Trace |

### constructor

constructor(options?: OperateCheckV2Options)

A constructor used to create an **OperateCheckV2** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| options | [OperateCheckV2Options](#operatecheckv2options) | No | Configuration of the right element **Switch**, **CheckBox**, or **Radio** of the list item. |

## OperateCheckV2Options

Defines options for the **OperateCheckV2** constructor.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Readonly | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| isCheck | boolean | No | Yes | Whether the right element **Switch**, **CheckBox**, or **Radio** of the list item is selected. |
| onChange | [OnChangeCallback](#onchangecallback) | No | Yes | Callback triggered when the selection state of the right element **Switch**, **CheckBox**, or **Radio** of the list item changes. |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text of the right element **Switch**, **CheckBox**, or **Radio** of the list item. When a component does not contain a text attribute, the screen reader does not announce it upon selection, leaving users unaware of which component is currently selected. To address this, you can set accessibility text for components without text information. When the screen reader selects such a component, it announces the accessibility text, helping screen reader users clearly understand which component they have selected.<br/>Default value: **""** |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the right element **Switch**, **CheckBox**, or **Radio** of the list item. This description is used to explain the current component to users in detail. You should provide a relatively detailed text description for this attribute to help users understand the operation to be performed and its possible consequences, especially when such consequences cannot be directly inferred from the component's attributes and accessibility text. If a component that is selected has both a text attribute and an accessibility description attribute, the system first announces the text attribute, followed by the accessibility description.<br/>By default, the announcement rules of the base components **Switch**, **CheckBox**, and **Radio** are followed. |
| accessibilityLevel | string | No | Yes | Accessibility level of the right element **Switch**, **CheckBox**, or **Radio** of the list item. This attribute controls whether the current component can be recognized by accessibility services.<br/>Supported values:<br/>**"auto"**: The attribute value of the component is converted to **"no"**.<br/>**"yes"**: The component can be recognized by accessibility services.<br/>**"no"**: The component cannot be recognized by accessibility services.<br/>**"no-hide-descendants"**: The component and all its child components cannot be recognized by accessibility services.<br/>Default value: **"auto"** |

## OnActionCallback

type OnActionCallback = () => void

Defines the callback triggered for the tap event of the right icon or arrow of the list item.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phones, PCs/2-in-1 devices, tablets, and TVs) are fewer than those supported by its system capability (phones, PCs/2-in-1 devices, tablets, TVs, and wearables). Due to hardware limitations, calling this API on wearable devices will result in an exception, with the error message indicating that the API is undefined.

## OnChangeCallback

type OnChangeCallback = (value: boolean) => void

Defines the callback triggered when the state of the right element **Switch**, **CheckBox**, or **Radio** of the list item changes.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name  | Type      | Mandatory | Description                                                         |
| ------- | --------- | ---- | ------------------------------------------------------------ |
| value | boolean   | Yes   | Callback triggered when the selection state of the right element **Switch**, **CheckBox**, or **Radio** element of the list item changes.<br>The value **true** indicates that the state changes from unselected to selected.<br>The value **false** indicates that the state changes from selected to unselected. |

## Events

[Universal events](ts-component-general-events.md) are not supported.

## Example

### Example 1: Setting a Simple List Item

Since API version 26.0.0, a simple list item with a primary title, secondary title, description, right button, and text can be implemented through the **ComposeListItemV2** component API.

```ts
// This example demonstrates the basic functionality of this component, including left and right elements.
import { IconTypeV2, ComposeListItemV2, ContentItemV2, OperateItemV2, OperateIconV2 } from '@kit.ArkUI';

@Entry
@ComponentV2
struct ComposeListItemV2Example {
  build(): void {
    Column() {
      List() {
        ListItem() {
          ComposeListItemV2({
            contentItemV2: new ContentItemV2({
              iconStyle: IconTypeV2.NORMAL_ICON,
              icon: $r('sys.media.ohos_app_icon'),
              primaryText: 'Two-line list',
              secondaryText: 'Secondary text',
              description: 'Description text'
            }),
            operateItemV2: new OperateItemV2({
              icon: new OperateIconV2({
                value: $r('sys.media.ohos_app_icon'),
                action: () => {
                  this.getUIContext().getPromptAction().showToast({
                    message: 'icon'
                  });
                }
              }),
              text: 'Right text'
            })
          })
        }
      }
    }
  }
}
```

![Example 1 - ComposeListItemV2 left and right elements + text](figures/image-composelistitemv2-demo-01.jpg)

### Example 2: Setting Custom Announcements for Different Right Elements of the List Item

Since API version 26.0.0, custom screen reader announcement text can be implemented for the right icons, buttons, and radio buttons of a list item by setting the **accessibilityText**, **accessibilityDescription**, and **accessibilityLevel** attributes.

```ts
import {
  IconTypeV2,
  ComposeListItemV2,
  ContentItemV2,
  OperateItemV2,
  OperateCheckV2,
  OperateButtonV2,
  OperateIconV2
} from '@kit.ArkUI';

@Entry
@ComponentV2
struct ComposeListItemV2Example {
  build(): void {
    Column() {
      List() {
        ListItem() {
          ComposeListItemV2({
            contentItemV2: new ContentItemV2({
              iconStyle: IconTypeV2.NORMAL_ICON,
              icon: $r('sys.media.ohos_app_icon'),
              primaryText: 'Two-line list',
              secondaryText: 'Secondary text',
              description: 'Description text'
            }),
            operateItemV2: new OperateItemV2({
              radio: new OperateCheckV2({
                accessibilityText: 'Radio button', // The screen reader announces 'radio button' for this radio button.
                accessibilityDescription: 'Unselected', // The screen reader announces this radio button as 'unselected'.
                accessibilityLevel: 'yes'  // This item can be focused by the accessibility screen reader.
              })
            })
          })
        }

        ListItem() {
          ComposeListItemV2({
            contentItemV2: new ContentItemV2({
              iconStyle: IconTypeV2.NORMAL_ICON,
              icon: $r('sys.media.ohos_app_icon'),
              primaryText: 'Two-line list',
              secondaryText: 'Secondary text',
              description: 'Description text'
            }),
            operateItemV2: new OperateItemV2({
              button: new OperateButtonV2({
                text: 'OK',
                accessibilityText: 'This is a button',
                accessibilityDescription: 'Double-tap to activate',
                accessibilityLevel: 'no'  // This button cannot be recognized by the screen reader service.
              })
            })
          })
        }

        ListItem() {
          ComposeListItemV2({
            contentItemV2: new ContentItemV2({
              iconStyle: IconTypeV2.NORMAL_ICON,
              icon: $r('sys.media.ohos_app_icon'),
              primaryText: 'Two-line list',
              secondaryText: 'Secondary text',
              description: 'Description text'
            }),
            operateItemV2: new OperateItemV2({
              icon: new OperateIconV2({
                value: $r('sys.media.ohos_app_icon'),
                action: () => {
                  this.getUIContext().getPromptAction().showToast({
                    message: 'icon'
                  });
                },
                accessibilityText: 'This is an icon', // The screen reader announcement text for this icon is 'This is an icon.'
                accessibilityDescription: 'Double tap to open more options', // The screen reader announcement description for this icon is 'Double tap to open more options.'
                accessibilityLevel: 'yes'  // This item can be focused by the accessibility screen reader.
              })
            })
          })
        }
      }
    }
  }
}
```

![Example 2 - ComposeListItemV2: Setting custom announcement for right elements of a list item](figures/image-composelistitemv2-demo-02.png)

### Example 3: Setting Symbol Icons

Since API version 26.0.0, you can set symbol icon parameters through the attribute API **symbolStyle** of **ContentItemV2**, **OperateItemV2**, and **OperateIconV2**.

```ts
import {
  IconTypeV2,
  ComposeListItemV2,
  ContentItemV2,
  OperateItemV2,
  OperateIconV2,
  SymbolGlyphModifier
} from '@kit.ArkUI';

@Entry
@ComponentV2
struct ComposeListItemV2Example {
  build(): void {
    Column() {
      List() {
        ListItem() {
          ComposeListItemV2({
            contentItemV2: new ContentItemV2({
              iconStyle: IconTypeV2.NORMAL_ICON,
              icon: $r('sys.symbol.house'),
              primaryText: 'Two-line list',
              secondaryText: 'Secondary text',
              description: 'Description text'
            }),
            operateItemV2: new OperateItemV2({
              image: $r('sys.symbol.car'),
            })
          })
        }

        ListItem() {
          ComposeListItemV2({
            contentItemV2: new ContentItemV2({
              iconStyle: IconTypeV2.NORMAL_ICON,
              icon: $r('sys.symbol.house'),
              symbolStyle: new SymbolGlyphModifier($r('sys.symbol.bell')).fontColor([Color.Red]),
              primaryText: 'Two-line list',
              secondaryText: 'Secondary text',
              description: 'Description text'
            }),
            operateItemV2: new OperateItemV2({
              image: $r('sys.symbol.car'),
              symbolStyle: new SymbolGlyphModifier($r('sys.symbol.heart')).fontColor([Color.Pink]),
            })
          })
        }

        ListItem() {
          ComposeListItemV2({
            contentItemV2: new ContentItemV2({
              iconStyle: IconTypeV2.NORMAL_ICON,
              icon: $r('sys.symbol.house'),
              symbolStyle: new SymbolGlyphModifier($r('sys.symbol.bell')).fontColor([Color.Blue]),
              primaryText: 'Two-line list',
              secondaryText: 'Secondary text',
              description: 'Description text.'
            }),
            operateItemV2: new OperateItemV2({
              icon: new OperateIconV2({
                value: $r('sys.symbol.car'),
                symbolStyle: new SymbolGlyphModifier($r('sys.symbol.heart')).fontColor([Color.Orange]),
                action: () => {
                  this.getUIContext().getPromptAction().showToast({
                    message: 'icon'
                  });
                }
              })
            })
          })
        }
      }
    }
  }
}
```

![Example 3 - ComposeListItemV2 with Symbol type icon](figures/image-composelistitemv2-demo-03.png)
<!--no_check-->