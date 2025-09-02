# 使用SoundPool播放短音频(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

使用[SoundPool](media-kit-intro.md#soundpool)（音频池）提供的接口，可以实现低时延短音播放。

当应用开发时，经常需要使用一些急促简短的音效（如相机快门音效、系统通知音效等），此时建议调用SoundPool，实现一次加载，多次低时延播放。

SoundPool当前支持播放解码后1MB以下的音频资源，解码后大小超过1MB的长音频将截取前面的1MB大小数据进行播放，这相当于44.1kHz的16bit位深的立体声下约5.6秒的音频时长（在较低采样率或单声道配置下，持续时间会相应延长）。

本开发指导将以SoundPool进行一次低时延播放音频的过程为例，向开发者讲解如何使用SoundPool。详细的API声明请参考[SoundPool API参考](../../reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md)。

过程包括：创建SoundPool实例，加载音频资源（包括资源的解封装与解码:解码格式参考[音频解码支持](../avcodec/audio-decoding.md)），设置播放参数（循环模式/播放优先级等），播放控制（播放/停止），释放资源。

在应用开发过程中，开发者应通过监听方法检查当前播放状态并按照一定顺序调用接口，执行对应操作，否则系统可能会抛出异常或生成其他未定义的行为。具体顺序可参考下列开发步骤及对应说明。

> **说明：**
>
> 使用SoundPool播放短音频时，涉及音频焦点管控策略的问题，请参考[音频焦点指南](../audio/audio-playback-concurrency.md)。

## 开发步骤及注意事项

1. 调用createSoundPool方法创建SoundPool实例。

   ```ts
   import { media } from '@kit.MediaKit';
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   private soundPool: media.SoundPool | undefined = undefined;
   // audioRenderInfo中的参数usage取值为STREAM_USAGE_UNKNOWN，STREAM_USAGE_MUSIC，STREAM_USAGE_MOVIE。
   // STREAM_USAGE_AUDIOBOOK时，SoundPool播放短音时为混音模式，不会打断其他音频播放。
   let audioRendererInfo: audio.AudioRendererInfo = {
     usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
     rendererFlags: 1 // 音频渲染器标志。
   };

   //创建soundPool实例。
   this.soundPool = await media.createSoundPool(14, audioRendererInfo); // 最大播放的流数为14。
   ```

2. 调用on('loadComplete')方法，用于监听“资源加载完成”。

   ```ts
   private soundId: number = 0;
   // 加载完成回调。
   this.soundPool!.on('loadComplete', (soundId_: number) => {
     this.soundId = soundId_;
     console.info('loadComplete soundId: ' + soundId_);
   })
   ```

3. 调用on('playFinished')或者on('playFinishedWithStreamId')方法，用于监听“播放完成”。

    当仅单独注册'playFinished'事件回调或者'playFinishedWithStreamId'事件回调时，当音频播放完成的时候，都会触发注册的回调。

    当同时注册'playFinished'事件回调和'playFinishedWithStreamId'事件回调时，当音频播放完成的时候，仅会触发'playFinishedWithStreamId'事件回调，不会触发'playFinished'事件回调。

    ```ts
    this.soundPool!.on('playFinished', () => {
      console.info("receive play finished message");
      // 可进行下次播放。
    });
    this.soundPool!.on('playFinishedWithStreamId', (streamId) => {
      console.info("receive play finished message, streamId: " + streamId);
    });
    ```

4. 调用on('error')方法，设置错误类型监听。

    ```ts
    this.soundPool!.on('error', (error: BusinessError) => {
      console.error('error happened,message is :' + error.code);
      console.error('error happened,message is :' + error.message);
    });
    ```

5. 调用load方法进行音频资源加载。

    可以传入uri或fd加载资源，此处使用传入fd的方式为例，更多方法请参考[API文档](../../reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md#load)。

    当系统加载完毕音频资源文件的时候，会通过loadComplete回调，通知用户资源加载完成，请在收到回调之后，再进行后续的play操作。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { fileIo as fs } from '@kit.CoreFileKit';

    private soundId: number = 0;
    // 获取当前组件所在Ability的Context，以通过Context获取应用文件路径。
    let context = this.getUIContext().getHostContext();
    // 获取输入文件fd，test.ogg为rawfile目录下的预置资源，需要开发者根据实际情况进行替换。
    let fileDescriptor = await context!.resourceManager.getRawFd('test.ogg');
    this.soundId = await this.soundPool!.load(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length);
    console.info(`load soundPool soundId: ${this.soundId}`)
    ```

6. 配置播放参数PlayParameters，并在收到loadComplete回调通知之后，调用play方法播放音频。多次调用play播放同一个soundID，只会播放一次。

    ```ts
    private soundId: number = 0;
    private streamId: number = 0;
    let playParameters: media.PlayParameters = {
      loop: 1, // 循环1次，即播放2次。
      rate: 1, // 2倍速播放。
      leftVolume: 0.5, // 取值范围0.0-1.0。
      rightVolume: 0.5, // 取值范围0.0-1.0。
      priority: 0, // 最低优先级。
    };
    // 开始播放，调用play可携带播放参数PlayParameters。请在音频资源加载完毕，即收到loadComplete回调之后再执行play操作。
    this.soundPool!.play(this.soundId, playParameters, (error, streamID: number) => {
      if (error) {
        console.error(`play sound Error: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        this.streamId = streamID;
        console.info('play success soundId:' + this.streamId);
      }
    });
    ```

7. 调用setLoop方法设置循环次数。

    ```ts
    // 设置循环播放次数。
    await this.soundPool!.setLoop(this.streamId, 2); // 播放3次。
    ```

8. 调用setPriority方法设置优先级。

    ```ts
    // 设置对应流的优先级。
    await this.soundPool!.setPriority(this.streamId, 1);
    ```

9. 调用setVolume方法设置音量。

    ```ts
    // 设置音量。
    await this.soundPool!.setVolume(this.streamId, 0.5, 0.5);
    ```

10. 调用stop方法终止指定流的播放。

    ```ts
    // 终止指定流的播放。
    await this.soundPool!.stop(this.streamId);
    ```

11. 调用unload方法卸载音频资源。

    ```ts
    // 卸载音频资源。
    await this.soundPool!.unload(this.soundId);
    ```

12. 调用off('loadComplete')方法注销加载完成监听。

    ```ts
    await this.soundPool!.off('loadComplete');
    ```

13. 调用off('playFinished')方法注销播放完成监听。

    ```ts
    await this.soundPool!.off('playFinished');
    ```

14. 调用off('error')方法注销错误类型监听。

    ```ts
    await this.soundPool!.off('error');
    ```

15. 调用release方法释放SoundPool实例。

    ```ts
    // 释放SoundPool。
    await this.soundPool!.release();
    ```

## 运行示例工程

参考以下示例，使用SoundPool进行低时延播放。

1. 新建工程，下载[完整示例工程](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/SoundPool/SoundPoolArkTS)，并将示例工程的资源复制到对应目录。

    ```
    SoundPoolArkTS
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
    │
    └── rawfile
        └── test.ogg (音频资源)
    ```
2. 编译新建工程并运行。