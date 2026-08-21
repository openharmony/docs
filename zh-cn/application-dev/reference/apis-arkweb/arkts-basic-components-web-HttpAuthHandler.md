# Class (HttpAuthHandler)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

HttpAuthHandler是Web组件用于处理HTTP认证请求的处理类。当服务器返回401 Unauthorized要求身份认证时，Web组件通过onHttpAuthRequest事件回调获取HttpAuthHandler实例，由应用决定是否提供认证凭据。示例代码参考[onHttpAuthRequest](./arkts-basic-components-web-events.md#onhttpauthrequest9)事件。

> **说明：**
>
> - 该组件从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class从API version 9开始支持。
>
> - 示例效果请以真机运行为准。

## constructor<sup>9+</sup>

constructor()

HttpAuthHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## cancel<sup>9+</sup>

cancel(): void

通知Web组件用户取消HTTP认证操作。

**系统能力：** SystemCapability.Web.Webview.Core

## confirm<sup>9+</sup>

confirm(userName: string, password: string): boolean

使用用户名和密码进行HTTP认证操作。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填  | 说明       |
| -------- | ------ | ---- | ---------- |
| userName | string | 是   | HTTP认证用户名，建议传入非空字符串。 |
| password      | string | 是   | HTTP认证密码，建议传入非空字符串。  |

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 返回值仅表示接口调用状态，不代表认证结果。true表示调用成功，false表示调用失败。 |

## isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

检查当前主机存储的凭据是否适用，如果凭据在当前请求中曾被服务器拒绝过，则不适用。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 存储的凭据适用时返回true，其他返回false。 |