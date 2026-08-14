# Using ImageSource to Obtain Specific Metadata

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:47:54.545Z pushedAt=2026-08-11T09:25:24.119Z -->

Starting from API version 23, you can use `ImageSource` to obtain specific metadata from various image formats, including GIF, HEIFS, DNG, WebP, PNG, JFIF, TIFF, and AVIS.

## Supported Metadata Categories

| Metadata Category | MetadataType | Return Field | Starting API Version | Typical Information |
| ---------- | ------------ | -------- | ----------- | -------- |
| GIF | GIF_METADATA | [GifMetadata](../../reference/apis-image-kit/arkts-apis-image-GifMetadata.md) | 26.0.0 | Frame delay time, loop count, canvas size, etc. |
| HEIFS | HEIFS_METADATA | [HeifsMetadata](../../reference/apis-image-kit/arkts-apis-image-HeifsMetadata.md) | 23 | Canvas height, canvas width, unclamped delay time, etc. |
| DNG | DNG_METADATA | [DngMetadata](../../reference/apis-image-kit/arkts-apis-image-i.md#dngmetadata24) | 24 | DNG version, camera model, CFA parameters, black/white levels, color correction matrix, etc. |
| WebP | WEBP_METADATA | [WebPMetadata](../../reference/apis-image-kit/arkts-apis-image-WebPMetadata.md) | 24 | Canvas size, frame delay time, loop count, etc. |
| PNG | PNG_METADATA | [PngMetadata](../../reference/apis-image-kit/arkts-apis-image-PngMetadata.md) | 26.0.0 | Pixel density, description, copyright, etc. |
| JFIF | JFIF_METADATA | [JfifMetadata](../../reference/apis-image-kit/arkts-apis-image-JfifMetadata.md) | 26.0.0 | Pixel density, progressive encoding, etc. |
| TIFF | TIFF_METADATA | [TiffMetadata](../../reference/apis-image-kit/arkts-apis-image-TiffMetadata.md) | 26.0.0 | Resolution, chromaticity coordinates, compression method, etc. |
| AVIS | AVIS_METADATA | [AvisMetadata](../../reference/apis-image-kit/arkts-apis-image-AvisMetadata.md) | 26.0.0 | Frame delay time, etc. |

> **NOTE**
>
> `HeifsMetadata` is available since API version 23, and three properties (`heifsCanvasWidth`, `heifsCanvasHeight`, and `heifsUnclampedDelayTime`) are newly added in API version 26.0.0.

## Available APIs

| API | Description |
| --- | --- |
| [readImageMetadata](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#readimagemetadata23) | Reads the metadata of an image source, using propertyKeys to specify the metadata fields.<br>Supported since API version 23. |
| [readImageMetadataByType](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#readimagemetadatabytype24) | Reads the metadata of an image source, using metadataTypes to specify the metadata types.<br>Supported since API version 24. |

## How to Develop

For details about the APIs for obtaining image-specific metadata, see [ImageSource](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md) and [Metadata](../../reference/apis-image-kit/arkts-apis-image-Metadata.md).

1. Import the `Image` module globally, and import the corresponding Kit modules as needed.

   <!-- @[decodingPixelMap_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/DecodingPixelMap.ets) -->   

   ``` TypeScript
   // Import the related modules.
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { resourceManager } from '@kit.LocalizationKit';
   ```

2. Create an `ImageSource` instance by referring to [Using ImageSource for Image Decoding](image-decoding.md).

3. Read specific metadata.

   Use the [readImageMetadata](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#readimagemetadata23) API to read specific metadata of the corresponding format by specifying property keys (`propertyKeys`). The following example reads the frame delay time in GIF metadata:

   <!-- @[read_imageMetadata](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

   ``` TypeScript
   async readImageMetadata(imageSource: image.ImageSource | undefined) : Promise<image.ImageMetadata | undefined> {
     if (imageSource == undefined) {
       console.error('imageSource is undefined.');
       return undefined;
     }
     try {
       let properties: string[] = [image.GifPropertyKey.GIF_DELAY_TIME];
       let index: number = 0;
       let imageMetadata: image.ImageMetadata = await imageSource.readImageMetadata(properties, index);
       if (imageMetadata.gifMetadata != undefined) {
         console.info(`GIF_DELAY_TIME: ${JSON.stringify(imageMetadata.gifMetadata?.delayTime)}`);
       }
       return imageMetadata
     } catch (error) {
       console.error(`ReadImageMetadata failed, error.code: ${error.code},
                  error.message: ${error.message}`)
       return undefined;
     }
   }
   ```

   Use the [readImageMetadataByType](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#readimagemetadatabytype24) API to read specific metadata of the corresponding format by specifying a [MetadataType](../../reference/apis-image-kit/arkts-apis-image-e.md#metadatatype13) enum value. The following example reads GIF metadata:

   <!-- @[read_imageMetadataByType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

   ``` TypeScript
   async readImageMetadataByType(imageSource: image.ImageSource | undefined) : Promise<image.ImageMetadata | undefined> {
     if (imageSource == undefined) {
       console.error('imageSource is undefined.');
       return undefined;
     }
     try {
       let types: image.MetadataType[] = [image.MetadataType.GIF_METADATA];
       let index: number = 0;
       let imageMetadata: image.ImageMetadata = await imageSource.readImageMetadataByType(types, index);
       if (imageMetadata.gifMetadata != undefined) {
         console.info(`GIF_DELAY_TIME: ${JSON.stringify(imageMetadata.gifMetadata?.delayTime)}`);
       }
       return imageMetadata;
     } catch (error) {
       console.error(`ReadImageMetadataByType failed, error.code: ${error.code},
                  error.message: ${error.message}`)
       return undefined;
     }
   }
   ```

4. Release the `imageSource`.

   After confirming that the asynchronous method of `imageSource` has completed execution and the variable is no longer in use, you can manually call the following method to release it as needed.

   <!-- @[release_pixelMapDecoder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/DecodingPixelMap.ets) -->   

   ``` TypeScript
   async release() {
     try {
       await this.pixelMap?.release();
     } catch (error) {
       console.error(`Failed to release PixelMap: ${error}.`);
     } finally {
       this.pixelMap = undefined;
     }
   
     try {
       await this.imageSource?.release();
     } catch (error) {
       console.error(`Failed to release ImageSource: ${error}.`);
     } finally {
       this.imageSource = undefined;
     }
   }
   ```

## Precautions

- If the image does not contain the target metadata, the returned field is `undefined`. Check whether the field is valid before using it.

- Reading image files requires the read permission. Ensure that the app has declared and obtained the corresponding permission.

- When reading multi-frame images (such as GIF images), `index` must not be less than `0` or exceed the valid frame range. Otherwise, the read operation fails.