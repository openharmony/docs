# Using AVPlayer to Play Streaming Media (ArkTS)

This topic describes how to use [AVPlayer](media-kit-intro.md#avplayer) for streaming live broadcasts and video-on-demand. The examples demonstrate how to play streaming videos in an end-to-end manner.

This guide focuses solely on streaming media playback. For details about other scenarios such as local audio and video playback, see [Using AVPlayer to Play Audio (ArkTS)](using-avplayer-for-playback.md).

## Formats Supported by Streaming Media

| Streaming Media Protocol| Typical Link Format| On-Demand Streaming| Live Streaming|Content Protection|
| -------- | -------- | -------- | -------- | -------- |
| HLS | `https://xxxx/index.m3u8` | Supported| Supported| Supported (see [DRM Kit](../drm/drm-overview.md))|
| DASH | `https://xxxx.mpd` | Supported| - | Supported (see [DRM Kit](../drm/drm-overview.md))|
| HTTP/HTTPS | `https://xxxx.mp4` | Supported| - | - |
| HTTP-FLV | `https://xxxx.flv` | Supported| Supported| - |

## How to Develop

The full streaming media playback process includes creating an AVPlayer instance, setting the media asset to play and the window to display the video, setting playback parameters (volume, speed, and scale type), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the instance. During application development, you can use the **state** attribute of the AVPlayer to obtain the AVPlayer state or call **on('stateChange')** to listen for state changes. Performing actions when the AVPlayer is in an incorrect state can lead to exceptions or undefined behavior. For details, see [AVPlayerState](../../reference/apis-media-kit/js-apis-media.md#avplayerstate9).  

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

The standard process for playing streaming media follows the development steps outlined above. However, different streaming media formats have their own peculiarities in practice. This section delves into these differences, covering aspects like video startup strategies and the switching between audio and video tracks.

### Buffering Status for Streaming Media

If the download speed falls below the bit rate of the media source, playback stuttering may occur. In this case, the AVPlayer detects a lack of data in the buffer and will accumulate some data before resuming playback to prevent continuous stuttering. The buffering event reporting sequence for a single instance of stuttering is as follows: BUFFERING_START -> BUFFERING_PERCENT 0 -> ... -> BUFFERING_PERCENT 100 -> BUFFERING_END. The CACHED_DURATION event is continuously reported throughout the stuttering and playback phases, until the download reaches the end of the resource. For details, see [BufferingInfoType](../../reference/apis-media-kit/js-apis-media.md#bufferinginfotype8).

Sample code for listening for the bufferingUpdate event:

```ts
this.avPlayer.on('bufferingUpdate', (infoType : media.BufferingInfoType, value : number) => {
  console.info(`AVPlayer bufferingUpdate, infoType is ${infoType}, value is ${value}.`);
})
```

### HLS Bit Rate Switching

HLS streams currently support playback at multiple bit rates. By default, the AVPlayer selects the most suitable bit rate based on the network download speed.

1. Use [on('availableBitrates')](../../reference/apis-media-kit/js-apis-media.md#onavailablebitrates9) to listen for the available bit rates for an HLS stream. If the bit rate list has a length of 0, setting a specific bit rate is not supported.

    ```ts
    // Create an AVPlayer instance.
    this.avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Listen for the available bit rates of the current HLS stream.
    this.avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
      console.info('availableBitrates called, and availableBitrates length is: ' + bitrates.length);
    })
    ```

2. Use [setBitrate](../../reference/apis-media-kit/js-apis-media.md#setbitrate9) to set the playback bit rate. If the bit rate is not among the available bit rates, the AVPlayer selects the minimum and closest bit rate from the available ones. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can listen for the [bitrateDone](../../reference/apis-media-kit/js-apis-media.md#onbitratedone9) event to check whether the setting takes effect.

    ```ts
    // Create an AVPlayer instance.
    this.avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Check whether the bit rate setting takes effect.
    this.avPlayer.on('bitrateDone', (bitrate: number) => {
      console.info('bitrateDone called, and bitrate value is: ' + bitrate);
    })
    // Set the playback bit rate.
    this.bitrate: number = 96000;
    avPlayer.setBitrate(bitrate);
    ```

### DASH Video Playback Startup Strategy

To maintain a smooth playback experience in environments with poor network connectivity, the AVPlayer initially selects the lowest video resolution for playback and then adjusts automatically based on the network status. You can customize the playback startup strategy, including setting parameters such as the video width, height, and color format, for DASH videos based on service requirements.

The sample code below demonstrates setting the video to start at a width of 1920 px and a height of 1080 px. The AVPlayer selects a video stream with a resolution of 1920 x 1080 from the MPD resources for playback.

```ts
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://test.cn/dash/aaa.mpd",  {"User-Agent" : "User-Agent-Value"});
let playbackStrategy : media.PlaybackStrategy = {preferredWidth: 1920, preferredHeight: 1080};
this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

### DASH Audio and Video Track Switching

DASH streaming media includes multiple audio, video, and subtitle tracks, each with different resolutions, bit rates, sampling rates, and encoding formats. By default, the AVPlayer automatically select video tracks with different bit rates based on the network status. You can manually select an audio or video track for playback based on service requirements. In this case, the adaptive bit rate switching feature becomes invalid.

1. Set the [trackChange](../../reference/apis-media-kit/js-apis-media.md#ontrackchange12) event.

    ```ts
    this.avPlayer.on('trackChange', (index: number, isSelect: boolean) => {
      console.info(`trackChange info, index: ${index}, isSelect: ${isSelect}`);
    })
    ```

2. Call [getTrackDescription](../../reference/apis-media-kit/js-apis-media.md#gettrackdescription9) to obtain the list of all audio and video tracks. You can determine the index of the target track based on an actual requirement and information about each field in [MediaDescription](../../reference/apis-media-kit/js-apis-media.md#mediadescription8).

    ```ts
    // The following uses the 1080p video track index as an example.
    this.avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          let propertyIndex: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
          let propertyType: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_TYPE];
          let propertyWidth: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_WIDTH];
          let propertyHeight: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_HEIGHT];
          if (propertyType == media.MediaType.MEDIA_TYPE_VID && propertyWidth == 1920 && propertyHeight == 1080) {
            this.videoTrackIndex = parseInt(propertyIndex.toString()); // Obtain the 1080p video track index.
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

If the network is disconnected when the AVPlayer is playing streaming media, the AVPlayer module handles the fault based on the returned error code, server response time, and number of requests. If the error code type does not require a retry, the module reports the corresponding error code to the application. If the error code type requires a retry, the module initiates a maximum of 10 retries within 30 seconds. If the number of retries exceeds 10 or the total retry duration exceeds 30 seconds, the module reports the corresponding error code to the application. If the retry is successful, the module continues the playback.

## Running the Sample Project

Refer to the following example to play a complete streaming video.

1. Create a project, download the [sample project](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSStreamingMedia), and copy the following resources of the sample project to the corresponding directories.
    ```
    AVPlayerArkTSAudio
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
        └── test1.mp4 (video resource)
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

## Development Example

```ts
@Entry
@Component
struct Index {
  private avPlayer: media.AVPlayer | null = null;
  private context: common.UIAbilityContext | undefined = undefined;
  public videoTrackIndex: number = 0;
  public bitrate: number = 0;
  ...

  getDurationTime(): number {
    return this.durationTime;
  }

  getCurrentTime(): number {
    return this.currentTime;
  }

  timeConvert(time: number): string {
    let min: number = Math.floor(time / TIME_ONE);
    let second: string = ((time % TIME_ONE) / TIME_TWO).toFixed(0);
    // return `${min}:${(+second < TIME_THREE ? '0' : '') + second}`;
    second = second.padStart(2, '0');
    return `${min}:${second}`;
  }

  async msleepAsync(ms: number): Promise<boolean> {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        resolve(true)
      }, ms)
    })
  }

  async avSetupStreaminMediaVideo() {
    if (this.context == undefined) return;
    // Create an AVPlayer instance.
    this.avPlayer = await media.createAVPlayer();

    // Set a callback function for state changes.
    await this.setAVPlayerCallback((avPlayer: media.AVPlayer) => {
      this.percent = avPlayer.width / avPlayer.height;
      this.setVideoWH();
      this.durationTime = this.getDurationTime();
      setInterval(() => { // Update the current time.
        if (!this.isSwiping) {
          this.currentTime = this.getCurrentTime();
        }
      }, SET_INTERVAL);
    });

    // Case 1: HTTP video playback.
    this.avPlayer.url = "http://media.iyuns.top:1000/http/720p_1m.mp4";

    // Case 2: HLS video playback.
    // this.avPlayer.url = "http://media.iyuns.top:1000/720-270-480.m3u8";

    // Case 3: DASH video playback.
    // this.avPlayer.url = "http://media.iyuns.top:1000/dash/720p/720-1/720-1.mpd";

    // Case 4: setMediaSource is used to set custom header fields and preferred media playback parameters to implement initial playback parameter settings, and HTTP on-demand streaming media is used as an example.
    /*
    let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://media.iyuns.top:1000/http/720p_1m.mp4", {"":""});
    // Set the playback strategy and set the data volume in the buffer to 20s.
    let playbackStrategy : media.PlaybackStrategy = {preferredBufferDuration: 20};
    // Set the media source and playback strategy for the AVPlayer.
    this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
    * */

    // Case 5: HLS bit rate switching.
    /*
    this.avPlayer.url = "https://upftimae.dailyworkout.cn/videos/course/c800f81a209b5ee7891f1128ed301db/4/master.m3u8";
    let bitrate: number = 0;
    // Listen for the available bit rates of the current HLS stream.
    this.avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
      console.info('availableBitrates called, and availableBitrates length is: ' + bitrates.length);
      this.bitrate = bitrates[0]; // Save the bit rate to be switched.
    })
    // Check whether the bit rate setting takes effect.
    this.avPlayer.on('bitrateDone', (bitrate: number) => {
      console.info('bitrateDone called, and bitrate value is: ' + bitrate);
    })
    * */

    // Case 6: DASH audio and video track switching.
    /*
    this.avPlayer.url = "http://poster-inland.hwcloudtest.cn/AiMaxEngine/ProductionEnvVideo/DASH_SDR_MultiAudio_MultiSubtitle_yinHeHuWeiDui3/DASH_SDR_MultiAudio_MultiSubtitle_yinHeHuWeiDui3.mpd";
    // 
    this.avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          let propertyIndex: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
          let propertyType: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_TYPE];
          let propertyWidth: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_WIDTH];
          let propertyHeight: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_HEIGHT];
          if (propertyType == media.MediaType.MEDIA_TYPE_VID && propertyWidth == 1920 && propertyHeight == 1080) {
            this.videoTrackIndex = parseInt(propertyIndex.toString()); // Obtain the 1080p video track index.
          }
        }
      } else {
        console.error(`getTrackDescription fail, error:${error}`);
      }
    });
    * */
  }

  // HLS bit rate switching.
  changeBitrate(bitrate: number) {
    if (this.avPlayer == null) {
      return;
    }
    // Set the playback bit rate.
    try {
      this.avPlayer.setBitrate(bitrate);
    } catch (error) {
      console.error(`${this.tag}: setBitrate failed, error message is = ${JSON.stringify(error.message)}`);
    }
  }

  // DASH audio and video track switching.
  changeTrack(track: number) {
    if (this.avPlayer == null) {
      return;
    }
    // Select a video track.
    try {
      this.avPlayer.selectTrack(track);
    } catch (error) {
      console.error(`${this.tag}: selectTrack failed, error message is = ${JSON.stringify(error.message)}`);
    }
    // Deselect the video track.
    /*
    try {
      this.avPlayer.deselectTrack(track);
    } catch (error) {
      console.error(`${this.tag}: deselectTrack failed, error message is = ${JSON.stringify(error.message)}`);
    }
    * */
  }

  avPlay(): void {
    if (this.avPlayer) {
      try {
        this.avPlayer.play();
      } catch (e) {
        console.error(`${this.tag}: avPlay = ${JSON.stringify(e)}`);
      }
    }
  }

  avPause(): void {
    if (this.avPlayer) {
      try {
        this.avPlayer.pause();
        console.info(`${this.tag}: avPause==`);
      } catch (e) {
        console.error(`${this.tag}: avPause== ${JSON.stringify(e)}`);
      }
    }
  }

  async avSeek(seekTime: number, mode: SliderChangeMode): Promise<void> {
    if (this.avPlayer) {
      try {
        console.info(`${this.tag}: videoSeek  seekTime== ${seekTime}`);
        this.avPlayer.seek(seekTime, 2);
        this.currentTime = seekTime;
      } catch (e) {
        console.error(`${this.tag}: videoSeek== ${JSON.stringify(e)}`);
      }
    }
  }

  avSetSpeed(speed: number): void {
    if (this.avPlayer) {
      try {
        this.avPlayer.setSpeed(speed);
        console.info(`${this.tag}: avSetSpeed enum ${speed}`);
      } catch (e) {
        console.error(`${this.tag}: avSetSpeed == ${JSON.stringify(e)}`);
      }
    }
  }

  // Set AVPlayer callback functions.
  async setAVPlayerCallback(callback: (avPlayer: media.AVPlayer) => void, vType?: number): Promise<void> {
    // Callback function for the seek operation.
    if (this.avPlayer == null) {
      console.error(`${this.tag}: avPlayer has not init!`);
      return;
    }
    this.avPlayer.on('seekDone', (seekDoneTime) => {
      console.info(`${this.tag}: setAVPlayerCallback AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
    });
    this.avPlayer.on('speedDone', (speed) => {
      console.info(`${this.tag}: setAVPlayerCallback AVPlayer speedDone, speed is ${speed}`);
    });
    // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
    this.avPlayer.on('error', (err) => {
      console.error(`${this.tag}: setAVPlayerCallback Invoke avPlayer failed ${JSON.stringify(err)}`);
      if (this.avPlayer == null) {
        console.error(`${this.tag}: avPlayer has not init on error`);
        return;
      }
      this.avPlayer.reset();
    });
    // Callback function for state changes.
    this.avPlayer.on('stateChange', async (state, reason) => {
      if (this.avPlayer == null) {
        console.info(`${this.tag}: avPlayer has not init on state change`);
        return;
      }
      switch (state) {
        case 'idle': // This state is reported upon a successful callback of reset().
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state idle called.`);
          break;
        case 'initialized': // This state is reported when the AVPlayer sets the playback source.
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state initialized called.`);
          if (this.surfaceId) {
            this.avPlayer.surfaceId = this.surfaceId; // Set the window to display the video. This setting is not required when a pure audio asset is to be played.
            console.info(`${this.tag}: setAVPlayerCallback this.avPlayer.surfaceId = ${this.avPlayer.surfaceId}`);
            this.avPlayer.prepare();
          }
          break;
        case 'prepared': // This state is reported upon a successful callback of prepare().
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state prepared called.`);
          this.avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
            console.info(`${this.tag}: bufferingUpdate called, infoType value: ${infoType}, value:${value}}`);
          })
          this.durationTime = this.avPlayer.duration;
          this.currentTime = this.avPlayer.currentTime;
          this.avPlayer.play(); // Call play() to start playback.
          console.info(`${this.tag}:
            setAVPlayerCallback speedSelect: ${this.speedSelect}, duration: ${this.durationTime}`);
          if (this.speedSelect != -1) {
            switch (this.speedSelect) {
              case SPEED_ZERO:
                this.avSetSpeed(media.PlaybackSpeed.SPEED_FORWARD_1_00_X);
                break;
              case SPEED_ONE:
                this.avSetSpeed(media.PlaybackSpeed.SPEED_FORWARD_1_25_X);
                break;
              case SPEED_TWO:
                this.avSetSpeed(media.PlaybackSpeed.SPEED_FORWARD_1_75_X);
                break;
              case SPEED_THREE:
                this.avSetSpeed(media.PlaybackSpeed.SPEED_FORWARD_2_00_X);
                break;
            }
          }
          callback(this.avPlayer);
          break;
        case 'playing': // This state is reported upon a successful callback of play().
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state playing called.`);
          if (this.intervalID != -1) {
            clearInterval(this.intervalID)
          }
          this.intervalID = setInterval(() => { // Update the current time.
            AppStorage.setOrCreate('durationTime', this.durationTime);
            AppStorage.setOrCreate('currentTime', this.currentTime);
          }, 100);
          let eventDataTrue: emitter.EventData = {
            data: {
              'flag': true
            }
          };
          let innerEventTrue: emitter.InnerEvent = {
            eventId: 2,
            priority: emitter.EventPriority.HIGH
          };
          emitter.emit(innerEventTrue, eventDataTrue);
          break;
        case 'completed': // This state is reported upon the completion of the playback.
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state completed called.`);
          let eventDataFalse: emitter.EventData = {
            data: {
              'flag': false
            }
          };
          let innerEvent: emitter.InnerEvent = {
            eventId: 1,
            priority: emitter.EventPriority.HIGH
          };
          emitter.emit(innerEvent, eventDataFalse);
          if (this.intervalID != -1) {
            clearInterval(this.intervalID)
          }
          this.avPlayer.off('bufferingUpdate')
          AppStorage.setOrCreate('currentTime', this.durationTime);
          break;
        case 'released':
          console.info(`${this.tag}: setAVPlayerCallback released called.`);
          break
        case 'stopped':
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state stopped called.`);
          break
        case 'error':
          console.error(`${this.tag}: setAVPlayerCallback AVPlayer state error called.`);
          break
        case 'paused':
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state paused called.`);
          break
        default:
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state unknown called.`);
          break;
      }
    });
    // Callback function for time updates.
    this.avPlayer.on('timeUpdate', (time: number) => {
      this.currentTime = time;
    });
  }

  aboutToAppear() {
    this.windowWidth = display.getDefaultDisplaySync().width;
    this.windowHeight = display.getDefaultDisplaySync().height;
    this.surfaceW = this.windowWidth * SURFACE_W;
    this.surfaceH = this.surfaceW / SURFACE_H;
    this.isPaused = true;
    this.context = getContext(this) as common.UIAbilityContext;
  }

  aboutToDisappear() {
    if (this.avPlayer == null) {
      console.info(`${this.tag}: avPlayer has not init aboutToDisappear`);
      return;
    }
    this.avPlayer.release((err) => {
      if (err == null) {
        console.info(`${this.tag}: videoRelease release success`);
      } else {
        console.error(`${this.tag}: videoRelease release failed, error message is = ${JSON.stringify(err.message)}`);
      }
    });
    emitter.off(innerEventFalse.eventId);
  }

  onPageHide() {
    this.avPause();
    this.isPaused = false;
  }

  onPageShow() {
    emitter.on(innerEventTrue, (res: emitter.EventData) => {
      if (res.data) {
        this.isPaused = res.data.flag;
        this.XComponentFlag = res.data.flag;
      }
    });
    emitter.on(innerEventFalse, (res: emitter.EventData) => {
      if (res.data) {
        this.isPaused = res.data.flag;
      }
    });
    emitter.on(innerEventWH, (res: emitter.EventData) => {
      if (res.data) {
        this.windowWidth = res.data.width;
        this.windowHeight = res.data.height;
        this.setVideoWH();
      }
    });
  }

  setVideoWH(): void {
    if (this.percent >= 1) { // Horizontal video.
      this.surfaceW = Math.round(this.windowWidth * PROPORTION);
      this.surfaceH = Math.round(this.surfaceW / this.percent);
    } else { // Vertical video.
      this.surfaceH = Math.round(this.windowHeight * PROPORTION);
      this.surfaceW = Math.round(this.surfaceH * this.percent);
    }
  }

  @Builder
  CoverXComponent() {...}

  build() {...}
}
```
