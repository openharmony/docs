# 使用AVImageGenerator提取视频指定时间图像(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

使用[AVImageGenerator](media-kit-intro.md#avimagegenerator)可以实现从原始媒体资源中获取视频指定时间的缩略图，本开发指导将以获取一个视频资源的缩略图作为示例，向开发者讲解AVImageGenerator相关功能。

获取视频资源的缩略图的全流程包含：创建AVImageGenerator对象，设置资源，获取缩略图，销毁资源。

## 开发步骤及注意事项

详细的API说明请参考[AVImageGenerator API参考](../../reference/apis-media-kit/arkts-apis-media-AVImageGenerator.md)。

1. 使用createAVImageGenerator()创建实例。

   ```ts
   import { media } from '@kit.MediaKit';
   let avImageGenerator: media.AVImageGenerator = await media.createAVImageGenerator();
   ```

2. 设置资源：需要设置属性fdSrc（表示文件描述符）。
   > **说明：**
   >
   > 开发者需根据实际情况，确认资源有效性并设置fdSrc：
   > - 可以使用ResourceManager.getRawFd打开HAP资源文件描述符，使用方法可参考[ResourceManager API参考](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)。
   >
   > - 也可以使用应用沙箱路径访问对应资源（必须确认资源文件可用），参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。
   >
   > - 不同AVImageGenerator或者[AVMetadataExtractor](../../reference/apis-media-kit/arkts-apis-media-AVMetadataExtractor.md)，如果需要操作同一资源，需要多次打开文件描述符，不要共用同一文件描述符。

   ```ts
   import { common } from '@kit.AbilityKit';
   // 获取当前组件所在Ability的Context，并通过Context获取应用文件路径。
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   // 设置fdSrc，H264_AAC.mp4为rawfile目录下的预置资源，需要开发者根据实际情况进行替换。
   avImageGenerator.fdSrc = await context.resourceManager.getRawFd('H264_AAC.mp4');
   ```

3. 获取指定时间图像：调用fetchFrameByTime()，可以获取到一个PixelMap对象，该对象可用于图片显示。
   ```ts
   import { image } from '@kit.ImageKit';

   // pixelMap对象声明，用于图片显示。
   @State pixelMap: image.PixelMap | undefined = undefined;

   // 初始化入参。
   let timeUs = 0; // 需要获取的缩略图在视频中的时间点。
   let queryOption = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC; // AV_IMAGE_QUERY_NEXT_SYNC表示选取传入时间点或之后的关键帧。
   // 输出缩略图的格式参数。
   let param: media.PixelMapParams = {
     width : 300, // 输出的缩略图宽度。
     height : 300 // 输出的缩略图高度。
   };

   // 获取缩略图（promise模式）。
   this.pixelMap = await avImageGenerator.fetchFrameByTime(timeUs, queryOption, param);
   ```

4. 释放资源：调用release()销毁实例，释放资源。
   ```ts
   // 释放资源（promise模式）。
   avImageGenerator.release();
   ```

## 运行示例工程

参考以下示例，获取一个视频指定时间的缩略图。

1. 新建工程，下载[完整示例工程](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVImageGenerator/AVImageGeneratorArkTS)，并将示例工程的资源复制到对应目录。
    ```
    AVImageGeneratorArkTS
    entry/src/main/ets/
    └── pages
        └── Index.ets (获取缩略图界面)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │
    └── rawfile
        └── H264_AAC.mp4 (视频资源)
    ```
2. 编译新建工程并运行。