# AvgPoolFusion


## 概述

在输入tensor上应用 2D 平均池化。支持int8量化输入。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_AVGPOOL_FUSION。

参数限制：当padMode==PAD_MODE_PAD时，padList的数值必须大于等于0。其他情况下padding的数值必须为0。

输入：

- x，n维张量。

输出：

- output， 输出平均池化后的张量。

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
| [kernelSize](#kernelsize) | long[]<br/>用来取平均值的kernel大小 | 
| [strides](#strides) | long[]<br/>kernel移动的距离 | 
| [pad](#pad) | long[]<br/>x周围的填充 | 
| [padMode](#padmode) | enum&nbsp;[PadMode](_n_n_rt.md#padmode)<br/>填充模式 | 
| [roundMode](#roundmode) | enum&nbsp;[RoundMode](_n_n_rt.md#roundmode)<br/>取整数的算法 | 
| [format](#format) | enum&nbsp;[Format](_n_n_rt.md#format)<br/>运算时的数据排列排列，详情请参考：[Format](_n_n_rt.md#format) | 
| [global](#global) | boolean<br/>是否是全局池化 | 
| [activationType](#activationtype) | enum&nbsp;[ActivationType](_n_n_rt.md#activationtype)<br/>激活函数，详情请参考：[ActivationType](_n_n_rt.md#activationtype) | 


## 类成员变量说明


### activationType

  
```
enum ActivationType AvgPoolFusion::activationType
```

**描述:**

激活函数，详情请参考：[ActivationType](_n_n_rt.md#activationtype)


### format

  
```
enum Format AvgPoolFusion::format
```

**描述:**

运算时的数据排列排列，详情请参考：[Format](_n_n_rt.md#format)


### global

  
```
boolean AvgPoolFusion::global
```

**描述:**

是否是全局池化


### kernelSize

  
```
long [] AvgPoolFusion::kernelSize
```

**描述:**

用来取平均值的kernel大小，是一个长度为2的int数组[kernel_height，kernel_weight]， 第一个数表示kernel高度，第二个数表示kernel宽度。


### pad

  
```
long [] AvgPoolFusion::pad
```

**描述:**

x周围的填充，是一个长度为4的int数组[top，bottom，left，right]，并且以最近邻的值填充。


### padMode

  
```
enum PadMode AvgPoolFusion::padMode
```

**描述:**

填充模式


### roundMode

  
```
enum RoundMode AvgPoolFusion::roundMode
```

**描述:**

取整数的算法


### strides

  
```
long [] AvgPoolFusion::strides
```

**描述:**

kernel移动的距离，是一个长度为2的int数组[stride_height，stride_weight]， 第一个数表示高度上的移动步幅，第二个数表示宽度上的移动步幅。
