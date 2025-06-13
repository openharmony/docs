# NativeVsync


## 概述

提供获取系统vsync回调的功能，可用于实现应用的绘制帧率与系统帧率同步。

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**起始版本:**

9


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [native_vsync.h](native__vsync_8h.md) | 定义获取和使用NativeVsync的相关函数。<br/>**引用文件：** &lt;native_vsync/native_vsync.h&gt; <br/>**库：** libnative_vsync.so |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [OHNativeErrorCode](#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。  | 
| typedef struct [OH_NativeVSync](#oh_nativevsync)  [OH_NativeVSync](#oh_nativevsync) | 提供OH_NativeVSync结构体声明。  | 
| typedef void(\* [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback)) (long long timestamp, void \*data) | VSync回调函数类型。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_MEM_OPERATION_ERROR = 30001000, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000,NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000,<br/>NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br/>} | 接口错误码说明（仅用于查询）。  | 


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeVSync_Create](#oh_nativevsync_create) (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例。 |
| [OH_NativeVSync](#oh_nativevsync) \* [OH_NativeVSync_Create_ForAssociatedWindow](#oh_nativevsync_create_forassociatedwindow) (uint64_t windowID, const char \*name, unsigned int length) | 创建一个和窗口绑定的OH_NativeVSync实例，每次调用都会产生一个新的实例。 | 
| [OH_NativeVSync_Destroy](#oh_nativevsync_destroy) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync) | 销毁OH_NativeVSync实例。 |
| int [OH_NativeVSync_RequestFrame](#oh_nativevsync_requestframe) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback) callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback。 如果在同一帧内中多次调用此接口，则只会触发最后一个回调。<br/>如果此接口与[OH_NativeVSync_RequestFrameWithMultiCallback](#oh_nativevsync_requestframewithmulticallback)接口在同一帧内被调用，则此接口的功能不会生效。 | 
| int [OH_NativeVSync_RequestFrameWithMultiCallback](#oh_nativevsync_requestframewithmulticallback) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback) callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback。 如果在同一帧内中多次调用此接口，每一次传入的callback都会被执行。 | 
| [OH_NativeVSync_GetPeriod](#oh_nativevsync_getperiod) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, long long \*period) |获取vsync周期。|
| int [OH_NativeVSync_DVSyncSwitch](#oh_nativevsync_dvsyncswitch) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, bool enable) | 启用DVSync以提高自绘制动画场景的流畅性。 DVSync是Decoupled VSync的缩写，它是一种与硬件VSync解耦的帧时序管理策略。<br/>DVSync通过提前发送带有未来时间戳的VSync信号驱动后续动画帧的提前绘制，这些帧会被帧缓冲队列缓存；DVSync通过缓存的帧减少未来可能发生的丢帧，进而提高动画场景的流畅性。<br/>因为DVSync需要占用空闲的自绘制帧缓冲用于缓存提前绘制的动画帧，用户需要确保至少有一个空闲的帧缓冲区，否则不建议启用此功能。<br/>启用DVSync后，用户需要正确响应提前发送的VSync信号，并在前一个VSync对应的动画帧完成后再请求下一个VSync，且自绘制帧需要携带与VSync一致的时间戳。<br/>在动画结束之后，用户需要关闭DVSync。<br/>在不支持DVSync的平台或者如果有另一个应用程序已经启用了DVSync，则当前的启用操作将不会生效，应用程序仍将收到正常的VSync信号。 | 

## 类型定义说明


### OH_NativeVSync


```
typedef struct OH_NativeVSync OH_NativeVSync
```

**描述:**

提供OH_NativeVSync结构体声明。


### OH_NativeVSync_FrameCallback


```
typedef void(* OH_NativeVSync_FrameCallback) (long long timestamp, void *data)
```

**描述:**

VSync回调函数类型。

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| timestamp | VSync使用CLOCK_MONOTONIC获取的系统时间戳，单位为纳秒。 |
| data | 用户自定义数据。 |


### OHNativeErrorCode

```
typedef enum OHNativeErrorCode OHNativeErrorCode
```

**描述：**

接口错误码说明（仅用于查询）。

**起始版本：** 12


## 枚举类型说明


### OHNativeErrorCode

```
enum OHNativeErrorCode
```

**描述：**

接口错误码说明（仅用于查询）。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NATIVE_ERROR_OK  | 成功。   | 
| NATIVE_ERROR_MEM_OPERATION_ERROR<sup>15+</sup> | 内存操作错误。 | 
| NATIVE_ERROR_INVALID_ARGUMENTS  | 入参无效。   | 
| NATIVE_ERROR_NO_PERMISSION  | 无权限操作。   | 
| NATIVE_ERROR_NO_BUFFER  | 无空闲可用的buffer。   | 
| NATIVE_ERROR_NO_CONSUMER  | 消费端不存在。   | 
| NATIVE_ERROR_NOT_INIT  | 未初始化。   | 
| NATIVE_ERROR_CONSUMER_CONNECTED  | 消费端已经被连接。   | 
| NATIVE_ERROR_BUFFER_STATE_INVALID  | buffer状态不符合预期。   | 
| NATIVE_ERROR_BUFFER_IN_CACHE  | buffer已在缓存队列中。   | 
| NATIVE_ERROR_BUFFER_QUEUE_FULL  | 队列已满。   | 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE  | buffer不在缓存队列中。   | 
| NATIVE_ERROR_CONSUMER_DISCONNECTED | 消费端已经被断开连接。 |
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED | 消费端未注册listener回调函数。 |
| NATIVE_ERROR_UNSUPPORTED  | 当前设备或平台不支持。   | 
| NATIVE_ERROR_UNKNOWN  | 未知错误，请查看日志。   | 
| NATIVE_ERROR_HDI_ERROR  | HDI接口调用失败。   | 
| NATIVE_ERROR_BINDER_ERROR  | 跨进程通信失败。   |  
| NATIVE_ERROR_EGL_STATE_UNKNOWN  | egl环境状态异常。   | 
| NATIVE_ERROR_EGL_API_FAILED  | egl接口调用失败。   | 

## 函数说明


### OH_NativeVSync_DVSyncSwitch()

```
int OH_NativeVSync_DVSyncSwitch (OH_NativeVSync* nativeVsync, bool enable )
```

**描述：**

启用DVSync以提高自绘制动画场景的流畅性。 DVSync是Decoupled VSync的缩写，它是一种与硬件VSync解耦的帧时序管理策略。

DVSync通过提前发送带有未来时间戳的VSync信号驱动后续动画帧的提前绘制，这些帧会被帧缓冲队列缓存；DVSync通过缓存的帧减少未来可能发生的丢帧，进而提高动画场景的流畅性。

因为DVSync需要占用空闲的自绘制帧缓冲用于缓存提前绘制的动画帧，用户需要确保至少有一个空闲的帧缓冲区，否则不建议启用此功能。

启用DVSync后，用户需要正确响应提前发送的VSync信号，并在前一个VSync对应的动画帧完成后再请求下一个VSync，且自绘制帧需要携带与VSync一致的时间戳。

在动画结束之后，用户需要关闭DVSync。

在不支持DVSync的平台或者如果有另一个应用程序已经启用了DVSync，则当前的启用操作将不会生效，应用程序仍将收到正常的VSync信号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeVsync

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nativeVsync | 一个指向OH_NativeVSync实例的指针。 | 
| enable | 表示打开或者关闭DVSync，true表示打开，false表示关闭。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。



### OH_NativeVSync_GetPeriod()


```
int OH_NativeVSync_GetPeriod (OH_NativeVSync * nativeVsync, long long * period )
```

**描述:**

获取vsync周期。

vsync周期是在每次使用OH_NativeVSync_RequestFrame接口请求vsync信号后收到OH_NativeVSync_FrameCallback回调的时候才会更新。

首次使用该接口获取vsync周期之前，需要先使用OH_NativeVSync_RequestFrame接口请求vsync信号，在收到OH_NativeVSync_FrameCallback回调之后，才可以通过该接口获取到vsync周期。

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| nativeVsync | 一个指向OH_NativeVSync实例的指针。|
| period | 表示vsync周期，作为出参使用。 |

**返回:**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。

**起始版本：**

10


### OH_NativeVSync_Create()


```
OH_NativeVSync* OH_NativeVSync_Create (const char * name, unsigned int length )
```

**描述:**

创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例。

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| name | 表示一个名字，与创建的OH_NativeVSync实例关联。 |
| length | name的长度（字符数）。 |

**返回:**

返回一个指向OH_NativeVSync实例的指针。


### OH_NativeVSync_Create_ForAssociatedWindow()

```
OH_NativeVSync* OH_NativeVSync_Create_ForAssociatedWindow (uint64_t windowID, const char* name, unsigned int length )
```

**描述：**

创建一个和窗口绑定的OH_NativeVSync实例，每次调用都会产生一个新的实例。

使用本接口创建出来的OH_NativeVSync实例的实际vsync周期与系统vsync周期不完全一致，系统会根据窗口的状态对实际vsync周期进行调整。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeVsync

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| windowID | 表示窗口ID，窗口子进程索引标识符，可以通过[OH_NativeWindow_GetSurfaceId](_native_window.md#oh_nativewindow_getsurfaceid)接口获取。 | 
| name | 表示一个名称，与创建的OH_NativeVSync实例关联。 | 
| length | name的长度（字符数）。 | 

**返回：**

返回一个指向OH_NativeVSync实例的指针。



### OH_NativeVSync_Destroy()


```
void OH_NativeVSync_Destroy (OH_NativeVSync * nativeVsync)
```

**描述:**

销毁OH_NativeVSync实例。

销毁后的OH_NativeVSync指针不能再继续使用，否则会有野指针问题，尤其需要注意多线程并发时对于OH_NativeVSync指针的管理。

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| nativeVsync | 一个指向OH_NativeVSync实例的指针。 |


### OH_NativeVSync_RequestFrame()


```
int OH_NativeVSync_RequestFrame (OH_NativeVSync * nativeVsync, OH_NativeVSync_FrameCallback callback, void * data )
```

**描述:**

请求下一次vsync信号，当信号到来时，调用回调函数callback。 如果在同一帧内中多次调用此接口，则只会触发最后一个回调。
如果此接口与[OH_NativeVSync_RequestFrameWithMultiCallback](#oh_nativevsync_requestframewithmulticallback)接口在同一帧内被调用，则此接口的功能不会生效。

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| nativeVsync | 一个指向OH_NativeVSync实例的指针。 |
| callback | 一个OH_NativeVSync_FrameCallback类型的函数指针，当下一次vsync信号到来时会被调用。 |
| data | 一个指向用户自定义数据结构的指针，类型是void\*。 |

**返回:**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeVSync_RequestFrameWithMultiCallback()

```
int OH_NativeVSync_RequestFrameWithMultiCallback (OH_NativeVSync* nativeVsync, OH_NativeVSync_FrameCallback callback, void* data )
```

**描述：**

请求下一次vsync信号，当信号到来时，调用回调函数callback。 如果在同一帧内中多次调用此接口，每一次传入的callback都会被执行。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeVsync

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nativeVsync | 一个指向OH_NativeVSync实例的指针。 | 
| callback | 一个OH_NativeVSync_FrameCallback类型的函数指针，当下一次vsync信号到来时会被调用。 | 
| data | 一个指向用户自定义数据结构的指针，类型是void\*。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。