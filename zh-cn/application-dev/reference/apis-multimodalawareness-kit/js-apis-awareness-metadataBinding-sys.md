# @ohos.multimodalAwareness.metadataBinding (记忆链接)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: Msdp-->
<!--Owner: @codexu62-->
<!--Designer: @yuxiaoyang-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->

本模块提供记忆链接能力调用，用于在图片加入和解析相关信息，完成信息传递。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。


## 导入模块
```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
```

## metadataBinding.encodeImage
encodeImage(srcImage: image.PixelMap, metadata: string): Promise&lt;image.PixelMap&gt;

在图片中加入信息。

**系统能力**：SystemCapability.MultimodalAwareness.metadataBinding

**系统API**：此接口为系统接口

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | PixelMap                           | 是   | 原始图片。 |
| metadata     | string                             | 是   | 嵌入的信息。|

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;image.PixelMap&gt; | Promise对象。返回嵌入信息的图片。 |

**错误码**:  

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. File creation failed. |
| 32100002 | Encode process fail. Possible causes: 1. Image processing error; 2. Channel coding error. |

**示例**：

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

解析图片中携带的信息。

**系统能力**：SystemCapability.MultimodalAwareness.metadataBinding

**系统API**：此接口为系统接口

**参数**：  

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| encodedImage     | PixelMap                           | 是   | 带有信息的图片。 |

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;string&gt; | Promise对象。返回从图片解析出的信息。 |

**错误码**：  

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. File read failed. |
| 32100003 | Decode process fail. Possible causes: 1. Image is not an encoded Image; 2. Image destroyed, decoding failed. |

**示例：**  
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

推送待嵌入的信息给调用编码接口的应用或服务。

**系统能力**：SystemCapability.MultimodalAwareness.metadataBinding

**系统API**：此接口为系统接口

**参数**：  

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | 是   | 要嵌入图片中的信息。 |

**错误码**：  

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. Obtain metadata failed. |

**示例**：

```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let metadata: string = '';
metadataBinding.notifyMetadataBindingEvent(metadata).catch((error: BusinessError) => {
  console.error("notify metadata error" + error);
});
```