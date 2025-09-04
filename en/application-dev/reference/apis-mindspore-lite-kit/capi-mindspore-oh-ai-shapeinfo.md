# OH_AI_ShapeInfo

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## Overview

Defines the maximum number of shapes. The maximum value reserved is **32**, and the maximum number currently supported is **8**.

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

**Header file**: [model.h](capi-model-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| size_t shape_num | Dimension array length.|
| int64_t shape[OH_AI_MAX_SHAPE_NUM] | Dimension array.|
