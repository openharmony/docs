# Eltwise


## 概述

元素级别操作的算子。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_ELTWISE。

输入：

- x1，第一个输入张量。

- x2，第二个输入张量。

输出：

- output，与x1有相同的数据类型和形状。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [mode](#mode) | enum&nbsp;[EltwiseMode](_n_n_rt.md#eltwisemode)<br/>元素级别操作的类型，详情请参考：[EltwiseMode](_n_n_rt.md#eltwisemode)。&nbsp; | 


## 类成员变量说明


### mode

  
```
enum EltwiseMode Eltwise::mode
```
**描述:**

元素级别操作的类型，详情请参考：[EltwiseMode](_n_n_rt.md#eltwisemode)。
