# Tensor


## 概述

张量结构体。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [name](#name) | String<br/>张量名称。 | 
| [dataType](#datatype) | enum&nbsp;[DataType](_n_n_rt.md#datatype)<br/>张量数据类型，详情请参考：[DataType](_n_n_rt.md#datatype)。 | 
| [dims](#dims) | int[]<br/>张量维度数组。 | 
| [format](#format) | enum&nbsp;[Format](_n_n_rt.md#format)<br/>张量数据的排列，详情请参考：[Format](_n_n_rt.md#format)。 | 
| [data](#data) | struct&nbsp;[SharedBuffer](_shared_buffer.md)<br/>进程通信时用于张量数据传输的结构体，详情请参考：[SharedBuffer](_shared_buffer.md)。 | 
| [quantParams](#quantparams) | struct&nbsp;[QuantParam](_quant_param.md)[]<br/>张量的量化参数数组。详情请参考：[QuantParam](_quant_param.md)。 | 


## 类成员变量说明


### data

  
```
struct SharedBuffer Tensor::data
```

**描述:**

进程通信时用于张量数据传输的结构体，详情请参考：[SharedBuffer](_shared_buffer.md)。


### dataType

  
```
enum DataType Tensor::dataType
```

**描述:**

张量数据类型，详情请参考：[DataType](_n_n_rt.md#datatype)。


### dims

  
```
int [] Tensor::dims
```

**描述:**

张量维度数组。


### format

  
```
enum Format Tensor::format
```

**描述:**

张量数据的排列，详情请参考：[Format](_n_n_rt.md#format)。


### name

  
```
String Tensor::name
```

**描述:**

张量名称。


### quantParams

  
```
struct QuantParam [] Tensor::quantParams
```

**描述:**

张量的量化参数数组。详情请参考：[QuantParam](_quant_param.md)。

分为两种情况，如果长度为一，则所有轴公用一个量化； 若长度不为一，则数组中的每一个量化参数和轴一一对应。
