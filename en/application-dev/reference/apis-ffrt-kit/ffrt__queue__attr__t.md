# ffrt_queue_attr_t


## Overview

The **ffrt_queue_attr_t** struct describes a queue attribute.

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [storage](#storage) [(ffrt_queue_attr_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)] | Storage size of a queue attribute. | 


## Member Variable Description


### storage

```
uint32_t ffrt_queue_attr_t::storage[(ffrt_queue_attr_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```
**Description**
Storage size of a queue attribute.
