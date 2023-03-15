# OpenSL ES Audio Recording Development

## Introduction

You can use OpenSL ES to develop the audio recording function in OpenHarmony. Currently, only some [OpenSL ES APIs](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h) are implemented. If an API that has not been implemented is called, **SL_RESULT_FEATURE_UNSUPPORTED** will be returned.

## How to Develop

To use OpenSL ES to develop the audio recording function in OpenHarmony, perform the following steps:

1. Add the header files.

    ```c++
    #include <OpenSLES.h>
    #include <OpenSLES_OpenHarmony.h>
    #include <OpenSLES_Platform.h>
    ```

2. Use the **slCreateEngine** API to create and instantiate the **engine** instance.

    ```c++
    SLObjectItf engineObject = nullptr;
    slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
    (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
    ```

3. Obtain the **engineEngine** instance of the **SL_IID_ENGINE** interface.

    ```c++
    SLEngineItf engineItf = nullptr;
    result = (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineItf);
    ```

4. Configure the recorder information (including the input source **audiosource** and output source **audiosink**), and create a **pcmCapturerObject** instance.

    ```c++
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
        SL_DATAFORMAT_PCM,
        OHOS::AudioStandard::AudioChannel::MONO,
        OHOS::AudioStandard::AudioSamplingRate::SAMPLE_RATE_44100,
        OHOS::AudioStandard::AudioSampleFormat::SAMPLE_S16LE,
        0,
        0,
        0
    };

    SLDataSink audioSink = {
        &buffer_queue,
        &format_pcm
    };
    
    SLObjectItf pcmCapturerObject = nullptr;
    result = (*engineItf)->CreateAudioRecorder(engineItf, &pcmCapturerObject,
        &audioSource, &audioSink, 0, nullptr, nullptr);
    (*pcmCapturerObject)->Realize(pcmCapturerObject, SL_BOOLEAN_FALSE);
    ```

5. Obtain the **recordItf** instance of the **SL_IID_RECORD** interface.
 
    ```c++
    SLRecordItf  recordItf;
    (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_RECORD, &recordItf);
    ```   

6. Obtain the **bufferQueueItf** instance of the **SL_IID_OH_BUFFERQUEUE** interface.

    ```c++
    SLOHBufferQueueItf bufferQueueItf;
    (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
    ```

7. Register the **BufferQueueCallback** function.

    ```c++
    static void BufferQueueCallback(SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
    {
        AUDIO_INFO_LOG("BufferQueueCallback");
        FILE *wavFile = (FILE *)pContext;
        if (wavFile != nullptr) {
            SLuint8 *buffer = nullptr;
            SLuint32 pSize = 0;
            (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, pSize);
            if (buffer != nullptr) {
                fwrite(buffer, 1, pSize, wavFile);
                (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, size);
            } 
        }

        return;
    }
    
    // Set wavFile_ to the descriptor of the file to be recorded.
    (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BufferQueueCallback, wavFile_);
    ```

8. Start audio recording.

    ```c++
    static void CaptureStart(SLRecordItf recordItf, SLOHBufferQueueItf bufferQueueItf, FILE *wavFile)
    {
        AUDIO_INFO_LOG("CaptureStart");
        (*recordItf)->SetRecordState(recordItf, SL_RECORDSTATE_RECORDING);
        if (wavFile != nullptr) {
            SLuint8* buffer = nullptr;
            SLuint32 pSize = 0;
            (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, pSize);
            if (buffer != nullptr) {
                AUDIO_INFO_LOG("CaptureStart, enqueue buffer length: %{public}lu.", pSize);
                fwrite(buffer, 1, pSize, wavFile);
                (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, pSize);
            } else {
                AUDIO_INFO_LOG("CaptureStart, buffer is null or pSize: %{public}lu.", pSize);
            }
        }

        return;
    }
    ```

9. Stop audio recording.

    ```c++
    static void CaptureStop(SLRecordItf recordItf)
    {
        AUDIO_INFO_LOG("Enter CaptureStop");
        fflush(wavFile_);
        (*recordItf)->SetRecordState(recordItf, SL_RECORDSTATE_STOPPED);
        (*pcmCapturerObject)->Destroy(pcmCapturerObject);
        fclose(wavFile_);
        wavFile_ = nullptr;
        return;
    }  
    ```
