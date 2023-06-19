# OH_NN_Memory


## Overview

Defines the memory structure.

**Since:**
9

**Related Modules:**

[NeuralNeworkRuntime](_neural_nework_runtime.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [data](#data) |Pointer to the shared memory. The shared memory is usually allocated by the underlying hardware driver.  | 
| [length](#length) |Records the length of the shared memory, in bytes.  | 


## Member Variable Description 


### data

  
```
void* const OH_NN_Memory::data
```
**Description**<br>
Pointer to the shared memory. The shared memory is usually allocated by the underlying hardware driver.


### length

  
```
const size_t OH_NN_Memory::length
```
**Description**<br>
Records the length of the shared memory, in bytes.
