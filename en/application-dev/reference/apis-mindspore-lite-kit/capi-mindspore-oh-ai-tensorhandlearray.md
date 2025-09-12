# OH_AI_TensorHandleArray

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

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
