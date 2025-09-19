# Popup Overview

Popups are small windows that provide users with additional information or guidance. They are commonly used in scenarios such as screen recording and tooltips.

## When to Use

| API|Use Case |
| ----------| ----------------------------------- |
| [Popup](arkts-popup-and-menu-components-popup.md)| Used to display a hint for a specific component, for example, a tooltip when a question mark is clicked.|
| [Global popup independent of UI components (openPopup)](arkts-popup-and-menu-components-uicontext-popup.md)| Used to display a hint in scenarios where UI components cannot be directly accessed, for example, in event callbacks.|

## Constraints

* Popups can be displayed only after the page is fully built. Setting the [show](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#bindpopup) property to true during page construction may result in issues with the popup's position and shape.
* When using **openPopup**, you need to provide valid [TargetInfo](../reference/apis-arkui/arkts-apis-uicontext-i.md#targetinfo18). Otherwise, the menu won't display correctly.
* For details about other specifications, see [Popup Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md) and [openPopup](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#openpopup18) .
