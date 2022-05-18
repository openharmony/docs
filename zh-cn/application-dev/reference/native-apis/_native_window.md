# NativeWindow


## **Overview**

**Description:**

提供NativeWindow功能，主要用来和egl对接

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Since:**

8

**Version:**

1.0


## **Summary**


### Files

  | File&nbsp;Name | Description | 
| -------- | -------- |
| [external_window.h](external__window_8h.md) | 定义获取和使用NativeWindow的相关函数 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| OH_NativeWindow_CreateNativeWindowFromSurface&nbsp;(void&nbsp;\*pSurface) | struct&nbsp;NativeWindow&nbsp;\*<br/>创建NativeWindow实例，每次调用都会产生一个新的NativeWindow实例 | 
| OH_NativeWindow_DestroyNativeWindow&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window) | void<br/>将NativeWindow对象的引用计数减1，当引用计数为0的时候，该NativeWindow对象会被析构掉 | 
| OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer&nbsp;(void&nbsp;\*pSurfaceBuffer) | struct&nbsp;NativeWindowBuffer&nbsp;\*<br/>创建NativeWindowBuffer实例，每次调用都会产生一个新的NativeWindowBuffer实例 | 
| OH_NativeWindow_DestroyNativeWindowBuffer&nbsp;(struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | void<br/>将NativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该NativeWindowBuffer对象会被析构掉 | 
| OH_NativeWindow_NativeWindowRequestBuffer&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*\*buffer,&nbsp;int&nbsp;\*fenceFd) | int32_t<br/>通过NativeWindow对象申请一块NativeWindowBuffer，用以内容生产 | 
| OH_NativeWindow_NativeWindowFlushBuffer&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*buffer,&nbsp;int&nbsp;fenceFd,&nbsp;Region&nbsp;region) | int32_t<br/>通过NativeWindow将生产好内容的NativeWindowBuffer放回到Buffer队列中，用以内容消费 | 
| OH_NativeWindow_NativeWindowCancelBuffer&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | int32_t<br/>通过NativeWindow将之前申请出来的NativeWindowBuffer返还到Buffer队列中，供下次再申请 | 
| OH_NativeWindow_NativeWindowHandleOpt&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;int&nbsp;code,...) | int32_t<br/>设置/获取NativeWindow的属性，包括设置/获取宽高、内容格式等 | 
| OH_NativeWindow_GetBufferHandleFromNative&nbsp;(struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | BufferHandle&nbsp;\*<br/>通过NativeWindowBuffer获取该buffer的BufferHandle指针 | 
| OH_NativeWindow_NativeObjectReference&nbsp;(void&nbsp;\*obj) | int32_t<br/>增加一个NativeObject的引用计数 | 
| OH_NativeWindow_NativeObjectUnreference&nbsp;(void&nbsp;\*obj) | int32_t<br/>减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉 | 
| OH_NativeWindow_GetNativeObjectMagic&nbsp;(void&nbsp;\*obj) | int32_t<br/>获取NativeObject的MagicId | 


## **Details**


## **Function**


### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()

  
```
struct NativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void * pSurfaceBuffer)
```

**Description:**

创建NativeWindowBuffer实例，每次调用都会产生一个新的NativeWindowBuffer实例

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| pSurfaceBuffer | 参数是一个指向生产者buffer的指针，类型为sptr&lt;OHOS::SurfaceBuffer&gt; | 

**Returns:**

返回一个指针，指向NativeWindowBuffer的结构体实例


### OH_NativeWindow_CreateNativeWindowFromSurface()

  
```
struct NativeWindow* OH_NativeWindow_CreateNativeWindowFromSurface (void * pSurface)
```

**Description:**

创建NativeWindow实例，每次调用都会产生一个新的NativeWindow实例

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| pSurface | 参数是一个指向生产者ProduceSurface的指针，类型为sptr&lt;OHOS::Surface&gt; | 

**Returns:**

返回一个指针，指向NativeWindow的结构体实例


### OH_NativeWindow_DestroyNativeWindow()

  
```
void OH_NativeWindow_DestroyNativeWindow (struct NativeWindow * window)
```

**Description:**

将NativeWindow对象的引用计数减1，当引用计数为0的时候，该NativeWindow对象会被析构掉

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 | 


### OH_NativeWindow_DestroyNativeWindowBuffer()

  
```
void OH_NativeWindow_DestroyNativeWindowBuffer (struct NativeWindowBuffer * buffer)
```

**Description:**

将NativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该NativeWindowBuffer对象会被析构掉

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| buffer | 参数是一个NativeWindowBuffer的结构体实例的指针 | 


### OH_NativeWindow_GetBufferHandleFromNative()

  
```
BufferHandle* OH_NativeWindow_GetBufferHandleFromNative (struct NativeWindowBuffer * buffer)
```

**Description:**

通过NativeWindowBuffer获取该buffer的BufferHandle指针

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| buffer | 参数是一个NativeWindowBuffer的结构体实例的指针 | 

**Returns:**

BufferHandle 返回一个指针，指向BufferHandle的结构体实例


### OH_NativeWindow_GetNativeObjectMagic()

  
```
int32_t OH_NativeWindow_GetNativeObjectMagic (void * obj)
```

**Description:**

获取NativeObject的MagicId

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| obj | 参数是一个NativeWindow&nbsp;or&nbsp;NativeWindowBuffer的结构体实例的指针 | 

**Returns:**

MagicId 返回值为魔鬼数字，每个NativeObject唯一


### OH_NativeWindow_NativeObjectReference()

  
```
int32_t OH_NativeWindow_NativeObjectReference (void * obj)
```

**Description:**

增加一个NativeObject的引用计数

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| obj | 参数是一个NativeWindow&nbsp;or&nbsp;NativeWindowBuffer的结构体实例的指针 | 

**Returns:**

GSError 返回值为错误码


### OH_NativeWindow_NativeObjectUnreference()

  
```
int32_t OH_NativeWindow_NativeObjectUnreference (void * obj)
```

**Description:**

减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| obj | 参数是一个NativeWindow&nbsp;or&nbsp;NativeWindowBuffer的结构体实例的指针 | 

**Returns:**

GSError


### OH_NativeWindow_NativeWindowCancelBuffer()

  
```
int32_t OH_NativeWindow_NativeWindowCancelBuffer (struct NativeWindow * window, struct NativeWindowBuffer * buffer )
```

**Description:**

通过NativeWindow将之前申请出来的NativeWindowBuffer返还到Buffer队列中，供下次再申请

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 | 
| buffer | 参数是一个NativeWindowBuffer的结构体实例的指针 | 

**Returns:**

GSError 返回值为错误码


### OH_NativeWindow_NativeWindowFlushBuffer()

  
```
int32_t OH_NativeWindow_NativeWindowFlushBuffer (struct NativeWindow * window, struct NativeWindowBuffer * buffer, int fenceFd, Region region )
```

**Description:**

通过NativeWindow将生产好内容的NativeWindowBuffer放回到Buffer队列中，用以内容消费

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 | 
| buffer | 参数是一个NativeWindowBuffer的结构体实例的指针 | 
| fenceFd | 参数是一个文件描述符句柄，用以同步时序 | 
| region | 参数表示一块脏区域，该区域有内容更新 | 

**Returns:**

GSError 返回值为错误码


### OH_NativeWindow_NativeWindowHandleOpt()

  
```
int32_t OH_NativeWindow_NativeWindowHandleOpt (struct NativeWindow * window, int code,  ... )
```

**Description:**

设置/获取NativeWindow的属性，包括设置/获取宽高、内容格式等

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 | 
| code | 操作码 | 

**Returns:**

GSError 返回值为错误码


### OH_NativeWindow_NativeWindowRequestBuffer()

  
```
int32_t OH_NativeWindow_NativeWindowRequestBuffer (struct NativeWindow * window, struct NativeWindowBuffer ** buffer, int * fenceFd )
```

**Description:**

通过NativeWindow对象申请一块NativeWindowBuffer，用以内容生产

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| window | 参数是一个NativeWindow的结构体实例的指针 | 
| buffer | 参数是一个NativeWindowBuffer的结构体实例的二级指针 | 
| fenceFd | 参数是一个文件描述符句柄 | 

**Returns:**

GSError 返回值为错误码
