# 使用AVMetadataExtractor提取音视频元数据信息(ArkTS)

使用[AVMetadataExtractor](media-kit-intro.md#avmetadataextractor)可以实现从原始媒体资源中获取元数据。本指南将以获取一个媒体资源的元数据作为示例，向开发者讲解AVMetadataExtractor元数据相关功能。

获取音视频资源的元数据的全流程包含：创建AVMetadataExtractor、设置资源、获取元数据、获取音频资源的专辑封面或获取视频缩略图、销毁资源。

## 开发步骤及注意事项

详细的API说明请参考[AVMetadataExtractor API参考](../../reference/apis-media-kit/arkts-apis-media-AVMetadataExtractor.md)。

1. 使用createAVMetadataExtractor()创建实例。
   ```ts
   import { media } from '@kit.MediaKit';
   // 创建AVMetadataExtractor对象。
   let avMetadataExtractor: media.AVMetadataExtractor = await media.createAVMetadataExtractor();
   ```

2. 设置资源：用户可以根据需要选择设置属性fdSrc（表示文件描述符）和属性dataSrc（表示dataSource描述符）或者调用setUrlSource设置在线媒体链接。
   > **说明：**
   >
   > 开发者需根据实际情况，确认资源有效性并设置（只能设置其中一种）：
   >
   > - 如果设置fdSrc，可以使用ResourceManager.getRawFd打开HAP资源文件描述符，使用方法可参考[ResourceManager API参考](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)。也可以通过应用沙箱路径访问对应资源（必须确保资源可用），参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。
   >
   > - 如果设置dataSrc，必须正确设置dataSrc中的callback属性，确保callback被调用时能正确读取到对应资源，使用应用沙箱路径访问对应资源，参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。
   >
   > - 如果设置[setUrlSource](../../reference/apis-media-kit/arkts-apis-media-AVMetadataExtractor.md#seturlsource20)，必须正确设置setUrlSource中的url和headers属性，确保正确访问url。
   >
   > - 不同AVMetadataExtractor或者[AVImageGenerator](../../reference/apis-media-kit/arkts-apis-media-AVImageGenerator.md)实例，如果需要操作同一资源，需要多次打开文件描述符，不要共用同一文件描述符。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
   // 获取rawfile目录下资源文件描述符，设置fdSrc属性。
   // 获取当前组件所在Ability的Context，并通过Context获取应用文件路径。
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   // 设置fdSrc，test.mp3为rawfile目录下的预置资源，需要开发者根据实际情况进行替换。
   avMetadataExtractor.fdSrc = await context.resourceManager.getRawFd('test.mp3');

   // 使用fs文件系统打开沙箱地址获取媒体文件地址，设置fdSrc属性。
   context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   rootPath: string = this.context.filesDir; // 应用文件目录。
   testFilename: string = '/test.mp3'; // test.mp3为应用文件目录下的预置资源，需要开发者根据实际情况进行替换。
   avMetadataExtractor.fdSrc = fs.openSync(this.rootPath + this.testFilename); // 设置fdSrc属性。

   // 使用fs文件系统打开沙箱地址获取媒体文件地址，设置dataSrc属性。
   // 通过UIAbilityContext获取沙箱地址filesDir（以Stage模型为例）。
   let fd: number = fs.openSync(this.rootPath + this.testFilename).fd;
   let fileSize: number = fs.statSync(this.rootPath + this.testFilename).size;
   // 设置dataSrc描述符，通过callback从文件中获取资源，写入buffer中。
   let dataSrc: media.AVDataSrcDescriptor = {
     fileSize: fileSize,
     callback: (buffer, len, pos) => {
       if (buffer == undefined || len == undefined || pos == undefined) {
         console.error(TAG, `dataSrc callback param invalid`);
         return -1;
       }
       let options: ReadOptions = {
         offset: pos,
         length: len
       };
       let num = fs.readSync(fd, buffer, options);
       console.info(TAG, 'readAt end, num: ' + num);
       if (num > 0 && fileSize >= pos) {
         return num;
       }
       return -1;
     }
   };
   // 设置dataSrc。
   avMetadataExtractor.dataSrc = dataSrc;

   // 调用setUrlSource设置网络点播媒体资源URL，用来获取在线音视频元数据和在线视频缩略图。
   let url: string = 'http://xx.mp4';
   let headers: Record<string, string> = {
     "User-Agent" : "User-Agent-Value"
   };
   await avMetadataExtractor.setUrlSource(url, headers).then(() => {
   }).catch((error: BusinessError) => {
     console.error(`Failed to setUrlSource, code: ${error.code} message: ${error.message}`);
   });
   ```

3. 获取元数据：调用fetchMetadata()，可以获取到一个[AVMetadata](../../reference/apis-media-kit/arkts-apis-media-i.md#avmetadata11)对象，通过访问该对象的各个属性，可以获取到元数据。
   ```ts
   // 获取元数据（callback模式）。
   avMetadataExtractor.fetchMetadata((error, metadata) => {
     if (error) {
       console.error(TAG, `fetchMetadata callback failed, err = ${JSON.stringify(error)}`);
       return;
     }
   })

   // 获取元数据（promise模式）。
   let metadata = await avMetadataExtractor.fetchMetadata();
   ```

4. 对于视频资源：可以通过fetchMetadata获取的AVMetadata对象metadata拿到视频资源的宽、高等数据。
   ```ts
   // 获取视频资源的宽和高。
   let metadata = await avMetadataExtractor.fetchMetadata();
   let width = metadata.videoWidth;
   let height = metadata.videoHeight;
   ```

5. 对于音频资源而言，除了可以通过AVMetadata对象来获取音频资源的标题、时长等元数据外，还可以获取专辑封面（例如，调用fetchAlbumCover()，可以获取到专辑封面）。
   ```ts
   import { image } from '@kit.ImageKit';
   // pixelMap对象声明，用于图片显示。
   @State pixelMap: image.PixelMap | undefined = undefined;
   //获取专辑封面（callback模式）。
   avMetadataExtractor.fetchAlbumCover((err, pixelMap) => {
     if (err) {
       console.error(TAG, `fetchAlbumCover callback failed, err = ${JSON.stringify(err)}`);
       return;
     }
     this.pixelMap = pixelMap;
   })

   // 获取专辑封面（promise模式）。
   this.pixelMap = await avMetadataExtractor.fetchAlbumCover();
   ```

6. （可选）获取视频缩略图：调用fetchFrameByTime，可以获取到视频缩略图。
   ```ts
   import { image } from '@kit.ImageKit';
   // pixelMap对象声明，用于图片显示。
   @State pixelMap: image.PixelMap | undefined = undefined;
   // 接口入参声明。
   let timeUs: number = 0;
   let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_PREVIOUS_SYNC;
   let param: media.PixelMapParams = {
     width : 300,
     height : 300
   }
   // 获取视频缩略图（promise模式）。
   this.pixelMap = await avMetadataExtractor.fetchFrameByTime(timeUs, queryOption, param);

7. 释放资源：调用release()销毁实例，释放资源。
   ```ts
   // 释放资源（callback模式）。
   avMetadataExtractor.release((error) => {
     if (error) {
       console.error(TAG, `release failed, err = ${JSON.stringify(error)}`);
       return;
     }
     console.info(TAG, `release success.`);
   })

   // 释放资源（promise模式）。
   avMetadataExtractor.release();
   ```

## 运行示例工程

参考以下示例，获取一个音频的元数据和专辑封面。

1. 新建工程，下载[完整示例工程](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVMetadataExtractor/AVMetadataExtractorArkTS)，并将示例工程的资源复制到对应目录。
    ```
    AVMetadataExtractorArkTS
    entry/src/main/ets/
    └── pages
        └── Index.ets (获取元数据界面)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │
    └── rawfile
        └── test.mp3 (音频资源)
    ```
2. 编译新建工程并运行。