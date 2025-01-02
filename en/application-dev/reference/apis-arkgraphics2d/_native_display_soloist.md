# NativeDisplaySoloist


## Overview

The NativeDisplaySoloist module provides the native service that control the frame rate in threads other than the UI thread.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_display_soloist.h](native__display__soloist_8h.md) | Declares the functions for obtaining and using native display soloist.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) | Describes the expected frame rate range.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_DisplaySoloist](#oh_displaysoloist)  [OH_DisplaySoloist](#oh_displaysoloist) | Provides the declaration of an **OH_DisplaySoloist** struct.| 
| typedef void(\* [OH_DisplaySoloist_FrameCallback](#oh_displaysoloist_framecallback)) (long long timestamp, long long targetTimestamp, void \*data) | Defines the pointer to an OH_DisplaySoloist callback function.| 
| typedef struct [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md)  [DisplaySoloist_ExpectedRateRange](#displaysoloist_expectedraterange) | Defines a struct for the expected frame rate range.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_DisplaySoloist](#oh_displaysoloist) \* [OH_DisplaySoloist_Create](#oh_displaysoloist_create) (bool useExclusiveThread) | Creates an **OH_DisplaySoloist** instance. A new **OH_DisplaySoloist** instance is created each time this API is called.| 
| int32_t [OH_DisplaySoloist_Destroy](#oh_displaysoloist_destroy) ([OH_DisplaySoloist](#oh_displaysoloist) \*displaySoloist) | Destroys an **OH_DisplaySoloist** object and reclaims the memory occupied.| 
| int32_t [OH_DisplaySoloist_Start](#oh_displaysoloist_start) ([OH_DisplaySoloist](#oh_displaysoloist) \*displaySoloist, [OH_DisplaySoloist_FrameCallback](#oh_displaysoloist_framecallback) callback, void \*data) | Sets a callback function for each frame. The callback function is triggered each time a VSync signal arrives.| 
| int32_t [OH_DisplaySoloist_Stop](#oh_displaysoloist_stop) ([OH_DisplaySoloist](#oh_displaysoloist) \*displaySoloist) | Stops requesting the next VSync signal and triggering the callback function.| 
| int32_t [OH_DisplaySoloist_SetExpectedFrameRateRange](#oh_displaysoloist_setexpectedframeraterange) ([OH_DisplaySoloist](#oh_displaysoloist) \*displaySoloist, [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) \*range) | Sets the expected frame rate range.| 


## Type Description


### DisplaySoloist_ExpectedRateRange

```
typedef struct DisplaySoloist_ExpectedRateRange DisplaySoloist_ExpectedRateRange
```

**Description**

Defines a struct for the expected frame rate range.

**Since**: 12


### OH_DisplaySoloist

```
typedef struct OH_DisplaySoloist OH_DisplaySoloist
```

**Description**

Provides the declaration of an **OH_DisplaySoloist** struct.

**Since**: 12


### OH_DisplaySoloist_FrameCallback

```
typedef void(* OH_DisplaySoloist_FrameCallback) (long long timestamp, long long targetTimestamp, void *data)
```

**Description**

Defines the pointer to an OH_DisplaySoloist callback function.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| timestamp | VSync timestamp.| 
| targetTimestamp | Expected VSync timestamp of the next frame.| 
| data | User-defined data.| 


## Function Description


### OH_DisplaySoloist_Create()

```
OH_DisplaySoloist* OH_DisplaySoloist_Create (bool useExclusiveThread)
```

**Description**

Creates an **OH_DisplaySoloist** instance. A new **OH_DisplaySoloist** instance is created each time this API is called.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| useExclusiveThread | Whether the **OH_DisplaySoloist** instance exclusively occupies a thread. The value **true** means that the instance exclusively occupies a thread, and **false** means that the instance shares a thread with others.| 

**Returns**

Returns the pointer to the [OH_DisplaySoloist](#oh_displaysoloist) instance created if the operation is successful; returns a null pointer otherwise. The failure cause may be out of memory.


### OH_DisplaySoloist_Destroy()

```
int32_t OH_DisplaySoloist_Destroy (OH_DisplaySoloist* displaySoloist)
```

**Description**

Destroys an **OH_DisplaySoloist** object and reclaims the memory occupied.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displaySoloist | Pointer to an [OH_DisplaySoloist](#oh_displaysoloist) instance.| 

**Returns**

Returns **0** if the operation is successful; returns **-1** otherwise.


### OH_DisplaySoloist_SetExpectedFrameRateRange()

```
int32_t OH_DisplaySoloist_SetExpectedFrameRateRange (OH_DisplaySoloist* displaySoloist, DisplaySoloist_ExpectedRateRange* range )
```

**Description**

Sets the expected frame rate range.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displaySoloist | Pointer to an [OH_DisplaySoloist](#oh_displaysoloist) instance.| 
| range | Pointer to the expected frame rate range, which is a [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) instance.| 

**Returns**

Returns **0** if the operation is successful; returns **-1** otherwise.


### OH_DisplaySoloist_Start()

```
int32_t OH_DisplaySoloist_Start (OH_DisplaySoloist* displaySoloist, OH_DisplaySoloist_FrameCallback callback, void* data )
```

**Description**

Sets a callback function for each frame. The callback function is triggered each time a VSync signal arrives.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displaySoloist | Pointer to an [OH_DisplaySoloist](#oh_displaysoloist) instance.| 
| callback | Callback function to be triggered when the next VSync signal arrives.| 
| data | Pointer to the user-defined data struct. The type is void\*.| 

**Returns**

Returns **0** if the operation is successful; returns **-1** otherwise.


### OH_DisplaySoloist_Stop()

```
int32_t OH_DisplaySoloist_Stop (OH_DisplaySoloist* displaySoloist)
```

**Description**

Stops requesting the next VSync signal and triggering the callback function.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displaySoloist | Pointer to an [OH_DisplaySoloist](#oh_displaysoloist) instance.| 

**Returns**

Returns **0** if the operation is successful; returns **-1** otherwise.
