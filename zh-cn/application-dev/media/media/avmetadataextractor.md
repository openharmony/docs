# 使用AVMetadataExtractor提取音视频元数据信息(ArkTS)

使用AVMetadataExtractor可以实现从原始媒体资源中获取元数据，本开发指导将以获取一个音频资源的元数据作为示例，向开发者讲解AVMetadataExtractor元数据相关功能。视频资源的元数据获取流程与音频类似，由于视频没有专辑封面，所以无法获取视频资源的专辑封面。

获取音频资源的元数据的全流程包含：创建AVMetadataExtractor，设置资源，获取元数据，获取专辑封面，销毁资源。

## 开发步骤及注意事项

详细的API说明请参考[AVMetadataExtractor API参考](../../reference/apis-media-kit/js-apis-media.md#avmetadataextractor11)。

1. 使用createAVMetadataExtractor()创建实例。

2. 设置资源：用户可以根据需要选择设置属性fdSrc（表示文件描述符）, 或者设置属性dataSrc（表示dataSource描述符）。
   > **说明：**
   >
   > 开发者需根据实际情况，确认资源有效性并设置（只能设置其中一种）：
   >
   > - 如果设置fdSrc，可以使用ResourceManager.getRawFd打开HAP资源文件描述符，使用方法可参考[ResourceManager API参考](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)。也可以通过应用沙箱路径访问对应资源（必须确保资源可用），参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。
   >
   > - 如果设置dataSrc，必须正确设置dataSrc中的callback属性，确保callback被调用时能正确读取到对应资源，使用应用沙箱路径访问对应资源，参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。
   >
   > - 不同AVMetadataExtractor或者[AVImageGenerator](../../reference/apis-media-kit/js-apis-media.md#avmetadataextractor11)实例，如果需要操作同一资源，需要多次打开文件描述符，不要共用同一文件描述符。

3. 获取元数据：调用fetchMetadata()，可以获取到一个AVMetadata对象，通过访问该对象的各个属性，可以获取到元数据。

4. （可选）获取专辑封面：调用fetchAlbumCover()，可以获取到专辑封面。

5. 释放资源：调用release()销毁实例，释放资源。

## 完整示例

参考以下示例，设置文件描述符，获取一个音频的元数据和专辑封面。

```ts
import { media } from '@kit.MediaKit';
import { image } from '@kit.ImageKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';

const TAG = 'MetadataDemo'

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  // pixelMap对象声明，用于图片显示
  @State pixelMap: image.PixelMap | undefined = undefined;
  rootPath: string = getContext(this).getApplicationContext().filesDir
  testFilename: string = '/cover.mp3'

  build() {
    Row() {
      Column() {
        Text(this.message).fontSize(50).fontWeight(FontWeight.Bold)
        Button() {
          Text('TestButton')
            .fontSize(30)
            .fontWeight(FontWeight.Bold)
        }
        .type(ButtonType.Capsule)
        .margin({
          top: 20
        })
        .backgroundColor('#0D9FFB')
        .width('60%')
        .height('5%')
        .onClick(() => {
          // 设置fdSrc, 获取音频元数据和专辑封面（异步接口以Callback形式调用）
          this.testFetchMetadataFromFdSrcByCallback()
          // 设置fdSrc, 获取音频元数据和专辑封面（异步接口以Promise形式调用）
          this.testFetchMetadataFromFdSrcByPromise()
          // 通过fdSrc获取沙箱路径下音频元数据和专辑封面
          this.testFetchMetadataFromFdSrc()
          // 设置dataSrc, 获取音频元数据和专辑封面
          this.testFetchMetadataFromDataSrc()
        })

        Image(this.pixelMap).width(300).height(300)
          .margin({
            top: 20
          })
      }
      .width('100%')
    }
    .height('100%')
  }

  // 在以下demo中，使用资源管理接口获取打包在HAP内的媒体资源文件，通过设置fdSrc属性，获取音频元数据并打印，
  // 获取音频专辑封面并通过Image控件显示在屏幕上。该demo以Callback形式进行异步接口调用
  async testFetchMetadataFromFdSrcByCallback() {
    if (canIUse("SystemCapability.Multimedia.Media.AVMetadataExtractor")) {
      // 创建AVMetadataExtractor对象
      let avMetadataExtractor: media.AVMetadataExtractor = await media.createAVMetadataExtractor()

      // 设置fdSrc
      avMetadataExtractor.fdSrc = await getContext(this).resourceManager.getRawFd('cover.mp3');

      // 获取元数据（callback模式）
      avMetadataExtractor.fetchMetadata((error, metadata) => {
        if (error) {
          console.error(TAG, `fetchMetadata callback failed, err = ${JSON.stringify(error)}`)
          return
        }
        console.info(TAG, `fetchMetadata callback success, genre: ${metadata.genre}`)
      })

      //获取专辑封面（callback模式）
      avMetadataExtractor.fetchAlbumCover((err, pixelMap) => {
        if (err) {
          console.error(TAG, `fetchAlbumCover callback failed, err = ${JSON.stringify(err)}`)
          return
        }
        this.pixelMap = pixelMap

        // 释放资源（callback模式）
        avMetadataExtractor.release((error) => {
          if (error) {
            console.error(TAG, `release failed, err = ${JSON.stringify(error)}`)
            return
          }
          console.info(TAG, `release success.`)
        })
      })
    }
  }

  // 在以下demo中，使用资源管理接口获取打包在HAP内的媒体资源文件，通过设置fdSrc属性，获取音频元数据并打印，
  // 获取音频专辑封面并通过Image控件显示在屏幕上。该demo以Promise形式进行异步接口调用
  async testFetchMetadataFromFdSrcByPromise() {
    if (canIUse("SystemCapability.Multimedia.Media.AVMetadataExtractor")) {
      // 创建AVMetadataExtractor对象
      let avMetadataExtractor: media.AVMetadataExtractor = await media.createAVMetadataExtractor()
      // 设置fdSrc
      avMetadataExtractor.fdSrc = await getContext(this).resourceManager.getRawFd('cover.mp3');

      // 获取元数据（promise模式）
      let metadata = await avMetadataExtractor.fetchMetadata()
      console.info(TAG, `get meta data, hasAudio: ${metadata.hasAudio}`)

      // 获取专辑封面（promise模式）
      this.pixelMap = await avMetadataExtractor.fetchAlbumCover()

      // 释放资源（promise模式）
      avMetadataExtractor.release()
      console.info(TAG, `release success.`)
    }
  }

  // 在以下demo中，使用fs文件系统打开沙箱地址获取媒体文件地址，设置fdSrc属性，获取音频元数据并打印，
  // 获取音频专辑封面并通过Image控件显示在屏幕上。
  async testFetchMetadataFromFdSrc() {
    if (canIUse("SystemCapability.Multimedia.Media.AVMetadataExtractor")) {
      // 创建AVMetadataExtractor对象
      let avMetadataExtractor = await media.createAVMetadataExtractor()

      // 设置fdSrc
      avMetadataExtractor.fdSrc = fs.openSync(this.rootPath + this.testFilename);

      // 获取元数据（promise模式）
      let metadata = await avMetadataExtractor.fetchMetadata()
      console.info(TAG, `get meta data, mimeType: ${metadata.mimeType}`)

      // 获取专辑封面（promise模式）
      this.pixelMap = await avMetadataExtractor.fetchAlbumCover()

      // 释放资源（promise模式）
      avMetadataExtractor.release()
      console.info(TAG, `release data source success.`)
    }
  }

  // 在以下demo中，使用fs文件系统打开沙箱地址获取媒体文件地址，设置dataSrc属性，获取音频元数据并打印，
  // 获取音频专辑封面并通过Image控件显示在屏幕上。
  async testFetchMetadataFromDataSrc() {
    let context = getContext(this) as common.UIAbilityContext
    // 通过UIAbilityContext获取沙箱地址filesDir（以Stage模型为例）
    let fd: number = fs.openSync(this.rootPath + this.testFilename).fd;
    let fileSize: number = fs.statSync(this.rootPath + this.testFilename).size;
    // 设置dataSrc描述符，通过callback从文件中获取资源，写入buffer中
    let dataSrc: media.AVDataSrcDescriptor = {
      fileSize: fileSize,
      callback: (buffer, len, pos) => {
        if (buffer == undefined || len == undefined || pos == undefined) {
          console.error(TAG, `dataSrc callback param invalid`)
          return -1
        }
        let options: ReadOptions = {
          offset: pos,
          length: len
        }
        let num = fs.readSync(fd, buffer, options)
        console.info(TAG, 'readAt end, num: ' + num)
        if (num > 0 && fileSize >= pos) {
          return num;
        }
        return -1;
      }
    }

    if (canIUse("SystemCapability.Multimedia.Media.AVMetadataExtractor")) {
      // 创建AVMetadataExtractor对象
      let avMetadataExtractor = await media.createAVMetadataExtractor()
      // 设置dataSrc
      avMetadataExtractor.dataSrc = dataSrc;

      // 获取元数据（promise模式）
      let metadata = await avMetadataExtractor.fetchMetadata()
      console.info(TAG, `get meta data, mimeType: ${metadata.mimeType}`)

      // 获取专辑封面（promise模式）
      this.pixelMap = await avMetadataExtractor.fetchAlbumCover()

      // 释放资源（promise模式）
      avMetadataExtractor.release()
      console.info(TAG, `release data source success.`)
    }
  }
}
```