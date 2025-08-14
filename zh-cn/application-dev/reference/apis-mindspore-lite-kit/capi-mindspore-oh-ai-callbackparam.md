# OH_AI_CallBackParam

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--SE: @zhuguodong8; @jjfeing-->
<!--TSE: @principal87-->

## 概述

回调函数中传入的算子信息。

**起始版本：** 9

**相关模块：** [MindSpore](capi-mindspore.md)

**所在头文件：** [model.h](capi-model-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* node_name | 算子名称。 |
| char* node_type | 算子类型。 |