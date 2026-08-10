# Class (SslErrorHandler)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

SslErrorHandler是Web组件中处理SSL证书验证错误的类。当加载安全页面时遇到SSL证书错误（如证书过期、主机名不匹配、不受信任的CA），应用可通过onSslErrorEvent回调获取SslErrorHandler实例，并决定是否继续加载或取消导航。示例代码参考[onSslErrorEvent](./arkts-basic-components-web-events.md#onsslerrorevent12)事件。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 9开始支持。
>
> - 示例效果请以真机运行为准。

## constructor<sup>9+</sup>

constructor()

SslErrorHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## handleCancel<sup>9+</sup>

handleCancel(): void

通知Web组件取消此请求，并停止当前SSL证书验证流程。

**系统能力：** SystemCapability.Web.Webview.Core

## handleConfirm<sup>9+</sup>

handleConfirm(): void

忽略SSL证书验证错误，继续加载页面。

**系统能力：** SystemCapability.Web.Webview.Core

## handleCancel<sup>20+</sup>

handleCancel(abortLoading: boolean): void

通知Web组件取消此请求，并根据参数abortLoading决定是否停止加载。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| abortLoading    | boolean  | 是    | 是否在取消请求后停止加载页面。<br>true表示停止加载页面，false表示继续加载页面。 |