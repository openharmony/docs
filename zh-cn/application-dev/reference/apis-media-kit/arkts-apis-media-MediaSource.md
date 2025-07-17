# Interface (MediaSource)

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 12开始支持。

媒体数据信息。来源自[createMediaSourceWithUrl](arkts-apis-media-f.md#mediacreatemediasourcewithurl12)。

**系统能力：** SystemCapability.Multimedia.Media.Core

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```

## setMimeType<sup>12+</sup>

setMimeType(mimeType: AVMimeTypes): void

设置媒体MIME类型，以帮助播放器处理扩展的媒体源。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| mimeType | [AVMimeTypes](arkts-apis-media-e.md#avmimetypes12) | 是   | 媒体MIME类型。 |

## setMediaResourceLoaderDelegate<sup>18+</sup>

setMediaResourceLoaderDelegate(resourceLoader: MediaSourceLoader): void

设置MediaSourceLoader，帮助播放器请求媒体数据。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| resourceLoader | [MediaSourceLoader](arkts-apis-media-i.md#mediasourceloader18) | 是   | 应用实现的媒体数据获取接口，方便播放器获取数据。 |

**示例：**

```ts
import HashMap from '@ohos.util.HashMap';

let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
let uuid: number = 1;
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();

let sourceOpenCallback: media.SourceOpenCallback = (request: media.MediaSourceLoadingRequest) => {
  console.log(`Opening resource: ${request.url}`);
  // 成功打开资源，返回唯一的句柄, 保证uuid和request对应。
  uuid += 1;
  requests.set(uuid, request);
  return uuid;
};

let sourceReadCallback: media.SourceReadCallback = (uuid: number, requestedOffset: number, requestedLength: number) => {
  console.log(`Reading resource with handle ${uuid}, offset: ${requestedOffset}, length: ${requestedLength}`);
  // 判断uuid是否合法、存储read请求，不要在read请求阻塞去推送数据和头信息。
};

let sourceCloseCallback: media.SourceCloseCallback = (uuid: number) => {
  console.log(`Closing resource with handle ${uuid}`);
  // 清除当前uuid相关资源。
  requests.remove(uuid);
};

// 应用按需实现。
let resourceLoader: media.MediaSourceLoader = {
  open: sourceOpenCallback,
  read: sourceReadCallback,
  close: sourceCloseCallback
};

mediaSource.setMediaResourceLoaderDelegate(resourceLoader);
```