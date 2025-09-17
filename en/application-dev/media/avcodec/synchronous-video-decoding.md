# Synchronous Video Decoding

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

Starting from API version 20, video decoding in synchronous mode is supported.

You can call native APIs to perform synchronous video decoding.

For details about the supported decoding capabilities, see [AVCodec Supported Formats](avcodec-support-formats.md#video-decoding).

For details about the restrictions, supported capabilities, and state machine call relationships of video decoding, see [Video Decoding](video-decoding.md).

## When to Use

Asynchronous mode is generally recommended for most use cases. Synchronous mode can be used if you need to actively request buffers for frame delivery.


## How to Develop

Read [VideoDecoder](../../reference/apis-avcodec-kit/_video_decoder.md) for the API reference.

The figure below shows the call relationship of synchronous video decoding.

- The dotted line indicates an optional operation.

- The solid line indicates a mandatory operation.

![Call relationship of synchronous video decoding](figures/synchronous-video-decode.png)

### Linking the Dynamic Libraries in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_vdec.so)
```

> **NOTE**
>
> The word **sample** in the preceding code snippet is only an example. Use the actual project directory name.
>

### Defining the Basic Structure

The sample code provided in this section adheres to the C++17 standard and is for reference only.

1. Add the header files.

    ```c++
    #include <multimedia/player_framework/native_avcodec_videodecoder.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    #include <multimedia/player_framework/native_avbuffer.h>
    #include <multimedia/player_framework/native_averrors.h>
    #include <native_buffer/native_buffer.h>
    #include <memory>
    #include <fstream>
    #include <mutex>
    #include <shared_mutex>
    #include <string.h>
    ```
    
2. Configure global variables.

    These global variables are for reference only. They can be encapsulated into an object based on service requirements.

    ```c++
    // Video frame width.
    int32_t width = 320;
    // Video frame height.
    int32_t height = 240;
    // Video pixel format.
    OH_AVPixelFormat pixelFormat = AV_PIXEL_FORMAT_NV12;
    // Decoder synchronization lock.
    std::shared_mutex codecMutex;
    // Pointer to the decoder instance.
    OH_AVCodec *videoDec = nullptr;
    // Decoding output.
    bool outputDone = false;
    // Decoding input.
    bool inputDone = false;
    std::unique_ptr<std::ifstream> inFile_;
    ```

### Surface Mode

The following walks you through how to implement the entire video decoding process in surface mode and implement data rotation in synchronous mode. In this example, an H.264 stream file is input, decoded, and rendered.


1. Create a decoder instance.

    Create a decoder by name. In the code snippet below, the following variables are used:

    - **videoDec**: pointer to the video decoder instance.
    - **capability**: pointer to the decoder's capability.
    - **OH_AVCODEC_MIMETYPE_VIDEO_AVC**: AVC video codec.

    ```c++
    // Create a hardware decoder instance.
    OH_AVCapability *capability= OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, HARDWARE);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(name);
    if (videoDec == nullptr) {
        printf("create videoDec failed");
        return;
    }
    ```
2. Call **OH_VideoDecoder_Configure()** to configure the decoder.

    - For details about the configurable options, see [Media Data Key-Value Pairs](../../reference/apis-avcodec-kit/_codec_base.md#media-data-key-value-pairs).
    - For details about the parameter verification rules, see [OH_VideoDecoder_Configure()](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_configure).
    - The parameter value ranges can be obtained through the capability query interface. For details, see [Obtaining Supported Codecs](obtain-supported-codecs.md).

    Currently, the following options must be configured for all supported formats: video frame width and height.

    ```c++

    auto format = std::shared_ptr<OH_AVFormat>(OH_AVFormat_Create(), OH_AVFormat_Destroy);
    if (format == nullptr) {
        // Handle exceptions.
    }
    // Set the format.
    OH_AVFormat_SetIntValue(format.get(), OH_MD_KEY_WIDTH, width); // Mandatory.
    OH_AVFormat_SetIntValue(format.get(), OH_MD_KEY_HEIGHT, height); // Mandatory.
    OH_AVFormat_SetIntValue(format.get(), OH_MD_KEY_PIXEL_FORMAT, pixelFormat);
    OH_AVFormat_SetIntValue(format.get(), OH_MD_KEY_ENABLE_SYNC_MODE, 1); // Set synchronous mode.
    // Configure the decoder.
    OH_AVErrCode ret = OH_VideoDecoder_Configure(videoDec, format.get());
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

    > **NOTE**
    >
    > To enable video decoding in synchronous mode, **OH_MD_KEY_ENABLE_SYNC_MODE** must be set to **1**.
    >
    > To use synchronous mode, do not call **OH_VideoDecoder_RegisterCallback** in prior to **OH_VideoDecoder_Configure**. Otherwise, the decoder will run in asynchronous mode instead.


3. Set the surface.

   In the code snippet below, the following variables are used:
   - **nativeWindow**: For details about how to obtain the native window, see step 6 in [Surface Mode](video-decoding.md#surface-mode).

    ```c++
    // Set the surface.
    // Set the window parameters.
    OH_AVErrCode ret = OH_VideoDecoder_SetSurface(videoDec, nativeWindow);  
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```


4. Call **OH_VideoDecoder_Prepare()** to prepare internal resources for the decoder.

    ```c++
    OH_AVErrCode ret = OH_VideoDecoder_Prepare(videoDec);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

5. Call **OH_VideoDecoder_Start()** to start the decoder.

    ```c++
    // Start the decoder.
    OH_AVErrCode ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

6. Obtain an available buffer and write the bitstream to the decoder.

    - Call [OH_VideoDecoder_QueryInputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_queryinputbuffer) to obtain the index of the next available input buffer.
    - Based on this index, call [OH_VideoDecoder_GetInputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_getinputbuffer) to obtain the buffer instance.
    - Write the data to be decoded into the buffer, and call [OH_VideoDecoder_PushInputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_pushinputbuffer) to push it to the decoder for decoding. When all the data to be processed has been passed to the decoder, set flag to **AVCODEC_BUFFER_FLAGS_EOS** to notify the decoder that the input is complete.

    Send the input queue for decoding. In the code snippet below, the following variables are used:
    - **size**, **offset**, **pts**, and **frameData**: size, offset, timestamp, and frame data. For details about how to obtain such information, see step 9 in [Media Data Demultiplexing](./audio-video-demuxer.md#how-to-develop).
    - **flags**: type of the buffer flag. For details, see [OH_AVCodecBufferFlags](../../reference/apis-avcodec-kit/_core.md#oh_avcodecbufferflags).

    ```c++
    bool DecoderInput(OH_AVCodec *videoDec, int64_t timeoutUs)
    {    
        uint32_t index;
        std::shared_lock<std::shared_mutex> lock(codecMutex);

        OH_AVErrCode ret = OH_VideoDecoder_QueryInputBuffer(videoDec, &index, timeoutUs);
        switch (ret) {
            case AV_ERR_OK: {
                OH_AVBuffer *buffer = OH_VideoDecoder_GetInputBuffer(videoDec, index);
                if (buffer == nullptr) {
                    // Handle exceptions.
                    return false;
                }
                // Write stream data.
                uint8_t *addr = OH_AVBuffer_GetAddr(buffer);
                if (addr == nullptr) {
                   // Handle exceptions.
                   return false;
                }
                // Fill in the buffer.
                int32_t capacity = OH_AVBuffer_GetCapacity(buffer);
                if (size > capacity) {
                    // Handle exceptions.
                }
                memcpy(addr, frameData, size);

                OH_AVCodecBufferAttr info;
                // Set the buffer attributes.
                // Configure the size, offset, and timestamp of the frame data.
                info.size = size;
                info.offset = offset;
                info.pts = pts;
                if (inFile_->eof()) {
                    info.flags = AVCODEC_BUFFER_FLAGS_EOS;
                } else {
                    info.flags = flags;
                }
                OH_AVErrCode setBufferRet = OH_AVBuffer_SetBufferAttr(buffer, &info);
                if (setBufferRet != AV_ERR_OK) {
                    // Handle exceptions.
                    return false;
                }    
                OH_AVErrCode pushInputRet = OH_VideoDecoder_PushInputBuffer(videoDec, index);
                if (pushInputRet != AV_ERR_OK) {
                    // Handle exceptions.
                    return false;
                }
                if (inFile_->eof()) {
                    inputDone = 1;
                }
                break;
            }
            case AV_ERR_TRY_AGAIN_LATER: {
                break;
            }
            default: {
                // Handle exceptions.
                return false;
            }    
        }
        return true;
    }
    ```

7. Obtain an available buffer and release the decoded frame.

   - Call [OH_VideoDecoder_QueryOutputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_queryoutputbuffer) to obtain the index of the next available input buffer.
   - Bsed on this index, call [OH_VideoDecoder_GetOutputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_getoutputbuffer) to obtain the buffer instance.
   - Determine the subsequent operations based on the **isRender** flag. If the decoded frame does not need to be rendered, call [OH_VideoDecoder_FreeOutputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_freeoutputbuffer) to release the decoded frame. If the decoded frame needs to be rendered, you can call [OH_VideoDecoder_RenderOutputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_renderoutputbuffer) to display the decoded frame and automatically release it, or call [OH_VideoDecoder_RenderOutputBufferAtTime](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_renderoutputbufferattime) to display the decoded frame at a specified time and then release it.

    ```c++
    bool DecoderOutput(OH_AVCodec *videoDec, int64_t timeoutUs)
    {
        uint32_t index;
        std::shared_lock<std::shared_mutex> lock(codecMutex);

        OH_AVErrCode ret = OH_VideoDecoder_QueryOutputBuffer(videoDec, &index, timeoutUs);
        switch (ret) {
            case AV_ERR_OK: {
                OH_AVBuffer *buffer = OH_VideoDecoder_GetOutputBuffer(videoDec, index);
                if (buffer == nullptr) {
                    // Handle exceptions.
                    return false;
                }
            
                // Obtain the decoded information.
                OH_AVCodecBufferAttr info;
                OH_AVErrCode getBufferRet = OH_AVBuffer_GetBufferAttr(buffer, &info);
                if (getBufferRet != AV_ERR_OK) {
                    // Handle exceptions.                   
                    return false;
                }
                if (info.flags & AVCODEC_BUFFER_FLAGS_EOS) {
                    outputDone = 1;
                }
                
                // Handle the decoded output data.
                // You can determine the value.
                bool isRender;
                bool isNeedRenderAtTime;
                OH_AVErrCode result = AV_ERR_OK;
                if (isRender) {
                    // Render the data and free the output buffer. index is the index of the buffer.
                    if (isNeedRenderAtTime){
                        // Obtain the system absolute time, and call renderTimestamp to display the time based on service requirements.
                        int64_t renderTimestamp =
                            std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
                        result = OH_VideoDecoder_RenderOutputBufferAtTime(videoDec, index, renderTimestamp);
                    } else {
                        result = OH_VideoDecoder_RenderOutputBuffer(videoDec, index);
                    }
                } else {
                    // Free the output buffer.
                    result = OH_VideoDecoder_FreeOutputBuffer(videoDec, index);
                }
                if (result != AV_ERR_OK) {
                    // Handle exceptions.
                    return false;
                }
                break;
            }
            case AV_ERR_TRY_AGAIN_LATER: {
                break;
            }
            case AV_ERR_STREAM_CHANGED: {
                auto format = std::shared_ptr<OH_AVFormat>(OH_VideoDecoder_GetOutputDescription(videoDec), OH_AVFormat_Destroy);
                if (format == nullptr) {
                    // Handle exceptions.
                }
                // Obtain the new width and height.
                bool getIntRet = OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_PIC_WIDTH, &width) &&
                                 OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_PIC_HEIGHT, &height);
                if (!getIntRet) {
             	    // Handle exceptions.
                }
                break;
            }
            default: {
                // Handle exceptions.
                return false;
            }
        }
        return true;
    }
    ```

8. Enable the decoder to input and output frames in a loop.

    ```c++
    bool result = true;
    int64_t timeoutUs = 0; // Unit: μs. A negative value means to wait infinitely. The value 0 means to return immediately. A positive value means to wait for the specified time before exiting.

    while (!outputDone && result) {
        if (!inputDone) {
            result = DecoderInput(videoDec, timeoutUs);
        }
        if (!outputDone) {
            result = DecoderOutput(videoDec, timeoutUs);
        }
    }
    ```

9. (Optional) Call **OH_VideoDecoder_Flush()** to refresh the decoder.

    After **OH_VideoDecoder_Flush** is called, the decoder remains in the Running state, but the input and output data and parameter set (such as the H.264 PPS/SPS) buffered in the decoder are cleared.

    In this case, you need to call [OH_VideoDecoder_Start](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_start) to start decoding again.

    ```c++
    // Use codecMutex to avoid the problem where the decoding thread keeps running and exits the loop after the Flush API is called and the state is changed.
    std::unique_lock<std::shared_mutex> lock(codecMutex);
    // Refresh the decoder.
    OH_AVErrCode ret = OH_VideoDecoder_Flush(videoDec);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }

    // Start decoding again.
    ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

10. (Optional) Call **OH_VideoDecoder_Reset()** to reset the decoder.

    After **OH_VideoDecoder_Reset** is called, the decoder returns to the Initialized state. To continue decoding, you must call [OH_VideoDecoder_Configure](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_configure), [OH_VideoDecoder_SetSurface](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_setsurface), and [OH_VideoDecoder_Prepare](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_prepare) in sequence.

    ```c++
    // Reset the decoder.
    std::unique_lock<std::shared_mutex> lock(codecMutex);
    OH_AVErrCode resetRet = OH_VideoDecoder_Reset(videoDec);
    if (resetRet != AV_ERR_OK) {
        // Handle exceptions.
    }
 
    // Reconfigure the decoder.
    auto format = std::shared_ptr<OH_AVFormat>(OH_AVFormat_Create(), OH_AVFormat_Destroy);
    if (format == nullptr) {
        // Handle exceptions.
    }
    OH_AVErrCode configRet = OH_VideoDecoder_Configure(videoDec, format.get());
    if (configRet != AV_ERR_OK) {
        // Handle exceptions.
    }

    // Reconfigure the surface in surface mode. This is not required in buffer mode.
    OH_AVErrCode setRet = OH_VideoDecoder_SetSurface(videoDec, nativeWindow);
    if (setRet != AV_ERR_OK) {
        // Handle exceptions.
    }
    // The decoder is ready again.
    OH_AVErrCode prepareRet = OH_VideoDecoder_Prepare(videoDec);
    if (prepareRet != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

    > **NOTE**
    >
    > When the decoder returns to the initialized state, you must call **OH_VideoDecoder_Configure** to set **OH_MD_KEY_ENABLE_SYNC_MODE** to **1** to reconfigure the decoder parameters. Otherwise, the decoder will run in asynchronous mode.

11. (Optional) Call **OH_VideoDecoder_Stop()** to stop the decoder.

    After **OH_VideoDecoder_Stop()** is called, the decoder retains the decoding instance and releases the input and output buffers.

    ```c++
    // Stop the decoder.
    std::unique_lock<std::shared_mutex> lock(codecMutex);
    OH_AVErrCode ret = OH_VideoDecoder_Stop(videoDec);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

12. Call **OH_VideoDecoder_Destroy()** to destroy the decoder instance and release resources.

    ```c++
    // Call OH_VideoDecoder_Destroy to destroy the decoder.
    std::unique_lock<std::shared_mutex> lock(codecMutex);
    OH_AVErrCode ret = AV_ERR_OK;
    if (videoDec != nullptr) {
        ret = OH_VideoDecoder_Destroy(videoDec);
        videoDec = nullptr;
    }
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

    > **NOTE**
    >
    > After the call, you must set a null pointer to the decoder to prevent program errors caused by wild pointers.

### Buffer Mode

The following walks you through how to implement the entire video decoding process in buffer mode and implement data rotation in synchronous mode. In this example, an H.264 stream file is input and decoded into a YUV file.

1. Create a decoder instance.

    The procedure is the same as that in surface mode and is not described here.

    ```c++
    // To create a decoder by name, call OH_AVCapability_GetName to obtain the codec names available and then call OH_VideoDecoder_CreateByName. If your application has special requirements, for example, expecting a decoder that supports a certain resolution, you can call OH_AVCodec_GetCapability to query the capability first.
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(name);
    if (videoDec == nullptr) {
        printf("create videoDec failed");
        return;
    }
    ```

2. Call **OH_VideoDecoder_Configure()** to configure the decoder.

    The procedure is the same as that in surface mode and is not described here.

    ```c++

    auto format = std::shared_ptr<OH_AVFormat>(OH_AVFormat_Create(), OH_AVFormat_Destroy);
    if (format == nullptr) {
        // Handle exceptions.
    }
    // Set the format.
    OH_AVFormat_SetIntValue(format.get(), OH_MD_KEY_WIDTH, width); // Mandatory.
    OH_AVFormat_SetIntValue(format.get(), OH_MD_KEY_HEIGHT, height); // Mandatory.
    OH_AVFormat_SetIntValue(format.get(), OH_MD_KEY_PIXEL_FORMAT, pixelFormat);
    OH_AVFormat_SetIntValue(format.get(), OH_MD_KEY_ENABLE_SYNC_MODE, 1); // Set synchronous mode.
    // Configure the decoder.
    OH_AVErrCode ret = OH_VideoDecoder_Configure(videoDec, format.get());
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

    > **NOTE**
    >
    > To enable video decoding in synchronous mode, **OH_MD_KEY_ENABLE_SYNC_MODE** must be set to **1**.
    >
    > To use synchronous mode, do not call **OH_VideoDecoder_RegisterCallback** in prior to **OH_VideoDecoder_Configure**. Otherwise, the decoder will run in asynchronous mode instead.

3. Call **OH_VideoDecoder_Prepare()** to prepare internal resources for the decoder.

   ```c++
OH_AVErrCode ret = OH_VideoDecoder_Prepare(videoDec);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```
    
4. Call **OH_VideoDecoder_Start()** to start the decoder.

    ```c++
    std::unique_ptr<std::ofstream> outputFile = std::make_unique<std::ofstream>();
    if (outputFile != nullptr) {
        outputFile->open("/*yourpath*.yuv", std::ios::out | std::ios::binary | std::ios::ate);
    }
    // Start the decoder.
    OH_AVErrCode ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

5. Obtain an available buffer and write the bitstream to the decoder.

    - Call [OH_VideoDecoder_QueryInputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_queryinputbuffer) to obtain the index of the next available input buffer.
    - Based on this index, call [OH_VideoDecoder_GetInputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_getinputbuffer) to obtain the buffer instance.
    - Write the data to be decoded into the buffer, and call [OH_VideoDecoder_PushInputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_pushinputbuffer) to push it to the decoder for decoding. When all the data to be processed has been passed to the decoder, set flag to **AVCODEC_BUFFER_FLAGS_EOS** to notify the decoder that the input is complete.

    The meanings of the variables **size**, **offset**, **pts**, **frameData**, and **flags** in the example are the same as those in surface mode.

    ```c++
    bool DecoderInput(OH_AVCodec *videoDec, int64_t timeoutUs)
    {    
        uint32_t index;
        std::shared_lock<std::shared_mutex> lock(codecMutex);

        OH_AVErrCode ret = OH_VideoDecoder_QueryInputBuffer(videoDec, &index, timeoutUs);
        switch (ret) {
            case AV_ERR_OK: {
                OH_AVBuffer *buffer = OH_VideoDecoder_GetInputBuffer(videoDec, index);
                if (buffer == nullptr) {
                    // Handle exceptions.
                    return false;
                }
                // Write stream data.
                uint8_t *addr = OH_AVBuffer_GetAddr(buffer);
                if (addr == nullptr) {
                   // Handle exceptions.
                   return false;
                }
                // Fill in the buffer.
                int32_t capacity = OH_AVBuffer_GetCapacity(buffer);
                if (size > capacity) {
                    // Handle exceptions.
                }
                memcpy(addr, frameData, size);

                OH_AVCodecBufferAttr info;
                // Set the buffer attributes.
                // Configure the size, offset, and timestamp of the frame data.
                info.size = size;
                info.offset = offset;
                info.pts = pts;
                if (inFile_->eof()) {
                    info.flags = AVCODEC_BUFFER_FLAGS_EOS;
                } else {
                    info.flags = flags;
                }
                OH_AVErrCode setBufferRet = OH_AVBuffer_SetBufferAttr(buffer, &info);
                if (setBufferRet != AV_ERR_OK) {
                    // Handle exceptions.
                    return false;
                }    
                OH_AVErrCode pushInputRet = OH_VideoDecoder_PushInputBuffer(videoDec, index);
                if (pushInputRet != AV_ERR_OK) {
                    // Handle exceptions.
                    return false;
                }
                if (inFile_->eof()) {
                    inputDone = 1;
                }
                break;
            }
            case AV_ERR_TRY_AGAIN_LATER: {
                break;
            }
            default: {
                // Handle exceptions.
                return false;
            }    
        }
        return true;
    }
    ```

6. Obtain an available buffer and release the decoded frame.

   - Call [OH_VideoDecoder_QueryOutputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_queryoutputbuffer) to obtain the index of the next available input buffer.
   - Based on this index, call [OH_VideoDecoder_GetOutputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_getoutputbuffer) to obtain the buffer instance.
   - Call [OH_VideoDecoder_FreeOutputBuffer](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_freeoutputbuffer) to release the decoded frame.

    ```c++
    bool DecoderOutput(OH_AVCodec *videoDec, int64_t timeoutUs)
    {
        uint32_t index;
        int32_t cropTop = 0;
        int32_t cropBottom = 0;
        int32_t cropLeft = 0;
        int32_t cropRight = 0;
        int32_t widthStride = 0;
        int32_t heightStride = 0;
        std::shared_lock<std::shared_mutex> lock(codecMutex);

        OH_AVErrCode ret = OH_VideoDecoder_QueryOutputBuffer(videoDec, &index, timeoutUs);
        switch (ret) {
            case AV_ERR_OK: {
                OH_AVBuffer *buffer = OH_VideoDecoder_GetOutputBuffer(videoDec, index);
                if (buffer == nullptr) {
                    // Handle exceptions.
                    return false;
                }
            
                // Obtain the decoded information.
                OH_AVCodecBufferAttr info;
                OH_AVErrCode getBufferRet = OH_AVBuffer_GetBufferAttr(buffer, &info);
                if (getBufferRet != AV_ERR_OK) {
                    // Handle exceptions.                   
                    return false;
                }
                if (info.flags & AVCODEC_BUFFER_FLAGS_EOS) {
                    outputDone = 1;
                }
                
                // Free the output buffer. index is the index of the buffer.
                OH_AVErrCode freeOutputRet = OH_VideoDecoder_FreeOutputBuffer(videoDec, index);
                if (freeOutputRet != AV_ERR_OK) {
                    // Handle exceptions.
                    return false;
                }
                break;
            }
            case AV_ERR_TRY_AGAIN_LATER: {
                break;
            }
            case AV_ERR_STREAM_CHANGED: {
                auto format = std::shared_ptr<OH_AVFormat>(OH_VideoDecoder_GetOutputDescription(videoDec), OH_AVFormat_Destroy);
                if (format == nullptr) {
                    // Handle exceptions.
                }
                // Obtain the new video width, height, and stride.
                bool getIntRet = OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_PIC_WIDTH, &width) &&
                           OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_PIC_HEIGHT, &height) &&
                           OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_STRIDE, &widthStride) &&
                           OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_SLICE_HEIGHT, &heightStride) &&
                           // (Optional) Obtain the cropped rectangle information.
                           OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_CROP_TOP, &cropTop) &&
                           OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_CROP_BOTTOM, &cropBottom) &&
                           OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_CROP_LEFT, &cropLeft) &&
                           OH_AVFormat_GetIntValue(format.get(), OH_MD_KEY_VIDEO_CROP_RIGHT, &cropRight);
                if (!getIntRet) {
                 	// Handle exceptions.
                }
                break;
            }
            default: {
                // Handle exceptions.
                return false;
            }
        }
        return true;
    }
    ```

7. Enable the decoder to input and output frames in a loop.
  
    ```c++
    bool result = true;
    int64_t timeoutUs = 0; // Unit: μs. A negative value means to wait infinitely. The value 0 means to return immediately. A positive value means to wait for the specified time before exiting.

    while (!outputDone && result) {
        if (!inputDone) {
            result = DecoderInput(videoDec, timeoutUs);
        }
        if (!outputDone) {
            result = DecoderOutput(videoDec, timeoutUs);
        }
    }
    ```

The subsequent processes (including refreshing, resetting, stopping, and destroying the decoder) are the same as those in surface mode. For details, see steps 9–12 in [Surface Mode](#surface-mode).
