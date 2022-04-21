# external_window.h


## **Overview**

**Related Modules:**

[NativeWindow](_native_window.md)

**Description:**

定义获取和使用NativeWindow的相关函数

**Since:**
8
**Version:**
1.0

## **Summary**


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindowFromSurface](_native_window.md#ga4225dd025093bc610670c2b517f186c2)&nbsp;(void&nbsp;\*pSurface) | struct&nbsp;NativeWindow&nbsp;\*<br/>创建NativeWindow实例，每次调用都会产生一个新的NativeWindow实例 | 
| [OH_NativeWindow_DestroyNativeWindow](_native_window.md#ga1ca5f2e39a03b6546352ac90be19238d)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window) | void<br/>将NativeWindow对象的引用计数减1，当引用计数为0的时候，该NativeWindow对象会被析构掉 | 
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](_native_window.md#gaec1b04ace16a364d79b7d54cf917e6f5)&nbsp;(void&nbsp;\*pSurfaceBuffer) | struct&nbsp;NativeWindowBuffer&nbsp;\*<br/>创建NativeWindowBuffer实例，每次调用都会产生一个新的NativeWindowBuffer实例 | 
| [OH_NativeWindow_DestroyNativeWindowBuffer](_native_window.md#gafa11a7f9a36b2e6962cc34790eb1e87e)&nbsp;(struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | void<br/>将NativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该NativeWindowBuffer对象会被析构掉 | 
| [OH_NativeWindow_NativeWindowRequestBuffer](_native_window.md#ga80cad8d3c2863294f828caa4d3422c2c)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*\*buffer,&nbsp;int&nbsp;\*fenceFd) | int32_t<br/>通过NativeWindow对象申请一块NativeWindowBuffer，用以内容生产 | 
| [OH_NativeWindow_NativeWindowFlushBuffer](_native_window.md#ga8489a6525b5c9f7a6b52aafba07fb777)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*buffer,&nbsp;int&nbsp;fenceFd,&nbsp;Region&nbsp;region) | int32_t<br/>通过NativeWindow将生产好内容的NativeWindowBuffer放回到Buffer队列中，用以内容消费 | 
| [OH_NativeWindow_NativeWindowCancelBuffer](_native_window.md#gad7b6ffa8b402f5be0bf6e742b18f03d0)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | int32_t<br/>通过NativeWindow将之前申请出来的NativeWindowBuffer返还到Buffer队列中，供下次再申请 | 
| [OH_NativeWindow_NativeWindowHandleOpt](_native_window.md#ga5620fba277d2f086da6c6d7434c09253)&nbsp;(struct&nbsp;NativeWindow&nbsp;\*window,&nbsp;int&nbsp;code,...) | int32_t<br/>设置/获取NativeWindow的属性，包括设置/获取宽高、内容格式等 | 
| [OH_NativeWindow_GetBufferHandleFromNative](_native_window.md#ga28c34ab9b0751010cb716ca9acd6dfef)&nbsp;(struct&nbsp;NativeWindowBuffer&nbsp;\*buffer) | BufferHandle&nbsp;\*<br/>通过NativeWindowBuffer获取该buffer的BufferHandle指针 | 
| [OH_NativeWindow_NativeObjectReference](_native_window.md#gafcbd7894c5cdae431e591028c5f7f709)&nbsp;(void&nbsp;\*obj) | int32_t<br/>增加一个NativeObject的引用计数 | 
| [OH_NativeWindow_NativeObjectUnreference](_native_window.md#ga24567fa7daee679bf927623adac93a9f)&nbsp;(void&nbsp;\*obj) | int32_t<br/>减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉 | 
| [OH_NativeWindow_GetNativeObjectMagic](_native_window.md#ga93828d364eebf3ec5c81d7897757f9f2)&nbsp;(void&nbsp;\*obj) | int32_t<br/>获取NativeObject的MagicId | 
