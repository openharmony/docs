# OH_VBucket


## 概述

用于存储键值对的类型。

**起始版本：** 10

**相关模块：**[RDB](_r_d_b.md)

**所在头文件：**[oh_values_bucket.h](oh__values__bucket_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [id](_r_d_b.md#id-45) | OH_VBucket结构体的唯一标识符。 |
| [capability](_r_d_b.md#capability) | 表示结构体的存储键值对的数量。 |
| [putText](_r_d_b.md#puttext-12) | 将char\*值放入给定列名的OH_VBucket对象中。 |
| [putInt64](_r_d_b.md#putint64-12) | 将int64_t值放入给定列名的OH_VBucket对象中。 |
| [putReal](_r_d_b.md#putreal) | 将double值放入给定列名的OH_VBucket对象中。 |
| [putBlob](_r_d_b.md#putblob) | 将const uint8_t \*值放入给定列名的OH_VBucket对象中。 |
| [putNull](_r_d_b.md#putnull) | 将NULL值放入给定列名的OH_VBucket对象中。 |
| [clear](_r_d_b.md#clear-22) | 清空OH_VBucket对象。 |
| [destroy](_r_d_b.md#destroy-34) | 销毁OH_VBucket对象，并回收该对象占用的内存。 |
