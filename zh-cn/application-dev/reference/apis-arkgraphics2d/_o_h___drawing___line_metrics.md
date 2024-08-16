# OH_Drawing_LineMetrics


## 概述

文字行位置信息。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| double [ascender](#ascender) | 文字相对于基线以上的高度。 | 
| double [descender](#descender) | 文字相对于基线以下的高度。 | 
| double [capHeight](#capheight) | 大写字母的高度。 | 
| double [xHeight](#xheight) | 小写字母的高度。 | 
| double [width](#width) | 文字宽度。 | 
| double [height](#height) | 行高。 | 
| double [x](#x) | 文字左端到容器左端距离，左对齐为0，右对齐为容器宽度减去行文字宽度。 | 
| double [y](#y) | 文字上端到容器上端高度，第一行为0，第二行为第一行高度。 | 
| size_t [startIndex](#startindex) | 行起始位置字符索引。 | 
| size_t [endIndex](#endindex) | 行结束位置字符索引。 | 
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) [firstCharMetrics](#firstcharmetrics) | 第一个字的度量信息。 | 


## 结构体成员变量说明


### ascender

```
double OH_Drawing_LineMetrics::ascender
```

**描述**

文字相对于基线以上的高度


### capHeight

```
double OH_Drawing_LineMetrics::capHeight
```

**描述**

大写字母的高度


### descender

```
double OH_Drawing_LineMetrics::descender
```

**描述**

文字相对于基线以下的高度


### endIndex

```
size_t OH_Drawing_LineMetrics::endIndex
```

**描述**

行结束位置字符索引


### firstCharMetrics

```
OH_Drawing_Font_Metrics OH_Drawing_LineMetrics::firstCharMetrics
```

**描述**

第一个字的度量信息


### height

```
double OH_Drawing_LineMetrics::height
```

**描述**

行高


### startIndex

```
size_t OH_Drawing_LineMetrics::startIndex
```

**描述**

行起始位置字符索引


### width

```
double OH_Drawing_LineMetrics::width
```

**描述**

文字宽度


### x

```
double OH_Drawing_LineMetrics::x
```

**描述**

文字左端到容器左端距离，左对齐为0，右对齐为容器宽度减去行文字宽度


### xHeight

```
double OH_Drawing_LineMetrics::xHeight
```

**描述**

小写字母的高度


### y

```
double OH_Drawing_LineMetrics::y
```

**描述**

文字上端到容器上端高度，第一行为0，第二行为第一行高度
