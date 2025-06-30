# MenuItem

The **MenuItem** component represents an item in a menu.

> **NOTE**
>
> This component is supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

MenuItem(value?: MenuItemOptions| CustomBuilder)

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                        |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------- |
| value  | [MenuItemOptions](#menuitemoptions) \| [CustomBuilder](ts-types.md#custombuilder8) | No  | Information about the menu item.|

## MenuItemOptions

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                       | Mandatory| Description                            |
| --------- | ------------------------------------------- | ---- | -------------------------------------- |
| startIcon | [ResourceStr](ts-types.md#resourcestr)      | No  | Path to the icon displayed on the left of the menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 11.     |
| content   | [ResourceStr](ts-types.md#resourcestr)      | No  | Content of the menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                       |
| endIcon   | [ResourceStr](ts-types.md#resourcestr)      | No  | Path to the icon displayed on the right of the menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 11.       |
| labelInfo | [ResourceStr](ts-types.md#resourcestr)      | No  | Information about the ending label, for example, shortcut **Ctrl+C**.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| builder   | [CustomBuilder](ts-types.md#custombuilder8) | No  | Builder for a level-2 menu.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                     |
| symbolStartIcon<sup>12+</sup>   | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | No  | Path to the symbol icon displayed on the left of the menu item. When this parameter is set, the icon set through **startIcon** is not displayed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| symbolEndIcon<sup>12+</sup>   | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | No  | Path to the symbol icon displayed on the right of the menu item. When this parameter is set, the icon set through **endIcon** is not displayed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|


## Attributes

In addition to the [universal attributes](ts-component-general-attributes.md), the following attributes are supported.

### selected

selected(value: boolean)

Sets whether the menu item is selected.

Since API version 10, this attribute supports two-way binding through [$$](../../../ui/state-management/arkts-two-way-sync.md).
Since API version 18, this attribute supports two-way binding through [!!](../../../ui/state-management/arkts-new-binding.md#two-way-binding-between-built-in-component-parameters).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether the menu item is selected.<br>Default value: **false**<br>**true**: The menu item is selected.<br> **false**: The menu item is not selected.|

### selectIcon

selectIcon(value: boolean | ResourceStr | SymbolGlyphModifier)

Sets whether to display the selected icon when the menu item is selected.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | boolean \| [ResourceStr](ts-types.md#resourcestr)<sup>10+</sup>\| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md)<sup>12+</sup> | Yes  | Whether to display the selected icon when the menu item is selected.<br>Default value: **false**<br>**true**: When the menu item is selected, the default tick icon is displayed.<br>**false**: When the menu item is selected, no icon is displayed.<br>**ResourceStr**: When the menu item is selected, the specified icon is displayed.<br>**SymbolGlyphModifier**: When the menu item is selected, the specified symbol icon is displayed.|
### contentFont<sup>10+</sup>

contentFont(value: Font)

Sets the font style of the menu item content.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                    | Mandatory| Description                        |
| ------ | ------------------------ | ---- | ---------------------------- |
| value  | [Font](ts-types.md#font) | Yes  | Font style of the menu item content.|

### contentFontColor<sup>10+</sup>

contentFontColor(value: ResourceColor)

Sets the font color of the menu item content.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | Yes  | Font color of the menu item content.<br>Default value: **'#E5000000'**|

### labelFont<sup>10+</sup>

labelFont(value: Font)

Sets the font style of the menu item label.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                    | Mandatory| Description                        |
| ------ | ------------------------ | ---- | ---------------------------- |
| value  | [Font](ts-types.md#font) | Yes  | Font style of the menu item label.|

### labelFontColor<sup>10+</sup>

labelFontColor(value: ResourceColor)

Sets the font color of the menu item label.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | Yes  | Font color of the menu item label.<br>Default value: **'#99000000'**|

## Events

### onChange

onChange(callback: (selected: boolean) => void)

Triggered when the selection status of the menu item is changed manually.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| selected | boolean | Yes  | Invoked when the selected status changes.<br>If the return value is **true**, the menu item is selected. If the return value is **false**, the menu item is not selected.|

## Example

See the example of [Menu](ts-basic-components-menu.md#example).
