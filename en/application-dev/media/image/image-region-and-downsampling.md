# Image Region Decoding and Downsampling (ArkTS)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

When processing large images, directly decoding the entire image may cause excessive memory usage and long decoding time for an application. Region decoding and downsampling decoding can effectively optimize these scenarios:

- **Region decoding**: Decodes only a specified rectangular region of the image. This is suitable for scenarios where only a portion of the image needs to be viewed.

- **Downsampling**: Decodes the image to the desired dimensions, with the decoder automatically selecting the optimal sampling rate. This is suitable for large image preview scenarios.

**Application scenarios**:

| Scenario | Recommended approach | Description |
|------|----------|------|
| Viewing an enlarged local region of an image | Region decoding | Decodes only the region to be viewed. |
| Large image preview (for example, displaying a 4K image on a phone screen) | Downsampling | Reduces the resolution to lower memory usage. |
| Map/Panorama tile loading | Combined use | Specifies both the region and the output size. |

## Region Decoding

Region decoding specifies the rectangular region to decode by setting the decoding parameter `desiredRegion`. The decoder decodes only the data in this area. For parameter details, see [Region](../../reference/apis-image-kit/arkts-apis-image-i.md#region8).

### How to Develop

1. Create an `ImageSource` instance by referring to [Using ImageSource to Decode Images](image-decoding.md).

2. Set the `desiredRegion` parameter to perform region decoding.

   <!-- @[decode_region](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->

   ``` TypeScript
   async DecodeRegion(imageSource: image.ImageSource): Promise<image.PixelMap | undefined> {
     let decodingOptions: image.DecodingOptions = {
       desiredRegion: {
         size: { width: 1000, height: 1000 },
         x: 0,
         y: 0
       }
     };

     try {
       let pixelMap = await imageSource.createPixelMap(decodingOptions);
       console.info('Succeeded in decoding region.');
       return pixelMap;
     } catch (error) {
       console.error(`Failed to decode region: ${error}.`);
       return undefined;
     }
   }
   ```

### Constraints

- The region coordinates and size must be within the original image boundaries.

- The region size must be a positive integer.

## Downsampling

Downsampling specifies the desired output image size by setting the decoding parameter `desiredSize`. The decoder outputs a `PixelMap` based on the desired size, reducing the final memory usage.

**Decoding differences**:

- **JPEG, PNG, and HEIF formats**: A downsampling strategy is used during decoding, with the optimal sampling rate applied for higher decoding efficiency.

- **Other formats**: The original image is fully decoded first, and then scaled to the desired size.

For parameter details, see [DecodingOptions](../../reference/apis-image-kit/arkts-apis-image-i.md#decodingoptions7).

### How to Develop

1. Create an `ImageSource` instance by following the instructions in [Using ImageSource to Decode Images](image-decoding.md).

2. Set the `desiredSize` parameter to perform downsampling.

   <!-- @[decode_downsample](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->

   ``` TypeScript
   async DownsampleDecode(imageSource: image.ImageSource): Promise<image.PixelMap | undefined> {
     let decodingOptions: image.DecodingOptions = {
       desiredSize: { width: 512, height: 512 }
     };

     try {
       let pixelMap = await imageSource.createPixelMap(decodingOptions);
       console.info('Succeeded in downsample decoding.');
       return pixelMap;
     } catch (error) {
       console.error(`Failed to downsample decode: ${error}.`);
       return undefined;
     }
   }
   ```

## Combining Region Decoding and Downsampling

When both `desiredRegion` and `desiredSize` are set, the `cropAndScaleStrategy` parameter must be used to specify the sequence of cropping and scaling.

### cropAndScaleStrategy

| Strategy | Constant value | Operation sequence | Description |
|------|--------|----------|------|
| SCALE_FIRST | 1 | Scale first, then crop. | - |
| CROP_FIRST | 2 | Crop first, then scale. | Recommended. Reduces peak decoding memory. |

**CROP_FIRST is recommended**: Cropping before scaling allows precise control over the crop region and ensures consistent decoding results across different formats.

For parameter details, see [CropAndScaleStrategy](../../reference/apis-image-kit/arkts-apis-image-e.md#cropandscalestrategy18).

### How to Develop

1. Refer to [Using ImageSource to Decode Images](image-decoding.md) to create an `ImageSource` instance.

2. Set the `desiredRegion`, `desiredSize`, and `cropAndScaleStrategy` parameters.

   <!-- @[decode_combined](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->

   ``` TypeScript
   async CombinedDecode(imageSource: image.ImageSource): Promise<image.PixelMap | undefined> {
     let decodingOptions: image.DecodingOptions = {
       desiredRegion: {
         size: { width: 2000, height: 2000 },
         x: 1000,
         y: 500
       },
       desiredSize: { width: 512, height: 512 },
       cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST
     };

     try {
       let pixelMap = await imageSource.createPixelMap(decodingOptions);
       console.info('Succeeded in combined decoding.');
       return pixelMap;
     } catch (error) {
       console.error(`Failed to combined decode: ${error}.`);
       return undefined;
     }
   }
   ```

## Notes

- When setting both `desiredRegion` and `desiredSize`, you are advised to set `cropAndScaleStrategy` to `CROP_FIRST` to ensure consistent decoding results.

- For images whose original pixel memory exceeds 2 GB, you are advised to use downsampling to avoid memory overflow.
