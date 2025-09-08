# Audio Encoding

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @zengyawen-->

You can call native APIs to perform audio encoding, which compresses audio PCM data into a desired format.

PCM data can be from any source. For example, you can use a microphone to record audio data or import edited PCM data. After audio encoding, you can output streams in the desired format and encapsulate the streams into a target file.

For details about the supported encoding capabilities, see [AVCodec Supported Formats](avcodec-support-formats.md#audio-encoding).

**When to Use**

- Audio recording

  Record PCM data, encode it into the desired format, and then [multiplex](audio-video-muxer.md) it in the target file format.
- Audio editing

  Export edited PCM data, encode it into the corresponding audio format, and then [multiplex](audio-video-muxer.md) it into a file.
> **NOTE**
>
> AAC encoders adopt the VBR mode by default. This may result in differences from the configured parameters.

## Development Guidelines

Read [AudioCodec](../../reference/apis-avcodec-kit/capi-native-avcodec-audiocodec-h.md) for the API reference.

Refer to the code snippet below to complete the entire audio encoding process, including creating an encoder, setting encoding parameters (such as the sample rate, bit rate, and audio channel count), and starting, refreshing, resetting, and destroying the encoder.

During application development, you must call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.

The figure below shows the call relationship of audio encoding.

- The dotted line indicates an optional operation.

- The solid line indicates a mandatory operation.

![Call relationship of audio encoding](figures/audio-codec.png)

### Linking the Dynamic Libraries in the CMake Script

```cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_acodec.so)
```
> **NOTE**
>
> The word **sample** in the preceding code snippet is only an example. Use the actual project directory name.

### How to Develop

1. Add the header files.

    ```cpp
    #include <multimedia/player_framework/native_avcodec_audiocodec.h>
    #include <multimedia/native_audio_channel_layout.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    #include <multimedia/player_framework/native_avbuffer.h>
    ```

2. Create an encoder instance. In the code snippet below, **OH_AVCodec *** is the pointer to the encoder instance created.

   You can create an encoder by MIME type or codec name.

   Method 1: Create an encoder by MIME type.
    ```cpp
    // Specify whether encoding is used. The value true means encoding.
    bool isEncoder = true;
    // Create an encoder by MIME type.
    OH_AVCodec *audioEnc_ = OH_AudioCodec_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC, isEncoder);
    ```
   Method 2: Create an encoder by codec name.
    ```cpp
    // Create an encoder by name.
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *audioEnc_ = OH_AudioCodec_CreateByName(name);
    ```
   Add the header file and namespace.
    ```cpp
    #include <mutex>
    #include <queue>
    // Namespace of the C++ standard library.
    using namespace std;
    ```
   The sample code is as follows:
    ```cpp
    // Initialize the queues.
    class AEncBufferSignal {
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
    AEncBufferSignal *signal_;
    ```

3. Call **OH_AudioCodec_RegisterCallback()** to register callback functions.

   Register the **OH_AVCodecCallback** struct that defines the following callback function pointers:

   - **OH_AVCodecOnError**, a callback used to report a codec operation error
   - **OH_AVCodecOnStreamChanged**, a callback not supported by the audio encoder yet
   - **OH_AVCodecOnNeedInputBuffer**, a callback used to report input data required, which means that the encoder is ready for receiving PCM data
   - **OH_AVCodecOnNewOutputBuffer**, a callback used to report output data generated, which means that encoding is complete

   You need to process the callback functions to ensure that the encoder runs properly.

   > **NOTE**
   >
   > You are not advised to perform time-consuming operations in the callback.

    ```cpp
    // Implement the OH_AVCodecOnError callback function.
    static void OnError(OH_AVCodec *codec, int32_t errorCode, void *userData)
    {
        (void)codec;
        (void)errorCode;
        (void)userData;
    }
    // Implement the OH_AVCodecOnStreamChanged callback function.
    static void OnOutputFormatChanged(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
    {
        (void)codec;
        (void)format;
        (void)userData;
    }
    // Implement the OH_AVCodecOnNeedInputBuffer callback function.
    static void OnInputBufferAvailable(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *data, void *userData)
    {
        (void)codec;
        // The input stream is sent to the InputBuffer queue.
        AEncBufferSignal *signal = static_cast<AEncBufferSignal *>(userData);
        unique_lock<mutex> lock(signal->inMutex_);
        signal->inQueue_.push(index);
        signal->inBufferQueue_.push(data);
        signal->inCond_.notify_all();
    }
    // Implement the OH_AVCodecOnNewOutputBuffer callback function.
    static void OnOutputBufferAvailable(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *data, void *userData)
    {
        (void)codec;
        // The index of the output buffer is sent to OutputQueue_.
        // The encoded data is sent to the outBuffer queue.
        AEncBufferSignal *signal = static_cast<AEncBufferSignal *>(userData);
        unique_lock<mutex> lock(signal->outMutex_);
        signal->outQueue_.push(index);
        signal->outBufferQueue_.push(data);
        signal->outCond_.notify_all();
    }
    ```
    Configure the callback information.
    ```cpp
    signal_ = new AEncBufferSignal();
    OH_AVCodecCallback cb_ = {&OnError, &OnOutputFormatChanged, &OnInputBufferAvailable, &OnOutputBufferAvailable};
    // Set the asynchronous callbacks.
    int32_t ret = OH_AudioCodec_RegisterCallback(audioEnc_, cb_, signal_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

4. Call **OH_AudioCodec_Configure** to configure the encoder.

   Key values of configuration options are described as follows:

   <!--RP2-->
   |             key               |       Description      |  AAC  |  FLAC| MPEG (MP3) | G711mu |
   | ----------------------------- | :--------------: | :---: | :---: | :------: | :---: |
   | OH_MD_KEY_AUD_SAMPLE_RATE     |      Sample rate.     |  Mandatory |  Mandatory|   Mandatory  |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT   |      Audio channel count.     |  Mandatory |  Mandatory|   Mandatory  |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT |  Output audio stream format.  |  Mandatory |  Mandatory|   Mandatory  |  Mandatory |
   | OH_MD_KEY_BITRATE             |       Bit rate.      |  Optional |  Mandatory|   Mandatory  |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT      |     Audio channel layout.    |  Optional |  Mandatory|    -     |   -   |
   | OH_MD_KEY_MAX_INPUT_SIZE      |   Maximum input size.   |  Optional |  Optional|   Optional  |  Optional |
   | OH_MD_KEY_AAC_IS_ADTS         |     ADTS or not.    |  Optional |   -   |    -    |   -    |
   | OH_MD_KEY_COMPLIANCE_LEVEL    |    Compatibility level.    |  -    |  Optional|    -     |   -    |
   <!--RP2End-->

   The sample below lists the value range of each audio encoding type.
   | Audio Encoding Type| Sample Rate (Hz)                                                                      |       Audio Channel Count      |
   | ----------- | ------------------------------------------------------------------------------- | :----------------: |
   | <!--DelRow-->AAC         | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000| 1, 2, 3, 4, 5, 6, and 8|
   | FLAC       | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000|        1–8        |
   | MP3         | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000                    |        1–2        |
   | G711mu      | 8000                                                                            |         1          |
   <!--RP3--><!--RP3End-->

   The code snippet below shows the API call process, where AAC encoding at the bit rate of 32000 bit/s is carried out on the PCM audio with the 44100 Hz sample rate, 2-channel stereo, and SAMPLE_S16LE sample format.
    <!--RP4-->
    ```cpp
    int32_t ret;
    // (Mandatory) Configure the audio sample rate.
    constexpr uint32_t DEFAULT_SAMPLERATE = 44100;
    // (Mandatory) Configure the audio bit rate.
    constexpr uint64_t DEFAULT_BITRATE = 32000;
    // (Mandatory) Configure the audio channel count.
    constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
    // (Mandatory) Configure the layout of audio channels.
    constexpr OH_AudioChannelLayout CHANNEL_LAYOUT = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
    // (Mandatory) Configure the audio bit depth.
    constexpr OH_BitsPerSample SAMPLE_FORMAT = OH_BitsPerSample::SAMPLE_S16LE;

    OH_AVFormat *format = OH_AVFormat_Create();
    // Set the format.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, DEFAULT_CHANNEL_COUNT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, DEFAULT_SAMPLERATE);
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, DEFAULT_BITRATE);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUDIO_SAMPLE_FORMAT, SAMPLE_FORMAT);
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_CHANNEL_LAYOUT, CHANNEL_LAYOUT);

    // Configure the encoder.
    ret = OH_AudioCodec_Configure(audioEnc_, format);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```
    <!--RP4End-->
    The following shows the API call process in the case of FLAC encoding.

    ```cpp
    int32_t ret;
    // (Mandatory) Configure the audio sample rate.
    constexpr uint32_t DEFAULT_SAMPLERATE = 44100;
    // (Mandatory) Configure the audio bit rate.
    constexpr uint64_t DEFAULT_BITRATE = 261000;
    // (Mandatory) Configure the audio channel count.
    constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
    // (Mandatory) Configure the layout of audio channels.
    // The value can be CH_LAYOUT_MONO, CH_LAYOUT_STEREO, CH_LAYOUT_SURROUND, CH_LAYOUT_QUAD, CH_LAYOUT_5POINT0, CH_LAYOUT_5POINT1, CH_LAYOUT_6POINT1, or CH_LAYOUT_7POINT1.
    constexpr OH_AudioChannelLayout CHANNEL_LAYOUT = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
    // (Mandatory) Configure the audio bit depth. Only SAMPLE_S16LE and SAMPLE_S32LE are available for FLAC encoding.
    constexpr OH_BitsPerSample SAMPLE_FORMAT = OH_BitsPerSample::SAMPLE_S32LE;
    // Configure the audio compliance level. The default value is 0, and the value ranges from -2 to 2.
    constexpr int32_t COMPLIANCE_LEVEL = 0;
    
    OH_AVFormat *format = OH_AVFormat_Create();
    // Set the format.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, DEFAULT_CHANNEL_COUNT);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, DEFAULT_SAMPLERATE);
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, DEFAULT_BITRATE);
    // Configure the audio sampling precision. In versions earlier than API version 20, this parameter must be set to 1 for FLAC encoding. Otherwise, OH_AudioCodec_Configure returns the error code AV_ERR_INVALID_VAL. However, this parameter has no actual effect and does not affect the encoding result. Starting from API version 20, you do not need to set it anymore.
    // constexpr int32_t BITS_PER_CODED_SAMPLE = 1;
    // OH_AVFormat_SetIntValue(format, OH_MD_KEY_BITS_PER_CODED_SAMPLE, BITS_PER_CODED_SAMPLE);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUDIO_SAMPLE_FORMAT, SAMPLE_FORMAT); 
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_CHANNEL_LAYOUT, CHANNEL_LAYOUT);
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_COMPLIANCE_LEVEL, COMPLIANCE_LEVEL); 
    // Configure the encoder.
    ret = OH_AudioCodec_Configure(audioEnc_, format);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

    <!--RP1--><!--RP1End-->

5. Call **OH_AudioCodec_Prepare()** to prepare internal resources for the encoder.

    ```cpp
    int32_t ret = OH_AudioCodec_Prepare(audioEnc_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

6. Call **OH_AudioCodec_Start()** to start the encoder.

   Add the header file.
    ```c++
    #include <fstream>
    ```
   The sample code is as follows:
    ```c++
    ifstream inputFile_;
    ofstream outFile_;

    // Set the input file path based on the actual situation.
    const char* inputFilePath = "/";
    // Set the output file path based on the actual situation.
    const char* outputFilePath = "/";
    // Open the path of the binary file to be encoded. (A PCM file is used as an example.)
    inputFile_.open(inputFilePath, ios::in | ios::binary); 
    // Set the path of the output file. (An encoded stream file is used as an example.)
    outFile_.open(outputFilePath, ios::out | ios::binary);
    // Start encoding.
    int32_t ret = OH_AudioCodec_Start(audioEnc_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

7. Call **OH_AudioCodec_PushInputBuffer()** to write the data to encode. You should fill in complete input data before calling this API.

   The method for determining the number of samples per frame (**SAMPLES_PER_FRAME**) is as follows:

   AAC-LC encodes 1024 PCM samples per frame. Therefore, you are advised to input exactly 1024 samples at a time.

   <!--RP5--><!--RP5End-->

   For FLAC encoding, set **SAMPLES_PER_FRAME** based on the table below.

   | Sample Rate| Sample Count|
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

   > **NOTE**
   >
   > Data volume (in bytes) of a single encoding input: Number of samples (**SAMPLES_PER_FRAME**) * Number of channels * Number of bytes per sample.
   >
   > In the case of FLAC encoding, use the table below to set the number of samples based on the sample rate to prevent possible file corruption.

   ```c++
    // Audio channel count.
    constexpr int32_t DEFAULT_CHANNEL_COUNT = 2;
    // Number of samples. For example, the number of samples for AAC-LC is 1024.
    constexpr int32_t SAMPLES_PER_FRAME = 1024;
    // Data volume (in bytes) of a single encoding input: Number of samples * Number of channels * Number of bytes per sample. (The sample format SAMPLE_S16LE is used as an example.)
    // If the last frame of data does not meet the required length,you are advised to discard it or add padding.
    constexpr int32_t INPUT_FRAME_BYTES = SAMPLES_PER_FRAME * DEFAULT_CHANNEL_COUNT * sizeof(short);
    uint32_t index = signal_->inQueue_.front();
    auto buffer = signal_->inBufferQueue_.front();
    OH_AVCodecBufferAttr attr = {0};
    if (!inputFile_.eof()) {
        inputFile_.read((char *)OH_AVBuffer_GetAddr(buffer), INPUT_FRAME_BYTES);
        attr.size = INPUT_FRAME_BYTES;
        attr.flags = AVCODEC_BUFFER_FLAGS_NONE;
    } else {
        attr.size = 0;
        attr.flags = AVCODEC_BUFFER_FLAGS_EOS;
    }
    OH_AVBuffer_SetBufferAttr(buffer, &attr);
    // Send the data to the input queue for encoding. The index is the subscript of the queue.
    int32_t ret = OH_AudioCodec_PushInputBuffer(audioEnc_, index);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
   ```
   In the preceding example, **attr.flags** indicates the type of the buffer flag.

   To indicate the End of Stream (EOS), pass in the **AVCODEC_BUFFER_FLAGS_EOS** flag.

   | Value| Description|
   | -------- | -------- |
   | AVCODEC_BUFFER_FLAGS_NONE | Common frame.|
   | AVCODEC_BUFFER_FLAGS_EOS | The buffer is an end-of-stream frame.|
   | AVCODEC_BUFFER_FLAGS_CODEC_DATA | The buffer contains codec-specific data.|

8. Call **OH_AudioCodec_FreeOutputBuffer()** to release the encoded data.

   Once you have retrieved the encoded stream, call **OH_AudioCodec_FreeOutputBuffer()** to free up the data.

    ```c++
    uint32_t index = signal_->outQueue_.front();
    OH_AVBuffer *avBuffer = signal_->outBufferQueue_.front();
    if (avBuffer == nullptr) {
        // Handle exceptions.
    }
    // Obtain the buffer attributes.
    OH_AVCodecBufferAttr attr = {0};
    int32_t ret = OH_AVBuffer_GetBufferAttr(avBuffer, &attr);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Write the encoded data (specified by data) to the output file.
    outFile_.write(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(avBuffer)), attr.size);
    // Release the output buffer.
    ret = OH_AudioCodec_FreeOutputBuffer(audioEnc_, index);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    if (attr.flags == AVCODEC_BUFFER_FLAGS_EOS) {
        // End.
    }
    ```

9. (Optional) Call **OH_AudioCodec_Flush()** to refresh the encoder.

   After **OH_AudioCodec_Flush()** is called, the current encoding queue is cleared.

   To continue encoding, you must call **OH_AudioCodec_Start()** again.

   You need to call **OH_AudioCodec_Flush()** in the following cases:

   * The EOS of the file is reached.
   * An error with **OH_AudioCodec_IsValid** set to **true** (indicating that the execution can continue) occurs.

    ```c++
    // Refresh the encoder.
    int32_t ret = OH_AudioCodec_Flush(audioEnc_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Start encoding again.
    ret = OH_AudioCodec_Start(audioEnc_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

10. (Optional) Call **OH_AudioCodec_Reset()** to reset the encoder.

    After **OH_AudioCodec_Reset()** is called, the encoder returns to the initialized state. To continue encoding, you must call **OH_AudioCodec_Configure()** and then **OH_AudioCodec_Start()**.

    ```c++
    // Reset the encoder.
    int32_t ret = OH_AudioCodec_Reset(audioEnc_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Reconfigure the encoder.
    ret = OH_AudioCodec_Configure(audioEnc_, format);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

11. Call **OH_AudioCodec_Stop()** to stop the encoder.

    After the encoder is stopped, you can call **Start** to start it again. If you have passed specific data in the previous **Start** for the encoder, you must pass it again.

    ```c++
    // Stop the encoder.
    int32_t ret = OH_AudioCodec_Stop(audioEnc_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

12. Call **OH_AudioCodec_Destroy()** to destroy the encoder instance and release resources.

    > **NOTE**
    >
    > You only need to call this API once.

    ```c++
    // Call OH_AudioCodec_Destroy to destroy the encoder.
    int32_t ret = OH_AudioCodec_Destroy(audioEnc_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    } else {
        audioEnc_ = NULL; // The encoder cannot be destroyed repeatedly.
    }
    ```
