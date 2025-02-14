# oh_data_values_buckets.h


## Overview

Defines structs, APIs, and enums related to stored data values.

**File to include**: &lt;database/rdb/oh_data_values_buckets.h&gt;

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 16

**Related module**: [RDB](_r_d_b.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) | Defines the **OH_Data_VBuckets** struct.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \* [OH_VBuckets_Create](_r_d_b.md#oh_vbuckets_create) (void) | Create an **OH_Data_VBuckets** instance.| 
| int [OH_VBuckets_Destroy](_r_d_b.md#oh_vbuckets_destroy) ([OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*buckets) | Destroys an **OH_Data_VBuckets** instance.| 
| int [OH_VBuckets_PutRow](_r_d_b.md#oh_vbuckets_putrow) ([OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*buckets, const [OH_VBucket](_o_h___v_bucket.md) \*row) | Adds data of the **OH_VBucket** type.| 
| int [OH_VBuckets_PutRows](_r_d_b.md#oh_vbuckets_putrows) ([OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*buckets, const [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*rows) | Adds data of the **OH_Data_VBuckets** type.| 
| int [OH_VBuckets_RowCount](_r_d_b.md#oh_vbuckets_rowcount) ([OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*buckets, size_t \*count) | Obtains the number of rows in **OH_VBucket** in **OH_Data_VBuckets**.| 
