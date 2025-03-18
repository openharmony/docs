# Using AVPlayer to Play Streaming Media (ArkTS)

In this topic, you will learn how to use the [AVPlayer](media-kit-intro.md#avplayer) to develop a service for streaming media playback, enabling the complete playback of a streaming video from beginning to end.

This topic describes only how to implement streaming media playback. For details about other scenarios such as local playback, see [Video Playback](using-avplayer-for-playback.md).

## Formats Supported by Streaming Media

| Streaming Media Protocol| Typical Link Format| On-Demand Streaming| Live Streaming|Content Protection|
| -------- | -------- | -------- | -------- | -------- |
| HLS | `https://xxxx/index.m3u8` | Supported| Supported| Supported (see [DRM Kit](../drm/drm-overview.md))|
| DASH | `https://xxxx.mpd` | Supported| - | Supported (see [DRM Kit](../drm/drm-overview.md))|
| HTTP/HTTPS | `https://xxxx.mp4` | Supported| - | - |
| HTTP-FLV | `https://xxxx.flv` | Supported| Supported| - |

## How to Develop

The full streaming media playback process includes creating an AVPlayer instance, setting the media asset to play and the window to display the video, setting playback parameters (volume, speed, and scale type), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the instance. During application development, you can use the **state** attribute of the AVPlayer to obtain the AVPlayer state or call **on('stateChange')** to listen for state changes. If the application performs an operation when the AVPlayer is not in the given state, the system may throw an exception or generate other undefined behavior. For details about the state, see [AVPlayerState](../../reference/apis-media-kit/js-apis-media.md#avplayerstate9). The development procedure is as follows:

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

3. Set the media asset. Specifically, [use the AVPlayer to set the playback URL](playback-url-setting-method.md). The AVPlayer transitions to the initialized state.
   > **NOTE**
   >
   > The URL in the code snippet below is for reference only. You need to check the media asset validity and set the URL based on service requirements.
   > 
   > - If a network playback path is used, you must [declare the ohos.permission.INTERNET permission](../../security/AccessToken/declare-permissions.md).
   > 
   > - The playback format and protocol must be supported.
   > 

4. Obtain and set the surface ID of the window to display the video.

   The application obtains the surface ID from the **XComponent**. For details about the process, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

5. Call **prepare()** to switch the AVPlayer to the **prepared** state. In this state, you can obtain the duration of the media asset to play and set the scale type and volume.

6. Call **play()**, **pause()**, **seek()**, and **stop()** to perform video playback control as required.

7. (Optional) Call **reset()** to reset the AVPlayer. The AVPlayer enters the **idle** state again and you can change the media asset URL.

8. Call **release()** to switch the AVPlayer to the **released** state. Now your application exits the playback.

## Special Notes

The standard procedure for streaming media playback is outlined in the development steps provided above. However, there are differences when working with various streaming media formats during actual development. This section will describe these differences in detail, including video playback startup strategies and switching between audio and video tracks.

### Buffering Status for Streaming Media

If the download speed falls below the bit rate of the media source, playback stuttering may occur. In this case, the AVPlayer detects a lack of data in the buffer and will accumulate some data before resuming playback to prevent continuous stuttering. The buffering event reporting sequence for a single instance of stuttering is as follows: BUFFERING_START -> BUFFERING_PERCENT 0 -> ... -> BUFFERING_PERCENT 100 -> BUFFERING_END. The CACHED_DURATION event is continuously reported throughout the stuttering and playback phases, until the download reaches the end of the resource. For details, see [BufferingInfoType](../../reference/apis-media-kit/js-apis-media.md#bufferinginfotype8).

Sample code for listening for the bufferingUpdate event:

```ts
avPlayer.on('bufferingUpdate', (infoType : media.BufferingInfoType, value : number) => {
  console.info(`AVPlayer bufferingUpdate, infoType is ${infoType}, value is ${value}.`);
})
```

### HLS Bit Rate Switching

HLS streams currently support playback at multiple bit rates. By default, the AVPlayer selects the most suitable bit rate based on the network download speed.

1. Use [on('availableBitrates')](../../reference/apis-media-kit/js-apis-media.md#onavailablebitrates9) to listen for the available bit rates for an HLS stream. If the bit rate list has a length of 0, setting a specific bit rate is not supported.

    ```ts
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Listen for the available bit rates of the current HLS stream.
    avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
      console.info('availableBitrates called, and availableBitrates length is: ' + bitrates.length);
    })
    ```

2. Use [setBitrate](../../reference/apis-media-kit/js-apis-media.md#setbitrate9) to set the playback bit rate. If the bit rate is not among the available bit rates, the AVPlayer selects the minimum and closest bit rate from the available ones. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can listen for the [bitrateDone](../../reference/apis-media-kit/js-apis-media.md#onbitratedone9) event to check whether the setting takes effect.

    ```ts
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Check whether the bit rate setting takes effect.
    avPlayer.on('bitrateDone', (bitrate: number) => {
      console.info('bitrateDone called, and bitrate value is: ' + bitrate);
    })
    // Set the playback bit rate.
    let bitrate: number = 96000;
    avPlayer.setBitrate(bitrate);
    ```

### DASH Video Playback Startup Strategy

To maintain a smooth playback experience in environments with poor network connectivity, the AVPlayer initially selects the lowest video resolution for playback and then adjusts automatically based on the network status. You can customize the playback startup strategy, including setting parameters such as the video width, height, and color format, for DASH videos based on service requirements.

As an illustration of adjusting the startup resolution, the sample code below demonstrates setting the video to start at a width of 1920 px and a height of 1080 px. In this case, the AVPlayer selects a video stream with a resolution of 1920 x 1080 from the MPD resources for playback.

```ts
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://test.cn/dash/aaa.mpd",  {"User-Agent" : "User-Agent-Value"});
let playbackStrategy : media.PlaybackStrategy = {preferredWidth: 1920, preferredHeight: 1080};
avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

### DASH Audio and Video Track Switching

DASH streaming media generally include multiple audio, video, and subtitle tracks, each with distinct parameters like resolution, bit rate, sampling rate, and encoding format. By default, the AVPlayer automatically select video tracks with different bit rates based on the network status. You can manually select an audio or video track for playback based on service requirements. In this case, the adaptive bit rate switching feature becomes invalid.

1. Set the [trackChange](../../reference/apis-media-kit/js-apis-media.md#ontrackchange12) event.

    ```ts
    avPlayer.on('trackChange', (index: number, isSelect: boolean) => {
      console.info(`trackChange info, index: ${index}, isSelect: ${isSelect}`);
    })
    ```

2. Call [getTrackDescription](../../reference/apis-media-kit/js-apis-media.md#gettrackdescription9) to obtain the list of all audio and video tracks. You can determine the index of the target track based on an actual requirement and information about each field in [MediaDescription](../../reference/apis-media-kit/js-apis-media.md#mediadescription8).

    ```ts
    // The following uses the 1080p video track index as an example.
    public videoTrackIndex: number;
    avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          let propertyIndex: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
          let propertyType: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_TYPE];
          let propertyWidth: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_WIDTH];
          let propertyHeight: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_HEIGHT];
          if (propertyType == media.MediaType.MEDIA_TYPE_VID && propertyWidth == 1920 && propertyHeight == 1080) {
            videoTrackIndex = parseInt(propertyIndex.toString()); // Obtain the 1080p video track index.
          }
        }
      } else {
        console.error(`getTrackDescription fail, error:${error}`);
      }
    });
    ```                   

3. During audio and video playback, call [selectTrack](../../reference/apis-media-kit/js-apis-media.md#selecttrack12) to select audio and video tracks, or call [deselectTrack](../../reference/apis-media-kit/js-apis-media.md#deselecttrack12) to deselect them.

    ```ts
    // Select a video track.
    avPlayer.selectTrack(videoTrackIndex);
    // Deselect the video track.
    // avPlayer.deselectTrack(videoTrackIndex);
    ```

## Exception Description

If the network is disconnected when the AVPlayer is playing streaming media, the AVPlayer module handles the fault based on the returned error code, response time of the server request failure, and number of requests. If the error code type does not require a retry, the module reports the corresponding error code to the application. If the error code type requires a retry, the module initiates a maximum of 10 retries within 30 seconds. If the number of retries exceeds 10 or the total retry duration exceeds 30 seconds, the module reports the corresponding error code to the application. If the retry is successful, the module continues the playback.

## Sample Code

Refer to the following example to play a complete streaming video.

```ts
import { media } from '@kit.MediaKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class AVPlayerDemo {
  private count: number = 0;
  private surfaceID: string = ''; // The surfaceID parameter specifies the window used to display the video. Its value is obtained through XComponent.
  private isSeek: boolean = true; // Specify whether the seek operation is supported.
  public audioTrackList: number[] = [];
  public videoTrackList: number[] = [];

  constructor(surfaceID: string) {
    this.surfaceID = surfaceID;
  }

  // Set AVPlayer callback functions.
  setAVPlayerCallback(avPlayer: media.AVPlayer) {
    // startRenderFrame: callback function invoked when the first frame starts rendering.
    avPlayer.on('startRenderFrame', () => {
      console.info(`AVPlayer start render frame`);
    });
    // Callback function for the seek operation.
    avPlayer.on('seekDone', (seekDoneTime: number) => {
      console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
    })
    // avPlayer.on('trackChange', (index: number, isSelect: boolean) => {
    //   console.info(`AVPlayer track changed, track index: ${index}, isSelect: ${isSelect}`);
    // })
    // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
    avPlayer.on('error', (err: BusinessError) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
      avPlayer.reset(); // Call reset() to reset the AVPlayer, which enters the idle state.
    })
    // Callback for state changes.
    avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
      switch (state) {
        case 'idle': // This state is reported upon a successful callback of reset().
          console.info('AVPlayer state idle called.');
          avPlayer.release(); // Call release() to release the instance.
          break;
        case 'initialized': // This state is reported when the AVPlayer sets the playback source.
          console.info('AVPlayer state initialized called.');
          avPlayer.surfaceId = this.surfaceID; // Set the window to display the video. This setting is not required when a pure audio asset is to be played.
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
    // Listen for the streaming media buffering status, buffering percentage, and estimated playback duration of buffered data.
    avPlayer.on('bufferingUpdate', (infoType : media.BufferingInfoType, value : number) => {
      console.info(`AVPlayer bufferingUpdate, infoType is ${infoType}, value is ${value}.`);
    })
  }

  // The following demo shows how to play an HLS on-demand video by setting the network address through url.
  async avPlayerVodDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = true; // The seek operation is supported in VOD scenarios.
    avPlayer.url = 'http://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  }

  // The following demo shows how to play an HLS live streaming video by setting the network address through url.
  async avPlayerLiveDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = false; // The seek operation is not supported in live streaming scenarios.
    avPlayer.url = 'http://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  }

  // The following demo shows how to play a DASH streaming video by setting the network address through url.
  async avPlayerDashDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    // Set the playback strategy.
    // let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://test.cn/dash/aaa.mpd",  {"User-Agent" : "User-Agent-Value"});
    // let playbackStrategy : media.PlaybackStrategy = {preferredWidth: 1, preferredHeight: 2, preferredBufferDuration: 3, preferredHdr: false};
    // avPlayer.setMediaSource(mediaSource, playbackStrategy);
    this.isSeek = true; // The seek operation is supported.
    avPlayer.url = 'http://test.cn/dash/aaa.mpd'; // Use the actual address of the DASH streaming video.

    // Set the audio or video track by calling selectTrack, and cancel the audio or video track selected last time by calling deselectTrack. After the cancellation, the default audio or video track is restored.
    avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          let propertyIndex: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
          let propertyType: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_TYPE];
          if (propertyType == 0) {
            this.audioTrackList.push(parseInt(propertyIndex.toString())); // Obtain the audio track list.
          } else if (propertyType == 1) {
            this.videoTrackList.push(parseInt(propertyIndex.toString())); // Obtain the video track list.
          }
        }
      } else {
        console.error(`getTrackDescription fail, error:${error}`);
      }
    });
    // Select a video track.
    // avPlayer.selectTrack(this.videoTrackList[0]);
    // Deselect the video track.
    // avPlayer.deselectTrack(this.videoTrackList[0]);
  }

  // The following demo uses setMediaSource to set custom header fields and preferred media playback parameters to implement initial playback parameter settings. It uses HTTPS on-demand streaming media as an example.
  async preDownloadDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = true; // The seek operation is supported in VOD scenarios.
    // Create a mediaSource instance, set the media source, and customize an HTTP request. If necessary, set fields such as User-Agent, Cookie, and Referer in key-value pairs.
    let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("https://xxx.xxx",  {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value", "Referer" : "Referer-Value"});
    // Set the playback strategy and set the data volume in the buffer to 20s.
    let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
    // Set the media source and playback strategy for the AVPlayer.
    avPlayer.setMediaSource(mediaSource, playbackStrategy);
  }
}
```
