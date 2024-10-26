# native_display_soloist.h


## Overview

The **native_display_soloist.h** file declares the functions for obtaining and using native display soloist.

**File to include**: &lt;native_display_soloist/native_display_soloist.h&gt;

**System capability**: SystemCapability.Graphic.Graphic2D.HyperGraphicManager

**Library**: libnative_display_soloist.so

**Since**: 12

**Related module**: [NativeDisplaySoloist](_native_display_soloist.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) | Describes the expected frame rate range.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist)  [OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) | Provides the declaration of an **OH_DisplaySoloist** struct.| 
| typedef void(\* [OH_DisplaySoloist_FrameCallback](_native_display_soloist.md#oh_displaysoloist_framecallback)) (long long timestamp, long long targetTimestamp, void \*data) | Defines the pointer to an OH_DisplaySoloist callback function.| 
| typedef struct [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md)  [DisplaySoloist_ExpectedRateRange](_native_display_soloist.md#displaysoloist_expectedraterange) | Defines a struct for the expected frame rate range.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \* [OH_DisplaySoloist_Create](_native_display_soloist.md#oh_displaysoloist_create) (bool useExclusiveThread) | Creates an **OH_DisplaySoloist** instance. A new **OH_DisplaySoloist** instance is created each time this API is called.| 
| int32_t [OH_DisplaySoloist_Destroy](_native_display_soloist.md#oh_displaysoloist_destroy) ([OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \*displaySoloist) | Destroys an **OH_DisplaySoloist** object and reclaims the memory occupied.| 
| int32_t [OH_DisplaySoloist_Start](_native_display_soloist.md#oh_displaysoloist_start) ([OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \*displaySoloist, [OH_DisplaySoloist_FrameCallback](_native_display_soloist.md#oh_displaysoloist_framecallback) callback, void \*data) | Sets a callback function for each frame. The callback function is triggered each time a VSync signal arrives.| 
| int32_t [OH_DisplaySoloist_Stop](_native_display_soloist.md#oh_displaysoloist_stop) ([OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \*displaySoloist) | Stops requesting the next VSync signal and triggering the callback function.| 
| int32_t [OH_DisplaySoloist_SetExpectedFrameRateRange](_native_display_soloist.md#oh_displaysoloist_setexpectedframeraterange) ([OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \*displaySoloist, [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) \*range) | Sets the expected frame rate range.| 
