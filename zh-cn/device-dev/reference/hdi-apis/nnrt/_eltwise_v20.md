# Eltwise


## 概述

元素级别操作的算子。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_ELTWISE。

输入：

- x1，第一个输入张量。

- x2，第二个输入张量。

输出：

- output，与x1有相同的数据类型和形状。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [EltwiseMode](_n_n_rt_v20.md#eltwisemode)[mode](#mode) | 元素级别操作的类型，详情请参考：[EltwiseMode](_n_n_rt_v20.md#eltwisemode)。  | 


## 类成员变量说明


### mode

```
enum EltwiseMode Eltwise::mode
```
**描述**

元素级别操作的类型，详情请参考：[EltwiseMode](_n_n_rt_v20.md#eltwisemode)。
