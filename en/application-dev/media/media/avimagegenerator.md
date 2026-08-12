# Using AVImageGenerator to Extract Video Images at a Specified Time (ArkTS)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @hanzhengshi-->
<!--Designer: @chris2981-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=4c8ef3749640601545b53c1c5b2711e5c92184c4 translatedAt=2026-08-11T01:49:15.495Z pushedAt=2026-08-11T11:44:10.382Z -->

You can use the [AVImageGenerator](media-kit-intro.md#avimagegenerator) to obtain the thumbnail of a video at the specified time from the raw media asset.

The full process of obtaining the video thumbnail includes creating an AVImageGenerator instance, setting resources, obtaining the thumbnail, and releasing the instance.

## How to Develop

For details about the APIs, see [AVImageGenerator](../../reference/apis-media-kit/arkts-apis-media-AVImageGenerator.md).

1. Use [createAVImageGenerator()](../../reference/apis-media-kit/arkts-apis-media-f.md#mediacreateavimagegenerator12-1) to create an instance.

   ```ts
   import { media } from '@kit.MediaKit';
   let avImageGenerator: media.AVImageGenerator = await media.createAVImageGenerator();
   ```

2. Set resources. Specifically, set the **fdSrc** property (indicating the file descriptor).

   > **NOTE**
   >
   > Verify resource validity and set **fdSrc** based on the actual situation:
   > - You can use **ResourceManager.getRawFd** to open a HAP resource file descriptor. For usage, refer to [getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9) in the **ResourceManager** API.
   >
   > - You can also use the app sandbox path to access the corresponding resource (ensure that the resource file is available). For details, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For an introduction to the app sandbox and how to push files to it, see [Application Sandbox](../../file-management/app-sandbox-directory.md).
   >
   > - If different **AVImageGenerator** or [AVMetadataExtractor](../../reference/apis-media-kit/arkts-apis-media-AVMetadataExtractor.md) instances need to operate on the same resource, you must open the file descriptor multiple times. Do not share the same file descriptor.

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
   await avImageGenerator.release().catch((err: BusinessError) => {
      console.error(`release failed, error code: ${err.code}, error message: ${err.message}`);
   });
   ```

## Running the Sample Project

Refer to the sample project to obtain the video thumbnail at a specified time.

1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVImageGenerator/AVImageGeneratorArkTS), and copy its resources to the corresponding directories.

    ```txt
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