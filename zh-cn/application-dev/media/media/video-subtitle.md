# 使用AVPlayer添加视频外挂字幕(ArkTS)

当前仅支持视频播放前设置外挂字幕。

在进行应用开发的过程中，开发者可以通过AVPlayer的实例注册on('subtitleUpdate')方法监听字幕信息。

## 开发步骤及注意事项

详细的API说明请参考[AVPlayer](../../reference/apis-media-kit/js-apis-media.md#avplayer9)

1. 使用视频播放的AVPlayer实例设置外挂字幕资源。

   ```ts
    // 设定字幕
    let fileDescriptorSub = await this.context.resourceManager.getRawFd('xxx.srt');
    this.avPlayer.addSubtitleFromFd(fileDescriptorSub.fd, fileDescriptorSub.offset, fileDescriptorSub.length);
   ```

2. 使用视频播放的AVPlayer实例注册字幕回调函数。

   ```ts
    // 字幕回调函数
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

1. 新建工程，下载[示例工程](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSSubtitle)，并将示例工程的以下资源复制到对应目录。
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

## 开发示例

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
    // 通过UIAbilityContext的resourceManager成员的getRawFd接口获取媒体资源播放地址。
    // 返回类型为{fd,offset,length},fd为HAP包fd地址，offset为媒体资源偏移量，length为播放长度。
    ...
    // 创建avPlayer实例对象
    this.avPlayer = await media.createAVPlayer();

    // 创建状态机变化回调函数
    await this.setAVPlayerCallback((avPlayer: media.AVPlayer) => {
      this.percent = avPlayer.width / avPlayer.height;
      this.setVideoWH();
      this.durationTime = this.getDurationTime();
      setInterval(() => { // 更新当前时间
        if (!this.isSwiping) {
          this.currentTime = this.getCurrentTime();
        }
      }, SET_INTERVAL);
    });

    // 为fdSrc赋值触发initialized状态机上报
    this.avPlayer.fdSrc = avFileDescriptor;

    // 设定字幕
    let fileDescriptorSub = await this.context.resourceManager.getRawFd('test1.srt');
    this.avPlayer.addSubtitleFromFd(fileDescriptorSub.fd, fileDescriptorSub.offset, fileDescriptorSub.length);
  }

  // (可选)当需要不显示字幕的时候，使用视频播放的AVPlayer实例注销字幕回调函数
  // async avTurnOffSubtitle() {
  //   this.avPlayer?.off('subtitleUpdate');
  // }

  // 注册avplayer回调函数
  async setAVPlayerCallback(callback: (avPlayer: media.AVPlayer) => void, vType?: number): Promise<void> {
    // seek操作结果回调函数
    ...
    // 状态机变化回调函数
    ...
    // 时间上报监听函数
    ...
    // 字幕回调函数
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
