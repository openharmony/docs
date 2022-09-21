# external_window.h


## 概述

定义获取和使用NativeWindow的相关函数。

**自从：**

8

**相关模块：**

[NativeWindow](_native_window.md)


## 汇总


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindowFromSurface](_native_window.md#ohnativewindowcreatenativewindowfromsurface) (void \*pSurface) | 创建NativeWindow实例，每次调用都会产生一个新的NativeWindow实例 |
| [OH_NativeWindow_DestroyNativeWindow](_native_window.md#ohnativewindowdestroynativewindow) (struct NativeWindow \*window) | 将NativeWindow对象的引用计数减1，当引用计数为0的时候，该NativeWindow对象会被析构掉 |
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](_native_window.md#ohnativewindowcreatenativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | 创建NativeWindowBuffer实例，每次调用都会产生一个新的NativeWindowBuffer实例 |
| [OH_NativeWindow_DestroyNativeWindowBuffer](_native_window.md#ohnativewindowdestroynativewindowbuffer) (struct NativeWindowBuffer \*buffer) | 将NativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该NativeWindowBuffer对象会被析构掉 |
| [OH_NativeWindow_NativeWindowRequestBuffer](_native_window.md#ohnativewindownativewindowrequestbuffer) (struct NativeWindow \*window, struct NativeWindowBuffer \*\*buffer, int \*fenceFd) | 通过NativeWindow对象申请一块NativeWindowBuffer，用以内容生产 |
| [OH_NativeWindow_NativeWindowFlushBuffer](_native_window.md#ohnativewindownativewindowflushbuffer) (struct NativeWindow \*window, struct NativeWindowBuffer \*buffer, int fenceFd, Region region) | 通过NativeWindow将生产好内容的NativeWindowBuffer放回到Buffer队列中，用以内容消费 |
| [OH_NativeWindow_NativeWindowCancelBuffer](_native_window.md#ohnativewindownativewindowcancelbuffer) (struct NativeWindow \*window, struct NativeWindowBuffer \*buffer) | 通过NativeWindow将之前申请出来的NativeWindowBuffer返还到Buffer队列中，供下次再申请 |
| [OH_NativeWindow_NativeWindowHandleOpt](_native_window.md#ohnativewindownativewindowhandleopt) (struct NativeWindow \*window, int code,...) | 设置/获取NativeWindow的属性，包括设置/获取宽高、内容格式等 |
| [OH_NativeWindow_GetBufferHandleFromNative](_native_window.md#ohnativewindowgetbufferhandlefromnative) (struct NativeWindowBuffer \*buffer) | 通过NativeWindowBuffer获取该buffer的BufferHandle指针 |
| [OH_NativeWindow_NativeObjectReference](_native_window.md#ohnativewindownativeobjectreference) (void \*obj) | 增加一个NativeObject的引用计数 |
| [OH_NativeWindow_NativeObjectUnreference](_native_window.md#ohnativewindownativeobjectunreference) (void \*obj) | 减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉 |
| [OH_NativeWindow_GetNativeObjectMagic](_native_window.md#ohnativewindowgetnativeobjectmagic) (void \*obj) | 获取NativeObject的MagicId |
