# oh_data_values_buckets.h


## 概述

提供与存储数据值相关的结构定义、函数和枚举。

**引用文件：**&lt;database/data/oh_data_values_buckets.h&gt;

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 16

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) | 定义OH_Data_VBuckets结构类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \* [OH_VBuckets_Create](_r_d_b.md#oh_vbuckets_create) (void) | 创建OH_Data_VBuckets实例。 | 
| int [OH_VBuckets_Destroy](_r_d_b.md#oh_vbuckets_destroy) ([OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*buckets) | 销毁OH_Data_VBuckets对象。 | 
| int [OH_VBuckets_PutRow](_r_d_b.md#oh_vbuckets_putrow) ([OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*buckets, const [OH_VBucket](_o_h___v_bucket.md) \*row) | 添加OH_VBucket类型数据。 | 
| int [OH_VBuckets_PutRows](_r_d_b.md#oh_vbuckets_putrows) ([OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*buckets, const [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*rows) | 添加OH_Data_VBuckets类型数据。 | 
| int [OH_VBuckets_RowCount](_r_d_b.md#oh_vbuckets_rowcount) ([OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*buckets, size_t \*count) | 获取OH_Data_VBuckets中OH_VBucket的行数。 | 
