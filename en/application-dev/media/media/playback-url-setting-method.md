# Using AVPlayer to Set Playback URLs (ArkTS)
This topic describes how to use the AVPlayer to set URLs in different playback scenarios.

This guide focuses only on the methods for setting playback URLs. For other scenarios and comprehensive sample code, see [Video Playback](video-playback.md).

This guide describes the following scenarios:
- [Setting URLs for Streaming Media Playback](#setting-urls-for-streaming-media-playback)
- [Setting URLs for Local Raw File Playback](#setting-urls-for-local-raw-file-playback)

## Setting URLs for Streaming Media Playback
**Case 1: playing HTTP/HTTPS media assets**
```ts
  // Set the URL of the media asset to play.
  let url = 'https://xxx.xxx.xxx.mp4';
  this.avPlayer.url = url;
```

**Case 2: playing HLS media assets (VOD/live streaming)**
```ts
  // Set the URL of the media asset to play.
  let url = 'https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  this.avPlayer.url = url;
```

**Case 3: setting the HTTP request header information for playback**

If the server needs to verify the HTTP request header, you can set the HTTP request header information through [createMediaSourceWithUrl](../../reference/apis-media-kit/js-apis-media.md#mediacreatemediasourcewithurl12).
```ts
  // Set the URL of the media asset to play.
  let url = 'https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  // Create a mediaSource instance, set the media source, and customize an HTTP request. If necessary, set fields such as User-Agent, Cookie, and Referer in key-value pairs.
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(url,
    {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value", "Referer" : "Referer-Value"});
  // Set the playback strategy and set the data volume in the buffer to 20s.
  let playbackStrategy : media.PlaybackStrategy =
    {preferredWidth: 1, preferredHeight: 2, preferredBufferDuration: 3, preferredHdr: false};
  // Set the media source and playback strategy for the AVPlayer.
  this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**Case 4: playing an online streaming media asset by parsing an M3U8 file in the local raw file folder**

If an application needs to play an online streaming media asset by parsing an M3U8 file in the local raw file folder, the application can obtain the file descriptor through [resourceManager.getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9), combine the file descriptor into fdUrl, and set the MIME type to **APPLICATION_M3U8** through [setMimeType](../../reference/apis-media-kit/js-apis-media.md#setmimetype12).
```ts
  // Obtain the file descriptor based on the local M3U8 file name.
  let fileDescriptor = await this.context.resourceManager.getRawFd('xxx.m3u8');
  // Use the file descriptor to construct the URL of the local M3U8 file.
  let fdUrl : string = "fd://" + fileDescriptor.fd +
    "?offset=" + fileDescriptor.offset + "&size=" + fileDescriptor.length;
  // Set the HTTP request header as required.
  let headers : Record<string,string> = {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value"};
  // Construct the media source based on the local M3U8 file URL and HTTP request header.
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl, headers);

  // Set the MIME type to APPLICATION_M3U8.
  let mimeType : media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
  mediaSource.setMimeType(mimeType);

  // Set the playback strategy and set the data volume in the buffer to 20s.
  let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
  // Set the media source and playback strategy for the AVPlayer.
  this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**Case 5: playing an online streaming media asset by parsing an M3U8 file in the application sandbox**

If an application needs to play an online streaming media asset by parsing an M3U8 file in the application sandbox, the application can obtain the file handle through [fs.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync), combine the file handle into fdUrl, and set the MIME type to **APPLICATION_M3U8** through [setMimeType](../../reference/apis-media-kit/js-apis-media.md#setmimetype12).
```ts
  let filePath = "/data/storage/el1/bundle/${m3u8FileName}";
  // Obtain the file handle through fs.openSync.
  let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  let fd : string = file.fd.toString();
  // Use the file handle to construct the URL of the local M3U8 file.
  let fdUrl : string = "fd://" + fd + "?offset=" + "0" + "&size=" + "0";

  // Set the HTTP request header as required.
  let headers : Record<string,string> = {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value"};
  // Construct the media source based on the local M3U8 file URL and HTTP request header.
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl, headers);

  // Set the MIME type to APPLICATION_M3U8.
  let mimeType : media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
  mediaSource.setMimeType(mimeType);

  // Set the playback strategy and set the data volume in the buffer to 20s.
  let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
  // Set the media source and playback strategy for the AVPlayer.
  this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

## Setting URLs for Local Raw File Playback
**Case 1: application sandbox file playback**
```ts
  import { common } from '@kit.AbilityKit';
  private context: Context | undefined;
  constructor(context: Context) {
    this.context = context; // this.getUIContext().getHostContext();
  }
  // Create an AVPlayer instance.
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  let fdPath = 'fd://';
  // Obtain the sandbox address filesDir through UIAbilityContext. The stage model is used as an example.
  let pathDir = this.context.filesDir;
  let path = '/data/storage/el1/bundle/01.mp3';
  // Open the corresponding file address to obtain the file descriptor and assign a value to the URL to trigger the reporting of the initialized state.
  let file = await fs.open(path);
  fdPath = fdPath + '' + file.fd;
  avPlayer.url = fdPath;
```

**Case 2: local file playback**

> **NOTE**
>
> When the AVPlayer is used to play local resources, it exclusively occupies the file descriptor.

```ts
  // Call getRawFd of the resourceManager member of UIAbilityContext to obtain the media asset URL.
  // The return type is {fd,offset,length}, where fd indicates the file descriptor address of the HAP file, offset indicates the media asset offset, and length indicates the duration of the media asset to play.
  let fileDescriptor = await this.context.resourceManager.getRawFd(this.fileName);
  let avFileDescriptor: media.AVFileDescriptor =
    { fd: fileDescriptor.fd, offset: fileDescriptor.offset, length: fileDescriptor.length };
  // Assign a value to fdSrc to trigger the reporting of the initialized state.
  this.avPlayer.fdSrc = avFileDescriptor;
```

## Running the Sample Project
1. Create a project, download the [sample project](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSURL), and copy the following resources of the sample project to the corresponding directories.
    ```
    AVPlayerArkTSURL
    entry/src/main/ets/
    └── pages
        └── Index.ets (playback page)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │       ├── ic_video_play.svg (play button image resource)
    │       └── ic_video_pause.svg (pause button image resource)
    └── rawfile
        ├── test.m3u8 (m3u8 resource)
        └── test_01.mp3 (audio resource)
    ```
2. Request the network permission in the **/entry/src/main/module.json5** file. Alternatively, replace the **module.json5** file with that in the sample project.
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
3. Comment out or uncomment the above examples in the **entry/src/main/ets/pages/Index.ets** file, and compile and run the application.

4. After installing the application, you can run the following commands to add the **/entry/src/main/resources/rawfile/test.m3u8** file in the sample project to the [application sandbox](../../file-management/app-sandbox-directory.md), allowing you to run sandbox-related examples. (The \<PACKAGENAME> of the sample project is **com.samples.AVPlayerArkTSURL**.)
    ```
    hdc file send "[Directory]\test.m3u8" /data/app/el1/bundle/public/<PACKAGENAME>
    hdc file send "[Directory]\test_01.mp3" /data/app/el1/bundle/public/<PACKAGENAME>
    ```
