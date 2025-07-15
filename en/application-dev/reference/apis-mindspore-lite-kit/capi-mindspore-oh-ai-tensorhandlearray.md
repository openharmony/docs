# OH_AI_TensorHandleArray
<!--Kit_MindSpore Lite Kit--><!--System_AI-->

## Overview

Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

**Header file**: [model.h](capi-model-h.md)

## Summary

### Member Variables

| Name                                 | Description|
|-------------------------------------| -- |
| size_t handle_num                   | Tensor array length.|
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md)* handle_list | Tensor array pointer.|
