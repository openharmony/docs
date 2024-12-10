# Using AVPlayer to Play Streaming Media
## Introduction
In this topic, you will learn how to use the AVPlayer to develop a streaming media playback service that plays a streaming video from start to finish.

This topic describes only how to implement streaming media playback. For details about other scenarios such as local playback, see [Video Playback](using-avplayer-for-playback.md).

## Formats Supported by Streaming Media
### HTTP/HTTPS
| Streaming Media Protocol| Typical Link Format| On-Demand Streaming| Live Streaming| Subtitle| Content Protection| Metadata|
| -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| HLS | https://xxxx/index.m3u8 | Supported| Supported| srt/vtt | Supported| Supported|
| DASH | https://xxxx.mpd | Supported|  | srt/vtt/webvtt | Supported| Supported|
| HTTP/HTTPS | https://xxxx.mp4 | Supported|  | srt/vtt |  | Supported|
| HTTP-FLV | https://xxxx.flv | Supported| Supported| srt/vtt |  | Supported|

## Streaming Media Playback Process
The full streaming media playback process includes creating an AVPlayer instance, setting the media asset to play and the window to display the video, setting playback parameters (volume, speed, and scale type), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the instance. During application development, you can use the **state** attribute of the AVPlayer to obtain the AVPlayer state or call **on('stateChange')** to listen for state changes. If the application performs an operation when the AVPlayer is not in the given state, the system may throw an exception or generate other undefined behavior. For details about the state, see [AVPlayerState](../../reference/apis-media-kit/js-apis-media.md#avplayerstate9).

## How to Develop
1. Call **createAVPlayer()** to create an AVPlayer instance. The AVPlayer is the **idle** state.

2. Set the events to listen for, which will be used in the full-process scenario. The table below lists the supported events.
   | Event| Description|
   | -------- | -------- |
   | stateChange | Mandatory; used to listen for changes of the **state** attribute of the AVPlayer.|
   | error | Mandatory; used to listen for AVPlayer errors.|
   | durationUpdate | Used to listen for progress bar updates to refresh the media asset duration.|
   | timeUpdate | Used to listen for the current position of the progress bar to refresh the current time.|
   | seekDone | Used to listen for the completion status of the **seek()** request.<br>This event is reported when the AVPlayer seeks to the playback position specified in **seek()**.|
   | speedDone | Used to listen for the completion status of the **setSpeed()** request.<br>This event is reported when the AVPlayer plays videos at the speed specified in **setSpeed()**.|
   | volumeChange | Used to listen for the completion status of the **setVolume()** request.<br>This event is reported when the AVPlayer plays videos at the volume specified in **setVolume()**.|
   | bufferingUpdate | Used to listen for network playback buffer information. This event reports the buffer percentage and playback progress.|
   | audioInterrupt | Used to listen for audio interruption. This event is used together with the **audioInterruptMode** attribute.<br>This event is reported when the current audio playback is interrupted by another (for example, when a call is coming), so the application can process the event in time.|

3. Set the media asset URL. The AVPlayer enters the **initialized** state.
   > **NOTE**
   >
   > The URL in the code snippet below is for reference only. You need to check the media asset validity and set the URL based on service requirements.
   > 
   > - If a network playback path is used, you must [declare the ohos.permission.INTERNET permission](../../security/AccessToken/declare-permissions.md).
   > 
   > - The playback format and protocol must be supported.
   > 

4. Call **prepare()** to switch the AVPlayer to the **prepared** state. In this state, you can obtain the duration of the media asset to play and set the volume.

5. Call **play()**, **pause()**, **seek()**, and **stop()** to perform audio playback control as required.

6. (Optional) Call **reset()** to reset the AVPlayer. The AVPlayer enters the **idle** state again and you can change the media asset URL.

7. Call **release()** to switch the AVPlayer to the **released** state. Now your application exits the playback.

## Sample Code
Refer to the following example to play a complete streaming video.

```ts
import { media } from '@kit.MediaKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class AVPlayerDemo {
  private count: number = 0;
  private isSeek: boolean = true; // Specify whether the seek operation is supported.
  // Set AVPlayer callback functions.
  setAVPlayerCallback(avPlayer: media.AVPlayer) {
    // Callback function for the seek operation.
    avPlayer.on('seekDone', (seekDoneTime: number) => {
      console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
    })
    // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
    avPlayer.on('error', (err: BusinessError) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
      avPlayer.reset(); // Call reset() to reset the AVPlayer, which enters the idle state.
    })
    // Callback function for state changes.
    avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
      switch (state) {
        case 'idle': // This state is reported upon a successful callback of reset().
          console.info('AVPlayer state idle called.');
          avPlayer.release(); // Call release() to release the instance.
          break;
        case 'initialized': // This state is reported when the AVPlayer sets the playback source.
          console.info('AVPlayer state initialized called.');
          this.avPlayer.audioRendererInfo = {
            usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
            rendererFlags: 0
          }
          avPlayer.prepare();
          break;
        case 'prepared': // This state is reported upon a successful callback of prepare().
          console.info('AVPlayer state prepared called.');
          avPlayer.play(); // Call play() to start playback.
          break;
        case 'playing': // This state is reported upon a successful callback of play().
          console.info('AVPlayer state playing called.');
          break;
        case 'paused': // This state is reported upon a successful callback of pause().
          console.info('AVPlayer state paused called.');
          break;
        case 'completed': // This state is reported upon the completion of the playback.
          console.info('AVPlayer state completed called.');
          avPlayer.stop(); // Call stop() to stop the playback.
          break;
        case 'stopped': // This state is reported upon a successful callback of stop().
          console.info('AVPlayer state stopped called.');
          avPlayer.reset(); // Call reset() to reset the AVPlayer.
          break;
        case 'released':
          console.info('AVPlayer state released called.');
          break;
        default:
          console.info('AVPlayer state unknown called.');
          break;
      }
    })
    // Obtain the streaming media buffer status and progress.
    avPlayer.on('bufferingUpdate', (infoType : media.BufferingInfoType, value : number) => {
      console.info(`AVPlayer bufferingUpdate, infoType is ${infoType}, value is ${value}.`);
    })
  }

  // The following demo shows how to play an HLS on-demand video by setting the network address through url.
  async avPlayerVodDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Create a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = true; // The seek operation is supported in VOD scenarios.
    avPlayer.url = 'http://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  }

  // The following demo shows how to play an HLS live streaming video by setting the network address through url.
  async avPlayerLiveDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Create a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = false; // The seek operation is not supported in live streaming scenarios.
    avPlayer.url = 'http://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  }

  // The following demo uses setMediaSource to set custom header fields and preferred media playback parameters to implement initial playback parameter settings. It uses HTTPS on-demand streaming media as an example.
  async preDownloadDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Create a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = true; // The seek operation is supported in VOD scenarios.
    // Create a mediaSource instance, set the media source, and customize an HTTP request. If necessary, set fields such as User-Agent, Cookie, and Referer in key-value pairs.
    let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("https://xxx.xxx",  {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value", "Referer" : "Referer-Value"});
    // Set the playback strategy. Set the size of the media source size to 1920 x 1080 and the buffer size to 20 MB.
    let playbackStrategy : media.PlaybackStrategy = {preferredWidth: 1920, preferredHeight: 1080, preferredBufferDuration: 20, preferredHdr: false};
    // Set the media source and playback strategy for the AVPlayer.
    avPlayer.setMediaSource(mediaSource, playbackStrategy);
  }
}
```

## Exception Description
If the network is disconnected when the AVPlayer is playing streaming media, the AVPlayer module handles the fault based on the returned error code, response time of the server request failure, and number of requests. If the error code type does not require a retry, the module reports the corresponding error code to the application. If the error code type requires a retry, the module initiates a maximum of 10 retries within 30 seconds. If the number of retries exceeds 10 or the total retry duration exceeds 30 seconds, the module reports the corresponding error code to the application. If the retry is successful, the module continues the playback.