# OH_NativeXComponent_Callback


## 概述

注册surface生命周期和触摸事件回调。

**起始版本：** 8

**相关模块：**[Native XComponent](_o_h___native_x_component.md)

**所在头文件：** [native_interface_xcomponent.h](native__interface__xcomponent_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| void(\* [OnSurfaceCreated](_o_h___native_x_component.md#onsurfacecreated) )([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window) |  创建surface时调用。| 
| void(\* [OnSurfaceChanged](_o_h___native_x_component.md#onsurfacechanged) )([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window) |  当surface改变时调用。| 
| void(\* [OnSurfaceDestroyed](_o_h___native_x_component.md#onsurfacedestroyed) )([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window) |  当surface被销毁时调用。| 
| void(\* [DispatchTouchEvent](_o_h___native_x_component.md#dispatchtouchevent) )([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window) |  当触摸事件被触发时调用。| 
