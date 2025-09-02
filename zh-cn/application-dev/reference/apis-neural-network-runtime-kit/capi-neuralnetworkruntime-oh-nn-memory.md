# OH_NN_Memory
<!--Kit: Neural Network Runtime Kit-->
<!--Subsystem: AI-->
<!--Owner: @GbuzhidaoR-->
<!--Designer: @GbuzhidaoR-->
<!--Tester: @GbuzhidaoR-->
<!--Adviser: @ge-yafang-->

## 概述

内存结构体。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md)

**相关模块：** [NeuralNetworkRuntime](capi-neuralnetworkruntime.md)

**所在头文件：** [neural_network_runtime_type.h](capi-neural-network-runtime-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| void * const data | 指向共享内存的指针，该共享内存通常由底层硬件驱动申请。 |
| const size_t length | 记录共享内存的字节长度。 |


