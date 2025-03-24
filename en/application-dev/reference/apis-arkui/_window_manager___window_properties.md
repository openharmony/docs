# WindowManager_WindowProperties


## Overview

The WindowManager_WindowProperties struct describes the window properties.

**Since**: 15

**Related module**: [WindowManager_NativeModule](_window_manager___native_module.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [WindowManager_Rect](_window_manager___rect.md)  [windowRect](#windowrect) | Position and size of the window.|
| [WindowManager_Rect](_window_manager___rect.md)  [drawableRect](#drawablerect) | Size of the drawable area within the window.|
| [WindowManager_WindowType](_window_manager___native_module.md#windowmanager_windowtype)  [type](#type) | Window type.|
| bool [isFullScreen](#isfullscreen) | Whether the window is in full-screen mode. The default value is **false**. The value **true** means that the window is in full-screen mode, and **false** means the opposite.|
| bool [isLayoutFullScreen](#islayoutfullscreen) | Whether the window layout is immersive. The default value is **false**. The value **true** means that the window layout is immersive, and **false** means the opposite.|
| bool [focusable](#focusable) | Whether the window is focusable. The default value is **true**. The value **true** means that the window is focusable, and **false** means the opposite.|
| bool [touchable](#touchable) | Whether the window is touchable. The default value is **true**. The value **true** means that the window is touchable, and **false** means the opposite.|
| float [brightness](#brightness) | Screen brightness of the window. The value is a floating point number in the range [0.0, 1.0] or set to **-1.0**, where **1.0** indicates the brightest, and **-1.0** is the default brightness.|
| bool [isKeepScreenOn](#iskeepscreenon) | Whether the screen is steady on. The default value is **false**. The value **true** means that the screen is steady on, and **false** means the opposite.|
| bool [isPrivacyMode](#isprivacymode) | Whether privacy mode is enabled for the window. The default value is **false**. The value **true** means that privacy mode is enabled, and **false** means the opposite.|
| bool [isTransparent](#istransparent) | Whether the window is transparent. The default value is **false**. The value **true** means that the window is transparent, and **false** means the opposite.|
| uint32_t [id](#id) | Window ID. The default value is **0**, and the value is an integer.|
| uint32_t [displayId](#displayid) | ID of the screen where the window is located. By default, the ID of the primary screen is returned. The value is an integer.|


## Member Variable Description


### brightness

```
float WindowManager_WindowProperties::brightness
```

**Description**

Screen brightness of the window. The value is a floating point number in the range [0.0, 1.0] or set to **-1.0**, where **1.0** indicates the brightest, and **-1.0** is the default brightness.


### displayId

```
uint32_t WindowManager_WindowProperties::displayId
```

**Description**

ID of the screen where the window is located. By default, the ID of the primary screen is returned. The value is an integer.


### drawableRect

```
WindowManager_Rect WindowManager_WindowProperties::drawableRect
```

**Description**

Size of the drawable area within the window.


### focusable

```
bool WindowManager_WindowProperties::focusable
```

**Description**

Whether the window is focusable. The default value is **true**. The value **true** means that the window is focusable, and **false** means the opposite.


### id

```
uint32_t WindowManager_WindowProperties::id
```

**Description**

Window ID. The default value is **0**, and the value is an integer.


### isFullScreen

```
bool WindowManager_WindowProperties::isFullScreen
```

**Description**

Whether the window is in full-screen mode. The default value is **false**. The value **true** means that the window is in full-screen mode, and **false** means the opposite.


### isKeepScreenOn

```
bool WindowManager_WindowProperties::isKeepScreenOn
```

**Description**

Whether the screen is steady on. The default value is **false**. The value **true** means that the screen is steady on, and **false** means the opposite.


### isLayoutFullScreen

```
bool WindowManager_WindowProperties::isLayoutFullScreen
```

**Description**

Whether the window layout is immersive. The default value is **false**. The value **true** means that the window layout is immersive, and **false** means the opposite.


### isPrivacyMode

```
bool WindowManager_WindowProperties::isPrivacyMode
```

**Description**

Whether privacy mode is enabled for the window. The default value is **false**. The value **true** means that privacy mode is enabled, and **false** means the opposite.


### isTransparent

```
bool WindowManager_WindowProperties::isTransparent
```

**Description**

Whether the window is transparent. The default value is **false**. The value **true** means that the window is transparent, and **false** means the opposite.


### touchable

```
bool WindowManager_WindowProperties::touchable
```

**Description**

Whether the window is touchable. The default value is **true**. The value **true** means that the window is touchable, and **false** means the opposite.


### type

```
WindowManager_WindowType WindowManager_WindowProperties::type
```

**Description**

Window type.


### windowRect

```
WindowManager_Rect WindowManager_WindowProperties::windowRect
```

**Description**

Position and size of the window.
