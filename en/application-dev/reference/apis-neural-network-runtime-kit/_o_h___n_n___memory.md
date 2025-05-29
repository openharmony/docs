# OH_NN_Memory


## Overview

Defines the memory structure.

**Since**: 9

**Deprecated**: This module is deprecated since API version 11.

**Substitute**: You are advised to use [NN_Tensor](_neural_network_runtime.md#nn_tensor).

**Related module**: [NeuralNeworkRuntime](_neural_network_runtime.md)

**Header file**: [neural_network_runtime_type.h](neural__network__runtime__type_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| void \*const [data](#data) | Pointer to the shared memory. The shared memory is usually applied for by the underlying hardware driver.| 
| const size_t [length](#length) | Length of the shared memory, in bytes.| 


## Member Variable Description


### data

```
void* const OH_NN_Memory::data
```

**Description**

Pointer to the shared memory. The shared memory is usually applied for by the underlying hardware driver.


### length

```
const size_t OH_NN_Memory::length
```

**Description**

Length of the shared memory, in bytes.
