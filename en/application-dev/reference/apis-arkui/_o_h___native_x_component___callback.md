# OH_NativeXComponent_Callback


## Overview

Registers callbacks for the surface lifecycle and touch event.

**Since**: 8

**Related module**: [Native XComponent](_o_h___native_x_component.md)

**Header file**: [native_interface_xcomponent.h](native__interface__xcomponent_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| void(\* [OnSurfaceCreated](_o_h___native_x_component.md#onsurfacecreated) )([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window) |  Invoked when a surface is created.| 
| void(\* [OnSurfaceChanged](_o_h___native_x_component.md#onsurfacechanged) )([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window) |  Invoked when the surface changes.| 
| void(\* [OnSurfaceDestroyed](_o_h___native_x_component.md#onsurfacedestroyed) )([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window) |  Invoked when the surface is destroyed.| 
| void(\* [DispatchTouchEvent](_o_h___native_x_component.md#dispatchtouchevent) )([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window) |  Invoked when a touch event is triggered.| 
