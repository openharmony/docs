# Class (JsMessageExt)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements a **JsMessageExt** object that is returned after the [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10) API is invoked.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 10.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## getType<sup>10+</sup>

getType(): JsMessageType

Obtains the type of the data object. For details about the sample code, see [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description                                                     |
| --------------| --------------------------------------------------------- |
| [JsMessageType](./arkts-apis-webview-e.md#jsmessagetype10) | Data type of the result returned after the [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10) API is executed.|

## getString<sup>10+</sup>

getString(): string

Obtains string-type data of the data object. For details about the sample code, see [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| string | Data of the string type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getNumber<sup>10+</sup>

getNumber(): number

Obtains number-type data of the data object. For details about the sample code, see [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| number | Data of the number type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getBoolean<sup>10+</sup>

getBoolean(): boolean

Obtains Boolean-type data of the data object. For details about the sample code, see [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| boolean | Data of the Boolean type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

Obtains raw binary data of the data object. For details about the sample code, see [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| ArrayBuffer | Raw binary data.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

Obtains array-type data of the data object. For details about the sample code, see [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | Data of the array type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
