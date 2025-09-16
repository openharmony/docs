# 使用AVPlayer设置播放URL(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xushubo; @chennotfound-->
<!--Designer: @dongyu_dy-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->
本开发指导将介绍如何使用AVPlayer开发播放功能，在不同的场景下如何设置URL。

当前指导仅介绍播放URL设置方法，其他场景及完整示例代码，请参考[视频播放](video-playback.md)。

当前开发指导将提供以下设置播放URL的方法：
- [流媒体播放场景下设置URL](#流媒体播放场景下设置url)
- [本地Raw文件播放场景下设置URL](#本地raw文件播放场景下设置url)

## 流媒体播放场景下设置URL
**情况一：播放HTTP/HTTPS媒体资源**
```ts
 import { media } from '@kit.MediaKit';
 // 类成员定义avPlayer。
 private avPlayer: media.AVPlayer | null = null;

 // 在业务函数中（示例工程函数名为avSetupURL）：
 // 创建avPlayer实例对象。
 this.avPlayer = await media.createAVPlayer();

 // 设置对应的播放url。
 let url = 'https://xxx.xxx.xxx.mp4';
 if (this.avPlayer == null) {
    return;
 }
 this.avPlayer.url = url;
```

**情况二：HLS媒体资源播放(点播/直播)**
```ts
 import { media } from '@kit.MediaKit';
 // 类成员定义avPlayer。
 private avPlayer: media.AVPlayer | null = null;

 // 在业务函数中（示例工程函数名为avSetupURL）：
 // 创建avPlayer实例对象。
 this.avPlayer = await media.createAVPlayer();

 // 设置对应的播放url。
 let url = 'https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
 if (this.avPlayer == null) {
    return;
 }
 this.avPlayer.url = url;
```

**情况三：设置HTTP请求头信息播放**

当服务器需要校验HTTP请求头信息时，可通过[createMediaSourceWithUrl](../../reference/apis-media-kit/arkts-apis-media-f.md#mediacreatemediasourcewithurl12)设置HTTP请求头信息。
```ts
 import { media } from '@kit.MediaKit';
 // 类成员定义avPlayer。
 private avPlayer: media.AVPlayer | null = null;

 // 在业务函数中（示例工程函数名为avSetupURL）：
 // 创建avPlayer实例对象。
 this.avPlayer = await media.createAVPlayer();

 // 设置对应的播放url。
 let url = 'https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
 // 创建mediaSource实例对象，设置媒体来源，定制HTTP请求，如需要，可以键值对的形式设置User-Agent、Cookie、Referer等字段。
 let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(url,
   {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value", "Referer" : "Referer-Value"});
 // 设置播放策略，设置缓冲区数据量为3s。
 let playbackStrategy : media.PlaybackStrategy =
   {preferredWidth: 1, preferredHeight: 2, preferredBufferDuration: 3, preferredHdr: false};
 // 为avPlayer设置媒体来源和播放策略。
 this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**情况四：通过本地Raw文件中的m3u8文件播放在线流媒体资源**

当应用需要通过解析本地Raw文件中的m3u8文件，播放在线流媒体资源时，可以通过[resourceManager.getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)获取文件描述符，将其拼接成fdUrl，并通过[setMimeType](../../reference/apis-media-kit/arkts-apis-media-MediaSource.md#setmimetype12)设置MIME类型为APPLICATION_M3U8。
```ts
 import { media } from '@kit.MediaKit';
 import { common } from '@kit.AbilityKit';
 // 类成员定义avPlayer和context。
 private avPlayer: media.AVPlayer | null = null;
 private context: common.UIAbilityContext | undefined = undefined;
 // 在业务函数中（示例工程函数名为avSetupURL）：
 // 创建avPlayer实例对象。
 this.avPlayer = await media.createAVPlayer();
 this.context = this.getUIContext().getHostContext() as common.UIAbilityContext;
 // 通过本地m3u8文件名，获取文件描述符。
 let fileDescriptor = await this.context.resourceManager.getRawFd('xxx.m3u8');
 // 用文件描述符构造本地m3u8的URL。
 let fdUrl : string = "fd://" + fileDescriptor.fd +
   "?offset=" + fileDescriptor.offset + "&size=" + fileDescriptor.length;
 // 按需设置HTTP请求头。
 let headers : Record<string,string> = {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value"};
 // 通过本地m3u8的URL和HTTP请求头构造mediaSource媒体来源。
 let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl, headers);

 // 设置媒体MIME类型为APPLICATION_M3U8。
 let mimeType : media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
 mediaSource?.setMimeType(mimeType);

 // 设置播放策略，设置缓冲区数据量为20s。
 let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
 // 为avPlayer设置媒体来源和播放策略。
 this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**情况五：通过应用沙箱中的m3u8文件播放在线流媒体资源**

当应用需要通过解析应用沙箱中的m3u8文件，播放在线流媒体资源时，可以通过[fs.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)获取文件句柄，将其拼接成fdUrl，并通过[setMimeType](../../reference/apis-media-kit/arkts-apis-media-MediaSource.md#setmimetype12)设置MIME类型为APPLICATION_M3U8。
```ts
 import { media } from '@kit.MediaKit';
 import { fileIo as fs } from '@kit.CoreFileKit';
 import { common } from '@kit.AbilityKit';
 // 类成员定义avPlayer和context。
 private avPlayer: media.AVPlayer | null = null;
 private context: common.UIAbilityContext | undefined = undefined;
 private m3u8FileName: string = '';

 // 在业务函数中（示例工程函数名为avSetupURL）：
 // 创建avPlayer实例对象。
 this.avPlayer = await media.createAVPlayer();
 this.context = this.getUIContext().getHostContext() as common.UIAbilityContext;
 // 通过UIAbilityContext获取沙箱地址filesDir，以Stage模型为例。
 let m3u8FileName = '';
 let filePath = `${this.context.filesDir}/${m3u8FileName}`; 
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
 mediaSource?.setMimeType(mimeType);

 // 设置播放策略，设置缓冲区数据量为20s。
 let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
 // 为avPlayer设置媒体来源和播放策略。
 this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

## 本地raw文件播放场景下设置URL
**情况一：应用沙箱文件播放**
```ts
 import { media } from '@kit.MediaKit';
 import { fileIo as fs } from '@kit.CoreFileKit';
 import { common } from '@kit.AbilityKit';
 // 类成员定义avPlayer，context和fileName。
 private avPlayer: media.AVPlayer | null = null;
 private context: common.UIAbilityContext | undefined = undefined;
 private fileName: string = '';

 // 在业务函数中（示例工程函数名为avSetupURL）：
 // 创建avPlayer实例对象。
 this.avPlayer = await media.createAVPlayer();
 this.context = this.getUIContext().getHostContext() as common.UIAbilityContext;
 let fdPath = 'fd://';
 let fileName = 'test.mp4'; // test.mp4为应用文件目录下的预置资源，需要开发者根据实际情况进行替换。
 // 通过UIAbilityContext获取沙箱地址filesDir，以Stage模型为例。
 let path = `${this.context?.filesDir}/${this.fileName}`;
 // 打开相应的资源文件地址获取fd，并为url赋值触发initialized状态机上报。
 let file = await fs.open(path);
 fdPath = fdPath + '' + file.fd;
 this.avPlayer.url = fdPath;
```

**情况二：本地文件播放**

> **说明：**
> 当使用AVPlayer播放本地资源时，AVPlayer会独占此fd。

```ts
 import { media } from '@kit.MediaKit';
 import { common } from '@kit.AbilityKit';
 // 类成员定义avPlayer，context和fileName。
 private avPlayer: media.AVPlayer | null = null;
 private fileName: string = '';
 private context: common.UIAbilityContext | undefined = undefined;
 // 在业务函数中（示例工程函数名为avSetupURL）：
 // 创建avPlayer实例对象。
 this.avPlayer = await media.createAVPlayer();
 this.context = this.getUIContext().getHostContext() as common.UIAbilityContext;
 // 通过UIAbilityContext的resourceManager成员的getRawFd接口获取媒体资源播放地址。
 // 返回类型为{fd,offset,length},fd为HAP包fd地址，offset为媒体资源偏移量，length为播放长度。
 let fileName = 'test.mp4'; // test.mp4为应用文件目录下的预置资源，需要开发者根据实际情况进行替换。
 let fileDescriptor = await this.context?.resourceManager.getRawFd(this.fileName);
 let avFileDescriptor: media.AVFileDescriptor =
  { fd: fileDescriptor.fd, offset: fileDescriptor.offset, length: fileDescriptor.length };
 // 为fdSrc赋值触发initialized状态机上报。
 this.avPlayer.fdSrc = avFileDescriptor;
```

## 运行完整示例
1. 新建工程，下载[示例工程](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSURL)（也可直接运行），并将示例工程的以下资源复制到对应目录。
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
        ├── test.m3u8    (m3u8资源)
        └── test_01.mp3 （音频资源）
    ```
2. 在/entry/src/main/module.json5中，申请使用网络的权限（或直接替换为示例工程的module.json5）。
    ```json
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

4. 在安装应用后，可将示例工程的/entry/src/main/resources/rawfile/test.m3u8通过以下命令加入应用沙箱，从而运行应用沙箱相关示例:（```<FILESDIR>```为物理路径，以示例工程为例，可通过console.info打印"this.context.filesDir"得到应用沙箱路径，再根据[应用沙箱指南](../../file-management/app-sandbox-directory.md)的```应用沙箱路径和真实物理路径的对应关系表```找到物理路径）。
    ```
    hdc file send "[目录]\test.m3u8" <FILESDIR>
    hdc file send "[目录]\test_01.mp3" <FILESDIR>
    ```
