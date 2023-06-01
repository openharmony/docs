# OH_VBucket


## 概述

用于存储键值对的类型。

**起始版本：**

10

**相关模块：**

[RDB](_r_d_b.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [id](_r_d_b.md#id-34) | OH_VBucket结构体的唯一标识符。 |
| [capability](_r_d_b.md#capability) | 表示结构体的存储键值对的数量。 |
| [putText](_r_d_b.md#puttext-12) | 将const&nbsp;char\*值放入给定列名的[OH_VBucket](zh-cn_topic_0000001564188350.xml)对象中。 |
| [putInt64](_r_d_b.md#putint64-12) | 将int64_t值放入给定列名的[OH_VBucket](zh-cn_topic_0000001564188350.xml)对象中。 |
| [putReal](_r_d_b.md#putreal) | 将double值放入给定列名的[OH_VBucket](zh-cn_topic_0000001564188350.xml)对象中**。** |
| [putBlob](_r_d_b.md#putblob) | 将const&nbsp;uint8_t&nbsp;\*值放入给定列名的[OH_VBucket](zh-cn_topic_0000001564188350.xml)对象中。 |
| [putNull](_r_d_b.md#putnull) | 将NULL值放入给定列名的[OH_VBucket](zh-cn_topic_0000001564188350.xml)对象中。 |
| [clear](_r_d_b.md#clear-22) | 清空[OH_VBucket](zh-cn_topic_0000001564188350.xml)对象。 |
| [destroyValuesBucket](_r_d_b.md#destroyvaluesbucket) | 销毁[OH_VBucket](zh-cn_topic_0000001564188350.xml)对象，并回收该对象占用的内存。 |
