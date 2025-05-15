# Using AVPlayer to Add External Subtitles to Videos (ArkTS)

Currently, you can add external subtitles to a video only before it starts playing.

During application development, you can call **on('subtitleUpdate')** of an AVPlayer instance to listen for subtitle updates.

## How to Develop

Read [AVPlayer](../../reference/apis-media-kit/js-apis-media.md#avplayer9) for the API reference.

1. Set an external subtitle resource in the AVPlayer instance used for video playback.

   ```ts
   private context: Context | undefined;
   constructor(context: Context) {
     this.context = context; // this.getUIContext().getHostContext();
   }
   let fileDescriptor = await this.context.resourceManager.getRawFd('xxx.srt');

   avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length);

   // Alternatively, use addSubtitleFromUrl.
   let fdUrl:string = "http://xxx.xxx.xxx.xxx:xx/xx/index.srt" ;
   avPlayer.addSubtitleFromUrl(fdUrl);
   ```

2. Register a subtitle callback function in the AVPlayer instance used for video playback.

   ```ts
   avPlayer.on('subtitleUpdate', (info: media.SubtitleInfo) => {
     if (!!info) {
       let text = (!info.text) ? '' : info.text;
       let startTime = (!info.startTime) ? 0 : info.startTime;
       let duration = (!info.duration) ? 0 : info.duration;
       console.info('subtitleUpdate info: text=' + text + ' startTime=' + startTime +' duration=' + duration);
     } else {
       console.info('subtitleUpdate info is null');
     }
   });
   ```

3. (Optional) Unregister the subtitle callback function in the AVPlayer instance used for video playback when subtitles are not required.

   ```ts
   avPlayer.off('subtitleUpdate');
   ```


## Sample Code

```ts
import { media } from '@kit.MediaKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class AVPlayerSubtitleDemo {
  private avPlayer: media.AVPlayer | undefined = undefined;
  private context: Context | undefined;
  constructor(context: Context) {
    this.context = context; // this.getUIContext().getHostContext();
  }
  // Set AVPlayer callback functions.
  setAVPlayerCallback(avPlayer: media.AVPlayer) {
    // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
    avPlayer.on('error', (err: BusinessError) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
      avPlayer.reset(); // Call reset() to reset the AVPlayer, which enters the idle state.
    });
    // Register a subtitle update callback function.
    avPlayer.on('subtitleUpdate', (info: media.SubtitleInfo) => {
      if (info) {
        let text = (!info.text) ? '' : info.text;
        let startTime = (!info.startTime) ? 0 : info.startTime;
        let duration = (!info.duration) ? 0 : info.duration;
        console.info('subtitleUpdate info: text=' + text + ' startTime=' + startTime +' duration=' + duration);
      } else {
        console.info('subtitleUpdate info is null');
      }
    });
  }

  // The following demo shows how to use resourceManager to obtain the media file packed in the HAP file and set based on the url attribute.
  async avPlayerSubtitleUrlDemo() {
    // Create an AVPlayer instance.
    this.avPlayer = await media.createAVPlayer();
    // Set video information.
    // Create a callback function.
    this.setAVPlayerCallback(this.avPlayer);

    let fdUrl:string = "http://xxx.xxx.xxx.xxx:xx/xx/index.srt";

    this.avPlayer.addSubtitleFromUrl(fdUrl);
  }

  // The following demo shows how to use resourceManager to obtain the media file packed in the HAP file and set based on the FromFd attribute.
  async avPlayerSubtitleFromFdDemo() {
    // Create an AVPlayer instance.
    this.avPlayer = await media.createAVPlayer();
    // Set video information.
    // Create a callback function.
    this.setAVPlayerCallback(this.avPlayer);

    let fileDescriptor = await this.context.resourceManager.getRawFd('xxx.srt');

    this.avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length);
  }

  // Unregister the subtitle update callback function.
  async avPlayerSubtitleOffDemo() {
    if(this.avPlayer) {
      this.avPlayer.off('subtitleUpdate');
    }
  }

}
```
