# Interface (MediaSource)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 12.

The MediaSource class defines the media data information, which is from [createMediaSourceWithUrl](arkts-apis-media-f.md#mediacreatemediasourcewithurl12).

**System capability**: SystemCapability.Multimedia.Media.Core

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## setMimeType<sup>12+</sup>

setMimeType(mimeType: AVMimeTypes): void

Sets the MIME type to help the player process extended media sources.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| mimeType | [AVMimeTypes](arkts-apis-media-e.md#avmimetypes12) | Yes  | MIME type.|

## setMediaResourceLoaderDelegate<sup>18+</sup>

setMediaResourceLoaderDelegate(resourceLoader: MediaSourceLoader): void

Sets a MediaSourceLoader object, which is used to help the player request media data.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| resourceLoader | [MediaSourceLoader](arkts-apis-media-i.md#mediasourceloader18) | Yes  | MediaSourceLoader object used to obtain media data for the player.|

**Example**

```ts
import HashMap from '@ohos.util.HashMap';

let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
let uuid: number = 1;
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();

let sourceOpenCallback: media.SourceOpenCallback = (request: media.MediaSourceLoadingRequest) => {
  console.log(`Opening resource: ${request.url}`);
  // Open the resource and return a unique handle, ensuring the mapping between the UUID and request.
  uuid += 1;
  requests.set(uuid, request);
  return uuid;
};

let sourceReadCallback: media.SourceReadCallback = (uuid: number, requestedOffset: number, requestedLength: number) => {
  console.log(`Reading resource with handle ${uuid}, offset: ${requestedOffset}, length: ${requestedLength}`);
  // Check whether the UUID is valid and store the read request. Avoid blocking the request while pushing data and header information.
};

let sourceCloseCallback: media.SourceCloseCallback = (uuid: number) => {
  console.log(`Closing resource with handle ${uuid}`);
  // Clear resources related to the current UUID.
  requests.remove(uuid);
};

// Implemented by applications as required.
let resourceLoader: media.MediaSourceLoader = {
  open: sourceOpenCallback,
  read: sourceReadCallback,
  close: sourceCloseCallback
};

mediaSource.setMediaResourceLoaderDelegate(resourceLoader);
```
