# OH_Drawing_FontConfigInfo


## 概述

系统字体配置信息结构体。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)

**所在头文件：**[drawing_text_typography.h](drawing__text__typography_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [fontDirSize](#fontdirsize) | 系统字体文件路径数量。 | 
| size_t [fontGenericInfoSize](#fontgenericinfosize) | 通用字体集列表数量。 | 
| size_t [fallbackGroupSize](#fallbackgroupsize) | 备用字体集列表数量。 | 
| char \*\* [fontDirSet](#fontdirset) | 系统字体文件路径列表。 | 
| [OH_Drawing_FontGenericInfo](_o_h___drawing___font_generic_info.md) \* [fontGenericInfoSet](#fontgenericinfoset) | 通用字体集列表。 | 
| [OH_Drawing_FontFallbackGroup](_o_h___drawing___font_fallback_group.md) \* [fallbackGroupSet](#fallbackgroupset) | 备用字体集列表。 | 


## 结构体成员变量说明


### fallbackGroupSet

```
OH_Drawing_FontFallbackGroup* OH_Drawing_FontConfigInfo::fallbackGroupSet
```

**描述**

备用字体集列表。


### fallbackGroupSize

```
size_t OH_Drawing_FontConfigInfo::fallbackGroupSize
```

**描述**

备用字体集列表数量。


### fontDirSet

```
char** OH_Drawing_FontConfigInfo::fontDirSet
```

**描述**

系统字体文件路径列表。


### fontDirSize

```
size_t OH_Drawing_FontConfigInfo::fontDirSize
```

**描述**

系统字体文件路径数量。


### fontGenericInfoSet

```
OH_Drawing_FontGenericInfo* OH_Drawing_FontConfigInfo::fontGenericInfoSet
```

**描述**

通用字体集列表。


### fontGenericInfoSize

```
size_t OH_Drawing_FontConfigInfo::fontGenericInfoSize
```

**描述**

通用字体集列表数量。
