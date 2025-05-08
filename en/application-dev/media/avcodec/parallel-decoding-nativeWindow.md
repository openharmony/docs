# Concurrently Creating a Video Decoder and Initializing NativeWindow

## When to Use

To ensure that a video decoder can be created and run properly in surface mode, you can create an empty surface before the **XComponent** is created or the OpenGL post-processing (NativeImage) is initialized.


## How to Develop

The following describes how to concurrently create a video decoder and initialize NativeWindow. This approach ensures that the video decoder can be set up and executed properly, even before the surface consumer is ready.

**Linking Dynamic Libraries**

``` cmake
target_link_libraries(sample PUBLIC libnative_image.so)
target_link_libraries(sample PUBLIC libnative_window.so)
target_link_libraries(sample PUBLIC libnative_buffer.so)
target_link_libraries(sample PUBLIC libnative_media_vdec.so)
```

> **NOTE**
>
> The word **sample** in the preceding code snippet is only an example. Use the actual project directory name.
>

**Including Header Files**

```c++
#include <iostream>
#include <string>
#include <native_image/native_image.h>
#include <native_window/external_window.h>
#include <native_buffer/native_buffer.h>
#include <multimedia/player_framework/native_avcodec_videodecoder.h>
```

1. Create an OH_NativeImage instance.
   
    ```c++
    // Create a NativeImage instance as the surface consumer.
    OH_NativeImage* image = OH_ConsumerSurface_Create();
    ```
   
2. Obtain the NativeWindow instance that functions as the producer.

    ```c++
    // Obtain a NativeWindow instance.
    OHNativeWindow* nativeImageWindow = OH_NativeImage_AcquireNativeWindow(image);
    ```

3. Set the width and height of the NativeWindow instance.

    ```c++
    int code = SET_BUFFER_GEOMETRY;
    int32_t width = 800;
    int32_t height = 600;
    int32_t ret = OH_NativeWindow_NativeWindowHandleOpt(nativeImageWindow, code, width, height);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

4. Register a callback function for the NativeImage instance.

    Register the **OH_OnFrameAvailableListener**, which contains the following parameters:

    - **context**: user-defined context information.
    - **onFrameAvailable**: callback function triggered when a frame is available.

    ```c++
    // Implement onFrameAvailable.
    static void onFrameAvailable()
    {
      OHNativeWindowBuffer *buffer = nullptr;
      int fenceFd;
      // Obtain an OHNativeWindowBuffer instance through the OH_NativeImage instance on the consumer side.
      OH_NativeImage_AcquireNativeWindowBuffer(image, &buffer, &fenceFd);
      // Release the OHNativeWindowBuffer instance through the OH_NativeImage instance.
      OH_NativeImage_ReleaseNativeWindowBuffer(image, &buffer, &fenceFd);
    }
    
    static void context()
    {
      // Customize the context information.
    }

    // Set a listener.
    OH_OnFrameAvailableListener listener = {&onFrameAvailable, &context};
    // Register the listener to listen for frame availability events.
    ret = OH_NativeImage_SetOnFrameAvailableListener(image, listener);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

    > **NOTE**
    >
    > In this example, the callback function just retrieves and releases the buffer. You can customize and expand the callback function based on service requirements.
    >

5. Configure the decoder.

    For details, see step 5 in [Video Decoding in Surface Mode](video-decoding.md#surface-output).

6. Set the surface.

    Before the actual surface consumer is created, you can use the temporarily created consumer to connect to the decoder.

    In the code snippet below, the following variables are used:
    - **videoDec**: pointer to the video decoder instance. For details, see step 2 in [Video Decoding Surface Mode](video-decoding.md#surface-output).

    ```c++

    ret = OH_VideoDecoder_SetSurface(videoDec, nativeImageWindow);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

7. Start the decoder.

    For details, see step 9 in [Video Decoding Surface Mode](video-decoding.md#surface-output).


8. Set the surface.

    After the actual surface consumer is created, call **OH_VideoDecoder_SetSurface** to redirect the decoded output to the new surface.

    You can obtain NativeWindow in either of the following ways:
    1. If the image is directly displayed after being decoded, obtain NativeWindow from the **XComponent**. For details about the operation, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).
    2. If OpenGL post-processing is performed after decoding, obtain NativeWindow from NativeImage. For details about the operation, see [NativeImage](../../graphics/native-image-guidelines.md).

    ```c++

    ret = OH_VideoDecoder_SetSurface(videoDec, nativeWindow);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

9. Destroy the OH_NativeImage instance.
   
   After calling **OH_VideoDecoder_Destroy**, call **OH_NativeImage_Destroy** to destroy the OH_NativeImage instance.
   ```c++
   // Destroy the OH_NativeImage instance.
   OH_NativeImage_Destroy(&image);
   ```
