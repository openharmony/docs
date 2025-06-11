# @ohos.multimodalAwareness.metadataBinding (Metadata Binding)

The **metadataBinding** module provides metadata binding–specific functions such as metadata transfer, event subscription, and event unsubscription.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import
```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
```

## submitMetadata(string)
function submitMetadata(metadata: string): void;  
Transfers the metadata to be encoded to the MSDP. The MSDP determines whether to transfer the metadata to the system application or service that calls the encoding API. 
**System capability**: SystemCapability.MultimodalAwareness.metadataBinding

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | Yes  | Metadata to be encoded.|

**Error codes** 

For details about the error codes, see [Metadata Binding Error Codes](errorcode-metadataBinding.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|32100001|Internal handling failed. File creation failed.|

**Example**

```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let metadata: string = "";
try {
  metadataBinding.submitMetadata(metadata);
} catch (error) {
  console.error("submit metadata error" + error);
}
```

## metadataBinding.on('operationSubmitMetadata', string,  Callback\<number\>)
metadataBinding.on(type: 'operationSubmitMetadata', bundleName: string, callback: Callback\<number\>): void;  

Subscribes to a system event to obtain the encoded metadata. The application needs to register a callback to return the encoded metadata when the registered system event occurs. 
**System capability**: SystemCapability.MultimodalAwareness.metadataBinding 
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
|32100001|Internal handling failed. File creation failed.|
|32100004|Subscription failed. Possible causes: 1. Abnormal system capability; 2. IPC exception; 3. Algorithm loading exception.|

**Example** 
```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName: string = '';
try {
  metadataBinding.on('operationSubmitMetadata', bundleName, (event: number) =>{
    if (event == 1) {
      console.info("The screenshot request is intercepted and the app link is obtained");
    }
  });
} catch (error) {
  console.info("register screenshot event error");
}
```


## metadataBinding.off('operationSubmitMetadata', string,  Callback\<number\>)
metadataBinding.off(type: 'operationSubmitMetadata', bundleName: string, callback?: Callback\<number>): void;  
Unsubscribes from system events that are used to obtain the encoded metadata. The respective callback will be unregistered. 
**System capability**: SystemCapability.MultimodalAwareness.metadataBinding 
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
|32100001|Internal handling failed. File creation failed.|
|32100005|Unsubscription failed. Possible causes: 1. Abnormal system capability; 2. IPC exception.|

**Example**

```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName: string = '';
try {
  metadataBinding.off('operationSubmitMetadata', bundleName, (evnet: number)=>{});
} catch (error) {
  console.error("unsubscript screenshot event" + error);
}
```
