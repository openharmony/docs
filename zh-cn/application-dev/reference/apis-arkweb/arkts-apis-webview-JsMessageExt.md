# Class (JsMessageExt)

[runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10)接口执行脚本返回的数据对象。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 10开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## getType<sup>10+</sup>

getType(): JsMessageType

获取数据对象的类型。完整示例代码参考[runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明                                                      |
| --------------| --------------------------------------------------------- |
| [JsMessageType](./arkts-apis-webview-e.md#jsmessagetype10) | [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10)接口脚本执行后返回的结果的类型。 |

## getString<sup>10+</sup>

getString(): string

获取数据对象的字符串类型数据。完整示例代码参考[runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| string | 返回字符串类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getNumber<sup>10+</sup>

getNumber(): number

获取数据对象的数值类型数据。完整示例代码参考[runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| number | 返回数值类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getBoolean<sup>10+</sup>

getBoolean(): boolean

获取数据对象的布尔类型数据。完整示例代码参考[runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| boolean | 返回布尔类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

获取数据对象的原始二进制数据。完整示例代码参考[runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| ArrayBuffer | 返回原始二进制数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

获取数据对象的数组类型数据。完整示例代码参考[runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | 返回数组类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
