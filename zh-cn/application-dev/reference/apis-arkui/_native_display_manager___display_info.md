# NativeDisplayManager_DisplayInfo


## 概述

显示设备的对象属性。

**起始版本：** 14

**相关模块：**[OH_DisplayManager](_o_h___display_manager.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [id](#id) | 显示设备的屏幕id号，为非负整数。 | 
| char [name](#name) [OH_DISPLAY_NAME_LENGTH+1] | 显示设备的名称。 | 
| bool [isAlive](#isalive) | 显示设备是否启用：true表示设备启动，false表示设备未启用。 | 
| int32_t [width](#width) | 显示设备的屏幕宽度，单位为px，该参数应为非负整数。 | 
| int32_t [height](#height) | 显示设备的屏幕高度，单位为px，该参数应为非负整数。 | 
| int32_t [physicalWidth](#physicalwidth) | 显示设备的物理宽度，单位为px，该参数应为非负整数。 | 
| int32_t [physicalHeight](#physicalheight) | 显示设备的物理高度，单位为px，该参数应为非负整数。 | 
| uint32_t [refreshRate](#refreshrate) | 显示设备的刷新率，单位为Hz，该参数应为非负整数。 | 
| uint32_t [availableWidth](#availablewidth) | 2in1设备上屏幕的可用区域宽度，单位为px，该参数为非负整数。 | 
| uint32_t [availableHeight](#availableheight) | 2in1设备上屏幕的可用区域高度，单位为px，该参数为非负整数。 | 
| float [densityDPI](#densitydpi) | 显示设备屏幕的物理像素密度，表示每英寸上的像素点数。该参数为大于0的浮点数，单位为px。一般取值160.0、480.0等，实际能取到的值取决于不同设备设置里提供的可选值。 | 
| float [densityPixels](#densitypixels) | 显示设备逻辑像素的密度，代表物理像素与逻辑像素的缩放系数。该参数为大于0的浮点数，受densityDPI范围限制，取值范围在[0.5，4.0]。一般取值1.0、3.0等，实际取值取决于不同设备提供的densityDPI。 | 
| float [scaledDensity](#scaleddensity) | 显示设备的显示字体的缩放因子。该参数为大于0的浮点数，通常与densityPixels相同。 | 
| float [xDPI](#xdpi) | 显示设备x方向中每英寸屏幕的确切物理像素值，该参数为大于0的浮点数。 | 
| float [yDPI](#ydpi) | 显示设备y方向中每英寸屏幕的确切物理像素值，该参数为大于0的浮点数。 | 
| [NativeDisplayManager_Rotation](_o_h___display_manager.md#nativedisplaymanager_rotation)[rotation](#rotation) | 显示设备的屏幕顺时针旋转角度。 | 
| [NativeDisplayManager_DisplayState](_o_h___display_manager.md#nativedisplaymanager_displaystate)[state](#state) | 显示设备的状态。 | 
| [NativeDisplayManager_Orientation](_o_h___display_manager.md#nativedisplaymanager_orientation)[orientation](#orientation) | 表示屏幕当前显示的方向。 | 
| [NativeDisplayManager_DisplayHdrFormat](_native_display_manager___display_hdr_format.md) \* [hdrFormat](#hdrformat) | 显示设备支持的所有HDR格式。 | 
| [NativeDisplayManager_DisplayColorSpace](_native_display_manager___display_color_space.md) \* [colorSpace](#colorspace) | 显示设备支持的所有色域类型。 | 


## 结构体成员变量说明


### availableHeight

```
uint32_t NativeDisplayManager_DisplayInfo::availableHeight
```

**描述**

2in1设备上屏幕的可用区域高度，单位为px，该参数为非负整数。


### availableWidth

```
uint32_t NativeDisplayManager_DisplayInfo::availableWidth
```

**描述**

2in1设备上屏幕的可用区域宽度，单位为px，该参数为非负整数。


### colorSpace

```
NativeDisplayManager_DisplayColorSpace* NativeDisplayManager_DisplayInfo::colorSpace
```

**描述**

显示设备支持的所有色域类型。


### densityDPI

```
float NativeDisplayManager_DisplayInfo::densityDPI
```

**描述**

显示设备屏幕的物理像素密度，表示每英寸上的像素点数。该参数为大于0的浮点数，单位为px。一般取值160.0、480.0等，实际能取到的值取决于不同设备设置里提供的可选值。


### densityPixels

```
float NativeDisplayManager_DisplayInfo::densityPixels
```

**描述**

显示设备逻辑像素的密度，代表物理像素与逻辑像素的缩放系数。该参数为大于0的浮点数，受densityDPI范围限制，取值范围在[0.5，4.0]。一般取值1.0、3.0等，实际取值取决于不同设备提供的densityDPI。


### hdrFormat

```
NativeDisplayManager_DisplayHdrFormat* NativeDisplayManager_DisplayInfo::hdrFormat
```

**描述**

显示设备支持的所有HDR格式。


### height

```
int32_t NativeDisplayManager_DisplayInfo::height
```

**描述**

显示设备的屏幕高度，单位为px，该参数应为非负整数。


### id

```
uint32_t NativeDisplayManager_DisplayInfo::id
```

**描述**

显示设备的屏幕id号，为非负整数。


### isAlive

```
bool NativeDisplayManager_DisplayInfo::isAlive
```

**描述**

显示设备是否启用：true表示设备启动，false表示设备未启用。


### name

```
char NativeDisplayManager_DisplayInfo::name[OH_DISPLAY_NAME_LENGTH+1]
```

**描述**

显示设备的名称。


### orientation

```
NativeDisplayManager_Orientation NativeDisplayManager_DisplayInfo::orientation
```

**描述**

表示屏幕当前显示的方向。


### physicalHeight

```
int32_t NativeDisplayManager_DisplayInfo::physicalHeight
```

**描述**

显示设备的物理高度，单位为px，该参数应为非负整数。


### physicalWidth

```
int32_t NativeDisplayManager_DisplayInfo::physicalWidth
```

**描述**

显示设备的物理宽度，单位为px，该参数应为非负整数。


### refreshRate

```
uint32_t NativeDisplayManager_DisplayInfo::refreshRate
```

**描述**

显示设备的刷新率，单位为Hz，该参数应为非负整数。


### rotation

```
NativeDisplayManager_Rotation NativeDisplayManager_DisplayInfo::rotation
```

**描述**

显示设备的屏幕顺时针旋转角度。


### scaledDensity

```
float NativeDisplayManager_DisplayInfo::scaledDensity
```

**描述**

显示设备的显示字体的缩放因子。该参数为大于0的浮点数，通常与densityPixels相同。


### state

```
NativeDisplayManager_DisplayState NativeDisplayManager_DisplayInfo::state
```

**描述**

显示设备的状态。


### width

```
int32_t NativeDisplayManager_DisplayInfo::width
```

**描述**

显示设备的屏幕宽度，单位为px，该参数应为非负整数。


### xDPI

```
float NativeDisplayManager_DisplayInfo::xDPI
```

**描述**

显示设备x方向中每英寸屏幕的确切物理像素值，该参数为大于0的浮点数。


### yDPI

```
float NativeDisplayManager_DisplayInfo::yDPI
```

**描述**

显示设备y方向中每英寸屏幕的确切物理像素值，该参数为大于0的浮点数。
