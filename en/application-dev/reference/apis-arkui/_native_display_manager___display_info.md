# NativeDisplayManager_DisplayInfo


## Overview

The NativeDisplayManager_DisplayInfo struct encapsulates the information about a display.

**Since**: 14

**Related module**: [OH_DisplayManager](_o_h___display_manager.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [id](#id) | ID of the display. The value must be a non-negative integer.| 
| char [name](#name) [OH_DISPLAY_NAME_LENGTH+1] | Name of the display.| 
| bool [isAlive](#isalive) | Whether the display is active. The value **true** means that the display is active, and **false** means the opposite.| 
| int32_t [width](#width) | Width of the display, in px. The value must be a non-negative integer.| 
| int32_t [height](#height) | Height of the display, in px. The value must be a non-negative integer.| 
| int32_t [physicalWidth](#physicalwidth) | Physical width of the display, in px. The value must be a non-negative integer.| 
| int32_t [physicalHeight](#physicalheight) | Physical height of the display, in px. The value must be a non-negative integer.| 
| uint32_t [refreshRate](#refreshrate) | Refresh rate of the display, in Hz. The value must be a non-negative integer.| 
| uint32_t [availableWidth](#availablewidth) | Width of the available area on a 2-in-1 device, in px. The value must be a non-negative integer.| 
| uint32_t [availableHeight](#availableheight) | Height of the available area on a 2-in-1 device, in px. The value must be a non-negative integer.| 
| float [densityDPI](#densitydpi) | Physical pixel density of the display, that is, the number of pixels per inch. The value must be a floating point number greater than 0. The unit is px. Generally, the value is **160.0** or **480.0**. The actual value depends on the optional values provided by the device in use.| 
| float [densityPixels](#densitypixels) | Logical pixel density of the display, which is the scaling coefficient between physical pixels and logical pixels. The value is a floating point number greater than 0 and is restricted by the range of **densityDPI**. The value range is [0.5, 4.0]. Generally, the value is **1.0** or **3.0**. The actual value depends on the density DPI provided by the device in use.| 
| float [scaledDensity](#scaleddensity) | Scaling factor for fonts displayed on the display. The value must be a floating point number greater than 0. Generally, the value is the same as that of **densityPixels**.| 
| float [xDPI](#xdpi) | Exact physical pixels per inch of the display in the X dimension. The value must be a floating point number greater than 0.| 
| float [yDPI](#ydpi) | Exact physical pixels per inch of the display in the Y dimension. The value must be a floating point number greater than 0.| 
| [NativeDisplayManager_Rotation](_o_h___display_manager.md#nativedisplaymanager_rotation)[rotation](#rotation) | Clockwise rotation angle of the display.| 
| [NativeDisplayManager_DisplayState](_o_h___display_manager.md#nativedisplaymanager_displaystate)[state](#state) | State of the display.| 
| [NativeDisplayManager_Orientation](_o_h___display_manager.md#nativedisplaymanager_orientation)[orientation](#orientation) | Orientation of the display.| 
| [NativeDisplayManager_DisplayHdrFormat](_native_display_manager___display_hdr_format.md) \* [hdrFormat](#hdrformat) | All the HDR formats supported by the display.| 
| [NativeDisplayManager_DisplayColorSpace](_native_display_manager___display_color_space.md) \* [colorSpace](#colorspace) | All the color spaces supported by the display.| 


## Member Variable Description


### availableHeight

```
uint32_t NativeDisplayManager_DisplayInfo::availableHeight
```

**Description**

Height of the available area on a 2-in-1 device, in px. The value must be a non-negative integer.


### availableWidth

```
uint32_t NativeDisplayManager_DisplayInfo::availableWidth
```

**Description**

Width of the available area on a 2-in-1 device, in px. The value must be a non-negative integer.


### colorSpace

```
NativeDisplayManager_DisplayColorSpace* NativeDisplayManager_DisplayInfo::colorSpace
```

**Description**

All the color spaces supported by the display.


### densityDPI

```
float NativeDisplayManager_DisplayInfo::densityDPI
```

**Description**

Physical pixel density of the display, that is, the number of pixels per inch. The value must be a floating point number greater than 0. The unit is px. Generally, the value is **160.0** or **480.0**. The actual value depends on the optional values provided by the device in use.


### densityPixels

```
float NativeDisplayManager_DisplayInfo::densityPixels
```

**Description**

Logical pixel density of the display, which is the scaling coefficient between physical pixels and logical pixels. The value is a floating point number greater than 0 and is restricted by the range of **densityDPI**. The value range is [0.5, 4.0]. Generally, the value is **1.0** or **3.0**. The actual value depends on the density DPI provided by the device in use.


### hdrFormat

```
NativeDisplayManager_DisplayHdrFormat* NativeDisplayManager_DisplayInfo::hdrFormat
```

**Description**

All the HDR formats supported by the display.


### height

```
int32_t NativeDisplayManager_DisplayInfo::height
```

**Description**

Height of the display, in px. The value must be a non-negative integer.


### id

```
uint32_t NativeDisplayManager_DisplayInfo::id
```

**Description**

ID of the display. The value must be a non-negative integer.


### isAlive

```
bool NativeDisplayManager_DisplayInfo::isAlive
```

**Description**

Whether the display is active. The value **true** means that the display is active, and **false** means the opposite.


### name

```
char NativeDisplayManager_DisplayInfo::name[OH_DISPLAY_NAME_LENGTH+1]
```

**Description**

Name of the display.


### orientation

```
NativeDisplayManager_Orientation NativeDisplayManager_DisplayInfo::orientation
```

**Description**

Orientation of the display.


### physicalHeight

```
int32_t NativeDisplayManager_DisplayInfo::physicalHeight
```

**Description**

Physical height of the display, in px. The value must be a non-negative integer.


### physicalWidth

```
int32_t NativeDisplayManager_DisplayInfo::physicalWidth
```

**Description**

Physical width of the display, in px. The value must be a non-negative integer.


### refreshRate

```
uint32_t NativeDisplayManager_DisplayInfo::refreshRate
```

**Description**

Refresh rate of the display, in Hz. The value must be a non-negative integer.


### rotation

```
NativeDisplayManager_Rotation NativeDisplayManager_DisplayInfo::rotation
```

**Description**

Clockwise rotation angle of the display.


### scaledDensity

```
float NativeDisplayManager_DisplayInfo::scaledDensity
```

**Description**

Scaling factor for fonts displayed on the display. The value must be a floating point number greater than 0. Generally, the value is the same as that of **densityPixels**.


### state

```
NativeDisplayManager_DisplayState NativeDisplayManager_DisplayInfo::state
```

**Description**

State of the display.


### width

```
int32_t NativeDisplayManager_DisplayInfo::width
```

**Description**

Width of the display, in px. The value must be a non-negative integer.


### xDPI

```
float NativeDisplayManager_DisplayInfo::xDPI
```

**Description**

Exact physical pixels per inch of the display in the X dimension. The value must be a floating point number greater than 0.


### yDPI

```
float NativeDisplayManager_DisplayInfo::yDPI
```

**Description**

Exact physical pixels per inch of the display in the Y dimension. The value must be a floating point number greater than 0.
