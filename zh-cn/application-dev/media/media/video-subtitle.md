# 使用AVPlayer接口添加视频外挂字幕(ArkTS)

当前仅支持视频播放前设置外挂字幕。

在进行应用开发的过程中，开发者可以通过AVPlayer的实例注册on('subtitleUpdate')方法监听字幕信息。

## 开发步骤及注意事项

详细的API说明请参考[AVPlayer](../../reference/apis-media-kit/js-apis-media.md#avplayer9)

1. 使用视频播放的AVPlayer实例设置外挂字幕资源。

   ```ts
   let context = getContext(this) as common.UIAbilityContext
   let fileDescriptor = await context.resourceManager.getRawFd('xxx.srt')

   avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length)

   // 或者使用addSubtitleFromUrl接口
   let fdUrl:string = "http://xxx.xxx.xxx.xxx:xx/xx/index.srt" 
   avPlayer.addSubtitleFromUrl(fdUrl)
   ```

2. 使用视频播放的AVPlayer实例注册字幕回调函数。

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

3. (可选)当需要不显示字幕的时候，使用视频播放的AVPlayer实例注销字幕回调函数。

   ```ts
   avPlayer.off('subtitleUpdate')
   ```


## 完整示例

```ts
import { media } from '@kit.MediaKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class AVPlayerSubtitleDemo {
  private avPlayer: media.AVPlayer | undefined = undefined;
  // 注册avplayer回调函数
  setAVPlayerCallback(avPlayer: media.AVPlayer) {
    // error回调监听函数,当avPlayer在操作过程中出现错误时调用reset接口触发重置流程
    avPlayer.on('error', (err: BusinessError) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`)
      avPlayer.reset() // 调用reset重置资源，触发idle状态
    })
    // 注册字幕回调函数
    avPlayer.on('subtitleUpdate', (info: media.SubtitleInfo) => {
      if (info) {
        let text = (!info.text) ? '' : info.text
        let startTime = (!info.startTime) ? 0 : info.startTime
        let duration = (!info.duration) ? 0 : info.duration
        console.info('subtitleUpdate info: text=' + text + ' startTime=' + startTime +' duration=' + duration)
      } else {
        console.info('subtitleUpdate info is null')
      }
    })
  }

  // 以下demo为使用资源管理接口获取打包在HAP内的媒体资源文件并通过url属性设置
  async avPlayerSubtitleUrlDemo() {
    // 创建avPlayer实例对象
    this.avPlayer = await media.createAVPlayer()
    // 设置视频信息
    // 创建回调函数
    this.setAVPlayerCallback(this.avPlayer)


    let fdUrl:string = "http://xxx.xxx.xxx.xxx:xx/xx/index.srt"

    this.avPlayer.addSubtitleFromUrl(fdUrl)
  }

  // 以下demo为使用资源管理接口获取打包在HAP内的媒体资源文件并通过FromFd属性设置
  async avPlayerSubtitleFromFdDemo() {
    // 创建avPlayer实例对象
    this.avPlayer = await media.createAVPlayer()
    // 设置视频信息
    // 创建回调函数
    this.setAVPlayerCallback(this.avPlayer)

    let context = getContext(this) as common.UIAbilityContext
    let fileDescriptor = await context.resourceManager.getRawFd('xxx.srt')

    this.avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length)
  }

  // 注销字幕回调函数
  async avPlayerSubtitleOffDemo() {
    if(this.avPlayer) {
      this.avPlayer.off('subtitleUpdate')
    }
  }

}
```
