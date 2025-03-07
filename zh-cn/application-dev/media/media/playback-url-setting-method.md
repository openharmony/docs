# 使用AVPlayer设置播放URL(ArkTS)
本开发指导将介绍如何使用AVPlayer开发播放功能，在不同的场景下如何设置URL。

当前指导仅介绍播放URL设置方法，其他场景及完整示例代码，请参考[视频播放](video-playback.md)。

当前开发指导将提供以下设置播放URL的方法：
- [流媒体播放场景下设置URL](#流媒体播放场景下设置url)
- [本地Raw文件播放场景下设置URL](#本地raw文件播放场景下设置url)

## 流媒体播放场景下设置URL
**情况一：播放HTTP/HTTPS媒体资源**
```ts
  // 创建avPlayer实例对象。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // 设置对应的播放url。
  avPlayer.url = 'https://xxx.xxx.xxx.mp4';
```

**情况二：HLS媒体资源播放(点播/直播)**
```ts
  // 创建avPlayer实例对象。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // 设置对应的播放url。
  avPlayer.url = 'https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
```

**情况三：设置HTTP请求头信息播放**

当服务器需要校验HTTP请求头信息时，可通过[createMediaSourceWithUrl](../../reference/apis-media-kit/js-apis-media.md#mediacreatemediasourcewithurl12)设置HTTP请求头信息。
```ts
  // 创建avPlayer实例对象。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // 创建mediaSource实例对象，设置媒体来源，定制HTTP请求，如需要，可以键值对的形式设置User-Agent、Cookie、Referer等字段。
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8",  {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value", "Referer" : "Referer-Value"});
  // 设置播放策略，设置缓冲区数据量为20s。
  let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
  // 为avPlayer设置媒体来源和播放策略。
  avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**情况四：通过本地Raw文件中的m3u8文件播放在线流媒体资源**

当应用需要通过解析本地Raw文件中的m3u8文件，播放在线流媒体资源时，可以通过[resourceManager.getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)获取文件描述符，将其拼接成fdUrl，并通过[setMimeType](../../reference/apis-media-kit/js-apis-media.md#setmimetype12)设置MIME类型为APPLICATION_M3U8。
```ts
  import { resourceManager } from '@kit.LocalizationKit';
  // 创建avPlayer实例对象。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // 获取context实例。
  let context = getContext(this) as common.UIAbilityContext;
  let mgr = context.resourceManager;
  // 设置本地m3u8文件名。
  let m3u8FileName : string = "xxx.m3u8";
  // 通过本地m3u8文件名，获取文件描述符。
  let fileDescriptor = await mgr.getRawFd(m3u8FileName);

  // 用文件描述符构造本地m3u8的URL。
  let fd : string = fileDescriptor.fd.toString();
  let offset : string = fileDescriptor.offset.toString();
  let length : string = fileDescriptor.length.toString();
  let fdUrl : string = "fd://" + fd + "?offset=" + offset + "&size=" + length;

  // 按需设置HTTP请求头。
  let headers : Record<string,string> = {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value"};
  // 通过本地m3u8的URL和HTTP请求头构造mediaSource媒体来源。
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl, headers);

  // 设置媒体MIME类型为APPLICATION_M3U8。
  let mimeType : media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
  mediaSource.setMimeType(mimeType);

  // 设置播放策略，设置缓冲区数据量为20s。
  let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
  // 为avPlayer设置媒体来源和播放策略。
  avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**情况五：通过应用沙箱中的m3u8文件播放在线流媒体资源**

当应用需要通过解析应用沙箱中的的m3u8文件，播放在线流媒体资源时，可以通过[fs.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)获取文件句柄，将其拼接成fdUrl，并通过[setMimeType](../../reference/apis-media-kit/js-apis-media.md#setmimetype12)设置MIME类型为APPLICATION_M3U8。
```ts
  import { fileIo as fs } from '@kit.CoreFileKit';
  // 创建avPlayer实例对象。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();

  // 获取context实例。
  let context = getContext(this) as common.UIAbilityContext;
  let mgr = context.resourceManager;
  // 设置本地m3u8文件名。
  let m3u8FileName : string = "xxx.m3u8";
  // 设置本地m3u8沙箱路径。
  let filePath = "/data/storage/el1/bundle/${m3u8FileName}";

  // 通过fs.openSync获取文件句柄。
  let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  let fd : string = file.fd.toString();
  // 用文件句柄构造本地m3u8的URL。
  let fdUrl : string = "fd://" + fd + "?offset=" + "0" + "&size=" + "0";

  // 按需设置HTTP请求头。
  let headers : Record<string,string> = {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value"};
  // 通过本地m3u8的URL和HTTP请求头构造mediaSource媒体来源。
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl, headers);

  // 设置媒体MIME类型为APPLICATION_M3U8。
  let mimeType : media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
  mediaSource.setMimeType(mimeType);

  // 设置播放策略，设置缓冲区数据量为20s。
  let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
  // 为avPlayer设置媒体来源和播放策略。
  avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

## 本地raw文件播放场景下设置URL
**情况一：应用沙箱文件播放**
```ts
  // 创建avPlayer实例对象。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  let fdPath = 'fd://';
  // 通过UIAbilityContext获取沙箱地址filesDir，以Stage模型为例。
  let context = getContext(this) as common.UIAbilityContext;
  let pathDir = context.filesDir;
  let path = '/data/storage/el1/bundle/01.mp3';
  // 打开相应的资源文件地址获取fd，并为url赋值触发initialized状态机上报。
  let file = await fs.open(path);
  fdPath = fdPath + '' + file.fd;
  avPlayer.url = fdPath;
```

**情况二：本地文件播放**
```ts
  // 创建avPlayer实例对象。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // 通过UIAbilityContext的resourceManager成员的getRawFd接口获取媒体资源播放地址。
  // 返回类型为{fd,offset,length},fd为HAP包fd地址，offset为媒体资源偏移量，length为播放长度。
  let context = getContext(this) as common.UIAbilityContext;
  let fileDescriptor = await context.resourceManager.getRawFd('01.mp3');
  let avFileDescriptor: media.AVFileDescriptor =
    { fd: fileDescriptor.fd, offset: fileDescriptor.offset, length: fileDescriptor.length };
  // 为fdSrc赋值触发initialized状态机上报。
  avPlayer.fdSrc = avFileDescriptor;
```