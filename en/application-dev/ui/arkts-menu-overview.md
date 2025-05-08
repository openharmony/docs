# Menu Overview

A menu is a pop-up window that allows users to perform specific actions. It typically appears when users right-click, long-press, or touch an item.

## When to Use

| API|Use Case |
| ----------| ----------------------------------- |
| [Menu control (Menu)](arkts-popup-and-menu-components-menu.md)| Used to bind actions to specified components, such as displaying operation options when an icon is long-pressed.|
| [Global menu independent of UI components (openMenu)](arkts-popup-and-menu-components-uicontext-menu.md)| Used to show options in scenarios where UI components cannot be directly accessed, for example, in event callbacks.|

## Constraints

* Menus can be displayed only after the page is fully built. Setting the [show](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11) property to **true** during page construction may result in issues with the menu's position and shape.
* When using **openMenu**, you need to provide valid [TargetInfo](../reference/apis-arkui/js-apis-arkui-UIContext.md#targetinfo18). Otherwise, the menu won't display correctly.
* For details about other specifications, see [Menu Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md) and [openMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#openmenu18).
