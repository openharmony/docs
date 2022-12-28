# OH_NN_Tensor


## 概述

张量结构体。

通常用于构造模型图中的数据节点和算子参数，在构造张量时需要明确数据类型、维数、维度信息和量化信息。

**起始版本：**

9

**相关模块：**

[NeuralNeworkRuntime](_neural_nework_runtime.md)


## 汇总


### 成员变量

| 成员变量名称 | 描述 | 
| -------- | -------- |
| [dataType](#datatype) | 指定张量的数据类型，要求从[OH_NN_DataType](_neural_nework_runtime.md#ohnndatatype)枚举类型中取值。 | 
| [dimensionCount](#dimensioncount) | 指定张量的维数。 | 
| [dimensions](#dimensions) | 指定张量的维度信息（形状）。 | 
| [quantParam](#quantparam) | 指定张量的量化信息，数据类型要求为[OH_NN_QuantParam](_o_h___n_n___quant_param.md)。 | 
| [type](#type) | 指定张量的类型，type的取值和张量的用途相关。<br/>当张量作为模型的输入或输出，则要求type设置为OH_NN_TENSOR；<br/>当张量作为算子参数，则要求从[OH_NN_TensorType](_neural_nework_runtime.md#ohnntensortype)枚举类型中选择除OH_NN_TENSOR之外的合适的枚举值。 | 


## 结构体成员变量说明


### dataType

  
```
OH_NN_DataType OH_NN_Tensor::dataType
```

**描述：**

指定张量的数据类型，要求从[OH_NN_DataType](_neural_nework_runtime.md#oh_nn_datatype)枚举类型中取值。


### dimensionCount

  
```
uint32_t OH_NN_Tensor::dimensionCount
```

**描述：**

指定张量的维数。


### dimensions

  
```
const int32_t* OH_NN_Tensor::dimensions
```

**描述：**

指定张量的维度信息（形状）。


### quantParam

  
```
const OH_NN_QuantParam* OH_NN_Tensor::quantParam
```

**描述：**

指定张量的量化信息，数据类型要求为[OH_NN_QuantParam](_o_h___n_n___quant_param.md)。


### type

  
```
OH_NN_TensorType OH_NN_Tensor::type
```

**描述：**

指定张量的类型，type的取值和张量的用途相关。

当张量作为模型的输入或输出，则要求type设置为OH_NN_TENSOR；

当张量作为算子参数，则要求从[OH_NN_TensorType](_neural_nework_runtime.md#oh_nn_tensortype)枚举类型中选择除OH_NN_TENSOR之外的合适的枚举值。
