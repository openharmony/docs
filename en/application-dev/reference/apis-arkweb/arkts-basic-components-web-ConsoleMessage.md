# Class (ConsoleMessage)

Implements the **ConsoleMessage** object. For details about the sample code, see [onConsole](./arkts-basic-components-web-events.md#onconsole).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 8.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor

constructor(message: string, sourceId: string, lineNumber: number, messageLevel: MessageLevel)

Constructs a **ConsoleMessage** object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [constructor](#constructor9) instead.

**System capability**: SystemCapability.Web.Webview.Core

## constructor<sup>9+</sup>

constructor()

Constructs a **ConsoleMessage** object.

**System capability**: SystemCapability.Web.Webview.Core

## getLineNumber

getLineNumber(): number

Obtains the number of rows in this console message.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | Number of rows in the console message.|

## getMessage

getMessage(): string

Obtains the log information of this console message.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                    |
| ------ | ---------------------- |
| string | Log information of the console message.|

## getMessageLevel

getMessageLevel(): MessageLevel

Obtains the level of this console message.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                               | Description                    |
| --------------------------------- | ---------------------- |
| [MessageLevel](./arkts-basic-components-web-e.md#messagelevel) | Level of the console message.|

## getSourceId

getSourceId(): string

Obtains the path and name of the web page source file.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Path and name of the web page source file.|
