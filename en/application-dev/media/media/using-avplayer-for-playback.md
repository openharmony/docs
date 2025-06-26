# Using AVPlayer to Play Audio (ArkTS)

The [AVPlayer](media-kit-intro.md#avplayer) is used to play raw media assets in an end-to-end manner. In this topic, you will learn how to use the AVPlayer to play a complete piece of music. To play PCM audio data, call [AudioRenderer](../audio/using-audiorenderer-for-playback.md).

The full playback process includes creating an AVPlayer instance, setting the media asset to play, setting playback parameters (volume, speed, and focus mode), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the instance.


During application development, you can use the **state** attribute of the AVPlayer to obtain the AVPlayer state or call **on('stateChange')** to listen for state changes. If the application performs an operation when the AVPlayer is not in the given state, the system may throw an exception or generate other undefined behavior.


**Figure 1** Playback state transition

![Playback status change](figures/playback-status-change.png)

For details about the state, see [AVPlayerState](../../reference/apis-media-kit/js-apis-media.md#avplayerstate9). When the AVPlayer is in the **prepared**, **playing**, **paused**, or **completed** state, the playback engine is working and a large amount of RAM is occupied. If your application does not need to use the AVPlayer, call **reset()** or **release()** to release the instance.

## Developer's Tips

This topic describes only how to implement the playback of a media asset. In practice, background playback and playback conflicts may be involved. You can refer to the following description to handle the situation based on your service requirements.

- If you want the application to continue playing the media asset in the background or when the screen is off, use the [AVSession](../avsession/avsession-access-scene.md) and [continuous task](../../task-management/continuous-task.md) to prevent the playback from being forcibly interrupted by the system.
- If the media asset being played involves audio, the playback may be interrupted by other applications based on the system audio management policy. (For details, see [Processing Audio Interruption Events](../audio/audio-playback-concurrency.md).) It is recommended that the player application proactively listen for audio interruption events and handle the events accordingly to avoid the inconsistency between the application status and the expected effect.
- When a device is connected to multiple audio output devices, the application can listen for audio output device changes through [on('audioOutputDeviceChangeWithInfo')](../../reference/apis-media-kit/js-apis-media.md#onaudiooutputdevicechangewithinfo11) and perform the processing accordingly.
- To access online media resources, you must request the ohos.permission.INTERNET permission.

## How to Develop

Read [AVPlayer](../../reference/apis-media-kit/js-apis-media.md#avplayer9) for the API reference.

1. Call **createAVPlayer()** to create an AVPlayer instance. The AVPlayer is the **idle** state.

2. Set the events to listen for, which will be used in the full-process scenario. The table below lists the supported events.
   | Event Type| Description|
   | -------- | -------- |
   | stateChange | Mandatory; used to listen for changes of the **state** attribute of the AVPlayer.|
   | error | Mandatory; used to listen for AVPlayer errors.|
   | durationUpdate | Used to listen for progress bar updates to refresh the media asset duration.|
   | timeUpdate | Used to listen for the current position of the progress bar to refresh the current time.|
   | seekDone | Used to listen for the completion status of the **seek()** request.<br>This event is reported when the AVPlayer seeks to the playback position specified in **seek()**.|
   | speedDone | Used to listen for the completion status of the **setSpeed()** request.<br>This event is reported when the AVPlayer plays music at the speed specified in **setSpeed()**.|
   | volumeChange | Used to listen for the completion status of the **setVolume()** request.<br>This event is reported when the AVPlayer plays music at the volume specified in **setVolume()**.|
   | bufferingUpdate | Used to listen for network playback buffer information. This event reports the buffer percentage and playback progress.|
   | audioInterrupt | Used to listen for audio interruption. This event is used together with the **audioInterruptMode** attribute.<br>This event is reported when the current audio playback is interrupted by another (for example, when a call is coming), so the application can process the event in time.|

3. Set the media asset URL. The AVPlayer enters the **initialized** state.
   > **NOTE**
   >
   > The URL in the code snippet below is for reference only. You need to check the media asset validity and set the URL based on service requirements.
   > 
   > - If local files are used for playback, ensure that the files are available and the application sandbox path is used for access. For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
   > 
   > - If a network playback path is used, you must [declare the ohos.permission.INTERNET permission](../../security/AccessToken/declare-permissions.md).
   > 
   > - You can also use **ResourceManager.getRawFd** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9).
   > 
   > - The [playback formats and protocols](media-kit-intro.md#supported-formats-and-protocols) in use must be those supported by the system.
   > 
   > In addition, the audio renderer information (if required) must be set only when the AVPlayer is in the initialized state, that is, before **prepare()** is called for the first time. If the media source contains videos, the default value of **usage** is **STREAM_USAGE_MOVIE**. Otherwise, the default value of **usage** is **STREAM_USAGE_MUSIC**. The default value of **rendererFlags** is 0. If the default value of **usage** does not meet the requirements, configure [audio.AudioRendererInfo](../../reference/apis-audio-kit/js-apis-audio.md#audiorendererinfo8).

4. Call **prepare()** to switch the AVPlayer to the **prepared** state. In this state, you can obtain the duration of the media asset to play and set the volume.

5. Call **play()**, **pause()**, **seek()**, and **stop()** to perform audio playback control as required.

6. (Optional) Call **reset()** to reset the AVPlayer. The AVPlayer enters the **idle** state again and you can change the media asset URL.

7. Call **release()** to switch the AVPlayer to the **released** state. Now your application exits the playback.

## Running the Sample Project

Refer to the sample code below to play a complete piece of music. In this example, 3 seconds after the playback starts, the playback is paused for 3 seconds and then resumed.

1. Create a project, download the [sample project](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSAudio), and copy the following resources of the sample project to the corresponding directories.
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
        └── test_01.mp3 (audio resource)
    ```
2. Compile and run the project.

## Development Example

```ts
import display from '@ohos.display';
import emitter from '@ohos.events.emitter';
import { common } from '@kit.AbilityKit';
import media from '@ohos.multimedia.media';

...

@Entry
@Component
struct Index {
  private avPlayer: media.AVPlayer | null = null;
  private context: common.UIAbilityContext | undefined = undefined;
  @State fileName: string = 'test_01.mp3';
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

  async avSetupAudio() {
    // Call getRawFd of the resourceManager member of UIAbilityContext to obtain the media asset URL.
    // The return type is {fd,offset,length}, where fd indicates the file descriptor address of the HAP file, offset indicates the media asset offset, and length indicates the duration of the media asset to play.
    if (this.context == undefined) return;
    let fileDescriptor = await this.context.resourceManager.getRawFd(this.fileName);
    let avFileDescriptor: media.AVFileDescriptor =
      { fd: fileDescriptor.fd, offset: fileDescriptor.offset, length: fileDescriptor.length };

    if (this.avPlayer) {
      console.info(`${this.tag}: init avPlayer release2createNew`);
      this.avPlayer.release();
      await this.msleepAsync(1500);
    }
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

    // Assign a value to fdSrc to trigger the reporting of the initialized state.
    this.avPlayer.fdSrc = avFileDescriptor;
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
        console.info(`${this.tag}: avPause== ${JSON.stringify(e)}`);
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
        console.info(`${this.tag}: videoSeek== ${JSON.stringify(e)}`);
      }
    }
  }

  avSetSpeed(speed: number): void {
    if (this.avPlayer) {
      try {
        this.avPlayer.setSpeed(speed);
        console.info(`${this.tag}: avSetSpeed enum ${speed}`);
      } catch (e) {
        console.info(`${this.tag}: avSetSpeed == ${JSON.stringify(e)}`);
      }
    }
  }

  // Set AVPlayer callback functions.
  async setAVPlayerCallback(callback: (avPlayer: media.AVPlayer) => void, vType?: number): Promise<void> {
    // Callback function for the seek operation.
    if (this.avPlayer == null) {
      console.info(`${this.tag}: avPlayer has not init!`);
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
        console.info(`${this.tag}: avPlayer has not init on error`);
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
          if (this.count !== 0) {
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
          } else {
            setTimeout(() => {
              console.info('AVPlayer playing wait to pause');
              this.avPlayer?.pause(); // Call the pause API to pause the playback 3 seconds later.
            }, 3000);
          }
          this.count++;
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
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state error called.`);
          break
        case 'paused':
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state paused called.`);
          setTimeout(() => {
            console.info('AVPlayer paused wait to play again');
            this.avPlayer?.play(); // After the playback is paused for 3 seconds, call the play API again to start playback.
          }, 3000);
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
        console.error(`${this.tag}: videoRelease release filed,error message is = ${JSON.stringify(err.message)}`);
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
