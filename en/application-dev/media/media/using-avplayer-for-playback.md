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

## Sample Code

Refer to the sample code below to play a complete piece of music. In this example, 3 seconds after the playback starts, the playback is paused for 3 seconds and then resumed.

```ts
import { media } from '@kit.MediaKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { audio } from '@kit.AudioKit';

export class AVPlayerDemo {
  private count: number = 0;
  private isSeek: boolean = true; // Specify whether the seek operation is supported.
  private fileSize: number = -1;
  private fd: number = 0;
  private context: Context | undefined;
  constructor(context: Context) {
    this.context = context; // this.getUIContext().getHostContext();
  }
  // Set AVPlayer callback functions.
  setAVPlayerCallback(avPlayer: media.AVPlayer) {
    // Callback function for the seek operation.
    avPlayer.on('seekDone', (seekDoneTime: number) => {
      console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
    });
    // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
    avPlayer.on('error', (err: BusinessError) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
      avPlayer.reset(); // Call reset() to reset the AVPlayer, which enters the idle state.
    });
    // Callback for state changes.
    avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
      switch (state) {
        case 'idle': // This state is reported upon a successful callback of reset().
          console.info('AVPlayer state idle called.');
          avPlayer.release(); // Call release() to release the instance.
          break;
        case 'initialized': // This state is reported when the AVPlayer sets the playback source.
          console.info('AVPlayer state initialized called.');
          avPlayer.audioRendererInfo = {
            usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
            rendererFlags: 0 // AudioRenderer flag.
          };
          avPlayer.prepare();
          break;
        case 'prepared': // This state is reported upon a successful callback of prepare().
          console.info('AVPlayer state prepared called.');
          avPlayer.play(); // Call play() to start playback.
          break;
        case 'playing': // This state is reported upon a successful callback of play().
          console.info('AVPlayer state playing called.');
          if (this.count !== 0) {
            if (this.isSeek) {
              console.info('AVPlayer start to seek.');
              avPlayer.seek(avPlayer.duration); // Call seek() to seek to the end of the audio clip.
            } else {
              // When the seek operation is not supported, the playback continues until it reaches the end.
              console.info('AVPlayer wait to play end.');
            }
          } else {
            setTimeout(() => {
              console.info('AVPlayer playing wait to pause');
              avPlayer.pause(); // Call the pause API to pause the playback 3 seconds later.
            }, 3000);
          }
          this.count++;
          break;
        case 'paused': // This state is reported upon a successful callback of pause().
          console.info('AVPlayer state paused called.');
          setTimeout(() => {
              console.info('AVPlayer paused wait to play again');
              avPlayer.play(); // After the playback is paused for 3 seconds, call the play API again to start playback.
            }, 3000);
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
    });
  }

  // The following demo shows how to use the file system to open the sandbox address, obtain the media file address, and play the media file using the URL attribute.
  async avPlayerUrlDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    let fdPath = 'fd://';
    // Obtain the sandbox address filesDir through UIAbilityContext. The stage model is used as an example.
    if (this.context != undefined) {
      let pathDir = this.context.filesDir;
      let path = pathDir + '/01.mp3';
      // Open the corresponding file address to obtain the file descriptor and assign a value to the URL to trigger the reporting of the initialized state.
      let file = await fs.open(path);
      fdPath = fdPath + '' + file.fd;
      this.isSeek = true; // The seek operation is supported.
      avPlayer.url = fdPath;
    }
  }

  // The following demo shows how to use resourceManager to obtain the media file packed in the HAP file and play the media file by using the fdSrc attribute.
  async avPlayerFdSrcDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    // Call getRawFd of the resourceManager member of UIAbilityContext to obtain the media asset URL.
    // The return type is {fd,offset,length}, where fd indicates the file descriptor address of the HAP file, offset indicates the media asset offset, and length indicates the duration of the media asset to play.
    if (this.context != undefined) {
      let fileDescriptor = await this.context.resourceManager.getRawFd('01.mp3');
      let avFileDescriptor: media.AVFileDescriptor =
        { fd: fileDescriptor.fd, offset: fileDescriptor.offset, length: fileDescriptor.length };
      this.isSeek = true; // The seek operation is supported.
      // Assign a value to fdSrc to trigger the reporting of the initialized state.
      avPlayer.fdSrc = avFileDescriptor;
    }
  }

  // The following demo shows how to use the file system to open the sandbox address, obtain the media file address, and play the media file with the seek operation using the dataSrc attribute.
  async avPlayerDataSrcSeekDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    // dataSrc indicates the playback source address. When the seek operation is supported, fileSize indicates the size of the file to be played. The following describes how to assign a value to fileSize.
    let src: media.AVDataSrcDescriptor = {
      fileSize: -1,
      callback: (buf: ArrayBuffer, length: number, pos: number | undefined) => {
        let num = 0;
        if (buf == undefined || length == undefined || pos == undefined) {
          return -1;
        }
        num = fs.readSync(this.fd, buf, { offset: pos, length: length });
        if (num > 0 && (this.fileSize >= pos)) {
          return num;
        }
        return -1;
      }
    };
    // Obtain the sandbox address filesDir through UIAbilityContext. The stage model is used as an example.
    if (this.context != undefined) {
      let pathDir = this.context.filesDir;
      let path = pathDir  + '/01.mp3';
      await fs.open(path).then((file: fs.File) => {
        this.fd = file.fd;
      });
    }
    // Obtain the size of the file to be played.
    this.fileSize = fs.statSync(path).size;
    src.fileSize = this.fileSize;
    this.isSeek = true; // The seek operation is supported.
    avPlayer.dataSrc = src;
  }

  // The following demo shows how to use the file system to open the sandbox address, obtain the media file address, and play the media file without the seek operation using the dataSrc attribute.
  async avPlayerDataSrcNoSeekDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    let src: media.AVDataSrcDescriptor = {
      fileSize: -1,
      callback: (buf: ArrayBuffer, length: number) => {
        let num = 0;
        if (buf == undefined || length == undefined) {
          return -1;
        }
        num = fs.readSync(this.fd, buf);
        if (num > 0) {
          return num;
        }
        return -1;
      }
    };
    // Obtain the sandbox address filesDir through UIAbilityContext. The stage model is used as an example.
    if (this.context != undefined) {
        let pathDir = this.context.filesDir;
        let path = pathDir  + '/01.mp3';
        await fs.open(path).then((file: fs.File) => {
          this.fd = file.fd;
        });
        this.isSeek = false; // The seek operation is not supported.
        avPlayer.dataSrc = src;
      }
  }

  // The following demo shows how to play live streams by setting the network address through the URL.
  async avPlayerLiveDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // Set a callback for state changes.
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = false; // The seek operation is not supported.
    avPlayer.url = 'http://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  }
}
```

<!--RP1-->
<!--RP1End-->
