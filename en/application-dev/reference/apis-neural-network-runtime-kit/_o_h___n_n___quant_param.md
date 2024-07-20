# OH_NN_QuantParam


## Overview

Defines the quantization information.

In quantization scenarios, the 32-bit floating-point data type is quantized into the fixed-point data type according to the following formula:

![zh-cn_formulaimage_0000001405137102](figures/zh-cn_formulaimage_0000001405137102.png)

where, **s** and **z** are quantization parameters, which are stored by **scale** and **zeroPoint** in OH_NN_QuanParam. **r** is a floating point number, **q** is the quantization result, **q_min** is the lower bound of the quantization result, and **q_max** is the upper bound of the quantization result. The calculation method is as follows:

![zh-cn_formulaimage_0000001459019845](figures/zh-cn_formulaimage_0000001459019845.png)

![zh-cn_formulaimage_0000001408820090](figures/zh-cn_formulaimage_0000001408820090.png)

The **clamp** function is defined as follows:

![zh-cn_formulaimage_0000001455538697](figures/zh-cn_formulaimage_0000001455538697.png)

**Since**: 9

**Deprecated**: This module is deprecated since API version 11.

**Substitute**: You are advised to use [NN_QuantParam](_neural_network_runtime.md#nn_quantparam).

**Related module**: [NeuralNetworkRuntime](_neural_network_runtime.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [quantCount](#quantcount) | Length of the numBits, scale, and zeroPoint arrays. In the per-layer quantization scenario, **quantCount** is usually set to **1**. That is, all channels of a tensor share a set of quantization parameters. In the per-channel quantization scenario, **quantCount** is usually the same as the number of tensor channels, and each channel uses its own quantization parameters.| 
| const uint32_t \* [numBits](#numbits) | Number of quantization bits.| 
| const double \* [scale](#scale) | Pointer to the scale data in the quantization formula.| 
| const int32_t \* [zeroPoint](#zeropoint) | Pointer to the zero point data in the quantization formula.| 


## Member Variable Description


### numBits

```
const uint32_t* OH_NN_QuantParam::numBits
```

**Description**

Number of quantization bits.


### quantCount

```
uint32_t OH_NN_QuantParam::quantCount
```

**Description**

Length of the numBits, scale, and zeroPoint arrays. In the per-layer quantization scenario, **quantCount** is usually set to **1**. That is, all channels of a tensor share a set of quantization parameters. In the per-channel quantization scenario, **quantCount** is usually the same as the number of tensor channels, and each channel uses its own quantization parameters.


### scale

```
const double* OH_NN_QuantParam::scale
```

**Description**

Pointer to the scale data in the quantization formula.


### zeroPoint

```
const int32_t* OH_NN_QuantParam::zeroPoint
```

**Description**

Pointer to the zero point data in the quantization formula.
