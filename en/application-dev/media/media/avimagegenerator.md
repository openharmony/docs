# Using AVImageGenerator to Extract Video Images at a Specified Time (ArkTS)

You can use the [AVImageGenerator](media-kit-intro.md#avimagegenerator) to obtain the thumbnail of a video at the specified time from the raw media asset.

The full process of obtaining the video thumbnail includes creating an AVImageGenerator instance, setting resources, obtaining the thumbnail, and releasing the instance.

## How to Develop

Read [AVImageGenerator](../../reference/apis-media-kit/js-apis-media.md#avimagegenerator12) for the API reference.

1. Call **createAVImageGenerator()** to create an AVImageGenerator instance.

2. Set resources. Specifically, set the **fdSrc** attribute (indicating the file descriptor).
   > **NOTE**
   >
   > You need to check the resource validity and set **fdSrc** based on the actual situation.
   > - You can use **ResourceManager.getRawFd** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9).
   >
   > - You can also access the resource through the application sandbox path (ensure that the resource is available). For details, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
   >
   > - If different AVImageGenerator or [AVMetadataExtractor](../../reference/apis-media-kit/js-apis-media.md#avmetadataextractor11) instances need to operate the same resource, the file descriptor needs to be opened for multiple times. Therefore, do not share a file descriptor.

3. Obtain the thumbnail at the specified time. Specifically, call **fetchFrameByTime()** to obtain a PixelMap object, which can be used for image display.

4. Call **release()** to release the AVImageGenerator instance.

## Development Example

Refer to the sample code below to set the file descriptor and obtain the thumbnail of a video at the specified time.

```ts
import { media } from '@kit.MediaKit';
import { image } from '@kit.ImageKit';
import { common } from '@kit.AbilityKit';

const TAG = 'MetadataDemo';
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  // Declare a pixelMap object, which is used for image display.
  @State pixelMap: image.PixelMap | undefined = undefined;

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
          // Set fdSrc and obtain the video thumbnail.
          this.testFetchFrameByTime();
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

  // The demo below uses the resource manager API to obtain the video file packaged in the HAP. By setting fdSrc,
  // it obtains the thumbnail of the video at the specified time, and displays the thumbnail on the screen through the Image component.
  async testFetchFrameByTime() {
    // Create an AVImageGenerator instance.
    let avImageGenerator: media.AVImageGenerator = await media.createAVImageGenerator();
    // Set the fdSrc attribute.
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    avImageGenerator.fdSrc = await context.resourceManager.getRawFd('demo.mp4');

    // Initialize input parameters.
    let timeUs = 0;
    let queryOption = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC;
    let param: media.PixelMapParams = {
      width : 300,
      height : 300
    };

    // Obtain the thumbnail (promise mode).
    this.pixelMap = await avImageGenerator.fetchFrameByTime(timeUs, queryOption, param);

    // Release the instance (promise mode).
    avImageGenerator.release();
    console.info(TAG, `release success.`);
  }
}
```
