# Native api中支持的OpenSL ES接口列表

## 简介

OpenSL ES（Open Sound Library for Embedded System）即嵌入式音频加速标准。为开发者提供了标准化、高性能以及低响应时间的音频功能开发的对象和接口。相对于开源免费的OpenSL ES，OpenHarmony基于[OpenSL ES](https://www.khronos.org/opensles/) 1.0.1 API规范实现了部分Native API，相关接口开放情况介绍如下：

## 支持的API

|对象                |对外接口               |接口调用详情                                                                           |是否支持   |说明                  |
| ------------------ | -------------------- | -------------------------------------------------------------------------------------|----------| -------------------- |
|SLEngineItf         |CreateAudioPlayer     |CreateAudioPlayer(SLEngineItf self, SLObjectItf *pPlayer, SLDataSource *pAudioSrc, SLDataSink *pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired) |是        |创建音频播放机。        |
|SLEngineItf         |CreateAudioRecorder   |reateAudioRecorder(SLEngineItf self, SLObjectItf *pRecorder, SLDataSource *pAudioSrc, SLDataSink *pAudioSnk, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired)|是        |创建音频录制器。        |
|SLEngineItf         |CreateAudioOutputMix  |CreateOutputMix(SLEngineItf self, SLObjectItf *pMix, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired)|是        |创建混音器。            |
|SLObjectItf         |Realize               |Realize(SLObjectItf self, SLboolean async)                                            |是        |创建音频播放机。        |
|SLObjectItf         |getState              |GetState(SLObjectItf self, SLuint32 *state)                                           |是        |获取状态。             |
|SLObjectItf         |getInterface          |GetInterface(SLObjectItf self, const SLInterfaceID iid, void *interface)              |是        |获取接口。             |
|SLObjectItf         |Destroy               |Destroy(SLObjectItf self)                                                             |是        |销毁对象。             |
|SLOHBufferQueueItf  |Enqueue               |Enqueue(SLOHBufferQueueItf self, const void *buffer, SLuint32 size)                   |是        |将buffer加入实际队列中。|
|SLOHBufferQueueItf  |clear                 |Clear(SLOHBufferQueueItf self)                                                        |是        |释放buffer队列         |
|SLOHBufferQueueItf  |getState              |GetState(SLOHBufferQueueItf self, SLOHBufferQueueState *state)                        |是        |获取BufferQueue状态。  |
|SLOHBufferQueueItf  |getBuffer             |GetBuffer(SLOHBufferQueueItf self, SLuint8 **buffer, SLuint32 *size)                  |是        |获取buffer。           |
|SLOHBufferQueueItf  |RegisterCallback      |RegisterCallback(SLOHBufferQueueItf self, SlOHBufferQueueCallback callback, void *pContext) |是  |注册回调函数。          |
|SLPlayItf           |SetPlayState          |SetPlayState(SLPlayItf self, SLuint32 state)                                          |是        |设置播放状态。          |
|SLPlayItf           |GetPlayState          |GetPlayState(SLPlayItf self, SLuint32 *state)                                         |是        |获取播放状态。          |
|SLRecordItf         |SetRecordState        |SetRecordState(SLRecordItf self, SLuint32 state)                                      |是        |设置录制状态。          |
|SLRecordItf         |GetRecordState        |GetRecordState(SLRecordItf self, SLuint32 *pState)                                    |是        |获取录制状态。          |
|SLVolumeItf         |SetVolumeLevel        |SetVolumeLevel(SLVolumeItf self, SLmillibel *level)                                   |是        |设置音量。              |
|SLVolumeItf         |GetVolumeLevel        |GetVolumeLevel(SLVolumeItf self, SLmillibel level)                                    |是        |获取音量。              |
|SLVolumeItf         |GetMaxVolumeLevel     |GetMaxVolumeLevel(SLVolumeItf self, SLmillibel *maxLevel)                             |是        |获取最大音量。          |