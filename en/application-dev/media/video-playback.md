# Video Playback

OpenHarmony provides two solutions for video playback development:

- [AVPlayer](using-avplayer-for-playback.md) class: provides ArkTS and JS APIs to implement audio and video playback. It also supports parsing streaming media and local assets, decapsulating media assets, decoding video, and rendering video. It is applicable to end-to-end playback of media assets and can be used to play video files in MP4 and MKV formats.

- <Video\> component: encapsulates basic video playback capabilities. It can be used to play video files after the data source and basic information are set. However, its scalability is poor. This component is provided by ArkUI. For details about how to use this component for video playback development, see [Video Component](../ui/arkts-common-components-video-player.md).

In this topic, you will learn how to use the AVPlayer to develop a video playback service that plays a complete video file. If you want the application to continue playing the video in the background or when the screen is off, you must use the [AVSession](avsession-overview.md) and [continuous task](../task-management/continuous-task.md) to prevent the playback from being forcibly interrupted by the system.

## Development Guidelines

The full playback process includes creating an **AVPlayer** instance, setting the media asset to play and the window to display the video, setting playback parameters (volume, speed, and scale type), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the instance. During application development, you can use the **state** attribute of the AVPlayer to obtain the AVPlayer state or call **on('stateChange')** to listen for state changes. If the application performs an operation when the AudioPlayer is not in the given state, the system may throw an exception or generate other undefined behavior.

**Figure 1** Playback state transition 

![Playback state change](figures/video-playback-status-change.png)

For details about the state, see [AVPlayerState](../reference/apis/js-apis-media.md#avplayerstate9). When the AVPlayer is in the **prepared**, **playing**, **paused**, or **completed** state, the playback engine is working and a large amount of RAM is occupied. If your application does not need to use the AVPlayer, call **reset()** or **release()** to release the instance.

### How to Develop

Read [AVPlayer](../reference/apis/js-apis-media.md#avplayer9) for the API reference.

1. Call **createAVPlayer()** to create an **AVPlayer** instance. The AVPlayer is the **idle** state.

2. Set the events to listen for, which will be used in the full-process scenario. The table below lists the supported events.
   | Event Type| Description|
   | -------- | -------- |
   | stateChange | Mandatory; used to listen for changes of the **state** attribute of the AVPlayer.|
   | error | Mandatory; used to listen for AVPlayer errors.|
   | durationUpdate | Used to listen for progress bar updates to refresh the media asset duration.|
   | timeUpdate | Used to listen for the current position of the progress bar to refresh the current time.|
   | seekDone | Used to listen for the completion status of the **seek()** request.<br>This event is reported when the AVPlayer seeks to the playback position specified in **seek()**.|
   | speedDone | Used to listen for the completion status of the **setSpeed()** request.<br>This event is reported when the AVPlayer plays video at the speed specified in **setSpeed()**.|
   | volumeChange | Used to listen for the completion status of the **setVolume()** request.<br>This event is reported when the AVPlayer plays video at the volume specified in **setVolume()**.|
   | bitrateDone | Used to listen for the completion status of the **setBitrate()** request, which is used for HTTP Live Streaming (HLS) streams.<br>This event is reported when the AVPlayer plays video at the bit rate specified in **setBitrate()**.|
   | availableBitrates | Used to listen for available bit rates of HLS resources. The available bit rates are provided for **setBitrate()**.|
   | bufferingUpdate | Used to listen for network playback buffer information.|
   | startRenderFrame | Used to listen for the rendering time of the first frame during video playback.|
   | videoSizeChange | Used to listen for the width and height of video playback and adjust the window size and ratio.|
   | audioInterrupt | Used to listen for audio interruption. This event is used together with the **audioInterruptMode** attribute.<br>This event is reported when the current audio playback is interrupted by another (for example, when a call is coming), so the application can process the event in time.|

3. Set the media asset URL. The AVPlayer enters the **initialized** state.
   > **NOTE**
   >
   > The URL in the code snippet below is for reference only. You need to check the media asset validity and set the URL based on service requirements.
   > 
   > - If local files are used for playback, ensure that the files are available and the application sandbox path is used for access. For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox, see [File Management](../file-management/app-sandbox-directory.md).
   > 
   > - If a network playback path is used, you must request the ohos.permission.INTERNET [permission](../security/accesstoken-guidelines.md).
   > 
   > - You can also use **ResourceManager.getRawFd** to obtain the file descriptor of a file packed in the HAP file. For details, see [ResourceManager API Reference](../reference/apis/js-apis-resource-manager.md#getrawfd9).
   > 
   > - The [playback formats and protocols](avplayer-avrecorder-overview.md#supported-formats-and-protocols) in use must be those supported by the system.

4. Obtain and set the surface ID of the window to display the video.
   The application obtains the surface ID from the XComponent. For details about the process, see [XComponent](../reference/arkui-ts/ts-basic-components-xcomponent.md).

5. Call **prepare()** to switch the AVPlayer to the **prepared** state. In this state, you can obtain the duration of the media asset to play and set the scale type and volume.

6. Call **play()**, **pause()**, **seek()**, and **stop()** to perform video playback control as required.

7. (Optional) Call **reset()** to reset the AVPlayer. The AVPlayer enters the **idle** state again and you can change the media asset URL.

8. Call **release()** to switch the AVPlayer to the **released** state. Now your application exits the playback.


### Sample Code


```ts
import media from '@ohos.multimedia.media';
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

export class AVPlayerDemo {
  private avPlayer;
  private count: number = 0;
  private surfaceID: string; // The surfaceID parameter specifies the window used to display the video. Its value is obtained through the XComponent.

  // Set AVPlayer callback functions.
  setAVPlayerCallback() {
    // Callback function for the seek operation.
    this.avPlayer.on('seekDone', (seekDoneTime) => {
      console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
    })
    // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
    this.avPlayer.on('error', (err) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
      this.avPlayer.reset(); // Call reset() to reset the AVPlayer, which enters the idle state.
    })
    // Callback function for state changes.
    this.avPlayer.on('stateChange', async (state, reason) => {
      switch (state) {
        case 'idle': // This state is reported upon a successful callback of reset().
          console.info('AVPlayer state idle called.');
          this.avPlayer.release(); // Call release() to release the instance.
          break;
        case 'initialized': // This state is reported when the AVPlayer sets the playback source.
          console.info('AVPlayerstate initialized called.');
          this.avPlayer.surfaceId = this.surfaceID // Set the window to display the video. This setting is not required when a pure audio asset is to be played.
          this.avPlayer.prepare().then(() => {
            console.info('AVPlayer prepare succeeded.');
          }, (err) => {
            console.error(`Invoke prepare failed, code is ${err.code}, message is ${err.message}`);
          });
          break;
        case 'prepared': // This state is reported upon a successful callback of prepare().
          console.info('AVPlayer state prepared called.');
          this.avPlayer.play(); // Call play() to start playback.
          break;
        case 'playing': // This state is reported upon a successful callback of play().
          console.info('AVPlayer state playing called.');
          if (this.count !== 0) {
            console.info('AVPlayer start to seek.');
            this.avPlayer.seek (this.avPlayer.duration); // Call seek() to seek to the end of the video clip.
          } else {
            this.avPlayer.pause(); // Call pause() to pause the playback.
          }
          this.count++;
          break;
        case 'paused': // This state is reported upon a successful callback of pause().
          console.info('AVPlayer state paused called.');
          this.avPlayer.play(); // Call play() again to start playback.
          break;
        case 'completed': // This state is reported upon the completion of the playback.
          console.info('AVPlayer state completed called.');
          this.avPlayer.stop(); // Call stop() to stop the playback.
          break;
        case 'stopped': // This state is reported upon a successful callback of stop().
          console.info('AVPlayer state stopped called.');
          this.avPlayer.reset(); // Call reset() to reset the AVPlayer state.
          break;
        case 'released':
          console.info('AVPlayer state released called.');
          break;
        default:
          console.info('AVPlayer state unknown called.');
          break;
      }
    })
  }

  // The following demo shows how to use the file system to open the sandbox address, obtain the media file address, and play the media file using the URL attribute.
  async avPlayerUrlDemo() {
    // Create an AVPlayer instance.
    this.avPlayer = await media.createAVPlayer();
    // Set a callback function for state changes.
    this.setAVPlayerCallback();
    let fdPath = 'fd://';
    let context = getContext(this) as common.UIAbilityContext;
    // Obtain the sandbox address filesDir through UIAbilityContext. The stage model is used as an example.
    let pathDir = context.filesDir;
    let path = pathDir  + '/H264_AAC.mp4'; 
    // Open the corresponding file address to obtain the file descriptor and assign a value to the URL to trigger the reporting of the initialized state.
    let file = await fs.open(path);
    fdPath = fdPath + '' + file.fd;
    this.avPlayer.url = fdPath;
  }

  // The following demo shows how to use resourceManager to obtain the media file packed in the HAP file and play the media file by using the fdSrc attribute.
  async avPlayerFdSrcDemo() {
    // Create an AVPlayer instance.
    this.avPlayer = await media.createAVPlayer();
    // Set a callback function for state changes.
    this.setAVPlayerCallback();
    // Call getRawFd of the resourceManager member of UIAbilityContext to obtain the media asset URL.
    // The return type is {fd,offset,length}, where fd indicates the file descriptor address of the HAP file, offset indicates the media asset offset, and length indicates the duration of the media asset to play.
    let context = getContext(this) as common.UIAbilityContext;
    let fileDescriptor = await context.resourceManager.getRawFd('H264_AAC.mp4');
    // Assign a value to fdSrc to trigger the reporting of the initialized state.
    this.avPlayer.fdSrc = fileDescriptor;
  }
}
```
