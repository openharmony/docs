# OH_Huks_ParamSet


## Overview

Defines the struct of a parameter set.

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| uint32_t [paramSetSize](#paramsetsize) | Memory size of the parameter set. |
| uint32_t [paramsCnt](#paramscnt) | Number of parameters in the parameter set. |
| struct [OH_Huks_Param](_o_h___huks___param.md) [params](#params) [] | Array of parameters. |


## Member Variable Description


### params[]

```
struct OH_Huks_Param OH_Huks_ParamSet::params[]
```
**Description**

Array of parameters.


### paramsCnt

```
uint32_t OH_Huks_ParamSet::paramsCnt
```
**Description**

Number of parameters in the parameter set.


### paramSetSize

```
uint32_t OH_Huks_ParamSet::paramSetSize
```
**Description**

Memory size of the parameter set.