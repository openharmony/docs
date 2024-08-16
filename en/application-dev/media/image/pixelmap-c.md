# Using Image_NativeModule for PixelMap Operations

You can use the **Pixelmap** class to create a pixel map, obtain its width, height, pixel format, alpha type, and row stride, operate the pixel map, and release **Pixelmap** instances.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libpixelmap.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md).

Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example of Using the Pixelmap APIs**

Create a **Pixelmap** instance after parameter initialization, read and write pixel data, and perform operations such as scaling, translating, flipping, rotating, and cropping on the image.

   ```c++

      #include <linux/kd.h>
      #include <string>

      #include <hilog/log.h>
      #include <multimedia/image_framework/image/pixelmap_native.h>

      #undef LOG_DOMAIN
      #undef LOG_TAG
      #define LOG_DOMAIN 0x3200
      #define LOG_TAG "MY_TAG"

      Image_ErrorCode PixelmapTest()
      {
          uint8_t data[96];
          size_t dataSize = 96;
          for (int i = 0; i < dataSize; i++) {
              data[i] = i + 1;
          }

          // Create a parameter structure instance and set parameters.
          OH_Pixelmap_InitializationOptions *createOpts;
          OH_PixelmapInitializationOptions_Create(&createOpts);
          OH_PixelmapInitializationOptions_SetWidth(createOpts, 6);
          OH_PixelmapInitializationOptions_SetHeight(createOpts, 4);
          OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
          OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);

          // Create a Pixelmap instance.
          OH_PixelmapNative *pixelmap = nullptr;
          Image_ErrorCode errCode = OH_PixelmapNative_CreatePixelmap(data, dataSize, createOpts, &pixelmap);

          // Read the image pixel data and write the data to the array.
          uint8_t destination[96];
          size_t destinationSize = 96;
          errCode = OH_PixelmapNative_ReadPixels(pixelmap, destination, &destinationSize);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_ReadPixels failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Read the image data in the buffer and write the data to the Pixelmap instance.
          uint8_t source[96];
          size_t sourceSize = 96;
          for (int i = 0; i < sourceSize; i++) {
              source[i] = i + 1;
          }
          errCode = OH_PixelmapNative_WritePixels(pixelmap, source, sourceSize);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_WritePixels failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Create an image information instance and obtain the pixel information.
          OH_Pixelmap_ImageInfo *imageInfo;
          OH_PixelmapImageInfo_Create(&imageInfo);
          errCode = OH_PixelmapNative_GetImageInfo(pixelmap, imageInfo);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_GetImageInfo failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Obtain the width, height, pixel format, and alpha type of the image.
          uint32_t width, height, rowStride;
          int32_t pixelFormat, alphaType;
          OH_PixelmapImageInfo_GetWidth(imageInfo, &width);
          OH_PixelmapImageInfo_GetHeight(imageInfo, &height);
          OH_PixelmapImageInfo_GetRowStride(imageInfo, &rowStride);
          OH_PixelmapImageInfo_GetPixelFormat(imageInfo, &pixelFormat);
          OH_PixelmapImageInfo_GetAlphaType(imageInfo, &alphaType);
          OH_PixelmapImageInfo_Release(imageInfo);
          OH_LOG_INFO(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest GetImageInfo success, width: %{public}d, height: %{public}d, rowStride: %{public}d, pixelFormat: %{public}d, alphaType: %{public}d.", width, height, rowStride, pixelFormat, alphaType);

          // Set the opacity rate to enable the pixel map to achieve the corresponding opacity effect.
          errCode = OH_PixelmapNative_Opacity(pixelmap, 0.5);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Opacity failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Scale the image.
          errCode = OH_PixelmapNative_Scale(pixelmap, 2.0, 1.0);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Scale failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Translate the image.
          errCode = OH_PixelmapNative_Translate(pixelmap, 50.0, 10.0);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Translate failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Rotate the image.
          errCode = OH_PixelmapNative_Rotate(pixelmap, 90.0);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Rotate failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Flip the image.
          errCode = OH_PixelmapNative_Flip(pixelmap, true, true);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Flip failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Crop the image.
          Image_Region region;
          region.x = 100;
          region.y = 100;
          region.width = 6;
          region.height = 4;
          errCode = OH_PixelmapNative_Crop(pixelmap, &region);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Crop failed, errCode: %{public}d.", errCode);
              return errCode;
          }

          // Release the Pixelmap and InitializationOptions instances.
          OH_PixelmapNative_Release(pixelmap);
          OH_PixelmapInitializationOptions_Release(createOpts);
          return IMAGE_SUCCESS;
      }
   ```
