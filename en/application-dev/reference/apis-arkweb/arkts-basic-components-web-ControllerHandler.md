# Class (ControllerHandler)

Implements a **WebviewController** object for new **Web** components. For details about the sample code, see [onWindowNew](./arkts-basic-components-web-events.md#onwindownew9).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

**System capability**: SystemCapability.Web.Webview.Core

## constructor<sup>9+</sup>

constructor()

Constructs a **ControllerHandler** API.

**System capability**: SystemCapability.Web.Webview.Core

## setWebController<sup>9+</sup>

setWebController(controller: WebviewController): void

Sets a **WebviewController** object. If opening a new window is not needed, set the parameter to **null**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                    | Mandatory| Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| controller | [WebviewController](./arkts-apis-webview-WebviewController.md) | Yes | **WebviewController** object of the **Web** component. If opening a new window is not needed, set it to **null**.|
