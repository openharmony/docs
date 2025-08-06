# Class (BackForwardCacheSupportedFeatures)

Implements a **BackForwardCacheSupportedFeatures** object to allow a page that uses any of the following features to enter the back-forward cache. For details about the sample code, see [enableBackForwardCache](./arkts-apis-webview-WebviewController.md#enablebackforwardcache12).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Attributes

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| nativeEmbed<sup>12+</sup> | boolean | Yes| Whether to allow the page that uses same-layer rendering to enter the back-forward cache.<br>When the value is set to **true**, you need to maintain the lifecycle of system components created for the same-layer rendering elements to avoid resource leak.<br>The value **true** means to allow the page that uses same-layer rendering to enter the back-forward cache, and **false** means the opposite.<br>Default value: **false**.|
| mediaTakeOver<sup>12+</sup> | boolean | Yes| Whether to allow a page using the media playback takeover feature to the back-forward cache.<br>When the value is set to **true**, you need to maintain the lifecycle of system components created for video elements to avoid resource leak.<br>The value **true** means to allow a page using the media playback takeover feature to enter the back-forward cache, and **false** means the opposite.<br>Default value: **false**.|

## constructor<sup>12+</sup>

constructor()

Constructs a **BackForwardCacheSupportedFeatures** object.

**System capability**: SystemCapability.Web.Webview.Core
