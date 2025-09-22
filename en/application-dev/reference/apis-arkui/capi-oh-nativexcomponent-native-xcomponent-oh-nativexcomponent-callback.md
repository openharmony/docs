# OH_NativeXComponent_Callback

## Overview

Registers callbacks for the surface lifecycle and touch event.

**Since**: 8

**Related module**: [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**Header file**: [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## Summary

### Member Functions

| Name| Description|
| -- | -- |
| [void (\*OnSurfaceCreated)(OH_NativeXComponent* component, void* window)](#onsurfacecreated) | Invoked when a surface is created.|
| [void (\*OnSurfaceChanged)(OH_NativeXComponent* component, void* window)](#onsurfacechanged) | Invoked when the surface changes.|
| [void (\*OnSurfaceDestroyed)(OH_NativeXComponent* component, void* window)](#onsurfacedestroyed) | Invoked when the surface is destroyed.|
| [void (\*DispatchTouchEvent)(OH_NativeXComponent* component, void* window)](#dispatchtouchevent) | Invoked when a touch event is triggered.|

## Member Function Description

### OnSurfaceCreated()

```
void (*OnSurfaceCreated)(OH_NativeXComponent* component, void* window)
```

**Description**


Invoked when a surface is created.

**Since**: 8

**Parameters**

| Name                               | Description|
|------------------------------------| -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void* window                       | Handle to the **NativeWindow** instance.|

### OnSurfaceChanged()

```
void (*OnSurfaceChanged)(OH_NativeXComponent* component, void* window)
```

**Description**


Invoked when the surface changes.

**Since**: 8

**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
|  void* window | Handle to the **NativeWindow** instance.|

### OnSurfaceDestroyed()

```
void (*OnSurfaceDestroyed)(OH_NativeXComponent* component, void* window)
```

**Description**


Invoked when the surface is destroyed.

**Since**: 8

**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
|  void* window | Handle to the **NativeWindow** instance.|

### DispatchTouchEvent()

```
void (*DispatchTouchEvent)(OH_NativeXComponent* component, void* window)
```

**Description**


Invoked when a touch event is triggered.

**Since**: 8

**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
|  void* window | Handle to the **NativeWindow** instance.|
