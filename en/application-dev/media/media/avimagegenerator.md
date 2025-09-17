# Using AVImageGenerator to Extract Video Images at a Specified Time (ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

You can use the [AVImageGenerator](media-kit-intro.md#avimagegenerator) to obtain the thumbnail of a video at the specified time from the raw media asset.

The full process of obtaining the video thumbnail includes creating an AVImageGenerator instance, setting resources, obtaining the thumbnail, and releasing the instance.

## How to Develop

Read [AVImageGenerator](../../reference/apis-media-kit/arkts-apis-media-AVImageGenerator.md) for the API reference.

1. Call **createAVImageGenerator()** to create an AVImageGenerator instance.

   ```ts
   import { media } from '@kit.MediaKit';
   let avImageGenerator: media.AVImageGenerator = await media.createAVImageGenerator();
   ```

2. Set resources. Specifically, set the **fdSrc** property (indicating the file descriptor).
   > **NOTE**
   >
   > You need to check the resource validity and set **fdSrc** based on the actual situation.
   > - You can use **ResourceManager.getRawFd** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9).
   >
   > - You can also access the resource through the application sandbox path (ensure that the resource is available). For details, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
   >
   > - If different AVImageGenerator or [AVMetadataExtractor](../../reference/apis-media-kit/arkts-apis-media-AVMetadataExtractor.md) instances need to operate the same resource, the file descriptor needs to be opened for multiple times. Therefore, do not share a file descriptor.

   ```ts
   import { common } from '@kit.AbilityKit';
   // Obtain the context of the ability to which the current component belongs and obtain the application file path through the context.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   // Set fdSrc. H264_AAC.mp4 is a preset resource in the rawfile directory. Replace it with the actual one.
   avImageGenerator.fdSrc = await context.resourceManager.getRawFd('H264_AAC.mp4');
   ```

3. Obtain the thumbnail at the specified time. Specifically, call **fetchFrameByTime()** to obtain a PixelMap object, which can be used for image display.
   ```ts
   import { image } from '@kit.ImageKit';

   // Declare a pixelMap object, which is used for image display.
   @State pixelMap: image.PixelMap | undefined = undefined;

   // Initialize input parameters.
   let timeUs = 0; // Timestamp in the video where the thumbnail should be captured.
   let queryOption = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC; // AV_IMAGE_QUERY_NEXT_SYNC means that the key frame at or after the specified timestamp is selected.
   // Parameters for the output thumbnail format.
   let param: media.PixelMapParams = {
     width : 300, // Width of the output thumbnail.
     height : 300 // Height of the output thumbnail.
   };

   // Obtain the thumbnail (promise mode).
   this.pixelMap = await avImageGenerator.fetchFrameByTime(timeUs, queryOption, param);
   ```

4. Call **release()** to release the AVImageGenerator instance.
   ```ts
   // Release the instance (promise mode).
   avImageGenerator.release();
   ```

## Running the Sample Project

Refer to the sample project to obtain the video thumbnail at a specified time.

1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVImageGenerator/AVImageGeneratorArkTS), and copy its resources to the corresponding directories.
    ```
    AVImageGeneratorArkTS
    entry/src/main/ets/
    └── pages
        └── Index.ets (Thumbnail retrieval UI)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │
    └── rawfile
        └── H264_AAC.mp4 (Video resource)
    ```
2. Compile and run the project.
