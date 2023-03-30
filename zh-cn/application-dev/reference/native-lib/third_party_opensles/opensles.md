# Open-SLES

## 简介

OpenSLES（Open Sound Library for Embedded System）即嵌入式音频加速标准。为开发者提供了标准化、高性能以及低响应时间的音频功能开发的对象和接口。相对于开源免费的OpenSLES，OpenHarmony基于OpenSLES1.0.1 API规范实现了部分Native API，相关接口开放情况介绍如下：

## 支持的API

|对象                |对外接口               |接口调用详情              |是否支持   |说明                  |
| ------------------ | -------------------- | --------------------| -------  | -------------------- |
|SLEngineItf         |CreateAudioPlayer     |CreateAudioPlayer( SLEngineItf self, SLObjectItf *pPlayer, SLDataSource *pAudioSrc, SLDataSink *pAudioSnk, SLuint32 numInterfaces,
    const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired)                   |是        |创建音频播放机。        |
|SLEngineItf         |CreateAudioRecorder   |是                   |是        |创建音频录制器。        |
|SLEngineItf         |CreateAudioOutputMix  |是                   |是        |创建混音器。            |
|SLObjectItf         |Realize               |是                   |是        |创建音频播放机。        |
|SLObjectItf         |getState              |是                   |是        |获取状态。             |
|SLObjectItf         |getInterface          |是                   |是        |获取接口。             |
|SLObjectItf         |Destroy               |是                   |是        |销毁对象。             |
|SLOHBufferQueueItf  |Enqueue               |是                   |是        |将buffer加入实际队列中。|
|SLOHBufferQueueItf  |clear                 |是                   |是        |释放buffer队列         |
|SLOHBufferQueueItf  |getState              |是                   |是        |获取BufferQueue状态。  |
|SLOHBufferQueueItf  |getBuffer             |是                   |是        |获取buffer。           |
|SLOHBufferQueueItf  |RegisterCallback      |是                   |是        |注册回调函数。          |
|SLPlayItf           |SetPlayState          |是                   |是        |设置播放状态。          |
|SLPlayItf           |GetPlayState          |是                   |是        |获取播放状态。          |
|SLRecordItf         |SetRecordState        |是                   |是        |设置录制状态。          |
|SLRecordItf         |GetRecordState        |是                   |是        |获取录制状态。          |
|SLVolumeItf         |SetVolumeLevel        |是                   |是        |设置音量。              |
|SLVolumeItf         |GetVolumeLevel        |是                   |是        |获取音量。              |
|SLVolumeItf         |GetMaxVolumeLevel     |是                   |是        |获取最大音量。          |