# OH_NN_QuantParam
<!--Kit_Neural Network Runtime Kit--><!--System_AI-->

## 概述

量化信息。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)

**相关模块：** [NeuralNetworkRuntime](capi-neuralnetworkruntime.md)

**所在头文件：** [neural_network_runtime_type.h](capi-neural-network-runtime-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t quantCount | 指定numBits、scale和zeroPoint数组的长度。在per-layer量化的场景下，quantCount通常指定为1，即一个张量所有通道共享一套量化参数；在per-channel量化场景下，quantCount通常和张量通道数一致，每个通道使用自己的量化参数。 |
| const uint32_t *numBits | 量化位数。 |
| const double *scale | 指向量化公式中scale数据的指针。 |
| const int32_t *zeroPoint | 指向量化公式中zero point数据的指针。 |


