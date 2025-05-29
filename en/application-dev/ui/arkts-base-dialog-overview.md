# Dialog Box Overview

A dialog box is a modal window designed to temporarily display information or pending operations that require user attention without disrupting the user's current context. Users are required to address the dialog box's content before they can return to their previous tasks. The dialog box may not be bound to any specific component and typically contains a variety of elements such as text, lists, text boxes, and images to create a comprehensive layout. ArkUI offers two types of dialog box components to suit different needs: custom and fixed-style.

* Custom dialog box: allows you to pass in custom components to define the appearance and behavior of the dialog box. Available APIs include **CustomDialog** and **openCustomDialog**.
* Fixed-style dialog box: offers a predefined structure for simple and standard interactions. Available APIs include **AlertDialog**, **ActionSheet**, **PickerDialog**, **showDialog**, and **showActionMenu**.

## When to Use

| Name| Description|
| --- | --- |
|[Global custom dialog box independent of UI components (openCustomDialog)](arkts-uicontext-custom-dialog.md)| Used when you need to dynamically update the attributes of the custom dialog box.|
|[Basic custom dialog box (CustomDialog)](arkts-common-components-custom-dialog.md)| Used when you need to customize the components and content within the dialog box.|
| [Alert dialog box (AlertDialog)](arkts-fixes-style-dialog.md#alert-dialog-box-alertdialog)| Usually used to display information or operations that users need to pay attention to or must focus on. For example, when a user performs a sensitive action, such a dialog box can be displayed for confirmation.|
| [Action sheet (ActionSheet)](arkts-fixes-style-dialog.md#action-sheet-actionsheet)| Used when there is a list of information that requires user attention or confirmation.|
|[Picker dialog box (PickerDialog)](arkts-fixes-style-dialog.md#picker-dialog-box-pickerdialog)| Used when users need to select dates, time, or text.|
| [Common dialog box (showDialog)](arkts-fixes-style-dialog.md#common-dialog-box-showdialog)| Used when processing of results returned asynchronously is required after the dialog box is closed.|
| [Action menu (showActionMenu)](arkts-fixes-style-dialog.md#action-menu-showactionmenu)| Used when processing of results returned asynchronously is required after the action menu is closed.|
| [Page-level dialog box](arkts-embedded-dialog.md)| Used when you expect the dialog box to switch with the navigation page during route navigation.|
| [Dialog box layer management](arkts-dialog-levelorder.md)| Used to manage the display sequence of dialog boxes by setting the [levelOrder](../reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11) parameter. Available since API version 18.|

## Constraints

* Except for UI-less scenarios<!--Del--> such as [ServiceExtension](../../application-dev/application-models/serviceextensionability.md)<!--DelEnd-->, it is recommended that you use the dialog APIs provided by **UIContext**.
* You can use the [getPromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#getpromptaction) method in **UIContext** to obtain the [PromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#promptaction) object associated with the current UI context.
