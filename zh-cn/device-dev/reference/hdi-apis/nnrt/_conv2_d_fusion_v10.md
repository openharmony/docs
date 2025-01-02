# Conv2DFusion


## 概述

对将4维的tensor执行带有偏置的二维卷积运算。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_CONV2D_FUSION。

参数限制：当padMode==PAD_MODE_PAD时，padList的数值必须大于等于0。其他情况下padding的数值必须为0。

输入：

- x，4维tensor，并按照NHWC进行排列。

- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，inChannel/group]， inChannel必须要能整除group。

- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias 参数不需要量化参数，其量化 版本要求输入 int32 类型数据，实际量化参数由 x 和 weight 共同决定。

输出：

- output，卷积的输出。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [kernelSize](#kernelsize) | 卷积核大小。 | 
| long[] [stride](#stride) | 卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。 | 
| long[] [dilation](#dilation) | 表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]， 值必须大于或等于1，并且不能超过x的height和width。 | 
| enum [PadMode](_n_n_rt_v10.md#padmode)[padMode](#padmode) | 填充类型，详情请参考：[PadMode](_n_n_rt_v10.md#padmode)。 | 
| long[] [padList](#padlist) | 输入x周围的填充，是一个长度为4的int数组[top，bottom，left，right]。 | 
| long [group](#group) | group，将输入x按inChannel分组，int类型。 | 
| long [inChannel](#inchannel) | 输入通道数量。 | 
| long [outChannel](#outchannel) | 输出通道数量。 | 
| enum [ActivationType](_n_n_rt_v10.md#activationtype)[activationType](#activationtype) | 激活函数类型，详情请参考：[ActivationType](_n_n_rt_v10.md#activationtype)。 | 


## 类成员变量说明


### activationType

```
enum ActivationType Conv2DFusion::activationType
```

**描述**


激活函数类型，详情请参考：[ActivationType](_n_n_rt_v10.md#activationtype)。


### dilation

```
long [] Conv2DFusion::dilation
```

**描述**


表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]， 值必须大于或等于1，并且不能超过x的height和width。


### group

```
long Conv2DFusion::group
```

**描述**


group，将输入x按inChannel分组，int类型。

- group等于1，这是常规卷积。

- group等于inChannel，这是depthwiseConv2d，此时group==in_channel==out_channel。

- group大于1且小于inChannel，这是分组卷积，此时out_channel==group。


### inChannel

```
long Conv2DFusion::inChannel
```

**描述**


输入通道数量。


### kernelSize

```
long [] Conv2DFusion::kernelSize
```

**描述**


卷积核大小。


### outChannel

```
long Conv2DFusion::outChannel
```

**描述**


输出通道数量。


### padList

```
long [] Conv2DFusion::padList
```

**描述**


输入x周围的填充，是一个长度为4的int数组[top，bottom，left，right]。


### padMode

```
enum PadMode Conv2DFusion::padMode
```

**描述**


填充类型，详情请参考：[PadMode](_n_n_rt_v10.md#padmode)。


### stride

```
long [] Conv2DFusion::stride
```

**描述**


卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。
