# 音频编码同步模式

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--SE: @dpy2650--->
<!--TSE: @baotianhao-->

开发者可以调用本模块的Native API接口，完成音频编码，即将音频PCM编码压缩成不同的格式。

接口不限制PCM数据的来源。开发者可以调用麦克风录制获取，也可以导入编辑后的PCM数据。通过音频编码，输出对应格式的码流，最后封装为目标格式文件。

支持的编码能力请参考[AVCodec支持的格式](avcodec-support-formats.md#音频编码)。

**适用场景**

通常推荐使用异步模式，异步模式请参考[音频编码](audio-encoding.md)。若需要主动请求buffer去编码PCM，则可以使用同步模式。
- 音频录制

  通过录制传入PCM，然后编码成对应格式的码流，最后封装成所需格式的文件。具体封装方法请参考[媒体数据封装](audio-video-muxer.md)。
- 音频编辑

  编辑PCM后导出音频文件的场景，需要编码成对应音频格式，最后封装成所需格式的文件。具体封装方法请参考[媒体数据封装](audio-video-muxer.md)。
> **说明：**
> AAC编码器默认采用的VBR可变码率模式，这可能导致与预期码率有偏差。

## 开发指导

详细的API说明请参考[AudioCodec](../../reference/apis-avcodec-kit/_audio_codec.md)。

参考以下示例代码，完成音频编码的全流程，包括：创建编码器、设置编码参数（采样率/码率/声道数等）、开始/刷新/重置/销毁资源。

在应用开发过程中，开发者应按一定顺序调用方法，执行对应操作，否则系统可能会抛出异常或生成其他未定义的行为。具体顺序可参考下列开发步骤及对应说明。

音频编解码同步模式调用关系图如下所示：

- 虚线表示可选。音频编码不涉及解密，无需调用OH_AudioCodec_SetDecryptionConfig。

- 实线表示必选。

![Invoking relationship of synchronous audio encode stream](figures/synchronous-audio.png)

### 在CMake脚本中链接动态库

```cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_acodec.so)
```
> **说明：**
>
> 上述'sample'字样仅为示例，此处由开发者根据实际工程目录自定义。

### 开发步骤

1. 添加头文件和命名空间。

    ```cpp
    #include <multimedia/player_framework/native_avcodec_audiocodec.h>
    #include <multimedia/native_audio_channel_layout.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    #include <multimedia/player_framework/native_avbuffer.h>

    // c++标准库命名空间。
    using namespace std;
    ```

2. 创建编码器实例对象，OH_AVCodec *为编码器实例指针。

   应用可以通过媒体类型或编解码器名称创建编码器。

   方法一：通过Mimetype创建编码器。
    ```cpp
    // 通过Mimetype创建编码器，这里示例创建的是AAC编码器，第二个参数设置为true表示当前是编码。
    OH_AVCodec *audioEnc_ = OH_AudioCodec_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
    ```
   方法二：通过codec name创建编码器。
    ```cpp
    // 通过codec name创建编码器。
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *audioEnc_ = OH_AudioCodec_CreateByName(name);
    ```

3. 调用OH_AudioCodec_Configure配置编码器。

   配置选项key值说明：

   <!--RP1-->
   |             key               |       描述       |  AAC  |  Flac | MPEG(MP3) | G711mu |
   | ----------------------------- | :--------------: | :---: | :---: | :------: | :---: |
   | OH_MD_KEY_AUD_SAMPLE_RATE     |      采样率      |  必须  |  必须 |   必须   |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT   |      声道数      |  必须  |  必须 |   必须   |  必须  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT |  输出音频流格式   |  必须  |  必须 |   必须   |  必须  |
   | OH_MD_KEY_BITRATE             |       码率       |  可选  |  必须 |   必须   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT      |     声道布局     |  可选  |  必须 |    -     |   -   |
   | OH_MD_KEY_MAX_INPUT_SIZE      |   最大输入长度    |  可选  |  可选 |   可选   |  可选  |
   | OH_MD_KEY_AAC_IS_ADTS         |     是否adts     |  可选  |   -   |    -    |   -    |
   | OH_MD_KEY_COMPLIANCE_LEVEL    |    兼容性等级     |  -    |  可选 |    -     |   -    |
   <!--RP1End-->

   各音频编码类型参数范围说明：
   | 音频编码类型 | 采样率(Hz)                                                                       |       声道数       |
   | ----------- | ------------------------------------------------------------------------------- | :----------------: |
   | <!--DelRow-->AAC         | 8000、11025、12000、16000、22050、24000、32000、44100、48000、64000、88200、96000 | 1、2、3、4、5、6、8 |
   | Flac        | 8000、11025、12000、16000、22050、24000、32000、44100、48000、64000、88200、96000 |        1~8         |
   | MP3         | 8000、11025、12000、16000、22050、24000、32000、44100、48000                     |        1~2         |
   | G711mu      | 8000                                                                            |         1          |
   <!--RP2--><!--RP2End-->

   例如，对44100Hz采样率、2声道立体声、SAMPLE_S16LE采样格式的PCM音频，以32000bps的码率进行AAC编码的调用流程如下：
    <!--RP3-->
    ```cpp
    OH_AVErrCode ret;
    // 配置音频采样率（必须）。
    constexpr uint32_t DEFAULT_SAMPLERATE = 44100;
    // 配置音频码率（必须）。
    constexpr uint64_t DEFAULT_BITRATE = 32000;
    // 配置音频声道数（必须）。
    constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
    // 配置音频位深（必须）。
    constexpr OH_BitsPerSample SAMPLE_FORMAT = OH_BitsPerSample::SAMPLE_S16LE;
    // 配置音频声道布局（可选）。
    constexpr OH_AudioChannelLayout CHANNEL_LAYOUT = OH_AudioChannelLayout::CH_LAYOUT_STEREO;

    OH_AVFormat *format = OH_AVFormat_Create();
    // 写入format。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, DEFAULT_CHANNEL_COUNT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, DEFAULT_SAMPLERATE);
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, DEFAULT_BITRATE);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUDIO_SAMPLE_FORMAT, SAMPLE_FORMAT);
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_CHANNEL_LAYOUT, CHANNEL_LAYOUT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_ENABLE_SYNC_MODE, 1); // 同步模式配置。
    // 配置编码器。
    ret = OH_AudioCodec_Configure(audioEnc_, format);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    ```
    <!--RP3End-->
    FLAC编码调用示例：

    ```cpp
    OH_AVErrCode ret;
    // 配置音频采样率（必须）。
    constexpr uint32_t DEFAULT_SAMPLERATE = 44100;
    // 配置音频码率（必须）。
    constexpr uint64_t DEFAULT_BITRATE = 261000;
    // 配置音频声道数（必须）。
    constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
    // 配置音频声道布局（必须）。
    // 值为CH_LAYOUT_MONO、CH_LAYOUT_STEREO、CH_LAYOUT_SURROUND、CH_LAYOUT_QUAD、CH_LAYOUT_5POINT0、CH_LAYOUT_5POINT1、CH_LAYOUT_6POINT1或CH_LAYOUT_7POINT1其中一项。
    constexpr OH_AudioChannelLayout CHANNEL_LAYOUT = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
    // 配置音频位深（必须） flac只有SAMPLE_S16LE和SAMPLE_S32LE。
    constexpr OH_BitsPerSample SAMPLE_FORMAT = OH_BitsPerSample::SAMPLE_S32LE;
    // 配置音频compliance level（默认值0，取值范围[-2,2]）。
    constexpr int32_t COMPLIANCE_LEVEL = 0;

    OH_AVFormat *format = OH_AVFormat_Create();
    // 写入format。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, DEFAULT_CHANNEL_COUNT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, DEFAULT_SAMPLERATE);
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, DEFAULT_BITRATE);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUDIO_SAMPLE_FORMAT, SAMPLE_FORMAT); 
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_CHANNEL_LAYOUT, CHANNEL_LAYOUT);
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_COMPLIANCE_LEVEL, COMPLIANCE_LEVEL); 
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_ENABLE_SYNC_MODE, 1); // 同步模式配置。
    // 配置编码器。
    ret = OH_AudioCodec_Configure(audioEnc_, format);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    ```

4. 调用OH_AudioCodec_Prepare()，编码器就绪。

    ```cpp
    OH_AVErrCode ret = OH_AudioCodec_Prepare(audioEnc_);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    ```

5. 调用OH_AudioCodec_Start()启动编码器，进入运行态。

   添加头文件：
    ```c++
    #include <fstream>
    ```
   使用示例：
    ```c++
    ifstream inputFile_;
    ofstream outFile_;

    // 根据实际使用情况填写输入文件路径。
    const char* inputFilePath = "/";
    // 根据实际使用情况填写输出文件路径。
    const char* outputFilePath = "/";
    // 打开待编码二进制文件路径（此处以输入为PCM文件为例）。
    inputFile_.open(inputFilePath, ios::in | ios::binary); 
    // 配置编码文件输出路径（此处以输出为编码码流文件为例，并非可播放的音频文件，可播放的音频文件需要音频码流封装到容器内生成）。
    outFile_.open(outputFilePath, ios::out | ios::binary);
    // 开始编码。
    OH_AVErrCode ret = OH_AudioCodec_Start(audioEnc_);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    ```

6. 同步模式调用，写入待编码的PCM，获取编码输出的音频帧。

   示例代码中，每次输入的采样点数SAMPLES_PER_FRAME取值方法如下：

   AAC LC编码每帧包含1024个PCM样点，建议单次输入1024个样点的数据量。

   <!--RP4--><!--RP4End-->

   FLAC需要根据如下表格进行设置。

   | 采样率 | 样点数 |
   | :----: | :----: |
   |  8000  |  576  |
   | 16000 |  1152  |
   | 22050 |  2304  |
   | 24000 |  2304  |
   | 32000 |  2304  |
   | 44100 |  4608  |
   | 48000 |  4608  |
   | 88200 |  8192  |
   | 96000 |  8192  |

   单次编码输入的数据量（单位：字节）为：SAMPLES_PER_FRAME * 声道数 * 单个采样点的占用字节。
   使用示例：
   ```c++
   int32_t SAMPLES_PER_FRAME = 1024;
   // AAC LC编码一帧包含1024采样点，2声道，输入数据为S16LE，16比特数据，占用2字节。
   int32_t inputFrameBytes = SAMPLES_PER_FRAME * 2 * 2;
   bool inputFinished = false;
   OH_AVErrCode ret;
   OH_AVCodecBufferAttr attr;

   for (;;) {
       uint32_t index = 0;
       if (!inputFinished) {
           ret = OH_AudioCodec_QueryInputBuffer(audioEnc_, &index, 20000); // 20000us
           if (ret == AV_ERR_TRY_AGAIN_LATER) {
               continue;
           }
           if (ret != AV_ERR_OK) {
               // 异常处理。
               break;
           }
           OH_AVBuffer *inputBuf = OH_AudioCodec_GetInputBuffer(audioEnc_, index);
           if (inputBuf == nullptr) {
               // 异常处理。
               break;
           }
           memset(&attr, 0, sizeof(attr));
           if (!inputFile_.eof()) {
               inputFile_.read((char *)OH_AVBuffer_GetAddr(inputBuf), inputFrameBytes);
               int32_t readSize = inputFile_.gcount();
               attr.size = readSize;
               attr.flags = readSize != 0 ? AVCODEC_BUFFER_FLAGS_NONE : AVCODEC_BUFFER_FLAGS_EOS;
           } else {
               inputFinished = true;
               attr.size = 0;
               attr.flags = AVCODEC_BUFFER_FLAGS_EOS;
           }
           if (OH_AVBuffer_SetBufferAttr(inputBuf, &attr) != AV_ERR_OK) {
               // 异常处理。
           }
           if (OH_AudioCodec_PushInputBuffer(audioEnc_, index) != AV_ERR_OK) {
               // 异常处理。
           }
       }
       // 当输入的数据量可以编码出多帧数据时，需要多次调用获取输出缓冲区，才能取完编码后的数据。
       ret = OH_AudioCodec_QueryOutputBuffer(audioEnc_, &index, 20000); // 20000us
       if (ret == AV_ERR_TRY_AGAIN_LATER) {
           // 超时，可能输入的数据不足以编码出一帧，或者超时时间设置过短。
           continue;
       }
       if (ret != AV_ERR_OK) {
           // 异常处理。
           break;
       }
       OH_AVBuffer *outputBuf = OH_AudioCodec_GetOutputBuffer(audioEnc_, index);
       if (outputBuf == nullptr) {
           // 异常处理。
           break;
       }
       if (OH_AVBuffer_GetBufferAttr(outputBuf, &attr) != AV_ERR_OK) {
           // 异常处理。
           break;
       }
       if (attr.flags & AVCODEC_BUFFER_FLAGS_EOS) {
           // 输出结束。
           break;
       }
       // 这里示例仅将数据写入文件记录。假如需要封装成音频文件，可参考媒体数据封装，调用OH_AVMuxer_WriteSampleBuffer封装数据。
       outFile_.write(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(outputBuf)), attr.size);
       OH_AudioCodec_FreeOutputBuffer(audioEnc_, index);
   }
   ```

   在上方案例中，attr.flags表示缓冲区标记的类别。

   如果是结束，需要将flags标识成AVCODEC_BUFFER_FLAGS_EOS。

   | 枚举值 | 描述 | 
   | -------- | -------- |
   | AVCODEC_BUFFER_FLAGS_NONE | 表示为普通帧。 | 
   | AVCODEC_BUFFER_FLAGS_EOS | 表示缓冲区是流结束帧。 | 
   | AVCODEC_BUFFER_FLAGS_CODEC_DATA | 表示缓冲区包含编解码特定数据。 | 

7. （可选）调用OH_AudioCodec_Reset()重置编码器。

    调用OH_AudioCodec_Reset()后，编码器回到初始化状态。需要调用OH_AudioCodec_Configure()重新配置，然后调用OH_AudioCodec_Start()重新开始编码。

    ```c++
    // 重置编码器。
    OH_AVErrCode ret = OH_AudioCodec_Reset(audioEnc_);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    // 重新配置编码器参数。
    ret = OH_AudioCodec_Configure(audioEnc_, format);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    ```

8. （可选）调用OH_AudioCodec_Stop()停止编码器。

    停止后，可以通过Start重新进入已启动状态（started），但若编码器之前已输入数据，则需要重新输入编码器数据。

    ```c++
    // 停止编码器。
    OH_AVErrCode ret = OH_AudioCodec_Stop(audioEnc_);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    ```

9. 调用OH_AudioCodec_Destroy()销毁编码器实例，释放资源。

    > **说明：**
    >
    > 禁止重复销毁编码器。

    ```c++
    // 调用OH_AudioCodec_Destroy销毁编码器。
    OH_AVErrCode ret = OH_AudioCodec_Destroy(audioEnc_);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    } else {
        audioEnc_ = NULL; // 不可重复destroy。
    }
    ```
