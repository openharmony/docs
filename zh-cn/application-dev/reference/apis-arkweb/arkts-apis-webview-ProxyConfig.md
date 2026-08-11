# Class (ProxyConfig)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

ProxyConfig是ArkWeb框架中用于配置网络代理规则的类，配合[ProxyController](./arkts-apis-webview-ProxyController.md)实现对应用中所有Web组件网络请求的代理控制。通过ProxyConfig，开发者可以灵活定义多种代理规则：指定特定URL使用特定代理服务器、指定某些URL直连服务器、定义绕过代理的规则等。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 15开始支持。
>
> - 示例效果请以真机运行为准。

## insertProxyRule<sup>15+</sup>

insertProxyRule(proxyRule: string, schemeFilter?: ProxySchemeFilter): void

插入一条代理规则，与schemeFilter匹配的URL都会使用指定代理。如果未指定schemeFilter参数，将使用默认值MATCH_ALL_SCHEMES，所有URL都将使用指定代理。

代理格式为[scheme://]host[:port]。

scheme是可选的，必须是HTTP、HTTPS或SOCKS。scheme默认值为HTTP。

host是带括号的IPv6字面量、IPv4字面量或由点分隔的一个或多个标签。

端口号是可选的，默认HTTP为80、HTTPS为443、SOCKS为1080。

例如：
- example.com host: example.com
- https://example.com  scheme: https  host: example.com
- example.com:8888     host: example.com  port: 8888
- https://example.com:8888  scheme: https  host: example.com  port: 8888
- 192.168.1.1  host: 192.168.1.1
- 192.168.1.1:8888  host: 192.168.1.1 port: 8888
- [10:20:30:40:50:60:70:80]

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| proxyRule      | string  | 是   | URL要使用的代理。 |
| schemeFilter   | [ProxySchemeFilter](./arkts-apis-webview-e.md#proxyschemefilter15)  | 否   | 与schemeFilter匹配的URL会使用代理。<br>默认值：MATCH_ALL_SCHEMES。<br>传入undefined或null会抛出异常错误码401。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## insertDirectRule<sup>15+</sup>

insertDirectRule(schemeFilter?: ProxySchemeFilter): void

插入一条直连规则，指明符合schemeFilter条件的URL将直接连接到服务器。

> **说明：**
>
> - 与[insertBypassRule](#insertbypassrule15)和[bypassHostnamesWithoutPeriod](#bypasshostnameswithoutperiod15)均可实现URL直连，区别在于匹配维度：本方法通过schemeFilter按协议类型匹配；insertBypassRule通过bypassRule字符串按URL模式匹配；bypassHostnamesWithoutPeriod无需传参，自动对不含点号的域名直连。可根据需要直连的URL范围选择合适的方法。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| schemeFilter   | [ProxySchemeFilter](./arkts-apis-webview-e.md#proxyschemefilter15)  | 否   | 与schemeFilter匹配的URL会直接与服务器相连。<br>默认值：MATCH_ALL_SCHEMES。 <br>传入undefined或null会抛出异常错误码401。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## insertBypassRule<sup>15+</sup>

insertBypassRule(bypassRule: string): void

插入一条bypass规则，指明哪些URL应该绕过代理并直接连接到服务器。当[enableReverseBypass](#enablereversebypass15)设置为true时，与bypassRule匹配的URL会使用代理而非绕过代理。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| bypassRule     | string  | 是   | bypass规则字符串，用于指定绕过代理的URL匹配规则，支持主机名或域名格式（如"example.com"匹配该域名及其子域名）。与bypassRule匹配的URL会绕过代理。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## bypassHostnamesWithoutPeriod<sup>15+</sup>

bypassHostnamesWithoutPeriod(): void

没有点字符的域名将绕过代理并直接连接到服务器。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## clearImplicitRules<sup>15+</sup>

clearImplicitRules(): void

默认情况下，如果某些主机名是本地IP地址或localhost地址，它们会绕过代理。调用此函数以覆盖默认行为，并强制将localhost或本地IP地址通过代理发送。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## enableReverseBypass<sup>15+</sup>

enableReverseBypass(reverse: boolean): void

反转bypass规则。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| reverse     | boolean  | 是   | 参数值默认是false，表示与[insertBypassRule](#insertbypassrule15)中的bypassRule匹配的URL会绕过代理，参数值为true时，表示与[insertBypassRule](#insertbypassrule15)中的bypassRule匹配的URL会使用代理。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## getBypassRules<sup>15+</sup>

getBypassRules(): Array\<string\>

获取不使用代理的URL列表。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Array\<string\> | 不使用代理的URL列表。 |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## getProxyRules<sup>15+</sup>

getProxyRules(): Array\<ProxyRule\>

获取代理规则。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Array\<[ProxyRule](./arkts-apis-webview-ProxyRule.md)\> | 代理规则，每个ProxyRule对象表示一条已配置的代理规则。 |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## isReverseBypassEnabled<sup>15+</sup>

isReverseBypassEnabled(): boolean

获取[enableReverseBypass](#enablereversebypass15)的参数值，详见[enableReverseBypass](#enablereversebypass15)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| boolean | [enableReverseBypass](#enablereversebypass15)的参数值。参数值为false，表示与[insertBypassRule](#insertbypassrule15)中的bypassRule匹配的URL会绕过代理，参数值为true时，表示与[insertBypassRule](#insertbypassrule15)中的bypassRule匹配的URL会使用代理。 |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。