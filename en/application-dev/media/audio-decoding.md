# Audio Decoding

You can call the native APIs provided by the **AudioDecoder** module to decode audio, that is, to decode media data into PCM streams.

Currently, the following decoding capabilities are supported:

| Container Specification| Audio Decoding Type                |
| -------- | :--------------------------- |
| mp4      | AAC, MPEG (MP3), FLAC, Vorbis|
| m4a      | AAC                          |
| flac     | FLAC                        |
| ogg      | Vorbis                       |
| aac      | AAC                          |
| mp3      | MPEG (MP3)                    |

**Usage Scenario**

- Audio playback

  Decode audio and transmit the data to the speaker for playing.
- Audio rendering

  Decode audio and transmit the data to the audio processing module for audio rendering.
- Audio editing

  Decode audio and transmit the data for audio editing (for example, adjusting the playback speed of a channel). Audio editing is performed based on PCM streams.

## How to Develop

Read [AudioDecoder](../reference/native-apis/_audio_decoder.md) for the API reference.

Refer to the code snippet below to complete the entire audio decoding process, including creating a decoder, setting decoding parameters (such as the sampling rate, bit rate, and number of audio channels), and starting, refreshing, resetting, and destroying the decoder.

During application development, you must call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.

For details about the complete code, see [Sample](https://gitee.com/openharmony/multimedia_av_codec/blob/master/test/nativedemo/audio_demo/avcodec_audio_decoder_demo.cpp).

The figure below shows the call relationship of audio decoding.

![Call relationship of audio decoding](figures/audio-decode.png)

1. Create a decoder instance.

    ```cpp
    // Create a decoder by name.
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_MPEG, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *audioDec = OH_AudioDecoder_CreateByName(name);
    ```

    ```cpp
    // Create a decoder by MIME type.
    OH_AVCodec *audioDec = OH_AudioDecoder_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_MPEG);
    ```

    ```cpp
    // Initialize the queues.
    class ADecSignal {
    public:
        std::mutex inMutex_;
        std::mutex outMutex_;
        std::mutex startMutex_;
        std::condition_variable inCond_;
        std::condition_variable outCond_;
        std::condition_variable startCond_;
        std::queue<uint32_t> inQueue_;
        std::queue<uint32_t> outQueue_;
        std::queue<OH_AVMemory *> inBufferQueue_;
        std::queue<OH_AVMemory *> outBufferQueue_;
        std::queue<OH_AVCodecBufferAttr> attrQueue_;
    };
    ADecSignal *signal_;
    ```

2. Call **OH_AudioDecoder_SetCallback()** to set callback functions.

   Register the **OH_AVCodecAsyncCallback** struct that defines the following callback function pointers:

   - **OH_AVCodecOnError**, a callback used to report a codec operation error
   - **OH_AVCodecOnStreamChanged**, a callback used to report a codec stream change, for example, audio channel change
   - **OH_AVCodecOnNeedInputData**, a callback used to report input data required, which means that the decoder is ready for receiving data
   - **OH_AVCodecOnNewOutputData**, a callback used to report output data generated, which means that decoding is complete

   You need to process the callback functions to ensure that the decoder runs properly.

    ```cpp
    // Implement the OH_AVCodecOnError callback function.
    static void OnError(OH_AVCodec *codec, int32_t errorCode, void *userData)
    {
        (void)codec;
        (void)errorCode;
        (void)userData;
    }
    // Implement the OH_AVCodecOnStreamChanged callback function.
    static void OnStreamChanged(OH_AVCodec *codec, OH_AVFormat *format, void*userData)
    {
        (void)codec;
        (void)format;
        (void)userData;
    }
    // Implement the OH_AVCodecOnNeedInputData callback function.
    static void onNeedInputData(OH_AVCodec *codec, uint32_t index, OH_AVMemory*data, void *userData)
    {
        (void)codec;
        ADecSignal *signal = static_cast<ADecSignal *>(userData);
        unique_lock<mutex> lock(signal->inMutex_);
        signal->inQueue_.push(index);
        signal->inBufferQueue_.push(data);
        signal->inCond_.notify_all();
        // The input stream is sent to the InputBuffer queue.
    }
    // Implement the OH_AVCodecOnNewOutputData callback function.
    static void onNeedOutputData(OH_AVCodec *codec, uint32_t index, OH_AVMemory*data, OH_AVCodecBufferAttr *attr,
                                            void *userData)
    {
        (void)codec;
        ADecSignal *signal = static_cast<ADecSignal *>(userData);
        unique_lock<mutex> lock(signal->outMutex_);
        signal->outQueue_.push(index);
        signal->outBufferQueue_.push(data);
        if (attr) {
            signal->attrQueue_.push(*attr);
        }
        signal->outCond_.notify_all();
        // The index of the output buffer is sent to OutputQueue_.
        // The decoded data is sent to the OutputBuffer queue.
    }
    signal_ = new ADecSignal();
    OH_AVCodecAsyncCallback cb = {&OnError, &OnStreamChanged, &onNeedInputData, &onNeedOutputData};
    // Set the asynchronous callbacks.
    int32_t ret = OH_AudioDecoder_SetCallback(audioDec, cb, signal_);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```
3. Call **OH_AudioDecoder_Configure()** to configure the decoder.

   The following options are mandatory: sampling rate, bit rate, and number of audio channels. The maximum input length is optional.

   - For AAC decoding, the parameter that specifies whether the data type is Audio Data Transport Stream (ADTS) must be specified. If this parameter is not specified, the data type is considered as Low Overhead Audio Transport Multiplex (LATM).

   - For Vorbis decoding, the ID header and setup header must also be specified.
    ```cpp
    enum AudioFormatType : int32_t {
        TYPE_AAC = 0,
        TYPE_FLAC = 1,
        TYPE_MP3 = 2,
        TYPE_VORBIS = 3,
    };  
    // Set the decoding resolution.
    int32_t ret;
    // (Mandatory) Configure the audio sampling rate.
    constexpr uint32_t DEFAULT_SMAPLERATE = 44100; 
    // (Mandatory) Configure the audio bit rate.
    constexpr uint32_t DEFAULT_BITRATE = 32000;
    // (Mandatory) Configure the number of audio channels.
    constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
    // (Optional) Configure the maximum input length.
    constexpr uint32_t DEFAULT_MAX_INPUT_SIZE = 1152;
    OH_AVFormat *format = OH_AVFormat_Create();
    // Set the format.
    OH_AVFormat_SetIntValue(format, MediaDescriptionKey::MD_KEY_SAMPLE_RATE.data(),DEFAULT_SMAPLERATE);
    OH_AVFormat_SetIntValue(format, MediaDescriptionKey::MD_KEY_BITRATE.data(),DEFAULT_BITRATE);
    OH_AVFormat_SetIntValue(format, MediaDescriptionKey::MD_KEY_CHANNEL_COUNT.data(),DEFAULT_CHANNEL_COUNT);
    OH_AVFormat_SetIntValue(format, MediaDescriptionKey::MD_KEY_MAX_INPUT_SIZE.data(),DEFAULT_MAX_INPUT_SIZE);
    if (audioType == TYPE_AAC) {
        OH_AVFormat_SetIntValue(format, MediaDescriptionKey::MD_KEY_AAC_IS_ADTS.data(), DEFAULT_AAC_TYPE);
    }
    if (audioType == TYPE_VORBIS) {
        OH_AVFormat_SetStringValue(format, MediaDescriptionKey::MD_KEY_IDENTIFICATION_HEADER.data(), DEFAULT_ID_HEADER);
        OH_AVFormat_SetStringValue(format, MediaDescriptionKey::MD_KEY_SETUP_HEADER.data(), DEFAULT_SETUP_HEADER);
    }
    // Configure the decoder.
    ret = OH_AudioDecoder_Configure(audioDec, format);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```
4. Call **OH_AudioDecoder_Prepare()** to prepare internal resources for the decoder.

    ```cpp
    ret = OH_AudioDecoder_Prepare(audioDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```
5. Call **OH_AudioDecoder_Start()** to start the decoder.

    ```c++
    inputFile_ = std::make_unique<std::ifstream>();
    // Open the path of the binary file to be decoded.
    inputFile_->open(inputFilePath.data(), std::ios::in | std::ios::binary); 
    // Configure the path of the output file.
    outFile_ = std::make_unique<std::ofstream>();
    outFile_->open(outputFilePath.data(), std::ios::out | std::ios::binary);
    // Start decoding.
    ret = OH_AudioDecoder_Start(audioDec);
    if (ret != AV_ERR_OK) {
    // Exception handling.
    }
    ```
6. Call **OH_AudioDecoder_PushInputData()** to write the data to decode.

   To indicate the End of Stream (EOS), pass in the **AVCODEC_BUFFER_FLAGS_EOS** flag.
    ```c++
    // Configure the buffer information.
    OH_AVCodecBufferAttr info;
    // Set the package size, offset, and timestamp.
    info.size = pkt_->size;
    info.offset = 0;
    info.pts = pkt_->pts;
    info.flags = AVCODEC_BUFFER_FLAGS_CODEC_DATA;
    auto buffer = signal_->inBufferQueue_.front();
    if (inputFile_->eof()){
        info.size = 0;
        info.flags = AVCODEC_BUFFER_FLAGS_EOS;
    }else{
        inputFile_->read((char *)OH_AVMemory_GetAddr(buffer), INPUT_FRAME_BYTES);
    }
    uint32_t index = signal_->inQueue_.front();
    // Send the data to the input queue for decoding. The index is the subscript of the queue.
    int32_t ret = OH_AudioDecoder_PushInputData(audioDec, index, info);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```
7. Call **OH_AudioDecoder_FreeOutputData()** to output decoded PCM streams.

    ```c++
    OH_AVCodecBufferAttr attr = signal_->attrQueue_.front();
    OH_AVMemory *data = signal_->outBufferQueue_.front();
    uint32_t index = signal_->outQueue_.front();
    // Write the decoded data (specified by data) to the output file.
    outFile_->write(reinterpret_cast<char *>(OH_AVMemory_GetAddr(data)), attr.size);
    // Free the buffer that stores the data.
    ret = OH_AudioDecoder_FreeOutputData(audioDec, index);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```
8. (Optional) Call **OH_AudioDecoder_Flush()** to refresh the decoder.

    After **OH_AudioDecoder_Flush()** is called, the decoder remains in the running state, but the current queue is cleared and the buffer storing the decoded data is freed. To continue decoding, you must call **OH_AudioDecoder_Start()** again.

    You need to call **OH_AudioDecoder_Start()** in the following cases:

    * The EOS of the file is reached.
    * An error with **OH_AudioDecoder_IsValid** set to **true** (indicating that the execution can continue) occurs.
    ```c++
    // Refresh the decoder.
    ret = OH_AudioDecoder_Flush(audioDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Start decoding again.
    ret = OH_AudioDecoder_Start(audioDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```
9. (Optional) Call **OH_AudioDecoder_Reset()** to reset the decoder.

    After **OH_AudioDecoder_Reset()** is called, the decoder returns to the initialized state. To continue decoding, you must call **OH_AudioDecoder_Configure()** and then **OH_AudioDecoder_Start()**.

    ```c++
    // Reset the decoder.
    ret = OH_AudioDecoder_Reset(audioDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    // Reconfigure the decoder.
    ret = OH_AudioDecoder_Configure(audioDec, format);
    if (ret != AV_ERR_OK) {
    // Exception handling.
    }
    ```
10. Call **OH_AudioDecoder_Stop()** to stop the decoder.

    ```c++
    // Stop the decoder.
    ret = OH_AudioDecoder_Stop(audioDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    return ret;
    ```
11. Call **OH_AudioDecoder_Destroy()** to destroy the decoder instance and release resources.

    **NOTE**: You only need to call this API once.

    ```c++
    // Call OH_AudioDecoder_Destroy to destroy the decoder.
    ret = OH_AudioDecoder_Destroy(audioDec);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    } else {
        audioEnc = NULL; // The decoder cannot be destroyed repeatedly.
    }
    return ret;
    ```
