# oh_data_values.h


## 概述

提供与多条数据值相关的函数和枚举。

**引用文件：** &lt;database/rdb/oh_data_values.h&gt;

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 16

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Data_Values](_r_d_b.md#oh_data_values) [OH_Data_Values](_r_d_b.md#oh_data_values) | 定义[OH_Data_Values](_r_d_b.md#oh_data_values)结构类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Data_Values](_r_d_b.md#oh_data_values) \* [OH_Values_Create](_r_d_b.md#oh_values_create) (void) | 创建[OH_Data_Values](_r_d_b.md#oh_data_values)实例，用于储存多条键值对数据。 | 
| int [OH_Values_Destroy](_r_d_b.md#oh_values_destroy) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values) | 销毁[OH_Data_Values](_r_d_b.md#oh_data_values)对象。 | 
| int [OH_Values_Put](_r_d_b.md#oh_values_put) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const [OH_Data_Value](_r_d_b.md#oh_data_value) \*val) | 添加OH_Data_Value类型数据给OH_Data_Values对象。 | 
| int [OH_Values_PutNull](_r_d_b.md#oh_values_putnull) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values) | 添加空数据给OH_Data_Values对象。 | 
| int [OH_Values_PutInt](_r_d_b.md#oh_values_putint) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int64_t val) | 添加整型数据给OH_Data_Values对象。 | 
| int [OH_Values_PutReal](_r_d_b.md#oh_values_putreal) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, double val) | 添加REAL类型数据给OH_Data_Values对象。 | 
| int [OH_Values_PutText](_r_d_b.md#oh_values_puttext) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const char \*val) | 添加字符串类型数据给OH_Data_Values对象。 | 
| int [OH_Values_PutBlob](_r_d_b.md#oh_values_putblob) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const unsigned char \*val, size_t length) | 添加BLOB类型数据给OH_Data_Values对象。 | 
| int [OH_Values_PutAsset](_r_d_b.md#oh_values_putasset) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const Data_Asset \*val) | 添加ASSET类型数据给OH_Data_Values对象。 | 
| int [OH_Values_PutAssets](_r_d_b.md#oh_values_putassets) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const Data_Asset \*const \*val, size_t length) | 添加ASSETS类型数据给OH_Data_Values对象。 | 
| int [OH_Values_PutFloatVector](_r_d_b.md#oh_values_putfloatvector) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const float \*val, size_t length) | 添加float数组类型数据给OH_Data_Values对象。 | 
| int [OH_Values_PutUnlimitedInt](_r_d_b.md#oh_values_putunlimitedint) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int sign, const uint64_t \*trueForm, size_t length) | 添加任意长度的整型数组数据给OH_Data_Values对象。 | 
| int [OH_Values_Count](_r_d_b.md#oh_values_count) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, size_t \*count) | 获取数据个数。 | 
| int [OH_Values_GetType](_r_d_b.md#oh_values_gettype) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, [OH_ColumnType](_r_d_b.md#oh_columntype) \*type) | 获取数据类型。 | 
| int [OH_Values_Get](_r_d_b.md#oh_values_get) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, [OH_Data_Value](_r_d_b.md#oh_data_value) \*\*val) | 获取OH_Data_Value类型数据。 | 
| int [OH_Values_IsNull](_r_d_b.md#oh_values_isnull) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, bool \*val) | 检查数据是否为空。 | 
| int [OH_Values_GetInt](_r_d_b.md#oh_values_getint) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, int64_t \*val) | 获取整型数据。 | 
| int [OH_Values_GetReal](_r_d_b.md#oh_values_getreal) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, double \*val) | 获取REAL类型数据。 | 
| int [OH_Values_GetText](_r_d_b.md#oh_values_gettext) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, const char \*\*val) | 获取字符串类型数据。 | 
| int [OH_Values_GetBlob](_r_d_b.md#oh_values_getblob) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, const uint8_t \*\*val, size_t \*length) | 获取BLOB类型数据。 | 
| int [OH_Values_GetAsset](_r_d_b.md#oh_values_getasset) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, Data_Asset \*val) | 获取ASSET类型数据。 | 
| int [OH_Values_GetAssetsCount](_r_d_b.md#oh_values_getassetscount) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, size_t \*length) | 获取ASSETS类型数据的大小。 | 
| int [OH_Values_GetAssets](_r_d_b.md#oh_values_getassets) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, Data_Asset \*\*val, size_t inLen, size_t \*outLen) | 获取ASSETS类型数据。 | 
| int [OH_Values_GetFloatVectorCount](_r_d_b.md#oh_values_getfloatvectorcount) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, size_t \*length) | 获取float数组类型数据的大小。 | 
| int [OH_Values_GetFloatVector](_r_d_b.md#oh_values_getfloatvector) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, float \*val, size_t inLen, size_t \*outLen) | 获取float数组类型数据。 | 
| int [OH_Values_GetUnlimitedIntBand](_r_d_b.md#oh_values_getunlimitedintband) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, size_t \*length) | 获取任意长度的整型数据的大小。 | 
| int [OH_Values_GetUnlimitedInt](_r_d_b.md#oh_values_getunlimitedint) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, int \*sign, uint64_t \*trueForm, size_t inLen, size_t \*outLen) | 获取任意长度的整型数据。 | 
