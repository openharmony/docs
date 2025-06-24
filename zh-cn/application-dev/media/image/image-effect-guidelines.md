# 使用ImageEffect编辑图片

## 场景介绍

ImageEffect提供了一系列接口用于图像的编辑。开发者可以通过`ImageEffect`接口处理不同图像输入类型`Pixelmap`、`NativeWindow`、`NativeBuffer`或`Uri`，获得滤镜处理效果。
针对ImageEffect，常见的开发场景如下：

- 通过`ImageEffect`提供的Native API接口添加滤镜或滤镜链，设置输入图像，最终生效滤镜效果。
- 通过注册自定义滤镜，实现开发者的定制化滤镜效果。
- 通过`EffectFilter`提供的Native API接口快速实现单个滤镜的处理效果。

## 接口说明

详细的接口说明请参考[ImageEffect](../../reference/apis-image-kit/capi-imageeffect.md)。

## 开发步骤

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
target_link_libraries(entry PUBLIC
    libace_ndk.z.so
    libimage_effect.so
    libpixelmap.so
    libnative_window.so
    libnative_buffer.so
)
```

根据处理的图像类型添加对应动态链接库：`Pixelmap`(libpixelmap.so)、`NativeWindow`(libnative_window.so)、`NativeBuffer`(libnative_buffer.so)

**添加头文件**

```c++
#include <multimedia/image_effect/image_effect.h>
#include <multimedia/image_effect/image_effect_filter.h>
#include <multimedia/image_effect/image_effect_errors.h>
```

### 通过ImageEffect提供的接口生效图像效果

1. 创建ImageEffect实例。

    ```c++
    // 创建imageEffect实例，“ImageEdit”是imageEffect实例别名。
    OH_ImageEffect *imageEffect = OH_ImageEffect_Create("ImageEdit");
    ```

2. 添加EffectFilter滤镜。

    ```c++
    // 添加滤镜，获取 OH_EffectFilter 实例。多次调用该接口可以添加多个滤镜，组成滤镜链。
    OH_EffectFilter *filter = OH_ImageEffect_AddFilter(imageEffect, OH_EFFECT_BRIGHTNESS_FILTER);
    CHECK_AND_RETURN_LOG(filter != nullptr, "OH_ImageEffect_AddFilter fail!");
    
    // 设置滤镜参数, 例如：滤镜强度设置为50。
    ImageEffect_Any value = { .dataType = ImageEffect_DataType::EFFECT_DATA_TYPE_FLOAT, .dataValue.floatValue = 50.f };
    ImageEffect_ErrorCode errorCode = OH_EffectFilter_SetValue(filter, OH_EFFECT_FILTER_INTENSITY_KEY, &value);
    ```

3. 设置处理数据。

    **场景一：设置OH_PixelmapNative输入类型。**

    OH_PixelmapNative的具体使用方法请参考[Pixelmap开发指导](image-pixelmap-operation-native.md)。

    ```c++
    // 设置输入的Pixelmap。
    errorCode = OH_ImageEffect_SetInputPixelmap(imageEffect, inputPixelmap);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetInputPixelmap fail!");
    
    // 设置输出的Pixelmap（可选），不调用该接口时会在输入Pixelmap上直接生效滤镜效果。
    errorCode = OH_ImageEffect_SetOutputPixelmap(imageEffect, outputPixelmap);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetOutputPixelmap fail!");
    ```

    **场景二：设置OH_NativeBuffer输入类型。**

    OH_NativeBuffer的具体使用方法请参考[NativeBuffer开发指导](../../graphics/native-buffer-guidelines.md)。

    ```c++
    // 设置输入的NativeBuffer。
    errorCode = OH_ImageEffect_SetInputNativeBuffer(imageEffect, inputNativeBuffer);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetInputNativeBuffer fail!");
    
    // 设置输出的NativeBuffer（可选），不调用该接口时会在输入NativeBuffer上直接生效滤镜效果。
    errorCode = OH_ImageEffect_SetOutputNativeBuffer(imageEffect, outputNativeBuffer);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetOutputNativeBuffer fail!");
    ```

    **场景三：设置URI输入类型。**

    ```c++
    // 设置输入的URI。
    errorCode = OH_ImageEffect_SetInputUri(imageEffect, inputUri);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetInputUri fail!");
    
    // 设置输出的URI（可选），不调用该接口时会在输入URI上直接生效滤镜效果。
    errorCode = OH_ImageEffect_SetOutputUri(imageEffect, outputUri);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetOutputUri fail!");
    ```
    **场景四：设置纹理输入类型。**

    纹理输入场景是使用硬件GPU渲染的高性能场景，此场景下，应用需要提供合法的OpenGL上下文环境，并在正确的环境下，设置参数以及进行渲染操作。
    ```c++
    // 设置输入的纹理ID。
    errorCode = OH_ImageEffect_SetInputTextureId(imageEffect, inputTex, ColorSpaceName::SRGB);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetInputTextureId fail!");

    // 设置输出的纹理ID, 注意不能与输入是同一块纹理，否则可能产生渲染异常。
    errorCode = OH_ImageEffect_SetOutputTextureId(imageEffect, outputTex);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetOutputTextureId fail!");
    ```

    **场景五：设置OHNativeWindow输入类型。**

    以相机预览场景为例来说明OHNativeWindow输入场景。XComponent组件为相机预览流提供的SurfaceId，可在native c++层将SurfaceId转换成OHNativeWindow，下面提供一份代码示例。
    XComponent模块的具体使用方法请参考[XComponent组件参考](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)。
    NativeWindow模块的具体使用方法请参考[OHNativeWindow](../../reference/apis-arkgraphics2d/capi-nativewindow.md)。
    Camera的具体使用方法请参考[Camera预览参考](../camera/native-camera-preview.md)。

    (1) 在xxx.ets中添加一个XComponent组件。

     ```ts
     XComponent({ 
         id: 'xcomponentId', 
         type: 'surface',
         controller: this.mXComponentController, 
         libraryname: 'entry'
     })
     .onLoad(() => {
         // 获取XComponent的SurfaceId。
         this.mSurfaceId = this.mXComponentController.getXComponentSurfaceId()
 
         // 调用native接口获取输入SurfaceId。
         this.mSurfaceId = imageEffect.getSurfaceId(this.mSurfaceId)
 
         // 调用相机接口启动预览，将获取到的输入SurfaceId传递给相机框架。
         // ...
     })
     .width('100%')
     .height('100%')
     ```

    (2) imageEffect.getSurfaceId的native c++层具体实现。

     ```c++
     // 根据SurfaceId创建NativeWindow，注意创建出来的NativeWindow在使用结束后需要主动调用OH_NativeWindow_DestoryNativeWindow进行释放。
     uint64_t outputSurfaceId;
     std::istrstream iss(outputSurfaceIdStr);
     issue >> outputSurfaceId;
     OHNativeWindow *outputNativeWindow = nullptr;
     int32_t res = OH_NativeWindow_CreateNativeWindowFromSurfaceId(outputSurfaceId, &outputNativeWindow);
     CHECK_AND_RETURN_LOG(res == 0, "OH_NativeWindow_CreateNativeWindowFromSurfaceId fail!");
     
     // 设置输出显示的Surface。
     ImageEffect_ErrorCode errorCode = OH_ImageEffect_SetOutputSurface(imageEffect, outputNativeWindow);
     CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_SetOutputSurface fail!");
     
     // 获取输入的Surface。注意获取的inputNativeWindow在使用结束后需要主动调用OH_NativeWindow_DestoryNativeWindow进行释放。
     OHNativeWindow *inputNativeWindow = nullptr;
     errorCode = OH_ImageEffect_GetInputSurface(imageEffect, &inputNativeWindow);
     CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_GetInputSurface fail!");
     
     // 从获取到输入的NativeWindow中获取SurfaceId。
     uint64_t inputSurfaceId = 0;
     res = OH_NativeWindow_GetSurfaceId(inputNativeWindow, &inputSurfaceId);
     CHECK_AND_RETURN_LOG(res == 0, "OH_NativeWindow_GetSurfaceId fail!");
     
     // 将SurfaceId转成字符串进行返回。
     std::string inputSurfaceIdStr = std::to_string(inputSurfaceId);
     ```

4. 启动效果器。

    ```c++
    // 执行生效滤镜效果。
    errorCode = OH_ImageEffect_Start(imageEffect);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_Start fail!");
    ```

5. 停止生效效果（可选，仅在输入Surface场景下才有效）。

    ```c++
    // 停止生效滤镜效果。
    errorCode = OH_ImageEffect_Stop(imageEffect);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_Stop fail!");
    ```

6. 序列化效果器（可选）。

    ```c++
    char *info = nullptr;
    errorCode = OH_ImageEffect_Save(imageEffect, &info);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_ImageEffect_Save fail!");
    ```

7. 销毁效果器实例。

    ```c++
    // 释放imageEffect实例资源。
    errorCode = OH_ImageEffect_Release(imageEffect);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, result, "OH_ImageEffect_Release fail!");
    ```

### 自定义滤镜

以下步骤描述了如何实现并注册自定义滤镜接口：

1. 定义 ImageEffect_FilterDelegate。

    ```c++
    // 图像信息结构体。
    struct EffectBufferInfo {
        void *addr = nullptr;
        int32_t width = 0;
        int32_t height = 0;
        int32_t rowSize = 0;
        ImageEffect_Format format = ImageEffect_Format::EFFECT_PIXEL_FORMAT_UNKNOWN;
    };

    // 自定义滤镜具体实现。
    ImageEffect_FilterDelegate filterDelegate = {
        .setValue = [](OH_EffectFilter *filter, const char *key, const ImageEffect_Any *value) {
            // 参数校验，校验成功时返回true，否则返回false。
            // ...
            return true;
        },
        .render = [](OH_EffectFilter *filter, OH_EffectBufferInfo *info, OH_EffectFilterDelegate_PushData pushData) {
            return Render(filter, info, pushData);
        },
        .save = [](OH_EffectFilter *filter, char **info) {
            // 获取自定义所设置的滤镜参数，其中"Brightness"为自定义滤镜的Key，由开发者自己任意指定。
            ImageEffect_Any value;
            ImageEffect_ErrorCode errorCode = OH_EffectFilter_GetValue(filter, "Brightness", &value);
            CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, false, "OH_EffectFilter_GetValue fail!");
            
            // 生成键值对信息。
            json values;
            values["Brightness"] = value.dataValue.floatValue;         
            json root;
            root["name"] = "CustomBrightness";
            root["values"] = values;
        
        　　 // 将json对象转成字符串infoStr。
            // ...

            // 对*info赋值序列化字符串地址。
            *info = infoStr;
            return true;
        },
        .restore = [](const char *info) {
            // 创建 OH_EffectFilter 实例，其中"CustomBrightness"为自定义滤镜的滤镜名。
            OH_EffectFilter *filter = OH_EffectFilter_Create("CustomBrightness");
            // 解析json字符串info获取key和value。
            // ...
        
            // 设置滤镜参数, value为info中按json解析出来的参数。
            ImageEffect_ErrorCode errorCode = OH_EffectFilter_SetValue(filter, "Brightness", &value);
            
            // ...
            return filter;
        }
    };
    ```

    其中Render接口的实现分两种场景。

    **场景一：自定义算法可以直接修改info中的像素数据（比如：亮度调节滤镜）。**

    ```c++
    bool Render(OH_EffectFilter *filter, OH_EffectBufferInfo *info, OH_EffectFilterDelegate_PushData pushData)
    {
        // 获取图像信息具体参数。
        EffectBufferInfo inputBufferInfo;
        OH_EffectBufferInfo_GetAddr(info, &inputBufferInfo.addr);
        OH_EffectBufferInfo_GetWidth(info, &inputBufferInfo.width);
        OH_EffectBufferInfo_GetHeight(info, &inputBufferInfo.height);
        OH_EffectBufferInfo_GetRowSize(info, &inputBufferInfo.rowSize);
        OH_EffectBufferInfo_GetEffectFormat(info, &inputBufferInfo.format);

        // 调用自定义滤镜算法。
        ApplyCustomAlgo(inputBufferInfo);

        // 编辑完成后调用pushData直接传递原图。
        pushData(filter, info);
        return true;
    }
    ```

    **场景二：自定义算法不能直接修改info中的像素数据（比如：裁剪滤镜）。**

    ```c++
    bool Render(OH_EffectFilter *filter, OH_EffectBufferInfo *info, OH_EffectFilterDelegate_PushData pushData)
    {
        // 获取图像信息具体参数。
        EffectBufferInfo inputBufferInfo;
        OH_EffectBufferInfo_GetAddr(info, &inputBufferInfo.addr);
        OH_EffectBufferInfo_GetWidth(info, &inputBufferInfo.width);
        OH_EffectBufferInfo_GetHeight(info, &inputBufferInfo.height);
        OH_EffectBufferInfo_GetRowSize(info, &inputBufferInfo.rowSize);
        OH_EffectBufferInfo_GetEffectFormat(info, &inputBufferInfo.format);

        // 创建输出像素信息。
        EffectBufferInfo outputBufferInfo = CreateOutputBufferInfo(inputBufferInfo);

        // 调用自定义滤镜算法。
        ApplyCustomAlgo(inputBufferInfo, outputBufferInfo);

        // 生成outputOhInfo。
        OH_EffectBufferInfo *outputOhInfo = OH_EffectBufferInfo_Create();
        OH_EffectBufferInfo_SetAddr(outputOhInfo, outputBufferInfo.addr);
        OH_EffectBufferInfo_SetWidth(outputOhInfo, outputBufferInfo.width);
        OH_EffectBufferInfo_SetHeight(outputOhInfo, outputBufferInfo.height);
        OH_EffectBufferInfo_SetRowSize(outputOhInfo, outputBufferInfo.rowSize);
        OH_EffectBufferInfo_SetEffectFormat(outputOhInfo, outputBufferInfo.format);

        // 编辑完成后调用pushData传递outputOhInfo。
        pushData(filter, outputOhInfo);

        // 释放资源。
        OH_EffectBufferInfo_Release(outputOhInfo);
        ReleaseOutputBuffer(outputBufferInfo.addr);

        return true;
    }
    ```

2. 生成自定义滤镜信息。

    ```c++
    // 创建 OH_EffectFilterInfo 实例。
    OH_EffectFilterInfo *customFilterInfo = OH_EffectFilterInfo_Create();
    CHECK_AND_RETURN_LOG(customFilterInfo != nullptr, "OH_EffectFilter_GetValue fail!");
    
    // 设置自定义滤镜滤镜名。
    OH_EffectFilterInfo_SetFilterName(customFilterInfo, "CustomBrightness");
    
    // 设置自定义滤镜所支持的内存类型。
    ImageEffect_BufferType bufferTypeArray[] = { ImageEffect_BufferType::EFFECT_BUFFER_TYPE_PIXEL };
    OH_EffectFilterInfo_SetSupportedBufferTypes(customFilterInfo, sizeof(bufferTypeArray) / sizeof(ImageEffect_BufferType), bufferTypeArray);
    
    // 设置自定义滤镜所支持的像素格式。
    ImageEffect_Format formatArray[] = { ImageEffect_Format::EFFECT_PIXEL_FORMAT_RGBA8888 };
    OH_EffectFilterInfo_SetSupportedFormats(customFilterInfo, sizeof(formatArray) / sizeof(ImageEffect_Format), formatArray);
    ```

3. 将 ImageEffect_FilterDelegate 注册到效果器。

    ```c++
    // 注册自定义滤镜。
    ImageEffect_ErrorCode errorCode = OH_EffectFilter_Register(customFilterInfo, &filterDelegate);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_EffectFilter_Register fail!");
    ```

### EffectFilter快速实现单个滤镜的处理效果

1. 创建滤镜。

    ```c++
    // 创建滤镜。比如：创建对比度效果器。
    OH_EffectFilter *filter = OH_EffectFilter_Create(OH_EFFECT_CONTRAST_FILTER);
    ```

2. 设置滤镜参数。

    ```c++
    // 设置滤镜参数, 滤镜强度设置为50。
    ImageEffect_Any value = {.dataType = ImageEffect_DataType::EFFECT_DATA_TYPE_FLOAT, .dataValue.floatValue = 50.f};
    ImageEffect_ErrorCode errorCode = OH_EffectFilter_SetValue(filter, OH_EFFECT_FILTER_INTENSITY_KEY, &value);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_EffectFilter_SetValue fail!");
    ```

3. 生效滤镜。

    ```c++
    // 生效滤镜效果。
    errorCode = OH_EffectFilter_Render(filter, inputPixelmap, outputPixelmap);
    ```

4. 销毁滤镜实例。

    ```c++
    // 销毁滤镜实例。
    errorCode = OH_EffectFilter_Release(filter);
    ```

### 查询能力

- 根据滤镜名查询滤镜信息。

    ```c++
    // 创建 OH_EffectFilterInfo 实例。
    OH_EffectFilterInfo *filterInfo = OH_EffectFilterInfo_Create();
    CHECK_AND_RETURN_LOG(filterInfo != nullptr, "OH_EffectFilterInfo_Create fail!");

    // 根据滤镜名查询滤镜能力信息。
    ImageEffect_ErrorCode errorCode = OH_EffectFilter_LookupFilterInfo(OH_EFFECT_BRIGHTNESS_FILTER, filterInfo);
    CHECK_AND_RETURN_LOG(errorCode == ImageEffect_ErrorCode::EFFECT_SUCCESS, "OH_EffectFilter_LookupFilterInfo fail!");

    // 从滤镜能力信息中获取滤镜名。
    char *name = nullptr;
    OH_EffectFilterInfo_GetFilterName(filterInfo, &name);

    // 获取支持的内存类型。
    uint32_t supportedBufferTypesCnt = 0;
    ImageEffect_BufferType *bufferTypeArray = nullptr;
    OH_EffectFilterInfo_GetSupportedBufferTypes(filterInfo, &supportedBufferTypesCnt, &bufferTypeArray);

    // 获取支持的像素类型信息。
    uint32_t supportedFormatsCnt = 0;
    ImageEffect_Format *formatArray = nullptr;
    OH_EffectFilterInfo_GetSupportedFormats(filterInfo, supportedFormatsCnt, &formatArray);

    // 销毁 OH_EffectFilterInfo 实例。
    OH_EffectFilterInfo_Release(filterInfo);
    ```

- 根据条件查询满足条件的滤镜。

    ```c++
    // 查询所有的Filter，需要主动进行资源释放。
    ImageEffect_FilterNames *filterNames = OH_EffectFilter_LookupFilters("Default");
    
    // ...
    
    // 释放FilterNames虚拟内存资源。
    OH_EffectFilter_ReleaseFilterNames();
    ```

## 相关实例

针对ImageEffect的开发，有以下相关实例可供参考：

- [ImageEffect（API12）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/ImageEffect)