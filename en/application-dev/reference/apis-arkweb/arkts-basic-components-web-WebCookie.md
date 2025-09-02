# Class (WebCookie)

Manages behavior of cookies in **Web** components. All **Web** components in an application share a **WebCookie**. You can use the **getCookieManager** API in **controller** to obtain the **WebCookie** for subsequent cookie management.

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 8.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor

constructor()

Constructs a **WebCookie** object.

**System capability**: SystemCapability.Web.Webview.Core

## setCookie<sup>(deprecated)</sup>

setCookie()

Sets the cookie. This API returns the result synchronously. **true** is returned if the operation is successful; otherwise, **false** is returned.

This API is deprecated since API version 9. You are advised to use [setCookie<sup>9+</sup>](./arkts-apis-webview-WebCookieManager.md#setcookiedeprecated) instead.

**System capability**: SystemCapability.Web.Webview.Core

## saveCookie<sup>(deprecated)</sup>

saveCookie()

Saves the cookies in the memory to the drive. This API returns the result synchronously.

This API is deprecated since API version 9. You are advised to use [saveCookieAsync<sup>9+</sup>](./arkts-apis-webview-WebCookieManager.md#savecookieasync) instead.

**System capability**: SystemCapability.Web.Webview.Core
