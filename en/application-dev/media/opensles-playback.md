# OpenSL ES Audio Playback Development

## Introduction

You can use OpenSL ES to develop the audio playback function in OpenHarmony. Currently, only some [OpenSL ES APIs](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h) are implemented. If an API that has not been implemented is called, **SL_RESULT_FEATURE_UNSUPPORTED** will be returned.
 
## How to Develop

To use OpenSL ES to develop the audio playback function in OpenHarmony, perform the following steps:

1. Add the header files.

    ```c++
    #include <OpenSLES.h>
    #include <OpenSLES_OpenHarmony.h>
    #include <OpenSLES_Platform.h>
    ```

2. Use the **slCreateEngine** API to obtain an **engine** instance.

    ```c++
    SLObjectItf engineObject = nullptr;
    slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
    (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
    ```

3. Obtain the **engineEngine** instance of the **SL_IID_ENGINE** interface.

    ```c++
    SLEngineItf engineEngine = nullptr;
    (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineEngine);
    ```

4. Configure the player and create an **AudioPlayer** instance.

    ```c++
    SLDataLocator_BufferQueue slBufferQueue = {
        SL_DATALOCATOR_BUFFERQUEUE,
        0
    };
    
    // Configure the parameters based on the audio file format.
    SLDataFormat_PCM pcmFormat = {
        SL_DATAFORMAT_PCM,
        2,
        48000,
        16,
        0,
        0,
        0
    };
    SLDataSource slSource = {&slBufferQueue, &pcmFormat};
    
    SLObjectItf pcmPlayerObject = nullptr;
    (*engineEngine)->CreateAudioPlayer(engineEngine, &pcmPlayerObject, &slSource, null, 0, nullptr, nullptr);
    (*pcmPlayerObject)->Realize(pcmPlayerObject, SL_BOOLEAN_FALSE);
    ```

5. Obtain the **bufferQueueItf** instance of the **SL_IID_OH_BUFFERQUEUE** interface.

    ```c++
    SLOHBufferQueueItf bufferQueueItf;
    (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
    ```

6. Open an audio file and register the **BufferQueueCallback** function.

    ```c++
    FILE *wavFile_ = nullptr;
    
    static void BufferQueueCallback (SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
    {
        FILE *wavFile = (FILE *)pContext;
        if (!feof(wavFile)) {
            SLuint8 *buffer = nullptr;
            SLuint32 pSize = 0;
            (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, pSize);
            // Read data from the file.
            fread(buffer, 1, size, wavFile);
            (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, size);
        }
        return;
    }
    
    // Set wavFile_ to the descriptor of the file to be played.
    wavFile_ = fopen(path, "rb");
    (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BufferQueueCallback, wavFile_);
    ```

7. Obtain the **playItf** instance of the **SL_PLAYSTATE_PLAYING** interface and start playback.

    ```c++
    SLPlayItf playItf = nullptr;
    (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_PLAY, &playItf);
    (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PLAYING);
    ```

8. Stop audio playback.

    ```c++
    (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_STOPPED);
    (*pcmPlayerObject)->Destroy(pcmPlayerObject);
    (*engineObject)->Destroy(engineObject);
    ```
