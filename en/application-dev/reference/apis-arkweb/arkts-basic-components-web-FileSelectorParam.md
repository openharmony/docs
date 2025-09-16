# Class (FileSelectorParam)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements the **FileSelectorParam** object to obtain files. For details about the sample code, see [onShowFileSelector](./arkts-basic-components-web-events.md#onshowfileselector9).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>9+</sup>

constructor()

Constructs a **FileSelectorParam**.

**System capability**: SystemCapability.Web.Webview.Core

## getTitle<sup>9+</sup>

getTitle(): string

Obtains the title of this file selector.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Title of the file selector.|

## getMode<sup>9+</sup>

getMode(): FileSelectorMode

Obtains the mode of the file selector.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description         |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](./arkts-basic-components-web-e.md#fileselectormode9) | Mode of the file selector.|

## getAcceptType<sup>9+</sup>

getAcceptType(): Array\<string\>

Obtains the file filtering type.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description       |
| --------------- | --------- |
| Array\<string\> | File filtering type.|

## isCapture<sup>9+</sup>

isCapture(): boolean

Checks whether multimedia capabilities are invoked.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description          |
| ------- | ------------ |
| boolean | Whether multimedia capabilities are invoked.<br>The value **true** indicates that multimedia capabilities are invoked, and **false** indicates the opposite.|

## getMimeTypes<sup>18+</sup>

getMimeTypes(): Array\<string\>

Obtains the MIME type of a file.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description       |
| --------------- | --------- |
| Array\<string\> | MIME type of a file.|
