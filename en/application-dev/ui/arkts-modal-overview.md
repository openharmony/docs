# Modal Page Overview

Modal pages are interactive popups with a large panel and expansive view, designed to present critical information or perform operations without navigating away from the current context. Unlike standard dialog boxes, modal pages offer a larger canvas for content, which you can populate using custom components. By default, user interaction is required to exit the modal page. ArkUI offers two distinct types of modal pages: semi-modal and full-modal, each serving different interaction patterns.

* Semi-modal: ideal for multi-form effects, allowing for various styles across different device widths. Users can dismiss the semi-modal page through side swiping, touching the mask, touching the close button, or pulling down.
* Full-modal: designed for full-screen modal dialog boxes that demand user attention. By default, side swiping is required to dismiss the full-model page.

## Available APIs

| API|Description |
| ----------| ----------------------------------- |
| [bindContentCover](arkts-contentcover-page.md) | Use this API to display a full-modal page. It can work with the transition animation and shared element animation to implement complex transition animation effects, for example, displaying an image in full in the modal upon the click of a thumbnail.|
| [bindSheet](arkts-sheet-page.md)  | Use this API to display a custom semi-modal page, for example, a sharing confirmation dialog box.|
| [openBindSheet/ updateBindSheet/closeBindSheet](../reference/apis-arkui/js-apis-arkui-UIContext.md#openbindsheet12) | Use this API for scenarios independent of UI components, such as global application launch, updates, and shutdowns.|

## Specifications Constraints

* The **openBindSheet**, **updateBindSheet**, and **closeBindSheet** APIs in **UIContext** are contingent upon the UI execution context and should not be used where the UI context is unclear. For details, see [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext). For details about other specifications, see [openBindSheet](../reference/apis-arkui/js-apis-arkui-UIContext.md#openbindsheet12), [updateBindSheet](../reference/apis-arkui/js-apis-arkui-UIContext.md#updatebindsheet12), and [closeBindSheet](../reference/apis-arkui/js-apis-arkui-UIContext.md#closebindsheet12).
* Except for UI-less scenarios<!--Del--> such as [ServiceExtension](../../application-dev/application-models/serviceextensionability.md)<!--DelEnd-->, it is recommended that you use the dialog APIs provided by **UIContext**.
