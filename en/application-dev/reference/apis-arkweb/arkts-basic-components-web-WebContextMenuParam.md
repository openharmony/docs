# Class (WebContextMenuParam)

Implements a **WebContextMenuParam** object, which is displayed after the user clicks the right mouse button or long presses a specific element, such as an image or a link. For details about the sample code, see [onContextMenuShow](./arkts-basic-components-web-events.md#oncontextmenushow9).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>9+</sup>

constructor()

Constructs a **WebContextMenuParam** object.

**System capability**: SystemCapability.Web.Webview.Core

## x<sup>9+</sup>

x(): number

Obtains the X coordinate of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | If the display is normal, a non-negative integer is returned. Otherwise, **-1** is returned.<br>Unit: vp.|

## y<sup>9+</sup>

y(): number

Obtains the Y coordinate of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | If the display is normal, a non-negative integer is returned. Otherwise, **-1** is returned.<br>Unit: vp.|

## getLinkUrl<sup>9+</sup>

getLinkUrl(): string

Obtains the URL of the link.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                       |
| ------ | ------------------------- |
| string | If it is a link that is being long pressed, the URL that has passed the security check is returned.|

## getUnfilteredLinkUrl<sup>9+</sup>

getUnfilteredLinkUrl(): string

Obtains the URL of the unfiltered link.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                   |
| ------ | --------------------- |
| string | If it is a link that is being long pressed, the original URL is returned.|

## getSourceUrl<sup>9+</sup>

getSourceUrl(): string

Obtain the source URL.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                      |
| ------ | ------------------------ |
| string | If the selected element has the **src** attribute, the URL in the **src** is returned.|

## existsImageContents<sup>9+</sup>

existsImageContents(): boolean

Checks whether image content exists.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | The value **true** means that there is image content in the element being long pressed, and **false** means the opposite.|

## getMediaType<sup>9+</sup>

getMediaType(): ContextMenuMediaType

Obtains the media type of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description       |
| ---------------------------------------- | --------- |
| [ContextMenuMediaType](./arkts-basic-components-web-e.md#contextmenumediatype9) | Media type of the web page element.|

## getSelectionText<sup>9+</sup>

getSelectionText(): string

Obtains the selected text.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| string | Selected text for the context menu. If no text is selected, null is returned.|

## getSourceType<sup>9+</sup>

getSourceType(): ContextMenuSourceType

Obtains the event source of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| [ContextMenuSourceType](./arkts-basic-components-web-e.md#contextmenusourcetype9) | Event source of the context menu.|

## getInputFieldType<sup>9+</sup>

getInputFieldType(): ContextMenuInputFieldType

Obtains the input field type of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description    |
| ---------------------------------------- | ------ |
| [ContextMenuInputFieldType](./arkts-basic-components-web-e.md#contextmenuinputfieldtype9) | Input field type.|

## isEditable<sup>9+</sup>

isEditable(): boolean

Checks whether this web page element is editable.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | **true** is returned if the web page element is editable; otherwise, **false** is returned.|

## getEditStateFlags<sup>9+</sup>

getEditStateFlags(): number

Obtains the edit state flag of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Edit state flag of the web page element. For details, see [ContextMenuEditStateFlags](./arkts-basic-components-web-e.md#contextmenueditstateflags9).|

## getPreviewWidth<sup>13+</sup>

getPreviewWidth(): number

Obtains the width of a preview image.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description      |
| ------ | ----------- |
| number | Width of a preview image.<br>Unit: vp.|

## getPreviewHeight<sup>13+</sup>

getPreviewHeight(): number

Obtains the height of a preview image.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description      |
| ------ | ----------  |
| number | Height of a preview image.<br>Unit: vp.|
