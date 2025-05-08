# OH_AI_ShapeInfo


## 概述

维度信息，最大的维度为OH_AI_MAX_SHAPE_NUM。

**系统能力：** SystemCapability.Ai.MindSpore

**起始版本：** 9

**相关模块：**[MindSpore](_mind_spore.md)

**所在头文件：**[model.h](model_8h.md)

## 汇总


### 成员变量

| 成员变量名称 | 描述 |
| -------- | -------- |
| [shape_num](#shape_num) | 维度数组长度。 |
| [shape](#shape) [OH_AI_MAX_SHAPE_NUM] | 维度数组。 |


## 结构体成员变量说明


### shape


```
int64_t OH_AI_ShapeInfo::shape[OH_AI_MAX_SHAPE_NUM]
```

**描述：**

维度数组。


### shape_num


```
size_t OH_AI_ShapeInfo::shape_num
```

**描述：**

维度数组长度。
