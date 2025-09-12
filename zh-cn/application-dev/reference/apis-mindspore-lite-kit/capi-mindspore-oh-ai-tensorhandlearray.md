# OH_AI_TensorHandleArray

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## 概述

张量数组结构体，用于存储张量数组指针和张量数组长度。

**起始版本：** 9

**相关模块：** [MindSpore](capi-mindspore.md)

**所在头文件：** [model.h](capi-model-h.md)

## 汇总

### 成员变量

| 名称                                  | 描述 |
|-------------------------------------| -- |
| size_t handle_num                   | 张量数组长度。 |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md)* handle_list | 指向张量数组的指针。 |