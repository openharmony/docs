# Using ImageEffect to Edit Images
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyj208-->
<!--Designer: @wangshoucheng-->
<!--Tester: @gengfei-->
<!--Adviser: @w_Machine_cc-->

## When to Use

The **ImageEffect** class provides a series of APIs for editing images. You can use the **ImageEffect** APIs to process images of different input types, such as `Pixelmap`, `NativeWindow`, `NativeBuffer`, and `Uri`, to obtain filter effects.

Common development scenarios for **ImageEffect** are as follows:

- Add a filter or filter chain by using the native APIs provided by **ImageEffect**, set the input image, and apply the filter effect.
- Register a custom filter to implement a developer-defined filter effect.
- Use the native APIs provided by **EffectFilter** to quickly implement the processing effect of a single filter.

## **Available APIs**

For details about the APIs, see [ImageEffect](../../reference/apis-image-kit/capi-imageeffect.md).

## How to Develop

**Adding Dynamic Link Libraries**

Add the following libraries to `CMakeLists.txt`.

```txt
target_link_libraries(entry PUBLIC
    libace_ndk.z.so
    libimage_effect.so
    libpixelmap.so
    libnative_window.so
    libnative_buffer.so
)
```

Add the corresponding dynamic link library based on the processed image type: `Pixelmap` (`libpixelmap.so`), `NativeWindow` (`libnative_window.so`), or `NativeBuffer` (`libnative_buffer.so`).

**Adding Header Files**

```c++
#include <hilog/log.h>
#include <multimedia/image_effect/image_effect.h>
#include <multimedia/image_effect/image_effect_filter.h>
#include <multimedia/image_effect/image_effect_errors.h>
```

### Making an Image Effect Take Effect by Using ImageEffect APIs

1. Create an **ImageEffect** instance.

   ```c++
   // Create an ImageEffect instance, with the alias set to ImageEdit.
   OH_ImageEffect *imageEffect = OH_ImageEffect_Create("ImageEdit");
   ```

2. Add an **EffectFilter** filter.

   ```c++
   // Add a filter to obtain an OH_EffectFilter instance. You can call this API multiple times to add multiple filters to form a filter chain.
   OH_EffectFilter *filter = OH_ImageEffect_AddFilter(imageEffect, OH_EFFECT_BRIGHTNESS_FILTER);
   if (filter == nullptr) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_AddFilter fail!");
       return;
   }
   // Set a filter parameter. For example, set the intensity to 50.
   ImageEffect_Any value = { .dataType = ImageEffect_DataType::EFFECT_DATA_TYPE_FLOAT, .dataValue.floatValue = 50.f };
   ImageEffect_ErrorCode errorCode = OH_EffectFilter_SetValue(filter, OH_EFFECT_FILTER_INTENSITY_KEY, &value);
   ```

3. Set the data to be processed.

   **Scenario 1: Set the `OH_PixelmapNative` input type.**

   For details about how to use `OH_PixelmapNative`, see [PixelMap Data Processing (C/C++)](image-pixelmap-operation-native.md).

   ```c++
   // Set an input pixel map.
   errorCode = OH_ImageEffect_SetInputPixelmap(imageEffect, inputPixelmap);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetInputPixelmap fail!");
       return;
   }

   // Set an output pixel map (optional). If this API is not called, the filter effect directly takes effect on the input pixel map.
   errorCode = OH_ImageEffect_SetOutputPixelmap(imageEffect, outputPixelmap);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetOutputPixelmap fail!");
       return;
   }
   ```

   **Scenario 2: Set the `OH_NativeBuffer` input type.**

   For details about how to use `OH_NativeBuffer`, see [Native Buffer Development (C/C++)](../../graphics/native-buffer-guidelines.md).

   ```c++
   // Set an input native buffer.
   errorCode = OH_ImageEffect_SetInputNativeBuffer(imageEffect, inputNativeBuffer);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetInputNativeBuffer fail!");
       return;
   }

   // Set an output native buffer (optional). If this API is not called, the filter effect directly takes effect on the input native buffer.
   errorCode = OH_ImageEffect_SetOutputNativeBuffer(imageEffect, outputNativeBuffer);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetOutputNativeBuffer fail!");
       return;
   }
   ```

   **Scenario 3: Set the URI input type.**

   ```c++
   // Set an input URI.
   errorCode = OH_ImageEffect_SetInputUri(imageEffect, inputUri);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetInputUri fail!");
       return;
   }
   // Set an output URI (optional). If this API is not called, the filter effect directly takes effect on the input URI.
   errorCode = OH_ImageEffect_SetOutputUri(imageEffect, outputUri);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetOutputUri fail!");
       return;
   }
   ```

   **Scenario 4: Set the texture input type.**

   The texture input scenario is a high-performance scenario that uses the hardware GPU for rendering. In this scenario, the application needs to provide a valid OpenGL context and set parameters and perform rendering operations in the correct environment.

   ```c++
   // Set the input texture ID.
   errorCode = OH_ImageEffect_SetInputTextureId(imageEffect, inputTex, ColorSpaceName::SRGB);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetInputTextureId fail!");
       return;
   }

   // Set the output texture ID. Note that it cannot be the same texture as the input. Otherwise, rendering exceptions may occur.
   errorCode = OH_ImageEffect_SetOutputTextureId(imageEffect, outputTex);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetOutputTextureId fail!");
       return;
   }
   ```

   **Scenario 5: Set the `OHNativeWindow` input type.**

   The following uses camera preview as an example to describe the `OHNativeWindow` input scenario. The `SurfaceId` provided by the **XComponent** for camera preview streams can be converted into `OHNativeWindow` at the native C++ layer. A code example is provided below.

   For details about how to use the **XComponent** module, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

   For details about how to use the native window module, see [OHNativeWindow](../../reference/apis-arkgraphics2d/capi-nativewindow.md).

   For details about how to use the camera, see [Camera Preview (C/C++)](../camera/native-camera-preview.md).

   (1) Add an **XComponent** to `xxx.ets`.

   ```ts
   XComponent({
      id: 'xcomponentId',
      type: 'surface',
      controller: this.mXComponentController,
      libraryname: 'entry'
   })
   .onLoad(() => {
      // Obtain the SurfaceId of the XComponent.
      this.mSurfaceId = this.mXComponentController.getXComponentSurfaceId()

      // Call the native API to obtain the input SurfaceId.
      this.mSurfaceId = imageEffect.getSurfaceId(this.mSurfaceId)

      // Call the camera API to start preview and transfer the obtained input SurfaceId to the camera framework.
      // ...
   })
   .width('100%')
   .height('100%')
   ```

   (2) The following shows how **imageEffect.getSurfaceId** is implemented at the native C++ layer.

   ```c++
   // Create a NativeWindow based on the SurfaceId. Note that the created NativeWindow must be released by calling OH_NativeWindow_DestroyNativeWindow when it is no longer needed.
   uint64_t outputSurfaceId;
   std::istrstream iss(outputSurfaceIdStr);
   iss >> outputSurfaceId;
   OHNativeWindow *outputNativeWindow = nullptr;
   int32_t res = OH_NativeWindow_CreateNativeWindowFromSurfaceId(outputSurfaceId, &outputNativeWindow);
   if (res != 0) {
       OH_LOG_ERROR(LOG_APP, "OH_NativeWindow_CreateNativeWindowFromSurfaceId fail!");
       return;
   }

   // Set the output display surface.
   ImageEffect_ErrorCode errorCode = OH_ImageEffect_SetOutputSurface(imageEffect, outputNativeWindow);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_SetOutputSurface fail!");
       return;
   }
   // Obtain the input surface. Note that the obtained inputNativeWindow must be released by calling OH_NativeWindow_DestroyNativeWindow when it is no longer needed.
   OHNativeWindow *inputNativeWindow = nullptr;
   errorCode = OH_ImageEffect_GetInputSurface(imageEffect, &inputNativeWindow);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_GetInputSurface fail!");
       return;
   }

   // Obtain the SurfaceId from the input NativeWindow.
   uint64_t inputSurfaceId = 0;
   res = OH_NativeWindow_GetSurfaceId(inputNativeWindow, &inputSurfaceId);
   if (res != 0) {
       OH_LOG_ERROR(LOG_APP, "OH_NativeWindow_GetSurfaceId fail!");
       return;
   }

   // Convert the SurfaceId into a string and return it.
   std::string inputSurfaceIdStr = std::to_string(inputSurfaceId);
   ```

4. Start the image effector.

   ```c++
   // Start the image effector.
   errorCode = OH_ImageEffect_Start(imageEffect);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_Start fail!");
       return;
   }
   ```

5. Stop the image effect (optional, available only in the input surface scenario).

   ```c++
   // Stop the image effector.
   errorCode = OH_ImageEffect_Stop(imageEffect);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_Stop fail!");
       return;
   }
   ```

6. Serialize the image effector (optional).

   ```c++
   char *info = nullptr;
   errorCode = OH_ImageEffect_Save(imageEffect, &info);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_Save fail!");
       return;
   }
   ```

7. Destroy the image effector instance.

   ```c++
   // Release the ImageEffect instance.
   errorCode = OH_ImageEffect_Release(imageEffect);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_ImageEffect_Release fail!");
       return;
   }
   ```

### Customizing a Filter

The following steps describe how to implement and register a custom filter:

1. Define `ImageEffect_FilterDelegate`.

   ```c++
   // Image information struct.
   struct EffectBufferInfo {
       void *addr = nullptr;
       int32_t width = 0;
       int32_t height = 0;
       int32_t rowSize = 0;
       ImageEffect_Format format = ImageEffect_Format::EFFECT_PIXEL_FORMAT_UNKNOWN;
   };

   // Implement a custom filter.
   ImageEffect_FilterDelegate filterDelegate = {
       .setValue = [](OH_EffectFilter *filter, const char *key, const ImageEffect_Any *value) {
           // Verify the parameters. If the verification is successful, true is returned. Otherwise, false is returned.
           // ...
           return true;
       },
       .render = [](OH_EffectFilter *filter, OH_EffectBufferInfo *info, OH_EffectFilterDelegate_PushData pushData) {
           return Render(filter, info, pushData);
       },
       .save = [](OH_EffectFilter *filter, char **info) {
           // Obtain the custom filter parameter. In this example, "Brightness" is the key of the custom filter and can be specified by the developer.
           ImageEffect_Any value;
           ImageEffect_ErrorCode errorCode = OH_EffectFilter_GetValue(filter, "Brightness", &value);
           if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
               OH_LOG_ERROR(LOG_APP, "OH_EffectFilter_GetValue fail!");
               return false;
           }

           // Generate a key-value pair.
           json values;
           values["Brightness"] = value.dataValue.floatValue;
           json root;
           root["name"] = "CustomBrightness";
           root["values"] = values;

           // Convert the JSON object into the string infoStr.
           // ...

           // Assign the serialized string address to *info.
           *info = infoStr;
           return true;
       },
       .restore = [](const char *info) {
           // Create an OH_EffectFilter instance. In this example, "CustomBrightness" is the name of the custom filter.
           OH_EffectFilter *filter = OH_EffectFilter_Create("CustomBrightness");
           // Parse the JSON string info to obtain the key and value.
           // ...

           // Set a filter parameter. value is the parameter parsed from info as JSON.
           ImageEffect_ErrorCode errorCode = OH_EffectFilter_SetValue(filter, "Brightness", &value);

           // ...
           return filter;
       }
   };
   ```

   The **Render** API can be implemented in the following two scenarios.

   **Scenario 1: The custom algorithm can directly modify the pixel data in `info` (for example, the brightness adjustment filter).**

   ```c++
   bool Render(OH_EffectFilter *filter, OH_EffectBufferInfo *info, OH_EffectFilterDelegate_PushData pushData)
   {
       // Obtain image details.
       EffectBufferInfo inputBufferInfo;
       OH_EffectBufferInfo_GetAddr(info, &inputBufferInfo.addr);
       OH_EffectBufferInfo_GetWidth(info, &inputBufferInfo.width);
       OH_EffectBufferInfo_GetHeight(info, &inputBufferInfo.height);
       OH_EffectBufferInfo_GetRowSize(info, &inputBufferInfo.rowSize);
       OH_EffectBufferInfo_GetEffectFormat(info, &inputBufferInfo.format);

       // Call the custom filter algorithm.
       ApplyCustomAlgo(inputBufferInfo);

       // After editing is complete, call pushData to directly pass the original image.
       pushData(filter, info);
       return true;
   }
   ```

   **Scenario 2: The custom algorithm cannot directly modify the pixel data in `info` (for example, the crop filter).**

   ```c++
   bool Render(OH_EffectFilter *filter, OH_EffectBufferInfo *info, OH_EffectFilterDelegate_PushData pushData)
   {
       // Obtain image details.
       EffectBufferInfo inputBufferInfo;
       OH_EffectBufferInfo_GetAddr(info, &inputBufferInfo.addr);
       OH_EffectBufferInfo_GetWidth(info, &inputBufferInfo.width);
       OH_EffectBufferInfo_GetHeight(info, &inputBufferInfo.height);
       OH_EffectBufferInfo_GetRowSize(info, &inputBufferInfo.rowSize);
       OH_EffectBufferInfo_GetEffectFormat(info, &inputBufferInfo.format);

       // Create output pixel information.
       EffectBufferInfo outputBufferInfo = CreateOutputBufferInfo(inputBufferInfo);

       // Call the custom filter algorithm.
       ApplyCustomAlgo(inputBufferInfo, outputBufferInfo);

       // Generate outputOhInfo.
       OH_EffectBufferInfo *outputOhInfo = OH_EffectBufferInfo_Create();
       OH_EffectBufferInfo_SetAddr(outputOhInfo, outputBufferInfo.addr);
       OH_EffectBufferInfo_SetWidth(outputOhInfo, outputBufferInfo.width);
       OH_EffectBufferInfo_SetHeight(outputOhInfo, outputBufferInfo.height);
       OH_EffectBufferInfo_SetRowSize(outputOhInfo, outputBufferInfo.rowSize);
       OH_EffectBufferInfo_SetEffectFormat(outputOhInfo, outputBufferInfo.format);

       // After editing is complete, call pushData to pass outputOhInfo.
       pushData(filter, outputOhInfo);

       // Release resources.
       OH_EffectBufferInfo_Release(outputOhInfo);
       ReleaseOutputBuffer(outputBufferInfo.addr);

       return true;
   }
   ```

2. Generate custom filter information.

   ```c++
   // Create an OH_EffectFilterInfo instance.
   OH_EffectFilterInfo *customFilterInfo = OH_EffectFilterInfo_Create();
   if (customFilterInfo ==nullptr) {
       OH_LOG_ERROR(LOG_APP, "OH_EffectFilter_GetValue fail!");
       return;
   }

   // Set the custom filter name.
   OH_EffectFilterInfo_SetFilterName(customFilterInfo, "CustomBrightness");

   // Set the memory types supported by the custom filter.
   ImageEffect_BufferType bufferTypeArray[] = { ImageEffect_BufferType::EFFECT_BUFFER_TYPE_PIXEL };
   OH_EffectFilterInfo_SetSupportedBufferTypes(customFilterInfo, sizeof(bufferTypeArray) / sizeof(ImageEffect_BufferType), bufferTypeArray);

   // Set the pixel formats supported by the custom filter.
   ImageEffect_Format formatArray[] = { ImageEffect_Format::EFFECT_PIXEL_FORMAT_RGBA8888 };
   OH_EffectFilterInfo_SetSupportedFormats(customFilterInfo, sizeof(formatArray) / sizeof(ImageEffect_Format), formatArray);
   ```

3. Register `ImageEffect_FilterDelegate` with the image effector.

   ```c++
   // Register the custom filter.
   ImageEffect_ErrorCode errorCode = OH_EffectFilter_Register(customFilterInfo, &filterDelegate);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_EffectFilter_Register fail!");
       return;
   }
   ```

### Using EffectFilter to Quickly Implement the Processing Effect of a Single Filter

1. Create a filter.

   ```c++
   // Create a filter. For example, create a contrast effector.
   OH_EffectFilter *filter = OH_EffectFilter_Create(OH_EFFECT_CONTRAST_FILTER);
   ```

2. Set a filter parameter.

   ```c++
   // Set a filter parameter. For example, set the intensity to 50.
   ImageEffect_Any value = {.dataType = ImageEffect_DataType::EFFECT_DATA_TYPE_FLOAT, .dataValue.floatValue = 50.f};
   ImageEffect_ErrorCode errorCode = OH_EffectFilter_SetValue(filter, OH_EFFECT_FILTER_INTENSITY_KEY, &value);
   if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
       OH_LOG_ERROR(LOG_APP, "OH_EffectFilter_SetValue fail!");
       return;
   }
   ```

3. Make the filter take effect.

   ```c++
   // Make the filter take effect.
   errorCode = OH_EffectFilter_Render(filter, inputPixelmap, outputPixelmap);
   ```

4. Destroy the filter instance.

   ```c++
   // Destroy the filter instance.
   errorCode = OH_EffectFilter_Release(filter);
   ```

### Querying Capabilities

- Query filter information based on the filter name.

  ```c++
  // Create an OH_EffectFilterInfo instance.
  OH_EffectFilterInfo *filterInfo = OH_EffectFilterInfo_Create();
  if (filterInfo == nullptr) {
      OH_LOG_ERROR(LOG_APP, "OH_EffectFilterInfo_Create fail!");
      return;
  }

  // Query filter capability information based on the filter name.
  ImageEffect_ErrorCode errorCode = OH_EffectFilter_LookupFilterInfo(OH_EFFECT_BRIGHTNESS_FILTER, filterInfo);
  if (errorCode != ImageEffect_ErrorCode::EFFECT_SUCCESS) {
      OH_LOG_ERROR(LOG_APP, "OH_EffectFilter_LookupFilterInfo fail!");
      return;
  }

  // Obtain the filter name from the filter capability information.
  char *name = nullptr;
  OH_EffectFilterInfo_GetFilterName(filterInfo, &name);

  // Obtain the supported memory types.
  uint32_t supportedBufferTypesCnt = 0;
  ImageEffect_BufferType *bufferTypeArray = nullptr;
  OH_EffectFilterInfo_GetSupportedBufferTypes(filterInfo, &supportedBufferTypesCnt, &bufferTypeArray);

  // Obtain the supported pixel format information.
  uint32_t supportedFormatsCnt = 0;
  ImageEffect_Format *formatArray = nullptr;
  OH_EffectFilterInfo_GetSupportedFormats(filterInfo, &supportedFormatsCnt, &formatArray);

  // Destroy the OH_EffectFilterInfo instance.
  OH_EffectFilterInfo_Release(filterInfo);
  ```

- Query filters that meet given conditions.

  ```c++
  // Query all filters. The resources need to be actively released.
  ImageEffect_FilterNames *filterNames = OH_EffectFilter_LookupFilters("Default");

  // ...

  // Release the virtual memory resources occupied by FilterNames.
  OH_EffectFilter_ReleaseFilterNames();
  ```

## Samples

The following sample is available for ImageEffect development:

- [ImageEffect (API12)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/ImageEffect)
