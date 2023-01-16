# NativeVsync


提供NativeVsync功能。


@syscap SystemCapability.Graphic.Graphic2D.NativeVsync


**起始版本：**


8


## 汇总


### 文件

| 文件名称 | 描述 |
| -------- | -------- |
| [native_vsync.h](native__vsync_8h.md) | 定义获取和使用NativeVsync的相关函数 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeVSync_Create](#oh_nativevsync_create) (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例 |
| [OH_NativeVSync_Destroy](#oh_nativevsync_destroy) (OH_NativeVSync \*nativeVsync) | 销毁OH_NativeVSync实例 |
| [OH_NativeVSync_RequestFrame](#oh_nativevsync_requestframe) (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | 请求下一次vsync信号，当信号到来时，调用回调函数callback |


## 详细描述


## 函数说明


### OH_NativeVSync_Create()


```
OH_NativeVSync* OH_NativeVSync_Create (const char * name, unsigned int length )
```

**描述：**

创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例

@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数：**

| Name | 描述 |
| -------- | -------- |
| name | 参数表示一个vsync连接的名字 |
| length | 参数是name的长度 |

**返回：**

返回一个指向OH_NativeVSync实例的指针

**起始版本：**

8


### OH_NativeVSync_Destroy()


```
void OH_NativeVSync_Destroy (OH_NativeVSync * nativeVsync)
```

**描述：**

销毁OH_NativeVSync实例

@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数：**

| Name | 描述 |
| -------- | -------- |
| nativeVsync | 参数是一个指向OH_NativeVSync实例的指针 |

**起始版本：**

8


### OH_NativeVSync_RequestFrame()


```
int OH_NativeVSync_RequestFrame (OH_NativeVSync * nativeVsync, OH_NativeVSync_FrameCallback callback, void * data )
```

**描述：**

请求下一次vsync信号，当信号到来时，调用回调函数callback

@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**参数：**

| Name | 描述 |
| -------- | -------- |
| nativeVsync | 参数是一个指向OH_NativeVSync实例的指针 |
| callback | 参数是一个OH_NativeVSync_FrameCallback类型的函数指针，当下一次vsync信号到来时会被调用 |
| data | 参数是一个指向用户自定义数据结构的指针，类型是void\* |

**返回：**

返回一个由GSError定义的int32_t类型的错误码

**起始版本：**

8
