# 使用AVPlayer设置播放URL(ArkTS)
本开发指导将介绍如何使用AVPlayer开发播放功能，在不同的场景下如何设置URL。

当前指导仅介绍播放URL设置方法，其他场景及完整示例代码，请参考[视频播放](video-playback.md)。

当前开发指导将提供以下设置播放URL的方法：
- [流媒体播放场景下设置URL](#流媒体播放场景下设置url)
- [本地Raw文件播放场景下设置URL](#本地raw文件播放场景下设置url)

## 流媒体播放场景下设置URL
**情况一：播放HTTP/HTTPS媒体资源**
```ts
  let url = 'https://xxx.xxx.xxx.mp4';
  this.avPlayer.url = url; // 设置对应的播放url
```

**情况二：HLS媒体资源播放(点播/直播)**
```ts
  let url = 'https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  this.avPlayer.url = url; // 设置对应的播放url
```

**情况三：设置HTTP请求头信息播放**

当服务器需要校验HTTP请求头信息时，可通过[createMediaSourceWithUrl](../../reference/apis-media-kit/js-apis-media.md#mediacreatemediasourcewithurl12)设置HTTP请求头信息。
```ts
  let url = 'https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  // 创建mediaSource实例对象，设置媒体来源，定制HTTP请求，如需要，可以键值对的形式设置User-Agent、Cookie、Referer等字段
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(url,  {'aa' : 'bb', 'cc' : 'dd'});
  // 设置播放策略，设置缓冲区数据量为20s
  let playbackStrategy : media.PlaybackStrategy =
    {preferredWidth: 1, preferredHeight: 2, preferredBufferDuration: 3, preferredHdr: false};
  // 为avPlayer设置媒体来源和播放策略
  this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**情况四：通过本地Raw文件中的m3u8文件播放在线流媒体资源**

当应用需要通过解析本地Raw文件中的m3u8文件，播放在线流媒体资源时，可以通过[resourceManager.getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)获取文件描述符，将其拼接成fdUrl，并通过[setMimeType](../../reference/apis-media-kit/js-apis-media.md#setmimetype12)设置MIME类型为APPLICATION_M3U8。
```ts
  // 通过本地m3u8文件名，获取文件描述符
  let fileDescriptor = await this.context.resourceManager.getRawFd('xxx.m3u8');
  // 用文件描述符构造本地m3u8的URL
  let fdUrl : string = "fd://" + fileDescriptor.fd +
    "?offset=" + fileDescriptor.offset + "&size=" + fileDescriptor.length;
  // 按需设置HTTP请求头
  let headers : Record<string,string> = {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value"};
  // 通过本地m3u8的URL和HTTP请求头构造mediaSource媒体来源
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl, headers);

  // 设置媒体MIME类型为APPLICATION_M3U8
  let mimeType : media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
  mediaSource.setMimeType(mimeType);

  // 设置播放策略，设置缓冲区数据量为20s
  let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
  // 为avPlayer设置媒体来源和播放策略
  this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**情况五：通过应用沙箱中的m3u8文件播放在线流媒体资源**

当应用需要通过解析应用沙箱中的的m3u8文件，播放在线流媒体资源时，可以通过[fs.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)获取文件句柄，将其拼接成fdUrl，并通过[setMimeType](../../reference/apis-media-kit/js-apis-media.md#setmimetype12)设置MIME类型为APPLICATION_M3U8。
```ts
  let filePath = "/data/storage/el1/bundle/${m3u8FileName}";
  // 通过fs.openSync获取文件句柄
  let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  let fd : string = file.fd.toString();
  // 用文件句柄构造本地m3u8的URL
  let fdUrl : string = "fd://" + fd + "?offset=" + "0" + "&size=" + "0";

  // 按需设置HTTP请求头
  let headers : Record<string,string> = {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value"};
  // 通过本地m3u8的URL和HTTP请求头构造mediaSource媒体来源
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl, headers);

  // 设置媒体MIME类型为APPLICATION_M3U8
  let mimeType : media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
  mediaSource.setMimeType(mimeType);

  // 设置播放策略，设置缓冲区数据量为20s
  let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
  // 为avPlayer设置媒体来源和播放策略
  this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

## 本地raw文件播放场景下设置URL
**情况一：应用沙箱文件播放**
```ts
  import { common } from '@kit.AbilityKit';
  private context: Context | undefined;
  constructor(context: Context) {
    this.context = context; // this.getUIContext().getHostContext();
  }
  // 创建avPlayer实例对象。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  let fdPath = 'fd://';
  // 通过UIAbilityContext获取沙箱地址filesDir，以Stage模型为例。
  let pathDir = this.context.filesDir;
  let path = '/data/storage/el1/bundle/01.mp3';
  // 打开相应的资源文件地址获取fd，并为url赋值触发initialized状态机上报。
  let file = await fs.open(path);
  fdPath = fdPath + '' + file.fd;
  avPlayer.url = fdPath;
```

**情况二：本地文件播放**

> **说明：**
> 当使用AVPlayer播放本地资源时，AVPlayer会独占此fd。

```ts
  // 通过UIAbilityContext的resourceManager成员的getRawFd接口获取媒体资源播放地址
    // 返回类型为{fd,offset,length},fd为HAP包fd地址，offset为媒体资源偏移量，length为播放长度
    let fileDescriptor = await this.context.resourceManager.getRawFd(this.fileName);
    let avFileDescriptor: media.AVFileDescriptor =
      { fd: fileDescriptor.fd, offset: fileDescriptor.offset, length: fileDescriptor.length };
    // 为fdSrc赋值触发initialized状态机上报
    this.avPlayer.fdSrc = avFileDescriptor;
```

## 运行示例步骤：
1. 新建工程，下载示例工程，将示例工程的以下资源复制到对应目录:
```
AVPlayerArkTSURL
entry/src/main/ets/
└── pages
    └── Index.ets (播放界面)
entry/src/main/resources/
├── base
│   ├── element
│   │   ├── color.json
│   │   ├── float.json
│   │   └── string.json
│   └── media
│       ├── ic_video_play.svg  (播放键图片资源)
│       └── ic_video_pause.svg (暂停键图片资源)
└── rawfile
    └── test_01.mp3 （音频资源）
```
2. 在/entry/src/main/module.json5中，增加获取网络的permissions（或用示例工程的module.json5直接替换）:
```ts
"requestPermissions": [
  {
    "name": "ohos.permission.INTERNET"
  },
  {
    "name": "ohos.permission.GET_WIFI_INFO"
  }
]
```
3. 通过注释、解注释/entry/src/main/ets/pages/Index.ets中的上文示例的各种情况，编译并运行。