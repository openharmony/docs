# OH_Drawing_Font_Metrics


## 概述

定义字体度量信息的结构体。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [fFlags](#fflags) | 指示哪些度量是有效的。 | 
| float [top](#top) | 字符最高点到基线的最大距离。 | 
| float [ascent](#ascent) | 字符最高点到基线的推荐距离。 | 
| float [descent](#descent) | 字符最低点到基线的推荐距离。 | 
| float [bottom](#bottom) | 字符最低点到基线的最大距离。 | 
| float [leading](#leading) | 行间距。 | 
| float [avgCharWidth](#avgcharwidth) | 平均字符宽度，如果未知则为零。 | 
| float [maxCharWidth](#maxcharwidth) | 最大字符宽度，如果未知则为零。 | 
| float [xMin](#xmin) | 任何字形边界框原点左侧的最大范围，通常为负值；不推荐使用可变字体。 | 
| float [xMax](#xmax) | 任何字形边界框原点右侧的最大范围，通常为负值；不推荐使用可变字体。 | 
| float [xHeight](#xheight) | 小写字母的高度，如果未知则为零，通常为负数。 | 
| float [capHeight](#capheight) | 大写字母的高度，如果未知则为零，通常为负数。 | 
| float [underlineThickness](#underlinethickness) | 下划线粗细。 | 
| float [underlinePosition](#underlineposition) | 表示下划线的位置，即从基线到文字下方笔画顶部的垂直距离，通常为正值。 | 
| float [strikeoutThickness](#strikeoutthickness) | 删除线粗细。 | 
| float [strikeoutPosition](#strikeoutposition) | 表示删除线的位置，即从基线到文字上方笔画底部的垂直距离，通常为负值。 | 


## 结构体成员变量说明


### ascent

```
float OH_Drawing_Font_Metrics::ascent
```

**描述**

字符最高点到基线的推荐距离。


### avgCharWidth

```
float OH_Drawing_Font_Metrics::avgCharWidth
```

**描述**

平均字符宽度，如果未知则为零。


### bottom

```
float OH_Drawing_Font_Metrics::bottom
```

**描述**

字符最低点到基线的最大距离。


### capHeight

```
float OH_Drawing_Font_Metrics::capHeight
```

**描述**

大写字母的高度，如果未知则为零，通常为负数。


### descent

```
float OH_Drawing_Font_Metrics::descent
```

**描述**

字符最低点到基线的推荐距离。


### fFlags

```
uint32_t OH_Drawing_Font_Metrics::fFlags
```

**描述**

指示哪些度量是有效的。


### leading

```
float OH_Drawing_Font_Metrics::leading
```

**描述**

行间距。


### maxCharWidth

```
float OH_Drawing_Font_Metrics::maxCharWidth
```

**描述**

最大字符宽度，如果未知则为零。


### strikeoutPosition

```
float OH_Drawing_Font_Metrics::strikeoutPosition
```

**描述**

表示删除线的位置，即从基线到文字上方笔画底部的垂直距离，通常为负值。


### strikeoutThickness

```
float OH_Drawing_Font_Metrics::strikeoutThickness
```

**描述**

删除线粗细。


### top

```
float OH_Drawing_Font_Metrics::top
```

**描述**

字符最高点到基线的最大距离。


### underlinePosition

```
float OH_Drawing_Font_Metrics::underlinePosition
```

**描述**

表示下划线的位置，即从基线到文字下方笔画顶部的垂直距离，通常为正值。


### underlineThickness

```
float OH_Drawing_Font_Metrics::underlineThickness
```

**描述**

下划线粗细。


### xHeight

```
float OH_Drawing_Font_Metrics::xHeight
```

**描述**

小写字母的高度，如果未知则为零，通常为负数。


### xMax

```
float OH_Drawing_Font_Metrics::xMax
```

**描述**

任何字形边界框原点右侧的最大范围，通常为负值；不推荐使用可变字体。


### xMin

```
float OH_Drawing_Font_Metrics::xMin
```

**描述**

任何字形边界框原点左侧的最大范围，通常为负值；不推荐使用可变字体。
