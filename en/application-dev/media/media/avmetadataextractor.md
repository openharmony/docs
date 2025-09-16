# Using AVMetadataExtractor to Extract Audio and Video Metadata (ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

You can use [AVMetadataExtractor](media-kit-intro.md#avmetadataextractor) to obtain metadata from a raw media asset. This topic walks you through on how to obtain the metadata of a media resource.

The full process of obtaining the metadata of a media asset includes creating an AVMetadataExtractor instance, setting resources, obtaining the metadata, obtaining the album cover of an audio resource or thumbnail of a video resource, and releasing the instance.

## How to Develop

Read [AVMetadataExtractor](../../reference/apis-media-kit/arkts-apis-media-AVMetadataExtractor.md) for the API reference.

1. Call **createAVMetadataExtractor()** to create an AVMetadataExtractor instance.
   ```ts
   import { media } from '@kit.MediaKit';
   // Create an AVMetadataExtractor instance.
   let avMetadataExtractor: media.AVMetadataExtractor = await media.createAVMetadataExtractor();
   ```

2. Set resources. Specifically, set the **fdSrc** property (indicating the file descriptor) and **dataSrc** property (indicating the data source descriptor), or call **setUrlSource** to set an online media link.
   
   You need to check the resource validity and set either property based on the actual situation.
   
   - To set **fdSrc**, use **ResourceManager.getRawFd** to obtain the file descriptor of the resource file packed in the HAP. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9). You can also access the resource through the application sandbox path (ensure that the resource is available). For details, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
      ```ts
      import { common } from '@kit.AbilityKit';
      import { media } from '@kit.MediaKit';

      // Create an AVMetadataExtractor instance.
      let avMetadataExtractor: media.AVMetadataExtractor = await media.createAVMetadataExtractor();
      // Obtain the file descriptor of the resource file in the rawfile directory and set the fdSrc property.
      // Obtain the context of the ability to which the current component belongs and obtain the application file path through the context.
      let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      // Set fdSrc. test.mp3 is a preset resource in the rawfile directory. Replace it with the actual one.
      avMetadataExtractor.fdSrc = await context.resourceManager.getRawFd('test.mp3');
      ```

   - To set **dataSrc**, set **callback** in **dataSrc** to ensure that the corresponding resource can be correctly read when the callback is invoked, and use the application sandbox directory to access the resource. For details, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
      ```ts
      import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
      import { common } from '@kit.AbilityKit';
      import { media } from '@kit.MediaKit';
      const TAG = 'MetadataDemo';

      // Create an AVMetadataExtractor instance.
      let avMetadataExtractor: media.AVMetadataExtractor = await media.createAVMetadataExtractor();
      let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      let rootPath: string = context.filesDir; // Application file directory.
      let testFilename: string = '/test.mp3'; // test.mp3 is a preset resource in the application file directory. Replace it with the actual one.
      // Use the file system to open the sandbox address to obtain the media file address and set the dataSrc property.
      // Obtain the sandbox address filesDir through UIAbilityContext. The stage model is used as an example.
      let fd: number = fs.openSync(rootPath + testFilename).fd;
      let fileSize: number = fs.statSync(rootPath + testFilename).size;
      // Set the dataSrc descriptor, obtain resources from the file through a callback, and write the resources to the buffer.
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
      // Set the dataSrc property.
      avMetadataExtractor.dataSrc = dataSrc;
      ```

   - If [setUrlSource](../../reference/apis-media-kit/arkts-apis-media-AVMetadataExtractor.md#seturlsource20) is used, fill in both the **url** and **headers** properties correctly to ensure that the URL is accessible.
      ```ts
      import { media } from '@kit.MediaKit';

      // Create an AVMetadataExtractor instance.
      let avMetadataExtractor: media.AVMetadataExtractor = await media.createAVMetadataExtractor();
      // Call setUrlSource to set the URL of the online on-demand media resource, so as to obtain online audio and video metadata and online video thumbnails.
      let url: string = 'http://xx.mp4';
      let headers: Record<string, string> = {
        "User-Agent" : "User-Agent-Value"
      };
      avMetadataExtractor.setUrlSource(url, headers);
      ```

   - If different AVMetadataExtractor or [AVImageGenerator](../../reference/apis-media-kit/arkts-apis-media-AVImageGenerator.md) instances need to operate the same resource, the file descriptor needs to be opened for multiple times. Therefore, do not share a file descriptor.
      ```ts
      import { common } from '@kit.AbilityKit';
      import { fileIo as fs } from '@kit.CoreFileKit';
      import { media } from '@kit.MediaKit';

      // Create an AVMetadataExtractor instance.
      let avMetadataExtractor: media.AVMetadataExtractor = await media.createAVMetadataExtractor();
      // Use the file system to open the sandbox address to obtain the media file address and set the fdSrc property.
      let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      let rootPath: string = context.filesDir; // Application file directory.
      let testFilename: string = '/test.mp3'; // test.mp3 is a preset resource in the application file directory. Replace it with the actual one.
      avMetadataExtractor.fdSrc = fs.openSync(rootPath + testFilename); // Set the fdSrc property.
      ```

3. Obtain metadata. Specifically, call **fetchMetadata()** to obtain an [AVMetadata](../../reference/apis-media-kit/arkts-apis-media-i.md#avmetadata11) object. You can access its properties to obtain the metadata.
   ```ts
   // Obtain the metadata (callback mode).
   avMetadataExtractor.fetchMetadata((error, metadata) => {
     if (error) {
       console.error(TAG, `fetchMetadata callback failed, err = ${JSON.stringify(error)}`);
       return;
     }
   })

   // Obtain the metadata (promise mode).
   let metadata = await avMetadataExtractor.fetchMetadata();
   ```

4. For a video resource, you can use **fetchMetadata** to obtain the width and height of the video resource from the metadata of the AVMetadata object.
   ```ts
   // Obtain the width and height of the video resource.
   let metadata = await avMetadataExtractor.fetchMetadata();
   let width = metadata.videoWidth;
   let height = metadata.videoHeight;
   ```

5. For an audio resource, in addition to obtaining metadata such as the title and duration of the audio resource through the AVMetadata object, you can retrieve the album cover by calling **fetchAlbumCover()**.
   ```ts
   import { image } from '@kit.ImageKit';
   // Declare a pixelMap object, which is used for image display.
   @State pixelMap: image.PixelMap | undefined = undefined;
   // Obtain the album cover (callback mode).
   avMetadataExtractor.fetchAlbumCover((err, pixelMap) => {
     if (err) {
       console.error(TAG, `fetchAlbumCover callback failed, err = ${JSON.stringify(err)}`);
       return;
     }
     this.pixelMap = pixelMap;
   })

   // Obtain the album cover (promise mode).
   this.pixelMap = await avMetadataExtractor.fetchAlbumCover();
   ```

6. (Optional) Call **fetchFrameByTime** to obtain the video thumbnail.
   ```ts
   import { image } from '@kit.ImageKit';
   // Declare a pixelMap object, which is used for image display.
   @State pixelMap: image.PixelMap | undefined = undefined;
   // Declare the input parameters of the API.
   let timeUs: number = 0;
   let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_PREVIOUS_SYNC;
   let param: media.PixelMapParams = {
     width : 300,
     height : 300
   }
   // Obtain the video thumbnail (promise mode).
   this.pixelMap = await avMetadataExtractor.fetchFrameByTime(timeUs, queryOption, param);
   ```
   
7. Call **release()** to release the AVMetadataExtractor instance.
   ```ts
   // Release the instance (callback mode).
   avMetadataExtractor.release((error) => {
     if (error) {
       console.error(TAG, `release failed, err = ${JSON.stringify(error)}`);
       return;
     }
     console.info(TAG, `release success.`);
   })

   // Release the instance (promise mode).
   avMetadataExtractor.release();
   ```

## Running the Sample Project

Refer to the sample project to obtain audio metadata and album cover.

1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVMetadataExtractor/AVMetadataExtractorArkTS), and copy its resources to the corresponding directories.
    ```
    AVMetadataExtractorArkTS
    entry/src/main/ets/
    └── pages
        └── Index.ets (metadata retrieval UI)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │
    └── rawfile
        └── test.mp3 (audio resource)
    ```
2. Compile and run the project.
