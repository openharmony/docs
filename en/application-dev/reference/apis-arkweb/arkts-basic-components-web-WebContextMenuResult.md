# Class (WebContextMenuResult)

Implements a **WebContextMenuResult** object. For details about the sample code, see [onContextMenuShow](./arkts-basic-components-web-events.md#oncontextmenushow9).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>9+</sup>

constructor()

Constructs a **WebContextMenuResult** object.

**System capability**: SystemCapability.Web.Webview.Core

## closeContextMenu<sup>9+</sup>

closeContextMenu(): void

Closes this context menu. This API must be called when no operations in **WebContextMenuResult** are performed.

**System capability**: SystemCapability.Web.Webview.Core

## copyImage<sup>9+</sup>

copyImage(): void

Copies the image specified in **WebContextMenuParam**.

**System capability**: SystemCapability.Web.Webview.Core

## copy<sup>9+</sup>

copy(): void

Copies text related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

## paste<sup>9+</sup>

paste(): void

Performs the paste operation related to this context menu.

> **NOTE**
>
> The **ohos.permission.READ_PASTEBOARD** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

## cut<sup>9+</sup>

cut(): void

Performs the cut operation related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

## selectAll<sup>9+</sup>

selectAll(): void

Performs the select all operation related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

## undo<sup>20+</sup>

undo(): void

Performs the undo operation related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

## redo<sup>20+</sup>

redo(): void

Performs the redo operation related to this context menu, that is, cancels the last undo operation.

**System capability**: SystemCapability.Web.Webview.Core

## pasteAndMatchStyle<sup>20+</sup>

pasteAndMatchStyle(): void

Performs the paste operation related to the context menu. The pasted content matches the target format and is displayed in plain text.

> **NOTE**
>
> The **ohos.permission.READ_PASTEBOARD** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core
