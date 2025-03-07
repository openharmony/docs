# Tensor


## 概述

张量结构体。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [name](#name) | 张量名称。  | 
| enum [DataType](_n_n_rt_v10.md#datatype)[dataType](#datatype) | 张量数据类型，详情请参考：[DataType](_n_n_rt_v10.md#datatype)。  | 
| int[] [dims](#dims) | 张量维度数组。  | 
| enum [Format](_n_n_rt_v10.md#format)[format](#format) | 张量数据的排列，详情请参考：[Format](_n_n_rt_v10.md#format)。  | 
| struct [SharedBuffer](_shared_buffer_v10.md)[data](#data) | 进程通信时用于张量数据传输的结构体，详情请参考：[SharedBuffer](_shared_buffer_v10.md)。  | 
| struct [QuantParam](_quant_param_v10.md)[] [quantParams](#quantparams) | 张量的量化参数数组。详情请参考：[QuantParam](_quant_param_v10.md)。 | 


## 类成员变量说明


### data

```
struct SharedBuffer Tensor::data
```
**描述**

进程通信时用于张量数据传输的结构体，详情请参考：[SharedBuffer](_shared_buffer_v10.md)。


### dataType

```
enum DataType Tensor::dataType
```
**描述**

张量数据类型，详情请参考：[DataType](_n_n_rt_v10.md#datatype)。


### dims

```
int [] Tensor::dims
```
**描述**

张量维度数组。


### format

```
enum Format Tensor::format
```
**描述**

张量数据的排列，详情请参考：[Format](_n_n_rt_v10.md#format)。


### name

```
String Tensor::name
```
**描述**

张量名称。


### quantParams

```
struct QuantParam [] Tensor::quantParams
```
**描述**

张量的量化参数数组。详情请参考：[QuantParam](_quant_param_v10.md)。

分为两种情况，如果长度为一，则所有轴公用一个量化； 若长度不为一，则数组中的每一个量化参数和轴一一对应。
