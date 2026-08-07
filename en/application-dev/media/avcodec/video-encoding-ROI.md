# ROI Video Encoding

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yang-xiaoyu5-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-06T13:51:02.594Z pushedAt=2026-08-07T09:56:50.379Z -->

## Basic Concepts

Region of Interest (ROI) video encoding has been supported since API version 20. This feature is an advanced optimization technology extended based on the hardware H.264/H.265 encoding capability. Its core logic is to allocate more encoding resources to the specified key regions in the frame to achieve high-quality encoding. It ensures the clear presentation of content in ROI regions under limited bandwidth, which significantly enhances the overall visual experience.

You can define ROI regions in the video frame (for example, human faces in live streaming, license plates in video security, etc.), and adjust the encoding quality difference between ROI and non-ROI regions by setting quality offset parameters, thus realizing the differentiated allocation of encoding resources.

## When to Use

ROI video encoding applies to scenarios where the bit rate cannot meet the video quality requirements due to limited network bandwidth, and the key frame content (ROI regions) can be clearly defined. Examples include video calls, live video streaming, video security, and more.

Recommended ROI regions for each scenario are as follows:

- Live fashion shows: Set the anchor's facial region as the ROI to optimize facial details (e.g., skin tone and facial feature contours), enhancing the audience's immersive viewing experience.

- Outdoor live streaming: Set the anchor's main body/core shooting scenes (for example, natural scenery and core areas of sports event footage) as the ROI to ensure the clarity of core content when the mobile network bandwidth fluctuates.

- E-commerce live streaming: Set the product display area (for example, makeup color testing and electronic product details) as the ROI to clearly present the product's appearance, material, and functional details, helping to improve product conversion rates.

- Online course videos: Set the areas of courseware text, lecture notes charts, and blackboard writing content as the ROI to ensure the clear readability of knowledge points, reduce visual fatigue, and improve teaching effectiveness.

- Video security: Set key regions in the camera frame (for example, human faces, license plates, entrances and exits) as the ROI to improve the clarity of capture, facilitating subsequent identification and analysis.

Based on different encoding modes and ROI configuration methods, three ROI encoding development examples are provided. You can choose the appropriate one according to your actual service requirements and technical architecture.

| Scenario| Live Streaming/Video Call| Video Recording| Editing & Export/Content Publishing|
| :----: |:----:|:----:| :----: |
| **ROI information producer**| Camera| Camera| App|
| **ROI Information Retrieval Method** | Extracted from video frame NativeBuffer metadata | Extracted from video frame NativeBuffer metadata | Self-managed by the app |
| **Direct Producer of Encoded Video Frames** | Graphics | Graphics | App |
| **Encoding mode**| Surface mode| Surface mode| Buffer mode|
| **ROI Parameter Configuration Method** | NativeBuffer metadata configuration (recommended) | Encoding input parameter callback configuration | Encoding input buffer callback configuration |
| **Development Example** | [Surface mode - Method 1](#method-1-configuring-roi-via-nativebuffer-metadata-recommended) | [Surface mode - Method 2](#method-2-configuring-roi-via-the-encoding-input-parameter-callback) | [Buffer mode](#method-3-configuring-roi-in-buffer-mode) |

> **NOTE**
>
> - Both live streaming and recording scenarios use Surface mode encoding, differing only in the ROI configuration method. The NativeBuffer metadata configuration method is recommended, as it is simple to implement and naturally aligned with encoding frames.
> - If the metadata of the encoder input buffer cannot be modified during frame processing (for example, when camera frames are directly sent to the encoder surface), you can choose the encoding input parameter callback configuration method.

## Constraints

**Supported encoders**: H.264 8-bit hardware encoding, H.265 8-bit hardware encoding, and H.265 10-bit hardware encoding

Supported bit rate control modes: variable bit rate (VBR), constant bit rate (CBR) and stable quality rate control (SQR)

**ROI detection and identification capability dependency:** The encoder does not have built-in ROI detection and recognition capability, so the effectiveness of ROI encoding technology relies on the ROI information provided by you. You can design and implement ROI recognition capabilities based on your service scenarios, or reduce development costs by calling the face region information natively provided by the system camera module. For details, see [Metadata (C/C++)](../camera/native-camera-metadata.md).

## Parameter Requirements

ROI configuration parameters are ultimately delivered to the encoder in the form of strings. Starting from API version 26.0.0, the key-value pair format is supported, while the legacy numeric-only format remains compatible. All coordinate parameters and numeric parameters are integers.

When ROI data comes from the NativeBuffer metadata of a camera frame, you do not need to manually concatenate strings. You can use the `OH_VideoMetadata_GetRoiCount`, `OH_VideoMetadata_ParseRoiString`, and `OH_VideoMetadata_AppendRoiString` APIs to directly parse region information from the ROI metadata of the camera frame, set key-value pair parameters (such as `OH_MD_KEY_VIDEO_METADATA_ROI_DELTA_QP` and `OH_MD_KEY_VIDEO_METADATA_ROI_SEM_LABEL`), and automatically generate a configuration string that meets the encoder requirements.

**String format:**

- Key-value pair format (recommended): `Top,Left-Bottom,Right=dqp:-6,slb:1`

- Numeric-only format (legacy compatible): `Top,Left-Bottom,Right=DeltaQp`

**Rectangle region definition:**
An ROI is a rectangular region. **Top**, **Left** and **Bottom**, **Right** define the coordinates of the top-left and bottom-right corners of the ROI region in the image (as shown in figure 1).

**Key-value pair parameters:**

| Parameter | Description | Value Range | Mandatory | Default Behavior |
| :----: | :----: | :----: |:----:|:----------------:|
| dqp | Quantization parameter offset (DeltaQP) | [-51, 51] | No | When not set, the encoder uses the default QP strategy (=-3). |
| slb | Semantic label | 0 (other) or 1 (face) | No | This parameter is only used to distinguish ROI region types and does not affect encoding behavior. |

- A negative dqp value indicates that the encoding quality of the ROI region is better than that of non-ROI regions. The larger the absolute value, the greater the quality difference.

- The slb value corresponds to the [OH_VideoMetadataRoiSemanticLabel](../../reference/apis-avcodec-kit/capi-native-avcodec-videobase-h.md#oh_videometadataroisemanticlabel) enumeration: `OH_VIDEO_METADATA_ROI_SEM_LABEL_OTHER` (0) indicates an unspecified region type, and `OH_VIDEO_METADATA_ROI_SEM_LABEL_FACE` (1) indicates a face region.

- Multiple ROI parameters are connected by semicolons (;). An example of multi-ROI configuration is `100,50-300,200=dqp:-6,slb:1;400,30-600,200=dqp:-3`.

**Quantity and area constraints:**

- A maximum of 6 ROI regions are supported per frame. Excess ROI regions will be ignored in the order of configuration.

- The total ROI area must not exceed 1/5 of the image area. The areas are accumulated in the order of configuration, and only the ROI regions whose cumulative area stays within the limit take effect.

**Figure 1: ROI coordinates and maximum allowed area ratio**

![ROI coordinates and maximum allowed area ratio](figures/roi-size-and-coordinate.png)

## Effectiveness Mechanism

Two methods are supported for ROI configuration: **NativeBuffer metadata configuration** and **encoding input callback configuration**. The encoding input callback configuration method includes encoding input parameter callback (Surface mode) and encoding input buffer callback (Buffer mode).

- (Recommended) NativeBuffer metadata configuration: Starting from API version 22, the ROI enumeration **OH_REGION_OF_INTEREST_METADATA** of **OH_NativeBuffer_MetaDataKey** can be used to configure ROI parameters in the NativeBuffer metadata.

- Encoding input callback configuration method: The video encoding parameter **OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS** is used to configure ROI parameters in the encoding input callback.

**General effectiveness mechanism:**

1. ROI parameters support frame-by-frame delivery and take effect in real time. You do not need to query capabilities or configure global switches.

2. If the system encoder does not support ROI encoding, the encoder ignores ROI parameters and performs normal encoding.

3. The valid range of **DeltaQp** is [-51, 51]. The encoder overlays **DeltaQp** on the QP of the ROI region, and then limits the result to the range [minQp, maxQp] to obtain the final QP.

4. When no ROI parameters are configured for a frame, if ROI encoding takes effect for the previous frame, the ROI information of the previous frame is reused for ROI encoding of the current frame. If normal encoding is used for the previous frame, normal encoding is performed for the current frame.

5. If the ROI parameters configured for a frame fail to parse any valid ROI information, normal encoding will be performed.

6. If multiple ROI regions overlap, only the first configured ROI region will take effect at the overlapping area in the order of configuration.

**Unique mechanism of NativeBuffer metadata configuration method**: A maximum of 256 bytes of character length is supported; the excess part will be truncated.

**Empty string handling differences:**

- NativeBuffer metadata configuration method: Empty strings are not allowed to be configured. An empty string is regarded as no ROI parameters configured, and the current frame will inherit the historical frame information for ROI encoding.

- Encoding input callback configuration method: Empty strings are allowed to be configured, but since no valid ROI information can be parsed, normal encoding will be performed actually.

> **NOTE**
>
> Due to the differences in empty string processing, you are advised not to configure empty strings. If you need to disable ROI encoding for a frame, you can configure a string without position information (for example, **"Clear"** or **";"**).

**Effectiveness priority**: If ROI parameters are configured via both methods for a frame, only the ROI parameters delivered via the encoding input callback configuration method will take effect, regardless of whether valid ROI information can be parsed from them.

## Development Example

The following development examples are organized by encoding mode. Surface mode and buffer mode share the same ROI information acquisition and assembly process, differing only in how the ROI is configured to the encoder.

When the camera outputs a video frame, if an ROI region (such as a face) is detected, the ROI information is written into the NativeBuffer metadata of the frame. You can directly extract it from each frame without additional callback APIs or timestamp matching. For details, see [OH_NativeBuffer_MetadataKey](../../reference/apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_metadatakey).

### Method 1: Configuring ROI via NativeBuffer Metadata (Recommended)

In surface mode, the camera outputs video frames to the surface of `OH_NativeImage`. In the frame processing thread, you extract ROI information from the NativeBuffer metadata of each frame, assemble it into a configuration string, and then write the ROI string into the NativeBuffer metadata of the encoder input frame, thereby delivering the ROI to the encoder frame by frame (as shown in figure 2).

**Figure 2: ROI configuration process via the NativeBuffer metadata API**

![ROI configuration process via the NativeBuffer metadata API](figures/roi-nativebuffer.png)

The development procedure is as follows:

1. Link dynamic libraries in `CMakeLists.txt`.

   <!-- @[roi_cmake_link_libraries](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/CMakeLists.txt) -->

   ``` Text
   set(BASE_LIBRARY
       libace_napi.z.so libEGL.so libGLESv3.so libace_ndk.z.so libuv.so libhilog_ndk.z.so
       libnative_media_codecbase.so libnative_media_core.so libnative_media_vdec.so libnative_window.so
       libnative_media_venc.so libnative_media_acodec.so libnative_media_avdemuxer.so libnative_media_avsource.so
       libnative_media_avmuxer.so libohaudio.so libnative_buffer.so libnative_vsync.so libnative_image.so libdeviceinfo_ndk.z.so
   )
   
   add_library(recorder SHARED recorder/RecorderNative.cpp
                               recorder/Recorder.cpp
                               capbilities/codec/Muxer.cpp
                               capbilities/codec/VideoEncoder.cpp
                               capbilities/codec/AudioCapturer.cpp
                               capbilities/codec/AudioEncoder.cpp
                               capbilities/codec/CodecCallback.cpp
                               capbilities/render/egl_render_context.cpp
                               capbilities/render/render_thread.cpp
                               capbilities/render/shader_program.cpp
                               common/RoiQueue.cpp
   )
   
   target_link_libraries(recorder PUBLIC ${BASE_LIBRARY} player)
   ```

   > **NOTE**
   >
   > The names **recorder** and **player** are examples only. Replace them with the actual target name of your CMake project.

2. Extract ROI information from the NativeBuffer metadata of the video frame.

   When the camera outputs a video frame, if an ROI region (such as a face) is detected, the ROI information is written into the NativeBuffer metadata of the frame. You can extract the raw ROI string through `OH_NativeBuffer_GetMetadataValue`.

   <!-- @[roi_buffer_roi_extraction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/render/render_thread.cpp) -->

   ``` C++
   OH_NativeBuffer *nativeBuffer = nullptr;
   int32_t ret = OH_NativeBuffer_FromNativeWindowBuffer(InBuffer, &nativeBuffer);
   if (ret == 0 && nativeBuffer != nullptr) {
       int32_t roiSize = 0;
       uint8_t *roiData = nullptr;
       ret = OH_NativeBuffer_GetMetadataValue(nativeBuffer,
           OH_NativeBuffer_MetadataKey::OH_REGION_OF_INTEREST_METADATA, &roiSize, &roiData);
       if (ret == 0 && roiData != nullptr && roiSize > 0) {
           return std::string(reinterpret_cast<char*>(roiData), roiSize);
       }
   }
   ```

   > **NOTE**
   >
   > `InBuffer` is the camera frame obtained from `OH_NativeImage` through `OH_NativeImage_AcquireNativeWindowBuffer`. The ROI information output by the camera has already been written into the metadata of this buffer. For details about NativeImage creation and the frame receiving mechanism, see [Surface Mode](video-encoding.md#surface-mode) in the video encoding development guide.

3. Use the `OH_VideoMetadata` API to assemble the ROI configuration string.

   The extracted raw ROI string contains region coordinate information. You need to use the `OH_VideoMetadata_GetRoiCount`, `OH_VideoMetadata_ParseRoiString`, and `OH_VideoMetadata_AppendRoiString` APIs to parse the raw ROI and append the DeltaQP parameter, generating a complete ROI configuration string (for example, `"100,50-300,200=dqp:-6"`).

   <!-- @[roi_buffer_roi_assembly](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/render/render_thread.cpp) -->

   ``` C++
   if (currentRoiStr.empty()) {
       return "";
   }
   uint32_t roiCount = 0;
   OH_AVErrCode roiRet = OH_VideoMetadata_GetRoiCount(currentRoiStr.c_str(), &roiCount);
   if (roiRet != AV_ERR_OK || roiCount == 0) {
       return "";
   }
   std::vector<OH_AVFormat*> parsedFormats(roiCount, nullptr);
   uint32_t actualCount = 0;
   roiRet = OH_VideoMetadata_ParseRoiString(currentRoiStr.c_str(), parsedFormats.data(),
                                            roiCount, &actualCount);
   if (roiRet != AV_ERR_OK || actualCount == 0) {
       return "";
   }
   char *assembledStr = nullptr;
   for (uint32_t i = 0; i < actualCount; i++) {
       if (parsedFormats[i] != nullptr) {
           OH_AVFormat_SetIntValue(parsedFormats[i], OH_MD_KEY_VIDEO_METADATA_ROI_DELTA_QP,
               ROI_DELTA_QP);
           OH_VideoMetadata_AppendRoiString(&assembledStr, parsedFormats[i]);
           OH_AVFormat_Destroy(parsedFormats[i]);
           parsedFormats[i] = nullptr;
       }
   }
   std::string result;
   if (assembledStr != nullptr) {
       result = std::string(assembledStr);
       free(assembledStr);
   }
   ```

   > **NOTE**
   >
   > `OH_VideoMetadata_AppendRoiString` internally performs memory expansion. The returned C-style string must be released by calling `free()`.

4. Write the ROI configuration string into the NativeBuffer metadata of the encoder input frame.

   In surface mode, the encoder receives video frames through the surface. You need to first request a buffer from the encoder surface through `OH_NativeWindow_NativeWindowRequestBuffer`, and then write the assembled ROI string into the NativeBuffer metadata of that buffer.

   <!-- @[roi_nativebuffer_metadata_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/render/render_thread.cpp) -->

   ``` C++
   OH_NativeBuffer *encoderNativeBuffer = nullptr;
   int32_t ret = OH_NativeBuffer_FromNativeWindowBuffer(OutBufferEncoder, &encoderNativeBuffer);
   if (ret == 0 && encoderNativeBuffer != nullptr) {
       int32_t roiStrSize = static_cast<int32_t>(assembledRoiStr.size());
       ret = OH_NativeBuffer_SetMetadataValue(encoderNativeBuffer,
           OH_NativeBuffer_MetadataKey::OH_REGION_OF_INTEREST_METADATA,
           roiStrSize, reinterpret_cast<uint8_t*>(const_cast<char*>(assembledRoiStr.data())));
       if (ret != 0) {
           OH_LOG_Print(LOG_APP, LOG_WARN, LOG_PRINT_DOMAIN, "RenderThread",
                        "OH_NativeBuffer_SetMetadataValue failed, ret: %{public}d", ret);
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "RenderThread",
                        "ROI metadata written to encoder buffer: %{public}s", assembledRoiStr.c_str());
       }
   }
   ```

   > **NOTE**
   >
   > When no ROI region is detected in the camera frame, `assembledRoiStr` is an empty string. The NativeBuffer metadata configuration method does not support empty strings. You need to write a string without position information (such as "Clear" or ";"). For details, see [Effectiveness Mechanism](#effectiveness-mechanism).

5. Submit the buffer to the encoder and release resources.

   After the ROI configuration is complete, submit the preview buffer and the encoder buffer through `OH_NativeWindow_NativeWindowFlushBuffer`, and release the camera frame resources.

   <!-- @[roi_surface_flush_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/render/render_thread.cpp) -->

   ``` C++
   void RenderThread::FlushAndCleanup(OHNativeWindowBuffer *InBuffer, int32_t fenceFd1,
       OHNativeWindowBuffer *OutBuffer, OHNativeWindowBuffer *OutBufferEncoder)
   {
       OH_NativeWindow_NativeObjectUnreference(InBuffer);
       OH_NativeImage_ReleaseNativeWindowBuffer(nativeImage_, InBuffer, fenceFd1);
   
       Region region{nullptr, 0};
       int acquireFenceFd = -1;
       OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow_, OutBuffer, acquireFenceFd, region);
       if (OutBufferEncoder != nullptr) {
           OH_NativeWindow_NativeWindowFlushBuffer(encoderNativeWindow_, OutBufferEncoder, acquireFenceFd, region);
       }
   }
   ```

### Method 2: Configuring ROI via the Encoding Input Parameter Callback

This method is also applicable to Surface mode. ROI information is extracted from the NativeBuffer metadata of the frame, and the configuration is completed through the encoding input parameter callback registered via `OH_VideoEncoder_RegisterParameterCallback` (as shown in figure 3).

The encoder triggers the parameter callback when receiving a video frame. Since the parameter callback does not include frame timestamp information, you need to use a synchronization queue (RoiQueue) keyed by PTS (timestamp) to pass the ROI data from the frame processing thread to the encoding callback in chronological order. In the callback, the ROI entry with the smallest PTS is popped from the queue and configured into the parameter format through `OH_AVFormat_SetStringValue`.

**Figure 3: ROI configuration process via the encoding input parameter callback API**

![ROI configuration process via the encoding input parameter callback API](figures/roi-input-param-callback.png)

The development procedure is as follows:

1. Link dynamic libraries in **CMakeList.txt**.

   Same as step 1 in [Method 1: Configuring ROI via NativeBuffer Metadata (Recommended)](#method-1-configuring-roi-via-nativebuffer-metadata-recommended).

2. Extract ROI information from the NativeBuffer metadata of the video frame.

   Same as step 2 in [Method 1: Configuring ROI via NativeBuffer Metadata (Recommended)](#method-1-configuring-roi-via-nativebuffer-metadata-recommended).

3. Use the OH_VideoMetadata API to assemble the ROI configuration string.

   Same as step 3 in [Method 1: Configuring ROI via NativeBuffer Metadata (Recommended)](#method-1-configuring-roi-via-nativebuffer-metadata-recommended).

4. Implement the PTS synchronization queue and callback user data structure.

   Since the parameter callback does not include frame timestamp information, ROI data cannot be directly aligned with encoding frames. It is recommended to implement a synchronization queue keyed by PTS to pass the ROI data from the frame processing thread to the encoding callback in PTS order. The encoding callback accesses the queue through the queue pointer in the user data structure, popping the entry with the smallest PTS to obtain the ROI configuration string.

   `CodecUserRoi` is a nested structure defined inside the VideoEncoder class, containing a queue pointer for direct access by the callback.

   <!-- @[roi_user_data_struct](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/codec/include/VideoEncoder.h) -->

   ``` C
   // User data structure for parameter callback configuration.
   struct CodecUserRoi {
       VideoEncoder* vencoder = nullptr;
       RoiQueue* roiQueue = nullptr;
   };
   ```

5. Register the encoding input parameter callback.

   After creating the encoder and before calling `Configure`, register the encoding input parameter callback. It must be registered before `Configure`; otherwise, the callback will not take effect.

   <!-- @[roi_register_parameter_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/codec/VideoEncoder.cpp) -->

   ``` C++
   // Parameter callback configuration: register the parameter callback before Configure.
   if (roiPathType_ == ROI_PATH_METADATA_CALLBACK) {
       userData_ = std::make_unique<CodecUserRoi>();
       if (userData_) {
           userData_->vencoder = this;
           userData_->roiQueue = &roiQueue_;
       }
       int32_t ret = OH_VideoEncoder_RegisterParameterCallback(encoder_, OnNeedInputParameter, userData_.get());
       CHECK_AND_RETURN_RET_LOG(ret == AV_ERR_OK, SAMPLE_ERR_ERROR,
                                "OH_VideoEncoder_RegisterParameterCallback failed, ret: %{public}d", ret);
       SAMPLE_LOGI("Parameter callback configuration: ROI parameter callback registered.");
   }
   ```

   > **NOTE**
   >
   > `OH_VideoEncoder_RegisterParameterCallback` must be called before `OH_VideoEncoder_Configure`. After the callback is registered, the `OnNeedInputParameter` callback is triggered each time the encoder receives a frame of input data.

6. Configure ROI information in the encoding input parameter callback.

   When the encoder receives input data, the `OnNeedInputParameter` callback is triggered. In the callback, pop the ROI entry with the smallest PTS from the RoiQueue, and configure it into the parameter format through `OH_AVFormat_SetStringValue`. An empty string must also be configured into the encoding parameters to explicitly indicate that no ROI region is configured for the frame.

   <!-- @[roi_encode_parameter_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/codec/VideoEncoder.cpp) -->

   ``` C++
   static void OnNeedInputParameter(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter, void *userData)
   {
       auto *roiUserData = static_cast<VideoEncoder::CodecUserRoi *>(userData);
       if (!roiUserData || !roiUserData->roiQueue) {
           OH_VideoEncoder_PushInputParameter(codec, index);
           return;
       }
   
       std::string roiStr = roiUserData->roiQueue->Pop();
       OH_AVFormat_SetStringValue(parameter, OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS, roiStr.c_str());
       if (!roiStr.empty()) {
           SAMPLE_LOGI("ROI configured (parameter callback path): %{public}s", roiStr.c_str());
       }
       OH_VideoEncoder_PushInputParameter(codec, index);
   }
   ```

7. Pass the assembled ROI string together with the frame PTS to the RoiQueue of VideoEncoder.

   After extracting and assembling the ROI string in the frame processing thread, you need to push the ROI string into the RoiQueue of VideoEncoder, indexed by PTS. The RoiQueue is sorted by PTS to ensure that the encoding callback obtains ROI data in frame order, avoiding misalignment.

   <!-- @[roi_parameter_callback_str_passing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/render/render_thread.cpp) -->

   ``` C++
   int64_t pts = OH_NativeImage_GetTimestamp(nativeImage_);
   if (roiPathType_ == ROI_PATH_METADATA_CALLBACK && onRoiStrAssembled_) {
       onRoiStrAssembled_(pts, assembledRoiStr);
   }
   ```

   VideoEncoder pushes ROI data into the RoiQueue:

   <!-- @[roi_parameter_callback_queue_storage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/codec/VideoEncoder.cpp) -->

   ``` C++
   // Parameter callback configuration: Push ROI entries into RoiQueue by PTS.
   void VideoEncoder::PushRoiEntry(int64_t pts, const std::string &roiStr)
   {
       roiQueue_.Push(pts, roiStr);
   }
   
   // Parameter callback configuration: Clear RoiQueue when ROI is disabled.
   void VideoEncoder::ClearRoiQueue()
   {
       roiQueue_.Clear();
   }
   ```

> **NOTE**
>
> The RoiQueue stores ROI entries sorted by PTS. The encoding callback retrieves the entry with the smallest PTS to ensure the order consistency between frames and ROI data. If the queue is empty, it waits for up to 3 ms before returning an empty string. The queue automatically cleans up stale entries older than 2 seconds to prevent unbounded growth. The ROI string (including an empty ROI string) must be enqueued for each frame. An empty ROI string is used to explicitly indicate that no ROI region is configured for the frame. When disabling ROI, call `ClearRoiQueue` to clear the queue.

### Method 3: Configuring ROI in Buffer Mode

In buffer mode, video frames are sent to the encoder through `OH_VideoEncoder_PushInputBuffer`. You need to configure ROI information while filling frame pixel data in the `OnNeedInputBuffer` callback. Since there is no encoder surface in buffer mode, the frame pixel data must be copied from the camera frame buffer and pushed into the frame queue together with the ROI string for consumption by the encoding callback (as shown in figure 4).

**Figure 4: ROI configuration process via the encoding input buffer callback API**

![ROI configuration process via the encoding input buffer callback API](figures/roi-input-buffer-callback.png)

The detailed development procedure is as follows:

1. Link dynamic libraries in `CMakeList.txt`.

   Same as step 1 in [Method 1: Configuring ROI via NativeBuffer Metadata (Recommended)](#method-1-configuring-roi-via-nativebuffer-metadata-recommended).

2. Extract ROI information from the NativeBuffer metadata of the video frame.

   Same as step 2 in [Method 1: Configuring ROI via NativeBuffer Metadata (Recommended)](#method-1-configuring-roi-via-nativebuffer-metadata-recommended).

3. Use the OH_VideoMetadata API to assemble the ROI configuration string.

   Same as step 3 in [Method 1: Configuring ROI via NativeBuffer Metadata (Recommended)](#method-1-configuring-roi-via-nativebuffer-metadata-recommended).

4. Define the frame data structure and frame queue.

   In Buffer mode, the encoder requests input buffers through callbacks. You need to encapsulate the pixel data of the camera frame and the ROI string into a frame data item, and push it into a thread-safe frame queue for consumption by the encoding callback.

   <!-- @[roi_frame_item_struct](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/common/FrameQueue.h) -->

   ``` C
   // Frame data item for Buffer mode encoding.
   constexpr uint32_t FRAME_QUEUE_POP_TIMEOUT_MS = 4;
   constexpr size_t FRAME_QUEUE_MAX_SIZE = 3;
   
   struct FrameItem {
       std::vector<uint8_t> pixels;
       int32_t width = 0;
       int32_t height = 0;
       std::string roiStr;
   };
   ```

5. Push the frame pixel data and ROI string into the frame queue.

   In the frame processing thread, read the pixel data from the camera frame buffer and push it into the frame queue together with the assembled ROI string.

   <!-- @[roi_buffer_pixel_read](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/render/render_thread.cpp) -->

   ``` C++
   // Buffer mode: Read pixel data from the camera frame and push it into the frame queue.
   BufferHandle *bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(InBuffer);
   if (bufferHandle == nullptr) {
       return;
   }
   OH_NativeBuffer *cameraNativeBuffer = nullptr;
   int32_t ret = OH_NativeBuffer_FromNativeWindowBuffer(InBuffer, &cameraNativeBuffer);
   if (ret != 0 || cameraNativeBuffer == nullptr) {
       return;
   }
   void *virAddr = nullptr;
   ret = OH_NativeBuffer_Map(cameraNativeBuffer, &virAddr);
   if (ret != 0 || virAddr == nullptr) {
       return;
   }
   int32_t frameWidth = bufferHandle->width;
   int32_t frameHeight = bufferHandle->height;
   int32_t stride = bufferHandle->stride;
   int32_t frameSize = stride * frameHeight;
   FrameItem frameItem;
   frameItem.width = frameWidth;
   frameItem.height = frameHeight;
   frameItem.roiStr = assembledRoiStr;
   frameItem.pixels.resize(frameSize);
   std::copy(static_cast<uint8_t *>(virAddr),
             static_cast<uint8_t *>(virAddr) + frameSize,
             frameItem.pixels.data());
   frameQueue_->Push(frameItem);
   OH_NativeBuffer_Unmap(cameraNativeBuffer);
   OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "RenderThread",
                ""Buffer mode: pushed frame to queue, size: %{public}d, ROI: %{public}s"",
                frameSize, assembledRoiStr.c_str());
   ```

   > **NOTE**
   >
   > Buffer mode requires copying pixel data from the camera frame buffer to the app memory, which incurs additional data copy overhead and results in higher latency compared to the zero-copy mechanism of Surface mode. You should choose the appropriate encoding mode based on your actual scenario.

6. Configure ROI information in the encoding input buffer callback.

   When the encoder requests an input buffer, the `OnNeedInputBuffer` callback is triggered. In the callback, the buffer is enqueued for processing by the consumer thread. The consumer thread in Buffer mode retrieves the buffer from the queue, calls `FillBufferModeInput` to pop a frame data item from the frame queue, copies the pixel data into the encoder buffer, and sets the ROI string after obtaining the format through `OH_AVBuffer_GetParameter`.

   The `OnNeedInputBuffer` callback enqueues the buffer for processing by the consumer thread as follows:

   <!-- @[roi_buffer_input_callback_queue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/capbilities/codec/CodecCallback.cpp) -->

   ``` C++
   void CodecCallback::OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
   {
       if (userData == nullptr) {
           return;
       }
       CodecUserData *codecUserData = static_cast<CodecUserData *>(userData);
       std::unique_lock<std::mutex> lock(codecUserData->inputMutex);
       codecUserData->inputBufferInfoQueue.emplace(index, buffer);
       codecUserData->inputCond.notify_all();
   }
   ```

   The following example shows how the consumer thread in Buffer mode retrieves a buffer from the queue and calls `FillBufferModeInput` to fill the frame data and ROI:

   <!-- @[roi_buffer_mode_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/recorder/Recorder.cpp) -->

   ``` C++
   void Recorder::VideoEncBufferInputThread()
   {
       while (isStarted_) {
           CHECK_AND_BREAK_LOG(isStarted_, "Work done, thread out");
           std::unique_lock<std::mutex> lock(encContext_->inputMutex);
           bool condRet = encContext_->inputCond.wait_for(
               lock, std::chrono::seconds(THREAD_WAIT_TIMEOUT_SEC),
               [this]() { return !isStarted_ || !encContext_->inputBufferInfoQueue.empty(); });
           CHECK_AND_BREAK_LOG(isStarted_, "Work done, thread out");
           CHECK_AND_CONTINUE_LOG(!encContext_->inputBufferInfoQueue.empty(),
               "Buffer queue is empty, continue, cond ret: %{public}d", condRet);
   
           CodecBufferInfo bufferInfo = encContext_->inputBufferInfoQueue.front();
           encContext_->inputBufferInfoQueue.pop();
           lock.unlock();
   
           OH_AVBuffer *buffer = reinterpret_cast<OH_AVBuffer *>(bufferInfo.buffer);
           FillBufferModeInput(bufferInfo.bufferIndex, buffer);
       }
   }
   ```

   The implementation of `FillBufferModeInput` is as follows:

   <!-- @[roi_buffer_mode_fill_input](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVCodec/ROISample/entry/src/main/cpp/recorder/Recorder.cpp) -->

   ``` C++
   void Recorder::FillBufferModeInput(uint32_t index, OH_AVBuffer *buffer)
   {
       FrameItem frameItem;
       if (!encContext_->frameQueue->Pop(frameItem, std::chrono::milliseconds(FRAME_QUEUE_POP_TIMEOUT_MS))) {
           OH_VideoEncoder_PushInputBuffer(videoEncoder_->GetCodec(), index);
           return;
       }
       uint8_t *bufferAddr = OH_AVBuffer_GetAddr(buffer);
       int32_t bufferCapacity = OH_AVBuffer_GetCapacity(buffer);
       if (bufferAddr != nullptr && bufferCapacity >= static_cast<int32_t>(frameItem.pixels.size())) {
           std::copy(frameItem.pixels.data(), frameItem.pixels.data() + frameItem.pixels.size(), bufferAddr);
           OH_AVCodecBufferAttr attr;
           attr.size = static_cast<int32_t>(frameItem.pixels.size());
           attr.offset = 0;
           attr.flags = AVCODEC_BUFFER_FLAGS_NONE;
           OH_AVBuffer_SetBufferAttr(buffer, &attr);
       }
       if (!frameItem.roiStr.empty()) {
           OH_AVFormat *format = OH_AVBuffer_GetParameter(buffer);
           if (format != nullptr) {
               OH_AVFormat_SetStringValue(format, OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS, frameItem.roiStr.c_str());
           }
       }
       OH_VideoEncoder_PushInputBuffer(videoEncoder_->GetCodec(), index);
   }
   ```