# MenuItem

The **\<MenuItem>** component represents an item in a menu.

> **NOTE**
>
> This component is supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

MenuItem(value?: MenuItemOptions| CustomBuilder)

**Parameters**

| Name | Type                                                                                                                         | Mandatory| Description                    |
| ----- | ----------------------------------------------------------------------------------------------------------------------------- | ---- | ---------------------------- |
| value | [MenuItemOptions](ts-basic-components-menuitem.md#menuitemoptions) \| [CustomBuilder](ts-types.md#custombuilder8) | No  | Information about the menu item.|

## MenuItemOptions

| Name     | Type                                    | Mandatory| Description                                  |
| --------- | ---------------------------------------- | ---- | -------------------------------------- |
| startIcon | [ResourceStr](ts-types.md#resourcestr)      | No  | Path to the icon displayed on the left of the menu item.      |
| content   | [ResourceStr](ts-types.md#resourcestr)      | Yes  | Content of the menu item.                      |
| endIcon   | [ResourceStr](ts-types.md#resourcestr)      | No  | Path to the icon displayed on the right of the menu item.      |
| labelInfo | [ResourceStr](ts-types.md#resourcestr)      | No  | Information about the ending label, for example, shortcut **Ctrl+C**. |
| builder   | [CustomBuilder](ts-types.md#custombuilder8) | No  | Builder for a level-2 menu.                    |

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name      | Type| Description                                    |
| ---------- | -------- | ---------------------------------------- |
| selected   | boolean  | Whether the menu item is selected.<br>Default value: **false** |
| selectIcon | boolean  | Whether to display the icon of the menu item being selected.|

## Events

| Name    | Type                   | Description                                                                                                                                                           |
| -------- | --------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| onChange | (selected: boolean) => void | Triggered when the selection status of the menu item is changed manually.<br>The value **true** means that the menu item is selected, and **false** means the opposite. |

## Example

For details, see [Example in Menu](ts-basic-components-menu.md#example).
