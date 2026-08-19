# Class (FileSelectorParam)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

Implements the **FileSelectorParam** object to obtain files. For details about the sample code, see [onShowFileSelector](./arkts-basic-components-web-events.md#onshowfileselector9).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - The sample effect is subject to the actual device.

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

## getSuggestedName<sup>23+</sup>

getSuggestedName(): string

Obtains the suggested file name, which corresponds to **suggestedName** in HTML's [option](../../web/web-file-upload.md#custom-processing-of-file-requests-invoked-by-js-apis).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Suggested file name.|

## getDefaultPath<sup>23+</sup>

getDefaultPath(): string

Obtains the default path of the file selector, which corresponds to **startIn** in HTML's [option](../../web/web-file-upload.md#custom-processing-of-file-requests-invoked-by-js-apis).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Default path.<br>If **startIn** is set to the public directory **downloads** or **pictures**, convert it to **download** or **images** in HarmonyOS.|

## getDescriptions<sup>23+</sup>

getDescriptions(): Array\<string\>

Obtains the descriptions of a group of file types, which are optional descriptions of allowed file types and correspond to **description** in HTML's [option](../../web/web-file-upload.md#custom-processing-of-file-requests-invoked-by-js-apis).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description       |
| --------------- | --------- |
| Array\<string\> | Description array of the file types.|

## isAcceptAllOptionExcluded<sup>23+</sup>

isAcceptAllOptionExcluded(): boolean

Checks whether the file selector supports the option (\*\/\*), that is, all files. This API corresponds to **excludeAcceptAllOption** in HTML's [option](../../web/web-file-upload.md#custom-processing-of-file-requests-invoked-by-js-apis).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description          |
| ------- | ------------ |
| boolean | Whether an option that does not apply any file type filter is excluded.<br>The value **true** indicates that an option that does not apply any file type filter is exclueded, and **false** indicates the opposite.|

## getAcceptableFileTypes<sup>23+</sup>

getAcceptableFileTypes(): Array\<Array\<AcceptableFileType\>>

Obtains the file types, which correspond to **types** in HTML's [option](../../web/web-file-upload.md#custom-processing-of-file-requests-invoked-by-js-apis).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description       |
| --------------- | --------- |
| Array\<Array\<[AcceptableFileType](./arkts-basic-components-web-i.md#acceptablefiletype23)\>> | File types.|
