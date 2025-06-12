# WindowManager_WindowProperties

## Overview

The WindowManager_WindowProperties struct describes the window properties.

**Since**: 15

**Related module**: [WindowManager](capi-windowmanager.md)

**Header file**: [oh_window_comm.h](capi-oh-window-comm-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| WindowManager_Rect windowRect | Position and size of the window.|
| WindowManager_Rect drawableRect | Size of the drawable area within the window.|
| WindowManager_WindowType type | Window type.|
| bool isFullScreen | Whether the window is in full-screen mode. The default value is **false**. The value **true** means that the window is in full-screen mode, and **false** means the opposite.|
| bool isLayoutFullScreen | Whether the window layout is immersive. The default value is **false**. The value **true** means that the window layout is immersive, and **false** means the opposite.|
| bool focusable | Whether the window is focusable. The default value is true. The value **true** means that the window is focusable, and **false** means the opposite.|
| bool touchable | Whether the window is touchable. The default value is true. The value **true** means that the window is touchable, and **false** means the opposite.|
| float brightness | Screen brightness of the window. The value is a floating point number in the range [0.0, 1.0] or is set to **-1.0**, where **1.0** indicates the brightest, and **-1.0** is the default brightness.|
| bool isKeepScreenOn | Whether the screen is steady on. The default value is **false**. The value **true** means that the screen is steady on, and **false** means the opposite.|
| bool isPrivacyMode | Whether privacy mode is enabled for the window. The default value is **false**. The value **true** means that privacy mode is enabled, and **false** means the opposite.|
| bool isTransparent | Whether the window is transparent. The default value is **false**. The value **true** means that the window is transparent, and **false** means the opposite.|
| uint32_t id | Window ID. The default value is **0**, and the value is an integer.|
| uint32_t displayId | ID of the screen where the window is located. By default, the ID of the primary screen is returned. The value is an integer.|
