# OH_OnFrameAvailableListener


## 概述

一个OH_NativeImage的监听者，通过OH_NativeImage_SetOnFrameAvailableListener接口注册，该监听结构体当有帧可用时，将触发回调。

**起始版本：** 11

**相关模块：**[OH_NativeImage](_o_h___native_image.md)

**所在头文件：**[native_image.h](native__image_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [context](#context) | 用户自定义的上下文信息，会在回调触发时返回给用户。 |
| [onFrameAvailable](#onframeavailable) | 有buffer可获取时触发的回调函数。 |


## 结构体成员变量说明


### context

```
void* OH_OnFrameAvailableListener::context
```

**描述：**

用户自定义的上下文信息，会在回调触发时返回给用户。


### onFrameAvailable

```
OH_OnFrameAvailable OH_OnFrameAvailableListener::onFrameAvailable
```

**描述：**

有buffer可获取时触发的回调函数。
