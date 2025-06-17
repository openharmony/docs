# ffrt_rwlock_t


## Overview

The **ffrt_rwlock_t** struct describes an FFRT read-write lock.

**Since**: 18

**Related module**: [FFRT](_f_f_r_t.md)

**Header file**: [type_def.h](type__def_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [storage](#storage) ffrt_rwlock_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)] | Storage size of a read-write lock. | 


## Member Variable Description


### storage

```
uint32_t ffrt_rwlock_t::storage[(ffrt_rwlock_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```
**Description**
Storage size of a read-write lock.
