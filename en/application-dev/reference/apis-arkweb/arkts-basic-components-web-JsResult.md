# Class (JsResult)

Implements the **JsResult** object to confirm or cancel a dialog box. For details about the sample code, see [onAlert](./arkts-basic-components-web-events.md#onalert).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 8.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor

constructor()

Constructs a **JsResult** object.

**System capability**: SystemCapability.Web.Webview.Core

## handleCancel

handleCancel(): void

Notifies the **Web** component of the user's cancel operation in the dialog box.

**System capability**: SystemCapability.Web.Webview.Core

## handleConfirm

handleConfirm(): void

Notifies the **Web** component of the user's confirm operation in the dialog box.

**System capability**: SystemCapability.Web.Webview.Core

## handlePromptConfirm<sup>9+</sup>

handlePromptConfirm(result: string): void

Notifies the **Web** component of the user's confirm operation in the dialog box as well as the dialog box content.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description       |
| ------ | ------ | ---- | ----------- |
| result | string | Yes   | User input in the dialog box.|
