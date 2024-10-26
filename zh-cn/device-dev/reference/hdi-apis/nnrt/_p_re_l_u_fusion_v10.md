# PReLUFusion


## 概述

计算x和weight的PReLU激活值。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_PRELU_FUSION。

输入：

- x，一个n维tensor，如果n&gt;=2，则要求x1的排布为[BatchSize，…，Channels]，第二个维度为通道数。

- weight，一个1维tensor。weight的长度只能是1或者等于通道数。当weight长度为1，则x所有通道共享一个权重值。 若weight长度等于通道数，每个通道独享一个权重，若x维数n&lt;2，weight长度只能为1。

输出：

- output，x的PReLU激活值。形状和数据类型和x保持一致。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [channelShared](#channelshared) | 是否开启权重共享，可以用于校验参数合法性。 若weight的是1则channelShared一定为true，否则为false。  | 


## 类成员变量说明


### channelShared

```
boolean PReLUFusion::channelShared
```
**描述**

是否开启权重共享，可以用于校验参数合法性。 若weight的是1则channelShared一定为true，否则为false。
