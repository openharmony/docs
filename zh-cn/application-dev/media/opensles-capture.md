# OpenSL ES音频播放开发指导

## 场景介绍

OpenSL ES™ 是无授权费、跨平台、针对嵌入式系统精心优化的硬件音频加速API。 

 

## 开发步骤

以下步骤描述了在**OpenHarmony**如何使用 **OpenSL ES** 开发音频录音功能：

1. 使用 **slCreateEngine** 接口创建引擎对象和实例化引擎对象 **engine**。

    ```c++
    SLObjectItf engineObject = nullptr;
    slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
    (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
    ```

    

2. 获取接口 **SL_IID_ENGINE** 的引擎接口 **engineEngine** 实例

    ```c++
    SLEngineItf engineItf = nullptr;
    result = (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineItf);
    ```

    

3. 配置录音器信息（配置输入源audiosource、输出源audiosink），创建录音对象**pcmCapturerObject** 。

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

4. 获取录音接口**SL_IID_RECORD** 的 **recordItf** 接口实例
 
    ```
    SLRecordItf  recordItf;
    (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_RECORD, &recordItf);
    ```   

5. 获取接口 **SL_IID_OH_BUFFERQUEUE** 的 **bufferQueueItf** 实例

    ```
    SLOHBufferQueueItf bufferQueueItf;
    (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
    ```

    

6. 注册 **BuqqerQueueCallback** 回调

    ```c++
    static void BuqqerQueueCallback(SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
    {
        AUDIO_INFO_LOG("BuqqerQueueCallback");
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
    
    //wavFile_ 需要设置为用户想要播放的文件描述符
    (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BuqqerQueueCallback, wavFile_);
    ```

    

7. 开始录音

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
                AUDIO_INFO_LOG("BuqqerQueueCallback, buffer is null or pSize: %{public}lu.", pSize);
            }
        }

        return;
    }
    ```

    

7. 结束录音

    ```c++
    (*recordItf)->SetRecordState(recordItf, SL_RECORDSTATE_STOPPED);
    (*pcmCapturerObject)->Destroy(pcmCapturerObject);
    (*engineObject)->Destroy(engineObject);
    fclose(wavFile_);
    wavFile_ = nullptr;    
    ```


## 相关实例 

针对OpenSL ES音频录音，有以下示例可供参考：  
 [**OpenSL ES** 音频播放代码 demo](https://gitee.com/openharmony/multimedia_audio_standard/blob/master/services/test/audio_opensles_capture_test.cpp)