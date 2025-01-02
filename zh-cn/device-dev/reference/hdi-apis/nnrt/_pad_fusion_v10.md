# PadFusion


## 概述

在x指定维度的数据前后，添加指定数值进行增广。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_PAD_FUSION。

参数限制：当paddingMode==PADDING_MODE_CONSTANT时，需要设置constantValue，默认constantValue为0。

输入：

- x，n维tensor

- paddings，一个2维tensor，指定每一维度增补的长度，shape为[n，2]。paddings[i][0]表示第i维上，需要在输入张量前增补的数量； paddings[i][1]表示第i维上，需要在输入张量x后增补的数量。

输出：

- output，一个n维tensor，维数和数据类型和x保持一致。shape由x和paddings共同决定 output.shape[i] = input.shape[i] + paddings[i][0]+paddings[i][1]。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[][] [paddings](#paddings) | 一个2维tensor，指定每一维度增补的长度，shape为[n，2]。paddings[i][0]表示第i维上，需要在x1前增补的数量； paddings[i][1]表示第i维上，需要在x1后增补的数量。 该参数和输入的paddings意义相同。  | 
| enum [PaddingMode](_n_n_rt_v10.md#paddingmode)[paddingMode](#paddingmode) | 填充类型。 详情请参考：[PaddingMode](_n_n_rt_v10.md#paddingmode)。  | 
| float [constantValue](#constantvalue) | 一个常数，数据类型和x一致，指定Pad操作增广的数值。 仅paddingMode==PADDING_MODE_CONSTANT时生效，默认值为0。  | 


## 类成员变量说明


### constantValue

```
float PadFusion::constantValue
```
**描述**

一个常数，数据类型和x一致，指定Pad操作增广的数值。 仅paddingMode==PADDING_MODE_CONSTANT时生效，默认值为0。


### paddingMode

```
enum PaddingMode PadFusion::paddingMode
```
**描述**

填充类型。 详情请参考：[PaddingMode](_n_n_rt_v10.md#paddingmode)。


### paddings

```
long [][] PadFusion::paddings
```
**描述**

一个2维tensor，指定每一维度增补的长度，shape为[n，2]。paddings[i][0]表示第i维上，需要在x1前增补的数量； paddings[i][1]表示第i维上，需要在x1后增补的数量。 该参数和输入的paddings意义相同。
