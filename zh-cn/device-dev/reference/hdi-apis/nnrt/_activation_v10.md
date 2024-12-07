# Activation


## 概述

激活类型的算子，所有的激活函数都属于该算子，具体的激活函数类型一句参数来确定。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_ACTIVATION。

输入：

- x，n维张量。

输出：

- 输出x经过激活函数之后的张量。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [ActivationType](_n_n_rt_v10.md#activationtype)[activationType](#activationtype) | 激活函数类型。  | 
| float [alpha](#alpha) | 尺寸因子，用于LeakyReLU和ELU激活函数。  | 
| float [minVal](#minval) | 最小值，用于HardTanh激活函数。  | 
| float [maxVal](#maxval) | 最大值，用于HardTanh激活函数。  | 
| boolean [approximate](#approximate) | 是否使用近似算法，用于GRLU激活函数。  | 


## 类成员变量说明


### activationType

```
enum ActivationType Activation::activationType
```
**描述**

激活函数类型。


### alpha

```
float Activation::alpha
```
**描述**

尺寸因子，用于LeakyReLU和ELU激活函数。


### approximate

```
boolean Activation::approximate
```
**描述**

是否使用近似算法，用于GRLU激活函数。


### maxVal

```
float Activation::maxVal
```
**描述**

最大值，用于HardTanh激活函数。


### minVal

```
float Activation::minVal
```
**描述**

最小值，用于HardTanh激活函数。
