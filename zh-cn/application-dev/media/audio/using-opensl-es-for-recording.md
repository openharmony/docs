# 使用OpenSL ES开发音频录制功能(C/C++)

OpenSL ES全称为Open Sound Library for Embedded Systems，是一个嵌入式、跨平台、免费的音频处理库。为嵌入式移动多媒体设备上的应用开发者提供标准化、高性能、低延迟的API。OpenHarmony的Native API基于[Khronos Group](https://www.khronos.org/)开发的[OpenSL ES](https://www.khronos.org/opensles/) 1.0.1 API 规范实现，开发者可以通过&lt;OpenSLES.h&gt;和&lt;OpenSLES_OpenHarmony.h&gt;在OpenHarmony上使用相关API。

## 使用OHAudio替代OpenSL ES
OpenHarmony上的OpenSL ES接口，是早期SDK8版本开始提供，用于支持应用Native层音频开发的接口。但随着版本演进，接口定义的可扩展性不足，不再能满足音频系统的能力拓展，因此当前已不再推荐应用开发者继续使用此接口进行音频功能开发，可能存在一些接口能力不足的缺陷。

在SDK10版本，OpenHarmony推出了OHAudio接口，并将系统具备的所有音频功能都通过此接口开放。OHAudio接口已能够覆盖OpenSL ES在OpenHarmony中已提供的所有能力，并拓展支持音频焦点事件，低时延等新版本特性。

OHAudio的开发指南见[使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)

考虑到一些接入OpenHarmony较早的应用开发者，这里提供了一份OpenSL ES接口切换到OHAudio的对照参考[OpenSL ES接口切换OHAudio参考](replace-opensles-by-ohaudio.md)，便于开发者能够更快的在新版本切换到使用新接口。

## OpenHarmony上的OpenSL ES

OpenSL ES中提供了以下的接口，OpenHarmony当前仅实现了部分[接口](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h)，可以实现音频录制的基础功能。

调用未实现接口后会返回**SL_RESULT_FEATURE_UNSUPPORTED，**当前没有相关扩展可以使用。

以下列表列举了OpenHarmony上已实现的OpenSL ES的接口，具体说明请参考[OpenSL ES](https://www.khronos.org/opensles/)规范：

- **OpenHarmony上支持的SLInterfaceID**：

  | SLInterfaceID | 说明 |
  | -------- | -------- |
  | SL_IID_ENGINE | 通用引擎，提供创建录音对象接口 |
  | SL_IID_RECORD | 提供录音状态接口 |
  | SL_IID_OH_BUFFERQUEUE | 提供音频录制流数据回调注册接口 |

- **OpenHarmony上支持的Engine接口：**
  - SLresult (\*CreateAudioPlayer) (SLEngineItf self, SLObjectItf \* pPlayer, SLDataSource \*pAudioSrc, SLDataSink \*pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)
  - SLresult (\*CreateAudioRecorder) (SLEngineItf self, SLObjectItf \* pRecorder, SLDataSource \*pAudioSrc, SLDataSink \*pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)
  - SLresult (\*CreateOutputMix) (SLEngineItf self, SLObjectItf \* pMix, SLuint32 numInterfaces, const SLInterfaceID \* pInterfaceIds, const SLboolean \* pInterfaceRequired)

- **OpenHarmony上支持的Object接口：**
  - SLresult (\*Realize) (SLObjectItf self, SLboolean async)
  - SLresult (\*GetState) (SLObjectItf self, SLuint32 \* pState)
  - SLresult (\*GetInterface) (SLObjectItf self, const SLInterfaceID iid, void \* pInterface)
  - void (\*Destroy) (SLObjectItf self)

- **OpenHarmony上支持的Recorder接口：**
  - SLresult (\*SetRecordState) (SLRecordItf self, SLuint32 state)
  - SLresult (\*GetRecordState) (SLRecordItf self,SLuint32 \*pState)

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

参考下列示例代码，完成音频录制。

1. 添加头文件。

   ```c++
   #include "SLES/OpenSLES.h"
   #include "SLES/OpenSLES_OpenHarmony.h"
   #include "SLES/OpenSLES_Platform.h"
   ```

2. 使用slCreateEngine接口创建引擎对象和实例化引擎对象engine。
     
   ```c++
   SLObjectItf engineObject = nullptr;
   slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
   (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
   ```

3. 获取接口SL_IID_ENGINE的引擎接口engineEngine实例。
     
   ```c++
   SLEngineItf engineItf = nullptr;
   (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineItf);
   ```

4. 配置录音器信息（配置输入源audiosource、输出源audiosink），创建录音对象pcmCapturerObject。
     
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
   // 具体参数需要根据音频文件格式进行适配
   SLDataFormat_PCM format_pcm = {
       SL_DATAFORMAT_PCM,           // 输入的音频格式
       1,                           // 单声道
       SL_SAMPLINGRATE_44_1,        // 采样率: 44100HZ
       SL_PCMSAMPLEFORMAT_FIXED_16, // 音频采样格式, 小端, 带符号的16位整数
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

5. 获取录音接口SL_IID_RECORD的recordItf接口实例。
     
   ```c++
   SLRecordItf  recordItf;
   (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_RECORD, &recordItf);
   ```

6. 获取接口SL_IID_OH_BUFFERQUEUE的bufferQueueItf实例。
     
   ```c++
   SLOHBufferQueueItf bufferQueueItf;
   (*pcmCapturerObject)->GetInterface(pcmCapturerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
   ```

7. 注册BufferQueueCallback回调。
     
   ```c++
   static void BufferQueueCallback(SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
   {
       // 可从pContext获取注册时传入的使用者信息
       SLuint8 *buffer = nullptr;
       SLuint32 pSize = 0;
       (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, &pSize);
       if (buffer != nullptr) {
           // 可从buffer内读取录音数据进行后续处理 
           (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, size);
       }
   }
   void *pContext; // 可传入自定义的上下文信息，会在Callback内收到
   (*bufferQueueItf)->RegisterCallback(bufferQueueItf, BufferQueueCallback, pContext);
   ```

8. 开始录音。
     
   ```c++
   (*recordItf)->SetRecordState(recordItf, SL_RECORDSTATE_RECORDING);
   ```

9. 结束音频录制。
     
   ```c++
   (*recordItf)->SetRecordState(recordItf, SL_RECORDSTATE_STOPPED);
   (*pcmCapturerObject)->Destroy(pcmCapturerObject);
   (*engineObject)->Destroy(engineObject);
   ```
