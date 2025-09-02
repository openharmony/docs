# Class (FileSelectorResult)

Implements the **FileSelectorResult** object to notify the file selection result. For details about the sample code, see [onShowFileSelector](./arkts-basic-components-web-events.md#onshowfileselector9).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>9+</sup>

constructor()

Constructs a **FileSelectorResult**.

**System capability**: SystemCapability.Web.Webview.Core

## handleFileList<sup>9+</sup>

handleFileList(fileList: Array\<string\>): void

Instructs the **Web** component to select a file.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type           | Mandatory | Description        |
| -------- | --------------- | ---- | ------------ |
| fileList | Array\<string\> | Yes  | List of files to operate.|
