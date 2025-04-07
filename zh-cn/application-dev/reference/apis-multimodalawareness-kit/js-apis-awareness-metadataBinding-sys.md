# @ohos.multimodalAwareness.metadataBinding (回旋镖)

本模块提供回旋镖能力调用，用于在图片加入和解析相关信息，完成信息传递。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。


## 导入模块
```ts
import { metadataBinding  }'@ohos.multimodalAwareness';
```

## encodeImage(image.PixelMap, string)
encodeImage(srcImage: image.PixelMap, metadata: string): Promise<image.PixelMap>;  
在图片中加入信息  
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding
**系统API**：此接口为系统接口

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | PixelMap                           | 是   | 原始图片。 |
| metadata     | string                             | 是   | 嵌入的信息。|
| Promise | Promise<image.PixelMap>                 | 是   |  回调函数，返回嵌入信息的图片。|

**错误码**:  

以下错误码的详细介绍请参见[回旋镖错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API.|
|   401    | Parameter error. Parameter verification failed.|
|32100001  | Internal handling failed. File creation failed.|
|32100002  | Encode process fail.|

**示例**：

```ts
import image from '@ohos.multimedia.image';
import { metadataBinding  }'@ohos.multimodalAwareness';
import { BusinessError } from '@kit.BasicServicesKit';

let captureImage: image.PixelMap | undefined;
metadataBinding.encodeImage(metadata, srcImage).then((pixelMap : image.PixelMap) =>{
	captureImage = pixelMap;
}).catch((error:BusinessError)=>{
	console.error("encode image error" + error);
});
```

## decodeImage(image.PixelMap)
function decodeImage(encodedImage: image.PixelMap): Promise\<string\>
解析图片中携带的信息。

**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding
**系统API**：此接口为系统接口

**参数**：  

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | PixelMap                           | 是   | 带有信息的图片。 |
|Promise|Promise\<string\>|是|回调函数，返回从图片解析出的信息。|

**错误码**：  

以下错误码的详细介绍请参见[回旋镖错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API.|
|   401    | Parameter error. Parameter verification failed.|
|32100001  | Internal handling failed. File read failed.|
|32100003  | Decode process fail.|

**示例：**  
```ts
import image from '@ohos.multimedia.image';
import { metadataBinding  }'@ohos.multimodalAwareness';
import { BusinessError } from '@kit.BasicServicesKit';

let encodeImage: image.PixelMap | undefined;
metadataBinding.decodeImage(srcImage).then((metadata : string) =>{
}).catch((error:BusinessError)=>{
	console.error("decode image error" + error);
}); 
```

## notifyMetadataBindingEvent(string)
notifyMetadataBindingEvent(metadata: string): void；
推送待嵌入的信息给调用编码接口的应用或服务。
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding
**系统API**：此接口为系统接口

**参数**：  

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | 是   | 要嵌入图片中的信息。 |

**错误码**：  

以下错误码的详细介绍请参见[回旋镖错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   401    | Parameter error. Parameter verification failed.|
|32100001|Internal handling failed. Obtain metadata failed.|

**示例**：

```ts
import { metadataBinding  }'@ohos.multimodalAwareness';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName:string = '';
metadataBinding.notifyMetadataBindingEvent(metadata).then((metadata : string) =>{
}).catch((error:BusinessError)=>{
  console.error("get metadata error" + error);
});
```