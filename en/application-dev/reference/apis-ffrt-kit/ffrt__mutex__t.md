# ffrt_mutex_t


## Overview

The **ffrt_mutex_t** struct describes an FFRT mutex.

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [storage](#storage) [(ffrt_mutex_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)] | Storage size of a mutex. | 


## Member Variable Description


### storage

```
uint32_t ffrt_mutex_t::storage[(ffrt_mutex_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```
**Description**
Storage size of a mutex.
