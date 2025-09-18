# native_display_soloist.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hudi33-->
<!--Designer: @hudi33-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->

## Overview

The **native_display_soloist.h** file declares the functions for obtaining and using native display soloist.

**File to import**: <native_display_soloist/native_display_soloist.h>

**Library**: libnative_display_soloist.so

**System capability**: SystemCapability.Graphic.Graphic2D.HyperGraphicManager

**Since**: 12

**Related module**: [NativeDisplaySoloist](capi-nativedisplaysoloist.md)

## Total

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [DisplaySoloist_ExpectedRateRange](capi-nativedisplaysoloist-displaysoloist-expectedraterange.md) | DisplaySoloist_ExpectedRateRange | Describes the expected frame rate range.|
| [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md) | OH_DisplaySoloist | Provides the declaration of an **OH_DisplaySoloist** struct.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_DisplaySoloist_FrameCallback)(long long timestamp, long long targetTimestamp, void* data)](#oh_displaysoloist_framecallback) | OH_DisplaySoloist_FrameCallback | Defines the pointer to an OH_DisplaySoloist callback function.|
| [OH_DisplaySoloist* OH_DisplaySoloist_Create(bool useExclusiveThread)](#oh_displaysoloist_create) | - | Creates an **OH_DisplaySoloist** instance. A new **OH_DisplaySoloist** instance is created each time this API is called.|
| [int32_t OH_DisplaySoloist_Destroy(OH_DisplaySoloist* displaySoloist)](#oh_displaysoloist_destroy) | - | Destroys an **OH_DisplaySoloist** object and reclaims the memory occupied.|
| [int32_t OH_DisplaySoloist_Start(OH_DisplaySoloist* displaySoloist, OH_DisplaySoloist_FrameCallback callback, void* data)](#oh_displaysoloist_start) | - | Sets a callback function for each frame. The callback function is triggered each time a VSync signal arrives.|
| [int32_t OH_DisplaySoloist_Stop(OH_DisplaySoloist* displaySoloist)](#oh_displaysoloist_stop) | - | Stops requesting the next VSync signal and triggering the callback function.|
| [int32_t OH_DisplaySoloist_SetExpectedFrameRateRange(OH_DisplaySoloist* displaySoloist, DisplaySoloist_ExpectedRateRange* range)](#oh_displaysoloist_setexpectedframeraterange) | - | Sets the expected frame rate range.|

## Function Description

### OH_DisplaySoloist_FrameCallback()

```
typedef void (*OH_DisplaySoloist_FrameCallback)(long long timestamp, long long targetTimestamp, void* data)
```

**Description**

Defines the pointer to an OH_DisplaySoloist callback function.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| long long timestamp | Current frame VSync timestamp.|
|  long long targetTimestamp | Expected VSync timestamp of the next frame.|
|  void* data | Pointer to user-defined data.|

### OH_DisplaySoloist_Create()

```
OH_DisplaySoloist* OH_DisplaySoloist_Create(bool useExclusiveThread)
```

**Description**

Creates an **OH_DisplaySoloist** instance. A new **OH_DisplaySoloist** instance is created each time this API is called.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| bool useExclusiveThread | Indicates whether the OH_DisplaySoloist instance exclusively occupies a thread. true: exclusively occupies a thread; false: shares a thread.|

**Return value**

| Type| Description|
| -- | -- |
| OH_DisplaySoloist* | Pointer to the [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md) instance. If the return value is empty, the execution fails, possibly because the memory is insufficient.|

### OH_DisplaySoloist_Destroy()

```
int32_t OH_DisplaySoloist_Destroy(OH_DisplaySoloist* displaySoloist)
```

**Description**

Destroys an **OH_DisplaySoloist** object and reclaims the memory occupied.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md)* displaySoloist | Pointer to the [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | 0: execution success; –1: execution failure|

### OH_DisplaySoloist_Start()

```
int32_t OH_DisplaySoloist_Start(OH_DisplaySoloist* displaySoloist, OH_DisplaySoloist_FrameCallback callback, void* data)
```

**Description**

Sets a callback function for each frame. The callback function is triggered each time a VSync signal arrives.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md)* displaySoloist | Pointer to a [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md) instance.|
| [OH_DisplaySoloist_FrameCallback](#oh_displaysoloist_framecallback) callback | Callback function to be triggered when the next VSync signal arrives.|
| void* data | Pointer to the user-defined data struct. The type is void.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | 0 on success; –1 on failure.|

### OH_DisplaySoloist_Stop()

```
int32_t OH_DisplaySoloist_Stop(OH_DisplaySoloist* displaySoloist)
```

**Description**

Stops requesting the next VSync signal and triggering the callback function.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md)* displaySoloist | Pointer to a [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | 0 on success; –1 on failure.|

### OH_DisplaySoloist_SetExpectedFrameRateRange()

```
int32_t OH_DisplaySoloist_SetExpectedFrameRateRange(OH_DisplaySoloist* displaySoloist, DisplaySoloist_ExpectedRateRange* range)
```

**Description**

Sets the expected frame rate range.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md)* displaySoloist | Pointer to an [OH_DisplaySoloist](capi-nativedisplaysoloist-oh-displaysoloist.md) instance.|
| [DisplaySoloist_ExpectedRateRange](capi-nativedisplaysoloist-displaysoloist-expectedraterange.md)* range | Pointer to the expected frame rate range [DisplaySoloist_ExpectedRateRange](capi-nativedisplaysoloist-displaysoloist-expectedraterange.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | 0 on success; –1 on failure.|
