# Audio Decoding

You can call the native APIs provided by the AudioCodec module to decode audio, that is, to decode media data into PCM streams.

For details about the supported decoding capabilities, see [AVCodec Supported Formats](avcodec-support-formats.md#audio-decoding).

**Usage Scenario**

- Audio playback

  Decode audio and transmit the data to the speaker for playing.
- Audio rendering

  Decode audio and transmit the data to the audio processing module for audio rendering.
- Audio editing

  Decode audio and transmit the data for audio editing (for example, adjusting the playback speed of a channel). Audio editing is performed based on PCM streams.
> **NOTE**
>
> Streams generated in the MP3 audio encoding process cannot be directly decoded through the MP3 audio decoding process. The following process is recommended: PCM stream -> MP3 audio encoding -> muxing -> demuxing -> MP3 audio decoding.

## How to Develop

Read [AudioCodec](../../reference/apis-avcodec-kit/_audio_codec.md) for the API reference.

Refer to the code snippet below to complete the entire audio decoding process, including creating a decoder, setting decoding parameters (such as the sampling rate, bit rate, and number of audio channels), and starting, refreshing, resetting, and destroying the decoder.

During application development, you must call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.

The figure below shows the call relationship of audio decoding.

- The dotted line indicates an optional operation.

- The solid line indicates a mandatory operation.

![Call relationship of audio decoding](figures/audio-codec.png)

### Linking the Dynamic Libraries in the CMake Script

```cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_acodec.so)
```

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

2. Create a decoder instance. In the code snippet below, **OH_AVCodec *** is the pointer to the decoder instance created.

    ```cpp
    // Namespace of the C++ standard library.
    using namespace std;
    // Create a decoder by codec name.
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_MPEG, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *audioDec_ = OH_AudioCodec_CreateByName(name);
    ```

    ```cpp
    // Specify whether encoding is used. The value false means decoding.
    bool isEncoder = false;
    // Create a decoder by MIME type.
    OH_AVCodec *audioDec_ = OH_AudioCodec_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_MPEG, isEncoder);
    ```

    ```cpp
    // Initialize the queues.
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
   
3. Call **OH_AudioCodec_RegisterCallback()** to register callback functions.

   Register the **OH_AVCodecCallback** struct that defines the following callback function pointers:

    - **OH_AVCodecOnError**, a callback used to report a codec operation error
    - **OH_AVCodecOnStreamChanged**, a callback used to report stream information changes, including changes in the sampling rate, number of audio channels, and audio sampling format. The decoding formats that can detect these changes include <!--RP5--><!--RP5End-->AAC, FLAC, MP3, and VORBIS. (This callback is supported since API version 15.)
    - **OH_AVCodecOnNeedInputBuffer**, a callback used to report input data required, which means that the decoder is ready for receiving data
    - **OH_AVCodecOnNewOutputBuffer**, a callback used to report output data generated, which means that decoding is complete

   You need to process the callback functions to ensure that the decoder runs properly.

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
        (void)userData;
        // Callback processing after the decoding output parameters are changed. The application performs processing as required.
        int32_t sampleRate;
        int32_t channelCount;
        int32_t sampleFormat;
        if (OH_AVFormat_GetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, &sampleRate)) {
            // Check whether the sampling rate changes and perform processing as required.
        }
        if (OH_AVFormat_GetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, &channelCount)) {
            // Check whether the number of audio channels changes and perform processing as required.
        }
        if (OH_AVFormat_GetIntValue(format, OH_MD_KEY_AUDIO_SAMPLE_FORMAT, &sampleFormat)) {
            // Check whether the audio sampling format changes and perform processing as required.
        }
    }
    // Implement the OH_AVCodecOnNeedInputBuffer callback function.
    static void OnInputBufferAvailable(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *data, void *userData)
    {
        (void)codec;
        ADecBufferSignal *signal = static_cast<ADecBufferSignal *>(userData);
        unique_lock<mutex> lock(signal->inMutex_);
        signal->inQueue_.push(index);
        signal->inBufferQueue_.push(data);
        signal->inCond_.notify_all();
        // The input stream is sent to inBufferQueue_.
    }
    // Implement the OH_AVCodecOnNewOutputBuffer callback function.
    static void OnOutputBufferAvailable(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *data, void *userData)
    {
        (void)codec;
        ADecBufferSignal *signal = static_cast<ADecBufferSignal *>(userData);
        unique_lock<mutex> lock(signal->outMutex_);
        signal->outQueue_.push(index);
        signal->outBufferQueue_.push(data);
        signal->outCond_.notify_all();
        // The index of the output buffer is sent to outQueue_.
        // The decoded data is sent to outBufferQueue_.
    }
    signal_ = new ADecBufferSignal();
    OH_AVCodecCallback cb_ = {&OnError, &OnOutputFormatChanged, &OnInputBufferAvailable, &OnOutputBufferAvailable};
    int32_t ret = OH_AudioCodec_RegisterCallback(audioDec_, cb_, signal_);
    if (ret != AVCS_ERR_OK) {
        // Handle exceptions.
    }
    ```

4. (Optional) Call **OH_AudioCodec_SetDecryptionConfig** to set the decryption configuration.

    Call this API after the media key system information is obtained but before **Prepare()** is called. For details about how to obtain such information, see step 4 in [Media Data Demuxing](audio-video-demuxer.md).

    For details about DRM APIs, see [DRM](../../reference/apis-drm-kit/_drm.md).

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
    
    // Create a media key session.
MediaKeySession *session = nullptr;
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO;
    ret = OH_MediaKeySystem_CreateMediaKeySession(system, &contentProtectionLevel, &session);
    if (ret != DRM_OK) {
        // If the creation fails, refer to the DRM interface document and check logs.
        printf("create media key session failed.");
        return;
    }
    if (session == nullptr) {
        printf("media key session is nullptr.");
        return;
    }
    // Generate a media key request and set the response to the media key request.
    // Set the decryption configuration, that is, set the decryption session and secure channel flag to the decoder. (Currently, the secure channel is not supported for audio decryption and therefore the secure channel flag should be set to false.)
    bool secureAudio = false;
    ret = OH_AudioCodec_SetDecryptionConfig(audioDec_, session, secureAudio);
    ```
    
5. Call **OH_AudioCodec_Configure()** to configure the decoder.

   Key values of configuration options are described as follows:

   |             key              |       Description      |                AAC                 | FLAC|               Vorbis               | MPEG |       G711mu        |          AMR (AMR-NB and AMR-WB)        | APE |
   | ---------------------------- | :--------------: | :--------------------------------: | :--: | :--------------------------------: | :--: | :-----------------: | :-------------------------------: | :--: |
   | OH_MD_KEY_AUD_SAMPLE_RATE    |      Sampling rate     |                Mandatory               | Mandatory|                Mandatory                | Mandatory|        Mandatory         |                Mandatory               | Mandatory|
   | OH_MD_KEY_AUD_CHANNEL_COUNT  |      Number of audio channels     |                Mandatory               | Mandatory|                Mandatory                | Mandatory|        Mandatory         |                Mandatory               | Mandatory|
   | OH_MD_KEY_MAX_INPUT_SIZE     |    Maximum input size  |                Optional               | Optional|                Optional                | Optional|        Optional          |               Optional               | Optional|
   | OH_MD_KEY_AAC_IS_ADTS        |     ADTS or not    |             Optional (defaults to **1**)            |  -   |                 -                  |  -   |         -             |               -                  |  -  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT   |  Output audio stream format | Optional (SAMPLE_S16LE, SAMPLE_F32LE)| Optional| Optional (SAMPLE_S16LE, SAMPLE_F32LE)|  Optional| Optional (default: SAMPLE_S16LE)| Optional (SAMPLE_S16LE, SAMPLE_F32LE)| Optional|
   | OH_MD_KEY_BITRATE               |       Bit rate     |                Optional               | Optional|                Optional               | Optional|         Optional          |              Optional                | Optional|
   | OH_MD_KEY_IDENTIFICATION_HEADER |    ID Header    |                 -                  |  -   |    Mandatory (Either this parameter or **MD_KEY_CODEC_CONFIG** must be set.)   |  -   |          -            |                -                  |  -  |
   | OH_MD_KEY_SETUP_HEADER          |   Setup Header  |                 -                  |  -   |    Mandatory (Either this parameter or **MD_KEY_CODEC_CONFIG** must be set.)   |  -   |          -            |                -                 |  -  |
   | OH_MD_KEY_CODEC_CONFIG          | Codec-specific data|                Optional                |  -   |   Mandatory (Either this parameter or the combination of **MD_KEY_IDENTIFICATION_HEADER** and **MD_KEY_SETUP_HEADER** must be selected.)   |  -   |           -            |                -                 | Optional|
   
   The sample below lists the value range of each audio decoding type.

   | Audio Decoding Type|                                          Sampling Rate (Hz)                                             | Audio Channel Count|
   | ----------- | ----------------------------------------------------------------------------------------------  | :----: |
   | AAC         | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000                |  1–8  |
   | FLAC       | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000, 192000        |  1–8  |
   | Vorbis      | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000, 176400, 192000|  1–8  |
   | MPEG (MP3)   | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000                                    |  1–2  |
   | G711mu      | 8000                                                                                            |   1    |
   | AMR (amrnb)  | 8000                                                                                            |   1    |
   | AMR (amrwb)  | 16000                                                                                           |   1    |
   | APE         | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000, 176400, 192000|  1–2  |
   <!--RP4-->
   <!--RP4End-->

   ```cpp
   // Set the decoding resolution.
   int32_t ret;
   // (Mandatory) Configure the audio sampling rate.
   constexpr uint32_t DEFAULT_SAMPLERATE = 44100;
   // (Optional) Configure the audio bit rate.
   constexpr uint32_t DEFAULT_BITRATE = 32000;
   // (Mandatory) Configure the number of audio channels.
   constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
   // (Optional) Configure the maximum input length.
   constexpr uint32_t DEFAULT_MAX_INPUT_SIZE = 1152;
   // Configure whether to use ADTS decoding (optional for AAC decoding).
   constexpr uint32_t DEFAULT_AAC_TYPE = 1;
   OH_AVFormat *format = OH_AVFormat_Create();
   // Set the format.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, DEFAULT_SAMPLERATE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_BITRATE, DEFAULT_BITRATE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, DEFAULT_CHANNEL_COUNT);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_MAX_INPUT_SIZE, DEFAULT_MAX_INPUT_SIZE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AAC_IS_ADTS, DEFAULT_AAC_TYPE);
   // Configure the decoder.
   ret = OH_AudioCodec_Configure(audioDec_, format);
   if (ret != AV_ERR_OK) {
       // Handle exceptions.
   }
   ```
   
6. Call **OH_AudioCodec_Prepare()** to prepare internal resources for the decoder.

   ```cpp
   ret = OH_AudioCodec_Prepare(audioDec_);
   if (ret != AV_ERR_OK) {
       // Handle exceptions.
   }
   ```
   
7. Call **OH_AudioCodec_Start()** to start the decoder.

    ```c++
    unique_ptr<ifstream> inputFile_ = make_unique<ifstream>();
    unique_ptr<ofstream> outFile_ = make_unique<ofstream>();
    // Open the path of the binary file to be decoded.
    inputFile_->open(inputFilePath.data(), ios::in | ios::binary); 
    // Configure the path of the output file.
    outFile_->open(outputFilePath.data(), ios::out | ios::binary);
    // Start decoding.
    ret = OH_AudioCodec_Start(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```
   
8. (Optional) Call **OH_AVCencInfo_SetAVBuffer()** to set the Common Encryption Scheme (CENC) information.

    If the content being played is DRM encrypted and [demuxing](audio-video-demuxer.md#media-data-demuxing) is performed by the upper-layer application, call **OH_AVCencInfo_SetAVBuffer()** to set the CENC information to the AVBuffer so that the media data can be decrypted in the AVBuffer.

    Add the header file.

    ```c++
    #include <multimedia/player_framework/native_cencinfo.h>
    ```
    Link the dynamic library in the CMake script.

    ``` cmake
    target_link_libraries(sample PUBLIC libnative_media_avcencinfo.so)
    ```

    The following is the sample code:
    ```c++
    auto buffer = signal_->inBufferQueue_.front();
    uint32_t keyIdLen = DRM_KEY_ID_SIZE;
    uint8_t keyId[] = {
        0xd4, 0xb2, 0x01, 0xe4, 0x61, 0xc8, 0x98, 0x96,
        0xcf, 0x05, 0x22, 0x39, 0x8d, 0x09, 0xe6, 0x28};
    uint32_t ivLen = DRM_KEY_IV_SIZE;
    uint8_t iv[] = {
        0xbf, 0x77, 0xed, 0x51, 0x81, 0xde, 0x36, 0x3e,
        0x52, 0xf7, 0x20, 0x4f, 0x72, 0x14, 0xa3, 0x95};
    uint32_t encryptedBlockCount = 0;
    uint32_t skippedBlockCount = 0;
    uint32_t firstEncryptedOffset = 0;
    uint32_t subsampleCount = 1;
    DrmSubsample subsamples[1] = { {0x10, 0x16} };
    // Create a CencInfo instance.
    OH_AVCencInfo *cencInfo = OH_AVCencInfo_Create();
    if (cencInfo == nullptr) {
        // Handle exceptions.
    }
    // Set the decryption algorithm.
    OH_AVErrCode errNo = OH_AVCencInfo_SetAlgorithm(cencInfo, DRM_ALG_CENC_AES_CTR);
    if (errNo != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Set KeyId and Iv.
    errNo = OH_AVCencInfo_SetKeyIdAndIv(cencInfo, keyId, keyIdLen, iv, ivLen);
    if (errNo != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Set the sample information.
    errNo = OH_AVCencInfo_SetSubsampleInfo(cencInfo, encryptedBlockCount, skippedBlockCount, firstEncryptedOffset,
        subsampleCount, subsamples);
    if (errNo != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Set the mode. KeyId, Iv, and SubSamples have been set.
    errNo = OH_AVCencInfo_SetMode(cencInfo, DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET);
    if (errNo != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Set CencInfo to the AVBuffer.
    errNo = OH_AVCencInfo_SetAVBuffer(cencInfo, buffer);
    if (errNo != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Destroy the CencInfo instance.
    errNo = OH_AVCencInfo_Destroy(cencInfo);
    if (errNo != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```
   
9. Call **OH_AudioCodec_PushInputBuffer()** to write the data to decode.

   You should fill in complete input data before calling this API.

   To indicate the End of Stream (EOS), pass in the **AVCODEC_BUFFER_FLAGS_EOS** flag.

    ```c++
    uint32_t index = signal_->inQueue_.front();
    auto buffer = signal_->inBufferQueue_.front();
    int64_t size;
    int64_t pts;
    // size is the length of each frame of the data to decode. pts is the timestamp of each frame and is used to indicate when the audio should be played.
    // The values of size and pts are obtained from an audio and video resource file or data stream to decode.
    // In the case of an audio and video resource file, the values are obtained from the buffer in the decapsulated OH_AVDemuxer_ReadSampleBuffer.
    // In the case of a data stream, the values are obtained from the data stream provider.
    // In this example, the values of size and pts are obtained from the test file.
    inputFile_.read(reinterpret_cast<char *>(&size), sizeof(size));
    inputFile_.read(reinterpret_cast<char *>(&pts), sizeof(pts));
    inputFile_.read((char *)OH_AVBuffer_GetAddr(buffer), size);
    OH_AVCodecBufferAttr attr = {0};
    if (inputFile_->eof()) {
        attr.size = 0;
        attr.flags = AVCODEC_BUFFER_FLAGS_EOS;
    } else {
        attr.size = size;
        attr.flags = AVCODEC_BUFFER_FLAGS_NONE;
    }
    attr.pts = pts;
    OH_AVBuffer_SetBufferAttr(buffer, &attr);
    int32_t ret = OH_AudioCodec_PushInputBuffer(audioDec_, index);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```
   
10. Call **OH_AudioCodec_FreeOutputBuffer()** to release the decoded data.

    Once you have retrieved the decoded PCM stream, call **OH_AudioCodec_FreeOutputBuffer()** to free up the data.

    <!--RP3-->
    ```c++
    uint32_t index = signal_->outQueue_.front();
    OH_AVBuffer *data = signal_->outBufferQueue_.front();
    // Obtain the buffer attributes.
    OH_AVCodecBufferAttr attr = {0};
    ret = OH_AVBuffer_GetBufferAttr(data, &attr);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Write the decoded data (specified by data) to the output file.
    pcmOutputFile_.write(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(data)), attr.size);
    ret = OH_AudioCodec_FreeOutputBuffer(audioDec_, index);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    if (attr.flags == AVCODEC_BUFFER_FLAGS_EOS) {
        // End.
    }
    ```
    <!--RP3End-->

11. (Optional) Call **OH_AudioCodec_Flush()** to refresh the decoder.

    After **OH_AudioCodec_Flush()** is called, the decoder remains in the running state, but the current queue is cleared and the buffer storing the decoded data is freed. To continue decoding, you must call **OH_AudioCodec_Start()** again.
   
    You need to call **OH_AudioCodec_Start()** in the following cases:

    * The EOS of the file is reached.
    * An error with **OH_AudioCodec_IsValid** set to **true** (indicating that the execution can continue) occurs.

    ```c++
    // Refresh the decoder.
    ret = OH_AudioCodec_Flush(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Start decoding again.
    ret = OH_AudioCodec_Start(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

12. (Optional) Call **OH_AudioCodec_Reset()** to reset the decoder.

    After **OH_AudioCodec_Reset()** is called, the decoder returns to the initialized state. To continue decoding, you must call **OH_AudioCodec_Configure()** and then **OH_AudioCodec_Start()**.

    ```c++
    // Reset the decoder.
    ret = OH_AudioCodec_Reset(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Reconfigure the decoder.
    ret = OH_AudioCodec_Configure(audioDec_, format);
    if (ret != AV_ERR_OK) {
    // Handle exceptions.
    }
    ```

13. Call **OH_AudioCodec_Stop()** to stop the decoder.

    After the codec is stopped, you can call **OH_AudioCodec_Start()** to start it again. If you have passed specific data in the previous **OH_AudioCodec_Start()** for the codec, you must pass it again.

    ```c++
    // Stop the decoder.
    ret = OH_AudioCodec_Stop(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

14. Call **OH_AudioCodec_Destroy()** to destroy the decoder instance and release resources.

    > **NOTE**
    >
    > You only need to call this API once.

    ```c++
    // Call OH_AudioCodec_Destroy to destroy the decoder.
    ret = OH_AudioCodec_Destroy(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    } else {
        audioDec_ = NULL; // The decoder cannot be destroyed repeatedly.
    }
    ```

