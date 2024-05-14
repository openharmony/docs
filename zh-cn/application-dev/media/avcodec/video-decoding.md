# 视频解码

开发者可以调用本模块的Native API接口，完成视频解码，即将媒体数据解码成YUV文件或送显。

当前支持的解码能力如下：

| 视频硬解类型       | 视频软解类型   |
| --------------------- | ---------------- |
| AVC(H.264)、HEVC(H.265) |AVC(H.264) |

<!--RP1-->
视频解码软/硬件解码存在差异，基于MimeType创建解码器时，软解当前仅支持 H264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC)，硬解则支持 H264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) 和 H265 (OH_AVCODEC_MIMETYPE_VIDEO_HEVC)。
<!--RP1End-->

## Surface输出与Buffer输出

两者数据的输出方式不同。

Surface输出是指用OHNativeWindow来传递输出数据，可以与其他模块对接，例如XComponent。

Buffer输出是指经过解码的数据会以共享内存的方式输出。

在接口调用的过程中，两种方式的接口调用方式基本一致，但存在以下差异点：

1. 在Surface模式下，可选择调用OH_VideoDecoder_FreeOutputBuffer()接口丢弃输出帧（不送显）；在Buffer模式下，应用必须调用OH_VideoDecoder_FreeOutputBuffer()释放数据。
2. Surface模式下，应用在解码器就绪前，必须调用OH_VideoDecoder_SetSurface()设置OHNativeWindow，启动后，调用OH_VideoDecoder_RenderOutputBuffer()将解码数据送显；
3. 输出回调传出的buffer，在Buffer模式下，可以获取共享内存的地址和数据信息；在Surface模式下，只能获取buffer的数据信息。

两种模式的开发步骤详细说明请参考：[Surface模式](#surface模式)和[Buffer模式](#buffer模式)。

## 开发指导

详细的API说明请参考[API文档](../../reference/apis-avcodec-kit/_video_decoder.md)。
如下为视频解码调用关系图：
![Invoking relationship of video decode stream](figures/video-decode.png)

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_vdec.so)
```

### Surface模式

参考以下示例代码，开发者可以完成Surface模式下视频解码的全流程。此处以H.264码流文件输入，解码送显输出为例。
本模块目前仅支持异步模式的数据轮转。

1. 添加头文件。

    ```c++
    #include <multimedia/player_framework/native_avcodec_videodecoder.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    #include <multimedia/player_framework/native_avbuffer.h>
    #include <fstream>
    ```

2. 创建解码器实例对象。

    应用可以通过名称或媒体类型创建解码器。示例中的变量说明如下：

    - videoDec：视频解码器实例的指针。
    - capability：解码器能力查询实例的指针。
    - OH_AVCODEC_MIMETYPE_VIDEO_AVC：AVC格式视频码流的名称。

    ```c++
    // 通过codecname创建解码器，应用有特殊需求，比如选择支持某种分辨率规格的解码器，可先查询capability，再根据codec name创建解码器。
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(name);
    ```

    ```c++
    // 通过mimetype创建解码器
    // 软/硬解: 创建H264解码器，存在多个可选解码器时，系统会创建最合适的解码器
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
    // 硬解: 创建H265解码器
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_HEVC);
    ```

3. 调用OH_VideoDecoder_RegisterCallback()设置回调函数。

    > **说明：**
    >
    > 在回调函数中，对数据队列进行操作时，需要注意多线程同步的问题。
    >

    注册回调函数指针集合OH_AVCodecCallback，包括：

    - 解码器运行错误；
    - 码流信息变化，如码流宽、高变化；
    - 运行过程中需要新的输入数据，即解码器已准备好，可以输入数据；
    - 运行过程中产生了新的输出数据，即解码完成。(注：Surface模式buffer参数为空)

    开发者可以通过处理该回调报告的信息，确保解码器正常运转。

    ```c++
    // 解码异常回调OH_AVCodecOnError实现
    static void OnError(OH_AVCodec *codec, int32_t errorCode, void *userData)
    {
        // 回调的错误码由用户判断处理
        (void)codec;
        (void)errorCode;
        (void)userData;
    }

    // 解码数据流变化回调OH_AVCodecOnStreamChanged实现
    static void OnStreamChanged(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
    {
        // 可通过format获取到变化后的视频宽、高、跨距等
        (void)codec;
        (void)format;
        (void)userData;
    }

    // 解码输入回调OH_AVCodecOnNeedInputBuffer实现
    static void OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        // 输入帧buffer对应的index，送入InIndexQueue队列
        // 输入帧的数据buffer送入InBufferQueue队列
        // 数据处理，请参考:
        // - 写入解码码流
    }

    // 解码输出回调OH_AVCodecOnNewOutputBuffer实现
    static void OnNewOutputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        // 完成帧buffer对应的index，送入outIndexQueue队列
        // 完成帧的数据buffer送入outBufferQueue队列
        // 数据处理，请参考:
        // - 显示并释放解码帧
    }
    // 配置异步回调，调用 OH_VideoDecoder_RegisterCallback 接口
    OH_AVCodecCallback cb = {&OnError, &OnStreamChanged, &OnNeedInputBuffer, &OnNewOutputBuffer};
    // 配置异步回调
    int32_t ret = OH_VideoDecoder_RegisterCallback(videoDec, cb, NULL);
    ```

4. 调用OH_VideoDecoder_Configure()配置解码器。

    详细可配置选项的说明请参考[视频专有键值对](../../reference/apis-avcodec-kit/_codec_base.md#媒体数据键值对)。
    
    参数校验规则请参考[OH_VideoDecoder_Configure() 参考文档](../../reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_configure)。
    
    目前支持的所有格式都必须配置以下选项：视频帧宽度、视频帧高度。示例中的变量如下：

    - DEFAULT_WIDTH：320像素宽度；
    - DEFAULT_HEIGHT：240像素高度；
    - DEFAULT_PIXELFORMAT： 颜色格式，因为示例需要保存的YUV文件颜色格式是NV12，所以设置为 AV_PIXEL_FORMAT_NV12。

    ```c++
    // 配置视频帧宽度（必须）
    constexpr int32_t DEFAULT_WIDTH = 320; 
    // 配置视频帧高度（必须）
    constexpr int32_t DEFAULT_HEIGHT = 240;
    // 配置视频颜色格式（必须）
    constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;

    OH_AVFormat *format = OH_AVFormat_Create();
    // 写入format
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, DEFAULT_WIDTH);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, DEFAULT_HEIGHT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, DEFAULT_PIXELFORMAT);
    // 配置解码器
    int32_t ret = OH_VideoDecoder_Configure(videoDec, format);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    OH_AVFormat_Destroy(format);
    ```

5. 设置Surface。本例中的nativeWindow，需要从XComponent组件获取，获取方式请参考 [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)。

    Surface模式，开发者可以在解码过程中执行该步骤，即动态切换Surface。

    ```c++
    // 配置送显窗口参数
    int32_t ret = OH_VideoDecoder_SetSurface(videoDec, window);    // 从 XComponent 获取 window
    ```

6. （可选）OH_VideoDecoder_SetParameter()动态配置解码器surface参数。
    详细可配置选项的说明请参考[视频专有键值对](../../reference/apis-avcodec-kit/_codec_base.md#媒体数据键值对)。

    ```c++
    OH_AVFormat *format = OH_AVFormat_Create();
    // 配置显示旋转角度
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_ROTATION, 90);
    // 配置视频与显示屏匹配模式（缩放与显示窗口适配，裁剪与显示窗口适配）
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_SCALING_MODE, SCALING_MODE_SCALE_CROP);
    int32_t ret = OH_VideoDecoder_SetParameter(videoDec, format);
    OH_AVFormat_Destroy(format);
    ```
7. （可选）OH_VideoDecoder_SetDecryptionConfig设置解密配置。当获取到DRM信息(参考[音视频解封装](audio-video-demuxer.md)开发步骤第3步)后，通过此接口进行解密配置。DRM相关接口详见[DRM API文档](../../reference/apis-drm-kit/_drm.md)。此接口需在Prepare前调用。

    添加头文件

    ```c++
    #include <multimedia/drm_framework/native_mediakeysystem.h>
    #include <multimedia/drm_framework/native_mediakeysession.h>
    #include <multimedia/drm_framework/native_drm_err.h>
    #include <multimedia/drm_framework/native_drm_common.h>
    ```
    在 CMake 脚本中链接动态库

    ``` cmake
    target_link_libraries(sample PUBLIC libnative_drm.so)
    ```

    使用示例
    ```c++
    // 根据DRM信息创建指定的DRM系统, 以创建"com.clearplay.drm"为例
    MediaKeySystem *system = nullptr;
    int32_t ret = OH_MediaKeySystem_Create("com.clearplay.drm", &system);
    if (system == nullptr) {
        printf("create media key system failed");
        return;
    }
    // 进行Provision认证
    // 创建解密会话
    MediaKeySession *session = nullptr;
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO;
    ret = OH_MediaKeySystem_CreateMediaKeySession(system, &contentProtectionLevel, &session);
    if (session == nullptr) {
        printf("create media key session failed");
        return;
    }
    // 获取许可证请求、设置许可证响应等
    // 设置解密配置, 即将解密会话、安全视频通路标志设置到解码器中。
    bool secureVideoPath = false;
    ret = OH_VideoDecoder_SetDecryptionConfig(videoDec, session, secureVideoPath);
    ```

8. 调用OH_VideoDecoder_Prepare()解码器就绪。

    该接口将在解码器运行前进行一些数据的准备工作。

    ```c++
    ret = OH_VideoDecoder_Prepare(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

9. 调用OH_VideoDecoder_Start()启动解码器。

    ```c++
    std::string_view inputFilePath = "/*yourpath*.h264";
    std::unique_ptr<std::ifstream> inputFile = std::make_unique<std::ifstream>();
    inputFile->open(inputFilePath.data(), std::ios::in | std::ios::binary); 
    // 启动解码器，开始解码
    int32_t ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

10. 调用OH_VideoDecoder_PushInputBuffer()写入解码码流。

    送入输入队列进行解码，以下示例中：

    - buffer：回调函数OnNeedInputBuffer传入的参数，可以通过OH_AVBuffer_GetAddr接口得到共享内存地址的指针；
    - index：回调函数OnNeedInputBuffer传入的参数，数据队列的索引；
    - size, offset, pts：输入尺寸、偏移量、时间戳等字段信息，获取方式可以参考[音视频解封装](./audio-video-demuxer.md)
    - flags：缓冲区标记的类别，请参考[OH_AVCodecBufferFlags](../../reference/apis-avcodec-kit/_core.md#oh_avcodecbufferflags)

    ```c++
    // 配置帧数据的输入尺寸、偏移量、时间戳等字段信息
    OH_AVCodecBufferAttr info;
    info.size = size;
    info.offset = offset;
    info.pts = pts;
    info.flags = flags;
    // info信息写入buffer
    int32_t ret = OH_AVBuffer_SetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 送入解码输入队列进行解码，index为对应队列下标
    ret = OH_VideoDecoder_PushInputBuffer(videoDec, index);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

11. 调用OH_VideoDecoder_RenderOutputBuffer()显示并释放解码帧，或调用OH_VideoDecoder_FreeOutputBuffer()释放解码帧。
    以下示例中：

    - index：回调函数OnNewOutputBuffer传入的参数，数据队列的索引。
    - buffer： 回调函数OnNewOutputBuffer传入的参数，可以通过OH_AVBuffer_GetAddr接口得到共享内存地址的指针。

    ```c++
    // 获取解码后信息
    OH_AVCodecBufferAttr info;
    int32_t ret = OH_AVBuffer_GetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 值由调用者决定
    bool isRender;
    if (isRender) {
        // 显示并释放已完成处理的信息，index为对应buffer队列下标
        ret = OH_VideoDecoder_RenderOutputBuffer(videoDec, index);
    } else {
        // 释放已完成处理的信息
        ret = OH_VideoDecoder_FreeOutputBuffer(videoDec, index);
    }
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

12. （可选）调用OH_VideoDecoder_Flush()刷新解码器。

    > **注意：**
    >
    > Flush、Start之后，需要重新传XPS。
    >

    调用OH_VideoDecoder_Flush()后，解码器仍处于运行态，但会将当前队列清空，将已解码的数据释放。

    此时需要调用OH_VideoDecoder_Start()重新开始解码。

    ```c++
    // 刷新解码器videoDec
    int32_t ret = OH_VideoDecoder_Flush(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 重新开始解码
    ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

13. （可选）调用OH_VideoDecoder_Reset()重置解码器。

    调用OH_VideoDecoder_Reset()后，解码器回到初始化的状态，需要调用OH_VideoDecoder_Configure()、OH_VideoDecoder_SetSurface()重新配置。

    ```c++
    // 重置解码器videoDec
    int32_t ret = OH_VideoDecoder_Reset(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 重新配置解码器参数
    ret = OH_VideoDecoder_Configure(videoDec, format);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // surface模式重新配置Surface，而buffer模式不需要配置Surface
    ret = OH_VideoDecoder_SetSurface(videoDec, window);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

14. （可选）调用OH_VideoDecoder_Stop()停止解码器。

    ```c++
    // 终止解码器videoDec
    int32_t ret = OH_VideoDecoder_Stop(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

15. 调用OH_VideoDecoder_Destroy()销毁解码器实例，释放资源。

    > **说明：**
    >
    > 不能在回调函数中调用；
    > 执行该步骤之后，需要开发者将videoDec指向nullptr，防止野指针导致程序错误。
    >

    ```c++
    // 调用OH_VideoDecoder_Destroy，注销解码器
    int32_t ret = OH_VideoDecoder_Destroy(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

### Buffer模式

参考以下示例代码，开发者可以完成Buffer模式下视频解码的全流程。此处以H.264文件输入，解码成YUV文件为例。
本模块目前仅支持异步模式的数据轮转。

1. 添加头文件。

    ```c++
    #include <multimedia/player_framework/native_avcodec_videodecoder.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    #include <multimedia/player_framework/native_avbuffer.h>
    #include <native_buffer/native_buffer.h>
    #include <fstream>
    ```

2. 创建解码器实例对象。

    与surface模式相同，此处不再赘述。

    ```c++
    // 通过codecname创建解码器，应用有特殊需求，比如选择支持某种分辨率规格的解码器，可先查询capability，再根据codec name创建解码器。
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(name);
    ```

    ```c++
    // 通过mimetype创建解码器
    // 软/硬解: 创建H264解码器，存在多个可选解码器时，系统会创建最合适的解码器
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
    // 硬解: 创建H265解码器
    OH_AVCodec *videoDec = OH_VideoDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_HEVC);
    ```

3. 调用OH_VideoDecoder_RegisterCallback()设置回调函数。

    > **说明：**
    >
    > 在回调函数中，对数据队列进行操作时，需要注意多线程同步的问题。
    >

    注册回调函数指针集合OH_AVCodecCallback，包括：

    - 解码器运行错误；
    - 码流信息变化，如码流宽、高变化；
    - 运行过程中需要新的输入数据，即解码器已准备好，可以输入数据；
    - 运行过程中产生了新的输出数据，即解码完成。

    开发者可以通过处理该回调报告的信息，确保解码器正常运转。

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
    // 解码异常回调OH_AVCodecOnError实现
    static void OnError(OH_AVCodec *codec, int32_t errorCode, void *userData)
    {
        // 回调的错误码由用户判断处理
        (void)codec;
        (void)errorCode;
        (void)userData;
    }
    
    // 解码数据流变化回调OH_AVCodecOnStreamChanged实现
    static void OnStreamChanged(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
    {
        // 可通过format获取到变化后的视频宽、高、跨距等
        (void)codec;
        (void)userData;
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_WIDTH, width);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_HEIGHT, height);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_STRIDE, widthStride);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_SLICE_HEIGHT, heightStride);
        // 获取裁剪矩形信息可选
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_TOP, cropTop);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_BOTTOM, cropBottom);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_LEFT, cropLeft);
        OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_RIGHT, cropRight);
    }
    
    // 解码输入回调OH_AVCodecOnNeedInputBuffer实现
    static void OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        // 输入帧buffer对应的index，送入InIndexQueue队列
        // 输入帧的数据buffer送入InBufferQueue队列
        // 数据处理，请参考:
        // - 写入解码码流
    }
    
    // 解码输出回调OH_AVCodecOnNewOutputBuffer实现
    static void OnNewOutputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        // 完成帧buffer对应的index，送入outIndexQueue队列
        // 完成帧的数据buffer送入outBufferQueue队列
        // 获取视频宽、高、跨距
        if (isFirstFrame) {
            OH_AVFormat *format = OH_VideoDecoder_GetOutputDescription(codec);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_WIDTH, width);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_HEIGHT, height);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_STRIDE, widthStride);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_SLICE_HEIGHT, heightStride);
            // 获取裁剪矩形信息可选
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_TOP, cropTop);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_BOTTOM, cropBottom);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_LEFT, cropLeft);
            OH_AVFormat_GetIntValue(format, OH_MD_KEY_VIDEO_CROP_RIGHT, cropRight);
            OH_AVFormat_Destroy(format);
            isFirstFrame = false;
        }
        // 数据处理，请参考:
        // - 释放解码帧
    }
    // 配置异步回调，调用OH_VideoDecoder_RegisterCallback接口
    OH_AVCodecCallback cb = {&OnError, &OnStreamChanged, &OnNeedInputBuffer, &OnNewOutputBuffer};
    // 配置异步回调
    int32_t ret = OH_VideoDecoder_RegisterCallback(videoDec, cb, NULL);
    ```

4. 调用OH_VideoDecoder_Configure()配置解码器。

    与surface模式相同，此处不再赘述。

    ```c++
    // 配置视频帧宽度（必须）
    constexpr int32_t DEFAULT_WIDTH = 320; 
    // 配置视频帧高度（必须）
    constexpr int32_t DEFAULT_HEIGHT = 240;
    // 配置视频颜色格式（必须）
    constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;

    OH_AVFormat *format = OH_AVFormat_Create();
    // 写入format
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, DEFAULT_WIDTH);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, DEFAULT_HEIGHT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, DEFAULT_PIXELFORMAT);
    // 配置解码器
    int32_t ret = OH_VideoDecoder_Configure(videoDec, format);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    OH_AVFormat_Destroy(format);
    ```

5. 调用OH_VideoDecoder_Prepare()解码器就绪。

    该接口将在解码器运行前进行一些数据的准备工作。

    ```c++
    int32_t ret = OH_VideoDecoder_Prepare(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

6. 调用OH_VideoDecoder_Start()启动解码器。

    ```c++
    std::string_view inputFilePath = "/*yourpath*.h264";
    std::string_view outputFilePath = "/*yourpath*.yuv";
    std::unique_ptr<std::ifstream> inputFile = std::make_unique<std::ifstream>();
    std::unique_ptr<std::ofstream> outputFile = std::make_unique<std::ofstream>();
    inputFile->open(inputFilePath.data(), std::ios::in | std::ios::binary); 
    outputFile->open(outputFilePath.data(), std::ios::out | std::ios::binary | std::ios::ate);
    // 启动解码器，开始解码
    int32_t ret = OH_VideoDecoder_Start(videoDec);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

7. 调用OH_VideoDecoder_PushInputBuffer()写入解码码流。

    与surface模式相同，此处不再赘述。

    ```c++
    // 配置帧数据的输入尺寸、偏移量、时间戳等字段信息
    OH_AVCodecBufferAttr info;
    info.size = size;
    info.offset = offset;
    info.pts = pts;
    info.flags = flags;
    // info信息写入buffer
    ret = OH_AVBuffer_SetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 送入解码输入队列进行解码，index为对应队列下标
    int32_t ret = OH_VideoDecoder_PushInputBuffer(videoDec, index);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

8. 调用OH_VideoDecoder_FreeOutputBuffer()释放解码帧。

    以下示例中：

    - index：回调函数OnNewOutputBuffer传入的参数，数据队列的索引。
    - buffer： 回调函数OnNewOutputBuffer传入的参数，可以通过OH_AVBuffer_GetAddr接口得到共享内存地址的指针。

    ```c++
    // 获取解码后信息
    OH_AVCodecBufferAttr info;
    int32_t ret = OH_AVBuffer_GetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 将解码完成数据data写入到对应输出文件中
    outputFile->write(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(buffer)), info.size);
    // buffer 模式，释放已完成写入的数据，index为对应buffer队列下标
    ret = OH_VideoDecoder_FreeOutputBuffer(videoDec, index);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```

    硬件解码在处理buffer数据时（释放数据前），一般需要获取数据的宽高、跨距、像素格式来保证解码输出数据被正确的处理，请参考图形子系统 [OH_NativeBuffer](../../reference/apis-arkgraphics2d/_o_h___native_buffer.md)。

    ```c++
    // OH_NativeBuffer *可以通过图形模块的接口可以获取数据的宽高、跨距等信息。
    OH_NativeBuffer *ohNativeBuffer = OH_AVBuffer_GetNativeBuffer(buffer);
    if (ohNativeBuffer != nullptr) {
        // 获取OH_NativeBuffer_Config结构体，包含OH_NativeBuffer的数据信息
        OH_NativeBuffer_Config config;
        OH_NativeBuffer_GetConfig(ohNativeBuffer, &config);

        // 释放ohNativeBuffer
        ret = OH_NativeBuffer_Unreference(ohNativeBuffer);
        if (ret != AV_ERR_OK) {
            // 异常处理
        }
        ohNativeBuffer = nullptr;
    }
    ```

后续流程（包括刷新解码器、重置解码器、停止解码器、销毁解码器）与Surface模式基本一致，请参考[Surface模式](#surface模式)的步骤11-14。
