# OpenSL ES音频录制开发指导

## 简介

开发者可以通过本文档了解在**OpenHarmony**中如何使用**OpenSL ES**进行录音相关操作；当前仅实现了部分[**OpenSL ES**接口](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h)，因此调用未实现接口后会返回**SL_RESULT_FEATURE_UNSUPPORTED**。

## 开发指导

以下步骤描述了在**OpenHarmony**如何使用 **OpenSL ES** 开发音频录音功能：

1. 添加头文件

    ```c++
    #include <OpenSLES.h>
    #include <OpenSLES_OpenHarmony.h>
    #include <OpenSLES_Platform.h>
    ```

2. 使用 **slCreateEngine** 接口创建引擎对象和实例化引擎对象 **engine**

    ```c++
    SLObjectItf engineObject = nullptr;
    slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
    (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
    ```

3. 获取接口 **SL_IID_ENGINE** 的引擎接口 **engineEngine** 实例

    ```c++
    SLEngineItf engineItf = nullptr;
    result = (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineItf);
    ```

4. 配置录音器信息（配置输入源audiosource、输出源audiosink），创建录音对象**pcmCapturerObject**

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

    //具体参数需要根据音频文件格式进行适配
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

5. 获取录音接口**SL_IID_RECORD** 的 **recordItf** 接口实例
 
    ```c++
    SLRecordItf  recordItf;
    (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_RECORD, &recordItf);
    ```   

6. 获取接口 **SL_IID_OH_BUFFERQUEUE** 的 **bufferQueueItf** 实例

    ```c++
    SLOHBufferQueueItf bufferQueueItf;
    (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
    ```

7. 注册 **BufferQueueCallback** 回调

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
    
    //wavFile_ 需要设置为用户想要录音的文件描述符
    (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BufferQueueCallback, wavFile_);
    ```

8. 开始录音

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

9. 结束录音

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