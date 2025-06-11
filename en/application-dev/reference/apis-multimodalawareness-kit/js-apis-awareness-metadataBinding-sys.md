# @ohos.multimodalAwareness.metadataBinding (Metadata Binding)

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

## encodeImage(image.PixelMap, string)
encodeImage(srcImage: image.PixelMap, metadata: string): Promise<image.PixelMap>;  
Encodes metadata into an image. 
**System capability**: SystemCapability.MultimodalAwarness.metadataBinding
**System API**: This is a system API.

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | PixelMap                           | Yes  | Source image.|
| metadata     | string                             | Yes  | Metadata to encoded.|
| Promise | Promise<image.PixelMap>                 | Yes  |  Callback used to return the image with encoded metadata.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API.|
|32100001  | Internal handling failed. File creation failed.|
|32100002  | Encoding failed. Possible causes: 1. Image processing error; 2. Channel coding error.|

**Example**

```ts
import image from '@ohos.multimedia.image';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let captureImage: image.PixelMap | undefined = undefined;
let metadata: string = "";
let srcImage: image.PixelMap | undefined = undefined;
metadataBinding.encodeImage(srcImage, metadata).then((pixelMap: image.PixelMap) =>{
	captureImage = pixelMap;
}).catch((error:BusinessError)=>{
	console.error("encode image error" + error);
});
```

## decodeImage(image.PixelMap)
function decodeImage(encodedImage: image.PixelMap): Promise\<string\>
Decodes the information carried in the image.

**System capability**: SystemCapability.MultimodalAwarness.metadataBinding
**System API**: This is a system API.

**Parameters** 

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| encodedImage     | PixelMap                           | Yes  | Image with metadata encoded.|
|Promise|Promise\<string\>|Yes|Callback used to return the encoded metadata of the image.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API.|
|32100001  | Internal handling failed. File creation failed.|
|32100003  | Decoding failed. Possible causes: 1. Image not encoded; 2. Image destroyed.|

**Example** 
```ts
import image from '@ohos.multimedia.image';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let encodeImage: image.PixelMap | undefined = undefined;
let captrueMetadata: string = "";
metadataBinding.decodeImage(encodeImage).then((metadata: string) =>{
	captrueMetadata = metadata;
}).catch((error:BusinessError)=>{
	console.error("decode image error" + error);
}); 
```

## notifyMetadataBindingEvent(string)
notifyMetadataBindingEvent(metadata: string): void;
Transfers metadata to the application or service that calls the encoding API.
**System capability**: SystemCapability.MultimodalAwarness.metadataBinding
**System API**: This is a system API.

**Parameters** 

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | Yes  | Metadata to be encoded.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|32100001| Internal handling failed. File creation failed.|

**Example**

```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let metadata:string = '';
metadataBinding.notifyMetadataBindingEvent(metadata).catch((error: BusinessError)=>{
  console.error("notify metadata error" + error);
});
```
