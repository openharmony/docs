# oh_data_value.h


## Overview

Defines APIs and enums related to a single data value.

**File to include**: &lt;database/data/oh_data_value.h&gt;

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 16

**Related module**: [RDB](_r_d_b.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_ColumnType](_r_d_b.md#oh_columntype) [OH_ColumnType](_r_d_b.md#oh_columntype) | Defines an enum for column types.| 
| typedef struct [OH_Data_Value](_r_d_b.md#oh_data_value) [OH_Data_Value](_r_d_b.md#oh_data_value) | Defines the [OH_Data_Value](_r_d_b.md#oh_data_value) struct.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_ColumnType](_r_d_b.md#oh_columntype-1) {<br>TYPE_NULL = 0, TYPE_INT64, TYPE_REAL, TYPE_TEXT,<br>TYPE_BLOB, TYPE_ASSET, TYPE_ASSETS, TYPE_FLOAT_VECTOR,<br>TYPE_UNLIMITED_INT<br>} | Enumerates the column types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Data_Value](_r_d_b.md#oh_data_value) \* [OH_Value_Create](_r_d_b.md#oh_value_create) (void) | Creates an [OH_Data_Value](_r_d_b.md#oh_data_value) instance to store a single KV pair.| 
| int [OH_Value_Destroy](_r_d_b.md#oh_value_destroy) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value) | Destroys an [OH_Data_Value](_r_d_b.md#oh_data_value) instance.| 
| int [OH_Value_PutNull](_r_d_b.md#oh_value_putnull) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value) | Adds empty data.| 
| int [OH_Value_PutInt](_r_d_b.md#oh_value_putint) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, int64_t val) | Adds integer data.| 
| int [OH_Value_PutReal](_r_d_b.md#oh_value_putreal) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, double val) | Adds data of the REAL type.| 
| int [OH_Value_PutText](_r_d_b.md#oh_value_puttext) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const char \*val) | Adds data of the string type.| 
| int [OH_Value_PutBlob](_r_d_b.md#oh_value_putblob) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const unsigned char \*val, size_t length) | Adds data of the BLOB type.| 
| int [OH_Value_PutAsset](_r_d_b.md#oh_value_putasset) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const Data_Asset \*val) | Adds data of the ASSET type.| 
| int [OH_Value_PutAssets](_r_d_b.md#oh_value_putassets) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const Data_Asset \*const \*val, size_t length) | Adds data of the ASSETS type.| 
| int [OH_Value_PutFloatVector](_r_d_b.md#oh_value_putfloatvector) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const float \*val, size_t length) | Adds data of the floating-point array type.| 
| int [OH_Value_PutUnlimitedInt](_r_d_b.md#oh_value_putunlimitedint) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, int sign, const uint64_t \*trueForm, size_t length) | Adds an integer array of any length.| 
| int [OH_Value_GetType](_r_d_b.md#oh_value_gettype) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, [OH_ColumnType](_r_d_b.md#oh_columntype) \*type) | Obtains the data type.| 
| int [OH_Value_IsNull](_r_d_b.md#oh_value_isnull) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, bool \*val) | Checks whether a value is null.| 
| int [OH_Value_GetInt](_r_d_b.md#oh_value_getint) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, int64_t \*val) | Obtains integer data.| 
| int [OH_Value_GetReal](_r_d_b.md#oh_value_getreal) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, double \*val) | Obtains data of the REAL type.| 
| int [OH_Value_GetText](_r_d_b.md#oh_value_gettext) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const char \*\*val) | Obtains data of the string type.| 
| int [OH_Value_GetBlob](_r_d_b.md#oh_value_getblob) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, const uint8_t \*\*val, size_t \*length) | Obtains data of the BLOB type.| 
| int [OH_Value_GetAsset](_r_d_b.md#oh_value_getasset) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, Data_Asset \*val) | Obtains data of the ASSET type.| 
| int [OH_Value_GetAssetsCount](_r_d_b.md#oh_value_getassetscount) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, size_t \*length) | Obtains the length of ASSETS data.| 
| int [OH_Value_GetAssets](_r_d_b.md#oh_value_getassets) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, Data_Asset \*\*val, size_t inLen, size_t \*outLen) | Obtains data of the ASSETS type.| 
| int [OH_Value_GetFloatVectorCount](_r_d_b.md#oh_value_getfloatvectorcount) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, size_t \*length) | Obtains the length of a floating-point array.| 
| int [OH_Value_GetFloatVector](_r_d_b.md#oh_value_getfloatvector) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, float \*val, size_t inLen, size_t \*outLen) | Obtains data of the floating-point array type.| 
| int [OH_Value_GetUnlimitedIntBand](_r_d_b.md#oh_value_getunlimitedintband) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, size_t \*length) | Obtains the length of an integer of any length.| 
| int [OH_Value_GetUnlimitedInt](_r_d_b.md#oh_value_getunlimitedint) ([OH_Data_Value](_r_d_b.md#oh_data_value) \*value, int \*sign, uint64_t \*trueForm, size_t inLen, size_t \*outLen) | Obtains integer data of any length.| 
