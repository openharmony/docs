# Class (ProxyRule)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--SE: @yaomingliu-->
<!--TSE: @ghiker-->

[insertProxyRule](./arkts-apis-webview-ProxyConfig.md#insertproxyrule15)中使用的代理规则。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 15开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## getSchemeFilter<sup>15+</sup>

getSchemeFilter(): ProxySchemeFilter

获取代理规则中的ProxySchemeFilter信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| [ProxySchemeFilter](./arkts-apis-webview-e.md#proxyschemefilter15) | 代理规则中的ProxySchemeFilter信息。 |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## getUrl<sup>15+</sup>

getUrl(): string

获取代理规则中的代理的URL信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 代理规则中的代理的Url信息。 |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。