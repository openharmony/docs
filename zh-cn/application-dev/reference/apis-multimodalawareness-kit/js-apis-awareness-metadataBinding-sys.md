# @ohos.multimodalAwareness.metadataBinding (记忆链接)(系统接口)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: Msdp-->
<!--Owner: @codexu62-->
<!--Designer: @yuxiaoyang-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->

本模块提供记忆链接能力调用，用于向图片加入和解析元数据信息，实现信息传递。适用于需要在图片中存储和传递元数据的场景，可用于防伪、版权保护等场景，为开发者提供灵活的信息嵌入和解析机制。

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

在图片中加入信息。通过特定的编码算法将metadata信息嵌入到图片中，编码过程对图片的视觉呈现影响极小，嵌入的信息可通过decodeImage接口解析。可用于防伪、版权保护等场景。使用Promise异步回调。

**系统能力**：SystemCapability.MultimodalAwareness.metadataBinding

**系统接口**：此接口为系统接口

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| srcImage     | [PixelMap](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/arkts-apis-image-pixelmap)                        | 是   | 待编码的原始图片，用于嵌入metadata信息。     |
| metadata     | string | 是 | 嵌入的信息。字符串编码格式建议使用UTF-8，长度不应超过128Bytes，且避免包含不可打印字符。 |

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;image.PixelMap&gt; | Promise对象。返回嵌入信息的图片。 |

**错误码**：

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. |
| 32100002 | Encode process fail. Possible causes: 1. Image processing error; 2. Channel coding error. |

**示例**：

```ts
import { image } from '@kit.ImageKit';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

let encodedImage: image.PixelMap | undefined = undefined;
let metadata: string = '';
// srcImage需通过image内的接口获取有效的PixelMap对象
let srcImage: image.PixelMap | undefined = undefined;
metadataBinding.encodeImage(srcImage, metadata).then((pixelMap: image.PixelMap) => {
  encodedImage = pixelMap;
}).catch((error: BusinessError) => {
  console.error(`Failed to encode image. Code: ${error.code}, message: ${error.message}`);
});
```

## metadataBinding.decodeImage
decodeImage(encodedImage: image.PixelMap): Promise&lt;string&gt;

解析图片中携带的信息。通过对应的解码算法从图片中提取嵌入的metadata信息。使用Promise异步回调。

**系统能力**：SystemCapability.MultimodalAwareness.metadataBinding

**系统接口**：此接口为系统接口

**参数**：  

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| encodedImage     | [PixelMap](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/arkts-apis-image-pixelmap)                           | 是   | 带有信息的图片，需为通过encodeImage接口处理过的编码图片。 |

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;string&gt; | Promise对象。返回从图片解析出的信息。 |

**错误码**：  

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. |
| 32100003 | Decode process fail. Possible causes: 1. Image is not an encoded Image; 2. Image destroyed, decoding failed. |

**示例：**  
```ts
import { image } from '@kit.ImageKit';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

// encodedImage需通过encodeImage接口处理后的图片获取。
let encodedImage: image.PixelMap | undefined = undefined;
let captureMetadata: string = '';
metadataBinding.decodeImage(encodedImage).then((metadata: string) => {
  // 将从图片解析出的元数据信息保存到captureMetadata变量，供后续使用
  captureMetadata = metadata;
}).catch((error: BusinessError) => {
  console.error(`Failed to decode image. Code: ${error.code}, message: ${error.message}`);
}); 
```

## metadataBinding.notifyMetadataBindingEvent
notifyMetadataBindingEvent(bundleName: string): Promise&lt;string&gt;

推送待嵌入的元数据信息给调用编码接口的应用或服务。系统会向指定包名的应用推送信息，并返回当前所在页面的applink信息，用于后续的编码处理。使用Promise异步回调。

**系统能力**：SystemCapability.MultimodalAwareness.metadataBinding

**系统接口**：此接口为系统接口

**参数**：  

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|bundleName|string|是|应用包名，需为已安装应用的包名。|

**返回值：**

| 类型                          | 说明        |
| ---------------------------- | ---------- |
| Promise&lt;string&gt; | Promise对象。返回当前所在页面的appLink信息。|

**错误码**：

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|   202    | Permission check failed. A non-system application uses the system API. |
| 32100001 | Internal handling failed. |

**示例**：

```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
import { BusinessError } from '@kit.BasicServicesKit';

// bundleName需为已安装应用的包名
let bundleName: string = '';
metadataBinding.notifyMetadataBindingEvent(bundleName).then((appLink:string) => {
  console.info('notify metadata:' + appLink);
}).catch((error: BusinessError) => {
  console.error(`Failed to notify metadata. Code: ${error.code}, message: ${error.message}`);
});
```