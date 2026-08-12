# Image Region Decoding and Downsampling (C/C++)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b6ba46968c3b2f8f9050610c4f908e26304f653a translatedAt=2026-08-11T01:47:23.019Z pushedAt=2026-08-11T08:41:24.382Z -->

When processing large images, directly decoding the entire image may cause excessive memory usage and long decoding time for an app. Region decoding and downsampling decoding can effectively optimize these scenarios:

- **Region decoding**: Decodes only a specified rectangular region of the image, suitable for scenarios where only a portion of the image needs to be viewed.

- **Downsampling**: Decodes the image to the desired dimensions, with the decoder automatically selecting the optimal sampling rate, suitable for large image preview scenarios.

**When to Use**

| Scenario | Recommended Approach | Description |
|------|----------|------|
| Partial zoom-in viewing of an image | Region Decoding | Decodes only the region to be viewed. |
| Large image preview (e.g., displaying a 4K image on a phone screen) | Downsampling Decoding | Reduces the resolution to lower memory usage. |
| Map/panorama tile loading | Combined use | Specifies both the region and the output size. |

## Region Decoding

Region decoding specifies the rectangular region to decode by setting the decoding parameter `cropRegion`. The decoder only decodes data within that region. For parameter details, see [Image_Region](../../reference/apis-image-kit/capi-image-nativemodule-image-region.md).

> **NOTE**
> For Native C region decoding, use the `OH_DecodingOptions_SetCropRegion` API instead of `SetDesiredRegion`. The `SetDesiredRegion` API does not take effect.

### How to Develop

1. Refer to [Using Image_NativeModule to Decode Images](image-source-c.md) to create an `OH_ImageSourceNative` instance.

2. Set the `cropRegion` parameter to perform region decoding.

   <!-- @[decode_region](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) --> 

   ``` C++
   // Region decoding example.
   napi_value DecodeRegion(napi_env env, napi_callback_info info)
   {
       OH_DecodingOptions *ops = nullptr;
       OH_DecodingOptions_Create(&ops);
       
       // Set the crop region parameters. Use SetCropRegion to implement region decoding.
       Image_Region region = {
           .x = 0,
           .y = 0,
           .width = 1000,
           .height = 1000
       };
       OH_DecodingOptions_SetCropRegion(ops, &region);
       
       OH_PixelmapNative_Release(g_thisImageSource->resPixMap);
       g_thisImageSource->resPixMap = nullptr;
       
       Image_ErrorCode errCode = OH_ImageSourceNative_CreatePixelmap(g_thisImageSource->source,
                                                                     ops, &g_thisImageSource->resPixMap);
       OH_DecodingOptions_Release(ops);
       ops = nullptr;
       
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "DecodeRegion failed, errCode: %{public}d.", errCode);
           return GetJsResult(env, errCode);
       }
       OH_LOG_INFO(LOG_APP, "DecodeRegion succeeded.");
       return GetJsResult(env, errCode);
   }
   ```

### Constraints

- The region coordinates and size must be within the original image boundaries.

- The region size must be a positive integer.

## Downsampling

Downsampling specifies the expected output image size by setting the decoding parameter `desiredSize`. The decoder outputs a `PixelMap` based on the desired size, reducing the final memory usage.

**Decoding differences**:

- **JPEG, PNG, and HEIF formats**: A downsampling strategy is used during decoding, with the optimal sampling rate applied for higher decoding efficiency.

- **Other formats**: The original image is fully decoded first, and then scaled to the desired size.

For parameter details, see [OH_DecodingOptions](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md).

### How to Develop

1. Create an `OH_ImageSourceNative` instance by referring to [Using Image_NativeModule to Decode Images](image-source-c.md).

2. Set the `desiredSize` parameter to perform downsampling.

   <!-- @[decode_downsample](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) --> 

   ``` C++
   // Downsampling decoding example.
   napi_value DownsampleDecode(napi_env env, napi_callback_info info)
   {
       OH_DecodingOptions *ops = nullptr;
       OH_DecodingOptions_Create(&ops);
       
       // Set the desired output size parameters.
       Image_Size desiredSize = {
           .width = 512,
           .height = 512
       };
       OH_DecodingOptions_SetDesiredSize(ops, &desiredSize);
       
       OH_PixelmapNative_Release(g_thisImageSource->resPixMap);
       g_thisImageSource->resPixMap = nullptr;
       
       Image_ErrorCode errCode = OH_ImageSourceNative_CreatePixelmap(g_thisImageSource->source,
                                                                     ops, &g_thisImageSource->resPixMap);
       OH_DecodingOptions_Release(ops);
       ops = nullptr;
       
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "DownsampleDecode failed, errCode: %{public}d.", errCode);
           return GetJsResult(env, errCode);
       }
       OH_LOG_INFO(LOG_APP, "DownsampleDecode succeeded.");
       return GetJsResult(env, errCode);
   }
   ```

## Combining Region Decoding and Downsampling

When both `cropRegion` and `desiredSize` are set, use the `cropAndScaleStrategy` parameter to specify the order of cropping and scaling operations.

### cropAndScaleStrategy

| Strategy | Constant Value | Operation Sequence | Description |
|------|--------|----------|------|
| IMAGE_CROP_AND_SCALE_STRATEGY_SCALE_FIRST | 1 | Scale first, then crop. | - |
| IMAGE_CROP_AND_SCALE_STRATEGY_CROP_FIRST | 2 | Crop first, then scale. | Recommended. Reduces peak decoding memory. |

**CROP_FIRST is recommended**: Cropping before scaling allows precise control over the crop region and ensures consistent decoding results across different formats.

For details about the parameter, see [Image_CropAndScaleStrategy](../../reference/apis-image-kit/capi-image-source-native-h.md#image_cropandscalestrategy).

### How to Develop

1. Create an `OH_ImageSourceNative` instance by referring to [Using Image_NativeModule to Decode Images](image-source-c.md).

2. Set the `cropRegion`, `desiredSize`, and `cropAndScaleStrategy` parameters.

   <!-- @[decode_combined](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) --> 

   ``` C++
   // Example of combining region decoding and downsampling decoding.
   napi_value CombinedDecode(napi_env env, napi_callback_info info)
   {
       OH_DecodingOptions *ops = nullptr;
       OH_DecodingOptions_Create(&ops);
       
       Image_Region region = {
           .x = 1000,
           .y = 500,
           .width = 2000,
           .height = 2000
       };
       OH_DecodingOptions_SetCropRegion(ops, &region);
       
       Image_Size desiredSize = {
           .width = 512,
           .height = 512
       };
       OH_DecodingOptions_SetDesiredSize(ops, &desiredSize);
       
       OH_DecodingOptions_SetCropAndScaleStrategy(ops, IMAGE_CROP_AND_SCALE_STRATEGY_CROP_FIRST);
       
       OH_PixelmapNative_Release(g_thisImageSource->resPixMap);
       g_thisImageSource->resPixMap = nullptr;
       
       Image_ErrorCode errCode = OH_ImageSourceNative_CreatePixelmap(g_thisImageSource->source,
                                                                     ops, &g_thisImageSource->resPixMap);
       OH_DecodingOptions_Release(ops);
       ops = nullptr;
       
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "CombinedDecode failed, errCode: %{public}d.", errCode);
           return GetJsResult(env, errCode);
       }
       OH_LOG_INFO(LOG_APP, "CombinedDecode succeeded.");
       return GetJsResult(env, errCode);
   }
   ```

## Precautions

- When setting both `cropRegion` and `desiredSize`, you are advised to set `cropAndScaleStrategy` to `IMAGE_CROP_AND_SCALE_STRATEGY_CROP_FIRST` to ensure consistent decoding results.

- For images whose original pixel memory exceeds 2 GB, you are advised to use downsampling to avoid memory overflow.