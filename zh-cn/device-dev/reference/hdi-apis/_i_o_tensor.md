# IOTensor


## 概述

AI模型的输入输出张量。

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
| [name](#name) | String<br/>张量的名称&nbsp; | 
| [dataType](#datatype) | enum&nbsp;[DataType](_n_n_rt.md#datatype)<br/>张量的数据类型,&nbsp;数据类型定义请查看[DataType](_n_n_rt.md#datatype) | 
| [dimensions](#dimensions) | int[]<br/>张量的形状&nbsp; | 
| [format](#format) | enum&nbsp;[Format](_n_n_rt.md#format)<br/>张量的数据排列格式，排列格式的定义请查看[Format](_n_n_rt.md#format) | 
| [data](#data) | struct&nbsp;[SharedBuffer](_shared_buffer.md)<br/>张量的数据，数据保存在共享内存中，共享内存的定义请查看[SharedBuffer](_shared_buffer.md) | 


## 类成员变量说明


### data

  
```
struct SharedBuffer IOTensor::data
```
**描述:**
张量的数据，数据保存在共享内存中，共享内存的定义请查看[SharedBuffer](_shared_buffer.md)


### dataType

  
```
enum DataType IOTensor::dataType
```
**描述:**
张量的数据类型, 数据类型定义请查看[DataType](_n_n_rt.md#datatype)


### dimensions

  
```
int [] IOTensor::dimensions
```
**描述:**
张量的形状


### format

  
```
enum Format IOTensor::format
```
**描述:**
张量的数据排列格式，排列格式的定义请查看[Format](_n_n_rt.md#format)


### name

  
```
String IOTensor::name
```
**描述:**
张量的名称
