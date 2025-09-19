# OH_NativeXComponent_MouseEvent_Callback

## Overview

Registers callbacks for the mouse event.

**Since**: 9

**Related module**: [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**Header file**: [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## Summary

### Member Functions

| Name| Description|
| -- | -- |
| [void (\*DispatchMouseEvent)(OH_NativeXComponent* component, void* window)](#dispatchmouseevent) | Invoked when a mouse event is triggered.|
| [void (\*DispatchHoverEvent)(OH_NativeXComponent* component, bool isHover)](#dispatchhoverevent) | Invoked when a hover event is triggered.|

## Member Function Description

### DispatchMouseEvent()

```
void (*DispatchMouseEvent)(OH_NativeXComponent* component, void* window)
```

**Description**


Invoked when a mouse event is triggered.

**Since**: 8

**Parameters**

| Name                               | Description|
|------------------------------------| -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void* window                       | Handle to the **NativeWindow** instance.|

### DispatchHoverEvent()

```
void (*DispatchHoverEvent)(OH_NativeXComponent* component, bool isHover)
```

**Description**


Invoked when a hover event is triggered.

**Since**: 8

**Parameters**

| Name                               | Description|
|------------------------------------| -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| bool isHover                       | Whether the mouse pointer or stylus is hovering over the component. **true**: The mouse pointer or stylus has entered the component. **false**: The mouse pointer or stylus has left the component.|
