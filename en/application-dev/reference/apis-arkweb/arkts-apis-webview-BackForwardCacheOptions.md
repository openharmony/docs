# Class (BackForwardCacheOptions)

Implements a **BackForwardCacheOptions** object to set back-forward cache options of the **Web** component.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

**System capability**: SystemCapability.Web.Webview.Core

## Attributes

| Name| Type| Mandatory| Description|
|------|------|------|------|
| size<sup>12+</sup> | number | Yes| The maximum number of pages that can be cached in a **Web** component.<br>The default value is **1**, and the maximum value is **50**.<br>If this parameter is set to **0** or a negative value, the back-forward cache is disabled.<br>The **Web** component reclaims the cache for memory pressure.|
| timeToLive<sup>12+</sup> | number | Yes| The time that a **Web** component allows a page to stay in the back-forward cache.<br>If this parameter is set to **0** or a negative value, the back-forward cache is disabled.<br>Default value: **600**<br>Unit: second|

## constructor<sup>12+</sup>

constructor()

Constructs a **BackForwardCacheOptions** object.

**System capability**: SystemCapability.Web.Webview.Core
