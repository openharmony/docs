# Class (UserAgentBrandVersion)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

UserAgentBrandVersion是ArkWeb框架中用于配置User-Agent客户端提示信息中品牌名称和版本号的数据类，配合[UserAgentMetadata](./arkts-apis-webview-UserAgentMetadata.md)使用。在User-Agent Client Hints机制中，浏览器通过Sec-CH-UA-Full-Version-List等请求标头向服务器报告品牌和版本信息，UserAgentBrandVersion用于定义其中的单个品牌条目。

UserAgentBrandVersion提供品牌名称和版本号的设置与获取方法：setBrand/getBrand用于设置和获取品牌名称（如“ArkWeb”等），setMajorVersion/getMajorVersion用于设置和获取主版本号（如“126”），setFullVersion/getFullVersion用于设置和获取完整版本号（如“126.0.0.0”）。应用可通过修改这些值来定制Web组件向服务器报告的浏览器身份信息。

> **说明：**
>
> - 本模块首批接口从API version 24开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 24开始支持。
>
> - 示例效果请以真机运行为准。

## setBrand

setBrand(brand: string): void

设置品牌名称。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| brand | string | 是 | 品牌名称，不能为空字符串。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getBrand

getBrand(): string

获取品牌名称。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 返回品牌名称字符串。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## setMajorVersion

setMajorVersion(majorVersion: string): void

设置主版本号。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| majorVersion | string | 是 | 主版本号，不能为空字符串。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getMajorVersion

getMajorVersion(): string

获取主版本号。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 返回主版本号字符串。 |

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
| fullVersion | string | 是 | 完整版本号，不能为空字符串。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。

## getFullVersion

getFullVersion(): string

获取完整版本号。

**系统能力：**  SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 返回完整版本号字符串。 |

**示例：**

完整示例代码参考[setUserAgentClientHintsEnabled](./arkts-apis-webview-WebviewController.md#setuseragentclienthintsenabled24)。
