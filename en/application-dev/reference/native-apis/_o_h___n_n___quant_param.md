# OH_NN_QuantParam


## Overview

Quantization information.

In quantization scenarios, the 32-bit floating-point data type is quantized into the fixed-point data type according to the following formula:

s and z are quantization parameters, which are stored by **scale** and **zeroPoint** in OH_NN_QuantParam. r is a floating point number, q is the quantization result, q_min is the lower bound of the quantization result, and q_max is an upper bound of a quantization result. The calculation method is as follows:

The clamp function is defined as follows:

**Since:**
9

**Related Modules:**

[NeuralNeworkRuntime](_neural_nework_runtime.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [quantCount](#quantcount) | Specifies the length of the numBits, scale, and zeroPoint arrays. In the per-layer quantization scenario, **quantCount** is usually set to **1**. That is, all channels of a tensor share a set of quantization parameters. In the per-channel quantization scenario, **quantCount** is usually the same as the number of tensor channels, and each channel uses its own quantization parameters.  | 
| [numBits](#numbits) | Number of quantization bits  | 
| [scale](#scale) | Pointer to the scale data in the quantization formula  | 
| [zeroPoint](#zeropoint) | Pointer to the zero point data in the quantization formula  | 


## Member Variable Description 


### numBits

  
```
const uint32_t* OH_NN_QuantParam::numBits
```
**Description**<br>
Number of quantization bits


### quantCount

  
```
uint32_t OH_NN_QuantParam::quantCount
```
**Description**<br>
Specifies the length of the numBits, scale, and zeroPoint arrays. In the per-layer quantization scenario, **quantCount** is usually set to **1**. That is, all channels of a tensor share a set of quantization parameters. In the per-channel quantization scenario, **quantCount** is usually the same as the number of tensor channels, and each channel uses its own quantization parameters.


### scale

  
```
const double* OH_NN_QuantParam::scale
```
**Description**<br>
Pointer to the scale data in the quantization formula


### zeroPoint

  
```
const int32_t* OH_NN_QuantParam::zeroPoint
```
**Description**<br>
Pointer to the zero point data in the quantization formula
