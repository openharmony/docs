# PresentParam


## 概述

定义显示参数。

**起始版本：** 5.0

**相关模块：**[Display](index_composer_display_v12.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [isLowLatency](#islowlatency) | 低延迟显示标志 | 
| unsigned int [sliceHeight](#sliceheight) | 切片高度 | 
| unsigned int [sliceNum](#slicenum) | 当前帧率 | 
| unsigned int [imageDimension](#imagedimension) | 低16位表示图像宽度，高16位表示图像高度 | 
| int [reserve](#reserve) | 预留 | 


## 结构体成员变量说明


### imageDimension

```
unsigned int PresentParam::imageDimension
```

**描述**

低16位表示图像宽度，高16位表示图像高度


### isLowLatency

```
unsigned int PresentParam::isLowLatency
```

**描述**

低延迟显示标志


### reserve

```
int PresentParam::reserve
```

**描述**

预留


### sliceHeight

```
unsigned int PresentParam::sliceHeight
```

**描述**

切片高度


### sliceNum

```
unsigned int PresentParam::sliceNum
```

**描述**

当前帧率
