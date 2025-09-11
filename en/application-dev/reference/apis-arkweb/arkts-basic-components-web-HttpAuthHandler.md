# Class (HttpAuthHandler)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements the **HttpAuthHandler** object. For details about the sample code, see [onHttpAuthRequest](./arkts-basic-components-web-events.md#onhttpauthrequest9).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>9+</sup>

constructor()

Constructs an **HttpAuthHandler**.

**System capability**: SystemCapability.Web.Webview.Core

## cancel<sup>9+</sup>

cancel(): void

Cancels HTTP authentication as requested by the user.

**System capability**: SystemCapability.Web.Webview.Core

## confirm<sup>9+</sup>

confirm(userName: string, password: string): boolean

Performs HTTP authentication with the user name and password provided by the user.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory | Description      |
| -------- | ------ | ---- | ---------- |
| userName | string | Yes  | HTTP authentication user name.|
| password      | string | Yes  | HTTP authentication password. |

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | **true** is returned if the authentication is successful; otherwise, **false** is returned.|

## isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

Sets whether to use the account name and password cached on the server for authentication.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | **true** is returned if the authentication is successful; otherwise, **false** is returned.|
