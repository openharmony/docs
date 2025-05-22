# WindowManager_WindowProperties


## 概述

窗口属性。

**起始版本：** 15

**相关模块：**[WindowManager](_window_manager___native_module.md)

**所在头文件：** [oh_window_comm.h](oh__window__comm_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [WindowManager_Rect](_window_manager___rect.md)  [windowRect](#windowrect) | 窗口的位置和尺寸。 |
| [WindowManager_Rect](_window_manager___rect.md)  [drawableRect](#drawablerect) | 窗口内可绘制区域的尺寸。 |
| [WindowManager_WindowType](_window_manager___native_module.md#windowmanager_windowtype)  [type](#type) | 窗口类型。 |
| bool [isFullScreen](#isfullscreen) | 窗口是否全屏模式。默认值为false。true表示窗口是全屏模式，false表示窗口是非全屏模式。 |
| bool [isLayoutFullScreen](#islayoutfullscreen) | 窗口布局是否沉浸式。默认值为false。true表示窗口布局是沉浸式，false表示窗口布局是非沉浸式。 |
| bool [focusable](#focusable) | 窗口是否能获取焦点。默认值为true。true表示窗口能获取焦点，false表示窗口不能获取焦点。 |
| bool [touchable](#touchable) | 窗口是否可触。默认值为true。true表示窗口可触，false表示窗口不可触。 |
| float [brightness](#brightness) | 窗口亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。 |
| bool [isKeepScreenOn](#iskeepscreenon) | 是否打开屏幕常亮。默认值为false。true表示屏幕常亮，false表示屏幕不常亮。 |
| bool [isPrivacyMode](#isprivacymode) | 窗口是否打开隐私模式。默认值为false。true表示窗口打开隐私模式，false表示窗口关闭隐私模式。 |
| bool [isTransparent](#istransparent) | 窗口是否透明。默认值为false。true表示窗口透明，false表示窗口非透明。 |
| uint32_t [id](#id) | 窗口id。默认值为0，该参数为整数。 |
| uint32_t [displayId](#displayid) | 窗口所在屏幕的id，默认返回主屏幕id，该参数为整数 |


## 结构体成员变量说明


### brightness

```
float WindowManager_WindowProperties::brightness
```

**描述**

窗口亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。


### displayId

```
uint32_t WindowManager_WindowProperties::displayId
```

**描述**

窗口所在屏幕的id，默认返回主屏幕id，该参数为整数。


### drawableRect

```
WindowManager_Rect WindowManager_WindowProperties::drawableRect
```

**描述**

窗口内可绘制区域的尺寸。


### focusable

```
bool WindowManager_WindowProperties::focusable
```

**描述**

窗口是否能获取焦点。默认值为true。true表示窗口能获取焦点，false表示窗口不能获取焦点。


### id

```
uint32_t WindowManager_WindowProperties::id
```

**描述**

窗口id。默认值为0，该参数为整数。


### isFullScreen

```
bool WindowManager_WindowProperties::isFullScreen
```

**描述**

窗口是否全屏模式。默认值为false。true表示窗口是全屏模式，false表示窗口是非全屏模式。


### isKeepScreenOn

```
bool WindowManager_WindowProperties::isKeepScreenOn
```

**描述**

是否打开屏幕常亮。默认值为false。true表示屏幕常亮，false表示屏幕不常亮。


### isLayoutFullScreen

```
bool WindowManager_WindowProperties::isLayoutFullScreen
```

**描述**

窗口布局是否沉浸式。默认值为false。true表示窗口布局是沉浸式，false表示窗口布局是非沉浸式。


### isPrivacyMode

```
bool WindowManager_WindowProperties::isPrivacyMode
```

**描述**

窗口是否打开隐私模式。默认值为false。true表示窗口打开隐私模式，false表示窗口关闭隐私模式。


### isTransparent

```
bool WindowManager_WindowProperties::isTransparent
```

**描述**

窗口是否透明。默认值为false。true表示窗口透明，false表示窗口非透明。


### touchable

```
bool WindowManager_WindowProperties::touchable
```

**描述**

窗口是否可触。默认值为true。true表示窗口可触，false表示窗口不可触。


### type

```
WindowManager_WindowType WindowManager_WindowProperties::type
```

**描述**

窗口类型。


### windowRect

```
WindowManager_Rect WindowManager_WindowProperties::windowRect
```

**描述**

窗口的位置和尺寸。
