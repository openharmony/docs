# 使用AVPlayer添加视频外挂字幕(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xushubo; @chennotfound-->
<!--SE: @dongyu_dy-->
<!--TSE: @xchaosioda-->

当前仅支持视频播放前设置外挂字幕。

在进行应用开发的过程中，开发者可以通过AVPlayer的实例注册on('subtitleUpdate')方法监听字幕信息。

## 开发步骤及注意事项

详细的API说明请参考[AVPlayer](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md)

1. 使用视频播放的AVPlayer实例设置外挂字幕资源。

   ```ts
    import media from '@ohos.multimedia.media';
    // 类成员定义avPlayer和context。
    private avPlayer: media.AVPlayer | null = null;
    private context: common.UIAbilityContext | undefined = undefined;
    
    // 在业务函数中（示例工程函数名为avSetupVideoAndSubtitle）：
    // 创建avPlayer实例对象。
    this.avPlayer = await media.createAVPlayer();

    // 设定视频源（此处省略）。

    // 设定字幕。
    let fileDescriptorSub = await this.context.resourceManager.getRawFd('xxx.srt');
    this.avPlayer.addSubtitleFromFd(fileDescriptorSub.fd, fileDescriptorSub.offset, fileDescriptorSub.length);
   ```

2. 使用视频播放的AVPlayer实例注册字幕回调函数。

   ```ts
    // 类成员定义用来显示的字幕字符串。
    @State subtitle: string = '';

    // 字幕回调函数。
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

3. (可选)当需要不显示字幕的时候，使用视频播放的AVPlayer实例注销字幕回调函数。

   ```ts
    this.avPlayer?.off('subtitleUpdate');
   ```


## 运行完整示例

1. 新建工程，下载[示例工程](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSSubtitle)，并将示例工程的以下资源复制到对应目录。
    ```
    AVPlayerArkTSSubtitle
    entry/src/main/ets/
    └── pages
        └── Index.ets (播放界面)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │       ├── ic_video_play.svg  (播放键图片资源)
    │       └── ic_video_pause.svg (暂停键图片资源)
    └── rawfile
        ├── test1.mp4 （视频资源）
        └── test1.srt （字幕资源）
    ```

2. 编译新建工程并运行。
