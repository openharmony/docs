# Class (PrefetchOptions)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Defines the prefetch behavior of web pages, including whether to ignore **Cache-Control: no-store** in the response header and the minimum interval between two prefetches.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 21.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Attributes

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Read-Only| Optional| Description|
|------|------|------|------|------|
| minTimeBetweenPrefetchesMs<sup>21+</sup> | number | No| No| Minimum interval between two web page prefetches.<br>The interval between two web page prefetches is calculated. If it is less than the specified value, the current prefetch is canceled.<br>The default value is **500**, and the maximum value is **500**.<br>If the value is set to a negative number, the default value **0** is used.|
| ignoreCacheControlNoStore<sup>21+</sup> | boolean | No| No| Whether to ignore **Cache-Control: no-store** in the response header.<br>Default value: **false**.<br>The value **true** means to ignore **Cache-Control: no-store** in the response header, and **false** means the opposite.|

## constructor<sup>21+</sup>

constructor()

A constructor used to create a **PrefetchOptions** instance.

**System capability**: SystemCapability.Web.Webview.Core
