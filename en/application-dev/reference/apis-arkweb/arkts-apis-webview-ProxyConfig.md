# Class (ProxyConfig)

Implements a **ProxyConfig** object to configure proxies.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 15.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## insertProxyRule<sup>15+</sup>

insertProxyRule(proxyRule: string, schemeFilter?: ProxySchemeFilter): void

Inserts a proxy rule for URLs matching **schemeFilter**. If **schemeFilter** is empty, all URLs use the specified proxy.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| proxyRule      | string  | Yes  | The specified proxy.|
| schemeFilter   | [ProxySchemeFilter](./arkts-apis-webview-e.md#proxyschemefilter15)  | No  | Filter used to specify URLs that use the proxy.<br>Default value: **MATCH_ALL_SCHEMES**.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## insertDirectRule<sup>15+</sup>

insertDirectRule(schemeFilter?: ProxySchemeFilter): void

Inserts a proxy rule to specify that URLs matching **schemeFilter** are directly connected to the server.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| schemeFilter   | [ProxySchemeFilter](./arkts-apis-webview-e.md#proxyschemefilter15)  | No  | Filter used to specify URLs to be directly connected to the server.<br>Default value: **MATCH_ALL_SCHEMES**.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## insertBypassRule<sup>15+</sup>

insertBypassRule(bypassRule: string): void

Inserts a bypass rule to specify the URLs that should bypass the proxy and directly connect to the server.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| bypassRule     | string  | Yes  | Bypass rule used to specify the URLs that should bypass the proxy.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## bypassHostnamesWithoutPeriod<sup>15+</sup>

bypassHostnamesWithoutPeriod(): void

Specifies that host names without a period should bypass the proxy and directly connect to the server.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## clearImplicitRules<sup>15+</sup>

clearImplicitRules(): void

Overrides the default behavior and forcibly sends the local host address or local IP address through the proxy. (By default, if host names are local IP addresses or local host addresses, they bypass the proxy.)

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## enableReverseBypass<sup>15+</sup>

enableReverseBypass(reverse: boolean): void

Reverses the bypass rule.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| reverse     | boolean  | Yes  | Whether to reverse the bypass rule. The default value is **false**, indicating the bypass rule set in [insertBypassRule](#insertbypassrule15) is not reversed. The value **true** indicates the opposite.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## getBypassRules<sup>15+</sup>

getBypassRules(): Array\<string\>

Obtains the list of URLs that do not use the proxy.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Array\<string\> | List of URLs that do not use the proxy.|

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## getProxyRules<sup>15+</sup>

getProxyRules(): Array\<ProxyRule\>

Obtains proxy rules.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Array\<[ProxyRule](./arkts-apis-webview-ProxyRule.md)\> | Proxy rules.|

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## isReverseBypassEnabled<sup>15+</sup>

isReverseBypassEnabled(): boolean

Obtains the value of [enableReverseBypass](#enablereversebypass15). For details, see [enableReverseBypass](#enablereversebypass15).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Value of [enableReverseBypass](#enablereversebypass15). The default value is **false**, indicating the bypass rule set in [insertBypassRule](#insertbypassrule15) is not reversed. The value **true** indicates the opposite.|

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).
