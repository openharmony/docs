# Class (ScreenCaptureHandler)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @qq_42700029-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements the **ScreenCaptureHandler** object for accepting or rejecting a screen capture request. For details about the sample code, see [onScreenCaptureRequest](./arkts-basic-components-web-events.md#onscreencapturerequest10).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 10.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>10+</sup>

constructor()

Constructs a **ScreenCaptureHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

## deny<sup>10+</sup>

deny(): void

Rejects this screen capture request.

**System capability**: SystemCapability.Web.Webview.Core

## getOrigin<sup>10+</sup>

getOrigin(): string

Obtains the origin of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Origin of the web page that requests the permission.|

## grant<sup>10+</sup>

grant(config: ScreenCaptureConfig): void

Grants the screen capture permission.

> **NOTE**
>
> The **ohos.permission.MICROPHONE** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type                                    | Mandatory  | Description   |
| ------ | ---------------------------------------- | ---- | ------- |
| config | [ScreenCaptureConfig](./arkts-basic-components-web-ScreenCaptureHandler.md) | Yes  | Screen capture configuration.|
