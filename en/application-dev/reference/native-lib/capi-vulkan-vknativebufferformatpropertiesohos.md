# VkNativeBufferFormatPropertiesOHOS

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @andrew1993-->
<!--Designer: @ext4FAT1-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The struct describes the format properties of the NativeBuffer.

**Since**: 10

**Related module**: [Vulkan](capi-vulkan.md)

**Header file**: [vulkan_ohos.h](capi-vulkan-ohos-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| VkStructureType sType | Struct type.|
| void* pNext | Pointer to the next-level struct.|
| VkFormat format | Format.|
| uint64_t externalFormat | Externally defined format.|
| VkFormatFeatureFlags formatFeatures | Features of the externally defined format.|
| VkComponentMapping samplerYcbcrConversionComponents | A group of VkComponentSwizzles.|
| VkSamplerYcbcrModelConversion suggestedYcbcrModel | Color model.|
| VkSamplerYcbcrRange suggestedYcbcrRange | Color value range.|
| VkChromaLocation suggestedXChromaOffset | X chrominance offset.|
| VkChromaLocation suggestedYChromaOffset | Y chrominance offset.|
