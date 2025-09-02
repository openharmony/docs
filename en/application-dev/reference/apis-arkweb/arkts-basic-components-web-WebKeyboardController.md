# Class (WebKeyboardController)

Implements a controller to control the input, deletion, and closure of the custom keyboard. For details about the sample code, see [onInterceptKeyboardAttach](./arkts-basic-components-web-events.md#oninterceptkeyboardattach12).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>12+</sup>

constructor()

Constructs a **WebKeyboardController** API.

**System capability**: SystemCapability.Web.Webview.Core

## insertText<sup>12+</sup>

insertText(text: string): void

Inserts characters into the **Web** component text box.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | -------- | ---- | --------------------- |
| text | string | Yes| Characters to insert into the **Web** component text box.|

## deleteForward<sup>12+</sup>

deleteForward(length: number): void

Deletes a specified number of characters forward in a **Web** component text box.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | -------- | ---- | ------------------------ |
| length | number   | Yes  | Length of characters to delete forward in a **Web** component text box.<br>The parameter has no value range. If the parameter value is greater than the character length, all characters before the cursor are deleted by default. If the parameter value is a negative number, the deletion is not performed.|

## deleteBackward12+</sup>

deleteBackward(length: number): void

Deletes a specified number of characters backward in a **Web** component text box.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | -------- | ---- | ------------------------ |
| length | number   | Yes  | Length of characters to delete backward in a **Web** component text box.<br>The parameter has no value range. If the parameter value is greater than the character length, all characters after the cursor are deleted by default. If the parameter value is a negative number, the deletion is not performed.|

## sendFunctionKey<sup>12+</sup>

sendFunctionKey(key: number): void

Inserts a function key. Currently, only the Enter key type is supported. For details about the value, see [EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                                  |
| ------ | -------- | ---- | ------------------------------------------ |
| key    | number   | Yes  | Function key to insert into the **Web** component text box. Currently, only the Enter key is supported.|

## close<sup>12+</sup>

close(): void

Closes this custom keyboard.

**System capability**: SystemCapability.Web.Webview.Core
