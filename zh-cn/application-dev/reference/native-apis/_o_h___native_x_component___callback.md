# OH_NativeXComponent_Callback


## 概述

注册surface生命周期和触摸事件回调。

**自从：**

8

**相关模块：**

[Native XComponent](_o_h___native_x_component.md)


## 汇总


### 成员变量

  | 成员变量名称 | 描述 | 
| -------- | -------- |
| [OnSurfaceCreated](_o_h___native_x_component.md#onsurfacecreated)&nbsp;)([OH_NativeXComponent](_o_h___native_x_component.md#ohnativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window) | 创建surface时调用。 | 
| [OnSurfaceChanged](_o_h___native_x_component.md#onsurfacechanged)&nbsp;)([OH_NativeXComponent](_o_h___native_x_component.md#ohnativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window) | 当surface改变时调用。 | 
| [OnSurfaceDestroyed](_o_h___native_x_component.md#onsurfacedestroyed)&nbsp;)([OH_NativeXComponent](_o_h___native_x_component.md#ohnativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window) | 当surface被破坏时调用。 | 
| [DispatchTouchEvent](_o_h___native_x_component.md#dispatchtouchevent)&nbsp;)([OH_NativeXComponent](_o_h___native_x_component.md#ohnativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window) | 当触摸事件被触发时调用。 | 
