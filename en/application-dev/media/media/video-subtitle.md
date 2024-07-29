# Adding External Subtitles to Videos

Currently, you can add external subtitles to a video only before it starts playing.

During application development, you can call **on('subtitleUpdate')** of an AVPlayer instance to listen for subtitle updates.

## How to Develop

Read [AVPlayer](../../reference/apis-media-kit/js-apis-media.md#avplayer9) for the API reference.

1. Set an external subtitle resource in the AVPlayer instance used for video playback.

   ```ts
   let context = getContext(this) as common.UIAbilityContext
   let fileDescriptor = await context.resourceManager.getRawFd('xxx.srt')

   avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length)

   // Alternatively, use addSubtitleUrl.
   let fd:string = fileDescriptor.fd.toString()
   let offset:string = fileDescriptor.offset.toString()
   let length:string = fileDescriptor.length.toString()
   let fdUrl:string = 'fd://' + fd + '?offset=' + offset + '&size=' + length
   avPlayer.addSubtitleUrl(fdUrl)
   ```

2. Register a subtitle callback function in the AVPlayer instance used for video playback.

   ```ts
   avPlayer.on('subtitleUpdate', (info: media.SubtitleInfo) => {
     if (!!info) {
       let text = (!info.text) ? '' : info.text
       let startTime = (!info.startTime) ? 0 : info.startTime
       let duration = (!info.duration) ? 0 : info.duration
       console.info('subtitleUpdate info: text=' + text + ' startTime=' + startTime +' duration=' + duration)
     } else {
       console.info('subtitleUpdate info is null')
     }
   })
   ```

3. (Optional) Unregister the subtitle callback function in the AVPlayer instance used for video playback when subtitles are not required.

   ```ts
   avPlayer.off('subtitleUpdate')
   ```


## Sample Code

```ts
import { media } from '@kit.MediaKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class AVPlayerSubtitleDemo {
  // Set AVPlayer callback functions.
  setAVPlayerCallback(avPlayer: media.AVPlayer) {
    // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
    avPlayer.on('error', (err: BusinessError) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`)
      avPlayer.reset(); // Call reset() to reset the AVPlayer, which enters the idle state.
    })
    // Register a subtitle update callback function.
    avPlayer.on('subtitleUpdate', (info: media.SubtitleInfo) => {
      if (!!info) {
        let text = (!info.text) ? '' : info.text
        let startTime = (!info.startTime) ? 0 : info.startTime
        let duration = (!info.duration) ? 0 : info.duration
        console.info('subtitleUpdate info: text=' + text + ' startTime=' + startTime +' duration=' + duration)
      } else {
        console.info('subtitleUpdate info is null')
      }
    })
  }

  // The following demo shows how to use resourceManager to obtain the media file packed in the HAP file and set based on the url attribute.
  async avPlayerSubtitleUrlDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer()
    // Set video information.
    // Create a callback function.
    this.setAVPlayerCallback(avPlayer)

    let context = getContext(this) as common.UIAbilityContext
    let fileDescriptor = await context.resourceManager.getRawFd('xxx.srt')

    let fd:string = fileDescriptor.fd.toString()
    let offset:string = fileDescriptor.offset.toString()
    let length:string = fileDescriptor.length.toString()
    let fdUrl:string = "fd://" + fd + "?offset=" + offset + "&size=" + length

    avPlayer.addSubtitleUrl(fdUrl)
  }

  // The following demo shows how to use resourceManager to obtain the media file packed in the HAP file and set based on the FromFd attribute.
  async avPlayerSubtitleFromFdDemo() {
    // Create an AVPlayer instance.
    let avPlayer: media.AVPlayer = await media.createAVPlayer()
    // Set video information.
    // Create a callback function.
    this.setAVPlayerCallback(avPlayer)

    let context = getContext(this) as common.UIAbilityContext
    let fileDescriptor = await context.resourceManager.getRawFd('xxx.srt')

    avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length)
  }

  // Unregister the subtitle update callback function.
  async avPlayerSubtitleOffDemo() {
    avPlayer.off('subtitleUpdate')
  }

}
```
