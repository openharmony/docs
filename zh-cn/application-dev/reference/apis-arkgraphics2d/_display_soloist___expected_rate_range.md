# DisplaySoloist_ExpectedRateRange


## 概述

提供期望帧率范围结构体。

**起始版本：** 12

**相关模块：**[NativeDisplaySoloist](_native_display_soloist.md)

**所在头文件：**[native_display_soloist.h](native__display__soloist_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [min](#min) | 期望帧率范围最小值，取值范围为[0,120]。 | 
| int32_t [max](#max) | 期望帧率范围最大值，取值范围为[0,120]。 | 
| int32_t [expected](#expected) | 期望帧率，取值范围为[0,120]。 | 


## 结构体成员变量说明


### expected

```
int32_t DisplaySoloist_ExpectedRateRange::expected
```

**描述**

期望帧率，取值范围为[0,120]。


### max

```
int32_t DisplaySoloist_ExpectedRateRange::max
```

**描述**

期望帧率范围最大值，取值范围为[0,120]。


### min

```
int32_t DisplaySoloist_ExpectedRateRange::min
```

**描述**

期望帧率范围最小值，取值范围为[0,120]。
