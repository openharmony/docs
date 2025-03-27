# Using AVPlayer to Set Playback URLs (ArkTS)
This topic describes how to use the AVPlayer to set URLs in different playback scenarios.

This guide focuses only on the methods for setting playback URLs. For other scenarios and comprehensive sample code, see [Video Playback](video-playback.md).

This guide describes the following scenarios:
- [Setting URLs for Streaming Media Playback](#setting-urls-for-streaming-media-playback)
- [Setting URLs for Local Raw File Playback](#setting-urls-for-local-raw-file-playback)

## Setting URLs for Streaming Media Playback
**Case 1: playing HTTP/HTTPS media assets**
```ts
  // Create an AVPlayer instance.
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // Set the URL of the media asset to play.
  avPlayer.url = 'https://xxx.xxx.xxx.mp4';
```

**Case 2: playing HLS media assets (VOD/live streaming)**
```ts
  // Create an AVPlayer instance.
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // Set the URL of the media asset to play.
  avPlayer.url = 'https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
```

**Case 3: setting the HTTP request header information for playback**

If the server needs to verify the HTTP request header, you can set the HTTP request header information through [createMediaSourceWithUrl](../../reference/apis-media-kit/js-apis-media.md#mediacreatemediasourcewithurl12).
```ts
  // Create an AVPlayer instance.
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // Create a mediaSource instance, set the media source, and customize an HTTP request. If necessary, set fields such as User-Agent, Cookie, and Referer in key-value pairs.
  let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("https://xxx.xxx.xxx.xxx:xx/xx/index.m3u8",  {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value", "Referer" : "Referer-Value"});
  // Set the playback strategy and set the data volume in the buffer to 20s.
  let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
  // Set the media source and playback strategy for the AVPlayer.
  avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**Case 4: playing an online streaming media asset by parsing an M3U8 file in the local raw file folder**

If an application needs to play an online streaming media asset by parsing an M3U8 file in the local raw file folder, the application can obtain the file descriptor through [resourceManager.getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9), combine the file descriptor into fdUrl, and set the MIME type to **APPLICATION_M3U8** through [setMimeType](../../reference/apis-media-kit/js-apis-media.md#setmimetype12).
```ts
  import { resourceManager } from '@kit.LocalizationKit';
  // Create an AVPlayer instance.
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // Obtain the context instance.
  let context = getContext(this) as common.UIAbilityContext;
  let mgr = context.resourceManager;
  // Set the local M3U8 file name.
  let m3u8FileName : string = "xxx.m3u8";
  // Obtain the file descriptor based on the local M3U8 file name.
  let fileDescriptor = await mgr.getRawFd(m3u8FileName);

  // Use the file descriptor to construct the URL of the local M3U8 file.
  let fd : string = fileDescriptor.fd.toString();
  let offset : string = fileDescriptor.offset.toString();
  let length : string = fileDescriptor.length.toString();
  let fdUrl : string = "fd://" + fd + "?offset=" + offset + "&size=" + length;

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
  avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

**Case 5: playing an online streaming media asset by parsing an M3U8 file in the application sandbox**

If an application needs to play an online streaming media asset by parsing an M3U8 file in the application sandbox, the application can obtain the file handle through [fs.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync), combine the file handle into fdUrl, and set the MIME type to **APPLICATION_M3U8** through [setMimeType](../../reference/apis-media-kit/js-apis-media.md#setmimetype12).
```ts
  import { fileIo as fs } from '@kit.CoreFileKit';
  // Create an AVPlayer instance.
  let avPlayer: media.AVPlayer = await media.createAVPlayer();

  // Obtain the context instance.
  let context = getContext(this) as common.UIAbilityContext;
  let mgr = context.resourceManager;
  // Set the local M3U8 file name.
  let m3u8FileName : string = "xxx.m3u8";
  // Set the sandbox path of the local M3U8 file.
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
  avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

## Setting URLs for Local Raw File Playback
**Case 1: application sandbox file playback**
```ts
  // Create an AVPlayer instance.
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  let fdPath = 'fd://';
  // Obtain the sandbox address filesDir through UIAbilityContext. The stage model is used as an example.
  let context = getContext(this) as common.UIAbilityContext;
  let pathDir = context.filesDir;
  let path = '/data/storage/el1/bundle/01.mp3';
  // Open the corresponding file address to obtain the file descriptor and assign a value to the URL to trigger the reporting of the initialized state.
  let file = await fs.open(path);
  fdPath = fdPath + '' + file.fd;
  avPlayer.url = fdPath;
```

**Case 2: local file playback**
```ts
  // Create an AVPlayer instance.
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  // Call getRawFd of the resourceManager member of UIAbilityContext to obtain the media asset URL.
  // The return type is {fd,offset,length}, where fd indicates the file descriptor address of the HAP file, offset indicates the media asset offset, and length indicates the duration of the media asset to play.
  let context = getContext(this) as common.UIAbilityContext;
  let fileDescriptor = await context.resourceManager.getRawFd('01.mp3');
  let avFileDescriptor: media.AVFileDescriptor =
    { fd: fileDescriptor.fd, offset: fileDescriptor.offset, length: fileDescriptor.length };
  // Assign a value to fdSrc to trigger the reporting of the initialized state.
  avPlayer.fdSrc = avFileDescriptor;
```
