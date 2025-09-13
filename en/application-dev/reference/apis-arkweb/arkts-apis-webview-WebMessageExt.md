# Class (WebMessageExt)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements a **WebMessageExt** object that received and sent by the [WebMessagePort](./arkts-apis-webview-WebMessagePort.md) API.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 10.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## getType<sup>10+</sup>

getType(): WebMessageType

Obtains the type of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description                                                     |
| --------------| --------------------------------------------------------- |
| [WebMessageType](./arkts-apis-webview-e.md#webmessagetype10) | Data types supported by the [webMessagePort](./arkts-apis-webview-WebMessagePort.md) API.|

## getString<sup>10+</sup>

getString(): string

Obtains string-type data of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| string | Data of the string type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getNumber<sup>10+</sup>

getNumber(): number

Obtains number-type data of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| number | Data of the number type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getBoolean<sup>10+</sup>

getBoolean(): boolean

Obtains Boolean-type data of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| boolean | Data of the Boolean type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

Obtains raw binary data of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| ArrayBuffer | Raw binary data.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

Obtains array-type data of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | Data of the array type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getError<sup>10+</sup>

getError(): Error

Obtains the error-object-type data of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| Error | Data of the error object type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## setType<sup>10+</sup>

setType(type: WebMessageType): void

Sets the type for the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| type  | [WebMessageType](./arkts-apis-webview-e.md#webmessagetype10) | Yes  | Data types supported by the [webMessagePort](./arkts-apis-webview-WebMessagePort.md) API.|

**Error codes**

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setString<sup>10+</sup>

setString(message: string): void

Sets the string-type data of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | string | Yes  | String type.|

**Error codes**

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setNumber<sup>10+</sup>

setNumber(message: number): void

Sets the number-type data of the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | number | Yes  | Data of the number type.|

**Error codes**

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setBoolean<sup>10+</sup>

setBoolean(message: boolean): void

Sets the Boolean-type data for the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | boolean | Yes  | Data of the Boolean type.|

**Error codes**

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setArrayBuffer<sup>10+</sup>

setArrayBuffer(message: ArrayBuffer): void

Sets the raw binary data for the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | ArrayBuffer | Yes  | Raw binary data.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setArray<sup>10+</sup>

setArray(message: Array\<string | number | boolean\>): void

Sets the array-type data for the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | Array\<string \| number \| boolean\> | Yes  | Data of the array type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## setError<sup>10+</sup>

setError(message: Error): void

Sets the error-object-type data for the data object. For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | Error | Yes  | Data of the error object type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
