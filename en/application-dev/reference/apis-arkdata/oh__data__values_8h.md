# oh_data_values.h


## Overview

Defines APIs and enums related to multiple data values.

**File to include**: &lt;database/rdb/oh_data_values.h&gt;

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 16

**Related module**: [RDB](_r_d_b.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Data_Values](_r_d_b.md#oh_data_values) [OH_Data_Values](_r_d_b.md#oh_data_values) | Defines the [OH_Data_Values](_r_d_b.md#oh_data_values) struct.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Data_Values](_r_d_b.md#oh_data_values) \* [OH_Values_Create](_r_d_b.md#oh_values_create) (void) | Creates an [OH_Data_Values](_r_d_b.md#oh_data_values) instance to store multiple KV pairs.| 
| int [OH_Values_Destroy](_r_d_b.md#oh_values_destroy) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values) | Destroys an [OH_Data_Values](_r_d_b.md#oh_data_values) instance.| 
| int [OH_Values_Put](_r_d_b.md#oh_values_put) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const [OH_Data_Value](_r_d_b.md#oh_data_value) \*val) | Adds data of the **OH_Data_Value** type to an **OH_Data_Values** instance.| 
| int [OH_Values_PutNull](_r_d_b.md#oh_values_putnull) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values) | Adds empty data to an **OH_Data_Values** instance.| 
| int [OH_Values_PutInt](_r_d_b.md#oh_values_putint) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int64_t val) | Adds integer data to an **OH_Data_Values** instance.| 
| int [OH_Values_PutReal](_r_d_b.md#oh_values_putreal) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, double val) | Adds data of the REAL type to an **OH_Data_Values** instance.| 
| int [OH_Values_PutText](_r_d_b.md#oh_values_puttext) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const char \*val) | Adds data of the string type to an **OH_Data_Values** instance.| 
| int [OH_Values_PutBlob](_r_d_b.md#oh_values_putblob) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const unsigned char \*val, size_t length) | Adds data of the BLOB type to an **OH_Data_Values** instance.| 
| int [OH_Values_PutAsset](_r_d_b.md#oh_values_putasset) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const Data_Asset \*val) | Adds data of the ASSET type to an **OH_Data_Values** instance.| 
| int [OH_Values_PutAssets](_r_d_b.md#oh_values_putassets) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const Data_Asset \*const \*val, size_t length) | Adds data of the ASSETS type to an **OH_Data_Values** instance.| 
| int [OH_Values_PutFloatVector](_r_d_b.md#oh_values_putfloatvector) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, const float \*val, size_t length) | Adds data of the float array type to an **OH_Data_Values** instance.| 
| int [OH_Values_PutUnlimitedInt](_r_d_b.md#oh_values_putunlimitedint) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int sign, const uint64_t \*trueForm, size_t length) | Adds an integer array of any length to an **OH_Data_Values** instance.| 
| int [OH_Values_Count](_r_d_b.md#oh_values_count) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, size_t \*count) | Obtains the number of values.| 
| int [OH_Values_GetType](_r_d_b.md#oh_values_gettype) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, [OH_ColumnType](_r_d_b.md#oh_columntype) \*type) | Obtains the data type.| 
| int [OH_Values_Get](_r_d_b.md#oh_values_get) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, [OH_Data_Value](_r_d_b.md#oh_data_value) \*\*val) | Obtains data of the **OH_Data_Value** type.| 
| int [OH_Values_IsNull](_r_d_b.md#oh_values_isnull) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, bool \*val) | Checks whether a value is null.| 
| int [OH_Values_GetInt](_r_d_b.md#oh_values_getint) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, int64_t \*val) | Obtains integer data.| 
| int [OH_Values_GetReal](_r_d_b.md#oh_values_getreal) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, double \*val) | Obtains data of the REAL type.| 
| int [OH_Values_GetText](_r_d_b.md#oh_values_gettext) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, const char \*\*val) | Obtains data of the string type.| 
| int [OH_Values_GetBlob](_r_d_b.md#oh_values_getblob) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, const uint8_t \*\*val, size_t \*length) | Obtains data of the BLOB type.| 
| int [OH_Values_GetAsset](_r_d_b.md#oh_values_getasset) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, Data_Asset \*val) | Obtains data of the ASSET type.| 
| int [OH_Values_GetAssetsCount](_r_d_b.md#oh_values_getassetscount) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, size_t \*length) | Obtains the length of ASSETS data.| 
| int [OH_Values_GetAssets](_r_d_b.md#oh_values_getassets) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, Data_Asset \*\*val, size_t inLen, size_t \*outLen) | Obtains data of the ASSETS type.| 
| int [OH_Values_GetFloatVectorCount](_r_d_b.md#oh_values_getfloatvectorcount) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, size_t \*length) | Obtains the length of a floating-point array.| 
| int [OH_Values_GetFloatVector](_r_d_b.md#oh_values_getfloatvector) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, float \*val, size_t inLen, size_t \*outLen) | Obtains data of the floating-point array type.| 
| int [OH_Values_GetUnlimitedIntBand](_r_d_b.md#oh_values_getunlimitedintband) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, size_t \*length) | Obtains the length of an integer of any length.| 
| int [OH_Values_GetUnlimitedInt](_r_d_b.md#oh_values_getunlimitedint) ([OH_Data_Values](_r_d_b.md#oh_data_values) \*values, int index, int \*sign, uint64_t \*trueForm, size_t inLen, size_t \*outLen) | Obtains integer data of any length.| 
