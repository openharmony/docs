# Using OpenSL ES for Audio Recording (C/C++)

OpenSL ES, short for Open Sound Library for Embedded Systems, is an embedded, cross-platform audio processing library that is free of charge. It provides high-performance and low-latency APIs for you to develop applications running on embedded mobile multimedia devices. OpenHarmony has implemented certain native APIs based on [OpenSL ES](https://www.khronos.org/opensles/) 1.0.1 API specifications developed by the [Khronos Group](https://www.khronos.org/). You can use these APIs through &lt;OpenSLES.h&gt; and &lt;OpenSLES_OpenHarmony.h&gt;.

## Using OHAudio to Replace OpenSL ES
OpenHarmony provides the OpenSL ES APIs for audio development at the native layer since SDK8. As the version evolves, these APIs fail to meet the capability expansion requirements of the audio system and therefore are no longer recommended.

In SDK 10, OpenHarmony provides the OHAudio APIs, which open up all audio functions of the system. The OHAudio APIs cover all the capabilities provided by OpenSL ES in OpenHarmony. They also support new features such as audio focus events and low latency.

For details about how to use the OHAudio APIs for audio development, see [Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md).

If you have used the OpenSL ES APIs in your code, you can switch them to the OHAudio APIs. For details, see [Switching from OpenSL ES to OHAudio (C/C++)](replace-opensles-by-ohaudio.md).

## OpenSL ES on OpenHarmony

Currently, OpenHarmony implements parts of [OpenSL ES APIs](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h) to implement basic audio recording functionalities.

If an API that has not been implemented on OpenHarmony is called, **SL_RESULT_FEATURE_UNSUPPORTED** is returned.

The following lists the OpenSL ES APIs that have been implemented on OpenHarmony. For details, see the [OpenSL ES](https://www.khronos.org/opensles/) specifications.

- **SLInterfaceID implemented on OpenHarmony**

  | SLInterfaceID | Description|
  | -------- | -------- |
  | SL_IID_ENGINE | Universal engine, which provides the interface for creating capturer objects.|
  | SL_IID_RECORD | Provides the capturer status interface.|
  | SL_IID_OH_BUFFERQUEUE | Provides the callback registration interface for audio recording stream data.|

- **Engine APIs implemented on OpenHarmony**
  - SLresult (\*CreateAudioPlayer) (SLEngineItf self, SLObjectItf \* pPlayer, SLDataSource \*pAudioSrc, SLDataSink \*pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)
  - SLresult (\*CreateAudioRecorder) (SLEngineItf self, SLObjectItf \* pRecorder, SLDataSource \*pAudioSrc, SLDataSink \*pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)
  - SLresult (\*CreateOutputMix) (SLEngineItf self, SLObjectItf \* pMix, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)

- **Object APIs implemented on OpenHarmony**
  - SLresult (\*Realize) (SLObjectItf self, SLboolean async)
  - SLresult (\*GetState) (SLObjectItf self, SLuint32 \* pState)
  - SLresult (\*GetInterface) (SLObjectItf self, const SLInterfaceID iid, void \* pInterface)
  - void (\*Destroy) (SLObjectItf self)

- **Recorder APIs implemented on OpenHarmony**
  - SLresult (\*SetRecordState) (SLRecordItf self, SLuint32 state)
  - SLresult (\*GetRecordState) (SLRecordItf self,SLuint32 \*pState)

- **BufferQueue APIs implemented on OpenHarmony**
  
  The APIs listed below can be used only after &lt;OpenSLES_OpenHarmony.h&gt; is introduced.

  | API| Description| 
  | -------- | -------- |
  | SLresult (\*Enqueue) (SLOHBufferQueueItf self, const void \*buffer, SLuint32 size) | Adds a buffer to the corresponding queue.<br>For an audio playback operation, this API adds the buffer with audio data to the **filledBufferQ_** queue. For an audio recording operation, this API adds the idle buffer after recording data storage to the **freeBufferQ_** queue.<br>The **self** parameter indicates the BufferQueue object that calls this API.<br>The **buffer** parameter indicates the pointer to the buffer with audio data or the pointer to the idle buffer after the recording data is stored.<br>The **size** parameter indicates the size of the buffer.| 
  | SLresult (\*Clear) (SLOHBufferQueueItf self) | Releases a BufferQueue object.<br>The **self** parameter indicates the BufferQueue object that calls this API.| 
  | SLresult (\*GetState) (SLOHBufferQueueItf self, SLOHBufferQueueState \*state) | Obtains the state of a BufferQueue object.<br>The **self** parameter indicates the BufferQueue object that calls this API.<br>The **state** parameter indicates the pointer to the state of the BufferQueue object.| 
  | SLresult (\*RegisterCallback) (SLOHBufferQueueItf self, SlOHBufferQueueCallback callback, void\* pContext) | Registers a callback.<br>The **self** parameter indicates the BufferQueue object that calls this API.<br>The **callback** parameter indicates the callback to be registered for the audio playback or recording operation.<br>The **pContext** parameter indicates the pointer to the audio file to be played for an audio playback operation or the pointer to the audio file to be recorded for an audio recording operation.| 
  | SLresult (\*GetBuffer) (SLOHBufferQueueItf self, SLuint8\*\* buffer, SLuint32\* size) | Obtains a buffer.<br>For an audio playback operation, this API obtains an idle buffer from the **freeBufferQ_** queue. For an audio recording operation, this API obtains the buffer that carries recording data from the **filledBufferQ_** queue.<br>The **self** parameter indicates the BufferQueue object that calls this API.<br>The **buffer** parameter indicates the double pointer to the idle buffer or the buffer carrying recording data.<br>The **size** parameter indicates the size of the buffer.| 

## Sample Code

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libOpenSLES.so)
```

Refer to the sample code below to record an audio file.

1. Add the header files.

   ```cpp
   #include "SLES/OpenSLES.h"
   #include "SLES/OpenSLES_OpenHarmony.h"
   #include "SLES/OpenSLES_Platform.h"
   ```

2. Use the **slCreateEngine** API to create and instantiate an engine object.
     
   ```cpp
   SLObjectItf engineObject = nullptr;
   slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
   (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
   ```

3. Obtain the engineEngine instance of the **SL_IID_ENGINE** API.
     
   ```cpp
   SLEngineItf engineItf = nullptr;
   (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineItf);
   ```

4. Configure the recorder information (including the input source **audiosource** and output source **audiosink**), and create a pcmCapturerObject instance.
     
   ```cpp
   SLDataLocator_IODevice io_device = {
       SL_DATALOCATOR_IODEVICE,
       SL_IODEVICE_AUDIOINPUT,
       SL_DEFAULTDEVICEID_AUDIOINPUT,
       NULL
   };
   SLDataSource audioSource = {
       &io_device,
       NULL
   };
   SLDataLocator_BufferQueue buffer_queue = {
       SL_DATALOCATOR_BUFFERQUEUE,
       3
   };
   // Configure the parameters based on the audio file format.
   SLDataFormat_PCM format_pcm = {
       SL_DATAFORMAT_PCM,           // Input audio format.
       1,                           // Mono channel.
       SL_SAMPLINGRATE_44_1,        // Sampling rate, 44100 Hz.
       SL_PCMSAMPLEFORMAT_FIXED_16, // Audio sampling format, a signed 16-bit integer in little-endian format.
       16,
       SL_SPEAKER_FRONT_LEFT,
       SL_BYTEORDER_LITTLEENDIAN
   };
   SLDataSink audioSink = {
       &buffer_queue,
       &format_pcm
   };
   
   SLObjectItf pcmCapturerObject = nullptr;
   (*engineItf)->CreateAudioRecorder(engineItf, &pcmCapturerObject,
       &audioSource, &audioSink, 0, nullptr, nullptr);
   (*pcmCapturerObject)->Realize(pcmCapturerObject, SL_BOOLEAN_FALSE);
   ```

5. Obtain the recordItf instance of the **SL_IID_RECORD** API.
     
   ```cpp
   SLRecordItf  recordItf;
   (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_RECORD, &recordItf);
   ```

6. Obtain the bufferQueueItf instance of the **SL_IID_OH_BUFFERQUEUE** API.
     
   ```cpp
   SLOHBufferQueueItf bufferQueueItf;
   (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
   ```

7. Register the **BufferQueueCallback** function.
     
   ```cpp
   static void BufferQueueCallback(SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
   {
       // Obtain the user information passed in during the registration from pContext.
       SLuint8 *buffer = nullptr;
       SLuint32 pSize = 0;
       (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, &pSize);
       if (buffer != nullptr) {
           // The recording data can be read from the buffer for subsequent processing.
           (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, size);
       }
   }
   void *pContext; // This callback can be used to obtain the custom context information passed in.
   (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BufferQueueCallback, pContext);
   ```

8. Start audio recording.
     
   ```cpp
   (*recordItf)->SetRecordState(recordItf, SL_RECORDSTATE_RECORDING);
   ```

9. Stop audio recording.
     
   ```cpp
   (*recordItf)->SetRecordState(recordItf, SL_RECORDSTATE_STOPPED);
   (*pcmCapturerObject)->Destroy(pcmCapturerObject);
   (*engineObject)->Destroy(engineObject);
   ```
