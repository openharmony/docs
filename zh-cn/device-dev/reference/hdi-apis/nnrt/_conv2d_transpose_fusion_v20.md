# Conv2dTransposeFusion


## 概述

对一个4维的tensor执行带有偏置的二维反卷积。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_CONV2D_TRANSPOSE_FUSION。

参数限制：当padMode==PAD_MODE_PAD时，padList的数值必须大于等于0。其他情况下padding的数值必须为0。

输入：

- x，4维tensor，并按照NHWC进行排列。

- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，inChannel/group]，inChannel必须要能整除group。

- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias参数不需要量化参数，其量化版本要求输入int32 型数据，实际量化参数由x和weight共同决定。

输出：

- output，n维tensor。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [kernelSize](#kernelsize) | 卷积核大小。 | 
| long[] [stride](#stride) | 卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。 | 
| long[] [dilation](#dilation) | 表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]， 值必须大于或等于1，并且不能超过x的height和width。 | 
| enum [PadMode](_n_n_rt_v20.md#padmode)[padMode](#padmode) | 填充类型，详情请参考：[PadMode](_n_n_rt_v20.md#padmode) | 
| long[] [padList](#padlist) | 输入x周围的填充，是一个长度为4的int数组[top，bottom，left，right]。 | 
| long [group](#group) | group，将输入x按inChannel分组。 | 
| long [inChannel](#inchannel) | 输入通道数。 | 
| long [outChannel](#outchannel) | 输出通道数。 | 
| enum [ActivationType](_n_n_rt_v20.md#activationtype)[activationType](#activationtype) | 激活函数类型，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。 | 
| long[] [outputPaddings](#outputpaddings) | 一个长度为的2整数列表，指定沿输出张量的高度和宽度的填充量。 | 


## 类成员变量说明


### activationType

```
enum ActivationType Conv2dTransposeFusion::activationType
```

**描述**


激活函数类型，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。


### dilation

```
long [] Conv2dTransposeFusion::dilation
```

**描述**


表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]， 值必须大于或等于1，并且不能超过x的height和width。


### group

```
long Conv2dTransposeFusion::group
```

**描述**


group，将输入x按inChannel分组。

- group等于1，这是常规卷积；

- group大于1且小于或等于inChannel，这是分组卷积。


### inChannel

```
long Conv2dTransposeFusion::inChannel
```

**描述**


输入通道数。


### kernelSize

```
long [] Conv2dTransposeFusion::kernelSize
```

**描述**


卷积核大小。


### outChannel

```
long Conv2dTransposeFusion::outChannel
```

**描述**


输出通道数。


### outputPaddings

```
long [] Conv2dTransposeFusion::outputPaddings
```

**描述**


一个长度为的2整数列表，指定沿输出张量的高度和宽度的填充量。


### padList

```
long [] Conv2dTransposeFusion::padList
```

**描述**


输入x周围的填充，是一个长度为4的int数组[top，bottom，left，right]。


### padMode

```
enum PadMode Conv2dTransposeFusion::padMode
```

**描述**


填充类型，详情请参考：[PadMode](_n_n_rt_v20.md#padmode)


### stride

```
long [] Conv2dTransposeFusion::stride
```

**描述**


卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。
