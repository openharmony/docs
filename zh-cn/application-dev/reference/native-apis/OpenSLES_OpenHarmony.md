# OpenSLES_OpenHarmony.h


**Description:**  
提供录音过程中通过回调函数获取包含录音数据的buffer及使用后将buffer加入空闲队列的操作接口。

**Version:**  
1.0


### Functions  
  | Function | Description | 
| -------- | -------- |
| SLresult (*Enqueue)(SLOHBufferQueueItf self, const void *buffer, SLuint32 size) | 将保存玩录音数据后的buffer加入空闲的buffer队列 |
| SLresult (*Clear) (SLOHBufferQueueItf self) | 录音结束后销毁BufferQueue接口对象 |
| SLresult (*GetState) (SLOHBufferQueueItf self, SLOHBufferQueueState *state) | 获取buffer的状态 |
| SLresult (*GetBuffer) (SLOHBufferQueueItf self, SLuint8** buffer, SLuint32& size) | 获取从输入设备存入录音数据的buffer |
| SLresult (*RegisterCallback) (SLOHBufferQueueItf self, SlOHBufferQueueCallback callback, void* pContext) | 注册读取音频数据的回调函数 |