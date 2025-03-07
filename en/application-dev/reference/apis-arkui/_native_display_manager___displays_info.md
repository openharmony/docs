# NativeDisplayManager_DisplaysInfo


## Overview

The NativeDisplayManager_DisplaysInfo struct encapsulates the information about displays of a device with multiple screens.

**Since**: 14

**Related module**: [OH_DisplayManager](_o_h___display_manager.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [displaysLength](#displayslength) | Number of displays of a device with multiple screens.| 
| [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) \* [displaysInfo](#displaysinfo) | An array of NativeDisplayManager_DisplayInfo structs, each containing information about a display.| 


## Member Variable Description


### displaysInfo

```
NativeDisplayManager_DisplayInfo* NativeDisplayManager_DisplaysInfo::displaysInfo
```

**Description**

An array of NativeDisplayManager_DisplayInfo structs, each containing information about a display.


### displaysLength

```
uint32_t NativeDisplayManager_DisplaysInfo::displaysLength
```

**Description**

Number of displays of a device with multiple screens.
