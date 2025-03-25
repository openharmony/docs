# ffrt_cond_t


## Overview

The **ffrt_cond_t** struct describes a condition variable.

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [storage](#storage) [(ffrt_cond_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)] | Storage size of a condition variable. | 


## Member Variable Description


### storage

```
uint32_t ffrt_cond_t::storage[(ffrt_cond_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```
**Description**
Storage size of a condition variable.
