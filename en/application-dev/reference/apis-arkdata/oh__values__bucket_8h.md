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
| [OH_VBucket](_r_d_b.md#oh_vbucket) | Indicates the types of the key and value in a KV pair. |
### Functions

| Name| Description| 
| -------- | -------- |
| int [OH_VBucket_PutAsset](_r_d_b.md#oh_vbucket_putasset) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*value) | Puts an **OH_Asset** object into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.| 
| int [OH_VBucket_PutAssets](_r_d_b.md#oh_vbucket_putassets) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*\*value, int count) | Puts an array of **OH_Asset** objects into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.| 
