# OpenSL ES音频播放开发指导 

## 简介

开发者可以通过本文档了解在**OpenHarmony**中如何使用**OpenSL ES**进行音频播放相关操作；当前仅实现了部分[**OpenSL ES**接口](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h)，因此调用未实现接口后会返回**SL_RESULT_FEATURE_UNSUPPORTED**
 
## 开发指导

以下步骤描述了在**OpenHarmony**如何使用**OpenSL ES**开发音频播放功能：

1. 添加头文件

    ```c++
    #include <OpenSLES.h>
    #include <OpenSLES_OpenHarmony.h>
    #include <OpenSLES_Platform.h>
    ```

2. 使用 **slCreateEngine** 接口和获取 **engine** 实例

    ```c++
    SLObjectItf engineObject = nullptr;
    slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
    (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
    ```

3. 获取接口 **SL_IID_ENGINE** 的 **engineEngine** 实例

    ```c++
    SLEngineItf engineEngine = nullptr;
    (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineEngine);
    ```

4. 配置播放器信息，创建 **AudioPlayer** 

    ```c++
    SLDataLocator_BufferQueue slBufferQueue = {
        SL_DATALOCATOR_BUFFERQUEUE,
        0
    };
    
    // 具体参数需要根据音频文件格式进行适配
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

5. 获取接口 **SL_IID_OH_BUFFERQUEUE** 的 **bufferQueueItf** 实例

    ```c++
    SLOHBufferQueueItf bufferQueueItf;
    (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
    ```

6. 打开音频文件，注册 **BufferQueueCallback** 回调

    ```c++
    FILE *wavFile_ = nullptr;
    
    static void BufferQueueCallback (SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
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
    
    // wavFile_ 需要设置为用户想要播放的文件描述符
    wavFile_ = fopen(path, "rb");
    (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BufferQueueCallback, wavFile_);
    ```

7. 获取接口 **SL_PLAYSTATE_PLAYING** 的 **playItf** 实例，开始播放

    ```c++
    SLPlayItf playItf = nullptr;
    (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_PLAY, &playItf);
    (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PLAYING);
    ```

8. 结束音频播放

    ```c++
    (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_STOPPED);
    (*pcmPlayerObject)->Destroy(pcmPlayerObject);
    (*engineObject)->Destroy(engineObject);
    ```