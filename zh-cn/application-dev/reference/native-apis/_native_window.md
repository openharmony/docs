# NativeWindow


提供NativeWindow功能，主要用来和egl对接


@syscap SystemCapability.Graphic.Graphic2D.NativeWindow


**自从：**


8


## 汇总


### 文件

| 文件名称 | 描述 |
| -------- | -------- |
| [external_window.h](external__window_8h.md) | 定义获取和使用NativeWindow的相关函数 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindowFromSurface](#ohnativewindowcreatenativewindowfromsurface)&nbsp;(void&nbsp;\*pSurface) | 创建NativeWindow实例，每次调用都会产生一个新的NativeWindow实例 |
| [OH_NativeWindow_DestroyNativeWindow](#ohnativewindowdestroynativewindow)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window) | 将NativeWindow对象的引用计数减1，当引用计数为0的时候，该NativeWindow对象会被析构掉 |
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](#ohnativewindowcreatenativewindowbufferfromsurfacebuffer)&nbsp;(void&nbsp;\*pSurfaceBuffer) | 创建NativeWindowBuffer实例，每次调用都会产生一个新的NativeWindowBuffer实例 |
| [OH_NativeWindow_DestroyNativeWindowBuffer](#ohnativewindowdestroynativewindowbuffer)&nbsp;(struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | 将NativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该NativeWindowBuffer对象会被析构掉 |
| [OH_NativeWindow_NativeWindowRequestBuffer](#ohnativewindownativewindowrequestbuffer)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*\*buffer,&nbsp;int&nbsp;\*fenceFd) | 通过NativeWindow对象申请一块NativeWindowBuffer，用以内容生产 |
| [OH_NativeWindow_NativeWindowFlushBuffer](#ohnativewindownativewindowflushbuffer)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*buffer,&nbsp;int&nbsp;fenceFd,&nbsp;Region&nbsp;region) | 通过NativeWindow将生产好内容的NativeWindowBuffer放回到Buffer队列中，用以内容消费 |
| [OH_NativeWindow_NativeWindowCancelBuffer](#ohnativewindownativewindowcancelbuffer)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | 通过NativeWindow将之前申请出来的NativeWindowBuffer返还到Buffer队列中，供下次再申请 |
| [OH_NativeWindow_NativeWindowHandleOpt](#ohnativewindownativewindowhandleopt)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;int&nbsp;code,...) | 设置/获取NativeWindow的属性，包括设置/获取宽高、内容格式等 |
| [OH_NativeWindow_GetBufferHandleFromNative](#ohnativewindowgetbufferhandlefromnative)&nbsp;(struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | 通过NativeWindowBuffer获取该buffer的BufferHandle指针 |
| [OH_NativeWindow_NativeObjectReference](#ohnativewindownativeobjectreference)&nbsp;(void&nbsp;\*obj) | 增加一个NativeObject的引用计数 |
| [OH_NativeWindow_NativeObjectUnreference](#ohnativewindownativeobjectunreference)&nbsp;(void&nbsp;\*obj) | 减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉 |
| [OH_NativeWindow_GetNativeObjectMagic](#ohnativewindowgetnativeobjectmagic)&nbsp;(void&nbsp;\*obj) | 获取NativeObject的MagicId |


## 详细描述


## 函数说明


### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()


```
struct NativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void * pSurfaceBuffer)
```

**描述：**

创建NativeWindowBuffer实例，每次调用都会产生一个新的NativeWindowBuffer实例

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| pSurfaceBuffer | 参数是一个指向生产者buffer的指针，类型为sptr&lt;OHOS::SurfaceBuffer&gt; |

**返回：**

返回一个指针，指向NativeWindowBuffer的结构体实例

**自从：**

8


### OH_NativeWindow_CreateNativeWindowFromSurface()


```
struct NativeWindow* OH_NativeWindow_CreateNativeWindowFromSurface (void * pSurface)
```

**描述：**

创建NativeWindow实例，每次调用都会产生一个新的NativeWindow实例

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| pSurface | 参数是一个指向生产者ProduceSurface的指针，类型为sptr&lt;OHOS::Surface&gt; |

**返回：**

返回一个指针，指向NativeWindow的结构体实例

**自从：**

8


### OH_NativeWindow_DestroyNativeWindow()


```
void OH_NativeWindow_DestroyNativeWindow (struct NativeWindow * window)
```

**描述：**

将NativeWindow对象的引用计数减1，当引用计数为0的时候，该NativeWindow对象会被析构掉

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 |

**自从：**

8


### OH_NativeWindow_DestroyNativeWindowBuffer()


```
void OH_NativeWindow_DestroyNativeWindowBuffer (struct NativeWindowBuffer * buffer)
```

**描述：**

将NativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该NativeWindowBuffer对象会被析构掉

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| buffer | 参数是一个NativeWindowBuffer的结构体实例的指针 |

**自从：**

8


### OH_NativeWindow_GetBufferHandleFromNative()


```
BufferHandle* OH_NativeWindow_GetBufferHandleFromNative (struct NativeWindowBuffer * buffer)
```

**描述：**

通过NativeWindowBuffer获取该buffer的BufferHandle指针

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| buffer | 参数是一个NativeWindowBuffer的结构体实例的指针 |

**返回：**

BufferHandle 返回一个指针，指向BufferHandle的结构体实例

**自从：**

8


### OH_NativeWindow_GetNativeObjectMagic()


```
int32_t OH_NativeWindow_GetNativeObjectMagic (void * obj)
```

**描述：**

获取NativeObject的MagicId

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| obj | 参数是一个NativeWindow&nbsp;or&nbsp;NativeWindowBuffer的结构体实例的指针 |

**返回：**

MagicId 返回值为魔鬼数字，每个NativeObject唯一

**自从：**

8


### OH_NativeWindow_NativeObjectReference()


```
int32_t OH_NativeWindow_NativeObjectReference (void * obj)
```

**描述：**

增加一个NativeObject的引用计数

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| obj | 参数是一个NativeWindow&nbsp;or&nbsp;NativeWindowBuffer的结构体实例的指针 |

**返回：**

GSError 返回值为错误码

**自从：**

8


### OH_NativeWindow_NativeObjectUnreference()


```
int32_t OH_NativeWindow_NativeObjectUnreference (void * obj)
```

**描述：**

减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| obj | 参数是一个NativeWindow&nbsp;or&nbsp;NativeWindowBuffer的结构体实例的指针 |

**返回：**

GSError

**自从：**

8


### OH_NativeWindow_NativeWindowCancelBuffer()


```
int32_t OH_NativeWindow_NativeWindowCancelBuffer (struct NativeWindow * window, struct NativeWindowBuffer * buffer )
```

**描述：**

通过NativeWindow将之前申请出来的NativeWindowBuffer返还到Buffer队列中，供下次再申请

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 |
| buffer | 参数是一个NativeWindowBuffer的结构体实例的指针 |

**返回：**

GSError 返回值为错误码

**自从：**

8


### OH_NativeWindow_NativeWindowFlushBuffer()


```
int32_t OH_NativeWindow_NativeWindowFlushBuffer (struct NativeWindow * window, struct NativeWindowBuffer * buffer, int fenceFd, Region region )
```

**描述：**

通过NativeWindow将生产好内容的NativeWindowBuffer放回到Buffer队列中，用以内容消费

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 |
| buffer | 参数是一个NativeWindowBuffer的结构体实例的指针 |
| fenceFd | 参数是一个文件描述符句柄，用以同步时序 |
| region | 参数表示一块脏区域，该区域有内容更新 |

**返回：**

GSError 返回值为错误码

**自从：**

8


### OH_NativeWindow_NativeWindowHandleOpt()


```
int32_t OH_NativeWindow_NativeWindowHandleOpt (struct NativeWindow * window, int code,  ... )
```

**描述：**

设置/获取NativeWindow的属性，包括设置/获取宽高、内容格式等

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 |
| code | 操作码 |

**返回：**

GSError 返回值为错误码

**自从：**

8


### OH_NativeWindow_NativeWindowRequestBuffer()


```
int32_t OH_NativeWindow_NativeWindowRequestBuffer (struct NativeWindow * window, struct NativeWindowBuffer ** buffer, int * fenceFd )
```

**描述：**

通过NativeWindow对象申请一块NativeWindowBuffer，用以内容生产

@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数：**

| Name | 描述 |
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 |
| buffer | 参数是一个NativeWindowBuffer的结构体实例的二级指针 |
| fenceFd | 参数是一个文件描述符句柄 |

**返回：**

GSError 返回值为错误码

**自从：**

8
