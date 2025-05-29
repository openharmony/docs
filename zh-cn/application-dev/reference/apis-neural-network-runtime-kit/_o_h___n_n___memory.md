# OH_NN_Memory


## 概述

内存结构体。

**起始版本：** 9

**弃用：** 从API version 11开始，此接口废弃。

**替代：** 推荐使用[NN_Tensor](_neural_network_runtime.md#nn_tensor)。

**相关模块：**[NeuralNetworkRuntime](_neural_network_runtime.md)

**所在头文件：**[neural_network_runtime_type.h](neural__network__runtime__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| void \*const [data](#data) | 指向共享内存的指针，该共享内存通常由底层硬件驱动申请。 | 
| const size_t [length](#length) | 记录共享内存的字节长度。 | 


## 结构体成员变量说明


### data

```
void* const OH_NN_Memory::data
```

**描述**

指向共享内存的指针，该共享内存通常由底层硬件驱动申请。


### length

```
const size_t OH_NN_Memory::length
```

**描述**

记录共享内存的字节长度。
