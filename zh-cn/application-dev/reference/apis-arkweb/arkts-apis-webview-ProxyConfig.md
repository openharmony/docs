# Class (ProxyConfig)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

可以通过该类提供的接口对代理进行配置。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 15开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## insertProxyRule<sup>15+</sup>

insertProxyRule(proxyRule: string, schemeFilter?: ProxySchemeFilter): void

插入一条代理规则，与schemeFilter匹配的URL都会使用指定代理。如果schemeFilter为空，所有URL都将使用指定代理。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| proxyRule      | string  | 是   | URL要使用的代理。 |
| schemeFilter   | [ProxySchemeFilter](./arkts-apis-webview-e.md#proxyschemefilter15)  | 否   | 与schemeFilter匹配的URL会使用代理。<br>默认值：MATCH_ALL_SCHEMES。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## insertDirectRule<sup>15+</sup>

insertDirectRule(schemeFilter?: ProxySchemeFilter): void

插入一条代理规则，指明符合schemeFilter条件的URL将直接连接到服务器。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| schemeFilter   | [ProxySchemeFilter](./arkts-apis-webview-e.md#proxyschemefilter15)  | 否   | 与schemeFilter匹配的URL会直接与服务器相连。<br>默认值：MATCH_ALL_SCHEMES |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## insertBypassRule<sup>15+</sup>

insertBypassRule(bypassRule: string): void

插入一条bypass规则，指明哪些URL应该绕过代理并直接连接到服务器。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| bypassRule     | string  | 是   | 与bypassRule匹配的URL会绕过代理。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## bypassHostnamesWithoutPeriod<sup>15+</sup>

bypassHostnamesWithoutPeriod(): void

没有点字符的域名将跳过代理并直接连接到服务器。

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
| Array\<[ProxyRule](./arkts-apis-webview-ProxyRule.md)\> | 代理规则。 |

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