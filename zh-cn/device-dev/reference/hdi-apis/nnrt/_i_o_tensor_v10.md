# IOTensor


## 概述

AI模型的输入输出张量。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [name](#name) | 张量的名称  | 
| enum [DataType](_n_n_rt_v10.md#datatype)[dataType](#datatype) | 张量的数据类型, 数据类型定义请查看[DataType](_n_n_rt_v10.md#datatype) | 
| int[] [dimensions](#dimensions) | 张量的形状  | 
| enum [Format](_n_n_rt_v10.md#format)[format](#format) | 张量的数据排列格式，排列格式的定义请查看[Format](_n_n_rt_v10.md#format) | 
| struct [SharedBuffer](_shared_buffer_v10.md)[data](#data) | 张量的数据，数据保存在共享内存中，共享内存的定义请查看[SharedBuffer](_shared_buffer_v10.md) | 


## 类成员变量说明


### data

```
struct SharedBuffer IOTensor::data
```
**描述**

张量的数据，数据保存在共享内存中，共享内存的定义请查看[SharedBuffer](_shared_buffer_v10.md)


### dataType

```
enum DataType IOTensor::dataType
```
**描述**

张量的数据类型, 数据类型定义请查看[DataType](_n_n_rt_v10.md#datatype)


### dimensions

```
int [] IOTensor::dimensions
```
**描述**

张量的形状


### format

```
enum Format IOTensor::format
```
**描述**

张量的数据排列格式，排列格式的定义请查看[Format](_n_n_rt_v10.md#format)


### name

```
String IOTensor::name
```
**描述**

张量的名称
