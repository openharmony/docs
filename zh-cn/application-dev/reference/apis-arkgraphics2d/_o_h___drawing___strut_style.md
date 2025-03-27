# OH_Drawing_StrutStyle


## 概述

用于描述支柱样式的结构体。支柱样式用于控制绘制文本时行之间的间距、基线对齐方式以及其他与行高相关的属性。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) [weight](#weight) | 计算支柱时使用的字体粗细。  | 
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) [style](#style) | 计算支柱时使用的字体格式。  | 
| double [size](#size) | 逻辑像素中的上升加下降的大小。  | 
| double [heightScale](#heightscale) | 行高缩放系数。  | 
| bool [heightOverride](#heightoverride) | 是否启用高度覆盖，true表示启用，false表示不启用。  | 
| bool [halfLeading](#halfleading) | 半行距是否启用，true表示启用，false表示不启用。  | 
| double [leading](#leading) | 以自定义行距应用于支柱的行距。  | 
| bool [forceStrutHeight](#forcestrutheight) | 是否所有行都将使用支柱的高度，true表示使用，false表示不使用。  | 
| size_t [familiesSize](#familiessize) | 字体家族的数量。  | 
| char \*\* [families](#families) | 计算支柱时使用的字体名称。  | 


## 结构体成员变量说明


### families

```
char** OH_Drawing_StrutStyle::families
```
**描述**

计算支柱时使用的字体名称。


### familiesSize

```
size_t OH_Drawing_StrutStyle::familiesSize
```

**描述**

字体家族的数量。


### forceStrutHeight

```
bool OH_Drawing_StrutStyle::forceStrutHeight
```
**描述**

是否所有行都将使用支柱的高度，true表示使用，false表示不使用。


### halfLeading

```
bool OH_Drawing_StrutStyle::halfLeading
```
**描述**

半行距是否启用，true表示启用，false表示不启用。


### heightOverride

```
bool OH_Drawing_StrutStyle::heightOverride
```

**描述**

是否启用高度覆盖，true表示启用，false表示不启用。


### heightScale

```
double OH_Drawing_StrutStyle::heightScale
```

**描述**

行高缩放系数。


### leading

```
double OH_Drawing_StrutStyle::leading
```

**描述**

以自定义行距应用于支柱的行距。


### size

```
double OH_Drawing_StrutStyle::size
```

**描述**

逻辑像素中的上升加下降的大小。


### style

```
OH_Drawing_FontStyle OH_Drawing_StrutStyle::style
```

**描述**

计算支柱时使用的字体格式。


### weight

```
OH_Drawing_FontWeight OH_Drawing_StrutStyle::weight
```

**描述**

计算支柱时使用的字体粗细。
