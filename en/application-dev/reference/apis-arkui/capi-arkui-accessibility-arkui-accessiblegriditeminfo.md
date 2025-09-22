# ArkUI_AccessibleGridItemInfo
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhanghangkai10241-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

## Overview

Configures attributes for specific components including **List**, **Flex**, **Select**, and **Swiper**.

**Since**: 13

**Related module**: [ArkUI_Accessibility](capi-arkui-accessibility.md)

**Header file**: [native_interface_accessibility.h](capi-native-interface-accessibility-h.md)

## Summary

### Member Variables

| Name| Description    |
| -- |--------|
| bool heading | Whether the item is a heading.|
| bool selected | Whether the item is selected.|
| int32_t columnIndex | Row index of the item.  |
| int32_t rowIndex | Column index of the item.  |
| int32_t columnSpan | Number of rows that the item spans.  |
| int32_t rowSpan | Number of columns that the item spans.  |
