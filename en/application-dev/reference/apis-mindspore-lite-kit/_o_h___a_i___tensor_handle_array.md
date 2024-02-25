# OH_AI_TensorHandleArray


## Overview

Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.

**Since**

9

**Related module**

[MindSpore](_mind_spore.md)


## Summary


### Member Variables

| Name| Description.|
| -------- | -------- |
| [handle_num](#handle_num) | Tensor array length.|
| [handle_list](#handle_list) | Tensor array pointer.|


## Member Variable Description


### handle_list


```
OH_AI_TensorHandle* OH_AI_TensorHandleArray::handle_list
```

**Description**

Tensor array pointer.


### handle_num


```
size_t OH_AI_TensorHandleArray::handle_num
```

**Description**

Tensor array length.
