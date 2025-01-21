# oh_values_bucket.h


## Overview

Defines the types of the key and value in a key-value (KV) pair.

**File to include**: <database/rdb/oh_values_bucket.h>

**Library**: libnative_rdb_ndk.z.so

**Since**: 10

**Related module**: [RDB](_r_d_b.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [OH_VBucket](_o_h___v_bucket.md) | Defines the types of the key and value in a KV pair.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_VBucket](_r_d_b.md#oh_vbucket) | Defines the types of the key and value in a KV pair.|
### Functions

| Name| Description| 
| -------- | -------- |
| int [OH_VBucket_PutAsset](_r_d_b.md#oh_vbucket_putasset) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*value) | Puts an **OH_Asset** object into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.| 
| int [OH_VBucket_PutAssets](_r_d_b.md#oh_vbucket_putassets) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*\*value, int count) | Puts an array of **OH_Asset** objects into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.| 
| int [OH_VBucket_PutFloatVector](_r_d_b.md#oh_vbucket_putfloatvector) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, const float \*vec, size_t len) | Puts a floating-point array into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.| 
| int [OH_VBucket_PutUnlimitedInt](_r_d_b.md#oh_vbucket_putunlimitedint) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, int sign, const uint64_t \*trueForm, size_t len) | Puts an integer of any length into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.| 
