# Common Attributes for Graphics Drawing

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @l30014443-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=13c018abd6fbacca5a7bccacae70bb4f4f195a2c translatedAt=2026-08-13T11:54:38.547Z pushedAt=2026-08-13T12:36:07.723Z -->

Defines the common attributes of graphics drawing components.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## fill

fill(value: ResourceColor): T

Sets the fill color. This attribute supports the [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) attribute method for dynamic setting. Invalid values are treated as the default value. If this attribute is set together with the universal attribute **foregroundColor**, the one set later takes effect.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type                                       | Mandatory | Description                                   |
| ------ | ------------------------------------------ | ---- | -------------------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | Yes   | Fill color.<br/>Default value: [Color](ts-appendix-enums.md#color).Black <br/>Abnormal values **undefined**, **null**, **NaN**, and **Infinity** are treated as the default value.|

**Return value**

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Current component.                                                |

## fillOpacity

fillOpacity(value: number | string | Resource): T

Sets the opacity of the fill area. This attribute supports dynamic setting through [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier).

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type                                                         | Mandatory | Description                           |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------ |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | Yes   | Opacity of the fill area.<br/>**NOTE**<br/>The value range of the number format is [0.0, 1.0]. If the given value is less than 0.0, the value is 0.0; if the given value is greater than 1.0, the value is 1.0. Other abnormal values are processed as 1.0.<br/>The string format supports the string form of the number format value, and the value range is the same as that of the number format.<br/>The Resource format supports strings in system resources or app resources, and the value range is the same as that of the number format.<br/>The abnormal value **NaN** is processed as 0.0, and **undefined**, **null**, and **Infinity** are processed as 1.0.<br/>Default value: 1.0 |

**Return value**

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Returns the current component.                                                |

## stroke

stroke(value: ResourceColor): T

Sets the stroke color. This attribute supports [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) for dynamic setting of the attribute method. If it is not set, the default stroke opacity is 0, that is, no stroke is displayed.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type                                       | Mandatory | Description       |
| ------ | ------------------------------------------ | ---- | ---------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | Yes  | Stroke color.<br/>Default value: [Color](ts-appendix-enums.md#color).Transparent<br/>Abnormal values **undefined** and **null** are processed as the default value, and **NaN** and **Infinity** are processed as [Color](ts-appendix-enums.md#color).Black. |

**Return value**

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Current component.                                                |

## strokeDashArray

strokeDashArray(value: Array&lt;any&gt;): T

Sets the dashed line segment length and gap length of the stroke. This attribute supports the [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) dynamic setting attribute method. The value range is ≥ 0. Abnormal values are processed as the default value.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type             | Mandatory | Description                      |
| ------ | ---------------- | ---- | ------------------------- |
| value  | Array&lt;any&gt; | Yes   | Array that defines the dashed pattern of the Rect stroke. The array elements alternately represent the segment length and gap length.<br/>Default value: **[]** (empty array)<br/>Default unit: vp <br/>The abnormal values **undefined** and **null** are processed as the default value.<br/>**NOTE**<br/>Empty array: solid line<br/>Even-numbered multi-element array: the array elements are cycled in order. For example, [a, b, c, d] represents segment length a -> gap length b -> segment length c -> gap length d -> segment length a -> ...<br/>Odd-numbered multi-element array: the array elements are repeated once and then cycled following the rule of an even-numbered multi-element array. For example, [a, b, c] is equivalent to [a, b, c, a, b, c], which represents segment length a -> gap length b -> segment length c -> gap length a -> segment length b -> gap length c -> segment length a -> ... |

**Return value**

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Returns the current component.                                                |

## strokeDashOffset

strokeDashOffset(value: number | string): T

Sets the offset of the stroke drawing start point. This attribute supports [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) for dynamic setting of the attribute method. Abnormal values are processed as the default value.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type                       | Mandatory | Description                                 |
| ------ | -------------------------- | ---- | ------------------------------------ |
| value  | number&nbsp;\|&nbsp;string | Yes   | Offset of the stroke drawing start point.<br/>Default value: **0**<br/>Default unit: vp <br/>The abnormal values **undefined** and **null** are processed as the default value. **NaN** and **Infinity** cause **strokeDashArray** to become invalid.|

**Return value**

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Returns the current component.                                                |

## strokeLineCap

strokeLineCap(value: LineCapStyle): T

Sets the line cap style of the stroke. This attribute supports [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) for dynamic setting of the attribute method.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type                                              | Mandatory | Description                                             |
| ------ | ------------------------------------------------- | ---- | ------------------------------------------------ |
| value  | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | Yes   | Line cap style of the stroke.<br/>Default value: **LineCapStyle.Butt** <br/>The abnormal values **undefined**, **null**, **NaN**, and **Infinity** are processed as the default value.|

**Return value**

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Returns the current component.                                                |

## strokeLineJoin

strokeLineJoin(value: LineJoinStyle): T

Sets the style for drawing the corners of the stroke. This attribute method supports [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) for dynamic setting.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                | Mandatory | Description                                               |
| ----- | --------------------------------------------------- | --------- | --------------------------------------------------------- |
| value | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | Yes       | Style for drawing the corners of the stroke.<br/>Default value: **LineJoinStyle.Miter**<br/>Abnormal values **undefined**, **null**, **NaN**, and **Infinity** are processed as the default value.|

**Return value**

| Type | Description                                                         |
| ---- | ------------------------------------------------------------------- |
| T    | Current component.                                           |

## strokeMiterLimit

strokeMiterLimit(value: number | string): T

Sets the limit value of the ratio of the miter length to the stroke width. This attribute supports [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) for dynamic setting of the attribute method. The miter length is the distance from the intersection of the outer edges to the intersection of the inner edges, and the stroke width is the value of the **strokeWidth** attribute. This attribute takes effect only when the **strokeLineJoin** attribute is set to **LineJoinStyle.Miter**.

The valid value range of this attribute must be greater than or equal to 1.0. When the value is in the range [0, 1), it is processed as 1.0, and other abnormal values are processed as the default value.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type | Mandatory | Description |
| ------ | -------------------------- | ---- | ---------------------------------------------- |
| value | number&nbsp;\|&nbsp;string | Yes | Limit value of the ratio of the miter length to the stroke width.<br/>Default value: **4**<br/>The abnormal values **undefined**, **null**, and **NaN** are processed as the default value, and **Infinity** causes stroke to become invalid.|

**Return value**

| Type                    | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Returns the current component.                                                |

## strokeOpacity

strokeOpacity(value: number | string | Resource): T

Sets the stroke opacity. This attribute supports [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) for dynamic setting of the attribute method. The value range of this attribute is [0.0, 1.0]. If the given value is less than 0.0, the value is 0.0; if the given value is greater than 1.0, the value is 1.0.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type                                                         | Mandatory | Description                       |
| ------ | ------------------------------------------------------------ | ---- | -------------------------- |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | Yes   | Stroke opacity.<br/>Default value: the opacity set by [stroke](#stroke).<br/>The abnormal value **NaN** is processed as 0.0, and **undefined**, **null**, and **Infinity** are processed as 1.0. |

**Return value**

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Returns the current component.                                                |

## strokeWidth

strokeWidth(value: Length): T

Sets the stroke width. This attribute supports the [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) dynamic setting attribute method. If this attribute is of the string type, percentages are not supported, and a percentage is processed as 1px.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type                         | Mandatory | Description                     |
| ------ | ---------------------------- | ---- | ------------------------ |
| value  | [Length](ts-types.md#length) | Yes   | Stroke width. Value range: ≥0.<br/>Default value: **1**<br/>Default unit: vp<br/>The abnormal values **undefined**, **null**, and **NaN** are processed as the default value, and **Infinity** is processed as 0. |

**Return value**

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T                        | Returns the current component.                                                |

## antiAlias

antiAlias(value: boolean): T

Sets whether to enable anti-aliasing. This attribute supports [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier) for dynamic setting of the attribute method.

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type | Mandatory | Description |
| ------ | ------- | ---- | ------------------------------------- |
| value | boolean | Yes | Whether to enable anti-aliasing.<br/>**true**: enables anti-aliasing; **false**: disables anti-aliasing.<br/>Default value: **true**<br/>The abnormal values **undefined** and **null** are processed as **false**.|

**Return value**

| Type | Description |
| ------------------------ | ------------------------------------------------------------ |
| T | Returns the current component. |