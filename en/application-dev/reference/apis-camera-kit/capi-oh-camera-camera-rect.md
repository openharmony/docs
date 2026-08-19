# Camera_Rect

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=bad8bf8b64978e36c5bf2ec500361ab9a984e7f6 translatedAt=2026-08-11T02:02:24.591Z pushedAt=2026-08-12T03:43:27.607Z -->

```c
typedef struct Camera_Rect {...} Camera_Rect
```

## Overview

Defines a camera rectangle. This method is used to draw rectangles for various detection objects.<br>The coordinate system for detection points is based on the landscape device orientation, with the charging port on the right.<br>The origin of the coordinate system is (0, 0) at the upper left corner, and the coordinates at the lower right corner are the resolution of the camera preview stream.<br>All parameters are integer pixel values. **topLeftX** and **topLeftY** indicate the coordinates of the upper left corner of the rectangle, and **width** and **height** indicate the width and height of the rectangle.

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

**Header file**: [camera.h](capi-camera-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| int32_t topLeftX | X-axis coordinate of the upper left corner of the rectangle.<br>The value range is [0, preview stream width]. For example, for a 1920 × 1440 preview stream, the value range is [0, 1920]. |
| int32_t topLeftY | Y-axis coordinate of the upper left corner of the rectangle.<br>The value range is [0, preview stream height]. For example, for a 1920 × 1440 preview stream, the value range is [0, 1440]. |
| int32_t width | Rectangle width.<br>The value cannot exceed the upper limit of the X axis of the coordinate system, that is, the maximum value of **topLeftX**. |
| int32_t height | Rectangle height.<br>The value cannot exceed the upper limit of the Y axis of the coordinate system, that is, the maximum value of **topLeftY**. |