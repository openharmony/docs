# Video Decoding

You can call the native APIs provided by the VideoDecoder module to decode video, that is, to decode media data into a YUV file or render it.

Currently, the following decoding capabilities are supported:

| Video Hardware Decoding Type      | Video Software Decoding Type  |
| --------------------- | ---------------- |
| AVC (H.264) and HEVC (H.265)|AVC (H.264) |

Video software decoding and hardware decoding are different. When a decoder is created based on the MIME type, only H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) is supported for software decoding, and H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) and H.265 (OH_AVCODEC_MIMETYPE_VIDEO_HEVC) are supported for hardware decoding.

## Surface Output and Buffer Output

Surface output and buffer output differ in data output modes.

Surface output indicates that the OHNativeWindow is used to transfer output data. It supports connection with other modules, such as the **\<XComponent>**.

Buffer output indicates that decoded data is output in shared memory mode.

The two also differ slightly in the API calling modes:

- In surface mode, an application can choose to call **OH_VideoDecoder_FreeOutputBuffer()** to free the output buffer (without rendering the data). In buffer mode, an application must call **OH_VideoDecoder_FreeOutputBuffer()** to free the output buffer.
- In surface mode, an application must call **OH_VideoDecoder_SetSurface()** to set an OHNativeWindow before the decoder is ready and call **OH_VideoDecoder_RenderOutputBuffer()** to render the decoded data after the decoder is started.
- In buffer mode, an application can obtain the shared memory address and data from the output buffer. In surface mode, an application can obtain the data from the output buffer.

For details about the development procedure, see [Surface Output](#surface-output) and [Buffer Output](#buffer-output).

## How to Develop

Read [VideoDecoder](../../reference/apis-avcodec-kit/_video_decoder.md) for the API reference.

The figure below shows the call relationship of video decoding.

![Call relationship of video decoding](figures/video-decode.png)

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_vdec.so)
```

### Surface Output

The following walks you through how to implement the entire video decoding process in surface mode. In this example, an H.264 stream file is input, decoded, and rendered.

Currently, the VideoDecoder module supports only data rotation in asynchronous mode.

1. Add the header files.

    ```c++
    #include <multimedia/player_framework/native_avcodec_videodecoder.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    #include <multimedia/player_framework/native_avbuffer.h>
    #include <fstream>
    ```

2. Create a decoder instance.

    You can create a decoder by name or MIME type. In the code snippet below, the following variables are used:

    - **videoDec**: pointer to the video decoder instance.
    - **capability**: pointer to the decoder's capability.
    - **OH_AVCODEC_MIMETYPE_VIDEO_AVC**: name of an AVC video stream.

    ```c++
    // To create a decoder by name, call OH_AVCapability_GetName to obtain the codec names available and then call OH_VideoDecoder_CreateByName. If your application has special requirements, for example, expecting a decoder that supports a certain resolution, you can call OH_AVCodec_GetCapability to query the capability first.
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(name);
    ```

    ```c++
    // Create a decoder by MIME type.
    // Create an H.264 decoder for software/hardware decoding. The system creates the most appropriate decoder if multiple decoders are available.
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
    // Create an H.265 decoder for hardware decoding.
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_HEVC);
    ```

3. Call **OH_VideoDecoder_RegisterCallback()** to register the callback functions.

    > **NOTE**
    >
    > In the callback functions, pay attention to multi-thread synchronization for operations on the data queue.
    >

    Register the **OH_AVCodecCallback** struct that defines the following callback function pointers:

    - **OH_AVCodecOnError**, a callback used to report a codec operation error.
    - **OH_AVCodecOnStreamChanged**, a callback used to report a codec stream change, for example, stream width or height change.
    - **OH_AVCodecOnNeedInputBuffer**, a callback used to report input data required, which means that the decoder is ready for receiving data.
    - **OH_AVCodecOnNewOutputBuffer**, a callback used to report output data generated, which means that decoding is complete. (Note: The **buffer** parameter in the callback function is empty in surface mode.)

    You need to process the callback functions to ensure that the decoder runs properly.

    ```c++
    // Implement the OH_AVCodecOnError callback function.
    static void OnError(OH_AVCodec *codec, int32_t errorCode, void *userData)
    {
        // You need to process the error code in the callback.
        (void)codec;
        (void)errorCode;
        (void)userData;
    }

    // Implement the OH_AVCodecOnStreamChanged callback function.
    static void OnStreamChanged(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
    {
        // The changed video width, height, and stride can be obtained through format.
        (void)codec;
        (void)format;
        (void)userData;
    }

    // Implement the OH_AVCodecOnNeedInputBuffer callback function.
    static void OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        // The index of the input frame buffer is sent to InIndexQueue.
        // The input frame data (specified by buffer) is sent to InBufferQueue.
        // Perform data processing. For details, see
        // - Write the stream to decode.
    }

    // Implement the OH_AVCodecOnNewOutputBuffer callback function.
    static void OnNewOutputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        // The index of the output frame buffer is sent to outIndexQueue.
        // The output frame data (specified by buffer) is sent to outBufferQueue.
        // Perform data processing. For details, see
        // - Display and release decoded frames.
    }
    // Call OH_VideoDecoder_RegisterCallback() to register the callback functions.
    OH_AVCodecCallback cb = {&OnError, &OnStreamChanged, &OnNeedInputBuffer, &OnNewOutputBuffer};
    // Set the asynchronous callbacks.
    int32_t ret = OH_VideoDecoder_RegisterCallback(videoDec, cb, NULL);
    ```

4. Call **OH_VideoDecoder_Configure()** to configure the decoder.

    For details about the configurable options, see [Video Dedicated Key-Value Paris](../../reference/apis-avcodec-kit/_codec_base.md#media-data-key-value-pairs).

    Currently, the following options must be configured for all supported formats: video frame width and height. In the code snippet below, the following variables are used:

    - **DEFAULT_WIDTH**: 320 pixels
    - **DEFAULT_HEIGHT**: 240 pixels
    - **DEFAULT_PIXELFORMAT**: **AV_PIXEL_FORMAT_NV12** (the color format of the YUV file is NV12)

    ```c++
    // (Mandatory) Configure the video frame width.
    constexpr int32_t DEFAULT_WIDTH = 320; 
    // (Mandatory) Configure the video frame height.
    constexpr int32_t DEFAULT_HEIGHT = 240;
    // (Mandatory) Configure the video color format.
    constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;

    OH_AVFormat *format = OH_AVFormat_Create();
    // Set the format.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, DEFAULT_WIDTH);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, DEFAULT_HEIGHT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, DEFAULT_PIXELFORMAT);
    // Configure the decoder.
    int32_t ret = OH_VideoDecoder_Configure(videoDec, format);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    OH_AVFormat_Destroy(format);
    ```

5. Set the surface. The application obtains the native window from the **\<XComponent>**. For details about the process, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

    You perform this step during decoding, that is, dynamically switch the surface.

    ```c++
    // Set the window parameters.
    int32_t ret = OH_VideoDecoder_SetSurface(videoDec, window); // Obtain the window from the <XComponent>.
    ```

6. (Optional) Call **OH_VideoDecoder_SetParameter()** to set the surface parameters of the decoder.
    For details about the configurable options, see [Video Dedicated Key-Value Paris](../../reference/apis-avcodec-kit/_codec_base.md#media-data-key-value-pairs).

    ```c++
    OH_AVFormat *format = OH_AVFormat_Create();
    // Configure the display rotation angle.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_ROTATION, 90);
    // Configure the matching mode (scaling or cropping) between the video and the screen.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_SCALING_MODE, SCALING_MODE_SCALE_CROP);
    int32_t ret = OH_VideoDecoder_SetParameter(videoDec, format);
    OH_AVFormat_Destroy(format);
    ```
7. (Optional) Call **OH_VideoDecoder_SetDecryptionConfig** to set the decryption configuration. Call this API after the media key system information is obtained but before **Prepare()** is called. For details about how to obtain such information, see step 3 in [Audio and Video Demuxing](audio-video-demuxer.md). For details about DRM APIs, see [DRM](../../reference/apis-drm-kit/_drm.md).  

    Add the header files.

    ```c++
    #include <multimedia/drm_framework/native_mediakeysystem.h>
    #include <multimedia/drm_framework/native_mediakeysession.h>
    #include <multimedia/drm_framework/native_drm_err.h>
    #include <multimedia/drm_framework/native_drm_common.h>
    ```
    Link the dynamic library in the CMake script.

    ``` cmake
    target_link_libraries(sample PUBLIC libnative_drm.so)
    ```

    The following is the sample code:
    ```c++
    // Create a media key system based on the media key system information. The following uses com.clearplay.drm as an example.
    MediaKeySystem *system = nullptr;
    int32_t ret = OH_MediaKeySystem_Create("com.clearplay.drm", &system);
    if (system == nullptr) {
        printf("create media key system failed");
        return;
    }
    // Perform authentication via the provisioning server.
    // Create a media key session.
    MediaKeySession *session = nullptr;
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO;
    ret = OH_MediaKeySystem_CreateMediaKeySession(system, &contentProtectionLevel, &session);
    if (session == nullptr) {
        printf("create media key session failed");
        return;
    }
    // Generate a media key request and set the response to the media key request.
    // Set the decryption configuration, that is, set the decryption session and secure video channel flag to the decoder.
    bool secureVideoPath = false;
    ret = OH_VideoDecoder_SetDecryptionConfig(videoDec, session, secureVideoPath);
    ```

8. Call **OH_VideoDecoder_Prepare()** to prepare internal resources for the decoder.

     

    ```c++
    ret = OH_VideoDecoder_Prepare(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

9. Call **OH_VideoDecoder_Start()** to start the decoder.

    ```c++
    std::string_view inputFilePath = "/*yourpath*.h264";
    std::unique_ptr<std::ifstream> inputFile = std::make_unique<std::ifstream>();
    inputFile->open(inputFilePath.data(), std::ios::in | std::ios::binary); 
    // Start the decoder.
    int32_t ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

10. Call **OH_VideoDecoder_PushInputBuffer()** to push the stream to the input buffer for decoding.

    In the code snippet below, the following variables are used:

    - **buffer**: parameter passed in by the callback function **OnNeedInputBuffer**. You can call **OH_AVBuffer_GetAddr()** to obtain the pointer to the shared memory address.
    - **index**: index of the data queue, which is passed in by the callback function **OnNeedInputBuffer**.
    - **size**, **offset**, and **pts**: size, offset, and timestamp. For details about how to obtain the information, see [Audio and Video Demuxing](./audio-video-demuxer.md).
    - **flags**: type of the buffer flag. For details, see [OH_AVCodecBufferFlags](../../reference/apis-avcodec-kit/_core.md#oh_avcodecbufferflags).

    ```c++
    // Configure the size, offset, and timestamp of the frame data.
    OH_AVCodecBufferAttr info;
    info.size = size;
    info.offset = offset;
    info.pts = pts;
    info.flags = flags;
    // Write information to the buffer.
    int32_t ret = OH_AVBuffer_SetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Send the data to the input buffer for decoding. index is the index of the buffer.
    ret = OH_VideoDecoder_PushInputBuffer(videoDec, index);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

11. Call **OH_VideoDecoder_RenderOutputBuffer()** to render the data and free the output buffer, or call **OH_VideoDecoder_FreeOutputBuffer()** to directly free the output buffer.
    
    In the code snippet below, the following variables are used:

    - **index**: index of the data queue, which is passed in by the callback function **OnNewOutputBuffer**.
    - **buffer**: parameter passed in by the callback function **OnNewOutputBuffer**. You can call **OH_AVBuffer_GetAddr()** to obtain the pointer to the shared memory address.

    ```c++
    // Obtain the decoded information.
    OH_AVCodecBufferAttr info;
    int32_t ret = OH_AVBuffer_GetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // The value is determined by the caller.
    bool isRender;
    if (isRender) {
        // Render the data and free the output buffer. index is the index of the buffer.
        ret = OH_VideoDecoder_RenderOutputBuffer(videoDec, index);
    } else {
        // Free the output buffer.
        ret = OH_VideoDecoder_FreeOutputBuffer(videoDec, index);
    }
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

12. (Optional) Call **OH_VideoDecoder_Flush()** to refresh the decoder.

    > **NOTE**
    >
    > After **OH_VideoDecoder_Flush()** and **OH_VideoDecoder_Start()** are called, the XPS must be transferred again.
    >

    After **OH_VideoDecoder_Flush()** is called, the decoder remains in the running state, but the current queue is cleared and the buffer storing the decoded data is freed.

    To continue decoding, you must call **OH_VideoDecoder_Start()** again.

    ```c++
    // Refresh the decoder.
    int32_t ret = OH_VideoDecoder_Flush(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Start decoding again.
    ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

13. (Optional) Call **OH_VideoDecoder_Reset()** to reset the decoder.

    After **OH_VideoDecoder_Reset()** is called, the decoder returns to the initialized state. To continue decoding, you must call **OH_VideoDecoder_Configure()** and then **OH_VideoDecoder_SetSurface()**.

    ```c++
    // Reset the decoder.
    int32_t ret = OH_VideoDecoder_Reset(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Reconfigure the decoder.
    ret = OH_VideoDecoder_Configure(videoDec, format);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Reconfigure the surface in surface mode. This is not required in buffer mode.
    ret = OH_VideoDecoder_SetSurface(videoDec, window);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

14. (Optional) Call **OH_VideoDecoder_Stop()** to stop the decoder.

    ```c++
    // Stop the decoder.
    int32_t ret = OH_VideoDecoder_Stop(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

15. Call **OH_VideoDecoder_Destroy()** to destroy the decoder instance and release resources.

    > **NOTE**
    >
    > This API cannot be called in the callback function.
    > After the call, you must set a null pointer to the decoder to prevent program errors caused by wild pointers.
    >

    ```c++
    // Call OH_VideoDecoder_Destroy to destroy the decoder.
    int32_t ret = OH_VideoDecoder_Destroy(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

### Buffer Output

The following walks you through how to implement the entire video decoding process in buffer mode. In this example, an H.264 file is input and decoded into a YUV file.
Currently, the VideoDecoder module supports only data rotation in asynchronous mode.

1. Add the header files.

    ```c++
    #include <multimedia/player_framework/native_avcodec_videodecoder.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    #include <multimedia/player_framework/native_avbuffer.h>
    #include <native_buffer/native_buffer.h>
    #include <fstream>
    ```

2. Create a decoder instance.

    The procedure is the same as that in surface mode and is not described here.

    ```c++
    // To create a decoder by name, call OH_AVCapability_GetName to obtain the codec names available and then call OH_VideoDecoder_CreateByName. If your application has special requirements, for example, expecting a decoder that supports a certain resolution, you can call OH_AVCodec_GetCapability to query the capability first.
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(name);
    ```

    ```c++
    // Create a decoder by MIME type.
    // Create an H.264 decoder for software/hardware decoding. The system creates the most appropriate decoder if multiple decoders are available.
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
    // Create an H.265 decoder for hardware decoding.
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_HEVC);
    ```

3. Call **OH_VideoDecoder_RegisterCallback()** to register the callback functions.

    > **NOTE**
    >
    > In the callback functions, pay attention to multi-thread synchronization for operations on the data queue.
    >

    Register the **OH_AVCodecCallback** struct that defines the following callback function pointers:

    - **OH_AVCodecOnError**, a callback used to report a codec operation error.
    - **OH_AVCodecOnStreamChanged**, a callback used to report a codec stream change, for example, stream width or height change.
    - **OH_AVCodecOnNeedInputBuffer**, a callback used to report input data required, which means that the decoder is ready for receiving data.
    - **OH_AVCodecOnNewOutputBuffer**, a callback used to report output data generated, which means that decoding is complete.

    You need to process the callback functions to ensure that the decoder runs properly.

    ```c++
    int32_t width = 0;
    int32_t height = 0;
    int32_t widthStride = 0;
    int32_t heightStride = 0;
    int32_t cropTop = 0;
    int32_t cropBottom = 0;
    int32_t cropLeft = 0;
    int32_t cropRight = 0;
    bool isFirstFrame = true;
    // Implement the OH_AVCodecOnError callback function.
    static void OnError(OH_AVCodec *codec, int32_t errorCode, void *userData)
    {
        // You need to process the error code in the callback.
        (void)codec;
        (void)errorCode;
        (void)userData;
    }
    
    // Implement the OH_AVCodecOnStreamChanged callback function.
    static void OnStreamChanged(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
    {
        // The changed video width, height, and stride can be obtained through format.
        (void)codec;
        (void)userData;
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_WIDTH, width);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_HEIGHT, height);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_STRIDE, widthStride);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_SLICE_HEIGHT, heightStride);
        // (Optional) Obtain the cropped rectangle information.
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_TOP, cropTop);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_BOTTOM, cropBottom);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_LEFT, cropLeft);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_RIGHT, cropRight);
    }
    
    // Implement the OH_AVCodecOnNeedInputBuffer callback function.
    static void OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        // The index of the input frame buffer is sent to InIndexQueue.
        // The input frame data (specified by buffer) is sent to InBufferQueue.
        // Perform data processing. For details, see
        // - Write the stream to decode.
    }
    
    // Implement the OH_AVCodecOnNewOutputBuffer callback function.
    static void OnNewOutputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        // The index of the output frame buffer is sent to outIndexQueue.
        // The output frame data (specified by buffer) is sent to outBufferQueue.
        // Obtain the video width, height, and stride.
        if (isFirstFrame) {
            OH_AVFormat *format = OH_VideoDecoder_GetOutputDescription(codec);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_WIDTH, width);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_HEIGHT, height);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_STRIDE, widthStride);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_SLICE_HEIGHT, heightStride);
            // (Optional) Obtain the cropped rectangle information.
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_TOP, cropTop);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_BOTTOM, cropBottom);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_LEFT, cropLeft);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_RIGHT, cropRight);
            OH_AVFormat_Destroy(format);
            isFirstFrame = false;
        }
        // Perform data processing. For details, see
        // - Release the decoded frame.
    }
    // Call OH_VideoDecoder_RegisterCallback() to register the callback functions.
    OH_AVCodecCallback cb = {&OnError, &OnStreamChanged, &OnNeedInputBuffer, &OnNewOutputBuffer};
    // Set the asynchronous callbacks.
    int32_t ret = OH_VideoDecoder_RegisterCallback(videoDec, cb, NULL);
    ```

4. Call **OH_VideoDecoder_Configure()** to configure the decoder.

    The procedure is the same as that in surface mode and is not described here.

    ```c++
    // (Mandatory) Configure the video frame width.
    constexpr int32_t DEFAULT_WIDTH = 320; 
    // (Mandatory) Configure the video frame height.
    constexpr int32_t DEFAULT_HEIGHT = 240;
    // (Mandatory) Configure the video color format.
    constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;

    OH_AVFormat *format = OH_AVFormat_Create();
    // Set the format.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, DEFAULT_WIDTH);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, DEFAULT_HEIGHT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, DEFAULT_PIXELFORMAT);
    // Configure the decoder.
    int32_t ret = OH_VideoDecoder_Configure(videoDec, format);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    OH_AVFormat_Destroy(format);
    ```

5. Call **OH_VideoDecoder_Prepare()** to prepare internal resources for the decoder.

     

    ```c++
    int32_t ret = OH_VideoDecoder_Prepare(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

6. Call **OH_VideoDecoder_Start()** to start the decoder.

    ```c++
    std::string_view inputFilePath = "/*yourpath*.h264";
    std::string_view outputFilePath = "/*yourpath*.yuv";
    std::unique_ptr<std::ifstream> inputFile = std::make_unique<std::ifstream>();
    std::unique_ptr<std::ofstream> outputFile = std::make_unique<std::ofstream>();
    inputFile->open(inputFilePath.data(), std::ios::in | std::ios::binary); 
    outputFile->open(outputFilePath.data(), std::ios::out | std::ios::binary | std::ios::ate);
    // Start the decoder.
    int32_t ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

7. Call **OH_VideoDecoder_PushInputBuffer()** to push the stream to the input buffer for decoding.

    The procedure is the same as that in surface mode and is not described here.

    ```c++
    // Configure the size, offset, and timestamp of the frame data.
    OH_AVCodecBufferAttr info;
    info.size = size;
    info.offset = offset;
    info.pts = pts;
    info.flags = flags;
    // Write information to the buffer.
    ret = OH_AVBuffer_SetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Send the data to the input buffer for decoding. index is the index of the buffer.
    int32_t ret = OH_VideoDecoder_PushInputBuffer(videoDec, index);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

8. Call **OH_VideoDecoder_FreeOutputBuffer()** to release decoded frames.

    In the code snippet below, the following variables are used:

    - **index**: index of the data queue, which is passed in by the callback function **OnNewOutputBuffer**.
    - **buffer**: parameter passed in by the callback function **OnNewOutputBuffer**. You can call **OH_AVBuffer_GetAddr()** to obtain the pointer to the shared memory address.

    ```c++
    // Obtain the decoded information.
    OH_AVCodecBufferAttr info;
    int32_t ret = OH_AVBuffer_GetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Write the decoded data (specified by data) to the output file.
    outputFile->write(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(buffer)), info.size);
    // Free the buffer that stores the output data. index is the index of the buffer.
    ret = OH_VideoDecoder_FreeOutputBuffer(videoDec, index);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```

    When processing the buffer data (before freeing the buffer) during hardware decoding, the system must obtain the width, height, stride, and pixel format of the data to ensure correct processing of the decoded data. For details, see [OH_NativeBuffer](../../reference/apis-arkgraphics2d/_o_h___native_buffer.md) of the graphics module.

    ```c++
    // OH_NativeBuffer * You can obtain information such as the width, height, and stride of the data by calling the APIs of the graphics module.
    OH_NativeBuffer *ohNativeBuffer = OH_AVBuffer_GetNativeBuffer(buffer);
    if (ohNativeBuffer != nullptr) {
        // Obtain the OH_NativeBuffer_Config struct, including the OH_NativeBuffer data information.
        OH_NativeBuffer_Config config;
        OH_NativeBuffer_GetConfig(ohNativeBuffer, &config);

        // Free the OH_NativeBuffer.
        ret = OH_NativeBuffer_Unreference(ohNativeBuffer);
        if (ret != AV_ERR_OK) {
            // Exception handling.
        }
        ohNativeBuffer = nullptr;
    }
    ```

The subsequent processes (including refreshing, resetting, stopping, and destroying the decoder) are basically the same as those in surface mode. For details, see steps 11-14 in [Surface Output](#surface-output).
