# ArkGraphics2D Subsystem Changelog

## cl.ArkGraphics2D.1 Corrected Enumerated Values of OH_NativeBuffer_Format

**Access Level**

Public API

**Change Reason**

The names of the following enumerated values of **OH_NativeBuffer_Format** are misspelled: **NATIVEBUFFER_PIXEL_FMT_YUV_422_T**, **NATIVEBUFFER_PIXEL_FMT_YCRCR_422_SP**, **NATIVEBUFFER_PIXEL_FMT_YCRCR_420_SP**, **NATIVEBUFFER_PIXEL_FMT_YCRCR_422_P**, and **NATIVEBUFFER_PIXEL_FMT_YCRCR_420_P**.

**Change Impact**

This change is a non-compatible change.

If the preceding enumerated values are used in your code, change them to the correct names.

**API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.22

**Key API/Component Changes**

Enumerated values of **OH_NativeBuffer_Format** in **native_buffer.h**.

**Adaptation Guide**

Refer to the code snippet provided in [OH_NativeBuffer](../../../application-dev/reference/apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_format).
