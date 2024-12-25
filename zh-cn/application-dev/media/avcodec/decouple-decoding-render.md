# 解耦视频解码与渲染

## 场景介绍

解码Surface模式的正常运行，依赖一片surface进行buffer轮转。但由于应用的业务原因，导致在调用OH_VideoDecoder_SetSurface()时，
还没有已准备好的OHNativeWindow。这种场景，可以建立一片ConsumerSurface，作为OH_VideoDecoder_SetSurface()的入参，保证视频解码器正常创建运行。


## 开发步骤

以下步骤描述了在surface的texture没有创建之前，如何让视频解码器正常创建执行。

**添加动态链接库**

``` cmake
target_link_libraries(sample PUBLIC libnative_image.so)
target_link_libraries(sample PUBLIC libnative_window.so)
target_link_libraries(sample PUBLIC libnative_buffer.so)
target_link_libraries(sample PUBLIC libnative_media_vdec.so)
```

> **说明：**
>
> 上述'sample'字样仅为示例，此处由调用者根据实际工程目录自定义。
>

**头文件**

```c++
#include <iostream>
#include <string>
#include <native_image/native_image.h>
#include <native_window/external_window.h>
#include <native_buffer/native_buffer.h>
#include <multimedia/player_framework/native_avcodec_videodecoder.h>
```

1. **创建OH_NativeImage实例**。
   
    ```c++
    // 创建 NativeImage 实例，作为surface的消费者
    OH_NativeImage* image = OH_ConsumerSurface_Create();
    ```
   
2. **获取对应的数据生产者端NativeWindow**。

    ```c++
    // 获取生产者NativeWindow
    OHNativeWindow* nativeImageWindow = OH_NativeImage_AcquireNativeWindow(image);
    ```

3. **设置NativeWindow的宽高**。

    ```c++
    int code = SET_BUFFER_GEOMETRY;
    int32_t width = 800;
    int32_t height = 600;
    int32_t ret = OH_NativeWindow_NativeWindowHandleOpt(nativeImageWindow, code, width, height);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

4. **注册NativeImage的回调函数**。

    注册OH_NativeImage的监听者OH_OnFrameAvailableListener，包括：

    - context 用户自定义的上下文信息；
    - onFrameAvailable 有buffer可获取触发时的回调函数。

    ```c++
    // onFrameAvailable实现
    static void onFrameAvailable()
    {
      OHNativeWindowBuffer *buffer = nullptr;
      int fenceFd;
      // 通过消费端的OH_NativeImage获取一个OHNativeWindowBuffer
      OH_NativeImage_AcquireNativeWindowBuffer(image, &buffer, &fenceFd);
      // 通过OH_NativeImage实例将OHNativeWindowBuffer归还到buffer队列中
      OH_NativeImage_ReleaseNativeWindowBuffer(image, &buffer, &fenceFd);
    }
    
    static void context()
    {
      // 调用者自定义的上下文信息
    }

    // 设置回调监听者
    OH_OnFrameAvailableListener listener = {&onFrameAvailable, &context};
    // 设置帧可用回调
    ret = OH_NativeImage_SetOnFrameAvailableListener(image, listener);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

    > **说明：**
    >
    > 在此示例中，回调函数的实现仅仅是将buffer取出来并释放，调用者可以根据业务需求自行拓展。
    >

5. **配置解码器**。

    具体开发指导请参考[视频解码Surface模式](video-decoding.md#surface模式)“步骤-5：调用OH_VideoDecoder_Configure()配置解码器”。

6. **设置surface**。

    在应用业务相关的surface的texture创建成功之前，可以先使用消费者NativeImage作为临时输出的surface

    示例中的变量说明如下：
    - videoDec：视频解码器实例的指针。创建方式可参考[视频解码Surface模式](video-decoding.md#surface模式)“步骤-2：创建解码器实例对象”。

    ```c++

    int32_t ret = OH_VideoDecoder_SetSurface(videoDec, nativeImageWindow);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

7. **启动解码器**。

    具体开发指导请参考[视频解码Surface模式](video-decoding.md#surface模式)“步骤-9：调用OH_VideoDecoder_Start()启动解码器”。


8. **设置surface**。

    在应用业务的surface的texture创建完毕后，可以调用OH_VideoDecoder_SetSurface接口，将解码输出重定向到新的surface上。

    本例中的nativeWindow，有两种方式获取：
    1. 如果解码后直接显示，则从XComponent组件获取，获取方式请参考 [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)；
    2. 如果解码后接OpenGL后处理，则从NativeImage获取，获取方式请参考 [NativeImage](../../graphics/native-image-guidelines.md)。

    ```c++

    int32_t ret = OH_VideoDecoder_SetSurface(videoDec, nativeWindow);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

9. **销毁OH_NativeImage实例**。
   
   在调用OH_VideoDecoder_Destroy接口后，调用OH_NativeImage_Destroy接口销毁OH_NativeImage实例
   ```c++
   // 销毁OH_NativeImage实例
   OH_NativeImage_Destroy(&image);
   ```