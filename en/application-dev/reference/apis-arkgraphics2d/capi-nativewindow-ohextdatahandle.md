# OHExtDataHandle
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## **Overview**

Describes the extended data handle.

**Since**: 9

**Deprecated**: This enum is deprecated since API version 10. No substitute is provided.

**Related module**: [NativeWindow](capi-nativewindow.md)

**Header file**: [external_window.h](capi-external-window-h.md)

## Summary

### Member Variables

| Name                | Description                   |
| -------------------- | ----------------------- |
| int32_t fd           | File descriptor handle. The value **-1** indicates that the handle is not supported.|
| uint32_t reserveInts | Number of reserved arrays.    |
| int32_t reserve[0]   | Reserved array.          |
