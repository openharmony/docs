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
| [OHNativeErrorCode](_native_vsync.md#ohnativeerrorcode-1) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br/>} | 接口错误码说明（仅用于查询）。  | 

### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeVSync_Create](_native_vsync.md#oh_nativevsync_create) (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例 |
| [OH_NativeVSync_Destroy](_native_vsync.md#oh_nativevsync_destroy) (OH_NativeVSync \*nativeVsync) | 销毁OH_NativeVSync实例 |
| int [OH_NativeVSync_RequestFrame](_native_vsync.md#oh_nativevsync_requestframe) ([OH_NativeVSync](_native_vsync.md#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](_native_vsync.md#oh_nativevsync_framecallback) callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback。 如果在同一帧内中多次调用此接口，则只会触发最后一个回调。 | 
| int [OH_NativeVSync_RequestFrameWithMultiCallback](_native_vsync.md#oh_nativevsync_requestframewithmulticallback) ([OH_NativeVSync](_native_vsync.md#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](_native_vsync.md#oh_nativevsync_framecallback) callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback。 如果在同一帧内中多次调用此接口，每一次传入的callback都会被执行。 | 
| [OH_NativeVSync_GetPeriod](_native_vsync.md#oh_nativevsync_getperiod) (OH_NativeVSync \*nativeVsync, long long \*period) |获取vsync周期。|