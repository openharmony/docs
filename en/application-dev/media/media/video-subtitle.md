# Using AVPlayer to Add External Subtitles to Videos (ArkTS)

Currently, you can add external subtitles to a video only before it starts playing.

During application development, you can call **on('subtitleUpdate')** of an AVPlayer instance to listen for subtitle updates.

## How to Develop

Read [AVPlayer](../../reference/apis-media-kit/js-apis-media.md#avplayer9) for the API reference.

1. Set an external subtitle resource in the AVPlayer instance used for video playback.

   ```ts
    // Set subtitles.
    let fileDescriptorSub = await this.context.resourceManager.getRawFd('xxx.srt');
    this.avPlayer.addSubtitleFromFd(fileDescriptorSub.fd, fileDescriptorSub.offset, fileDescriptorSub.length);
   ```

2. Register a subtitle callback function in the AVPlayer instance used for video playback.

   ```ts
    // Callback function for subtitle updates.
    this.avPlayer.on('subtitleUpdate', (info: media.SubtitleInfo) => {
      if (!!info) {
        let text = (!info.text) ? '' : info.text;
        let startTime = (!info.startTime) ? 0 : info.startTime;
        let duration = (!info.duration) ? 0 : info.duration;
        console.info(`${this.tag}: subtitleUpdate info: text=${text} startTime=${startTime} duration=${duration}`);
        this.subtitle = text;
      } else {
        console.info(`${this.tag}: subtitleUpdate info is null`);
      }
    });
   ```

3. (Optional) Unregister the subtitle callback function in the AVPlayer instance used for video playback when subtitles are not required.

   ```ts
    this.avPlayer?.off('subtitleUpdate');
   ```


## Running the Sample Project

1. Create a project, download the [sample project](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSSubtitle), and copy the following resources of the sample project to the corresponding directories.
    ```
    AVPlayerArkTSSubtitle
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
        └── test1.srt (subtitle resource)
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
  @State subtitle: string = '';
  ...

  async avSetupVideoAndSubtitle() {
    // Call getRawFd of the resourceManager member of UIAbilityContext to obtain the media asset URL.
    // The return type is {fd,offset,length}, where fd indicates the file descriptor address of the HAP file, offset indicates the media asset offset, and length indicates the duration of the media asset to play.
    ...
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

    // Set subtitles.
    let fileDescriptorSub = await this.context.resourceManager.getRawFd('test1.srt');
    this.avPlayer.addSubtitleFromFd(fileDescriptorSub.fd, fileDescriptorSub.offset, fileDescriptorSub.length);
  }

  // (Optional) Unregister the subtitle callback function in the AVPlayer instance used for video playback when subtitles are not required.
  // async avTurnOffSubtitle() {
  //   this.avPlayer?.off('subtitleUpdate');
  // }

  // Set AVPlayer callback functions.
  async setAVPlayerCallback(callback: (avPlayer: media.AVPlayer) => void, vType?: number): Promise<void> {
    // Callback function for the seek operation.
    ...
    // Callback function for state changes.
    ...
    // Callback function for time updates.
    ...
    // Callback function for subtitle updates.
    this.avPlayer.on('subtitleUpdate', (info: media.SubtitleInfo) => {
      if (!!info) {
        let text = (!info.text) ? '' : info.text;
        let startTime = (!info.startTime) ? 0 : info.startTime;
        let duration = (!info.duration) ? 0 : info.duration;
        console.info(`${this.tag}: subtitleUpdate info: text=${text} startTime=${startTime} duration=${duration}`);
        this.subtitle = text;
      } else {
        console.info(`${this.tag}: subtitleUpdate info is null`);
      }
    });
  }

  ...

  @Builder
  CoverXComponent() {...}

  build() {...}
}
```
