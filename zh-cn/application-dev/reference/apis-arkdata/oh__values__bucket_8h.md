# oh_values_bucket.h


## 概述

用于存储键值对的类型。

**引用文件：** <database/rdb/oh_values_bucket.h>

**库：** libnative_rdb_ndk.z.so

**起始版本：** 10

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_VBucket](_o_h___v_bucket.md) | 用于存储键值对的类型。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_VBucket](_r_d_b.md#oh_vbucket) | 用于存储键值对的类型。 |
### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [OH_VBucket_PutAsset](_r_d_b.md#oh_vbucket_putasset) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*value) | 将**OH_Asset** 类型的对象放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 | 
| int [OH_VBucket_PutAssets](_r_d_b.md#oh_vbucket_putassets) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*\*value, int count) | 将**OH_Asset** 类型的对象数组放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 | 
