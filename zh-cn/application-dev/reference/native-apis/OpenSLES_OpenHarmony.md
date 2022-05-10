# OpenSLES_OpenHarmony.h


**Description:**  
提供录音过程中通过回调函数获取包含录音数据的buffer及使用后将buffer加入空闲队列的操作接口。

**Version:**  
1.0


### Functions  
  | Function | Description | 
| -------- | -------- |
| SLresult (*Enqueue)(SLOHBufferQueueItf self, const void *buffer, SLuint32 size) | 将保存完录音数据后的buffer加入空闲的buffer队列 |
| SLresult (*Clear) (SLOHBufferQueueItf self) | 录音结束后销毁BufferQueue接口对象 |
| SLresult (*GetBuffer) (SLOHBufferQueueItf self, SLuint8** buffer, SLuint32& size) | 获取从输入设备存入录音数据的buffer |
| SLresult (*RegisterCallback) (SLOHBufferQueueItf self, SlOHBufferQueueCallback callback, void* pContext) | 注册读取音频数据的回调函数 |



### **Details**
如下是对以上接口函数形参的解释
  | Function | Parameter introduction | 
| -------- | -------- |
| Enqueue（） |  SLOHBufferQueueItf self ：BufferQueue接口对象； const void *buffer: 使用后的空闲buffer； SLuint32 size：buffer 长度； |
| Clear（） |  SLOHBufferQueueItf self ：BufferQueue接口对象; |
| GetBuffer() |  SLOHBufferQueueItf self ：BufferQueue接口对象；  SLuint8** buffer: 获取带有录音数据的buffer； SLuint32& size：buffer 长度； |
| RegisterCallback() | SLOHBufferQueueItf self ：BufferQueue接口对象；  SlOHBufferQueueCallback callback: 回调函数；  void* pContext: 录音文件； |


### **Third party reference**

[接口函数使用详情参考](https://gitee.com/openharmony/third_party_opensles/blob/master/api/1.0.1/OpenSLES.h)