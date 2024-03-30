# OH_VBucket


## Overview

Defines the types of the key and value in a KV pair.

**Since**: 10

**Related module**: [RDB](_r_d_b.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [id](_r_d_b.md#id-45) | Unique identifier of the **OH_VBucket** struct.|
| [capability](_r_d_b.md#capability) | Number of the KV pairs in the struct.|
| [putText](_r_d_b.md#puttext-12) | Puts a char value into the **OH_VBucket** object in the given column.|
| [putInt64](_r_d_b.md#putint64-12) | Puts an int64_t value into the **OH_VBucket** object in the given column.|
| [putReal](_r_d_b.md#putreal) | Puts a double value into the **OH_VBucket** object in the given column.|
| [putBlob](_r_d_b.md#putblob) | Puts a const uint8_t value into the **OH_VBucket** object in the given column.|
| [putNull](_r_d_b.md#putnull) | Puts a null value into the **OH_VBucket** object in the given column.|
| [clear](_r_d_b.md#clear-22) | Clears an **OH_VBucket** object.|
| [destroy](_r_d_b.md#destroy-34) | Destroys an **OH_VBucket** object and reclaims the memory occupied.|
