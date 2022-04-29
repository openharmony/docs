# OpenSLES音频播放开发指导

 

## 场景介绍

OpenSL ES™ 是无授权费、跨平台、针对嵌入式系统精心优化的硬件音频加速API。 

 

## 开发步骤

以下步骤描述了在**openHarmony**如何使用 **OpenSLES** 开发音频播放功能：

1. 使用 **slCreateEngine** 接口和获取 **engine** 实例。

    ```c++
    SLObjectItf engineObject = nullptr;
    slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
    (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
    ```

    

2. 获取接口 **SL_IID_ENGINE** 的 **engineEngine** 实例

    ```c++
    SLEngineItf engineEngine = nullptr;
    (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineEngine);
    ```

    

3. 配置播放器信息，创建 **AudioPlayer** 。

    ```c++
    SLDataLocator_BufferQueue slBufferQueue = {
        SL_DATALOCATOR_BUFFERQUEUE,
        0
    };
    
    //具体参数需要根据音频文件格式进行适配
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

    

4. 获取接口 **SL_IID_OH_BUFFERQUEUE** 的 **bufferQueueItf** 实例

    ```
    SLOHBufferQueueItf bufferQueueItf;
    (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
    ```

    

5. 打开音频文件，注册 **BuqqerQueueCallback** 回调

    ```c++
    FILE *wavFile_ = nullptr;
    
    static void BuqqerQueueCallback (SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
    {
        FILE *wavFile = (FILE *)pContext;
        if (!feof(wavFile)) {
            SLuint8 *buffer = nullptr;
            SLuint32 pSize = 0;
            (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, pSize);
            //从文件读取数据
            fread(buffer, 1, size, wavFile);
            (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, size);
        }
        return;
    }
    
    //wavFile_ 需要设置为用户想要播放的文件描述符
    wavFile_ = fopen(path, "rb");
    (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BuqqerQueueCallback, wavFile_);
    ```

    

6. 获取接口 **SL_PLAYSTATE_PLAYING** 的 **playItf** 实例，开始播放

    ```c++
    SLPlayItf playItf = nullptr;
    (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_PLAY, &playItf);
    (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PLAYING);
    ```

    

7. 结束音频播放

    ```c++
    (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_STOPPED);
    (*pcmPlayerObject)->Destroy(pcmPlayerObject);
    (*engineObject)->Destroy(engineObject);
    ```

    

 [**OpenSLES** 音频播放代码 demo](https://gitee.com/openharmony/multimedia_audio_standard/blob/master/services/test/audio_opensles_test.cpp)