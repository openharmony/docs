# ffrt_function_header_t


## Overview

The **ffrt_function_header_t** struct describes a task execution function.

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)

**Header file**: [type_def.h](type__def_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [ffrt_function_t](_f_f_r_t.md#ffrt_function_t) [exec](#exec) | Function used to execute a task. | 
| [ffrt_function_t](_f_f_r_t.md#ffrt_function_t) [destroy](#destroy) | Function used to destroy a task. | 
| uint64_t [reserve](#reserve) [2] | Reserved bit, which must be set to **0**. | 


## Member Variable Description


### destroy

```
ffrt_function_t ffrt_function_header_t::destroy
```
**Description**
Function used to destroy a task.


### exec

```
ffrt_function_t ffrt_function_header_t::exec
```
**Description**
Function used to execute a task.


### reserve

```
uint64_t ffrt_function_header_t::reserve[2]
```
**Description**
Reserved bit, which must be set to **0**.
