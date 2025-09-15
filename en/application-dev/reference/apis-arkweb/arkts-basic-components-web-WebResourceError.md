# Class (WebResourceError)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements the **WebResourceError** object to manage resource errors. For details about the sample code, see [onErrorReceive](./arkts-basic-components-web-events.md#onerrorreceive).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 8.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor

constructor()

Constructs a **WebResourceError** object.

**System capability**: SystemCapability.Web.Webview.Core

## getErrorCode

getErrorCode(): number

Obtains the error code for resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Error code for resource loading. For details about error codes, see [WebNetErrorList](arkts-apis-netErrorList.md).|

## getErrorInfo

getErrorInfo(): string

Obtains error information about resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Error information about resource loading.|
