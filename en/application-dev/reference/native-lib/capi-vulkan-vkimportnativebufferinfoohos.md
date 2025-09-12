# VkImportNativeBufferInfoOHOS

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @andrew1993-->
<!--Designer: @ext4FAT1-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The struct describes the pointer to an OH_NativeBuffer struct.

**Since**: 10

**Related module**: [Vulkan](capi-vulkan.md)

**Header file**: [vulkan_ohos.h](capi-vulkan-ohos-h.md)

## Summary

### Member Variables

| Name                                | Description|
|------------------------------------| -- |
| VkStructureType sType              | Struct type.|
| const void* pNext                  | Pointer to the next-level struct.|
| struct [OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)* buffer | Pointer to an OH_NativeBuffer struct.|
