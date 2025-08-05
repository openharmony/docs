# Interface (MediaAssetProgressHandler)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 15.

MediaAssetProgressHandler is used to obtain the media asset processing progress from **onProgress()**.

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## onProgress<sup>15+</sup>

onProgress(progress: number): void

Called when the progress of the requested video is returned.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| progress | number | Yes  | Progress in percentage. <br>Value range: 0 to 100|
