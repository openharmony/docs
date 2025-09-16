# Class (JsGeolocation)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements the **PermissionRequest** object. For details about the sample code, see [onGeolocationShow](./arkts-basic-components-web-events.md#ongeolocationshow).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 8.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor

constructor()

Constructs a **JsGeolocation** object.

**System capability**: SystemCapability.Web.Webview.Core

## invoke

invoke(origin: string, allow: boolean, retain: boolean): void

Sets the geolocation permission status of a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type   | Mandatory | Description                                    |
| ------ | ------- | ---- | ---------------------------------------- |
| origin | string  | Yes  | Index of the origin.                              |
| allow  | boolean | Yes  | Geolocation permission status.<br>The value **true** means to enable the geolocation permission, and **false** means the opposite.                            |
| retain | boolean | Yes  | Whether the geolocation permission status can be saved to the system. You can manage the geolocation permissions saved to the system through the [GeolocationPermissions<sup>9+</sup>](./arkts-apis-webview-GeolocationPermissions.md) API.<br>The value **true** indicates that the geolocation permission status can be saved to the system, and **false** indicates the opposite.|
