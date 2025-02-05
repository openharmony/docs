# oh_data_value.h


## 概述

提供与单条数据值相关的函数和枚举。

**引用文件：** &lt;database/rdb/oh_data_value.h&gt;

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 16

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_ColumnType](_r_d_b.md#oh_columntype) [OH_ColumnType](_r_d_b.md#oh_columntype) | 表示列的类型。 | 
| typedef struct [OH_Data_Value](_r_d_b.md#oh_data_value) [OH_Data_Value](_r_d_b.md#oh_data_value) | 定义[OH_Data_Value](_r_d_b.md#oh_data_value)结构类型。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_ColumnType](_r_d_b.md#oh_columntype-1) {<br/>TYPE_NULL = 0, TYPE_INT64, TYPE_REAL, TYPE_TEXT,<br/>TYPE_BLOB, TYPE_ASSET, TYPE_ASSETS, TYPE_FLOAT_VECTOR,<br/>TYPE_UNLIMITED_INT<br/>} | 表示列的类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Data_Value](_r_d_b.md#oh_data_value) \* [OH_Value_Create](_r_d_b.md#oh_value_create) (void) | 创建[OH_Data_Value](_r_d_b.md#oh_data_value)实例，用于储存单条键值对数据。 | 
| int [OH_Value_Destroy](_r_d_b.md#oh_value_destroy) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value) | 销毁[OH_Data_Value](_r_d_b.md#oh_data_value)对象。 | 
| int [OH_Value_PutNull](_r_d_b.md#oh_value_putnull) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value) | 添加空数据。 | 
| int [OH_Value_PutInt](_r_d_b.md#oh_value_putint) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, int64_t val) | 添加整型数据。 | 
| int [OH_Value_PutReal](_r_d_b.md#oh_value_putreal) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, double val) | 添加REAL类型数据。 | 
| int [OH_Value_PutText](_r_d_b.md#oh_value_puttext) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const char \*val) | 添加字符串类型数据。 | 
| int [OH_Value_PutBlob](_r_d_b.md#oh_value_putblob) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const unsigned char \*val, size_t length) | 添加BLOB类型数据。 | 
| int [OH_Value_PutAsset](_r_d_b.md#oh_value_putasset) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const Data_Asset \*val) | 添加ASSET类型数据。 | 
| int [OH_Value_PutAssets](_r_d_b.md#oh_value_putassets) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const Data_Asset \*const \*val, size_t length) | 添加ASSETS类型数据。 | 
| int [OH_Value_PutFloatVector](_r_d_b.md#oh_value_putfloatvector) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const float \*val, size_t length) | 添加float数组类型数据。 | 
| int [OH_Value_PutUnlimitedInt](_r_d_b.md#oh_value_putunlimitedint) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, int sign, const uint64_t \*trueForm, size_t length) | 添加任意长度的整型数组数据。 | 
| int [OH_Value_GetType](_r_d_b.md#oh_value_gettype) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, [OH_ColumnType](_r_d_b.md#oh_columntype) \*type) | 获取数据类型。 | 
| int [OH_Value_IsNull](_r_d_b.md#oh_value_isnull) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, bool \*val) | 检查数据是否为空。 | 
| int [OH_Value_GetInt](_r_d_b.md#oh_value_getint) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, int64_t \*val) | 获取整型数据。 | 
| int [OH_Value_GetReal](_r_d_b.md#oh_value_getreal) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, double \*val) | 获取REAL类型数据。 | 
| int [OH_Value_GetText](_r_d_b.md#oh_value_gettext) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const char \*\*val) | 获取字符串类型数据。 | 
| int [OH_Value_GetBlob](_r_d_b.md#oh_value_getblob) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const uint8_t \*\*val, size_t \*length) | 获取BLOB类型数据。 | 
| int [OH_Value_GetAsset](_r_d_b.md#oh_value_getasset) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, Data_Asset \*val) | 获取ASSET类型数据。 | 
| int [OH_Value_GetAssetsCount](_r_d_b.md#oh_value_getassetscount) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, size_t \*length) | 获取ASSETS类型数据的大小。 | 
| int [OH_Value_GetAssets](_r_d_b.md#oh_value_getassets) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, Data_Asset \*\*val, size_t inLen, size_t \*outLen) | 获取ASSETS类型数据。 | 
| int [OH_Value_GetFloatVectorCount](_r_d_b.md#oh_value_getfloatvectorcount) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, size_t \*length) | 获取float数组类型数据的大小。 | 
| int [OH_Value_GetFloatVector](_r_d_b.md#oh_value_getfloatvector) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, float \*val, size_t inLen, size_t \*outLen) | 获取float数组类型数据。 | 
| int [OH_Value_GetUnlimitedIntBand](_r_d_b.md#oh_value_getunlimitedintband) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, size_t \*length) | 获取任意长度的整型数据的大小。 | 
| int [OH_Value_GetUnlimitedInt](_r_d_b.md#oh_value_getunlimitedint) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, int \*sign, uint64_t \*trueForm, size_t inLen, size_t \*outLen) | 获取任意长度的整型数据。 | 
