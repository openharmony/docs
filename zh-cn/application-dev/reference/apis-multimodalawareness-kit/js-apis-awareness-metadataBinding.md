# @ohos.multimodalAwareness.metadataBinding (回旋镖)

本模块提供回旋镖能力调用，包括编码内容传递、订阅事件和取消订阅事件。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块
```ts
import { metadataBinding  }'@ohos.multimodalAwareness';
```

## submitMetadata(string)
function submitMetadata(metadata: string): void;  
第三方应用将需要编码的内容传递给MSDP，MSDP决定适时将内容传递给调用编码接口的系统应用或服务。  
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | 是   | 要嵌入图片中的信息。 |

**错误码**：  

以下错误码的详细介绍请参见[回旋镖错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   401    | Parameter error. Parameter verification failed.|
|32100001|Internal handling failed. Set Meta data to screenshot app fail.|

**示例**：

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

订阅系统事件以获取编码内容，应用注册回调，事件发生时回传编码内容。  
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding  
**参数**： 

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type| string|是|事件类型，type为‘operationSubmitMetadata’，表示系统应用获取编码内容。|
|bundlename|string|是|应用包名，标识注册应用的包名。|
|callback|Callback\<number\>|是|回调函数，用于返回编码内容。| 

**错误码**：

以下错误码的详细介绍请参见[回旋镖错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|401|Parameter error. Parameter verification failed.|
|32100001|Internal handling failed. Service exception.|
|32100004|Subscribe Failed.|

**示例：**  
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
取消订阅系统获取编码内容的事件。取消注册回调接口。  
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding  
**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type|string|是|事件类型，type为“operationSubmitMetadata”，表示系统应用获取编码内容。|
|bundlename|string|是|应用包名，标识注册应用的包名。|
|callback|Callback\<number\>|是|回调函数，返回编码内容。|

**错误码**：  

以下错误码的详细介绍请参见[回旋镖错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|401|Parameter error. Parameter verification failed.|
|32100001|Internal handling failed. Service exception.|
|32100005|Unsubscribe Failed.|

**示例**：

```ts
import { metadataBinding  }'@ohos.multimodalAwareness';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName:string = '';
metadataBinding.off('operationSubmitMetadata', bundleName, (evnet:number)=>{}).catch((error:BusinessError)=>{
	console.error("unsubscript screenshot event" + error);
});
```
