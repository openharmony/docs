# MenuItemGroup

The **MenuItemGroup** component represents a group of menu items.

> **NOTE**
>
> This component is supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Child Components

This component contains the [MenuItem](ts-basic-components-menuitem.md) child component.

## APIs

MenuItemGroup(value?: MenuItemGroupOptions)

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                 | Mandatory| Description                                       |
| ------ | ----------------------------------------------------- | ---- | ------------------------------------------- |
| value  | [MenuItemGroupOptions](#menuitemgroupoptions) | No  | Header and footer of the menu item group.|

## MenuItemGroupOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type                                                        | Mandatory| Description                         |
| ------ | ------------------------------------------------------------ | ---- | ----------------------------- |
| header | [ResourceStr](ts-types.md#resourcestr) \| [CustomBuilder](ts-types.md#custombuilder8) | No  | Header of the menu item group.|
| footer | [ResourceStr](ts-types.md#resourcestr) \| [CustomBuilder](ts-types.md#custombuilder8) | No  | Footer of the menu item group.|

## Sample

For details, see [Example in Menu](ts-basic-components-menu.md#example).
