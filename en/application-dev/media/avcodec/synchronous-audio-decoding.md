# Synchronous Audio Decoding

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @zengyawen-->

Starting from API version 20, audio decoding in synchronous mode is supported.

You can call native APIs to perform audio decoding in synchronous mode, which decodes media data into PCM streams.

For details about the supported decoding capabilities, see [AVCodec Supported Formats](avcodec-support-formats.md#audio-decoding).

**When to Use**

Asynchronous mode is generally recommended for most use cases. For details, see [Audio Decoding](audio-decoding.md). Synchronous mode can be used if you need to actively request buffers for frame delivery.
Decoding an audio/video file into a PCM stream typically involves the following steps: [media data demultiplexing](audio-video-demuxer.md) -> audio decoding.

This guide outlines the audio decoding process: inputting audio frames and decoding them into PCM streams.

## Development Guidelines

Read [AudioCodec](../../reference/apis-avcodec-kit/capi-native-avcodec-audiocodec-h.md) for the API reference.

Refer to the code snippet below to complete the entire audio decoding process, including creating a decoder, setting decoding parameters (such as the sample rate, bit rate, and audio channel count), and starting, refreshing, resetting, and destroying the decoder.

During application development, you must call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.

The figure below shows the call relationship of audio decoding in synchronous mode.

- The dotted line indicates an optional operation.

- The solid line indicates a mandatory operation.

![Call relationship of synchronous audio decoding](figures/synchronous-audio.png)

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

1. Add the header files and namespace.

    ```cpp
    #include <multimedia/player_framework/native_avcodec_audiocodec.h>
    #include <multimedia/native_audio_channel_layout.h>
    #include <multimedia/player_framework/native_avcapability.h>
    #include <multimedia/player_framework/native_avcodec_base.h>
    #include <multimedia/player_framework/native_avformat.h>
    #include <multimedia/player_framework/native_avbuffer.h>

    // Namespace of the C++ standard library.
    using namespace std;
    ```

2. Create a decoder instance. In the code snippet below, **OH_AVCodec *** is the pointer to the decoder instance created.

   You can create a decoder by MIME type or codec name.

   Method 1: Create a decoder by MIME type.
    ```c++
    // Create a decoder by MIME type. The following example creates an AAC decoder. The second parameter is set to false to indicate decoding.
    OH_AVCodec *audioDec_ = OH_AudioCodec_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC, false);
    ```
   Method 2: Create a decoder by codec name.
    ```c++
    // Create a decoder by name.
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, false);
    const char *name = OH_AVCapability_GetName(capability);
    OH_AVCodec *audioDec_ = OH_AudioCodec_CreateByName(name);
    ```

3. (Optional) Call **OH_AudioCodec_SetDecryptionConfig** to set the decryption configuration.

    Call this API after the media key system information is obtained but before **Prepare()** is called. For details about how to obtain such information, see step 4 in [Media Data Demultiplexing](audio-video-demuxer.md).

    For details about DRM APIs, see [DRM](../../reference/apis-drm-kit/capi-drm.md).

     Add the header files.

    ```c++
#include <multimedia/drm_framework/native_mediakeysystem.h>
    #include <multimedia/drm_framework/native_mediakeysession.h>
    #include <multimedia/drm_framework/native_drm_err.h>
    #include <multimedia/drm_framework/native_drm_common.h>
    ```
    Link the dynamic libraries in the CMake script.
    
    ``` cmake
target_link_libraries(sample PUBLIC libnative_drm.so)
    ```
    
    The sample code is as follows:
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
    // Set the decryption configuration, that is, assign the decryption session to the decoder. Currently, audio decryption does not support secure decoders. Therefore, set the secureAudio parameter to false.
    bool secureAudio = false;
    ret = OH_AudioCodec_SetDecryptionConfig(audioDec_, session, secureAudio);
    ```
    
4. Call **OH_AudioCodec_Configure()** to configure the decoder.

   Key values of configuration options are described as follows:

   |             Key             |       Description      |                AAC                 | FLAC|               Vorbis               | MPEG |       G711mu        |          AMR (AMR-NB and AMR-WB)        | APE |          G711a          |
   | ---------------------------- | :--------------: | :--------------------------------: | :--: | :--------------------------------: | :--: | :-----------------: | :-------------------------------: | :--: | :----------------------: |
   | OH_MD_KEY_ENABLE_SYNC_MODE   |   Synchronous mode. It must be set to **1** if synchronization mode is enabled.  | Mandatory for synchronous mode| Mandatory for synchronous mode| Mandatory for synchronous mode| Mandatory for synchronous mode| Mandatory for synchronous mode| Mandatory for synchronous mode| Mandatory for synchronous mode| Mandatory for synchronous mode|
   | OH_MD_KEY_AUD_SAMPLE_RATE    |      Sample rate.     |                Mandatory               | Mandatory|                Mandatory                | Mandatory|        Mandatory         |                Mandatory               | Mandatory|           Mandatory          |
   | OH_MD_KEY_AUD_CHANNEL_COUNT  |      Audio channel count.     |                Mandatory               | Mandatory|                Mandatory                | Mandatory|        Mandatory         |                Mandatory               | Mandatory|           Mandatory          |
   | OH_MD_KEY_MAX_INPUT_SIZE     |    Maximum input size.  |                Optional               | Optional|                Optional                | Optional|        Optional          |               Optional               | Optional|          Optional           |
   | OH_MD_KEY_AAC_IS_ADTS        |     ADTS or not.    |             Optional (defaults to **1**)            |  -   |                 -                  |  -   |         -             |               -                  |  -  |         -                |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT   |  Output audio stream format. | Optional (SAMPLE_S16LE, SAMPLE_F32LE)| Optional| Optional (SAMPLE_S16LE, SAMPLE_F32LE)|  Optional| Optional (default: SAMPLE_S16LE)| Optional (SAMPLE_S16LE, SAMPLE_F32LE)| Optional| Optional (default: SAMPLE_S16LE)|
   | OH_MD_KEY_BITRATE               |       Bit rate.     |                Optional               | Optional|                Optional               | Optional|         Optional          |              Optional                | Optional|         Optional          |
   | OH_MD_KEY_IDENTIFICATION_HEADER |    ID header.   |                 -                  |  -   |    Mandatory (Either this parameter or **MD_KEY_CODEC_CONFIG** must be set.)   |  -   |          -            |                -                  |  -  |           -            |
   | OH_MD_KEY_SETUP_HEADER          |   Setup header. |                 -                  |  -   |    Mandatory (Either this parameter or **MD_KEY_CODEC_CONFIG** must be set.)   |  -   |          -            |                -                 |  -  |            -            |
   | OH_MD_KEY_CODEC_CONFIG          | Codec-specific data.|                Optional                |  -   |   Mandatory (Either this parameter or the combination of **MD_KEY_IDENTIFICATION_HEADER** and **MD_KEY_SETUP_HEADER** must be selected.)   |  -   |           -            |                -                 | Optional|           -            |
   
   The sample below lists the value range of each audio decoding type.

   | Audio Decoding Type|                                          Sample Rate (Hz)                                             | Audio Channel Count|
   | ----------- | ----------------------------------------------------------------------------------------------  | :----: |
   | AAC         | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000                |  1–8  |
   | FLAC       | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000, 192000        |  1–8  |
   | Vorbis      | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000, 176400, 192000|  1–8  |
   | MPEG (MP3)   | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000                                    |  1–2  |
   | G711mu      | 8000                                                                                            |   1    |
   | AMR (amrnb)  | 8000                                                                                            |   1    |
   | AMR (amrwb)  | 16000                                                                                           |   1    |
   | APE         | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000, 176400, 192000|  1–2  |
   | G711a       | 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000                                    |  1–6  |
   <!--RP4-->
   <!--RP4End-->

   ```c++
   // (Mandatory) Configure the audio sample rate.
   constexpr uint32_t DEFAULT_SAMPLERATE = 44100;
   // (Mandatory) Configure the audio channel count.
   constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
   // Configure whether to use ADTS decoding (optional for AAC decoding).
   constexpr uint32_t DEFAULT_AAC_TYPE = 1;
   OH_AVFormat *format = OH_AVFormat_Create();
   // Set the format.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, DEFAULT_SAMPLERATE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, DEFAULT_CHANNEL_COUNT);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AAC_IS_ADTS, DEFAULT_AAC_TYPE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_ENABLE_SYNC_MODE, 1); // Set synchronous mode.
   // Configure the decoder.
   OH_AVErrCode ret = OH_AudioCodec_Configure(audioDec_, format);
   if (ret != AV_ERR_OK) {
       // Handle exceptions.
   }
   ```

5. Call **OH_AudioCodec_Prepare()** to prepare internal resources for the decoder.

   ```c++
   OH_AVErrCode ret = OH_AudioCodec_Prepare(audioDec_);
   if (ret != AV_ERR_OK) {
       // Handle exceptions.
   }
   ```

6. Call **OH_AudioCodec_Start()** to start the decoder.

   Add the header file.
    ```c++
    #include <fstream>
    ```

   The sample code is as follows:
    ```c++
    ifstream inputFile_;
    ofstream outFile_;

    // Set the input file path based on the actual situation. To demonstrate audio decoding, the input file here contains audio frames and related information (not a directly playable audio file).
    const char* inputFilePath = "/";
    // Set the output file path based on the actual situation. This guide only demonstrates audio decoding; decoded PCM data is saved to a file without further processing.
    const char* outputFilePath = "/";
    // Open the path of the binary file to be decoded.
    inputFile_.open(inputFilePath, ios::in | ios::binary); 
    // Set the path of the output file.
    outFile_.open(outputFilePath, ios::out | ios::binary);
    // Start decoding.
    OH_AVErrCode ret = OH_AudioCodec_Start(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```
   
7. (Optional) Call **OH_AVCencInfo_SetAVBuffer()** to set the Common Encryption Scheme (CENC) information.

    If the content being played is DRM encrypted and [demultiplexing](audio-video-demuxer.md) is performed by the upper-layer application, call **OH_AVCencInfo_SetAVBuffer()** to set the CENC information to the AVBuffer for media data decryption.

    Add the header file.

    ```c++
    #include <multimedia/player_framework/native_cencinfo.h>
    ```
    Link the dynamic libraries in the CMake script.

    ``` cmake
    target_link_libraries(sample PUBLIC libnative_media_avcencinfo.so)
    ```

    The sample code is as follows:
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
   
8. Invoke synchronous mode to write the data to decode and obtain the decoded output.

   Read data:
   ```c++
   // size is the length of each frame of the data to decode. pts is the timestamp of each frame and is used to indicate when the audio should be played.
   // The values of size and pts are obtained from an audio and video resource file or data stream to decode.
   // In the case of an audio and video resource file, the values are obtained from the buffer in the demultiplexed OH_AVDemuxer_ReadSampleBuffer.
   // In the case of a data stream, the values are obtained from the data stream provider.
   // In this example, the values of size and pts are obtained from the test file.
   bool DecoderFillInputBuffer(OH_AVBuffer *buffer, ifstream &inputFile)
   {
       OH_AVCodecBufferAttr attr;
       memset(&attr, 0, sizeof(attr));
       attr.flags = AVCODEC_BUFFER_FLAGS_EOS;
       bool finished = true;
       do {
           int64_t size;
           inputFile.read(reinterpret_cast<char *>(&size), sizeof(size));
           if (inputFile.eof() || inputFile.gcount() != sizeof(size)) {
               break;
           }
           inputFile.read(reinterpret_cast<char *>(&attr.pts), sizeof(attr.pts));
           if (inputFile.gcount() != sizeof(attr.pts)) {
               break;
           }
           attr.size = static_cast<int32_t>(size);
           if (attr.size > 0) {
               inputFile.read((char *)OH_AVBuffer_GetAddr(buffer), attr.size);
               attr.flags = AVCODEC_BUFFER_FLAGS_NONE;
               finished = false;
           }
       } while (0);
       OH_AVBuffer_SetBufferAttr(buffer, &attr);
       return finished;
   }
   bool InputOneFrame(OH_AVCodec *codec, ifstream &inputFile)
   {
       uint32_t index = 0;
       bool finished = true;
       OH_AVErrCode ret = OH_AudioCodec_QueryInputBuffer(codec, &index, 20000); // 20000us
       if (ret == AV_ERR_TRY_AGAIN_LATER) {
           // Timeout: exception handling. The timeout period is too short, or input/output buffers are not consumed/released (causing decoding blocking).
           return finished;
       }
       if (ret != AV_ERR_OK) {
           // Handle exceptions.
           return finished;
       }
       OH_AVBuffer *inputBuf = OH_AudioCodec_GetInputBuffer(codec, index);
       if (inputBuf == nullptr) {
           // Handle exceptions.
           return finished;
       }
       finished = DecoderFillInputBuffer(inputBuf, inputFile);
       OH_AudioCodec_PushInputBuffer(codec, index);
       return finished;
   }
   
   ```

   You should fill in complete input data before calling this API.

   When finished, set the flags to **AVCODEC_BUFFER_FLAGS_EOS**.

    ```c++
    bool inputFinished = false;
    for (;;) {
        if (!inputFinished) {
            inputFinished = InputOneFrame(audioDec_, inputFile_);
        }
        uint32_t index;
        OH_AVErrCode ret = OH_AudioCodec_QueryOutputBuffer(audioDec_, &index, 20000); // 20000us
        if (ret == AV_ERR_TRY_AGAIN_LATER) {
            // Timeout: exception handling. The timeout period is too short, or input/output buffers are not consumed/released (causing decoding blocking).
            continue;
        } else if (ret == AV_ERR_STREAM_CHANGED) {
            // Callback processing after the decoding output parameters are changed. The application performs processing as required.
            OH_AVFormat *outFormat = OH_AudioCodec_GetOutputDescription(audioDec_);
            int32_t sampleRate;
            int32_t channelCount;
            int32_t sampleFormat;
            if (OH_AVFormat_GetIntValue(outFormat, OH_MD_KEY_AUD_SAMPLE_RATE, &sampleRate)) {
                // Check whether the sample rate changes and perform processing as required.
            }
            if (OH_AVFormat_GetIntValue(outFormat, OH_MD_KEY_AUD_CHANNEL_COUNT, &channelCount)) {
                // Check whether the audio channel count changes and perform processing as required.
            }
            if (OH_AVFormat_GetIntValue(outFormat, OH_MD_KEY_AUDIO_SAMPLE_FORMAT, &sampleFormat)) {
                // Check whether the audio sample format changes and perform processing as required.
            }
            continue;
        }
        if (ret != AV_ERR_OK) {
            // Handle exceptions.
            break;
        }
        OH_AVBuffer *outputBuf = OH_AudioCodec_GetOutputBuffer(audioDec_, index);
        if (outputBuf == nullptr) {
            // Handle exceptions.
            break;
        }
        OH_AVCodecBufferAttr attr;
        if (OH_AVBuffer_GetBufferAttr(outputBuf, &attr) != AV_ERR_OK) {
            // Handle exceptions.
            break;
        }
        if (attr.flags & AVCODEC_BUFFER_FLAGS_EOS) {
            OH_AudioCodec_FreeOutputBuffer(audioDec_, index);
            // Decoding output completed.
            break;
        }
        outFile_.write(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(outputBuf)), attr.size);
        OH_AudioCodec_FreeOutputBuffer(audioDec_, index);
    }
    ```

9. (Optional) Call **OH_AudioCodec_Flush()** to refresh the decoder.

    After **OH_AudioCodec_Flush()** is called, the decoder remains in the running state, but the current queue is cleared and the buffer storing the decoded data is freed. The input and output buffers obtained before flushing cannot be reused.

    To continue decoding, you must call **OH_AudioCodec_Start()** again.

    You need to call **OH_AudioCodec_Start()** in the following cases:
    * Previously input data is no longer needed, for example, after seeking during demultiplexing.
    * The EOS of the file is reached.
    * An error with **OH_AudioCodec_IsValid** set to **true** (indicating that the execution can continue) occurs.

    ```c++
    // Refresh the decoder.
    OH_AVErrCode ret = OH_AudioCodec_Flush(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Start decoding again.
    ret = OH_AudioCodec_Start(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

10. (Optional) Call **OH_AudioCodec_Reset()** to reset the decoder.

    After **OH_AudioCodec_Reset()** is called, the decoder returns to the initialized state. To continue decoding, you must call **OH_AudioCodec_Configure()** and then **OH_AudioCodec_Start()**.

    ```c++
    // Reset the decoder.
    OH_AVErrCode ret = OH_AudioCodec_Reset(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // Reconfigure the decoder.
    ret = OH_AudioCodec_Configure(audioDec_, format);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

11. Call **OH_AudioCodec_Stop()** to stop the decoder.

    After the decoder is stopped, you can call **OH_AudioCodec_Start()** to start it again. The input and output buffers obtained before the decoder is stopped cannot be reused. You must obtain them again after the decoder is started.

    ```c++
    // Stop the decoder.
    OH_AVErrCode ret = OH_AudioCodec_Stop(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

12. Call **OH_AudioCodec_Destroy()** to destroy the decoder instance and release resources.

    > **NOTE**
    >
    > You only need to call this API once.

    ```c++
    // Call OH_AudioCodec_Destroy to destroy the decoder.
    OH_AVErrCode ret = OH_AudioCodec_Destroy(audioDec_);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    } else {
        audioDec_ = NULL; // The decoder cannot be destroyed repeatedly.
    }
    ```
