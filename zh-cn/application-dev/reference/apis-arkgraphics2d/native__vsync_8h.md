# native_vsync.h


## 概述

定义获取和使用NativeVsync的相关函数

**起始版本:**

9

**相关模块:**

[NativeVsync](_native_vsync.md)


## 汇总


### 类型定义

| 类型名称 | 描述 |
| -------- | -------- |
| typedef enum [OHNativeErrorCode](_native_vsync.md#ohnativeerrorcode) [OHNativeErrorCode](_native_vsync.md#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。  | 
| typedef struct [OH_NativeVSync](_native_vsync.md#oh_nativevsync) [OH_NativeVSync](_native_vsync.md#oh_nativevsync) | 提供OH_NativeVSync结构体声明。  | 
| typedef void(\* [OH_NativeVSync_FrameCallback](_native_vsync.md#oh_nativevsync_framecallback)) (long long timestamp, void \*data) | VSync回调函数类型。  | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeErrorCode](_native_vsync.md#ohnativeerrorcode-1) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_MEM_OPERATION_ERROR = 30001000, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br/>} | 接口错误码说明（仅用于查询）。  | 

### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeVSync_Create](_native_vsync.md#oh_nativevsync_create) (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例。 |
| [OH_NativeVSync](_native_vsync.md#oh_nativevsync) \* [OH_NativeVSync_Create_ForAssociatedWindow](_native_vsync.md#oh_nativevsync_create_forassociatedwindow) (uint64_t windowID, const char \*name, unsigned int length) | 创建一个和窗口绑定的OH_NativeVSync实例，每次调用都会产生一个新的实例。 | 
| [OH_NativeVSync_Destroy](_native_vsync.md#oh_nativevsync_destroy) (OH_NativeVSync \*nativeVsync) | 销毁OH_NativeVSync实例。 |
| int [OH_NativeVSync_RequestFrame](_native_vsync.md#oh_nativevsync_requestframe) ([OH_NativeVSync](_native_vsync.md#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](_native_vsync.md#oh_nativevsync_framecallback) callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback。 如果在同一帧内中多次调用此接口，则只会触发最后一个回调。 | 
| int [OH_NativeVSync_RequestFrameWithMultiCallback](_native_vsync.md#oh_nativevsync_requestframewithmulticallback) ([OH_NativeVSync](_native_vsync.md#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](_native_vsync.md#oh_nativevsync_framecallback) callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback。 如果在同一帧内中多次调用此接口，每一次传入的callback都会被执行。 | 
| [OH_NativeVSync_GetPeriod](_native_vsync.md#oh_nativevsync_getperiod) (OH_NativeVSync \*nativeVsync, long long \*period) |获取vsync周期。|
| int [OH_NativeVSync_DVSyncSwitch](_native_vsync.md#oh_nativevsync_dvsyncswitch) ([OH_NativeVSync](_native_vsync.md#oh_nativevsync) \*nativeVsync, bool enable) | 启用DVSync以提高自绘制动画场景的流畅性。 DVSync是Decoupled VSync的缩写，它是一种与硬件VSync解耦的帧时序管理策略。<br/>DVSync通过提前发送带有未来时间戳的VSync信号驱动后续动画帧的提前绘制，这些帧会被帧缓冲队列缓存；DVSync通过缓存的帧减少未来可能发生的丢帧，进而提高动画场景的流畅性。<br/>因为DVSync需要占用空闲的自绘制帧缓冲用于缓存提前绘制的动画帧，用户需要确保至少有一个空闲的帧缓冲区，否则不建议启用此功能。<br/>启用DVSync后，用户需要正确响应提前发送的VSync信号，并在前一个VSync对应的动画帧完成后再请求下一个VSync，且自绘制帧需要携带与VSync一致的时间戳。<br/>在动画结束之后，用户需要关闭DVSync。<br/>在不支持DVSync的平台或者如果有另一个应用程序已经启用了DVSync，则当前的启用操作将不会生效，应用程序仍将收到正常的VSync信号。 | 