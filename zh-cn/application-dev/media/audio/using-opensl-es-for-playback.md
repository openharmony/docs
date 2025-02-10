# 使用OpenSL ES开发音频播放功能(C/C++)

OpenSL ES全称为Open Sound Library for Embedded Systems，是一个嵌入式、跨平台、免费的音频处理库。为嵌入式移动多媒体设备上的应用开发者提供标准化、高性能、低延迟的API。OpenHarmony的Native API基于[Khronos Group](https://www.khronos.org/)开发的[OpenSL ES](https://www.khronos.org/opensles/) 1.0.1 API 规范实现，开发者可以通过&lt;OpenSLES.h&gt;和&lt;OpenSLES_OpenHarmony.h&gt;在OpenHarmony上使用相关API。

## 使用OHAudio替代OpenSL ES

OpenHarmony上的OpenSL ES接口，是早期SDK8版本开始提供，用于支持应用Native层音频开发的接口。但随着版本演进，接口定义的可扩展性不足，不再能满足音频系统的能力拓展，因此当前已不再推荐应用开发者继续使用此接口进行音频功能开发，可能存在一些接口能力不足的缺陷。

在SDK10版本，OpenHarmony推出了OHAudio接口，并将系统具备的所有音频功能都通过此接口开放。OHAudio接口已能够覆盖OpenSL ES在OpenHarmony中已提供的所有能力，并拓展支持音频焦点事件，低时延等新版本特性。

OHAudio的开发指南见[使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)

考虑到一些接入OpenHarmony较早的应用开发者，这里提供了一份OpenSL ES接口切换到OHAudio的对照参考[OpenSL ES接口切换OHAudio参考](replace-opensles-by-ohaudio.md)，便于开发者能够更快的在新版本切换到使用新接口。

## OpenHarmony上的OpenSL ES

OpenSL ES中提供了以下的接口，OpenHarmony当前仅实现了部分[接口](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h)，可以实现音频播放的基础功能。

调用未实现接口后会返回**SL_RESULT_FEATURE_UNSUPPORTED**, 当前没有相关扩展可以使用。

以下列表列举了OpenHarmony上已实现的OpenSL ES的接口，具体说明请参考[OpenSL ES](https://www.khronos.org/opensles/)规范：

- **OpenHarmony上支持的SLInterfaceID**：

  | SLInterfaceID | 说明 |
  | -------- | -------- |
  | SL_IID_ENGINE | 通用引擎，提供创建播放对象接口 |
  | SL_IID_PLAY | 提供播放状态接口 |
  | SL_IID_VOLUME | 提供音频播放流音量调节和读取接口 |
  | SL_IID_OH_BUFFERQUEUE | 提供音频播放流数据回调注册接口 |

- **OpenHarmony上支持的Engine接口：**
  - SLresult (\*CreateAudioPlayer) (SLEngineItf self, SLObjectItf \* pPlayer, SLDataSource \*pAudioSrc, SLDataSink \*pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)
  - SLresult (\*CreateAudioRecorder) (SLEngineItf self, SLObjectItf \* pRecorder, SLDataSource \*pAudioSrc, SLDataSink \*pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)
  - SLresult (\*CreateOutputMix) (SLEngineItf self, SLObjectItf \* pMix, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)

- **OpenHarmony上支持的Object接口：**
  - SLresult (\*Realize) (SLObjectItf self, SLboolean async)
  - SLresult (\*GetState) (SLObjectItf self, SLuint32 \* pState)
  - SLresult (\*GetInterface) (SLObjectItf self, const SLInterfaceID iid, void \* pInterface)
  - void (\*Destroy) (SLObjectItf self)

- **OpenHarmony上支持的Playback接口：**
  - SLresult (\*SetPlayState) (SLPlayItf self, SLuint32 state)
  - SLresult (\*GetPlayState) (SLPlayItf self, SLuint32 \*pState)

- **OpenHarmony上支持的Volume控制接口**：
  - SLresult (\*SetVolumeLevel) (SLVolumeItf self, SLmillibel level)
  - SLresult (\*GetVolumeLevel) (SLVolumeItf self, SLmillibel \*pLevel)
  - SLresult (\*GetMaxVolumeLevel) (SLVolumeItf  self, SLmillibel \*pMaxLevel)

- **OpenHarmony上支持的BufferQueue接口**：
   
   以下接口需引入&lt;OpenSLES_OpenHarmony.h&gt;使用。

  | 接口 | 说明 | 
  | -------- | -------- |
  | SLresult (\*Enqueue) (SLOHBufferQueueItf self, const void \*buffer, SLuint32 size) | 根据情况将buffer加到相应队列中。<br/>如果是播放操作，则将带有音频数据的buffer插入到filledBufferQ_队列中；如果是录音操作，则将录音使用后的空闲buffer插入到freeBufferQ_队列中。<br/>self：表示调用该函数的BufferQueue接口对象。<br/>buffer：播放时表示带有音频数据的buffer，录音时表示已存储完录音数据后的空闲buffer。<br/>size：表示buffer的大小。 | 
  | SLresult (\*Clear) (SLOHBufferQueueItf self) | 释放BufferQueue接口对象。<br/>self：表示调用该函数的BufferQueue接口对象将被释放。 | 
  | SLresult (\*GetState) (SLOHBufferQueueItf self, SLOHBufferQueueState \*state) | 获取BufferQueue接口对象状态。<br/>self：表示调用该函数的BufferQueue接口对象。<br/>state：BufferQueue的当前状态。 | 
  | SLresult (\*RegisterCallback) (SLOHBufferQueueItf self, SlOHBufferQueueCallback callback, void\* pContext) | 注册回调函数。<br/>self：表示调用该函数的BufferQueue接口对象。<br/>callback：播放/录音时注册的回调函数。<br/>pContext：播放时传入待播放音频文件，录音时传入将要录制的音频文件。 | 
  | SLresult (\*GetBuffer) (SLOHBufferQueueItf self, SLuint8\*\* buffer, SLuint32\* size) | 根据情况获取相应的buffer。<br/>如果是播放操作，则从freeBufferQ_队列中获取空闲buffer；如果是录音操作，则从filledBufferQ_队列中获取携带录音数据的buffer。<br/>self：表示调用该函数的BufferQueue接口对象。<br/>buffer：播放时表示空闲的buffer，录音时表示携带录音数据的buffer。<br/>size：表示buffer的大小。 | 

## 完整示例

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libOpenSLES.so)
```

参考以下示例代码，播放一个音频文件。

1. 添加头文件。
     
   ```cpp
   #include "SLES/OpenSLES.h"
   #include "SLES/OpenSLES_OpenHarmony.h"
   #include "SLES/OpenSLES_Platform.h"
   ```

2. 使用slCreateEngine接口和获取engine实例。
     
   ```cpp
   SLObjectItf engineObject = nullptr;
   slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
   (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
   ```

3. 获取接口SL_IID_ENGINE的engineEngine实例。
     
   ```cpp
   SLEngineItf engineEngine = nullptr;
   (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineEngine);
   ```

4. 配置播放器信息，创建AudioPlayer。
     
   ```cpp
   SLDataLocator_BufferQueue slBufferQueue = {
       SL_DATALOCATOR_BUFFERQUEUE,
       1
   };
   
   // 具体参数需要根据音频文件格式进行适配
   SLDataFormat_PCM pcmFormat = {
       SL_DATAFORMAT_PCM,
       2,                           // 通道数
       SL_SAMPLINGRATE_48,          // 采样率
       SL_PCMSAMPLEFORMAT_FIXED_16, // 音频采样格式
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

5. 获取接口SL_IID_OH_BUFFERQUEUE的bufferQueueItf实例。
     
   ```cpp
   SLOHBufferQueueItf bufferQueueItf;
   (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
   ```

6. 打开音频文件，注册BufferQueueCallback回调。
     
   ```cpp
   static void BufferQueueCallback (SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
   {
       SLuint8 *buffer = nullptr;
       SLuint32 pSize;
       (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, &pSize);
       // 将待播放音频数据写入buffer
       (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, size);
   }
   void *pContext; // 可传入自定义的上下文信息，会在Callback内收到
   (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BufferQueueCallback, pContext);
   ```

7. 获取接口SL_PLAYSTATE_PLAYING的playItf实例，开始播放。
     
   ```cpp
   SLPlayItf playItf = nullptr;
   (*pcmPlayerObject)->GetInterface(pcmPlayerObject, SL_IID_PLAY, &playItf);
   (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PLAYING);
   ```

8. 结束音频播放。
     
   ```cpp
   (*playItf)->SetPlayState(playItf, SL_PLAYSTATE_STOPPED);
   (*pcmPlayerObject)->Destroy(pcmPlayerObject);
   (*engineObject)->Destroy(engineObject);
   ```
