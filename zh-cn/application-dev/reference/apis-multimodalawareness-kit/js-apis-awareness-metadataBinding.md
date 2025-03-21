# @ohos.multimodalAwareness.metadataBinding (回旋镖)

本模块，提供回旋镖能力调用，用于在图片加入和解析相关信息，完成信息传递

> **说明：**
>
> 本模块首批接口从API version 15开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块
```ts
import { motion } from '@kit.MultimodalAwarenessKit';
```

## encodeImage(image.PixelMap, string)
encodeImage(srcImage: image.PixelMap, metadata: string): Promise<image.PixelMap>; 
在图片中加入信息 
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | PixelMap                           | 是   | 原始图片 |
| metadata     | string                             | 是   | 嵌入的信息|
| Promise | Promise<image.PixelMap>                 | 是   |  回调函数，返回嵌入信息的图片|

**错误码**：
| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | 权限管控，非系统应用调用系统API|
|   401    | 参数校验失败，输入参数不满足要求|
|32100001  | 内部函数调用失败，文件创建失败|
|32100002  | 编码程序运行失败|

**示例**：

```ts
let captureImage: imageManager.PixelMap | undefined;
metadataBinding.encodeImage(metadataValue, captureImage).then((pixelMap : imageManager.PixelMap) =>{
	captureImage = pixelMap;
}).catch((error:Error)=>{
	console.error("encode image error" + error);
});
```

## decodeImage(image.PixelMap)
function decodeImage(encodedImage: image.PixelMap): Promise<string>; 
从图片中解析出信息

**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding

**参数**：
| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | PixelMap                           | 是   | 带有信息的图片 |
|Promise|Promise<string>|是|回调函数，返回从图片解析出的信息|

**错误码**：
| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | 权限管控，非系统应用调用系统API|
|   401    | 参数校验失败，输入参数不满足要求|
|32100001  | 内部函数调用失败，文件创建失败|
|32100003  | 解码程序运行失败|

## notifyMetadataBindingEvent(string)
submitMetadata(metadata: string): void；
把需要嵌入的信息传递给需要调用编码接口的应用或服务
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding

**参数**：
| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | 是   | 要嵌入图片中的信息 |

**错误码**：
| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   401    | 参数校验失败，输入参数不满足要求|
|32100001|程序运行失败，参数传递给调用编码接口的程序或服务出现错误|

**示例**：

```ts
let bundleName:string = '';
metadataBinding.notifyMetadataBindingEvent(bundleName).then((metadata : string) =>{
}).catch((error:BusinessError)=>{
  console.error("get metadata error" + error);
});
```

## submitMetadata(string)
function submitMetadata(metadata: string): void;
三方应用把需要编码的内容传递给MSDP，由MSDP决定适时传递给调用编码接口的系统应用或服务 
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding

**参数**：
| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | 是   | 要嵌入图片中的信息 |

**错误码**：
| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   401    | 参数校验失败，输入参数不满足要求|
|32100001|程序运行失败，参数传递给调用编码接口的程序或服务出现错误|


```ts
let metadata:string = "";
metadataBinding.submitMetadata(metadata).catch((error:BusinessError)=>{
  console.error("submit metadata error" + error);
});
```

## metadataBinding.on('operationSubmitMetadata', string)
metadataBinding.on(type: 'operationSubmitMetadata', bundleName: string, callback: Callback<number>): void;

订阅系统要求获取编码内容的事件，应用注册回调，当事件发生时回传编码内容
系统能力：SystemCapability.MultimodalAwarness.metadataBinding
**参数**：
| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type| string|是|type为，‘operationSubmitMetadata’事件类型，|
|bundlename|string|是|应用包名|标识注册应用的包名|
|callback|Callback<number>|是|回调函数，用于返回编码内容| 

**错误码**：
| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|401|参数错误|
|32100001|内部错误，服务异常|
|32100004|注册失败|


## metadataBinding.off('operationSubmitMetadata', string)
off(type: 'operationSubmitMetadata', bundleName: string, callback?: Callback<number>): void;
去订阅系统获取编码内容的事件。去注册回调接口
**系统能力**：SystemCapability.MultimodalAwarness.metadataBinding
**参数**：
| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type|string|是|事件类型，type为“operationSubmitMetadata”，表示系统应用获取编码内容|
|callback|Callback<number>|是|回调函数，返回编码内容|
**错误码**：
| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|401|参数错误|
|32100001|内部错误，服务异常|
|32100005|去订阅失败|

```ts
let bundleName:string = '';
metadataBinding.off('operationSubmitMetadata', bundleName, (evnet:number)=>{}).catch((error:Error)=>{
	console.error("unsubscript screenshot event" + error);
});
```