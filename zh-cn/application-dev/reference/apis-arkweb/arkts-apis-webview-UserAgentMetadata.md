# Class (UserAgentMetadata)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

UserAgentMetadata是ArkWeb框架中用于配置User-Agent Client Hints（UA客户端提示）完整元数据的类。User-Agent Client Hints是一种现代化的HTTP请求标头机制，通过一组Sec-CH-UA系列标头向服务器报告客户端信息，替代传统User-Agent字符串实现更安全、更细粒度的浏览器身份标识。通过UserAgentMetadata，应用可以自定义Web组件向服务器报告的所有客户端信息字段。

> **说明：**
>
> - 本模块首批接口从API version 24开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 24开始支持。
>
> - 示例效果请以真机运行为准。

## setBrandVersionList

setBrandVersionList(brandVersionList: Array\<UserAgentBrandVersion>): void

设置品牌和版本信息。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| brandVersionList | Array\<[UserAgentBrandVersion](./arkts-apis-webview-UserAgentBrandVersion.md)> | 是   | 对应请求标头的Sec-CH-UA-Full-Version-List。空代表使用ArkWeb默认值。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getBrandVersionList

getBrandVersionList(): Array\<UserAgentBrandVersion>

获取品牌和版本信息列表。不调用对应的[setBrandVersionList](#setbrandversionlist)进行设置时，列表默认值：[{"brand":"Chromium","version":[ChromeCompatibleVersion](../../web/web-default-userAgent.md#默认user-agent结构)}, {"brand":"ArkWeb","version":[OSVersion](../../web/web-default-userAgent.md#默认user-agent结构)}]。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| Array\<[UserAgentBrandVersion](./arkts-apis-webview-UserAgentBrandVersion.md)> | 品牌和版本信息列表。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setArchitecture

setArchitecture(arch: string): void

设置平台的架构类型。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| arch | string | 是   | 对应请求标头的Sec-CH-UA-Arch。空代表使用ArkWeb默认值。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getArchitecture

getArchitecture(): string

获取平台的架构类型。不调用对应的[setArchitecture](#setarchitecture)设置时，架构类型默认值：""。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 平台架构类型。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setBitness

setBitness(bitness: string): void

设置平台的位数类型。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| bitness | string | 是   | 对应请求标头的Sec-CH-UA-Bitness。空代表使用ArkWeb默认值。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getBitness

getBitness(): string

获取平台的位数类型。不调用对应的[setBitness](#setbitness)设置时，位数类型默认值：Desktop："64"，其他设备：""。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 平台位数。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setFormFactors

setFormFactors(formFactors: Array\<UserAgentFormFactor>): void

设置设备形态信息，如手机、平板等。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| formFactors | Array\<[UserAgentFormFactor](./arkts-apis-webview-e.md#useragentformfactor24)> | 是   | 对应请求标头的Sec-CH-UA-Form-Factor。空代表使用ArkWeb默认值。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getFormFactors

getFormFactors(): Array\<UserAgentFormFactor>

获取设备形态信息，如手机、平板等。不调用对应的[setFormFactors](#setformfactors)进行设置时，形态信息默认值：手机："Mobile"、手表："Watch"、车机："Automotive"、PC："Desktop"、平板："Tablet"。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| Array\<[UserAgentFormFactor](./arkts-apis-webview-e.md#useragentformfactor24)> | 设备形态信息。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setFullVersion

setFullVersion(fullVersion: string): void

设置完整版本号。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| fullVersion | string | 是   | 对应请求标头的Sec-CH-UA-Full-Version。空代表使用ArkWeb默认值。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getFullVersion

getFullVersion(): string

获取完整版本号。不调用对应的[setFullVersion](#setfullversion)设置时，版本号默认值：""。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 完整版本号。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setMobile

setMobile(isMobile: boolean): void

设置是否为移动设备。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| isMobile | boolean | 是   | 对应请求标头的Sec-CH-UA-Mobile。表示设备是否为移动设备。true为是移动设备，false为不是移动设备。|

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getMobile

getMobile(): boolean

获取是否为移动设备。不调用对应的[setMobile](#setmobile)设置时，默认值：手机: true，手表、车机、平板、大屏: false。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| boolean | 是否为移动设备，true为移动设备，false为不是移动设备。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setModel

setModel(model: string): void

设置设备型号。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| model | string | 是   | 对应请求标头的Sec-CH-UA-Model。 空代表使用ArkWeb默认值。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getModel

getModel(): string

获取设备型号。不调用对应的[setModel](#setmodel)设置时，型号默认值：手机根据const.product.model取设备型号；手表、大屏、车机、PC、平板：""。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 设备型号。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setPlatform

setPlatform(platform: string): void

设置操作系统名称。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| platform | string | 是   | 对应请求标头的Sec-CH-UA-Platform。空代表使用ArkWeb默认值。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getPlatform

getPlatform(): string

获取操作系统名称。不调用对应的[setPlatform](#setplatform)设置时，名称默认值："OpenHarmony" 。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 操作系统名称。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setPlatformVersion

setPlatformVersion(platformVersion: string): void

设置操作系统版本号。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| platformVersion | string | 是   | 对应请求标头的Sec-CH-UA-Platform-Version。空代表使用ArkWeb默认值。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getPlatformVersion

getPlatformVersion(): string

获取操作系统版本号。不调用对应的[setPlatformVersion](#setplatformversion)设置时，版本号默认值：按OpenHarmony平台版本号规则，同const.product.os.dist.version。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 操作系统版本号。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setWow64

setWow64(isWow64: boolean): void

设置二进制文件是否在64位Windows上以32位模式运行。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| isWow64 | boolean | 是   | 对应请求标头的Sec-CH-UA-WoW64。表示二进制文件是否在64位Windows上以32位模式运行。true为是，false为不是。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getWow64

getWow64(): boolean

获取二进制文件是否是在64位Windows上以32位模式运行。不调用对应的[setWow64](#setwow64)设置时，默认值为false。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| boolean | 表示二进制文件是否在64位Windows上以32位模式运行。true为是，false为不是。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。
