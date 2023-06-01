# Conv2dTransposeFusion


## 概述

对一个4维的tensor执行带有偏置的二维反卷积。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_CONV2D_TRANSPOSE_FUSION。

参数限制：当padMode==PAD_MODE_PAD时，padList的数值必须大于等于0。其他情况下padding的数值必须为0。

输入：

- x，4维tensor，并按照NHWC进行排列。

- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，inChannel/group]， inChannel必须要能整除group。

- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias 参数不需要量化参数，其量化 版本要求输入 int32 类型数据，实际量化参数由 x 和 weight 共同决定。

输出：

- output，n维tensor。

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
| [kernelSize](#kernelsize) | long[]<br/>卷积核大小。&nbsp; | 
| [stride](#stride) | long[]<br/>卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。&nbsp; | 
| [dilation](#dilation) | long[]<br/>表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]，&nbsp;值必须大于或等于1，并且不能超过x的height和width。&nbsp; | 
| [padMode](#padmode) | enum&nbsp;[PadMode](_n_n_rt.md#padmode)<br/>填充类型，详情请参考：[PadMode](_n_n_rt.md#padmode) | 
| [padList](#padlist) | long[]<br/>输入x周围的填充，是一个长度为4的int数组[top，bottom，left，right]。&nbsp; | 
| [group](#group) | long<br/>group，将输入x按inChannel分组。&nbsp;group等于1，这是常规卷积；&nbsp;group大于1且小于或等于inChannel，这是分组卷积。&nbsp; | 
| [inChannel](#inchannel) | long<br/>输入通道数。&nbsp; | 
| [outChannel](#outchannel) | long<br/>输出通道数。&nbsp; | 
| [activationType](#activationtype) | enum&nbsp;[ActivationType](_n_n_rt.md#activationtype)<br/>激活函数类型，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。&nbsp; | 
| [outputPaddings](#outputpaddings) | long[]<br/>一个长度为的2整数列表，指定沿输出张量的高度和宽度的填充量。&nbsp; | 


## 类成员变量说明


### activationType

  
```
enum ActivationType Conv2dTransposeFusion::activationType
```
**描述:**
激活函数类型，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。


### dilation

  
```
long [] Conv2dTransposeFusion::dilation
```
**描述:**
表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]， 值必须大于或等于1，并且不能超过x的height和width。


### group

  
```
long Conv2dTransposeFusion::group
```
**描述:**
group，将输入x按inChannel分组。 group等于1，这是常规卷积； group大于1且小于或等于inChannel，这是分组卷积。


### inChannel

  
```
long Conv2dTransposeFusion::inChannel
```
**描述:**
输入通道数。


### kernelSize

  
```
long [] Conv2dTransposeFusion::kernelSize
```
**描述:**
卷积核大小。


### outChannel

  
```
long Conv2dTransposeFusion::outChannel
```
**描述:**
输出通道数。


### outputPaddings

  
```
long [] Conv2dTransposeFusion::outputPaddings
```
**描述:**
一个长度为的2整数列表，指定沿输出张量的高度和宽度的填充量。


### padList

  
```
long [] Conv2dTransposeFusion::padList
```
**描述:**
输入x周围的填充，是一个长度为4的int数组[top，bottom，left，right]。


### padMode

  
```
enum PadMode Conv2dTransposeFusion::padMode
```
**描述:**
填充类型，详情请参考：[PadMode](_n_n_rt.md#padmode)


### stride

  
```
long [] Conv2dTransposeFusion::stride
```
**描述:**
卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。
