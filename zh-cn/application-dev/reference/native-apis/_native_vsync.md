# NativeVsync


## 概述

提供NativeVsync功能。

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**起始版本:**

9


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [native_vsync.h](native__vsync_8h.md) | 定义获取和使用NativeVsync的相关函数<br/>引用文件：&lt;native_vsync/native_vsync.h&gt; |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeVSync](#oh_nativevsync) | 提供OH_NativeVSync结构体声明 |
| (\*[OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback)) (long long timestamp, void \*data) | VSync回调函数类型 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeVSync_Create](#oh_nativevsync_create) (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例 |
| [OH_NativeVSync_Destroy](#oh_nativevsync_destroy) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync) | 销毁OH_NativeVSync实例 |
| [OH_NativeVSync_RequestFrame](#oh_nativevsync_requestframe) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback) callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback |


## 类型定义说明


### OH_NativeVSync


```
typedef struct OH_NativeVSync OH_NativeVSync
```

**描述:**

提供OH_NativeVSync结构体声明


### OH_NativeVSync_FrameCallback


```
typedef void(* OH_NativeVSync_FrameCallback) (long long timestamp, void *data)
```

**描述:**

VSync回调函数类型

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| timestamp | VSync时间戳 |
| data | 用户自定义数据 |


## 函数说明


### OH_NativeVSync_Create()


```
OH_NativeVSync* OH_NativeVSync_Create (const char * name, unsigned int length )
```

**描述:**

创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| name | 表示一个名字，与创建的OH_NativeVSync实例关联 |
| length | name的长度 |

**返回:**

返回一个指向OH_NativeVSync实例的指针


### OH_NativeVSync_Destroy()


```
void OH_NativeVSync_Destroy (OH_NativeVSync * nativeVsync)
```

**描述:**

销毁OH_NativeVSync实例

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| nativeVsync | 一个指向OH_NativeVSync实例的指针 |


### OH_NativeVSync_RequestFrame()


```
int OH_NativeVSync_RequestFrame (OH_NativeVSync * nativeVsync, OH_NativeVSync_FrameCallback callback, void * data )
```

**描述:**

请求下一次vsync信号，当信号到来时，调用回调函数callback

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| nativeVsync | 一个指向OH_NativeVSync实例的指针 |
| callback | 一个OH_NativeVSync_FrameCallback类型的函数指针，当下一次vsync信号到来时会被调用 |
| data | 一个指向用户自定义数据结构的指针，类型是void\* |

**返回:**

返回值为0表示执行成功
