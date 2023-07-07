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
| [OH_NativeVSync](_native_vsync.md#oh_nativevsync) | 提供OH_NativeVSync结构体声明 |
| (\*[OH_NativeVSync_FrameCallback](_native_vsync.md#oh_nativevsync_framecallback)) (long long timestamp, void \*data) | VSync回调函数类型 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeVSync_Create](_native_vsync.md#oh_nativevsync_create) (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例 |
| [OH_NativeVSync_Destroy](_native_vsync.md#oh_nativevsync_destroy) (OH_NativeVSync \*nativeVsync) | 销毁OH_NativeVSync实例 |
| [OH_NativeVSync_RequestFrame](_native_vsync.md#oh_nativevsync_requestframe) (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback |
