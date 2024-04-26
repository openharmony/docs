# Web Subsystem ChangeLog

## cl.web.1 Enabling Rule Change for the Viewport meta Tag

**Access Level**

Public

**Reason for Change**

In previous versions, the viewport **\<meta>** tag is enabled or disabled based on the device type. On mobile devices, the tag is enabled, and pages are displayed with a mobile-optimized viewport. On other devices, the tag is disabled, and pages are displayed with a desktop-optimized viewport. This means that the viewport cannot be customized.

**Change Impact**

The [setCustomUserAgent](../../../application-dev/reference/apis-arkweb/js-apis-webview.md#setcustomuseragent10) API can be used to customize the viewport. Specifically, if the custom user agent does not contain the **Mobile** field, the device is identified as desktop and the viewport **\<meta>** tag is disabled by default; if the custom user agent contains the **Mobile** field, the device is identified as mobile and  and the viewport **\<meta>** tag is enabled by default.

This change is a non-compatible change. If the custom user agent is not standards compliant, a web page layout error will occur.

**API Level**

10

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

setCustomUserAgent

**Adaptation Guide**

Set a standards compliant custom user agent or use the default user agent. You are advised to use [getUserAgent](../../../application-dev/reference/apis-arkweb/js-apis-webview.md#getuseragent) to obtain the default user agent and then define a custom user agent based on the default one.
