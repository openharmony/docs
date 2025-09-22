# VkSurfaceCreateInfoOHOS

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @andrew1993-->
<!--Designer: @ext4FAT1-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The struct describes the parameters required for creating a Vulkan surface.

**Since**: 10

**Related module**: [Vulkan](capi-vulkan.md)

**Header file**: [vulkan_ohos.h](capi-vulkan-ohos-h.md)

## Summary

### Member Variables

| Name                            | Description|
|--------------------------------| -- |
| VkStructureType sType          | Struct type.|
| const void* pNext              | Pointer to the next-level struct.|
| VkSurfaceCreateFlagsOHOS flags | Reserved flag type.|
| [OHNativeWindow](capi-vulkan-nativewindow.md)* window     | Pointer to an OHNativeWindow instance.|
