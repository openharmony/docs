# Class (WebCookie)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有Web组件共享一个WebCookie。通过controller方法中的getCookieManager方法可以获取WebCookie对象，进行后续的cookie管理操作。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 8开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## constructor

constructor()

WebCookie的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## setCookie<sup>(deprecated)</sup>

setCookie()

设置cookie，该方法为同步方法。设置成功返回true，否则返回false。

从API version 9开始不再维护，建议使用[setCookie<sup>9+</sup>](./arkts-apis-webview-WebCookieManager.md#setcookiedeprecated)代替。

**系统能力：** SystemCapability.Web.Webview.Core

## saveCookie<sup>(deprecated)</sup>

saveCookie()

将当前存在内存中的cookie同步到磁盘中，该方法为同步方法。

从API version 9开始不再维护，建议使用[saveCookieAsync<sup>9+</sup>](./arkts-apis-webview-WebCookieManager.md#savecookieasync)代替。

**系统能力：** SystemCapability.Web.Webview.Core