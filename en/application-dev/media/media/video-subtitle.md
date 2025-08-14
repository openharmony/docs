# Using AVPlayer to Add External Subtitles to Videos (ArkTS)

Currently, you can add external subtitles to a video only before it starts playing.

During application development, you can call **on('subtitleUpdate')** of an AVPlayer instance to listen for subtitle updates.

## How to Develop

Read [AVPlayer](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md) for the API reference.

1. Set an external subtitle resource in the AVPlayer instance used for video playback.

   ```ts
    import media from '@ohos.multimedia.media';
    // Define the class member avPlayer and context.
    private avPlayer: media.AVPlayer | null = null;
    private context: common.UIAbilityContext | undefined = undefined;
    
    // In the service function (named avSetupVideoAndSubtitle in the sample project):
    // Create an AVPlayer instance.
    this.avPlayer = await media.createAVPlayer();

    // Set the video source (omitted).

    // Set the subtitle.
    let fileDescriptorSub = await this.context.resourceManager.getRawFd('xxx.srt');
    this.avPlayer.addSubtitleFromFd(fileDescriptorSub.fd, fileDescriptorSub.offset, fileDescriptorSub.length);
   ```

2. Register a subtitle callback function in the AVPlayer instance used for video playback.

   ```ts
    // Define the subtitle string to be displayed.
    @State subtitle: string = '';

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

1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSSubtitle), and copy its resources to the corresponding directories.
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
