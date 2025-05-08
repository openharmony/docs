# Using OpenSL ES for Audio Playback (C/C++)

OpenSL ES, short for Open Sound Library for Embedded Systems, is an embedded, cross-platform audio processing library that is free of charge. It provides high-performance and low-latency APIs for you to develop applications running on embedded mobile multimedia devices. OpenHarmony has implemented certain native APIs based on [OpenSL ES](https://www.khronos.org/opensles/) 1.0.1 API specifications developed by the [Khronos Group](https://www.khronos.org/). You can use these APIs through <OpenSLES.h\> and <OpenSLES_OpenHarmony.h\>.

## Using OHAudio to Replace OpenSL ES

OpenHarmony provides the OpenSL ES APIs for audio development at the native layer since SDK8. As the version evolves, these APIs fail to meet the capability expansion requirements of the audio system and therefore are no longer recommended.

In SDK 10, OpenHarmony provides the **OHAudio** APIs, which open up all audio functions of the system. The **OHAudio** APIs cover all the capabilities provided by OpenSL ES in OpenHarmony. They also support new features such as audio focus events and low latency.

For details about how to use the **OHAudio** APIs for audio development, see [Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md).

If you have used the OpenSL ES APIs in your code, you can switch them to the **OHAudio** APIs. For details, see [Switching from OpenSL ES to OHAudio (C/C++)](replace-opensles-by-ohaudio.md).

## OpenSL ES on OpenHarmony

Currently, OpenHarmony implements parts of [OpenSL ES APIs](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h) to implement basic audio playback functionalities.

If an API that has not been implemented on OpenHarmony is called, **SL_RESULT_FEATURE_UNSUPPORTED** is returned.

The following lists the OpenSL ES APIs that have been implemented on OpenHarmony. For details, see the [OpenSL ES](https://www.khronos.org/opensles/) specifications.

- **SLInterfaceID implemented on OpenHarmony**

  | SLInterfaceID | Description|
  | -------- | -------- |
  | SL_IID_ENGINE | Universal engine, which provides the interface for creating player objects.|
  | SL_IID_PLAY | Provides the player status interface.|
  | SL_IID_VOLUME | Provides interfaces for adjusting and reading the volume of audio playback streams.|
  | SL_IID_OH_BUFFERQUEUE | Provides the callback registration interface for audio playback stream data.|

- **Engine APIs implemented on OpenHarmony**
  - SLresult (\*CreateAudioPlayer) (SLEngineItf self, SLObjectItf \* pPlayer, SLDataSource \*pAudioSrc, SLDataSink \*pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)
  - SLresult (\*CreateAudioRecorder) (SLEngineItf self, SLObjectItf \* pRecorder, SLDataSource \*pAudioSrc, SLDataSink \*pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)
  - SLresult (\*CreateOutputMix) (SLEngineItf self, SLObjectItf \* pMix, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)

- **Object APIs implemented on OpenHarmony**
  - SLresult (\*Realize) (SLObjectItf self, SLboolean async)
  - SLresult (\*GetState) (SLObjectItf self, SLuint32 \* pState)
  - SLresult (\*GetInterface) (SLObjectItf self, const SLInterfaceID iid, void \* pInterface)
  - void (\*Destroy) (SLObjectItf self)

- **Playback APIs implemented on OpenHarmony**
  - SLresult (\*SetPlayState) (SLPlayItf self, SLuint32 state)
  - SLresult (\*GetPlayState) (SLPlayItf self, SLuint32 \*pState)

- **Volume control APIs implemented on OpenHarmony**
  - SLresult (\*SetVolumeLevel) (SLVolumeItf self, SLmillibel level)
  - SLresult (\*GetVolumeLevel) (SLVolumeItf self, SLmillibel \*pLevel)
  - SLresult (\*GetMaxVolumeLevel) (SLVolumeItf  self, SLmillibel \*pMaxLevel)

- **BufferQueue APIs implemented on OpenHarmony**
   
   The APIs listed below can be used only after <OpenSLES_OpenHarmony.h\> is introduced.

  | API| Description| 
  | -------- | -------- |
  | SLresult (\*Enqueue) (SLOHBufferQueueItf self, const void \*buffer, SLuint32 size) | Adds a buffer to the corresponding queue.<br>For an audio playback operation, this API adds the buffer with audio data to the **filledBufferQ_** queue. For an audio recording operation, this API adds the idle buffer after recording data storage to the **freeBufferQ_** queue.<br>The **self** parameter indicates the **BufferQueue** object that calls this API.<br>The **buffer** parameter indicates the pointer to the buffer with audio data or the pointer to the idle buffer after the recording data is stored.<br>The **size** parameter indicates the size of the buffer.| 
  | SLresult (\*Clear) (SLOHBufferQueueItf self) | Releases a **BufferQueue** object.<br>The **self** parameter indicates the **BufferQueue** object that calls this API.| 
  | SLresult (\*GetState) (SLOHBufferQueueItf self, SLOHBufferQueueState \*state) | Obtains the state of a **BufferQueue** object.<br>The **self** parameter indicates the **BufferQueue** object that calls this API.<br>The **state** parameter indicates the pointer to the state of the **BufferQueue** object.| 
  | SLresult (\*RegisterCallback) (SLOHBufferQueueItf self, SlOHBufferQueueCallback callback, void\* pContext) | Registers a callback.<br>The **self** parameter indicates the **BufferQueue** object that calls this API.<br>The **callback** parameter indicates the callback to be registered for the audio playback or recording operation.<br>The **pContext** parameter indicates the pointer to the audio file to be played for an audio playback operation or the pointer to the audio file to be recorded for an audio recording operation.| 
  | SLresult (\*GetBuffer) (SLOHBufferQueueItf self, SLuint8\*\* buffer, SLuint32\* size) | Obtains a buffer.<br>For an audio playback operation, this API obtains an idle buffer from the **freeBufferQ_** queue. For an audio recording operation, this API obtains the buffer that carries recording data from the **filledBufferQ_** queue.<br>The **self** parameter indicates the **BufferQueue** object that calls this API.<br>The **buffer** parameter indicates the double pointer to the idle buffer or the buffer carrying recording data.<br>The **size** parameter indicates the size of the buffer.| 

## Sample Code

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libOpenSLES.so)
```

Refer to the sample code below to play an audio file.

1. Add the header files.
     
   ```cpp
   #include "SLES/OpenSLES.h"
   #include "SLES/OpenSLES_OpenHarmony.h"
   #include "SLES/OpenSLES_Platform.h"
   ```

2. Use the **slCreateEngine** API to obtain an **engine** instance.
     
   ```cpp
   SLObjectItf engineObject = nullptr;
   slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
   (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
   ```

3. Obtain the **engineEngine** instance of the **SL_IID_ENGINE** API.
     
   ```cpp
   SLEngineItf engineEngine = nullptr;
   (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineEngine);
   ```

4. Configure the player and create an **AudioPlayer** instance.
     
   ```cpp
   SLDataLocator_BufferQueue slBufferQueue = {
       SL_DATALOCATOR_BUFFERQUEUE,
       1
   };
   
   // Configure the parameters based on the audio file format.
   SLDataFormat_PCM pcmFormat = {
       SL_DATAFORMAT_PCM,
       2,                           // Number of channels.
       SL_SAMPLINGRATE_48,          // Sampling rate.
       SL_PCMSAMPLEFORMAT_FIXED_16, // Audio sample format.
       16,
       SL_SPEAKER_FRONT_LEFT | SL_SPEAKER_FRONT_RIGHT,
       SL_BYTEORDER_LITTLEENDIAN
   };
   SLDataSource slSource = {
      &slBufferQueue,
      &pcmFormat
   };
   SLObjectItf pcmPlayerObject = nullptr;
   (*engineEngine)->CreateAudioPlayer(engineEngine,
                                      &pcmPlayerObject,
                                      &slSource,
                                      &slSink,
                                      0,
                                      nullptr,
                                      nullptr);
   (*pcmPlayerObject)->Realize(pcmPlayerObject, SL_BOOLEAN_FALSE);
   ```

5. Obtain the **bufferQueueItf** instance of the **SL_IID_OH_BUFFERQUEUE** API.
     
   ```cpp
   SLOHBufferQueueItf bufferQueueItf;
   (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
   ```

6. Open an audio file and register the **BufferQueueCallback** function.
     
   ```cpp
   static void BufferQueueCallback (SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
   {
       SLuint8 *buffer = nullptr;
       SLuint32 pSize;
       (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, &pSize);
       // Write the audio data to be played to the buffer.
       (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, size);
   }
   void *pContext; // This callback can be used to obtain the custom context information passed in.
   (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BufferQueueCallback, pContext);
   ```

7. Obtain the **playItf** instance of the **SL_PLAYSTATE_PLAYING** API and start playing.
     
   ```cpp
   SLPlayItf playItf = nullptr;
   (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_PLAY, &playItf);
   (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PLAYING);
   ```

8. Stop playing.
     
   ```cpp
   (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_STOPPED);
   (*pcmPlayerObject)->Destroy(pcmPlayerObject);
   (*engineObject)->Destroy(engineObject);
   ```
