# @ohos.multimodalAwareness.metadataBinding (Metadata Binding)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: Msdp-->
<!--Owner: @codexu62-->
<!--Designer: @yuxiaoyang-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->

The **metadataBinding** module provides the capability of adding metadata to images and parsing the metadata to complete information transfer.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.


## Modules to Import
```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
```

## metadataBinding.encodeImage
encodeImage(srcImage: image.PixelMap, metadata: string): Promise&lt;image.PixelMap&gt;

Encodes metadata into an image.

**System capability**: SystemCapability.MultimodalAwareness.metadataBinding

**System API**: This is a system API.

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | [PixelMap](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/arkts-apis-image-pixelmap)                            | Yes  | Source image.|
| metadata     | string                             | Yes  | Metadata to be encoded.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;image.PixelMap&gt; | Promise used to return the image with encoded metadata.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. File creation failed. |
| 32100002 | Encode process fail. Possible causes: 1. Image processing error; 2. Channel coding error. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let captureImage: image.PixelMap | undefined = undefined;
let metadata: string = "";
let srcImage: image.PixelMap | undefined = undefined;
metadataBinding.encodeImage(srcImage, metadata).then((pixelMap: image.PixelMap) => {
  captureImage = pixelMap;
}).catch((error: BusinessError) => {
  console.error("encode image error" + error);
});
```

## metadataBinding.decodeImage
function decodeImage(encodedImage: image.PixelMap): Promise&lt;string&gt;

Decodes the information carried in the image.

**System capability**: SystemCapability.MultimodalAwareness.metadataBinding

**System API**: This is a system API.

**Parameters** 

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| encodedImage     | [PixelMap](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/arkts-apis-image-pixelmap)                            | Yes  | Image with metadata encoded.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;string&gt; | Promise used to return the encoded metadata of the image.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. File read failed. |
| 32100003 | Decode process fail. Possible causes: 1. Image is not an encoded Image; 2. Image destroyed, decoding failed. |

**Example** 
```ts
import { image } from '@kit.ImageKit';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let encodeImage: image.PixelMap | undefined = undefined;
let captureMetadata: string = "";
metadataBinding.decodeImage(encodeImage).then((metadata: string) => {
  captureMetadata = metadata;
}).catch((error: BusinessError) => {
  console.error("decode image error" + error);
}); 
```

## metadataBinding.notifyMetadataBindingEvent
notifyMetadataBindingEvent(metadata: string): void

Transfers metadata to the application or service that calls the encoding API.

**System capability**: SystemCapability.MultimodalAwareness.metadataBinding

**System API**: This is a system API.

**Parameters** 

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | Yes  | Metadata to be encoded.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. Obtain metadata failed. |

**Example**

```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let metadata: string = '';
metadataBinding.notifyMetadataBindingEvent(metadata).catch((error: BusinessError) => {
  console.error("notify metadata error" + error);
});
```
