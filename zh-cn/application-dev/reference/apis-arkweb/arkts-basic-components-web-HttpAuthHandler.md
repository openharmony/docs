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
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 9开始支持。
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
| userName | string | 是   | HTTP认证用户名，需为非空字符串。 |
| password      | string | 是   | HTTP认证密码，需为非空字符串。  |

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 认证成功时返回true，失败返回false。 |

## isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

检查当前主机存储的凭据是否适用，如果凭据在当前请求中曾被服务器拒绝过，则不适用。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 存储的凭据适用时返回true，其他返回false。 |