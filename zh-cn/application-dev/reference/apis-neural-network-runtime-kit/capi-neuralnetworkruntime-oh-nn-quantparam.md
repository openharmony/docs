# OH_NN_QuantParam
<!--Kit: Neural Network Runtime Kit-->
<!--Subsystem: AI-->
<!--Owner: @GbuzhidaoR-->
<!--Designer: @GbuzhidaoR-->
<!--Tester: @GbuzhidaoR-->
<!--Adviser: @ge-yafang-->

## 概述

量化信息。

在量化的场景中，32位浮点型数据根据以下公式量化为定点数据：

![zh-cn_formulaimage_0000001405137102](figures/zh-cn_formulaimage_0000001405137102.png)

其中s和z是量化参数，在OH_NN_QuanParam中通过scale和zeroPoint保存，r是浮点数，q是量化后的结果，q_min是量化后下界，q_max是量化后的上界，计算方式如下：

![zh-cn_formulaimage_0000001459019845](figures/zh-cn_formulaimage_0000001459019845.png)

![zh-cn_formulaimage_0000001408820090](figures/zh-cn_formulaimage_0000001408820090.png)

clamp函数定义如下：

![zh-cn_formulaimage_0000001455538697](figures/zh-cn_formulaimage_0000001455538697.png)

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


