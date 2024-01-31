# Video Decoding (C/C++)

You can call the native APIs provided by the **VideoDecoder** module to decode video, that is, to decode media data into a YUV file or send it for display.

Currently, the following decoding capabilities are supported:

| Video Hardware Decoding Type      | Video Software Decoding Type  |
| --------------------- | ---------------- |
| AVC (H.264), HEVC (H.265)|AVC (H.264) |

Video software decoding and hardware decoding are different. When a decoder is created based on the MIME type, only H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) is supported for software decoding, and H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) and H.265 (OH_AVCODEC_MIMETYPE_VIDEO_HEVC) are supported for hardware decoding.

## How to Develop

Read [VideoDecoder](../reference/native-apis/_video_decoder.md) for the API reference.

The figure below shows the call relationship of video decoding.

![Call relationship of video decoding](figures/video-decode.png)

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_vdec.so)
```

### How to Develop

1. Add the header files.

   ``` c++
   #include <multimedia/player_framework/native_avcodec_videodecoder.h>
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <multimedia/player_framework/native_avbuffer.h>
   ```

2. Create a decoder instance.

   You can create a decoder by name or MIME type. In the code snippet below, the following variables are used:

   - videoDec: pointer to the video decorder instance.
   - capability: pointer to the codec capability instance.
   - OH_AVCODEC_MIMETYPE_VIDEO_AVC: name of an AVC-format video stream.

   ``` c++
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

   ``` c++
   // Initialize the queues.
   class VDecSignal {
   public:
       std::mutex inMutex_;
       std::mutex outMutex_;
       std::condition_variable inCond_;
       std::condition_variable outCond_;
       std::queue<uint32_t> inQueue_;
       std::queue<uint32_t> outQueue_;
       std::queue<OH_AVBuffer *> inBufferQueue_;
       std::queue<OH_AVBuffer *> outBufferQueue_;
   };
   VDecSignal *signal_;
   ```

3. Call **OH_VideoDecoder_RegisterCallback()** to set callback functions.

   Register the **OH_AVCodecCallback** struct that defines the following callback function pointers:

   - **OH_AVCodecOnError**, a callback used to report a codec operation error
   - **OH_AVCodecOnStreamChanged**, a callback used to report a codec stream change, for example, stream width or height change.
   - **OH_AVCodecOnNeedInputData**, a callback used to report input data required, which means that the decoder is ready for receiving data
   - **OH_AVCodecOnNewOutputData**, a callback used to report output data generated, which means that decoding is complete (Note: The **buffer** parameter in the callback function is empty in surface output mode.)

   You need to process the callback functions to ensure that the decoder runs properly.

   ``` c++
    // Implement the OH_AVCodecOnError callback function.
    static void OnError(OH_AVCodec *codec, int32_t errorCode, void *userData)
    {
        (void)codec;
        (void)errorCode;
        (void)userData;
    }

    // Implement the OH_AVCodecOnStreamChanged callback function.
    static void OnStreamChanged(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
    {
        (void)codec;
        (void)format;
        (void)userData;
    }

    // Implement the OH_AVCodecOnNeedInputBuffer callback function.
    static void OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        (void)codec;
        VDecSignal *signal_ = static_cast<VDecSignal *>(userData);
        std::unique_lock<std::mutex> lock(signal_->inMutex_);
        // The ID of the input frame is sent to inQueue_.
        signal_->inQueue_.push(index);
        // The input frame data is sent to inBufferQueue_.
        signal_->inBufferQueue_.push(buffer);
        signal_->inCond_.notify_all();
    }

    // Implement the OH_AVCodecOnNewOutputBuffer callback function.
    static void OnNewOutputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        (void)codec;
        VDecSignal *signal_ = static_cast<VDecSignal *>(userData);
        std::unique_lock<std::mutex> lock(signal_->outMutex_);
        // The index of the output buffer is sent to outQueue_.
        signal_->outQueue_.push(index);
        // The decoded data (specified by data) is sent to outBufferQueue_. (Note: buffer is empty in surface output mode.)
        signal_->outBufferQueue_.push(buffer);
        signal_->outCond_.notify_all();
    }
    OH_AVCodecCallback cb = {&OnError, &OnStreamChanged, &OnNeedInputBuffer, &OnNewOutputBuffer};
    // Set the asynchronous callbacks.
    int32_t ret = OH_VideoDecoder_RegisterCallback(videoDec, cb, signal_);
   ```

4. Call **OH_VideoDecoder_Configure()** to configure the decoder.

   The following options are mandatory: video frame width, video frame height, and video color format.

   ``` c++
    // (Mandatory) Configure the video frame width.
    constexpr uint32_t DEFAULT_WIDTH = 320; 
    // (Mandatory) Configure the video frame height.
    constexpr uint32_t DEFAULT_HEIGHT = 240;
    OH_AVFormat *format = OH_AVFormat_Create();
    // Set the format.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, DEFAULT_WIDTH);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, DEFAULT_HEIGHT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV21);
    // Configure the decoder.
    int32_t ret = OH_VideoDecoder_Configure(videoDec, format);
    OH_AVFormat_Destroy(format);
   ```

5. (Optional) Set the surface.

   This step is required only when the surface is used to send the data for display. The application obtains the native window from the XComponent. For details about the process, see [XComponent](../reference/arkui-ts/ts-basic-components-xcomponent.md).

   ``` c++
    // Set the parameters of the display window.
    int32_t ret = OH_VideoDecoder_SetSurface(videoDec, window); // Obtain the window from the XComponent.
    bool isSurfaceMode = true;
   ```  

6. (Optional) Configure the surface parameters of the decoder.

   This step is required only when the surface is used.

   ``` c++
    OH_AVFormat *format = OH_AVFormat_Create();
    // Configure the display rotation angle.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_ROTATION, 90);
    // Configure the matching mode (scaling or cropping) between the video and the display screen.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_SCALING_MODE, SCALING_MODE_SCALE_CROP);
    int32_t ret = OH_VideoDecoder_SetParameter(videoDec, format);
    OH_AVFormat_Destroy(format);
   ```

7. Call **OH_VideoDecoder_Start()** to start the decoder.

   ``` c++
    string_view outputFilePath = "/*yourpath*.yuv";
    std::unique_ptr<std::ifstream> inputFile = std::make_unique<std::ifstream>();
    // Open the path of the binary file to be decoded.
    inputFile->open(inputFilePath.data(), std::ios::in | std::ios::binary); 
    // Configure the parameter in buffer mode.
    if(!isSurfaceMode) {
        // Configure the output file path in buffer mode.
        std::unique_ptr<std::ofstream> outFile = std::make_unique<std::ofstream>();
        outFile->open(outputFilePath.data(), std::ios::out | std::ios::binary);
    }
    // Start decoding.
    int32_t ret = OH_VideoDecoder_Start(videoDec);
   ```

8. Call **OH_VideoDecoder_PushInputBuffer()** to push the stream to the input queue for decoding.

   ``` c++
    // Configure the buffer information.
    OH_AVCodecBufferAttr info;
    // Call av_packet_alloc of FFmpeg to initialize and return a container packet.
    AVPacket pkt = av_packet_alloc();
    // Configure the input size, offset, and timestamp of the buffer.
    info.size = pkt->size;
    info.offset = 0;
    info.pts = pkt->pts;
    info.flags = AVCODEC_BUFFER_FLAGS_NONE;
   // Write info information to the buffer.
   ret = OH_AVBuffer_SetBufferAttr(buffer, &info);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   // Send the data to the input queue for decoding. The index is the subscript of the queue.
   int32_t ret = OH_VideoDecoder_PushInputBuffer(videoDec, index);
   ```

9. In surface display mode, call **OH_VideoDecoder_RenderOutputBuffer()** to display and release the decoded frames. In the surface no display mode or buffer mode, call **OH_VideoDecoder_FreeOutputBuffer()** to the release decoded frames.

   ``` c++
    int32_t ret;
    // Obtain the decoded information.
    OH_AVCodecBufferAttr attr;
    ret = OH_AVBuffer_GetBufferAttr(buffer, &attr);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Write the decoded data (specified by data) to the output file.
    outFile->write(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(buffer)), attr.size);
    // Free the buffer that stores the output data. The index is the subscript of the surface/buffer queue.
    if (isSurfaceMode && isRender) {
        ret = OH_VideoDecoder_RenderOutputBuffer(videoDec, index);
    } else {
        ret = OH_VideoDecoder_FreeOutputBuffer(videoDec, index);
    }
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
   ```

10. (Optional) Call **OH_VideoDecoder_Flush()** to refresh the decoder.
   
    After **OH_VideoDecoder_Flush()** is called, the decoder remains in the running state, but the current queue is cleared and the buffer storing the decoded data is freed.
   
    To continue decoding, you must call **OH_VideoDecoder_Start()** again.

    ``` c++
    int32_t ret;
    // Refresh the decoder.
    ret = OH_VideoDecoder_Flush(videoDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Start decoding again.
    ret = OH_VideoDecoder_Start(videoDec);
    ```

11. (Optional) Call **OH_VideoDecoder_Reset()** to reset the decoder.

    After **OH_VideoDecoder_Reset()** is called, the decoder returns to the initialized state. To continue decoding, you must call **OH_VideoDecoder_Configure()** and then **OH_VideoDecoder_Start()**.

    ``` c++
     int32_t ret;
     // Reset the decoder.
     ret = OH_VideoDecoder_Reset(videoDec);
     if (ret != AV_ERR_OK) {
         // Exception handling.
     }
     // Reconfigure the decoder.
     ret = OH_VideoDecoder_Configure(videoDec, format);
    ```

12. Call **OH_VideoDecoder_Stop()** to stop the decoder.

    ``` c++
     int32_t ret;
     // Stop the decoder.
     ret = OH_VideoDecoder_Stop(videoDec);
     if (ret != AV_ERR_OK) {
         // Exception handling.
     }
    ```

13. Call **OH_VideoDecoder_Destroy()** to destroy the decoder instance and release resources.

    ``` c++
     int32_t ret;
     // Call OH_VideoDecoder_Destroy to destroy the decoder.
     ret = OH_VideoDecoder_Destroy(videoDec);
     if (ret != AV_ERR_OK) {
         // Exception handling.
     }
    ```
