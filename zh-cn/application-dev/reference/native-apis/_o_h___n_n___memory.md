# OH_NN_Memory


## 概述

内存结构体。

**起始版本：**

9

**相关模块：**

[NeuralNeworkRuntime](_neural_nework_runtime.md)


## 汇总


### 成员变量

| 成员变量名称 | 描述 | 
| -------- | -------- |
| [data](#data) | 指向共享内存的指针，该共享内存通常由底层硬件驱动申请。 | 
| [length](#length) | 记录共享内存的字节长度。 | 


## 结构体成员变量说明


### data

  
```
void* const OH_NN_Memory::data
```

**描述：**

指向共享内存的指针，该共享内存通常由底层硬件驱动申请。


### length

  
```
const size_t OH_NN_Memory::length
```

**描述：**

记录共享内存的字节长度。
