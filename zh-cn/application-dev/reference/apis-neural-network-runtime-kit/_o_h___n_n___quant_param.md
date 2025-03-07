# OH_NN_QuantParam


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

**弃用：** 从API version 11开始，此接口废弃。

**替代：** 推荐使用[NN_QuantParam](_neural_network_runtime.md#nn_quantparam)。

**相关模块：** [NeuralNeworkRuntime](_neural_network_runtime.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [quantCount](#quantcount) | 指定numBits、scale和zeroPoint数组的长度。在per-layer量化的场景下，quantCount通常指定为1，即一个张量所有通道 共享一套量化参数；在per-channel量化场景下，quantCount通常和张量通道数一致，每个通道使用自己的量化参数。 | 
| const uint32_t \* [numBits](#numbits) | 量化位数 | 
| const double \* [scale](#scale) | 指向量化公式中scale数据的指针 | 
| const int32_t \* [zeroPoint](#zeropoint) | 指向量化公式中zero point数据的指针 | 


## 结构体成员变量说明


### numBits

```
const uint32_t* OH_NN_QuantParam::numBits
```

**描述**

量化位数


### quantCount

```
uint32_t OH_NN_QuantParam::quantCount
```

**描述**

指定numBits、scale和zeroPoint数组的长度。在per-layer量化的场景下，quantCount通常指定为1，即一个张量所有通道 共享一套量化参数；在per-channel量化场景下，quantCount通常和张量通道数一致，每个通道使用自己的量化参数。


### scale

```
const double* OH_NN_QuantParam::scale
```

**描述**

指向量化公式中scale数据的指针


### zeroPoint

```
const int32_t* OH_NN_QuantParam::zeroPoint
```

**描述**

指向量化公式中zero point数据的指针