# Class (WebMessageExt)

[WebMessagePort](./arkts-apis-webview-WebMessagePort.md)接口接收、发送的数据对象。

> **说明：**
>
> - 本模块接口从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## getType<sup>10+</sup>

getType(): WebMessageType

获取数据对象的类型。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明                                                      |
| --------------| --------------------------------------------------------- |
| [WebMessageType](./arkts-apis-webview-e.md#webmessagetype10) | [webMessagePort](./arkts-apis-webview-WebMessagePort.md)接口所支持的数据类型。 |

## getString<sup>10+</sup>

getString(): string

获取数据对象的字符串类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

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

获取数据对象的数值类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

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

获取数据对象的布尔类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

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

获取数据对象的原始二进制数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

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

获取数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

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

## getError<sup>10+</sup>

getError(): Error

获取数据对象的错误类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| Error | 返回错误对象类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## setType<sup>10+</sup>

setType(type: WebMessageType): void

设置数据对象的类型。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| type  | [WebMessageType](./arkts-apis-webview-e.md#webmessagetype10) | 是   | [webMessagePort](./arkts-apis-webview-WebMessagePort.md)接口所支持的数据类型。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setString<sup>10+</sup>

setString(message: string): void

设置数据对象的字符串类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | string | 是   | 字符串类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setNumber<sup>10+</sup>

setNumber(message: number): void

设置数据对象的数值类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | number | 是   | 数值类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setBoolean<sup>10+</sup>

setBoolean(message: boolean): void

设置数据对象的布尔类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | boolean | 是   | 布尔类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setArrayBuffer<sup>10+</sup>

setArrayBuffer(message: ArrayBuffer): void

设置数据对象的原始二进制数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | ArrayBuffer | 是   | 原始二进制类型数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setArray<sup>10+</sup>

setArray(message: Array\<string | number | boolean\>): void

设置数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | Array\<string \| number \| boolean\> | 是   | 数组类型数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setError<sup>10+</sup>

setError(message: Error): void

设置数据对象的错误对象类型数据。完整示例代码参考[onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | Error | 是   | 错误对象类型数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |