# OH_Filter


## 概述

滤镜结构体，用来生成滤镜位图。

**起始版本：** 12

**相关模块：**[EffectKit](effect_kit.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| std::vector&lt; sk_sp&lt; SkImageFilter &gt; &gt; [skFilters_](#skfilters_) | 定义存储图像滤镜对象指针的容器。  | 


## 结构体成员变量说明


### skFilters_

```
std::vector<sk_sp<SkImageFilter> > OH_Filter::skFilters_
```
**描述**

定义存储图像滤镜对象指针的容器。
