# 音频解码(C/C++)

开发者可以调用本模块的Native API接口，完成音频解码，即将媒体数据解码为PCM码流。

当前支持的解码能力如下:

| 容器规格 | 音频解码类型                 |
| -------- | :--------------------------- |
| mp4      | AAC、MPEG(MP3)、Flac、Vorbis |
| m4a      | AAC                          |
| flac     | Flac                         |
| ogg      | Vorbis                       |
| aac      | AAC                          |
| mp3      | MPEG(MP3)                    |
| amr      | AMR(amrnb、amrwb)            |
| raw      | G711mu                       |

**适用场景**

- 音频播放

  在播放音频之前，需要先解码音频，再将数据输送到硬件扬声器播放。
- 音频渲染

  在对音频文件进行音效处理之前，需要先解码再由音频处理模块进行音频渲染。
- 音频编辑

  音频编辑（如调整单个声道的播放倍速等）需要基于PCM码流进行，所以需要先将音频文件解码。

## 开发指导

详细的API说明请参考[API文档](../reference/native-apis/_audio_codec.md)。
参考以下示例代码，完成音频解码的全流程，包括：创建解码器，设置解码参数（采样率/码率/声道数等），开始，刷新，重置，销毁资源。

在应用开发过程中，开发者应按一定顺序调用方法，执行对应操作，否则系统可能会抛出异常或生成其他未定义的行为。具体顺序可参考下列开发步骤及对应说明。

如下为音频解码调用关系图：
![Invoking relationship of audio decode stream](figures/audio-codec.png)

### 在 CMake 脚本中链接动态库

```cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_acodec.so)
```

### 开发步骤

1. 添加头文件。

    ```cpp
    #include <multimedia/player_framework/native_avcodec_audiodecoder.h>
    #include <multimedia/native_audio_channel_layout.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    ```

2. 创建解码器实例对象，OH_AVCodec *为解码器实例指针。

    ```cpp
    //c++标准库命名空间
    using namespace std;
    // 通过 codecname 创建解码器
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_MPEG, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *audioDec_ = OH_AudioCodec_CreateByName(name);
    ```

    ```cpp
    // 设置判定是否为编码；设置false表示当前是解码。
    bool isEncoder = false;
    // 通过 Mimetype 创建解码器
    OH_AVCodec *audioDec_ = OH_AudioCodec_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_MPEG, isEncoder);
    ```

    ```cpp
    // 初始化队列
    class ADecBufferSignal {
    public:
        std::mutex inMutex_;
        std::mutex outMutex_;
        std::mutex startMutex_;
        std::condition_variable inCond_;
        std::condition_variable outCond_;
        std::condition_variable startCond_;
        std::queue<uint32_t> inQueue_;
        std::queue<uint32_t> outQueue_;
        std::queue<OH_AVBuffer *> inBufferQueue_;
        std::queue<OH_AVBuffer *> outBufferQueue_;
    };
    ADecBufferSignal *signal_;
    ```
   
3. 调用OH_AudioCodec_RegisterCallback()注册回调函数。  
   注册回调函数指针集合OH_AVCodecAsyncCallback，包括：

    - OH_AVCodecOnError：解码器运行错误。
    - OH_AVCodecOnStreamChanged：码流信息变化，如声道变化等。
    - OH_AVCodecOnNeedInputBuffer：运行过程中需要新的输入数据，即解码器已准备好，可以输入数据。
    - OH_AVCodecOnNewOutputBuffer：运行过程中产生了新的输出数据，即解码完成。

   开发者可以通过处理该回调报告的信息，确保解码器正常运转。

    ```cpp
    // OH_AVCodecOnError回调函数的实现
    static void OnError(OH_AVCodec *codec, int32_t errorCode, void *userData)
    {
        (void)codec;
        (void)errorCode;
        (void)userData;
    }
    // OH_AVCodecOnStreamChanged回调函数的实现
    static void OnOutputFormatChanged(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
    {
        (void)codec;
        (void)format;
        (void)userData;
    }
    // OH_AVCodecOnNeedInputBuffer回调函数的实现
    static void OnInputBufferAvailable(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *data, void *userData)
    {
        (void)codec;
        ADecBufferSignal *signal = static_cast<ADecBufferSignal *>(userData);
        unique_lock<mutex> lock(signal->inMutex_);
        signal->inQueue_.push(index);
        signal->inBufferQueue_.push(data);
        signal->inCond_.notify_all();
        // 解码输入码流送入inBufferQueue_队列
    }
    // OH_AVCodecOnNewOutputBuffer回调函数的实现
    static void OnOutputBufferAvailable(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *data, void *userData)
    {
        (void)codec;
        ADecBufferSignal *signal = static_cast<ADecBufferSignal *>(userData);
        unique_lock<mutex> lock(signal->outMutex_);
        signal->outQueue_.push(index);
        signal->outBufferQueue_.push(data);
        signal->outCond_.notify_all();
        // 将对应输出buffer的 index 送入outQueue_队列
        // 将对应解码完成的数据data送入outBufferQueue_队列
    }
    signal_ = new ADecSignal();
    OH_AVCodecCallback cb_ = {&OnError, &OnOutputFormatChanged, &OnInputBufferAvailable, &OnOutputBufferAvailable};
    int32_t ret = OH_AudioCodec_RegisterCallback(audioDec_, cb_, signal_);
    if (ret != AVCS_ERR_OK) {
        // 异常处理
    }
    ```
   
4. 调用OH_AudioCodec_Configure()配置解码器。
   配置选项key值说明：

   |                              |                             描述                             |                AAC                 | Flac |               Vorbis               | MPEG |
   | ---------------------------- | :----------------------------------------------------------: | :--------------------------------: | :--: | :--------------------------------: | :--: |
   | OH_MD_KEY_AUD_SAMPLE_RATE    |                            采样率                            |                必须                | 必须 |                必须                | 必须 |
   | OH_MD_KEY_AUD_CHANNEL_COUNT  |                            声道数                            |                必须                | 必须 |                必须                | 必须 |
   | OH_MD_KEY_MAX_INPUT_SIZE     |                         最大输入长度                         |                可选                | 可选 |                可选                | 可选 |
   | OH_MD_KEY_AAC_IS_ADTS        |                           是否adts                           |        可选,默认1 latm类型         |  -   |                 -                  |  -   |
   | MD_KEY_AUDIO_SAMPLE_FORMAT   |                        输出音频流格式                        | 可选（SAMPLE_S16LE，SAMPLE_F32LE） |  -   | 可选（SAMPLE_S16LE，SAMPLE_F32LE） |  -   |
   | MD_KEY_BITRATE               |                             可选                             |                可选                | 可选 |                可选                | 可选 |
   | MD_KEY_IDENTIFICATION_HEADER |                          ID Header                           |                 -                  |  -   |    必须（和Codec_Config二选一）    |  -   |
   | MD_KEY_SETUP_HEADER          |                         Setup Header                         |                 -                  |  -   |    必须（和Codec_Config二选一）    |  -   |
   | MD_KEY_CODEC_CONFIG          | MD_KEY_SETUP_HEADERID Header+Common Header+Setup Header 拼接 |                 -                  |      |   必须（和上述ID和Setup二选一）    |  -   |
   
   ```cpp
   // 设置解码分辨率
   int32_t ret;
   // 配置音频采样率（必须）
   constexpr uint32_t DEFAULT_SMAPLERATE = 44100; 
   // 配置音频码率（必须）
   constexpr uint32_t DEFAULT_BITRATE = 32000;
   // 配置音频声道数（必须）
   constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
   // 配置最大输入长度（可选）
   constexpr uint32_t DEFAULT_MAX_INPUT_SIZE = 1152;
   // 配置是否为ADTS解码（acc）
   constexpr uint32_t DEFAULT_AAC_TYPE = 1;
   OH_AVFormat *format = OH_AVFormat_Create();
   // 写入format
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, DEFAULT_SMAPLERATE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_BITRATE, DEFAULT_BITRATE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, DEFAULT_CHANNEL_COUNT);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_MAX_INPUT_SIZE, DEFAULT_MAX_INPUT_SIZE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AAC_IS_ADTS, DEFAULT_AAC_TYPE);
   // 配置解码器
   ret = OH_AudioCodec_Configure(audioDec_, format);
   if (ret != AV_ERR_OK) {
       // 异常处理
   }
   ```
   
5. 调用OH_AudioCodec_Prepare()，解码器就绪。

   ```cpp
   ret = OH_AudioCodec_Prepare(audioDec_);
   if (ret != AV_ERR_OK) {
       // 异常处理
   }
   ```
   
6. 调用OH_AudioCodec_Start()启动解码器，进入运行态。

    ```c++
    unique_ptr<ifstream> inputFile_ = make_unique<ifstream>();
    unique_ptr<ofstream> outFile_ = make_unique<ofstream>();
    // 打开待解码二进制文件路径
    inputFile_->open(inputFilePath.data(), ios::in | ios::binary); 
    // 配置解码文件输出路径
    outFile_->open(outputFilePath.data(), ios::out | ios::binary);
    // 开始解码
    ret = OH_AudioCodec_Start(audioDec_);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```
   
7. 调用OH_AudioCodec_PushInputBuffer()，写入待解码的数据。

   如果是结束，需要对flag标识成AVCODEC_BUFFER_FLAGS_EOS。

    ```c++
    uint32_t index = signal_->inQueue_.front();
    auto buffer = signal_->inBufferQueue_.front();
    int64_t size;
    int64_t pts;
    inputFile_.read(reinterpret_cast<char *>(&size), sizeof(size));
    inputFile_.read(reinterpret_cast<char *>(&pts), sizeof(pts));
    inputFile_.read((char *)OH_AVMemory_GetAddr(buffer), size);
    OH_AVCodecBufferAttr attr = {0};
    if (inputFile_->eof()) {
        attr.size = 0;
        attr.flags = AVCODEC_BUFFER_FLAGS_EOS;
    } else {
        attr.size = size;
        attr.flags = AVCODEC_BUFFER_FLAGS_NONE;
    }
    OH_AVBuffer_SetBufferAttr(buffer, &attr);
    int32_t ret = OH_AudioCodec_PushInputBuffer(audioDec_, index);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```
   
8. 调用OH_AudioCodec_FreeOutputBuffer()，输出解码后的PCM码流。

    ```c++
    uint32_t index = signal_->outQueue_.front();
    OH_AVBuffer *data = signal_->outBufferQueue_.front();
    // 获取buffer attributes
    OH_AVCodecBufferAttr attr = {0};
    ret = OH_AVBuffer_GetBufferAttr(data, &attr);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 将解码完成数据data写入到对应输出文件中
    pcmOutputFile_.write(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(data)), attr.size);
    ret = OH_AudioCodec_FreeOutputBuffer(audioDec_, index);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    if (attr.flags == AVCODEC_BUFFER_FLAGS_EOS) {
        // 结束
    }
    ```
   
9. （可选）调用OH_AudioCodec_Flush()刷新解码器。
   调用OH_AudioCodec_Flush()后，解码器仍处于运行态，但会将当前队列清空，将已解码的数据释放。
   此时需要调用OH_AudioCodec_Start()重新开始解码。
   使用情况：

   * 在文件EOS之后，需要调用刷新
   * 在执行过程中遇到可继续执行的错误时（即OH_AudioCodec_IsValid 为true）调用

    ```c++
    // 刷新解码器 audioDec_
    ret = OH_AudioCodec_Flush(audioDec_);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 重新开始解码
    ret = OH_AudioCodec_Start(audioDec_);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```
   
10. （可选）调用OH_AudioCodec_Reset()重置解码器。
    调用OH_AudioCodec_Reset()后，解码器回到初始化的状态，需要调用OH_AudioCodec_Configure()重新配置，然后调用OH_AudioCodec_Start()重新开始解码。

    ```c++
    // 重置解码器 audioDec_
    ret = OH_AudioCodec_Reset(audioDec_);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    // 重新配置解码器参数
    ret = OH_AudioCodec_Configure(audioDec_, format);
    if (ret != AV_ERR_OK) {
    // 异常处理
    }
    ```
    
11. 调用OH_AudioCodec_Stop()停止解码器。

    ```c++
    // 终止解码器 audioDec_
    ret = OH_AudioCodec_Stop(audioDec_);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
    ```
    
12. 调用OH_AudioCodec_Destroy()销毁解码器实例，释放资源。

    **注意**：不要重复销毁解码器

    ```c++
    // 调用OH_AudioCodec_Destroy, 注销解码器
    ret = OH_AudioCodec_Destroy(audioDec_);
    if (ret != AV_ERR_OK) {
        // 异常处理
    } else {
        audioDec_ = NULL; // 不可重复destroy
    }
    ```

## 相关实例

针对音频解码，有以下相关实例可供参考：

- [音频解码](https://gitee.com/openharmony/multimedia_av_codec/blob/master/test/nativedemo/audio_demo/avcodec_audio_avbuffer_decoder_demo.cpp)