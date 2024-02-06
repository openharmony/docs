# OH_Huks_ParamSet


## Overview

Defines the structure of the parameter set.

**Since:**
9

**Related Modules:**

[HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [paramSetSize](#paramsetsize) | Memory size of the parameter set.  | 
| [paramsCnt](#paramscnt) | Number of parameters in the parameter set.  | 
| [params](#params) [] | Parameter array.  | 


## Member Variable Description 


### params

  
```
struct OH_Huks_Param OH_Huks_ParamSet::params[]
```
**Description**<br>
Parameter array.


### paramsCnt

  
```
uint32_t OH_Huks_ParamSet::paramsCnt
```
**Description**<br>
Number of parameters in the parameter set.


### paramSetSize

  
```
uint32_t OH_Huks_ParamSet::paramSetSize
```
**Description**<br>
Memory size of the parameter set.
