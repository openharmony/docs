# @ohos.multimodalAwareness.metadataBinding (Metadata Binding)

The **metadataBinding** module provides the capability of adding metadata to images and parsing the metadata to complete information transfer.

> **NOTE**
>
> The initial APIs of this module are supported since API version 15. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import
```ts
import { motion } from '@kit.MultimodalAwarenessKit';
```

## encodeImage(image.PixelMap, string)
encodeImage(srcImage: image.PixelMap, metadata: string): Promise<image.PixelMap>;  
Encodes metadata into an image. 
**System capability**: SystemCapability.MultimodalAwarness.metadataBinding

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
|   401    | Parameter error. Parameter verification failed.|
|32100001  | Internal handling failed. File creation failed.|
|32100002  | Encode process fail.|

**Example**

```ts
let captureImage: imageManager.PixelMap | undefined;
metadataBinding.encodeImage(metadataValue, captureImage).then((pixelMap : imageManager.PixelMap) =>{
	captureImage = pixelMap;
}).catch((error:Error)=>{
	console.error("encode image error" + error);
});
```

## decodeImage(image.PixelMap)
function decodeImage(encodedImage: image.PixelMap): Promise\<string\>
Parses encoded metadata from an image.

**System capability**: SystemCapability.MultimodalAwarness.metadataBinding

**Parameters** 

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | PixelMap                           | Yes  | Image with metadata encoded.|
|Promise|Promise\<string\>|Yes|Callback used to return the encoded metadata of the image.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API.|
|   401    | Parameter error. Parameter verification failed.|
|32100001  | Internal handling failed. File read failed.|
|32100003  | Decode process fail.|

**Example** 
```ts
let encodeImage: imageManager.PixelMap | undefined;
metadataBinding.decodeImage(encodeImage).then((metadata : string) =>{
}).catch((error:Error)=>{
	console.error("decode image error" + error);
}); 
```

## notifyMetadataBindingEvent(string)
submitMetadata(metadata: string): void;
Transfers metadata to the application or service that calls the encoding API. 
**System capability**: SystemCapability.MultimodalAwarness.metadataBinding

**Parameters** 

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | Yes  | Metadata to be encoded.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|   401    | Parameter error. Parameter verification failed.|
|32100001|Internal handling failed. Obtain metadata failed.|

**Example**

```ts
let bundleName:string = '';
metadataBinding.notifyMetadataBindingEvent(bundleName).then((metadata : string) =>{
}).catch((error:BusinessError)=>{
  console.error("get metadata error" + error);
});
```

## submitMetadata(string)
function submitMetadata(metadata: string): void;  
Transfers the metadata to be encoded to the MSDP. The MSDP determines whether to transfer the metadata to the system application or service that calls the encoding API. 
**System capability**: SystemCapability.MultimodalAwarness.metadataBinding

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | Yes  | Metadata to be encoded.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|   401    | Parameter error. Parameter verification failed.|
|32100001|Internal handling failed. Set Meta data to screenshot app fail.|

**Example**

```ts
let metadata:string = "";
metadataBinding.submitMetadata(metadata).catch((error:BusinessError)=>{
  console.error("submit metadata error" + error);
});
```

## metadataBinding.on('operationSubmitMetadata', string)
metadataBinding.on(type: 'operationSubmitMetadata', bundleName: string, callback: Callback\<number\>): void;  

Enables listening for **operationSubmitMetadata** events. An application can register a callback to transfer the encoded metadata when such an event occurs. 
**System capability**: SystemCapability.MultimodalAwarness.metadataBinding 
**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type| string|Yes|Event type. This parameter has a fixed value of **operationSubmitMetadata**, indicating the system application's attempt to obtain the encoded metadata.|
|bundlename|string|Yes|Application bundle name.|
|callback|Callback\<number\>|Yes|Callback used to return the encoded metadata.| 

**Error codes**

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|401|Parameter error. Parameter verification failed.|
|32100001|Internal handling failed. Service exception.|
|32100004|Subscribe Failed.|

**Example** 
```ts
let bundleName:string = '';
metadataBinding.on('operationSubmitMetadata', bundleName, (evnet:number)=>{
	if (event == 1) {
		console.info("The screenshot request is intercepted and the app link is obtained");
	}
}).catch((error:Error)=>{
	console.error("subscript screenshot event" + error);
});
```


## metadataBinding.off('operationSubmitMetadata', string)
off(type: 'operationSubmitMetadata', bundleName: string, callback?: Callback\<number>): void;  
Disables listening for **operationSubmitMetadata** events.   
**System capability**: SystemCapability.MultimodalAwarness.metadataBinding 
**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type|string|Yes|Event type. This parameter has a fixed value of **operationSubmitMetadata**, indicating the system application's attempt to obtain the encoded metadata.|
|callback|Callback\<number\>|Yes|Callback used to return the encoded metadata.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|401|Parameter error. Parameter verification failed.|
|32100001|Internal handling failed. Service exception.|
|32100005|Unsubscribe Failed.|

**Example**

```ts
let bundleName:string = '';
metadataBinding.off('operationSubmitMetadata', bundleName, (evnet:number)=>{}).catch((error:Error)=>{
	console.error("unsubscript screenshot event" + error);
});
```
