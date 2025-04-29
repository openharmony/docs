# OH_Drawing_FontFallbackGroup


## 概述

备用字体集信息结构体。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)

**所在头文件：**[drawing_text_typography.h](drawing__text__typography_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [groupName](#groupname) | 备用字体集所对应的字体集名称，如果值为空，表示可以使用备用字体集列表集所有的字体。  | 
| size_t [fallbackInfoSize](#fallbackinfosize) | 备用字体集数量。  | 
| [OH_Drawing_FontFallbackInfo](_o_h___drawing___font_fallback_info.md) \* [fallbackInfoSet](#fallbackinfoset) | 备用字体集列表。  | 


## 结构体成员变量说明


### fallbackInfoSet

```
OH_Drawing_FontFallbackInfo* OH_Drawing_FontFallbackGroup::fallbackInfoSet
```
**描述**

备用字体集列表。


### fallbackInfoSize

```
size_t OH_Drawing_FontFallbackGroup::fallbackInfoSize
```
**描述**

备用字体集数量。


### groupName

```
char* OH_Drawing_FontFallbackGroup::groupName
```
**描述**

备用字体集所对应的字体集名称，如果值为空，表示可以使用备用字体集列表集所有的字体。
