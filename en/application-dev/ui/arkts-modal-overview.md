# Modal Page Overview

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=fd87a3fabd6b3d582616cc6b10933b62b2152e9f translatedAt=2026-08-04T06:34:31.088Z pushedAt=2026-08-04T07:45:09.432Z -->

Modal pages are interactive popups featuring expansive panels that display critical information or enable operations while maintaining the current context. Unlike conventional popup components, modal pages provide substantially more space for content, which you must populate with custom components. By default, these modal pages require explicit user interaction to dismiss. ArkUI offers two distinct types of modal pages: semi-modal and full-modal, each serving different interaction patterns.

* Semi-modal: ideal for multi-form effects, allowing for various styles across different device widths. Users can dismiss the semi-modal page through side swiping, touching the mask, touching the close button, or pulling down.

  ![en-us_sheet1](./figures/sheet1.gif)

* Full-modal: designed for full-screen modal dialog boxes that demand user attention. By default, side swiping is required to dismiss the full-modal page.

  ![en-us_modal1](./figures/modal1.gif)

## Available APIs

| API|Description |
| ----------| ----------------------------------- |
| [bindContentCover](arkts-contentcover-page.md) | Use this API to display a full-modal page. It can work with the transition animation and shared element animation to implement complex transition animation effects, for example, displaying an image in full in the modal upon the click of a thumbnail.|
| [bindSheet](arkts-sheet-page.md)  | Use this API to display a custom semi-modal page, for example, a sharing confirmation dialog box.|
| [openBindSheet](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#openbindsheet12)/ [updateBindSheet](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#updatebindsheet12)/ [closeBindSheet](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#closebindsheet12) | Use this API for scenarios independent of UI components, such as global launch, updates, and shutdowns.|

## Specifications Constraints

* It is recommended that you use the dialog box APIs provided by **UIContext**<!--Del-->, except for UI-less scenarios such as [ServiceExtensionAbility](../../application-dev/application-models/serviceextensionability-sys.md)<!--DelEnd-->. For details about other specifications constraints, see [openBindSheet](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#openbindsheet12), [updateBindSheet](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#updatebindsheet12), and [closeBindSheet](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#closebindsheet12).