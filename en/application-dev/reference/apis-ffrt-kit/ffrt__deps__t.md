# ffrt_deps_t


## Overview

The **ffrt_dependence_t** struct describes dependencies.

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)

**Header file**: [type_def.h](type__def_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [len](#len) | Number of dependencies. | 
| const [ffrt_dependence_t](ffrt__dependence__t.md) \* [items](#items) | Dependency data. | 


## Member Variable Description


### items

```
const ffrt_dependence_t* ffrt_deps_t::items
```
**Description**
Dependency data.


### len

```
uint32_t ffrt_deps_t::len
```
**Description**
Number of dependencies.
