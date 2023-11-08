# Audio Encoding

You can call the native APIs provided by the **AudioEncoder** module to encode audio, that is, to compress audio PCM data into a desired format.

PCM data can be from any source. For example, you can use a microphone to record audio data or import edited PCM data. After audio encoding, you can output streams in the desired format and encapsulate the streams into a target file.

Currently, the following encoding capabilities are supported:

| Container Specification| Audio Encoding Type|
| -------- | :----------- |
| mp4      | AAC, FLAC   |
| m4a      | AAC          |
| flac     | FLAC        |
| aac      | AAC          |

**Usage Scenario**

- Audio recording

  Record and pass in PCM data, and encode the data into streams in the desired format.
- Audio editing

  Export edited PCM data, and encode the data into streams in the desired format.

## How to Develop

Read [AudioEncoder](../reference/native-apis/_audio_encoder.md) for the API reference.

Refer to the code snippet below to complete the entire audio encoding process, including creating an encoder, setting encoding parameters (such as the sampling rate, bit rate, and number of audio channels), and starting, refreshing, resetting, and destroying the encoder.

During application development, you must call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur. 

For details about the complete code, see [Sample](https://gitee.com/openharmony/multimedia_av_codec/blob/master/test/nativedemo/audio_demo/avcodec_audio_aac_encoder_demo.cpp).

The figure below shows the call relationship of audio encoding.

![Call relationship of audio encoding](figures/audio-encode.png)

### Linking the Dynamic Library in the CMake Script
``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_aenc.so)
```

### How to Develop

1. Create an encoder instance.

   You can create an encoder by name or MIME type.

   ```cpp
   // Namespace of the C++ standard library.
   using namespace std;
   // Create an encoder by name.
   OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
   const char *name = OH_AVCapability_GetName(capability);
   OH_AVCodec *audioEnc = OH_AudioEncoder_CreateByName(name);
   ```
   ```cpp
   // Create an encoder by MIME type.
   OH_AVCodec *audioEnc = OH_AudioEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC); 
   ```
   ```cpp
   // Initialize the queues.
   class AEncSignal {
   public:
       mutex inMutex_;
       mutex outMutex_;
       mutex startMutex_;
       condition_variable inCond_;
       condition_variable outCond_;
       condition_variable startCond_;
       queue<uint32_t> inQueue_;
       queue<uint32_t> outQueue_;
       queue<OH_AVMemory *> inBufferQueue_;
       queue<OH_AVMemory *> outBufferQueue_;
       queue<OH_AVCodecBufferAttr> attrQueue_;
   };
   AEncSignal *signal_ = new AEncSignal();
   ```
2. Call **OH_AudioEncoder_SetCallback()** to set callback functions.

   Register the **OH_AVCodecAsyncCallback** struct that defines the following callback function pointers:

   - **OH_AVCodecOnError**, a callback used to report a codec operation error
   - **OH_AVCodecOnStreamChanged**, a callback used to report a codec stream change, for example, audio channel change
   - **OH_AVCodecOnNeedInputData**, a callback used to report input data required, which means that the encoder is ready for receiving PCM data
   - **OH_AVCodecOnNewOutputData**, a callback used to report output data generated, which means that encoding is complete

   You need to process the callback functions to ensure that the encoder runs properly.

   ```cpp
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
   // Implement the OH_AVCodecOnNeedInputData callback function.
   static void OnNeedInputData(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
   {
       (void)codec;
       // The input stream is sent to the InputBuffer queue.
       AEncSignal *signal = static_cast<AEncSignal *>(userData);
       unique_lock<mutex> lock(signal->inMutex_);
       signal->inQueue_.push(index);
       signal->inBufferQueue_.push(data);
       signal->inCond_.notify_all();
   }
   // Implement the OH_AVCodecOnNewOutputData callback function.
   static void OnNeedOutputData(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr,
                                           void *userData)
   {
       (void)codec;
       // The index of the output buffer is sent to OutputQueue_.
       // The encoded data is sent to the outBuffer queue.
       AEncSignal *signal = static_cast<AEncSignal *>(userData);
       unique_lock<mutex> lock(signal->outMutex_);
       signal->outQueue_.push(index);
       signal->outBufferQueue_.push(data);
       if (attr) {
           signal->attrQueue_.push(*attr);
       }
   }
   signal_ = new AEncSignal();
   OH_AVCodecAsyncCallback cb = {&OnError, &OnStreamChanged, &OnNeedInputData, &OnNeedOutputData};
   // Set the asynchronous callbacks.
   int32_t ret = OH_AudioEncoder_SetCallback(audioEnc, cb, signal_);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   ```
3. Call **OH_AudioEncoder_Configure** to configure the encoder.

   The following options are mandatory: sampling rate, bit rate, number of audio channels, audio channel type, and bit depth. The maximum input length is optional.

   For FLAC encoding, the compliance level and sampling precision are also mandatory.
   
   The following provides the AAC invoking process.
   ```cpp
   #include "avcodec_audio_channel_layout.h"
   
   int32_t ret;
   // (Mandatory) Configure the audio sampling rate.
   constexpr uint32_t DEFAULT_SAMPLERATE = 44100; 
   // (Mandatory) Configure the audio bit rate.
   constexpr uint64_t DEFAULT_BITRATE = 32000;
   // (Mandatory) Configure the number of audio channels.
   constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
   // (Mandatory) Configure the audio channel type.
   constexpr AudioChannelLayout CHANNEL_LAYOUT = AudioChannelLayout::STEREO;
   // (Mandatory) Configure the audio bit depth. Only SAMPLE_F32P is available for AAC encoding.
   constexpr OH_BitsPerSample SAMPLE_FORMAT = OH_BitsPerSample::SAMPLE_F32LE;
   // Configure the audio compliance level. The default value is 0, and the value ranges from -2 to 2.
   constexpr int32_t COMPLIANCE_LEVEL = 0;
   // (Mandatory) Configure the audio sampling precision. SAMPLE_S16LE, SAMPLE_S24LE, and SAMPLE_S32LE are available.
   constexpr uint32_t BITS_PER_CODED_SAMPLE = OH_BitsPerSample::SAMPLE_S24LE;
   // (Optional) Configure the maximum input length.
   constexpr uint32_t DEFAULT_MAX_INPUT_SIZE = 1024*DEFAULT_CHANNEL_COUNT *sizeof(float);//aac
   OH_AVFormat *format = OH_AVFormat_Create();
   // Set the format.
   OH_AVFormat_SetIntValue(format,OH_MD_KEY_AUD_CHANNEL_COUNT,DEFAULT_CHANNEL_COUNT);
   OH_AVFormat_SetIntValue(format,OH_MD_KEY_AUD_SAMPLE_RATE,DEFAULT_SAMPLERATE);
   OH_AVFormat_SetLongValue(format,OH_MD_KEY_BITRATE, DEFAULT_BITRATE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUDIO_SAMPLE_FORMAT, SAMPLE_FORMAT);
   OH_AVFormat_SetLongValue(format,OH_MD_KEY_CHANNEL_LAYOUT,CHANNEL_LAYOUT);
   OH_AVFormat_SetIntValue(format,OH_MD_KEY_MAX_INPUT_SIZE,DEFAULT_MAX_INPUT_SIZE);
   // Configure the encoder.
   ret = OH_AudioEncoder_Configure(audioEnc, format);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   ```
   The following provides the FLAC invoking process.
   ```cpp
   #include "avcodec_audio_channel_layout.h"
   
   int32_t ret;
   // (Mandatory) Configure the audio sampling rate.
   constexpr uint32_t DEFAULT_SMAPLERATE = 44100; 
   // (Mandatory) Configure the audio bit rate.
   constexpr uint64_t DEFAULT_BITRATE = 32000;
   // (Mandatory) Configure the number of audio channels.
   constexpr uint32_t DEFAULT_CHANNEL_COUNT = 2;
   // (Mandatory) Configure the audio channel type.
   constexpr AudioChannelLayout CHANNEL_LAYOUT = AudioChannelLayout::STEREO;
   // (Mandatory) Configure the audio bit depth. Only SAMPLE_S16LE and SAMPLE_S32LE are available for FLAC encoding.
   constexpr OH_BitsPerSample SAMPLE_FORMAT = OH_BitsPerSample::SAMPLE_S32LE;
   // Configure the audio compliance level. The default value is 0, and the value ranges from -2 to 2.
   constexpr int32_t COMPLIANCE_LEVEL = 0;
   // (Mandatory) Configure the audio sampling precision. SAMPLE_S16LE, SAMPLE_S24LE, and SAMPLE_S32LE are available.
   constexpr uint32_t BITS_PER_CODED_SAMPLE = OH_BitsPerSample::SAMPLE_S24LE;
   OH_AVFormat *format = OH_AVFormat_Create();
   // Set the format.
   OH_AVFormat_SetIntValue(format,OH_MD_KEY_AUD_CHANNEL_COUNT,DEFAULT_CHANNEL_COUNT);
   OH_AVFormat_SetIntValue(format,OH_MD_KEY_AUD_SAMPLE_RATE,DEFAULT_SMAPLERATE);
   OH_AVFormat_SetLongValue(format,OH_MD_KEY_BITRATE, DEFAULT_BITRATE);
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_BITS_PER_CODED_SAMPLE, BITS_PER_CODED_SAMPLE); 
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUDIO_SAMPLE_FORMAT, SAMPLE_FORMAT); 
   OH_AVFormat_SetLongValue(format,OH_MD_KEY_CHANNEL_LAYOUT,CHANNEL_LAYOUT);
   OH_AVFormat_SetLongValue(format, OH_MD_KEY_COMPLIANCE_LEVEL, COMPLIANCE_LEVEL); 
   // Configure the encoder.
   ret = OH_AudioEncoder_Configure(audioEnc, format);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   ```
4. Call **OH_AudioEncoder_Prepare()** to prepare internal resources for the encoder.

   ```c++
   OH_AudioEncoder_Prepare(audioEnc);
   ```
5. Call **OH_AudioEncoder_Start()** to start the encoder.

   ```c++
   unique_ptr<ifstream> inputFile_ = make_unique<ifstream>();
   unique_ptr<ofstream> outFile_ = make_unique<ofstream>();
   // Open the path of the binary file to be encoded.
   inputFile_->open(inputFilePath.data(), ios::in |ios::binary); 
   // Configure the path of the output file.
   outFile_->open(outputFilePath.data(), ios::out |ios::binary);
   // Start encoding.
   ret = OH_AudioEncoder_Start(audioEnc);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   ```
6. Call **OH_AudioEncoder_PushInputData()** to write the data to encode.

   To indicate the End of Stream (EOS), pass in the **AVCODEC_BUFFER_FLAGS_EOS** flag.

   For AAC encoding, **FRAME_SIZE** (number of sampling points) is fixed at **1024**.

   For FLAC encoding, set **FRAME_SIZE** based on the table below.

   | Sampling Rate| FRAME_SIZE|
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

   **NOTE**: If **FRAME_SIZE** is not set to **1024** for AAC encoding, an error code is returned. In the case of FLAC encoding, if **FRAME_SIZE** is set to a value greater than the value listed in the table for a given sampling rate, an error code is returned; if **FRAME_SIZE** is set to a value less than the value listed, the encoded file may be damaged.
   
   
      ```c++
      constexpr int32_t FRAME_SIZE = 1024; // AAC encoding
      constexpr int32_t DEFAULT_CHANNEL_COUNT = 2;
      constexpr int32_t INPUT_FRAME_BYTES = DEFAULT_CHANNEL_COUNT * FRAME_SIZE * sizeof(float); // AAC encoding
      // Configure the buffer information.
      OH_AVCodecBufferAttr info;
      // Set the size, offset, and timestamp.
      info.size = INPUT_FRAME_BYTES;
      info.offset = 0;
      info.flags = AVCODEC_BUFFER_FLAGS_CODEC_DATA;
      auto buffer = signal_->inBufferQueue_.front();
      if (inputFile_->eof()){
          info.size = 0;
          info.flags = AVCODEC_BUFFER_FLAGS_EOS;
      }else{
          inputFile_->read((char *)OH_AVMemory_GetAddr(buffer), INPUT_FRAME_BYTES);
      }
      uint32_t index = signal_->inQueue_.front();
      // Send the data to the input queue for encoding. The index is the subscript of the queue.
      int32_t ret = OH_AudioEncoder_PushInputData(audioEnc, index,info);
      if (ret != AV_ERR_OK) {
          // Exception handling.
      }
      ```
   
7. Call **OH_AudioEncoder_FreeOutputData()** to output the encoded stream.

   ```c++
   OH_AVCodecBufferAttr attr = signal_->attrQueue_.front();
   OH_AVMemory *data = signal_->outBufferQueue_.front();
   uint32_t index = signal_->outQueue_.front();
   // Write the encoded data (specified by data) to the output file.
   outFile_->write(reinterpret_cast<char *>(OH_AVMemory_GetAdd(data)), attr.size);
   // Release the output buffer.
   ret = OH_AudioEncoder_FreeOutputData(audioEnc, index);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   if (attr.flags == AVCODEC_BUFFER_FLAGS_EOS) {
       cout << "decode eos" << endl;
       isRunning_.store(false);
       break;
   }
   ```
8. (Optional) Call **OH_AudioEncoder_Flush()** to refresh the encoder.

   After **OH_AudioEncoder_Flush()** is called, the current encoding queue is cleared.

   To continue encoding, you must call **OH_AudioEncoder_Start()** again.

   You need to call **OH_AudioEncoder_Flush()** in the following cases:

   * The EOS of the file is reached.
   * An error with **OH_AudioEncoder_IsValid** set to **true** (indicating that the execution can continue) occurs.

   ```c++
   // Refresh the encoder.
   ret = OH_AudioEncoder_Flush(audioEnc);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   // Start encoding again.
   ret = OH_AudioEncoder_Start(audioEnc);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   ```
9. (Optional) Call **OH_AudioEncoder_Reset()** to reset the encoder.

   After **OH_AudioEncoder_Reset()** is called, the encoder returns to the initialized state. To continue encoding, you must call **OH_AudioEncoder_Configure()** and then **OH_AudioEncoder_Start()**.

   ```c++
   // Reset the encoder.
   ret = OH_AudioEncoder_Reset(audioEnc);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   // Reconfigure the encoder.
   ret = OH_AudioEncoder_Configure(audioEnc, format);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   ```
10. Call **OH_AudioEncoder_Stop()** to stop the encoder.

    ```c++
    // Stop the encoder.
    ret = OH_AudioEncoder_Stop(audioEnc);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    ```
11. Call **OH_AudioEncoder_Destroy()** to destroy the encoder instance and release resources.

    **NOTE**: You only need to call this API once.

    ```c++
    // Call OH_AudioEncoder_Destroy to destroy the encoder.
    ret = OH_AudioEncoder_Destroy(audioEnc);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    } else {
        audioEnc = NULL; // The encoder cannot be destroyed repeatedly.
    }
    ```