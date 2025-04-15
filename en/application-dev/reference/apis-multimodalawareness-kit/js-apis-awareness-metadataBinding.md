# @ohos.multimodalAwareness.metadataBinding (Metadata Binding)

The **metadataBinding** module provides metadata binding–specific functions such as metadata transfer, event subscription, and event unsubscription.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import
```ts
import { metadataBinding  }'@ohos.multimodalAwareness';
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
import { metadataBinding  }'@ohos.multimodalAwareness';
import { BusinessError } from '@kit.BasicServicesKit';

let metadata:string = "";
metadataBinding.submitMetadata(metadata).catch((error:BusinessError)=>{
  console.error("submit metadata error" + error);
});
```

## metadataBinding.on('operationSubmitMetadata', string)
metadataBinding.on(type: 'operationSubmitMetadata', bundleName: string, callback: Callback\<number\>): void;  

Subscribes to a system event to obtain the encoded metadata. The application needs to register a callback to return the encoded metadata when the registered system event occurs. 
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
import { metadataBinding  }'@ohos.multimodalAwareness';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName:string = '';
metadataBinding.on('operationSubmitMetadata', bundleName, (evnet:number)=>{
	if (event == 1) {
		console.info("The screenshot request is intercepted and the app link is obtained");
	}
}).catch((error:BusinessError)=>{
	console.error("subscript screenshot event" + error);
});
```


## metadataBinding.off('operationSubmitMetadata', string)
metadataBinding.off(type: 'operationSubmitMetadata', bundleName: string, callback?: Callback\<number>): void;  
Unsubscribes from system events that are used to obtain the encoded metadata. The respective callback will be unregistered. 
**System capability**: SystemCapability.MultimodalAwarness.metadataBinding 
**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type|string|Yes|Event type. This parameter has a fixed value of **operationSubmitMetadata**, indicating the system application's attempt to obtain the encoded metadata.|
|bundlename|string|Yes|Application bundle name.|
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
import { metadataBinding  }'@ohos.multimodalAwareness';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName:string = '';
metadataBinding.off('operationSubmitMetadata', bundleName, (evnet:number)=>{}).catch((error:BusinessError)=>{
	console.error("unsubscript screenshot event" + error);
});
```
